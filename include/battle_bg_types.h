#ifndef GUARD_BATTLE_BG_TYPES_H
#define GUARD_BATTLE_BG_TYPES_H

#include "types.h"

typedef struct BattleBackgroundDef {
    void* tiles;
    u16 tilesSize;
    u8 unk_06[0x2];
    void* palette;
    u16 paletteSize;
    u8 unk_0E[0x2];
    u8 map[0x4];
} BattleBackgroundDef;

#endif
