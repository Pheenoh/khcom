#include "macros.h"
#include "hum.h"

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

void task_hum_hook_moon_0(HookMoonWork* work) {
    work->unk_00 = LoadObjTiles(gUnk_08B5A872, 0xC00);
    func_08007E68(0);
    work->unk_04 = LoadObjPalette(gUnk_08F6DC64, 0x20);
    func_08007E7C();
    func_0801C298(work->unk_04[6] + 16, 0);
    work->unk_0A = 0;
    work->unk_08 = 0;
}

u8 task_hum_hook_moon_1(HookMoonWork* work) {
    work->unk_08++;
    return 1;
}

INCLUDE_ASM("hum/task_hum_hook_moon_2.s");

void task_hum_hook_moon_3(HookMoonWork* work) {
    ReleaseObjTiles(work->unk_00);
    ReleaseObjPalette(work->unk_04);
}

INCLUDE_ASM("hum/task_hum_hook_bomb_0.s");
INCLUDE_ASM("hum/task_hum_hook_bomb_1.s");
INCLUDE_ASM("hum/task_hum_hook_bomb_2.s");

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

INCLUDE_ASM("hum/func_0804D060.s");

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

INCLUDE_ASM("hum/task_hum_ansem_3.s");

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
        LoadObjPaletteBank(((u16*)work->base.unk_008)[3], gUnk_09617F18);
        work->base.unk_178 = gUnk_09617F18;
        work->unk_1CA &= 0xFFFE;
        work->base.unk_184 = (u32)gUnk_0813F214;
    } else {
        work->unk_1CC++;
    }
    func_0801AF08(act);
}

INCLUDE_ASM("hum/task_hum_hades_0.s");
INCLUDE_ASM("hum/task_hum_hades_1.s");
INCLUDE_ASM("hum/task_hum_hades_2.s");

void task_hum_hades_3(HadesWork* work) {
    ReleaseObjTiles(work->unk_1D4);
    ReleaseObjTiles(work->unk_1D8);
    ReleaseObjTiles(work->unk_1DC);
    ReleaseObjPalette(work->unk_228);
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
        w->unk_160 = (gUnk_02039B84->unk_0DE + 16) << 8;
    } else {
        w->unk_160 = (gUnk_02039B84->unk_0E0 - 16) << 8;
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

    c = gUnk_02039B84->unk_07C;
    func_0801C700(&work->base.unk_040, &v, 0, 0);
    func_0800F368(work, 1);
    if (func_0800F504(work, 0x100, 0x100, 0x100)) {
        if (gUnk_02039B84->unk_068 & 0x8000) {
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

    dst->unk_00 = act->unk_04;
    dst->unk_04 = act->unk_08;
    dst->unk_08 = act->unk_0C;
    if (act->unk_34 & 4) {
        dst->unk_0C |= 1;
    } else {
        dst->unk_0C &= 0xFFFE;
    }
    dst->unk_10 = work->base.unk_014;
    dst->unk_28 = *(u32*)work->base.unk_004;
    dst->unk_2C = gUnk_02039B84->unk_024;
}

INCLUDE_ASM("hum/func_0804FAD4.s");

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

INCLUDE_ASM("hum/task_hum_mahluxia_0.s");
INCLUDE_ASM("hum/func_0804FD7C.s");
INCLUDE_ASM("hum/task_hum_mahluxia_1.s");
INCLUDE_ASM("hum/task_hum_mahluxia_2.s");
INCLUDE_ASM("hum/task_hum_mahluxia_3.s");

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
    TaskCreate(&work->unk_194, gUnk_09EDB668, &args);
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
    work->unk_04 = LoadObjPalette(gUnk_09618458, 0x20);
    work->unk_00 = LoadObjTiles(gUnk_08BD99F4, 0x2C0);
    AnimInit(&work->unk_08, gUnk_09EE1DB4, gUnk_09EE1DA4);
    AnimStart(&work->unk_08, 0, 0);
    if (args->unk_12 != 0) {
        work->unk_2C = 1;
    } else {
        work->unk_2C = 0;
    }
    work->unk_20 = args->unk_00;
    work->unk_24 = args->unk_04;
    work->unk_28 = args->unk_08;
    work->unk_2E = 0;
    work->unk_2D = 1;
    work->unk_3C = 0;
    work->unk_30 = gUnk_02039B84->unk_07C->unk_04;
    work->unk_34 = gUnk_02039B84->unk_07C->unk_08;
    work->unk_38 = gUnk_02039B84->unk_07C->unk_0C;
    work->unk_40 = GetRandom() % 897 + 0x800;
    m4aSongNumStart(0x2A4);
}

INCLUDE_ASM("hum/task_hum_laxene_knf_1.s");

void task_hum_laxene_knf_2(LaxeneKnfWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 attr;

    gfx = AnimGetGfx(&work->unk_08);
    if (work->unk_2C != 0) {
        attr = func_0801AF1C(work->unk_24);
    } else {
        attr = func_0801AF1C(work->unk_24) | 1;
    }
    WorldToScreen(&x, &y, work->unk_20, work->unk_24, work->unk_28);
    DrawSprite(x, y, gfx, work->unk_00, work->unk_04, 0, attr,
        -0x1004 - (work->unk_24 >> 8) * 4);
    if (func_080035CC(x, y, 2, 2, 32, 32)) {
        work->unk_2D = 0;
    }
}

INCLUDE_ASM("hum/task_hum_laxene_knf_3.s");

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
        TaskCreate(&work->unk_220, gUnk_09EDB698, args);
    }
}

INCLUDE_ASM("hum/task_hum_axcel_0.s");
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
        DrawSprite(x, y, gUnk_08B22BA8, work->unk_218, work->unk_21C, affine, 0x800, 0xFFFE);
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
    ReleaseObjTiles(work->unk_218);
    ReleaseObjPalette(work->unk_21C);
    func_0800E380(&work->base);
}

void task_hum_axcel_ptc_0(AxcelPtcWork* work, s32* args) {
    work->unk_24 = args[0];
    work->unk_28 = args[1];
    work->unk_2C = args[2];
    work->unk_00 = LoadObjTiles(gUnk_08BF73C6, 0x300);
    work->unk_04 = LoadObjPalette(gUnk_08F69BA4, 0x20);
    AnimInit(&work->unk_0C, gUnk_09EE1FC0, gUnk_09EE1F90);
    switch (GetRandom() % 3) {
    case 0:
        AnimStart(&work->unk_0C, 0, 0);
        break;
    case 1:
        AnimStart(&work->unk_0C, 1, 0);
        break;
    case 2:
        AnimStart(&work->unk_0C, 2, 0);
        break;
    }
}

u8 task_hum_axcel_ptc_1(AxcelPtcWork* work) {
    if (AnimIsFinished(&work->unk_0C)) {
        return 0;
    }
    work->unk_08 = AnimUpdate(&work->unk_0C);
    return 1;
}

void task_hum_axcel_ptc_2(AxcelPtcWork* work) {
    s16 x;
    s16 y;

    WorldToScreen(&x, &y, work->unk_24, work->unk_28, work->unk_2C);
    DrawSprite(x, y, work->unk_08, work->unk_00, work->unk_04, 0,
        func_0801AF1C(work->unk_28), -0x1004 - (work->unk_28 >> 8) * 4);
}

void task_hum_axcel_ptc_3(AxcelPtcWork* work) {
    ReleaseObjTiles(work->unk_00);
    ReleaseObjPalette(work->unk_04);
}

#ifdef NON_MATCHING
void func_08054334(VixenWork* work) {
    VixenSub* p;
    s32 i;

    m4aSongNumStart(0x287);
    p = work->unk_1C4;
    for (i = 0; i < 3; i++) {
        p[i].unk_00 = p[i].unk_01 = 1;
        p[i].unk_04 = (gUnk_02039B84->unk_0DA +
            GetRandom() % (gUnk_02039B84->unk_0DC - gUnk_02039B84->unk_0DA - 0x3F) + 32) << 8;
        p[i].unk_08 = (gUnk_02039B84->unk_0DE +
            GetRandom() % (gUnk_02039B84->unk_0E0 - gUnk_02039B84->unk_0DE - 0x1F) + 16) << 8;
    }
}
#else
INCLUDE_ASM("hum/func_08054334.s");
#endif
#ifdef NON_MATCHING
void func_080543B4(VixenWork* work) {
    VixenSub* p;
    s32 i;

    p = work->unk_1C4;
    for (i = 0; i < 3; i++) {
        p->unk_00 = p->unk_01 = 0;
        TaskCreate(&work->unk_1A4, gUnk_09EDB6E0, &work->unk_1C4[i]);
        p++;
    }
}
#else
INCLUDE_ASM("hum/func_080543B4.s");
#endif

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
    if (gUnk_02039BB0.unk_008 & 8) {
        gUnk_02039B84->unk_114 = AllocObjTiles(0x840, 0);
    }
}

INCLUDE_ASM("hum/task_hum_vixen_1.s");

void task_hum_vixen_2(VixenWork* work) {
    func_0800EFE8(&work->base);
    TaskPoolDraw(&work->unk_1A4);
}

void task_hum_vixen_3(VixenWork* work) {
    if (gUnk_02039BB0.unk_008 & 8) {
        ReleaseObjTiles(gUnk_02039B84->unk_114);
    }
    func_0800E380(&work->base);
    TaskPoolDestroy(&work->unk_1A4);
}

void task_hum_vixen_ndl_0(VixenNdlWork* work, VixenNdlArgs* args) {
    work->unk_04 = LoadObjPalette(gUnk_08F6DCA4, 0x20);
    work->unk_00 = args->unk_18;
    AnimInit(&work->unk_08, gUnk_09EE26B0, gUnk_09EE2690);
    AnimStart(&work->unk_08, 0, 0);
    work->unk_2C = args->unk_12;
    work->unk_20 = args->unk_00;
    work->unk_24 = args->unk_04 + (GetRandom() % 11 - 5) * 256;
    work->unk_28 = args->unk_08;
    work->unk_2D = 0;
    m4aSongNumStart(0x286);
    if ((GetRandom() & 1) != 0) {
        work->unk_2E = 1;
    } else {
        work->unk_2E = 0;
    }
}

u8 task_hum_vixen_ndl_1(VixenNdlWork* work) {
    if ((gUnk_02039B84->unk_068 & 0x40) == 0) {
        return 0;
    }
    if (AnimIsFinished(&work->unk_08)) {
        return 0;
    }
    switch (func_08005B34(&work->unk_08)) {
    case 1:
    case 2:
        if (work->unk_2D == 0) {
            if (gFrameCounter % 8 == work->unk_2C) {
                func_08011F78(0x13A, work->unk_20, work->unk_24, 0, 4, 4, 16);
            }
        }
        break;
    }
    if (gUnk_02039B84->unk_07C->unk_34 & 0x2000) {
        work->unk_2D = 1;
    }
    AnimUpdate(&work->unk_08);
    return 1;
}

void task_hum_vixen_ndl_2(VixenNdlWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 attr;

    gfx = AnimGetGfx(&work->unk_08);
    attr = func_0801AF1C(work->unk_24);
    if (work->unk_2E != 0) {
        attr |= 1;
    }
    WorldToScreen(&x, &y, work->unk_20, work->unk_24, work->unk_28);
    DrawSprite(x, y, gfx, work->unk_00, work->unk_04, 0, attr,
        -0x1004 - (work->unk_24 >> 8) * 4);
}

void task_hum_vixen_ndl_3(VixenNdlWork* work) {
    ReleaseObjPalette(work->unk_04);
}

void task_hum_vixen_ice_0(VixenIceWork* work, VixenSub* args) {
    work->unk_08 = LoadObjPalette(gUnk_08F6DCA4, 0x20);
    work->unk_04 = LoadObjTiles(gUnk_08EE4264, 0x800);
    work->unk_24 = args;
    work->unk_00 = 3;
    AnimInit(&work->unk_0C, gUnk_09EE26CC, gUnk_09EE26B4);
    AnimStart(&work->unk_0C, 0, 0);
    func_080122AC(&work->unk_28, 12, 27, 1);
    func_08012614(&work->unk_28, 1);
}

INCLUDE_ASM("hum/task_hum_vixen_ice_1.s");

void task_hum_vixen_ice_2(VixenIceWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    s32 s;
    s32 affine;

    if (work->unk_24->unk_01 != 0) {
        gfx = AnimGetGfx(&work->unk_0C);
        WorldToScreen(&x, &y, work->unk_24->unk_04, work->unk_24->unk_08, 0);
        s = work->unk_8C * gUnk_02039B84->unk_024 >> 8;
        if (gUnk_02039B84->unk_018 != 0 || s > 0x100) {
            affine = AllocObjAffine(gUnk_02039B84->unk_018, s, s, 1);
        } else {
            affine = AllocObjAffine(gUnk_02039B84->unk_018, s, s, 0);
        }
        DrawSprite(x, y, gfx, work->unk_04, work->unk_08, affine, 0x800, 0xFFFF);
    }
}

void task_hum_vixen_ice_3(VixenIceWork* work) {
    ReleaseObjTiles(work->unk_04);
    ReleaseObjPalette(work->unk_08);
    func_08012304(&work->unk_28);
}

void task_hum_vixen_frz_0(VixenFrzWork* work, VixenNdlArgs* args) {
    work->unk_04 = LoadObjPalette(gUnk_08F6DCA4, 0x20);
    work->unk_00 = gUnk_02039B84->unk_114;
    if (gUnk_02039BB0.unk_008 & 8) {
        if (gUnk_02039B84->unk_068 & 0x800000000000) {
            work->unk_32 = 2;
        } else {
            work->unk_32 = 1;
        }
    } else {
        work->unk_32 = 0;
    }
    AnimInit(&work->unk_08, 0, 0);
    func_08019068(gUnk_0813F91C, &work->unk_08, 0, 0, work->unk_00);
    work->unk_2C = 0;
    if (gUnk_02039B84->unk_07C->unk_34 & 4) {
        work->unk_34 = 0;
    } else {
        work->unk_34 = 1;
    }
    m4aSongNumStart(0x1FE);
    work->unk_20 = args->unk_00;
    work->unk_24 = args->unk_04;
    work->unk_28 = args->unk_08;
}

INCLUDE_ASM("hum/task_hum_vixen_frz_1.s");

void task_hum_vixen_frz_2(VixenFrzWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 attr;

    if (work->unk_2C != 6) {
        gfx = AnimGetGfx(&work->unk_08);
        attr = func_0801AF1C(work->unk_24) | work->unk_34;
        WorldToScreen(&x, &y, work->unk_20, work->unk_24, work->unk_28);
        DrawSprite(x, y, gfx, work->unk_00, work->unk_04, 0, attr,
            -0x1004 - (work->unk_24 >> 8) * 4);
    }
}

void task_hum_vixen_frz_3(VixenFrzWork* work) {
    ReleaseObjPalette(work->unk_04);
}

INCLUDE_ASM("hum/task_hum_vixen_frg_0.s");
INCLUDE_ASM("hum/task_hum_vixen_frg_1.s");

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
        DrawSprite(x, y, p[i].unk_00, work->unk_30, work->unk_34, 0, attr,
            -0x1004 - (p[i].unk_08 >> 8) * 4);
    }
}

void task_hum_vixen_frg_3(VixenFrgWork* work) {
    ReleaseObjPalette(work->unk_34);
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
        func_080058FC(&work->base.unk_168, work->unk_1D0, work->unk_1CC);
        func_080058FC(&work->base.unk_16C, work->unk_1D4, work->unk_1CC);
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
    AnimInit(&work->unk_08, gUnk_09EE22B0, gUnk_09EE2298);
    AnimStart(&work->unk_08, 0, 1);
    if (args->unk_12 != 0) {
        work->unk_2C = 1;
    } else {
        work->unk_2C = 0;
    }
    work->unk_20 = args->unk_00;
    work->unk_24 = args->unk_04;
    work->unk_28 = args->unk_08;
    work->unk_34 = gUnk_02039B84->unk_130 + (GetRandom() % 65 - 32) * 256;
    work->unk_38 = gUnk_02039B84->unk_134 + (GetRandom() % 33 - 16) * 256;
    work->unk_30 = 0;
    work->unk_4A = 0;
    work->unk_2D = 0;
    work->unk_3C = -0x980;
    work->unk_40 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    work->unk_44 = LoadObjPalette(gUnk_08F69BA4, 0x20);
    m4aSongNumStart(0x2B1);
}

INCLUDE_ASM("hum/task_hum_lex_tmh_1.s");

void task_hum_lex_tmh_2(LexTmhWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 attr;
    s32 affine;
    s32 scale;

    gfx = AnimGetGfx(&work->unk_08);
    if (work->unk_2C != 0) {
        attr = func_0801AF1C(work->unk_24);
    } else {
        attr = func_0801AF1C(work->unk_24) | 1;
    }
    WorldToScreen(&x, &y, work->unk_20, work->unk_24, work->unk_28);
    DrawSprite(x, y, gfx, work->unk_00, work->unk_04, 0, attr,
        -0x1004 - (work->unk_24 >> 8) * 4);
    if (work->unk_28 >= 0) {
        affine = 0;
    } else {
        scale = 0x100 - (-work->unk_28) / 256;
        if (scale <= 75) {
            scale = 76;
        }
        affine = AllocObjAffine(0, scale, scale, 0);
    }
    WorldToScreen(&x, &y, work->unk_20, work->unk_24, 0);
    DrawSprite(x, y, gUnk_08B22BA8, work->unk_40, work->unk_44, affine, attr, 0xFFF0);
}

void task_hum_lex_tmh_3(LexTmhWork* work) {
    ReleaseObjTiles(work->unk_40);
    ReleaseObjPalette(work->unk_44);
    ReleaseObjTiles(work->unk_00);
    ReleaseObjPalette(work->unk_04);
}

void task_hum_lex_tmh0_0(LexTmh0Work* work, VixenNdlArgs* args) {
    work->unk_04 = LoadObjPalette(gUnk_09618478, 0x20);
    work->unk_00 = AllocObjTiles(0x400, gUnk_08C3151E);
    AnimInit(&work->unk_08, gUnk_09EE2288, gUnk_09EE2250);
    AnimStart(&work->unk_08, 2, 1);
    if (args->unk_12 != 0) {
        work->unk_2C = 1;
    } else {
        work->unk_2C = 0;
    }
    work->unk_20 = args->unk_00;
    work->unk_24 = args->unk_04;
    work->unk_28 = args->unk_08;
    work->unk_30 = 10;
    work->unk_34 = 21;
    m4aSongNumStart(0x2B4);
}

u8 task_hum_lex_tmh0_1(LexTmh0Work* work) {
    if (gUnk_02039B84->unk_068 & 0x40) {
        func_080058FC(&work->unk_30, 0x100, work->unk_34--);
        if (work->unk_34 > 0) {
            AnimUpdate(&work->unk_08);
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("hum/task_hum_lex_tmh0_2.s");

void task_hum_lex_tmh0_3(LexTmh0Work* work) {
    ReleaseObjTiles(work->unk_00);
    ReleaseObjPalette(work->unk_04);
}

INCLUDE_ASM("hum/task_hum_lex_rock_0.s");
INCLUDE_ASM("hum/task_hum_lex_rock_1.s");
INCLUDE_ASM("hum/task_hum_lex_rock_2.s");

void task_hum_lex_rock_3(LexRockWork* work) {
    s32 i;

    ReleaseObjTiles(work->unk_2B8);
    ReleaseObjPalette(work->unk_2BC);
    if (work->unk_164 != 0) {
        ReleaseObjPalette(work->unk_30);
        for (i = 0; i < work->unk_164; i++) {
            ReleaseObjTiles(work->unk_00[i]);
        }
    }
}

void task_hum_mahluxia_flw_0(MahluxiaFlwWork* work, VixenNdlArgs* args) {
    work->unk_08 = LoadObjPalette(gUnk_08F6DC84, 0x20);
    work->unk_04 = LoadObjTiles(gUnk_08BCB3D8, 0x100);
    work->unk_00 = 0;
    work->unk_30 = args->unk_00;
    work->unk_34 = args->unk_04;
    work->unk_38 = args->unk_08;
    work->unk_2C = GetRandom() % 717 - 358;
    work->unk_28 = -(GetRandom() % 539 + 102);
    AnimInit(&work->unk_0C, gUnk_09EE1CB4, gUnk_09EE1C94);
    AnimStart(&work->unk_0C, GetRandom() & 1, 1);
}

u8 task_hum_mahluxia_flw_1(MahluxiaFlwWork* work) {
    switch (work->unk_00) {
    case 0:
        work->unk_30 += work->unk_2C;
        work->unk_38 += work->unk_28;
        work->unk_28 += 17;
        if (work->unk_28 > 0x1CC) {
            work->unk_00 = 1;
        }
        break;
    case 1:
        work->unk_30 += work->unk_2C;
        work->unk_38 += work->unk_28;
        work->unk_28 -= 12;
        if (work->unk_28 < 0) {
            work->unk_28 = GetRandom() % 181 + 204;
            if (work->unk_2C > 0) {
                work->unk_2C = -(GetRandom() % 257 + 128);
            } else {
                work->unk_2C = GetRandom() % 257 + 128;
            }
        }
        if (work->unk_38 >= 0) {
            return 0;
        }
        break;
    }
    AnimUpdate(&work->unk_0C);
    return 1;
}

void task_hum_mahluxia_flw_2(MahluxiaFlwWork* work) {
    s16 x;
    s16 y;
    void* gfx;

    gfx = AnimGetGfx(&work->unk_0C);
    WorldToScreen(&x, &y, work->unk_30, work->unk_34, work->unk_38);
    DrawSprite(x, y, gfx, work->unk_04, work->unk_08, 0, 0x800,
        -0x1004 - (work->unk_34 >> 8) * 4);
}

void task_hum_mahluxia_flw_3(MahluxiaFlwWork* work) {
    ReleaseObjTiles(work->unk_04);
    ReleaseObjPalette(work->unk_08);
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

INCLUDE_ASM("hum/func_08057D68.s");

void func_08057E2C(RikuWork* work, RikuSpawn* dst) {
    HumActor* act = &work->base.unk_040;

    dst->unk_00 = act->unk_04;
    dst->unk_04 = act->unk_08;
    dst->unk_08 = act->unk_0C;
    if (act->unk_34 & 4) {
        dst->unk_0C |= 1;
    } else {
        dst->unk_0C &= 0xFFFE;
    }
    dst->unk_10 = work->base.unk_014;
    dst->unk_28 = *(u32*)work->base.unk_004;
    dst->unk_2C = gUnk_02039B84->unk_024;
}

INCLUDE_ASM("hum/func_08057E90.s");
INCLUDE_ASM("hum/task_hum_riku_0.s");
INCLUDE_ASM("hum/task_hum_riku_1.s");
INCLUDE_ASM("hum/task_hum_riku_2.s");

void task_hum_riku_3(HumWork* work) {
    func_0800E380(work);
}

void task_hum_leon_0(LeonWork* work) {
    func_0800E168(&work->base, gUnk_0813FDA8);
    work->unk_188 = 0;
    work->unk_18A = 0;
    func_08019068(gUnk_0813FD58, &work->base.unk_014, 0, 1, work->base.unk_004);
    work->unk_18C = gUnk_02039BB0.unk_10C;
    work->unk_194 = gUnk_02039BB0.unk_114;
    gUnk_02039BB0.unk_10C = 0;
    gUnk_02039BB0.unk_114 = 0;
}

INCLUDE_ASM("hum/task_hum_leon_1.s");

void task_hum_leon_2(HumWork* work) {
    func_0800EFE8(work);
}

void task_hum_leon_3(LeonWork* work) {
    gUnk_02039BB0.unk_10C = work->unk_18C;
    gUnk_02039BB0.unk_114 = work->unk_194;
    func_0800E380(&work->base);
}

void task_hum_robe_0(RobeWork* work) {
    func_0800E168(&work->base, gUnk_0813FDF4);
    work->unk_188 = 1;
    func_08019068(gUnk_0813FDD4, &work->base.unk_014, 0, 1, work->base.unk_004);
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
    if (gUnk_02039B84->unk_068 & 0x20000000) {
        if (work->unk_188 == 1) {
            func_08019068(gUnk_0813FDD4, &work->base.unk_014, 1, 0, work->base.unk_004);
            work->unk_188 = 0;
        }
    } else if (AnimIsFinished(&work->base.unk_014)) {
        func_08019068(gUnk_0813FDD4, &work->base.unk_014, 0, 1, work->base.unk_004);
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

INCLUDE_ASM("hum/MakeSaveHeaderData.s");
INCLUDE_ASM("hum/MakeSaveSystem.s");
INCLUDE_ASM("hum/MakeSaveFileLarge.s");
INCLUDE_ASM("hum/MakeSaveFileSmall.s");
INCLUDE_ASM("hum/ApplySaveHeaderData.s");
INCLUDE_ASM("hum/ApplySaveSystem.s");
INCLUDE_ASM("hum/ApplySaveFileLarge.s");
INCLUDE_ASM("hum/ApplySaveFileSmall.s");
INCLUDE_ASM("hum/func_0805A484.s");
INCLUDE_ASM("hum/func_0805A4D8.s");

#ifndef VERSION_JP
u16 func_0805A55C(u16* p) {
    s32 n;
    u16* q;

    n = 0;
    q = p;
    while (1) {
        if (*q == 0) {
            return n;
        }
        q++;
        n++;
    }
}
#else
INCLUDE_ASM("hum/func_0805A55C.s");
#endif

INCLUDE_ASM("hum/func_0805A574.s");
INCLUDE_ASM("hum/func_0805A638.s");
INCLUDE_ASM("hum/func_0805A698.s");
INCLUDE_ASM("hum/func_0805A7D0.s");
INCLUDE_ASM("hum/func_0805A8D0.s");
INCLUDE_ASM("hum/func_0805A95C.s");
INCLUDE_ASM("hum/func_0805AA9C.s");
