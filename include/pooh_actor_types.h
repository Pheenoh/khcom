#ifndef GUARD_POOH_ACTOR_TYPES_H
#define GUARD_POOH_ACTOR_TYPES_H

#include "types.h"

typedef struct PooPos {
    s32 x;
    s32 y;
    s32 z;
    s32 unk_0C;
} PooPos;

typedef struct PooActor {
    PooPos pos;
    s32 unk_10;
    u8 angle;
    u8 unk_15[0x05];
    u16 unk_1A;
    u8 unk_1C[0x14];
    u16 unk_30;
    u16 unk_32;
    u8 unk_34[0x06];
    u16 unk_3A;
    s32 unk_3C;
} PooActor;

typedef struct PooState {
    PooPos pos;
    PooPos pos2;
    s32 unk_20;
    u32 unk_24;
    u16 unk_28;
    u16 unk_2A;
    u32 unk_2C[4];
    u16 unk_3C;
    u16 unk_3E;
    u16 unk_40;
    u16 unk_42;
} PooState;

#endif
