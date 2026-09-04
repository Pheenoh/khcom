#!/bin/bash
# usage: tools/permuter_setup.sh <cfile> <symbol> <start> <end>
#
# Builds a decomp-permuter working directory at permuter/<symbol> from a
# candidate that already compiles standalone (the same input tools/match.sh
# takes). Run it with:
#
#     .venv/bin/python3 tools/decomp-permuter/permuter.py permuter/<symbol> \
#         -j 8 --stop-on-zero
set -e
REPO="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
C="$1"
SYM="$2"
START="$3"
END="$4"
DIR="$REPO/permuter/$SYM"
mkdir -p "$DIR"

if grep -qE "^$(basename "$C")([[:space:]]|$)" "$REPO/config/us/units.txt" 2>/dev/null \
   && [ -z "${PERM_UNIT:-}" ]; then
    echo "refusing: $C is a whole translation unit." >&2
    echo "permuter_compile.sh links the entire unit at the target function's" >&2
    echo "address while target.o holds one function, so the base score comes out" >&2
    echo "in the millions and the search never converges. Build a standalone" >&2
    echo "file (the one function plus its header) and confirm with tools/match.sh" >&2
    echo "that it reproduces the same diff as the in-unit compile first." >&2
    echo "A standalone cannot reach the unit's statics; if the function touches" >&2
    echo "one, park it rather than permuting. Set PERM_UNIT=1 to override." >&2
    exit 2
fi

cp "$C" "$DIR/src.c"
arm-none-eabi-cpp -nostdinc -undef -P -I "$REPO/include" -I "$REPO/tools/agbcc/include" \
    -DVERSION_US "$DIR/src.c" -o "$DIR/base.c"
"$REPO/tools/permuter_target.sh" "$START" "$END" "$DIR/target.o"

U="$(basename "$C" .c)"
BSS="${PERM_BSS:-}"
if [ -z "$BSS" ]; then
    BSS=$(grep -A1 "^\.bss\.$U " "$REPO/build/us/com_us.map" 2>/dev/null | head -1 | awk '{print $2}')
fi
if [ -z "$BSS" ]; then
    BSS=$(U=$U python3 -c '
import os, re
u = os.environ["U"]
src = open("'"$REPO"'/configure.py").read()
m = re.search(r"\"src/%s\.o\"\s*:\s*(\{[^}]*\}|0[xX][0-9a-fA-F]+)" % re.escape(u), src)
if m:
    t = m.group(1)
    if t.startswith("{"):
        v = re.search(r"\"us\"\s*:\s*(0[xX][0-9a-fA-F]+)", t)
        t = v.group(1) if v else ""
    print(t.lower())
' 2>/dev/null)
fi
FLAGS="${PERM_FLAGS_IN:-}"
[ -z "$FLAGS" ] && FLAGS=$(awk -v u="$U.c" '$1==u{$1=""; print; exit}' "$REPO/config/us/units.txt" 2>/dev/null)
[ -z "$FLAGS" ] && FLAGS="-O2 -fprologue-bugfix"
printf '#!/bin/bash\nADDR=%s PERM_BSS=%s PERM_FLAGS=%s exec "$(dirname "$0")/../../tools/permuter_compile.sh" "$@"\n' \
    "$START" "$BSS" "\"$FLAGS\"" > "$DIR/compile.sh"
[ -n "$BSS" ] && echo "  unit .bss placed at $BSS"
chmod +x "$DIR/compile.sh"

printf 'func_name = "%s"\ncompiler_type = "gcc"\nobjdump_command = "arm-none-eabi-objdump -drz -M force-thumb"\n' \
    "$SYM" > "$DIR/settings.toml"

echo "$DIR"
