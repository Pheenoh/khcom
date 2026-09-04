#!/bin/bash
# usage: tools/match.sh <cfile> <symbol> <start> <end>
#
# Compiles one candidate function and compares it byte-for-byte against the
# base ROM. Callees are resolved to their real addresses (as Thumb symbols,
# read out of build/<ver>/com_<ver>.map) so bl encodings compare exactly.
#
# MATCH_BSS=<addr> builds with -fno-common and places the unit's own .bss and
# COMMON at that address, which is what a unit defining its own globals needs;
# without it the link dies on "defined in discarded section COMMON".
#
# MATCH_BASE=<addr> links .text at that address instead of <start> and slices
# <symbol> back out of the result, so a whole translation unit can be compiled
# and one function compared. Use the unit's .text base.
set -e
FT=${MATCH_TMP:-/tmp/mt-$(git rev-parse --show-toplevel 2>/dev/null | cksum | cut -d" " -f1)}; mkdir -p $FT; export MATCH_TMP=$FT
C=$1; SYM=$2; START=$3; END=$4; export MATCH_SYM=$SYM
U=$(basename $C .c)
if [ -z "${MATCH_BASE:-}" ] && [ -f build/us/com_us.map ]; then
  MATCH_BASE=$(grep -E "^ \.text +0x0[0-9a-f]{7} +0x[0-9a-f]+ build/us/src/$U\.o$" build/us/com_us.map | head -1 | awk '{print $2}')
fi
if [ -z "${MATCH_BSS:-}" ] && [ -f build/us/com_us.map ]; then
  MATCH_BSS=$(grep -A1 "^\.bss\.$U " build/us/com_us.map 2>/dev/null | head -1 | awk '{print $2}')
fi
[ -n "${MATCH_BASE:-}" ] && export MATCH_BASE
[ -n "${MATCH_BSS:-}" ] && export MATCH_BSS
arm-none-eabi-cpp -nostdinc -undef -I include -I tools -I /tmp ${EXTRA_INC:-} $C -o $FT/x.i
BSSFLAG=""; [ -n "${MATCH_BSS:-}" ] && BSSFLAG="-fno-common"
tools/agbcc/bin/agbcc -mthumb-interwork -O2 -fprologue-bugfix $BSSFLAG ${AGBCC_EXTRA:-} -o $FT/x.s $FT/x.i
arm-none-eabi-as -mcpu=arm7tdmi -mthumb-interwork -I include -I asm/us/nonmatchings -o $FT/x.o $FT/x.s
grep -oE '^[A-Za-z_][A-Za-z0-9_]*' config/us/symbols.txt 2>/dev/null | sort -u > $FT/datasyms.txt || : > $FT/datasyms.txt
awk -F= '/=/{gsub(/ /,"",$1); gsub(/ /,"",$2); printf "%s = %s;\n", $1, $2}' config/us/symbols.txt > $FT/defs.ld 2>/dev/null || : > $FT/defs.ld
arm-none-eabi-nm -u $FT/x.o | awk '{print $2}' | grep -vxF -f $FT/datasyms.txt > $FT/undef.txt || : > $FT/undef.txt
: > $FT/stub.s
: > $FT/place.ld
while read s; do
  [ -z "$s" ] && continue
  a=$(grep -E "^ +0x0[0-9a-f]{7} +$s$" build/us/com_us.map | head -1 | awk '{print $1}')
  [ -z "$a" ] && a=$(grep -E "^ +0x[0-9a-f]{16} +$s$" build/us/com_us.map | head -1 | awk '{print $1}')
  [ -z "$a" ] && { echo "MISSING SYMBOL $s" >&2; exit 2; }
  n=$((a))
  if [ $n -lt $((0x08000240)) ] || [ $n -ge $((0x08121330)) ]; then
    printf '%s = %s;\n' "$s" "$a" >> $FT/defs.ld
    continue
  fi
  printf '\t.section .st_%s,"ax"\n\t.thumb\n\t.global %s\n\t.thumb_func\n%s:\n\tbx lr\n' "$s" "$s" "$s" >> $FT/stub.s
  printf '  .st_%s %s : { *(.st_%s) }\n' "$s" "$a" "$s" >> $FT/place.ld
done < $FT/undef.txt
arm-none-eabi-as -mcpu=arm7tdmi -mthumb-interwork -o $FT/stub.o $FT/stub.s
BSSLINE=""; LDEXTRA=""
if [ -n "${MATCH_BSS:-}" ]; then
  BSSLINE="  .bss $MATCH_BSS (NOLOAD) : { $FT/x.o(.bss COMMON) }"
  LDEXTRA="--no-check-sections"
fi
BASE=${MATCH_BASE:-$START}
{ cat $FT/defs.ld; echo "SECTIONS {"; echo "  .text $BASE : SUBALIGN(4) { $FT/x.o(.text) }"; cat $FT/place.ld; [ -n "$BSSLINE" ] && echo "$BSSLINE"; echo "  /DISCARD/ : { *(*) }"; echo "}"; } > $FT/l.ld
arm-none-eabi-ld $LDEXTRA -T $FT/l.ld -o $FT/x.elf $FT/x.o $FT/stub.o
arm-none-eabi-objcopy -O binary --only-section=.text $FT/x.elf $FT/x.bin
SYMA=$(arm-none-eabi-nm $FT/x.elf | awk -v s="$SYM" '$3==s{print "0x"$1}' | head -1)
python3 - "$START" "$END" "$BASE" "${SYMA:-}" <<'PY'
import sys, os
s=int(sys.argv[1],16)-0x08000000; e=int(sys.argv[2],16)-0x08000000
rom=open('roms/B8CE.gba','rb').read()[s:e]
new=open(os.environ['MATCH_TMP']+'/x.bin','rb').read()
base=int(sys.argv[3],16)
if base != int(sys.argv[1],16):
    if not sys.argv[4]:
        sys.exit("MISSING SYMBOL %s in candidate" % os.environ.get('MATCH_SYM',''))
    off=int(sys.argv[4],16)-base
    new=new[off:off+(e-s)]
while len(new)>len(rom) and new[-2:] in (b'\xc0\x46', b'\x00\x00'):
    new=new[:-2]
if len(new)==len(rom) and new[:-2]==rom[:-2] and new[-2:]==b'\xc0\x46' and rom[-2:]==b'\x00\x00':
    new=rom
if new==rom: print("EXACT MATCH")
else:
    print(f"diff (rom {len(rom)}B, new {len(new)}B)")
    print("rom:", rom.hex()); print("new:", new.hex())
PY
