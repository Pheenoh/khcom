#include "display.h"
#include "mode_vsbattle.h"
#include "enemy_common.h"

void func_0800C778(EmyWork* work, const EmyDef* def, EmyObj* obj) {
    BtlObj* actor = &work->actor;
    u16 t;

    func_0801B37C(actor, &def->kind, obj->x, obj->y, obj->z);
    actor->unk_0CE = def->unk_12;
    actor->unk_0D0 = def->unk_14;
    actor->unk_0D2 = def->unk_16;
    actor->unk_0B2 = def->unk_18;

    if (gBtlWork->actor->x < actor->x) {
        actor->flags |= 4;
    }

    actor->flags |= 0x300;
    t = gUnk_09EDA4EC[actor->unk_000];
    work->def = def;
    work->tiles = AllocObjTiles(t * 32, 0);
    work->palette = LoadObjPalette(def->palette, 32);
    work->palette2 = LoadObjPalette(gUnk_08F69BC4, 32);
    work->unk_150 = 0;
    work->unk_14C = 11;
    work->unk_154 = 0;
    work->unk_156 = 0;
    work->flags = 0;
    work->unk_15A = 1;
    work->angle = 0;
    work->unk_164 = def->unk_08;
    work->unk_168 = 0;
    actor->vx = 0;
    actor->vy = 0;
    work->unk_162 = 0;

    if (actor->flags & 0x20000) {
        work->unk_16C = 281;
    } else {
        work->unk_16C = 0x100;
    }

    work->x = 0;
    work->y = 0;
    work->unk_178 = 0;
    AnimInit(&work->anim, 0, 0);
    AnimChangeWithDef(work->def->animDef, &work->anim, 0, 1, work->tiles);
    work->gfx = AnimGetGfx(&work->anim);
    TaskPoolInit(&work->tasks, 3);

    if (!(def->flags & 1)) {
        TaskCreate(&work->tasks, &gTaskDescBtlShadow, actor);
    }

    TaskCreate(&work->tasks, &gTaskDescBtlBadstatus, actor);

    if (def->flags & 2) {
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
    BtlObj* actor = &work->actor;
    s32 ret;
    s32 v;
    s32 target;
    s16 steps;

    ret = 0;

    if (work->unk_154 == 0) {
        work->flags &= ~4;
    }

    if (work->unk_154 >= a) {
        if (work->unk_154 < a + b) {
            steps = (a + b) - work->unk_154;
            target = actor->unk_018;

            if (work->actor.flags & 4) {
                v = actor->unk_014 - (e << 8);
            } else {
                v = actor->unk_014 + (e << 8);
            }

            if (actor->unk_0E8 != 5) {
                ApproachValueHalfSteps(&actor->x, v, steps);
                ApproachValueHalfSteps(&actor->y, target, steps);
            }

            if (!(work->flags & 4)) {
                if (actor->flags & 4) {
                    if (func_08011F78(d, actor->x - (g << 8), actor->y, actor->z + (h << 8), (s16)i, i / 2, (s16)i) != 0) {
                        m4aSongNumStart(f);
                        work->flags |= 4;
                        ret = 1;
                    }
                } else {
                    if (func_08011F78(d, actor->x + (g << 8), actor->y, actor->z + (h << 8), (s16)i, i / 2, (s16)i) != 0) {
                        m4aSongNumStart(f);
                        ret = 1;
                        work->flags |= 4;
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
    func_0801AF08(&work->actor);
    work->unk_14C = work->unk_150;
    work->unk_154 = 0;
}

void func_0800CB78(EmyWork* work) {
    work->unk_168 = -work->actor.unk_0AC * 3;
    work->actor.vx = ((gSineTable[work->actor.angle] << 1) * work->actor.unk_0A8) >> 8;
    work->actor.vy = ((-gSineTable[work->actor.angle + 0x40] << 1) * work->actor.unk_0A8) >> 8;
}


u8 _0800CBDC(EmyWork* work) {
    BtlObj* actor = &work->actor;

    actor->unk_0FC = actor->x;
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
            actor->vx = actor->vy = 0;
        }
        break;
    }

    return 0;
}

void func_0800CD40(EmyWork* work) {
    BtlObj* actor = &work->actor;

    if (gGameState.flags & 4) {
        actor->flags |= 0x4002;

        if (gGameState.unk_1B8 == 3) {
            actor->unk_020 = (actor->unk_02E * 204) >> 8;
        } else {
            actor->unk_020 = (actor->unk_02E * 25) >> 8;
        }

        actor->unk_024 = 0x200;
        gBtlWork->unk_076 = 0;
        actor->unk_0A8 = 0;
        actor->unk_0AC = 0;
    }

    work->unk_14C = work->unk_150;
    work->unk_154 = 0;
    actor->flags &= ~0x300;
}

s32 _0800CDF0(EmyWork* work) {
    BtlObj* actor = &work->actor;
    s32 x;
    s32 y;
    s32 z;

    func_0801C700(actor, &x, &y, &z);

    if (gBtlWork->flags & 0x2000) {
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
        AnimChangeWithDef(work->def->animDef, &work->anim, 2, 1, work->tiles);
        func_0801BCF8(actor);
        actor->z += ((work->unk_178 + gSineTable[gFrameCounter & 0xFF] * 10) - actor->z) >> 4;

        if (GetRandom() % work->def->unk_0E == 0) {
            if (actor->x > x) {
                actor->flags |= 4;
            } else {
                actor->flags &= ~4;
            }
        }
        if (gBtlWork->flags & 0x40000) {
            s32 tx;
            s32 ty;
            s32 d;

            tx = work->x;
            ty = work->y;
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
        AnimChangeWithDef(work->def->animDef, &work->anim, 0, 1, work->tiles);
        func_0801BCF8(actor);
        actor->z += ((work->unk_178 + gSineTable[gFrameCounter * 2 & 0xFF] * 12) - actor->z) >> 4;

        if (GetRandom() % work->def->unk_0E == 0) {
            if (actor->x > x) {
                actor->flags |= 4;
            } else {
                actor->flags &= ~4;
            }
        }
        if (GetRandom() % work->def->unk_0C == 0) {
            work->unk_164 = 0;
            work->unk_14C = 8;

            if (GetRandom() % 2 == 0) {
                s32 lo;

                work->x = x - ((actor->unk_0CE + ((lo = -actor->unk_0D0) + GetRandom() % (actor->unk_0D0 - lo + 1))) << 8);
            } else {
                s32 lo;

                work->x = x + ((actor->unk_0CE + ((lo = -actor->unk_0D0) + GetRandom() % (actor->unk_0D0 - lo + 1))) << 8);
            }
            work->y = y + ((GetRandom() % 121 - 60) << 8);
            work->unk_178 = -((GetRandom() % 49 + 16) << 8);
            work->unk_154 = 0;
        } else {
            work->unk_154++;
        }
        break;
    case 13:
        if (work->unk_154 == 0) {
            AnimReset(&work->anim);
            AnimChangeWithDef(work->def->animDef, &work->anim, 1, 0, work->tiles);
            actor->unk_014 = actor->x;
            actor->unk_018 = actor->y;
        }
        switch (work->unk_154 % 4) {
        case 0:
            actor->x = actor->unk_014 + 0x100;
            actor->y = actor->unk_018;
            break;
        case 1:
            actor->x = actor->unk_014 - 0x100;
            actor->y = actor->unk_018;
            break;
        case 2:
            actor->x = actor->unk_014;
            actor->y = actor->unk_018 + 0x100;
            break;
        case 3:
            actor->x = actor->unk_014;
            actor->y = actor->unk_018 - 0x100;
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
        if (gBtlWork->flags & 0x40000) {
            s32 tx;
            s32 ty;

            if (work->unk_154 == 0) {
                AnimChangeWithDef(work->def->animDef, &work->anim, 2, 1, work->tiles);
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
            actor->x += ((gSineTable[work->angle] << 1) * work->def->unk_08) >> 8;
            actor->y += ((-gSineTable[work->angle + 64] << 1) * work->def->unk_08) >> 8;

            if ((s8)work->angle >= 0) {
                actor->flags &= ~4;
            } else {
                actor->flags |= 4;
            }
            if (actor->unk_0E8 != 4) {
                work->unk_14C = work->unk_150;
                work->unk_154 = 0;
            } else {
                work->unk_154++;
            }
        }
        break;
    case 4:
        if (gBtlWork->flags & 0x40000) {
            s32 px;
            s32 tx;
            s32 ty;
            s32 d;

            AnimChangeWithDef(work->def->animDef, &work->anim, 2, 1, work->tiles);
            func_0801BCF8(actor);
            px = x;
            tx = px + work->x;
            ty = y;

            if (tx < (gBtlWork->unk_0DA + 32) << 8) {
                tx = px + ((actor->unk_0CE + actor->unk_0D0) << 8);
            } else if (tx > (gBtlWork->unk_0DC - 32) << 8) {
                tx = ty - ((actor->unk_0CE + actor->unk_0D0) << 8);
            }
            if (GetRandom() % 100 == 0) {
                if (GetRandom() % 2 == 0) {
                    s32 lo;

                    work->x = -((actor->unk_0CE + ((lo = -actor->unk_0D0) + GetRandom() % (actor->unk_0D0 - lo + 1))) << 8);
                } else {
                    s32 lo;

                    work->x = ((actor->unk_0CE + ((lo = -actor->unk_0D0) + GetRandom() % (actor->unk_0D0 - lo + 1))) << 8);
                }
            } else {
                if ((tx - actor->x >= 0 ? tx - actor->x : actor->x - tx) > 0x400
                    || (ty - actor->y >= 0 ? ty - actor->y : actor->y - ty) > 0x400) {
                    work->angle = GetAngle(actor->x, actor->y, tx, ty);
                    actor->x += (gSineTable[work->angle] * work->unk_164) >> 8;
                    actor->y += (-gSineTable[work->angle + 64] * work->unk_164) >> 8;
                } else if (AnimIsFinished(&work->anim)) {
                    work->unk_14C = work->unk_150;
                }
            }
            if (GetRandom() % work->def->unk_0E == 0) {
                if (actor->x > x) {
                    actor->flags |= 4;
                } else {
                    actor->flags &= ~4;
                }
            }
        }
        break;
    case 0:
        AnimChangeWithDef(work->def->animDef, &work->anim, 0, 1, work->tiles);
        func_0801BCF8(actor);

        if (GetRandom() % work->def->unk_0C == 0) {
            work->unk_14C = 4;

            if (GetRandom() % 2 == 0) {
                s32 lo;

                work->x = -((actor->unk_0CE + ((lo = -actor->unk_0D0) + GetRandom() % (actor->unk_0D0 - lo + 1))) << 8);
            } else {
                s32 lo;

                work->x = ((actor->unk_0CE + ((lo = -actor->unk_0D0) + GetRandom() % (actor->unk_0D0 - lo + 1))) << 8);
            }
        }
        if (GetRandom() % work->def->unk_0E == 0) {
            if (actor->x > x) {
                actor->flags |= 4;
            } else {
                actor->flags &= ~4;
            }
        }
        break;
    case 12:
        if (actor->unk_0E8 != 2) {
            work->unk_14C = work->unk_150;
            func_0801AF08(actor);
        }
        break;
    case 9:
        if (work->unk_154 == 0) {
            AnimReset(&work->anim);
            AnimChangeWithDef(work->def->animDef, &work->anim, 1, 0, work->tiles);
            work->unk_154++;
        }
        if (AnimIsFinished(&work->anim)) {
            actor->flags &= ~0x80;
            actor->flags &= ~0x2000;
        }
        if (GetRandom() % 10 == 0) {
            actor->unk_0EC--;
        }
        if (actor->unk_0E8 != 1) {
            func_0801AF08(actor);
            work->unk_14C = work->unk_150;
            work->unk_154 = 0;
        }
        break;
    case 1:
        if (work->unk_154 == 0) {
            AnimReset(&work->anim);
            AnimChangeWithDef(work->def->animDef, &work->anim, 1, 0, work->tiles);
        }
        if (work->unk_154 >= work->def->unk_10) {
            s32 ok = 0;

            func_0801AF08(actor);
            work->unk_14C = 2;
            work->unk_154 = 0;

            if (actor->x < x) {
                if (actor->flags & 4) {
                    if (GetRandom() % 5 == 0) {
                        actor->flags &= ~4;
                        ok = 1;
                    }
                } else {
                    ok = 1;
                }
            } else {
                if (actor->flags & 4) {
                    ok = 1;
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
            ColliderSetDisabled(&actor->collider, 1);
            actor->flags |= 0x100;
            AnimChangeWithDef(work->def->animDef, &work->anim, 1, 0, work->tiles);
            work->anim.frame = 0;
            work->anim.timer = 0;
            work->unk_168 = 0x400;
            actor->vx = 0;
            actor->vy = 0;
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
            if (actor->unk_02C <= 0) {
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
            ColliderSetDisabled(&actor->collider, 0);
            work->unk_156 = 10;
        }
        ApproachValueHalfSteps(&work->unk_180, 0x100, work->unk_156--);

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
            AnimChangeWithDef(work->def->animDef, &work->anim, 0, 1, work->tiles);
            work->unk_17C = 0x100;
            work->unk_180 = 0x100;
            actor->vx = 0;
            actor->vy = 0;
        }
        work->unk_168 = 0;

        if (work->unk_154 == 40) {
            func_08019190(actor, 10);
            actor->unk_02C -= actor->unk_020;
            if (actor->unk_02C > actor->unk_02E) {
                actor->unk_02C = actor->unk_02E;
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

        if (BgAnimIsStopped()) {
            gBldCnt = (BLDCNT_TGT1_OBJ | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3);
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
                BgAnimStop();
                FadeStartIn(2, 20);
                FadeLock();
            }
            func_0801B994(actor);
            func_0801C830(actor);
            return 0;
        } else {
            work->unk_154++;
        }
        break;
    case 3:
        if (work->unk_154 == 0) {
            s32 t;

            AnimChangeWithDef(work->def->animDef, &work->anim, 1, 0, work->tiles);

            if (actor->flags & 0x800000000) {
                work->unk_154++;
                break;
            }
            if (actor->vx != 0) {
                break;
            }
            if (actor->vy != 0) {
                break;
            }
            if (actor->z != actor->unk_010) {
                break;
            }
            if (func_080128EC()) {
                break;
            }
            t = (actor->unk_09C / 2) * work->unk_16C;

            if (work->flags & 1) {
                func_08013E4C(actor->x, actor->y, actor->z - t, work->unk_16C);
            } else {
                func_08013DB8(actor->x, actor->y, actor->z - t, work->unk_16C);
            }
            work->unk_154++;
        } else if (work->unk_154 > 0) {
            if (gBtlWork->unk_0EE == 1 && gBtlWork->unk_120 <= 0) {
                FadeStartIn(2, 20);
                FadeLock();
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
            gBtlWork->flags |= 0x10000;
            func_0801C830(actor);
            return 0;
        }
        break;
    case 5:
        if (work->unk_154 == 0) {
            AnimChangeWithDef(work->def->animDef, &work->anim, 1, 0, work->tiles);
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

    if (actor->unk_0E8 != 2) {
        actor->z += work->unk_168;
        work->unk_168 += gBtlWork->unk_12C;

        if (actor->z > 0) {
            actor->z = 0;
            work->unk_168 = 0;
        }
        if (actor->collider.unk_2C != 0 && !(actor->flags & 0x10) && !(actor->collider.other->unk_30 & 2)) {
            actor->x += actor->collider.unk_38 >> 1;
            actor->y += actor->collider.unk_3C >> 1;
        }
    }

    if (actor->vx > 0) {
        actor->x += actor->vx;
        actor->vx -= 17;
        if (actor->vx < 0) {
            actor->vx = 0;
        }
    } else if (actor->vx < 0) {
        actor->x += actor->vx;
        actor->vx += 17;
        if (actor->vx > 0) {
            actor->vx = 0;
        }
    }

    if (actor->vy > 0) {
        actor->y += actor->vy;
        actor->vy -= 17;
        if (actor->vy < 0) {
            actor->vy = 0;
        }
    } else if (actor->vy < 0) {
        actor->y += actor->vy;
        actor->vy += 17;
        if (actor->vy > 0) {
            actor->vy = 0;
        }
    }

    switch (ClampBattlePosition(&actor->x, &actor->y, -20, 0)) {
    case 1:
    case 2:
        work->flags |= 2;
        actor->vx = -(actor->vx >> 1);
        break;
    case 3:
    case 4:
        work->flags |= 2;
        actor->vy = -(actor->vy >> 1);
        break;
    default:
        work->flags &= 0xFFFD;
        break;
    }

    if (actor->flags & 0x10) {
        work->gfx = AnimUpdate(&work->anim);
    } else if (actor->unk_0E8 != 2) {
        if (gBtlWork->flags & 1) {
            if (!AnimIsFrameEnding(&work->anim)) {
                work->gfx = AnimUpdate(&work->anim);
            }
        } else {
            if (AnimIsFrameEnding(&work->anim)) {
                gBtlWork->flags |= 1;
            }
            work->gfx = AnimUpdate(&work->anim);
        }
    }

    if (actor->unk_0E8 == 5) {
        actor->x = actor->unk_0FC;
        actor->y = actor->unk_100;
    }

    TaskPoolUpdate(&work->tasks);
    ColliderSetPosition(&actor->collider, actor->x, actor->y, actor->z);
    return 1;
}

void func_0800DF30(EmyWork* work) {
    if (work->unk_15A != 0) {
        BtlObj* actor;
        u16 g;
        s32 affine;
        s32 sx;
        s32 sy;
        s16 x;
        s16 y;

        actor = &work->actor;
        g = GetBattleSpritePriorityFlags(actor->y) | work->unk_162;
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
            DrawSprite(x, y, work->gfx, work->tiles, work->palette2, affine, g, (-4100 - ((actor->y >> 8) << 2)) | 3);
        } else {
            DrawSprite(x, y, work->gfx, work->tiles, work->palette, affine, g, (-4100 - ((actor->y >> 8) << 2)) | 3);
        }

        TaskPoolDraw(&work->tasks);
    }
}

void func_0800E0D0(EmyWork* work) {
    gBtlWork->unk_0EC -= gUnk_09EDA4EC[work->actor.unk_000];

    if (gBtlWork->actor2 == (BtlObj*)&work->actor) {
        gBtlWork->actor2 = 0;
    }

    func_0801B7D8(&work->actor);

    if (gBtlWork->unk_0EE == 0) {
        if (gBtlWork->unk_120 <= 0) {
            if (gBtlWork->actor->unk_02C > 0) {
                gBtlWork->flags |= 0x200000000;
            }
        }
    }

    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ReleaseObjPalette(work->palette2);
    TaskPoolDestroy(&work->tasks);
}
