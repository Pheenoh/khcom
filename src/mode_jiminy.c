#include "macros.h"
#include "mode_jiminy.h"

#ifndef VERSION_JP
void mode_jiminy_0(void) {
    s32 i;
    s32 j;
    JiminyEntry* e;

    gUnk_02034934 = EwramAlloc(0xD40);
    func_08004DB0();
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
    gUnk_02034934->unk_004 = LoadObjTiles(gUnk_08C69C9C, 0x880);
    gUnk_02034934->unk_008 = LoadObjPalette(gUnk_08F6DD64, 0x20);
    func_080062F4(gUnk_02034934->unk_008->unk_06 + 0x10, 1);
    gUnk_02034934->unk_00C = LoadObjTiles(gUnk_08C6A88C, 0x40);
    gUnk_02034934->unk_010 = LoadObjPalette(gUnk_08F6DDE4, 0x20);
    gUnk_02034934->unk_014 = LoadObjPalette(gUnk_08F6DD84, 0x20);
    gUnk_02034934->unk_028 = LoadObjTiles(gUnk_08C6A54E, 0x140);
    gUnk_02034934->unk_02C = LoadObjPalette(gUnk_08F6DDA4, 0x20);
    gUnk_02034934->unk_030 = LoadObjTiles(gUnk_08C6A6B8, 0x1C0);
    gUnk_02034934->unk_034 = LoadObjPalette(gUnk_08F6DDC4, 0x20);
    gUnk_02034934->unk_04C = -0x8000;
    gUnk_02034934->unk_050 = -0x800;
    gUnk_02034934->unk_054 = 0xA000;
    gUnk_02034934->unk_000 = 0;
    gUnk_02034934->unk_048 = 0;
    gUnk_02034934->unk_C70 = 0;
    gUnk_02034934->unk_C72 = 0;
    gUnk_02034934->unk_C74 = 0;

    if (gUnk_02039BB0.unk_008 & 8) {
        gUnk_02034934->unk_018 = AllocObjTiles(0x1000, gUnk_0913F0C2);
        gUnk_02034934->unk_01C = LoadObjPalette(gUnk_09614D58, 0x20);
        AnimInit(&gUnk_02034934->unk_C7C, gUnk_09EED320, gUnk_09EED2BC);
        AnimStart(&gUnk_02034934->unk_C7C, 0, 1);
    } else {
        gUnk_02034934->unk_018 = AllocObjTiles(0x1000, gUnk_090FDBF4);
        gUnk_02034934->unk_01C = LoadObjPalette(gUnk_09614AB8, 0x20);
        AnimInit(&gUnk_02034934->unk_C7C, gUnk_09EECAA0, gUnk_09EECA44);
        AnimStart(&gUnk_02034934->unk_C7C, 0, 1);
    }

    if (func_08006314() == 0) {
        gUnk_02034934->unk_020 = AllocObjTiles(0x200, gUnk_08C6A958);
        gUnk_02034934->unk_024 = LoadObjPalette(gUnk_08F6DE04, 0x20);
        AnimInit(&gUnk_02034934->unk_C94, gUnk_09EE2678, gUnk_09EE2668);
        AnimStart(&gUnk_02034934->unk_C94, 2, 1);
    }

    gUnk_02034934->unk_038 = AllocObjTiles(0x2000, 0);
    gUnk_02034934->unk_03C = LoadObjPalette(gUnk_09A3CC9C, 0x20);
    gUnk_02034934->unk_040 = AllocObjTiles(0x800, 0);
    gUnk_02034934->unk_044 = LoadObjPalette(gUnk_09611AB8, 0x20);
    gUnk_02034934->unk_D3C = 0;
    gUnk_02034934->unk_D38 = 0x100;
    func_08006120(0, 0x10);

    for (i = 0; i < 8; i++) {
        func_08065ACC(&gUnk_02034934->unk_060[i], 0x30);
    }

    func_08064B80(0);
    gUnk_02034934->unk_C71 = func_08065170(0x200, 0x2400, gUnk_08159FE0);

    for (j = 0; j <= 0x14; j++) {
        gUnk_02034934->unk_CD8[j].unk_00 = 0;
        gUnk_02034934->unk_CD8[j].unk_02 = 0;
    }

    if (gUnk_02039BB0.unk_008 & 8) {
        gUnk_02034934->unk_D2C = 14;
        e = gUnk_08155554;
        e += 14;
        func_0805A95C(3, e->unk_08, e->unk_04, e->unk_10, e->unk_0C, 0x80, 0x40, 0x18);
        gUnk_02034934->unk_CAC = 2;
    } else {
        gUnk_02034934->unk_D2C = 0;
        e = gUnk_08155554;
        func_0805A95C(3, e->unk_08, e->unk_04, e->unk_10, e->unk_0C, 0x80, 0x40, 0x18);
        gUnk_02034934->unk_CAC = 3;
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

    switch (gUnk_02034934->unk_000) {
    case 0:
        if (gUnk_02034934->unk_048 == 0) {
            gUnk_02034934->unk_04A = 16;
        }
        func_080058FC(&gUnk_02034934->unk_050, 0, gUnk_02034934->unk_04A);
        func_080058FC(&gUnk_02034934->unk_054, 0x9800, gUnk_02034934->unk_04A);
        gUnk_02034934->unk_04A--;
        if (gUnk_02034934->unk_04A <= 0) {
            gUnk_02034934->unk_000 = 1;
            gUnk_02034934->unk_048 = 0;
        } else {
            gUnk_02034934->unk_048++;
        }
        break;
    case 1:
        if (gUnk_02034934->unk_048 == 0) {
            gUnk_02034934->unk_04A = 16;
        }
        func_080058FC(&gUnk_02034934->unk_04C, 0, gUnk_02034934->unk_04A);
        gUnk_02034934->unk_04A--;
        if (gUnk_02034934->unk_04A <= 0) {
            gUnk_02034934->unk_000 = 6;
            gUnk_02034934->unk_048 = 0;
        } else {
            gUnk_02034934->unk_048++;
        }
        break;
    case 2:
        if (gUnk_02034934->unk_048 == 0) {
            c = gUnk_02034934->unk_CAC | 2;
            gUnk_02034934->unk_CAC = c & 0xFFFB;
            gUnk_02034934->unk_04A = 16;
            LoadBgMap(1, gUnk_08F61B84, 0x800);
        }
        func_080058FC(&gUnk_02034934->unk_04C, -0x8000, gUnk_02034934->unk_04A);
        gUnk_02034934->unk_04A--;
        if (gUnk_02034934->unk_04A <= 0) {
            gUnk_02034934->unk_000 = 3;
            gUnk_02034934->unk_048 = 0;
        } else {
            gUnk_02034934->unk_048++;
        }
        break;
    case 3:
        if (gUnk_02034934->unk_048 == 0) {
            gUnk_02034934->unk_04A = 16;
        }
        func_080058FC(&gUnk_02034934->unk_050, -0x800, gUnk_02034934->unk_04A);
        func_080058FC(&gUnk_02034934->unk_054, 0xA000, gUnk_02034934->unk_04A);
        gUnk_02034934->unk_04A--;
        if (gUnk_02034934->unk_04A <= 0) {
            gUnk_02034934->unk_000 = 4;
            gUnk_02034934->unk_048 = 0;
        } else {
            gUnk_02034934->unk_048++;
        }
        break;
    case 4:
        if (gUnk_02034934->unk_048 == 0) {
            func_08006184(0, 16);
            func_080063A8();
        }
        if (func_08006390() > 30) {
            func_080E052C(1);
        }
        break;
    case 5:
        if (gUnk_02034934->unk_048 == 0) {
            func_08006184(0, 16);
            func_080063A8();
        }
        if (func_08006390() > 30) {
            func_080E052C(0);
        }
        break;
    case 6:
        e = &gUnk_08155554[gUnk_02034934->unk_D2C];
        p = &gUnk_02034934->unk_CD8[gUnk_02034934->unk_D2C];
        gUnk_02034934->unk_C71 = func_08065170(0x200, 0x2400, gUnk_08159FE0);
        DisableBg(3);
        DisableBg(0);
        gUnk_02034934->unk_C72 = p->unk_00;
        gUnk_02034934->unk_C74 = p->unk_02;

        if (gUnk_02034934->unk_D2C == 0 || gUnk_02034934->unk_D2C == 14) {
            if (gUnk_02039BB0.unk_008 & 8) {
                LoadBgMap(1, gUnk_08F62B84, 0x800);
            } else {
                LoadBgMap(1, e->unk_00, 0x800);
            }
            LoadObjPaletteBank(gUnk_02034934->unk_014->unk_06, gUnk_08F6DD84);
            func_0805A95C(3, e->unk_08, e->unk_04, e->unk_10, e->unk_0C, 0x80, 0x40, 0x18);
        } else {
            LoadBgMap(1, e->unk_00, 0x800);
            LoadObjPaletteBank(gUnk_02034934->unk_014->unk_06, gUnk_08F6DDC4);
            func_0805A95C(4, e->unk_08, e->unk_04, e->unk_10, e->unk_0C, 0x70, 0x3A, 0x10);
        }

        gUnk_02034934->unk_000 = 7;
    case 7:
        e2 = &gUnk_08155554[gUnk_02034934->unk_D2C];
        p2 = &gUnk_02034934->unk_CD8[gUnk_02034934->unk_D2C];

        if (func_0805AA9C() != 0) {
            break;
        }

        p2->unk_00 = gUnk_02034934->unk_C72;
        p2->unk_02 = gUnk_02034934->unk_C74;

        if (GetKeysPressed() & 2) {
            gUnk_02034934->unk_048 = 0;
            if (e2->unk_0A == -1) {
                gUnk_02034934->unk_000 = 2;
            } else {
                gUnk_02034934->unk_000 = 6;
                gUnk_02034934->unk_D2C = e2->unk_0A;
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
                ok = func_0800FF00(e2->unk_10[gUnk_02034934->unk_C72]) != 0;
            } else {
                if (gUnk_02034934->unk_C68[gUnk_02034934->unk_C74] == 3) {
                    ok = 0;
                }
            }

            if (ok != 0) {
                m4aSongNumStart(0x66);
                if (e2->unk_0C != 0) {
                    gUnk_02034934->unk_000 = 6;
                    gUnk_02034934->unk_D2C = e2->unk_0C[gUnk_02034934->unk_C72];
                    gUnk_02034934->unk_048 = 0;
                    func_08006120(0, 5);
                    func_080063A8();
                    break;
                } else {
                    func_08006120(0, 5);
                    func_080063A8();
                    gUnk_02034934->unk_048 = 0;
                    gUnk_02034934->unk_000 = 8;
                    gUnk_02034934->unk_CD2 = gUnk_02034934->unk_C72;
                    gUnk_02034934->unk_D34 = e2->unk_14;
                    func_08001248(func_0805BAE4);
                    break;
                }
            }
        }

        gUnk_02034934->unk_048++;
        break;
    }

    t = abs(gSineTable[(gUnk_02034934->unk_D3E * 2) & 0xFF]) * 15 >> 8;
    gBldCnt = 0xF10;
    SetBlendAlpha(t, 16 - t);

    if (gUnk_02034934->unk_CAC & 1) {
        EnableBg(2);
        func_080658B8(gUnk_02034934->unk_C70);
        DrawSprite(0x23, 0x76, AnimUpdate(&gUnk_02034934->unk_C7C), gUnk_02034934->unk_018,
            gUnk_02034934->unk_01C, 0, 0, 0);
    } else {
        DisableBg(2);
    }

    for (i = 0; gUnk_02034934->unk_060[i].unk_000 != 0; i++) {
        if (i >= gUnk_02034934->unk_C78) {
            break;
        }
        func_080664D8(gUnk_02034934->unk_CAE, gUnk_02034934->unk_CB0 + gUnk_02034934->unk_CB2 * i,
            &gUnk_02034934->unk_060[i], gUnk_02034934->unk_014, 0, gUnk_02034934->unk_C60[i]);

        if (gUnk_02034934->unk_000 == 7) {
            switch (gUnk_02034934->unk_C68[i]) {
            case 1:
                DrawSprite(0xD9, gUnk_02034934->unk_CB0 + gUnk_02034934->unk_CB2 * i, gUnk_08C6A6A4,
                    gUnk_02034934->unk_030, gUnk_02034934->unk_034, 0, 4, 0);
                break;
            case 2:
                DrawSprite(0xD9, gUnk_02034934->unk_CB0 + gUnk_02034934->unk_CB2 * i - 2, gUnk_08C6A69A,
                    gUnk_02034934->unk_030, gUnk_02034934->unk_034, 0, 4, 0);
                break;
            }
        }
    }

    if (gUnk_02034934->unk_CAC & 2) {
        if (gUnk_02039BB0.unk_008 & 8) {
            DrawSprite(gUnk_02034934->unk_04C >> 8, 0, gUnk_08C69C76, gUnk_02034934->unk_004,
                gUnk_02034934->unk_008, 0, 0, 0);
        } else {
            DrawSprite(gUnk_02034934->unk_04C >> 8, 0, gUnk_08C69C04, gUnk_02034934->unk_004,
                gUnk_02034934->unk_008, 0, 0, 0);
        }
        DrawSprite(0x58, 0x98, gUnk_08C6A878, gUnk_02034934->unk_00C, gUnk_02034934->unk_010, 0, 0, 0);
        DrawSprite(0x80, gUnk_02034934->unk_050 >> 8, gUnk_08C69C20, gUnk_02034934->unk_004,
            gUnk_02034934->unk_008, 0, 0, 1);
        DrawSprite(0x80, gUnk_02034934->unk_054 >> 8, gUnk_08C69C54, gUnk_02034934->unk_004,
            gUnk_02034934->unk_008, 0, 0, 1);
    }

    if (gUnk_02034934->unk_000 == 7) {
        if (gUnk_02034934->unk_CAC & 8) {
            DrawSprite(gUnk_02034934->unk_CC2, gUnk_02034934->unk_CC4 - ((gUnk_02034934->unk_D3E >> 3) & 3),
                gUnk_08C6A51C, gUnk_02034934->unk_028, gUnk_02034934->unk_02C, 0, 0, 0);
        }
        if (gUnk_02034934->unk_CAC & 0x10) {
            DrawSprite(gUnk_02034934->unk_CC6, gUnk_02034934->unk_CC8 + ((gUnk_02034934->unk_D3E >> 3) & 3),
                gUnk_08C6A526, gUnk_02034934->unk_028, gUnk_02034934->unk_02C, 0, 0, 0);
        }
        if (func_08006314() == 0) {
            if (gUnk_02034934->unk_CAC & 4) {
                if (gUnk_02034934->unk_CC0 <= 0) {
                    DrawSprite(gUnk_02034934->unk_058 >> 8, gUnk_02034934->unk_05C >> 8,
                        AnimUpdate(&gUnk_02034934->unk_C94), gUnk_02034934->unk_020,
                        gUnk_02034934->unk_024, 0, 0, 0);
                } else {
                    DrawSprite(gUnk_02034934->unk_058 >> 8, gUnk_02034934->unk_05C >> 8, gUnk_08C6A8F8,
                        gUnk_02034934->unk_020, gUnk_02034934->unk_024, 0, 0, 0);
                    if (gUnk_02034934->unk_CC0 == 1) {
                        func_08005B64(&gUnk_02034934->unk_C94);
                    }
                }
            }
        }
    }

    UpdatePlayTime();
    gUnk_02034934->unk_D3E++;
}
#else
INCLUDE_ASM("mode_jiminy/mode_jiminy_1.s");
#endif

void func_0805B9D0(s16 a, s16 b, s32 c, s16 d, s16 e, s16 f) {
    gUnk_02034934->unk_CAE = d;
    gUnk_02034934->unk_CB0 = e;
    gUnk_02034934->unk_CB2 = f;
    gUnk_02034934->unk_C76 = b;
    gUnk_02034934->unk_C78 = a;
    gUnk_02034934->unk_CB4 = c;
    gUnk_02034934->unk_CC2 = d + 0x38;
    gUnk_02034934->unk_CC6 = d + 0x38;
    gUnk_02034934->unk_CC4 = e - 10;
    gUnk_02034934->unk_CC8 = e + f * (a - 1) + 12;
    gUnk_02034934->unk_C72 = 0;
    gUnk_02034934->unk_C74 = 0;
    gUnk_02034934->unk_CC0 = 0;
    gUnk_02034934->unk_D3E = 0;
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
    ReleaseObjTiles(gUnk_02034934->unk_004);
    ReleaseObjPalette(gUnk_02034934->unk_008);
    ReleaseObjTiles(gUnk_02034934->unk_00C);
    ReleaseObjPalette(gUnk_02034934->unk_010);
    ReleaseObjPalette(gUnk_02034934->unk_014);
    ReleaseObjTiles(gUnk_02034934->unk_018);
    ReleaseObjPalette(gUnk_02034934->unk_01C);
    ReleaseObjTiles(gUnk_02034934->unk_020);
    ReleaseObjPalette(gUnk_02034934->unk_024);
    ReleaseObjTiles(gUnk_02034934->unk_028);
    ReleaseObjPalette(gUnk_02034934->unk_02C);
    ReleaseObjTiles(gUnk_02034934->unk_030);
    ReleaseObjPalette(gUnk_02034934->unk_034);
    ReleaseObjTiles(gUnk_02034934->unk_038);
    ReleaseObjPalette(gUnk_02034934->unk_03C);
    ReleaseObjTiles(gUnk_02034934->unk_040);
    ReleaseObjPalette(gUnk_02034934->unk_044);
    func_0805A484();
    EwramFree(gUnk_02034934);
}
