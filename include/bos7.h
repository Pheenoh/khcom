#ifndef GUARD_BOS7_H
#define GUARD_BOS7_H

#include "types.h"
#include "game.h"

typedef struct LstState {
    u16 unk_00;
    s16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A[0x04];
    u16 unk_12;
    u8 unk_14[0xB8];
    s16 unk_CC;
} LstState;

typedef struct LstWork {
    void* unk_00;
    LstState* unk_04;
} LstWork;

typedef struct LstEdgWork {
    u16 unk_000;
    u16 unk_002;
    u16 unk_004;
    u16 unk_006;
    u32 unk_008;
    u32 unk_00C;
    u32 unk_010;
    u32 unk_014;
    u32 unk_018;
    u32 unk_01C;
    u32 unk_020;
    u32 unk_024;
    u32 unk_028;
    u32 unk_02C;
    u8 unk_030[0x14];
    u32 unk_044;
    u32 unk_048;
} LstEdgWork;

typedef struct LstCtrWork {
    u32 unk_000;
    u16 unk_004;
    u16 unk_006;
    u16 unk_008;
    u16 unk_00A;
    u16 unk_00C;
    u16 unk_00E;
    u8 unk_010;
    u8 unk_011[0x1];
    u16 unk_012;
    u32 unk_014;
    u32 unk_018;
    u32 unk_01C;
    u32 unk_020;
    u32 unk_024;
    u32 unk_028;
    u32 unk_02C;
    u32 unk_030;
    u32 unk_034;
    u32 unk_038;
    u32 unk_03C;
    u32 unk_040;
    u32 unk_044;
    u8 unk_048[0x14];
    u32 unk_05C;
    u32 unk_060;
    u8 unk_064[0x124];
} LstCtrWork;

void ReleaseObjTiles(void* a);
void ReleaseObjPalette(void* a);
void AnimStart(void* a, s32 b, s32 c);

void task_bos_lst_fld_2(void);
void task_bos_lst_edg_3(LstEdgWork* work);
void task_bos_lst_ctr_3(LstCtrWork* work);
s32 func_0811089C(s32 x);
s32 func_081108A4(s32 x);
s32 func_08112410(s32 x);
s32 func_08112418(s32 x);
u8 func_08110938(LstWork* work);
u8 func_08110918(LstWork* work);
void func_08110984(LstWork* work);
void func_08110994(LstWork* work, u16 a);
void func_081109A8(LstWork* work);
void func_08111660(LstWork* work);

#endif /* GUARD_BOS7_H */
