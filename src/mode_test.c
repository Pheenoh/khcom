#include "macros.h"
#include "mode_test.h"
#include "gba/keys.h"

#ifndef VERSION_EU
void* gUnk_02034A08;
void* gUnk_02034A0C;
s32 gUnk_02034A10;
#endif
u32 gUnk_02034A14;
u8 gUnk_02034A18;
UnkStruct_02034A1C* gUnk_02034A1C;
u8 gUnk_02034A20;
u8 gUnk_02034A21;
s32 gUnk_02034A24;
s32 gUnk_02034A28;
void* gUnk_02034A2C;
#ifdef VERSION_JP
u32 gUnkJp_0203498C;
#endif
TaskPool gUnk_02034A30;
u8 gUnk_02034A44;
TaskPool gUnk_02034A48;
UnkStruct_02034A5C* gUnk_02034A5C;
TaskPool gUnk_02034A60;
u8 gUnk_02034A74;
s32 gUnk_02034A78;
u8 gUnk_02034A7C;

#ifndef VERSION_EU
void mode_test_0(void) {
    gUnk_02034A10 = 0;
    gUnk_02034A08 = LoadObjTiles(gUnk_08B24DAA, 0x7C0);
    gUnk_02034A0C = LoadObjPalette(gUnk_08F69BA4, 0x20);
}
#endif

#ifndef VERSION_EU
void mode_test_1(void) {
    if (GetKeysRepeat() & DPAD_LEFT) {
        gUnk_02034A10--;
    } else if (GetKeysRepeat() & DPAD_RIGHT) {
        gUnk_02034A10++;
    }

    if (gUnk_02034A10 < 0) {
        gUnk_02034A10 = 0;
    }

    if (gUnk_02034A10 > 13) {
        gUnk_02034A10 = 13;
    }

    DrawSprite(120, 80, gUnk_09EE14D4[gUnk_02034A10], gUnk_02034A08, gUnk_02034A0C, 0, 0, 0);
}
#endif

#ifndef VERSION_EU
void mode_test_2(void) {
    ReleaseObjTiles(gUnk_02034A08);
    ReleaseObjPalette(gUnk_02034A0C);
}
#endif

#ifndef VERSION_EU
void func_0805F1C0(s32* p, s32 v) {
    *p += (v - *p) >> 1;
}
#else
INCLUDE_ASM("mode_test/func_0805F1C0.s");
#endif

#ifdef VERSION_EU
INCLUDE_ASM("mode_test/eu_08060C44.s");
#endif

void task_lockon_0(LockonWork* w) {
    s32 i;

    gUnk_02039DC4 = EwramAlloc(12);
    w->tiles = AllocObjTiles(0x80, 0);
    w->palette = LoadObjPalette(gUnk_08F69BE4, 0x20);
    func_08002A10(w->tiles, gUnk_090D7C84);
    AnimInit(&w->anim, gUnk_09EEC66C, gUnk_09EEC660);
    AnimStart(&w->anim, 0, 1);
    w->gfx = AnimGetGfx(&w->anim);

    for (i = 0; i < 8; i++) {
        w->unk_0C[i] = 0;
    }

    w->unk_2C = 0;
    w->unk_2D = -1;
    w->unk_2F = 0;
    w->unk_30 = 0;
    w->unk_4C = 0;
}

#ifdef NON_MATCHING
u8 task_lockon_1(LockonWork* w) {
    FldObj* o;
    s8 count;
    s8 i;
    s8 nsel;
    s8 list[8];
    s32 px;
    s32 py;
    s32 dx;
    s32 dy;
    s32 ox;
    s32 oy;

    i = 0;
    o = ListPoolFirst(&gUnk_02039BA0->unk_58);

    if (gUnk_02039BA0->unk_70 & 1) {
        gUnk_02039BA0->unk_68 = 0;
        return 1;
    }

    func_0805F66C(w);

    if (w->unk_2E != w->unk_2D) {
        w->unk_30 = 0;
    }

    px = gUnk_02039BA0->unk_18;
    py = gUnk_02039BA0->unk_1C;
    count = 0;

    if ((gUnk_02039BA0->unk_70 & 2) == 0) {
        while (o != 0) {
            ox = o->unk_00;
            oy = o->unk_04;
            dx = px - ox;
            dy = py - oy;

            if (func_0805F588(dx, dy) <= 0x3000 && (dx > -0x8000 && dx < 0x8000) && (dy > -0x8000 && dy < 0x8000) && o->unk_0C == gUnk_02039BA0->unk_24) {
                if (o->unk_30 == 3) {
                    gUnk_02039DC4->unk_00 = o->unk_00;
                    gUnk_02039DC4->unk_04 = o->unk_04;
                    gUnk_02039DC4->unk_08 = o->unk_08;
                }

                w->unk_0C[count++] = o;
                w->unk_2C++;
            }

            if (count > 6) {
                break;
            }

            o = ListPoolNext(&o->unk_1C);
        }

        if (w->unk_2C != 0) {
            nsel = 0;

            for (i = 0; i < w->unk_2C; i++) {
                if (func_0805F6B4(gUnk_02039BA0->unk_2C, px, py, w->unk_0C[i])) {
                    w->unk_2D = i;
                    list[nsel++] = i;
                }
            }

            if (nsel > 1) {
                w->unk_2D = func_0805F5D8(px, py, w, nsel, list);
            }
        }
    }

    if (w->unk_2D >= 0) {
        gUnk_02039BA0->unk_68 = w->unk_0C[w->unk_2D];
    } else {
        gUnk_02039BA0->unk_68 = 0;
        w->unk_30 = 0;
    }

    w->unk_2E = w->unk_2D;
    w->gfx = AnimUpdate(&w->anim);
    return 1;
}
#else
INCLUDE_ASM("mode_test/task_lockon_1.s");
#endif
#ifdef NON_MATCHING
void task_lockon_2(LockonWork* w) {
    FldObj* obj;
    s32 x;
    s32 y;
    s32 x2;
    s32 y2;

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        return;
    }

    obj = w->unk_0C[w->unk_2D];

    if (obj->unk_30 == 2) {
        return;
    }

    x = (obj->unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    x2 = x + 12;
    y = (obj->unk_04 >> 8) + (obj->unk_08 >> 8) - (gUnk_02039BA0->unk_04 >> 8) - obj->unk_1A;
    y2 = y - 8;

    if (x + 60 > 240) {
        x2 = 192;
    }

    if (y > 160) {
        y2 = 152;
    }

    if (w->unk_2F++ > 10) {
        w->unk_2F = 0;
    }

    if (gUnk_02039BA0->unk_68 == 0) {
        return;
    }

    if (w->unk_2D < 0) {
        return;
    }

    obj = w->unk_0C[w->unk_2D];
    DrawSprite((obj->unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8), (obj->unk_04 >> 8) + (obj->unk_08 >> 8) - (gUnk_02039BA0->unk_04 >> 8) - obj->unk_1A + 40, w->gfx, w->tiles, w->palette, 0, 0, (u16)(-0x100E - ((w->unk_0C[w->unk_2D]->unk_04 >> 8) << 2)));
}
#else
INCLUDE_ASM("mode_test/task_lockon_2.s");
#endif

void task_lockon_3(LockonWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    gUnk_02039BA0->unk_68 = 0;
    EwramFree(gUnk_02039DC4);
    gUnk_02039DC4 = 0;
}

s32 func_0805F588(s32 a, s32 b) {
    return (u16)Sqrt(a * a + b * b);
}

s32 func_0805F5A4(s32* x, s32* y) {
    s32 d = func_0805F588(*x, *y);

    if (d > 0) {
        *x = (*x << 8) / d;
        *y = (*y << 8) / d;
    }

    return d;
}

s8 func_0805F5D8(s32 a, s32 b, LockonWork* w, s8 n, s8* list) {
    s8 i;
    s8 best;
    s32 bestDist;
    FldObj* o;
    s32 dist;
    s32 dx;
    s32 dy;

    best = -1;
    bestDist = 0x10000;

    for (i = 0; i < n; i++) {
        o = w->unk_0C[list[i]];

        if (o != 0) {
            dx = o->unk_00;
            dy = o->unk_04;
            dist = func_0805F588(dx - a, dy - b);

            if (bestDist > dist) {
                bestDist = dist;
                best = i;
            }
        }
    }

    if (best != -1) {
        return list[best];
    }

    return best;
}

void func_0805F66C(LockonWork* w) {
    s8 i;

    if ((gUnk_02039BA0->unk_70 & 2) == 0) {
        w->unk_2D = -1;

        for (i = 0; i < 8; i++) {
            w->unk_0C[i] = 0;
        }

        w->unk_2C = 0;
    }
}

u8 func_0805F6B4(u16 a, s32 b, s32 c, FldObj* d) {
    s32 x;
    s32 y;
    s32 sn;
    s32 cs;
    s32 dot;

    if (d != 0) {
        x = d->unk_00 - b;
        y = d->unk_04 - c;
        sn = gSineTable[a & 0xFF];
        cs = -gSineTable[(a & 0xFF) + 0x40];
        func_0805F5A4(&x, &y);
        dot = (sn * x >> 8) + (y * cs >> 8);

        if (d->unk_30 == 3) {
            if (dot > 99) {
                return 1;
            }
        } else {
            if (dot > 19) {
                return 1;
            }
        }
    }

    return 0;
}

void func_0805F728(s32* x, s32* y) {
    if (gUnk_02039DC4 != 0) {
        *x = (gUnk_02039DC4->unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
        *y = (gUnk_02039DC4->unk_04 >> 8) + (gUnk_02039DC4->unk_08 >> 8) - (gUnk_02039BA0->unk_04 >> 8) - 24;
    } else {
        *x = 0;
        *y = 0;
    }
}

void func_0805F770(void) {
    s32 a;
    s32 b;
    void* charBase = GetBgCharBase(0);
    void* screenBase = GetBgScreenBase(0);

    a = 0;
    CpuFastSet(&a, charBase, 0x01001500);
    b = 0;
    CpuFastSet(&b, screenBase, 0x01000140);
}

void func_0805F7B0(s32 a) {
    gUnk_02034A24 = a;
}

void func_0805F7BC(void) {
    func_0805F770();
}

void func_0805F7C8(u8 a) {
    gUnk_02034A2C = (u8*)GetBgCharBase(0) + (a << 12);
}

void func_0805F7E8(u8 x, u8 y, u16* s) {
    u8 i;
    u16 c;

    for (i = 0; i <= 59 && (u8)*s != 0; i++, s++) {
        c = *s;
        c = (u8)(c >> 8) | (c << 8);

        switch (c & 0xFF00) {
        case 0x8100:
            gUnk_02034A1C[gUnk_02034A20].unk_00[i] = c + 0x7EC0;
            break;
        case 0x8200:
            gUnk_02034A1C[gUnk_02034A20].unk_00[i] = (c + 0x7DC0) | 0x400;
            break;
        }
    }

    gUnk_02034A1C[gUnk_02034A20].unk_7A = x;
    gUnk_02034A1C[gUnk_02034A20].unk_7B = y;
    gUnk_02034A1C[gUnk_02034A20].unk_7D = i;
    gUnk_02034A20++;
}

u8 func_0805F8F0(u8 a) {
    return a * 4 % 32;
}

void func_0805F904(void) {
    u8 i;
    u8 j;

    for (i = 0; i <= 19; i++) {
        for (j = 0; j <= 60; j++) {
            gUnk_02034A1C[i].unk_00[j] = 0;
        }
    }
}

s32 func_0805F93C(u8 bg, u8 b, u8 c, u8 d, u8 e) {
    u8 i;
    u8 j;
    u8 r;
    u8 k;
    u16 col;
    u32 p;
    u32* dst;
    u32* src;
    u32 t;
    u32 ko;
    u32 ko4;
    u32 co;
    s32 n;

    j = 0;
    gUnk_02034A14 = (u32)GetBgCharBase(bg) + c * 0x400 + (b + 1) * 32;
    b = ((b + d) >> 3) + 1;
    n = (s8)d + b;
    d = n;
    e += (c + e) >> 3;
    k = c & 7;
    col = (c >> 3) << 3;

    for (; j < e; j++) {
        for (i = 0; i < d; i++) {
            ko = k * 4;
            co = col * 4;
            ko4 = ko + 4;
            p = gUnk_02034A14 + i * 32 + j * 1024;
            dst = (u32*)(p + ko + co);
            src = (u32*)(p + ko4 + co);

            for (r = 0; r < 9; r++) {
                t = ((u32)dst & 0xFF) + 4;

                if (t == ((t >> 5) << 5)) {
                    *dst++ = *(u32*)((u8*)src + 0x3E0);
                    dst += 248;
                    src += 249;
                } else {
                    *dst++ = *src++;
                }
            }
        }

        k++;

        if (k == 8) {
            col += 0x100;
            k = 0;
        }
    }

    return 1;
}

void func_0805FA60(s32 a, void* b, s32 c, u8 d) {
    if (b != 0) {
        LoadPalette(b, (void*)(d * 32 + 0x05000000), 32);
    }

    gUnk_02034A18 = d;
}

void func_0805FA8C(u8 bg, u16 b, u16 c) {
    s32 fillA;
    s32 fillB;
    u8 i;
    u8 j;
    void* charBase = GetBgCharBase(bg);
    void* screenBase = GetBgScreenBase(bg);

    fillA = 0;
    CpuSet(&fillA, charBase, (b >> 2) | CPU_SET_32BIT | CPU_SET_SRC_FIXED);
    fillB = 0;
    CpuSet(&fillB, screenBase, (c >> 2) | CPU_SET_32BIT | CPU_SET_SRC_FIXED);

    gUnk_02034A1C = EwramAlloc(0xA50);
    gUnk_02034A20 = 0;

    for (i = 0; i <= 19; i++) {
        for (j = 0; j <= 60; j++) {
            gUnk_02034A1C[i].unk_00[j] = 0;
        }

        gUnk_02034A1C[i].unk_7A = 0;
        gUnk_02034A1C[i].unk_7B = 0;
        gUnk_02034A1C[i].unk_7C = 0;
        gUnk_02034A1C[i].unk_7D = 0;
    }

    func_0805F7B0(0);
    gUnk_02034A21 = 0;
    gUnk_02034A18 = 0;
    EnableBg(bg);
}

void func_0805FB78(s32 a) {
    gUnk_02034A28 = a;
}

void func_0805FB84(u8 x, u8 y, u32 c, u8 v) {
    u8 buf[8];

    buf[3] = v / 10;
    buf[5] = v - buf[3] * 10;
    buf[0] = 0x82;
    buf[1] = 0x98;
    buf[2] = 0x82;
    buf[3] += 0x4F;
    buf[4] = 0x82;
    buf[5] += 0x4F;
    buf[6] = 0;
    func_0805FCB0(x, y, c, buf);
}

void func_0805FC04(u8 x, u8 y, u32 c, u16 v) {
    u8 buf[8];

    buf[1] = v / 100;
    buf[3] = v / 10 - buf[1] * 10;
    buf[5] = v - (buf[1] * 100 + buf[3] * 10);
    buf[0] = 0x82;
    buf[1] += 0x4F;
    buf[2] = 0x82;
    buf[3] += 0x4F;
    buf[4] = 0x82;
    buf[5] += 0x4F;
    buf[6] = 0;
    func_0805FCB0(x, y, c, buf);
}

INCLUDE_ASM("mode_test/func_0805FCB0.s");
void func_08060470(u8 bg) {
    u8 n;
    u8 i;
    u8 k;
    u8 x;
    u8 y;
    u16* screen;
    u32* tiles;
    u32* src;

    screen = GetBgScreenBase(bg);

    for (n = 0; n < gUnk_02034A20; n++) {
        tiles = (u32*)((u8*)GetBgCharBase(bg) + (n * 0x1000 + 0x2000));
        x = gUnk_02034A1C[n].unk_7A;
        y = gUnk_02034A1C[n].unk_7B;

        for (i = 0; i < gUnk_02034A1C[n].unk_7D; i++) {
            src = (u32*)&gUnk_0941DD38[gUnk_02034A1C[n].unk_00[i] * 32];

            for (k = 0; k < 8; k++) {
                tiles[k] = src[0];
                tiles[k + 0x100] = src[0x100];
                src++;
            }

            *(screen + x + i + (y << 5)) = (i + 0x100 + n * 128) | 0x1000;
            *(screen + x + i + ((y + 1) << 5)) = (i + 0x120 + n * 128) | 0x1000;
            tiles += 8;
        }
    }
}

void func_08060598(void) {
    gUnk_02034A20 = 0;
}

INCLUDE_ASM("mode_test/func_080605A4.s");

void func_0806098C(void) {
    EwramFree(gUnk_02034A1C);
}

void func_080609A0(void) {
    func_0806098C();
}

u16 func_080609AC(u16 a) {
    s32 n;
    u16 v;
    CardStat* stat;

    if (a & 0x8000) {
        return gCardDefs[a & 0x0FFF].unk_1C.unk_10;
    }

    if ((a & 0x0FFF) <= 0x1C1) {
        stat = &gCardDefs[a & 0x0FFF].unk_1C;
        n = stat->unk_04;

        if (n == 0) {
            n = 10;
        }

        n--;
        v = stat->unk_10;
        v += (v / 10) * n;
        return v;
    }

    return gCardDefs[a & 0x0FFF].unk_1C.unk_10;
}

u16 func_08060A2C(u16 a) {
    u16 v;

    if ((a & 0x8000) == 0) {
        v = func_080609AC(a) / 5 * 2;
    } else {
        v = func_080609AC(a & 0x0FFF) / 5 * 2 + 10;
    }

    return v;
}

void func_08060A74(void) {
    gUnk_02034A44 = 0;
    TaskPoolInit(&gUnk_02034A30, 1);

    if ((gGameState.flags & 8) == 0) {
        TaskCreate(&gUnk_02034A30, &gUnk_09EE4AF4, &gUnk_02034A44);
    } else {
        TaskCreate(&gUnk_02034A30, &gUnk_09EE8EF0, &gUnk_02034A44);
    }

    if (gSystemFlags & 1) {
        m4aMPlayAllStop();
    }
}

void func_08060AD8(void) {
    if (gSystemFlags & 1) {
        func_080B0754();
    } else {
        UpdatePlayTime();
    }

    TaskPoolUpdate(&gUnk_02034A30);
    TaskPoolDraw(&gUnk_02034A30);

    if (gUnk_02034A44 == 7) {
        if (gUnk_03006C10 & 1) {
            ModeRequest(&gModeChkbtl, 0);
        } else if (gSystemFlags & 1) {
            ModeRequest(&gModeSioBtlOption, 1);
        } else {
            func_080E052C(0);
        }
    }

    if (gUnk_02034A44 == 8) {
        if (gUnk_03006C10 & 1) {
            ModeRequest(&gModeChkbtl, 0);
        } else if (gSystemFlags & 1) {
            ModeRequest(&gModeSioBtlOption, 1);
        } else {
            func_080E052C(1);
        }
    }
}

void func_08060BAC(void) {
    TaskPoolDestroy(&gUnk_02034A30);
}
void menu_0(MenuWork* w) {
    gUnk_02039BA0->unk_70 |= 0x1000;
    gUnk_02039BA0->unk_70 |= 0x80;
    gUnk_02039BA0->unk_70 |= 0x2000;
    w->unk_08 = 0xF000;
    w->unk_0C = 0x4800;
    w->unk_11 = 0;
    w->unk_10 = 0;
    w->tiles = LoadObjTiles(gUnk_090D4DD0, 0x2E80);
    w->palette = LoadObjPalette(gUnk_096148B8, 0x20);
    m4aSongNumStart(103);
}

u8 menu_1(MenuWork* w) {
    switch (w->unk_10) {
    case 0:
        w->unk_08 += (0xBC00 - w->unk_08) >> 1;

        if ((w->unk_08 >> 8) == 0xBC) {
            w->unk_10 = 1;
        }

        if (GetKeysPressed() & B_BUTTON) {
            w->unk_10 = 4;
        }

        break;
    case 1:
        if (GetKeysRepeat() & DPAD_UP) {
            if (w->unk_11 != 0) {
                w->unk_11--;
            } else {
                w->unk_11 = 5;
            }

            m4aSongNumStart(101);
        }

        if (GetKeysRepeat() & DPAD_DOWN) {
            if (w->unk_11 <= 4) {
                w->unk_11++;
            } else {
                w->unk_11 = 0;
            }

            m4aSongNumStart(101);
        }

        if (GetKeysPressed() & A_BUTTON) {
            switch (w->unk_11) {
            case 0:
                w->unk_10 = 2;
                w->unk_11 = 6;
                m4aSongNumStart(103);
                break;
            case 2:
                func_0801CB0C();
                func_08006184(0, 32);
                w->unk_10 = 4;
                m4aSongNumStart(102);
                break;
            case 1:
            case 3:
            case 4:
                m4aSongNumStart(105);
                break;
            case 5:
                m4aSongNumStart(105);
                break;
            }
        }

        if (GetKeysPressed() & B_BUTTON) {
            w->unk_10 = 5;
            m4aSongNumStart(104);
        }

        break;
    case 2:
        if (GetKeysRepeat() & DPAD_UP) {
            if (w->unk_11 > 6) {
                w->unk_11--;
            } else {
                w->unk_11 = 9;
            }

            m4aSongNumStart(101);
        }

        if (GetKeysRepeat() & DPAD_DOWN) {
            if (w->unk_11 <= 8) {
                w->unk_11++;
            } else {
                w->unk_11 = 6;
            }

            m4aSongNumStart(101);
        }

        if (GetKeysPressed() & B_BUTTON) {
            w->unk_10 = 1;
            w->unk_11 = 0;
            m4aSongNumStart(104);
        }

        if (GetKeysPressed() & A_BUTTON) {
            switch (w->unk_11) {
            case 6:
                w->unk_11 = 0;
                w->unk_10 = 1;
                m4aSongNumStart(102);
                break;
            case 7:
                w->unk_11 = 0;
                w->unk_10 = 1;
                m4aSongNumStart(102);
                break;
            case 8:
                w->unk_11 = 0;
                w->unk_10 = 1;
                m4aSongNumStart(102);
                break;
            case 9:
                func_0801CB0C();
                func_08006184(0, 32);
                w->unk_10 = 4;
                m4aSongNumStart(102);
                break;
            }
        }

        break;
    case 4:
        w->unk_08 += (0x11800 - w->unk_08) >> 1;

        if ((w->unk_08 >> 8) > 274) {
            if (func_08006314() == 0) {
                if (w->unk_11 != 2) {
                    if (w->unk_11 == 9) {
                        ModeRequest(&gUnk_09EE2704, 0);
                    }
                } else {
                    ModeRequest(&gModeAllmap, 0);
                }

                w->unk_10 = 5;
            }
        }

        break;
    case 5:
        w->unk_08 += (0x11800 - w->unk_08) >> 1;

        if ((w->unk_08 >> 8) > 274) {
            return 0;
        }

        break;
    case 3:
    default:
        break;
    }

    return 1;
}

void menu_2(MenuWork* w) {
    DrawSprite(w->unk_08 >> 8, w->unk_0C >> 8, gUnk_09EEC600[w->unk_11], w->tiles, w->palette, 0, 0, 80);
}

void menu_3(MenuWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    gUnk_02039BA0->unk_70 &= ~0x1000;
    gUnk_02039BA0->unk_70 &= ~0x80;
    gUnk_02039BA0->unk_70 &= ~0x2000;
}

void func_08060ED8(void) {
    TaskPoolInit(&gUnk_02034A48, 2);

    if ((gGameState.flags & 8) == 0) {
        gUnk_02034A5C = TaskCreate(&gUnk_02034A48, &gUnk_09EE2834, 0);
    } else {
        gUnk_02034A5C = TaskCreate(&gUnk_02034A48, &gUnk_09EE284C, 0);
    }
}

#ifndef VERSION_EU
void func_08060F1C(void) {
    ContinueWork* w;

    TaskPoolUpdate(&gUnk_02034A48);
    TaskPoolDraw(&gUnk_02034A48);
    w = gUnk_02034A5C->unk_04;

    if (w->unk_6A == 3) {
        switch (w->unk_60) {
        case 0:
            func_080E04EC();
            break;
        case 1:
            SoftReset(255);
            break;
        }
    }
}
#else
INCLUDE_ASM("mode_test/func_08060F1C.s");
#endif

void func_08060F64(void) {
    TaskPoolDestroy(&gUnk_02034A48);
}
void Event_0(s32 arg) {
    EvtArg cfg;
    UnkStruct_09EE3CA0* e;

    gUnk_02039DC8 = EwramAlloc(0x8C);
    e = gUnk_09EE3CA0[arg & 0x7FFF];
    gBldCnt = 0;
    gBldAlpha = 0;
    gUnk_02034A78 = arg;
    gUnk_02034A74 = 0;

    if (e != 0) {
        if (e->unk_24 != 0) {
            SetBgMode1();
            SetupBg(0, 3, 31, 14);
            SetupBg(1, 0, 16, 0);
            SetupBg(2, 0, 17, 0);
            SetupBg(3, 0, 18, 0);
            SetBgPriority(0, 0);
            SetBgPriority(1, 1);
            SetBgPriority(2, 2);
            SetBgPriority(3, 3);
        } else {
            SetBgMode0();
            SetupBg(0, 3, 31, 14);
            SetupBg(1, 0, 21, 0);
            SetupBg(2, 0, 22, 0);
            SetupBg(3, 0, 23, 0);
            SetBgPriority(0, 0);
            SetBgPriority(1, 1);
            SetBgPriority(2, 2);
            SetBgPriority(3, 3);
            DisableBg(0);
            DisableBg(1);
            DisableBg(2);
            DisableBg(3);
        }
    } else {
        SetBgMode0();
        SetBgMode0();
        SetupBg(0, 0, 22, 0);
        SetupBg(1, 0, 24, 0);
        SetupBg(2, 2, 28, 14);
        SetBgPriority(0, 3);
        SetBgPriority(1, 2);
        SetBgPriority(2, 1);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
    }

    cfg.unk_00 = arg;
    gUnk_02039DC8->unk_74 = arg & 0x7FFF;

    if (arg & 0x8000) {
        cfg.unk_08 = 0;
    } else {
        cfg.unk_08 = 1;
    }

    if (gUnk_09EE3FB4[gUnk_02034A78 & 0x8000]->unk_08->unk_14 & 0x80) {
        func_08006120(1, 999);
    }

    TaskPoolInit(&gUnk_02034A60, 2);
    TaskCreate(&gUnk_02034A60, &gTaskDescEventSeq, &cfg);
    func_080A42B4();
    gUnk_02034A7C = 0;
}
void func_0806119C(void) {
    if (gUnk_02039DC8 == 0) {
        ModeRequest(&gModeEventselect, 0);
    }

    if (gUnk_02034A74 == 0) {
        TaskPoolUpdate(&gUnk_02034A60);
    } else if (GetKeysRepeat() & 4) {
        TaskPoolUpdate(&gUnk_02034A60);
    }

    TaskPoolDraw(&gUnk_02034A60);

    if (gUnk_02039DC8->unk_7A == 0) {
        if (gUnk_02034A7C == 0) {
            func_08061824();
            gUnk_02034A7C = 1;
        }

        if (gUnk_02034A7C == 1) {
            if (func_080A42C8() == 0) {
                ModeRequest(&gModeEventselect, 0);
            }
        }
    }

    if (GetKeysPressed() & 8) {
        gUnk_02034A74 = 0;
    }
}

INCLUDE_ASM("mode_test/func_08061248.s");

void Event_2(void) {
    TaskPoolDestroy(&gUnk_02034A60);
    EwramFree(gUnk_02039DC8);
    gUnk_02039DC8 = 0;
}
