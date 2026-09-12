#ifndef GUARD_EVT_TASKS_H
#define GUARD_EVT_TASKS_H

#include "types.h"

struct EvtObj;
struct EvtObjParam;
struct EvtObjWork;
struct EvtShadowWork;

void task_evt_obj_0(struct EvtObjWork* work, struct EvtObjParam* param);
s32 task_evt_obj_1(struct EvtObjWork* work);
void task_evt_obj_2(struct EvtObjWork* work);
void task_evt_obj_3(struct EvtObjWork* work);
void task_evt_shadow_0(struct EvtShadowWork* work, struct EvtObj* obj);
s32 task_evt_shadow_1(void);
void task_evt_shadow_2(struct EvtShadowWork* work);
void task_evt_shadow_3(struct EvtShadowWork* work);

#endif
