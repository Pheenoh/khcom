#ifndef GUARD_STAFF_ROLL_TYPES_H
#define GUARD_STAFF_ROLL_TYPES_H

#include "types.h"

typedef struct StaffRollScene {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    s32 unk_04;
    s32 x;
    s32 y;
    void* tiles;
    u16 tilesSize;
    u16 unk_16;
    void* map;
    u16 mapSize;
    u16 unk_1E;
    void* palette;
    u16 paletteSize;
    u16 unk_26;
    s32 targetX;
    s32 targetY;
    u16 unk_30;
    u16 unk_32;
} StaffRollScene;

#endif
