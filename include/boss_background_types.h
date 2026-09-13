#ifndef GUARD_BOSS_BACKGROUND_TYPES_H
#define GUARD_BOSS_BACKGROUND_TYPES_H

#include "types.h"

typedef struct BosMapConfig {
    void* tiles;
    u16 tilesSize;
    u16 unk_06;
    void* palette;
    u16 paletteSize;
    u16 unk_0E;
    void* unk_10[4];
} BosMapConfig;

#endif
