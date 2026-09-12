#ifndef GUARD_EVT_H
#define GUARD_EVT_H

#include "evt_object_types.h"

#include "evt_tasks.h"

#include "obj_api.h"
#include "types.h"
#include "anim.h"
#include "taskpool.h"
#include "evt_types.h"
#include "game.h"
#include "evt_api.h"


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

void func_0801CD94(EvtObj* obj, s32 a);
void func_0801CE70(EvtObjWork* work);

#endif /* GUARD_EVT_H */
