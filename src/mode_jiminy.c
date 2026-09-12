#include "jiminy_list.h"
#include "map_api.h"
#include "msg_api.h"
#include "fade.h"
#include "macros.h"
#include "mode_jiminy.h"

JiminyWork* gJiminyWork;

void mode_jiminy_0(void) {
    s32 i;
    s32 j;
    JiminyEntry* e;

#ifdef VERSION_EU
    gJiminyWork = EwramAlloc(0xED0);
#else
    gJiminyWork = EwramAlloc(0xD40);
#endif
    SetBgMode0();
    SetupBg(0, 0, 0x1D, 0);
    SetupBg(1, 0, 0x1E, 0);
    SetupBg(2, 0, 0x1F, 0);
    SetupBg(3, 0, 0x1C, 0x0D);
    SetBgPriority(0, 0);
    SetBgPriority(1, 1);
    SetBgPriority(2, 0);
    SetBgPriority(3, 0);
#ifdef VERSION_JP
    LoadBgTiles(1, gUnk_08EE4A64, 0x2DA0);
#elif defined(VERSION_EU)
    LoadBgTiles(1, gUnk_08EE4A64, 0x2F60);
    switch (gLanguage) {
    case 1:
        RequestDma3Copy(gUnkEu_08EF3EDC, (u8*)GetBgCharBase(1) + 0x2000, 0x1000);
        break;
    case 4:
        RequestDma3Copy(gUnkEu_08EF4EDC, (u8*)GetBgCharBase(1) + 0x2000, 0x1000);
        break;
    case 3:
        RequestDma3Copy(gUnkEu_08EF5EDC, (u8*)GetBgCharBase(1) + 0x2000, 0x1000);
        break;
    case 2:
        RequestDma3Copy(gUnkEu_08EF6EDC, (u8*)GetBgCharBase(1) + 0x2000, 0x1000);
        break;
    }
#else
    LoadBgTiles(1, gUnk_08EE4A64, 0x2E80);
#endif
    LoadBgPalette(1, gUnk_08F6DE24, 0x200);
    LoadBgMap(1, gUnk_08F61B84, 0x800);
    LoadBgMap(2, gUnk_08F60B84, 0x800);
#ifdef VERSION_EU
    if (gLanguage == 0) {
        gJiminyWork->tiles = LoadObjTiles(gUnk_08C69C9C, 0x880);
    } else {
        gJiminyWork->tiles = LoadObjTiles(gUnkEu_08C9A5E2, 0x1780);
    }
#else
    gJiminyWork->tiles = LoadObjTiles(gUnk_08C69C9C, 0x880);
#endif
    gJiminyWork->palette = LoadObjPalette(gUnk_08F6DD64, 0x20);
    func_080062F4(gJiminyWork->palette->unk_06 + 0x10, 1);
    gJiminyWork->tiles2 = LoadObjTiles(gUnk_08C6A88C, 0x40);
    gJiminyWork->palette2 = LoadObjPalette(gUnk_08F6DDE4, 0x20);
    gJiminyWork->palette3 = LoadObjPalette(gUnk_08F6DD84, 0x20);
    gJiminyWork->tiles5 = LoadObjTiles(gUnk_08C6A54E, 0x140);
    gJiminyWork->palette6 = LoadObjPalette(gUnk_08F6DDA4, 0x20);
#ifdef VERSION_EU
    gJiminyWork->tiles6 = LoadObjTiles(gUnk_08C6A6B8, 0x340);
#else
    gJiminyWork->tiles6 = LoadObjTiles(gUnk_08C6A6B8, 0x1C0);
#endif
    gJiminyWork->palette7 = LoadObjPalette(gUnk_08F6DDC4, 0x20);
    gJiminyWork->unk_04C = -0x8000;
    gJiminyWork->unk_050 = -0x800;
    gJiminyWork->unk_054 = 0xA000;
    gJiminyWork->unk_000 = 0;
    gJiminyWork->unk_048 = 0;
    gJiminyWork->unk_C70 = 0;
    gJiminyWork->unk_C72 = 0;
    gJiminyWork->unk_C74 = 0;

    if (gGameState.flags & 8) {
        gJiminyWork->tiles3 = AllocObjTiles(0x1000, gUnk_0913F0C2);
        gJiminyWork->palette4 = LoadObjPalette(gUnk_09614D58, 0x20);
        AnimInit(&gJiminyWork->unk_C7C, gUnk_09EED320, gUnk_09EED2BC);
        AnimStart(&gJiminyWork->unk_C7C, 0, 1);
    } else {
        gJiminyWork->tiles3 = AllocObjTiles(0x1000, gUnk_090FDBF4);
        gJiminyWork->palette4 = LoadObjPalette(gUnk_09614AB8, 0x20);
        AnimInit(&gJiminyWork->unk_C7C, gUnk_09EECAA0, gUnk_09EECA44);
        AnimStart(&gJiminyWork->unk_C7C, 0, 1);
    }

    if (func_08006314() == 0) {
        gJiminyWork->tiles4 = AllocObjTiles(0x200, gUnk_08C6A958);
        gJiminyWork->palette5 = LoadObjPalette(gUnk_08F6DE04, 0x20);
        AnimInit(&gJiminyWork->unk_C94, gUnk_09EE2678, gUnk_09EE2668);
        AnimStart(&gJiminyWork->unk_C94, 2, 1);
    }

    gJiminyWork->tiles7 = AllocObjTiles(0x2000, 0);
#ifdef VERSION_EU
    gJiminyWork->palette8 = LoadObjPalette(gUnk_09A3CDDC, 0x40);
#else
    gJiminyWork->palette8 = LoadObjPalette(gUnk_09A3CC9C, 0x20);
#endif
    gJiminyWork->tiles8 = AllocObjTiles(0x800, 0);
    gJiminyWork->palette9 = LoadObjPalette(gUnk_09611AB8, 0x20);
    gJiminyWork->unk_D3C = 0;
    gJiminyWork->unk_D38 = 0x100;
    func_08006120(0, 0x10);

    for (i = 0; i < 8; i++) {
        func_08065ACC(&gJiminyWork->unk_060[i], 0x30);
    }

    func_08064B80(0);
#ifdef VERSION_JP
    gJiminyWork->unk_C71 = func_080653D4(0x400, 0x2600, gUnk_08159FE0);
#elif defined(VERSION_EU)
    gJiminyWork->unk_C71 = func_08065170(0x200, 0x2400, eu_0805E924(gUnkEu_08892334));
#else
    gJiminyWork->unk_C71 = func_08065170(0x200, 0x2400, gUnk_08159FE0);
#endif

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
#ifdef VERSION_JP
        gJiminyWork->unk_C71 = func_080653D4(0x400, 0x2600, gUnk_08159FE0);
#else
#ifdef VERSION_EU
        gJiminyWork->unk_C71 = func_08065170(0x200, 0x2400, eu_0805E924(gUnkEu_08892334));
#else
        gJiminyWork->unk_C71 = func_08065170(0x200, 0x2400, gUnk_08159FE0);
#endif
#endif
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
            LoadObjPaletteBank(gJiminyWork->palette3->unk_06, gUnk_08F6DD84);
            func_0805A95C(3, e->unk_08, e->unk_04, e->unk_10, e->unk_0C, 0x80, 0x40, 0x18);
        } else {
            LoadBgMap(1, e->unk_00, 0x800);
            LoadObjPaletteBank(gJiminyWork->palette3->unk_06, gUnk_08F6DDC4);
#ifdef VERSION_JP
            func_0805A95C(8, e->unk_08, e->unk_04, e->unk_10, e->unk_0C, 0x70, 0x1A, 0x10);
#else
            func_0805A95C(4, e->unk_08, e->unk_04, e->unk_10, e->unk_0C, 0x70, 0x3A, 0x10);
#endif
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
        DrawSprite(0x23, 0x76, AnimUpdate(&gJiminyWork->unk_C7C), gJiminyWork->tiles3,
            gJiminyWork->palette4, 0, 0, 0);
    } else {
        DisableBg(2);
    }

    for (i = 0; gJiminyWork->unk_060[i].unk_000 != 0; i++) {
        if (i >= gJiminyWork->unk_C78) {
            break;
        }
        func_080664D8(gJiminyWork->unk_CAE, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i,
            &gJiminyWork->unk_060[i], gJiminyWork->palette3, 0, gJiminyWork->unk_C60[i]);

        if (gJiminyWork->unk_000 == 7) {
            switch (gJiminyWork->unk_C68[i]) {
            case 1:
#ifdef VERSION_EU
                switch (gLanguage) {
                case 0:
                    DrawSprite(0xD9, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i, gUnk_08C6A6A4,
                        gJiminyWork->tiles6, gJiminyWork->palette7, 0, 4, 0xFFFE);
                    break;
                case 1:
                    DrawSprite(0xD9, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i, gUnkEu_08C9BD82,
                        gJiminyWork->tiles6, gJiminyWork->palette7, 0, 4, 0xFFFE);
                    break;
                case 4:
                    DrawSprite(0xD9, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i, gUnkEu_08C9BD8C,
                        gJiminyWork->tiles6, gJiminyWork->palette7, 0, 4, 0xFFFE);
                    break;
                case 3:
                    DrawSprite(0xD9, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i, gUnkEu_08C9BD9C,
                        gJiminyWork->tiles6, gJiminyWork->palette7, 0, 4, 0xFFFE);
                    break;
                case 2:
                default:
                    DrawSprite(0xD9, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i, gUnkEu_08C9BDAC,
                        gJiminyWork->tiles6, gJiminyWork->palette7, 0, 4, 0xFFFE);
                    break;
                }
#else
                DrawSprite(0xD9, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i, gUnk_08C6A6A4,
                    gJiminyWork->tiles6, gJiminyWork->palette7, 0, 4, 0);
#endif
                break;
            case 2:
#ifdef VERSION_EU
                DrawSprite(0xD9, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i - 2, gUnk_08C6A69A,
                    gJiminyWork->tiles6, gJiminyWork->palette7, 0, 4, 0xFFFE);
#else
                DrawSprite(0xD9, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i - 2, gUnk_08C6A69A,
                    gJiminyWork->tiles6, gJiminyWork->palette7, 0, 4, 0);
#endif
                break;
            }
        }
    }

    if (gJiminyWork->unk_CAC & 2) {
#ifdef VERSION_EU
        switch (gLanguage) {
        case 0:
            if (gGameState.flags & 8) {
                DrawSprite(gJiminyWork->unk_04C >> 8, 0, gUnk_08C69C76, gJiminyWork->tiles,
                    gJiminyWork->palette, 0, 0, 0);
            } else {
                DrawSprite(gJiminyWork->unk_04C >> 8, 0, gUnk_08C69C04, gJiminyWork->tiles,
                    gJiminyWork->palette, 0, 0, 0);
            }
            DrawSprite(0x58, 0x98, gUnk_08C6A878, gJiminyWork->tiles2, gJiminyWork->palette2, 0, 0, 0);
            DrawSprite(0x80, gJiminyWork->unk_050 >> 8, gUnk_08C69C20, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 1);
            DrawSprite(0x80, gJiminyWork->unk_054 >> 8, gUnk_08C69C54, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 1);
            break;
        case 1:
            if (gGameState.flags & 8) {
                DrawSprite(gJiminyWork->unk_04C >> 8, 0, gUnkEu_08C9A538, gJiminyWork->tiles,
                    gJiminyWork->palette, 0, 0, 0);
            } else {
                DrawSprite(gJiminyWork->unk_04C >> 8, 0, gUnkEu_08C9A4CC, gJiminyWork->tiles,
                    gJiminyWork->palette, 0, 0, 0);
            }
            DrawSprite(0x58, 0x98, gUnk_08C6A878, gJiminyWork->tiles2, gJiminyWork->palette2, 0, 0, 0);
            DrawSprite(0x80, gJiminyWork->unk_050 >> 8, gUnkEu_08C9A4E2, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 1);
            DrawSprite(0x80, gJiminyWork->unk_054 >> 8, gUnkEu_08C9A516, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 1);
            break;
        case 4:
            if (gGameState.flags & 8) {
                DrawSprite(gJiminyWork->unk_04C >> 8, 0, gUnkEu_08C9A564, gJiminyWork->tiles,
                    gJiminyWork->palette, 0, 0, 0);
            } else {
                DrawSprite(gJiminyWork->unk_04C >> 8, 0, gUnkEu_08C9A554, gJiminyWork->tiles,
                    gJiminyWork->palette, 0, 0, 0);
            }
            DrawSprite(0x58, 0x98, gUnk_08C6A878, gJiminyWork->tiles2, gJiminyWork->palette2, 0, 0, 0);
            DrawSprite(0x80, gJiminyWork->unk_050 >> 8, gUnkEu_08C9A4E2, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 1);
            DrawSprite(0x80, gJiminyWork->unk_054 >> 8, gUnkEu_08C9A516, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 1);
            break;
        case 3:
            if (gGameState.flags & 8) {
                DrawSprite(gJiminyWork->unk_04C >> 8, 0, gUnkEu_08C9A590, gJiminyWork->tiles,
                    gJiminyWork->palette, 0, 0, 0);
            } else {
                DrawSprite(gJiminyWork->unk_04C >> 8, 0, gUnkEu_08C9A57A, gJiminyWork->tiles,
                    gJiminyWork->palette, 0, 0, 0);
            }
            DrawSprite(0x58, 0x98, gUnk_08C6A878, gJiminyWork->tiles2, gJiminyWork->palette2, 0, 0, 0);
            DrawSprite(0x80, gJiminyWork->unk_050 >> 8, gUnkEu_08C9A4E2, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 1);
            DrawSprite(0x80, gJiminyWork->unk_054 >> 8, gUnkEu_08C9A516, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 1);
            break;
        case 2:
        default:
            if (gGameState.flags & 8) {
                DrawSprite(gJiminyWork->unk_04C >> 8, 0, gUnkEu_08C9A5C2, gJiminyWork->tiles,
                    gJiminyWork->palette, 0, 0, 0);
            } else {
                DrawSprite(gJiminyWork->unk_04C >> 8, 0, gUnkEu_08C9A5A6, gJiminyWork->tiles,
                    gJiminyWork->palette, 0, 0, 0);
            }
            DrawSprite(0x58, 0x98, gUnk_08C6A878, gJiminyWork->tiles2, gJiminyWork->palette2, 0, 0, 0);
            DrawSprite(0x80, gJiminyWork->unk_050 >> 8, gUnkEu_08C9A4E2, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 1);
            DrawSprite(0x80, gJiminyWork->unk_054 >> 8, gUnkEu_08C9A516, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 1);
            break;
        }
#else
        if (gGameState.flags & 8) {
            DrawSprite(gJiminyWork->unk_04C >> 8, 0, gUnk_08C69C76, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 0);
        } else {
            DrawSprite(gJiminyWork->unk_04C >> 8, 0, gUnk_08C69C04, gJiminyWork->tiles,
                gJiminyWork->palette, 0, 0, 0);
        }
        DrawSprite(0x58, 0x98, gUnk_08C6A878, gJiminyWork->tiles2, gJiminyWork->palette2, 0, 0, 0);
        DrawSprite(0x80, gJiminyWork->unk_050 >> 8, gUnk_08C69C20, gJiminyWork->tiles,
            gJiminyWork->palette, 0, 0, 1);
        DrawSprite(0x80, gJiminyWork->unk_054 >> 8, gUnk_08C69C54, gJiminyWork->tiles,
            gJiminyWork->palette, 0, 0, 1);
#endif
    }

    if (gJiminyWork->unk_000 == 7) {
        if (gJiminyWork->unk_CAC & 8) {
            DrawSprite(gJiminyWork->unk_CC2, gJiminyWork->unk_CC4 - ((gJiminyWork->unk_D3E >> 3) & 3),
                gUnk_08C6A51C, gJiminyWork->tiles5, gJiminyWork->palette6, 0, 0, 0);
        }

        if (gJiminyWork->unk_CAC & 0x10) {
            DrawSprite(gJiminyWork->unk_CC6, gJiminyWork->unk_CC8 + ((gJiminyWork->unk_D3E >> 3) & 3),
                gUnk_08C6A526, gJiminyWork->tiles5, gJiminyWork->palette6, 0, 0, 0);
        }

        if (func_08006314() == 0) {
            if (gJiminyWork->unk_CAC & 4) {
                if (gJiminyWork->unk_CC0 <= 0) {
                    DrawSprite(gJiminyWork->unk_058 >> 8, gJiminyWork->unk_05C >> 8,
                        AnimUpdate(&gJiminyWork->unk_C94), gJiminyWork->tiles4,
                        gJiminyWork->palette5, 0, 0, 0);
                } else {
                    DrawSprite(gJiminyWork->unk_058 >> 8, gJiminyWork->unk_05C >> 8, gUnk_08C6A8F8,
                        gJiminyWork->tiles4, gJiminyWork->palette5, 0, 0, 0);

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

void func_0805BAE4(void) {
    s32 count;
    JiminyDetail* entries;
    s16 i;
    s16 unlocked;
    s16 selected;
    s16 width;
    u8 digits[3];
    u8* map0;
    u8* map1;
    u8* source;
    u8* dest;
    u16* paletteDest;
#ifdef VERSION_EU
    s32 wide = 0;
#endif

    switch ((u32)gJiminyWork->unk_000) {
    case 8:
        switch ((u32)gJiminyWork->unk_D34) {
        case 1:
            count = 17;
            entries = gUnk_0815574C;
            gJiminyWork->unk_D30 = 0;
            break;
        case 2:
            count = 17;
            entries = gUnk_08155C54;
            gJiminyWork->unk_D30 = 1;
            break;
        case 3:
            count = 14;
            entries = gUnk_0815600C;
            gJiminyWork->unk_D30 = 1;
            break;
        case 4:
            count = 7;
            entries = gUnk_0815631C;
            gJiminyWork->unk_D30 = 1;
            break;
        case 5:
            count = 7;
            entries = gUnk_081564A4;
            gJiminyWork->unk_D30 = 1;
            break;
        case 6:
            count = 49;
            entries = gUnk_0815662C;
            gJiminyWork->unk_D30 = 1;
            break;
        case 7:
            count = 26;
            entries = gUnk_081570E4;
            gJiminyWork->unk_D30 = 1;
            break;
        case 8:
            count = 1;
            entries = gUnk_08157694;
            gJiminyWork->unk_D30 = 1;
            break;
        case 9:
            count = 25;
            entries = gUnk_08157B9C;
            gJiminyWork->unk_D30 = 2;
            break;
        case 10:
            count = 40;
            entries = gUnk_08158114;
            gJiminyWork->unk_D30 = 2;
            break;
        case 11:
            count = 35;
            entries = gUnk_081589D4;
            gJiminyWork->unk_D30 = 2;
            break;
        case 12:
            count = 6;
            entries = gUnk_08155B04;
            gJiminyWork->unk_D30 = 0;
            break;
        case 13:
            count = 22;
            entries = gUnk_081576CC;
            gJiminyWork->unk_D30 = 1;
            break;
        case 14:
            count = 14;
            entries = gUnk_0815917C;
            gJiminyWork->unk_D30 = 2;
            break;
        case 15:
            count = 6;
            entries = gUnk_0815948C;
            gJiminyWork->unk_D30 = 2;
            break;
        case 16:
            count = 33;
            entries = gUnk_081595DC;
            gJiminyWork->unk_D30 = 2;
            break;
        default:
            count = 25;
            entries = gUnk_08157B9C;
            gJiminyWork->unk_D30 = 2;
            break;
        }
        gJiminyWork->unk_CD0 = count;
        if (gJiminyWork->unk_CD2 >= (s16)count) {
            gJiminyWork->unk_CD2 = 0;
        }
        gJiminyWork->unk_CCC = &entries[gJiminyWork->unk_CD2];
        if (gJiminyWork->unk_CB8 != 0) {
            func_0800FFE0(gJiminyWork->unk_CB8[gJiminyWork->unk_CD2]);
            unlocked = 0;
            selected = 0;
            for (i = 0; i < count; i++) {
                if (func_0800FF00(gJiminyWork->unk_CB8[i])) {
                    if (gJiminyWork->unk_CD2 == i) {
                        selected = unlocked;
                    }
                    unlocked++;
                }
            }
            gJiminyWork->unk_CD4 = gJiminyWork->unk_CD2;
            gJiminyWork->unk_CD6 = gJiminyWork->unk_CD2;
            i = gJiminyWork->unk_CD2 + 1;
            for (;;) {
                if (i >= count) {
                    i = 0;
                }
                if (i == gJiminyWork->unk_CD2) {
                    break;
                }
                if (func_0800FF00(gJiminyWork->unk_CB8[i])) {
                    gJiminyWork->unk_CD4 = i;
                    break;
                }
                i++;
            }
            i = gJiminyWork->unk_CD2 - 1;
            for (;;) {
                if (i < 0) {
                    i = count - 1;
                }
                if (i == gJiminyWork->unk_CD2) {
                    break;
                }
                if (func_0800FF00(gJiminyWork->unk_CB8[i])) {
                    gJiminyWork->unk_CD6 = i;
                    break;
                }
                i--;
            }
        } else {
            unlocked = count;
            selected = gJiminyWork->unk_CD2;
            gJiminyWork->unk_CD4 = gJiminyWork->unk_CD2 + 1;
            if (gJiminyWork->unk_CD4 >= count) {
                gJiminyWork->unk_CD4 = 0;
            }
            gJiminyWork->unk_CD6 = gJiminyWork->unk_CD2 - 1;
            if (gJiminyWork->unk_CD6 < 0) {
                gJiminyWork->unk_CD6 = count - 1;
            }
        }
        switch (gJiminyWork->unk_D30) {
        case 0:
            map0 = gUnk_08F64384;
            map1 = gUnk_08F60384;
#ifdef VERSION_JP
            gJiminyWork->unk_C71 = func_080653D4(0x400,
                0x1800, gJiminyWork->unk_CCC->name);
#elif defined(VERSION_EU)
            gJiminyWork->unk_C71 = func_08065170(0x400,
                0x1600, eu_0805E924(gJiminyWork->unk_CCC->name));
#else
            gJiminyWork->unk_C71 = func_08065170(0x400,
                0x1600, gJiminyWork->unk_CCC->name);
#endif
#ifdef VERSION_EU
            func_0805B9D0(4, eu_0805E9AC(gJiminyWork->unk_CCC->text), (s32)eu_0805E968(gJiminyWork->unk_CCC->text), 8, 0x3A, 16);
#else
#ifdef VERSION_JP
            func_0805B9D0(7, gJiminyWork->unk_CCC->lineCount, (s32)gJiminyWork->unk_CCC->text, 8, 0x2A, 16);
#else
            func_0805B9D0(4, gJiminyWork->unk_CCC->lineCount, (s32)gJiminyWork->unk_CCC->text, 8, 0x3A, 16);
#endif
#endif
            break;
        case 1:
            map0 = gUnk_08F64384;
            map1 = gUnk_08F5EB84;
#ifdef VERSION_JP
            gJiminyWork->unk_C71 = func_080653D4(0x400,
                0x1800, gJiminyWork->unk_CCC->name);
#elif defined(VERSION_EU)
            gJiminyWork->unk_C71 = func_08065170(0x400,
                0x1600, eu_0805E924(gJiminyWork->unk_CCC->name));
#else
            gJiminyWork->unk_C71 = func_08065170(0x400,
                0x1600, gJiminyWork->unk_CCC->name);
#endif
#ifdef VERSION_EU
            func_0805B9D0(4, eu_0805E9AC(gJiminyWork->unk_CCC->text), (s32)eu_0805E968(gJiminyWork->unk_CCC->text), 8, 0x3A, 16);
#else
#ifdef VERSION_JP
            func_0805B9D0(7, gJiminyWork->unk_CCC->lineCount, (s32)gJiminyWork->unk_CCC->text, 8, 0x2A, 16);
#else
            func_0805B9D0(4, gJiminyWork->unk_CCC->lineCount, (s32)gJiminyWork->unk_CCC->text, 8, 0x3A, 16);
#endif
#endif
            break;
        case 2:
        default:
            map0 = gUnk_08F63384;
            map1 = gUnk_08F5FB84;
#ifdef VERSION_JP
            gJiminyWork->unk_C71 = func_080653D4(0x2800,
                0x1800, gJiminyWork->unk_CCC->name);
#elif defined(VERSION_EU)
            gJiminyWork->unk_C71 = func_08065170(0x2800,
                0x1600, eu_0805E924(gJiminyWork->unk_CCC->name));
#else
            gJiminyWork->unk_C71 = func_08065170(0x2800,
                0x1600, gJiminyWork->unk_CCC->name);
#endif
#ifdef VERSION_EU
            func_0805B9D0(4, eu_0805E9AC(gJiminyWork->unk_CCC->text), (s32)eu_0805E968(gJiminyWork->unk_CCC->text), 8, 0x3A, 16);
#else
            func_0805B9D0(
#ifdef VERSION_JP
                6,
#else
                4,
#endif
                gJiminyWork->unk_CCC->lineCount, (s32)gJiminyWork->unk_CCC->text, 8, 0x3A, 16);
#endif
            break;
        }
        LoadBgMap(0, map0, 0x800);
        LoadBgMap(1, map1, 0x800);
        if (gJiminyWork->unk_CCC->tiles != 0) {
#ifdef VERSION_EU
            if (gJiminyWork->unk_CCC->palette == gUnkEu_09A9A880 && func_080D2DD8()) {
                LoadObjPaletteBank(gJiminyWork->palette8->unk_06, gUnkEu_09A9A8A0);
                LoadObjPaletteBank(gJiminyWork->palette8->unk_06 + 1, gUnkEu_09A9A8A0 + 0x20);
                func_08002A10(gJiminyWork->tiles7, gUnkEu_099FBE00);
            } else
#endif
            {
                LoadObjPaletteBank(gJiminyWork->palette8->unk_06, gJiminyWork->unk_CCC->palette);
                func_08002A10(gJiminyWork->tiles7, gJiminyWork->unk_CCC->tiles);
            }
        }
        if (gJiminyWork->unk_CCC->tiles2 != 0) {
            LoadObjPaletteBank(gJiminyWork->palette9->unk_06, gJiminyWork->unk_CCC->palette2);
            func_08002A10(gJiminyWork->tiles8, gJiminyWork->unk_CCC->tiles2);
        }
        if (gJiminyWork->unk_D30 == 2) {
            source = gUnk_08F63B84;
            dest = (u8*)GetBgScreenBase(0) + 0x8E;
        } else {
            source = gUnk_08F64B84;
            dest = (u8*)GetBgScreenBase(0) + 0x80;
        }
        if (gJiminyWork->unk_D30 < 2) {
#ifdef VERSION_JP
            switch (gJiminyWork->unk_C71) {
            case 1: source += 0xC0; break;
            case 2: source += 0x240; break;
            case 3: source += 0x300; break;
            case 4: source += 0x480; break;
            case 5: source += 0x540; break;
            case 6: source += 0x600; break;
            case 7: source += 0x6C0; break;
            case 8: source += 0xE0; break;
            case 9: source += 0x1A0; break;
            case 10: source += 0x260; break;
            default: source += 0x320; break;
            }
#else
            width = func_08064DD4(
#ifdef VERSION_EU
                eu_0805E924(gJiminyWork->unk_CCC->name)
#else
                gJiminyWork->unk_CCC->name
#endif
            );
            switch ((width + 12) / 8) {
            case 0: source += 0x240; break;
            case 1: source += 0x240; break;
            case 2: source += 0x240; break;
            case 3: source += 0x240; break;
            case 4: source += 0x300; break;
            case 5: source += 0x3C0; break;
            case 6: source += 0x480; break;
            case 7: source += 0x540; break;
            case 8: source += 0x600; break;
            case 9: source += 0x6C0; break;
            case 10: source += 0x20; break;
            case 11: source += 0xE0; break;
            case 12: source += 0x1A0; break;
            case 13: source += 0x260; break;
#ifdef VERSION_EU
            case 14: source += 0x320; break;
            case 15: source += 0x3E0; break;
            default: source += 0x3E0; wide = 1; break;
#else
            default: source += 0x320; break;
#endif
            }
#endif
        } else {
#ifdef VERSION_JP
            width = gJiminyWork->unk_C71;
#else
            width = (s16)func_08064DD4(
#ifdef VERSION_EU
                eu_0805E924(gJiminyWork->unk_CCC->name)
#else
                gJiminyWork->unk_CCC->name
#endif
            ) / 8;
#endif
            switch (width) {
            case 0: break;
            case 1: break;
            case 2: source += 0xC0; break;
            case 3: source += 0x180; break;
            case 4: source += 0x240; break;
            case 5: source += 0x300; break;
            case 6: source += 0x3C0; break;
#ifdef VERSION_JP
            case 7: source += 0x540; break;
            case 8: source += 0x600; break;
            case 9: source += 0x6C0; break;
            case 10: source += 0x20; break;
            case 11: source += 0x1A0; break;
            case 12: source += 0x1A0; break;
            case 13: source += 0x1A0; break;
#else
            case 7: source += 0x480; break;
            case 8: source += 0x540; break;
            case 9: source += 0x600; break;
            case 10: source += 0x6C0; break;
            case 11: source += 0x20; break;
            case 12: source += 0xE0; break;
            case 13: source += 0x1A0; break;
#endif
            default: source += 0x260; break;
            }
        }
        RequestDma3Copy(source, dest, 0x20);
        RequestDma3Copy(source + 0x40, dest + 0x40, 0x20);
        RequestDma3Copy(source + 0x80, dest + 0x80, 0x20);
#ifdef VERSION_EU
        if (wide) {
            RequestDma3Copy(source, dest + 2, 0x20);
            RequestDma3Copy(source + 0x40, dest + 0x42, 0x20);
            RequestDma3Copy(source + 0x80, dest + 0x82, 0x20);
        }
#endif
        source = gUnk_08EE78E4;
        func_0805BAAC(selected + 1, digits);
        dest = (u8*)GetBgCharBase(0) + 0x20;
        RequestDma3Copy(source + digits[0] * 0x20, dest, 0x20);
        dest = (u8*)GetBgCharBase(0) + 0x40;
        RequestDma3Copy(source + digits[1] * 0x20, dest, 0x20);
        dest = (u8*)GetBgCharBase(0) + 0x60;
        RequestDma3Copy(source + digits[2] * 0x20, dest, 0x20);
        func_0805BAAC(unlocked, digits);
        dest = (u8*)GetBgCharBase(0) + 0x80;
        RequestDma3Copy(source + digits[0] * 0x20, dest, 0x20);
        dest = (u8*)GetBgCharBase(0) + 0xA0;
        RequestDma3Copy(source + digits[1] * 0x20, dest, 0x20);
        dest = (u8*)GetBgCharBase(0) + 0xC0;
        RequestDma3Copy(source + digits[2] * 0x20, dest, 0x20);
        gJiminyWork->unk_000 = 9;
        DisableBg(2);
        if (gJiminyWork->unk_CCC->bgTiles != 0) {
            EnableBg(3);
            RequestDma3Copy(gJiminyWork->unk_CCC->bgTiles,
                (u8*)GetBgCharBase(3) + 0x4000, gJiminyWork->unk_CCC->tileSize);
            switch ((u16)gJiminyWork->unk_CCC->paletteSize) {
            case 0x60:
                paletteDest = (u16*)0x050001A0;
                LoadPalette(gJiminyWork->unk_CCC->bgPalette, paletteDest, 0x60);
                break;
            case 0x40:
                paletteDest = (u16*)0x050001C0;
                LoadPalette(gJiminyWork->unk_CCC->bgPalette, paletteDest, 0x40);
                break;
            case 0x20:
            default:
                paletteDest = (u16*)0x050001E0;
                LoadPalette(gJiminyWork->unk_CCC->bgPalette, paletteDest, 0x20);
                break;
            }
            LoadBgMap(3, gJiminyWork->unk_CCC->bgMap, 0x800);
        } else {
            DisableBg(3);
        }
        gJiminyWork->unk_D3C = 5;
        SetBlendAlpha(0, 16);
    case 9:
        if (gJiminyWork->unk_C72 > 0) {
            gJiminyWork->unk_CAC |= 8;
        } else {
            gJiminyWork->unk_CAC &= ~8;
        }
        if (gJiminyWork->unk_C78 < gJiminyWork->unk_C76 - gJiminyWork->unk_C72) {
            gJiminyWork->unk_CAC |= 0x10;
        } else {
            gJiminyWork->unk_CAC &= ~0x10;
        }
        if (func_08006314() != 0) {
            break;
        }
        if (gJiminyWork->unk_CC0 <= 0) {
            if (GetKeysRepeat() & 0x40) {
                if (gJiminyWork->unk_C72 > 0) {
                    gJiminyWork->unk_CC0 = 1;
                    gJiminyWork->unk_C72--;
                    m4aSongNumStart(0x79);
                    func_0805A8D0();
                }
            } else if (GetKeysRepeat() & 0x80) {
                if (gJiminyWork->unk_C78 < gJiminyWork->unk_C76 - gJiminyWork->unk_C72) {
                    gJiminyWork->unk_CC0 = 1;
                    gJiminyWork->unk_C72++;
                    m4aSongNumStart(0x79);
                    func_0805A8D0();
                }
            }
        } else {
            gJiminyWork->unk_CC0 = 0;
        }
        if (gJiminyWork->unk_CD2 != gJiminyWork->unk_CD4) {
            if (GetKeysRepeat() & 0x200) {
                gJiminyWork->unk_000 = 8;
                gJiminyWork->unk_048 = 0;
                gJiminyWork->unk_CD2 = gJiminyWork->unk_CD6;
                m4aSongNumStart(0x67);
                break;
            } else if (GetKeysRepeat() & 0x100) {
                gJiminyWork->unk_000 = 8;
                gJiminyWork->unk_048 = 0;
                gJiminyWork->unk_CD2 = gJiminyWork->unk_CD4;
                m4aSongNumStart(0x67);
                break;
            }
        }
        if (GetKeysPressed() & 2) {
            gJiminyWork->unk_048 = 0;
            gJiminyWork->unk_000 = 6;
            func_08006120(0, 5);
            func_080063A8();
            SetModeUpdate(mode_jiminy_1);
            m4aSongNumStart(0x68);
        } else if (GetKeysPressed() & 8) {
            gJiminyWork->unk_048 = 0;
            gJiminyWork->unk_000 = 5;
            m4aSongNumStart(0x68);
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
    }
    func_080658B8(gJiminyWork->unk_C71);
    for (i = 0; gJiminyWork->unk_060[i].unk_000 != 0 && i < gJiminyWork->unk_C78; i++) {
        func_080664D8(gJiminyWork->unk_CAE, gJiminyWork->unk_CB0 + gJiminyWork->unk_CB2 * i,
            &gJiminyWork->unk_060[i], gJiminyWork->palette3, 0, gJiminyWork->unk_C60[i]);
    }
    if (gJiminyWork->unk_CAC & 8) {
        DrawSprite(gJiminyWork->unk_CC2, gJiminyWork->unk_CC4 - ((gJiminyWork->unk_D3E >> 3) & 3) + 4,
            gUnk_08C6A51C, gJiminyWork->tiles5, gJiminyWork->palette6, 0, 0, 0);
    }
    if (gJiminyWork->unk_CAC & 0x10) {
        DrawSprite(gJiminyWork->unk_CC6, gJiminyWork->unk_CC8 + ((gJiminyWork->unk_D3E >> 3) & 3),
            gUnk_08C6A526, gJiminyWork->tiles5, gJiminyWork->palette6, 0, 0, 0);
    }
    if (gJiminyWork->unk_CD2 != gJiminyWork->unk_CD4) {
        DrawSprite(-((gJiminyWork->unk_D3E >> 3) & 3) + 0x9A, 5, gUnk_08C6A530,
            gJiminyWork->tiles5, gJiminyWork->palette6, 0, 0, 0);
        DrawSprite(0xE0 + ((gJiminyWork->unk_D3E >> 3) & 3), 5, gUnk_08C6A53A,
            gJiminyWork->tiles5, gJiminyWork->palette6, 0, 0, 0);
    }
    switch (gJiminyWork->unk_D30) {
    case 0:
        if (gJiminyWork->unk_CCC->tiles != 0) {
            DrawSprite(gJiminyWork->unk_CCC->x + 0xC8, gJiminyWork->unk_CCC->y + 0x5C,
                gJiminyWork->unk_CCC->sprite, gJiminyWork->tiles7, gJiminyWork->palette8, 0, 4, 1);
        }
        break;
    case 1:
        if (gJiminyWork->unk_CCC->tiles != 0) {
            DrawSprite(0xC2, 0x5E, gJiminyWork->unk_CCC->sprite,
                gJiminyWork->tiles7, gJiminyWork->palette8, 0, 4, 1);
        }
        if (gJiminyWork->unk_CCC->tiles2 != 0 && gJiminyWork->unk_CCC->sprite2 != 0) {
            DrawSprite(0xC2, 0x5E, gJiminyWork->unk_CCC->sprite2,
                gJiminyWork->tiles8, gJiminyWork->palette9, 0, 4, 0);
        }
        break;
    case 2:
        if (gJiminyWork->unk_CCC->tiles != 0) {
            DrawSprite(gJiminyWork->unk_CCC->x + 0xC4, gJiminyWork->unk_CCC->y + 0x74,
                gJiminyWork->unk_CCC->sprite, gJiminyWork->tiles7, gJiminyWork->palette8, 0, 4, 1);
        }
        if (gJiminyWork->unk_CCC->tiles2 != 0) {
            DrawSprite(0x14, 0x25, gJiminyWork->unk_CCC->sprite2,
                gJiminyWork->tiles8, gJiminyWork->palette9, 0, 0x404, 0);
        }
        break;
    }
    if ((s16)gJiminyWork->unk_D3C > 0) {
        gJiminyWork->unk_D3C--;
    }
    UpdatePlayTime();
    gJiminyWork->unk_D3E++;
}

void mode_jiminy_2(void) {
    func_08065940();
    ReleaseObjTiles(gJiminyWork->tiles);
    ReleaseObjPalette(gJiminyWork->palette);
    ReleaseObjTiles(gJiminyWork->tiles2);
    ReleaseObjPalette(gJiminyWork->palette2);
    ReleaseObjPalette(gJiminyWork->palette3);
    ReleaseObjTiles(gJiminyWork->tiles3);
    ReleaseObjPalette(gJiminyWork->palette4);
    ReleaseObjTiles(gJiminyWork->tiles4);
    ReleaseObjPalette(gJiminyWork->palette5);
    ReleaseObjTiles(gJiminyWork->tiles5);
    ReleaseObjPalette(gJiminyWork->palette6);
    ReleaseObjTiles(gJiminyWork->tiles6);
    ReleaseObjPalette(gJiminyWork->palette7);
    ReleaseObjTiles(gJiminyWork->tiles7);
    ReleaseObjPalette(gJiminyWork->palette8);
    ReleaseObjTiles(gJiminyWork->tiles8);
    ReleaseObjPalette(gJiminyWork->palette9);
    func_0805A484();
    EwramFree(gJiminyWork);
}
