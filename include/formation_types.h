#ifndef GUARD_FORMATION_TYPES_H
#define GUARD_FORMATION_TYPES_H

#include "types.h"

typedef struct BtlFormStep {
    u32 unk_00;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
} BtlFormStep;

typedef struct BtlFormEntry {
    s16 unk_00;
    u8 unk_02[0x02];
    const BtlFormStep* unk_04;
    u16 unk_08;
} BtlFormEntry;

typedef struct BtlFormList {
    s16 unk_00;
    u8 unk_02[0x02];
    const BtlFormEntry* const* unk_04;
    s16 unk_08;
    u8 unk_0A[0x02];
} BtlFormList;

typedef char BtlFormStep_size[(sizeof(BtlFormStep) == 12) ? 1 : -1];
typedef char BtlFormEntry_size[(sizeof(BtlFormEntry) == 12) ? 1 : -1];
typedef char BtlFormList_size[(sizeof(BtlFormList) == 12) ? 1 : -1];

#endif
