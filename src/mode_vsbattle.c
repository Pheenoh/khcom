#include "mode_vsbattle.h"
#include "macros.h"

void mode_vsbattle_0(u32 mode) {
    VsTaskArg arg;
    VsTaskArg arg2;
    VsBattleWork** p;

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


u8 _0800CBDC(EmyWork* work) {
    VsActor* actor = &work->unk_03C;

    actor->unk_FC = actor->unk_04;
    actor->unk_100 = actor->unk_08;

    if (work->unk_14C == 3) {
        return 0;
    }

    if (work->unk_14C == 10) {
        return 0;
    }

    switch (func_0801ADAC(actor)) {
    case 6:
        func_0800CB78(work);
        work->unk_14C = 9;
        work->unk_154 = 0;
        break;
    case 7:
        work->unk_14C = 15;
        work->unk_154 = 0;
        break;
    case 8:
        func_0801C2DC(actor, 1);
        work->unk_14C = 15;
        work->unk_154 = 0;
        break;
    case 1:
        func_0800CB78(work);
        work->unk_14C = 1;
        work->unk_154 = 0;
        break;
    case 11:
        func_0801C2DC(actor, 1);
        work->unk_14C = 10;
        work->unk_154 = 0;
        break;
    case 3:
        func_0801C2DC(actor, 1);
        func_0800CB78(work);
        work->unk_14C = 3;
        work->unk_154 = 0;
        break;
    case 12:
        work->unk_14C = 13;
        work->unk_154 = 0;
        break;
    case 2:
        if (work->unk_14C != 12) {
            work->unk_14C = 6;
            work->unk_154 = 0;
        }
        break;
    case 5:
        work->unk_154 = 0;
        return 1;
    case 4:
        work->unk_14C = 5;
        work->unk_154 = 0;
        work->unk_15A = 1;
        break;
    case 10:
        if (work->unk_14C != 12) {
            work->unk_14C = 12;
            work->unk_154 = 0;
            actor->unk_108 = actor->unk_10C = 0;
        }
        break;
    }

    return 0;
}

void func_0800CD40(EmyWork* work) {
    VsActor* actor = &work->unk_03C;

    if (gUnk_02039BB0.unk_008 & 4) {
        actor->unk_34 |= 0x4002;

        if (gUnk_02039BB0.unk_1B8 == 3) {
            actor->unk_20 = (actor->unk_2E * 204) >> 8;
        } else {
            actor->unk_20 = (actor->unk_2E * 25) >> 8;
        }

        actor->unk_24 = 0x200;
        gUnk_02039B84->unk_076 = 0;
        actor->unk_A8 = 0;
        actor->unk_AC = 0;
    }

    work->unk_14C = work->unk_150;
    work->unk_154 = 0;
    actor->unk_34 &= ~0x300;
}
INCLUDE_ASM("mode_vsbattle/_0800CDF0.s");
INCLUDE_ASM("mode_vsbattle/func_0800DF30.s");

void func_0800E0D0(EmyWork* work) {
    gUnk_02039B84->unk_0EC -= gUnk_09EDA4EC[work->unk_03C.unk_00];

    if (gUnk_02039B84->unk_078 == &work->unk_03C) {
        gUnk_02039B84->unk_078 = 0;
    }

    func_0801B7D8(&work->unk_03C);

    if (gUnk_02039B84->unk_0EE == 0) {
        if (gUnk_02039B84->unk_120 <= 0) {
            if (gUnk_02039B84->unk_07C->unk_2C > 0) {
                gUnk_02039B84->unk_068 |= 0x200000000;
            }
        }
    }

    ReleaseObjTiles(work->unk_000);
    ReleaseObjPalette(work->unk_004);
    ReleaseObjPalette(work->unk_008);
    TaskPoolDestroy(&work->unk_028);
}

void func_0800E168(HumWork* work, HumDef* def) {
    VsActor* actor = &work->unk_040;

    s32 a = 0x14000;
    s32 b = 0x18100;
    s32 z = 0;

    func_0801B37C(actor, &def->unk_0C, a, b, z);
    actor->unk_CE = 0;
    actor->unk_D0 = 0;
    actor->unk_D2 = 0;
    actor->unk_B2 = 1;
    actor->unk_34 |= 0x40000000000000;

    if (gUnk_02039B84->unk_07C->unk_04 < actor->unk_04) {
        actor->unk_34 |= 4;
    }

    work->unk_000 = def;
    work->unk_004 = AllocObjTiles(def->unk_00 * 32, 0);
    work->unk_008 = LoadObjPalette(def->unk_04, 32);
    work->unk_178 = def->unk_04;
    work->unk_150 = 0;
    work->unk_152 = 0;
    work->unk_154 = 0;
    work->unk_158 = 0;
    actor->unk_108 = 0;
    actor->unk_10C = 0;
    work->unk_15C = 0;
    work->unk_160 = 0;
    work->unk_164 = 0;
    work->unk_174 = 0xFFF0;
    work->unk_17C = 1;
    AnimInit(&work->unk_014, 0, 0);
    TaskPoolInit(&work->unk_02C, 3);
    TaskCreate(&work->unk_02C, &gUnk_09EDAE88, actor);
    TaskCreate(&work->unk_02C, &gUnk_09EDB3F8, actor);
    work->unk_170 = 12;
    work->unk_168 = 0x100;
    work->unk_16C = 0x100;
    work->unk_00C = 0;
    work->unk_010 = 0;
    work->unk_184 = 0;
    gUnk_02039B9C->unk_07C = actor;
    gUnk_02039B84->unk_0A8 = actor;
    actor->unk_E4 = gUnk_02039B9C;
    actor->unk_34 |= 0x24000000000;
}

void func_0800E314(HumWork* work, HumSub* sub, HumSubDef* def) {
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

s32 _0800E434(HumWork* work) {
    VsActor* actor = &work->unk_040;
    s32 r;

    actor->unk_FC = actor->unk_04;
    actor->unk_100 = actor->unk_08;
    r = func_0801ADAC(actor);

    switch (r) {
    case 5:
        work->unk_154 |= 4;
        gUnk_02039B9C->unk_068 &= ~0x40000000;
        work->unk_17E = 0;
        work->unk_150 = 0;
        func_08005B64(&work->unk_014);
        break;
    case 11:
        func_08006120(2, 20);
        gUnk_02039B84->unk_072 = 15;

        if (actor->unk_E8 != 1) {
            actor->unk_E8 = 1;
            actor->unk_EC = 0x168;
        }

        work->unk_170 = 11;
        work->unk_150 = 0;
        break;
    case 6:
        func_0800E3D0(work);
        work->unk_170 = 11;
        work->unk_150 = 0;
        break;
    case 7:
    case 8:
        work->unk_170 = 14;
        work->unk_150 = 0;
        break;
    case 1:
        func_0800E3D0(work);
        work->unk_170 = 1;
        work->unk_150 = 0;
        break;
    case 3:
        work->unk_154 |= 4;
        work->unk_170 = 3;
        work->unk_150 = 0;
        break;
    case 2:
        work->unk_170 = 10;
        work->unk_150 = 0;
        break;
    case 4:
        work->unk_170 = 9;
        work->unk_150 = 0;
        break;
    case 10:
        if (work->unk_170 != 13) {
            work->unk_170 = 13;
            work->unk_150 = 0;
            actor->unk_108 = actor->unk_10C = 0;
        }
        break;
    }

    return r;
}

void func_0800E5CC(HumSub* sub) {
    if (sub != 0) {
        if (!(sub->unk_34 & 2)) {
            sub->unk_38 = AnimUpdate(&sub->unk_10);
        }
    }
}

INCLUDE_ASM("mode_vsbattle/func_0800E5F0.s");
