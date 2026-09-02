#include "macros.h"
#include "mode_ms.h"
#include "gba/keys.h"

void mode_ms_top_0(u32 a) {
    s32 i;

    func_08001F98();
    func_08006120(0, 16);
    func_08004DB0();
    gBldCnt = 0x142;
    gBldAlpha = 0x1010;
    SetupBg(0, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(2, 0, 30, 0);
    SetupBg(3, 3, 31, 14);
    SetBgPriority(0, 3);
    SetBgPriority(1, 2);
    SetBgPriority(2, 1);
    SetBgPriority(3, 0);

    if (a & 1) {
        func_08102774();
    }

    if (a & 2) {
        gUnk_020358A4 = 0;
        gUnk_02035890 = 7;
    } else {
        gUnk_020358A4 = 1;
        gUnk_02035890 = 0;
        gUnk_02035892 = 16;
        gUnk_02035898[0] = -0x800;
        gUnk_02035898[1] = 0xA800;
        gUnk_020358A0 = -0x8000;
        gUnk_020357C0 = 0;
    }
    gUnk_02035878 = 0;
    gUnk_0203587A = 0;
    gUnk_0203587C = 0;

    if (gUnk_020357C0 == 0) {
        gUnk_02035880 = 0;
        gUnk_02035884 = 0;
        gUnk_02035888 = 0;
        gUnk_0203588C = 0;
    } else {
        gUnk_02035880 = -0x6100;
        gUnk_02035884 = 0x2100;
        gUnk_02035888 = -0x1C00;
        gUnk_0203588C = 0xBC00;
    }
    gUnk_020358BC = -1;
    gUnk_020358BE = -1;
    gUnk_020358C0 = 0;
    LoadBgPalette(0, gUnk_09A3D79C, 0x60);
    LoadBgTiles(0, gUnk_09A10A3C, 0x19A0);
    func_08101588(func_08101518(), gUnk_09A123DC, (u8*)GetBgCharBase(0) + 0x20, 0x20, 5);
    LoadBgMap(0, gUnk_09A36EDC, 0x500);
    LoadBgMap(1, gUnk_09A373DC, 0x500);
    if (gUnk_020358A4 != 0) {
        LoadBgMap(2, gUnk_09A378DC, 0x500);
    } else {
        LoadBgMap(2, gUnk_09A37DDC, 0x500);
    }

    for (i = 0; i < 2; i++) {
        gUnk_02035820[i] = 0;
        gUnk_02035818[i] = 0;
    }
    gUnk_020357CC = LoadObjPalette(gUnk_09A3D7FC, 0x20);
    gUnk_020357C8 = LoadObjTiles(gUnk_099A2B62, 0x400);
    gUnk_020357D4 = LoadObjPalette(gUnk_09A3D85C, 0x20);
    gUnk_020357D0 = LoadObjTiles(gUnk_099A36F8, 0x500);
    AnimInit(&gUnk_020357D8, gUnk_09EF99D0, gUnk_09EF99A8);
    gUnk_020357F4 = LoadObjPalette(gUnk_08F683A4, 0x20);
    gUnk_020357F0 = LoadObjTiles(gUnk_088C56C6, 0x300);
    AnimInit(&gUnk_020357F8, gUnk_09EDEA6C, gUnk_09EDEA68);
    AnimStart(&gUnk_020357F8, 0, 1);
    gUnk_02035814 = LoadObjPalette(gUnk_08F69BA4, 0x20);
    gUnk_02035810 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    gUnk_0203585C = LoadObjPalette(gUnk_09617D58, 0x20);
    gUnk_02035858 = LoadObjTiles(gUnk_092028EC, 0xC00);
    AnimInit(&gUnk_02035860, gUnk_09EEEAC8, gUnk_09EEEA98);
    AnimStart(&gUnk_02035860, 0, 1);
    func_08101740(gUnk_020357C0);
    func_08101654();
    func_081015E8();
    TaskPoolInit(&gUnk_020358A8, 1);
    EnableBg(0);
    EnableBg(1);
    EnableBg(2);
    DisableBg(3);
}
INCLUDE_ASM("mode_ms/mode_ms_top_1.s");
void mode_ms_top_2(void) {
    s32 i;

    ReleaseObjPalette(gUnk_020357CC);
    ReleaseObjTiles(gUnk_020357C8);
    ReleaseObjPalette(gUnk_020357D4);
    ReleaseObjTiles(gUnk_020357D0);
    ReleaseObjPalette(gUnk_020357F4);
    ReleaseObjTiles(gUnk_020357F0);
    ReleaseObjPalette(gUnk_02035814);
    ReleaseObjTiles(gUnk_02035810);

    for (i = 0; i < 2; i++) {
        ReleaseObjPalette(gUnk_02035820[i]);
        ReleaseObjTiles(gUnk_02035818[i]);
    }
    ReleaseObjPalette(gUnk_0203585C);
    ReleaseObjTiles(gUnk_02035858);
    TaskPoolDestroy(&gUnk_020358A8);
}
void func_081025AC(void) {
    s32 i;

    for (i = 0; i < 32; i++) {
        gUnk_02035B68[i] = 0;
    }
    for (i = 0; i < 2; i++) {
        gUnk_02035BA8[i] = 0;
    }
}

void func_081025D4(void* a) {
    u16* p = a;
    s32 i;

    for (i = 0; i < 32; i++) {
        p[i] = gUnk_02035B68[i];
    }
    for (i = 0; i < 2; i++) {
        p[i + 32] = gUnk_02035BA8[i];
    }
}

void func_08102610(void* a) {
    u16* p = a;
    s32 i;

    for (i = 0; i < 32; i++) {
        gUnk_02035B68[i] = p[i];
    }
    for (i = 0; i < 2; i++) {
        gUnk_02035BA8[i] = p[i + 32];
    }
}

void func_0810264C(u16 a, u16 b, u16 c) {
    u16 v;

    v = a * 16 + b * 4 + c;
    if (v <= 0x1FF) {
        gUnk_02035B68[v >> 4] |= 1 << (v & 15);
    }
}

void func_08102688(u16 a, u16 b, u16 c) {
    u16 v;

    v = a * 16 + b * 4 + c;
    if (v <= 0x1FF) {
        gUnk_02035B68[v >> 4] &= ~(1 << (v & 15));
    }
}

u8 func_081026C4(u16 a, u16 b, u16 c) {
    u16 v;

    v = a * 16 + b * 4 + c;
    if (v <= 0x1FF) {
        return gUnk_02035B68[v >> 4] >> (v & 15) & 1;
    }
    return 0;
}

void func_08102704(u16 a) {
    if (a <= 31) {
        gUnk_02035BA8[a >> 4] |= 1 << (a & 15);
    }
}

void func_08102728(u16 a) {
    if (a <= 31) {
        gUnk_02035BA8[a >> 4] &= ~(1 << (a & 15));
    }
}

s32 func_0810274C(u16 a) {
    if (a <= 31) {
        return gUnk_02035BA8[a >> 4] >> (a & 15) & 1;
    }
    return 0;
}

void func_08102774(void) {
    s16 i;
    s16 j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            func_08102688(gUnk_0203C590[6], i, j);
        }
    }
    func_08102728(gUnk_0203C590[6]);
}
INCLUDE_ASM("mode_ms/func_081027B4.s");
void func_081028F8(u16 w, s16 h, u16* src, s16 sx, s16 sy, u16* dst, s16 dx, s16 dy) {
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
void func_08102984(s16 a) {
    vu32* dma;
    vu16 zero;
    s32 j;

    zero = 0;
    dma = (vu32*)0x040000D4;
    dma[0] = (u32)&zero;
    dma[1] = (u32)gUnk_02035C00;
    dma[2] = 0x81000280;
    dma[2];

    for (j = 0; j < 4; j++) {
        if (gUnk_02035B18[a][j][0] >= 0) {
            func_08101588(gUnk_09993760[gUnk_02035B08[a]][gUnk_02035B18[a][j][1]], gUnk_09A18EBC,
                (u8*)GetBgCharBase(2) + (j * 0xC0 + 0xC0), 0x40, 3);
            func_081028F8(12, 8, gUnk_099931E4[j].unk_1C[gUnk_02035B08[a]].unk_00,
                gUnk_099931E4[j].unk_1C[gUnk_02035B08[a]].unk_04,
                gUnk_099931E4[j].unk_1C[gUnk_02035B08[a]].unk_06, gUnk_02035C00,
                gUnk_099931E4[j].unk_12, gUnk_099931E4[j].unk_14);
        }
    }
    LoadBgMap(2, gUnk_02035C00, 0x500);
}
s32 func_08102A94(void) {
    s32 k;

    k = GetKeysPressed() & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON);
    return k | (GetKeysRepeat() & (DPAD_ANY | R_BUTTON | L_BUTTON));
}
INCLUDE_ASM("mode_ms/func_08102AB4.s");
void func_08102DC8(void) {
    s16 i;

    for (i = 0; i < 5; i++) {
        func_080062F4(gUnk_020358C8[i].unk_00->unk_06 + 0x10, 0);
        ReleaseObjPalette(gUnk_020358C8[i].unk_00);
        ReleaseObjTiles(gUnk_020358C8[i].unk_04);
        func_080062F4(gUnk_020358C8[i].unk_0C->unk_06 + 0x10, 0);
        ReleaseObjPalette(gUnk_020358C8[i].unk_0C);
        ReleaseObjTiles(gUnk_020358C8[i].unk_10);
    }
    func_080062F4(gUnk_02035AE0->unk_06 + 0x10, 0);
    ReleaseObjPalette(gUnk_02035AE0);
    ReleaseObjTiles(gUnk_02035ADC);
    func_080062F4(gUnk_02035A40->unk_06 + 0x10, 0);
    ReleaseObjPalette(gUnk_02035A40);
    func_08065AE0(gUnk_02035A44, 0x24);
    EwramFree(gUnk_02035A44);
    func_08065AE0(gUnk_02035A4C, 0x5A);
    EwramFree(gUnk_02035A4C);
    func_080062F4(gUnk_02035A30->unk_06 + 0x10, 0);
    ReleaseObjPalette(gUnk_02035A30);
    ReleaseObjTiles(gUnk_02035A34);
    func_080062F4(gUnk_02035A38->unk_06 + 0x10, 0);
    ReleaseObjPalette(gUnk_02035A38);
    ReleaseObjTiles(gUnk_02035A3C);
    ReleaseObjTiles(gUnk_02035A54);

    for (i = 0; i < 5; i++) {
        TaskPoolDestroy(&gUnk_02035A70[i]);
    }
}
INCLUDE_ASM("mode_ms/func_08102F30.s");
INCLUDE_ASM("mode_ms/func_0810329C.s");
void func_08103CD8(s16 a) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (gUnk_02035B08[i] >= 0) {
            func_0800448C(gUnk_09A3ABDC, GetBgScreenBase(0), gUnk_02035B08[i] * 6, i == a ? 0 : 3, 0, i * 3 + 3, 6, 3);
        }
    }
}
void func_08103D54(s16 a) {
    LoadBgMap(1, gUnk_099931E4[a].unk_0C, gUnk_099931E4[a].unk_10);
}
void func_08103D7C(void) {
    u16 keys;

    keys = func_08102A94();
    if ((keys & A_BUTTON) == 0) {
        if (keys & B_BUTTON) {
            m4aSongNumStart(0x68);
            func_08006184(0, 16);
            gUnk_02035C0C = 1;
            gUnk_02035B02 = 5;
        } else if (keys & START_BUTTON) {
            m4aSongNumStart(0x68);
            func_08006184(0, 16);
            gUnk_02035C0C = 0;
            gUnk_02035B02 = 5;
        }
    }
}
void func_08103DE8(void) {
    u16 keys;
    s16 old;
    s16 i;

    old = gUnk_02035B04;
    keys = func_08102A94();
    if ((keys & A_BUTTON) == 0) {
        if (keys & B_BUTTON) {
            m4aSongNumStart(0x68);
            func_08006184(0, 16);
            gUnk_02035C0C = 1;
            gUnk_02035B02 = 5;
        } else if (keys & START_BUTTON) {
            m4aSongNumStart(0x68);
            func_08006184(0, 16);
            gUnk_02035C0C = 0;
            gUnk_02035B02 = 5;
        } else if (keys & DPAD_UP) {
            gUnk_02035B04--;
            if (gUnk_02035B04 < 0) {
                i = 3;
                if (gUnk_02035B08[i] < 0) {
                    do {
                        i--;
                        if (i <= 0) {
                            break;
                        }
                    } while (gUnk_02035B08[i] < 0);
                }
                gUnk_02035B04 = i;
            }
        } else if (keys & DPAD_DOWN) {
            gUnk_02035B04++;
            if (gUnk_02035B04 > 3) {
                gUnk_02035B04 = 0;
            } else if (gUnk_02035B08[gUnk_02035B04] < 0) {
                gUnk_02035B04 = 0;
            }
        } else if (keys & DPAD_RIGHT) {
            gUnk_02035B02 = 3;
            gUnk_02035B10 = 0;
            func_08103D54(0);
            m4aSongNumStart(0x65);
        }
    }
    if (gUnk_02035B04 == -1) {
        gUnk_02035B04 = old;
    }
    if (gUnk_02035B04 != old) {
        func_08103CD8(gUnk_02035B04);
        func_08102984(gUnk_02035B04);
        m4aSongNumStart(0x65);
    }
}
u16 func_08103F3C(void) {
    s16 i;
    u16 r;
    u16 acc;

    r = GetRandom() % 100;
    i = 0;
    acc = gUnk_09993334[0];
    if (r >= acc) {
        do {
            i++;
            if (i > 9) {
                break;
            }
            acc += gUnk_09993334[i];
        } while (r >= acc);
    }
    return i % 10;
}
INCLUDE_ASM("mode_ms/func_08103F94.s");
void func_081041B4(void) {
    u16 keys;
    s16 old;

    old = gUnk_02035B10;
    keys = func_08102A94();
    if (keys & A_BUTTON) {
        if (gUnk_02035B18[gUnk_02035B04][gUnk_02035B10][0] >= 0 &&
            func_08101538(gUnk_09993760[gUnk_02035B08[gUnk_02035B04]][gUnk_02035B18[gUnk_02035B04][gUnk_02035B10][1]]) != 0) {
            func_08103F94(gUnk_02035B08[gUnk_02035B04], gUnk_02035B18[gUnk_02035B04][gUnk_02035B10][1]);
            func_08102AB4(gUnk_02035B10 % 2 * 96 + 72, gUnk_02035B10 / 2 * 64 + 48);
            func_080062F4(13, 1);
            func_08006238(0, 16, 8);
            m4aSongNumStart(0x66);
            gUnk_02035B02 = 4;
        } else {
            m4aSongNumStart(0x69);
        }
    } else if (keys & B_BUTTON) {
        m4aSongNumStart(0x68);
        func_08006184(0, 16);
        gUnk_02035C0C = 1;
        gUnk_02035B02 = 5;
    } else if (keys & START_BUTTON) {
        m4aSongNumStart(0x68);
        func_08006184(0, 16);
        gUnk_02035C0C = 0;
        gUnk_02035B02 = 5;
    } else if (keys & DPAD_UP) {
        gUnk_02035B10 = gUnk_099931E4[gUnk_02035B10].unk_00;
    } else if (keys & DPAD_DOWN) {
        gUnk_02035B10 = gUnk_099931E4[gUnk_02035B10].unk_02;
    } else if (keys & DPAD_LEFT) {
        gUnk_02035B10 = gUnk_099931E4[gUnk_02035B10].unk_04;
    } else if (keys & DPAD_RIGHT) {
        gUnk_02035B10 = gUnk_099931E4[gUnk_02035B10].unk_06;
    }

    if (gUnk_02035B10 == -1) {
        gUnk_02035B10 = old;
    } else if (gUnk_02035B10 == 5) {
        gUnk_02035B10 = old;
        gUnk_02035B02 = 2;
        DisableBg(1);
        m4aSongNumStart(0x65);
    } else if (gUnk_02035B18[gUnk_02035B04][gUnk_02035B10][0] < 0) {
        gUnk_02035B10 = old;
    }

    if (gUnk_02035B10 != old) {
        func_08103D54(gUnk_02035B10);
        m4aSongNumStart(0x65);
    }
}
INCLUDE_ASM("mode_ms/func_08104404.s");
void mode_ms_shop_0(void) {
    s16 i;
    s32 size;
    u16** p;

    p = &gUnk_02035C00;
    size = 0x500;
    *p = EwramAlloc(size);
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
    gUnk_02035B02 = 0;
    gUnk_02035B04 = 0;
    gUnk_02035B10 = 0;
    gUnk_02035B00 = func_081027B4(gUnk_02039BB0.unk_00E);
    LoadBgPalette(0, gUnk_09A3D87C, 0x1A0);
    LoadBgTiles(0, gUnk_09A1251C, 0x6860);
    func_08101588(func_08101518(), gUnk_09A18D7C, (u8*)GetBgCharBase(0) + 0x20, 0x20, 5);
    LoadBgMap(0, gUnk_09A382DC, size);
    func_08103CD8(gUnk_02035B04);
    if (gUnk_02035B00 != 0) {
        func_08103D54(gUnk_02035B10);
    }
    func_08102984(gUnk_02035B04);
    LoadBgMap(3, gUnk_09A3AD5C, size);
    gUnk_02035BB0 = LoadObjPalette(gUnk_09A3DA7C, 0x20);
    gUnk_02035BAC = LoadObjTiles(gUnk_099A3CE4, 0x1C0);
    AnimInit(&gUnk_02035BB8, gUnk_09EF99F8, gUnk_09EF99D8);
    AnimStart(&gUnk_02035BB8, 0, 1);

    for (i = 0; i < 4; i++) {
        gUnk_02035BE0[i] = LoadObjPalette(gUnk_099932D4[i].unk_00, gUnk_099932D4[i].unk_04);
        gUnk_02035BD0[i] = LoadObjTiles(gUnk_099932D4[i].unk_08, gUnk_099932D4[i].unk_0C);
        gUnk_02035BF0[i] = gUnk_099932D4[i].unk_10;
    }
    EnableBg(0);
    DisableBg(1);
    EnableBg(2);
    DisableBg(3);
}
INCLUDE_ASM("mode_ms/mode_ms_shop_1.s");
void mode_ms_shop_2(void) {
    s32 i;

    ReleaseObjPalette(gUnk_02035BB0);
    ReleaseObjTiles(gUnk_02035BAC);

    for (i = 0; i < 4; i++) {
        ReleaseObjPalette(gUnk_02035BE0[i]);
        ReleaseObjTiles(gUnk_02035BD0[i]);
    }
    EwramFree(gUnk_02035C00);
}
