#ifndef GUARD_CARD_UI_TYPES_H
#define GUARD_CARD_UI_TYPES_H

#include "types.h"
#include "anim.h"

struct ObjTiles;
struct ObjPalette;

typedef struct CardUiSpriteState {
    struct ObjTiles* tiles;
    struct ObjPalette* palette;
    AnimState anim;
    void* gfx;
} CardUiSpriteState;

typedef struct MapCardUiResources {
    struct ObjTiles* tiles;
    struct ObjTiles* extraTiles;
    u8 unk_08[4];
    struct ObjPalette* palette;
    void* gfx;
    void** sprites;
    AnimState anim;
} MapCardUiResources;

typedef char CardUiSpriteState_size[(sizeof(CardUiSpriteState) == 0x24) ? 1 : -1];
typedef char MapCardUiResources_size[(sizeof(MapCardUiResources) == 0x30) ? 1 : -1];

typedef struct SpriteFrameResourceDef {
    void* tiles;
    void** sprites;
    u16 tilesSize;
    u16 spriteIndex;
} SpriteFrameResourceDef;

typedef struct MapCardDef {
    void* unk_00;
    void* unk_04;
    void** unk_08;
    void* unk_0C;
    void* unk_10;
    void** unk_14;
    u16 unk_18;
    u16 unk_1A;
    u16 unk_1C;
    u8 unk_1E;
    u8 unk_1F;
    u16 unk_20;
    u16 unk_22;
    u16 unk_24;
    u16 unk_26;
} MapCardDef;

typedef struct MapCardBackDef {
    void* unk_00;
    void* unk_04;
    void** unk_08;
    void* unk_0C;
    void** unk_10;
    u16 unk_14;
    u16 unk_16;
    u8 unk_18[0x4];
} MapCardBackDef;

#endif
