#ifndef GUARD_SIO_H
#define GUARD_SIO_H

#include "types.h"

#define REG_DISPCNT (*(vu16*)0x04000000)
#define REG_DISPSTAT (*(vu16*)0x04000004)
#define REG_TM3CNT_L (*(vu16*)0x0400010C)
#define REG_TM3CNT_H (*(vu16*)0x0400010E)
#define REG_SIODATA32 (*(vu16*)0x04000120)
#define REG_SIOMLT_RECV (*(vu16*)0x04000120)
#define REG_SIOMULTI0 (*(vu16*)0x04000120)
#define REG_SIOMULTI1 (*(vu16*)0x04000122)
#define REG_SIOMULTI2 (*(vu16*)0x04000124)
#define REG_SIOMULTI3 (*(vu16*)0x04000126)
#define REG_SIOCNT (*(vu16*)0x04000128)
#define REG_SIOCNT32 (*(vu32*)0x04000128)
#define REG_SIODATA8 (*(vu16*)0x0400012A)
#define REG_SIOMLT_SEND (*(vu16*)0x0400012A)
#define REG_RCNT (*(vu16*)0x04000134)
#define REG_IE (*(vu16*)0x04000200)
#define REG_IF (*(vu16*)0x04000202)
#define REG_IME (*(vu16*)0x04000208)

typedef void (*IntrFunc)(void);

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u16 unk_04[4];
    u8 unk_0C;
    u8 unk_0D;
    u8 unk_0E;
    u8 unk_0F;
    u8 unk_10;
    u8 unk_11;
    u8 unk_12;
    u8 unk_13;
    u8 unk_14;
    u8 unk_15;
    u16 unk_16;
    u8 unk_18;
    u8 unk_19;
    u8 unk_1A;
    u8 unk_1B;
    u16 unk_1C[4][32];
    u8 unk_11C;
    u8 unk_11D;
    u8 unk_11E;
    u8 unk_11F;
    u16 unk_120[2][4][32];
    u8 unk_320;
    u8 unk_321;
} SioWork;

extern u8* gUnk_02034040;
extern u16 gUnk_02034044;
extern u16 gUnk_02034046;
extern u8 gUnk_02034054;
extern u8 gUnk_0203406C;
extern u16 gUnk_0203406E;
extern u8 gUnk_02034070;
extern u8 gUnk_02034071;
extern u8 gUnk_02034072;
extern u8 gUnk_02034073;
extern s8 gUnk_02034074;
extern u16 gUnk_02034076;
extern u16 gUnk_02034078;
extern u8 gUnk_020397D0;
extern s16 gUnk_020397D4;
extern u32 gUnk_020397F0;
extern s32 (*gUnk_020397F8)(void);
extern u8 gUnk_020397FC;
extern u8 gUnk_02039800;
extern s32 (*gUnk_02039804)(void);
extern u32 gUnk_02039820;
extern u8 gUnk_02039824;
extern u32 gUnk_02039828;
extern u8 gUnk_0203982C;
extern SioWork gUnk_02039830;
extern u8 gUnk_02039B50;
extern u8 gUnk_02039B60;

extern IntrFunc* gIntrTableSerial;
extern IntrFunc* gIntrTableVCount;
extern IntrFunc* gIntrTableVBlank;
extern IntrFunc* gIntrTableTimer3;
extern IntrFunc gHBlankCallback;
extern IntrFunc gVCountCallback;
extern IntrFunc gVBlankCallback;
extern IntrFunc* gIntrTableHBlank;


void CpuSet(void* src, void* dst, u32 ctrl);

u8 func_08006B74(void);
void func_08006B80(u16* a, u16* b);
s32 func_08006BA0(u8* p);
u8* func_08006BA8(void);
u16 func_08006BB4(void);
void SetVBlankCallback(IntrFunc fn);
void ResetVBlankCallback(void);
void SetVCountCallback(IntrFunc fn);
void ResetVCountCallback(void);
void SetHBlankCallback(IntrFunc fn);
void ResetHBlankCallback(void);
void SetSerialCallback(IntrFunc fn);
void ResetSerialCallback(void);
void SetTimer3Callback(IntrFunc fn);
void ResetTimer3Callback(void);
void func_08006D08(void);
void func_08006E60(void);
void func_08006E70(void);
void func_08006E74(void);
u32 func_08006ED4(u8* a, u16* b, u16 (*c)[2]);
u32 func_0800702C(u8* a, u16* b, u16 (*c)[2]);
void func_080070B4(void);
void func_080070DC(void);
void func_0800712C(u16* p);
void func_08007210(u16 (*c)[2]);
void func_08007318(void);
void func_080073A4(void);
void func_080073B4(void);
void func_08007444(void);
u8 func_08007454(void);
void func_08007550(void);
void func_08007694(void);
void func_08007768(void);
void func_08007798(void);
void func_080077C4(void);
void func_08007814(void);
void func_08007874(void);
void func_080078A4(void);
u8 func_080078E8(void);

void VBlankIntr(void);
void HBlankIntrDummy(void);
void VCountIntrDummy(void);
void SerialIntrDummy(void);
void VBlankIntrSio(void);

#endif /* GUARD_SIO_H */
