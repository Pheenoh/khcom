#ifndef GUARD_PRIZE_TYPES_H
#define GUARD_PRIZE_TYPES_H

#include "types.h"

typedef struct PrizeCardArg {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C[0x14];
} PrizeCardArg;

typedef struct PoohPrizeArgs {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    u16 unk_14;
} PoohPrizeArgs;

#endif
