#!/bin/bash
# usage: tools/match.sh <cfile> <symbol> <start> <end>
#
# Compiles one candidate function and compares it byte-for-byte against the
# base ROM. Callees are resolved to their real addresses (as Thumb symbols,
# read out of build/<ver>/com_<ver>.map) so bl encodings compare exactly.
set -e
FT=/tmp/mt; mkdir -p $FT
C=$1; SYM=$2; START=$3; END=$4
arm-none-eabi-cpp -nostdinc -undef -I include -I tools -I /tmp -I /tmp/claude-1000/-home-pheenoh-git-c-com/a1bfa4de-60d5-4f26-80f7-ed193de463ed/scratchpad/bos2 -I /tmp/claude-1000/-home-pheenoh-git-c-com/a1bfa4de-60d5-4f26-80f7-ed193de463ed/scratchpad/bos3 -I /tmp/claude-1000/-home-pheenoh-git-c-com/a1bfa4de-60d5-4f26-80f7-ed193de463ed/scratchpad/bos4 -I /tmp/claude-1000/-home-pheenoh-git-c-com/a1bfa4de-60d5-4f26-80f7-ed193de463ed/scratchpad/bos5 $C -o $FT/x.i
tools/agbcc/bin/agbcc -mthumb-interwork -O2 -fprologue-bugfix ${AGBCC_EXTRA:-} -o $FT/x.s $FT/x.i
arm-none-eabi-as -mcpu=arm7tdmi -mthumb-interwork -o $FT/x.o $FT/x.s
grep -oE '^[A-Za-z_][A-Za-z0-9_]*' config/us/symbols.txt 2>/dev/null | sort -u > $FT/datasyms.txt || : > $FT/datasyms.txt
awk -F= '/=/{gsub(/ /,"",$1); gsub(/ /,"",$2); printf "%s = %s;\n", $1, $2}' config/us/symbols.txt > $FT/defs.ld 2>/dev/null || : > $FT/defs.ld
arm-none-eabi-nm -u $FT/x.o | awk '{print $2}' | grep -vxF -f $FT/datasyms.txt > $FT/undef.txt || : > $FT/undef.txt
: > $FT/stub.s
: > $FT/place.ld
while read s; do
  [ -z "$s" ] && continue
  a=$(grep -E "^ +0x0[0-9a-f]{7} +$s$" build/us/com_us.map | head -1 | awk '{print $1}')
  [ -z "$a" ] && { echo "MISSING SYMBOL $s" >&2; exit 2; }
  printf '\t.section .st_%s,"ax"\n\t.thumb\n\t.global %s\n\t.thumb_func\n%s:\n\tbx lr\n' "$s" "$s" "$s" >> $FT/stub.s
  printf '  .st_%s %s : { *(.st_%s) }\n' "$s" "$a" "$s" >> $FT/place.ld
done < $FT/undef.txt
arm-none-eabi-as -mcpu=arm7tdmi -mthumb-interwork -o $FT/stub.o $FT/stub.s
{ cat $FT/defs.ld; echo "SECTIONS {"; echo "  .text $START : SUBALIGN(4) { $FT/x.o(.text) }"; cat $FT/place.ld; echo "  /DISCARD/ : { *(*) }"; echo "}"; } > $FT/l.ld
arm-none-eabi-ld -T $FT/l.ld -o $FT/x.elf $FT/x.o $FT/stub.o
arm-none-eabi-objcopy -O binary --only-section=.text $FT/x.elf $FT/x.bin
python3 - "$START" "$END" <<'PY'
import sys
s=int(sys.argv[1],16)-0x08000000; e=int(sys.argv[2],16)-0x08000000
rom=open('roms/B8CE.gba','rb').read()[s:e]
new=open('/tmp/mt/x.bin','rb').read()
while len(new)>len(rom) and new[-2:] in (b'\xc0\x46', b'\x00\x00'):
    new=new[:-2]
if new==rom: print("EXACT MATCH")
else:
    print(f"diff (rom {len(rom)}B, new {len(new)}B)")
    print("rom:", rom.hex()); print("new:", new.hex())
PY
