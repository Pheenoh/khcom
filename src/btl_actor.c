#include "macros.h"
#include "battle.h"
#include "battle_actor.h"

void func_0800EEBC(Actor* p, SprObj* s) {
    s16 x;
    s16 y;
    Collider* c;
    u16 attr;
    s32 affine;
    u16 prio;
    s32 sx;
    s32 sy;

    if (s == 0) {
        return;
    }

    if (s->flags & 2) {
        return;
    }
    c = (Collider*)&p->unk_40;
    attr = GetBattleSpritePriorityFlags(s->y);

    if (*(u64*)&c->unk_34 & 4) {
        sy = gBtlWork->unk_024;
        sx = sy;
    } else {
        sy = gBtlWork->unk_024;

        if (sy == 0x100) {
            sx = sy;
            attr |= 1;
        } else {
            sx = -sy;
        }
    }

    if (sy == 0x100 && sx == 0x100) {
        affine = 0;
    } else if (sy <= 0xFF) {
        affine = AllocObjAffine(0, sx, sy, 0);
    } else {
        affine = AllocObjAffine(0, sx, sy, 1);
    }

    if (s->flags & 4) {
        prio = (-0x1004 - (s->y >> 8) * 4) | 3;
    } else if (s->flags & 1) {
        prio = ((-0x1004 - (c->unk_08 >> 8) * 4) | 3) - 1;
    } else {
        prio = ((-0x1004 - (c->unk_08 >> 8) * 4) | 3) + 1;
    }
    WorldToScreen(&x, &y, s->x, s->y, s->z);
    DrawSprite(x, y, s->gfx, s->tiles, s->palette, affine, attr, prio);
}

void func_0800EFE8(Actor* work) {
    s16 x;
    s16 y;
    BtlObj* c = (BtlObj*)&work->unk_40;
    u16 attr;
    s32 affine;
    s32 sx;
    s32 sy;
    s32 g;
    s16 idx;

    if (work->unk_154 & 0x20) {
        attr = 0x800;
    } else {
        attr = GetBattleSpritePriorityFlags(c->unk_008);
    }
    WorldToScreen(&x, &y, c->unk_004, c->unk_008, c->unk_00C);

    if (work->unk_168 == 0x100 && work->unk_16C == 0x100) {
        if (c->unk_034 & 4) {
            sy = gBtlWork->unk_024;
            sx = sy;
        } else {
            sy = gBtlWork->unk_024;

            if (sy == 0x100) {
                sx = sy;
                attr |= 1;
            } else {
                sx = -sy;
            }
        }
    } else {
        if (c->unk_034 & 4) {
            sx = (gBtlWork->unk_024 * work->unk_168 >> 8);
            g = gBtlWork->unk_024;
            sy = g * work->unk_16C >> 8;
        } else {
            sx = -(gBtlWork->unk_024 * work->unk_168 >> 8);
            g = gBtlWork->unk_024;
            sy = g * work->unk_16C >> 8;
        }
    }

    if (sy == 0x100 && sx == 0x100) {
        affine = 0;
    } else if (sy <= 0xFF) {
        affine = AllocObjAffine(0, sx, sy, 0);
    } else {
        affine = AllocObjAffine(0, sx, sy, 1);
    }

    if (work->unk_170 == 17) {
        idx = ((s16)work->unk_150 >> 2) % 8;

        if (work->unk_150 & 1) {
            work->unk_154 |= 2;
            LoadObjPaletteBank(work->palette->unk_06, gUnk_08F6DA04 + 32 + gUnk_08133E54[idx] * 32);
        } else {
            work->unk_154 &= ~2;
            LoadObjPaletteBank(work->palette->unk_06, work->unk_178);
        }
    } else if (func_0801CA00(c)) {
        work->unk_154 |= 2;
        LoadObjPaletteBank(work->palette->unk_06, gUnk_08F69BC4);
    } else if (work->unk_154 & 2) {
        work->unk_154 &= ~2;
        LoadObjPaletteBank(work->palette->unk_06, work->unk_178);
    }
    DrawSprite(x, y, work->gfx, work->tiles, work->palette, affine, attr, (-0x1004 - (c->unk_008 >> 8) * 4) | 3);
    func_0800EEBC(work, work->unk_0C);
    func_0800EEBC(work, work->unk_10);
    TaskPoolDraw(&work->unk_2C);
}
void func_0800F230(void) {
    BtlObj* c = gUnk_02039B9C->unk_07C;
    u8 keys;
    u16 t;

    if (gUnk_02039B9C->unk_068 & 0x1000000) {
        return;
    }
    t = gUnk_02039B9C->unk_1CC;

    if ((s16)t > 0) {
        gUnk_02039B9C->unk_1CC = t - 1;

        if (gUnk_02039B9C->unk_1CC == 0) {
            func_0807E260();
        }
        return;
    }
    keys = gBtlWork->unk_0EF;
    gBtlWork->unk_0EF = 0;

    if (keys & 1) {
        func_0807E1F4();
    }

    if (keys & 2) {
        func_0807E200();
    }

    if (keys & 4) {
        func_0807E260();
    }

    if (c->unk_034 & 0x200) {
        return;
    }

    if (gBtlWork->unk_068 & 0x40) {
        return;
    }

    if (gBtlWork->unk_068 & 0x10000000) {
        return;
    }

    if (gBtlWork->unk_068 & 0x800000) {
        return;
    }

    if (c->unk_034 & 2) {
        return;
    }

    if (keys & 0x10) {
        if (func_0807B3F8() > 2) {
            func_0807E224();
        } else {
            func_0807E218();
        }
    }

    if (keys & 0x20) {
        func_0807E20C();

        if (func_08081838() == 3 && !func_0807E34C()) {
            gUnk_02039B9C->unk_1CC = 15;
        }
    }
}

#ifdef VERSION_EU
void eu_08013190(void) {
    BtlObj* c = gUnk_02039B9C->unk_07C;
    u8 keys;

    keys = gBtlWork->unk_0EF;
    gBtlWork->unk_0EF = 0;
    if (c->unk_034 & 0x200) {
        return;
    }
    if (gBtlWork->unk_068 & 0x40) {
        return;
    }
    if (gBtlWork->unk_068 & 0x10000000) {
        return;
    }
    if (gBtlWork->unk_068 & 0x800000) {
        return;
    }
    if (c->unk_034 & 2) {
        return;
    }
    if (keys & 0x20) {
        func_0807E20C();
    }
}
#endif

void func_0800F368(Actor* p, u16 n) {
    s32 v;
    func_0801C700(&p->unk_40, &v, 0, 0);

    if (GetRandom() % n == 0) {
        if (p->unk_44 > v) {
            p->unk_74 |= 4;
        } else {
            p->unk_74 &= ~4;
        }
    }
}

u8 func_0800F3BC(Collider* c, s32 x, s32 y, s32 spd) {
    u8 ang = GetAngle(c->unk_44, c->unk_48, x, y);

    c->unk_44 += gSineTable[ang] * spd >> 8;
    c->unk_48 += -gSineTable[ang + 64] * spd >> 8;

    if (c->unk_44 - x >= 0 ? c->unk_44 - x > 0x1E00 : x - c->unk_44 > 0x1E00) {
        return 0;
    }

    if (c->unk_48 - y >= 0 ? c->unk_48 - y > 0x1000 : y - c->unk_48 > 0x1000) {
        return 0;
    }
    return 1;
}

u8 func_0800F440(Actor* p, s16 a, u16 b, u16 r) {
    s32 v0;
    s32 v1;
    Collider* c = (Collider*)&p->unk_40;
    s32 d;
    s32 t;
    s32 bb;
    s32 rr;

    func_0801C700(c, &v0, &v1, 0);
    rr = r << 8;
    d = c->unk_08 - v1;

    if (d >= 0 ? d > rr : v1 - c->unk_08 > rr) {
        return 0;
    }

    if (*(u64*)&c->unk_34 & 4) {
        t = c->unk_04 - (a << 8);
        bb = b << 8;

        if (t - bb > v0) {
            return 0;
        }

        if (t + bb < v0) {
            return 0;
        }
    } else {
        t = c->unk_04 + (a << 8);
        bb = b << 8;

        if (t + bb < v0) {
            return 0;
        }

        if (t - bb > v0) {
            return 0;
        }
    }
    return 1;
}

u8 func_0800F4C8(BtlObj* p, u16 b) {
    if (p->unk_040.unk_04 < (gBtlWork->unk_0DA + b) << 8) {
        return 1;
    }

    if (p->unk_040.unk_04 > (gBtlWork->unk_0DC - b) << 8) {
        return 1;
    }
    return 0;
}

u8 func_0800F504(Actor* p, s16 a, u16 b, u16 r) {
    s32 v0;
    s32 v1;
    Collider* c = (Collider*)&p->unk_40;
    BtlObj* o = gBtlWork->unk_07C;
    s32 d;
    s32 t;
    s32 bb;
    s32 rr;

    func_0801C700(c, &v0, &v1, 0);
    rr = r << 8;
    d = c->unk_08 - v1;

    if (d >= 0 ? d > rr : v1 - c->unk_08 > rr) {
        return 0;
    }

    if (o->unk_034 & 4) {
        t = v0 - (a << 8);
        bb = b << 8;

        if (t - bb > c->unk_04) {
            return 0;
        }

        if (t + bb < c->unk_04) {
            return 0;
        }
    } else {
        t = v0 + (a << 8);
        bb = b << 8;

        if (t + bb < c->unk_04) {
            return 0;
        }

        if (t - bb > c->unk_04) {
            return 0;
        }
    }
    return 1;
}

u8 func_0800F5A4(Actor* work, u16 interval, u16 offset, u16 width, u16 depth) {
    u32 value;
    u32 cards;
    u32 id;
    s32 count;
    s32 n;

    if (gBtlWork->unk_068 & 0x40) {
        return 0;
    }
    if ((s16)gUnk_02039B9C->unk_1CC > 0) {
        return 0;
    }
    if ((u16)((u32)GetRandom() % interval) != 0) {
        return 0;
    }
    value = func_08081870();
    cards = func_0807B3F8();
    id = func_0807E2BC();
    count = func_0807E33C();
    switch (id) {
    case 47:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
        n = count >> 1;
        if (n <= 0) {
            n = 1;
        }
        if (GetRandom() % n == 0) {
            gBtlWork->unk_0EF |= 0x20;
        } else {
            gBtlWork->unk_0EF |= 1;
        }
        return 0;
    }
    if (func_0807E29C()) {
        if (count > 1 && (u16)(GetRandom() % 20U) == 0) {
            gBtlWork->unk_0EF |= 1;
        }
        return 0;
    }
    if (func_08081838() == 3) {
        if ((GetRandom() & 3) == 0) {
            if (count <= 0) {
                work->unk_154 |= 0x10;
                gBtlWork->unk_0EF |= 4;
            } else {
                gBtlWork->unk_0EF |= 0x20;
                if (count == 1) {
                    work->unk_154 |= 0x10;
                }
            }
        } else if (count > 1) {
            gBtlWork->unk_0EF |= 1;
        }
        return 0;
    }
    if (!(work->unk_154 & 0x10) && gUnk_02039B9C->unk_0F4 == 0
        && (u16)(GetRandom() % 60U) == 0) {
        gBtlWork->unk_0EF |= 4;
        return 0;
    }
    if (cards > 2) {
        if ((u16)(GetRandom() % 6U) == 0) {
            gBtlWork->unk_0EF |= 0x10;
            return 1;
        }
    } else if ((u16)GetRandom() % 2 == 0) {
        if (count <= 1 && cards != 0) {
            gBtlWork->unk_0EF |= 0x10;
            return 1;
        }
        if (value == 0 || work->unk_184[cards] != id) {
            gBtlWork->unk_0EF |= 1;
        } else {
            gBtlWork->unk_0EF |= 0x10;
        }
        return 0;
    }
    if (gBtlWork->unk_068 & 0x20000000) {
        if (func_0800F440(work, (s16)offset, width, depth)) {
            if (func_08081848() <= value || value == 0) {
                gBtlWork->unk_0EF |= 0x20;
            }
        } else if (func_08081848() == value) {
            gBtlWork->unk_0EF |= 0x20;
        }
    } else if (func_0800F440(work, (s16)offset, width, depth)) {
        gBtlWork->unk_0EF |= 0x20;
    }
    return 0;
}
s32 _0800F84C(Actor* work) {
    s32 buf[6];
    s32 id = func_080ABA80(buf);

    if (id == 145) {
        if (!(gUnk_02039B9C->unk_068 & 2)) {
            gUnk_02039B9C->unk_068 |= 2;
            gUnk_02039B9C->unk_0B2 = 0;
        }
        id = buf[gUnk_02039B9C->unk_0B2];
        gUnk_02039B9C->unk_0B2++;
    }
    work->unk_150 = 0;

    switch (id) {
    case 47:
        work->unk_170 = 18;
        work->unk_17E = 0;
        break;
    case 48:
        work->unk_170 = 18;
        work->unk_17E = 1;
        break;
    case 49:
        work->unk_170 = 18;
        work->unk_17E = 2;
        break;
    case 50:
        work->unk_170 = 18;
        work->unk_17E = 3;
        break;
    case 51:
        work->unk_170 = 18;
        work->unk_17E = 4;
        break;
    case 52:
        work->unk_170 = 18;
        work->unk_17E = 5;
        break;
    case 53:
        work->unk_170 = 18;
        work->unk_17E = 6;
        break;
    }
    return id;
}

ALIGN_ZERO(2);
