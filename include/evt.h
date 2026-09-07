#ifndef GUARD_EVT_H
#define GUARD_EVT_H

#include "types.h"
#include "anim.h"
#include "taskpool.h"
#include "evt_types.h"
#include "game.h"


typedef struct EvtObj {
    s32 unk_00;
    s32 x;
    s32 y;
    s32 z;
    s32 unk_10;
    u16 flags;
    u16 unk_16;
    void* unk_18;
    u16 unk_1C;
    u8 unk_1E[0x02];
    s32 unk_20;
    s32 unk_24;
    u8 unk_28;
} EvtObj;

typedef struct EvtObjRes {
    u16 unk_00;
    u8 unk_02[0x06];
    void* unk_08;
} EvtObjRes;

typedef struct EvtObjParam {
    EvtObjRes* unk_00;
    EvtObj* unk_04;
} EvtObjParam;

typedef struct EvtObjWork {
    EvtObj* obj;
    void* tiles;
    u16* palette;
    u8 anim[0x18];
    u8 unk_24[0x14];
} EvtObjWork;

typedef struct EvtShadowWork {
    void* palette;
    EvtObj* obj;
    void* tiles;
    void* tiles2;
    void* tiles3;
} EvtShadowWork;

void* AllocObjTiles(u16 a, s32 b);
void AnimInit(AnimState* a, s32 b, s32 c);
void* AnimUpdate(AnimState* a);
void* AnimGetGfx(AnimState* a);
void TaskCreate(void* a, void* b, void* c);
void TaskPoolInit(TaskPool* a, s32 count);
void TaskPoolUpdate(TaskPool* a);
void func_0801CE70(EvtObjWork* work);

extern u8 gUnk_08B22CBC[];
extern u8 gUnk_08B22CE4[];
extern u8 gUnk_08F69BE4[];
extern u8 gTaskDescEvtShadow[];

void task_evt_obj_0(EvtObjWork* work, EvtObjParam* param);
s32 task_evt_obj_1(EvtObjWork* work);
void task_evt_obj_2(EvtObjWork* work);
void task_evt_obj_3(EvtObjWork* work);
void task_evt_shadow_0(EvtShadowWork* work, EvtObj* obj);
s32 task_evt_shadow_1(void);
void task_evt_shadow_2(EvtShadowWork* work);
void task_evt_shadow_3(EvtShadowWork* work);

#endif /* GUARD_EVT_H */
