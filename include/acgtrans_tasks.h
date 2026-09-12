#ifndef GUARD_ACGTRANS_TASKS_H
#define GUARD_ACGTRANS_TASKS_H

#include "types.h"

struct AcgTransConfig;
struct AcgTransWork;

void task_acgtrans_0(struct AcgTransWork* work, struct AcgTransConfig* cfg);
s32 task_acgtrans_1(struct AcgTransWork* work);

#endif
