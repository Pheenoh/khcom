#ifndef GUARD_BG_ANIMATION_TYPES_H
#define GUARD_BG_ANIMATION_TYPES_H

#include "types.h"

typedef struct BgAnimationChunk {
    void* data;
    u16 size;
    u16 unk_06;
} BgAnimationChunk;

typedef struct BgAnimationDef {
    const BgAnimationChunk* chunks;
    void* tilemap;
    void* palette;
    u16 paletteSize;
    u16 tilesPerFrame;
    u16 unk_10;
    u16 unk_12;
    u16 frameCount;
    u16 frameDuration;
} BgAnimationDef;

typedef char BgAnimationDef_size[(sizeof(BgAnimationDef) == 0x18) ? 1 : -1];
typedef char BgAnimationChunk_size[(sizeof(BgAnimationChunk) == 0x08) ? 1 : -1];

#endif
