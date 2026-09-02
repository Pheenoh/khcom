#include "macros.h"
#include "mode_worldwarp.h"

s16 gUnk_020354E8;
s16 gUnk_020354EA;
u8 gUnk_020354EC[4];
s16 gUnk_020354F0[13];
s16 gUnk_0203550A;
void* gUnk_0203550C;
void* gUnk_02035510;
void* gUnk_02035514;
void* gUnk_02035518;
void* gUnk_0203551C;
AnimState gUnk_02035520;
AnimState gUnk_02035538;
void* gUnk_02035550;
void* gUnk_02035554;
AnimState gUnk_02035558;
void* gUnk_02035570[14];
void* gUnk_020355A8[14];
void* gUnk_020355E0[14];
u8 gUnk_02035618[192];
u8 gUnk_020356D8;
u8 gUnk_020356D9[7];
u8 gUnk_020356E0[192];
u8 gUnk_020357A0;
s16 gUnk_020357A2;
s16 gUnk_020357A4;
s32 gUnk_020357A8[2];
s32 gUnk_020357B0;
s32 gUnk_020357B4;
s32 gUnk_020357B8;

#ifdef NON_MATCHING
void mode_worldwarp_0(void) {
    s32 i;
    vu32* dma;

    gUnk_020354EA = func_080DF750() + 1;
    gUnk_0203550C = EwramAlloc(0x500);
    func_08001F98();
    func_08006120(0, 16);
    func_08004DB0();
    SetupBg(0, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(2, 0, 30, 0);
    SetupBg(3, 0, 31, 0);
    SetBgPriority(0, 3);
    SetBgPriority(1, 2);
    SetBgPriority(2, 1);
    SetBgPriority(3, 0);
    gUnk_020354E8 = gUnk_02039BB0.unk_00E;
    gUnk_0203550A = -1;

    for (i = 0; i <= 12; i++) {
        if (i < gUnk_020354EA) {
            gUnk_020354F0[i] = gUnk_02039BB0.unk_186[i][0];
        } else {
            gUnk_020354F0[i] |= 0xFFFF;
        }
    }

    gUnk_020357A2 = 0;
    gUnk_020357A4 = 16;
    gUnk_020357A8[0] = -0x800;
    gUnk_020357A8[1] = 0xA800;
    gUnk_020357B0 = -0x8000;
    gUnk_020357B4 = (gUnk_09EF9384[gUnk_020354E8].unk_08 << 11) + 0x2000;
    gUnk_020357B8 = (gUnk_09EF9384[gUnk_020354E8].unk_0A << 11) - 0x600;
    LoadBgPalette(0, gUnk_09A3D37C, 0x200);

    for (i = 0; i <= 12; i++) {
        if (gUnk_020354F0[i] > 0) {
            gUnk_020355A8[i] = LoadObjPalette(gUnk_09EF9488[gUnk_020354F0[i]].unk_00, gUnk_09EF9488[gUnk_020354F0[i]].unk_04);
            gUnk_02035570[i] = LoadObjTiles(gUnk_09EF9488[gUnk_020354F0[i]].unk_08, gUnk_09EF9488[gUnk_020354F0[i]].unk_0C);
            gUnk_020355E0[i] = gUnk_09EF9488[gUnk_020354F0[i]].unk_10;
        } else {
            gUnk_020355A8[i] = 0;
            gUnk_02035570[i] = 0;
            gUnk_020355E0[i] = 0;
        }
    }

    LoadBgTiles(0, gUnk_09A06A7C, 0x6BC0);
    LoadBgMap(0, gUnk_09A35A1C, 0x500);
    dma = (vu32*)0x040000D4;
    dma[0] = (u32)gUnk_09A3641C;
    dma[1] = (u32)gUnk_0203550C;
    dma[2] = 0x80000280;
    dma[2];

    for (i = 0; i <= 12; i++) {
        if (gUnk_020354F0[i] >= 0) {
            func_0810057C(7, 4, gUnk_09A3691C, 0, 0, gUnk_0203550C, gUnk_09EF9384[i].unk_08, gUnk_09EF9384[i].unk_0A);
        }
    }

    for (i = 0; i < gUnk_020354EA - 1; i++) {
        if (gUnk_020354F0[i] >= 0 && gUnk_020354F0[i + 1] >= 0) {
            func_0810057C(gUnk_099930E8[gUnk_09EF9384[i].unk_0C].unk_00, gUnk_099930E8[gUnk_09EF9384[i].unk_0C].unk_02,
                gUnk_09A3691C, gUnk_099930E8[gUnk_09EF9384[i].unk_0C].unk_04,
                gUnk_099930E8[gUnk_09EF9384[i].unk_0C].unk_06, gUnk_0203550C,
                gUnk_09EF9384[i].unk_0E, gUnk_09EF9384[i].unk_10);
        }
    }

    for (i = 0; i < gUnk_020354EA; i++) {
        if (gUnk_020354F0[i] >= 0) {
            if (gUnk_02039BB0.unk_008 & 8) {
                if (i <= 2) {
                    func_0810057C(4, 1, gUnk_09A3691C, i * 4, 21, gUnk_0203550C,
                        gUnk_09EF9384[i].unk_08 + 3, gUnk_09EF9384[i].unk_0A + 2);
                } else {
                    func_0810057C(3, 1, gUnk_09A3691C, (i - 3) * 3, 22, gUnk_0203550C,
                        gUnk_09EF9384[i].unk_08 + 3, gUnk_09EF9384[i].unk_0A + 2);
                }
            } else if (i <= 8) {
                func_0810057C(3, 1, gUnk_09A3691C, i * 3, 9, gUnk_0203550C,
                    gUnk_09EF9384[i].unk_08 + 3, gUnk_09EF9384[i].unk_0A + 2);
            } else {
                func_0810057C(4, 1, gUnk_09A3691C, (i - 9) * 4, 10, gUnk_0203550C,
                    gUnk_09EF9384[i].unk_08 + 3, gUnk_09EF9384[i].unk_0A + 2);
            }
        }
    }

    for (i = 0; i < gUnk_020354EA; i++) {
        if (gUnk_020354E8 == i) {
            func_081004EC(3, 7, 4, gUnk_0203550C, gUnk_09EF9384[i].unk_08, gUnk_09EF9384[i].unk_0A);
        } else {
            func_081004EC(2, 7, 4, gUnk_0203550C, gUnk_09EF9384[i].unk_08, gUnk_09EF9384[i].unk_0A);
        }
    }

    LoadBgMap(1, gUnk_0203550C, 0x500);

    if (gUnk_02039BB0.unk_008 & 8) {
        func_08100670(gUnk_02039BB0.unk_00E, gUnk_09A0FD3C, (u8*)GetBgCharBase(0) + 0x120);
        func_08100670(gUnk_020354E8, gUnk_09A0F03C, (u8*)GetBgCharBase(0) + 0x20);
    } else {
        func_08100670(gUnk_02039BB0.unk_00E, gUnk_09A0E33C, (u8*)GetBgCharBase(0) + 0x120);
        func_08100670(gUnk_020354E8, gUnk_09A0D63C, (u8*)GetBgCharBase(0) + 0x20);
    }
    gUnk_02035514 = LoadObjPalette(gUnk_09A3D57C, 32);
    gUnk_02035510 = LoadObjTiles(gUnk_0999F488, 0x500);
    gUnk_0203551C = LoadObjPalette(gUnk_09A3D59C, 32);
    gUnk_02035518 = LoadObjTiles(gUnk_0999FA20, 0x680);
    AnimInit(&gUnk_02035520, gUnk_09EF9898, gUnk_09EF9870);
    AnimStart(&gUnk_02035520, 0, 1);
    AnimInit(&gUnk_02035538, gUnk_09EF9898, gUnk_09EF9870);
    AnimStart(&gUnk_02035538, 1, 1);
    gUnk_02035554 = LoadObjPalette(gUnk_09A3D5BC, 32);
    gUnk_02035550 = LoadObjTiles(gUnk_099A012C, 192);
    AnimInit(&gUnk_02035558, gUnk_09EF98B0, gUnk_09EF98A0);
    AnimStart(&gUnk_02035558, 0, 1);
    func_08065ACC(gUnk_02035618, 24);
    func_08065ACC(gUnk_020356E0, 24);
    gUnk_020356D8 = func_08100608(gUnk_020354F0[gUnk_02039BB0.unk_00E]);
    gUnk_020357A0 = func_0810063C(gUnk_020354F0[gUnk_020354E8]);
    EnableBg(0);
    EnableBg(1);
    DisableBg(2);
    DisableBg(3);
}
#else
INCLUDE_ASM("mode_worldwarp/mode_worldwarp_0.s");
#endif

void mode_worldwarp_1(void) {
    UpdatePlayTime();

    switch (gUnk_020357A2) {
    case 0:
        ApproachValue(&gUnk_020357A8[0], 0, gUnk_020357A4);
        ApproachValue(&gUnk_020357A8[1], 0x9800, gUnk_020357A4);

        if (--gUnk_020357A4 <= 0) {
            gUnk_020357A4 = 16;
            gUnk_020357A2 = 1;
        }
        break;
    case 1:
        ApproachValue(&gUnk_020357B0, 0, gUnk_020357A4);

        if (--gUnk_020357A4 <= 0) {
            LoadBgMap(0, gUnk_09A35F1C, 0x500);
            gUnk_020357A2 = 2;
        }
        break;
    case 2:
        func_081006AC();
        break;
    case 3:
        ApproachValue(&gUnk_020357B0, -0x8000, gUnk_020357A4);

        if (--gUnk_020357A4 <= 0) {
            gUnk_020357A4 = 16;
            gUnk_020357A2 = 4;
        }
        break;
    case 4:
        ApproachValue(&gUnk_020357A8[0], -0x800, gUnk_020357A4);
        ApproachValue(&gUnk_020357A8[1], 0xA800, gUnk_020357A4);

        if (--gUnk_020357A4 <= 0) {
            gUnk_020357A4 = 16;
            func_08006184(0, 16);
            gUnk_020357A2 = 5;
        }
        break;
    case 5:
        if (!func_08006314()) {
            if (gUnk_0203550A >= 0) {
                func_080DF9E0(gUnk_0203550A);
            } else {
                func_080E04EC();
            }
        }
        break;
    }
    func_08100980();
}

#ifndef VERSION_EU
void mode_worldwarp_2(void) {
    s32 i;

    ReleaseObjPalette(gUnk_02035514);
    ReleaseObjTiles(gUnk_02035510);
    ReleaseObjPalette(gUnk_0203551C);
    ReleaseObjTiles(gUnk_02035518);
    ReleaseObjPalette(gUnk_02035554);
    ReleaseObjTiles(gUnk_02035550);

    for (i = 0; i <= 12; i++) {
        if (gUnk_020355A8[i] != 0) {
            ReleaseObjPalette(gUnk_020355A8[i]);
        }

        if (gUnk_02035570[i] != 0) {
            ReleaseObjTiles(gUnk_02035570[i]);
        }
    }
    func_08065AE0(gUnk_02035618, 24);
    func_08065AE0(gUnk_020356E0, 24);
    EwramFree(gUnk_0203550C);
}
#else
INCLUDE_ASM("mode_worldwarp/mode_worldwarp_2.s");
#endif

u32 func_08101518(void) {
    return gUnk_02039BB0.unk_174;
}

void func_08101528(u32 a) {
    gUnk_02039BB0.unk_174 = a;
}

u8 func_08101538(u32 a) {
    u8 ok = 0;

    if (func_08101518() >= a) {
        func_08101528(func_08101518() - a);
        ok = 1;
    }
    return ok;
}

u8 func_0810155C(u32 a) {
    a += func_08101518();
    if (a > 99999) {
        func_08101528(99999);
        return 0;
    }
    func_08101528(a);
    return 1;
}

void func_08101588(u32 value, u8* glyphs, u8* dst, u16 stride, u16 count) {
    s32 i;
    u32 digit;

    for (i = 0; i < count; i++) {
        digit = value % 10;
        value /= 10;
        RequestDma3Copy(&glyphs[digit * stride], &dst[(count - 1 - i) * stride], stride);
    }
}

void func_081015E8(void) {
    s32 flag;
    s16 x;
    s32 v;
    s32 base;

    x = gUnk_09993118[0].unk_16 + ((gUnk_0203588C - gUnk_02035884) >> 8);
    flag = 0;
    v = x;
    base = (-gUnk_02035880) >> 8;
    if (v <= base + 0x1C || v >= base + 0x1C + 0x62) {
        flag = 1;
    }
    ReleaseObjPalette(gUnk_0203585C);
    gUnk_0203585C = LoadObjPalette(flag == 0 ? gUnk_09617D58 : gUnk_09A3D77C, 0x20);
}

void func_08101654(void) {
    s16 i;
    s32 flag;
    s16 x;
    s32 v;
    s32 base;

    for (i = 0; i <= 1; i++) {
        x = gUnk_09993118[0].unk_1C[i].unk_00 - (gUnk_02035884 >> 8);
        flag = 0;
        v = x;
        base = (-gUnk_02035880) >> 8;
        if (v <= base + 0x18 || v >= base + 0x18 + 0x6A) {
            flag = 1;
        }

        if (gUnk_02035820[i] != 0) {
            ReleaseObjPalette(gUnk_02035820[i]);
        }

        if (gUnk_02035818[i] != 0) {
            ReleaseObjTiles(gUnk_02035818[i]);
        }
        gUnk_02035820[i] = LoadObjPalette(gUnk_09993118[flag].unk_1C[i].unk_04, gUnk_09993118[flag].unk_1C[i].unk_08);
        gUnk_02035818[i] = LoadObjTiles(gUnk_09993118[flag].unk_1C[i].unk_0C, gUnk_09993118[flag].unk_1C[i].unk_10);
        AnimInit(&gUnk_02035828[i], gUnk_09993118[flag].unk_1C[i].unk_14, gUnk_09993118[flag].unk_1C[i].unk_18);
        AnimStart(&gUnk_02035828[i], gUnk_09993118[flag].unk_1C[i].unk_1C, 1);
    }
}

void func_08101740(s16 a) {
    AnimStart(&gUnk_020357D8, gUnk_09993118[a].unk_0E, 1);
}

void func_08101768(void) {
    if (gUnk_020358BC < 0) {
        if (gUnk_020358C2 <= 2) {
            gUnk_020358BC = gUnk_099931D0[gUnk_020358C2];
            gUnk_020358C2++;
        }
    }
}

#ifndef VERSION_EU
void func_081017A0(void) {
    s16 prev;
    u16 keys;

    prev = gUnk_020357C0;
    keys = GetKeysPressed();
    if (keys & 1) {
        if (gUnk_020357C0 == 1) {
            AnimStart(&gUnk_02035828[gUnk_020357C0], 2, 1);
        }
        gUnk_020357C4 = gUnk_09993118[gUnk_020357C0].unk_00;
        m4aSongNumStart(0x66);
        func_08006184(0, 16);
        func_080063A8();
        gUnk_02035890 = 11;
    } else if (keys & 2) {
        gUnk_020357C4 = 0;
        m4aSongNumStart(0x68);
        gUnk_020358A4 = 1;
        LoadBgMap(2, gUnk_09A378DC, 0x500);
        gUnk_02035892 = 16;
        gUnk_02035890 = 9;
    } else if (keys & 8) {
        gUnk_020357C4 = 0;
        m4aSongNumStart(0x68);
        gUnk_020358A4 = 1;
        LoadBgMap(2, gUnk_09A378DC, 0x500);
        func_08006184(0, 16);
        func_080063A8();
        gUnk_02035890 = 11;
    } else if ((keys & 0x20) && gUnk_02035878 != 1 && gUnk_020357C0 != 0) {
        gUnk_020357C0 = 0;
        gUnk_02035878 = 1;
        gUnk_0203587A = 30 - gUnk_0203587A;
        gUnk_0203587C = 1;
        AnimStart(&gUnk_02035860, 1, 1);
    } else if ((keys & 0x10) && gUnk_02035878 != 2 && gUnk_020357C0 != 1) {
        gUnk_020357C0 = 1;
        gUnk_02035878 = 2;
        gUnk_0203587A = 30 - gUnk_0203587A;
        gUnk_0203587C = 2;
        AnimStart(&gUnk_02035860, 1, 1);
    }

    if (gUnk_020357C0 != prev) {
        if (func_080A42C8()) {
            func_080A42E0();
        }
        gUnk_020358BE = gUnk_020357C0 == 0 ? 0x40 : 0x41;
        func_08101740(gUnk_020357C0);
        m4aSongNumStart(0x65);
    }
}
#else
INCLUDE_ASM("mode_worldwarp/func_081017A0.s");
#endif

#ifndef VERSION_EU
void func_08101970(void) {
    s32 i;
    u16 flags;

    if (gUnk_020358A4 != 0) {
        DrawSprite(gUnk_020358A0 >> 8, 0, gUnk_099A2AD4, gUnk_020357C8, gUnk_020357CC, 0, 0x800, 0x7D0);
        DrawSprite(0x80, gUnk_02035898[0] >> 8, gUnk_099A2AF0, gUnk_020357C8, gUnk_020357CC, 0, 0x800, 0x7D1);
        DrawSprite(0x80, gUnk_02035898[1] >> 8, gUnk_099A2B24, gUnk_020357C8, gUnk_020357CC, 0, 0x800, 0x7D1);
    }

    flags = 0x800;

    switch (gUnk_0203587C) {
    case 0:
        if (gUnk_020357C0 == 0) {
            flags |= 1;
        }
        break;
    case 1:
        break;
    case 2:
        flags |= 1;
        break;
    }
    DrawSprite(gUnk_09993118[0].unk_16 + ((gUnk_0203588C - gUnk_02035884) >> 8), gUnk_09993118[0].unk_18,
        AnimUpdate(&gUnk_02035860), gUnk_02035858, gUnk_0203585C, 0, flags, 0x834);
    DrawSprite((gUnk_02035888 >> 8) + gUnk_09993118[0].unk_0A, gUnk_09993118[0].unk_0C,
        AnimUpdate(&gUnk_020357D8), gUnk_020357D0, gUnk_020357D4, 0, 0x800, 0x7D0);

    DrawSprite(gUnk_09993118[0].unk_10 + (gUnk_02035888 >> 8), gUnk_09993118[0].unk_12,
        AnimUpdate(&gUnk_020357F8), gUnk_020357F0, gUnk_020357F4, 0,
        0x800 | gUnk_09993118[gUnk_020357C0].unk_14, 0x7D0);
    DrawSprite(gUnk_09993118[0].unk_10 + (gUnk_02035888 >> 8), gUnk_09993118[0].unk_12,
        gUnk_08B22BA8, gUnk_02035810, gUnk_02035814, 0,
        0x800 | gUnk_09993118[gUnk_020357C0].unk_14, 0x7D1);

    for (i = 0; i <= 1; i++) {
        DrawSprite(gUnk_09993118[0].unk_1C[i].unk_00 - (gUnk_02035884 >> 8), gUnk_09993118[0].unk_1C[i].unk_02,
            AnimUpdate(&gUnk_02035828[i]), gUnk_02035818[i], gUnk_02035820[i], 0, 0x800, 0x7D0);
    }

    if (gUnk_02035890 == 6) {
        func_08102F30();
    }
    TaskPoolDraw(&gUnk_020358A8);
    SetBgScroll(0, gUnk_02035884 >> 8, 0);
    SetBgScroll(1, gUnk_02035880 >> 8, 0);
}
#else
INCLUDE_ASM("mode_worldwarp/func_08101970.s");
#endif
