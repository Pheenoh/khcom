#ifndef GUARD_POOH_ACTOR_TYPES_H
#define GUARD_POOH_ACTOR_TYPES_H

#include "types.h"

typedef struct PooPos {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} PooPos;

typedef struct PooActor {
    PooPos unk_00;
    s32 unk_10;
    u8 unk_14;
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
    PooPos unk_00;
    PooPos unk_10;
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
