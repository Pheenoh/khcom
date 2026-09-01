#ifndef GUARD_UNK_080DFEBC_H
#define GUARD_UNK_080DFEBC_H

#include "types.h"

typedef struct UnkStruct_080DFB8C {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06[0x02];
    s32 unk_08;
    s32 unk_0C;
    void* unk_10;
    u16* unk_14;
    u16* unk_18;
    u16* unk_1C;
} UnkStruct_080DFB8C;

typedef struct UnkStruct_080DFF1C {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} UnkStruct_080DFF1C;

typedef struct UnkStruct_02039BA0 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u16 unk_10;
    u16 unk_12;
    u8 unk_14[0x0C];
    s32 unk_20;
    s32 unk_24;
    u8 unk_28[0x40];
    s32 unk_68;
    u8 unk_6C[0x04];
    u32 unk_70;
    u8 unk_74[0x04];
    u8 unk_78[0x14];
    u8 unk_8C[0x14];
    u8 unk_A0[0x14];
    u8 unk_B4[0x14];
    u8 unk_C8[0x14];
} UnkStruct_02039BA0;

typedef struct UnkStruct_0203C7AC {
    u32 unk_00;
    u8 unk_04[0x02];
    u16 unk_06;
    u8 unk_08[0x05];
    u8 unk_0D;
    u8 unk_0E[0x02];
    s32 unk_10;
    s32 unk_14;
    u8 unk_18[0x08];
    u8 unk_20;
    u8 unk_21[0x03];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    u8 unk_30[0x14];
} UnkStruct_0203C7AC;

typedef struct UnkStruct_02034F20 {
    u16 unk_00;
    u16 unk_02;
    s32 unk_04;
    u8 unk_08;
    u8 unk_09[0x0B];
    s32 unk_14;
} UnkStruct_02034F20;

typedef struct UnkStruct_02034F24 {
    u8 unk_00[0x08];
} UnkStruct_02034F24;

typedef struct UnkStruct_02034F34 {
    u8 unk_00[0x18];
    u16* unk_18;
    u16* unk_1C;
    u16* unk_20;
} UnkStruct_02034F34;

typedef struct UnkStruct_02034F80 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
} UnkStruct_02034F80;

typedef struct UnkStruct_02034F7C {
    u8 unk_00;
    u8 unk_01[0x03];
    UnkStruct_02034F80* unk_04;
} UnkStruct_02034F7C;

typedef struct UnkStruct_02034F84 {
    u8 unk_00;
    u8 unk_01;
} UnkStruct_02034F84;

typedef struct UnkStruct_02039D6C {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    s32 unk_04;
} UnkStruct_02039D6C;

typedef struct UnkStruct_02039BB0Tail {
    u32 unk_00[0x0D];
} UnkStruct_02039BB0Tail;

typedef struct UnkStruct_02039BB0 {
    u8 unk_00;
    u8 unk_01[0x07];
    u32 unk_08;
    u8 unk_0C;
    u8 unk_0D;
    u8 unk_0E;
    u8 unk_0F;
    u8 unk_10[0x174];
    UnkStruct_02039BB0Tail unk_184;
} UnkStruct_02039BB0;

typedef struct UnkStruct_080E92B8 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02[0x02];
    u8 unk_04[0x21C];
    UnkStruct_02039BB0Tail unk_220;
} UnkStruct_080E92B8;

typedef struct UnkStruct_080E7D80 {
    void* unk_00;
    void* unk_04;
    u16 unk_08;
    u8 unk_0A[0x0B];
    u8 unk_15;
} UnkStruct_080E7D80;

typedef struct UnkStruct_0203C7B8 {
    u16 unk_00;
    u8 unk_02[0x02];
    UnkStruct_080DFF1C unk_04;
    UnkStruct_080E7D80* unk_14;
} UnkStruct_0203C7B8;

typedef struct UnkStruct_080DEDD8 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04[0x04];
} UnkStruct_080DEDD8;

typedef struct UnkStruct_080DEE18 {
    u8 unk_00[0x0C];
    u8 unk_0C;
} UnkStruct_080DEE18;

typedef struct UnkStruct_080E8864 {
    s32 unk_00;
    u8 unk_04[0x0C];
} UnkStruct_080E8864;

typedef struct UnkStruct_080E8E24 {
    u8 unk_00[0x02];
    u16 unk_02;
} UnkStruct_080E8E24;

typedef struct UnkStruct_080E8F50 {
    u8 unk_00;
    u8 unk_01[0x03];
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10[0x04];
    u16 unk_14;
    u8 unk_16[0x02];
} UnkStruct_080E8F50;

typedef struct UnkStruct_080E590C {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
    UnkStruct_080DFF1C unk_08;
    u8 unk_18;
    u8 unk_19[0x03];
    u32 unk_1C;
    u8 unk_20[0x28];
    u8 unk_48[0x2C];
    u8 unk_74;
    u8 unk_75[0x0B];
    s32 unk_80;
    s32 unk_84;
    u8 unk_88[0x1C];
    u8 unk_A4[0x18];
    void* unk_BC;
    u8 unk_C0[0x04];
    void* unk_C4;
    s16 unk_C8;
    s16 unk_CA;
    s32 unk_CC;
    u8 unk_D0[0x14];
    u8 unk_E4[0x14];
} UnkStruct_080E590C;

typedef struct FldRes {
    u8 unk_00[0x06];
    u16 unk_06;
} FldRes;

typedef struct UnkStruct_080ECFE8 {
    u8 unk_000[0x20];
    FldRes* unk_020;
    u8 unk_024[0x14];
    FldRes* unk_038;
    FldRes* unk_03C;
    u8 unk_040[0x20];
    FldRes* unk_060;
    u8 unk_064[0x0C];
    FldRes* unk_070;
    u8 unk_074[0xE4];
    FldRes* unk_158[3];
} UnkStruct_080ECFE8;

typedef struct UnkStruct_080ED06C {
    FldRes* unk_000;
    u8 unk_004[0x134];
    FldRes* unk_138;
    u8 unk_13C[0x04];
    FldRes* unk_140;
} UnkStruct_080ED06C;

typedef struct UnkStruct_080EE50C {
    u8 unk_000[0x14];
    FldRes* unk_014;
    u8 unk_018[0x1C];
    FldRes* unk_034;
    u8 unk_038[0x08];
    FldRes* unk_040;
    u8 unk_044[0x14C];
    FldRes* unk_190;
} UnkStruct_080EE50C;

typedef struct UnkStruct_080EE580 {
    FldRes* unk_000;
    u8 unk_004[0x164];
    FldRes* unk_168;
    u8 unk_16C[0x14];
    FldRes* unk_180;
    u8 unk_184[0x04];
    FldRes* unk_188;
} UnkStruct_080EE580;

extern UnkStruct_02039BA0* gUnk_02039BA0;
extern UnkStruct_02039BB0 gUnk_02039BB0;
extern UnkStruct_02039D6C gUnk_02039D6C[];
extern UnkStruct_0203C7AC* gUnk_0203C7AC;
extern UnkStruct_0203C7B8* gUnk_0203C7B8;
extern UnkStruct_080DFB8C* gUnk_02034F1C;
extern UnkStruct_02034F20* gUnk_02034F20;
extern UnkStruct_02034F24* gUnk_02034F24;
extern u16 gUnk_02034F28;
extern u16 gUnk_02034F2A;
extern UnkStruct_02034F34* gUnk_02034F34;
extern u8 gUnk_02034F40;
extern UnkStruct_080DFF1C gUnk_02034F48[];
extern u8 gUnk_02034F78;
extern u8 gUnk_02034F79;
extern u16 gUnk_02034F7A;
extern UnkStruct_02034F7C* gUnk_02034F7C;
extern UnkStruct_02034F80 gUnk_02034F80;
extern UnkStruct_02034F84* gUnk_02034F84;
extern s32 gUnk_02034F88;
extern s32 gUnk_02034FB0;
extern s32 gUnk_02034FD4;
extern u8 gUnk_0203C590[];
extern UnkStruct_02034F84 gUnk_0203C598[];
extern void* gUnk_0203DB10;
extern UnkStruct_080E7D80 gUnk_0984C1CC;
extern UnkStruct_02034F7C gUnk_0984CECC[];
extern const u8 gUnk_0984D134[][8];
extern const u8 gUnk_0984D314[][4];
extern const u8 gUnk_0984D32C[][4];
extern const u8 gUnk_0984D3F8[][4];
extern const u16 gUnk_09858238[];
extern const u8 gUnk_09961A64[][320];
extern const u8 gUnk_09963D64[][320];
extern const u8 gUnk_09966064[];
extern void* gUnk_09EF3C88;
extern const u8 gUnk_09EF6A34[];
extern const u8 gUnk_09EF6A42[];
extern u8 (*gUnk_09EF6A50[])(UnkStruct_080DFF1C*);
extern void* gUnk_09EF6AA0;
extern void* gUnk_09EF6AC0;
extern void* gUnk_09EF6B00;
extern void* gUnk_09EF6E64;
extern void* gUnk_09EF6EC4;

void* memcpy(void* dst, const void* src, unsigned long n);
void EwramFree(void* p);
u16 GetRandom(void);
void* GetBgCharBase(s32 bg);
void* GetBgScreenBase(s32 bg);
u8 RequestDma3Copy(void* src, void* dst, u16 size);
void* TaskCreate(void* pool, void* desc, void* arg);
void TaskPoolDestroy(void* pool);
void TaskPoolDraw(void* pool);
void* AnimUpdate(void* a);
void m4aMPlayVolumeControl(void* a, u16 b, u16 c);
void m4aSongNumStart(u16 id);
u16 CountCardsById(u16 cardId);
void func_080010CC(void* mode, s32 arg);
void func_080045AC(void* a, void* b, u8 c, u8 d, s32 e);
void func_080062F4(u16 a, s32 b);
u8 func_08005AC4(void* a);
void func_08012614(void* a, s32 b);
u8 func_08012660(void* a, s32 b);
u8 func_080840E4(void);
u8 func_080A42C8(s32 a);
s32 func_080DF548(s32 a);
void func_080DF6D0(UnkStruct_0203C7AC* p, u8 a);
UnkStruct_080DEDD8* func_080DEDD8(s32 a);
UnkStruct_080DEE18* func_080DEE18(u8 a);
UnkStruct_080DFB8C* func_080DFB8C(s32 x, s32 y);
UnkStruct_080DFB8C* func_080E08BC(s16 x, s16 y);
void func_080E0960(UnkStruct_080DFB8C* p, s32 n);
void func_080E2668(UnkStruct_02034F20* p, u8 a);
void func_080E4EB0(void* a, void* b, void* c, s16 d, s16 e);
void func_080E507C(void* a, void* b, void* c, s16 d, s16 e);
u8 func_080E524C(UnkStruct_080DFF1C* a, s32* b);
void func_080E5354(UnkStruct_080DFF1C* a, s32* b);
s32 func_080E55A4(s32 a, s32 b);
void func_080E5C00(void* a, u8 b, u8 c);
void func_080E5EAC(UnkStruct_080E590C* p);
u8* func_080E8644(void* a, u16 b, u16 c);
void func_080E83DC(s32 a, s32 b, s32 c);
void func_080E8864(UnkStruct_080E8864* p);
void func_080E8A24(UnkStruct_080E8864* p);
u8 func_080E86C8(UnkStruct_080DFB8C* p, s32 x, s32 y);
UnkStruct_080E8E24* func_080E8E74(u8 a);
void func_080EAB20(u8 a, s32 b, u8 c);
void func_080EABB8(u8 a, u8 b);
void func_080EAC60(u8 a, s32 b);

s32 func_080DFEBC(s32 x, s32 y, s32 z);
s32 func_080DFF1C(UnkStruct_080DFF1C* p);
s32 func_080DFF30(UnkStruct_080DFF1C* p);
void func_080DFF4C(UnkStruct_080DFF1C* p);
void func_080DFF5C(UnkStruct_080DFF1C* p, s16 x, s16 y, u8 a, u8 b);
s32 func_080E0010(s32 x);
s32 func_080E0044(s32 y);
void func_080E0298(s32 x, s32 y);
void func_080E02A8(s32 dx, s32 dy);
void func_080E02C0(s32 x, s32 y, s32 z);
u8 func_080E02E0(UnkStruct_080DFF1C* p, s16 a, s16 b);
u8 func_080E0378(void);
s32 func_080E0390(void);
s32 func_080E03C0(s32 a);
void func_080E0418(void);
void func_080E04EC(void);
void func_080E052C(u8 a);
void func_080E05E4(void);
void func_080E0820(void);
void func_080E0878(void);
u8 func_080E0938(u8 a);
void func_080E09B4(UnkStruct_080DFB8C* p, u8 n, u8 v);
void func_080E0A38(UnkStruct_080DFB8C* p);
void func_080E0B98(UnkStruct_080DFB8C* p, s32 n, u8 v);
void func_080E1C64(s16 x, s16 y, u8 n);
s32 func_080E1CA8(s16 x, s16 y);
u8 func_080E2BA0(u8 a);
void func_080E2BF8(u8 a);
s32 func_080E2E24(s16 a, s16 b, s16 c);
s32 func_080E2E9C(s16 a, s16 b, s16 c);
s32 func_080E2F14(s16 x, s16 y);
s32 func_080E2F48(s16 a, s16 b, s16 c, u8 d);
s32 func_080E2F98(s16 a, s16 b, s16 c, u8 d);
s32 func_080E300C(u8 d, s16 x, s16 y);
void func_080E3060(u8 i, s16 a, s16 b, s16 c);
void func_080E4FF0(void* p, s16 a, s16 b);
void func_080E51C0(void* p, s16 a, s16 b);
UnkStruct_080DFB8C* func_080E548C(s16 a, s16 b);
UnkStruct_02034F20* func_080E54A0(u8 a);
UnkStruct_02034F24* func_080E5590(u8 a);
s32 func_080E58F8(s16 a, s16 b);
void func_080E590C(UnkStruct_080E590C* p);
void func_080E5938(UnkStruct_080E590C* p);
s32 func_080E5968(UnkStruct_080E590C* p);
void func_080E5DEC(UnkStruct_080E590C* p);
u8 func_080E5E44(void);
void func_080E5F50(UnkStruct_080E590C* p);
s32 func_080E5FB4(UnkStruct_080E590C* p);
void func_080E6100(void);
UnkStruct_080DFB8C* func_080E67D4(s32 x, s32 y);
u8 func_080E68A4(s16 x, s16 y, u8 n);
s32 func_080E68E4(s16 x, s16 y, u8 w, u8 h, u8 n);
s32 func_080E6968(s16 a, s16 b, u8 c);
s16 func_080E6A14(s16 x, s16 y);
u8 func_080E7D64(UnkStruct_080DFF1C* a, u8 b);
s32 func_080E7D80(void* a);
s32 func_080E7DB8(u8 flag, void* a);
void func_080E7DF8(void);
void func_080E7FCC(void);
void func_080E84DC(UnkStruct_080DFF1C* p);
void func_080E8624(void);
void func_080E891C(UnkStruct_080E8864* p);
s32 func_080E89E4(s16 x, s16 y, const u8* p);
void func_080E8AC8(UnkStruct_080E8864* p);
s32 func_080E8C38(u8 a, u8 b);
s32 func_080E8C84(u8 a, u8 b);
u8 func_080E8D00(void);
UnkStruct_02034F80* func_080E8D1C(u8 a);
s32 func_080E8E24(UnkStruct_080E8E24* p);
u8 func_080E8F0C(void);
s32 func_080E8F50(UnkStruct_080E8E24* a, u8 b, s32 c, s32 d, s32 e);
u8 func_080E8FB8(u8 a, s32 b, s32 c, s32 d);
void func_080E9338(s32 a);
void func_080E92B8(UnkStruct_080E92B8* p);
void func_080E92F8(UnkStruct_080E92B8* p);
void func_080E988C(s32 a);
void func_080EA1E8(s32 a);
s32 func_080EAD3C(u8 i);
void func_080ECFE8(UnkStruct_080ECFE8* p, u8 a);
void func_080ED06C(UnkStruct_080ED06C* p, u8 a);
void func_080EE50C(UnkStruct_080EE50C* p, u8 a);
void func_080EE580(UnkStruct_080EE580* p, u8 a);
void func_080EE5E0(u8 a);
void func_080EE62C(u16 v);
s32 func_080EF3A0(UnkStruct_080E590C* p);

#endif /* GUARD_UNK_080DFEBC_H */
