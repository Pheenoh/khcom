#!/bin/bash
# usage: tools/permute.sh <permuter args...>
#
# Runs decomp-permuter with TMPDIR pointed at a repo-local directory. The
# permuter creates two scratch files per candidate compile through tempfile,
# and a night of parallel runs put a million of them in /tmp, which exhausted
# the tmpfs inode table (nr_inodes=1048576) while leaving 19G of space free.
set -e
ROOT=$(git rev-parse --show-toplevel)
export TMPDIR="$ROOT/permuter/tmp"
mkdir -p "$TMPDIR"
exec "$ROOT/.venv/bin/python3" "$ROOT/tools/decomp-permuter/permuter.py" "$@"
