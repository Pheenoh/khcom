#include "macros.h"
#include "unk_080dfebc.h"

INCLUDE_ASM("unk_080dfebc/func_080DFEBC.s");

s32 func_080DFF1C(UnkStruct_080DFF1C* p) {
    return func_080DFEBC(p->unk_00, p->unk_04 + p->unk_0C, p->unk_0C);
}

s32 func_080DFF30(UnkStruct_080DFF1C* p) {
    return func_080DFEBC(p->unk_00, p->unk_04 + p->unk_08, -0x100000);
}

void func_080DFF4C(UnkStruct_080DFF1C* p) {
    p->unk_0C = func_080DFF30(p);
}

void func_080DFF5C(UnkStruct_080DFF1C* p, s16 x, s16 y, u8 a, u8 b) {
    p->unk_00 = (x << 13) + (a << 12);
    p->unk_04 = (y << 12) + (b << 11);
    p->unk_08 = 0;
    p->unk_08 = p->unk_0C = func_080DFF30(p);
    p->unk_04 -= p->unk_0C;
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
    func_080E524C(p, &p->unk_04);
    p->unk_08 = 0;
    p->unk_08 = p->unk_0C = func_080DFF30(p);
    p->unk_04 -= p->unk_0C;
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

INCLUDE_ASM("unk_080dfebc/func_080E00E4.s");

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

    if (gUnk_0203C7AC->unk_28 - 0x1400 > p->unk_04 + (a << 8)) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_28 + 0x1400 < p->unk_04 - (a << 8)) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_2C - 0x2000 > p->unk_08) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_2C + 0x800 < p->unk_08 - (b << 8)) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_2C <= p->unk_0C) {
        return 1;
    }
    return 0;
}

u8 func_080E0378(void) {
    return func_080DF548(gUnk_0203C590[6]);
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

INCLUDE_ASM("unk_080dfebc/func_080E042C.s");

void func_080E04EC(void) {
    switch (gUnk_0203C590[6]) {
        case 0xFC:
        case 0xFD:
        case 0xFE:
            func_080010CC(&gUnk_09EF6AC0, 0);
            break;
        default:
            if (gUnk_0203C590[4] != 13) {
                func_080010CC(&gUnk_09EF6AA0, 0);
            } else {
                func_080010CC(&gUnk_09EF3C88, 1);
            }
            break;
    }
}

void func_080E052C(u8 a) {
    if (a != 1) {
        gUnk_02039BB0.unk_0F = 0xFF;
        m4aMPlayVolumeControl(&gUnk_0203DB10, 0xFF, 0x100);
    }
    func_080E04EC();
}

INCLUDE_ASM("unk_080dfebc/func_080E0558.s");

void func_080E05E4(void) {
    func_080DF6D0(gUnk_0203C7AC, gUnk_0203C590[6]);
    if (gUnk_0203C7AC->unk_0D == 5) {
        gUnk_02039BA0->unk_70 |= 0x200;
    }
    TaskCreate(gUnk_02039BA0->unk_78, &gUnk_09EF6B00, 0);
}

INCLUDE_ASM("unk_080dfebc/func_080E062C.s");
INCLUDE_ASM("unk_080dfebc/func_080E0780.s");

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

INCLUDE_ASM("unk_080dfebc/func_080E0920.s");

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

INCLUDE_ASM("unk_080dfebc/func_080E0A70.s");
INCLUDE_ASM("unk_080dfebc/sub_080E0B00.s");

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

INCLUDE_ASM("unk_080dfebc/func_080E0C1C.s");
INCLUDE_ASM("unk_080dfebc/func_080E1194.s");
INCLUDE_ASM("unk_080dfebc/func_080E1204.s");

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

INCLUDE_ASM("unk_080dfebc/func_080E1D08.s");
INCLUDE_ASM("unk_080dfebc/func_080E2668.s");
INCLUDE_ASM("unk_080dfebc/func_080E2B08.s");

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

INCLUDE_ASM("unk_080dfebc/func_080E2C50.s");

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

INCLUDE_ASM("unk_080dfebc/func_080E309C.s");
INCLUDE_ASM("unk_080dfebc/func_080E3400.s");
INCLUDE_ASM("unk_080dfebc/func_080E3768.s");
INCLUDE_ASM("unk_080dfebc/func_080E3C1C.s");
INCLUDE_ASM("unk_080dfebc/func_080E3CD4.s");
INCLUDE_ASM("unk_080dfebc/func_080E3D80.s");
INCLUDE_ASM("unk_080dfebc/func_080E3EFC.s");
INCLUDE_ASM("unk_080dfebc/func_080E3FD4.s");
INCLUDE_ASM("unk_080dfebc/func_080E4244.s");
INCLUDE_ASM("unk_080dfebc/func_080E47E8.s");
INCLUDE_ASM("unk_080dfebc/func_080E4900.s");
INCLUDE_ASM("unk_080dfebc/func_080E4B78.s");
INCLUDE_ASM("unk_080dfebc/func_080E4D68.s");
INCLUDE_ASM("unk_080dfebc/func_080E4EB0.s");

void func_080E4FF0(void* p, s16 a, s16 b) {
    void* q = (u8*)p + 0x40;
    void* r = (u8*)p + 0x80;

    func_080E4EB0(p, q, r, a, b);
    func_080045AC(p, GetBgScreenBase(3), a, b, 1);
    func_080045AC(q, GetBgScreenBase(2), a, b, 1);
    func_080045AC(r, GetBgScreenBase(1), a, b, 1);
}

INCLUDE_ASM("unk_080dfebc/func_080E507C.s");

void func_080E51C0(void* p, s16 a, s16 b) {
    void* q = (u8*)p + 0x40;
    void* r = (u8*)p + 0x80;

    func_080E507C(p, q, r, a, b);
    func_080045AC(p, GetBgScreenBase(3), a, b, 0);
    func_080045AC(q, GetBgScreenBase(2), a, b, 0);
    func_080045AC(r, GetBgScreenBase(1), a, b, 0);
}

INCLUDE_ASM("unk_080dfebc/func_080E524C.s");
INCLUDE_ASM("unk_080dfebc/func_080E5354.s");

UnkStruct_080DFB8C* func_080E548C(s16 a, s16 b) {
    return func_080E08BC(a, b);
}

UnkStruct_02034F20* func_080E54A0(u8 a) {
    return &gUnk_02034F20[a];
}

s32* func_080E54B8(u8 a) {
    if (gUnk_02039BB0.unk_08 & 8) {
        return gUnk_09EF70D0[gUnk_0203C590[4]]->unk_34 + a;
    }
    return gUnk_09EF70D0[gUnk_0203C590[4]]->unk_30 + a;
}

INCLUDE_ASM("unk_080dfebc/func_080E5504.s");

void func_080E5510(u8 a) {
    if (a != 0x10) {
        gUnk_0203C7B0 = gUnk_0984D1F4[a];
    } else {
        gUnk_0203C7B0 = gUnk_0984D1F4[GetRandom() % 15];
    }
}

INCLUDE_ASM("unk_080dfebc/func_080E5564.s");

UnkStruct_02034F24* func_080E5590(u8 a) {
    return &gUnk_02034F24[a];
}

s32 func_080E55A4(s16 x, s16 y) {
    if (y < 0 || y >= gUnk_0203C7AC->unk_06 || x < 0 || x >= gUnk_0203C7AC->unk_04) {
        return 0;
    }
    return (s32)(gUnk_02034F38 + (gUnk_0203C7AC->unk_04 * y + x) * 32);
}

INCLUDE_ASM("unk_080dfebc/func_080E55E4.s");
INCLUDE_ASM("unk_080dfebc/func_080E56B4.s");
INCLUDE_ASM("unk_080dfebc/func_080E5800.s");

s32 func_080E58F8(s16 a, s16 b) {
    return func_080E55A4(a, b);
}

void func_080E590C(UnkStruct_080E590C* p) {
    UnkStruct_080DFF1C* q = &p->unk_08;
    s32 t;

    func_080E5354(q, &q->unk_04);
    q->unk_08 = 0;
    t = func_080DFF30(q);
    q->unk_0C = t;
    q->unk_04 -= t;
    q->unk_08 = t;
}

void func_080E5938(UnkStruct_080E590C* p) {
    UnkStruct_080DFF1C* q = &p->unk_08;
    s32 t;

    func_080E5354(q, &q->unk_04);
    q->unk_08 = 0;
    t = func_080DFF30(q);
    q->unk_0C = t;
    q->unk_04 -= t;
    q->unk_08 = -0xA000;
}

s32 func_080E5968(UnkStruct_080E590C* p) {
    UnkStruct_080DFF1C* q = &p->unk_08;
    s32 t;
    s32 i;

    if (func_080E524C(q, &q->unk_04) != 0) {
        q->unk_08 = 0;
        t = func_080DFF30(q);
        q->unk_0C = t;
        q->unk_08 = t;
        q->unk_04 -= t;
        for (i = 0; i < gUnk_02034F40; i++) {
            if (gUnk_02034F48[i].unk_00 >> 8 == q->unk_00 >> 8 && gUnk_02034F48[i].unk_04 >> 8 == q->unk_04 >> 8) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

INCLUDE_ASM("unk_080dfebc/func_080E59D8.s");
INCLUDE_ASM("unk_080dfebc/func_080E5AC8.s");
INCLUDE_ASM("unk_080dfebc/func_080E5B90.s");
INCLUDE_ASM("unk_080dfebc/func_080E5C00.s");
INCLUDE_ASM("unk_080dfebc/func_080E5CD4.s");
INCLUDE_ASM("unk_080dfebc/func_080E5D6C.s");

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
    p->unk_C4 = AnimUpdate(p->unk_A4);
}

u8 func_080E5E44(void) {
    const u8* q = gUnk_0984D134[gUnk_0203C7AC->unk_0D];
    u8 v = q[3] + GetRandom() % (q[4] - q[3] + 1);

    if (gUnk_02039BB0.unk_08 & 8) {
        return v + gUnk_09EF6A42[gUnk_0203C590[4]];
    }
    return v + gUnk_09EF6A34[gUnk_0203C590[4]];
}

INCLUDE_ASM("unk_080dfebc/func_080E5EAC.s");

void func_080E5F50(UnkStruct_080E590C* p) {
    if (p->unk_74 != 0) {
        if ((gUnk_0203C7AC->unk_00 & 4) == 0 && func_08012660(p->unk_48, 1)) {
            func_080E5EAC(p);
            return;
        }

        if (func_08012660(p->unk_48, 6)) {
            p->unk_08.unk_00 += p->unk_80;
            p->unk_08.unk_04 += p->unk_84;
        }
    }
}

s32 func_080E5FB4(UnkStruct_080E590C* p) {
    if (func_080E02E0(&p->unk_08, p->unk_C8 / 2, p->unk_CA / 2)) {
        gUnk_0203C7AC->unk_00 |= 0x80;
        gUnk_0203C7AC->unk_00 |= 4;
        TaskCreate(p->unk_E4, &gUnk_09EF6EC4, &p->unk_08);
        if (gUnk_02039BB0.unk_08 & 8) {
            m4aSongNumStart(0xE4);
        } else {
            m4aSongNumStart(0x75);
        }
        return 1;
    }
    return 0;
}

INCLUDE_ASM("unk_080dfebc/func_080E6034.s");
INCLUDE_ASM("unk_080dfebc/func_080E607C.s");

void func_080E6100(void) {
    u8 w[0x20];
    s32 i;
    s32 r;

    switch (gUnk_0203C7AC->unk_0D) {
        case 3:
            func_080E5C00(w, 3, 3);
            func_080E5C00(w, 2, 2);
            break;
        case 5:
            for (i = 2; i >= 0; i--) {
                if (gUnk_0203C590[4] == 2) {
                    func_080E5C00(w, 4, 0);
                } else {
                    r = GetRandom();
                    if (r & 1) {
                        func_080E5C00(w, 0, 0);
                    } else {
                        func_080E5C00(w, 1, 0);
                    }
                }
            }
            break;
    }
}

INCLUDE_ASM("unk_080dfebc/func_080E6178.s");
INCLUDE_ASM("unk_080dfebc/func_080E6264.s");
INCLUDE_ASM("unk_080dfebc/func_080E6394.s");
INCLUDE_ASM("unk_080dfebc/func_080E64D4.s");
INCLUDE_ASM("unk_080dfebc/func_080E657C.s");
INCLUDE_ASM("unk_080dfebc/func_080E6634.s");

UnkStruct_080DFB8C* func_080E67D4(s32 x, s32 y) {
    u16 a = x / 0x2000;
    u16 b = y / 0x1000;
    return func_080E548C(a, b);
}

INCLUDE_ASM("unk_080dfebc/func_080E6804.s");

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

INCLUDE_ASM("unk_080dfebc/func_080E6998.s");

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

INCLUDE_ASM("unk_080dfebc/func_080E6A80.s");
INCLUDE_ASM("unk_080dfebc/func_080E6B24.s");

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

INCLUDE_ASM("unk_080dfebc/func_080E7E3C.s");

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

INCLUDE_ASM("unk_080dfebc/func_080E8058.s");
INCLUDE_ASM("unk_080dfebc/func_080E80E0.s");
INCLUDE_ASM("unk_080dfebc/func_080E826C.s");

u8 func_080E8374(UnkStruct_080E8374* p) {
    s32 lim = gUnk_02039BA0->unk_1C + gUnk_02039BA0->unk_20 + 0x4000 + (p->unk_1A << 8);

    if (p->unk_00 < gUnk_02039BA0->unk_00 || p->unk_00 > gUnk_02039BA0->unk_00 + 0xF000 ||
        p->unk_04 + p->unk_08 < gUnk_02039BA0->unk_04 || p->unk_04 + p->unk_08 > lim) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("unk_080dfebc/func_080E83C4.s");
INCLUDE_ASM("unk_080dfebc/func_080E83DC.s");

void func_080E84DC(UnkStruct_080DFF1C* p) {
    u16 r = GetRandom() % 10000;

    if (r <= 0x5DB) {
        if (func_080E8FB8(0, p->unk_00, p->unk_04, p->unk_08) != 1) {
            func_080E83DC(p->unk_00, p->unk_04, p->unk_08);
        }
    } else if (r <= 0x1D4B) {
        func_080E83DC(p->unk_00, p->unk_04, p->unk_08);
    }
}

INCLUDE_ASM("unk_080dfebc/func_080E853C.s");
INCLUDE_ASM("unk_080dfebc/func_080E8594.s");

void func_080E8624(void) {
    if (gUnk_02039BB0.unk_00 == 0) {
        EwramFree(gUnk_0203C7B8);
    }
}

u8* func_080E8644(void* a, u16 b, u16 c) {
    u8* p = a;

    return gUnk_0984B860[p[(u8)(b >> 3) + (u8)(c >> 3) * 4]];
}

INCLUDE_ASM("unk_080dfebc/func_080E8668.s");

#ifdef NON_MATCHING

u8 func_080E86C8(UnkStruct_080DFB8C* p, s32 x, s32 y) {
    u16 cx;
    u16 cy;
    u8* t;

    if (p == 0) {
        return 1;
    }
    cx = (x >> 8) % 32;
    cy = (y >> 8) % 16;
    t = func_080E8644(p->unk_10, cx, cy);
    return (t[cy & 7] >> (7 - (cx & 7))) & 1;
}

#else

INCLUDE_ASM("unk_080dfebc/func_080E86C8.s");

#endif

INCLUDE_ASM("unk_080dfebc/func_080E8724.s");
INCLUDE_ASM("unk_080dfebc/func_080E87EC.s");
INCLUDE_ASM("unk_080dfebc/func_080E8864.s");

void func_080E891C(UnkStruct_080E8864* p) {
    if (p != 0) {
        while (p->unk_00 != 0) {
            func_080E8864(p);
            p++;
        }
    }
}

INCLUDE_ASM("unk_080dfebc/func_080E893C.s");

s32 func_080E89E4(s16 x, s16 y, const u8* p) {
    while (p[0] != 0xFF) {
        if (func_080E548C(p[0] + x, p[1] + y)->unk_05 != p[2]) {
            return 0;
        }
        p += 4;
    }
    return 1;
}

INCLUDE_ASM("unk_080dfebc/func_080E8A24.s");

void func_080E8AC8(UnkStruct_080E8864* p) {
    if (p != 0) {
        while (p->unk_00 != 0) {
            func_080E8A24(p);
            p++;
        }
    }
}

void func_080E8AE8(void) {
    if (gUnk_02039BB0.unk_00 == 0) {
        UnkStruct_09EF70D0* p = gUnk_09EF70D0[gUnk_0203C590[4]];

        func_080E891C(p->unk_24);
        func_080E8AC8(p->unk_28);
    }
}

INCLUDE_ASM("unk_080dfebc/func_080E8B1C.s");

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

INCLUDE_ASM("unk_080dfebc/func_080E8D64.s");

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

INCLUDE_ASM("unk_080dfebc/func_080E8E74.s");

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
        TaskCreate(gUnk_02039BA0->unk_C8, &gUnk_09EF6E64, &w);
        return 1;
    }
    return 0;
}

u8 func_080E8FB8(u8 a, s32 b, s32 c, s32 d) {
    UnkStruct_080E8E24* q;

    if (gUnk_02039BB0.unk_08 & 8) {
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

    if (func_080DEE18(gUnk_0203C590[6])->unk_0C == 0) {
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
        TaskCreate(gUnk_02039BA0->unk_A0, &gUnk_09EF6E4C, &w);
    }
}

INCLUDE_ASM("unk_080dfebc/func_080E9078.s");

void func_080E92B8(UnkStruct_080E92B8* p) {
    s32 i;
    u32* src;
    u32* dst;

    p->unk_00 = gUnk_02039BB0.unk_0C;
    p->unk_01 = gUnk_02039BB0.unk_0E;
    memcpy(p->unk_04, gUnk_0203C590, 0x21C);
    src = gUnk_02039BB0.unk_184.unk_00;
    dst = p->unk_220.unk_00;
    for (i = 12; i >= 0; i--) {
        *dst++ = *src++;
    }
}

void func_080E92F8(UnkStruct_080E92B8* p) {
    s32 i;
    u32* src;
    u32* dst;

    gUnk_02039BB0.unk_0C = p->unk_00;
    gUnk_02039BB0.unk_0E = p->unk_01;
    memcpy(gUnk_0203C590, p->unk_04, 0x21C);
    src = p->unk_220.unk_00;
    dst = gUnk_02039BB0.unk_184.unk_00;
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

INCLUDE_ASM("unk_080dfebc/func_080E935C.s");

void func_080E988C(s32 a) {
    gUnk_02034FB0 = a;
}

void func_080E9898(s32 a) {
    func_080E988C(a);
    ((void (*)(void))gUnk_02034FB0)();
}

INCLUDE_ASM("unk_080dfebc/func_080E98B0.s");

void func_080E9A00(void) {
    if (gUnk_02034FB8 != 0) {
        func_08000DE8(gUnk_02039BA0->unk_78, gUnk_02034FB8);
        gUnk_02034FB8 = 0;
    }
}

INCLUDE_ASM("unk_080dfebc/func_080E9A28.s");

void func_080EA1E8(s32 a) {
    gUnk_02034FD4 = a;
}

void func_080EA1F4(s32 a) {
    func_080EA1E8(a);
    ((void (*)(void))gUnk_02034FD4)();
}

INCLUDE_ASM("unk_080dfebc/func_080EA20C.s");
INCLUDE_ASM("unk_080dfebc/func_080EAB20.s");
INCLUDE_ASM("unk_080dfebc/func_080EABB8.s");
INCLUDE_ASM("unk_080dfebc/func_080EAC60.s");

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

INCLUDE_ASM("unk_080dfebc/func_080EAD84.s");
INCLUDE_ASM("unk_080dfebc/func_080EAEB0.s");

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

INCLUDE_ASM("unk_080dfebc/func_080EB898.s");
INCLUDE_ASM("unk_080dfebc/func_080EBA58.s");
INCLUDE_ASM("unk_080dfebc/func_080EBAE0.s");

void func_080ECA88(UnkStruct_080ECA88* p) {
    func_080038E4(p->unk_44, p->unk_4C, p->unk_54);
    func_080038E4(p->unk_58, p->unk_60, p->unk_64);
}

INCLUDE_ASM("unk_080dfebc/func_080ECAA8.s");

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

INCLUDE_ASM("unk_080dfebc/func_080ED14C.s");
INCLUDE_ASM("unk_080dfebc/func_080ED250.s");
INCLUDE_ASM("unk_080dfebc/func_080ED314.s");

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

void func_080EE5E0(u8 a) {
    const u8* src;

    if (gUnk_02039BB0.unk_08 & 8) {
        src = gUnk_09963D64[a];
    } else {
        src = gUnk_09961A64[a];
    }
    RequestDma3Copy((void*)src, (u8*)GetBgCharBase(0) + 320, 320);
}

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

INCLUDE_ASM("unk_080dfebc/func_080EE6AC.s");
INCLUDE_ASM("unk_080dfebc/func_080EE760.s");
INCLUDE_ASM("unk_080dfebc/func_080EE7B0.s");

s32 func_080EF3A0(UnkStruct_080E590C* p) {
    UnkStruct_080DFF1C* q = &p->unk_08;

    if (p->unk_08.unk_00 < gUnk_02039BA0->unk_00 - 0x1800 || p->unk_08.unk_00 > gUnk_02039BA0->unk_00 + 0x10800 ||
        q->unk_04 + q->unk_08 < gUnk_02039BA0->unk_04 - 0x800 || q->unk_04 + q->unk_08 > gUnk_02039BA0->unk_04 + 0xC000) {
        p->unk_CC = 0;
        func_08012614(p->unk_48, 1);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("unk_080dfebc/func_080EF404.s");
INCLUDE_ASM("unk_080dfebc/func_080EF478.s");

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

INCLUDE_ASM("unk_080dfebc/func_080EF508.s");
INCLUDE_ASM("unk_080dfebc/func_080EF84C.s");
INCLUDE_ASM("unk_080dfebc/func_080EFA7C.s");
INCLUDE_ASM("unk_080dfebc/func_080EFB24.s");
INCLUDE_ASM("unk_080dfebc/func_080EFC08.s");
INCLUDE_ASM("unk_080dfebc/func_080F0108.s");
INCLUDE_ASM("unk_080dfebc/func_080F01B0.s");

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

INCLUDE_ASM("unk_080dfebc/func_080F02A0.s");
INCLUDE_ASM("unk_080dfebc/func_080F0660.s");

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

INCLUDE_ASM("unk_080dfebc/func_080F07EC.s");

void func_080F3D58(UnkStruct_080DFF1C* p) {
    u16 r;

    if (gUnk_02039BB0.unk_08 & 8) {
        r = GetRandom() % 10000;
        if (r < 6000) {
            func_080E9034(0, 5, p->unk_00, p->unk_04, p->unk_08);
        } else if (r < 10000) {
            func_080E9034(1, 3, p->unk_00, p->unk_04, p->unk_08);
        }
    } else {
        r = GetRandom() % 10000;
        if (r < 3000) {
            func_080E9034(0, 5, p->unk_00, p->unk_04, p->unk_08);
        } else if (r < 5000) {
            func_080E9034(1, 3, p->unk_00, p->unk_04, p->unk_08);
        } else if (r < 8000) {
            func_080E9034(2, 5, p->unk_00, p->unk_04, p->unk_08);
        } else {
            func_080E9034(3, 5, p->unk_00, p->unk_04, p->unk_08);
        }
    }
}

INCLUDE_ASM("unk_080dfebc/func_080F3E24.s");
INCLUDE_ASM("unk_080dfebc/func_080F4EE4.s");
INCLUDE_ASM("unk_080dfebc/func_080F4F60.s");

s32 func_080F7488(UnkStruct_080DFF1C* p, s32 lim) {
    s32 dx;
    s32 dy;

    dx = p->unk_00 - gUnk_02039BA0->unk_18;
    if (dx < 0) {
        dx = gUnk_02039BA0->unk_18 - p->unk_00;
    }
    dy = p->unk_04 - gUnk_02039BA0->unk_1C;
    if (dy < 0) {
        dy = gUnk_02039BA0->unk_1C - p->unk_04;
    }

    if (dx > 0x8000 || dy > 0x8000) {
        return 0;
    }
    return func_08003C9C((dx * dx >> 8) + (dy * dy >> 8)) < lim ? 1 : 0;
}

INCLUDE_ASM("unk_080dfebc/func_080F74E8.s");
