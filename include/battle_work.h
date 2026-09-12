#ifndef GUARD_BATTLE_WORK_H
#define GUARD_BATTLE_WORK_H

#include "types.h"
#include "taskpool.h"
#include "battle_bounds.h"

#include "battle_actor_types.h"

typedef struct BtlWork {
    s32 unk_000;
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
    s32 unk_010;
    s32 unk_014;
    u8 unk_018;
    u8 unk_019;
    s16 unk_01A;
    s32 unk_01C;
    s32 unk_020;
    s32 unk_024;
    s32 unk_028;
    TaskPool taskPools[3];
    u64 unk_068;
    u8 unk_070;
    u8 unk_071;
    s16 unk_072;
    s16 unk_074;
    u16 unk_076;
    BtlObj* unk_078;
    BtlObj* unk_07C;
    ListNode unk_080;
    ListNode unk_090;
    s32 unk_0A0;
    u8 unk_0A4;
    u8 unk_0A5[0x03];
    BtlObj* unk_0A8;
    BtlObj* unk_0AC;
    s16 unk_0B0;
    s8 unk_0B2;
    u8 unk_0B3;
    u8 unk_0B4;
    u8 unk_0B5[0x03];
    s32 unk_0B8;
    s32 unk_0BC;
    s32 unk_0C0;
    s16 unk_0C4;
    s16 unk_0C6;
    s16 unk_0C8;
    u8 unk_0CA[0x02];
    s32 unk_0CC;
    s32 unk_0D0;
    s32 unk_0D4;
    s16 unk_0D8;
    s16 unk_0DA;
    s16 unk_0DC;
    s16 unk_0DE;
    s16 unk_0E0;
    u8 unk_0E2;
    u8 unk_0E3;
    s16 unk_0E4;
    u8 unk_0E6[0x02];
    Task* unk_0E8;
    s16 unk_0EC;
    u8 unk_0EE;
    u8 unk_0EF;
    s32 unk_0F0;
    s32 unk_0F4;
    u16 unk_0F8;
    u8 unk_0FA;
    u8 unk_0FB;
    s32 unk_0FC;
    s32 unk_100;
    s32 unk_104;
    s32 unk_108;
    s32 unk_10C;
    void* unk_110;
    void* unk_114;
    u8 unk_118[0x08];
    s16 unk_120;
    u8 unk_122[0x02];
    s32 unk_124;
    BtlBoundsCallback unk_128;
    s32 unk_12C;
    s32 unk_130;
    s32 unk_134;
    s32 unk_138;
    u8 unk_13C[0x88];
    u16 unk_1C4;
    u16 unk_1C6;
    s16 unk_1C8;
    s8 unk_1CA;
    u8 unk_1CB;
    u16 unk_1CC;
    u8 unk_1CE[0x02];
} BtlWork;

typedef char BtlWork_size[(sizeof(BtlWork) == 0x1D0) ? 1 : -1];

extern BtlWork* gBtlWork;
extern BtlWork* gUnk_02039B9C;

#endif
