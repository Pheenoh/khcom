#!/bin/bash
# usage: ADDR=0x08008F00 tools/permuter_compile.sh input.c -o output.o
#
# Compiles one preprocessed candidate and links it at its real ROM address, with
# every callee resolved to a Thumb stub at its own address (read from the build
# map), so bl encodings match the target byte for byte. Emits an ELF holding
# just .text, which is what tools/permuter_target.sh produces for the target.
set -e
REPO="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
: "${ADDR:?ADDR must be set}"
IN="$1"
OUT="$3"
MAP="$REPO/build/us/com_us.map"
TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"' EXIT

UFLAGS="${PERM_FLAGS:--O2 -fprologue-bugfix}"
"$REPO/tools/agbcc/bin/agbcc" -mthumb-interwork $UFLAGS -o "$TMP/x.s" "$IN"
arm-none-eabi-as -mcpu=arm7tdmi -mthumb-interwork -I "$REPO/include" \
    -I "$REPO/asm/us/nonmatchings" -o "$TMP/x.o" "$TMP/x.s"

: > "$TMP/stub.s"
: > "$TMP/place.ld"
grep -oE '^[A-Za-z_][A-Za-z0-9_]*' "$REPO/config/us/symbols.txt" 2>/dev/null | sort -u > "$TMP/datasyms.txt" || : > "$TMP/datasyms.txt"
awk -F= '/=/{gsub(/ /,"",$1); gsub(/ /,"",$2); printf "%s = %s;\n", $1, $2}' "$REPO/config/us/symbols.txt" > "$TMP/defs.ld" 2>/dev/null || : > "$TMP/defs.ld"
arm-none-eabi-nm -u "$TMP/x.o" | awk '{print $2}' | grep -vxF -f "$TMP/datasyms.txt" | while IFS= read -r s; do
    [ -z "$s" ] && continue
    a=$(grep -E "^ +0x0[0-9a-f]{7} +$s\$" "$MAP" | head -1 | awk '{print $1}')
    [ -z "$a" ] && { echo "MISSING SYMBOL $s" >&2; exit 2; }
    n=$((a))
    if [ $n -lt $((0x08000240)) ] || [ $n -ge $((0x08121330)) ]; then
        printf '%s = %s;\n' "$s" "$a" >> "$TMP/defs.ld"
        continue
    fi
    printf '\t.section .st_%s,"ax"\n\t.thumb\n\t.global %s\n\t.thumb_func\n%s:\n\tbx lr\n' "$s" "$s" "$s" >> "$TMP/stub.s"
    printf '  .st_%s %s : { *(.st_%s) }\n' "$s" "$a" "$s" >> "$TMP/place.ld"
done
arm-none-eabi-as -mcpu=arm7tdmi -mthumb-interwork -o "$TMP/stub.o" "$TMP/stub.s"

{
    cat "$TMP/defs.ld"
    echo "SECTIONS {"
    echo "  .text $ADDR : SUBALIGN(4) { $TMP/x.o(.text) }"
    cat "$TMP/place.ld"
    [ -n "${PERM_BSS:-}" ] && echo "  .bss $PERM_BSS (NOLOAD) : { $TMP/x.o(.bss COMMON) }"
    echo "  /DISCARD/ : { *(*) }"
    echo "}"
} > "$TMP/l.ld"
LDEXTRA=""; [ -n "${PERM_BSS:-}" ] && LDEXTRA="--no-check-sections"
arm-none-eabi-ld $LDEXTRA -T "$TMP/l.ld" -o "$TMP/x.elf" "$TMP/x.o" "$TMP/stub.o"
arm-none-eabi-objcopy --only-section=.text -N '$d' -N '$a' -N '$t' "$TMP/x.elf" "$OUT" 2>/dev/null
