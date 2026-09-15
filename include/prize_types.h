#ifndef GUARD_PRIZE_TYPES_H
#define GUARD_PRIZE_TYPES_H

#include "types.h"

typedef struct PrizeCardArg {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x14];
} PrizeCardArg;

typedef struct PoohPrizeArgs {
    s32 unk_00;
    s32 x;
    s32 y;
    s32 z;
    s32 unk_10;
    u16 unk_14;
} PoohPrizeArgs;

#endif
