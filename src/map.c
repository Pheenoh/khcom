#include "macros.h"
#include "map.h"

UnkStruct_080DFB8C* gUnk_02034F1C;
UnkStruct_02034F20* gUnk_02034F20;
UnkStruct_02034F24* gUnk_02034F24;
u16 gUnk_02034F28;
u16 gUnk_02034F2A;
u16 gUnk_02034F2C;
u16 gUnk_02034F2E;
void* gUnk_02034F30;
UnkStruct_02034F34* gUnk_02034F34;
u8* gUnk_02034F38;
#ifndef VERSION_EU
u8 gUnk_02034F3C[4];
#endif
u8 gUnk_02034F40;
u8 gUnk_02034F41;
u8 gUnk_02034F42;
u32 gUnk_02034F44;
UnkStruct_080DFF1C gUnk_02034F48[3];
u8 gUnk_02034F78;
u8 gUnk_02034F79;
u16 gUnk_02034F7A;
UnkStruct_02034F7C* gUnk_02034F7C;
UnkStruct_02034F80 gUnk_02034F80;
UnkStruct_02034F84* gUnk_02034F84;
s32 gUnk_02034F88;
u32 gUnk_02034F8C;
u8 gUnk_02034F90[0x14];
u8 gUnk_02034FA4;
void* gUnk_02034FA8;
u32 gUnk_02034FAC;
s32 gUnk_02034FB0;
void* gUnk_02034FB4;
void* gUnk_02034FB8;
u8 gUnk_02034FBC;
u8 gUnk_02034FBD[0x17];
s32 gUnk_02034FD4;
u8 gUnk_02034FD8;
u32 gUnk_02034FDC;
UnkStruct_02034FE0* gUnk_02034FE0;
u32 gUnk_02034FE4;

s32 func_080DFEBC(s32 x, s32 y, s32 z) {
    UnkStruct_080DFB8C* p = func_080DFB8C(x, y);
    s32 r;

    if (p == 0) {
        return 0;
    }
    if (p->unk_08 < z) {
        if (p->unk_02 == 4 || p->unk_02 == 6) {
            if (func_080E86C8(p, x, y)) {
                r = p->unk_08;
            } else {
                r = p->unk_0C;
            }
        } else {
            r = p->unk_08;
        }
    } else {
        if (p->unk_02 == 3 || p->unk_02 == 5) {
            if (func_080E86C8(p, x, y)) {
                r = p->unk_0C;
            } else {
                r = p->unk_08;
            }
        } else {
            r = p->unk_0C;
        }
    }
    return r;
}

s32 func_080DFF1C(UnkStruct_080DFF1C* p) {
    return func_080DFEBC(p->unk_00, p->x + p->z, p->z);
}

s32 func_080DFF30(UnkStruct_080DFF1C* p) {
    return func_080DFEBC(p->unk_00, p->x + p->y, -0x100000);
}

void func_080DFF4C(UnkStruct_080DFF1C* p) {
    p->z = func_080DFF30(p);
}

void func_080DFF5C(UnkStruct_080DFF1C* p, s16 x, s16 y, u8 a, u8 b) {
    p->unk_00 = (x << 13) + (a << 12);
    p->x = (y << 12) + (b << 11);
    p->y = 0;
    p->y = p->z = func_080DFF30(p);
    p->x -= p->z;
}

s32 func_080DFF94(s32 x, s32 y, s32 z) {
    switch (func_080DFB8C(x, y + z)->unk_02) {
    case 1:
    case 2:
    case 7:
        return 0;
    case 3:
    case 4:
    case 8:
        return 0xD3;
    case 5:
    case 6:
    case 9:
        return 0x2D;
    }
    return 0x80;
}

void func_080DFFEC(UnkStruct_080DFF1C* p) {
    func_080E524C(p, &p->x);
    p->y = 0;
    p->y = p->z = func_080DFF30(p);
    p->x -= p->z;
}


s32 func_080E0010(s32 x) {
    s32 lim;

    x -= 0x7800;
    lim = (gUnk_02039BA0->unk_10 << 11) - 0xF000;

    if (x < 0) {
        x = 0;
    } else if (x > lim) {
        x = lim;
    }
    return x;
}

s32 func_080E0044(s32 y) {
    s32 lim;

    y -= 0x6000;
    lim = (gUnk_02039BA0->unk_12 << 11) - 0xA000;

    if (y < 0) {
        y = 0;
    } else if (y > lim) {
        y = lim;
    }
    return y;
}

void func_080E0078(void) {
    s16 sx;
    s16 sy;

    gUnk_02039BA0->unk_00 = func_080E0010(gUnk_02039BA0->unk_08);
    gUnk_02039BA0->unk_04 = func_080E0044(gUnk_02039BA0->unk_0C);
    sx = gUnk_02039BA0->unk_00 >> 8;
    sy = gUnk_02039BA0->unk_04 >> 8;
    func_080E4B78(sx / 8, sy / 8);
    SetBgScroll(3, sx, sy);
    SetBgScroll(2, sx, sy);
    SetBgScroll(1, sx, sy);
}

INCLUDE_ASM("map/func_080E00E4.s");

void func_080E0298(s32 x, s32 y) {
    gUnk_02039BA0->unk_08 = x;
    gUnk_02039BA0->unk_0C = y;
}

void func_080E02A8(s32 dx, s32 dy) {
    gUnk_02039BA0->unk_08 += dx;
    gUnk_02039BA0->unk_0C += dy;
}

void func_080E02C0(s32 x, s32 y, s32 z) {
    gUnk_0203C7AC->unk_20 = 1;
    gUnk_0203C7AC->unk_24 = x;
    gUnk_0203C7AC->unk_28 = y;
    gUnk_0203C7AC->unk_2C = z;
}

u8 func_080E02E0(UnkStruct_080DFF1C* p, s16 a, s16 b) {
    if (gUnk_0203C7AC->unk_20 == 0) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_00 & 0x80) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_24 - 0x1400 > p->unk_00 + (a << 8)) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_24 + 0x1400 < p->unk_00 - (a << 8)) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_28 - 0x1400 > p->x + (a << 8)) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_28 + 0x1400 < p->x - (a << 8)) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_2C - 0x2000 > p->y) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_2C + 0x800 < p->y - (b << 8)) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_2C <= p->z) {
        return 1;
    }
    return 0;
}

u8 func_080E0378(void) {
    return func_080DF548(gUnk_0203C590.unk_06);
}

s32 func_080E0390(void) {
    if ((gUnk_02039BA0->unk_70 & 0x42000) || (gUnk_0203C7AC->unk_00 & 0x2000)) {
        return 1;
    }
    return 0;
}

s32 func_080E03C0(s32 a) {
    if (func_080A42C8(a)) {
        return 0;
    }

    if (gUnk_02039BA0->unk_70 & 0x841000) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_00 & 0x84) {
        return 0;
    }

    if (gUnk_02039BA0->unk_20 != gUnk_02039BA0->unk_24) {
        return 0;
    }
    return gUnk_02039BA0->unk_68 == a;
}

void func_080E0418(void) {
    gUnk_0203C7AC->unk_00 |= 1;
}

INCLUDE_ASM("map/func_080E042C.s");
INCLUDE_ASM("map/func_080E04E0.s");

void func_080E04EC(void) {
    switch (gUnk_0203C590.unk_06) {
    case 0xFC:
    case 0xFD:
    case 0xFE:
        ModeRequest(&gModeMapFix, 0);
        break;
    default:
        if (gUnk_0203C590.unk_04 != 13) {
            ModeRequest(&gModeMapFld, 0);
        } else {
            ModeRequest(&gModePooh, 1);
        }
        break;
    }
}

void func_080E052C(u8 a) {
    if (a != 1) {
        gGameState.unk_0F = 0xFF;
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFF, 0x100);
    }
    func_080E04EC();
}

void func_080E0558(void) {
    gUnk_02039BA0->unk_00 = 0;
    gUnk_02039BA0->unk_04 = 0;
    gUnk_02039BA0->unk_08 = 0;
    gUnk_02039BA0->unk_0C = 0;
    gUnk_02039BA0->unk_10 = 32;
    gUnk_02039BA0->unk_12 = 32;
    gUnk_02039BA0->unk_68 = 0;
    gUnk_02039BA0->unk_6C = 60;
    gUnk_02039BA0->unk_70 = 0;
    gUnk_02039BA0->unk_74 = 0;
    TaskPoolInit(gUnk_02039BA0->unk_78, 50);
    TaskPoolInit(gUnk_02039BA0->unk_8C, 1);
    ListPoolInit(gUnk_02039BA0->unk_58);
    TaskPoolInit(gUnk_02039BA0->unk_A0, 25);
    TaskPoolInit(gUnk_02039BA0->unk_C8, 1);
    TaskPoolInit(gUnk_02039BA0->unk_B4, 8);
    gUnk_0203C7AC->unk_00 = 0;
    gUnk_0203C7AC->unk_18 = 0;
    gUnk_0203C7AC->unk_1C = 0;
    gUnk_0203C7AC->unk_20 = 0;
    TaskPoolInit(gUnk_0203C7AC->unk_30, 1);
}

void func_080E05E4(void) {
    func_080DF6D0(gUnk_0203C7AC, gUnk_0203C590.unk_06);

    if (gUnk_0203C7AC->unk_0D == 5) {
        gUnk_02039BA0->unk_70 |= 0x200;
    }
    TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapRnd, 0);
}

INCLUDE_ASM("map/func_080E062C.s");
void func_080E0780(void) {
    if (gUnk_02039BA0->unk_6C > 0) {
        gUnk_02039BA0->unk_70 |= 1;
        gUnk_02039BA0->unk_6C--;
    } else {
        gUnk_02039BA0->unk_70 &= ~1;
    }
    gUnk_0203C7AC->unk_1C = 0;
    TaskPoolUpdate(gUnk_02039BA0->unk_78);
    gUnk_0203C7AC->unk_20 = 0;

    if ((gUnk_02039BA0->unk_70 & 0x1000) == 0 && (gUnk_0203C7AC->unk_00 & 4) == 0) {
        TaskPoolUpdate(gUnk_02039BA0->unk_8C);
    }
    if ((gUnk_02039BA0->unk_70 & 0x80) == 0) {
        TaskPoolUpdate(gUnk_02039BA0->unk_B4);
    }
    TaskPoolUpdate(gUnk_02039BA0->unk_A0);
    TaskPoolUpdate(gUnk_02039BA0->unk_C8);
}

void func_080E0820(void) {
    TaskPoolDraw(gUnk_02039BA0->unk_78);

    if ((gUnk_0203C7AC->unk_00 & 0x1000) == 0) {
        TaskPoolDraw(gUnk_02039BA0->unk_8C);
    }

    if ((gUnk_02039BA0->unk_70 & 0x100) == 0) {
        TaskPoolDraw(gUnk_02039BA0->unk_B4);
    }
    TaskPoolDraw(gUnk_02039BA0->unk_A0);
    TaskPoolDraw(gUnk_02039BA0->unk_C8);
}

void func_080E0878(void) {
    TaskPoolDestroy(gUnk_02039BA0->unk_78);
    TaskPoolDestroy(gUnk_02039BA0->unk_8C);
    TaskPoolDestroy(gUnk_02039BA0->unk_A0);
    TaskPoolDestroy(gUnk_02039BA0->unk_C8);
    TaskPoolDestroy(gUnk_02039BA0->unk_B4);
    TaskPoolDestroy(gUnk_0203C7AC->unk_30);
}

UnkStruct_080DFB8C* func_080E08BC(s16 x, s16 y) {
    if (y < 0 || y >= gUnk_02034F2A) {
        return 0;
    }

    if (x < 0 || x >= gUnk_02034F28) {
        return 0;
    }
    return &gUnk_02034F1C[gUnk_02034F28 * y + x];
}

void func_080E0900(UnkStruct_080DFB8C* p, s32 a, s32 b) {
    if (p != 0) {
        p->unk_02 = a;
        p->unk_10 = func_080E8668(a);
        p->unk_08 = b;
    }
}

u8 func_080E0920(UnkStruct_080DFF1C* p, u16 a) {
    u16 d = (p->z - p->y) >> 8;

    return d > a * 16;
}

u8 func_080E0938(u8 a) {
    const u8* p = gUnk_0984D32C[a];
    return GetRandom() % p[3];
}

void func_080E0960(UnkStruct_080DFB8C* p, s32 n) {
    if (p != 0) {
        u16* base = gUnk_02034F34->unk_18;
        const u8* q = gUnk_0984D314[n];
        u8 m = GetRandom() % q[3];
        s32 u = ((m & 7) + q[1]) * 4;
        s32 v = (m >> 3) + q[2];
        p->unk_03 = n;
        p->unk_14 = base + (v * 64 + u);
    }
}

void func_080E09B4(UnkStruct_080DFB8C* p, u8 n, u8 v) {
    if (p != 0) {
        const u8* q = gUnk_0984D32C[n];
        u16* base;
        u16 t;

        switch (q[0]) {
        case 1:
            base = gUnk_02034F34->unk_1C;
            break;
        case 0:
        default:
            base = gUnk_02034F34->unk_18;
            break;
        }
        t = ((v & 7) + q[1]) * 4 + ((v >> 3) + q[2]) * 64;

        if (p->unk_00 & 4) {
            t = t + q[3] * 4;
        }

        if (p->unk_00 & 8) {
            t = t + q[3] * 8;
        }
        p->unk_04 = n;
        p->unk_18 = base + t;
    }
}

void func_080E0A38(UnkStruct_080DFB8C* p) {
    if (p->unk_00 & 1) {
        func_080E0960(p, 1);
    } else if (p->unk_00 & 2) {
        func_080E0960(p, 2);
    } else {
        func_080E0960(p, 0);
    }
}

void func_080E0A70(UnkStruct_080DFB8C* p, s32 n) {
    u16* base;
    const u8* t;
    u8 r;
    u16 off;
    u16 step;

    if (p == 0) {
        return;
    }
    if ((p->unk_00 & 0x0C) == 0) {
        p->unk_04 = n;
        return;
    }
    base = gUnk_02034F34->unk_18;
    t = gUnk_0984D32C[n];
    r = GetRandom() % t[3];
    off = (r % 8 + t[1]) * 4 + (r / 8 + t[2]) * 64;

    if (p->unk_00 & 8) {
        step = t[3] * 4;
        off += step;

        if (p->unk_00 & 4) {
            off += step;
        }
    }
    p->unk_04 = n;
    p->unk_18 = base + off;
}
void sub_080E0B00(UnkStruct_080DFB8C* p, s32 n) {
    const u8* t;
    u16* base;
    u16 off;

    if (p == 0) {
        return;
    }
    t = gUnk_0984D32C[n];
    off = t[1] * 4 + t[2] * 64;
    base = gUnk_02034F34->unk_1C;

    switch (n) {
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
        if (p->unk_00 & 8) {
            off += t[3] * 4;
        }
        break;
    case 23:
    case 24:
    case 25:
    case 32:
    case 33:
    case 34:
        if (p->unk_00 & 4) {
            off += t[3] * 4;
        }
        break;
    }
    p->unk_04 = n;
    p->unk_18 = base + off;
}

void func_080E0B98(UnkStruct_080DFB8C* p, s32 n, u8 v) {
    if (p != 0) {
        u16* base = gUnk_02034F34->unk_1C;
        const u8* q = gUnk_0984D32C[n];
        s32 t;

        if (v == 0xFF) {
            v = GetRandom() % q[3];
        }
        t = ((v & 7) + q[1]) * 4 + ((v >> 3) + q[2]) * 64;
        p->unk_04 = n;
        p->unk_18 = base + t;
    }
}

void func_080E0BF4(s16 x, s16 y, s32 a, s32 b) {
    UnkStruct_080DFB8C* p = func_080E08BC(x, y);

    func_080E0960(p, a);
    sub_080E0B00(p, b);
}

INCLUDE_ASM("map/func_080E0C1C.s");
s16 func_080E1194(u8 a, u8 b, s16 c) {
    switch (a) {
    case 2:
    case 6:
        if (b == 6) {
            c++;
        }
        break;
    case 4:
        if (b != 6) {
            c--;
        }
        break;
    case 1:
    case 3:
        if (b == 3) {
            c--;
        }
        break;
    case 5:
        if (b != 3) {
            c++;
        }
        break;
    }
    return c;
}
INCLUDE_ASM("map/func_080E1204.s");

void func_080E1C64(s16 x, s16 y, u8 n) {
    UnkStruct_080DFB8C* p = func_080E08BC(x, y);
    if (p != 0) {
        u16* base = gUnk_02034F34->unk_20;
        const u8* q = gUnk_0984D3F8[n];
        s32 t = q[1] * 4 + q[2] * 64;
        p->unk_05 = n;
        p->unk_1C = base + t;
    }
}

s32 func_080E1CA8(s16 x, s16 y) {
    UnkStruct_080DFB8C* p = func_080E08BC(x, y);
    if (p == 0 || p->unk_08 == -0x100000 || p->unk_0C == 0x100000) {
        return 1;
    }
    return 0;
}

u8 func_080E1CE0(s16 x, s16 y, u8 n) {
    UnkStruct_080DFB8C* p = func_080E08BC(x, y);

    if (p != 0 && p->unk_02 == n) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("map/func_080E1D08.s");
INCLUDE_ASM("map/func_080E2668.s");
s32 func_080E2B08(void) {
    s32 r = 5;
    UnkStruct_02034F20* p = &gUnk_02034F20[11];

    while (p->unk_04 == 0x100000) {
        p--;
    }

    switch (gUnk_0203C7AC->unk_00 & 0x6000000) {
    case 0x2000000:
        r = 1;
        break;
    case 0x4000000:
        r = 2;
        break;
    case 0x6000000:
        if (p->unk_02 == gUnk_02034F28) {
            r = 2;
        } else if (p->unk_00 == 0) {
            r = 1;
        } else {
            s32 v = GetRandom() % 2 ? 2 : 1;

            r = v;
        }
        break;
    }

    if (r != 5) {
        func_080E2668(p, r);
    }
    return r;
}

u8 func_080E2BA0(u8 a) {
    UnkStruct_02034F20* p = gUnk_02034F20;

    switch (gUnk_0203C7AC->unk_00 & 0x9000000) {
    case 0x1000000:
        a = 0;
        break;
    case 0x8000000:
        a = 3;
        break;
    case 0x9000000:
        break;
    default:
        a = 5;
        break;
    }

    if (a != 5) {
        func_080E2668(p, a);
    }
    return a;
}

void func_080E2BF8(u8 a) {
    UnkStruct_02034F20* p = gUnk_02034F20;
    while (p->unk_02 != gUnk_02034F28) {
        p++;
    }
    func_080E2668(p, a);
}

void func_080E2C2C(u8 a) {
    UnkStruct_02034F20* p = gUnk_02034F20;

    while (p->unk_00 != 0) {
        p++;
    }
    func_080E2668(p, a);
}

INCLUDE_ASM("map/func_080E2C50.s");

s32 func_080E2E24(s16 a, s16 b, s16 c) {
    s32 ret;

    if (c - a < b - c) {
        if (GetRandom() % 3 != 0) {
            ret = 4;
        } else {
            ret = GetRandom() % 5 != 0 ? 2 : 6;
        }
    } else {
        if (GetRandom() % 3 != 0) {
            ret = 6;
        } else {
            ret = GetRandom() % 5 != 0 ? 2 : 4;
        }
    }
    return ret;
}

s32 func_080E2E9C(s16 a, s16 b, s16 c) {
    s32 ret;

    if (c - a < b - c) {
        if (GetRandom() % 3 != 0) {
            ret = 5;
        } else {
            ret = GetRandom() % 5 != 0 ? 1 : 3;
        }
    } else {
        if (GetRandom() % 3 != 0) {
            ret = 3;
        } else {
            ret = GetRandom() % 5 != 0 ? 1 : 5;
        }
    }
    return ret;
}

s32 func_080E2F14(s16 x, s16 y) {
    switch (func_080E08BC(x, y)->unk_02) {
    case 6:
        return 5;
    case 2:
        return 1;
    case 4:
        return 3;
    }
    return 0xB;
}

s32 func_080E2F48(s16 a, s16 b, s16 c, u8 d) {
    if (d != 0) {
        if (c - a < b - c) {
            return 4;
        }
        return 6;
    }

    if (c - a < b - c) {
        return 5;
    }
    return 3;
}

s32 func_080E2F98(s16 a, s16 b, s16 c, u8 d) {
    if (d != 0) {
        if (c - a < (b - a) / 3) {
            return 4;
        }

        if (b - c > (b - a) / 3) {
            return 2;
        }
        return 6;
    }

    if (c - a < (b - a) / 3) {
        return 5;
    }

    if (b - c > (b - a) / 3) {
        return 1;
    }
    return 3;
}

s32 func_080E300C(u8 d, s16 x, s16 y) {
    s32 i;

    if (d != 0) {
        for (i = y; i >= 0; i--) {
            switch (func_080E08BC(x, i)->unk_02) {
            case 3:
                return 4;
            case 5:
                return 6;
            case 1:
                return 2;
            }
        }
    }
    return 0xB;
}

void func_080E3060(u8 i, s16 a, s16 b, s16 c) {
    if (gUnk_02034F20[i].unk_04 == 0x100000) {
        gUnk_02034F20[i].unk_00 = a;
        gUnk_02034F20[i].unk_02 = b;
        gUnk_02034F20[i].unk_04 = c << 12;
    }
}

INCLUDE_ASM("map/func_080E309C.s");
INCLUDE_ASM("map/func_080E3400.s");
INCLUDE_ASM("map/func_080E3768.s");
INCLUDE_ASM("map/func_080E3C1C.s");
#ifdef NON_MATCHING
void func_080E3CD4(s32 a, s16* px, s16* py, s16* pz, s16 e, s16 f) {
    s32 i;
    s32 j;
    s32 x;
    u16 n;
    UnkStruct_080DFB8C* q;

    n = f - e;
    x = e + GetRandom() % (f - e);

    for (i = 0; i < n; i++) {
        for (j = gUnk_02034F2A - 1; j >= 0; j--) {
            q = func_080E08BC(x, j);

            if (q->unk_02 == a) {
                *px = x;
                *py = j;
                *pz = (q->unk_08 >> 8) / 16;
                return;
            }
            if (q->unk_02 != 11) {
                break;
            }
        }
        x = x > e ? x - 1 : f - 1;
    }
}
#else
INCLUDE_ASM("map/func_080E3CD4.s");
#endif
INCLUDE_ASM("map/func_080E3D80.s");
INCLUDE_ASM("map/func_080E3EFC.s");
INCLUDE_ASM("map/func_080E3FD4.s");
INCLUDE_ASM("map/func_080E4244.s");
INCLUDE_ASM("map/func_080E47E8.s");
INCLUDE_ASM("map/func_080E4900.s");
INCLUDE_ASM("map/func_080E4B78.s");
INCLUDE_ASM("map/func_080E4D68.s");
INCLUDE_ASM("map/func_080E4EB0.s");

void func_080E4FF0(void* p, s16 a, s16 b) {
    void* q = (u8*)p + 0x40;
    void* r = (u8*)p + 0x80;

    func_080E4EB0(p, q, r, a, b);
    func_080045AC(p, GetBgScreenBase(3), a, b, 1);
    func_080045AC(q, GetBgScreenBase(2), a, b, 1);
    func_080045AC(r, GetBgScreenBase(1), a, b, 1);
}

INCLUDE_ASM("map/func_080E507C.s");

void func_080E51C0(void* p, s16 a, s16 b) {
    void* q = (u8*)p + 0x40;
    void* r = (u8*)p + 0x80;

    func_080E507C(p, q, r, a, b);
    func_080045AC(p, GetBgScreenBase(3), a, b, 0);
    func_080045AC(q, GetBgScreenBase(2), a, b, 0);
    func_080045AC(r, GetBgScreenBase(1), a, b, 0);
}

INCLUDE_ASM("map/func_080E524C.s");
INCLUDE_ASM("map/func_080E5354.s");

UnkStruct_080DFB8C* func_080E548C(s16 a, s16 b) {
    return func_080E08BC(a, b);
}

UnkStruct_02034F20* func_080E54A0(u8 a) {
    return &gUnk_02034F20[a];
}

u8* func_080E54B8(u8 a) {
    if (gGameState.flags & 8) {
        return (u8*)(gUnk_09EF70D0[gUnk_0203C590.unk_04]->unk_34 + a);
    }
    return (u8*)(gUnk_09EF70D0[gUnk_0203C590.unk_04]->unk_30 + a);
}

void* func_080E5504(void) {
    return gUnk_02034F30;
}

void func_080E5510(u8 a) {
    if (a != 0x10) {
        gUnk_0203C7B0 = gUnk_0984D1F4[a];
    } else {
        gUnk_0203C7B0 = gUnk_0984D1F4[GetRandom() % 15];
    }
}

u16 func_080E5564(void) {
    return gUnk_0203C7B0.unk_01 + GetRandom() % (gUnk_0203C7B0.unk_02 - gUnk_0203C7B0.unk_01 + 1);
}

UnkStruct_02034F24* func_080E5590(u8 a) {
    return &gUnk_02034F24[a];
}

s32 func_080E55A4(s16 x, s16 y) {
    if (y < 0 || y >= gUnk_0203C7AC->unk_06 || x < 0 || x >= gUnk_0203C7AC->unk_04) {
        return 0;
    }
    return (s32)(gUnk_02034F38 + (gUnk_0203C7AC->unk_04 * y + x) * 32);
}

INCLUDE_ASM("map/func_080E55E4.s");
INCLUDE_ASM("map/func_080E56B4.s");
INCLUDE_ASM("map/func_080E5800.s");

s32 func_080E58F8(s16 a, s16 b) {
    return func_080E55A4(a, b);
}

void func_080E590C(UnkStruct_080E5B90* p) {
    UnkStruct_080DFF1C* q = &p->unk_08;
    s32 t;

    func_080E5354(q, &q->x);
    q->y = 0;
    t = func_080DFF30(q);
    q->z = t;
    q->x -= t;
    q->y = t;
}

void func_080E5938(UnkStruct_080E5B90* p) {
    UnkStruct_080DFF1C* q = &p->unk_08;
    s32 t;

    func_080E5354(q, &q->x);
    q->y = 0;
    t = func_080DFF30(q);
    q->z = t;
    q->x -= t;
    q->y = -0xA000;
}

s32 func_080E5968(UnkStruct_080E5B90* p) {
    UnkStruct_080DFF1C* q = &p->unk_08;
    s32 t;
    s32 i;

    if (func_080E524C(q, &q->x) != 0) {
        q->y = 0;
        t = func_080DFF30(q);
        q->z = t;
        q->y = t;
        q->x -= t;

        for (i = 0; i < gUnk_02034F40; i++) {
            if (gUnk_02034F48[i].unk_00 >> 8 == q->unk_00 >> 8 && gUnk_02034F48[i].x >> 8 == q->x >> 8) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

INCLUDE_ASM("map/func_080E59D8.s");
INCLUDE_ASM("map/func_080E5AC8.s");
void func_080E5B90(UnkStruct_080E5B90* p, UnkStruct_0984BC9C* q) {
    if (q->unk_14 & 4) {
        func_080E5968(p);
    } else if (q->unk_14 & 2) {
        func_080E5938(p);
    } else {
        func_080E590C(p);
    }
    switch (GetRandom() % 4) {
    case 0:
        p->unk_18 = 0xAD;
        break;
    case 1:
        p->unk_18 = 0x53;
        break;
    case 2:
        p->unk_18 = 0xD3;
        break;
    default:
        p->unk_18 = 0x2D;
        break;
    }
    p->unk_1C = 0;
    p->unk_00 = q;
    p->unk_04 = 0;
}
void func_080E5C00(UnkStruct_080E5B90* w, u8 a, u8 b) {
    const u8* t;
    UnkStruct_080DEE18* e;
    UnkStruct_0984BC9C* d;
    u8 ok;

    t = gUnk_0984D134[gUnk_0203C7AC->unk_0D];
    e = func_080DEE18(gUnk_0203C590.unk_06);

    if (gUnk_02034F40 >= t[1]) {
        return;
    }
    if (e->unk_0B - gUnk_02034F40 <= 0) {
        return;
    }
    d = gUnk_09EF83F8[a];

    switch (b) {
    case 2:
        ok = func_080E59D8(w);
        break;
    case 3:
        ok = func_080E5AC8(w);
        break;
    case 0:
    default:
        ok = func_080E5968(w);
        w->unk_18 = GetAngle(w->unk_08.unk_00, w->unk_08.x, gUnk_02039BA0->unk_18, gUnk_02039BA0->unk_1C);
        break;
    }
    if (ok) {
        gUnk_02034F48[gUnk_02034F40] = w->unk_08;
        w->unk_1C = 0;
        w->unk_00 = d;
        w->unk_04 = 0;
        TaskCreate(gUnk_02039BA0->unk_B4, d->unk_10, w);
    }
}
void func_080E5CD4(UnkStruct_080E590C* p) {
    switch (gUnk_0203C7AC->unk_0D) {
    case 4:
        p->unk_04 |= 8;
        break;
    case 5:
        p->unk_04 |= 0x20;
        p->unk_04 |= 2;
        break;
    case 18:
        p->unk_04 |= 0x10;
        break;
    case 20:
        p->unk_04 |= 0x100;
        break;
    case 21:
        p->unk_04 |= 0x200;
        break;
    }
}
void func_080E5D6C(UnkStruct_080E590C* p, u8 n, u16 a) {
    UnkStruct_0984BB9C* q = p->unk_00->unk_00;

    switch (p->unk_1C >> 6) {
    case 0:
        q += n * 2;
        p->unk_04 |= 1;
        break;
    case 1:
        q += n * 2 + 1;
        p->unk_04 |= 1;
        break;
    case 2:
        q += n * 2 + 1;
        p->unk_04 &= ~1;
        break;
    default:
        q += n * 2;
        p->unk_04 &= ~1;
        break;
    }
    func_08005974(p->unk_A4, q->unk_0C, a, q->unk_04, q->unk_00);
    func_08002A10(p->tiles, q->unk_08);
}

void func_080E5DEC(UnkStruct_080E590C* p) {
    if (gUnk_02039BA0->unk_70 & 0x10000) {
        if (func_08005AC4(p->unk_A4)) {
            return;
        }
    } else {
        if (func_08005AC4(p->unk_A4)) {
            gUnk_02039BA0->unk_70 |= 0x10000;
        }
    }
    p->gfx = AnimUpdate(p->unk_A4);
}

u8 func_080E5E44(void) {
    const u8* q = gUnk_0984D134[gUnk_0203C7AC->unk_0D];
    u8 v = q[3] + GetRandom() % (q[4] - q[3] + 1);

    if (gGameState.flags & 8) {
        return v + gUnk_09EF6A42[gUnk_0203C590.unk_04];
    }
    return v + gUnk_09EF6A34[gUnk_0203C590.unk_04];
}

void func_080E5EAC(UnkStruct_080E590C* p) {
    gGameState.flags |= 2;
    func_08012614(p->unk_48, 1);
    gUnk_0203C7AC->unk_00 |= 2;
    gUnk_02039BA0->unk_70 |= 0x80;
    p->unk_04 |= 4;
    if (p->unk_04 & 0x40) {
        gGameState.flags |= 4;
    }
    if (p->unk_04 & 0x100) {
        gUnk_0203C7AC->unk_0E = GetRandom() % 3 + 128;
    } else if (p->unk_04 & 0x200) {
        gUnk_0203C7AC->unk_0E = GetRandom() % 3 + 131;
    } else {
        gUnk_0203C7AC->unk_0E = func_080E5E44();
    }
}

void func_080E5F50(UnkStruct_080E590C* p) {
    if (p->unk_74 != 0) {
        if ((gUnk_0203C7AC->unk_00 & 4) == 0 && func_08012660(p->unk_48, 1)) {
            func_080E5EAC(p);
            return;
        }

        if (func_08012660(p->unk_48, 6)) {
            p->unk_08.unk_00 += p->unk_80;
            p->unk_08.x += p->unk_84;
        }
    }
}

s32 func_080E5FB4(UnkStruct_080E590C* p) {
    if (func_080E02E0(&p->unk_08, p->unk_C8 / 2, p->unk_CA / 2)) {
        gUnk_0203C7AC->unk_00 |= 0x80;
        gUnk_0203C7AC->unk_00 |= 4;
        TaskCreate(p->unk_E4, &gTaskDescMapSpark, &p->unk_08);

        if (gGameState.flags & 8) {
            m4aSongNumStart(0xE4);
        } else {
            m4aSongNumStart(0x75);
        }
        return 1;
    }
    return 0;
}

void func_080E6034(UnkStruct_080E590C* p) {
    UnkStruct_080E6034* q = ListPoolFirstFree(gGameState.unk_E8);

    if (q != 0) {
        q->unk_30 = p->unk_00;
        q->unk_34 = p->unk_CC;
        q->unk_00 = p->unk_08;
        q->unk_10 = p->unk_1C;
        q->unk_14 = p->unk_18;
        ListPoolActivate(q->unk_1C, gGameState.unk_E8);
    }
}
void func_080E607C(void) {
    UnkStruct_080E6034* q;
    UnkStruct_080E5B90 w;
    UnkStruct_0984BC9C* d;
    s32 i;

    q = ListPoolFirst(gGameState.unk_E8);
    while (q != 0) {
        d = q->unk_30;
        w.unk_00 = d;
        w.unk_04 = q->unk_34;
        w.unk_08 = q->unk_00;
        w.unk_18 = q->unk_10;
        w.unk_1C = q->unk_14;
        TaskCreate(gUnk_02039BA0->unk_B4, d->unk_10, &w);
        q = ListPoolNext(q->unk_1C);
    }
    ListPoolInit(gGameState.unk_E8);

    for (i = 0; i < 3; i++) {
        ListPoolAddFree(gGameState.unk_40[i].unk_1C, gGameState.unk_E8, gGameState.unk_40[i].unk_00);
    }
}

void func_080E6100(void) {
    UnkStruct_080E5B90 w;
    s32 i;

    switch (gUnk_0203C7AC->unk_0D) {
    case 3:
        func_080E5C00(&w, 3, 3);
        func_080E5C00(&w, 2, 2);
        break;
    case 5:
        for (i = 0; i < 3; i++) {
            if (gUnk_0203C590.unk_04 == 2) {
                func_080E5C00(&w, 4, 0);
            } else if (GetRandom() % 2) {
                func_080E5C00(&w, 0, 0);
            } else {
                func_080E5C00(&w, 1, 0);
            }
        }
        break;
    }
}

void func_080E6178(void) {
    UnkStruct_080E6034* q;
    UnkStruct_080E5B90 w;
    UnkStruct_0984BC9C* d;
    UnkStruct_080DEE18* e;
    s32 i;

    gUnk_02034F40 = 0;
    gUnk_02034F41 = 0;
    gUnk_02034F42 = 46;

    if (gGameState.unk_00 != 0) {
        q = ListPoolFirst(gGameState.unk_E8);
        while (q != 0) {
            d = q->unk_30;
            w.unk_00 = d;
            w.unk_04 = q->unk_34;
            w.unk_08 = q->unk_00;
            w.unk_18 = q->unk_10;
            w.unk_1C = q->unk_14;
            TaskCreate(gUnk_02039BA0->unk_B4, d->unk_10, &w);
            q = ListPoolNext(q->unk_1C);
        }
        if (gGameState.flags & 2) {
            gGameState.flags &= ~2;
            if ((gGameState.flags & 0x40) == 0) {
                e = func_080DEE18(gUnk_0203C590.unk_06);
                if (e->unk_0B != 0) {
                    e->unk_0B--;
                }
            }
        }
    } else {
        func_080E6100();
    }
    ListPoolInit(gGameState.unk_E8);

    for (i = 0; i < 3; i++) {
        ListPoolAddFree(gGameState.unk_40[i].unk_1C, gGameState.unk_E8, gGameState.unk_40[i].unk_00);
    }
}

void func_080E6264(void) {
    const u8* t;
    UnkStruct_080DEE18* e;
    UnkStruct_0984BC9C* d;
    UnkStruct_080E5B90 w;

    t = gUnk_0984D134[gUnk_0203C7AC->unk_0D];
    gUnk_02039BA0->unk_70 &= ~0x10000;

    if (gUnk_02034F42 != 0) {
        gUnk_02034F42--;
        return;
    }
    e = func_080DEE18(gUnk_0203C590.unk_06);

    if (gUnk_02034F40 >= t[1]) {
        return;
    }
    if (e->unk_0B - gUnk_02034F40 <= 0) {
        return;
    }
    if (gUnk_02039BA0->unk_70 & 0x40280) {
        return;
    }
    if (GetRandom() % 10000 <= 7999) {
        return;
    }
    switch (gUnk_0203C7AC->unk_0D) {
    case 20:
        d = gUnk_09EF83F8[5];
        break;
    case 21:
        d = gUnk_09EF83F8[6];
        break;
    default:
        if (gUnk_0203C590.unk_04 == 2) {
            d = gUnk_09EF83F8[4];
        } else if (GetRandom() % 3) {
            d = gUnk_09EF83F8[0];
        } else {
            d = gUnk_09EF83F8[1];
        }
        break;
    }
    if (gUnk_02034F41 + d->unk_08 > 256) {
        return;
    }
    gUnk_02034F42 = 30;
    func_080E5B90(&w, d);
    TaskCreate(gUnk_02039BA0->unk_B4, d->unk_10, &w);
}
INCLUDE_ASM("map/func_080E6394.s");
void func_080E64D4(UnkStruct_080E590C* p) {
    UnkStruct_080E64D4* q = (UnkStruct_080E64D4*)&p->unk_08;
    u16 flags;
    u16 v;
    s32 k;
    s32 x;
    s32 y;
    s32 z;
    s32 t;

    if (p->gfx == 0) {
        return;
    }

    t = p->unk_04 & 1;
    flags = 0x800;

    if (t) {
        flags = 0x801;
    }

    k = q->unk_00.x >> 8;
    v = -0x1004 - k * 4;
    q->unk_3C = q->unk_00.z;
    q->unk_3A = v + 1;
    z = 0;
    x = (p->unk_08.unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    t = flags;
    y = k + (q->unk_00.y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    DrawSprite(x, y, p->gfx, p->tiles, p->palette, z, t, v);
    TaskPoolDraw(p->unk_E4);
}
void func_080E657C(UnkStruct_080E590C* p) {
    UnkStruct_080E6034* q;

    if (gGameState.unk_00 != 0 && (p->unk_04 & 4) == 0 &&
        ((gUnk_0203C7AC->unk_00 & 2) == 0 || (p->unk_04 & 2))) {
        q = ListPoolFirstFree(gGameState.unk_E8);
        if (q != 0) {
            q->unk_30 = p->unk_00;
            q->unk_34 = p->unk_CC;
            q->unk_00 = p->unk_08;
            q->unk_10 = p->unk_1C;
            q->unk_14 = p->unk_18;
            ListPoolActivate(q->unk_1C, gGameState.unk_E8);
        }
    }
    gUnk_02034F40--;
    gUnk_02034F41 -= p->unk_00->unk_08;
    func_08012304(p->unk_48);
    ReleaseObjTiles(p->tiles);
    ReleaseObjPalette(p->palette);
    TaskPoolDestroy(p->unk_E4);
}
INCLUDE_ASM("map/func_080E6634.s");

UnkStruct_080DFB8C* func_080E67D4(s32 x, s32 y) {
    u16 a = x / 0x2000;
    u16 b = y / 0x1000;
    return func_080E548C(a, b);
}

s32 func_080E6804(s16 x, s16 y) {
    s32 i;
    u8 n;
    s16 cx;
    s16 cy;

    n = 0;

    for (i = 0; i < gUnk_02034F78; i++) {
        cx = (gUnk_0203C7B8[i].unk_04.unk_00 >> 8) / 32;
        cy = ((gUnk_0203C7B8[i].unk_04.x + gUnk_0203C7B8[i].unk_04.y) >> 8) / 16;
        if (cx > x - 9 && cx < x + 9 && cy > y - 11 && cy < y + 11) {
            n++;
            if (n > 2) {
                return 0;
            }
        }
    }
    return 1;
}

u8 func_080E68A4(s16 x, s16 y, u8 n) {
    UnkStruct_080DFB8C* p = func_080E548C(x, y);

    if (p != 0 && p->unk_0C != 0x100000 && p->unk_02 == n && (p->unk_00 & 0x960) == 0) {
        return 1;
    }
    return 0;
}

s32 func_080E68E4(s16 x, s16 y, u8 w, u8 h, u8 n) {
    s32 i;
    s32 j;

    for (i = 0; i < w; i++) {
        for (j = 0; j < h; j++) {
            if (func_080E68A4(x + i, y + j, n) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

s32 func_080E6968(s16 a, s16 b, u8 c) {
    u16 d;
    UnkStruct_080DFB8C* p = func_080E548C(a, b);
    d = (p->unk_0C - p->unk_08) >> 8;
    return d > (c << 4);
}

void func_080E6998(s16 x, s16 y, u8 w, u8 h) {
    s32 i;
    s32 j;

    for (i = 0; i < w; i++) {
        for (j = 0; j < h; j++) {
            func_080E548C(x + i, y + j)->unk_00 |= 0x100;
        }
    }
}

s16 func_080E6A14(s16 x, s16 y) {
    u16 n = gUnk_0203C7AC->unk_06 - y;
    s32 i;

    for (i = 0; i < n; i++) {
        UnkStruct_080DFB8C* p = func_080E548C(x, y + i);
        if (p->unk_00 & 0x100) {
            return 0;
        }

        if (p->unk_02 == 0 || p->unk_02 == 4 || p->unk_02 == 2 || p->unk_02 == 6) {
            return i;
        }
    }
    return 0;
}

s32 func_080E6A80(s16 x, s16 y, u16 n) {
    s32 i;
    u16 h;
    s32 j;
    UnkStruct_080DFB8C* q;
    s32 mask;

    h = gUnk_0203C7AC->unk_06 - y;

    for (j = 0; j < n; j++) {
        for (i = 0; i < h; i++) {
            q = func_080E548C(x + j, y - i);
            if (q->unk_00 & 0x100) {
                return 0;
            }
            if (q->unk_02 < 7 || q->unk_02 > 9) {
                break;
            }
        }
    }
    return 1;
}
INCLUDE_ASM("map/func_080E6B24.s");

u8 func_080E7D64(UnkStruct_080DFF1C* a, u8 b) {
    return gUnk_09EF6A50[b](a);
}

s32 func_080E7D80(void* a) {
    s32 i;

    for (i = 0; i < gUnk_02034F78; i++) {
        if (gUnk_0203C7B8[i].unk_14->unk_00 == a) {
            return 0;
        }
    }
    return 1;
}

s32 func_080E7DB8(u8 flag, void* a) {
    s32 i;

    if (flag != 0) {
        return 1;
    }

    for (i = 0; i < gUnk_02034F78; i++) {
        if (gUnk_0203C7B8[i].unk_14->unk_04 == a) {
            return 0;
        }
    }
    return 1;
}

void func_080E7DF8(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        UnkStruct_02034F20* p = func_080E54A0(i);
        if (p->unk_08 == 0 && p->unk_14 != 0x100000) {
            gUnk_02034F7A += 0x4C;
            gUnk_02034F79++;
            break;
        }
    }
}

INCLUDE_ASM("map/func_080E7E3C.s");

void func_080E7FCC(void) {
    UnkStruct_080DFF1C w;

    if (gUnk_0203C7AC->unk_0D == 6 || gUnk_0203C7AC->unk_0D == 0x17) {
        func_080E7D64(&w, gUnk_0984C1CC.unk_15);
        gUnk_0203C7B8[gUnk_02034F78].unk_00 = 0;
        gUnk_0203C7B8[gUnk_02034F78].unk_14 = &gUnk_0984C1CC;
        gUnk_0203C7B8[gUnk_02034F78].unk_04 = w;
        gUnk_02034F7A += gUnk_0984C1CC.unk_08 >> 5;
        gUnk_02034F79++;
        gUnk_02034F78++;
    }
}

void func_080E8058(void) {
    UnkStruct_080DFF1C w;

    if (gUnk_0203C7AC->unk_0D == 11) {
        func_080E7D64(&w, gUnk_0984C204.unk_15);
        gUnk_0203C7B8[gUnk_02034F78].unk_00 = 0;
        gUnk_0203C7B8[gUnk_02034F78].unk_14 = &gUnk_0984C204;
        gUnk_0203C7B8[gUnk_02034F78].unk_04 = w;
        gUnk_02034F7A += gUnk_0984C204.unk_08 >> 5;
        gUnk_02034F79++;
        gUnk_02034F78++;
    }
}
INCLUDE_ASM("map/func_080E80E0.s");
INCLUDE_ASM("map/func_080E826C.s");

u8 func_080E8374(UnkStruct_080E8374* p) {
    s32 lim = gUnk_02039BA0->unk_1C + gUnk_02039BA0->unk_20 + 0x4000 + (p->unk_1A << 8);

    if (p->unk_00 < gUnk_02039BA0->unk_00 || p->unk_00 > gUnk_02039BA0->unk_00 + 0xF000 ||
        p->unk_04 + p->unk_08 < gUnk_02039BA0->unk_04 || p->unk_04 + p->unk_08 > lim) {
        return 1;
    }
    return 0;
}

u16 func_080E83C4(void) {
    return 512 - gUnk_02034F7A;
}
INCLUDE_ASM("map/func_080E83DC.s");

void func_080E84DC(UnkStruct_080DFF1C* p) {
    u16 r = GetRandom() % 10000;

    if (r <= 0x5DB) {
        if (func_080E8FB8(0, p->unk_00, p->x, p->y) != 1) {
            func_080E83DC(p->unk_00, p->x, p->y);
        }
    } else if (r <= 0x1D4B) {
        func_080E83DC(p->unk_00, p->x, p->y);
    }
}

void func_080E853C(void) {
    if (gGameState.unk_00 == 0) {
        gUnk_0203C7B8 = EwramAlloc(384);
        gUnk_02034F78 = 0;
        gUnk_02034F79 = 0;
        gUnk_02034F7A = 0;
        func_080E7DF8();
        func_080E7E3C();
        func_080E7FCC();
        func_080E8058();
        func_080E826C();
        func_080E80E0();
    }
    func_080E8594();
}
void func_080E8594(void) {
    s32 i;
    UnkStruct_02034F20* p;
    UnkStruct_080E7D80* d;

    for (i = 0; i < 12; i++) {
        p = func_080E54A0(i);
        if (p->unk_08 == 0 && p->unk_14 != 0x100000) {
            TaskCreate(gUnk_02039BA0->unk_78, gTaskDescMapGmkJump, p);
        }
    }
    for (i = 0; i < gUnk_02034F78; i++) {
        d = gUnk_0203C7B8[i].unk_14;

        if ((gUnk_0203C7B8[i].unk_00 & 1) == 0) {
            TaskCreate(gUnk_02039BA0->unk_78, d->unk_24, &gUnk_0203C7B8[i]);
        }
    }
    TaskCreate(gUnk_02039BA0->unk_78, gTaskDescMapGmkDmy, 0);
}

void func_080E8624(void) {
    if (gGameState.unk_00 == 0) {
        EwramFree(gUnk_0203C7B8);
    }
}

u8* func_080E8644(void* a, u16 b, u16 c) {
    u8* p = a;

    return gUnk_0984B860[p[(u8)(b >> 3) + (u8)(c >> 3) * 4]];
}

void* func_080E8668(u8 a) {
    s32 i;

    switch (a) {
    case 1:
    case 2:
    case 7:
    case 8:
    case 9:
        i = 1;
        break;
    case 3:
        i = 2;
        break;
    case 5:
        i = 3;
        break;
    case 4:
        i = 4;
        break;
    case 6:
        i = 5;
        break;
    default:
        i = 0;
        break;
    }
    return &gUnk_0984B860[i + 10];
}

u8 func_080E86C8(UnkStruct_080DFB8C* p, s32 x, s32 y) {
    u16 cx;
    u16 cy;
    u8 bx;
    u8 by;
    u8* t;

    if (p == 0) {
        return 1;
    }
    cx = (x >> 8) % 32;
    cy = (y >> 8) % 16;
    t = func_080E8644(p->unk_10, cx, cy);
    bx = cx & 7;
    by = cy & 7;
    return (t[by] >> (7 - bx)) & 1;
}

void func_080E8724(s16 x, s16 y, const u8* p, u16* base) {
    s32 i;
    s32 j;
    s32 off;
    u8 v;
    UnkStruct_080DFB8C* q;

    v = GetRandom() % 100;
    while (v >= p[0]) {
        p += 8;
    }
    for (j = 0; j < p[3]; j++) {
        for (i = 0; i < p[4]; i++) {
            switch (p[5]) {
            case 1:
                q = func_080E548C(x + j, y + i + (p[3] - 1 - j));
                break;
            case 2:
                q = func_080E548C(x + j, y + i + j);
                break;
            case 0:
            default:
                q = func_080E548C(x + j, y + i);
                break;
            }
            off = (p[2] + i) * 64 + (p[1] + j) * 4;
            q->unk_04 = 50;
            q->unk_18 = base + off;
        }
    }
}
u8 func_080E87EC(s16 x, s16 y, const UnkStruct_080E87EC* p) {
    UnkStruct_080DFB8C* q;
    s32 v;

    while (p->unk_04 != 0xFF) {
        q = func_080E548C(x + p->unk_00, y + p->unk_02);

        if (q->unk_0C == 0x100000) {
            return 0;
        }
        if (p->unk_04 != 7 && q->unk_03 != p->unk_04) {
            return 0;
        }
        if (q->unk_04 != p->unk_05) {
            return 0;
        }
        v = 0x520;

        if ((q->unk_00 & v) != 0) {
            return 0;
        }
        v = q->unk_00 & 12;
        v = v & ~p->unk_08;

        if (v != p->unk_06) {
            return 0;
        }
        p++;
    }
    return 1;
}
INCLUDE_ASM("map/func_080E8864.s");

void func_080E891C(UnkStruct_080E8864* p) {
    if (p != 0) {
        while (p->unk_00 != 0) {
            func_080E8864(p);
            p++;
        }
    }
}

void func_080E893C(s16 x, s16 y, const u8* p, u16* base) {
    s32 i;
    s32 j;
    s32 off;
    u8 v;
    UnkStruct_080DFB8C* q;

    v = GetRandom() % 100;
    while (v >= p[0]) {
        p += 8;
    }
    for (j = 0; j < p[3]; j++) {
        for (i = 0; i < p[4]; i++) {
            q = func_080E548C(x + j, y + i);
            off = (p[2] + i) * 64 + (p[1] + j) * 4;
            q->unk_05 = 38;
            q->unk_1C = base + off;
        }
    }
}

u8 func_080E89E4(s16 x, s16 y, const u8* p) {
    while (p[0] != 0xFF) {
        if (func_080E548C(p[0] + x, p[1] + y)->unk_05 != p[2]) {
            return 0;
        }
        p += 4;
    }
    return 1;
}

void func_080E8A24(UnkStruct_080E8864* p) {
    s16 i;
    s16 j;
    u16 w;
    u16 h;

    w = gUnk_0203C7AC->unk_04 - p->unk_04 + 1;
    h = gUnk_0203C7AC->unk_06 - p->unk_05 + 1;
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            if (func_080E89E4(i, j, p->unk_00)) {
                if (GetRandom() % 100 < p->unk_06) {
                    func_080E893C(i, j, p->unk_08, p->unk_0C);
                }
            }
        }
    }
}

void func_080E8AC8(UnkStruct_080E8864* p) {
    if (p != 0) {
        while (p->unk_00 != 0) {
            func_080E8A24(p);
            p++;
        }
    }
}

void func_080E8AE8(void) {
    if (gGameState.unk_00 == 0) {
        UnkStruct_09EF70D0* p = gUnk_09EF70D0[gUnk_0203C590.unk_04];

        func_080E891C(p->unk_24);
        func_080E8AC8(p->unk_28);
    }
}

INCLUDE_ASM("map/func_080E8B1C.s");

s32 func_080E8C38(u8 a, u8 b) {
    UnkStruct_080DEDD8* p;

    if ((s32)gUnk_0203C7AC->unk_00 < 0) {
        return 0;
    }
    p = func_080DEDD8(0);
    while (p->unk_00 != 5) {
        if (p->unk_01 != 0xFF && p->unk_02 == a && p->unk_03 == b) {
            return 1;
        }
        p++;
    }
    return 0;
}

s32 func_080E8C84(u8 a, u8 b) {
    UnkStruct_080DEDD8* p;
    u8 i;

    if ((s32)gUnk_0203C7AC->unk_00 < 0) {
        return 0;
    }
    i = 0;
    p = func_080DEDD8(0);
    while (p->unk_00 != 5) {
        if (p->unk_01 != 0xFF && p->unk_02 == a && p->unk_03 == b) {
            gUnk_02034F7C = &gUnk_0984CECC[p->unk_01];
            gUnk_02034F84 = &gUnk_0203C598[i];
            return 1;
        }
        i++;
        p++;
    }
    return 0;
}

u8 func_080E8D00(void) {
    return gUnk_02034F7C->unk_00 - gUnk_02034F84->unk_00;
}

UnkStruct_02034F80* func_080E8D1C(u8 a) {
    UnkStruct_02034F80* p = &gUnk_02034F7C->unk_04[gUnk_02034F84->unk_00];
    UnkStruct_02034F80* q = &p[a];

    gUnk_02034F80 = *q;

    if (a == 0 && q->unk_02 == 4 && gUnk_02034F84->unk_01 != 0) {
        gUnk_02034F80.unk_03 = gUnk_02034F84->unk_01;
    }
    return &gUnk_02034F80;
}

INCLUDE_ASM("map/func_080E8D64.s");

s32 func_080E8E24(UnkStruct_080E8E24* p) {
    if (func_080E8D1C(0)->unk_02 == 4) {
        if (gUnk_02034F80.unk_03 > p->unk_02) {
            gUnk_02034F80.unk_03 -= p->unk_02;
            gUnk_02034F84->unk_01 = gUnk_02034F80.unk_03;
            return 0;
        }
        gUnk_02034F84->unk_01 = 0;
    }
    gUnk_02034F84->unk_00++;
    return 1;
}

UnkStruct_080E8E24* func_080E8E74(u8 a) {
    u16 v = GetRandom() % 10000;
    UnkStruct_09EF8370** t = &gUnk_09EF8370[6];
    UnkStruct_080E8E74* p = (UnkStruct_080E8E74*)t[gGameState.world];

    while (p->unk_00 != 41) {
        UnkStruct_080E8E24* q = &gUnk_0985814C[p->unk_00];
        u16 n = a != 0 ? p->unk_04 : p->unk_02;

        if (v < n) {
            if (func_0800FC5C(q->unk_00[0])) {
                return q;
            }
            if (p->unk_00 <= 16) {
                return &gUnk_0985814C[0];
            }
            if (p->unk_00 <= 30) {
                return &gUnk_0985814C[20];
            }
            return &gUnk_0985814C[31];
        }
        v -= n;
        p++;
    }
    return 0;
}

u8 func_080E8F0C(void) {
    u16 acc = 0;
    u16 r = GetRandom() % 10000;
    s32 i;
    const u16* p = gUnk_09858238;

    for (i = 0; i < 10; i++) {
        acc += p[i];
        if (r < acc) {
            return i;
        }
    }
    return 0;
}

s32 func_080E8F50(UnkStruct_080E8E24* a, u8 b, s32 c, s32 d, s32 e) {
    UnkStruct_080E8F50 w;

    w.unk_00 = b;
    w.unk_04 = c;
    w.unk_08 = d;
    w.unk_0C = e;
    w.unk_14 = a->unk_02;
    if (w.unk_14 <= 0x1B8) {
        w.unk_14 += func_080E8F0C();
    }

    if (CountCardsById(w.unk_14) <= 0x62) {
        TaskCreate(gUnk_02039BA0->unk_C8, &gTaskDescMapPrzCard, &w);
        return 1;
    }
    return 0;
}

u8 func_080E8FB8(u8 a, s32 b, s32 c, s32 d) {
    UnkStruct_080E8E24* q;

    if (gGameState.flags & 8) {
        return 0;
    }

    if (func_080840E4()) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_00 & 0x20) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_00 & 0x10) {
        return 0;
    }

    if (func_080DEE18(gUnk_0203C590.unk_06)->unk_0C == 0) {
        return 0;
    }
    q = func_080E8E74(a);
    if (q == 0) {
        return 0;
    }
    return func_080E8F50(q, 0, b, c, d);
}

void func_080E9034(u8 a, u8 b, s32 c, s32 d, s32 e) {
    UnkStruct_080E8F50 w;
    s32 i;

    w.unk_04 = c;
    w.unk_08 = d;
    w.unk_0C = e;
    w.unk_14 = a;

    for (i = 0; i < b; i++) {
        TaskCreate(gUnk_02039BA0->unk_A0, &gTaskDescMapPrize, &w);
    }
}

INCLUDE_ASM("map/func_080E9078.s");

void func_080E92B8(UnkStruct_080E92B8* p) {
    s32 i;
    u32* src;
    u32* dst;

    p->unk_00 = gGameState.world;
    p->unk_01 = gGameState.floor;
    memcpy(p->unk_04, &gUnk_0203C590, 0x21C);
    src = (u32*)gGameState.unk_184.unk_00;
    dst = (u32*)p->unk_220.unk_00;

    for (i = 12; i >= 0; i--) {
        *dst++ = *src++;
    }
}

void func_080E92F8(UnkStruct_080E92B8* p) {
    s32 i;
    u32* src;
    u32* dst;

    gGameState.world = p->unk_00;
    gGameState.floor = p->unk_01;
    memcpy(&gUnk_0203C590, p->unk_04, 0x21C);
    src = (u32*)p->unk_220.unk_00;
    dst = (u32*)gGameState.unk_184.unk_00;

    for (i = 12; i >= 0; i--) {
        *dst++ = *src++;
    }
}

void func_080E9338(s32 a) {
    gUnk_02034F88 = a;
}

void func_080E9344(s32 a) {
    func_080E9338(a);
    ((void (*)(void))gUnk_02034F88)();
}

void func_080E935C(void) {
    s32 y = 0;
    s32 x = 0;
    u16 m1 = 0x200;
    u16 m2 = 0x1000;

    if (GetKeysHeld() & 0x20) {
        x = -1024;
    }
    if (GetKeysHeld() & 0x10) {
        x = 1024;
    }
    if (GetKeysHeld() & 0x40) {
        y = -1024;
    }
    if (GetKeysHeld() & 0x80) {
        y = 1024;
    }
    func_080E02A8(x, y);
    if (GetKeysPressed() & 1) {
        gDispCnt = (gDispCnt & 0xFDFF) | (m1 & ~gDispCnt);
    }
    if (GetKeysPressed() & 2) {
        gDispCnt = (gDispCnt & 0xEFFF) | (m2 & ~gDispCnt);
    }
}
void func_080E93FC(void) {
    if (gUnk_0203C7AC->unk_00 & 2) {
        gUnk_0203C7AC->unk_00 &= ~2;
        gUnk_0203C7AC->unk_00 &= ~4;
        gUnk_0203C7AC->unk_00 &= ~0x80;
    }
    if (gUnk_02039BA0->unk_70 & 0x10) {
        func_08006184(0, 16);
        func_080E9344((s32)func_080E9508);
        return;
    }
    if (gUnk_0203C7AC->unk_00 & 0x2000) {
        func_08000DE8(gUnk_02039BA0->unk_78, gUnk_02034FA8);
        gUnk_02034FA8 = 0;
        func_080E9344((s32)func_080E95E8);
        return;
    }
    if (gUnk_02039BA0->unk_70 & 0x40000) {
        func_08000DE8(gUnk_02039BA0->unk_78, gUnk_02034FA8);
        gUnk_02034FA8 = 0;
        func_080E9344((s32)func_080E963C);
        return;
    }
    if (gUnk_02034FA4 != 0) {
        func_080E9344((s32)func_080E95C4);
        return;
    }
    func_080E0780();
    func_080E0820();
    func_080125A4();
    func_080E6264();
    if ((GetKeysHeld() & 0x300) == 0x300) {
        return;
    }
    if (GetKeysPressed() & 8) {
        func_080E9338((s32)func_080E9550);
    }
    if (GetKeysPressed() & 4) {
        ModeRequest(&gModeMapChk, 0);
    }
}
void func_080E9508(void) {
    func_080E0820();
    if (func_08006314() == 0) {
        func_080DF730(gUnk_0203C7AC->unk_0F, gUnk_0203C7AC->unk_10);
        if (gUnk_0203C7AC->unk_0F != 0xFD && gUnk_0203C7AC->unk_0F != 0xFE) {
            ModeRequest(&gModeMapDbg, 0);
        } else {
            func_080E04EC();
        }
    }
}
void func_080E9550(void) {
    if (gUnk_02034FA4 != 0) {
        func_080E9344((s32)func_080E95C4);
        return;
    }
    func_080E935C();
    TaskPoolUpdate(gUnk_02039BA0->unk_78);
    func_080E0820();
    if ((GetKeysHeld() & 0x300) == 0x300) {
        return;
    }
    if (GetKeysPressed() & 8) {
        func_080E9338((s32)func_080E93FC);
    }
    if (GetKeysPressed() & 4) {
        ModeRequest(&gModeMapChk, 0);
    }
}
void func_080E95C4(void) {
    func_080E0820();
    if (gUnk_02034FA4 == 0) {
        ModeRequest(&gModeMapDbg, 0);
    }
}
void func_080E95E8(void) {
    if ((gUnk_02039BA0->unk_70 & 0x2000) == 0 && (gUnk_0203C7AC->unk_00 & 0x2000) == 0) {
        gUnk_02034FA8 = func_080D3A20(gUnk_02039BA0->unk_78);
        func_080E8594();
        func_080E9344((s32)func_080E93FC);
    } else {
        func_080E0780();
        func_080E0820();
    }
}
void func_080E963C(void) {
    if (gUnk_02039BA0->unk_70 & 0x10) {
        func_08006184(0, 16);
        func_080E9344((s32)func_080E9508);
    } else if ((gUnk_02039BA0->unk_70 & 0x40000) == 0) {
        gBldCnt = 0;
        SetBgPriority(0, 0);
        gUnk_02034FA8 = func_080D3A20(gUnk_02039BA0->unk_78);
        func_080E8594();
        func_080E607C();
        func_080E9344((s32)func_080E93FC);
    } else {
        func_080E0780();
        func_080E0820();
    }
}
void Mode_MapDbg_0(void) {
    UnkStruct_09EF70D0* p;

    gUnk_02039BA0 = EwramAlloc(0xE8);
    gUnk_0203C7AC = EwramAlloc(0x44);
    func_080DEF20();
    SetBgMode0();
    SetupBg(3, 0, 28, 0);
    SetupBg(2, 0, 29, 0);
    SetupBg(1, 2, 30, 0);
    SetupBg(0, 3, 31, 14);
    SetBgPriority(3, 3);
    SetBgPriority(2, 3);
    SetBgPriority(1, 1);
    SetBgPriority(0, 0);
    SetBackdropColor(6, 31, 31);
    SetBlendAlpha(6, 10);
    func_080E0558();
    func_0801227C();
    func_080E05E4();
    func_080E853C();
    func_080E6178();
    func_080E8AE8();
    func_080E062C();

    p = gUnk_09EF70D0[gUnk_0203C590.unk_04];
    TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescLockon, 0);
    TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapAnm, p->unk_2C);
    gUnk_02034FA8 = func_080D3A20(gUnk_02039BA0->unk_78);
    func_080E9338((s32)func_080E93FC);

    if (gGameState.unk_00 != 0) {
        func_080E0298(gGameState.unk_14, gGameState.unk_18 + gGameState.unk_1C);
    } else {
        func_080E0298(gUnk_02039BA0->unk_DC, gUnk_02039BA0->unk_E0);
    }

    func_080E0078();
    func_0801CB00();
    SeedRandom(gFrameCounter);
    m4aSongNumStartOrContinue(p->unk_38);
    TaskPoolInit(gUnk_02034F90, 1);
    TaskCreate(gUnk_02034F90, &gTaskDescMapDbg, &gUnk_02034FA4);
    TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapDmg, 0);
    func_08006120(0, 16);
}
void Mode_MapDbg_1(void) {
    TaskPoolUpdate(gUnk_02034F90);
    TaskPoolDraw(gUnk_02034F90);
    ((void (*)(void))gUnk_02034F88)();
    UpdatePlayTime();
}
void Mode_MapDbg_2(void) {
    func_080E0878();
    func_080E8624();
    EwramFree(gUnk_02039BA0);
    EwramFree(gUnk_0203C7AC);
    TaskPoolDestroy(gUnk_02034F90);
}

void func_080E988C(s32 a) {
    gUnk_02034FB0 = a;
}

void func_080E9898(s32 a) {
    func_080E988C(a);
    ((void (*)(void))gUnk_02034FB0)();
}

void func_080E98B0(void) {
    switch (gUnk_0203C590.unk_04) {
    case 2:
        gUnk_02034FB4 = TaskCreate(gUnk_0203C7AC->unk_30, &gTaskDescWLogo, (void*)2);
        break;
    case 6:
        gUnk_02034FB4 = TaskCreate(gUnk_0203C7AC->unk_30, &gTaskDescWLogo, (void*)6);
        break;
    case 5:
        gUnk_02034FB4 = TaskCreate(gUnk_0203C7AC->unk_30, &gTaskDescWLogo, (void*)5);
        break;
    case 7:
        gUnk_02034FB4 = TaskCreate(gUnk_0203C7AC->unk_30, &gTaskDescWLogo, (void*)7);
        break;
    case 3:
        gUnk_02034FB4 = TaskCreate(gUnk_0203C7AC->unk_30, &gTaskDescWLogo, (void*)3);
        break;
    case 8:
        gUnk_02034FB4 = TaskCreate(gUnk_0203C7AC->unk_30, &gTaskDescWLogo, (void*)8);
        break;
    case 9:
        gUnk_02034FB4 = TaskCreate(gUnk_0203C7AC->unk_30, &gTaskDescWLogo, (void*)9);
        break;
    case 1:
        gUnk_02034FB4 = TaskCreate(gUnk_0203C7AC->unk_30, &gTaskDescWLogo, (void*)1);
        break;
    case 10:
        gUnk_02034FB4 = TaskCreate(gUnk_0203C7AC->unk_30, &gTaskDescWLogo, (void*)10);
        break;
    case 11:
        gUnk_02034FB4 = TaskCreate(gUnk_0203C7AC->unk_30, &gTaskDescWLogo, (void*)11);
        break;
    case 12:
        gUnk_02034FB4 = TaskCreate(gUnk_0203C7AC->unk_30, &gTaskDescWLogo, (void*)12);
        break;
    default:
        gUnk_02034FB4 = TaskCreate(gUnk_0203C7AC->unk_30, &gTaskDescWLogo, (void*)4);
        break;
    }
}

void func_080E9A00(void) {
    if (gUnk_02034FB8 != 0) {
        func_08000DE8(gUnk_02039BA0->unk_78, gUnk_02034FB8);
        gUnk_02034FB8 = 0;
    }
}

void func_080E9A28(void) {
    switch (gGameState.world) {
    case 10:
        ModeRequest(&gModeBattle, 0x94);
        break;
    case 1:
        ModeRequest(&gModeBattle, 0x95);
        break;
    case 5:
        ModeRequest(&gModeBattle, 0x98);
        break;
    case 7:
        ModeRequest(&gModeBattle, 0x9E);
        break;
    case 6:
        ModeRequest(&gModeBattle, 0x9B);
        break;
    case 2:
        ModeRequest(&gModeBattle, 0x97);
        break;
    case 4:
        ModeRequest(&gModeBattle, 0x96);
        break;
    case 3:
        ModeRequest(&gModeBattle, 0xA0);
        break;
    }
}
void func_080E9AF0(void) {
    u8 r = IsTaskActive(gUnk_02034FB4);

    if (r != 0) {
        TaskPoolUpdate(gUnk_0203C7AC->unk_30);
        TaskPoolDraw(gUnk_0203C7AC->unk_30);
        TaskPoolUpdate(gUnk_02039BA0->unk_78);
        func_080E0820();
    } else {
        u16 t = gUnk_0203C590.unk_02 | 0x10;
        gUnk_0203C590.unk_02 = t;
        gUnk_02034FB4 = 0;
        gUnk_02034FB8 = func_080D3A20(gUnk_02039BA0->unk_78);
        gUnk_02039BA0->unk_70 &= ~0x200;
        gUnk_02039BA0->unk_70 &= ~1;
        func_080E9898((s32)func_080E9B7C);
    }
}
void func_080E9B7C(void) {
    if (gUnk_0203C7AC->unk_00 & 2) {
        func_08006184(0, 16);
        func_080063A8();
        func_080E9898((s32)func_080E9D94);
        return;
    }
    if (gUnk_02039BA0->unk_70 & 0x10) {
        func_08006184(0, 16);
        func_080063A8();
        func_080E9898((s32)func_080E9CBC);
        return;
    }
    if (func_08006314() == 0 && (gGameState.unk_17A & 0x200) != 0 &&
        (gUnk_02039BA0->unk_70 & 0x41000) == 0 && (gUnk_0203C7AC->unk_00 & 4) == 0) {
        if (GetKeysPressed() & 4) {
            m4aSongNumStart(0x67);
            func_08006184(0, 16);
            func_080063A8();
            func_080E9898((s32)func_080E9E04);
            return;
        }
        if (GetKeysPressed() & 8) {
            func_080E9A00();
            TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapMenu, 0);
            func_080E9898((s32)func_080E9E28);
            return;
        }
    }
    if (gUnk_0203C7AC->unk_00 & 0x2000) {
        func_080E9A00();
        func_080E9898((s32)func_080E9E28);
        return;
    }
    if (gUnk_02039BA0->unk_70 & 0x40000) {
        func_080E9A00();
        func_080E9898((s32)func_080E9E94);
        return;
    }
    func_080E0780();
    func_080E0820();
    func_080125A4();
    func_080E6264();
}
void func_080E9CBC(void) {
    u8 r;
    u8* e;
    UnkStruct_080DEDD8* d;

    func_080E0820();
    r = func_08006314();
    if (r != 0) {
        return;
    }
    if (gUnk_0203C7AC->unk_0F == 0xFE) {
        func_080DF814();
        return;
    }
    if (gUnk_0203C7AC->unk_0F == 0xFD) {
        func_080DF828();
        return;
    }

    e = func_080E54B8(gUnk_0203C590.unk_05);
    if (e[0] == 0xFF) {
        func_080DF730(gUnk_0203C7AC->unk_0F, gUnk_0203C7AC->unk_10);
        ModeRequest(&gModeMapFld, 0);
        return;
    }

    d = func_080DEDD8(e[0]);
    if (d->unk_02 != gUnk_0203C7AC->unk_0F || d->unk_03 != gUnk_0203C7AC->unk_10) {
        func_080DF730(gUnk_0203C7AC->unk_0F, gUnk_0203C7AC->unk_10);
        ModeRequest(&gModeMapFld, 0);
        return;
    }

    gGameState.unk_1B8 = r;

    switch (d->unk_00) {
    case 1:
    case 3:
        if (e[1] == 0x51 && (gGameState.flags & 0x400)) {
            func_0806180C(0x55);
        } else {
            func_0806180C(e[1]);
        }
        break;
    case 2:
        func_080DF730(gUnk_0203C7AC->unk_0F, gUnk_0203C7AC->unk_10);
        ModeRequest(&gModeMapFld, 0);
        break;
    case 4:
        func_080E9A28();
        break;
    }
}
void func_080E9D94(void) {
    func_080E0820();
    if (func_08006314() == 0) {
        func_0801CB0C();
        if (gGameState.flags & 8) {
            if (gGameState.unk_17A & 0x1000) {
                ModeRequest(&gModeBattle, gUnk_0203C7AC->unk_0E);
            } else {
                ModeRequest(&gModeRikuBtlTutorial, gUnk_0203C7AC->unk_0E);
            }
        } else {
            ModeRequest(&gModeBattle, gUnk_0203C7AC->unk_0E);
        }
    }
}
void func_080E9E04(void) {
    func_080E0820();
    if (func_08006314() == 0) {
        func_0801CB0C();
        ModeRequest(&gModeAllmap, 1);
    }
}
void func_080E9E28(void) {
    if ((gUnk_02039BA0->unk_70 & 0x2000) == 0 && (gUnk_0203C7AC->unk_00 & 0x2000) == 0) {
        SetupBg(0, 3, 31, 14);
        SetBgPriority(0, 0);
        func_080E8594();
        gUnk_02034FB8 = func_080D3A20(gUnk_02039BA0->unk_78);
        func_080E9898((s32)func_080E9B7C);
    } else {
        func_080E0780();
        func_080E0820();
    }
}
void func_080E9E94(void) {
    u16 t;

    if (gUnk_02039BA0->unk_70 & 0x10) {
        func_08006184(0, 16);
        func_080063A8();
        func_080E9898((s32)func_080E9CBC);
        if ((gGameState.unk_17A & 0x200) == 0) {
            t = gGameState.unk_17A | 0x200;
            gGameState.unk_17A = t;
        }
    } else if ((gUnk_02039BA0->unk_70 & 0x40000) == 0) {
        gBldCnt = 0;
        SetBgPriority(0, 0);
        func_080E8594();
        func_080E607C();
        gUnk_02034FB8 = func_080D3A20(gUnk_02039BA0->unk_78);
        func_080E9898((s32)func_080E9B7C);
    } else {
        func_080E0780();
        func_080E0820();
    }
}
void func_080E9F30(void) {
    func_080E0820();
    if (gUnk_02034FBC == 0) {
        ModeRequest(&gModeMapFld, 0);
    }
}
void Mode_MapFld_0(void) {
    UnkStruct_09EF70D0* p;
    u16 t;

    if ((gUnk_0203C590.unk_02 & 0x10) && gGameState.unk_00 == 0) {
        switch (gUnk_0203C590.unk_07) {
        case 0:
            gGameState.unk_24 = 0xAD;
            break;
        case 1:
            gGameState.unk_24 = 0x2D;
            break;
        case 2:
            gGameState.unk_24 = 0xD3;
            break;
        case 3:
            gGameState.unk_24 = 0x53;
            break;
        }
        func_080104F4();
    }

    gUnk_02039BA0 = EwramAlloc(0xE8);
    gUnk_0203C7AC = EwramAlloc(0x44);
    gUnk_02034FB4 = 0;
    gUnk_02034FB8 = 0;
    func_080DEF20();
    SetBgMode0();
    SetupBg(3, 0, 28, 0);
    SetupBg(2, 0, 29, 0);
    SetupBg(1, 2, 30, 0);
    SetupBg(0, 3, 31, 14);
    SetBgPriority(3, 3);
    SetBgPriority(2, 3);
    SetBgPriority(1, 1);
    SetBgPriority(0, 0);
    SetBackdropColor(6, 31, 31);
    func_080E0558();
    func_0801227C();
    func_080E05E4();
    func_080E853C();
    func_080E6178();
    func_080E8AE8();
    func_080E062C();

    p = gUnk_09EF70D0[gUnk_0203C590.unk_04];
    TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescLockon, 0);
    TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapAnm, p->unk_2C);

    if ((gGameState.unk_17A & 0x20) == 0) {
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapTutorial, 0);
    }

    if ((gUnk_0203C590.unk_02 & 0x10) == 0) {
        func_080E988C((s32)func_080E9AF0);
        gUnk_02039BA0->unk_70 |= 0x200;
        gUnk_02039BA0->unk_70 |= 1;
        func_080E0298(gUnk_02039BA0->unk_DC, gUnk_02039BA0->unk_E0);
        func_080E98B0();
    } else if (gGameState.unk_00 != 0) {
        func_080E0298(gGameState.unk_14, gGameState.unk_18 + gGameState.unk_1C);
        if ((s8)gGameState.unk_0F != -1) {
            t = gDispCnt & 0xEFFF;
            gDispCnt = t;
            TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapMenu, 0);
            func_080E988C((s32)func_080E9E28);
        } else {
            gUnk_02034FB8 = func_080D3A20(gUnk_02039BA0->unk_78);
            func_080E988C((s32)func_080E9B7C);
        }
    } else {
        gUnk_02034FB8 = func_080D3A20(gUnk_02039BA0->unk_78);
        func_080E0298(gUnk_02039BA0->unk_DC, gUnk_02039BA0->unk_E0);
        func_080E988C((s32)func_080E9B7C);
    }

    func_080E0078();
    func_0801CB00();
    SeedRandom(gFrameCounter);
    m4aSongNumStartOrContinue(p->unk_38);
    func_08006120(0, 16);
}
void Mode_MapFld_1(void) {
    ((void (*)(void))gUnk_02034FB0)();
    UpdatePlayTime();
}
void Mode_MapFld_2(void) {
    func_080E0878();
    func_080E8624();
    EwramFree(gUnk_02039BA0);
    EwramFree(gUnk_0203C7AC);
}

void func_080EA1E8(s32 a) {
    gUnk_02034FD4 = a;
}

void func_080EA1F4(s32 a) {
    func_080EA1E8(a);
    ((void (*)(void))gUnk_02034FD4)();
}

UnkStruct_09EF8370* func_080EA20C(void) {
    if (gGameState.flags & 8) {
        if (gUnk_0203C590.unk_06 == 0xFD) {
            return gUnk_09EF8370[2];
        }
        if (gUnk_0203C590.unk_06 == 0xFE) {
            if ((s8)gGameState.floor != 0) {
                return gUnk_09EF8370[1];
            }
            return gUnk_09EF8370[5];
        }
    }
    if (gUnk_0203C590.unk_06 == 0xFD) {
        if ((s8)gGameState.floor != 12) {
            return gUnk_09EF8370[2];
        }
        return gUnk_09EF8370[3];
    }
    if (gUnk_0203C590.unk_06 == 0xFE) {
        if ((s8)gGameState.floor != 0) {
            return gUnk_09EF8370[1];
        }
        return gUnk_09EF8370[0];
    }
    return gUnk_09EF8370[4];
}
void func_080EA2AC(void) {
    if (gUnk_0203C590.unk_06 == 0xFC) {
        return;
    }
    if (gGameState.flags & 8) {
        switch (gUnk_0203C590.unk_00) {
        case 20:
        case 22:
        case 23:
        case 24:
            TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapMickey, 0);
            break;
        }
        return;
    }
    if (gGameState.unk_17C & 2) {
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapDonald, 0);
    }
    if (gGameState.unk_17C & 1) {
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapGoofy, 0);
    }
    if (gUnk_0203C590.unk_06 != 0xFD) {
        return;
    }
    switch (gUnk_0203C590.unk_00) {
    case 23:
    case 24:
        if ((s8)gGameState.floor == 11) {
            TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapNamine, 0);
            TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapNiseriku, 0);
        }
        break;
    case 25:
    case 26:
        if ((s8)gGameState.floor == 11 && gGameState.unk_184.unk_00[12].unk_03 == 0) {
            TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapNamine, 0);
            TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapNiseriku, 0);
        }
        break;
    case 27:
        if ((s8)gGameState.floor == 12) {
            TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapNamine, 0);
            TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapNiseriku, 0);
        }
        break;
    }
}
u8 func_080EA400(void) {
    if (gUnk_0203C590.unk_02 & 2) {
        return 0xFF;
    }
    if (gGameState.flags & 8) {
        switch (gUnk_0203C590.unk_04) {
        case 8:
#ifdef VERSION_EU
            return 0x95;
#else
            return 0x97;
#endif
        case 9:
#ifdef VERSION_EU
            return 0xAF;
#else
            return 0xB1;
#endif
        case 11:
#ifdef VERSION_EU
            return 0xB8;
#else
            return 0xBA;
#endif
        case 12:
#ifdef VERSION_EU
            return 0xBE;
#else
            return 0xC0;
#endif
        }
        return 0xFF;
    }
    return gUnk_09EF6AB0[gUnk_0203C590.unk_04];
}
u8 func_080EA45C(void) {
    if (gUnk_0203C590.unk_02 & 1) {
        return 0xFF;
    }
    if (gGameState.flags & 8) {
        return gUnk_0984B905[(s8)gGameState.floor];
    }
    return gUnk_0984B8F8[(s8)gGameState.floor];
}
void func_080EA498(void) {
    if (gUnk_0203C7AC->unk_00 & 0x100) {
        func_080EA1F4((s32)func_080EA78C);
        return;
    }
    if (gUnk_0203C7AC->unk_00 & 0xE00) {
        func_08006184(0, 16);
        if (gUnk_0203C590.unk_06 == 0xFE) {
            func_080EA1F4((s32)func_080EA5CC);
            return;
        }
        if (gUnk_0203C590.unk_06 == 0xFD) {
            func_080EA1F4((s32)func_080EA694);
            return;
        }
        func_080EA1F4((s32)func_080EA5A8);
        return;
    }
    if (gUnk_02039BA0->unk_70 & 0x40000) {
        func_080EA1F4((s32)func_080EA7FC);
        return;
    }
    if (gUnk_0203C7AC->unk_00 & 0x2000) {
        func_080EA1F4((s32)func_080EA730);
    } else if (func_08006314() == 0 && (gGameState.unk_17A & 0x200) != 0 &&
               (gUnk_02039BA0->unk_70 & 0x41000) == 0 && (gUnk_0203C7AC->unk_00 & 4) == 0 &&
               (GetKeysPressed() & 8) != 0) {
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapMenu, 0);
        func_080EA1F4((s32)func_080EA730);
    } else {
        func_080E0780();
        func_080E0820();
        func_080125A4();
    }
}
void func_080EA5A8(void) {
    func_080E0820();
    if (func_08006314() == 0) {
        func_080DFA3C();
        ModeRequest(&gModeMapFld, 0);
    }
}
void func_080EA5CC(void) {
    func_080E0820();
    if (func_08006314() != 0) {
        return;
    }
    if (gUnk_0203C7AC->unk_00 & 0x200) {
        if ((s8)gGameState.floor == func_080DF750()) {
            gGameState.flags &= ~0x80;
            gGameState.unk_17C = (gGameState.unk_17C & 0xFF83) | gGameState.unk_17E;
        }
        if (gUnk_0203C590.unk_04 == 0) {
            gUnk_0203C590.unk_07 = 0;
            ModeRequest(&gModeWorldselect, 0);
        } else if (gUnk_0203C590.unk_04 == 13) {
#ifdef VERSION_EU
            func_0806180C(0x85);
#else
            func_0806180C(0x87);
#endif
        } else if (func_080EA400() != 0xFF) {
            gUnk_02034FD8 = 60;
            func_080EA1F4((s32)func_080EA7D8);
        } else {
            func_080DFA3C();
            func_080E04EC();
        }
    } else {
        func_080DFAA8();
        func_080DF9C4();
        func_080E04EC();
    }
}
void func_080EA694(void) {
    u8 v;
    u16 t;

    func_080E0820();
    if (func_08006314() != 0) {
        return;
    }
    if (gUnk_0203C7AC->unk_00 & 0x200) {
        if (gUnk_0203C590.unk_04 != 13) {
            func_080DFA3C();
            ModeRequest(&gModeMapFld, 0);
        } else {
            gUnk_0203C590.unk_07 = 1;
            ModeRequest(&gModePooh, 2);
        }
        return;
    }
    v = func_080EA45C();
    if (v != 0xFF) {
        func_0806180C(v);
        return;
    }
    if ((gUnk_0203C590.unk_02 & 1) == 0) {
        t = gUnk_0203C590.unk_02 | 1;
        gUnk_0203C590.unk_02 = t;
        func_080DF244();
        gUnk_0203C590.unk_00++;
    }
    func_080DFAA8();
    func_080DF9A8();
    func_080E04EC();
}
void func_080EA730(void) {
    if ((gUnk_02039BA0->unk_70 & 0x2000) == 0 && (gUnk_0203C7AC->unk_00 & 0x2000) == 0) {
        SetupBg(0, 3, 31, 14);
        SetBgPriority(0, 0);
        func_080E56B4(func_080EA20C()->unk_2C);
        func_080EA1F4((s32)func_080EA498);
    } else {
        func_080E0780();
        func_080E0820();
    }
}
void func_080EA78C(void) {
    if ((gUnk_0203C7AC->unk_00 & 0x100) == 0) {
        func_08006184(2, 60);
        func_080063A8();
        gUnk_0203C7AC->unk_00 |= 0x200;
        func_080EA1F4((s32)func_080EA5CC);
    } else {
        func_080E0780();
        func_080E0820();
    }
}
void func_080EA7D8(void) {
    if (gUnk_02034FD8 != 0) {
        gUnk_02034FD8--;
    } else {
        func_0806180C(func_080EA400());
    }
}
void func_080EA7FC(void) {
    if (gUnk_02039BA0->unk_70 & 0x10) {
        func_08006184(0, 16);
        func_080EA1F4((s32)func_080EA5A8);
    } else if ((gUnk_02039BA0->unk_70 & 0x40000) == 0) {
        gBldCnt = 0;
        SetBgPriority(0, 0);
        func_080E56B4(func_080EA20C()->unk_2C);
        func_080EA1F4((s32)func_080EA498);
    } else {
        func_080E0780();
        func_080E0820();
        func_080125A4();
    }
}
void Mode_MapFix_0(void) {
    UnkStruct_09EF8370* p;
    u16 t;

    gUnk_02039BA0 = EwramAlloc(0xE8);
    gUnk_0203C7AC = EwramAlloc(0x44);
    gUnk_0203C7B8 = EwramAlloc(0x180);
    func_080DEF20();
    SetBgMode0();

    if (gUnk_0203C590.unk_06 == 0xFE) {
        SetupBg(3, 0, 28, 0);
        SetupBg(2, 0, 29, 0);
        SetupBg(1, 0, 30, 0);
        SetupBg(0, 3, 31, 14);
    } else {
        SetupBg(3, 0, 28, 0);
        SetupBg(2, 0, 29, 0);
        SetupBg(1, 2, 30, 0);
        SetupBg(0, 3, 31, 14);
    }

    SetBgPriority(3, 3);
    SetBgPriority(2, 3);
    SetBgPriority(1, 1);
    SetBgPriority(0, 0);
    SetBackdropColor(0, 0, 0);
    func_080E0558();
    func_0801227C();
    gUnk_0203C7AC->unk_00 |= 0x80000000;
    gUnk_0203C7AC->unk_0C = 26;
    gUnk_0203C7AC->unk_0D = 0;

    p = func_080EA20C();
    TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapFix, p);
    func_080E56B4(p->unk_2C);

    if (gGameState.flags & 8) {
        TaskCreate(gUnk_02039BA0->unk_8C, &gTaskDescFldRiku, 0);
    } else {
        TaskCreate(gUnk_02039BA0->unk_8C, &gTaskDescFldSora, 0);
    }

    TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescLockon, 0);

    if (gUnk_0203C590.unk_02 & 0x100) {
        t = gUnk_0203C590.unk_02 & 0xFEFF;
        gUnk_0203C590.unk_02 = t;
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapFloor, 0);
    }

    if (gUnk_0203C590.unk_06 == 0xFC) {
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapGmkTutorial, 0);
    }

    func_080EA2AC();

    if (gGameState.unk_00 != 0) {
        func_080E0298(gGameState.unk_14, gGameState.unk_18 + gGameState.unk_1C);
        if ((s8)gGameState.unk_0F != -1) {
            t = gDispCnt & 0xEFFF;
            gDispCnt = t;
            TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapMenu, 0);
            func_080EA1E8((s32)func_080EA730);
        } else {
            func_080EA1E8((s32)func_080EA498);
        }
    } else {
        func_080E0298(gUnk_02039BA0->unk_DC, gUnk_02039BA0->unk_E0);
        func_080EA1E8((s32)func_080EA498);
    }

    func_080E5800();
    func_0801CB00();
    SeedRandom(gFrameCounter);
    m4aSongNumStartOrContinue(p->unk_34);

    if (gUnk_0203C590.unk_02 & 0x80) {
        t = gUnk_0203C590.unk_02 & 0xFF7F;
        gUnk_0203C590.unk_02 = t;
        func_08006494(16, 15);
        func_08006120(0, 16);
    } else {
        func_08006120(0, 16);
    }
}
void Mode_MapFix_1(void) {
    ((void (*)(void))gUnk_02034FD4)();
    UpdatePlayTime();
}
void Mode_MapFix_2(void) {
    func_080E0878();
    EwramFree(gUnk_02039BA0);
    EwramFree(gUnk_0203C7AC);
    EwramFree(gUnk_0203C7B8);
}
#ifndef VERSION_EU
void func_080EAB20(u8 a, u8 b, u8 c) {
    const u8* src;

    a &= 1;

    if (b != 0) {
        if (gGameState.flags & 8) {
            src = gUnk_09963D64[c];
        } else {
            src = gUnk_09961A64[c];
        }
    } else {
        if (gGameState.flags & 8) {
            src = gUnk_09964EE4[c];
        } else {
            src = gUnk_09962BE4[c];
        }
    }
    RequestDma3Copy((void*)src, (u8*)GetBgCharBase(1) + (a * 608 + 320), 320);
}
#else
INCLUDE_ASM("map/func_080EAB20.s");
#endif
void func_080EABB8(u8 a, u16 v) {
    u16 d[4];
    s32 off;
    u16* q;
    s32 i;

    a &= 1;
    d[0] = v / 100;
    d[1] = v / 10 - d[0] * 10;
    d[2] = v - d[0] * 100 - d[1] * 10;
    i = 1;
    off = a * 608 + 32;
    q = &d[1];

    while (i <= 2) {
        RequestDma3Copy((void*)&gUnk_09966064[*q * 32], (u8*)GetBgCharBase(1) + off + i * 32, 0x20);
        q++;
        i++;
    }
}
INCLUDE_ASM("map/func_080EAC60.s");

s32 func_080EAD3C(u8 i) {
    UnkStruct_02039D6C* p = &gUnk_02039D6C[i];

    if (p->unk_02 != 0) {
        func_080EABB8(i, p->unk_02);
        func_080EAC60(i, p->unk_04);
        func_080EAB20(i, 0, p->unk_00);
        return 1;
    }
    func_080EAB20(i, 0, 13);
    return 0;
}

INCLUDE_ASM("map/func_080EAD84.s");
INCLUDE_ASM("map/func_080EAEB0.s");

#ifndef VERSION_EU
void func_080EB818(u8 a, u8 b, u8 c) {
    const u8* src;

    if (a <= 1) {
        if (b != 0) {
            src = gUnk_09961A64[c];
        } else {
            src = gUnk_09962BE4[c];
        }
    } else {
        if (b != 0) {
            src = gUnk_09963D64[c];
        } else {
            src = gUnk_09964EE4[c];
        }
    }
    RequestDma3Copy((void*)src, (u8*)GetBgCharBase(1) + (a * 608 + 320), 320);
}
#else
INCLUDE_ASM("map/func_080EB818.s");
#endif

INCLUDE_ASM("map/func_080EB898.s");
void func_080EBA58(u8 a) {
    UnkStruct_02039D6C* e = &gUnk_02039D6C[a];

    if (e->unk_02 != 0) {
        func_080EB818(a, 1, e->unk_00);
        gUnk_02034FE0->unk_15C = func_08065B6C((void*)func_080DF804(e->unk_01), &gUnk_02034FE0->unk_03C);

        if (a <= 1) {
            LoadObjPaletteBank(gUnk_02034FE0->unk_038->unk_06, &gUnk_099910C4[0xB40]);
        } else {
            LoadObjPaletteBank(gUnk_02034FE0->unk_038->unk_06, &gUnk_099910C4[0xB80]);
        }
    } else {
        func_080EB818(a, 1, 13);
        gUnk_02034FE0->unk_15C = 0;
    }
}
INCLUDE_ASM("map/func_080EBAE0.s");

void func_080ECA88(UnkStruct_080ECA88* p) {
    func_080038E4(p->unk_44, p->unk_4C, p->unk_54);
    func_080038E4(p->unk_58, p->unk_60, p->unk_64);
}

INCLUDE_ASM("map/func_080ECAA8.s");

void func_080ECFE8(UnkStruct_080ECFE8* p, u8 a) {
    s32 i;

    func_080062F4(p->unk_020->unk_06 + 0x10, a);
    func_080062F4(p->unk_070->unk_06 + 0x10, a);
    func_080062F4(p->unk_038->unk_06 + 0x10, a);
    func_080062F4(p->unk_03C->unk_06 + 0x10, a);
    func_080062F4(p->unk_060->unk_06 + 0x10, a);

    for (i = 0; i < 3; i++) {
        if (p->unk_158[i] != 0) {
            func_080062F4(p->unk_158[i]->unk_06 + 0x10, a);
        }
    }
}

void func_080ED06C(UnkStruct_080ED06C* p, u8 a) {
    func_080062F4(p->unk_000->unk_06 + 0x10, a);
    func_080062F4(p->unk_138->unk_06 + 0x10, a);
    func_080062F4(p->unk_140->unk_06 + 0x10, a);
}

void func_080ED0B8(FldRes* p, u8 a, u16 v) {
    u16 d[3];
    u16* q;
    s32 i;

    d[0] = v / 100;
    d[1] = v / 10 - d[0] * 10;
    d[2] = v - d[0] * 100 - d[1] * 10;

    for (i = 0, q = d; i < 3; i++) {
        RequestDma3Copy((void*)&gUnk_099581A4[*q * 32], (void*)(0x06010000 + (p->unk_06 + a + i) * 32), 0x20);
        q++;
    }
}

INCLUDE_ASM("map/func_080ED14C.s");
INCLUDE_ASM("map/func_080ED250.s");
INCLUDE_ASM("map/func_080ED314.s");

void func_080EE50C(UnkStruct_080EE50C* p, u8 a) {
    func_080062F4(0x0B, a);
    func_080062F4(0x0C, a);
    func_080062F4(0x0D, a);
    func_080062F4(0x0E, a);
    func_080062F4(p->unk_014->unk_06 + 0x10, a);
    func_080062F4(p->unk_034->unk_06 + 0x10, a);
    func_080062F4(p->unk_040->unk_06 + 0x10, a);
    func_080062F4(p->unk_190->unk_06 + 0x10, a);
}

void func_080EE580(UnkStruct_080EE580* p, u8 a) {
    func_080062F4(p->unk_000->unk_06 + 0x10, a);
    func_080062F4(p->unk_168->unk_06 + 0x10, a);
    func_080062F4(p->unk_180->unk_06 + 0x10, a);
    func_080062F4(p->unk_188->unk_06 + 0x10, a);
}

#ifndef VERSION_EU
void func_080EE5E0(u8 a) {
    const u8* src;

    if (gGameState.flags & 8) {
        src = gUnk_09963D64[a];
    } else {
        src = gUnk_09961A64[a];
    }
    RequestDma3Copy((void*)src, (u8*)GetBgCharBase(0) + 320, 320);
}
#else
INCLUDE_ASM("map/func_080EE5E0.s");
#endif

void func_080EE62C(u16 v) {
    u16 d[4];
    s32 off;
    u16* q;
    s32 i;

    d[0] = v / 100;
    d[1] = v / 10 - d[0] * 10;
    d[2] = v - d[0] * 100 - d[1] * 10;
    off = 0x40;
    q = &d[1];

    for (i = 0; i < 2; i++) {
        RequestDma3Copy((void*)&gUnk_09966064[*q * 32], (u8*)GetBgCharBase(0) + off, 0x20);
        do {
            off += 0x20;
        } while (0);
        q++;
    }
}

void func_080EE6AC(u32 t) {
    u16 d[6];
    s32 off;
    u16* q;
    s32 i;
    u32 v;

    v = t / 3600;
    d[0] = v / 10;
    d[1] = v - d[0] * 10;
    t -= v * 3600;
    v = t / 60;
    d[2] = v / 10;
    d[3] = v - d[2] * 10;
    t -= v * 60;
    d[4] = t / 10;
    d[5] = t - d[4] * 10;
    off = 128;
    q = d;

    for (i = 0; i < 6; i++) {
        RequestDma3Copy((void*)&gUnk_09966064[*q * 32], (u8*)GetBgCharBase(0) + off, 0x20);
        off += 0x20;
        q++;
    }
}
void func_080EE760(u8* work, u8 i) {
    UnkStruct_02039D6C* e = &gUnk_02039D6C[i];

    if (e->unk_02 == 0) {
        work[0x164] = 0;
    } else {
        func_080EE5E0(e->unk_00);
        func_080EE62C(e->unk_02);
        func_080EE6AC(e->unk_04);
        work[0x164] = func_08065B6C((void*)func_080DF804(e->unk_01), &work[0x44]);
    }
}
INCLUDE_ASM("map/func_080EE7B0.s");

s32 func_080EF3A0(UnkStruct_080E590C* p) {
    UnkStruct_080DFF1C* q = &p->unk_08;

    if (p->unk_08.unk_00 < gUnk_02039BA0->unk_00 - 0x1800 || p->unk_08.unk_00 > gUnk_02039BA0->unk_00 + 0x10800 ||
        q->x + q->y < gUnk_02039BA0->unk_04 - 0x800 || q->x + q->y > gUnk_02039BA0->unk_04 + 0xC000) {
        p->unk_CC = 0;
        func_08012614(p->unk_48, 1);
        return 1;
    }
    return 0;
}

void func_080EF404(UnkStruct_080E590C* p, s32 b, s32 c) {
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&p->unk_08;

    if (p->unk_04 & 0x10) {
        b /= 5;
        c /= 5;
    }
    p->unk_08.unk_00 += gSineTable[q->unk_14] * q->unk_10 >> 8;
    q->unk_04 += -gSineTable[q->unk_14 + 64] * q->unk_10 >> 8;
    q->unk_10 += b;
    if (q->unk_10 > c) {
        q->unk_10 = c;
    }
}
void func_080EF478(UnkStruct_080E590C* p, s32 b, s32 c) {
    UnkStruct_080DFF1C* q = &p->unk_08;

    if (func_080DFBDC(q) != 0 || func_080DFF1C(q) != q->y) {
        p->unk_08.unk_00 = b;
        q->x = c;
        p->unk_CC = func_080EF84C;
        func_08012614(p->unk_48, 1);
    }
}

s32 func_080EF4BC(UnkStruct_080E590C* p) {
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&p->unk_08;
    u8 ang;

    if (gUnk_02039BA0->unk_24 != q->unk_0C) {
        return 0;
    }
    ang = GetAngle(p->unk_08.unk_00, q->unk_04, gUnk_02039BA0->unk_18, gUnk_02039BA0->unk_1C);
    if (abs(GetAngleDiff(ang, q->unk_14)) > 0x18) {
        return 0;
    }
    q->unk_14 = ang;
    return 1;
}

INCLUDE_ASM("map/func_080EF508.s");
INCLUDE_ASM("map/func_080EF84C.s");
void func_080EFA7C(UnkStruct_080F023C* p, u8 a) {
    s32* q = &p->unk_08;
    s32 t = q[2];
    s32 v;

    switch (a) {
    case 1:
        v = p->unk_DC + gSineTable[gFrameCounter & 0xFF] * 10;
        break;
    case 0:
    default:
        v = p->unk_DC + gSineTable[gFrameCounter * 2 & 0xFF] * 12;
        break;
    }

    if (p->unk_04 & 16) {
        q[2] += (v - q[2]) / 80;
    } else {
        q[2] += (v - q[2]) >> 4;
    }
    if (q[3] < q[2]) {
        q[2] = t;
        p->unk_DC = t - 0x1C00;
    }
}
INCLUDE_ASM("map/func_080EFB24.s");
INCLUDE_ASM("map/func_080EFC08.s");
void func_080F0108(UnkStruct_080F023C* p, u8 a) {
    s32* q = &p->unk_08;
    s32 t = q[2];
    s32 v;

    switch (a) {
    case 1:
        v = p->unk_DC + gSineTable[gFrameCounter & 0xFF] * 10;
        break;
    case 0:
    default:
        v = p->unk_DC + gSineTable[gFrameCounter * 2 & 0xFF] * 12;
        break;
    }

    if (p->unk_04 & 16) {
        q[2] += (v - q[2]) / 80;
    } else {
        q[2] += (v - q[2]) >> 4;
    }
    if (q[3] < q[2]) {
        q[2] = t;
        p->unk_DC = t - 0x1C00;
    }
}
s32 func_080F01B0(UnkStruct_080F023C* p) {
    s32* q = &p->unk_08;
    s32 dx;
    s32 dy;
    s32 lim;

    q[4] += 0x100;
    if (q[4] > 0x500) {
        q[4] = 0x500;
    }

    dx = (p->unk_D4 - p->unk_08) / 32;
    lim = q[4];

    if (dx > lim) {
        dx = lim;
    } else if (dx < -lim) {
        dx = -lim;
    }
    q[0] += dx;

    dy = (p->unk_D8 - q[1]) / 32;

    if (dy > lim) {
        dy = lim;
    } else if (dy < -lim) {
        dy = -lim;
    }
    q[1] += dy;

    if (p->unk_D0 > 64) {
        return 1;
    }
    p->unk_D0++;
    return 0;
}

s32 func_080F023C(UnkStruct_080F023C* p, s32 lim) {
    s32 dx;
    s32 dy;

    dx = p->unk_F8 - gUnk_02039BA0->unk_18;
    if (dx < 0) {
        dx = gUnk_02039BA0->unk_18 - p->unk_F8;
    }
    dy = p->unk_FC - gUnk_02039BA0->unk_1C;
    if (dy < 0) {
        dy = gUnk_02039BA0->unk_1C - p->unk_FC;
    }

    if (dx > 0x8000 || dy > 0x8000) {
        return 0;
    }
    return func_08003C9C((dx * dx >> 8) + (dy * dy >> 8)) < lim ? 1 : 0;
}

INCLUDE_ASM("map/func_080F02A0.s");
void func_080F0660(UnkStruct_080F023C* p, u8 a) {
    s32* q = &p->unk_08;
    s32 t = q[2];
    s32 v;

    switch (a) {
    case 1:
        v = p->unk_DC + gSineTable[gFrameCounter & 0xFF] * 10;
        break;
    case 0:
    default:
        v = p->unk_DC + gSineTable[gFrameCounter * 2 & 0xFF] * 12;
        break;
    }

    if (p->unk_04 & 16) {
        q[2] += (v - q[2]) / 80;
    } else {
        q[2] += (v - q[2]) >> 4;
    }
    if (q[3] < q[2]) {
        q[2] = t;
        p->unk_DC = t - 0x1C00;
    }
}

void func_080F0708(UnkStruct_080F023C* p, u8 flag) {
    if (flag) {
        p->unk_D4 = gUnk_02039BA0->unk_18;
        p->unk_D8 = gUnk_02039BA0->unk_1C;
        p->unk_DC = gUnk_02039BA0->unk_20 - 0x1000;
    } else {
        p->unk_D4 = gUnk_02039BA0->unk_18;
        p->unk_D8 = gUnk_02039BA0->unk_1C;
        p->unk_DC = gUnk_02039BA0->unk_20;

        if (GetRandom() % 2) {
            s32 t = GetRandom() % 65 * 256 + 0x2000;

            p->unk_D4 -= t;
        } else {
            s32 t = GetRandom() % 65 * 256 + 0x2000;

            p->unk_D4 += t;
        }
        {
            s32 t = GetRandom() % 121 * 256 - 0x3C00;

            p->unk_D8 += t;
        }
        {
            s32 t = GetRandom() % 49 * 256 + 0x1000;

            p->unk_DC -= t;
        }
    }
}

INCLUDE_ASM("map/func_080F07EC.s");

void func_080F3D58(UnkStruct_080DFF1C* p) {
    u16 r;

    if (gGameState.flags & 8) {
        r = GetRandom() % 10000;
        if (r < 6000) {
            func_080E9034(0, 5, p->unk_00, p->x, p->y);
        } else if (r < 10000) {
            func_080E9034(1, 3, p->unk_00, p->x, p->y);
        }
    } else {
        r = GetRandom() % 10000;
        if (r < 3000) {
            func_080E9034(0, 5, p->unk_00, p->x, p->y);
        } else if (r < 5000) {
            func_080E9034(1, 3, p->unk_00, p->x, p->y);
        } else if (r < 8000) {
            func_080E9034(2, 5, p->unk_00, p->x, p->y);
        } else {
            func_080E9034(3, 5, p->unk_00, p->x, p->y);
        }
    }
}

INCLUDE_ASM("map/func_080F3E24.s");
void func_080F4EE4(UnkStruct_080F4EE4* work) {
    work->unk_0B4 = -gSineTable[((work->unk_0D0 + 0x80) & 0xFF) + 0x40] * work->unk_0CC >> 8;
    work->unk_0B6 = -gSineTable[((work->unk_0CF + 0x80) & 0xFF) + 0x40] * work->unk_0CC >> 8;

    if ((u16)(work->unk_0B4 + 2) <= 4) {
        work->unk_0B4 = 2;
    }
    if ((u16)(work->unk_0B6 + 2) <= 4) {
        work->unk_0B6 = 2;
    }
}
INCLUDE_ASM("map/func_080F4F60.s");

s32 func_080F7488(UnkStruct_080DFF1C* p, s32 lim) {
    s32 dx;
    s32 dy;

    dx = p->unk_00 - gUnk_02039BA0->unk_18;
    if (dx < 0) {
        dx = gUnk_02039BA0->unk_18 - p->unk_00;
    }
    dy = p->x - gUnk_02039BA0->unk_1C;
    if (dy < 0) {
        dy = gUnk_02039BA0->unk_1C - p->x;
    }

    if (dx > 0x8000 || dy > 0x8000) {
        return 0;
    }
    return func_08003C9C((dx * dx >> 8) + (dy * dy >> 8)) < lim ? 1 : 0;
}

INCLUDE_ASM("map/func_080F74E8.s");
