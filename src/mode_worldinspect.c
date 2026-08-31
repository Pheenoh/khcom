#include "macros.h"
#include "mode_worldinspect.h"

INCLUDE_ASM("mode_worldinspect/mode_worldinspect_0.s");

void mode_worldinspect_1(void) {
    func_0801CC80();
    gUnk_0203511A += 2;

    switch (gUnk_020354C0) {
    case 0:
        func_080058FC(&gUnk_020354C8[0], 0, gUnk_020354C2);
        func_080058FC(&gUnk_020354C8[1], 0x9800, gUnk_020354C2);
        gUnk_020354C2--;
        if (gUnk_020354C2 <= 0) {
            gUnk_020354C2 = 16;
            gUnk_020354C0 = 1;
        }
        break;
    case 1:
        func_080058FC(&gUnk_020354D0, 0, gUnk_020354C2);
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
        func_080058FC(&gUnk_020354D0, -0x8000, gUnk_020354C2);
        gUnk_020354C2--;
        if (gUnk_020354C2 <= 0) {
            gUnk_020354C2 = 16;
            gUnk_020354C0 = 4;
        }
        break;
    case 4:
        func_080058FC(&gUnk_020354C8[0], -0x800, gUnk_020354C2);
        func_080058FC(&gUnk_020354C8[1], 0xA800, gUnk_020354C2);
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

    func_08065AE0(gUnk_020351F8, 0x18);
    func_08065AE0(gUnk_020352C0, 0x3C);
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
    return func_08065B6C(gUnk_09EF9488[a].unk_14, gUnk_02035618);
}

u8 func_0810063C(s16 a) {
    if (a <= 0) {
        return 0;
    }
    return func_08065B6C(gUnk_09EF9488[a].unk_14, gUnk_020356E0);
}

void func_08100670(s16 a, u8* b, void* c) {
    RequestDma3Copy(b + a * 256, c, 0x100);
}

u16 func_0810068C(void) {
    s32 keys;

    keys = GetKeysPressed() & 0xF;
    keys |= GetKeysRepeat() & 0x3F0;
    return keys;
}

INCLUDE_ASM("mode_worldinspect/func_081006AC.s");
INCLUDE_ASM("mode_worldinspect/func_08100980.s");
