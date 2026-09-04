#!/bin/bash
set -u
cd "$(dirname "${BASH_SOURCE[0]}")/.."
ROUNDS=${1:-8}
PER=${2:-25}

for r in $(seq 1 "$ROUNDS"); do
    before=$(grep -c unified docs/proto_ledger.tsv 2>/dev/null || echo 0)
    timeout 20000 python3 tools/unify_proto.py --pick "$PER" --apply --commit 2>&1 | sed "s/^/round $r: /"
    after=$(grep -c unified docs/proto_ledger.tsv 2>/dev/null || echo 0)
    echo "round $r: $before -> $after unified"
    [ "$before" = "$after" ] && echo "fixed point" && break
done
