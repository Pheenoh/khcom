#include "engine_math.h"
#include "m4a_song.h"
#include "text.h"
#include "fade.h"
#include "obj_api.h"
#include "display.h"
#include "macros.h"
#include "malloc.h"
#include "mode_worldinspect.h"
#include "game_state.h"
#include "gba/keys.h"
#include "anim.h"
#include "m4a.h"
#ifdef VERSION_EU
extern u8 gUnkEu_09A86E60[];
extern u32 gLanguage;
extern u8 gUnkEu_09A2D440[];
extern u8 gUnkEu_09A2E440[];
extern u8 gUnkEu_09A2F440[];
extern u8 gUnkEu_09A30440[];
extern u8 gUnkEu_09A2CC40[];
extern u8 gUnkEu_09A2DC40[];
extern u8 gUnkEu_09A2EC40[];
extern u8 gUnkEu_09A2FC40[];
extern u8 gUnkEu_099A4CDA[];
extern u8 gUnkEu_099A51AA[];
extern u8 gUnkEu_099A563A[];
extern u8 gUnkEu_099A5ACA[];
extern u8 gUnkEu_099AABA4[];
extern u8 gUnkEu_099AABBA[];
extern u8 gUnkEu_099AABEE[];
extern u8 gUnkEu_099AB990[];
extern u8 gUnkEu_099AB9A6[];
extern u8 gUnkEu_099AB9DA[];
extern u8 gUnkEu_099ABF18[];
extern u8 gUnkEu_099ABF2E[];
extern u8 gUnkEu_099ABF62[];
extern u8 gUnkEu_099AC3E0[];
extern u8 gUnkEu_099AC3F6[];
extern u8 gUnkEu_099AC42A[];
extern u8 gUnkEu_099AC968[];
extern u8 gUnkEu_099AC97E[];
extern u8 gUnkEu_099AC9B2[];
#endif

typedef struct {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    s16 unk_0E;
    s16 unk_10;
    u8 unk_12[0x02];
} WorldinspectWarpIcon;

extern s16 gUnk_020354E8;
extern s16 gUnk_020357A2;
extern s32 gUnk_020357A8[2];
extern s32 gUnk_020357B0;
extern s32 gUnk_020357B4;
extern s32 gUnk_020357B8;
extern struct ObjTiles* gUnk_02035510;
extern struct ObjPaletteNode* gUnk_02035514;
extern struct ObjTiles* gUnk_02035518;
extern struct ObjPaletteNode* gUnk_0203551C;
extern AnimState gUnk_02035520;
extern AnimState gUnk_02035538;
extern struct ObjTiles* gUnk_02035550;
extern struct ObjPaletteNode* gUnk_02035554;
extern AnimState gUnk_02035558;
extern void* gUnk_02035570[];
extern void* gUnk_020355A8[];
extern void* gUnk_020355E0[];
extern u8 gUnk_02035618[];
extern u8 gUnk_020356D8;
extern u8 gUnk_020356E0[];
extern u8 gUnk_020357A0;
extern WorldinspectWarpIcon gUnk_09EF9384[];
extern u8 gUnk_0999F400[];
extern u8 gUnk_0999F416[];
extern u8 gUnk_0999F44A[];

typedef struct {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    s16 unk_0E;
    s16 unk_10;
    u8 unk_12[0x02];
} WorldinspectNav;

typedef struct {
    u16 unk_00;
    u16 unk_02;
    void* unk_04;
    u16 unk_08;
    u8 unk_0A[0x02];
    void* unk_0C;
    u16 unk_10;
    u8 unk_12[0x02];
    void* unk_14;
    void* unk_18;
    u16 unk_1C;
    u8 unk_1E[0x02];
    void* unk_20;
    u16 unk_24;
    u8 unk_26[0x02];
    void* unk_28;
    void* unk_2C;
    u16 unk_30;
    u16 unk_32;
} WorldinspectMsg;

typedef struct {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
} WorldinspectConn;

extern s16 gUnk_020350F8;
extern s16 gUnk_020350FA;
extern s16 gUnk_02035100[];
extern u8 gUnk_020352B8;
extern s16 gUnk_020354F0[];
extern s16 gUnk_0203550A;
extern s16 gUnk_020357A4;
extern u16 gUnk_02039D30;
extern WorldinspectNav gUnk_09EF8FAC[];
extern WorldinspectMsg gUnk_09EF909C[];
extern WorldinspectConn gUnk_099930BC[];
extern u8 gUnk_099FB53C[];
extern u8 gUnk_09A324DC[];
extern u8 gUnk_09A32EDC[];
extern u8 gUnk_09A333DC[];
extern u8 gUnk_09A3399C[];
extern u8 gUnk_09A33E9C[];
extern u8 gUnk_09A3CE7C[];
extern u8 gUnk_09A3D07C[];
extern u8 gUnk_09A3D09C[];
extern u8 gUnk_09A3D0BC[];
extern u8 gUnk_0999CFC6[];
extern u8 gUnk_0999D41A[];
extern u8 gUnk_0999D8A8[];
extern u8 gUnk_09EF97B0[];
extern u8 gUnk_09EF97C4[];
extern u8 gUnk_09EF97CC[];
extern u8 gUnk_09EF97DC[];
extern u8 gUnk_09A35A1C[];
extern u8 gUnk_09A0D63C[];
extern u8 gUnk_09A0F03C[];
#ifdef VERSION_EU
extern u8 gUnk_09A53380[];
extern u8 gUnk_09A59B80[];
extern u8 gUnk_09A54080[];
extern u8 gUnk_09A5A880[];
extern u8 gUnk_09A54D80[];
extern u8 gUnk_09A5B580[];
extern u8 gUnk_09A55A80[];
extern u8 gUnk_09A5C280[];
#endif
void func_080FF19C(s16 w, s16 h, u16* src, s16 sx, s16 sy, u16* dst, s16 dx, s16 dy);
void func_080FF10C(u8 pal, u16 w, s16 h, u16* map, s16 x, s16 y);
void func_080FF2B8(s16 index);
u8 func_080FF228(s16 id);

s16 gUnk_02035118;
u8 gUnk_0203511A;
struct ObjPaletteNode* gUnk_0203511C;
struct ObjTiles* gUnk_02035120;
struct ObjPaletteNode* gUnk_02035124;
struct ObjTiles* gUnk_02035128;
s32 gUnk_0203512C;
u8 gUnk_02035130[0x18];
struct ObjPaletteNode* gUnk_02035148;
struct ObjTiles* gUnk_0203514C;
u8 gUnk_02035150[0x18];
void* gUnk_02035168[12];
void* gUnk_02035198[12];
void* gUnk_020351C8[12];
u8 gUnk_020351F8[0xC8];
#ifdef VERSION_EU
u8 gUnkEu_020354B0[0xC0];
#endif
u8 gUnk_020352C0[0x200];
#ifdef VERSION_EU
u8 gUnkEu_02035770[0x1E0];
#endif
s16 gUnk_020354C0;
s16 gUnk_020354C2;
s32 gUnk_020354C4;
s32 gUnk_020354C8[2];
s32 gUnk_020354D0;
void* gUnk_020354D4;
s32 gUnk_020354D8;
s32 gUnk_020354DC;
u8 gUnk_020354E0;

void mode_worldinspect_0(void) {
    s16 i;
    s32 floor;
    s16 id;
    void** p;
    u32 floorKeep;
    s16 fa;
    vu32* dma;

    p = &gUnk_020354D4;
    *p = EwramAlloc(0x500);
    SpriteReset();
    func_08006120(0, 16);
    SetBgMode0();
    SetupBg(0, 0, 0x1C, 0);
    SetupBg(1, 0, 0x1D, 0);
    SetupBg(2, 0, 0x1E, 0);
    SetupBg(3, 0, 0x1F, 0);
    SetBgPriority(0, 3);
    SetBgPriority(1, 2);
    SetBgPriority(2, 1);
    SetBgPriority(3, 0);
    floor = gGameState.floor;
    floorKeep = (u16)floor;
    gUnk_020350F8 = gGameState.floor > 11 ? 11 : floor;

    gUnk_020350FA = 0;

    for (i = 0; i <= 11; i++) {
        gUnk_02035100[i] = gGameState.floors[i].world;

        if (gUnk_02035100[i] != 0) {
            gUnk_020350FA = i + 1;
        }
    }

    for (i = 0, fa = gUnk_020350FA; i <= 13; i++) {
        if ((gUnk_02039D30 & gUnk_09EF909C[i].unk_00) != 0) {
            gUnk_02035100[fa++] = gUnk_09EF909C[i].unk_02;

            if (fa > 11) {
                break;
            }
        }
    }

    gUnk_02035118 = 0;
    gUnk_0203511A = 0;
    gUnk_020354D8 = (gUnk_09EF8FAC[gUnk_020350F8].unk_08 << 11) + 0x2000;
    gUnk_020354DC = (gUnk_09EF8FAC[gUnk_020350F8].unk_0A << 11) - 0x600;
    gUnk_020354C0 = 0;
    gUnk_020354C2 = 16;
    gUnk_020354C8[0] = -0x800;
    gUnk_020354C8[1] = 0xA800;
    gUnk_020354D0 = -0x8000;
    LoadBgPalette(0, gUnk_09A3CE7C, 0x200);

    for (i = 0; i <= 11; i++) {
        if (gUnk_02035100[i] != 0) {
            id = gUnk_02035100[i];
            gUnk_02035168[i] = LoadObjPalette(gUnk_09EF909C[id].unk_04, gUnk_09EF909C[id].unk_08);
            id = gUnk_02035100[i];
            gUnk_02035198[i] = LoadObjTiles(gUnk_09EF909C[id].unk_0C, gUnk_09EF909C[id].unk_10);
            id = gUnk_02035100[i];
            gUnk_020351C8[i] = gUnk_09EF909C[id].unk_14;
        } else {
            gUnk_02035168[i] = 0;
            gUnk_02035198[i] = 0;
            gUnk_020351C8[i] = 0;
        }
    }

    LoadBgTiles(0, gUnk_099FB53C, 0x6BC0);
#ifdef VERSION_EU
    if (gGameState.flags & 8) {
        switch (gLanguage) {
        case 1:
            RequestDma3Copy(gUnkEu_09A2D440, (u8*)GetBgCharBase(0) + 0x6400, 0x800);
            break;
        case 4:
            RequestDma3Copy(gUnkEu_09A2E440, (u8*)GetBgCharBase(0) + 0x6400, 0x800);
            break;
        case 3:
            RequestDma3Copy(gUnkEu_09A2F440, (u8*)GetBgCharBase(0) + 0x6400, 0x800);
            break;
        case 2:
            RequestDma3Copy(gUnkEu_09A30440, (u8*)GetBgCharBase(0) + 0x6400, 0x800);
            break;
        }
    } else {
        switch (gLanguage) {
        case 1:
            RequestDma3Copy(gUnkEu_09A2CC40, (u8*)GetBgCharBase(0) + 0x800, 0x800);
            break;
        case 4:
            RequestDma3Copy(gUnkEu_09A2DC40, (u8*)GetBgCharBase(0) + 0x800, 0x800);
            break;
        case 3:
            RequestDma3Copy(gUnkEu_09A2EC40, (u8*)GetBgCharBase(0) + 0x800, 0x800);
            break;
        case 2:
            RequestDma3Copy(gUnkEu_09A2FC40, (u8*)GetBgCharBase(0) + 0x800, 0x800);
            break;
        }
    }
#endif

    LoadBgMap(0, gUnk_09A324DC, 0x500);
    dma = (vu32*)0x040000D4;
    dma[0] = (u32)gUnk_09A32EDC;
    dma[1] = (u32)gUnk_020354D4;
    dma[2] = 0x80000280;
    dma[2];

    for (i = 0; i <= 11; i++) {
        if (gUnk_02035100[i] != 0) {
            func_080FF19C(7, 4, gUnk_09A333DC, 0, 0, gUnk_020354D4, gUnk_09EF8FAC[i].unk_08, gUnk_09EF8FAC[i].unk_0A);
        }
    }

    for (i = 0; i < gUnk_020350FA - 1; i++) {
        if (gUnk_02035100[i] != 0 && gUnk_02035100[i + 1] != 0) {
            WorldinspectConn* conn = gUnk_099930BC;
            id = gUnk_09EF8FAC[i].unk_0C;
            func_080FF19C(conn[id].unk_00, conn[id].unk_02, gUnk_09A333DC, conn[id].unk_04, conn[id].unk_06, gUnk_020354D4, gUnk_09EF8FAC[i].unk_0E, gUnk_09EF8FAC[i].unk_10);
        }
    }

    for (i = 0; i < gUnk_020350FA; i++) {
        if (gUnk_02035100[i] != 0) {
            if ((gGameState.flags & 8) == 0) {
                if (i <= 8) {
                    func_080FF19C(3, 1, gUnk_09A333DC, i * 3, 9, gUnk_020354D4, gUnk_09EF8FAC[i].unk_08 + 3, gUnk_09EF8FAC[i].unk_0A + 2);
                } else {
                    func_080FF19C(4, 1, gUnk_09A333DC, (i - 9) * 4, 10, gUnk_020354D4, gUnk_09EF8FAC[i].unk_08 + 3, gUnk_09EF8FAC[i].unk_0A + 2);
                }
            } else {
                if (i <= 2) {
                    func_080FF19C(4, 1, gUnk_09A333DC, i * 4, 0x15, gUnk_020354D4, gUnk_09EF8FAC[i].unk_08 + 3, gUnk_09EF8FAC[i].unk_0A + 2);
                } else {
                    func_080FF19C(3, 1, gUnk_09A333DC, (i - 3) * 3, 0x16, gUnk_020354D4, gUnk_09EF8FAC[i].unk_08 + 3, gUnk_09EF8FAC[i].unk_0A + 2);
                }
            }
        }
    }

    for (i = 0; i < gUnk_020350FA; i++) {
        if ((s16)floorKeep == i) {
            func_080FF10C(3, 7, 4, gUnk_020354D4, gUnk_09EF8FAC[i].unk_08, gUnk_09EF8FAC[i].unk_0A);
        } else {
            func_080FF10C(2, 7, 4, gUnk_020354D4, gUnk_09EF8FAC[i].unk_08, gUnk_09EF8FAC[i].unk_0A);
        }
    }

    LoadBgMap(1, gUnk_020354D4, 0x500);
    LoadBgMap(2, gUnk_09A33E9C, 0x500);
    LoadBgMap(3, gUnk_09A3399C, 0x500);
    func_080FF2B8(gUnk_020350F8);
    gUnk_02035124 = LoadObjPalette(gUnk_09A3D09C, 0x20);
    gUnk_02035128 = LoadObjTiles(gUnk_0999D41A, 0x400);
    AnimInit((AnimState*)gUnk_02035130, gUnk_09EF97C4, gUnk_09EF97B0);
    AnimStart((AnimState*)gUnk_02035130, 0, 1);
    gUnk_02035148 = LoadObjPalette(gUnk_09A3D0BC, 0x20);
    gUnk_0203514C = LoadObjTiles(gUnk_0999D8A8, 0xC0);
    AnimInit((AnimState*)gUnk_02035150, gUnk_09EF97DC, gUnk_09EF97CC);
    AnimStart((AnimState*)gUnk_02035150, 0, 1);
#ifdef VERSION_EU
    func_08065ACC(gUnk_020351F8, 0x30);
#else
    func_08065ACC(gUnk_020351F8, 0x18);
#endif
    gUnk_020352B8 = func_080FF228(gUnk_02035100[gUnk_020350F8]);
#ifdef VERSION_EU
    func_08065ACC(gUnk_020352C0, 0x78);
#else
    func_08065ACC(gUnk_020352C0, 0x3C);
#endif
    gUnk_0203511C = LoadObjPalette(gUnk_09A3D07C, 0x20);
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        gUnk_02035120 = LoadObjTiles(gUnk_0999CFC6, 0x400);
        break;
    case 1:
        gUnk_02035120 = LoadObjTiles(gUnkEu_099A4CDA, 0x440);
        break;
    case 4:
        gUnk_02035120 = LoadObjTiles(gUnkEu_099A51AA, 0x400);
        break;
    case 3:
        gUnk_02035120 = LoadObjTiles(gUnkEu_099A563A, 0x400);
        break;
    case 2:
    default:
        gUnk_02035120 = LoadObjTiles(gUnkEu_099A5ACA, 0x440);
        break;
    }
#elif defined(VERSION_JP)
    gUnk_02035120 = LoadObjTiles(gUnk_0999CFC6, 0x3C0);
#else
    gUnk_02035120 = LoadObjTiles(gUnk_0999CFC6, 0x400);
#endif
    EnableBg(0);
    EnableBg(1);
    DisableBg(2);
    DisableBg(3);
}

void mode_worldinspect_1(void) {
    UpdatePlayTime();
    gUnk_0203511A += 2;

    switch (gUnk_020354C0) {
    case 0:
        ApproachValue(&gUnk_020354C8[0], 0, gUnk_020354C2);
        ApproachValue(&gUnk_020354C8[1], 0x9800, gUnk_020354C2);
        gUnk_020354C2--;
        if (gUnk_020354C2 <= 0) {
            gUnk_020354C2 = 16;
            gUnk_020354C0 = 1;
        }
        break;
    case 1:
        ApproachValue(&gUnk_020354D0, 0, gUnk_020354C2);
        gUnk_020354C2--;
        if (gUnk_020354C2 <= 0) {
#ifdef VERSION_EU
            LoadBgMap(0, gUnkEu_09A86E60, 0x500);
#else
            LoadBgMap(0, gUnk_09A329DC, 0x500);
            ReleaseObjPalette(gUnk_0203511C);
#endif
            gUnk_020354C0 = 2;
        }
        break;
    case 2:
        switch (gUnk_02035118) {
        case 0:
            func_080FF330();
            break;
        case 1:
            func_080FF794();
            break;
        }
        break;
    case 3:
        ApproachValue(&gUnk_020354D0, -0x8000, gUnk_020354C2);
        gUnk_020354C2--;
        if (gUnk_020354C2 <= 0) {
            gUnk_020354C2 = 16;
            gUnk_020354C0 = 4;
        }
        break;
    case 4:
        ApproachValue(&gUnk_020354C8[0], -0x800, gUnk_020354C2);
        ApproachValue(&gUnk_020354C8[1], 0xA800, gUnk_020354C2);
        gUnk_020354C2--;
        if (gUnk_020354C2 <= 0) {
            func_08006184(0, 16);
            gUnk_020354C0 = 5;
        }
        break;
    case 5:
        if (!func_08006314()) {
            func_080E052C(gUnk_020354E0);
        }
        break;
    }

    func_080FF8CC();
}

void mode_worldinspect_2(void) {
    s32 i;

    ReleaseObjPalette(gUnk_0203511C);
    ReleaseObjTiles(gUnk_02035120);
    ReleaseObjPalette(gUnk_02035124);
    ReleaseObjTiles(gUnk_02035128);
    ReleaseObjPalette(gUnk_02035148);
    ReleaseObjTiles(gUnk_0203514C);

    for (i = 0; i < 12; i++) {
        if (gUnk_02035168[i]) {
            ReleaseObjPalette(gUnk_02035168[i]);
        }

        if (gUnk_02035198[i]) {
            ReleaseObjTiles(gUnk_02035198[i]);
        }
    }

#ifdef VERSION_EU
    func_08065AE0(gUnk_020351F8, 0x30);
#else
    func_08065AE0(gUnk_020351F8, 0x18);
#endif
#ifdef VERSION_EU
    func_08065AE0(gUnk_020352C0, 0x78);
#else
    func_08065AE0(gUnk_020352C0, 0x3C);
#endif
    EwramFree(gUnk_020354D4);
}

void func_081004EC(u8 pal, u16 w, s16 h, u16* map, s16 x, s16 y) {
    s16 i;
    s16 j;
    s16 n;
    u16 v;

    n = w;
    v = pal << 12;
    map += x + y * 32;

    for (j = 0; j < h; j++) {
        for (i = 0; i < n; i++) {
            *map = (*map & 0xFFF) | v;
            map++;
        }
        map += 32 - n;
    }
}

void func_0810057C(u16 w, s16 h, u16* src, s16 sx, s16 sy, u16* dst, s16 dx, s16 dy) {
    s16 i;
    s16 j;
    s16 n;

    n = w;
    src += sx + sy * 32;
    dst += dx + dy * 32;

    for (j = 0; j < h; j++) {
        for (i = 0; i < n; i++) {
            *dst++ = *src++;
        }
        src += 32 - n;
        dst += 32 - n;
    }
}

u8 func_08100608(s16 a) {
    if (a <= 0) {
        return 0;
    }
#ifdef VERSION_EU
    return func_08065B6C(eu_0805E924(gUnk_09EF9488[a].unk_14), gUnk_02035618);
#else
    return func_08065B6C(gUnk_09EF9488[a].unk_14, gUnk_02035618);
#endif
}

u8 func_0810063C(s16 a) {
    if (a <= 0) {
        return 0;
    }
#ifdef VERSION_EU
    return func_08065B6C(eu_0805E924(gUnk_09EF9488[a].unk_14), gUnk_020356E0);
#else
    return func_08065B6C(gUnk_09EF9488[a].unk_14, gUnk_020356E0);
#endif
}

void func_08100670(s16 a, u8* b, void* c) {
    RequestDma3Copy(b + a * 256, c, 0x100);
}

u16 func_0810068C(void) {
    s32 keys;

    keys = GetKeysPressed() & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON);
    keys |= GetKeysRepeat() & (DPAD_ANY | L_BUTTON | R_BUTTON);
    return keys;
}

void func_081006AC(void) {
    s16 prev;
    u16 keys;

    prev = gUnk_020354E8;
    keys = func_0810068C();

    if (keys & A_BUTTON) {
        if (gUnk_020354E8 == gGameState.floor) {
            gUnk_0203550A = -1;
            LoadBgMap(0, gUnk_09A35A1C, 0x500);
            gUnk_020357A4 = 16;
            gUnk_020357A2 = 3;
            m4aSongNumStart(0x68);
        } else {
            if (gUnk_020354F0[gUnk_020354E8] >= 0) {
                gUnk_0203550A = gUnk_020354E8;
                LoadBgMap(0, gUnk_09A35A1C, 0x500);
                gUnk_020357A4 = 16;
                gUnk_020357A2 = 3;
                m4aSongNumStart(0xCE);
            } else {
                m4aSongNumStart(0x69);
            }
        }
    } else if (keys & B_BUTTON) {
        gUnk_0203550A = -1;
        LoadBgMap(0, gUnk_09A35A1C, 0x500);
        gUnk_020357A4 = 16;
        gUnk_020357A2 = 3;
        m4aSongNumStart(0x68);
    } else if (keys & DPAD_UP) {
        do {
            gUnk_020354E8 = gUnk_09EF9384[gUnk_020354E8].unk_00;
            if (gUnk_020354E8 == prev) {
                break;
            }
        } while (gUnk_020354F0[gUnk_020354E8] == -1);
    } else if (keys & DPAD_DOWN) {
        do {
            gUnk_020354E8 = gUnk_09EF9384[gUnk_020354E8].unk_02;
            if (gUnk_020354E8 == prev) {
                break;
            }
        } while (gUnk_020354F0[gUnk_020354E8] == -1);
    } else if (keys & DPAD_LEFT) {
        do {
            gUnk_020354E8 = gUnk_09EF9384[gUnk_020354E8].unk_04;
            if (gUnk_020354E8 == prev) {
                break;
            }
        } while (gUnk_020354F0[gUnk_020354E8] == -1);
    } else if (keys & DPAD_RIGHT) {
        do {
            gUnk_020354E8 = gUnk_09EF9384[gUnk_020354E8].unk_06;
            if (gUnk_020354E8 == prev) {
                break;
            }
        } while (gUnk_020354F0[gUnk_020354E8] == -1);
    }

    if (gUnk_020354E8 != prev) {
#ifdef VERSION_EU
        switch (gLanguage) {
        case 0:
            if ((gGameState.flags & 8) == 0) {
                func_08100670(gUnk_020354E8, gUnk_09A0D63C, (u8*)GetBgCharBase(0) + 0x20);
            } else {
                func_08100670(gUnk_020354E8, gUnk_09A0F03C, (u8*)GetBgCharBase(0) + 0x20);
            }
            break;
        case 1:
            if ((gGameState.flags & 8) == 0) {
                func_08100670(gUnk_020354E8, gUnk_09A53380, (u8*)GetBgCharBase(0) + 0x20);
            } else {
                func_08100670(gUnk_020354E8, gUnk_09A59B80, (u8*)GetBgCharBase(0) + 0x20);
            }
            break;
        case 4:
            if ((gGameState.flags & 8) == 0) {
                func_08100670(gUnk_020354E8, gUnk_09A54080, (u8*)GetBgCharBase(0) + 0x20);
            } else {
                func_08100670(gUnk_020354E8, gUnk_09A5A880, (u8*)GetBgCharBase(0) + 0x20);
            }
            break;
        case 3:
            if ((gGameState.flags & 8) == 0) {
                func_08100670(gUnk_020354E8, gUnk_09A54D80, (u8*)GetBgCharBase(0) + 0x20);
            } else {
                func_08100670(gUnk_020354E8, gUnk_09A5B580, (u8*)GetBgCharBase(0) + 0x20);
            }
            break;
        case 2:
        default:
            if ((gGameState.flags & 8) == 0) {
                func_08100670(gUnk_020354E8, gUnk_09A55A80, (u8*)GetBgCharBase(0) + 0x20);
            } else {
                func_08100670(gUnk_020354E8, gUnk_09A5C280, (u8*)GetBgCharBase(0) + 0x20);
            }
            break;
        }
#else
        if ((gGameState.flags & 8) == 0) {
            func_08100670(gUnk_020354E8, gUnk_09A0D63C, (u8*)GetBgCharBase(0) + 0x20);
        } else {
            func_08100670(gUnk_020354E8, gUnk_09A0F03C, (u8*)GetBgCharBase(0) + 0x20);
        }
#endif
        gUnk_020357A0 = func_0810063C(gUnk_020354F0[gUnk_020354E8]);
        m4aSongNumStart(0x65);
    }
}

void func_08100980(void) {
    s32 i;
#ifdef VERSION_EU
    u8* tile0;
    u8* tile1;
    u8* tile2;

    switch (gLanguage) {
    case 0:
        tile0 = gUnkEu_099AABA4;
        tile1 = gUnkEu_099AABBA;
        tile2 = gUnkEu_099AABEE;
        break;
    case 1:
        tile0 = gUnkEu_099AB990;
        tile1 = gUnkEu_099AB9A6;
        tile2 = gUnkEu_099AB9DA;
        break;
    case 4:
        tile0 = gUnkEu_099ABF18;
        tile1 = gUnkEu_099ABF2E;
        tile2 = gUnkEu_099ABF62;
        break;
    case 3:
        tile0 = gUnkEu_099AC3E0;
        tile1 = gUnkEu_099AC3F6;
        tile2 = gUnkEu_099AC42A;
        break;
    case 2:
    default:
        tile0 = gUnkEu_099AC968;
        tile1 = gUnkEu_099AC97E;
        tile2 = gUnkEu_099AC9B2;
        break;
    }

    DrawSprite(gUnk_020357B0 >> 8, 0, tile0, gUnk_02035510, gUnk_02035514, 0, 0xC00, 0xBB8);
    if (gUnk_020357A2 != 2) {
        DrawSprite(0x80, gUnk_020357A8[0] >> 8, tile1, gUnk_02035510, gUnk_02035514, 0, 0xC00, 0xBB9);
        DrawSprite(0x80, gUnk_020357A8[1] >> 8, tile2, gUnk_02035510, gUnk_02035514, 0, 0xC00, 0xBB9);
    }
#else
    if (gUnk_020357A2 != 2) {
        DrawSprite(gUnk_020357B0 >> 8, 0, gUnk_0999F400, gUnk_02035510, gUnk_02035514, 0, 0xC00, 0xBB8);
        DrawSprite(0x80, gUnk_020357A8[0] >> 8, gUnk_0999F416, gUnk_02035510, gUnk_02035514, 0, 0xC00, 0xBB9);
        DrawSprite(0x80, gUnk_020357A8[1] >> 8, gUnk_0999F44A, gUnk_02035510, gUnk_02035514, 0, 0xC00, 0xBB9);
    }
#endif

    if (gUnk_020357A2 == 2) {
        DrawSprite((s16)(gUnk_09EF9384[gUnk_020354E8].unk_08 * 8 + 22),
            (s16)(gUnk_09EF9384[gUnk_020354E8].unk_0A * 8 + 12),
            AnimUpdate(&gUnk_02035520), gUnk_02035518, gUnk_0203551C, 0, 0x800, 0x898);
        func_0805F1C0(&gUnk_020357B4, (gUnk_09EF9384[gUnk_020354E8].unk_08 << 11) + 0x2000);
        func_0805F1C0(&gUnk_020357B8, (gUnk_09EF9384[gUnk_020354E8].unk_0A << 11) + 0xFFFFFA00);
        DrawSprite(gUnk_020357B4 >> 8, gUnk_020357B8 >> 8, AnimUpdate(&gUnk_02035558),
            gUnk_02035550, gUnk_02035554, 0, 0x800, 0x7D0);
    }

    for (i = 0; i <= 12; i++) {
        if (gUnk_020355E0[i] != 0) {
            DrawSprite((s16)(gUnk_09EF9384[i].unk_08 * 8 + 16), (s16)(gUnk_09EF9384[i].unk_0A * 8 + 16),
                gUnk_020355E0[i], gUnk_02035570[i], gUnk_020355A8[i], 0, 0x800, (u16)(i + 0x834));
        }
    }

    if (gUnk_020355E0[gGameState.floor] != 0) {
#ifdef VERSION_EU
        DrawSprite(0x66, 0x10, gUnk_020355E0[gGameState.floor], gUnk_02035570[gGameState.floor],
            gUnk_020355A8[gGameState.floor], 0, 0, 2);
#else
        DrawSprite(0x70, 0x10, gUnk_020355E0[gGameState.floor], gUnk_02035570[gGameState.floor],
            gUnk_020355A8[gGameState.floor], 0, 0, 2);
#endif
    }

    if (gUnk_020356D8 != 0) {
#ifdef VERSION_EU
        func_080664D8(0x78, 0x0C, gUnk_02035618, gUnk_0203551C, 0, gUnk_020356D8);
#else
        func_080664D8(0x80, 0x0C, gUnk_02035618, gUnk_0203551C, 0, gUnk_020356D8);
#endif
    }

    DrawSprite(0xB0, 0x1A, AnimUpdate(&gUnk_02035538), gUnk_02035518, gUnk_0203551C, 0, 0, 2);

    if (gUnk_020355E0[gUnk_020354E8] != 0) {
#ifdef VERSION_EU
        DrawSprite(0x66, 0x30, gUnk_020355E0[gUnk_020354E8], gUnk_02035570[gUnk_020354E8],
            gUnk_020355A8[gUnk_020354E8], 0, 0, 2);
#else
        DrawSprite(0x70, 0x30, gUnk_020355E0[gUnk_020354E8], gUnk_02035570[gUnk_020354E8],
            gUnk_020355A8[gUnk_020354E8], 0, 0, 2);
#endif
    }

    if (gUnk_020357A0 != 0) {
#ifdef VERSION_EU
        func_080664D8(0x78, 0x2C, gUnk_020356E0, gUnk_02035554, 0, gUnk_020357A0);
#else
        func_080664D8(0x80, 0x2C, gUnk_020356E0, gUnk_02035554, 0, gUnk_020357A0);
#endif
    }
}
