#ifndef GUARD_WORLD_TYPES_H
#define GUARD_WORLD_TYPES_H

#include "types.h"

typedef struct WorldSelectDef {
    void* palette;
    u16 paletteSize;
    u8 unk_06[0x02];
    void* tiles;
    u16 tilesSize;
    u8 unk_0E[0x02];
    void* sprite;
    void* name;
} WorldSelectDef;

#endif
