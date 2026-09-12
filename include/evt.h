#ifndef GUARD_EVT_H
#define GUARD_EVT_H

#include "evt_tasks.h"

#include "obj_api.h"
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

typedef struct EvtAnimDef {
    void* unk_00;
    void* unk_04;
    void* unk_08;
} EvtAnimDef;

typedef struct EvtObjAnim {
    EvtAnimDef* unk_00;
    u8 unk_04[0x08];
    u16 unk_0C;
    u16 unk_0E;
} EvtObjAnim;

typedef struct EvtObjResTable {
    EvtObjRes unk_00;
    u8 unk_0C[0x04];
} EvtObjResTable;

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


extern EvtObjAnim gUnk_0813766C[];
extern EvtObjResTable gUnk_0813B09C[];
extern u8 gTaskDescEvtObj[];


extern u8 gUnk_08B22CBC[];
extern u8 gUnk_08B22CE4[];
extern u8 gUnk_08F69BE4[];
extern u8 gTaskDescEvtShadow[];

void func_0801CD74(EvtObj* obj, s32 anim);
void EvtObjSetPos(EvtObj* obj, s32 a, s32 b, s32 c);
void func_0801CD94(EvtObj* obj, s32 a);
void func_0801CD98(void* pool, EvtObj* obj, s32 res, s32 anim, s32 a, s32 b, s32 c);
void func_0801CE00(EvtObj* obj, u16 a);
s32 func_0801CE04(void* pool, void* desc, EvtObj* obj, s32 res, s32 anim, s32 a, s32 b, s32 c);
void func_0801CE70(EvtObjWork* work);


#endif /* GUARD_EVT_H */
