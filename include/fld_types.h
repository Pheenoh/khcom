#ifndef GUARD_FLD_TYPES_H
#define GUARD_FLD_TYPES_H

#include "types.h"

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

#endif
