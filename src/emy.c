#include "display.h"
#include "macros.h"
#include "emy.h"

void task_emy_00_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813D3CC, obj);
    work->unk_158 |= 1;
    work->unk_150 = 0x12;
    work->unk_14C = 0x16;
}

u8 task_emy_00_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    u16 r;
    s32 pos;
    s32 pos2;
    u8 ret;

    w = work;
    act = &work->unk_03C;

    if (_0800CBDC(work)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->unk_14C = 24;
            break;
        case 1:
            work->unk_14C = 25;
            break;
        }
    }

    switch (w->unk_14C) {
    case 24:
        func_08019068(gUnk_0813D35C, &work->anim, 5, 0, work->tiles);
        func_0800C980(w, 31, 18, 11, 165, 40, 0x211, 0, 0, 24);
        break;
    case 25:
        func_08019068(gUnk_0813D35C, &work->anim, 6, 0, work->tiles);

        if (w->unk_154 == 10) {
            w->unk_168 = -0x400;
        }

        func_0800C980(w, 14, 35, 10, 166, 96, 0x211, 0, 0, 24);
        break;
    case 19:
        func_08019068(gUnk_0813D35C, &work->anim, 0, 0, work->tiles);

        if (AnimIsFinished(&w->anim)) {
            w->unk_14C = 20;
            ColliderSetDisabled(&act->unk_040, 1);
            act->unk_034 |= 0x100;
            act->unk_0A2 = 0;
        }
        break;
    case 20:
        if (gBtlWork->unk_068 & 0x40000) {
            func_0801C700(act, &pos, 0, 0);
            func_08019068(gUnk_0813D35C, &work->anim, 1, 1, work->tiles);
            act->unk_004 += gSineTable[w->angle] * w->unk_164 >> 8;
            act->unk_008 += -gSineTable[w->angle + 64] * w->unk_164 >> 8;

            if (w->unk_154 > 100) {
                w->unk_14C = 21;
                ColliderSetDisabled(&act->unk_040, 0);
                act->unk_034 &= ~0x100;
                act->unk_0A2 = 16;
                w->unk_154 = 0;
            } else {
                w->unk_154++;
            }

            if (act->unk_004 > pos) {
                act->unk_034 |= 4;
            } else {
                act->unk_034 &= ~4;
            }
        }
        break;
    case 22:
        func_08019068(gUnk_0813D35C, &work->anim, 3, 0, work->tiles);

        if (w->unk_154 == 20) {
            act->unk_034 &= ~0x100;

            if (gGameState.flags & 4) {
                func_0800CD40(w);
                break;
            }
        }

        if (AnimIsFinished(&w->anim)) {
            func_0800CD40(w);
            break;
        }

        w->unk_154++;
        break;
    case 21:
        func_08019068(gUnk_0813D35C, &work->anim, 2, 0, work->tiles);

        if (w->unk_154 == 30) {
            act->unk_034 &= ~0x100;
        }

        if (AnimIsFinished(&w->anim)) {
            act->unk_034 &= ~0x300;
            w->unk_14C = 18;

#ifdef VERSION_EU
            w->unk_154 = 0;
#endif
        } else {
            w->unk_154++;
        }
        break;
    case 18:
        if (w->unk_154 == 0) {
            ColliderSetDisabled(&act->unk_040, 0);
            act->unk_034 &= ~0x300;
            func_08019068(work->unk_15C->unk_04, &work->anim, 0, 3,
                work->tiles);
        }

        func_0801BCF8(act);

        if (GetRandom() % 120 == 0) {
            w->unk_14C = 4;

            if (GetRandom() % 2 == 0) {
                w->unk_170 = -((act->unk_0CE
                    + (-act->unk_0D0
                        + GetRandom() % (act->unk_0D0 - -act->unk_0D0 + 1)))
                    << 8);
            } else {
                w->unk_170 = (act->unk_0CE
                    + (-act->unk_0D0
                        + GetRandom() % (act->unk_0D0 - -act->unk_0D0 + 1)))
                    << 8;
            }
        } else if (GetRandom() % 200 == 0) {
            w->unk_14C = 19;
            act->unk_034 |= 0x200;
            w->angle = GetRandom();
            w->unk_154 = 0;
            break;
        }

        if (GetRandom() % w->unk_15C->unk_0E == 0) {
            func_0801C700(act, &pos2, 0, 0);

            if (act->unk_004 > pos2) {
                act->unk_034 |= 4;
            } else {
                act->unk_034 &= ~4;
            }
        }

        w->unk_154++;
        break;
    }

    ret = _0800CDF0(w);

    if (w->unk_14C == 14) {
        func_08019068(gUnk_0813D35C, &work->anim, 4, 1, work->tiles);
    }

    return ret;
}

void task_emy_00_2(EmyWork* work) {
    BtlObj* act;
    u16 pri;
    s32 affine;
    s32 rot;
    s32 scale;
    s32 zoom;
    s16 x;
    s16 y;

    if (work->unk_15A != 0) {
        act = &work->unk_03C;
        pri = GetBattleSpritePriorityFlags(act->unk_008) | work->unk_162;
        WorldToScreen(&x, &y, act->unk_004, act->unk_008, act->unk_00C);
        zoom = work->unk_180;

        if (zoom == 0x100) {
            if (act->unk_034 & 4) {
                scale = gBtlWork->unk_024;
                rot = scale;
            } else if (gBtlWork->unk_024 == zoom) {
                scale = zoom;
                rot = scale;
                pri |= 1;
            } else {
                rot = -gBtlWork->unk_024;
                scale = gBtlWork->unk_024;
            }
        } else {
            if (act->unk_034 & 4) {
                rot = gBtlWork->unk_024 * work->unk_17C >> 8;
                scale = gBtlWork->unk_024;
            } else {
                rot = -(gBtlWork->unk_024 * work->unk_17C >> 8);
                scale = gBtlWork->unk_024;
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
            DrawSprite(x, y, work->gfx, work->tiles, work->unk_008, affine, pri,
                -0x1004 - (act->unk_008 >> 8) * 4);
        } else if (work->unk_14C == 0x14) {
            DrawSprite(x, y, work->gfx, work->tiles, work->unk_004, affine, pri, 0xFFFF);
        } else {
            DrawSprite(x, y, work->gfx, work->tiles, work->unk_004, affine, pri,
                -0x1004 - (act->unk_008 >> 8) * 4);
        }

        TaskPoolDraw(&work->unk_028);
    }
}

void task_emy_00_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_01_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813D454, obj);
    work->unk_150 = 7;
}

u8 task_emy_01_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    u16 r;
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
    case 0x12: {
        s32 z;
        func_08019068(gUnk_0813D434, &w->anim, 0, 0, w->tiles);
        work->unk_168 = 0;

        if (work->unk_154 != 0) {
            if (work->unk_154 == 0x16) {
                z = act->unk_008;

                if (act->unk_034 & 4) {
                    x = act->unk_004 - 0x6400;
                    func_08012E44(0, act->unk_004 - 0x2600, z, act->unk_00C - 0xC00, x, z, 0, 1,
                        0xA7);
                } else {
                    x = act->unk_004 + 0x6400;
                    func_08012E44(0, act->unk_004 + 0x2600, z, act->unk_00C - 0xC00, x, z, 0, 0,
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
    }
    case 0x13: {
        s32 z;
        func_08019068(gUnk_0813D434, &w->anim, 1, 0, w->tiles);
        work->unk_168 = 0;

        if (work->unk_154 != 0) {
            if (work->unk_154 == 0x16) {
                z = act->unk_008;

                if (act->unk_034 & 4) {
                    x = act->unk_004 - 0x6400;
                    func_08012E44(1, act->unk_004 - 0x2600, z, act->unk_00C - 0xC00, x, z, 0, 1,
                        0xA8);
                } else {
                    x = act->unk_004 + 0x6400;
                    func_08012E44(1, act->unk_004 + 0x2600, z, act->unk_00C - 0xC00, x, z, 0, 0,
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
    }

    return _0800CDF0(work);
}

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

u8 task_emy_02_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    u16 r;
    s32 p;

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
    case 0x12: {
        s32 y;

        func_08019068(gUnk_0813D4BC, &w->anim, 0, 0, w->tiles);
        work->unk_168 = 0;

        if (work->unk_154 == 0) {
        } else if (work->unk_154 == 22) {
            y = act->unk_008;

            if (act->unk_034 & 4) {
                p = act->unk_004 - 0x3C00;
                func_08013308(0, act->unk_004 - 0x2800, y, act->unk_00C - 0x800, p, y, 0, 1,
                    0xA9);
            } else {
                p = act->unk_004 + 0x3C00;
                func_08013308(0, act->unk_004 + 0x2800, y, act->unk_00C - 0x800, p, y, 0, 0,
                    0xA9);
            }
        }

        if (work->unk_154 > 21 && !func_080128EC()) {
            func_0800CB4C(work);
        } else {
            work->unk_154++;
        }
        break;
    }
    case 0x13: {
        s32 y;

        func_08019068(gUnk_0813D4BC, &w->anim, 1, 0, w->tiles);
        work->unk_168 = 0;

        if (work->unk_154 == 0) {
        } else if (work->unk_154 == 3) {
            y = act->unk_008;

            if (act->unk_034 & 4) {
                p = act->unk_004 - 0x3C00;
                func_08013308(1, act->unk_004 - 0x2800, y, act->unk_00C - 0x800, p, y, 0, 1,
                    0xAA);
            } else {
                p = act->unk_004 + 0x3C00;
                func_08013308(1, act->unk_004 + 0x2800, y, act->unk_00C - 0x800, p, y, 0, 0,
                    0xAA);
            }
        }

        if (work->unk_154 > 2 && !func_080128EC()) {
            func_0800CB4C(work);
        } else {
            work->unk_154++;
        }
        break;
    }
    }

    return _0800CDF0(work);
}

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
    BtlObj* act;
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
            func_08019068(gUnk_0813D544, &w->base.anim, 0, 0, w->base.tiles);
        } else if (work->base.unk_154 == 1) {
            func_080141FC(act);
            m4aSongNumStart(0x246);
        }

        if (func_0800C980(&work->base, 0x11, 0x17, 0x0A, 0xAB, 0x50, 0x247, 0, 0, 0x0A) == 2) {
            BgAnimStop();
        }
        break;
    case 0x13:
        if (work->base.unk_154 == 0) {
            func_08019068(gUnk_0813D544, &w->base.anim, 1, 0, w->base.tiles);
        } else if (work->base.unk_154 == 1) {
            func_0801C700(act, &w->unk_184, &w->unk_188, 0);
            w->unk_18C = 0;
            func_08015834(0, act->unk_004, act->unk_008, act->unk_00C - 0x1000, w->unk_184,
                w->unk_188, 0, 0xAC);
        }

        work->base.unk_168 = 0;

        if (AnimIsFinished(&work->base.anim) && !func_080128EC()) {
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
    BtlObj* act;
    BtlObj* p;
    BtlObj* best;
    s16 bestv;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        work->base.unk_14C = 0x12;
    }

    switch (work->base.unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813D5CC, &work->base.anim, 0, 0, work->base.tiles);
        work->base.unk_168 = 0;

        if (work->unk_186 > 2) {
            func_08019190(act, 2);
            func_0800CB4C(&work->base);
            break;
        }

        if (work->base.unk_154 == 3) {
            best = 0;
            bestv = 0;

            for (p = ListPoolFirst(&gBtlWork->unk_080); p != 0;
                    p = ListPoolNext(&p->unk_0B8)) {
                if (!(p->unk_034 & 0x100)) {
                    if (bestv < p->unk_02E - p->unk_02C) {
                        bestv = p->unk_02E - p->unk_02C;
                        best = p;
                    }
                }
            }

            if (best == 0) {
                best = act;
            }

            if (best->unk_02C == best->unk_02E) {
                func_08019190(act, 2);
                func_0800CB4C(&work->base);
                break;
            }

            best->unk_034 |= 0x20;
            best->unk_020 = -0x1E;
            func_08012AAC(0, best->unk_004, best->unk_008, best->unk_00C);
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
    BtlObj* act;
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
        d = act->unk_008 - pos;

        if (d >= 0 ? d <= 0xFFF : pos - act->unk_008 <= 0xFFF) {
            work->base.unk_14C = 0x13;
        } else {
            work->base.unk_14C = 0x12;
        }

        w->unk_184 = 0;
    }

    switch (work->base.unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813D644, &w->base.anim, 0, 0, w->base.tiles);
        work->base.unk_168 = 0;
        p = &gBtlWork->unk_138;
        t = act->unk_00C + 0xC00;
        act->unk_00C += (*p - t) >> 4;
        s = AnimGetFrame(&work->base.anim);

        if (s >= 5 && s <= 20) {
            m = work->base.unk_154;
            m &= 3;

            if (m == 0) {
                func_0801C700(act, &tx, &ty, 0);
                work->base.angle = GetAngle(act->unk_004, act->unk_008, tx, ty);
            }

            act->unk_004 += gSineTable[work->base.angle] * 2;
            act->unk_008 -= gSineTable[work->base.angle + 0x40] * 2;

            if (func_08011F78(0xAF, act->unk_004, act->unk_008, act->unk_00C - 0x800, 0x14, 0x14,
                    8)) {
                m4aSongNumStart(0x249);
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    case 0x13:
        func_08019068(gUnk_0813D644, &w->base.anim, 1, 0, w->base.tiles);
        work->base.unk_168 = 0;
        p = &gBtlWork->unk_138;
        t = act->unk_00C + 0xC00;
        act->unk_00C += (*p - t) >> 4;
        s = AnimGetFrame(&work->base.anim);

        if (s >= 6 && s <= 16) {
            if (act->unk_034 & 4) {
                v = act->unk_004;
                v += 0x7800;
            } else {
                v = act->unk_004;
                v -= 0x7800;
            }

            e = (act->unk_014 - v) >> 3;
            w->unk_184 += 0x33;

            if (e > w->unk_184) {
                e = w->unk_184;
            } else if (e < -w->unk_184) {
                e = -w->unk_184;
            }

            act->unk_004 += e;

            if (func_08011F78(0xB0, act->unk_004, act->unk_008, act->unk_00C - 0x800, 0x10, 0x10,
                    8)) {
                m4aSongNumStart(0x211);
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
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
    work->base.unk_03C.unk_034 |= 0x1000;
    work->unk_187 = 0;
}

u8 task_emy_07_1(Emy07Work* work) {
    Emy07Work* w;
    BtlObj* act;
    EmySpawn spawn;
    u32 state;
    s32 pos;
    s32 pos2;

    w = work;
    act = &work->base.unk_03C;
    state = work->base.unk_14C;

#ifdef VERSION_EU
    act->unk_02C = 0x7FFF;
#endif

    _0800CBDC(&work->base);

#ifdef VERSION_EU
    act->unk_02C = act->unk_02E;
#endif


    switch (work->base.unk_14C) {
    case 1:
    case 3:
    case 15:
        work->base.unk_14C = 26;

        switch (state) {
        case 21:
            w->unk_186 = 0;

            if (act->unk_024 & 0x10000000) {
                func_0801AF08(act);
                work->base.unk_14C = 20;
                work->base.unk_154 = 0;
            }
            break;
        case 22:
            w->unk_186 = 0;

            if (act->unk_024 & 0x20000000) {
                func_0801AF08(act);
                work->base.unk_14C = 20;
                work->base.unk_154 = 0;
            }
            break;
        case 23:
            w->unk_186 = 1;

            if (act->unk_024 & 0x40000000) {
                func_0801AF08(act);
                work->base.unk_14C = 20;
                work->base.unk_154 = 0;
            }
            break;
        }

        act->unk_02C = act->unk_02E;
        ColliderSetDisabled(&act->unk_040, 0);
        break;
    }

    switch (work->base.unk_14C) {
    case 18:
        func_08019068(w->base.unk_15C->unk_04, &w->base.anim, 0, 3,
            w->base.tiles);
        func_0801C700(act, &pos, 0, 0);

        if (act->unk_004 < pos) {
            act->unk_034 &= ~4;
        } else {
            act->unk_034 |= 4;
        }

        if (GetRandom() % 60 == 0) {
            work->base.unk_154 = 0;

            switch (GetRandom() % 3) {
            case 1:
                work->base.unk_14C = 22;
                break;
            case 2:
                work->base.unk_14C = 23;
                break;
            case 0:
            default:
                work->base.unk_14C = 21;
                break;
            }
        } else {
            work->base.unk_154++;
        }
        break;
    case 21:
        func_08019068(gUnk_0813D6CC, &w->base.anim, 3, 1, w->base.tiles);

        if (work->base.unk_154 > 300) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 18;
        } else {
            work->base.unk_154++;
        }
        break;
    case 22:
        func_08019068(gUnk_0813D6CC, &w->base.anim, 4, 1, w->base.tiles);

        if (work->base.unk_154 > 300) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 18;
        } else {
            work->base.unk_154++;
        }
        break;
    case 23:
        func_08019068(gUnk_0813D6CC, &w->base.anim, 5, 1, w->base.tiles);

        if (work->base.unk_154 > 300) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 18;
        } else {
            work->base.unk_154++;
        }
        break;
    case 20:
        if (w->unk_186 != 0) {
            func_08019068(gUnk_0813D6CC, &w->base.anim, 2, 0, w->base.tiles);
        } else {
            func_08019068(gUnk_0813D6CC, &w->base.anim, 1, 0, w->base.tiles);
        }

        if (work->base.unk_154 == 0) {
            m4aSongNumStart(0x231);
            work->base.unk_154 = 1;
            act->unk_034 |= 0x100;
        }

        if (w->unk_184 == 2 && gFrameCounter % 10 == 0) {
            spawn.unk_12 = 1;
            spawn.unk_14 = 0;
            spawn.x = act->unk_004;
            spawn.y = act->unk_008;
            spawn.z = act->unk_00C - (act->unk_09C << 8);
            TaskCreate(&gBtlWork->taskPools[0], gTaskDescBtlPrize,
                &spawn);
        }

        if (AnimIsFinished(&work->base.anim)) {
            w->unk_184++;

            if (w->unk_184 > 2) {
                work->base.unk_154 = 0;
                work->base.unk_14C = 25;
                w->unk_187 = 1;
                func_0800FDD0(110);
            } else {
                work->base.unk_154 = 0;
                work->base.unk_14C = 18;
                act->unk_034 &= ~0x100;
            }
        }
        break;
    case 26:
        if (work->base.unk_154 == 0) {
            func_08019068(w->base.unk_15C->unk_04, &w->base.anim, 1, 0,
                w->base.tiles);
        }

        func_0801C700(act, &pos2, 0, 0);

        if (act->unk_004 < pos2) {
            act->unk_034 &= ~4;
        } else {
            act->unk_034 |= 4;
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            act->unk_034 |= 0x100;
            work->base.unk_154 = 0;
            work->base.unk_14C = 19;
        } else {
            work->base.unk_154++;
        }
        break;
    case 19:
        func_08019068(gUnk_0813D6CC, &w->base.anim, 0, 0, w->base.tiles);

        if (work->base.unk_154 == 0) {
            act->unk_034 |= 0x100;
            work->base.unk_154 = 1;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 25;
        }
        break;
    case 25:
        func_08019068(gUnk_0813D6CC, &w->base.anim, 6, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            if (w->unk_187 != 0) {
                func_0801B994(act);
                func_0801BBF0(act);
            }

            return 0;
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_07_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_07_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_08_0(Emy08Work* work, void* obj) {
    func_0800C778(&work->base, gUnk_0813D804, obj);
    work->palette = LoadObjPalette(gUnk_08F698C4, 0x20);
    work->unk_188 = work->base.unk_004;
    work->unk_18C = 0;
}

u8 task_emy_08_1(Emy08Work* work) {
    Emy08Work* w;
    BtlObj* act;
    u16 r;
    s32 dx;
    s32 dy;

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
    case 0:
        if (GetRandom() % 100 == 0) {
            if (w->unk_18C & 2) {
                work->base.unk_14C = 23;
            } else {
                work->base.unk_14C = 22;
            }

            work->base.unk_154 = 0;
        }
        break;
    case 22:
        func_08019068(gUnk_0813D7A4, &w->base.anim, 4, 0, w->base.tiles);

        if (AnimGetFrame(&work->base.anim) == 6) {
            act->unk_034 |= 0x180000000;
            w->unk_18C |= 2;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = work->base.unk_150;
        }
        break;
    case 23:
        func_08019068(gUnk_0813D7A4, &w->base.anim, 5, 0, w->base.tiles);

        if (AnimGetFrame(&work->base.anim) == 4) {
            act->unk_034 &= ~0x180000000;
            w->unk_18C &= ~2;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = work->base.unk_150;
        }
        break;
    case 18:
        func_08019068(gUnk_0813D7A4, &w->base.anim, 0, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
            act->unk_034 |= 0x200;

            if (w->unk_18C & 1) {
                work->base.unk_14C = 20;
            } else {
                work->base.unk_14C = 21;
            }
        } else if (work->base.anim.timer == 0) {
            dx = 0;
            dy = 0;

            switch (work->base.anim.frame) {
            case 1:
                dx = 2;
                break;
            case 2:
                dx = 2;
                dy = 1;
                break;
            case 3:
                dx = 2;
                dy = 1;
                break;
            case 4:
                dx = 2;
                dy = 1;
                break;
            case 5:
                dx = 3;
                dy = 1;
                break;
            case 6:
                dx = 3;
                break;
            case 7:
                dx = 2;

                if ((act->unk_034 & 4)
                        ? func_08011F78(0xB1, act->unk_004 - 0x1400, act->unk_008, act->unk_00C,
                            4, 4, 0x20)
                        : func_08011F78(0xB1, act->unk_004 + 0x1400, act->unk_008, act->unk_00C,
                            4, 4, 0x20)) {
                    m4aSongNumStart(0x242);
                    w->unk_18C |= 1;
                } else {
                    w->unk_18C &= ~1;
                }
                break;
            }

            if (act->unk_034 & 4) {
                act->unk_004 -= dx << 8;
            } else {
                act->unk_004 += dx << 8;
            }

            act->unk_008 -= dy << 8;
        }
        break;
    case 20:
        func_08019068(gUnk_0813D7A4, &w->base.anim, 2, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = work->base.unk_150;
            act->unk_034 &= ~0x200;
        } else {
            work->base.unk_154++;
        }
        break;
    case 21:
        func_08019068(gUnk_0813D7A4, &w->base.anim, 3, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = work->base.unk_150;
            act->unk_034 &= ~0x200;
        } else {
            work->base.unk_154++;
        }
        break;
    case 19:
        func_08019068(gUnk_0813D7A4, &w->base.anim, 1, 0, w->base.tiles);

        if (work->base.anim.timer == 0
                && AnimGetFrame(&work->base.anim) == 7) {
            if (act->unk_034 & 4) {
                func_080150D8(act->unk_004, act->unk_008, act->unk_00C - 0xA00, 1);
            } else {
                func_080150D8(act->unk_004, act->unk_008, act->unk_00C - 0xA00, 0);
            }
        }

        if (work->base.unk_154 == 60) {
            (act->unk_034 & 4)
                ? func_08011F78(0xB2, act->unk_004, act->unk_008, act->unk_00C, 0x20, 0x20, 0x20)
                : func_08011F78(0xB2, act->unk_004, act->unk_008, act->unk_00C, 0x20, 0x20, 0x20);
        }

        if (AnimIsFinished(&work->base.anim) && !func_080128EC()) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_08_2(Emy08Work* work) {
    work->base.unk_004 = (work->unk_18C & 2) ? work->palette : work->unk_188;
    func_0800DF30(&work->base);
    work->base.unk_004 = work->unk_188;
}

void task_emy_08_3(Emy08Work* work) {
    func_0800E0D0(&work->base);
    ReleaseObjPalette(work->palette);
}

void task_emy_14_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813D88C, obj);
}

u8 task_emy_14_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    s32 pos;
    s32 d;

    w = work;
    act = &work->unk_03C;

    if (_0800CBDC(work)) {
        func_0801C700(act, &pos, 0, 0);
        d = act->unk_004 - pos;

        if (d >= 0 ? d <= 0x31FF : pos - act->unk_004 <= 0x31FF) {
            work->unk_14C = 0x12;
        } else {
            work->unk_14C = 0x13;
        }
    }

    switch (work->unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813D86C, &w->anim, 0, 0, w->tiles);
        func_0800C980(work, 0x0F, 0x0E, 0x14, 0xB3, 0x18, 0x242, 0, 0, 0x16);
        break;
    case 0x13:
        func_08019068(gUnk_0813D86C, &w->anim, 1, 0, w->tiles);
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
    BtlObj* act;
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
        func_08019068(gUnk_0813D8F4, &w->anim, 0, 0, w->tiles);

        if (AnimIsFinished(&work->anim)) {
            work->unk_14C = 0x13;
            work->unk_154 = 0x1E;
        }
        break;
    case 0x13:
        func_08019068(gUnk_0813D8F4, &w->anim, 1, 0, w->tiles);

        if (act->unk_034 & 4) {
            ApproachValueHalfSteps(&act->unk_004, act->unk_014 - 0x5000, work->unk_154);
        } else {
            ApproachValueHalfSteps(&act->unk_004, act->unk_014 + 0x5000, work->unk_154);
        }

        work->unk_154--;

        if ((act->unk_034 & 4)
                ? func_08011F78(0xB5, act->unk_004 - 0x1400, act->unk_008, act->unk_00C, 5, 5, 4)
                : func_08011F78(0xB5, act->unk_004 + 0x1400, act->unk_008, act->unk_00C, 5, 5, 4)) {
            m4aSongNumStart(0x242);
        }

        if (work->unk_154 <= 0) {
            work->unk_14C = 0x14;
            work->unk_154 = 0;
        }
        break;
    case 0x14:
        func_08019068(gUnk_0813D8F4, &w->anim, 2, 0, w->tiles);

        if (AnimIsFinished(&work->anim)) {
            func_0800CB4C(work);
        }
        break;
    case 0x15:
        if (work->unk_154 == 0) {
            func_08019068(gUnk_0813D8F4, &w->anim, 3, 0, w->tiles);
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
        func_08019068(gUnk_0813D8F4, &w->anim, 4, 0, w->tiles);
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
    BtlObj* act;
    EmySpawn spawn;
    u16 r;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        if (IsTaskActiveNamed(work->unk_188, gTaskDescEmy16B)) {
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
        func_08019068(gUnk_0813D9AC, &w->base.anim, 0, 0, w->base.tiles);

        if (AnimGetFrame(&work->base.anim) == 3 && work->base.anim.timer == 0) {
            if (act->unk_034 & 4) {
                spawn.x = act->unk_004 - 0x1000;
                spawn.y = act->unk_008;
                spawn.z = act->unk_00C - 0x1000;
                spawn.unk_12 = 1;
            } else {
                spawn.x = act->unk_004 + 0x1000;
                spawn.y = act->unk_008;
                spawn.z = act->unk_00C - 0x1000;
                spawn.unk_12 = 0;
            }

            w->unk_184 = TaskCreate(&w->unk_18C, &gTaskDescEmy16P, &spawn);
            w->unk_1A0 = 1;
        }

        if (w->unk_1A0 != 0) {
            if (!IsTaskActiveNamed(w->unk_184, gTaskDescEmy16P)) {
                func_0800CB4C(&work->base);
            }
        }
        break;
    case 0x13:
        func_08019068(gUnk_0813D9AC, &w->base.anim, 1, 0, w->base.tiles);

        if (AnimGetFrame(&work->base.anim) == 0x0A && work->base.anim.timer == 0) {
            if (act->unk_034 & 4) {
                spawn.x = act->unk_004 - 0xC00;
                spawn.y = act->unk_008;
                spawn.z = act->unk_00C - 0x200;
                spawn.unk_12 = 1;
            } else {
                spawn.x = act->unk_004 + 0xC00;
                spawn.y = act->unk_008;
                spawn.z = act->unk_00C - 0x200;
                spawn.unk_12 = 0;
            }

            w->unk_188 = TaskCreate(&w->unk_18C, &gTaskDescEmy16B, &spawn);
        }

        if (AnimIsFinished(&work->base.anim)) {
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

    work->palette = LoadObjPalette(gUnk_08F699C4, 0x20);
    work->tiles = AllocObjTiles(0x80, gUnk_08A23630);
    AnimInit(work->anim, gUnk_09EE04F4, gUnk_09EE04E0);
    AnimStart(work->anim, 0, 1);
    work->unk_038 = 0;
    work->x = spawn->x;
    work->y = spawn->y;
    work->z = spawn->z;
    work->unk_034 = 0x200;
    work->unk_030 = -0x34C;
    work->unk_03C = 0;
    work->unk_09C = 1;
    work->unk_09D = 0;
    ColliderInit(&work->unk_040, 0x0C, 4, 3);
    ColliderSetDisabled(&work->unk_040, 1);
}

u8 task_emy_16_b_1(Emy16bWork* work) {
    switch (work->unk_038) {
    case 0:
        if (work->unk_02C != 0) {
            work->x -= work->unk_034;
        } else {
            work->x += work->unk_034;
        }

        if (ClampBattlePosition(&work->x, &work->y, -0x10, 0) != 0) {
            work->unk_034 = -work->unk_034;
        }

        if (work->unk_09D == 0
                && func_08011E3C(work->x, work->y, work->z, 4, 4, 4)) {
            work->unk_034 = -(work->unk_034 >> 1);
            work->unk_09D = 1;
        }

        if (work->z >= 0) {
            work->unk_038 = 1;
            work->unk_03C = 0;
        }
        break;
    case 1:
        if (work->unk_03C == 0) {
            ColliderSetDisabled(&work->unk_040, 0);
            AnimStart(work->anim, 1, 1);
        }

        if (work->unk_06C != 0) {
            work->unk_03C = 0;
            work->unk_038 = 2;
            ColliderSetDisabled(&work->unk_040, 1);
        } else if (work->unk_03C > 0x64) {
            work->unk_03C = 0;
            work->unk_038 = 3;
        } else {
            work->unk_03C++;
        }
        break;
    case 2:
        if (work->unk_03C != 0) {
            if (work->z >= 0) {
                work->unk_03C = 0;
                work->unk_038 = 3;
                break;
            }
        } else {
            AnimStart(work->anim, 2, 1);
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
            ColliderSetDisabled(&work->unk_040, 1);
            work->unk_09C = 1;
        } else if (work->unk_03C > 0x3C) {
            return 0;
        } else {
            work->unk_03C++;
        }
        break;
    }

    work->z += work->unk_030;
    work->unk_030 += 0x33;

    if (work->z >= 0) {
        work->unk_030 = 0;
        work->z = 0;
    }

    ColliderSetPosition(&work->unk_040, work->x, work->y, work->z);
    AnimUpdate(work->anim);
    return 1;
}

void task_emy_16_b_2(Emy16bWork* work) {
    void* gfx;
    u16 pri;
    s32 affine;
    s32 angle;
    s16 x;
    s16 y;

    gfx = AnimGetGfx(work->anim);

    if (work->unk_09C != 0) {
        pri = GetBattleSpritePriorityFlags(work->y);
        WorldToScreen(&x, &y, work->x, work->y, work->z);
        angle = gBtlWork->unk_024;

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

        DrawSprite(x, y, gfx, work->tiles, work->palette, affine, pri,
            -0x1004 - (work->y >> 8) * 4);
    }
}

void task_emy_16_b_3(Emy16bWork* work) {
    ColliderUnregister(&work->unk_040);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_emy_16_p_0(Emy16pWork* work, EmySpawn* spawn) {
    if (spawn->unk_12 != 0) {
        work->unk_02C = 1;
    } else {
        work->unk_02C = 0;
    }

    work->palette = LoadObjPalette(gUnk_08F699C4, 0x20);
    work->tiles = AllocObjTiles(0x80, gUnk_08A20BCE);
    AnimInit(work->anim, gUnk_09EE04B4, gUnk_09EE04AC);
    AnimStart(work->anim, 0, 1);
    work->x = spawn->x;
    work->y = spawn->y;
    work->z = spawn->z;
    work->unk_030 = 0;
}

u8 task_emy_16_p_1(Emy16pWork* work) {
    if ((gBtlWork->unk_068 & 0x40) == 0) {
        return 0;
    }

    if (work->unk_02C != 0) {
        work->x -= 0x400;
    } else {
        work->x += 0x400;
    }

    if (func_08011F78(0xB7, work->x, work->y, work->z, 4, 4, 4) != 0) {
        m4aSongNumStart(0x264);
    }

    if (ClampBattlePosition(&work->x, &work->y, 0x10, 0) != 0) {
        return 0;
    }

    work->z += work->unk_030;
    work->unk_030 += 0x2E;

    if (work->z >= 0) {
        work->unk_030 = -0x400;
        work->z = 0;
    }

    AnimUpdate(work->anim);
    return 1;
}

void task_emy_16_p_2(Emy16pWork* work) {
    void* gfx;
    u16 pri;
    s16 x;
    s16 y;

    gfx = AnimGetGfx(work->anim);
    pri = GetBattleSpritePriorityFlags(work->y);
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, 0, pri,
        -0x1004 - ((work->y + 0x1000) >> 8) * 4);
}

void task_emy_16_p_3(Emy16pWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_emy_18_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813DA94, obj);
    work->unk_03C.unk_00C = (GetRandom() % 0x1001) - 0x3000;
    work->unk_150 = 7;
}

u8 task_emy_18_1(Emy18Work* work) {
    Emy18Work* w;
    BtlObj* act;
    u16 r;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->base.unk_14C = 18;
            break;
        case 1:
            work->base.unk_14C = 19;
            break;
        }

        w->unk_184 = 0xEFFF;
    }

    if (work->base.unk_14C == 8) {
        work->base.unk_14C = 20;
        work->base.unk_154 = 0;
    }

    switch (work->base.unk_14C) {
    case 20:
        func_08019068(gUnk_0813DA54, &w->base.anim, 2, 0, w->base.tiles);
        work->base.unk_168 = 0;

        if (AnimGetFrame(&work->base.anim) == 5) {
            work->base.angle = GetAngle(act->unk_004, act->unk_008, work->base.unk_170,
                work->base.unk_174);
            work->base.unk_164 = work->base.unk_15C->unk_08;
            act->unk_004 += gSineTable[work->base.angle] * work->base.unk_164 >> 8;
            act->unk_008 += -gSineTable[work->base.angle + 64] * work->base.unk_164
                >> 8;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 22;
        }
        break;
    case 22:
        work->base.unk_168 = 0;
        func_08019068(w->base.unk_15C->unk_04, &w->base.anim, 2, 3,
            w->base.tiles);

        if (gBtlWork->unk_068 & 0x40000) {
            if (act->unk_004 > work->base.unk_170) {
                act->unk_034 |= 4;
            } else {
                act->unk_034 &= ~4;
            }

            work->base.angle = GetAngle(act->unk_004, act->unk_008, work->base.unk_170,
                work->base.unk_174);
            work->base.unk_164 = work->base.unk_15C->unk_08;
            act->unk_004 += gSineTable[work->base.angle] * work->base.unk_164 >> 8;
            act->unk_008 += -gSineTable[work->base.angle + 64] * work->base.unk_164
                >> 8;
            act->unk_00C += (work->base.unk_178 - act->unk_00C) >> 3;

            if ((work->base.unk_158 & 2) ||
                    ((act->unk_004 - work->base.unk_170 >= 0
                    ? act->unk_004 - work->base.unk_170 <= 0xFFF
                    : work->base.unk_170 - act->unk_004 <= 0xFFF) &&
                    (act->unk_008 - work->base.unk_174 >= 0
                        ? act->unk_008 - work->base.unk_174 <= 0xFFF
                        : work->base.unk_174 - act->unk_008 <= 0xFFF))) {
                work->base.unk_14C = 21;
                work->base.unk_154 = 0;
                break;
            }

            work->base.unk_154++;
        }
        break;
    case 21:
        func_08019068(gUnk_0813DA54, &w->base.anim, 3, 0, w->base.tiles);
        work->base.unk_168 = 0;
        act->unk_004 += gSineTable[work->base.angle] * work->base.unk_164 >> 8;
        act->unk_008 += -gSineTable[work->base.angle + 64] * work->base.unk_164 >> 8;
        work->base.unk_164 -= 25;

        if (work->base.unk_164 < 0) {
            work->base.unk_164 = 0;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 7;
        }
        break;
    case 18:
        func_08019068(gUnk_0813DA54, &w->base.anim, 0, 0, w->base.tiles);

        if (work->base.unk_154 <= 29) {
            work->base.unk_168 = 0;
            act->unk_00C += (-0x3500 - act->unk_00C) >> 3;
        } else if (work->base.unk_154 == 30) {
            work->base.unk_168 = 0x300;
        }

        if (func_0800C980(&work->base, 30, 10, 6, 185, 32, 0x221, 24, -10, 16)
                == 1) {
            w->unk_184 = work->base.unk_154;
        }
        break;
    case 19:
        func_08019068(gUnk_0813DA54, &w->base.anim, 1, 0, w->base.tiles);

        if (work->base.anim.timer == 0) {
            switch (AnimGetFrame(&work->base.anim)) {
            case 0:
                work->base.unk_168 = 0x300;
                break;
            case 3:
                work->base.unk_168 = -0x600;
                break;
            }
        }

        if (func_0800C980(&work->base, 21, 8, 7, 186, 32, 0x211, 16, -30, 16)
                == 1) {
            w->unk_184 = work->base.unk_154;
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_18_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_18_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_19_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813DB4C, obj);
}

u8 task_emy_19_1(Emy19Work* work) {
    Emy19Work* w;
    BtlObj* act;
    s32 pos;
    s32 d;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        func_0801C700(act, &pos, 0, 0);
        d = act->unk_004 - pos;

        if (d >= 0 ? d <= 0x3BFF : pos - act->unk_004 <= 0x3BFF) {
            work->base.unk_14C = 0x17;
        } else {
            work->base.unk_14C = 0x12;
        }

        w->unk_184 = 0;
    }

    switch (work->base.unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813DAFC, &w->base.anim, 0, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_14C = 0x13;
            work->base.unk_154 = 0;
        }
        break;
    case 0x13:
        if (work->base.unk_154 == 0) {
            func_08019068(gUnk_0813DAFC, &w->base.anim, 1, 0, w->base.tiles);
            work->base.unk_168 = -0x500;
            w->unk_184 = 0x500;
        }

        act->unk_004 = act->unk_034 & 4 ? act->unk_004 - w->unk_184 : act->unk_004 + w->unk_184;
        w->unk_184 = w->unk_184 * 248 >> 8;

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_14C = 0x14;
            work->base.unk_154 = 0;
        } else {
            work->base.unk_154++;
        }
        break;
    case 0x14:
        func_08019068(gUnk_0813DAFC, &w->base.anim, 2, 1, w->base.tiles);
        act->unk_004 = act->unk_034 & 4 ? act->unk_004 - w->unk_184 : act->unk_004 + w->unk_184;
        w->unk_184 = w->unk_184 * 248 >> 8;

        if (act->unk_00C >= act->unk_010) {
            work->base.unk_168 = -0x500;
        }

        if (func_08011F78(0xBB, act->unk_004, act->unk_008, act->unk_00C, 10, 10, 10) != 0) {
            m4aSongNumStart(0x244);
            w->unk_184 = -w->unk_184;
            work->base.unk_168 = -0x500;
        }

        if (work->base.unk_154 > 55) {
            work->base.unk_14C = 0x15;
            work->base.unk_154 = 0;
        } else {
            work->base.unk_154++;
        }
        break;
    case 0x15:
        func_08019068(gUnk_0813DAFC, &w->base.anim, 3, 0, w->base.tiles);
        act->unk_004 = act->unk_034 & 4 ? act->unk_004 - w->unk_184 : act->unk_004 + w->unk_184;
        w->unk_184 = w->unk_184 * 248 >> 8;

        if (act->unk_00C >= act->unk_010) {
            work->base.unk_14C = 0x16;
            work->base.unk_154 = 0;
        }
        break;
    case 0x16:
        func_08019068(gUnk_0813DAFC, &w->base.anim, 0, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
        }
        break;
    case 0x17:
        func_08019068(gUnk_0813DAFC, &w->base.anim, 4, 0, w->base.tiles);

        switch (AnimGetFrame(&work->base.anim)) {
        case 3:
            if (work->base.anim.timer == 0) {
                w->unk_184 = 0x400;
            }
            break;
        case 4:
            if (work->base.anim.timer == 0) {
                w->unk_184 = 0;
            }

            if ((act->unk_034 & 4)
                    ? func_08011F78(0xBC, act->unk_004 - 0x1000, act->unk_008, act->unk_00C, 16, 16, 32) != 0
                    : func_08011F78(0xBC, act->unk_004 + 0x1000, act->unk_008, act->unk_00C, 16, 16, 32) != 0) {
                m4aSongNumStart(0x230);
            }
            break;
        }

        act->unk_004 = act->unk_034 & 4 ? act->unk_004 - w->unk_184 : act->unk_004 + w->unk_184;
        w->unk_184 = w->unk_184 * 240 >> 8;

        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
        }
        break;
    }

    return _0800CDF0(&work->base);
}

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

u8 task_emy_21_1(Emy21Work* work) {
    Emy21Work* w;
    BtlObj* act;
    s32 pos;
    s32 d;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        func_0801C700(act, &pos, 0, 0);
        d = pos - act->unk_004;

        if (d >= 0 ? d <= 0x3FFF : act->unk_004 - pos <= 0x3FFF) {
            work->base.unk_14C = 0x12;
        } else {
            work->base.unk_14C = 0x14;
        }
    } else if (work->base.unk_14C == 5 && work->base.unk_154 == 0) {
        m4aSongNumStop(0x22C);
    }

    switch (work->base.unk_14C) {
    case 0x12:
        if (work->base.unk_154 == 0) {
            func_08019068(gUnk_0813DBB4, &w->base.anim, 0, 1, w->base.tiles);
        }

        if (work->base.unk_154 > 29) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 0x13;
        } else {
            work->base.unk_154++;
        }
        break;
    case 0x13: {
        u16 t;

        t = work->base.unk_154;

        if (t >= 12 && t <= 39) {
            if (act->unk_034 & 4) {
                func_08011F78(0xBD, act->unk_004, act->unk_008, act->unk_00C, 30, 30, 32);
            } else {
                func_08011F78(0xBD, act->unk_004, act->unk_008, act->unk_00C, 30, 30, 32);
            }
        }

        switch (work->base.unk_154) {
        case 2:
            func_08019A30();
            func_08014020(work->base.unk_03C.unk_004, work->base.unk_03C.unk_008,
                work->base.unk_03C.unk_00C - 0x1000);
            break;
        case 40:
            func_0801AF08(act);
            return 0;
        }

        work->base.unk_154++;
        break;
    }
    case 0x14:
        func_08019068(gUnk_0813DBB4, &w->base.anim, 1, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 0x15;
        }
        break;
    case 0x15:
        if (work->base.unk_154 == 0) {
            func_08019068(gUnk_0813DBB4, &w->base.anim, 2, 1, w->base.tiles);
            w->unk_184 = 0;
        }

        act->unk_004 = act->unk_034 & 4 ? act->unk_004 - w->unk_184 : act->unk_004 + w->unk_184;
        w->unk_184 += 43;

        if ((act->unk_034 & 4)
            ? func_08011F78(0xBE, act->unk_004, act->unk_008, act->unk_00C, 20, 32, 32)
            : func_08011F78(0xBE, act->unk_004, act->unk_008, act->unk_00C, 20, 32, 32)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 0x13;
        } else if (work->base.unk_154 > 28) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 0x16;
        } else {
            work->base.unk_154++;
        }
        break;
    case 0x16:
        func_08019068(gUnk_0813DBB4, &w->base.anim, 3, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 0x13;
            break;
        }

        if (work->base.anim.timer == 0) {
            switch (AnimGetFrame(&work->base.anim)) {
            case 0:
            case 1:
                act->unk_004 -= 0x380;
                act->unk_008 += 0x80;
                break;
            case 2:
                act->unk_004 -= 0x680;
                act->unk_008 += 0x280;
                break;
            case 3:
                act->unk_004 -= 0x500;
                act->unk_008 += 0x280;
                break;
            case 4:
                act->unk_004 -= 0x580;
                act->unk_008 += 0xC0;
                break;
            case 5:
                act->unk_004 -= 0x280;
                act->unk_008 += 0x3C0;
                break;
            case 6:
                act->unk_004 -= 0x180;
                break;
            case 7:
                act->unk_004 += 0x80;
                act->unk_008 += 0x40;
                break;
            }
        }

        act->unk_004 = act->unk_034 & 4 ? act->unk_004 - w->unk_184 : act->unk_004 + w->unk_184;
        w->unk_184 -= 46;

        if (w->unk_184 < 0) {
            w->unk_184 = 0;
        }

        work->base.unk_154++;
        break;
    }

    return _0800CDF0(&work->base);
}

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

u8 task_emy_22_1(Emy22Work* work) {
    Emy22Work* w;
    BtlObj* act;
    s32 pos;
    s32 pos2;
    s32 pos3;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        if (act->unk_02C < act->unk_02E) {
            work->base.unk_14C = 20;
        } else {
            work->base.unk_14C = 21;
        }
    }

    switch (work->base.unk_14C) {
    case 1:
        if (work->base.unk_154 == 0) {
            w->unk_184 = 1;
        }
        break;
    case 7:
        if (w->unk_184 != 0 && work->base.unk_154 == 0) {
            work->base.unk_14C = 18;
            work->base.unk_154 = 0;
            w->unk_184 = 0;
        }
        break;
    case 18:
        if (work->base.unk_154 == 0) {
            func_08019068(w->base.unk_15C->unk_04, &w->base.anim, 0, 1,
                w->base.tiles);
            act->unk_034 |= 0x300;
            work->base.unk_156 = 20;
            work->base.unk_154 = 1;
        }

        work->base.unk_168 = 0;

        if (work->base.unk_156 > 0) {
            ApproachValue(&work->base.unk_17C, 25, work->base.unk_156);

            if (--work->base.unk_156 > 0) {
                break;
            }
        }

        work->base.unk_14C = 19;
        work->base.unk_154 = 0;
        break;
    case 19:
        if (work->base.unk_154 == 0) {
            func_0801C700(act, &pos, 0, 0);
            func_08019068(w->base.unk_15C->unk_04, &w->base.anim, 0, 1,
                w->base.tiles);

            if (act->unk_004 > pos) {
                act->unk_034 |= 4;
            } else {
                act->unk_034 &= ~4;
            }

            act->unk_004 = (gBtlWork->unk_0DA
                + GetRandom() % (gBtlWork->unk_0DC - gBtlWork->unk_0DA + 1))
                << 8;
            act->unk_008 = (gBtlWork->unk_0DE
                + GetRandom() % (gBtlWork->unk_0E0 - gBtlWork->unk_0DE + 1))
                << 8;
            act->unk_00C = gBtlWork->unk_138;
            work->base.unk_17C = 25;
            work->base.unk_156 = 20;
            work->base.unk_154 = 1;
            m4aSongNumStart(0x23F);
        }

        work->base.unk_168 = 0;

        if (work->base.unk_156 > 0) {
            ApproachValue(&work->base.unk_17C, 0x100, work->base.unk_156);

            if (--work->base.unk_156 > 0) {
                break;
            }
        }

        act->unk_034 &= ~0x300;
        work->base.unk_14C = work->base.unk_150;
        work->base.unk_154 = 0;
        break;
    case 20:
        if (work->base.unk_154 == 0) {
            func_0801C700(act, &pos2, 0, 0);

            if (act->unk_004 > pos2) {
                act->unk_034 |= 4;
            } else {
                act->unk_034 &= ~4;
            }
        }

        act->unk_00C += -act->unk_00C >> 4;
        func_08019068(gUnk_0813DC5C, &w->base.anim, 0, 0, w->base.tiles);
        func_0800C980(&work->base, 27, 14, 40, 191, 24, 0x211, 24, 0, 24);

        if (gBtlWork->unk_07C->unk_034 & 2) {
            act->unk_02C += act->unk_02E >> 3;

            if (act->unk_02C > act->unk_02E) {
                act->unk_02C = act->unk_02E;
            }

            func_08019190(act, 10);
        }
        break;
    case 21:
        if (work->base.unk_154 == 0) {
            func_0801C700(act, &pos3, 0, 0);

            if (act->unk_004 > pos3) {
                act->unk_034 |= 4;
            } else {
                act->unk_034 &= ~4;
            }
        }

        act->unk_00C += -act->unk_00C >> 4;
        func_08019068(gUnk_0813DC5C, &w->base.anim, 1, 0, w->base.tiles);
        func_0800C980(&work->base, 50, 19, 30, 192, 16, 0x211, 48, 0, 24);
        break;
    }

    return _0800CDF0(&work->base);
}

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
    BtlObj* act;
    s32 pos;
    s32 d;
    s32 t;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        func_0801C700(act, &pos, 0, 0);
        d = act->unk_004 - pos;

        if (d >= 0 ? d <= 0x31FF : pos - act->unk_004 <= 0x31FF) {
            work->base.unk_14C = 0x13;
        } else {
            work->base.unk_14C = 0x12;
        }
    }

    switch (work->base.unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813DCE4, &w->base.anim, 0, 0, w->base.tiles);

        switch (AnimGetFrame(&work->base.anim)) {
        case 0:
        case 1:
        case 2:
            work->base.unk_168 = 0;
            act->unk_00C += (-0x4000 - act->unk_00C) >> 3;
            break;
        case 3:
            if (work->base.anim.timer == 0) {
                func_0801C700(act, &t, 0, 0);
                work->base.unk_168 = 0x200;
                w->unk_184 = t;
            }
        case 4:
        case 5:
            if (act->unk_00C >= act->unk_010) {
                work->base.unk_168 = -0x466;
            }

            act->unk_004 += (w->unk_184 - act->unk_004) >> 4;

            if (func_08011F78(0xC1, act->unk_004, act->unk_008, act->unk_00C - 0x1000, 12, 16, 16)) {
                m4aSongNumStart(0x22E);
                work->base.unk_168 = -0x466;
            }
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
        }
        break;
    case 0x13:
        func_08019068(gUnk_0813DCE4, &w->base.anim, 1, 0, w->base.tiles);
        act->unk_00C += -act->unk_00C >> 2;

        if (AnimGetFrame(&work->base.anim) == 3) {
            if ((act->unk_034 & 4)
                    ? func_08011F78(0xC2, act->unk_004 - 0x1E00, act->unk_008, act->unk_00C,
                        0x10, 0x10, 4)
                    : func_08011F78(0xC2, act->unk_004 + 0x1E00, act->unk_008, act->unk_00C,
                        0x10, 0x10, 4)) {
                m4aSongNumStart(0x22E);
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
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
    BtlObj* act;
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
        func_08019068(gUnk_0813DD6C, &w->anim, 0, 0, w->tiles);

        if (AnimIsFinished(&work->anim)) {
            func_0800CB4C(work);
        } else if (work->anim.timer == 0) {
            dx = 0;
            dy = 0;

            switch (work->anim.frame) {
            case 2:
                dx = 5;
                dy = -1;
                break;
            case 3:
                dx = 5;
                dy = -2;

                if ((act->unk_034 & 4)
                        ? func_08011F78(0xC3, act->unk_004 - 0x2800, act->unk_008, act->unk_00C,
                            0x10, 0x10, 0x20)
                        : func_08011F78(0xC3, act->unk_004 + 0x2800, act->unk_008, act->unk_00C,
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

            if (act->unk_034 & 4) {
                act->unk_004 -= dx << 8;
            } else {
                act->unk_004 += dx << 8;
            }

            act->unk_008 -= (s16)dy << 8;
        }
        break;
    case 0x13:
        func_08019068(gUnk_0813DD6C, &w->anim, 1, 0, w->tiles);

        if (AnimIsFinished(&work->anim)) {
            func_0800CB4C(work);
        } else if (work->anim.timer == 0) {
            e = 0;
            f = 0;

            switch (work->anim.frame) {
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

            if (act->unk_034 & 4) {
                act->unk_004 -= (s16)e << 8;
            } else {
                act->unk_004 += (s16)e << 8;
            }

            act->unk_008 -= (s16)f << 8;

            if (work->anim.frame >= 8 && work->anim.frame <= 22) {
                if ((act->unk_034 & 4)
                        ? func_08011F78(0xC4, act->unk_004, act->unk_008, act->unk_00C, 0x30, 0x30,
                            0x20)
                        : func_08011F78(0xC4, act->unk_004, act->unk_008, act->unk_00C, 0x30, 0x30,
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
    work->unk_03C.unk_00C = (GetRandom() % 0x1001) - 0x3000;
    work->unk_150 = 7;
}

u8 task_emy_26_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
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
        func_08019068(gUnk_0813DDF4, &w->anim, 0, 0, w->tiles);

        switch (AnimGetFrame(&work->anim)) {
        case 3:
            if (work->anim.timer == 0) {
                work->unk_168 = 0x300;
            }
            break;
        case 0:
        case 1:
        case 2:
            work->unk_168 = 0;
            p = &gBtlWork->unk_138;
            t = act->unk_00C + 0x3C00;
            act->unk_00C += (*p - t) >> 3;
            break;
        }

        func_0800C980(work, 0x20, 0x0C, 0x14, 0xC5, 0x28, 0x242, 0x14, 0x0A, 0x0A);
        break;
    case 0x13:
        work->unk_168 = 0;

        switch (work->unk_154) {
        case 0:
            func_08019068(gUnk_0813DDF4, &w->anim, 1, 0, w->tiles);
            work->unk_154++;
            break;
        case 1:
            if (AnimIsFinished(&work->anim)) {
                z = act->unk_008;

                if (act->unk_034 & 4) {
                    x = act->unk_004 - 0x6400;
                    func_08012E44(1, act->unk_004 - 0x2600, z, act->unk_00C - 0x2000, x, z, 0, 1,
                        0xC6);
                } else {
                    x = act->unk_004 + 0x6400;
                    func_08012E44(1, act->unk_004 + 0x2600, z, act->unk_00C - 0x2000, x, z, 0, 0,
                        0xC6);
                }

                work->unk_154++;
            }
            break;
        case 2:
            AnimChange(&work->anim, 1, 0);

            if (AnimIsFinished(&work->anim)) {
                work->unk_154++;
            }
            break;
        case 3:
            AnimChange(&work->anim, 1, 0);

            if (AnimIsFinished(&work->anim)) {
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
    BtlObj* act;
    u16 s;
    s32 d;
    s32 y;
    s32 tx;
    s32 ty;

    w = work;
    act = &work->unk_03C;

    if (_0800CBDC(work)) {
        func_0801C700(act, 0, &y, 0);
        d = act->unk_008 - y;

        if (d >= 0 ? d <= 0xFFF : y - act->unk_008 <= 0xFFF) {
            work->unk_14C = 0x12;
        } else {
            work->unk_14C = 0x13;
        }
    }

    switch (work->unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813DE7C, &w->anim, 0, 0, w->tiles);

        if (AnimGetFrame(&work->anim) == 1 && work->anim.timer == 0) {
            m4aSongNumStart(0x267);

            if (act->unk_034 & 4) {
                func_08013480(act->unk_004 - 0xC00, act->unk_008, act->unk_00C - 0x2200);
            } else {
                func_08013480(act->unk_004 + 0xC00, act->unk_008, act->unk_00C - 0x2200);
            }
        }

        func_0800C980(work, 0x3D, 6, 0x14, 0xC8, 0x20, 0x268, 0x28, 0, 0x14);
        break;
    case 0x13:
        func_08019068(gUnk_0813DE7C, &w->anim, 1, 1, w->tiles);
        func_0801C700(act, &tx, &ty, 0);

        if (work->unk_154 % 6 == 0) {
            work->angle = GetAngle(act->unk_004, act->unk_008, tx, ty);
        }

        act->unk_004 += gSineTable[work->angle];
        act->unk_008 -= gSineTable[work->angle + 0x40];

        if (act->unk_004 > tx) {
            act->unk_034 |= 4;
        } else {
            act->unk_034 &= ~4;
        }

        s = AnimGetFrame(&work->anim);

        if (s == 2 || s == 5) {
            if ((act->unk_034 & 4)
                    ? func_08011F78(0xC7, act->unk_004 - 0x1000, act->unk_008, act->unk_00C, 0x14,
                        0x14, 0x20)
                    : func_08011F78(0xC7, act->unk_004 + 0x1000, act->unk_008, act->unk_00C, 0x14,
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
    work->unk_03C.unk_00C = (GetRandom() % 0x1001) - 0x3000;
    work->unk_150 = 7;
}

u8 task_emy_28_1(Emy28Work* work) {
    Emy28Work* w;
    BtlObj* act;
    u16 r;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->base.unk_14C = 18;
            break;
        case 1:
            work->base.unk_14C = 19;
            break;
        }

        w->unk_184 = 0xEFFF;
    }

    if (work->base.unk_14C == 8) {
        work->base.unk_14C = 20;
        work->base.unk_154 = 0;
    }

    switch (work->base.unk_14C) {
    case 20:
        func_08019068(gUnk_0813DF04, &w->base.anim, 2, 0, w->base.tiles);
        work->base.unk_168 = 0;

        if (AnimGetFrame(&work->base.anim) == 1) {
            work->base.angle = GetAngle(act->unk_004, act->unk_008, work->base.unk_170,
                work->base.unk_174);
            work->base.unk_164 = work->base.unk_15C->unk_08;
            act->unk_004 += gSineTable[work->base.angle] * work->base.unk_164 >> 8;
            act->unk_008 += -gSineTable[work->base.angle + 64] * work->base.unk_164
                >> 8;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 22;
        }
        break;
    case 22:
        work->base.unk_168 = 0;
        func_08019068(w->base.unk_15C->unk_04, &w->base.anim, 2, 3,
            w->base.tiles);

        if (gBtlWork->unk_068 & 0x40000) {
            if (act->unk_004 > work->base.unk_170) {
                act->unk_034 |= 4;
            } else {
                act->unk_034 &= ~4;
            }

            work->base.angle = GetAngle(act->unk_004, act->unk_008, work->base.unk_170,
                work->base.unk_174);
            work->base.unk_164 = work->base.unk_15C->unk_08;
            act->unk_004 += gSineTable[work->base.angle] * work->base.unk_164 >> 8;
            act->unk_008 += -gSineTable[work->base.angle + 64] * work->base.unk_164
                >> 8;
            act->unk_00C += (work->base.unk_178 - act->unk_00C) >> 3;

            if ((work->base.unk_158 & 2) ||
                    ((act->unk_004 - work->base.unk_170 >= 0
                    ? act->unk_004 - work->base.unk_170 <= 0xFFF
                    : work->base.unk_170 - act->unk_004 <= 0xFFF) &&
                    (act->unk_008 - work->base.unk_174 >= 0
                        ? act->unk_008 - work->base.unk_174 <= 0xFFF
                        : work->base.unk_174 - act->unk_008 <= 0xFFF))) {
                work->base.unk_14C = 21;
                work->base.unk_154 = 0;
                break;
            }

            work->base.unk_154++;
        }
        break;
    case 21:
        func_08019068(gUnk_0813DF04, &w->base.anim, 3, 0, w->base.tiles);
        work->base.unk_168 = 0;
        act->unk_004 += gSineTable[work->base.angle] * work->base.unk_164 >> 8;
        act->unk_008 += -gSineTable[work->base.angle + 64] * work->base.unk_164 >> 8;
        work->base.unk_164 -= 25;

        if (work->base.unk_164 < 0) {
            work->base.unk_164 = 0;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 7;
        }
        break;
    case 18:
        func_08019068(gUnk_0813DF04, &w->base.anim, 0, 0, w->base.tiles);

        if (work->base.anim.timer == 0) {
            switch (AnimGetFrame(&work->base.anim)) {
            case 0:
                work->base.unk_168 = 0x300;
                break;
            case 3:
                work->base.unk_168 = -0x600;
                break;
            }
        }

        if (func_0800C980(&work->base, 22, 10, 20, 201, 32, 0x211, 16, -40, 32)
                == 1) {
            w->unk_184 = work->base.unk_154;
        }
        break;
    case 19:
        func_08019068(gUnk_0813DF04, &w->base.anim, 1, 0, w->base.tiles);

        if (work->base.unk_154 <= 34) {
            work->base.unk_168 = 0;
            act->unk_00C += (-0x4000 - act->unk_00C) >> 3;
        } else if (work->base.unk_154 == 35) {
            work->base.unk_168 = 0x300;
        }

        if (work->base.anim.timer == 0 && AnimGetFrame(&work->base.anim) == 1) {
            if (act->unk_034 & 4) {
                func_08013480(act->unk_004 + 0x1000, act->unk_008, act->unk_00C - 0x3200);
            } else {
                func_08013480(act->unk_004 - 0x1000, act->unk_008, act->unk_00C - 0x3200);
            }

            m4aSongNumStart(0x267);
        }

        if (func_0800C980(&work->base, 35, 10, 14, 202, 32, 0x249, 24, 32, 16)
                == 1) {
            w->unk_184 = work->base.unk_154;
        }
        break;
    }

    return _0800CDF0(&work->base);
}

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
        AnimChange(&work->base.anim, anim, 0);
        ApproachValue(&work->base.unk_03C.unk_004, work->base.unk_03C.unk_014 + ((s16)dx << 8), work->unk_186);
        ApproachValue(&work->base.unk_03C.unk_008, work->base.unk_03C.unk_018 + ((s16)dy << 8), work->unk_186);
        ApproachValue(&work->base.unk_03C.unk_00C, (s16)dz << 8, work->unk_186);
        work->unk_186--;
    } else {
        work->unk_186 = 8;
        work->unk_184++;
    }
}

u8 task_emy_29_1(Emy29Work* work) {
    Emy29Work* w;
    BtlObj* act;
    s32 pos;
    s32 d;
    s32 a;
    s32 t;
    s16 c;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        func_0801C700(act, &pos, 0, 0);
        d = act->unk_004 - pos;

        if (d >= 0 ? d <= 0x27FF : pos - act->unk_004 <= 0x27FF) {
            work->base.unk_14C = 0x13;
        } else {
            work->base.unk_14C = 0x12;
        }
    }

    switch (work->base.unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813DFAC, &w->base.anim, 0, 0, w->base.tiles);
        work->base.unk_168 = 0;
        a = -gSineTable[(((u16)work->base.unk_154 * 2) & 0xFF) + 0x40] << 4;
        t = act->unk_00C + 0x1000;
        act->unk_00C += (a - t) >> 2;

        if (func_0800C980(&work->base, 0x16, 0x64, 0x18, 0xCB, 0xB4, 0x241, 0, 0, 0x0C) == 1) {
            func_0800CB4C(&work->base);
        }
        break;
    case 0x13:
        c = work->base.unk_154;

        if (c == 0) {
            func_08019068(gUnk_0813DFAC, &w->base.anim, 1, 0, w->base.tiles);
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

        if ((act->unk_034 & 4)
                ? func_08011F78(0xCC, act->unk_004, act->unk_008, act->unk_00C, 0x0C, 0x0C, 0x0C)
                : func_08011F78(0xCC, act->unk_004, act->unk_008, act->unk_00C, 0x0C, 0x0C, 0x0C)) {
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
    work->unk_03C.unk_00C = (GetRandom() % 0x1001) - 0x3000;
    work->unk_150 = 7;
}

u8 task_emy_30_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    s32 x;
    s32 y;
    s32 d;
    u16 r;

    w = work;
    act = &work->unk_03C;
    func_0801C700(act, &x, &y, 0);

    if (_0800CBDC(work)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->unk_14C = 18;
            break;
        case 1:
            work->unk_14C = 21;
            break;
        }
    }

    if (work->unk_14C == 8) {
        work->unk_14C = 24;
        work->unk_154 = 0;
    }

    switch (work->unk_14C) {
    case 24:
        func_08019068(gUnk_0813E034, &w->anim, 0, 0, w->tiles);
        work->unk_168 = 0;

        if (AnimGetFrame(&work->anim) == 1) {
            work->angle = GetAngle(act->unk_004, act->unk_008, work->unk_170, work->unk_174);
            work->unk_164 = work->unk_15C->unk_08;
            act->unk_004 += gSineTable[work->angle] * work->unk_164 >> 8;
            act->unk_008 += -gSineTable[work->angle + 64] * work->unk_164 >> 8;
        }

        if (AnimIsFinished(&work->anim)) {
            work->unk_154 = 0;
            work->unk_14C = 26;
        }
        break;
    case 26:
        work->unk_168 = 0;
        func_08019068(w->unk_15C->unk_04, &w->anim, 2, 3, w->tiles);

        if (gBtlWork->unk_068 & 0x40000) {
            if (act->unk_004 > work->unk_170) {
                act->unk_034 |= 4;
            } else {
                act->unk_034 &= ~4;
            }

            work->angle = GetAngle(act->unk_004, act->unk_008, work->unk_170, work->unk_174);
            work->unk_164 = work->unk_15C->unk_08;
            act->unk_004 += gSineTable[work->angle] * work->unk_164 >> 8;
            act->unk_008 += -gSineTable[work->angle + 64] * work->unk_164 >> 8;
            act->unk_00C += (work->unk_178 - act->unk_00C) >> 3;

            if ((work->unk_158 & 2)
                || ((act->unk_004 - work->unk_170 >= 0
                        ? act->unk_004 - work->unk_170
                        : work->unk_170 - act->unk_004) <= 0xFFF
                    && (act->unk_008 - work->unk_174 >= 0
                        ? act->unk_008 - work->unk_174
                        : work->unk_174 - act->unk_008) <= 0xFFF)) {
                work->unk_14C = 25;
                work->unk_154 = 0;
            } else {
                work->unk_154++;
            }
        }
        break;
    case 25:
        func_08019068(gUnk_0813E034, &w->anim, 1, 0, w->tiles);
        work->unk_168 = 0;
        act->unk_004 += gSineTable[work->angle] * work->unk_164 >> 8;
        act->unk_008 += -gSineTable[work->angle + 64] * work->unk_164 >> 8;
        work->unk_164 -= 25;

        if (work->unk_164 < 0) {
            work->unk_164 = 0;
        }

        if (AnimIsFinished(&work->anim)) {
            work->unk_154 = 0;
            work->unk_14C = 7;
        }
        break;
    case 18: {
    s32 currentX;
    s32 targetX;
        func_08019068(gUnk_0813E034, &w->anim, 2, 0, w->tiles);
        work->unk_168 = 0;
        act->unk_00C += (-0x4000 - act->unk_00C) >> 3;
        act->unk_008 += (y - act->unk_008) >> 3;

        currentX = act->unk_004;
        targetX = x;

        if (currentX < targetX) {
            act->unk_034 &= ~4;
            d = currentX + 0x1400;
        } else {
            act->unk_034 |= 4;
            d = currentX - 0x1400;
        }

        act->unk_004 = currentX + ((targetX - d) >> 3);

        if (AnimIsFinished(&work->anim)) {
            work->unk_14C = 19;
            work->unk_154 = 0;
        }
        break;
    }
    case 19: {
    s32 currentX;
    s32 targetX;
        func_08019068(gUnk_0813E034, &w->anim, 3, 1, w->tiles);
        work->unk_168 = 0;
        act->unk_00C += (-0x2000 - act->unk_00C) >> 3;
        act->unk_008 += (y - act->unk_008) >> 4;

        currentX = act->unk_004;
        targetX = x;

        if (currentX < targetX) {
            act->unk_034 &= ~4;
            d = currentX + 0x1400;
        } else {
            act->unk_034 |= 4;
            d = currentX - 0x1400;
        }

        act->unk_004 = currentX + ((targetX - d) >> 3);

        if (work->anim.timer == 0) {
            switch (AnimGetFrame(&work->anim)) {
            case 1:
            case 3:
                func_08019A30();

                if (func_08011F78(0xCD, act->unk_004, act->unk_008, act->unk_00C, 12, 12, 12)) {
                    m4aSongNumStart(0x241);
                }
                break;
            }
        }

        if (work->unk_154 > 100) {
            work->unk_154 = 0;
            work->unk_14C = 20;
        } else {
            work->unk_154++;
        }
        break;
    }
    case 20:
        func_08019068(gUnk_0813E034, &w->anim, 4, 0, w->tiles);
        work->unk_168 = 0;

        if (AnimIsFinished(&work->anim)) {
            func_0800CB4C(work);
        }
        break;
    case 21:
        work->unk_168 = 0;

        if (work->unk_154 == 0) {
            func_08019068(gUnk_0813E034, &w->anim, 5, 0, w->tiles);

            if (act->unk_004 > 0x10000) {
                act->unk_034 |= 4;
                work->unk_170 = gBtlWork->unk_0DC * 256;
            } else {
                act->unk_034 &= ~4;
                work->unk_170 = gBtlWork->unk_0DA * 256;
            }
        }

        act->unk_004 += (work->unk_170 - act->unk_004) >> 4;
        act->unk_008 += (y - act->unk_008) >> 4;
        act->unk_00C += (-0x800 - act->unk_00C) >> 4;

        if (AnimIsFinished(&work->anim) && (work->unk_158 & 2)) {
            work->unk_154 = 0;
            work->unk_14C = 22;
            work->unk_164 = 0;
        } else {
            work->unk_154++;
        }
        break;
    case 22:
        func_08019068(gUnk_0813E034, &w->anim, 6, 1, w->tiles);
        work->unk_168 = 0;
        work->unk_164 += 38;
        act->unk_008 += (y - act->unk_008) >> 4;
        act->unk_00C += (-0x800 - act->unk_00C) >> 4;

        if (act->unk_034 & 4) {
            if (func_08011F78(0xCE, act->unk_004 - 0x1400, act->unk_008, act->unk_00C, 12, 12, 12)) {
                m4aSongNumStart(0x248);
            }

            act->unk_004 -= work->unk_164;

            if (act->unk_004 < (gBtlWork->unk_0DA + 32) * 256) {
                work->unk_14C = 23;
                work->unk_154 = 0;
            }
        } else {
            if (func_08011F78(0xCE, act->unk_004 + 0x1400, act->unk_008, act->unk_00C, 12, 12, 12)) {
                m4aSongNumStart(0x248);
            }

            act->unk_004 += work->unk_164;

            if (act->unk_004 > (gBtlWork->unk_0DC - 32) * 256) {
                work->unk_14C = 23;
                work->unk_154 = 0;
            }
        }
        break;
    case 23:
        func_08019068(gUnk_0813E034, &w->anim, 7, 0, w->tiles);
        work->unk_168 = 0;
        work->unk_164 -= 128;

        if (work->unk_164 < 0) {
            work->unk_164 = 0;
        }

        if (act->unk_034 & 4) {
            act->unk_004 -= work->unk_164;
        } else {
            act->unk_004 += work->unk_164;
        }

        if (AnimIsFinished(&work->anim)) {
            func_0800CB4C(work);
        }
        break;
    }

    return _0800CDF0(work);
}

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

u8 task_emy_31_1(Emy31Work* work) {
    Emy31Work* w;
    BtlObj* act;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        switch ((u16)(GetRandom() % 3)) {
        case 0:
            work->base.unk_14C = 18;
            break;
        case 1:
            work->base.unk_14C = 19;
            break;
        case 2:
            work->base.unk_14C = 20;
            break;
        }

        w->unk_184 = 0;
    }

    switch (work->base.unk_14C) {
    case 18: {
        s32 x;
        s32 y;
        work->base.unk_168 = 0;

        switch (w->unk_184) {
        case 0:
            if (work->base.unk_154 == 0) {
                func_08019068(gUnk_0813E11C, &w->base.anim, 0, 0,
                    w->base.tiles);
            }

            if (AnimIsFinished(&work->base.anim)) {
                w->unk_184 = 1;
                work->base.unk_154 = 0;
            } else {
                work->base.unk_154++;
            }
            break;
        case 1:
            if (work->base.unk_154 == 0) {
                AnimStart(&work->base.anim, 1, 0);

                y = act->unk_008;
                if (act->unk_034 & 4) {
                    x = act->unk_004 - 0xC800;
                    func_08012E44(1, act->unk_004 - 0x4000, y, act->unk_00C,
                        x, y, 0, 1, 0xCF);
                } else {
                    x = act->unk_004 + 0xC800;
                    func_08012E44(1, act->unk_004 + 0x4000, y, act->unk_00C,
                        x, y, 0, 0, 0xCF);
                }
            }

            if (work->base.unk_154 > 30) {
                w->unk_184 = 3;
                work->base.unk_154 = 0;
            } else {
                work->base.unk_154++;
            }
            break;
        case 3:
            if (work->base.unk_154 == 0) {
                AnimStart(&work->base.anim, 2, 0);
            }

            if (AnimIsFinished(&work->base.anim)) {
                func_08019068(w->base.unk_15C->unk_04, &w->base.anim, 0, 1,
                    w->base.tiles);
            }

            if (func_080128EC()) {
                work->base.unk_154++;
            } else {
                w->unk_184 = 0;
                func_0800CB4C(&work->base);
            }
            break;
        }
        break;
    }
    case 19: {
        s32 x;
        s32 y;
        work->base.unk_168 = 0;

        switch (w->unk_184) {
        case 0:
            if (work->base.unk_154 == 0) {
                func_08019068(gUnk_0813E11C, &w->base.anim, 1, 0,
                    w->base.tiles);
            }

            if (AnimIsFinished(&work->base.anim)) {
                w->unk_184 = 1;
                work->base.unk_154 = 0;
            } else {
                work->base.unk_154++;
            }
            break;
        case 1:
            if (work->base.unk_154 == 0) {
                AnimStart(&work->base.anim, 1, 1);

                y = act->unk_008;
                if (act->unk_034 & 4) {
                    x = act->unk_004 - 0x6400;
                    func_08013308(1, act->unk_004 - 0x4600, y, act->unk_00C,
                        x, y, 0, 1, 0xD0);
                } else {
                    x = act->unk_004 + 0x6400;
                    func_08013308(1, act->unk_004 + 0x4600, y, act->unk_00C,
                        x, y, 0, 0, 0xD0);
                }
            }

            if (work->base.unk_154 > 60) {
                w->unk_184 = 2;
                work->base.unk_154 = 0;
            } else {
                work->base.unk_154++;
            }
            break;
        case 2:
            if (work->base.unk_154 == 0) {
                AnimStart(&work->base.anim, 2, 0);
            }

            if (AnimIsFinished(&work->base.anim)) {
                func_08019068(w->base.unk_15C->unk_04, &w->base.anim, 0, 1,
                    w->base.tiles);
            }

            if (func_080128EC()) {
                work->base.unk_154++;
            } else {
                w->unk_184 = 0;
                func_0800CB4C(&work->base);
            }
            break;
        }
        break;
    }
    case 20:
        work->base.unk_168 = 0;

        switch (w->unk_184) {
        case 0:
            if (work->base.unk_154 == 0) {
                func_08019068(gUnk_0813E11C, &w->base.anim, 2, 0,
                    w->base.tiles);
                func_0801C700(act, &w->unk_188, &w->unk_18C, &w->unk_190);
            }

            if (AnimIsFinished(&work->base.anim)) {
                w->unk_184 = 1;
                work->base.unk_154 = 0;
            } else {
                work->base.unk_154++;
            }
            break;
        case 1:
            if (work->base.unk_154 == 0) {
                AnimStart(&work->base.anim, 1, 0);
                work->base.unk_156 = 0;
            }

            if (AnimIsFinished(&work->base.anim)) {
                if (work->base.unk_156 == 0) {
                    if (act->unk_034 & 4) {
                        func_08015834(1, act->unk_004 - 0x1600, act->unk_008,
                            act->unk_00C - 0x3C00, w->unk_188, w->unk_18C,
                            w->unk_190, 0xD1);
                    } else {
                        func_08015834(1, act->unk_004 + 0x1600, act->unk_008,
                            act->unk_00C - 0x3C00, w->unk_188, w->unk_18C,
                            w->unk_190, 0xD1);
                    }

                    work->base.unk_156++;
                }

                if (!func_080128EC()) {
                    w->unk_184 = 2;
                    work->base.unk_154 = 0;
                    break;
                }
            }
            work->base.unk_154++;
            break;
        case 2:
            if (work->base.unk_154 == 0) {
                AnimStart(&work->base.anim, 2, 0);
            }

            if (AnimIsFinished(&work->base.anim)) {
                w->unk_184 = 0;
                func_0800CB4C(&work->base);
            } else {
                work->base.unk_154++;
            }
            break;
        }
        break;
    }

    return _0800CDF0(&work->base);
}


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

u8 task_emy_37_1(Emy37Work* work) {
    Emy37Work* w;
    BtlObj* act;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        if (work->base.unk_14C == 20) {
            work->unk_184 = 0;
            act->unk_034 &= ~0x100;
            work->base.unk_14C = 25;
            work->base.unk_03C.unk_0A2 = 20;
        } else {
            work->base.unk_14C = 24;
        }
    }

    switch (work->base.unk_14C) {
    case 24:
        func_08019068(gUnk_0813E1B4, &w->base.anim, 0, 0, w->base.tiles);
        func_0800C980(&work->base, 30, 14, 20, 0xD2, 70, 0x211, 0, 0, 24);
        break;
    case 25:
        func_08019068(gUnk_0813E1B4, &w->base.anim, 4, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 29;
        } else {
            work->base.unk_154++;
        }
        break;
    case 29:
        if (work->base.unk_154 == 0) {
            work->base.unk_168 = -0x399;
            func_08019068(gUnk_0813E1B4, &w->base.anim, 1, 0, w->base.tiles);
        }

        if (work->base.unk_168 > 0) {
            work->base.unk_168 = 0;
        }

        if (func_08011F78(0xD3, act->unk_004, act->unk_008, act->unk_00C, 16, 8, 32)) {
            m4aSongNumStart(0x211);
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 30;
        } else {
            work->base.unk_154++;
        }
        break;
    case 30:
        if (work->base.unk_154 == 0) {
            s32 x;
            s32 y;

            func_08019068(gUnk_0813E1B4, &w->base.anim, 2, 1, w->base.tiles);
            w->unk_188 = 0;
            func_0801C700(act, &x, &y, 0);
            w->unk_18C = GetAngle(act->unk_004, act->unk_008, x, y);
        }

        if (((u16)work->base.unk_154 % 4) == 0) {
            u8 angle;
            s32 x;
            s32 y;

            func_0801C700(act, &x, &y, 0);
            angle = GetAngle(act->unk_004, act->unk_008, x, y);
            ApproachAngle(&w->unk_18C, angle, 4);
        }

        act->unk_004 += gSineTable[(u8)w->unk_18C] * (s32)w->unk_188 >> 8;
        act->unk_008 += -gSineTable[(u8)w->unk_18C + 64] * (s32)w->unk_188 >> 8;
        w->unk_188 += 12;

        if (func_08011F78(0xD3, act->unk_004, act->unk_008, act->unk_00C, 32, 16, 16)) {
            m4aSongNumStart(0x211);
            work->base.unk_154 = 120;
        }

        work->base.unk_168 = 0;

        if (work->base.unk_154 > 120) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    case 28:
        func_08019068(gUnk_0813E1B4, &w->base.anim, 10, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            act->unk_034 &= ~0x100;
            func_0800CD40(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    case 19:
        func_08019068(gUnk_0813E1B4, &w->base.anim, 9, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_14C = 20;
            ColliderSetDisabled(&act->unk_040, 1);
            act->unk_034 |= 0x100;
            act->unk_0A2 = 0;
        }
        break;
    case 20:
        if (gBtlWork->unk_068 & 0x40000) {
            s32 x;
            s32 y;
            s32 dx;
            s32 dy;
            s32 sample;
            s32 offset;

            func_0801C700(act, &x, &y, 0);
            func_08019068(gUnk_0813E1B4, &w->base.anim, 5, 1, w->base.tiles);
            sample = gSineTable[work->base.angle];
            offset = 70;
            offset *= sample;
            dx = x + offset;
            dy = y + -gSineTable[work->base.angle + 64] * 35;
            dx -= act->unk_004;
            dx >>= 4;
            dy -= act->unk_008;
            dy >>= 4;

            if (dx > 0x300) {
                dx = 0x300;
            } else if (dx < -0x300) {
                dx = -0x300;
            }

            if (dy > 0x300) {
                dy = 0x300;
            } else if (dy < -0x300) {
                dy = -0x300;
            }

            act->unk_004 += dx;
            act->unk_008 += dy;

            if (work->base.unk_154 == 0) {
                act->unk_034 &= ~0x200;
            }

            func_0801BCF8(act);

            if (act->unk_034 & 4) {
                work->base.angle -= 2;
                w->unk_184 = work->base.angle;
            } else {
                work->base.angle += 2;
                w->unk_184 = -work->base.angle;
            }

            if (work->base.unk_154 > 160) {
                w->unk_184 = 0;
                work->base.unk_14C = 21;
                ColliderSetDisabled(&act->unk_040, 0);
                act->unk_034 &= ~0x100;
                act->unk_0A2 = 20;
                act->unk_034 |= 0x200;
                work->base.unk_154 = 0;
            } else {
                work->base.unk_154++;
            }
        }
        break;
    case 21:
        func_08019068(gUnk_0813E1B4, &w->base.anim, 6, 0, w->base.tiles);

        if (work->base.unk_154 == 30) {
            act->unk_034 &= ~0x100;
        }

        if (AnimIsFinished(&work->base.anim)) {
            act->unk_034 &= ~0x300;
            work->base.unk_14C = 26;
            work->base.unk_154 = 0;
        } else {
            work->base.unk_154++;
        }
        break;
    case 26:
        if (work->base.unk_154 == 0) {
            func_08019068(gUnk_0813E1B4, &w->base.anim, 7, 0, w->base.tiles);
            work->base.unk_168 = -0x433;
        }

        if (work->base.unk_168 > 0) {
            work->base.unk_14C = 27;
            work->base.unk_154 = 0;
        } else {
            work->base.unk_154++;
        }
        break;
    case 27:
        if (work->base.unk_154 == 0) {
            func_08019068(gUnk_0813E1B4, &w->base.anim, 8, 0, w->base.tiles);
        }

        if (act->unk_00C >= act->unk_010) {
            work->base.unk_14C = 18;
            work->base.unk_154 = 0;
        } else {
            work->base.unk_154++;
        }
        break;
    case 18:
        if (work->base.unk_154 == 0) {
            act->unk_0A2 = 20;
            ColliderSetDisabled(&act->unk_040, 0);
            act->unk_034 &= ~0x300;
            func_08019068(w->base.unk_15C->unk_04, &w->base.anim, 0, 3, w->base.tiles);
        }

        func_0801BCF8(act);

        if ((u16)(GetRandom() % 200U) == 0) {
            work->base.unk_14C = 4;

            if (GetRandom() % 2 == 0) {
                work->base.unk_170 = -((act->unk_0CE
                    + (-act->unk_0D0 + GetRandom() % (act->unk_0D0 - -act->unk_0D0 + 1))) * 256);
            } else {
                work->base.unk_170 = (act->unk_0CE
                    + (-act->unk_0D0 + GetRandom() % (act->unk_0D0 - -act->unk_0D0 + 1))) * 256;
            }
            break;
        } else if ((u16)(GetRandom() % 100U) == 0) {
            work->base.unk_14C = 19;
            act->unk_034 |= 0x200;
            work->base.angle = GetRandom();
            work->base.unk_154 = 0;
            break;
        }

        if ((u16)((u32)GetRandom() % work->base.unk_15C->unk_0E) == 0) {
            s32 x;

            func_0801C700(act, &x, 0, 0);

            if (act->unk_004 > x) {
                act->unk_034 |= 4;
            } else {
                act->unk_034 &= ~4;
            }
        }

        work->base.unk_154++;
        break;
    }

    return _0800CDF0(&work->base);
}


void task_emy_37_2(Emy37Work* work) {
    Emy37Work* w;
    BtlObj* act;
    u16 pri;
    s32 affine;
    s32 rot;
    s32 scale;
    s32 zoom;
    s16 x;
    s16 y;

    w = work;

    if (work->base.unk_15A != 0) {
        act = &work->base.unk_03C;
        pri = GetBattleSpritePriorityFlags(act->unk_008) | work->base.unk_162;
        WorldToScreen(&x, &y, act->unk_004, act->unk_008, act->unk_00C);

        zoom = work->base.unk_180;

        if (zoom == 0x100) {
            if (act->unk_034 & 4) {
                scale = gBtlWork->unk_024;
                rot = scale;
            } else if (work->unk_184 == 0 && gBtlWork->unk_024 == zoom) {
                scale = zoom;
                rot = scale;
                pri |= 1;
            } else {
                rot = -gBtlWork->unk_024;
                scale = gBtlWork->unk_024;
            }
        } else {
            if (act->unk_034 & 4) {
                rot = gBtlWork->unk_024 * work->base.unk_17C >> 8;
                scale = gBtlWork->unk_024;
            } else {
                rot = -(gBtlWork->unk_024 * work->base.unk_17C >> 8);
                scale = gBtlWork->unk_024;
            }

            scale = scale * zoom >> 8;
        }

        if (w->unk_184) {
            affine = AllocObjAffine(w->unk_184, rot, scale, 1);
        } else if (scale == 0x100 && rot == scale) {
            affine = 0;
        } else if (scale <= 0xFF) {
            affine = AllocObjAffine(0, rot, scale, 0);
        } else {
            affine = AllocObjAffine(0, rot, scale, 1);
        }

        if (func_0801CA00(act)) {
            DrawSprite(x, y, work->base.gfx, work->base.tiles, work->base.unk_008, affine,
                pri, -0x1004 - (act->unk_008 >> 8) * 4);
        } else if (work->base.unk_14C == 0x14) {
            DrawSprite(x, y, work->base.gfx, work->base.tiles, work->base.unk_004, affine,
                pri, 0xFFFF);
        } else {
            DrawSprite(x, y, work->base.gfx, work->base.tiles, work->base.unk_004, affine,
                pri, -0x1004 - (act->unk_008 >> 8) * 4);
        }

        TaskPoolDraw(&work->base.unk_028);
    }
}


void task_emy_37_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_38_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813E2EC, obj);
}

u8 task_emy_38_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
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
        func_08019068(gUnk_0813E2CC, &w->anim, 0, 0, w->tiles);
        func_0800C980(work, 0x1E, 0x14, 0x2D, 0xD4, 0x32, 0x212, 0, 0, 0x18);

        if (work->unk_154 == 0x1E) {
            work->unk_168 = -0x300;
        }
        break;
    case 0x13:
        func_08019068(gUnk_0813E2CC, &w->anim, 1, 0, w->tiles);

        if (work->unk_154 == 0x3F) {
            func_08011F78(0xD5, act->unk_004, act->unk_008, act->unk_00C, 0x100, 0x100, 1);
            m4aSongNumStart(0x210);
            func_0802F1E8();
        }

        if (AnimIsFinished(&work->anim)) {
            func_0800CB4C(work);
        } else {
            work->unk_154++;
        }
        break;
    }

    ret = _0800CDF0(work);

    if ((gBtlWork->unk_07C->unk_004 < work->unk_03C.unk_004 && (work->unk_03C.unk_034 & 4)) ||
            (gBtlWork->unk_07C->unk_004 > work->unk_03C.unk_004 &&
                !(work->unk_03C.unk_034 & 4))) {
        work->unk_03C.unk_034 |= 0x8000;
    } else {
        work->unk_03C.unk_034 &= ~0x8000;
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
    BtlObj* act;
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
        func_08019068(gUnk_0813E354, &w->base.anim, 0, 0, w->base.tiles);

        if (work->base.unk_154 == 0x30) {
            z = act->unk_008;

            if (act->unk_034 & 4) {
                x = act->unk_004 - 0x6400;
                func_08012E44(0, act->unk_004 - 0x4000, z, act->unk_00C - 0x2000, x, z, 0, 1,
                    0xD6);
            } else {
                x = act->unk_004 + 0x6400;
                func_08012E44(0, act->unk_004 + 0x4000, z, act->unk_00C - 0x2000, x, z, 0, 0,
                    0xD6);
            }
        }

        if (work->base.unk_154 > 0x30 && BgAnimIsStopped()) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    case 0x13:
        c = work->base.unk_154;

        if (c == 0) {
            func_08019068(gUnk_0813E354, &w->base.anim, 1, 0, w->base.tiles);
            w->unk_184 = 0;
        }

        switch (AnimGetFrame(&work->base.anim)) {
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

            if (work->base.anim.timer == 0) {
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

            if (work->base.anim.timer == 0) {
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

        if (act->unk_034 & 4) {
            act->unk_004 -= w->unk_184;
        } else {
            act->unk_004 += w->unk_184;
        }

        w->unk_184 -= 0x19;

        if (w->unk_184 < 0) {
            w->unk_184 = 0;
        }

        if (func_08011F78(0xD7, act->unk_004, act->unk_008, act->unk_00C, p, q, 0x28)) {
            m4aSongNumStart(0x221);
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    }

    ret = _0800CDF0(&work->base);

    if ((gBtlWork->unk_07C->unk_004 < work->base.unk_03C.unk_004
                && (work->base.unk_03C.unk_034 & 4))
            || (gBtlWork->unk_07C->unk_004 > work->base.unk_03C.unk_004
                && !(work->base.unk_03C.unk_034 & 4))) {
        work->base.unk_03C.unk_034 |= 0x8000;
    } else {
        work->base.unk_03C.unk_034 &= ~0x8000;
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
    BtlObj* act;
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
        func_08019068(gUnk_0813E3DC, &w->base.anim, 0, 0, w->base.tiles);
        work->base.unk_168 = 0;
        a = gSineTable[((u16)work->base.unk_154 * 4) & 0xFF] << 4;
        t = act->unk_00C + 0x1000;
        act->unk_00C += (a - t) >> 2;
        func_0800C980(&work->base, 0x14, 0x63, 0x1E, 0xD8, 0x40, 0x221, 0, -0x10, 0x2C);
        break;
    case 0x13:
        if (work->base.unk_154 == 0) {
            func_08019068(gUnk_0813E3DC, &w->base.anim, 1, 0, w->base.tiles);
            func_0801C700(act, &w->unk_184, &w->unk_188, 0);
            w->unk_18C = 0;
        }

        if (AnimGetFrame(&work->base.anim) == 4 && work->base.anim.timer == 0) {
            if (act->unk_034 & 4) {
                func_08015834(1, act->unk_004 - 0x2C00, act->unk_008, act->unk_00C, w->unk_184,
                    w->unk_188, w->unk_18C, 0xD9);
            } else {
                func_08015834(1, act->unk_004 + 0x2C00, act->unk_008, act->unk_00C, w->unk_184,
                    w->unk_188, w->unk_18C, 0xD9);
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
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
    BtlObj* act;
    s32 pos;
    s32 d;
    u8 ret;

    w = work;
    act = &work->unk_03C;

    if (_0800CBDC(work)) {
        func_0801C700(act, &pos, 0, 0);
        d = act->unk_004 - pos;

        if (d >= 0 ? d <= 0x4FFF : pos - act->unk_004 <= 0x4FFF) {
            work->unk_14C = 0x12;
        } else {
            work->unk_14C = 0x13;
        }
    }

    switch (work->unk_14C) {
    case 0x12:
        func_08019068(gUnk_0813E464, &w->anim, 0, 0, w->tiles);

        switch (AnimGetFrame(&work->anim)) {
        case 1:
        case 2:
        case 3:
        case 4:
            if ((act->unk_034 & 4)
                    ? func_08011F78(0xDA, act->unk_004 - 0x2000, act->unk_008, act->unk_00C, 0x20,
                        0x10, 0x28)
                    : func_08011F78(0xDA, act->unk_004 + 0x2000, act->unk_008, act->unk_00C, 0x20,
                        0x10, 0x28)) {
                m4aSongNumStart(0x243);
            }
            break;
        }

        if (AnimIsFinished(&work->anim)) {
            func_0800CB4C(work);
        }
        break;
    case 0x13:
        func_08019068(gUnk_0813E464, &w->anim, 1, 0, w->tiles);

        if (AnimGetFrame(&work->anim) == 7 && work->anim.timer == 0) {
            if (act->unk_034 & 4) {
                func_08012E44(1, act->unk_004 - 0x4000, act->unk_008, act->unk_00C - 0x400,
                    act->unk_004 - 0xB400, act->unk_008, act->unk_00C - 0x400, 1, 0xDB);
            } else {
                func_08012E44(1, act->unk_004 + 0x4000, act->unk_008, act->unk_00C - 0x400,
                    act->unk_004 + 0xB400, act->unk_008, act->unk_00C - 0x400, 0, 0xDB);
            }
        }

        if (AnimIsFinished(&work->anim)) {
            func_0800CB4C(work);
        }
        break;
    }

    ret = _0800CDF0(work);

    if ((gBtlWork->unk_07C->unk_004 < work->unk_03C.unk_004 && (work->unk_03C.unk_034 & 4)) ||
            (gBtlWork->unk_07C->unk_004 > work->unk_03C.unk_004 &&
                !(work->unk_03C.unk_034 & 4))) {
        work->unk_03C.unk_034 |= 0x0C008000;
    } else {
        work->unk_03C.unk_034 &= ~0x0C008000;
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

static inline s32 EmyFacingX(BtlObj* actor, s32 offset) {
    return actor->unk_034 & 4 ? actor->unk_004 - offset : actor->unk_004 + offset;
}

u8 task_emy_81_1(Emy81Work* work) {
    Emy81Work* w;
    BtlObj* act;
    u16 r;
    u16 frame;
    u16 idleFrame;
    s32 d;
    s32 hitX;
    s32 a;
    s32 z;
    s32 b;

    w = work;
    act = &work->base.unk_03C;

    if (_0800CBDC(&work->base)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->base.unk_14C = 18;
            break;
        case 1:
            work->base.unk_14C = 19;
            break;
        }
    }

    switch (work->base.unk_14C) {
    case 0:
    case 4:
        idleFrame = AnimGetGfxIndex(&work->base.anim);

        if ((idleFrame == 2 || idleFrame == 6) && work->base.anim.timer == 0) {
            work->base.unk_168 = -0x133;
        }

        if (GetRandom() % 200 == 0) {
            work->base.unk_14C = 20;
            work->base.unk_154 = 0;
            w->unk_184 = 0;
        }
        break;
    case 20:
        func_08019068(gUnk_0813E4EC, &w->base.anim, 2, 0, w->base.tiles);

        d = (-0x2800 - act->unk_00C) >> 4;

        if (d < -w->unk_184) {
            w->unk_184 += 25;
        } else {
            w->unk_184 = -d;
        }

        work->base.unk_168 = 0;

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 21;
        } else {
            work->base.unk_154++;
        }
        break;
    case 21:
        if (work->base.unk_154 == 0) {
            func_0801C700(act, &a, &b, 0);
            func_08019068(gUnk_0813E4EC, &w->base.anim, 3, 1, w->base.tiles);
            w->unk_18C = (a * 2) - act->unk_004;
            w->unk_190 = (b * 2) - act->unk_008;
            w->unk_184 = 0;
            w->unk_188 = 0;
        }

        work->base.unk_168 = 0;
        {
            s32 sample = gSineTable[((u16)work->base.unk_154 * 4) & 0xFF] * 10;
            s32 current = act->unk_00C;

            z = current + 0x2800;
            act->unk_00C = current + ((sample - z) >> 3);
        }

        d = (w->unk_18C - act->unk_004) >> 4;

        if (d > w->unk_184) {
            d = w->unk_184;
            w->unk_184 += 51;
        } else if (d < -w->unk_184) {
            d = -w->unk_184;
            w->unk_184 += 51;
        } else {
            w->unk_184 = d < 0 ? -d : d;
        }

        act->unk_004 += d;
        d = (w->unk_190 - act->unk_008) >> 4;

        if (d > w->unk_188) {
            d = w->unk_188;
            w->unk_188 = d + 2;
        } else if (d < -w->unk_188) {
            d = -w->unk_188;
            w->unk_188 += 2;
        } else {
            w->unk_188 = d < 0 ? -d : d;
        }

        act->unk_008 += d;

        if ((work->base.unk_158 & 2)
                || ((w->unk_18C - act->unk_004 < 0
                        ? act->unk_004 - w->unk_18C
                        : w->unk_18C - act->unk_004) <= 0x7FF
                    && (w->unk_190 - act->unk_008 < 0
                        ? act->unk_008 - w->unk_190
                        : w->unk_190 - act->unk_008) <= 0x7FF)) {
            work->base.unk_14C = 22;
            work->base.unk_154 = 0;
        } else {
            work->base.unk_154++;
        }
        break;
    case 22:
        func_08019068(gUnk_0813E4EC, &w->base.anim, 4, 0, w->base.tiles);
        work->base.unk_168 -= 25;

        if (act->unk_00C >= act->unk_010) {
            work->base.unk_14C = work->base.unk_150;
            work->base.unk_154 = 0;
        }
        break;
    case 18:
        if (work->base.unk_154 == 0) {
            func_08019068(gUnk_0813E4EC, &w->base.anim, 0, 0, w->base.tiles);
        }

        {
            s32 currentX;
            s32 targetX;
            s32 adjustedX;

            if (act->unk_034 & 4) {
                targetX = 0x3000;
                currentX = act->unk_004;
                adjustedX = currentX + targetX;
            } else {
                targetX = -0x3000;
                currentX = act->unk_004;
                adjustedX = currentX + targetX;
            }

            targetX = act->unk_014;
            targetX -= adjustedX;
            targetX >>= 4;
            currentX += targetX;
            act->unk_004 = currentX;
        }

        frame = AnimGetFrame(&work->base.anim);

        if (frame >= 3 && frame <= 6) {
            work->base.unk_168 = 0;
        }

        switch (frame) {
        case 1:
            if (work->base.anim.timer == 0) {
                work->base.unk_168 = -0x400;
            }
            break;
        case 3:
            hitX = EmyFacingX(act, 0x1600);

            if (func_08011F78(0xDC, hitX, act->unk_008, act->unk_00C + 0x800, 10, 10, 10)) {
                m4aSongNumStart(0x249);
            }
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    case 19:
        if (work->base.unk_154 == 0) {
            func_08019068(gUnk_0813E4EC, &w->base.anim, 1, 0, w->base.tiles);
        }

        {
            s32 currentX;
            s32 targetX;
            s32 adjustedX;

            if (act->unk_034 & 4) {
                targetX = 0x4600;
                currentX = act->unk_004;
                adjustedX = currentX + targetX;
            } else {
                targetX = -0x4600;
                currentX = act->unk_004;
                adjustedX = currentX + targetX;
            }

            targetX = act->unk_014;
            targetX -= adjustedX;
            targetX >>= 4;
            currentX += targetX;
            act->unk_004 = currentX;
        }

        frame = AnimGetFrame(&work->base.anim);

        if (frame == 4) {
            s32 centerX = EmyFacingX(act, 0);

            if ((act->unk_034 & 4)
                    ? func_08011F78(0xDD, centerX - 0x1800, act->unk_008, act->unk_00C,
                        0x10, 0x10, 10)
                    : func_08011F78(0xDD, centerX + 0x1800, act->unk_008, act->unk_00C,
                        0x10, 0x10, 10)) {
                m4aSongNumStart(0x211);
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    }

    return _0800CDF0(&work->base);
}


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

u8 func_0803DD44(EmyWork* work) {
    BtlObj* act;
    s32 x;
    s32 y;
    s32 d;
    s32 t;
    s32 lo;
    s32 actorX;
    s32 actorY;
    s32 targetY;

    act = &work->unk_03C;
    func_0801C700(act, &x, &y, 0);

    if (x < (gBtlWork->unk_0DA + 0x30) << 8) {
        d = x + 0x28;
    } else if (x > (gBtlWork->unk_0DC - 0x30) << 8) {
        d = x - 0x28;
    } else {
        t = (work->unk_03C.unk_0CE + ((lo = -work->unk_03C.unk_0D0) +
            GetRandom() % (work->unk_03C.unk_0D0 - lo + 1))) << 8;

        if (act->unk_004 < x) {
            d = x - t;
        } else {
            d = x + t;
        }
    }

    targetY = y;
    actorX = act->unk_004;
    actorY = act->unk_008;
    return GetAngle(actorX, actorY, d, targetY);
}

u8 task_emy_82_1(Emy82Work* work) {
    Emy82Work* w;
    BtlObj* act;

    w = work;
    act = &work->base.unk_03C;
    if (_0800CBDC(&work->base)) {
        switch ((u16)(GetRandom() % 3U)) {
        case 0:
            work->base.unk_14C = 18;
            break;
        case 1:
            if (gBtlWork->unk_0EE > 1) {
                work->base.unk_14C = 19;
            } else {
                work->base.unk_14C = 18;
            }
            break;
        case 2:
            work->base.unk_14C = 20;
            break;
        }
    }

    switch (work->base.unk_14C) {
    case 5:
        if (work->base.unk_154 == 0) {
            m4aSongNumStop(0x25F);
        }
        break;
    case 22:
        func_08019068(w->base.unk_15C->unk_04, &w->base.anim, 2, 1, w->base.tiles);
        if (act->unk_00C < act->unk_010 && (gBtlWork->unk_068 & 0x40000)) {
            act->unk_004 += gSineTable[work->base.angle] * work->base.unk_164 >> 8;
            act->unk_008 += -gSineTable[work->base.angle + 64] * work->base.unk_164 >> 8;
            if ((u16)((u32)GetRandom() % work->base.unk_15C->unk_0E) == 0) {
                s32 x;
                func_0801C700(act, &x, 0, 0);
                if (act->unk_004 > x) {
                    act->unk_034 |= 4;
                } else {
                    act->unk_034 &= ~4;
                }
            }
        } else {
            switch (AnimGetFrame(&work->base.anim)) {
            case 6:
                if (work->base.anim.timer > 2 && (u16)(GetRandom() % 15U) == 0) {
                    work->base.unk_14C = work->base.unk_150;
                }
                break;
            case 1:
                if (work->base.anim.timer == 0) {
                    work->base.angle = func_0803DD44(&work->base);
                    func_0801BCF8(act);
                    work->base.unk_168 = -0x3CC;
                }
                break;
            }
        }
        break;
    case 21:
        func_08019068(w->base.unk_15C->unk_04, &w->base.anim, 0, 1, w->base.tiles);
        if ((u16)((u32)GetRandom() % work->base.unk_15C->unk_0E) == 0) {
            s32 x;
            func_0801C700(act, &x, 0, 0);
            if (act->unk_004 > x) {
                act->unk_034 |= 4;
            } else {
                act->unk_034 &= ~4;
            }
        }
        switch (AnimGetGfxIndex(&work->base.anim)) {
        case 0:
            if (work->base.anim.timer == 5 && (u16)((u32)GetRandom() % work->base.unk_15C->unk_0C) == 0) {
                work->base.unk_14C = 22;
                work->base.angle = func_0803DD44(&work->base);
            }
            break;
        case 2:
            if (work->base.anim.timer == 0 && act->unk_00C >= act->unk_010) {
                work->base.unk_168 = -0x4C0;
                func_0801BCF8(act);
            }
            break;
        }
        break;
    case 18:
        {
            s32 d;
            s32 currentX;
            s32 targetX;
            u32 frame;
            s32 hitX;
            if (work->base.unk_154 == 0) {
                func_08019068(gUnk_0813E5A4, &w->base.anim, 3, 0, w->base.tiles);
                work->base.unk_168 = -0x400;
            }
            if (act->unk_034 & 4) {
                targetX = 0x3000;
                currentX = act->unk_004;
                d = currentX + targetX;
            } else {
                targetX = -0x3000;
                currentX = act->unk_004;
                d = currentX + targetX;
            }
            targetX = act->unk_014;
            targetX -= d;
            targetX >>= 4;
            currentX += targetX;
            act->unk_004 = currentX;
            frame = AnimGetFrame(&work->base.anim);
            if (frame > 3) {
                work->base.unk_168 = 0;
            }
            if (frame == 4) {
                if (act->unk_034 & 4) {
                    hitX = act->unk_004 - 0x1400;
                } else {
                    hitX = act->unk_004 + 0x1400;
                }
                if (func_08011F78(0xDE, hitX, act->unk_008, act->unk_00C + 0x800, 10, 10, 20)) {
                    m4aSongNumStart(0x211);
                }
            } else if (frame == 5) {
                if (act->unk_034 & 4) {
                    hitX = act->unk_004 - 0x1800;
                } else {
                    hitX = act->unk_004 + 0x1800;
                }
                if (func_08011F78(0xDE, hitX, act->unk_008, act->unk_00C - 0x2300, 10, 10, 10)) {
                    m4aSongNumStart(0x211);
                }
            }
            if (AnimIsFinished(&work->base.anim)) {
                work->base.unk_14C = 23;
            } else {
                work->base.unk_154++;
            }
        }
        break;
    case 19:
        {
            u32 frame;
            if (work->base.unk_154 == 0) {
                func_08019068(gUnk_0813E5A4, &w->base.anim, 4, 0, w->base.tiles);
            }
            frame = AnimGetFrame(&work->base.anim);
            if (frame > 1) {
                work->base.unk_168 = 0;
            }
            if (work->base.anim.timer == 0) {
                switch (frame) {
                case 1:
                    work->base.unk_168 = -0x100;
                    m4aSongNumStart(0x25F);
                    break;
                case 4:
                    {
                        BtlObj* best = 0;
                        BtlObj* actor;
                        s16 missing = 0;
                        for (actor = ListPoolFirst(&gBtlWork->unk_080); actor;
                             actor = ListPoolNext(&actor->unk_0B8)) {
                            if (actor != act && !(actor->unk_034 & 0x100)) {
                                if (missing <= actor->unk_02E - actor->unk_02C) {
                                    missing = actor->unk_02E - actor->unk_02C;
                                    best = actor;
                                }
                            }
                        }
                        if (best) {
                            m4aSongNumStart(0x204);
                            best->unk_034 |= 0x20;
                            best->unk_020 = 0xFFEC;
                        } else {
                            func_08019190(act, 2);
                        }
                    }
                    break;
                }
            }
            if (AnimIsFinished(&work->base.anim)) {
                work->base.unk_14C = 23;
            } else {
                work->base.unk_154++;
            }
        }
        break;
    case 20:
        {
            u32 frame;
            if (work->base.unk_154 == 0) {
                func_08019068(gUnk_0813E5A4, &w->base.anim, 5, 0, w->base.tiles);
            }
            frame = AnimGetFrame(&work->base.anim);
            if ((u16)(frame - 2) <= 21) {
                work->base.unk_168 = 0;
            }
            if (work->base.anim.timer == 0) {
                switch (frame) {
                case 1:
                    work->base.unk_168 = -0x100;
                    m4aSongNumStart(0x25F);
                    break;
                case 24:
                    work->base.unk_168 = -0x380;
                    if (gBtlWork->unk_0EE <= 3 && (s16)w->unk_184 <= 2) {
                        u32 spawnFailure = 0;
                        s32 x;
                        s32 offset;
                        if (act->unk_034 & 4) {
                            x = act->unk_004;
                            offset = 0x2000;
                        } else {
                            x = act->unk_004;
                            offset = -0x2000;
                        }
                        x += offset;
                        offset = act->unk_008;
                        if (func_0801BDDC(9, x, offset, act->unk_00C - 0xC00) != spawnFailure) {
                            gBtlWork->unk_120++;
                            w->unk_184++;
                        } else {
                            func_08019190(act, 2);
                        }
                    } else {
                        func_08019190(act, 2);
                    }
                    break;
                }
            }
            if (AnimIsFinished(&work->base.anim)) {
                work->base.unk_14C = 23;
            } else {
                work->base.unk_154++;
            }
        }
        break;
    case 23:
        func_08019068(gUnk_0813E5A4, &w->base.anim, 0, 0, w->base.tiles);
        work->base.unk_168 = 0;
        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_14C = 24;
        }
        break;
    case 24:
        func_08019068(gUnk_0813E5A4, &w->base.anim, 1, 0, w->base.tiles);
        if (act->unk_00C >= act->unk_010) {
            work->base.unk_14C = 25;
        }
        break;
    case 25:
        func_08019068(gUnk_0813E5A4, &w->base.anim, 2, 0, w->base.tiles);
        if (AnimGetFrame(&work->base.anim) == 1 && work->base.anim.timer == 0) {
            work->base.unk_168 = -0x333;
        }
        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
        }
        break;
    }
    return _0800CDF0(&work->base);
}


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
    BtlObj* act;
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
        func_08019068(w->base.unk_15C->unk_04, &w->base.anim, 0, 3, w->base.tiles);
        func_0801BCF8(act);
        func_0801C700(act, &pos, 0, 0);

        if (act->unk_004 < pos) {
            act->unk_034 &= ~4;
        } else {
            act->unk_034 |= 4;
        }
        break;
    case 0x12:
        func_08019068(gUnk_0813E66C, &w->base.anim, 0, 0, w->base.tiles);
        c = work->base.anim.timer;

        if (c == 0) {
            switch (AnimGetFrame(&work->base.anim)) {
            case 3:
                func_0801C700(act, &w->unk_19C, &w->unk_1A0, 0);
                break;
            case 5:
                spawn.x = w->unk_19C;
                spawn.y = w->unk_1A0;
                spawn.z = c;
                w->unk_184 = TaskCreate(&w->unk_188, &gTaskDescEmy83B, &spawn);
                break;
            }
        }

        if (AnimIsFinished(&work->base.anim) && !IsTaskActiveNamed(w->unk_184, gTaskDescEmy83B)) {
            func_0800CB4C(&work->base);
        }
        break;
    case 0x13:
        func_08019068(gUnk_0813E66C, &w->base.anim, 1, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_14C = 0x14;
        }
        break;
    case 0x14:
        func_08019068(gUnk_0813E66C, &w->base.anim, 2, 1, w->base.tiles);

        if (AnimGetGfxIndex(&work->base.anim) == 6 && work->base.anim.timer == 0) {
            if (act->unk_034 & 4) {
                spawn.x = act->unk_004 - 0x1000;
                spawn.unk_12 = 1;
            } else {
                spawn.x = act->unk_004 + 0x1000;
                spawn.unk_12 = 0;
            }

            spawn.y = act->unk_008;
            spawn.z = act->unk_00C - 0x1200;
            spawn.unk_14 = 0;
            TaskCreate(&w->unk_188, &gTaskDescEmy83S, &spawn);
            spawn.unk_14 = 1;
            TaskCreate(&w->unk_188, &gTaskDescEmy83S, &spawn);
            spawn.unk_14 = 2;
            TaskCreate(&w->unk_188, &gTaskDescEmy83S, &spawn);
            w->unk_1A4++;
        }

        if (w->unk_1A4 > 2 && AnimIsFinished(&work->base.anim)) {
            work->base.unk_14C = 0x15;
            work->base.unk_154 = 0;
        } else {
            work->base.unk_154++;
        }
        break;
    case 0x15:
        func_08019068(gUnk_0813E66C, &w->base.anim, 3, 0, w->base.tiles);

        if (work->base.unk_154 > 0x28) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    }

    TaskPoolUpdate(&w->unk_188);
    x = act->unk_004;
    y = act->unk_008;
    z = act->unk_00C;
    ret = _0800CDF0(&work->base);

    if (work->base.unk_14C != 0x0B) {
        act->unk_004 = x;
        act->unk_008 = y;
        act->unk_00C = z;
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
    work->palette = LoadObjPalette(gUnk_08F69B84, 0x20);
    work->tiles = AllocObjTiles(0x80, gUnk_08B1B854);
    AnimInit(work->unk_008, gUnk_09EE10A4, gUnk_09EE1090);
    AnimStart(work->unk_008, 0, 0);
    work->x = spawn->x;
    work->y = spawn->y;
    work->z = spawn->z;
    work->unk_030 = 0;
    ColliderInit(&work->unk_034, 0x0C, 4, 0x10);
}

u8 task_emy_83_b_1(Emy83bWork* work) {
    if ((gBtlWork->unk_068 & 0x40) == 0) {
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

        if (AnimGetFrame(work->unk_008) == 1 && work->unk_012 == 0) {
            if (func_08011F78(0xE0, work->x, work->y, work->z, 4, 4, 0x10)) {
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

    ColliderSetPosition(&work->unk_034, work->x, work->y, work->z);
    AnimUpdate(work->unk_008);
    return 1;
}

void task_emy_83_b_2(Emy83bWork* work) {
    void* gfx;
    u16 pri;
    s16 x;
    s16 y;

    gfx = AnimGetGfx(work->unk_008);
    pri = GetBattleSpritePriorityFlags(work->y);
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, 0, pri,
        -0x1004 - ((work->y + 0x400) >> 8) * 4);
}

void task_emy_83_b_3(Emy83bWork* work) {
    ColliderUnregister(&work->unk_034);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_emy_83_s_0(Emy83sWork* work, EmySpawn* spawn) {
    work->palette = LoadObjPalette(gUnk_08F69B84, 0x20);
    work->tiles = LoadObjTiles(gUnk_08B1D846, 0x40);
    work->x = spawn->x;
    work->y = spawn->y;
    work->z = spawn->z;
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

    if (gBtlWork->unk_068 & 0x40) {
        x = work->x + work->unk_018;
        work->x = x;
        y = work->y + work->unk_01C;
        work->y = y;

        if (work->unk_022 % 3 == work->unk_020) {
            if (func_08011F78(0xE1, x, y, work->z, 2, 2, 2) != 0) {
                m4aSongNumStart(0x241);
            }
        }

        work->z += work->unk_014;
        work->unk_014 += 0x14;

        if (work->z < 0) {
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

    pri = GetBattleSpritePriorityFlags(work->y);
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gUnk_08B1D828, work->tiles, work->palette, 0, pri,
        -0x1004 - ((work->y + 0x400) >> 8) * 4);
    WorldToScreen(&x, &y, work->x, work->y, 0);
    DrawSprite(x, y, gUnk_08B1D832, work->tiles, work->palette, 0, pri, -2);
}

void task_emy_83_s_3(Emy83sWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_emy_trump_h_0(EmyWork* work, void* obj) {
    func_0800C778(work, gUnk_0813E744, obj);
}

u8 task_emy_trump_h_1(EmyWork* work) {
    BtlObj* act;

    act = &work->unk_03C;

    if (_0800CBDC(work)) {
        work->unk_14C = 0x13;
    }

    if (work->unk_14C == 3) {
        work->unk_14C = 0x12;
    }

    switch (work->unk_14C) {
    case 0x13:
        func_08019068(gUnk_0813E734, &work->anim, 0, 0, work->tiles);
        func_0800C980(work, 0x19, 8, 0x0A, 0x12B, 0x30, 0x22E, 0x50, 0, 0x18);
        break;
    case 0x12:
        if (work->unk_154 == 0) {
            func_08019068(work->unk_15C->unk_04, &work->anim, 0, 0, work->tiles);
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
    BtlObj* act;

    act = &work->unk_03C;

    if (_0800CBDC(work)) {
        work->unk_14C = 0x13;
    }

    if (work->unk_14C == 3) {
        work->unk_14C = 0x12;
    }

    switch (work->unk_14C) {
    case 0x13:
        func_08019068(gUnk_0813E7B4, &work->anim, 0, 0, work->tiles);
        func_0800C980(work, 0x14, 0x1E, 0x0A, 0x12A, 0x46, 0x22F, 0x10, 0, 0x18);

        if (work->unk_154 == 0x14) {
            work->unk_168 = -0x480;
        }
        break;
    case 0x12:
        if (work->unk_154 == 0) {
            func_08019068(work->unk_15C->unk_04, &work->anim, 0, 0, work->tiles);
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
    work->unk_03C.unk_02E = 0xBB8;
    work->unk_03C.unk_02C = 0xBB8;
    work->unk_03C.unk_034 |= 0x1000;
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
