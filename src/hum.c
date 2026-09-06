#include "macros.h"
#include "hum.h"
#include "gba/keys.h"

void task_hum_cloud_0(CloudWork* work, void* obj) {
    func_0800E168(&work->base, gUnk_0813EF28);
    work->unk_188 = 0;
    work->base.unk_184 = (u32)gUnk_0813EDD0;
}

INCLUDE_ASM("hum/task_hum_cloud_1.s");

void task_hum_cloud_2(HumWork* work) {
    func_0800EFE8(work);
}

void task_hum_cloud_3(HumWork* work) {
    func_0800E380(work);
}

void func_0804B44C(CloudWork* work, s16 a, s32 b) {
    HumWork* w = &work->base;
    HumActor* act = &w->unk_040;

    if (act->unk_34 & 4) {
        work->base.unk_15C = act->unk_04 - (a << 8);
    } else {
        work->base.unk_15C = act->unk_04 + (a << 8);
    }
    w->unk_160 = act->unk_08;
    w->unk_170 = 0x16;
    w->unk_150 = 0;
    work->unk_188 = -b;
}

void func_0804B4BC(CloudWork* work, s32 a, s32 b) {
    work->base.unk_15C = a;
    work->base.unk_160 = b;
    work->base.unk_170 = 0x16;
    work->base.unk_150 = 0;
    work->unk_188 = -0x680;
}

u8 func_0804B4F4(CloudWork* work) {
    s32 x;
    s32 y;
    Collider* c;

    c = gBtlWork->unk_07C;
    func_0801C700(&work->base.unk_040, &x, &y, 0);
    func_0800F368(work, 1);

    if (func_0800F504(work, 0x100, 0x100, 0x100)) {
        if (gBtlWork->unk_068 & 0x8000) {
            func_0804B44C(work, -99, 0x280);
        } else if (GetRandom() & 1) {
            if (c->unk_34 & 4) {
                func_0804B4BC(work, x + 0x2800, y);
            } else {
                func_0804B4BC(work, x - 0x2800, y);
            }
        } else {
            func_0804B44C(work, -80, 0x500);
        }
        return 1;
    }
    return 0;
}

void task_hum_hook_0(HookWork* work, void* arg) {
    TaskCreate(&gBtlWork->unk_02C, gTaskDescHumHookMoon, 0);
    func_0800E168(&work->base, gUnk_0813F05C);
    work->base.unk_040.unk_34 |= 0x10000000;

    if (GetRandom() % 2) {
        work->base.unk_184 = (u32)gUnk_0813EF54;
    } else {
        work->base.unk_184 = (u32)gUnk_0813EF60;
    }
    work->base.unk_154 |= 0x40;
    work->unk_188 = 0;
    work->unk_18C = 0;
    work->unk_190 = 0;
    work->unk_194 = 0;
    work->unk_196 = 0;
    work->unk_198 = 0;
    TaskPoolInit(&work->unk_19C, 3);
}

#ifdef NON_MATCHING
u8 task_hum_hook_1(HookWork* work) {
    HookWork* w;
    HumActor* act;
    HumActor* c;
    VixenNdlArgs args;
    s32 x;
    s32 y;
    s32 z;
    s32 d;
    u16 f;
    u8 a;

    w = work;
    act = &work->base.unk_040;
    c = (HumActor*)gBtlWork->unk_07C;
    func_0801C700(act, &x, &y, &z);

    if (_0800E434(work) == 5) {
        work->base.unk_150 = 0;

        switch (_0800F84C(work)) {
        case 36:
            work->base.unk_170 = 20;
            break;
        case 37:
            work->base.unk_170 = 21;
            break;
        case 38:
            work->base.unk_170 = 19;
            break;
        case 39:
            work->base.unk_170 = 25;
            break;
        case 0xED1AF6BD:
            work->base.unk_170 = 26;
            break;
        case 0xED1B1EC7:
            work->base.unk_170 = 29;
            work->base.unk_152 = 0;
            break;
        }
    }

    if (func_0800F5A4(work, 13, 40, 40, 24)) {
        if (GetRandom() % 2) {
            w->base.unk_184 = (u32)gUnk_0813EF54;
        } else {
            w->base.unk_184 = (u32)gUnk_0813EF60;
        }
    }

    switch (work->base.unk_170) {
    case 12:
    case 18:
        func_08019068(gUnk_0813EF6C, &w->base.anim, 0, 1, w->base.tiles);
        break;
    case 17:
        func_08019068(gUnk_0813EF6C, &w->base.anim, 0, 3, w->base.tiles);

        if (gBtlWork->unk_068 & 0x20000000) {
            if (func_0804B4F4((CloudWork*)w)) {
                break;
            }
        }
        d = act->unk_04 - x;

        if (d >= 0) {
            if (d > 0x3FFF) {
                break;
            }
        } else if (x - act->unk_04 > 0x3FFF) {
            break;
        }

        if (x <= 0xFFFF) {
            func_0804B4BC((CloudWork*)w, (gBtlWork->unk_0DC - 40) << 8,
                (gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7);
        } else {
            func_0804B4BC((CloudWork*)w, (gBtlWork->unk_0DA + 40) << 8,
                (gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7);
        }
        break;
    case 0:
        func_08019068(gUnk_0813EF6C, &w->base.anim, 0, 3, w->base.tiles);

        if (func_08081828()) {
            break;
        }

        if (GetRandom() % 150 == 0) {
            work->base.unk_170 = 8;
            work->base.unk_150 = 0;
            break;
        }

        if (func_0800F4C8(work, 40)) {
            func_0804B4BC((CloudWork*)w, 0x10000,
                (gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7);
            break;
        }

        if (gBtlWork->unk_068 & 0x20000000) {
            if (func_0804B4F4((CloudWork*)w)) {
                break;
            }
        } else {
            func_0800F368(work, 8);
        }
        work->base.unk_150++;
        break;
    case 8:
        func_08019068(gUnk_0813EF6C, &w->base.anim, 1, 3, w->base.tiles);
        work->base.unk_15C = x;
        work->base.unk_160 = y;

        if (func_0800F3BC(work, work->base.unk_15C, y, 358)) {
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
            break;
        }

        if (gBtlWork->unk_068 & 0x20000000) {
            if (func_0804B4F4((CloudWork*)w)) {
                break;
            }
        } else {
            func_0800F368(work, 8);
        }
        work->base.unk_150++;
        break;
    case 3:
        func_08019068(gUnk_0813EF6C, &w->base.anim, 2, 0, w->base.tiles);
        gBtlWork->unk_018 = 0;
        break;
    case 1:
    case 9:
    case 11:
    case 14:
        func_08019068(gUnk_0813EF6C, &w->base.anim, 2, 0, w->base.tiles);
        break;
    case 2:
        if (func_08081828() == 0) {
            break;
        }

        if (GetRandom() % 10 != 0) {
            break;
        }

        if (x <= 0xFFFF) {
            work->base.unk_15C = (gBtlWork->unk_0DC - 40) << 8;
        } else {
            work->base.unk_15C = (gBtlWork->unk_0DA + 40) << 8;
        }
        work->base.unk_160 = (gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7;
        work->base.unk_170 = 23;
        work->base.unk_150 = 0;
        work->base.unk_158 = -0x680;
        break;
    case 26:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 11, 1, w->base.tiles);
        }
        func_0802F284(act->unk_04, act->unk_08, act->unk_0C);
        func_0800F368(work, 1);

        if (act->unk_34 & 4) {
            act->unk_04 += (x + 0x1000 - act->unk_04) >> 4;
        } else {
            act->unk_04 += (x - 0x1000 - act->unk_04) >> 4;
        }
        act->unk_08 += (y - act->unk_08) >> 4;

        if (work->base.anim.timer == 0) {
            switch (AnimGetFrame(&work->base.anim)) {
            case 2:
            case 4:
            case 7:
                func_08019A30();

                if (act->unk_34 & 4) {
                    if (func_08011F78(280, act->unk_04 - 0x1400, act->unk_08, act->unk_0C, 20, 20, 50)) {
                        m4aSongNumStart(0x22E);
                    }
                } else {
                    if (func_08011F78(280, act->unk_04 + 0x1400, act->unk_08, act->unk_0C, 20, 20, 50)) {
                        m4aSongNumStart(0x22E);
                    }
                }
                break;
            }
        }

        if ((s16)work->base.unk_150 > 120) {
            work->base.unk_170 = 27;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 27:
        func_0802F284(act->unk_04, act->unk_08, act->unk_0C);

        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 9, 0, w->base.tiles);
        }
        func_0800F368(work, 1);

        if (act->unk_34 & 4) {
            act->unk_04 += (x + 0x1000 - act->unk_04) >> 4;
        } else {
            act->unk_04 += (x - 0x1000 - act->unk_04) >> 4;
        }
        act->unk_08 += (y - act->unk_08) >> 4;

        if (work->base.anim.timer == 0 && AnimGetFrame(&work->base.anim) == 3) {
            func_08019A30();

            if (act->unk_34 & 4) {
                if (func_08011F78(0x119, act->unk_04 - 0x1400, act->unk_08, act->unk_0C, 20, 20, 50)) {
                    m4aSongNumStart(0x22E);
                }
            } else {
                if (func_08011F78(0x119, act->unk_04 + 0x1400, act->unk_08, act->unk_0C, 20, 20, 50)) {
                    m4aSongNumStart(0x22E);
                }
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_170 = 28;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 28:
        func_0802F284(act->unk_04, act->unk_08, act->unk_0C);

        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 12, 0, w->base.tiles);
            w->unk_1B0 = 0;
            w->unk_1B4 = 0;
            w->unk_1B8 = 0;
            w->unk_198 &= 0xFFFC;
            m4aSongNumStart(198);
        }

        if ((w->unk_198 & 1) == 0) {
            if (AnimGetFrame(&work->base.anim) == 6 && work->base.anim.timer == 0) {
                if (act->unk_34 & 4) {
                    args.unk_00 = act->unk_04 - 0x3200;
                    args.unk_04 = act->unk_08;
                    args.unk_08 = act->unk_0C - 0x1C00;
                    args.unk_12 = 1;
                } else {
                    args.unk_00 = act->unk_04 + 0x3200;
                    args.unk_04 = act->unk_08;
                    args.unk_08 = act->unk_0C - 0x1C00;
                    args.unk_12 = 0;
                }
                args.unk_14 = 1;
                w->unk_1B0 = TaskCreate(&w->unk_19C, gTaskDescHumHookBomb, &args);
                w->unk_1B4 = TaskCreate(&w->unk_19C, gTaskDescHumHookBomb, &args);
                w->unk_1B8 = TaskCreate(&w->unk_19C, gTaskDescHumHookBomb, &args);
                w->unk_198 |= 1;
            }
        } else if (w->unk_198 & 2) {
            if (AnimIsFinished(&work->base.anim)) {
                func_08019068(gUnk_0813EF6C, &w->base.anim, 14, 1, w->base.tiles);
            }
        } else {
            if (AnimIsFinished(&work->base.anim)) {
                func_08019068(gUnk_0813EF6C, &w->base.anim, 13, 0, w->base.tiles);
                w->unk_198 |= 2;
            }
        }

        if ((w->unk_198 & 1) &&
            IsTaskActiveNamed(w->unk_1B0, *(void**)gTaskDescHumHookBomb) == 0 &&
            IsTaskActiveNamed(w->unk_1B4, *(void**)gTaskDescHumHookBomb) == 0 &&
            IsTaskActiveNamed(w->unk_1B8, *(void**)gTaskDescHumHookBomb) == 0) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 25:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 12, 0, w->base.tiles);
            w->unk_1B0 = 0;
            w->unk_198 &= 0xFFFC;
            m4aSongNumStart(198);
        }

        if ((w->unk_198 & 1) == 0) {
            if (AnimGetFrame(&work->base.anim) == 6 && work->base.anim.timer == 0) {
                if (act->unk_34 & 4) {
                    args.unk_00 = act->unk_04 - 0x3200;
                    args.unk_04 = act->unk_08;
                    args.unk_08 = act->unk_0C - 0x1C00;
                    args.unk_12 = 1;
                    args.unk_14 = 0;
                } else {
                    args.unk_00 = act->unk_04 + 0x3200;
                    args.unk_04 = act->unk_08;
                    args.unk_08 = act->unk_0C - 0x1C00;
                    args.unk_12 = 0;
                    args.unk_14 = 0;
                }
                w->unk_1B0 = TaskCreate(&w->unk_19C, gTaskDescHumHookBomb, &args);
                w->unk_198 |= 1;
            }
        } else if (w->unk_198 & 2) {
            if (AnimIsFinished(&work->base.anim)) {
                func_08019068(gUnk_0813EF6C, &w->base.anim, 14, 1, w->base.tiles);
            }
        } else {
            if (AnimIsFinished(&work->base.anim)) {
                func_08019068(gUnk_0813EF6C, &w->base.anim, 13, 0, w->base.tiles);
                w->unk_198 |= 2;
            }
        }

        if ((w->unk_198 & 1) &&
            IsTaskActiveNamed(w->unk_1B0, *(void**)gTaskDescHumHookBomb) == 0) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 29:
        if ((s16)work->base.unk_150 == 0) {
            AnimReset(&work->base.anim);
            func_08019068(gUnk_0813EF6C, &w->base.anim, 12, 0, w->base.tiles);
            w->unk_1B0 = 0;
            w->unk_198 &= 0xFFFE;
            m4aSongNumStart(198);
        }
        func_0800F368(work, 1);

        if ((w->unk_198 & 1) == 0) {
            if (AnimGetFrame(&work->base.anim) == 6 && work->base.anim.timer == 0) {
                if (act->unk_34 & 4) {
                    args.unk_00 = act->unk_04 - 0x3200;
                    args.unk_04 = act->unk_08;
                    args.unk_08 = act->unk_0C - 0x1C00;
                    args.unk_12 = 1;
                } else {
                    args.unk_00 = act->unk_04 + 0x3200;
                    args.unk_04 = act->unk_08;
                    args.unk_08 = act->unk_0C - 0x1C00;
                    args.unk_12 = 0;
                }
                args.unk_14 = 2;
                w->unk_1B0 = TaskCreate(&w->unk_19C, gTaskDescHumHookBomb, &args);
                w->unk_198 |= 1;
            }
        }

        if (w->unk_198 & 1) {
            if ((s16)work->base.unk_152 > 4) {
                if (IsTaskActiveNamed(w->unk_1B0, *(void**)gTaskDescHumHookBomb) == 0) {
                    work->base.unk_150 = 0;
                    func_0801AF08(act);
                    work->base.unk_170 = 0;
                }
            } else {
                work->base.unk_150 = 0;
                work->base.unk_152++;
                work->base.unk_170 = 29;
            }
        } else {
            work->base.unk_150++;
        }
        break;
    case 20:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 9, 0, w->base.tiles);
            m4aSongNumStart(198);
        }
        f = AnimGetFrame(&work->base.anim);

        if (f > 1) {
            if (act->unk_34 & 4) {
                act->unk_04 += (act->unk_14 - 0x1400 - act->unk_04) >> 3;
            } else {
                act->unk_04 += (act->unk_14 + 0x1400 - act->unk_04) >> 3;
            }
        }

        if (f == 2) {
            if (act->unk_34 & 4) {
                if (func_08011F78(0x115, act->unk_04 - 0x2000, act->unk_08, act->unk_0C, 16, 16, 50)) {
                    m4aSongNumStart(0x22E);
                }
            } else {
                if (func_08011F78(0x115, act->unk_04 + 0x2000, act->unk_08, act->unk_0C, 16, 16, 50)) {
                    m4aSongNumStart(0x22E);
                }
            }
        } else if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
            break;
        }
        work->base.unk_150++;
        break;
    case 19:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 8, 0, w->base.tiles);
            m4aSongNumStart(199);
        }
        f = AnimGetFrame(&work->base.anim);

        if (f >= 3 && f <= 5) {
            if (act->unk_34 & 4) {
                act->unk_04 += (act->unk_14 - 0x4000 - act->unk_04) >> 3;
            } else {
                act->unk_04 += (act->unk_14 + 0x4000 - act->unk_04) >> 3;
            }
        }

        switch (f) {
        case 4:
        case 5:
            if (act->unk_34 & 4) {
                if (func_08011F78(0x115, act->unk_04 - 0x4400, act->unk_08, act->unk_0C, 20, 16, 50)) {
                    m4aSongNumStart(0x22E);
                }
            } else {
                if (func_08011F78(0x115, act->unk_04 + 0x4400, act->unk_08, act->unk_0C, 20, 16, 50)) {
                    m4aSongNumStart(0x22E);
                }
            }
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 21:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 10, 0, w->base.tiles);
        }
        func_0800F368(work, 1);
        f = AnimGetFrame(&work->base.anim);

        if ((f == 2 || f == 6) && work->base.anim.timer == 0) {
            if (GetRandom() & 1) {
                m4aSongNumStart(198);
            } else {
                m4aSongNumStart(199);
            }
            a = GetAngle(act->unk_04, act->unk_08, x, y);
            work->base.unk_15C = act->unk_04 + gSineTable[a] * 50;
            work->base.unk_160 = act->unk_08 + -gSineTable[a + 64] * 50;
            func_08019A30();
        }
        act->unk_04 += ((s32)work->base.unk_15C - act->unk_04) >> 3;
        act->unk_08 += ((s32)work->base.unk_160 - act->unk_08) >> 3;

        if (act->unk_34 & 4) {
            if (func_08011F78(278, act->unk_04 - 0x1000, act->unk_08, act->unk_0C, 32, 24, 70)) {
                m4aSongNumStart(0x22F);
            }
        } else {
            if (func_08011F78(278, act->unk_04 + 0x1000, act->unk_08, act->unk_0C, 32, 24, 70)) {
                m4aSongNumStart(0x22F);
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 22:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 3, 0, w->base.tiles);
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 23;
            work->base.unk_158 = w->unk_188;
        } else {
            work->base.unk_150++;
        }
        break;
    case 23:
        act->unk_04 += ((s32)work->base.unk_15C - act->unk_04) >> 4;
        act->unk_08 += ((s32)work->base.unk_160 - act->unk_08) >> 4;
        d = work->base.unk_158;

        if (d < 0) {
            if (d > -0x200) {
                func_08019068(gUnk_0813EF6C, &w->base.anim, 5, 0, w->base.tiles);
            } else {
                func_08019068(gUnk_0813EF6C, &w->base.anim, 4, 0, w->base.tiles);
            }
        } else if (d <= 0x1FF) {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 5, 0, w->base.tiles);
        } else {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 6, 0, w->base.tiles);
        }

        if (act->unk_0C >= 0) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 24;
        } else {
            func_0800F368(work, 1);
            work->base.unk_150++;
        }
        break;
    case 24:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813EF6C, &w->base.anim, 7, 0, w->base.tiles);
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    }

    if ((s16)act->unk_2C > 0) {
        gBtlWork->unk_018 = (gSineTable[(w->unk_194 / 2) & 0xFF] * gUnk_0813F078[w->unk_196]) >> 8;
        w->unk_194++;

        if (w->unk_194 % 512 == 0) {
            w->unk_196++;

            if (w->unk_196 > 7) {
                w->unk_196 = 1;
            }
        }

        if (c->unk_0C >= c->unk_10 && (s16)c->unk_2C > 0 && c->unk_E8 != 2 &&
            !(c->unk_34 & 16)) {
            w->unk_18C += (((s16)GetAngleDiff(0, gBtlWork->unk_018) << 6) - w->unk_18C) >> 4;
            c->unk_04 -= w->unk_18C;
        } else {
            w->unk_18C = 0;
        }

        if (act->unk_0C >= act->unk_10 && (s16)act->unk_2C > 0 && act->unk_E8 != 2 &&
            !(act->unk_34 & 16)) {
            w->unk_190 += (((s16)GetAngleDiff(0, gBtlWork->unk_018) << 6) - w->unk_190) >> 4;
            act->unk_04 -= w->unk_190;
        } else {
            w->unk_190 = 0;
        }
    }
    TaskPoolUpdate(&w->unk_19C);
    return func_0800E5F0(work);
}
#else
INCLUDE_ASM("hum/task_hum_hook_1.s");
#endif

void task_hum_hook_2(HookWork* work) {
    TaskPoolDraw(&work->unk_19C);
    func_0800EFE8(&work->base);
}

void task_hum_hook_3(HookWork* work) {
    TaskPoolDestroy(&work->unk_19C);
    func_0800E380(&work->base);
    gBtlWork->unk_018 = 0;
}

void task_hum_hook_moon_0(HookMoonWork* work) {
    work->tiles = LoadObjTiles(gUnk_08B5A872, 0xC00);
    PushPaletteEffect(0);
    work->palette = LoadObjPalette(gUnk_08F6DC64, 0x20);
    PopPaletteEffect();
    func_0801C298(work->palette[6] + 16, 0);
    work->unk_0A = 0;
    work->unk_08 = 0;
}

u8 task_hum_hook_moon_1(HookMoonWork* work) {
    work->unk_08++;
    return 1;
}

void task_hum_hook_moon_2(HookMoonWork* work) {
    s16 x;
    s16 y;
    u16 v;
    u16 t;
    s32 s;

    x = 248 - (gBtlWork->unk_000 >> 9);
    y = 208 - (gBtlWork->unk_004 >> 9);
    s = gSineTable[(u8)work->unk_08];
    y += s >> 5;
    DrawSprite(x + 64, y - 28, gUnk_08B5A854, work->tiles, work->palette, 0, 0xC00, 0xFFFF);
    DrawSprite(x - 144, y, gUnk_08B5A85E, work->tiles, work->palette, 0, 0xC00, 0xFFFE);
    DrawSprite(x - 88, y, gUnk_08B5A85E, work->tiles, work->palette, 0, 0xC00, 0xFFFE);
    DrawSprite(x - 32, y, gUnk_08B5A85E, work->tiles, work->palette, 0, 0xC00, 0xFFFE);
    DrawSprite(x + 24, y, gUnk_08B5A85E, work->tiles, work->palette, 0, 0xC00, 0xFFFE);
    DrawSprite(x + 80, y, gUnk_08B5A85E, work->tiles, work->palette, 0, 0xC00, 0xFFFE);
    v = func_08006390();
    if (v != 0) {
        switch (_08006338()) {
        case 0:
            t = 9 - v;
            if ((s16)t < 0) {
                t = 0;
            }
            SetBackdropColor(0, 0, t);
            break;
        case 0x7FFF:
            t = v + 9;
            if ((s16)t > 31) {
                t = 31;
            }
            SetBackdropColor(v, v, t);
            break;
        case 31:
            SetBackdropColor(v, 0, 9);
            break;
        case 0x7C00:
            t = v + 9;
            if ((s16)t > 31) {
                t = 31;
            }
            SetBackdropColor(0, 0, t);
            break;
        case 0x3E0:
            SetBackdropColor(0, v, 9);
            break;
        }
        work->unk_0A = 1;
    } else if (work->unk_0A != 0) {
        SetBackdropColor(0, 0, 9);
        work->unk_0A = v;
    }
}

void task_hum_hook_moon_3(HookMoonWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_hum_hook_bomb_0(HookBombWork* work, VixenNdlArgs* args) {
    if (args->unk_12 != 0) {
        work->unk_2C = 1;
    } else {
        work->unk_2C = 0;
    }
    work->unk_04 = LoadObjPalette(gUnk_08F6DC44, 0x20);
    work->unk_00 = AllocObjTiles(0x280, gUnk_08B59E52);
    AnimInit(&work->anim, gUnk_09EE17AC, gUnk_09EE1798);
    AnimStart(&work->anim, 0, 1);
    work->x = args->unk_00;
    work->y = args->unk_04;
    work->z = args->unk_08;
    work->unk_4E = args->unk_14;
    work->unk_3C = 0;
    work->unk_4A = 0;
    work->unk_50 = GetRandom() % 0x201 + 0x14C;
    work->unk_30 = -(GetRandom() % 0x201 + 0x100);

    switch (work->unk_4E) {
    case 0:
        work->unk_34 = GetAngle(work->x, work->y,
            gBtlWork->unk_130, gBtlWork->unk_134);
        work->unk_4C = GetRandom() % 3 + 1;
        work->unk_38 = 0;
        break;
    case 2:
        work->unk_34 = GetAngle(work->x, work->y,
            gBtlWork->unk_130, gBtlWork->unk_134);
        work->unk_4C = 0;
        work->unk_38 = 1;
        break;
    case 1:
    default:
        work->unk_34 = GetRandom();
        work->unk_4C = GetRandom() % 5 + 4;
        work->unk_38 = 0;
        break;
    }
    work->unk_40 = LoadObjTiles(gUnk_08B22CE4, 0x200);
    work->unk_44 = LoadObjPalette(gUnk_08F69BA4, 0x20);
    work->unk_48 = 1;
}

u8 task_hum_hook_bomb_1(HookBombWork* work) {
    if ((gBtlWork->unk_068 & 0x40) == 0) {
        return 0;
    }

    if (work->unk_38 == 0) {
        work->x += gSineTable[work->unk_34] * work->unk_50 >> 8;
        work->y += -gSineTable[work->unk_34 + 64] * work->unk_50 >> 8;
        work->z += work->unk_30;
        work->unk_30 += 64;

        if (work->z > 0) {
            work->z = 0;

            if (work->unk_4A >= work->unk_4C) {
                work->unk_3C = 0;
                work->unk_38 = 1;
                goto anim;
            }
            work->unk_30 = -(GetRandom() % 0x301 + 0x200);

            if (work->unk_4E == 0) {
                work->unk_34 = GetAngle(work->x, work->y,
                    gBtlWork->unk_130, gBtlWork->unk_134);
            } else {
                work->unk_34 = GetRandom();
            }
            work->unk_4A++;
        }

        if (func_08011E3C(work->x, work->y, work->z, 2, 2, 2)) {
            work->unk_3C = 0;
            work->unk_38 = 1;
            goto anim;
        }
    } else {
        if (work->unk_3C == 0) {
            AnimStart(&work->anim, 1, 0);
        }

        if (work->unk_3C <= 17) {
            work->x += gSineTable[work->unk_34] * work->unk_50 >> 8;
            work->y += -gSineTable[work->unk_34 + 64] * work->unk_50 >> 8;
            work->z += work->unk_30;
            work->unk_30 += 64;

            if (work->z > 0) {
                work->z = 0;
                work->unk_30 = -(GetRandom() % 0x301 + 0x200);
                work->unk_34 = GetAngle(work->x, work->y,
                    gBtlWork->unk_130, gBtlWork->unk_134);
            }
        } else if (work->unk_3C == 18) {
            func_08019A30();
            func_08014020(work->x, work->y, work->z);
            work->unk_48 = 0;
        } else if (work->unk_3C > 18) {
            if (func_08011F78(0x117, work->x, work->y, work->z, 24, 24, 24)) {
                m4aSongNumStart(0x264);
            }
        }

        if (work->unk_3C > 17 && func_080128EC() == 0) {
            return 0;
        }
    }
    work->unk_3C++;
anim:
    if (func_0801A8A4(&work->x, &work->y, 0, 0)) {
        work->unk_34 = (u8)(work->unk_34 + 118) + GetRandom() % 21;
    }
    AnimUpdate(&work->anim);
    return 1;
}

void task_hum_hook_bomb_2(HookBombWork* work) {
    void* gfx;
    u16 attr;
    s16 x;
    s16 y;

    if (work->unk_48 == 0) {
        return;
    }
    gfx = AnimGetGfx(&work->anim);
    attr = func_0801AF1C(work->y);

    if (work->unk_2C == 0) {
        attr |= 1;
    }
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->unk_00, work->unk_04, 0, attr,
        -0x1004 - ((work->y + 0x800) >> 8) * 4);
    WorldToScreen(&x, &y, work->x, work->y, 0);
    DrawSprite(x, y, gUnk_08B22CBC, work->unk_40, work->unk_44, 0, attr, 0xFFF0);
}

void task_hum_hook_bomb_3(HookBombWork* work) {
    ReleaseObjTiles(work->unk_40);
    ReleaseObjPalette(work->unk_44);
    ReleaseObjTiles(work->unk_00);
    ReleaseObjPalette(work->unk_04);
}

void func_0804D018(HumWork* work, s32 a) {
    HumActor* act = &work->unk_040;
    s32 t;

    if (a != 0) {
        t = a + gSineTable[gFrameCounter * 4 % 256] * 8;
        work->unk_158 = 0;
        act->unk_0C += (t - act->unk_0C) >> 4;
    }
}

void func_0804D060(AnsemWork* work) {
    HumActor* act = &work->base.unk_040;

    if (act->unk_34 & 4) {
        *(s32*)&work->unk_1C8 += (0x1800 - *(s32*)&work->unk_1C8) >> 3;
    } else {
        *(s32*)&work->unk_1C8 += (-0x1800 - *(s32*)&work->unk_1C8) >> 3;
    }
    *(s32*)&work->unk_1CC += (-0x1200 - *(s32*)&work->unk_1CC) >> 3;
    work->unk_188.unk_28 = act->unk_04 + *(s32*)&work->unk_1C8;
    work->unk_188.unk_2C = act->unk_08;
    work->unk_188.unk_30 = act->unk_0C + *(s32*)&work->unk_1CC;
}

void task_hum_ansem_0(AnsemWork* work) {
    func_0800E168(&work->base, gUnk_0813F1E8);
    func_0800E314(&work->base, &work->unk_188, gUnk_0813F1E0);
    work->unk_1C4 = -0xC00;
    *(s32*)&work->unk_1C8 = 0;
    work->base.unk_174 = -50;
    work->base.unk_184 = (u32)gUnk_0813F0B8;
}

INCLUDE_ASM("hum/task_hum_ansem_1.s");

void task_hum_ansem_2(HumWork* work) {
    func_0800EFE8(work);
}

void task_hum_ansem_3(HumWork* work) {
    func_0800E380(work);
}

void func_0804E3BC(HumWork* work, s32 a) {
    HumActor* act = &work->unk_040;
    s32 t;

    if (a != 0) {
        t = a + gSineTable[gFrameCounter * 4 % 256] * 4;
        work->unk_158 = 0;
        act->unk_0C += (t - act->unk_0C) >> 4;
    }
}

void func_0804E404(AnsemWork* work) {
    HumActor* act = &work->base.unk_040;

    if (work->unk_1CC > 2) {
        LoadObjPaletteBank(((u16*)work->base.palette)[3], gUnk_09617F18);
        work->base.unk_178 = gUnk_09617F18;
        work->unk_1CA &= 0xFFFE;
        work->base.unk_184 = (u32)gUnk_0813F214;
    } else {
        work->unk_1CC++;
    }
    func_0801AF08(act);
}

void task_hum_hades_0(HadesWork* work) {
    func_0800E168(&work->base, gUnk_0813F324);
    func_0800E314(&work->base, &work->unk_188, gUnk_0813F31C);
    work->base.unk_040.unk_34 |= 0x100000;
    work->base.unk_154 |= 0x40;
    work->unk_1CA = 0;
    work->unk_1C4 = -0xA00;
    work->unk_188.unk_34 |= 3;
    work->unk_1D4 = AllocObjTiles(0x80, gUnk_08BAFB62);
    work->unk_1D8 = AllocObjTiles(0x280, gUnk_08BAFB62);
    work->unk_1DC = AllocObjTiles(0x3A0, gUnk_08BAFB62);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);
    AnimInit(&work->unk_1E0, gUnk_09EE1B78, gUnk_09EE1B38);
    AnimStart(&work->unk_1E0, 2, 1);
    AnimInit(&work->unk_1F8, gUnk_09EE1B78, gUnk_09EE1B38);
    AnimStart(&work->unk_1F8, 1, 1);
    AnimInit(&work->unk_210, gUnk_09EE1B78, gUnk_09EE1B38);
    AnimStart(&work->unk_210, 0, 1);
    work->base.unk_184 = (u32)gUnk_0813F214;
}

INCLUDE_ASM("hum/task_hum_hades_1.s");

void task_hum_hades_2(HadesWork* work) {
    HumActor* act;
    HadesSub* e;
    void* gfx;
    u16 attr;
    s32 sx;
    s32 affine;
    s16 x;
    s16 y;
    s32 i;

    func_0800EFE8(&work->base);

    if ((work->unk_1CA & 2) == 0) {
        return;
    }
    act = &work->base.unk_040;

    for (i = 0; i < 2; i++) {
        e = &work->unk_22C[i];
        attr = func_0801AF1C(e->unk_00);

        if (work->unk_27C == 0x100) {
            if ((act->unk_34 & 4) == 0) {
                attr |= 1;
            }
            sx = work->unk_27C;
        } else {
            if ((act->unk_34 & 4) == 0) {
                sx = work->unk_27C;
            } else {
                sx = -work->unk_27C;
            }
        }
        affine = AllocObjAffine(0, sx, work->unk_27C, 0);
        gfx = AnimGetGfx(&work->unk_1E0);
        WorldToScreen(&x, &y, e->unk_04, e->unk_08, e->unk_0C);
        DrawSprite(x, y, gfx, work->unk_1D4, work->palette, affine, attr,
            -0x1005 - (e->unk_00 >> 8) * 4);
        gfx = AnimGetGfx(&work->unk_1F8);
        WorldToScreen(&x, &y, e->unk_10, e->unk_14, e->unk_18);
        DrawSprite(x, y, gfx, work->unk_1D8, work->palette, affine, attr,
            -0x1006 - (e->unk_00 >> 8) * 4);
        gfx = AnimGetGfx(&work->unk_210);
        WorldToScreen(&x, &y, e->unk_1C, e->unk_20, e->unk_24);
        DrawSprite(x, y, gfx, work->unk_1DC, work->palette, affine, attr,
            -0x1007 - (e->unk_00 >> 8) * 4);
    }
}

void task_hum_hades_3(HadesWork* work) {
    ReleaseObjTiles(work->unk_1D4);
    ReleaseObjTiles(work->unk_1D8);
    ReleaseObjTiles(work->unk_1DC);
    ReleaseObjPalette(work->palette);
    func_0800E380(&work->base);
}

void func_0804F8F0(MahluxiaWork* work, s16 a) {
    HumWork* w = &work->base;
    HumActor* act = &w->unk_040;
    s32 v;

    func_0801C700(act, &v, 0, 0);

    if (act->unk_34 & 4) {
        w->unk_15C = act->unk_04 - (a << 8);
    } else {
        w->unk_15C = act->unk_04 + (a << 8);
    }
    w->unk_170 = 20;
    w->unk_150 = 0;
    work->unk_1C4 = -0x300;

    if (act->unk_08 < v) {
        w->unk_160 = (gBtlWork->unk_0DE + 16) << 8;
    } else {
        w->unk_160 = (gBtlWork->unk_0E0 - 16) << 8;
    }
}

void func_0804F9A0(MahluxiaWork* work, s32 a, u16 b) {
    work->base.unk_15C = a;
    work->unk_1C8 = b;
    work->base.unk_170 = 19;
    work->base.unk_150 = 0;
}

u8 func_0804F9C8(MahluxiaWork* work) {
    s32 v;
    Collider* c;

    c = gBtlWork->unk_07C;
    func_0801C700(&work->base.unk_040, &v, 0, 0);
    func_0800F368(work, 1);

    if (func_0800F504(work, 0x100, 0x100, 0x100)) {
        if (gBtlWork->unk_068 & 0x8000) {
            func_0804F8F0(work, -128);
        } else if (GetRandom() & 1) {
            if (c->unk_34 & 4) {
                func_0804F9A0(work, v + 0x2800, 48);
            } else {
                func_0804F9A0(work, v - 0x2800, 48);
            }
        } else {
            func_0804F8F0(work, -128);
        }
        return 1;
    }
    return 0;
}

void func_0804FA70(MahluxiaWork* work, RikuSpawn* dst) {
    HumActor* act = &work->base.unk_040;

    dst->x = act->unk_04;
    dst->y = act->unk_08;
    dst->z = act->unk_0C;

    if (act->unk_34 & 4) {
        dst->unk_0C |= 1;
    } else {
        dst->unk_0C &= 0xFFFE;
    }
    dst->anim = work->base.anim;
    dst->unk_28 = *(u32*)work->base.tiles;
    dst->unk_2C = gBtlWork->unk_024;
}

void func_0804FAD4(MahluxiaWork* work, RikuSpawn* p) {
    HumActor* act;
    HumSub* sub;
    void* gfx;
    u16 attr;
    s32 sx;
    s32 sy;
    s32 affine;
    s16 x;
    s16 y;
    u16 pri;

    sub = work->base.unk_00C;
    gfx = AnimGetGfx(&p->anim);
    act = &work->base.unk_040;

    if (func_080128EC() == 0) {
        gBldCnt = 0xF10;
        SetBlendAlpha(4, 14);
        attr = 0x804;
    } else {
        attr = func_0801AF1C(act->unk_08);
    }

    if (p->unk_0C & 1) {
        sy = p->unk_2C;
        sx = sy;
    } else if (p->unk_2C == 0x100) {
        sy = p->unk_2C;
        sx = sy;
        attr |= 1;
    } else {
        sx = -gBtlWork->unk_024;
        sy = gBtlWork->unk_024;
    }

    if (sy == 0x100 && sx == sy) {
        affine = 0;
    } else if (sy <= 255) {
        affine = AllocObjAffine(0, sx, sy, 0);
    } else {
        affine = AllocObjAffine(0, sx, sy, 1);
    }
    pri = 0xFFF0;
    WorldToScreen(&x, &y, p->x, p->y, p->z);
    func_08002A10(sub->tiles, p->unk_28);
    DrawSprite(x, y, gfx, sub->tiles, work->base.palette, affine, attr, pri);
}

void func_0804FBDC(HumWork* work, s32 a) {
    HumActor* act;
    s32 t;

    if (a != 0) {
        act = &work->unk_040;
        t = a + gSineTable[gFrameCounter * 4 % 256] * 3;
        work->unk_158 = 0;
        act->unk_0C += (t - act->unk_0C) >> 4;
    }
}

void task_hum_mahluxia_0(MahluxiaWork* work) {
    func_0800E168(&work->base, gUnk_0813F450);
    func_0800E314(&work->base, &work->unk_188, gUnk_0813F448);
    work->unk_1D0 = 0;
    work->unk_1C4 = -0x300;
    work->unk_188.unk_34 |= 3;
    work->unk_1D8 = 0;
    func_08019068(gUnk_0813F368, &work->base.anim, 0, 1, work->base.tiles);
    func_0804FA70(work, &work->unk_1DC[0]);
    work->unk_1DC[1] = work->unk_1DC[0];
    work->unk_1DC[2] = work->unk_1DC[0];
    work->unk_1DC[3] = work->unk_1DC[0];
    work->unk_1DC[4] = work->unk_1DC[0];
    work->unk_1DC[5] = work->unk_1DC[0];
    work->unk_1DC[6] = work->unk_1DC[0];
    work->unk_1DC[7] = work->unk_1DC[0];
    work->unk_1DC[8] = work->unk_1DC[0];
    TaskPoolInit(&work->unk_390, 22);
    work->base.unk_184 = (u32)gUnk_0813F35C;
}

void func_0804FD7C(MahluxiaWork* work) {
    HumActor* act = &work->base.unk_040;
    VixenNdlArgs args;
    s32 range;

    if (gFrameCounter % 5 == 0) {
        args.unk_00 = act->unk_04;
        args.unk_04 = act->unk_08;
        args.unk_08 = act->unk_0C - ((s16)act->unk_A2 << 8);
        range = 0x2000;
        args.unk_00 += ((GetRandom() % 65) << 8) - range;
        range = 0x1000;
        args.unk_04 += ((GetRandom() % 33) << 8) - range;
        args.unk_08 += ((GetRandom() % 41) << 8) - range;
        TaskCreate(&work->unk_390, gTaskDescHumMahluxiaFlw, &args);
    }
}

#ifdef NON_MATCHING
u8 task_hum_mahluxia_1(MahluxiaWork* work) {
    MahluxiaWork* w;
    HumActor* act;
    s32 x;
    s32 y;
    s32 z;
    u16 n;

    w = work;
    act = &work->base.unk_040;
    func_0801C700(act, &x, &y, &z);
    work->unk_1D0 &= ~2;

    switch (_0800E434(work)) {
    case 5:
        work->base.unk_150 = 0;
        w->unk_1C4 = 0;

        switch (_0800F84C(work)) {
        case 36:
            work->base.unk_170 = 21;
            break;
        case 37:
            work->base.unk_170 = 27;
            break;
        case 38:
        case 39:
            work->base.unk_170 = 28;
            break;
        case 0xF71D9F71:
            work->base.unk_170 = 26;
            break;
        case 0xF7BDC767:
            work->base.unk_170 = 22;
            break;
        }
        break;
    case 4:
        w->unk_188.unk_34 |= 2;
        break;
    }

    if (func_0800F5A4(&work->base, 4, 40, 40, 24)) {
        if (GetRandom() % 2) {
            work->base.unk_184 = (u32)gUnk_0813F35C;
        } else {
            work->base.unk_184 = (u32)gUnk_0813F350;
        }
    }

    switch (work->base.unk_170) {
    case 12:
    case 18:
        func_08019068(gUnk_0813F368, &w->base.anim, 0, 1, w->base.tiles);
        break;
    case 17:
        func_08019068(gUnk_0813F368, &w->base.anim, 0, 1, w->base.tiles);

        if (gBtlWork->unk_068 & 0x20000000) {
            if (func_0804F9C8(w)) {
                break;
            }
        }

        if (act->unk_04 - x >= 0 ? act->unk_04 - x <= 0x4FFF : x - act->unk_04 <= 0x4FFF) {
            if (x > 0xFFFF) {
                func_0804F9A0(w, (gBtlWork->unk_0DA + 60) << 8, 48);
            } else {
                func_0804F9A0(w, (gBtlWork->unk_0DC - 60) << 8, 48);
            }
        }
        break;
    case 0:
        func_08019068(gUnk_0813F368, &w->base.anim, 0, 1, w->base.tiles);
        w->unk_1C4 = -0x300;

        if (func_08081828()) {
            break;
        }

        if (act->unk_04 - x >= 0 ? act->unk_04 - x > 0x2800 : x - act->unk_04 > 0x2800) {
            if (GetRandom() % 80 == 0) {
                work->base.unk_170 = 8;
                work->base.unk_150 = 0;
                break;
            }
        }

        if (func_0800F4C8(work, 40)) {
            func_0804F9A0(w, 0x10000, 48);
            break;
        }

        if (gBtlWork->unk_068 & 0x20000000) {
            if (func_0804F9C8(w)) {
                break;
            }
        } else {
            func_0800F368(work, 8);
        }
        work->base.unk_150++;
        break;
    case 8:
        func_08019068(gUnk_0813F368, &w->base.anim, 1, 1, w->base.tiles);
        work->base.unk_15C = x;
        work->base.unk_160 = y;

        if (func_0800F3BC(&work->base, work->base.unk_15C, work->base.unk_160, 358)) {
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
            break;
        }

        if (gBtlWork->unk_068 & 0x20000000) {
            if (func_0804F9C8(w)) {
                break;
            }
        } else {
            func_0800F368(work, 30);
        }
        work->base.unk_150++;
        break;
    case 1:
        func_0804FD7C(w);
    case 3:
    case 9:
    case 11:
    case 14:
        func_08019068(gUnk_0813F368, &w->base.anim, 2, 0, w->base.tiles);
        break;
    case 20:
        func_08019068(gUnk_0813F368, &w->base.anim, 1, 0, w->base.tiles);
        act->unk_04 += ((s32)work->base.unk_15C - act->unk_04) >> 4;
        act->unk_08 += ((s32)work->base.unk_160 - act->unk_08) >> 4;

        if ((work->base.unk_154 & 1)
                || ((s32)work->base.unk_15C - act->unk_04 >= 0
                    ? (s32)work->base.unk_15C - act->unk_04 <= 0x7FF
                    : act->unk_04 - (s32)work->base.unk_15C <= 0x7FF)) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 0;
            break;
        }
        func_0800F368(work, 1);
        func_0804FD7C(w);
        w->unk_1D0 |= 2;
        work->base.unk_150++;
        break;
    case 19:
        if ((s16)work->base.unk_150 == 0) {
            w->unk_1CA = 60;
            w->unk_1CC = 0;
            w->unk_1D4 = act->unk_08;

            if (((gBtlWork->unk_0DE + gBtlWork->unk_0E0) << 7) < act->unk_08) {
                w->unk_1D0 &= ~1;
            } else {
                w->unk_1D0 |= 1;
            }
            func_08019068(gUnk_0813F368, &w->base.anim, 1, 1, w->base.tiles);
        }

        if ((s16)w->unk_1CA != 0) {
            func_0800592C(&act->unk_04, work->base.unk_15C, w->unk_1CA);
            func_0800592C(&w->unk_1CC, 128, w->unk_1CA);

            if (w->unk_1D0 & 1) {
                act->unk_08 = w->unk_1D4 + gSineTable[(u8)w->unk_1CC] * w->unk_1C8;
            } else {
                act->unk_08 = w->unk_1D4 - gSineTable[(u8)w->unk_1CC] * w->unk_1C8;
            }
            w->unk_1CA--;
        }
        func_0804FD7C(w);

        if ((s16)w->unk_1CA <= 0) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 0;
            break;
        }
        func_0800F368(work, 3);
        w->unk_1D0 |= 2;
        work->base.unk_150++;
        break;
    case 22:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F368, &w->base.anim, 4, 0, w->base.tiles);
        }
        w->unk_1D0 |= 2;

        if (!AnimIsFinished(&work->base.anim)) {
            work->base.unk_150++;
            break;
        }
        work->base.unk_170 = 23;
        work->base.unk_150 = 0;
        break;
    case 23:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F368, &w->base.anim, 5, 1, w->base.tiles);
        }
        act->unk_08 += (y - act->unk_08) >> 2;
        n = work->base.unk_150;

        if ((s16)n > 60) {
            work->base.unk_170 = 24;
            work->base.unk_150 = 0;
            break;
        }
        work->base.unk_150 = n + 1;
        break;
    case 24:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F368, &w->base.anim, 6, 0, w->base.tiles);
        }
        w->unk_1D0 |= 2;

        if (!AnimIsFinished(&work->base.anim)) {
            work->base.unk_150++;
            break;
        }
        work->base.unk_170 = 25;
        work->base.unk_150 = 0;
        break;
    case 25:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F368, &w->base.anim, 7, 0, w->base.tiles);
            m4aSongNumStart(0x116);
        }
        w->unk_1D0 |= 2;

        switch (AnimGetFrame(&work->base.anim)) {
        case 1:
            if (work->base.anim.timer == 0) {
                func_0800F368(work, 1);
                func_0801836C(act->unk_04, act->unk_08, act->unk_0C, x - act->unk_04, 316);
            }
            break;
        case 2:
            if (work->base.anim.timer == 0) {
                if (act->unk_34 & 4) {
                    if (func_08011F78(0x13B, act->unk_04 - 0x2800, act->unk_08, act->unk_0C, 40, 12, 64)) {
                        m4aSongNumStart(0x20D);
                    }
                } else {
                    if (func_08011F78(0x13B, act->unk_04 + 0x2800, act->unk_08, act->unk_0C, 40, 12, 64)) {
                        m4aSongNumStart(0x20D);
                    }
                }
            }
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            if (func_080128EC() == 0) {
                func_0801AF08(act);
                work->base.unk_170 = 0;
                work->base.unk_150 = 0;
                break;
            }
        }
        work->base.unk_150++;
        break;
    case 28:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F368, &w->base.anim, 10, 0, w->base.tiles);
            m4aSongNumStart(0x119);
        }
        w->unk_1D0 |= 2;

        if (act->unk_34 & 4) {
            act->unk_04 = act->unk_04 - 0x105;
        } else {
            act->unk_04 = act->unk_04 + 0x105;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_170 = 29;
            work->base.unk_150 = 0;
            break;
        }
        work->base.unk_150++;
        break;
    case 29:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F368, &w->base.anim, 11, 0, w->base.tiles);
            func_08006120(2, 20);
            m4aSongNumStart(0x2C2);
            func_080063A8();
            gBtlWork->unk_072 = 20;
            w->unk_1D0 |= 2;

            if (act->unk_34 & 4) {
                act->unk_04 -= 0x5000;
                func_08011F78(0x13F, act->unk_04 + 0x2800, act->unk_08, 0, 40, 16, 40);
            } else {
                act->unk_04 += 0x5000;
                func_08011F78(0x13F, act->unk_04 - 0x2800, act->unk_08, 0, 40, 16, 40);
            }
        }
        n = work->base.unk_150;

        if ((s16)n > 60) {
            work->base.unk_170 = 30;
            work->base.unk_150 = 0;
            break;
        }
        work->base.unk_150 = n + 1;
        break;
    case 30:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F368, &w->base.anim, 12, 0, w->base.tiles);
        }
        w->unk_1D0 |= 2;

        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
            break;
        }
        work->base.unk_150++;
        break;
    case 26:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F368, &w->base.anim, 8, 0, w->base.tiles);
            w->unk_1D0 &= ~4;
            m4aSongNumStart(0x117);
        }
        w->unk_1D0 |= 2;

        if (AnimGetFrame(&work->base.anim) == 4) {
            if (work->base.anim.timer == 0) {
                func_08018184(act->unk_04, act->unk_08, act->unk_0C - 0x4D00, 318);
                w->unk_1D0 |= 4;
            }
        }

        if (w->unk_1D0 & 4) {
            func_0804FD7C(w);
        }

        if (AnimIsFinished(&work->base.anim)) {
            if (func_080128EC() == 0) {
                func_0801AF08(act);
                work->base.unk_170 = 0;
                work->base.unk_150 = 0;
                break;
            }
        }
        work->base.unk_150++;
        break;
    case 27:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F368, &w->base.anim, 9, 0, w->base.tiles);
            m4aSongNumStart(0x119);
        }
        w->unk_1D0 |= 2;

        switch (AnimGetFrame(&work->base.anim)) {
        case 4:
            if (work->base.anim.timer == 0) {
                m4aSongNumStart(0x2A9);

                if (act->unk_34 & 4) {
                    func_08017F70(act->unk_04 + 0x1700, act->unk_08, 0, 0x13D);
                } else {
                    func_08017F70(act->unk_04 - 0x1700, act->unk_08, 0, 0x13D);
                }
            }
            break;
        case 5:
            if (work->base.anim.timer == 0) {
                m4aSongNumStart(0x2AA);
            }
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            if (func_080128EC() == 0) {
                func_0801AF08(act);
                work->base.unk_170 = 0;
                work->base.unk_150 = 0;
                break;
            }
        }
        work->base.unk_150++;
        break;
    case 21:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813F368, &w->base.anim, 3, 0, w->base.tiles);
            w->unk_1D0 &= ~4;

            if (act->unk_34 & 4) {
                w->unk_188.unk_28 = act->unk_04 - 0x4600;
            } else {
                w->unk_188.unk_28 = act->unk_04 + 0x4600;
            }
            w->unk_188.unk_30 = 0;
            w->unk_38C = 0;
            m4aSongNumStart(0x119);
        }

        switch (AnimGetFrame(&work->base.anim)) {
        case 0:
        case 1:
        case 2:
        case 3:
            w->unk_1D0 |= 2;
            act->unk_08 += (y - act->unk_08) >> 2;
            w->unk_188.unk_2C = act->unk_08;
            break;
        case 4:
            if (work->base.anim.timer == 0) {
                AnimReset(&w->unk_188.anim);
                func_08019068(gUnk_0813F438, &w->base.unk_00C->anim, 0, 0, w->base.unk_00C->tiles);
                w->unk_1D0 |= 4;
                w->unk_188.unk_34 &= ~2;
                m4aSongNumStart(0x224);

                if (act->unk_34 & 4) {
                    if (func_08011F78(0x13B, act->unk_04 - 0x2800, act->unk_08, act->unk_0C, 40, 12, 64)) {
                        m4aSongNumStart(0x20D);
                    }
                } else {
                    if (func_08011F78(0x13B, act->unk_04 + 0x2800, act->unk_08, act->unk_0C, 40, 12, 64)) {
                        m4aSongNumStart(0x20D);
                    }
                }
                func_0804FD7C(w);
            }
            break;
        case 5:
        case 6:
            func_0804FD7C(w);
            break;
        }

        if ((w->unk_1D0 & 4) == 0) {
            work->base.unk_150++;
            break;
        }
        w->unk_38C += 25;

        if (act->unk_34 & 4) {
            w->unk_188.unk_28 = w->unk_188.unk_28 - w->unk_38C;
        } else {
            w->unk_188.unk_28 = w->unk_188.unk_28 + w->unk_38C;
        }

        switch (AnimGetFrame(&w->unk_188.anim)) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            if (func_08011F78(0x13B, w->unk_188.unk_28, w->unk_188.unk_2C, w->unk_188.unk_30, 8, 4, 64)) {
                m4aSongNumStart(0x28C);
            }
            break;
        default:
            if (func_08011F78(0x13B, w->unk_188.unk_28, w->unk_188.unk_2C, w->unk_188.unk_30, 16, 4, 20)) {
                m4aSongNumStart(0x28C);
            }
            break;
        }

        if (w->unk_188.unk_28 < (gBtlWork->unk_0DA - 32) << 8 ||
            w->unk_188.unk_28 > (gBtlWork->unk_0DC + 32) << 8) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
            w->unk_188.unk_34 |= 2;
            break;
        }
        work->base.unk_150++;
        break;
    }

    if (!(act->unk_34 & 0x2000)) {
        if (act->unk_E8 != 2) {
            func_0804FBDC(&work->base, w->unk_1C4);
        }
    }
    TaskPoolUpdate(&w->unk_390);
    return func_0800E5F0(&work->base);
}
#else
INCLUDE_ASM("hum/task_hum_mahluxia_1.s");
#endif

void task_hum_mahluxia_2(MahluxiaWork* work) {
    func_0800EFE8(&work->base);

    if ((work->unk_1D0 & 2) && (work->unk_188.unk_34 & 2)) {
        switch (work->unk_1D8 % 12) {
        case 0:
        case 2:
        case 4:
        case 6:
        case 8:
        case 10:
            func_0804FAD4(work, &work->unk_1DC[2]);
            break;
        case 1:
        case 3:
        case 7:
            func_0804FAD4(work, &work->unk_1DC[4]);
            break;
        case 5:
        case 9:
            func_0804FAD4(work, &work->unk_1DC[6]);
            break;
        case 11:
            func_0804FAD4(work, &work->unk_1DC[8]);
            break;
        }
        work->unk_1D8++;
    }
    work->unk_1DC[8] = work->unk_1DC[7];
    work->unk_1DC[7] = work->unk_1DC[6];
    work->unk_1DC[6] = work->unk_1DC[5];
    work->unk_1DC[5] = work->unk_1DC[4];
    work->unk_1DC[4] = work->unk_1DC[3];
    work->unk_1DC[3] = work->unk_1DC[2];
    work->unk_1DC[2] = work->unk_1DC[1];
    work->unk_1DC[1] = work->unk_1DC[0];
    func_0804FA70(work, &work->unk_1DC[0]);
    TaskPoolDraw(&work->unk_390);
}

void task_hum_mahluxia_3(MahluxiaWork* work) {
    func_0800E380(&work->base);
    TaskPoolDestroy(&work->unk_390);
}

void func_08050EC4(HumWork* work, s32 a) {
    HumActor* act;
    s32 t;

    if (a != 0) {
        act = &work->unk_040;
        t = a + gSineTable[gFrameCounter * 4 % 256] * 6;
        work->unk_158 = 0;
        act->unk_0C += (t - act->unk_0C) >> 3;
    }
}

void func_08050F10(LaxeneWork* work, s16 a, s16 b) {
    HumActor* act = &work->base.unk_040;
    VixenNdlArgs args;

    if (act->unk_34 & 4) {
        args.unk_00 = act->unk_04 + (a << 8);
        args.unk_12 = 1;
    } else {
        args.unk_00 = act->unk_04 - (a << 8);
        args.unk_12 = 0;
    }
    args.unk_08 = act->unk_0C + (b << 8);
    args.unk_04 = act->unk_08;
    TaskCreate(&work->unk_194, gTaskDescHumLaxeneKnf, &args);
}

void task_hum_laxene_0(LaxeneWork* work) {
    func_0800E168(&work->base, gUnk_0813F588);
    work->unk_18E = 0;
    work->unk_188 = -0x3000;
    work->unk_190 = 0;
    work->base.unk_040.unk_34 |= 0x80000000000;
    work->base.unk_184 = (u32)gUnk_0813F480;
    TaskPoolInit(&work->unk_194, 12);
}

INCLUDE_ASM("hum/task_hum_laxene_1.s");

void task_hum_laxene_2(LaxeneWork* work) {
    func_0800EFE8(&work->base);
    TaskPoolDraw(&work->unk_194);
}

void task_hum_laxene_3(LaxeneWork* work) {
    m4aSongNumStop(0x2A2);
    func_0800E380(&work->base);
    TaskPoolDestroy(&work->unk_194);
}

void task_hum_laxene_knf_0(LaxeneKnfWork* work, VixenNdlArgs* args) {
    work->palette = LoadObjPalette(gUnk_09618458, 0x20);
    work->tiles = LoadObjTiles(gUnk_08BD99F4, 0x2C0);
    AnimInit(&work->anim, gUnk_09EE1DB4, gUnk_09EE1DA4);
    AnimStart(&work->anim, 0, 0);

    if (args->unk_12 != 0) {
        work->unk_2C = 1;
    } else {
        work->unk_2C = 0;
    }
    work->x = args->unk_00;
    work->y = args->unk_04;
    work->z = args->unk_08;
    work->unk_2E = 0;
    work->unk_2D = 1;
    work->unk_3C = 0;
    work->unk_30 = gBtlWork->unk_07C->unk_04;
    work->unk_34 = gBtlWork->unk_07C->unk_08;
    work->unk_38 = gBtlWork->unk_07C->unk_0C;
    work->unk_40 = GetRandom() % 897 + 0x800;
    m4aSongNumStart(0x2A4);
}

u8 task_hum_laxene_knf_1(LaxeneKnfWork* work) {
    Collider* c;

    if ((gBtlWork->unk_068 & 0x40) == 0) {
        return 0;
    }

    if (work->unk_2D == 0) {
        return 0;
    }

    switch (work->unk_3C) {
    case 0:
        if (func_08011F78(0x133, work->x, work->y, work->z, 1, 6, 2)) {
            m4aSongNumStart(0x2A3);
            work->unk_2E = 0;
            work->unk_3C = 1;
            func_08013994(work->x, work->y, work->z + 0x1000);
        } else {
            if (work->unk_2C != 0) {
                work->x = work->x - work->unk_40;
            } else {
                work->x = work->x + work->unk_40;
            }
            work->unk_2E++;
        }
        break;
    case 1:
        if ((s16)work->unk_2E == 0) {
            AnimStart(&work->anim, 1, 0);
        }
        c = gBtlWork->unk_07C;
        work->x += c->unk_04 - work->unk_30;
        work->y += c->unk_08 - work->unk_34;
        work->z += c->unk_0C - work->unk_38;

        if ((s16)work->unk_2E > 30) {
            return 0;
        }
        work->unk_2E++;
        break;
    }
    AnimUpdate(&work->anim);
    work->unk_30 = gBtlWork->unk_07C->unk_04;
    work->unk_34 = gBtlWork->unk_07C->unk_08;
    work->unk_38 = gBtlWork->unk_07C->unk_0C;
    return 1;
}

void task_hum_laxene_knf_2(LaxeneKnfWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 attr;

    gfx = AnimGetGfx(&work->anim);

    if (work->unk_2C != 0) {
        attr = func_0801AF1C(work->y);
    } else {
        attr = func_0801AF1C(work->y) | 1;
    }
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, 0, attr,
        -0x1004 - (work->y >> 8) * 4);

    if (func_080035CC(x, y, 2, 2, 32, 32)) {
        work->unk_2D = 0;
    }
}

void task_hum_laxene_knf_3(LaxeneKnfWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void func_080526A8(HumWork* work, s32 a, s32 b) {
    work->unk_15C = a;
    work->unk_160 = b;
    work->unk_170 = 19;
    work->unk_150 = 0;
}

void func_080526D4(AxcelWork* work, s32 a, s32 b, u16 c) {
    work->unk_208 = c;
    work->unk_20C = a;
    work->unk_210 = b;
}

void func_080526F0(HumWork* work, s32 a) {
    HumActor* act;
    s32 t;

    if (a != 0) {
        act = &work->unk_040;
        t = a + gSineTable[gFrameCounter * 4 % 256] * 3;
        work->unk_158 = 0;
        act->unk_0C += (t - act->unk_0C) >> 4;
    }
}

void func_0805273C(AxcelWork* work, HumSub* sub) {
    s32 args[3];

    if (GetRandom() % 6 == 0) {
        args[0] = sub->unk_28 + (GetRandom() % 29 - 14) * 256;
        args[1] = sub->unk_2C + (GetRandom() % 15 - 7) * 256;
        args[2] = sub->unk_30;
        TaskCreate(&work->unk_220, gTaskDescHumAxcelPtc, args);
    }
}

void task_hum_axcel_0(AxcelWork* work) {
    func_0800E168(&work->base, gUnk_0813F768);
    func_0800E314(&work->base, &work->unk_188, gUnk_0813F760);
    func_0800E314(&work->base, &work->unk_1C4, gUnk_0813F760);
    work->base.unk_040.unk_34 |= 0x04000000;
    work->base.unk_184 = (u32)gUnk_0813F5C8;
    work->unk_206 = 0;
    work->unk_200 = -0x300;
    work->unk_208 = 0;
    work->unk_188.unk_34 |= 2;
    work->unk_1C4.unk_34 |= 2;
    work->tiles = LoadObjTiles(gUnk_08B22BBC, 0x100);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);
    TaskPoolInit(&work->unk_220, 16);
}

INCLUDE_ASM("hum/task_hum_axcel_1.s");

void func_08054100(AxcelWork* work, HumSub* sub) {
    s16 x;
    s16 y;
    s32 affine;
    s32 scale;
    s32 f;

    if ((sub->unk_34 & 2) == 0) {
        if (sub->unk_30 >= 0) {
            affine = 0;
        } else {
            scale = 0x100 - (-sub->unk_30) / 128;
            if (scale <= 127) {
                scale = 128;
            }
            f = 0;

            if (scale > 0x100) {
                f = 1;
            }
            affine = AllocObjAffine(0, scale, scale, f);
        }
        WorldToScreen(&x, &y, sub->unk_28, sub->unk_2C, 0);
        DrawSprite(x, y, gUnk_08B22BA8, work->tiles, work->palette, affine, 0x800, 0xFFFE);
    }
}

void task_hum_axcel_2(AxcelWork* work) {
    func_0800EFE8(&work->base);
    func_08054100(work, &work->unk_188);
    func_08054100(work, &work->unk_1C4);
    TaskPoolDraw(&work->unk_220);
}

void task_hum_axcel_3(AxcelWork* work) {
    m4aSongNumStop(0x28E);
    TaskPoolDestroy(&work->unk_220);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    func_0800E380(&work->base);
}

void task_hum_axcel_ptc_0(AxcelPtcWork* work, s32* args) {
    work->x = args[0];
    work->y = args[1];
    work->z = args[2];
    work->tiles = LoadObjTiles(gUnk_08BF73C6, 0x300);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);
    AnimInit(&work->anim, gUnk_09EE1FC0, gUnk_09EE1F90);

    switch (GetRandom() % 3) {
    case 0:
        AnimStart(&work->anim, 0, 0);
        break;
    case 1:
        AnimStart(&work->anim, 1, 0);
        break;
    case 2:
        AnimStart(&work->anim, 2, 0);
        break;
    }
}

u8 task_hum_axcel_ptc_1(AxcelPtcWork* work) {
    if (AnimIsFinished(&work->anim)) {
        return 0;
    }
    work->gfx = AnimUpdate(&work->anim);
    return 1;
}

void task_hum_axcel_ptc_2(AxcelPtcWork* work) {
    s16 x;
    s16 y;

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, work->gfx, work->tiles, work->palette, 0,
        func_0801AF1C(work->y), -0x1004 - (work->y >> 8) * 4);
}

void task_hum_axcel_ptc_3(AxcelPtcWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void func_08054334(VixenWork* work) {
    VixenSub* p;
    s32 i;

    m4aSongNumStart(0x287);
    p = work->unk_1C4;

    for (i = 0; i < 3; i++) {
        p[i].unk_00 = p[i].unk_01 = 1;
        p[i].unk_04 = (gBtlWork->unk_0DA + 32 +
            GetRandom() % (gBtlWork->unk_0DC - gBtlWork->unk_0DA - 0x3F)) << 8;
        p[i].unk_08 = (gBtlWork->unk_0DE + 16 +
            GetRandom() % (gBtlWork->unk_0E0 - gBtlWork->unk_0DE - 0x1F)) << 8;
    }
}

void func_080543B4(VixenWork* work) {
    VixenSub* p;
    s32 i;
    u8 z;

    z = 0;
    p = work->unk_1C4;

    for (i = 0; i < 3; i++) {
        p->unk_01 = z;
        p->unk_00 = z;
        TaskCreate(&work->unk_1A4, gTaskDescHumVixenIce, &work->unk_1C4[i]);
        p++;
    }
}

void func_080543F4(HumWork* work, s32 a) {
    HumActor* act;
    s32 t;

    if (a != 0) {
        act = &work->unk_040;
        t = a + gSineTable[gFrameCounter * 4 % 256] * 3;
        work->unk_158 = 0;
        act->unk_0C += (t - act->unk_0C) >> 4;
    }
}

void task_hum_vixen_0(VixenWork* work) {
    func_0800E168(&work->base, gUnk_0813F8C8);
    work->unk_188 = 0;
    work->base.unk_040.unk_34 |= 0x08000000;
    work->unk_1A2 = 0;
    TaskPoolInit(&work->unk_1A4, 15);
    func_080543B4(work);
    work->base.unk_184 = (u32)gUnk_0813F7A8;

    if (gGameState.flags & 8) {
        gBtlWork->unk_114 = AllocObjTiles(0x840, 0);
    }
}

#ifdef NON_MATCHING
u8 task_hum_vixen_1(VixenWork* work) {
    VixenWork* w;
    HumActor* act;
    VixenNdlArgs args;
    s32 x;
    s32 y;
    s32 z;
    s32 s;
    u8 ang;
    s32 d;
    s32 v;
    s32 cx;
    s32 ax;
    u16 t;
    u8 r;

    w = work;
    act = &work->base.unk_040;
    func_0801C700(act, &x, &y, &z);

    switch (_0800E434(work)) {
    case 5:
        work->base.unk_150 = 0;

        switch (_0800F84C(work)) {
        case 36:
        case 38:
            w->base.unk_170 = 22;
            break;
        case 37:
        case 39:
            w->base.unk_170 = 21;
            break;
        case 0xF53D7753:
            work->base.unk_170 = 33;
            break;
        case 0xF53D4F5D:
            work->base.unk_170 = 28;
            break;
        case 0xF5DD4F53:
            work->base.unk_170 = 29;
            break;
        case 0xF53D4F53:
            work->base.unk_170 = 23;
            break;
        }
        break;
    case 4:
        m4aSongNumStop(0x288);
        break;
    case 3:
    case 8:
        if (*(s32*)((u8*)act->unk_E4 + 0xF4) == 27) {
            w->base.unk_170 = 37;
            w->base.unk_150 = 0;
        }
        break;
    }

    switch ((u32)gBtlWork->unk_10C) {
    case 164:
        if (func_0800F5A4(w, 30, 40, 40, 24)) {
            w->base.unk_184 = (u32)gUnk_0813F7A8;
        }
        break;
    case 175:
        if (func_0800F5A4(w, 5, 40, 40, 24)) {
            switch (GetRandom() % 3) {
            case 0:
                w->base.unk_184 = (u32)gUnk_0813F7A8;
                break;
            case 1:
                w->base.unk_184 = (u32)gUnk_0813F7C0;
                break;
            case 2:
                w->base.unk_184 = (u32)gUnk_0813F7CC;
                break;
            }
        }
        break;
    default:
        if (func_0800F5A4(w, 30, 40, 40, 24)) {
            switch (GetRandom() % 3) {
            case 0:
                w->base.unk_184 = (u32)gUnk_0813F7A8;
                break;
            case 1:
                w->base.unk_184 = (u32)gUnk_0813F7B4;
                break;
            case 2:
                w->base.unk_184 = (u32)gUnk_0813F7CC;
                break;
            }
        }
        break;
    case 176:
    }

    switch (w->base.unk_170) {
    case 12:
    case 18:
        func_08019068(gUnk_0813F7D8, &work->base.anim, 0, 1, work->base.tiles);
        break;
    case 17:
        func_08019068(gUnk_0813F7D8, &work->base.anim, 0, 1, work->base.tiles);
        work->unk_188 = -0x4000;
        func_0800F368(w, 20);
        break;
    case 0:
        func_08019068(gUnk_0813F7D8, &work->base.anim, 0, 1, work->base.tiles);
        work->unk_188 = 0;

        if (func_08081828() == 0) {
            func_0800F368(w, 80);

            if (AnimIsFinished(&w->base.anim) && GetRandom() % 80 == 0) {
                w->base.unk_170 = 8;
                w->base.unk_150 = 0;
            } else {
                w->base.unk_150++;
            }
        }
        break;
    case 8:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 1, 1, work->base.tiles);
            work->unk_188 = -0xF00;

            if (act->unk_04 <= 0xFFFF) {
                act->unk_34 &= ~4;
                w->base.unk_15C = (gBtlWork->unk_0DC - 48) << 8;
            } else {
                act->unk_34 |= 4;
                w->base.unk_15C = (gBtlWork->unk_0DA + 48) << 8;
            }
            work->unk_1C0 = 0;
        }
        work->unk_1C0 += 17;

        if (work->unk_1C0 > 0x199) {
            work->unk_1C0 = 0x199;
        }

        if (act->unk_34 & 4) {
            act->unk_04 -= work->unk_1C0;
        } else {
            act->unk_04 += work->unk_1C0;
        }

        if (w->base.unk_154 & 1) {
            work->unk_1A2 ^= 1;
        }

        if (work->unk_1A2 & 1) {
            act->unk_08 += work->unk_1C0;
        } else {
            act->unk_08 -= work->unk_1C0;
        }
        d = act->unk_04 - (s32)w->base.unk_15C;

        if (d >= 0) {
            if (d <= 0xBFF) {
                w->base.unk_170 = 0;
                w->base.unk_150 = 0;
            } else {
                w->base.unk_150++;
            }
        } else if ((s32)w->base.unk_15C - act->unk_04 <= 0xBFF) {
            w->base.unk_170 = 0;
            w->base.unk_150 = 0;
        } else {
            w->base.unk_150++;
        }
        break;
    case 1:
    case 3:
    case 9:
    case 11:
    case 14:
        func_08019068(gUnk_0813F7D8, &work->base.anim, 2, 0, work->base.tiles);
        break;
    case 21:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 3, 0, work->base.tiles);
            work->unk_188 = 0;
        }

        if (AnimGetFrame(&w->base.anim) == 3) {
            if (act->unk_34 & 4) {
                act->unk_04 += (act->unk_14 - (act->unk_04 + 0x3200)) >> 2;
            } else {
                act->unk_04 += (act->unk_14 - (act->unk_04 - 0x3200)) >> 2;
            }

            if (act->unk_34 & 4) {
                if (func_08011F78(312, act->unk_04 - 0x2000, act->unk_08, act->unk_0C, 12, 12, 48)) {
                    m4aSongNumStart(0x285);
                }
            } else {
                if (func_08011F78(312, act->unk_04 + 0x2000, act->unk_08, act->unk_0C, 12, 12, 48)) {
                    m4aSongNumStart(0x285);
                }
            }
        }

        if (AnimIsFinished(&w->base.anim)) {
            func_0801AF08(act);
            w->base.unk_170 = 0;
            w->base.unk_150 = 0;
        } else {
            w->base.unk_150++;
        }
        break;
    case 37:
        if ((s16)w->base.unk_150 == 0) {
            AnimReset(&w->base.anim);
            func_08019068(gUnk_0813F7D8, &work->base.anim, 2, 0, work->base.tiles);
        }

        if (AnimIsFinished(&w->base.anim)) {
            w->base.unk_154 &= ~4;
            v = 0;
            *(u16*)((u8*)act->unk_E4 + 0xF8) -= 1;
            act->unk_2C = act->unk_2E / 4;
            act->unk_34 &= ~0x100;
            func_0801AF08(act);
            func_08019190(act, 10);
            w->base.unk_170 = v;
            w->base.unk_150 = v;
        } else {
            w->base.unk_150++;
        }
        break;
    case 22:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 4, 0, work->base.tiles);
            work->unk_188 = 0;
        }

        if (AnimGetFrame(&w->base.anim) == 3 && w->base.anim.timer == 0) {
            if (act->unk_34 & 4) {
                func_08013308(1, act->unk_04 - 0x3700, act->unk_08, act->unk_0C - 0x4000,
                    act->unk_04 - 0x6E00, act->unk_08, -0x1400, 1, 0x139);
            } else {
                func_08013308(1, act->unk_04 + 0x3700, act->unk_08, act->unk_0C - 0x4000,
                    act->unk_04 + 0x6E00, act->unk_08, -0x1400, 0, 0x139);
            }
        }

        if (AnimIsFinished(&w->base.anim) && func_080128EC() == 0) {
            func_0801AF08(act);
            w->base.unk_170 = 0;
            w->base.unk_150 = 0;
        } else {
            w->base.unk_150++;
        }
        break;
    case 23:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 5, 0, work->base.tiles);
            work->unk_188 = 0;
            work->unk_1BC = 0;
        }

        if (AnimIsFinished(&w->base.anim)) {
            w->base.unk_150 = 0;
            w->base.unk_170 = 24;
        } else {
            w->base.unk_150++;
        }
        break;
    case 24:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 6, 1, work->base.tiles);
        }

        if ((s16)w->base.unk_150 > 60) {
            w->base.unk_150 = 0;
            w->base.unk_170 = 25;
        } else {
            w->base.unk_150++;
        }
        break;
    case 25:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 7, 0, work->base.tiles);
        }

        if (AnimIsFinished(&w->base.anim)) {
            w->base.unk_150 = 0;
            w->base.unk_170 = 26;
        } else {
            w->base.unk_150++;
        }
        break;
    case 26:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 4, 0, work->base.tiles);

            if (act->unk_34 & 4) {
                work->unk_198 = act->unk_04 - 0x2000;
                work->unk_1A0 = 192;
            } else {
                work->unk_198 = act->unk_04 + 0x2000;
                work->unk_1A0 = 64;
            }
            work->unk_19C = act->unk_08;
            m4aSongNumStart(276);
            func_0800380C(&work->unk_1E8, *(u16*)((u8*)gBtlWork->unk_114 + 6), gUnk_08EE3A84, 0x7E0);
        }

        if (AnimGetFrame(&w->base.anim) > 2) {
            ang = GetAngle(work->unk_198, work->unk_19C, x, y);
            ApproachAngle(&work->unk_1A0, ang, 3);
            s = abs(gSineTable[(w->base.unk_150 * 2) & 0xFF]);
            s += 384;
            work->unk_198 += (gSineTable[(u8)work->unk_1A0] * s) >> 8;
            work->unk_19C += (-gSineTable[(u8)work->unk_1A0 + 64] * s) >> 8;
            func_0801A8A4(&work->unk_198, &work->unk_19C, 0, 0);
            func_0800F368(w, 1);

            if ((s16)w->base.unk_150 % 9 == 0) {
                args.unk_00 = work->unk_198;
                args.unk_04 = work->unk_19C;
                args.unk_08 = 0;
                args.unk_12 = work->unk_1BC & 7;
                args.unk_18 = &work->unk_1E8;
                work->unk_1BC++;
                TaskCreate(&work->unk_1A4, gTaskDescHumVixenNdl, &args);
            }
        }

        if ((s16)w->base.unk_150 > 360 || (gBtlWork->unk_07C->unk_34 & 0x2000)) {
            w->base.unk_170 = 27;
            w->base.unk_150 = 0;
        } else {
            w->base.unk_150++;
        }
        break;
    case 27:
        if ((s16)w->base.unk_150 > 70) {
            func_0801AF08(act);
            w->base.unk_170 = 0;
            w->base.unk_150 = 0;
        } else {
            w->base.unk_150++;
        }
        break;
    case 28:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 8, 0, work->base.tiles);
            work->unk_188 = 0;
            func_08006238(0, *((u8*)gBtlWork + 0xB3), 8);
        }

        if (AnimGetFrame(&w->base.anim) > 4 && func_080128EC() == 0) {
            m4aSongNumStart(0x115);
            m4aSongNumStart(0x288);
            func_080171FC(9999);
        }

        if ((s16)w->base.unk_150 % 15 == 0) {
            t = gBtlWork->unk_07C->unk_2C;

            if ((s16)t > 1) {
                gBtlWork->unk_07C->unk_2C = t - 1;
            }
        }

        if ((s16)w->base.unk_150 > 300 ||
            ((s16)w->base.unk_150 > 120 && (s16)gBtlWork->unk_07C->unk_2C <= 1)) {
            m4aSongNumStop(0x288);
            func_080061E8(0, 8);
            gBtlWork->unk_068 |= 0x400000;
            func_0801AF08(act);
            w->base.unk_170 = 0;
            w->base.unk_150 = 0;
        } else {
            w->base.unk_150++;
        }
        break;
    case 29:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 9, 0, work->base.tiles);
            work->unk_188 = 0;
        }

        if (AnimIsFinished(&w->base.anim)) {
            w->base.unk_150 = 0;
            w->base.unk_170 = 30;
        } else {
            w->base.unk_150++;
        }
        break;
    case 30:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 10, 1, work->base.tiles);
        }

        if ((s16)w->base.unk_150 > 60) {
            w->base.unk_150 = 0;
            w->base.unk_170 = 31;
        } else {
            w->base.unk_150++;
        }
        break;
    case 31:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 11, 0, work->base.tiles);
        }

        if (AnimIsFinished(&w->base.anim)) {
            w->base.unk_150 = 0;
            w->base.unk_170 = 32;
        } else {
            w->base.unk_150++;
        }
        break;
    case 32:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 4, 0, work->base.tiles);
        }

        if (AnimGetFrame(&w->base.anim) == 3 && w->base.anim.timer == 0) {
            func_08006120(1, 60);
            func_08054334(work);
        }

        if (AnimIsFinished(&w->base.anim) && func_08006314() == 0) {
            func_0801AF08(act);
            w->base.unk_170 = 0;
            w->base.unk_150 = 0;
        } else {
            w->base.unk_150++;
        }
        break;
    case 33:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 12, 0, work->base.tiles);
            work->unk_188 = 0;
        }

        if (AnimIsFinished(&w->base.anim)) {
            w->base.unk_150 = 0;
            w->base.unk_170 = 34;
        } else {
            w->base.unk_150++;
        }
        break;
    case 34:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 13, 1, work->base.tiles);
        }

        if ((s16)w->base.unk_150 > 60) {
            w->base.unk_150 = 0;
            w->base.unk_170 = 35;
        } else {
            w->base.unk_150++;
        }
        break;
    case 35:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 14, 0, work->base.tiles);
            m4aSongNumStart(0x113);
        }

        if (AnimIsFinished(&w->base.anim)) {
            w->base.unk_150 = 0;
            w->base.unk_170 = 36;
        } else {
            w->base.unk_150++;
        }
        break;
    case 36:
        if ((s16)w->base.unk_150 == 0) {
            func_08019068(gUnk_0813F7D8, &work->base.anim, 4, 0, work->base.tiles);
            work->unk_1B8 = 0;
        }

        if (AnimGetFrame(&w->base.anim) == 3 && w->base.anim.timer == 0) {
            args.unk_00 = x;
            args.unk_04 = y;
            args.unk_08 = 0;
            work->unk_1B8 = TaskCreate(&work->unk_1A4, gTaskDescHumVixenFrz, &args);
        }

        if (AnimIsFinished(&w->base.anim) &&
            IsTaskActiveNamed(work->unk_1B8, *(void**)gTaskDescHumVixenFrz) == 0) {
            func_0801AF08(act);
            w->base.unk_170 = 0;
            w->base.unk_150 = 0;
        } else {
            w->base.unk_150++;
        }
        break;
    }

    if (!(act->unk_34 & 0x2000) && act->unk_E8 != 2) {
        func_080543F4(&w->base, work->unk_188);
    }
    r = func_0800E5F0(&w->base);
    cx = gBtlWork->unk_07C->unk_04;
    ax = act->unk_04;

    if ((cx < ax && (act->unk_34 & 4)) || (cx > ax && !(act->unk_34 & 4))) {
        act->unk_34 |= 0x8000;
    } else {
        act->unk_34 &= ~0x8000;
    }
    TaskPoolUpdate(&work->unk_1A4);
    return r;
}
#else
INCLUDE_ASM("hum/task_hum_vixen_1.s");
#endif

void task_hum_vixen_2(VixenWork* work) {
    func_0800EFE8(&work->base);
    TaskPoolDraw(&work->unk_1A4);
}

void task_hum_vixen_3(VixenWork* work) {
    if (gGameState.flags & 8) {
        ReleaseObjTiles(gBtlWork->unk_114);
    }
    func_0800E380(&work->base);
    TaskPoolDestroy(&work->unk_1A4);
}

void task_hum_vixen_ndl_0(VixenNdlWork* work, VixenNdlArgs* args) {
    work->palette = LoadObjPalette(gUnk_08F6DCA4, 0x20);
    work->unk_00 = args->unk_18;
    AnimInit(&work->anim, gUnk_09EE26B0, gUnk_09EE2690);
    AnimStart(&work->anim, 0, 0);
    work->unk_2C = args->unk_12;
    work->x = args->unk_00;
    work->y = args->unk_04 + (GetRandom() % 11 - 5) * 256;
    work->z = args->unk_08;
    work->unk_2D = 0;
    m4aSongNumStart(0x286);

    if ((GetRandom() & 1) != 0) {
        work->unk_2E = 1;
    } else {
        work->unk_2E = 0;
    }
}

u8 task_hum_vixen_ndl_1(VixenNdlWork* work) {
    if ((gBtlWork->unk_068 & 0x40) == 0) {
        return 0;
    }

    if (AnimIsFinished(&work->anim)) {
        return 0;
    }

    switch (AnimGetFrame(&work->anim)) {
    case 1:
    case 2:
        if (work->unk_2D == 0) {
            if (gFrameCounter % 8 == work->unk_2C) {
                func_08011F78(0x13A, work->x, work->y, 0, 4, 4, 16);
            }
        }
        break;
    }

    if (gBtlWork->unk_07C->unk_34 & 0x2000) {
        work->unk_2D = 1;
    }
    AnimUpdate(&work->anim);
    return 1;
}

void task_hum_vixen_ndl_2(VixenNdlWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 attr;

    gfx = AnimGetGfx(&work->anim);
    attr = func_0801AF1C(work->y);

    if (work->unk_2E != 0) {
        attr |= 1;
    }
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->unk_00, work->palette, 0, attr,
        -0x1004 - (work->y >> 8) * 4);
}

void task_hum_vixen_ndl_3(VixenNdlWork* work) {
    ReleaseObjPalette(work->palette);
}

void task_hum_vixen_ice_0(VixenIceWork* work, VixenSub* args) {
    work->palette = LoadObjPalette(gUnk_08F6DCA4, 0x20);
    work->tiles = LoadObjTiles(gUnk_08EE4264, 0x800);
    work->unk_24 = args;
    work->unk_00 = 3;
    AnimInit(&work->anim, gUnk_09EE26CC, gUnk_09EE26B4);
    AnimStart(&work->anim, 0, 0);
    func_080122AC(&work->unk_28, 12, 27, 1);
    func_08012614(&work->unk_28, 1);
}

u8 task_hum_vixen_ice_1(VixenIceWork* work) {
    if (work->unk_24->unk_01 == 0) {
        if (work->unk_24->unk_00 != 0) {
            func_080062F4(((ObjPalette*)work->palette)->unk_06 + 16, 1);
            work->unk_24->unk_00 = 0;
            func_08012614(&work->unk_28, 1);
        }
        return 1;
    }

    if (work->unk_24->unk_00 != 0) {
        func_080062F4(((ObjPalette*)work->palette)->unk_06 + 16, 0);
        work->unk_24->unk_00 = 0;
        work->unk_00 = 0;
        work->unk_84 = 0;
        work->unk_8C = 10;

        switch (GetRandom() % 3) {
        case 0:
            work->unk_90 = 0x100;
            break;
        case 1:
            work->unk_90 = 0xC0;
            break;
        case 2:
            work->unk_90 = 0x80;
            break;
        }
    }

    switch (work->unk_00) {
    case 0:
        if (work->unk_84 == 0) {
            work->unk_86 = 30;
            work->unk_84++;
        }
        ApproachValue(&work->unk_8C, work->unk_90, work->unk_86);
        work->unk_86--;
        if ((s16)work->unk_86 <= 0) {
            func_08012614(&work->unk_28, 0);
            work->unk_00 = 1;
            work->unk_84 = 0;
            work->unk_88 = GetRandom() % 0x259 + 600;
        }
        break;
    case 1:
        if (work->unk_84 == 0) {
            AnimStart(&work->anim, 0, 0);
            work->unk_84++;
        }

        if (GetRandom() % 300 == 0) {
            work->unk_00 = 2;
            work->unk_84 = 0;
        }
        break;
    case 2:
        if (work->unk_84 == 0) {
            AnimStart(&work->anim, 1, 0);
            work->unk_84++;
        }

        if (AnimIsFinished(&work->anim)) {
            work->unk_00 = 1;
            work->unk_84 = 0;
        }
        break;
    }

    switch (work->unk_00) {
    case 1:
    case 2:
        ApproachValue(&work->unk_8C, 10, work->unk_88);
        work->unk_88--;
        if ((s16)work->unk_88 <= 0) {
            work->unk_24->unk_01 = 0;
            work->unk_24->unk_00 = 1;
        }
        ColliderSetRadius(&work->unk_28, work->unk_8C * 27 >> 8);
        func_08012324(&work->unk_28, work->unk_24->unk_04, work->unk_24->unk_08, 0);
        break;
    }
    AnimUpdate(&work->anim);
    return 1;
}

void task_hum_vixen_ice_2(VixenIceWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    s32 s;
    s32 affine;

    if (work->unk_24->unk_01 != 0) {
        gfx = AnimGetGfx(&work->anim);
        WorldToScreen(&x, &y, work->unk_24->unk_04, work->unk_24->unk_08, 0);
        s = work->unk_8C * gBtlWork->unk_024 >> 8;
        if (gBtlWork->unk_018 != 0 || s > 0x100) {
            affine = AllocObjAffine(gBtlWork->unk_018, s, s, 1);
        } else {
            affine = AllocObjAffine(gBtlWork->unk_018, s, s, 0);
        }
        DrawSprite(x, y, gfx, work->tiles, work->palette, affine, 0x800, 0xFFFF);
    }
}

void task_hum_vixen_ice_3(VixenIceWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    func_08012304(&work->unk_28);
}

void task_hum_vixen_frz_0(VixenFrzWork* work, VixenNdlArgs* args) {
    work->palette = LoadObjPalette(gUnk_08F6DCA4, 0x20);
    work->unk_00 = gBtlWork->unk_114;

    if (gGameState.flags & 8) {
        if (gBtlWork->unk_068 & 0x800000000000) {
            work->unk_32 = 2;
        } else {
            work->unk_32 = 1;
        }
    } else {
        work->unk_32 = 0;
    }
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813F91C, &work->anim, 0, 0, work->unk_00);
    work->unk_2C = 0;

    if (gBtlWork->unk_07C->unk_34 & 4) {
        work->unk_34 = 0;
    } else {
        work->unk_34 = 1;
    }
    m4aSongNumStart(0x1FE);
    work->x = args->unk_00;
    work->y = args->unk_04;
    work->z = args->unk_08;
}

u8 task_hum_vixen_frz_1(VixenFrzWork* work) {
    VixenNdlArgs args;
    VixenNdlArgs args2;

    if ((gBtlWork->unk_068 & 0x40) == 0) {
        return 0;
    }

    switch (work->unk_2C) {
    case 1:
        if (work->unk_30 == 0) {
            switch (work->unk_32) {
            case 0:
                func_08019068(gUnk_0813F91C, &work->anim, 2, 0, work->unk_00);
                break;
            case 1:
                func_08019068(gUnk_0813F91C, &work->anim, 7, 0, work->unk_00);
                break;
            case 2:
                func_08019068(gUnk_0813F91C, &work->anim, 10, 0, work->unk_00);
                break;
            }
        }
        work->x = gBtlWork->unk_07C->unk_04;
        work->y = gBtlWork->unk_07C->unk_08;
        work->z = gBtlWork->unk_07C->unk_0C;

        if (AnimIsFinished(&work->anim)) {
            work->unk_2C = 2;
            work->unk_30 = 0;
        } else {
            work->unk_30++;
        }
        break;
    case 2:
        if (work->unk_30 == 0) {
            switch (work->unk_32) {
            case 0:
                func_08019068(gUnk_0813F91C, &work->anim, 4, 0, work->unk_00);
                break;
            case 1:
                func_08019068(gUnk_0813F91C, &work->anim, 8, 0, work->unk_00);
                break;
            case 2:
                func_08019068(gUnk_0813F91C, &work->anim, 11, 0, work->unk_00);
                break;
            }
        }
        work->x = gBtlWork->unk_07C->unk_04;
        work->y = gBtlWork->unk_07C->unk_08;
        work->z = gBtlWork->unk_07C->unk_0C;

        if (gBtlWork->unk_068 & 0x100000) {
            work->unk_2C = 3;
            work->unk_30 = 0;
        } else {
            work->unk_30++;
        }
        break;
    case 3:
        if (work->unk_30 == 0) {
            switch (work->unk_32) {
            case 0:
                func_08019068(gUnk_0813F91C, &work->anim, 6, 0, work->unk_00);
                break;
            case 1:
                func_08019068(gUnk_0813F91C, &work->anim, 9, 0, work->unk_00);
                break;
            case 2:
                func_08019068(gUnk_0813F91C, &work->anim, 12, 0, work->unk_00);
                break;
            }
        }
        work->x = gBtlWork->unk_07C->unk_04;
        work->y = gBtlWork->unk_07C->unk_08;
        work->z = gBtlWork->unk_07C->unk_0C;

        if (AnimIsFinished(&work->anim)) {
            args.unk_00 = work->x;
            args.unk_04 = work->y;
            args.unk_08 = work->z;
            TaskCreate(&gBtlWork->unk_02C, gTaskDescHumVixenFrg, &args);
            work->unk_2C = 6;
            work->unk_30 = 0;
        } else {
            work->unk_30++;
        }
        break;
    case 0:
        if (!AnimIsFinished(&work->anim)) {
            break;
        }

        if (func_08011E3C(work->x, work->y, work->z, 8, 8, 1)) {
            gBtlWork->unk_07C->unk_04 = work->x;
            gBtlWork->unk_07C->unk_08 = work->y;
            gBtlWork->unk_07C->unk_0C = work->z;
            gBtlWork->unk_07C->unk_34 |= 0x100000000200;
            work->unk_2C = 1;
            gBtlWork->unk_068 &= ~0x100000;
            work->unk_30 = 0;
        } else {
            work->unk_2C = 4;
            work->unk_30 = 0;
        }
        break;
    case 4:
        if (work->unk_30 == 0) {
            func_08019068(gUnk_0813F91C, &work->anim, 1, 0, work->unk_00);
        }

        if (AnimIsFinished(&work->anim)) {
            work->unk_2C = 5;
            work->unk_30 = 0;
        } else {
            work->unk_30++;
        }
        break;
    case 5:
        if (work->unk_30 == 0) {
            func_08019068(gUnk_0813F91C, &work->anim, 5, 0, work->unk_00);
        }

        if (AnimIsFinished(&work->anim)) {
            args2.unk_00 = work->x;
            args2.unk_04 = work->y;
            args2.unk_08 = work->z;
            TaskCreate(&gBtlWork->unk_02C, gTaskDescHumVixenFrg, &args2);
            work->unk_2C = 6;
            work->unk_30 = 0;
        } else {
            work->unk_30++;
        }
        break;
    case 6:
        if (work->unk_30 > 80) {
            return 0;
        }
        work->unk_30++;
        break;
    }
    AnimUpdate(&work->anim);
    return 1;
}

void task_hum_vixen_frz_2(VixenFrzWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 attr;

    if (work->unk_2C != 6) {
        gfx = AnimGetGfx(&work->anim);
        attr = func_0801AF1C(work->y) | work->unk_34;
        WorldToScreen(&x, &y, work->x, work->y, work->z);
        DrawSprite(x, y, gfx, work->unk_00, work->palette, 0, attr,
            -0x1004 - (work->y >> 8) * 4);
    }
}

void task_hum_vixen_frz_3(VixenFrzWork* work) {
    ReleaseObjPalette(work->palette);
}

void task_hum_vixen_frg_0(VixenFrgWork* work, VixenNdlArgs* args) {
    VixenFrgSub* e;
    s32 i;
    s32 a;
    s32 b;

    func_0800380C(work, ((ObjPalette*)gBtlWork->unk_114)->unk_06, gUnk_08C1E78C, 0x4C0);
    work->unk_30 = work;
    work->palette = LoadObjPalette(gUnk_08F6DCA4, 0x20);
    work->unk_38 = 0;
    work->unk_21C = 0;

    for (i = 0; i < 15; i++) {
        VixenFrgDef* d = &gUnk_0813FA00[i];
        e = &work->unk_3C[i];
        e->unk_04 = args->unk_00 + (d->unk_00 << 8);
        e->unk_08 = args->unk_04;
        e->unk_0C = args->unk_08 + (d->unk_02 << 8);
        e->unk_1C = d->unk_06;
        e->unk_00 = gUnk_09EE218C[d->unk_04];
        e->unk_10 = GetRandom() % 0x401 - 0x500;
        a = (u8)GetRandom();
        b = GetRandom() % 0x380;
        e->unk_14 = gSineTable[a] * b >> 8;
        e->unk_18 = -gSineTable[a + 64] * (b >> 1) >> 8;
    }
    m4aSongNumStart(0x2A0);
}

u8 task_hum_vixen_frg_1(VixenFrgWork* work) {
    VixenFrgSub* e;
    s32 i;

    if (gBtlWork->unk_068 & 0x200000) {
        return 0;
    }

    for (i = 0; i < 15; i++) {
        e = &work->unk_3C[i];
        e->unk_04 += e->unk_14;
        e->unk_08 += e->unk_18;
        e->unk_0C += e->unk_10;
        e->unk_10 += gBtlWork->unk_12C;

        if (e->unk_0C > 0) {
            e->unk_0C = 0;
            e->unk_10 = -(e->unk_10 >> 1);
            e->unk_14 = e->unk_14 >> 1;
            e->unk_18 = e->unk_18 >> 1;
        }
        func_0801A8A4(&e->unk_04, &e->unk_08, 0, 0);
    }
    work->unk_38++;
    if (work->unk_38 == 50) {
        work->unk_21C = 1;
    }

    if (work->unk_38 > 70) {
        return 0;
    }
    return 1;
}

void task_hum_vixen_frg_2(VixenFrgWork* work) {
    VixenFrgSub* p;
    s16 x;
    s16 y;
    u16 attr;
    s32 i;

    if (work->unk_21C != 0) {
        if (work->unk_38 & 1) {
            return;
        }
    }
    p = work->unk_3C;

    for (i = 0; i < 15; i++) {
        attr = func_0801AF1C(p[i].unk_08) | p[i].unk_1C;
        WorldToScreen(&x, &y, p[i].unk_04, p[i].unk_08, p[i].unk_0C);
        DrawSprite(x, y, p[i].unk_00, work->unk_30, work->palette, 0, attr,
            -0x1004 - (p[i].unk_08 >> 8) * 4);
    }
}

void task_hum_vixen_frg_3(VixenFrgWork* work) {
    ReleaseObjPalette(work->palette);
}

void func_080560AC(HumWork* work, s32 a) {
    HumActor* act;
    s32 t;

    if (a != 0) {
        act = &work->unk_040;
        t = a + gSineTable[gFrameCounter * 4 % 256] * 3;
        work->unk_158 = 0;
        act->unk_0C += (t - act->unk_0C) >> 4;
    }
}

void task_hum_lexceus_0(LexceusWork* work) {
    func_0800E168(&work->base, gUnk_0813FB38);
    work->unk_1CA = 0;
    work->unk_1C4 = 0;
    work->unk_1CC = 0;
    work->unk_1F8 = 0;
    work->unk_1F0 = 0;
    work->unk_1F4 = 0;
    work->unk_1FC = 0;
    work->base.unk_184 = (u32)gUnk_0813FA8C;
    TaskPoolInit(&work->unk_1D8, 3);
}

#ifdef NON_MATCHING
u8 task_hum_lexceus_1(LexceusWork* work) {
    LexceusWork* w;
    HumActor* act;
    Collider* p;
    VixenNdlArgs a1;
    VixenNdlArgs a2;
    s32 x;
    s32 y;
    s32 z;
    s16 dx;
    s16 dy;

    w = work;
    act = &work->base.unk_040;
    p = gBtlWork->unk_07C;
    func_0801C700(act, &x, &y, &z);

    switch (_0800E434(work)) {
    case 5:
        work->base.unk_150 = 0;
        work->base.unk_152 = 0;

        switch (_0800F84C(work)) {
        case 36:
            work->base.unk_170 = 21;
            break;
        case 37:
            work->base.unk_170 = 23;
            break;
        case 38:
        case 39:
            work->base.unk_170 = 27;
            break;
        case 0xF85E3F85:
            work->base.unk_170 = 25;
            break;
        }
        break;
    case 4:
        work->base.unk_168 = work->unk_1D0 = 0x100;
        work->base.unk_16C = work->unk_1D4 = 0x100;
        work->unk_1CC = 0;

        if (work->unk_1F4 != 0) {
            work->unk_1F4 = 0;
            work->unk_1F8 = 420;
        }
        break;
    }
    func_0800F5A4(&work->base, 3, 40, 40, 20);
    w->unk_1C4 = 0;

    switch (work->base.unk_170) {
    case 12:
    case 17:
    case 18:
        func_08019068(gUnk_0813FA98, &w->base.anim, 0, 1, w->base.tiles);
        break;
    case 0:
        func_08019068(gUnk_0813FA98, &w->base.anim, 0, 1, w->base.tiles);

        if (func_08081828()) {
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            if (GetRandom() % 80 == 0) {
                work->base.unk_170 = 8;
                work->base.unk_150 = 0;
                break;
            }
        }
        func_0800F368(work, 10);
        work->base.unk_150++;
        break;
    case 8:
        func_08019068(gUnk_0813FA98, &w->base.anim, 1, 1, w->base.tiles);
        w->unk_1C4 = -0x1000;
        work->base.unk_15C = x;
        work->base.unk_160 = y;

        if (AnimIsFinished(&work->base.anim)) {
            if (func_0800F3BC(&work->base, work->base.unk_15C, work->base.unk_160, 0x100)) {
                work->base.unk_170 = 0;
                work->base.unk_150 = 0;
                break;
            }
        }
        func_0800F368(work, 10);
        work->base.unk_150++;
        break;
    case 1:
        act->unk_108 = act->unk_10C = 0;
        work->base.unk_158 = 0;

        if ((s16)work->base.unk_150 > 5) {
            break;
        }
        work->base.unk_150 = 6;
        act->unk_E2 = 30;
        break;
    case 3:
    case 9:
    case 11:
    case 14:
        func_08019068(gUnk_0813FA98, &w->base.anim, 2, 0, w->base.tiles);
        break;
    case 25:
        if ((s16)work->base.unk_150 == 0) {
            m4aSongNumStart(0x11E);
            func_08019068(gUnk_0813FA98, &w->base.anim, 7, 0, w->base.tiles);
            gBtlWork->unk_068 &= ~0x100000;
        }

        switch (AnimGetFrame(&work->base.anim)) {
        case 2:
            if (work->base.anim.timer == 0) {
                m4aSongNumStart(0x2B7);
            }
            break;
        case 3:
            if (work->base.anim.timer == 0) {
                if (act->unk_34 & 4) {
                    a1.unk_00 = act->unk_04 - 0x2000;
                    a1.unk_12 = 1;
                } else {
                    a1.unk_00 = act->unk_04 + 0x2000;
                    a1.unk_12 = 0;
                }
                a1.unk_04 = act->unk_08;
                a1.unk_08 = 0;
                w->unk_1EC = TaskCreate(&w->unk_1D8, &gTaskDescHumLexRock, &a1);
            }
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 26;
        } else {
            work->base.unk_150++;
        }
        break;
    case 26:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813FA98, &w->base.anim, 8, 0, w->base.tiles);
            gBtlWork->unk_068 |= 0x100000;
        }

        if (IsTaskActiveNamed(w->unk_1EC, gTaskDescHumLexRock.name)) {
            break;
        }

        if (!AnimIsFinished(&work->base.anim)) {
            break;
        }
        work->base.unk_150 = 0;
        work->base.unk_170 = 0;
        func_0801AF08(act);
        break;
    case 23:
        if ((s16)work->base.unk_150 == 0) {
            w->unk_1C4 = 0;
            func_08019068(gUnk_0813FA98, &w->base.anim, 5, 0, w->base.tiles);
            w->unk_1CA &= ~4;
            w->unk_1EC = 0;
            m4aSongNumStart(0x11F);
        }

        if (AnimGetFrame(&work->base.anim) == 3) {
            if (work->base.anim.timer == 2) {
                if (act->unk_34 & 4) {
                    a1.unk_00 = act->unk_04 - 0x1800;
                    a1.unk_12 = 1;
                } else {
                    a1.unk_00 = act->unk_04 + 0x1800;
                    a1.unk_12 = 0;
                }
                a1.unk_04 = act->unk_08;
                a1.unk_08 = act->unk_0C - 0x6000;
                w->unk_1CA |= 4;
                w->unk_1EC = TaskCreate(&w->unk_1D8, &gTaskDescHumLexTmh, &a1);
            }
        }

        if (w->unk_1CA & 4) {
            if (IsTaskActiveNamed(w->unk_1EC, gTaskDescHumLexTmh.name) == 0) {
                work->base.unk_150 = 0;
                work->base.unk_170 = 24;
                break;
            }
        }
        work->base.unk_150++;
        break;
    case 24:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813FA98, &w->base.anim, 6, 0, w->base.tiles);
        }

        if (AnimGetFrame(&work->base.anim) == 2) {
            if (work->base.anim.timer == 10) {
                if (act->unk_34 & 4) {
                    a2.unk_00 = act->unk_04 - 0x700;
                    a2.unk_12 = 1;
                } else {
                    a2.unk_00 = act->unk_04 + 0x700;
                    a2.unk_12 = 0;
                }
                a2.unk_04 = act->unk_08;
                a2.unk_08 = act->unk_0C;
                TaskCreate(&w->unk_1D8, &gTaskDescHumLexTmh0, &a2);
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
            break;
        }
        work->base.unk_150++;
        break;
    case 21:
        if ((s16)work->base.unk_150 == 0) {
            w->unk_1C4 = 0;
            AnimReset(&work->base.anim);
            func_08019068(gUnk_0813FA98, &w->base.anim, 3, 0, w->base.tiles);
            w->unk_1CA &= ~3;
        }

        if (work->base.anim.timer == 0) {
            switch (AnimGetFrame(&work->base.anim)) {
            case 3:
                dx = 9;
                dy = 0;
                break;
            case 4:
                dx = 13;
                dy = 0;
                break;
            case 5:
                dx = 6;
                dy = 6;
                break;
            case 7:
                dx = -21;
                dy = -6;
                break;
            default:
                dx = 0;
                dy = 0;
                break;
            }

            if (!AnimIsFinished(&work->base.anim)) {
                if (act->unk_34 & 4) {
                    act->unk_04 = act->unk_04 - (dx << 8);
                } else {
                    act->unk_04 = act->unk_04 + (dx << 8);
                }
                act->unk_08 = act->unk_08 + (dy << 8);
            }

            if (work->base.anim.timer == 0) {
                if (AnimGetGfxIndex(&work->base.anim) == 5) {
                    func_08019A30();

                    if (act->unk_34 & 4) {
                        if (func_08011F78(0x144, act->unk_04 - 0x3C00, act->unk_08, act->unk_0C, 24, 20, 30)) {
                            m4aSongNumStart(0x2B0);
                            w->unk_1CA |= 1;
                        }
                    } else {
                        if (func_08011F78(0x144, act->unk_04 + 0x3C00, act->unk_08, act->unk_0C, 24, 20, 30)) {
                            m4aSongNumStart(0x2B0);
                            w->unk_1CA |= 1;
                        }
                    }
                }
            }
        }

        if (w->unk_1CA & 1) {
            if (AnimGetFrame(&work->base.anim) == 6) {
                if (work->base.anim.timer == 19) {
                    w->unk_1CA |= 2;
                }
            }
        }

        if (w->unk_1CA & 2) {
            work->base.unk_150 = 0;
            work->base.unk_170 = 22;
            work->base.unk_152++;
        } else if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_150 = 0;
            func_0801AF08(act);
            work->base.unk_170 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 22:
        if ((s16)work->base.unk_150 == 0) {
            w->unk_1C4 = 0;
            AnimReset(&work->base.anim);
            func_08019068(gUnk_0813FA98, &w->base.anim, 4, 0, w->base.tiles);
            w->unk_1CA &= ~1;
        }

        if (work->base.anim.timer == 0) {
            if (AnimGetGfxIndex(&work->base.anim) == 1) {
                func_08019A30();

                if (act->unk_E4->unk_F4 == 49) {
                    if (act->unk_34 & 4) {
                        if (func_08011F78(0x149, act->unk_04 - 0x2800, act->unk_08, act->unk_0C, 24, 20, 55)) {
                            m4aSongNumStart(0x2B0);
                            w->unk_1CA |= 1;
                        }
                    } else {
                        if (func_08011F78(0x149, act->unk_04 + 0x2800, act->unk_08, act->unk_0C, 24, 20, 55)) {
                            m4aSongNumStart(0x2B0);
                            w->unk_1CA |= 1;
                        }
                    }
                } else {
                    if (act->unk_34 & 4) {
                        if (func_08011F78(0x145, act->unk_04 - 0x2800, act->unk_08, act->unk_0C, 24, 20, 55)) {
                            m4aSongNumStart(0x2B0);
                            w->unk_1CA |= 1;
                        }
                    } else {
                        if (func_08011F78(0x145, act->unk_04 + 0x2800, act->unk_08, act->unk_0C, 24, 20, 55)) {
                            m4aSongNumStart(0x2B0);
                            w->unk_1CA |= 1;
                        }
                    }
                }
            }
        }

        if (!AnimIsFinished(&work->base.anim)) {
            work->base.unk_150++;
            break;
        }

        if (act->unk_34 & 4) {
            act->unk_04 = act->unk_04 - 0x1900;
        } else {
            act->unk_04 = act->unk_04 + 0x1900;
        }
        func_08019068(gUnk_0813FA98, &w->base.anim, 0, 1, w->base.tiles);
        work->base.unk_150 = 0;
        func_0801AF08(act);
        work->base.unk_170 = 0;
        break;
    case 27:
        if ((s16)work->base.unk_150 == 0) {
            func_08019068(gUnk_0813FA98, &w->base.anim, 9, 0, w->base.tiles);
            w->unk_1C4 = 0;
            w->unk_200 = gBtlWork->unk_00C;
        }

        if (AnimGetFrame(&work->base.anim) == 3) {
            if (work->base.anim.timer == 0) {
                m4aSongNumStart(0x120);
            }
        }

        switch (AnimGetFrame(&work->base.anim)) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            func_0800F368(work, 1);
            break;
        case 5:
            if (work->base.anim.timer == 0) {
                m4aSongNumStart(0x2B9);

                if ((act->unk_34 & 4) == 0) {
                    w->unk_1F4 = -0x800;
                } else {
                    w->unk_1F4 = 0x800;
                }
                w->unk_1F8 = 10;

                if (act->unk_34 & 4) {
                    func_0801801C(act->unk_04 - 0x3000, act->unk_08 + 0xE00, 0, 0x147);
                } else {
                    func_0801801C(act->unk_04 + 0x3000, act->unk_08 + 0xE00, 0, 0x147);
                }
            }

            if ((s16)work->base.unk_150 % 6 <= 2) {
                gBtlWork->unk_014 = w->unk_200 - 0x4000;
            } else {
                gBtlWork->unk_014 = w->unk_200 + 0x4000;
            }
            break;
        case 6:
            if ((s16)work->base.unk_150 % 6 <= 2) {
                gBtlWork->unk_014 = w->unk_200 - 0x3000;
            } else {
                gBtlWork->unk_014 = w->unk_200 + 0x3000;
            }
            break;
        case 7:
            if ((s16)work->base.unk_150 % 6 <= 2) {
                gBtlWork->unk_014 = w->unk_200 - 0x2000;
            } else {
                gBtlWork->unk_014 = w->unk_200 + 0x2000;
            }
            break;
        case 8:
            if ((s16)work->base.unk_150 % 6 <= 2) {
                gBtlWork->unk_014 = w->unk_200 - 0x1000;
            } else {
                gBtlWork->unk_014 = w->unk_200 + 0x1000;
            }
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
            w->unk_1F4 = 0;
            w->unk_1F8 = 420;
        } else {
            work->base.unk_150++;
        }
        break;
    }

    if (!(act->unk_34 & 0x2000)) {
        if (act->unk_E8 != 2) {
            func_080560AC(&work->base, w->unk_1C4);
        }
    }

    if ((s16)w->unk_1F8 > 0) {
        ApproachValue(&w->unk_1F0, w->unk_1F4, w->unk_1F8);
        w->unk_1F8--;
    }
    gBtlWork->unk_018 = w->unk_1F0 >> 8;

    if (p->unk_0C >= p->unk_10 && (s16)p->unk_2C > 0 && p->unk_E8 != 2 && !(p->unk_34 & 16)) {
        w->unk_1FC += (GetAngleDiff(0, gBtlWork->unk_018) * 64 - w->unk_1FC) >> 4;
        p->unk_04 -= w->unk_1FC;
    } else {
        w->unk_1FC = 0;
    }
    TaskPoolUpdate(&w->unk_1D8);
    return func_0800E5F0(&work->base);
}
#else
INCLUDE_ASM("hum/task_hum_lexceus_1.s");
#endif

void task_hum_lexceus_2(LexceusWork* work) {
    func_0800EFE8(&work->base);

    if (work->unk_1CC > 0) {
        ApproachValue(&work->base.unk_168, work->unk_1D0, work->unk_1CC);
        ApproachValue(&work->base.unk_16C, work->unk_1D4, work->unk_1CC);
        work->unk_1CC--;
    }
    TaskPoolDraw(&work->unk_1D8);
}

void task_hum_lexceus_3(LexceusWork* work) {
    func_0800E380(&work->base);
    TaskPoolDestroy(&work->unk_1D8);
}

void task_hum_lex_tmh_0(LexTmhWork* work, VixenNdlArgs* args) {
    work->unk_04 = LoadObjPalette(gUnk_09618478, 0x20);
    work->unk_00 = AllocObjTiles(0x400, gUnk_08C3724C);
    AnimInit(&work->anim, gUnk_09EE22B0, gUnk_09EE2298);
    AnimStart(&work->anim, 0, 1);

    if (args->unk_12 != 0) {
        work->unk_2C = 1;
    } else {
        work->unk_2C = 0;
    }
    work->x = args->unk_00;
    work->y = args->unk_04;
    work->z = args->unk_08;
    work->unk_34 = gBtlWork->unk_130 + (GetRandom() % 65 - 32) * 256;
    work->unk_38 = gBtlWork->unk_134 + (GetRandom() % 33 - 16) * 256;
    work->unk_30 = 0;
    work->unk_4A = 0;
    work->unk_2D = 0;
    work->unk_3C = -0x980;
    work->unk_40 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    work->unk_44 = LoadObjPalette(gUnk_08F69BA4, 0x20);
    m4aSongNumStart(0x2B1);
}

u8 task_hum_lex_tmh_1(LexTmhWork* work) {
    if ((gBtlWork->unk_068 & 0x40) == 0) {
        return 0;
    }

    if (work->unk_2D != 0) {
        return 0;
    }

    switch (work->unk_30) {
    case 0:
        work->x += (work->unk_34 - work->x) >> 4;
        work->y += (work->unk_38 - work->y) >> 4;
        work->z += work->unk_3C;
        work->unk_3C += 64;

        if (func_08011F78(0x146, work->x, work->y, work->z, 16, 12, 16)) {
            m4aSongNumStart(0x2B3);
            work->unk_4A = 0;
            work->unk_30 = 1;
        } else if (work->z >= 0) {
            m4aSongNumStart(0x2B2);
            work->unk_4A = 0;
            work->unk_30 = 1;
        } else {
            work->unk_4A++;
        }
        break;
    case 1:
        if (work->unk_4A == 0) {
            work->unk_3C = -work->unk_3C >> 1;

            if (gBtlWork->unk_130 < work->x) {
                work->unk_48 = 1;
            } else {
                work->unk_48 = 0;
            }
        }

        if (work->x < (gBtlWork->unk_0DA - 32) << 8 ||
            work->x > (gBtlWork->unk_0DC + 32) << 8) {
            work->unk_2D = 1;
        }

        if (work->unk_48 != 0) {
            work->x += -0x400;
        } else {
            work->x += 0x400;
        }
        work->y += (gBtlWork->unk_134 - work->y) >> 4;
        work->z += work->unk_3C;
        work->unk_3C += 64;

        if (func_08011F78(0x146, work->x, work->y, work->z, 16, 12, 16)) {
            m4aSongNumStart(0x2B3);
        }

        if (work->z >= 0) {
            m4aSongNumStart(0x2B2);
            work->unk_3C = -work->unk_3C >> 1;
            work->z = 0;
        }
        work->unk_4A++;
        break;
    }
    AnimUpdate(&work->anim);
    return 1;
}

void task_hum_lex_tmh_2(LexTmhWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 attr;
    s32 affine;
    s32 scale;

    gfx = AnimGetGfx(&work->anim);

    if (work->unk_2C != 0) {
        attr = func_0801AF1C(work->y);
    } else {
        attr = func_0801AF1C(work->y) | 1;
    }
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->unk_00, work->unk_04, 0, attr,
        -0x1004 - (work->y >> 8) * 4);

    if (work->z >= 0) {
        affine = 0;
    } else {
        scale = 0x100 - (-work->z) / 256;
        if (scale <= 75) {
            scale = 76;
        }
        affine = AllocObjAffine(0, scale, scale, 0);
    }
    WorldToScreen(&x, &y, work->x, work->y, 0);
    DrawSprite(x, y, gUnk_08B22BA8, work->unk_40, work->unk_44, affine, attr, 0xFFF0);
}

void task_hum_lex_tmh_3(LexTmhWork* work) {
    ReleaseObjTiles(work->unk_40);
    ReleaseObjPalette(work->unk_44);
    ReleaseObjTiles(work->unk_00);
    ReleaseObjPalette(work->unk_04);
}

void task_hum_lex_tmh0_0(LexTmh0Work* work, VixenNdlArgs* args) {
    work->palette = LoadObjPalette(gUnk_09618478, 0x20);
    work->tiles = AllocObjTiles(0x400, gUnk_08C3151E);
    AnimInit(&work->anim, gUnk_09EE2288, gUnk_09EE2250);
    AnimStart(&work->anim, 2, 1);

    if (args->unk_12 != 0) {
        work->unk_2C = 1;
    } else {
        work->unk_2C = 0;
    }
    work->x = args->unk_00;
    work->y = args->unk_04;
    work->z = args->unk_08;
    work->unk_30 = 10;
    work->unk_34 = 21;
    m4aSongNumStart(0x2B4);
}

u8 task_hum_lex_tmh0_1(LexTmh0Work* work) {
    if (gBtlWork->unk_068 & 0x40) {
        ApproachValue(&work->unk_30, 0x100, work->unk_34--);

        if (work->unk_34 > 0) {
            AnimUpdate(&work->anim);
            return 1;
        }
    }
    return 0;
}

void task_hum_lex_tmh0_2(LexTmh0Work* work) {
    void* gfx;
    u16 attr;
    s32 sx;
    s32 h;
    s32 affine;
    s16 x;
    s16 y;

    gfx = AnimGetGfx(&work->anim);
    attr = func_0801AF1C(work->y);
    h = work->unk_30;
    if (h == 0x100) {
        if (work->unk_2C == 0) {
            attr |= 1;
        }
        sx = h;
    } else {
        if (work->unk_2C != 0) {
            sx = h;
        } else {
            sx = -h;
        }
    }
    affine = AllocObjAffine(0, sx, 0x100, 0);
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, affine, attr,
        -0x100C - (work->y >> 8) * 4);
}

void task_hum_lex_tmh0_3(LexTmh0Work* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_hum_lex_rock_0(LexRockWork* work, VixenNdlArgs* args) {
    if (args->unk_12 != 0) {
        work->unk_160 = 1;
    } else {
        work->unk_160 = 0;
    }
    work->x = args->unk_00;
    work->y = args->unk_04;
    work->z = args->unk_08;
    work->unk_162 = 0;
    work->unk_164 = 0;
    work->tiles = LoadObjTiles(gUnk_08B22CE4, 0x200);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);
    work->unk_2C0 = 0;
}

u8 task_hum_lex_rock_1(LexRockWork* work) {
    s32 i;
    s32 range;
    LexRockSub* e;
    u32 v;

    if ((gBtlWork->unk_068 & 0x40) == 0) {
        return 0;
    }

    switch (work->unk_162) {
    case 0:
        work->unk_164 = 1;
        work->unk_30 = LoadObjPalette(gUnk_08F6DCC4, 0x20);
        work->unk_00[0] = AllocObjTiles(0xDC0, gUnk_08C42BBE);
        AnimInit(&work->anim[0], gUnk_09EE2338, gUnk_09EE230C);
        AnimStart(&work->anim[0], 0, 0);
        work->unk_162++;
        break;
    case 1:
        if (!AnimIsFinished(&work->anim[0])) {
            break;
        }
        work->unk_162++;
        break;
    case 2:
        ReleaseObjTiles(work->unk_00[0]);
        ReleaseObjPalette(work->unk_30);
        work->unk_164 = 1;
        work->unk_30 = LoadObjPalette(gUnk_08F6DCE4, 0x20);
        work->unk_00[0] = AllocObjTiles(0xDC0, gUnk_08C46790);
        AnimInit(&work->anim[0], gUnk_09EE239C, gUnk_09EE233C);
        AnimStart(&work->anim[0], 0, 0);
        work->z -= 0x4000;
        work->unk_162++;
        break;
    case 3:
        if (gBtlWork->unk_068 & 0x100000) {
            m4aSongNumStart(0x2B8);
            work->unk_162 += 2;
        }
        break;
    case 4:
        if (!AnimIsFinished(&work->anim[0])) {
            break;
        }
        work->unk_162++;
        break;
    case 5:
        work->unk_164 = 12;
        ReleaseObjTiles(work->unk_00[0]);

        for (i = 0; i < 12; i++) {
            e = &work->unk_168[i];
            work->unk_00[i] = AllocObjTiles(0xC0, gUnk_08C46790);
            AnimInit(&work->anim[i], gUnk_09EE239C, gUnk_09EE233C);
            AnimStart(&work->anim[i], GetRandom() % 5 + 2, 3);

            if (work->unk_160 != 0) {
                e->unk_14 = -(GetRandom() % 0x501 + 0x300);
            } else {
                e->unk_14 = GetRandom() % 0x501 + 0x300;
            }
            e->unk_18 = GetRandom() % 0x801 - 0x400;
            e->unk_04 = work->x + ((GetRandom() % 17 - 8) << 8);
            e->unk_08 = work->y + ((GetRandom() % 17 - 8) << 8);
            e->unk_0C = work->z + ((GetRandom() % 17 - 8) << 8);
            e->unk_00 = 0;

            if (GetRandom() % 2) {
                e->unk_10 = -(GetRandom() % 0x701 + 0x100);
            } else {
                e->unk_10 = GetRandom() % 1 + 0x300;
            }
        }
        work->unk_162++;
        work->unk_166 = 0;
        break;
    case 6:
        if (work->unk_2C0 == 0) {
            func_08019A30();

            for (i = 0; i < 12; i++) {
                e = &work->unk_168[i];
                e->unk_04 += e->unk_14;
                e->unk_08 += e->unk_18;
                e->unk_0C += e->unk_10;
                e->unk_10 += 64;

                if (e->unk_0C > 0) {
                    e->unk_0C = 0;
                    e->unk_10 = -(e->unk_10 >> 1);
                }
                v = func_0801A8A4(&e->unk_04, &e->unk_08, 0, 0);

                switch (v) {
                case 3:
                case 4:
                    e->unk_18 = -e->unk_18;
                    break;
                case 1:
                case 2:
                    e->unk_14 = -e->unk_14;
                    break;
                }

                if (e->unk_00 == 0) {
                    if (func_08011F78(0x148, e->unk_04, e->unk_08, e->unk_0C, 4, 4, 4)) {
                        m4aSongNumStart(0x221);
                        e->unk_00 = 1;
                    }
                }
            }
        }

        if (work->unk_166 == 80) {
            work->unk_2C0 = 1;
        }

        if (work->unk_166 > 100) {
            return 0;
        }
        work->unk_166++;
        break;
    }

    for (i = 0; i < work->unk_164; i++) {
        AnimUpdate(&work->anim[i]);
    }
    return 1;
}

void task_hum_lex_rock_2(LexRockWork* work) {
    void* gfx;
    u16 attr;
    s16 x;
    s16 y;
    s32 i;
    LexRockSub* e;

    if (work->unk_2C0 != 0 && (work->unk_166 & 1)) {
        return;
    }

    if (work->unk_164 == 1) {
        gfx = AnimGetGfx(&work->anim[0]);

        if (work->unk_160 != 0) {
            attr = func_0801AF1C(work->y);
        } else {
            attr = func_0801AF1C(work->y) | 1;
        }
        WorldToScreen(&x, &y, work->x, work->y, work->z);
        DrawSprite(x, y, gfx, work->unk_00[0], work->unk_30, 0, attr,
            -0x1006 - (work->y >> 8) * 4);
    } else if (work->unk_164 == 12) {
        for (i = 0; i < work->unk_164; i++) {
            e = &work->unk_168[i];
            gfx = AnimGetGfx(&work->anim[i]);

            if (work->unk_160 != 0) {
                attr = func_0801AF1C(e->unk_08);
            } else {
                attr = func_0801AF1C(e->unk_08) | 1;
            }
            WorldToScreen(&x, &y, e->unk_04, e->unk_08,
                e->unk_0C);
            DrawSprite(x, y, gfx, work->unk_00[i], work->unk_30, 0, attr,
                -0x1006 - (e->unk_08 >> 8) * 4);
            WorldToScreen(&x, &y, e->unk_04, e->unk_08, 0);
            DrawSprite(x, y, gUnk_08B22CBC, work->tiles, work->palette, 0, attr, 0xFFFE);
        }
    }
}

void task_hum_lex_rock_3(LexRockWork* work) {
    s32 i;

    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);

    if (work->unk_164 != 0) {
        ReleaseObjPalette(work->unk_30);

        for (i = 0; i < work->unk_164; i++) {
            ReleaseObjTiles(work->unk_00[i]);
        }
    }
}

void task_hum_mahluxia_flw_0(MahluxiaFlwWork* work, VixenNdlArgs* args) {
    work->palette = LoadObjPalette(gUnk_08F6DC84, 0x20);
    work->tiles = LoadObjTiles(gUnk_08BCB3D8, 0x100);
    work->unk_00 = 0;
    work->x = args->unk_00;
    work->y = args->unk_04;
    work->z = args->unk_08;
    work->unk_2C = GetRandom() % 717 - 358;
    work->unk_28 = -(GetRandom() % 539 + 102);
    AnimInit(&work->anim, gUnk_09EE1CB4, gUnk_09EE1C94);
    AnimStart(&work->anim, GetRandom() & 1, 1);
}

u8 task_hum_mahluxia_flw_1(MahluxiaFlwWork* work) {
    switch (work->unk_00) {
    case 0:
        work->x += work->unk_2C;
        work->z += work->unk_28;
        work->unk_28 += 17;
        if (work->unk_28 > 0x1CC) {
            work->unk_00 = 1;
        }
        break;
    case 1:
        work->x += work->unk_2C;
        work->z += work->unk_28;
        work->unk_28 -= 12;
        if (work->unk_28 < 0) {
            work->unk_28 = GetRandom() % 181 + 204;

            if (work->unk_2C > 0) {
                work->unk_2C = -(GetRandom() % 257 + 128);
            } else {
                work->unk_2C = GetRandom() % 257 + 128;
            }
        }

        if (work->z >= 0) {
            return 0;
        }
        break;
    }
    AnimUpdate(&work->anim);
    return 1;
}

void task_hum_mahluxia_flw_2(MahluxiaFlwWork* work) {
    s16 x;
    s16 y;
    void* gfx;

    gfx = AnimGetGfx(&work->anim);
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, 0, 0x800,
        -0x1004 - (work->y >> 8) * 4);
}

void task_hum_mahluxia_flw_3(MahluxiaFlwWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void func_08057CBC(RikuWork* work, s16 a, s32 b) {
    HumWork* w = &work->base;
    HumActor* act = &w->unk_040;

    if (act->unk_34 & 4) {
        work->base.unk_15C = act->unk_04 - (a << 8);
    } else {
        work->base.unk_15C = act->unk_04 + (a << 8);
    }
    w->unk_160 = act->unk_08;
    w->unk_170 = 19;
    w->unk_150 = 0;
    work->unk_1C4 = -b;
    work->unk_1C8 = 0;
}

void func_08057D30(RikuWork* work, s32 a, s32 b) {
    work->base.unk_15C = a;
    work->base.unk_160 = b;
    work->base.unk_170 = 19;
    work->base.unk_150 = 0;
    work->unk_1C4 = -0x500;
}

u8 func_08057D68(RikuWork* work) {
    s32 v;
    s32 w;
    Collider* c;

    c = gBtlWork->unk_07C;

    if (GetRandom() % 30 == 0) {
        func_0801C700(&work->base.unk_040, &v, &w, 0);
        func_0800F368(work, 1);

        if (func_0800F504(work, 0x100, 0x100, 0x100)) {
            if (gBtlWork->unk_068 & 0x8000) {
                func_08057CBC(work, -99, 0x280);
            } else if (GetRandom() & 1) {
                if (c->unk_34 & 4) {
                    func_08057D30(work, v + 0x2800, w);
                } else {
                    func_08057D30(work, v - 0x2800, w);
                }
            } else {
                func_08057CBC(work, -80, 0x500);
            }
            return 1;
        }
    }
    return 0;
}

void func_08057E2C(RikuWork* work, RikuSpawn* dst) {
    HumActor* act = &work->base.unk_040;

    dst->x = act->unk_04;
    dst->y = act->unk_08;
    dst->z = act->unk_0C;

    if (act->unk_34 & 4) {
        dst->unk_0C |= 1;
    } else {
        dst->unk_0C &= 0xFFFE;
    }
    dst->anim = work->base.anim;
    dst->unk_28 = *(u32*)work->base.tiles;
    dst->unk_2C = gBtlWork->unk_024;
}

void func_08057E90(RikuWork* work, RikuSpawn* p) {
    HumActor* act;
    HumSub* sub;
    void* gfx;
    u16 attr;
    s32 sx;
    s32 sy;
    s32 affine;
    s16 x;
    s16 y;
    u16 pri;

    sub = work->base.unk_00C;
    gfx = AnimGetGfx(&p->anim);
    act = &work->base.unk_040;

    if (func_080128EC() == 0) {
        gBldCnt = 0xF10;
        SetBlendAlpha(6, 12);
        attr = 0x804;
    } else {
        attr = func_0801AF1C(act->unk_08);
    }

    if (p->unk_0C & 1) {
        sy = p->unk_2C;
        sx = sy;
    } else if (p->unk_2C == 0x100) {
        sy = p->unk_2C;
        sx = sy;
        attr |= 1;
    } else {
        sx = -gBtlWork->unk_024;
        sy = gBtlWork->unk_024;
    }

    if (sy == 0x100 && sx == sy) {
        affine = 0;
    } else if (sy <= 255) {
        affine = AllocObjAffine(0, sx, sy, 0);
    } else {
        affine = AllocObjAffine(0, sx, sy, 1);
    }
    pri = 0xFFF0;
    WorldToScreen(&x, &y, p->x, p->y, p->z);
    func_08002A10(sub->tiles, p->unk_28);
    DrawSprite(x, y, gfx, sub->tiles, work->base.palette, affine, attr, pri);
}

void task_hum_riku_0(RikuWork* work) {
    func_0800E168(&work->base, gUnk_0813FD24);
    func_0800E314(&work->base, &work->unk_188, gUnk_0813FD40);
    work->unk_1C4 = 0;
    work->unk_1CA = 0;
    work->unk_188.unk_34 |= 3;
    work->unk_1CC = 0;

    if (gBtlWork->unk_10C != 0xA1) {
        work->base.unk_184 = (u32)gUnk_0813FBBC;
    }
    func_08057E2C(work, &work->unk_1D0[0]);
    work->unk_1D0[1] = work->unk_1D0[0];
    work->unk_1D0[2] = work->unk_1D0[0];
    work->unk_1D0[3] = work->unk_1D0[0];
    work->unk_1D0[4] = work->unk_1D0[0];
    work->unk_1D0[5] = work->unk_1D0[0];
    work->unk_1D0[6] = work->unk_1D0[0];
    work->unk_1D0[7] = work->unk_1D0[0];
    work->unk_1D0[8] = work->unk_1D0[0];
}

INCLUDE_ASM("hum/task_hum_riku_1.s");

void task_hum_riku_2(RikuWork* work) {
    func_0800EFE8(&work->base);

    if ((work->unk_1CA & 4) && (work->unk_188.unk_34 & 2)) {
        switch (work->unk_1CC % 2) {
        case 0:
            func_08057E90(work, &work->unk_1D0[2]);
            break;
        case 1:
            func_08057E90(work, &work->unk_1D0[4]);
            break;
        }
        work->unk_1CC++;
    }
    work->unk_1D0[4] = work->unk_1D0[3];
    work->unk_1D0[3] = work->unk_1D0[2];
    work->unk_1D0[2] = work->unk_1D0[1];
    work->unk_1D0[1] = work->unk_1D0[0];
    func_08057E2C(work, &work->unk_1D0[0]);
}

void task_hum_riku_3(HumWork* work) {
    func_0800E380(work);
}

void task_hum_leon_0(LeonWork* work) {
    func_0800E168(&work->base, gUnk_0813FDA8);
    work->unk_188 = 0;
    work->unk_18A = 0;
    func_08019068(gUnk_0813FD58, &work->base.anim, 0, 1, work->base.tiles);
    work->unk_18C = gGameState.unk_10C;
    work->unk_194 = gGameState.unk_114;
    gGameState.unk_10C = 0;
    gGameState.unk_114 = 0;
}

#ifdef NON_MATCHING
u8 task_hum_leon_1(LeonWork* work) {
    LeonWork* w;
    HumActor* act;
    s32 x;
    s32 y;
    s32 z;
    s32 a;
    s32 b;
    s32 c;
    u8 r;

    w = work;
    act = &work->base.unk_040;
    func_0801C700(act, &a, &b, &c);

    switch (_0800E434(work)) {
    case 4:
        break;
    case 5:
        work->base.unk_170 = 19;
        work->base.unk_150 = 0;
        break;
    }
    func_0800F368(work, 1);

    switch (work->base.unk_170) {
    case 12:
        func_08019068(gUnk_0813FD58, &w->base.anim, 0, 1, w->base.tiles);
        break;
    case 0:
        if (gBtlWork->unk_068 & 0x20000000000) {
            if (w->unk_18A == 0) {
                func_08019068(gUnk_0813FD58, &w->base.anim, 1, 0, w->base.tiles);
                w->unk_18A = 1;
            } else if (AnimIsFinished(&work->base.anim)) {
                func_08019068(gUnk_0813FD58, &w->base.anim, 3, 0, w->base.tiles);
            }
        } else {
            if (w->unk_18A != 0) {
                func_08019068(gUnk_0813FD58, &w->base.anim, 2, 0, w->base.tiles);
                w->unk_18A = 0;
            } else if (AnimIsFinished(&work->base.anim)) {
                func_08019068(gUnk_0813FD58, &w->base.anim, 0, 1, w->base.tiles);
            }
        }

        if (gBtlWork->unk_068 & 0x100000) {
            if (gBtlWork->unk_068 & 0x20000000) {
                work->base.unk_170 = 20;
                work->base.unk_150 = 0;
            }
        }
        break;
    case 1:
        if ((s16)work->base.unk_150 == 0) {
            func_0801AF08(act);
            func_08019068(gUnk_0813FD58, &w->base.anim, 4, 0, w->base.tiles);
            work->base.unk_150 = 8;
        }
        break;
    case 2:
        if (gBtlWork->unk_068 & 0x100000) {
            if (gBtlWork->unk_068 & 0x20000000) {
                work->base.unk_170 = 20;
                work->base.unk_150 = 0;
            }
        }
        break;
    case 20:
        if ((s16)work->base.unk_150 > 10) {
            gBtlWork->unk_0EF |= 32;
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 19:
        if ((s16)work->base.unk_150 > 80) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    default:
        func_08019068(gUnk_0813FD58, &w->base.anim, 3, 0, w->base.tiles);
        func_0800F368(work, 1);
        break;
    }

    if ((s16)work->unk_188 > 0) {
        work->unk_188--;
        act->unk_34 |= 0x2000;
    } else {
        act->unk_34 &= ~0x2000;
    }
    x = act->unk_04;
    y = act->unk_08;
    z = act->unk_0C;
    r = func_0800E5F0(work);
    act->unk_04 = x;
    act->unk_08 = y;
    act->unk_0C = z;
    return r;
}
#else
INCLUDE_ASM("hum/task_hum_leon_1.s");
#endif

void task_hum_leon_2(HumWork* work) {
    func_0800EFE8(work);
}

void task_hum_leon_3(LeonWork* work) {
    gGameState.unk_10C = work->unk_18C;
    gGameState.unk_114 = work->unk_194;
    func_0800E380(&work->base);
}

void task_hum_robe_0(RobeWork* work) {
    func_0800E168(&work->base, gUnk_0813FDF4);
    work->unk_188 = 1;
    func_08019068(gUnk_0813FDD4, &work->base.anim, 0, 1, work->base.tiles);
}

u8 task_hum_robe_1(RobeWork* work) {
    HumActor* act = &work->base.unk_040;
    s32 x;
    s32 y;
    s32 z;
    u8 r;

    if (_0800E434(work) == 1) {
        work->base.unk_150 = 1;
    }

    if (gBtlWork->unk_068 & 0x20000000) {
        if (work->unk_188 == 1) {
            func_08019068(gUnk_0813FDD4, &work->base.anim, 1, 0, work->base.tiles);
            work->unk_188 = 0;
        }
    } else if (AnimIsFinished(&work->base.anim)) {
        func_08019068(gUnk_0813FDD4, &work->base.anim, 0, 1, work->base.tiles);
        work->unk_188 = 1;
    }
    func_0800F368(work, 1);
    x = act->unk_04;
    y = act->unk_08;
    z = act->unk_0C;
    r = func_0800E5F0(work);
    act->unk_04 = x;
    act->unk_08 = y;
    act->unk_0C = z;
    return r;
}

void task_hum_robe_2(HumWork* work) {
    func_0800EFE8(work);
}

void task_hum_robe_3(HumWork* work) {
    func_0800E380(work);
}

#ifdef NON_MATCHING
void MakeSaveHeaderData(SaveHeaderData* data, s16 file) {
    s16 i;

    data->flags = 0;

    if (gGameState.flags & 0x20) {
        data->flags = 1;
    }

    if (gGameState.flags & 0x800) {
        data->flags |= 4;

        if (gGameState.flags & 8) {
            data->flags |= 2;
        } else {
            data->flags &= ~2;
        }
    } else if (gGameState.flags & 0x20) {
        data->flags |= 2;
    }

    for (i = 0; i < 4; i++) {
        if (file == i) {
            data->files[i].unk_00 = gGameState.floor;
            data->files[i].unk_01 = gGameState.world;
            data->files[i].unk_02 = gUnk_02039CB8;
            data->files[i].unk_04 = gUnk_02039D8C;
        } else {
            data->files[i].unk_00 = gGameState.fileSummaries[i].unk_00;
            data->files[i].unk_01 = gGameState.fileSummaries[i].unk_01;
            data->files[i].unk_02 = gGameState.fileSummaries[i].unk_02;
            data->files[i].unk_04 = gGameState.fileSummaries[i].unk_04;
        }
    }
}
#else
INCLUDE_ASM("hum/MakeSaveHeaderData.s");
#endif

void MakeSaveSystem(SaveFileLarge* save) {
    save->common.flags = gGameState.flags;
    save->common.unk_8E = gGameState.hp;
    memcpy(save->common.unk_04, gGameState.unk_0F8, 0x88);
    save->common.unk_8C = gGameState.unk_180;
    save->common.unk_90 = gGameState.floor;
    save->common.unk_91 = gGameState.world;
    save->common.unk_94 = gGameState.playTime;
    func_080E92B8(save->unk_098);
    func_080A324C(save->unk_2EC);
    func_080C700C(save->unk_E6C);
    func_080DDEB0(save->unk_E70);
    func_0810962C(save->unk_EB4);
}

void MakeSaveFileLarge(SaveFileLarge* save) {
    save->common.flags = gGameState.flags;
    save->common.unk_8E = gGameState.hp;
    memcpy(save->common.unk_04, gGameState.unk_0F8, 0x88);
    save->common.unk_8C = gGameState.unk_180;
    save->common.unk_90 = gGameState.floor;
    save->common.unk_91 = gGameState.world;
    save->common.unk_94 = gGameState.playTime;
    func_080E92B8(save->unk_098);
    func_080A324C(save->unk_2EC);
    func_080C700C(save->unk_E6C);
    func_080DDEB0(save->unk_E70);
    func_0810962C(save->unk_EB4);

    if (gGameState.flags & 0x10) {
        gGameState.fileSummaries[1].unk_00 = gGameState.floor;
        gGameState.fileSummaries[1].unk_01 = gGameState.world;
        gGameState.fileSummaries[1].unk_02 = gGameState.level;
        gGameState.fileSummaries[1].unk_04 = gGameState.playTime;
    } else {
        gGameState.fileSummaries[0].unk_00 = gGameState.floor;
        gGameState.fileSummaries[0].unk_01 = gGameState.world;
        gGameState.fileSummaries[0].unk_02 = gGameState.level;
        gGameState.fileSummaries[0].unk_04 = gGameState.playTime;
    }
}

void MakeSaveFileSmall(SaveFileSmall* save) {
    save->common.flags = gGameState.flags;
    save->common.unk_8E = gGameState.hp;
    memcpy(save->common.unk_04, gGameState.unk_0F8, 0x88);
    save->common.unk_8C = gGameState.unk_180;
    save->common.unk_90 = gGameState.floor;
    save->common.unk_91 = gGameState.world;
    save->common.unk_94 = gGameState.playTime;
    func_080E92B8(save->unk_098);
    func_080A3370(save->unk_2EC);

    if (gGameState.flags & 0x10) {
        gGameState.fileSummaries[3].unk_00 = gGameState.floor;
        gGameState.fileSummaries[3].unk_01 = gGameState.world;
        gGameState.fileSummaries[3].unk_02 = gGameState.level;
        gGameState.fileSummaries[3].unk_04 = gGameState.playTime;
    } else {
        gGameState.fileSummaries[2].unk_00 = gGameState.floor;
        gGameState.fileSummaries[2].unk_01 = gGameState.world;
        gGameState.fileSummaries[2].unk_02 = gGameState.level;
        gGameState.fileSummaries[2].unk_04 = gGameState.playTime;
    }
}

#ifndef VERSION_EU
void ApplySaveHeaderData(SaveHeaderData* data) {
    if (SaveRepairHeader() == SAVE_OK) {
        if (data->flags & 1) {
            gGameState.flags |= 0x20;
        }

        if (data->flags & 4) {
            gGameState.flags |= 0x800;
        }

        if (data->flags & 2) {
            gGameState.flags |= 0x200;
        }
    }

    if (SaveRepairFileLarge(0) == SAVE_OK) {
        gGameState.fileSummaries[0].unk_00 = data->files[0].unk_00;
        gGameState.fileSummaries[0].unk_01 = data->files[0].unk_01;
        gGameState.fileSummaries[0].unk_02 = data->files[0].unk_02;
        gGameState.fileSummaries[0].unk_04 = data->files[0].unk_04;
    } else {
        gGameState.fileSummaries[0].unk_00 = 0;
        gGameState.fileSummaries[0].unk_01 = 0;
        gGameState.fileSummaries[0].unk_02 = 0;
        gGameState.fileSummaries[0].unk_04 = 0;
    }

    if (SaveRepairFileLarge(1) == SAVE_OK) {
        gGameState.fileSummaries[1].unk_00 = data->files[1].unk_00;
        gGameState.fileSummaries[1].unk_01 = data->files[1].unk_01;
        gGameState.fileSummaries[1].unk_02 = data->files[1].unk_02;
        gGameState.fileSummaries[1].unk_04 = data->files[1].unk_04;
    } else {
        gGameState.fileSummaries[1].unk_00 = 0;
        gGameState.fileSummaries[1].unk_01 = 0;
        gGameState.fileSummaries[1].unk_02 = 0;
        gGameState.fileSummaries[1].unk_04 = 0;
    }

    if (SaveRepairFileSmall(0) == SAVE_OK) {
        gGameState.fileSummaries[2].unk_00 = data->files[2].unk_00;
        gGameState.fileSummaries[2].unk_01 = data->files[2].unk_01;
        gGameState.fileSummaries[2].unk_02 = data->files[2].unk_02;
        gGameState.fileSummaries[2].unk_04 = data->files[2].unk_04;
    } else {
        gGameState.fileSummaries[2].unk_00 = 0;
        gGameState.fileSummaries[2].unk_01 = 0;
        gGameState.fileSummaries[2].unk_02 = 0;
        gGameState.fileSummaries[2].unk_04 = 0;
    }

    if (SaveRepairFileSmall(1) == SAVE_OK) {
        gGameState.fileSummaries[3].unk_00 = data->files[3].unk_00;
        gGameState.fileSummaries[3].unk_01 = data->files[3].unk_01;
        gGameState.fileSummaries[3].unk_02 = data->files[3].unk_02;
        gGameState.fileSummaries[3].unk_04 = data->files[3].unk_04;
    } else {
        gGameState.fileSummaries[3].unk_00 = 0;
        gGameState.fileSummaries[3].unk_01 = 0;
        gGameState.fileSummaries[3].unk_02 = 0;
        gGameState.fileSummaries[3].unk_04 = 0;
    }
}
#else
INCLUDE_ASM("hum/ApplySaveHeaderData.s");
#endif

void ApplySaveSystem(SaveFileLarge* save) {
    u32 t;

    t = gGameState.flags & 0xA20;
    save->common.flags &= 0xFFFFF5DF;
    gGameState.flags = save->common.flags | t;
    gGameState.hp = save->common.unk_8E;
    memcpy(gGameState.unk_0F8, save->common.unk_04, 0x88);
    gGameState.unk_180 = save->common.unk_8C;
    gGameState.floor = save->common.unk_90;
    gGameState.world = save->common.unk_91;
    gGameState.playTime = save->common.unk_94;
    func_080E92F8(save->unk_098);
    func_080A32DC(save->unk_2EC);
    func_080C7024(save->unk_E6C);
    func_080DDEBC(save->unk_E70);
    func_08109638(save->unk_EB4);
}

void ApplySaveFileLarge(SaveFileLarge* save) {
    u32 t;

    t = gGameState.flags & 0xA20;
    save->common.flags &= 0xFFFFF5DF;
    gGameState.flags = save->common.flags | t;
    gGameState.hp = save->common.unk_8E;
    memcpy(gGameState.unk_0F8, save->common.unk_04, 0x88);
    gGameState.unk_180 = save->common.unk_8C;
    gGameState.floor = save->common.unk_90;
    gGameState.world = save->common.unk_91;
    gGameState.playTime = save->common.unk_94;
    func_080E92F8(save->unk_098);
    func_080A32DC(save->unk_2EC);
    func_080C7024(save->unk_E6C);
    func_080DDEBC(save->unk_E70);
    func_08109638(save->unk_EB4);
    gGameState.flags &= ~8;
}

void ApplySaveFileSmall(SaveFileSmall* save) {
    u32 t;

    t = gGameState.flags & 0xA20;
    save->common.flags &= 0xFFFFF5DF;
    gGameState.flags = save->common.flags | t;
    gGameState.hp = save->common.unk_8E;
    memcpy(gGameState.unk_0F8, save->common.unk_04, 0x88);
    gGameState.unk_180 = save->common.unk_8C;
    gGameState.floor = save->common.unk_90;
    gGameState.world = save->common.unk_91;
    gGameState.playTime = save->common.unk_94;
    func_080E92F8(save->unk_098);
    func_080A3398(save->unk_2EC);
    gGameState.flags |= 8;
}
