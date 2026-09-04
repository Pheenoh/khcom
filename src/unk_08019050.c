#include "macros.h"
#include "unk_0800eebc.h"

s32 gUnk_02039DC0;

void func_08019050(u16 a, s32 b, s32 c, s32 d) {
    gBtlWork->unk_028 = b;
    gBtlWork->unk_01A = a;
    gBtlWork->unk_01C = c;
    gBtlWork->unk_020 = d;
}

void func_08019068(AnimDef* tbl, void* a, u16 i, u16 j, void* obj) {
    AnimDef* e = &tbl[i];
    func_08005974(a, e->unk_0C, j, e->unk_04, e->unk_00);
    func_08002A10(obj, e->unk_08);
}

#ifdef NON_MATCHING
void WorldToScreen(s16* a, s16* b, s32 px, s32 py, s32 pz) {
    s16 x;
    s16 y;
    u8 ang;
    s32 c;
    s32 u;
    s32 v;

    if (gBtlWork->unk_024 == 0x100) {
        x = (px >> 8) - (gBtlWork->unk_000 >> 8);
        y = ((py >> 8) + (pz >> 8)) - (gBtlWork->unk_004 >> 8);
    } else {
        x = (((px >> 8) - (gBtlWork->unk_000 >> 8)) * gBtlWork->unk_024) >> 8;
        y = ((((py >> 8) + (pz >> 8)) - (gBtlWork->unk_004 >> 8)) * gBtlWork->unk_024) >> 8;
    }

    if (gBtlWork->unk_018 == 0) {
        *a = x + 120;
        *b = y + 80;
    } else {
        ang = -gBtlWork->unk_018;
        c = (ang + 64) & 0xFF;
        u = gSineTable[c] * x + gSineTable[ang] * y;
        v = gSineTable[c + 64] * x + gSineTable[ang + 64] * y;
        *a = (u >> 8) + 120;
        *b = (v >> 8) + 80;
    }
}
#else
INCLUDE_ASM("unk_0800eebc/WorldToScreen.s");
#endif
void func_08019190(BtlObj* p, s16 b) {
    UnkStruct_0801B8A8 a;
    s16* t;

    if (b != 9) {
        if (p->unk_0D8 != 0) {
            t = &((BtlObj*)p->unk_0D8)->unk_104;
        } else {
            t = &p->unk_104;
        }

        if (*t > 0) {
            return;
        }
        *t = 50;
    }
    a.x = p->unk_004;
    a.y = p->unk_008;
    a.z = p->unk_00C - ((p->unk_09C / 2) << 8);
    if (gGameState.flags & 8) {
        if (b == 9) {
            a.unk_12 = abs(gBtlWork->unk_1CA);
            TaskCreate(&gBtlWork->unk_02C, gTaskDescBtlPopCb, &a);
            return;
        }
        a.unk_12 = b;
        TaskCreate(&gBtlWork->unk_02C, gTaskDescBtlPop, &a);
        return;
    }
    a.unk_12 = b;

    if (b == 9) {
        if (p->unk_034 & 0x200000000000) {
            return;
        }
        TaskCreate(&gBtlWork->unk_02C, gTaskDescBtlPop, &a);
        return;
    }
    TaskCreate(&gBtlWork->unk_02C, gTaskDescBtlPop, &a);
}

void BtlWorkInit(void) {
    s32 zero = 0;
    u8* d;
    u8* p;
    CpuSet(&zero, gBtlWork, 0x05000074);
    gBtlWork->unk_0A0 = 0;
    gBtlWork->unk_0FC = 0xFFFF0000;
    gBtlWork->unk_12C = 0x42;
    gBtlWork->unk_0B3 = 10;
    d = gBtlWork->unk_13C;
    p = (u8*)&gGameState;
    p += 0xF8;
    memcpy(d, p, 0x88);
    ListPoolInit(&gBtlWork->unk_080);
    ListPoolInit(&gBtlWork->unk_090);
}

void func_080192E0(void) {
    BtlObj* p;

    if (gBtlWork->unk_068 & 0x40) {
        return;
    }
    if (gBtlWork->unk_068 & 0x10000000) {
        return;
    }
    if (gBtlWork->unk_068 & 0x800000) {
        return;
    }
    p = gBtlWork->unk_0AC;
    if (p == 0) {
        return;
    }
    if (p->unk_034 & 0x7202) {
        return;
    }
    gBtlWork->unk_0A8 = p;
    func_08091234(p->unk_000);
}

INCLUDE_ASM("unk_0800eebc/func_08019350.s");
INCLUDE_ASM("unk_0800eebc/func_080197AC.s");
void func_08019A30(void) {
    BtlWork* w = gBtlWork;
    BtlObj* p;

    if (w->unk_068 & 0x4000) {
        if (w->unk_068 & 0x20000000) {
            p = (BtlObj*)gUnk_02039B9C->unk_07C;
            p->unk_034 &= ~0x80;
            return;
        }
    } else if (w->unk_068 & 0x20000000) {
        p = ListPoolFirst(&w->unk_080);

        while (p != 0) {
            p->unk_034 &= ~0x80;
            *(u16*)((u8*)p + 0xE2) = 0;
            p = ListPoolNext(&p->unk_0B8);
        }
        return;
    }
    p = (BtlObj*)w->unk_07C;
    p->unk_034 &= ~0x80;
}

INCLUDE_ASM("unk_0800eebc/func_08019ACC.s");

void func_08019C5C(void) {
    gBtlWork->unk_0A0 = 1;

    if (!(gBtlWork->unk_068 & 0x800000)) {
        gBtlWork->unk_068 |= 0x20;
    }
    gBtlWork->unk_068 &= ~0x40;
    gBtlWork->unk_068 &= ~0x20000000;
}

INCLUDE_ASM("unk_0800eebc/_08019CB4.s");

u8 func_0801A8A4(s32* px, s32* py, u16 rx, u16 ry) {
    u8 r = 0;

    if (*py < (gBtlWork->unk_0DE - (s16)ry) << 8) {
        *py = (gBtlWork->unk_0DE - (s16)ry) << 8;
        r = 3;
    }

    if (*py > (gBtlWork->unk_0E0 + (s16)ry) << 8) {
        *py = (gBtlWork->unk_0E0 + (s16)ry) << 8;
        r = 4;
    }

    if (*px < (gBtlWork->unk_0DA - (s16)rx) << 8) {
        *px = (gBtlWork->unk_0DA - (s16)rx) << 8;
        r = 1;
    }

    if (*px > (gBtlWork->unk_0DC + (s16)rx) << 8) {
        *px = (gBtlWork->unk_0DC + (s16)rx) << 8;
        r = 2;
    }
    return r;
}

void func_0801A920(u16 a, u16 b, u16 c, u16 d) {
    gBtlWork->unk_0DA = a;
    gBtlWork->unk_0DC = b;
    gBtlWork->unk_0DE = c;
    gBtlWork->unk_0E0 = d;
    func_0801C274(((s16)a + (s16)b) << 7, ((s16)c + (s16)d) << 7, -0x2000);
}

INCLUDE_ASM("unk_0800eebc/func_0801A978.s");

#ifdef NON_MATCHING
u8 func_0801AD68(BtlObj* p) {
    u64 f = p->unk_034;
    if (!((u32)f & 1)) {
        return 0;
    }
    f &= ~0x46023;
    f |= 0x90;
    p->unk_034 = f;
    p->unk_014 = p->unk_004;
    p->unk_018 = p->unk_008;
    p->unk_01C = p->unk_00C;
    return 1;
}
#else
INCLUDE_ASM("unk_0800eebc/func_0801AD68.s");
#endif

s32 func_0801ADAC(BtlObj* p) {
    u16 t;
    u16 u;
    u16 v;

    if (p->unk_0E8 == 2) {
        if (p->unk_034 & 2) {
            p->unk_034 &= ~0x40002;
            p->unk_034 &= ~0x52000004800;
            gBtlWork->unk_072 = gBtlWork->unk_076;
            p->unk_0E2 = 30;
            p->unk_0E0 += p->unk_020;
        }
    } else {
        t = p->unk_0E0;

        if ((s16)p->unk_0E0 > 0) {
            p->unk_020 = t;
            p->unk_0E0 = 0;
            gBtlWork->unk_076 = 0;
            p->unk_034 &= ~0x52000004800;
            p->unk_034 |= 2;
            p->unk_024 = 0;
            p->unk_0A8 = 0;
            p->unk_0AC = 0;
        }
    }
    u = p->unk_0E2;

    if (p->unk_0E2 > 0) {
        p->unk_0E2 = u - 1;
    }
    v = p->unk_104;

    if (p->unk_104 > 0) {
        p->unk_104 = v - 1;
    }

    if (p->unk_034 & 0x10000) {
        p->unk_034 &= ~0x10003;
        func_0801AF08(p);
        p->unk_034 |= 0x200;
        func_08019190(p, 9);
        gBtlWork->unk_072 = 12;
        return 4;
    }
    if (func_0801AD68(p)) {
        return 5;
    }
    return func_0801A978(p);
}

void func_0801AF08(BtlObj* p) {
    p->unk_034 &= ~0x2290;
}

u16 func_0801AF1C(s32 a) {
    if (a < gBtlWork->unk_0D0 + (gBtlWork->unk_0D8 << 8)) {
        return 0x800;
    }
    return 0x400;
}

#ifdef NON_MATCHING
void func_0801AF4C(void) {
    BtlObj* p;

    gBtlWork->unk_068 |= 0x80000;
    gBtlWork->unk_068 |= 0x40000000;
    gBtlWork->unk_068 |= 0x200000000;
    func_0801C830();
    m4aMPlayFadeOut(gMPlayTable[gSongTable[3].ms].info, 12);
    func_08006120(2, 20);
    func_080063A8();
    p = ListPoolFirst(&gBtlWork->unk_080);

    while (p != 0) {
        p->unk_0B8.flags |= 2;
        p = ListPoolNext(&p->unk_0B8);
    }
    gBtlWork->unk_0EE = 0;
}
#else
INCLUDE_ASM("unk_0800eebc/func_0801AF4C.s");
#endif

void func_0801B008(void) {
    gBtlWork->unk_068 &= ~0x80000;
}

INCLUDE_ASM("unk_0800eebc/func_0801B024.s");
INCLUDE_ASM("unk_0800eebc/func_0801B37C.s");

void func_0801B7D8(BtlObj* obj) {
    BtlObj* p = obj->unk_0DC;
    if (p == obj) {
        func_08000D90(&p->unk_0B8, &gBtlWork->unk_080);

        if (!(p->unk_03C & 1)) {
            func_08012304(&p->unk_040);
        }
        gBtlWork->unk_0EE--;
    }
}

u8 func_0801B818(UnkStruct_0801B8A8* p, u16 b, s16 c, s16* n, s16* cnt) {
    s16 i;
    s16 lim;

    lim = *n / c;
    p->unk_12 = b;

    for (i = 0; i < lim; i++) {
        TaskCreate(&gBtlWork->unk_02C, gTaskDescBtlPrize, p);

        if (++(*cnt) > 2) {
            return 1;
        }
    }
    *n = *n % c;
    return 0;
}

void func_0801B8A8(UnkStruct_0801B8A8* p, u16 b, s16 c, s16* n) {
    s16 i;
    s16 lim;
    lim = *n / c;
    p->unk_12 = b;

    for (i = 0; i < lim; i++) {
        TaskCreate(&gBtlWork->unk_02C, gTaskDescBtlPrize, p);
    }
    *n = *n % c;
}
void func_0801B918(BtlObj* p) {
    UnkStruct_0801B8A8 a;
    s16 n;
    a.x = p->unk_004;
    a.y = p->unk_008;
    a.z = p->unk_00C;
    a.unk_14 = 1;
    n = p->unk_0B4;
    func_0801B8A8(&a, 0, 0x578, &n);
    func_0801B8A8(&a, 8, 199, &n);
    func_0801B8A8(&a, 5, 60, &n);
    func_0801B8A8(&a, 7, 30, &n);
    func_0801B8A8(&a, 4, 10, &n);
    func_0801B8A8(&a, 6, 5, &n);
    func_0801B8A8(&a, 3, 1, &n);
}
INCLUDE_ASM("unk_0800eebc/func_0801B994.s");
void func_0801BBF0(BtlObj* p) {
    UnkStruct_0801B8A8 a;

    if (gGameState.flags & 8) {
        return;
    }
    if (func_08085BAC()) {
        return;
    }
    if (gBtlWork->unk_068 & 0x400000000) {
        return;
    }
    if (gBtlWork->unk_068 & 0x100000000) {
        return;
    }
    if (!func_080856DC()) {
        return;
    }
    if (func_08085B38(GetActiveDeckIndex()) <= 9) {
        return;
    }
    gBtlWork->unk_068 |= 0x100000000;
    a.x = p->unk_004;
    a.y = p->unk_008;
    a.z = p->unk_00C;
    a.unk_14 = 0;
    TaskCreate(&gBtlWork->unk_02C, gTaskDescBtlPremire, &a);
}

u8 func_0801BCA8(s32 a) {
    if (a == gBtlWork->unk_0F0) {
        return 1;
    } else {
        return 0;
    }
}

void func_0801BCC0(s32 a, s32 b, s32 c) {
    gBtlWork->unk_07C->unk_04 = a;
    gBtlWork->unk_07C->unk_08 = b;
    gBtlWork->unk_07C->unk_0C = c;
}

void func_0801BCD4(BtlObj* p) {
    if (!(p->unk_034 & 0x7202)) {
        gBtlWork->unk_0AC = p;
    }
}

#ifdef NON_MATCHING
void func_0801BCF8(BtlObj* p) {
    s32 x;
    s32 y;
    s32 cx;
    s32 x0;
    s32 x1;
    s32 y0;
    s32 y1;

    if (p->unk_034 & 0x7202) {
        return;
    }
    if (GetRandom() % (p->unk_0B2 * gBtlWork->unk_0EE) != 0) {
        return;
    }
    func_0801C700(p, &x, &y, 0);

    if (p->unk_0D0 == 0) {
        gBtlWork->unk_0AC = p;
        return;
    }

    if (p->unk_034 & 4) {
        cx = p->unk_004 - (p->unk_0CE << 8);
    } else {
        cx = p->unk_004 + (p->unk_0CE << 8);
    }
    x0 = p->unk_0D0;
    x0 = cx - ((x0 - 4) << 8);
    y0 = p->unk_008 - (p->unk_0D2 << 8);
    x1 = x0 + ((p->unk_0D0 + 4) << 9);
    y1 = y0 + ((p->unk_0D2 + 4) << 9);

    if (x0 > x) {
        return;
    }
    if (x1 < x) {
        return;
    }
    if (y0 > y) {
        return;
    }
    if (y1 < y) {
        return;
    }
    gBtlWork->unk_0AC = p;
}
#else
INCLUDE_ASM("unk_0800eebc/func_0801BCF8.s");
#endif

void func_0801BDD4(BtlObj* p, s32 v) {
    p->unk_0D8 = v;
}

INCLUDE_ASM("unk_0800eebc/func_0801BDDC.s");
void func_0801C068(void) {
    if (gGameState.flags & 8) {
        gBtlWork->unk_110 = AllocObjTiles(0x840, 0);
    } else {
        gBtlWork->unk_110 = AllocObjTiles(0xC80, 0);
        gBtlWork->unk_114 = AllocObjTiles(0xA00, 0);

        if (gBtlWork->unk_068 & 0x4000) {
            gUnk_02039B9C->unk_110 = AllocObjTiles(0xC80, 0);
        }
    }
    gBtlWork->unk_068 |= 0x1000000000000;
}

void func_0801C104(void) {
    if (gBtlWork->unk_068 & 0x1000000000000) {
        if (gGameState.flags & 8) {
            ReleaseObjTiles(gBtlWork->unk_110);
        } else {
            ReleaseObjTiles(gBtlWork->unk_110);
            ReleaseObjTiles(gBtlWork->unk_114);

            if (gBtlWork->unk_068 & 0x4000) {
                ReleaseObjTiles(gUnk_02039B9C->unk_110);
            }
        }
        gBtlWork->unk_068 &= ~0x1000000000000;
    }
}

void func_0801C1A0(u8 a) {
    if (a <= 4) {
        gBtlWork->unk_0FB |= 1 << a;
    }
}

u8 func_0801C1C0(u8 a) {
    u8 m;

    if (a > 4) {
        return 0;
    }
    m = 1 << a;
    if (gBtlWork->unk_0FB & m) {
        gBtlWork->unk_0FB &= ~m;
        return 1;
    }
    return 0;
}

ALIGN_ZERO(2);

void _0801C1F8(u8 a, s32 x, s32 y, s32 z) {
    u16 id;

    switch (a) {
    case 0:
        id = 0x28F;
        break;
    case 1:
        id = 0x290;
        break;
    case 2:
        id = 0x291;
        break;
    case 3:
        id = 0x292;
        break;
    case 4:
        id = 0x293;
        break;
    default:
        return;
    }
    func_0809B710(&gBtlWork->unk_02C, x >> 8, y >> 8, z >> 8, id);
}

void func_0801C274(s32 a, s32 b, s32 c) {
    gBtlWork->unk_100 = a;
    gBtlWork->unk_104 = b;
    gBtlWork->unk_108 = c;
}

void func_0801C298(u8 a, u8 b) {
    if (a <= 0x1F) {
        if (b != 0) {
            gBtlWork->unk_0FC |= 1 << a;
        } else {
            gBtlWork->unk_0FC &= ~(1 << a);
        }
    }
}

void func_0801C2DC(BtlObj* p, u8 f) {
    if (f) {
        p->unk_034 |= 0x1000000;
    } else {
        p->unk_034 &= ~0x1000000;
    }
}

INCLUDE_ASM("unk_0800eebc/func_0801C314.s");

#ifdef NON_MATCHING
u8 func_0801C6D4(s32 a) {
    if (gBtlWork->unk_128 != 0) {
        return gBtlWork->unk_128(a);
    }
    return 0;
}
#else
INCLUDE_ASM("unk_0800eebc/func_0801C6D4.s");
#endif

void func_0801C700(void* a, s32* b, s32* c, s32* d) {
    u16 n;

    if (*(s32*)((u8*)a + 0xE8) == 3) {
        if (b != 0) {
            *b = *(s32*)((u8*)a + 0xF0);
        }
        if (c != 0) {
            *c = *(s32*)((u8*)a + 0xF4);
        }
        if (d != 0) {
            *d = *(s32*)((u8*)a + 0xF8);
        }
        n = GetRandom() % 6;

        if (n == 0) {
            if (b != 0) {
                *b = (gBtlWork->unk_0DA + GetRandom() % (gBtlWork->unk_0DC - gBtlWork->unk_0DA + 1)) << 8;
            }
            if (c != 0) {
                *c = (gBtlWork->unk_0DE + GetRandom() % (gBtlWork->unk_0E0 - gBtlWork->unk_0DE + 1)) << 8;
            }
            if (d != 0) {
                *d = n;
            }
        }
    } else {
        if (b != 0) {
            *b = gBtlWork->unk_130;
        }
        if (c != 0) {
            *c = gBtlWork->unk_134;
        }
        if (d != 0) {
            *d = gBtlWork->unk_138;
        }
    }
}

void func_0801C7FC(HitData* a, u16 b, s32 c) {
    const UnkStruct_08133E5C* e = func_0800FB14(b);
    if (e != 0) {
        a->unk_2E = (e->unk_00 * c) >> 8;
        if (a->unk_2E <= 0) {
            a->unk_2E = 1;
        }
        a->unk_2C = a->unk_2E;
    }
}

INCLUDE_ASM("unk_0800eebc/func_0801C830.s");

u8 func_0801CA00(BtlObj* p) {
    if (gBtlWork->unk_070 == 1) {
        return 0;
    }

    if (!(p->unk_034 & 0x2000)) {
        return 0;
    }

    if (p->unk_106 > 0x17) {
        return 0;
    }
    p->unk_106++;
    if (p->unk_106 & 1) {
        return 1;
    }
    return 0;
}

u8 func_0801CA48(BtlObj* p) {
    if (gBtlWork->unk_070 == 1) {
        return 0;
    }

    if (!(p->unk_034 & 0x2000)) {
        return 0;
    }

    if (p->unk_106 > 0x17) {
        return 0;
    }
    p->unk_106++;
    return 1;
}

void func_0801CA88(void) {
    s32 zero = 0;
    CpuSet(&zero, &gGameState, 0x05000084);

    if (gUnk_03006C10 & 0x800) {
        gGameState.flags |= 8;
        gGameState.flags |= 0x20;
    }
    gGameState.world = 4;
    gGameState.unk_00D = 1;
    func_0800F9A0();
    gGameState.unk_180 = 0xFFFF;
    func_080DFB2C();
    gGameState.hp = gGameState.maxHp;
    gGameState.unk_024 = 0x2D;
    gGameState.unk_1B8 = 0;
}

void func_0801CB00(void) {
    gGameState.unk_000 = 0;
}

void func_0801CB0C(void) {
    gGameState.unk_000 = 1;
}

void func_0801CB18(void) {
    if (gGameState.unk_000 != 0) {
        SeedRandom(gGameState.randomSeed);
    } else {
        gGameState.randomSeed = GetRandom();
        SeedRandom(gGameState.randomSeed);
    }
}

#ifndef VERSION_EU
void func_0801CB44(void) {
    SeedRandom(gFrameCounter);
    func_0801CA88();
    func_0801CB00();
    func_0800ABD8();
    gUnk_02039DC0 = 0;
}
#else
INCLUDE_ASM("unk_08019050/func_0801CB44.s");
#endif
