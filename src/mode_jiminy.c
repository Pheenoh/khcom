#include "macros.h"
#include "mode_jiminy.h"

JiminyWork* gJiminyWork;

#ifndef VERSION_JP
void mode_jiminy_0(void) {
    s32 i;
    s32 j;
    JiminyEntry* e;

    gJiminyWork = EwramAlloc(0xD40);
    SetBgMode0();
    SetupBg(0, 0, 0x1D, 0);
    SetupBg(1, 0, 0x1E, 0);
    SetupBg(2, 0, 0x1F, 0);
    SetupBg(3, 0, 0x1C, 0x0D);
    SetBgPriority(0, 0);
    SetBgPriority(1, 1);
    SetBgPriority(2, 0);
    SetBgPriority(3, 0);
    LoadBgTiles(1, gUnk_08EE4A64, 0x2E80);
    LoadBgPalette(1, gUnk_08F6DE24, 0x200);
    LoadBgMap(1, gUnk_08F61B84, 0x800);
    LoadBgMap(2, gUnk_08F60B84, 0x800);
    gJiminyWork->unk_004 = LoadObjTiles(gUnk_08C69C9C, 0x880);
    gJiminyWork->unk_008 = LoadObjPalette(gUnk_08F6DD64, 0x20);
    func_080062F4(gJiminyWork->unk_008->unk_06 + 0x10, 1);
    gJiminyWork->unk_00C = LoadObjTiles(gUnk_08C6A88C, 0x40);
    gJiminyWork->unk_010 = LoadObjPalette(gUnk_08F6DDE4, 0x20);
    gJiminyWork->unk_014 = LoadObjPalette(gUnk_08F6DD84, 0x20);
    gJiminyWork->unk_028 = LoadObjTiles(gUnk_08C6A54E, 0x140);
    gJiminyWork->unk_02C = LoadObjPalette(gUnk_08F6DDA4, 0x20);
    gJiminyWork->unk_030 = LoadObjTiles(gUnk_08C6A6B8, 0x1C0);
    gJiminyWork->unk_034 = LoadObjPalette(gUnk_08F6DDC4, 0x20);
    gJiminyWork->unk_04C = -0x8000;
    gJiminyWork->unk_050 = -0x800;
    gJiminyWork->unk_054 = 0xA000;
    gJiminyWork->unk_000 = 0;
    gJiminyWork->unk_048 = 0;
    gJiminyWork->unk_C70 = 0;
    gJiminyWork->unk_C72 = 0;
    gJiminyWork->unk_C74 = 0;

    if (gGameState.flags & 8) {
        gJiminyWork->unk_018 = AllocObjTiles(0x1000, gUnk_0913F0C2);
        gJiminyWork->unk_01C = LoadObjPalette(gUnk_09614D58, 0x20);
        AnimInit(&gJiminyWork->unk_C7C, gUnk_09EED320, gUnk_09EED2BC);
        AnimStart(&gJiminyWork->unk_C7C, 0, 1);
    } else {
        gJiminyWork->unk_018 = AllocObjTiles(0x1000, gUnk_090FDBF4);
        gJiminyWork->unk_01C = LoadObjPalette(gUnk_09614AB8, 0x20);
        AnimInit(&gJiminyWork->unk_C7C, gUnk_09EECAA0, gUnk_09EECA44);
        AnimStart(&gJiminyWork->unk_C7C, 0, 1);
    }

    if (func_08006314() == 0) {
        gJiminyWork->unk_020 = AllocObjTiles(0x200, gUnk_08C6A958);
        gJiminyWork->unk_024 = LoadObjPalette(gUnk_08F6DE04, 0x20);
        AnimInit(&gJiminyWork->unk_C94, gUnk_09EE2678, gUnk_09EE2668);
        AnimStart(&gJiminyWork->unk_C94, 2, 1);
    }

    gJiminyWork->unk_038 = AllocObjTiles(0x2000, 0);
    gJiminyWork->unk_03C = LoadObjPalette(gUnk_09A3CC9C, 0x20);
    gJiminyWork->unk_040 = AllocObjTiles(0x800, 0);
    gJiminyWork->unk_044 = LoadObjPalette(gUnk_09611AB8, 0x20);
    gJiminyWork->unk_D3C = 0;
    gJiminyWork->unk_D38 = 0x100;
    func_08006120(0, 0x10);

    for (i = 0; i < 8; i++) {
        func_08065ACC(&gJiminyWork->unk_060[i], 0x30);
    }

    func_08064B80(0);
    gJiminyWork->unk_C71 = func_08065170(0x200, 0x2400, gUnk_08159FE0);

    for (j = 0; j <= 0x14; j++) {
        gJiminyWork->unk_CD8[j].unk_00 = 0;
        gJiminyWork->unk_CD8[j].unk_02 = 0;
    }

    if (gGameState.flags & 8) {
        gJiminyWork->unk_D2C = 14;
        e = gUnk_08155554;
        e += 14;
        func_0805A95C(3, e->unk_08, e->unk_04, e->unk_10, e->unk_0C, 0x80, 0x40, 0x18);
        gJiminyWork->unk_CAC = 2;
    } else {
        gJiminyWork->unk_D2C = 0;
        e = gUnk_08155554;
        func_0805A95C(3, e->unk_08, e->unk_04, e->unk_10, e->unk_0C, 0x80, 0x40, 0x18);
        gJiminyWork->unk_CAC = 3;
    }
}
#else
INCLUDE_ASM("mode_jiminy/mode_jiminy_0.s");
#endif

#ifndef VERSION_JP
void mode_jiminy_1(void) {
    s32 i;
    u16 c;
    u16 t;
    JiminyEntry* e;
    JiminyPair* p;
    JiminyEntry* e2;
    JiminyPair* p2;

    switch (gJiminyWork->unk_000) {
    case 0:
        if (gJiminyWork->unk_048 == 0) {
            gJiminyWork->unk_04A = 16;
        }
        ApproachValue(&gJiminyWork->unk_050, 0, gJiminyWork->unk_04A);
        ApproachValue(&gJiminyWork->unk_054, 0x9800, gJiminyWork->unk_04A);
        gJiminyWork->unk_04A--;
        if (gJiminyWork->unk_04A <= 0) {
            gJiminyWork->unk_000 = 1;
            gJiminyWork->unk_048 = 0;
        } else {
            gJiminyWork->unk_048++;
        }
        break;
    case 1:
        if (gJiminyWork->unk_048 == 0) {
            gJiminyWork->unk_04A = 16;
        }
        ApproachValue(&gJiminyWork->unk_04C, 0, gJiminyWork->unk_04A);
        gJiminyWork->unk_04A--;
        if (gJiminyWork->unk_04A <= 0) {
            gJiminyWork->unk_000 = 6;
            gJiminyWork->unk_048 = 0;
        } else {
            gJiminyWork->unk_048++;
        }
        break;
    case 2:
        if (gJiminyWork->unk_048 == 0) {
            c = gJiminyWork->unk_CAC | 2;
            gJiminyWork->unk_CAC = c & 0xFFFB;
            gJiminyWork->unk_04A = 16;
            LoadBgMap(1, gUnk_08F61B84, 0x800);
        }
        ApproachValue(&gJiminyWork->unk_04C, -0x8000, gJiminyWork->unk_04A);
        gJiminyWork->unk_04A--;
        if (gJiminyWork->unk_04A <= 0) {
            gJiminyWork->unk_000 = 3;
            gJiminyWork->unk_048 = 0;
        } else {
            gJiminyWork->unk_048++;
        }
        break;
    case 3:
        if (gJiminyWork->unk_048 == 0) {
            gJiminyWork->unk_04A = 16;
        }
        ApproachValue(&gJiminyWork->unk_050, -0x800, gJiminyWork->unk_04A);
        ApproachValue(&gJiminyWork->unk_054, 0xA000, gJiminyWork->unk_04A);
        gJiminyWork->unk_04A--;
        if (gJiminyWork->unk_04A <= 0) {
            gJiminyWork->unk_000 = 4;
            gJiminyWork->unk_048 = 0;
        } else {
            gJiminyWork->unk_048++;
        }
        break;
    case 4:
        if (gJiminyWork->unk_048 == 0) {
            func_08006184(0, 16);
            func_080063A8();
        }

        if (func_08006390() > 30) {
            func_080E052C(1);
        }
        break;
    case 5:
        if (gJiminyWork->unk_048 == 0) {
            func_08006184(0, 16);
            func_080063A8();
        }

        if (func_08006390() > 30) {
            func_080E052C(0);
        }
        break;
    case 6:
        e = &gUnk_08155554[gJiminyWork->unk_D2C];
        p = &gJiminyWork->unk_CD8[gJiminyWork->unk_D2C];
        gJiminyWork->unk_C71 = func_08065170(0x200, 0x2400, gUnk_08159FE0);
        DisableBg(3);
        DisableBg(0);
        gJiminyWork->unk_C72 = p->unk_00;
        gJiminyWork->unk_C74 = p->unk_02;

        if (gJiminyWork->unk_D2C == 0 || gJiminyWork->unk_D2C == 14) {
            if (gGameState.flags & 8) {
                LoadBgMap(1, gUnk_08F62B84, 0x800);
            } else {
                LoadBgMap(1, e->unk_00, 0x800);
            }
            LoadObjPaletteBank(gJiminyWork->unk_014->unk_06, gUnk_08F6DD84);
            func_0805A95C(3, e->unk_08, e->unk_04, e->unk_10, e->unk_0C, 0x80, 0x40, 0x18);
        } else {
            LoadBgMap(1, e->unk_00, 0x800);
            LoadObjPaletteBank(gJiminyWork->unk_014->unk_06, gUnk_08F6DDC4);
            func_0805A95C(4, e->unk_08, e->unk_04, e->unk_10, e->unk_0C, 0x70, 0x3A, 0x10);
        }

        gJiminyWork->unk_000 = 7;
    case 7:
        e2 = &gUnk_08155554[gJiminyWork->unk_D2C];
        p2 = &gJiminyWork->unk_CD8[gJiminyWork->unk_D2C];

        if (func_0805AA9C() != 0) {
            break;
        }

        p2->unk_00 = gJiminyWork->unk_C72;
        p2->unk_02 = gJiminyWork->unk_C74;

        if (GetKeysPressed() & 2) {
            gJiminyWork->unk_048 = 0;

            if (e2->unk_0A == -1) {
                gJiminyWork->unk_000 = 2;
            } else {
                gJiminyWork->unk_000 = 6;
                gJiminyWork->unk_D2C = e2->unk_0A;
                func_08006120(0, 5);
                func_080063A8();
            }
            m4aSongNumStart(0x68);
            break;
        }

        if (GetKeysPressed() & 1) {
            u32 ok;

            ok = 1;

            if (e2->unk_10 != 0) {
                ok = func_0800FF00(e2->unk_10[gJiminyWork->unk_C72]) != 0;
            } else {
                if (gJiminyWork->unk_C68[gJiminyWork->unk_C74] == 3) {
                    ok = 0;
                }
            }

            if (ok != 0) {
                m4aSongNumStart(0x66);

                if (e2->unk_0C != 0) {
                    gJiminyWork->unk_000 = 6;
                    gJiminyWork->unk_D2C = e2->unk_0C[gJiminyWork->unk_C72];
                    gJiminyWork->unk_048 = 0;
                    func_08006120(0, 5);
                    func_080063A8();
                    break;
                } else {
                    func_08006120(0, 5);
                    func_080063A8();
                    gJiminyWork->unk_048 = 0;
                    gJiminyWork->unk_000 = 8;
                    gJiminyWork->unk_CD2 = gJiminyWork->unk_C72;
                    gJiminyWork->unk_D34 = e2->unk_14;
                    SetModeUpdate(func_0805BAE4);
                    break;
                }
            }
        }

        gJiminyWork->unk_048++;
        break;
    }

    t = abs(gSineTable[(gJiminyWork->unk_D3E * 2) & 0xFF]) * 15 >> 8;
    gBldCnt = 0xF10;
    SetBlendAlpha(t, 16 - t);

    if (gJiminyWork->unk_CAC & 1) {
        EnableBg(2);
        func_080658B8(gJiminyWork->unk_C70);
        DrawSprite(0x23, 0x76, AnimUpdate(&gJiminyWork->unk_C7C), gJiminyWork->unk_018,
            gJiminyWork->unk_01C, 0, 0, 0);
    } else {
        DisableBg(2);
    }

    for (i = 0; gJiminyWork->unk_060[i].unk_000 != 0; i++) {
        if (i >= gJiminyWork->unk_C78) {
            break;
        }
        func_080664D8(gJiminyWork->unk_CAE, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i,
            &gJiminyWork->unk_060[i], gJiminyWork->unk_014, 0, gJiminyWork->unk_C60[i]);

        if (gJiminyWork->unk_000 == 7) {
            switch (gJiminyWork->unk_C68[i]) {
            case 1:
                DrawSprite(0xD9, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i, gUnk_08C6A6A4,
                    gJiminyWork->unk_030, gJiminyWork->unk_034, 0, 4, 0);
                break;
            case 2:
                DrawSprite(0xD9, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i - 2, gUnk_08C6A69A,
                    gJiminyWork->unk_030, gJiminyWork->unk_034, 0, 4, 0);
                break;
            }
        }
    }

    if (gJiminyWork->unk_CAC & 2) {
        if (gGameState.flags & 8) {
            DrawSprite(gJiminyWork->unk_04C >> 8, 0, gUnk_08C69C76, gJiminyWork->unk_004,
                gJiminyWork->unk_008, 0, 0, 0);
        } else {
            DrawSprite(gJiminyWork->unk_04C >> 8, 0, gUnk_08C69C04, gJiminyWork->unk_004,
                gJiminyWork->unk_008, 0, 0, 0);
        }
        DrawSprite(0x58, 0x98, gUnk_08C6A878, gJiminyWork->unk_00C, gJiminyWork->unk_010, 0, 0, 0);
        DrawSprite(0x80, gJiminyWork->unk_050 >> 8, gUnk_08C69C20, gJiminyWork->unk_004,
            gJiminyWork->unk_008, 0, 0, 1);
        DrawSprite(0x80, gJiminyWork->unk_054 >> 8, gUnk_08C69C54, gJiminyWork->unk_004,
            gJiminyWork->unk_008, 0, 0, 1);
    }

    if (gJiminyWork->unk_000 == 7) {
        if (gJiminyWork->unk_CAC & 8) {
            DrawSprite(gJiminyWork->unk_CC2, gJiminyWork->unk_CC4 - ((gJiminyWork->unk_D3E >> 3) & 3),
                gUnk_08C6A51C, gJiminyWork->unk_028, gJiminyWork->unk_02C, 0, 0, 0);
        }

        if (gJiminyWork->unk_CAC & 0x10) {
            DrawSprite(gJiminyWork->unk_CC6, gJiminyWork->unk_CC8 + ((gJiminyWork->unk_D3E >> 3) & 3),
                gUnk_08C6A526, gJiminyWork->unk_028, gJiminyWork->unk_02C, 0, 0, 0);
        }

        if (func_08006314() == 0) {
            if (gJiminyWork->unk_CAC & 4) {
                if (gJiminyWork->unk_CC0 <= 0) {
                    DrawSprite(gJiminyWork->unk_058 >> 8, gJiminyWork->unk_05C >> 8,
                        AnimUpdate(&gJiminyWork->unk_C94), gJiminyWork->unk_020,
                        gJiminyWork->unk_024, 0, 0, 0);
                } else {
                    DrawSprite(gJiminyWork->unk_058 >> 8, gJiminyWork->unk_05C >> 8, gUnk_08C6A8F8,
                        gJiminyWork->unk_020, gJiminyWork->unk_024, 0, 0, 0);

                    if (gJiminyWork->unk_CC0 == 1) {
                        AnimReset(&gJiminyWork->unk_C94);
                    }
                }
            }
        }
    }

    UpdatePlayTime();
    gJiminyWork->unk_D3E++;
}
#else
INCLUDE_ASM("mode_jiminy/mode_jiminy_1.s");
#endif

void func_0805B9D0(s16 a, s16 b, s32 c, s16 d, s16 e, s16 f) {
    gJiminyWork->unk_CAE = d;
    gJiminyWork->unk_CB0 = e;
    gJiminyWork->unk_CB2 = f;
    gJiminyWork->unk_C76 = b;
    gJiminyWork->unk_C78 = a;
    gJiminyWork->unk_CB4 = c;
    gJiminyWork->unk_CC2 = d + 0x38;
    gJiminyWork->unk_CC6 = d + 0x38;
    gJiminyWork->unk_CC4 = e - 10;
    gJiminyWork->unk_CC8 = e + f * (a - 1) + 12;
    gJiminyWork->unk_C72 = 0;
    gJiminyWork->unk_C74 = 0;
    gJiminyWork->unk_CC0 = 0;
    gJiminyWork->unk_D3E = 0;
    func_0805A8D0();
}

void func_0805BAAC(s16 a, u8* out) {
    out[0] = a / 100;
    out[1] = a % 100 / 10;
    out[2] = a % 10;
}

INCLUDE_ASM("mode_jiminy/func_0805BAE4.s");

void mode_jiminy_2(void) {
    func_08065940();
    ReleaseObjTiles(gJiminyWork->unk_004);
    ReleaseObjPalette(gJiminyWork->unk_008);
    ReleaseObjTiles(gJiminyWork->unk_00C);
    ReleaseObjPalette(gJiminyWork->unk_010);
    ReleaseObjPalette(gJiminyWork->unk_014);
    ReleaseObjTiles(gJiminyWork->unk_018);
    ReleaseObjPalette(gJiminyWork->unk_01C);
    ReleaseObjTiles(gJiminyWork->unk_020);
    ReleaseObjPalette(gJiminyWork->unk_024);
    ReleaseObjTiles(gJiminyWork->unk_028);
    ReleaseObjPalette(gJiminyWork->unk_02C);
    ReleaseObjTiles(gJiminyWork->unk_030);
    ReleaseObjPalette(gJiminyWork->unk_034);
    ReleaseObjTiles(gJiminyWork->unk_038);
    ReleaseObjPalette(gJiminyWork->unk_03C);
    ReleaseObjTiles(gJiminyWork->unk_040);
    ReleaseObjPalette(gJiminyWork->unk_044);
    func_0805A484();
    EwramFree(gJiminyWork);
}
