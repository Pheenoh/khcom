#ifndef GUARD_HUM_TYPES_H
#define GUARD_HUM_TYPES_H

#include "types.h"
#include "anim.h"
#include "taskpool.h"
#include "battle_actor_types.h"

typedef struct HumSub {
    void* unk_00;
    void* tiles;
    void* palette;
    void* unk_0C;
    AnimState anim;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u16 unk_34;
    u16 unk_36;
    void* gfx;
} HumSub;

typedef struct HumDef {
    u16 unk_00;
    u16 unk_02;
    void* unk_04;
    u32 unk_08;
    u32 unk_0C;
} HumDef;

typedef struct HumSubDef {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
} HumSubDef;

typedef struct HumWork {
    void* unk_000;
    void* tiles;
    void* palette;
    HumSub* unk_00C;
    HumSub* unk_010;
    AnimState anim;
    TaskPool unk_02C;
    BtlObj unk_040;
    s16 unk_150;
    s16 unk_152;
    u32 unk_154;
    u32 unk_158;
    u32 unk_15C;
    u32 unk_160;
    s32 unk_164;
    s32 unk_168;
    s32 unk_16C;
    u32 unk_170;
    s16 unk_174;
    u16 unk_176;
    void* unk_178;
    u16 unk_17C;
    u16 unk_17E;
    void* gfx;
    u32 unk_184;
} HumWork;

#endif
