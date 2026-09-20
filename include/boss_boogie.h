#ifndef GUARD_BOSS_BOOGIE_H
#define GUARD_BOSS_BOOGIE_H

#include "anim.h"
#include "taskpool.h"
#include "battle_actor.h"

typedef struct BoogieWork {
    s32 unk_000;
    s16 unk_004;
    u16 unk_006;
    void* tiles;
    void* palette;
    void* palette2;
    AnimState anim;
    TaskPool tasks;
    BtlObj actor;
    s32 unk_150;
    s32 unk_154;
    s32 unk_158;
    s32 animationIndex;
    s32 unk_160;
    void* unk_164;
    s32 unk_168;
    Task* dialog;
    u32 unk_170;
    u8 unk_174;
    u8 unk_175;
    u8 unk_176[2];
} BoogieWork;

typedef struct StatusObjDef {
    void* sprites;
    u16 spriteCount;
    u16 unk_06;
} StatusObjDef;

typedef struct StatusAnimDef {
    u32 anims;
    u32 gfxTable;
    void* tiles;
    u16 animId;
    u16 unk_0E;
} StatusAnimDef;

typedef struct BoogieFx {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x14];
} BoogieFx;

typedef struct BoogieResource {
    u8 unk_00[10];
    s16 unk_0A;
} BoogieResource;

typedef struct BoogiePalette {
    u8 unk_00[6];
    u8 unk_06;
} BoogiePalette;

void func_080D8F14(BoogieWork* work);
void SetBoogieAnimation(BoogieWork* work, s32 a, u16 b);
u8 ClampBoogiePosition(s32* a, s32* b);
void task_bos_boogie_0(BoogieWork* work);
u8 task_bos_boogie_1(BoogieWork* work);
void task_bos_boogie_2(BoogieWork* work);
void task_bos_boogie_3(BoogieWork* work);
void func_080D9A14(void);
void func_080D9A58(void);
u32 GetBoogieDiceState(void);

#endif
