#ifndef GUARD_CHARA_H
#define GUARD_CHARA_H

#include "chara_link_buffers.h"

#include "chara_link_state.h"

#include "chara_types.h"

#include "card_api.h"
#include "card_deck.h"

#include "chara_api.h"
#include "mode_test_api.h"

#include "sio_api.h"
#include "util.h"
#include "m4a_song.h"
#include "fade.h"
#include "btl_effect.h"
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
u8 func_080C56BC(void);
void func_080C5808(void);
void func_080C5850(u16 a, u16 b, u16 c, u16 d);
void func_080C58D0(void);
void func_080C58DC(void);
void func_080C58F0(void);
void func_080C590C(void);
void func_080C594C(void);
u8 func_080C5978(void);
void func_080C5A30(void);
s32 func_080C5AA4(void);
s32 func_080C5B50(void);
s32 func_080C5C24(void);
s32 func_080C5C7C(void);
void func_080C5D10(void);
void func_080C5D24(void);
void func_080C62F0(void (*a)(void));
s32 func_080C6314(void);
s32 func_080C6378(void);
void CharaObjFree(void);
void func_080C6990(u16 a, u8 b);
void func_080C6E7C(u8* src, u8* dst, u16 size, s16 count);

void func_08083D68(void);
void func_08083DD4(void);
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

extern u8 gUnk_09EF2F08[];
extern u16 gUnk_020397E0[4][2];
extern u16 gUnk_02039810[4][2];
extern u16 gUnk_02039B58[];
extern u16 gUnk_02039B68[];

extern s16 gUnk_0203BEB8;
extern u32 gUnk_0203BEBC;

extern u32 gSioStatus;
extern u32 gVBlankCounter;
extern vu16 gSystemFlags;

#endif /* GUARD_CHARA_H */
