#ifndef GUARD_POOH_ACTOR_TYPES_H
#define GUARD_POOH_ACTOR_TYPES_H

#include "types.h"
#include "obj.h"
#include "taskpool.h"

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

typedef struct PoohWork {
    void* tiles;
    PaletteSlot* palette;
    u8 unk_08[0x04];
    u8 anim[0x18];
    u8 unk_24;
    u8 unk_25;
    u16 unk_26;
    u8 unk_28[0x10];
    u8 unk_38;
    u8 unk_39;
    u8 unk_3A;
    u8 unk_3B;
    u8 unk_3C[0x0C];
    s32 unk_48;
    u8 collider[0x5C];
    s32 unk_A8;
    u16 unk_AC;
    u8 unk_AE[0x02];
    TaskPool tasks;
    Task* task;
    u8 unk_C8[0x0E];
    u8 unk_D6;
    u8 unk_D7[0x03];
    u16 unk_DA;
    u8 unk_DC[0x1A];
    u8 unk_F6;
    u8 unk_F7[0x03];
    u8 unk_FA;
} PoohWork;

#endif
