#include "mode_vsbattle.h"
#include "macros.h"

INCLUDE_ASM("mode_vsbattle/mode_vsbattle_0.s");
INCLUDE_ASM("mode_vsbattle/mode_vsbattle_1.s");
INCLUDE_ASM("mode_vsbattle/mode_vsbattle_2.s");
INCLUDE_ASM("mode_vsbattle/func_0800C778.s");
INCLUDE_ASM("mode_vsbattle/func_0800C980.s");

void func_0800CB4C(EmyWork* work) {
    func_0801AF08(&work->unk_03C);
    work->unk_14C = work->unk_150;
    work->unk_154 = 0;
}

void func_0800CB78(EmyWork* work) {
    work->unk_168 = -work->unk_03C.unk_AC * 3;
    work->unk_03C.unk_108 = ((gUnk_08121400[work->unk_03C.unk_B0] << 1) * work->unk_03C.unk_A8) >> 8;
    work->unk_03C.unk_10C = ((-gUnk_08121400[work->unk_03C.unk_B0 + 0x40] << 1) * work->unk_03C.unk_A8) >> 8;
}

INCLUDE_ASM("mode_vsbattle/_0800CBDC.s");
INCLUDE_ASM("mode_vsbattle/func_0800CD40.s");
INCLUDE_ASM("mode_vsbattle/_0800CDF0.s");
INCLUDE_ASM("mode_vsbattle/func_0800DF30.s");
INCLUDE_ASM("mode_vsbattle/func_0800E0D0.s");
INCLUDE_ASM("mode_vsbattle/func_0800E168.s");

void func_0800E314(HumWork* work, HumSub* sub, HumDef* def) {
    if (work->unk_00C == 0) {
        work->unk_00C = sub;
    } else {
        work->unk_010 = sub;
    }

    sub->unk_04 = AllocObjTiles(def->unk_04 * 32, 0);
    sub->unk_0C = sub->unk_08 = LoadObjPalette(def->unk_00, 32);
    sub->unk_28 = work->unk_040.unk_04;
    sub->unk_2C = work->unk_040.unk_08;
    sub->unk_30 = work->unk_040.unk_0C;
    sub->unk_34 = 0;
    AnimInit(&sub->unk_10, 0, 0);
}

void func_0800E364(HumSub* sub) {
    if (sub != 0) {
        ReleaseObjTiles(sub->unk_04);
        ReleaseObjPalette(sub->unk_08);
    }
}

void func_0800E380(HumWork* work) {
    if (gUnk_02039B84->unk_078 == &work->unk_040) {
        gUnk_02039B84->unk_078 = 0;
    }

    func_0800E364(work->unk_00C);
    func_0800E364(work->unk_010);
    gUnk_02039B84->unk_0A8 = 0;
    func_0801B7D8(&work->unk_040);
    ReleaseObjTiles(work->unk_004);
    ReleaseObjPalette(work->unk_008);
    TaskPoolDestroy(&work->unk_02C);
}

void func_0800E3D0(HumWork* work) {
    work->unk_158 = -work->unk_040.unk_AC * 3;
    work->unk_040.unk_108 = ((gUnk_08121400[work->unk_040.unk_B0] << 1) * work->unk_040.unk_A8) >> 8;
    work->unk_040.unk_10C = ((-gUnk_08121400[work->unk_040.unk_B0 + 0x40] << 1) * work->unk_040.unk_A8) >> 8;
}

INCLUDE_ASM("mode_vsbattle/_0800E434.s");

void func_0800E5CC(HumSub* sub) {
    if (sub != 0) {
        if (!(sub->unk_34 & 2)) {
            sub->unk_38 = AnimUpdate(&sub->unk_10);
        }
    }
}

INCLUDE_ASM("mode_vsbattle/func_0800E5F0.s");
