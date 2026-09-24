#include "macros.h"
#include "map.h"

UnkStruct_0203C7AC* gUnk_0203C7AC EWRAM_COMMON(4);
UnkStruct_0203C7B0 gUnk_0203C7B0 EWRAM_COMMON(8);
struct UnkStruct_0203C7B8* gUnk_0203C7B8 EWRAM_COMMON(4);

MapCell* gMapCells;
UnkStruct_02034F20* gUnk_02034F20;
UnkStruct_02034F24* gUnk_02034F24;
u16 gUnk_02034F28;
u16 gUnk_02034F2A;
u16 gUnk_02034F2C;
u16 gUnk_02034F2E;
void* gUnk_02034F30;
UnkStruct_09EF70D0* gUnk_02034F34;
u8* gUnk_02034F38;
#ifndef VERSION_EU
u8 gUnk_02034F3C[4];
#endif

s32 func_080DFEBC(s32 x, s32 y, s32 z) {
    MapCell* p = func_080DFB8C(x, y);
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
    return func_080DFEBC(p->x, p->y + p->unk_0C, p->unk_0C);
}

s32 func_080DFF30(UnkStruct_080DFF1C* p) {
    return func_080DFEBC(p->x, p->y + p->z, -0x100000);
}

void func_080DFF4C(UnkStruct_080DFF1C* p) {
    p->unk_0C = func_080DFF30(p);
}

void func_080DFF5C(UnkStruct_080DFF1C* p, s16 x, s16 y, u8 a, u8 b) {
    p->x = (x << 13) + (a << 12);
    p->y = (y << 12) + (b << 11);
    p->z = 0;
    p->z = p->unk_0C = func_080DFF30(p);
    p->y -= p->unk_0C;
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
    func_080E524C(p, &p->y);
    p->z = 0;
    p->z = p->unk_0C = func_080DFF30(p);
    p->y -= p->unk_0C;
}

s32 func_080E0010(s32 x) {
    s32 lim;

    x -= 0x7800;
    lim = (gFieldState->unk_10 << 11) - 0xF000;

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
    lim = (gFieldState->unk_12 << 11) - 0xA000;

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

    gFieldState->x = func_080E0010(gFieldState->x2);
    gFieldState->y = func_080E0044(gFieldState->y2);
    sx = gFieldState->x >> 8;
    sy = gFieldState->y >> 8;
    func_080E4B78(sx / 8, sy / 8);
    SetBgScroll(3, (u16)sx, (u16)sy);
    SetBgScroll(2, (u16)sx, (u16)sy);
    SetBgScroll(1, (u16)sx, (u16)sy);
}

void func_080E00E4(s32 a, s32 b) {
    s32 x;
    s32 y;
    s32 dx;
    s32 dy;
    s16 sx;
    s16 sy;
    u8* p;

    if ((gFieldState->flags & 0x40000) == 0) {
        x = func_080E0010(a);
        y = func_080E0044(b);
    } else {
        x = a - 0x7800;
        y = b - 0x6000;
    }

    dx = (x - gFieldState->x) >> 3;

    if (dx > 0x800) {
        dx = 0x800;
    } else if (dx < -0x800) {
        dx = -0x800;
    }

    dy = (y - gFieldState->y) >> 3;

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

    gFieldState->x += dx;
    gFieldState->y += dy;
    sx = gFieldState->x / 0x800;
    sy = gFieldState->y / 0x800;
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

    SetBgScroll(3, (u16)(gFieldState->x >> 8), (u16)(gFieldState->y >> 8));
    SetBgScroll(2, (u16)(gFieldState->x >> 8), (u16)(gFieldState->y >> 8));

    if (!(gUnk_0203C7AC->flags & 1)) {
        SetBgScroll(1, (u16)(gFieldState->x >> 8), (u16)(gFieldState->y >> 8));
    }
}

void func_080E0298(s32 x, s32 y) {
    gFieldState->x2 = x;
    gFieldState->y2 = y;
}

void func_080E02A8(s32 dx, s32 dy) {
    gFieldState->x2 += dx;
    gFieldState->y2 += dy;
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

    if (gUnk_0203C7AC->flags & 0x80) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_24 - 0x1400 > p->x + (a << 8)) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_24 + 0x1400 < p->x - (a << 8)) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_28 - 0x1400 > p->y + (a << 8)) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_28 + 0x1400 < p->y - (a << 8)) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_2C - 0x2000 > p->z) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_2C + 0x800 < p->z - (b << 8)) {
        return 0;
    }

    if (gUnk_0203C7AC->unk_2C <= p->unk_0C) {
        return 1;
    }
    return 0;
}

u8 func_080E0378(void) {
    return func_080DF548(gUnk_0203C590.unk_06);
}

s32 func_080E0390(void) {
    if ((gFieldState->flags & 0x42000) || (gUnk_0203C7AC->flags & 0x2000)) {
        return 1;
    }
    return 0;
}

s32 func_080E03C0(s32 a) {
    if (func_080A42C8()) {
        return 0;
    }

    if (gFieldState->flags & 0x841000) {
        return 0;
    }

    if (gUnk_0203C7AC->flags & 0x84) {
        return 0;
    }

    if (gFieldState->actor.fieldPosition.z != gFieldState->actor.fieldPosition.unk_0C) {
        return 0;
    }
    return gFieldState->unk_68 == a;
}

void func_080E0418(void) {
    gUnk_0203C7AC->flags |= 1;
}

void func_080E042C(void) {
    UnkStruct_09EF8370* p;
    UnkStruct_09EF70D0* q;
    s16 x;
    s16 y;

    if ((s32)gUnk_0203C7AC->flags < 0) {
        p = gUnk_09EF8370[4];
        LoadBgTiles(1, p->tiles2, p->tilesSize2);
        LoadBgPalette(1, p->palette, p->paletteSize);
        SetBgMapBlocks(1, p->map, p->mapWidth, p->mapHeight);
        gUnk_0203C7AC->flags &= ~1;
    } else {
        q = gUnk_09EF70D0[gUnk_0203C590.unk_04];
        LoadBgTiles(1, q->tiles2, q->tilesSize2);
        LoadBgPalette(1, q->palette, q->paletteSize);
        x = gFieldState->x >> 8;
        y = gFieldState->y >> 8;
        func_080E4D68(x / 8, y / 8);
        SetBgScroll(1, (u16)x, (u16)y);
        gUnk_0203C7AC->flags &= ~1;
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
        gGameState.unk_00F = 0xFF;
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFF, 0x100);
    }
    func_080E04EC();
}

void func_080E0558(void) {
    gFieldState->x = 0;
    gFieldState->y = 0;
    gFieldState->x2 = 0;
    gFieldState->y2 = 0;
    gFieldState->unk_10 = 32;
    gFieldState->unk_12 = 32;
    gFieldState->unk_68 = 0;
    gFieldState->unk_6C = 60;
    gFieldState->flags = 0;
    gFieldState->unk_74 = 0;
    TaskPoolInit(gFieldState->tasks, 50);
    TaskPoolInit(gFieldState->tasks2, 1);
    ListPoolInit(&gFieldState->actor.pool);
    TaskPoolInit(gFieldState->tasks3, 25);
    TaskPoolInit(gFieldState->tasks5, 1);
    TaskPoolInit(gFieldState->tasks4, 8);
    gUnk_0203C7AC->flags = 0;
    gUnk_0203C7AC->unk_18 = 0;
    gUnk_0203C7AC->unk_1C = 0;
    gUnk_0203C7AC->unk_20 = 0;
    TaskPoolInit(gUnk_0203C7AC->tasks, 1);
}

void func_080E05E4(void) {
    func_080DF6D0(gUnk_0203C7AC, gUnk_0203C590.unk_06);

    if (gUnk_0203C7AC->unk_0D == 5) {
        gFieldState->flags |= 0x200;
    }
    TaskCreate(gFieldState->tasks, &gTaskDescMapRnd, 0);
}

void func_080E062C(void) {
    UnkStruct_080DFB7C* e;
    s32 x;
    s32 y;

    if (gUnk_0203C590.unk_07 <= 3) {
        e = (UnkStruct_080DFB7C*)func_080DFB7C(gUnk_0203C590.unk_07);
        x = (e->unk_02 << 5) + 16;
        y = (e->unk_04 << 4) + 10;

        switch (gUnk_0203C590.unk_07) {
        case 0:
            gFieldState->unk_DC = (x << 8) - 0xC00;
            gFieldState->unk_E0 = (y << 8) + 0x800;
            gFieldState->unk_E4 = 0xAD;
            break;
        case 1:
            gFieldState->unk_DC = (x << 8) + 0xC00;
            gFieldState->unk_E0 = (y << 8) - 0x800;
            gFieldState->unk_E4 = 0x2D;
            break;
        case 2:
            gFieldState->unk_DC = (x << 8) - 0xC00;
            gFieldState->unk_E0 = (y << 8) - 0x800;
            gFieldState->unk_E4 = 0xD3;
            break;
        case 3:
            gFieldState->unk_DC = (x << 8) + 0xC00;
            gFieldState->unk_E0 = (y << 8) + 0x800;
            gFieldState->unk_E4 = 0x53;
            break;
        }
    } else {
        func_080E524C((UnkStruct_080DFF1C*)&gFieldState->unk_DC, &gFieldState->unk_E0);
        gFieldState->unk_E4 = 0x80;
    }

    if (gGameState.flags & 8) {
        TaskCreate(gFieldState->tasks2, &gTaskDescFldRiku, 0);
    } else {
        TaskCreate(gFieldState->tasks2, &gTaskDescFldSora, 0);
    }
}

void func_080E0780(void) {
    if (gFieldState->unk_6C > 0) {
        gFieldState->flags |= 1;
        gFieldState->unk_6C--;
    } else {
        gFieldState->flags &= ~1;
    }
    gUnk_0203C7AC->unk_1C = 0;
    TaskPoolUpdate(gFieldState->tasks);
    gUnk_0203C7AC->unk_20 = 0;

    if ((gFieldState->flags & 0x1000) == 0 && (gUnk_0203C7AC->flags & 4) == 0) {
        TaskPoolUpdate(gFieldState->tasks2);
    }
    if ((gFieldState->flags & 0x80) == 0) {
        TaskPoolUpdate(gFieldState->tasks4);
    }
    TaskPoolUpdate(gFieldState->tasks3);
    TaskPoolUpdate(gFieldState->tasks5);
}

void func_080E0820(void) {
    TaskPoolDraw(gFieldState->tasks);

    if ((gUnk_0203C7AC->flags & 0x1000) == 0) {
        TaskPoolDraw(gFieldState->tasks2);
    }

    if ((gFieldState->flags & 0x100) == 0) {
        TaskPoolDraw(gFieldState->tasks4);
    }
    TaskPoolDraw(gFieldState->tasks3);
    TaskPoolDraw(gFieldState->tasks5);
}

void func_080E0878(void) {
    TaskPoolDestroy(gFieldState->tasks);
    TaskPoolDestroy(gFieldState->tasks2);
    TaskPoolDestroy(gFieldState->tasks3);
    TaskPoolDestroy(gFieldState->tasks5);
    TaskPoolDestroy(gFieldState->tasks4);
    TaskPoolDestroy(gUnk_0203C7AC->tasks);
}

MapCell* func_080E08BC(s16 x, s16 y) {
    if (y < 0 || y >= gUnk_02034F2A) {
        return 0;
    }

    if (x < 0 || x >= gUnk_02034F28) {
        return 0;
    }
    return &gMapCells[gUnk_02034F28 * y + x];
}

void func_080E0900(MapCell* p, s32 a, s32 b) {
    if (p != 0) {
        p->unk_02 = a;
        p->unk_10 = func_080E8668(a);
        p->unk_08 = b;
    }
}

u8 func_080E0920(UnkStruct_080DFF1C* p, u16 a) {
    u16 d = (p->unk_0C - p->z) >> 8;

    return d > a * 16;
}

u8 func_080E0938(u8 a) {
    const u8* p = gUnk_0984D32C[a];
    return GetRandom() % p[3];
}

void func_080E0960(MapCell* p, s32 n) {
    if (p != 0) {
        u16* base = gUnk_02034F34->map3;
        const u8* q = gUnk_0984D314[n];
        u8 m = GetRandom() % q[3];
        s32 u = ((m & 7) + q[1]) * 4;
        s32 v = (m >> 3) + q[2];
        p->unk_03 = n;
        p->unk_14 = base + (v * 64 + u);
    }
}

void func_080E09B4(MapCell* p, u8 n, u8 v) {
    if (p != 0) {
        const u8* q = gUnk_0984D32C[n];
        u16* base;
        u16 t;

        switch (q[0]) {
        case 1:
            base = gUnk_02034F34->map2;
            break;
        case 0:
        default:
            base = gUnk_02034F34->map3;
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

void func_080E0A38(MapCell* p) {
    if (p->unk_00 & 1) {
        func_080E0960(p, 1);
    } else if (p->unk_00 & 2) {
        func_080E0960(p, 2);
    } else {
        func_080E0960(p, 0);
    }
}

void func_080E0A70(MapCell* p, s32 n) {
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
    base = gUnk_02034F34->map3;
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

void sub_080E0B00(MapCell* p, s32 n) {
    const u8* t;
    u16* base;
    u16 off;

    if (p == 0) {
        return;
    }
    t = gUnk_0984D32C[n];
    off = t[1] * 4 + t[2] * 64;
    base = gUnk_02034F34->map2;

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

void func_080E0B98(MapCell* p, s32 n, u8 v) {
    if (p != 0) {
        u16* base = gUnk_02034F34->map2;
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
    MapCell* p = func_080E08BC(x, y);

    func_080E0960(p, a);
    sub_080E0B00(p, b);
}

void func_080E0C1C(u16 x, u16 y) {
    MapCell* e;
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

void func_080E0ED4(UnkStruct_02034F20* p) {
    s32 go = 1;
    u16 x = p->x;
    u16 y = p->y;

    while (go) {
        s16 cy = (s16)y;
        MapCell* c = func_080E08BC((s16)x, cy);

        switch (c->unk_02) {
        case 4:
            func_080E08BC((s16)x, (s16)(y + 1))->unk_00 |= 0x40;
            func_080E08BC((s16)(x + 1), cy)->unk_00 |= 0x40;
            func_080E08BC((s16)(x + 1), (s16)(y + 1))->unk_00 |= 0x40;
            c->unk_00 |= 0x40;
            p->x = x + 1;
            p->y = y + 1;
            go = 0;
            break;
        case 6:
            func_080E08BC((s16)x, (s16)(y + 1))->unk_00 |= 0x40;
            func_080E08BC((s16)(x - 1), cy)->unk_00 |= 0x40;
            func_080E08BC((s16)(x - 1), (s16)(y + 1))->unk_00 |= 0x40;
            c->unk_00 |= 0x40;
            p->x = x;
            p->y = y + 1;
            go = 0;
            break;
        default:
            break;
        }
        y++;
    }
}

void func_080E0FD8(UnkStruct_02034F20* p) {
    u16 x;
    u16 y;
    u16 d;
    MapCell* e;
    MapCell* q;

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
                                p->x = x;
                                p->y = y - d;
                                p->unk_0E = q->unk_02;
                                p->unk_10 = q->unk_08;
                                p->unk_14 = q->unk_0C;
                            }
                        } else if (p->unk_08 == 0 && p->unk_10 <= q->unk_08 &&
                                   (p->unk_10 < q->unk_08 ||
                                    p->unk_00 + GetRandom() % (p->unk_02 - p->unk_00 + 1) > x)) {
                            p->x = x;
                            p->y = y - d;
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
            func_080E0C1C(e->x, e->y);
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
    MapCell* p;

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
            MapCell* c = func_080E08BC((s16)x, (s16)y);
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
            MapCell* a = func_080E08BC(x, y);
            MapCell* b = func_080E08BC(x + 1, y);
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
    MapCell* e;
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
    MapCell* p = func_080E08BC(x, y);
    if (p != 0) {
        u16* base = gUnk_02034F34->map;
        const u8* q = gUnk_0984D3F8[n];
        s32 t = q[1] * 4 + q[2] * 64;
        p->unk_05 = n;
        p->unk_1C = base + t;
    }
}

u8 func_080E1CA8(s16 x, s16 y) {
    MapCell* p = func_080E08BC(x, y);
    if (p == 0 || p->unk_08 == -0x100000 || p->unk_0C == 0x100000) {
        return 1;
    }
    return 0;
}

u8 func_080E1CE0(s16 x, s16 y, u8 n) {
    MapCell* p = func_080E08BC(x, y);

    if (p != 0 && p->unk_02 == n) {
        return 1;
    }
    return 0;
}

void func_080E1D08(s16 x, s16 y) {
    MapCell* p = func_080E08BC(x, y + 7);

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
    MapCell* p = func_080E08BC(x, y);

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
    MapCell* q = func_080E08BC(x, j);

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
    MapCell* p;

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
    UnkStruct_080DFB7C* e;
    MapCell* q;

    d = a;
    e = (UnkStruct_080DFB7C*)func_080DFB7C(d);

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
                    e->unk_02 = x;
                    e->unk_04 = y;
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
                    e->unk_02 = x;
                    e->unk_04 = y;
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
                    e->unk_02 = x;
                    e->unk_04 = y;
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
                    e->unk_02 = x;
                    e->unk_04 = y;
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

    switch (gUnk_0203C7AC->flags & 0x6000000) {
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

    switch (gUnk_0203C7AC->flags & 0x9000000) {
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
    MapCell* e;

    for (i = 0; i < 4; i++) {
        e = func_080DFB7C(i);
        e->unk_06[1] = func_080DEE28(gUnk_0203C590.unk_06, i);
        e->unk_06[0] = i;
        e->unk_00 = func_080DEE44(gUnk_0203C590.unk_06, i);

        if (e->unk_06[1] != 0xFF) {
            switch (i) {
            case 0:
                gUnk_0203C7AC->flags |= 0x1000000;
                break;
            case 1:
                gUnk_0203C7AC->flags |= 0x2000000;
                break;
            case 2:
                gUnk_0203C7AC->flags |= 0x4000000;
                break;
            case 3:
                gUnk_0203C7AC->flags |= 0x8000000;
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
    MapCell* q;
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
    MapCell* q;
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
    MapCell* q;
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
        s32 t = (u8)func_080E300C(i, x, y);

        if (t == 11) {
            if (y <= 3) {
                t = 6;
            } else if (i == 0) {
                if (e == 2) {
                    t = (u8)func_080E2F48(a, b, x, 1);
                } else if (e == 3) {
                    t = (u8)func_080E2F98(a, b, x, 1);
                } else {
                    t = (u8)func_080E2E24(a, b, x);
                }
            } else {
                t = (u8)func_080E2E24(a, b, x);
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
        s32 t = (u8)func_080E300C(i, x, y);

        if (t == 11) {
            if (y <= 3) {
                t = 4;
            } else if (i == 0) {
                if (e == 2) {
                    t = (u8)func_080E2F48(a, b, x, 1);
                } else if (e == 3) {
                    t = (u8)func_080E2F98(a, b, x, 1);
                } else {
                    t = (u8)func_080E2E24(a, b, x);
                }
            } else {
                t = (u8)func_080E2E24(a, b, x);
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
    yb = *(buf + b - a - 1) + (b - a);
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

void func_080E3C1C(s32 a, s16* px, s16* py, s16* pz, s16 lo, s16 hi) {
    s32 x = lo + GetRandom() % (hi - lo);
    s32 n;

    for (n = 0; n < -lo + hi; n++) {
        s32 j;

        for (j = gUnk_02034F2A - 1; j >= 0; j--) {
            MapCell* p = func_080E08BC(x, j);

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
void func_080E3CD4(s32 a, s16* px, s16* py, s16* pz, s16 e, s16 f) {
    s32 i;
    s32 j;
    s32 x;
    u16 n;
    MapCell* q;

    n = f - e;
    x = e + GetRandom() % (-e + f);

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
    MapCell* p;

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

void func_080E470C(void) {
    s16 a;
    s16 b;
    s16 c;
    s16 t;
    s16 d;
    s16 v;
    s32 k;

    t = (gUnk_02034F28 * 5) / 8;
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

    if (gGameState.unk_000 == 0) {
        gMapCells = EwramAlloc(0x18000);
        gUnk_02034F20 = EwramAlloc(0x120);
        gUnk_02034F24 = EwramAlloc(0x20);
        n = gUnk_02034F28 * gUnk_02034F2A;

        for (i = 0; i < n; i++) {
            gMapCells[i].unk_00 = 0;
            gMapCells[i].unk_02 = 11;
            gMapCells[i].unk_03 = 7;
            gMapCells[i].unk_04 = 0;
            gMapCells[i].unk_05 = 0;
            gMapCells[i].unk_14 = 0;
            gMapCells[i].unk_18 = 0;
            gMapCells[i].unk_1C = 0;
        }

        for (i = 0; i < 12; i++) {
            gUnk_02034F20[i].unk_00 = 0;
            gUnk_02034F20[i].unk_02 = 0;
            gUnk_02034F20[i].unk_04 = 0x100000;
            gUnk_02034F20[i].unk_08 = 0;
            gUnk_02034F20[i].x = 0;
            gUnk_02034F20[i].y = 0;
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

    if (gGameState.unk_000 == 0) {
        EwramFree(gMapCells);
        EwramFree(gUnk_02034F20);
        EwramFree(gUnk_02034F24);
    }
}

void func_080E4B78(s16 x, s16 y) {
    s16 x0;
    u16* p0;
    u16* p1;
    u16* p2;
    s16 yy;
    s32 i;

    p0 = gUnk_02034F30;
    p1 = (u16*)((u8*)gUnk_02034F30 + 0x800);
    p2 = (u16*)((u8*)gUnk_02034F30 + 0x1000);
    x0 = x - 1;
    yy = y - 1;

    for (i = 0; i < 32; i++) {
        s16 v;
        s16 m;
        s16 ya;
        s16 xx;
        s32 j;

        v = (yy < 0) ? (yy - 8) / 2 : yy / 2;

        m = yy % 2;
        ya = yy & 31;
        xx = x0;

        for (j = 0; j < 32; j++) {
            MapCell* e;
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
                p1[ya * 32 + xa] = gUnk_02034F34->map2[0x340];
                p2[ya * 32 + xa] = gUnk_02034F34->map[0x110];
            }

            xx++;
        }

        yy++;
    }

    RequestDma3Copy(p0, GetBgScreenBase(3), 0x800);
    RequestDma3Copy(p1, GetBgScreenBase(2), 0x800);
    RequestDma3Copy(p2, GetBgScreenBase(1), 0x800);
}

void func_080E4D68(s32 x, s32 y) {
    s16 x0;
    u16* dst;
    s16 yy;
    s32 i;

    dst = (u16*)((u8*)gUnk_02034F30 + 0x1000);
    x0 = x;
    x0--;
    yy = y;
    yy--;

    for (i = 0; i < 32; i++) {
        s16 v;
        s16 m;
        s16 ya;
        s16 xx;
        s32 j;

        v = (yy < 0) ? (yy - 8) / 2 : yy / 2;

        m = yy % 2;
        ya = yy & 31;
        xx = x0;

        for (j = 0; j < 32; j++) {
            MapCell* e;
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
                if (e->unk_1C != 0) {
                    dst[ya * 32 + xa] = e->unk_1C[m * 32 + n];
                } else {
                    dst[ya * 32 + xa] = 0;
                }
            } else {
                dst[ya * 32 + xa] = gUnk_02034F34->map[0x110];
            }

            xx++;
        }

        yy++;
    }

    RequestDma3Copy(dst, GetBgScreenBase(1), 0x800);
}

void func_080E4EB0(u16* a, u16* b, u16* c, s16 d, s16 e) {
    MapCell* cell;
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
            b[i] = gUnk_02034F34->map2[0x340];
            c[i] = gUnk_02034F34->map[0x110];
        }
        e++;
    }
}

void func_080E4FF0(void* p, s16 a, s16 b) {
    void* q = (u8*)p + 0x40;
    void* r = (u8*)p + 0x80;

    func_080E4EB0(p, q, r, a, b);
    RequestTilemapStripCopy(p, GetBgScreenBase(3), a, b, 1);
    RequestTilemapStripCopy(q, GetBgScreenBase(2), a, b, 1);
    RequestTilemapStripCopy(r, GetBgScreenBase(1), a, b, 1);
}

void func_080E507C(u16* a, u16* b, u16* c, s16 d, s16 e) {
    MapCell* cell;
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
            b[i] = gUnk_02034F34->map2[0x340];
            c[i] = gUnk_02034F34->map[0x110];
        }
        d++;
    }
}

void func_080E51C0(void* p, s16 a, s16 b) {
    void* q = (u8*)p + 0x40;
    void* r = (u8*)p + 0x80;

    func_080E507C(p, q, r, a, b);
    RequestTilemapStripCopy(p, GetBgScreenBase(3), a, b, 0);
    RequestTilemapStripCopy(q, GetBgScreenBase(2), a, b, 0);
    RequestTilemapStripCopy(r, GetBgScreenBase(1), a, b, 0);
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
                a->x = (x << 13) + 0x1000;
                *b = (yy << 12) + 0x800;
                return 1;
            }

            x++;
            x %= gUnk_02034F28;
        }

        y++;
        y %= h;
    }

    a->x = gFieldState->actor.fieldPosition.x;
    *b = gFieldState->actor.fieldPosition.y + gFieldState->actor.fieldPosition.unk_0C;
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
        s32 ty = (gFieldState->y / 16 >> 8) + 2;
        u16 yy = y + ty;

        for (i = 0; i < w; i++) {
            s32 tx = (gFieldState->x / 32 >> 8) + 1;
            u16 xx = x + tx;
            s32* q = &gFieldState->actor.fieldPosition.x;
            MapCell* e;

            if (q[0] < (xx * 32 + 80) << 8 && q[0] > (xx * 32 - 48) << 8 &&
                q[1] < (yy * 16 + 40) << 8 && q[1] > (yy * 16 - 24) << 8) {
                continue;
            }

            e = func_080E08BC(xx, yy);

            if (e != 0 && (*(u32*)e & 0xFF0340) == 0) {
                a->x = (xx << 13) + 0x1000;
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

MapCell* func_080E548C(s16 a, s16 b) {
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
            MapCell* e = (MapCell*)func_080E55A4(x, y);

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

void func_080E56B4(void* a) {
    UnkStruct_080E56B4* q = a;
    UnkStruct_0203C7B8* e;
    UnkStruct_080DFF1C v;
    s32 x;
    s32 n;

    if (q == 0) {
        return;
    }
    e = gUnk_0203C7B8;

    while (q->unk_00 != 0xFF) {
        v.x = q->unk_04;
        x = q->unk_08;
        v.y = v.z = v.unk_0C = 0;
        v.y = x;
        e->unk_00 = 2;
        n = q->unk_00;
        e->unk_14 = &gUnk_09856FB4[n];
        e->unk_04 = v;
        TaskCreate(gFieldState->tasks, &gTaskDescMapGmk00, e);
        q++;
        e++;
    }

    if (gUnk_0203C590.unk_06 != 0xFE) {
        return;
    }

    if ((gGameState.flags & 8) || (s8)gGameState.floor != 0) {
        v.x = 0x18000;
        x = 0x11000;
    } else {
        v.x = 0x26000;
        x = 0x12000;
    }

    v.y = x;
    n = 0;
    v.unk_0C = n;
    v.z = n;
    e->unk_00 = n;
    e->unk_14 = &gUnk_0984C1CC;
    e->unk_04 = v;
    TaskCreate(gFieldState->tasks, gUnk_0984C1CC.desc, e);
    e++;

    if (func_080DF750() != 0) {
        if ((gGameState.flags & 8) || (s8)gGameState.floor != 0) {
            v.x = 0x1F000;
            x = 0x14000;
        } else {
            v.x = 0x2D000;
            x = 0x15000;
        }

        v.y = x;
        n = 0;
        v.unk_0C = n;
        v.z = n;
        e->unk_00 = n;
        e->unk_14 = &gUnk_0984C23C;
        e->unk_04 = v;
        TaskCreate(gFieldState->tasks, gUnk_0984C23C.desc, e);
    }
}

void func_080E5800(void) {
    u16 sx;
    u16 sy;

    gFieldState->x = gFieldState->x2 - 0x7800;
    gFieldState->y = gFieldState->y2 - 0x6000;
    sx = (gFieldState->x / 8) >> 8;
    sy = (gFieldState->y / 8) >> 8;
    RedrawBgMapAt(3, sx, sy);
    RedrawBgMapAt(2, sx, sy);
    RedrawBgMapAt(1, sx, sy);
}

void func_080E5868(UnkStruct_09EF8370* p) {
    s32 i;
    s32 n;

    gUnk_02034F38 = EwramAlloc(0x18000);
    n = gUnk_0203C7AC->unk_04 * gUnk_0203C7AC->unk_06;

    for (i = 0; i < n; i++) {
        ((MapCell*)gUnk_02034F38)[i].unk_00 = 0;
        ((MapCell*)gUnk_02034F38)[i].unk_02 = 11;
        ((MapCell*)gUnk_02034F38)[i].unk_03 = 7;
        ((MapCell*)gUnk_02034F38)[i].unk_04 = 0;
        ((MapCell*)gUnk_02034F38)[i].unk_05 = 0;
        ((MapCell*)gUnk_02034F38)[i].unk_14 = 0;
        ((MapCell*)gUnk_02034F38)[i].unk_18 = 0;
        ((MapCell*)gUnk_02034F38)[i].unk_1C = 0;
    }
    func_080E55E4(p->unk_28);
}

void func_080E58E4(void) {
    EwramFree(gUnk_02034F38);
}

MapCell* func_080E58F8(s16 a, s16 b) {
    return (MapCell*)func_080E55A4(a, b);
}
