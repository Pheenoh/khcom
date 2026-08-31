#ifndef GUARD_CHARA_H
#define GUARD_CHARA_H

#include "types.h"
#include "game.h"

typedef struct MaskFadeWork {
    u8* unk_000;
    u16 unk_004;
    u16 unk_006;
    u16 unk_008;
    u16 unk_00A;
    u8 unk_00C[0x20];
    u8 unk_02C[0x20];
    s8 unk_04C[0x1F4];
} MaskFadeWork;

typedef struct MaskFadeArgs {
    u8* unk_00;
    u16 unk_04;
    u16 unk_06;
} MaskFadeArgs;

void task_chara_mask_fade_0(MaskFadeWork* work, MaskFadeArgs* args);
u8 task_chara_mask_fade_1(MaskFadeWork* work);
void task_chara_mask_fade_2(void);
void task_chara_mask_fade_3(void);
void func_080C57A4(void);
void func_080C57B4(void);
void func_080C5808(void);
void func_080C5850(u16 a, u16 b, u16 c, u16 d);
void func_080C58D0(void);
void func_080C58DC(void);
void func_080C58F0(void);
void func_080C590C(void);
s32 func_080C5930(void);
void func_080C594C(void);
u8 func_080C5978(void);
void func_080C5A30(void);
void func_080C5A3C(void (*a)(void), void (*b)(void), u8 c);
s32 func_080C5AA4(void);
void func_080C5D00(void);
void func_080C5D10(void);
void func_080C5D24(void);
s32 func_080C5D50(void);
s32 func_080C5D80(void);
void func_080C6878(void);
void func_080C6EB0(u8* src, u8* dst, s16 size, s16 count);

void RequestDma3Copy(void* src, void* dst, u16 size);
void EwramFree(void* p);
void TaskPoolDestroy(void* a);
u16 GetKeysPressed(void);
u16 GetRandom(void);
void func_080078A4(void);
void func_08006E60(void);
void func_08083D68(void);
void func_08083DD4(void);
void CpuFastSet(void* dst, void* src, s32 n);

extern u8 gUnk_09EF082F[];
extern u16 gUnk_020397E0[4][2];
extern u16 gUnk_02039810[4][2];
extern u16 gUnk_02039B58[];
extern u16 gUnk_02039B68[];
extern void* gUnk_02034CD8;
extern u8 gUnk_02034CE0[];
extern u8 gUnk_0203C38C;
extern s8 gUnk_0203C3A0;
extern s8 gUnk_0203C3A8;
extern void (*gUnk_0203C3AC)(void);
extern u16 gUnk_0203C3B0;
extern u16 gUnk_0203BEA4;
extern u16 gUnk_0203BEA8;
extern u32 gUnk_0203BEA0;
extern u32 gUnk_0203BEB0;
extern u16 gUnk_0203BEB8;
extern u32 gUnk_0203BEBC;
extern u32 gUnk_0203BD10[];
extern u32 gUnk_0203BEC0[];
extern u32 gUnk_0203C050[];
extern u32 gUnk_0203C1E0[];
extern u16 gUnk_0203C370;
extern s8 gUnk_0203C374;
extern u32 gUnk_02039820;
extern u32 gUnk_03006C68;
extern vu16 gUnk_03006C78;
extern void (*gUnk_0203BEAC)(void);

#endif /* GUARD_CHARA_H */
