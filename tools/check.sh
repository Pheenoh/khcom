#!/bin/sh
set -e

python3 tools/gen_version.py jp B8CJ -q | sed 's/^ */  /'
for v in us jp; do
    python3 configure.py --version "$v" >/dev/null
    ninja
done
