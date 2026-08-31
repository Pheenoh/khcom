#!/bin/bash
# usage: tools/permuter_target.sh <start> <end> <out.o>
#
# Builds the permuter's target object for one function: the base ROM's own bytes,
# placed at the function's real address in an ELF holding just .text, so it
# compares directly against tools/permuter_compile.sh output.
set -e
REPO="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
START="$1"
END="$2"
OUT="$3"
TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"' EXIT

python3 - "$START" "$END" "$TMP/t.s" "$REPO" <<'PY'
import sys
start, end, out, repo = int(sys.argv[1], 16), int(sys.argv[2], 16), sys.argv[3], sys.argv[4]
data = open(f"{repo}/roms/B8CE.gba", "rb").read()[start - 0x08000000:end - 0x08000000]
with open(out, "w") as f:
    f.write("\t.section .text\n\t.thumb\n\t.thumb_func\n\t.global target\n\t.type target, %function\ntarget:\n")
    for i in range(0, len(data), 16):
        f.write("\t.byte " + ", ".join("0x%02X" % b for b in data[i:i + 16]) + "\n")
PY
arm-none-eabi-as -mcpu=arm7tdmi -mthumb-interwork -o "$TMP/t.o" "$TMP/t.s"
printf 'SECTIONS {\n  .text %s : { %s(.text) }\n  /DISCARD/ : { *(*) }\n}\n' "$START" "$TMP/t.o" > "$TMP/l.ld"
arm-none-eabi-ld -T "$TMP/l.ld" -o "$TMP/t.elf" "$TMP/t.o"
arm-none-eabi-objcopy --only-section=.text -N '$d' -N '$a' -N '$t' "$TMP/t.elf" "$OUT" 2>/dev/null
