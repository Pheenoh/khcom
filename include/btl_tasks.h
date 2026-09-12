#ifndef GUARD_BTL_TASKS_H
#define GUARD_BTL_TASKS_H

#include "types.h"

struct BtlAreaWork;
struct BtlLockonWork;
struct BtlMapWork;
struct BtlRikuWork;
struct BtlSoraWork;
struct BtlTaskArg;

void task_btl_lockon_0(struct BtlLockonWork* work);
u8 task_btl_lockon_1(struct BtlLockonWork* work);
void task_btl_lockon_2(struct BtlLockonWork* work);
void task_btl_lockon_3(struct BtlLockonWork* work);
void task_btl_area_0(struct BtlAreaWork* work);
u8 task_btl_area_1(struct BtlAreaWork* work);
void task_btl_area_2(struct BtlAreaWork* work);
void task_btl_area_3(struct BtlAreaWork* work);
void task_btl_sora_0(struct BtlSoraWork* work, struct BtlTaskArg* arg);
s32 task_btl_sora_1(struct BtlSoraWork* work);
void task_btl_sora_2(struct BtlSoraWork* work);
void task_btl_sora_3(struct BtlSoraWork* work);
void task_btl_riku_0(struct BtlRikuWork* work, struct BtlTaskArg* arg);
s32 task_btl_riku_1(struct BtlRikuWork* work);
void task_btl_riku_2(struct BtlRikuWork* work);
void task_btl_riku_3(struct BtlRikuWork* work);
void task_btl_map_0(struct BtlMapWork* work);
s32 task_btl_map_1(struct BtlMapWork* work);

#endif
