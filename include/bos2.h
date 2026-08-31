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
