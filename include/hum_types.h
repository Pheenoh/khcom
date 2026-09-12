#ifndef GUARD_HUM_TYPES_H
#define GUARD_HUM_TYPES_H

#include "types.h"
#include "anim.h"

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

#endif
