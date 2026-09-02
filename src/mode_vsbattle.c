#include "mode_vsbattle.h"
#include "macros.h"

void mode_vsbattle_0(u32 mode) {
    VsTaskArg arg;
    VsTaskArg arg2;
    void** p;

    gUnk_02039B84 = EwramAlloc(sizeof(VsBattleWork));
    p = &gUnk_02039B9C;
    *p = EwramAlloc(sizeof(VsBattleWork));

    if (gUnk_02039828 == 0) {
        SeedRandom(gUnk_0203AAC0.unk_1E);
    } else {
        SeedRandom(gUnk_0203AA10.unk_1E);
    }

    func_0801071C();
    func_0801C068();
    func_0800C6B8();
    func_08004F08();
    gUnk_02039B84->unk_1C4 = 2;
    gUnk_02039B84->unk_1C6 = 3;
    SetupBg(3, 0, 12, 0);
    SetupBg(2, 2, 28, 10);
    SetBgPriority(3, 2);
    SetBgPriority(2, 0);
    SetBgOverflow(3, 1);
    SetBgOverflow(2, 0);
    TaskPoolInit(&gUnk_02039B84->unk_02C, 32);
    TaskPoolInit(&gUnk_02039B84->unk_040, 32);
    func_08012798(0x80, gUnk_02039B84->unk_1C4);
    func_0801227C();

    if (mode == 0) {
        arg.unk_04 = 1;
        arg.unk_00 = 0;
        TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDAE40, &arg);
        arg.unk_04 = 0;
        arg.unk_00 = 1;
        TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDAE40, &arg);
        gUnk_02039B84->unk_068 |= 0x1000;
    } else {
        arg2.unk_04 = 0;
        arg2.unk_00 = 0;
        TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDAE40, &arg2);
        arg2.unk_04 = 1;
        arg2.unk_00 = 1;
        TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDAE40, &arg2);
    }

    func_0801A920(0x100 - gUnk_02039B90, gUnk_02039B90 + 0x100, gUnk_02039B88, gUnk_02039B8C);
    TaskCreate(&gUnk_02039B84->unk_040, &gUnk_09EDAE70, 0);
    gUnk_02039B98 = 0;
    func_08006120(0, 60);
}

void mode_vsbattle_1(void) {
    if (gUnk_02039B84->unk_070 == 0) {
        func_08010CC8();

        if (gUnk_02039B84->unk_072 <= 0) {
            TaskPoolUpdate(&gUnk_02039B84->unk_02C);
        } else {
            gUnk_02039B84->unk_072--;
        }

        func_08012824();
        func_080125A4();
        TaskPoolDraw(&gUnk_02039B84->unk_040);

        if (gUnk_02039B84->unk_068 & 0x800000) {
            gUnk_02039B84->unk_068 &= ~0x800000;
        }
    }

    TaskPoolDraw(&gUnk_02039B84->unk_02C);
}

void mode_vsbattle_2(void) {
    func_08012810();
    TaskPoolDestroy(&gUnk_02039B84->unk_040);
    TaskPoolDestroy(&gUnk_02039B84->unk_02C);
    func_0801C104();
    EwramFree(gUnk_02039B9C);
    EwramFree(gUnk_02039B84);
}

void func_0800C6B0(void) {
}

void func_0800C6B4(void) {
}

void func_0800C6B8(void) {
    switch (gUnk_02039BB0.unk_00D) {
    case 1:
        m4aSongNumStart(1);
        break;
    case 3:
        m4aSongNumStart(23);
        break;
    case 4:
        m4aSongNumStart(17);
        break;
    case 5:
        m4aSongNumStart(9);
        break;
    case 6:
        m4aSongNumStart(20);
        break;
    case 7:
        m4aSongNumStart(16);
        break;
    case 8:
        m4aSongNumStart(11);
        break;
    case 10:
        m4aSongNumStart(26);
        break;
    case 11:
        m4aSongNumStart(12);
        break;
    case 9:
        m4aSongNumStart(40);
        break;
    case 12:
        m4aSongNumStart(39);
        break;
    case 13:
        m4aSongNumStart(43);
        break;
    default:
        m4aSongNumStart(3);
        break;
    }
}

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
