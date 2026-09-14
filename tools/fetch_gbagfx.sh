#!/bin/sh
set -e
ROOT="$(CDPATH= cd -- "$(dirname "$0")/.." && pwd)"
DEST="$ROOT/tools/gbagfx"
if [ -x "$DEST/gbagfx" ]; then
    echo "gbagfx already present: $DEST/gbagfx"
    exit 0
fi
if [ ! -d "$DEST/.git" ]; then
    git clone --depth 1 https://github.com/pret/gbagfx.git "$DEST"
fi
make -C "$DEST"
echo "built $DEST/gbagfx"
