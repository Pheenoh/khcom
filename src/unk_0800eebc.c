#include "macros.h"
#include "unk_0800eebc.h"

UnkStruct_02039CA8 gUnk_02039CA8;

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
    attr = func_0801AF1C(s->y);

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

#ifdef NON_MATCHING
void func_0800EFE8(Actor* work) {
    s16 x;
    s16 y;
    Collider* c = (Collider*)&work->unk_40;
    u16 attr;
    s32 affine;
    s32 sx;
    s32 sy;
    s32 g;
    s16 idx;

    if (work->unk_154 & 0x20) {
        attr = 0x800;
    } else {
        attr = func_0801AF1C(c->unk_08);
    }
    WorldToScreen(&x, &y, c->unk_04, c->unk_08, c->unk_0C);

    if (work->unk_168 == 0x100 && work->unk_16C == 0x100) {
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
    } else {
        if (*(u64*)&c->unk_34 & 4) {
            sx = gBtlWork->unk_024 * work->unk_168 >> 8;
            g = gBtlWork->unk_024;
        } else {
            sx = -(gBtlWork->unk_024 * work->unk_168 >> 8);
            g = gBtlWork->unk_024;
        }
        sy = g * work->unk_16C >> 8;
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
    } else if (func_0801CA00((BtlObj*)c)) {
        work->unk_154 |= 2;
        LoadObjPaletteBank(work->palette->unk_06, gUnk_08F69BC4);
    } else if (work->unk_154 & 2) {
        work->unk_154 &= ~2;
        LoadObjPaletteBank(work->palette->unk_06, work->unk_178);
    }
    DrawSprite(x, y, work->gfx, work->tiles, work->palette, affine, attr, (-0x1004 - (c->unk_08 >> 8) * 4) | 3);
    func_0800EEBC(work, work->unk_0C);
    func_0800EEBC(work, work->unk_10);
    TaskPoolDraw(&work->unk_2C);
}
#else
INCLUDE_ASM("unk_0800eebc/func_0800EFE8.s");
#endif
void func_0800F230(void) {
    Collider* c = gUnk_02039B9C->unk_07C;
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

    if (*(u64*)&c->unk_34 & 0x200) {
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

    if (*(u64*)&c->unk_34 & 2) {
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
INCLUDE_ASM("unk_0800eebc/eu_08013190.s");
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
    Collider* o = gBtlWork->unk_07C;
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

    if (*(u64*)&o->unk_34 & 4) {
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

INCLUDE_ASM("unk_0800eebc/func_0800F5A4.s");
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

#ifdef NON_MATCHING
void func_0800F988(UnkStruct_02039CA8* p) {
    s32 n = p->level + 1;
    p->nextExp += n * n * 3;
}
#else
INCLUDE_ASM("unk_0800eebc/func_0800F988.s");
#endif

void func_0800F9A0(void) {
    gUnk_02039CA8.maxHp = 0x50;
    gUnk_02039CA8.cp = 0x113;
    gUnk_02039CA8.dp = 8;
    gUnk_02039CA8.ap = 10;
    gUnk_02039CA8.exp = 0;
    gUnk_02039CA8.level = 1;
    gUnk_02039CA8.unk_14[0] = 0;
    gUnk_02039CA8.unk_14[1] = 0;
    gUnk_02039CA8.unk_14[2] = 0;
    gUnk_02039CA8.unk_14[3] = 0;
    gUnk_02039CA8.unk_14[4] = 0;
    gUnk_02039CA8.unk_14[5] = 0;
    gUnk_02039CA8.unk_14[6] = 0;
    gUnk_02039CA8.unk_14[7] = 0;
    gUnk_02039CA8.unk_14[8] = 0;
    gUnk_02039CA8.unk_14[9] = 0;
    gUnk_02039CA8.unk_14[10] = 0;
    gUnk_02039CA8.unk_14[11] = 0;
    gUnk_02039CA8.unk_14[12] = 0;
    gUnk_02039CA8.unk_7C = 0;
    gUnk_02039CA8.unk_80 = 0;
    gUnk_02039CA8.unk_82 = 0;
    gUnk_02039CA8.unk_84 = 0;
    gUnk_02039CA8.nextExp = 0x19;
    func_080C6FF8();
    func_080DDEA4();
    func_08109620();
}

u8 LevelUp(void) {
    if (gUnk_02039CA8.level + gBtlWork->unk_0FA + 1 <= 99) {
        gBtlWork->unk_0FA++;
        gUnk_02039CA8.level++;
        func_0800F988(&gUnk_02039CA8);
        return 1;
    } else {
        return 0;
    }
}
s32 func_0800FA58(void) {
    gGameState.maxHp += 15;
    if (gGameState.maxHp > 560) {
        gGameState.maxHp = 560;
    }
    return 15;
}
s32 func_0800FA7C(void) {
    gGameState.cp += 25;
    if (gGameState.cp > 9999) {
        gGameState.cp = 9999;
    }
    return 25;
}
s32 func_0800FAA0(void) {
    gGameState.dp += 2;
    if (gGameState.dp > 999) {
        gGameState.dp = 999;
    }
    return 2;
}
s32 func_0800FAC4(void) {
    gGameState.ap += 1;
    if (gGameState.ap > 999) {
        gGameState.ap = 999;
    }
    return 1;
}
void AddExp(u16 a) {
    gUnk_02039CA8.exp += a;
}

u8 CanLevelUp(void) {
    if (gUnk_02039CA8.exp >= gUnk_02039CA8.nextExp) {
        return 1;
    }
    return 0;
}

const UnkStruct_08133E5C* func_0800FB14(u16 i) {
    if (i > 0x35) {
        return 0;
    }
    return &gUnk_08133E5C[i];
}

void func_0800FB2C(u32 a) {
    u8* q;
    u8* z;

    if (a == 72) {
        z = (u8*)&gGameState;
        *(u64*)(z + 0x10C) = -1;
        *(u64*)(z + 0x114) = -1;
        return;
    }

    if (func_0800FBCC(a)) {
        return;
    }

    if (a <= 0x1E) {
        q = (u8*)&gGameState;
        *(u64*)(q + 0x10C) |= 1LL << a;
        *(u64*)(q + 0x11C) |= 1LL << a;
    } else {
        a -= 0x1F;
        q = (u8*)&gGameState;
        *(u64*)(q + 0x114) |= 1LL << a;
        *(u64*)(q + 0x124) |= 1LL << a;
    }
}

u8 func_0800FBCC(u32 a) {
    u64* p;
    u8* q;

    if (a <= 0x1E) {
        q = (u8*)&gGameState;
        q += 0x10C;
    } else {
        a -= 0x1F;
        q = (u8*)&gGameState;
        q += 0x114;
    }
    p = (u64*)q;
    if (*p & (1LL << a)) {
        return 1;
    }
    return 0;
}

void func_0800FC14(s32 a) {
    if (a == 0x3A) {
        gGameState.unk_12C = -1;
    } else {
        gGameState.unk_12C |= 1LL << a;
    }
}

u8 func_0800FC5C(s32 a) {
    if (gGameState.unk_12C & (1LL << a)) {
        return 1;
    }
    return 0;
}

u8 func_0800FC90(u32 a) {
    u64* p;
    u8* q;

    if (a <= 0x1E) {
        q = (u8*)&gGameState;
        q += 0x1E8;
    } else {
        a -= 0x1F;
        q = (u8*)&gGameState;
        q += 0x1F0;
    }
    p = (u64*)q;
    if (*p & (1LL << a)) {
        return 1;
    }
    return 0;
}

u8 func_0800FCD8(u32 a) {
    u64* p;
    u8* q;

    if (a <= 0x1E) {
        q = (u8*)&gGameState;
        q += 0x200;
    } else {
        a -= 0x1F;
        q = (u8*)&gGameState;
        q += 0x208;
    }
    p = (u64*)q;
    if (*p & (1LL << a)) {
        return 1;
    }
    return 0;
}

u8 func_0800FD20(u32 a) {
    u64* p;
    u8* q;

    if (a <= 0x1E) {
        q = (u8*)&gGameState;
        q += 0x11C;
    } else {
        a -= 0x1F;
        q = (u8*)&gGameState;
        q += 0x124;
    }
    p = (u64*)q;
    if (*p & (1LL << a)) {
        return 1;
    }
    return 0;
}

void func_0800FD68(u32 a) {
    u64* p;
    u8* q;

    if (a == 0x48) {
        GameState* s = &gGameState;
        s->unk_11C = 0;
        s->unk_124 = 0;
    } else {
        if (a <= 0x1E) {
            q = (u8*)&gGameState;
            q += 0x11C;
        } else {
            a -= 0x1F;
            q = (u8*)&gGameState;
            q += 0x124;
        }
        p = (u64*)q;
        *p &= ~(1LL << a);
    }
}

INCLUDE_ASM("unk_0800eebc/func_0800FDD0.s");

u8 func_0800FF00(u32 a) {
    u64* p;
    u8* q;

    if (a <= 0x3F) {
        q = (u8*)&gGameState;
        q += 0x134;
    } else if (a <= 0x7F) {
        a -= 0x40;
        q = (u8*)&gGameState;
        q += 0x13C;
    } else if (a <= 0xBF) {
        a -= 0x80;
        q = (u8*)&gGameState;
        q += 0x144;
    } else {
        a -= 0xC0;
        q = (u8*)&gGameState;
        q += 0x14C;
    }
    p = (u64*)q;
    if (*p & (1LL << a)) {
        return 1;
    }
    return 0;
}

u8 func_0800FF70(u32 a) {
    u64* p;
    u8* q;

    if (a <= 0x3F) {
        q = (u8*)&gGameState;
        q += 0x154;
    } else if (a <= 0x7F) {
        a -= 0x40;
        q = (u8*)&gGameState;
        q += 0x15C;
    } else if (a <= 0xBF) {
        a -= 0x80;
        q = (u8*)&gGameState;
        q += 0x164;
    } else {
        a -= 0xC0;
        q = (u8*)&gGameState;
        q += 0x16C;
    }
    p = (u64*)q;
    if (*p & (1LL << a)) {
        return 1;
    }
    return 0;
}

void func_0800FFE0(u32 a) {
    u64* p;
    u8* q;
    u8* z;

    if (a == 250) {
        z = (u8*)&gGameState;
        *(u64*)(z + 0x154) = 0;
        *(u64*)(z + 0x15C) = 0;
        *(u64*)(z + 0x164) = 0;
        *(u64*)(z + 0x16C) = 0;
        return;
    }

    if (a <= 0x3F) {
        q = (u8*)&gGameState;
        q += 0x154;
    } else if (a <= 0x7F) {
        a -= 0x40;
        q = (u8*)&gGameState;
        q += 0x15C;
    } else if (a <= 0xBF) {
        a -= 0x80;
        q = (u8*)&gGameState;
        q += 0x164;
    } else {
        a -= 0xC0;
        q = (u8*)&gGameState;
        q += 0x16C;
    }
    p = (u64*)q;
    *p &= ~(1LL << a);
}
