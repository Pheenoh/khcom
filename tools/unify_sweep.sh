#!/bin/bash
set -u
cd "$(dirname "${BASH_SOURCE[0]}")/.."
ROUNDS=${1:-12}
PER=${2:-10}

for r in $(seq 1 "$ROUNDS"); do
    before=$(grep -c 'unified' docs/proto_ledger.tsv 2>/dev/null || echo 0)

    for i in $(seq 1 "$PER"); do
        if ! git diff --quiet; then
            git add -u include src
            git commit -q -m "Unify a duplicated prototype" || true
        fi
        out=$(timeout 1800 python3 tools/unify_proto.py --pick 1 --apply 2>&1 | tail -1)
        echo "round $r: $out"
        [ -z "$out" ] && break
    done

    if ! git diff --quiet; then
        git add -u include src
        git commit -q -m "Unify a duplicated prototype" || true
    fi
    after=$(grep -c 'unified' docs/proto_ledger.tsv 2>/dev/null || echo 0)
    echo "round $r done: $before -> $after unified"
    [ "$before" = "$after" ] && echo "fixed point reached" && break
done
