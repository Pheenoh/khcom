#include "mode_vsbattle.h"
#include "macros.h"

void func_0800C778(EmyWork* work, EmyDef* def, EmyObj* obj) {
    VsActor* actor = &work->unk_03C;
    u16 t;

    func_0801B37C(actor, &def->unk_1C, obj->unk_00, obj->unk_04, obj->unk_08);
    actor->unk_CE = def->unk_12;
    actor->unk_D0 = def->unk_14;
    actor->unk_D2 = def->unk_16;
    actor->unk_B2 = def->unk_18;

    if (gBtlWork->unk_07C->x < actor->x) {
        actor->flags |= 4;
    }

    actor->flags |= 0x300;
    t = gUnk_09EDA4EC[actor->unk_00];
    work->unk_15C = def;
    work->tiles = AllocObjTiles(t * 32, 0);
    work->unk_004 = LoadObjPalette(def->unk_00, 32);
    work->unk_008 = LoadObjPalette(gUnk_08F69BC4, 32);
    work->unk_150 = 0;
    work->unk_14C = 11;
    work->unk_154 = 0;
    work->unk_156 = 0;
    work->unk_158 = 0;
    work->unk_15A = 1;
    work->angle = 0;
    work->unk_164 = def->unk_08;
    work->unk_168 = 0;
    actor->unk_108 = 0;
    actor->unk_10C = 0;
    work->unk_162 = 0;

    if (actor->flags & 0x20000) {
        work->unk_16C = 281;
    } else {
        work->unk_16C = 0x100;
    }

    work->unk_170 = 0;
    work->unk_174 = 0;
    work->unk_178 = 0;
    AnimInit(&work->anim, 0, 0);
    func_08019068(work->unk_15C->unk_04, &work->anim, 0, 1, work->tiles);
    work->gfx = AnimGetGfx(&work->anim);
    TaskPoolInit(&work->unk_028, 3);

    if (!(def->unk_1A & 1)) {
        TaskCreate(&work->unk_028, &gTaskDescBtlShadow, actor);
    }

    TaskCreate(&work->unk_028, &gTaskDescBtlBadstatus, actor);

    if (def->unk_1A & 2) {
        work->unk_17C = 0x100;
        work->unk_180 = 0x100;
    } else {
        work->unk_17C = 0x80;
        work->unk_180 = 0x80;
    }

    gBtlWork->unk_0EC += t;
    gBtlWork->unk_120--;
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

            if (work->unk_03C.flags & 4) {
                v = actor->unk_14 - (e << 8);
            } else {
                v = actor->unk_14 + (e << 8);
            }

            if (actor->unk_E8 != 5) {
                func_0800592C(&actor->x, v, steps);
                func_0800592C(&actor->y, target, steps);
            }

            if (!(work->unk_158 & 4)) {
                if (actor->flags & 4) {
                    if (func_08011F78(d, actor->x - (g << 8), actor->y, actor->z + (h << 8), (s16)i, i / 2, (s16)i) != 0) {
                        m4aSongNumStart(f);
                        work->unk_158 |= 4;
                        ret = 1;
                    }
                } else {
                    if (func_08011F78(d, actor->x + (g << 8), actor->y, actor->z + (h << 8), (s16)i, i / 2, (s16)i) != 0) {
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
    work->unk_03C.unk_108 = ((gSineTable[work->unk_03C.unk_B0] << 1) * work->unk_03C.unk_A8) >> 8;
    work->unk_03C.unk_10C = ((-gSineTable[work->unk_03C.unk_B0 + 0x40] << 1) * work->unk_03C.unk_A8) >> 8;
}


u8 _0800CBDC(EmyWork* work) {
    VsActor* actor = &work->unk_03C;

    actor->unk_FC = actor->x;
    actor->unk_100 = actor->y;

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

    if (gGameState.flags & 4) {
        actor->flags |= 0x4002;

        if (gGameState.unk_1B8 == 3) {
            actor->unk_20 = (actor->unk_2E * 204) >> 8;
        } else {
            actor->unk_20 = (actor->unk_2E * 25) >> 8;
        }

        actor->unk_24 = 0x200;
        gBtlWork->unk_076 = 0;
        actor->unk_A8 = 0;
        actor->unk_AC = 0;
    }

    work->unk_14C = work->unk_150;
    work->unk_154 = 0;
    actor->flags &= ~0x300;
}

#ifdef NON_MATCHING
s32 _0800CDF0(EmyWork* work) {
    VsActor* actor = &work->unk_03C;
    s32 x;
    s32 y;
    s32 z;

    func_0801C700(actor, &x, &y, &z);

    if (gBtlWork->unk_068 & 0x2000) {
        return 0;
    }

    switch (work->unk_14C) {
    case 11:
        if (work->unk_154 == 0) {
            work->unk_156 = 18;
        }
        work->unk_168 = 0;
        ApproachValue(&work->unk_180, 0x100, work->unk_156--);
        work->unk_17C = work->unk_180;

        if (work->unk_156 <= 0) {
            func_0800CD40(work);
        } else {
            work->unk_154++;
        }
        break;
    case 8:
        work->unk_168 = 0;
        func_08019068(work->unk_15C->unk_04, &work->anim, 2, 1, work->tiles);
        func_0801BCF8(actor);
        actor->z += ((work->unk_178 + gSineTable[gFrameCounter & 0xFF] * 10) - actor->z) >> 4;

        if (GetRandom() % work->unk_15C->unk_0E == 0) {
            if (actor->x > x) {
                actor->flags |= 4;
            } else {
                actor->flags &= ~4;
            }
        }
        if (gBtlWork->unk_068 & 0x40000) {
            s32 tx;
            s32 ty;
            s32 d;

            tx = work->unk_170;
            ty = work->unk_174;
            work->unk_164 += 51;
            d = (tx - actor->x) >> 5;
            if (d > work->unk_164) {
                d = work->unk_164;
            } else if (d < -work->unk_164) {
                d = -work->unk_164;
            }
            actor->x += d;
            d = (ty - actor->y) >> 5;
            if (d > work->unk_164) {
                d = work->unk_164;
            } else if (d < -work->unk_164) {
                d = -work->unk_164;
            }
            actor->y += d;

            if (work->unk_154 > 64) {
                work->unk_14C = work->unk_150;
            } else {
                work->unk_154++;
            }
        }
        break;
    case 7:
        work->unk_168 = 0;
        func_08019068(work->unk_15C->unk_04, &work->anim, 0, 1, work->tiles);
        func_0801BCF8(actor);
        actor->z += ((work->unk_178 + gSineTable[gFrameCounter * 2 & 0xFF] * 12) - actor->z) >> 4;

        if (GetRandom() % work->unk_15C->unk_0E == 0) {
            if (actor->x > x) {
                actor->flags |= 4;
            } else {
                actor->flags &= ~4;
            }
        }
        if (GetRandom() % work->unk_15C->unk_0C == 0) {
            work->unk_164 = 0;
            work->unk_14C = 8;

            if (GetRandom() % 2 == 0) {
                s32 lo;

                work->unk_170 = x - ((actor->unk_CE + ((lo = -actor->unk_D0) + GetRandom() % (actor->unk_D0 - lo + 1))) << 8);
            } else {
                s32 lo;

                work->unk_170 = x + ((actor->unk_CE + ((lo = -actor->unk_D0) + GetRandom() % (actor->unk_D0 - lo + 1))) << 8);
            }
            work->unk_174 = y + ((GetRandom() % 121 - 60) << 8);
            work->unk_178 = -((GetRandom() % 49 + 16) << 8);
            work->unk_154 = 0;
        } else {
            work->unk_154++;
        }
        break;
    case 13:
        if (work->unk_154 == 0) {
            AnimReset(&work->anim);
            func_08019068(work->unk_15C->unk_04, &work->anim, 1, 0, work->tiles);
            actor->unk_14 = actor->x;
            actor->unk_18 = actor->y;
        }
        switch (work->unk_154 % 4) {
        case 0:
            actor->x = actor->unk_14 + 0x100;
            actor->y = actor->unk_18;
            break;
        case 1:
            actor->x = actor->unk_14 - 0x100;
            actor->y = actor->unk_18;
            break;
        case 2:
            actor->x = actor->unk_14;
            actor->y = actor->unk_18 + 0x100;
            break;
        case 3:
            actor->x = actor->unk_14;
            actor->y = actor->unk_18 - 0x100;
            break;
        }
        if (AnimIsFinished(&work->anim)) {
            func_0801AF08(actor);
            work->unk_14C = 14;
            work->unk_154 = 0;
        } else {
            work->unk_154++;
        }
        break;
    case 14:
        if (gBtlWork->unk_068 & 0x40000) {
            s32 tx;
            s32 ty;

            if (work->unk_154 == 0) {
                func_08019068(work->unk_15C->unk_04, &work->anim, 2, 1, work->tiles);
            }
            if (x < 0x10000) {
                tx = x >> 1;
            } else {
                tx = (x + 0x20000) >> 1;
            }
            if (y < ((gBtlWork->unk_0DE + gBtlWork->unk_0E0) >> 1) << 8) {
                ty = (gBtlWork->unk_0DE << 8) - 0x4000;
            } else {
                ty = (gBtlWork->unk_0E0 << 8) + 0x4000;
            }
            work->angle = GetAngle(tx, ty, actor->x, actor->y);
            actor->x += ((gSineTable[work->angle] << 1) * work->unk_15C->unk_08) >> 8;
            actor->y += ((-gSineTable[work->angle + 64] << 1) * work->unk_15C->unk_08) >> 8;

            if ((s8)work->angle >= 0) {
                actor->flags &= ~4;
            } else {
                actor->flags |= 4;
            }
            if (actor->unk_E8 != 4) {
                work->unk_14C = work->unk_150;
                work->unk_154 = 0;
            } else {
                work->unk_154++;
            }
        }
        break;
    case 4:
        if (gBtlWork->unk_068 & 0x40000) {
            s32 tx;
            s32 ty;
            s32 d;

            func_08019068(work->unk_15C->unk_04, &work->anim, 2, 1, work->tiles);
            func_0801BCF8(actor);
            tx = x + work->unk_170;
            ty = y;

            if (tx < (gBtlWork->unk_0DA + 32) << 8) {
                tx = x + ((actor->unk_CE + actor->unk_D0) << 8);
            } else if (tx > (gBtlWork->unk_0DC - 32) << 8) {
                tx = ty - ((actor->unk_CE + actor->unk_D0) << 8);
            }
            if (GetRandom() % 100 == 0) {
                if (GetRandom() % 2 == 0) {
                    s32 lo;

                    work->unk_170 = -((actor->unk_CE + ((lo = -actor->unk_D0) + GetRandom() % (actor->unk_D0 - lo + 1))) << 8);
                } else {
                    s32 lo;

                    work->unk_170 = ((actor->unk_CE + ((lo = -actor->unk_D0) + GetRandom() % (actor->unk_D0 - lo + 1))) << 8);
                }
            } else {
                d = tx - actor->x;
                if (d < 0) {
                    d = actor->x - tx;
                }
                if (d > 0x400) {
                    work->angle = GetAngle(actor->x, actor->y, tx, ty);
                    actor->x += (gSineTable[work->angle] * work->unk_164) >> 8;
                    actor->y += (-gSineTable[work->angle + 64] * work->unk_164) >> 8;
                } else if ((d = ty - actor->y) >= 0 ? d > 0x400 : actor->y - ty > 0x400) {
                    work->angle = GetAngle(actor->x, actor->y, tx, ty);
                    actor->x += (gSineTable[work->angle] * work->unk_164) >> 8;
                    actor->y += (-gSineTable[work->angle + 64] * work->unk_164) >> 8;
                } else if (AnimIsFinished(&work->anim)) {
                    work->unk_14C = work->unk_150;
                }
            }
            if (GetRandom() % work->unk_15C->unk_0E == 0) {
                if (actor->x > x) {
                    actor->flags |= 4;
                } else {
                    actor->flags &= ~4;
                }
            }
        }
        break;
    case 0:
        func_08019068(work->unk_15C->unk_04, &work->anim, 0, 1, work->tiles);
        func_0801BCF8(actor);

        if (GetRandom() % work->unk_15C->unk_0C == 0) {
            work->unk_14C = 4;

            if (GetRandom() % 2 == 0) {
                s32 lo;

                work->unk_170 = -((actor->unk_CE + ((lo = -actor->unk_D0) + GetRandom() % (actor->unk_D0 - lo + 1))) << 8);
            } else {
                s32 lo;

                work->unk_170 = ((actor->unk_CE + ((lo = -actor->unk_D0) + GetRandom() % (actor->unk_D0 - lo + 1))) << 8);
            }
        }
        if (GetRandom() % work->unk_15C->unk_0E == 0) {
            if (actor->x > x) {
                actor->flags |= 4;
            } else {
                actor->flags &= ~4;
            }
        }
        break;
    case 12:
        if (actor->unk_E8 != 2) {
            work->unk_14C = work->unk_150;
            func_0801AF08(actor);
        }
        break;
    case 9:
        if (work->unk_154 == 0) {
            AnimReset(&work->anim);
            func_08019068(work->unk_15C->unk_04, &work->anim, 1, 0, work->tiles);
            work->unk_154++;
        }
        if (AnimIsFinished(&work->anim)) {
            actor->flags &= ~0x80;
            actor->flags &= ~0x2000;
        }
        if (GetRandom() % 10 == 0) {
            actor->unk_EC--;
        }
        if (actor->unk_E8 != 1) {
            func_0801AF08(actor);
            work->unk_14C = work->unk_150;
            work->unk_154 = 0;
        }
        break;
    case 1:
        if (work->unk_154 == 0) {
            AnimReset(&work->anim);
            func_08019068(work->unk_15C->unk_04, &work->anim, 1, 0, work->tiles);
        }
        if (work->unk_154 >= work->unk_15C->unk_10) {
            s32 ok = 0;

            func_0801AF08(actor);
            work->unk_14C = 2;
            work->unk_154 = 0;

            if (actor->x < x) {
                if (actor->flags & 4) {
                    if (GetRandom() % 5 == 0) {
                        actor->flags &= ~4;
                        goto turned;
                    }
                } else {
                    goto turned;
                }
            } else {
                if (actor->flags & 4) {
                    goto turned;
                } else {
                    if (GetRandom() % 5 == 0) {
                        actor->flags |= 4;
                        ok = 1;
                    }
                }
            }
            if (ok == 0) {
                break;
            }
turned:
            if (GetRandom() % 4 == 0) {
                func_0801BCD4(actor);
            }
        } else {
            work->unk_154++;
        }
        break;
    case 2:
        if (AnimIsFinished(&work->anim)) {
            work->unk_14C = work->unk_150;
            work->unk_154 = 0;
        }
        break;
    case 15:
        if (work->unk_154 == 0) {
            func_08012614(&actor->unk_40, 1);
            actor->flags |= 0x100;
            func_08019068(work->unk_15C->unk_04, &work->anim, 1, 0, work->tiles);
            work->anim.frame = 0;
            work->anim.timer = 0;
            work->unk_168 = 0x400;
            actor->unk_108 = 0;
            actor->unk_10C = 0;
            work->unk_156 = 10;
        }
        ApproachValue(&work->unk_180, 64, work->unk_156--);

        if (work->unk_156 <= 0) {
            work->unk_154 = 0;
            work->unk_14C = 16;
        } else {
            work->unk_154++;
        }
        break;
    case 16:
        if (work->unk_154 > 44) {
            if (actor->unk_2C <= 0) {
                work->unk_14C = 3;
            } else {
                work->unk_14C = 17;
            }
            work->unk_154 = 0;
        } else {
            work->unk_154++;
        }
        break;
    case 17:
        if (work->unk_154 == 0) {
            func_08012614(&actor->unk_40, 0);
            work->unk_156 = 10;
        }
        func_0800592C(&work->unk_180, 0x100, work->unk_156--);

        if (work->unk_156 <= 0) {
            actor->flags &= ~0x100;
            func_0801AF08(actor);
            work->unk_14C = work->unk_150;
            work->unk_154 = 0;
        } else {
            work->unk_154++;
        }
        break;
    case 6:
        if (work->unk_154 == 0) {
            func_08019068(work->unk_15C->unk_04, &work->anim, 0, 1, work->tiles);
            work->unk_17C = 0x100;
            work->unk_180 = 0x100;
            actor->unk_108 = 0;
            actor->unk_10C = 0;
        }
        work->unk_168 = 0;

        if (work->unk_154 == 40) {
            func_08019190(actor, 10);
            actor->unk_2C -= actor->unk_20;
            if (actor->unk_2C > actor->unk_2E) {
                actor->unk_2C = actor->unk_2E;
            }
            func_0801AF08(actor);
            work->unk_14C = work->unk_150;
            work->unk_154 = 0;
        } else {
            work->unk_154++;
        }
        break;
    case 10:
        if (work->unk_154 == 0) {
            work->unk_156 = 16;
        }
        actor->z -= (16 - work->unk_156) << 8;

        if (func_08006B74()) {
            gBldCnt = 0xF10;
            work->unk_162 = 4;
            SetBlendAlpha(16 - work->unk_156, work->unk_156);
        } else {
            work->unk_162 &= 0xFFFB;
        }
        ApproachValue(&work->unk_17C, 10, work->unk_156);
        ApproachValue(&work->unk_180, 0x200, work->unk_156);
        work->unk_156--;
        if (work->unk_156 <= 0) {
            if (gBtlWork->unk_0EE == 1 && gBtlWork->unk_120 <= 0) {
                func_08006B4C();
                func_08006120(2, 20);
                func_080063A8();
            }
            func_0801B994(actor);
            gBtlWork->unk_068 |= 0x10000;
            func_0801C830(actor);
            return 0;
        } else {
            work->unk_154++;
        }
        break;
    case 3:
        if (work->unk_154 == 0) {
            s32 t;

            func_08019068(work->unk_15C->unk_04, &work->anim, 1, 0, work->tiles);

            if (actor->flags & 0x800000000) {
                work->unk_154++;
                break;
            }
            if (actor->unk_108 != 0) {
                break;
            }
            if (actor->unk_10C != 0) {
                break;
            }
            if (actor->z != actor->unk_10) {
                break;
            }
            if (func_080128EC()) {
                break;
            }
            t = (actor->unk_9C / 2) * work->unk_16C;

            if (work->unk_158 & 1) {
                func_08013E4C(actor->x, actor->y, actor->z - t);
            } else {
                func_08013DB8(actor->x, actor->y, actor->z - t);
            }
            work->unk_154++;
        } else if (work->unk_154 > 0) {
            if (gBtlWork->unk_0EE == 1 && gBtlWork->unk_120 <= 0) {
                func_08006120(2, 20);
                func_080063A8();
            }
            func_0801B994(actor);

            if (gGameState.unk_1B8 == 6) {
                if (GetRandom() % 10 == 0) {
                    func_0801BBF0(actor);
                }
            } else {
                if (GetRandom() % 1000 == 0) {
                    func_0801BBF0(actor);
                }
            }
            gBtlWork->unk_068 |= 0x10000;
            func_0801C830(actor);
            return 0;
        }
        break;
    case 5:
        if (work->unk_154 == 0) {
            func_08019068(work->unk_15C->unk_04, &work->anim, 1, 0, work->tiles);
        }
        if (AnimIsFinished(&work->anim) && work->unk_154 > 40) {
            func_0801AF08(actor);
            work->unk_14C = work->unk_150;
            work->unk_154 = 0;
        } else {
            work->unk_154++;
        }
        break;
    }

    if (actor->unk_E8 != 2) {
        actor->z += work->unk_168;
        work->unk_168 += gBtlWork->unk_12C;

        if (actor->z > 0) {
            actor->z = 0;
            work->unk_168 = 0;
        }
        if (actor->unk_6C != 0 && !(actor->flags & 0x10) && !(actor->unk_90->unk_30 & 2)) {
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

    switch (func_0801A8A4(&actor->x, &actor->y, -20, 0)) {
    case 1:
    case 2:
        work->unk_158 |= 2;
        actor->unk_108 = -(actor->unk_108 >> 1);
        break;
    case 3:
    case 4:
        work->unk_158 |= 2;
        actor->unk_10C = -(actor->unk_10C >> 1);
        break;
    default:
        work->unk_158 &= 0xFFFD;
        break;
    }

    if (actor->flags & 0x10) {
        work->gfx = AnimUpdate(&work->anim);
    } else if (actor->unk_E8 != 2) {
        if (gBtlWork->unk_068 & 1) {
            if (!func_08005AC4(&work->anim)) {
                work->gfx = AnimUpdate(&work->anim);
            }
        } else {
            if (func_08005AC4(&work->anim)) {
                gBtlWork->unk_068 |= 1;
            }
            work->gfx = AnimUpdate(&work->anim);
        }
    }

    if (actor->unk_E8 == 5) {
        actor->x = actor->unk_FC;
        actor->y = actor->unk_100;
    }

    TaskPoolUpdate(&work->unk_028);
    func_08012324(&actor->unk_40, actor->x, actor->y, actor->z);
    return 1;
}
#else
INCLUDE_ASM("unk_0800c778/_0800CDF0.s");
#endif

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
        g = func_0801AF1C(actor->y) | work->unk_162;
        WorldToScreen(&x, &y, actor->x, actor->y, actor->z);

        if (work->unk_17C == 0x100 && work->unk_180 == 0x100) {
            if (actor->flags & 4) {
                sy = gBtlWork->unk_024;
                sx = sy;
            } else if (gBtlWork->unk_024 == 0x100) {
                sy = gBtlWork->unk_024;
                sx = sy;
                g |= 1;
            } else {
                sy = gBtlWork->unk_024;
                sx = -sy;
            }
        } else {
            if (actor->flags & 4) {
                sx = (gBtlWork->unk_024 * work->unk_17C) >> 8;
                sy = gBtlWork->unk_024;
                sy = (sy * work->unk_180) >> 8;
            } else {
                sx = -((gBtlWork->unk_024 * work->unk_17C) >> 8);
                sy = gBtlWork->unk_024;
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
            DrawSprite(x, y, work->gfx, work->tiles, work->unk_008, affine, g, (-4100 - ((actor->y >> 8) << 2)) | 3);
        } else {
            DrawSprite(x, y, work->gfx, work->tiles, work->unk_004, affine, g, (-4100 - ((actor->y >> 8) << 2)) | 3);
        }

        TaskPoolDraw(&work->unk_028);
    }
}

void func_0800E0D0(EmyWork* work) {
    gBtlWork->unk_0EC -= gUnk_09EDA4EC[work->unk_03C.unk_00];

    if (gBtlWork->unk_078 == &work->unk_03C) {
        gBtlWork->unk_078 = 0;
    }

    func_0801B7D8(&work->unk_03C);

    if (gBtlWork->unk_0EE == 0) {
        if (gBtlWork->unk_120 <= 0) {
            if (gBtlWork->unk_07C->unk_2C > 0) {
                gBtlWork->unk_068 |= 0x200000000;
            }
        }
    }

    ReleaseObjTiles(work->tiles);
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

#ifndef VERSION_EU
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
#else
INCLUDE_ASM("unk_0800c778/func_0800E5F0.s");
#endif

ALIGN_ZERO(2);
