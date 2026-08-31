#ifndef GUARD_EVT_H
#define GUARD_EVT_H

#include "types.h"
#include "game.h"

typedef struct UnkStruct_02039DC8 {
    u8 unk_00[0x58];
    s32 unk_58;
    s32 unk_5C;
} UnkStruct_02039DC8;

extern UnkStruct_02039DC8* gUnk_02039DC8;

typedef struct EvtObj {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    u16 unk_14;
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
    EvtObj* unk_00;
    void* unk_04;
    u16* unk_08;
    u8 unk_0C[0x18];
    u8 unk_24[0x14];
} EvtObjWork;

typedef struct EvtShadowWork {
    void* unk_00;
    EvtObj* unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
} EvtShadowWork;

void* func_080028F8(u16 a, s32 b);
void func_08005968(void* a, s32 b, s32 c);
void* func_08005A64(void* a);
void* func_08005AFC(void* a);
void func_08000E14(void* a, void* b, void* c);
void func_08000E64(void* a, s32 b);
void func_08000EA4(void* a);
void func_0801CE70(EvtObjWork* work);

extern u8 gUnk_08B22CBC[];
extern u8 gUnk_08B22CE4[];
extern u8 gUnk_08F69BE4[];
extern u8 gUnk_09EDADE0[];

void task_evt_obj_0(EvtObjWork* work, EvtObjParam* param);
s32 task_evt_obj_1(EvtObjWork* work);
void task_evt_obj_2(EvtObjWork* work);
void task_evt_obj_3(EvtObjWork* work);
void task_evt_shadow_0(EvtShadowWork* work, EvtObj* obj);
s32 task_evt_shadow_1(void);
void task_evt_shadow_2(EvtShadowWork* work);
void task_evt_shadow_3(EvtShadowWork* work);

#endif /* GUARD_EVT_H */
