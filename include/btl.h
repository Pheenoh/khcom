#ifndef GUARD_BTL_H
#define GUARD_BTL_H

#include "types.h"

typedef struct ListNode {
    void* unk_00;
    u8 unk_04[0x04];
    struct ListNode* unk_08;
    u16 unk_0C;
} ListNode;

typedef struct Collider {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
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
    struct Collider* unk_54;
    u32 unk_58;
} Collider;

typedef struct BtlWork {
    u16 unk_000;
    u16 unk_002;
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
    s32 unk_010;
    s32 unk_014;
    u8 unk_018;
    u8 unk_019;
    u16 unk_01A;
    s32 unk_01C;
    s32 unk_020;
    s32 unk_024;
    s32 unk_028;
    u8 unk_02C[0x3C];
    u64 unk_068;
    u8 unk_070;
    u8 unk_071;
    u16 unk_072;
    u16 unk_074;
    u16 unk_076;
    Collider* unk_078;
    Collider* unk_07C;
    ListNode unk_080;
    ListNode unk_090;
    s32 unk_0A0;
    u8 unk_0A4[0x04];
    void* unk_0A8;
    void* unk_0AC;
    u8 unk_0B0[0x03];
    u8 unk_0B3;
    u8 unk_0B4;
    u8 unk_0B5[0x1B];
    s32 unk_0D0;
    u8 unk_0D4[0x04];
    s16 unk_0D8;
    s16 unk_0DA;
    s16 unk_0DC;
    s16 unk_0DE;
    s16 unk_0E0;
    u8 unk_0E2;
    u8 unk_0E3;
    u16 unk_0E4;
    u8 unk_0E6[0x02];
    s32 unk_0E8;
    u8 unk_0EC[0x02];
    u8 unk_0EE;
    u8 unk_0EF;
    u8 unk_0F0[0x0A];
    u8 unk_0FA;
    u8 unk_0FB;
    s32 unk_0FC;
    s32 unk_100;
    s32 unk_104;
    s32 unk_108;
    s32 unk_10C;
    u8 unk_110[0x18];
    u8 (*unk_128)(s32 a);
    s32 unk_12C;
    u8 unk_130[0x0C];
    u8 unk_13C[0x88];
    u8 unk_1C4[0x0C];
} BtlWork;

typedef struct BtlLockonWork {
    void* unk_000;
    void* unk_004;
    u32 unk_008;
    u8 unk_00C[0x14];
    u32 unk_020;
    u16 unk_024;
    u8 unk_026[0x02];
} BtlLockonWork;

typedef struct BtlAreaWork {
    void* unk_000;
    void* unk_004;
    u8 unk_008;
    u8 unk_009;
    u16 unk_00A;
} BtlAreaWork;

typedef struct BtlSoraWork {
    u32 unk_000;
    u32 unk_004;
    u32 unk_008;
    u32 unk_00C;
    u8 unk_010[0xF];
    u8 unk_01F;
    u8 unk_020[0x4];
    u32 unk_024;
    u8 unk_028[0x10];
    u32 unk_038;
    u32 unk_03C;
    u32 unk_040;
    u32 unk_044;
    u32 unk_048;
    u32 unk_04C;
    u32 unk_050;
    u32 unk_054;
    u32 unk_058;
    u32 unk_05C;
    u16 unk_060;
    u8 unk_062[0xA];
    u16 unk_06C;
    u16 unk_06E;
    u16 unk_070;
    u8 unk_072[0x2];
    u32 unk_074;
    u32 unk_078;
    u8 unk_07C[0x4];
    u32 unk_080;
    u8 unk_084[0xC];
    u32 unk_090;
    u8 unk_094[0x18];
    u16 unk_0AC;
    u16 unk_0AE;
    u16 unk_0B0;
    u16 unk_0B2;
    u32 unk_0B4;
    u32 unk_0B8;
    u32 unk_0BC;
    u32 unk_0C0;
    u32 unk_0C4;
    u32 unk_0C8;
    u32 unk_0CC;
    u32 unk_0D0;
    u8 unk_0D4[0x8];
    u16 unk_0DC;
    u16 unk_0DE;
    u16 unk_0E0;
    u16 unk_0E2;
    u8 unk_0E4[0x1C];
    u16 unk_100;
    u8 unk_102[0xA];
    u16 unk_10C;
    u8 unk_10E[0x14];
    u16 unk_122;
    BtlWork* unk_124;
    u8 unk_128[0x4];
    u16 unk_12C;
    u8 unk_12E[0x1A];
    u32 unk_148;
    u8 unk_14C[0x4];
    u32 unk_150;
    u16 unk_154;
    u16 unk_156;
    u16 unk_158;
    u16 unk_15A;
    u8 unk_15C[0x16];
    u8 unk_172;
    u8 unk_173[0x1];
    u16 unk_174;
    u8 unk_176[0x2];
    u16 unk_178;
    u8 unk_17A[0xA];
    u32 unk_184;
    u32 unk_188;
    u8 unk_18C[0x10];
    u32 unk_19C;
    u32 unk_1A0;
    u8 unk_1A4[0x4];
    u16 unk_1A8;
    u8 unk_1AA[0x2];
} BtlSoraWork;

extern BtlWork* gUnk_02039B84;

extern u8 gUnk_08B1EA00[];
extern u8 gUnk_08F69BA4[];

void func_080140C0(s32* a, s32* b, s32* c);
void func_0801AF08(void* p);
void func_0802F284(s32 a, s32 b, s32 c);

void* LoadObjTiles(void* src, s32 size);
void* LoadObjPalette(void* src, s32 size);
void ReleaseObjTiles(void* p);
void ReleaseObjPalette(void* p);

#endif /* GUARD_BTL_H */
