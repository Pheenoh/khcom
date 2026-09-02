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
void mode_ms_top_1(void) {
    UpdatePlayTime();
    switch (gUnk_02035890) {
        case 0:
            ApproachValue(&gUnk_02035898[0], 0, gUnk_02035892);
            ApproachValue(&gUnk_02035898[1], 0x9800, gUnk_02035892);
            if (--gUnk_02035892 <= 0) {
                gUnk_02035892 = 16;
                gUnk_02035890 = 1;
            }
            break;
        case 1:
            ApproachValue(&gUnk_020358A0, 0, gUnk_02035892);
            if (--gUnk_02035892 <= 0) {
                gUnk_020358A4 = 0;
                LoadBgMap(2, gUnk_09A37DDC, 0x500);
                gUnk_02035890 = 2;
            }
            break;
        case 2:
            if ((gUnk_02039BB0.unk_17A & 0x80) == 0) {
                gUnk_020358C2 = 0;
                gUnk_02035890 = 3;
            } else {
                gUnk_02035890 = 4;
            }
            break;
        case 3:
            func_08101768();
            if (gUnk_020358C2 > 2 && gUnk_020358BC < 0 && func_080A42C8() == 0) {
                func_0800FDD0(27);
                gUnk_02039BB0.unk_17A |= 0x80;
                gUnk_02035890 = 4;
            }
            break;
        case 4:
            if (func_0810274C(gUnk_0203C590[6]) == 0) {
                gUnk_020358BC = 0x42;
                gUnk_02035890 = 5;
            } else {
                gUnk_02035890 = 7;
            }
            break;
        case 5:
            if (func_080A42C8() == 0) {
                if (gUnk_02039BB0.unk_00E <= 5) {
                    func_08103F94(0, 0);
                } else if (gUnk_02039BB0.unk_00E <= 9) {
                    func_08103F94(0, 1);
                } else {
                    func_08103F94(0, 2);
                }
                func_08102AB4(120, 80);
                func_080062F4(13, 1);
                func_08006238(0, 16, 8);
                gUnk_02035890 = 6;
            }
            break;
        case 6:
            if (func_0810329C(1) == 0) {
                func_08102DC8();
                func_08102704(gUnk_0203C590[6]);
                SetupBg(3, 3, 31, 14);
                DisableBg(3);
                func_08101588(func_08101518(), gUnk_09A123DC, (u8*)GetBgCharBase(0) + 0x20, 0x20, 5);
                func_080061E8(0, 8);
                gUnk_02035890 = 7;
            }
            break;
        case 7:
            gUnk_020358BE = gUnk_020357C0 == 0 ? 0x40 : 0x41;
            gUnk_02035890 = 8;
            break;
        case 8:
            func_081017A0();
            break;
        case 9:
            ApproachValue(&gUnk_020358A0, -0x8000, gUnk_02035892);
            if (--gUnk_02035892 <= 0) {
                gUnk_02035892 = 16;
                gUnk_02035890 = 10;
            }
            break;
        case 10:
            ApproachValue(&gUnk_02035898[0], -0x800, gUnk_02035892);
            ApproachValue(&gUnk_02035898[1], 0xA800, gUnk_02035892);
            if (--gUnk_02035892 <= 0) {
                func_08006184(0, 16);
                func_080063A8();
                gUnk_02035890 = 11;
            }
            break;
        case 11:
            if (func_08006314() == 0) {
                if (gUnk_020357C4 != 0) {
                    func_080010CC(gUnk_020357C4, 0);
                } else {
                    func_080E04EC();
                }
            }
            break;
    }

    switch (gUnk_02035878) {
        case 0:
            break;
        case 1:
            func_08101654();
            ApproachValue(&gUnk_02035880, 0, gUnk_0203587A);
            ApproachValue(&gUnk_02035884, 0, gUnk_0203587A);
            ApproachValue(&gUnk_02035888, 0, gUnk_0203587A);
            if (--gUnk_0203587A <= 0) {
                gUnk_02035878 = 0;
            }
            break;
        case 2:
            func_08101654();
            ApproachValue(&gUnk_02035880, -0x6100, gUnk_0203587A);
            ApproachValue(&gUnk_02035884, 0x2100, gUnk_0203587A);
            ApproachValue(&gUnk_02035888, -0x1C00, gUnk_0203587A);
            if (--gUnk_0203587A <= 0) {
                gUnk_02035878 = 0;
            }
            break;
    }

    switch (gUnk_0203587C) {
        case 0:
            break;
        case 1:
            func_081015E8();
            gUnk_0203588C -= 0x180;
            if (gUnk_0203588C <= 0) {
                AnimStart(&gUnk_02035860, 0, 1);
                gUnk_0203588C = 0;
                gUnk_0203587C = 0;
            }
            break;
        case 2:
            func_081015E8();
            gUnk_0203588C += 0x180;
            if (gUnk_0203588C >= 0xBC00) {
                AnimStart(&gUnk_02035860, 0, 1);
                gUnk_0203588C = 0xBC00;
                gUnk_0203587C = 0;
            }
            break;
    }

    if (gUnk_020358BE >= 0) {
        if (gUnk_020358C0 != 0) {
            if (func_080A42C8() == 0) {
                func_080A4234(&gUnk_020358A8, 3, gUnk_020358BE);
                gUnk_020358BE = -1;
            }
        } else {
            func_080A4234(&gUnk_020358A8, 3, gUnk_020358BE);
            gUnk_020358BE = -1;
            gUnk_020358C0 = 1;
        }
    }

    if (gUnk_020358BC >= 0) {
        if (gUnk_020358C0 != 0) {
            if (func_080A42C8() == 0) {
                func_080A411C(&gUnk_020358A8, 3, gUnk_020358BC);
                gUnk_020358BC = -1;
            }
        } else {
            func_080A411C(&gUnk_020358A8, 3, gUnk_020358BC);
            gUnk_020358BC = -1;
            gUnk_020358C0 = 1;
        }
    }
    TaskPoolUpdate(&gUnk_020358A8);
    func_08101970();
}
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

u8 func_0810274C(u16 a) {
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
u8 func_081027B4(s16 a) {
    s16 i;
    s16 k;
    s16 m;
    s16 n;
    s16 v;
    s32 r;

    for (i = 0; i < 4; i++) {
        gUnk_02035B08[i] |= 0xFFFFu;
        for (k = 0; k < 4; k++) {
            gUnk_02035B18[i][k][0] |= 0xFFFFu;
        }
    }

    n = 0;
    for (i = 0; i < 4; i++) {
        m = 0;
        for (k = 0; k < 4; k++) {
            v = gUnk_099935C0[a][i][k];
            if (func_081026C4(gUnk_0203C590[6], i, k) == 0) {
                if (v >= 0) {
                    gUnk_02035B18[n][m][0] = k;
                    gUnk_02035B18[n][m][1] = v;
                    m++;
                }
            }
        }
        if (m > 0) {
            gUnk_02035B08[n] = i;
            n++;
        }
    }

    r = 0;
    if (n > 0) {
        r = 1;
    }
    return r;
}
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
void func_08102AB4(s16 x, s16 y) {
    s16 i;
    u16 id;
    void** p;

    for (i = 0; i < 5; i++) {
        id = gUnk_02035B58[i];
        if (id & 0x8000) {
            gUnk_020358C8[i].unk_46 = 1;
        } else {
            gUnk_020358C8[i].unk_46 = 0;
        }
        gUnk_020358C8[i].unk_47 = 0;
        id &= 0xFFF;
        gUnk_020358C8[i].unk_00 = LoadObjPalette(gCardDefs[id].unk_08, 0x20);
        func_080062F4(gUnk_020358C8[i].unk_00->unk_06 + 0x10, 1);
        gUnk_020358C8[i].unk_04 = LoadObjTiles(gCardDefs[id].unk_04, 0x200);
        gUnk_020358C8[i].unk_08 = gCardDefs[id].unk_00;
        gUnk_020358C8[i].unk_0C = LoadObjPalette(gUnk_09A3DB1C + gCardDefs[id].unk_2A * 32, 0x20);
        func_080062F4(gUnk_020358C8[i].unk_0C->unk_06 + 0x10, 1);
        gUnk_020358C8[i].unk_10 = LoadObjTiles(gUnk_099A4B9A, 0x1D80);
        gUnk_020358C8[i].unk_14 = 0;
        AnimInit(&gUnk_020358C8[i].unk_18, gUnk_09EF9A48, gUnk_09EF9A20);
        AnimStart(&gUnk_020358C8[i].unk_18, 0, 1);
        gUnk_020358C8[i].unk_3C = x << 8;
        gUnk_020358C8[i].unk_40 = y << 8;
        gUnk_020358C8[i].unk_34 = 2;
        gUnk_020358C8[i].unk_30 = 0;
        gUnk_020358C8[i].unk_38 = 0;
        gUnk_020358C8[i].unk_44 = 0;
    }
    gUnk_02035A30 = LoadObjPalette(gUnk_09611AB8, 0x20);
    func_080062F4(((FldRes*)gUnk_02035A30)->unk_06 + 0x10, 1);
    gUnk_02035A34 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    gUnk_02035A38 = LoadObjPalette(gUnk_08F69BA4, 0x20);
    func_080062F4(((FldRes*)gUnk_02035A38)->unk_06 + 0x10, 1);
    gUnk_02035A3C = LoadObjTiles(gUnk_0905ED36, 0x140);
    gUnk_02035AE0 = LoadObjPalette(gUnk_09A3DA7C, 0x20);
    gUnk_02035ADC = LoadObjTiles(gUnk_099A3CE4, 0x1C0);
    AnimInit(&gUnk_02035AE8, gUnk_09EF99F8, gUnk_09EF99D8);
    AnimStart(&gUnk_02035AE8, 0, 1);
    func_080062F4(((FldRes*)gUnk_02035AE0)->unk_06 + 0x10, 1);
    gUnk_02035A40 = LoadObjPalette(gUnk_09A3DB7C, 0x20);
    func_080062F4(((FldRes*)gUnk_02035A40)->unk_06 + 0x10, 1);
    p = &gUnk_02035A44;
    *p = EwramAlloc(0x120);
    func_08065ACC(gUnk_02035A44, 0x24);
    p = &gUnk_02035A4C;
    *p = EwramAlloc(0x2D0);
    func_08065ACC(gUnk_02035A4C, 0x5A);
    gUnk_02035A54 = LoadObjTiles(gUnk_0908B1B4, 0x9A0);
    AnimInit(&gUnk_02035A58, gUnk_09EEA164, gUnk_09EEA148);
    AnimStart(&gUnk_02035A58, 0, 1);

    for (i = 0; i < 5; i++) {
        TaskPoolInit(&gUnk_02035A70[i], 8);
    }
    gUnk_020358C8[0].unk_44 = 15;
}
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
    func_080062F4(((FldRes*)gUnk_02035AE0)->unk_06 + 0x10, 0);
    ReleaseObjPalette(gUnk_02035AE0);
    ReleaseObjTiles(gUnk_02035ADC);
    func_080062F4(((FldRes*)gUnk_02035A40)->unk_06 + 0x10, 0);
    ReleaseObjPalette(gUnk_02035A40);
    func_08065AE0(gUnk_02035A44, 0x24);
    EwramFree(gUnk_02035A44);
    func_08065AE0(gUnk_02035A4C, 0x5A);
    EwramFree(gUnk_02035A4C);
    func_080062F4(((FldRes*)gUnk_02035A30)->unk_06 + 0x10, 0);
    ReleaseObjPalette(gUnk_02035A30);
    ReleaseObjTiles(gUnk_02035A34);
    func_080062F4(((FldRes*)gUnk_02035A38)->unk_06 + 0x10, 0);
    ReleaseObjPalette(gUnk_02035A38);
    ReleaseObjTiles(gUnk_02035A3C);
    ReleaseObjTiles(gUnk_02035A54);

    for (i = 0; i < 5; i++) {
        TaskPoolDestroy(&gUnk_02035A70[i]);
    }
}
void func_08102F30(void) {
    s16 i;
    s32 affine;
    void* obj;
    s32 v;
    void* anim;

    anim = AnimUpdate(&gUnk_02035A58);

    for (i = 0; i < 5; i++) {
        if (gUnk_020358C8[i].unk_47 == 0) {
            v = gUnk_020358C8[i].unk_34;
            affine = AllocObjAffine(0, v, v, 0);
            obj = AnimUpdate(&gUnk_020358C8[i].unk_18);
        } else {
            v = gUnk_020358C8[i].unk_34 * -gSineTable[(gUnk_020358C8[i].unk_30 & 0xFF) + 0x40] >> 8;
            affine = AllocObjAffine(0, v, gUnk_020358C8[i].unk_34, 0);
            obj = gUnk_020358C8[i].unk_14;
        }

        if (v != 0) {
            DrawSprite(gUnk_020358C8[i].unk_3C >> 8, gUnk_020358C8[i].unk_40 >> 8, obj, gUnk_020358C8[i].unk_10, gUnk_020358C8[i].unk_0C, affine, 0, 0x50);
            if (gUnk_020358C8[i].unk_47 != 0) {
                DrawSprite(gUnk_020358C8[i].unk_3C >> 8, gUnk_020358C8[i].unk_40 >> 8, gUnk_020358C8[i].unk_08, gUnk_020358C8[i].unk_04, gUnk_020358C8[i].unk_00, affine, 0, 0x58);
                if (gUnk_020358C8[i].unk_46 != 0) {
                    DrawSprite(gUnk_020358C8[i].unk_3C >> 8, gUnk_020358C8[i].unk_40 >> 8, gUnk_09EE9894[gCardDefs[gUnk_02035B58[i] & 0xFFF].unk_20], gUnk_02035A3C, gUnk_02035A38, affine, 0, 0x48);
                    DrawSprite(gUnk_020358C8[i].unk_3C >> 8, gUnk_020358C8[i].unk_40 >> 8, anim, gUnk_02035A54, gUnk_02035A30, affine, 0, 0x40);
                } else {
                    DrawSprite(gUnk_020358C8[i].unk_3C >> 8, gUnk_020358C8[i].unk_40 >> 8, gUnk_09EE981C[gCardDefs[gUnk_02035B58[i] & 0xFFF].unk_20], gUnk_02035A34, gUnk_02035A30, affine, 0, 0x48);
                }
            }
        }

        if (gUnk_020358C8[i].unk_38 == 9) {
            func_080664D8(0x30, 0x63, gUnk_02035A44, gUnk_02035A40, 0, gUnk_02035A48);
            func_080664D8(0x31, 0x72, gUnk_02035A4C, gUnk_02035AE0, 0, gUnk_02035A50);
            func_0805F1C0(&gUnk_02035AD4, gUnk_020358C8[gUnk_02035B62].unk_3C - 0x1000);
            func_0805F1C0(&gUnk_02035AD8, gUnk_020358C8[gUnk_02035B62].unk_40 - 0x2000);
            DrawSprite(gUnk_02035AD4 >> 8, gUnk_02035AD8 >> 8, AnimUpdate(&gUnk_02035AE8), gUnk_02035ADC, gUnk_02035AE0, 0, 0, 0);
        }
    }

    for (i = 0; i < 5; i++) {
        TaskPoolDraw(&gUnk_02035A70[i]);
    }
}
u8 func_0810329C(u16 a) {
    MsShopHosiArg arg0;
    MsShopHosiArg arg1;
    MsShopHosiArg arg2;
    u8 result;
    s16 i;
    s16 j;
    s16 k;
    s16 old;
    u16 keys;
    u16 d;
    s32 f;
    s32 g;
    s32 h;

    result = 1;

    for (i = 0; i < 5; i++) {
        switch (gUnk_020358C8[i].unk_38) {
            case 0:
                if (func_08006314() == 0) {
                    if (gUnk_020358C8[i].unk_44 != 0) {
                        gUnk_020358C8[i].unk_38 = 1;
                    }
                }
                break;
            case 1:
                ApproachValue(&gUnk_020358C8[i].unk_3C, i * 10240 + 0x2800, gUnk_020358C8[i].unk_44);
                ApproachValue(&gUnk_020358C8[i].unk_40, 0x6400, gUnk_020358C8[i].unk_44);
                ApproachValue(&gUnk_020358C8[i].unk_34, 0x100, gUnk_020358C8[i].unk_44);
                if (--gUnk_020358C8[i].unk_44 == 0) {
                    if (gUnk_020358C8[i].unk_46 != 0) {
                        gUnk_020358C8[i].unk_38 = 5;
                    } else {
                        gUnk_020358C8[i].unk_38 = 2;
                    }
                    if (i <= 3) {
                        gUnk_020358C8[i + 1].unk_44 = 15;
                    } else {
                        for (j = 0; j < 5; j++) {
                            if (gUnk_020358C8[j].unk_38 == 2) {
                                gUnk_020358C8[j].unk_44 = 8;
                                break;
                            }
                        }
                        if (j == 5) {
                            gUnk_020358C8[0].unk_44 = 8;
                        }
                    }
                }
                break;
            case 2:
                if (gUnk_020358C8[i].unk_44 != 0) {
                    if (func_08005B34(&gUnk_020358C8[i].unk_18) == 3 || func_08005B34(&gUnk_020358C8[i].unk_18) == 8) {
                        ReleaseObjPalette(gUnk_020358C8[i].unk_0C);
                        ReleaseObjTiles(gUnk_020358C8[i].unk_10);
                        gUnk_020358C8[i].unk_0C = LoadObjPalette(gUnk_09611AB8, 0x20);
                        func_080062F4(gUnk_020358C8[i].unk_0C->unk_06 + 0x10, 1);
                        gUnk_020358C8[i].unk_10 = LoadObjTiles(gUnk_08F709B0[gCardDefs[gUnk_02035B58[i] & 0xFFF].unk_2A].unk_0C, 0x300);
                        gUnk_020358C8[i].unk_14 = gUnk_08F709B0[gCardDefs[gUnk_02035B58[i] & 0xFFF].unk_2A].unk_00;
                        gUnk_020358C8[i].unk_30 = 0x40;
                        gUnk_020358C8[i].unk_38 = 3;
                        gUnk_020358C8[i].unk_47 = 1;
                    }
                }
                break;
            case 3:
                d = 0x80 - gUnk_020358C8[i].unk_30;
                gUnk_020358C8[i].unk_30 += d / gUnk_020358C8[i].unk_44;
                if (--gUnk_020358C8[i].unk_44 == 0) {
                    gUnk_020358C8[i].unk_44 = 5;
                    gUnk_020358C8[i].unk_38 = 4;
                }
                break;
            case 4:
                ApproachValue(&gUnk_020358C8[i].unk_40, 0x4600, gUnk_020358C8[i].unk_44);
                if (--gUnk_020358C8[i].unk_44 == 0) {
                    m4aSongNumStart(0xD2);
                    gUnk_020358C8[i].unk_38 = 8;
                    for (j = 0; j < 5; j++) {
                        if (gUnk_020358C8[j].unk_38 == 2) {
                            gUnk_020358C8[j].unk_44 = 8;
                            break;
                        }
                    }
                    if (j == 5) {
                        for (j = 0; j < 5; j++) {
                            if (gUnk_020358C8[j].unk_38 == 5) {
                                gUnk_020358C8[j].unk_44 = 8;
                                break;
                            }
                        }
                        if (j == 5) {
                            gUnk_020358C8[0].unk_44 = 60;
                        }
                    }
                }
                break;
            case 5:
                if (gUnk_020358C8[i].unk_44 != 0) {
                    if (func_08005B34(&gUnk_020358C8[i].unk_18) == 3 || func_08005B34(&gUnk_020358C8[i].unk_18) == 8) {
                        ReleaseObjPalette(gUnk_020358C8[i].unk_0C);
                        ReleaseObjTiles(gUnk_020358C8[i].unk_10);
                        gUnk_020358C8[i].unk_0C = LoadObjPalette(gUnk_09611AB8, 0x20);
                        func_080062F4(gUnk_020358C8[i].unk_0C->unk_06 + 0x10, 1);
                        gUnk_020358C8[i].unk_10 = LoadObjTiles(gUnk_08F709B0[gCardDefs[gUnk_02035B58[i] & 0xFFF].unk_2A].unk_0C, 0x300);
                        gUnk_020358C8[i].unk_14 = gUnk_08F709B0[gCardDefs[gUnk_02035B58[i] & 0xFFF].unk_2A].unk_00;
                        gUnk_020358C8[i].unk_30 = 0x40;
                        gUnk_020358C8[i].unk_38 = 6;
                        gUnk_020358C8[i].unk_47 = 1;
                    }
                }
                break;
            case 6:
                d = 0x80 - gUnk_020358C8[i].unk_30;
                gUnk_020358C8[i].unk_30 += d / gUnk_020358C8[i].unk_44;
                if (--gUnk_020358C8[i].unk_44 == 0) {
                    gUnk_020358C8[i].unk_44 = 5;
                    gUnk_020358C8[i].unk_38 = 7;
                    for (k = 0; k < 8; k++) {
                        arg0.unk_00 = gUnk_020358C8[i].unk_3C >> 8;
                        arg0.unk_02 = gUnk_020358C8[i].unk_40 >> 8;
                        arg0.unk_04 = gUnk_02035A40;
                        arg0.unk_08 = GetRandom() % 96 - 48;
                        arg0.unk_0C = GetRandom() % 256 + 0x1C0;
                        TaskCreate(&gUnk_02035A70[i], gUnk_09EF9650, &arg0);
                    }
                }
                break;
            case 7:
                ApproachValue(&gUnk_020358C8[i].unk_40, 0x4600, gUnk_020358C8[i].unk_44);
                f = gFrameCounter & 0x1F;
                if (f == 0) {
                    arg0.unk_00 = (gUnk_020358C8[i].unk_3C >> 8) + GetRandom() % 32 - 16;
                    arg0.unk_02 = (gUnk_020358C8[i].unk_40 >> 8) + GetRandom() % 32 - 16;
                    arg0.unk_04 = gUnk_02035A40;
                    arg0.unk_08 = 0x80;
                    arg0.unk_0C = f;
                    TaskCreate(&gUnk_02035A70[i], gUnk_09EF9650, &arg0);
                }
                if (--gUnk_020358C8[i].unk_44 == 0) {
                    m4aSongNumStart(0xD2);
                    gUnk_020358C8[i].unk_38 = 8;
                    for (j = 0; j < 5; j++) {
                        if (gUnk_020358C8[j].unk_38 == 5) {
                            gUnk_020358C8[j].unk_44 = 8;
                            break;
                        }
                    }
                    if (j == 5) {
                        gUnk_020358C8[0].unk_44 = 60;
                    }
                }
                break;
            case 8:
                if (gUnk_020358C8[i].unk_46 != 0) {
                    g = gFrameCounter & 0x1F;
                    if (g == 0) {
                        arg1.unk_00 = (gUnk_020358C8[i].unk_3C >> 8) + GetRandom() % 32 - 16;
                        arg1.unk_02 = (gUnk_020358C8[i].unk_40 >> 8) + GetRandom() % 32 - 16;
                        arg1.unk_04 = gUnk_02035A40;
                        arg1.unk_08 = 0x80;
                        arg1.unk_0C = g;
                        TaskCreate(&gUnk_02035A70[i], gUnk_09EF9650, &arg1);
                    }
                }
                if (gUnk_020358C8[i].unk_44 != 0) {
                    if (--gUnk_020358C8[i].unk_44 == 0) {
                        if (a & 1) {
                            SetupBg(3, 0, 31, 0);
                            SetBgScroll(3, 0, 0);
                            RequestDma3Copy(gUnk_09A17D1C, (u8*)GetBgCharBase(3) + 0x5800, 0x1400);
                            LoadBgMap(3, gUnk_09A3AD5C, 0x500);
                        }
                        gUnk_02035B62 = 0;
                        gUnk_02035AD4 = gUnk_020358C8[0].unk_3C - 0x1000;
                        gUnk_02035AD8 = gUnk_020358C8[0].unk_40 - 0x2000;
                        LoadPalette(gUnk_09A3DA1C + gCardDefs[gUnk_02035B58[gUnk_02035B62] & 0xFFF].unk_2A * 32, (void*)0x050001A0, 0x20);
                        gUnk_02035A48 = func_08065B6C(gCardDefs[gUnk_02035B58[gUnk_02035B62] & 0xFFF].unk_0C, gUnk_02035A44);
                        gUnk_02035A50 = func_08065B6C(gUnk_09EE8F48[gCardDefs[gUnk_02035B58[gUnk_02035B62] & 0xFFF].unk_1C], gUnk_02035A4C);
                        LoadObjPaletteBank(((FldRes*)gUnk_02035A40)->unk_06, gUnk_09A3DB7C + gCardDefs[gUnk_02035B58[gUnk_02035B62] & 0xFFF].unk_2A * 32);
                        EnableBg(3);
                        gUnk_020358C8[i].unk_38 = 9;
                    }
                }
                break;
            case 9:
                if (gUnk_020358C8[i].unk_46 != 0) {
                    h = gFrameCounter & 0x1F;
                    if (h == 0) {
                        arg2.unk_00 = (gUnk_020358C8[i].unk_3C >> 8) + GetRandom() % 32 - 16;
                        arg2.unk_02 = (gUnk_020358C8[i].unk_40 >> 8) + GetRandom() % 32 - 16;
                        arg2.unk_04 = gUnk_02035A40;
                        arg2.unk_08 = 0x80;
                        arg2.unk_0C = h;
                        TaskCreate(&gUnk_02035A70[i], gUnk_09EF9650, &arg2);
                    }
                }
                keys = func_08102A94();
                old = gUnk_02035B62;
                if (keys & (A_BUTTON | B_BUTTON)) {
                    m4aSongNumStart(0x68);
                    result = 0;
                } else if (keys & DPAD_LEFT) {
                    gUnk_02035B62--;
                    if (gUnk_02035B62 < 0) {
                        gUnk_02035B62 = 4;
                    }
                } else if (keys & DPAD_RIGHT) {
                    gUnk_02035B62++;
                    if (gUnk_02035B62 > 4) {
                        gUnk_02035B62 = 0;
                    }
                }
                if (gUnk_02035B62 != old) {
                    LoadPalette(gUnk_09A3DA1C + gCardDefs[gUnk_02035B58[gUnk_02035B62] & 0xFFF].unk_2A * 32, (void*)0x050001A0, 0x20);
                    gUnk_02035A48 = func_08065B6C(gCardDefs[gUnk_02035B58[gUnk_02035B62] & 0xFFF].unk_0C, gUnk_02035A44);
                    gUnk_02035A50 = func_08065B6C(gUnk_09EE8F48[gCardDefs[gUnk_02035B58[gUnk_02035B62] & 0xFFF].unk_1C], gUnk_02035A4C);
                    LoadObjPaletteBank(((FldRes*)gUnk_02035A40)->unk_06, gUnk_09A3DB7C + gCardDefs[gUnk_02035B58[gUnk_02035B62] & 0xFFF].unk_2A * 32);
                    m4aSongNumStart(0x65);
                }
                break;
        }
    }

    for (i = 0; i < 5; i++) {
        TaskPoolUpdate(&gUnk_02035A70[i]);
    }
    return result;
}
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
void func_08104404(void) {
    s32 i;
    s16 v;

    switch (gUnk_02035B02) {
        case 2:
            if (gUnk_02035B00 != 0) {
                func_0805F1C0(&gUnk_02035C04, 0x400);
                func_0805F1C0(&gUnk_02035C08, gUnk_02035B04 * 6144 + 0x800);
                DrawSprite(gUnk_02035C04 >> 8, gUnk_02035C08 >> 8, AnimUpdate(&gUnk_02035BB8), gUnk_02035BAC, gUnk_02035BB0, 0, 0x400, 0x3E8);
            }
            break;
        case 3:
            func_0805F1C0(&gUnk_02035C04, gUnk_099931E4[gUnk_02035B10].unk_08 << 8);
            func_0805F1C0(&gUnk_02035C08, gUnk_099931E4[gUnk_02035B10].unk_0A << 8);
            DrawSprite(gUnk_02035C04 >> 8, gUnk_02035C08 >> 8, AnimUpdate(&gUnk_02035BB8), gUnk_02035BAC, gUnk_02035BB0, 0, 0x400, 0x3E8);
            break;
        case 4:
            func_08102F30();
            break;
    }

    for (i = 0; i < 4; i++) {
        if (gUnk_02035B18[gUnk_02035B04][i][0] >= 0) {
            v = gUnk_02035B18[gUnk_02035B04][i][1];
            DrawSprite(gUnk_099931E4[i].unk_16 + gUnk_099932D4[v].unk_14, gUnk_099931E4[i].unk_18 + gUnk_099932D4[v].unk_16, gUnk_02035BF0[v], gUnk_02035BD0[v], gUnk_02035BE0[v], 0, 0x400, 0x3F2);
        }
    }
}
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
void mode_ms_shop_1(void) {
    UpdatePlayTime();
    switch (gUnk_02035B02) {
        case 0:
            if (func_08006314() == 0) {
                if (gUnk_02035B00 != 0) {
                    gUnk_02035C04 = 0x400;
                    gUnk_02035C08 = gUnk_02035B04 * 6144 + 0x800;
                    gUnk_02035B02 = 2;
                } else {
                    gUnk_02035B02 = 1;
                }
            }
            break;
        case 1:
            func_08103D7C();
            break;
        case 2:
            func_08103DE8();
            break;
        case 3:
            func_081041B4();
            break;
        case 4:
            if (func_0810329C(0) == 0) {
                func_08102DC8();
                func_0810264C(gUnk_0203C590[6], gUnk_02035B08[gUnk_02035B04], gUnk_02035B18[gUnk_02035B04][gUnk_02035B10][0]);
                gUnk_02035B00 = func_081027B4(gUnk_02039BB0.unk_00E);
                LoadBgMap(0, gUnk_09A382DC, 0x500);
                if (gUnk_02035B04 > 0) {
                    if (gUnk_02035B08[gUnk_02035B04] < 0) {
                        do {
                            gUnk_02035B04--;
                            if (gUnk_02035B04 <= 0) {
                                break;
                            }
                        } while (gUnk_02035B08[gUnk_02035B04] < 0);
                    }
                }
                func_08103CD8(gUnk_02035B04);
                func_08102984(gUnk_02035B04);
                if (gUnk_02035B00 != 0) {
                    for (; gUnk_02035B10 > 0 && gUnk_02035B18[gUnk_02035B04][gUnk_02035B10][0] < 0; gUnk_02035B10--) {
                    }
                    func_08103D54(gUnk_02035B10);
                } else {
                    DisableBg(1);
                }
                func_08101588(func_08101518(), gUnk_09A18D7C, (u8*)GetBgCharBase(0) + 0x20, 0x20, 5);
                DisableBg(3);
                func_080061E8(0, 8);
                gUnk_02035B02 = gUnk_02035B00 != 0 ? 3 : 1;
            }
            break;
        case 5:
            if (func_08006314() == 0) {
                if (gUnk_02035C0C != 0) {
                    func_080010CC(&gUnk_09EF95E8, 2);
                } else {
                    func_080E04EC();
                }
            }
            break;
    }
    func_08104404();
}
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
