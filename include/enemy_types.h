#ifndef GUARD_ENEMY_TYPES_H
#define GUARD_ENEMY_TYPES_H

#include "types.h"
#include "anim.h"
#include "taskpool.h"
#include "battle_actor.h"

typedef struct EmyDef {
    void* palette;
    const AnimDef* animDef;
    s32 unk_08;
    u16 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    u16 unk_16;
    u16 unk_18;
    u16 flags;
    EmyKind kind;
} EmyDef;

typedef struct EmyWork {
    void* tiles;
    void* palette;
    void* palette2;
    void* gfx;
    AnimState anim;
    TaskPool tasks;
    BtlObj actor;
    u32 unk_14C;
    u32 unk_150;
    s16 unk_154;
    s16 unk_156;
    u16 flags;
    u8 unk_15A;
    u8 unk_15B;
    const EmyDef* def;
    u8 angle;
    u8 unk_161;
    u16 unk_162;
    s32 unk_164;
    s32 unk_168;
    u32 unk_16C;
    s32 x;
    s32 y;
    s32 unk_178;
    s32 unk_17C;
    s32 unk_180;
} EmyWork;

typedef struct EmyObj {
    s32 x;
    s32 y;
    s32 z;
} EmyObj;

#endif
