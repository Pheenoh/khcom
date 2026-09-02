#include "macros.h"
#include "mode_test.h"
#include "gba/keys.h"

void mode_test_0(void) {
    gUnk_02034A10 = 0;
    gUnk_02034A08 = LoadObjTiles(gUnk_08B24DAA, 0x7C0);
    gUnk_02034A0C = LoadObjPalette(gUnk_08F69BA4, 0x20);
}

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

void mode_test_2(void) {
    ReleaseObjTiles(gUnk_02034A08);
    ReleaseObjPalette(gUnk_02034A0C);
}

void func_0805F1C0(s32* p, s32 v) {
    *p += (v - *p) >> 1;
}

void task_lockon_0(LockonWork* w) {
    s32 i;

    gUnk_02039DC4 = EwramAlloc(12);
    w->unk_00 = AllocObjTiles(0x80, 0);
    w->unk_04 = LoadObjPalette(gUnk_08F69BE4, 0x20);
    func_08002A10(w->unk_00, gUnk_090D7C84);
    AnimInit(&w->unk_34, gUnk_09EEC66C, gUnk_09EEC660);
    AnimStart(&w->unk_34, 0, 1);
    w->unk_08 = AnimGetGfx(&w->unk_34);

    for (i = 0; i < 8; i++) {
        w->unk_0C[i] = 0;
    }

    w->unk_2C = 0;
    w->unk_2D = -1;
    w->unk_2F = 0;
    w->unk_30 = 0;
    w->unk_4C = 0;
}

INCLUDE_ASM("mode_test/task_lockon_1.s");
INCLUDE_ASM("mode_test/task_lockon_2.s");

void task_lockon_3(LockonWork* w) {
    ReleaseObjTiles(w->unk_00);
    ReleaseObjPalette(w->unk_04);
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

INCLUDE_ASM("mode_test/func_0805F93C.s");

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
INCLUDE_ASM("mode_test/func_08060470.s");

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

    if ((gUnk_02039BB0.unk_008 & 8) == 0) {
        TaskCreate(&gUnk_02034A30, &gUnk_09EE4AF4, &gUnk_02034A44);
    } else {
        TaskCreate(&gUnk_02034A30, &gUnk_09EE8EF0, &gUnk_02034A44);
    }

    if (gUnk_03006C78 & 1) {
        m4aMPlayAllStop();
    }
}

void func_08060AD8(void) {
    if (gUnk_03006C78 & 1) {
        func_080B0754();
    } else {
        UpdatePlayTime();
    }

    TaskPoolUpdate(&gUnk_02034A30);
    TaskPoolDraw(&gUnk_02034A30);

    if (gUnk_02034A44 == 7) {
        if (gUnk_03006C10 & 1) {
            func_080010CC(&gUnk_09ECEB54, 0);
        } else if (gUnk_03006C78 & 1) {
            func_080010CC(&gUnk_09EF14DC, 1);
        } else {
            func_080E052C(0);
        }
    }

    if (gUnk_02034A44 == 8) {
        if (gUnk_03006C10 & 1) {
            func_080010CC(&gUnk_09ECEB54, 0);
        } else if (gUnk_03006C78 & 1) {
            func_080010CC(&gUnk_09EF14DC, 1);
        } else {
            func_080E052C(1);
        }
    }
}

void func_08060BAC(void) {
    TaskPoolDestroy(&gUnk_02034A30);
}
void func_08060BBC(MenuWork* w) {
    gUnk_02039BA0->unk_70 |= 0x1000;
    gUnk_02039BA0->unk_70 |= 0x80;
    gUnk_02039BA0->unk_70 |= 0x2000;
    w->unk_08 = 0xF000;
    w->unk_0C = 0x4800;
    w->unk_11 = 0;
    w->unk_10 = 0;
    w->unk_00 = LoadObjTiles(gUnk_090D4DD0, 0x2E80);
    w->unk_04 = LoadObjPalette(gUnk_096148B8, 0x20);
    m4aSongNumStart(103);
}

INCLUDE_ASM("mode_test/func_08060C18.s");

void func_08060E64(MenuWork* w) {
    DrawSprite(w->unk_08 >> 8, w->unk_0C >> 8, gUnk_09EEC600[w->unk_11], w->unk_00, w->unk_04, 0, 0, 80);
}

void func_08060EA0(MenuWork* w) {
    ReleaseObjTiles(w->unk_00);
    ReleaseObjPalette(w->unk_04);
    gUnk_02039BA0->unk_70 &= ~0x1000;
    gUnk_02039BA0->unk_70 &= ~0x80;
    gUnk_02039BA0->unk_70 &= ~0x2000;
}

INCLUDE_ASM("mode_test/func_08060ED8.s");

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

void func_08060F64(void) {
    TaskPoolDestroy(&gUnk_02034A48);
}
INCLUDE_ASM("mode_test/func_08060F74.s");
void func_0806119C(void) {
    if (gUnk_02039DC8 == 0) {
        func_080010CC(&gUnk_09EE47AC, 0);
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
                func_080010CC(&gUnk_09EE47AC, 0);
            }
        }
    }

    if (GetKeysPressed() & 8) {
        gUnk_02034A74 = 0;
    }
}
INCLUDE_ASM("mode_test/func_08061248.s");
void func_080617E8(void) {
    TaskPoolDestroy(&gUnk_02034A60);
    EwramFree(gUnk_02039DC8);
    gUnk_02039DC8 = 0;
}
