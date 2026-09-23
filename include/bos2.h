#include "registration_data.h"
#include "battle_actor_types.h"
#ifndef GUARD_BOS2_H
#define GUARD_BOS2_H

extern void* gUnk_09EF280C[48];
extern const u16* gUnk_09EF28CC;
extern void* gUnk_09EF28D0[48];
extern void* gUnk_09EF2990;
extern u32 gUnk_09EF2994[27];
extern u32 gUnk_09EF2A00;
extern u32 gUnk_09EF2A04;
extern u32 gUnk_09EF2A08;
extern u32 gUnk_09EF2A0C;
extern u32 gUnk_09EF2A10;
extern u32 gUnk_09EF2A14;
extern u32 gUnk_09EF2A18;
extern u32 gUnk_09EF2A1C;
extern s8 gUnk_09EF2A38[9];
extern s8 gUnk_09EF2A41;
extern s16 gUnk_09EF2A42[12];

extern void* gUnk_09EF275C[2][15];


#include "background_actor_assets.h"

#include "boss_jafar_types.h"

#include "prize_types.h"

#include "chara_types.h"

#include "card_api.h"

#include "chara_api.h"
#include "pallet.h"
#include "m4a_song.h"
#include <string.h>
#include "fade.h"
#include "btl_effect.h"
#include "btl_collision.h"
#include "obj_api.h"
#include "battle_actor.h"
#include "display.h"
#include "types.h"
#include "engine_math.h"
#include "listpool.h"
#include "game_state.h"
#include "anim.h"
#include "taskpool.h"
#include "game.h"
#include "btl_api.h"
#include "acgtrans.h"
#include "mode_battle_data.h"

typedef struct BosPos {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} BosPos;

typedef struct DsdWork {
    BtlObj body[3];
    u32 unk_330;
    u32 unk_334;
    u32 unk_338;
    s16 unk_33C;
    u16 unk_33E;
    u32 unk_340;
    u32 unk_344;
    u32 unk_348;
    u16 unk_34C;
    u16 unk_34E;
    s16 unk_350;
    s16 unk_352;
    s16 unk_354;
    s16 unk_356;
    s16 unk_358;
    s8 unk_35A;
    u8 unk_35B;
    s32 unk_35C;
    void* tiles;
    void* palette;
    void* tiles2;
    void* palette2;
    void* palette3;
    void* tiles3;
    void* palette4;
    TaskPool tasks;
    u16 unk_390;
    u16 unk_392;
} DsdWork;

typedef struct DsdEnergy1Work {
    DsdWork* dsd;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    u8 unk_28;
    u8 unk_29;
    u8 unk_2A[0x2];
    s32 unk_2C;
    s32 unk_30;
    s16 unk_34;
    u16 unk_36;
    s16 unk_38;
    u16 unk_3A;
    s16 unk_3C;
    u8 unk_3E[0x2];
    s16 unk_40;
    u8 unk_42[0x2];
    void* gfx;
    s8 unk_48;
    u8 unk_49[0x3];
} DsdEnergy1Work;

typedef struct DsdEnergy2Work {
    DsdWork* dsd;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s16 unk_2C;
    u16 unk_2E;
    s16 unk_30;
    s16 unk_32;
    s8 unk_34;
    u8 unk_35;
    u8 unk_36[0x2];
    void* gfx;
    s8 unk_3C;
    u8 unk_3D[0x3];
} DsdEnergy2Work;

typedef struct DsdRockWork {
    DsdWork* dsd;
    s32 x;
    s32 y;
    s32 z;
    s32 vx;
    s32 unk_14;
    s32 vz;
    void* gfx;
    u8 unk_20;
    u8 unk_21[0x3];
} DsdRockWork;

typedef struct DsdCircleWork {
    DsdWork* dsd;
    void* gfx;
    s32 x;
    s32 y;
    s32 z;
    s16 unk_14;
    s16 unk_16;
    s16 unk_18;
    s8 unk_1A;
    u8 unk_1B;
    s16 unk_1C;
    u16 unk_1E;
} DsdCircleWork;

typedef struct DsdMainWork {
    DsdWork* dsd;
    u16 unk_004;
    s16 unk_006;
    u8 unk_008;
    u8 unk_009[0x1];
    s16 unk_00A;
    void* tiles;
    void* tiles2;
    void* gfx;
    void* gfx2;
    AnimState anim;
    AnimState anim2;
    void* palette;
    void* palette2;
    s8 unk_054;
    u8 unk_055[0x3];
    TaskPool tasks;
    void* unk_06C;
    s8 unk_070;
    u8 unk_071[0x3];
    BtlObj body;
    void* unk_184;
    void* unk_188;
    void* unk_18C;
} DsdMainWork;

typedef struct DsdItaWork {
    DsdWork* dsd;
    u32 unk_004;
    u8 unk_008[0x58];
    s32 x;
    s32 y;
    s32 z;
    s32 unk_06C;
    s32 unk_070;
    s16 unk_074;
    u16 unk_076;
    s16 unk_078;
    u8 unk_07A;
    u8 unk_07B[0x1];
    u16 unk_07C;
    s16 unk_07E;
    s32 unk_080;
    u8 unk_084[0x4];
    void* gfx;
    void* gfx2;
} DsdItaWork;

typedef struct JfWork {
    BtlObj body;
    BtlObj sub;
    s32 unk_220;
    s32 unk_224;
    s32 unk_228;
    s32 unk_22C;
    s32 unk_230;
    s32 unk_234;
    u32 unk_238;
    u32 unk_23C;
    u16 unk_240;
    s16 unk_242;
    s16 unk_244;
    s16 unk_246;
    s16 unk_248;
    s16 unk_24A;
    s16 unk_24C;
    s16 unk_24E;
    s16 unk_250;
    u8 unk_252[0x2];
    TaskPool tasks;
    u16 unk_268;
    u16 unk_26A;
} JfWork;

typedef struct JfMapWork {
    s16 unk_00;
    s16 unk_02;
} JfMapWork;

typedef struct JfLampWork {
    JfWork* jf;
    void* tiles;
    void* gfx;
    void* tiles2;
    void* gfx2;
    void* palette;
    void* palette2;
    s16 unk_1C;
    s16 unk_1E;
    s16 unk_20;
    s16 unk_22;
    u8 unk_24;
    u8 unk_25[0x3];
    s32 unk_28;
    u8 unk_2C[0x1];
    u8 unk_2D;
    s16 unk_2E;
    u8 unk_30[0x2];
    u8 unk_32;
    u8 unk_33[0x1];
    s16 unk_34;
    u16 unk_36;
    s32 unk_38;
    u8 unk_3C[0x6];
    u16 unk_42;
    TaskPool tasks;
} JfLampWork;

typedef struct JfRockWork {
    JfWork* jf;
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s16 unk_028;
    s16 unk_02A;
    u32 unk_02C;
    s32 x;
    s32 y;
    s32 z;
    u32 unk_03C;
    u8 unk_040[0x20];
    u64 unk_060;
    u8 unk_068[0x90];
    u16 unk_0F8;
    u8 unk_0FA[0x42];
    s32 unk_13C;
    s32 unk_140;
    s32 unk_144;
    s32 unk_148;
    s32 unk_14C;
    s32 unk_150;
    s32 unk_154;
    s16 unk_158;
    u8 unk_15A;
    u8 unk_15B[0x1];
    s16 unk_15C;
    s16 unk_15E;
    u8 unk_160;
    u8 unk_161[0x3];
    void* tiles2;
    void* palette2;
    void* gfx2;
    s32 x2;
    s32 y2;
    s32 z2;
    u8 unk_17C;
    u8 unk_17D;
    s16 unk_17E;
    TaskPool tasks;
    u8 unk_194;
    u8 unk_195[0x3];
} JfRockWork;

typedef struct JfMajinWork {
    JfWork* jf;
    void* tiles;
    void* palette;
    void* palette2;
    void* gfx;
    AnimState anim;
    u8 unk_2C;
    u8 unk_2D[0x3];
    u32 unk_30;
    u32 unk_34;
    u8 unk_38[0x4];
    s16 unk_3C;
    u8 unk_3E[0x2];
    s16 y;
    u8 unk_42[0x2];
    s16 unk_44;
    s16 unk_46;
    u8 unk_48;
    u8 unk_49;
    s16 unk_4A;
    u32 unk_4C;
    u32 x;
    u32 y2;
    u32 z;
    s16 unk_5C;
    s16 unk_5E;
    u16 unk_60;
    u16 unk_62;
    u16 unk_64;
    u16 unk_66;
    u16 unk_68;
    s8 unk_6A;
    u8 unk_6B[0x1];
    TaskPool tasks;
    u32 unk_80;
} JfMajinWork;

typedef struct JfBorderlineWork {
    BosPos* unk_000;
    u32 tiles;
    u32 palette;
    void* gfx;
    void* gfx2;
    void* gfx3;
    void* gfx4;
    AnimState anim;
    AnimState anim2;
    AnimState anim3;
    AnimState anim4;
    void* gfx5;
    AnimState anim5;
    s32 unk_098;
    s32 unk_09C;
    u32 unk_0A0;
    s32 unk_0A4;
    s32 unk_0A8;
    u32 unk_0AC;
    u16 unk_0B0;
    u16 unk_0B2;
    u8 unk_0B4;
    u8 unk_0B5;
    u8 unk_0B6[0x2];
} JfBorderlineWork;

typedef char JfWork_size[(sizeof(JfWork) == 0x26C) ? 1 : -1];

extern u8 gUnk_096FB744[];
extern const EmyKind gUnk_0961A7B0;
extern const s16 gUnk_0961A89E[9];
extern const s16 gUnk_0961A8B0[10];
extern u8 gUnk_096C5C64[];
extern u8 gUnk_096FB484[];
extern const s16 gUnk_0961A7D0[47];
extern const s8 gUnk_0961A82E[10];
extern u32 gFrameCounter;

extern u8 gUnk_09665C04[];
extern u8 gUnk_096CAC64[];
extern u8 gUnk_096983E4[];
extern u8 gUnk_096FB8C4[];
extern u8 gUnk_096A2F04[];
extern u8 gUnk_096FB8E4[];
extern u8 gUnk_096869A4[];
extern u8 gUnk_096FB864[];
extern u8 gUnk_096FB884[];
extern const s8 gUnk_0961A894[10];
extern u8 gUnk_096FB904[];
extern u8 gUnk_09682AA4[];
extern u8 gUnk_096FB5A4[];
extern u8 gUnk_096FB584[];
extern u8 gUnk_09685DA4[];
extern u8 gUnk_096FB604[];
extern u8 gUnk_06010000[];
extern u8 gUnk_0965DC04[];
extern u8 gUnk_096FB404[];
extern u8 gUnk_096C4C64[];
extern u8 gUnk_096C5464[];
extern u8 gUnk_096C6464[];
extern u8 gUnk_0961A668[];

extern u8 gUnk_08F69BC4[];
extern const s16 gUnk_0961A860[6];
extern const s16 gUnk_0961A6A8[49];
extern const s8 gUnk_0961A70A[6];
extern const u16 gUnk_0961A710[16][3];

void func_080C1A48(JfBorderlineWork* work);
s32 __divsi3(s32 a, s32 b);
void func_080BE3DC(u8 a, JfMajinWork* work);
void func_080BE478(u8 a, JfMajinWork* work);
void func_080BE380(u8 a, u16 b, JfMajinWork* work);

u8 task_bos_jf_borderline_1(JfBorderlineWork* work);
void task_bos_jf_borderline_3(JfBorderlineWork* work);

u8 task_bos_dsd_rock_1(DsdRockWork* work);
void task_bos_dsd_rock_3(void);
void task_bos_dsd_circle_0(DsdCircleWork* work, void* arg);
void task_bos_dsd_circle_2(DsdCircleWork* work);
void task_bos_dsd_circle_3(void);
void task_bos_dsd_energy2_3(void);
void func_080C2734(DsdMainWork* work);
void func_080C288C(DsdMainWork* work);
void func_080C2828(DsdMainWork* work);
void func_080C297C(DsdMainWork* work, s32 x, s32 y, s32 z);
void task_bos_dsd_main_3(DsdMainWork* work);
void task_bos_dsd_energy1_0(DsdEnergy1Work* work, void* arg);
void task_bos_dsd_energy2_0(DsdEnergy2Work* work, void* arg);
s32 func_080BDB58(void);
void func_080BDAAC(void);
void func_080BDB28(s16 a);
void task_bos_jf_map_0(JfMapWork* work, JfMapArg* arg);
u8 task_bos_jf_map_1(JfMapWork* work);
u8 func_080BD7F8(s32* p, s32* a, s32 b, s32* out);
void task_bos_dsd_energy1_2(DsdEnergy1Work* work);
void task_bos_dsd_energy2_2(DsdEnergy2Work* work);
void task_bos_dsd_map_0(void);
void task_bos_dsd_ita_0(DsdItaWork* work, void* arg);
void task_bos_dsd_rock_2(DsdRockWork* work);
void task_bos_dsd_ita_3(DsdItaWork* work);
void task_bos_jf_2(JfWork* work);
void task_bos_jf_3(JfWork* work);
u8 task_bos_dsd_map_1(void);
void task_bos_dsd_2(DsdWork* work);
void task_bos_dsd_3(DsdWork* work);
void func_080C211C(u8 index);
void func_080C213C(u8 index, u16 a);
void func_080C43E4(s32* p, s32 target);

void func_080C3868(DsdMainWork* work);
void func_080C3C34(DsdMainWork* work);
void task_bos_dsd_energy1_3(void);
void task_bos_jf_lamp_3(JfLampWork* work);
void task_bos_jf_majin_3(JfMajinWork* work);
s32 func_080BE910(void);
void task_bos_jf_rock_0(JfRockWork* work, JfWork* arg);
void task_bos_jf_rock_3(JfRockWork* work);
void func_080C29F4(DsdMainWork* work);
void func_080C2944(DsdMainWork* work);
void func_080C4398(DsdItaWork* work);
u8 func_080C0258(u16* p, s16 b, u8 c, u8 d);
s32 func_080BE940(JfMajinWork* work);
void func_080C2F68(DsdMainWork* work);
void func_080C3504(DsdMainWork* work);
void func_080C4C54(DsdEnergy1Work* work);
void func_080C386C(DsdMainWork* work);
u8 func_080C1370(s32 a, s32 b, s32 c);
s32 func_080BE278(JfLampWork* work);
void func_080C4CCC(DsdEnergy1Work* work);
void func_080C0624(JfMajinWork* work);
void func_080BFEF0(JfMajinWork* work);
void func_080C0714(JfMajinWork* work);
void func_080BE9A0(JfMajinWork* work);
void func_080BFDD4(JfMajinWork* work);
void func_080BFDD8(JfMajinWork* work);
void func_080BEAE8(JfMajinWork* work);
void func_080BEDF4(JfMajinWork* work);
void func_080BF160(JfMajinWork* work);
void func_080BF4F4(JfMajinWork* work);
void func_080BF8C4(JfMajinWork* work);
void func_080BFFF8(JfMajinWork* work);
void func_080C02AC(JfMajinWork* work);
u8 task_bos_jf_majin_1(JfMajinWork* work);
u8 task_bos_dsd_energy2_1(DsdEnergy2Work* work);
void func_080C3754(DsdMainWork* work);
void func_080C2BB0(DsdMainWork* work);
void func_080C2A2C(DsdMainWork* work);
void func_080C2CC0(DsdMainWork* work);
void func_080C2FD8(DsdMainWork* work);
void func_080C3574(DsdMainWork* work);
void func_080C3928(DsdMainWork* work);
void func_080C3188(DsdMainWork* work);
void func_080C427C(DsdItaWork* work);
void task_bos_jf_majin_2(JfMajinWork* work);
void task_bos_jf_rock_2(JfRockWork* work);
void task_bos_dsd_ita_2(DsdItaWork* work);
u8 task_bos_dsd_energy1_1(DsdEnergy1Work* work);
u8 task_bos_dsd_main_1(DsdMainWork* work);
void task_bos_dsd_main_2(DsdMainWork* work);
u8 task_bos_dsd_ita_1(DsdItaWork* work);
void task_bos_dsd_rock_0(DsdRockWork* work, DsdWork* arg);
void task_bos_jf_lamp_0(JfLampWork* work, JfWork* jf);
u8 task_bos_dsd_circle_1(DsdCircleWork* work);
void task_bos_dsd_0(DsdWork* work, void* arg);
void task_bos_jf_borderline_0(JfBorderlineWork* work, BosPos* arg);
void task_bos_jf_lamp_2(JfLampWork* work);
void task_bos_dsd_main_0(DsdMainWork* work, DsdWork* arg);
u8 task_bos_dsd_1(DsdWork* work);

void func_080C3C40(DsdMainWork* work);

extern s16 gUnk_0203AC80;
extern JfMapArg gUnk_0203AC90;
extern s16 gUnk_0203ACB0;
extern s16 gUnk_0203ACB4;

#endif /* GUARD_BOS2_H */
