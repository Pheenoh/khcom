#include "macros.h"
#include "mode_sio.h"
#include "gba/keys.h"

void mode_sio_btl_connect_0(s32 arg) {
    gUnk_02034B3C = EwramAlloc(sizeof(SioBtlConnectWork));
    func_08006120(0, 16);
    func_08004DB0();
    SetupBg(0, 0, 7, 15);
    SetupBg(1, 1, 31, 0);
    EnableBg(0);
    EnableBg(1);
    LoadBgTiles(0, gUnk_096AD604, 0x140);
    LoadBgMap(0, gUnk_096F6464, 0x800);
    LoadBgPalette(0, gUnk_09611AB8, 0x20);
    LoadBgTiles(1, gUnk_096ACA44, 0xBC0);
    LoadBgPalette(1, gUnk_096FBA04, 0x40);
    LoadBgMap(1, gUnk_096F5C64, 0x800);
    gUnk_02034B3C->unk_00 = 0;
    gUnk_02034B3C->unk_02 = 0;
    gUnk_02034B3C->unk_04 = 0;
    gUnk_02034B3C->unk_05 = 0;
    func_08065ACC(gUnk_02034B3C->unk_08, 0x5A);
    gUnk_02034B3C->unk_05 = func_08065B6C(gUnk_08159E4A, gUnk_02034B3C->unk_08);
    gUnk_02034B3C->unk_2D8 = LoadObjPalette(gUnk_096FBAA4, 32);
    func_08006E60();
    func_080C5A3C(func_080AEE50, func_080AEE6C, 0);
}

#ifndef VERSION_JP
void mode_sio_btl_connect_1(void) {
    s32 i;
    s32 j;

    switch (gUnk_02034B3C->unk_04) {
    case 0:
        func_080C54B4();
        break;
    case 1:
        func_080C54B4();
        gUnk_02034B3C->unk_02++;
        if (gUnk_02034B3C->unk_02 > 4) {
            func_080C5DC0(func_080C6008, func_080C60D8);
            func_080C61D4();
            gUnk_03006C78 |= 1;
            gUnk_03006C78 |= 0x10;
            gUnk_02034B3C->unk_04++;
        }
        break;
    case 2:
        if (gUnk_02039B60 == 2) {
            gUnk_02034B3C->unk_02 = 0;
            func_080AEE84();
            gUnk_02034B3C->unk_04++;
        }
        break;
    case 3:
        gUnk_02034B3C->unk_02++;
        if (gUnk_02034B3C->unk_02 > 4) {
            func_080C5DC0(func_080C5D50, func_080C5D80);
            func_080C5D00();
            gUnk_0203AA00 = 1;
            gUnk_0203AA90 = 1;
            gUnk_0203AA8C = 1;
            gUnk_0203AA58[0] = 6;
            gUnk_0203AA58[1] = 6;

            for (i = 0; i < 2; i++) {
                for (j = 0; j < 20; j++) {
                    gUnk_0203AA60[i][j] = 0;
                    gUnk_0203AAE0[i][j] = 0;
                    gUnk_0203AA30[i][j] = 0;
                }
            }
            gUnk_0203A9EC = 0;
            gUnk_0203A9F0 = 0;
            ModeRequest(&gUnk_09EF14DC, 0);
            return;
        }
        break;
    }
    func_080664D8(0x42, 0x3F, gUnk_02034B3C->unk_08, gUnk_02034B3C->unk_2D8, 20, gUnk_02034B3C->unk_05);
}
#else
INCLUDE_ASM("mode_sio/mode_sio_btl_connect_1.s");
#endif

void mode_sio_btl_connect_2(void) {
    ReleaseObjPalette(gUnk_02034B3C->unk_2D8);
    func_08065AE0(gUnk_02034B3C->unk_08, 0x5A);
    EwramFree(gUnk_02034B3C);
}

void func_080AEE50(void) {
    m4aSongNumStart(0x6A);
    gUnk_02034B3C->unk_04++;
}

void func_080AEE6C(void) {
    m4aSongNumStart(0x68);
    ModeRequest(&gUnk_09EF12F8, 2);
}

void func_080AEE84(void) {
    s32 i;
    s32 flags;
    gUnk_0203AA88 = 0;

    for (i = 0; i < 13; i++) {
        gUnk_0203AAA0[i] = 0;
    }
    flags = 0x1FFE;

    for (i = 1; i < 14; i++) {
        if ((flags >> i) & 1) {
            gUnk_0203AAA0[gUnk_0203AA88 + 1] = i;
            gUnk_0203AA88++;
        }
    }
}

void func_080AEED8(u16 a, u16 b, u16 c) {
    SioAnimDef* def = &gUnk_096193E0[b];
    func_08005974(&gUnk_02034B40->unk_020[a], def->unk_0C, c, def->unk_04, def->unk_00);
    func_08002A10(gUnk_02034B40->unk_008[a], def->unk_08);
}

void mode_sio_btl_option_0(s32 arg) {
    gUnk_02034B40 = EwramAlloc(sizeof(SioBtlOptionWork));
    func_08004E64();
    SetupBg(0, 0, 7, 10);
    SetBgPriority(0, 0);
    SetBgOverflow(0, 1);
    SetBgSize(0, 0);
    SetupBg(1, 0, 15, 10);
    SetBgPriority(1, 1);
    SetBgOverflow(1, 1);
    SetBgSize(1, 0);
    SetupBg(2, 2, 24, 0);
    SetBgPriority(2, 2);
    SetBgOverflow(2, 1);
    SetBgSize(2, 0x8000);
    RequestDma3Copy(gUnk_096AD744, GetBgCharBase(0), 0x2000);
    func_08065ACC(gUnk_02034B40->unk_054, 20);
    func_08065ACC(gUnk_02034B40->unk_0FC, 10);
    func_08065ACC(gUnk_02034B40->unk_154, 10);
    gUnk_02034B40->unk_0F8 = func_08065B6C(gUnk_0203AA30[0], gUnk_02034B40->unk_0FC);
    gUnk_02034B40->unk_150 = func_08065B6C(gUnk_0203AA30[1], gUnk_02034B40->unk_154);
    gUnk_02034B40->unk_0F4 = LoadObjPalette(gUnk_096FBCC4, 32);
    gUnk_02034B40->unk_14C = LoadObjPalette(gUnk_096FBCC4 + 64, 32);
    gUnk_02034B40->unk_1A4 = LoadObjPalette(gUnk_096FBCC4 + 32, 32);
    gUnk_02034B40->unk_417 = gUnk_0203AAA0[gUnk_0203AA00];
    DisableBg(0);
    DisableBg(1);
    gUnk_02034B40->unk_21A = arg;
    gUnk_02034B40->unk_002 = 0;
}

void func_080AF0B0(void) {
    RequestDma3Copy(gUnk_096AF744, (u8*)GetBgCharBase(0) + 0x2000, 0x800);
    LoadBgMap(0, gUnk_096F6C64, 0x800);
    LoadBgPalette(0, gUnk_096FBC04, 0xC0);
    LoadBgMap(1, gUnk_096F7464, 0x800);
    DisableBg(0);
    DisableBg(1);
    gUnk_02034B40->unk_002 = 1;
}

#ifndef VERSION_JP
void func_080AF11C(void) {
    s32 i;

    if (gUnk_02034B40->unk_21A == 1) {
        gUnk_02034B40->unk_1B4 = 1;
        gUnk_02034B40->unk_000 = 1;
        gUnk_02034B40->unk_1DC = gUnk_02034B40->unk_000 * 4608 + 10752;
    } else {
        gUnk_02034B40->unk_1B4 = 0;
        gUnk_02034B40->unk_000 = 0;
        gUnk_02034B40->unk_1DC = 10752;
    }
    gUnk_02034B40->unk_004 = 0;
    gUnk_02034B40->unk_006 = 0;
    gUnk_02034B40->unk_217 = 0;
    gUnk_02034B40->unk_218 = 0;
    gUnk_02034B40->unk_410 = 0;
    gUnk_02034B40->unk_1FA = 0;
    gUnk_02034B40->unk_416 = 0;
    gUnk_02034B40->unk_418 = 0;
    func_08005690(2, 0, 256, 256, 0x10000, 0x16800);

    for (i = 0; i < 2; i++) {
        gUnk_02034B40->unk_008[i] = AllocObjTiles(0xC80, 0);
        AnimInit(&gUnk_02034B40->unk_020[i], 0, 0);
        func_080AEED8(i, 0, 0);
        gUnk_02034B40->unk_018[i] = AnimGetGfx(&gUnk_02034B40->unk_020[i]);
    }

    if (gUnk_02039828 == 0) {
        gUnk_02034B40->unk_008[2] = LoadObjPalette(gUnk_08F683A4, 32);
        gUnk_02034B40->unk_008[3] = LoadObjPalette(gUnk_096FAC64, 32);
    } else {
        gUnk_02034B40->unk_008[2] = LoadObjPalette(gUnk_096FAC64, 32);
        gUnk_02034B40->unk_008[3] = LoadObjPalette(gUnk_08F683A4, 32);
    }
    gUnk_02034B40->unk_1A8 = LoadObjTiles(gUnk_0962BEDA, 0xC00);
    gUnk_02034B40->unk_1AC = LoadObjPalette(gUnk_096FBD24, 32);
    gUnk_02034B40->unk_1B0 = gUnk_09EF38D4[0];
    gUnk_02034B40->unk_1B8 = LoadObjTiles(gUnk_0962B090, 0x1C0);
    gUnk_02034B40->unk_1BC = LoadObjPalette(gUnk_096FBAA4, 32);
    AnimInit(&gUnk_02034B40->unk_1C4, gUnk_09EF38B4, gUnk_09EF3894);
    AnimStart(&gUnk_02034B40->unk_1C4, 1, 1);
    gUnk_02034B40->unk_1C0 = AnimGetGfx(&gUnk_02034B40->unk_1C4);
    gUnk_02034B40->unk_1E0 = 1;
    gUnk_02034B40->unk_21C = LoadObjTiles(gUnk_093F8C8E, 0xC00);
    gUnk_02034B40->unk_220 = LoadObjPalette(gUnk_09611AB8, 32);
    gUnk_02034B40->unk_224 = gUnk_09EF1278[0];
    gUnk_02034B40->unk_228 = 0;
    func_08065ACC(gUnk_02034B40->unk_22C, 60);
    gUnk_02034B40->unk_229 = func_08065B6C(gUnk_0815A20C, gUnk_02034B40->unk_22C);
    gUnk_02034B40->unk_412 = 65;
    gUnk_02034B40->unk_414 = 124;
    gUnk_02034B40->unk_40C = LoadObjPalette(gUnk_096FBAA4, 32);
    gUnk_02034B40->unk_1E4 = LoadObjTiles(gUnk_0962D7C0, 0x120);
    gUnk_02034B40->unk_1E8 = LoadObjPalette(gUnk_096FBD44, 32);
    gUnk_02034B40->unk_1EC = gUnk_09EF38EC[0];
    gUnk_02034B40->unk_1F0 = gUnk_09EF38EC[1];
    gUnk_02034B40->unk_1F4 = gUnk_09EF38EC[2];
    gUnk_02034B40->unk_1F8 = 0;
    gUnk_02034B40->unk_1FC[0] = LoadObjTiles(gUnk_0962D900, 0x280);
    gUnk_02034B40->unk_20C[0] = LoadObjPalette(gUnk_096FBD64, 32);
    gUnk_02034B40->unk_204[0] = gUnk_09EF38FC[0];
    gUnk_02034B40->unk_214[0] = gUnk_0203AA58[0];
    gUnk_02034B40->unk_1FC[1] = LoadObjTiles(gUnk_0962DBA0, 0x280);
    gUnk_02034B40->unk_20C[1] = LoadObjPalette(gUnk_096FBDA4, 32);
    gUnk_02034B40->unk_204[1] = gUnk_09EF3904[0];
    gUnk_02034B40->unk_214[1] = gUnk_0203AA58[1];

    if (gUnk_02039828 == 0) {
        gUnk_02034B40->unk_216 = gUnk_0203AA58[0];
    } else {
        gUnk_02034B40->unk_216 = gUnk_0203AA58[1];
    }
    func_080B09C0();
    gUnk_02034B40->unk_002 = 2;
}
#else
INCLUDE_ASM("mode_sio/func_080AF11C.s");
#endif

void func_080AF4F8(void) {
    s8 i = gUnk_0203AAA0[gUnk_0203AA00];
    RequestDma3Copy(gUnk_09EF1318[i].unk_00, GetBgCharBase(2), 0x2000);
    LoadBgPalette(2, gUnk_09EF1318[i].unk_10, gUnk_09EF1318[i].unk_14);
    LoadBgMap(2, gUnk_09EF1318[i].unk_08, gUnk_09EF1318[i].unk_0C);
    gUnk_02034B40->unk_050 = func_08065B6C(gUnk_09EF1318[i].unk_18, gUnk_02034B40->unk_054);
    DisableBg(2);
    gUnk_02034B40->unk_002++;
}

void func_080AF58C(void) {
    s8 i = gUnk_0203AAA0[gUnk_0203AA00];
    func_08006120(0, 16);
    RequestDma3Copy((u8*)gUnk_09EF1318[i].unk_00 + 0x2000, (u8*)GetBgCharBase(2) + 0x2000, gUnk_09EF1318[i].unk_04 - 0x2000);
    EnableBg(0);
    EnableBg(1);
    EnableBg(2);
    func_080B13D0();
    gUnk_02034B40->unk_001 = 4;
    gUnk_02034B40->unk_002 = 4;
}

void mode_sio_btl_option_1(void) {
    switch (gUnk_02034B40->unk_002) {
    case 0:
        func_080AF0B0();
        break;
    case 1:
        func_080AF11C();
        break;
    case 2:
        func_080AF4F8();
        break;
    case 3:
        func_080AF58C();
        break;
    case 4:
        func_080AFA90();
        break;
    case 5:
        func_080AFADC();
        func_080AF70C();
        break;
    case 6:
        func_080AFCD4();
        func_080AF70C();
        break;
    case 7:
        func_080AFEFC();
        func_080AF70C();
        break;
    case 8:
        func_080B0010();
        func_080AF70C();
        break;
    case 9:
        func_080B01FC();
        func_080AF70C();
        break;
    case 10:
        func_080B02A4();
        func_080AF70C();
        break;
    case 11:
        func_080B0380();
        func_080AF70C();
        break;
    case 12:
        func_080B03BC();
        func_080AF70C();
        break;
    case 13:
        func_080B03DC();
        func_080AF70C();
        break;
    case 14:
        func_080B041C();
        func_080AF70C();
        break;
    case 15:
        func_080B0440();
        func_080AF70C();
        break;
    case 16:
        func_080B0494();
        func_080AF70C();
        break;
    }
}

void func_080AF70C(void) {
    gUnk_02034B40->unk_018[0] = AnimUpdate(&gUnk_02034B40->unk_020[0]);
    gUnk_02034B40->unk_018[1] = AnimUpdate(&gUnk_02034B40->unk_020[1]);
    gUnk_02034B40->unk_1C0 = AnimUpdate(&gUnk_02034B40->unk_1C4);
    DrawSprite(60, 88, gUnk_02034B40->unk_018[0], gUnk_02034B40->unk_008[0], gUnk_02034B40->unk_008[2], 0, 1, 0xFFF0);
    DrawSprite(180, 88, gUnk_02034B40->unk_018[1], gUnk_02034B40->unk_008[1], gUnk_02034B40->unk_008[3], 0, 0, 0xFFF0);
    func_080664D8(gUnk_09EF1318[gUnk_02034B40->unk_417].unk_1E + 108, 4, gUnk_02034B40->unk_054, gUnk_02034B40->unk_0F4, 20, gUnk_02034B40->unk_050);
    func_080664D8(16, 144, gUnk_02034B40->unk_0FC, gUnk_02034B40->unk_14C, 0xF200, gUnk_02034B40->unk_0F8);
    func_080664D8(136, 144, gUnk_02034B40->unk_154, gUnk_02034B40->unk_1A4, 0xF200, gUnk_02034B40->unk_150);
    DrawSprite(-((gUnk_02034B40->unk_1FA >> 3) % 4) + 88, 2, gUnk_02034B40->unk_1EC, gUnk_02034B40->unk_1E4, gUnk_02034B40->unk_1E8, 0, 0, 0xFF00);
    DrawSprite(224 + ((gUnk_02034B40->unk_1FA >> 3) % 4), 2, gUnk_02034B40->unk_1F0, gUnk_02034B40->unk_1E4, gUnk_02034B40->unk_1E8, 0, 0, 0xFF00);

    if (gUnk_02034B40->unk_1B4 == 1) {
        DrawSprite(72, 38, gUnk_02034B40->unk_1B0, gUnk_02034B40->unk_1A8, gUnk_02034B40->unk_1AC, 0, 0, 0x200);

        if (gUnk_02034B40->unk_1E0 == 1) {
            func_0805F1C0(&gUnk_02034B40->unk_1DC, gUnk_02034B40->unk_000 * 4608 + 10752);
            DrawSprite(64, gUnk_02034B40->unk_1DC >> 8, gUnk_02034B40->unk_1C0, gUnk_02034B40->unk_1B8, gUnk_02034B40->unk_1BC, 0, 0, 0x100);
        }
    }

    if (gUnk_02034B40->unk_228 == 1) {
        DrawSprite(120, 131, gUnk_02034B40->unk_224, gUnk_02034B40->unk_21C, gUnk_02034B40->unk_220, 0, 0, 0xF000);
        func_080664D8(gUnk_02034B40->unk_412, gUnk_02034B40->unk_414, gUnk_02034B40->unk_22C, gUnk_02034B40->unk_40C, 20, gUnk_02034B40->unk_229);
    }
    DrawSprite(32, 24, gUnk_02034B40->unk_204[0], gUnk_02034B40->unk_1FC[0], gUnk_02034B40->unk_20C[0], 0, 0, 0xF100);
    DrawSprite(132, 24, gUnk_02034B40->unk_204[1], gUnk_02034B40->unk_1FC[1], gUnk_02034B40->unk_20C[1], 0, 0, 0xF100);

    if (gUnk_02034B40->unk_1F8 == 1) {
        DrawSprite(gUnk_02039828 * 101 + 44 + gUnk_09EF14B8[gUnk_02034B40->unk_216], -((gUnk_02034B40->unk_1FA >> 3) % 4) / 2 + 22, gUnk_02034B40->unk_1F4, gUnk_02034B40->unk_1E4, gUnk_02034B40->unk_1E8, 0, 0, 0xF000);
    }
    gUnk_02034B40->unk_1FA++;
}

void func_080AFA90(void) {
    if (gUnk_02034B40->unk_006 > 4) {
        gUnk_02034B40->unk_006 = 0;

        if (gUnk_02034B40->unk_21A == 1) {
            gUnk_02034B40->unk_002 = 6;
        } else {
            gUnk_02034B40->unk_002 = 5;
        }
    } else {
        gUnk_02034B40->unk_006++;
    }
    func_080B0634();
    func_080B1064();
    func_080B06D4();
    func_080B0874();
}

void func_080AFADC(void) {
    s8 v = 0;
    gUnk_02039B58[1] |= 5;

    if (GetKeysPressed() & 1) {
        gUnk_02039B58[1] |= 0x1F20;
    } else if (GetKeysPressed() & 2) {
        gUnk_02039B58[1] |= 0xC2F0;
    }

    if (GetKeysPressed() & L_BUTTON) {
        if (gUnk_0203AA88 == 1) {
            m4aSongNumStart(105);
        } else {
            v = gUnk_0203AA00;
            v--;
            if (v <= 0) {
                v = gUnk_0203AA88;
            }
            gUnk_02039B58[2] |= v & 15;
        }
    } else if (GetKeysPressed() & R_BUTTON) {
        if (gUnk_0203AA88 == 1) {
            m4aSongNumStart(105);
        } else {
            v = gUnk_0203AA00;
            v++;
            if (v > gUnk_0203AA88) {
                v = 1;
            }
            gUnk_02039B58[2] |= v & 15;
        }
    } else {
        gUnk_02039B58[2] &= 0xFFF0;
    }

    if ((gUnk_02039810[1][0] & 0xFFF0) == 0xC2F0 || (gUnk_02039810[1][1] & 0xFFF0) == 0xC2F0) {
        if ((gUnk_02039810[1][0] & 15) == 5 && (gUnk_02039810[1][1] & 15) == 5 && gUnk_02034B40->unk_416 == 0) {
            func_080C57B4();
            m4aMPlayAllStop();
            gUnk_0203A9EC = 0;
            gUnk_0203A9F0 = 0;
            ModeRequest(&gUnk_09EF1308, 0);
        }
    } else if ((gUnk_02039810[1][0] & 0xFFF0) == 0x1F20) {
        gUnk_02034B40->unk_416 = 10;

        if (gUnk_02039828 == 0) {
            m4aSongNumStart(103);
            gUnk_02034B40->unk_1B4 = 1;
            gUnk_02034B40->unk_002 = 6;
        }
    } else if ((gUnk_02039810[1][1] & 0xFFF0) == 0x1F20) {
        gUnk_02034B40->unk_416 = 10;

        if (gUnk_02039828 == 1) {
            m4aSongNumStart(103);
            gUnk_02034B40->unk_1B4 = 1;
            gUnk_02034B40->unk_002 = 6;
        }
    }
    func_080B0634();
    func_080B1064();
    func_080B06D4();
    func_080B0874();

    if (gUnk_02034B40->unk_416 > 0) {
        gUnk_02034B40->unk_416--;
    }
}

#ifndef VERSION_JP
void func_080AFCD4(void) {
    s8 v = 0;
    gUnk_02039B58[1] = 6;

    if (GetKeysPressed() & DPAD_UP) {
        m4aSongNumStart(101);
        gUnk_02034B40->unk_000--;
        if (gUnk_02034B40->unk_000 < 0) {
            gUnk_02034B40->unk_000 = 2;
        }
    } else if (GetKeysPressed() & DPAD_DOWN) {
        m4aSongNumStart(101);
        gUnk_02034B40->unk_000++;
        if (gUnk_02034B40->unk_000 > 2) {
            gUnk_02034B40->unk_000 = 0;
        }
    }

    if (GetKeysPressed() & L_BUTTON) {
        if (gUnk_0203AA88 == 1) {
            m4aSongNumStart(105);
        } else {
            v = gUnk_0203AA00;
            v--;
            if (v <= 0) {
                v = gUnk_0203AA88;
            }
            gUnk_02039B58[2] |= v & 15;
        }
    } else if (GetKeysPressed() & R_BUTTON) {
        if (gUnk_0203AA88 == 1) {
            m4aSongNumStart(105);
        } else {
            v = gUnk_0203AA00;
            v++;
            if (v > gUnk_0203AA88) {
                v = 1;
            }
            gUnk_02039B58[2] |= v & 15;
        }
    } else {
        gUnk_02039B58[2] &= 0xFFF0;
    }

    if (GetKeysPressed() & 1) {
        m4aSongNumStart(102);

        switch (gUnk_02034B40->unk_000) {
        case 0:
            if (gUnk_02039828 == 0) {
                gUnk_02039B58[1] = 0x2FCF;
            } else {
                gUnk_02039B58[1] = 0x6AD6;
            }
            gUnk_02034B40->unk_1B4 = 0;
            gUnk_02034B40->unk_228 = 1;
            gUnk_02034B40->unk_229 = func_08065B6C(gUnk_0815A20C, gUnk_02034B40->unk_22C);
            gUnk_02034B40->unk_412 = 65;
            gUnk_02034B40->unk_414 = 124;
            gUnk_02034B40->unk_002 = 9;
            break;
        case 1:
            ModeRequest(&gUnk_09EE2704, 0);
            break;
        case 2:
            gUnk_02034B40->unk_1E0 = 0;
            gUnk_02034B40->unk_1F8 = 1;
            gUnk_02034B40->unk_002 = 7;
            break;
        }
    } else if (GetKeysPressed() & 2) {
        m4aSongNumStart(104);
        gUnk_02034B40->unk_1B4 = 0;
        gUnk_02034B40->unk_002 = 5;
    }
    func_080B0634();
    func_080B1064();
    func_080B06D4();
    func_080B0874();
}
#else
INCLUDE_ASM("mode_sio/func_080AFCD4.s");
#endif

void func_080AFEFC(void) {
    if (GetKeysPressed() & DPAD_LEFT) {
        if (gUnk_02034B40->unk_216 > 1) {
            m4aSongNumStart(101);
            gUnk_02034B40->unk_216--;
        } else {
            m4aSongNumStart(105);
        }
    } else if (GetKeysPressed() & DPAD_RIGHT) {
        if (gUnk_02034B40->unk_216 <= 10) {
            m4aSongNumStart(101);
            gUnk_02034B40->unk_216++;
        } else {
            m4aSongNumStart(105);
        }
    }

    if (gUnk_02039828 == 0) {
        gUnk_0203AA58[0] = gUnk_02034B40->unk_216;
    } else {
        gUnk_0203AA58[1] = gUnk_02034B40->unk_216;
    }

    if (GetKeysPressed() & 3) {
        m4aSongNumStart(104);
        gUnk_02034B40->unk_1E0 = 1;
        gUnk_02034B40->unk_1F8 = 0;
        gUnk_02034B40->unk_002 = 6;
    }
    func_080B0634();
    func_080B1064();
    func_080B06D4();
    func_080B0874();
}

void func_080B0010(void) {
    s8 a = gUnk_0203AAA0[gUnk_0203AA90];
    s8 b = gUnk_0203AAA0[gUnk_0203AA00];

    switch (gUnk_02034B40->unk_410) {
    case 0:
        gUnk_02034B40->unk_006++;
        if (gUnk_02034B40->unk_006 > 1) {
            gUnk_02034B40->unk_006 = 0;

            if (gUnk_02034B40->unk_004 > 31) {
                gUnk_02034B40->unk_004 = 32;
                gUnk_02034B40->unk_410++;
            } else {
                gUnk_02034B40->unk_004 += 8;
                FadePaletteToBlack(gUnk_09EF1318[a].unk_10, (u16*)0x05000000, gUnk_09EF1318[a].unk_14, gUnk_02034B40->unk_004);
            }
        }
        break;
    case 1:
        FadePaletteToBlack(gUnk_09EF1318[b].unk_10, (u16*)0x05000000, gUnk_09EF1318[b].unk_14, 32);
        LoadBgMap(2, gUnk_09EF1318[b].unk_08, gUnk_09EF1318[b].unk_0C);
        RequestDma3Copy(gUnk_09EF1318[b].unk_00, GetBgCharBase(2), 0x2000);
        gUnk_02034B40->unk_410++;
        break;
    case 2:
        RequestDma3Copy((u8*)gUnk_09EF1318[b].unk_00 + 0x2000, (u8*)GetBgCharBase(2) + 0x2000, gUnk_09EF1318[b].unk_04 - 0x2000);
        gUnk_02034B40->unk_050 = func_08065B6C(gUnk_09EF1318[b].unk_18, gUnk_02034B40->unk_054);
        gUnk_02034B40->unk_417 = b;
        gUnk_02034B40->unk_410++;
        break;
    case 3:
        gUnk_02034B40->unk_006++;
        if (gUnk_02034B40->unk_006 > 1) {
            gUnk_02034B40->unk_006 = 0;

            if (gUnk_02034B40->unk_004 <= 0) {
                gUnk_02034B40->unk_004 = 0;
                func_080B13D0();
                gUnk_02034B40->unk_410++;
            } else {
                gUnk_02034B40->unk_004 -= 8;
                if (gUnk_02034B40->unk_004 == 0) {
                    LoadPaletteWithEffect(gUnk_09EF1318[b].unk_10, (u16*)0x05000000, gUnk_09EF1318[b].unk_14);
                } else {
                    FadePaletteToBlack(gUnk_09EF1318[b].unk_10, (u16*)0x05000000, gUnk_09EF1318[b].unk_14, gUnk_02034B40->unk_004);
                }
            }
        }
        break;
    default:
        gUnk_02034B40->unk_002 = gUnk_02034B40->unk_001;
        break;
    }
    func_080B0634();
    func_080B1064();
    func_080B0874();
}

#ifndef VERSION_JP
void func_080B01FC(void) {
    if (gUnk_02039828 == 0) {
        gUnk_02039B58[1] = 0x2FCF;
    } else {
        gUnk_02039B58[1] = 0x6AD6;
    }

    if (gUnk_02034B40->unk_217 == 1 && gUnk_02034B40->unk_218 == 1) {
        gUnk_02034B40->unk_006 = 0;
        gUnk_02034B40->unk_229 = func_08065B6C(gUnk_0815A23C, gUnk_02034B40->unk_22C);
        gUnk_02034B40->unk_412 = 68;
        gUnk_02034B40->unk_414 = 119;
        gUnk_02034B40->unk_002++;
    }
    func_080B0634();
    func_080B1064();
    func_080B06D4();
    func_080B0874();
}
#else
INCLUDE_ASM("mode_sio/func_080B01FC.s");
#endif

#ifndef VERSION_JP
void func_080B02A4(void) {
    if (GetKeysPressed() & 1) {
        gUnk_02039B58[1] = 0xA926;
    } else if (GetKeysPressed() & 2) {
        gUnk_02039B58[1] = 0xDD42;
    }

    if (gUnk_02039810[1][0] == 0xA926 || gUnk_02039810[1][1] == 0xA926) {
        m4aSongNumStart(106);
        gUnk_02034B40->unk_006 = 0;
        gUnk_02034B40->unk_229 = func_08065B6C(gUnk_0815B3D4, gUnk_02034B40->unk_22C);
        gUnk_02034B40->unk_412 = 72;
        gUnk_02034B40->unk_414 = 124;
        gUnk_02034B40->unk_002++;
    } else if (gUnk_02039810[1][0] == 0xDD42 || gUnk_02039810[1][1] == 0xDD42) {
        gUnk_02034B40->unk_416 = 10;
        m4aSongNumStart(104);
        gUnk_02034B40->unk_006 = 0;
        func_080B1364();
        gUnk_02034B40->unk_002 = 5;
    }
}
#else
INCLUDE_ASM("mode_sio/func_080B02A4.s");
#endif

void func_080B0380(void) {
    gUnk_02034B40->unk_006++;
    if (gUnk_02034B40->unk_006 > 9) {
        func_080C5DC0(func_080C6008, func_080C60D8);
        func_080C5F94();
        gUnk_02034B40->unk_002++;
    }
}

void func_080B03BC(void) {
    if (gUnk_02039B60 == 2) {
        gUnk_02034B40->unk_006 = 0;
        gUnk_02034B40->unk_002++;
    }
}

void func_080B03DC(void) {
    gUnk_02034B40->unk_006++;
    if (gUnk_02034B40->unk_006 > 4) {
        gUnk_02034B40->unk_006 = 0;
        func_080C5DC0(func_080C5D50, func_080C5D80);
        func_080C5D00();
        gUnk_02034B40->unk_002++;
    }
}

void func_080B041C(void) {
    gUnk_02034B40->unk_006++;
    if (gUnk_02034B40->unk_006 > 30) {
        gUnk_02034B40->unk_006 = 0;
        gUnk_02034B40->unk_002++;
    }
}

void func_080B0440(void) {
    gUnk_02034B40->unk_006++;
    if (gUnk_02034B40->unk_006 > 20) {
        gUnk_02039B58[1] = 0x7CD2;

        if (gUnk_02039810[1][0] == 0x7CD2 && gUnk_02039810[1][1] == 0x7CD2) {
            gUnk_02034B40->unk_006 = 0;
            gUnk_03006C78 &= 0xFFEF;
            gUnk_02034B40->unk_002++;
        }
    }
}

void func_080B0494(void) {
    gUnk_02034B40->unk_006++;
    if (gUnk_02034B40->unk_006 > 4) {
        gUnk_02034B40->unk_006 = 0;
        func_080C5DC0(func_080C5E58, func_080C5ECC);
        func_080B0F18();

        if (gUnk_02039828 == 0) {
            ModeRequest(&gUnk_09ED9B98, 0);
        } else {
            ModeRequest(&gUnk_09ED9B98, 1);
        }
    }
}

void mode_sio_btl_option_2(void) {
    ReleaseObjTiles(gUnk_02034B40->unk_008[0]);
    ReleaseObjPalette(gUnk_02034B40->unk_008[2]);
    ReleaseObjTiles(gUnk_02034B40->unk_008[1]);
    ReleaseObjPalette(gUnk_02034B40->unk_008[3]);
    ReleaseObjPalette(gUnk_02034B40->unk_0F4);
    ReleaseObjPalette(gUnk_02034B40->unk_14C);
    ReleaseObjPalette(gUnk_02034B40->unk_1A4);
    ReleaseObjPalette(gUnk_02034B40->unk_40C);
    func_08065AE0(gUnk_02034B40->unk_054, 20);
    func_08065AE0(gUnk_02034B40->unk_0FC, 10);
    func_08065AE0(gUnk_02034B40->unk_154, 10);
    func_08065AE0(gUnk_02034B40->unk_22C, 60);
    ReleaseObjTiles(gUnk_02034B40->unk_1A8);
    ReleaseObjPalette(gUnk_02034B40->unk_1AC);
    ReleaseObjTiles(gUnk_02034B40->unk_1B8);
    ReleaseObjPalette(gUnk_02034B40->unk_1BC);
    ReleaseObjTiles(gUnk_02034B40->unk_21C);
    ReleaseObjPalette(gUnk_02034B40->unk_220);
    ReleaseObjTiles(gUnk_02034B40->unk_1E4);
    ReleaseObjPalette(gUnk_02034B40->unk_1E8);
    ReleaseObjTiles(gUnk_02034B40->unk_1FC[0]);
    ReleaseObjPalette(gUnk_02034B40->unk_20C[0]);
    ReleaseObjTiles(gUnk_02034B40->unk_1FC[1]);
    ReleaseObjPalette(gUnk_02034B40->unk_20C[1]);
    EwramFree(gUnk_02034B40);
}

void func_080B0634(void) {
    if (gUnk_02039810[1][0] == 0x2FCF) {
        RequestDma3Copy(gUnk_096B2724, (void*)0x06000020, 0xC0);

        if (gUnk_02034B40->unk_217 == 0) {
            func_080AEED8(0, 1, 1);
        }
        gUnk_02034B40->unk_217 = 1;
    }

    if (gUnk_02039810[1][1] == 0x6AD6) {
        RequestDma3Copy(gUnk_096B2B24, (void*)0x06000300, 0xC0);

        if (gUnk_02034B40->unk_218 == 0) {
            func_080AEED8(1, 1, 1);
        }
        gUnk_02034B40->unk_218 = 1;
    }
}

void func_080B06D4(void) {
    s8 x = gUnk_02039810[2][0] & 15;
    s8 y = gUnk_02039810[2][1] & 15;
    if (x != 0 || y != 0) {
        if (x <= 12 && y <= 12) {
            gUnk_0203AA90 = gUnk_0203AA00;

            if (x > y) {
                gUnk_0203AA00 = x;
            } else if (x < y) {
                gUnk_0203AA00 = y;
            } else {
                gUnk_0203AA00 = x;
            }
            gUnk_02034B40->unk_006 = 0;
            gUnk_02034B40->unk_004 = 0;
            gUnk_02034B40->unk_410 = 0;
            gUnk_02034B40->unk_001 = gUnk_02034B40->unk_002;
            gUnk_02034B40->unk_002 = 8;
            m4aSongNumStart(103);
        }
    }
}

void func_080B0754(void) {
    u8 buf[2];
    s8 x;
    s8 y;
    s32 i;
    buf[0] = (gUnk_02039810[2][0] & 0xF0) >> 4;
    buf[1] = (gUnk_02039810[2][1] & 0xF0) >> 4;

    if (buf[0] >= 1 && buf[0] <= 11) {
        gUnk_0203AA58[0] = buf[0];
    }

    if (buf[1] >= 1 && buf[1] <= 11) {
        gUnk_0203AA58[1] = buf[1];
    }

    if ((gUnk_02039810[2][0] >> 12) != 0) {
        u16 n = (gUnk_02039810[2][0] >> 12) - 1;
        gUnk_0203AAE0[0][n * 2] = gUnk_02039810[3][0];
        gUnk_0203AAE0[0][n * 2 + 1] = gUnk_02039810[3][0] >> 8;

        if (n == 9) {
            for (i = 0; i < 20; i++) {
                gUnk_0203AA60[0][i] = gUnk_0203AAE0[0][i];
            }
        }
    }

    if ((gUnk_02039810[2][1] >> 12) != 0) {
        u16 n = (gUnk_02039810[2][1] >> 12) - 1;
        gUnk_0203AAE0[1][n * 2] = gUnk_02039810[3][1];
        gUnk_0203AAE0[1][n * 2 + 1] = gUnk_02039810[3][1] >> 8;

        if (n == 9) {
            for (i = 0; i < 20; i++) {
                gUnk_0203AA60[1][i] = gUnk_0203AAE0[1][i];
            }
        }
    }
    x = gUnk_02039810[2][0] & 15;
    y = gUnk_02039810[2][1] & 15;
    if (x != 0 || y != 0) {
        if (x <= 12 && y <= 12) {
            if (x > y) {
                gUnk_0203AA00 = x;
            } else if (x < y) {
                gUnk_0203AA00 = y;
            } else {
                gUnk_0203AA00 = x;
            }
        }
    }
}

void func_080B0874(void) {
    s32 deck = GetActiveDeckIndex();
    s32 i;
    gUnk_02039B58[2] |= (gUnk_0203AA8C & 15) << 12;
    gUnk_02039B58[3] = gDecks[deck].unk_C6[(gUnk_0203AA8C - 1) * 2] | (gDecks[deck].unk_C6[(gUnk_0203AA8C - 1) * 2 + 1] << 8);
    gUnk_0203AA8C++;
    if (gUnk_0203AA8C > 10) {
        gUnk_0203AA8C = 1;
    }

    if ((gUnk_02039810[2][0] >> 12) != 0) {
        u16 n = (gUnk_02039810[2][0] >> 12) - 1;
        gUnk_0203AAE0[0][n * 2] = gUnk_02039810[3][0];
        gUnk_0203AAE0[0][n * 2 + 1] = gUnk_02039810[3][0] >> 8;

        if (n == 9) {
            for (i = 0; i < 20; i++) {
                gUnk_0203AA60[0][i] = gUnk_0203AAE0[0][i];
                gUnk_0203AA30[0][i] = gUnk_0203AA60[0][i];
            }
            gUnk_02034B40->unk_0F8 = func_08065B6C(gUnk_0203AA30[0], gUnk_02034B40->unk_0FC);
        }
    }

    if ((gUnk_02039810[2][1] >> 12) != 0) {
        u16 n = (gUnk_02039810[2][1] >> 12) - 1;
        gUnk_0203AAE0[1][n * 2] = gUnk_02039810[3][1];
        gUnk_0203AAE0[1][n * 2 + 1] = gUnk_02039810[3][1] >> 8;

        if (n == 9) {
            for (i = 0; i < 20; i++) {
                gUnk_0203AA60[1][i] = gUnk_0203AAE0[1][i];
                gUnk_0203AA30[1][i] = gUnk_0203AA60[1][i];
            }
            gUnk_02034B40->unk_150 = func_08065B6C(gUnk_0203AA30[1], gUnk_02034B40->unk_154);
        }
    }
}

INCLUDE_ASM("mode_sio/func_080B09C0.s");
INCLUDE_ASM("mode_sio/func_080B0F18.s");

void func_080B1064(void) {
    u8 buf[2];

    if (gUnk_02039828 == 0) {
        gUnk_02039B58[2] |= (gUnk_0203AA58[0] & 15) << 4;
    } else {
        gUnk_02039B58[2] |= (gUnk_0203AA58[1] & 15) << 4;
    }
    buf[0] = (gUnk_02039810[2][0] & 0xF0) >> 4;
    buf[1] = (gUnk_02039810[2][1] & 0xF0) >> 4;

    if (buf[0] >= 1 && buf[0] <= 11) {
        gUnk_02034B40->unk_214[0] = buf[0];
        gUnk_0203AA58[0] = gUnk_02034B40->unk_214[0];
    }

    if (buf[1] >= 1 && buf[1] <= 11) {
        gUnk_02034B40->unk_214[1] = buf[1];
        gUnk_0203AA58[1] = gUnk_02034B40->unk_214[1];
    }
    func_080B1134(gUnk_02034B40->unk_214[0], gUnk_02034B40->unk_214[1]);
}

void func_080B1134(u16 a, u16 b) {
    switch (a) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        LoadPalette(gUnk_096FBD64, (void*)(((ObjPalSlot*)gUnk_02034B40->unk_20C[0])->unk_06 * 32 + 0x05000200), 32);
        LoadPalette(gUnk_096FBD64 + 0x22, (void*)(((ObjPalSlot*)gUnk_02034B40->unk_20C[0])->unk_06 * 32 + 0x05000202), (6 - a) * 2);
        break;
    case 6:
        LoadPalette(gUnk_096FBD64, (void*)(((ObjPalSlot*)gUnk_02034B40->unk_20C[0])->unk_06 * 32 + 0x05000200), 32);
        break;
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        LoadPalette(gUnk_096FBD64, (void*)(((ObjPalSlot*)gUnk_02034B40->unk_20C[0])->unk_06 * 32 + 0x05000200), 32);
        LoadPalette(gUnk_096FBD64 + 0x2C, (void*)(((ObjPalSlot*)gUnk_02034B40->unk_20C[0])->unk_06 * 32 + 0x0500020C), (a - 6) * 2);
        break;
    }

    switch (b) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        LoadPalette(gUnk_096FBDA4, (void*)(((ObjPalSlot*)gUnk_02034B40->unk_20C[1])->unk_06 * 32 + 0x05000200), 32);
        LoadPalette(gUnk_096FBDA4 + 0x22, (void*)(((ObjPalSlot*)gUnk_02034B40->unk_20C[1])->unk_06 * 32 + 0x05000202), (6 - b) * 2);
        break;
    case 6:
        LoadPalette(gUnk_096FBDA4, (void*)(((ObjPalSlot*)gUnk_02034B40->unk_20C[1])->unk_06 * 32 + 0x05000200), 32);
        break;
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        LoadPalette(gUnk_096FBDA4, (void*)(((ObjPalSlot*)gUnk_02034B40->unk_20C[1])->unk_06 * 32 + 0x05000200), 32);
        LoadPalette(gUnk_096FBDA4 + 0x2C, (void*)(((ObjPalSlot*)gUnk_02034B40->unk_20C[1])->unk_06 * 32 + 0x0500020C), (b - 6) * 2);
        break;
    }
}

void func_080B1364(void) {
    gUnk_02034B40->unk_228 = 0;
    RequestDma3Copy(gUnk_096B2664, (void*)0x06000020, 0xC0);
    RequestDma3Copy(gUnk_096B2664 + 0x400, (void*)0x06000300, 0xC0);
    gUnk_02034B40->unk_217 = 0;
    gUnk_02034B40->unk_218 = 0;
    func_080AEED8(0, 0, 0);
    func_080AEED8(1, 0, 0);
}

void func_080B13D0(void) {
    s8 i = gUnk_0203AAA0[gUnk_0203AA00];
    switch (i) {
    case 1:
        m4aSongNumStart(23);
        break;
    case 2:
        m4aSongNumStart(17);
        break;
    case 3:
        m4aSongNumStart(20);
        break;
    case 4:
        m4aSongNumStart(1);
        break;
    case 5:
        m4aSongNumStart(9);
        break;
    case 6:
        m4aSongNumStart(16);
        break;
    case 7:
        m4aSongNumStart(11);
        break;
    case 8:
        m4aSongNumStart(26);
        break;
    case 9:
        m4aSongNumStart(40);
        break;
    case 10:
        m4aSongNumStart(12);
        break;
    case 11:
        m4aSongNumStart(43);
        break;
    case 12:
        m4aSongNumStart(39);
        break;
    }
}

void mode_sio_btl_cardget_0(s32 arg) {
    gUnk_03006C78 |= 0x10;

    if (gUnk_0203C374 == 1) {
        func_080C57A4();
        gUnk_0203C374 = 0;
    }
    gUnk_02034B44 = EwramAlloc(sizeof(SioBtlCardgetWork));

    if (arg == 0) {
        gUnk_02034B44->unk_06 = 0;
    } else {
        gUnk_02034B44->unk_06 = 1;
    }
    func_08004DB0();
    SetupBg(1, 0, 16, 0);
    SetBgPriority(1, 1);
    SetupBg(2, 0, 24, 0);
    SetBgPriority(2, 2);
    RequestDma3Copy(gUnk_096AD744, GetBgCharBase(1), 0x2000);
    gUnk_02034B44->unk_00 = 0;
}

void func_080B1534(void) {
    RequestDma3Copy(gUnk_096AF744, (u8*)GetBgCharBase(1) + 0x2000, 0x2000);
}

void func_080B1558(void) {
    RequestDma3Copy(gUnk_096B1744, (u8*)GetBgCharBase(1) + 0x4000, 0x9E0);
    LoadBgPalette(1, gUnk_096FBAC4, 0x200);
    LoadBgMap(1, gUnk_096F7C64, 0x800);
    DisableBg(1);
}

void func_080B15A4(void) {
    func_08006120(0, 16);
    DisableBg(0);
    EnableBg(1);
    EnableBg(2);
    DisableBg(3);

    if (gUnk_02034B44->unk_06 == 0) {
        gUnk_0203A9EC++;
        if (gUnk_0203A9EC > 0x270F) {
            gUnk_0203A9EC = 0x270F;
        }

        if (gUnk_02039828 == 0) {
            func_080B18C4();
            gUnk_02034B44->unk_10 = LoadObjPalette(gUnk_08F683A4, 32);
            gUnk_02034B44->unk_14 = LoadObjPalette(gUnk_096FAC64, 32);
        } else {
            func_080B1974();
            gUnk_02034B44->unk_10 = LoadObjPalette(gUnk_096FAC64, 32);
            gUnk_02034B44->unk_14 = LoadObjPalette(gUnk_08F683A4, 32);
        }
    } else {
        gUnk_0203A9F0++;
        if (gUnk_0203A9F0 > 0x270F) {
            gUnk_0203A9F0 = 0x270F;
        }

        if (gUnk_02039828 == 0) {
            func_080B1974();
            gUnk_02034B44->unk_10 = LoadObjPalette(gUnk_08F683A4, 32);
            gUnk_02034B44->unk_14 = LoadObjPalette(gUnk_096FAC64, 32);
        } else {
            func_080B18C4();
            gUnk_02034B44->unk_10 = LoadObjPalette(gUnk_096FAC64, 32);
            gUnk_02034B44->unk_14 = LoadObjPalette(gUnk_08F683A4, 32);
        }
    }

    if (gUnk_02039828 == 0) {
        gUnk_02034B44->unk_20 = 0x3C00;
        gUnk_02034B44->unk_24 = 0x6000;
    } else {
        gUnk_02034B44->unk_20 = 0xB400;
        gUnk_02034B44->unk_24 = 0x6000;
    }
    gUnk_02034B44->unk_02 = 0;
    gUnk_02034B44->unk_04 = 0;
    gUnk_02039BB0.unk_32 = gUnk_0203AAC0.unk_00;
    gUnk_02039BB0.unk_0C = gUnk_0203AAB0;
}

void mode_sio_btl_cardget_1(void) {
    switch (gUnk_02034B44->unk_00) {
    case 0:
        func_080B1534();
        gUnk_02034B44->unk_00++;
        break;
    case 1:
        func_080B1558();
        gUnk_02034B44->unk_00++;
        break;
    case 2:
        func_080B15A4();
        gUnk_02034B44->unk_00++;
        break;
    case 3:
        gUnk_02034B44->unk_04++;
        if (gUnk_02034B44->unk_04 > 4) {
            gUnk_02034B44->unk_04 = 0;
            func_080C5DC0(func_080C5D50, func_080C5D80);
            func_080C5D00();
            gUnk_02034B44->unk_00++;
        }
        func_080B1848();
        break;
    case 4:
        gUnk_02034B44->unk_04++;
        if (gUnk_02034B44->unk_04 > 4) {
            gUnk_02034B44->unk_04 = 0;
            gUnk_02034B44->unk_00++;
        }
        func_080B1848();
        break;
    case 5:
        if (GetKeysPressed() & (A_BUTTON | B_BUTTON | START_BUTTON)) {
            gUnk_02039B58[1] = 0x45FC;
        }

        if (gUnk_02039810[1][0] == 0x45FC || gUnk_02039810[1][1] == 0x45FC) {
            m4aSongNumStart(106);
            gUnk_02034B44->unk_04 = 0;
            gUnk_02034B44->unk_00++;
        }
        func_080B1848();
        break;
    case 6:
        gUnk_02034B44->unk_04++;
        if (gUnk_02034B44->unk_04 > 4) {
            func_080C5DC0(func_080C6008, func_080C60D8);
            func_080C61D4();
            gUnk_02034B44->unk_00++;
        }
        func_080B1848();
        break;
    case 7:
        if (gUnk_02039B60 == 2) {
            gUnk_02034B44->unk_04 = 0;
            gUnk_02034B44->unk_00++;
        }
        func_080B1848();
        break;
    case 8:
        gUnk_02034B44->unk_04++;
        if (gUnk_02034B44->unk_04 > 4) {
            func_080C5DC0(func_080C5D50, func_080C5D80);
            func_080C5D00();
            gUnk_02034B44->unk_00++;
        }
        func_080B1848();
        break;
    case 9:
        ModeRequestHeapReset(&gUnk_09EF14DC, 0);
        gUnk_02034B44->unk_00++;
        break;
    }
}

void mode_sio_btl_cardget_2(void) {
}

#ifndef VERSION_JP
void func_080B1848(void) {
    DrawSprite(60, 116, gUnk_02034B44->unk_18, gUnk_02034B44->unk_08, gUnk_02034B44->unk_10, 0, 0, 0xFFF0);
    DrawSprite(180, 116, gUnk_02034B44->unk_1C, gUnk_02034B44->unk_0C, gUnk_02034B44->unk_14, 0, 0, 0xFFF0);
    DrawSprite(13, 36, gUnk_02034B44->unk_38, gUnk_02034B44->unk_28, gUnk_02034B44->unk_30, 0, 0, 0xFF00);
    DrawSprite(135, 36, gUnk_02034B44->unk_3C, gUnk_02034B44->unk_2C, gUnk_02034B44->unk_34, 0, 0, 0xFF00);
}
#else
INCLUDE_ASM("mode_sio/func_080B1848.s");
#endif

#ifndef VERSION_JP
void func_080B18C4(void) {
    LoadBgMap(2, gUnk_096F8C64, 0x800);
    gUnk_02034B44->unk_08 = AllocObjTiles(0xC80, gUnk_088B6560);
    gUnk_02034B44->unk_18 = gUnk_09EDE8CC[18];
    gUnk_02034B44->unk_0C = AllocObjTiles(0xC80, gUnk_091CF5D4);
    gUnk_02034B44->unk_1C = gUnk_09EEE4C8[6];
    gUnk_02034B44->unk_28 = LoadObjTiles(gUnk_0962CAFC, 0x680);
    gUnk_02034B44->unk_30 = LoadObjPalette(gUnk_096FBDE4, 32);
    gUnk_02034B44->unk_38 = gUnk_09EF38DC[0];
    gUnk_02034B44->unk_2C = LoadObjTiles(gUnk_0962D196, 0x600);
    gUnk_02034B44->unk_34 = LoadObjPalette(gUnk_096FBE04, 32);
    gUnk_02034B44->unk_3C = gUnk_09EF38E4[0];
}
#else
INCLUDE_ASM("mode_sio/func_080B18C4.s");
#endif

#ifndef VERSION_JP
void func_080B1974(void) {
    LoadBgMap(2, gUnk_096F8464, 0x800);
    gUnk_02034B44->unk_08 = AllocObjTiles(0xC80, gUnk_091CF5D4);
    gUnk_02034B44->unk_18 = gUnk_09EEE4C8[6];
    gUnk_02034B44->unk_0C = AllocObjTiles(0xC80, gUnk_088B6560);
    gUnk_02034B44->unk_1C = gUnk_09EDE8CC[18];
    gUnk_02034B44->unk_28 = LoadObjTiles(gUnk_0962D196, 0x600);
    gUnk_02034B44->unk_30 = LoadObjPalette(gUnk_096FBE04, 32);
    gUnk_02034B44->unk_38 = gUnk_09EF38E4[0];
    gUnk_02034B44->unk_2C = LoadObjTiles(gUnk_0962CAFC, 0x680);
    gUnk_02034B44->unk_34 = LoadObjPalette(gUnk_096FBDE4, 32);
    gUnk_02034B44->unk_3C = gUnk_09EF38DC[0];
}
#else
INCLUDE_ASM("mode_sio/func_080B1974.s");
#endif

void mode_sio_chg_connect_0(s32 arg) {
    gUnk_02034B48 = EwramAlloc(sizeof(SioBtlConnectWork));
    func_08006120(0, 16);
    func_08004DB0();
    SetupBg(0, 0, 7, 15);
    SetupBg(1, 1, 31, 0);
    EnableBg(0);
    EnableBg(1);
    LoadBgTiles(0, gUnk_096AD604, 0x140);
    LoadBgMap(0, gUnk_096F6464, 0x800);
    LoadBgPalette(0, gUnk_09611AB8, 0x20);
    LoadBgTiles(1, gUnk_096ACA44, 0xBC0);
    LoadBgPalette(1, gUnk_096FBA04, 0x40);
    LoadBgMap(1, gUnk_096F5C64, 0x800);
    gUnk_02034B48->unk_00 = 0;
    gUnk_02034B48->unk_02 = 0;
    gUnk_02034B48->unk_04 = 0;
    gUnk_02034B48->unk_05 = 0;
    func_08065ACC(gUnk_02034B48->unk_08, 0x5A);
    gUnk_02034B48->unk_05 = func_08065B6C(gUnk_08159EC4, gUnk_02034B48->unk_08);
    gUnk_02034B48->unk_2D8 = LoadObjPalette(gUnk_096FBAA4, 32);
    func_08006E60();
    func_080C5A3C(func_080B1BE0, func_080B1BFC, 1);
}

void mode_sio_chg_connect_1(void) {
    switch (gUnk_02034B48->unk_04) {
    case 0:
        func_080C54B4();
        break;
    case 1:
        func_080C54B4();
        gUnk_02034B48->unk_02++;
        if (gUnk_02034B48->unk_02 > 4) {
            func_080C5DC0(func_080C5D50, func_080C5D80);
            func_080C5D00();
            gUnk_03006C78 |= 1;
            gUnk_03006C78 |= 0x10;
            func_080B1C14();
            return;
        }
        break;
    }
    func_080664D8(61, 68, gUnk_02034B48->unk_08, gUnk_02034B48->unk_2D8, 20, gUnk_02034B48->unk_05);
}

void mode_sio_chg_connect_2(void) {
    ReleaseObjPalette(gUnk_02034B48->unk_2D8);
    func_08065AE0(gUnk_02034B48->unk_08, 0x5A);
    EwramFree(gUnk_02034B48);
}

void func_080B1BE0(void) {
    m4aSongNumStart(0x6A);
    gUnk_02034B48->unk_04++;
}

void func_080B1BFC(void) {
    m4aSongNumStart(0x68);
    ModeRequest(&gUnk_09EF12F8, 3);
}

void func_080B1C14(void) {
    s32 i;

    if (gUnk_02039828 == 0) {
        gUnk_0203AB10 = 0;
    } else {
        gUnk_0203AB10 = 5;
    }

    for (i = 0; i < 10; i++) {
        gUnk_0203AB20[i] = 0x800;
    }

    for (i = 0; i < 2; i++) {
        gUnk_0203AB34[i] = 0;
    }
    ModeRequest(&gUnk_09EF15A8, 0x800);
}

void func_080B1C70(u16 a, u16 b, u16 c) {
    SioAnimDef* def = &gUnk_09619444[b];
    func_08005974(&gUnk_02034B4C->unk_020[a], def->unk_0C, c, def->unk_04, def->unk_00);
    func_08002A10(gUnk_02034B4C->unk_008[a], def->unk_08);
}

void mode_sio_chg_card_0(s32 arg) {
    gUnk_02034B4C = EwramAlloc(sizeof(SioChgCardWork));
    func_08004DB0();
    SetupBg(0, 0, 7, 0);
    SetBgPriority(0, 0);
    SetBgOverflow(0, 1);
    SetBgSize(0, 0);
    SetupBg(1, 0, 15, 0);
    SetBgPriority(1, 1);
    SetBgOverflow(1, 1);
    SetBgSize(1, 0);
    SetupBg(2, 0, 24, 0);
    SetBgPriority(2, 2);
    SetBgOverflow(2, 1);
    SetBgSize(2, 0);
    RequestDma3Copy(gUnk_096B2BE4, GetBgCharBase(0), 0x2000);
    DisableBg(0);
    DisableBg(1);
    DisableBg(2);
    gUnk_02034B4C->unk_002 = 0;
    gUnk_02034B4C->unk_004 = 0;
    gUnk_02034B4C->unk_0A4 = 0;
    gUnk_02034B4C->unk_001 = 0;
    gUnk_02034B4C->unk_404 = 0;
    gUnk_02034B4C->unk_BE0 = 0;
    gUnk_02034B4C->unk_202 = arg;
    gUnk_02039B58[3] = ((gUnk_0203AB10 & 15) << 12) | ((arg + 1) & 0x0FFF);
}

void func_080B1DDC(void) {
    RequestDma3Copy(gUnk_096B4BE4, (u8*)GetBgCharBase(0) + 0x2000, 0x11C0);
    LoadBgPalette(0, gUnk_096FBE24, 0xE0);
    LoadBgMap(0, gUnk_096FA464, 0x800);
    DisableBg(0);
    DisableBg(1);
    DisableBg(2);
    gUnk_02039B58[3] = ((gUnk_0203AB10 & 15) << 12) | ((gUnk_02034B4C->unk_202 + 1) & 0x0FFF);
    gUnk_02034B4C->unk_001++;
}

void func_080B1E70(void) {
    s32 i;
    s16 n;
    func_08006120(0, 16);
    LoadBgMap(1, gUnk_096F9C64, 0x800);
    LoadBgMap(2, gUnk_096F9464, 0x800);
    DisableBg(0);
    EnableBg(1);
    EnableBg(2);
    gUnk_02034B4C->unk_076 = gUnk_0203AB10;
    gUnk_02034B4C->unk_07A = gUnk_09EF150C[gUnk_02034B4C->unk_076].unk_00;
    gUnk_02034B4C->unk_07C = gUnk_09EF150C[gUnk_02034B4C->unk_076].unk_02;
    gUnk_02034B4C->unk_078 = gUnk_02034B4C->unk_076;
    gUnk_02034B4C->unk_074 = 1;

    for (i = 0; i < 2; i++) {
        gUnk_02034B4C->unk_008[i] = AllocObjTiles(0xC80, 0);
        AnimInit(&gUnk_02034B4C->unk_020[i], 0, 0);

        if (gUnk_0203AB34[i] == 0) {
            func_080B1C70(i, 0, 0);
        } else {
            func_080B1C70(i, 2, 0);
        }
        gUnk_02034B4C->unk_018[i] = AnimGetGfx(&gUnk_02034B4C->unk_020[i]);
    }

    if (gUnk_02039828 == 0) {
        gUnk_02034B4C->unk_008[2] = LoadObjPalette(gUnk_08F683A4, 32);
        gUnk_02034B4C->unk_008[3] = LoadObjPalette(gUnk_096FAC64, 32);
    } else {
        gUnk_02034B4C->unk_008[2] = LoadObjPalette(gUnk_096FAC64, 32);
        gUnk_02034B4C->unk_008[3] = LoadObjPalette(gUnk_08F683A4, 32);
    }
    gUnk_02034B4C->unk_050 = LoadObjTiles(gUnk_0962DEA8, 0x780);
    gUnk_02034B4C->unk_054 = LoadObjPalette(gUnk_096FBF04, 32);
    AnimInit(&gUnk_02034B4C->unk_05C, gUnk_09EF3920, gUnk_09EF390C);
    AnimStart(&gUnk_02034B4C->unk_05C, 0, 1);
    gUnk_02034B4C->unk_058 = AnimGetGfx(&gUnk_02034B4C->unk_05C);
    gUnk_02034B4C->unk_080 = LoadObjTiles(gUnk_0962B090, 0x1C0);
    gUnk_02034B4C->unk_084 = LoadObjPalette(gUnk_096FBAA4, 32);
    AnimInit(&gUnk_02034B4C->unk_08C, gUnk_09EF38B4, gUnk_09EF3894);
    AnimStart(&gUnk_02034B4C->unk_08C, 0, 1);
    gUnk_02034B4C->unk_088 = AnimGetGfx(&gUnk_02034B4C->unk_08C);

    for (i = 0; i < 10; i++) {
        if (gUnk_0203AB20[i] == 0x800) {
            gUnk_02034B4C->unk_0A5[i] = 0;
            gUnk_02034B4C->unk_0B0[i] = gUnk_09EF150C[i].unk_00 << 8;
            gUnk_02034B4C->unk_0D8[i] = gUnk_09EF150C[i].unk_02 << 8;
            gUnk_02034B4C->unk_100[i] = LoadObjTiles(gCardDefs[0].unk_14, 0x200);
            gUnk_02034B4C->unk_128[i] = LoadObjPalette(gCardDefs[0].unk_18, 32);
            gUnk_02034B4C->unk_150[i] = gCardDefs[0].unk_10;
            gUnk_02034B4C->unk_180[i] = gUnk_09EE981C[0];
            gUnk_02034B4C->unk_1A8[i] = 0x100;
            gUnk_02034B4C->unk_1D0[i] = 0x100;
            gUnk_02034B4C->unk_1F8[i] = 0;
        } else {
            gUnk_02034B4C->unk_0A5[i] = 1;
            gUnk_02034B4C->unk_0B0[i] = gUnk_09EF150C[i].unk_00 << 8;
            gUnk_02034B4C->unk_0D8[i] = gUnk_09EF150C[i].unk_02 << 8;
            n = gUnk_0203AB20[i];
            gUnk_02034B4C->unk_100[i] = LoadObjTiles(gCardDefs[n].unk_14, 0x200);
            gUnk_02034B4C->unk_128[i] = LoadObjPalette(gCardDefs[n].unk_18, 32);
            gUnk_02034B4C->unk_150[i] = gCardDefs[n].unk_10;
            gUnk_02034B4C->unk_180[i] = gUnk_09EE981C[gCardDefs[n].unk_20];
            gUnk_02034B4C->unk_1A8[i] = 0x100;
            gUnk_02034B4C->unk_1D0[i] = 0x100;
            gUnk_02034B4C->unk_1F8[i] = 0;
        }
    }
    gUnk_02034B4C->unk_178 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    gUnk_02034B4C->unk_17C = LoadObjPalette(gUnk_09611AB8, 32);
    gUnk_02034B4C->unk_204 = LoadObjTiles(gUnk_093F8C8E, 0xC00);
    gUnk_02034B4C->unk_208 = gUnk_09EF1278[0];
    gUnk_02034B4C->unk_20C = 0;
    func_08065ACC(gUnk_02034B4C->unk_210, 42);
    gUnk_02034B4C->unk_20D = func_08065B6C(gUnk_0815A394, gUnk_02034B4C->unk_210);
    gUnk_02034B4C->unk_BDC = 68;
    gUnk_02034B4C->unk_BDE = 124;
    func_08065ACC(gUnk_02034B4C->unk_364, 20);
    gUnk_02034B4C->unk_361 = func_08065B6C(gCardDefs[0].unk_0C, gUnk_02034B4C->unk_364);
    gUnk_02034B4C->unk_360 = 0;
    TaskPoolInit(gUnk_02034B4C->unk_BE4, 11);
    gUnk_02039B58[3] = ((gUnk_0203AB10 & 15) << 12) | ((gUnk_02034B4C->unk_202 + 1) & 0x0FFF);
    gUnk_02034B4C->unk_001++;
}

void mode_sio_chg_card_1(void) {
    switch (gUnk_02034B4C->unk_001) {
    case 0:
        func_080B1DDC();
        break;
    case 1:
        func_080B1E70();
        break;
    case 2:
        func_080B2420();
        func_080B2CD0();
        break;
    case 3:
        func_080B2480();
        func_080B2CD0();
        break;
    case 4:
        func_080B2788();
        func_080B2CD0();
        break;
    case 5:
        func_080B2854();
        func_080B2CD0();
        break;
    case 6:
        func_080B28A8();
        func_080B2CD0();
        break;
    case 7:
        func_080B298C();
        func_080B2CD0();
        break;
    case 8:
        func_080B29BC();
        func_080B2CD0();
        break;
    case 9:
        func_080B29D8();
        func_080B2CD0();
        break;
    case 10:
        func_080B2A5C();
        func_080B2CD0();
        break;
    case 11:
        func_080B2AE8();
        func_080B2CD0();
        break;
    case 12:
        func_080B2B48();
        func_080B2CD0();
        break;
    case 13:
        func_080B2B78();
        func_080B2CD0();
        break;
    }
}

void func_080B2420(void) {
    gUnk_02034B4C->unk_004++;
    if (gUnk_02034B4C->unk_004 > 5) {
        func_080B2FC0();
        func_080B3204();
        gUnk_02034B4C->unk_001++;
    }
    gUnk_02039B58[3] = ((gUnk_0203AB10 & 15) << 12) | ((gUnk_02034B4C->unk_202 + 1) & 0x0FFF);
}

void func_080B2480(void) {
    gUnk_02039B58[2] = (GetKeysPressed() & 0x0FFF) | 0x5000;
    gUnk_02039B58[3] = ((gUnk_0203AB10 & 15) << 12) | ((gUnk_02034B4C->unk_202 + 1) & 0x0FFF);

    if (gUnk_02034B4C->unk_0A4 == 0) {
        func_080B3354();
    } else {
        func_080B3DF8();
        gUnk_02039B58[1] = 0x1AC7;
    }

    if (gUnk_02039810[1][0] == 0x1AC7) {
        if (gUnk_0203AB34[0] == 0) {
            func_080B1C70(0, 1, 0);
            m4aSongNumStart(102);
        }
        RequestDma3Copy(gUnk_096B5FA4, (void*)0x06000020, 0xC0);
        gUnk_0203AB34[0] = 1;
    } else if (gUnk_02039810[1][0] == 0x2B9A) {
        if (gUnk_0203AB34[0] == 1) {
            func_080B1C70(0, 0, 0);
            m4aSongNumStart(104);
            gUnk_02034B4C->unk_20C = 0;
        }
        RequestDma3Copy(gUnk_096B5EE4, (void*)0x06000020, 0xC0);
        gUnk_0203AB34[0] = 0;
    }

    if (gUnk_02039810[1][1] == 0x1AC7) {
        if (gUnk_0203AB34[1] == 0) {
            func_080B1C70(1, 1, 0);
            m4aSongNumStart(102);
        }
        RequestDma3Copy(gUnk_096B63A4, (void*)0x060000E0, 0xC0);
        gUnk_0203AB34[1] = 1;
    } else if (gUnk_02039810[1][1] == 0x2B9A) {
        if (gUnk_0203AB34[1] == 1) {
            func_080B1C70(1, 0, 0);
            m4aSongNumStart(104);
            gUnk_02034B4C->unk_20C = 0;
        }
        RequestDma3Copy(gUnk_096B62E4, (void*)0x060000E0, 0xC0);
        gUnk_0203AB34[1] = 0;
    }

    if (gUnk_0203AB34[0] == 1 && gUnk_0203AB34[1] == 1) {
        gUnk_02034B4C->unk_004 = 0;
        m4aSongNumStart(106);
        gUnk_02034B4C->unk_20D = func_08065B6C(gUnk_0815A3C0, gUnk_02034B4C->unk_210);
        gUnk_02034B4C->unk_BDC = 64;
        gUnk_02034B4C->unk_BDE = 114;
        gUnk_02034B4C->unk_001++;
    }

    if (gUnk_02039810[1][0] == 0xA4CA || gUnk_02039810[1][1] == 0xA4CA) {
        if ((gUnk_02039810[2][0] & 0xF000) == 0x5000 && (gUnk_02039810[2][1] & 0xF000) == 0x5000 && gUnk_02034B4C->unk_BE0 == 0) {
            m4aSongNumStart(104);
            func_080B3DA0();
            func_080C57B4();
            ModeRequest(&gUnk_09EF14FC, 3);
        }
    } else if (gUnk_02039810[1][0] == 0x1D58) {
        gUnk_02034B4C->unk_BE0 = 10;

        if (gUnk_02039828 == 0) {
            m4aSongNumStart(102);
            gUnk_0203AB10 = gUnk_02034B4C->unk_076;
            ModeRequest(&gUnk_09EE8F20, 0);
        }
    } else if (gUnk_02039810[1][1] == 0x1D58) {
        gUnk_02034B4C->unk_BE0 = 10;

        if (gUnk_02039828 == 1) {
            m4aSongNumStart(102);
            gUnk_0203AB10 = gUnk_02034B4C->unk_076;
            ModeRequest(&gUnk_09EE8F20, 0);
        }
    }
    func_080B2FC0();
    func_080B3204();

    if (gUnk_02034B4C->unk_BE0 > 0) {
        gUnk_02034B4C->unk_BE0--;
    }
}

void func_080B2788(void) {
    if (GetKeysPressed() & 1) {
        gUnk_02039B58[1] = 0xEF01;
    } else if (GetKeysPressed() & 2) {
        gUnk_02039B58[1] = 0x58FA;
    }

    if (gUnk_02039810[1][0] == 0xEF01 || gUnk_02039810[1][1] == 0xEF01) {
        gUnk_02034B4C->unk_004 = 0;
        gUnk_02034B4C->unk_20D = func_08065B6C(gUnk_0815A404, gUnk_02034B4C->unk_210);
        gUnk_02034B4C->unk_BDC = 71;
        gUnk_02034B4C->unk_BDE = 124;
        gUnk_02034B4C->unk_001++;
    }

    if (gUnk_02039810[1][0] == 0x58FA || gUnk_02039810[1][1] == 0x58FA) {
        m4aSongNumStart(104);
        gUnk_02034B4C->unk_004 = 0;
        func_080B3A68();
        gUnk_02034B4C->unk_001 = 3;
    }
    func_080B2FC0();
    func_080B3204();
}

void func_080B2854(void) {
    func_080B3C64();
    gUnk_02034B4C->unk_404 = func_080B3D28();
    if (gUnk_02034B4C->unk_404 == 1) {
        gUnk_02039B58[1] = 0xEF23;
    } else {
        gUnk_02039B58[1] = 0x1269;
    }
    gUnk_02034B4C->unk_001++;
}

void func_080B28A8(void) {
    if (gUnk_02034B4C->unk_404 == 1) {
        gUnk_02039B58[1] = 0xEF23;
    } else {
        gUnk_02039B58[1] = 0x1269;
    }

    if (gUnk_02039810[1][0] == 0xEF23 && gUnk_02039810[1][1] == 0xEF23) {
        m4aSongNumStart(106);
        gUnk_02034B4C->unk_004 = 0;
        gUnk_02039BB0.unk_12C = gUnk_02034B4C->unk_BD4;
        gUnk_02034B4C->unk_001 = 8;
    }

    if (gUnk_02039810[1][0] == 0x1269 || gUnk_02039810[1][1] == 0x1269) {
        m4aSongNumStart(105);
        gUnk_02034B4C->unk_20D = func_08065B6C(gUnk_0815A4B6, gUnk_02034B4C->unk_210);
        gUnk_02034B4C->unk_BDC = 63;
        gUnk_02034B4C->unk_BDE = 118;
        func_080B3CC0();
        gUnk_02034B4C->unk_004 = 0;
        gUnk_02034B4C->unk_001 = 7;
    }
}

void func_080B298C(void) {
    if (gUnk_02034B4C->unk_004 > 179) {
        gUnk_02034B4C->unk_004 = 0;
        func_080B3A68();
        gUnk_02034B4C->unk_001 = 3;
    } else {
        gUnk_02034B4C->unk_004++;
    }
}

void func_080B29BC(void) {
    func_080B3B5C();
    gUnk_02034B4C->unk_004 = 0;
    gUnk_02034B4C->unk_001++;
}

void func_080B29D8(void) {
    TaskPoolUpdate(gUnk_02034B4C->unk_BE4);

    if (func_080C5930() == 0) {
        if (gUnk_0203A9E4 == 0) {
            if (gUnk_02039BB0.unk_08 & 0x10) {
                SaveWriteFileLarge(1);
            } else {
                SaveWriteFileLarge(0);
            }
        }
    } else {
        gUnk_03006C78 &= 0xFFFE;
        ModeRequest(&gUnk_09EF15B8, 0);
    }
    gUnk_02034B4C->unk_004 = 0;
    gUnk_02034B4C->unk_001++;
}

void func_080B2A5C(void) {
    TaskPoolUpdate(gUnk_02034B4C->unk_BE4);

    if (gUnk_02034B4C->unk_004 == 80) {
        gUnk_02034B4C->unk_20C = 0;
    }
    gUnk_02034B4C->unk_004++;
    if (gUnk_02034B4C->unk_004 > 199) {
        gUnk_02034B4C->unk_004 = 0;
        gUnk_02034B4C->unk_20C = 1;
        gUnk_02034B4C->unk_20D = func_08065B6C(gUnk_0815A428, gUnk_02034B4C->unk_210);
        gUnk_02034B4C->unk_BDC = 70;
        gUnk_02034B4C->unk_BDE = 119;
        gUnk_02034B4C->unk_001++;
    }
}

void func_080B2AE8(void) {
    gUnk_02034B4C->unk_004++;
    if (gUnk_02034B4C->unk_004 > 119) {
        gUnk_02034B4C->unk_004 = 0;
        gUnk_02034B4C->unk_20D = func_08065B6C(gUnk_0815B3FA, gUnk_02034B4C->unk_210);
        gUnk_02034B4C->unk_BDC = 83;
        gUnk_02034B4C->unk_BDE = 124;
        gUnk_02034B4C->unk_001++;
    }
}

void func_080B2B48(void) {
    gUnk_02034B4C->unk_004++;
    if (gUnk_02034B4C->unk_004 > 119) {
        gUnk_02034B4C->unk_004 = 0;
        gUnk_02034B4C->unk_20C = 0;
        gUnk_02034B4C->unk_001++;
    }
}

void func_080B2B78(void) {
    s32 i;
    gUnk_02039B58[1] = 0x25FD;

    if (gUnk_02039810[1][0] == 0x25FD || gUnk_02039810[1][1] == 0x25FD) {
        if (gUnk_02039828 == 0) {
            gUnk_0203AB10 = 0;
        } else {
            gUnk_0203AB10 = 5;
        }

        for (i = 0; i < 10; i++) {
            gUnk_0203AB20[i] = 0x800;
        }
        gUnk_0203AB34[0] = 0;
        gUnk_0203AB34[1] = 0;
        ModeRequest(&gUnk_09EF15A8, 0x800);
    }
}

void mode_sio_chg_card_2(void) {
    s32 i;
    ReleaseObjTiles(gUnk_02034B4C->unk_008[0]);
    ReleaseObjTiles(gUnk_02034B4C->unk_008[1]);
    ReleaseObjPalette(gUnk_02034B4C->unk_008[2]);
    ReleaseObjPalette(gUnk_02034B4C->unk_008[3]);
    ReleaseObjTiles(gUnk_02034B4C->unk_050);
    ReleaseObjPalette(gUnk_02034B4C->unk_054);
    ReleaseObjTiles(gUnk_02034B4C->unk_080);
    ReleaseObjPalette(gUnk_02034B4C->unk_084);

    for (i = 0; i < 10; i++) {
        ReleaseObjTiles(gUnk_02034B4C->unk_100[i]);
        ReleaseObjPalette(gUnk_02034B4C->unk_128[i]);
    }
    ReleaseObjTiles(gUnk_02034B4C->unk_178);
    ReleaseObjPalette(gUnk_02034B4C->unk_17C);
    ReleaseObjTiles(gUnk_02034B4C->unk_204);
    func_08065AE0(gUnk_02034B4C->unk_210, 42);
    func_08065AE0(gUnk_02034B4C->unk_364, 20);
    TaskPoolDestroy(gUnk_02034B4C->unk_BE4);
    EwramFree(gUnk_02034B4C);
}

void func_080B2CD0(void) {
    s32 i;
    s32 aff;
    gUnk_02034B4C->unk_018[0] = AnimUpdate(&gUnk_02034B4C->unk_020[0]);
    gUnk_02034B4C->unk_018[1] = AnimUpdate(&gUnk_02034B4C->unk_020[1]);
    gUnk_02034B4C->unk_058 = AnimUpdate(&gUnk_02034B4C->unk_05C);
    gUnk_02034B4C->unk_088 = AnimUpdate(&gUnk_02034B4C->unk_08C);
    DrawSprite(72, 72, gUnk_02034B4C->unk_018[0], gUnk_02034B4C->unk_008[0], gUnk_02034B4C->unk_008[2], 0, 0x401, 0xFFFF);
    DrawSprite(168, 72, gUnk_02034B4C->unk_018[1], gUnk_02034B4C->unk_008[1], gUnk_02034B4C->unk_008[3], 0, 0x400, 0xFFFF);

    if (gUnk_02034B4C->unk_074 == 1) {
        DrawSprite(gUnk_02034B4C->unk_07A, gUnk_02034B4C->unk_07C, gUnk_02034B4C->unk_058, gUnk_02034B4C->unk_050, gUnk_02034B4C->unk_054, 0, 0x400, 0xFFC0);
        DrawSprite(gUnk_02034B4C->unk_07A + 2, gUnk_02034B4C->unk_07C - 8, gUnk_02034B4C->unk_088, gUnk_02034B4C->unk_080, gUnk_02034B4C->unk_084, 0, 0x400, 0xFFA0);
    }

    for (i = 0; i < 10; i++) {
        if (gUnk_02034B4C->unk_0A5[i] == 1) {
            aff = AllocObjAffine(gUnk_02034B4C->unk_1F8[i], gUnk_02034B4C->unk_1A8[i], gUnk_02034B4C->unk_1D0[i], 1);
            DrawSprite((gUnk_02034B4C->unk_0B0[i] >> 8) + 16, (gUnk_02034B4C->unk_0D8[i] >> 8) + 20, gUnk_02034B4C->unk_150[i], gUnk_02034B4C->unk_100[i], gUnk_02034B4C->unk_128[i], aff, 0x400, 0xFFF0);

            if (gCardDefs[gUnk_0203AB20[i]].unk_2A != 3) {
                DrawSprite((gUnk_02034B4C->unk_0B0[i] >> 8) + 13, (gUnk_02034B4C->unk_0D8[i] >> 8) + 16, gUnk_02034B4C->unk_180[i], gUnk_02034B4C->unk_178, gUnk_02034B4C->unk_17C, aff, 0x400, 0xFFE0);
            }
        }
    }

    if (gUnk_02034B4C->unk_20C == 1) {
        DrawSprite(120, 131, gUnk_02034B4C->unk_208, gUnk_02034B4C->unk_204, gUnk_02034B4C->unk_17C, 0, 0, 0xFF00);
        func_080664D8(gUnk_02034B4C->unk_BDC, gUnk_02034B4C->unk_BDE, gUnk_02034B4C->unk_210, gUnk_02034B4C->unk_084, 20, gUnk_02034B4C->unk_20D);
    }

    if (gUnk_02034B4C->unk_360 == 1) {
        func_080664D8(58, 27, gUnk_02034B4C->unk_364, gUnk_02034B4C->unk_054, 18, gUnk_02034B4C->unk_361);
        func_080664D8(52, 42, gUnk_02034B4C->unk_210, gUnk_02034B4C->unk_084, 18, gUnk_02034B4C->unk_20D);
    }
}

void func_080B2FC0(void) {
    if (gUnk_02039810[0][0] == 0xACD) {
        func_080B2FEC(gUnk_02039810[3][0]);
    }

    if (gUnk_02039810[0][1] == 0xACD) {
        func_080B2FEC(gUnk_02039810[3][1]);
    }
}

void func_080B2FEC(u16 a) {
    u16 slot;
    s32 i;

    if (a != 0) {
        i = a;
        i = i >> 12;
        slot = (a & 0x0FFF) - 1;
        if (slot == 0x800) {
            gUnk_02034B4C->unk_0A5[i] = 0;
            ReleaseObjTiles(gUnk_02034B4C->unk_100[i]);
            ReleaseObjPalette(gUnk_02034B4C->unk_128[i]);
            gUnk_02034B4C->unk_100[i] = LoadObjTiles(gCardDefs[0].unk_14, 0x200);
            gUnk_02034B4C->unk_128[i] = LoadObjPalette(gCardDefs[0].unk_18, 32);
            gUnk_02034B4C->unk_150[i] = gCardDefs[0].unk_10;
            gUnk_02034B4C->unk_180[i] = gUnk_09EE981C[0];
            gUnk_0203AB20[i] = slot;

            if (gUnk_02034B4C->unk_360 == 1) {
                if (i == gUnk_02034B4C->unk_076) {
                    func_080B3A48();
                }
            }
        } else {
            gUnk_02034B4C->unk_0A5[i] = 1;
            ReleaseObjTiles(gUnk_02034B4C->unk_100[i]);
            ReleaseObjPalette(gUnk_02034B4C->unk_128[i]);
            gUnk_02034B4C->unk_100[i] = LoadObjTiles(gCardDefs[slot].unk_14, 0x200);
            gUnk_02034B4C->unk_128[i] = LoadObjPalette(gCardDefs[slot].unk_18, 32);
            gUnk_02034B4C->unk_150[i] = gCardDefs[slot].unk_10;
            gUnk_02034B4C->unk_180[i] = gUnk_09EE981C[gCardDefs[slot].unk_20];
            gUnk_0203AB20[i] = slot;
        }
    }
}

void func_080B31A0(void) {
    gUnk_02039B58[2] = 0x6000;

    if (gUnk_02039810[0][0] == 0xACD) {
        func_080B31D8(gUnk_02039810[3][0]);
    }

    if (gUnk_02039810[0][1] == 0xACD) {
        func_080B31D8(gUnk_02039810[3][1]);
    }
}

void func_080B31D8(u16 a) {
    u16 slot;
    s32 i;

    if (a != 0) {
        i = a;
        i = i >> 12;
        slot = (a & 0x0FFF) - 1;
        if (slot == 0x800) {
            gUnk_0203AB20[i] = 0x800;
        } else {
            gUnk_0203AB20[i] = slot;
        }
    }
}

INCLUDE_ASM("mode_sio/func_080B3204.s");

void func_080B3354(void) {
    u16 k1;
    u16 k2;
    s16 v;
    k1 = GetKeysPressed();
    k2 = GetKeysPressed();

    if (gUnk_02034B4C->unk_360 == 1) {
        if (GetKeysPressed() & 2) {
            if (gUnk_02034B4C->unk_360 == 1) {
                func_080B3A48();
            }
        }
    } else if (gUnk_02039828 == 0) {
        if (k1 & 0xF0) {
            m4aSongNumStart(101);
        }

        if (k1 & 0x40) {
            gUnk_02034B4C->unk_078 = gUnk_09EF150C[gUnk_02034B4C->unk_076].unk_05;
        } else if (k1 & 0x80) {
            gUnk_02034B4C->unk_078 = gUnk_09EF150C[gUnk_02034B4C->unk_076].unk_06;
        }

        if (k1 & 0x20) {
            gUnk_02034B4C->unk_078 = gUnk_09EF150C[gUnk_02034B4C->unk_076].unk_07;
        } else if (k1 & 0x10) {
            gUnk_02034B4C->unk_078 = gUnk_09EF150C[gUnk_02034B4C->unk_076].unk_08;
        }

        if (gUnk_02034B4C->unk_078 != 11) {
            gUnk_02034B4C->unk_076 = gUnk_02034B4C->unk_078;
        }

        if (k1 & 8) {
            m4aSongNumStart(101);
            gUnk_02034B4C->unk_078 = 10;
            gUnk_02034B4C->unk_076 = 10;
        }
        gUnk_02034B4C->unk_07A = gUnk_09EF150C[gUnk_02034B4C->unk_076].unk_00;
        gUnk_02034B4C->unk_07C = gUnk_09EF150C[gUnk_02034B4C->unk_076].unk_02;
        v = gUnk_09EF150C[gUnk_02034B4C->unk_076].unk_04;

        if (k1 & 1) {
            if (v == 2) {
                if (func_080B3908() == 1) {
                    gUnk_02034B4C->unk_0A4 = 1;
                    gUnk_02034B4C->unk_20D = func_08065B6C(gUnk_0815A394, gUnk_02034B4C->unk_210);
                    gUnk_02034B4C->unk_BDC = 68;
                    gUnk_02034B4C->unk_BDE = 124;
                    gUnk_02034B4C->unk_20C = 1;
                } else {
                    m4aSongNumStart(105);
                }
            } else if (gUnk_0203AB20[gUnk_02034B4C->unk_076] == 0x800) {
                if (v == 0) {
                    gUnk_02039B58[1] = 0x1D58;
                }
            } else if (gUnk_02034B4C->unk_360 == 0) {
                m4aSongNumStart(102);
                func_080B397C();
            }
        } else if (k1 & 2) {
            if (func_080B3958() == 1) {
                gUnk_02039B58[1] = 0xA4CA;
            } else if (v == 0) {
                if (gUnk_0203AB20[gUnk_02034B4C->unk_076] != 0x800) {
                    m4aSongNumStart(104);
                    func_080B38A4();
                }
            }
        }
    } else {
        if (k2 & 0xF0) {
            m4aSongNumStart(101);
        }

        if (k2 & 0x40) {
            gUnk_02034B4C->unk_078 = gUnk_09EF150C[gUnk_02034B4C->unk_076].unk_05;
        } else if (k2 & 0x80) {
            gUnk_02034B4C->unk_078 = gUnk_09EF150C[gUnk_02034B4C->unk_076].unk_06;
        }

        if (k2 & 0x20) {
            gUnk_02034B4C->unk_078 = gUnk_09EF150C[gUnk_02034B4C->unk_076].unk_07;
        } else if (k2 & 0x10) {
            gUnk_02034B4C->unk_078 = gUnk_09EF150C[gUnk_02034B4C->unk_076].unk_08;
        }

        if (gUnk_02034B4C->unk_078 != 10) {
            gUnk_02034B4C->unk_076 = gUnk_02034B4C->unk_078;
        }

        if (k2 & 8) {
            m4aSongNumStart(101);
            gUnk_02034B4C->unk_078 = 11;
            gUnk_02034B4C->unk_076 = 11;
        }
        gUnk_02034B4C->unk_07A = gUnk_09EF150C[gUnk_02034B4C->unk_076].unk_00;
        gUnk_02034B4C->unk_07C = gUnk_09EF150C[gUnk_02034B4C->unk_076].unk_02;
        v = gUnk_09EF150C[gUnk_02034B4C->unk_076].unk_04;

        if (k2 & 1) {
            if (v == 2) {
                if (func_080B3908() == 1) {
                    gUnk_02034B4C->unk_0A4 = 1;
                    gUnk_02034B4C->unk_20D = func_08065B6C(gUnk_0815A394, gUnk_02034B4C->unk_210);
                    gUnk_02034B4C->unk_BDC = 68;
                    gUnk_02034B4C->unk_BDE = 124;
                    gUnk_02034B4C->unk_20C = 1;
                } else {
                    m4aSongNumStart(105);
                }
            } else if (gUnk_0203AB20[gUnk_02034B4C->unk_076] == 0x800) {
                if (v == 1) {
                    gUnk_02039B58[1] = 0x1D58;
                }
            } else if (gUnk_02034B4C->unk_360 == 0) {
                m4aSongNumStart(102);
                func_080B397C();
            }
        } else if (k2 & 2) {
            if (func_080B3958() == 1) {
                gUnk_02039B58[1] = 0xA4CA;
            } else if (v == 1) {
                if (gUnk_0203AB20[gUnk_02034B4C->unk_076] != 0x800) {
                    m4aSongNumStart(104);
                    func_080B38A4();
                }
            }
        }
    }

    if (gUnk_02034B4C->unk_076 == 10) {
        gUnk_02034B4C->unk_074 = 0;

        if (gUnk_03007480 % 10 == 0) {
            RequestDma3Copy(&gUnk_096B5EE4[gUnk_02034B4C->unk_002 * 192], (void*)0x06000020, 0xC0);
            gUnk_02034B4C->unk_002 = 1 - gUnk_02034B4C->unk_002;
        }
    } else if (gUnk_02034B4C->unk_076 == 11) {
        gUnk_02034B4C->unk_074 = 0;

        if (gUnk_03007480 % 10 == 0) {
            RequestDma3Copy(&gUnk_096B62E4[gUnk_02034B4C->unk_002 * 192], (void*)0x060000E0, 0xC0);
            gUnk_02034B4C->unk_002 = 1 - gUnk_02034B4C->unk_002;
        }
    } else {
        gUnk_02034B4C->unk_074 = 1;
        RequestDma3Copy(gUnk_096B5EE4, (void*)0x06000020, 0xC0);
        RequestDma3Copy(gUnk_096B5EE4 + 0x400, (void*)0x060000E0, 0xC0);
    }
}

void func_080B38A4(void) {
    func_08084068(gUnk_0203AB20[gUnk_02034B4C->unk_076]);
    gUnk_0203AB20[gUnk_02034B4C->unk_076] = 0x800;
    gUnk_0203AB10 = gUnk_02034B4C->unk_076;
    gUnk_02034B4C->unk_202 = 0x800;
    gUnk_02039B58[3] = ((gUnk_0203AB10 & 15) << 12) | ((gUnk_02034B4C->unk_202 + 1) & 0x0FFF);
}

s8 func_080B3908(void) {
    s32 i;

    if (gUnk_02039828 == 0) {
        for (i = 0; i < 5; i++) {
            if (gUnk_0203AB20[i] != 0x800) {
                return 1;
            }
        }
    } else {
        for (i = 5; i < 10; i++) {
            if (gUnk_0203AB20[i] != 0x800) {
                return 1;
            }
        }
    }
    return 0;
}

s8 func_080B3958(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        if (gUnk_0203AB20[i] != 0x800) {
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM("mode_sio/func_080B397C.s");

void func_080B3A48(void) {
    DisableBg(0);
    gUnk_02034B4C->unk_360 = 0;
}

INCLUDE_ASM("mode_sio/func_080B3A68.s");

void func_080B3B5C(void) {
    SioCardTaskArg arg;
    s32 i;

    for (i = 0; i < 5; i++) {
        if (gUnk_0203AB20[i] != 0x800) {
            arg.unk_00 = &gUnk_02034B4C->unk_0B0[i];
            arg.unk_04 = &gUnk_02034B4C->unk_0D8[i];
            arg.unk_08 = &gUnk_02034B4C->unk_1A8[i];
            arg.unk_0C = &gUnk_02034B4C->unk_1D0[i];
            arg.unk_10 = &gUnk_02034B4C->unk_1F8[i];
            arg.unk_14 = &gUnk_02034B4C->unk_0A5[i];
            arg.unk_18 = 0xA000;
            arg.unk_1C = 0x800;
            arg.unk_20 = (5 - i) * 20;
            TaskCreate(gUnk_02034B4C->unk_BE4, &gUnk_09EF34C0, &arg);
        }
    }

    for (i = 5; i < 10; i++) {
        if (gUnk_0203AB20[i] != 0x800) {
            arg.unk_00 = &gUnk_02034B4C->unk_0B0[i];
            arg.unk_04 = &gUnk_02034B4C->unk_0D8[i];
            arg.unk_08 = &gUnk_02034B4C->unk_1A8[i];
            arg.unk_0C = &gUnk_02034B4C->unk_1D0[i];
            arg.unk_10 = &gUnk_02034B4C->unk_1F8[i];
            arg.unk_14 = &gUnk_02034B4C->unk_0A5[i];
            arg.unk_18 = 0x4000;
            arg.unk_1C = 0x800;
            arg.unk_20 = (10 - i) * 20 + 10;
            TaskCreate(gUnk_02034B4C->unk_BE4, &gUnk_09EF34C0, &arg);
        }
    }
}

void func_080B3C64(void) {
    u16 i;

    for (i = 0; i <= 0x3E6; i++) {
        gUnk_02034B4C->unk_406[i] = gCardCollection[i];
    }
    gUnk_02034B4C->unk_BD4 = gUnk_02039BB0.unk_12C;
}

void func_080B3CC0(void) {
    u16 i;

    for (i = 0; i <= 0x3E6; i++) {
        gCardCollection[i] = gUnk_02034B4C->unk_406[i];
    }
    gUnk_02039BB0.unk_12C = gUnk_02034B4C->unk_BD4;
}

s16 func_080B3D28(void) {
    s32 i;
    s32 t;

    if (gUnk_02039828 == 0) {
        for (i = 5; i < 10; i++) {
            t = gUnk_0203AB20[i] != 0x800;
            if (t) {
                if (func_08084068(gUnk_0203AB20[i]) == -1) {
                    return 0;
                }
            }
        }
    } else {
        for (i = 0; i < 5; i++) {
            t = gUnk_0203AB20[i] != 0x800;
            if (t) {
                if (func_08084068(gUnk_0203AB20[i]) == -1) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

void func_080B3DA0(void) {
    s32 i;

    if (gUnk_02039828 == 0) {
        for (i = 0; i < 5; i++) {
            if (gUnk_0203AB20[i] != 0x800) {
                func_08084068(gUnk_0203AB20[i]);
            }
        }
    } else {
        for (i = 5; i < 10; i++) {
            if (gUnk_0203AB20[i] != 0x800) {
                func_08084068(gUnk_0203AB20[i]);
            }
        }
    }
}

#ifndef VERSION_JP
void func_080B3DF8(void) {
}
#else
INCLUDE_ASM("mode_sio/func_080B3DF8.s");
#endif

#ifndef VERSION_JP
void mode_sioError_0(s32 arg) {
    gUnk_03006C78 |= 0x20;
    gUnk_02034B50 = EwramAlloc(sizeof(SioErrorWork));
    m4aMPlayAllStop();
    func_08006120(0, 16);
    func_080C57B4();
    func_08004DB0();
    SetupBg(0, 0, 7, 15);
    SetupBg(1, 1, 31, 0);
    SetBgSize(1, 0);
    LoadBgTiles(1, gUnk_096ACA44, 0xBC0);
    LoadBgPalette(1, gUnk_096FBA04, 0x40);
    LoadBgMap(1, gUnk_096F5C64, 0x800);
    EnableBg(0);
    EnableBg(1);
    DisableBg(2);
    DisableBg(3);
    gUnk_02034B50->unk_00 = 0;
    gUnk_02034B50->unk_02 = 0;
    gUnk_02034B50->unk_04 = 0;
    LoadBgTiles(0, gUnk_0950E2F8, 0x140);
    LoadBgMap(0, gUnk_096112B8, 0x800);
    LoadBgPalette(0, gUnk_09611AB8, 32);
    SetBgScroll(0, 0xFFE9, 0xFFD0);
    func_08065ACC(gUnk_02034B50->unk_08, 0x6C);
    gUnk_02034B50->unk_06 = func_08065B6C(gUnk_0815A2BE, gUnk_02034B50->unk_08);
    gUnk_02034B50->unk_368 = LoadObjPalette(gUnk_096FBAA4, 32);
}
#else
INCLUDE_ASM("mode_sio/mode_sioError_0.s");
#endif

#ifndef VERSION_JP
void mode_sioError_1(void) {
    func_080B3F24();
}
#else
INCLUDE_ASM("mode_sio/mode_sioError_1.s");
#endif

#ifndef VERSION_JP
void func_080B3F24(void) {
    func_080664D8(36, 57, gUnk_02034B50->unk_08, gUnk_02034B50->unk_368, 20, gUnk_02034B50->unk_06);
}
#else
INCLUDE_ASM("mode_sio/func_080B3F24.s");
#endif

#ifndef VERSION_JP
void mode_sioError_2(void) {
    ReleaseObjPalette(gUnk_02034B50->unk_368);
    func_08065AE0(gUnk_02034B50->unk_08, 0x6C);
    EwramFree(gUnk_02034B50);
}
#else
INCLUDE_ASM("mode_sio/mode_sioError_2.s");
#endif

#ifndef VERSION_JP
void mode_wLogo_0(s32 arg) {
    gUnk_02034B59 = arg;
    func_080B4154();
}
#else
INCLUDE_ASM("mode_sio/mode_wLogo_0.s");
#endif

#ifndef VERSION_JP
void mode_wLogo_1(void) {
    u8* p;

    switch (gUnk_02034B58) {
    case 0:
        func_080664D8(35, 75, gUnk_02034B60, gUnk_02034C00, 20, gUnk_02034B5B);

        if (GetKeysPressed() & DPAD_LEFT) {
            gUnk_02034B59--;
            if (gUnk_02034B59 < 0) {
                gUnk_02034B59 = 12;
            }
            gUnk_02034B5B = func_08065B6C(gUnk_09EF15C8[gUnk_02034B59], gUnk_02034B60);
        }

        if (GetKeysPressed() & DPAD_RIGHT) {
            gUnk_02034B59++;
            if (gUnk_02034B59 > 12) {
                gUnk_02034B59 = 0;
            }
            p = &gUnk_02034B5B;
            *p = func_08065B6C(gUnk_09EF15C8[gUnk_02034B59], gUnk_02034B60);
        }

        if (GetKeysPressed() & 1) {
            func_08006184(0, 16);
            DisableBg(0);
            DisableBg(1);
            gUnk_02034B58++;
        }

        if (GetKeysPressed() & 2) {
            ModeRequest(&gUnk_09ECEB64, 0);
        }
        break;
    case 1:
        func_080B4210(gUnk_09EF15FC[gUnk_02034B59]);
        gUnk_02034B58++;
        break;
    case 2:
        if (func_08000F48(gUnk_02034C1C)) {
            TaskPoolUpdate(gUnk_02034C08);
            TaskPoolDraw(gUnk_02034C08);
        } else {
            gUnk_02034B58++;
        }
        break;
    case 3:
        gUnk_02034B5A++;
        if (gUnk_02034B5A > 10) {
            ModeRequest(&gUnk_09EF160C, gUnk_02034B59);
        }
        break;
    }
}
#else
INCLUDE_ASM("mode_sio/mode_wLogo_1.s");
#endif

#ifndef VERSION_JP
void mode_wLogo_2(void) {
    func_08065AE0(gUnk_02034B60, 20);
    ReleaseObjPalette(gUnk_02034C00);

    if (gUnk_02034B58 != 0) {
        if (gUnk_02034B58 == 3) {
            TaskPoolDestroy(gUnk_02034C08);
        }
    }
}
#else
INCLUDE_ASM("mode_sio/mode_wLogo_2.s");
#endif

#ifndef VERSION_JP
void func_080B4154(void) {
    u8* p;
    func_08006120(0, 16);
    func_08004DB0();
    SetupBg(1, 2, 31, 0);
    SetBgSize(1, 0);
    LoadBgTiles(1, gUnk_096ACA44, 0xBC0);
    LoadBgPalette(1, gUnk_096FBA04, 0x40);
    LoadBgMap(1, gUnk_096F5464, 0x800);
    DisableBg(0);
    EnableBg(1);
    gUnk_02034B58 = 0;
    gUnk_02034B5A = 0;
    func_08065ACC(gUnk_02034B60, 20);
    p = &gUnk_02034B5B;
    *p = func_08065B6C(gUnk_09EF15C8[gUnk_02034B59], gUnk_02034B60);
    gUnk_02034C00 = LoadObjPalette(gUnk_096FBCC4, 32);
}
#else
INCLUDE_ASM("mode_sio/func_080B4154.s");
#endif

#ifndef VERSION_JP
void func_080B4210(u8 a) {
    func_08006120(0, 16);
    func_08004E64();
    SetupBg(0, 0, 7, 14);
    SetBgPriority(0, 0);
    SetBgOverflow(0, 1);
    SetBgSize(0, 0);
    SetupBg(2, 2, 24, 0);
    SetBgPriority(2, 2);
    SetBgOverflow(2, 1);
    SetBgSize(2, 0x8000);
    TaskPoolInit(gUnk_02034C08, 2);

    switch (a) {
    case 4:
        LoadBgTiles(2, gUnk_08C84824, 0x4000);
        LoadBgPalette(2, gUnk_08F68904, 0xC0);
        LoadBgMap(2, gUnk_08EF2384, 0x1000);
        gUnk_02034C1C = TaskCreate(gUnk_02034C08, &gUnk_09EF185C, 0);
        break;
    case 5:
        LoadBgTiles(2, gUnk_08C8C824, 0x4000);
        LoadBgPalette(2, gUnk_08F68A84, 0x100);
        LoadBgMap(2, gUnk_08EF4384, 0x1000);
        gUnk_02034C1C = TaskCreate(gUnk_02034C08, &gUnk_09EF1634, 0);
        break;
    case 6:
        LoadBgTiles(2, gUnk_08C94824, 0x4000);
        LoadBgPalette(2, gUnk_08F68C84, 0xE0);
        LoadBgMap(2, gUnk_08EF6384, 0x1000);
        gUnk_02034C1C = TaskCreate(gUnk_02034C08, &gUnk_09EF164C, 0);
        break;
    case 2:
        LoadBgTiles(2, gUnk_08C88824, 0x4000);
        LoadBgPalette(2, gUnk_08F689C4, 0xC0);
        LoadBgMap(2, gUnk_08EF3384, 0x1000);
        gUnk_02034C1C = TaskCreate(gUnk_02034C08, &gUnk_09EF1874, 0);
        break;
    case 7:
        LoadBgTiles(2, gUnk_08C98824, 0x3EC0);
        LoadBgPalette(2, gUnk_08F68D64, 0x140);
        LoadBgMap(2, gUnk_08EF7384, 0x1000);
        gUnk_02034C1C = TaskCreate(gUnk_02034C08, &gUnk_09EF188C, 0);
        break;
    case 3:
        LoadBgTiles(2, gUnk_08C7C824, 0x4000);
        LoadBgPalette(2, gUnk_08F686E4, 0xE0);
        LoadBgMap(2, gUnk_08EF0384, 0x1000);
        gUnk_02034C1C = TaskCreate(gUnk_02034C08, &gUnk_09EF18D4, 0);
        break;
    case 8:
        LoadBgTiles(2, gUnk_08CA06E4, 0x4000);
        LoadBgPalette(2, gUnk_08F68FC4, 0xE0);
        LoadBgMap(2, gUnk_08EF9384, 0x1000);
        gUnk_02034C1C = TaskCreate(gUnk_02034C08, &gUnk_09EF18EC, 0);
        break;
    case 9:
        LoadBgTiles(2, gUnk_08C9C6E4, 0x4000);
        LoadBgPalette(2, gUnk_08F68EA4, 0x120);
        LoadBgMap(2, gUnk_08EF8384, 0x1000);
        gUnk_02034C1C = TaskCreate(gUnk_02034C08, &gUnk_09EF1904, 0);
        break;
    case 1:
        LoadBgTiles(2, gUnk_08C90824, 0x4000);
        LoadBgPalette(2, gUnk_08F68B84, 0x100);
        LoadBgMap(2, gUnk_08EF5384, 0x1000);
        gUnk_02034C1C = TaskCreate(gUnk_02034C08, &gUnk_09EF1A5C, 0);
        break;
    case 10:
        LoadBgTiles(2, gUnk_08C78824, 0x4000);
        LoadBgPalette(2, gUnk_08F68624, 0xC0);
        LoadBgMap(2, gUnk_08EEF384, 0x1000);
        gUnk_02034C1C = TaskCreate(gUnk_02034C08, &gUnk_09EF1ABC, 0);
        break;
    case 0:
        LoadBgTiles(2, gUnk_08C84824, 0x4000);
        LoadBgPalette(2, gUnk_08F68904, 0xC0);
        LoadBgMap(2, gUnk_08EF2384, 0x1000);
        gUnk_02034C1C = TaskCreate(gUnk_02034C08, &gUnk_09EF1AD4, 0);
        break;
    case 11:
        LoadBgTiles(2, gUnk_08CA46E4, 0x4000);
        LoadBgPalette(2, gUnk_08F690A4, 0x140);
        LoadBgMap(2, gUnk_08EFA384, 0x1000);
        gUnk_02034C1C = TaskCreate(gUnk_02034C08, &gUnk_09EF1B38, 0);
        break;
    case 12:
        LoadBgTiles(2, gUnk_08CA86E4, 0x4000);
        LoadBgPalette(2, gUnk_08F691E4, 0xE0);
        LoadBgMap(2, gUnk_08EFB384, 0x1000);
        gUnk_02034C1C = TaskCreate(gUnk_02034C08, &gUnk_09EF1C58, 0);
        break;
    }
    func_08005690(2, 0, 256, 256, 0x10000, 0x16800);
}
#else
INCLUDE_ASM("mode_sio/func_080B4210.s");
#endif

#ifndef VERSION_JP
void task_wLogo_0(WLogoTaskWork* work, u8 arg) {
    work->unk_00 = arg;
    work->unk_04 = -0x5A00;
    work->unk_08 = 0;
    TaskPoolInit(gUnk_02034C20, 2);

    switch (work->unk_00) {
    case 4:
        gUnk_02034C34 = TaskCreate(gUnk_02034C20, &gUnk_09EF185C, 0);
        break;
    case 5:
        gUnk_02034C34 = TaskCreate(gUnk_02034C20, &gUnk_09EF1634, 0);
        break;
    case 6:
        gUnk_02034C34 = TaskCreate(gUnk_02034C20, &gUnk_09EF164C, 0);
        break;
    case 2:
        gUnk_02034C34 = TaskCreate(gUnk_02034C20, &gUnk_09EF1874, 0);
        break;
    case 7:
        gUnk_02034C34 = TaskCreate(gUnk_02034C20, &gUnk_09EF188C, 0);
        break;
    case 3:
        gUnk_02034C34 = TaskCreate(gUnk_02034C20, &gUnk_09EF18D4, 0);
        break;
    case 8:
        gUnk_02034C34 = TaskCreate(gUnk_02034C20, &gUnk_09EF18EC, 0);
        break;
    case 1:
        gUnk_02034C34 = TaskCreate(gUnk_02034C20, &gUnk_09EF1A5C, 0);
        break;
    case 9:
        gUnk_02034C34 = TaskCreate(gUnk_02034C20, &gUnk_09EF1904, 0);
        break;
    case 10:
        gUnk_02034C34 = TaskCreate(gUnk_02034C20, &gUnk_09EF1ABC, 0);
        break;
    case 0:
        gUnk_02034C34 = TaskCreate(gUnk_02034C20, &gUnk_09EF1AD4, 0);
        break;
    case 11:
        gUnk_02034C34 = TaskCreate(gUnk_02034C20, &gUnk_09EF1B38, 0);
        break;
    case 12:
        gUnk_02034C34 = TaskCreate(gUnk_02034C20, &gUnk_09EF1C58, 0);
        break;
    default:
        gUnk_02034C34 = TaskCreate(gUnk_02034C20, &gUnk_09EF185C, 0);
        break;
    }

    if (work->unk_00 == 0) {
        func_080CA6A8(0, work->unk_04);
    } else {
        func_080E02A8(0, work->unk_04);
    }
}
#else
INCLUDE_ASM("mode_sio/task_wLogo_0.s");
#endif

#ifndef VERSION_JP
u8 task_wLogo_1(WLogoTaskWork* work) {
    if (work->unk_00 == 0) {
        work->unk_08++;
        if (work->unk_08 <= 314) {
            func_080CA6A8(0, 76);
        }
    } else {
        work->unk_08++;
        if (work->unk_08 <= 314) {
            func_080E02A8(0, 76);
        }
    }

    if (func_08000F48(gUnk_02034C34) != 0) {
        TaskPoolUpdate(gUnk_02034C20);
        TaskPoolDraw(gUnk_02034C20);
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("mode_sio/task_wLogo_1.s");
#endif

#ifndef VERSION_JP
void task_wLogo_2(WLogoTaskWork* work) {
}
#else
INCLUDE_ASM("mode_sio/task_wLogo_2.s");
#endif

#ifndef VERSION_JP
void task_wLogo_3(WLogoTaskWork* work) {
    TaskPoolDestroy(gUnk_02034C20);
    SetBgBlend(0, 0, 16);
}
#else
INCLUDE_ASM("mode_sio/task_wLogo_3.s");
#endif
