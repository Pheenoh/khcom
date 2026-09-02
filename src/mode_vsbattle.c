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

void func_0800C778(EmyWork* work, EmyDef* def, EmyObj* obj) {
    VsActor* actor = &work->unk_03C;
    u16 t;

    func_0801B37C(actor, &def->unk_1C, obj->unk_00, obj->unk_04, obj->unk_08);
    actor->unk_CE = def->unk_12;
    actor->unk_D0 = def->unk_14;
    actor->unk_D2 = def->unk_16;
    actor->unk_B2 = def->unk_18;

    if (gUnk_02039B84->unk_07C->unk_04 < actor->unk_04) {
        actor->unk_34 |= 4;
    }

    actor->unk_34 |= 0x300;
    t = gUnk_09EDA4EC[actor->unk_00];
    work->unk_15C = def;
    work->unk_000 = AllocObjTiles(t * 32, 0);
    work->unk_004 = LoadObjPalette(def->unk_00, 32);
    work->unk_008 = LoadObjPalette(gUnk_08F69BC4, 32);
    work->unk_150 = 0;
    work->unk_14C = 11;
    work->unk_154 = 0;
    work->unk_156 = 0;
    work->unk_158 = 0;
    work->unk_15A = 1;
    work->unk_160 = 0;
    work->unk_164 = def->unk_08;
    work->unk_168 = 0;
    actor->unk_108 = 0;
    actor->unk_10C = 0;
    work->unk_162 = 0;

    if (actor->unk_34 & 0x20000) {
        work->unk_16C = 281;
    } else {
        work->unk_16C = 0x100;
    }

    work->unk_170 = 0;
    work->unk_174 = 0;
    work->unk_178 = 0;
    AnimInit(&work->unk_010, 0, 0);
    func_08019068(work->unk_15C->unk_04, &work->unk_010, 0, 1, work->unk_000);
    work->unk_00C = AnimGetGfx(&work->unk_010);
    TaskPoolInit(&work->unk_028, 3);

    if (!(def->unk_1A & 1)) {
        TaskCreate(&work->unk_028, &gUnk_09EDAE88, actor);
    }

    TaskCreate(&work->unk_028, &gUnk_09EDB3F8, actor);

    if (def->unk_1A & 2) {
        work->unk_17C = 0x100;
        work->unk_180 = 0x100;
    } else {
        work->unk_17C = 0x80;
        work->unk_180 = 0x80;
    }

    gUnk_02039B84->unk_0EC += t;
    gUnk_02039B84->unk_120--;
}
s16 func_0800C980(EmyWork* work, s16 a, s16 b, s16 c, s32 d, s16 e, u16 f, s16 g, s16 h, u16 i) {
    VsActor* actor = &work->unk_03C;
    s32 ret;
    s32 v;
    s32 target;
    s16 steps;

    ret = 0;

    if (work->unk_154 == 0) {
        work->unk_158 &= ~4;
    }

    if (work->unk_154 >= a) {
        if (work->unk_154 < a + b) {
            steps = (a + b) - work->unk_154;
            target = actor->unk_18;

            if (work->unk_03C.unk_34 & 4) {
                v = actor->unk_14 - (e << 8);
            } else {
                v = actor->unk_14 + (e << 8);
            }

            if (actor->unk_E8 != 5) {
                func_0800592C(&actor->unk_04, v, steps);
                func_0800592C(&actor->unk_08, target, steps);
            }

            if (!(work->unk_158 & 4)) {
                if (actor->unk_34 & 4) {
                    if (func_08011F78(d, actor->unk_04 - (g << 8), actor->unk_08, actor->unk_0C + (h << 8), (s16)i, i / 2, (s16)i) != 0) {
                        m4aSongNumStart(f);
                        work->unk_158 |= 4;
                        ret = 1;
                    }
                } else {
                    if (func_08011F78(d, actor->unk_04 + (g << 8), actor->unk_08, actor->unk_0C + (h << 8), (s16)i, i / 2, (s16)i) != 0) {
                        m4aSongNumStart(f);
                        ret = 1;
                        work->unk_158 |= 4;
                    }
                }
            }
        } else if (work->unk_154 > a + b + c) {
            func_0800CB4C(work);
            return 2;
        }
    }

    work->unk_154++;
    return ret;
}

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

void func_0800DF30(EmyWork* work) {
    if (work->unk_15A != 0) {
        VsActor* actor;
        u16 g;
        s32 affine;
        s32 sx;
        s32 sy;
        s16 x;
        s16 y;

        actor = &work->unk_03C;
        g = func_0801AF1C(actor->unk_08) | work->unk_162;
        WorldToScreen(&x, &y, actor->unk_04, actor->unk_08, actor->unk_0C);

        if (work->unk_17C == 0x100 && work->unk_180 == 0x100) {
            if (actor->unk_34 & 4) {
                sy = gUnk_02039B84->unk_024;
                sx = sy;
            } else if (gUnk_02039B84->unk_024 == 0x100) {
                sy = gUnk_02039B84->unk_024;
                sx = sy;
                g |= 1;
            } else {
                sy = gUnk_02039B84->unk_024;
                sx = -sy;
            }
        } else {
            if (actor->unk_34 & 4) {
                sx = (gUnk_02039B84->unk_024 * work->unk_17C) >> 8;
                sy = gUnk_02039B84->unk_024;
                sy = (sy * work->unk_180) >> 8;
            } else {
                sx = -((gUnk_02039B84->unk_024 * work->unk_17C) >> 8);
                sy = gUnk_02039B84->unk_024;
                sy = (sy * work->unk_180) >> 8;
            }
        }

        if (sy == 0x100 && sx == sy) {
            affine = 0;
        } else if (sy < 256) {
            affine = AllocObjAffine(0, sx, sy, 0);
        } else {
            affine = AllocObjAffine(0, sx, sy, 1);
        }

        if (func_0801CA00(actor) != 0) {
            DrawSprite(x, y, work->unk_00C, work->unk_000, work->unk_008, affine, g, (-4100 - ((actor->unk_08 >> 8) << 2)) | 3);
        } else {
            DrawSprite(x, y, work->unk_00C, work->unk_000, work->unk_004, affine, g, (-4100 - ((actor->unk_08 >> 8) << 2)) | 3);
        }

        TaskPoolDraw(&work->unk_028);
    }
}

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
