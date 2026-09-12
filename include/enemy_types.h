#ifndef GUARD_ENEMY_TYPES_H
#define GUARD_ENEMY_TYPES_H

#include "types.h"
#include "anim.h"
#include "taskpool.h"
#include "battle_actor.h"

typedef struct EmyDef {
    void* unk_00;
    void* unk_04;
    s32 unk_08;
    u16 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    u16 unk_16;
    u16 unk_18;
    u16 unk_1A;
    u32 unk_1C;
} EmyDef;

typedef struct EmyWork {
    void* tiles;
    void* unk_004;
    void* unk_008;
    void* gfx;
    AnimState anim;
    TaskPool unk_028;
    BtlObj unk_03C;
    u32 unk_14C;
    u32 unk_150;
    s16 unk_154;
    s16 unk_156;
    u16 unk_158;
    u8 unk_15A;
    u8 unk_15B;
    EmyDef* unk_15C;
    u8 angle;
    u8 unk_161;
    u16 unk_162;
    s32 unk_164;
    s32 unk_168;
    u32 unk_16C;
    s32 unk_170;
    s32 unk_174;
    s32 unk_178;
    s32 unk_17C;
    s32 unk_180;
} EmyWork;

typedef struct EmyObj {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} EmyObj;

#endif
