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

"$REPO/tools/agbcc/bin/agbcc" -mthumb-interwork -O2 -o "$TMP/x.s" "$IN"
arm-none-eabi-as -mcpu=arm7tdmi -mthumb-interwork -o "$TMP/x.o" "$TMP/x.s"

: > "$TMP/stub.s"
: > "$TMP/place.ld"
arm-none-eabi-nm -u "$TMP/x.o" | awk '{print $2}' | while IFS= read -r s; do
    [ -z "$s" ] && continue
    a=$(grep -E "^ +0x0[0-9a-f]{7} +$s\$" "$MAP" | head -1 | awk '{print $1}')
    [ -z "$a" ] && { echo "MISSING SYMBOL $s" >&2; exit 2; }
    printf '\t.section .st_%s,"ax"\n\t.thumb\n\t.global %s\n\t.thumb_func\n%s:\n\tbx lr\n' "$s" "$s" "$s" >> "$TMP/stub.s"
    printf '  .st_%s %s : { *(.st_%s) }\n' "$s" "$a" "$s" >> "$TMP/place.ld"
done
arm-none-eabi-as -mcpu=arm7tdmi -mthumb-interwork -o "$TMP/stub.o" "$TMP/stub.s"

{
    echo "SECTIONS {"
    echo "  .text $ADDR : SUBALIGN(4) { $TMP/x.o(.text) }"
    cat "$TMP/place.ld"
    echo "  /DISCARD/ : { *(*) }"
    echo "}"
} > "$TMP/l.ld"
arm-none-eabi-ld -T "$TMP/l.ld" -o "$TMP/x.elf" "$TMP/x.o" "$TMP/stub.o"
arm-none-eabi-objcopy --only-section=.text -N '$d' -N '$a' -N '$t' "$TMP/x.elf" "$OUT" 2>/dev/null
