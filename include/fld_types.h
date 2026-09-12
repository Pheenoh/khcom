#ifndef GUARD_FLD_TYPES_H
#define GUARD_FLD_TYPES_H

#include "types.h"
#include "listpool.h"

typedef struct FldPos {
    s32 x;
    s32 y;
    s32 z;
    s32 unk_0C;
} FldPos;

typedef struct FldAnimDef {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C;
    u8 unk_0D[0x03];
} FldAnimDef;

typedef struct FldRes {
    u8 unk_00[0x06];
    u16 unk_06;
} FldRes;

typedef struct FldActor {
    FldPos unk_00;
    s32 unk_10;
    u8 angle;
    u8 unk_15[0x05];
    u16 unk_1A;
    u8 unk_1C[0x14];
    u16 unk_30;
    u16 unk_32;
    u8 unk_34[0x06];
    u16 unk_3A;
    s32 unk_3C;
    ListPool unk_40;
} FldActor;

typedef struct FldObj {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10[0x0A];
    s16 unk_1A;
    ListNode unk_1C;
    u16 unk_30;
    u8 unk_32[0x02];
} FldObj;

typedef char FldActor_size[(sizeof(FldActor) == 0x50) ? 1 : -1];

#endif
