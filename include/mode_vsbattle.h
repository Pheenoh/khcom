#ifndef GUARD_MODE_VSBATTLE_H
#define GUARD_MODE_VSBATTLE_H

#include "hum_types.h"

#include "enemy_types.h"

#include "chara_types.h"

#include "prize_types.h"

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


typedef struct VsTaskArg {
    s32 unk_00;
    u32 unk_04 : 8;
} VsTaskArg;





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
