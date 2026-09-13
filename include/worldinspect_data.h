#ifndef GUARD_WORLDINSPECT_DATA_H
#define GUARD_WORLDINSPECT_DATA_H

#include "types.h"

typedef struct WorldinspectNav {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    s16 unk_0E;
    s16 unk_10;
    u8 unk_12[0x02];
} WorldinspectNav;

typedef struct WorldinspectMsg {
    u16 unk_00;
    u16 unk_02;
    void* unk_04;
    u16 unk_08;
    u8 unk_0A[0x02];
    void* unk_0C;
    u16 unk_10;
    u8 unk_12[0x02];
    void* unk_14;
    void* unk_18;
    u16 unk_1C;
    u8 unk_1E[0x02];
    void* unk_20;
    u16 unk_24;
    u8 unk_26[0x02];
    void* unk_28;
    void* unk_2C;
    u16 unk_30;
    u16 unk_32;
} WorldinspectMsg;

typedef WorldinspectNav MdWorldNav;
typedef WorldinspectMsg MdMsg;

extern WorldinspectNav gUnk_09EF8FAC[12];
extern WorldinspectMsg gUnk_09EF909C[14];

#endif
