#ifndef GUARD_PC_TASKS_H
#define GUARD_PC_TASKS_H

#include "types.h"

struct BtlObj;
struct PcAcdDmgWork;

void task_pc_acddmg_0(struct PcAcdDmgWork* work, struct BtlObj* obj);
s32 task_pc_acddmg_1(struct PcAcdDmgWork* work);

#endif
