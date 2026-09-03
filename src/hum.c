#include "macros.h"
#include "hum.h"
#include "gba/keys.h"

void task_hum_cloud_0(CloudWork* work, void* obj) {
    func_0800E168(&work->base, gUnk_0813EF28);
    work->unk_188 = 0;
    work->base.unk_184 = (u32)gUnk_0813EDD0;
}

INCLUDE_ASM("hum/task_hum_cloud_1.s");

void task_hum_cloud_2(HumWork* work) {
    func_0800EFE8(work);
}

void task_hum_cloud_3(HumWork* work) {
    func_0800E380(work);
}

void func_0804B44C(CloudWork* work, s16 a, s32 b) {
    HumWork* w = &work->base;
    HumActor* act = &w->unk_040;

    if (act->unk_34 & 4) {
        work->base.unk_15C = act->unk_04 - (a << 8);
    } else {
        work->base.unk_15C = act->unk_04 + (a << 8);
    }
    w->unk_160 = act->unk_08;
    w->unk_170 = 0x16;
    w->unk_150 = 0;
    work->unk_188 = -b;
}

void func_0804B4BC(CloudWork* work, s32 a, s32 b) {
    work->base.unk_15C = a;
    work->base.unk_160 = b;
    work->base.unk_170 = 0x16;
    work->base.unk_150 = 0;
    work->unk_188 = -0x680;
}

INCLUDE_ASM("hum/func_0804B4F4.s");
INCLUDE_ASM("hum/task_hum_hook_0.s");
INCLUDE_ASM("hum/task_hum_hook_1.s");
INCLUDE_ASM("hum/task_hum_hook_2.s");
INCLUDE_ASM("hum/task_hum_hook_3.s");

void task_hum_hook_moon_0(HookMoonWork* work) {
    work->tiles = LoadObjTiles(gUnk_08B5A872, 0xC00);
    PushPaletteEffect(0);
    work->palette = LoadObjPalette(gUnk_08F6DC64, 0x20);
    PopPaletteEffect();
    func_0801C298(work->palette[6] + 16, 0);
    work->unk_0A = 0;
    work->unk_08 = 0;
}

u8 task_hum_hook_moon_1(HookMoonWork* work) {
    work->unk_08++;
    return 1;
}

void task_hum_hook_moon_2(HookMoonWork* work) {
    s16 x;
    s16 y;
    u16 v;
    u16 t;
    s32 s;

    x = 248 - (gBtlWork->unk_000 >> 9);
    y = 208 - (gBtlWork->unk_004 >> 9);
    s = gSineTable[(u8)work->unk_08];
    y += s >> 5;
    DrawSprite(x + 64, y - 28, gUnk_08B5A854, work->tiles, work->palette, 0, 0xC00, 0xFFFF);
    DrawSprite(x - 144, y, gUnk_08B5A85E, work->tiles, work->palette, 0, 0xC00, 0xFFFE);
    DrawSprite(x - 88, y, gUnk_08B5A85E, work->tiles, work->palette, 0, 0xC00, 0xFFFE);
    DrawSprite(x - 32, y, gUnk_08B5A85E, work->tiles, work->palette, 0, 0xC00, 0xFFFE);
    DrawSprite(x + 24, y, gUnk_08B5A85E, work->tiles, work->palette, 0, 0xC00, 0xFFFE);
    DrawSprite(x + 80, y, gUnk_08B5A85E, work->tiles, work->palette, 0, 0xC00, 0xFFFE);
    v = func_08006390();
    if (v != 0) {
        switch (_08006338()) {
        case 0:
            t = 9 - v;
            if ((s16)t < 0) {
                t = 0;
            }
            SetBackdropColor(0, 0, t);
            break;
        case 0x7FFF:
            t = v + 9;
            if ((s16)t > 31) {
                t = 31;
            }
            SetBackdropColor(v, v, t);
            break;
        case 31:
            SetBackdropColor(v, 0, 9);
            break;
        case 0x7C00:
            t = v + 9;
            if ((s16)t > 31) {
                t = 31;
            }
            SetBackdropColor(0, 0, t);
            break;
        case 0x3E0:
            SetBackdropColor(0, v, 9);
            break;
        }
        work->unk_0A = 1;
    } else if (work->unk_0A != 0) {
        SetBackdropColor(0, 0, 9);
        work->unk_0A = v;
    }
}

void task_hum_hook_moon_3(HookMoonWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_hum_hook_bomb_0(HookBombWork* work, VixenNdlArgs* args) {
    if (args->unk_12 != 0) {
        work->unk_2C = 1;
    } else {
        work->unk_2C = 0;
    }
    work->unk_04 = LoadObjPalette(gUnk_08F6DC44, 0x20);
    work->unk_00 = AllocObjTiles(0x280, gUnk_08B59E52);
    AnimInit(&work->anim, gUnk_09EE17AC, gUnk_09EE1798);
    AnimStart(&work->anim, 0, 1);
    work->x = args->unk_00;
    work->y = args->unk_04;
    work->z = args->unk_08;
    work->unk_4E = args->unk_14;
    work->unk_3C = 0;
    work->unk_4A = 0;
    work->unk_50 = GetRandom() % 0x201 + 0x14C;
    work->unk_30 = -(GetRandom() % 0x201 + 0x100);

    switch (work->unk_4E) {
    case 0:
        work->unk_34 = GetAngle(work->x, work->y,
            gBtlWork->unk_130, gBtlWork->unk_134);
        work->unk_4C = GetRandom() % 3 + 1;
        work->unk_38 = 0;
        break;
    case 2:
        work->unk_34 = GetAngle(work->x, work->y,
            gBtlWork->unk_130, gBtlWork->unk_134);
        work->unk_4C = 0;
        work->unk_38 = 1;
        break;
    case 1:
    default:
        work->unk_34 = GetRandom();
        work->unk_4C = GetRandom() % 5 + 4;
        work->unk_38 = 0;
        break;
    }
    work->unk_40 = LoadObjTiles(gUnk_08B22CE4, 0x200);
    work->unk_44 = LoadObjPalette(gUnk_08F69BA4, 0x20);
    work->unk_48 = 1;
}

INCLUDE_ASM("hum/task_hum_hook_bomb_1.s");

void task_hum_hook_bomb_2(HookBombWork* work) {
    void* gfx;
    u16 attr;
    s16 x;
    s16 y;

    if (work->unk_48 == 0) {
        return;
    }
    gfx = AnimGetGfx(&work->anim);
    attr = func_0801AF1C(work->y);

    if (work->unk_2C == 0) {
        attr |= 1;
    }
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->unk_00, work->unk_04, 0, attr,
        -0x1004 - ((work->y + 0x800) >> 8) * 4);
    WorldToScreen(&x, &y, work->x, work->y, 0);
    DrawSprite(x, y, gUnk_08B22CBC, work->unk_40, work->unk_44, 0, attr, 0xFFF0);
}

void task_hum_hook_bomb_3(HookBombWork* work) {
    ReleaseObjTiles(work->unk_40);
    ReleaseObjPalette(work->unk_44);
    ReleaseObjTiles(work->unk_00);
    ReleaseObjPalette(work->unk_04);
}

void func_0804D018(HumWork* work, s32 a) {
    HumActor* act = &work->unk_040;
    s32 t;

    if (a != 0) {
        t = a + gSineTable[gFrameCounter * 4 % 256] * 8;
        work->unk_158 = 0;
        act->unk_0C += (t - act->unk_0C) >> 4;
    }
}

void func_0804D060(AnsemWork* work) {
    HumActor* act = &work->base.unk_040;

    if (act->unk_34 & 4) {
        *(s32*)&work->unk_1C8 += (0x1800 - *(s32*)&work->unk_1C8) >> 3;
    } else {
        *(s32*)&work->unk_1C8 += (-0x1800 - *(s32*)&work->unk_1C8) >> 3;
    }
    *(s32*)&work->unk_1CC += (-0x1200 - *(s32*)&work->unk_1CC) >> 3;
    work->unk_188.unk_28 = act->unk_04 + *(s32*)&work->unk_1C8;
    work->unk_188.unk_2C = act->unk_08;
    work->unk_188.unk_30 = act->unk_0C + *(s32*)&work->unk_1CC;
}

void task_hum_ansem_0(AnsemWork* work) {
    func_0800E168(&work->base, gUnk_0813F1E8);
    func_0800E314(&work->base, &work->unk_188, gUnk_0813F1E0);
    work->unk_1C4 = -0xC00;
    *(s32*)&work->unk_1C8 = 0;
    work->base.unk_174 = -50;
    work->base.unk_184 = (u32)gUnk_0813F0B8;
}

INCLUDE_ASM("hum/task_hum_ansem_1.s");

void task_hum_ansem_2(HumWork* work) {
    func_0800EFE8(work);
}

void task_hum_ansem_3(HumWork* work) {
    func_0800E380(work);
}

void func_0804E3BC(HumWork* work, s32 a) {
    HumActor* act = &work->unk_040;
    s32 t;

    if (a != 0) {
        t = a + gSineTable[gFrameCounter * 4 % 256] * 4;
        work->unk_158 = 0;
        act->unk_0C += (t - act->unk_0C) >> 4;
    }
}

void func_0804E404(AnsemWork* work) {
    HumActor* act = &work->base.unk_040;

    if (work->unk_1CC > 2) {
        LoadObjPaletteBank(((u16*)work->base.palette)[3], gUnk_09617F18);
        work->base.unk_178 = gUnk_09617F18;
        work->unk_1CA &= 0xFFFE;
        work->base.unk_184 = (u32)gUnk_0813F214;
    } else {
        work->unk_1CC++;
    }
    func_0801AF08(act);
}

void task_hum_hades_0(HadesWork* work) {
    func_0800E168(&work->base, gUnk_0813F324);
    func_0800E314(&work->base, &work->unk_188, gUnk_0813F31C);
    work->base.unk_040.unk_34 |= 0x100000;
    work->base.unk_154 |= 0x40;
    work->unk_1CA = 0;
    work->unk_1C4 = -0xA00;
    work->unk_188.unk_34 |= 3;
    work->unk_1D4 = AllocObjTiles(0x80, gUnk_08BAFB62);
    work->unk_1D8 = AllocObjTiles(0x280, gUnk_08BAFB62);
    work->unk_1DC = AllocObjTiles(0x3A0, gUnk_08BAFB62);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);
    AnimInit(&work->unk_1E0, gUnk_09EE1B78, gUnk_09EE1B38);
    AnimStart(&work->unk_1E0, 2, 1);
    AnimInit(&work->unk_1F8, gUnk_09EE1B78, gUnk_09EE1B38);
    AnimStart(&work->unk_1F8, 1, 1);
    AnimInit(&work->unk_210, gUnk_09EE1B78, gUnk_09EE1B38);
    AnimStart(&work->unk_210, 0, 1);
    work->base.unk_184 = (u32)gUnk_0813F214;
}

INCLUDE_ASM("hum/task_hum_hades_1.s");

void task_hum_hades_2(HadesWork* work) {
    HumActor* act;
    HadesSub* e;
    void* gfx;
    u16 attr;
    s32 sx;
    s32 affine;
    s16 x;
    s16 y;
    s32 i;

    func_0800EFE8(&work->base);

    if ((work->unk_1CA & 2) == 0) {
        return;
    }
    act = &work->base.unk_040;

    for (i = 0; i < 2; i++) {
        e = &work->unk_22C[i];
        attr = func_0801AF1C(e->unk_00);

        if (work->unk_27C == 0x100) {
            if ((act->unk_34 & 4) == 0) {
                attr |= 1;
            }
            sx = work->unk_27C;
        } else {
            if ((act->unk_34 & 4) == 0) {
                sx = work->unk_27C;
            } else {
                sx = -work->unk_27C;
            }
        }
        affine = AllocObjAffine(0, sx, work->unk_27C, 0);
        gfx = AnimGetGfx(&work->unk_1E0);
        WorldToScreen(&x, &y, e->unk_04, e->unk_08, e->unk_0C);
        DrawSprite(x, y, gfx, work->unk_1D4, work->palette, affine, attr,
            -0x1005 - (e->unk_00 >> 8) * 4);
        gfx = AnimGetGfx(&work->unk_1F8);
        WorldToScreen(&x, &y, e->unk_10, e->unk_14, e->unk_18);
        DrawSprite(x, y, gfx, work->unk_1D8, work->palette, affine, attr,
            -0x1006 - (e->unk_00 >> 8) * 4);
        gfx = AnimGetGfx(&work->unk_210);
        WorldToScreen(&x, &y, e->unk_1C, e->unk_20, e->unk_24);
        DrawSprite(x, y, gfx, work->unk_1DC, work->palette, affine, attr,
            -0x1007 - (e->unk_00 >> 8) * 4);
    }
}

void task_hum_hades_3(HadesWork* work) {
    ReleaseObjTiles(work->unk_1D4);
    ReleaseObjTiles(work->unk_1D8);
    ReleaseObjTiles(work->unk_1DC);
    ReleaseObjPalette(work->palette);
    func_0800E380(&work->base);
}

void func_0804F8F0(MahluxiaWork* work, s16 a) {
    HumWork* w = &work->base;
    HumActor* act = &w->unk_040;
    s32 v;

    func_0801C700(act, &v, 0, 0);

    if (act->unk_34 & 4) {
        w->unk_15C = act->unk_04 - (a << 8);
    } else {
        w->unk_15C = act->unk_04 + (a << 8);
    }
    w->unk_170 = 20;
    w->unk_150 = 0;
    work->unk_1C4 = -0x300;

    if (act->unk_08 < v) {
        w->unk_160 = (gBtlWork->unk_0DE + 16) << 8;
    } else {
        w->unk_160 = (gBtlWork->unk_0E0 - 16) << 8;
    }
}

void func_0804F9A0(MahluxiaWork* work, s32 a, u16 b) {
    work->base.unk_15C = a;
    work->unk_1C8 = b;
    work->base.unk_170 = 19;
    work->base.unk_150 = 0;
}

u8 func_0804F9C8(MahluxiaWork* work) {
    s32 v;
    Collider* c;

    c = gBtlWork->unk_07C;
    func_0801C700(&work->base.unk_040, &v, 0, 0);
    func_0800F368(work, 1);

    if (func_0800F504(work, 0x100, 0x100, 0x100)) {
        if (gBtlWork->unk_068 & 0x8000) {
            func_0804F8F0(work, -128);
        } else if (GetRandom() & 1) {
            if (c->unk_34 & 4) {
                func_0804F9A0(work, v + 0x2800, 48);
            } else {
                func_0804F9A0(work, v - 0x2800, 48);
            }
        } else {
            func_0804F8F0(work, -128);
        }
        return 1;
    }
    return 0;
}

void func_0804FA70(MahluxiaWork* work, RikuSpawn* dst) {
    HumActor* act = &work->base.unk_040;

    dst->x = act->unk_04;
    dst->y = act->unk_08;
    dst->z = act->unk_0C;

    if (act->unk_34 & 4) {
        dst->unk_0C |= 1;
    } else {
        dst->unk_0C &= 0xFFFE;
    }
    dst->unk_10 = work->base.anim;
    dst->unk_28 = *(u32*)work->base.tiles;
    dst->unk_2C = gBtlWork->unk_024;
}

void func_0804FAD4(MahluxiaWork* work, RikuSpawn* p) {
    HumActor* act;
    HumSub* sub;
    void* gfx;
    u16 attr;
    s32 sx;
    s32 sy;
    s32 affine;
    s16 x;
    s16 y;
    u16 pri;

    sub = work->base.unk_00C;
    gfx = AnimGetGfx(&p->unk_10);
    act = &work->base.unk_040;

    if (func_080128EC() == 0) {
        gBldCnt = 0xF10;
        SetBlendAlpha(4, 14);
        attr = 0x804;
    } else {
        attr = func_0801AF1C(act->unk_08);
    }

    if (p->unk_0C & 1) {
        sy = p->unk_2C;
        sx = sy;
    } else if (p->unk_2C == 0x100) {
        sy = p->unk_2C;
        sx = sy;
        attr |= 1;
    } else {
        sx = -gBtlWork->unk_024;
        sy = gBtlWork->unk_024;
    }

    if (sy == 0x100 && sx == sy) {
        affine = 0;
    } else if (sy <= 255) {
        affine = AllocObjAffine(0, sx, sy, 0);
    } else {
        affine = AllocObjAffine(0, sx, sy, 1);
    }
    pri = 0xFFF0;
    WorldToScreen(&x, &y, p->x, p->y, p->z);
    func_08002A10(sub->tiles, p->unk_28);
    DrawSprite(x, y, gfx, sub->tiles, work->base.palette, affine, attr, pri);
}

void func_0804FBDC(HumWork* work, s32 a) {
    HumActor* act;
    s32 t;

    if (a != 0) {
        act = &work->unk_040;
        t = a + gSineTable[gFrameCounter * 4 % 256] * 3;
        work->unk_158 = 0;
        act->unk_0C += (t - act->unk_0C) >> 4;
    }
}

void task_hum_mahluxia_0(MahluxiaWork* work) {
    func_0800E168(&work->base, gUnk_0813F450);
    func_0800E314(&work->base, &work->unk_188, gUnk_0813F448);
    work->unk_1D0 = 0;
    work->unk_1C4 = -0x300;
    work->unk_188.unk_34 |= 3;
    work->unk_1D8 = 0;
    func_08019068(gUnk_0813F368, &work->base.anim, 0, 1, work->base.tiles);
    func_0804FA70(work, &work->unk_1DC[0]);
    work->unk_1DC[1] = work->unk_1DC[0];
    work->unk_1DC[2] = work->unk_1DC[0];
    work->unk_1DC[3] = work->unk_1DC[0];
    work->unk_1DC[4] = work->unk_1DC[0];
    work->unk_1DC[5] = work->unk_1DC[0];
    work->unk_1DC[6] = work->unk_1DC[0];
    work->unk_1DC[7] = work->unk_1DC[0];
    work->unk_1DC[8] = work->unk_1DC[0];
    TaskPoolInit(&work->unk_390, 22);
    work->base.unk_184 = (u32)gUnk_0813F35C;
}

#ifdef NON_MATCHING
void func_0804FD7C(MahluxiaWork* work) {
    HumActor* act = &work->base.unk_040;
    VixenNdlArgs args;
    s32 t;

    if (gFrameCounter % 5 == 0) {
        args.unk_00 = act->unk_04;
        args.unk_04 = act->unk_08;
        args.unk_08 = act->unk_0C - ((s16)act->unk_A2 << 8);
        t = ((GetRandom() % 65) << 8) - 0x2000;
        args.unk_00 += t;
        t = ((GetRandom() % 33) << 8) - 0x1000;
        args.unk_04 += t;
        t = ((GetRandom() % 41) << 8) - 0x1000;
        args.unk_08 += t;
        TaskCreate(&work->unk_390, gTaskDescHumMahluxiaFlw, &args);
    }
}
#else
INCLUDE_ASM("hum/func_0804FD7C.s");
#endif

INCLUDE_ASM("hum/task_hum_mahluxia_1.s");

void task_hum_mahluxia_2(MahluxiaWork* work) {
    func_0800EFE8(&work->base);

    if ((work->unk_1D0 & 2) && (work->unk_188.unk_34 & 2)) {
        switch (work->unk_1D8 % 12) {
        case 0:
        case 2:
        case 4:
        case 6:
        case 8:
        case 10:
            func_0804FAD4(work, &work->unk_1DC[2]);
            break;
        case 1:
        case 3:
        case 7:
            func_0804FAD4(work, &work->unk_1DC[4]);
            break;
        case 5:
        case 9:
            func_0804FAD4(work, &work->unk_1DC[6]);
            break;
        case 11:
            func_0804FAD4(work, &work->unk_1DC[8]);
            break;
        }
        work->unk_1D8++;
    }
    work->unk_1DC[8] = work->unk_1DC[7];
    work->unk_1DC[7] = work->unk_1DC[6];
    work->unk_1DC[6] = work->unk_1DC[5];
    work->unk_1DC[5] = work->unk_1DC[4];
    work->unk_1DC[4] = work->unk_1DC[3];
    work->unk_1DC[3] = work->unk_1DC[2];
    work->unk_1DC[2] = work->unk_1DC[1];
    work->unk_1DC[1] = work->unk_1DC[0];
    func_0804FA70(work, &work->unk_1DC[0]);
    TaskPoolDraw(&work->unk_390);
}

void task_hum_mahluxia_3(MahluxiaWork* work) {
    func_0800E380(&work->base);
    TaskPoolDestroy(&work->unk_390);
}

void func_08050EC4(HumWork* work, s32 a) {
    HumActor* act;
    s32 t;

    if (a != 0) {
        act = &work->unk_040;
        t = a + gSineTable[gFrameCounter * 4 % 256] * 6;
        work->unk_158 = 0;
        act->unk_0C += (t - act->unk_0C) >> 3;
    }
}

void func_08050F10(LaxeneWork* work, s16 a, s16 b) {
    HumActor* act = &work->base.unk_040;
    VixenNdlArgs args;

    if (act->unk_34 & 4) {
        args.unk_00 = act->unk_04 + (a << 8);
        args.unk_12 = 1;
    } else {
        args.unk_00 = act->unk_04 - (a << 8);
        args.unk_12 = 0;
    }
    args.unk_08 = act->unk_0C + (b << 8);
    args.unk_04 = act->unk_08;
    TaskCreate(&work->unk_194, gTaskDescHumLaxeneKnf, &args);
}

void task_hum_laxene_0(LaxeneWork* work) {
    func_0800E168(&work->base, gUnk_0813F588);
    work->unk_18E = 0;
    work->unk_188 = -0x3000;
    work->unk_190 = 0;
    work->base.unk_040.unk_34 |= 0x80000000000;
    work->base.unk_184 = (u32)gUnk_0813F480;
    TaskPoolInit(&work->unk_194, 12);
}

INCLUDE_ASM("hum/task_hum_laxene_1.s");

void task_hum_laxene_2(LaxeneWork* work) {
    func_0800EFE8(&work->base);
    TaskPoolDraw(&work->unk_194);
}

void task_hum_laxene_3(LaxeneWork* work) {
    m4aSongNumStop(0x2A2);
    func_0800E380(&work->base);
    TaskPoolDestroy(&work->unk_194);
}

void task_hum_laxene_knf_0(LaxeneKnfWork* work, VixenNdlArgs* args) {
    work->palette = LoadObjPalette(gUnk_09618458, 0x20);
    work->tiles = LoadObjTiles(gUnk_08BD99F4, 0x2C0);
    AnimInit(&work->anim, gUnk_09EE1DB4, gUnk_09EE1DA4);
    AnimStart(&work->anim, 0, 0);

    if (args->unk_12 != 0) {
        work->unk_2C = 1;
    } else {
        work->unk_2C = 0;
    }
    work->x = args->unk_00;
    work->y = args->unk_04;
    work->z = args->unk_08;
    work->unk_2E = 0;
    work->unk_2D = 1;
    work->unk_3C = 0;
    work->unk_30 = gBtlWork->unk_07C->unk_04;
    work->unk_34 = gBtlWork->unk_07C->unk_08;
    work->unk_38 = gBtlWork->unk_07C->unk_0C;
    work->unk_40 = GetRandom() % 897 + 0x800;
    m4aSongNumStart(0x2A4);
}

u8 task_hum_laxene_knf_1(LaxeneKnfWork* work) {
    Collider* c;

    if ((gBtlWork->unk_068 & 0x40) == 0) {
        return 0;
    }

    if (work->unk_2D == 0) {
        return 0;
    }

    switch (work->unk_3C) {
    case 0:
        if (func_08011F78(0x133, work->x, work->y, work->z, 1, 6, 2)) {
            m4aSongNumStart(0x2A3);
            work->unk_2E = 0;
            work->unk_3C = 1;
            func_08013994(work->x, work->y, work->z + 0x1000);
        } else {
            if (work->unk_2C != 0) {
                work->x = work->x - work->unk_40;
            } else {
                work->x = work->x + work->unk_40;
            }
            work->unk_2E++;
        }
        break;
    case 1:
        if ((s16)work->unk_2E == 0) {
            AnimStart(&work->anim, 1, 0);
        }
        c = gBtlWork->unk_07C;
        work->x += c->unk_04 - work->unk_30;
        work->y += c->unk_08 - work->unk_34;
        work->z += c->unk_0C - work->unk_38;

        if ((s16)work->unk_2E > 30) {
            return 0;
        }
        work->unk_2E++;
        break;
    }
    AnimUpdate(&work->anim);
    work->unk_30 = gBtlWork->unk_07C->unk_04;
    work->unk_34 = gBtlWork->unk_07C->unk_08;
    work->unk_38 = gBtlWork->unk_07C->unk_0C;
    return 1;
}

void task_hum_laxene_knf_2(LaxeneKnfWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 attr;

    gfx = AnimGetGfx(&work->anim);

    if (work->unk_2C != 0) {
        attr = func_0801AF1C(work->y);
    } else {
        attr = func_0801AF1C(work->y) | 1;
    }
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, 0, attr,
        -0x1004 - (work->y >> 8) * 4);

    if (func_080035CC(x, y, 2, 2, 32, 32)) {
        work->unk_2D = 0;
    }
}

void task_hum_laxene_knf_3(LaxeneKnfWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void func_080526A8(HumWork* work, s32 a, s32 b) {
    work->unk_15C = a;
    work->unk_160 = b;
    work->unk_170 = 19;
    work->unk_150 = 0;
}

void func_080526D4(AxcelWork* work, s32 a, s32 b, u16 c) {
    work->unk_208 = c;
    work->unk_20C = a;
    work->unk_210 = b;
}

void func_080526F0(HumWork* work, s32 a) {
    HumActor* act;
    s32 t;

    if (a != 0) {
        act = &work->unk_040;
        t = a + gSineTable[gFrameCounter * 4 % 256] * 3;
        work->unk_158 = 0;
        act->unk_0C += (t - act->unk_0C) >> 4;
    }
}

void func_0805273C(AxcelWork* work, HumSub* sub) {
    s32 args[3];

    if (GetRandom() % 6 == 0) {
        args[0] = sub->unk_28 + (GetRandom() % 29 - 14) * 256;
        args[1] = sub->unk_2C + (GetRandom() % 15 - 7) * 256;
        args[2] = sub->unk_30;
        TaskCreate(&work->unk_220, gTaskDescHumAxcelPtc, args);
    }
}

void task_hum_axcel_0(AxcelWork* work) {
    func_0800E168(&work->base, gUnk_0813F768);
    func_0800E314(&work->base, &work->unk_188, gUnk_0813F760);
    func_0800E314(&work->base, &work->unk_1C4, gUnk_0813F760);
    work->base.unk_040.unk_34 |= 0x04000000;
    work->base.unk_184 = (u32)gUnk_0813F5C8;
    work->unk_206 = 0;
    work->unk_200 = -0x300;
    work->unk_208 = 0;
    work->unk_188.unk_34 |= 2;
    work->unk_1C4.unk_34 |= 2;
    work->tiles = LoadObjTiles(gUnk_08B22BBC, 0x100);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);
    TaskPoolInit(&work->unk_220, 16);
}

INCLUDE_ASM("hum/task_hum_axcel_1.s");

void func_08054100(AxcelWork* work, HumSub* sub) {
    s16 x;
    s16 y;
    s32 affine;
    s32 scale;
    s32 f;

    if ((sub->unk_34 & 2) == 0) {
        if (sub->unk_30 >= 0) {
            affine = 0;
        } else {
            scale = 0x100 - (-sub->unk_30) / 128;
            if (scale <= 127) {
                scale = 128;
            }
            f = 0;

            if (scale > 0x100) {
                f = 1;
            }
            affine = AllocObjAffine(0, scale, scale, f);
        }
        WorldToScreen(&x, &y, sub->unk_28, sub->unk_2C, 0);
        DrawSprite(x, y, gUnk_08B22BA8, work->tiles, work->palette, affine, 0x800, 0xFFFE);
    }
}

void task_hum_axcel_2(AxcelWork* work) {
    func_0800EFE8(&work->base);
    func_08054100(work, &work->unk_188);
    func_08054100(work, &work->unk_1C4);
    TaskPoolDraw(&work->unk_220);
}

void task_hum_axcel_3(AxcelWork* work) {
    m4aSongNumStop(0x28E);
    TaskPoolDestroy(&work->unk_220);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    func_0800E380(&work->base);
}

void task_hum_axcel_ptc_0(AxcelPtcWork* work, s32* args) {
    work->x = args[0];
    work->y = args[1];
    work->z = args[2];
    work->tiles = LoadObjTiles(gUnk_08BF73C6, 0x300);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 0x20);
    AnimInit(&work->anim, gUnk_09EE1FC0, gUnk_09EE1F90);

    switch (GetRandom() % 3) {
    case 0:
        AnimStart(&work->anim, 0, 0);
        break;
    case 1:
        AnimStart(&work->anim, 1, 0);
        break;
    case 2:
        AnimStart(&work->anim, 2, 0);
        break;
    }
}

u8 task_hum_axcel_ptc_1(AxcelPtcWork* work) {
    if (AnimIsFinished(&work->anim)) {
        return 0;
    }
    work->gfx = AnimUpdate(&work->anim);
    return 1;
}

void task_hum_axcel_ptc_2(AxcelPtcWork* work) {
    s16 x;
    s16 y;

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, work->gfx, work->tiles, work->palette, 0,
        func_0801AF1C(work->y), -0x1004 - (work->y >> 8) * 4);
}

void task_hum_axcel_ptc_3(AxcelPtcWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void func_08054334(VixenWork* work) {
    VixenSub* p;
    s32 i;

    m4aSongNumStart(0x287);
    p = work->unk_1C4;

    for (i = 0; i < 3; i++) {
        p[i].unk_00 = p[i].unk_01 = 1;
        p[i].unk_04 = (gBtlWork->unk_0DA + 32 +
            GetRandom() % (gBtlWork->unk_0DC - gBtlWork->unk_0DA - 0x3F)) << 8;
        p[i].unk_08 = (gBtlWork->unk_0DE + 16 +
            GetRandom() % (gBtlWork->unk_0E0 - gBtlWork->unk_0DE - 0x1F)) << 8;
    }
}

void func_080543B4(VixenWork* work) {
    VixenSub* p;
    s32 i;
    u8 z;

    z = 0;
    p = work->unk_1C4;

    for (i = 0; i < 3; i++) {
        p->unk_01 = z;
        p->unk_00 = z;
        TaskCreate(&work->unk_1A4, gTaskDescHumVixenIce, &work->unk_1C4[i]);
        p++;
    }
}

void func_080543F4(HumWork* work, s32 a) {
    HumActor* act;
    s32 t;

    if (a != 0) {
        act = &work->unk_040;
        t = a + gSineTable[gFrameCounter * 4 % 256] * 3;
        work->unk_158 = 0;
        act->unk_0C += (t - act->unk_0C) >> 4;
    }
}

void task_hum_vixen_0(VixenWork* work) {
    func_0800E168(&work->base, gUnk_0813F8C8);
    work->unk_188 = 0;
    work->base.unk_040.unk_34 |= 0x08000000;
    work->unk_1A2 = 0;
    TaskPoolInit(&work->unk_1A4, 15);
    func_080543B4(work);
    work->base.unk_184 = (u32)gUnk_0813F7A8;

    if (gGameState.flags & 8) {
        gBtlWork->unk_114 = AllocObjTiles(0x840, 0);
    }
}

INCLUDE_ASM("hum/task_hum_vixen_1.s");

void task_hum_vixen_2(VixenWork* work) {
    func_0800EFE8(&work->base);
    TaskPoolDraw(&work->unk_1A4);
}

void task_hum_vixen_3(VixenWork* work) {
    if (gGameState.flags & 8) {
        ReleaseObjTiles(gBtlWork->unk_114);
    }
    func_0800E380(&work->base);
    TaskPoolDestroy(&work->unk_1A4);
}

void task_hum_vixen_ndl_0(VixenNdlWork* work, VixenNdlArgs* args) {
    work->palette = LoadObjPalette(gUnk_08F6DCA4, 0x20);
    work->unk_00 = args->unk_18;
    AnimInit(&work->anim, gUnk_09EE26B0, gUnk_09EE2690);
    AnimStart(&work->anim, 0, 0);
    work->unk_2C = args->unk_12;
    work->x = args->unk_00;
    work->y = args->unk_04 + (GetRandom() % 11 - 5) * 256;
    work->z = args->unk_08;
    work->unk_2D = 0;
    m4aSongNumStart(0x286);

    if ((GetRandom() & 1) != 0) {
        work->unk_2E = 1;
    } else {
        work->unk_2E = 0;
    }
}

u8 task_hum_vixen_ndl_1(VixenNdlWork* work) {
    if ((gBtlWork->unk_068 & 0x40) == 0) {
        return 0;
    }

    if (AnimIsFinished(&work->anim)) {
        return 0;
    }

    switch (AnimGetFrame(&work->anim)) {
    case 1:
    case 2:
        if (work->unk_2D == 0) {
            if (gFrameCounter % 8 == work->unk_2C) {
                func_08011F78(0x13A, work->x, work->y, 0, 4, 4, 16);
            }
        }
        break;
    }

    if (gBtlWork->unk_07C->unk_34 & 0x2000) {
        work->unk_2D = 1;
    }
    AnimUpdate(&work->anim);
    return 1;
}

void task_hum_vixen_ndl_2(VixenNdlWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 attr;

    gfx = AnimGetGfx(&work->anim);
    attr = func_0801AF1C(work->y);

    if (work->unk_2E != 0) {
        attr |= 1;
    }
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->unk_00, work->palette, 0, attr,
        -0x1004 - (work->y >> 8) * 4);
}

void task_hum_vixen_ndl_3(VixenNdlWork* work) {
    ReleaseObjPalette(work->palette);
}

void task_hum_vixen_ice_0(VixenIceWork* work, VixenSub* args) {
    work->palette = LoadObjPalette(gUnk_08F6DCA4, 0x20);
    work->tiles = LoadObjTiles(gUnk_08EE4264, 0x800);
    work->unk_24 = args;
    work->unk_00 = 3;
    AnimInit(&work->anim, gUnk_09EE26CC, gUnk_09EE26B4);
    AnimStart(&work->anim, 0, 0);
    func_080122AC(&work->unk_28, 12, 27, 1);
    func_08012614(&work->unk_28, 1);
}

u8 task_hum_vixen_ice_1(VixenIceWork* work) {
    if (work->unk_24->unk_01 == 0) {
        if (work->unk_24->unk_00 != 0) {
            func_080062F4(((ObjPalette*)work->palette)->unk_06 + 16, 1);
            work->unk_24->unk_00 = 0;
            func_08012614(&work->unk_28, 1);
        }
        return 1;
    }

    if (work->unk_24->unk_00 != 0) {
        func_080062F4(((ObjPalette*)work->palette)->unk_06 + 16, 0);
        work->unk_24->unk_00 = 0;
        work->unk_00 = 0;
        work->unk_84 = 0;
        work->unk_8C = 10;

        switch (GetRandom() % 3) {
        case 0:
            work->unk_90 = 0x100;
            break;
        case 1:
            work->unk_90 = 0xC0;
            break;
        case 2:
            work->unk_90 = 0x80;
            break;
        }
    }

    switch (work->unk_00) {
    case 0:
        if (work->unk_84 == 0) {
            work->unk_86 = 30;
            work->unk_84++;
        }
        ApproachValue(&work->unk_8C, work->unk_90, work->unk_86);
        work->unk_86--;
        if ((s16)work->unk_86 <= 0) {
            func_08012614(&work->unk_28, 0);
            work->unk_00 = 1;
            work->unk_84 = 0;
            work->unk_88 = GetRandom() % 0x259 + 600;
        }
        break;
    case 1:
        if (work->unk_84 == 0) {
            AnimStart(&work->anim, 0, 0);
            work->unk_84++;
        }

        if (GetRandom() % 300 == 0) {
            work->unk_00 = 2;
            work->unk_84 = 0;
        }
        break;
    case 2:
        if (work->unk_84 == 0) {
            AnimStart(&work->anim, 1, 0);
            work->unk_84++;
        }

        if (AnimIsFinished(&work->anim)) {
            work->unk_00 = 1;
            work->unk_84 = 0;
        }
        break;
    }

    switch (work->unk_00) {
    case 1:
    case 2:
        ApproachValue(&work->unk_8C, 10, work->unk_88);
        work->unk_88--;
        if ((s16)work->unk_88 <= 0) {
            work->unk_24->unk_01 = 0;
            work->unk_24->unk_00 = 1;
        }
        ColliderSetRadius(&work->unk_28, work->unk_8C * 27 >> 8);
        func_08012324(&work->unk_28, work->unk_24->unk_04, work->unk_24->unk_08, 0);
        break;
    }
    AnimUpdate(&work->anim);
    return 1;
}

void task_hum_vixen_ice_2(VixenIceWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    s32 s;
    s32 affine;

    if (work->unk_24->unk_01 != 0) {
        gfx = AnimGetGfx(&work->anim);
        WorldToScreen(&x, &y, work->unk_24->unk_04, work->unk_24->unk_08, 0);
        s = work->unk_8C * gBtlWork->unk_024 >> 8;
        if (gBtlWork->unk_018 != 0 || s > 0x100) {
            affine = AllocObjAffine(gBtlWork->unk_018, s, s, 1);
        } else {
            affine = AllocObjAffine(gBtlWork->unk_018, s, s, 0);
        }
        DrawSprite(x, y, gfx, work->tiles, work->palette, affine, 0x800, 0xFFFF);
    }
}

void task_hum_vixen_ice_3(VixenIceWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    func_08012304(&work->unk_28);
}

void task_hum_vixen_frz_0(VixenFrzWork* work, VixenNdlArgs* args) {
    work->palette = LoadObjPalette(gUnk_08F6DCA4, 0x20);
    work->unk_00 = gBtlWork->unk_114;

    if (gGameState.flags & 8) {
        if (gBtlWork->unk_068 & 0x800000000000) {
            work->unk_32 = 2;
        } else {
            work->unk_32 = 1;
        }
    } else {
        work->unk_32 = 0;
    }
    AnimInit(&work->anim, 0, 0);
    func_08019068(gUnk_0813F91C, &work->anim, 0, 0, work->unk_00);
    work->unk_2C = 0;

    if (gBtlWork->unk_07C->unk_34 & 4) {
        work->unk_34 = 0;
    } else {
        work->unk_34 = 1;
    }
    m4aSongNumStart(0x1FE);
    work->x = args->unk_00;
    work->y = args->unk_04;
    work->z = args->unk_08;
}

INCLUDE_ASM("hum/task_hum_vixen_frz_1.s");

void task_hum_vixen_frz_2(VixenFrzWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 attr;

    if (work->unk_2C != 6) {
        gfx = AnimGetGfx(&work->anim);
        attr = func_0801AF1C(work->y) | work->unk_34;
        WorldToScreen(&x, &y, work->x, work->y, work->z);
        DrawSprite(x, y, gfx, work->unk_00, work->palette, 0, attr,
            -0x1004 - (work->y >> 8) * 4);
    }
}

void task_hum_vixen_frz_3(VixenFrzWork* work) {
    ReleaseObjPalette(work->palette);
}

void task_hum_vixen_frg_0(VixenFrgWork* work, VixenNdlArgs* args) {
    VixenFrgSub* e;
    s32 i;
    s32 a;
    s32 b;

    func_0800380C(work, ((ObjPalette*)gBtlWork->unk_114)->unk_06, gUnk_08C1E78C, 0x4C0);
    work->unk_30 = work;
    work->palette = LoadObjPalette(gUnk_08F6DCA4, 0x20);
    work->unk_38 = 0;
    work->unk_21C = 0;

    for (i = 0; i < 15; i++) {
        VixenFrgDef* d = &gUnk_0813FA00[i];
        e = &work->unk_3C[i];
        e->unk_04 = args->unk_00 + (d->unk_00 << 8);
        e->unk_08 = args->unk_04;
        e->unk_0C = args->unk_08 + (d->unk_02 << 8);
        e->unk_1C = d->unk_06;
        e->unk_00 = gUnk_09EE218C[d->unk_04];
        e->unk_10 = GetRandom() % 0x401 - 0x500;
        a = (u8)GetRandom();
        b = GetRandom() % 0x380;
        e->unk_14 = gSineTable[a] * b >> 8;
        e->unk_18 = -gSineTable[a + 64] * (b >> 1) >> 8;
    }
    m4aSongNumStart(0x2A0);
}

u8 task_hum_vixen_frg_1(VixenFrgWork* work) {
    VixenFrgSub* e;
    s32 i;

    if (gBtlWork->unk_068 & 0x200000) {
        return 0;
    }

    for (i = 0; i < 15; i++) {
        e = &work->unk_3C[i];
        e->unk_04 += e->unk_14;
        e->unk_08 += e->unk_18;
        e->unk_0C += e->unk_10;
        e->unk_10 += gBtlWork->unk_12C;

        if (e->unk_0C > 0) {
            e->unk_0C = 0;
            e->unk_10 = -(e->unk_10 >> 1);
            e->unk_14 = e->unk_14 >> 1;
            e->unk_18 = e->unk_18 >> 1;
        }
        func_0801A8A4(&e->unk_04, &e->unk_08, 0, 0);
    }
    work->unk_38++;
    if (work->unk_38 == 50) {
        work->unk_21C = 1;
    }

    if (work->unk_38 > 70) {
        return 0;
    }
    return 1;
}

void task_hum_vixen_frg_2(VixenFrgWork* work) {
    VixenFrgSub* p;
    s16 x;
    s16 y;
    u16 attr;
    s32 i;

    if (work->unk_21C != 0) {
        if (work->unk_38 & 1) {
            return;
        }
    }
    p = work->unk_3C;

    for (i = 0; i < 15; i++) {
        attr = func_0801AF1C(p[i].unk_08) | p[i].unk_1C;
        WorldToScreen(&x, &y, p[i].unk_04, p[i].unk_08, p[i].unk_0C);
        DrawSprite(x, y, p[i].unk_00, work->unk_30, work->palette, 0, attr,
            -0x1004 - (p[i].unk_08 >> 8) * 4);
    }
}

void task_hum_vixen_frg_3(VixenFrgWork* work) {
    ReleaseObjPalette(work->palette);
}

void func_080560AC(HumWork* work, s32 a) {
    HumActor* act;
    s32 t;

    if (a != 0) {
        act = &work->unk_040;
        t = a + gSineTable[gFrameCounter * 4 % 256] * 3;
        work->unk_158 = 0;
        act->unk_0C += (t - act->unk_0C) >> 4;
    }
}

void task_hum_lexceus_0(LexceusWork* work) {
    func_0800E168(&work->base, gUnk_0813FB38);
    work->unk_1CA = 0;
    work->unk_1C4 = 0;
    work->unk_1CC = 0;
    work->unk_1F8 = 0;
    work->unk_1F0 = 0;
    work->unk_1F4 = 0;
    work->unk_1FC = 0;
    work->base.unk_184 = (u32)gUnk_0813FA8C;
    TaskPoolInit(&work->unk_1D8, 3);
}

INCLUDE_ASM("hum/task_hum_lexceus_1.s");

void task_hum_lexceus_2(LexceusWork* work) {
    func_0800EFE8(&work->base);

    if (work->unk_1CC > 0) {
        ApproachValue(&work->base.unk_168, work->unk_1D0, work->unk_1CC);
        ApproachValue(&work->base.unk_16C, work->unk_1D4, work->unk_1CC);
        work->unk_1CC--;
    }
    TaskPoolDraw(&work->unk_1D8);
}

void task_hum_lexceus_3(LexceusWork* work) {
    func_0800E380(&work->base);
    TaskPoolDestroy(&work->unk_1D8);
}

void task_hum_lex_tmh_0(LexTmhWork* work, VixenNdlArgs* args) {
    work->unk_04 = LoadObjPalette(gUnk_09618478, 0x20);
    work->unk_00 = AllocObjTiles(0x400, gUnk_08C3724C);
    AnimInit(&work->anim, gUnk_09EE22B0, gUnk_09EE2298);
    AnimStart(&work->anim, 0, 1);

    if (args->unk_12 != 0) {
        work->unk_2C = 1;
    } else {
        work->unk_2C = 0;
    }
    work->x = args->unk_00;
    work->y = args->unk_04;
    work->z = args->unk_08;
    work->unk_34 = gBtlWork->unk_130 + (GetRandom() % 65 - 32) * 256;
    work->unk_38 = gBtlWork->unk_134 + (GetRandom() % 33 - 16) * 256;
    work->unk_30 = 0;
    work->unk_4A = 0;
    work->unk_2D = 0;
    work->unk_3C = -0x980;
    work->unk_40 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    work->unk_44 = LoadObjPalette(gUnk_08F69BA4, 0x20);
    m4aSongNumStart(0x2B1);
}

u8 task_hum_lex_tmh_1(LexTmhWork* work) {
    if ((gBtlWork->unk_068 & 0x40) == 0) {
        return 0;
    }

    if (work->unk_2D != 0) {
        return 0;
    }

    switch (work->unk_30) {
    case 0:
        work->x += (work->unk_34 - work->x) >> 4;
        work->y += (work->unk_38 - work->y) >> 4;
        work->z += work->unk_3C;
        work->unk_3C += 64;

        if (func_08011F78(0x146, work->x, work->y, work->z, 16, 12, 16)) {
            m4aSongNumStart(0x2B3);
            work->unk_4A = 0;
            work->unk_30 = 1;
        } else if (work->z >= 0) {
            m4aSongNumStart(0x2B2);
            work->unk_4A = 0;
            work->unk_30 = 1;
        } else {
            work->unk_4A++;
        }
        break;
    case 1:
        if (work->unk_4A == 0) {
            work->unk_3C = -work->unk_3C >> 1;

            if (gBtlWork->unk_130 < work->x) {
                work->unk_48 = 1;
            } else {
                work->unk_48 = 0;
            }
        }

        if (work->x < (gBtlWork->unk_0DA - 32) << 8 ||
            work->x > (gBtlWork->unk_0DC + 32) << 8) {
            work->unk_2D = 1;
        }

        if (work->unk_48 != 0) {
            work->x += -0x400;
        } else {
            work->x += 0x400;
        }
        work->y += (gBtlWork->unk_134 - work->y) >> 4;
        work->z += work->unk_3C;
        work->unk_3C += 64;

        if (func_08011F78(0x146, work->x, work->y, work->z, 16, 12, 16)) {
            m4aSongNumStart(0x2B3);
        }

        if (work->z >= 0) {
            m4aSongNumStart(0x2B2);
            work->unk_3C = -work->unk_3C >> 1;
            work->z = 0;
        }
        work->unk_4A++;
        break;
    }
    AnimUpdate(&work->anim);
    return 1;
}

void task_hum_lex_tmh_2(LexTmhWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 attr;
    s32 affine;
    s32 scale;

    gfx = AnimGetGfx(&work->anim);

    if (work->unk_2C != 0) {
        attr = func_0801AF1C(work->y);
    } else {
        attr = func_0801AF1C(work->y) | 1;
    }
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->unk_00, work->unk_04, 0, attr,
        -0x1004 - (work->y >> 8) * 4);

    if (work->z >= 0) {
        affine = 0;
    } else {
        scale = 0x100 - (-work->z) / 256;
        if (scale <= 75) {
            scale = 76;
        }
        affine = AllocObjAffine(0, scale, scale, 0);
    }
    WorldToScreen(&x, &y, work->x, work->y, 0);
    DrawSprite(x, y, gUnk_08B22BA8, work->unk_40, work->unk_44, affine, attr, 0xFFF0);
}

void task_hum_lex_tmh_3(LexTmhWork* work) {
    ReleaseObjTiles(work->unk_40);
    ReleaseObjPalette(work->unk_44);
    ReleaseObjTiles(work->unk_00);
    ReleaseObjPalette(work->unk_04);
}

void task_hum_lex_tmh0_0(LexTmh0Work* work, VixenNdlArgs* args) {
    work->palette = LoadObjPalette(gUnk_09618478, 0x20);
    work->tiles = AllocObjTiles(0x400, gUnk_08C3151E);
    AnimInit(&work->anim, gUnk_09EE2288, gUnk_09EE2250);
    AnimStart(&work->anim, 2, 1);

    if (args->unk_12 != 0) {
        work->unk_2C = 1;
    } else {
        work->unk_2C = 0;
    }
    work->x = args->unk_00;
    work->y = args->unk_04;
    work->z = args->unk_08;
    work->unk_30 = 10;
    work->unk_34 = 21;
    m4aSongNumStart(0x2B4);
}

u8 task_hum_lex_tmh0_1(LexTmh0Work* work) {
    if (gBtlWork->unk_068 & 0x40) {
        ApproachValue(&work->unk_30, 0x100, work->unk_34--);

        if (work->unk_34 > 0) {
            AnimUpdate(&work->anim);
            return 1;
        }
    }
    return 0;
}

void task_hum_lex_tmh0_2(LexTmh0Work* work) {
    void* gfx;
    u16 attr;
    s32 sx;
    s32 h;
    s32 affine;
    s16 x;
    s16 y;

    gfx = AnimGetGfx(&work->anim);
    attr = func_0801AF1C(work->y);
    h = work->unk_30;
    if (h == 0x100) {
        if (work->unk_2C == 0) {
            attr |= 1;
        }
        sx = h;
    } else {
        if (work->unk_2C != 0) {
            sx = h;
        } else {
            sx = -h;
        }
    }
    affine = AllocObjAffine(0, sx, 0x100, 0);
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, affine, attr,
        -0x100C - (work->y >> 8) * 4);
}

void task_hum_lex_tmh0_3(LexTmh0Work* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_hum_lex_rock_0(LexRockWork* work, VixenNdlArgs* args) {
    if (args->unk_12 != 0) {
        work->unk_160 = 1;
    } else {
        work->unk_160 = 0;
    }
    work->x = args->unk_00;
    work->y = args->unk_04;
    work->z = args->unk_08;
    work->unk_162 = 0;
    work->unk_164 = 0;
    work->tiles = LoadObjTiles(gUnk_08B22CE4, 0x200);
    work->unk_2BC = LoadObjPalette(gUnk_08F69BA4, 0x20);
    work->unk_2C0 = 0;
}

INCLUDE_ASM("hum/task_hum_lex_rock_1.s");

void task_hum_lex_rock_2(LexRockWork* work) {
    void* gfx;
    u16 attr;
    s16 x;
    s16 y;
    s32 i;
    LexRockSub* e;

    if (work->unk_2C0 != 0 && (work->unk_166 & 1)) {
        return;
    }

    if (work->unk_164 == 1) {
        gfx = AnimGetGfx(&work->unk_34[0]);

        if (work->unk_160 != 0) {
            attr = func_0801AF1C(work->y);
        } else {
            attr = func_0801AF1C(work->y) | 1;
        }
        WorldToScreen(&x, &y, work->x, work->y, work->z);
        DrawSprite(x, y, gfx, work->unk_00[0], work->unk_30, 0, attr,
            -0x1006 - (work->y >> 8) * 4);
    } else if (work->unk_164 == 12) {
        for (i = 0; i < work->unk_164; i++) {
            e = &work->unk_16C[i];
            gfx = AnimGetGfx(&work->unk_34[i]);

            if (work->unk_160 != 0) {
                attr = func_0801AF1C(e->unk_04);
            } else {
                attr = func_0801AF1C(e->unk_04) | 1;
            }
            WorldToScreen(&x, &y, e->unk_00, e->unk_04,
                e->unk_08);
            DrawSprite(x, y, gfx, work->unk_00[i], work->unk_30, 0, attr,
                -0x1006 - (e->unk_04 >> 8) * 4);
            WorldToScreen(&x, &y, e->unk_00, e->unk_04, 0);
            DrawSprite(x, y, gUnk_08B22CBC, work->tiles, work->unk_2BC, 0, attr, 0xFFFE);
        }
    }
}

void task_hum_lex_rock_3(LexRockWork* work) {
    s32 i;

    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->unk_2BC);

    if (work->unk_164 != 0) {
        ReleaseObjPalette(work->unk_30);

        for (i = 0; i < work->unk_164; i++) {
            ReleaseObjTiles(work->unk_00[i]);
        }
    }
}

void task_hum_mahluxia_flw_0(MahluxiaFlwWork* work, VixenNdlArgs* args) {
    work->palette = LoadObjPalette(gUnk_08F6DC84, 0x20);
    work->tiles = LoadObjTiles(gUnk_08BCB3D8, 0x100);
    work->unk_00 = 0;
    work->x = args->unk_00;
    work->y = args->unk_04;
    work->z = args->unk_08;
    work->unk_2C = GetRandom() % 717 - 358;
    work->unk_28 = -(GetRandom() % 539 + 102);
    AnimInit(&work->anim, gUnk_09EE1CB4, gUnk_09EE1C94);
    AnimStart(&work->anim, GetRandom() & 1, 1);
}

u8 task_hum_mahluxia_flw_1(MahluxiaFlwWork* work) {
    switch (work->unk_00) {
    case 0:
        work->x += work->unk_2C;
        work->z += work->unk_28;
        work->unk_28 += 17;
        if (work->unk_28 > 0x1CC) {
            work->unk_00 = 1;
        }
        break;
    case 1:
        work->x += work->unk_2C;
        work->z += work->unk_28;
        work->unk_28 -= 12;
        if (work->unk_28 < 0) {
            work->unk_28 = GetRandom() % 181 + 204;

            if (work->unk_2C > 0) {
                work->unk_2C = -(GetRandom() % 257 + 128);
            } else {
                work->unk_2C = GetRandom() % 257 + 128;
            }
        }

        if (work->z >= 0) {
            return 0;
        }
        break;
    }
    AnimUpdate(&work->anim);
    return 1;
}

void task_hum_mahluxia_flw_2(MahluxiaFlwWork* work) {
    s16 x;
    s16 y;
    void* gfx;

    gfx = AnimGetGfx(&work->anim);
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, 0, 0x800,
        -0x1004 - (work->y >> 8) * 4);
}

void task_hum_mahluxia_flw_3(MahluxiaFlwWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void func_08057CBC(RikuWork* work, s16 a, s32 b) {
    HumWork* w = &work->base;
    HumActor* act = &w->unk_040;

    if (act->unk_34 & 4) {
        work->base.unk_15C = act->unk_04 - (a << 8);
    } else {
        work->base.unk_15C = act->unk_04 + (a << 8);
    }
    w->unk_160 = act->unk_08;
    w->unk_170 = 19;
    w->unk_150 = 0;
    work->unk_1C4 = -b;
    work->unk_1C8 = 0;
}

void func_08057D30(RikuWork* work, s32 a, s32 b) {
    work->base.unk_15C = a;
    work->base.unk_160 = b;
    work->base.unk_170 = 19;
    work->base.unk_150 = 0;
    work->unk_1C4 = -0x500;
}

u8 func_08057D68(RikuWork* work) {
    s32 v;
    s32 w;
    Collider* c;

    c = gBtlWork->unk_07C;

    if (GetRandom() % 30 == 0) {
        func_0801C700(&work->base.unk_040, &v, &w, 0);
        func_0800F368(work, 1);

        if (func_0800F504(work, 0x100, 0x100, 0x100)) {
            if (gBtlWork->unk_068 & 0x8000) {
                func_08057CBC(work, -99, 0x280);
            } else if (GetRandom() & 1) {
                if (c->unk_34 & 4) {
                    func_08057D30(work, v + 0x2800, w);
                } else {
                    func_08057D30(work, v - 0x2800, w);
                }
            } else {
                func_08057CBC(work, -80, 0x500);
            }
            return 1;
        }
    }
    return 0;
}

void func_08057E2C(RikuWork* work, RikuSpawn* dst) {
    HumActor* act = &work->base.unk_040;

    dst->x = act->unk_04;
    dst->y = act->unk_08;
    dst->z = act->unk_0C;

    if (act->unk_34 & 4) {
        dst->unk_0C |= 1;
    } else {
        dst->unk_0C &= 0xFFFE;
    }
    dst->unk_10 = work->base.anim;
    dst->unk_28 = *(u32*)work->base.tiles;
    dst->unk_2C = gBtlWork->unk_024;
}

void func_08057E90(RikuWork* work, RikuSpawn* p) {
    HumActor* act;
    HumSub* sub;
    void* gfx;
    u16 attr;
    s32 sx;
    s32 sy;
    s32 affine;
    s16 x;
    s16 y;
    u16 pri;

    sub = work->base.unk_00C;
    gfx = AnimGetGfx(&p->unk_10);
    act = &work->base.unk_040;

    if (func_080128EC() == 0) {
        gBldCnt = 0xF10;
        SetBlendAlpha(6, 12);
        attr = 0x804;
    } else {
        attr = func_0801AF1C(act->unk_08);
    }

    if (p->unk_0C & 1) {
        sy = p->unk_2C;
        sx = sy;
    } else if (p->unk_2C == 0x100) {
        sy = p->unk_2C;
        sx = sy;
        attr |= 1;
    } else {
        sx = -gBtlWork->unk_024;
        sy = gBtlWork->unk_024;
    }

    if (sy == 0x100 && sx == sy) {
        affine = 0;
    } else if (sy <= 255) {
        affine = AllocObjAffine(0, sx, sy, 0);
    } else {
        affine = AllocObjAffine(0, sx, sy, 1);
    }
    pri = 0xFFF0;
    WorldToScreen(&x, &y, p->x, p->y, p->z);
    func_08002A10(sub->tiles, p->unk_28);
    DrawSprite(x, y, gfx, sub->tiles, work->base.palette, affine, attr, pri);
}

void task_hum_riku_0(RikuWork* work) {
    func_0800E168(&work->base, gUnk_0813FD24);
    func_0800E314(&work->base, &work->unk_188, gUnk_0813FD40);
    work->unk_1C4 = 0;
    work->unk_1CA = 0;
    work->unk_188.unk_34 |= 3;
    work->unk_1CC = 0;

    if (gBtlWork->unk_10C != 0xA1) {
        work->base.unk_184 = (u32)gUnk_0813FBBC;
    }
    func_08057E2C(work, &work->unk_1D0[0]);
    work->unk_1D0[1] = work->unk_1D0[0];
    work->unk_1D0[2] = work->unk_1D0[0];
    work->unk_1D0[3] = work->unk_1D0[0];
    work->unk_1D0[4] = work->unk_1D0[0];
    work->unk_1D0[5] = work->unk_1D0[0];
    work->unk_1D0[6] = work->unk_1D0[0];
    work->unk_1D0[7] = work->unk_1D0[0];
    work->unk_1D0[8] = work->unk_1D0[0];
}

INCLUDE_ASM("hum/task_hum_riku_1.s");

void task_hum_riku_2(RikuWork* work) {
    func_0800EFE8(&work->base);

    if ((work->unk_1CA & 4) && (work->unk_188.unk_34 & 2)) {
        switch (work->unk_1CC % 2) {
        case 0:
            func_08057E90(work, &work->unk_1D0[2]);
            break;
        case 1:
            func_08057E90(work, &work->unk_1D0[4]);
            break;
        }
        work->unk_1CC++;
    }
    work->unk_1D0[4] = work->unk_1D0[3];
    work->unk_1D0[3] = work->unk_1D0[2];
    work->unk_1D0[2] = work->unk_1D0[1];
    work->unk_1D0[1] = work->unk_1D0[0];
    func_08057E2C(work, &work->unk_1D0[0]);
}

void task_hum_riku_3(HumWork* work) {
    func_0800E380(work);
}

void task_hum_leon_0(LeonWork* work) {
    func_0800E168(&work->base, gUnk_0813FDA8);
    work->unk_188 = 0;
    work->unk_18A = 0;
    func_08019068(gUnk_0813FD58, &work->base.anim, 0, 1, work->base.tiles);
    work->unk_18C = gGameState.unk_10C;
    work->unk_194 = gGameState.unk_114;
    gGameState.unk_10C = 0;
    gGameState.unk_114 = 0;
}

#ifdef NON_MATCHING
u8 task_hum_leon_1(LeonWork* work) {
    LeonWork* w;
    HumActor* act;
    s32 x;
    s32 y;
    s32 z;
    s32 a;
    s32 b;
    s32 c;
    u8 r;

    w = work;
    act = &work->base.unk_040;
    func_0801C700(act, &a, &b, &c);

    switch (_0800E434(work)) {
    case 4:
        break;
    case 5:
        work->base.unk_170 = 19;
        work->base.unk_150 = 0;
        break;
    }
    func_0800F368(work, 1);

    switch (work->base.unk_170) {
    case 12:
        func_08019068(gUnk_0813FD58, &w->base.anim, 0, 1, w->base.tiles);
        break;
    case 0:
        if (gBtlWork->unk_068 & 0x20000000000) {
            if (w->unk_18A == 0) {
                func_08019068(gUnk_0813FD58, &w->base.anim, 1, 0, w->base.tiles);
                w->unk_18A = 1;
            } else if (AnimIsFinished(&work->base.anim)) {
                func_08019068(gUnk_0813FD58, &w->base.anim, 3, 0, w->base.tiles);
            }
        } else {
            if (w->unk_18A != 0) {
                func_08019068(gUnk_0813FD58, &w->base.anim, 2, 0, w->base.tiles);
                w->unk_18A = 0;
            } else if (AnimIsFinished(&work->base.anim)) {
                func_08019068(gUnk_0813FD58, &w->base.anim, 0, 1, w->base.tiles);
            }
        }

        if (gBtlWork->unk_068 & 0x100000) {
            if (gBtlWork->unk_068 & 0x20000000) {
                work->base.unk_170 = 20;
                work->base.unk_150 = 0;
            }
        }
        break;
    case 1:
        if ((s16)work->base.unk_150 == 0) {
            func_0801AF08(act);
            func_08019068(gUnk_0813FD58, &w->base.anim, 4, 0, w->base.tiles);
            work->base.unk_150 = 8;
        }
        break;
    case 2:
        if (gBtlWork->unk_068 & 0x100000) {
            if (gBtlWork->unk_068 & 0x20000000) {
                work->base.unk_170 = 20;
                work->base.unk_150 = 0;
            }
        }
        break;
    case 20:
        if ((s16)work->base.unk_150 > 10) {
            gBtlWork->unk_0EF |= 32;
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    case 19:
        if ((s16)work->base.unk_150 > 80) {
            func_0801AF08(act);
            work->base.unk_170 = 0;
            work->base.unk_150 = 0;
        } else {
            work->base.unk_150++;
        }
        break;
    default:
        func_08019068(gUnk_0813FD58, &w->base.anim, 3, 0, w->base.tiles);
        func_0800F368(work, 1);
        break;
    }

    if ((s16)work->unk_188 > 0) {
        work->unk_188--;
        act->unk_34 |= 0x2000;
    } else {
        act->unk_34 &= ~0x2000;
    }
    x = act->unk_04;
    y = act->unk_08;
    z = act->unk_0C;
    r = func_0800E5F0(work);
    act->unk_04 = x;
    act->unk_08 = y;
    act->unk_0C = z;
    return r;
}
#else
INCLUDE_ASM("hum/task_hum_leon_1.s");
#endif

void task_hum_leon_2(HumWork* work) {
    func_0800EFE8(work);
}

void task_hum_leon_3(LeonWork* work) {
    gGameState.unk_10C = work->unk_18C;
    gGameState.unk_114 = work->unk_194;
    func_0800E380(&work->base);
}

void task_hum_robe_0(RobeWork* work) {
    func_0800E168(&work->base, gUnk_0813FDF4);
    work->unk_188 = 1;
    func_08019068(gUnk_0813FDD4, &work->base.anim, 0, 1, work->base.tiles);
}

u8 task_hum_robe_1(RobeWork* work) {
    HumActor* act = &work->base.unk_040;
    s32 x;
    s32 y;
    s32 z;
    u8 r;

    if (_0800E434(work) == 1) {
        work->base.unk_150 = 1;
    }

    if (gBtlWork->unk_068 & 0x20000000) {
        if (work->unk_188 == 1) {
            func_08019068(gUnk_0813FDD4, &work->base.anim, 1, 0, work->base.tiles);
            work->unk_188 = 0;
        }
    } else if (AnimIsFinished(&work->base.anim)) {
        func_08019068(gUnk_0813FDD4, &work->base.anim, 0, 1, work->base.tiles);
        work->unk_188 = 1;
    }
    func_0800F368(work, 1);
    x = act->unk_04;
    y = act->unk_08;
    z = act->unk_0C;
    r = func_0800E5F0(work);
    act->unk_04 = x;
    act->unk_08 = y;
    act->unk_0C = z;
    return r;
}

void task_hum_robe_2(HumWork* work) {
    func_0800EFE8(work);
}

void task_hum_robe_3(HumWork* work) {
    func_0800E380(work);
}

#ifdef NON_MATCHING
void MakeSaveHeaderData(SaveHeaderData* data, s16 file) {
    s16 i;

    data->flags = 0;

    if (gGameState.flags & 0x20) {
        data->flags = 1;
    }

    if (gGameState.flags & 0x800) {
        data->flags |= 4;

        if (gGameState.flags & 8) {
            data->flags |= 2;
        } else {
            data->flags &= ~2;
        }
    } else if (gGameState.flags & 0x20) {
        data->flags |= 2;
    }

    for (i = 0; i < 4; i++) {
        if (file == i) {
            data->files[i].unk_00 = gGameState.floor;
            data->files[i].unk_01 = gGameState.world;
            data->files[i].unk_02 = gUnk_02039CB8;
            data->files[i].unk_04 = gUnk_02039D8C;
        } else {
            data->files[i].unk_00 = gGameState.fileSummaries[i].unk_00;
            data->files[i].unk_01 = gGameState.fileSummaries[i].unk_01;
            data->files[i].unk_02 = gGameState.fileSummaries[i].unk_02;
            data->files[i].unk_04 = gGameState.fileSummaries[i].unk_04;
        }
    }
}
#else
INCLUDE_ASM("hum/MakeSaveHeaderData.s");
#endif

void MakeSaveSystem(SaveFileLarge* save) {
    save->common.flags = gGameState.flags;
    save->common.unk_8E = gGameState.hp;
    memcpy(save->common.unk_04, gGameState.unk_0F8, 0x88);
    save->common.unk_8C = gGameState.unk_180;
    save->common.unk_90 = gGameState.floor;
    save->common.unk_91 = gGameState.world;
    save->common.unk_94 = gGameState.playTime;
    func_080E92B8(save->unk_098);
    func_080A324C(save->unk_2EC);
    func_080C700C(save->unk_E6C);
    func_080DDEB0(save->unk_E70);
    func_0810962C(save->unk_EB4);
}

void MakeSaveFileLarge(SaveFileLarge* save) {
    save->common.flags = gGameState.flags;
    save->common.unk_8E = gGameState.hp;
    memcpy(save->common.unk_04, gGameState.unk_0F8, 0x88);
    save->common.unk_8C = gGameState.unk_180;
    save->common.unk_90 = gGameState.floor;
    save->common.unk_91 = gGameState.world;
    save->common.unk_94 = gGameState.playTime;
    func_080E92B8(save->unk_098);
    func_080A324C(save->unk_2EC);
    func_080C700C(save->unk_E6C);
    func_080DDEB0(save->unk_E70);
    func_0810962C(save->unk_EB4);

    if (gGameState.flags & 0x10) {
        gGameState.fileSummaries[1].unk_00 = gGameState.floor;
        gGameState.fileSummaries[1].unk_01 = gGameState.world;
        gGameState.fileSummaries[1].unk_02 = gGameState.level;
        gGameState.fileSummaries[1].unk_04 = gGameState.playTime;
    } else {
        gGameState.fileSummaries[0].unk_00 = gGameState.floor;
        gGameState.fileSummaries[0].unk_01 = gGameState.world;
        gGameState.fileSummaries[0].unk_02 = gGameState.level;
        gGameState.fileSummaries[0].unk_04 = gGameState.playTime;
    }
}

void MakeSaveFileSmall(SaveFileSmall* save) {
    save->common.flags = gGameState.flags;
    save->common.unk_8E = gGameState.hp;
    memcpy(save->common.unk_04, gGameState.unk_0F8, 0x88);
    save->common.unk_8C = gGameState.unk_180;
    save->common.unk_90 = gGameState.floor;
    save->common.unk_91 = gGameState.world;
    save->common.unk_94 = gGameState.playTime;
    func_080E92B8(save->unk_098);
    func_080A3370(save->unk_2EC);

    if (gGameState.flags & 0x10) {
        gGameState.fileSummaries[3].unk_00 = gGameState.floor;
        gGameState.fileSummaries[3].unk_01 = gGameState.world;
        gGameState.fileSummaries[3].unk_02 = gGameState.level;
        gGameState.fileSummaries[3].unk_04 = gGameState.playTime;
    } else {
        gGameState.fileSummaries[2].unk_00 = gGameState.floor;
        gGameState.fileSummaries[2].unk_01 = gGameState.world;
        gGameState.fileSummaries[2].unk_02 = gGameState.level;
        gGameState.fileSummaries[2].unk_04 = gGameState.playTime;
    }
}

void ApplySaveHeaderData(SaveHeaderData* data) {
    if (SaveRepairHeader() == SAVE_OK) {
        if (data->flags & 1) {
            gGameState.flags |= 0x20;
        }

        if (data->flags & 4) {
            gGameState.flags |= 0x800;
        }

        if (data->flags & 2) {
            gGameState.flags |= 0x200;
        }
    }

    if (SaveRepairFileLarge(0) == SAVE_OK) {
        gGameState.fileSummaries[0].unk_00 = data->files[0].unk_00;
        gGameState.fileSummaries[0].unk_01 = data->files[0].unk_01;
        gGameState.fileSummaries[0].unk_02 = data->files[0].unk_02;
        gGameState.fileSummaries[0].unk_04 = data->files[0].unk_04;
    } else {
        gGameState.fileSummaries[0].unk_00 = 0;
        gGameState.fileSummaries[0].unk_01 = 0;
        gGameState.fileSummaries[0].unk_02 = 0;
        gGameState.fileSummaries[0].unk_04 = 0;
    }

    if (SaveRepairFileLarge(1) == SAVE_OK) {
        gGameState.fileSummaries[1].unk_00 = data->files[1].unk_00;
        gGameState.fileSummaries[1].unk_01 = data->files[1].unk_01;
        gGameState.fileSummaries[1].unk_02 = data->files[1].unk_02;
        gGameState.fileSummaries[1].unk_04 = data->files[1].unk_04;
    } else {
        gGameState.fileSummaries[1].unk_00 = 0;
        gGameState.fileSummaries[1].unk_01 = 0;
        gGameState.fileSummaries[1].unk_02 = 0;
        gGameState.fileSummaries[1].unk_04 = 0;
    }

    if (SaveRepairFileSmall(0) == SAVE_OK) {
        gGameState.fileSummaries[2].unk_00 = data->files[2].unk_00;
        gGameState.fileSummaries[2].unk_01 = data->files[2].unk_01;
        gGameState.fileSummaries[2].unk_02 = data->files[2].unk_02;
        gGameState.fileSummaries[2].unk_04 = data->files[2].unk_04;
    } else {
        gGameState.fileSummaries[2].unk_00 = 0;
        gGameState.fileSummaries[2].unk_01 = 0;
        gGameState.fileSummaries[2].unk_02 = 0;
        gGameState.fileSummaries[2].unk_04 = 0;
    }

    if (SaveRepairFileSmall(1) == SAVE_OK) {
        gGameState.fileSummaries[3].unk_00 = data->files[3].unk_00;
        gGameState.fileSummaries[3].unk_01 = data->files[3].unk_01;
        gGameState.fileSummaries[3].unk_02 = data->files[3].unk_02;
        gGameState.fileSummaries[3].unk_04 = data->files[3].unk_04;
    } else {
        gGameState.fileSummaries[3].unk_00 = 0;
        gGameState.fileSummaries[3].unk_01 = 0;
        gGameState.fileSummaries[3].unk_02 = 0;
        gGameState.fileSummaries[3].unk_04 = 0;
    }
}

void ApplySaveSystem(SaveFileLarge* save) {
    u32 t;

    t = gGameState.flags & 0xA20;
    save->common.flags &= 0xFFFFF5DF;
    gGameState.flags = save->common.flags | t;
    gGameState.hp = save->common.unk_8E;
    memcpy(gGameState.unk_0F8, save->common.unk_04, 0x88);
    gGameState.unk_180 = save->common.unk_8C;
    gGameState.floor = save->common.unk_90;
    gGameState.world = save->common.unk_91;
    gGameState.playTime = save->common.unk_94;
    func_080E92F8(save->unk_098);
    func_080A32DC(save->unk_2EC);
    func_080C7024(save->unk_E6C);
    func_080DDEBC(save->unk_E70);
    func_08109638(save->unk_EB4);
}

void ApplySaveFileLarge(SaveFileLarge* save) {
    u32 t;

    t = gGameState.flags & 0xA20;
    save->common.flags &= 0xFFFFF5DF;
    gGameState.flags = save->common.flags | t;
    gGameState.hp = save->common.unk_8E;
    memcpy(gGameState.unk_0F8, save->common.unk_04, 0x88);
    gGameState.unk_180 = save->common.unk_8C;
    gGameState.floor = save->common.unk_90;
    gGameState.world = save->common.unk_91;
    gGameState.playTime = save->common.unk_94;
    func_080E92F8(save->unk_098);
    func_080A32DC(save->unk_2EC);
    func_080C7024(save->unk_E6C);
    func_080DDEBC(save->unk_E70);
    func_08109638(save->unk_EB4);
    gGameState.flags &= ~8;
}

void ApplySaveFileSmall(SaveFileSmall* save) {
    u32 t;

    t = gGameState.flags & 0xA20;
    save->common.flags &= 0xFFFFF5DF;
    gGameState.flags = save->common.flags | t;
    gGameState.hp = save->common.unk_8E;
    memcpy(gGameState.unk_0F8, save->common.unk_04, 0x88);
    gGameState.unk_180 = save->common.unk_8C;
    gGameState.floor = save->common.unk_90;
    gGameState.world = save->common.unk_91;
    gGameState.playTime = save->common.unk_94;
    func_080E92F8(save->unk_098);
    func_080A3398(save->unk_2EC);
    gGameState.flags |= 8;
}
