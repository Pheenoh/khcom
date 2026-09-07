#include "macros.h"
#include "btl2.h"
#include "gba/keys.h"

#ifdef VERSION_EU
extern u32 gLanguage;
extern u8 gUnkEu_08B51BA8[];
extern void* gUnkEu_09F5C1FC[];
#endif

void task_btl_shadow_0(BtlShadowWork* work, BtlWork* actor) {
    work->actor = actor;

    if (actor->unk_034 & 0x80000) {
        work->tiles = LoadObjTiles(gUnk_08B22CE4, 0x200);
        work->gfx = gUnk_08B22CBC;
    } else if (actor->unk_034 & 0x20000) {
        work->tiles = LoadObjTiles(gUnk_08B22EFE, 0x140);
        work->gfx = gUnk_08B22EE4;
    } else {
        work->tiles = LoadObjTiles(gUnk_08B22BBC, 0x100);
        work->gfx = gUnk_08B22BA8;
    }
    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);
}

s32 task_btl_shadow_1(void) {
    return 1;
}

void task_btl_shadow_2(BtlShadowWork* work) {
    BtlWork* actor = work->actor;
    s16 x;
    s16 y;
    u16 anim;
    s32 aff;

    if (actor->unk_0CC != 0) {
        if (!(actor->unk_034 & 0x0000000402000000)) {
            anim = func_0801AF1C(actor->unk_008);

            if (actor->unk_00C >= 0 && gBtlWork->unk_024 == 0x100) {
                aff = 0;
            } else {
                s32 sc = 0x100 - (actor->unk_010 - actor->unk_00C) / 128;
                sc = (gBtlWork->unk_024 * sc) >> 8;
                if (sc <= 127) {
                    sc = 128;
                }
                aff = AllocObjAffine(0, sc, sc, sc > 0x100);
            }
            WorldToScreen(&x, &y, actor->unk_004, actor->unk_008, actor->unk_010);
            DrawSprite(x, y, work->gfx, work->tiles, work->palette, aff, anim, actor->unk_0CC);
        }
    }
}

void task_btl_shadow_3(BtlShadowWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_btl_hpply_0(BtlHpplyWork* work) {
    if (gGameState.flags & 8) {
        work->palette = LoadObjPalette(gUnk_09618118, 0x20);
        work->tiles = AllocObjTiles(0x280, gUnk_08B21438);
        work->gfx = gUnk_08B213F0;
        AnimInit(&work->unk_44, gUnk_09EE12C8, gUnk_09EE12BC);
    } else {
        work->palette = LoadObjPalette(gUnk_08F683A4, 0x20);
        work->tiles = AllocObjTiles(0x280, gUnk_08B20D6E);
        work->gfx = gUnk_08B20D20;
        AnimInit(&work->unk_44, gUnk_09EE12B0, gUnk_09EE12A4);
    }

    work->palette2 = LoadObjPalette(gUnk_08F69BA4, 0x20);
    work->tiles2 = AllocObjTiles(0x280, gUnk_08B24016);
    work->tiles3 = AllocObjTiles(0x120, gUnk_08B24016);
    work->tiles4 = AllocObjTiles(0x80, gUnk_08B24016);
    work->gfx2 = gUnk_08B23CBA;
    AnimInit(&work->unk_2C, gUnk_09EE1498, gUnk_09EE1420);
    AnimStart(&work->unk_44, 0, 1);

    if (gBtlWork->unk_07C->unk_02E <= 40) {
        work->unk_64 = 0;
        work->unk_68 = 0;
    } else if (gBtlWork->unk_07C->unk_02E <= 80) {
        work->unk_64 = 1;
        work->unk_68 = 0;
    } else if (gBtlWork->unk_07C->unk_02E <= 120) {
        work->unk_64 = 2;
        work->unk_68 = 0;
    } else if (gBtlWork->unk_07C->unk_02E <= 160) {
        work->unk_64 = 3;
        work->unk_68 = 0;
    } else if (gBtlWork->unk_07C->unk_02E <= 200) {
        work->unk_64 = 4;
        work->unk_68 = 0;
    } else if (gBtlWork->unk_07C->unk_02E <= 240) {
        work->unk_64 = 5;
        work->unk_68 = 0;
    } else if (gBtlWork->unk_07C->unk_02E <= 280) {
        work->unk_64 = 6;
        work->unk_68 = 0;
    } else if (gBtlWork->unk_07C->unk_02E <= 320) {
        work->unk_64 = 0;
        work->unk_68 = 1;
    } else if (gBtlWork->unk_07C->unk_02E <= 360) {
        work->unk_64 = 1;
        work->unk_68 = 1;
    } else if (gBtlWork->unk_07C->unk_02E <= 400) {
        work->unk_64 = 2;
        work->unk_68 = 1;
    } else if (gBtlWork->unk_07C->unk_02E <= 440) {
        work->unk_64 = 3;
        work->unk_68 = 1;
    } else if (gBtlWork->unk_07C->unk_02E <= 480) {
        work->unk_64 = 4;
        work->unk_68 = 1;
    } else if (gBtlWork->unk_07C->unk_02E <= 520) {
        work->unk_64 = 5;
        work->unk_68 = 1;
    } else if (gBtlWork->unk_07C->unk_02E <= 560) {
        work->unk_64 = 6;
        work->unk_68 = 1;
    } else {
        work->unk_64 = 6;
        work->unk_68 = 1;
    }

    if (work->unk_68 == 0) {
        switch (work->unk_64) {
        case 0:
        case 1:
            AnimStart(&work->unk_2C, 1, 1);
            break;
        case 2:
            AnimStart(&work->unk_2C, 3, 1);
            break;
        case 3:
            AnimStart(&work->unk_2C, 5, 1);
            break;
        case 4:
            AnimStart(&work->unk_2C, 7, 1);
            break;
        case 5:
            AnimStart(&work->unk_2C, 9, 1);
            break;
        case 6:
            AnimStart(&work->unk_2C, 11, 1);
            break;
        default:
            AnimStart(&work->unk_2C, 11, 1);
            break;
        }
        work->gfx3 = 0;
    } else {
        AnimStart(&work->unk_2C, 11, 1);

        switch (work->unk_64) {
        case 0:
            work->gfx3 = gUnk_08B23E7C;
            break;
        case 1:
            work->gfx3 = gUnk_08B23E8C;
            break;
        case 2:
            work->gfx3 = gUnk_08B23E9C;
            break;
        case 3:
            work->gfx3 = gUnk_08B23EAC;
            break;
        case 4:
            work->gfx3 = gUnk_08B23EBC;
            break;
        case 5:
            work->gfx3 = gUnk_08B23ED2;
            break;
        case 6:
            work->gfx3 = gUnk_08B23EE8;
            break;
        default:
            work->gfx3 = gUnk_08B23EE8;
            break;
        }
    }

    work->unk_00 = 0x100;
    work->unk_04 = 1;
    work->unk_5C = 1;
    work->unk_5E = 0;
    work->unk_60 = 0;
    work->unk_62 = 0;
    work->unk_5D = 0;
}

s32 task_btl_hpply_1(BtlHpplyWork* work) {
    BtlWork* actor;
    s32 flag;

    actor = gBtlWork->unk_07C;
    if (actor == 0) {
        return 0;
    }

    if (gBtlWork->unk_068 & 0x2000) {
        return 0;
    }

    if (work->unk_68 != 1 && work->unk_00 <= 63) {
        flag = 1;
    } else {
        flag = 0;
    }

    if (actor->unk_02C < work->unk_60) {
        work->unk_5E = 44;
    }

    if (work->unk_5E != 0) {
        AnimChange(&work->unk_44, 1, 1);
        work->unk_5E--;
    } else if (flag != 0) {
        AnimChange(&work->unk_44, 2, 1);
    } else {
        AnimChange(&work->unk_44, 0, 1);
    }

    if (work->unk_04 != 0) {
        work->unk_04 = 0;
        work->unk_62 = actor->unk_02C;
    } else if (work->unk_62 < actor->unk_02C) {
        work->unk_62 += 3;
        if (work->unk_62 > actor->unk_02C) {
            work->unk_62 = actor->unk_02C;
        }
    } else if (work->unk_62 > actor->unk_02C) {
        work->unk_62 -= 3;
        if (work->unk_62 < actor->unk_02C) {
            work->unk_62 = actor->unk_02C;
        }
    }

    if (work->unk_68 == 1) {
        if (work->unk_62 <= 280) {
            work->unk_68 = 2;
        }
    } else if (work->unk_68 == 2) {
        if (work->unk_62 > 280) {
            work->unk_68 = 1;
        }
    }

    switch (work->unk_68) {
    case 0:
        work->unk_00 = (work->unk_62 << 8) / actor->unk_02E;
        break;
    case 1:
        work->unk_00 = ((work->unk_62 - 280) << 8) / (actor->unk_02E - 280);
        break;
    case 2:
        work->unk_00 = (work->unk_62 << 8) / 280;
        break;
    }

    if (flag != 0) {
        if (work->unk_5D == 0) {
            work->unk_5D = 1;
            m4aSongNumStart(0x92);
        }

        if (work->unk_68 == 0) {
            switch (work->unk_64) {
            case 0:
            case 1:
                AnimChange(&work->unk_2C, 2, 1);
                break;
            case 2:
                AnimChange(&work->unk_2C, 4, 1);
                break;
            case 3:
                AnimChange(&work->unk_2C, 6, 1);
                break;
            case 4:
                AnimChange(&work->unk_2C, 8, 1);
                break;
            case 5:
                AnimChange(&work->unk_2C, 10, 1);
                break;
            case 6:
                AnimChange(&work->unk_2C, 12, 1);
                break;
            default:
                AnimChange(&work->unk_2C, 12, 1);
                break;
            }
        } else {
            AnimChange(&work->unk_2C, 12, 1);
        }
    } else {
        if (work->unk_68 == 0) {
            switch (work->unk_64) {
            case 0:
            case 1:
                AnimChange(&work->unk_2C, 1, 1);
                break;
            case 2:
                AnimChange(&work->unk_2C, 3, 1);
                break;
            case 3:
                AnimChange(&work->unk_2C, 5, 1);
                break;
            case 4:
                AnimChange(&work->unk_2C, 7, 1);
                break;
            case 5:
                AnimChange(&work->unk_2C, 9, 1);
                break;
            case 6:
                AnimChange(&work->unk_2C, 11, 1);
                break;
            default:
                AnimChange(&work->unk_2C, 11, 1);
                break;
            }
        } else {
            AnimChange(&work->unk_2C, 11, 1);
        }

        if (work->unk_5D != 0) {
            work->unk_5D = 0;
            m4aSongNumStop(0x92);
        }
    }

    work->gfx = AnimUpdate(&work->unk_44);
    work->gfx2 = AnimUpdate(&work->unk_2C);
    work->unk_60 = actor->unk_02C;
    return 1;
}

void task_btl_hpply_2(BtlHpplyWork* work) {
    s32 v;
    s32 aff;

    DrawSprite(4, 2, work->gfx, work->tiles, work->palette, 0, 0x410, 1);

    switch (work->unk_68) {
    case 0:
        DrawSprite(4, 2, work->gfx2, work->tiles2, work->palette2, 0, 0x410, 4);
        break;
    case 1:
        DrawSprite(4, 2, gUnk_08B23F08, work->tiles2, work->palette2, 0, 0x410, 4);
        DrawSprite(4, 2, work->gfx3, work->tiles3, work->palette2, 0, 0x410, 3);
        break;
    case 2:
        DrawSprite(4, 2, work->gfx2, work->tiles2, work->palette2, 0, 0x410, 4);
        DrawSprite(4, 2, work->gfx3, work->tiles3, work->palette2, 0, 0x410, 5);
        break;
    }

    switch (work->unk_68) {
    case 2:
        v = work->unk_00;
        break;
    case 0:
        switch (work->unk_64) {
        case 0:
        case 1:
            v = (work->unk_00 * 72) >> 8;
            break;
        case 2:
            v = (work->unk_00 * 109) >> 8;
            break;
        case 3:
            v = (work->unk_00 * 146) >> 8;
            break;
        case 4:
            v = (work->unk_00 * 182) >> 8;
            break;
        case 5:
            v = (work->unk_00 * 219) >> 8;
            break;
        case 6:
            v = work->unk_00;
            break;
        default:
            v = work->unk_00;
            break;
        }
        break;
    case 1:
    default:
        switch (work->unk_64) {
        case 0:
            v = (work->unk_00 * 36) >> 8;
            break;
        case 1:
            v = (work->unk_00 * 72) >> 8;
            break;
        case 2:
            v = (work->unk_00 * 109) >> 8;
            break;
        case 3:
            v = (work->unk_00 * 146) >> 8;
            break;
        case 4:
            v = (work->unk_00 * 182) >> 8;
            break;
        case 5:
            v = (work->unk_00 * 219) >> 8;
            break;
        case 6:
            v = work->unk_00;
            break;
        default:
            v = work->unk_00;
            break;
        }
        break;
    }

    v *= 2;

    if (work->unk_62 > 0) {
        if (v <= 9) {
            v = 10;
        }

        if (v > 0x100) {
            aff = AllocObjAffine(0, v, 0x100, 1);
        } else {
            aff = AllocObjAffine(0, v, 0x100, 0);
        }

        if (work->unk_68 == 1) {
            DrawSprite(31, 9, gUnk_08B23EFE, work->tiles4, work->palette2, aff, 0x410, 2);
        } else {
            DrawSprite(31, 6, gUnk_08B23CB0, work->tiles4, work->palette2, aff, 0x410, 2);
        }
    }
}

void task_btl_hpply_3(BtlHpplyWork* work) {
    m4aSongNumStop(0x92);
    ReleaseObjTiles(work->tiles);
    ReleaseObjTiles(work->tiles2);
    ReleaseObjTiles(work->tiles3);
    ReleaseObjTiles(work->tiles4);
    ReleaseObjPalette(work->palette2);
    ReleaseObjPalette(work->palette);
}

void task_btl_hpenm_0(BtlHpenmWork* work) {
    work->tiles = AllocObjTiles(0x140, gUnk_08B24DAA);
    work->tiles2 = AllocObjTiles(0x80, gUnk_08B24DAA);
    work->tiles3 = AllocObjTiles(0x20, gUnk_08B24DAA);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);
    work->unk_14 = 0;
    work->unk_10 = 0x100;
    work->unk_18 = 0;
    work->unk_1C = 0;
    work->unk_20 = 0;
}

s32 task_btl_hpenm_1(BtlHpenmWork* work) {
    BtlWork* actor;

    if (gBtlWork->unk_0A0 == 4) {
        return 0;
    }

    if (gBtlWork->unk_068 & 0x800) {
        actor = gUnk_02039B9C->unk_07C;
        work->unk_14 = 1;
    } else {
        if (gBtlWork->unk_078 == 0) {
            if (work->unk_14 != 0) {
                work->unk_14 = 0;
            }
            return 1;
        }
        work->unk_14 = 1;
        actor = gBtlWork->unk_078;
    }

    if (actor->unk_0D8 != 0) {
        actor = actor->unk_0D8;
    }

    if (work->unk_18 != actor) {
        work->unk_18 = actor;
        work->unk_1E = actor->unk_02C;

        if (actor->unk_02E <= 80) {
            work->unk_1C = 0;
        } else if (actor->unk_02E <= 160) {
            work->unk_1C = 1;
        } else if (actor->unk_02E <= 240) {
            work->unk_1C = 2;
        } else if (actor->unk_02E <= 320) {
            work->unk_1C = 3;
        } else if (actor->unk_02E <= 400) {
            work->unk_1C = 4;
        } else if (actor->unk_02E <= 480) {
            work->unk_1C = 5;
        } else if (actor->unk_02E <= 560) {
            work->unk_1C = 6;
        } else {
            work->unk_1C = 7;
        }
    } else if (work->unk_1E < actor->unk_02C) {
        work->unk_1E += 5;
        if (work->unk_1E > actor->unk_02C) {
            work->unk_1E = actor->unk_02C;
        }
    } else if (work->unk_1E > actor->unk_02C) {
        work->unk_1E -= 5;
        if (work->unk_1E < actor->unk_02C) {
            work->unk_1E = actor->unk_02C;
        }
    }

    if (work->unk_1E <= 560) {
        work->unk_20 = 0;
    } else if (work->unk_1E <= 1120) {
        work->unk_20 = 1;
    } else if (work->unk_1E <= 1680) {
        work->unk_20 = 2;
    } else {
        work->unk_20 = 3;
    }

    switch (work->unk_20) {
    case 3:
        work->unk_10 = ((work->unk_1E - 1680) << 8) / 560;
        break;
    case 2:
        work->unk_10 = ((work->unk_1E - 1120) << 8) / 560;
        break;
    case 1:
        work->unk_10 = ((work->unk_1E - 560) << 8) / 560;
        break;
    case 0:
        if (work->unk_1C <= 6) {
            work->unk_10 = (work->unk_1E << 8) / actor->unk_02E;
        } else {
            work->unk_10 = (work->unk_1E << 8) / 560;
        }
        break;
    }

    return 1;
}

#ifndef VERSION_EU
void task_btl_hpenm_2(BtlHpenmWork* work) {
    void* gfx;
    void* bar;
    s32 v;
    s32 aff;

    if (work->unk_14 == 0) {
        return;
    }

    switch (work->unk_20) {
    case 3:
        gfx = gUnk_08B24D58;
        bar = gUnk_08B24D22;
        break;
    case 2:
        gfx = gUnk_08B24D42;
        bar = gUnk_08B24D18;
        break;
    case 1:
        gfx = gUnk_08B24D2C;
        bar = gUnk_08B24D0E;
        break;
    case 0:
    default:
        switch (work->unk_1C) {
        case 0:
        case 1:
            gfx = gUnk_08B24CA2;
            break;
        case 2:
            gfx = gUnk_08B24CB2;
            break;
        case 3:
            gfx = gUnk_08B24CC2;
            break;
        case 4:
            gfx = gUnk_08B24CD2;
            break;
        case 5:
            gfx = gUnk_08B24CE2;
            break;
        case 6:
            gfx = gUnk_08B24CF8;
            break;
        default:
            gfx = gUnk_08B24CF8;
            break;
        }
        bar = gUnk_08B24C98;
        break;
    }

    DrawSprite(236, 2, gfx, work->tiles, work->palette, 0, 0x410, 3);
    DrawSprite(236, 2, gUnk_08B24D6E, work->tiles3, work->palette, 0, 0x410, 1);

    switch (work->unk_1C) {
    case 0:
    case 1:
        v = (work->unk_10 * 72) >> 8;
        break;
    case 2:
        v = (work->unk_10 * 109) >> 8;
        break;
    case 3:
        v = (work->unk_10 * 146) >> 8;
        break;
    case 4:
        v = (work->unk_10 * 182) >> 8;
        break;
    case 5:
        v = (work->unk_10 * 219) >> 8;
        break;
    case 6:
        v = work->unk_10;
        break;
    default:
        v = work->unk_10;
        break;
    }

    v *= 2;

    if (work->unk_1E > 0) {
        if (v <= 9) {
            v = 10;
        }

        if (v > 0x100) {
            aff = AllocObjAffine(0, v, 0x100, 1);
        } else {
            aff = AllocObjAffine(0, v, 0x100, 0);
        }
        DrawSprite(217, 6, bar, work->tiles2, work->palette, aff, 0x410, 2);
    }
}
#else
INCLUDE_ASM("btl2/task_btl_hpenm_2.s");
#endif

void task_btl_hpenm_3(BtlHpenmWork* work) {
    ReleaseObjTiles(work->tiles3);
    ReleaseObjTiles(work->tiles2);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_btl_pause_0(BtlPauseWork* work) {
#ifdef VERSION_EU
    void** p;

    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);

    if (gLanguage <= 2) {
        work->tiles = LoadObjTiles(gUnk_08B1E7F4, 0x180);
        p = gUnk_09EE115C;
    } else {
        work->tiles = LoadObjTiles(gUnkEu_08B51BA8, 0x180);
        p = gUnkEu_09F5C1FC;
    }
    work->gfx = p[0];
    work->gfx2 = p[1];
#else
    work->tiles = LoadObjTiles(gUnk_08B1E7F4, 0x180);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);
    work->gfx = gUnk_09EE115C[0];
    work->gfx2 = gUnk_09EE115C[1];
#endif
    work->unk_10 = 0;
    work->unk_24 = 0;
    work->unk_26 = 0;
    gBtlWork->unk_068 |= 0x04000000;
}

s32 task_btl_pause_1(BtlPauseWork* work) {
    s32 paused;

    if (GetKeysPressed() & 8) {
        if (!(gBtlWork->unk_068 & 0x04000000)) {
            gBtlWork->unk_070 = gBtlWork->unk_070 == 0 ? 1 : 0;
        }
    }

    paused = gBtlWork->unk_070;
    if (paused != 0) {
        if (work->unk_10 == 0) {
            func_080063C4(1);
            work->unk_10 = 1;
            work->x = -0x4000;
            work->y = 0x5000;
            work->x2 = 0x13000;
            work->y2 = 0x5000;
            work->unk_24 = 14;
        m4aMPlayVolumeControl(gMPlayInfo_BGM, 0xFF, 0x80);
        m4aMPlayVolumeControl(gUnk_0203DC90, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203DCD0, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203DEE0, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203DE50, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203DA10, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203DAD0, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203DC50, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203DEA0, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203DA90, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203DD10, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203DF20, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203DDD0, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203DA50, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203DE10, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203DC10, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203D990, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203DB50, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203DBD0, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203DD90, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203D9D0, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203DB90, 0xFF, 0);
        m4aMPlayVolumeControl(gUnk_0203DD50, 0xFF, 0);
        } else {
            ApproachValue(&work->x, 0x7800, work->unk_24);
            ApproachValue(&work->x2, 0x7800, work->unk_24);

            if (work->unk_24 > 1) {
                work->unk_24--;
            }
        }
    } else if (work->unk_10 != 0) {
        m4aMPlayVolumeControl(gMPlayInfo_BGM, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203DC90, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203DCD0, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203DEE0, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203DE50, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203DA10, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203DAD0, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203DC50, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203DEA0, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203DA90, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203DD10, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203DF20, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203DDD0, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203DA50, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203DE10, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203DC10, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203D990, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203DB50, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203DBD0, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203DD90, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203D9D0, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203DB90, 0xFF, 0x100);
        m4aMPlayVolumeControl(gUnk_0203DD50, 0xFF, 0x100);
        work->unk_10 = paused;
        func_080063C4(0);
    }

    return 1;
}

void task_btl_pause_2(BtlPauseWork* work) {
    if (work->unk_10 != 0) {
        DrawSprite(work->x >> 8, work->y >> 8, work->gfx, work->tiles, work->palette, 0, 0, 0);
        DrawSprite(work->x2 >> 8, work->y2 >> 8, work->gfx2, work->tiles, work->palette, 0, 0, 0);
    }
}

void task_btl_pause_3(BtlPauseWork* work) {
    func_080063C4(0);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

#ifndef VERSION_EU
void task_btl_pop_0(BtlPopWork* work, BtlPremireSrc* src) {
    switch (src->unk_12) {
    case 0:
        work->tiles = LoadObjTiles(gUnk_08B1F020, 0x100);
        AnimInit(&work->anim, gUnk_09EE11D0, gUnk_09EE11CC);
        AnimStart(&work->anim, 0, 1);
        break;
    case 1:
        work->tiles = LoadObjTiles(gUnk_08B1ED76, 0x180);
        AnimInit(&work->anim, gUnk_09EE11C0, gUnk_09EE11BC);
        AnimStart(&work->anim, 0, 1);
        break;
    case 2:
        work->tiles = LoadObjTiles(gUnk_08B1EF0C, 0x100);
        AnimInit(&work->anim, gUnk_09EE11C8, gUnk_09EE11C4);
        AnimStart(&work->anim, 0, 1);
        break;
    case 3:
        work->tiles = LoadObjTiles(gUnk_08B1F13A, 0x180);
        AnimInit(&work->anim, gUnk_09EE11D8, gUnk_09EE11D4);
        AnimStart(&work->anim, 0, 1);
        break;
    case 5:
        work->tiles = LoadObjTiles(gUnk_08B1F7AC, 0x500);
        AnimInit(&work->anim, gUnk_09EE1204, gUnk_09EE11F4);
        AnimStart(&work->anim, 0, 1);
        break;
    case 6:
        work->tiles = LoadObjTiles(gUnk_08B1F7AC, 0x500);
        AnimInit(&work->anim, gUnk_09EE1204, gUnk_09EE11F4);
        AnimStart(&work->anim, 2, 1);
        break;
    case 7:
        work->tiles = LoadObjTiles(gUnk_08B1F7AC, 0x500);
        AnimInit(&work->anim, gUnk_09EE1204, gUnk_09EE11F4);
        AnimStart(&work->anim, 1, 1);
        break;
    case 8:
        work->tiles = LoadObjTiles(gUnk_08B1F7AC, 0x500);
        AnimInit(&work->anim, gUnk_09EE1204, gUnk_09EE11F4);
        AnimStart(&work->anim, 3, 1);
        break;
    case 9:
        work->tiles = LoadObjTiles(gUnk_08B1F472, 0x180);
        AnimInit(&work->anim, gUnk_09EE11E8, gUnk_09EE11E4);
        AnimStart(&work->anim, 0, 1);
        break;
    case 10:
        work->tiles = LoadObjTiles(gUnk_08B1F60E, 0x140);
        AnimInit(&work->anim, gUnk_09EE11F0, gUnk_09EE11EC);
        AnimStart(&work->anim, 0, 1);
        break;
    case 4:
    default:
        work->tiles = LoadObjTiles(gUnk_08B1F2D6, 0x180);
        AnimInit(&work->anim, gUnk_09EE11E0, gUnk_09EE11DC);
        AnimStart(&work->anim, 0, 1);
        break;
    }

    work->gfx = AnimGetGfx(&work->anim);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);
    work->x = src->x;
    work->y = src->y;
    work->z = src->z;
    work->unk_30 = 0;
}
#else
INCLUDE_ASM("btl2/task_btl_pop_0.s");
#endif

s32 task_btl_pop_1(BtlPopWork* work) {
    work->z -= 0xC0;

    if (work->unk_30 > 49) {
        return 0;
    }
    work->unk_30++;
    work->gfx = AnimUpdate(&work->anim);
    return 1;
}

void task_btl_pop_2(BtlPopWork* work) {
    s16 x;
    s16 y;

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, work->gfx, work->tiles, work->palette, 0, 16, 5);
}

void task_btl_pop_3(BtlPopWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

#ifndef VERSION_EU
void task_btl_escape_0(BtlEscapeWork* work) {
    work->unk_18 = 0x5A00;
    work->tiles = LoadObjTiles(gUnk_08B1EB1C, 0x240);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);
    work->gfx = gUnk_09EE11A4[0];
    work->gfx2 = gUnk_09EE11A4[2];
    work->gfx3 = gUnk_09EE11A4[1];
    work->unk_14 = 0;
    work->unk_1C = 0;
    work->unk_22 = 0;
    work->unk_20 = 0;
}
#else
INCLUDE_ASM("btl2/task_btl_escape_0.s");
#endif

s32 task_btl_escape_1(BtlEscapeWork* work) {
    if (gBtlWork->unk_068 & 0x0100000000000000) {
        return 0;
    }

    if (!(gBtlWork->unk_068 & 8)) {
        if (work->unk_22 != 0) {
            work->unk_1C = 0;
            work->unk_22 = 0;
            work->unk_20 = 0;
        }
    } else {
        if (work->unk_20 <= 15) {
            work->unk_20++;
            work->unk_22 = 0;
        } else {
            work->unk_22 = 1;
            work->unk_14 = (work->unk_1C << 8) / work->unk_18;

            if (work->unk_1C >= work->unk_18) {
                gGameState.flags |= 0x40;
                gBtlWork->unk_068 |= 0x10;
                gBtlWork->unk_068 |= 0x0000000200000000;
                work->unk_22 = 0;
            } else {
                work->unk_1C += 256;
            }
        }
    }

    return 1;
}

void task_btl_escape_2(BtlEscapeWork* work) {
    BtlWork* actor;
    s16 x;
    s16 y;
    s32 v;
    s32 aff;

    if (work->unk_22 == 0) {
        return;
    }

    actor = gBtlWork->unk_07C;
    if (actor->unk_034 & 4) {
        WorldToScreen(&x, &y, actor->unk_004 - 768, actor->unk_008, actor->unk_00C - 10240);
        DrawSprite(x, y, work->gfx, work->tiles, work->palette, 0, 0, 2);
    } else {
        WorldToScreen(&x, &y, actor->unk_004 - 3072, actor->unk_008, actor->unk_00C - 10240);
        DrawSprite(x, y, work->gfx2, work->tiles, work->palette, 0, 0, 2);
    }

    if (work->unk_14 > 0) {
        v = work->unk_14 * 2;
        if (v > 256) {
            aff = AllocObjAffine(0, v, 256, 1);
        } else {
            aff = AllocObjAffine(0, v, 256, 0);
        }
        DrawSprite(x, y, work->gfx3, work->tiles, work->palette, aff, 0, 1);
    }
}

void task_btl_escape_3(BtlEscapeWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_btl_prize_0(BtlPrizeWork* work, BtlPremireSrc* src) {
    u8 angle;
    s32 spd;

    work->x = src->x;
    work->y = src->y;
    work->z = src->z;
    work->unk_0C = 0;

    if (gBtlWork->unk_128 != 0) {
        gBtlWork->unk_128(&work->x, &work->y, &work->z, &work->unk_0C);
    }

    work->unk_20 = -(GetRandom() % 897 + 768);
    angle = GetRandom();

    work->tiles = LoadObjTiles(gUnk_08B209E0, 0x340);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);
    work->unk_28 = 0;
    work->gfx2 = gUnk_08B208E8;
    work->unk_2C = 3;

    if (src->unk_14 != 0) {
        work->unk_2C = 11;
    }

    switch (src->unk_12) {
    case 0:
        work->gfx = gUnk_08B208F2;
        work->unk_3A = 0;
        work->unk_38 = 1400;
        work->unk_24 = 1280;
        spd = 384;
        break;
    case 1:
        work->gfx = gUnk_08B208FC;
        work->unk_3A = 3;
        work->unk_38 = 0;
        work->unk_24 = 0x300;
        spd = 76;
        break;
    case 2:
        work->gfx = gUnk_08B20906;
        work->unk_3A = 10;
        work->unk_38 = 0;
        work->unk_24 = 0x300;
        spd = 76;
        break;
    case 3:
        work->gfx = gUnk_08B20910;
        work->unk_3A = 0;
        work->unk_38 = 1;
        work->unk_24 = 0x400;
        spd = 128;
        break;
    case 4:
        work->gfx = gUnk_08B2091A;
        work->unk_3A = 0;
        work->unk_38 = 10;
        work->unk_24 = 0x400;
        spd = 128;
        break;
    case 5:
        work->gfx = gUnk_08B20924;
        work->unk_3A = 0;
        work->unk_38 = 60;
        work->unk_24 = 0x400;
        spd = 128;
        break;
    case 6:
        work->gfx = gUnk_08B2092E;
        work->unk_3A = 0;
        work->unk_38 = 5;
        work->unk_24 = 0x400;
        spd = 179;
        break;
    case 7:
        work->gfx = gUnk_08B20938;
        work->unk_3A = 0;
        work->unk_38 = 30;
        work->unk_24 = 0x400;
        spd = 179;
        break;
    case 8:
    default:
        work->gfx = gUnk_08B20942;
        work->unk_3A = 0;
        work->unk_38 = 199;
        work->unk_24 = 0x400;
        spd = 179;
        break;
    }

    work->unk_30 = 0;
    work->unk_34 = 0x100;
    gBtlWork->unk_0B0++;
    work->unk_3C = (gSineTable[angle] * spd) >> 8;
    work->unk_40 = (-gSineTable[angle + 64] * spd) >> 8;

    if (abs(work->unk_3C) <= 50) {
        if (work->unk_3C < 0) {
            work->unk_3C = -(GetRandom() % 78 + 51);
        } else {
            work->unk_3C = GetRandom() % 78 + 51;
        }
    }

    work->unk_48 = gBtlWork->unk_07C;
}

#define DIST(a, b) ((a) - (b) >= 0 ? (a) - (b) : (b) - (a))

s32 task_btl_prize_1(BtlPrizeWork* work) {
    s32 hit;
    s32 near;
    s32 range;
    s32 d1;
    s32 d2;
    s32 vz;
    s32 tx;
    s32 ty;
    s32 tz;
    u64 f;
    u64 bit;

    if (gBtlWork->unk_068 & 0x2000) {
        return 0;
    }

    if (work->unk_30 == 0) {
        if (!(work->unk_2C & 4)) {
            if (gBtlWork->unk_128 != 0) {
                gBtlWork->unk_128(&work->x, &work->y, &work->z, &work->unk_0C);
            }

            work->z += work->unk_20;
            vz = work->unk_20 - 15;
            work->unk_20 = vz + gBtlWork->unk_12C;

            switch (func_0801A8A4(&work->x, &work->y, 0, 0)) {
            case 1:
            case 2:
                work->unk_3C = -work->unk_3C;
                break;
            case 3:
            case 4:
                work->unk_40 = -work->unk_40;
                break;
            }

            work->x += work->unk_3C;
            work->y += work->unk_40;

            if (work->z > work->unk_0C) {
                work->unk_2C &= ~2;
                work->z = work->unk_0C;
                work->unk_20 = -((work->unk_24 >> 1) + GetRandom() % (work->unk_24 - (work->unk_24 >> 1) + 1));
            } else {
                work->unk_2C |= 2;
            }
        }

        if (work->unk_2C & 16) {
            hit = 0;
            f = gBtlWork->unk_068;

            if (f & 0x4000) {
                d1 = DIST(work->x, gBtlWork->unk_07C->unk_004);
                d2 = DIST(work->x, gUnk_02039B9C->unk_07C->unk_004);

                if (d1 == d2) {
                    bit = f & 0x1000;
                    near = bit != 0;
                } else {
                    near = 1;

                    if (d1 < d2) {
                        near = 0;
                    }
                }

                if (near) {
                    if (gUnk_02039B9C->unk_0F4 == 6) {
                        range = 0x10000;
                    } else {
                        range = 0x2800;
                    }

                    if (DIST(gUnk_02039B9C->unk_07C->unk_004, work->x) < range &&
                        DIST(gUnk_02039B9C->unk_07C->unk_008, work->y) < (range >> 1) &&
                        DIST(gUnk_02039B9C->unk_07C->unk_00C, work->z) < 12800) {
                        work->unk_48 = gUnk_02039B9C->unk_07C;
                        hit = 1;
                    } else {
                        if (gBtlWork->unk_0F4 == 6) {
                            range = 0x10000;
                        } else {
                            range = 0x2800;
                        }

                        if (DIST(gBtlWork->unk_07C->unk_004, work->x) < range &&
                            DIST(gBtlWork->unk_07C->unk_008, work->y) < (range >> 1) &&
                            DIST(gBtlWork->unk_07C->unk_00C, work->z) < 12800) {
                            hit = 1;
                        }
                    }
                } else {
                    if (gBtlWork->unk_0F4 == 6) {
                        range = 0x10000;
                    } else {
                        range = 0x2800;
                    }

                    if (DIST(gBtlWork->unk_07C->unk_004, work->x) < range &&
                        DIST(gBtlWork->unk_07C->unk_008, work->y) < (range >> 1) &&
                        DIST(gBtlWork->unk_07C->unk_00C, work->z) < 12800) {
                        hit = 1;
                    } else {
                        if (gUnk_02039B9C->unk_0F4 == 6) {
                            range = 0x10000;
                        } else {
                            range = 0x2800;
                        }

                        if (DIST(gUnk_02039B9C->unk_07C->unk_004, work->x) < range &&
                            DIST(gUnk_02039B9C->unk_07C->unk_008, work->y) < (range >> 1) &&
                            DIST(gUnk_02039B9C->unk_07C->unk_00C, work->z) < 12800) {
                            work->unk_48 = gUnk_02039B9C->unk_07C;
                            hit = 1;
                        }
                    }
                }
            } else {
                if (gBtlWork->unk_0F4 == 6) {
                    range = 0x10000;
                } else {
                    range = 0x2800;
                }

                if (DIST(gBtlWork->unk_07C->unk_004, work->x) < range &&
                    DIST(gBtlWork->unk_07C->unk_008, work->y) < (range >> 1) &&
                    DIST(gBtlWork->unk_07C->unk_00C, work->z) < 12800) {
                    hit = 1;
                }
            }

            if (hit) {
                m4aSongNumStart(0x6B);

                if (gBtlWork->unk_068 & 0x4000) {
                    work->unk_48->unk_02C += work->unk_3A;

                    if (work->unk_48->unk_02C > work->unk_48->unk_02E) {
                        work->unk_48->unk_02C = work->unk_48->unk_02E;
                    }
                } else {
                    work->unk_48->unk_02C += work->unk_3A;

                    if (work->unk_48->unk_02C > work->unk_48->unk_02E) {
                        work->unk_48->unk_02C = work->unk_48->unk_02E;
                    }
                    gGameState.exp += work->unk_38;
                }

                work->unk_30 = 1;
                work->unk_28 = 0;
                work->unk_44 = GetAngle(work->unk_48->unk_004, work->unk_48->unk_008, work->x, work->y);
                work->unk_2C &= ~2;
                work->unk_2C |= 1;
                work->unk_2A = GetRandom() % 6 + 5;
                return 1;
            }

            if (!(work->unk_2C & 8)) {
                if (work->unk_28 > 360 && (work->unk_28 & 3) == 0) {
                    work->unk_2C ^= 1;
                }

                if (work->unk_28 > 420) {
                    return 0;
                }
            }
        } else {
            if (work->unk_28 > 10) {
                work->unk_2C |= 16;
            }
        }

        work->unk_28++;
    } else {
        tx = work->unk_48->unk_004 + ((gSineTable[work->unk_44] * (work->unk_34 << 5)) >> 8);
        ty = work->unk_48->unk_008 + ((-gSineTable[work->unk_44 + 64] * (work->unk_34 << 4)) >> 8);
        tz = work->unk_48->unk_00C - ((work->unk_28 >> 1) << 8);
        work->unk_44 += work->unk_2A;
        work->x += (tx - work->x) >> 2;
        work->y += (ty - work->y) >> 2;
        work->z += (tz - work->z) >> 2;
        work->unk_34 -= 2;

        if (work->unk_28 > 60) {
            return 0;
        }
        work->unk_28++;
    }

    return 1;
}

void task_btl_prize_2(BtlPrizeWork* work) {
    s16 x;
    s16 y;
    s32 aff;

    if (work->unk_2C & 1) {
        s32 pri = 0x800;

        WorldToScreen(&x, &y, work->x, work->y, work->z);
        aff = AllocObjAffine(0, gBtlWork->unk_024, gBtlWork->unk_024, 1);
        DrawSprite(x, y, work->gfx, work->tiles, work->palette, aff, pri,
                   (u16)(-4100 - (work->y >> 8) * 4));

        if (work->unk_2C & 2) {
            WorldToScreen(&x, &y, work->x, work->y, work->unk_0C);
            DrawSprite(x, y, work->gfx2, work->tiles, work->palette, aff, pri, 0xFFFF);
        }
    }
}

void task_btl_prize_3(BtlPrizeWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    gBtlWork->unk_0B0--;
}

void task_btl_premire_0(BtlPremireWork* work, BtlPremireSrc* src) {
    u8 angle;
    s32 spd;

    work->x = src->x;
    work->y = src->y;
    work->z = src->z;
    work->unk_0C = 0;

    if (gBtlWork->unk_128 != 0) {
        gBtlWork->unk_128(&work->x, &work->y, &work->z, &work->unk_0C);
    }

    work->unk_20 = -(GetRandom() % 897 + 768);
    angle = GetRandom();

    work->tiles = LoadObjTiles(gUnk_08B209E0, 0x340);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);
    AnimInit(&work->anim, gUnk_09EE1278, gUnk_09EE1244);
    AnimStart(&work->anim, 10, 1);
    work->gfx = AnimGetGfx(&work->anim);
    work->unk_28 = 0;
    work->gfx2 = gUnk_08B208E8;
    work->unk_2C = 3;

    if (src->unk_14 != 0) {
        work->unk_2C = 11;
    }
    work->unk_24 = 0x400;
    spd = 384;
    work->unk_30 = 0;
    work->unk_34 = 0x100;
    gBtlWork->unk_0B0++;
    work->unk_38 = (gSineTable[angle] * spd) >> 8;
    work->unk_3C = (-gSineTable[angle + 64] * spd) >> 8;
    work->unk_44 = gBtlWork->unk_07C;
}

s32 task_btl_premire_1(BtlPremireWork* work) {
    s32 hit;
    s32 range;
    s32 vz;
    s32 tx;
    s32 ty;
    s32 tz;
    u64 f;

    if (gBtlWork->unk_068 & 0x2000) {
        return 0;
    }

    if (work->unk_30 == 0) {
        if (!(work->unk_2C & 4)) {
            if (gBtlWork->unk_128 != 0) {
                gBtlWork->unk_128(&work->x, &work->y, &work->z, &work->unk_0C);
            }

            work->z += work->unk_20;
            vz = work->unk_20 - 15;
            work->unk_20 = vz + gBtlWork->unk_12C;

            switch (func_0801A8A4(&work->x, &work->y, 0, 0)) {
            case 1:
            case 2:
                work->unk_38 = -work->unk_38;
                break;
            case 3:
            case 4:
                work->unk_3C = -work->unk_3C;
                break;
            }

            work->x += work->unk_38;
            work->y += work->unk_3C;

            if (work->z > work->unk_0C) {
                work->unk_2C &= ~2;
                work->z = work->unk_0C;
                work->unk_20 = -((work->unk_24 >> 1) + GetRandom() % (work->unk_24 - (work->unk_24 >> 1) + 1));
            } else {
                work->unk_2C |= 2;
            }
        }

        if (work->unk_2C & 16) {
            hit = 0;
            f = gBtlWork->unk_068;

            if (f & 0x4000) {
                if (f & 0x1000) {
                    if (gUnk_02039B9C->unk_0F4 == 6) {
                        range = 0x10000;
                    } else {
                        range = 0x2000;
                    }

                    if (DIST(gUnk_02039B9C->unk_07C->unk_004, work->x) < range &&
                        DIST(gUnk_02039B9C->unk_07C->unk_008, work->y) < (range >> 1) &&
                        DIST(gUnk_02039B9C->unk_07C->unk_00C, work->z) < 12800) {
                        work->unk_44 = gUnk_02039B9C->unk_07C;
                        hit = 1;
                    } else {
                        if (gBtlWork->unk_0F4 == 6) {
                            range = 0x10000;
                        } else {
                            range = 0x2000;
                        }

                        if (DIST(gBtlWork->unk_07C->unk_004, work->x) < range &&
                            DIST(gBtlWork->unk_07C->unk_008, work->y) < (range >> 1) &&
                            DIST(gBtlWork->unk_07C->unk_00C, work->z) < 12800) {
                            hit = 1;
                        }
                    }
                } else {
                    if (gBtlWork->unk_0F4 == 6) {
                        range = 0x10000;
                    } else {
                        range = 0x2000;
                    }

                    if (DIST(gBtlWork->unk_07C->unk_004, work->x) < range &&
                        DIST(gBtlWork->unk_07C->unk_008, work->y) < (range >> 1) &&
                        DIST(gBtlWork->unk_07C->unk_00C, work->z) < 12800) {
                        hit = 1;
                    } else {
                        if (gUnk_02039B9C->unk_0F4 == 6) {
                            range = 0x10000;
                        } else {
                            range = 0x2000;
                        }

                        if (DIST(gUnk_02039B9C->unk_07C->unk_004, work->x) < range &&
                            DIST(gUnk_02039B9C->unk_07C->unk_008, work->y) < (range >> 1) &&
                            DIST(gUnk_02039B9C->unk_07C->unk_00C, work->z) < 12800) {
                            work->unk_44 = gUnk_02039B9C->unk_07C;
                            hit = 1;
                        }
                    }
                }
            } else {
                if (gBtlWork->unk_0F4 == 6) {
                    range = 0x10000;
                } else {
                    range = 0x2000;
                }

                if (DIST(gBtlWork->unk_07C->unk_004, work->x) < range &&
                    DIST(gBtlWork->unk_07C->unk_008, work->y) < (range >> 1) &&
                    DIST(gBtlWork->unk_07C->unk_00C, work->z) < 12800) {
                    hit = 1;
                }
            }

            if (hit) {
                m4aSongNumStart(0x6B);
                gBtlWork->unk_068 |= 0x0008000000000000;
                work->unk_28 = 0;
                work->unk_30 = 1;
                work->unk_28 = 0;
                work->unk_40 = GetAngle(work->unk_44->unk_004, work->unk_44->unk_008, work->x, work->y);
                work->unk_2C &= ~2;
                work->unk_2C |= 1;
                work->unk_2A = GetRandom() % 6 + 5;
                work->gfx = AnimUpdate(&work->anim);
                return 1;
            }

            if (!(work->unk_2C & 8)) {
                if (work->unk_28 > 360 && (work->unk_28 & 3) == 0) {
                    work->unk_2C ^= 1;
                }

                if (work->unk_28 > 420) {
                    return 0;
                }
            }
        } else {
            if (work->unk_28 > 10) {
                work->unk_2C |= 16;
            }
        }

        work->unk_28++;
    } else {
        tx = work->unk_44->unk_004 + ((gSineTable[work->unk_40] * (work->unk_34 << 5)) >> 8);
        ty = work->unk_44->unk_008 + ((-gSineTable[work->unk_40 + 64] * (work->unk_34 << 4)) >> 8);
        tz = work->unk_44->unk_00C - ((work->unk_28 >> 1) << 8);
        work->unk_40 += work->unk_2A;
        work->x += (tx - work->x) >> 2;
        work->y += (ty - work->y) >> 2;
        work->z += (tz - work->z) >> 2;
        work->unk_34 -= 2;

        if (work->unk_28 > 60) {
            return 0;
        }

        work->unk_28++;
    }

    work->gfx = AnimUpdate(&work->anim);
    return 1;
}

void task_btl_premire_2(BtlPremireWork* work) {
    s16 x;
    s16 y;
    s32 aff;

    if (work->unk_2C & 1) {
        u16 anim = func_0801AF1C(work->y);

        WorldToScreen(&x, &y, work->x, work->y, work->z);
        aff = AllocObjAffine(0, gBtlWork->unk_024, gBtlWork->unk_024, 1);
        DrawSprite(x, y, work->gfx, work->tiles, work->palette, aff, anim,
                   (u16)(-4100 - (work->y >> 8) * 4));

        if (work->unk_2C & 2) {
            WorldToScreen(&x, &y, work->x, work->y, work->unk_0C);
            DrawSprite(x, y, work->gfx2, work->tiles, work->palette, aff, anim, 0xFFFF);
        }
    }
}

void task_btl_premire_3(BtlPremireWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    gBtlWork->unk_0B0--;
}

void task_btl_start_0(BtlStartWork* work) {
    func_08006778(gUnk_09EDA918, 120, 72);
    func_0800675C(0, 0x200, 0x200);
    SetBgBlend(gBtlWork->unk_1C4, 16, 16);
    func_08019050(1, 0x200, 0x10000, 0x14000);
    func_08006120(0, 60);
    work->unk_00 = 0;
    m4aSongNumStart(0x8F);
    SetBgPriority(gBtlWork->unk_1C4, 0);
}

s32 task_btl_start_1(BtlStartWork* work) {
    if (work->unk_00 <= 20) {
        func_08006120(0, 40);
    }

    switch (work->unk_00) {
    case 34:
        func_08019050(35, 0x100, gBtlWork->unk_010, gBtlWork->unk_014);
        break;
    case 43:
        func_08006120(2, 30);
        break;
    case 74:
        return 0;
    }

    work->unk_00++;
    return 1;
}

void func_08031BC4(FldActor* act) {
    if ((GetKeysHeld() & DPAD_LEFT) && (GetKeysHeld() & DPAD_DOWN)) {
        act->angle = 173;
    } else if ((GetKeysHeld() & DPAD_UP) && (GetKeysHeld() & DPAD_LEFT)) {
        act->angle = 211;
    } else if ((GetKeysHeld() & DPAD_UP) && (GetKeysHeld() & DPAD_RIGHT)) {
        act->angle = 45;
    } else if ((GetKeysHeld() & DPAD_RIGHT) && (GetKeysHeld() & DPAD_DOWN)) {
        act->angle = 83;
    } else if ((GetKeysHeld() & DPAD_DOWN) && GetKeyReleaseTime(DPAD_LEFT) <= 4) {
        act->angle = 173;
    } else if ((GetKeysHeld() & DPAD_DOWN) && GetKeyReleaseTime(DPAD_RIGHT) <= 4) {
        act->angle = 83;
    } else if ((GetKeysHeld() & DPAD_UP) && GetKeyReleaseTime(DPAD_LEFT) <= 4) {
        act->angle = 211;
    } else if ((GetKeysHeld() & DPAD_UP) && GetKeyReleaseTime(DPAD_RIGHT) <= 4) {
        act->angle = 45;
    } else if ((GetKeysHeld() & DPAD_LEFT) && GetKeyReleaseTime(DPAD_UP) <= 4) {
        act->angle = 211;
    } else if ((GetKeysHeld() & DPAD_LEFT) && GetKeyReleaseTime(DPAD_DOWN) <= 4) {
        act->angle = 173;
    } else if ((GetKeysHeld() & DPAD_RIGHT) && GetKeyReleaseTime(DPAD_UP) <= 4) {
        act->angle = 45;
    } else if ((GetKeysHeld() & DPAD_RIGHT) && GetKeyReleaseTime(DPAD_DOWN) <= 4) {
        act->angle = 83;
    } else if (GetKeysHeld() & DPAD_DOWN) {
        act->angle = 128;
    } else if (GetKeysHeld() & DPAD_UP) {
        act->angle = 0;
    } else if (GetKeysHeld() & DPAD_LEFT) {
        act->angle = 192;
    } else if (GetKeysHeld() & DPAD_RIGHT) {
        act->angle = 64;
    }
}

u8 func_08031D74(FldPos* p) {
    FldPos a;
    FldPos b;
    s32 v1;
    s32 v2;

    a = *p;
    b = *p;
    a.y -= 1536;
    b.y += 1536;

    v1 = func_080DFF1C(&a);
    if (v1 > a.unk_0C) {
        a.unk_0C = v1;
    }
    v2 = func_080DFF1C(&b);
    if (v2 > b.unk_0C) {
        b.unk_0C = v2;
    }

    if (func_080DFBDC(&a) != 0) {
        return 1;
    }

    if (func_080DFBDC(&b) != 0) {
        return 1;
    }
    p->unk_0C = v2 > v1 ? v1 : v2;
    return 0;
}

s32 func_08031DF8(FldPos* p) {
    FldPos a;
    FldPos b;
    s32 v1;
    s32 v2;

    a = *p;
    b = *p;
    a.y -= 1536;
    b.y += 1536;
    v1 = func_080DFF1C(&a);
    v2 = func_080DFF1C(&b);
    if (v2 > v1) {
        v2 = v1;
    }
    return v2;
}

u8 func_08031E48(FldPos* p, FldWork* work) {
    FldPos a;
    FldPos b;
    u8 r;

    a = *p;
    b = *p;
    a.y -= 1536;
    b.y += 1536;

    r = _080DFE1C(&a);
    if (r != 0) {
        work->unk_B0 = a.x;
        work->unk_B4 = a.y;
        return r;
    }
    r = _080DFE1C(&b);
    if (r != 0) {
        work->unk_B0 = b.x;
        work->unk_B4 = b.y;
        return r;
    }
    return 0;
}

u8 func_08031EC4(FldActor* act) {
    FldPos a;

    a = act->unk_00;
    a.x += gSineTable[act->angle] * 8;
    a.y -= gSineTable[act->angle + 64] * 8;

    if (func_080DFCDC(&a) != 0) {
        return 1;
    }
    return 0;
}

s32 func_08031F1C(FldWork* work) {
    FldActor* act;
    s32 v;

    act = &gUnk_02039BA0->unk_18;

    if (work->unk_66 & 1) {
        if (act->unk_00.unk_0C < work->unk_78) {
            v = act->unk_00.unk_0C;
        } else {
            v = work->unk_78;
        }

        work->unk_BC = 1;
    } else {
        work->unk_BC = 0;
        v = act->unk_00.unk_0C;
    }

    return v;
}

void func_08031F60(FldActor* act) {
    u8 old = act->angle;

    func_08031BC4(act);

    if (old != act->angle) {
        s32 v;

        if (abs(GetAngleDiff(old, act->angle)) > 100) {
            v = 0;
        } else {
            v = act->unk_10 >> 1;
        }
        act->unk_10 = v;
    }
}

void func_08031F98(FldWork* work, s32 a, s32 b) {
    FldAnimDef* e;
    u16 flags = b;
    s32 idx;

    switch (gUnk_02039BA0->unk_18.angle) {
    case 45:
        idx = 4;
        work->unk_A4 |= 2;
        break;
    case 64:
        idx = 3;
        work->unk_A4 |= 2;
        break;
    case 83:
        idx = 2;
        work->unk_A4 |= 2;
        break;
    case 128:
        idx = 1;
        work->unk_A4 &= 0xFFFD;
        break;
    case 173:
        idx = 2;
        work->unk_A4 &= 0xFFFD;
        break;
    case 192:
        idx = 3;
        work->unk_A4 &= 0xFFFD;
        break;
    case 211:
        idx = 4;
        work->unk_A4 &= 0xFFFD;
        break;
    case 0:
    default:
        idx = 0;
        work->unk_A4 &= 0xFFFD;
        break;
    }

    if (work->unk_A8 == a) {
        flags |= 4;
    }
    work->unk_A8 = a;

    e = &gUnk_0813C89C[a][idx];
    func_08005974(&work->unk_08, e->unk_0C, flags, e->unk_04, e->unk_00);
    func_08002A10(work->tiles, e->unk_08);
}
