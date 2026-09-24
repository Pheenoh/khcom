#include "bos7.h"
#include "sprites_bos7.h"
#include "sprites_bos6.h"

const EmyKind gBosLstBitEmyKind = { 0, 1, 8, 8, 0, 128, 0 };

const s32 gUnk_09A4FD5C[32] = {
    6, 12, 18, 25, 31, 37, 44, 50, 57, 64, 70, 77, 84, 91, 98, 106,
    113, 121, 128, 136, 145, 153, 162, 171, 180, 189, 199, 210, 220, 232, 243, 256,
};

const s32 gUnk_09A4FDDC[3] = { 0, -8, 8 };

const s32 gUnk_09A4FDE8[16] = { -1, -2, -3, -4, -5, -6, -7, -8, -7, -6, -5, -4, -3, -2, -1, 0 };

LstAnimSet gLstAnimSets[4] = {
    { 5, 0, 4, 5 },
    { 5, 0, 4, 12 },
    { 5, 0, 4, 13 },
    { 5, 0, 4, 14 },
};

TaskDesc gTaskDescBosLstBit = {
    "task_bos_lst_bit",
    (TaskInitFunc)task_bos_lst_bit_0,
    (TaskUpdateFunc)task_bos_lst_bit_1,
    (TaskFunc)task_bos_lst_bit_2,
    (TaskFunc)task_bos_lst_bit_3,
    0x1D0,
};

s32 func_0811089C(s32 x) {
    return x * x;
}

s32 func_081108A4(s32 x) {
    return x * x;
}

u8 func_081108AC(LstState* work, s32 kind) {
    LstFalArg arg;
    u8 result;

    result = 0;

    if (work->unk_00E != 0) {
        return 0;
    }

    if ((s16)*work->unk_020 <= 31) {
        arg.unk_00 = 0;
        if (kind == 1) {
            arg.x = work->unk_050;
            arg.y = work->unk_054;
            arg.z = work->unk_058;
        } else {
            arg.x = work->unk_028;
            arg.y = work->unk_02C;
            arg.z = work->unk_030;
        }
        arg.unk_12 = *work->unk_01C;
        arg.unk_14 = work->unk_020;
        TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBosLstFal, &arg);
        result = 1;
    }

    return result;
}

u8 func_08110918(LstWork* work) {
    LstState* s;
    u8 result;

    s = work->state;
    result = 1;

    if (s->unk_0A0.unk_2C <= 0 || s->unk_002 == 6) {
        result = 0;
    }

    return result;
}

u8 func_08110938(LstWork* work) {
    LstState* s;
    u8 result;

    s = work->state;
    result = func_08110918(work);

    if (result == 1 && s->unk_012 <= 0) {
        result = 0;
    }

    return result;
}

#ifdef VERSION_EU
u8 eu_0810F08C(LstWork* work) {
    LstState* s;
    u8 result;

    s = work->state;
    result = func_08110918(work);

    if (result == 1 && (s->scaleX == 0x100 || s->scaleY == 0x100)) {
        result = 0;
    }

    return result;
}
#endif

s16 func_0811095C(LstWork* work, s16 a) {
    LstState* s;

    s = work->state;

    if (func_08110918(work) == 1 && a == 0) {
        s->unk_010 = a;
        a = 1;
    }

    return a;
}

void func_08110984(LstWork* work) {
    LstState* s;
    u16 zero;

    s = work->state;
    zero = 0;
    s->unk_002 = 1;
    s->unk_004 = zero;
    s->unk_006 = zero;
    s->unk_008 = zero;
}

void func_08110994(LstWork* work, s16 a) {
    LstState* s;
    u16 zero;

    s = work->state;
    zero = 0;
    s->unk_002 = 2;
    s->unk_004 = zero;
    s->unk_006 = zero;
    s->unk_008 = zero;
    s->unk_012 = a;
}

void func_081109A8(LstWork* work) {
    LstState* s;
    u16 zero;

    s = work->state;
#ifdef VERSION_EU
    if ((u16)(s->unk_002 - 5) > 1) {
#endif
        zero = 0;
        s->unk_002 = 5;
        s->unk_004 = zero;
        s->unk_006 = zero;
        s->unk_008 = zero;
#ifdef VERSION_EU
    }
#endif
}

u8 func_081109B8(LstWork* work, u8 a) {
    LstState* s;
    u8 result;

    s = work->state;
    result = 0;
    func_08111660(s->unk_1C4);
    func_08111660(s->unk_1C8);
    func_08111660(s->unk_1CC);
    s->unk_012 = 0;

    if (s->unk_002 >= 5 && s->unk_002 <= 6) {
        return 0;
    }

    if (a == 1 && s->unk_010 == 0) {
        s->unk_0A0.unk_2C = 0;
        func_0801C2DC(&s->unk_0A0, 1);
        func_081108AC(s, 0);
        func_081108AC(s, 0);
        result = 1;
    }

#ifdef VERSION_EU
    AnimReset(&s->anim);
    AnimChange(&s->anim, gLstAnimSets[s->unk_000].unk_00, 1);

    if (s->unk_002 != 0 && s->unk_002 != 5) {
        s->unk_002 = 7;
        s->unk_004 = 0;
        s->unk_006 = 0;
        s->unk_008 = 0;

        if (gBtlWork->actor->z > -0xC000) {
            s->unk_058 = -0x6000;
        } else {
            s->unk_058 = gBtlWork->unk_0D4 - 0x5000;
        }
    }
#else
    s->unk_002 = 7;
    s->unk_004 = 0;
    s->unk_006 = 0;
    s->unk_008 = 0;
#endif

    return result;
}

s32 func_08110A38(s32 a, s32 b) {
    s32 v;
    s32 step;
    s32 i;

    if (a == 0 || b == 0) {
        return 0;
    }

    v = (b << 8) / a;
    if (v <= gUnk_09A4FD5C[0]) {
        return 0;
    }

    step = 8;
    i = 16;
    while (step != 0 && v != gUnk_09A4FD5C[i]) {
        if (v < gUnk_09A4FD5C[i]) {
            i -= step;
        } else {
            i += step;
        }
        step /= 2;
    }

    return i;
}

s32 func_08110A98(s32 x0, s32 y0, s32 x1, s32 y1) {
    s32 dx;
    s32 dy;
    s32 a;

    dx = x0 - x1;
    dy = y0 - y1;

    if (abs(dx) >= abs(dy)) {
        a = func_08110A38(abs(dx), abs(dy));
    } else {
        a = 63 - func_08110A38(abs(dy), abs(dx));
    }

    if (dx >= 0) {
        if (dy >= 0) {
            a = 63 - a;
            a = a + 192;
        }
    } else if (dy >= 0) {
        a = a + 128;
    } else {
        a = 63 - a;
        a = a + 64;
    }

    a = 255 - a;
    a = a + 65;

    return a & 255;
}

s32 func_08110B10(u8 a, u8 b) {
    s32 d;

    if (a > b) {
        d = a - b;
        if (d > 128) {
            d = d - 256;
        }
        return -d;
    }

    d = b - a;
    if (d > 128) {
        d = d - 256;
    }

    return d;
}

void task_bos_lst_bit_0(LstState* work, LstBitArg* arg) {
    LstBitSubArg sub;
    BtlObj* p;
    void* pool;

    work->unk_000 = 0;
    work->unk_002 = 0;
    work->unk_004 = 0;
    work->unk_006 = 0;
    work->unk_008 = 0;
    work->unk_00A = 0;
    work->unk_00C = 0;
    work->unk_00E = arg->unk_00;
    work->unk_010 = arg->unk_04;
    work->unk_012 = 0;
    work->unk_014 = GetRandom() % 32;
    work->unk_01C = arg->unk_08;
    work->unk_020 = arg->unk_0C;
    work->unk_024 = arg->unk_10;
    work->unk_028 = arg->unk_14;
    work->unk_02C = arg->unk_18;
    work->unk_030 = arg->unk_1C;
    work->unk_044 = arg->unk_14;
    work->unk_048 = arg->unk_18;
    work->unk_04C = arg->unk_1C;
    work->unk_040 = 0;
    work->unk_050 = arg->unk_20;
    work->unk_054 = arg->unk_24;
    work->unk_058 = arg->unk_28;
    p = gBtlWork->actor;
    work->unk_068 = p->x;
    work->unk_06C = p->y;
    work->unk_070 = p->z;
    work->angle = arg->unk_04 << 7;
    work->scaleX = 2;
    work->scaleY = 2;
    work->tiles = (u32)LoadObjTiles(gUnk_09CD0334, 0x900);
    work->palette = (u32)LoadObjPalette(gUnk_09D69594, 0x60);
    work->palette2 = (u32)LoadObjPalette(gUnk_08F69BC4, 0x20);
    AnimInit(&work->anim, gUnk_09EFBF18, gUnk_09EFBEC4);
    AnimStart(&work->anim, gLstAnimSets[work->unk_000].unk_00, 1);
    func_0801B37C(&work->unk_0A0, &gBosLstBitEmyKind, work->unk_028, work->unk_02C, work->unk_030);
    pool = &work->tasks;
    TaskPoolInit(pool, 4);
    sub.unk_00 = work->unk_00E;
    sub.unk_04 = work->unk_01C;
    sub.unk_08 = work->unk_020;
    work->unk_1C4 = TaskCreate(pool, &gTaskDescBosLstLsr, &sub);
    work->unk_1C8 = TaskCreate(pool, &gTaskDescBosLstLsr, &sub);
    work->unk_1CC = TaskCreate(pool, &gTaskDescBosLstLsr, &sub);
}

void func_08110C9C(LstState* work) {
    void* anim;

    anim = &work->unk_0A0;

    switch (func_0801ADAC(anim)) {
    case 1:
    case 6:
    case 7:
        work->unk_00A = 20;
        func_081108AC(work, 0);
        func_0801AF08(anim);
        break;
    case 3:
        func_0801C2DC(&work->unk_0A0, 1);
        func_081108AC(work, 0);
        func_081108AC(work, 0);
        func_0801AF08(anim);
        break;
    case 5:
        func_0801AF08(anim);
        break;
    case 4:
        func_0801AF08(anim);
        break;
    case 2:
        break;
    }
}

u8 task_bos_lst_bit_1(LstState* work) {
    Vec3 a;
    Vec3 b;
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;
    BtlObj* p;
    s32 d;
    u8 dir;
    LstObj* obj;

    obj = &work->unk_0A0;

    if (obj->unk_2C <= 0) {
        func_0801C2DC(obj, 1);
        return 1;
    }

    func_08110C9C(work);

    switch (work->unk_002) {
    case 0:
        ApproachValueHalfSteps(&work->unk_028, work->unk_050, 20);
        ApproachValueHalfSteps(&work->unk_02C, work->unk_054, 20);
        ApproachValueHalfSteps(&work->unk_030, work->unk_058, 20);
        ApproachValueHalfSteps(&work->scaleX, 0x100, 32);
        ApproachValueHalfSteps(&work->scaleY, 0x100, 32);
        work->unk_006++;

        if (work->unk_006 > 29) {
            work->unk_002 = 1;
            work->unk_004 = 0;
            work->unk_006 = 0;
            work->unk_008 = 0;
            work->scaleX = 0x100;
            work->scaleY = 0x100;
        }
        break;
    case 1:
        if (work->unk_006 == 0) {
            if (gBtlWork->flags & 0x2000000000000) {
                work->unk_050 = (GetRandom() % 113 << 8) + 0xC000;
#ifndef VERSION_EU
                work->unk_054 = gBtlWork->actor->y;
#endif
            } else if (work->unk_00E == 0) {
                work->unk_050 = (GetRandom() % 113 << 8) + 0xC000;
                work->unk_054 = gBtlWork->actor->y + (gUnk_09A4FDDC[work->unk_010] << 8);
            } else {
                work->unk_050 = gBtlWork->actor->x;
                work->unk_054 = gBtlWork->actor->y;
            }

            AnimReset(&work->anim);
            AnimChange(&work->anim, gLstAnimSets[work->unk_000].unk_00, 1);
        }

        if (!(gBtlWork->flags & 0x2000000000000)) {
            if (gBtlWork->actor->z > -0xC000) {
                work->unk_058 = -0x6000;
            } else {
                work->unk_058 = gBtlWork->unk_0D4 - 0x5000;
            }
        }

        work->unk_006++;

        if ((work->unk_014 & 31) == 0) {
            func_081108AC(work, 0);
        }

        ApproachValueHalfSteps(&work->unk_028, work->unk_050, 20);
        ApproachValueHalfSteps(&work->unk_02C, work->unk_054, 20);
        ApproachValueHalfSteps(&work->unk_030, work->unk_058, 20);
        break;
    case 2:
        if (work->unk_006 == 0) {
            work->unk_050 = gBtlWork->actor->x;
            work->unk_054 = gBtlWork->actor->y;

            if (gBtlWork->actor->z > -0xC000) {
                work->unk_058 = 0;
            } else {
                work->unk_058 = gBtlWork->unk_0D4;
            }

            AnimReset(&work->anim);
            AnimChange(&work->anim, gLstAnimSets[work->unk_000].unk_02, 0);
        }

        work->unk_006++;

        if (AnimGetId(&work->anim) == (s16)gLstAnimSets[work->unk_000].unk_02 && AnimIsFinished(&work->anim) == 1) {
            work->unk_002 = 3;
            work->unk_006 = 0;
            work->unk_018 = 1;
            work->unk_01A = work->unk_01B;
            work->unk_05C = work->unk_028 + work->unk_034;
            work->unk_060 = work->unk_02C + work->unk_038;
            work->unk_064 = work->unk_030 + work->unk_03C;
            m4aSongNumStart(SONG_SND_708);
            AnimReset(&work->anim);
            AnimChange(&work->anim, gLstAnimSets[work->unk_000].unk_00, 1);
        }
        break;
    case 3:
        if (work->unk_006 == 0) {
            if (func_081115B4(work->unk_1C4) == 0) {
                a.x = work->unk_05C;
                a.y = work->unk_060;
                a.z = work->unk_064;
                b.x = work->unk_050;
                b.y = work->unk_054;
                b.z = work->unk_058;
                func_081115CC(work->unk_1C4, &a, &b, work->unk_01A, 0);
            }

            work->unk_006++;
        } else {
            work->unk_050 = gBtlWork->actor->x;
            work->unk_054 = gBtlWork->actor->y;

            if (gBtlWork->actor->z > -0xC000) {
                work->unk_058 = 0;
            } else {
                work->unk_058 = gBtlWork->unk_0D4;
            }

            if (func_081115B4(work->unk_1C4) == 0) {
                if (work->unk_012 > 1) {
                    work->unk_002 = 2;
                    work->unk_006 = 0;
                    work->unk_012--;
                } else {
                    work->unk_012 = 0;
                }
            }
        }
        break;
    case 4:
        if (work->unk_006 > 14) {
            break;
        }

        func_08011F78(0x10D, work->unk_050, work->unk_054, work->unk_058, 8, 8, 8);

        if ((work->unk_006 & 3) == 0) {
            func_081108AC(work, 1);
        }

        if (abs(work->unk_050 - gBtlWork->actor->x) < 0x180) {
            work->unk_050 = gBtlWork->actor->x;
        } else if (work->unk_050 > gBtlWork->actor->x) {
            work->unk_050 = work->unk_050 - 0x180;
        } else if (work->unk_050 < gBtlWork->actor->x) {
            work->unk_050 = work->unk_050 + 0x180;
        }

        if (abs(work->unk_054 - gBtlWork->actor->y) < 0x180) {
            work->unk_054 = gBtlWork->actor->y;
        } else if (work->unk_054 > gBtlWork->actor->y) {
            work->unk_054 = work->unk_054 - 0x180;
        } else if (work->unk_054 < gBtlWork->actor->y) {
            work->unk_054 = work->unk_054 + 0x180;
        }

        work->unk_006++;
        break;
    case 5:
        work->unk_050 = gBtlWork->unk_0CC;
        work->unk_054 = gBtlWork->unk_0D0 - 0x1400;
        work->unk_058 = gBtlWork->unk_0D4;
        ApproachValueHalfSteps(&work->unk_028, work->unk_050, 16);
        ApproachValueHalfSteps(&work->unk_02C, work->unk_054, 16);
        ApproachValueHalfSteps(&work->unk_030, work->unk_058, 16);
        ApproachValueHalfSteps(&work->scaleX, 0x200, 16);
        ApproachValueHalfSteps(&work->scaleY, 2, 16);
        work->unk_006++;

        if (work->unk_006 > 59) {
            work->unk_002 = 6;
            work->unk_004 = 0;
            work->unk_006 = 0;
            work->unk_008 = 0;
        }
        break;
    case 6:
        work->scaleX = 0x100;
        work->scaleY = 0x100;
        AnimReset(&work->anim);
        AnimChange(&work->anim, 4, 1);
        break;
    case 7:
        AnimChange(&work->anim, gLstAnimSets[work->unk_000].unk_00, 1);
        break;
    }

    WorldToScreen(&x1, &y1, work->unk_028 + work->unk_034, work->unk_02C + work->unk_038,
                  work->unk_030 + work->unk_03C);

    if (gBtlWork->flags & 0x2000000000000) {
        WorldToScreen(&x2, &y2, work->unk_068, work->unk_06C, work->unk_070);
        work->angle += 2;
    } else {
        if (work->unk_00E == 0) {
            switch (work->unk_002) {
            case 2:
            case 3:
                work->angle += 2;
                WorldToScreen(&x2, &y2, work->unk_050, work->unk_054, work->unk_058);
                break;
            default:
                work->angle += 2;
                WorldToScreen(&x2, &y2, gBtlWork->actor->x, gBtlWork->actor->y,
                              gBtlWork->actor->z);
                break;
            }
        } else {
            switch (work->unk_002) {
            case 2:
            case 3:
            case 4:
                work->angle += 6;
                WorldToScreen(&x2, &y2, work->unk_050, work->unk_054, work->unk_058);
                break;
            default:
                work->angle += 2;
                WorldToScreen(&x2, &y2, gBtlWork->actor->x, gBtlWork->actor->y,
                              gBtlWork->actor->z);
                break;
            }
        }

        work->unk_068 = gBtlWork->actor->x;
        work->unk_06C = gBtlWork->actor->y;
        work->unk_070 = gBtlWork->actor->z;
    }

    work->angle &= 0xFF;

    if (work->unk_00E == 0) {
        work->unk_034 = (-gSineTable[(work->angle & 0xFF) + 64] * 3 >> 6) << 8;
        work->unk_038 = (gSineTable[work->angle & 0xFF] * 3 >> 6) << 8;
        work->unk_03C = work->unk_03C / 2;
    } else if (work->unk_010 == 0) {
        work->unk_034 = work->unk_034 / 2;
        work->unk_038 = work->unk_038 / 2;
        work->unk_03C = work->unk_03C / 2;
    } else {
        work->unk_034 = (-gSineTable[(work->angle & 0xFF) + 64] >> 3) << 8;
        work->unk_038 = (gSineTable[work->angle & 0xFF] * 3 >> 6) << 8;
        work->unk_03C = 0x800;
    }

    work->unk_040 = gUnk_09A4FDE8[(work->unk_00C >> 2) & 15] << 8;
    dir = func_08110A98(x2, y2, x1, y1);
    d = func_08110B10(work->unk_01B, dir);

    if (abs(d) <= 1) {
        work->unk_01B = dir;
    } else {
        work->unk_01B += d / 2;
    }

    obj->unk_04 = work->unk_028 + work->unk_034;
    obj->unk_08 = work->unk_02C + work->unk_038;
    obj->unk_0C = work->unk_030 + work->unk_03C + work->unk_040;
    AnimUpdate(&work->anim);
    TaskPoolUpdate(&work->tasks);
    work->unk_014++;
    work->unk_00C++;

    return 1;
}

void task_bos_lst_bit_2(LstState* work) {
    s16 x;
    s16 y;
    void* pal;
    s32 affine;
    u16 prio;
    u16 z;
    void* gfx;

    if (work->unk_0A0.unk_2C <= 0) {
        return;
    }

    pal = (void*)work->palette;
    if ((work->unk_00A & 1) != 0) {
        pal = (void*)work->palette2;
    }

    if (work->unk_00A > 0) {
        work->unk_00A = work->unk_00A - 1;
    }

    WorldToScreen(&x, &y, work->unk_028 + work->unk_034, work->unk_02C + work->unk_038,
                  work->unk_030 + work->unk_03C + work->unk_040);
    prio = GetBattleSpritePriorityFlags(work->unk_02C);
    z = -0x1004 - (work->unk_02C >> 8) * 4;
    affine = AllocObjAffine(work->unk_01B, work->scaleX, work->scaleY, 0);
    gfx = AnimGetGfx(&work->anim);
    DrawSprite(x, y, gfx, (void*)work->tiles, pal, affine, prio, z);
    TaskPoolDraw(&work->tasks);
}

void task_bos_lst_bit_3(LstBitWork* work) {
    func_0801B7D8(&work->unk_0A0);
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
    ReleaseObjPalette((void*)work->palette2);
    TaskPoolDestroy(&work->tasks);
}
