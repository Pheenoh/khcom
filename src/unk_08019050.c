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
INCLUDE_ASM("unk_08019050/WorldToScreen.s");
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

void func_08019350(void) {
    BtlObj* p;
    u16 t;
    u16 a;

    if (gBtlWork->unk_068 & 0x20000000000000) {
        return;
    }
    t = gBtlWork->unk_1CC;

    if ((s16)t > 0) {
        gBtlWork->unk_1CC = t - 1;

        if (gBtlWork->unk_1CC == 0) {
            func_08076394();
        }
        return;
    }

    if (gBtlWork->unk_068 & 0x10000000000000) {
        if (!(gGameState.flags & 8)) {
            if (GetKeysHeld() & 1) {
                if (!(GetKeysHeld() & 0x300)) {
                    func_080763F0();
                }
            }
        }
    }

    if (gBtlWork->unk_068 & 0x1000000) {
        return;
    }
    a = func_080015F8(0x200, 0x100);

    switch (a) {
    case 0x200:
        func_08076318();
        break;
    case 0x100:
        func_08076324();
        break;
    }

    if (GetKeysPressed() & 4) {
        func_08076394();
    }

    if (func_080763D0() != 0) {
        gBtlWork->unk_0E2 = 0;
        gBtlWork->unk_0E3 = 0;
    } else {
        if ((GetKeysHeld() & 0x200) && !(GetKeysHeld() & 0x100)) {
            if (gBtlWork->unk_0E2 < 255) {
                gBtlWork->unk_0E2++;
            }
        } else {
            gBtlWork->unk_0E2 = 0;
        }

        if ((GetKeysHeld() & 0x100) && !(GetKeysHeld() & 0x200)) {
            if (gBtlWork->unk_0E3 < 255) {
                gBtlWork->unk_0E3++;
            }
        } else {
            gBtlWork->unk_0E3 = 0;
        }
    }

    if (gBtlWork->unk_0E2 > 32) {
        func_08076318();
    }

    if (gBtlWork->unk_0E3 > 32) {
        func_08076324();
    }
    p = (BtlObj*)gBtlWork->unk_07C;

    if (p->unk_034 & 0x200) {
        return;
    }
    if (gBtlWork->unk_068 & 0x20000000) {
        return;
    }
    if (gBtlWork->unk_068 & 0x8000000) {
        return;
    }
    if (gBtlWork->unk_068 & 0x800000) {
        return;
    }
    if (p->unk_034 & 2) {
        return;
    }

    if (a == 0x300) {
        if (func_0807B3E0() > 2) {
            func_08076348();
        } else {
            func_0807633C();
        }
    }

    if (GetKeysPressed() & 1) {
        func_08076330();

        if (func_0807B3C8() == 3) {
            if (func_0807643C() == 0) {
                gBtlWork->unk_1CC = 15;
            }
        }
    }
}

INCLUDE_ASM("unk_08019050/func_080195A8.s");
void func_080197AC(void) {
    BtlObj* p;
    u16 a;
    u16 pressed;
    u16 held;

    if (!(gBtlWork->unk_068 & 0x2000000000)) {
        if (gBtlWork->unk_068 & 0x10000000000000) {
            if (!(gGameState.flags & 8)) {
                if (GetKeysHeld() & 1) {
                    if (!(GetKeysHeld() & 0x300)) {
                        func_080763F0();
                    }
                }
            }
        }
    }

    if (gBtlWork->unk_068 & 0x1000000) {
        return;
    }
    a = func_080015F8(0x200, 0x100);
    pressed = GetKeysPressed();
    held = GetKeysHeld();

    if (!(gBtlWork->unk_068 & 0x4000000000)) {
        switch (a) {
        case 0x200:
            func_08076318();
            break;
        case 0x100:
            func_08076324();
            break;
        }
    }

    if (!(gBtlWork->unk_068 & 0x10000000000)) {
        if (pressed & 4) {
            func_08076394();
        }
    }

    if (!(gBtlWork->unk_068 & 0x4000000000)) {
        if (func_080763D0() != 0) {
            gBtlWork->unk_0E2 = 0;
            gBtlWork->unk_0E3 = 0;
        } else {
            if ((held & 0x200) && !(held & 0x100)) {
                if (gBtlWork->unk_0E2 < 255) {
                    gBtlWork->unk_0E2++;
                }
            } else {
                gBtlWork->unk_0E2 = 0;
            }

            if ((held & 0x100) && !(held & 0x200)) {
                if (gBtlWork->unk_0E3 < 255) {
                    gBtlWork->unk_0E3++;
                }
            } else {
                gBtlWork->unk_0E3 = 0;
            }
        }
    }

    if (gBtlWork->unk_0E2 > 32) {
        func_08076318();
    }

    if (gBtlWork->unk_0E3 > 32) {
        func_08076324();
    }
    p = (BtlObj*)gBtlWork->unk_07C;

    if (p->unk_034 & 0x200) {
        return;
    }
    if (gBtlWork->unk_068 & 0x20000000) {
        return;
    }
    if (gBtlWork->unk_068 & 0x8000000) {
        return;
    }
    if (gBtlWork->unk_068 & 0x800000) {
        return;
    }
    if (p->unk_034 & 2) {
        return;
    }

    if (a == 0x300) {
        if (func_0807B3E0() > 2) {
            if (!(gBtlWork->unk_068 & 0x4000000000000)) {
                func_08076348();
            }
        } else {
            if (!(gBtlWork->unk_068 & 0x8000000000)) {
                func_0807633C();
            }
        }
    }

    if (!(gBtlWork->unk_068 & 0x2000000000)) {
        if (pressed & 1) {
            func_08076330();
        }
    }
}
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

void func_08019ACC(s32 a, s32 b, s32 c) {
    u16 flags;
    s16 v;

    flags = gGameState.unk_17C;

    if (gBtlWork->unk_068 & 0x800000000LL) {
        return;
    }

    if (gGameState.flags & 8) {
        if (flags & 0x80) {
            func_0800FDD0(244);
            func_0809B644(gBtlWork->unk_02C, a >> 8, b >> 8, c >> 8, 7);
        }
        return;
    }

    v = -1;

    if (GetRandom() % 4 != 0) {
        switch (gGameState.world) {
        case 1:
            if (flags & 4) {
                v = 2;
                func_0800FDD0(159);
            }
            break;
        case 2:
            if (flags & 8) {
                v = 3;
                func_0800FDD0(160);
            }
            break;
        case 6:
            if (flags & 0x10) {
                v = 4;
                func_0800FDD0(161);
            }
            break;
        case 7:
            if (flags & 0x20) {
                v = 5;
                func_0800FDD0(162);
            }
            break;
        case 8:
            if (flags & 0x40) {
                v = 6;
                func_0800FDD0(163);
            }
            break;
        }
    }

    if (v == -1) {
        if (GetRandom() % 2 != 0) {
            if (flags & 1) {
                v = 0;
                func_0800FDD0(158);
            }
        } else {
            if (flags & 2) {
                v = 1;
                func_0800FDD0(157);
            }
        }
    }

    if (v != -1) {
        func_0809B644(gBtlWork->unk_02C, a >> 8, b >> 8, c >> 8, v);
    }
}

void func_08019C5C(void) {
    gBtlWork->unk_0A0 = 1;

    if (!(gBtlWork->unk_068 & 0x800000)) {
        gBtlWork->unk_068 |= 0x20;
    }
    gBtlWork->unk_068 &= ~0x40;
    gBtlWork->unk_068 &= ~0x20000000;
}

INCLUDE_ASM("unk_08019050/_08019CB4.s");

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

s32 func_0801A978(BtlObj* p) {
    if (p->unk_034 & 0x40) {
        p->unk_034 &= ~0x40;

        if (p->unk_024 & 0x20000) {
            p->unk_034 |= 0x800000000;
        }
        return 11;
    }

    if (p->unk_034 & 2) {
        p->unk_034 &= ~3;
        p->unk_02C -= p->unk_020;

        if (p->unk_02C < 0) {
            p->unk_02C = 0;
        }
        p->unk_034 &= ~1;
        gBtlWork->unk_072 = gBtlWork->unk_076;
        p->unk_034 |= 0x2280;
        p->unk_106 = 0;

        if (p->unk_02C <= 0) {
            p->unk_034 |= 0x100;
            p->unk_034 &= ~0x4020;
            p->unk_034 |= 0x1000000000;
            p->unk_0E8 = 0;
            p->unk_0EC = 0;

            if (p->unk_024 & 0x20000) {
                p->unk_034 |= 0x800000000;
            }

            if (p->unk_034 & 0x40000) {
                p->unk_034 &= ~0x40000;
                return 8;
            }
            return 3;
        }

        if (p->unk_000 != 55 && GetRandom() % 8 == 0) {
            func_08019ACC(p->unk_004, p->unk_008, p->unk_00C - 0x7800);
        }

        if (p->unk_034 & 0x40000) {
            p->unk_034 &= ~0x40000;
            p->unk_034 &= ~0x52000004800;
            p->unk_0E8 = 0;
            p->unk_0EC = 0;
            return 7;
        }

        if (p->unk_034 & 0x4000) {
            p->unk_034 &= ~0x52000004800;

            if (p->unk_0E8 != 1) {
                p->unk_0E8 = 1;
                p->unk_0EC = 240;
            }
            return 6;
        }

        if (p->unk_034 & 0x2000000000) {
            p->unk_034 &= ~0x52000004800;
            p->unk_0E8 = 4;
            p->unk_0EC = 300;
            return 12;
        }

        if (p->unk_034 & 0x10000000000) {
            p->unk_034 &= ~0x52000004800;
            p->unk_0E8 = 3;
            p->unk_0EC = 300;
            return 1;
        }

        if (p->unk_034 & 0x40000000000) {
            p->unk_034 &= ~0x52000004800;

            if (p->unk_0E8 != 5) {
                p->unk_0E8 = 5;
                p->unk_0EC = 600;
            }
            return 1;
        }
        p->unk_0E8 = 0;
        p->unk_0EC = 0;
        return 1;
    }

    if (p->unk_034 & 0x20) {
        p->unk_034 &= ~0x21;
        p->unk_034 |= 0x280;
        return 2;
    }

    if (p->unk_034 & 0x20000000) {
        p->unk_034 &= ~0x20000000;

        if (p->unk_02C > 0) {
            func_0801AF08(p);
            return 9;
        }
        return 0;
    }

    if (p->unk_034 & 0x800) {
        p->unk_034 &= ~0x52000004800;
        gBtlWork->unk_072 = gBtlWork->unk_076;
        func_0801AF08(p);
        p->unk_034 |= 0x200;

        if (p->unk_0E8 != 2) {
            p->unk_0E8 = 2;
            p->unk_0EC = p->unk_020;
        }
        return 10;
    }
    return 0;
}

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
INCLUDE_ASM("unk_08019050/func_0801AD68.s");
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
INCLUDE_ASM("unk_08019050/func_0801AF4C.s");
#endif

void func_0801B008(void) {
    gBtlWork->unk_068 &= ~0x80000;
}

void func_0801B024(BtlObj* p) {
    switch (p->unk_000) {
    case 1:
        p->unk_034 |= 0x10800000100000;
        break;
    case 2:
        p->unk_034 |= 0x10400000200000;
        break;
    case 3:
        p->unk_034 |= 0x400000;
        break;
    case 4:
        p->unk_034 |= 0x700000;
        break;
    case 5:
        p->unk_034 |= 0x1000000000000;
        break;
    case 7:
        p->unk_034 |= 0x3C02C000000000;
        break;
    case 16:
        p->unk_034 |= 0x400000;
        break;
    case 23:
        p->unk_034 |= 0x280700000;
        break;
    case 27:
        p->unk_034 |= 0x400000;
        break;
    case 32:
        p->unk_034 |= 0x11C000000000000;
        break;
    case 33:
        p->unk_034 |= 0x11C000000000000;
        break;
    case 34:
        p->unk_034 |= 0x11C000000000000;
        break;
    case 35:
        p->unk_034 |= 0x11C000000000000;
        break;
    case 36:
        p->unk_034 |= 0x11C000000000000;
        break;
    case 37:
        p->unk_034 |= 0x11C000000000000;
        break;
    case 38:
        p->unk_034 |= 0x11C000000000000;
        break;
    case 39:
        p->unk_034 |= 0x11E000000000000;
        break;
    case 40:
        p->unk_034 |= 0x11E000000000000;
        break;
    case 42:
        p->unk_034 |= 0x108000290000000;
        break;
    case 43:
        p->unk_034 |= 0x11C000280000000;
        break;
    case 44:
        p->unk_034 |= 0x100000290100000;
        break;
    case 45:
        p->unk_034 |= 0x1C000280000000;
        break;
    case 46:
        p->unk_034 |= 0x400000000000;
        break;
    case 47:
        p->unk_034 |= 0x400000000000;
        break;
    case 48:
        p->unk_034 |= 0x110000280100000;
        break;
    case 49:
        p->unk_034 |= 0xC000280400000;
        break;
    case 50:
        p->unk_034 |= 0x110000280200000;
        break;
    case 51:
        p->unk_034 |= 0x11E000280000000;
        break;
    case 52:
        p->unk_034 |= 0x11C000280000000;
        break;
    case 53:
        p->unk_034 |= 0x34000288000000;
        break;
    case 0:
    default:
        break;
    }
}

#ifdef NON_MATCHING
void func_0801B37C(BtlObj* p, EmyKind* d, s32 x, s32 y, s32 z) {
    const UnkStruct_08133E5C* e;
    u32 v;
    s32 a;
    s32 b;
    s32 c;

    e = func_0800FB14(d->unk_00);

    if (e != 0) {
        v = *(s32*)d;

        switch (v) {
        case 45:
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
            switch (gBtlWork->unk_10C) {
        case 161:
            p->unk_02E = 1120;
            p->unk_030 = 5;
            p->unk_0B4 = 2775;
            break;
        case 168:
            p->unk_02E = 1120;
            p->unk_030 = 5;
            p->unk_0B4 = 3225;
            break;
        case 169:
            p->unk_02E = 1120;
            p->unk_030 = 8;
            p->unk_0B4 = 5700;
            break;
        case 170:
            p->unk_02E = 1680;
            p->unk_030 = 10;
            p->unk_0B4 = 6825;
            break;
        case 171:
            p->unk_02E = 1120;
            p->unk_030 = 5;
            p->unk_0B4 = 1875;
            break;
        case 172:
            p->unk_02E = 1680;
            p->unk_030 = 10;
            p->unk_0B4 = 5700;
            break;
        case 162:
            p->unk_02E = 320;
            p->unk_030 = 2;
            p->unk_0B4 = 75;
            break;
        case 173:
            p->unk_02E = 1680;
            p->unk_030 = 15;
            p->unk_0B4 = 6825;
            break;
        case 163:
            p->unk_02E = 1120;
            p->unk_030 = 5;
            p->unk_0B4 = 2325;
            break;
        case 174:
            p->unk_02E = 1680;
            p->unk_030 = 15;
            p->unk_0B4 = 6263;
            break;
        case 164:
            p->unk_02E = 1120;
            p->unk_030 = 15;
            p->unk_0B4 = 4125;
            break;
        case 175:
            p->unk_02E = 1120;
            p->unk_030 = 20;
            p->unk_0B4 = 5700;
            break;
        case 176:
            p->unk_02E = 1120;
            p->unk_030 = 3;
            p->unk_0B4 = 975;
            break;
        case 166:
            p->unk_02E = 400;
            p->unk_030 = 3;
            p->unk_0B4 = 133;
            break;
        case 177:
            p->unk_02E = 2240;
            p->unk_030 = 25;
            p->unk_0B4 = 0;
            break;
        case 167:
            p->unk_02E = 1680;
            p->unk_030 = 15;
            p->unk_0B4 = 6517;
            break;
        default:
            p->unk_02E = 2240;
            p->unk_030 = 27;
            p->unk_0B4 = 13131;
            break;
            }
            break;
        case 37:
            if (gGameState.flags & 8) {
                p->unk_02E = 300;
                p->unk_030 = 4;
                p->unk_0B4 = 150;
                break;
            }
        default:
            if (gGameState.unk_00E <= 9) {
                a = 25;
                b = 102;
                c = 384;
            } else {
                a = 51;
                b = 76;
                c = 640;
            }
            p->unk_02E = ((gGameState.unk_00E * a + 256) * e->unk_00) >> 8;
            p->unk_030 = ((gGameState.unk_00E * b + 256) * e->unk_02) >> 8;
            p->unk_0B4 = ((c * gGameState.unk_00E + 256) * (u16)e->unk_04) >> 8;
            break;
        }
    } else {
        p->unk_02E = d->unk_04;
        p->unk_030 = 0;
        p->unk_0B4 = 1;
        v = *(s32*)d;
    }
    p->unk_0CE = 80;
    p->unk_0D0 = 32;
    p->unk_0D2 = 32;
    p->unk_0B2 = 100;
    p->unk_02C = p->unk_02E;
    p->unk_0DC = p;
    p->unk_004 = x;
    p->unk_008 = y;
    p->unk_00C = z;
    p->unk_010 = 0;
    p->unk_034 = 0;
    p->unk_03C = d->unk_0E;
    p->unk_09C = d->unk_06;
    p->unk_0A2 = d->unk_0A;
    p->unk_0A4 = 0;
    p->unk_09E = d->unk_08;
    p->unk_0A0 = d->unk_08 >> 1;
    p->unk_000 = v;
    p->unk_020 = 0;
    p->unk_0D4 = 0;
    p->unk_0D8 = 0;
    p->unk_0E2 = 0;
    p->unk_0E0 = 0;
    p->unk_0CC = 0xFFF1;
    p->unk_0E4 = 0;
    p->unk_0E8 = 0;
    p->unk_0EC = 0;
    p->unk_0F0 = gBtlWork->unk_07C->unk_04;
    p->unk_0F4 = gBtlWork->unk_07C->unk_08;
    p->unk_0F8 = gBtlWork->unk_07C->unk_0C;
    p->unk_108 = 0;
    p->unk_10C = 0;
    p->unk_104 = 0;

    if (v <= 40 && v >= 32) {
        if (!(d->unk_0E & 1)) {
            func_080122AC(&p->unk_040, 8, d->unk_08, d->unk_06);
        }
        p->unk_034 |= 0xAC280000000;
        p->unk_034 |= 0x40000000;
    } else if (!(d->unk_0E & 1)) {
        if (d->unk_0E & 8) {
            func_080122AC(&p->unk_040, 11, d->unk_08, d->unk_06);
        } else {
            func_080122AC(&p->unk_040, 3, d->unk_08, d->unk_06);
        }
    }
    func_0801B024(p);

    if (d->unk_0E & 4) {
        p->unk_034 |= 0x20000;
    }
    func_08000D20(&p->unk_0B8, &gBtlWork->unk_080, p);
    func_08000D28(&p->unk_0B8, &gBtlWork->unk_080);
    gBtlWork->unk_0EE++;
}
#else
INCLUDE_ASM("unk_08019050/func_0801B37C.s");
#endif

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

void func_0801B994(BtlObj* p) {
    UnkStruct_0801B8A8 a;
    UnkStruct_0801B8A8 b;
    s16 n;
    s16 cnt;
    s32 flag;
    s32 hit;
    s32 v;
    s32 r;

    if (gBtlWork->unk_068 & 0x400000000) {
        return;
    }
    a.x = p->unk_004;
    a.y = p->unk_008;
    a.z = p->unk_00C;
    a.unk_14 = 0;
    n = p->unk_0B4;
    cnt = 0;

    if (gBtlWork->unk_0EE == 1 && gBtlWork->unk_120 <= 0) {
        if (func_08093B38() <= 4) {
            flag = 0;
        } else {
            switch (p->unk_000) {
            case 10:
            case 15:
            case 25:
            case 26:
            case 27:
            case 31:
                v = 2;
                break;
            case 0:
            case 5:
            case 6:
            case 9:
            case 11:
            case 14:
            case 16:
            case 18:
            case 20:
            case 21:
            case 22:
            case 28:
            case 29:
                v = 4;
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 7:
            case 12:
            case 13:
            case 17:
            case 19:
            case 23:
            case 24:
            case 30:
                v = 3;
                break;
            default:
                v = 0;
                break;
            }

            if (v > 99) {
                flag = 1;
            } else if (v == 0) {
                flag = 0;
            } else {
                if (gGameState.unk_1B8 == 1 || gGameState.unk_1B8 == 10) {
                    v = (v * 5 * 128) >> 8;
                }
                v = 100 / v;
                r = GetRandom();
                hit = 0;

                if ((u16)r % v == 0) {
                    hit = 1;
                }
                flag = hit;
            }
        }

        if (gGameState.flags & 8) {
            flag = 0;
        }

        if (gBtlWork->unk_10C != 120 && gBtlWork->unk_10C != 124) {
            if (flag != 0) {
                func_0809B6D0(&gBtlWork->unk_02C, p->unk_004 >> 8, p->unk_008 >> 8, p->unk_00C >> 8, p->unk_000);
            } else {
                b.x = p->unk_004;
                b.y = p->unk_008;
                b.z = p->unk_00C;
                func_08096DB0(&gBtlWork->unk_02C, &b);
            }
        }
    }

    if (func_0801B818(&a, 0, 0x578, &n, &cnt)) {
        return;
    }
    if (func_0801B818(&a, 8, 199, &n, &cnt)) {
        return;
    }
    if (func_0801B818(&a, 5, 60, &n, &cnt)) {
        return;
    }
    if (func_0801B818(&a, 7, 30, &n, &cnt)) {
        return;
    }
    if (func_0801B818(&a, 4, 10, &n, &cnt)) {
        return;
    }
    if (func_0801B818(&a, 6, 5, &n, &cnt)) {
        return;
    }
    func_0801B818(&a, 3, 1, &n, &cnt);
}

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
INCLUDE_ASM("unk_08019050/func_0801BCF8.s");
#endif

void func_0801BDD4(BtlObj* p, s32 v) {
    p->unk_0D8 = v;
}

u8 func_0801BDDC(s32 id, s32 x, s32 y, s32 z) {
    EmySpawn s;
    s32 born;

    born = 1;
    s.unk_10 = 0;

    switch (id) {
    case 0:
        s.desc = &gTaskDescEmy00;
        born = 0;
        break;
    case 1:
        s.desc = &gTaskDescEmy01;
        break;
    case 2:
        s.desc = &gTaskDescEmy02;
        break;
    case 3:
        s.desc = &gTaskDescEmy03;
        break;
    case 4:
        s.desc = &gTaskDescEmy04;
        break;
    case 5:
        s.desc = &gTaskDescEmy06;
        break;
    case 6:
        s.desc = &gTaskDescEmy07;
        break;
    case 7:
        s.desc = &gTaskDescEmy08;
        break;
    case 9:
        s.desc = &gTaskDescEmy14;
        break;
    case 10:
        s.desc = &gTaskDescEmy15;
        break;
    case 11:
        s.desc = &gTaskDescEmy16;
        break;
    case 12:
        s.desc = &gTaskDescEmy18;
        break;
    case 13:
        s.desc = &gTaskDescEmy19;
        break;
    case 14:
        s.desc = &gTaskDescEmy21;
        break;
    case 15:
        s.desc = &gTaskDescEmy22;
        break;
    case 16:
        s.desc = &gTaskDescEmy23;
        break;
    case 17:
        s.desc = &gTaskDescEmy25;
        break;
    case 18:
        s.desc = &gTaskDescEmy26;
        s.unk_10 |= 1;
        break;
    case 19:
        s.desc = &gTaskDescEmy27;
        break;
    case 20:
        s.desc = &gTaskDescEmy28;
        s.unk_10 |= 1;
        break;
    case 21:
        s.desc = &gTaskDescEmy29;
        s.unk_10 |= 1;
        break;
    case 22:
        s.desc = &gTaskDescEmy30;
        s.unk_10 |= 1;
        break;
    case 23:
        s.desc = &gTaskDescEmy31;
        s.unk_10 |= 1;
        break;
    case 24:
        s.desc = &gTaskDescEmy37;
        born = 0;
        break;
    case 25:
        s.desc = &gTaskDescEmy38;
        s.unk_10 |= 1;
        break;
    case 26:
        s.desc = &gTaskDescEmy39;
        s.unk_10 |= 1;
        break;
    case 27:
        s.desc = &gTaskDescEmy41;
        s.unk_10 |= 1;
        break;
    case 28:
        s.desc = &gTaskDescEmy44;
        s.unk_10 |= 1;
        break;
    case 29:
        s.desc = &gTaskDescEmy81;
        break;
    case 30:
        s.desc = &gTaskDescEmy82;
        break;
    case 31:
        s.desc = &gTaskDescEmy83;
        break;
    case 47:
        s.desc = &gTaskDescEmyTrumpH;
        born = 0;
        break;
    case 46:
        s.desc = &gTaskDescEmyTrumpS;
        born = 0;
        break;
    default:
        s.desc = &gTaskDescEmy00;
        break;
    }
    s.x = x;
    s.y = y;
    s.z = z;
    s.unk_12 = gUnk_09EDA4EC[id];

    if (born != 0) {
        TaskCreate(&gBtlWork->unk_02C, &gTaskDescBtlBorn, &s);
    } else {
        if (CanAllocObjTiles(s.unk_12) == 0 || CanAllocObjPalette(1) == 0) {
            gBtlWork->unk_120--;
            return 0;
        }
        TaskCreate(&gBtlWork->unk_02C, s.desc, &s.x);
    }
    return 1;
}

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

INCLUDE_ASM("unk_08019050/func_0801C314.s");

#ifdef NON_MATCHING
u8 func_0801C6D4(s32 a) {
    if (gBtlWork->unk_128 != 0) {
        return gBtlWork->unk_128(a);
    }
    return 0;
}
#else
INCLUDE_ASM("unk_08019050/func_0801C6D4.s");
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

void func_0801C830(BtlObj* p) {
    switch (p->unk_000) {
    case 0:
        func_0800FDD0(84);
        break;
    case 1:
        func_0800FDD0(87);
        break;
    case 2:
        func_0800FDD0(88);
        break;
    case 3:
        func_0800FDD0(89);
        break;
    case 4:
        func_0800FDD0(90);
        break;
    case 5:
        func_0800FDD0(98);
        break;
    case 6:
        func_0800FDD0(110);
        break;
    case 7:
        func_0800FDD0(111);
        break;
    case 9:
        func_0800FDD0(85);
        break;
    case 10:
        func_0800FDD0(91);
        break;
    case 11:
        func_0800FDD0(92);
        break;
    case 12:
        func_0800FDD0(93);
        break;
    case 13:
        func_0800FDD0(94);
        break;
    case 14:
        func_0800FDD0(96);
        break;
    case 15:
        func_0800FDD0(97);
        break;
    case 16:
        func_0800FDD0(99);
        break;
    case 17:
        func_0800FDD0(101);
        break;
    case 18:
        func_0800FDD0(102);
        break;
    case 19:
        func_0800FDD0(103);
        break;
    case 20:
        func_0800FDD0(104);
        break;
    case 21:
        func_0800FDD0(105);
        break;
    case 22:
        func_0800FDD0(107);
        break;
    case 23:
        func_0800FDD0(108);
        break;
    case 24:
        func_0800FDD0(109);
        break;
    case 25:
        func_0800FDD0(86);
        break;
    case 26:
        func_0800FDD0(95);
        break;
    case 27:
        func_0800FDD0(100);
        break;
    case 28:
        func_0800FDD0(106);
        break;
    case 29:
        func_0800FDD0(113);
        break;
    case 30:
        func_0800FDD0(114);
        break;
    case 31:
        func_0800FDD0(112);
        break;
    case 32:
        func_0800FDD0(115);
        break;
    case 34:
        func_0800FDD0(117);
        break;
    case 36:
        func_0800FDD0(116);
        break;
    case 38:
        func_0800FDD0(118);
        break;
    }
}

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
