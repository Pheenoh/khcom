#ifndef GUARD_FORMATION_TYPES_H
#define GUARD_FORMATION_TYPES_H

#include "types.h"

typedef struct BtlFormStep {
    u32 id;
    s16 x;
    s16 y;
    s16 z;
    s16 delay;
} BtlFormStep;

typedef struct BtlFormEntry {
    s16 count;
    u8 unk_02[0x02];
    const BtlFormStep* steps;
    u16 delay;
} BtlFormEntry;

typedef struct BtlFormList {
    s16 count;
    u8 unk_02[0x02];
    const BtlFormEntry* const* entries;
    s16 threshold;
    u8 unk_0A[0x02];
} BtlFormList;

typedef char BtlFormStep_size[(sizeof(BtlFormStep) == 12) ? 1 : -1];
typedef char BtlFormEntry_size[(sizeof(BtlFormEntry) == 12) ? 1 : -1];
typedef char BtlFormList_size[(sizeof(BtlFormList) == 12) ? 1 : -1];

#endif
