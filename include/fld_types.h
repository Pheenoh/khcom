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

typedef struct FldWork {
    void* tiles;
    FldRes* palette;
    u8 unk_08[0x0A];
    u16 unk_12;
    u8 unk_14[0x02];
    u16 unk_16;
    u8 unk_18[0x08];
    void* gfx;
    u8 unk_24[0x14];
    u8 unk_38[0x10];
    s32 unk_48;
    u8 unk_4C[0x18];
    u8 unk_64;
    u8 unk_65;
    u16 unk_66;
    u8 unk_68[0x04];
    u32 unk_6C;
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    s32 unk_7C;
    s32 unk_80;
    s32 unk_84;
    u8 unk_88[0x0C];
    u32 unk_94;
    s16 unk_98;
    s16 unk_9A;
    u8 unk_9C;
    u8 unk_9D;
    u16 unk_9E;
    s32 unk_A0;
    u16 unk_A4;
    u8 unk_A6[0x02];
    s32 unk_A8;
    u16* unk_AC;
    s32 unk_B0;
    s32 unk_B4;
    s32 unk_B8;
    u8 unk_BC;
    u8 unk_BD[0x03];
} FldWork;

#endif
