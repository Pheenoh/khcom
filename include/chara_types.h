#ifndef GUARD_CHARA_TYPES_H
#define GUARD_CHARA_TYPES_H

#include "types.h"

typedef struct CharaObjParam {
    u32 unk_00;
    u16 unk_04;
    u8 unk_06[0x02];
    u32 unk_08;
    u16 unk_0C;
    u8 unk_0E[0x02];
    u32 unk_10;
    u16 unk_14;
    u8 unk_16[0x02];
    u32 unk_18;
    u16 unk_1C;
    u8 unk_1E[0x02];
    u32 unk_20;
    u16 unk_24;
    u8 unk_26[0x02];
    u32 unk_28;
    u16 unk_2C;
    u8 unk_2E[0x02];
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3C;
    u32 unk_40;
    u16 unk_44;
} CharaObjParam;

typedef struct CharaLinkData {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
    u64 unk_0C;
    u64 unk_14;
    u16 unk_1C;
    u16 unk_1E;
} CharaLinkData;

#endif
