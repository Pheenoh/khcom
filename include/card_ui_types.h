#ifndef GUARD_CARD_UI_TYPES_H
#define GUARD_CARD_UI_TYPES_H

#include "types.h"

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
