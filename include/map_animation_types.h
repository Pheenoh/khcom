#ifndef GUARD_MAP_ANIMATION_TYPES_H
#define GUARD_MAP_ANIMATION_TYPES_H

#include "types.h"

typedef struct MapTileAnimationFrame {
    u16 tileOffset;
    u8 duration;
    u8 unk_03;
} MapTileAnimationFrame;

typedef struct MapTileAnimationTrack {
    const MapTileAnimationFrame* frames;
    u8* tiles;
    u8 frameCount;
    u8 unk_09;
    s16 destOffset;
    u16 copySize;
    u8 unk_0E[0x02];
} MapTileAnimationTrack;

typedef struct MapTileAnimationDef {
    const MapTileAnimationTrack* tracks;
    u8 trackCount;
    u8 unk_05;
    u16 unk_06;
} MapTileAnimationDef;

#endif
