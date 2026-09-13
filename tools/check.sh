#!/bin/sh
set -e

python3 -m unittest discover -s tools -p test_check_data_ownership.py

python3 configure.py --version us >/dev/null
ninja
python3 tools/check_data_ownership.py us

python3 tools/version_align.py jp B8CJ
python3 tools/gen_version.py jp B8CJ -q | sed 's/^ */  /'
python3 configure.py --version jp >/dev/null
ninja
python3 tools/check_data_ownership.py jp

python3 tools/version_align.py eu B8CP
python3 tools/gen_version.py eu B8CP -q | sed 's/^ */  /'
python3 configure.py --version eu >/dev/null
ninja
python3 tools/check_data_ownership.py eu
