#include "macros.h"
#include "map_ui_data.h"
#include "map_text_assets.h"
#include "registration_data.h"
#include "map_menu_assets.h"
#include "system_state.h"
#include "map_api.h"
#include "msg_api.h"
#include "status_api.h"
#include "task.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "display.h"
#include "text.h"
#include "monsgage.h"
#include "anim.h"
#include "map.h"
#include "map_spawn_data.h"
#include "map_resource_assets.h"
#include "map_text_data.h"
#include "sprites_btl.h"
#include "sprites_evt.h"
#include "sprites_map.h"
#include "sprites_sora.h"

UnkStruct_0203C7AC* gUnk_0203C7AC EWRAM_COMMON(4);
UnkStruct_0203C7B0 gUnk_0203C7B0 EWRAM_COMMON(8);
struct UnkStruct_0203C7B8* gUnk_0203C7B8 EWRAM_COMMON(4);

extern u8 gUnk_09EF6A34[];
extern u8 gUnk_09EF6A42[];
extern u8 (*gUnk_09EF6A50[])(UnkStruct_080DFF1C*);
extern u8 (*gUnk_09EF6A88[])(UnkStruct_080E8B1C*);
extern u8 gUnk_09EF6AB0[];

#ifdef VERSION_EU
extern void* gUnkEu_088927F4[];
extern void* gUnkEu_088928E4[];
extern void* gUnkEu_08890E1C[];
extern void* gUnkEu_08890E44[];
extern void* gUnkEu_08892780[];
extern void* gUnkEu_08892864[];
extern const u8 gUnkEu_09953BF0[];
extern const u8 gUnkEu_099543F0[];
extern const u8 gUnkEu_09954BF0[];
extern u8 gUnkEu_09938170[];
extern u8 gUnkEu_09939D30[];
extern u8 gUnkEu_0993B8F0[];
extern u8 gUnkEu_0993D4B0[];
extern u8 gUnkEu_0993E9B0[];
extern u8 gUnkEu_0993FEB0[];
extern u8 gUnkEu_099413B0[];
extern u8 gUnkEu_099428B0[];
extern u8 gUnkEu_09943DB0[];
extern u8 gUnkEu_099452B0[];
extern u8 gUnkEu_099467B0[];
extern u8 gUnkEu_09947CB0[];
extern u8 gUnkEu_099491B0[];
extern u8 gUnkEu_0994A6B0[];
extern u8 gUnkEu_0994A8B0[];
extern u8 gUnkEu_0994AAB0[];
extern u8 gUnkEu_0994ACB0[];
extern const u8 gUnkEu_0996D130[];
extern const u8 gUnkEu_0996D930[];
extern const u8 gUnkEu_0996E130[];
extern const u8 gUnkEu_0996E930[];
extern const u8 gUnkEu_09955250[][320];
extern const u8 gUnkEu_09957550[][320];
extern const u8 gUnkEu_09959850[][320];
extern const u8 gUnkEu_0995BB50[][320];
extern const u8 gUnkEu_0995DE50[][320];
extern const u8 gUnkEu_09960150[][320];
extern const u8 gUnkEu_09962450[][320];
extern const u8 gUnkEu_09964750[][320];
extern const u8 gUnkEu_09966A50[][320];
extern const u8 gUnkEu_09968D50[][320];
extern const u8 gUnkEu_099563D0[][320];
extern const u8 gUnkEu_099586D0[][320];
extern const u8 gUnkEu_0995A9D0[][320];
extern const u8 gUnkEu_0995CCD0[][320];
extern const u8 gUnkEu_0995EFD0[][320];
extern const u8 gUnkEu_099612D0[][320];
extern const u8 gUnkEu_099635D0[][320];
extern const u8 gUnkEu_099658D0[][320];
extern const u8 gUnkEu_09967BD0[][320];
extern const u8 gUnkEu_09969ED0[][320];
extern u8 gUnkEu_098863B2[];
extern u8 gUnkEu_0988683C[];
extern u8 gUnkEu_09886C7E[];
extern u8 gUnkEu_09886FC8[];
#define LANGSEL(x) eu_0805E924(x)
#else
#define LANGSEL(x) (x)
#endif

MapCell* gUnk_02034F1C;
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
Task* gUnk_02034FB4;
void* gUnk_02034FB8;
u8 gUnk_02034FBC;
u8 gUnk_02034FBD[0x17];
s32 gUnk_02034FD4;
u8 gUnk_02034FD8;
NewGameSlotMenuWork* gUnk_02034FDC;
LoadGameMenuWork* gUnk_02034FE0;
UnkStruct_02034FE4* gUnk_02034FE4;

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

    gUnk_02039BA0->x = func_080E0010(gUnk_02039BA0->x2);
    gUnk_02039BA0->y = func_080E0044(gUnk_02039BA0->y2);
    sx = gUnk_02039BA0->x >> 8;
    sy = gUnk_02039BA0->y >> 8;
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

    if ((gUnk_02039BA0->unk_70 & 0x40000) == 0) {
        x = func_080E0010(a);
        y = func_080E0044(b);
    } else {
        x = a - 0x7800;
        y = b - 0x6000;
    }

    dx = (x - gUnk_02039BA0->x) >> 3;

    if (dx > 0x800) {
        dx = 0x800;
    } else if (dx < -0x800) {
        dx = -0x800;
    }

    dy = (y - gUnk_02039BA0->y) >> 3;

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

    gUnk_02039BA0->x += dx;
    gUnk_02039BA0->y += dy;
    sx = gUnk_02039BA0->x / 0x800;
    sy = gUnk_02039BA0->y / 0x800;
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

    SetBgScroll(3, (u16)(gUnk_02039BA0->x >> 8), (u16)(gUnk_02039BA0->y >> 8));
    SetBgScroll(2, (u16)(gUnk_02039BA0->x >> 8), (u16)(gUnk_02039BA0->y >> 8));

    if (!(gUnk_0203C7AC->unk_00 & 1)) {
        SetBgScroll(1, (u16)(gUnk_02039BA0->x >> 8), (u16)(gUnk_02039BA0->y >> 8));
    }
}

void func_080E0298(s32 x, s32 y) {
    gUnk_02039BA0->x2 = x;
    gUnk_02039BA0->y2 = y;
}

void func_080E02A8(s32 dx, s32 dy) {
    gUnk_02039BA0->x2 += dx;
    gUnk_02039BA0->y2 += dy;
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

    if (gUnk_02039BA0->actor.fieldPosition.z != gUnk_02039BA0->actor.fieldPosition.unk_0C) {
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
        LoadBgTiles(1, p->tiles2, p->tilesSize2);
        LoadBgPalette(1, p->palette, p->paletteSize);
        SetBgMapBlocks(1, p->map, p->mapWidth, p->mapHeight);
        gUnk_0203C7AC->unk_00 &= ~1;
    } else {
        q = gUnk_09EF70D0[gUnk_0203C590.unk_04];
        LoadBgTiles(1, q->tiles2, q->tilesSize2);
        LoadBgPalette(1, q->palette, q->paletteSize);
        x = gUnk_02039BA0->x >> 8;
        y = gUnk_02039BA0->y >> 8;
        func_080E4D68(x / 8, y / 8);
        SetBgScroll(1, (u16)x, (u16)y);
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
        gGameState.unk_00F = 0xFF;
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFF, 0x100);
    }
    func_080E04EC();
}

void func_080E0558(void) {
    gUnk_02039BA0->x = 0;
    gUnk_02039BA0->y = 0;
    gUnk_02039BA0->x2 = 0;
    gUnk_02039BA0->y2 = 0;
    gUnk_02039BA0->unk_10 = 32;
    gUnk_02039BA0->unk_12 = 32;
    gUnk_02039BA0->unk_68 = 0;
    gUnk_02039BA0->unk_6C = 60;
    gUnk_02039BA0->unk_70 = 0;
    gUnk_02039BA0->unk_74 = 0;
    TaskPoolInit(gUnk_02039BA0->unk_78, 50);
    TaskPoolInit(gUnk_02039BA0->unk_8C, 1);
    ListPoolInit(&gUnk_02039BA0->actor.pool);
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
    UnkStruct_080DFB7C* e;
    s32 x;
    s32 y;

    if (gUnk_0203C590.unk_07 <= 3) {
        e = (UnkStruct_080DFB7C*)func_080DFB7C(gUnk_0203C590.unk_07);
        x = (e->unk_02 << 5) + 16;
        y = (e->unk_04 << 4) + 10;

        switch (gUnk_0203C590.unk_07) {
        case 0:
            gUnk_02039BA0->unk_DC = (x << 8) - 0xC00;
            gUnk_02039BA0->unk_E0 = (y << 8) + 0x800;
            gUnk_02039BA0->unk_E4 = 0xAD;
            break;
        case 1:
            gUnk_02039BA0->unk_DC = (x << 8) + 0xC00;
            gUnk_02039BA0->unk_E0 = (y << 8) - 0x800;
            gUnk_02039BA0->unk_E4 = 0x2D;
            break;
        case 2:
            gUnk_02039BA0->unk_DC = (x << 8) - 0xC00;
            gUnk_02039BA0->unk_E0 = (y << 8) - 0x800;
            gUnk_02039BA0->unk_E4 = 0xD3;
            break;
        case 3:
            gUnk_02039BA0->unk_DC = (x << 8) + 0xC00;
            gUnk_02039BA0->unk_E0 = (y << 8) + 0x800;
            gUnk_02039BA0->unk_E4 = 0x53;
            break;
        }
    } else {
        func_080E524C((UnkStruct_080DFF1C*)&gUnk_02039BA0->unk_DC, &gUnk_02039BA0->unk_E0);
        gUnk_02039BA0->unk_E4 = 0x80;
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

MapCell* func_080E08BC(s16 x, s16 y) {
    if (y < 0 || y >= gUnk_02034F2A) {
        return 0;
    }

    if (x < 0 || x >= gUnk_02034F28) {
        return 0;
    }
    return &gUnk_02034F1C[gUnk_02034F28 * y + x];
}

void func_080E0900(MapCell* p, s32 a, s32 b) {
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
    u16 x = p->unk_0A;
    u16 y = p->unk_0C;

    while (go) {
        s16 cy = (s16)y;
        MapCell* c = func_080E08BC((s16)x, cy);

        switch (c->unk_02) {
        case 4:
            func_080E08BC((s16)x, (s16)(y + 1))->unk_00 |= 0x40;
            func_080E08BC((s16)(x + 1), cy)->unk_00 |= 0x40;
            func_080E08BC((s16)(x + 1), (s16)(y + 1))->unk_00 |= 0x40;
            c->unk_00 |= 0x40;
            p->unk_0A = x + 1;
            p->unk_0C = y + 1;
            go = 0;
            break;
        case 6:
            func_080E08BC((s16)x, (s16)(y + 1))->unk_00 |= 0x40;
            func_080E08BC((s16)(x - 1), cy)->unk_00 |= 0x40;
            func_080E08BC((s16)(x - 1), (s16)(y + 1))->unk_00 |= 0x40;
            c->unk_00 |= 0x40;
            p->unk_0A = x;
            p->unk_0C = y + 1;
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
    MapCell* e;

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

    if (gGameState.unk_000 == 0) {
        EwramFree(gUnk_02034F1C);
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

    a->unk_00 = gUnk_02039BA0->actor.fieldPosition.x;
    *b = gUnk_02039BA0->actor.fieldPosition.y + gUnk_02039BA0->actor.fieldPosition.unk_0C;
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
        s32 ty = (gUnk_02039BA0->y / 16 >> 8) + 2;
        u16 yy = y + ty;

        for (i = 0; i < w; i++) {
            s32 tx = (gUnk_02039BA0->x / 32 >> 8) + 1;
            u16 xx = x + tx;
            s32* q = &gUnk_02039BA0->actor.fieldPosition.x;
            MapCell* e;

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
        v.unk_00 = q->unk_04;
        x = q->unk_08;
        v.x = v.y = v.z = 0;
        v.x = x;
        e->unk_00 = 2;
        n = q->unk_00;
        e->unk_14 = &gUnk_09856FB4[n];
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
        x = 0x11000;
    } else {
        v.unk_00 = 0x26000;
        x = 0x12000;
    }

    v.x = x;
    n = 0;
    v.z = n;
    v.y = n;
    e->unk_00 = n;
    e->unk_14 = &gUnk_0984C1CC;
    e->unk_04 = v;
    TaskCreate(gUnk_02039BA0->unk_78, gUnk_0984C1CC.unk_24, e);
    e++;

    if (func_080DF750() != 0) {
        if ((gGameState.flags & 8) || (s8)gGameState.floor != 0) {
            v.unk_00 = 0x1F000;
            x = 0x14000;
        } else {
            v.unk_00 = 0x2D000;
            x = 0x15000;
        }

        v.x = x;
        n = 0;
        v.z = n;
        v.y = n;
        e->unk_00 = n;
        e->unk_14 = &gUnk_0984C23C;
        e->unk_04 = v;
        TaskCreate(gUnk_02039BA0->unk_78, gUnk_0984C23C.unk_24, e);
    }
}

void func_080E5800(void) {
    u16 sx;
    u16 sy;

    gUnk_02039BA0->x = gUnk_02039BA0->x2 - 0x7800;
    gUnk_02039BA0->y = gUnk_02039BA0->y2 - 0x6000;
    sx = (gUnk_02039BA0->x / 8) >> 8;
    sy = (gUnk_02039BA0->y / 8) >> 8;
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
            MapCell* e = func_080E548C(x, y);

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

void func_080E5B90(UnkStruct_080E5B90* p, const UnkStruct_0984BC9C* q) {
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
    const UnkStruct_0984BC9C* d;
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
        w->unk_18 = GetAngle(w->unk_08.unk_00, w->unk_08.x, gUnk_02039BA0->actor.fieldPosition.x, gUnk_02039BA0->actor.fieldPosition.y);
        break;
    }
    if (ok) {
        gUnk_02034F48[gUnk_02034F40] = w->unk_08;
        w->unk_1C = 0;
        w->unk_00 = d;
        w->unk_04 = 0;
        TaskCreate(gUnk_02039BA0->unk_B4, d->desc, w);
    }
}

void func_080E5CD4(MapEnmWork* p) {
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

void func_080E5D6C(MapEnmWork* p, u8 n, u16 a) {
    const AnimDef* q = p->unk_00->animDef;

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
    AnimChangeWithTables(p->anim, q->animId, a, q->anims, q->gfxTable);
    SetObjTileSource(p->tiles, q->tiles);
}

void func_080E5DEC(MapEnmWork* p) {
    if (gUnk_02039BA0->unk_70 & 0x10000) {
        if (AnimIsFrameEnding(p->anim)) {
            return;
        }
    } else {
        if (AnimIsFrameEnding(p->anim)) {
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

void func_080E5EAC(MapEnmWork* p) {
    gGameState.flags |= 2;
    ColliderSetDisabled(p->unk_48, 1);
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

void func_080E5F50(MapEnmWork* p) {
    if (p->unk_74 != 0) {
        if ((gUnk_0203C7AC->unk_00 & 4) == 0 && ColliderIsTouchingType(p->unk_48, 1)) {
            func_080E5EAC(p);
            return;
        }

        if (ColliderIsTouchingType(p->unk_48, 6)) {
            p->unk_08.unk_00 += p->unk_80;
            p->unk_08.x += p->unk_84;
        }
    }
}

s32 func_080E5FB4(MapEnmWork* p) {
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

void func_080E6034(MapEnmWork* p) {
    UnkStruct_080E6034* q = ListPoolFirstFree(gGameState.unk_0E8);

    if (q != 0) {
        q->unk_30 = p->unk_00;
        q->unk_34 = p->update;
        q->unk_00 = p->unk_08;
        q->unk_10 = p->unk_1C;
        q->unk_14 = p->unk_18;
        ListPoolActivate(q->unk_1C, gGameState.unk_0E8);
    }
}

void func_080E607C(void) {
    UnkStruct_080E6034* q;
    UnkStruct_080E5B90 w;
    const UnkStruct_0984BC9C* d;
    s32 i;

    q = ListPoolFirst(gGameState.unk_0E8);
    while (q != 0) {
        d = q->unk_30;
        w.unk_00 = d;
        w.unk_04 = q->unk_34;
        w.unk_08 = q->unk_00;
        w.unk_18 = q->unk_10;
        w.unk_1C = q->unk_14;
        TaskCreate(gUnk_02039BA0->unk_B4, d->desc, &w);
        q = ListPoolNext(q->unk_1C);
    }
    ListPoolInit(gGameState.unk_0E8);

    for (i = 0; i < 3; i++) {
        ListPoolAddFree(gGameState.unk_040[i].unk_1C, gGameState.unk_0E8, gGameState.unk_040[i].unk_00);
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
    const UnkStruct_0984BC9C* d;
    UnkStruct_080DEE18* e;
    s32 i;

    gUnk_02034F40 = 0;
    gUnk_02034F41 = 0;
    gUnk_02034F42 = 46;

    if (gGameState.unk_000 != 0) {
        q = ListPoolFirst(gGameState.unk_0E8);
        while (q != 0) {
            d = q->unk_30;
            w.unk_00 = d;
            w.unk_04 = q->unk_34;
            w.unk_08 = q->unk_00;
            w.unk_18 = q->unk_10;
            w.unk_1C = q->unk_14;
            TaskCreate(gUnk_02039BA0->unk_B4, d->desc, &w);
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
    ListPoolInit(gGameState.unk_0E8);

    for (i = 0; i < 3; i++) {
        ListPoolAddFree(gGameState.unk_040[i].unk_1C, gGameState.unk_0E8, gGameState.unk_040[i].unk_00);
    }
}

void func_080E6264(void) {
    const u8* t;
    UnkStruct_080DEE18* e;
    const UnkStruct_0984BC9C* d;
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
    TaskCreate(gUnk_02039BA0->unk_B4, d->desc, &w);
}

void func_080E6394(MapEnmWork* p, UnkStruct_080E5B90* q) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&p->unk_08;
    const UnkStruct_0984BC9C* d = q->unk_00;

    p->unk_00 = d;
    p->update = q->unk_04;
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
    p->palette = LoadObjPalette(d->palette, 32);
    p->gfx = 0;
    AnimInit((AnimState*)&p->anim, 0, 0);
    TaskPoolInit((TaskPool*)&p->unk_E4, 2);

    if ((d->unk_14 & 1) == 0) {
        TaskCreate(&p->unk_E4, &gTaskDescFldShadow, e);
    }

    if (d->unk_14 & 8) {
        p->unk_04 |= 2;
        ColliderInit(&p->unk_48, 11, d->unk_0C, d->unk_0A);
    } else {
        ColliderInit(&p->unk_48, 3, d->unk_0C, d->unk_0A);
    }
    ColliderSetPosition(&p->unk_48, e->unk_00.unk_00, e->unk_00.x, e->unk_00.y);
    ColliderSetDisabled(&p->unk_48, 1);
    func_080E5CD4(p);
}

void func_080E64D4(MapEnmWork* p) {
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
    x = (p->unk_08.unk_00 >> 8) - (gUnk_02039BA0->x >> 8);
    t = flags;
    y = k + (q->unk_00.y >> 8) - (gUnk_02039BA0->y >> 8);
    DrawSprite(x, y, p->gfx, p->tiles, p->palette, z, t, v);
    TaskPoolDraw(p->unk_E4);
}

void func_080E657C(MapEnmWork* p) {
    UnkStruct_080E6034* q;

    if (gGameState.unk_000 != 0 && (p->unk_04 & 4) == 0 &&
        ((gUnk_0203C7AC->unk_00 & 2) == 0 || (p->unk_04 & 2))) {
        q = ListPoolFirstFree(gGameState.unk_0E8);
        if (q != 0) {
            q->unk_30 = p->unk_00;
            q->unk_34 = p->update;
            q->unk_00 = p->unk_08;
            q->unk_10 = p->unk_1C;
            q->unk_14 = p->unk_18;
            ListPoolActivate(q->unk_1C, gGameState.unk_0E8);
        }
    }
    gUnk_02034F40--;
    gUnk_02034F41 -= p->unk_00->unk_08;
    ColliderUnregister(p->unk_48);
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

MapCell* func_080E67D4(s32 x, s32 y) {
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
    MapCell* p = func_080E548C(x, y);

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
    MapCell* p = func_080E548C(a, b);
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
        MapCell* p = func_080E548C(x, y + i);
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
    MapCell* q;
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

u8 func_080E6B24(UnkStruct_080DFF1C* p) {
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

u8 func_080E6C2C(UnkStruct_080DFF1C* p) {
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

u8 func_080E6DB0(UnkStruct_080DFF1C* p) {
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

u8 func_080E6F04(UnkStruct_080DFF1C* p) {
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

u8 func_080E7088(UnkStruct_080DFF1C* p) {
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

u8 func_080E71F0(UnkStruct_080DFF1C* p) {
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

u8 func_080E7358(UnkStruct_080DFF1C* p) {
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

u8 func_080E74D8(UnkStruct_080DFF1C* p) {
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

u8 func_080E7620(UnkStruct_080DFF1C* p) {
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

u8 func_080E77A4(UnkStruct_080DFF1C* p) {
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

u8 func_080E7928(UnkStruct_080DFF1C* p) {
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

u8 func_080E7A30(UnkStruct_080DFF1C* p) {
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

u8 func_080E7B38(UnkStruct_080DFF1C* p) {
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

u8 func_080E7C40(UnkStruct_080DFF1C* p) {
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
        if (gUnk_0203C7B8[i].unk_14->palette == a) {
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
        if (gUnk_0203C7B8[i].unk_14->tiles == a) {
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

void func_080E7E3C(void) {
    UnkStruct_080DFF1C w;
    UnkStruct_080DEE18* e;
    const UnkStruct_080E7D80* q;
    s32 i;

    e = func_080DEE18(gUnk_0203C590.unk_06);

    if (gUnk_0203C7AC->unk_0D == 10) {
        u8* n;

        q = &gUnk_0984C158;
        n = &gUnk_02034F78;

        for (i = 1; i >= 0; i--) {
            s32 size;

            func_080E7D64(&w, q->unk_15);

            if (e->unk_00 & 0x10) {
                gUnk_0203C7B8[*n].unk_00 = 10;
            } else {
                gUnk_0203C7B8[*n].unk_00 = 8;
            }

            gUnk_0203C7B8[*n].unk_14 = q;
            gUnk_0203C7B8[*n].unk_04 = w;
            gUnk_02034F7A += (size = q->tilesSize) / 32;
            gUnk_02034F79++;
            (*n)++;
        }
    }

    if (gUnk_0203C7AC->unk_0D == 3 || gUnk_0203C7AC->unk_0D == 9 || gUnk_0203C7AC->unk_0D == 10 ||
        gUnk_0203C7AC->unk_0D == 22) {
        MapCell* p;
        u16 v;

        q = &gUnk_0984C158;
        func_080E7D64(&w, q->unk_15);
        v = e->unk_00 & 0x10;

        if (v != 0) {
            gUnk_0203C7B8[gUnk_02034F78].unk_00 = 2;
        } else {
            gUnk_0203C7B8[gUnk_02034F78].unk_00 = 0;
        }

        gUnk_0203C7B8[gUnk_02034F78].unk_14 = q;
        gUnk_0203C7B8[gUnk_02034F78].unk_04 = w;
        gUnk_02034F7A += q->tilesSize >> 5;
        gUnk_02034F79++;
        gUnk_02034F78++;
        p = func_080E67D4(w.unk_00, w.x + w.y);
        p->unk_00 |= 0x80;
    }
}

void func_080E7FCC(void) {
    UnkStruct_080DFF1C w;

    if (gUnk_0203C7AC->unk_0D == 6 || gUnk_0203C7AC->unk_0D == 0x17) {
        func_080E7D64(&w, gUnk_0984C1CC.unk_15);
        gUnk_0203C7B8[gUnk_02034F78].unk_00 = 0;
        gUnk_0203C7B8[gUnk_02034F78].unk_14 = &gUnk_0984C1CC;
        gUnk_0203C7B8[gUnk_02034F78].unk_04 = w;
        gUnk_02034F7A += gUnk_0984C1CC.tilesSize >> 5;
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
        gUnk_02034F7A += gUnk_0984C204.tilesSize >> 5;
        gUnk_02034F79++;
        gUnk_02034F78++;
    }
}

void func_080E80E0(void) {
    UnkStruct_080DFF1C w;
    const UnkStruct_080E7D80* t;
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

        if (gUnk_02034F7A + t->tilesSize / 32 > 0x200) {
            return;
        }

        f = (u8)func_080E7D80(t->palette);

        if (f != 0 && gUnk_02034F79 > 5) {
            return;
        }

        if (func_080E7D64(&w, t->unk_15) == 0) {
            return;
        }

        gUnk_0203C7B8[gUnk_02034F78].unk_00 = 0;
        gUnk_0203C7B8[gUnk_02034F78].unk_14 = t;
        gUnk_0203C7B8[gUnk_02034F78].unk_04 = w;
        gUnk_02034F7A += t->tilesSize >> 5;
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
        const UnkStruct_080E7D80* e = &gUnk_09856FB4[func_080E6634(i)];
        u8 f = func_080E7DB8(e->unk_14, e->tiles);
        u8 g;

        if (f != 0) {
            if ((e->tilesSize >> 5) + gUnk_02034F7A > 512) {
                continue;
            }
        }

        g = func_080E7D80(e->palette);

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
            gUnk_02034F7A += e->tilesSize >> 5;
        }

        if (g != 0) {
            gUnk_02034F79++;
        }
    }
}

u8 func_080E8374(UnkStruct_080E8374* p) {
    s32 lim = gUnk_02039BA0->actor.fieldPosition.y + gUnk_02039BA0->actor.fieldPosition.z + 0x4000 + (p->unk_1A << 8);

    if (p->unk_00 < gUnk_02039BA0->x || p->unk_00 > gUnk_02039BA0->x + 0xF000 ||
        p->unk_04 + p->unk_08 < gUnk_02039BA0->y || p->unk_04 + p->unk_08 > lim) {
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
    if (gGameState.unk_000 == 0) {
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
    const UnkStruct_080E7D80* d;

    for (i = 0; i < 12; i++) {
        p = func_080E54A0(i);
        if (p->unk_08 == 0 && p->unk_14 != 0x100000) {
            TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapGmkJump, p);
        }
    }
    for (i = 0; i < gUnk_02034F78; i++) {
        d = gUnk_0203C7B8[i].unk_14;

        if ((gUnk_0203C7B8[i].unk_00 & 1) == 0) {
            TaskCreate(gUnk_02039BA0->unk_78, d->unk_24, &gUnk_0203C7B8[i]);
        }
    }
    TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapGmkDmy, 0);
}

void func_080E8624(void) {
    if (gGameState.unk_000 == 0) {
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

u8 func_080E86C8(MapCell* p, s32 x, s32 y) {
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
    MapCell* q;

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
    MapCell* q;
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
    MapCell* q;

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
    if (gGameState.unk_000 == 0) {
        UnkStruct_09EF70D0* p = gUnk_09EF70D0[gUnk_0203C590.unk_04];

        func_080E891C(p->unk_24);
        func_080E8AC8(p->unk_28);
    }
}

void func_080E8B1C(UnkStruct_080E8B1C* p, const UnkStruct_080E7D80* q) {
    p->unk_00 = q->tiles;
    p->unk_04 = q->tilesSize;
    p->unk_08 += q->unk_0A << 5;
    p->unk_10 = 0;
    p->unk_14 = q->palette;
    p->unk_18 = q->palette;
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

u8 func_080E8C84(u8 a, u8 b) {
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
            gUnk_02034F84 = &((UnkStruct_02034F84*)gUnk_0203C590.unk_08)[i];
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
    UnkStruct_080E8E74** t = gUnk_09EF8388;
    UnkStruct_080E8E74* p = t[gGameState.world];

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
        e = &gUnk_0985814C[14];

        if (func_0800FC5C(e->unk_00[0]) != 1) {
            func_0800FC14(e->unk_00[0]);
            func_080E8F50(e, 1, x, y, z);
            return;
        }

        e += 24;

        if (func_0800FC5C(e->unk_00[0]) != 1) {
            func_0800FC14(e->unk_00[0]);
            func_080E8F50(e, 1, x, y, z);
            return;
        }

        e++;

        if (func_0800FC5C(e->unk_00[0]) != 1) {
            func_0800FC14(e->unk_00[0]);
            func_080E8F50(e, 1, x, y, z);
            return;
        }
    }

    e = func_080E8E74(1);

    if (e != 0) {
        func_080E8F50(e, 1, x, y, z);
    }
}

u8 func_080E924C(void) {
    s32 i;
    u8* p;

    for (i = 1; i <= 11; i++) {
        UnkStruct_080E8E24** t = gUnk_09EF83C0;

        p = (u8*)t[i];

        while (p[0] != 4) {
            switch (p[0]) {
            case 2:
                if (func_0800FC5C((gUnk_0985814C + p[1])->unk_00[0]) != 1) {
                    return 0;
                }
                break;
            case 3:
                if (func_0800FBCC((gUnk_098581EC + p[1])->unk_00[0]) != 1) {
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
    src = (u32*)gGameState.floors;
    dst = (u32*)p->floors;

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
    src = (u32*)p->floors;
    dst = (u32*)gGameState.floors;

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
        (*(volatile u16*)&gDispCnt) = ((*(volatile u16*)&gDispCnt) & 0xFDFF) | (m1 & ~(*(volatile u16*)&gDispCnt));
    }
    if (GetKeysPressed() & 2) {
        (*(volatile u16*)&gDispCnt) = ((*(volatile u16*)&gDispCnt) & 0xEFFF) | (m2 & ~(*(volatile u16*)&gDispCnt));
    }
}

void func_080E93FC(void) {
    if (gUnk_0203C7AC->unk_00 & 2) {
        gUnk_0203C7AC->unk_00 &= ~2;
        gUnk_0203C7AC->unk_00 &= ~4;
        gUnk_0203C7AC->unk_00 &= ~0x80;
    }
    if (gUnk_02039BA0->unk_70 & 0x10) {
        FadeStartOut(0, 16);
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
    ColliderUpdateAll();
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
    if (FadeIsActive() == 0) {
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
        FadeStartOut(0, 16);
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
    ColliderPoolsInit();
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

    if (gGameState.unk_000 != 0) {
        func_080E0298(gGameState.fieldPosition.x, gGameState.fieldPosition.y + gGameState.fieldPosition.z);
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
    FadeStartIn(0, 16);
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
        FadeStartOut(0, 16);
        FadeLock();
        func_080E9898((s32)func_080E9D94);
        return;
    }
    if (gUnk_02039BA0->unk_70 & 0x10) {
        FadeStartOut(0, 16);
        FadeLock();
        func_080E9898((s32)func_080E9CBC);
        return;
    }
    if (FadeIsActive() == 0 && (gGameState.progression.unk_82 & 0x200) != 0 &&
        (gUnk_02039BA0->unk_70 & 0x41000) == 0 && (gUnk_0203C7AC->unk_00 & 4) == 0) {
        if (GetKeysPressed() & 4) {
            m4aSongNumStart(0x67);
            FadeStartOut(0, 16);
            FadeLock();
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
    ColliderUpdateAll();
    func_080E6264();
}

void func_080E9CBC(void) {
    u8 r;
    u8* e;
    UnkStruct_080DEDD8* d;

    func_080E0820();
    r = FadeIsActive();
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
    if (FadeIsActive() == 0) {
        func_0801CB0C();
        if (gGameState.flags & 8) {
            if (gGameState.progression.unk_82 & 0x1000) {
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
    if (FadeIsActive() == 0) {
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
        FadeStartOut(0, 16);
        FadeLock();
        func_080E9898((s32)func_080E9CBC);
        if ((gGameState.progression.unk_82 & 0x200) == 0) {
            t = gGameState.progression.unk_82 | 0x200;
            gGameState.progression.unk_82 = t;
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

    if ((gUnk_0203C590.unk_02 & 0x10) && gGameState.unk_000 == 0) {
        switch (gUnk_0203C590.unk_07) {
        case 0:
            gGameState.unk_024 = 0xAD;
            break;
        case 1:
            gGameState.unk_024 = 0x2D;
            break;
        case 2:
            gGameState.unk_024 = 0xD3;
            break;
        case 3:
            gGameState.unk_024 = 0x53;
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
    ColliderPoolsInit();
    func_080E05E4();
    func_080E853C();
    func_080E6178();
    func_080E8AE8();
    func_080E062C();

    p = gUnk_09EF70D0[gUnk_0203C590.unk_04];
    TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescLockon, 0);
    TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapAnm, p->unk_2C);

    if ((gGameState.progression.unk_82 & 0x20) == 0) {
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapTutorial, 0);
    }

    if ((gUnk_0203C590.unk_02 & 0x10) == 0) {
        func_080E988C((s32)func_080E9AF0);
        gUnk_02039BA0->unk_70 |= 0x200;
        gUnk_02039BA0->unk_70 |= 1;
        func_080E0298(gUnk_02039BA0->unk_DC, gUnk_02039BA0->unk_E0);
        func_080E98B0();
    } else if (gGameState.unk_000 != 0) {
        func_080E0298(gGameState.fieldPosition.x, gGameState.fieldPosition.y + gGameState.fieldPosition.z);
        if ((s8)gGameState.unk_00F != -1) {
            t = (*(volatile u16*)&gDispCnt) & 0xEFFF;
            (*(volatile u16*)&gDispCnt) = t;
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
    FadeStartIn(0, 16);
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
    if (gGameState.progression.unk_84 & 2) {
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapDonald, 0);
    }
    if (gGameState.progression.unk_84 & 1) {
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
        if ((s8)gGameState.floor == 11 && gGameState.floors[12].unk_03 == 0) {
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
        FadeStartOut(0, 16);
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
    } else if (FadeIsActive() == 0 && (gGameState.progression.unk_82 & 0x200) != 0 &&
               (gUnk_02039BA0->unk_70 & 0x41000) == 0 && (gUnk_0203C7AC->unk_00 & 4) == 0 &&
               (GetKeysPressed() & 8) != 0) {
        TaskCreate(gUnk_02039BA0->unk_78, &gTaskDescMapMenu, 0);
        func_080EA1F4((s32)func_080EA730);
    } else {
        func_080E0780();
        func_080E0820();
        ColliderUpdateAll();
    }
}

void func_080EA5A8(void) {
    func_080E0820();
    if (FadeIsActive() == 0) {
        func_080DFA3C();
        ModeRequest(&gModeMapFld, 0);
    }
}

void func_080EA5CC(void) {
    func_080E0820();
    if (FadeIsActive() != 0) {
        return;
    }
    if (gUnk_0203C7AC->unk_00 & 0x200) {
        if ((s8)gGameState.floor == func_080DF750()) {
            gGameState.flags &= ~0x80;
            gGameState.progression.unk_84 = (gGameState.progression.unk_84 & 0xFF83) | gGameState.progression.unk_86;
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
    if (FadeIsActive() != 0) {
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
        FadeStartOut(2, 60);
        FadeLock();
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
        FadeStartOut(0, 16);
        func_080EA1F4((s32)func_080EA5A8);
    } else if ((gUnk_02039BA0->unk_70 & 0x40000) == 0) {
        gBldCnt = 0;
        SetBgPriority(0, 0);
        func_080E56B4(func_080EA20C()->unk_2C);
        func_080EA1F4((s32)func_080EA498);
    } else {
        func_080E0780();
        func_080E0820();
        ColliderUpdateAll();
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
    ColliderPoolsInit();
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

    if (gGameState.unk_000 != 0) {
        func_080E0298(gGameState.fieldPosition.x, gGameState.fieldPosition.y + gGameState.fieldPosition.z);
        if ((s8)gGameState.unk_00F != -1) {
            t = (*(volatile u16*)&gDispCnt) & 0xEFFF;
            (*(volatile u16*)&gDispCnt) = t;
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
        MosaicStartIn(16, 15);
        FadeStartIn(0, 16);
    } else {
        FadeStartIn(0, 16);
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
void func_080EAB20(u8 a, u8 b, u8 c) {
    const u8* src;

    a &= 1;

#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        if (b != 0) {
            if (gGameState.flags & 8) {
                src = gUnkEu_09957550[c];
            } else {
                src = gUnkEu_09955250[c];
            }
        } else {
            if (gGameState.flags & 8) {
                src = gUnkEu_099586D0[c];
            } else {
                src = gUnkEu_099563D0[c];
            }
        }
        break;
    case 1:
        if (b != 0) {
            if (gGameState.flags & 8) {
                src = gUnkEu_0995BB50[c];
            } else {
                src = gUnkEu_09959850[c];
            }
        } else {
            if (gGameState.flags & 8) {
                src = gUnkEu_0995CCD0[c];
            } else {
                src = gUnkEu_0995A9D0[c];
            }
        }
        break;
    case 4:
        if (b != 0) {
            if (gGameState.flags & 8) {
                src = gUnkEu_09960150[c];
            } else {
                src = gUnkEu_0995DE50[c];
            }
        } else {
            if (gGameState.flags & 8) {
                src = gUnkEu_099612D0[c];
            } else {
                src = gUnkEu_0995EFD0[c];
            }
        }
        break;
    case 3:
        if (b != 0) {
            if (gGameState.flags & 8) {
                src = gUnkEu_09964750[c];
            } else {
                src = gUnkEu_09962450[c];
            }
        } else {
            if (gGameState.flags & 8) {
                src = gUnkEu_099658D0[c];
            } else {
                src = gUnkEu_099635D0[c];
            }
        }
        break;
    case 2:
    default:
        if (b != 0) {
            if (gGameState.flags & 8) {
                src = gUnkEu_09968D50[c];
            } else {
                src = gUnkEu_09966A50[c];
            }
        } else {
            if (gGameState.flags & 8) {
                src = gUnkEu_09969ED0[c];
            } else {
                src = gUnkEu_09967BD0[c];
            }
        }
        break;
    }
#else
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
#endif
    RequestDma3Copy((void*)src, (u8*)GetBgCharBase(1) + (a * 608 + 320), 320);
}

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
    SaveFileSummary* p = &gGameState.fileSummaries[i];

    if (p->level != 0) {
        func_080EABB8(i, p->level);
        func_080EAC60(i, p->playTime);
        func_080EAB20(i, 0, p->floor);
        return 1;
    }
    func_080EAB20(i, 0, 13);
    return 0;
}

void func_080EAD84(u8 a) {
    SaveFileSummary* e;
    u8 i = gUnk_02034FDC->unk_33D != 0 ? a + 2 : a;
    e = &gGameState.fileSummaries[i];

    if (e->level != 0) {
        func_080EAB20(i, 1, e->floor);
        gUnk_02034FDC->unk_160 = LoadTextSlots((void*)func_080DF804(e->world), &gUnk_02034FDC->unk_040);

        if (gUnk_02034FDC->unk_33D == 0) {
            LoadObjPaletteBank(gUnk_02034FDC->palette8->unk_06, &gUnk_099910C4[0xB40]);
        } else {
            LoadObjPaletteBank(gUnk_02034FDC->palette8->unk_06, &gUnk_099910C4[0xB80]);
        }
    } else {
        func_080EAB20(i, 1, 13);
        gUnk_02034FDC->unk_160 = 0;
    }

    if (gUnk_02034FDC->selectedSlot == 0) {
        if (gUnk_02034FDC->unk_33D != 0) {
            LoadBgMap(1, &gUnk_09985F44[0x8800], 0x800);
        } else {
            LoadBgMap(1, &gUnk_09985F44[0x7800], 0x800);
        }

        SetBgScroll(1, 0, (u16)-9);
    } else {
        if (gUnk_02034FDC->unk_33D != 0) {
            LoadBgMap(1, &gUnk_09985F44[0x9000], 0x800);
        } else {
            LoadBgMap(1, &gUnk_09985F44[0x8000], 0x800);
        }

        SetBgScroll(1, 0, (u16)-6);
    }
}

void func_080EAEB0(u8 a) {
    u8 idx = gUnk_02034FDC->unk_33D != 0 ? a + 2 : a;
    SaveFileSummary* e = &gGameState.fileSummaries[idx];

    if (e->level != 0) {
        func_080EAB20(idx, 0, e->floor);
    } else {
        func_080EAB20(idx, 0, 13);
    }

    gUnk_02034FDC->unk_160 = 0;
}

void func_080EAF10(void) {
    s32 t;
    s32 u;

    DrawSprite(128, gUnk_02034FDC->y >> 8, gUnk_09EF8D68[1], gUnk_02034FDC->tiles2,
        gUnk_02034FDC->palette2, 0, 0xC00, 90);
    DrawSprite(128, gUnk_02034FDC->y2 >> 8, gUnk_09EF8D68[2], gUnk_02034FDC->tiles2,
        gUnk_02034FDC->palette2, 0, 0xC00, 90);

    if (gUnk_02034FDC->unk_33D == 0) {
        DrawSprite(56, 112, ((void**)gUnk_09EDE8CC)[0], gUnk_02034FDC->tiles4,
            gUnk_02034FDC->palette4, 0, 0x400, 80);
        DrawSprite(72, 96, gUnk_09EEFF84[0], gUnk_02034FDC->tiles5, gUnk_02034FDC->palette5, 0,
            0x401, 81);
        DrawSprite(40, 96, gUnk_09EEFEC0[0], gUnk_02034FDC->tiles6, gUnk_02034FDC->palette6, 0,
            0x400, 81);
    } else {
        DrawSprite(56, 112, gUnk_09EEF89C[0], gUnk_02034FDC->tiles7, gUnk_02034FDC->palette7, 0,
            0x400, 81);
    }

    DrawSprite(0, 16, gUnk_098A8F28, gUnk_02034FDC->tiles3, gUnk_02034FDC->palette3, 0, 0x400, 90);
    t = 45;
    u = gUnk_02034FDC->selectedSlot * t;
    ApproachValueHalf(&gUnk_02034FDC->y3, (gUnk_02034FDC->unk_162 + u) << 8);
    DrawSprite(76, gUnk_02034FDC->y3 >> 8, AnimGetGfx(&gUnk_02034FDC->anim),
        gUnk_02034FDC->tiles, gUnk_02034FDC->palette, 0, 0, 70);
    DrawTextSlots(100, u + (gUnk_02034FDC->unk_162 + 22), &gUnk_02034FDC->unk_040,
        gUnk_02034FDC->palette8, 50, gUnk_02034FDC->unk_160);
    DrawTextSlots(
        (240 - GetTextSlotsWidth(&gUnk_02034FDC->unk_168, gUnk_02034FDC->unk_318)) / 2, 134,
        &gUnk_02034FDC->unk_168, gUnk_02034FDC->palette9, 50, gUnk_02034FDC->unk_318);
}

void func_080EB12C(NewGameSlotMenuWork* w) {
    u8 prev = w->selectedSlot;

    if (GetKeysRepeat() & 0x40) {
        w->selectedSlot = w->selectedSlot != 0 ? w->selectedSlot - 1 : 1;
        m4aSongNumStart(0x65);
    }

    if (GetKeysRepeat() & 0x80) {
        w->selectedSlot = w->selectedSlot == 0 ? w->selectedSlot + 1 : 0;
        m4aSongNumStart(0x65);
    }

    if (prev != w->selectedSlot) {
        func_080EAEB0(prev);
        func_080EAD84(w->selectedSlot);
    }
}

void func_080EB1AC(NewGameSlotMenuWork* w) {
    if (w->timer != 0) {
        ApproachValue(&w->y, 0, w->timer);
        ApproachValue(&w->y2, 0x9800, w->timer);
        w->timer--;
    } else {
        w->update = func_080EB1F4;
    }
}

void func_080EB1F4(NewGameSlotMenuWork* w) {
    func_080EB12C(w);

    if (GetKeysPressed() & 2) {
        m4aSongNumStart(0x68);
    } else {
        if (!(GetKeysPressed() & 9)) {
            return;
        }

        switch (w->selectedSlot) {
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
    w->timer = 16;
    w->update = func_080EB27C;
}

void func_080EB27C(NewGameSlotMenuWork* w) {
    if (w->timer != 0) {
        ApproachValue(&w->y, -0x800, w->timer);
        ApproachValue(&w->y2, 0xA000, w->timer);
        w->timer--;
    } else {
        FadeStartOut(0, 90);
        w->update = func_080EB2D0;
    }
}

void func_080EB2D0(NewGameSlotMenuWork* w) {
    if ((u8)FadeIsActive() != 0) {
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

void Mode_MenuNew_0(void) {
    u8 v;
    u8 u;

    gUnk_02034FDC = EwramAlloc(0x348);
    gUnk_02034FDC->unk_33C = 0;
    gUnk_02034FDC->unk_33D = (gGameState.flags >> 3) & 1;
    gUnk_02034FDC->unk_162 = 33;
    gUnk_02034FDC->timer = 16;
    gUnk_02034FDC->update = func_080EB1AC;
    SetBgMode0();
    SetupBg(3, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(0, 0, 30, 0);
    SetBgPriority(3, 3);
    SetBgPriority(1, 0);
    SetBgPriority(0, 0);
#ifdef VERSION_EU
    LoadBgTiles(0, &gUnk_09966064[0x140], 0x1FA0);
    switch (gLanguage) {
    case 1:
        RequestDma3Copy((void*)gUnkEu_0996D130, (u8*)GetBgCharBase(0) + 0x800, 0x800);
        break;
    case 4:
        RequestDma3Copy((void*)gUnkEu_0996D930, (u8*)GetBgCharBase(0) + 0x800, 0x800);
        break;
    case 3:
        RequestDma3Copy((void*)gUnkEu_0996E130, (u8*)GetBgCharBase(0) + 0x800, 0x800);
        break;
    case 2:
        RequestDma3Copy((void*)gUnkEu_0996E930, (u8*)GetBgCharBase(0) + 0x800, 0x800);
        break;
    }
    LoadBgPalette(3, gUnk_09991D44, 0x200);
    LoadBgMap(3, gUnk_0998CF44, 0x800);
    LoadBgPalette(1, gUnk_09991D44, 0x200);
    LoadBgPalette(0, gUnk_09991D44, 0x200);
    LoadBgMap(0, gUnk_0998F744, 0x800);
#else
    LoadBgTiles(3, &gUnk_09966064[0x140], 0x1FA0);
    LoadBgPalette(3, gUnk_09991D44, 0x200);
    LoadBgMap(3, gUnk_0998CF44, 0x800);
    LoadBgTiles(1, &gUnk_09966064[0x140], 0x1FA0);
    LoadBgPalette(1, gUnk_09991D44, 0x200);
    LoadBgTiles(0, &gUnk_09966064[0x140], 0x1FA0);
    LoadBgPalette(0, gUnk_09991D44, 0x200);
    LoadBgMap(0, gUnk_0998F744, 0x800);
#endif
    SetBgScroll(0, 0, 0xFFFC);
    gUnk_02034FDC->palette2 = LoadObjPalette(gUnk_09991D04, 32);
    gUnk_02034FDC->tiles2 = LoadObjTiles(gUnk_098A8C66, 0x2C0);
    gUnk_02034FDC->y = -0x800;
    gUnk_02034FDC->y2 = 0xA000;
    gUnk_02034FDC->tiles4 = AllocObjTiles(0x340, gUnk_088B6560);
    gUnk_02034FDC->palette4 = LoadObjPalette(gUnk_08F683A4, 32);
    gUnk_02034FDC->tiles5 = AllocObjTiles(0x280, gUnk_0932EDD8);
    gUnk_02034FDC->palette5 = LoadObjPalette(gUnk_096181D8, 32);
    gUnk_02034FDC->tiles6 = AllocObjTiles(0x400, gUnk_09322F50);
    gUnk_02034FDC->palette6 = LoadObjPalette(gUnk_096181B8, 32);
    gUnk_02034FDC->tiles7 = AllocObjTiles(0x400, gUnk_092EB78A);
    gUnk_02034FDC->palette7 = LoadObjPalette(gUnk_09618118, 32);
    gUnk_02034FDC->palette3 = LoadObjPalette(gUnk_09991D24, 32);
    gUnk_02034FDC->tiles3 = LoadObjTiles(&gUnk_098A8F28[0x62], 0x4C0);
    gUnk_02034FDC->palette = LoadObjPalette(gUnk_09991BE4, 32);
#ifdef VERSION_EU
    gUnk_02034FDC->tiles = AllocObjTiles(0x120, &gUnk_098A8628[0x120E]);
#else
    gUnk_02034FDC->tiles = AllocObjTiles(0x120, &gUnk_098A8628[0x4BA]);
#endif
    AnimInit(&gUnk_02034FDC->anim, gUnk_09EF8D88, gUnk_09EF8D78);
    AnimStart(&gUnk_02034FDC->anim, 0, 1);
    gUnk_02034FDC->palette8 = LoadObjPalette(gUnk_09991C04, 32);
    gUnk_02034FDC->unk_160 = 0;
    InitTextSlots(&gUnk_02034FDC->unk_040, 36);
    InitTextSlots(&gUnk_02034FDC->unk_168, 54);
    gUnk_02034FDC->palette9 = LoadObjPalette(gUnk_09991BE4, 32);
#ifdef VERSION_EU
    gUnk_02034FDC->unk_318 = LoadTextSlots(eu_0805E924(gUnkEu_08892780), &gUnk_02034FDC->unk_168);
#else
    gUnk_02034FDC->unk_318 = LoadTextSlots(gUnk_08159E1E, &gUnk_02034FDC->unk_168);
#endif

    if (gUnk_02034FDC->unk_33D != 0) {
        v = func_080EAD3C(2);
        u = func_080EAD3C(3);
    } else {
        v = func_080EAD3C(0);
        u = func_080EAD3C(1);
    }

    if (v != 0) {
        gUnk_02034FDC->selectedSlot = u == 0 ? 1 : 0;
    } else {
        gUnk_02034FDC->selectedSlot = 0;
    }

    func_080EAD84(gUnk_02034FDC->selectedSlot);
    gUnk_02034FDC->y3 = (gUnk_02034FDC->unk_162 + gUnk_02034FDC->selectedSlot * 45) << 8;
    FadeStartIn(0, 8);
}

void Mode_MenuNew_1(void) {
    if (gUnk_02034FDC->update != 0) {
        gUnk_02034FDC->update(gUnk_02034FDC);
    }
    func_080EAF10();
}

void Mode_MenuNew_2(void) {
    ReleaseObjPalette(gUnk_02034FDC->palette2);
    ReleaseObjTiles(gUnk_02034FDC->tiles2);
    ReleaseObjPalette(gUnk_02034FDC->palette3);
    ReleaseObjTiles(gUnk_02034FDC->tiles3);
    ReleaseObjPalette(gUnk_02034FDC->palette);
    ReleaseObjTiles(gUnk_02034FDC->tiles);
    ReleaseObjPalette(gUnk_02034FDC->palette4);
    ReleaseObjTiles(gUnk_02034FDC->tiles4);
    ReleaseObjPalette(gUnk_02034FDC->palette5);
    ReleaseObjTiles(gUnk_02034FDC->tiles5);
    ReleaseObjPalette(gUnk_02034FDC->palette6);
    ReleaseObjTiles(gUnk_02034FDC->tiles6);
    ReleaseObjPalette(gUnk_02034FDC->palette7);
    ReleaseObjTiles(gUnk_02034FDC->tiles7);
    ReleaseObjPalette((u8*)gUnk_02034FDC->palette8);
    FreeTextSlots(gUnk_02034FDC->unk_040, 36);
    ReleaseObjPalette(gUnk_02034FDC->palette9);
    FreeTextSlots(gUnk_02034FDC->unk_168, 54);
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

void func_080EB818(u8 a, u8 b, u8 c) {
    const u8* src;

#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        if (a <= 1) {
            if (b != 0) {
                src = gUnkEu_09955250[c];
            } else {
                src = gUnkEu_099563D0[c];
            }
        } else {
            if (b != 0) {
                src = gUnkEu_09957550[c];
            } else {
                src = gUnkEu_099586D0[c];
            }
        }
        break;
    case 1:
        if (a <= 1) {
            if (b != 0) {
                src = gUnkEu_09959850[c];
            } else {
                src = gUnkEu_0995A9D0[c];
            }
        } else {
            if (b != 0) {
                src = gUnkEu_0995BB50[c];
            } else {
                src = gUnkEu_0995CCD0[c];
            }
        }
        break;
    case 4:
        if (a <= 1) {
            if (b != 0) {
                src = gUnkEu_0995DE50[c];
            } else {
                src = gUnkEu_0995EFD0[c];
            }
        } else {
            if (b != 0) {
                src = gUnkEu_09960150[c];
            } else {
                src = gUnkEu_099612D0[c];
            }
        }
        break;
    case 3:
        if (a <= 1) {
            if (b != 0) {
                src = gUnkEu_09962450[c];
            } else {
                src = gUnkEu_099635D0[c];
            }
        } else {
            if (b != 0) {
                src = gUnkEu_09964750[c];
            } else {
                src = gUnkEu_099658D0[c];
            }
        }
        break;
    case 2:
    default:
        if (a <= 1) {
            if (b != 0) {
                src = gUnkEu_09966A50[c];
            } else {
                src = gUnkEu_09967BD0[c];
            }
        } else {
            if (b != 0) {
                src = gUnkEu_09968D50[c];
            } else {
                src = gUnkEu_09969ED0[c];
            }
        }
        break;
    }
#else
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
#endif
    RequestDma3Copy((void*)src, (u8*)GetBgCharBase(1) + (a * 608 + 320), 320);
}

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
    SaveFileSummary* e = &gGameState.fileSummaries[a];

    if (e->level != 0) {
        func_080EB898(a, e->level);
        func_080EB93C(a, e->playTime);
        func_080EB818(a, 0, e->floor);
    } else {
        func_080EB818(a, 0, 13);
    }
}

void func_080EBA58(u8 a) {
    SaveFileSummary* e = &gGameState.fileSummaries[a];

    if (e->level != 0) {
        func_080EB818(a, 1, e->floor);
        gUnk_02034FE0->unk_15C = LoadTextSlots((void*)func_080DF804(e->world), &gUnk_02034FE0->unk_03C);

        if (a <= 1) {
            LoadObjPaletteBank(gUnk_02034FE0->palette7->unk_06, &gUnk_099910C4[0xB40]);
        } else {
            LoadObjPaletteBank(gUnk_02034FE0->palette7->unk_06, &gUnk_099910C4[0xB80]);
        }
    } else {
        func_080EB818(a, 1, 13);
        gUnk_02034FE0->unk_15C = 0;
    }
}

void func_080EBAE0(u8 a) {
    SaveFileSummary* e = &gGameState.fileSummaries[a];

    if (e->level != 0) {
        func_080EB818(a, 0, e->floor);
    } else {
        func_080EB818(a, 0, 13);
    }
    gUnk_02034FE0->unk_15C = 0;
}

void func_080EBB24(void) {
    s32 t;
    s32 u;
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        DrawSprite(128, gUnk_02034FE0->y >> 8, gUnk_09EF8D68[1], gUnk_02034FE0->tiles2,
            gUnk_02034FE0->palette2, 0, 0xC00, 90);
        DrawSprite(128, gUnk_02034FE0->y2 >> 8, gUnk_09EF8D68[2], gUnk_02034FE0->tiles2,
            gUnk_02034FE0->palette2, 0, 0xC00, 90);
        DrawSprite(gUnk_02034FE0->x >> 8, 0, gUnk_09EF8D68[0], gUnk_02034FE0->tiles2,
            gUnk_02034FE0->palette2, 0, 0xC00, 80);
        break;
    case 1:
        DrawSprite(128, gUnk_02034FE0->y >> 8, gUnkEu_09F843D8[1], gUnk_02034FE0->tiles2,
            gUnk_02034FE0->palette2, 0, 0xC00, 90);
        DrawSprite(128, gUnk_02034FE0->y2 >> 8, gUnkEu_09F843D8[2], gUnk_02034FE0->tiles2,
            gUnk_02034FE0->palette2, 0, 0xC00, 90);
        DrawSprite(gUnk_02034FE0->x >> 8, 0, gUnkEu_09F843D8[0], gUnk_02034FE0->tiles2,
            gUnk_02034FE0->palette2, 0, 0xC00, 80);
        break;
    case 4:
        DrawSprite(128, gUnk_02034FE0->y >> 8, gUnkEu_09F843E8[1], gUnk_02034FE0->tiles2,
            gUnk_02034FE0->palette2, 0, 0xC00, 90);
        DrawSprite(128, gUnk_02034FE0->y2 >> 8, gUnkEu_09F843E8[2], gUnk_02034FE0->tiles2,
            gUnk_02034FE0->palette2, 0, 0xC00, 90);
        DrawSprite(gUnk_02034FE0->x >> 8, 0, gUnkEu_09F843E8[0], gUnk_02034FE0->tiles2,
            gUnk_02034FE0->palette2, 0, 0xC00, 80);
        break;
    case 3:
        DrawSprite(128, gUnk_02034FE0->y >> 8, gUnkEu_09F843F8[1], gUnk_02034FE0->tiles2,
            gUnk_02034FE0->palette2, 0, 0xC00, 90);
        DrawSprite(128, gUnk_02034FE0->y2 >> 8, gUnkEu_09F843F8[2], gUnk_02034FE0->tiles2,
            gUnk_02034FE0->palette2, 0, 0xC00, 90);
        DrawSprite(gUnk_02034FE0->x >> 8, 0, gUnkEu_09F843F8[0], gUnk_02034FE0->tiles2,
            gUnk_02034FE0->palette2, 0, 0xC00, 80);
        break;
    case 2:
    default:
        DrawSprite(128, gUnk_02034FE0->y >> 8, gUnkEu_09F84408[1], gUnk_02034FE0->tiles2,
            gUnk_02034FE0->palette2, 0, 0xC00, 90);
        DrawSprite(128, gUnk_02034FE0->y2 >> 8, gUnkEu_09F84408[2], gUnk_02034FE0->tiles2,
            gUnk_02034FE0->palette2, 0, 0xC00, 90);
        DrawSprite(gUnk_02034FE0->x >> 8, 0, gUnkEu_09F84408[0], gUnk_02034FE0->tiles2,
            gUnk_02034FE0->palette2, 0, 0xC00, 80);
        break;
    }
#else
    DrawSprite(128, gUnk_02034FE0->y >> 8, gUnk_09EF8D68[1], gUnk_02034FE0->tiles2,
        gUnk_02034FE0->palette2, 0, 0xC00, 90);
    DrawSprite(128, gUnk_02034FE0->y2 >> 8, gUnk_09EF8D68[2], gUnk_02034FE0->tiles2,
        gUnk_02034FE0->palette2, 0, 0xC00, 90);
    DrawSprite(gUnk_02034FE0->x >> 8, 0, gUnk_09EF8D68[0], gUnk_02034FE0->tiles2,
        gUnk_02034FE0->palette2, 0, 0xC00, 80);
#endif

    if (gUnk_02034FE0->selectedSlot <= 1) {
        DrawSprite(56, 112, ((void**)gUnk_09EDE8CC)[0], gUnk_02034FE0->tiles3,
            gUnk_02034FE0->palette3, 0, 0x400, 80);
        DrawSprite(72, 96, ((void**)gUnk_09EEE03C)[0], gUnk_02034FE0->tiles4,
            gUnk_02034FE0->palette4, 0, 0x401, 81);
        DrawSprite(40, 96, ((void**)gUnk_09EEE1C8)[0], gUnk_02034FE0->tiles5,
            gUnk_02034FE0->palette5, 0, 0x400, 81);
    } else {
        DrawSprite(56, 112, gUnk_09EEF89C[0], gUnk_02034FE0->tiles6, gUnk_02034FE0->palette6, 0,
            0x400, 81);
    }

    if (gUnk_02034FE0->unk_180 != 0) {
        t = 32;
    } else {
        t = 45;
    }

    u = t * gUnk_02034FE0->selectedSlot;
    ApproachValueHalf(&gUnk_02034FE0->y3, (gUnk_02034FE0->unk_15E + u) << 8);
    DrawSprite(76, gUnk_02034FE0->y3 >> 8, AnimGetGfx(&gUnk_02034FE0->anim),
        gUnk_02034FE0->tiles, gUnk_02034FE0->palette, 0, 0x400, 70);
    DrawTextSlots(100, u + (gUnk_02034FE0->unk_15E + 22), &gUnk_02034FE0->unk_03C,
        gUnk_02034FE0->palette7, 50, gUnk_02034FE0->unk_15C);
}

void func_080EBD00(LoadGameMenuWork* w) {
    u8 old = w->selectedSlot;

    if (GetKeysRepeat() & 0x40) {
        w->selectedSlot = w->selectedSlot != 0 ? w->selectedSlot - 1 : w->unk_184;
        m4aSongNumStart(0x65);
    }

    if (GetKeysRepeat() & 0x80) {
        w->selectedSlot = w->selectedSlot < w->unk_184 ? w->selectedSlot + 1 : 0;
        m4aSongNumStart(0x65);
    }

    if (old != w->selectedSlot) {
        func_080EBAE0(old);
        func_080EBA58(w->selectedSlot);

        switch (w->selectedSlot) {
        case 0:
            if (w->unk_180 != 0) {
                LoadBgMap(1, &gUnk_09985F44[0x3000], 0x800);
                SetBgScroll(1, 0, (u16)-1);
            } else {
                LoadBgMap(1, &gUnk_09985F44[0x2000], 0x800);
                SetBgScroll(1, 0, (u16)-3);
            }
            break;
        case 1:
            if (w->unk_180 != 0) {
                LoadBgMap(1, &gUnk_09985F44[0x3800], 0x800);
                SetBgScroll(1, 0, (u16)-1);
            } else {
                LoadBgMap(1, &gUnk_09985F44[0x2800], 0x800);
                SetBgScroll(1, 0, 0);
            }
            break;
        case 2:
            LoadBgMap(1, &gUnk_09985F44[0x4000], 0x800);
            SetBgScroll(1, 0, (u16)-1);
            break;
        case 3:
            LoadBgMap(1, &gUnk_09985F44[0x4800], 0x800);
            SetBgScroll(1, 0, (u16)-1);
            break;
        }
    }
}

void func_080EBE44(LoadGameMenuWork* work) {
    if (work->timer != 0) {
        ApproachValue(&work->y, 0, work->timer);
        ApproachValue(&work->y2, 0x9800, work->timer);
        work->timer--;
    } else {
        work->timer = 16;
        work->update = func_080EBE90;
    }
}

void func_080EBE90(LoadGameMenuWork* work) {
    if (work->timer != 0) {
        ApproachValue(&work->x, 0, work->timer);
        work->timer--;
    } else {
        work->update = func_080EBEC8;
    }
}

void func_080EBEC8(LoadGameMenuWork* work) {
    func_080EBD00(work);

    if (GetKeysPressed() & 2) {
        work->timer = 16;
        work->update = func_080EBFB8;
        m4aSongNumStart(0x68);
    } else if (GetKeysPressed() & 9) {
        if ((u8)func_080EB7A0(work->selectedSlot) != 0) {
            switch (work->selectedSlot) {
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
            work->timer = 16;
            work->update = func_080EBFB8;
        } else {
            m4aSongNumStart(0x69);
        }
    }
}

void func_080EBFB8(LoadGameMenuWork* work) {
    if (work->timer != 0) {
        ApproachValue(&work->x, -0x8000, work->timer);
        work->timer--;
    } else {
        work->timer = 16;
        work->update = func_080EBFF8;
    }
}

void func_080EBFF8(LoadGameMenuWork* work) {
    if (work->timer != 0) {
        ApproachValue(&work->y, -0x800, work->timer);
        ApproachValue(&work->y2, 0xA000, work->timer);
        work->timer--;
    } else {
        FadeStartOut(0, 16);
        work->update = func_080EC04C;
    }
}

void func_080EC04C(LoadGameMenuWork* work) {
#ifdef VERSION_EU
    SaveFileSummary* e = &gGameState.fileSummaries[work->selectedSlot];
#endif

    if ((u8)FadeIsActive() != 0) {
        return;
    }

    if (work->unk_181 != 0) {
        if (work->unk_182 != 0) {
            ModeRequest(&gModeSioBattle, 1);
        } else {
            ModeRequest(&gModeSioBattle, 0);
        }
    } else if (work->unk_182 != 0) {
#ifdef VERSION_EU
        if (e->world != 13) {
#else
        if (gUnk_0203C590.unk_04 != 13) {
#endif
            func_080E04EC();
        } else {
            ModeRequest(&gModePooh, 2);
        }
    } else {
        ModeRequest(&gModeTitle, 0);
    }
}

void Mode_MenuLoad_0(s32 arg) {
    s32 i;

    gUnk_02034FE0 = EwramAlloc(0x18C);
    gUnk_02034FE0->unk_181 = arg != 0;

    if (gUnk_02034FE0->unk_181 != 0) {
        gUnk_02034FE0->unk_180 = 0;
    } else {
        gUnk_02034FE0->unk_180 = (gGameState.flags >> 5) & 1;
    }

    gUnk_02034FE0->unk_182 = 0;
    gUnk_02034FE0->selectedSlot = 0;

    if (gUnk_02034FE0->unk_180 != 0) {
        gUnk_02034FE0->unk_184 = 3;
        gUnk_02034FE0->unk_15E = 17;
        gUnk_02034FE0->y3 = gUnk_02034FE0->unk_15E << 8;
    } else {
        gUnk_02034FE0->unk_184 = 1;
        gUnk_02034FE0->unk_15E = 43;
        gUnk_02034FE0->y3 = gUnk_02034FE0->unk_15E << 8;
    }

    gUnk_02034FE0->timer = 16;
    gUnk_02034FE0->update = func_080EBE44;
    SetBgMode0();
    SetupBg(3, 0, 28, 0);
    SetupBg(2, 0, 29, 0);
    SetupBg(1, 0, 30, 0);
    SetupBg(0, 3, 31, 0);
#ifdef VERSION_EU
    LoadBgTiles(1, gUnk_09959A64, 0x8000);
    switch (gLanguage) {
    case 1:
        RequestDma3Copy((void*)gUnk_09961A64, (u8*)GetBgCharBase(1) + 0xC00, 0x800);
        break;
    case 4:
        RequestDma3Copy((void*)gUnkEu_09953BF0, (u8*)GetBgCharBase(1) + 0xC00, 0x800);
        break;
    case 3:
        RequestDma3Copy((void*)gUnkEu_099543F0, (u8*)GetBgCharBase(1) + 0xC00, 0x800);
        break;
    case 2:
        RequestDma3Copy((void*)gUnkEu_09954BF0, (u8*)GetBgCharBase(1) + 0xC00, 0x800);
        break;
    }
    LoadBgPalette(3, gUnk_099919C4, 0x200);
    LoadBgMap(3, gUnk_09986F44, 0x800);
    LoadBgPalette(2, gUnk_099919C4, 0x200);
    LoadBgMap(2, gUnk_09987744, 0x800);
    LoadBgPalette(1, gUnk_099919C4, 0x200);
#else
    LoadBgTiles(3, gUnk_09959A64, 0x8000);
    LoadBgPalette(3, gUnk_099919C4, 0x200);
    LoadBgMap(3, gUnk_09986F44, 0x800);
    LoadBgTiles(2, gUnk_09959A64, 0x8000);
    LoadBgPalette(2, gUnk_099919C4, 0x200);
    LoadBgMap(2, gUnk_09987744, 0x800);
    LoadBgTiles(1, gUnk_09959A64, 0x8000);
    LoadBgPalette(1, gUnk_099919C4, 0x200);
#endif

    if (gUnk_02034FE0->unk_180 != 0) {
        LoadBgMap(1, gUnk_09988F44, 0x800);
        SetBgScroll(1, 0, 0xFFFF);
    } else {
        LoadBgMap(1, gUnk_09987F44, 0x800);
        SetBgScroll(1, 0, 0xFFFD);
    }

    gUnk_02034FE0->palette2 = LoadObjPalette(gUnk_09991BC4, 32);
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        gUnk_02034FE0->tiles2 = LoadObjTiles(gUnkEu_09885EEA, 0x2C0);
        break;
    case 1:
        gUnk_02034FE0->tiles2 = LoadObjTiles(gUnkEu_0988519C, 0x300);
        break;
    case 4:
        gUnk_02034FE0->tiles2 = LoadObjTiles(gUnkEu_0988551E, 0x2C0);
        break;
    case 3:
        gUnk_02034FE0->tiles2 = LoadObjTiles(gUnkEu_09885862, 0x2C0);
        break;
    case 2:
    default:
        gUnk_02034FE0->tiles2 = LoadObjTiles(gUnkEu_09885BA6, 0x2C0);
        break;
    }
#else
    gUnk_02034FE0->tiles2 = LoadObjTiles(gUnk_098A87AA, 0x2C0);
#endif
    gUnk_02034FE0->y = -0x800;
    gUnk_02034FE0->y2 = 0xA000;
    gUnk_02034FE0->x = -0x8000;
    gUnk_02034FE0->tiles3 = AllocObjTiles(0x340, gUnk_088B6560);
    gUnk_02034FE0->palette3 = LoadObjPalette(gUnk_08F683A4, 32);
    gUnk_02034FE0->tiles4 = AllocObjTiles(0x280, gUnk_0919FDF8);
    gUnk_02034FE0->palette4 = LoadObjPalette(gUnk_09617C58, 32);
    gUnk_02034FE0->tiles5 = AllocObjTiles(0x400, gUnk_091ABDB8);
    gUnk_02034FE0->palette5 = LoadObjPalette(gUnk_08F68384, 32);
    gUnk_02034FE0->tiles6 = AllocObjTiles(0x400, gUnk_092EB78A);
    gUnk_02034FE0->palette6 = LoadObjPalette(gUnk_09618118, 32);
    gUnk_02034FE0->palette = LoadObjPalette(gUnk_09991BE4, 32);
#ifdef VERSION_EU
    gUnk_02034FE0->tiles = AllocObjTiles(0x120, &gUnk_098A8628[0x120E]);
#else
    gUnk_02034FE0->tiles = AllocObjTiles(0x120, gUnk_098A8AE2);
#endif
    AnimInit(&gUnk_02034FE0->anim, gUnk_09EF8D88, gUnk_09EF8D78);
    AnimStart(&gUnk_02034FE0->anim, 0, 1);
    gUnk_02034FE0->palette7 = LoadObjPalette(gUnk_09991C04, 32);
    gUnk_02034FE0->unk_15C = 0;
    InitTextSlots(gUnk_02034FE0->unk_03C, 36);

    for (i = 0; i < 4; i++) {
        func_080EBA14(i);
    }

    func_080EBA58(gUnk_02034FE0->selectedSlot);
    FadeStartIn(0, 16);
}

void Mode_MenuLoad_1(void) {
    if (gUnk_02034FE0->update != 0) {
        gUnk_02034FE0->update(gUnk_02034FE0);
    }
    func_080EBB24();
}

void Mode_MenuLoad_2(void) {
    ReleaseObjPalette(gUnk_02034FE0->palette2);
    ReleaseObjTiles(gUnk_02034FE0->tiles2);
    ReleaseObjPalette(gUnk_02034FE0->palette);
    ReleaseObjTiles(gUnk_02034FE0->tiles);
    ReleaseObjPalette(gUnk_02034FE0->palette3);
    ReleaseObjTiles(gUnk_02034FE0->tiles3);
    ReleaseObjPalette(gUnk_02034FE0->palette4);
    ReleaseObjTiles(gUnk_02034FE0->tiles4);
    ReleaseObjPalette(gUnk_02034FE0->palette5);
    ReleaseObjTiles(gUnk_02034FE0->tiles5);
    ReleaseObjPalette(gUnk_02034FE0->palette6);
    ReleaseObjTiles(gUnk_02034FE0->tiles6);
    ReleaseObjPalette((u8*)gUnk_02034FE0->palette7);
    FreeTextSlots(gUnk_02034FE0->unk_03C, 36);
    EwramFree(gUnk_02034FE0);
}

void func_080EC500(UnkStruct_02034FE4* w) {
    if (func_080A42C8() == 0) {
        if (w->unk_00 == 0) {
            func_080C75A4(1, 16);
            FadeStartOut(1, 16);
        } else {
            func_080C75A4(0, 16);
            FadeStartOut(0, 16);
        }
        w->update = func_080EC544;
    }
}

void func_080EC544(UnkStruct_02034FE4* w) {
    if (FadeIsActive() == 0) {
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
    TaskPoolInit(&gUnk_02034FE4->tasks, 1);

    if (gUnk_02034FE4->unk_00 == 0) {
        func_080A4188(&gUnk_02034FE4->tasks, 0xB0);
        func_080C736C();
        func_080C73A4(0, 0, 0);
        func_080C7568(1, 16);
        FadeStartIn(1, 16);
        FadeLock();
    } else {
#ifdef VERSION_EU
        func_080A4188(&gUnk_02034FE4->tasks, 0xB2);
#else
        func_080A4188(&gUnk_02034FE4->tasks, 0xB3);
#endif
        func_080C736C();
        func_080C73A4(0, 0, 0);
        func_080C7568(0, 1);
        FadeStartIn(0, 1);
        FadeLock();
    }
    gUnk_02034FE4->update = func_080EC500;
}

void Mode_MenuMsg_1(void) {
    gUnk_02034FE4->update(gUnk_02034FE4);
    TaskPoolUpdate(&gUnk_02034FE4->tasks);
    TaskPoolDraw(&gUnk_02034FE4->tasks);
    func_080C73D8();
}

void Mode_MenuMsg_2(void) {
    TaskPoolDestroy(&gUnk_02034FE4->tasks);
    EwramFree(gUnk_02034FE4);
}

void Task_MapRnd_0(MapRndWork* w) {
    UnkStruct_09EF70D0* r = gUnk_09EF70D0[gUnk_0203C590.unk_04];
    s32 i;

    TaskPoolInit(&w->tasks, 4);
    LoadBgTiles(3, r->tiles, r->tilesSize);
    LoadBgTiles(2, r->tiles, r->tilesSize);
    LoadBgTiles(1, r->tiles2, r->tilesSize2);
    LoadBgPalette(3, r->palette, r->paletteSize);
    LoadBgPalette(2, r->palette, r->paletteSize);
    LoadBgPalette(1, r->palette, r->paletteSize);
    gUnk_0203C7AC->unk_04 = func_080E5564();
    gUnk_0203C7AC->unk_06 = 64;
    gUnk_02039BA0->unk_10 = gUnk_0203C7AC->unk_04 * 4;
    gUnk_02039BA0->unk_12 = gUnk_0203C7AC->unk_06 * 2;
    func_080E49DC(gUnk_0203C7AC->unk_04, gUnk_0203C7AC->unk_06);

    for (i = 0; i < 4; i++) {
        MapCell* e = func_080DFB7C(i);

        if (e->unk_00 & 1) {
            if ((e->unk_00 & 8) == 0) {
                TaskCreate(&w->tasks, &gTaskDescMapDoor, e);
            }
        }
    }
}

s32 Task_MapRnd_1(MapRndWork* w) {
    func_080E00E4(gUnk_02039BA0->x2, gUnk_02039BA0->y2);
    TaskPoolUpdate(&w->tasks);
    return 1;
}

void Task_MapRnd_2(TaskPool* pool) {
    TaskPoolDraw(pool);
}

void Task_MapRnd_3(TaskPool* pool) {
    TaskPoolDestroy(pool);
    func_080E4B34();
}

void func_080EC760(MapFixWork* p, UnkStruct_080EC760Entry* q) {
    s32 i;

    p->unk_00 = 0;

    if (q != 0) {
        i = 0;

        do {
            if (q->unk_00 != 0) {
                ColliderInit(p->unk_04[i], 6, q->unk_00, 0xA0);
                ColliderSetPosition(p->unk_04[i], q->unk_04, q->unk_08, 0);
                p->unk_00++;
            } else {
                break;
            }
            q++;
            i++;
        } while (i < 5);
    }
}

void Task_MapFix_0(MapFixWork* w, UnkStruct_09EF8370* p) {
    UnkStruct_080EF4BC v;

    switch (gUnk_0203C590.unk_07) {
    case 0:
        gUnk_02039BA0->unk_E4 = 173;
        gUnk_02039BA0->unk_DC = p->unk_38 - 0xC00;
        gUnk_02039BA0->unk_E0 = p->unk_3C + 0x800;
        break;
    case 1:
        gUnk_02039BA0->unk_E4 = 45;
        gUnk_02039BA0->unk_DC = p->unk_40 + 0xC00;
        gUnk_02039BA0->unk_E0 = p->unk_44 - 0x800;
        break;
    default:
        gUnk_02039BA0->unk_E4 = 45;
        gUnk_02039BA0->unk_DC = p->unk_48;
        gUnk_02039BA0->unk_E0 = p->unk_4C;
        break;
    }

#ifdef VERSION_EU
    w->unk_1E6 = 0;
    w->unk_1E5 = 0;
    w->unk_1E4 = 0;

    if (p->unk_50 == 0) {
        eu_080059D4(3, p->tiles);
    } else {
        LoadBgTiles(3, p->tiles, p->tilesSize);
    }
#else
    LoadBgTiles(3, p->tiles, p->tilesSize);
#endif
    LoadBgPalette(3, p->palette, p->paletteSize);
#ifdef VERSION_EU
    eu_08005A1C(3, p->map3, p->mapWidth, p->mapHeight);
    w->unk_1E4 = 1;
#else
    SetBgMapBlocks(3, p->map3, p->mapWidth, p->mapHeight);
#endif

    if (p->map2 != 0) {
#ifdef VERSION_EU
        if (p->unk_50 == 0) {
            eu_080059D4(2, p->tiles);
        } else {
            LoadBgTiles(2, p->tiles, p->tilesSize);
        }
#else
        LoadBgTiles(2, p->tiles, p->tilesSize);
#endif
        LoadBgPalette(2, p->palette, p->paletteSize);
#ifdef VERSION_EU
        eu_08005A1C(2, p->map2, p->mapWidth, p->mapHeight);
        w->unk_1E5 = 1;
#else
        SetBgMapBlocks(2, p->map2, p->mapWidth, p->mapHeight);
#endif
    } else {
        DisableBg(2);
    }

    if (p->map != 0) {
#ifdef VERSION_EU
        if (p->unk_50 == 0) {
            eu_080059D4(1, p->tiles2);
        } else {
            LoadBgTiles(1, p->tiles2, p->tilesSize2);
        }
#else
        LoadBgTiles(1, p->tiles2, p->tilesSize2);
#endif
        LoadBgPalette(1, p->palette, p->paletteSize);
#ifdef VERSION_EU
        eu_08005A1C(1, p->map, p->mapWidth, p->mapHeight);
        w->unk_1E6 = 1;
#else
        SetBgMapBlocks(1, p->map, p->mapWidth, p->mapHeight);
#endif
    } else {
        DisableBg(1);
    }

    gUnk_02039BA0->unk_10 = p->mapWidth * 32;
    gUnk_02039BA0->unk_12 = p->mapHeight * 32;
    gUnk_0203C7AC->unk_04 = gUnk_02039BA0->unk_10 / 4;
    gUnk_0203C7AC->unk_06 = gUnk_02039BA0->unk_12 / 2;
    func_080E5868(p);
    TaskPoolInit(&w->tasks, 2);
    v.unk_00 = p->unk_38;
    v.unk_04 = p->unk_3C;
    v.unk_14 = 45;
    TaskCreate(&w->tasks, &gTaskDescMapStair, &v);

    if (p->unk_40 != 0 || p->unk_44 != 0) {
        v.unk_00 = p->unk_40;
        v.unk_04 = p->unk_44;
        v.unk_14 = 173;
        TaskCreate(&w->tasks, &gTaskDescMapStair, &v);
    }

    func_080EC760(w, p->unk_30);
}

s32 Task_MapFix_1(u8* work) {
    s32 tx = gUnk_02039BA0->x2 - 0x7800;
    s32 ty = gUnk_02039BA0->y2 - 0x6000;

    gUnk_02039BA0->x += (tx - gUnk_02039BA0->x) / 8;
    gUnk_02039BA0->y += (ty - gUnk_02039BA0->y) / 8;

    if (gUnk_02039BA0->x < 0) {
        gUnk_02039BA0->x = 0;
    }

    if (gUnk_02039BA0->y < 0) {
        gUnk_02039BA0->y = 0;
    }

    if (gUnk_02039BA0->x + 0xF000 > gUnk_02039BA0->unk_10 << 11) {
        gUnk_02039BA0->x = (gUnk_02039BA0->unk_10 << 11) - 0xF000;
    }

    if (gUnk_02039BA0->y + 0xA000 > gUnk_02039BA0->unk_12 << 11) {
        gUnk_02039BA0->y = (gUnk_02039BA0->unk_12 << 11) - 0xA000;
    }
    TaskPoolUpdate((TaskPool*)&work[0x1D0]);
    return 1;
}

void Task_MapFix_2(u8* work) {
    ScrollBgMapTo(3, gUnk_02039BA0->x >> 8, gUnk_02039BA0->y >> 8);
    ScrollBgMapTo(2, gUnk_02039BA0->x >> 8, gUnk_02039BA0->y >> 8);

    if ((gUnk_0203C7AC->unk_00 & 1) == 0) {
        ScrollBgMapTo(1, gUnk_02039BA0->x >> 8, gUnk_02039BA0->y >> 8);
    }
    TaskPoolDraw((TaskPool*)&work[0x1D0]);
}

void Task_MapFix_3(u8* work) {
    s32 i;

    for (i = 0; i < work[0]; i++) {
        ColliderUnregister(&work[4 + i * 92]);
    }

#ifdef VERSION_EU
    if (work[0x1E4] != 0) {
        eu_08005ADC(3);
    }

    if (work[0x1E5] != 0) {
        eu_08005ADC(2);
    }

    if (work[0x1E6] != 0) {
        eu_08005ADC(1);
    }
#endif

    TaskPoolDestroy((TaskPool*)&work[0x1D0]);
    func_080E58E4();
}

void func_080ECA88(MapDoorWork* p) {
    UpdateSpriteFrameTiles(p->tiles, p->unk_4C, p->unk_54);
    UpdateSpriteFrameTiles(p->tiles2, p->unk_60, p->unk_64);
}

void func_080ECAA8(MapDoorWork* p) {
    UpdateSpriteFrameTiles(p->tiles, p->unk_4C, p->unk_50);
    UpdateSpriteFrameTiles(p->tiles2, p->unk_60, p->unk_68);
}

s32 func_080ECAC8(MapDoorWork* p) {
    UnkStruct_080DFB7C* flags = p->unk_00;
    UnkStruct_080DFF1C* e = (UnkStruct_080DFF1C*)&p->unk_04;

    if (!(gUnk_02039BA0->unk_70 & 0x2000) && !(gUnk_0203C7AC->unk_00 & 0x4004) &&
        (u8)(flags->unk_07 + 3) > 1 && (flags->unk_00 & 0x12) != 0x12 &&
        func_080E02E0(e, 0, 8) != 0 && !(gUnk_02039BA0->unk_70 & 0x800000) &&
        gUnk_02039BA0->actor.fieldPosition.z == gUnk_02039BA0->actor.fieldPosition.unk_0C) {
        TaskPool* pool;

        m4aSongNumStart(0xDC);
        pool = &p->tasks;
        TaskCreate(pool, &gTaskDescMapSpark, e);
        gUnk_0203C7AC->unk_00 |= 0x80;
        gUnk_02039BA0->unk_68 = (s32)e;
        gUnk_0203C7AC->unk_14 = (s32)e;
        p->unk_71 = 1;
        p->update = func_080ECBC8;
        gUnk_0203C7AC->unk_0F = flags->unk_07;
        gUnk_0203C7AC->unk_10 = flags->unk_06;
        FadeSetPaletteExcluded(*(u16*)&p->palette[6] + 16, 1);
        FadeSetPaletteExcluded(*(u16*)&p->palette2[6] + 16, 1);
        TaskCreate(pool, &gTaskDescRoomcreate, 0);
    }
    return 1;
}

s32 func_080ECBC8(MapDoorWork* p) {
    UnkStruct_080DFB7C* flags = p->unk_00;
    void* t = func_08093BF8();

    if (t != 0) {
        if (flags->unk_00 & 0x10) {
            func_080DF640(flags->unk_07, 0);
        } else {
            func_080DF640(flags->unk_07, t);
        }
        p->update = func_080ECC54;
    }

    if (!(gUnk_02039BA0->unk_70 & 0x40000)) {
        gUnk_0203C7AC->unk_00 &= ~0x80;
        FadeSetPaletteExcluded(*(u16*)&p->palette[6] + 16, 0);
        FadeSetPaletteExcluded(*(u16*)&p->palette2[6] + 16, 0);
        p->update = func_080ECAC8;
    }
    return 1;
}

s32 func_080ECC54(MapDoorWork* p) {
    UnkStruct_080DFB7C* flags = p->unk_00;
    u16 v;

    if (gUnk_02039BA0->unk_70 & 0x200000) {
        func_080ECA88(p);
        v = flags->unk_00 | 2;
        flags->unk_00 = v;
        p->update = func_080ECC8C;
    }

    return 1;
}

u8 func_080ECC8C(MapDoorWork* p) {
    return 1;
}

void Task_MapDoor_0(MapDoorWork* w, UnkStruct_080DFB7C* p) {
    UnkStruct_080E6394* e = (UnkStruct_080E6394*)&w->unk_04;
    UnkStruct_080DFF1C* v = &e->unk_00;
    const UnkStruct_0984B968* q = &gUnk_0984B968[gUnk_0203C590.unk_04];

    w->unk_00 = p;
    w->unk_71 = 0;
    w->unk_70 = 1;

    switch (p->unk_06) {
    case 0:
        w->unk_4C = gUnk_098A94A0;
        w->unk_54 = q->unk_08;
        w->unk_50 = q->unk_04;
        e->unk_14 = 173;
        w->unk_04 = (p->unk_02 << 5) + 16;
        e->unk_00.x = (p->unk_04 << 4) + 10;
        break;
    case 1:
        w->unk_4C = gUnk_098A94B4;
        w->unk_54 = q->unk_20;
        w->unk_50 = q->unk_1C;
        e->unk_14 = 45;
        w->unk_04 = (p->unk_02 << 5) + 16;
        e->unk_00.x = (p->unk_04 << 4) + 6;
        break;
    case 2:
        w->unk_4C = gUnk_098A94C8;
        w->unk_54 = q->unk_18;
        w->unk_50 = q->unk_14;
        e->unk_14 = 211;
        w->unk_04 = (p->unk_02 << 5) + 16;
        e->unk_00.x = (p->unk_04 << 4) + 6;
        break;
    case 3:
        w->unk_4C = gUnk_098A948C;
        w->unk_54 = q->unk_10;
        w->unk_50 = q->unk_0C;
        e->unk_14 = 83;
        w->unk_04 = (p->unk_02 << 5) + 16;
        e->unk_00.x = (p->unk_04 << 4) + 10;
        break;
    }

    v->unk_00 <<= 8;
    v->x <<= 8;
    v->y = 0;
    v->y = v->z = func_080DFF30(v);
    v->x -= v->y;
    e->unk_1A = 32;
    e->unk_30 = 3;
    w->tiles = AllocSpriteFrameTiles(0x400);
    w->palette = LoadObjPalette(q->unk_00, 32);
    w->palette2 = LoadObjPalette(gUnk_09991284, 32);
    w->tiles2 = AllocSpriteFrameTiles(0x100);

    switch (p->unk_06) {
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
        w->update = func_080ECAC8;
        func_080ECA88(w);
    } else {
        w->update = func_080ECAC8;
        func_080ECAA8(w);
    }

    TaskPoolInit(&w->tasks, 2);
}

s32 Task_MapDoor_1(MapDoorWork* w) {
    if (gUnk_02039BA0->unk_70 & 0x40000) {
        if (w->unk_71 == 0) {
            w->unk_70 = 0;
        }
    } else {
        w->unk_71 = 0;
        w->unk_70 = 1;
    }

    if (w->update != 0) {
        if (w->update(w) == 0) {
            return 0;
        }
    }

    TaskPoolUpdate(&w->tasks);
    return 1;
}

void Task_MapDoor_2(MapDoorWork* p) {
    UnkStruct_080DFB7C* f = p->unk_00;
    u16 sx;
    u16 sy;
    u16 v;
    u16 t;
    s32 k;

    if (p->unk_70 == 1) {
        sx = (p->unk_04 >> 8) - (gUnk_02039BA0->x >> 8);
        k = p->unk_08 >> 8;
        sy = k + (p->unk_0C >> 8) - (gUnk_02039BA0->y >> 8);

        switch (f->unk_06) {
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
        DrawSprite(sx, sy, 0, p->tiles, p->palette, 0, t, v);

        if (f->unk_00 & 0x10) {
            switch (f->unk_06) {
            case 0:
            case 2:
                DrawSprite(sx, sy, 0, p->tiles2, p->palette2, 0, t, v - 1);
                break;
            case 1:
            case 3:
                DrawSprite(sx, sy, 0, p->tiles2, p->palette2, 0, t, v - 1);
                break;
            }
        }

        TaskPoolDraw(&p->tasks);
    }
}

void Task_MapDoor_3(MapDoorWork* p) {
    ReleaseObjTiles(p->tiles);
    ReleaseObjPalette(p->palette);
    ReleaseObjTiles(p->tiles2);
    ReleaseObjPalette(p->palette2);
    TaskPoolDestroy(&p->tasks);
}

void func_080ECFE8(UnkStruct_080ECFE8* p, u8 a) {
    s32 i;

    FadeSetPaletteExcluded(p->palette->index + 0x10, a);
    FadeSetPaletteExcluded(p->palette5->index + 0x10, a);
    FadeSetPaletteExcluded(p->palette2->index + 0x10, a);
    FadeSetPaletteExcluded(p->palette3->index + 0x10, a);
    FadeSetPaletteExcluded(p->palette4->index + 0x10, a);

    for (i = 0; i < 3; i++) {
        if (p->palettes[i] != 0) {
            FadeSetPaletteExcluded(p->palettes[i]->index + 0x10, a);
        }
    }
}

void func_080ED06C(UnkStruct_080ED06C* p, u8 a) {
    FadeSetPaletteExcluded(p->palette->index + 0x10, a);
    FadeSetPaletteExcluded(p->palette2->index + 0x10, a);
    FadeSetPaletteExcluded(p->palette3->index + 0x10, a);
}

void func_080ED0B8(FldRes* p, u8 a, u16 v) {
    u16 d[3];
    u16* q;
    s32 i;

    d[0] = v / 100;
    d[1] = v / 10 - d[0] * 10;
    d[2] = v - d[0] * 100 - d[1] * 10;

    for (i = 0, q = d; i < 3; i++) {
        RequestDma3Copy((void*)&gUnk_099581A4[*q * 32], (void*)(0x06010000 + (p->index + a + i) * 32), 0x20);
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
        RequestDma3Copy((void*)&gUnk_099581A4[*q * 32], (void*)(0x06010000 + (p->index + a + i) * 32), 0x20);
        q++;
    }
}
void func_080ED250(u8* work) {
    u8* p1;
    u8* p2;
    u8* p3;

    LoadBgTiles(0, gUnk_099597E4, 0x140);
    LoadBgMap(0, gUnk_09985F44, 0x800);
    LoadPalette(gUnk_09611AB8, &gUnk_050001C0[0x20], 0x20);
    FadeSetPaletteExcluded(15, 1);
    SetBgScroll(0, 0, 0);
    *(void**)&work[0x17C] = _08066468(1);
#ifdef VERSION_EU
    p1 = &work[0x180];
    InitTextSlots(p1, 66);
    p2 = &work[0x394];
    InitTextSlots(p2, 6);
    p3 = &work[0x3C8];
    InitTextSlots(p3, 9);
    work[0x390] = LoadTextSlots(eu_0805E924(gUnkEu_088927F4), p1);
    work[0x3C4] = LoadTextSlots(eu_0805E924(gUnkEu_08890E1C), p2);
    work[0x410] = LoadTextSlots(eu_0805E924(gUnkEu_08890E44), p3);
#else
    p1 = &work[0x180];
    InitTextSlots(p1, 33);
    p2 = &work[0x28C];
    InitTextSlots(p2, 6);
    p3 = &work[0x2C0];
    InitTextSlots(p3, 9);
    work[0x288] = LoadTextSlots(gUnk_0815A03A, p1);
    work[0x2BC] = LoadTextSlots(gUnk_08159E10, p2);
    work[0x308] = LoadTextSlots(gUnk_08159E18, p3);
#endif
}
void func_080ED314(u8* work) {
    FadeSetPaletteExcluded(15, 0);
    DisableBg(0);
    ReleaseObjPalette(*(u8**)&work[0x17C]);
#ifdef VERSION_EU
    FreeTextSlots(&work[0x180], 0x42);
    FreeTextSlots(&work[0x394], 6);
    FreeTextSlots(&work[0x3C8], 9);
#else
    FreeTextSlots(&work[0x180], 0x21);
    FreeTextSlots(&work[0x28C], 6);
    FreeTextSlots(&work[0x2C0], 9);
#endif
}

s32 func_080ED35C(MapMenuWork* w) {
    w->palette2 = LoadObjPalette(gUnk_09991984, 32);
    w->tiles2 = LoadObjTiles(gUnk_09958124, 0x80);
    w->y = -0x800;
    w->y2 = 0xA000;

    if (gGameState.flags & 8) {
        w->tiles8 = AllocObjTiles(0x400, gUnk_092EB78A);
    } else {
        w->tiles8 = AllocObjTiles(0x340, gUnk_088B6560);
    }

    w->tiles7 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->palette7 = LoadObjPalette(gUnk_08F69BE4, 32);
    w->unk_150 = gUnk_02039BA0->actor.fieldPosition.x - gUnk_02039BA0->x;
    w->unk_154 = gUnk_02039BA0->actor.fieldPosition.y + gUnk_02039BA0->actor.fieldPosition.z - gUnk_02039BA0->y;
    w->x8 = w->unk_150;
    w->y4 = w->unk_154;
    w->unk_309 = gGameState.unk_00F;
    w->unk_30A = 0;
    w->unk_034 = 0;
    w->unk_30E = 0;
    w->unk_30C = w->unk_30F != 0 ? 1 : 16;
    w->update = func_080ED498;
    func_080ED06C((UnkStruct_080ED06C*)w, 1);

    if (w->unk_30F == 0) {
        FadeToAmount(0, 16, 16);
    }
    return 1;
}

s32 func_080ED498(MapMenuWork* w) {
    if (w->unk_30C != 0) {
        ApproachValue(&w->y, 0, w->unk_30C);
        ApproachValue(&w->y2, 0x9800, w->unk_30C);
        w->unk_30C--;
    } else {
        s32 i;

        gUnk_0203C7AC->unk_00 |= 0x1000;
        gUnk_02039BA0->unk_70 |= 0x100;
#ifdef VERSION_EU
        switch (gLanguage) {
        case 0:
            w->tiles5 = LoadObjTiles(gUnk_09954B64, 0x1BC0);
            break;
        case 1:
            w->tiles5 = LoadObjTiles(gUnk_09956724, 0x1BC0);
            break;
        case 4:
            w->tiles5 = LoadObjTiles(gUnkEu_09938170, 0x1BC0);
            break;
        case 3:
            w->tiles5 = LoadObjTiles(gUnkEu_09939D30, 0x1BC0);
            break;
        case 2:
        default:
            w->tiles5 = LoadObjTiles(gUnkEu_0993B8F0, 0x1BC0);
            break;
        }
#else
        w->tiles5 = LoadObjTiles(gUnk_09954B64, 0x1BC0);
#endif
        w->palette3 = LoadObjPalette(gUnk_09991924, 32);
        w->x3 = 0x11800;
        w->x4 = 0xF000;
        w->x5 = 0x10000;
        func_080ED0B8(w->tiles5, 0, gGameState.progression.level);
        func_080ED0B8(w->tiles5, 6, gGameState.progression.maxHp);
        func_080ED0B8(w->tiles5, 3, gGameState.hp);

        if (gGameState.flags & 8) {
            func_080ED0B8(w->tiles5, 9, gGameState.progression.dp);
        } else {
            func_080ED14C(w->tiles5, 9, gGameState.progression.mooglePoints);
        }

        w->palette4 = LoadObjPalette(gUnk_09991964, 32);
        w->palette5 = LoadObjPalette(gUnk_09991944, 32);

#ifdef VERSION_EU
        switch (gLanguage) {
        case 0:
            if (gGameState.flags & 8) {
                w->tiles6 = LoadObjTiles(gUnkEu_09943DB0, 0x1500);
            } else {
                w->tiles6 = LoadObjTiles(gUnkEu_0993D4B0, 0x1500);
            }
            break;
        case 1:
            if (gGameState.flags & 8) {
                w->tiles6 = LoadObjTiles(gUnkEu_099452B0, 0x1500);
            } else {
                w->tiles6 = LoadObjTiles(gUnkEu_0993E9B0, 0x1500);
            }
            break;
        case 4:
            if (gGameState.flags & 8) {
                w->tiles6 = LoadObjTiles(gUnkEu_099467B0, 0x1500);
            } else {
                w->tiles6 = LoadObjTiles(gUnkEu_0993FEB0, 0x1500);
            }
            break;
        case 3:
            if (gGameState.flags & 8) {
                w->tiles6 = LoadObjTiles(gUnkEu_09947CB0, 0x1500);
            } else {
                w->tiles6 = LoadObjTiles(gUnkEu_099413B0, 0x1500);
            }
            break;
        case 2:
        default:
            if (gGameState.flags & 8) {
                w->tiles6 = LoadObjTiles(gUnkEu_099491B0, 0x1500);
            } else {
                w->tiles6 = LoadObjTiles(gUnkEu_099428B0, 0x1500);
            }
            break;
        }
#else
        if (gGameState.flags & 8) {
            w->tiles6 = LoadObjTiles(gUnk_099582E4, 0x1500);
        } else {
            w->tiles6 = LoadObjTiles(gUnk_09956724, 0x1500);
        }
#endif

        w->x6 = -0x7800;
        w->palette = LoadObjPalette(gUnk_099919A4, 32);
        w->tiles = AllocObjTiles(0x120, gUnk_098A8628);
        AnimInit(&w->anim, gUnk_09EF8D58, gUnk_09EF8D48);
        AnimStart(&w->anim, 2, 1);

        for (i = 0; i < 3; i++) {
            w->tiles9[i] = 0;
            w->palette9[i] = 0;
            w->gfx[i] = 0;
        }

        func_080D8B84(&w->tiles9, &w->palette9, &w->gfx);
        InitTextSlots(&w->unk_074, 24);
        w->palette8 = _08066468(1);
        w->unk_074[0xC0] = LoadTextSlots(GetDeckName(GetActiveDeckIndex()), &w->unk_074);
#ifdef VERSION_EU
        switch (gLanguage) {
        case 0:
            w->tiles3 = LoadObjTiles(gUnkEu_0994A6B0, 0x200);
            break;
        case 1:
            w->tiles3 = LoadObjTiles(gUnkEu_0994A6B0, 0x200);
            break;
        case 4:
            w->tiles3 = LoadObjTiles(gUnkEu_0994A8B0, 0x200);
            break;
        case 3:
            w->tiles3 = LoadObjTiles(gUnkEu_0994A6B0, 0x200);
            break;
        case 2:
        default:
            w->tiles3 = LoadObjTiles(gUnkEu_0994AAB0, 0x200);
            break;
        }
        w->x = -0x8000;
        w->tiles4 = LoadObjTiles(gUnkEu_0994ACB0, 0x300);
#else
        w->tiles3 = LoadObjTiles(gUnk_09957F24, 0x200);
        w->x = -0x8000;
        w->tiles4 = LoadObjTiles(gUnk_09957C24, 0x300);
#endif
        w->x2 = 0xF800;
        func_080ECFE8((UnkStruct_080ECFE8*)w, 1);
        w->unk_30E = 1;
        w->unk_30C = w->unk_30F != 0 ? 1 : 16;
        w->update = func_080ED6CC;
    }

    return 1;
}

s32 func_080ED6CC(MapMenuWork* w) {
    if (w->unk_30C != 0) {
        ApproachValue(&w->x, 0, w->unk_30C);
        ApproachValue(&w->x6, 0x800, w->unk_30C);
        ApproachValue(&w->x2, 0x7800, w->unk_30C);
        ApproachValue(&w->x3, 0x9800, w->unk_30C);
        ApproachValue(&w->x4, 0x7000, w->unk_30C);
        ApproachValue(&w->x5, 0x8000, w->unk_30C);
        ApproachValue(&w->x8, 0xAC00, w->unk_30C);
        ApproachValue(&w->y4, 0x6000, w->unk_30C);
        w->unk_30C--;
    } else {
        w->unk_034 = 1;
        w->y3 = (w->unk_309 * 19 + 16) << 8;

        if (w->unk_30F != 0) {
            w->unk_30F = 0;
            FadeToAmount(0, 16, 1);
            w->update = func_080EDD7C;
        } else {
            w->update = (gGameState.flags & 8) ? func_080ED91C : func_080ED7CC;
        }
    }

    return 1;
}

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
        w->update = func_080EDB4C;
        m4aSongNumStart(0x68);
    } else if (GetKeysPressed() & 1) {
        switch (w->unk_309) {
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
            func_0801CB0C();
            w->update = func_080EDA90;
            m4aSongNumStart(0x66);
            break;
        case 1:
            if ((u8)(gUnk_0203C590.unk_06 + 4) > 2) {
                func_0801CB0C();
                w->update = func_080EDA90;
                m4aSongNumStart(0x66);
            } else {
                m4aSongNumStart(0x69);
            }
            break;
        case 6:
            m4aSongNumStart(0x66);
            func_080ED250((u8*)w);
            w->unk_30A = 2;
            w->x7 = 0x8800;
            w->update = func_080EDC94;
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
        w->update = func_080EDB4C;
        m4aSongNumStart(104);
    } else if (GetKeysPressed() & 1) {
        switch (w->unk_309) {
        case 0:
        case 2:
        case 3:
        case 4:
            m4aSongNumStart(102);
            func_0801CB0C();
            w->update = func_080EDA90;
            break;
        case 5:
            m4aSongNumStart(102);
            func_0801CB0C();
            w->update = func_080EDA90;
            break;
        case 1:
            if ((u8)(gUnk_0203C590.unk_06 + 4) > 2) {
                m4aSongNumStart(102);
                func_0801CB0C();
                w->update = func_080EDA90;
            } else {
                m4aSongNumStart(105);
            }
            break;
        case 6:
            m4aSongNumStart(102);
            func_080ED250((u8*)w);
            w->unk_30A = 2;
            w->x7 = 0x8800;
            w->update = func_080EDC94;
            break;
        }
    }

    return 1;
}

s32 func_080EDA90(MapMenuWork* w) {
    gGameState.unk_00F = w->unk_309;

    switch (w->unk_309) {
    case 0:
        if (gGameState.flags & 8) {
            if (gGameState.progression.unk_82 & 0x800) {
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

s32 func_080EDB4C(MapMenuWork* w) {
    if (w->unk_30C != 0) {
        ApproachValue(&w->x, -0x8000, w->unk_30C);
        ApproachValue(&w->x6, -0x7800, w->unk_30C);
        ApproachValue(&w->x2, 0xF800, w->unk_30C);
        ApproachValue(&w->x3, 0x11800, w->unk_30C);
        ApproachValue(&w->x4, 0xF000, w->unk_30C);
        ApproachValue(&w->x5, 0x10000, w->unk_30C);
        ApproachValue(&w->x8, w->unk_150, w->unk_30C);
        ApproachValue(&w->y4, w->unk_154, w->unk_30C);
        w->unk_30C--;
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x1000;
        gUnk_02039BA0->unk_70 &= ~0x100;
        func_080ECFE8((UnkStruct_080ECFE8*)w, 0);
        FadeToOriginal(0, 16);
        w->unk_30C = 16;
        w->update = func_080EDC38;
    }
    return 1;
}

s32 func_080EDC38(MapMenuWork* w) {
    if (w->unk_30C != 0) {
        ApproachValue(&w->y, -0x800, w->unk_30C);
        ApproachValue(&w->y2, 0xA000, w->unk_30C);
        w->unk_30C--;
        return 1;
    }

    gGameState.unk_00F = 0xFF;
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
        w->y3 = (w->unk_309 * 19 + 16) << 8;
        w->update = (gGameState.flags & 8) ? func_080ED91C : func_080ED7CC;
        m4aSongNumStart(0x68);
    } else if (GetKeysPressed() & 1) {
        SaveWriteSystem();
        w->update = func_080EDA90;
        m4aSongNumStart(0x66);
    }
    return 1;
}

s32 func_080EDD7C(MapMenuWork* w) {
    (*(volatile u16*)&gDispCnt) |= 0x1000;
    w->update = (gGameState.flags & 8) ? func_080ED91C : func_080ED7CC;
    return 1;
}

void Task_MapMenu_0(MapMenuWork* w) {
    s8 v;

    gUnk_02039BA0->unk_70 |= 0x1000;
    gUnk_02039BA0->unk_70 |= 0x80;
    gUnk_02039BA0->unk_70 |= 0x2000;

    if (gGameState.flags & 8) {
        w->palette6 = LoadObjPalette(gUnk_09618118, 32);
    } else {
        w->palette6 = LoadObjPalette(gUnk_08F683A4, 32);
    }

    FadeSetPaletteExcluded(w->palette6->index + 0x10, 1);
    v = gGameState.unk_00F;

    if (v != -1) {
        w->unk_30F = 1;
    } else {
        gGameState.unk_00F = 0;
        w->unk_30F = 0;
        m4aSongNumStart(0x67);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFF, 0x80);
    }
    w->update = func_080ED35C;
}

s32 Task_MapMenu_1(MapMenuWork* w) {
    if (w->unk_30F != 0) {
        FadeStartIn(0, 16);
    }

    if (w->unk_30E != 0) {
        AnimUpdate(&w->anim);
    }

    if (w->update != 0 && (u8)w->update(w) == 0) {
        return 0;
    }
    return 1;
}

void Task_MapMenu_2(MapMenuWork* w) {
    s32 i;
    s32 k;

#ifdef VERSION_EU
    DrawSprite(128, w->y >> 8, gUnkEu_09F84738[0], w->tiles2, w->palette2, 0, 0x400, 90);
    DrawSprite(128, w->y2 >> 8, gUnkEu_09F84738[1], w->tiles2, w->palette2, 0, 0x400, 90);
#else
    DrawSprite(128, w->y >> 8, gUnk_09EF8E74[0], w->tiles2, w->palette2, 0, 0x400, 90);
    DrawSprite(128, w->y2 >> 8, gUnk_09EF8E74[1], w->tiles2, w->palette2, 0, 0x400, 90);
#endif

    if (
#ifdef VERSION_EU
        w->unk_30A == 0 &&
#endif
        (gUnk_0203C7AC->unk_00 & 0x1000)) {
        if (gGameState.flags & 8) {
            DrawSprite(w->x8 >> 8, w->y4 >> 8, gUnk_09EEF89C[0], w->tiles8, w->palette6,
                0, 0x400, 80);
        } else {
            DrawSprite(w->x8 >> 8, w->y4 >> 8, ((void**)gUnk_09EDE8CC)[0], w->tiles8,
                w->palette6, 0, 0x400, 80);
        }

        DrawSprite(w->x8 >> 8, w->y4 >> 8, gUnk_09EE1380[0], w->tiles7, w->palette7, 0,
            0x400, 81);
    }

    if (w->unk_30E != 0) {
#ifdef VERSION_EU
        switch (gLanguage) {
        case 4:
            DrawSprite(w->x >> 8, 0, gUnkEu_09F84720[0], w->tiles3, w->palette2, 0, 0x400, 80);
            break;
        case 0:
        case 1:
        case 3:
            DrawSprite(w->x >> 8, 0, gUnkEu_09F84718[0], w->tiles3, w->palette2, 0, 0x400, 80);
            break;
        case 2:
        default:
            DrawSprite(w->x >> 8, 0, gUnkEu_09F84728[0], w->tiles3, w->palette2, 0, 0x400, 80);
            break;
        }
#else
        DrawSprite(w->x >> 8, 0, gUnk_09EF8E6C[0], w->tiles3, w->palette2, 0, 0x400, 80);
#endif
#ifdef VERSION_EU
        DrawSprite(w->x2 >> 8, 14, gUnkEu_09F84730[0], w->tiles4, w->palette2, 0, 0x400, 90);
#else
        DrawSprite(w->x2 >> 8, 14, gUnk_09EF8E64[0], w->tiles4, w->palette2, 0, 0x400, 90);
#endif

        if (gGameState.flags & 8) {
#ifdef VERSION_EU
            switch (gLanguage) {
            case 0:
                DrawSprite(w->x3 >> 8, 0, gUnkEu_09F84560[0], w->tiles5, w->palette3, 0, 0x400, 80);
                DrawSprite(w->x3 >> 8, 0, gUnkEu_09F84560[1], w->tiles5, w->palette3, 0, 0x400, 81);
                DrawSprite(w->x4 >> 8, 103, gUnkEu_09F84560[2], w->tiles5, w->palette3, 0, 0x400,
                    81);
                break;
            case 1:
                DrawSprite(w->x3 >> 8, 0, gUnkEu_09F84574[0], w->tiles5, w->palette3, 0, 0x400, 80);
                DrawSprite(w->x3 >> 8, 0, gUnkEu_09F84574[1], w->tiles5, w->palette3, 0, 0x400, 81);
                DrawSprite(w->x4 >> 8, 103, gUnkEu_09F84574[2], w->tiles5, w->palette3, 0, 0x400,
                    81);
                break;
            case 4:
                DrawSprite(w->x3 >> 8, 0, gUnkEu_09F84588[0], w->tiles5, w->palette3, 0, 0x400, 80);
                DrawSprite(w->x3 >> 8, 0, gUnkEu_09F84588[1], w->tiles5, w->palette3, 0, 0x400, 81);
                DrawSprite(w->x4 >> 8, 103, gUnkEu_09F84588[2], w->tiles5, w->palette3, 0, 0x400,
                    81);
                break;
            case 3:
                DrawSprite(w->x3 >> 8, 0, gUnkEu_09F8459C[0], w->tiles5, w->palette3, 0, 0x400, 80);
                DrawSprite(w->x3 >> 8, 0, gUnkEu_09F8459C[1], w->tiles5, w->palette3, 0, 0x400, 81);
                DrawSprite(w->x4 >> 8, 103, gUnkEu_09F8459C[2], w->tiles5, w->palette3, 0, 0x400,
                    81);
                break;
            case 2:
            default:
                DrawSprite(w->x3 >> 8, 0, gUnkEu_09F845B0[0], w->tiles5, w->palette3, 0, 0x400, 80);
                DrawSprite(w->x3 >> 8, 0, gUnkEu_09F845B0[1], w->tiles5, w->palette3, 0, 0x400, 81);
                DrawSprite(w->x4 >> 8, 103, gUnkEu_09F845B0[2], w->tiles5, w->palette3, 0, 0x400,
                    81);
                break;
            }
#else
            DrawSprite(w->x3 >> 8, 0, gUnk_09EF8E80[0], w->tiles5, w->palette3, 0, 0x400, 80);
            DrawSprite(w->x3 >> 8, 0, gUnk_09EF8E80[1], w->tiles5, w->palette3, 0, 0x400, 81);
            DrawSprite(w->x4 >> 8, 103, gUnk_09EF8E80[2], w->tiles5, w->palette3, 0, 0x400,
                81);
#endif

            if (w->tiles9[0] != 0) {
                DrawSprite((w->x4 >> 8) + 18, 124, w->gfx[0], w->tiles9[0],
                    w->palette9[0], 0, 0x400, 80);
            }
        } else {
#ifdef VERSION_EU
            switch (gLanguage) {
            case 0:
                DrawSprite(w->x3 >> 8, 0, gUnkEu_09F844FC[0], w->tiles5, w->palette3, 0, 0x400, 80);
                DrawSprite(w->x3 >> 8, 0, gUnkEu_09F844FC[1], w->tiles5, w->palette3, 0, 0x400, 81);
                DrawSprite(w->x4 >> 8, 103, gUnkEu_09F844FC[2], w->tiles5, w->palette3, 0, 0x400,
                    81);
                break;
            case 1:
                DrawSprite(w->x3 >> 8, 0, gUnkEu_09F84510[0], w->tiles5, w->palette3, 0, 0x400, 80);
                DrawSprite(w->x3 >> 8, 0, gUnkEu_09F84510[1], w->tiles5, w->palette3, 0, 0x400, 81);
                DrawSprite(w->x4 >> 8, 103, gUnkEu_09F84510[2], w->tiles5, w->palette3, 0, 0x400,
                    81);
                break;
            case 4:
                DrawSprite(w->x3 >> 8, 0, gUnkEu_09F84524[0], w->tiles5, w->palette3, 0, 0x400, 80);
                DrawSprite(w->x3 >> 8, 0, gUnkEu_09F84524[1], w->tiles5, w->palette3, 0, 0x400, 81);
                DrawSprite(w->x4 >> 8, 103, gUnkEu_09F84524[2], w->tiles5, w->palette3, 0, 0x400,
                    81);
                break;
            case 3:
                DrawSprite(w->x3 >> 8, 0, gUnkEu_09F84538[0], w->tiles5, w->palette3, 0, 0x400, 80);
                DrawSprite(w->x3 >> 8, 0, gUnkEu_09F84538[1], w->tiles5, w->palette3, 0, 0x400, 81);
                DrawSprite(w->x4 >> 8, 103, gUnkEu_09F84538[2], w->tiles5, w->palette3, 0, 0x400,
                    81);
                break;
            case 2:
            default:
                DrawSprite(w->x3 >> 8, 0, gUnkEu_09F8454C[0], w->tiles5, w->palette3, 0, 0x400, 80);
                DrawSprite(w->x3 >> 8, 0, gUnkEu_09F8454C[1], w->tiles5, w->palette3, 0, 0x400, 81);
                DrawSprite(w->x4 >> 8, 103, gUnkEu_09F8454C[2], w->tiles5, w->palette3, 0, 0x400,
                    81);
                break;
            }
#else
            DrawSprite(w->x3 >> 8, 0, gUnk_09EF8E0C[0], w->tiles5, w->palette3, 0, 0x400, 80);
            DrawSprite(w->x3 >> 8, 0, gUnk_09EF8E0C[1], w->tiles5, w->palette3, 0, 0x400, 81);
            DrawSprite(w->x4 >> 8, 103, gUnk_09EF8E0C[2], w->tiles5, w->palette3, 0, 0x400,
                81);
#endif

            for (i = 0; i < 3; i++) {
                k = i * 20 + 14;

                if (w->tiles9[i] != 0) {
                    DrawSprite((w->x4 >> 8) + k, 124, w->gfx[i], w->tiles9[i],
                        w->palette9[i], 0, 0x400, 80);
                }
            }
        }

        if (!(gGameState.flags & 8)) {
#ifdef VERSION_EU
            switch (gLanguage) {
            case 0:
                DrawSprite(w->x5 >> 8, 144, gUnkEu_09F844FC[3], w->tiles5, w->palette3, 0, 0x400,
                    81);
                break;
            case 1:
                DrawSprite(w->x5 >> 8, 144, gUnkEu_09F84510[3], w->tiles5, w->palette3, 0, 0x400,
                    81);
                break;
            case 4:
                DrawSprite(w->x5 >> 8, 144, gUnkEu_09F84524[3], w->tiles5, w->palette3, 0, 0x400,
                    81);
                break;
            case 3:
                DrawSprite(w->x5 >> 8, 144, gUnkEu_09F84538[3], w->tiles5, w->palette3, 0, 0x400,
                    81);
                break;
            case 2:
            default:
                DrawSprite(w->x5 >> 8, 144, gUnkEu_09F8454C[3], w->tiles5, w->palette3, 0, 0x400,
                    81);
                break;
            }
#else
            DrawSprite(w->x5 >> 8, 144, gUnk_09EF8E0C[3], w->tiles5, w->palette3, 0, 0x400,
                81);
#endif
            DrawTextSlots((w->x5 >> 8) + 16, 145, &w->unk_074, w->palette8, 50,
                w->unk_074[0xC0]);
        }

#ifdef VERSION_EU
        switch (gLanguage) {
        case 0:
            if (w->unk_034 != 0) {
                DrawSprite(w->x6 >> 8, 26, gUnkEu_09F845C4[w->unk_309], w->tiles6, w->palette5, 0,
                    0x400, 81);
                DrawSprite(w->x6 >> 8, 26, gUnkEu_09F84678[w->unk_309], w->tiles6, w->palette4, 0,
                    0x400, 81);
            } else {
                DrawSprite(w->x6 >> 8, 26, gUnkEu_09F845C4[7], w->tiles6, w->palette5, 0, 0x400,
                    80);
            }
            break;
        case 1:
            if (w->unk_034 != 0) {
                DrawSprite(w->x6 >> 8, 26, gUnkEu_09F845E8[w->unk_309], w->tiles6, w->palette5, 0,
                    0x400, 81);
                DrawSprite(w->x6 >> 8, 26, gUnkEu_09F84698[w->unk_309], w->tiles6, w->palette4, 0,
                    0x400, 81);
            } else {
                DrawSprite(w->x6 >> 8, 26, gUnkEu_09F845E8[7], w->tiles6, w->palette5, 0, 0x400,
                    80);
            }
            break;
        case 4:
            if (w->unk_034 != 0) {
                DrawSprite(w->x6 >> 8, 26, gUnkEu_09F8460C[w->unk_309], w->tiles6, w->palette5, 0,
                    0x400, 81);
                DrawSprite(w->x6 >> 8, 26, gUnkEu_09F846B8[w->unk_309], w->tiles6, w->palette4, 0,
                    0x400, 81);
            } else {
                DrawSprite(w->x6 >> 8, 26, gUnkEu_09F8460C[7], w->tiles6, w->palette5, 0, 0x400,
                    80);
            }
            break;
        case 3:
            if (w->unk_034 != 0) {
                DrawSprite(w->x6 >> 8, 26, gUnkEu_09F84630[w->unk_309], w->tiles6, w->palette5, 0,
                    0x400, 81);
                DrawSprite(w->x6 >> 8, 26, gUnkEu_09F846D8[w->unk_309], w->tiles6, w->palette4, 0,
                    0x400, 81);
            } else {
                DrawSprite(w->x6 >> 8, 26, gUnkEu_09F84630[7], w->tiles6, w->palette5, 0, 0x400,
                    80);
            }
            break;
        case 2:
        default:
            if (w->unk_034 != 0) {
                DrawSprite(w->x6 >> 8, 26, gUnkEu_09F84654[w->unk_309], w->tiles6, w->palette5, 0,
                    0x400, 81);
                DrawSprite(w->x6 >> 8, 26, gUnkEu_09F846F8[w->unk_309], w->tiles6, w->palette4, 0,
                    0x400, 81);
            } else {
                DrawSprite(w->x6 >> 8, 26, gUnkEu_09F84654[7], w->tiles6, w->palette5, 0, 0x400,
                    80);
            }
            break;
        }
#else
        if (w->unk_034 != 0) {
            DrawSprite(w->x6 >> 8, 26, gUnk_09EF8E20[w->unk_309], w->tiles6, w->palette5, 0,
                0x400, 81);
            DrawSprite(w->x6 >> 8, 26, gUnk_09EF8E44[w->unk_309], w->tiles6, w->palette4, 0,
                0x400, 81);
        } else {
            DrawSprite(w->x6 >> 8, 26, gUnk_09EF8E20[7], w->tiles6, w->palette5, 0, 0x400,
                80);
        }
#endif

        if (w->unk_034 != 0) {
            switch (w->unk_30A) {
            case 1:
                ApproachValueHalf(&w->x7, 0x4800);
                DrawSprite(w->x7 >> 8, 80, AnimGetGfx(&w->anim), w->tiles, w->palette, 0,
                    1, 60);
                break;
            case 2:
                ApproachValueHalf(&w->x7, 0x8800);
                DrawSprite(w->x7 >> 8, 80, AnimGetGfx(&w->anim), w->tiles, w->palette, 0,
                    1, 60);
                break;
            case 0:
            default:
                ApproachValueHalf(&w->y3, (w->unk_309 * 19 + 16) << 8);
                DrawSprite(24, w->y3 >> 8, AnimGetGfx(&w->anim), w->tiles, w->palette, 0,
                    0x401, 60);
                break;
            }
        }

        if (w->unk_30A != 0) {
            DrawTextSlots(
#ifdef VERSION_EU
                120 - (GetTextSlotsWidth(w->unk_180, w->unk_288) >> 1),
#else
                (240 - GetTextSlotsWidth(w->unk_180, w->unk_288)) / 2,
#endif
                64, w->unk_180,
                w->unk_17C, 70, w->unk_288);
            DrawTextSlots(80, 84, w->unk_28C, w->unk_17C, 70, w->unk_2BC);
            DrawTextSlots(144, 84, w->unk_2C0, w->unk_17C, 70, w->unk_308);
        }
    }
}

void Task_MapMenu_3(MapMenuWork* w) {
    s32 i;

    func_080ED06C((UnkStruct_080ED06C*)w, 0);
    func_080ECFE8((UnkStruct_080ECFE8*)w, 0);
    ReleaseObjPalette(w->palette2);
    ReleaseObjTiles(w->tiles2);
    ReleaseObjTiles(w->tiles3);
    ReleaseObjTiles(w->tiles4);
    ReleaseObjPalette(w->palette3);
    ReleaseObjTiles(w->tiles5);
    ReleaseObjPalette(w->palette4);
    ReleaseObjPalette(w->palette5);
    ReleaseObjTiles(w->tiles6);
    ReleaseObjPalette(w->palette);
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette((u8*)w->palette6);
    ReleaseObjTiles(w->tiles8);
    ReleaseObjPalette(w->palette7);
    ReleaseObjTiles(w->tiles7);

    for (i = 0; i < 3; i++) {
        if (w->tiles9[i] != 0) {
            ReleaseObjTiles(w->tiles9[i]);
            ReleaseObjPalette(w->palette9[i]);
        }
    }

    FreeTextSlots(w->unk_074, 24);
    ReleaseObjPalette(w->palette8);
    gUnk_0203C7AC->unk_00 &= ~0x80;
    gUnk_02039BA0->unk_70 &= ~0x1000;
    gUnk_02039BA0->unk_70 &= ~0x80;
    gUnk_02039BA0->unk_70 &= ~0x2000;
}

void func_080EE50C(UnkStruct_080EE50C* p, u8 a) {
    FadeSetPaletteExcluded(0x0B, a);
    FadeSetPaletteExcluded(0x0C, a);
    FadeSetPaletteExcluded(0x0D, a);
    FadeSetPaletteExcluded(0x0E, a);
    FadeSetPaletteExcluded(p->palette->index + 0x10, a);
    FadeSetPaletteExcluded(p->palette2->index + 0x10, a);
    FadeSetPaletteExcluded(p->palette3->index + 0x10, a);
    FadeSetPaletteExcluded(p->palette4->index + 0x10, a);
}

void func_080EE580(UnkStruct_080EE580* p, u8 a) {
    FadeSetPaletteExcluded(p->palette->index + 0x10, a);
    FadeSetPaletteExcluded(p->palette2->index + 0x10, a);
    FadeSetPaletteExcluded(p->palette3->index + 0x10, a);
    FadeSetPaletteExcluded(p->palette4->index + 0x10, a);
}

void func_080EE5E0(u8 a) {
    const u8* src;

#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        if (gGameState.flags & 8) {
            src = gUnkEu_09957550[a];
        } else {
            src = gUnkEu_09955250[a];
        }
        break;
    case 1:
        if (gGameState.flags & 8) {
            src = gUnkEu_0995BB50[a];
        } else {
            src = gUnkEu_09959850[a];
        }
        break;
    case 4:
        if (gGameState.flags & 8) {
            src = gUnkEu_09960150[a];
        } else {
            src = gUnkEu_0995DE50[a];
        }
        break;
    case 3:
        if (gGameState.flags & 8) {
            src = gUnkEu_09964750[a];
        } else {
            src = gUnkEu_09962450[a];
        }
        break;
    case 2:
    default:
        if (gGameState.flags & 8) {
            src = gUnkEu_09968D50[a];
        } else {
            src = gUnkEu_09966A50[a];
        }
        break;
    }
#else
    if (gGameState.flags & 8) {
        src = gUnk_09963D64[a];
    } else {
        src = gUnk_09961A64[a];
    }
#endif
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
    SaveFileSummary* e = &gGameState.fileSummaries[i];

    if (e->level == 0) {
        work[0x164] = 0;
    } else {
        func_080EE5E0(e->floor);
        func_080EE62C(e->level);
        func_080EE6AC(e->playTime);
        work[0x164] = LoadTextSlots((void*)func_080DF804(e->world), &work[0x44]);
    }
}

s32 func_080EE7B0(MapSaveWork* w) {
    if (w->unk_2F6 != 0) {
        ApproachValue(&w->y, 0, w->unk_2F6);
        ApproachValue(&w->y2, 0x9800, w->unk_2F6);
        w->unk_2F6 -= 1;
    } else {
        gUnk_0203C7AC->unk_00 |= 0x1000;
        gUnk_02039BA0->unk_70 |= 0x100;
        w->unk_2F6 = 16;
        w->update = func_080EE824;
    }
    return 1;
}

s32 func_080EE824(MapSaveWork* w) {
    u8* p1;
    u8* p2;
    u8* p3;

    if (w->unk_2F6 != 0) {
        ApproachValue(&w->x, 0, w->unk_2F6);

        if (gGameState.flags & 8) {
            ApproachValue(&w->x3, 0x3800, w->unk_2F6);
            ApproachValue(&w->y3, 0x7000, w->unk_2F6);
        } else {
            ApproachValue(&w->x3, 0x3800, w->unk_2F6);
            ApproachValue(&w->y3, 0x7000, w->unk_2F6);
        }
        w->unk_2F6 -= 1;
    } else {
        if (!(gGameState.flags & 8)) {
            w->palette4 = LoadObjPalette(gUnk_09991C04, 32);
        } else {
            w->palette4 = LoadObjPalette(gUnk_09991C44, 32);
        }

        w->unk_044[0x120] = 0;
        InitTextSlots(w->unk_044, 36);
        SetupBg(0, 3, 31, 11);
        SetBgPriority(0, 0);
        LoadBgPalette(0, gUnk_09991C84, 128);
        LoadBgTiles(0, gUnk_099661A4, 0x1FA0);

#ifdef VERSION_EU
        switch (gLanguage) {
        case 1:
            RequestDma3Copy((void*)gUnkEu_0996D130, (u8*)GetBgCharBase(0) + 0x800, 0x800);
            break;
        case 4:
            RequestDma3Copy((void*)gUnkEu_0996D930, (u8*)GetBgCharBase(0) + 0x800, 0x800);
            break;
        case 3:
            RequestDma3Copy((void*)gUnkEu_0996E130, (u8*)GetBgCharBase(0) + 0x800, 0x800);
            break;
        case 2:
            RequestDma3Copy((void*)gUnkEu_0996E930, (u8*)GetBgCharBase(0) + 0x800, 0x800);
            break;
        }
#endif

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
        w->tiles5 = AllocObjTiles(0x280, gUnk_0919FDF8);
        w->tiles6 = AllocObjTiles(0x400, gUnk_091ABDB8);
        w->palette3 = LoadObjPalette(gUnk_09991D24, 32);
        w->tiles3 = LoadObjTiles(gUnk_098A8F8A, 0x4C0);
        w->palette = LoadObjPalette(gUnk_099919A4, 32);
        w->tiles = AllocObjTiles(0x120, gUnk_098A8628);
        AnimInit(&w->anim, gUnk_09EF8D58, gUnk_09EF8D48);
        AnimStart(&w->anim, 2, 1);
        w->palette8 = _08066468(1);
        p1 = w->unk_194;
#ifdef VERSION_EU
        InitTextSlots(p1, 54);
#else
        InitTextSlots(p1, 27);
#endif
        p2 = w->unk_270;
        InitTextSlots(p2, 6);
        p3 = w->unk_2A4;
        InitTextSlots(p3, 9);
#ifdef VERSION_EU
        w->unk_26C = LoadTextSlots(eu_0805E924(gUnkEu_08892864), p1);
        w->unk_2A0 = LoadTextSlots(eu_0805E924(gUnkEu_08890E1C), p2);
        w->unk_2EC = LoadTextSlots(eu_0805E924(gUnkEu_08890E44), p3);
#else
        w->unk_26C = LoadTextSlots(gUnk_08159DF0, p1);
        w->unk_2A0 = LoadTextSlots(gUnk_08159E10, p2);
        w->unk_2EC = LoadTextSlots(gUnk_08159E18, p3);
#endif
        func_080EE50C((UnkStruct_080EE50C*)w, 1);
        w->unk_2F8 = 1;
        w->unk_2F4 = 2;
        w->x2 = 0xB000;
        w->update = func_080EEB00;
    }
    return 1;
}

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
        w->update = func_080EEC9C;
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

#ifdef VERSION_EU
        w->unk_26C = LoadTextSlots(eu_0805E924(gUnkEu_088928E4), w->unk_194);
#else
        w->unk_26C = LoadTextSlots(gUnk_0815B5A6, w->unk_194);
#endif
        w->unk_2A0 = 0;
        w->unk_2EC = 0;
        w->unk_2F4 = 0;
        w->update = func_080EEC5C;
    }

    return 1;
}

s32 func_080EEC5C(MapSaveWork* w) {
    if (GetKeysPressed() & 3) {
        w->unk_2F8 = 0;
        DisableBg(0);
        w->unk_2F6 = 16;
        w->update = func_080EEC9C;
    }

    return 1;
}

s32 func_080EEC9C(MapSaveWork* w) {
    if (w->unk_2F6 != 0) {
        ApproachValue(&w->x, -0x8000, w->unk_2F6);
        ApproachValue(&w->x3, w->unk_178, w->unk_2F6);
        ApproachValue(&w->y3, w->unk_17C, w->unk_2F6);
        w->unk_2F6--;
    } else {
        gUnk_0203C7AC->unk_00 &= ~0x1000;
        gUnk_02039BA0->unk_70 &= ~0x100;
        func_080EE50C((UnkStruct_080EE50C*)w, 0);
        FadeToOriginal(0, 16);
        w->unk_2F6 = 16;
        w->update = func_080EED44;
    }

    return 1;
}

s32 func_080EED44(MapSaveWork* w) {
    if (w->unk_2F6 != 0) {
        ApproachValue(&w->y, -0x800, w->unk_2F6);
        ApproachValue(&w->y2, 0xA000, w->unk_2F6);
        w->unk_2F6--;
        return 1;
    }

    return 0;
}

void Task_MapSave_0(MapSaveWork* w) {
    gUnk_02039BA0->unk_70 |= 0x1000;
    gUnk_02039BA0->unk_70 |= 0x80;
    gUnk_0203C7AC->unk_00 |= 0x2000;
    gGameState.hp = gGameState.progression.maxHp;
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        w->tiles2 = LoadObjTiles(gUnk_098A8C66, 0x2C0);
        break;
    case 1:
        w->tiles2 = LoadObjTiles(gUnkEu_098863B2, 0x400);
        break;
    case 4:
        w->tiles2 = LoadObjTiles(gUnkEu_0988683C, 0x3C0);
        break;
    case 3:
        w->tiles2 = LoadObjTiles(gUnkEu_09886C7E, 0x2C0);
        break;
    case 2:
    default:
        w->tiles2 = LoadObjTiles(gUnkEu_09886FC8, 0x3C0);
        break;
    }
    w->palette2 = LoadObjPalette(gUnk_09991D04, 32);
#else
    w->palette2 = LoadObjPalette(gUnk_09991D04, 32);
    w->tiles2 = LoadObjTiles(gUnk_098A8C66, 0x2C0);
#endif
    w->y = -0x800;
    w->y2 = 0xA000;
    w->x = -0x8000;

    if (gGameState.flags & 8) {
        w->tiles4 = AllocObjTiles(0x400, gUnk_092EB78A);
        w->palette5 = LoadObjPalette(gUnk_09618118, 32);
    } else {
        w->tiles4 = AllocObjTiles(0x340, gUnk_088B6560);
        w->palette5 = LoadObjPalette(gUnk_08F683A4, 32);
    }

    w->palette6 = LoadObjPalette(gUnk_09617C58, 32);
    w->palette7 = LoadObjPalette(gUnk_08F68384, 32);
    w->unk_178 = gUnk_02039BA0->actor.fieldPosition.x - gUnk_02039BA0->x;
    w->unk_17C = gUnk_02039BA0->actor.fieldPosition.y + gUnk_02039BA0->actor.fieldPosition.z - gUnk_02039BA0->y;
    w->x3 = w->unk_178;
    w->y3 = w->unk_17C;
    w->unk_2F4 = 0;
    w->unk_2F8 = 0;
    w->unk_2F6 = 16;
    w->update = func_080EE7B0;
    TaskPoolInit(&w->tasks, 1);
    func_080EE580((UnkStruct_080EE580*)w, 1);
    FadeToAmount(0, 16, 16);
    m4aSongNumStart(103);
}

s32 Task_MapSave_1(MapSaveWork* w) {
    TaskPoolUpdate(&w->tasks);

    if (w->unk_2F4 != 0) {
        AnimUpdate(&w->anim);
    }

    if (w->update != 0) {
        if ((u8)w->update(w) == 0) {
            return 0;
        }
    }
    return 1;
}

void Task_MapSave_2(MapSaveWork* w) {
    TaskPoolDraw(&w->tasks);
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        DrawSprite(128, w->y >> 8, gUnkEu_09F8447C[1], w->tiles2, w->palette2, 0, 0x400, 90);
        DrawSprite(128, w->y2 >> 8, gUnkEu_09F8447C[2], w->tiles2, w->palette2, 0, 0x400, 90);
        DrawSprite(w->x >> 8, 0, gUnkEu_09F8447C[0], w->tiles2, w->palette2, 0, 0x400, 80);
        break;
    case 1:
        DrawSprite(128, w->y >> 8, gUnk_09EF8D8C[1], w->tiles2, w->palette2, 0, 0x400, 90);
        DrawSprite(128, w->y2 >> 8, gUnk_09EF8D8C[2], w->tiles2, w->palette2, 0, 0x400, 90);
        DrawSprite(w->x >> 8, 0, gUnk_09EF8D8C[0], w->tiles2, w->palette2, 0, 0x400, 80);
        break;
    case 4:
        DrawSprite(128, w->y >> 8, gUnkEu_09F8444C[1], w->tiles2, w->palette2, 0, 0x400, 90);
        DrawSprite(128, w->y2 >> 8, gUnkEu_09F8444C[2], w->tiles2, w->palette2, 0, 0x400, 90);
        DrawSprite(w->x >> 8, 0, gUnkEu_09F8444C[0], w->tiles2, w->palette2, 0, 0x400, 80);
        break;
    case 3:
        DrawSprite(128, w->y >> 8, gUnkEu_09F8445C[1], w->tiles2, w->palette2, 0, 0x400, 90);
        DrawSprite(128, w->y2 >> 8, gUnkEu_09F8445C[2], w->tiles2, w->palette2, 0, 0x400, 90);
        DrawSprite(w->x >> 8, 0, gUnkEu_09F8445C[0], w->tiles2, w->palette2, 0, 0x400, 80);
        break;
    case 2:
    default:
        DrawSprite(128, w->y >> 8, gUnkEu_09F8446C[1], w->tiles2, w->palette2, 0, 0x400, 90);
        DrawSprite(128, w->y2 >> 8, gUnkEu_09F8446C[2], w->tiles2, w->palette2, 0, 0x400, 90);
        DrawSprite(w->x >> 8, 0, gUnkEu_09F8446C[0], w->tiles2, w->palette2, 0, 0x400, 80);
        break;
    }
#else
    DrawSprite(128, w->y >> 8, gUnk_09EF8D8C[1], w->tiles2, w->palette2, 0, 0x400, 90);
    DrawSprite(128, w->y2 >> 8, gUnk_09EF8D8C[2], w->tiles2, w->palette2, 0, 0x400, 90);
    DrawSprite(w->x >> 8, 0, gUnk_09EF8D8C[0], w->tiles2, w->palette2, 0, 0x400, 80);
#endif

    if (gUnk_0203C7AC->unk_00 & 0x1000) {
        if (gGameState.flags & 8) {
            DrawSprite(w->x3 >> 8, w->y3 >> 8, gUnk_09EEF89C[0], w->tiles4, w->palette5,
                0, 0x400, 80);
        } else {
            DrawSprite(w->x3 >> 8, w->y3 >> 8, ((void**)gUnk_09EDE8CC)[0], w->tiles4,
                w->palette5, 0, 0x400, 80);
        }
    }

    if (w->unk_2F8 != 0) {
        if (!(gGameState.flags & 8)) {
            DrawSprite(72, 96, ((void**)gUnk_09EEE03C)[0], w->tiles5, w->palette6, 0, 0x401, 81);
            DrawSprite(40, 96, ((void**)gUnk_09EEE1C8)[0], w->tiles6, w->palette7, 0, 0x400, 81);
        }

        DrawSprite(0, 16, gUnk_098A8F28, w->tiles3, w->palette3, 0, 0x400, 90);
        DrawTextSlots(100, 59, w->unk_044, w->palette4, 50, w->unk_044[0x120]);

        if (w->unk_2F4 != 0) {
#ifdef VERSION_EU
            DrawTextSlots(166 - (GetTextSlotsWidth(w->unk_194, w->unk_26C) >> 1), 92, w->unk_194, w->palette8, 50, w->unk_26C);
#elif defined(VERSION_JP)
            DrawTextSlots(129, 92, w->unk_194, w->palette8, 50, w->unk_26C);
#else
            DrawTextSlots(124, 92, w->unk_194, w->palette8, 50, w->unk_26C);
#endif
            DrawTextSlots(128, 114, w->unk_270, w->palette8, 50, w->unk_2A0);
            DrawTextSlots(184, 114, w->unk_2A4, w->palette8, 50, w->unk_2EC);
        } else {
#ifdef VERSION_EU
            DrawTextSlots(166 - (GetTextSlotsWidth(w->unk_194, w->unk_26C) >> 1), 102, w->unk_194, w->palette8, 50, w->unk_26C);
#elif defined(VERSION_JP)
            DrawTextSlots(129, 103, w->unk_194, w->palette8, 50, w->unk_26C);
#else
            DrawTextSlots(130, 102, w->unk_194, w->palette8, 50, w->unk_26C);
#endif
        }

        switch (w->unk_2F4) {
        case 1:
            ApproachValueHalf(&w->x2, 0x7800);
            DrawSprite(w->x2 >> 8, 110, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, 1,
                40);
            break;
        case 2:
            ApproachValueHalf(&w->x2, 0xB000);
            DrawSprite(w->x2 >> 8, 110, AnimGetGfx(&w->anim), w->tiles, w->palette, 0, 1,
                40);
            break;
        }
    }
}

void Task_MapSave_3(MapSaveWork* w) {
    u32 f;

    func_080EE580((UnkStruct_080EE580*)w, 0);
    ReleaseObjPalette((u8*)w->palette2);
    ReleaseObjTiles(w->tiles2);
    ReleaseObjPalette((u8*)w->palette3);
    ReleaseObjTiles(w->tiles3);
    ReleaseObjPalette((u8*)w->palette);
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette((u8*)w->palette5);
    ReleaseObjTiles(w->tiles4);
    ReleaseObjPalette((u8*)w->palette6);
    ReleaseObjTiles(w->tiles5);
    ReleaseObjPalette((u8*)w->palette7);
    ReleaseObjTiles(w->tiles6);
    ReleaseObjPalette((u8*)w->palette4);
    FreeTextSlots(w->unk_044, 36);
    ReleaseObjPalette((u8*)w->palette8);
#ifdef VERSION_EU
    FreeTextSlots(w->unk_194, 54);
#else
    FreeTextSlots(w->unk_194, 27);
#endif
    FreeTextSlots(w->unk_270, 6);
    FreeTextSlots(w->unk_2A4, 9);
    f = gUnk_0203C7AC->unk_00 & ~0x80;
    gUnk_0203C7AC->unk_00 = f;
    gUnk_02039BA0->unk_70 &= ~0x1000;
    gUnk_02039BA0->unk_70 &= ~0x80;
    gUnk_0203C7AC->unk_00 = f & ~0x2000;
    TaskPoolDestroy(&w->tasks);
}

void Task_MapAnm_0(MapAnmWork* work, MapAnmEntry* list) {
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
                func_080E8B1C(e, (const UnkStruct_080E7D80*)list);
                e++;
                list++;
            } while (list->unk_00 != 0);
        }
    }
}

s32 Task_MapAnm_1(MapAnmWork* w) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (w->unk_00[i].unk_14 != 0) {
            func_080E8BA0(&w->unk_00[i]);
        }
    }
    return 1;
}

void Task_MapAnm_2(MapAnmWork* w) {
}

void Task_MapAnm_3(MapAnmWork* w) {
}

const char gModeNameMapDbg[] = "Mode_MapDbg";

const char gModeNameMapFld[] = "Mode_MapFld";

const u8 gUnk_0984B8F8[13] = { 12, 14, 17, 20, 23, 28, 32, 35, 38, 42, 50, 255, 68 };

#ifdef VERSION_EU
const u8 gUnk_0984B905[13] = { 155, 157, 255, 160, 163, 165, 166, 167, 173, 182, 189, 255, 0 };
#else
const u8 gUnk_0984B905[13] = { 157, 159, 255, 162, 165, 167, 168, 169, 175, 184, 191, 255, 0 };
#endif

const char gModeNameMapFix[] = "Mode_MapFix";

const char gModeNameMenuNew[] = "Mode_MenuNew";

const char gModeNameMenuLoad[] = "Mode_MenuLoad";

const char gModeNameMenuMsg[] = "Mode_MenuMsg";

const char gTaskNameMapRnd[] = "Task_MapRnd";

const char gTaskNameMapFix[] = "Task_MapFix";

const UnkStruct_0984B968 gUnk_0984B968[14] = {
    { gUnk_09991224, gUnk_0994DF64, gUnk_0994E364, gUnk_0994D764, gUnk_0994DB64, gUnk_0994EF64, gUnk_0994F364, gUnk_0994E764, gUnk_0994EB64 },
    { gUnk_09991104, gUnk_0993BF64, gUnk_0993C364, gUnk_0993B764, gUnk_0993BB64, gUnk_0993CF64, gUnk_0993D364, gUnk_0993C764, gUnk_0993CB64 },
    { gUnk_09991124, gUnk_0993DF64, gUnk_0993E364, gUnk_0993D764, gUnk_0993DB64, gUnk_0993EF64, gUnk_0993F364, gUnk_0993E764, gUnk_0993EB64 },
    { gUnk_09991144, gUnk_0993FF64, gUnk_09940364, gUnk_0993F764, gUnk_0993FB64, gUnk_09940F64, gUnk_09941364, gUnk_09940764, gUnk_09940B64 },
    { gUnk_09991224, gUnk_0994DF64, gUnk_0994E364, gUnk_0994D764, gUnk_0994DB64, gUnk_0994EF64, gUnk_0994F364, gUnk_0994E764, gUnk_0994EB64 },
    { gUnk_099911C4, gUnk_09947F64, gUnk_09948364, gUnk_09947764, gUnk_09947B64, gUnk_09948F64, gUnk_09949364, gUnk_09948764, gUnk_09948B64 },
    { gUnk_09991184, gUnk_09943F64, gUnk_09944364, gUnk_09943764, gUnk_09943B64, gUnk_09944F64, gUnk_09945364, gUnk_09944764, gUnk_09944B64 },
    { gUnk_099911E4, gUnk_09949F64, gUnk_0994A364, gUnk_09949764, gUnk_09949B64, gUnk_0994AF64, gUnk_0994B364, gUnk_0994A764, gUnk_0994AB64 },
    { gUnk_099911A4, gUnk_09945F64, gUnk_09946364, gUnk_09945764, gUnk_09945B64, gUnk_09946F64, gUnk_09947364, gUnk_09946764, gUnk_09946B64 },
    { gUnk_09991164, gUnk_09941F64, gUnk_09942364, gUnk_09941764, gUnk_09941B64, gUnk_09942F64, gUnk_09943364, gUnk_09942764, gUnk_09942B64 },
    { gUnk_09991204, gUnk_0994BF64, gUnk_0994C364, gUnk_0994B764, gUnk_0994BB64, gUnk_0994CF64, gUnk_0994D364, gUnk_0994C764, gUnk_0994CB64 },
    { gUnk_09991264, gUnk_09951F64, gUnk_09952364, gUnk_09951764, gUnk_09951B64, gUnk_09952F64, gUnk_09953364, gUnk_09952764, gUnk_09952B64 },
    { gUnk_09991244, gUnk_0994FF64, gUnk_09950364, gUnk_0994F764, gUnk_0994FB64, gUnk_09950F64, gUnk_09951364, gUnk_09950764, gUnk_09950B64 },
    { gUnk_09991224, gUnk_0994DF64, gUnk_0994E364, gUnk_0994D764, gUnk_0994DB64, gUnk_0994EF64, gUnk_0994F364, gUnk_0994E764, gUnk_0994EB64 },
};

const char gTaskNameMapDoor[] = "Task_MapDoor";

const char gTaskNameMapMenu[] = "Task_MapMenu";

const char gTaskNameMapSave[] = "Task_MapSave";

const char gTaskNameMapAnm[] = "Task_MapAnm";

u8 gUnk_09EF6A34[14] = {
    40,
    40,
    50,
    30,
    20,
    80,
    60,
    70,
    100,
    0,
    10,
    90,
    110,
    40,
};

u8 gUnk_09EF6A42[14] = {
    40,
    40,
    50,
    30,
    20,
    80,
    60,
    70,
    134,
    0,
    10,
    90,
    110,
    40,
};

u8 (*gUnk_09EF6A50[14])(UnkStruct_080DFF1C*) = {
    func_080E6B24,
    func_080E6C2C,
    func_080E6F04,
    func_080E77A4,
    func_080E7088,
    func_080E71F0,
    func_080E7358,
    func_080E74D8,
    func_080E7620,
    func_080E7928,
    func_080E6DB0,
    func_080E7A30,
    func_080E7B38,
    func_080E7C40,
};

u8 (*gUnk_09EF6A88[2])(UnkStruct_080E8B1C*) = {
    func_080E8BD8,
    func_080E8C30,
};

Mode gModeMapDbg = {
    gModeNameMapDbg,
    (void (*)(s32))Mode_MapDbg_0,
    (void (*)(void))Mode_MapDbg_1,
    (void (*)(void))Mode_MapDbg_2,
};

Mode gModeMapFld = {
    gModeNameMapFld,
    (void (*)(s32))Mode_MapFld_0,
    (void (*)(void))Mode_MapFld_1,
    (void (*)(void))Mode_MapFld_2,
};

u8 gUnk_09EF6AB0[14] = {
#if defined(VERSION_US)
    255,
    107,
    101,
    120,
    94,
    74,
    87,
    115,
    129,
    53,
    2,
    44,
    61,
    135,
#elif defined(VERSION_JP)
    255,
    107,
    101,
    120,
    94,
    74,
    87,
    115,
    129,
    53,
    2,
    44,
    61,
    135,
#elif defined(VERSION_EU)
    255,
    107,
    101,
    120,
    94,
    74,
    87,
    115,
    127,
    53,
    2,
    44,
    61,
    133,
#endif
};

Mode gModeMapFix = {
    gModeNameMapFix,
    (void (*)(s32))Mode_MapFix_0,
    (void (*)(void))Mode_MapFix_1,
    (void (*)(void))Mode_MapFix_2,
};

Mode gModeMenuNew = {
    gModeNameMenuNew,
    (void (*)(s32))Mode_MenuNew_0,
    (void (*)(void))Mode_MenuNew_1,
    (void (*)(void))Mode_MenuNew_2,
};

Mode gModeMenuLoad = {
    gModeNameMenuLoad,
    (void (*)(s32))Mode_MenuLoad_0,
    (void (*)(void))Mode_MenuLoad_1,
    (void (*)(void))Mode_MenuLoad_2,
};

Mode gModeMenuMsg = {
    gModeNameMenuMsg,
    (void (*)(s32))func_080EC57C,
    (void (*)(void))Mode_MenuMsg_1,
    (void (*)(void))Mode_MenuMsg_2,
};

TaskDesc gTaskDescMapRnd = {
    gTaskNameMapRnd,
    (void (*)(void*, void*))Task_MapRnd_0,
    Task_MapRnd_1,
    (void (*)(void*))Task_MapRnd_2,
    (void (*)(void*))Task_MapRnd_3,
    0x14,
};

TaskDesc gTaskDescMapFix = {
    gTaskNameMapFix,
    (void (*)(void*, void*))Task_MapFix_0,
    Task_MapFix_1,
    (void (*)(void*))Task_MapFix_2,
    (void (*)(void*))Task_MapFix_3,
#ifdef VERSION_EU
    0x1E8,
#else
    0x1E4,
#endif
};

TaskDesc gTaskDescMapDoor = {
    gTaskNameMapDoor,
    (void (*)(void*, void*))Task_MapDoor_0,
    Task_MapDoor_1,
    (void (*)(void*))Task_MapDoor_2,
    (void (*)(void*))Task_MapDoor_3,
    0x88,
};

TaskDesc gTaskDescMapMenu = {
    gTaskNameMapMenu,
    (void (*)(void*, void*))Task_MapMenu_0,
    Task_MapMenu_1,
    (void (*)(void*))Task_MapMenu_2,
    (void (*)(void*))Task_MapMenu_3,
#ifdef VERSION_EU
    0x41C,
#else
    0x314,
#endif
};

TaskDesc gTaskDescMapSave = {
    gTaskNameMapSave,
    (void (*)(void*, void*))Task_MapSave_0,
    Task_MapSave_1,
    (void (*)(void*))Task_MapSave_2,
    (void (*)(void*))Task_MapSave_3,
#ifdef VERSION_EU
    0x3E8,
#else
    0x310,
#endif
};

TaskDesc gTaskDescMapAnm = {
    gTaskNameMapAnm,
    (void (*)(void*, void*))Task_MapAnm_0,
    Task_MapAnm_1,
    (void (*)(void*))Task_MapAnm_2,
    (void (*)(void*))Task_MapAnm_3,
    0xE0,
};
