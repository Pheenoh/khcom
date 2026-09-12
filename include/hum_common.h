#ifndef GUARD_HUM_COMMON_H
#define GUARD_HUM_COMMON_H

#include "types.h"

struct HumDef;
struct HumSub;
struct HumSubDef;
struct HumWork;

void HumInit(struct HumWork* work, struct HumDef* def);
void HumSubInit(struct HumWork* work, struct HumSub* sub, struct HumSubDef* def);
void HumReleaseResources(struct HumWork* work);
s32 _0800E434(struct HumWork* work);
s32 func_0800E5F0(struct HumWork* work);

#endif
