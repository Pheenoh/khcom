#ifndef GUARD_BOS_TASKS_H
#define GUARD_BOS_TASKS_H

#include "types.h"

struct BosMapConfig;
struct BosShadowWork;
struct BtlObj;

void task_bos_map_0(s32 unused, struct BosMapConfig* cfg);
s32 task_bos_map_1(void);
void task_bos_shadow_0(struct BosShadowWork* work, struct BtlObj* obj);
s32 task_bos_shadow_1(void);
void task_bos_shadow_2(struct BosShadowWork* work);
void task_bos_shadow_3(struct BosShadowWork* work);

#endif
