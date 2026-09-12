#ifndef GUARD_MODE_VSBATTLE_H
#define GUARD_MODE_VSBATTLE_H

#include "card_api.h"

#include "fade.h"
#include "btl_effect.h"
#include "btl_collision.h"
#include "obj_api.h"
#include "battle_actor.h"
#include "display.h"
#include "types.h"
#include "engine_math.h"
#include "battle_work.h"
#include "game_state.h"
#include "anim.h"
#include "taskpool.h"
#include "malloc.h"
#include "m4a.h"
#include "enemy_common.h"
#include "hum_common.h"
#include "btl_api.h"

typedef struct CharaLinkData {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u16 unk_1C;
    u16 unk_1E;
} CharaLinkData;

typedef struct VsTaskArg {
    s32 unk_00;
    u32 unk_04 : 8;
} VsTaskArg;

typedef struct EmyDef {
    void* unk_00;
    void* unk_04;
    s32 unk_08;
    u16 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    u16 unk_16;
    u16 unk_18;
    u16 unk_1A;
    u32 unk_1C;
} EmyDef;

typedef struct EmyObj {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} EmyObj;

typedef struct EmyWork {
    void* tiles;
    void* unk_004;
    void* unk_008;
    void* gfx;
    AnimState anim;
    TaskPool unk_028;
    BtlObj unk_03C;
    u32 unk_14C;
    u32 unk_150;
    s16 unk_154;
    s16 unk_156;
    u16 unk_158;
    u8 unk_15A;
    u8 unk_15B;
    EmyDef* unk_15C;
    u8 angle;
    u8 unk_161;
    u16 unk_162;
    s32 unk_164;
    s32 unk_168;
    u32 unk_16C;
    s32 unk_170;
    s32 unk_174;
    s32 unk_178;
    s32 unk_17C;
    s32 unk_180;
} EmyWork;

typedef struct HumSub {
    void* unk_00;
    void* tiles;
    void* palette;
    void* unk_0C;
    AnimState anim;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u16 unk_34;
    u16 unk_36;
    void* gfx;
} HumSub;

typedef struct HumWork {
    void* unk_000;
    void* tiles;
    void* palette;
    HumSub* unk_00C;
    HumSub* unk_010;
    AnimState anim;
    TaskPool unk_02C;
    BtlObj unk_040;
    s16 unk_150;
    s16 unk_152;
    u32 unk_154;
    u32 unk_158;
    u32 unk_15C;
    u32 unk_160;
    s32 unk_164;
    s32 unk_168;
    s32 unk_16C;
    u32 unk_170;
    s16 unk_174;
    u16 unk_176;
    void* unk_178;
    u16 unk_17C;
    u16 unk_17E;
    void* gfx;
    u32 unk_184;
} HumWork;

typedef struct HumSubDef {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
} HumSubDef;

typedef struct PrizeCardArg {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C[0x14];
} PrizeCardArg;

typedef struct HumDef {
    u16 unk_00;
    u16 unk_02;
    void* unk_04;
    u32 unk_08;
    u32 unk_0C;
} HumDef;

extern u16 gUnk_02039B88;
extern u16 gUnk_02039B8C;
extern u16 gUnk_02039B90;
extern u8 gUnk_02039B98;
extern u32 gSioPlayerId;
extern CharaLinkData gUnk_0203AA10;
extern CharaLinkData gUnk_0203AAC0;
extern s16 gSineTable[];
extern u8 gUnk_08F69BC4[];
extern u16 gUnk_09EDA4EC[];
extern TaskDesc gTaskDescBtlSora;
extern TaskDesc gTaskDescBtlMap;
extern TaskDesc gTaskDescBtlShadow;
extern TaskDesc gTaskDescBtlBadstatus;

void func_08010CC8(void);
void func_0801071C(void);
extern vu32 gFrameCounter;
extern u16 gBldCnt;
void func_0807E2F4(void);

void mode_vsbattle_0(u32 mode);
void mode_vsbattle_1(void);
void mode_vsbattle_2(void);
void func_0800C6B0(void);
void func_0800C6B4(void);
void func_0800C6B8(void);
void func_0800CB78(EmyWork* work);
void HumSubReleaseGraphics(HumSub* sub);
void func_0800E3D0(HumWork* work);
void HumSubUpdateAnimation(HumSub* sub);

#endif
