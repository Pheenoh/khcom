#!/bin/sh
set -e
ROOT="$(CDPATH= cd -- "$(dirname "$0")/.." && pwd)"
DEST="$ROOT/tools/gbagfx"
if [ -x "$DEST/gbagfx" ]; then
    echo "gbagfx already present: $DEST/gbagfx"
    exit 0
fi
if [ ! -d "$DEST/src/.git" ]; then
    git clone --quiet --depth 1 --filter=blob:none --sparse https://github.com/pret/pokeemerald.git "$DEST/src"
    git -C "$DEST/src" sparse-checkout set tools/gbagfx
fi
make -C "$DEST/src/tools/gbagfx"
cp "$DEST/src/tools/gbagfx/gbagfx" "$DEST/gbagfx"
echo "built $DEST/gbagfx"
