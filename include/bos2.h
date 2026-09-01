#ifndef GUARD_BOS2_H
#define GUARD_BOS2_H

#include "types.h"
#include "game.h"

typedef struct DsdWork {
    u32 unk_000;
    u8 unk_004[0x10C];
    u32 unk_110;
    u8 unk_114[0x30];
    u32 unk_144;
    u32 unk_148;
    u8 unk_14C[0xD4];
    u32 unk_220;
    u8 unk_224[0x3C];
    u32 unk_260;
    u8 unk_264[0xCC];
    u32 unk_330;
    u32 unk_334;
    u32 unk_338;
    u16 unk_33C;
    u8 unk_33E[0x6];
    u32 unk_344;
    u32 unk_348;
    u16 unk_34C;
    u8 unk_34E[0xA];
    u16 unk_358;
    u8 unk_35A[0x2];
    u32 unk_35C;
    u8 unk_360[0x1C];
    u32 unk_37C;
    u8 unk_380[0x10];
    u16 unk_390;
    u8 unk_392[0x2];
} DsdWork;

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
    u8 unk_03B[0x27];
    u8 unk_062;
    u8 unk_063[0x1];
    u16 unk_064;
    u8 unk_066;
    u8 unk_067;
    u32 unk_068;
} TmTblWork;

typedef struct TmClbWork {
    u32 unk_000;
    u32 unk_004;
    u32 unk_008;
    u16 unk_00C;
    u8 unk_00E[0x2];
    u32 unk_010;
    u32 unk_014;
    u32 unk_018;
} TmClbWork;

typedef struct JfWork {
    u32 unk_000;
    u8 unk_004[0x10C];
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
    u16 unk_24C;
    u8 unk_24E[0x2];
    u16 unk_250;
    u8 unk_252[0x2];
    u32 unk_254;
    u8 unk_258[0x14];
} JfWork;

typedef struct JfBorderlineWork {
    u32 unk_000;
    u32 unk_004;
    u32 unk_008;
    u32 unk_00C;
    u32 unk_010;
    u32 unk_014;
    u32 unk_018;
    u32 unk_01C;
    u8 unk_020[0x14];
    u32 unk_034;
    u8 unk_038[0x14];
    u32 unk_04C;
    u8 unk_050[0x14];
    u32 unk_064;
    u8 unk_068[0x14];
    u32 unk_07C;
    u32 unk_080;
    u8 unk_084[0x14];
    u32 unk_098;
    u32 unk_09C;
    u32 unk_0A0;
    u32 unk_0A4;
    u32 unk_0A8;
    u32 unk_0AC;
    u16 unk_0B0;
    u16 unk_0B2;
    u8 unk_0B4;
    u8 unk_0B5;
    u8 unk_0B6[0x2];
} JfBorderlineWork;

typedef struct TmArmWork {
    u32 unk_000;
    u32 unk_004;
    u32 unk_008;
    u32 unk_00C;
    u32 unk_010;
    u8 unk_014[0x4];
    u16 unk_018;
    u8 unk_01A[0xA];
    u16 unk_024;
    u8 unk_026[0x26];
    u32 unk_04C;
    u8 unk_050[0x90];
    u32 unk_0E0;
    u8 unk_0E4[0x4];
    u16 unk_0E8;
    u8 unk_0EA[0xA];
    u16 unk_0F4;
    u8 unk_0F6[0x26];
    u32 unk_11C;
    u8 unk_120[0x5C];
    u32 unk_17C;
    u32 unk_180;
    u8 unk_184;
    u8 unk_185[0x27];
    u32 unk_1AC;
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
    u8 unk_1F8[0xC];
    u16 unk_204;
    u8 unk_206[0xE];
    u16 unk_214;
    u8 unk_216[0x2];
    u32 unk_218;
    u8 unk_21C[0x14];
    u8 unk_230;
    u8 unk_231[0x3];
    u32 unk_234;
    u32 unk_238;
    u32 unk_23C;
    u8 unk_240[0x14];
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

extern u8 gUnk_09652E84[];
extern u8 gUnk_096FB2A4[];

void task_bos_jf_borderline_3(JfBorderlineWork* work);
void task_bos_tm_arm_3(TmArmWork* work);
void task_bos_tm_foot_3(TmFootWork* work);
void task_bos_tm_clb_0(TmClbWork* work, void* arg);

void task_bos_dsd_rock_3(void);
void task_bos_dsd_circle_3(void);
void task_bos_dsd_energy2_3(void);
void task_bos_dsd_ita_3(DsdItaWork* work);
void task_bos_jf_2(JfWork* work);
void task_bos_dsd_2(DsdWork* work);
void task_bos_dsd_3(DsdWork* work);
void task_bos_tm_tbl_3(TmTblWork* work);
void task_bos_tm_clb_3(TmClbWork* work);
void func_080BA0E4(s32* p, s32 a, s32 b, s32 c);
void func_080BA0F8(u8* work);
void func_080BB428(u8* dst, u8* src);
void func_080BB43C(u8* work, u8* src, u16 a, u8* dst);
void func_080C211C(u8 index);
void func_080C43E4(s32* p, s32 target);

#endif /* GUARD_BOS2_H */
