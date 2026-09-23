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

enum WorldId {
    WORLD_AGRABAH = 1,
    WORLD_ATLANTICA = 2,
    WORLD_OLYMPUS_COLISEUM = 3,
    WORLD_WONDERLAND = 4,
    WORLD_MONSTRO = 5,
    WORLD_HALLOWEEN_TOWN = 6,
    WORLD_NEVER_LAND = 7,
    WORLD_HOLLOW_BASTION = 8,
    WORLD_DESTINY_ISLANDS = 9,
    WORLD_TRAVERSE_TOWN = 10,
    WORLD_TWILIGHT_TOWN = 11,
    WORLD_CASTLE_OBLIVION = 12,
    WORLD_100_ACRE_WOOD = 13
};

#endif
