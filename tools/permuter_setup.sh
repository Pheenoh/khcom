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

cp "$C" "$DIR/src.c"
arm-none-eabi-cpp -nostdinc -undef -P -I "$REPO/include" -I "$REPO/tools/agbcc/include" \
    -DVERSION_US "$DIR/src.c" -o "$DIR/base.c"
"$REPO/tools/permuter_target.sh" "$START" "$END" "$DIR/target.o"

printf '#!/bin/bash\nADDR=%s exec "$(dirname "$0")/../../tools/permuter_compile.sh" "$@"\n' \
    "$START" > "$DIR/compile.sh"
chmod +x "$DIR/compile.sh"

printf 'func_name = "%s"\ncompiler_type = "gcc"\nobjdump_command = "arm-none-eabi-objdump -drz -M force-thumb"\n' \
    "$SYM" > "$DIR/settings.toml"

echo "$DIR"
