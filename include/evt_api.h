#ifndef GUARD_EVT_API_H
#define GUARD_EVT_API_H

#include "types.h"

struct EvtObj;

void func_0801CD74(struct EvtObj* obj, s32 anim);
void EvtObjSetPos(struct EvtObj* obj, s32 a, s32 b, s32 c);
void func_0801CD98(void* pool, struct EvtObj* obj, s32 res, s32 anim, s32 a, s32 b, s32 c);
void func_0801CE00(struct EvtObj* obj, u16 a);
s32 func_0801CE04(void* pool, void* desc, struct EvtObj* obj, s32 res, s32 anim, s32 a, s32 b, s32 c);

#endif
