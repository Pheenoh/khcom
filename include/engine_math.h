#ifndef GUARD_ENGINE_MATH_H
#define GUARD_ENGINE_MATH_H

#include "types.h"

void ApproachAngle(u16* value, u16 target, u16 shift);
void ApproachAngle16(u16* value, u16 target, u16 shift);
void ApproachValue(s32* value, s32 target, u16 steps);
void func_0800592C(s32* value, s32 target, u16 steps);
void SeedRand(u32 seed);
u32 Rand(void);
void SeedRandom(u32 seed);
u16 GetRandom(void);

#endif
