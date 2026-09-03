#include "macros.h"
#include "bos4.h"

void* gUnk_02034F0C;
UrsulaMapanimeWork* gUnk_02034F10;
UnkStruct_02034F14* gUnk_02034F14;
UnkStruct_02034F18* gUnk_02034F18;

void task_bos_boogie_dice_0(BoogieDiceWork* work, u8* arg) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)(arg + 0x40);
    s32 c;
    s32 d;
    s32 e;
    u16 r;

    work->unk_170 = arg[0x175];
    work->unk_16C = (u32)arg;
    work->unk_000 = 10;
    work->unk_004 = 0;
    work->unk_150 = -0x4CC;
    work->unk_154 = GetRandom() % 437 + 0x4C;
    work->unk_158 = GetRandom() % 0x78 + 0x44;
    work->unk_160 = 0x33;
    work->unk_15C = 0x33;
    work->unk_164 = 0;
    work->unk_168 = 0;
    gUnk_0203C564 = 0;
    c = p->unk_04;
    d = 0x24000;
    e = p->unk_0C - 0x3800;
    func_0801B37C(&work->unk_040, &gUnk_096FDF54, c, d, e);
    func_080122AC(&work->unk_080, 3, gUnk_096FDF54.unk_08, gUnk_096FDF54.unk_06);
    work->unk_074 |= 0x400;
    work->unk_074 |= 0x80;
    work->unk_008 = (u32)AllocObjTiles(func_08003524(gUnk_09EF6788, 4), gUnk_09796EAA);
    work->unk_00C = (u32)LoadObjPalette(gUnk_0984AF98, 32);
    work->unk_010 = (u32)LoadObjPalette(gUnk_08F69BC4, 32);
    AnimInit(&work->unk_014, gUnk_09EF6798, gUnk_09EF6788);
    AnimStart(&work->unk_014, 0, 1);
    r = GetRandom();
    func_08005B44(&work->unk_014, r & 3);
    TaskPoolInit(&work->unk_02C, 1);
    TaskCreate(&work->unk_02C, gTaskDescBosShadow, &work->unk_040);

    if (work->unk_170 == 0) {
        func_0801BCD4(&work->unk_040);
    }
}
u8 task_bos_boogie_dice_1(BoogieDiceWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_040;

    if (work->unk_170 == 0) {
        switch (func_0801ADAC(p)) {
        case 5:
            work->unk_000 = 3;
            work->unk_004 = 0;
            break;
        case 4:
            work->unk_000 = 0;
            work->unk_004 = 0;
            gUnk_0203C554 += 180;
            break;
        case 2:
        default:
            if (func_0801C1C0(0) != 0) {
                func_080D9A58();

                if (work->unk_000 == 3) {
                    work->unk_000 = 0;
                    work->unk_004 = 0;
                }
            }

            break;
        case 1:
        case 3:
        case 6:
        case 7:
        case 8:
            work->unk_000 = 2;
            work->unk_004 = 0;
            break;
        }
    } else {
        switch (func_080D9A90()) {
        case 3:
            if (work->unk_000 != 3) {
                work->unk_000 = 3;
                work->unk_004 = 0;
            }

            break;
        case 0:
            if (work->unk_000 != 0) {
                work->unk_000 = 0;
                work->unk_004 = 0;
            }

            break;
        case 1:
            if (work->unk_000 == 3) {
                work->unk_000 = 0;
                work->unk_004 = 0;
            }

            break;
        }

        switch (func_0801ADAC(p)) {
        case 1:
        case 3:
        case 6:
        case 7:
        case 8:
            work->unk_000 = 2;
            work->unk_004 = 0;
            break;
        }
    }

    switch (work->unk_000) {
    case 3:
        if (func_080D9B28(work) != 0) {
            return 1;
        }

        *(u64*)((u8*)p + 0x34) &= ~0x80;
        func_080D9B6C(work);
        work->unk_150 += 51;
        p->unk_0C += work->unk_150;
        p->unk_04 += gSineTable[work->unk_158] * work->unk_154 >> 8;
        p->unk_08 += -gSineTable[work->unk_158 + 0x40] * work->unk_154 >> 8;

        if (*((u8*)p + 0x6C) != 0 && work->unk_160 > 255 && work->unk_15C > 255) {
            work->unk_154 = work->unk_154 * 230 >> 8;
            p->unk_04 += *(s32*)((u8*)p + 0x78);
            p->unk_08 += *(s32*)((u8*)p + 0x7C);
            work->unk_158 = work->unk_158 + (100 + GetRandom() % 57);
        }

        if (func_080D9AC4(&p->unk_04, &p->unk_08, 0, 0) != 0) {
            work->unk_158 = work->unk_158 + (100 + GetRandom() % 57);
        }

        if (p->unk_0C > 0) {
            p->unk_0C = 0;
            work->unk_150 = -(work->unk_150 * 179 >> 8);
            work->unk_154 = work->unk_154 * 212 >> 8;

            if (work->unk_150 >= -25) {
                func_080DA42C(work);
                work->unk_000 = 4;
                *(u64*)((u8*)p + 0x34) |= 0x100;

                if (work->unk_170 == 0) {
                    func_0801AF08(p);
                }
            }
        }

        break;
    case 0:
        *(u64*)((u8*)p + 0x34) &= ~0x80;

        if ((s16)work->unk_004 == 0 && work->unk_170 == 0) {
            func_0801AF08(p);
            gUnk_0203C560++;
            work->unk_168 = 1;
        }

        work->unk_004++;
        func_080D9B6C(work);

        if (*((u8*)p + 0x6C) != 0 && work->unk_160 > 255 && work->unk_15C > 255) {
            work->unk_154 = work->unk_154 * 230 >> 8;
            p->unk_04 += *(s32*)((u8*)p + 0x78);
            p->unk_08 += *(s32*)((u8*)p + 0x7C);
            work->unk_158 = work->unk_158 + (100 + GetRandom() % 57);
        }

        work->unk_150 += 51;
        p->unk_0C += work->unk_150;

        if (p->unk_0C > 0) {
            p->unk_0C = 0;
            work->unk_150 = -(work->unk_150 * 128 >> 8);
            work->unk_004 = 0;
            work->unk_000 = 1;
        }

        break;
    case 1:
        if ((s16)work->unk_004 > 59) {
            work->unk_000 = 6;
            break;
        }

        work->unk_004++;
        work->unk_150 += 51;
        p->unk_04 += gSineTable[work->unk_158] * work->unk_154 >> 8;
        p->unk_08 += -gSineTable[work->unk_158 + 0x40] * work->unk_154 >> 8;

        if (*((u8*)p + 0x6C) != 0 && work->unk_160 > 255 && work->unk_15C > 255) {
            work->unk_154 = work->unk_154 * 230 >> 8;
            p->unk_04 += *(s32*)((u8*)p + 0x78);
            p->unk_08 += *(s32*)((u8*)p + 0x7C);
            work->unk_158 = work->unk_158 + (100 + GetRandom() % 57);
        }

        if (func_080D9AC4(&p->unk_04, &p->unk_08, 0, 0) != 0) {
            work->unk_158 = work->unk_158 + (100 + GetRandom() % 57);
        }

        if (p->unk_0C > 0) {
            p->unk_0C = 0;
            work->unk_150 = -(work->unk_150 * 179 >> 8);
        }

        break;
    case 2:
        if (work->unk_170 == 0 && gUnk_0203C568 == 0 && GetRandom() % 16 <= 7) {
            gUnk_0203C568 = 1;
            _0801C1F8(0, p->unk_04, p->unk_08, p->unk_0C);
        }

        func_0801C2DC(p, 1);

        return 0;
    case 4:
        if (AnimIsFinished(&work->unk_014) != 0) {
            work->unk_000 = 5;
            work->unk_004 = 0;
        }

        break;
    case 5:
        if ((s16)work->unk_004 > 20) {
            work->unk_000 = 6;
            break;
        }

        work->unk_004++;
        break;
    case 6:
        func_0801C2DC(p, 1);
        work->unk_160 -= 12;
        work->unk_164 += 96;

        if (work->unk_160 <= 127) {
            work->unk_000 = 7;
            work->unk_150 = -0x4CC;
            work->unk_004 = 0;
        }

        break;
    case 7:
        if ((s16)work->unk_004 > 10) {
            work->unk_000 = 8;
            work->unk_004 = 0;
            break;
        }

        work->unk_004++;
        break;
    case 8:
        work->unk_150 += 51;
        p->unk_0C += work->unk_150;
        work->unk_160 += 25;
        work->unk_164 -= 200;

        if (work->unk_160 > 255) {
            work->unk_000 = 9;
            work->unk_004 = 0;
        } else if (work->unk_160 <= 178) {
            break;
        }
    case 9:
        work->unk_15C -= 38;

        if (work->unk_15C <= 24) {
            func_08013F5C(p->unk_04, p->unk_08 + p->unk_0C, 0x100, 8, 16);

            return 0;
        }

        break;
    case 10:
        if ((s16)work->unk_004 > 30) {
            return 0;
        }

        work->unk_004++;
        break;
    }

    AnimUpdate(&work->unk_014);

    if (work->unk_000 == 1) {
        AnimUpdate(&work->unk_014);
    }

    func_08012324((u8*)p + 0x40, p->unk_04, p->unk_08, p->unk_0C);
    TaskPoolUpdate(&work->unk_02C);

    return 1;
}
void task_bos_boogie_dice_2(BoogieDiceWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_040;
    s16 x;
    s16 y;
    u16 c;
    void* pal;
    s32 aff;
    s32 a;
    s32 b;

    if (func_080D9B28(work) != 0) {
        return;
    }

    c = func_0801AF1C(p->unk_08);

    if (func_0801CA00(p) != 0) {
        pal = (void*)work->unk_010;
    } else {
        pal = (void*)work->unk_00C;
    }

    a = work->unk_15C;

    if (a > 0x100) {
        a = 0x100;
    }

    b = work->unk_160;

    if (b > 0x100) {
        b = 0x100;
    }

    aff = AllocObjAffine(0, a, b, 0);
    WorldToScreen(&x, &y, p->unk_04, p->unk_08, p->unk_0C);
    DrawSprite(x, (work->unk_164 >> 8) + y, AnimGetGfx(&work->unk_014), (void*)work->unk_008, pal,
        aff, c, -0x1004 - (p->unk_08 >> 8) * 4);
    TaskPoolDraw(&work->unk_02C);
}

void task_bos_boogie_dice_3(BoogieDiceWork* work) {
    if (work->unk_168 == 0 && gUnk_0203C560 != 3 && work->unk_170 == 0 && work->unk_000 != 10) {
        gUnk_0203C564 = 1;
    }

    func_08012304(&work->unk_080);
    func_0801B7D8(&work->unk_040);
    ReleaseObjTiles((void*)work->unk_008);
    ReleaseObjPalette((void*)work->unk_00C);
    ReleaseObjPalette((void*)work->unk_010);
    TaskPoolDestroy(&work->unk_02C);
}

void func_080DA42C(BoogieDiceWork* work) {
    void* tbl[6][3];
    u8 n;

    memcpy(tbl, gUnk_096FDF7C, 72);

    switch (GetRandom() % 4) {
    case 0:
        n = 5;
        break;
    case 1:
        n = 3;
        break;
    case 2:
        n = 0;
        break;
    default:
        switch (GetRandom() % 3) {
        case 0:
            n = 1;
            break;
        case 1:
            n = 2;
            break;
        default:
            n = 4;
            break;
        }
        break;
    }

    if (work->unk_170 == 0) {
        gUnk_0203C558 = n;
    }

    func_08005974(&work->unk_014, 0, 0, tbl[n][0], tbl[n][1]);
    func_08002A10((void*)work->unk_008, tbl[n][2]);
}

u8 func_080DA4DC(u8* p) {
    u8* q = *(u8**)(p + 0x15C);

    if (*(u32*)(q + 0x15C) == 3 && func_08005B34(q + 20) <= 2) {
        return 1;
    }

    return 0;
}

void task_bos_boogie_explosiondice_0(BoogieExplosiondiceWork* work, void* arg) {
    u8* p;

    work->unk_15C = (u32)arg;
    work->unk_000 = 0;
    work->unk_004 = 0;
    work->unk_150 = 0;
    work->unk_154 = GetRandom() % 437 + 76;
    work->unk_158 = GetRandom() % 128 + 0x40;
    p = (u8*)gUnk_02039B84->unk_07C;
    work->unk_044 = *(s32*)(p + 4);
    work->unk_048 = *(s32*)(p + 8);
    work->unk_04C = -0xA000;
    func_080122AC(&work->unk_080, 8, gUnk_096FDFC4.unk_08, gUnk_096FDFC4.unk_06);
    work->unk_008 = (u32)AllocObjTiles(func_08003524(gUnk_09EF6774, 4), gUnk_0979666A);
    work->unk_00C = (u32)LoadObjPalette(gUnk_0984AF98, 32);
    work->unk_010 = (u32)LoadObjPalette(gUnk_08F69BC4, 32);
    AnimInit(&work->unk_014, gUnk_09EF6784, gUnk_09EF6774);
    AnimStart(&work->unk_014, 0, 1);
    TaskPoolInit(&work->unk_02C, 1);
    TaskCreate(&work->unk_02C, gTaskDescBosShadow, &work->unk_040);
}

u8 task_bos_boogie_explosiondice_1(BoogieExplosiondiceWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_040;

    if (func_080DA4DC((u8*)work) != 0) {
        return 1;
    }

    switch (work->unk_000) {
    case 0:
        work->unk_150 += 51;
        p->unk_0C += work->unk_150;

        if (p->unk_0C > -0x2000) {
            func_08014020(p->unk_04, p->unk_08 + p->unk_0C, 0);
            return 0;
        }

        break;
    case 2:
        if (func_080128EC() == 0) {
            return 0;
        }

        break;
    }

    AnimUpdate(&work->unk_014);
    func_08012324((u8*)p + 0x40, p->unk_04, p->unk_08, p->unk_0C);
    TaskPoolUpdate(&work->unk_02C);

    return 1;
}

void task_bos_boogie_explosiondice_2(BoogieExplosiondiceWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_040;
    u8 f = func_080DA4DC((u8*)work);
    s16 x;
    s16 y;
    u16 c;
    void* pal;

    if (f != 0 || work->unk_000 == 1) {
        return;
    }

    c = func_0801AF1C(p->unk_08);
    pal = (void*)work->unk_00C;
    WorldToScreen(&x, &y, p->unk_04, p->unk_08, p->unk_0C);
    DrawSprite(x, y, AnimGetGfx(&work->unk_014), (void*)work->unk_008, pal, f, c,
        -0x1004 - (p->unk_08 >> 8) * 4);
    TaskPoolDraw(&work->unk_02C);
}

void task_bos_boogie_explosiondice_3(BoogieExplosiondiceWork* work) {
    func_08012304(&work->unk_080);
    ReleaseObjTiles((void*)work->unk_008);
    ReleaseObjPalette((void*)work->unk_00C);
    ReleaseObjPalette((void*)work->unk_010);
    TaskPoolDestroy(&work->unk_02C);
}

u8 func_080DA73C(void) {
    if (*(s32*)((u8*)gUnk_02039B84->unk_07C + 8) <= 0x23EFF) {
        return 1;
    }

    return 0;
}

void task_bos_boogie_saku_0(BoogieSakuWork* work, void* arg) {
    work->unk_024 = (u32)arg;
    work->unk_000 = (u32)LoadObjTiles(gUnk_09799CBA, 0x2E0);
    work->unk_004 = (u32)LoadObjPalette(gUnk_0984AF78, 32);
    AnimInit(&work->unk_008, gUnk_09EF680C, gUnk_09EF67FC);
    AnimStart(&work->unk_008, 0, 0);
    work->unk_020 = 0;
    TaskPoolInit(&work->unk_028, 1);
    work->unk_03C = 0;
    work->unk_040 = 0;
}

u8 task_bos_boogie_saku_1(BoogieSakuWork* work) {
    u8 f;

    if (gUnk_0203C560 > 2 && AnimIsFinished(&work->unk_008) != 0) {
        if (work->unk_020 < gUnk_0203C554) {
            if (work->unk_020 == 0) {
                func_0802F1E8();
            }

            work->unk_020++;
            func_0801A920(0x80, 0x170, 0x228, 0x278);

            if (func_080DA73C() != 0) {
                func_0801C2DC((u8*)work->unk_024 + 0x40, 0);
            } else {
                func_0801C2DC((u8*)work->unk_024 + 0x40, 1);
            }
        } else if (*(u32*)work->unk_024 != 4) {
            work->unk_040 = 1;
            gUnk_0203C560 = 0;
            work->unk_020 = 0;
            gUnk_0203C554 = 0;
            func_0801C2DC((u8*)work->unk_024 + 0x40, 1);

            if (func_080DA73C() != 0) {
                work->unk_03C = (u32)TaskCreate(&work->unk_028, gUnk_09EF5040, (void*)work->unk_024);
            }
        }
    }

    if (gUnk_0203C560 <= 2 && func_08000F48((void*)work->unk_03C) == 0) {
        func_0801A920(0x80, 0x170, 0x240, 0x278);

        if (gUnk_0203C560 != 0) {
            AnimChange(&work->unk_008, gUnk_0203C560, 0);
        } else if (work->unk_040 != 0) {
            AnimChange(&work->unk_008, 3, 0);
            work->unk_040 = 0;
        }
    }

    f = AnimIsFinished(&work->unk_008);

    if (gUnk_0203C560 > 2
            || (gUnk_0203C560 == 0 && func_08005B30(&work->unk_008) == 3
                && func_08000F48((void*)work->unk_03C) == 0)) {
        AnimUpdate(&work->unk_008);
    }

    if (f == 0 && AnimIsFinished(&work->unk_008) != 0) {
        m4aSongNumStart(0x255);

        if (func_08005B30(&work->unk_008) == 3) {
            AnimChange(&work->unk_008, 0, 0);
        }
    }

    TaskPoolUpdate(&work->unk_028);

    return 1;
}

void func_080DA954(BoogieSakuWork* work, s32 a, u16 b) {
    s16 x;
    s16 y;

    WorldToScreen(&x, &y, a, 0x23F00, -0x2000);
    DrawSprite(x, y + 1, AnimGetGfx(&work->unk_008), (void*)work->unk_000, (void*)work->unk_004, 0, b, 0xE700);
    TaskPoolDraw(&work->unk_028);
}

void task_bos_boogie_saku_2(BoogieSakuWork* work) {
    u16 v = func_0801AF1C(0x23F00);

    func_080DA954(work, 0xA800, v);
    func_080DA954(work, 0xF800, v);
    func_080DA954(work, 0x14800, v);
}

void task_bos_boogie_saku_3(BoogieSakuWork* work) {
    ReleaseObjTiles((void*)work->unk_000);
    ReleaseObjPalette((void*)work->unk_004);
    TaskPoolDestroy(&work->unk_028);
}

void task_bos_boogie_map_0(void* work, UnkStruct_080DAA28* arg) {
    LoadBgTiles(0, arg->unk_00, arg->unk_04);
    LoadBgPalette(0, arg->unk_08, arg->unk_0C);
    func_0800516C(0, &arg->unk_10, 2, 2);
    gUnk_02039B84->unk_024 = 0x100;
    gUnk_02039B84->unk_028 = 0x100;
    gUnk_02039B84->unk_008 = 0xF800;
    gUnk_02039B84->unk_00C = 0x21000;
    gUnk_02039B84->unk_000 = 0xF800;
    gUnk_02039B84->unk_004 = 0x21000;
    gUnk_02039B84->unk_010 = 0xF800;
    gUnk_02039B84->unk_014 = 0x21000;
    gUnk_02039B84->unk_01C = 0xF800;
    gUnk_02039B84->unk_020 = 0x21000;
    gUnk_02039B84->unk_01A = 15;
    gUnk_02039B84->unk_018 = 0;
    func_0802F1C8();
    func_08005244(0, gUnk_02039B84->unk_000 >> 8, gUnk_02039B84->unk_004 >> 8);
}

u8 task_bos_boogie_map_1(void) {
    s32 a;
    s32 b;

    func_0802F208();
    a = (gUnk_02039B84->unk_010 - gUnk_02039B84->unk_008) >> 3;
    b = (gUnk_02039B84->unk_014 - gUnk_02039B84->unk_00C) >> 3;

    if (a > 0x500) {
        a = 0x500;
    } else if (a < -0x500) {
        a = -0x500;
    }

    gUnk_02039B84->unk_008 += a;
    gUnk_02039B84->unk_00C += b;
    gUnk_02039B84->unk_000 = gUnk_02039B84->unk_008;
    gUnk_02039B84->unk_004 = gUnk_02039B84->unk_00C;

    if (gUnk_02039B84->unk_000 - 0x7800 < gUnk_02039B84->unk_0DA * 256) {
        gUnk_02039B84->unk_000 = (gUnk_02039B84->unk_0DA + 0x78) << 8;
    } else if (gUnk_02039B84->unk_000 + 0x7800 > gUnk_02039B84->unk_0DC * 256) {
        gUnk_02039B84->unk_000 = (gUnk_02039B84->unk_0DC - 0x78) << 8;
    }

    if (gUnk_02039B84->unk_004 - 0x5000 < 0x18C00) {
        gUnk_02039B84->unk_004 = 0x1DC00;
    } else if (gUnk_02039B84->unk_004 + 0x5000 > 0x27800) {
        gUnk_02039B84->unk_004 = 0x22800;
    }

    gUnk_02039B84->unk_004 += func_0802F268();
    func_08005244(0, (gUnk_02039B84->unk_000 >> 8) + 8, (gUnk_02039B84->unk_004 >> 8) - 0x108);

    return 1;
}

void task_bos_boogie_mapanime_0(BoogieMapanimeWork* work) {
    func_080DDDDC(&work->unk_000[0], &gUnk_096FE034);
    func_080DDDDC(&work->unk_000[1], &gUnk_096FE04C);
    func_080DDDDC(&work->unk_000[2], &gUnk_096FE064);
}

u8 task_bos_boogie_mapanime_1(BoogieMapanimeWork* work) {
    u32 i;
    u8 r = 0;

    for (i = gUnk_0203C560; i <= 2; i++) {
        r = func_080DDDEC(&work->unk_000[i], work->unk_000[i].unk_08, r);
    }

    return 1;
}

void task_bos_boogie_mapanime_2(void) {
}

void task_bos_boogie_mapanime_3(void) {
}

u8 func_080DABFC(s32* x, s32* y, s16 w, s16 h, s32 z) {
    u8 r = 0;

    if (*x < (0x80 - w) << 8) {
        *x = (0x80 - w) << 8;
        r = 1;
    }

    if (*x > (w + 0x170) << 8) {
        *x = (w + 0x170) << 8;
        r = 1;
    }

    if (*y < (0x240 - h) << 8) {
        *y = (0x240 - h) << 8;
        r = 1;
    }

    if (*y > (0x278 - h) << 8) {
        *y = (0x278 - h) << 8;
        r = 1;
    }

    return r;
}

void task_bos_boogie_disk_0(BoogieDiskWork* work, UnkStruct_0203C55C* arg) {
    s32 x;
    s32 v;
    s32 d;
    s32 e;

    work->unk_000 = 2;
    work->unk_004 = 0;
    work->unk_15C = 0;
    work->unk_150 = -0x200;

    if (*(s32*)((u8*)gUnk_02039B84->unk_07C + 4) < 0xF800) {
        x = *(s32*)((u8*)gUnk_02039B84->unk_07C + 4) + 0xF000;
        work->unk_154 = -0x266;
    } else {
        x = *(s32*)((u8*)gUnk_02039B84->unk_07C + 4) - 0xF000;
        work->unk_154 = 0x266;
    }

    work->unk_158 = 0x133;
    v = arg->unk_2E;

    if (arg->unk_2C < (s16)(v / 3)) {
        work->unk_154 *= 3;
        work->unk_158 *= 3;
    } else if (arg->unk_2C < v * 2 / 3) {
        work->unk_154 *= 2;
        work->unk_158 *= 2;
    }

    d = *(s32*)((u8*)gUnk_02039B84->unk_07C + 8);
    e = -0x1000;
    func_0801B37C(&work->unk_040, gUnk_096FE098, x, d, e);
    work->unk_074 |= 0x400;
    work->unk_008 = (u32)AllocObjTiles(func_08003524(gUnk_09EF6824, 8), gUnk_0979A426);
    work->unk_00C = (u32)LoadObjPalette(gUnk_0984AFB8, 32);
    work->unk_010 = (u32)LoadObjPalette(gUnk_08F69BC4, 32);
    AnimInit(&work->unk_014, gUnk_09EF6844, gUnk_09EF6824);
    AnimStart(&work->unk_014, 0, 1);
    TaskPoolInit(&work->unk_02C, 1);
    TaskCreate(&work->unk_02C, gTaskDescBosShadow, &work->unk_040);
    func_0801BCD4(&work->unk_040);
    m4aSongNumStart(0x253);
}
u8 task_bos_boogie_disk_1(BoogieDiskWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_040;

    switch (func_0801ADAC(p)) {
    case 5:
        work->unk_000 = 0;
        work->unk_004 = 0;
        break;
    case 2:
    default:
        if (func_0801C1C0(0) == 0) {
            break;
        }

        func_080D9A58();
    case 1:
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
        if (work->unk_000 != 1) {
            work->unk_000 = 1;
            work->unk_004 = 0;
        }

        break;
    }

    switch (work->unk_000) {
    case 0:
        p->unk_08 += work->unk_158;

        if (func_080DABFC(&p->unk_04, &p->unk_08, 0x20, -0x10, p->unk_0C) != 0) {
            work->unk_158 = -work->unk_158;
        }

        p->unk_04 += work->unk_154;

        if ((work->unk_154 > 0 && p->unk_04 > 0x19000)
                || (work->unk_154 <= 0 && p->unk_04 < 0x6000)) {
            func_0801AF08(p);

            return 0;
        }

        if (func_08011F78(0x105, p->unk_04, p->unk_08, p->unk_0C, 0x20, 0x10, 1) == 1) {
            gUnk_0203C56C = 1;
            m4aSongNumStart(0x22F);
        }

        break;
    case 1:
        if (p->unk_0C >= 0) {
            gUnk_0203C570 = 1;
            func_0801AF08(p);

            return 0;
        }

        work->unk_004++;
        p->unk_04 -= work->unk_154;
        work->unk_15C += 0x19;
        p->unk_0C += work->unk_150;
        work->unk_150 += 0x42;

        if (p->unk_0C > 0) {
            p->unk_0C = 0;
        }

        break;
    case 2:
        if ((s16)work->unk_004 > 30) {
            return 0;
        }

        work->unk_004++;
        break;
    }

    AnimUpdate(&work->unk_014);
    func_08012324((u8*)p + 0x40, p->unk_04, p->unk_08, p->unk_0C);
    TaskPoolUpdate(&work->unk_02C);

    return 1;
}
void task_bos_boogie_disk_2(BoogieDiskWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_040;
    s16 x;
    s16 y;
    u16 c = func_0801AF1C(p->unk_08);
    void* pal = (void*)work->unk_00C;
    u8* obj = func_08002C28(work->unk_15C, 1);

    WorldToScreen(&x, &y, p->unk_04, p->unk_08, p->unk_0C);
    DrawSprite(x, y, AnimGetGfx(&work->unk_014), (void*)work->unk_008, pal, (s32)obj, c,
        -0x1004 - (p->unk_08 >> 8) * 4);
    TaskPoolDraw(&work->unk_02C);
}

void task_bos_boogie_disk_3(BoogieDiskWork* work) {
    func_0801B7D8(&work->unk_040);
    ReleaseObjTiles((void*)work->unk_008);
    ReleaseObjPalette((void*)work->unk_00C);
    ReleaseObjPalette((void*)work->unk_010);
    TaskPoolDestroy(&work->unk_02C);
}

void func_080DB04C(BoogieKnifeWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_02C;
    s32 dy;

    if (gUnk_0203C578 != 0) {
        work->unk_148 = 0x100;
        work->unk_14C = 0;
        dy = 0x2000;
    } else {
        work->unk_148 = -0x100;
        work->unk_14C = 0;
        dy = -0x2000;
    }

    if (func_08011F78(0x106, p->unk_04 - dy, p->unk_08, p->unk_0C - 0x1000, 4, 0x1C, 0x10) == 1) {
        gUnk_0203C56C = 1;
        m4aSongNumStart(0x226);
    }
}
void task_bos_boogie_knife_0(BoogieKnifeWork* work, u32* arg) {
    UnkStruct_0203C55C* p;
    s32 v;

    work->unk_000 = 0;
    work->unk_004 = 0;

    if (gUnk_0203C578 != 0) {
        work->unk_140 = 0x133;
    } else {
        work->unk_140 = -0x133;
    }

    work->unk_13C = 0;
    work->unk_150 = 0x42;
    work->unk_154 = -0x500;
    p = gUnk_0203C55C;
    v = p->unk_2E;

    if (p->unk_2C < (s16)(v / 3)) {
        work->unk_150 = (work->unk_150 * 0x300) >> 8;
        work->unk_154 = -0xA00;
    } else if (p->unk_2C < v * 2 / 3) {
        work->unk_150 = (work->unk_150 * 0x200) >> 8;
        work->unk_154 = -0x780;
    }

    work->unk_034 = 0x25C00;
    work->unk_038 = -0xC000;
    work->unk_030 = *arg;
    func_080122AC(&work->unk_06C, 8, gUnk_096FE0C0.unk_08, gUnk_096FE0C0.unk_06);
    work->unk_008 = (u32)LoadObjTiles(gUnk_0979C44E, 0xC40);
    work->unk_00C = (u32)LoadObjPalette(gUnk_0984AFD8, 32);
    work->unk_010 = (u32)LoadObjPalette(gUnk_08F69BC4, 32);
    AnimInit(&work->unk_014, gUnk_09EF684C, gUnk_09EF6848);
    AnimStart(&work->unk_014, 0, 1);
}
u8 task_bos_boogie_knife_1(BoogieKnifeWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_02C;

    if (gUnk_0203C574 != 0) {
        work->unk_000 = 2;
    }

    switch (work->unk_000) {
    case 0:
        p->unk_0C += work->unk_13C;
        work->unk_13C += work->unk_150;

        if (p->unk_0C < 0) {
            func_080DB04C(work);
        } else {
            p->unk_0C = 0;
            work->unk_000 = 1;
            work->unk_13C = work->unk_154;
        }

        break;
    case 1:
        p->unk_04 += work->unk_140;
        p->unk_0C += work->unk_13C;
        work->unk_13C += work->unk_150;
        work->unk_004++;

        if (p->unk_0C < 0) {
            func_080DB04C(work);
        } else {
            p->unk_0C = 0;
            work->unk_13C = work->unk_154;

            if ((s16)work->unk_004 > 199.99999f) {
                work->unk_000 = 2;
            } else {
                func_080DB04C(work);
            }
        }

        break;
    case 2:
        p->unk_0C -= 0x800;

        if (p->unk_0C < -0xC000) {
            return 0;
        }

        break;
    }

    AnimUpdate(&work->unk_014);
    func_08012324((u8*)p + 0x40, p->unk_04, p->unk_08, p->unk_0C);

    return 1;
}
void task_bos_boogie_knife_2(BoogieKnifeWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_02C;
    s16 x;
    s16 y;
    u16 c;
    void* pal;
    s32 aff;

    WorldToScreen(&x, &y, p->unk_04 + work->unk_14C, p->unk_08 - 0x2400, p->unk_0C);

    if ((u16)(x + 0x20) > 0x130) {
        return;
    }

    c = func_0801AF1C(p->unk_08);

    if (gUnk_0203C574 != 0 && (gFrameCounter & 1) != 0 && gUnk_02039B84->unk_070 == 0) {
        pal = (void*)work->unk_010;
    } else {
        pal = (void*)work->unk_00C;
    }

    aff = AllocObjAffine(0, work->unk_148, 0x100, 0);
    DrawSprite(x, y, AnimGetGfx(&work->unk_014), (void*)work->unk_008, pal, aff, c,
        -0x1004 - (p->unk_08 >> 8) * 4);
}

void task_bos_boogie_knife_3(BoogieKnifeWork* work) {
    func_08012304(&work->unk_06C);
    ReleaseObjTiles((void*)work->unk_008);
    ReleaseObjPalette((void*)work->unk_00C);
    ReleaseObjPalette((void*)work->unk_010);
}

u8 func_080DB428(u8* p) {
    if (*(s32*)(p + 0x38) >= 0) {
        return 1;
    }

    return 0;
}

u8 func_080DB438(BoogieKnifereaderWork* work) {
    s32 i;

    for (i = 0; i <= 4; i++) {
        if (func_08000F48(work->unk_12C[i]) != 0) {
            return 1;
        }
    }

    return 0;
}

void func_080DB468(BoogieKnifereaderWork* work) {
    s32 i;
    s32 v;

    if (GetRandom() % 16 > 7) {
        gUnk_0203C578 = 1;
        v = -0x4000;

        for (i = 0; i <= 4; i++) {
            work->unk_12C[i] = TaskCreate(&work->unk_008, gUnk_09EF50B8, &v);
            v += 0x6800;
        }
    } else {
        gUnk_0203C578 = 0;
        v = 0x23000;

        for (i = 0; i <= 4; i++) {
            work->unk_12C[i] = TaskCreate(&work->unk_008, gUnk_09EF50B8, &v);
            v += -0x6800;
        }
    }
}

void task_bos_boogie_knifereader_0(BoogieKnifereaderWork* work) {
    s32 i;

    work->unk_000 = 2;
    work->unk_004 = 0;
    gUnk_0203C574 = 0;
    TaskPoolInit(&work->unk_008, 5);

    for (i = 0; i < 5; i++) {
        work->unk_12C[i] = 0;
    }

    func_0801B37C(&work->unk_01C, gUnk_096FE0E8, 0xF800, 0x24000, 0);
    func_0801C2DC(&work->unk_01C, 1);
    func_0801BCD4(&work->unk_01C);
}

u8 task_bos_boogie_knifereader_1(BoogieKnifereaderWork* work) {
    s32 i;
    void* e = &work->unk_01C;
    void* pool;

    switch (func_0801ADAC(e)) {
    case 5:
        work->unk_000 = 0;
        work->unk_004 = 0;
        break;
    case 2:
    default:
        if (func_0801C1C0(0) == 0) {
            break;
        }

        func_080D9A58();
    case 1:
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
        if (work->unk_000 != 1) {
            work->unk_000 = 1;
            work->unk_004 = 0;
        }

        break;
    }

    switch (work->unk_000) {
    case 2:
        if ((s16)work->unk_004 > 30) {
            return 0;
        }

        work->unk_004++;
        break;
    case 1:
        gUnk_0203C574 = 1;
        goto rest;
    case 0:
        if ((s16)work->unk_004 == 0) {
            work->unk_004++;
            func_080DB468(work);
            break;
        }
    default:
        goto rest;
    }

    pool = &work->unk_008;
    TaskPoolUpdate(pool);

    return 1;

rest:
    if (func_080DB438(work) == 0) {
        func_0801AF08(e);

        return 0;
    }

    for (i = 0; i <= 4; i++) {
        pool = &work->unk_008;

        if (func_08000F48(work->unk_12C[i]) != 0) {
            if (func_080DB428(((u8**)work->unk_12C[i])[1]) != 0) {
                m4aSongNumStart(0x254);
            }

            break;
        }
    }

    TaskPoolUpdate(pool);

    return 1;
}

void task_bos_boogie_knifereader_2(BoogieKnifereaderWork* work) {
    TaskPoolDraw(&work->unk_008);
}

void task_bos_boogie_knifereader_3(BoogieKnifereaderWork* work) {
    func_0801B7D8(&work->unk_01C);
    TaskPoolDestroy(&work->unk_008);
}

void task_bos_boogie_kaihuku_0(BoogieKaihukuWork* work, BoogieDiceWork* arg) {
    s32 c;
    s32 d;
    s32 e;

    work->unk_000 = 2;
    work->unk_004 = 0;
    work->unk_154 = (u32)arg;
    work->unk_150 = 0;
    c = arg->unk_044;
    d = arg->unk_048 + 0x100;
    e = arg->unk_04C - 0x7C00;
    func_0801B37C(&work->unk_040, gUnk_096FE114, c, d, e);
    work->unk_074 |= 0x400;
    work->unk_008 = (u32)LoadObjTiles(gUnk_09799FB0, 0x400);
    work->unk_00C = (u32)LoadObjPalette(gUnk_0984AFB8, 32);
    work->unk_010 = (u32)LoadObjPalette(gUnk_08F69BC4, 32);
    AnimInit(&work->unk_014, gUnk_09EF6820, gUnk_09EF681C);
    AnimStart(&work->unk_014, 0, 1);
    func_0801BCD4(&work->unk_040);
}
u8 task_bos_boogie_kaihuku_1(BoogieKaihukuWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_040;
    BoogieDiceWork* arg = (BoogieDiceWork*)work->unk_154;
    void* q = &arg->unk_040;

    switch (func_0801ADAC(p)) {
    case 5:
        work->unk_000 = 0;
        work->unk_004 = 0;
        break;
    case 2:
    default:
        if (func_0801C1C0(0) == 0) {
            break;
        }

        func_080D9A58();
    case 1:
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
        if (work->unk_000 != 1) {
            work->unk_000 = 1;
            work->unk_004 = 0;
        }

        break;
    }

    switch (work->unk_000) {
    case 0:
        func_0802F274(p->unk_04, p->unk_08 + p->unk_0C);

        if ((s16)work->unk_004 == 0) {
            func_08015228(p->unk_04, p->unk_08, p->unk_0C + 0x2800, 0x199);
            m4aSongNumStart(0x256);
            work->unk_004++;
            break;
        }

        if (func_080128EC() != 0) {
            break;
        }

        func_08019190(q, 10);
        arg = (BoogieDiceWork*)work->unk_154;
        arg->unk_06C += arg->unk_06E / 16;
        arg = (BoogieDiceWork*)work->unk_154;

        if ((s16)arg->unk_06C > arg->unk_06E) {
            arg->unk_06C = arg->unk_06E;
        }

        return 0;
    case 1:
        if (p->unk_0C >= 0) {
            gUnk_0203C570 = 1;
            func_0801AF08(p);

            return 0;
        }

        work->unk_004++;
        p->unk_0C += work->unk_150;
        work->unk_150 += 0x42;

        if (p->unk_0C < -0x2000) {
            p->unk_0C = 0;
        }

        break;
    case 2:
        if ((s16)work->unk_004 > 30) {
            return 0;
        }

        work->unk_004++;
        break;
    }

    AnimUpdate(&work->unk_014);
    func_08012324((u8*)p + 0x40, p->unk_04, p->unk_08, p->unk_0C);

    return 1;
}

void task_bos_boogie_kaihuku_2(BoogieKaihukuWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_040;
    void* d;
    u16 v;
    s16 x;
    s16 y;

    if (work->unk_000 != 2) {
        v = func_0801AF1C(p->unk_08);
        d = (void*)work->unk_00C;
        WorldToScreen(&x, &y, p->unk_04, p->unk_08, p->unk_0C);
        DrawSprite(x, y, AnimGetGfx(&work->unk_014), (void*)work->unk_008, d, 0, v, -0x1004 - (p->unk_08 >> 8) * 4);
    }
}

void task_bos_boogie_kaihuku_3(BoogieKaihukuWork* work) {
    func_0801B7D8(&work->unk_040);
    ReleaseObjTiles((void*)work->unk_008);
    ReleaseObjPalette((void*)work->unk_00C);
    ReleaseObjPalette((void*)work->unk_010);
}

void func_080DB978(UrsulaWork* work) {
    if (work->unk_000 >= 3 && work->unk_000 <= 4) {
        if (work->unk_028 > *(s32*)((u8*)gUnk_02039B84->unk_07C + 4)) {
            if (work->unk_134 != (u32)gUnk_09EF5130) {
                work->unk_134 = (u32)gUnk_09EF5130;
                func_0800516C(0, gUnk_09EF5130, 4, 3);
            } else {
                func_080DD69C(0);
            }
        } else {
            if (work->unk_134 != (u32)gUnk_09EF5190) {
                work->unk_134 = (u32)gUnk_09EF5190;
                func_0800516C(0, gUnk_09EF5190, 4, 3);
            } else {
                func_080DD69C(0);
            }
        }
    } else if (func_080DC510() != 0) {
        if (work->unk_134 != (u32)gUnk_09EF5100) {
            work->unk_134 = (u32)gUnk_09EF5100;
            func_0800516C(0, gUnk_09EF5100, 4, 3);
        }
    } else {
        if (work->unk_134 != (u32)gUnk_09EF5160) {
            work->unk_134 = (u32)gUnk_09EF5160;
            func_0800516C(0, gUnk_09EF5160, 4, 3);
        }
    }
}

u8 func_080DBA14(UrsulaWork* work) {
    if (work->unk_142 == 0 && func_080DD1FC(*(void**)(work->unk_01C + 4)) == 0 && func_080DD1FC(*(void**)(work->unk_020 + 4)) == 0) {
        return 1;
    }

    return 0;
}

void task_bos_ursula_0(UrsulaWork* work) {
    u8 v;

    gUnk_02034F0C = work;
    gUnk_0203C57C = 1;
    TaskCreate((u8*)gUnk_02039B84 + 0x40, gUnk_09EF51D8, gUnk_096FE14C);
    TaskCreate((u8*)gUnk_02039B84 + 0x2C, gUnk_09EF51F0, 0);
    work->unk_000 = 0;
    work->unk_004 = 0;
    work->unk_134 = 0;
    work->unk_160 = 0;
    work->unk_140 = 0;
    work->unk_13C = 0;
    work->unk_138 = 0;
    work->unk_142 = 0;
    func_0801A920(0, 0x200, 0x1A8, 0x1E0);
    func_0801BCC0(0x10000, 0x1A800, 0);
    gUnk_02039B84->unk_0D8 = 0xFF00;
    gUnk_0203C580 = -0x5000;
    func_0801B37C(&work->unk_024, gUnk_096FE13C, 0x10000, 0x19800, -0x5000);
    work->unk_034 = 0;
    work->unk_058 |= 4;
    func_0801C2DC(&work->unk_024, 1);
    func_080DB978(work);
    func_080051C4(0, (gUnk_02039B84->unk_000 - (work->unk_028 - 0x12000)) >> 8,
        (gUnk_02039B84->unk_004 - (work->unk_02C + work->unk_030 - 0x12000)) >> 8);
    func_0801C298(0, 1);
    func_0801C298(1, 1);
    gUnk_02039B84->unk_0CC = work->unk_028;
    gUnk_02039B84->unk_0D0 = work->unk_02C;
    gUnk_02039B84->unk_0D4 = work->unk_030;
    TaskPoolInit(&work->unk_008, 5);
    v = 1;
    work->unk_01C = (u32)TaskCreate(&work->unk_008, gUnk_09EF5208, &v);
    v = 0;
    work->unk_020 = (u32)TaskCreate(&work->unk_008, gUnk_09EF5208, &v);
    TaskCreate(&work->unk_008, gUnk_09EF5238, 0);
    v = 1;
    TaskCreate(&work->unk_008, gUnk_09EF5220, &v);
    work->unk_15E = 0;
}

void func_080DBC00(UrsulaWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_024;

    if ((s16)work->unk_140 == 0) {
        work->unk_140 = 32;

        if (work->unk_13C == 0) {
            work->unk_13C = -0x400;
        } else {
            work->unk_13C = 0;
        }
    }

    ApproachValue(&work->unk_138, work->unk_13C, work->unk_140);
    p->unk_0C = gUnk_0203C580 + work->unk_138;
    work->unk_140--;
}

u8 func_080DBC68(UrsulaWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_024;

    func_080DBC00(work);

    if (func_080DC510() != 0) {
        p->unk_04 -= 0x100;

        if (p->unk_04 <= -0x9800) {
            p->unk_04 = -0x9800;
            return 0;
        }
    } else {
        p->unk_04 += 0x100;

        if (p->unk_04 >= 0x28000) {
            p->unk_04 = 0x28000;
            return 0;
        }
    }

    return 1;
}

s32 func_080DBCC0(UrsulaWork* work) {
    s32* p = (s32*)gUnk_02039B84->unk_07C;

    if (p[1] < work->unk_028 - 0x5000 || work->unk_028 + 0x5000 < p[1]) {
        return 1;
    }

    return 3;
}

s32 func_080DBCEC(UrsulaWork* work) {
    if (work->unk_028 - 0x3800 < *(s32*)((u8*)gUnk_02039B84->unk_07C + 4) && *(s32*)((u8*)gUnk_02039B84->unk_07C + 4) < work->unk_028 + 0x3800) {
        return 3;
    }

    if (work->unk_028 - 0x6800 < *(s32*)((u8*)gUnk_02039B84->unk_07C + 4) && *(s32*)((u8*)gUnk_02039B84->unk_07C + 4) < work->unk_028 + 0x6800) {
        return 2;
    }

    return 1;
}

INCLUDE_ASM("bos4/func_080DBD44.s");

s32 func_080DBDC0(UrsulaWork* work) {
    switch (func_080DC5E8()) {
    case 0:
        return func_080DBCC0(work);
    case 1:
        return func_080DBCEC(work);
    case 2:
    default:
        return func_080DBD44(work);
    }
}

void func_080DBDEC(UrsulaWork* work) {
    if (work->unk_160 != 0) {
        func_080DD210(*(void**)(work->unk_01C + 4));
        func_080DD210(*(void**)(work->unk_020 + 4));
        work->unk_160 = 0;
    }
}

void func_080DBE18(UrsulaWork* work) {
    if (work->unk_142 == 0 && func_080DD230(*(void**)(work->unk_01C + 4)) == 0 && func_080DD230(*(void**)(work->unk_020 + 4)) == 0) {
        func_080DBDEC(work);
        work->unk_160 = 1;
    } else {
        work->unk_160 = 0;
    }
}

u8 func_080DBE64(void) {
    switch (func_080DC5E8()) {
    case 0:
        return 150;
    case 1:
        return 120;
    case 2:
    default:
        return 100;
    }
}

INCLUDE_ASM("bos4/task_bos_ursula_1.s");
void task_bos_ursula_2(UrsulaWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_024;
    s32 d = 0;

    if (func_080DC510() != 0 && work->unk_134 == (u32)gUnk_09EF5190) {
        d = -0x1000;
    } else if (func_080DC510() == 0 && work->unk_134 == (u32)gUnk_09EF5130) {
        d = 0x1000;
    }

    func_08005244(0, (gUnk_02039B84->unk_000 - (p->unk_04 - 0x12000) + d) >> 8,
        (gUnk_02039B84->unk_004 - (p->unk_08 + p->unk_0C - 0x12000)) >> 8);
    TaskPoolDraw(&work->unk_008);
}

void task_bos_ursula_3(UrsulaWork* work) {
    func_0801B7D8(&work->unk_024);
    TaskPoolDestroy(&work->unk_008);
    gDispCnt &= 0xDFFF;
}

u8 func_080DC510(void) {
    return *(u64*)((u8*)gUnk_02034F0C + 0x58) & 4;
}

u8 func_080DC528(void) {
    if (*(u16*)((u8*)gUnk_02034F0C + 0x142) == 0) {
        return 0;
    }

    return 1;
}

u8 func_080DC544(void) {
    UnkStruct_02039B84* p;
    u8 r = 1;

    for (p = func_08000C8C(gUnk_02039B84->unk_080); p != 0; p = func_08000CD4((u8*)p + 0xB8)) {
        if (p->unk_000 == 0x23) {
            r = 0;
            break;
        }
    }

    return r;
}

u8 func_080DC578(void) {
    if (func_080DC544() != 0 || func_080DC528() == 0 || *(u16*)((u8*)gUnk_02034F0C + 0x15E) == 0) {
        return 0;
    }

    return 1;
}

u8 func_080DC5B0(void) {
    if (func_080DC528() != 0 && (*(u32*)((u8*)gUnk_02034F0C + 0x158) != 0 || *(u16*)((u8*)gUnk_02034F0C + 0x15C) != 0)) {
        return 1;
    }

    return 0;
}

u32 func_080DC5E8(void) {
    s16* p = (s16*)((u8*)gUnk_02034F0C + 0x50);

    if (*p > (s16)(*(s16*)((u8*)gUnk_02034F0C + 0x52) / 3) * 2) {
        return 0;
    }

    if (*p > (s16)(*(s16*)((u8*)gUnk_02034F0C + 0x52) / 3)) {
        return 1;
    }

    return 2;
}

u8 func_080DC628(void) {
    if (**(u32**)&gUnk_02034F0C == 4) {
        return 1;
    }

    return 0;
}

void task_bos_ursula_map_0(UrsulaMapWork* work, UnkStruct_080DAA28* arg) {
    SetupBg(0, 0, 0x1A, 0);
    SetupBg(1, 0, 0x18, 0);
    SetBgPriority(1, 3);
    SetBgPriority(0, 2);
    LoadBgTiles(1, arg->unk_00, arg->unk_04);
    LoadBgPalette(1, arg->unk_08, arg->unk_0C);
    func_0800516C(1, arg->unk_10, 2, 2);
    gUnk_02039B84->unk_024 = 0x100;
    gUnk_02039B84->unk_028 = 0x100;
    gUnk_02039B84->unk_008 = 0x10000;
    gUnk_02039B84->unk_00C = 0x17100;
    gUnk_02039B84->unk_000 = 0x10000;
    gUnk_02039B84->unk_004 = 0x17100;
    gUnk_02039B84->unk_010 = 0x10000;
    gUnk_02039B84->unk_014 = 0x17100;
    gUnk_02039B84->unk_01C = 0x10000;
    gUnk_02039B84->unk_020 = 0x17100;
    gUnk_02039B84->unk_01A = 0x0F;
    gUnk_02039B84->unk_018 = 0;
    func_0802F1C8();
    func_08005244(1, gUnk_02039B84->unk_000 >> 8, gUnk_02039B84->unk_004 >> 8);
    gDispCnt |= 0x2000;
    gWin0H = 0xF0;
    gWin0V = 0x50A0;
    gWinIn = 0x3E;
    gWinOut = 0x3F;
    work->unk_00 = 0x1E000;
    work->unk_04 = 0x1E000;
    work->unk_08 = 0;
}
u8 task_bos_ursula_map_1(UrsulaMapWork* work) {
    s32 a;
    s32 b;
    u8 v;

    if (func_080DC578() != 0) {
        return 1;
    }

    func_0802F208();
    a = (gUnk_02039B84->unk_010 - gUnk_02039B84->unk_008) >> 3;
    b = (gUnk_02039B84->unk_014 - gUnk_02039B84->unk_00C) >> 3;

    if (a > 0x500) {
        a = 0x500;
    } else if (a < -0x500) {
        a = -0x500;
    }

    if (b > 0x500) {
        b = 0x500;
    } else if (b < -0x500) {
        b = -0x500;
    }

    gUnk_02039B84->unk_008 += a;
    gUnk_02039B84->unk_00C += b;
    gUnk_02039B84->unk_000 = gUnk_02039B84->unk_008;
    gUnk_02039B84->unk_004 = gUnk_02039B84->unk_00C;

    if (gUnk_02039B84->unk_000 - 0x7800 < gUnk_02039B84->unk_0DA * 256) {
        gUnk_02039B84->unk_000 = (gUnk_02039B84->unk_0DA + 0x78) << 8;
    } else if (gUnk_02039B84->unk_000 + 0x7800 > gUnk_02039B84->unk_0DC * 256) {
        gUnk_02039B84->unk_000 = (gUnk_02039B84->unk_0DC - 0x78) << 8;
    }

    if (func_080DC5B0() != 0 && work->unk_04 == 0x1E000) {
        work->unk_04 = 0x22000;
        work->unk_08 = 20;
    } else if (func_080DC5B0() == 0 && work->unk_04 == 0x22000) {
        work->unk_04 = 0x1E000;
        work->unk_08 = 20;
    }

    if (work->unk_08 != 0) {
        ApproachValue(&work->unk_00, work->unk_04, work->unk_08);
        work->unk_08--;
    }

    if (gUnk_02039B84->unk_004 - 0x5000 < 0x8800) {
        gUnk_02039B84->unk_004 = 0xD800;
    } else if (gUnk_02039B84->unk_004 + 0x5000 > work->unk_00) {
        gUnk_02039B84->unk_004 = work->unk_00 - 0x5000;
    }

    gUnk_02039B84->unk_004 += func_0802F268();
    func_08005244(1, (gUnk_02039B84->unk_000 >> 8) - 0x78, (gUnk_02039B84->unk_004 >> 8) - 0x50);
    v = -0x18 - (gUnk_02039B84->unk_004 >> 8);

    if (v > 0xA0 || gUnk_0203C57C == 0) {
        gDispCnt &= 0xDFFF;
    } else {
        gDispCnt |= 0x2000;
        gWin0V = (v << 8) | 0xA0;
    }

    return 1;
}

void task_bos_ursula_map_3(void) {
}

void task_bos_ursula_border_0(UrsulaBorderWork* work) {
    work->unk_000 = LoadObjTiles(gUnk_0979D0B6, 0x800);
    work->unk_004 = LoadObjPalette(gUnk_0984B0D8, 0x20);
    func_0801C298(((u8*)work->unk_004)[6] + 16, 0);
}

s32 task_bos_ursula_border_1(void) {
    return 1;
}

void task_bos_ursula_border_2(UrsulaBorderWork* work) {
    s16 a;
    s16 b;
    s16 c;
    s16 d;

    func_0801AF1C(0x19800);
    WorldToScreen(&a, &b, 0x8000, 0x19800, -0x800);
    WorldToScreen(&c, &d, 0x18000, 0x19800, -0x800);
    DrawSprite(a, b, gUnk_0979D090, work->unk_000, work->unk_004, 0, 0x800, 0xFB00);
    DrawSprite(c, d, gUnk_0979D8B8, work->unk_000, work->unk_004, 0, 0x800, 0xFB00);
}

void task_bos_ursula_border_3(UrsulaBorderWork* work) {
    ReleaseObjTiles(work->unk_000);
    ReleaseObjPalette(work->unk_004);
}

void func_080DC9DC(s32* a, s32* b, s32* c, UrsulaTakoWork* d) {
    s32* p;
    s32 t;

    *a = gUnk_02039B84->unk_0CC + d->unk_1FC;

    if (d->unk_13E != 0) {
        if (func_080DC510() != 0) {
            *a += -0x2200;
        } else {
            *a += -0x3600;
        }
    } else {
        if (func_080DC510() != 0) {
            *a += 0x3600;
        } else {
            *a += 0x2200;
        }
    }

    *b = gUnk_02039B84->unk_0D0;
    p = &gUnk_02039B84->unk_0D4;
    t = d->unk_200 + 0x5000;
    *c = *p + t;
}

s32 func_080DCA78(u8 a) {
    if (a == func_080DC510()) {
        return 12;
    }

    return 6;
}

void task_bos_ursula_tako_0(UrsulaTakoWork* work, u8* arg) {
    s32 x;
    s32 y;
    s32 z;

    work->unk_13E = *arg;
    work->unk_1FC = 0;
    work->unk_200 = 0;
    func_080DC9DC(&x, &y, &z, work);
    func_0801B37C(&work->unk_028, gUnk_096FE1A8, x, y, z);
    func_080122AC(&work->unk_19C, 7, 0x28, 0x20);

    if (work->unk_13E != 0) {
        work->unk_024 = 0xFFFC;
        work->unk_05C |= 4;
        work->unk_1F8 = -0x2800;
    } else {
        work->unk_024 = 0;
        work->unk_1F8 = 0x2800;
    }

    work->unk_000 = AllocObjTiles(func_08003524(gUnk_09EF6860, 6), gUnk_0979E344);
    work->unk_004 = LoadObjPalette(gUnk_0984B0F8, 32);
    work->unk_008 = LoadObjPalette(gUnk_08F69BC4, 32);
    AnimInit(&work->unk_00C, gUnk_09EF68A0, gUnk_09EF6860);
    AnimStart(&work->unk_00C, (u16)(work->unk_024 + 4), 1);
    work->unk_138 = 0;
    func_080122AC(&work->unk_140, 7, (u16)func_080DCA78(work->unk_13E), 1);
    func_08012324(&work->unk_140, work->unk_02C, work->unk_030 + 0x1000, -0x3800);
    func_0801C7FC(&work->unk_028, 35, 51);
}
INCLUDE_ASM("bos4/task_bos_ursula_tako_1.s");

void task_bos_ursula_tako_2(UrsulaTakoWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_028;
    void* pal;
    s16 x;
    s16 y;

    if (work->unk_138 != 4 && func_080DC528() == 0) {
        pal = func_0801CA00(p) != 0 ? work->unk_008 : work->unk_004;
        WorldToScreen(&x, &y, p->unk_04, p->unk_08, p->unk_0C);
        DrawSprite(x, y, AnimGetGfx(&work->unk_00C), work->unk_000, pal, 0, 0x800, 0xFC00);
    }
}

void task_bos_ursula_tako_3(UrsulaTakoWork* work) {
    func_0801B7D8(&work->unk_028);
    func_08012304(&work->unk_19C);
    func_08012304(&work->unk_140);
    ReleaseObjTiles(work->unk_000);
    ReleaseObjPalette(work->unk_004);
    ReleaseObjPalette(work->unk_008);
}

u8 func_080DD1FC(UrsulaTakoWork* work) {
    if (work->unk_138 <= 1) {
        return 0;
    }

    return 1;
}

void func_080DD210(UrsulaTakoWork* work) {
    if (work->unk_138 >= 3 && work->unk_138 <= 4) {
        work->unk_138 = 4;
        work->unk_13C = 180;
    }
}

u8 func_080DD230(UrsulaTakoWork* work) {
    if (work->unk_16E & 2) {
        return 1;
    }

    return 0;
}

void func_080DD248(s32* a, s32* b, s32* c, UrsulaBacktakoWork* d) {
    s32* p;
    s32 t;

    *a = gUnk_02039B84->unk_0CC + d->unk_024;

    if (d->unk_022 != 0) {
        if (func_080DC510() != 0) {
            *a += -0x4A00;
        } else {
            *a += -0x5E00;
        }
    } else {
        if (func_080DC510() != 0) {
            *a += 0x5E00;
        } else {
            *a += 0x4A00;
        }
    }

    *b = gUnk_02039B84->unk_0D0 + 0x800;
    p = &gUnk_02039B84->unk_0D4;
    t = d->unk_028 + 0x5000;
    *c = *p + t;
}
void task_bos_ursula_backtako_0(UrsulaBacktakoWork* work, u8* arg) {
    work->unk_022 = *arg;
    work->unk_024 = 0;
    work->unk_028 = 0;
    func_080DD248(&work->unk_02C, &work->unk_030, &work->unk_034, work);
    work->unk_022 = work->unk_022 == 0 ? 1 : 0;
    func_080DD248(&work->unk_038, &work->unk_03C, &work->unk_040, work);
    work->unk_022 = work->unk_022 == 0 ? 1 : 0;
    if (work->unk_022 != 0) {
        work->unk_020 = 0xFFFC;
    } else {
        work->unk_020 = 0;
    }

    work->unk_000 = (u32)AllocObjTiles(func_08003524(gUnk_09EF6860, 8), gUnk_0979E344);
    work->unk_004 = (u32)LoadObjPalette(gUnk_0984B0F8, 32);
    AnimInit(&work->unk_008, gUnk_09EF68A0, gUnk_09EF6860);
    AnimStart(&work->unk_008, (u16)(work->unk_020 + 4), 1);
    func_08005B44(&work->unk_008, GetRandom() % work->unk_014 + 1);
}

u8 task_bos_ursula_backtako_1(UrsulaBacktakoWork* work) {
    if (func_080DC628() == 0) {
        func_080DD248(&work->unk_02C, &work->unk_030, &work->unk_034, work);
        work->unk_022 = work->unk_022 == 0 ? 1 : 0;
        func_080DD248(&work->unk_038, &work->unk_03C, &work->unk_040, work);
        work->unk_022 = work->unk_022 == 0 ? 1 : 0;
        AnimUpdate(&work->unk_008);
    }

    return 1;
}

void task_bos_ursula_backtako_2(UrsulaBacktakoWork* work) {
    s16 x;
    s16 y;
    u8 f = func_080DC528();

    if (f != 0) {
        return;
    }

    WorldToScreen(&x, &y, work->unk_02C, work->unk_030, work->unk_034);
    DrawSprite(x, y, AnimGetGfx(&work->unk_008), (void*)work->unk_000, (void*)work->unk_004, f, 0xC00,
        0xFE00);
    WorldToScreen(&x, &y, work->unk_038, work->unk_03C, work->unk_040);
    DrawSprite(x, y, AnimGetGfx(&work->unk_008), (void*)work->unk_000, (void*)work->unk_004, f, 0xC01,
        0xFE00);
}

void task_bos_ursula_backtako_3(UrsulaBacktakoWork* work) {
    ReleaseObjTiles((void*)work->unk_000);
    ReleaseObjPalette((void*)work->unk_004);
}

void task_bos_ursula_mapanime_0(UrsulaMapanimeWork* work) {
    gUnk_02034F10 = work;
    TaskPoolInit(&work->unk_010, 1);
    work->unk_024 = 0;
    work->unk_00C = 4;
    func_080DD69C(0);
}

u8 task_bos_ursula_mapanime_1(UrsulaMapanimeWork* work) {
    s32 d;

    func_080DDDEC(&work->unk_000, work->unk_000.unk_08, 0);

    if (func_080DDE74(&work->unk_000) != 0) {
        if (work->unk_000.unk_08 == &gUnk_096FE278) {
            if (work->unk_00C == 1) {
                func_080DDDDC(&work->unk_000, &gUnk_096FE290);
                work->unk_00C = 4;
            } else if (work->unk_00C == 2) {
                func_080DDDDC(&work->unk_000, &gUnk_096FE2A8);
                work->unk_00C = 4;
            }
        } else if (work->unk_000.unk_08 == &gUnk_096FE290
                || work->unk_000.unk_08 == &gUnk_096FE2A8) {
            func_080DDDDC(&work->unk_000, &gUnk_096FE2C0);
            work->unk_00C = 4;
        } else if (work->unk_000.unk_08 == &gUnk_096FE2C0) {
            func_080DDDDC(&work->unk_000, &gUnk_096FE260);
            work->unk_00C = 0;
        }
    }

    if (work->unk_000.unk_08 == &gUnk_096FE2A8 && func_080DDEA0(&work->unk_000) == 2) {
        if (work->unk_028 == 0) {
            work->unk_028 = 1;
            func_080168B8(gUnk_02039B84->unk_0CC, gUnk_02039B84->unk_0D0 + 0xC00,
                gUnk_02039B84->unk_0D4, func_080DC510(), 0x266, 0x78);
        } else {
            func_08014780(gUnk_02039B84->unk_0CC, gUnk_02039B84->unk_0D0 + 0xC00,
                gUnk_02039B84->unk_0D4);
        }

        d = func_080DC510() != 0 ? -0x5000 : 0x5000;
        func_08011F78(0xF3, gUnk_02039B84->unk_0CC + d, 0x1C400, 0, 0x18, 0x38, 0x50);
    }

    if (work->unk_000.unk_08 == &gUnk_096FE290 && func_080DDEA0(&work->unk_000) == 2
            && work->unk_028 == 0) {
        work->unk_028 = 1;
        work->unk_024 = TaskCreate(&work->unk_010, gUnk_09EF5250, 0);
    }

    TaskPoolUpdate(&work->unk_010);

    return 1;
}

void task_bos_ursula_mapanime_2(UrsulaMapanimeWork* work) {
    TaskPoolDraw(&work->unk_010);
}

void task_bos_ursula_mapanime_3(UrsulaMapanimeWork* work) {
    TaskPoolDestroy(&work->unk_010);
}

void func_080DD69C(s32 a) {
    if (func_08000F48(gUnk_02034F10->unk_024) != 0) {
        if (strcmp(func_08000F84(gUnk_02034F10->unk_024), gUnk_096FE2F4) == 0) {
            func_080DD9B0(((UrsulaBubbleWork**)gUnk_02034F10->unk_024)[1]);
        } else {
            func_08000DE8(&gUnk_02034F10->unk_010, gUnk_02034F10->unk_024);
        }
    }

    if (a == 3) {
        gUnk_02034F10->unk_024 = TaskCreate(&gUnk_02034F10->unk_010, gUnk_09EF5280, 0);
    } else if (gUnk_02034F10->unk_00C != a) {
        gUnk_02034F10->unk_00C = a;

        if (a == 0) {
            func_080DDDDC(&gUnk_02034F10->unk_000, &gUnk_096FE2C0);
            gUnk_02034F10->unk_028 = 1;
        } else {
            func_080DDDDC(&gUnk_02034F10->unk_000, &gUnk_096FE278);
            gUnk_02034F10->unk_028 = 0;
            m4aSongNumStart(0x111);
        }
    }
}

u8 func_080DD754(void) {
    if (gUnk_02034F10->unk_000.unk_08 == &gUnk_096FE290 || gUnk_02034F10->unk_000.unk_08 == &gUnk_096FE2A8 || gUnk_02034F10->unk_000.unk_08 == &gUnk_096FE278) {
        return 1;
    }

    return func_08000F48((void*)gUnk_02034F10->unk_024);
}

u8 func_080DD794(void) {
    if (gUnk_02034F10->unk_000.unk_08 == &gUnk_096FE2A8 && func_080DDEA0(&gUnk_02034F10->unk_000) == 2) {
        return 1;
    }

    return 0;
}

u16 func_080DD7C4(UrsulaBubbleWork* work) {
    s8 v = 0x60;

    if (func_080DC510() != 0) {
        v = -v;
    }

    work->unk_018[0] = TaskCreate(&work->unk_004, gUnk_09EF5268, &v);
    v = 0x20;

    if (func_080DC510() != 0) {
        v = -v;
    }

    work->unk_018[1] = TaskCreate(&work->unk_004, gUnk_09EF5268, &v);
    v = 0x40;

    if (func_080DC510() != 0) {
        v = -v;
    }

    work->unk_018[2] = TaskCreate(&work->unk_004, gUnk_09EF5268, &v);

    return 3;
}

u16 func_080DD854(UrsulaBubbleWork* work) {
    s8 v;
    s32 i;
    u8 a = 14;

    for (i = 0; i <= 5; i++) {
        v = a;

        if (func_080DC510() != 0) {
            v = -v;
        }

        work->unk_018[i] = TaskCreate(&work->unk_004, gUnk_09EF5268, &v);
        a += 20;
    }

    return i;
}

u16 func_080DD8A8(UrsulaBubbleWork* work) {
    s8 v;
    s32 i;
    u8 a = 240;

    for (i = 0; i <= 9; i++) {
        v = a;

        if (func_080DC510() != 0) {
            v = -v;
        }

        work->unk_018[i] = TaskCreate(&work->unk_004, gUnk_09EF5268, &v);
        a += 16;
    }

    return i;
}

void task_bos_ursula_bubble_0(UrsulaBubbleWork* work) {
    TaskPoolInit(&work->unk_004, 10);
    work->unk_040 = 0;

    switch (func_080DC5E8()) {
    case 2:
        work->unk_040 = func_080DD8A8(work);
        break;
    case 1:
        work->unk_040 += func_080DD854(work);
        break;
    case 0:
    default:
        work->unk_040 += func_080DD7C4(work);
        break;
    }

    m4aSongNumStart(640);
}

u8 task_bos_ursula_bubble_1(UrsulaBubbleWork* work) {
    s32 i;

    TaskPoolUpdate(&work->unk_004);

    for (i = 0; i < work->unk_040; i++) {
        if (func_08000F48(work->unk_018[i]) != 0) {
            break;
        }
    }

    if (i == work->unk_040) {
        return 0;
    }

    return 1;
}

void task_bos_ursula_bubble_2(UrsulaBubbleWork* work) {
    TaskPoolDraw(&work->unk_004);
}

#ifndef VERSION_EU
void task_bos_ursula_bubble_3(UrsulaBubbleWork* work) {
    TaskPoolDestroy(&work->unk_004);
}
#else
INCLUDE_ASM("bos4/task_bos_ursula_bubble_3.s");
#endif

void func_080DD9B0(UrsulaBubbleWork* work) {
    s32 i;

    for (i = 0; i < work->unk_040; i++) {
        if (func_08000F48(work->unk_018[i]) != 0) {
            func_080DDD30(*(void**)((u8*)work->unk_018[i] + 4));
        }
    }
}

void task_bos_ursula_bubble_single_0(UrsulaBubbleSingleWork* work, u8* arg) {
    work->unk_13C = *arg;
    work->unk_140 = 0x333;
    func_0801B37C(&work->unk_024, gUnk_096FE324, gUnk_02039B84->unk_0CC,
        gUnk_02039B84->unk_0D0 + 0x1000, gUnk_02039B84->unk_0D4);
    func_0801C2DC(&work->unk_024, 1);
    work->unk_000 = LoadObjTiles(gUnk_097A0DE4, 0xA80);
    work->unk_004 = LoadObjPalette(gUnk_0984B0F8, 32);
    work->unk_008 = LoadObjPalette(gUnk_08F69BC4, 32);
    AnimInit(&work->unk_00C, gUnk_09EF68D8, gUnk_09EF68C0);
    AnimStart(&work->unk_00C, 0, 1);
    work->unk_138 = 0;
    work->unk_134 = 0x3C;
}
u8 task_bos_ursula_bubble_single_1(UrsulaBubbleSingleWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_024;

    work->unk_140 -= 12;

    if (work->unk_140 < 0x166) {
        work->unk_140 = 0x166;
    }

    if (work->unk_138 == 0) {
        p->unk_04 += gSineTable[(u8)work->unk_13C] * work->unk_140 >> 8;
        p->unk_0C += -gSineTable[(u8)work->unk_13C + 0x40] * work->unk_140 >> 8;
        work->unk_134--;

        if (p->unk_0C >= 0) {
            p->unk_0C = 0;
            work->unk_134 = 0;
        }

        if (work->unk_134 == 0) {
            work->unk_134 = 180;
            work->unk_138 = 1;
        }
    }

    if (work->unk_138 == 1 && work->unk_134 != 0) {
        work->unk_13E = (u8)GetAngle(p->unk_04, p->unk_0C,
            *(s32*)((u8*)gUnk_02039B84->unk_07C + 4), *(s32*)((u8*)gUnk_02039B84->unk_07C + 12));
        ApproachAngle(&work->unk_13C, work->unk_13E, 4);
        p->unk_04 += gSineTable[(u8)work->unk_13C] * work->unk_140 >> 8;
        p->unk_0C += -gSineTable[(u8)work->unk_13C + 0x40] * work->unk_140 >> 8;

        if (work->unk_134 <= 169) {
            ApproachValue(&p->unk_08, *(s32*)((u8*)gUnk_02039B84->unk_07C + 8), 30);
        }

        if ((u32)p->unk_04 > 0x20800 || p->unk_08 > 0x20800) {
            return 0;
        }

        work->unk_134--;

        if (work->unk_134 == 0) {
            AnimStart(&work->unk_00C, 1, 0);
            func_0801C2DC(&work->unk_024, 1);
        }
    }

    if (func_08005B30(&work->unk_00C) == 0
            && func_08011F78(0xF2, p->unk_04, p->unk_08, p->unk_0C, 1, 1, 1) == 1) {
        m4aSongNumStart(0x281);

        return 0;
    }

    if (func_08005B30(&work->unk_00C) == 1 && AnimIsFinished(&work->unk_00C) != 0) {
        return 0;
    }

    AnimUpdate(&work->unk_00C);
    func_08012324((u8*)p + 0x40, p->unk_04, p->unk_08, p->unk_0C);

    return 1;
}

void task_bos_ursula_bubble_single_2(UrsulaBubbleSingleWork* work) {
    UnkStruct_080DFF1C* p = (UnkStruct_080DFF1C*)&work->unk_024;
    void* pal;
    u16 v;
    s16 x;
    s16 y;

    v = func_0801AF1C(p->unk_08);
    pal = func_0801CA00(p) != 0 ? work->unk_008 : work->unk_004;
    WorldToScreen(&x, &y, p->unk_04, p->unk_08, p->unk_0C);
    DrawSprite(x, y, AnimGetGfx(&work->unk_00C), work->unk_000, pal, 0, v, -0x1004 - (p->unk_08 >> 8) * 4);
}

void task_bos_ursula_bubble_single_3(UrsulaBubbleSingleWork* work) {
    func_0801B7D8(&work->unk_024);
    ReleaseObjTiles((void*)work->unk_000);
    ReleaseObjPalette((void*)work->unk_004);
    ReleaseObjPalette((void*)work->unk_008);
}

void func_080DDD30(UrsulaBubbleSingleWork* work) {
    if (func_08005B30(&work->unk_00C) == 0) {
        work->unk_134 = 0;
        AnimStart(&work->unk_00C, 1, 0);
        func_0801C2DC(&work->unk_024, 1);
        work->unk_138 = 2;
    }
}

void task_bos_ursula_thunder_0(UrsulaThunderWork* work) {
    u8* p = (u8*)gUnk_02039B84->unk_07C;

    work->unk_004 = *(s32*)(p + 4);
    work->unk_008 = *(s32*)(p + 8);
    work->unk_00C = *(s32*)(p + 12) - 0x6000;
    func_08017390(work->unk_004, work->unk_008, work->unk_00C);
    work->unk_000 = 0;
}

u8 task_bos_ursula_thunder_1(UrsulaThunderWork* work) {
    if (func_080128EC() == 0) {
        if (work->unk_000 != 0) {
            return 0;
        }

        func_080155BC(work->unk_004, work->unk_008, 0, 244);
        work->unk_000 = 1;
    }

    return 1;
}

void task_bos_ursula_thunder_2(void) {
}

void task_bos_ursula_thunder_3(void) {
}

void func_080DDDDC(UnkStruct_080DDDDC* p, UnkStruct_096FE034* q) {
    p->unk_00 = 0;
    p->unk_02 = 0;
    p->unk_04 = 1;
    p->unk_08 = q;
}

u8 func_080DDDEC(UnkStruct_080DDDDC* p, UnkStruct_096FE034* q, u8 a) {
    if (p->unk_04 == 0) {
        p->unk_00++;

        if (p->unk_00 > q->unk_00[p->unk_02].unk_00) {
            p->unk_00 = 0;
            p->unk_02++;

            if (p->unk_02 >= q->unk_04) {
                p->unk_02 = 0;
            }
        }
    }

    if (a == 0) {
        if (p->unk_00 == 0 || p->unk_04 != 0) {
            RequestDma3Copy((u8*)q->unk_08 + q->unk_10 * q->unk_00[p->unk_02].unk_02,
                (u8*)GetBgCharBase(q->unk_14) + q->unk_0C, q->unk_0E);
            p->unk_04 = 0;
        }
    } else if (p->unk_00 == 0) {
        p->unk_04 = 1;
    }

    return a;
}

u8 func_080DDE74(UnkStruct_080DDDDC* p) {
    UnkStruct_096FE034* q = p->unk_08;

    if (p->unk_00 + 1 > q->unk_00[p->unk_02].unk_00 && p->unk_02 + 1 >= q->unk_04) {
        return 1;
    }

    return 0;
}

u16 func_080DDEA0(UnkStruct_080DDDDC* p) {
    return p->unk_02;
}

void func_080DDEA4(s32 a) {
    func_080D2C78(a);
}

void func_080DDEB0(s32 a) {
    func_080D2DB0(a);
}

void func_080DDEBC(s32 a) {
    func_080D2DC4(a);
}

void func_080DDEC8(u8* p, u8 a) {
    if (p[5] != a) {
        p[5] = a;

        if (a != 0) {
            func_0805FCB0(80, 68, 2, gUnk_0984B74C);
        } else {
            func_0805FCB0(80, 68, 2, gUnk_0984B754);
        }
    }
}

void func_080DDF04(u8 a, u8 b) {
    if ((gUnk_02039BB0.flags & 8) != 0) {
        if (b != 0) {
            switch (a) {
            case 0:
                gUnk_0203C590.unk_00 = 1;
                break;
            case 1:
                gUnk_0203C590.unk_00 = 3;
                break;
            case 2:
                gUnk_0203C590.unk_00 = 5;
                break;
            case 3:
                gUnk_0203C590.unk_00 = 7;
                break;
            case 4:
                gUnk_0203C590.unk_00 = 9;
                break;
            case 5:
                gUnk_0203C590.unk_00 = 11;
                break;
            case 6:
                gUnk_0203C590.unk_00 = 13;
                break;
            case 7:
                gUnk_0203C590.unk_00 = 15;
                break;
            case 8:
                gUnk_0203C590.unk_00 = 17;
                break;
            case 9:
                gUnk_0203C590.unk_00 = 19;
                break;
            case 10:
                gUnk_0203C590.unk_00 = 22;
                break;
            case 11:
                gUnk_0203C590.unk_00 = 24;
                break;
            }
        } else {
            switch (a) {
            case 0:
                gUnk_0203C590.unk_00 = 0;
                break;
            case 1:
                gUnk_0203C590.unk_00 = 2;
                break;
            case 2:
                gUnk_0203C590.unk_00 = 4;
                break;
            case 3:
                gUnk_0203C590.unk_00 = 6;
                break;
            case 4:
                gUnk_0203C590.unk_00 = 8;
                break;
            case 5:
                gUnk_0203C590.unk_00 = 10;
                break;
            case 6:
                gUnk_0203C590.unk_00 = 12;
                break;
            case 7:
                gUnk_0203C590.unk_00 = 14;
                break;
            case 8:
                gUnk_0203C590.unk_00 = 16;
                break;
            case 9:
                gUnk_0203C590.unk_00 = 18;
                break;
            case 10:
                gUnk_0203C590.unk_00 = 20;
                break;
            case 11:
                gUnk_0203C590.unk_00 = 23;
                break;
            }
        }
    } else {
        if (b != 0) {
            switch (a) {
            case 0:
                gUnk_0203C590.unk_00 = 1;
                break;
            case 1:
                gUnk_0203C590.unk_00 = 3;
                break;
            case 2:
                gUnk_0203C590.unk_00 = 5;
                break;
            case 3:
                gUnk_0203C590.unk_00 = 7;
                break;
            case 4:
                gUnk_0203C590.unk_00 = 9;
                break;
            case 5:
                gUnk_0203C590.unk_00 = 11;
                break;
            case 6:
                gUnk_0203C590.unk_00 = 13;
                break;
            case 7:
                gUnk_0203C590.unk_00 = 15;
                break;
            case 8:
                gUnk_0203C590.unk_00 = 17;
                break;
            case 9:
                gUnk_0203C590.unk_00 = 19;
                break;
            case 10:
                gUnk_0203C590.unk_00 = 21;
                break;
            case 11:
                gUnk_0203C590.unk_00 = 23;
                break;
            case 12:
                gUnk_0203C590.unk_00 = 27;
                break;
            }
        } else {
            switch (a) {
            case 0:
                gUnk_0203C590.unk_00 = 0;
                break;
            case 1:
                gUnk_0203C590.unk_00 = 2;
                break;
            case 2:
                gUnk_0203C590.unk_00 = 4;
                break;
            case 3:
                gUnk_0203C590.unk_00 = 6;
                break;
            case 4:
                gUnk_0203C590.unk_00 = 8;
                break;
            case 5:
                gUnk_0203C590.unk_00 = 10;
                break;
            case 6:
                gUnk_0203C590.unk_00 = 12;
                break;
            case 7:
                gUnk_0203C590.unk_00 = 14;
                break;
            case 8:
                gUnk_0203C590.unk_00 = 16;
                break;
            case 9:
                gUnk_0203C590.unk_00 = 18;
                break;
            case 10:
                gUnk_0203C590.unk_00 = 20;
                break;
            case 11:
                gUnk_0203C590.unk_00 = 22;
                break;
            case 12:
                gUnk_0203C590.unk_00 = 25;
                break;
            }
        }
    }
}
void func_080DE2A4(UnkStruct_02034F14* p) {
    if ((GetKeysRepeat() & 0x20) != 0) {
        p->unk_01 = p->unk_01 == 0 ? 4 : p->unk_01 - 1;
    }

    if ((GetKeysRepeat() & 0x10) != 0) {
        p->unk_01 = p->unk_01 > 3 ? 0 : p->unk_01 + 1;
    }

    func_0805FCB0(80, 32, 2, gUnk_09EF6960[p->unk_01]);
}
void func_080DE2FC(UnkStruct_02034F14* p) {
    u8 v = p->unk_02;
    const u8* t;
    s32 n;

    if ((GetKeysRepeat() & 0x20) != 0) {
        p->unk_02 = p->unk_02 == 0 ? 12 : p->unk_02 - 1;
    }

    if ((GetKeysRepeat() & 0x10) != 0) {
        p->unk_02 = p->unk_02 > 11 ? 0 : p->unk_02 + 1;
    }

    if (v != p->unk_02) {
        t = gUnk_0984B458[0];
        n = p->unk_02 * 8;
        t += 4;
        func_0805FCB0(80, 44, 2, *(const char**)(t + n));
    }
}
void func_080DE35C(UnkStruct_02034F14* p) {
    if ((GetKeysRepeat() & 0x20) != 0) {
        p->unk_03 = p->unk_03 == 0 ? 13 : p->unk_03 - 1;
    }

    if ((GetKeysRepeat() & 0x10) != 0) {
        p->unk_03 = p->unk_03 > 12 ? 0 : p->unk_03 + 1;
    }

    func_0805FC04(80, 56, 2, p->unk_03 + 1);
    func_0805FCB0(112, 56, 2, gUnk_0984B75C);

    if (12 - p->unk_03 > 0) {
        func_0805FC04(128, 56, 2, 12 - p->unk_03);
    } else {
        func_0805FCB0(112, 56, 2, gUnk_0984B76C);
    }
}
void func_080DE3E8(UnkStruct_02034F14* p) {
    u8 v = p->unk_04;

    if ((GetKeysRepeat() & 0x20) != 0) {
        p->unk_04 = p->unk_04 == 0 ? 12 : p->unk_04 - 1;
    }

    if ((GetKeysRepeat() & 0x10) != 0) {
        p->unk_04 = p->unk_04 > 11 ? 0 : p->unk_04 + 1;
    }

    if (v != p->unk_04) {
        func_080E5510(p->unk_04 + 15);
        func_0805FCB0(80, 80, 2, gUnk_09EF6974[p->unk_04]);
        func_0805FC04(80, 92, 2, gUnk_02034F18->unk_02);
        func_0805FC04(80, 104, 2, gUnk_02034F18->unk_03);
        func_0805FC04(80, 116, 2, gUnk_02034F18->unk_04);
        func_0805FC04(80, 128, 2, gUnk_02034F18->unk_05);
        func_0805FC04(80, 140, 2, gUnk_02034F18->unk_06);
        func_080DDEC8((u8*)p, 1);
    }
}
void func_080DE4A4(UnkStruct_02034F14* p) {
    u8 v = gUnk_02034F18->unk_02;

    if ((GetKeysRepeat() & 0x20) != 0 && v > 8) {
        v--;
    }

    if ((GetKeysRepeat() & 0x10) != 0 && v <= 47) {
        v++;
    }

    if (gUnk_02034F18->unk_02 != v) {
        gUnk_02034F18->unk_02 = v;
        gUnk_02034F18->unk_01 = v;
        func_0805FC04(80, 92, 2, gUnk_02034F18->unk_02);
        func_080DDEC8((u8*)p, 1);
    }
}
void func_080DE50C(UnkStruct_02034F14* p) {
    if ((GetKeysRepeat() & 0x30) != 0) {
        func_080DDEC8((u8*)p, p->unk_05 == 0 ? 1 : 0);
    }
}
void func_080DE534(UnkStruct_02034F14* p) {
    u8 v = gUnk_02034F18->unk_03;

    if ((GetKeysRepeat() & 0x20) != 0 && v > 2) {
        v--;
    }

    if ((GetKeysRepeat() & 0x10) != 0 && v <= 9) {
        v++;
    }

    if (gUnk_02034F18->unk_03 != v) {
        gUnk_02034F18->unk_03 = v;
        func_0805FC04(80, 104, 2, gUnk_02034F18->unk_03);

        if (gUnk_02034F18->unk_04 < v) {
            gUnk_02034F18->unk_04 = v;
            func_0805FC04(80, 116, 2, gUnk_02034F18->unk_04);
        }

        func_080DDEC8((u8*)p, 1);
    }
}
void func_080DE5B0(UnkStruct_02034F14* p) {
    u8 v = gUnk_02034F18->unk_04;

    if ((GetKeysRepeat() & 0x20) != 0 && v > 2) {
        v--;
    }

    if ((GetKeysRepeat() & 0x10) != 0 && v <= 9) {
        v++;
    }

    if (gUnk_02034F18->unk_04 != v) {
        gUnk_02034F18->unk_04 = v;
        func_0805FC04(80, 116, 2, gUnk_02034F18->unk_04);

        if (gUnk_02034F18->unk_03 > v) {
            gUnk_02034F18->unk_03 = v;
            func_0805FC04(80, 104, 2, gUnk_02034F18->unk_03);
        }

        func_080DDEC8((u8*)p, 1);
    }
}
void func_080DE62C(UnkStruct_02034F14* p) {
    u8 v = gUnk_02034F18->unk_05;

    if ((GetKeysRepeat() & 0x20) != 0 && v > 3) {
        v--;
    }

    if ((GetKeysRepeat() & 0x10) != 0 && v <= 47) {
        v++;
    }

    if (gUnk_02034F18->unk_05 != v) {
        gUnk_02034F18->unk_05 = v;
        func_0805FC04(80, 128, 2, gUnk_02034F18->unk_05);

        if (gUnk_02034F18->unk_06 < v) {
            gUnk_02034F18->unk_06 = v;
            func_0805FC04(80, 140, 2, gUnk_02034F18->unk_06);
        }

        func_080DDEC8((u8*)p, 1);
    }
}
void func_080DE6A8(UnkStruct_02034F14* p) {
    u8 v = gUnk_02034F18->unk_06;

    if ((GetKeysRepeat() & 0x20) != 0 && v > 3) {
        v--;
    }

    if ((GetKeysRepeat() & 0x10) != 0 && v <= 47) {
        v++;
    }

    if (gUnk_02034F18->unk_06 != v) {
        gUnk_02034F18->unk_06 = v;
        func_0805FC04(80, 140, 2, gUnk_02034F18->unk_06);

        if (gUnk_02034F18->unk_05 > v) {
            gUnk_02034F18->unk_05 = v;
            func_0805FC04(80, 128, 2, gUnk_02034F18->unk_05);
        }

        func_080DDEC8((u8*)p, 1);
    }
}
void func_080DE724(void) {
    const u8* t;
    s32 n;

    gUnk_02034F14 = (UnkStruct_02034F14*)EwramAlloc(8);
    SaveLoadHeader();
    gUnk_0203C584 = 0;
    gUnk_02034F14->unk_00 = 0;
    gUnk_02034F14->unk_01 = 0;
    gUnk_02034F14->unk_02 = 0;
    gUnk_02034F14->unk_03 = 1;
    gUnk_02034F14->unk_04 = 0;
    gUnk_02034F14->unk_05 = 0;
    gUnk_02039BB0.unk_1B8 = 0;
    func_080E5510(gUnk_02034F14->unk_04);
    gUnk_02034F18 = &gUnk_0203C7B0;
    func_08004DB0();
    SetupBg(0, 0, 15, 0);
    EnableBg(0);
    func_0805FA8C(0, 0x5400, 0x500);
    func_0805FA60(0, gUnk_0984B72C, 32, 15);
    func_0805FCB0(0, 0, 2, gUnk_0984B77C);
    func_0805FCB0(24, 32, 2, gUnk_0984B7B0);
    func_0805FCB0(24, 44, 2, gUnk_0984B7C0);
    func_0805FCB0(24, 56, 2, gUnk_0984B7D0);
    func_0805FCB0(24, 68, 2, gUnk_0984B7E0);
    func_0805FCB0(24, 80, 2, gUnk_0984B7F0);
    func_0805FCB0(24, 92, 2, gUnk_0984B800);
    func_0805FCB0(24, 104, 2, gUnk_0984B810);
    func_0805FCB0(24, 128, 2, gUnk_0984B820);
    func_0805FCB0(80, 68, 2, gUnk_0984B754);
    func_0805FCB0(80, 32, 2, gUnk_09EF6960[gUnk_02034F14->unk_01]);
    t = gUnk_0984B458[0];
    n = gUnk_02034F14->unk_02 * 8;
    t += 4;
    func_0805FCB0(80, 44, 2, *(const char**)(t + n));
    func_0805FC04(80, 56, 2, gUnk_02034F14->unk_03 + 1);
    func_0805FCB0(80, 80, 2, gUnk_09EF6974[gUnk_02034F14->unk_04]);
    func_0805FC04(80, 92, 2, gUnk_02034F18->unk_02);
    func_0805FC04(80, 104, 2, gUnk_02034F18->unk_03);
    func_0805FC04(80, 116, 2, gUnk_02034F18->unk_04);
    func_0805FC04(80, 128, 2, gUnk_02034F18->unk_05);
    func_0805FC04(80, 140, 2, gUnk_02034F18->unk_06);
    func_08006120(0, 8);
    m4aMPlayAllStop();
}
void func_080DE910(void) {
    UnkStruct_02034F14* e;

    func_0805FCB0(12, gUnk_02034F14->unk_00 * 12 + 32, 2, gUnk_0984B830);

    if ((GetKeysRepeat() & 0x40) != 0) {
        gUnk_02034F14->unk_00 = gUnk_02034F14->unk_00 == 0 ? 9 : gUnk_02034F14->unk_00 - 1;
    }

    if ((GetKeysRepeat() & 0x80) != 0) {
        gUnk_02034F14->unk_00 = gUnk_02034F14->unk_00 > 8 ? 0 : gUnk_02034F14->unk_00 + 1;
    }

    func_0805FCB0(12, gUnk_02034F14->unk_00 * 12 + 32, 2, gUnk_0984B834);
    gUnk_09EF69A8[gUnk_02034F14->unk_00](gUnk_02034F14);

    if ((GetKeysPressed() & 9) != 0) {
        func_08085FB0();

        if ((gUnk_02039BB0.flags & 8) == 0) {
            func_08085C3C();
        }

        func_08093BB4();
        gUnk_0203C584 = gUnk_02034F14->unk_05;
        gUnk_02039BB0.unk_17C |= 2;
        gUnk_02039BB0.unk_17C |= 1;
        gUnk_02039BB0.unk_17A |= 0x778;
        e = gUnk_02034F14;

        switch (e->unk_01) {
        case 1:
            gUnk_02039BB0.unk_184[e->unk_03].unk_02 = gUnk_0984B458[e->unk_02][0];
            func_080DDF04(gUnk_02034F14->unk_03, 0);
            func_080DF990(gUnk_02034F14->unk_03);
            func_080DFA18(gUnk_0984B458[gUnk_02034F14->unk_02][0]);
            gUnk_0203C590.unk_02 |= 0x10;
            func_080DFA3C();
            func_080E04EC();
            break;
        case 2:
            gUnk_02039BB0.unk_184[e->unk_03].unk_02 = 0;
            func_080DDF04(gUnk_02034F14->unk_03, 0);
            func_080DF990(gUnk_02034F14->unk_03);
            gUnk_0203C590.unk_06 = 0xFE;
            gUnk_0203C590.unk_07 = 5;
            func_080E04EC();
            break;
        case 3:
            gUnk_02039BB0.unk_184[gUnk_02034F14->unk_03].unk_02 = gUnk_0984B458[gUnk_02034F14->unk_02][0];
            func_080DDF04(gUnk_02034F14->unk_03, 1);
            func_080DF990(gUnk_02034F14->unk_03);
            gUnk_0203C590.unk_06 = 0xFD;
            gUnk_0203C590.unk_07 = 5;
            func_080E04EC();
            break;
        case 4:
            gUnk_02039BB0.unk_184[0].unk_02 = 10;
            func_080DF990(0);
            func_080DFA18(10);
            gUnk_0203C590.unk_06 = 0xFC;
            gUnk_0203C590.unk_07 = 5;
            func_080E04EC();
            break;
        default:
            gUnk_02039BB0.unk_184[gUnk_02034F14->unk_03].unk_02 =
                gUnk_0984B458[gUnk_02034F14->unk_02][0];
            func_080DDF04(gUnk_02034F14->unk_03, 0);
            func_080DF990(gUnk_02034F14->unk_03);
            func_080DFA18(gUnk_0984B458[gUnk_02034F14->unk_02][0]);
            func_080DFA3C();
            ModeRequest(gUnk_09EF6A90, 0);
            break;
        }
    } else if ((GetKeysPressed() & 6) != 0) {
        ModeRequest(gModeDebug, 0);
    } else {
        func_080605A4(0);
        func_08060598();
    }
}

void func_080DEB94(void) {
    func_080609A0();
    EwramFree(gUnk_02034F14);
}

u8 func_080DEBAC(u8 a) {
    switch (a) {
    case 0:
        a = 1;
        break;
    case 1:
        a = 0;
        break;
    case 2:
        a = 3;
        break;
    case 3:
        a = 2;
        break;
    }

    return a;
}

void func_080DEBD8(UnkStruct_080DEDD8* p) {
    UnkStruct_080DEE18* e;

    if (p->unk_00 == 1 || p->unk_00 == 4) {
        e = func_080DEE18(p->unk_02);
        e->unk_0A = 0;
        e->unk_08 = 26;
        e->unk_09 = 0;
        e->unk_00 |= 8;
    }
}

void func_080DEC00(void) {
    if (gUnk_02039BB0.flags & 8) {
        switch ((s8)gUnk_02039BB0.floor) {
        case 1:
        case 5:
        case 8:
        case 9:
        case 10:
        case 11:
            gUnk_0203C590.unk_07 = 5;
            break;
        }
    } else {
        if ((s8)gUnk_02039BB0.floor != 12) {
            gUnk_0203C590.unk_07 = 5;
        }
    }
}

void func_080DEC44(void) {
    u16 t;

    if ((s8)gUnk_02039BB0.floor != func_080DF750() || gUnk_0203C590.unk_06 == 0xFE
            || gUnk_0203C590.unk_06 == 0xFD) {
        if ((gUnk_02039BB0.flags & 0x80) == 0) {
            gUnk_02039BB0.flags |= 0x80;
            gUnk_02039BB0.unk_17E = gUnk_02039BB0.unk_17C & 0x7C;
        }

        if ((gUnk_02039BB0.flags & 8) != 0) {
            return;
        }

        t = gUnk_02039BB0.unk_17C & 0xFF83;
        gUnk_02039BB0.unk_17C = t;

        if (gUnk_0203C590.unk_06 >= 0xFD && gUnk_0203C590.unk_06 <= 0xFE) {
            return;
        }

        switch (gUnk_0203C590.unk_04) {
        case 1:
            t = 4 | gUnk_02039BB0.unk_17C;
            gUnk_02039BB0.unk_17C = t;
            break;
        case 2:
            t = 8 | gUnk_02039BB0.unk_17C;
            gUnk_02039BB0.unk_17C = t;
            break;
        case 6:
            t = 0x10 | gUnk_02039BB0.unk_17C;
            gUnk_02039BB0.unk_17C = t;
            break;
        case 7:
            t = 0x20 | gUnk_02039BB0.unk_17C;
            gUnk_02039BB0.unk_17C = t;
            break;
        case 8:
            t = 0x40 | gUnk_02039BB0.unk_17C;
            gUnk_02039BB0.unk_17C = t;
            break;
        case 3:
        case 4:
        case 5:
        default:
            break;
        }
    } else {
        if ((gUnk_02039BB0.flags & 0x80) == 0) {
            return;
        }

        gUnk_02039BB0.flags &= ~0x80;
        t = (gUnk_02039BB0.unk_17C & 0xFF83) | gUnk_02039BB0.unk_17E;
        gUnk_02039BB0.unk_17C = t;
    }
}

UnkStruct_0984C868* func_080DED64(u8 a) {
    if (gUnk_02039BB0.flags & 8) {
        return &gUnk_0984CBD0[a];
    }

    return &gUnk_0984C868[a];
}

u8* func_080DED98(u8 a) {
    if (gUnk_02039BB0.flags & 8) {
        return gUnk_0984CBD0[(s8)gUnk_02039BB0.floor].unk_04 + a * 4;
    }

    return gUnk_0984C868[(s8)gUnk_02039BB0.floor].unk_04 + a * 4;
}

UnkStruct_080DEDD8* func_080DEDD8(u8 a) {
    if (gUnk_02039BB0.flags & 8) {
        return gUnk_0984CBD0[(s8)gUnk_02039BB0.floor].unk_08 + a;
    }

    return gUnk_0984C868[(s8)gUnk_02039BB0.floor].unk_08 + a;
}

UnkStruct_080DEE18* func_080DEE18(u8 index) {
    return &gUnk_0203C5AC[index];
}

u8 func_080DEE28(u8 a, u8 b) {
    return func_080DED98(a)[b];
}

u16 func_080DEE44(u8 a, u8 b) {
    UnkStruct_080DEE18* e;
    UnkStruct_080DEDD8* p;
    u16 r;
    u8 c;
    u8 d;

    c = func_080DEE28(a, b);

    if (c == 0xFF) {
        return 0;
    }

    if (c >= 0xFD && c <= 0xFE) {
        return 3;
    }

    e = func_080DEE18(c);
    r = 1;

    if ((e->unk_00 & 1) != 0) {
        r = 3;
    }

    if ((e->unk_00 & 8) != 0) {
        r |= 8;
    }

    if ((e->unk_00 & 4) != 0) {
        r |= 8;
    }

    d = func_080DF51C(c);

    if (d == 1 || d == 4 || d == 2) {
        r |= 0x10;
        p = func_080DEDD8(0);

        while (p->unk_00 != 5) {
            if (p->unk_02 == c) {
                if (p->unk_03 != b) {
                    r |= 8;
                }

                break;
            }

            p++;
        }
    }

    if ((gUnk_0203C590.unk_02 & 8) != 0) {
        p = func_080DEDD8(*func_080E54B8(gUnk_0203C590.unk_05));

        if (p->unk_02 == c && p->unk_03 == b) {
            r |= 2;
        }
    }

    return r;
}
void func_080DEF20(void) {
    u16 t;

    switch (gUnk_0203C590.unk_06) {
    case 0xFD:
    case 0xFE:
        gUnk_02039BB0.world = 0;
        gUnk_02039BB0.unk_00D = 12;
        break;
    case 0xFC:
        gUnk_02039BB0.world = 10;
        gUnk_02039BB0.unk_00D = 11;
        break;
    default:
        gUnk_02039BB0.world = gUnk_0203C590.unk_04;
        gUnk_02039BB0.unk_00D = gUnk_09EF69E0[gUnk_0203C590.unk_04];
        break;
    }

    if ((gUnk_02039BB0.flags & 8) != 0) {
        _08085D04(gUnk_02039BB0.world);

        if ((gUnk_02039BB0.flags & 8) != 0) {
            t = gUnk_02039BB0.unk_17C & 0xFF80;
            gUnk_02039BB0.unk_17C = t;
            return;
        }
    }

    switch (gUnk_02039BB0.world) {
    case 0:
        break;
    case 1:
        t = gUnk_02039BB0.unk_17C & 0xFF07;
        gUnk_02039BB0.unk_17C = t;
        break;
    case 2:
        t = gUnk_02039BB0.unk_17C & 0xFF0B;
        gUnk_02039BB0.unk_17C = t;
        break;
    case 6:
        t = gUnk_02039BB0.unk_17C & 0xFF13;
        gUnk_02039BB0.unk_17C = t;
        break;
    case 7:
        t = gUnk_02039BB0.unk_17C & 0xFF23;
        gUnk_02039BB0.unk_17C = t;
        break;
    case 8:
        t = gUnk_02039BB0.unk_17C & 0xFF43;
        gUnk_02039BB0.unk_17C = t;
        break;
    case 3:
    case 4:
    case 5:
    default:
        t = gUnk_02039BB0.unk_17C & 0xFF03;
        gUnk_02039BB0.unk_17C = t;
        break;
    }
}
void func_080DF048(void) {
    if ((gUnk_02039BB0.flags & 8) != 0) {
        switch (gUnk_02039BB0.world) {
        case 1:
            func_0800FDD0(57);
            break;
        case 2:
            func_0800FDD0(67);
            break;
        case 3:
            func_0800FDD0(50);
            break;
        case 6:
            func_0800FDD0(61);
            break;
        case 7:
            func_0800FDD0(72);
            break;
        case 8:
            func_0800FDD0(75);
            break;
        }
    } else {
        switch (gUnk_02039BB0.world) {
        case 10:
            func_0800FDD0(4);
            func_0800FDD0(28);
            func_0800FDD0(29);
            func_0800FDD0(30);
            func_0800FDD0(31);
            break;
        case 4:
            func_0800FDD0(5);
            func_0800FDD0(42);
            func_0800FDD0(43);
            func_0800FDD0(44);
            func_0800FDD0(45);
            func_0800FDD0(46);
            func_0800FDD0(47);
            break;
        case 3:
            func_0800FDD0(6);
            func_0800FDD0(32);
            func_0800FDD0(48);
            func_0800FDD0(49);
            func_0800FDD0(50);
            break;
        case 1:
            func_0800FDD0(7);
            func_0800FDD0(51);
            func_0800FDD0(52);
            func_0800FDD0(53);
            func_0800FDD0(54);
            func_0800FDD0(55);
            func_0800FDD0(56);
            func_0800FDD0(57);
            break;
        case 6:
            func_0800FDD0(8);
            func_0800FDD0(58);
            func_0800FDD0(59);
            func_0800FDD0(60);
            func_0800FDD0(61);
            break;
        case 5:
            func_0800FDD0(9);
            func_0800FDD0(62);
            func_0800FDD0(63);
            break;
        case 2:
            func_0800FDD0(10);
            func_0800FDD0(64);
            func_0800FDD0(65);
            func_0800FDD0(66);
            func_0800FDD0(67);
            func_0800FDD0(68);
            break;
        case 7:
            func_0800FDD0(11);
            func_0800FDD0(69);
            func_0800FDD0(70);
            func_0800FDD0(71);
            func_0800FDD0(72);
            break;
        case 8:
            func_0800FDD0(12);
            func_0800FDD0(73);
            func_0800FDD0(74);
            func_0800FDD0(75);
            func_0800FDD0(76);
            break;
        case 11:
            func_0800FDD0(14);
            break;
        case 9:
            func_0800FDD0(15);
            func_0800FDD0(33);
            func_0800FDD0(34);
            func_0800FDD0(35);
            break;
        }
    }
}
void func_080DF244(void) {
    if ((gUnk_02039BB0.flags & 8) != 0) {
        switch ((s8)gUnk_02039BB0.floor) {
        case 0:
            func_0800FDD0(1);
            break;
        case 2:
            func_0800FDD0(0x28);
            break;
        case 4:
            func_0800FDD0(2);
            func_0800FDD0(0xEE);
            break;
        case 8:
            func_0800FDD0(3);
            func_0800FDD0(0xF0);
            break;
        case 9:
            func_0800FDD0(0xEB);
            func_0800FDD0(0xF1);
            break;
        case 10:
            func_0800FDD0(0xEC);
            func_0800FDD0(0x24);
            func_0800FDD0(0x26);
            func_0800FDD0(0x29);
            func_0800FDD0(0x27);
            func_0800FDD0(0xF2);
            break;
        }
    } else {
        switch ((s8)gUnk_02039BB0.floor) {
        case 0:
            func_0800FDD0(0);
            func_0800FDD0(0x26);
            break;
        case 5:
            func_0800FDD0(1);
            func_0800FDD0(0x27);
            break;
        case 8:
            func_0800FDD0(2);
            break;
        case 9:
            func_0800FDD0(0x28);
            break;
        case 11:
            func_0800FDD0(3);
            func_0800FDD0(0x24);
            func_0800FDD0(0x25);
            break;
        }
    }
}
void func_080DF380(void) {
    u8* e = func_080E54B8(gUnk_0203C590.unk_05);
    UnkStruct_080DEDD8* p;
    UnkStruct_080DEE18* q;
    u16 t;
    u16 u;
    u16 v;

    if (gUnk_0203C590.unk_06 == 0xFE) {
        t = gUnk_0203C590.unk_02 | 2;
        gUnk_0203C590.unk_02 = t;

        if ((gUnk_02039BB0.flags & 8) != 0) {
            if ((s8)gUnk_02039BB0.floor == 0x0A) {
                gUnk_0203C590.unk_00++;
            }
        } else {
            if ((s8)gUnk_02039BB0.floor == 0) {
                gUnk_0203C590.unk_06 = 0xFC;
                gUnk_0203C590.unk_07 = 5;
                return;
            }

            if ((s8)gUnk_02039BB0.floor == 0x0C) {
                gUnk_0203C590.unk_00++;
            }
        }

        func_080DFA3C();
    } else if (gUnk_0203C590.unk_06 == 0xFD) {
        u = gUnk_0203C590.unk_02 | 1;
        gUnk_0203C590.unk_02 = u;
        func_080DF244();
        gUnk_0203C590.unk_00++;
        func_080DFAA8();
        func_080DF9A8();
        func_080DEC00();
    } else if (e[0] == 0xFF) {
        v = gUnk_0203C590.unk_02 | 4;
        gUnk_0203C590.unk_02 = v;
        gUnk_0203C590.unk_00++;
        func_080DF730(0xFD, 5);
    } else {
        t = gUnk_0203C590.unk_02 & ~8;
        gUnk_0203C590.unk_02 = t;
        p = func_080DEDD8(e[0]);
        func_080DEBD8(p);
        func_080DF640(p->unk_04, 0);
        func_080DF730(p->unk_04, p->unk_05);
        gUnk_0203C590.unk_05++;

        if (e[4] == 0xFF) {
            q = func_080DEE18(func_080DED64(gUnk_02039BB0.floor)->unk_01);
            t = q->unk_00 & ~4;
            q->unk_00 = t;
            gUnk_0203C590.unk_02 |= 0x20;
            func_080DF048();
        }
    }
}

void func_080DF480(void) {
    gUnk_0203C590.unk_00++;
    func_080DF730(0xFD, 5);
}

u8 func_080DF49C(void) {
    u8* e = func_080E54B8(gUnk_0203C590.unk_05);
    UnkStruct_02034F7C* t = &gUnk_0984CECC[func_080DEDD8(*e)->unk_01];
    UnkStruct_02034F80* q;

    t += *e;
    q = t->unk_04;

    while (q->unk_00 == 0xFF) {
        q++;
    }

    return q->unk_00;
}

u8 func_080DF4D8(void) {
    if (func_080E8C84(gUnk_0203C7AC->unk_0F, gUnk_0203C7AC->unk_10) != 0) {
        return *func_080E8D1C(0);
    }

    return 0xFF;
}

u8 func_080DF500(void) {
    return func_080E8C84(gUnk_0203C7AC->unk_0F, gUnk_0203C7AC->unk_10);
}

u8 func_080DF51C(u8 a) {
    UnkStruct_080DEDD8* p = func_080DEDD8(0);

    while (p->unk_00 != 5) {
        if (p->unk_02 == a) {
            return p->unk_00;
        }

        p++;
    }

    return 0;
}

u8 func_080DF548(u8 a) {
    u8* p;
    u8* q;

    if (gUnk_0203C7AC->unk_00 < 0) {
        return 0;
    }

    p = (u8*)&gUnk_0203C590;
    q = p + a * 0x10;

    return q[0x26];
}

void func_080DF570(u8 a) {
    UnkStruct_080DEE18* e = func_080DEE18(a);
    UnkStruct_080DEDD8* p = func_080DEDD8(0);

    while (p->unk_00 != 5) {
        if (p->unk_02 == a) {
            if (p->unk_00 == 2) {
                e->unk_0A = 0;
                e->unk_08 = 27;
                e->unk_09 = 22;
                return;
            }

            gUnk_0203C590.unk_02 |= 8;
            e->unk_0A = 0;
            e->unk_08 = 26;
            e->unk_09 = 0;
        }

        p++;
    }

    if (func_080DED64(gUnk_02039BB0.floor)->unk_01 != a) {
        e->unk_0A = 0;
        e->unk_08 = 26;
        e->unk_09 = 0;
        return;
    }

    e->unk_0A = 0;
    e->unk_08 = 5;
    e->unk_09 = 23;
}

u8 func_080DF5F4(void) {
    if ((gUnk_02039BB0.flags & 8) == 0) {
        return GetRandom() % 21 + 1;
    }

    return gUnk_09EF69EE[GetRandom() % 13];
}

void func_080DF640(u8 a, UnkStruct_080DF640* p) {
    UnkStruct_080DEE18* e = func_080DEE18(a);
    const u8* row;
    const u8* anim;

    if (p == 0 && (e->unk_00 & 1) != 0) {
        return;
    }

    e->unk_00 &= ~0x10;
    e->unk_00 &= ~0x20;
    e->unk_00 |= 1;
    e->unk_04 = gFrameCounter * gFrameCounter;

    if (p != 0) {
        row = gUnk_0984D0CC[p->unk_00];
        e->unk_0A = p->unk_02;
        e->unk_08 = row[0];

        if (row[1] != 25) {
            e->unk_09 = row[1];
        } else {
            e->unk_09 = func_080DF5F4();
        }
    } else {
        func_080DF570(a);
    }

    anim = gUnk_0984D134[e->unk_09];
    e->unk_0B = anim[2];
    e->unk_0C = anim[6];
}

void func_080DF6D0(UnkStruct_0203C7AC* p, u8 a) {
    UnkStruct_080DEE18* e = func_080DEE18(a);
    const u8* row;
    u16 t;

    t = e->unk_00 | 2;
    e->unk_00 = t;
    SeedRandom(e->unk_04);
    gUnk_0203C7AC->unk_0C = e->unk_08;
    gUnk_0203C7AC->unk_0D = e->unk_09;

    if (gUnk_0203C584 == 0) {
        row = gUnk_0984D134[e->unk_09];
        gUnk_02039BB0.unk_1B8 = row[5];
        func_080E5510(row[0]);
    }
}

void func_080DF730(u8 a, u8 b) {
    gUnk_0203C590.unk_06 = a;
    gUnk_0203C590.unk_07 = func_080DEBAC(b);
    func_080DEC44();
}

u8 func_080DF750(void) {
    if ((gUnk_02039BB0.flags & 8) != 0) {
        if (gUnk_0203C590.unk_00 > 0x16) {
            return 11;
        }

        if (gUnk_0203C590.unk_00 > 0x13) {
            return 10;
        }

        if (gUnk_0203C590.unk_00 > 0x11) {
            return 9;
        }

        if (gUnk_0203C590.unk_00 > 0x0F) {
            return 8;
        }

        if (gUnk_0203C590.unk_00 > 0x0D) {
            return 7;
        }

        if (gUnk_0203C590.unk_00 > 0x0B) {
            return 6;
        }

        if (gUnk_0203C590.unk_00 > 0x09) {
            return 5;
        }

        if (gUnk_0203C590.unk_00 > 0x07) {
            return 4;
        }

        if (gUnk_0203C590.unk_00 > 0x05) {
            return 3;
        }

        if (gUnk_0203C590.unk_00 > 0x03) {
            return 2;
        }

        if (gUnk_0203C590.unk_00 <= 0x01) {
            return 0;
        }

        return 1;
    }

    if (gUnk_0203C590.unk_00 > 0x18) {
        return 12;
    }

    if (gUnk_0203C590.unk_00 > 0x15) {
        return 11;
    }

    if (gUnk_0203C590.unk_00 > 0x13) {
        return 10;
    }

    if (gUnk_0203C590.unk_00 > 0x11) {
        return 9;
    }

    if (gUnk_0203C590.unk_00 > 0x0F) {
        return 8;
    }

    if (gUnk_0203C590.unk_00 > 0x0D) {
        return 7;
    }

    if (gUnk_0203C590.unk_00 > 0x0B) {
        return 6;
    }

    if (gUnk_0203C590.unk_00 > 0x09) {
        return 5;
    }

    if (gUnk_0203C590.unk_00 > 0x07) {
        return 4;
    }

    if (gUnk_0203C590.unk_00 > 0x05) {
        return 3;
    }

    if (gUnk_0203C590.unk_00 > 0x03) {
        return 2;
    }

    if (gUnk_0203C590.unk_00 <= 0x01) {
        return 0;
    }

    return 1;
}

#ifndef VERSION_EU
u32 func_080DF804(u8 index) {
    return gUnk_09EF69FC[index];
}
#else
INCLUDE_ASM("bos4/func_080DF804.s");
#endif

void func_080DF814(void) {
    func_080DF730(0xFE, 1);
    func_080E04EC();
}

void func_080DF828(void) {
    u8 v;
    u16 f;

    if ((gUnk_0203C590.unk_02 & 4) != 0) {
        v = 0xFF;
    } else {
        if ((gUnk_02039BB0.flags & 8) != 0) {
            v = gUnk_0984B851[(s8)gUnk_02039BB0.floor];
        } else {
            v = gUnk_0984B844[(s8)gUnk_02039BB0.floor];
        }
    }

    if (v != 0xFF) {
        gUnk_02039BB0.world = 0;
        gUnk_02039BB0.unk_00D = 12;
        gUnk_02039BB0.unk_1B8 = 0;

        if ((gUnk_02039BB0.flags & 8) != 0) {
            _08085D04(0);
        }

        func_0806180C(v);
    } else {
        if ((gUnk_0203C590.unk_02 & 4) == 0) {
            f = gUnk_0203C590.unk_02 | 4;
            gUnk_0203C590.unk_02 = f;
            gUnk_0203C590.unk_00++;
        }

        func_080DF730(0xFD, 0);
        func_080E04EC();
    }
}
void func_080DF8C0(u8 a, u8 b) {
    s32 i;
    u16 t;

    gUnk_0203C590.unk_02 = gUnk_02039BB0.unk_184[(s8)gUnk_02039BB0.floor].unk_00;
    gUnk_0203C590.unk_04 = gUnk_02039BB0.unk_184[(s8)gUnk_02039BB0.floor].unk_02;
    gUnk_0203C590.unk_05 = gUnk_02039BB0.unk_184[(s8)gUnk_02039BB0.floor].unk_03;
    gUnk_0203C590.unk_06 = a;
    gUnk_0203C590.unk_07 = b;

    for (i = 0; i <= 3; i++) {
        gUnk_0203C590.unk_18[i] = 0;
        gUnk_0203C590.unk_08[i][0] = 0;
        gUnk_0203C590.unk_08[i][1] = 0;
    }

    for (i = 0; i < 32; i++) {
        gUnk_0203C590.unk_1C[i].unk_00 = 0;
        gUnk_0203C590.unk_1C[i].unk_04 = 0;
        gUnk_0203C590.unk_1C[i].unk_08 = 0;
        gUnk_0203C590.unk_1C[i].unk_0A = 0;
        gUnk_0203C590.unk_1C[i].unk_09 = 0;
    }

    gUnk_02039BB0.unk_00F = 0xFF;
    t = gUnk_0203C590.unk_02 | 0x100;
    gUnk_0203C590.unk_02 = t;
}

void func_080DF964(void) {
    s32 i;

    for (i = 0; i < gUnk_0203C590.unk_05; i++) {
        func_080DEBD8(func_080DEDD8(*func_080E54B8(i)));
    }
}

void func_080DF990(u8 a) {
    gUnk_02039BB0.floor = a;
    func_080DF8C0(0xFE, 0);
}

void func_080DF9A8(void) {
    gUnk_02039BB0.floor++;
    func_080DF8C0(0xFE, 1);
}

void func_080DF9C4(void) {
    gUnk_02039BB0.floor--;
    func_080DF8C0(0xFD, 0);
}

void func_080DF9E0(u8 a) {
    u16 t;

    func_0801CB00();
    func_080DFAA8();
    func_080DF990(a);
    gUnk_0203C590.unk_06 = 0xFE;
    gUnk_0203C590.unk_07 = 5;
    t = gUnk_0203C590.unk_02 | 0x80;
    gUnk_0203C590.unk_02 = t;
    func_080E04EC();
}

void func_080DFA18(u8 a) {
    gUnk_0203C590.unk_04 = a;
    gUnk_02039BB0.unk_184[(s8)gUnk_02039BB0.floor].unk_02 = a;
}

void func_080DFA3C(void) {
    UnkStruct_0984C868* e = func_080DED64(gUnk_02039BB0.floor);
    UnkStruct_080DEE18* p;
    u16 t;

    if ((s8)gUnk_02039BB0.floor == 13) {
        gUnk_02039BB0.floor = 0;
    }

    if (gUnk_0203C590.unk_06 == 0xFD) {
        func_080DF730(e->unk_01, 1);
    } else {
        func_080DF730(e->unk_00, 0);
    }

    func_080DF964();

    if ((gUnk_0203C590.unk_02 & 0x20) == 0) {
        p = func_080DEE18(e->unk_01);
        t = p->unk_00 | 4;
        p->unk_00 = t;
    }

    func_080DF640(gUnk_0203C590.unk_06, 0);
}

void func_080DFAA8(void) {
    gUnk_02039BB0.unk_184[(s8)gUnk_02039BB0.floor].unk_00 = gUnk_0203C590.unk_02;
    gUnk_02039BB0.unk_184[(s8)gUnk_02039BB0.floor].unk_02 = gUnk_0203C590.unk_04;
    gUnk_02039BB0.unk_184[(s8)gUnk_02039BB0.floor].unk_03 = gUnk_0203C590.unk_05;
}

void func_080DFAF4(u8 a, u8 b) {
    func_080DF990(a);
    func_080DFA18(b);

    if (a == 0) {
        gUnk_0203C590.unk_00 = 0;
        gUnk_0203C590.unk_02 &= 0xFEFF;
    }
}

void func_080DFB2C(void) {
    s32 i;

    for (i = 0; i < 13; i++) {
        gUnk_02039BB0.unk_184[i].unk_00 = 0;
        gUnk_02039BB0.unk_184[i].unk_02 = 0;
        gUnk_02039BB0.unk_184[i].unk_03 = 0;
    }

    gUnk_0203C590.unk_00 = 0;

    if ((gUnk_02039BB0.flags & 8) == 0) {
        func_08085C3C();
    }

    func_080DF990(0);
}

s32 func_080DFB7C(u8 a) {
    return func_080E5590(a);
}

UnkStruct_080DFB8C* func_080DFB8C(s32 x, s32 y) {
    s16 a = x / 0x2000;
    s16 b = y / 0x1000;

    if (gUnk_0203C7AC->unk_00 < 0) {
        return func_080E58F8(a, b);
    }

    return func_080E548C(a, b);
}

u8 func_080DFBDC(UnkStruct_080DFF1C* p) {
    s32 y = p->unk_04 + p->unk_0C;
    UnkStruct_080DFB8C* q = func_080DFB8C(p->unk_00, y);

    if (q == 0) {
        return 1;
    }

    if (q->unk_08 >= p->unk_08 && q->unk_0C != 0x100000) {
        return 0;
    }

    return func_080E86C8(q, p->unk_00, y);
}

u8 func_080DFC24(void) {
    if (gUnk_0203C7AC->unk_00 & 0x100) {
        if (gUnk_0203C590.unk_04 != 0) {
            return 2;
        }

        if ((gUnk_02039BB0.flags & 8) == 0 && (s8)gUnk_02039BB0.floor == 12) {
            func_080DFA18(12);
            return 2;
        }

        return 1;
    }

    return 0;
}

void func_080DFC7C(void) {
    gUnk_0203C7AC->unk_00 &= ~0x100;
}

u8 func_080DFC94(UnkStruct_080DFF1C* p, s32 x, s32 y) {
    s32 old;

    if (func_080DFBDC(p) != 0) {
        p->unk_00 = x;
        p->unk_04 = y;
        return 1;
    }

    old = p->unk_0C;
    p->unk_0C = func_080DFF1C(p);

    if (old != p->unk_0C) {
        if (func_080DFBDC(p) != 0) {
            p->unk_00 = x;
            p->unk_04 = y;
            p->unk_0C = old;
            return 1;
        }
    }

    return 0;
}

u8 func_080DFCDC(UnkStruct_080DFF1C* p) {
    s32 i;
    u16 a;
    u16 b;
    UnkStruct_080DFB7C* e;
    u8 r = 0;

    if (gUnk_0203C7AC->unk_00 < 0) {
        return 0;
    }

    if ((gUnk_02039BB0.unk_17A & 0x200) == 0) {
        return 0;
    }

    if (p->unk_08 != p->unk_0C) {
        return 0;
    }

    a = (p->unk_00 >> 8) / 32;
    b = ((p->unk_04 + p->unk_08) >> 8) / 16;

    for (i = 0; i <= 3; i++) {
        e = (UnkStruct_080DFB7C*)func_080DFB7C(i);

        if ((e->unk_00 & 1) != 0 && (e->unk_00 & 0xA) == 2 && e->unk_02 == a && e->unk_04 == b) {
            gUnk_0203C7AC->unk_0F = e->unk_07;
            gUnk_0203C7AC->unk_10 = e->unk_06;
            r = 1;
            break;
        }
    }

    return r;
}
u8 func_080DFD84(UnkStruct_080DFF1C* p) {
    s32 i;
    u16 a;
    u16 b;
    UnkStruct_080DFB7C* e;

    if (gUnk_0203C7AC->unk_00 < 0) {
        return (u32)gUnk_0203C7AC->unk_00 >> 9 & 1;
    }

    if (p->unk_08 != p->unk_0C) {
        return 0;
    }

    a = (p->unk_00 >> 8) / 32;
    b = ((p->unk_04 + p->unk_08) >> 8) / 16;

    for (i = 0; i <= 3; i++) {
        e = (UnkStruct_080DFB7C*)func_080DFB7C(i);

        if ((e->unk_00 & 1) != 0 && (e->unk_00 & 0xA) == 2 && e->unk_02 == a && e->unk_04 == b
                && e->unk_07 == gUnk_0203C7AC->unk_0F && e->unk_06 == gUnk_0203C7AC->unk_10) {
            return 1;
        }
    }

    return 0;
}

u8 _080DFE1C(UnkStruct_080DFF1C* p) {
    UnkStruct_080DFB8C* q = func_080DFB8C(p->unk_00, p->unk_04 + p->unk_0C);

    if (q->unk_00 & 0x20) {
        switch (q->unk_02) {
        case 3:
        case 4:
        case 8:
            return 2;
        case 5:
        case 6:
        case 9:
            return 1;
        case 7:
            return 0;
        }
    }

    return 0;
}

s32 func_080DFE7C(s32 x, s32 y, s32 z) {
    UnkStruct_080DFB8C* p;
    s32 r;

    y += z;
    p = func_080DFB8C(x, y);

    if (p == 0) {
        return 0;
    }

    if (p->unk_02 == 4 || p->unk_02 == 6) {
        if (func_080E86C8(p, x, y) != 0) {
            r = p->unk_0C;
        } else {
            r = p->unk_08;
        }
    } else {
        r = p->unk_0C;
    }

    return r;
}
