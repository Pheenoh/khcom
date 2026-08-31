#include "macros.h"
#include "bos6.h"

INCLUDE_ASM("bos6/task_bos_pc_0.s");
INCLUDE_ASM("bos6/func_0810A850.s");
INCLUDE_ASM("bos6/func_0810A914.s");
INCLUDE_ASM("bos6/task_bos_pc_1.s");

void task_bos_pc_2(void* work) {
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
INCLUDE_ASM("bos6/func_0810B4F4.s");

void func_0810B51C(u8* p) {
    *p = 0;
}

INCLUDE_ASM("bos6/task_bos_pc_fld_0.s");
INCLUDE_ASM("bos6/task_bos_pc_fld_1.s");
INCLUDE_ASM("bos6/task_bos_pc_fld_2.s");
INCLUDE_ASM("bos6/task_bos_pc_fld_3.s");
INCLUDE_ASM("bos6/func_0810B7E8.s");
INCLUDE_ASM("bos6/func_0810BCD4.s");
INCLUDE_ASM("bos6/task_bos_pc_flt_0.s");
INCLUDE_ASM("bos6/task_bos_pc_flt_1.s");
INCLUDE_ASM("bos6/task_bos_pc_flt_2.s");
INCLUDE_ASM("bos6/task_bos_pc_flt_3.s");

void func_0810BF24(u8** p, u8 v) {
    p[1][24] = v;
}

INCLUDE_ASM("bos6/task_bos_pc_acd_0.s");
INCLUDE_ASM("bos6/task_bos_pc_acd_1.s");
INCLUDE_ASM("bos6/task_bos_pc_acd_2.s");
INCLUDE_ASM("bos6/task_bos_pc_acd_3.s");

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
