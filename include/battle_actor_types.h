#ifndef GUARD_BATTLE_ACTOR_TYPES_H
#define GUARD_BATTLE_ACTOR_TYPES_H

#include "types.h"
#include "taskpool.h"

typedef struct Collider {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 radius;
    s32 height;
    ListNode unk_18;
    u8 unk_28[0x04];
    u8 unk_2C;
    u8 unk_2D;
    u16 unk_2E;
    u16 unk_30;
    u8 unk_32[0x02];
    s32 unk_34;
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4C;
    struct Collider* unk_50;
    struct Collider* self;
    u32 unk_58;
} Collider;

typedef struct BtlObj {
    s32 unk_000;
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
    s32 unk_010;
    s32 unk_014;
    s32 unk_018;
    s32 unk_01C;
    s16 unk_020;
    u8 unk_022[0x02];
    s32 unk_024;
    s32 unk_028;
    s16 unk_02C;
    s16 unk_02E;
    s16 unk_030;
    u8 unk_032[0x02];
    u64 unk_034;
    u16 unk_03C;
    u8 unk_03E[0x02];
    Collider unk_040;
    u16 unk_09C;
    u16 unk_09E;
    u16 unk_0A0;
    s16 unk_0A2;
    u16 unk_0A4;
    u8 unk_0A6[0x02];
    s32 unk_0A8;
    s32 unk_0AC;
    u8 unk_0B0;
    u8 unk_0B1;
    u16 unk_0B2;
    u16 unk_0B4;
    u8 unk_0B6[0x02];
    ListNode unk_0B8;
    u8 unk_0C8[0x04];
    u16 unk_0CC;
    s16 unk_0CE;
    s16 unk_0D0;
    s16 unk_0D2;
    s32 unk_0D4;
    s32 unk_0D8;
    struct BtlObj* unk_0DC;
    u16 unk_0E0;
    s16 unk_0E2;
    struct BtlCardWork* unk_0E4;
    s32 unk_0E8;
    u16 unk_0EC;
    u8 unk_0EE[0x02];
    s32 unk_0F0;
    s32 unk_0F4;
    s32 unk_0F8;
    u8 unk_0FC[0x08];
    s16 unk_104;
    s16 unk_106;
    s32 unk_108;
    s32 unk_10C;
} BtlObj;

typedef struct BtlCardWork {
    u8 unk_000[0xF4];
    s32 unk_0F4;
    u16 unk_0F8;
    u8 unk_0FA[0x02];
} BtlCardWork;

typedef char Collider_size[(sizeof(Collider) == 0x5C) ? 1 : -1];
typedef char BtlObj_size[(sizeof(BtlObj) == 0x110) ? 1 : -1];

#endif
