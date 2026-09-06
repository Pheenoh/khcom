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
UnkStruct_02034FDC* gUnk_02034FDC;
UnkStruct_02034FE0* gUnk_02034FE0;
UnkStruct_02034FE4* gUnk_02034FE4;

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

void func_080E00E4(s32 a, s32 b) {
    s32 x;
    s32 y;
    s32 dx;
    s32 dy;
    s16 sx;
    s16 sy;
    u8* p;

    if ((gUnk_02039BA0->unk_70 & 0x40000) == 0) {
        x = func_080E0010(a);
        y = func_080E0044(b);
    } else {
        x = a - 0x7800;
        y = b - 0x6000;
    }

    dx = (x - gUnk_02039BA0->unk_00) >> 3;

    if (dx > 0x800) {
        dx = 0x800;
    } else if (dx < -0x800) {
        dx = -0x800;
    }

    dy = (y - gUnk_02039BA0->unk_04) >> 3;

    if (dy > 0x800) {
        dy = 0x800;
    } else if (dy < -0x800) {
        dy = -0x800;
    }

    if (abs(dx) <= 50) {
        dx = 0;
    }

    if (abs(dy) <= 50) {
        dy = 0;
    }

    gUnk_02039BA0->unk_00 += dx;
    gUnk_02039BA0->unk_04 += dy;
    sx = gUnk_02039BA0->unk_00 / 0x800;
    sy = gUnk_02039BA0->unk_04 / 0x800;
    p = func_080E5504();

    if (dx > 0) {
        func_080E4FF0(p, sx + 30, sy - 1);
    } else if (dx < 0) {
        func_080E4FF0(p, sx - 1, sy - 1);
    }

    p += 0xC0;

    if (dy > 0) {
        func_080E51C0(p, sx - 1, sy + 20);
    } else if (dy < 0) {
        func_080E51C0(p, sx - 1, sy - 1);
    }

    SetBgScroll(3, gUnk_02039BA0->unk_00 >> 8, gUnk_02039BA0->unk_04 >> 8);
    SetBgScroll(2, gUnk_02039BA0->unk_00 >> 8, gUnk_02039BA0->unk_04 >> 8);

    if (!(gUnk_0203C7AC->unk_00 & 1)) {
        SetBgScroll(1, gUnk_02039BA0->unk_00 >> 8, gUnk_02039BA0->unk_04 >> 8);
    }
}

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
    if (func_080A42C8()) {
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

void func_080E042C(void) {
    UnkStruct_09EF8370* p;
    UnkStruct_09EF70D0* q;
    s16 x;
    s16 y;

    if ((s32)gUnk_0203C7AC->unk_00 < 0) {
        p = gUnk_09EF8370[4];
        LoadBgTiles(1, p->unk_10, p->unk_14);
        LoadBgPalette(1, p->unk_00, p->unk_04);
        func_0800516C(1, p->unk_20, p->unk_24, p->unk_25);
        gUnk_0203C7AC->unk_00 &= ~1;
    } else {
        q = gUnk_09EF70D0[gUnk_0203C590.unk_04];
        LoadBgTiles(1, q->unk_10, q->unk_14);
        LoadBgPalette(1, q->unk_00, q->unk_04);
        x = gUnk_02039BA0->unk_00 >> 8;
        y = gUnk_02039BA0->unk_04 >> 8;
        func_080E4D68(x / 8, y / 8);
        SetBgScroll(1, x, y);
        gUnk_0203C7AC->unk_00 &= ~1;
    }
}

s32 func_080E04E0(void) {
    return gUnk_0203C7AC->unk_14;
}

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

void func_080E062C(void) {
    UnkStruct_080DFB8C* e;
    s32 x;
    s32 y;

    if (gUnk_0203C590.unk_07 <= 3) {
        e = func_080DFB7C(gUnk_0203C590.unk_07);
        x = (*(u16*)((u8*)e + 2) << 5) + 16;
        y = (*(u16*)((u8*)e + 4) << 4) + 10;

        switch (gUnk_0203C590.unk_07) {
        case 0:
            gUnk_02039BA0->unk_DC = (x << 8) - 0xC00;
            gUnk_02039BA0->unk_E0 = (y << 8) + 0x800;
            gUnk_02039BA0->unk_E4[0] = 0xAD;
            break;
        case 1:
            gUnk_02039BA0->unk_DC = (x << 8) + 0xC00;
            gUnk_02039BA0->unk_E0 = (y << 8) - 0x800;
            gUnk_02039BA0->unk_E4[0] = 0x2D;
            break;
        case 2:
            gUnk_02039BA0->unk_DC = (x << 8) - 0xC00;
            gUnk_02039BA0->unk_E0 = (y << 8) - 0x800;
            gUnk_02039BA0->unk_E4[0] = 0xD3;
            break;
        case 3:
            gUnk_02039BA0->unk_DC = (x << 8) + 0xC00;
            gUnk_02039BA0->unk_E0 = (y << 8) + 0x800;
            gUnk_02039BA0->unk_E4[0] = 0x53;
            break;
        }
    } else {
        func_080E524C((UnkStruct_080DFF1C*)&gUnk_02039BA0->unk_DC, &gUnk_02039BA0->unk_E0);
        gUnk_02039BA0->unk_E4[0] = 0x80;
    }

    if (gGameState.flags & 8) {
        TaskCreate(gUnk_02039BA0->unk_8C, &gTaskDescFldRiku, 0);
    } else {
        TaskCreate(gUnk_02039BA0->unk_8C, &gTaskDescFldSora, 0);
    }
}

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

void func_080E0C1C(u16 x, u16 y) {
    UnkStruct_080DFB8C* e;
    u8 v;
    s32 go;

    go = 1;

    while (go) {
        e = func_080E08BC((s16)x, (s16)y);

        switch (e->unk_02) {
        case 3:
            func_080E08BC((s16)x, (s16)(y - 1))->unk_00 |= 0x800;
            func_080E08BC((s16)(x - 1), (s16)y)->unk_00 |= 0x800;
            func_080E08BC((s16)(x - 1), (s16)(y - 1))->unk_00 |= 0x800;
            v = func_080E0938(38);
            e->unk_00 |= 0x20;
            func_080E0B98(e, 38, v);
            y++;
            e = func_080E08BC((s16)x, (s16)y);
            e->unk_00 |= 0x20;
            func_080E0B98(e, 39, v);
            break;
        case 5:
            func_080E08BC((s16)x, (s16)(y - 1))->unk_00 |= 0x800;
            func_080E08BC((s16)(x + 1), (s16)y)->unk_00 |= 0x800;
            func_080E08BC((s16)(x + 1), (s16)(y - 1))->unk_00 |= 0x800;
            v = func_080E0938(43);
            e->unk_00 |= 0x20;
            func_080E0B98(e, 43, v);
            y++;
            e = func_080E08BC((s16)x, (s16)y);
            e->unk_00 |= 0x20;
            func_080E0B98(e, 44, v);
            break;
        case 8:
            e->unk_00 |= 0x20;
            func_080E0B98(e, 37, 0xFF);
            break;
        case 9:
            e->unk_00 |= 0x20;
            func_080E0B98(e, 42, 0xFF);
            break;
        case 4:
            func_080E08BC((s16)x, (s16)(y + 1))->unk_00 |= 0x800;
            func_080E08BC((s16)(x + 1), (s16)y)->unk_00 |= 0x800;
            func_080E08BC((s16)(x + 1), (s16)(y + 1))->unk_00 |= 0x800;
            v = func_080E0938(40);
            e->unk_00 |= 0x20;
            func_080E0B98(e, 40, v);
            e = func_080E08BC((s16)x, (s16)(y - 1));
            e->unk_00 |= 0x20;
            func_080E0B98(e, 41, v);
            go = 0;
            break;
        case 6:
            func_080E08BC((s16)x, (s16)(y + 1))->unk_00 |= 0x800;
            func_080E08BC((s16)(x - 1), (s16)y)->unk_00 |= 0x800;
            func_080E08BC((s16)(x - 1), (s16)(y + 1))->unk_00 |= 0x800;
            v = func_080E0938(45);
            e->unk_00 |= 0x20;
            func_080E0B98(e, 45, v);
            e = func_080E08BC((s16)x, (s16)(y - 1));
            e->unk_00 |= 0x20;
            func_080E0B98(e, 46, v);
            go = 0;
            break;
        }
        y++;
    }
}

#ifdef NON_MATCHING
void func_080E0ED4(UnkStruct_02034F20* p) {
    s32 go = 1;
    u16 x = p->unk_0A;
    u16 y = p->unk_0C;
    u16 ny;

    while (go) {
        s16 cy = (s16)y;
        UnkStruct_080DFB8C* c = func_080E08BC((s16)x, cy);

        switch (c->unk_02) {
        case 4:
            y++;
            func_080E08BC((s16)x, (s16)y)->unk_00 |= 0x40;
            func_080E08BC((s16)(x + 1), cy)->unk_00 |= 0x40;
            func_080E08BC((s16)(x + 1), (s16)y)->unk_00 |= 0x40;
            c->unk_00 |= 0x40;
            p->unk_0A = x + 1;
            p->unk_0C = y;
            go = 0;
            break;
        case 6:
            ny = y + 1;
            func_080E08BC((s16)x, (s16)ny)->unk_00 |= 0x40;
            func_080E08BC((s16)(x - 1), cy)->unk_00 |= 0x40;
            func_080E08BC((s16)(x - 1), (s16)ny)->unk_00 |= 0x40;
            c->unk_00 |= 0x40;
            p->unk_0A = x;
            p->unk_0C = ny;
            go = 0;
            y = ny;
            break;
        default:
            y++;
            break;
        }
    }
}
#else
INCLUDE_ASM("map/func_080E0ED4.s");
#endif

void func_080E0FD8(UnkStruct_02034F20* p) {
    u16 x;
    u16 y;
    u16 d;
    UnkStruct_080DFB8C* e;
    UnkStruct_080DFB8C* q;

    x = p->unk_00;

    while (x < p->unk_02) {
        y = gUnk_02034F2C;

        while (y < gUnk_02034F2E) {
            e = func_080E08BC((s16)x, (s16)y);

            if (e->unk_02 == 4 || e->unk_02 == 6) {
                if (e->unk_08 != -0x100000 && p->unk_04 == e->unk_0C) {
                    d = ((p->unk_04 - e->unk_08) >> 8) / 16;

                    if (func_080E0920((UnkStruct_080DFF1C*)e, 3)) {
                        q = func_080E08BC((s16)x, (s16)(y - d));

                        if ((e->unk_00 & 28) == 0 && (q->unk_00 & 28) == 0) {
                            if (p->unk_08 == 0 ||
                                (p->unk_10 <= q->unk_08 &&
                                 (p->unk_10 < q->unk_08 ||
                                  p->unk_00 + GetRandom() % (p->unk_02 - p->unk_00 + 1) > x))) {
                                p->unk_08 = 1;
                                p->unk_0A = x;
                                p->unk_0C = y - d;
                                p->unk_0E = q->unk_02;
                                p->unk_10 = q->unk_08;
                                p->unk_14 = q->unk_0C;
                            }
                        } else if (p->unk_08 == 0 && p->unk_10 <= q->unk_08 &&
                                   (p->unk_10 < q->unk_08 ||
                                    p->unk_00 + GetRandom() % (p->unk_02 - p->unk_00 + 1) > x)) {
                            p->unk_0A = x;
                            p->unk_0C = y - d;
                            p->unk_0E = q->unk_02;
                            p->unk_10 = q->unk_08;
                            p->unk_14 = q->unk_0C;
                        }
                    }
                }
            }
            y++;
        }
        x++;
    }
}

void func_080E1138(void) {
    s32 i;

    for (i = 11; i >= 0; i--) {
        UnkStruct_02034F20* e = &gUnk_02034F20[i];

        if (e->unk_04 != 0x100000) {
            func_080E0FD8(e);
        }

        if (e->unk_08 != 0) {
            func_080E0C1C(e->unk_0A, e->unk_0C);
        } else if (e->unk_14 != 0x100000) {
            func_080E0ED4(e);
        }
    }
}

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

s16 func_080E1204(u8 a, u8 b, s16 c) {
    switch (a) {
    case 2:
    case 4:
        if (b == 4) {
            c += 1;
        }
        break;
    case 6:
        if (b != 4) {
            c -= 1;
        }
        break;
    case 1:
    case 5:
        if (b == 5) {
            c -= 1;
        }
        break;
    case 3:
        if (b != 5) {
            c += 1;
        }
        break;
    }

    return c;
}

void func_080E1274(void) {
    s32 i;
    s32 j;
    s32 dir;
    UnkStruct_080DFB8C* p;

    for (i = 0; i < gUnk_02034F28; i++) {
        dir = 10;

        for (j = 0; j < gUnk_02034F2A; j++) {
            p = func_080E08BC(i, j);

            switch (p->unk_02) {
            case 2:
            case 4:
            case 6:
                dir = 0;
                break;
            case 3:
                dir = 8;
                break;
            case 5:
                dir = 9;
                break;
            case 1:
                dir = 7;
                break;
            case 11:
                if (dir != 10) {
                    func_080E0900(p, dir, 0);
                }
                break;
            }
        }

        if (dir == 11) {
            for (j = 0; j < gUnk_02034F2A; j++) {
                func_080E0900(func_080E08BC(i, j), 7, 0);
            }
        }
    }

    for (i = 0; i < gUnk_02034F28; i++) {
        dir = 10;

        for (j = gUnk_02034F2A - 1; j >= 0; j--) {
            p = func_080E08BC(i, j);

            switch (p->unk_02) {
            case 4:
                dir = 8;
                break;
            case 6:
                dir = 9;
                break;
            case 2:
                dir = 7;
                break;
            case 11:
                if (dir != 10) {
                    func_080E0900(p, dir, 0);
                }
                break;
            }
        }
    }
}

void func_080E13B0(void) {
    u16 y = gUnk_02034F2E;
    u16 n = y - gUnk_02034F2C + 1;
    s32 j;

    for (j = 0; j < n; j++) {
        u16 x;

        for (x = 0; x < gUnk_02034F28; x++) {
            UnkStruct_080DFB8C* c = func_080E08BC((s16)x, (s16)y);
            s32 v;
            s32 ok;
            s32 k;

            switch (c->unk_02) {
            case 0:
            case 1:
            case 3:
            case 5:
                v = c->unk_08;
                break;
            case 2:
            case 4:
            case 6:
                v = c->unk_0C;
                break;
            default:
                v = 0x100000;
                break;
            }

            if (v == 0x100000) {
                continue;
            }

            ok = 1;

            for (k = 11; k >= 0; k--) {
                if (gUnk_02034F20[k].unk_04 != v) {
                    if (gUnk_02034F20[k].unk_04 != 0x100000) {
                        ok = 0;
                    }
                } else {
                    if (ok == 0) {
                        if (k % 2) {
                            c->unk_00 |= 2;
                        } else {
                            c->unk_00 |= 1;
                        }
                    }
                    break;
                }
            }
        }

        y--;
    }
}

void func_080E14D0(void) {
    s32 x;
    s32 y;

    for (y = 0; y < gUnk_02034F2A; y++) {
        for (x = 0; x < gUnk_02034F28 - 1; x++) {
            UnkStruct_080DFB8C* a = func_080E08BC(x, y);
            UnkStruct_080DFB8C* b = func_080E08BC(x + 1, y);
            s32 flag = 0;

            switch (a->unk_02) {
            case 0:
                if (b->unk_02 != 0 && b->unk_02 != 3 && b->unk_02 != 4 && b->unk_02 != 5 &&
                    b->unk_02 != 6) {
                    flag = 1;
                }
                break;
            case 6:
                if (b->unk_02 != 9) {
                    flag = 1;
                }
                break;
            case 3:
                if (b->unk_02 != 8) {
                    flag = 1;
                }
                break;
            case 4:
            case 5:
                if (b->unk_02 != 0) {
                    flag = 1;
                }
                break;
            case 8:
                if (b->unk_02 != 8 && b->unk_02 != 4) {
                    flag = 1;
                }
                break;
            case 9:
                if (b->unk_02 != 9 && b->unk_02 != 5) {
                    flag = 1;
                }
                break;
            case 1:
            case 2:
            case 7:
                if (a->unk_02 != b->unk_02) {
                    flag = 1;
                }
                break;
            }

            if (flag != 0) {
                a->unk_00 |= 8;
                b->unk_00 |= 4;
            }

            switch (a->unk_02) {
            case 4:
                if (func_080E08BC(x + 1, y - 1)->unk_02 == 2) {
                    a->unk_00 |= 8;
                }
                break;
            case 6:
                if (func_080E08BC(x - 1, y - 1)->unk_02 == 2) {
                    a->unk_00 |= 4;
                }
                break;
            case 3:
                if (func_080E08BC(x - 1, y + 1)->unk_02 == 1) {
                    a->unk_00 |= 4;
                }
                break;
            case 5:
                if (func_080E08BC(x + 1, y + 1)->unk_02 == 1) {
                    a->unk_00 |= 8;
                }
                break;
            }
        }
    }
}

void func_080E1670(void) {
    s32 i;
    s32 j;
    UnkStruct_080DFB8C* e;
    u8 v;

    for (i = 0; i < gUnk_02034F28; i++) {
        for (j = 0; j < gUnk_02034F2A; j++) {
            e = func_080E08BC(i, j);

            if (e->unk_03 != 7) {
                continue;
            }

            switch (e->unk_02) {
            case 0:
                func_080E0A38(e);
                break;
            case 7:
                func_080E0960(e, 3);
                func_080E0A70(e, 4);
                break;
            case 8:
                func_080E0960(e, 4);
                func_080E0A70(e, 5);
                break;
            case 9:
                func_080E0960(e, 5);
                func_080E0A70(e, 6);
                break;
            case 2:
                v = func_080E0938(10);

                if (func_080E0920((UnkStruct_080DFF1C*)e, 3)) {
                    func_080E0A38(e);
                    func_080E09B4(e, 10, v);
                    func_080E0960(func_080E08BC(i, j - 1), 3);
                    func_080E09B4(func_080E08BC(i, j - 1), 11, v);
                } else {
                    func_080E0A38(e);
                    func_080E09B4(e, 12, v);
                }
                break;
            case 1:
                v = func_080E0938(7);
                func_080E09B4(func_080E08BC(i, j - 1), 48, v);
                func_080E0A38(e);

                if (func_080E0920((UnkStruct_080DFF1C*)e, 3)) {
                    func_080E09B4(e, 7, v);
                    func_080E0960(func_080E08BC(i, j + 1), 3);
                    func_080E09B4(func_080E08BC(i, j + 1), 8, v);
                } else {
                    func_080E09B4(e, 9, v);
                }
                break;
            case 3:
                if (e->unk_00 & 16) {
                    func_080E0A38(e);
                    sub_080E0B00(e, 23);

                    if (func_080E0920((UnkStruct_080DFF1C*)e, 2)) {
                        func_080E0BF4(i, j + 1, 4, 24);
                    } else {
                        func_080E0BF4(i, j + 1, 4, 25);

                        if ((func_080E08BC(i, j + 2)->unk_00 & 16) == 0) {
                            func_080E0A38(func_080E08BC(i, j + 2));
                            func_080E09B4(func_080E08BC(i, j + 2), 15, 0);
                        }
                    }
                } else {
                    v = func_080E0938(13);
                    func_080E0A38(e);
                    func_080E09B4(e, 13, v);
                    func_080E09B4(func_080E08BC(i, j - 1), 47, v);

                    if (func_080E0920((UnkStruct_080DFF1C*)e, 2)) {
                        func_080E0960(func_080E08BC(i, j + 1), 4);
                        func_080E09B4(func_080E08BC(i, j + 1), 14, v);
                    } else if ((func_080E08BC(i, j + 2)->unk_00 & 16) == 0) {
                        func_080E0960(func_080E08BC(i, j + 1), 4);
                        func_080E09B4(func_080E08BC(i, j + 1), 17, v);
                        func_080E0A38(func_080E08BC(i, j + 2));
                        func_080E09B4(func_080E08BC(i, j + 2), 15, v);
                    }
                }
                break;
            case 5:
                if (e->unk_00 & 16) {
                    func_080E0A38(e);
                    sub_080E0B00(e, 29);

                    if (func_080E0920((UnkStruct_080DFF1C*)e, 2)) {
                        func_080E0BF4(i, j + 1, 5, 30);
                    } else {
                        func_080E0BF4(i, j + 1, 5, 31);

                        if ((func_080E08BC(i, j + 2)->unk_00 & 16) == 0) {
                            func_080E0A38(func_080E08BC(i, j + 2));
                            func_080E09B4(func_080E08BC(i, j + 2), 20, 0);
                        }
                    }
                } else {
                    v = func_080E0938(18);
                    func_080E0A38(e);
                    func_080E09B4(e, 18, v);
                    func_080E09B4(func_080E08BC(i, j - 1), 49, v);

                    if (func_080E0920((UnkStruct_080DFF1C*)e, 2)) {
                        func_080E0960(func_080E08BC(i, j + 1), 5);
                        func_080E09B4(func_080E08BC(i, j + 1), 19, v);
                    } else if ((func_080E08BC(i, j + 2)->unk_00 & 16) == 0) {
                        func_080E0960(func_080E08BC(i, j + 1), 5);
                        func_080E09B4(func_080E08BC(i, j + 1), 22, v);
                        func_080E0A38(func_080E08BC(i, j + 2));
                        func_080E09B4(func_080E08BC(i, j + 2), 20, v);
                    }
                }
                break;
            case 4:
                if (e->unk_00 & 16) {
                    func_080E0A38(e);
                    sub_080E0B00(e, 26);

                    if (func_080E0920((UnkStruct_080DFF1C*)e, 2)) {
                        func_080E0BF4(i, j - 1, 4, 27);
                    } else if ((func_080E08BC(i, j - 2)->unk_00 & 16) == 0) {
                        func_080E0BF4(i, j - 1, 4, 28);
                    } else {
                        func_080E0BF4(i, j - 1, 4, 35);
                    }
                } else {
                    v = func_080E0938(15);
                    func_080E0A38(e);
                    func_080E09B4(e, 15, v);

                    if (func_080E0920((UnkStruct_080DFF1C*)e, 2)) {
                        func_080E0960(func_080E08BC(i, j - 1), 4);
                        func_080E09B4(func_080E08BC(i, j - 1), 16, v);
                    }
                }
                break;
            case 6:
                if (e->unk_00 & 16) {
                    func_080E0A38(e);
                    sub_080E0B00(e, 32);

                    if (func_080E0920((UnkStruct_080DFF1C*)e, 2)) {
                        func_080E0BF4(i, j - 1, 5, 33);
                    } else if ((func_080E08BC(i, j - 2)->unk_00 & 16) == 0) {
                        func_080E0BF4(i, j - 1, 5, 34);
                    } else {
                        func_080E0BF4(i, j - 1, 5, 36);
                    }
                } else {
                    v = func_080E0938(20);
                    func_080E0A38(e);
                    func_080E09B4(e, 20, v);

                    if (func_080E0920((UnkStruct_080DFF1C*)e, 2)) {
                        func_080E0960(func_080E08BC(i, j - 1), 5);
                        func_080E09B4(func_080E08BC(i, j - 1), 21, v);
                    }
                }
                break;
            }
        }
    }
}

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

u8 func_080E1CA8(s16 x, s16 y) {
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

void func_080E1D08(s16 x, s16 y) {
    UnkStruct_080DFB8C* p = func_080E08BC(x, y + 7);

    if (p->unk_08 == -0x100000) {
        switch (p->unk_02) {
        case 4:
            if (!func_080E1CA8(x + 1, y + 6)) {
                func_080E1C64(x, y, 18);
                func_080E1C64(x, y + 1, 19);
            } else if (!func_080E1CA8(x - 1, y + 7)) {
                func_080E1C64(x, y, 26);
                func_080E1C64(x, y + 1, 27);
            } else {
                func_080E1C64(x, y, 6);
                func_080E1C64(x, y + 1, 7);
            }
            break;
        case 6:
            if (!func_080E1CA8(x - 1, y + 6)) {
                func_080E1C64(x, y, 20);
                func_080E1C64(x, y + 1, 21);
            } else if (!func_080E1CA8(x + 1, y + 7)) {
                func_080E1C64(x, y, 28);
                func_080E1C64(x, y + 1, 29);
            } else {
                func_080E1C64(x, y, 8);
                func_080E1C64(x, y + 1, 9);
            }
            break;
        case 2:
            if (!func_080E1CA8(x + 1, y + 7)) {
                func_080E1C64(x, y, 2);
                func_080E1C64(x, y + 1, 34);
            } else if (!func_080E1CA8(x - 1, y + 7)) {
                func_080E1C64(x, y, 3);
                func_080E1C64(x, y + 1, 35);
            } else {
                func_080E1C64(x, y, 1);
                func_080E1C64(x, y + 1, 4);
            }
            break;
        case 7:
        case 8:
        case 9:
            if (func_080E1CE0(x - 1, y + 6, 6)) {
                func_080E1C64(x, y, 15);
            } else if (func_080E1CE0(x + 1, y + 6, 4)) {
                func_080E1C64(x, y, 14);
            } else if (!func_080E1CA8(x + 1, y + 7)) {
                func_080E1C64(x, y, 2);
            } else if (!func_080E1CA8(x - 1, y + 7)) {
                func_080E1C64(x, y, 3);
            } else {
                func_080E1C64(x, y, 1);
            }
            break;
        }
    }
}

void func_080E1FA8(s16 x, s16 y) {
    UnkStruct_080DFB8C* p = func_080E08BC(x, y);

    if (p->unk_0C == 0x100000 && p->unk_05 == 0) {
        switch (p->unk_02) {
        case 3:
            func_080E1C64(x, y, 12);
            func_080E1C64(x, y - 1, 13);

            if (!func_080E1CA8(x - 1, y + 1)) {
                func_080E1C64(x, y + 1, 1);
                func_080E1C64(x - 1, y + 1, 24);
                func_080E1C64(x - 1, y, 25);
            }

            if (!func_080E1CA8(x + 1, y)) {
                func_080E1C64(x + 1, y - 1, 32);
                func_080E1C64(x + 1, y - 2, 33);
                func_080E1C64(x + 1, y, 2);

                if (func_080E1CA8(x + 1, y + 1)) {
                    func_080E1C64(x + 1, y + 1, 16);
                } else {
                    func_080E1C64(x + 1, y + 1, 2);
                }
            }
            break;
        case 5:
            func_080E1C64(x, y, 10);
            func_080E1C64(x, y - 1, 11);

            if (!func_080E1CA8(x + 1, y + 1)) {
                func_080E1C64(x, y + 1, 1);
                func_080E1C64(x + 1, y + 1, 22);
                func_080E1C64(x + 1, y, 23);
            }

            if (!func_080E1CA8(x - 1, y)) {
                func_080E1C64(x - 1, y - 1, 30);
                func_080E1C64(x - 1, y - 2, 31);
                func_080E1C64(x - 1, y, 3);

                if (func_080E1CA8(x - 1, y + 1)) {
                    func_080E1C64(x - 1, y + 1, 17);
                } else {
                    func_080E1C64(x - 1, y + 1, 3);
                }
            }
            break;
        case 1:
            func_080E1C64(x, y, 1);
            func_080E1C64(x, y - 1, 5);

            if (!func_080E1CA8(x - 1, y)) {
                func_080E1C64(x - 1, y, 3);
                func_080E1C64(x - 1, y - 1, 37);
            }

            if (!func_080E1CA8(x + 1, y)) {
                func_080E1C64(x + 1, y, 2);
                func_080E1C64(x + 1, y - 1, 36);
            }
            break;
        case 7:
        case 8:
        case 9:
            func_080E1C64(x, y, 1);

            if (func_080E1CE0(x - 1, y + 1, 3)) {
                func_080E1C64(x - 1, y, 3);
                func_080E1C64(x - 1, y + 1, 17);
            }

            if (func_080E1CE0(x + 1, y + 1, 5)) {
                func_080E1C64(x + 1, y, 2);
                func_080E1C64(x + 1, y + 1, 16);
            }

            if (!func_080E1CA8(x - 1, y)) {
                if (func_080E1CE0(x, y - 1, 3)) {
                    func_080E1C64(x - 1, y, 24);
                    func_080E1C64(x - 1, y - 1, 25);
                } else {
                    func_080E1C64(x - 1, y, 3);
                }
            }

            if (!func_080E1CA8(x + 1, y)) {
                if (func_080E1CE0(x, y - 1, 5)) {
                    func_080E1C64(x + 1, y, 22);
                    func_080E1C64(x + 1, y - 1, 23);
                } else {
                    func_080E1C64(x + 1, y, 2);
                }
            }
            break;
        }
    }
}

void func_080E2318(s16 y) {
    switch (func_080E08BC(0, y)->unk_05) {
    case 10:
        func_080E1C64(0, y, 16);
        break;
    case 6:
        func_080E1C64(0, y, 14);
        break;
    case 0:
    case 7:
    case 11:
    case 18:
    case 19:
    case 22:
    case 23:
        func_080E1C64(0, y, 2);
        break;
    }
}

void func_080E23CC(s16 j) {
    s16 x = gUnk_02034F28 - 1;
    UnkStruct_080DFB8C* q = func_080E08BC(x, j);

    switch (q->unk_05) {
    case 12:
        func_080E1C64(x, j, 17);
        break;
    case 8:
        func_080E1C64(x, j, 15);
        break;
    case 0:
    case 9:
    case 13:
    case 20:
    case 21:
    case 24:
    case 25:
        func_080E1C64(x, j, 3);
        break;
    }
}

void func_080E249C(void) {
    s32 i;
    s32 j;

    for (i = 0; i < gUnk_02034F28; i++) {
        for (j = 0; j < gUnk_02034F2A; j++) {
            func_080E1D08(i, j);
            func_080E1FA8(i, j);
        }
    }

    for (j = 0; j < gUnk_02034F2A; j++) {
        func_080E2318(j);
        func_080E23CC(j);
    }
}

void func_080E2520(void) {
    s16 i;
    s16 j;
    s32 z;
    UnkStruct_080DFB8C* p;

    for (i = 0; i < gUnk_02034F28; i++) {
        z = 0x100000;

        for (j = gUnk_02034F2A - 1; j >= 0; j--) {
            p = func_080E08BC(i, j);

            switch (p->unk_02) {
            case 1:
            case 3:
            case 5:
                p->unk_0C = z;
                z = p->unk_08;
                break;
            case 0:
                p->unk_08 = z;
                p->unk_0C = z;
                break;
            case 2:
            case 4:
            case 6:
                p->unk_0C = p->unk_08;
                break;
            case 7:
            case 8:
            case 9:
            default:
                p->unk_0C = z;
                break;
            }
        }
    }

    for (i = 0; i < gUnk_02034F28; i++) {
        z = -0x100000;

        for (j = 0; j < gUnk_02034F2A; j++) {
            p = func_080E08BC(i, j);

            switch (p->unk_02) {
            case 1:
            case 3:
            case 5:
                z = p->unk_08;
                break;
            case 2:
            case 4:
            case 6:
            case 7:
            case 8:
            case 9:
                p->unk_08 = z;
                break;
            }
        }
    }
}

void func_080E2668(UnkStruct_02034F20* p, s32 a) {
    u8 d;
    s32 i;
    u16 x;
    u16 y;
    u16 w;
    UnkStruct_080DFB8C* e;
    UnkStruct_080DFB8C* q;

    d = a;
    e = func_080DFB7C(d);

    if (!(e->unk_00 & 1)) {
        return;
    }

    w = p->unk_02 - p->unk_00;

    if (d == 0) {
        x = p->unk_00 + w * 5 / 8 + GetRandom() % (w >> 2);

        for (i = 0; i < w; i++) {
            for (y = gUnk_02034F2C; y <= gUnk_02034F2E; y++) {
                q = func_080E08BC(x, y);

                if (q->unk_02 == 6 && q->unk_0C == p->unk_04 && q->unk_08 == -0x100000 && (q->unk_00 & 0x20) == 0) {
                    *(u16*)&e->unk_02 = x;
                    *(u16*)&e->unk_04 = y;
                    q->unk_00 |= 0x800;
                    q->unk_00 |= 0x400;
                    func_080E08BC(x, y + 1)->unk_00 |= 0x800;
                    func_080E08BC(x - 1, y)->unk_00 |= 0x800;
                    func_080E08BC(x - 1, y + 1)->unk_00 |= 0x800;
                    func_080E08BC(x, y - 1)->unk_00 |= 0x400;
                    func_080E08BC(x, y - 2)->unk_00 |= 0x400;
                    func_080E08BC(x, y - 3)->unk_00 |= 0x400;
                    return;
                }
            }

            x = x < p->unk_02 - 1 ? x + 1 : p->unk_00;
        }
    }

    if (d == 2) {
        x = p->unk_00 + w * 5 / 8 + GetRandom() % (w >> 2);

        for (i = 0; i < w; i++) {
            for (y = gUnk_02034F2C; y <= gUnk_02034F2E; y++) {
                q = func_080E08BC(x, y);

                if (q->unk_02 == 3 && q->unk_08 == p->unk_04 && q->unk_0C == 0x100000 && (q->unk_00 & 0x20) == 0) {
                    *(u16*)&e->unk_02 = x;
                    *(u16*)&e->unk_04 = y;
                    func_080E08BC(x, y)->unk_00 |= 0x800;
                    func_080E08BC(x, y - 1)->unk_00 |= 0x800;
                    func_080E08BC(x - 1, y)->unk_00 |= 0x800;
                    func_080E08BC(x - 1, y - 1)->unk_00 |= 0x800;
                    return;
                }
            }

            x = x < p->unk_02 - 1 ? x + 1 : p->unk_00;
        }
    }

    if (d == 1) {
        x = p->unk_00 + w * 3 / 8 - GetRandom() % (w >> 2);

        for (i = 0; i < w; i++) {
            for (y = gUnk_02034F2C; y <= gUnk_02034F2E; y++) {
                q = func_080E08BC(x, y);

                if (q->unk_02 == 5 && q->unk_08 == p->unk_04 && q->unk_0C == 0x100000 && (q->unk_00 & 0x20) == 0) {
                    *(u16*)&e->unk_02 = x;
                    *(u16*)&e->unk_04 = y;
                    func_080E08BC(x, y)->unk_00 |= 0x800;
                    func_080E08BC(x, y - 1)->unk_00 |= 0x800;
                    func_080E08BC(x + 1, y)->unk_00 |= 0x800;
                    func_080E08BC(x + 1, y - 1)->unk_00 |= 0x800;
                    return;
                }
            }

            x = x > p->unk_00 ? x - 1 : p->unk_02 - 1;
        }
    }

    if (d == 3) {
        x = p->unk_00 + w * 3 / 8 - GetRandom() % (w >> 2);

        for (i = 0; i < w; i++) {
            for (y = gUnk_02034F2C; y <= gUnk_02034F2E; y++) {
                q = func_080E08BC(x, y);

                if (q->unk_02 == 4 && q->unk_0C == p->unk_04 && q->unk_08 == -0x100000 && (q->unk_00 & 0x20) == 0) {
                    *(u16*)&e->unk_02 = x;
                    *(u16*)&e->unk_04 = y;
                    q->unk_00 |= 0x800;
                    q->unk_00 |= 0x400;
                    func_080E08BC(x, y + 1)->unk_00 |= 0x800;
                    func_080E08BC(x + 1, y)->unk_00 |= 0x800;
                    func_080E08BC(x + 1, y + 1)->unk_00 |= 0x800;
                    func_080E08BC(x, y - 1)->unk_00 |= 0x400;
                    func_080E08BC(x, y - 2)->unk_00 |= 0x400;
                    func_080E08BC(x, y - 3)->unk_00 |= 0x400;
                    return;
                }
            }

            x = x > p->unk_00 ? x - 1 : p->unk_02 - 1;
        }
    }
}

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

void func_080E2C50(void) {
    UnkStruct_02034F20* p = &gUnk_02034F20[11];

    while (p->unk_04 == 0x100000) {
        p--;
    }

    func_080E2668(p, 0);
    func_080E2668(p, 1);
    func_080E2668(p, 2);
    func_080E2668(p, 3);
}

void func_080E2C98(void) {
    s32 i;
    UnkStruct_080DFB8C* e;

    for (i = 0; i < 4; i++) {
        e = func_080DFB7C(i);
        e->unk_06[1] = func_080DEE28(gUnk_0203C590.unk_06, i);
        e->unk_06[0] = i;
        e->unk_00 = func_080DEE44(gUnk_0203C590.unk_06, i);

        if (e->unk_06[1] != 0xFF) {
            switch (i) {
            case 0:
                gUnk_0203C7AC->unk_00 |= 0x1000000;
                break;
            case 1:
                gUnk_0203C7AC->unk_00 |= 0x2000000;
                break;
            case 2:
                gUnk_0203C7AC->unk_00 |= 0x4000000;
                break;
            case 3:
                gUnk_0203C7AC->unk_00 |= 0x8000000;
                break;
            }
        }
    }

    if (gUnk_0203C7AC->unk_0D != 3) {
        if ((u8)func_080E2B08() != 2) {
            func_080E2BF8(2);

            if (func_080E2BA0(0) != 3) {
                func_080E2C2C(3);
            }
        } else {
            func_080E2C2C(1);

            if (func_080E2BA0(3) != 0) {
                func_080E2BF8(0);
            }
        }
    } else {
        func_080E2C50();
    }
}

void func_080E2D80(void) {
    s32 i;
    s32 j;

    gUnk_02034F2C = gUnk_02034F2A;
    gUnk_02034F2E = 0;

    for (i = 0; i < gUnk_02034F28; i++) {
        for (j = 0; j < gUnk_02034F2A; j++) {
            switch (func_080E08BC(i, j)->unk_02) {
            case 2:
            case 4:
            case 6:
                if (j < gUnk_02034F2C) {
                    gUnk_02034F2C = j;
                }
                break;
            case 1:
            case 3:
            case 5:
                if (j > gUnk_02034F2E) {
                    gUnk_02034F2E = j;
                }
                break;
            }
        }
    }
}

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

void func_080E3060(u8 i, u16 a, u16 b, s16 c) {
    if (gUnk_02034F20[i].unk_04 == 0x100000) {
        gUnk_02034F20[i].unk_00 = a;
        gUnk_02034F20[i].unk_02 = b;
        gUnk_02034F20[i].unk_04 = c << 12;
    }
}

void func_080E309C(u8 i, s16 a, s16 b, s16 c, u8 e) {
    s16 x;
    s16 y;
    s16 yn;
    s16 n;
    u8 t;
    s32 k;
    s16 yb;
    u16* buf;
    u16* w;
    s32 v;
    UnkStruct_080DFB8C* q;
    s32 m;

    v = gUnk_02034F20[i].unk_04;
    buf = EwramAlloc(96);
    y = c;
    k = 4;
    q = func_080E08BC(a, y);
    func_080E0900(q, 4, v);
    q->unk_00 |= 0x10;
    w = buf;
    *w++ = y;

    for (x = a + 1; x < b - 1; x++) {
        t = func_080E300C(i, x, y);

        if (t == 11) {
            if (y <= 3) {
                t = 6;
            } else if (i == 0) {
                if (e == 2) {
                    t = func_080E2F48(a, b, x, 1);
                } else if (e == 3) {
                    t = func_080E2F98(a, b, x, 1);
                } else {
                    t = func_080E2E24(a, b, x);
                }
            } else {
                t = func_080E2E24(a, b, x);
            }
        }

        y = func_080E1194(k, t, y);
        k = t;
        q = func_080E08BC(x, y);
        func_080E0900(q, t, v);
        *w++ = y;
    }

    n = func_080E1194(k, 6, y);
    q = func_080E08BC(x, n);
    func_080E0900(q, 6, v);
    q->unk_00 |= 0x10;
    yb = n + (b - a);
    y = c + 1;
    q = func_080E08BC(a, y);
    k = 5;
    func_080E0900(q, 5, v);
    q->unk_00 |= 0x10;
    w = buf + 1;

    for (x = a + 1; x < b - 1; x++) {
        yn = func_080E1194(k, 1, y);

        if (b - x == 2 && yb - yn == 2) {
            t = 5;
        } else if (yb - yn == 1) {
            t = 1;
        } else if (yn >= yb) {
            t = 3;
        } else if (yn - w[1] < gUnk_0203C7B0.unk_05) {
            t = 5;
        } else if (yn - w[1] > gUnk_0203C7B0.unk_06) {
            t = 3;
        } else if (yn - w[1] == gUnk_0203C7B0.unk_05 || yn - w[1] == gUnk_0203C7B0.unk_06) {
            t = func_080E2F14(x, w[0]);
        } else if (e == 2) {
            t = func_080E2F48(a, b, x, 0);
        } else if (e == 3) {
            t = func_080E2F98(a, b, x, 0);
        } else {
            t = func_080E2E9C(a, b, x);
        }

        if (yn >= gUnk_02034F2A - 1 && t == 5) {
            t = 1;
        }

        y = func_080E1194(k, t, y);
        k = t;
        q = func_080E08BC(x, y);
        func_080E0900(q, t, v);
        w++;
        yb--;
    }

    m = func_080E1194(k, 3, y);
    q = func_080E08BC(x, m);
    func_080E0900(q, 3, v);
    q->unk_00 |= 0x10;
    EwramFree(buf);
}

void func_080E3400(u8 i, s16 a, s16 b, s16 c, u8 e) {
    s16 x;
    s16 yn;
    s16 n;
    u8 t;
    s32 k;
    s16 y;
    s16 yb;
    u16* buf;
    u16* w;
    s32 v;
    UnkStruct_080DFB8C* q;
    s32 m;

    v = gUnk_02034F20[i].unk_04;
    buf = EwramAlloc(96);
    y = c;
    k = 6;
    q = func_080E08BC(b - 1, y);
    func_080E0900(q, 6, v);
    q->unk_00 |= 0x10;
    w = buf;
    *w++ = y;

    for (x = b - 2; x > a; x--) {
        t = func_080E300C(i, x, y);

        if (t == 11) {
            if (y <= 3) {
                t = 4;
            } else if (i == 0) {
                if (e == 2) {
                    t = func_080E2F48(a, b, x, 1);
                } else if (e == 3) {
                    t = func_080E2F98(a, b, x, 1);
                } else {
                    t = func_080E2E24(a, b, x);
                }
            } else {
                t = func_080E2E24(a, b, x);
            }
        }

        y = func_080E1204(k, t, y);
        k = t;
        q = func_080E08BC(x, y);
        func_080E0900(q, t, v);
        *w++ = y;
    }

    n = func_080E1204(k, 4, y);
    q = func_080E08BC(x, n);
    func_080E0900(q, 4, v);
    q->unk_00 |= 0x10;
    yb = n + (b - a);
    y = c + 1;
    q = func_080E08BC(b - 1, y);
    k = 3;
    func_080E0900(q, 3, v);
    q->unk_00 |= 0x10;
    w = buf + 1;

    for (x = b - 2; x > a; x--) {
        yn = func_080E1204(k, 1, y);

        if (x - a == 1 && yb - yn == 2) {
            t = 3;
        } else if (yb - yn == 1) {
            t = 1;
        } else if (yn >= yb) {
            t = 5;
        } else if (yn - w[1] < gUnk_0203C7B0.unk_05) {
            t = 3;
        } else if (yn - w[1] > gUnk_0203C7B0.unk_06) {
            t = 5;
        } else if (yn - w[1] == gUnk_0203C7B0.unk_05 || yn - w[1] == gUnk_0203C7B0.unk_06) {
            t = func_080E2F14(x, w[0]);
        } else if (e == 2) {
            t = func_080E2F48(a, b, x, 0);
        } else if (e == 3) {
            t = func_080E2F98(a, b, x, 0);
        } else {
            t = func_080E2E9C(a, b, x);
        }

        if (yn >= gUnk_02034F2A - 1 && t == 3) {
            t = 1;
        }

        y = func_080E1204(k, t, y);
        k = t;
        q = func_080E08BC(x, y);
        func_080E0900(q, t, v);
        w++;
        yb--;
    }

    m = func_080E1204(k, 5, y);
    q = func_080E08BC(x, m);
    func_080E0900(q, 5, v);
    q->unk_00 |= 0x10;
    EwramFree(buf);
}

#ifdef NON_MATCHING
void func_080E3768(u8 i, s16 a, s16 b, s16 c, s16 d, u8 e) {
    s16 x;
    s16 yn;
    s16 n;
    u8 t;
    s32 k;
    s16 y;
    s16 yb;
    u16* buf;
    u16* w;
    s32 v;
    UnkStruct_080DFB8C* q;
    s32 m;

    v = gUnk_02034F20[i].unk_04;
    buf = EwramAlloc(96);
    w = buf + c;
    y = d;
    t = func_080E300C(i, c, y);
    k = t;
    q = func_080E08BC(c, y);
    func_080E0900(q, t, v);
    *w++ = y;

    for (x = c + 1; x < b - 1; x++) {
        t = func_080E300C(i, x, y);

        if (t == 11) {
            if (y <= 3) {
                t = 6;
            } else if (i == 0) {
                if (e == 2) {
                    t = func_080E2F48(a, b, x, 1);
                } else if (e == 3) {
                    t = func_080E2F98(a, b, x, 1);
                } else {
                    t = func_080E2E24(a, b, x);
                }
            } else {
                t = func_080E2E24(a, b, x);
            }
        }

        y = func_080E1194(k, t, y);
        k = t;
        q = func_080E08BC(x, y);
        func_080E0900(q, t, v);
        *w++ = y;
    }

    y = func_080E1194(k, 6, y);
    q = func_080E08BC(x, y);
    func_080E0900(q, 6, v);
    q->unk_00 |= 0x10;
    *w = y;
    w = buf + c;
    y = d;
    t = func_080E300C(i, c, y);
    k = t;
    w--;

    for (x = c - 1; x > a; x--) {
        t = func_080E300C(i, x, y);

        if (t == 11) {
            if (y <= 3) {
                t = 4;
            } else if (i == 0) {
                if (e == 2) {
                    t = func_080E2F48(a, b, x, 1);
                } else if (e == 3) {
                    t = func_080E2F98(a, b, x, 1);
                } else {
                    t = func_080E2E24(a, b, x);
                }
            } else {
                t = func_080E2E24(a, b, x);
            }
        }

        y = func_080E1204(k, t, y);
        k = t;
        q = func_080E08BC(x, y);
        func_080E0900(q, t, v);
        *w-- = y;
    }

    n = func_080E1204(k, 4, y);
    q = func_080E08BC(x, n);
    func_080E0900(q, 4, v);
    q->unk_00 |= 0x10;
    yb = b - a + *(buf + b - a - 1);
    y = n + 1;
    q = func_080E08BC(a, y);
    k = 5;
    func_080E0900(q, 5, v);
    q->unk_00 |= 0x10;
    w = buf + 1;

    for (x = a + 1; x < b - 1; x++) {
        yn = func_080E1194(k, 1, y);

        if (b - x == 2 && yb - yn == 2) {
            t = 5;
        } else if (yb - yn == 1) {
            t = 1;
        } else if (yn >= yb) {
            t = 3;
        } else if (yn - w[1] < gUnk_0203C7B0.unk_05) {
            t = 5;
        } else if (yn - w[1] > gUnk_0203C7B0.unk_06) {
            t = 3;
        } else if (yn - w[1] == gUnk_0203C7B0.unk_05 || yn - w[1] == gUnk_0203C7B0.unk_06) {
            t = func_080E2F14(x, w[0]);
        } else if (e == 2) {
            t = func_080E2F48(a, b, x, 0);
        } else if (e == 3) {
            t = func_080E2F98(a, b, x, 0);
        } else {
            t = func_080E2E9C(a, b, x);
        }

        if (yn >= gUnk_02034F2A - 1 && t == 5) {
            t = 1;
        }

        y = func_080E1194(k, t, y);
        k = t;
        q = func_080E08BC(x, y);
        func_080E0900(q, t, v);
        w++;
        yb--;
    }

    m = func_080E1194(k, 3, y);
    q = func_080E08BC(x, m);
    func_080E0900(q, 3, v);
    q->unk_00 |= 0x10;
    EwramFree(buf);
}
#else
INCLUDE_ASM("map/func_080E3768.s");
#endif

#ifdef NON_MATCHING
void func_080E3C1C(s32 a, s16* px, s16* py, s16* pz, s16 lo, s16 hi) {
    s32 x = lo + GetRandom() % (hi - lo);
    s32 n;

    for (n = 0; n < hi - lo; n++) {
        s32 j;

        for (j = gUnk_02034F2A - 1; j >= 0; j--) {
            UnkStruct_080DFB8C* p = func_080E08BC(x, j);

            if (p->unk_02 == a) {
                *px = x;
                *py = j;
                *pz = (p->unk_08 >> 11) / 2;
                return;
            }

            if (p->unk_02 != 11) {
                break;
            }
        }

        x++;

        if (x == hi) {
            x = lo;
        }
    }
}
#else
INCLUDE_ASM("map/func_080E3C1C.s");
#endif
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

u8 func_080E3D80(s16* a, s16* b, s16* c, s16* d) {
    u16 x1 = 0;
    u16 y1 = 0;
    u16 x2 = 0;
    u16 y2 = 0;
    s32 z1 = 0;
    s32 z2 = 0;
    s32 found = 0;
    s32 x;
    s32 y;
    UnkStruct_080DFB8C* p;

    for (x = 0; x < gUnk_02034F28; x++) {
        for (y = gUnk_02034F2A - 1; y >= 0; y--) {
            p = func_080E08BC((s16)x, (s16)y);

            if (p->unk_02 == 3) {
                x1 = x;
                y1 = y;
                z1 = p->unk_08;
                found = 1;
                break;
            }

            if (p->unk_02 != 11) {
                break;
            }
        }

        if (found != 0) {
            break;
        }
    }

    found = 0;

    for (x = gUnk_02034F28 - 1; x >= 0; x--) {
        for (y = gUnk_02034F2A - 1; y >= 0; y--) {
            p = func_080E08BC((s16)x, (s16)y);

            if (p->unk_02 == 5) {
                x2 = x + 1;
                y2 = y;
                z2 = p->unk_08;
                found = 1;
                break;
            }

            if (p->unk_02 != 11) {
                break;
            }
        }

        if (found != 0) {
            break;
        }
    }

    if ((s16)y1 <= gUnk_02034F2A - gUnk_02034F2A / 4 &&
        (s16)y2 <= gUnk_02034F2A - gUnk_02034F2A / 4 && (s16)x2 - (s16)x1 > 4) {
        *a = x1;
        *b = x2;

        if (z1 > z2) {
            *d = z1 / 16 >> 8;
            *c = y1;
            return 1;
        }

        *d = z2 / 16 >> 8;
        *c = y2;
        return 2;
    }

    return 0;
}

void func_080E3EFC(void) {
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    s16 v;

    d = gUnk_02034F28 / 2;
    b = gUnk_02034F2A / 4;
    d = gUnk_02034F28 - d;
    a = gUnk_02034F28;
    func_080E3060(0, d, a, 0);
    func_080E309C(0, d, a, b, 2);
    func_080E3CD4(5, &a, &b, &c, 0, gUnk_02034F28);
    v = gUnk_0203C7B0.unk_03 + GetRandom() % (gUnk_0203C7B0.unk_04 - gUnk_0203C7B0.unk_03 + 1);
    func_080E3060(1, 0, a + 1, v + c);
    func_080E3400(1, 0, a + 1, v + b, 0);
}

void func_080E3FD4(void) {
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    s16 t;
    s16 v;
    s32 k;

    t = GetRandom() % (gUnk_02034F28 - 7) + 4;
    a = GetRandom() % (gUnk_02034F28 - t - 3) + 2;
    d = a + t;
    b = gUnk_02034F2A / 4;
    func_080E3060(0, a, d, 0);
    func_080E309C(0, a, d, b, k = 0);

    if (GetRandom() % 100 < 50) {
        func_080E3C1C(3, &a, &b, &c, k, gUnk_02034F28);
        v = gUnk_0203C7B0.unk_03 + GetRandom() % (gUnk_0203C7B0.unk_04 - gUnk_0203C7B0.unk_03 + 1);
        func_080E3060(1, a, gUnk_02034F28, v + c);
        func_080E309C(1, a, gUnk_02034F28, v + b, k);
        func_080E3CD4(5, &d, &b, &c, k, gUnk_02034F28);
        v = gUnk_0203C7B0.unk_03 + GetRandom() % (gUnk_0203C7B0.unk_04 - gUnk_0203C7B0.unk_03 + 1);
        func_080E3060(2, 0, d + 1, v + c);
        func_080E3400(2, 0, d + 1, v + b, k);
    } else {
        func_080E3CD4(5, &d, &b, &c, k, gUnk_02034F28);
        v = gUnk_0203C7B0.unk_03 + GetRandom() % (gUnk_0203C7B0.unk_04 - gUnk_0203C7B0.unk_03 + 1);
        func_080E3060(1, 0, d + 1, v + c);
        func_080E3400(1, 0, d + 1, v + b, k);
        func_080E3C1C(3, &a, &b, &c, k, gUnk_02034F28);
        v = gUnk_0203C7B0.unk_03 + GetRandom() % (gUnk_0203C7B0.unk_04 - gUnk_0203C7B0.unk_03 + 1);
        func_080E3060(2, a, gUnk_02034F28, v + c);
        func_080E309C(2, a, gUnk_02034F28, v + b, k);
    }
}

void func_080E4244(void) {
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    s16 t;
    s16 v;

    t = GetRandom() % (gUnk_02034F28 - 9) + 6;
    a = (gUnk_02034F28 - t) / 2;
    d = a + t;
    b = gUnk_02034F2A / 4;
    func_080E3060(0, a, d, 0);
    func_080E309C(0, a, d, b, 2);

    if (GetRandom() % 100 < 50) {
        func_080E3C1C(3, &a, &b, &c, 0, gUnk_02034F28);
        v = gUnk_0203C7B0.unk_03 + GetRandom() % (gUnk_0203C7B0.unk_04 - gUnk_0203C7B0.unk_03 + 1) + 10;
        func_080E3060(1, a, gUnk_02034F28, v + c);
        func_080E309C(1, a, gUnk_02034F28, v + b, 2);
        func_080E3CD4(5, &d, &b, &c, 0, gUnk_02034F28);
        v = gUnk_0203C7B0.unk_03 + GetRandom() % (gUnk_0203C7B0.unk_04 - gUnk_0203C7B0.unk_03 + 1);
        func_080E3060(2, 0, d + 1, v + c);
        func_080E3400(2, 0, d + 1, v + b, 2);
    } else {
        func_080E3CD4(5, &d, &b, &c, 0, gUnk_02034F28);
        v = gUnk_0203C7B0.unk_03 + GetRandom() % (gUnk_0203C7B0.unk_04 - gUnk_0203C7B0.unk_03 + 1) + 10;
        func_080E3060(1, 0, d + 1, v + c);
        func_080E3400(1, 0, d + 1, v + b, 2);
        func_080E3C1C(3, &a, &b, &c, 0, gUnk_02034F28);
        v = gUnk_0203C7B0.unk_03 + GetRandom() % (gUnk_0203C7B0.unk_04 - gUnk_0203C7B0.unk_03 + 1);
        func_080E3060(2, a, gUnk_02034F28, v + c);
        func_080E309C(2, a, gUnk_02034F28, v + b, 2);
    }
}

void func_080E44A8(void) {
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    s16 t;
    s16 v;

    t = GetRandom() % (gUnk_02034F28 - 9) + 6;
    a = (gUnk_02034F28 - t) / 2;
    d = a + t;
    b = gUnk_02034F2A / 4;
    func_080E3060(0, a, d, 0);
    func_080E309C(0, a, d, b, 3);

    if (GetRandom() % 100 < 50) {
        func_080E3C1C(3, &a, &b, &c, 0, gUnk_02034F28);
        v = gUnk_0203C7B0.unk_03 + GetRandom() % (gUnk_0203C7B0.unk_04 - gUnk_0203C7B0.unk_03 + 1);
        func_080E3060(1, a, gUnk_02034F28, v + c);
        func_080E309C(1, a, gUnk_02034F28, v + b, 3);
        func_080E3CD4(5, &d, &b, &c, 0, gUnk_02034F28);
        v = gUnk_0203C7B0.unk_03 + GetRandom() % (gUnk_0203C7B0.unk_04 - gUnk_0203C7B0.unk_03 + 1);
        func_080E3060(2, 0, d + 1, v + c);
        func_080E3400(2, 0, d + 1, v + b, 3);
    } else {
        func_080E3CD4(5, &d, &b, &c, 0, gUnk_02034F28);
        v = gUnk_0203C7B0.unk_03 + GetRandom() % (gUnk_0203C7B0.unk_04 - gUnk_0203C7B0.unk_03 + 1);
        func_080E3060(1, 0, d + 1, v + c);
        func_080E3400(1, 0, d + 1, v + b, 3);
        func_080E3C1C(3, &a, &b, &c, 0, gUnk_02034F28);
        v = gUnk_0203C7B0.unk_03 + GetRandom() % (gUnk_0203C7B0.unk_04 - gUnk_0203C7B0.unk_03 + 1);
        func_080E3060(2, a, gUnk_02034F28, v + c);
        func_080E309C(2, a, gUnk_02034F28, v + b, 3);
    }
}

#ifdef NON_MATCHING
void func_080E470C(void) {
    s16 a;
    s16 b;
    s16 c;
    s16 t;
    s16 d;
    s16 v;
    s32 k;

    t = gUnk_02034F28 * 5 >> 3;
    a = (gUnk_02034F28 - t) / 2;
    d = a + t;
    b = gUnk_02034F2A / 4;
    func_080E3060(0, a, d, 0);
    func_080E309C(0, a, d, b, k = 3);
    func_080E3C1C(3, &a, &b, &c, 0, gUnk_02034F28);
    v = gUnk_0203C7B0.unk_03 + GetRandom() % (gUnk_0203C7B0.unk_04 - gUnk_0203C7B0.unk_03 + 1);
    func_080E3060(1, 0, gUnk_02034F28, v + c);
    func_080E3768(1, 0, gUnk_02034F28, a, v + b, k);
}
#else
INCLUDE_ASM("map/func_080E470C.s");
#endif

void func_080E47E8(u8 a, u8 b) {
    s32 i;

    for (i = a; i < b; i++) {
        s16 p;
        s16 q;
        s16 r;
        s16 s;
        s16 t;

        switch (func_080E3D80(&p, &q, &r, &s)) {
        case 1:
            t = gUnk_0203C7B0.unk_03 + GetRandom() % (gUnk_0203C7B0.unk_04 - gUnk_0203C7B0.unk_03 + 1);
            func_080E3060(i, p, q, t + s);
            func_080E309C(i, p, q, t + r, 0);
            break;
        case 2:
            t = gUnk_0203C7B0.unk_03 + GetRandom() % (gUnk_0203C7B0.unk_04 - gUnk_0203C7B0.unk_03 + 1);
            func_080E3060(i, p, q, t + s);
            func_080E3400(i, p, q, t + r, 0);
            break;
        default:
            return;
        }
    }
}

void func_080E4900(void) {
    switch (gUnk_0203C7B0.unk_00) {
    case 0:
        func_080E3060(0, 0, gUnk_02034F28, 0);
        func_080E309C(0, 0, gUnk_02034F28, gUnk_02034F2A / 4, 0);
        break;
    case 1:
        func_080E3EFC();
        break;
    case 2:
        func_080E3FD4();
        break;
    case 4:
        func_080E4244();
        func_080E47E8(3, 4);
        break;
    case 5:
        func_080E44A8();
        func_080E47E8(3, 4);
        break;
    case 6:
        func_080E470C();
        break;
    case 7:
        func_080E3060(0, 0, gUnk_02034F28, 0);
        func_080E309C(0, 0, gUnk_02034F28, gUnk_02034F2A / 4, 3);
        func_080E47E8(1, 12);
        break;
    case 3:
    default:
        func_080E3FD4();
        func_080E47E8(3, 12);
        break;
    }
}

void func_080E49DC(u16 a, u16 b) {
    s32 i;
    s32 n;
    void** p;

    gUnk_02034F34 = gUnk_09EF70D0[gUnk_0203C590.unk_04];
    gUnk_02034F28 = a;
    gUnk_02034F2A = b;
    p = &gUnk_02034F30;
    *p = EwramAlloc(0x1800);

    if (gGameState.unk_00 == 0) {
        gUnk_02034F1C = EwramAlloc(0x18000);
        gUnk_02034F20 = EwramAlloc(0x120);
        gUnk_02034F24 = EwramAlloc(0x20);
        n = gUnk_02034F28 * gUnk_02034F2A;

        for (i = 0; i < n; i++) {
            gUnk_02034F1C[i].unk_00 = 0;
            gUnk_02034F1C[i].unk_02 = 11;
            gUnk_02034F1C[i].unk_03 = 7;
            gUnk_02034F1C[i].unk_04 = 0;
            gUnk_02034F1C[i].unk_05 = 0;
            gUnk_02034F1C[i].unk_14 = 0;
            gUnk_02034F1C[i].unk_18 = 0;
            gUnk_02034F1C[i].unk_1C = 0;
        }

        for (i = 0; i < 12; i++) {
            gUnk_02034F20[i].unk_00 = 0;
            gUnk_02034F20[i].unk_02 = 0;
            gUnk_02034F20[i].unk_04 = 0x100000;
            gUnk_02034F20[i].unk_08 = 0;
            gUnk_02034F20[i].unk_0A = 0;
            gUnk_02034F20[i].unk_0C = 0;
            gUnk_02034F20[i].unk_0E = 11;
            gUnk_02034F20[i].unk_10 = -0x100000;
            gUnk_02034F20[i].unk_14 = 0x100000;
        }

        func_080E4900();
        func_080E1274();
        func_080E2520();
        func_080E2D80();
        func_080E14D0();
        func_080E13B0();
        func_080E1670();
        func_080E249C();
        func_080E1138();
        func_080E2C98();
    }

    gUnk_0203C7AC->unk_08 = gUnk_02034F2C;
    gUnk_0203C7AC->unk_0A = gUnk_02034F2E;
}

void func_080E4B34(void) {
    EwramFree(gUnk_02034F30);

    if (gGameState.unk_00 == 0) {
        EwramFree(gUnk_02034F1C);
        EwramFree(gUnk_02034F20);
        EwramFree(gUnk_02034F24);
    }
}

#ifdef NON_MATCHING
void func_080E4B78(s16 x, s16 y) {
    u16* p0 = gUnk_02034F30;
    u16* p1 = (u16*)((u8*)gUnk_02034F30 + 0x800);
    u16* p2 = (u16*)((u8*)gUnk_02034F30 + 0x1000);
    s16 x0 = x - 1;
    s16 yy = y - 1;
    s32 i;

    for (i = 0; i < 32; i++) {
        s16 v;
        s16 m;
        s16 ya;
        s16 xx;
        s32 j;

        if (yy < 0) {
            v = (yy - 8) / 2;
        } else {
            v = yy / 2;
        }

        m = yy % 2;
        ya = yy & 31;
        xx = x0;

        for (j = 31; j >= 0; j--) {
            UnkStruct_080DFB8C* e;
            s16 c;
            s16 n;
            s16 xa;

            if (xx < 0) {
                c = (xx - 8) / 4;
            } else {
                c = xx / 4;
            }

            n = xx % 4;
            xa = xx & 31;
            e = func_080E08BC(c, v);

            if (e != 0) {
                p0[ya * 32 + xa] = e->unk_14[m * 32 + n];

                if (e->unk_18 != 0) {
                    p1[ya * 32 + xa] = e->unk_18[m * 32 + n];
                } else {
                    p1[ya * 32 + xa] = 0;
                }

                if (e->unk_1C != 0) {
                    p2[ya * 32 + xa] = e->unk_1C[m * 32 + n];
                } else {
                    p2[ya * 32 + xa] = 0;
                }
            } else {
                p0[ya * 32 + xa] = 0;
                p1[ya * 32 + xa] = gUnk_02034F34->unk_1C[0x340];
                p2[ya * 32 + xa] = gUnk_02034F34->unk_20[0x110];
            }

            xx++;
        }

        yy++;
    }

    RequestDma3Copy(p0, GetBgScreenBase(3), 0x800);
    RequestDma3Copy(p1, GetBgScreenBase(2), 0x800);
    RequestDma3Copy(p2, GetBgScreenBase(1), 0x800);
}
#else
INCLUDE_ASM("map/func_080E4B78.s");
#endif

#ifdef NON_MATCHING
void func_080E4D68(s32 a, s32 b) {
    u16* dst;
    UnkStruct_080DFB8C* p;
    s16 x0;
    s16 cx;
    s16 cy;
    s16 sx;
    s16 sy;
    s16 mx;
    s16 my;
    s32 k;
    s32 ty;
    s32 i;
    s32 j;

    dst = (u16*)((u8*)gUnk_02034F30 + 0x1000);
    x0 = a;
    x0--;
    cy = b;
    cy--;

    for (i = 0; i < 32; i++) {
        if (cy < 0) {
            sy = (cy - 8) / 2;
        } else {
            sy = cy / 2;
        }

        my = cy % 2;
        ty = (cy & 31) << 5;
        cx = x0;

        for (j = 31; j >= 0; j--) {
            if (cx < 0) {
                sx = (cx - 8) / 4;
            } else {
                sx = cx / 4;
            }

            mx = cx % 4;
            k = cx & 31;
            p = func_080E08BC(sx, sy);

            if (p != 0) {
                if (p->unk_1C != 0) {
                    dst[k | ty] = p->unk_1C[my * 32 + mx];
                } else {
                    dst[k | ty] = 0;
                }
            } else {
                dst[k | ty] = gUnk_02034F34->unk_20[0x110];
            }
            cx++;
        }
        cy++;
    }

    RequestDma3Copy(dst, GetBgScreenBase(1), 0x800);
}
#else
INCLUDE_ASM("map/func_080E4D68.s");
#endif

void func_080E4EB0(u16* a, u16* b, u16* c, s16 d, s16 e) {
    UnkStruct_080DFB8C* cell;
    s16 hx;
    s16 mx;
    s16 hy;
    s16 my;
    s32 i;

    hx = (d < 0) ? (d - 8) / 4 : d / 4;
    mx = d % 4;

    for (i = 0; i < 32; i++) {
        hy = (e < 0) ? (e - 8) / 2 : e / 2;
        my = e % 2;
        cell = func_080E08BC(hx, hy);

        if (cell != 0) {
            a[i] = cell->unk_14[my * 32 + mx];

            if (cell->unk_18 != 0) {
                b[i] = cell->unk_18[my * 32 + mx];
            } else {
                b[i] = 0;
            }

            if (cell->unk_1C != 0) {
                c[i] = cell->unk_1C[my * 32 + mx];
            } else {
                c[i] = 0;
            }
        } else {
            a[i] = 0;
            b[i] = gUnk_02034F34->unk_1C[0x340];
            c[i] = gUnk_02034F34->unk_20[0x110];
        }
        e++;
    }
}

void func_080E4FF0(void* p, s16 a, s16 b) {
    void* q = (u8*)p + 0x40;
    void* r = (u8*)p + 0x80;

    func_080E4EB0(p, q, r, a, b);
    func_080045AC(p, GetBgScreenBase(3), a, b, 1);
    func_080045AC(q, GetBgScreenBase(2), a, b, 1);
    func_080045AC(r, GetBgScreenBase(1), a, b, 1);
}

void func_080E507C(u16* a, u16* b, u16* c, s16 d, s16 e) {
    UnkStruct_080DFB8C* cell;
    s16 hx;
    s16 mx;
    s16 hy;
    s16 my;
    s32 i;

    hy = (e < 0) ? (e - 8) / 2 : e / 2;
    my = e % 2;
    for (i = 0; i < 32; i++) {
        if (d < 0) {
            hx = (d - 8) / 4;
        } else {
            hx = d / 4;
        }
        mx = d % 4;
        cell = func_080E08BC(hx, hy);

        if (cell != 0) {
            a[i] = cell->unk_14[my * 32 + mx];

            if (cell->unk_18 != 0) {
                b[i] = cell->unk_18[my * 32 + mx];
            } else {
                b[i] = 0;
            }

            if (cell->unk_1C != 0) {
                c[i] = cell->unk_1C[my * 32 + mx];
            } else {
                c[i] = 0;
            }
        } else {
            a[i] = 0;
            b[i] = gUnk_02034F34->unk_1C[0x340];
            c[i] = gUnk_02034F34->unk_20[0x110];
        }
        d++;
    }
}

void func_080E51C0(void* p, s16 a, s16 b) {
    void* q = (u8*)p + 0x40;
    void* r = (u8*)p + 0x80;

    func_080E507C(p, q, r, a, b);
    func_080045AC(p, GetBgScreenBase(3), a, b, 0);
    func_080045AC(q, GetBgScreenBase(2), a, b, 0);
    func_080045AC(r, GetBgScreenBase(1), a, b, 0);
}

u8 func_080E524C(UnkStruct_080DFF1C* a, s32* b) {
    u16 h;
    u16 x;
    u16 y;
    s32 i;
    s32 j;

    h = gUnk_02034F2E - gUnk_02034F2C;
    x = GetRandom() % gUnk_02034F28;
    y = GetRandom() % h;

    for (i = 0; i < h; i++) {
        for (j = 0; j < gUnk_02034F28; j++) {
            u16 yy = y + gUnk_02034F2C;

            if ((*(u32*)func_080E08BC(x, yy) & 0xFF0340) == 0) {
                a->unk_00 = (x << 13) + 0x1000;
                *b = (yy << 12) + 0x800;
                return 1;
            }

            x++;
            x %= gUnk_02034F28;
        }

        y++;
        y %= h;
    }

    a->unk_00 = gUnk_02039BA0->unk_18;
    *b = gUnk_02039BA0->unk_1C + gUnk_02039BA0->unk_24;
    return 0;
}

u8 func_080E5354(UnkStruct_080DFF1C* a, s32* b) {
    u16 w = 6;
    u16 h = 8;
    u16 x;
    u16 y;
    s32 i;
    s32 k;

    x = GetRandom() % w;
    y = GetRandom() % h;

    for (k = 0; k < h; k++) {
        s32 ty = (gUnk_02039BA0->unk_04 / 16 >> 8) + 2;
        u16 yy = y + ty;

        for (i = 0; i < w; i++) {
            s32 tx = (gUnk_02039BA0->unk_00 / 32 >> 8) + 1;
            u16 xx = x + tx;
            s32* q = &gUnk_02039BA0->unk_18;
            UnkStruct_080DFB8C* e;

            if (q[0] < (xx * 32 + 80) << 8 && q[0] > (xx * 32 - 48) << 8 &&
                q[1] < (yy * 16 + 40) << 8 && q[1] > (yy * 16 - 24) << 8) {
                continue;
            }

            e = func_080E08BC(xx, yy);

            if (e != 0 && (*(u32*)e & 0xFF0340) == 0) {
                a->unk_00 = (xx << 13) + 0x1000;
                *b = (yy << 12) + 0x800;
                return 1;
            }

            x++;
            x %= w;
        }

        y++;
        y %= h;
    }

    func_080E524C(a, b);
    return 0;
}

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

void func_080E55E4(const u8* src) {
    s32 x;
    s32 y;

    for (y = 0; y < gUnk_0203C7AC->unk_06; y++) {
        for (x = 0; x < gUnk_0203C7AC->unk_04; x++) {
            UnkStruct_080DFB8C* e = (UnkStruct_080DFB8C*)func_080E55A4(x, y);

            e->unk_02 = src[gUnk_0203C7AC->unk_04 * y + x];
            e->unk_10 = func_080E8668(e->unk_02);

            switch (e->unk_02) {
            case 0:
                e->unk_08 = 0;
                e->unk_0C = 0;
                break;
            case 1:
            case 3:
            case 5:
                e->unk_08 = 0;
                e->unk_0C = 0x100000;
                break;
            case 2:
            case 4:
            case 6:
                e->unk_08 = -0x100000;
                e->unk_0C = 0;
                break;
            default:
                e->unk_08 = -0x100000;
                e->unk_0C = 0x100000;
                break;
            }
        }
    }
}

#ifdef NON_MATCHING
void func_080E56B4(void* a) {
    UnkStruct_080E56B4* q = a;
    UnkStruct_0203C7B8* e;
    UnkStruct_080DFF1C v;

    if (q == 0) {
        return;
    }
    e = gUnk_0203C7B8;

    while (q->unk_00 != 0xFF) {
        v.unk_00 = q->unk_04;
        v.z = 0;
        v.x = q->unk_08;
        v.y = 0;
        e->unk_00 = 2;
        e->unk_14 = &gUnk_09856FB4[q->unk_00];
        e->unk_04 = v;
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapGmk00, e);
        q++;
        e++;
    }

    if (gUnk_0203C590.unk_06 != 0xFE) {
        return;
    }

    if ((gGameState.flags & 8) || (s8)gGameState.floor != 0) {
        v.unk_00 = 0x18000;
        v.x = 0x11000;
    } else {
        v.unk_00 = 0x26000;
        v.x = 0x12000;
    }

    v.z = 0;
    v.y = 0;
    e->unk_00 = 0;
    e->unk_14 = &gUnk_0984C1CC;
    e->unk_04 = v;
    TaskCreate(gUnk_02039BA0->unk_78, gUnk_0984C1CC.unk_24, e);
    e++;

    if (func_080DF750() != 0) {
        if ((gGameState.flags & 8) || (s8)gGameState.floor != 0) {
            v.unk_00 = 0x1F000;
            v.x = 0x14000;
        } else {
            v.unk_00 = 0x2D000;
            v.x = 0x15000;
        }

        v.z = 0;
        v.y = 0;
        e->unk_00 = 0;
        e->unk_14 = &gUnk_0984C23C;
        e->unk_04 = v;
        TaskCreate(gUnk_02039BA0->unk_78, gUnk_0984C23C.unk_24, e);
    }
}
#else
INCLUDE_ASM("map/func_080E56B4.s");
#endif

void func_080E5800(void) {
    u16 sx;
    u16 sy;

    gUnk_02039BA0->unk_00 = gUnk_02039BA0->unk_08 - 0x7800;
    gUnk_02039BA0->unk_04 = gUnk_02039BA0->unk_0C - 0x6000;
    sx = (gUnk_02039BA0->unk_00 / 8) >> 8;
    sy = (gUnk_02039BA0->unk_04 / 8) >> 8;
    func_080051C4(3, sx, sy);
    func_080051C4(2, sx, sy);
    func_080051C4(1, sx, sy);
}

void func_080E5868(UnkStruct_09EF70D0* p) {
    s32 i;
    s32 n;

    gUnk_02034F38 = EwramAlloc(0x18000);
    n = gUnk_0203C7AC->unk_04 * gUnk_0203C7AC->unk_06;

    for (i = 0; i < n; i++) {
        ((UnkStruct_080DFB8C*)gUnk_02034F38)[i].unk_00 = 0;
        ((UnkStruct_080DFB8C*)gUnk_02034F38)[i].unk_02 = 11;
        ((UnkStruct_080DFB8C*)gUnk_02034F38)[i].unk_03 = 7;
        ((UnkStruct_080DFB8C*)gUnk_02034F38)[i].unk_04 = 0;
        ((UnkStruct_080DFB8C*)gUnk_02034F38)[i].unk_05 = 0;
        ((UnkStruct_080DFB8C*)gUnk_02034F38)[i].unk_14 = 0;
        ((UnkStruct_080DFB8C*)gUnk_02034F38)[i].unk_18 = 0;
        ((UnkStruct_080DFB8C*)gUnk_02034F38)[i].unk_1C = 0;
    }
    func_080E55E4((const u8*)p->unk_28);
}

void func_080E58E4(void) {
    EwramFree(gUnk_02034F38);
}

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

u8 func_080E59D8(UnkStruct_080E5B90* w) {
    UnkStruct_080DFF1C* d = &w->unk_08;
    UnkStruct_02034F20* q = func_080E54A0(1);
    u16 wd = q->unk_02 - q->unk_00 - 2;
    u16 ht = gUnk_0203C7AC->unk_0A - gUnk_0203C7AC->unk_08 - 2;
    s32 i;

    for (i = 0; i < ht; i++) {
        s16 y = gUnk_0203C7AC->unk_08 + i;
        s32 j;

        for (j = 0; j < wd; j++) {
            s32 x = (s16)(q->unk_00 + j);
            UnkStruct_080DFB8C* e = func_080E548C(x, y);

            if (e->unk_0C == q->unk_04 && (e->unk_00 & 0x20)) {
                s32 t;
                s32 v;

                if (e->unk_02 == 4) {
                    w->unk_18 = 0x53;
                    v = (x << 13) + 0x1800;
                } else if (e->unk_02 == 6) {
                    w->unk_18 = 0xAD;
                    v = (x << 13) + 0x800;
                } else {
                    continue;
                }

                d->unk_00 = v;
                v = y << 12;
                d->x = v + 0x1800;
                d->y = 0;
                t = func_080DFF30(d);
                d->z = t;
                d->y = t;
                d->x -= t;
                return 1;
            }
        }
    }
    return 0;
}

u8 func_080E5AC8(UnkStruct_080E5B90* w) {
    UnkStruct_080DFF1C* d = &w->unk_08;
    UnkStruct_02034F20* q = func_080E54A0(0);
    u16 wd = q->unk_02 - q->unk_00 - 2;
    u16 ht = gUnk_0203C7AC->unk_0A - gUnk_0203C7AC->unk_08 - 2;
    s32 i;

    for (i = 0; i < ht; i++) {
        s16 y = gUnk_0203C7AC->unk_08 + i;
        s32 j;

        for (j = 0; j < wd; j++) {
            s32 x = (s16)(q->unk_00 + j);

            if (func_080E548C(x, y)->unk_00 & 0x80) {
                s32 t;

                d->unk_00 = x << 13;
                d->x = y << 12;
                d->y = 0;
                t = func_080DFF30(d);
                d->z = t;
                d->x -= t;
                d->y = t - 0x2000;
                return 1;
            }
        }
    }
    return 0;
}

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
    func_08005974(p->anim, q->unk_0C, a, q->unk_04, q->unk_00);
    func_08002A10(p->tiles, q->unk_08);
}

void func_080E5DEC(UnkStruct_080E590C* p) {
    if (gUnk_02039BA0->unk_70 & 0x10000) {
        if (func_08005AC4(p->anim)) {
            return;
        }
    } else {
        if (func_08005AC4(p->anim)) {
            gUnk_02039BA0->unk_70 |= 0x10000;
        }
    }
    p->gfx = AnimUpdate(p->anim);
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

void func_080E6394(UnkStruct_080E590C* p, UnkStruct_080E5B90* q) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&p->unk_08;
    UnkStruct_0984BC9C* d = q->unk_00;

    p->unk_00 = d;
    p->unk_CC = q->unk_04;
    p->unk_04 = 0;
    p->unk_E0 = 30;
    e->unk_00 = q->unk_08;
    e->unk_14 = q->unk_18;
    e->unk_10 = q->unk_1C;
    e->unk_1A = d->unk_0A;
    e->unk_34 = 0;
    e->unk_30 = 1;
    p->unk_C8 = d->unk_0C;
    p->unk_CA = d->unk_0A;
    p->unk_D0 = 0;
    p->unk_D2 = 0;
    p->unk_D4 = e->unk_00.unk_00;
    p->unk_D8 = e->unk_00.x;
    p->unk_DC = e->unk_00.y;
    gUnk_02034F40++;
    gUnk_02034F41 += d->unk_08;
    p->tiles = AllocObjTiles(d->unk_08 * 32, 0);
    p->palette = LoadObjPalette(d->unk_04, 32);
    p->gfx = 0;
    AnimInit((AnimState*)&p->anim, 0, 0);
    TaskPoolInit((TaskPool*)&p->unk_E4, 2);

    if ((d->unk_14 & 1) == 0) {
        TaskCreate(&p->unk_E4, &gTaskDescFldShadow, e);
    }

    if (d->unk_14 & 8) {
        p->unk_04 |= 2;
        func_080122AC(&p->unk_48, 11, d->unk_0C, d->unk_0A);
    } else {
        func_080122AC(&p->unk_48, 3, d->unk_0C, d->unk_0A);
    }
    func_08012324(&p->unk_48, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
    func_08012614(&p->unk_48, 1);
    func_080E5CD4(p);
}

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

u8 func_080E6634(u8 a) {
    u8 r;

    switch (gUnk_0203C590.unk_04) {
    case 1:
        r = GetRandom() % 12 + 2;
        break;
    case 2:
        r = GetRandom() % 2;
        break;
    case 4:
        r = GetRandom() % 3 + 14;
        break;
    case 5:
        r = GetRandom() % 5 + 17;
        break;
    case 3:
        r = GetRandom() % 5 + 35;
        break;
    case 8:
        r = GetRandom() % 5 + 40;
        break;
    case 7:
        r = GetRandom() % 7 + 45;
        break;
    case 9:
        r = GetRandom() % 5 + 52;
        break;
    case 10:
        r = GetRandom() % 2 + 57;
        break;
    case 12:
        r = GetRandom() % 2 + 63;
        break;
    case 6:
        if (a <= 7) {
            switch (GetRandom() % 5) {
            case 2:
            case 3:
                r = GetRandom() % 3 != 0 ? 31 : 34;
                break;
            case 0:
            case 1:
                r = GetRandom() % 3 != 0 ? 30 : 33;
                break;
            default:
                r = GetRandom() % 3 != 0 ? 29 : 32;
                break;
            }
        } else {
            r = GetRandom() % 7 + 22;
        }
        break;
    default:
        r = GetRandom() % 3 + 59;
        break;
    }
    return r;
}

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

s32 func_080E6B24(UnkStruct_080DFF1C* p) {
    u16 w = gUnk_0203C7AC->unk_04 - 2;
    u16 h = gUnk_0203C7AC->unk_0A - gUnk_0203C7AC->unk_08 - 2;
    s16 rx = GetRandom() % w;
    s16 ry = GetRandom() % h;
    s32 i;
    s32 j;

    for (j = 0; j < h; j++) {
        s16 sy = gUnk_0203C7AC->unk_08 + ry;

        for (i = 0; i < w; i++) {
            if ((u8)func_080E6804(rx, sy) != 0 && (u8)func_080E68E4(rx, sy, 2, 2, 0) != 0) {
                func_080E6998(rx, sy, 2, 2);
                func_080DFF5C(p, rx, sy, 2, 2);
                return 1;
            }

            rx = (s16)(rx + 1) % w;
        }

        ry = (ry != 0 ? ry : h) - 1;
    }

    return 0;
}

s32 func_080E6C2C(UnkStruct_080DFF1C* p) {
    s16 ry;
    s16 rx;
    s16 sy;
    u16 h;
    u16 w;
    s32 i;
    s32 j;

    w = gUnk_0203C7AC->unk_04 - 2;
    h = gUnk_0203C7AC->unk_0A - gUnk_0203C7AC->unk_08 - 3;
    rx = GetRandom() % w;
    ry = GetRandom() % h;

    for (j = 0; j < h; j++) {
        sy = gUnk_0203C7AC->unk_08 + ry;

        for (i = 0; i < w; i++) {
            if ((u8)func_080E6804(rx, sy) != 0 && func_080E68A4(rx, sy, 8) != 0) {
                s32 y1 = (s16)(sy + 1);

                if (func_080E68A4(rx, y1, 4) != 0) {
                    s32 y2 = (s16)(sy + 2);

                    if (func_080E68A4(rx, y2, 0) != 0) {
                        s32 x1 = (s16)(rx + 1);

                        if (func_080E68A4(x1, sy, 4) != 0 && func_080E68A4(x1, y1, 0) != 0 &&
                            func_080E68A4(x1, y2, 0) != 0 && (u8)func_080E6968(rx, sy, 3) != 0) {
                            func_080E6998(rx, sy, 2, 3);
                            func_080DFF5C(p, rx, sy, 2, 3);
                            return 1;
                        }
                    }
                }
            }

            rx = (s16)(rx + 1) % w;
        }

        ry = (ry != 0 ? ry : h) - 1;
    }

    return 0;
}

s32 func_080E6DB0(UnkStruct_080DFF1C* p) {
    s16 x;
    s16 y;
    s16 cy;
    u16 n;
    u16 m;
    s32 i;
    s32 j;

    n = gUnk_0203C7AC->unk_04 - 1;
    m = gUnk_0203C7AC->unk_0A - gUnk_0203C7AC->unk_08 - 4;
    x = GetRandom() % n;
    y = GetRandom() % m;

    for (i = 0; i < m; i++) {
        cy = gUnk_0203C7AC->unk_08 + y;

        for (j = 0; j < n; j++) {
            if ((u8)func_080E6804(x, cy) != 0) {
                if (func_080E68A4(x, cy, 4) != 0) {
                    if (func_080E68A4(x, cy + 1, 0) != 0) {
                        if (func_080E68A4(x, cy + 2, 0) != 0) {
                            if (func_080E68A4(x, cy + 3, 0) != 0) {
                                if ((u8)func_080E6968(x, cy, 3) != 0) {
                                    func_080E6998(x, cy, 1, 4);
                                    func_080DFF5C(p, x, cy, 1, 4);
                                    return 1;
                                }
                            }
                        }
                    }
                }
            }
            x++;
            x %= n;
        }
        y = (y != 0 ? y : m) - 1;
    }
    return 0;
}

s32 func_080E6F04(UnkStruct_080DFF1C* p) {
    s16 ry;
    s16 rx;
    s16 sy;
    u16 h;
    u16 w;
    s32 i;
    s32 j;

    w = gUnk_0203C7AC->unk_04 - 2;
    h = gUnk_0203C7AC->unk_0A - gUnk_0203C7AC->unk_08 - 3;
    rx = GetRandom() % w;
    ry = GetRandom() % h;

    for (j = 0; j < h; j++) {
        sy = gUnk_0203C7AC->unk_08 + ry;

        for (i = 0; i < w; i++) {
            if ((u8)func_080E6804(rx, sy) != 0 && func_080E68A4(rx, sy, 6) != 0) {
                s32 y1 = (s16)(sy + 1);

                if (func_080E68A4(rx, y1, 0) != 0) {
                    s32 y2 = (s16)(sy + 2);

                    if (func_080E68A4(rx, y2, 0) != 0) {
                        s32 x1 = (s16)(rx + 1);

                        if (func_080E68A4(x1, sy, 9) != 0 && func_080E68A4(x1, y1, 6) != 0 &&
                            func_080E68A4(x1, y2, 0) != 0 && (u8)func_080E6968(rx, sy, 3) != 0) {
                            func_080E6998(rx, sy, 2, 3);
                            func_080DFF5C(p, rx, sy, 2, 3);
                            return 1;
                        }
                    }
                }
            }

            rx = (s16)(rx + 1) % w;
        }

        ry = (ry != 0 ? ry : h) - 1;
    }

    return 0;
}

s32 func_080E7088(UnkStruct_080DFF1C* p) {
    s16 ry;
    s16 rx;
    s16 sy;
    u16 h;
    u16 w;
    s32 i;
    s32 j;

    w = gUnk_0203C7AC->unk_04 - 3;
    h = gUnk_0203C7AC->unk_0A - gUnk_0203C7AC->unk_08 - 3;
    rx = GetRandom() % w;
    ry = GetRandom() % h;

    for (j = 0; j < h; j++) {
        sy = gUnk_0203C7AC->unk_08 + ry;

        for (i = 0; i < w; i++) {
            if ((u8)func_080E6804(rx, sy) != 0 && (u8)func_080E68E4(rx, sy, 3, 3, 8) != 0) {
                u16 a;
                u16 b;

                if ((u8)func_080E6A80(rx, sy, 3) == 0) {
                    continue;
                }

                a = func_080E6A14(rx, (s16)(sy + 2));
                b = func_080E6A14((s16)(rx + 2), sy);

                if (a == b && a > 8) {
                    func_080E6998(rx, sy, 3, 3);
                    func_080DFF5C(p, rx, (s16)(a + sy), 3, 3);
                    p->y -= a << 12;
                    return 1;
                }
            }

            rx = (s16)(rx + 1) % w;
        }

        ry = (ry != 0 ? ry : h) - 1;
    }

    return 0;
}

s32 func_080E71F0(UnkStruct_080DFF1C* p) {
    s16 ry;
    s16 rx;
    s16 sy;
    u16 h;
    u16 w;
    s32 i;
    s32 j;

    w = gUnk_0203C7AC->unk_04 - 3;
    h = gUnk_0203C7AC->unk_0A - gUnk_0203C7AC->unk_08 - 3;
    rx = GetRandom() % w;
    ry = GetRandom() % h;

    for (j = 0; j < h; j++) {
        sy = gUnk_0203C7AC->unk_08 + ry;

        for (i = 0; i < w; i++) {
            if ((u8)func_080E6804(rx, sy) != 0 && (u8)func_080E68E4(rx, sy, 3, 3, 9) != 0) {
                u16 a;
                u16 b;

                if ((u8)func_080E6A80(rx, sy, 3) == 0) {
                    continue;
                }

                a = func_080E6A14(rx, sy);
                b = func_080E6A14((s16)(rx + 2), (s16)(sy + 2));

                if (a == b && a > 8) {
                    func_080E6998(rx, sy, 3, 3);
                    func_080DFF5C(p, rx, (s16)(a + sy), 3, 3);
                    p->y -= a << 12;
                    return 1;
                }
            }

            rx = (s16)(rx + 1) % w;
        }

        ry = (ry != 0 ? ry : h) - 1;
    }

    return 0;
}

s32 func_080E7358(UnkStruct_080DFF1C* p) {
    s16 ry;
    s16 rx;
    s16 sy;
    u16 h;
    u16 w;
    s32 i;
    s32 j;

    w = gUnk_0203C7AC->unk_04 - 2;
    h = gUnk_0203C7AC->unk_0A - gUnk_0203C7AC->unk_08 - 2;
    rx = GetRandom() % w;
    ry = GetRandom() % h;

    for (j = 0; j < h; j++) {
        sy = gUnk_0203C7AC->unk_08 + ry;

        for (i = 0; i < w; i++) {
            if ((u8)func_080E6804(rx, sy) != 0 && func_080E68A4(rx, sy, 0) != 0) {
                if (func_080E68A4(rx, (s16)(sy + 1), 3) != 0) {
                    if (func_080E68A4((s16)(rx + 1), sy, 3) != 0 &&
                        func_080E68A4((s16)(rx + 1), (s16)(sy + 1), 8) != 0) {
                        u16 a = func_080E6A14(rx, (s16)(sy + 1));
                        u16 b = func_080E6A14((s16)(rx + 1), sy);

                        if (a == b && a > 8) {
                            func_080E6998(rx, sy, 2, 2);
                            func_080DFF5C(p, rx, (s16)(a + sy), 2, 2);
                            p->y -= a << 12;
                            return 1;
                        }
                    }
                }
            }

            rx = (s16)(rx + 1) % w;
        }

        ry = (ry != 0 ? ry : h) - 1;
    }

    return 0;
}

s32 func_080E74D8(UnkStruct_080DFF1C* p) {
    s16 x;
    s16 y;
    s16 cy;
    u16 n;
    u16 m;
    u16 h;
    s32 i;
    s32 j;

    n = gUnk_0203C7AC->unk_04 - 1;
    m = gUnk_0203C7AC->unk_0A - gUnk_0203C7AC->unk_08 - 2;
    x = GetRandom() % n;
    y = GetRandom() % m;

    for (i = 0; i < m; i++) {
        cy = gUnk_0203C7AC->unk_08 + y;

        for (j = 0; j < n; j++) {
            if ((u8)func_080E6804(x, cy) != 0) {
                if (func_080E68A4(x, cy, 1) != 0) {
                    if (func_080E68A4(x, cy + 1, 7) != 0) {
                        h = func_080E6A14(x, cy);

                        if (h > 8) {
                            func_080E6998(x, cy, 1, 2);
                            func_080DFF5C(p, x, h + cy, 1, 2);
                            p->y -= h << 12;
                            return 1;
                        }
                    }
                }
            }
            x++;
            x %= n;
        }
        y = (y != 0 ? y : m) - 1;
    }
    return 0;
}

s32 func_080E7620(UnkStruct_080DFF1C* p) {
    s16 ry;
    s16 rx;
    s16 sy;
    u16 h;
    u16 w;
    s32 i;
    s32 j;

    w = gUnk_0203C7AC->unk_04 - 2;
    h = gUnk_0203C7AC->unk_0A - gUnk_0203C7AC->unk_08 - 2;
    rx = GetRandom() % w;
    ry = GetRandom() % h;

    for (j = 0; j < h; j++) {
        sy = gUnk_0203C7AC->unk_08 + ry;

        for (i = 0; i < w; i++) {
            if ((u8)func_080E6804(rx, sy) != 0 && func_080E68A4(rx, sy, 5) != 0) {
                s32 y1 = (s16)(sy + 1);

                if (func_080E68A4(rx, y1, 9) != 0) {
                    if (func_080E68A4((s16)(rx + 1), sy, 0) != 0 &&
                        func_080E68A4((s16)(rx + 1), y1, 5) != 0) {
                        u16 a = func_080E6A14(rx, sy);
                        u16 b = func_080E6A14((s16)(rx + 1), y1);

                        if (a == b && a > 8) {
                            func_080E6998(rx, sy, 2, 2);
                            func_080DFF5C(p, rx, (s16)(a + sy), 2, 2);
                            p->y -= a << 12;
                            return 1;
                        }
                    }
                }
            }

            rx = (s16)(rx + 1) % w;
        }

        ry = (ry != 0 ? ry : h) - 1;
    }

    return 0;
}

s32 func_080E77A4(UnkStruct_080DFF1C* p) {
    s16 ry;
    s16 rx;
    s16 sy;
    u16 h;
    u16 w;
    s32 i;
    s32 j;

    w = gUnk_0203C7AC->unk_04 - 2;
    h = gUnk_0203C7AC->unk_0A - gUnk_0203C7AC->unk_08 - 3;
    rx = GetRandom() % w;
    ry = GetRandom() % h;

    for (j = 0; j < h; j++) {
        sy = gUnk_0203C7AC->unk_08 + ry;

        for (i = 0; i < w; i++) {
            if ((u8)func_080E6804(rx, sy) != 0 && func_080E68A4(rx, sy, 2) != 0) {
                s32 y1 = (s16)(sy + 1);

                if (func_080E68A4(rx, y1, 0) != 0) {
                    s32 y2 = (s16)(sy + 2);

                    if (func_080E68A4(rx, y2, 0) != 0) {
                        s32 x1 = (s16)(rx + 1);

                        if (func_080E68A4(x1, sy, 2) != 0 && func_080E68A4(x1, y1, 0) != 0 &&
                            func_080E68A4(x1, y2, 0) != 0 && (u8)func_080E6968(rx, sy, 3) != 0) {
                            func_080E6998(rx, sy, 2, 3);
                            func_080DFF5C(p, rx, sy, 2, 3);
                            return 1;
                        }
                    }
                }
            }

            rx = (s16)(rx + 1) % w;
        }

        ry = (ry != 0 ? ry : h) - 1;
    }

    return 0;
}

s32 func_080E7928(UnkStruct_080DFF1C* p) {
    u16 w = gUnk_0203C7AC->unk_04 - 3;
    u16 h = gUnk_0203C7AC->unk_0A - gUnk_0203C7AC->unk_08 - 3;
    s16 rx = GetRandom() % w;
    s16 ry = GetRandom() % h;
    s32 i;
    s32 j;

    for (j = 0; j < h; j++) {
        s16 sy = gUnk_0203C7AC->unk_08 + ry;

        for (i = 0; i < w; i++) {
            if ((u8)func_080E6804(rx, sy) != 0 && (u8)func_080E68E4(rx, sy, 3, 3, 0) != 0) {
                func_080E6998(rx, sy, 3, 3);
                func_080DFF5C(p, rx, sy, 3, 3);
                return 1;
            }

            rx = (s16)(rx + 1) % w;
        }

        ry = (ry != 0 ? ry : h) - 1;
    }

    return 0;
}

s32 func_080E7A30(UnkStruct_080DFF1C* p) {
    u16 w = gUnk_0203C7AC->unk_04 - 4;
    u16 h = gUnk_0203C7AC->unk_0A - gUnk_0203C7AC->unk_08 - 4;
    s16 rx = GetRandom() % w;
    s16 ry = GetRandom() % h;
    s32 i;
    s32 j;

    for (j = 0; j < h; j++) {
        s16 sy = gUnk_0203C7AC->unk_08 + ry;

        for (i = 0; i < w; i++) {
            if ((u8)func_080E6804(rx, sy) != 0 && (u8)func_080E68E4(rx, sy, 4, 4, 0) != 0) {
                func_080E6998(rx, sy, 4, 4);
                func_080DFF5C(p, rx, sy, 4, 4);
                return 1;
            }

            rx = (s16)(rx + 1) % w;
        }

        ry = (ry != 0 ? ry : h) - 1;
    }

    return 0;
}

s32 func_080E7B38(UnkStruct_080DFF1C* p) {
    u16 w = gUnk_0203C7AC->unk_04 - 5;
    u16 h = gUnk_0203C7AC->unk_0A - gUnk_0203C7AC->unk_08 - 5;
    s16 rx = GetRandom() % w;
    s16 ry = GetRandom() % h;
    s32 i;
    s32 j;

    for (j = 0; j < h; j++) {
        s16 sy = gUnk_0203C7AC->unk_08 + ry;

        for (i = 0; i < w; i++) {
            if ((u8)func_080E6804(rx, sy) != 0 && (u8)func_080E68E4(rx, sy, 5, 5, 0) != 0) {
                func_080E6998(rx, sy, 5, 5);
                func_080DFF5C(p, rx, sy, 5, 5);
                return 1;
            }

            rx = (s16)(rx + 1) % w;
        }

        ry = (ry != 0 ? ry : h) - 1;
    }

    return 0;
}

s32 func_080E7C40(UnkStruct_080DFF1C* p) {
    UnkStruct_02034F20* e = func_080E54A0(0);
    u16 w = e->unk_02 - e->unk_00 - 2;
    u16 h = gUnk_0203C7AC->unk_0A - gUnk_0203C7AC->unk_08 - 2;
    s16 rx = GetRandom() % w;
    s16 ry = GetRandom() % h;
    s32 i;
    s32 j;

    for (j = 0; j < h; j++) {
        s16 sy = gUnk_0203C7AC->unk_08 + ry;

        for (i = 0; i < w; i++) {
            s32 sx = (s16)(e->unk_00 + rx);

            if ((u8)func_080E68E4(sx, sy, 2, 2, 0) != 0 && e->unk_04 == func_080E548C(sx, sy)->unk_0C) {
                func_080E6998(sx, sy, 2, 2);
                func_080DFF5C(p, sx, sy, 2, 2);
                return 1;
            }

            rx = (s16)(rx + 1) % w;
        }

        ry = (s16)(ry + 1) % h;
    }

    return 0;
}

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

#ifdef NON_MATCHING
void func_080E7E3C(void) {
    UnkStruct_080DFF1C w;
    UnkStruct_080DEE18* e;
    s32 i;

    e = func_080DEE18(gUnk_0203C590.unk_06);

    if (gUnk_0203C7AC->unk_0D == 10) {
        UnkStruct_080E7D80* q = &gUnk_0984C158;
        u8* n = &gUnk_02034F78;

        i = 1;

    lab:
        {
            func_080E7D64(&w, q->unk_15);

            if (e->unk_00 & 0x10) {
                gUnk_0203C7B8[*n].unk_00 = 10;
            } else {
                gUnk_0203C7B8[*n].unk_00 = 8;
            }

            gUnk_0203C7B8[*n].unk_14 = q;
            gUnk_0203C7B8[*n].unk_04 = w;
            gUnk_02034F7A += q->unk_08 >> 5;
            gUnk_02034F79++;
            (*n)++;
        }
        i--;

        if (i >= 0) {
            goto lab;
        }
    }

    if (gUnk_0203C7AC->unk_0D == 3 || gUnk_0203C7AC->unk_0D == 9 || gUnk_0203C7AC->unk_0D == 10 ||
        gUnk_0203C7AC->unk_0D == 22) {
        UnkStruct_080DFB8C* p;
        UnkStruct_080E7D80* q = &gUnk_0984C158;
        u16 v;

        func_080E7D64(&w, q->unk_15);
        v = e->unk_00 & 0x10;

        if (v != 0) {
            gUnk_0203C7B8[gUnk_02034F78].unk_00 = 2;
        } else {
            gUnk_0203C7B8[gUnk_02034F78].unk_00 = 0;
        }

        gUnk_0203C7B8[gUnk_02034F78].unk_14 = q;
        gUnk_0203C7B8[gUnk_02034F78].unk_04 = w;
        gUnk_02034F7A += q->unk_08 >> 5;
        gUnk_02034F79++;
        gUnk_02034F78++;
        p = func_080E67D4(w.unk_00, w.x + w.y);
        p->unk_00 |= 0x80;
    }
}
#else
INCLUDE_ASM("map/func_080E7E3C.s");
#endif

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

void func_080E80E0(void) {
    UnkStruct_080DFF1C w;
    UnkStruct_080E7D80* t;
    s32 i;
    s32 f;

    if (gUnk_0203C7AC->unk_0D == 6 || gUnk_0203C7AC->unk_0D == 9 || gUnk_0203C7AC->unk_0D == 11 ||
        gUnk_0203C7AC->unk_0D == 22 || gUnk_0203C7AC->unk_0D == 23) {
        return;
    }

    for (i = gUnk_02034F78; i <= 15; i++) {
        switch (gUnk_0203C590.unk_04) {
        case 10:
            t = &gUnk_09857A2C[0];
            break;
        case 4:
            t = &gUnk_09857A2C[1];
            break;
        case 2:
            t = &gUnk_09857A2C[2];
            break;
        case 6:
            t = &gUnk_09857A2C[3];
            break;
        case 8:
            t = GetRandom() % 2 ? &gUnk_09857A2C[4] : &gUnk_09857A2C[5];
            break;
        case 12:
            t = &gUnk_09857A2C[6];
            break;
        default:
            t = &gUnk_0984C190;
            break;
        }

        if (gUnk_02034F7A + t->unk_08 / 32 > 0x200) {
            return;
        }

        f = (u8)func_080E7D80(t->unk_00);

        if (f != 0 && gUnk_02034F79 > 5) {
            return;
        }

        if (func_080E7D64(&w, t->unk_15) == 0) {
            return;
        }

        gUnk_0203C7B8[gUnk_02034F78].unk_00 = 0;
        gUnk_0203C7B8[gUnk_02034F78].unk_14 = t;
        gUnk_0203C7B8[gUnk_02034F78].unk_04 = w;
        gUnk_02034F7A += t->unk_08 >> 5;
        gUnk_02034F78++;

        if (f != 0) {
            gUnk_02034F79++;
        }
    }
}

void func_080E826C(void) {
    s32 i;

    for (i = gUnk_02034F78; i < 16; i++) {
        UnkStruct_080DFF1C w;
        UnkStruct_080E7D80* e = &gUnk_09856FB4[func_080E6634(i)];
        u8 f = func_080E7DB8(e->unk_14, e->unk_04);
        u8 g;

        if (f != 0) {
            if ((e->unk_08 >> 5) + gUnk_02034F7A > 512) {
                continue;
            }
        }

        g = func_080E7D80(e->unk_00);

        if (g != 0) {
            if (gUnk_02034F79 > 5) {
                continue;
            }
        }

        if (func_080E7D64(&w, e->unk_15) == 0) {
            continue;
        }

        gUnk_0203C7B8[gUnk_02034F78].unk_00 = 0;
        gUnk_0203C7B8[gUnk_02034F78].unk_14 = e;
        gUnk_0203C7B8[gUnk_02034F78].unk_04 = w;
        gUnk_02034F78++;

        if (f != 0) {
            gUnk_02034F7A += e->unk_08 >> 5;
        }

        if (g != 0) {
            gUnk_02034F79++;
        }
    }
}

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

void func_080E83DC(s32 a, s32 b, s32 c) {
    u16 r;

    if (gGameState.flags & 8) {
        r = GetRandom() % 10000;
        if (r < 2500) {
            func_080E9034(0, 2, a, b, c);
        } else if (r < 6500) {
            func_080E9034(0, 5, a, b, c);
        } else if (r < 9000) {
            func_080E9034(1, 3, a, b, c);
        } else {
            func_080E9034(1, 5, a, b, c);
        }
    } else {
        r = GetRandom() % 10000;
        if (r < 2000) {
            func_080E9034(0, 2, a, b, c);
        } else if (r < 4000) {
            func_080E9034(0, 5, a, b, c);
        } else if (r < 6000) {
            func_080E9034(1, 3, a, b, c);
        } else if (r < 6500) {
            func_080E9034(1, 5, a, b, c);
        } else if (r < 8000) {
            func_080E9034(2, 5, a, b, c);
        } else {
            func_080E9034(3, 5, a, b, c);
        }
    }
}

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

void func_080E8864(UnkStruct_080E8864* p) {
    u16 w = gUnk_0203C7AC->unk_04 - p->unk_04 + 1;
    u16 h = gUnk_0203C7AC->unk_0A - gUnk_0203C7AC->unk_08 + 7;
    s16 y0 = gUnk_0203C7AC->unk_08 - 7;
    s32 i;

    for (i = 0; i < h; i++) {
        s16 y = y0 + i;
        s16 j;

        for (j = 0; j < w; j++) {
            if (func_080E87EC(j, y, (const UnkStruct_080E87EC*)p->unk_00)) {
                if (GetRandom() % 100 < p->unk_06) {
                    func_080E8724(j, y, p->unk_08, p->unk_0C);
                }
            }
        }
    }
}

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

void func_080E8B1C(UnkStruct_080E8B1C* p, UnkStruct_080E7D80* q) {
    p->unk_00 = q->unk_04;
    p->unk_04 = q->unk_08;
    p->unk_08 += q->unk_0A << 5;
    p->unk_10 = 0;
    p->unk_14 = q->unk_00;
    p->unk_18 = q->unk_00;
}

void func_080E8B40(UnkStruct_080E8B1C* p) {
    s16* q;
    u8 (*f)(UnkStruct_080E8B1C*);

    if (p->unk_14 == 0) {
        return;
    }

    do {
        q = p->unk_18;

        if (*q & 0x8000) {
            f = gUnk_09EF6A88[*(u8*)q];
        } else {
            f = func_080E8BE4;
        }
    } while (f(p));
}

void func_080E8B84(UnkStruct_080E8B1C* p) {
    if (p->unk_0C != 0) {
        RequestDma3Copy(p->unk_0C, p->unk_08, p->unk_04);
        p->unk_0C = 0;
    }
}

void func_080E8BA0(UnkStruct_080E8B1C* p) {
    func_080E8B40(p);
    func_080E8B84(p);
}

void func_080E8BB4(UnkStruct_080E8B1C* p) {
    p->unk_00 = 0;
    p->unk_08 = (u8*)GetBgCharBase(2) + 0x7800;
    p->unk_0C = 0;
    p->unk_10 = 0;
    p->unk_14 = 0;
    p->unk_18 = 0;
}

u8 func_080E8BD8(UnkStruct_080E8B1C* p) {
    p->unk_14 = 0;
    p->unk_18 = 0;
    return 0;
}

u8 func_080E8BE4(UnkStruct_080E8B1C* p) {
    UnkStruct_080E8B1C* w = p;
    s16* q;
    s16 n;

    if (p->unk_10 == 0) {
        p->unk_0C = (u8*)p->unk_00 + p->unk_04 * p->unk_18[1];
    }

    q = w->unk_18;
    n = *(u16*)q & 0x7FFF;

    if (n != 0) {
        w->unk_10++;

        if (w->unk_10 >= n) {
            w->unk_10 = 0;
            w->unk_18 = q + 2;
        }
    }
    return 0;
}

u8 func_080E8C30(UnkStruct_080E8B1C* p) {
    p->unk_18 = p->unk_14;
    return 1;
}

u8 func_080E8C38(u8 a, u8 b) {
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

u8 func_080E8D64(UnkStruct_080E8D64* p) {
    UnkStruct_02034F80* q;
    u8 n;

    if (func_080E8C38(gUnk_0203C7AC->unk_0F, gUnk_0203C7AC->unk_10) == 0) {
        if (p->unk_00 > 21) {
            return 0;
        }

        n = func_080DF548(gUnk_0203C590.unk_06);

        if (p->unk_02 == 0) {
            return 1;
        }
        return p->unk_02 > n;
    }

    q = func_080E8D1C(0);

    if (q->unk_00 != 0xFF) {
        if (q->unk_00 != p->unk_00) {
            return 0;
        }
    } else if (p->unk_00 > 21) {
        return 0;
    }

    if (q->unk_01 != 0 && q->unk_01 != p->unk_04) {
        return 0;
    }

    switch (q->unk_02) {
    case 1:
        return p->unk_02 >= q->unk_03;
    case 2:
        return p->unk_02 <= q->unk_03;
    case 3:
        return p->unk_02 == q->unk_03;
    case 4:
        return p->unk_02 != 0;
    }
    return 1;
}

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

#ifdef NON_MATCHING
void func_080E9078(s32 x, s32 y, s32 z) {
    UnkStruct_080E8E24* p = gUnk_09EF83C0[gGameState.world];
    UnkStruct_080E8E24* e;

    for (; p->unk_00[0] != 4; p++) {
        switch (p->unk_00[0]) {
        case 0:
            if (gUnk_0203C7AC->unk_0D == 22) {
                break;
            }

            e = &gUnk_0985814C[p->unk_00[1]];

            if (func_0800FC5C(e->unk_00[0]) == 1) {
                break;
            }

            func_0800FC14(e->unk_00[0]);
            func_080E8F50(e, 1, x, y, z);
            return;
        case 1:
            if (gUnk_0203C7AC->unk_0D == 22) {
                break;
            }

            e = &gUnk_098581EC[p->unk_00[1]];

            if (func_0800FBCC(e->unk_00[0]) == 1) {
                break;
            }

            func_0800FB2C(e->unk_00[0]);
            TaskCreate(gUnk_02039BA0->unk_C8, &gTaskDescMapPrzStock, e);
            return;
        case 2:
            if (gUnk_0203C7AC->unk_0D != 22) {
                break;
            }

            e = &gUnk_0985814C[p->unk_00[1]];

            if (func_0800FC5C(e->unk_00[0]) == 1) {
                break;
            }

            func_0800FC14(e->unk_00[0]);
            func_080E8F50(e, 1, x, y, z);
            gUnk_0203C590.unk_02 |= 0x40;
            return;
        case 3:
            if (gUnk_0203C7AC->unk_0D != 22) {
                break;
            }

            e = &gUnk_098581EC[p->unk_00[1]];

            if (func_0800FBCC(e->unk_00[0]) != 1) {
                func_0800FB2C(e->unk_00[0]);
                TaskCreate(gUnk_02039BA0->unk_C8, &gTaskDescMapPrzStock, e);
                gUnk_0203C590.unk_02 |= 0x40;
                return;
            }
            break;
        }
    }

    if ((gGameState.flags & 0x800) && gGameState.world == 12 && func_0800FC5C(16) != 0) {
        e = gUnk_09858184;

        if (func_0800FC5C(e->unk_00[0]) == 1) {
            e += 24;

            if (func_0800FC5C(e->unk_00[0]) == 1) {
                e++;

                if (func_0800FC5C(e->unk_00[0]) == 1) {
                    goto other;
                }
            }
        }

        func_0800FC14(e->unk_00[0]);
        func_080E8F50(e, 1, x, y, z);
        return;
    }

other:
    e = func_080E8E74(1);

    if (e != 0) {
        func_080E8F50(e, 1, x, y, z);
    }
}
#else
INCLUDE_ASM("map/func_080E9078.s");
#endif

s32 func_080E924C(void) {
    s32 i;
    u8* p;

    for (i = 1; i <= 11; i++) {
        UnkStruct_09EF8370** t = &gUnk_09EF8370[20];

        p = (u8*)t[i];

        while (p[0] != 4) {
            switch (p[0]) {
            case 2:
                if (func_0800FC5C((gUnk_0985814C + p[1])->unk_00[0]) != 1) {
                    return 0;
                }
                break;
            case 3:
                if (func_0800FBCC((gUnk_0985814C + 40 + p[1])->unk_00[0]) != 1) {
                    return 0;
                }
                break;
            }
            p += 4;
        }
    }
    return 1;
}

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

void func_080EAC60(u8 a, u32 b) {
    u16 d[6];
    s32 off;
    u16* q;
    s32 i;
    u32 t;

    a &= 1;
    t = b / 3600;
    d[0] = t / 10;
    d[1] = t - d[0] * 10;
    b -= t * 3600;
    t = b / 60;
    d[2] = t / 10;
    d[3] = t - d[2] * 10;
    b -= t * 60;
    d[4] = b / 10;
    d[5] = b - d[4] * 10;
    i = 0;
    off = a * 608 + 128;
    q = &d[0];

    while (i <= 5) {
        RequestDma3Copy((void*)&gUnk_09966064[*q * 32], (u8*)GetBgCharBase(1) + off + i * 32, 0x20);
        q++;
        i++;
    }
}

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

void func_080EAD84(u8 a) {
    UnkStruct_02039D6C* e;
    u8 i = gUnk_02034FDC->unk_33D != 0 ? a + 2 : a;
    e = &gUnk_02039D6C[i];

    if (e->unk_02 != 0) {
        func_080EAB20(i, 1, e->unk_00);
        gUnk_02034FDC->unk_160 = func_08065B6C((void*)func_080DF804(e->unk_01), &gUnk_02034FDC->unk_040);

        if (gUnk_02034FDC->unk_33D == 0) {
            LoadObjPaletteBank(gUnk_02034FDC->unk_03C->unk_06, &gUnk_099910C4[0xB40]);
        } else {
            LoadObjPaletteBank(gUnk_02034FDC->unk_03C->unk_06, &gUnk_099910C4[0xB80]);
        }
    } else {
        func_080EAB20(i, 1, 13);
        gUnk_02034FDC->unk_160 = 0;
    }

    if (gUnk_02034FDC->unk_33E == 0) {
        if (gUnk_02034FDC->unk_33D != 0) {
            LoadBgMap(1, &gUnk_09985F44[0x8800], 0x800);
        } else {
            LoadBgMap(1, &gUnk_09985F44[0x7800], 0x800);
        }

        SetBgScroll(1, 0, -9);
    } else {
        if (gUnk_02034FDC->unk_33D != 0) {
            LoadBgMap(1, &gUnk_09985F44[0x9000], 0x800);
        } else {
            LoadBgMap(1, &gUnk_09985F44[0x8000], 0x800);
        }

        SetBgScroll(1, 0, -6);
    }
}

void func_080EAEB0(u8 a) {
    u8 idx = gUnk_02034FDC->unk_33D != 0 ? a + 2 : a;
    UnkStruct_02039D6C* e = &gUnk_02039D6C[idx];

    if (e->unk_02 != 0) {
        func_080EAB20(idx, 0, e->unk_00);
    } else {
        func_080EAB20(idx, 0, 13);
    }

    gUnk_02034FDC->unk_160 = 0;
}

void func_080EAF10(void) {
    s32 t;
    s32 u;

    DrawSprite(128, gUnk_02034FDC->unk_008 >> 8, gUnk_09EF8D68[1], gUnk_02034FDC->unk_004,
        gUnk_02034FDC->unk_000, 0, 0xC00, 90);
    DrawSprite(128, gUnk_02034FDC->unk_00C >> 8, gUnk_09EF8D68[2], gUnk_02034FDC->unk_004,
        gUnk_02034FDC->unk_000, 0, 0xC00, 90);

    if (gUnk_02034FDC->unk_33D == 0) {
        DrawSprite(56, 112, ((void**)gUnk_09EDE8CC)[0], gUnk_02034FDC->unk_320,
            gUnk_02034FDC->unk_31C, 0, 0x400, 80);
        DrawSprite(72, 96, gUnk_09EEFF84[0], gUnk_02034FDC->unk_328, gUnk_02034FDC->unk_324, 0,
            0x401, 81);
        DrawSprite(40, 96, gUnk_09EEFEC0[0], gUnk_02034FDC->unk_330, gUnk_02034FDC->unk_32C, 0,
            0x400, 81);
    } else {
        DrawSprite(56, 112, gUnk_09EEF89C[0], gUnk_02034FDC->unk_338, gUnk_02034FDC->unk_334, 0,
            0x400, 81);
    }

    DrawSprite(0, 16, gUnk_098A8F28, gUnk_02034FDC->unk_014, gUnk_02034FDC->unk_010, 0, 0x400, 90);
    t = 45;
    u = gUnk_02034FDC->unk_33E * t;
    func_0805F1C0(&gUnk_02034FDC->unk_038, (gUnk_02034FDC->unk_162 + u) << 8);
    DrawSprite(76, gUnk_02034FDC->unk_038 >> 8, AnimGetGfx(&gUnk_02034FDC->unk_018),
        gUnk_02034FDC->unk_034, gUnk_02034FDC->unk_030, 0, 0, 70);
    func_080664D8(100, u + (gUnk_02034FDC->unk_162 + 22), &gUnk_02034FDC->unk_040,
        gUnk_02034FDC->unk_03C, 50, gUnk_02034FDC->unk_160);
    func_080664D8(
        (240 - func_08065B08(&gUnk_02034FDC->unk_168, gUnk_02034FDC->unk_318)) / 2, 134,
        &gUnk_02034FDC->unk_168, gUnk_02034FDC->unk_164, 50, gUnk_02034FDC->unk_318);
}

void func_080EB12C(UnkStruct_02034FDC* w) {
    u8 prev = w->unk_33E;

    if (GetKeysRepeat() & 0x40) {
        w->unk_33E = w->unk_33E != 0 ? w->unk_33E - 1 : 1;
        m4aSongNumStart(0x65);
    }

    if (GetKeysRepeat() & 0x80) {
        w->unk_33E = w->unk_33E == 0 ? w->unk_33E + 1 : 0;
        m4aSongNumStart(0x65);
    }

    if (prev != w->unk_33E) {
        func_080EAEB0(prev);
        func_080EAD84(w->unk_33E);
    }
}

void func_080EB1AC(UnkStruct_02034FDC* w) {
    if (w->unk_340 != 0) {
        ApproachValue(&w->unk_008, 0, w->unk_340);
        ApproachValue(&w->unk_00C, 0x9800, w->unk_340);
        w->unk_340--;
    } else {
        w->unk_344 = func_080EB1F4;
    }
}

void func_080EB1F4(UnkStruct_02034FDC* w) {
    func_080EB12C(w);

    if (GetKeysPressed() & 2) {
        m4aSongNumStart(0x68);
    } else {
        if (!(GetKeysPressed() & 9)) {
            return;
        }

        switch (w->unk_33E) {
        case 0:
            gGameState.flags &= ~0x10;
            break;
        case 1:
            gGameState.flags |= 0x10;
            break;
        }
        m4aSongNumStart(0xD3);
        w->unk_33C = 1;
    }
    w->unk_340 = 16;
    w->unk_344 = func_080EB27C;
}

void func_080EB27C(UnkStruct_02034FDC* w) {
    if (w->unk_340 != 0) {
        ApproachValue(&w->unk_008, -0x800, w->unk_340);
        ApproachValue(&w->unk_00C, 0xA000, w->unk_340);
        w->unk_340--;
    } else {
        func_08006184(0, 90);
        w->unk_344 = func_080EB2D0;
    }
}

void func_080EB2D0(UnkStruct_02034FDC* w) {
    if ((u8)func_08006314() != 0) {
        return;
    }

    if (w->unk_33C != 0) {
        if (w->unk_33D != 0) {
            func_0801CCB4();
#ifdef VERSION_EU
            func_0806180C(0x93);
#else
            func_0806180C(0x95);
#endif
        } else {
            func_0801CD20();
            ModeRequestHeapReset(&gModeMovie, 1);
        }
    } else {
        ModeRequest(&gModeTitle, 0);
    }
}

#ifndef VERSION_EU
void func_080EB328(void) {
    u8 v;
    u8 u;

    gUnk_02034FDC = EwramAlloc(0x348);
    gUnk_02034FDC->unk_33C = 0;
    gUnk_02034FDC->unk_33D = (gGameState.flags >> 3) & 1;
    gUnk_02034FDC->unk_162 = 33;
    gUnk_02034FDC->unk_340 = 16;
    gUnk_02034FDC->unk_344 = func_080EB1AC;
    SetBgMode0();
    SetupBg(3, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(0, 0, 30, 0);
    SetBgPriority(3, 3);
    SetBgPriority(1, 0);
    SetBgPriority(0, 0);
    LoadBgTiles(3, &gUnk_09966064[0x140], 0x1FA0);
    LoadBgPalette(3, gUnk_09991D44, 0x200);
    LoadBgMap(3, gUnk_0998CF44, 0x800);
    LoadBgTiles(1, &gUnk_09966064[0x140], 0x1FA0);
    LoadBgPalette(1, gUnk_09991D44, 0x200);
    LoadBgTiles(0, &gUnk_09966064[0x140], 0x1FA0);
    LoadBgPalette(0, gUnk_09991D44, 0x200);
    LoadBgMap(0, gUnk_0998F744, 0x800);
    SetBgScroll(0, 0, 0xFFFC);
    gUnk_02034FDC->unk_000 = LoadObjPalette(gUnk_09991D04, 32);
    gUnk_02034FDC->unk_004 = LoadObjTiles(gUnk_098A8C66, 0x2C0);
    gUnk_02034FDC->unk_008 = -0x800;
    gUnk_02034FDC->unk_00C = 0xA000;
    gUnk_02034FDC->unk_320 = AllocObjTiles(0x340, gUnk_088B6560);
    gUnk_02034FDC->unk_31C = LoadObjPalette(gUnk_08F683A4, 32);
    gUnk_02034FDC->unk_328 = AllocObjTiles(0x280, gUnk_0932EDD8);
    gUnk_02034FDC->unk_324 = LoadObjPalette(gUnk_096181D8, 32);
    gUnk_02034FDC->unk_330 = AllocObjTiles(0x400, gUnk_09322F50);
    gUnk_02034FDC->unk_32C = LoadObjPalette(gUnk_096181B8, 32);
    gUnk_02034FDC->unk_338 = AllocObjTiles(0x400, gUnk_092EB78A);
    gUnk_02034FDC->unk_334 = LoadObjPalette(gUnk_09618118, 32);
    gUnk_02034FDC->unk_010 = LoadObjPalette(gUnk_09991D24, 32);
    gUnk_02034FDC->unk_014 = LoadObjTiles(&gUnk_098A8F28[0x62], 0x4C0);
    gUnk_02034FDC->unk_030 = LoadObjPalette(gUnk_09991BE4, 32);
    gUnk_02034FDC->unk_034 = AllocObjTiles(0x120, &gUnk_098A8628[0x4BA]);
    AnimInit(&gUnk_02034FDC->unk_018, gUnk_09EF8D88, gUnk_09EF8D78);
    AnimStart(&gUnk_02034FDC->unk_018, 0, 1);
    gUnk_02034FDC->unk_03C = LoadObjPalette(gUnk_09991C04, 32);
    gUnk_02034FDC->unk_160 = 0;
    func_08065ACC(&gUnk_02034FDC->unk_040, 36);
    func_08065ACC(&gUnk_02034FDC->unk_168, 54);
    gUnk_02034FDC->unk_164 = LoadObjPalette(gUnk_09991BE4, 32);
    gUnk_02034FDC->unk_318 = func_08065B6C(gUnk_08159E1E, &gUnk_02034FDC->unk_168);

    if (gUnk_02034FDC->unk_33D != 0) {
        v = func_080EAD3C(2);
        u = func_080EAD3C(3);
    } else {
        v = func_080EAD3C(0);
        u = func_080EAD3C(1);
    }

    if (v != 0) {
        gUnk_02034FDC->unk_33E = u == 0 ? 1 : 0;
    } else {
        gUnk_02034FDC->unk_33E = 0;
    }

    func_080EAD84(gUnk_02034FDC->unk_33E);
    gUnk_02034FDC->unk_038 = (gUnk_02034FDC->unk_162 + gUnk_02034FDC->unk_33E * 45) << 8;
    func_08006120(0, 8);
}
#else
INCLUDE_ASM("map/func_080EB328.s");
#endif

void func_080EB698(void) {
    if (gUnk_02034FDC->unk_344 != 0) {
        gUnk_02034FDC->unk_344(gUnk_02034FDC);
    }
    func_080EAF10();
}

void func_080EB6BC(void) {
    ReleaseObjPalette(gUnk_02034FDC->unk_000);
    ReleaseObjTiles(gUnk_02034FDC->unk_004);
    ReleaseObjPalette(gUnk_02034FDC->unk_010);
    ReleaseObjTiles(gUnk_02034FDC->unk_014);
    ReleaseObjPalette(gUnk_02034FDC->unk_030);
    ReleaseObjTiles(gUnk_02034FDC->unk_034);
    ReleaseObjPalette(gUnk_02034FDC->unk_31C);
    ReleaseObjTiles(gUnk_02034FDC->unk_320);
    ReleaseObjPalette(gUnk_02034FDC->unk_324);
    ReleaseObjTiles(gUnk_02034FDC->unk_328);
    ReleaseObjPalette(gUnk_02034FDC->unk_32C);
    ReleaseObjTiles(gUnk_02034FDC->unk_330);
    ReleaseObjPalette(gUnk_02034FDC->unk_334);
    ReleaseObjTiles(gUnk_02034FDC->unk_338);
    ReleaseObjPalette((u8*)gUnk_02034FDC->unk_03C);
    func_08065AE0(gUnk_02034FDC->unk_040, 36);
    ReleaseObjPalette(gUnk_02034FDC->unk_164);
    func_08065AE0(gUnk_02034FDC->unk_168, 54);
    EwramFree(gUnk_02034FDC);
}

s32 func_080EB7A0(u8 a) {
    switch (a) {
    case 0:
        if (SaveRepairFileLarge(0) == 2) {
            SaveLoadFileLarge(0);
            return 1;
        }
        break;
    case 1:
        if (SaveRepairFileLarge(1) == 2) {
            SaveLoadFileLarge(1);
            return 1;
        }
        break;
    case 2:
        if (SaveRepairFileSmall(0) == 2) {
            SaveLoadFileSmall(0);
            _08085D04(gGameState.world);
            return 1;
        }
        break;
    case 3:
        if (SaveRepairFileSmall(1) == 2) {
            SaveLoadFileSmall(1);
            _08085D04(gGameState.world);
            return 1;
        }
        break;
    }
    return 0;
}

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

void func_080EB898(u8 a, u16 v) {
    u16 d[4];
    s32 off;
    u16* q;
    s32 i;

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

void func_080EB93C(u8 a, u32 v) {
    u16 d[6];
    s32 off;
    u16* q;
    s32 i;
    u32 t;

    t = v / 3600;
    d[0] = t / 10;
    d[1] = t - d[0] * 10;
    v -= t * 3600;
    t = v / 60;
    d[2] = t / 10;
    d[3] = t - d[2] * 10;
    v -= t * 60;
    d[4] = v / 10;
    d[5] = v - d[4] * 10;
    i = 0;
    off = a * 608 + 128;
    q = d;

    while (i <= 5) {
        RequestDma3Copy((void*)&gUnk_09966064[*q * 32], (u8*)GetBgCharBase(1) + off + i * 32, 0x20);
        q++;
        i++;
    }
}

void func_080EBA14(u8 a) {
    UnkStruct_02039D6C* e = &gUnk_02039D6C[a];

    if (e->unk_02 != 0) {
        func_080EB898(a, e->unk_02);
        func_080EB93C(a, e->unk_04);
        func_080EB818(a, 0, e->unk_00);
    } else {
        func_080EB818(a, 0, 13);
    }
}

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

void func_080EBAE0(u8 a) {
    UnkStruct_02039D6C* e = &gUnk_02039D6C[a];

    if (e->unk_02 != 0) {
        func_080EB818(a, 0, e->unk_00);
    } else {
        func_080EB818(a, 0, 13);
    }
    gUnk_02034FE0->unk_15C = 0;
}

#ifndef VERSION_EU
void func_080EBB24(void) {
    s32 t;
    s32 u;

    DrawSprite(128, gUnk_02034FE0->unk_008 >> 8, gUnk_09EF8D68[1], gUnk_02034FE0->unk_004,
        gUnk_02034FE0->unk_000, 0, 0xC00, 90);
    DrawSprite(128, gUnk_02034FE0->unk_00C >> 8, gUnk_09EF8D68[2], gUnk_02034FE0->unk_004,
        gUnk_02034FE0->unk_000, 0, 0xC00, 90);
    DrawSprite(gUnk_02034FE0->unk_010 >> 8, 0, gUnk_09EF8D68[0], gUnk_02034FE0->unk_004,
        gUnk_02034FE0->unk_000, 0, 0xC00, 80);

    if (gUnk_02034FE0->unk_183 <= 1) {
        DrawSprite(56, 112, ((void**)gUnk_09EDE8CC)[0], gUnk_02034FE0->unk_164,
            gUnk_02034FE0->unk_160, 0, 0x400, 80);
        DrawSprite(72, 96, ((void**)gUnk_09EEE03C)[0], gUnk_02034FE0->unk_16C,
            gUnk_02034FE0->unk_168, 0, 0x401, 81);
        DrawSprite(40, 96, ((void**)gUnk_09EEE1C8)[0], gUnk_02034FE0->unk_174,
            gUnk_02034FE0->unk_170, 0, 0x400, 81);
    } else {
        DrawSprite(56, 112, gUnk_09EEF89C[0], gUnk_02034FE0->unk_17C, gUnk_02034FE0->unk_178, 0,
            0x400, 81);
    }

    if (gUnk_02034FE0->unk_180 != 0) {
        t = 32;
    } else {
        t = 45;
    }

    u = t * gUnk_02034FE0->unk_183;
    func_0805F1C0(&gUnk_02034FE0->unk_034, (gUnk_02034FE0->unk_15E + u) << 8);
    DrawSprite(76, gUnk_02034FE0->unk_034 >> 8, AnimGetGfx(&gUnk_02034FE0->unk_014),
        gUnk_02034FE0->unk_030, gUnk_02034FE0->unk_02C, 0, 0x400, 70);
    func_080664D8(100, u + (gUnk_02034FE0->unk_15E + 22), &gUnk_02034FE0->unk_03C,
        gUnk_02034FE0->unk_038, 50, gUnk_02034FE0->unk_15C);
}
#else
INCLUDE_ASM("map/func_080EBB24.s");
#endif

void func_080EBD00(UnkStruct_02034FE0* w) {
    u8 old = w->unk_183;

    if (GetKeysRepeat() & 0x40) {
        w->unk_183 = w->unk_183 != 0 ? w->unk_183 - 1 : w->unk_184;
        m4aSongNumStart(0x65);
    }

    if (GetKeysRepeat() & 0x80) {
        w->unk_183 = w->unk_183 < w->unk_184 ? w->unk_183 + 1 : 0;
        m4aSongNumStart(0x65);
    }

    if (old != w->unk_183) {
        func_080EBAE0(old);
        func_080EBA58(w->unk_183);

        switch (w->unk_183) {
        case 0:
            if (w->unk_180 != 0) {
                LoadBgMap(1, &gUnk_09985F44[0x3000], 0x800);
                SetBgScroll(1, 0, -1);
            } else {
                LoadBgMap(1, &gUnk_09985F44[0x2000], 0x800);
                SetBgScroll(1, 0, -3);
            }
            break;
        case 1:
            if (w->unk_180 != 0) {
                LoadBgMap(1, &gUnk_09985F44[0x3800], 0x800);
                SetBgScroll(1, 0, -1);
            } else {
                LoadBgMap(1, &gUnk_09985F44[0x2800], 0x800);
                SetBgScroll(1, 0, 0);
            }
            break;
        case 2:
            LoadBgMap(1, &gUnk_09985F44[0x4000], 0x800);
            SetBgScroll(1, 0, -1);
            break;
        case 3:
            LoadBgMap(1, &gUnk_09985F44[0x4800], 0x800);
            SetBgScroll(1, 0, -1);
            break;
        }
    }
}

void func_080EBE44(UnkStruct_02034FE0* work) {
    if (work->unk_186 != 0) {
        ApproachValue(&work->unk_008, 0, work->unk_186);
        ApproachValue(&work->unk_00C, 0x9800, work->unk_186);
        work->unk_186--;
    } else {
        work->unk_186 = 16;
        work->unk_188 = func_080EBE90;
    }
}

void func_080EBE90(UnkStruct_02034FE0* work) {
    if (work->unk_186 != 0) {
        ApproachValue(&work->unk_010, 0, work->unk_186);
        work->unk_186--;
    } else {
        work->unk_188 = func_080EBEC8;
    }
}

void func_080EBEC8(UnkStruct_02034FE0* work) {
    func_080EBD00(work);

    if (GetKeysPressed() & 2) {
        work->unk_186 = 16;
        work->unk_188 = func_080EBFB8;
        m4aSongNumStart(0x68);
    } else if (GetKeysPressed() & 9) {
        if ((u8)func_080EB7A0(work->unk_183) != 0) {
            switch (work->unk_183) {
            case 0:
                gGameState.flags &= ~8;
                gGameState.flags &= ~0x10;
                break;
            case 1:
                gGameState.flags &= ~8;
                gGameState.flags |= 0x10;
                break;
            case 2:
                gGameState.flags |= 8;
                gGameState.flags &= ~0x10;
                break;
            case 3:
                gGameState.flags |= 8;
                gGameState.flags |= 0x10;
                break;
            }
            m4aSongNumStart(0xD3);
            work->unk_182 = 1;
            work->unk_186 = 16;
            work->unk_188 = func_080EBFB8;
        } else {
            m4aSongNumStart(0x69);
        }
    }
}

void func_080EBFB8(UnkStruct_02034FE0* work) {
    if (work->unk_186 != 0) {
        ApproachValue(&work->unk_010, -0x8000, work->unk_186);
        work->unk_186--;
    } else {
        work->unk_186 = 16;
        work->unk_188 = func_080EBFF8;
    }
}

void func_080EBFF8(UnkStruct_02034FE0* work) {
    if (work->unk_186 != 0) {
        ApproachValue(&work->unk_008, -0x800, work->unk_186);
        ApproachValue(&work->unk_00C, 0xA000, work->unk_186);
        work->unk_186--;
    } else {
        func_08006184(0, 16);
        work->unk_188 = func_080EC04C;
    }
}

#ifndef VERSION_EU
void func_080EC04C(UnkStruct_02034FE0* work) {
    if ((u8)func_08006314() != 0) {
        return;
    }

    if (work->unk_181 != 0) {
        if (work->unk_182 != 0) {
            ModeRequest(&gModeSioBattle, 1);
        } else {
            ModeRequest(&gModeSioBattle, 0);
        }
    } else if (work->unk_182 != 0) {
        if (gUnk_0203C590.unk_04 != 13) {
            func_080E04EC();
        } else {
            ModeRequest(&gModePooh, 2);
        }
    } else {
        ModeRequest(&gModeTitle, 0);
    }
}
#else
INCLUDE_ASM("map/func_080EC04C.s");
#endif

#ifndef VERSION_EU
void func_080EC0D4(s32 arg) {
    s32 i;

    gUnk_02034FE0 = EwramAlloc(0x18C);
    gUnk_02034FE0->unk_181 = arg != 0;

    if (gUnk_02034FE0->unk_181 != 0) {
        gUnk_02034FE0->unk_180 = 0;
    } else {
        gUnk_02034FE0->unk_180 = (gGameState.flags >> 5) & 1;
    }

    gUnk_02034FE0->unk_182 = 0;
    gUnk_02034FE0->unk_183 = 0;

    if (gUnk_02034FE0->unk_180 != 0) {
        gUnk_02034FE0->unk_184 = 3;
        gUnk_02034FE0->unk_15E = 17;
        gUnk_02034FE0->unk_034 = gUnk_02034FE0->unk_15E << 8;
    } else {
        gUnk_02034FE0->unk_184 = 1;
        gUnk_02034FE0->unk_15E = 43;
        gUnk_02034FE0->unk_034 = gUnk_02034FE0->unk_15E << 8;
    }

    gUnk_02034FE0->unk_186 = 16;
    gUnk_02034FE0->unk_188 = func_080EBE44;
    SetBgMode0();
    SetupBg(3, 0, 28, 0);
    SetupBg(2, 0, 29, 0);
    SetupBg(1, 0, 30, 0);
    SetupBg(0, 3, 31, 0);
    LoadBgTiles(3, gUnk_09959A64, 0x8000);
    LoadBgPalette(3, gUnk_099919C4, 0x200);
    LoadBgMap(3, gUnk_09986F44, 0x800);
    LoadBgTiles(2, gUnk_09959A64, 0x8000);
    LoadBgPalette(2, gUnk_099919C4, 0x200);
    LoadBgMap(2, gUnk_09987744, 0x800);
    LoadBgTiles(1, gUnk_09959A64, 0x8000);
    LoadBgPalette(1, gUnk_099919C4, 0x200);

    if (gUnk_02034FE0->unk_180 != 0) {
        LoadBgMap(1, gUnk_09988F44, 0x800);
        SetBgScroll(1, 0, 0xFFFF);
    } else {
        LoadBgMap(1, gUnk_09987F44, 0x800);
        SetBgScroll(1, 0, 0xFFFD);
    }

    gUnk_02034FE0->unk_000 = LoadObjPalette(gUnk_09991BC4, 32);
    gUnk_02034FE0->unk_004 = LoadObjTiles(gUnk_098A87AA, 0x2C0);
    gUnk_02034FE0->unk_008 = -0x800;
    gUnk_02034FE0->unk_00C = 0xA000;
    gUnk_02034FE0->unk_010 = -0x8000;
    gUnk_02034FE0->unk_164 = AllocObjTiles(0x340, gUnk_088B6560);
    gUnk_02034FE0->unk_160 = LoadObjPalette(gUnk_08F683A4, 32);
    gUnk_02034FE0->unk_16C = AllocObjTiles(0x280, gUnk_0919FDF8);
    gUnk_02034FE0->unk_168 = LoadObjPalette(gUnk_09617C58, 32);
    gUnk_02034FE0->unk_174 = AllocObjTiles(0x400, gUnk_091ABDB8);
    gUnk_02034FE0->unk_170 = LoadObjPalette(gUnk_08F68384, 32);
    gUnk_02034FE0->unk_17C = AllocObjTiles(0x400, gUnk_092EB78A);
    gUnk_02034FE0->unk_178 = LoadObjPalette(gUnk_09618118, 32);
    gUnk_02034FE0->unk_02C = LoadObjPalette(gUnk_09991BE4, 32);
    gUnk_02034FE0->unk_030 = AllocObjTiles(0x120, gUnk_098A8AE2);
    AnimInit((AnimState*)gUnk_02034FE0->unk_014, gUnk_09EF8D88, gUnk_09EF8D78);
    AnimStart((AnimState*)gUnk_02034FE0->unk_014, 0, 1);
    gUnk_02034FE0->unk_038 = LoadObjPalette(gUnk_09991C04, 32);
    gUnk_02034FE0->unk_15C = 0;
    func_08065ACC(gUnk_02034FE0->unk_03C, 36);

    for (i = 0; i < 4; i++) {
        func_080EBA14(i);
    }

    func_080EBA58(gUnk_02034FE0->unk_183);
    func_08006120(0, 16);
}
#else
INCLUDE_ASM("map/func_080EC0D4.s");
#endif

void func_080EC424(void) {
    if (gUnk_02034FE0->unk_188 != 0) {
        gUnk_02034FE0->unk_188(gUnk_02034FE0);
    }
    func_080EBB24();
}

void func_080EC448(void) {
    ReleaseObjPalette(gUnk_02034FE0->unk_000);
    ReleaseObjTiles(gUnk_02034FE0->unk_004);
    ReleaseObjPalette(gUnk_02034FE0->unk_02C);
    ReleaseObjTiles(gUnk_02034FE0->unk_030);
    ReleaseObjPalette(gUnk_02034FE0->unk_160);
    ReleaseObjTiles(gUnk_02034FE0->unk_164);
    ReleaseObjPalette(gUnk_02034FE0->unk_168);
    ReleaseObjTiles(gUnk_02034FE0->unk_16C);
    ReleaseObjPalette(gUnk_02034FE0->unk_170);
    ReleaseObjTiles(gUnk_02034FE0->unk_174);
    ReleaseObjPalette(gUnk_02034FE0->unk_178);
    ReleaseObjTiles(gUnk_02034FE0->unk_17C);
    ReleaseObjPalette((u8*)gUnk_02034FE0->unk_038);
    func_08065AE0(gUnk_02034FE0->unk_03C, 36);
    EwramFree(gUnk_02034FE0);
}

void func_080EC500(UnkStruct_02034FE4* w) {
    if (func_080A42C8() == 0) {
        if (w->unk_00 == 0) {
            func_080C75A4(1, 16);
            func_08006184(1, 16);
        } else {
            func_080C75A4(0, 16);
            func_08006184(0, 16);
        }
        w->unk_04 = func_080EC544;
    }
}

void func_080EC544(UnkStruct_02034FE4* w) {
    if (func_08006314() == 0) {
        if (w->unk_00 == 0) {
            ModeRequest(&gModeCopyright1, 0);
        } else {
            ModeRequest(&gModeTitle, 0);
        }
    }
}

void func_080EC57C(s32 arg) {
    gUnk_02034FE4 = EwramAlloc(0x1C);
    gUnk_02034FE4->unk_00 = arg;
    SetBgMode0();
    TaskPoolInit(&gUnk_02034FE4->unk_08, 1);

    if (gUnk_02034FE4->unk_00 == 0) {
        func_080A4188(&gUnk_02034FE4->unk_08, 0xB0);
        func_080C736C();
        func_080C73A4(0, 0, 0);
        func_080C7568(1, 16);
        func_08006120(1, 16);
        func_080063A8();
    } else {
#ifdef VERSION_EU
        func_080A4188(&gUnk_02034FE4->unk_08, 0xB2);
#else
        func_080A4188(&gUnk_02034FE4->unk_08, 0xB3);
#endif
        func_080C736C();
        func_080C73A4(0, 0, 0);
        func_080C7568(0, 1);
        func_08006120(0, 1);
        func_080063A8();
    }
    gUnk_02034FE4->unk_04 = func_080EC500;
}

void func_080EC618(void) {
    gUnk_02034FE4->unk_04(gUnk_02034FE4);
    TaskPoolUpdate(&gUnk_02034FE4->unk_08);
    TaskPoolDraw(&gUnk_02034FE4->unk_08);
    func_080C73D8();
}

void func_080EC644(void) {
    TaskPoolDestroy(&gUnk_02034FE4->unk_08);
    EwramFree(gUnk_02034FE4);
}

void func_080EC660(MapRndWork* w) {
    UnkStruct_09EF70D0* r = gUnk_09EF70D0[gUnk_0203C590.unk_04];
    s32 i;

    TaskPoolInit(&w->unk_00, 4);
    LoadBgTiles(3, r->unk_08, r->unk_0C);
    LoadBgTiles(2, r->unk_08, r->unk_0C);
    LoadBgTiles(1, r->unk_10, r->unk_14);
    LoadBgPalette(3, r->unk_00, r->unk_04);
    LoadBgPalette(2, r->unk_00, r->unk_04);
    LoadBgPalette(1, r->unk_00, r->unk_04);
    gUnk_0203C7AC->unk_04 = func_080E5564();
    gUnk_0203C7AC->unk_06 = 64;
    gUnk_02039BA0->unk_10 = gUnk_0203C7AC->unk_04 * 4;
    gUnk_02039BA0->unk_12 = gUnk_0203C7AC->unk_06 * 2;
    func_080E49DC(gUnk_0203C7AC->unk_04, gUnk_0203C7AC->unk_06);

    for (i = 0; i < 4; i++) {
        UnkStruct_080DFB8C* e = func_080DFB7C(i);

        if (e->unk_00 & 1) {
            if ((e->unk_00 & 8) == 0) {
                TaskCreate(&w->unk_00, &gTaskDescMapDoor, e);
            }
        }
    }
}

s32 func_080EC720(MapRndWork* w) {
    func_080E00E4(gUnk_02039BA0->unk_08, gUnk_02039BA0->unk_0C);
    TaskPoolUpdate(&w->unk_00);
    return 1;
}

void func_080EC744(TaskPool* pool) {
    TaskPoolDraw(pool);
}

void func_080EC750(TaskPool* pool) {
    TaskPoolDestroy(pool);
    func_080E4B34();
}

void func_080EC760(UnkStruct_080EC760* p, UnkStruct_080EC760Entry* q) {
    s32 i;

    p->unk_00 = 0;

    if (q != 0) {
        i = 0;

        do {
            if (q->unk_00 != 0) {
                func_080122AC(p->unk_04[i], 6, q->unk_00, 0xA0);
                func_08012324(p->unk_04[i], q->unk_04, q->unk_08, 0);
                p->unk_00++;
            } else {
                break;
            }
            q++;
            i++;
        } while (i < 5);
    }
}

#ifndef VERSION_EU
void func_080EC7AC(UnkStruct_080EC760* w, UnkStruct_09EF8370* p) {
    UnkStruct_080EF4BC v;

    switch (gUnk_0203C590.unk_07) {
    case 0:
        gUnk_02039BA0->unk_E4[0] = 173;
        gUnk_02039BA0->unk_DC = p->unk_38 - 0xC00;
        gUnk_02039BA0->unk_E0 = p->unk_3C + 0x800;
        break;
    case 1:
        gUnk_02039BA0->unk_E4[0] = 45;
        gUnk_02039BA0->unk_DC = p->unk_40 + 0xC00;
        gUnk_02039BA0->unk_E0 = p->unk_44 - 0x800;
        break;
    default:
        gUnk_02039BA0->unk_E4[0] = 45;
        gUnk_02039BA0->unk_DC = p->unk_48;
        gUnk_02039BA0->unk_E0 = p->unk_4C;
        break;
    }

    LoadBgTiles(3, p->unk_08, p->unk_0C);
    LoadBgPalette(3, p->unk_00, p->unk_04);
    func_0800516C(3, p->unk_18, p->unk_24, p->unk_25);

    if (p->unk_1C != 0) {
        LoadBgTiles(2, p->unk_08, p->unk_0C);
        LoadBgPalette(2, p->unk_00, p->unk_04);
        func_0800516C(2, p->unk_1C, p->unk_24, p->unk_25);
    } else {
        DisableBg(2);
    }

    if (p->unk_20 != 0) {
        LoadBgTiles(1, p->unk_10, p->unk_14);
        LoadBgPalette(1, p->unk_00, p->unk_04);
        func_0800516C(1, p->unk_20, p->unk_24, p->unk_25);
    } else {
        DisableBg(1);
    }

    gUnk_02039BA0->unk_10 = p->unk_24 * 32;
    gUnk_02039BA0->unk_12 = p->unk_25 * 32;
    gUnk_0203C7AC->unk_04 = gUnk_02039BA0->unk_10 / 4;
    gUnk_0203C7AC->unk_06 = gUnk_02039BA0->unk_12 / 2;
    func_080E5868((UnkStruct_09EF70D0*)p);
    TaskPoolInit(&w->unk_1D0, 2);
    v.unk_00 = p->unk_38;
    v.unk_04 = p->unk_3C;
    v.unk_14 = 45;
    TaskCreate(&w->unk_1D0, &gTaskDescMapStair, &v);

    if (p->unk_40 != 0 || p->unk_44 != 0) {
        v.unk_00 = p->unk_40;
        v.unk_04 = p->unk_44;
        v.unk_14 = 173;
        TaskCreate(&w->unk_1D0, &gTaskDescMapStair, &v);
    }

    func_080EC760(w, p->unk_30);
}
#else
INCLUDE_ASM("map/func_080EC7AC.s");
#endif

s32 func_080EC94C(u8* work) {
    s32 tx = gUnk_02039BA0->unk_08 - 0x7800;
    s32 ty = gUnk_02039BA0->unk_0C - 0x6000;

    gUnk_02039BA0->unk_00 += (tx - gUnk_02039BA0->unk_00) / 8;
    gUnk_02039BA0->unk_04 += (ty - gUnk_02039BA0->unk_04) / 8;

    if (gUnk_02039BA0->unk_00 < 0) {
        gUnk_02039BA0->unk_00 = 0;
    }

    if (gUnk_02039BA0->unk_04 < 0) {
        gUnk_02039BA0->unk_04 = 0;
    }

    if (gUnk_02039BA0->unk_00 + 0xF000 > gUnk_02039BA0->unk_10 << 11) {
        gUnk_02039BA0->unk_00 = (gUnk_02039BA0->unk_10 << 11) - 0xF000;
    }

    if (gUnk_02039BA0->unk_04 + 0xA000 > gUnk_02039BA0->unk_12 << 11) {
        gUnk_02039BA0->unk_04 = (gUnk_02039BA0->unk_12 << 11) - 0xA000;
    }
    TaskPoolUpdate((TaskPool*)&work[0x1D0]);
    return 1;
}

void func_080EC9EC(u8* work) {
    func_08005244(3, gUnk_02039BA0->unk_00 >> 8, gUnk_02039BA0->unk_04 >> 8);
    func_08005244(2, gUnk_02039BA0->unk_00 >> 8, gUnk_02039BA0->unk_04 >> 8);

    if ((gUnk_0203C7AC->unk_00 & 1) == 0) {
        func_08005244(1, gUnk_02039BA0->unk_00 >> 8, gUnk_02039BA0->unk_04 >> 8);
    }
    TaskPoolDraw((TaskPool*)&work[0x1D0]);
}

#ifndef VERSION_EU
void func_080ECA54(u8* work) {
    s32 i;

    for (i = 0; i < work[0]; i++) {
        func_08012304(&work[4 + i * 92]);
    }

    TaskPoolDestroy((TaskPool*)&work[0x1D0]);
    func_080E58E4();
}
#else
INCLUDE_ASM("map/func_080ECA54.s");
#endif

void func_080ECA88(UnkStruct_080ECA88* p) {
    func_080038E4(p->unk_44, p->unk_4C, p->unk_54);
    func_080038E4(p->unk_58, p->unk_60, p->unk_64);
}

void func_080ECAA8(UnkStruct_080ECA88* p) {
    func_080038E4(p->unk_44, p->unk_4C, p->unk_50);
    func_080038E4(p->unk_58, p->unk_60, p->unk_68);
}

s32 func_080ECAC8(UnkStruct_080ECA88* p) {
    u16* flags = p->unk_00;
    UnkStruct_080DFF1C* e = (UnkStruct_080DFF1C*)&p->unk_04;

    if (!(gUnk_02039BA0->unk_70 & 0x2000) && !(gUnk_0203C7AC->unk_00 & 0x4004) &&
        (u8)(((u8*)flags)[7] + 3) > 1 && (*flags & 0x12) != 0x12 &&
        func_080E02E0(e, 0, 8) != 0 && !(gUnk_02039BA0->unk_70 & 0x800000) &&
        gUnk_02039BA0->unk_20 == gUnk_02039BA0->unk_24) {
        TaskPool* pool;

        m4aSongNumStart(0xDC);
        pool = &p->unk_74;
        TaskCreate(pool, &gTaskDescMapSpark, e);
        gUnk_0203C7AC->unk_00 |= 0x80;
        gUnk_02039BA0->unk_68 = (s32)e;
        gUnk_0203C7AC->unk_14 = (s32)e;
        p->unk_71 = 1;
        p->unk_6C = func_080ECBC8;
        gUnk_0203C7AC->unk_0F = ((u8*)flags)[7];
        gUnk_0203C7AC->unk_10 = ((u8*)flags)[6];
        func_080062F4(*(u16*)&p->unk_48[6] + 16, 1);
        func_080062F4(*(u16*)&p->unk_5C[6] + 16, 1);
        TaskCreate(pool, &gTaskDescRoomcreate, 0);
    }
    return 1;
}

s32 func_080ECBC8(UnkStruct_080ECA88* p) {
    u16* flags = p->unk_00;
    void* t = func_08093BF8();

    if (t != 0) {
        if (*flags & 0x10) {
            func_080DF640(((u8*)flags)[7], 0);
        } else {
            func_080DF640(((u8*)flags)[7], t);
        }
        p->unk_6C = func_080ECC54;
    }

    if (!(gUnk_02039BA0->unk_70 & 0x40000)) {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        func_080062F4(*(u16*)&p->unk_48[6] + 16, 0);
        func_080062F4(*(u16*)&p->unk_5C[6] + 16, 0);
        p->unk_6C = func_080ECAC8;
    }
    return 1;
}

s32 func_080ECC54(UnkStruct_080ECA88* p) {
    u16* flags = p->unk_00;
    u16 v;

    if (gUnk_02039BA0->unk_70 & 0x200000) {
        func_080ECA88(p);
        v = *flags | 2;
        *flags = v;
        p->unk_6C = func_080ECC8C;
    }

    return 1;
}

u8 func_080ECC8C(UnkStruct_080ECA88* p) {
    return 1;
}

void func_080ECC90(UnkStruct_080ECA88* w, UnkStruct_080DFB8C* p) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_04;
    UnkStruct_080DFF1C* v = &e->unk_00;
    UnkStruct_0984B968* q = &gUnk_0984B968[gUnk_0203C590.unk_04];

    w->unk_00 = (u16*)p;
    w->unk_71 = 0;
    w->unk_70 = 1;

    switch (p->unk_06[0]) {
    case 0:
        w->unk_4C = gUnk_098A94A0;
        w->unk_54 = q->unk_08;
        w->unk_50 = q->unk_04;
        e->unk_14 = 173;
        w->unk_04 = (*(u16*)((u8*)p + 2) << 5) + 16;
        e->unk_00.x = (*(u16*)((u8*)p + 4) << 4) + 10;
        break;
    case 1:
        w->unk_4C = gUnk_098A94B4;
        w->unk_54 = q->unk_20;
        w->unk_50 = q->unk_1C;
        e->unk_14 = 45;
        w->unk_04 = (*(u16*)((u8*)p + 2) << 5) + 16;
        e->unk_00.x = (*(u16*)((u8*)p + 4) << 4) + 6;
        break;
    case 2:
        w->unk_4C = gUnk_098A94C8;
        w->unk_54 = q->unk_18;
        w->unk_50 = q->unk_14;
        e->unk_14 = 211;
        w->unk_04 = (*(u16*)((u8*)p + 2) << 5) + 16;
        e->unk_00.x = (*(u16*)((u8*)p + 4) << 4) + 6;
        break;
    case 3:
        w->unk_4C = gUnk_098A948C;
        w->unk_54 = q->unk_10;
        w->unk_50 = q->unk_0C;
        e->unk_14 = 83;
        w->unk_04 = (*(u16*)((u8*)p + 2) << 5) + 16;
        e->unk_00.x = (*(u16*)((u8*)p + 4) << 4) + 10;
        break;
    }

    v->unk_00 <<= 8;
    v->x <<= 8;
    v->y = 0;
    v->y = v->z = func_080DFF30(v);
    v->x -= v->y;
    e->unk_1A = 32;
    e->unk_30 = 3;
    w->unk_44 = func_080038C8(0x400);
    w->unk_48 = LoadObjPalette(q->unk_00, 32);
    w->unk_5C = LoadObjPalette(gUnk_09991284, 32);
    w->unk_58 = func_080038C8(0x100);

    switch (p->unk_06[0]) {
    case 0:
    case 1:
        w->unk_60 = gUnk_098A94DC;
        w->unk_64 = gUnk_09953864;
        w->unk_68 = gUnk_09953864 + 0x200;
        break;
    case 2:
    case 3:
        w->unk_60 = gUnk_098A94FC;
        w->unk_64 = gUnk_09953764;
        w->unk_68 = gUnk_09953764 + 0x200;
        break;
    }

    if (p->unk_00 & 2) {
        w->unk_6C = func_080ECAC8;
        func_080ECA88(w);
    } else {
        w->unk_6C = func_080ECAC8;
        func_080ECAA8(w);
    }

    TaskPoolInit(&w->unk_74, 2);
}

s32 func_080ECE3C(UnkStruct_080ECA88* w) {
    if (gUnk_02039BA0->unk_70 & 0x40000) {
        if (w->unk_71 == 0) {
            w->unk_70 = 0;
        }
    } else {
        w->unk_71 = 0;
        w->unk_70 = 1;
    }

    if (w->unk_6C != 0) {
        if (w->unk_6C(w) == 0) {
            return 0;
        }
    }

    TaskPoolUpdate(&w->unk_74);
    return 1;
}

void func_080ECE98(UnkStruct_080ECA88* p) {
    u16* f = p->unk_00;
    u16 sx;
    u16 sy;
    u16 v;
    u16 t;
    s32 k;

    if (p->unk_70 == 1) {
        sx = (p->unk_04 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
        k = p->unk_08 >> 8;
        sy = k + (p->unk_0C >> 8) - (gUnk_02039BA0->unk_04 >> 8);

        switch (((u8*)f)[6]) {
        case 0:
        case 3:
            v = -0xFE4 - (p->unk_08 >> 8) * 4;
            break;
        case 1:
        case 2:
            v = -0x1024 - k * 4;
            break;
        default:
            v = 0;
            break;
        }

        t = 0x800;
        DrawSprite(sx, sy, 0, p->unk_44, p->unk_48, 0, t, v);

        if (*f & 0x10) {
            switch (((u8*)f)[6]) {
            case 0:
            case 2:
                DrawSprite(sx, sy, 0, p->unk_58, p->unk_5C, 0, t, v - 1);
                break;
            case 1:
            case 3:
                DrawSprite(sx, sy, 0, p->unk_58, p->unk_5C, 0, t, v - 1);
                break;
            }
        }

        TaskPoolDraw(&p->unk_74);
    }
}

void func_080ECFBC(UnkStruct_080ECA88* p) {
    ReleaseObjTiles(p->unk_44);
    ReleaseObjPalette(p->unk_48);
    ReleaseObjTiles(p->unk_58);
    ReleaseObjPalette(p->unk_5C);
    TaskPoolDestroy(&p->unk_74);
}

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

void func_080ED14C(FldRes* p, u8 a, u32 v) {
    u16 d[5];
    u16* q;
    s32 i;

    d[0] = v / 10000;
    d[1] = v / 1000 - d[0] * 10;
    d[2] = v / 100 - d[0] * 100 - d[1] * 10;
    d[3] = v / 10 - d[0] * 1000 - d[1] * 100 - d[2] * 10;
    d[4] = v - d[0] * 10000 - d[1] * 1000 - d[2] * 100 - d[3] * 10;

    for (i = 0, q = d; i < 5; i++) {
        RequestDma3Copy((void*)&gUnk_099581A4[*q * 32], (void*)(0x06010000 + (p->unk_06 + a + i) * 32), 0x20);
        q++;
    }
}
#ifndef VERSION_EU
void func_080ED250(u8* work) {
    u8* p1;
    u8* p2;
    u8* p3;

    LoadBgTiles(0, gUnk_099597E4, 0x140);
    LoadBgMap(0, gUnk_09985F44, 0x800);
    LoadPalette(gUnk_09611AB8, &gUnk_050001C0[0x20], 0x20);
    func_080062F4(15, 1);
    SetBgScroll(0, 0, 0);
    *(void**)&work[0x17C] = _08066468(1);
    p1 = &work[0x180];
    func_08065ACC(p1, 33);
    p2 = &work[0x28C];
    func_08065ACC(p2, 6);
    p3 = &work[0x2C0];
    func_08065ACC(p3, 9);
    work[0x288] = func_08065B6C(gUnk_0815A03A, p1);
    work[0x2BC] = func_08065B6C(gUnk_08159E10, p2);
    work[0x308] = func_08065B6C(gUnk_08159E18, p3);
}
#else
INCLUDE_ASM("map/func_080ED250.s");
#endif
void func_080ED314(u8* work) {
    func_080062F4(15, 0);
    DisableBg(0);
    ReleaseObjPalette(*(u8**)&work[0x17C]);
#ifdef VERSION_EU
    func_08065AE0(&work[0x180], 0x42);
    func_08065AE0(&work[0x394], 6);
    func_08065AE0(&work[0x3C8], 9);
#else
    func_08065AE0(&work[0x180], 0x21);
    func_08065AE0(&work[0x28C], 6);
    func_08065AE0(&work[0x2C0], 9);
#endif
}

s32 func_080ED35C(MapMenuWork* w) {
    w->unk_000 = LoadObjPalette(gUnk_09991984, 32);
    w->unk_004 = LoadObjTiles(gUnk_09958124, 0x80);
    w->unk_008 = -0x800;
    w->unk_00C = 0xA000;

    if (gGameState.flags & 8) {
        w->unk_13C = AllocObjTiles(0x400, gUnk_092EB78A);
    } else {
        w->unk_13C = AllocObjTiles(0x340, gUnk_088B6560);
    }

    w->unk_144 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->unk_140 = LoadObjPalette(gUnk_08F69BE4, 32);
    w->unk_150 = gUnk_02039BA0->unk_18 - gUnk_02039BA0->unk_00;
    w->unk_154 = gUnk_02039BA0->unk_1C + gUnk_02039BA0->unk_20 - gUnk_02039BA0->unk_04;
    w->unk_148 = w->unk_150;
    w->unk_14C = w->unk_154;
    w->unk_309 = gGameState.unk_0F;
    w->unk_30A = 0;
    w->unk_034 = 0;
    w->unk_30E = 0;
    w->unk_30C = w->unk_30F != 0 ? 1 : 16;
    w->unk_310 = func_080ED498;
    func_080ED06C((UnkStruct_080ED06C*)w, 1);

    if (w->unk_30F == 0) {
        func_08006238(0, 16, 16);
    }
    return 1;
}

#ifndef VERSION_EU
s32 func_080ED498(MapMenuWork* w) {
    if (w->unk_30C != 0) {
        ApproachValue(&w->unk_008, 0, w->unk_30C);
        ApproachValue(&w->unk_00C, 0x9800, w->unk_30C);
        w->unk_30C--;
    } else {
        s32 i;

        gUnk_0203C7AC->unk_00 |= 0x1000;
        gUnk_02039BA0->unk_70 |= 0x100;
        w->unk_024 = LoadObjTiles(gUnk_09954B64, 0x1BC0);
        w->unk_020 = LoadObjPalette(gUnk_09991924, 32);
        w->unk_028 = 0x11800;
        w->unk_02C = 0xF000;
        w->unk_030 = 0x10000;
        func_080ED0B8(w->unk_024, 0, gGameState.unk_108);
        func_080ED0B8(w->unk_024, 6, gGameState.unk_F8);
        func_080ED0B8(w->unk_024, 3, gGameState.unk_32);

        if (gGameState.flags & 8) {
            func_080ED0B8(w->unk_024, 9, gGameState.unk_FC);
        } else {
            func_080ED14C(w->unk_024, 9, gGameState.unk_174);
        }

        w->unk_038 = LoadObjPalette(gUnk_09991964, 32);
        w->unk_03C = LoadObjPalette(gUnk_09991944, 32);

        if (gGameState.flags & 8) {
            w->unk_040 = LoadObjTiles(gUnk_099582E4, 0x1500);
        } else {
            w->unk_040 = LoadObjTiles(gUnk_09956724, 0x1500);
        }

        w->unk_044 = -0x7800;
        w->unk_060 = LoadObjPalette(gUnk_099919A4, 32);
        w->unk_064 = AllocObjTiles(0x120, gUnk_098A8628);
        AnimInit(&w->unk_048, gUnk_09EF8D58, gUnk_09EF8D48);
        AnimStart(&w->unk_048, 2, 1);

        for (i = 0; i < 3; i++) {
            w->unk_164[i] = 0;
            w->unk_158[i] = 0;
            w->unk_170[i] = 0;
        }

        func_080D8B84(&w->unk_164, &w->unk_158, &w->unk_170);
        func_08065ACC(&w->unk_074, 24);
        w->unk_070 = _08066468(1);
        w->unk_074[0xC0] = func_08065B6C(func_080857BC(GetActiveDeckIndex()), &w->unk_074);
        w->unk_010 = LoadObjTiles(gUnk_09957F24, 0x200);
        w->unk_014 = -0x8000;
        w->unk_018 = LoadObjTiles(gUnk_09957C24, 0x300);
        w->unk_01C = 0xF800;
        func_080ECFE8((UnkStruct_080ECFE8*)w, 1);
        w->unk_30E = 1;
        w->unk_30C = w->unk_30F != 0 ? 1 : 16;
        w->unk_310 = func_080ED6CC;
    }

    return 1;
}
#else
INCLUDE_ASM("map/func_080ED498.s");
#endif

#ifndef VERSION_EU
s32 func_080ED6CC(MapMenuWork* w) {
    if (w->unk_30C != 0) {
        ApproachValue(&w->unk_014, 0, w->unk_30C);
        ApproachValue(&w->unk_044, 0x800, w->unk_30C);
        ApproachValue(&w->unk_01C, 0x7800, w->unk_30C);
        ApproachValue(&w->unk_028, 0x9800, w->unk_30C);
        ApproachValue(&w->unk_02C, 0x7000, w->unk_30C);
        ApproachValue(&w->unk_030, 0x8000, w->unk_30C);
        ApproachValue(&w->unk_148, 0xAC00, w->unk_30C);
        ApproachValue(&w->unk_14C, 0x6000, w->unk_30C);
        w->unk_30C--;
    } else {
        w->unk_034 = 1;
        w->unk_06C = (w->unk_309 * 19 + 16) << 8;

        if (w->unk_30F != 0) {
            w->unk_30F = 0;
            func_08006238(0, 16, 1);
            w->unk_310 = func_080EDD7C;
        } else {
            w->unk_310 = (gGameState.flags & 8) ? func_080ED91C : func_080ED7CC;
        }
    }

    return 1;
}
#else
INCLUDE_ASM("map/func_080ED6CC.s");
#endif

s32 func_080ED7CC(MapMenuWork* w) {
    if (GetKeysRepeat() & 0x40) {
        w->unk_309 = w->unk_309 != 0 ? w->unk_309 - 1 : 6;
        m4aSongNumStart(0x65);
    }

    if (GetKeysRepeat() & 0x80) {
        w->unk_309 = w->unk_309 <= 5 ? w->unk_309 + 1 : 0;
        m4aSongNumStart(0x65);
    }

    if (GetKeysPressed() & 10) {
        w->unk_034 = 0;
        w->unk_30C = 16;
        w->unk_310 = func_080EDB4C;
        m4aSongNumStart(0x68);
    } else if (GetKeysPressed() & 1) {
        switch (w->unk_309) {
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
            func_0801CB0C();
            w->unk_310 = func_080EDA90;
            m4aSongNumStart(0x66);
            break;
        case 1:
            if ((u8)(gUnk_0203C590.unk_06 + 4) > 2) {
                func_0801CB0C();
                w->unk_310 = func_080EDA90;
                m4aSongNumStart(0x66);
            } else {
                m4aSongNumStart(0x69);
            }
            break;
        case 6:
            m4aSongNumStart(0x66);
            func_080ED250((u8*)w);
            w->unk_30A = 2;
            w->unk_068 = 0x8800;
            w->unk_310 = func_080EDC94;
            break;
        }
    }
    return 1;
}

s32 func_080ED91C(MapMenuWork* w) {
    if (GetKeysRepeat() & 0x40) {
        w->unk_309 = w->unk_309 != 0 ? w->unk_309 - 1 : 6;
        m4aSongNumStart(101);
    }

    if (GetKeysRepeat() & 0x80) {
        w->unk_309 = w->unk_309 <= 5 ? w->unk_309 + 1 : 0;
        m4aSongNumStart(101);
    }

    if (GetKeysPressed() & 10) {
        w->unk_034 = 0;
        w->unk_30C = 16;
        w->unk_310 = func_080EDB4C;
        m4aSongNumStart(104);
    } else if (GetKeysPressed() & 1) {
        switch (w->unk_309) {
        case 0:
        case 2:
        case 3:
        case 4:
            m4aSongNumStart(102);
            func_0801CB0C();
            w->unk_310 = func_080EDA90;
            break;
        case 5:
            m4aSongNumStart(102);
            func_0801CB0C();
            w->unk_310 = func_080EDA90;
            break;
        case 1:
            if ((u8)(gUnk_0203C590.unk_06 + 4) > 2) {
                m4aSongNumStart(102);
                func_0801CB0C();
                w->unk_310 = func_080EDA90;
            } else {
                m4aSongNumStart(105);
            }
            break;
        case 6:
            m4aSongNumStart(102);
            func_080ED250((u8*)w);
            w->unk_30A = 2;
            w->unk_068 = 0x8800;
            w->unk_310 = func_080EDC94;
            break;
        }
    }

    return 1;
}

s32 func_080EDA90(MapMenuWork* w) {
    gGameState.unk_0F = w->unk_309;

    switch (w->unk_309) {
    case 0:
        if (gGameState.flags & 8) {
            if (gGameState.unk_17A & 0x800) {
                ModeRequest(&gUnk_09EE2704, 0);
            } else {
                ModeRequest(&gModeRikuDeckTutorial, 0);
            }
        } else {
            ModeRequest(&gUnk_09EE2704, 0);
        }
        break;
    case 1:
        ModeRequest(&gModeAllmap, 0);
        break;
    case 4:
        ModeRequest(&gModeStatus, 0);
        break;
    case 2:
        ModeRequest(&gModeMapinspect, 0);
        break;
    case 3:
        ModeRequest(&gModeWorldinspect, 0);
        break;
    case 5:
        ModeRequest(&gModeJiminy, 0);
        break;
    case 6:
        ModeRequest(&gModeMenuMsg, 1);
        break;
    }
    return 1;
}

#ifndef VERSION_EU
s32 func_080EDB4C(MapMenuWork* w) {
    if (w->unk_30C != 0) {
        ApproachValue(&w->unk_014, -0x8000, w->unk_30C);
        ApproachValue(&w->unk_044, -0x7800, w->unk_30C);
        ApproachValue(&w->unk_01C, 0xF800, w->unk_30C);
        ApproachValue(&w->unk_028, 0x11800, w->unk_30C);
        ApproachValue(&w->unk_02C, 0xF000, w->unk_30C);
        ApproachValue(&w->unk_030, 0x10000, w->unk_30C);
        ApproachValue(&w->unk_148, w->unk_150, w->unk_30C);
        ApproachValue(&w->unk_14C, w->unk_154, w->unk_30C);
        w->unk_30C--;
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x1000;
        gUnk_02039BA0->unk_70 &= ~0x100;
        func_080ECFE8((UnkStruct_080ECFE8*)w, 0);
        func_080061E8(0, 16);
        w->unk_30C = 16;
        w->unk_310 = func_080EDC38;
    }
    return 1;
}
#else
INCLUDE_ASM("map/func_080EDB4C.s");
#endif

s32 func_080EDC38(MapMenuWork* w) {
    if (w->unk_30C != 0) {
        ApproachValue(&w->unk_008, -0x800, w->unk_30C);
        ApproachValue(&w->unk_00C, 0xA000, w->unk_30C);
        w->unk_30C--;
        return 1;
    }

    gGameState.unk_0F = 0xFF;
    m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFF, 0x100);
    return 0;
}

s32 func_080EDC94(MapMenuWork* w) {
    if (GetKeysPressed() & 0x20) {
        if (w->unk_30A != 1) {
            w->unk_30A = 1;
            m4aSongNumStart(0x65);
        }
    }

    if (GetKeysPressed() & 0x10) {
        if (w->unk_30A != 2) {
            w->unk_30A = 2;
            m4aSongNumStart(0x65);
        }
    }

    if ((GetKeysPressed() & 2) || ((GetKeysPressed() & 1) && w->unk_30A == 2)) {
        w->unk_30A = 0;
        func_080ED314((u8*)w);
        w->unk_06C = (w->unk_309 * 19 + 16) << 8;
        w->unk_310 = (gGameState.flags & 8) ? func_080ED91C : func_080ED7CC;
        m4aSongNumStart(0x68);
    } else if (GetKeysPressed() & 1) {
        SaveWriteSystem();
        w->unk_310 = func_080EDA90;
        m4aSongNumStart(0x66);
    }
    return 1;
}

s32 func_080EDD7C(MapMenuWork* w) {
    gDispCnt |= 0x1000;
    w->unk_310 = (gGameState.flags & 8) ? func_080ED91C : func_080ED7CC;
    return 1;
}

void func_080EDDBC(MapMenuWork* w) {
    s8 v;

    gUnk_02039BA0->unk_70 |= 0x1000;
    gUnk_02039BA0->unk_70 |= 0x80;
    gUnk_02039BA0->unk_70 |= 0x2000;

    if (gGameState.flags & 8) {
        w->unk_138 = LoadObjPalette(gUnk_09618118, 32);
    } else {
        w->unk_138 = LoadObjPalette(gUnk_08F683A4, 32);
    }

    func_080062F4(w->unk_138->unk_06 + 0x10, 1);
    v = gGameState.unk_0F;

    if (v != -1) {
        w->unk_30F = 1;
    } else {
        gGameState.unk_0F = 0;
        w->unk_30F = 0;
        m4aSongNumStart(0x67);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFF, 0x80);
    }
    w->unk_310 = func_080ED35C;
}

s32 func_080EDE78(MapMenuWork* w) {
    if (w->unk_30F != 0) {
        func_08006120(0, 16);
    }

    if (w->unk_30E != 0) {
        AnimUpdate(&w->unk_048);
    }

    if (w->unk_310 != 0 && (u8)w->unk_310(w) == 0) {
        return 0;
    }
    return 1;
}

#ifndef VERSION_EU
void func_080EDECC(MapMenuWork* w) {
    s32 i;
    s32 k;

    DrawSprite(128, w->unk_008 >> 8, gUnk_09EF8E74[0], w->unk_004, w->unk_000, 0, 0x400, 90);
    DrawSprite(128, w->unk_00C >> 8, gUnk_09EF8E74[1], w->unk_004, w->unk_000, 0, 0x400, 90);

    if (gUnk_0203C7AC->unk_00 & 0x1000) {
        if (gGameState.flags & 8) {
            DrawSprite(w->unk_148 >> 8, w->unk_14C >> 8, gUnk_09EEF89C[0], w->unk_13C, w->unk_138,
                0, 0x400, 80);
        } else {
            DrawSprite(w->unk_148 >> 8, w->unk_14C >> 8, ((void**)gUnk_09EDE8CC)[0], w->unk_13C,
                w->unk_138, 0, 0x400, 80);
        }

        DrawSprite(w->unk_148 >> 8, w->unk_14C >> 8, gUnk_09EE1380[0], w->unk_144, w->unk_140, 0,
            0x400, 81);
    }

    if (w->unk_30E != 0) {
        DrawSprite(w->unk_014 >> 8, 0, gUnk_09EF8E6C[0], w->unk_010, w->unk_000, 0, 0x400, 80);
        DrawSprite(w->unk_01C >> 8, 14, gUnk_09EF8E64[0], w->unk_018, w->unk_000, 0, 0x400, 90);

        if (gGameState.flags & 8) {
            DrawSprite(w->unk_028 >> 8, 0, gUnk_09EF8E80[0], w->unk_024, w->unk_020, 0, 0x400, 80);
            DrawSprite(w->unk_028 >> 8, 0, gUnk_09EF8E80[1], w->unk_024, w->unk_020, 0, 0x400, 81);
            DrawSprite(w->unk_02C >> 8, 103, gUnk_09EF8E80[2], w->unk_024, w->unk_020, 0, 0x400,
                81);

            if (w->unk_164[0] != 0) {
                DrawSprite((w->unk_02C >> 8) + 18, 124, w->unk_170[0], w->unk_164[0],
                    w->unk_158[0], 0, 0x400, 80);
            }
        } else {
            DrawSprite(w->unk_028 >> 8, 0, gUnk_09EF8E0C[0], w->unk_024, w->unk_020, 0, 0x400, 80);
            DrawSprite(w->unk_028 >> 8, 0, gUnk_09EF8E0C[1], w->unk_024, w->unk_020, 0, 0x400, 81);
            DrawSprite(w->unk_02C >> 8, 103, gUnk_09EF8E0C[2], w->unk_024, w->unk_020, 0, 0x400,
                81);

            for (i = 0; i < 3; i++) {
                k = i * 20 + 14;

                if (w->unk_164[i] != 0) {
                    DrawSprite((w->unk_02C >> 8) + k, 124, w->unk_170[i], w->unk_164[i],
                        w->unk_158[i], 0, 0x400, 80);
                }
            }
        }

        if (!(gGameState.flags & 8)) {
            DrawSprite(w->unk_030 >> 8, 144, gUnk_09EF8E0C[3], w->unk_024, w->unk_020, 0, 0x400,
                81);
            func_080664D8((w->unk_030 >> 8) + 16, 145, &w->unk_074, w->unk_070, 50,
                w->unk_074[0xC0]);
        }

        if (w->unk_034 != 0) {
            DrawSprite(w->unk_044 >> 8, 26, gUnk_09EF8E20[w->unk_309], w->unk_040, w->unk_03C, 0,
                0x400, 81);
            DrawSprite(w->unk_044 >> 8, 26, gUnk_09EF8E44[w->unk_309], w->unk_040, w->unk_038, 0,
                0x400, 81);
        } else {
            DrawSprite(w->unk_044 >> 8, 26, gUnk_09EF8E20[7], w->unk_040, w->unk_03C, 0, 0x400,
                80);
        }

        if (w->unk_034 != 0) {
            switch (w->unk_30A) {
            case 1:
                func_0805F1C0(&w->unk_068, 0x4800);
                DrawSprite(w->unk_068 >> 8, 80, AnimGetGfx(&w->unk_048), w->unk_064, w->unk_060, 0,
                    1, 60);
                break;
            case 2:
                func_0805F1C0(&w->unk_068, 0x8800);
                DrawSprite(w->unk_068 >> 8, 80, AnimGetGfx(&w->unk_048), w->unk_064, w->unk_060, 0,
                    1, 60);
                break;
            case 0:
            default:
                func_0805F1C0(&w->unk_06C, (w->unk_309 * 19 + 16) << 8);
                DrawSprite(24, w->unk_06C >> 8, AnimGetGfx(&w->unk_048), w->unk_064, w->unk_060, 0,
                    0x401, 60);
                break;
            }
        }

        if (w->unk_30A != 0) {
            func_080664D8((240 - func_08065B08(w->unk_180, w->unk_288)) / 2, 64, w->unk_180,
                w->unk_17C, 70, w->unk_288);
            func_080664D8(80, 84, w->unk_28C, w->unk_17C, 70, w->unk_2BC);
            func_080664D8(144, 84, w->unk_2C0, w->unk_17C, 70, w->unk_308);
        }
    }
}
#else
INCLUDE_ASM("map/func_080EDECC.s");
#endif

void func_080EE418(MapMenuWork* w) {
    s32 i;

    func_080ED06C((UnkStruct_080ED06C*)w, 0);
    func_080ECFE8((UnkStruct_080ECFE8*)w, 0);
    ReleaseObjPalette(w->unk_000);
    ReleaseObjTiles(w->unk_004);
    ReleaseObjTiles(w->unk_010);
    ReleaseObjTiles(w->unk_018);
    ReleaseObjPalette(w->unk_020);
    ReleaseObjTiles(w->unk_024);
    ReleaseObjPalette(w->unk_038);
    ReleaseObjPalette(w->unk_03C);
    ReleaseObjTiles(w->unk_040);
    ReleaseObjPalette(w->unk_060);
    ReleaseObjTiles(w->unk_064);
    ReleaseObjPalette((u8*)w->unk_138);
    ReleaseObjTiles(w->unk_13C);
    ReleaseObjPalette(w->unk_140);
    ReleaseObjTiles(w->unk_144);

    for (i = 0; i < 3; i++) {
        if (w->unk_164[i] != 0) {
            ReleaseObjTiles(w->unk_164[i]);
            ReleaseObjPalette(w->unk_158[i]);
        }
    }

    func_08065AE0(w->unk_074, 24);
    ReleaseObjPalette(w->unk_070);
    gUnk_0203C7AC->unk_00 &= ~0x80;
    gUnk_02039BA0->unk_70 &= ~0x1000;
    gUnk_02039BA0->unk_70 &= ~0x80;
    gUnk_02039BA0->unk_70 &= ~0x2000;
}

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

s32 func_080EE7B0(MapSaveWork* w) {
    if (w->unk_2F6 != 0) {
        ApproachValue(&w->unk_008, 0, w->unk_2F6);
        ApproachValue(&w->unk_00C, 0x9800, w->unk_2F6);
        w->unk_2F6 -= 1;
    } else {
        gUnk_0203C7AC->unk_00 |= 0x1000;
        gUnk_02039BA0->unk_70 |= 0x100;
        w->unk_2F6 = 16;
        w->unk_2F0 = func_080EE824;
    }
    return 1;
}

#ifndef VERSION_EU
s32 func_080EE824(MapSaveWork* w) {
    u8* p1;
    u8* p2;
    u8* p3;

    if (w->unk_2F6 != 0) {
        ApproachValue(&w->unk_010, 0, w->unk_2F6);

        if (gGameState.flags & 8) {
            ApproachValue(&w->unk_170, 0x3800, w->unk_2F6);
            ApproachValue(&w->unk_174, 0x7000, w->unk_2F6);
        } else {
            ApproachValue(&w->unk_170, 0x3800, w->unk_2F6);
            ApproachValue(&w->unk_174, 0x7000, w->unk_2F6);
        }
        w->unk_2F6 -= 1;
    } else {
        if (!(gGameState.flags & 8)) {
            w->unk_040 = LoadObjPalette(gUnk_09991C04, 32);
        } else {
            w->unk_040 = LoadObjPalette(gUnk_09991C44, 32);
        }

        w->unk_044[0x120] = 0;
        func_08065ACC(w->unk_044, 36);
        SetupBg(0, 3, 31, 11);
        SetBgPriority(0, 0);
        LoadBgPalette(0, gUnk_09991C84, 128);
        LoadBgTiles(0, gUnk_099661A4, 0x1FA0);

        if (gGameState.flags & 8) {
            if (gGameState.flags & 0x10) {
                LoadBgMap(0, gUnk_0998C744, 0x800);

                if (SaveRepairFileSmall(1) == 2) {
                    func_080EE760((u8*)w, 3);
                }
            } else {
                LoadBgMap(0, gUnk_0998BF44, 0x800);

                if (SaveRepairFileSmall(0) == 2) {
                    func_080EE760((u8*)w, 2);
                }
            }
        } else {
            if (gGameState.flags & 0x10) {
                LoadBgMap(0, gUnk_0998B744, 0x800);

                if (SaveRepairFileLarge(1) == 2) {
                    func_080EE760((u8*)w, 1);
                }
            } else {
                LoadBgMap(0, gUnk_0998AF44, 0x800);

                if (SaveRepairFileLarge(0) == 2) {
                    func_080EE760((u8*)w, 0);
                }
            }
        }

        SetBgScroll(0, 0, 0xFFFB);
        w->unk_184 = AllocObjTiles(0x280, gUnk_0919FDF8);
        w->unk_18C = AllocObjTiles(0x400, gUnk_091ABDB8);
        w->unk_014 = LoadObjPalette(gUnk_09991D24, 32);
        w->unk_018 = LoadObjTiles(gUnk_098A8F8A, 0x4C0);
        w->unk_034 = LoadObjPalette(gUnk_099919A4, 32);
        w->unk_038 = AllocObjTiles(0x120, gUnk_098A8628);
        AnimInit(&w->unk_01C, gUnk_09EF8D58, gUnk_09EF8D48);
        AnimStart(&w->unk_01C, 2, 1);
        w->unk_190 = _08066468(1);
        p1 = w->unk_194;
        func_08065ACC(p1, 27);
        p2 = w->unk_270;
        func_08065ACC(p2, 6);
        p3 = w->unk_2A4;
        func_08065ACC(p3, 9);
        w->unk_26C = func_08065B6C(gUnk_08159DF0, p1);
        w->unk_2A0 = func_08065B6C(gUnk_08159E10, p2);
        w->unk_2EC = func_08065B6C(gUnk_08159E18, p3);
        func_080EE50C((UnkStruct_080EE50C*)w, 1);
        w->unk_2F8 = 1;
        w->unk_2F4 = 2;
        w->unk_03C = 0xB000;
        w->unk_2F0 = func_080EEB00;
    }
    return 1;
}
#else
INCLUDE_ASM("map/func_080EE824.s");
#endif

#ifndef VERSION_EU
s32 func_080EEB00(MapSaveWork* w) {
    if (GetKeysRepeat() & 0x20) {
        if (w->unk_2F4 != 1) {
            w->unk_2F4 = 1;
            m4aSongNumStart(101);
        }
    }

    if (GetKeysRepeat() & 0x10) {
        if (w->unk_2F4 != 2) {
            w->unk_2F4 = 2;
            m4aSongNumStart(101);
        }
    }

    if ((GetKeysPressed() & 2) || ((GetKeysPressed() & 1) && w->unk_2F4 != 1)) {
        m4aSongNumStart(104);
        w->unk_2F4 = 0;
        w->unk_2F8 = 0;
        w->unk_2F6 = 16;
        w->unk_2F0 = func_080EEC9C;
        DisableBg(0);
    } else if (GetKeysPressed() & 1) {
        m4aSongNumStart(211);

        if (gGameState.flags & 8) {
            if (gGameState.flags & 0x10) {
                SaveWriteFileSmall(1);
                func_080EE760((u8*)w, 3);
            } else {
                SaveWriteFileSmall(0);
                func_080EE760((u8*)w, 2);
            }
        } else {
            if (gGameState.flags & 0x10) {
                SaveWriteFileLarge(1);
                func_080EE760((u8*)w, 1);
            } else {
                SaveWriteFileLarge(0);
                func_080EE760((u8*)w, 0);
            }
        }

        w->unk_26C = func_08065B6C(gUnk_0815B5A6, w->unk_194);
        w->unk_2A0 = 0;
        w->unk_2EC = 0;
        w->unk_2F4 = 0;
        w->unk_2F0 = func_080EEC5C;
    }

    return 1;
}
#else
INCLUDE_ASM("map/func_080EEB00.s");
#endif

s32 func_080EEC5C(MapSaveWork* w) {
    if (GetKeysPressed() & 3) {
        w->unk_2F8 = 0;
        DisableBg(0);
        w->unk_2F6 = 16;
        w->unk_2F0 = func_080EEC9C;
    }

    return 1;
}

s32 func_080EEC9C(MapSaveWork* w) {
    if (w->unk_2F6 != 0) {
        ApproachValue(&w->unk_010, -0x8000, w->unk_2F6);
        ApproachValue(&w->unk_170, w->unk_178, w->unk_2F6);
        ApproachValue(&w->unk_174, w->unk_17C, w->unk_2F6);
        w->unk_2F6--;
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x1000;
        gUnk_02039BA0->unk_70 &= ~0x100;
        func_080EE50C((UnkStruct_080EE50C*)w, 0);
        func_080061E8(0, 16);
        w->unk_2F6 = 16;
        w->unk_2F0 = func_080EED44;
    }

    return 1;
}

s32 func_080EED44(MapSaveWork* w) {
    if (w->unk_2F6 != 0) {
        ApproachValue(&w->unk_008, -0x800, w->unk_2F6);
        ApproachValue(&w->unk_00C, 0xA000, w->unk_2F6);
        w->unk_2F6--;
        return 1;
    }

    return 0;
}

#ifndef VERSION_EU
void func_080EED88(MapSaveWork* w) {
    gUnk_02039BA0->unk_70 |= 0x1000;
    gUnk_02039BA0->unk_70 |= 0x80;
    gUnk_0203C7AC->unk_00 |= 0x2000;
    gGameState.unk_32 = gGameState.unk_F8;
    w->unk_000 = LoadObjPalette(gUnk_09991D04, 32);
    w->unk_004 = LoadObjTiles(gUnk_098A8C66, 0x2C0);
    w->unk_008 = -0x800;
    w->unk_00C = 0xA000;
    w->unk_010 = -0x8000;

    if (gGameState.flags & 8) {
        w->unk_16C = AllocObjTiles(0x400, gUnk_092EB78A);
        w->unk_168 = LoadObjPalette(gUnk_09618118, 32);
    } else {
        w->unk_16C = AllocObjTiles(0x340, gUnk_088B6560);
        w->unk_168 = LoadObjPalette(gUnk_08F683A4, 32);
    }

    w->unk_180 = LoadObjPalette(gUnk_09617C58, 32);
    w->unk_188 = LoadObjPalette(gUnk_08F68384, 32);
    w->unk_178 = gUnk_02039BA0->unk_18 - gUnk_02039BA0->unk_00;
    w->unk_17C = gUnk_02039BA0->unk_1C + gUnk_02039BA0->unk_20 - gUnk_02039BA0->unk_04;
    w->unk_170 = w->unk_178;
    w->unk_174 = w->unk_17C;
    w->unk_2F4 = 0;
    w->unk_2F8 = 0;
    w->unk_2F6 = 16;
    w->unk_2F0 = func_080EE7B0;
    TaskPoolInit(&w->unk_2FC, 1);
    func_080EE580((UnkStruct_080EE580*)w, 1);
    func_08006238(0, 16, 16);
    m4aSongNumStart(103);
}
#else
INCLUDE_ASM("map/func_080EED88.s");
#endif

#ifndef VERSION_EU
s32 func_080EEF04(MapSaveWork* w) {
    TaskPoolUpdate(&w->unk_2FC);

    if (w->unk_2F4 != 0) {
        AnimUpdate(&w->unk_01C);
    }

    if (w->unk_2F0 != 0) {
        if ((u8)w->unk_2F0(w) == 0) {
            return 0;
        }
    }
    return 1;
}
#else
INCLUDE_ASM("map/func_080EEF04.s");
#endif

#ifndef VERSION_EU
void func_080EEF4C(MapSaveWork* w) {
    TaskPoolDraw(&w->unk_2FC);
    DrawSprite(128, w->unk_008 >> 8, gUnk_09EF8D8C[1], w->unk_004, w->unk_000, 0, 0x400, 90);
    DrawSprite(128, w->unk_00C >> 8, gUnk_09EF8D8C[2], w->unk_004, w->unk_000, 0, 0x400, 90);
    DrawSprite(w->unk_010 >> 8, 0, gUnk_09EF8D8C[0], w->unk_004, w->unk_000, 0, 0x400, 80);

    if (gUnk_0203C7AC->unk_00 & 0x1000) {
        if (gGameState.flags & 8) {
            DrawSprite(w->unk_170 >> 8, w->unk_174 >> 8, gUnk_09EEF89C[0], w->unk_16C, w->unk_168,
                0, 0x400, 80);
        } else {
            DrawSprite(w->unk_170 >> 8, w->unk_174 >> 8, ((void**)gUnk_09EDE8CC)[0], w->unk_16C,
                w->unk_168, 0, 0x400, 80);
        }
    }

    if (w->unk_2F8 != 0) {
        if (!(gGameState.flags & 8)) {
            DrawSprite(72, 96, ((void**)gUnk_09EEE03C)[0], w->unk_184, w->unk_180, 0, 0x401, 81);
            DrawSprite(40, 96, ((void**)gUnk_09EEE1C8)[0], w->unk_18C, w->unk_188, 0, 0x400, 81);
        }

        DrawSprite(0, 16, gUnk_098A8F28, w->unk_018, w->unk_014, 0, 0x400, 90);
        func_080664D8(100, 59, w->unk_044, w->unk_040, 50, w->unk_044[0x120]);

        if (w->unk_2F4 != 0) {
#ifdef VERSION_JP
            func_080664D8(129, 92, w->unk_194, w->unk_190, 50, w->unk_26C);
#else
            func_080664D8(124, 92, w->unk_194, w->unk_190, 50, w->unk_26C);
#endif
            func_080664D8(128, 114, w->unk_270, w->unk_190, 50, w->unk_2A0);
            func_080664D8(184, 114, w->unk_2A4, w->unk_190, 50, w->unk_2EC);
        } else {
#ifdef VERSION_JP
            func_080664D8(129, 103, w->unk_194, w->unk_190, 50, w->unk_26C);
#else
            func_080664D8(130, 102, w->unk_194, w->unk_190, 50, w->unk_26C);
#endif
        }

        switch (w->unk_2F4) {
        case 1:
            func_0805F1C0(&w->unk_03C, 0x7800);
            DrawSprite(w->unk_03C >> 8, 110, AnimGetGfx(&w->unk_01C), w->unk_038, w->unk_034, 0, 1,
                40);
            break;
        case 2:
            func_0805F1C0(&w->unk_03C, 0xB000);
            DrawSprite(w->unk_03C >> 8, 110, AnimGetGfx(&w->unk_01C), w->unk_038, w->unk_034, 0, 1,
                40);
            break;
        }
    }
}
#else
INCLUDE_ASM("map/func_080EEF4C.s");
#endif

void func_080EF234(MapSaveWork* w) {
    u32 f;

    func_080EE580((UnkStruct_080EE580*)w, 0);
    ReleaseObjPalette((u8*)w->unk_000);
    ReleaseObjTiles(w->unk_004);
    ReleaseObjPalette((u8*)w->unk_014);
    ReleaseObjTiles(w->unk_018);
    ReleaseObjPalette((u8*)w->unk_034);
    ReleaseObjTiles(w->unk_038);
    ReleaseObjPalette((u8*)w->unk_168);
    ReleaseObjTiles(w->unk_16C);
    ReleaseObjPalette((u8*)w->unk_180);
    ReleaseObjTiles(w->unk_184);
    ReleaseObjPalette((u8*)w->unk_188);
    ReleaseObjTiles(w->unk_18C);
    ReleaseObjPalette((u8*)w->unk_040);
    func_08065AE0(w->unk_044, 36);
    ReleaseObjPalette((u8*)w->unk_190);
#ifdef VERSION_EU
    func_08065AE0(w->unk_194, 54);
#else
    func_08065AE0(w->unk_194, 27);
#endif
    func_08065AE0(w->unk_270, 6);
    func_08065AE0(w->unk_2A4, 9);
    f = gUnk_0203C7AC->unk_00 & ~0x80;
    gUnk_0203C7AC->unk_00 = f;
    gUnk_02039BA0->unk_70 &= ~0x1000;
    gUnk_02039BA0->unk_70 &= ~0x80;
    gUnk_0203C7AC->unk_00 = f & ~0x2000;
    TaskPoolDestroy(&w->unk_2FC);
}

void func_080EF32C(MapAnmWork* work, MapAnmEntry* list) {
    UnkStruct_080E8B1C* e;
    s32 i;

    e = work->unk_00;

    for (i = 0; i < 8; i++) {
        func_080E8BB4(e);
        e++;
    }

    if (list != 0) {
        if (list->unk_00 != 0) {
            e = work->unk_00;

            do {
                func_080E8B1C(e, (UnkStruct_080E7D80*)list);
                e++;
                list++;
            } while (list->unk_00 != 0);
        }
    }
}

s32 func_080EF368(MapAnmWork* w) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (w->unk_00[i].unk_14 != 0) {
            func_080E8BA0(&w->unk_00[i]);
        }
    }
    return 1;
}

void func_080EF398(MapAnmWork* w) {
}

void func_080EF39C(MapAnmWork* w) {
}

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

void func_080EF508(UnkStruct_080E590C* p) {
    s32 z;

    func_080E5D6C(p, 0, 0);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished(p->anim)) {
        if (p->unk_04 & 8) {
            p->unk_CC = func_080EF7B8;
        } else {
            p->unk_CC = func_080EF58C;
        }
        *(u16*)&p->unk_D0 = z = 0;
        func_08012614(p->unk_48, z);
    } else {
        func_080E5DEC(p);

        if (*(s16*)&p->unk_E0 > 0) {
            (*(s16*)&p->unk_E0)--;

            if (*(s16*)&p->unk_E0 <= 0) {
                func_08012614(p->unk_48, 0);
            }
        }
    }
}

void func_080EF58C(UnkStruct_080E590C* p) {
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&p->unk_08;
    s32 x;
    s32 y;
    s32 v;

    func_080E5D6C(p, 1, 1);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);
    x = p->unk_08.unk_00;
    y = q->unk_04;

    if ((u8)func_080EF4BC(p) != 0) {
        p->unk_D0 = 0;
        p->unk_CC = func_080EF718;
    } else if (GetRandom() % 80 == 0) {
        switch (GetRandom() % 4) {
        case 0:
            v = 173;
            break;
        case 1:
            v = 83;
            break;
        case 2:
            v = 211;
            break;
        default:
            v = 45;
            break;
        }
        ((u8*)q)[0x14] = v;
        p->unk_D0 = 0;
        p->unk_CC = func_080EF664;
    }

    if ((u8)func_080E5FB4(p) != 0) {
        p->unk_CC = func_080EF88C;
    } else {
        func_080E5F50(p);

        if ((u8)func_080EF3A0(p) == 0) {
            func_080EF478(p, x, y);
        }
    }
}

void func_080EF664(UnkStruct_080E590C* p) {
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&p->unk_08;
    s32 x;
    s32 y;

    func_080E5D6C(p, 2, 1);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);
    x = p->unk_08.unk_00;
    y = q->unk_04;

    if ((u8)func_080EF4BC(p) != 0) {
        p->unk_D0 = 0;
        p->unk_CC = func_080EF718;
    } else if (GetRandom() % 80 == 0) {
        q->unk_10 = 0;
        p->unk_CC = func_080EF58C;
    } else {
        func_080EF404(p, 12, 0x80);
    }

    if ((u8)func_080E5FB4(p) != 0) {
        p->unk_CC = func_080EF88C;
    } else {
        func_080E5F50(p);

        if ((u8)func_080EF3A0(p) == 0) {
            func_080EF478(p, x, y);
        }
    }
}

void func_080EF718(UnkStruct_080E590C* p) {
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&p->unk_08;
    s32 x;
    s32 y;

    func_080E5D6C(p, 2, 1);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);
    x = q->unk_00;
    y = q->unk_04;

    if (p->unk_D0 % 8 == 0) {
        if ((u8)func_080EF4BC(p) == 0) {
            q->unk_10 = 0;
            p->unk_CC = func_080EF58C;
        }
    }
    func_080EF404(p, 12, 0x180);
    p->unk_D0++;

    if ((u8)func_080E5FB4(p) != 0) {
        p->unk_CC = func_080EF88C;
    } else {
        func_080E5F50(p);

        if ((u8)func_080EF3A0(p) == 0) {
            func_080EF478(p, x, y);
        }
    }
}

void func_080EF7B8(UnkStruct_080E590C* p) {
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&p->unk_08;
    s32 x;
    s32 y;

    func_080E5D6C(p, 2, 1);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);
    x = q->unk_00;
    y = q->unk_04;

    if (p->unk_D0 % 8 == 0) {
        q->unk_14 = GetAngle(x, y, gUnk_02039BA0->unk_18, gUnk_02039BA0->unk_1C);
    }
    func_080EF404(p, 25, 0x200);

    if ((u8)func_080E5FB4(p) != 0) {
        p->unk_CC = func_080EF88C;
    } else {
        func_080E5F50(p);
        func_080EF478(p, x, y);
        p->unk_D0++;
    }
}

void func_080EF84C(UnkStruct_080E590C* p) {
    p->unk_04 |= 4;
    func_080E5D6C(p, 3, 0);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished(p->anim)) {
        p->unk_CC = 0;
    }
}

void func_080EF88C(UnkStruct_080E590C* p) {
    func_080E5D6C(p, 4, 0);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished(p->anim)) {
        p->unk_04 |= 0x40;
        func_080E5EAC(p);
    } else {
        func_080E5DEC(p);
    }
}

void func_080EF8CC(UnkStruct_080E590C* p) {
    func_080E5D6C(p, 1, 0);
    p->gfx = AnimGetGfx(p->anim);
    TaskPoolUpdate(p->unk_E4);

    if ((u8)func_080E5FB4(p) != 0) {
        p->unk_CC = func_080EF88C;
    } else {
        func_080E5F50(p);
    }
}

void func_080EF914(UnkStruct_080E590C* p, UnkStruct_080E5B90* q) {
    func_080E6394(p, q);

    if (p->unk_CC == 0) {
        if (p->unk_04 & 0x20) {
            p->unk_CC = func_080EF8CC;
            func_080E5D6C(p, 1, 0);
            p->gfx = AnimGetGfx(p->anim);
            func_08012614(p->unk_48, 0);
        } else {
            p->unk_CC = func_080EF508;
            func_080E5D6C(p, 0, 0);
            p->gfx = AnimGetGfx(p->anim);
            func_08012614(p->unk_48, 1);
        }
    } else {
        func_08012614(p->unk_48, 0);
    }
    *(u16*)&p->unk_D0 = 0;
}

s32 func_080EF9A0(UnkStruct_080E590C* p) {
    UnkStruct_080DFF1C* q = &p->unk_08;

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        func_080E6034(p);
        return 0;
    }

    if ((gUnk_0203C7AC->unk_00 & 4) && p->unk_CC != func_080EF88C) {
        return 1;
    }

    if (p->unk_CC != 0) {
        p->unk_CC(p);

        if (p->unk_CC != 0) {
            func_08012324(p->unk_48, q->unk_00, q->x, q->y);
            return 1;
        }
    }
    return 0;
}

void func_080EFA18(UnkStruct_080E590C* p) {
    func_080E64D4(p);
}

void func_080EFA24(UnkStruct_080E590C* p) {
    func_080E657C(p);
}

void func_080EFA30(UnkStruct_080EFA30* p) {
    if (p->unk_08 < gUnk_02039BA0->unk_00 - 0x1800 || p->unk_08 > gUnk_02039BA0->unk_00 + 0x10800) {
        if (p->unk_F8 != 0) {
            p->unk_CC = 0;
        }
    } else if (p->unk_F8 == 0) {
        p->unk_F8 = 1;
    }
}

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

void func_080EFB24(UnkStruct_080F023C* w, u8 a) {
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;

    if (a != 0) {
        w->unk_D4 = gUnk_02039BA0->unk_18;
        w->unk_D8 = gUnk_02039BA0->unk_1C;
        w->unk_DC = gUnk_02039BA0->unk_20 - 0x1000;
    } else {
        w->unk_D4 = gUnk_02039BA0->unk_18;
        w->unk_D8 = gUnk_02039BA0->unk_1C;
        w->unk_DC = gUnk_02039BA0->unk_20;

        if (GetRandom() % 2) {
            t1 = GetRandom() % 65 * 256;
            t1 += 0x2000;
            w->unk_D4 -= t1;
        } else {
            t2 = GetRandom() % 65 * 256;
            t2 += 0x2000;
            w->unk_D4 += t2;
        }

        t3 = GetRandom() % 121 * 256;
        t3 -= 0x3C00;
        w->unk_D8 += t3;
        t4 = GetRandom() % 49 * 256;
        t4 += 0x1000;
        w->unk_DC -= t4;
    }
}

void func_080EFC08(UnkStruct_080E590C* p) {
    UnkStruct_080E590C* w = p;
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&p->unk_08;

    func_080E5D6C(p, 0, 3);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);
    func_080EFA7C((UnkStruct_080F023C*)p, 0);

    if (GetRandom() % 20 == 0) {
        q->unk_14 = GetAngle(p->unk_08.unk_00, q->unk_04, gUnk_02039BA0->unk_18, gUnk_02039BA0->unk_1C);
    }

    if (q->unk_08 < gUnk_02039BA0->unk_20 - 0x4000) {
        func_080EFB24((UnkStruct_080F023C*)p, 0);
        p->unk_D0 = 0;
        q->unk_10 = 0;
        p->unk_CC = func_080EFCF4;
    } else if (GetRandom() % 130 == 0) {
        if (GetRandom() % 2 != 0) {
            func_080EFB24((UnkStruct_080F023C*)p, 0);
        } else {
            func_080EFB24((UnkStruct_080F023C*)p, 1);
        }
        w->unk_D0 = 0;
        q->unk_10 = 0;
        w->unk_CC = func_080EFCF4;
    }

    if ((u8)func_080E5FB4(w) != 0) {
        w->unk_CC = func_080EFE54;
    } else {
        func_080E5F50(w);
        func_080EFA30((UnkStruct_080EFA30*)p);
    }
}

void func_080EFCF4(UnkStruct_080E590C* p) {
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&p->unk_08;
    UnkStruct_080DFF1C t;
    s32 dx;
    s32 dy;
    s32 v;
    s32 r;
    u32 lim;

    func_080E5D6C(p, 1, 3);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);
    func_080EFA7C((UnkStruct_080F023C*)p, 1);
    t = p->unk_08;

    if (GetRandom() % 20 != 0) {
        q->unk_14 = GetAngle(p->unk_08.unk_00, q->unk_04, gUnk_02039BA0->unk_18, gUnk_02039BA0->unk_1C);
    }

    dx = p->unk_D4;
    dy = p->unk_D8;

    if (p->unk_04 & 16) {
        lim = 0x140;
        q->unk_10 += 10;

        if (q->unk_10 > 76) {
            q->unk_10 = 76;
        }
    } else {
        lim = 64;
        q->unk_10 += 51;

        if (q->unk_10 > 0x180) {
            q->unk_10 = 0x180;
        }
    }

    v = (dx - q->unk_00) >> 5;

    if (v > q->unk_10) {
        v = q->unk_10;
    } else if (v < -q->unk_10) {
        v = -q->unk_10;
    }

    q->unk_00 += v;
    v = (dy - q->unk_04) >> 5;

    if (v > q->unk_10) {
        v = q->unk_10;
    } else if (v < -q->unk_10) {
        v = -q->unk_10;
    }

    q->unk_04 += v;

    if (p->unk_D0 > lim) {
        p->unk_CC = func_080EFC08;
    } else {
        p->unk_D0++;
    }

    r = func_080DFF1C((UnkStruct_080DFF1C*)q);

    if (r < q->unk_08) {
        *(UnkStruct_080DFF1C*)q = t;
        p->unk_D8 = q->unk_04 + 0x1000;
    } else if (r == 0x100000) {
        *(UnkStruct_080DFF1C*)q = t;
        p->unk_D8 = q->unk_04 - 0x1000;
    } else {
        q->unk_0C = r;
    }

    if ((u8)func_080E5FB4(p) != 0) {
        p->unk_CC = func_080EFE54;
    } else {
        func_080E5F50(p);
    }
}

void func_080EFE54(UnkStruct_080E590C* p) {
    func_080E5D6C(p, 2, 0);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished((AnimState*)p->anim)) {
        p->unk_04 |= 0x40;
        func_080E5EAC(p);
    } else {
        func_080E5DEC(p);
    }
}

void func_080EFE94(UnkStruct_080E590C* p) {
    func_080E5D6C(p, 0, 0);
    p->gfx = AnimGetGfx(p->anim);
    TaskPoolUpdate(p->unk_E4);

    if ((u8)func_080E5FB4(p) != 0) {
        p->unk_CC = func_080EFE54;
    } else {
        func_080E5F50(p);
    }
}

void func_080EFEDC(UnkStruct_080E590C* p, UnkStruct_080E5B90* q) {
    UnkStruct_080EFA30* w = (UnkStruct_080EFA30*)p;

    func_080E6394(p, q);

    if (p->unk_04 & 0x20) {
        p->unk_CC = func_080EFE94;
        func_080E5D6C(p, 0, 0);
        p->gfx = AnimGetGfx(p->anim);
        func_08012614(p->unk_48, 0);
    } else {
        p->unk_CC = func_080EFC08;
        func_080E5D6C(p, 0, 1);
        p->gfx = AnimGetGfx(p->anim);
        func_08012614(p->unk_48, 0);
    }
    w->unk_D0 = 0;
    ((UnkStruct_080EFA30*)p)->unk_F8 = 0;
}

s32 func_080EFF64(UnkStruct_080E590C* p) {
    UnkStruct_080E590C* q = p;
    UnkStruct_080DFF1C* pos = &p->unk_08;

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        func_080E6034(p);
        return 0;
    }

    if ((gUnk_0203C7AC->unk_00 & 4) && p->unk_CC != func_080EFE54) {
        return 1;
    }

    if (p->unk_CC != 0) {
        ((void (*)(UnkStruct_080E590C*))p->unk_CC)(q);

        if (p->unk_CC != 0) {
            func_08012324(&p->unk_48, pos->unk_00, pos->x, pos->y);
            return 1;
        }
    }

    return 0;
}

void func_080EFFE0(UnkStruct_080E590C* p) {
    func_080E64D4(p);
}

void func_080EFFEC(UnkStruct_080E590C* p) {
    func_080E657C(p);
}

void func_080EFFF8(UnkStruct_080E590C* p) {
    func_080E5D6C(p, 0, 1);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);

    if (func_080E02E0(&p->unk_08, p->unk_C8, p->unk_CA)) {
        m4aSongNumStart(0x75);
        gUnk_0203C7AC->unk_00 |= 0x80;
        gUnk_0203C7AC->unk_00 |= 4;
        func_080E5EAC(p);
    }
    func_080E5F50(p);
}

void func_080F005C(UnkStruct_080E590C* p, UnkStruct_080E5B90* q) {
    func_080E6394(p, q);
    p->unk_CC = func_080EFFF8;
    func_080E5D6C(p, 0, 1);
    p->gfx = AnimGetGfx(p->anim);
    func_08012614(p->unk_48, 0);
}

s32 func_080F0098(UnkStruct_080E590C* p) {
    UnkStruct_080E590C* w = p;
    UnkStruct_080DFF1C* q = &w->unk_08;

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        func_080E6034(p);
        return 0;
    }

    if (w->unk_CC != 0) {
        ((void (*)(UnkStruct_080E590C*))w->unk_CC)(w);

        if (w->unk_CC != 0) {
            func_08012324(w->unk_48, q->unk_00, q->x, q->y);
            return 1;
        }
    }
    return 0;
}

void func_080F00F0(UnkStruct_080E590C* p) {
    func_080E64D4(p);
}

void func_080F00FC(UnkStruct_080E590C* p) {
    func_080E657C(p);
}

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

void func_080F02A0(UnkStruct_080F023C* w) {
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&w->unk_08;

    func_080E5D6C((UnkStruct_080E590C*)w, 0, 3);
    func_080E5DEC((UnkStruct_080E590C*)w);
    TaskPoolUpdate(&w->unk_E4);
    func_080F0108(w, 0);

    if (GetRandom() % 20 == 0) {
        q->unk_14 = GetAngle(w->unk_08, q->unk_04, gUnk_02039BA0->unk_18, gUnk_02039BA0->unk_1C);
    }

    if ((u8)func_080F023C(w, 0x6000) != 0 && q->unk_0C == gUnk_02039BA0->unk_24) {
        w->unk_D4 = gUnk_02039BA0->unk_18;
        w->unk_D8 = gUnk_02039BA0->unk_1C;
        w->unk_DC = gUnk_02039BA0->unk_24 - 0x1000;
        w->unk_D0 = 0;
        q->unk_10 = 0;
        w->unk_CC = func_080F0348;
    }
    func_080E5F50((UnkStruct_080E590C*)w);
}

void func_080F0348(UnkStruct_080F023C* w) {
    UnkStruct_080F023C* q = w;
    UnkStruct_080EF4BC* v = (UnkStruct_080EF4BC*)&w->unk_08;
    UnkStruct_080DFF1C tmp;
    s32 n;

    func_080E5D6C((UnkStruct_080E590C*)w, 1, 3);
    func_080E5DEC((UnkStruct_080E590C*)w);
    TaskPoolUpdate(&w->unk_E4);
    func_080F0108(w, 1);
    tmp = *(UnkStruct_080DFF1C*)v;

    if (GetRandom() % 20 != 0) {
        v->unk_14 = GetAngle(w->unk_08, v->unk_04, gUnk_02039BA0->unk_18, gUnk_02039BA0->unk_1C);
    }

    if ((u8)func_080F023C(w, 0x6000) != 0 && v->unk_0C == gUnk_02039BA0->unk_24) {
        w->unk_D4 = gUnk_02039BA0->unk_18;
        w->unk_D8 = gUnk_02039BA0->unk_1C;
    }

    if ((u8)func_080F01B0(q) != 0) {
        w->unk_D4 = q->unk_F8;
        w->unk_D8 = q->unk_FC;
        w->unk_DC = q->unk_100;
        w->unk_D0 = 0;
        v->unk_10 = 0;
        w->unk_CC = func_080F0470;
    }

    n = func_080DFF1C((UnkStruct_080DFF1C*)v);

    if (n < v->unk_08) {
        *(UnkStruct_080DFF1C*)v = tmp;
        w->unk_D8 = v->unk_04 + 0x1000;
    } else if (n == 0x100000) {
        *(UnkStruct_080DFF1C*)v = tmp;
        w->unk_D8 = v->unk_04 - 0x1000;
    } else {
        v->unk_0C = n;
    }

    func_080E5F50((UnkStruct_080E590C*)w);
}

void func_080F0470(UnkStruct_080F023C* w) {
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&w->unk_08;
    UnkStruct_080DFF1C save;
    s32 r;

    func_080E5D6C((UnkStruct_080E590C*)w, 1, 3);
    func_080E5DEC((UnkStruct_080E590C*)w);
    TaskPoolUpdate(&w->unk_E4);
    func_080F0108(w, 1);
    save = *(UnkStruct_080DFF1C*)q;

    if (GetRandom() % 20 != 0) {
        q->unk_14 = GetAngle(w->unk_08, q->unk_04, gUnk_02039BA0->unk_18, gUnk_02039BA0->unk_1C);
    }

    if ((u8)func_080F01B0(w) != 0) {
        w->unk_D0 = 0;
        q->unk_10 = 0;
        w->unk_CC = func_080F02A0;
    }

    r = func_080DFF1C((UnkStruct_080DFF1C*)q);

    if (r < q->unk_08) {
        *(UnkStruct_080DFF1C*)q = save;
        w->unk_D8 = q->unk_04 + 0x1000;
    } else if (r == 0x100000) {
        *(UnkStruct_080DFF1C*)q = save;
        w->unk_D8 = q->unk_04 - 0x1000;
    } else {
        q->unk_0C = r;
    }
    func_080E5F50((UnkStruct_080E590C*)w);
}

void func_080F0550(UnkStruct_080F023C* w, UnkStruct_080E5B90* arg) {
    func_080E6394((UnkStruct_080E590C*)w, arg);
    w->unk_CC = func_080F02A0;
    func_080E5D6C((UnkStruct_080E590C*)w, 0, 1);
    w->unk_C4 = AnimGetGfx(&w->unk_A4);
    func_08012614(&w->unk_48, 0);
    w->unk_D0 = 0;
    *(UnkStruct_080DFF1C*)&w->unk_F8 = *(UnkStruct_080DFF1C*)&w->unk_08;
}

s32 func_080F05A4(UnkStruct_080E590C* p) {
    UnkStruct_080E590C* w = p;
    UnkStruct_080DFF1C* q = &w->unk_08;

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        func_080E6034(p);
        return 0;
    }

    if (w->unk_CC != 0) {
        ((void (*)(UnkStruct_080E590C*))w->unk_CC)(w);

        if (w->unk_CC != 0) {
            func_08012324(w->unk_48, q->unk_00, q->x, q->y);
            return 1;
        }
    }
    return 0;
}

void func_080F05FC(UnkStruct_080E590C* p) {
    func_080E64D4(p);
}

void func_080F0608(UnkStruct_080E590C* p) {
    func_080E657C(p);
}

void func_080F0614(UnkStruct_080EFA30* p) {
    if (p->unk_08 < gUnk_02039BA0->unk_00 - 0x1800 || p->unk_08 > gUnk_02039BA0->unk_00 + 0x10800) {
        if (p->unk_F8 != 0) {
            p->unk_CC = 0;
        }
    } else if (p->unk_F8 == 0) {
        p->unk_F8 = 1;
    }
}

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

void func_080F07EC(UnkStruct_080E590C* p) {
    UnkStruct_080E590C* r = p;
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&p->unk_08;
    UnkStruct_080DFF1C tmp;

    func_080E5D6C(p, 0, 3);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);
    tmp = p->unk_08;
    func_080F0660((UnkStruct_080F023C*)p, 0);

    if (GetRandom() % 20 == 0) {
        q->unk_14 = GetAngle(p->unk_08.unk_00, q->unk_04, gUnk_02039BA0->unk_18, gUnk_02039BA0->unk_1C);
    }

    if (q->unk_08 < gUnk_02039BA0->unk_20 - 0x4000) {
        func_080F0708((UnkStruct_080F023C*)p, 0);
        p->unk_D0 = 0;
        q->unk_10 = 0;
        p->unk_CC = func_080F08E4;
    } else if (GetRandom() % 130 == 0) {
        if (GetRandom() % 2) {
            func_080F0708((UnkStruct_080F023C*)p, 0);
        } else {
            func_080F0708((UnkStruct_080F023C*)p, 1);
        }

        r->unk_D0 = 0;
        q->unk_10 = 0;
        r->unk_CC = func_080F08E4;
    }

    if ((u8)func_080E5FB4(r) != 0) {
        r->unk_CC = func_080F0A44;
    } else {
        func_080E5F50(r);
        func_080F0614((UnkStruct_080EFA30*)p);
    }
}

void func_080F08E4(UnkStruct_080E590C* p) {
    UnkStruct_080EF4BC* q = (UnkStruct_080EF4BC*)&p->unk_08;
    UnkStruct_080DFF1C t;
    s32 dx;
    s32 dy;
    s32 v;
    s32 r;
    u32 lim;

    func_080E5D6C(p, 1, 3);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);
    func_080F0660((UnkStruct_080F023C*)p, 1);
    t = p->unk_08;

    if (GetRandom() % 20 != 0) {
        q->unk_14 = GetAngle(p->unk_08.unk_00, q->unk_04, gUnk_02039BA0->unk_18, gUnk_02039BA0->unk_1C);
    }

    dx = p->unk_D4;
    dy = p->unk_D8;

    if (p->unk_04 & 16) {
        lim = 0x140;
        q->unk_10 += 10;

        if (q->unk_10 > 76) {
            q->unk_10 = 76;
        }
    } else {
        lim = 64;
        q->unk_10 += 51;

        if (q->unk_10 > 0x180) {
            q->unk_10 = 0x180;
        }
    }

    v = (dx - q->unk_00) >> 5;

    if (v > q->unk_10) {
        v = q->unk_10;
    } else if (v < -q->unk_10) {
        v = -q->unk_10;
    }

    q->unk_00 += v;
    v = (dy - q->unk_04) >> 5;

    if (v > q->unk_10) {
        v = q->unk_10;
    } else if (v < -q->unk_10) {
        v = -q->unk_10;
    }

    q->unk_04 += v;

    if (p->unk_D0 > lim) {
        p->unk_CC = func_080F07EC;
    } else {
        p->unk_D0++;
    }

    r = func_080DFF1C((UnkStruct_080DFF1C*)q);

    if (r < q->unk_08) {
        *(UnkStruct_080DFF1C*)q = t;
        p->unk_D8 = q->unk_04 + 0x1000;
    } else if (r == 0x100000) {
        *(UnkStruct_080DFF1C*)q = t;
        p->unk_D8 = q->unk_04 - 0x1000;
    } else {
        q->unk_0C = r;
    }

    if ((u8)func_080E5FB4(p) != 0) {
        p->unk_CC = func_080F0A44;
    } else {
        func_080E5F50(p);
    }
}

void func_080F0A44(UnkStruct_080E590C* p) {
    func_080E5D6C(p, 2, 0);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished((AnimState*)p->anim)) {
        p->unk_04 |= 0x40;
        func_080E5EAC(p);
    } else {
        func_080E5DEC(p);
    }
}

void func_080F0A84(UnkStruct_080E590C* p) {
    func_080E5D6C(p, 0, 0);
    p->gfx = AnimGetGfx(p->anim);
    TaskPoolUpdate(p->unk_E4);

    if ((u8)func_080E5FB4(p)) {
        p->unk_CC = func_080F0A44;
    } else {
        func_080E5F50(p);
    }
}

void func_080F0ACC(UnkStruct_080E590C* p, UnkStruct_080E5B90* q) {
    UnkStruct_080EFA30* w = (UnkStruct_080EFA30*)p;

    func_080E6394(p, q);

    if (p->unk_04 & 0x20) {
        p->unk_CC = func_080F0A84;
        func_080E5D6C(p, 0, 0);
        p->gfx = AnimGetGfx(p->anim);
        func_08012614(p->unk_48, 0);
    } else {
        p->unk_CC = func_080F07EC;
        func_080E5D6C(p, 0, 1);
        p->gfx = AnimGetGfx(p->anim);
        func_08012614(p->unk_48, 0);
    }
    w->unk_D0 = 0;
    ((UnkStruct_080EFA30*)p)->unk_F8 = 0;
}

s32 func_080F0B54(UnkStruct_080E590C* p) {
    UnkStruct_080E590C* q = p;
    UnkStruct_080DFF1C* pos = &p->unk_08;

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        func_080E6034(p);
        return 0;
    }

    if ((gUnk_0203C7AC->unk_00 & 4) && p->unk_CC != func_080F0A44) {
        return 1;
    }

    if (p->unk_CC != 0) {
        ((void (*)(UnkStruct_080E590C*))p->unk_CC)(q);

        if (p->unk_CC != 0) {
            func_08012324(&p->unk_48, pos->unk_00, pos->x, pos->y);
            return 1;
        }
    }

    return 0;
}

void func_080F0BD0(UnkStruct_080E590C* p) {
    func_080E64D4(p);
}

void func_080F0BDC(UnkStruct_080E590C* p) {
    func_080E657C(p);
}

void func_080F0BE8(UnkStruct_080E590C* p) {
    UnkStruct_080E590C* q = p;

    func_080E5D6C(p, 0, 0);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished(p->anim)) {
        func_08012614(p->unk_48, 0);
        p->unk_D0 = GetRandom() % 121 + 60;
        p->unk_CC = func_080F0C68;
    } else {
        func_080E5DEC(q);
        if (q->unk_E0 > 0) {
            q->unk_E0--;

            if (q->unk_E0 <= 0) {
                func_08012614(q->unk_48, 0);
            }
        }
    }
}

void func_080F0C68(UnkStruct_080E590C* p) {
    UnkStruct_080E590C* q = p;
    UnkStruct_080EF4BC* r = (UnkStruct_080EF4BC*)&p->unk_08;

    func_080E5D6C(p, 1, 1);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);

    if (GetRandom() % 20 == 0) {
        r->unk_14 = GetAngle(p->unk_08.unk_00, r->unk_04, gUnk_02039BA0->unk_18, gUnk_02039BA0->unk_1C);
    }

    if ((u8)func_080E5FB4(p) != 0) {
        p->unk_CC = func_080F0D40;
    } else {
        func_080E5F50(p);

        if (p->unk_D0 != 0) {
            p->unk_D0--;
        } else {
            func_08012614(q->unk_48, 1);
            q->unk_CC = func_080F0D00;
        }
    }
}

void func_080F0D00(UnkStruct_080E590C* p) {
    p->unk_04 |= 4;
    func_080E5D6C(p, 2, 0);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished((AnimState*)p->anim)) {
        p->unk_CC = 0;
    }
}

void func_080F0D40(UnkStruct_080E590C* p) {
    func_080E5D6C(p, 3, 0);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished((AnimState*)p->anim)) {
        p->unk_04 |= 0x40;
        func_080E5EAC(p);
    } else {
        func_080E5DEC(p);
    }
}

void func_080F0D80(UnkStruct_080E590C* p, UnkStruct_080E5B90* q) {
    func_080E6394(p, q);

    if (p->unk_CC == 0) {
        p->unk_CC = func_080F0BE8;
        func_080E5D6C(p, 0, 0);
        p->gfx = AnimGetGfx(p->anim);
        func_08012614(p->unk_48, 1);
    } else {
        func_08012614(p->unk_48, 0);
    }
    p->unk_D0 = 0;
}

s32 func_080F0DD8(UnkStruct_080E590C* p) {
    UnkStruct_080E590C* q = p;
    UnkStruct_080DFF1C* pos = &p->unk_08;

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        func_080E6034(p);
        return 0;
    }

    if ((gUnk_0203C7AC->unk_00 & 4) && p->unk_CC != func_080F0D40) {
        return 1;
    }

    if (p->unk_CC != 0) {
        ((void (*)(UnkStruct_080E590C*))p->unk_CC)(q);

        if (p->unk_CC != 0) {
            func_08012324(&p->unk_48, pos->unk_00, pos->x, pos->y);
            return 1;
        }
    }

    return 0;
}

void func_080F0E54(UnkStruct_080E590C* p) {
    func_080E64D4(p);
}

void func_080F0E60(UnkStruct_080E590C* p) {
    func_080E657C(p);
}

void func_080F0E6C(UnkStruct_080E590C* p) {
    UnkStruct_080E590C* q = p;

    func_080E5D6C(p, 0, 0);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished(p->anim)) {
        func_08012614(p->unk_48, 0);
        p->unk_D0 = GetRandom() % 121 + 60;
        p->unk_CC = func_080F0EEC;
    } else {
        func_080E5DEC(q);
        if (q->unk_E0 > 0) {
            q->unk_E0--;

            if (q->unk_E0 <= 0) {
                func_08012614(q->unk_48, 0);
            }
        }
    }
}

void func_080F0EEC(UnkStruct_080E590C* p) {
    UnkStruct_080E590C* q = p;
    UnkStruct_080EF4BC* r = (UnkStruct_080EF4BC*)&p->unk_08;

    func_080E5D6C(p, 1, 1);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);

    if (GetRandom() % 20 == 0) {
        r->unk_14 = GetAngle(p->unk_08.unk_00, r->unk_04, gUnk_02039BA0->unk_18, gUnk_02039BA0->unk_1C);
    }

    if ((u8)func_080E5FB4(p) != 0) {
        p->unk_CC = func_080F0FC4;
    } else {
        func_080E5F50(p);

        if (p->unk_D0 != 0) {
            p->unk_D0--;
        } else {
            func_08012614(q->unk_48, 1);
            q->unk_CC = func_080F0F84;
        }
    }
}

void func_080F0F84(UnkStruct_080E590C* p) {
    p->unk_04 |= 4;
    func_080E5D6C(p, 2, 0);
    func_080E5DEC(p);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished((AnimState*)p->anim)) {
        p->unk_CC = 0;
    }
}

void func_080F0FC4(UnkStruct_080E590C* p) {
    func_080E5D6C(p, 3, 0);
    TaskPoolUpdate(p->unk_E4);

    if (AnimIsFinished((AnimState*)p->anim)) {
        p->unk_04 |= 0x40;
        func_080E5EAC(p);
    } else {
        func_080E5DEC(p);
    }
}

void func_080F1004(UnkStruct_080E590C* p, UnkStruct_080E5B90* q) {
    func_080E6394(p, q);

    if (p->unk_CC == 0) {
        p->unk_CC = func_080F0E6C;
        func_080E5D6C(p, 0, 0);
        p->gfx = AnimGetGfx(p->anim);
        func_08012614(p->unk_48, 1);
    } else {
        func_08012614(p->unk_48, 0);
    }
    p->unk_D0 = 0;
}

s32 func_080F105C(UnkStruct_080E590C* p) {
    UnkStruct_080E590C* q = p;
    UnkStruct_080DFF1C* pos = &p->unk_08;

    if (gUnk_02039BA0->unk_70 & 0x40000) {
        func_080E6034(p);
        return 0;
    }

    if ((gUnk_0203C7AC->unk_00 & 4) && p->unk_CC != func_080F0FC4) {
        return 1;
    }

    if (p->unk_CC != 0) {
        ((void (*)(UnkStruct_080E590C*))p->unk_CC)(q);

        if (p->unk_CC != 0) {
            func_08012324(&p->unk_48, pos->unk_00, pos->x, pos->y);
            return 1;
        }
    }

    return 0;
}

void func_080F10D8(UnkStruct_080E590C* p) {
    func_080E64D4(p);
}

void func_080F10E4(UnkStruct_080E590C* p) {
    func_080E657C(p);
}

s32 func_080F10F0(u8* p) {
    return ((s8)gGameState.floor << 28) + (p[9] << 20) + (p[10] << 16) + (gUnk_0203C590.unk_06 << 8) + (gUnk_0203C590.unk_05 << 4) + gUnk_0203C590.unk_04;
}

#ifndef VERSION_EU
void func_080F1124(MapDbgWork* w) {
    if ((GetKeysHeld() & 0x300) == 0x300) {
        if (GetKeysPressed() & 4) {
            *w->unk_04 = 1;
            func_0801CB0C();
            ModeRequest(&gModeDebflag, 1);
        }

        if (GetKeysPressed() & 8) {
            w->unk_00 = 1;
            *w->unk_04 = 1;
            w->unk_08 = func_080F117C;
        }
    }
}
#else
INCLUDE_ASM("map/func_080F1124.s");
#endif

void func_080F117C(MapDbgWork* w) {
    UnkStruct_080DEE18* d;
    s32 step;
    s32 i;

    step = 1;

    for (i = w->unk_0C; i > 0; i--) {
        step <<= 4;
    }

    d = func_080DEE18(gUnk_0203C590.unk_06);

    if (GetKeysRepeat() & 0x40) {
        d->unk_04 += step;
    }

    if (GetKeysRepeat() & 0x80) {
        d->unk_04 -= step;
    }

    if (GetKeysPressed() & 0x20) {
        w->unk_0C = w->unk_0C == 7 ? 0 : w->unk_0C + 1;
    }

    if (GetKeysPressed() & 0x10) {
        w->unk_0C = w->unk_0C == 0 ? 7 : w->unk_0C - 1;
    }

    w->unk_2C = func_08066AF8(d->unk_04, w->unk_18);

    if (GetKeysPressed() & 4) {
        if (++gUnk_0203C590.unk_04 > 12) {
            gUnk_0203C590.unk_04 = 0;
        }

        w->unk_42 = func_08066AF8(func_080F10F0((u8*)d), w->unk_2E);
    }

    if (GetKeysPressed() & 0x300) {
        w->unk_08 = func_080F1274;
    } else if (GetKeysPressed() & 0xB) {
        *w->unk_04 = 0;
        w->unk_08 = func_080F1124;
    }
}

void func_080F1274(MapDbgWork* w) {
    UnkStruct_080DEE18* d = func_080DEE18(gUnk_0203C590.unk_06);

    if ((GetKeysRepeat() & 0x40) && w->unk_0D == 0) {
        gUnk_0203C590.unk_04 = gUnk_0203C590.unk_04 < 12 ? gUnk_0203C590.unk_04 + 1 : 0;
    }

    if ((GetKeysRepeat() & 0x80) && w->unk_0D == 0) {
        gUnk_0203C590.unk_04 = gUnk_0203C590.unk_04 != 0 ? gUnk_0203C590.unk_04 - 1 : 12;
    }

    w->unk_42 = func_08066AF8(func_080F10F0((u8*)d), w->unk_2E);

    if (GetKeysPressed() & 0x300) {
        w->unk_08 = func_080F117C;
    }

    if (GetKeysPressed() & 0xB) {
        *w->unk_04 = 0;
        w->unk_08 = func_080F1124;
    }
}

#ifndef VERSION_EU
void func_080F131C(MapDbgWork* w, u8* p) {
    UnkStruct_080DEE18* d;

    w->unk_00 = 0;
    w->unk_04 = p;
    *p = 0;
    w->unk_08 = func_080F1124;
    w->unk_0C = 0;
    w->unk_0D = 0;
    d = func_080DEE18(gUnk_0203C590.unk_06);
    w->unk_10 = func_080668F0();
    w->unk_14 = func_08066904();
    w->unk_2C = func_08066AF8(d->unk_04, w->unk_18);
    w->unk_42 = func_08066AF8(func_080F10F0((u8*)d), w->unk_2E);
    w->unk_46 = func_0806692C(gUnk_09EF6C38, &w->unk_44);
}
#else
INCLUDE_ASM("map/func_080F131C.s");
#endif

s32 func_080F138C(u8* work) {
    (*(void (**)(u8*))&work[8])(work);
    return 1;
}

#ifndef VERSION_EU
void func_080F139C(MapDbgWork* w) {
    if (w->unk_00 != 0) {
        func_08066DC0(240 - w->unk_2C * 8, 0x8E, w->unk_18, w->unk_10, w->unk_14, 0, w->unk_2C);
        func_08066DC0(240 - w->unk_42 * 8, 0x96, w->unk_2E, w->unk_10, w->unk_14, 0, w->unk_42);

        if (*w->unk_04 != 0) {
            if (w->unk_08 == func_080F117C) {
                func_08066DC0(240 - (w->unk_0C + 1) * 8, 0x90, &w->unk_44, w->unk_10, w->unk_14, 0, w->unk_46);
            } else {
                func_08066DC0(240 - (w->unk_0D + 1) * 8, 0x98, &w->unk_44, w->unk_10, w->unk_14, 0, w->unk_46);
            }
        }
    }
}
#else
INCLUDE_ASM("map/func_080F139C.s");
#endif

#ifndef VERSION_EU
void func_080F1450(u8* work) {
    func_08066918(*(void**)&work[16], *(void**)&work[20]);
}
#else
INCLUDE_ASM("map/func_080F1450.s");
#endif

void func_080F1460(MapGmkJumpWork* w) {
    if (func_08012660(&w->unk_040, 1) && (w->unk_06E & 2)) {
        gUnk_0203C7AC->unk_1C = w->unk_0C4;
        gUnk_0203C7AC->unk_18 = w->unk_014;
        w->unk_0C8 = func_080F14C4;
        w->unk_0C0 = 1;
        AnimStart(&w->unk_09C, 1, 1);
    } else {
        AnimUpdate(&w->unk_09C);
    }
}

void func_080F14C4(MapGmkJumpWork* w) {
    if (func_08012660(&w->unk_040, 1)) {
        gUnk_0203C7AC->unk_1C = w->unk_0C4;
        gUnk_0203C7AC->unk_18 = w->unk_014;
    } else if (gUnk_02039BA0->unk_20 != gUnk_02039BA0->unk_24) {
        w->unk_0C8 = func_080F1544;
        w->unk_0C0 = 2;
        AnimStart(&w->unk_09C, 2, 1);
    } else {
        w->unk_0C8 = func_080F1460;
        w->unk_0C0 = 0;
        AnimStart(&w->unk_09C, 0, 1);
    }
}

void func_080F1544(MapGmkJumpWork* w) {
    if (AnimIsFinished(&w->unk_09C)) {
        w->unk_0C8 = func_080F1460;
        w->unk_0C0 = 0;
        AnimStart(&w->unk_09C, 0, 1);
    } else {
        AnimUpdate(&w->unk_09C);
    }
}

void func_080F1584(MapGmkJumpWork* w, UnkStruct_02034F20* arg) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)w;
    AnimState* a;
    s32 v;

    p->unk_00 = arg->unk_0A << 13;
    p->x = arg->unk_0C << 12;
    p->y = 0;
    p->y = w->unk_00C = func_080DFF30(p);
    p->x -= w->unk_00C;

    switch (arg->unk_0E) {
    case 3:
        v = 211;
        break;
    case 5:
        v = 45;
        break;
    case 0:
    default:
        v = 0;
        break;
    }
    ((u8*)p)[0x14] = v;
    w->unk_0C4 = arg->unk_14 - arg->unk_10;
    w->unk_0B8 = LoadObjPalette(&gUnk_099910C4[0x240], 32);
    w->unk_0B4 = LoadObjTiles(&gUnk_09858238[0x10D9], 0x980);
    a = &w->unk_09C;
    AnimInit(a, gUnk_09EF8488, gUnk_09EF8468);
    w->unk_0C0 = 0;
    AnimStart(a, 0, 1);
    w->unk_0C8 = func_080F1460;
    func_080122AC(&w->unk_040, 6, 16, 0);
    func_08012324(&w->unk_040, p->unk_00, p->x, p->y);
}

s32 func_080F1650(MapGmkJumpWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)w)) {
        func_08012614(&w->unk_040, 1);
    } else {
        func_08012614(&w->unk_040, 0);
    }

    if (w->unk_0C8 != 0) {
        w->unk_0C8(w);
    }
    return 1;
}

void func_080F169C(MapGmkJumpWork* w) {
    u16 v;
    s32 k;
    s16 x;
    s16 y;

    x = (w->unk_000 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    k = w->unk_004 >> 8;
    y = k + (w->unk_008 >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, AnimGetGfx(&w->unk_09C), w->unk_0B4, w->unk_0B8, 0, 0x800, v);
}

void func_080F1718(MapGmkJumpWork* w) {
    ReleaseObjTiles(w->unk_0B4);
    ReleaseObjPalette(w->unk_0B8);
    func_08012304(&w->unk_040);
}

s32 func_080F173C(MapGmkEnmWork* w) {
    if (w->unk_070 != 0) {
        w->unk_060 = AnimUpdate(&w->unk_040);
        ApproachValue(&w->unk_000.y, w->unk_06C, w->unk_070);
        w->unk_070--;
    } else {
        gUnk_0203C7AC->unk_00 |= 2;
        gUnk_02039BA0->unk_70 |= 0x80;
        gUnk_0203C7AC->unk_0E = func_080E5E44();
        w->unk_064 = 0;
    }

    return 1;
}

void func_080F1798(MapGmkEnmWork* w, UnkStruct_080DFF1C* arg) {
    UnkStruct_080DFF1C* e = &w->unk_000;
    AnimState* an;
    u8* anim;
    u8* frames;
    u8 f;

    w->unk_000 = *arg;
    w->unk_000.x += 0x800;
    w->unk_000.y -= 0x1000;
    w->unk_01A = 16;

    if (gUnk_0203C590.unk_04 != 2) {
        w->unk_058 = AllocObjTiles(0x220, gUnk_08988980);
        w->unk_05C = LoadObjPalette(gUnk_08F69804, 32);
        an = &w->unk_040;
        anim = gUnk_09EDFC3C;
        frames = gUnk_09EDFB5C;
    } else {
        w->unk_058 = AllocObjTiles(0x440, gUnk_089D8148);
        w->unk_05C = LoadObjPalette(gUnk_08F69924, 32);
        an = &w->unk_040;
        anim = gUnk_09EE00F0;
        frames = gUnk_09EE00D0;
    }

    do {
        AnimInit(an, anim, frames);
        AnimStart(an, 0, 1);
    } while (0);
    w->unk_060 = AnimGetGfx(an);
    w->unk_064 = func_080F173C;
    f = 0;

    if (gUnk_02039BA0->unk_18 >= e->unk_00) {
        f = 1;
    }
    w->unk_068 = f;
    w->unk_070 = 8;
    w->unk_06C = e->y - 0x1000;
}

u8 func_080F1880(u8* work) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (*(void**)&work[0x64] != 0) {
        return (*(u8 (**)(u8*))&work[0x64])(work);
    }
    return 1;
}

void func_080F18AC(u8* work) {
    u16 flags;
    s32 k;
    s32 x;
    s32 y;
    s32 t;

    t = work[0x68];
    flags = 0x800;

    if (t) {
        flags = 0x801;
    }
    x = (*(s32*)&work[0] >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    k = *(s32*)&work[4] >> 8;
    y = k + (*(s32*)&work[8] >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    DrawSprite(x, y, *(void**)&work[0x60], *(void**)&work[0x58], *(void**)&work[0x5C], 0, flags, -0x1004 - k * 4);
}

void func_080F1918(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x58]);
    ReleaseObjPalette(*(u8**)&work[0x5C]);
}

void func_080F1930(u8* work) {
    *(void**)work = AllocObjTiles(func_080E83C4() << 5, 0);
}

s32 func_080F194C(void) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }
    return 1;
}

void func_080F1964(u8* work) {
}

void func_080F1968(u8* work) {
    if (*(void**)work != 0) {
        ReleaseObjTiles(*(void**)work);
    }
}

u8 func_080F1978(MapGmkTutorialWork* w) {
    if (func_080E02E0((UnkStruct_080DFF1C*)w, 0, 8) != 0) {
        if ((gUnk_02039BA0->unk_70 & 0x800000) == 0 && gUnk_02039BA0->unk_20 == gUnk_02039BA0->unk_24) {
            TaskPool* pool = &w->unk_0B0;

            TaskCreate(pool, &gTaskDescMapSpark, w);
            m4aSongNumStart(0xDC);
            gUnk_0203C7AC->unk_00 |= 0x80;
            gUnk_02039BA0->unk_68 = (s32)w;
            gUnk_0203C7AC->unk_14 = (s32)w;
            w->unk_0AC = func_080F1A10;
            gUnk_0203C7AC->unk_0F = 0;
            gUnk_0203C7AC->unk_10 = 0;
            func_080062F4(*(u16*)&w->unk_0A0[6] + 16, 1);
            TaskCreate(pool, &gTaskDescRoomcreate, 0);
        }
    }
    return 1;
}

u8 func_080F1A10(MapGmkTutorialWork* w) {
    void* p = func_08093BF8();

    if (p != 0) {
        func_080DF640(gUnk_0984C868[0], p);
        w->unk_0AC = func_080F1A84;
    }

    if ((gUnk_02039BA0->unk_70 & 0x40000) == 0) {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        func_080062F4(*(u16*)&w->unk_0A0[6] + 16, 0);
        w->unk_0AC = func_080F1978;
    }
    return 1;
}

u8 func_080F1A84(MapGmkTutorialWork* w) {
    if (gUnk_02039BA0->unk_70 & 0x200000) {
        func_080038E4(w->unk_09C, gUnk_098A94A0, gUnk_0994C364);
        w->unk_0A8 = 1;
        w->unk_0AC = func_080F1ACC;
    }
    return 1;
}

u8 func_080F1ACC(MapGmkTutorialWork* w) {
    return 1;
}

void func_080F1AD0(MapGmkTutorialWork* w) {
    w->unk_000 = 0x19000;
    w->unk_004 = 0xAA00;
    w->unk_008 = 0;
    w->unk_00C = func_080DFF30((UnkStruct_080DFF1C*)w);
    w->unk_008 = w->unk_00C;
    w->unk_004 -= w->unk_00C;
    w->unk_014 = 0xAD;
    w->unk_01A = 32;
    w->unk_0A0 = LoadObjPalette(&gUnk_099910C4[0x140], 32);
    w->unk_09C = func_080038C8(0x400);
    func_080038E4(w->unk_09C, gUnk_098A94A0, gUnk_0994BF64);
    func_080122AC(&w->unk_040, 6, 16, 0);
    func_08012324(&w->unk_040, w->unk_000, w->unk_004, w->unk_008);
    w->unk_0A8 = 0;
    w->unk_0AC = func_080F1978;
    TaskPoolInit(&w->unk_0B0, 2);
}

s32 func_080F1B6C(MapGmkTutorialWork* w) {
    if (w->unk_0A8 != 0 && (w->unk_06E & 2) && w->unk_074 == 1) {
        gUnk_0203C7AC->unk_00 |= 0x200;
    }

    if (w->unk_0AC != 0) {
        if (w->unk_0AC(w) == 0) {
            return 0;
        }
    }

    TaskPoolUpdate(&w->unk_0B0);
    return 1;
}

void func_080F1BC8(MapGmkTutorialWork* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_000 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    k = w->unk_004 >> 8;
    y = k + (w->unk_008 >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    v = -0xFE4 - k * 4;
    DrawSprite(x, y, 0, w->unk_09C, w->unk_0A0, 0, 0x800, v);
    TaskPoolDraw(&w->unk_0B0);
}

void func_080F1C38(MapGmkTutorialWork* w) {
    ReleaseObjTiles(w->unk_09C);
    ReleaseObjPalette(w->unk_0A0);
    func_08012304(w->unk_040);
    TaskPoolDestroy(&w->unk_0B0);
}

u8 func_080F1C64(MapGmkSpiderWork* w) {
    AnimState* a = &w->unk_09C;

    if (AnimIsFinished(a)) {
        gUnk_0203C7AC->unk_00 |= 2;
        gUnk_02039BA0->unk_70 |= 0x80;
        gUnk_0203C7AC->unk_0E = GetRandom() % 3 + 125;
        w->unk_0C0 = 0;
    } else {
        w->unk_0BC = AnimUpdate(a);
    }
    return 1;
}

void func_080F1CCC(MapGmkSpiderWork* w, UnkStruct_0203C7B8* arg) {
    u8 v;

    *(UnkStruct_080DFF1C*)w = arg->unk_04;
    w->unk_01A = 24;
    w->unk_0B4 = AllocObjTiles(0x720, gUnk_0899A8BE);
    w->unk_0B8 = LoadObjPalette(&gUnk_08F691E4[0x6A0], 32);
    AnimInit(&w->unk_09C, gUnk_09EDFCF4, gUnk_09EDFCBC);
    AnimStart(&w->unk_09C, 0, 1);
    w->unk_0BC = AnimGetGfx(&w->unk_09C);
    func_08002A10(w->unk_0B4, gUnk_0899A8BE);
    w->unk_0C0 = func_080F1C64;
    v = 0;

    if (gUnk_02039BA0->unk_18 >= w->unk_000) {
        v = 1;
    }
    w->unk_0C4 = v;
}

u8 func_080F1D68(MapGmkSpiderWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (w->unk_0C0 != 0) {
        return w->unk_0C0(w);
    }
    return 1;
}

void func_080F1D98(MapGmkSpiderWork* w) {
    u16 flags;
    u16 v;
    s32 t;
    s32 k;
    s32 x;
    s32 y;

    t = w->unk_0C4;
    flags = 0x800;

    if (t) {
        flags = 0x801;
    }

    x = (w->unk_000 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    k = w->unk_004 >> 8;
    y = k + (w->unk_008 >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->unk_0BC, w->unk_0B4, w->unk_0B8, 0, flags, v);
}

void func_080F1E0C(MapGmkSpiderWork* w) {
    ReleaseObjTiles(w->unk_0B4);
    ReleaseObjPalette(w->unk_0B8);
}

s32 func_080F1E28(MapGmkGpWork* w) {
    UnkStruct_080DFF1C* p = &w->unk_004;

    if (func_080E02E0(p, 8, 8)) {
        m4aSongNumStart(w->unk_0C4);
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, p);

        if (!(w->unk_000->unk_00 & 2)) {
            w->unk_000->unk_00 |= 2;
            func_080E84DC(p);
        }

        gUnk_0203C7AC->unk_00 |= 0x80;
        w->unk_0C6 = 20;
        w->unk_0C8 = func_080F1EA0;
    }
    return 1;
}

s32 func_080F1EA0(MapGmkGpWork* w) {
    if (w->unk_0C6 != 0) {
        w->unk_0C6--;
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        w->unk_0C8 = func_080F1E28;
    }
    return 1;
}

void func_080F1ED4(MapGmkGpWork* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    UnkStruct_080E7D80* d = arg->unk_14;

    w->unk_000 = (UnkStruct_080DFB8C*)arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->unk_0B8 = LoadObjTiles(d->unk_04, d->unk_08);
    w->unk_0BC = LoadObjPalette(d->unk_00, 32);
    AnimInit(&w->unk_0A0, d->unk_10, d->unk_0C);
    AnimStart(&w->unk_0A0, 0, 1);
    w->unk_0C0 = AnimGetGfx(&w->unk_0A0);
    func_080122AC(&w->unk_044, 6, d->unk_1C, d->unk_1E);
    func_08012324(&w->unk_044, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C4 = d->unk_20;
    w->unk_0C6 = 0;
    w->unk_0C8 = func_080F1E28;
}

u8 func_080F1F98(MapGmkGpWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)&w->unk_004) != 0) {
        func_08012614(&w->unk_044, 1);
    } else {
        func_08012614(&w->unk_044, 0);
    }

    if (w->unk_0C8 != 0) {
        return w->unk_0C8(w);
    }
    return 1;
}

void func_080F1FEC(MapGmkGpWork* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    k = w->unk_004.x >> 8;
    y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->unk_0C0, w->unk_0B8, w->unk_0BC, 0, 0x800, v);
}

void func_080F2058(MapGmkGpWork* w) {
    ReleaseObjTiles(w->unk_0B8);
    ReleaseObjPalette(w->unk_0BC);
    func_08012304(w->unk_044);
}

u8 func_080F207C(MapGmkGp1Work* w) {
    UnkStruct_080DFF1C* p = &w->unk_004;

    if (func_080E8374((UnkStruct_080E8374*)p) != 0) {
        func_08012614(&w->unk_044, 1);
    } else {
        func_08012614(&w->unk_044, 0);
    }

    if (!func_080E02E0(p, 8, 8)) {
        w->unk_0C0 = AnimUpdate(&w->unk_0A0);
    } else {
        m4aSongNumStart(w->unk_0C4);
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, p);
        func_080E84DC(&w->unk_004);
        gUnk_0203C7AC->unk_00 |= 0x80;
        w->unk_000->unk_00 |= 1;
        func_08012614(&w->unk_044, 1);
        AnimStart(&w->unk_0A0, 1, 0);
        w->unk_0C8 = func_080F2130;
    }
    return 1;
}

s32 func_080F2130(MapGmkGp1Work* w) {
    AnimState* a = &w->unk_0A0;

    if (!AnimIsFinished(a)) {
        w->unk_0C0 = AnimUpdate(a);
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        w->unk_0C6 = 0;
        w->unk_0C8 = 0;
    }
    return 1;
}

void func_080F2178(MapGmkGp1Work* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    UnkStruct_080E7D80* d = arg->unk_14;
    AnimState* a;

    w->unk_000 = arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->unk_0B8 = AllocObjTiles(d->unk_08, d->unk_04);
    w->unk_0BC = LoadObjPalette(d->unk_00, 32);
    a = &w->unk_0A0;
    AnimInit(a, d->unk_10, d->unk_0C);
    AnimStart(a, 0, 1);
    w->unk_0C0 = AnimGetGfx(a);
    func_08002A10(w->unk_0B8, d->unk_04);
    func_080122AC(&w->unk_044, 6, d->unk_1C, d->unk_1E);
    func_08012324(&w->unk_044, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C4 = d->unk_20;
    w->unk_0C6 = 1;
    w->unk_0C8 = func_080F207C;
}

u8 func_080F2244(MapGmkGpWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (w->unk_0C8 != 0) {
        return w->unk_0C8(w);
    }
    return 1;
}

void func_080F2274(MapGmkGp1Work* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    if (w->unk_0C6 != 0) {
        x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
        k = w->unk_004.x >> 8;
        y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
        v = -0x1004 - k * 4;
        DrawSprite(x, y, w->unk_0C0, w->unk_0B8, w->unk_0BC, 0, 0x800, v);
    }
}

void func_080F22E8(MapGmkGpWork* w) {
    ReleaseObjTiles(w->unk_0B8);
    ReleaseObjPalette(w->unk_0BC);
    func_08012304(w->unk_044);
}

u8 func_080F230C(MapGmkGpWork* w) {
    UnkStruct_080DFF1C* q = &w->unk_004;

    if (func_080E02E0(q, 8, 8)) {
        UnkStruct_080DFB8C* e;

        m4aSongNumStart(w->unk_0C4);
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, q);
        e = w->unk_000;

        if ((e->unk_00 & 2) == 0) {
            e->unk_00 |= 2;
            func_080E84DC(q);
        }

        gUnk_0203C7AC->unk_00 |= 0x80;
        AnimStart(&w->unk_0A0, 1, 0);
        w->unk_0C8 = func_080F238C;
    }
    return 1;
}

u8 func_080F238C(MapGmkGpWork* w) {
    if (AnimIsFinished(&w->unk_0A0) == 0) {
        w->unk_0C0 = AnimUpdate(&w->unk_0A0);
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        AnimStart(&w->unk_0A0, 0, 0);
        w->unk_0C0 = AnimGetGfx(&w->unk_0A0);
        w->unk_0C8 = func_080F230C;
    }

    return 1;
}

void func_080F23E8(MapGmkGpWork* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    UnkStruct_080E7D80* d = arg->unk_14;
    AnimState* a;

    w->unk_000 = arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->unk_0B8 = AllocObjTiles(d->unk_08, d->unk_04);
    w->unk_0BC = LoadObjPalette(d->unk_00, 32);
    a = &w->unk_0A0;
    AnimInit(a, d->unk_10, d->unk_0C);
    AnimStart(a, 0, 1);
    w->unk_0C0 = AnimGetGfx(a);
    func_08002A10(w->unk_0B8, d->unk_04);
    func_080122AC(&w->unk_044, 6, d->unk_1C, d->unk_1E);
    func_08012324(&w->unk_044, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C4 = d->unk_20;
    w->unk_0C8 = func_080F230C;
}

u8 func_080F24B0(MapGmkGpWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)&w->unk_004) != 0) {
        func_08012614(&w->unk_044, 1);
    } else {
        func_08012614(&w->unk_044, 0);
    }

    if (w->unk_0C8 != 0) {
        return w->unk_0C8(w);
    }
    return 1;
}

void func_080F2504(MapGmkGpWork* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    k = w->unk_004.x >> 8;
    y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->unk_0C0, w->unk_0B8, w->unk_0BC, 0, 0x800, v);
}

void func_080F2570(MapGmkGpWork* w) {
    ReleaseObjTiles(w->unk_0B8);
    ReleaseObjPalette(w->unk_0BC);
    func_08012304(w->unk_044);
}

u8 func_080F2594(MapGmkGpWork* w) {
    UnkStruct_080DFF1C* q = &w->unk_004;

    if (func_080E02E0(q, 8, 8)) {
        m4aSongNumStart(w->unk_0C4);
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, q);
        gUnk_0203C7AC->unk_00 |= 0x80;
        AnimStart(&w->unk_0A0, 1, 0);
        w->unk_0C8 = func_080F25FC;
    }
    return 1;
}

s32 func_080F25FC(MapGmkGpWork* w) {
    AnimState* a = &w->unk_0A0;

    if (AnimIsFinished(a)) {
        UnkStruct_080DFB8C* e = w->unk_000;

        if ((e->unk_00 & 2) == 0) {
            e->unk_00 |= 2;
            func_080E84DC(&w->unk_004);
        }
        AnimStart(a, 2, 0);
        w->unk_0C8 = func_080F2654;
    } else {
        w->unk_0C0 = AnimUpdate(a);
    }
    return 1;
}

u8 func_080F2654(MapGmkGpWork* w) {
    if (AnimIsFinished(&w->unk_0A0) == 0) {
        w->unk_0C0 = AnimUpdate(&w->unk_0A0);
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        AnimStart(&w->unk_0A0, 0, 0);
        w->unk_0C0 = AnimGetGfx(&w->unk_0A0);
        w->unk_0C8 = func_080F2594;
    }

    return 1;
}

void func_080F26B0(MapGmkGpWork* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    UnkStruct_080E7D80* d = arg->unk_14;
    AnimState* a;

    w->unk_000 = arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->unk_0B8 = AllocObjTiles(d->unk_08, d->unk_04);
    w->unk_0BC = LoadObjPalette(d->unk_00, 32);
    a = &w->unk_0A0;
    AnimInit(a, d->unk_10, d->unk_0C);
    AnimStart(a, 0, 1);
    w->unk_0C0 = AnimGetGfx(a);
    func_08002A10(w->unk_0B8, d->unk_04);
    func_080122AC(&w->unk_044, 6, d->unk_1C, d->unk_1E);
    func_08012324(&w->unk_044, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C4 = d->unk_20;
    w->unk_0C8 = func_080F2594;
}

u8 func_080F2778(MapGmkGpWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)&w->unk_004) != 0) {
        func_08012614(&w->unk_044, 1);
    } else {
        func_08012614(&w->unk_044, 0);
    }

    if (w->unk_0C8 != 0) {
        return w->unk_0C8(w);
    }
    return 1;
}

void func_080F27CC(MapGmkGpWork* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    k = w->unk_004.x >> 8;
    y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->unk_0C0, w->unk_0B8, w->unk_0BC, 0, 0x800, v);
}

void func_080F2838(MapGmkGpWork* w) {
    ReleaseObjTiles(w->unk_0B8);
    ReleaseObjPalette(w->unk_0BC);
    func_08012304(w->unk_044);
}

u8 func_080F285C(MapGmkGpWork* w) {
    UnkStruct_080DFF1C* q = &w->unk_004;
    AnimState* a = &w->unk_0A0;

    w->unk_0C0 = AnimUpdate(a);

    if ((w->unk_000->unk_00 & 2) == 0 && func_080E02E0(q, 8, 8)) {
        m4aSongNumStart(w->unk_0C4);
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, q);
        func_080E84DC(q);
        w->unk_000->unk_00 |= 2;
        gUnk_0203C7AC->unk_00 |= 0x80;
        AnimStart(a, 1, 1);
        w->unk_0C6 = 20;
        w->unk_0C8 = func_080F28F4;
    }
    return 1;
}

s32 func_080F28F4(MapGmkGpWork* w) {
    w->unk_0C0 = AnimUpdate(&w->unk_0A0);

    if (w->unk_0C6 != 0) {
        w->unk_0C6--;
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        w->unk_0C8 = 0;
    }
    return 1;
}

void func_080F2934(MapGmkGpWork* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    UnkStruct_080E7D80* d = arg->unk_14;

    w->unk_000 = (UnkStruct_080DFB8C*)arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->unk_0B8 = AllocObjTiles(d->unk_08, d->unk_04);
    w->unk_0BC = LoadObjPalette(d->unk_00, 32);
    AnimInit(&w->unk_0A0, d->unk_10, d->unk_0C);

    if (w->unk_000->unk_00 & 2) {
        AnimStart(&w->unk_0A0, 1, 1);
    } else {
        AnimStart(&w->unk_0A0, 0, 1);
    }

    w->unk_0C0 = AnimGetGfx(&w->unk_0A0);
    func_08002A10(w->unk_0B8, d->unk_04);
    func_080122AC(&w->unk_044, 6, d->unk_1C, d->unk_1E);
    func_08012324(&w->unk_044, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C4 = d->unk_20;
    w->unk_0C8 = func_080F285C;
}

u8 func_080F2A10(MapGmkGpWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)&w->unk_004) != 0) {
        func_08012614(&w->unk_044, 1);
    } else {
        func_08012614(&w->unk_044, 0);
    }

    if (w->unk_0C8 != 0) {
        return w->unk_0C8(w);
    }
    return 1;
}

void func_080F2A64(MapGmkGpWork* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    k = w->unk_004.x >> 8;
    y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->unk_0C0, w->unk_0B8, w->unk_0BC, 0, 0x800, v);
}

void func_080F2AD0(MapGmkGpWork* w) {
    ReleaseObjTiles(w->unk_0B8);
    ReleaseObjPalette(w->unk_0BC);
    func_08012304(w->unk_044);
}

s32 func_080F2AF4(MapGmkGpWork* w) {
    UnkStruct_080DFF1C* q = &w->unk_004;

    if (!(w->unk_000->unk_00 & 2) && func_080E02E0(q, 8, 8)) {
        m4aSongNumStart(w->unk_0C4);
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, q);
        func_080E84DC(q);
        w->unk_000->unk_00 |= 2;
        gUnk_0203C7AC->unk_00 |= 0x80;
        AnimStart(&w->unk_0A0, 1, 0);
        w->unk_0C8 = func_080F2B78;
    }
    return 1;
}

s32 func_080F2B78(MapGmkGpWork* w) {
    AnimState* a = &w->unk_0A0;

    if (!AnimIsFinished(a)) {
        w->unk_0C0 = AnimUpdate(a);
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        AnimStart(a, 2, 0);
        w->unk_0C0 = AnimGetGfx(a);
        w->unk_0C8 = 0;
    }
    return 1;
}

void func_080F2BD0(MapGmkGpWork* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    UnkStruct_080E7D80* d = arg->unk_14;

    w->unk_000 = (UnkStruct_080DFB8C*)arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->unk_0B8 = AllocObjTiles(d->unk_08, d->unk_04);
    w->unk_0BC = LoadObjPalette(d->unk_00, 32);
    AnimInit(&w->unk_0A0, d->unk_10, d->unk_0C);

    if (w->unk_000->unk_00 & 2) {
        AnimStart(&w->unk_0A0, 2, 1);
    } else {
        AnimStart(&w->unk_0A0, 0, 1);
    }

    w->unk_0C0 = AnimGetGfx(&w->unk_0A0);
    func_08002A10(w->unk_0B8, d->unk_04);
    func_080122AC(&w->unk_044, 6, d->unk_1C, d->unk_1E);
    func_08012324(&w->unk_044, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C4 = d->unk_20;
    w->unk_0C8 = func_080F2AF4;
}

u8 func_080F2CAC(MapGmkGpWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)&w->unk_004) != 0) {
        func_08012614(&w->unk_044, 1);
    } else {
        func_08012614(&w->unk_044, 0);
    }

    if (w->unk_0C8 != 0) {
        return w->unk_0C8(w);
    }
    return 1;
}

void func_080F2D00(MapGmkGpWork* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    k = w->unk_004.x >> 8;
    y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->unk_0C0, w->unk_0B8, w->unk_0BC, 0, 0x800, v);
}

void func_080F2D6C(MapGmkGpWork* w) {
    ReleaseObjTiles(w->unk_0B8);
    ReleaseObjPalette(w->unk_0BC);
    func_08012304(w->unk_044);
}

u8 func_080F2D90(MapGmkGpWork* w) {
    UnkStruct_080DFF1C* q = &w->unk_004;
    AnimState* a = &w->unk_0A0;

    w->unk_0C0 = AnimUpdate(a);

    if (func_080E02E0(q, 8, 8)) {
        m4aSongNumStart(w->unk_0C4);
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, q);

        if ((w->unk_000->unk_00 & 2) == 0) {
            w->unk_000->unk_00 |= 2;
            func_080E84DC(q);
        }

        gUnk_0203C7AC->unk_00 |= 0x80;

        if (w->unk_000->unk_00 & 4) {
            w->unk_000->unk_00 &= ~4;
            AnimStart(a, 0, 1);
        } else {
            w->unk_000->unk_00 |= 4;
            AnimStart(a, 1, 1);
        }

        w->unk_0C6 = 20;
        w->unk_0C8 = func_080F2E4C;
    }
    return 1;
}

s32 func_080F2E4C(MapGmkGpWork* w) {
    w->unk_0C0 = AnimUpdate(&w->unk_0A0);

    if (w->unk_0C6 != 0) {
        w->unk_0C6--;
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        w->unk_0C8 = func_080F2D90;
    }
    return 1;
}

void func_080F2E90(MapGmkGpWork* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    UnkStruct_080E7D80* d = arg->unk_14;

    w->unk_000 = (UnkStruct_080DFB8C*)arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->unk_0B8 = AllocObjTiles(d->unk_08, d->unk_04);
    w->unk_0BC = LoadObjPalette(d->unk_00, 32);
    AnimInit(&w->unk_0A0, d->unk_10, d->unk_0C);

    if (w->unk_000->unk_00 & 4) {
        AnimStart(&w->unk_0A0, 1, 1);
    } else {
        AnimStart(&w->unk_0A0, 0, 1);
    }

    w->unk_0C0 = AnimGetGfx(&w->unk_0A0);
    func_08002A10(w->unk_0B8, d->unk_04);
    func_080122AC(&w->unk_044, 6, d->unk_1C, d->unk_1E);
    func_08012324(&w->unk_044, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C4 = d->unk_20;
    w->unk_0C8 = func_080F2D90;
}

u8 func_080F2F6C(MapGmkGpWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)&w->unk_004) != 0) {
        func_08012614(&w->unk_044, 1);
    } else {
        func_08012614(&w->unk_044, 0);
    }

    if (w->unk_0C8 != 0) {
        return w->unk_0C8(w);
    }
    return 1;
}

void func_080F2FC0(MapGmkGpWork* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    k = w->unk_004.x >> 8;
    y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->unk_0C0, w->unk_0B8, w->unk_0BC, 0, 0x800, v);
}

void func_080F302C(MapGmkGpWork* w) {
    ReleaseObjTiles(w->unk_0B8);
    ReleaseObjPalette(w->unk_0BC);
    func_08012304(w->unk_044);
}

s32 func_080F3050(MapGmkGp8Work* w) {
    AnimState* a = &w->unk_0A0;

    w->unk_0C0 = AnimUpdate(a);

    if (func_08012660(w->unk_044, 1) != 0) {
        if (w->unk_072 & 2) {
            if (!(w->unk_000->unk_00 & 2)) {
                w->unk_000->unk_00 |= 2;
                func_080E84DC(&w->unk_004);
            }
            AnimStart(a, 1, 0);
            w->unk_0C0 = AnimGetGfx(a);
            w->unk_0C4 = func_080F30C4;
        }
    }
    return 1;
}

s32 func_080F30C4(MapGmkGp8Work* w) {
    w->unk_0C0 = AnimUpdate(&w->unk_0A0);

    if (func_08012660(w->unk_044, 1) == 0) {
        AnimStart(&w->unk_0A0, 2, 0);
        w->unk_0C4 = func_080F3108;
    }
    return 1;
}

s32 func_080F3108(MapGmkGp8Work* w) {
    AnimState* a = &w->unk_0A0;

    if (AnimIsFinished(a)) {
        AnimStart(a, 0, 1);
        w->unk_0C0 = AnimGetGfx(a);
        w->unk_0C4 = func_080F3050;
    } else {
        w->unk_0C0 = AnimUpdate(a);
    }
    return 1;
}

void func_080F3150(MapGmkGp8Work* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    UnkStruct_080E7D80* d = arg->unk_14;

    w->unk_000 = (UnkStruct_080DFB8C*)arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->unk_0B8 = AllocObjTiles(d->unk_08, d->unk_04);
    w->unk_0BC = LoadObjPalette(d->unk_00, 32);
    AnimInit(&w->unk_0A0, d->unk_10, d->unk_0C);
    AnimStart(&w->unk_0A0, 0, 1);
    w->unk_0C0 = AnimGetGfx(&w->unk_0A0);
    func_08002A10(w->unk_0B8, d->unk_04);
    func_080122AC(&w->unk_044, 6, d->unk_1C, d->unk_1E);
    func_08012324(&w->unk_044, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C4 = func_080F3050;
}

u8 func_080F3210(MapGmkGp8Work* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)&w->unk_004)) {
        func_08012614(w->unk_044, 1);
    } else {
        func_08012614(w->unk_044, 0);
    }

    if (w->unk_0C4 != 0) {
        return w->unk_0C4(w);
    }
    return 1;
}

void func_080F3264(MapGmkGpWork* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    k = w->unk_004.x >> 8;
    y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->unk_0C0, w->unk_0B8, w->unk_0BC, 0, 0x800, v);
}

void func_080F32D0(MapGmkGpWork* w) {
    ReleaseObjTiles(w->unk_0B8);
    ReleaseObjPalette(w->unk_0BC);
    func_08012304(w->unk_044);
}

s32 func_080F32F4(MapGmkGp8Work* w) {
    UnkStruct_080DFF1C* q = &w->unk_004;
    AnimState* a;

    if (func_080E02E0(q, 8, 8)) {
        m4aSongNumStart(*(u16*)&w->unk_0C8);
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, q);

        if (!(w->unk_000->unk_00 & 2)) {
            w->unk_000->unk_00 |= 2;
            func_080E84DC(q);
        }

        gUnk_0203C7AC->unk_00 |= 0x80;
        a = &w->unk_0A0;
        AnimStart(a, 1, 0);
        w->unk_0C4 = AnimGetGfx(a);
        w->unk_0CA = 1;
        w->unk_0CC = func_080F3384;
    }
    return 1;
}

s32 func_080F3384(MapGmkGp8Work* w) {
    AnimState* a = &w->unk_0A0;

    if (!AnimIsFinished(a)) {
        w->unk_0C4 = AnimUpdate(a);
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        w->unk_0CA = 0;
        w->unk_0CC = func_080F32F4;
    }
    return 1;
}

void func_080F33D0(MapGmkGp08Work* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    UnkStruct_080E7D80* d = arg->unk_14;

    w->unk_000 = (UnkStruct_080DFB8C*)arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->unk_0B8 = LoadObjTiles(d->unk_04, d->unk_08);
    w->unk_0BC = LoadObjPalette(d->unk_00, 32);
    AnimInit(&w->unk_0A0, d->unk_10, d->unk_0C);
    AnimStart(&w->unk_0A0, 0, 1);
    w->unk_0C0 = AnimGetGfx(&w->unk_0A0);
    func_080122AC(&w->unk_044, 6, d->unk_1C, d->unk_1E);
    func_08012324(&w->unk_044, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C8 = d->unk_20;
    w->unk_0CA = 0;
    w->unk_0CC = func_080F32F4;
}

u8 func_080F3494(MapGmkGp8Work* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)&w->unk_004)) {
        func_08012614(w->unk_044, 1);
    } else {
        func_08012614(w->unk_044, 0);
    }

    if (w->unk_0CC != 0) {
        return w->unk_0CC(w);
    }
    return 1;
}

void func_080F34E8(MapGmkGp8Work* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    k = w->unk_004.x >> 8;
    y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->unk_0C0, w->unk_0B8, w->unk_0BC, 0, 0x800, v);

    if (w->unk_0CA != 0) {
        DrawSprite(x, y, w->unk_0C4, w->unk_0B8, w->unk_0BC, 0, 0x800, v - 1);
    }
}

void func_080F359C(MapGmkGp8Work* w) {
    ReleaseObjTiles(w->unk_0B8);
    ReleaseObjPalette(w->unk_0BC);
    func_08012304(w->unk_044);
}

s32 func_080F35C0(MapGmkGp8Work* w) {
    AnimState* a = &w->unk_0A0;

    w->unk_0C4 = AnimUpdate(a);

    if (func_08012660(w->unk_044, 1) != 0) {
        if (w->unk_072 & 2) {
            if (!(w->unk_000->unk_00 & 2)) {
                w->unk_000->unk_00 |= 2;
                func_080E84DC(&w->unk_004);
            }
            AnimStart(a, 1, 0);
            w->unk_0C4 = AnimGetGfx(a);
            w->unk_0C8 = 1;
            w->unk_0CC = func_080F3638;
        }
    }
    return 1;
}

s32 func_080F3638(MapGmkGp8Work* w) {
    if (AnimIsFinished(&w->unk_0A0)) {
        w->unk_0C8 = 0;
        w->unk_0CC = func_080F3674;
    } else {
        w->unk_0C4 = AnimUpdate(&w->unk_0A0);
    }

    return 1;
}

s32 func_080F3674(MapGmkGp8Work* w) {
    if (func_08012660(w->unk_044, 1) == 0) {
        w->unk_0CC = func_080F35C0;
    }
    return 1;
}

void func_080F369C(MapGmkGp8Work* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    UnkStruct_080E7D80* d = arg->unk_14;

    w->unk_000 = (UnkStruct_080DFB8C*)arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->unk_0B8 = LoadObjTiles(d->unk_04, d->unk_08);
    w->unk_0BC = LoadObjPalette(d->unk_00, 32);
    AnimInit(&w->unk_0A0, d->unk_10, d->unk_0C);
    AnimStart(&w->unk_0A0, 0, 1);
    w->unk_0C0 = AnimGetGfx(&w->unk_0A0);
    func_080122AC(&w->unk_044, 6, d->unk_1C, d->unk_1E);
    func_08012324(&w->unk_044, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C8 = 0;
    w->unk_0CC = func_080F35C0;
}

u8 func_080F375C(MapGmkGp8Work* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)&w->unk_004)) {
        func_08012614(w->unk_044, 1);
    } else {
        func_08012614(w->unk_044, 0);
    }

    if (w->unk_0CC != 0) {
        return w->unk_0CC(w);
    }
    return 1;
}

void func_080F37B0(MapGmkGp8Work* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    k = w->unk_004.x >> 8;
    y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->unk_0C0, w->unk_0B8, w->unk_0BC, 0, 0x800, v);

    if (w->unk_0C8 != 0) {
        DrawSprite(x, y, w->unk_0C4, w->unk_0B8, w->unk_0BC, 0, 0x800, v - 1);
    }
}

void func_080F3864(MapGmkGp8Work* w) {
    ReleaseObjTiles(w->unk_0B8);
    ReleaseObjPalette(w->unk_0BC);
    func_08012304(w->unk_044);
}

void func_080F3888(MapGmk00Work* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    UnkStruct_080E7D80* d = arg->unk_14;
    AnimState* a;

    w->unk_000 = arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->unk_0B8 = LoadObjTiles(d->unk_04, d->unk_08);
    w->unk_0BC = LoadObjPalette(d->unk_00, 32);
    a = &w->unk_0A0;
    AnimInit(a, d->unk_10, d->unk_0C);
    AnimStart(a, 0, 1);
    w->unk_0C0 = AnimGetGfx(a);
    func_080122AC(&w->unk_044, 6, d->unk_1C, d->unk_1E);
    func_08012324(&w->unk_044, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);

    if (func_080E8374((UnkStruct_080E8374*)e) != 0) {
        func_08012614(&w->unk_044, 1);
    }
    w->unk_0C4 = d->unk_1C;
    w->unk_0C9 = 0;
    w->unk_0C8 = 1;
    w->unk_0C6 = 0;
}

u8 func_080F3958(MapGmk00Work* w) {
    UnkStruct_080DFF1C* q = &w->unk_004;
    u16 t;

    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (func_080E8374((UnkStruct_080E8374*)q) != 0) {
        func_08012614(&w->unk_044, 1);
    } else {
        func_08012614(&w->unk_044, 0);
    }

    if (!(w->unk_000->unk_00 & 2)) {
        t = w->unk_072 & 2;

        if (t != 0) {
            if (w->unk_0C9 != 1) {
                w->unk_0C9 = 1;
                w->unk_000->unk_00 |= 2;
                func_080E84DC(q);
            }
        } else {
            w->unk_0C9 = 0;
        }
    }
    return 1;
}

void func_080F39DC(MapGmk00Work* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    if (w->unk_0C8 != 0) {
        x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
        k = w->unk_004.x >> 8;
        y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
        v = -0x1004 - k * 4;
        DrawSprite(x, y, w->unk_0C0, w->unk_0B8, w->unk_0BC, 0, 0x800, v);
    }
}

void func_080F3A50(MapGmkGpWork* w) {
    ReleaseObjTiles(w->unk_0B8);
    ReleaseObjPalette(w->unk_0BC);
    func_08012304(w->unk_044);
}

u8 func_080F3A74(MapGmk01Work* w) {
    if (func_080E02E0(&w->unk_004, 8, 8)) {
        AnimState* a;

        gUnk_0203C7AC->unk_00 |= 0x80;
        m4aSongNumStart(0xD0);
        a = &w->unk_0A0;
        AnimStart(a, 1, 1);
        w->unk_0C0 = AnimGetGfx(a);
        func_08002A10(w->unk_0B8, &gUnk_09858238[0x74]);
        w->unk_0C8 = func_080F3ADC;
    }
    return 1;
}

u8 func_080F3ADC(MapGmk01Work* w) {
    UnkStruct_080DFF1C* q = &w->unk_004;

    if (w->unk_000->unk_00 & 8) {
        gUnk_0203C7AC->unk_00 |= 4;
        w->unk_000->unk_00 |= 2;
        TaskCreate(gUnk_02039BA0->unk_78, gTaskDescMapGmkEnm, q);
        w->unk_0C8 = 0;
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x20;
        func_080E9078(gUnk_02039BA0->unk_18, gUnk_02039BA0->unk_1C, gUnk_02039BA0->unk_20);
        func_080DEE18(gUnk_0203C590.unk_06)->unk_00 |= 0x10;
        w->unk_000->unk_00 |= 2;
        w->unk_0C4 = 20;
        w->unk_0C8 = func_080F3B84;
    }

    return 1;
}

s32 func_080F3B84(MapGmk01Work* w) {
    if (w->unk_0C4 != 0) {
        if (func_080A42C8() == 0) {
            w->unk_0C4--;
        }
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        w->unk_0C8 = 0;
    }
    return 1;
}

void func_080F3BC4(MapGmk01Work* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    UnkStruct_080E7D80* d = arg->unk_14;
    AnimState* a;

    w->unk_000 = arg;
    e->unk_00 = arg->unk_04;
    e->unk_1A = d->unk_1E;
    w->unk_0B8 = AllocObjTiles(0x320, &gUnk_09858238[0x74]);
    w->unk_0BC = LoadObjPalette(d->unk_00, 32);
    a = &w->unk_0A0;
    AnimInit(a, d->unk_10, d->unk_0C);

    if (w->unk_000->unk_00 & 2) {
        AnimStart(a, 1, 1);
        w->unk_0C0 = AnimGetGfx(a);
        w->unk_0C8 = 0;
    } else {
        gUnk_0203C7AC->unk_00 |= 0x20;
        AnimStart(a, 0, 1);
        w->unk_0C0 = AnimGetGfx(a);
        w->unk_0C8 = func_080F3A74;
    }
    func_08002A10(w->unk_0B8, &gUnk_09858238[0x74]);
    func_080122AC(&w->unk_044, 6, d->unk_1C, d->unk_1E);
    func_08012324(&w->unk_044, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
}

u8 func_080F3C98(MapGmk01Work* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (w->unk_0C8 != 0) {
        return w->unk_0C8(w);
    }
    return 1;
}

void func_080F3CC8(MapGmkGpWork* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    k = w->unk_004.x >> 8;
    y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->unk_0C0, w->unk_0B8, w->unk_0BC, 0, 0x800, v);
}

void func_080F3D34(MapGmkGpWork* w) {
    ReleaseObjTiles(w->unk_0B8);
    ReleaseObjPalette(w->unk_0BC);
    func_08012304(w->unk_044);
}

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

u8 func_080F3E24(MapGmkBarrelWork* w) {
    UnkStruct_080DFF1C* p = &w->unk_004;
    u16 r;

    if (func_080E02E0(p, 8, 8) != 0) {
        r = GetRandom() % 10000;

        if (r <= 1499) {
            m4aSongNumStart(0x90);
            TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, p);
            gUnk_0203C7AC->unk_00 |= 0x80;
            gUnk_0203C7AC->unk_00 |= 4;
            w->unk_000->unk_00 |= 1;
            TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapGmkSpider, w->unk_000);
            return 0;
        }

        m4aSongNumStart(0x90);
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, p);

        if (r <= 5999) {
            if ((u8)func_080E8FB8(0, p->unk_00, p->x, p->y) != 1) {
                func_080F3D58(p);
            }
        } else if (r <= 9999) {
            func_080F3D58(p);
        }

        gUnk_0203C7AC->unk_00 |= 0x80;
        w->unk_000->unk_00 |= 1;
        func_08012614(&w->unk_044, 1);
        AnimStart(&w->unk_0A0, 1, 0);
        w->unk_0C8 = func_080F3F6C;
        return 1;
    }

    if ((u8)func_080E8374((UnkStruct_080E8374*)p) != 0) {
        func_08012614(&w->unk_044, 1);
    } else {
        func_08012614(&w->unk_044, 0);
    }
    return 1;
}

s32 func_080F3F6C(MapGmkBarrelWork* w) {
    AnimState* a = &w->unk_0A0;

    if (!AnimIsFinished(a)) {
        w->unk_0C0 = AnimUpdate(a);
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        w->unk_0C4 = 0;
        w->unk_0C8 = 0;
    }
    return 1;
}

void func_080F3FB4(MapGmkBarrelWork* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    UnkStruct_080E7D80* d = arg->unk_14;
    AnimState* a;

    w->unk_000 = arg;
    e->unk_00 = arg->unk_04;
    w->unk_004.unk_00 += d->unk_16 << 8;
    e->unk_00.x += d->unk_18 << 8;
    e->unk_00.y += d->unk_1A << 8;
    e->unk_1A = d->unk_1E;
    w->unk_0B8 = AllocObjTiles(d->unk_08, d->unk_04);
    w->unk_0BC = LoadObjPalette(d->unk_00, 32);
    a = &w->unk_0A0;
    AnimInit(a, d->unk_10, d->unk_0C);
    AnimStart(a, 0, 1);
    w->unk_0C0 = AnimGetGfx(a);
    func_08002A10(w->unk_0B8, d->unk_04);
    func_080122AC(&w->unk_044, 6, d->unk_1C, d->unk_1E);
    func_08012324(&w->unk_044, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);
    w->unk_0C4 = 1;
    w->unk_0C8 = func_080F3E24;
}

u8 func_080F4078(MapGmkBarrelWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (w->unk_0C8 != 0) {
        return w->unk_0C8(w);
    }
    return 1;
}

void func_080F40A8(MapGmkBarrelWork* w) {
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    if (w->unk_0C4 != 0) {
        x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
        k = w->unk_004.x >> 8;
        y = k + (w->unk_004.y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
        v = -0x1004 - k * 4;
        DrawSprite(x, y, w->unk_0C0, w->unk_0B8, w->unk_0BC, 0, 0x800, v);
    }
}

void func_080F411C(MapGmkGpWork* w) {
    ReleaseObjTiles(w->unk_0B8);
    ReleaseObjPalette(w->unk_0BC);
    func_08012304(w->unk_044);
}

void func_080F4140(MapGmk04Work* w) {
    if ((gUnk_0203C7AC->unk_00 & 0x4000) == 0 && (u8)func_080E03C0((s32)&w->unk_004) != 0 && (GetKeysPressed() & 1)) {
        m4aSongNumStart(0x66);
        gUnk_02039BA0->unk_70 |= 0x1000;
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSave, 0);
        w->unk_0C4 = 0;
    }
}

void func_080F41A4(MapGmk04Work* w) {
    u32 state = gUnk_0203C7AC->unk_00;

    if (state & 0x4000) {
        gUnk_02039BA0->unk_70 |= 0x1000;
        func_080A411C(&w->unk_0C8, 0, 0x69);
        w->unk_0C4 = func_080F4258;
    } else if (gUnk_02039BA0->unk_68 == (s32)&w->unk_004) {
        gUnk_02039BA0->unk_70 |= 0x1000;
        gUnk_0203C7AC->unk_00 = state | 0x4000;
        func_080A411C(&w->unk_0C8, 0, 0x67);
        w->unk_0C4 = func_080F4224;
    }
}

void func_080F4224(MapGmk04Work* w) {
    if (func_080A42C8() == 0) {
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSave, 0);
        w->unk_0C4 = 0;
    }
}

void func_080F4258(MapGmk04Work* w) {
    if (func_080A42C8() == 0) {
        gUnk_0203C7AC->unk_00 &= ~0x4000;
        gUnk_02039BA0->unk_70 &= ~0x1000;
        gGameState.unk_17A |= 0x10;
        w->unk_0C4 = func_080F4140;
    }
}

void func_080F42B4(MapGmk04Work* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    UnkStruct_080E7D80* d = arg->unk_14;

    w->unk_000 = arg;
    e->unk_00 = arg->unk_04;
    e->unk_1A = d->unk_1E;
    e->unk_30 = 3;

    if (gGameState.unk_17A & 0x10) {
        w->unk_0C4 = func_080F4140;
    } else {
        w->unk_0C4 = func_080F41A4;
    }

    w->unk_0A0 = LoadObjPalette(d->unk_00, 32);
    w->unk_0A4 = AllocObjTiles(d->unk_08, d->unk_04);
    AnimInit(&w->unk_0A8, d->unk_10, d->unk_0C);
    AnimStart(&w->unk_0A8, 0, 1);
    w->unk_0C0 = AnimGetGfx(&w->unk_0A8);
    func_080122AC(&w->unk_044, 4, 24, 24);
    func_08012324(&w->unk_044, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
    TaskPoolInit(&w->unk_0C8, 1);
    func_080121D4(e);
}

s32 func_080F4370(MapGmk04Work* w) {
    TaskPoolUpdate(&w->unk_0C8);

    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    w->unk_0C0 = AnimUpdate(&w->unk_0A8);

    if (w->unk_0C4 != 0) {
        w->unk_0C4(w);

        if (w->unk_0C4 != 0) {
            return 1;
        }
    }
    return 0;
}

void func_080F43B4(MapGmk04Work* w) {
    UnkStruct_080DFF1C* p = &w->unk_004;
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    TaskPoolDraw(&w->unk_0C8);
    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    k = p->x >> 8;
    y = k + (p->y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->unk_0C0, w->unk_0A4, w->unk_0A0, 0, 0x800, v);
}

void func_080F4428(MapGmk04Work* w) {
    ReleaseObjTiles(w->unk_0A4);
    ReleaseObjPalette(w->unk_0A0);
    func_08012304(&w->unk_044);
    TaskPoolDestroy(&w->unk_0C8);
    func_080121FC(&w->unk_004);
}

void func_080F445C(MapGmk05Work* w) {
    if (w->unk_0C8 != 0 && (GetKeysPressed() & 1)) {
        gUnk_02039BA0->unk_70 |= 0x1000;
        func_0801CB0C();
        func_08006184(0, 16);
        m4aSongNumStart(0xCF);
        w->unk_0C4 = func_080F44AC;
    }
}

void func_080F44AC(MapGmk04Work* w) {
    UnkStruct_080DEE18* e;

    if ((u8)func_08006314() != 0) {
        return;
    }
    e = func_080DEE18(gUnk_0203C590.unk_06);

    if (e->unk_00 & 0x20) {
        ModeRequest(&gModeMsTop, 0);
    } else {
        e->unk_00 |= 0x20;
        ModeRequest(&gModeMsTop, 1);
    }
    w->unk_0C4 = 0;
}

void func_080F4500(MapGmk05Work* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    UnkStruct_080E7D80* d = arg->unk_14;
    AnimState* a;

    e->unk_00 = arg->unk_04;
    e->unk_1A = d->unk_1E;
    e->unk_30 = 2;
    w->unk_0C4 = func_080F445C;
    w->unk_0A0 = LoadObjPalette(d->unk_00, 32);
    w->unk_0A4 = AllocObjTiles(d->unk_08, d->unk_04);
    a = &w->unk_0A8;
    AnimInit(a, d->unk_10, d->unk_0C);
    AnimStart(a, 0, 1);
    w->unk_0C0 = AnimGetGfx(a);
    func_080122AC(&w->unk_044, 4, 16, 24);
    func_08012324(&w->unk_044, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);
    func_080121D4(e);
    TaskPoolInit(&w->unk_0CC, 1);
    TaskCreate(&w->unk_0CC, &gTaskDescFldShadow, e);
    w->unk_0C8 = 0;
    TaskPoolInit(&w->unk_0E0, 1);
    TaskCreate(&w->unk_0E0, &gTaskDescMapTalk, e);
}

s32 func_080F45D4(MapGmk05Work* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    TaskPoolUpdate(&w->unk_0CC);
    TaskPoolUpdate(&w->unk_0E0);
    w->unk_0C0 = AnimUpdate(&w->unk_0A8);
    w->unk_0C8 = func_080E03C0((s32)&w->unk_004);

    if (w->unk_0C4 != 0) {
        w->unk_0C4(w);

        if (w->unk_0C4 != 0) {
            return 1;
        }
    }
    return 0;
}

void func_080F4630(MapGmk05Work* w) {
    UnkStruct_080DFF1C* p = &w->unk_004;
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    k = p->x >> 8;
    v = -0x1004 - k * 4;
    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    y = k + (p->y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    DrawSprite(x, y, w->unk_0C0, w->unk_0A4, w->unk_0A0, 0, 0x800, v);
    *(s32*)((u8*)p + 0x3C) = p->z;
    *(u16*)((u8*)p + 0x3A) = v + 1;
    TaskPoolDraw(&w->unk_0CC);

    if (w->unk_0C8 != 0) {
        TaskPoolDraw(&w->unk_0E0);
    }
}

void func_080F46C0(MapGmk05Work* w) {
    ReleaseObjTiles(w->unk_0A4);
    ReleaseObjPalette(w->unk_0A0);
    func_08012304(w->unk_044);
    func_080121FC(&w->unk_004);
    TaskPoolDestroy(&w->unk_0CC);
    TaskPoolDestroy(&w->unk_0E0);
}

void func_080F46FC(MapGmk06Work* w) {
    if (gUnk_02039BA0->unk_68 == (s32)&w->unk_004 && (gGameState.unk_17A & 0x100) == 0) {
        gUnk_02039BA0->unk_70 |= 0x1000;
        gUnk_0203C7AC->unk_00 |= 0x4000;
        func_080A411C(&w->unk_0C8, 0, 0x84);
        gUnk_02039BA0->unk_6C = 30;
        w->unk_0C4 = func_080F47DC;
    } else if ((u8)func_080E03C0((s32)&w->unk_004) != 0 && (GetKeysPressed() & 1)) {
        m4aSongNumStart(0x66);
        gUnk_02039BA0->unk_70 |= 0x1000;
        func_0801CB0C();
        func_08006184(0, 16);
        w->unk_0C4 = func_080F47B4;
    }
}

void func_080F47B4(MapGmk06Work* w) {
    if (func_08006314() == 0) {
        ModeRequest(&gModeWorldwarp, 0);
        w->unk_0C4 = 0;
    }
}

void func_080F47DC(MapGmk06Work* w) {
    if (func_080A42C8() == 0) {
        gUnk_02039BA0->unk_70 &= ~0x1000;
        gUnk_0203C7AC->unk_00 &= ~0x4000;
        gGameState.unk_17A |= 0x100;
        w->unk_0C4 = func_080F46FC;
    } else {
        gUnk_02039BA0->unk_6C = 30;
    }
}

void func_080F484C(MapGmk06Work* w, UnkStruct_0203C7B8* arg) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_004;
    UnkStruct_080E7D80* d = arg->unk_14;

    e->unk_00 = arg->unk_04;
    e->unk_1A = d->unk_1E;
    e->unk_30 = 3;
    w->unk_0C4 = func_080F46FC;
    w->unk_0B8 = LoadObjPalette(d->unk_00, 32);
    w->unk_0BC = AllocObjTiles(d->unk_08, d->unk_04);
    AnimInit(&w->unk_0A0, d->unk_10, d->unk_0C);
    AnimStart(&w->unk_0A0, 0, 1);
    w->unk_0C0 = AnimGetGfx(&w->unk_0A0);
    func_080122AC(&w->unk_044, 4, 24, 24);
    func_08012324(&w->unk_044, w->unk_004.unk_00, e->unk_00.x, e->unk_00.y);
    TaskPoolInit(&w->unk_0C8, 1);
    func_080121D4(e);
}

s32 func_080F48E4(MapGmk06Work* w) {
    TaskPoolUpdate(&w->unk_0C8);

    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    w->unk_0C0 = AnimUpdate(&w->unk_0A0);

    if (w->unk_0C4 != 0) {
        w->unk_0C4(w);

        if (w->unk_0C4 != 0) {
            return 1;
        }
    }
    return 0;
}

void func_080F4928(MapGmk06Work* w) {
    UnkStruct_080DFF1C* p = &w->unk_004;
    u16 v;
    s32 k;
    s32 x;
    s32 y;

    TaskPoolDraw(&w->unk_0C8);
    x = (w->unk_004.unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    k = p->x >> 8;
    y = k + (p->y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    v = -0x1004 - k * 4;
    DrawSprite(x, y, w->unk_0C0, w->unk_0BC, w->unk_0B8, 0, 0x800, v);
}

void func_080F499C(MapGmk06Work* w) {
    ReleaseObjTiles(w->unk_0BC);
    ReleaseObjPalette(w->unk_0B8);
    func_08012304(&w->unk_044);
    TaskPoolDestroy(&w->unk_0C8);
    func_080121FC(&w->unk_004);
}

void func_080F49D0(MapPrizeWork* w) {
    w->unk_84 += 0x38;
    w->unk_08 += w->unk_84;
    w->unk_00 += gSineTable[w->unk_8C] * w->unk_88 >> 8;
    w->unk_04 += -gSineTable[w->unk_8C + 64] * w->unk_88 >> 8;

    if (func_080DFBDC((UnkStruct_080DFF1C*)w) != 0) {
        w->unk_8C = w->unk_8C + (100 + GetRandom() % 57);
    } else {
        w->unk_0C = func_080DFF1C((UnkStruct_080DFF1C*)w);
    }

    if (w->unk_08 > w->unk_0C) {
        w->unk_08 = w->unk_0C;
        w->unk_84 = -(GetRandom() % 0x181 + 0x180);
    }

    if (w->unk_10[0x2C] != 0) {
        u16 t;

        switch (w->unk_80) {
        case 2:
        case 3:
            m4aSongNumStart(107);
            gGameState.unk_174 += w->unk_94;

            if (gGameState.unk_174 > 99999) {
                gGameState.unk_174 = 99999;
            }
            break;
        case 0:
        case 1:
        default:
            m4aSongNumStart(107);
            gGameState.unk_32 += w->unk_94;
            t = gGameState.unk_F8;

            if ((s16)gGameState.unk_32 > (s16)t) {
                gGameState.unk_32 = t;
            }
            break;
        }

        w->unk_7C = func_080F4BA0;
        w->unk_82 = 0;
        w->unk_8C = GetAngle(gUnk_02039BA0->unk_18, gUnk_02039BA0->unk_1C, w->unk_00, w->unk_04);
        w->unk_97 = 1;
        w->unk_96 = 1;
        w->unk_8D = GetRandom() % 6 + 5;
        func_08012614(&w->unk_10, 1);
    } else {
        func_08012324(&w->unk_10, w->unk_00, w->unk_04, w->unk_08);

        if (w->unk_82 == 20) {
            func_08012614(&w->unk_10, 0);
        }

        if (w->unk_82 > 420) {
                w->unk_96 = w->unk_96 == 0 ? 1 : 0;
        }

        if (w->unk_82++ > 480) {
            w->unk_7C = 0;
        }
    }
}

void func_080F4BA0(MapPrizeWork* w) {
    s32 x;
    s32 y;
    s32 z;
    s32 s;
    UnkStruct_02039BA0* g = gUnk_02039BA0;

    s = gSineTable[w->unk_8C] * 32;
    x = g->unk_18 + (s * w->unk_90 >> 8);
    s = -gSineTable[w->unk_8C + 64] * 22;
    y = g->unk_1C + (s * w->unk_90 >> 8);
    z = g->unk_20 - (w->unk_82 / 2 << 8);
    w->unk_8C += w->unk_8D;
    w->unk_00 += (x - w->unk_00) >> 2;
    w->unk_04 += (y - w->unk_04) >> 2;
    w->unk_08 += (z - w->unk_08) >> 2;
    w->unk_0C = func_080DFE7C(w->unk_00, w->unk_04, w->unk_08);
    w->unk_90 -= 2;

    if (w->unk_82 > 60) {
        w->unk_7C = 0;
    } else {
        w->unk_82++;
    }
}

void func_080F4C5C(MapPrizeWork* w, UnkStruct_080E8F50* arg) {
    w->unk_00 = arg->unk_04;
    w->unk_04 = arg->unk_08;
    w->unk_08 = arg->unk_0C;
    w->unk_0C = 0;
    func_080DFF4C((UnkStruct_080DFF1C*)w);
    w->unk_84 = -(GetRandom() % 0x301 + 0x200);
    w->unk_88 = GetRandom() % 155 + 153;
    w->unk_8C = GetRandom();
    w->unk_6C = LoadObjTiles(gUnk_098A5CF4, 0x160);
    w->unk_70 = LoadObjPalette(gUnk_08F69BE4, 32);
    w->unk_80 = arg->unk_14;

    switch (w->unk_80) {
    case 3:
        w->unk_74 = gUnk_098A5CAE;
        w->unk_94 = 10;
        break;
    case 2:
        w->unk_74 = gUnk_098A5CA4;
        w->unk_94 = 4;
        break;
    case 1:
        w->unk_74 = gUnk_098A5C9A;
        w->unk_94 = gGameState.unk_F8 / 20;
        break;
    case 0:
    default:
        w->unk_74 = gUnk_098A5C90;
        w->unk_94 = gGameState.unk_F8 * 3 / 100;
        break;
    }

    w->unk_78 = gUnk_098A5CB8;
    w->unk_97 = 0;
    w->unk_96 = 1;
    w->unk_82 = 0;
    w->unk_7C = func_080F49D0;
    w->unk_90 = 0x100;
    func_080122AC(&w->unk_10, 5, 16, 50);
    func_08012324(&w->unk_10, w->unk_00, w->unk_04, w->unk_08);
    func_08012614(&w->unk_10, 1);
}

s32 func_080F4DB0(MapPrizeWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (w->unk_7C == 0) {
        return 0;
    }
    w->unk_7C(w);

    if (w->unk_7C == 0) {
        return 0;
    }
    return 1;
}

void func_080F4DDC(MapPrizeWork* w) {
    s16 x;
    s16 y;
    s32 aff;

    if (w->unk_96 != 0) {
        x = (w->unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
        y = (w->unk_04 >> 8) + (w->unk_08 >> 8) - (gUnk_02039BA0->unk_04 >> 8);

        if (w->unk_90 != 0x100) {
            aff = AllocObjAffine(0, w->unk_90, w->unk_90, 0);
        } else {
            aff = 0;
        }

        DrawSprite(x, y, w->unk_74, w->unk_6C, w->unk_70, aff, 0x800, -0x1004 - (w->unk_04 >> 8) * 4);

        if (w->unk_97 == 0) {
            DrawSprite(x, (w->unk_04 >> 8) + (w->unk_0C >> 8) - (gUnk_02039BA0->unk_04 >> 8), w->unk_78, w->unk_6C, w->unk_70, aff, 0x800, 0xFFFF);
        }
    }
}

void func_080F4EC4(MapPrizeWork* w) {
    ReleaseObjTiles(w->unk_6C);
    ReleaseObjPalette(w->unk_70);
    func_08012304(w->unk_10);
}

void func_080F4EE4(MapPrzCardWork* work) {
    work->unk_0B4 = -gSineTable[((work->unk_0D0 + 0x80) & 0xFF) + 0x40] * work->unk_0CC >> 8;
    work->unk_0B6 = -gSineTable[((work->unk_0CF + 0x80) & 0xFF) + 0x40] * work->unk_0CC >> 8;

    if ((u16)(work->unk_0B4 + 2) <= 4) {
        work->unk_0B4 = 2;
    }
    if ((u16)(work->unk_0B6 + 2) <= 4) {
        work->unk_0B6 = 2;
    }
}

void func_080F4F60(MapPrzCardWork* w) {
    s32 dx;
    s32 dy;

    dx = 0x7800;
    dy = 0x5000;
    dx -= w->unk_000;
    dy -= w->unk_004;
    w->unk_0C8 = func_0805F5A4(&dx, &dy);
    w->unk_0C0 = -dx;
    w->unk_0C4 = -dy;
    w->unk_0B0 = 0x300;
    w->unk_0AC = 2;
}

void func_080F4FB0(MapPrzCardWork* w) {
    UnkStruct_080DFF1C v = *(UnkStruct_080DFF1C*)w;
    s32 nx;
    s32 ny;

    w->unk_0AC += 0x38;
    w->unk_008 += w->unk_0AC;
    w->unk_000 += gSineTable[w->unk_0B8] * w->unk_0B0 >> 8;
    w->unk_004 += -gSineTable[w->unk_0B8 + 64] * w->unk_0B0 >> 8;

    if (func_080DFBDC((UnkStruct_080DFF1C*)w) != 0) {
        w->unk_0B8 = w->unk_0B8 + (112 + GetRandom() % 33);
        w->unk_000 = v.unk_00;
        w->unk_004 = v.x;
    } else {
        w->unk_00C = func_080DFF1C((UnkStruct_080DFF1C*)w);
    }

    if (w->unk_008 - 0x800 > w->unk_00C) {
        w->unk_008 = w->unk_00C - 0x800;
        w->unk_0AC = -(w->unk_0AC * 217 >> 8);

        if (w->unk_0AC > -0x200) {
            w->unk_0AC = -0x200;
        }
    }

    if (w->unk_010[0x2C] != 0) {
        w->unk_0D2 = 1;
        m4aSongNumStart(106);
        func_08084458(w->unk_0A8);

        if (w->unk_0D1 == 0) {
            UnkStruct_080DEE18* e = func_080DEE18(gUnk_0203C590.unk_06);

            if (e->unk_0C != 0) {
                e->unk_0C--;
            }
        }

        nx = (w->unk_000 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
        ny = (w->unk_004 >> 8) + (w->unk_008 >> 8) - (gUnk_02039BA0->unk_04 >> 8);
        w->unk_000 = (s16)nx << 8;
        w->unk_004 = (s16)ny << 8;
        func_08012614(&w->unk_010, 1);
        w->unk_0BE = 50;
        func_080F4F60(w);
        w->unk_088 = 0;
        w->unk_08C = func_080F51A0;
    } else {
        w->unk_0BA = (w->unk_000 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
        w->unk_0BC = (w->unk_004 >> 8) + (w->unk_008 >> 8) - (gUnk_02039BA0->unk_04 >> 8);
        w->unk_0BE = -0x1004 - (w->unk_004 >> 8) * 4;
        func_080F4EE4(w);
        w->unk_0D0 += 2;
        func_08012324(&w->unk_010, w->unk_000, w->unk_004, w->unk_008);

        if (w->unk_08A == 20) {
            func_08012614(&w->unk_010, 0);
        }

        if (w->unk_08A <= 59) {
            w->unk_08A++;
        }
    }
}

#ifndef VERSION_EU
void func_080F51A0(MapPrzCardWork* w) {
    s32 dx;
    s32 dy;
    s32 x;
    s32 y;

    if (w->unk_0B0 < 0) {
        dx = 0x7800 - w->unk_000;
        dy = 0x5000 - w->unk_004;
        func_0805F5A4(&dx, &dy);
        w->unk_0C0 = -dx;
        w->unk_0C4 = -dy;

        if (w->unk_0C8 <= 0x7FF) {
            w->unk_0CE = 0;
            w->unk_08A = 0;
            w->unk_08C = func_080F52D4;
            TaskCreate(&w->unk_0D4, &gTaskDescMapMsg, gCardDefs[w->unk_0A8].unk_0C);
        }
    }

    w->unk_000 += w->unk_0C0 * w->unk_0B0 >> 8;
    w->unk_004 += w->unk_0C4 * w->unk_0B0 >> 8;
    w->unk_0CE += 32;
    w->unk_0CF += (64 - w->unk_0CF) >> 4;
    w->unk_0D0 = 0;
    w->unk_0C8 = func_0805F588(0x7800 - w->unk_000, 0x5000 - w->unk_004);
    w->unk_0B0 -= w->unk_0AC;
    w->unk_0AC += 2;
    w->unk_0CC += 3;

    if (w->unk_0CC > 0x100) {
        w->unk_0CC = 0x100;
    }

    x = w->unk_000 >> 8;
    w->unk_0BA = x;
    y = w->unk_004 >> 8;
    w->unk_0BC = y;
    func_080F4EE4(w);
}
#else
INCLUDE_ASM("map/func_080F51A0.s");
#endif

void func_080F52D4(MapPrzCardWork* w) {
    s32 x;
    s32 y;

    w->unk_000 = 0x7800;
    w->unk_004 = 0x5800;
    w->unk_0CE = 0;
    w->unk_0CF = 0;
    w->unk_0CC += 2;

    if (w->unk_0CC > 0x100) {
        w->unk_0CC = 0x100;
    }

    x = w->unk_000 >> 8;
    w->unk_0BA = x;
    y = w->unk_004 >> 8;
    w->unk_0BC = y;
    func_080F4EE4(w);
    w->unk_08A++;

    if (w->unk_08A == 30) {
        w->unk_08A = 0;
        w->unk_08C = func_080F534C;
    }

    TaskPoolUpdate(&w->unk_0D4);
}

void func_080F534C(MapPrzCardWork* w) {
    s32 x;
    s32 y;

    w->unk_0CE += 32;
    x = (gUnk_02039BA0->unk_18 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    y = (gUnk_02039BA0->unk_1C >> 8) + (gUnk_02039BA0->unk_20 >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    w->unk_0BA += ((s16)x - w->unk_0BA) >> 3;
    w->unk_0BC += ((s16)y - w->unk_0BC) >> 3;
    w->unk_0B4 -= 10;
    w->unk_0B6 -= 10;

    if (w->unk_0B4 <= 10) {
        w->unk_08C = 0;
    }
}

void func_080F53D0(MapPrzCardWork* w, UnkStruct_080E8F50* p) {
    CardDef* d;
    UnkStruct_08F709B0* q;

    gUnk_0203C7AC->unk_00 |= 0x10;
    w->unk_0A8 = p->unk_14;
    d = &gCardDefs[w->unk_0A8];
    w->unk_070 = LoadObjTiles(d->unk_04, 0x300);
    w->unk_06C = LoadObjPalette(d->unk_08, 32);
    w->unk_090 = *(UnkStruct_08F70ACC*)&d->unk_1C;
    q = &gUnk_08F709B0[w->unk_090.unk_0E];
    w->unk_074 = LoadObjPalette(gUnk_09611AB8, 32);
    w->unk_078 = LoadObjTiles(q->unk_0C, 0x280);
    w->unk_07C = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    w->unk_084 = LoadObjPalette(gUnk_08F69BE4, 32);
    w->unk_080 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->unk_000 = p->unk_04;
    w->unk_004 = p->unk_08;
    w->unk_008 = p->unk_0C;
    w->unk_00C = 0;
    func_080DFF4C((UnkStruct_080DFF1C*)w);
    w->unk_0AC = -(GetRandom() % 129 + 0x300);
    w->unk_0B0 = GetRandom() % 129 + 128;
    w->unk_0B8 = GetRandom();
    w->unk_0B4 = 128;
    w->unk_0B6 = 128;
    w->unk_0CC = 128;
    w->unk_0CE = 24;
    w->unk_0CF = 0;
    w->unk_0D0 = 0;
    w->unk_0D1 = p->unk_00;
    func_080122AC(&w->unk_010, 5, 30, 10);
    func_08012324(&w->unk_010, w->unk_000, w->unk_004, w->unk_008);

    if (w->unk_0D1 != 0) {
        func_08012614(&w->unk_010, 0);
    } else {
        func_08012614(&w->unk_010, 1);
    }

    w->unk_088 = 0x800;
    w->unk_08A = 0;
    w->unk_08C = func_080F4FB0;
    w->unk_0D2 = 0;
    TaskPoolInit(&w->unk_0D4, 1);
}

s32 func_080F5580(MapPrzCardWork* w) {
    if ((u8)func_080E0390() != 0) {
        return 0;
    }

    if (w->unk_08C == 0) {
        return 0;
    }
    w->unk_08C(w);

    if (w->unk_08C == 0) {
        return 0;
    }
    return 1;
}

void func_080F55B0(MapPrzCardWork* w) {
    CardDef* d;
    UnkStruct_08F709B0* q;
    void* t;
    s32 affine;
    s16 x;
    s16 y;
    s16 s;

    if (*(s32*)&w->unk_0B4 == 0x01000100 && w->unk_0CE == 0) {
        affine = 0;
    } else {
        affine = AllocObjAffine(w->unk_0CE, w->unk_0B4, w->unk_0B6, 1);
    }

    d = &gCardDefs[w->unk_0A8];
    DrawSprite(w->unk_0BA, *(u16*)&w->unk_0BC - 8, d->unk_00, w->unk_070, w->unk_06C,
        affine, w->unk_088, w->unk_0BE + 1);
    q = &gUnk_08F709B0[w->unk_090.unk_0E];
    DrawSprite(w->unk_0BA, *(u16*)&w->unk_0BC - 8, q->unk_00, w->unk_078,
        w->unk_074, affine, w->unk_088, w->unk_0BE);

    if (w->unk_090.unk_0E != 3) {
        t = gUnk_09EE981C[w->unk_090.unk_04];
        DrawSprite(w->unk_0BA, *(u16*)&w->unk_0BC - 8, t, w->unk_07C,
            w->unk_074, affine, w->unk_088, w->unk_0BE - 1);
    }

    if (w->unk_0D2 == 0) {
        x = (w->unk_000 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
        y = (w->unk_004 >> 8) + (w->unk_00C >> 8) - (gUnk_02039BA0->unk_04 >> 8);
        s = 204 - ((w->unk_00C - w->unk_008) >> 7);

        if (s <= 2) {
            s = 2;
        }

        DrawSprite(x, y, gUnk_09EE1380[0], w->unk_080, w->unk_084,
            AllocObjAffine(0, s, s, 0), 0x800, w->unk_0BE + 2);
    }

    TaskPoolDraw(&w->unk_0D4);
}
void func_080F5780(MapPrzCardWork* w) {
    func_080062F4(w->unk_074->unk_06 + 0x10, 0);
    func_080062F4(w->unk_06C->unk_06 + 0x10, 0);
    func_08012304(w->unk_010);
    ReleaseObjTiles(w->unk_070);
    ReleaseObjTiles(w->unk_078);
    ReleaseObjTiles(w->unk_07C);
    ReleaseObjTiles(w->unk_080);
    ReleaseObjPalette(w->unk_06C);
    ReleaseObjPalette(w->unk_074);
    ReleaseObjPalette(w->unk_084);
    TaskPoolDestroy(&w->unk_0D4);
    gUnk_0203C7AC->unk_00 &= ~0x10;
}

void func_080F5800(MapPrzStockWork* w) {
    func_080A411C(&w->unk_08, 0, w->unk_00[1]);
    w->unk_04 = func_080F5820;
}

void func_080F5820(MapPrzStockWork* w) {
    if (func_080A42C8() == 0) {
        w->unk_04 = 0;
    }
}

void func_080F5838(MapPrzStockWork* w, u16* a) {
    w->unk_00 = a;
    gUnk_02039BA0->unk_70 |= 0x1000;
    gUnk_02039BA0->unk_70 |= 0x80;
    w->unk_04 = func_080F5800;
    TaskPoolInit(&w->unk_08, 1);
}

s32 func_080F5868(MapPrzStockWork* w) {
    TaskPoolUpdate(&w->unk_08);

    if (w->unk_04 != 0) {
        w->unk_04(w);

        if (w->unk_04 != 0) {
            return 1;
        }
    }
    return 0;
}

void func_080F5890(MapPrzStockWork* w) {
    TaskPoolDraw(&w->unk_08);
}

void func_080F589C(MapPrzStockWork* w) {
    TaskPoolDestroy(&w->unk_08);
    gUnk_02039BA0->unk_70 &= ~0x1000;
    gUnk_02039BA0->unk_70 &= ~0x80;
}

void func_080F58C4(MapMsgWork* w, void* text) {
    LoadBgTiles(0, &gUnk_099597E4[0x140], 0x140);
    LoadBgMap(0, &gUnk_09985F44[0x800], 0x800);
    SetBgScroll(0, 0, -46);
    LoadPalette(gUnk_09611AB8, &gUnk_050001C0[0x20], 32);
    func_08065ACC(w->unk_004, 48);
    w->unk_184 = func_08065B6C(text, w->unk_004);
    w->unk_000 = _08066468(1);
    func_080062F4(w->unk_000->unk_06 + 16, 1);
    w->unk_186 = (240 - func_08065B08(w->unk_004, w->unk_184)) / 2;
    w->unk_188 = 0;
}

s32 func_080F5968(MapMsgWork* w) {
    return 1;
}

void func_080F596C(MapMsgWork* w) {
    func_080664D8(w->unk_186, 120, &w->unk_004, w->unk_000, 50, w->unk_184);
}

void func_080F59A0(MapMsgWork* w) {
    if ((gUnk_02039BA0->unk_70 & 0x40000) == 0) {
        DisableBg(0);
    }

    func_080062F4(w->unk_000->unk_06 + 0x10, 0);
    ReleaseObjPalette((u8*)w->unk_000);
    func_08065AE0(&w->unk_004, 0x30);
}

s32 func_080F59E4(MapMsgWork* w) {
    w->unk_188++;

    if (w->unk_188 == 120) {
        return 0;
    }
    return 1;
}

void func_080F5A00(MapSparkWork* w, void* arg) {
    AnimState* a;

    w->unk_00 = arg;
    w->unk_1C = AllocObjTiles(0x200, gUnk_098A4B68);
    w->unk_20 = LoadObjPalette(gUnk_08F69BE4, 32);
    a = &w->unk_04;
    AnimInit(a, gUnk_09EF8CC0, gUnk_09EF8CA0);

    if (gGameState.flags & 8) {
        AnimStart(a, 1, 1);
    } else {
        AnimStart(a, 0, 1);
    }
}

s32 func_080F5A64(MapSparkWork* w) {
    AnimUpdate(&w->unk_04);

    if (AnimIsFinished(&w->unk_04) != 0) {
        return 0;
    }
    return 1;
}

void func_080F5A88(MapSparkWork* w) {
    UnkStruct_080E8374* p = w->unk_00;
    s32 h;
    u16 x;
    u16 y;

    if (p->unk_1A <= 32) {
        h = p->unk_1A << 8;
    } else {
        h = 0x2000;
    }

    x = (p->unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    y = (p->unk_04 >> 8) + ((p->unk_08 - h) >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    DrawSprite(x, y, AnimGetGfx(&w->unk_04), w->unk_1C, w->unk_20, 0, 0x400, 0x50);
}

void func_080F5B00(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x1C]);
    ReleaseObjPalette(*(u8**)&work[0x20]);
}

void func_080F5B18(MapTalkWork* w, s32* arg) {
    w->unk_00 = arg;
    w->unk_1C = AllocObjTiles(0x200, &gUnk_098A4B68[0x1028]);
    w->unk_20 = LoadObjPalette(gUnk_08F69BE4, 32);
    AnimInit(&w->unk_04, (s32)gUnk_09EF8CD0, (s32)gUnk_09EF8CC8);
    AnimStart(&w->unk_04, 0, 1);
    w->unk_28 = 0;
}

s32 func_080F5B68(MapTalkWork* w) {
    s32* p = w->unk_00;
    AnimState* anim = &w->unk_04;

    AnimUpdate(anim);

    if (gUnk_02039BA0->unk_18 < *p) {
        w->unk_28 = 0;
        AnimStart(anim, 0, 1);
    } else {
        w->unk_28 = 1;
        AnimStart(anim, 1, 1);
    }
    return 1;
}

void func_080F5BB8(MapTalkWork* w) {
    UnkStruct_080E8374* p = (UnkStruct_080E8374*)w->unk_00;
    u16 x;
    u16 y;

    if (w->unk_28 != 0) {
        x = (p->unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8) - 16;
    } else {
        x = (p->unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8) + 16;
    }
    y = (p->unk_04 >> 8) + ((p->unk_08 - (p->unk_1A << 8)) >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    DrawSprite(x, y, AnimGetGfx(&w->unk_04), w->unk_1C, w->unk_20, 0, 0x400, 0x50);
}

void func_080F5C48(MapTalkWork* w) {
    ReleaseObjTiles(w->unk_1C);
    ReleaseObjPalette(w->unk_20);
}

void func_080F5C60(MapDonaldWork* w) {
    if (w->unk_0C0 != 0 && (GetKeysPressed() & 1)) {
        gUnk_02039BA0->unk_70 |= 0x1000;

        if ((s8)gGameState.floor == 12 && gUnk_0203C590.unk_06 == 0xFD) {
            func_080A411C(&w->unk_0C4, 0, 24);
        } else {
            func_080A411C(&w->unk_0C4, 0, gUnk_0984C2E4[gUnk_0203C590.unk_00]);
        }

        w->unk_0BC = func_080F5CDC;
    }
}

void func_080F5CDC(MapDonaldWork* w) {
    if (func_080A42C8() == 0) {
        gUnk_02039BA0->unk_70 &= ~0x1000;
        w->unk_0BC = func_080F5C60;
    }
}

void func_080F5D10(MapDonaldWork* w) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)w;

    if (gUnk_0203C590.unk_06 != 0xFE) {
        if ((s8)gGameState.floor == 12) {
            w->unk_000 = 0x22300;
            w->unk_004 = 0xE600;
        } else {
            w->unk_000 = 0x28800;
            w->unk_004 = 0x10000;
        }
    } else {
        if ((s8)gGameState.floor != 0) {
            w->unk_000 = 0x25000;
            w->unk_004 = 0x11000;
        } else {
            w->unk_000 = 0x35000;
            w->unk_004 = 0x12000;
        }
    }

    e->unk_00.y = 0;
    e->unk_00.z = func_080DFF30(&e->unk_00);
    e->unk_00.y = e->unk_00.z;
    e->unk_00.x -= e->unk_00.z;
    e->unk_14 = 0x80;
    e->unk_1A = 0x20;
    e->unk_30 = 2;
    w->unk_0C1 = 1;
    w->unk_0BC = func_080F5C60;
    w->unk_0B4 = AllocObjTiles(0x400, gUnk_0919FDF8);
    w->unk_0B8 = LoadObjPalette(gUnk_09617C58, 32);
    AnimInit(&w->unk_09C, gUnk_09EEE0A8, gUnk_09EEE03C);
    AnimStart(&w->unk_09C, 0, 1);
    func_080122AC(&w->unk_040, 4, 16, 48);
    func_08012324(&w->unk_040, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
    func_080121D4(e);
    TaskPoolInit(&w->unk_0C4, 2);
    TaskCreate(&w->unk_0C4, &gTaskDescFldShadow, w);
    w->unk_0C0 = 0;
    TaskPoolInit(&w->unk_0D8, 1);
    TaskCreate(&w->unk_0D8, &gTaskDescMapTalk, w);
}

s32 func_080F5E4C(MapDonaldWork* w) {
    if ((u8)func_080E0390() != 0) {
        w->unk_0C1 = 0;
    } else {
        w->unk_0C1 = 1;
        w->unk_0C0 = func_080E03C0((s32)w);
        TaskPoolUpdate(&w->unk_0C4);
        TaskPoolUpdate(&w->unk_0D8);
        AnimUpdate(&w->unk_09C);

        if (w->unk_0BC != 0) {
            w->unk_0BC(w);
        }
    }

    return 1;
}

void func_080F5EA8(MapDonaldWork* w) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)w;
    u16 v;
    s32 k;
    s16 x;
    s16 y;

    if (w->unk_0C1 != 0) {
        x = (p->unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
        k = p->x >> 8;
        y = k + (p->y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
        v = -0x1004 - k * 4;
        DrawSprite(x, y, AnimGetGfx(&w->unk_09C), w->unk_0B4, w->unk_0B8, 0, 0x800, v);
        *(s32*)((u8*)p + 0x3C) = p->z;
        *(u16*)((u8*)p + 0x3A) = v + 1;
        TaskPoolDraw(&w->unk_0C4);

        if (w->unk_0C0 != 0) {
            TaskPoolDraw(&w->unk_0D8);
        }
    }
}

void func_080F5F4C(MapFrdWork* w) {
    ReleaseObjTiles(w->unk_0B4);
    ReleaseObjPalette(w->unk_0B8);
    func_08012304(w->unk_040);
    func_080121FC(w);
    TaskPoolDestroy(&w->unk_0C4);
    TaskPoolDestroy(&w->unk_0D8);
}

void func_080F5F88(MapGoofyWork* w) {
    if (w->unk_0C0 != 0 && (GetKeysPressed() & 1)) {
        gUnk_02039BA0->unk_70 |= 0x1000;

        if ((s8)gGameState.floor == 12 && gUnk_0203C590.unk_06 == 0xFD) {
            func_080A411C(&w->unk_0C4, 0, 49);
        } else {
            func_080A411C(&w->unk_0C4, 0, gUnk_0984C310[gUnk_0203C590.unk_00]);
        }

        w->unk_0BC = func_080F6004;
    }
}

void func_080F6004(MapGoofyWork* w) {
    if (func_080A42C8() == 0) {
        gUnk_02039BA0->unk_70 &= ~0x1000;
        w->unk_0BC = func_080F5F88;
    }
}

void func_080F6038(MapGoofyWork* w) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)w;

    if (gUnk_0203C590.unk_06 != 0xFE) {
        if ((s8)gGameState.floor == 12) {
            w->unk_000 = 0x25000;
            w->unk_004 = 0x10A00;
        } else {
            w->unk_000 = 0x20000;
            w->unk_004 = 0xB000;
        }
    } else {
        if ((s8)gGameState.floor != 0) {
            w->unk_000 = 0x1E800;
            w->unk_004 = 0xD000;
        } else {
            w->unk_000 = 0x2C000;
            w->unk_004 = 0xE000;
        }
    }

    e->unk_00.y = 0;
    e->unk_00.z = func_080DFF30(&e->unk_00);
    e->unk_00.y = e->unk_00.z;
    e->unk_00.x -= e->unk_00.z;
    e->unk_14 = 0x80;
    e->unk_1A = 0x30;
    e->unk_30 = 2;
    w->unk_0C1 = 1;
    w->unk_0BC = func_080F5F88;
    w->unk_0B4 = AllocObjTiles(0x400, gUnk_091ABDB8);
    w->unk_0B8 = LoadObjPalette(gUnk_08F68384, 32);
    AnimInit(&w->unk_09C, gUnk_09EEE1CC, gUnk_09EEE1C8);
    AnimStart(&w->unk_09C, 0, 1);
    func_080122AC(&w->unk_040, 4, 16, 48);
    func_08012324(&w->unk_040, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
    func_080121D4(e);
    TaskPoolInit(&w->unk_0C4, 2);
    TaskCreate(&w->unk_0C4, &gTaskDescFldShadow, w);
    w->unk_0C0 = 0;
    TaskPoolInit(&w->unk_0D8, 1);
    TaskCreate(&w->unk_0D8, &gTaskDescMapTalk, w);
}

s32 func_080F6174(MapGoofyWork* w) {
    if ((u8)func_080E0390() != 0) {
        w->unk_0C1 = 0;
    } else {
        w->unk_0C1 = 1;
        w->unk_0C0 = func_080E03C0((s32)w);
        TaskPoolUpdate(&w->unk_0C4);
        TaskPoolUpdate(&w->unk_0D8);
        AnimUpdate(&w->unk_09C);

        if (w->unk_0BC != 0) {
            w->unk_0BC(w);
        }
    }

    return 1;
}

void func_080F61D0(MapGoofyWork* w) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)w;
    u16 v;
    s32 k;
    s16 x;
    s16 y;

    if (w->unk_0C1 != 0) {
        x = (p->unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
        k = p->x >> 8;
        y = k + (p->y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
        v = -0x1004 - k * 4;
        DrawSprite(x, y, AnimGetGfx(&w->unk_09C), w->unk_0B4, w->unk_0B8, 0, 0x800, v);
        *(s32*)((u8*)p + 0x3C) = p->z;
        *(u16*)((u8*)p + 0x3A) = v + 1;
        TaskPoolDraw(&w->unk_0C4);

        if (w->unk_0C0 != 0) {
            TaskPoolDraw(&w->unk_0D8);
        }
    }
}

void func_080F6274(MapFrdWork* w) {
    ReleaseObjTiles(w->unk_0B4);
    ReleaseObjPalette(w->unk_0B8);
    func_08012304(w->unk_040);
    func_080121FC(w);
    TaskPoolDestroy(&w->unk_0C4);
    TaskPoolDestroy(&w->unk_0D8);
}

void func_080F62B0(MapNamineWork* w) {
    if (w->unk_0C1 != 0 && (GetKeysPressed() & 1)) {
        gUnk_02039BA0->unk_70 |= 0x1000;

        if (gUnk_0203C590.unk_00 == 27) {
            func_080A411C(&w->unk_0C8, 0, 0x33);
        } else {
            func_080A411C(&w->unk_0C8, 0, 0x32);
        }
        w->unk_0BC = func_080F6314;
    }
}

void func_080F6314(MapNamineWork* w) {
    if (func_080A42C8() == 0) {
        gUnk_02039BA0->unk_70 &= ~0x1000;
        w->unk_0BC = func_080F62B0;
    }
}

void func_080F6348(MapNamineWork* w) {
    UnkStruct_080E6394* p = (UnkStruct_080E6394*)w;

    switch (gUnk_0203C590.unk_00) {
    case 27:
        w->unk_000 = 0x20D00;
        w->unk_004 = 0xD500;
        w->unk_0C4 = 0x800;
        break;
    case 23:
        w->unk_000 = 0x27C00;
        w->unk_004 = 0xD400;
        w->unk_0C4 = 0x800;
        break;
    case 24:
    case 25:
    case 26:
    default:
        p->unk_00.unk_00 = 0x15200;
        p->unk_00.x = 0xF800;
        w->unk_0C4 = 0x801;
        break;
    }

    p->unk_00.y = 0;
    p->unk_00.y = p->unk_00.z = func_080DFF30(&p->unk_00);
    p->unk_00.x -= p->unk_00.z;
    p->unk_14 = 173;
    p->unk_1A = 48;
    p->unk_30 = 2;
    w->unk_0C0 = gUnk_0203C590.unk_00 != 23;
    w->unk_0C2 = 1;
    w->unk_0BC = func_080F62B0;
    w->unk_0B4 = AllocObjTiles(0x300, gUnk_093E1EE0);
    w->unk_0B8 = LoadObjPalette(gUnk_096184D8, 32);
    AnimInit(&w->unk_09C, gUnk_09EF0D64, gUnk_09EF0D48);
    AnimStart(&w->unk_09C, 0, 1);
    func_080122AC(w->unk_040, 4, 16, 48);
    func_08012324(w->unk_040, p->unk_00.unk_00, p->unk_00.x, p->unk_00.y);

    if (w->unk_0C0 != 0) {
        func_080121D4(p);
    }

    TaskPoolInit(&w->unk_0C8, 2);
    TaskCreate(&w->unk_0C8, &gTaskDescFldShadow, w);
    w->unk_0C1 = 0;
    TaskPoolInit(&w->unk_0DC, 1);
    TaskCreate(&w->unk_0DC, &gTaskDescMapTalk, w);
}

s32 func_080F64A4(MapNamineWork* w) {
    if ((u8)func_080E0390() != 0) {
        w->unk_0C2 = 0;
    } else {
        w->unk_0C2 = 1;
        w->unk_0C1 = func_080E03C0((s32)w);
        TaskPoolUpdate(&w->unk_0C8);
        TaskPoolUpdate(&w->unk_0DC);
        AnimUpdate(&w->unk_09C);

        if (w->unk_0BC != 0) {
            w->unk_0BC(w);
        }
    }

    return 1;
}

void func_080F6500(MapNamineWork* w) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)w;
    u16 v;
    s32 k;
    s16 x;
    s16 y;

    if (w->unk_0C2 != 0) {
        x = (p->unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
        k = p->x >> 8;
        y = k + (p->y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
        v = -0x1004 - k * 4;
        DrawSprite(x, y, AnimGetGfx(&w->unk_09C), w->unk_0B4, w->unk_0B8, 0, w->unk_0C4, v);
        *(s32*)((u8*)p + 0x3C) = p->z;
        *(u16*)((u8*)p + 0x3A) = v + 1;
        TaskPoolDraw(&w->unk_0C8);

        if (w->unk_0C1 != 0) {
            TaskPoolDraw(&w->unk_0DC);
        }
    }
}

void func_080F65A8(MapNamineWork* w) {
    ReleaseObjTiles(w->unk_0B4);
    ReleaseObjPalette(w->unk_0B8);
    func_08012304(w->unk_040);

    if (w->unk_0C0 != 0) {
        func_080121FC(w);
    }

    TaskPoolDestroy(&w->unk_0C8);
    TaskPoolDestroy(&w->unk_0DC);
}

void func_080F65EC(MapNamineWork* w) {
    if (w->unk_0C1 != 0 && (GetKeysPressed() & 1)) {
        gUnk_02039BA0->unk_70 |= 0x1000;
        func_080A411C(&w->unk_0C4, 0, 0x34);
        w->unk_0BC = func_080F6634;
    }
}

void func_080F6634(MapNamineWork* w) {
    if (func_080A42C8() == 0) {
        gUnk_02039BA0->unk_70 &= ~0x1000;
        w->unk_0BC = func_080F65EC;
    }
}

void func_080F6668(MapNamineWork* w) {
    s32 dx;
    s32 dy;

    dx = w->unk_000 - gUnk_02039BA0->unk_18;

    if (dx < 0) {
        dx = gUnk_02039BA0->unk_18 - w->unk_000;
    }

    dy = w->unk_004 - gUnk_02039BA0->unk_1C;

    if (dy < 0) {
        dy = gUnk_02039BA0->unk_1C - w->unk_004;
    }

    if (dx <= 0x8000 && dy <= 0x8000) {
        if (func_08003C9C((dx * dx >> 8) + (dy * dy >> 8)) < 0x3000) {
            func_08006184(0, 16);
            gUnk_02039BA0->unk_70 |= 0x1000;
            w->unk_0BC = func_080F66E0;
        }
    }
}

void func_080F66E0(MapNamineWork* w) {
    if (func_08006314() == 0) {
        func_0806180C(0x3B);
        w->unk_0BC = 0;
    }
}

void func_080F6704(MapNiserikuWork* w) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)w;
    s32 c;

    switch (gUnk_0203C590.unk_00) {
    case 27:
        e->unk_00.unk_00 = 0x27C00;
        e->unk_00.x = 0x10700;
        break;
    case 23:
        e->unk_00.unk_00 = 0x24900;
        e->unk_00.x = 0xD500;
        break;
    case 24:
    case 25:
    case 26:
    default:
        e->unk_00.unk_00 = 0x17A00;
        e->unk_00.x = 0x11000;
        break;
    }

    e->unk_00.y = 0;
    e->unk_00.y = e->unk_00.z = func_080DFF30(&e->unk_00);
    e->unk_00.x -= e->unk_00.y;
    e->unk_14 = 173;
    e->unk_1A = 48;
    e->unk_30 = 2;

    c = 0;

    if (gUnk_0203C590.unk_00 == 27) {
        c = 1;
    }

    w->unk_0C0 = c;

    w->unk_0C2 = 1;
    w->unk_0C1 = 0;
    TaskPoolInit(&w->unk_0D8, 1);
    TaskCreate(&w->unk_0D8, &gTaskDescMapTalk, w);
    TaskPoolInit(&w->unk_0C4, 2);

    switch (gUnk_0203C590.unk_00) {
    case 27:
        w->unk_0BC = func_080F65EC;
        w->unk_0B4 = AllocObjTiles(0x680, gUnk_0937E90A);
        w->unk_0B8 = LoadObjPalette(gUnk_09618338, 32);
        AnimInit(&w->unk_09C, gUnk_09EF04D8, gUnk_09EF04D4);
        AnimStart(&w->unk_09C, 0, 1);
        func_080122AC(&w->unk_040, 4, 16, 48);
        func_08012324(&w->unk_040, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
        TaskCreate(&w->unk_0C4, &gTaskDescFldShadow, w);
        break;
    case 23:
        w->unk_0BC = func_080F6668;
        w->unk_0B4 = AllocObjTiles(0x320, gUnk_0938044A);
        w->unk_0B8 = LoadObjPalette(gUnk_09618338, 32);
        AnimInit(&w->unk_09C, gUnk_09EF0510, gUnk_09EF04FC);
        AnimStart(&w->unk_09C, 0, 1);
        func_080122AC(&w->unk_040, 4, 16, 48);
        func_08012324(&w->unk_040, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
        TaskCreate(&w->unk_0C4, &gTaskDescFldShadow, w);
        break;
    case 24:
    case 25:
    case 26:
    default:
        w->unk_0BC = 0;
        w->unk_0B4 = AllocObjTiles(0x300, gUnk_0938D282);
        w->unk_0B8 = LoadObjPalette(gUnk_09618338, 32);
        AnimInit(&w->unk_09C, gUnk_09EF0628, gUnk_09EF060C);
        AnimStart(&w->unk_09C, 1, 1);
        func_080122AC(&w->unk_040, 4, 36, 48);
        func_08012324(&w->unk_040, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
        break;
    }

    if (w->unk_0C0 != 0) {
        func_080121D4(e);
    }
}

s32 func_080F691C(MapNiserikuWork* w) {
    if ((u8)func_080E0390() != 0) {
        w->unk_0C2 = 0;
    } else {
        w->unk_0C2 = 1;
        w->unk_0C1 = func_080E03C0((s32)w);
        TaskPoolUpdate(&w->unk_0C4);
        TaskPoolUpdate(&w->unk_0D8);
        AnimUpdate(&w->unk_09C);

        if (w->unk_0BC != 0) {
            w->unk_0BC(w);
        }
    }

    return 1;
}

void func_080F6978(MapNiserikuWork* w) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)w;
    u16 v;
    s32 k;
    s16 x;
    s16 y;

    if (w->unk_0C2 != 0) {
        x = (p->unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
        k = p->x >> 8;
        y = k + (p->y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
        v = -0x1004 - k * 4;
        DrawSprite(x, y, AnimGetGfx(&w->unk_09C), w->unk_0B4, w->unk_0B8, 0, 0x800, v);
        *(s32*)((u8*)p + 0x3C) = p->z;
        *(u16*)((u8*)p + 0x3A) = v + 1;
        TaskPoolDraw(&w->unk_0C4);

        if (w->unk_0C1 != 0) {
            TaskPoolDraw(&w->unk_0D8);
        }
    }
}

void func_080F6A1C(MapMickeyWork* w) {
    ReleaseObjTiles(w->unk_0B4);
    ReleaseObjPalette(w->unk_0B8);
    func_08012304(w->unk_040);

    if (w->unk_0C0 != 0) {
        func_080121FC(w);
    }

    TaskPoolDestroy(&w->unk_0C4);
    TaskPoolDestroy(&w->unk_0D8);
}

void func_080F6A60(MapMickeyWork* w) {
    if (w->unk_0C0 != 0 && (GetKeysPressed() & 1)) {
        gUnk_02039BA0->unk_70 |= 0x1000;

        switch (gUnk_0203C590.unk_00) {
        case 20:
            func_080A411C(&w->unk_0C4, 0, 0x3F);
            break;
        case 22:
            func_080A411C(&w->unk_0C4, 0, 0x3D);
            break;
        case 23:
        default:
            func_080A411C(&w->unk_0C4, 0, 0x3E);
            break;
        }

        w->unk_0BC = func_080F6AD8;
    }
}

void func_080F6AD8(MapMickeyWork* w) {
    if (func_080A42C8() == 0) {
        gUnk_02039BA0->unk_70 &= ~0x1000;
        w->unk_0BC = func_080F6A60;
    }
}

void func_080F6B0C(MapMickeyWork* w) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)w;

    e->unk_00.unk_00 = 0x1C800;
    e->unk_00.x = 0xE000;
    w->unk_0C2 = 0x801;
    e->unk_00.y = 0;
    e->unk_00.z = func_080DFF30(&e->unk_00);
    e->unk_00.y = e->unk_00.z;
    e->unk_00.x -= e->unk_00.z;
    e->unk_14 = 0xAD;
    e->unk_1A = 0x30;
    e->unk_30 = 2;
    w->unk_0C1 = 1;
    w->unk_0BC = func_080F6A60;
    w->unk_0B4 = AllocObjTiles(0x300, gUnk_093A5E10);
    w->unk_0B8 = LoadObjPalette(gUnk_096183F8, 32);
    AnimInit(&w->unk_09C, gUnk_09EF0824, gUnk_09EF0820);
    AnimStart(&w->unk_09C, 0, 1);
    func_080122AC(&w->unk_040, 4, 16, 48);
    func_08012324(&w->unk_040, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
    func_080121D4(e);
    TaskPoolInit(&w->unk_0C4, 2);
    TaskCreate(&w->unk_0C4, &gTaskDescFldShadow, w);
    w->unk_0C0 = 0;
    TaskPoolInit(&w->unk_0D8, 1);
    TaskCreate(&w->unk_0D8, &gTaskDescMapTalk, w);
}

s32 func_080F6C00(MapMickeyWork* w) {
    if ((u8)func_080E0390() != 0) {
        w->unk_0C1 = 0;
    } else {
        w->unk_0C1 = 1;
        w->unk_0C0 = func_080E03C0((s32)w);
        TaskPoolUpdate(&w->unk_0C4);
        TaskPoolUpdate(&w->unk_0D8);
        AnimUpdate(&w->unk_09C);

        if (w->unk_0BC != 0) {
            w->unk_0BC(w);
        }
    }

    return 1;
}

void func_080F6C5C(MapMickeyWork* w) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)w;
    u16 v;
    s32 k;
    s16 x;
    s16 y;

    if (w->unk_0C1 != 0) {
        x = (p->unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
        k = p->x >> 8;
        y = k + (p->y >> 8) - (gUnk_02039BA0->unk_04 >> 8);
        v = -0x1004 - k * 4;
        DrawSprite(x, y, AnimGetGfx(&w->unk_09C), w->unk_0B4, w->unk_0B8, 0, w->unk_0C2, v);
        *(s32*)((u8*)p + 0x3C) = p->z;
        *(u16*)((u8*)p + 0x3A) = v + 1;
        TaskPoolDraw(&w->unk_0C4);

        if (w->unk_0C0 != 0) {
            TaskPoolDraw(&w->unk_0D8);
        }
    }
}

void func_080F6D04(MapFrdWork* w) {
    ReleaseObjTiles(w->unk_0B4);
    ReleaseObjPalette(w->unk_0B8);
    func_08012304(w->unk_040);
    func_080121FC(w);
    TaskPoolDestroy(&w->unk_0C4);
    TaskPoolDestroy(&w->unk_0D8);
}

void func_080F6D40(void) {
    gUnk_02039BA0->unk_70 |= 0x80;
    gUnk_0203C7AC->unk_0E = 10;
    gUnk_0203C7AC->unk_00 &= ~0x4000;
    gUnk_0203C7AC->unk_00 |= 2;
}

void func_080F6D70(MapTutorialWork* w) {
    u32 flags;

    if (gUnk_02039BA0->unk_68 == 0) {
        flags = gUnk_02039BA0->unk_70;

        if (!(flags & 0x2000) && !(gUnk_0203C7AC->unk_00 & 0x2000) && (gGameState.unk_17A & 0x10)) {
            gUnk_0203C7AC->unk_00 |= 0x4000;
            gUnk_02039BA0->unk_70 = flags | 0x1000;
            func_080A411C(&w->unk_0C8, 0, 0x6A);
            w->unk_0C4 = func_080F6DE8;
        }
    }
}

void func_080F6DE8(MapTutorialWork* w) {
    if (func_080A42C8() == 0) {
        AnimState* a;

        func_080E5354((UnkStruct_080DFF1C*)w, &w->unk_004);
        w->unk_008 = 0;
        w->unk_00C = func_080DFF30((UnkStruct_080DFF1C*)w);
        w->unk_004 -= w->unk_00C;
        w->unk_008 = w->unk_00C - 0xA000;
        *(u16*)&w->unk_014[6] = 24;
        w->unk_010 = 2;
        w->unk_0B4 = AllocObjTiles(0x400, &gUnk_09858238[0x482]);
        w->unk_0B8 = LoadObjPalette(&gUnk_099910C4[0x220], 32);
        a = &w->unk_09C;
        AnimInit(a, gUnk_09EF8460, gUnk_09EF8424);
        AnimStart(a, 0, 1);
        w->unk_0BC = AnimGetGfx(a);
        func_080122AC(w->unk_040, 6, 12, 24);
        func_08012324(w->unk_040, w->unk_000, w->unk_004, w->unk_008);
        w->unk_0C1 = 1;
        TaskCreate(&w->unk_0DC, &gTaskDescFldShadow, w);
        w->unk_0C0 = 1;
        w->unk_0C4 = func_080F6EBC;
    }
}

void func_080F6EBC(MapTutorialWork* w) {
    MapTutorialWork* p = w;

    w->unk_010 += 0x38;
    w->unk_008 += w->unk_010;

    if (w->unk_008 > w->unk_00C) {
        gUnk_02039BA0->unk_70 &= ~0x1000;
        m4aSongNumStart(0xD7);
        w->unk_008 = w->unk_00C;
        w->unk_010 = 0;
        w->unk_0C1 = 0;
        w->unk_0C4 = func_080F6F1C;
    }
    func_08012324(p->unk_040, p->unk_000, p->unk_004, p->unk_008);
}

void func_080F6F1C(MapTutorialWork* w) {
    if (func_080E02E0((UnkStruct_080DFF1C*)w, 8, 8)) {
        m4aSongNumStart(0x90);
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, w);
        gUnk_0203C7AC->unk_00 &= ~0x20;
        func_080E8FB8(0, w->unk_000, w->unk_004, w->unk_008);
        AnimStart(&w->unk_09C, 1, 0);
        w->unk_0C4 = func_080F6F90;
        func_08012304(w->unk_040);
    }
}

void func_080F6F90(MapTutorialWork* w) {
    if (AnimIsFinished(&w->unk_09C)) {
        w->unk_0C4 = func_080F6FC4;
    } else {
        w->unk_0BC = AnimUpdate(&w->unk_09C);
    }
}

void func_080F6FC4(MapTutorialWork* w) {
    if ((gUnk_0203C7AC->unk_00 & 0x10) == 0) {
        gGameState.unk_17A |= 0x2000;
        gUnk_02039BA0->unk_70 |= 0x1000;
        func_080A411C(&w->unk_0C8, 0, 0x6B);
        w->unk_0C4 = func_080F7024;
    }
}

void func_080F7024(MapTutorialWork* w) {
    if (func_080A42C8() == 0) {
        AnimState* a;
        u8 v;

        func_080E5354((UnkStruct_080DFF1C*)w, &w->unk_004);
        w->unk_008 = 0;
        w->unk_00C = func_080DFF30((UnkStruct_080DFF1C*)w);
        w->unk_004 -= w->unk_00C;
        w->unk_008 = w->unk_00C;
        *(u16*)&w->unk_014[6] = 16;
        v = 0;

        if (gUnk_02039BA0->unk_18 > w->unk_000) {
            v = 1;
        }
        w->unk_0C2 = v;
        w->unk_0B4 = AllocObjTiles(0x400, gUnk_0895EECC);
        w->unk_0B8 = LoadObjPalette(&gUnk_08F691E4[0x5C0], 32);
        a = &w->unk_09C;
        AnimInit(a, gUnk_09EDF940, gUnk_09EDF914);
        AnimStart(a, 0, 1);
        w->unk_0BC = AnimGetGfx(a);
        func_080122AC(w->unk_040, 3, 8, 16);
        func_08012324(w->unk_040, w->unk_000, w->unk_004, w->unk_008);
        func_08012614(w->unk_040, 1);
        w->unk_0C4 = func_080F70F4;
    }
}

void func_080F70F4(MapTutorialWork* w) {
    AnimState* a = &w->unk_09C;

    if (AnimIsFinished(a)) {
        func_08005974(a, 0, 1, gUnk_09EDF85C, gUnk_09EDF834);
        func_08002A10(w->unk_0B4, gUnk_08957290);
        func_080A411C(&w->unk_0C8, 0, 0x6C);
        w->unk_0C4 = func_080F7160;
    } else {
        w->unk_0BC = AnimUpdate(a);
    }
}

void func_080F7160(MapTutorialWork* w) {
    w->unk_0BC = AnimUpdate(&w->unk_09C);

    if (func_080A42C8() == 0) {
        gUnk_02039BA0->unk_70 &= ~0x1000;
        func_08012614(w->unk_040, 0);
        w->unk_0C4 = func_080F71AC;
    }
}

void func_080F71AC(MapTutorialWork* w) {
    AnimState* a = &w->unk_09C;

    w->unk_0BC = AnimUpdate(a);

    if (func_080E02E0((UnkStruct_080DFF1C*)w, 8, 16)) {
        gUnk_0203C7AC->unk_00 |= 0x80;
        gUnk_0203C7AC->unk_00 |= 4;
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapSpark, w);
        m4aSongNumStart(0x75);
        func_08005974(a, 0, 1, gUnk_09EDF9BC, gUnk_09EDF9A8);
        func_08002A10(w->unk_0B4, gUnk_08963BAC);
        w->unk_0C4 = func_080F7284;
    } else if (w->unk_06C != 0) {
        if (!(gUnk_0203C7AC->unk_00 & 4) && w->unk_074 == 1) {
            func_08012614(w->unk_040, 1);
            func_080F6D40();
        } else {
            w->unk_000 += w->unk_078;
            w->unk_004 += w->unk_07C;
        }
    }
}

void func_080F7284(MapTutorialWork* w) {
    AnimState* a = &w->unk_09C;

    if (AnimIsFinished(a)) {
        func_08012614(w->unk_040, 1);
        gGameState.flags |= 4;
        func_080F6D40();
    } else {
        w->unk_0BC = AnimUpdate(a);
    }
}

void func_080F72CC(MapTutorialWork* w) {
    u16 t;

    TaskPoolInit(&w->unk_0C8, 1);
    TaskPoolInit(&w->unk_0DC, 1);
    gUnk_0203C7AC->unk_00 |= 0x20;
    w->unk_0B4 = 0;
    w->unk_0B8 = 0;
    w->unk_0C2 = 0;
    t = gGameState.unk_17A & 0x2000;

    if (t == 0) {
        w->unk_0C1 = 0;
        w->unk_0C0 = 0;
        w->unk_0C4 = func_080F6D70;
    } else {
        gUnk_02039BA0->unk_70 |= 0x1000;
        TaskCreate(&w->unk_0DC, &gTaskDescFldShadow, w);
        w->unk_0C0 = 1;
        w->unk_0C1 = 1;
        w->unk_0C4 = func_080F7024;
    }
}

s32 func_080F7378(MapTutorialWork* w) {
    TaskPoolUpdate(&w->unk_0C8);
    TaskPoolUpdate(&w->unk_0DC);

    if (w->unk_0C4 != 0) {
        w->unk_0C4(w);

        if (w->unk_0C4 != 0) {
            return 1;
        }
    }
    return 0;
}

void func_080F73AC(MapTutorialWork* w) {
    u16 flags;
    u16 v;
    s32 k;
    s32 t;
    s16 x;
    s16 y;

    TaskPoolDraw(&w->unk_0C8);

    if (w->unk_0C0 != 0) {
        x = (w->unk_000 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
        k = w->unk_004 >> 8;
        y = k + (w->unk_008 >> 8) - (gUnk_02039BA0->unk_04 >> 8);
        v = -0x1004 - k * 4;
        t = w->unk_0C2;
        flags = 0x800;

        if (t != 0) {
            flags = 0x801;
        }
        DrawSprite(x, y, w->unk_0BC, w->unk_0B4, w->unk_0B8, 0, flags, v);

        if (w->unk_0C1 != 0) {
            *(s32*)((u8*)w + 0x3C) = w->unk_00C;
            *(u16*)((u8*)w + 0x3A) = v + 1;
            TaskPoolDraw(&w->unk_0DC);
        }
    }
}

void func_080F7458(MapTutorialWork* w) {
    if (w->unk_0B4 != 0) {
        ReleaseObjTiles(w->unk_0B4);
        ReleaseObjPalette(w->unk_0B8);
    }
    TaskPoolDestroy(&w->unk_0C8);
    TaskPoolDestroy(&w->unk_0DC);
}

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

void func_080F74E8(UnkStruct_080DFF1C* p) {
    if ((u8)func_080F7488(p, 0x800) != 0) {
        if (gUnk_02039BA0->unk_20 == gUnk_02039BA0->unk_24) {
            if (gUnk_0203C590.unk_06 == 0xFE) {
                gUnk_0203C7AC->unk_00 |= 0x100;
            } else {
                gUnk_0203C7AC->unk_00 |= 0x400;
            }
        }
    }
}

void func_080F753C(UnkStruct_080DFF1C* p) {
    s32 k = 0x800;

    if ((u8)func_080F7488(p, k) != 0) {
        if (gUnk_02039BA0->unk_20 == gUnk_02039BA0->unk_24) {
            if (gUnk_0203C590.unk_06 == 0xFE) {
                gUnk_0203C7AC->unk_00 |= k;
            } else {
                gUnk_0203C7AC->unk_00 |= 0x200;
            }
        }
    }
}

void func_080F7594(MapStairWork* w) {
    if ((u8)func_080F7488((UnkStruct_080DFF1C*)w, 0x3000) != 0) {
        gUnk_02039BA0->unk_70 |= 0x1000;
        gUnk_0203C7AC->unk_00 |= 0x4000;
        func_080A411C(&w->unk_50, 0, 0xA7);
        w->unk_4C = func_080F75E4;
    }
}

void func_080F75E4(MapStairWork* w) {
    if (func_080A42C8() == 0) {
        gUnk_02039BA0->unk_70 &= ~0x1000;
        gUnk_0203C7AC->unk_00 &= ~0x4000;
        gGameState.unk_17A |= 0x400;
        w->unk_4C = func_080F74E8;
    }
}

void func_080F7640(MapStairWork* w, UnkStruct_080EF4BC* arg) {
    s32 y;

    w->unk_14 = arg->unk_14;
    w->unk_00 = arg->unk_00;
    y = arg->unk_04;
    w->unk_0C = 0;
    w->unk_08 = 0;
    w->unk_04 = y;
    w->unk_40 = LoadObjPalette(gUnk_08F69BE4, 0x20);
    w->unk_44 = LoadObjTiles(gUnk_08B1EA00, 0xE0);
    w->unk_48 = 0;

    switch (w->unk_14) {
    case 0x2D:
        if ((gGameState.unk_17A & 0x400) == 0 && gUnk_0203C590.unk_06 == 0xFD) {
            w->unk_4C = func_080F7594;
        } else {
            w->unk_4C = (void (*)(struct MapStairWork*))func_080F74E8;
        }
        break;
    case 0xAD:
        w->unk_4C = (void (*)(struct MapStairWork*))func_080F753C;
        break;
    }
    TaskPoolInit(&w->unk_50, 1);
}

s32 func_080F76D0(MapStairWork* w) {
    TaskPoolUpdate(&w->unk_50);

    if (w->unk_4C != 0) {
        w->unk_4C(w);
    }
    return 1;
}

void func_080F76F0(MapStairWork* w) {
    s32 x;
    s32 y;

    TaskPoolDraw(&w->unk_50);

    if (w->unk_48 == 1) {
        x = (w->unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
        y = (w->unk_04 >> 8) + (w->unk_08 >> 8) - (gUnk_02039BA0->unk_04 >> 8);
        DrawSprite(x, y, gUnk_08B1E9A6, w->unk_44, w->unk_40, 0, 0x800, 0x101);
    }
}

void func_080F775C(MapStairWork* w) {
    ReleaseObjTiles(w->unk_44);
    ReleaseObjPalette(w->unk_40);
    TaskPoolDestroy(&w->unk_50);
}

void func_080F777C(MapFaintWork* w, void* a) {
    w->unk_00 = a;
    w->unk_1C = AllocObjTiles(0x80, gUnk_08B21ACE);
    w->unk_20 = LoadObjPalette(gUnk_08F69BE4, 32);
    AnimInit(&w->unk_04, gUnk_09EE12E4, gUnk_09EE12D4);
    AnimStart(&w->unk_04, 0, 1);
}

s32 func_080F77C4(u8* work) {
    AnimUpdate((AnimState*)&work[4]);
    return 1;
}

void func_080F77D4(MapFaintWork* w) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)w->unk_00;
    u16 x;
    u16 y;

    x = (e->unk_00.unk_00 >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    y = (e->unk_00.x >> 8) + ((e->unk_00.y - ((s16)e->unk_1A + 8) * 0x100) >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    DrawSprite(x, y, AnimGetGfx(&w->unk_04), w->unk_1C, w->unk_20, 0, 0x800, -0x1005 - (e->unk_00.x >> 8) * 4);
}

void func_080F7860(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x1C]);
    ReleaseObjPalette(*(u8**)&work[0x20]);
}

void func_080F7878(u8* work) {
    s32 z = 0;

    work[8] = z;
    *(void**)&work[0] = LoadObjPalette(gUnk_08F69BE4, 32);
    *(void**)&work[4] = LoadObjTiles(gUnk_08B1EA00, 224);
    *(u16*)&work[10] = z;
    work[9] = 1;
}

s32 func_080F78A8(u8* work) {
    if (work[9] == 0) {
        work[8] = 0;
    } else {
        if (gUnk_0203C7AC->unk_20 != 0 || (gUnk_0203C7AC->unk_00 & 4)) {
            *(u16*)&work[0xA] = 20;
        }

        work[8] = *(u16*)&work[0xA] != 0;

        if (*(u16*)&work[0xA] != 0) {
            *(u16*)&work[0xA] -= 1;
        }
    }
    return 1;
}

void func_080F78EC(u8* work) {
    s16 x;
    s16 y;

    if (work[8] == 0) {
        return;
    }

    x = ((gUnk_0203C7AC->unk_24 - 0x1400) >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    y = ((gUnk_0203C7AC->unk_28 - 0x1400) >> 8) + (gUnk_0203C7AC->unk_2C >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    DrawSprite(x, y, gUnk_08B1E974, *(void**)&work[4], *(void**)&work[0], 0, 0x800, 0x101);

    x = ((gUnk_0203C7AC->unk_24 + 0x1400) >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    y = ((gUnk_0203C7AC->unk_28 - 0x1400) >> 8) + (gUnk_0203C7AC->unk_2C >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    DrawSprite(x, y, gUnk_08B1E97E, *(void**)&work[4], *(void**)&work[0], 0, 0x800, 0x101);

    x = ((gUnk_0203C7AC->unk_24 - 0x1400) >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    y = ((gUnk_0203C7AC->unk_28 + 0x1400) >> 8) + (gUnk_0203C7AC->unk_2C >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    DrawSprite(x, y, gUnk_08B1E992, *(void**)&work[4], *(void**)&work[0], 0, 0x800, 0x101);

    x = ((gUnk_0203C7AC->unk_24 + 0x1400) >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    y = ((gUnk_0203C7AC->unk_28 + 0x1400) >> 8) + (gUnk_0203C7AC->unk_2C >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    DrawSprite(x, y, gUnk_08B1E988, *(void**)&work[4], *(void**)&work[0], 0, 0x800, 0x101);

    x = ((gUnk_0203C7AC->unk_24) >> 8) - (gUnk_02039BA0->unk_00 >> 8);
    y = ((gUnk_0203C7AC->unk_28) >> 8) + (gUnk_0203C7AC->unk_2C >> 8) - (gUnk_02039BA0->unk_04 >> 8);
    DrawSprite(x, y, gUnk_08B1E9A6, *(void**)&work[4], *(void**)&work[0], 0, 0x800, 0x101);
}

void func_080F7A9C(u8* work) {
    ReleaseObjTiles(*(void**)&work[4]);
    ReleaseObjPalette(*(u8**)&work[0]);
}

#ifndef VERSION_EU
void* func_080F7AB4(void) {
    if (gGameState.flags & 8) {
        return gUnk_09EF7000[(s8)gGameState.floor];
    }
    return gUnk_09EF6FCC[(s8)gGameState.floor];
}
#else
INCLUDE_ASM("map/func_080F7AB4.s");
#endif

void func_080F7AE0(MapFloorWork* w) {
    gUnk_02039BA0->unk_70 |= 0x1000;
    gUnk_02039BA0->unk_70 |= 0x80;
    w->unk_00 = LoadObjTiles(gUnk_0993AF64, 0x800);
    w->unk_04 = LoadObjPalette(gUnk_099910C4, 32);
    w->unk_08 = gUnk_09EF8DA4[0];
    w->unk_0E = 120;
#ifdef VERSION_EU
    func_08065ACC(w->unk_18, 60);
#else
    func_08065ACC(w->unk_18, 40);
#endif
    w->unk_14 = _08066468(1);
    w->unk_10 = func_08065B6C(func_080F7AB4(), w->unk_18);
    w->unk_0C = (240 - func_08065B08(w->unk_18, w->unk_10)) / 2;
}

s32 func_080F7B64(u8* work) {
    u16* p = (u16*)&work[14];

    if (*p != 0) {
        (*p)--;
        return 1;
    }
    return 0;
}

void func_080F7B78(MapFloorWork* w) {
    DrawSprite(120, 138, w->unk_08, w->unk_00, w->unk_04, 0, 0, 0x3C);
    func_080664D8(w->unk_0C, 0x85, w->unk_18, w->unk_14, 50, w->unk_10);
}

void func_080F7BB8(MapFloorWork* w) {
    ReleaseObjPalette(w->unk_04);
    ReleaseObjTiles(w->unk_00);
    ReleaseObjPalette(w->unk_14);
#ifdef VERSION_EU
    func_08065AE0(w->unk_18, 60);
#else
    func_08065AE0(w->unk_18, 40);
#endif
    gUnk_02039BA0->unk_70 &= ~0x80;
    gUnk_02039BA0->unk_70 &= ~0x1000;
}

