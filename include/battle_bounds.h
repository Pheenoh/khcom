#ifndef GUARD_BATTLE_BOUNDS_H
#define GUARD_BATTLE_BOUNDS_H

#include "types.h"

typedef u8 (*BtlBoundsCallback)(s32* x, s32* y, s32* z, s32* floor);

u8 func_0801050C(s32* a, s32* b, s32* c, s32* d);
u8 func_080BD4A8(s32* p, s32* b, s32* a, s32* out);

#endif
