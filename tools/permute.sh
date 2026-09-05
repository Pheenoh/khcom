#!/bin/bash
# usage: tools/permute.sh <permuter args...>
#
# Runs decomp-permuter with TMPDIR pointed at a repo-local directory. The
# permuter creates two scratch files per candidate compile through tempfile,
# and a night of parallel runs put a million of them in /tmp, which exhausted
# the tmpfs inode table (nr_inodes=1048576) while leaving 19G of space free.
# A leading --budget <seconds> ends the run after that long (exit 124), which
# is the same job coreutils timeout did on Linux; macOS ships no timeout.
set -e
ROOT=$(git rev-parse --show-toplevel)
exec "$ROOT/.venv/bin/python3" "$ROOT/tools/permute_run.py" "$@"
