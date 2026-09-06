#include "macros.h"
#include "mode_worldinspect.h"
#include "gba/keys.h"
#ifdef VERSION_EU
extern void* eu_0805E924(void* strings);
#endif

s16 gUnk_02035118;
u8 gUnk_0203511A;
void* gUnk_0203511C;
void* gUnk_02035120;
void* gUnk_02035124;
void* gUnk_02035128;
s32 gUnk_0203512C;
u8 gUnk_02035130[0x18];
void* gUnk_02035148;
void* gUnk_0203514C;
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

INCLUDE_ASM("mode_worldinspect/mode_worldinspect_0.s");

#ifndef VERSION_EU
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
            LoadBgMap(0, gUnk_09A329DC, 0x500);
            ReleaseObjPalette(gUnk_0203511C);
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
#else
INCLUDE_ASM("mode_worldinspect/mode_worldinspect_1.s");
#endif

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

INCLUDE_ASM("mode_worldinspect/func_081006AC.s");
INCLUDE_ASM("mode_worldinspect/func_08100980.s");
