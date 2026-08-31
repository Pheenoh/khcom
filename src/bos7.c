#include "macros.h"
#include "bos7.h"

INCLUDE_ASM("bos7/task_bos_lst_fld_0.s");
INCLUDE_ASM("bos7/func_08110058.s");
INCLUDE_ASM("bos7/task_bos_lst_fld_1.s");

void task_bos_lst_fld_2(void) {
}

INCLUDE_ASM("bos7/task_bos_lst_fld_3.s");
INCLUDE_ASM("bos7/task_bos_lst_edg_0.s");
INCLUDE_ASM("bos7/task_bos_lst_edg_1.s");
INCLUDE_ASM("bos7/task_bos_lst_edg_2.s");

void task_bos_lst_edg_3(LstEdgWork* work) {
    ReleaseObjTiles((void*)work->unk_044);
    ReleaseObjPalette((void*)work->unk_048);
}

s32 func_0811089C(s32 x) {
    return x * x;
}

s32 func_081108A4(s32 x) {
    return x * x;
}

INCLUDE_ASM("bos7/func_081108AC.s");

u8 func_08110918(LstWork* work) {
    LstState* s;
    u8 result;

    s = work->unk_04;
    result = 1;

    if (s->unk_CC <= 0 || s->unk_02 == 6) {
        result = 0;
    }

    return result;
}

u8 func_08110938(LstWork* work) {
    LstState* s;
    u8 result;

    s = work->unk_04;
    result = func_08110918(work);

    if (result == 1 && (s16)s->unk_12 <= 0) {
        result = 0;
    }

    return result;
}

INCLUDE_ASM("bos7/func_0811095C.s");

void func_08110984(LstWork* work) {
    LstState* s;
    u16 zero;

    s = work->unk_04;
    zero = 0;
    s->unk_02 = 1;
    s->unk_04 = zero;
    s->unk_06 = zero;
    s->unk_08 = zero;
}

void func_08110994(LstWork* work, u16 a) {
    LstState* s;
    u16 zero;

    s = work->unk_04;
    zero = 0;
    s->unk_02 = 2;
    s->unk_04 = zero;
    s->unk_06 = zero;
    s->unk_08 = zero;
    s->unk_12 = a;
}

void func_081109A8(LstWork* work) {
    LstState* s;
    u16 zero;

    s = work->unk_04;
    zero = 0;
    s->unk_02 = 5;
    s->unk_04 = zero;
    s->unk_06 = zero;
    s->unk_08 = zero;
}

INCLUDE_ASM("bos7/func_081109B8.s");
INCLUDE_ASM("bos7/func_08110A38.s");
INCLUDE_ASM("bos7/func_08110A98.s");
INCLUDE_ASM("bos7/func_08110B10.s");
INCLUDE_ASM("bos7/task_bos_lst_bit_0.s");
INCLUDE_ASM("bos7/task_bos_lst_bit_1.s");
INCLUDE_ASM("bos7/task_bos_lst_bit_2.s");
INCLUDE_ASM("bos7/task_bos_lst_bit_3.s");

void func_08111660(LstWork* work) {
    LstState* s;

    s = work->unk_04;
    s->unk_00 = 0;
    *(u16*)((u8*)s + 16) = 0;
    AnimStart((u8*)s + 68, 4, 0);
}

INCLUDE_ASM("bos7/func_08111678.s");
INCLUDE_ASM("bos7/task_bos_lst_lsr_0.s");
INCLUDE_ASM("bos7/task_bos_lst_lsr_1.s");
INCLUDE_ASM("bos7/task_bos_lst_lsr_2.s");
INCLUDE_ASM("bos7/task_bos_lst_lsr_3.s");
INCLUDE_ASM("bos7/task_bos_lst_ptl_0.s");
INCLUDE_ASM("bos7/task_bos_lst_ptl_1.s");
INCLUDE_ASM("bos7/task_bos_lst_ptl_2.s");
INCLUDE_ASM("bos7/task_bos_lst_ptl_3.s");
INCLUDE_ASM("bos7/task_bos_lst_fal_0.s");
INCLUDE_ASM("bos7/task_bos_lst_fal_1.s");
INCLUDE_ASM("bos7/task_bos_lst_fal_2.s");
INCLUDE_ASM("bos7/task_bos_lst_fal_3.s");
INCLUDE_ASM("bos7/task_bos_lst_ctr_0.s");
INCLUDE_ASM("bos7/task_bos_lst_ctr_1.s");
INCLUDE_ASM("bos7/task_bos_lst_ctr_2.s");

void task_bos_lst_ctr_3(LstCtrWork* work) {
    ReleaseObjTiles((void*)work->unk_05C);
    ReleaseObjPalette((void*)work->unk_060);
}

s32 func_08112410(s32 x) {
    return x * x;
}

s32 func_08112418(s32 x) {
    return x * x;
}

INCLUDE_ASM("bos7/task_bos_lst_snp_0.s");
INCLUDE_ASM("bos7/task_bos_lst_snp_1.s");
INCLUDE_ASM("bos7/task_bos_lst_snp_2.s");
INCLUDE_ASM("bos7/task_bos_lst_snp_3.s");
