#ifndef GUARD_FLD_TASKS_H
#define GUARD_FLD_TASKS_H

#include "types.h"

struct FldActor;
struct FldShadowWork;
struct FldWork;

void task_fld_sora_0(struct FldWork* work);
u8 task_fld_sora_1(struct FldWork* work, void* task);
void task_fld_sora_2(struct FldWork* work);
void task_fld_sora_3(struct FldWork* work);
void task_fld_riku_0(struct FldWork* work);
u8 task_fld_riku_1(struct FldWork* work, void* task);
void task_fld_riku_2(struct FldWork* work);
void task_fld_riku_3(struct FldWork* work);
void task_fld_shadow_0(struct FldShadowWork* work, struct FldActor* obj);
s32 task_fld_shadow_1(struct FldShadowWork* work);
void task_fld_shadow_2(struct FldShadowWork* work);
void task_fld_shadow_3(struct FldShadowWork* work);

#endif
