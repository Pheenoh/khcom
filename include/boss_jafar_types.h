#ifndef GUARD_BOSS_JAFAR_TYPES_H
#define GUARD_BOSS_JAFAR_TYPES_H

#include "types.h"

typedef struct JfMapArg {
    void* tiles;
    u16 tilesSize;
    u16 unk_06;
    void* palette;
    u16 paletteSize;
    u16 unk_0E;
    void* maps[4];
} JfMapArg;

typedef struct JfLampSpeed {
    u8 fraction;
    s8 integer;
} JfLampSpeed;

#endif
