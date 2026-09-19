#ifndef GUARD_MOOGLE_DATA_H
#define GUARD_MOOGLE_DATA_H

#include "types.h"
#include "ms_types.h"

typedef struct MooglePackCardDef {
    u16 cardId;
    u8 unk_02[0x2];
    void* unk_04;
    u16 weights[4];
} MooglePackCardDef;

typedef struct MooglePackCardTable {
    MooglePackCardDef* cards;
    s16 count;
    u8 unk_06[0x2];
} MooglePackCardTable;

typedef struct MooglePackSpriteDef {
    void* palette;
    u16 paletteSize;
    u8 unk_06[0x2];
    void* tiles;
    u16 tilesSize;
    u8 unk_0E[0x2];
    void* sprite;
    u16 xOffset;
    u16 yOffset;
} MooglePackSpriteDef;

typedef struct MooglePackTilemapDef {
#ifdef VERSION_EU
    u16** tilemap;
#else
    u16* tilemap;
#endif
    s16 srcX;
    s16 srcY;
} MooglePackTilemapDef;

typedef struct MooglePackMenuEntry {
    s16 upEntry;
    s16 downEntry;
    s16 leftEntry;
    s16 rightEntry;
    s16 cursorX;
    s16 cursorY;
    void* selectionTilemap;
    u16 selectionTilemapSize;
    s16 tilemapX;
    s16 tilemapY;
    u16 spriteX;
    u16 spriteY;
    u16 unk_1A;
    MooglePackTilemapDef packTilemaps[4];
} MooglePackMenuEntry;

extern MooglePackMenuEntry gUnk_099931E4[];
extern MooglePackSpriteDef gUnk_099932D4[];
extern u16 gUnk_09993334[];
extern MooglePackCardTable gUnk_099935A8[];
extern s16 gUnk_099935C0[][4][4];
extern s16 gUnk_09993760[][4];
extern MapCardCategoryDef gUnk_09EF9618[];
extern MooglePackCardDef gUnk_09993348[];
extern MooglePackCardDef gUnk_09993458[];
extern MooglePackCardDef gUnk_09993538[];

#ifdef VERSION_EU
extern u16* gUnkEu_09F84F70[5];
extern u16* gUnkEu_09F84F84[5];
#endif

#endif
