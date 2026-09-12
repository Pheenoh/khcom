#ifndef GUARD_ENGINE_MATH_H
#define GUARD_ENGINE_MATH_H

#include "types.h"

u8 GetAngle(s32 x0, s32 y0, s32 x1, s32 y1);
s16 GetAngleDiff(s32 a, s32 b);
s32 GetAngleDiff16(s32 a, s32 b);
void ApproachAngle(u16* value, u16 target, u16 shift);
void ApproachAngle16(u16* value, u16 target, u16 shift);
void ApproachValue(s32* value, s32 target, u16 steps);
void func_0800592C(s32* value, s32 target, u16 steps);
void func_0805F1C0(s32* value, s32 target);
void SeedRand(u32 seed);
u32 Rand(void);
void SeedRandom(u32 seed);
u16 GetRandom(void);

s32 Sqrt8(s32 a);

#endif
