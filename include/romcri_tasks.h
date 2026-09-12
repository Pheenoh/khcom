#ifndef GUARD_ROMCRI_TASKS_H
#define GUARD_ROMCRI_TASKS_H

#include "types.h"

struct RomcriEff2Work;
struct RomcriEffWork;

void task_romcri_eff_0(struct RomcriEffWork* work, s32 arg);
u8 task_romcri_eff_1(struct RomcriEffWork* work);
void task_romcri_eff_3(void);
void task_romcri_eff2_0(struct RomcriEff2Work* work, s32 arg);
u8 task_romcri_eff2_1(struct RomcriEff2Work* work);
void task_romcri_eff2_3(void);

#endif
