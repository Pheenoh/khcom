#!/bin/sh
set -e

missing=""
for code in B8CE B8CJ B8CP; do
    [ -f "roms/$code.gba" ] || missing="$missing roms/$code.gba"
done
if [ -n "$missing" ]; then
    echo "error: tools/check.sh regenerates JP and EU and needs every original ROM; missing:$missing" >&2
    exit 1
fi

python3 tools/movie_assets.py

python3 tools/extract_assets.py us
python3 configure.py --version us >/dev/null
ninja
python3 tools/check_data_ownership.py us
python3 tools/regional_data.py us --rom roms/B8CE.gba

python3 tools/version_align.py jp B8CJ
python3 tools/gen_version.py jp B8CJ -q > build/gen_version_jp.log
sed 's/^ */  /' build/gen_version_jp.log
python3 tools/extract_assets.py jp
python3 configure.py --version jp >/dev/null
ninja
python3 tools/check_data_ownership.py jp
python3 tools/regional_data.py jp --rom roms/B8CJ.gba

python3 tools/version_align.py eu B8CP
python3 tools/gen_version.py eu B8CP -q > build/gen_version_eu.log
sed 's/^ */  /' build/gen_version_eu.log
python3 tools/extract_assets.py eu
python3 configure.py --version eu >/dev/null
ninja
python3 tools/check_data_ownership.py eu
python3 tools/regional_data.py eu --rom roms/B8CP.gba
