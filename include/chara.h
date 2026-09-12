#ifndef GUARD_CHARA_H
#define GUARD_CHARA_H

#include "display.h"
#include "battle_actor.h"
#include "types.h"
#include "engine_math.h"
#include "game_state.h"
#include "taskpool.h"
#include "gba/syscall.h"
#include "key.h"
#include "malloc.h"
#include "game.h"
#include "mode.h"
#include "pallet.h"

typedef struct MaskFadeWork {
    u8* unk_000;
    u16 unk_004;
    u16 unk_006;
    s16 unk_008;
    s16 unk_00A;
    u8 unk_00C[0x20];
    u8 unk_02C[0x20];
    s8 unk_04C[0x1F4];
} MaskFadeWork;

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
typedef struct ChgCardObjWork {
    s16 unk_00;
    s16 unk_02;
    s8 unk_04;
    u8 unk_05[0x03];
    s32* unk_08;
    s32* unk_0C;
    s32* unk_10;
    s32* unk_14;
    u8* unk_18;
    u8* unk_1C;
    s32 unk_20;
    s32 unk_24;
    s16 unk_28;
    u8 unk_2A;
    u8 unk_2B;
    s16 unk_2C;
    u8 unk_2E[0x02];
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
} ChgCardObjWork;

typedef struct ChgCardObjParam {
    s32* unk_00;
    s32* unk_04;
    s32* unk_08;
    s32* unk_0C;
    u8* unk_10;
    u8* unk_14;
    s32 unk_18;
    s32 unk_1C;
    u16 unk_20;
} ChgCardObjParam;

typedef struct CharaObjParam2 {
    u32 unk_00;
    u16 unk_04;
    u8 unk_06[0x02];
    u32 unk_08;
    u16 unk_0C;
    u8 unk_0E[0x02];
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
} CharaObjParam2;

typedef struct CharaObj {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    u16 unk_10;
    u8 unk_12[0x02];
    u32 unk_14;
    u16 unk_18;
    u8 unk_1A[0x02];
    u32 unk_1C;
    u16 unk_20;
    u8 unk_22[0x02];
    u32 unk_24;
    u16 unk_28;
    u8 unk_2A[0x02];
    u32 unk_2C;
    u16 unk_30;
    u8 unk_32[0x02];
    u32 unk_34;
    u16 unk_38;
    s16 unk_3A;
    s32 unk_3C;
    s16 unk_40;
    s16 unk_42;
    u8 unk_44;
    u8 unk_45;
    u16 unk_46[0x400];
    u16 unk_846[0x400];
    u32 unk_1048;
    u32 unk_104C;
    u16 unk_1050[32];
    u16 unk_1090;
    u8 unk_1092[0x02];
} CharaObj;

typedef struct CharaPrizeArgs {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x14];
} CharaPrizeArgs;

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

typedef struct MaskFadeArgs {
    u8* unk_00;
    u32 unk_04 : 16;
    u32 unk_06 : 16;
} MaskFadeArgs;

void task_chara_mask_fade_0(MaskFadeWork* work, MaskFadeArgs* args);
u8 task_chara_mask_fade_1(MaskFadeWork* work);
void task_chara_mask_fade_2(void);
void task_chara_mask_fade_3(void);
void task_chgCardObj_0(ChgCardObjWork* work, ChgCardObjParam* param);
u8 task_chgCardObj_1(ChgCardObjWork* work);
void task_chgCardObj_2(void);
void task_chgCardObj_3(void);
u8 func_080C54B4(void);
u8 func_080C55DC(void);
u8 func_080C56BC(void);
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
s32 func_080C5B50(void);
s32 func_080C5C24(void);
s32 func_080C5C7C(void);
void func_080C5D00(void);
void func_080C5D10(void);
void func_080C5D24(void);
s32 func_080C5D50(void);
s32 func_080C5D80(void);
void func_080C5DC0(s32 (*a)(void), s32 (*b)(void));
s32 func_080C5E58(void);
s32 func_080C5ECC(void);
void func_080C5F94(void);
s32 func_080C6008(void);
void func_080C61D4(void);
s32 func_080C60D8(void);
void func_080C62F0(void (*a)(void));
s32 func_080C6314(void);
s32 func_080C6378(void);
void func_080C640C(CharaObjParam2* param);
void CharaObjFree(void);
void func_080C6894(CharaObjParam* param);
void func_080C6990(u16 a, u8 b);
void func_080C6E7C(u8* src, u8* dst, u16 size, s16 count);
void func_080C6EB0(u8* src, u8* dst, u16 size, s16 count);

s32 func_0805F588(s32 a, s32 b);
s32 func_0805F5A4(s32* a, s32* b);
void m4aSongNumStart(u16 id);
u32 func_08006ED4(void* a, void* b, void* c);
u32 func_0800702C(void* a, void* b, void* c);
void SioKeyStateUpdateA(u16 a);
void SioKeyStateUpdateB(u16 a);
u16* func_08083C94(void);
u16* func_08083D7C(void);
void func_080078A4(void);
void SioReset(void);
void func_08083D68(void);
void func_08083DD4(void);
u8 func_080128EC(void);
void func_080149BC(s32 x, s32 y);
void func_08014B30(s32 x, s32 y);
void func_0801475C(s32 x, s32 y, s32 z);
void func_08096DC4(TaskPool* pool, CharaPrizeArgs* args);
void func_08006184(s32 a, s32 b);
void func_080063A8(void);
void func_08006B4C(void);
void m4aSongNumStop(u16 id);
extern TaskDesc gUnk_09EF34A8;

extern s16 gSineTable[];
extern CharaLinkData gUnk_0203AAC0;
extern u16 gUnk_0203AA10[];
extern u16 gUnk_0203A9EC;
extern u16 gUnk_0203A9F0;
extern vu32 gFrameCounter;
extern Mode gModeSioError;
extern u16 gUnk_0203982C[];
extern u32 gSioPlayerId;
extern u8 gUnk_020397FC;
extern u8 gUnk_02039824;
extern u8 gUnk_02039B60;
extern s32 (*gUnk_02039804)(void);
extern s32 (*gUnk_020397F8)(void);
extern s16 gUnk_020397D4;
extern u32 gUnk_020397F0;
extern u16* gUnk_0203C37C;
extern u16 gUnk_0203C378;
extern u16* gUnk_0203C390;
extern u16 gUnk_0203C394;
extern u16* gUnk_0203C398;
extern u16* gUnk_0203C39C;
extern u16 gUnk_0203C3B8;
extern u8 gUnk_09EF2F08[];
extern u16 gUnk_020397E0[4][2];
extern u16 gUnk_02039810[4][2];
extern u16 gUnk_02039B58[];
extern u16 gUnk_02039B68[];
extern s8 gUnk_0203C38C;
extern s8 gUnk_0203C380;
extern s8 gUnk_0203C384;
extern s8 gUnk_0203C3A0;
extern s8 gUnk_0203C3A4;
extern s8 gUnk_0203C3A8;
extern void (*gUnk_0203C3AC)(void);
extern u16 gUnk_0203C3B0;
extern u16 gUnk_0203C3B4;
extern u16 gUnk_0203C388;
extern s16 gUnk_0203BEA4;
extern s16 gUnk_0203BEA8;
extern u32 gUnk_0203BEA0;
extern u32 gUnk_0203BEB0;
extern s16 gUnk_0203BEB8;
extern u32 gUnk_0203BEBC;
extern u32 gUnk_0203BD10[];
extern u32 gUnk_0203BEC0[];
extern u32 gUnk_0203C050[];
extern u32 gUnk_0203C1E0[];
extern u16 gUnk_0203C370;
extern s8 gUnk_0203C374;
extern u32 gSioStatus;
extern u32 gVBlankCounter;
extern vu16 gSystemFlags;
extern void (*gUnk_0203BEAC)(void);

#ifdef VERSION_EU
extern u16 gUnkEu_0203C964;
extern u16 gUnkEu_0203C970;
extern u16 gUnkEu_0203C97C;
#endif

#endif /* GUARD_CHARA_H */
