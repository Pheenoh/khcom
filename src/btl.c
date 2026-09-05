#include "macros.h"
#include "btl.h"

u8 gUnk_0203492C;
u16 gUnk_0203492E;
s32 gUnk_02034930;

void task_btl_lockon_0(BtlLockonWork* work) {
    work->tiles = LoadObjTiles(gUnk_08B1D8BC, 0x180);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);
    AnimInit(&work->anim, gUnk_09EE10F8, gUnk_09EE10EC);
    AnimStart(&work->anim, 0, 1);
    work->gfx = AnimGetGfx(&work->anim);
    work->unk_024 = 0;
    gBtlWork->unk_078 = 0;
}

void func_0801D288(void) {
    BtlWork* p;
    BtlWork* e;
    s32 min;

    p = gBtlWork->unk_07C;
    min = 0x40000;
    gBtlWork->unk_078 = 0;
    e = ListPoolFirst(&gBtlWork->unk_080);

    if (p->unk_034 & 4) {
        for (; e != 0; e = ListPoolNext(&e->unk_0B8)) {
            if (p->unk_004 < e->unk_004 || p->unk_004 - e->unk_004 > 0x9600 ||
                (p->unk_008 - e->unk_008 >= 0 ? p->unk_008 - e->unk_008 > 0x1800
                                              : e->unk_008 - p->unk_008 > 0x1800) ||
                (p->unk_00C - e->unk_00C >= 0 ? p->unk_00C - e->unk_00C > 0x6400
                                              : e->unk_00C - p->unk_00C > 0x6400) ||
                (e->unk_034 & 0x1000000) || p->unk_004 - e->unk_004 >= min) {
                continue;
            }
            gBtlWork->unk_078 = e;
            min = p->unk_004 - e->unk_004;
        }

        if (gBtlWork->unk_078 == 0) {
            min = 0x40000;
            e = ListPoolFirst(&gBtlWork->unk_080);

            for (; e != 0; e = ListPoolNext(&e->unk_0B8)) {
                if (p->unk_004 > e->unk_004 || e->unk_004 - p->unk_004 > 0x5A00 ||
                    (p->unk_008 - e->unk_008 >= 0 ? p->unk_008 - e->unk_008 > 0x1800
                                                  : e->unk_008 - p->unk_008 > 0x1800) ||
                    (p->unk_00C - e->unk_00C >= 0 ? p->unk_00C - e->unk_00C > 0x6400
                                                  : e->unk_00C - p->unk_00C > 0x6400) ||
                    (e->unk_034 & 0x1000000) || e->unk_004 - p->unk_004 >= min) {
                    continue;
                }
                gBtlWork->unk_078 = e;
                min = e->unk_004 - p->unk_004;
            }
        }
    } else {
        for (; e != 0; e = ListPoolNext(&e->unk_0B8)) {
            if (p->unk_004 > e->unk_004 || e->unk_004 - p->unk_004 > 0x9600 ||
                (p->unk_008 - e->unk_008 >= 0 ? p->unk_008 - e->unk_008 > 0x1800
                                              : e->unk_008 - p->unk_008 > 0x1800) ||
                (p->unk_00C - e->unk_00C >= 0 ? p->unk_00C - e->unk_00C > 0x6400
                                              : e->unk_00C - p->unk_00C > 0x6400) ||
                (e->unk_034 & 0x1000000) || e->unk_004 - p->unk_004 >= min) {
                continue;
            }
            gBtlWork->unk_078 = e;
            min = e->unk_004 - p->unk_004;
        }

        if (gBtlWork->unk_078 == 0) {
            min = 0x40000;
            e = ListPoolFirst(&gBtlWork->unk_080);

            for (; e != 0; e = ListPoolNext(&e->unk_0B8)) {
                if (p->unk_004 < e->unk_004 || p->unk_004 - e->unk_004 > 0x5A00 ||
                    (p->unk_008 - e->unk_008 >= 0 ? p->unk_008 - e->unk_008 > 0x1800
                                                  : e->unk_008 - p->unk_008 > 0x1800) ||
                    (p->unk_00C - e->unk_00C >= 0 ? p->unk_00C - e->unk_00C > 0x6400
                                                  : e->unk_00C - p->unk_00C > 0x6400) ||
                    (e->unk_034 & 0x1000000) || p->unk_004 - e->unk_004 >= min) {
                    continue;
                }
                gBtlWork->unk_078 = e;
                min = p->unk_004 - e->unk_004;
            }
        }
    }
}

u8 task_btl_lockon_1(BtlLockonWork* work) {
    if ((gBtlWork->unk_068 & 0x20000000) == 0) {
        func_0801D288();
    }

    if (gBtlWork->unk_078 != 0) {
        work->gfx = AnimUpdate(&work->anim);

        if (gBtlWork->unk_078->unk_034 & 0x1000000) {
            gBtlWork->unk_078 = 0;
        }
    }

    if (work->unk_024 != 0) {
        work->unk_024--;
    }
    return 1;
}

void task_btl_lockon_2(BtlLockonWork* work) {
    BtlWork* e;
    s16 x;
    s16 y;

    e = gBtlWork->unk_078;
    if (e != 0) {
        WorldToScreen(&x, &y, e->unk_004 + (e->unk_0A4 << 8), e->unk_008,
                      e->unk_00C - (e->unk_0A2 << 8));
        DrawSprite(x, y, work->gfx, work->tiles, work->palette, 0, 16, 16);
    }
}

void task_btl_lockon_3(BtlLockonWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_btl_area_0(BtlAreaWork* work) {
    work->unk_008 = 0;
    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);
    work->tiles = LoadObjTiles(gUnk_08B1EA00, 0xE0);
    work->unk_00A = 0;
    work->unk_009 = 1;
}

u8 task_btl_area_1(BtlAreaWork* work) {
    if (work->unk_009 == 0) {
        work->unk_008 = 0;
        return 1;
    }

    if (gBtlWork->unk_0B4 != 0) {
        work->unk_00A = 20;
        gBtlWork->unk_0B4 = 0;
    }

    if (work->unk_00A > 0) {
        work->unk_008 = 1;
    } else {
        work->unk_008 = 0;
    }

    if (work->unk_00A > 0) {
        work->unk_00A--;
    }
    return 1;
}

void task_btl_area_2(BtlAreaWork* work) {
    BtlWork* e;
    s16 x;
    s16 y;

    if (work->unk_008 == 0) {
        return;
    }

    WorldToScreen(&x, &y, gBtlWork->unk_0B8 - (gBtlWork->unk_0C4 << 8),
                  gBtlWork->unk_0BC - (gBtlWork->unk_0C6 << 8), gBtlWork->unk_0C0);
    DrawSprite(x, y, gUnk_08B1E974, work->tiles, work->palette, 0, 0, 0x101);
    WorldToScreen(&x, &y, gBtlWork->unk_0B8 + (gBtlWork->unk_0C4 << 8),
                  gBtlWork->unk_0BC - (gBtlWork->unk_0C6 << 8), gBtlWork->unk_0C0);
    DrawSprite(x, y, gUnk_08B1E97E, work->tiles, work->palette, 0, 0, 0x101);
    WorldToScreen(&x, &y, gBtlWork->unk_0B8 - (gBtlWork->unk_0C4 << 8),
                  gBtlWork->unk_0BC + (gBtlWork->unk_0C6 << 8), gBtlWork->unk_0C0);
    DrawSprite(x, y, gUnk_08B1E992, work->tiles, work->palette, 0, 0, 0x101);
    WorldToScreen(&x, &y, gBtlWork->unk_0B8 + (gBtlWork->unk_0C4 << 8),
                  gBtlWork->unk_0BC + (gBtlWork->unk_0C6 << 8), gBtlWork->unk_0C0);
    DrawSprite(x, y, gUnk_08B1E988, work->tiles, work->palette, 0, 0, 0x101);
    WorldToScreen(&x, &y, gBtlWork->unk_0B8, gBtlWork->unk_0BC, gBtlWork->unk_0C0);
    DrawSprite(x, y, gUnk_08B1E9A6, work->tiles, work->palette, 0, 0, 0x101);
    WorldToScreen(&x, &y, gBtlWork->unk_0B8, gBtlWork->unk_0BC,
                  gBtlWork->unk_0C0 - (gBtlWork->unk_0C8 << 8));
    DrawSprite(x, y, gUnk_08B1E99C, work->tiles, work->palette, 0, 0, 0x101);
    WorldToScreen(&x, &y, gBtlWork->unk_0B8, gBtlWork->unk_0BC,
                  gBtlWork->unk_0C0 + (gBtlWork->unk_0C8 << 8));
    DrawSprite(x, y, gUnk_08B1E99C, work->tiles, work->palette, 0, 2, 0x101);

    if ((u8)gBtlWork->unk_0A4 != 0) {
        e = ListPoolFirst(&gBtlWork->unk_080);

        while (e != 0) {
            WorldToScreen(&x, &y, e->unk_004 - (e->unk_09E << 8),
                          e->unk_008 - (e->unk_0A0 << 8), e->unk_00C);
            DrawSprite(x, y, gUnk_08B1E974, work->tiles, work->palette, 0, 0, 0x101);
            WorldToScreen(&x, &y, e->unk_004 + (e->unk_09E << 8),
                          e->unk_008 - (e->unk_0A0 << 8), e->unk_00C);
            DrawSprite(x, y, gUnk_08B1E97E, work->tiles, work->palette, 0, 0, 0x101);
            WorldToScreen(&x, &y, e->unk_004 - (e->unk_09E << 8),
                          e->unk_008 + (e->unk_0A0 << 8), e->unk_00C);
            DrawSprite(x, y, gUnk_08B1E992, work->tiles, work->palette, 0, 0, 0x101);
            WorldToScreen(&x, &y, e->unk_004 + (e->unk_09E << 8),
                          e->unk_008 + (e->unk_0A0 << 8), e->unk_00C);
            DrawSprite(x, y, gUnk_08B1E988, work->tiles, work->palette, 0, 0, 0x101);
            WorldToScreen(&x, &y, e->unk_004, e->unk_008, e->unk_00C);
            DrawSprite(x, y, gUnk_08B1E9A6, work->tiles, work->palette, 0, 0, 0x101);
            WorldToScreen(&x, &y, e->unk_004, e->unk_008,
                          e->unk_00C - (e->unk_09C << 8));
            DrawSprite(x, y, gUnk_08B1E99C, work->tiles, work->palette, 0, 0, 0x101);
            e = ListPoolNext(&e->unk_0B8);
        }
    } else {
        e = gBtlWork->unk_07C;
        WorldToScreen(&x, &y, e->unk_004 - (e->unk_09E << 8),
                      e->unk_008 - (e->unk_0A0 << 8), e->unk_00C);
        DrawSprite(x, y, gUnk_08B1E974, work->tiles, work->palette, 0, 0, 0x101);
        WorldToScreen(&x, &y, e->unk_004 + (e->unk_09E << 8),
                      e->unk_008 - (e->unk_0A0 << 8), e->unk_00C);
        DrawSprite(x, y, gUnk_08B1E97E, work->tiles, work->palette, 0, 0, 0x101);
        WorldToScreen(&x, &y, e->unk_004 - (e->unk_09E << 8),
                      e->unk_008 + (e->unk_0A0 << 8), e->unk_00C);
        DrawSprite(x, y, gUnk_08B1E992, work->tiles, work->palette, 0, 0, 0x101);
        WorldToScreen(&x, &y, e->unk_004 + (e->unk_09E << 8),
                      e->unk_008 + (e->unk_0A0 << 8), e->unk_00C);
        DrawSprite(x, y, gUnk_08B1E988, work->tiles, work->palette, 0, 0, 0x101);
        WorldToScreen(&x, &y, e->unk_004, e->unk_008, e->unk_00C);
        DrawSprite(x, y, gUnk_08B1E9A6, work->tiles, work->palette, 0, 0, 0x101);
        WorldToScreen(&x, &y, e->unk_004, e->unk_008,
                      e->unk_00C - (e->unk_09C << 8));
        DrawSprite(x, y, gUnk_08B1E99C, work->tiles, work->palette, 0, 0, 0x101);
    }
}

void task_btl_area_3(BtlAreaWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void func_0801DC40(BtlSoraWork* work) {
    u16 a = work->unk_15A | 0x80;
    u16 b;

    work->unk_15A = a;
    b = work->unk_040.unk_70 | 2;
    work->unk_040.unk_70 = b;
}

void func_0801DC5C(BtlSoraWork* work) {
    u16 a = work->unk_15A & 0xFF7F;
    u16 b;

    work->unk_15A = a;
    b = work->unk_040.unk_70 & 0xFFFD;
    work->unk_040.unk_70 = b;
}

u16 func_0801DC80(BtlSoraWork* work) {
    BtlWork* a;
    BtlWork* b;
    s32 d;

    a = work->unk_040.unk_E4->unk_07C;
    b = work->unk_040.unk_E4->unk_078;

    if (work->unk_040.unk_E4->unk_068 & 0x8000) {
        return 3;
    }

    if (b == 0) {
        return 0;
    }

    if (a->unk_00C - b->unk_00C > 0x2000) {
        return 2;
    }
    d = b->unk_004 - a->unk_004;
    if (d >= 0 ? d > 0x2800 : a->unk_004 - b->unk_004 > 0x2800) {
        return 1;
    }
    d = b->unk_008 - a->unk_008;
    if (d >= 0 ? d > 0xC00 : a->unk_008 - b->unk_008 > 0xC00) {
        return 4;
    }
    return 0;
}

void func_0801DD08(BtlSoraWork* work) {
    BtlWork* c;
    s32 x;
    s32 y;
    s32 z;

    if (work->unk_172 == 0) {
        return;
    }
    c = work->unk_040.unk_E4->unk_078;
    if (c != 0) {
        if (gBtlWork->unk_068 & 0x4000) {
            x = (work->unk_040.unk_04 + c->unk_004) >> 1;
            x = (work->unk_040.unk_04 + x) >> 1;
            y = work->unk_040.unk_08;
            z = work->unk_040.unk_0C;
            if (z < -0x3200) {
                z = -0x3200;
            }
        } else {
            x = (work->unk_040.unk_04 + c->unk_004) >> 1;
            y = (work->unk_040.unk_08 + c->unk_008) >> 1;
            z = (work->unk_040.unk_0C + c->unk_00C) >> 1;
        }
        func_0802F284(x, y, z);
    } else {
        func_0802F284(work->unk_040.unk_04, work->unk_040.unk_08, work->unk_040.unk_0C);
    }
}

void func_0801DD90(BtlSoraWork* work) {
    s32 x;
    s32 y;
    s32 z;

    if (work->unk_172 != 0) {
        func_080140C0(&x, &y, &z);
        func_0802F284(x, gBtlWork->unk_07C->unk_008, gBtlWork->unk_07C->unk_00C);
    }
}

void func_0801DDC4(BtlSoraWork* work) {
    if (work->unk_172 != 0) {
        func_0802F284(work->unk_040.unk_04, work->unk_040.unk_08, work->unk_040.unk_0C);
    }
}

void func_0801DDE4(BtlSoraWork* work, u16 a, u16 b) {
    FldAnimDef* e;

    e = &gUnk_0813BA2C[a];
    func_08005974(&work->anim, e->unk_0C, b, e->unk_04, e->unk_00);
    func_08002A10(work->unk_000, e->unk_08);
}

void func_0801DE1C(BtlSoraWork* work, u16 a, u16 b) {
    FldAnimDef* e;
    s32 idx;

    idx = 0;

    switch (((work->unk_160 + 16) & 0xFF) >> 5) {
    case 0:
        idx = 1;
        break;
    case 4:
        idx = 0;
        break;
    case 3:
    case 5:
        idx = 2;
        break;
    case 2:
    case 6:
        idx = 3;
        break;
    case 1:
    case 7:
        idx = 4;
        break;
    }
    e = &gUnk_0813BEFC[a][idx];
    func_08005974(&work->anim, e->unk_0C, b, e->unk_04, e->unk_00);
    func_08002A10(work->unk_000, e->unk_08);
}

void func_0801DEB8(BtlSoraWork* work) {
    work->unk_000 = work->unk_040.unk_E4->unk_110;

    if (work->unk_172 != 0) {
        work->palette = LoadObjPalette(gUnk_08F683A4, 0x20);
    } else {
        work->palette = LoadObjPalette(gUnk_096FAC64, 0x20);
    }
}

void func_0801DEF4(BtlSoraWork* work) {
    if (work->palette != 0) {
        ReleaseObjPalette(work->palette);
    }
    work->unk_000 = 0;
    work->palette = 0;
}

void func_0801DF10(BtlSoraWork* work, u16 a) {
    UnkStruct_0801AF08* p;

    p = &work->unk_040;

    if ((a & 0x10) && (a & 0x40)) {
        work->unk_160 = 0x20;
        p->unk_34 &= ~4;
    } else if ((a & 0x10) && (a & 0x80)) {
        work->unk_160 = 0x60;
        p->unk_34 &= ~4;
    } else if ((a & 0x20) && (a & 0x80)) {
        work->unk_160 = 0xA0;
        p->unk_34 |= 4;
    } else if ((a & 0x20) && (a & 0x40)) {
        work->unk_160 = 0xE0;
        p->unk_34 |= 4;
    } else if (a & 0x40) {
        work->unk_160 = 0;
    } else if (a & 0x10) {
        work->unk_160 = 0x40;
        p->unk_34 &= ~4;
    } else if (a & 0x80) {
        work->unk_160 = 0x80;
    } else if (a & 0x20) {
        work->unk_160 = 0xC0;
        p->unk_34 |= 4;
    }

    if (a & 0xF0) {
        func_0801DE1C(work, 0, 1);

        if (work->anim.timer == 0) {
            switch (work->anim.frame) {
            case 3:
                m4aSongNumStart(work->unk_184[0]);
                break;
            case 7:
                m4aSongNumStart(work->unk_184[1]);
                break;
            }
        }
    } else {
        func_0801DDE4(work, 1, 1);
    }

    if (a & 0xF0) {
        if (p->unk_E4->unk_0F4 == 50) {
            work->unk_15C += 256;
            if (work->unk_15C > 1024) {
                work->unk_15C = 1024;
            }
        } else {
            work->unk_15C += 128;
            if (work->unk_15C > 614) {
                work->unk_15C = 614;
            }
        }
    } else {
        work->unk_15C -= 128;
        if (work->unk_15C < 0) {
            work->unk_15C = 0;
        }
    }
}

INCLUDE_ASM("btl/task_btl_sora_0.s");

void func_0801E4E4(BtlSoraWork* work, u32 a) {
    work->unk_038 = a;
    work->unk_156 = 0;
    work->unk_154 = 0;
    func_0801AF08(&work->unk_040);
}

void func_0801E508(BtlSoraWork* work, u32 a) {
    work->unk_038 = a;
    func_0801AF08(&work->unk_040);
}

void func_0801E518(BtlSoraWork* work) {
    u16 t;

    if (work->unk_038 == 16 && work->unk_161 <= 1) {
        work->unk_161++;
        work->unk_154 = 0;
        work->unk_156 = 0;
    } else {
        switch (func_0801DC80(work)) {
        case 0:
            work->unk_164 = gUnk_0813C1D4;
            work->unk_168 = gUnk_0813C1EC;
            work->unk_16C = gUnk_0813C21C;
            break;
        case 1:
            work->unk_164 = gUnk_0813C1EC;
            work->unk_168 = gUnk_0813C1D4;
            work->unk_16C = gUnk_0813C21C;
            break;
        case 2:
            work->unk_164 = gUnk_0813C24C;
            work->unk_168 = gUnk_0813C264;
            work->unk_16C = gUnk_0813C27C;
            break;
        case 3:
            work->unk_164 = gUnk_0813C234;
            work->unk_168 = gUnk_0813C24C;
            work->unk_16C = gUnk_0813C27C;
            break;
        case 4:
        default:
            work->unk_164 = gUnk_0813C204;
            work->unk_168 = gUnk_0813C1EC;
            work->unk_16C = gUnk_0813C21C;
            break;
        }
        work->unk_038 = 16;
        work->unk_156 = 0;
        work->unk_154 = 0;
        work->unk_161 = 0;
        t = work->unk_15A & 0xFFBF;
        work->unk_15A = t;
    }

    if (work->unk_040.unk_E4->unk_0F4 == 44) {
        work->unk_190 = 0;
    }
}

void func_0801E678(BtlSoraWork* work) {
    work->unk_150 = -work->unk_040.unk_AC * 3;
    work->unk_148 = ((gSineTable[work->unk_040.unk_B0] << 1) * work->unk_040.unk_A8) >> 8;
    work->unk_14C = ((-gSineTable[work->unk_040.unk_B0 + 0x40] << 1) * work->unk_040.unk_A8) >> 8;
}

BtlWork* func_0801E6DC(BtlSoraWork* work) {
    BtlWork* list[10];
    BtlWork* e;
    s16 n;

    if (work->unk_040.unk_E4->unk_078 != 0) {
        return work->unk_040.unk_E4->unk_078;
    }

    if (gBtlWork->unk_068 & 0x4000) {
        if (work->unk_172 != 0) {
            e = gUnk_02039B9C->unk_07C;
        } else {
            e = gBtlWork->unk_07C;
        }

        if (e->unk_02C <= 0) {
            return 0;
        }
        return e;
    }
    n = 0;
    e = ListPoolFirst(&gBtlWork->unk_080);
    if (e != 0) {
        list[0] = e;
        n = 1;
        do {
            e = ListPoolNext(&e->unk_0B8);
            if (e == 0) {
                break;
            }
            list[n] = e;
            n++;
        } while (n <= 9);
    }

    if (n == 0) {
        return 0;
    }
    e = list[GetRandom() % n];
    return e;
}

u16 func_0801E794(u16 a, u16 b, u16 c) {
    u16 d;

    d = b;

    if (a & b) {
        if ((a & c) == 0) {
            a &= ~b;
        }
        a |= c;
    } else if (a & c) {
        a &= ~c;
        a |= d;
    }
    return a;
}

BtlWork* func_0801E7D4(BtlSoraWork* work) {
    if (gBtlWork->unk_068 & 0x4000) {
        if (work->unk_172 != 0) {
            if (gBtlWork->unk_068 & 0x40) {
                return gUnk_02039B9C->unk_07C;
            }
        } else {
            if (gBtlWork->unk_068 & 0x20000000) {
                return gBtlWork->unk_07C;
            }
        }
    } else {
        if (gBtlWork->unk_068 & 0x40) {
            return gBtlWork->unk_0A8;
        }
    }
    return 0;
}

INCLUDE_ASM("btl/task_btl_sora_1.s");
#ifndef VERSION_EU
void task_btl_sora_2(BtlSoraWork* work) {
    UnkStruct_0801AF08* p;
    s32 affine;
    s32 sx;
    s32 sy;
    u16 attr;
    u16 attr2;
    s16 x;
    s16 y;

    p = &work->unk_040;

    if (work->unk_15A & 4) {
        return;
    }

    if (work->unk_040.unk_E4->unk_0F4 == 19) {
        if (work->unk_172 != 0) {
            if (gFrameCounter & 1) {
                return;
            }
        } else if (gFrameCounter % 120 <= 59) {
            return;
        }
    }

    attr = func_0801AF1C(p->unk_08);

    if (work->unk_19C == 0x100 && work->unk_1A0 == 0x100) {
        if (p->unk_34 & 4) {
            sy = gBtlWork->unk_024;
            sx = sy;
        } else {
            sy = gBtlWork->unk_024;

            if (sy == 0x100) {
                sx = sy;
                attr |= 1;
            } else {
                sx = -sy;
            }
        }
    } else {
        if (p->unk_34 & 4) {
            sx = gBtlWork->unk_024 * work->unk_19C >> 8;
            sy = gBtlWork->unk_024 * work->unk_1A0 >> 8;
        } else {
            sx = -(gBtlWork->unk_024 * work->unk_19C >> 8);
            sy = gBtlWork->unk_024 * work->unk_1A0 >> 8;
        }
    }

    if (sy == 0x100 && sx == 0x100) {
        affine = 0;
    } else if (sy <= 255) {
        affine = AllocObjAffine(0, sx, sy, 0);
    } else {
        affine = AllocObjAffine(0, sx, sy, 1);
    }

    if (work->unk_15A & 0x10) {
        attr2 = work->unk_174 | 1;

        if (p->unk_8C <= p->unk_50) {
            if (p->unk_10 != 0) {
                p->unk_CC = 0;
            } else {
                p->unk_CC = 0xEFFF;
            }
        } else {
            p->unk_CC = work->unk_174 | 2;
        }
    } else {
        attr2 = (-0x1004 - ((p->unk_08 >> 8) << 2)) | 1;
        p->unk_CC = 0xEFFF;
    }
    WorldToScreen(&x, &y, p->unk_04, p->unk_08, p->unk_0C);

    if (func_0801CA00(p) != 0) {
        u16 t = work->unk_15A | 0x100;

        work->unk_15A = t;
        LoadObjPaletteBank(work->palette->unk_06, gUnk_08F69BC4);
    } else if (work->unk_15A & 0x100) {
        u16 t = work->unk_15A & 0xFEFF;

        work->unk_15A = t;

        if (work->unk_172 != 0) {
            LoadObjPaletteBank(work->palette->unk_06, gUnk_08F683A4);
        } else {
            LoadObjPaletteBank(work->palette->unk_06, gUnk_096FAC64);
        }
    }
    DrawSprite(x, y, work->unk_008, work->unk_000, work->palette, affine, attr, attr2);
    TaskPoolDraw(&work->unk_024);
}
#else
INCLUDE_ASM("btl/task_btl_sora_2.s");
#endif

void task_btl_sora_3(BtlSoraWork* work) {
    UnkStruct_0801AF08* p;

    p = &work->unk_040;
    m4aSongNumStop(590);

    if (!(gBtlWork->unk_068 & 0x4000)) {
        if (*(s32*)&gBtlWork->unk_0A0 == 3) {
            gGameState.hp = gGameState.maxHp;
        } else {
            gGameState.hp = p->hp;
        }
    }
    func_08012304(&p->unk_40);
    func_0801DEF4(work);
    TaskPoolDestroy(&work->unk_024);
}

void func_08027428(BtlRikuWork* work) {
    u16 a = work->unk_15E | 0x80;
    u16 b;

    work->unk_15E = a;
    b = work->unk_044.unk_70 | 2;
    work->unk_044.unk_70 = b;
}

void func_08027444(BtlRikuWork* work) {
    u16 a = work->unk_15E & 0xFF7F;
    u16 b;

    work->unk_15E = a;
    b = work->unk_044.unk_70 & 0xFFFD;
    work->unk_044.unk_70 = b;
}

u16 func_08027468(BtlRikuWork* work) {
    BtlWork* a;
    BtlWork* b;
    s32 d;

    a = work->unk_044.unk_E4->unk_07C;
    b = work->unk_044.unk_E4->unk_078;

    if (work->unk_044.unk_E4->unk_068 & 0x8000) {
        return 3;
    }

    if (b == 0) {
        return 0;
    }

    if (a->unk_00C - b->unk_00C > 0x2000) {
        return 2;
    }
    d = b->unk_004 - a->unk_004;
    if (d >= 0 ? d > 0x2800 : a->unk_004 - b->unk_004 > 0x2800) {
        return 1;
    }
    d = b->unk_008 - a->unk_008;
    if (d >= 0 ? d > 0xC00 : a->unk_008 - b->unk_008 > 0xC00) {
        return 4;
    }
    return 0;
}

void func_080274F0(BtlRikuWork* work) {
    BtlWork* c;

    if (work->unk_178 == 0) {
        return;
    }
    c = work->unk_044.unk_E4->unk_078;
    if (c != 0) {
        func_0802F284((work->unk_044.unk_04 + c->unk_004) >> 1, (work->unk_044.unk_08 + c->unk_008) >> 1,
                      (work->unk_044.unk_0C + c->unk_00C) >> 1);
    } else {
        func_0802F284(work->unk_044.unk_04, work->unk_044.unk_08, work->unk_044.unk_0C);
    }
}

void func_0802753C(BtlRikuWork* work) {
    s32 x;
    s32 y;
    s32 z;

    if (work->unk_178 != 0) {
        func_080140C0(&x, &y, &z);
        func_0802F284(x, gBtlWork->unk_07C->unk_008, gBtlWork->unk_07C->unk_00C);
    }
}

void func_08027570(BtlRikuWork* work, BtlDrawInfo* out) {
    UnkStruct_0801AF08* a;

    a = &work->unk_044;
    out->x = a->unk_04;
    out->y = a->unk_08;
    out->z = a->unk_0C;

    if (a->unk_34 & 4) {
        out->unk_0C |= 1;
    } else {
        out->unk_0C &= 0xFFFE;
    }
    out->anim = work->anim;
    out->unk_28 = *(void**)work->unk_000;
    out->unk_2C = gBtlWork->unk_024;
}

void func_080275D4(BtlRikuWork* work, BtlDrawInfo* out) {
    UnkStruct_0801AF08* a;
    void* gfx;
    u16 flags;
    s32 affine;
    s32 p;
    s32 q;
    s16 x;
    s16 y;
    s32 z;
    s32 v;

    gfx = AnimGetGfx(&out->anim);
    a = &work->unk_044;

    if (func_080128EC() == 0) {
        gBldCnt = 0xF10;
        SetBlendAlpha(6, 12);
        flags = 0x804;
    } else {
        flags = func_0801AF1C(a->unk_08);
    }

    if (out->unk_0C & 1) {
        p = out->unk_2C;
        q = p;
    } else {
        p = out->unk_2C;
        if (p == 256) {
            q = p;
            flags |= 1;
        } else {
            v = gBtlWork->unk_024;
            q = -v;
            p = v;
        }
    }

    if (p == 256 && q == p) {
        affine = 0;
    } else if (p <= 255) {
        affine = AllocObjAffine(0, q, p, 0);
    } else {
        affine = AllocObjAffine(0, q, p, 1);
    }
    z = 0xFFF0;
    WorldToScreen(&x, &y, out->x, out->y, out->z);
    func_08002A10(work->tiles, out->unk_28);
    DrawSprite(x, y, gfx, work->tiles, work->palette, affine, flags, z);
}

void func_080276D4(BtlRikuWork* work, u16 a, u16 b) {
    FldAnimDef* e;

    e = &gUnk_0813C2AC[a];
    func_08005974(&work->anim, e->unk_0C, b, e->unk_04, e->unk_00);
    func_08002A10(work->unk_000, e->unk_08);
}

void func_0802770C(BtlRikuWork* work, u16 a, u16 b) {
    FldAnimDef* e;
    s32 idx;

    idx = 0;

    switch (((work->unk_164 + 16) & 0xFF) >> 5) {
    case 0:
        idx = 1;
        break;
    case 4:
        idx = 0;
        break;
    case 3:
    case 5:
        idx = 2;
        break;
    case 2:
    case 6:
        idx = 3;
        break;
    case 1:
    case 7:
        idx = 4;
        break;
    }
    e = &gUnk_0813C4DC[a][idx];
    func_08005974(&work->anim, e->unk_0C, b, e->unk_04, e->unk_00);
    func_08002A10(work->unk_000, e->unk_08);
}

void func_080277A8(BtlRikuWork* work) {
    work->unk_000 = work->unk_044.unk_E4->unk_110;

    if (work->unk_178 != 0) {
        work->palette = LoadObjPalette(work->unk_1AC, 0x20);
    } else {
        work->palette = LoadObjPalette(gUnk_096FAC64, 0x20);
    }
}

void func_080277E4(BtlRikuWork* work) {
    ReleaseObjPalette(work->palette);
    work->unk_000 = 0;
    work->palette = 0;
}

void func_080277FC(BtlRikuWork* work, u16 a) {
    UnkStruct_0801AF08* p;

    p = &work->unk_044;

    if ((a & 0x10) && (a & 0x40)) {
        work->unk_164 = 0x20;
        p->unk_34 &= ~4;
        *(s32*)((u8*)p + 0x108) += 25;
        *(s32*)((u8*)p + 0x10C) -= 12;
    } else if ((a & 0x10) && (a & 0x80)) {
        work->unk_164 = 0x60;
        p->unk_34 &= ~4;
        *(s32*)((u8*)p + 0x108) += 25;
        *(s32*)((u8*)p + 0x10C) += 12;
    } else if ((a & 0x20) && (a & 0x80)) {
        work->unk_164 = 0xA0;
        p->unk_34 |= 4;
        *(s32*)((u8*)p + 0x108) -= 25;
        *(s32*)((u8*)p + 0x10C) += 12;
    } else if ((a & 0x20) && (a & 0x40)) {
        work->unk_164 = 0xE0;
        p->unk_34 |= 4;
        *(s32*)((u8*)p + 0x108) -= 25;
        *(s32*)((u8*)p + 0x10C) -= 12;
    } else if (a & 0x40) {
        work->unk_164 = 0;
        *(s32*)((u8*)p + 0x10C) -= 12;
    } else if (a & 0x10) {
        work->unk_164 = 0x40;
        p->unk_34 &= ~4;
        *(s32*)((u8*)p + 0x108) += 25;
    } else if (a & 0x80) {
        work->unk_164 = 0x80;
        *(s32*)((u8*)p + 0x10C) += 12;
    } else if (a & 0x20) {
        work->unk_164 = 0xC0;
        p->unk_34 |= 4;
        *(s32*)((u8*)p + 0x108) -= 25;
    }

    if (*(s32*)((u8*)p + 0x108) > 512) {
        *(s32*)((u8*)p + 0x108) = 512;
    } else if (*(s32*)((u8*)p + 0x108) < -512) {
        *(s32*)((u8*)p + 0x108) = -512;
    }

    if (*(s32*)((u8*)p + 0x10C) > 256) {
        *(s32*)((u8*)p + 0x10C) = 256;
    } else if (*(s32*)((u8*)p + 0x10C) < -256) {
        *(s32*)((u8*)p + 0x10C) = -256;
    }

    if (a & 0xF0) {
        func_0802770C(work, 0, 1);

        if (work->anim.timer == 0) {
            switch (work->anim.frame) {
            case 3:
                m4aSongNumStart(work->unk_188[0]);
                break;
            case 7:
                m4aSongNumStart(work->unk_188[1]);
                break;
            }
        }
    } else {
        func_080276D4(work, 0, 1);
    }

    if (a & 0xF0) {
        if (p->unk_E4->unk_0F4 == 50) {
            work->unk_160 += 256;

            if (work->unk_160 > 768) {
                work->unk_160 = 768;
            }
        } else {
            work->unk_160 += 128;

            if (work->unk_160 > 512) {
                work->unk_160 = 512;
            }
        }
    } else {
        work->unk_160 -= 128;

        if (work->unk_160 < 0) {
            work->unk_160 = 0;
        }
    }
}

void func_08027A64(BtlRikuWork* work, u16 a) {
    UnkStruct_0801AF08* p;

    p = &work->unk_044;

    if ((a & 0x10) && (a & 0x40)) {
        work->unk_164 = 0x20;
        p->unk_34 &= ~4;
    } else if ((a & 0x10) && (a & 0x80)) {
        work->unk_164 = 0x60;
        p->unk_34 &= ~4;
    } else if ((a & 0x20) && (a & 0x80)) {
        work->unk_164 = 0xA0;
        p->unk_34 |= 4;
    } else if ((a & 0x20) && (a & 0x40)) {
        work->unk_164 = 0xE0;
        p->unk_34 |= 4;
    } else if (a & 0x40) {
        work->unk_164 = 0;
    } else if (a & 0x10) {
        work->unk_164 = 0x40;
        p->unk_34 &= ~4;
    } else if (a & 0x80) {
        work->unk_164 = 0x80;
    } else if (a & 0x20) {
        work->unk_164 = 0xC0;
        p->unk_34 |= 4;
    }

    if (a & 0xF0) {
        func_080276D4(work, 13, 1);

        if (work->anim.timer == 0) {
            switch (work->anim.frame) {
            case 3:
                m4aSongNumStart(work->unk_188[0]);
                break;
            case 7:
                m4aSongNumStart(work->unk_188[1]);
                break;
            }
        }
    } else {
        func_080276D4(work, 12, 1);
    }

    if (a & 0xF0) {
        if (p->unk_E4->unk_0F4 == 50) {
            work->unk_160 += 256;
            if (work->unk_160 > 768) {
                work->unk_160 = 768;
            }
        } else {
            work->unk_160 += 128;
            if (work->unk_160 > 640) {
                work->unk_160 = 640;
            }
        }
    } else {
        work->unk_160 -= 128;
        if (work->unk_160 < 0) {
            work->unk_160 = 0;
        }
    }
}

INCLUDE_ASM("btl/task_btl_riku_0.s");

void func_080280BC(BtlRikuWork* work, u32 a) {
    work->unk_03C = a;
    work->unk_15A = 0;
    work->unk_158 = 0;
    func_0801AF08(&work->unk_044);
}

void func_080280E0(BtlRikuWork* work) {
    u16 t;

    if (work->unk_03C == 9 && work->unk_165 <= 1) {
        work->unk_165++;
        work->unk_158 = 0;
        work->unk_15A = 0;
    } else {
        switch (func_08027468(work)) {
        case 0:
            work->unk_168 = gUnk_0813C6E8;
            work->unk_16C = gUnk_0813C704;
            work->unk_170 = gUnk_0813C73C;
            break;
        case 1:
            work->unk_168 = gUnk_0813C704;
            work->unk_16C = gUnk_0813C6E8;
            work->unk_170 = gUnk_0813C73C;
            break;
        case 2:
            work->unk_168 = gUnk_0813C774;
            work->unk_16C = gUnk_0813C790;
            work->unk_170 = gUnk_0813C7AC;
            break;
        case 3:
            work->unk_168 = gUnk_0813C758;
            work->unk_16C = gUnk_0813C774;
            work->unk_170 = gUnk_0813C7AC;
            break;
        case 4:
        default:
            work->unk_168 = gUnk_0813C720;
            work->unk_16C = gUnk_0813C704;
            work->unk_170 = gUnk_0813C73C;
            break;
        }
        work->unk_03C = 9;
        work->unk_15A = 0;
        work->unk_158 = 0;
        work->unk_165 = 0;
        t = work->unk_15E & 0xFFBF;
        work->unk_15E = t;
    }
}

void func_08028228(BtlRikuWork* work) {
    work->unk_154 = -work->unk_044.unk_AC * 3;
    work->unk_14C = ((gSineTable[work->unk_044.unk_B0] << 1) * work->unk_044.unk_A8) >> 8;
    work->unk_150 = ((-gSineTable[work->unk_044.unk_B0 + 0x40] << 1) * work->unk_044.unk_A8) >> 8;
}

BtlWork* func_0802828C(BtlRikuWork* work) {
    if (gBtlWork->unk_068 & 0x4000) {
        if (work->unk_178 != 0) {
            if (gBtlWork->unk_068 & 0x40) {
                return gUnk_02039B9C->unk_07C;
            }
        } else {
            if (gBtlWork->unk_068 & 0x20000000) {
                return gBtlWork->unk_07C;
            }
        }
    } else {
        if (gBtlWork->unk_068 & 0x40) {
            return gBtlWork->unk_0A8;
        }
    }
    return 0;
}

BtlWork* func_0802830C(void) {
    BtlWork* e;
    BtlWork* best;
    s32 d;
    s32 min;

    min = 0x10000;
    best = 0;
    e = ListPoolFirst(&gBtlWork->unk_080);
    while (e != 0) {
        if (!(e->unk_034 & 0x1000000)) {
            d = e->unk_00C - (e->unk_0A2 << 8);
            if (min > d) {
                best = e;
                min = d;
            }
        }
        e = ListPoolNext(&e->unk_0B8);
    }
    return best;
}

BtlWork* func_08028370(BtlRikuWork* work) {
    BtlWork* list[10];
    BtlWork* e;
    s16 n;

    if (work->unk_044.unk_E4->unk_078 != 0) {
        return work->unk_044.unk_E4->unk_078;
    }

    if (gBtlWork->unk_068 & 0x4000) {
        if (work->unk_178 != 0) {
            e = gUnk_02039B9C->unk_07C;
        } else {
            e = gBtlWork->unk_07C;
        }

        if (e->unk_02C <= 0) {
            return 0;
        }
        return e;
    }
    n = 0;
    e = ListPoolFirst(&gBtlWork->unk_080);
    if (e != 0) {
        list[0] = e;
        n = 1;
        do {
            e = ListPoolNext(&e->unk_0B8);
            if (e == 0) {
                break;
            }
            list[n] = e;
            n++;
        } while (n <= 9);
    }

    if (n == 0) {
        return 0;
    }
    e = list[GetRandom() % n];
    return e;
}

u16 func_08028428(u16 a, u16 b, u16 c) {
    u16 d;

    d = b;

    if (a & b) {
        if ((a & c) == 0) {
            a &= ~b;
        }
        a |= c;
    } else if (a & c) {
        a &= ~c;
        a |= d;
    }
    return a;
}

void func_08028468(BtlRikuWork* work) {
    if (gBtlWork->unk_068 & 0x800000000000) {
        work->unk_1AC = gUnk_09618118;
        LoadObjPaletteBank(work->palette->unk_06, gUnk_09618118);
        gBtlWork->unk_068 &= ~0x800000000000;
        gBtlWork->unk_068 |= 0x80000000000000;
    }
}

void func_080284C8(s16 a) {
    if (gGameState.flags & 0x100) {
        return;
    }
    gBtlWork->unk_1C8 += a;
    if (gBtlWork->unk_1C8 < 0) {
        gBtlWork->unk_1C8 = 0;
    } else if (gBtlWork->unk_1C8 > 999) {
        gBtlWork->unk_1C8 = 999;
    }
}

INCLUDE_ASM("btl/task_btl_riku_1.s");
void task_btl_riku_2(BtlRikuWork* work) {
    UnkStruct_0801AF08* p;
    s32 affine;
    s32 sx;
    s32 sy;
    u16 attr;
    u16 attr2;
    s16 x;
    s16 y;

    p = &work->unk_044;

    if (work->unk_15E & 4) {
        return;
    }

    if (work->unk_044.unk_E4->unk_0F4 == 19) {
        if (work->unk_178 != 0) {
            if (gFrameCounter & 1) {
                return;
            }
        } else if (gFrameCounter % 120 <= 59) {
            return;
        }
    }

    attr = func_0801AF1C(p->unk_08);

    if (work->unk_19C == 0x100 && work->unk_1A0 == 0x100) {
        if (p->unk_34 & 4) {
            sy = gBtlWork->unk_024;
            sx = sy;
        } else {
            sy = gBtlWork->unk_024;

            if (sy == 0x100) {
                sx = sy;
                attr |= 1;
            } else {
                sx = -sy;
            }
        }
    } else {
        if (p->unk_34 & 4) {
            sx = gBtlWork->unk_024 * work->unk_19C >> 8;
            sy = gBtlWork->unk_024 * work->unk_1A0 >> 8;
        } else {
            sx = -(gBtlWork->unk_024 * work->unk_19C >> 8);
            sy = gBtlWork->unk_024 * work->unk_1A0 >> 8;
        }
    }

    if (sy == 0x100 && sx == 0x100) {
        affine = 0;
    } else if (sy <= 255) {
        affine = AllocObjAffine(0, sx, sy, 0);
    } else {
        affine = AllocObjAffine(0, sx, sy, 1);
    }

    if (work->unk_15E & 0x10) {
        attr2 = work->unk_17A | 1;

        if (p->unk_8C <= p->unk_50) {
            if (p->unk_10 != 0) {
                p->unk_CC = 0;
            } else {
                p->unk_CC = 0xEFFF;
            }
        } else {
            p->unk_CC = work->unk_17A | 2;
        }
    } else {
        attr2 = (-0x1004 - ((p->unk_08 >> 8) << 2)) | 1;
        p->unk_CC = 0xEFFF;
    }
    WorldToScreen(&x, &y, p->unk_04, p->unk_08, p->unk_0C);

    if (func_0801CA00(p) != 0) {
        u16 t = work->unk_15E | 0x100;

        work->unk_15E = t;
        LoadObjPaletteBank(work->palette->unk_06, gUnk_08F69BC4);
    } else if (work->unk_15E & 0x100) {
        u16 t = work->unk_15E & 0xFEFF;

        work->unk_15E = t;

        if (work->unk_178 != 0) {
            LoadObjPaletteBank(work->palette->unk_06, work->unk_1AC);
        } else {
            LoadObjPaletteBank(work->palette->unk_06, gUnk_096FAC64);
        }
    }
    DrawSprite(x, y, work->unk_00C, work->unk_000, work->palette, affine, attr, attr2);

    if (work->unk_15E & 0x800) {
        switch (work->unk_1BC % 2) {
        case 0:
            func_080275D4(work, &work->unk_1C0[3]);
            break;
        case 1:
            func_080275D4(work, &work->unk_1C0[6]);
            break;
        }
        work->unk_1BC++;
    }
    work->unk_1C0[6] = work->unk_1C0[5];
    work->unk_1C0[5] = work->unk_1C0[4];
    work->unk_1C0[4] = work->unk_1C0[3];
    work->unk_1C0[3] = work->unk_1C0[2];
    work->unk_1C0[2] = work->unk_1C0[1];
    work->unk_1C0[1] = work->unk_1C0[0];
    func_08027570(work, &work->unk_1C0[0]);
    TaskPoolDraw(&work->unk_028);
}

void task_btl_riku_3(BtlRikuWork* work) {
    UnkStruct_0801AF08* p;

    p = &work->unk_044;

    if (*(s32*)&gBtlWork->unk_0A0 == 3) {
        gGameState.hp = gGameState.maxHp;
    } else {
        gGameState.hp = p->hp;
    }
    func_08012304(&p->unk_40);
    func_080277E4(work);
    ReleaseObjTiles(work->tiles);
    TaskPoolDestroy(&work->unk_028);
}

#ifndef VERSION_EU
void task_btl_map_0(BtlMapWork* work) {
    SetBgSize(gBtlWork->unk_1C6, 0x8000);

    if (gBtlWork->unk_068 & 0x800) {
        switch (gBtlWork->unk_10C) {
        case 0xB2:
        case 0xB3:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C78824, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F68624, 0xC0);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EEF384, 0x1000);
            gBtlWork->unk_0B3 = 5;
            break;
        case 0xB1:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08CBC6E4, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F69604, 0x120);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08F00384, 0x1000);
            gBtlWork->unk_0B3 = 5;
            break;
        case 0xA0:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08CB06E4, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F69404, 0xC0);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EFD384, 0x1000);
            gBtlWork->unk_0B3 = 10;
            break;
        case 0x9E:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08CAC6E4, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F692C4, 0x140);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EFC384, 0x1000);
            gBtlWork->unk_0B3 = 9;
            break;
        case 0x9F:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C7C824, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F686E4, 0xE0);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF0384, 0x1000);
            gBtlWork->unk_0B3 = 10;
            break;
        case 0xAC:
        case 0xAF:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08CB86E4, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F69544, 0xC0);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EFF384, 0x1000);
            gBtlWork->unk_0B3 = 10;
            break;
        case 0xA5:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08CC06E4, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F69724, 0x80);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08F01384, 0x1000);
            gBtlWork->unk_0B3 = 20;
            break;
        default:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08CB46E4, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F694C4, 0x80);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EFE384, 0x1000);
            gBtlWork->unk_0B3 = 20;
            break;
        }
    } else if (gBtlWork->unk_10C == 0x78) {
        LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C80824, 0x4000);
        LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F687C4, 0x140);
        LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF1384, 0x1000);
        gBtlWork->unk_0B3 = 10;
    } else {
        switch (gGameState.unk_00D) {
        case 1:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C84824, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F68904, 0xC0);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF2384, 0x1000);
            gBtlWork->unk_0B3 = 10;
            break;
        case 2:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C80824, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F687C4, 0x140);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF1384, 0x1000);
            gBtlWork->unk_0B3 = 10;
            break;
        case 3:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C90824, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F68B84, 0x100);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF5384, 0x1000);
            gBtlWork->unk_0B3 = 10;
            break;
        case 4:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C88824, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F689C4, 0xC0);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF3384, 0x1000);
            gBtlWork->unk_0B3 = 10;
            break;
        case 5:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C8C824, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F68A84, 0x100);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF4384, 0x1000);
            gBtlWork->unk_0B3 = 10;
            break;
        case 7:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C94824, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F68C84, 0xE0);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF6384, 0x1000);
            gBtlWork->unk_0B3 = 5;
            break;
        case 8:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C98824, 0x3EC0);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F68D64, 0x140);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF7384, 0x1000);
            gBtlWork->unk_0B3 = 5;
            break;
        case 9:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C9C6E4, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F68EA4, 0x120);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF8384, 0x1000);
            gBtlWork->unk_0B3 = 10;
            break;
        case 10:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08CA06E4, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F68FC4, 0xE0);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF9384, 0x1000);
            gBtlWork->unk_0B3 = 10;
            break;
        case 11:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C78824, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F68624, 0xC0);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EEF384, 0x1000);
            gBtlWork->unk_0B3 = 5;
            break;
        case 12:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08CA86E4, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F691E4, 0xE0);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EFB384, 0x1000);
            gBtlWork->unk_0B3 = 20;
            break;
        case 13:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08CA46E4, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F690A4, 0x140);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EFA384, 0x1000);
            gBtlWork->unk_0B3 = 10;
            break;
        default:
            LoadBgTiles(gBtlWork->unk_1C6, gUnk_08C7C824, 0x4000);
            LoadBgPalette(gBtlWork->unk_1C6, gUnk_08F686E4, 0xE0);
            LoadBgMap(gBtlWork->unk_1C6, gUnk_08EF0384, 0x1000);
            gBtlWork->unk_0B3 = 11;
            break;
        }
    }
    gBtlWork->unk_024 = 0x100;
    gBtlWork->unk_028 = 0x100;
    gBtlWork->unk_008 = 0x10000;
    gBtlWork->unk_00C = 0x16000;
    gBtlWork->unk_000 = 0x10000;
    gBtlWork->unk_004 = 0x16000;
    gBtlWork->unk_010 = 0x10000;
    gBtlWork->unk_014 = 0x16000;
    gBtlWork->unk_01C = 0x10000;
    gBtlWork->unk_020 = 0x16000;
    gBtlWork->unk_01A = 0;
    gBtlWork->unk_018 = 0;
    work->unk_00 = gBtlWork->unk_0DA << 8;
    work->unk_04 = gBtlWork->unk_0DC << 8;
    work->unk_08 = gBtlWork->unk_0DE << 8;
    work->unk_0C = (gBtlWork->unk_0E0 + 0x20) << 8;
    func_0802F1C8();
    SetBgAffine(gBtlWork->unk_1C6, gBtlWork->unk_018, gBtlWork->unk_024,
                gBtlWork->unk_024, gBtlWork->unk_000,
                gBtlWork->unk_004 + 0x2800);
}
#else
INCLUDE_ASM("btl/task_btl_map_0.s");
#endif

void func_0802F1C8(void) {
    gUnk_0203492C = 0;
    gUnk_0203492E = 0;
    gUnk_02034930 = 0;
}

void func_0802F1E8(void) {
    gUnk_0203492C = 1;
    gUnk_0203492E = 0;
    gUnk_02034930 = 0;
}

void func_0802F208(void) {
    if (gUnk_0203492C != 0) {
        gUnk_02034930 += ((gUnk_0813C7D8[(s16)gUnk_0203492E] << 12) - gUnk_02034930) >> 3;
        gUnk_0203492E++;
        if (gUnk_0203492E > 0x1F) {
            gUnk_0203492C = 0;
            gUnk_02034930 = 0;
            gBtlWork->unk_018 = 0;
        }
    }
}

s32 func_0802F268(void) {
    return gUnk_02034930;
}

void func_0802F274(s32 a, s32 b) {
    gBtlWork->unk_010 = a;
    gBtlWork->unk_014 = b;
}

void func_0802F284(s32 a, s32 b, s32 c) {
    s32 x = (a + 0x10000) >> 1;
    s32 y = (b + 0x14400) >> 1;

    if (a - x > 0x3000) {
        x = a - 0x3000;
    } else if (x - a > 0x3000) {
        x = a + 0x3000;
    }

    if (b - y > 0x3000) {
        y = b - 0x3000;
    } else if (y - b > 0x3000) {
        y = b + 0x3000;
    }
    gBtlWork->unk_010 = x;
    gBtlWork->unk_014 = y + c;
}

s32 task_btl_map_1(BtlMapWork* work) {
    s32 dx;
    s32 dy;

    func_0802F208();

    if (gBtlWork->unk_01A > 0) {
        func_0800592C(&gBtlWork->unk_024, gBtlWork->unk_028, gBtlWork->unk_01A);
        func_0800592C(&gBtlWork->unk_008, gBtlWork->unk_01C, gBtlWork->unk_01A);
        func_0800592C(&gBtlWork->unk_00C, gBtlWork->unk_020, gBtlWork->unk_01A);

        if (gBtlWork->unk_028 == 0x100) {
            func_0800592C(&work->unk_00, gBtlWork->unk_0DA << 8, gBtlWork->unk_01A);
            func_0800592C(&work->unk_04, gBtlWork->unk_0DC << 8, gBtlWork->unk_01A);
            func_0800592C(&work->unk_08, gBtlWork->unk_0DE << 8, gBtlWork->unk_01A);
            func_0800592C(&work->unk_0C, (gBtlWork->unk_0E0 + 0x20) << 8, gBtlWork->unk_01A);
        } else if (gBtlWork->unk_028 > 0x100) {
            func_0800592C(&work->unk_00, 0x3000, gBtlWork->unk_01A);
            func_0800592C(&work->unk_04, 0x1D000, gBtlWork->unk_01A);
            func_0800592C(&work->unk_08, 0x9000, gBtlWork->unk_01A);
            func_0800592C(&work->unk_0C, 0x1E800, gBtlWork->unk_01A);
        }
        gBtlWork->unk_01A--;
    } else if (gBtlWork->unk_024 == 0x100) {
        dx = (gBtlWork->unk_010 - gBtlWork->unk_008) >> 3;
        dy = (gBtlWork->unk_014 - gBtlWork->unk_00C) >> 3;

        if (dx > 0x400) {
            dx = 0x400;
        } else if (dx < -0x400) {
            dx = -0x400;
        }

        if (dy > 0x400) {
            dy = 0x400;
        } else if (dy < -0x400) {
            dy = -0x400;
        }
        gBtlWork->unk_008 += dx;
        gBtlWork->unk_00C += dy;
    }
    gBtlWork->unk_000 = gBtlWork->unk_008;
    gBtlWork->unk_004 = gBtlWork->unk_00C;

    if (gUnk_0203492C != 0) {
        gBtlWork->unk_018 = (gUnk_02034930 >> 8) / 3;
    }

    if (gBtlWork->unk_000 - 0x7800 < work->unk_00) {
        gBtlWork->unk_000 = work->unk_00 + 0x7800;
    } else if (gBtlWork->unk_000 + 0x7800 > work->unk_04) {
        gBtlWork->unk_000 = work->unk_04 - 0x7800;
    }

    if (gBtlWork->unk_004 - 0x5000 < 0x9000) {
        gBtlWork->unk_004 = 0xE000;
    } else if (gBtlWork->unk_004 + 0x5000 > work->unk_0C) {
        gBtlWork->unk_004 = work->unk_0C - 0x5000;
    }
    SetBgAffine(gBtlWork->unk_1C6, gBtlWork->unk_018, gBtlWork->unk_024,
                  gBtlWork->unk_024, gBtlWork->unk_000,
                  gBtlWork->unk_004 + 0x2800);
    return 1;
}
