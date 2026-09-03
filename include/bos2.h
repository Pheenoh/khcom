#ifndef GUARD_BOS2_H
#define GUARD_BOS2_H

#include "types.h"
#include "game.h"

typedef struct BosPos {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} BosPos;

typedef struct BosSub {
    u32 unk_000;
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
    u8 unk_010[0x1C];
    s16 unk_02C;
    u8 unk_02E[0x6];
    u64 unk_034;
    u8 unk_03C[0x4];
    u32 unk_040;
    u8 unk_044[0xCC];
} BosSub;

typedef struct DsdWork {
    BosSub unk_000[3];
    u32 unk_330;
    u32 unk_334;
    u32 unk_338;
    u16 unk_33C;
    u8 unk_33E[0x6];
    u32 unk_344;
    u32 unk_348;
    u16 unk_34C;
    u8 unk_34E[0x6];
    s16 unk_354;
    s16 unk_356;
    s16 unk_358;
    s8 unk_35A;
    u8 unk_35B;
    s32 unk_35C;
    void* unk_360;
    void* unk_364;
    void* unk_368;
    void* unk_36C;
    void* unk_370;
    void* unk_374;
    void* unk_378;
    u32 unk_37C;
    u8 unk_380[0x10];
    u16 unk_390;
    u8 unk_392[0x2];
} DsdWork;

typedef struct DsdEnergy1Work {
    DsdWork* unk_00;
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
    u16 unk_34;
    u16 unk_36;
    u16 unk_38;
    u16 unk_3A;
    u16 unk_3C;
    u8 unk_3E[0x2];
    u32 unk_40;
    void* unk_44;
    s8 unk_48;
    u8 unk_49[0x3];
} DsdEnergy1Work;

typedef struct DsdEnergy2Work {
    DsdWork* unk_00;
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
    u16 unk_2C;
    u16 unk_2E;
    u16 unk_30;
    s16 unk_32;
    u8 unk_34;
    u8 unk_35;
    u8 unk_36[0x2];
    void* unk_38;
    s8 unk_3C;
    u8 unk_3D[0x3];
} DsdEnergy2Work;

typedef struct DsdRockWork {
    DsdWork* unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    void* unk_1C;
    u8 unk_20;
    u8 unk_21[0x3];
} DsdRockWork;

typedef struct DsdCircleWork {
    DsdWork* unk_00;
    void* unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    u16 unk_14;
    u16 unk_16;
    u16 unk_18;
    u8 unk_1A;
    u8 unk_1B;
    u16 unk_1C;
    u16 unk_1E;
} DsdCircleWork;

typedef struct DsdMainWork {
    DsdWork* unk_000;
    u16 unk_004;
    u16 unk_006;
    u8 unk_008;
    u8 unk_009[0x1];
    s16 unk_00A;
    void* unk_00C;
    void* unk_010;
    void* unk_014;
    void* unk_018;
    AnimState unk_01C;
    AnimState unk_034;
    void* unk_04C;
    void* unk_050;
    u8 unk_054;
    u8 unk_055[0x3];
    TaskPool unk_058;
    u32 unk_06C;
    s8 unk_070;
    u8 unk_071[0x3];
    u32 unk_074;
    s32 unk_078;
    s32 unk_07C;
    s32 unk_080;
    u8 unk_084[0x30];
    u8 unk_0B4[0xDC];
} DsdMainWork;

typedef struct DsdItaWork {
    u32 unk_000;
    u32 unk_004;
    u8 unk_008[0x58];
    u32 unk_060;
    u32 unk_064;
    u32 unk_068;
    u32 unk_06C;
    u32 unk_070;
    u16 unk_074;
    u16 unk_076;
    u16 unk_078;
    u8 unk_07A;
    u8 unk_07B[0x1];
    u16 unk_07C;
    u16 unk_07E;
    u32 unk_080;
    u8 unk_084[0x4];
    u32 unk_088;
    u32 unk_08C;
} DsdItaWork;

typedef struct TmTblWork {
    u32 unk_000;
    u32 unk_004;
    u8 unk_008[0x32];
    u8 unk_03A;
    u8 unk_03B[0x25];
    u16 unk_060;
    u8 unk_062;
    u8 unk_063[0x1];
    u16 unk_064;
    u8 unk_066;
    u8 unk_067;
    u32 unk_068;
} TmTblWork;

typedef struct TmClbSrc {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u16 unk_0C;
    u16 unk_0E;
} TmClbSrc;

typedef struct TmClbArg {
    u32 unk_00;
    u32 unk_04;
    TmClbSrc* unk_08;
    s32 unk_0C;
    void* unk_10;
    void* unk_14;
} TmClbArg;

typedef struct TmClbWork {
    TmClbArg* unk_000;
    void* unk_004;
    void* unk_008;
    u16 unk_00C;
    u8 unk_00E[0x2];
    s32 unk_010;
    s32 unk_014;
    s32 unk_018;
} TmClbWork;

typedef struct JfWork {
    u32 unk_000;
    u8 unk_004[0x8];
    s32 unk_00C;
    u8 unk_010[0x100];
    u32 unk_110;
    u32 unk_114;
    u32 unk_118;
    u32 unk_11C;
    u8 unk_120[0x14];
    u32 unk_134;
    u8 unk_138[0x100];
    u32 unk_238;
    u32 unk_23C;
    u16 unk_240;
    u8 unk_242[0x2];
    u16 unk_244;
    u8 unk_246[0x6];
    s16 unk_24C;
    u8 unk_24E[0x2];
    u16 unk_250;
    u8 unk_252[0x2];
    u32 unk_254;
    u8 unk_258[0x14];
} JfWork;

typedef struct JfMapArg {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
    void* unk_08;
    u16 unk_0C;
    u16 unk_0E;
    u8 unk_10[0x4];
} JfMapArg;

typedef struct JfMapWork {
    s16 unk_00;
    s16 unk_02;
} JfMapWork;

typedef struct JfMajinWork {
    JfWork* unk_00;
    u8 unk_04[0x66];
    s8 unk_6A;
    u8 unk_6B[0x1];
    TaskPool unk_6C;
    u32 unk_80;
} JfMajinWork;

typedef struct JfBorderlineWork {
    BosPos* unk_000;
    u32 unk_004;
    u32 unk_008;
    void* unk_00C;
    void* unk_010;
    void* unk_014;
    void* unk_018;
    AnimState unk_01C;
    AnimState unk_034;
    AnimState unk_04C;
    AnimState unk_064;
    void* unk_07C;
    AnimState unk_080;
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

typedef struct TmWork {
    u8 unk_00[0x28];
    u16 unk_28;
    u8 unk_2A[0x2];
    u32 unk_2C;
    u8 unk_30[0x34];
} TmWork;

typedef struct TmBodyWork {
    TmWork* unk_000;
    void* unk_004;
    void* unk_008;
    void* unk_00C;
    u8 unk_010[0x11C];
    u8 unk_12C[0x2C];
    s16 unk_158;
    s16 unk_15A;
    u8 unk_15C[0x338];
} TmBodyWork;

typedef struct TmArmState {
    u8 unk_00[0x2C];
    s32 unk_2C;
} TmArmState;

typedef struct TmArmSrc {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    TmArmState* unk_18;
} TmArmSrc;

typedef struct TmArmJoint {
    s32 unk_00;
    s32 unk_04;
    u8 unk_08;
    u8 unk_09[0x3];
    s32 unk_0C;
    s32 unk_10;
    u16 unk_14;
    u8 unk_16[0x10];
    u16 unk_26;
    u8 unk_28[0xC];
} TmArmJoint;

typedef struct TmArmPos {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u16 unk_0C;
    u16 unk_0E;
} TmArmPos;

typedef struct TmArmWork {
    u32 unk_000;
    u16* unk_004;
    u32 unk_008;
    TmArmSrc* unk_00C;
    TmArmJoint unk_010[8];
    u16 unk_1B0;
    u16 unk_1B2;
    u32 unk_1B4;
    u8 unk_1B8[0x10];
    u32 unk_1C8;
    u8 unk_1CC[0xC];
    u32 unk_1D8;
    u32 unk_1DC;
    u32 unk_1E0;
    u8 unk_1E4[0xC];
    u32 unk_1F0;
    u32 unk_1F4;
    TmArmPos unk_1F8[2];
    u32 unk_218;
    u8 unk_21C[0x14];
    u8 unk_230;
    u8 unk_231[0x3];
    u32 unk_234;
    u32 unk_238;
    AnimState unk_23C;
    u8 unk_254;
    u8 unk_255[0x3];
} TmArmWork;

typedef struct TmFootWork {
    u16 unk_000;
    u8 unk_002;
    u8 unk_003;
    u8 unk_004;
    u8 unk_005[0x3];
    u32 unk_008;
    u32 unk_00C;
    u32 unk_010;
    u32 unk_014;
    u32 unk_018;
    u32 unk_01C;
    u32 unk_020;
    u32 unk_024;
    u32 unk_028;
    u8 unk_02C[0x100];
    u32 unk_12C;
    u8 unk_130;
    u8 unk_131[0x3];
    u32 unk_134;
    u32 unk_138;
    u32 unk_13C;
    u32 unk_140;
    u8 unk_144[0x100];
    u32 unk_244;
    u8 unk_248;
    u8 unk_249[0x3];
    u32 unk_24C;
    u32 unk_250;
    u32 unk_254;
    u32 unk_258;
    u8 unk_25C[0x100];
    u32 unk_35C;
    u8 unk_360;
    u8 unk_361[0x3];
    u32 unk_364;
    u8 unk_368[0x8];
    u32 unk_370;
    u8 unk_374[0x104];
    u8 unk_478;
    u8 unk_479[0x7];
    u32 unk_480;
} TmFootWork;

extern s16 gSineTable[];
extern u8 gUnk_096874E4[];
extern u8 gUnk_096FB744[];
extern u8 gUnk_09EF2E68[];
extern s16 gUnk_0961A89E;
extern s16 gUnk_0961A8B0;
extern void* gUnk_09EF3C50;
extern void* gUnk_09EF3BF8;
extern void* gUnk_09EF3C18;
extern void* gUnk_09EF280C[];
extern void* gUnk_09EF28D0[];
extern void* gUnk_0203B500;
extern u8 gUnk_0203B510[];
extern u8 gUnk_08B22CBC[];
extern u8 gUnk_096C5C64[];
extern u8 gUnk_096FB304[];
extern u8 gUnk_0962E838[];
extern u8 gUnk_096FB484[];
extern u8 gUnk_09EF2EA8[];
extern s16 gUnk_0961A7D0[];
extern s8 gUnk_0961A82E[];
extern u32 gFrameCounter;
extern u8 gUnk_0203ACE0[];
extern void* gUnk_0203ACD8;
extern void* gUnk_09EF275C[][15];
extern s16 gUnk_0203ACC0;
extern s16 gUnk_0203ACC4;
extern s16 gUnk_0203ACD4;
extern u8 gUnk_0203AF2C[][14];
extern s8 gUnk_0203ACD0;
extern s16 gUnk_0203ACC8;
extern s16 gUnk_0203ACCC;
extern s16 gUnk_0203B4E0;
extern s32 gUnk_0203B4E8;
extern void* gUnk_09EF2D94[];
extern u8 gUnk_09EF26FC[];
extern u8 gUnk_09652E84[];
extern u8 gUnk_096FB2A4[];

void func_080122AC(void* a, s32 b, s32 c, s32 d);
void func_08012324(void* a, s32 x, s32 y, s32 z);
void func_08012614(void* a, s32 b);
void ApproachAngle(void* a, u16 b, u16 c);
void* TaskCreate(void* pool, void* desc, void* arg);
void* AnimUpdate(AnimState* a);
void AnimStart(AnimState* a, u16 animId, u16 flags);
void func_080C1A48(JfBorderlineWork* work);
void func_080062F4(u16 a, s32 b);
void func_08006238(s32 a, s32 b, s32 c);
void func_08018B04(s32 x, s32 y, s32 z, s32 s);
void m4aSongNumStart(u16 a);
void func_08014588(s32 x, s32 y, s32 z, s32 w, s32 a, s32 b);
void func_080C6EB0(void* a, void* b, s32 c, s32 d);
void LoadObjPaletteBank(u16 bank, void* src);
u8* func_08002C28(u8 a, s32 b);
u16 GetRandom(void);
s32 __divsi3(s32 a, s32 b);
void LoadPalette(void* src, void* dst, s32 size);
void TaskPoolUpdate(void* pool);
void func_080BB924(TmArmWork* work);
void func_080BC304(TmArmWork* work);
s32 func_0802F268(void);
u8 RequestDma3Copy(void* src, void* dst, u16 size);
u8 func_0800443C(void* a, u16 b);
void func_080BE3DC(u8 a, JfMajinWork* work);
void func_080BE478(u8 a, JfMajinWork* work);
void func_080BE380(u8 a, u16 b, JfMajinWork* work);

u8 task_bos_jf_borderline_1(JfBorderlineWork* work);
void task_bos_jf_borderline_3(JfBorderlineWork* work);
u8 task_bos_tm_clb_1(TmClbWork* work);
u8 task_bos_tm_arm_1(TmArmWork* work);
void task_bos_tm_arm_3(TmArmWork* work);
void task_bos_tm_foot_3(TmFootWork* work);
void task_bos_tm_clb_0(TmClbWork* work, void* arg);
void task_bos_tm_clb_2(TmClbWork* work);

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
void task_bos_tm_tbl_0(TmTblWork* work, void* arg);
void task_bos_tm_tbl_3(TmTblWork* work);
void task_bos_tm_clb_3(TmClbWork* work);
void func_080BA0E4(s32* p, s32 a, s32 b, s32 c);
void func_080BA0F8(u8* work);
void func_080B83B8(void* a);
void func_08083900(u8 a);
void func_080B9FC4(TmBodyWork* work);
void task_bos_tm_body_3(TmBodyWork* work);
void func_080BB1B8(void* pool, TmClbArg* p, TmClbSrc* a);
void func_080BB1D8(TmClbArg* p, TmClbSrc* a, s32 b);
void func_080BB1E8(TmClbArg* p, TmClbSrc* a);
void func_080BB1F4(TmClbArg* p, TmClbSrc* a, u8 mode);
void func_080BB428(u8* dst, u8* src);
void func_080BB43C(u8* work, u8* src, u16 a, u8* dst);
void func_080BB464(TmArmWork* work);
void func_080BB4C0(TmArmWork* work);
void func_080C211C(u8 index);
void func_080C213C(u8 index, u16 a);
void func_080C43E4(s32* p, s32 target);

#endif /* GUARD_BOS2_H */
