#include "macros.h"
#include "emy.h"

void task_emy_00_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813D3CC, obj);
    work->unk_158 |= 1;
    work->unk_150 = 0x12;
    work->unk_14C = 0x16;
}

INCLUDE_ASM("emy/task_emy_00_1.s");

#ifdef NON_MATCHING
void task_emy_00_2(EmyWork* work) {
    EmyActor* act;
    u16 pri;
    s32 affine;
    s32 rot;
    s32 scale;
    s32 zoom;
    s16 x;
    s16 y;

    if (work->unk_15A != 0) {
        act = &work->unk_03C;
        pri = func_0801AF1C(act->unk_08) | work->unk_162;
        WorldToScreen(&x, &y, act->unk_04, act->unk_08, act->unk_0C);
        zoom = work->unk_180;

        if (zoom == 0x100) {
            if (act->unk_34 & 4) {
                scale = gUnk_02039B84->unk_024;
                rot = scale;
            } else if (gUnk_02039B84->unk_024 == zoom) {
                scale = zoom;
                rot = scale;
                pri |= 1;
            } else {
                rot = -gUnk_02039B84->unk_024;
                scale = gUnk_02039B84->unk_024;
            }
        } else {
            if (act->unk_34 & 4) {
                scale = gUnk_02039B84->unk_024;
                rot = work->unk_17C * scale >> 8;
            } else {
                scale = gUnk_02039B84->unk_024;
                rot = -(work->unk_17C * scale >> 8);
            }

            scale = scale * zoom >> 8;
        }

        if (scale == 0x100 && rot == scale) {
            affine = 0;
        } else if (scale <= 0xFF) {
            affine = AllocObjAffine(0, rot, scale, 0);
        } else {
            affine = AllocObjAffine(0, rot, scale, 1);
        }

        if (func_0801CA00(act)) {
            DrawSprite(x, y, work->unk_00C, work->unk_000, work->unk_008, affine, pri,
                -0x1004 - (act->unk_08 >> 8) * 4);
        } else if (work->unk_14C == 0x14) {
            DrawSprite(x, y, work->unk_00C, work->unk_000, work->unk_004, affine, pri, 0xFFFF);
        } else {
            DrawSprite(x, y, work->unk_00C, work->unk_000, work->unk_004, affine, pri,
                -0x1004 - (act->unk_08 >> 8) * 4);
        }

        TaskPoolDraw(&work->unk_028);
    }
}

#else
INCLUDE_ASM("emy/task_emy_00_2.s");
#endif

void task_emy_00_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_01_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813D454, obj);
    work->unk_150 = 7;
}

#ifdef NON_MATCHING
u8 task_emy_01_1(EmyWork* work) {
    EmyWork* w;
    EmyActor* act;
    u16 r;
    s32 z;
    s32 x;

    w = work;
    act = &work->unk_03C;

    if (_0800CBDC(work)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->unk_14C = 0x12;
            break;
        case 1:
            work->unk_14C = 0x13;
            break;
        }
    }

    switch (work->unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813D434, &w->unk_010, 0, 0, w->unk_000);
        work->unk_168 = 0;

        if (work->unk_154 != 0) {
            if (work->unk_154 == 0x16) {
                z = act->unk_08;

                if (act->unk_34 & 4) {
                    x = act->unk_04 - 0x6400;
                    func_08012E44(0, act->unk_04 - 0x2600, z, act->unk_0C - 0xC00, x, z, 0, 1,
                        0xA7);
                } else {
                    x = act->unk_04 + 0x6400;
                    func_08012E44(0, act->unk_04 + 0x2600, z, act->unk_0C - 0xC00, x, z, 0, 0,
                        0xA7);
                }
            }
        }

        if (work->unk_154 > 0x15 && !func_080128EC()) {
            func_0800CB4C(work);
        } else {
            work->unk_154++;
        }
        break;
    case 0x13:
        func_08019068(gUnk_0813D434, &w->unk_010, 1, 0, w->unk_000);
        work->unk_168 = 0;

        if (work->unk_154 != 0) {
            if (work->unk_154 == 0x16) {
                z = act->unk_08;

                if (act->unk_34 & 4) {
                    x = act->unk_04 - 0x6400;
                    func_08012E44(1, act->unk_04 - 0x2600, z, act->unk_0C - 0xC00, x, z, 0, 1,
                        0xA8);
                } else {
                    x = act->unk_04 + 0x6400;
                    func_08012E44(1, act->unk_04 + 0x2600, z, act->unk_0C - 0xC00, x, z, 0, 0,
                        0xA8);
                }
            }
        }

        if (work->unk_154 > 0x15 && !func_080128EC()) {
            func_0800CB4C(work);
        } else {
            work->unk_154++;
        }
        break;
    }

    return _0800CDF0(work);
}

#else
INCLUDE_ASM("emy/task_emy_01_1.s");
#endif

void task_emy_01_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_01_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_02_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813D4DC, obj);
    work->unk_150 = 7;
}

INCLUDE_ASM("emy/task_emy_02_1.s");

void task_emy_02_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_02_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_03_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813D564, obj);
    work->unk_150 = 7;
}

u8 task_emy_03_1(Emy03Work* work) {
    Emy03Work* w;
    EmyActor* act;
    u16 r;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->base.unk_14C = 0x12;
            break;
        case 1:
            work->base.unk_14C = 0x13;
            break;
        }
    }

    switch (work->base.unk_14C) {
    case 0x12:
        if (work->base.unk_154 == 0) {
            work->base.unk_168 = -0x480;
            func_08019068(gUnk_0813D544, &w->base.unk_010, 0, 0, w->base.unk_000);
        } else if (work->base.unk_154 == 1) {
            func_080141FC(act);
            m4aSongNumStart(0x246);
        }

        if (func_0800C980(&work->base, 0x11, 0x17, 0x0A, 0xAB, 0x50, 0x247, 0, 0, 0x0A) == 2) {
            func_08006B4C();
        }
        break;
    case 0x13:
        if (work->base.unk_154 == 0) {
            func_08019068(gUnk_0813D544, &w->base.unk_010, 1, 0, w->base.unk_000);
        } else if (work->base.unk_154 == 1) {
            func_0801C700(act, &w->unk_184, &w->unk_188, 0);
            w->unk_18C = 0;
            func_08015834(0, act->unk_04, act->unk_08, act->unk_0C - 0x1000, w->unk_184,
                w->unk_188, 0, 0xAC);
        }

        work->base.unk_168 = 0;

        if (AnimIsFinished(&work->base.unk_010) && !func_080128EC()) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_03_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_03_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_04_0(Emy04Work* work, void* obj) {
    func_0800C778(&work->base, gUnk_0813D5DC, obj);
    work->base.unk_150 = 7;
    work->unk_184 = 0;
    work->unk_186 = 0;
}

u8 task_emy_04_1(Emy04Work* work) {
    Emy04Work* w;
    EmyActor* act;
    EmyActor* p;
    EmyActor* best;
    s16 bestv;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        work->base.unk_14C = 0x12;
    }

    switch (work->base.unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813D5CC, &work->base.unk_010, 0, 0, work->base.unk_000);
        work->base.unk_168 = 0;

        if (work->unk_186 > 2) {
            func_08019190(act, 2);
            func_0800CB4C(&work->base);
            break;
        }

        if (work->base.unk_154 == 3) {
            best = 0;
            bestv = 0;

            for (p = func_08000C8C(gUnk_02039B84->unk_080); p != 0;
                    p = func_08000CD4(&p->unk_B8)) {
                if (!(p->unk_34 & 0x100)) {
                    if (bestv < p->unk_2E - p->unk_2C) {
                        bestv = p->unk_2E - p->unk_2C;
                        best = p;
                    }
                }
            }

            if (best == 0) {
                best = act;
            }

            if (best->unk_2C == best->unk_2E) {
                func_08019190(act, 2);
                func_0800CB4C(&work->base);
                break;
            }

            best->unk_34 |= 0x20;
            best->unk_20 = -0x1E;
            func_08012AAC(0, best->unk_04, best->unk_08, best->unk_0C);
            w->unk_186++;
        }

        if (work->base.unk_154 > 0x0D) {
            if (!func_080128EC()) {
                func_0800CB4C(&work->base);
            }
        } else {
            work->base.unk_154++;
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_04_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_04_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_06_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813D664, obj);
    work->unk_150 = 7;
}

u8 task_emy_06_1(Emy06Work* work) {
    Emy06Work* w;
    EmyActor* act;
    s32* p;
    u16 s;
    u16 m;
    s32 pos;
    s32 d;
    s32 t;
    s32 v;
    s32 e;
    s32 tx;
    s32 ty;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        func_0801C700(act, 0, &pos, 0);
        d = act->unk_08 - pos;

        if (d >= 0 ? d <= 0xFFF : pos - act->unk_08 <= 0xFFF) {
            work->base.unk_14C = 0x13;
        } else {
            work->base.unk_14C = 0x12;
        }

        w->unk_184 = 0;
    }

    switch (work->base.unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813D644, &w->base.unk_010, 0, 0, w->base.unk_000);
        work->base.unk_168 = 0;
        p = &gUnk_02039B84->unk_138;
        t = act->unk_0C + 0xC00;
        act->unk_0C += (*p - t) >> 4;
        s = func_08005B34(&work->base.unk_010);

        if (s >= 5 && s <= 20) {
            m = work->base.unk_154;
            m &= 3;

            if (m == 0) {
                func_0801C700(act, &tx, &ty, 0);
                work->base.unk_160 = GetAngle(act->unk_04, act->unk_08, tx, ty);
            }

            act->unk_04 += gSineTable[work->base.unk_160] * 2;
            act->unk_08 -= gSineTable[work->base.unk_160 + 0x40] * 2;

            if (func_08011F78(0xAF, act->unk_04, act->unk_08, act->unk_0C - 0x800, 0x14, 0x14,
                    8)) {
                m4aSongNumStart(0x249);
            }
        }

        if (AnimIsFinished(&work->base.unk_010)) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    case 0x13:
        func_08019068(gUnk_0813D644, &w->base.unk_010, 1, 0, w->base.unk_000);
        work->base.unk_168 = 0;
        p = &gUnk_02039B84->unk_138;
        t = act->unk_0C + 0xC00;
        act->unk_0C += (*p - t) >> 4;
        s = func_08005B34(&work->base.unk_010);

        if (s >= 6 && s <= 16) {
            if (act->unk_34 & 4) {
                v = act->unk_04;
                v += 0x7800;
            } else {
                v = act->unk_04;
                v -= 0x7800;
            }

            e = (act->unk_14 - v) >> 3;
            w->unk_184 += 0x33;

            if (e > w->unk_184) {
                e = w->unk_184;
            } else if (e < -w->unk_184) {
                e = -w->unk_184;
            }

            act->unk_04 += e;

            if (func_08011F78(0xB0, act->unk_04, act->unk_08, act->unk_0C - 0x800, 0x10, 0x10,
                    8)) {
                m4aSongNumStart(0x211);
            }
        }

        if (AnimIsFinished(&work->base.unk_010)) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_06_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_06_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_07_0(Emy07Work* work, void* obj) {
    func_0800C778(&work->base, gUnk_0813D73C, obj);
    work->unk_184 = 0;
    work->unk_186 = 0;
    work->base.unk_150 = 0x12;
    work->base.unk_03C.unk_34 |= 0x1000;
    work->unk_187 = 0;
}

INCLUDE_ASM("emy/task_emy_07_1.s");

void task_emy_07_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_07_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_08_0(Emy08Work* work, void* obj) {
    func_0800C778(&work->base, gUnk_0813D804, obj);
    work->unk_184 = LoadObjPalette(gUnk_08F698C4, 0x20);
    work->unk_188 = work->base.unk_004;
    work->unk_18C = 0;
}

INCLUDE_ASM("emy/task_emy_08_1.s");

void task_emy_08_2(Emy08Work* work) {
    work->base.unk_004 = (work->unk_18C & 2) ? work->unk_184 : work->unk_188;
    func_0800DF30(&work->base);
    work->base.unk_004 = work->unk_188;
}

void task_emy_08_3(Emy08Work* work) {
    func_0800E0D0(&work->base);
    ReleaseObjPalette(work->unk_184);
}

void task_emy_14_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813D88C, obj);
}

u8 task_emy_14_1(EmyWork* work) {
    EmyWork* w;
    EmyActor* act;
    s32 pos;
    s32 d;

    w = work;
    act = &work->unk_03C;

    if (_0800CBDC(work)) {
        func_0801C700(act, &pos, 0, 0);
        d = act->unk_04 - pos;

        if (d >= 0 ? d <= 0x31FF : pos - act->unk_04 <= 0x31FF) {
            work->unk_14C = 0x12;
        } else {
            work->unk_14C = 0x13;
        }
    }

    switch (work->unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813D86C, &w->unk_010, 0, 0, w->unk_000);
        func_0800C980(work, 0x0F, 0x0E, 0x14, 0xB3, 0x18, 0x242, 0, 0, 0x16);
        break;
    case 0x13:
        func_08019068(gUnk_0813D86C, &w->unk_010, 1, 0, w->unk_000);
        func_0800C980(work, 0x14, 0x25, 0x06, 0xB4, 0x64, 0x221, 0, 0, 0x14);
        break;
    }

    return _0800CDF0(work);
}

void task_emy_14_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_14_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_15_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813D944, obj);
}

u8 task_emy_15_1(EmyWork* work) {
    EmyWork* w;
    EmyActor* act;
    u16 r;

    w = work;
    act = &work->unk_03C;

    if (_0800CBDC(work)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->unk_14C = 0x12;
            break;
        case 1:
            work->unk_14C = 0x15;
            break;
        }
    }

    switch (work->unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813D8F4, &w->unk_010, 0, 0, w->unk_000);

        if (AnimIsFinished(&work->unk_010)) {
            work->unk_14C = 0x13;
            work->unk_154 = 0x1E;
        }
        break;
    case 0x13:
        func_08019068(gUnk_0813D8F4, &w->unk_010, 1, 0, w->unk_000);

        if (act->unk_34 & 4) {
            func_0800592C(&act->unk_04, act->unk_14 - 0x5000, work->unk_154);
        } else {
            func_0800592C(&act->unk_04, act->unk_14 + 0x5000, work->unk_154);
        }

        work->unk_154--;

        if ((act->unk_34 & 4)
                ? func_08011F78(0xB5, act->unk_04 - 0x1400, act->unk_08, act->unk_0C, 5, 5, 4)
                : func_08011F78(0xB5, act->unk_04 + 0x1400, act->unk_08, act->unk_0C, 5, 5, 4)) {
            m4aSongNumStart(0x242);
        }

        if (work->unk_154 <= 0) {
            work->unk_14C = 0x14;
            work->unk_154 = 0;
        }
        break;
    case 0x14:
        func_08019068(gUnk_0813D8F4, &w->unk_010, 2, 0, w->unk_000);

        if (AnimIsFinished(&work->unk_010)) {
            func_0800CB4C(work);
        }
        break;
    case 0x15:
        if (work->unk_154 == 0) {
            func_08019068(gUnk_0813D8F4, &w->unk_010, 3, 0, w->unk_000);
            work->unk_168 = -0x533;
        }

        if (work->unk_154 > 5) {
            work->unk_14C = 0x16;
            work->unk_154 = 0;
        } else {
            work->unk_154++;
        }
        break;
    case 0x16:
        func_08019068(gUnk_0813D8F4, &w->unk_010, 4, 0, w->unk_000);
        func_0800C980(work, 0x16, 0x16, 0x3C, 0xB6, 0x40, 0x221, 0x10, -0x0C, 0x0C);
        break;
    }

    return _0800CDF0(work);
}

void task_emy_15_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_15_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_16_0(Emy16Work* work, void* obj) {
    func_0800C778(&work->base, gUnk_0813D9CC, obj);
    work->unk_184 = 0;
    work->unk_188 = 0;
    TaskPoolInit(&work->unk_18C, 2);
}

u8 task_emy_16_1(Emy16Work* work) {
    Emy16Work* w;
    EmyActor* act;
    EmySpawn spawn;
    u16 r;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        if (func_08000F60(work->unk_188, gTaskDescEmy16B)) {
            work->base.unk_14C = 0x12;
        } else {
            r = GetRandom();

            switch (r & 1) {
            case 0:
                work->base.unk_14C = 0x12;
                break;
            case 1:
                work->base.unk_14C = 0x13;
                break;
            }
        }

        w->unk_1A0 = 0;
    }

    switch (work->base.unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813D9AC, &w->base.unk_010, 0, 0, w->base.unk_000);

        if (func_08005B34(&work->base.unk_010) == 3 && work->base.unk_01A == 0) {
            if (act->unk_34 & 4) {
                spawn.unk_00 = act->unk_04 - 0x1000;
                spawn.unk_04 = act->unk_08;
                spawn.unk_08 = act->unk_0C - 0x1000;
                spawn.unk_12 = 1;
            } else {
                spawn.unk_00 = act->unk_04 + 0x1000;
                spawn.unk_04 = act->unk_08;
                spawn.unk_08 = act->unk_0C - 0x1000;
                spawn.unk_12 = 0;
            }

            w->unk_184 = TaskCreate(&w->unk_18C, &gTaskDescEmy16P, &spawn);
            w->unk_1A0 = 1;
        }

        if (w->unk_1A0 != 0) {
            if (!func_08000F60(w->unk_184, gTaskDescEmy16P)) {
                func_0800CB4C(&work->base);
            }
        }
        break;
    case 0x13:
        func_08019068(gUnk_0813D9AC, &w->base.unk_010, 1, 0, w->base.unk_000);

        if (func_08005B34(&work->base.unk_010) == 0x0A && work->base.unk_01A == 0) {
            if (act->unk_34 & 4) {
                spawn.unk_00 = act->unk_04 - 0xC00;
                spawn.unk_04 = act->unk_08;
                spawn.unk_08 = act->unk_0C - 0x200;
                spawn.unk_12 = 1;
            } else {
                spawn.unk_00 = act->unk_04 + 0xC00;
                spawn.unk_04 = act->unk_08;
                spawn.unk_08 = act->unk_0C - 0x200;
                spawn.unk_12 = 0;
            }

            w->unk_188 = TaskCreate(&w->unk_18C, &gTaskDescEmy16B, &spawn);
        }

        if (AnimIsFinished(&work->base.unk_010)) {
            func_0800CB4C(&work->base);
        }
        break;
    }

    TaskPoolUpdate(&w->unk_18C);
    return _0800CDF0(&work->base);
}

void task_emy_16_2(Emy16Work* work) {
    func_0800DF30(&work->base);
    TaskPoolDraw(&work->unk_18C);
}

void task_emy_16_3(Emy16Work* work) {
    func_0800E0D0(&work->base);
    TaskPoolDestroy(&work->unk_18C);
}

void task_emy_16_b_0(Emy16bWork* work, EmySpawn* spawn) {
    if (spawn->unk_12 != 0) {
        work->unk_02C = 1;
    } else {
        work->unk_02C = 0;
    }

    work->unk_004 = LoadObjPalette(gUnk_08F699C4, 0x20);
    work->unk_000 = AllocObjTiles(0x80, gUnk_08A23630);
    AnimInit(work->unk_008, gUnk_09EE04F4, gUnk_09EE04E0);
    AnimStart(work->unk_008, 0, 1);
    work->unk_038 = 0;
    work->unk_020 = spawn->unk_00;
    work->unk_024 = spawn->unk_04;
    work->unk_028 = spawn->unk_08;
    work->unk_034 = 0x200;
    work->unk_030 = -0x34C;
    work->unk_03C = 0;
    work->unk_09C = 1;
    work->unk_09D = 0;
    func_080122AC(&work->unk_040, 0x0C, 4, 3);
    func_08012614(&work->unk_040, 1);
}

u8 task_emy_16_b_1(Emy16bWork* work) {
    switch (work->unk_038) {
    case 0:
        if (work->unk_02C != 0) {
            work->unk_020 -= work->unk_034;
        } else {
            work->unk_020 += work->unk_034;
        }

        if (func_0801A8A4(&work->unk_020, &work->unk_024, -0x10, 0) != 0) {
            work->unk_034 = -work->unk_034;
        }

        if (work->unk_09D == 0
                && func_08011E3C(work->unk_020, work->unk_024, work->unk_028, 4, 4, 4)) {
            work->unk_034 = -(work->unk_034 >> 1);
            work->unk_09D = 1;
        }

        if (work->unk_028 >= 0) {
            work->unk_038 = 1;
            work->unk_03C = 0;
        }
        break;
    case 1:
        if (work->unk_03C == 0) {
            func_08012614(&work->unk_040, 0);
            AnimStart(work->unk_008, 1, 1);
        }

        if (work->unk_06C != 0) {
            work->unk_03C = 0;
            work->unk_038 = 2;
            func_08012614(&work->unk_040, 1);
        } else if (work->unk_03C > 0x64) {
            work->unk_03C = 0;
            work->unk_038 = 3;
        } else {
            work->unk_03C++;
        }
        break;
    case 2:
        if (work->unk_03C != 0) {
            if (work->unk_028 >= 0) {
                work->unk_03C = 0;
                work->unk_038 = 3;
                break;
            }
        } else {
            AnimStart(work->unk_008, 2, 1);
            work->unk_030 = -0x3CC;
        }

        work->unk_03C++;
        break;
    case 3:
        if ((work->unk_03C & 3) == 0) {
            work->unk_09C = work->unk_09C == 0;
        }

        if (work->unk_06C != 0) {
            work->unk_03C = 0;
            work->unk_038 = 2;
            func_08012614(&work->unk_040, 1);
            work->unk_09C = 1;
        } else if (work->unk_03C > 0x3C) {
            return 0;
        } else {
            work->unk_03C++;
        }
        break;
    }

    work->unk_028 += work->unk_030;
    work->unk_030 += 0x33;

    if (work->unk_028 >= 0) {
        work->unk_030 = 0;
        work->unk_028 = 0;
    }

    func_08012324(&work->unk_040, work->unk_020, work->unk_024, work->unk_028);
    AnimUpdate(work->unk_008);
    return 1;
}

void task_emy_16_b_2(Emy16bWork* work) {
    void* gfx;
    u16 pri;
    s32 affine;
    s32 angle;
    s16 x;
    s16 y;

    gfx = AnimGetGfx(work->unk_008);

    if (work->unk_09C != 0) {
        pri = func_0801AF1C(work->unk_024);
        WorldToScreen(&x, &y, work->unk_020, work->unk_024, work->unk_028);
        angle = gUnk_02039B84->unk_024;

        if (angle == 0x100) {
            affine = 0;

            if (work->unk_02C == 0) {
                pri |= 1;
            }
        } else if (work->unk_02C == 0) {
            affine = AllocObjAffine(0, -angle, angle, 1);
        } else {
            affine = AllocObjAffine(0, angle, angle, 1);
        }

        DrawSprite(x, y, gfx, work->unk_000, work->unk_004, affine, pri,
            -0x1004 - (work->unk_024 >> 8) * 4);
    }
}

void task_emy_16_b_3(Emy16bWork* work) {
    func_08012304(&work->unk_040);
    ReleaseObjTiles(work->unk_000);
    ReleaseObjPalette(work->unk_004);
}

void task_emy_16_p_0(Emy16pWork* work, EmySpawn* spawn) {
    if (spawn->unk_12 != 0) {
        work->unk_02C = 1;
    } else {
        work->unk_02C = 0;
    }

    work->unk_004 = LoadObjPalette(gUnk_08F699C4, 0x20);
    work->unk_000 = AllocObjTiles(0x80, gUnk_08A20BCE);
    AnimInit(work->unk_008, gUnk_09EE04B4, gUnk_09EE04AC);
    AnimStart(work->unk_008, 0, 1);
    work->unk_020 = spawn->unk_00;
    work->unk_024 = spawn->unk_04;
    work->unk_028 = spawn->unk_08;
    work->unk_030 = 0;
}

u8 task_emy_16_p_1(Emy16pWork* work) {
    if ((gUnk_02039B84->unk_068 & 0x40) == 0) {
        return 0;
    }

    if (work->unk_02C != 0) {
        work->unk_020 -= 0x400;
    } else {
        work->unk_020 += 0x400;
    }

    if (func_08011F78(0xB7, work->unk_020, work->unk_024, work->unk_028, 4, 4, 4) != 0) {
        m4aSongNumStart(0x264);
    }

    if (func_0801A8A4(&work->unk_020, &work->unk_024, 0x10, 0) != 0) {
        return 0;
    }

    work->unk_028 += work->unk_030;
    work->unk_030 += 0x2E;

    if (work->unk_028 >= 0) {
        work->unk_030 = -0x400;
        work->unk_028 = 0;
    }

    AnimUpdate(work->unk_008);
    return 1;
}

void task_emy_16_p_2(Emy16pWork* work) {
    void* gfx;
    u16 pri;
    s16 x;
    s16 y;

    gfx = AnimGetGfx(work->unk_008);
    pri = func_0801AF1C(work->unk_024);
    WorldToScreen(&x, &y, work->unk_020, work->unk_024, work->unk_028);
    DrawSprite(x, y, gfx, work->unk_000, work->unk_004, 0, pri,
        -0x1004 - ((work->unk_024 + 0x1000) >> 8) * 4);
}

void task_emy_16_p_3(Emy16pWork* work) {
    ReleaseObjTiles(work->unk_000);
    ReleaseObjPalette(work->unk_004);
}

void task_emy_18_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813DA94, obj);
    work->unk_03C.unk_0C = (GetRandom() % 0x1001) - 0x3000;
    work->unk_150 = 7;
}

INCLUDE_ASM("emy/task_emy_18_1.s");

void task_emy_18_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_18_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_19_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813DB4C, obj);
}

INCLUDE_ASM("emy/task_emy_19_1.s");

void task_emy_19_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_19_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_21_0(Emy21Work* work, void* obj) {
    func_0800C778(&work->base, gUnk_0813DBF4, obj);
    work->unk_184 = 0;
}

INCLUDE_ASM("emy/task_emy_21_1.s");

void task_emy_21_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_21_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_22_0(Emy22Work* work, void* obj) {
    func_0800C778(&work->base, gUnk_0813DC7C, obj);
    work->base.unk_150 = 7;
    work->unk_184 = 0;
}

INCLUDE_ASM("emy/task_emy_22_1.s");

void task_emy_22_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_22_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_23_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813DD04, obj);
    work->unk_150 = 7;
}

u8 task_emy_23_1(Emy23Work* work) {
    Emy23Work* w;
    EmyActor* act;
    s32 pos;
    s32 d;
    s32 t;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        func_0801C700(act, &pos, 0, 0);
        d = act->unk_04 - pos;

        if (d >= 0 ? d <= 0x31FF : pos - act->unk_04 <= 0x31FF) {
            work->base.unk_14C = 0x13;
        } else {
            work->base.unk_14C = 0x12;
        }
    }

    switch (work->base.unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813DCE4, &w->base.unk_010, 0, 0, w->base.unk_000);

        switch (func_08005B34(&work->base.unk_010)) {
        case 0:
        case 1:
        case 2:
            work->base.unk_168 = 0;
            act->unk_0C += (-0x4000 - act->unk_0C) >> 3;
            break;
        case 3:
            if (work->base.unk_01A == 0) {
                func_0801C700(act, &t, 0, 0);
                work->base.unk_168 = 0x200;
                w->unk_184 = t;
            }
        case 4:
        case 5:
            if (act->unk_0C >= act->unk_10) {
                work->base.unk_168 = -0x466;
            }

            act->unk_04 += (w->unk_184 - act->unk_04) >> 4;

            if (func_08011F78(0xC1, act->unk_04, act->unk_08, act->unk_0C - 0x1000, 12, 16, 16)) {
                m4aSongNumStart(0x22E);
                work->base.unk_168 = -0x466;
            }
            break;
        }

        if (AnimIsFinished(&work->base.unk_010)) {
            func_0800CB4C(&work->base);
        }
        break;
    case 0x13:
        func_08019068(gUnk_0813DCE4, &w->base.unk_010, 1, 0, w->base.unk_000);
        act->unk_0C += -act->unk_0C >> 2;

        if (func_08005B34(&work->base.unk_010) == 3) {
            if ((act->unk_34 & 4)
                    ? func_08011F78(0xC2, act->unk_04 - 0x1E00, act->unk_08, act->unk_0C,
                        0x10, 0x10, 4)
                    : func_08011F78(0xC2, act->unk_04 + 0x1E00, act->unk_08, act->unk_0C,
                        0x10, 0x10, 4)) {
                m4aSongNumStart(0x22E);
            }
        }

        if (AnimIsFinished(&work->base.unk_010)) {
            func_0800CB4C(&work->base);
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_23_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_23_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_25_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813DD8C, obj);
}

u8 task_emy_25_1(EmyWork* work) {
    EmyWork* w;
    EmyActor* act;
    u16 r;
    s32 dx;
    u16 dy;
    u16 e;
    u16 f;

    w = work;
    act = &work->unk_03C;

    if (_0800CBDC(work)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->unk_14C = 0x12;
            break;
        case 1:
            work->unk_14C = 0x13;
            break;
        }
    }

    switch (work->unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813DD6C, &w->unk_010, 0, 0, w->unk_000);

        if (AnimIsFinished(&work->unk_010)) {
            func_0800CB4C(work);
        } else if (work->unk_01A == 0) {
            dx = 0;
            dy = 0;

            switch (work->unk_01E) {
            case 2:
                dx = 5;
                dy = -1;
                break;
            case 3:
                dx = 5;
                dy = -2;

                if ((act->unk_34 & 4)
                        ? func_08011F78(0xC3, act->unk_04 - 0x2800, act->unk_08, act->unk_0C,
                            0x10, 0x10, 0x20)
                        : func_08011F78(0xC3, act->unk_04 + 0x2800, act->unk_08, act->unk_0C,
                            0x10, 0x10, 0x20)) {
                    m4aSongNumStart(0x242);
                }
                break;
            case 4:
                dx = 5;
                dy = -1;
                break;
            case 5:
                dx = 6;
                dy = -2;
                break;
            case 6:
                dx = 6;
                dy = -1;
                break;
            case 7:
                dx = 1;
                dy = -1;
                break;
            }

            if (act->unk_34 & 4) {
                act->unk_04 -= dx << 8;
            } else {
                act->unk_04 += dx << 8;
            }

            act->unk_08 -= (s16)dy << 8;
        }
        break;
    case 0x13:
        func_08019068(gUnk_0813DD6C, &w->unk_010, 1, 0, w->unk_000);

        if (AnimIsFinished(&work->unk_010)) {
            func_0800CB4C(work);
        } else if (work->unk_01A == 0) {
            e = 0;
            f = 0;

            switch (work->unk_01E) {
            case 8:
                e = 4;
                break;
            case 9:
                e = 2;
                break;
            case 10:
                e = 2;
                f = -1;
                break;
            case 11:
                e = 4;
                break;
            case 12:
                e = 7;
                f = -2;
                break;
            case 13:
                e = 1;
                f = -2;
                break;
            case 26:
                e = -5;
                f = 1;
                break;
            case 27:
                e = -15;
                f = 4;
                break;
            }

            if (act->unk_34 & 4) {
                act->unk_04 -= (s16)e << 8;
            } else {
                act->unk_04 += (s16)e << 8;
            }

            act->unk_08 -= (s16)f << 8;

            if (work->unk_01E >= 8 && work->unk_01E <= 22) {
                if ((act->unk_34 & 4)
                        ? func_08011F78(0xC4, act->unk_04, act->unk_08, act->unk_0C, 0x30, 0x30,
                            0x20)
                        : func_08011F78(0xC4, act->unk_04, act->unk_08, act->unk_0C, 0x30, 0x30,
                            0x20)) {
                    m4aSongNumStart(0x211);
                }
            }
        }
        break;
    }

    return _0800CDF0(work);
}

void task_emy_25_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_25_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_26_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813DE14, obj);
    work->unk_03C.unk_0C = (GetRandom() % 0x1001) - 0x3000;
    work->unk_150 = 7;
}

u8 task_emy_26_1(EmyWork* work) {
    EmyWork* w;
    EmyActor* act;
    u16 r;
    s32 z;
    s32 x;
    s32 t;
    s32* p;

    w = work;
    act = &work->unk_03C;

    if (_0800CBDC(work)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->unk_14C = 0x12;
            break;
        case 1:
            work->unk_14C = 0x13;
            break;
        }
    }

    switch (work->unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813DDF4, &w->unk_010, 0, 0, w->unk_000);

        switch (func_08005B34(&work->unk_010)) {
        case 3:
            if (work->unk_01A == 0) {
                work->unk_168 = 0x300;
            }
            break;
        case 0:
        case 1:
        case 2:
            work->unk_168 = 0;
            p = &gUnk_02039B84->unk_138;
            t = act->unk_0C + 0x3C00;
            act->unk_0C += (*p - t) >> 3;
            break;
        }

        func_0800C980(work, 0x20, 0x0C, 0x14, 0xC5, 0x28, 0x242, 0x14, 0x0A, 0x0A);
        break;
    case 0x13:
        work->unk_168 = 0;

        switch (work->unk_154) {
        case 0:
            func_08019068(gUnk_0813DDF4, &w->unk_010, 1, 0, w->unk_000);
            work->unk_154++;
            break;
        case 1:
            if (AnimIsFinished(&work->unk_010)) {
                z = act->unk_08;

                if (act->unk_34 & 4) {
                    x = act->unk_04 - 0x6400;
                    func_08012E44(1, act->unk_04 - 0x2600, z, act->unk_0C - 0x2000, x, z, 0, 1,
                        0xC6);
                } else {
                    x = act->unk_04 + 0x6400;
                    func_08012E44(1, act->unk_04 + 0x2600, z, act->unk_0C - 0x2000, x, z, 0, 0,
                        0xC6);
                }

                work->unk_154++;
            }
            break;
        case 2:
            AnimChange(&work->unk_010, 1, 0);

            if (AnimIsFinished(&work->unk_010)) {
                work->unk_154++;
            }
            break;
        case 3:
            AnimChange(&work->unk_010, 1, 0);

            if (AnimIsFinished(&work->unk_010)) {
                func_0800CB4C(work);
            }
            break;
        }
        break;
    }

    return _0800CDF0(work);
}

void task_emy_26_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_26_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_27_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813DE9C, obj);
}

u8 task_emy_27_1(EmyWork* work) {
    EmyWork* w;
    EmyActor* act;
    u16 s;
    s32 d;
    s32 y;
    s32 tx;
    s32 ty;

    w = work;
    act = &work->unk_03C;

    if (_0800CBDC(work)) {
        func_0801C700(act, 0, &y, 0);
        d = act->unk_08 - y;

        if (d >= 0 ? d <= 0xFFF : y - act->unk_08 <= 0xFFF) {
            work->unk_14C = 0x12;
        } else {
            work->unk_14C = 0x13;
        }
    }

    switch (work->unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813DE7C, &w->unk_010, 0, 0, w->unk_000);

        if (func_08005B34(&work->unk_010) == 1 && work->unk_01A == 0) {
            m4aSongNumStart(0x267);

            if (act->unk_34 & 4) {
                func_08013480(act->unk_04 - 0xC00, act->unk_08, act->unk_0C - 0x2200);
            } else {
                func_08013480(act->unk_04 + 0xC00, act->unk_08, act->unk_0C - 0x2200);
            }
        }

        func_0800C980(work, 0x3D, 6, 0x14, 0xC8, 0x20, 0x268, 0x28, 0, 0x14);
        break;
    case 0x13:
        func_08019068(gUnk_0813DE7C, &w->unk_010, 1, 1, w->unk_000);
        func_0801C700(act, &tx, &ty, 0);

        if (work->unk_154 % 6 == 0) {
            work->unk_160 = GetAngle(act->unk_04, act->unk_08, tx, ty);
        }

        act->unk_04 += gSineTable[work->unk_160];
        act->unk_08 -= gSineTable[work->unk_160 + 0x40];

        if (act->unk_04 > tx) {
            act->unk_34 |= 4;
        } else {
            act->unk_34 &= ~4;
        }

        s = func_08005B34(&work->unk_010);

        if (s == 2 || s == 5) {
            if ((act->unk_34 & 4)
                    ? func_08011F78(0xC7, act->unk_04 - 0x1000, act->unk_08, act->unk_0C, 0x14,
                        0x14, 0x20)
                    : func_08011F78(0xC7, act->unk_04 + 0x1000, act->unk_08, act->unk_0C, 0x14,
                        0x14, 0x20)) {
                m4aSongNumStart(0x244);
            }
        }

        if (work->unk_154 > 0x78) {
            func_0800CB4C(work);
        } else {
            work->unk_154++;
        }
        break;
    }

    return _0800CDF0(work);
}

void task_emy_27_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_27_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_28_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813DF44, obj);
    work->unk_03C.unk_0C = (GetRandom() % 0x1001) - 0x3000;
    work->unk_150 = 7;
}

INCLUDE_ASM("emy/task_emy_28_1.s");

void task_emy_28_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_28_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_29_0(Emy29Work* work, void* obj) {
    func_0800C778(&work->base, gUnk_0813DFCC, obj);
    work->base.unk_16C = 0x180;
    work->base.unk_150 = 7;
    work->base.unk_158 |= 1;
    work->unk_184 = 0;
    work->unk_186 = 0;
}

void func_0803B468(Emy29Work* work, s16 anim, s16 dx, s16 dy, s16 dz) {
    if (work->unk_186 > 0) {
        AnimChange(&work->base.unk_010, anim, 0);
        ApproachValue(&work->base.unk_03C.unk_04, work->base.unk_03C.unk_14 + ((s16)dx << 8), work->unk_186);
        ApproachValue(&work->base.unk_03C.unk_08, work->base.unk_03C.unk_18 + ((s16)dy << 8), work->unk_186);
        ApproachValue(&work->base.unk_03C.unk_0C, (s16)dz << 8, work->unk_186);
        work->unk_186--;
    } else {
        work->unk_186 = 8;
        work->unk_184++;
    }
}

u8 task_emy_29_1(Emy29Work* work) {
    Emy29Work* w;
    EmyActor* act;
    s32 pos;
    s32 d;
    s32 a;
    s32 t;
    s16 c;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        func_0801C700(act, &pos, 0, 0);
        d = act->unk_04 - pos;

        if (d >= 0 ? d <= 0x27FF : pos - act->unk_04 <= 0x27FF) {
            work->base.unk_14C = 0x13;
        } else {
            work->base.unk_14C = 0x12;
        }
    }

    switch (work->base.unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813DFAC, &w->base.unk_010, 0, 0, w->base.unk_000);
        work->base.unk_168 = 0;
        a = -gSineTable[(((u16)work->base.unk_154 * 2) & 0xFF) + 0x40] << 4;
        t = act->unk_0C + 0x1000;
        act->unk_0C += (a - t) >> 2;

        if (func_0800C980(&work->base, 0x16, 0x64, 0x18, 0xCB, 0xB4, 0x241, 0, 0, 0x0C) == 1) {
            func_0800CB4C(&work->base);
        }
        break;
    case 0x13:
        c = work->base.unk_154;

        if (c == 0) {
            func_08019068(gUnk_0813DFAC, &w->base.unk_010, 1, 0, w->base.unk_000);
            w->unk_184 = 0;
            w->unk_186 = 8;
            work->base.unk_154++;
            m4aSongNumStart(0x240);
        }

        switch (w->unk_184) {
        case 0:
            func_0803B468(w, 0, -25, 5, -10);
            break;
        case 1:
            func_0803B468(w, 1, 25, 0, 0);
            break;
        case 2:
            func_0803B468(w, 2, -20, -5, -22);
            break;
        case 3:
            func_0803B468(w, 3, 5, -17, -8);
            break;
        case 4:
            func_0803B468(w, 4, -5, 17, -16);
            break;
        case 5:
            func_0803B468(w, 5, 0, -17, 0);
            break;
        case 6:
            func_0803B468(w, 6, 25, 0, -11);
            break;
        case 7:
            func_0803B468(w, 7, -25, 0, -4);
            break;
        case 8:
            func_0803B468(w, 8, 0, 0, 0);
            break;
        case 9:
            func_0800CB4C(&work->base);
            break;
        }

        if ((act->unk_34 & 4)
                ? func_08011F78(0xCC, act->unk_04, act->unk_08, act->unk_0C, 0x0C, 0x0C, 0x0C)
                : func_08011F78(0xCC, act->unk_04, act->unk_08, act->unk_0C, 0x0C, 0x0C, 0x0C)) {
            m4aSongNumStart(0x212);
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_29_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_29_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_30_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813E0B4, obj);
    work->unk_03C.unk_0C = (GetRandom() % 0x1001) - 0x3000;
    work->unk_150 = 7;
}

INCLUDE_ASM("emy/task_emy_30_1.s");

void task_emy_30_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_30_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_31_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813E14C, obj);
    work->unk_150 = 7;
}

INCLUDE_ASM("emy/task_emy_31_1.s");

void task_emy_31_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_31_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_37_0(Emy37Work* work, void* obj) {
    func_0800C778(&work->base, gUnk_0813E264, obj);
    work->base.unk_158 |= 1;
    work->base.unk_150 = 0x12;
    work->base.unk_14C = 0x1C;
    work->unk_184 = 0;
}

INCLUDE_ASM("emy/task_emy_37_1.s");

#ifdef NON_MATCHING
void task_emy_37_2(Emy37Work* work) {
    Emy37Work* w;
    EmyActor* act;
    u16 pri;
    s32 affine;
    s32 rot;
    s32 scale;
    s32 zoom;
    u8 f;
    s16 x;
    s16 y;

    w = work;

    if (work->base.unk_15A != 0) {
        act = &work->base.unk_03C;
        pri = func_0801AF1C(act->unk_08) | work->base.unk_162;
        WorldToScreen(&x, &y, act->unk_04, act->unk_08, act->unk_0C);

        zoom = work->base.unk_180;

        if (zoom == 0x100) {
            if (act->unk_34 & 4) {
                scale = gUnk_02039B84->unk_024;
                rot = scale;
            } else if (work->unk_184 == 0 && gUnk_02039B84->unk_024 == zoom) {
                scale = zoom;
                rot = scale;
                pri |= 1;
            } else {
                rot = -gUnk_02039B84->unk_024;
                scale = gUnk_02039B84->unk_024;
            }
        } else {
            if (act->unk_34 & 4) {
                scale = gUnk_02039B84->unk_024;
                rot = work->base.unk_17C * scale >> 8;
            } else {
                scale = gUnk_02039B84->unk_024;
                rot = -(work->base.unk_17C * scale >> 8);
            }

            scale = scale * zoom >> 8;
        }

        f = w->unk_184;

        if (f == 0) {
            if (scale == 0x100 && rot == scale) {
                affine = 0;
            } else if (scale <= 0xFF) {
                affine = AllocObjAffine(0, rot, scale, 0);
            } else {
                affine = AllocObjAffine(0, rot, scale, 1);
            }
        } else {
            affine = AllocObjAffine(f, rot, scale, 1);
        }

        if (func_0801CA00(act)) {
            DrawSprite(x, y, work->base.unk_00C, work->base.unk_000, work->base.unk_008, affine,
                pri, -0x1004 - (act->unk_08 >> 8) * 4);
        } else if (work->base.unk_14C == 0x14) {
            DrawSprite(x, y, work->base.unk_00C, work->base.unk_000, work->base.unk_004, affine,
                pri, 0xFFFF);
        } else {
            DrawSprite(x, y, work->base.unk_00C, work->base.unk_000, work->base.unk_004, affine,
                pri, -0x1004 - (act->unk_08 >> 8) * 4);
        }

        TaskPoolDraw(&work->base.unk_028);
    }
}

#else
INCLUDE_ASM("emy/task_emy_37_2.s");
#endif

void task_emy_37_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_38_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813E2EC, obj);
}

u8 task_emy_38_1(EmyWork* work) {
    EmyWork* w;
    EmyActor* act;
    u16 r;
    u8 ret;

    w = work;
    act = &work->unk_03C;

    if (_0800CBDC(work)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->unk_14C = 0x12;
            break;
        case 1:
            work->unk_14C = 0x13;
            break;
        }
    }

    switch (work->unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813E2CC, &w->unk_010, 0, 0, w->unk_000);
        func_0800C980(work, 0x1E, 0x14, 0x2D, 0xD4, 0x32, 0x212, 0, 0, 0x18);

        if (work->unk_154 == 0x1E) {
            work->unk_168 = -0x300;
        }
        break;
    case 0x13:
        func_08019068(gUnk_0813E2CC, &w->unk_010, 1, 0, w->unk_000);

        if (work->unk_154 == 0x3F) {
            func_08011F78(0xD5, act->unk_04, act->unk_08, act->unk_0C, 0x100, 0x100, 1);
            m4aSongNumStart(0x210);
            func_0802F1E8();
        }

        if (AnimIsFinished(&work->unk_010)) {
            func_0800CB4C(work);
        } else {
            work->unk_154++;
        }
        break;
    }

    ret = _0800CDF0(work);

    if ((gUnk_02039B84->unk_07C->unk_004 < work->unk_03C.unk_04 && (work->unk_03C.unk_34 & 4)) ||
            (gUnk_02039B84->unk_07C->unk_004 > work->unk_03C.unk_04 &&
                !(work->unk_03C.unk_34 & 4))) {
        work->unk_03C.unk_34 |= 0x8000;
    } else {
        work->unk_03C.unk_34 &= ~0x8000;
    }

    return ret;
}

void task_emy_38_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_38_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_39_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813E374, obj);
}

u8 task_emy_39_1(Emy39Work* work) {
    Emy39Work* w;
    EmyActor* act;
    u16 r;
    s16 c;
    s32 z;
    s32 x;
    s32 p;
    s32 q;
    u8 ret;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->base.unk_14C = 0x12;
            break;
        case 1:
            work->base.unk_14C = 0x13;
            break;
        }
    }

    switch (work->base.unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813E354, &w->base.unk_010, 0, 0, w->base.unk_000);

        if (work->base.unk_154 == 0x30) {
            z = act->unk_08;

            if (act->unk_34 & 4) {
                x = act->unk_04 - 0x6400;
                func_08012E44(0, act->unk_04 - 0x4000, z, act->unk_0C - 0x2000, x, z, 0, 1,
                    0xD6);
            } else {
                x = act->unk_04 + 0x6400;
                func_08012E44(0, act->unk_04 + 0x4000, z, act->unk_0C - 0x2000, x, z, 0, 0,
                    0xD6);
            }
        }

        if (work->base.unk_154 > 0x30 && func_08006B74()) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    case 0x13:
        c = work->base.unk_154;

        if (c == 0) {
            func_08019068(gUnk_0813E354, &w->base.unk_010, 1, 0, w->base.unk_000);
            w->unk_184 = 0;
        }

        switch (func_08005B34(&work->base.unk_010)) {
        case 0:
            p = 24;
            q = 20;
            break;
        case 1:
            p = 30;
            q = 16;
            break;
        case 2:
            p = 24;
            q = 20;

            if (work->base.unk_01A == 0) {
                w->unk_184 = 0x200;
            }
            break;
        case 3:
            p = 24;
            q = 16;
            break;
        case 4:
            p = 48;
            q = 20;
            break;
        case 5:
            p = 30;
            q = 16;

            if (work->base.unk_01A == 0) {
                w->unk_184 = 0x200;
            }
            break;
        case 6:
            p = 48;
            q = 20;
            break;
        case 7:
        default:
            p = 24;
            q = 20;
            break;
        }

        if (act->unk_34 & 4) {
            act->unk_04 -= w->unk_184;
        } else {
            act->unk_04 += w->unk_184;
        }

        w->unk_184 -= 0x19;

        if (w->unk_184 < 0) {
            w->unk_184 = 0;
        }

        if (func_08011F78(0xD7, act->unk_04, act->unk_08, act->unk_0C, p, q, 0x28)) {
            m4aSongNumStart(0x221);
        }

        if (AnimIsFinished(&work->base.unk_010)) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    }

    ret = _0800CDF0(&work->base);

    if ((gUnk_02039B84->unk_07C->unk_004 < work->base.unk_03C.unk_04
                && (work->base.unk_03C.unk_34 & 4))
            || (gUnk_02039B84->unk_07C->unk_004 > work->base.unk_03C.unk_04
                && !(work->base.unk_03C.unk_34 & 4))) {
        work->base.unk_03C.unk_34 |= 0x8000;
    } else {
        work->base.unk_03C.unk_34 &= ~0x8000;
    }

    return ret;
}

void task_emy_39_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_39_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_41_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813E3FC, obj);
    work->unk_150 = 7;
}

u8 task_emy_41_1(Emy41Work* work) {
    Emy41Work* w;
    EmyActor* act;
    u16 r;
    s32 t;
    s32 a;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->base.unk_14C = 0x12;
            break;
        case 1:
            work->base.unk_14C = 0x13;
            break;
        }
    }

    switch (work->base.unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813E3DC, &w->base.unk_010, 0, 0, w->base.unk_000);
        work->base.unk_168 = 0;
        a = gSineTable[((u16)work->base.unk_154 * 4) & 0xFF] << 4;
        t = act->unk_0C + 0x1000;
        act->unk_0C += (a - t) >> 2;
        func_0800C980(&work->base, 0x14, 0x63, 0x1E, 0xD8, 0x40, 0x221, 0, -0x10, 0x2C);
        break;
    case 0x13:
        if (work->base.unk_154 == 0) {
            func_08019068(gUnk_0813E3DC, &w->base.unk_010, 1, 0, w->base.unk_000);
            func_0801C700(act, &w->unk_184, &w->unk_188, 0);
            w->unk_18C = 0;
        }

        if (func_08005B34(&work->base.unk_010) == 4 && work->base.unk_01A == 0) {
            if (act->unk_34 & 4) {
                func_08015834(1, act->unk_04 - 0x2C00, act->unk_08, act->unk_0C, w->unk_184,
                    w->unk_188, w->unk_18C, 0xD9);
            } else {
                func_08015834(1, act->unk_04 + 0x2C00, act->unk_08, act->unk_0C, w->unk_184,
                    w->unk_188, w->unk_18C, 0xD9);
            }
        }

        if (AnimIsFinished(&work->base.unk_010)) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_41_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_41_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_44_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813E484, obj);
}

u8 task_emy_44_1(EmyWork* work) {
    EmyWork* w;
    EmyActor* act;
    s32 pos;
    s32 d;
    u8 ret;

    w = work;
    act = &work->unk_03C;

    if (_0800CBDC(work)) {
        func_0801C700(act, &pos, 0, 0);
        d = act->unk_04 - pos;

        if (d >= 0 ? d <= 0x4FFF : pos - act->unk_04 <= 0x4FFF) {
            work->unk_14C = 0x12;
        } else {
            work->unk_14C = 0x13;
        }
    }

    switch (work->unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813E464, &w->unk_010, 0, 0, w->unk_000);

        switch (func_08005B34(&work->unk_010)) {
        case 1:
        case 2:
        case 3:
        case 4:
            if ((act->unk_34 & 4)
                    ? func_08011F78(0xDA, act->unk_04 - 0x2000, act->unk_08, act->unk_0C, 0x20,
                        0x10, 0x28)
                    : func_08011F78(0xDA, act->unk_04 + 0x2000, act->unk_08, act->unk_0C, 0x20,
                        0x10, 0x28)) {
                m4aSongNumStart(0x243);
            }
            break;
        }

        if (AnimIsFinished(&work->unk_010)) {
            func_0800CB4C(work);
        }
        break;
    case 0x13:
        func_08019068(gUnk_0813E464, &w->unk_010, 1, 0, w->unk_000);

        if (func_08005B34(&work->unk_010) == 7 && work->unk_01A == 0) {
            if (act->unk_34 & 4) {
                func_08012E44(1, act->unk_04 - 0x4000, act->unk_08, act->unk_0C - 0x400,
                    act->unk_04 - 0xB400, act->unk_08, act->unk_0C - 0x400, 1, 0xDB);
            } else {
                func_08012E44(1, act->unk_04 + 0x4000, act->unk_08, act->unk_0C - 0x400,
                    act->unk_04 + 0xB400, act->unk_08, act->unk_0C - 0x400, 0, 0xDB);
            }
        }

        if (AnimIsFinished(&work->unk_010)) {
            func_0800CB4C(work);
        }
        break;
    }

    ret = _0800CDF0(work);

    if ((gUnk_02039B84->unk_07C->unk_004 < work->unk_03C.unk_04 && (work->unk_03C.unk_34 & 4)) ||
            (gUnk_02039B84->unk_07C->unk_004 > work->unk_03C.unk_04 &&
                !(work->unk_03C.unk_34 & 4))) {
        work->unk_03C.unk_34 |= 0x0C008000;
    } else {
        work->unk_03C.unk_34 &= ~0x0C008000;
    }

    return ret;
}

void task_emy_44_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_44_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_81_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813E53C, obj);
}

INCLUDE_ASM("emy/task_emy_81_1.s");

void task_emy_81_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_81_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_82_0(Emy82Work* work, void* obj) {
    func_0800C778(&work->base, gUnk_0813E604, obj);
    work->base.unk_150 = 0x15;
    work->unk_184 = 0;
}

#ifdef NON_MATCHING
u8 func_0803DD44(EmyWork* work) {
    EmyActor* act;
    s32 x;
    s32 y;
    s32 d;
    s32 t;
    s32 lo;

    act = &work->unk_03C;
    func_0801C700(act, &x, &y, 0);

    if (x < (gUnk_02039B84->unk_0DA + 0x30) << 8) {
        d = x + 0x28;
    } else if (x > (gUnk_02039B84->unk_0DC - 0x30) << 8) {
        d = x - 0x28;
    } else {
        t = (work->unk_03C.unk_CE + ((lo = -work->unk_03C.unk_D0) +
            GetRandom() % (work->unk_03C.unk_D0 - lo + 1))) << 8;

        if (act->unk_04 < x) {
            d = x - t;
        } else {
            d = x + t;
        }
    }

    return GetAngle(act->unk_04, act->unk_08, d, y);
}

#else
INCLUDE_ASM("emy/func_0803DD44.s");
#endif

INCLUDE_ASM("emy/task_emy_82_1.s");

void task_emy_82_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_82_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_83_0(Emy83Work* work, void* obj) {
    func_0800C778(&work->base, gUnk_0813E6AC, obj);
    work->unk_184 = 0;
    work->base.unk_150 = 0x16;
    TaskPoolInit(&work->unk_188, 4);
}

u8 task_emy_83_1(Emy83Work* work) {
    Emy83Work* w;
    EmyActor* act;
    u16 r;
    u16 c;
    EmySpawn spawn;
    s32 pos;
    s32 x;
    s32 y;
    s32 z;
    u8 ret;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->base.unk_14C = 0x12;
            w->unk_184 = 0;
            break;
        case 1:
            work->base.unk_14C = 0x13;
            w->unk_1A4 = 0;
            break;
        }
    }

    switch (work->base.unk_14C) {
    case 0x16:
        func_08019068(w->base.unk_15C->unk_04, &w->base.unk_010, 0, 3, w->base.unk_000);
        func_0801BCF8(act);
        func_0801C700(act, &pos, 0, 0);

        if (act->unk_04 < pos) {
            act->unk_34 &= ~4;
        } else {
            act->unk_34 |= 4;
        }
        break;
    case 0x12:
        func_08019068(gUnk_0813E66C, &w->base.unk_010, 0, 0, w->base.unk_000);
        c = work->base.unk_01A;

        if (c == 0) {
            switch (func_08005B34(&work->base.unk_010)) {
            case 3:
                func_0801C700(act, &w->unk_19C, &w->unk_1A0, 0);
                break;
            case 5:
                spawn.unk_00 = w->unk_19C;
                spawn.unk_04 = w->unk_1A0;
                spawn.unk_08 = c;
                w->unk_184 = TaskCreate(&w->unk_188, &gTaskDescEmy83B, &spawn);
                break;
            }
        }

        if (AnimIsFinished(&work->base.unk_010) && !func_08000F60(w->unk_184, gTaskDescEmy83B)) {
            func_0800CB4C(&work->base);
        }
        break;
    case 0x13:
        func_08019068(gUnk_0813E66C, &w->base.unk_010, 1, 0, w->base.unk_000);

        if (AnimIsFinished(&work->base.unk_010)) {
            work->base.unk_14C = 0x14;
        }
        break;
    case 0x14:
        func_08019068(gUnk_0813E66C, &w->base.unk_010, 2, 1, w->base.unk_000);

        if (func_08005B38(&work->base.unk_010) == 6 && work->base.unk_01A == 0) {
            if (act->unk_34 & 4) {
                spawn.unk_00 = act->unk_04 - 0x1000;
                spawn.unk_12 = 1;
            } else {
                spawn.unk_00 = act->unk_04 + 0x1000;
                spawn.unk_12 = 0;
            }

            spawn.unk_04 = act->unk_08;
            spawn.unk_08 = act->unk_0C - 0x1200;
            spawn.unk_14 = 0;
            TaskCreate(&w->unk_188, &gTaskDescEmy83S, &spawn);
            spawn.unk_14 = 1;
            TaskCreate(&w->unk_188, &gTaskDescEmy83S, &spawn);
            spawn.unk_14 = 2;
            TaskCreate(&w->unk_188, &gTaskDescEmy83S, &spawn);
            w->unk_1A4++;
        }

        if (w->unk_1A4 > 2 && AnimIsFinished(&work->base.unk_010)) {
            work->base.unk_14C = 0x15;
            work->base.unk_154 = 0;
        } else {
            work->base.unk_154++;
        }
        break;
    case 0x15:
        func_08019068(gUnk_0813E66C, &w->base.unk_010, 3, 0, w->base.unk_000);

        if (work->base.unk_154 > 0x28) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    }

    TaskPoolUpdate(&w->unk_188);
    x = act->unk_04;
    y = act->unk_08;
    z = act->unk_0C;
    ret = _0800CDF0(&work->base);

    if (work->base.unk_14C != 0x0B) {
        act->unk_04 = x;
        act->unk_08 = y;
        act->unk_0C = z;
    }

    return ret;
}

void task_emy_83_2(Emy83Work* work) {
    func_0800DF30(&work->base);
    TaskPoolDraw(&work->unk_188);
}

void task_emy_83_3(Emy83Work* work) {
    TaskPoolDestroy(&work->unk_188);
    func_0800E0D0(&work->base);
}

void task_emy_83_b_0(Emy83bWork* work, EmySpawn* spawn) {
    work->unk_02C = 0;
    work->unk_004 = LoadObjPalette(gUnk_08F69B84, 0x20);
    work->unk_000 = AllocObjTiles(0x80, gUnk_08B1B854);
    AnimInit(work->unk_008, gUnk_09EE10A4, gUnk_09EE1090);
    AnimStart(work->unk_008, 0, 0);
    work->unk_020 = spawn->unk_00;
    work->unk_024 = spawn->unk_04;
    work->unk_028 = spawn->unk_08;
    work->unk_030 = 0;
    func_080122AC(&work->unk_034, 0x0C, 4, 0x10);
}

u8 task_emy_83_b_1(Emy83bWork* work) {
    if ((gUnk_02039B84->unk_068 & 0x40) == 0) {
        return 0;
    }

    switch (work->unk_02C) {
    case 0:
        if (work->unk_030 > 0x0F) {
            work->unk_02C = 1;
            work->unk_030 = 0;
        } else {
            work->unk_030++;
        }
        break;
    case 1:
        if (work->unk_030 == 0) {
            AnimStart(work->unk_008, 1, 0);
        }

        if (func_08005B34(work->unk_008) == 1 && work->unk_012 == 0) {
            if (func_08011F78(0xE0, work->unk_020, work->unk_024, work->unk_028, 4, 4, 0x10)) {
                m4aSongNumStart(0x242);
            }
        }

        if (work->unk_030 > 0x1D) {
            work->unk_02C = 2;
            work->unk_030 = 0;
        } else {
            work->unk_030++;
        }
        break;
    case 2:
    default:
        if (work->unk_030 == 0) {
            AnimStart(work->unk_008, 2, 0);
        }

        if (AnimIsFinished(work->unk_008)) {
            return 0;
        }

        work->unk_030++;
        break;
    }

    func_08012324(&work->unk_034, work->unk_020, work->unk_024, work->unk_028);
    AnimUpdate(work->unk_008);
    return 1;
}

void task_emy_83_b_2(Emy83bWork* work) {
    void* gfx;
    u16 pri;
    s16 x;
    s16 y;

    gfx = AnimGetGfx(work->unk_008);
    pri = func_0801AF1C(work->unk_024);
    WorldToScreen(&x, &y, work->unk_020, work->unk_024, work->unk_028);
    DrawSprite(x, y, gfx, work->unk_000, work->unk_004, 0, pri,
        -0x1004 - ((work->unk_024 + 0x400) >> 8) * 4);
}

void task_emy_83_b_3(Emy83bWork* work) {
    func_08012304(&work->unk_034);
    ReleaseObjTiles(work->unk_000);
    ReleaseObjPalette(work->unk_004);
}

void task_emy_83_s_0(Emy83sWork* work, EmySpawn* spawn) {
    work->unk_004 = LoadObjPalette(gUnk_08F69B84, 0x20);
    work->unk_000 = LoadObjTiles(gUnk_08B1D846, 0x40);
    work->unk_008 = spawn->unk_00;
    work->unk_00C = spawn->unk_04;
    work->unk_010 = spawn->unk_08;
    work->unk_014 = 0;
    work->unk_022 = 0;

    if (spawn->unk_12 != 0) {
        work->unk_018 = -(GetRandom() % 0x4CE + 0x133);
    } else {
        work->unk_018 = GetRandom() % 0x4CE + 0x133;
    }

    work->unk_01C = GetRandom() % 0x201 - 0x100;
    work->unk_020 = spawn->unk_14;
}

u8 task_emy_83_s_1(Emy83sWork* work) {
    s32 x;
    s32 y;

    if (gUnk_02039B84->unk_068 & 0x40) {
        x = work->unk_008 + work->unk_018;
        work->unk_008 = x;
        y = work->unk_00C + work->unk_01C;
        work->unk_00C = y;

        if (work->unk_022 % 3 == work->unk_020) {
            if (func_08011F78(0xE1, x, y, work->unk_010, 2, 2, 2) != 0) {
                m4aSongNumStart(0x241);
            }
        }

        work->unk_010 += work->unk_014;
        work->unk_014 += 0x14;

        if (work->unk_010 < 0) {
            work->unk_022++;
            return 1;
        }
    }

    return 0;
}

void task_emy_83_s_2(Emy83sWork* work) {
    u16 pri;
    s16 x;
    s16 y;

    pri = func_0801AF1C(work->unk_00C);
    WorldToScreen(&x, &y, work->unk_008, work->unk_00C, work->unk_010);
    DrawSprite(x, y, gUnk_08B1D828, work->unk_000, work->unk_004, 0, pri,
        -0x1004 - ((work->unk_00C + 0x400) >> 8) * 4);
    WorldToScreen(&x, &y, work->unk_008, work->unk_00C, 0);
    DrawSprite(x, y, gUnk_08B1D832, work->unk_000, work->unk_004, 0, pri, -2);
}

void task_emy_83_s_3(Emy83sWork* work) {
    ReleaseObjTiles(work->unk_000);
    ReleaseObjPalette(work->unk_004);
}

void task_emy_trump_h_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813E744, obj);
}

u8 task_emy_trump_h_1(EmyWork* work) {
    EmyActor* act;

    act = &work->unk_03C;

    if (_0800CBDC(work)) {
        work->unk_14C = 0x13;
    }

    if (work->unk_14C == 3) {
        work->unk_14C = 0x12;
    }

    switch (work->unk_14C) {
    case 0x13:
        func_08019068(gUnk_0813E734, &work->unk_010, 0, 0, work->unk_000);
        func_0800C980(work, 0x19, 8, 0x0A, 0x12B, 0x30, 0x22E, 0x50, 0, 0x18);
        break;
    case 0x12:
        if (work->unk_154 == 0) {
            func_08019068(work->unk_15C->unk_04, &work->unk_010, 0, 0, work->unk_000);
            m4aSongNumStart(0x23B);
        }

        work->unk_17C = gSineTable[(u8)work->unk_154 + 0x40];
        work->unk_154 += 8;

        if (work->unk_154 > 0x13F) {
            func_0801B994(act);
            return 0;
        }

        work->unk_154++;
        break;
    }

    return _0800CDF0(work);
}

void task_emy_trump_h_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_trump_h_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_trump_s_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813E7C4, obj);
}

u8 task_emy_trump_s_1(EmyWork* work) {
    EmyActor* act;

    act = &work->unk_03C;

    if (_0800CBDC(work)) {
        work->unk_14C = 0x13;
    }

    if (work->unk_14C == 3) {
        work->unk_14C = 0x12;
    }

    switch (work->unk_14C) {
    case 0x13:
        func_08019068(gUnk_0813E7B4, &work->unk_010, 0, 0, work->unk_000);
        func_0800C980(work, 0x14, 0x1E, 0x0A, 0x12A, 0x46, 0x22F, 0x10, 0, 0x18);

        if (work->unk_154 == 0x14) {
            work->unk_168 = -0x480;
        }
        break;
    case 0x12:
        if (work->unk_154 == 0) {
            func_08019068(work->unk_15C->unk_04, &work->unk_010, 0, 0, work->unk_000);
            m4aSongNumStart(0x23B);
        }

        work->unk_17C = gSineTable[(u8)work->unk_154 + 0x40];
        work->unk_154 += 8;

        if (work->unk_154 > 0x13F) {
            func_0801B994(act);
            return 0;
        }

        work->unk_154++;
        break;
    }

    return _0800CDF0(work);
}

void task_emy_trump_s_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_trump_s_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_test_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813E834, obj);
    work->unk_03C.unk_2E = 0xBB8;
    work->unk_03C.unk_2C = 0xBB8;
    work->unk_03C.unk_34 |= 0x1000;
}

u8 task_emy_test_1(EmyWork* work) {
    _0800CBDC(work);
    return _0800CDF0(work);
}

void task_emy_test_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_test_3(EmyWork* work) {
    func_0800E0D0(work);
}

ALIGN_ZERO(2);
