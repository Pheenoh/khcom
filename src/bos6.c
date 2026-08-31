#include "macros.h"
#include "bos6.h"

INCLUDE_ASM("bos6/task_bos_pc_0.s");
INCLUDE_ASM("bos6/func_0810A850.s");
INCLUDE_ASM("bos6/func_0810A914.s");
INCLUDE_ASM("bos6/task_bos_pc_1.s");

void task_bos_pc_2(PcWork* work) {
    func_0810A018(work);
    func_0810A498(work);
}

INCLUDE_ASM("bos6/task_bos_pc_3.s");
INCLUDE_ASM("bos6/func_0810B350.s");
INCLUDE_ASM("bos6/func_0810B3E4.s");
INCLUDE_ASM("bos6/func_0810B434.s");

void* func_0810B49C(void) {
    return gUnk_02036010;
}

void func_0810B4A8(u8* p) {
    u16 zero;

    zero = 0;
    *(u8*)(p + 0) = zero;
    *(u16*)(p + 2) = zero;
    *(u16*)(p + 4) = zero;
}

INCLUDE_ASM("bos6/func_0810B4B4.s");

void func_0810B4F4(u8* p) {
    if (p[0] != 0) {
        LoadPalette(gUnk_09D69374 + *(s16*)(p + 2) * 32, gUnk_05000080, 32);
    }
}

void func_0810B51C(u8* p) {
    *p = 0;
}

INCLUDE_ASM("bos6/task_bos_pc_fld_0.s");
INCLUDE_ASM("bos6/task_bos_pc_fld_1.s");
INCLUDE_ASM("bos6/task_bos_pc_fld_2.s");

void task_bos_pc_fld_3(PcFldWork* work) {
    func_0810B51C((u8*)work);
    func_08012304(&work->unk_010);

    if (work->unk_008 != 0) {
        ReleaseObjTiles((void*)work->unk_008);
    }

    if (work->unk_00C != 0) {
        ReleaseObjPalette((void*)work->unk_00C);
    }
}

s32 func_0810B7D8(s32 x) {
    return x * x;
}

s32 func_0810B7E0(s32 x) {
    return x * x;
}

INCLUDE_ASM("bos6/func_0810B7E8.s");
INCLUDE_ASM("bos6/func_0810BCD4.s");
INCLUDE_ASM("bos6/task_bos_pc_flt_0.s");
INCLUDE_ASM("bos6/task_bos_pc_flt_1.s");
INCLUDE_ASM("bos6/task_bos_pc_flt_2.s");

void task_bos_pc_flt_3(PcFltWork* work) {
    func_08012304(&work->unk_040);
    ReleaseObjTiles((void*)work->unk_034);
    ReleaseObjPalette((void*)work->unk_038);
}

s32 func_0810BF14(s32 x) {
    return x * x;
}

s32 func_0810BF1C(s32 x) {
    return x * x;
}

void func_0810BF24(u8** p, u8 v) {
    p[1][24] = v;
}

INCLUDE_ASM("bos6/task_bos_pc_acd_0.s");
INCLUDE_ASM("bos6/task_bos_pc_acd_1.s");
INCLUDE_ASM("bos6/task_bos_pc_acd_2.s");

void task_bos_pc_acd_3(PcAcdWork* work) {
    ReleaseObjTiles((void*)work->unk_004);
    ReleaseObjPalette((void*)work->unk_008);
}

s32 func_0810C2B4(s32 x) {
    return x * x;
}

s32 func_0810C2BC(s32 x) {
    return x * x;
}

void func_0810C2C4(u8** p) {
    p[1][1] = 1;
}

void func_0810C2CC(u8* p, u16 a, u16 b) {
    u16 zero;

    zero = 0;
    *(u16*)(p + 12) = a;
    *(u16*)(p + 14) = b;
    *(u16*)(p + 0x70) = zero;
    *(u16*)(p + 0x72) = zero;
}

void func_0810C2E0(u8* work) {
    func_0801BCD4(work + 0xE4);
    *(u16*)(work + 0x70) += 1;
}

INCLUDE_ASM("bos6/func_0810C2F8.s");
INCLUDE_ASM("bos6/func_0810C32C.s");
INCLUDE_ASM("bos6/func_0810C494.s");
INCLUDE_ASM("bos6/func_0810C57C.s");
INCLUDE_ASM("bos6/func_0810C630.s");
INCLUDE_ASM("bos6/func_0810C65C.s");
INCLUDE_ASM("bos6/func_0810C754.s");
INCLUDE_ASM("bos6/func_0810C7C4.s");
INCLUDE_ASM("bos6/func_0810CC14.s");
INCLUDE_ASM("bos6/func_0810D304.s");
INCLUDE_ASM("bos6/func_0810D364.s");
INCLUDE_ASM("bos6/func_0810D3A8.s");
INCLUDE_ASM("bos6/func_0810D3E0.s");
INCLUDE_ASM("bos6/func_0810D478.s");
INCLUDE_ASM("bos6/func_0810D4B0.s");
