#ifndef GUARD_MODE_STAFFROLL_H
#define GUARD_MODE_STAFFROLL_H

#include "types.h"
#include "staff_roll_types.h"

typedef struct StaffRollLabelArg {
    u16 unk_00;
    u16 unk_02;
    s32 x;
    s32 y;
} StaffRollLabelArg;


typedef struct StaffRollTaskArg {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    s32 x;
    s32 y;
    s32 targetX;
    s32 targetY;
} StaffRollTaskArg;

typedef struct StaffRollLogoArg {
    s32 unk_00;
    s32 unk_04;
    s32* unk_08;
    s32* unk_0C;
    u16 unk_10;
} StaffRollLogoArg;

typedef struct StaffRollSecnArg {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32* unk_0C;
    s32* unk_10;
} StaffRollSecnArg;

typedef struct StaffRollWork {
    u8 unk_000;
    u8 unk_001;
    u16 unk_002;
    u16 unk_004;
    u16 unk_006;
    s32 unk_008;
    s32 unk_00C;
    s32 unk_010;
    s32 unk_014;
    u8 unk_018[0x60];
    s32 unk_078;
    s32 unk_07C;
    s32 unk_080;
    s32 unk_084;
    s32 unk_088;
    s32 unk_08C;
    s32 unk_090;
    s32 unk_094;
    s32 unk_098;
    StaffRollScene* scene;
    u8 unk_0A0;
    u8 unk_0A1[0x3];
    s32 unk_0A4;
    s32 unk_0A8;
    s32 unk_0AC;
    s32 unk_0B0;
    s32 unk_0B4;
    s32 unk_0B8;
    s32 unk_0BC;
    s32 unk_0C0;
    s32 unk_0C4;
    s32 unk_0C8;
    s32* unk_0CC;
    s32 unk_0D0;
    s32 unk_0D4;
    s32 unk_0D8;
    s32 unk_0DC;
    s32 unk_0E0;
    s32 unk_0E4;
    s32 unk_0E8;
    s32 unk_0EC;
    s32 unk_0F0;
    s32 unk_0F4;
    u32 palette;
    u8 unk_0FC[0x14];
    u8 unk_110[0x14];
    s32 unk_124[6];
    u8 unk_13C[0x84];
    u8 unk_1C0[0x258];
} StaffRollWork;

#endif
