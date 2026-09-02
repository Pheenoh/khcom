#include "macros.h"
#include "mode_ms.h"
#include "gba/keys.h"

INCLUDE_ASM("mode_ms/mode_ms_top_0.s");
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
INCLUDE_ASM("mode_ms/func_081041B4.s");
INCLUDE_ASM("mode_ms/func_08104404.s");
INCLUDE_ASM("mode_ms/mode_ms_shop_0.s");
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
