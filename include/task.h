#ifndef GUARD_TASK_H
#define GUARD_TASK_H

#include "types.h"
#include "evt.h"

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

typedef struct UnkStruct_02039BB0 {
    u8 unk_000[0x08];
    u32 unk_008;
    u8 unk_00C[0x16E];
    u16 unk_17A;
    u16 unk_17C;
    u8 unk_17E[0x5E];
    u32 unk_1DC;
} UnkStruct_02039BB0;

extern UnkStruct_02039BB0 gUnk_02039BB0;
extern u32 gFrameCounter;
extern EvtObjAnim gUnk_0813766C[];
extern EvtObjResTable gUnk_0813B09C[];
extern u8 gUnk_09EDADC8[];

void func_08002A10(void* a, void* b);
void func_08005974(void* a, u16 b, u16 c, void* d, void* e);
void func_0800FDD0(s32 a);
void func_08085C3C(void);
void _08085D04(s32 a);
void func_080DFAF4(s32 a, s32 b);

u8 func_0801CB6C(s32 x0, s32 y0, s32 x1, s32 y1);
void func_0801CC80(void);
void func_0801CCB4(void);
void func_0801CD20(void);
void func_0801CD74(EvtObj* obj, s32 anim);
void func_0801CD8C(EvtObj* obj, s32 a, s32 b, s32 c);
void func_0801CD94(EvtObj* obj, s32 a);
void func_0801CD98(void* pool, EvtObj* obj, s32 res, s32 anim, s32 a, s32 b, s32 c);
void func_0801CE00(EvtObj* obj, u16 a);
s32 func_0801CE04(void* pool, void* desc, EvtObj* obj, s32 res, s32 anim, s32 a, s32 b, s32 c);

#endif /* GUARD_TASK_H */
