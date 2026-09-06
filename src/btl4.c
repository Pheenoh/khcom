#include "macros.h"
#include "btl4.h"

#ifndef VERSION_EU
void task_btl_pop_cb_0(BtlPopCbWork* work, BtlPopSrc* src) {
    work->tiles = AllocObjTiles(0x200, gUnk_08B1FD66);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 32);

    switch (src->unk_12) {
    case 0:
        work->gfx = gUnk_08B1FCBC;
        break;
    case 1:
        work->gfx = gUnk_08B1FCCC;
        break;
    case 2:
        work->gfx = gUnk_08B1FCDC;
        break;
    case 3:
        work->gfx = gUnk_08B1FCEC;
        break;
    case 4:
        work->gfx = gUnk_08B1FCFC;
        break;
    case 5:
        work->gfx = gUnk_08B1FD0C;
        break;
    case 6:
        work->gfx = gUnk_08B1FD1C;
        break;
    case 7:
        work->gfx = gUnk_08B1FD2C;
        break;
    case 8:
        work->gfx = gUnk_08B1FD3C;
        break;
    case 9:
    default:
        work->gfx = gUnk_08B1FD4C;
        break;
    }

    work->x = src->x;
    work->y = src->y;
    work->z = src->z;
    work->unk_18 = 0;
}
#else
INCLUDE_ASM("btl4/task_btl_pop_cb_0.s");
#endif

s32 task_btl_pop_cb_1(BtlPopCbWork* work) {
    work->z -= 192;

    if (work->unk_18 > 49) {
        return 0;
    }

    work->unk_18++;
    return 1;
}

void task_btl_pop_cb_2(BtlPopCbWork* work) {
    s16 x;
    s16 y;

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, work->gfx, work->tiles, work->palette, 0, 16, 5);
}

void task_btl_pop_cb_3(BtlPopCbWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void* func_0805CDC8(s32 digit, u8 leading) {
    switch (digit) {
    case 0:
        if (leading != 0) {
            return gUnk_08B25E6E;
        }
        break;
    case 1:
        return gUnk_08B25E78;
    case 2:
        return gUnk_08B25E82;
    case 3:
        return gUnk_08B25E8C;
    case 4:
        return gUnk_08B25E96;
    case 5:
        return gUnk_08B25EA0;
    case 6:
        return gUnk_08B25EAA;
    case 7:
        return gUnk_08B25EB4;
    case 8:
        return gUnk_08B25EBE;
    case 9:
        return gUnk_08B25EC8;
    }
    return 0;
}

void func_0805CE60(BtlExpWork* work, u32 value) {
    void* d0;
    void* d1;
    void* d2;
    void* d3;
    u8 flag;

    d0 = func_0805CDC8(value / 10000, 0);
    work->unk_24[0] = d0;
    value %= 10000;
    flag = d0 != 0;

    d1 = func_0805CDC8(value / 1000, flag);
    work->unk_24[1] = d1;
    value %= 1000;

    if (d1 != 0) {
        flag = 1;
    }

    d2 = func_0805CDC8(value / 100, flag);
    work->unk_24[2] = d2;
    value %= 100;

    if (d2 != 0) {
        flag = 1;
    }

    d3 = func_0805CDC8(value / 10, flag);
    work->unk_24[3] = d3;
    value %= 10;

    if (d3 != 0) {
        flag = 1;
    }

    work->unk_24[4] = gUnk_09EE157C[value + 4];
    work->unk_24[5] = gUnk_08B25ED2;
}

void task_btl_exp_0(BtlExpWork* work) {
    s32 i;

    work->palette = LoadObjPalette(gUnk_08F69BA4, 32);
#ifdef VERSION_EU
    work->tiles = AllocObjTiles(0xC0, gUnk_08B25EF0);
#else
    work->tiles = AllocObjTiles(0xA0, gUnk_08B25EF0);
#endif
    work->unk_20 = 0;

    for (i = 0; i <= 5; i++) {
        work->unk_08[i] = AllocObjTiles(32, gUnk_08B25EF0);
        work->unk_24[i] = 0;
    }

    work->unk_3C = 0;
    work->unk_3E = gGameState.level;
    work->unk_44 = gGameState.exp;
    work->unk_48 = 0;
    work->unk_40 = 0;
}

#ifndef VERSION_EU
s32 task_btl_exp_1(BtlExpWork* work) {
    if (gBtlWork->unk_068 & 0x2000) {
        return 0;
    }

    if (work->unk_3E < gGameState.level) {
        func_0805CE60(work, gGameState.level);
        work->unk_20 = gUnk_08B25E40;
        work->unk_3C = 0;
        work->unk_48 = 3;
        work->unk_3E = gGameState.level;
        work->unk_40 = 0;
    }

    if (work->unk_48 != 3) {
        if (work->unk_44 < gGameState.exp) {
            work->unk_40 += gGameState.exp - work->unk_44;
            func_0805CE60(work, work->unk_40);
            work->unk_20 = gUnk_08B25E54;
            work->unk_3C = 0;
            work->unk_48 = 1;
            work->unk_44 = gGameState.exp;
        }
    }

    switch (work->unk_48) {
    case 0:
        break;
    case 3:
        if (work->unk_3C > 100) {
            if (gGameState.level > 98) {
                work->unk_48 = 0;
            } else {
                work->unk_48 = 2;
                func_0805CE60(work, gGameState.nextExp - gGameState.exp);
                work->unk_20 = gUnk_08B25E5E;
            }
            work->unk_3C = 0;
            work->unk_40 = 0;
        } else {
            work->unk_3C++;
        }
        break;
    case 1:
        if (work->unk_3C > 60) {
            if (gGameState.level > 98) {
                work->unk_48 = 0;
            } else {
                work->unk_48 = 2;
                func_0805CE60(work, gGameState.nextExp - gGameState.exp);
                work->unk_20 = gUnk_08B25E5E;
            }
            work->unk_3C = 0;
            work->unk_40 = 0;
        } else {
            work->unk_3C++;
        }
        break;
    case 2:
        if (work->unk_3C > 100) {
            work->unk_3C = 0;
            work->unk_48 = 0;
        } else {
            work->unk_3C++;
        }
        break;
    }

    return 1;
}
#else
INCLUDE_ASM("btl4/task_btl_exp_1.s");
#endif

void task_btl_exp_2(BtlExpWork* work) {
    s32 i;
    s16 x;
    u16 y;

    if (work->unk_48 != 0) {
        y = 40;
        x = 0;
        DrawSprite(0, y, work->unk_20, work->tiles, work->palette, x, 0x410, x);

#ifdef VERSION_JP
        x = 32;
#else
        if (work->unk_48 == 2) {
#ifdef VERSION_EU
            x = 48;
#else
            x = 40;
#endif
        } else {
            x = 32;
        }
#endif

        for (i = 0; i <= 5; i++) {
            if (work->unk_24[i] != 0) {
                DrawSprite(x, y, work->unk_24[i], work->unk_08[i], work->palette, 0, 0x410, 0);
                x += 8;
            }
        }
    }
}

void task_btl_exp_3(BtlExpWork* work) {
    s32 i;

    for (i = 0; i < 6; i++) {
        ReleaseObjTiles(work->unk_08[i]);
    }

    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_btl_vslockon_0(BtlVslockonWork* work) {
    work->tiles = LoadObjTiles(gUnk_08B1D8BC, 0x180);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 32);
    AnimInit(&work->anim, gUnk_09EE10F8, gUnk_09EE10EC);
    AnimStart(&work->anim, 0, 1);
    work->gfx = AnimGetGfx(&work->anim);
    gBtlWork->unk_078 = gUnk_02039B9C->unk_07C;
    gUnk_02039B9C->unk_078 = gBtlWork->unk_07C;
}

s32 task_btl_vslockon_1(BtlVslockonWork* work) {
    if (gBtlWork->unk_0F4 == 19) {
        gUnk_02039B9C->unk_078 = 0;
    } else {
        gUnk_02039B9C->unk_078 = gBtlWork->unk_07C;
    }

    if (gUnk_02039B9C->unk_0F4 == 19) {
        gBtlWork->unk_078 = 0;
    } else {
        gBtlWork->unk_078 = gUnk_02039B9C->unk_07C;
    }

    work->gfx = AnimUpdate(&work->anim);
    return 1;
}

void task_btl_vslockon_2(BtlVslockonWork* work) {
    s16 x;
    s16 y;
    BtlWork* p;

    p = gBtlWork->unk_078;
    if (p != 0) {
        WorldToScreen(&x, &y, p->unk_004, p->unk_008, p->unk_00C - (p->unk_0A2 << 8));
        DrawSprite(x, y, work->gfx, work->tiles, work->palette, 0, 0, 0x100);
    }
}

void task_btl_vslockon_3(BtlVslockonWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_btl_hpoth_0(BtlHpothWork* work) {
    work->unk_0C = LoadObjPalette(gUnk_096FAC64, 32);
    work->unk_10 = AllocObjTiles(0x280, gUnk_08B20D6E);
    work->unk_20 = gUnk_08B20D20;
    AnimInit(&work->unk_44, gUnk_09EE12B0, gUnk_09EE12A4);
    work->unk_08 = LoadObjPalette(gUnk_08F69BA4, 32);
    work->unk_14 = AllocObjTiles(0x280, gUnk_08B24016);
    work->unk_18 = AllocObjTiles(0x120, gUnk_08B24016);
    work->unk_1C = AllocObjTiles(0x80, gUnk_08B24016);
    work->unk_24 = gUnk_08B23CBA;
    AnimInit(&work->unk_2C, gUnk_09EE1498, gUnk_09EE1420);
    AnimStart(&work->unk_44, 0, 1);

    if (gUnk_02039B9C->unk_07C->unk_02E <= 40) {
        work->unk_64 = 0;
        work->unk_68 = 0;
    } else if (gUnk_02039B9C->unk_07C->unk_02E <= 80) {
        work->unk_64 = 1;
        work->unk_68 = 0;
    } else if (gUnk_02039B9C->unk_07C->unk_02E <= 120) {
        work->unk_64 = 2;
        work->unk_68 = 0;
    } else if (gUnk_02039B9C->unk_07C->unk_02E <= 160) {
        work->unk_64 = 3;
        work->unk_68 = 0;
    } else if (gUnk_02039B9C->unk_07C->unk_02E <= 200) {
        work->unk_64 = 4;
        work->unk_68 = 0;
    } else if (gUnk_02039B9C->unk_07C->unk_02E <= 240) {
        work->unk_64 = 5;
        work->unk_68 = 0;
    } else if (gUnk_02039B9C->unk_07C->unk_02E <= 280) {
        work->unk_64 = 6;
        work->unk_68 = 0;
    } else if (gUnk_02039B9C->unk_07C->unk_02E <= 320) {
        work->unk_64 = 0;
        work->unk_68 = 1;
    } else if (gUnk_02039B9C->unk_07C->unk_02E <= 360) {
        work->unk_64 = 1;
        work->unk_68 = 1;
    } else if (gUnk_02039B9C->unk_07C->unk_02E <= 400) {
        work->unk_64 = 2;
        work->unk_68 = 1;
    } else if (gUnk_02039B9C->unk_07C->unk_02E <= 440) {
        work->unk_64 = 3;
        work->unk_68 = 1;
    } else if (gUnk_02039B9C->unk_07C->unk_02E <= 480) {
        work->unk_64 = 4;
        work->unk_68 = 1;
    } else if (gUnk_02039B9C->unk_07C->unk_02E <= 520) {
        work->unk_64 = 5;
        work->unk_68 = 1;
    } else if (gUnk_02039B9C->unk_07C->unk_02E <= 560) {
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
        work->unk_28 = 0;
    } else {
        AnimStart(&work->unk_2C, 11, 1);

        switch (work->unk_64) {
        case 0:
            work->unk_28 = gUnk_08B23E7C;
            break;
        case 1:
            work->unk_28 = gUnk_08B23E8C;
            break;
        case 2:
            work->unk_28 = gUnk_08B23E9C;
            break;
        case 3:
            work->unk_28 = gUnk_08B23EAC;
            break;
        case 4:
            work->unk_28 = gUnk_08B23EBC;
            break;
        case 5:
            work->unk_28 = gUnk_08B23ED2;
            break;
        case 6:
        default:
            work->unk_28 = gUnk_08B23EE8;
            break;
        }
    }

    work->unk_00 = 0x100;
    work->unk_04 = 1;
    work->unk_5C = 1;
    work->unk_5E = 0;
    work->unk_60 = 0;
    work->unk_62 = 0;
}

s32 task_btl_hpoth_1(BtlHpothWork* work) {
    BtlWork* actor;
    s32 flag;
    u32 state;

    actor = gUnk_02039B9C->unk_07C;
    if (actor == 0) {
        return 0;
    }

    if (gBtlWork->unk_068 & 0x2000) {
        return 0;
    }

    if (work->unk_68 != 1 && work->unk_00 < 64) {
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

    state = work->unk_68;

    switch (state) {
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
        if (state == 0) {
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
        if (state == 0) {
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
            default:
                AnimChange(&work->unk_2C, 11, 1);
                break;
            }
        } else {
            AnimChange(&work->unk_2C, 11, 1);
        }
    }

    work->unk_20 = AnimUpdate(&work->unk_44);
    work->unk_24 = AnimUpdate(&work->unk_2C);
    work->unk_60 = actor->unk_02C;
    return 1;
}

void task_btl_hpoth_2(BtlHpothWork* work) {
    s32 scale;
    s32 affine;

    DrawSprite(236, 2, work->unk_20, work->unk_10, work->unk_0C, 0, 0x411, 1);

    switch (work->unk_68) {
    case 0:
        DrawSprite(236, 2, work->unk_24, work->unk_14, work->unk_08, 0, 0x411, 4);
        break;
    case 1:
        DrawSprite(236, 2, gUnk_08B23F08, work->unk_14, work->unk_08, 0, 0x411, 4);
        DrawSprite(236, 2, work->unk_28, work->unk_18, work->unk_08, 0, 0x411, 3);
        break;
    case 2:
        DrawSprite(236, 2, work->unk_24, work->unk_14, work->unk_08, 0, 0x411, 4);
        DrawSprite(236, 2, work->unk_28, work->unk_18, work->unk_08, 0, 0x411, 5);
        break;
    }

    switch (work->unk_68) {
    case 2:
        scale = work->unk_00;
        break;
    case 0:
        switch (work->unk_64) {
        case 0:
        case 1:
            scale = work->unk_00 * 72 >> 8;
            break;
        case 2:
            scale = work->unk_00 * 109 >> 8;
            break;
        case 3:
            scale = work->unk_00 * 146 >> 8;
            break;
        case 4:
            scale = work->unk_00 * 182 >> 8;
            break;
        case 5:
            scale = work->unk_00 * 219 >> 8;
            break;
        case 6:
        default:
            scale = work->unk_00;
            break;
        }
        break;
    case 1:
    default:
        switch (work->unk_64) {
        case 0:
            scale = work->unk_00 * 36 >> 8;
            break;
        case 1:
            scale = work->unk_00 * 72 >> 8;
            break;
        case 2:
            scale = work->unk_00 * 109 >> 8;
            break;
        case 3:
            scale = work->unk_00 * 146 >> 8;
            break;
        case 4:
            scale = work->unk_00 * 182 >> 8;
            break;
        case 5:
            scale = work->unk_00 * 219 >> 8;
            break;
        case 6:
        default:
            scale = work->unk_00;
            break;
        }
        break;
    }

    scale *= 2;

    if (work->unk_62 > 0) {
        if (scale < 10) {
            scale = 10;
        }

        if (scale > 256) {
            affine = AllocObjAffine(0, scale, 256, 1);
        } else {
            affine = AllocObjAffine(0, scale, 256, 0);
        }

        if (work->unk_68 == 1) {
            DrawSprite(209, 9, gUnk_08B23F2E, work->unk_1C, work->unk_08, affine, 0x410, 2);
        } else {
            DrawSprite(209, 6, gUnk_08B23F24, work->unk_1C, work->unk_08, affine, 0x410, 2);
        }
    }
}

void task_btl_hpoth_3(BtlHpothWork* work) {
    ReleaseObjTiles(work->unk_10);
    ReleaseObjTiles(work->unk_14);
    ReleaseObjTiles(work->unk_18);
    ReleaseObjTiles(work->unk_1C);
    ReleaseObjPalette(work->unk_08);
    ReleaseObjPalette(work->unk_0C);
}

void func_0805DA64(u16 a) {
    gDispCnt = (gDispCnt & 0xFFF8) | 1;
    func_080A411C(gBtlWork->unk_040, 0, a);
}

void func_0805DA98(u16 a) {
    func_080A41F0(gBtlWork->unk_040, a);
}

void func_0805DAB4(void) {
    gDispCnt = (gDispCnt & 0xFFF8) | 2;
}

void func_0805DACC(BtlEffect* p, u16 b, void* c) {
    p->unk_0C = 0;
    p->unk_04 = 1;
    p->unk_08 = c;
    p->unk_02 = b;
}

void func_0805DADC(BtlEffect* p, u16 b, void* c) {
    p->unk_0C = 0;
    p->unk_04 = 3;
    p->unk_08 = c;
    p->unk_02 = b;
}

void func_0805DAEC(void) {
    func_080A42E0();
}

void func_0805DAF8(BtlEffect* p, u16 b, void* c) {
    p->unk_0C = 0;
    p->unk_04 = 0;
    p->unk_08 = c;
    p->unk_0E = b;
}

void func_0805DB04(BtlEffect* p, u16 b, u16 c, u16 d) {
    p->unk_00 |= 4;
    p->unk_12 = b;
    p->unk_14 = c;
    AnimStart(&p->anim, d, 1);
}

void func_0805DB28(BtlEffect* p) {
    p->unk_00 &= ~4;
}
