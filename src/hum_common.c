#include "mode_vsbattle.h"
#include "macros.h"

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
    actor->flags |= 0x40000000000000;

    if (gBtlWork->unk_07C->x < actor->x) {
        actor->flags |= 4;
    }

    work->unk_000 = def;
    work->tiles = AllocObjTiles(def->unk_00 * 32, 0);
    work->palette = LoadObjPalette(def->unk_04, 32);
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
    AnimInit(&work->anim, 0, 0);
    TaskPoolInit(&work->unk_02C, 3);
    TaskCreate(&work->unk_02C, &gTaskDescBtlShadow, actor);
    TaskCreate(&work->unk_02C, &gTaskDescBtlBadstatus, actor);
    work->unk_170 = 12;
    work->unk_168 = 0x100;
    work->unk_16C = 0x100;
    work->unk_00C = 0;
    work->unk_010 = 0;
    work->unk_184 = 0;
    gUnk_02039B9C->unk_07C = actor;
    gBtlWork->unk_0A8 = actor;
    actor->unk_E4 = gUnk_02039B9C;
    actor->flags |= 0x24000000000;
}

void func_0800E314(HumWork* work, HumSub* sub, HumSubDef* def) {
    if (work->unk_00C == 0) {
        work->unk_00C = sub;
    } else {
        work->unk_010 = sub;
    }

    sub->tiles = AllocObjTiles(def->unk_04 * 32, 0);
    sub->unk_0C = sub->palette = LoadObjPalette(def->unk_00, 32);
    sub->unk_28 = work->unk_040.x;
    sub->unk_2C = work->unk_040.y;
    sub->unk_30 = work->unk_040.z;
    sub->unk_34 = 0;
    AnimInit(&sub->anim, 0, 0);
}

void func_0800E364(HumSub* sub) {
    if (sub != 0) {
        ReleaseObjTiles(sub->tiles);
        ReleaseObjPalette(sub->palette);
    }
}

void func_0800E380(HumWork* work) {
    if (gBtlWork->unk_078 == &work->unk_040) {
        gBtlWork->unk_078 = 0;
    }

    func_0800E364(work->unk_00C);
    func_0800E364(work->unk_010);
    gBtlWork->unk_0A8 = 0;
    func_0801B7D8(&work->unk_040);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&work->unk_02C);
}

void func_0800E3D0(HumWork* work) {
    work->unk_158 = -work->unk_040.unk_AC * 3;
    work->unk_040.unk_108 = ((gSineTable[work->unk_040.unk_B0] << 1) * work->unk_040.unk_A8) >> 8;
    work->unk_040.unk_10C = ((-gSineTable[work->unk_040.unk_B0 + 0x40] << 1) * work->unk_040.unk_A8) >> 8;
}

s32 _0800E434(HumWork* work) {
    VsActor* actor = &work->unk_040;
    s32 r;

    actor->unk_FC = actor->x;
    actor->unk_100 = actor->y;
    r = func_0801ADAC(actor);

    switch (r) {
    case 5:
        work->unk_154 |= 4;
        gUnk_02039B9C->unk_068 &= ~0x40000000;
        work->unk_17E = 0;
        work->unk_150 = 0;
        AnimReset(&work->anim);
        break;
    case 11:
        func_08006120(2, 20);
        gBtlWork->unk_072 = 15;

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
            sub->gfx = AnimUpdate(&sub->anim);
        }
    }
}

s32 func_0800E5F0(HumWork* work);

s32 func_0800E5F0(HumWork* work) {
    VsActor* actor = &work->unk_040;
    s32 x;

    func_0801C700(actor, &x, 0, 0);

    switch (work->unk_170) {
    case 12:
        if (work->unk_150 > 100) {
            work->unk_170 = 0;
            work->unk_150 = 0;
        } else {
            work->unk_150++;
        }
        break;
    case 1:
        if (work->unk_150 == 0) {
            AnimReset(&work->anim);
        }
        if (work->unk_150 > 10) {
            func_0801AF08(actor);
            work->unk_170 = 2;
            work->unk_150 = 0;

            if (actor->x < x) {
                if (actor->flags & 4) {
                    if (GetRandom() % 3 == 0) {
                        actor->flags &= ~4;
                    }
                }
            } else {
                if (!(actor->flags & 4)) {
                    if (GetRandom() % 3 == 0) {
                        actor->flags |= 4;
                    }
                }
            }
            func_0800F5A4(work, 3, 64, 64, 32);
        } else {
            work->unk_150++;
        }
        break;
    case 2:
        if (AnimIsFinished(&work->anim)) {
            work->unk_170 = 0;
            work->unk_150 = 0;
        }
        break;
    case 14:
        if (work->unk_150 == 0) {
            AnimReset(&work->anim);
            func_08012614(&actor->unk_40, 1);
            actor->flags |= 0x100;
            work->anim.frame = 0;
            work->anim.timer = 0;
            work->unk_158 = 0x400;
            actor->unk_108 = 0;
            actor->unk_10C = 0;
            work->unk_152 = 10;
        }
        ApproachValue(&work->unk_16C, 64, work->unk_152--);

        if (work->unk_152 > 0) {
            work->unk_150++;
        } else {
            work->unk_150 = 0;
            work->unk_170 = 15;
        }
        break;
    case 15:
        if (work->unk_150 > 44) {
            if (actor->unk_2C <= 0) {
                work->unk_170 = 3;
            } else {
                work->unk_170 = 16;
            }
            work->unk_150 = 0;
        } else {
            work->unk_150++;
        }
        break;
    case 16:
        if (work->unk_150 == 0) {
            func_08012614(&actor->unk_40, 0);
            work->unk_152 = 10;
        }
        func_0800592C(&work->unk_16C, 0x100, work->unk_152--);

        if (work->unk_152 <= 0) {
            actor->flags &= ~0x100;
            func_0801AF08(actor);
            work->unk_170 = 0;
            work->unk_150 = 0;
        } else {
            work->unk_150++;
        }
        break;
    case 11:
        if (work->unk_150 == 0) {
            AnimReset(&work->anim);
            work->unk_150++;
        }
        if (AnimIsFinished(&work->anim)) {
            actor->flags &= ~0x80;
            actor->flags &= ~0x2000;
        }
        if (GetRandom() % 3 == 0) {
            actor->unk_EC -= 6;
        }
        if (actor->unk_E8 != 1) {
            func_0801AF08(actor);
            work->unk_170 = 0;
            work->unk_150 = 0;
        }
        break;
    case 9:
        if (AnimIsFinished(&work->anim) && work->unk_150 > 60) {
            func_0801AF08(actor);
            work->unk_170 = 0;
            work->unk_150 = 0;
        } else {
            work->unk_150++;
        }
        break;
    case 10:
        if (work->unk_150 == 0) {
            work->unk_168 = 0x100;
            work->unk_16C = 0x100;
            actor->unk_108 = 0;
            actor->unk_10C = 0;
        }
        work->unk_158 = 0;

        if (work->unk_150 == 40) {
            func_08019190(actor, 10);
            actor->unk_2C -= actor->unk_20;
            if (actor->unk_2C > actor->unk_2E) {
                actor->unk_2C = actor->unk_2E;
            }
            func_0801AF08(actor);
            work->unk_170 = 0;
            work->unk_150 = 0;
        } else {
            work->unk_150++;
        }
        break;
    case 18:
        if (work->unk_150 == 23) {
            func_08013A68(actor->x, actor->y, actor->z - ((actor->unk_9C - 48) << 8));
        }
        if (work->unk_150 > 23 && func_080128EC() == 0) {
            switch (work->unk_17E) {
            case 0:
                func_0807E1A0();
                break;
            case 1:
                func_0807E1AC();
                break;
            case 2:
                func_0807E1B8();
                break;
            case 3:
                func_0807E1C4();
                break;
            case 4:
                func_0807E1D0();
                break;
            case 5:
                func_0807E1DC();
                break;
            default:
                func_0807E1E8();
                break;
            }
            func_0801AF08(actor);
            work->unk_170 = 0;
            work->unk_150 = 0;
        } else {
            work->unk_150++;
        }
        break;
    case 13:
        if (actor->unk_E8 != 2) {
            work->unk_170 = 0;
            func_0801AF08(actor);
        }
        break;
    case 3:
        if (work->unk_150 == 0) {
            func_0801AF4C(actor);

            if (!(work->unk_154 & 0x40)) {
                m4aSongNumStart(0x20E);
            }
            func_08019050(1, 0x100, gBtlWork->unk_010, gBtlWork->unk_014);
        }
        if (func_08006314() == 0) {
            work->unk_150 = 0;

            if (work->unk_154 & 0x40) {
                work->unk_170 = 6;
            } else {
                work->unk_170 = 4;
            }
        } else {
            func_0802F284(actor->x, actor->y, actor->z);
            work->unk_150++;
        }
        break;
    case 4:
        if (work->unk_150 == 0) {
            func_08014A34(actor->x, actor->y + actor->z - ((s16)actor->unk_A2 << 8));
            func_08006238(0, gBtlWork->unk_0B3, 8);
        }
        func_0802F284(actor->x, actor->y, actor->z);
        work->unk_158 = 0;

        if (work->unk_150 > 150) {
            work->unk_150 = 0;
            work->unk_170 = 5;
        } else {
            work->unk_150++;
        }
        break;
    case 5:
        if (work->unk_150 == 0) {
            PrizeCardArg arg;

            func_08006120(2, 60);
            func_080063A8();
            m4aSongNumStart(0x20F);
            gBtlWork->unk_068 |= 0x400000;
            func_0801B008();
            func_0801B918(actor);
            arg.unk_00 = actor->x;
            arg.unk_04 = actor->y;
            arg.unk_08 = -0x4600;
            func_08096DC4(&gBtlWork->unk_02C, &arg);
            return 0;
        } else {
            work->unk_150++;
        }
        break;
    case 6:
        if (work->unk_150 == 0) {
            func_08014AAC(actor->x, actor->y + actor->z - ((s16)actor->unk_A2 << 8));
            func_08006238(0, gBtlWork->unk_0B3, 8);
        }
        func_0802F284(actor->x, actor->y, actor->z);
        work->unk_158 = 0;

        if (work->unk_150 > 150) {
            work->unk_150 = 0;
            work->unk_170 = 7;
            func_0801536C();
        } else {
            work->unk_150++;
        }
        break;
    case 7:
        func_0802F284(actor->x, actor->y, actor->z);

        if (func_080128EC() == 0) {
            PrizeCardArg arg2;

            func_0801B008();
#ifdef VERSION_EU
            func_0801A8A4(&actor->x, &actor->y, work->unk_174 - 8, -16);
#endif
            func_0801B918(actor);
            arg2.unk_00 = actor->x;
            arg2.unk_04 = actor->y;
            arg2.unk_08 = -0x4600;
            func_08096DC4(&gBtlWork->unk_02C, &arg2);
            return 0;
        }
        work->unk_150++;
        break;
    case 0:
        work->unk_154 &= ~4;

        if (func_0807E29C()) {
            work->unk_150 = 0;
            work->unk_170 = 17;
        }
        break;
    case 17:
        func_0807E2F4();

        if (func_0807E29C() == 0) {
            work->unk_150 = 0;
            work->unk_170 = 0;
        } else {
            work->unk_150++;
        }
        break;
    }

    if (actor->unk_E8 != 2) {
        actor->z += work->unk_158;
        work->unk_158 += gBtlWork->unk_12C;

        if (actor->z > 0) {
            actor->z = 0;
            work->unk_158 = 0;
        }
        if (actor->unk_6C != 0 && !(work->unk_154 & 4) && !(actor->unk_90->unk_30 & 2)) {
            actor->x += actor->unk_78 >> 1;
            actor->y += actor->unk_7C >> 1;
        }
    }

    if (actor->unk_108 > 0) {
        actor->x += actor->unk_108;
        actor->unk_108 -= 17;
        if (actor->unk_108 < 0) {
            actor->unk_108 = 0;
        }
    } else if (actor->unk_108 < 0) {
        actor->x += actor->unk_108;
        actor->unk_108 += 17;
        if (actor->unk_108 > 0) {
            actor->unk_108 = 0;
        }
    }

    if (actor->unk_10C > 0) {
        actor->y += actor->unk_10C;
        actor->unk_10C -= 17;
        if (actor->unk_10C < 0) {
            actor->unk_10C = 0;
        }
    } else if (actor->unk_10C < 0) {
        actor->y += actor->unk_10C;
        actor->unk_10C += 17;
        if (actor->unk_10C > 0) {
            actor->unk_10C = 0;
        }
    }

    if (!(work->unk_154 & 8)) {
        switch (func_0801A8A4(&actor->x, &actor->y, work->unk_174, 0)) {
        case 1:
        case 2:
            actor->unk_108 = -(actor->unk_108 >> 1);
            work->unk_154 |= 1;
            break;
        case 3:
        case 4:
            actor->unk_10C = -(actor->unk_10C >> 1);
            work->unk_154 |= 1;
            break;
        default:
            work->unk_154 &= ~1;
            break;
        }
    }

    if (actor->unk_E8 != 2) {
        work->gfx = AnimUpdate(&work->anim);
        func_0800E5CC(work->unk_00C);
        func_0800E5CC(work->unk_010);
    }

    if (actor->unk_E8 == 5) {
        actor->x = actor->unk_FC;
        actor->y = actor->unk_100;
    }

    TaskPoolUpdate(&work->unk_02C);
    func_08012324(&actor->unk_40, actor->x, actor->y, actor->z);
    return 1;
}

ALIGN_ZERO(2);
