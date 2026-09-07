#include "macros.h"
#include "wlogo.h"

static TaskPool gWlogoHwtTaskPool;
static u8 gUnk_02034C4C[4];
static TaskPool gWlogoNvlTaskPool;
static u8 gUnk_02034C64[4];
static TaskPool gWlogoNvlMovTaskPool;
static u8 gUnk_02034C7C[4];
static TaskPool gWlogoAgrTaskPool;
static u8 gUnk_02034C94[4];
static TaskPool gWlogoPooTaskPool;
static u8 gUnk_02034CAC[4];
static Task* gBosTmBodyTask;
static Task* gBosTmArmTask;
static Task* gBosTmFootTask;
static Task* gBosTmTblTask;
static TaskPool gBosTmTaskPool;

s32 gUnk_0203AB38;

void task_wlogo_mons_0(WlogoMonsWork* work) {
    LoadBgPalette(0, gUnk_096FACA4, 0x20);
    LoadBgTiles(0, gUnk_096324C4, 0xC80);
    LoadBgMap(0, gUnk_096B6C64, 0x800);
    work->tiles = LoadObjTiles(gUnk_0961AA92, 0x500);
    work->palette = LoadObjPalette(gUnk_096FACA4, 0x20);
    work->x = 64;
    work->y = 64;
    work->unk_028 = 0;
    work->unk_02A = 0;
    work->unk_02C = 0;
    work->unk_02D = 0;
    work->unk_02E = 0;
    SetBgBlend(0, 16, 0);
    AnimInit(&work->anim, gUnk_09EF3544, gUnk_09EF351C);
    AnimStart(&work->anim, 0, 0);
    work->gfx = AnimGetGfx(&work->anim);
}

u8 task_wlogo_mons_1(WlogoMonsWork* work) {
    switch (work->unk_02C) {
    case 0:
        work->unk_02A++;
        if (work->unk_02A > 29) {
            work->unk_02A = 0;
            work->unk_02C++;
        }
        break;
    case 1:
        work->unk_02A++;
        if (work->unk_02A > 4) {
            work->unk_02A = 0;
            work->unk_02E++;
            if (work->unk_02E > 15) {
                work->unk_02E = 16;
                work->unk_02C++;
            }
            SetBgBlend(0, 16 - work->unk_02E, work->unk_02E);
        }
        break;
    case 2:
        work->unk_02A++;
        if (work->unk_02A > 29) {
            work->unk_02A = 0;
            work->unk_02D = 1;
            work->unk_02C++;
        }
        break;
    case 3:
        if (!AnimIsFinished(&work->anim)) {
            work->gfx = AnimUpdate(&work->anim);
        }
        work->unk_02A++;
        if (work->unk_02A > 7) {
            work->unk_02A = 0;

            if (work->unk_028 <= 4) {
                LoadObjPaletteBank(work->palette->unk_06, &gUnk_096FACC4[work->unk_028 * 32]);
                LoadPaletteWithEffect(&gUnk_096FACC4[work->unk_028 * 32], (void*)0x050001C0, 0x20);
            } else if (work->unk_028 > 11) {
                if (work->unk_028 <= 15) {
                    LoadObjPaletteBank(work->palette->unk_06, &gUnk_096FACC4[(15 - work->unk_028) * 32]);
                    LoadPaletteWithEffect(&gUnk_096FACC4[(15 - work->unk_028) * 32], (void*)0x050001C0, 0x20);
                } else if (work->unk_028 == 20) {
                    work->unk_02D = 0;
                    RequestDma3Copy(gUnk_096B7464, GetBgScreenBase(0), 0x800);
                    work->unk_02C++;
                }
            }
            work->unk_028++;
        }
        break;
    case 4:
        work->unk_02A++;
        if (work->unk_02A > 49) {
            work->unk_02A = 0;
            work->unk_02C++;
        }
        break;
    case 5:
        work->unk_02A++;
        if (work->unk_02A > 4) {
            work->unk_02A = 0;
            work->unk_02E--;
            if (work->unk_02E == 0) {
                work->unk_02E = 0;
                SetBgBlend(0, 16, 0);
                DisableBg(0);
                return 0;
            }
            SetBgBlend(0, 16 - work->unk_02E, work->unk_02E);
        }
        break;
    }
    return 1;
}

void task_wlogo_mons_2(WlogoMonsWork* work) {
    if (work->unk_02D == 1) {
        DrawSprite(work->x, work->y, work->gfx, work->tiles, work->palette, 0, 0, 0);
    }
}

void task_wlogo_mons_3(WlogoMonsWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_wlogo_hwt_0(WlogoHwtWork* work) {
    LoadBgPalette(0, gUnk_096FAD64, 0x20);
    LoadBgTiles(0, gUnk_09633144, 0xC20);
    LoadBgMap(0, gUnk_096B7C64, 0x800);
    work->unk_000 = 0;
    work->unk_002 = 0;
    work->unk_004 = 0;
    work->unk_005 = 0;
    SetBgBlend(0, 16, 0);
    TaskPoolInit(&gWlogoHwtTaskPool, 4);
}

u8 task_wlogo_hwt_1(WlogoHwtWork* work) {
    switch (work->unk_004) {
    case 0:
        work->unk_002++;
        if (work->unk_002 == 20) {
            TaskCreate(&gWlogoHwtTaskPool, &gTaskDescWlogoHwtObj, (void*)0);
            TaskCreate(&gWlogoHwtTaskPool, &gTaskDescWlogoHwtObj, (void*)1);
        }

        if (work->unk_002 == 100) {
            TaskCreate(&gWlogoHwtTaskPool, &gTaskDescWlogoHwtObj, (void*)2);
        }

        if (work->unk_002 == 140) {
            work->unk_002 = 0;
            TaskCreate(&gWlogoHwtTaskPool, &gTaskDescWlogoHwtObj, (void*)3);
            work->unk_004++;
        }
        break;
    case 1:
        work->unk_002++;
        if (work->unk_002 > 4) {
            work->unk_002 = 0;
            work->unk_005++;
            if (work->unk_005 > 15) {
                work->unk_005 = 16;
                work->unk_004++;
            }
            SetBgBlend(0, 16 - work->unk_005, work->unk_005);
        }
        break;
    case 2:
        work->unk_002++;
        if (work->unk_002 > 119) {
            work->unk_002 = 0;
            work->unk_004++;
        }
        break;
    case 3:
        work->unk_002++;
        if (work->unk_002 > 4) {
            work->unk_002 = 0;
            work->unk_005--;
            if (work->unk_005 == 0) {
                work->unk_005 = 0;
                SetBgBlend(0, 16, 0);
                DisableBg(0);
                work->unk_004++;
            }
            SetBgBlend(0, 16 - work->unk_005, work->unk_005);
        }

        if (work->unk_002 == 0) {
            if (work->unk_005 == 15) {
                TaskCreate(&gWlogoHwtTaskPool, &gTaskDescWlogoHwtObj, (void*)4);
            }

            if (work->unk_005 == 12) {
                TaskCreate(&gWlogoHwtTaskPool, &gTaskDescWlogoHwtObj, (void*)5);
            }
        }
        break;
    case 4:
        work->unk_002++;
        if (work->unk_002 > 29) {
            work->unk_002 = 0;
            return 0;
        }
        break;
    }
    TaskPoolUpdate(&gWlogoHwtTaskPool);
    TaskPoolDraw(&gWlogoHwtTaskPool);
    return 1;
}

void task_wlogo_hwt_2(WlogoHwtWork* work) {
}

void task_wlogo_hwt_3(WlogoHwtWork* work) {
    TaskPoolDestroy(&gWlogoHwtTaskPool);
}

void task_wlogo_hwt_obj_0(WlogoHwtObjWork* work, s32 arg) {
    work->unk_04A = arg;
    work->tiles = LoadObjTiles(gUnk_0961B072, 0xF20);
    work->palette = LoadObjPalette(gUnk_096FAD64, 0x20);
    AnimInit(&work->anim, gUnk_09EF356C, gUnk_09EF3548);
    AnimStart(&work->anim, gUnk_096194D0[work->unk_04A].unk_0C, 1);
    work->gfx = AnimGetGfx(&work->anim);
    work->x = gUnk_096194D0[work->unk_04A].x;
    work->y = gUnk_096194D0[work->unk_04A].y;
    work->unk_02C = gUnk_09619530[work->unk_04A][0].unk_04;
    work->unk_030 = gUnk_09619530[work->unk_04A][0].unk_08;
    work->unk_034 = gUnk_09619530[work->unk_04A][0].unk_0C;
    work->unk_038 = gUnk_09619530[work->unk_04A][0].unk_10;
    work->unk_044 = gUnk_096194D0[work->unk_04A].unk_08;
    work->unk_03C = 0;
    work->unk_03E = 0;
    work->unk_040 = 0;
}

u8 task_wlogo_hwt_obj_1(WlogoHwtObjWork* work) {
    work->x += work->unk_02C;
    work->y += work->unk_030;
    work->unk_02C += work->unk_034;
    work->unk_030 += work->unk_038;

    if (++work->unk_03E >= gUnk_09619530[work->unk_04A][work->unk_03C].unk_00) {
        work->unk_03E = 0;

        if (gUnk_09619530[work->unk_04A][work->unk_03C].unk_14 == 1) {
            return 0;
        }
        work->unk_03C++;
        work->unk_02C = gUnk_09619530[work->unk_04A][work->unk_03C].unk_04;
        work->unk_030 = gUnk_09619530[work->unk_04A][work->unk_03C].unk_08;
        work->unk_034 = gUnk_09619530[work->unk_04A][work->unk_03C].unk_0C;
        work->unk_038 = gUnk_09619530[work->unk_04A][work->unk_03C].unk_10;
    }
    work->gfx = AnimUpdate(&work->anim);
    return 1;
}

void task_wlogo_hwt_obj_2(WlogoHwtObjWork* work) {
    DrawSprite(work->x >> 8, work->y >> 8, work->gfx, work->tiles, work->palette, 0, 0x400, 0);
}

void task_wlogo_hwt_obj_3(WlogoHwtObjWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_wlogo_won_0(WlogoWonWork* work) {
    s32 i;

    LoadBgPalette(0, gUnk_096FAC84, 0x20);
    LoadBgTiles(0, gUnk_096300C4, 0xC00);
    LoadBgMap(0, gUnk_096B6464, 0x800);
    work->tiles = LoadObjTiles(gUnk_09630CC4, 0x1800);
    work->palette = LoadObjPalette(gUnk_096FAC84, 0x20);

    for (i = 0; i < 10; i++) {
        work->unk_084[i] = gUnk_09EF3924[i];
        work->x[i] = gUnk_09EF1744[i].unk_00;
        work->y[i] = gUnk_09EF1744[i].unk_04;
        work->unk_05C[i] = gUnk_09EF1744[i].unk_08;
        work->unk_0CA[i] = gUnk_09EF1744[i].unk_12;
        work->unk_0DE[i] = 0;
        work->unk_0AC[i] = 0;
        work->unk_0C0[i] = 0;
    }
    work->unk_008 = 0;
    work->unk_00A = 0;
    work->unk_0F2 = 0;
    work->unk_0F3 = 0;
    SetBgBlend(0, 16, 0);
}

#ifdef NON_MATCHING
u8 task_wlogo_won_1(WlogoWonWork* work) {
    s32 i;

    switch (work->unk_0F2) {
    case 0:
        work->unk_008++;
        if (work->unk_008 > 9) {
            work->unk_008 = 0;
            work->unk_0F2++;
        }
        break;
    case 1:
        for (i = 0; i < 10; i++) {
            if (work->unk_0C0[i] == 0) {
                if (work->unk_0AC[i] > gUnk_09EF1744[i].unk_0C) {
                    work->unk_0C0[i]++;
                    work->unk_0AC[i] = 0;
                }
            } else if (work->unk_0AC[i] > gUnk_09EF1744[i].unk_0E) {
                work->unk_0C0[i]++;
            } else {
                work->x[i] -= work->unk_05C[i];

                if (++work->unk_0DE[i] > 1) {
                    work->unk_0DE[i] = 0;

                    if (++work->unk_0CA[i] > 19) {
                        work->unk_0CA[i] = 0;
                    }
                }
            }
            work->unk_0AC[i]++;
        }
        work->unk_008++;
        if (work->unk_008 > 229) {
            work->unk_008 = 0;
            work->unk_0F3 = 16;
            SetBgBlend(0, 0, 16);
            work->unk_0F2++;
        }
        break;
    case 2:
        work->unk_008++;
        if (work->unk_008 > 4) {
            work->unk_008 = 0;
            work->unk_0F3--;
            if (work->unk_0F3 == 0) {
                work->unk_0F3 = 0;
                SetBgBlend(0, 16, 0);
                DisableBg(0);
                return 0;
            }
            SetBgBlend(0, 16 - work->unk_0F3, work->unk_0F3);
        }
        break;
    }
    return 1;
}
#else
INCLUDE_ASM("wlogo/task_wlogo_won_1.s");
#endif

void task_wlogo_won_2(WlogoWonWork* work) {
    s32 i;
    s32 affine;

    if (work->unk_0F2 == 1) {
        for (i = 0; i < 10; i++) {
            affine = AllocObjAffine(work->unk_00A, gUnk_09EF180C[work->unk_0CA[i]], 0x100, 0);
            DrawSprite(work->x[i] >> 8, work->y[i] >> 8, work->unk_084[i], work->tiles, work->palette, affine, 0, gUnk_09EF167C[i].unk_10);
        }
    }
}

void task_wlogo_won_3(WlogoWonWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_wlogo_atl_0(WlogoAtlWork* work) {
    LoadBgPalette(0, gUnk_096FAD84, 0x20);
    LoadBgTiles(0, gUnk_09633D64, 0x900);
    LoadBgMap(0, gUnk_096B8464, 0x800);
    RequestDma3Copy(gUnk_09634664, (u8*)GetBgCharBase(0) + 32, 0x360);
    work->unk_002 = 0;
    work->unk_000 = 0;
    work->unk_008 = 0;
    work->unk_004 = 0;
    work->unk_006 = 0;
    work->unk_009 = 4;
    work->unk_00A = 0;
    SetBgBlend(0, 16, 0);
    StartBgWave(func_080B5444);
    SetBgWaveParams(0, work->unk_009, 4);
}

u8 task_wlogo_atl_1(WlogoAtlWork* work) {
    switch (work->unk_000) {
    case 0:
        work->unk_002++;
        if (work->unk_002 > 29) {
            work->unk_002 = 0;
            EnableBgWave(0);
            work->unk_000++;
        }
        break;
    case 1:
        work->unk_00A++;
        if (work->unk_00A > 39) {
            work->unk_00A = 0;
            work->unk_009--;
            if (work->unk_009 <= 1) {
                work->unk_009 = 1;
            }
            SetBgWaveParams(0, work->unk_009, 4);
        }
        work->unk_002++;
        if (work->unk_002 > 7) {
            work->unk_002 = 0;
            work->unk_008++;
            if (work->unk_008 > 15) {
                work->unk_008 = 16;
                StopBgWave(0);
                work->unk_000++;
            }
            SetBgBlend(0, 16 - work->unk_008, work->unk_008);
        }
        break;
    case 2:
        work->unk_002++;
        if (work->unk_002 > 113) {
            work->unk_002 = 0;
            work->unk_000++;
        }
        work->unk_006++;
        break;
    case 3:
        work->unk_002++;
        if (work->unk_002 > 4) {
            work->unk_002 = 0;
            work->unk_008--;
            if (work->unk_008 == 0) {
                work->unk_008 = 0;
                SetBgBlend(0, 16, 0);
                DisableBg(0);
                return 0;
            }
            SetBgBlend(0, 16 - work->unk_008, work->unk_008);
        }
        work->unk_006++;
        break;
    }

    if (work->unk_006 > 9) {
        work->unk_006 = 0;
        work->unk_004++;
        if (work->unk_004 > 14) {
            work->unk_004 = 15;
        }
        RequestDma3Copy(&gUnk_09634664[work->unk_004 * 1024], (u8*)GetBgCharBase(0) + 32, 0x360);
    }
    return 1;
}

void task_wlogo_atl_2(WlogoAtlWork* work) {
}

void task_wlogo_atl_3(WlogoAtlWork* work) {
    StopBgWave(0);
}

void func_080B5444(void) {
    gIntrCheck |= 2;
    HBlankIntrBgWave1(0);
}

void task_wlogo_nvl_0(WlogoNvlWork* work) {
    LoadBgPalette(0, gUnk_096FADA4, 0x20);
    LoadBgTiles(0, gUnk_09638664, 0x620);
    LoadBgMap(0, gUnk_096B8C64, 0x800);
    RequestDma3Copy(gUnk_09638C84, GetBgCharBase(0), 0x340);
    work->unk_002 = 0;
    work->unk_000 = 0;
    work->unk_00A = 0;
    work->unk_004 = 0;
    work->unk_006 = 0;
    work->unk_008 = 0;
    SetBgBlend(0, 16, 0);
    TaskPoolInit(&gWlogoNvlTaskPool, 4);
}

u8 task_wlogo_nvl_1(WlogoNvlWork* work) {
    switch (work->unk_000) {
    case 0:
        work->unk_002++;
        if (work->unk_002 > 29) {
            work->unk_002 = 0;
            work->unk_000++;
        }
        break;
    case 1:
        work->unk_002++;
        if (work->unk_002 > 5) {
            work->unk_002 = 0;
            work->unk_00A++;
            if (work->unk_00A > 15) {
                work->unk_00A = 16;
                work->unk_000++;
            }
            SetBgBlend(0, 16 - work->unk_00A, work->unk_00A);
        }
        break;
    case 2:
        work->unk_002++;
        if (work->unk_002 > 113) {
            work->unk_002 = 0;
            work->unk_000++;
        }

        if (work->unk_002 == 1) {
            TaskCreate(&gWlogoNvlTaskPool, &gTaskDescWlogoNvlMov, (void*)0);
        }
        break;
    case 3:
        work->unk_002++;
        if (work->unk_002 > 4) {
            work->unk_002 = 0;
            work->unk_00A--;
            if (work->unk_00A == 0) {
                work->unk_00A = 0;
                SetBgBlend(0, 16, 0);
                DisableBg(0);
                return 0;
            }
            SetBgBlend(0, 16 - work->unk_00A, work->unk_00A);
        }
        break;
    }

    if (work->unk_008 >= 50 && work->unk_008 <= 124) {
        work->unk_006++;
        if (work->unk_006 > 14) {
            work->unk_006 = 0;
            work->unk_004++;
            if (work->unk_004 > 4) {
                work->unk_004 = 5;
            }
            RequestDma3Copy(&gUnk_09638C84[work->unk_004 * 1024], GetBgCharBase(0), 0x340);
        }
    } else if (work->unk_008 >= 135 && work->unk_008 <= 209) {
        work->unk_006++;
        if (work->unk_006 > 14) {
            work->unk_006 = 0;
            work->unk_004--;
            if (work->unk_004 <= 0) {
                work->unk_004 = 0;
            }
            RequestDma3Copy(&gUnk_09638C84[work->unk_004 * 1024], GetBgCharBase(0), 0x340);
        }
    }
    work->unk_008++;
    TaskPoolUpdate(&gWlogoNvlTaskPool);
    TaskPoolDraw(&gWlogoNvlTaskPool);
    return 1;
}

void task_wlogo_nvl_2(WlogoNvlWork* work) {
}

void task_wlogo_nvl_3(WlogoNvlWork* work) {
    TaskPoolDestroy(&gWlogoNvlTaskPool);
}

void task_wlogo_nvl_mov_0(WlogoNvlMovWork* work) {
    work->unk_01A = 0;
    work->unk_01C = 0;
    work->x = 0x4E00;
    work->y = 0x5D00;
    work->unk_008 = gUnk_096198D4[0].unk_04;
    work->unk_00C = gUnk_096198D4[0].unk_08;
    work->unk_010 = gUnk_096198D4[0].unk_0C;
    work->unk_014 = gUnk_096198D4[0].unk_10;
    work->unk_01E = 0;
    work->unk_020 = 1;
    work->unk_018 = 0;
    work->unk_049 = 1;
    work->tiles = LoadObjTiles(gUnk_0961C062, 0x600);
    work->palette = LoadObjPalette(gUnk_096FADA4, 0x20);
    work->unk_048 = 3;
    AnimInit(&work->anim, gUnk_09EF35A4, gUnk_09EF3574);
    AnimStart(&work->anim, work->unk_048, 0);
    work->gfx = AnimGetGfx(&work->anim);
    TaskPoolInit(&gWlogoNvlMovTaskPool, 10);
}

u8 task_wlogo_nvl_mov_1(WlogoNvlMovWork* work) {
    WlogoNvlObjArg arg;

    if (work->unk_018 == 0) {
        work->x += work->unk_008;
        work->y += work->unk_00C;
        work->unk_008 += work->unk_010;
        work->unk_00C += work->unk_014;

        if (++work->unk_01A >= gUnk_096198D4[work->unk_01C].unk_00) {
            work->unk_01A = 0;

            if (gUnk_096198D4[work->unk_01C].unk_14 == 1) {
                work->unk_049 = 0;
                work->unk_018++;
            }
            work->unk_01C++;
            work->unk_008 = gUnk_096198D4[work->unk_01C].unk_04;
            work->unk_00C = gUnk_096198D4[work->unk_01C].unk_08;
            work->unk_010 = gUnk_096198D4[work->unk_01C].unk_0C;
            work->unk_014 = gUnk_096198D4[work->unk_01C].unk_10;
        }

        if (work->unk_01E % 5 == 0) {
            arg.unk_00 = work->x;
            arg.unk_04 = work->y;
            arg.unk_08 = work->unk_020;
            TaskCreate(&gWlogoNvlMovTaskPool, &gTaskDescWlogoNvlObj, &arg);
            work->unk_020 = 1 - work->unk_020;
        }
        work->gfx = AnimUpdate(&work->anim);

        if (work->unk_01E == 40) {
            func_08005974(&work->anim, 2, 0, gUnk_09EF35A4, gUnk_09EF3574);
        }

        if (work->unk_01E == 55) {
            func_08005974(&work->anim, 4, 0, gUnk_09EF35A4, gUnk_09EF3574);
        }

        if (work->unk_01E == 75) {
            func_08005974(&work->anim, 2, 0, gUnk_09EF35A4, gUnk_09EF3574);
        }
        work->unk_01E++;
    } else {
        work->unk_01A++;
        if (work->unk_01A > 40) {
            return 0;
        }
    }
    TaskPoolUpdate(&gWlogoNvlMovTaskPool);
    TaskPoolDraw(&gWlogoNvlMovTaskPool);
    return 1;
}

void task_wlogo_nvl_mov_2(WlogoNvlMovWork* work) {
    if (work->unk_049 == 1) {
        DrawSprite(work->x >> 8, work->y >> 8, work->gfx, work->tiles, work->palette, 0, 0, 0);
    }
}

void task_wlogo_nvl_mov_3(WlogoNvlMovWork* work) {
    TaskPoolDestroy(&gWlogoNvlMovTaskPool);
}

void task_wlogo_nvl_obj_0(WlogoNvlObjWork* work, WlogoNvlObjArg* arg) {
    work->x = arg->unk_00;
    work->y = arg->unk_04;
    work->unk_02C = arg->unk_08;
    work->tiles = LoadObjTiles(gUnk_0961C062, 0x600);
    work->palette = LoadObjPalette(gUnk_096FADA4, 0x20);
    AnimInit(&work->anim, gUnk_09EF35A4, gUnk_09EF3574);
    AnimStart(&work->anim, work->unk_02C, 0);
    work->gfx = AnimGetGfx(&work->anim);
}

u8 task_wlogo_nvl_obj_1(WlogoNvlObjWork* work) {
    if (AnimIsFinished(&work->anim)) {
        return 0;
    }
    work->gfx = AnimUpdate(&work->anim);
    return 1;
}

void task_wlogo_nvl_obj_2(WlogoNvlObjWork* work) {
    DrawSprite(work->x >> 8, work->y >> 8, work->gfx, work->tiles, work->palette, 0, 0, 1);
}

void task_wlogo_nvl_obj_3(WlogoNvlObjWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_wlogo_col_0(WlogoColWork* work) {
    LoadBgPalette(0, gUnk_096FADC4, 0x20);
    LoadBgTiles(0, gUnk_0963CC84, 0x1060);
    LoadBgMap(0, gUnk_096B9464, 0x800);
    RequestDma3Copy(gUnk_096424E4, GetBgCharBase(0), 0x620);
    work->tiles = LoadObjTiles(gUnk_0961C7F4, 0x1140);
    work->palette = LoadObjPalette(gUnk_096FADC4, 0x20);
    work->x = gUnk_0961C792[0];
    work->y = gUnk_0961C792[1];
    work->unk_02A = 0;
    work->unk_028 = 0;
    work->unk_030 = 0;
    work->unk_02C = 0;
    work->unk_02E = 0;
    work->unk_031 = 0;
    SetBgBlend(0, 16 - work->unk_030, work->unk_030);
    AnimInit(&work->anim, gUnk_09EF3610, gUnk_09EF35B8);
    AnimStart(&work->anim, 0, 0);
    work->gfx = AnimGetGfx(&work->anim);
}

#ifdef NON_MATCHING
u8 task_wlogo_col_1(WlogoColWork* work) {
    switch (work->unk_028) {
    case 0:
        work->unk_02A++;
        if (work->unk_02A > 9) {
            work->unk_02A = 0;
            work->unk_031 = 1;
            work->unk_028++;
        }
        break;
    case 1:
        if (AnimIsFinished(&work->anim)) {
            work->unk_031 = 0;
            work->unk_028++;
        } else {
            work->gfx = AnimUpdate(&work->anim);
        }
        break;
    case 2:
        work->unk_02A++;
        if (work->unk_02A > 1) {
            work->unk_02A = 0;
            work->unk_030++;
            if (work->unk_030 > 15) {
                work->unk_030 = 16;
                work->unk_028++;
            }
            SetBgBlend(0, 16 - work->unk_030, work->unk_030);
        }
        break;
    case 3:
        work->unk_02A++;
        if (work->unk_02A > 120) {
            work->unk_02A = 0;
            work->unk_028++;
        }
        work->unk_02E++;
        if (work->unk_02E > 4) {
            work->unk_02E = 0;
            work->unk_02C++;
            if (work->unk_02C > 10) {
                work->unk_02C = 11;
            } else {
                RequestDma3Copy(&gUnk_0963DCE4[(work->unk_02C - 1) * 2048], GetBgCharBase(0), 0x620);
            }
        }
        break;
    case 4:
        work->unk_02A++;
        if (work->unk_02A > 4) {
            work->unk_02A = 0;
            work->unk_030--;
            if (work->unk_030 == 0) {
                work->unk_030 = 0;
                SetBgBlend(0, 16, 0);
                DisableBg(0);
                return 0;
            }
            SetBgBlend(0, 16 - work->unk_030, work->unk_030);
        }
        break;
    }
    return 1;
}
#else
INCLUDE_ASM("wlogo/task_wlogo_col_1.s");
#endif

void task_wlogo_col_2(WlogoColWork* work) {
    if (work->unk_031 == 1) {
        DrawSprite(work->x, work->y, work->gfx, work->tiles, work->palette, 0, 0, 0);
    }
}

void task_wlogo_col_3(WlogoColWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_wlogo_hlw_0(WlogoHlwWork* work) {
    LoadBgPalette(0, gUnk_096FAE04, 0x20);
    LoadBgTiles(0, gUnk_096438E4, 0xC00);
    LoadBgMap(0, gUnk_096BAC64, 0x800);
    work->unk_002 = 0;
    work->unk_000 = 0;
    work->unk_004 = 0;
    SetBgBlend(0, 16, 0);
}

u8 task_wlogo_hlw_1(WlogoHlwWork* work) {
    switch (work->unk_000) {
    case 0:
        work->unk_002++;
        if (work->unk_002 > 29) {
            work->unk_002 = 0;
            work->unk_000++;
        }
        break;
    case 1:
        work->unk_002++;
        if (work->unk_002 > 5) {
            work->unk_002 = 0;
            work->unk_004++;
            if (work->unk_004 > 15) {
                work->unk_004 = 16;
                work->unk_000++;
            }
            SetBgBlend(0, 16 - work->unk_004, work->unk_004);
        }
        break;
    case 2:
        work->unk_002++;
        if (work->unk_002 > 113) {
            work->unk_002 = 0;
            work->unk_000++;
        }
        break;
    case 3:
        work->unk_002++;
        if (work->unk_002 > 4) {
            work->unk_002 = 0;
            work->unk_004--;
            if (work->unk_004 == 0) {
                work->unk_004 = 0;
                SetBgBlend(0, 16, 0);
                DisableBg(0);
                return 0;
            }
            SetBgBlend(0, 16 - work->unk_004, work->unk_004);
        }
        break;
    }
    return 1;
}

void task_wlogo_hlw_2(WlogoHlwWork* work) {
}

void task_wlogo_hlw_3(WlogoHlwWork* work) {
}

void task_wlogo_dil_0(WlogoDilWork* work) {
    LoadBgPalette(0, gUnk_096FAE24, 0x20);
    LoadBgTiles(0, gUnk_096444E4, 0x17A0);
    LoadBgMap(0, gUnk_096BB464, 0x800);
    work->tiles = LoadObjTiles(gUnk_0961FA28, 0xE20);
    work->palette = LoadObjPalette(gUnk_096FAE24, 0x20);
    work->gfx = gUnk_09EF36D0[0];
    work->x = 64;
    work->y = 64;
    work->unk_016 = 0;
    work->unk_00E = 0;
    work->unk_00C = 0;
    work->unk_010 = 0;
    SetBgBlend(0, 16, 0);
}

u8 task_wlogo_dil_1(WlogoDilWork* work) {
    switch (work->unk_00C) {
    case 0:
        work->unk_00E++;
        if (work->unk_00E > 29) {
            work->unk_00E = 0;
            work->unk_00C++;
        }
        break;
    case 1:
        work->unk_00E++;
        if (work->unk_00E > 2) {
            work->unk_00E = 0;
            work->unk_010++;
            if (work->unk_010 > 15) {
                work->unk_010 = 16;
                work->unk_016 = 1;
                work->unk_00C++;
            }
            SetBgBlend(0, 16 - work->unk_010, work->unk_010);
        }
        break;
    case 2:
        LoadBgMap(0, gUnk_096BBC64, 0x800);
        work->unk_010 = 0;
        SetBgBlend(0, 16, 0);
        work->unk_00C++;
        break;
    case 3:
        work->unk_00E++;
        if (work->unk_00E > 2) {
            work->unk_00E = 0;
            work->unk_010++;
            if (work->unk_010 > 15) {
                work->unk_010 = 16;
                LoadBgMap(0, gUnk_096BC464, 0x800);
                work->unk_016 = 0;
                work->unk_00C++;
            }
            SetBgBlend(0, 16 - work->unk_010, work->unk_010);
        }
        break;
    case 4:
        work->unk_00E++;
        if (work->unk_00E > 113) {
            work->unk_00E = 0;
            work->unk_00C++;
        }
        break;
    case 5:
        work->unk_00E++;
        if (work->unk_00E > 4) {
            work->unk_00E = 0;
            work->unk_010--;
            if (work->unk_010 == 0) {
                work->unk_010 = 0;
                SetBgBlend(0, 16, 0);
                DisableBg(0);
                return 0;
            }
            SetBgBlend(0, 16 - work->unk_010, work->unk_010);
        }
        break;
    }
    return 1;
}

void task_wlogo_dil_2(WlogoDilWork* work) {
    if (work->unk_016 == 1) {
        DrawSprite(work->x, work->y, work->gfx, work->tiles, work->palette, 0, 0x400, 0);
    }
}

void task_wlogo_dil_3(WlogoDilWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_wlogo_agr_0(WlogoAgrWork* work, s32 arg) {
    work->unk_017 = arg;
    LoadBgPalette(0, gUnk_096FADE4, 0x20);
    LoadBgMap(0, gUnk_096B9C64, 0x800);
    LoadBgTiles(0, gUnk_09642CE4, 0xC00);
    work->tiles = LoadObjTiles(gUnk_0961DC0E, 0x1DE0);
    work->palette = LoadObjPalette(gUnk_096FADE4, 0x20);
    work->gfx = gUnk_09EF3614[11];
    work->x = 64;
    work->y = 64;
    work->unk_010 = 0;
    work->unk_012 = 0;
    work->unk_011 = 0;
    work->unk_014 = 0;
    work->unk_016 = 0;
    SetBgBlend(0, 16, 0);
    TaskPoolInit(&gWlogoAgrTaskPool, 50);
}

u8 task_wlogo_agr_1(WlogoAgrWork* work) {
    WlogoAgrEntry a;
    WlogoAgrEntry b;

    switch (work->unk_011) {
    case 0:
        work->unk_012++;
        if (work->unk_012 > 29) {
            work->unk_012 = 0;
            work->unk_011++;
            TaskCreate(&gWlogoAgrTaskPool, &gTaskDescWlogoAgrFlash0, (void*)0);
        }
        break;
    case 1:
        work->unk_012++;
        if (work->unk_012 > 1) {
            work->unk_012 = 0;
            work->unk_016++;
            if (work->unk_016 > 15) {
                work->unk_016 = 16;
                work->unk_010 = 1;
                work->unk_011++;
            }
            SetBgBlend(0, 16 - work->unk_016, work->unk_016);
        }
        break;
    case 2:
        LoadBgMap(0, gUnk_096BA464, 0x800);
        work->unk_016 = 0;
        SetBgBlend(0, 16, 0);
        work->unk_011++;
        break;
    case 3:
        if (work->unk_012 == gUnk_09EF191C[work->unk_014].unk_04) {
            a.unk_00 = gUnk_09EF191C[work->unk_014].unk_00;
            a.unk_02 = gUnk_09EF191C[work->unk_014].unk_02;
            a.unk_06 = gUnk_09EF191C[work->unk_014].unk_06;
            a.unk_07 = gUnk_09EF191C[work->unk_014].unk_07;
            TaskCreate(&gWlogoAgrTaskPool, &gTaskDescWlogoAgrSmoke, &a);
            b.unk_08 = gUnk_09EF191C[work->unk_014].unk_08;
            b.unk_0A = gUnk_09EF191C[work->unk_014].unk_0A;
            b.unk_0C = gUnk_09EF191C[work->unk_014].unk_0C;
            TaskCreate(&gWlogoAgrTaskPool, &gTaskDescWlogoAgrFlash1, &b);
            b.unk_08 = gUnk_09EF191C[work->unk_014].unk_08 + 20;
            b.unk_0A = gUnk_09EF191C[work->unk_014].unk_0A + 20;
            b.unk_0C = gUnk_09EF191C[work->unk_014].unk_0C + 1;
            TaskCreate(&gWlogoAgrTaskPool, &gTaskDescWlogoAgrFlash1, &b);
            work->unk_014++;
            if (work->unk_014 > 18) {
                work->unk_012 = 0;
                work->unk_014 = 5;
                work->unk_010 = 0;
                work->unk_011++;
            }
        }

        if (work->unk_012 >= 30 && work->unk_012 <= 78) {
            if ((work->unk_012 - 30) % 3 == 0) {
                work->unk_016++;
                if (work->unk_016 > 15) {
                    work->unk_016 = 16;
                }
                SetBgBlend(0, 16 - work->unk_016, work->unk_016);
            }
        }
        work->unk_012++;
        break;
    case 4:
        if (work->unk_012 <= 59) {
            if (work->unk_012 % 20 == 0) {
                b.unk_08 = gUnk_09EF191C[work->unk_014].unk_08;
                b.unk_0A = gUnk_09EF191C[work->unk_014].unk_0A;
                b.unk_0C = gUnk_09EF191C[work->unk_014].unk_0C;
                TaskCreate(&gWlogoAgrTaskPool, &gTaskDescWlogoAgrFlash1, &b);
            }
            work->unk_014++;
            if (work->unk_014 > 15) {
                work->unk_014 = 9;
            }
        }

        if (work->unk_012 == 60) {
            b.unk_08 = 115;
            b.unk_0A = 80;
            b.unk_0C = 6;
            TaskCreate(&gWlogoAgrTaskPool, &gTaskDescWlogoAgrFlash1, &b);
            b.unk_08 = 110;
            b.unk_0A = 60;
            b.unk_0C = 8;
            TaskCreate(&gWlogoAgrTaskPool, &gTaskDescWlogoAgrFlash1, &b);
        }

        if (work->unk_012 == 70) {
            b.unk_08 = 95;
            b.unk_0A = 65;
            b.unk_0C = 7;
            TaskCreate(&gWlogoAgrTaskPool, &gTaskDescWlogoAgrFlash1, &b);
            b.unk_08 = 100;
            b.unk_0A = 80;
            b.unk_0C = 6;
            TaskCreate(&gWlogoAgrTaskPool, &gTaskDescWlogoAgrFlash1, &b);
        }

        if (work->unk_012 == 80) {
            b.unk_08 = 134;
            b.unk_0A = 42;
            b.unk_0C = 8;
            TaskCreate(&gWlogoAgrTaskPool, &gTaskDescWlogoAgrFlash1, &b);
            b.unk_08 = 126;
            b.unk_0A = 50;
            b.unk_0C = 7;
            TaskCreate(&gWlogoAgrTaskPool, &gTaskDescWlogoAgrFlash1, &b);
        }
        work->unk_012++;
        if (work->unk_012 > 169) {
            work->unk_012 = 0;
            work->unk_011++;
        }
        break;
    case 5:
        work->unk_012++;
        if (work->unk_012 > 4) {
            work->unk_012 = 0;
            work->unk_016--;
            if (work->unk_016 == 0) {
                work->unk_016 = 0;
                SetBgBlend(0, 16, 0);
                DisableBg(0);
                return 0;
            }
            SetBgBlend(0, 16 - work->unk_016, work->unk_016);
        }
        break;
    }
    TaskPoolUpdate(&gWlogoAgrTaskPool);
    TaskPoolDraw(&gWlogoAgrTaskPool);
    return 1;
}

void task_wlogo_agr_2(WlogoAgrWork* work) {
    if (work->unk_010 == 1) {
        DrawSprite(work->x, work->y, work->gfx, work->tiles, work->palette, 0, 0, 3);
    }
}

void task_wlogo_agr_3(WlogoAgrWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    TaskPoolDestroy(&gWlogoAgrTaskPool);
}

void task_wlogo_agr_smoke_0(WlogoAgrSmokeWork* work, WlogoAgrEntry* arg) {
    work->x = arg->unk_00 << 8;
    work->y = arg->unk_02 << 8;
    work->unk_030 = arg->unk_06;
    work->unk_031 = arg->unk_07;
    work->unk_02C = 0x100;
    work->unk_032 = 0;
    work->unk_034 = 30;
    work->tiles = LoadObjTiles(gUnk_0961DC0E, 0x1DE0);
    work->palette = LoadObjPalette(gUnk_096FADE4, 0x20);
    AnimInit(&work->anim, gUnk_09EF36AC, gUnk_09EF3614);
    AnimStart(&work->anim, work->unk_030, 1);
    work->gfx = AnimGetGfx(&work->anim);
}

u8 task_wlogo_agr_smoke_1(WlogoAgrSmokeWork* work) {
    if (AnimIsFinished(&work->anim)) {
        return 0;
    }
    work->gfx = AnimUpdate(&work->anim);
    return 1;
}

void task_wlogo_agr_smoke_2(WlogoAgrSmokeWork* work) {
    DrawSprite(work->x >> 8, work->y >> 8, work->gfx, work->tiles, work->palette, 0, 0, 1);
}

void task_wlogo_agr_smoke_3(WlogoAgrSmokeWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_wlogo_agr_flash0_0(WlogoAgrFlashWork* work) {
    work->unk_028 = 4;
    work->x = 64;
    work->y = 64;
    work->tiles = LoadObjTiles(gUnk_0961DC0E, 0x1DE0);
    work->palette = LoadObjPalette(gUnk_096FADE4, 0x20);
    AnimInit(&work->anim, gUnk_09EF36AC, gUnk_09EF3614);
    AnimStart(&work->anim, work->unk_028, 0);
    work->gfx = AnimGetGfx(&work->anim);
}

u8 task_wlogo_agr_flash0_1(WlogoAgrFlashWork* work) {
    if (AnimIsFinished(&work->anim)) {
        return 0;
    }
    work->gfx = AnimUpdate(&work->anim);
    return 1;
}

void task_wlogo_agr_flash0_2(WlogoAgrFlashWork* work) {
    DrawSprite(work->x, work->y, work->gfx, work->tiles, work->palette, 0, 0, 2);
}

void task_wlogo_agr_flash0_3(WlogoAgrFlashWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_wlogo_agr_flash1_0(WlogoAgrFlashWork* work, WlogoAgrEntry* arg) {
    work->unk_028 = arg->unk_0C;
    work->x = arg->unk_08;
    work->y = arg->unk_0A;
    work->tiles = LoadObjTiles(gUnk_0961DC0E, 0x1DE0);
    work->palette = LoadObjPalette(gUnk_096FADE4, 0x20);
    AnimInit(&work->anim, gUnk_09EF36AC, gUnk_09EF3614);
    AnimStart(&work->anim, work->unk_028, 1);
    work->gfx = AnimGetGfx(&work->anim);
}

u8 task_wlogo_agr_flash1_1(WlogoAgrFlashWork* work) {
    if (AnimIsFinished(&work->anim)) {
        return 0;
    }
    work->gfx = AnimUpdate(&work->anim);
    return 1;
}

void task_wlogo_agr_flash1_2(WlogoAgrFlashWork* work) {
    DrawSprite(work->x, work->y, work->gfx, work->tiles, work->palette, 0, 0, 0);
}

void task_wlogo_agr_flash1_3(WlogoAgrFlashWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_wlogo_tvt_0(WlogoTvtWork* work) {
    LoadBgPalette(0, gUnk_096FAE44, 0x20);
    LoadBgTiles(0, gUnk_09645C84, 0xC00);
    LoadBgMap(0, gUnk_096BCC64, 0x800);
    RequestDma3Copy(gUnk_096474A4, (u8*)GetBgCharBase(0) + 32, 0x300);
    work->tiles = AllocObjTiles(0x780, gUnk_09620B0E);
    work->palette = LoadObjPalette(gUnk_096FAE44, 0x20);
    work->x = 64;
    work->y = 64;
    work->unk_02A = 0;
    work->unk_029 = 0;
    work->unk_030 = 0;
    work->unk_02C = 0;
    work->unk_02E = 0;
    work->unk_028 = 0;
    SetBgBlend(0, 16 - work->unk_030, work->unk_030);
    AnimInit(&work->anim, gUnk_09EF3730, gUnk_09EF36D8);
    AnimStart(&work->anim, 0, 0);
    work->gfx = AnimGetGfx(&work->anim);
}

#ifdef NON_MATCHING
u8 task_wlogo_tvt_1(WlogoTvtWork* work) {
    switch (work->unk_029) {
    case 0:
        work->unk_02A++;
        if (work->unk_02A > 29) {
            work->unk_02A = 0;
            work->unk_029++;
        }
        break;
    case 1:
        work->unk_02E++;
        if (work->unk_02E > 44) {
            work->unk_02E = 0;
            work->unk_02C = 1 - work->unk_02C;
            RequestDma3Copy(&gUnk_096474A4[work->unk_02C * 1024], (u8*)GetBgCharBase(0) + 32, 0x320);
        }
        work->unk_02A++;
        if (work->unk_02A > 3) {
            work->unk_02A = 0;
            work->unk_030++;
            if (work->unk_030 > 15) {
                work->unk_030 = 16;
                work->unk_029++;
            }
            SetBgBlend(0, 16 - work->unk_030, work->unk_030);
        }
        break;
    case 2:
        work->unk_02E++;
        if (work->unk_02E > 44) {
            work->unk_02E = 0;
            work->unk_02C = 1 - work->unk_02C;
            RequestDma3Copy(&gUnk_096474A4[work->unk_02C * 1024], (u8*)GetBgCharBase(0) + 32, 0x320);
        }
        work->unk_02A++;
        if (work->unk_02A > 89) {
            work->unk_02A = 0;
            work->unk_028 = 1;
            work->unk_029++;
        }
        break;
    case 3:
        work->unk_02E++;
        if (work->unk_02E > 44) {
            work->unk_02E = 0;
            work->unk_02C = 1 - work->unk_02C;
            RequestDma3Copy(&gUnk_096474A4[work->unk_02C * 1024], (u8*)GetBgCharBase(0) + 32, 0x320);
        }

        if (AnimIsFinished(&work->anim)) {
            LoadBgTiles(0, gUnk_09646884, 0xC00);
            work->unk_02C += 2;
            RequestDma3Copy(&gUnk_096474A4[work->unk_02C * 1024], (u8*)GetBgCharBase(0) + 32, 0x320);
            work->unk_028 = 0;
            work->unk_029++;
        } else {
            work->gfx = AnimUpdate(&work->anim);
        }
        break;
    case 4:
        work->unk_02E++;
        if (work->unk_02E > 44) {
            work->unk_02E = 0;
            work->unk_02C = 5 - work->unk_02C;
            RequestDma3Copy(&gUnk_096474A4[work->unk_02C * 1024], (u8*)GetBgCharBase(0) + 32, 0x320);
        }
        work->unk_02A++;
        if (work->unk_02A > 113) {
            work->unk_02A = 0;
            work->unk_02C = 2;
            work->unk_029++;
        }
        break;
    case 5:
        work->unk_02E++;
        if (work->unk_02E > 44) {
            work->unk_02E = 0;
            work->unk_02C = 5 - work->unk_02C;
            RequestDma3Copy(&gUnk_096474A4[work->unk_02C * 1024], (u8*)GetBgCharBase(0) + 32, 0x320);
        }
        work->unk_02A++;
        if (work->unk_02A > 4) {
            work->unk_02A = 0;
            work->unk_030--;
            if (work->unk_030 == 0) {
                work->unk_030 = 0;
                SetBgBlend(0, 16, 0);
                DisableBg(0);
                return 0;
            }
            SetBgBlend(0, 16 - work->unk_030, work->unk_030);
        }
        break;
    }
    return 1;
}
#else
INCLUDE_ASM("wlogo/task_wlogo_tvt_1.s");
#endif

void task_wlogo_tvt_2(WlogoTvtWork* work) {
    if (work->unk_028 == 1) {
        DrawSprite(work->x, work->y, work->gfx, work->tiles, work->palette, 0, 0, 0);
    }
}

void task_wlogo_tvt_3(WlogoTvtWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_wlogo_poo_0(WlogoPooWork* work) {
    LoadBgPalette(0, gUnk_096FAE64, 0x20);
    LoadBgTiles(0, gUnk_09648484, 0xA20);
    LoadBgMap(0, gUnk_096BD464, 0x800);
    work->unk_002 = 0;
    work->unk_000 = 0;
    work->unk_008 = 0;
    work->unk_004 = 0;
    work->unk_006 = 0;
    SetBgBlend(0, 16, 0);
    TaskPoolInit(&gWlogoPooTaskPool, 4);
}

u8 task_wlogo_poo_1(WlogoPooWork* work) {
    switch (work->unk_000) {
    case 0:
        work->unk_002++;
        if (work->unk_002 > 29) {
            work->unk_002 = 0;
            work->unk_000++;
        }
        break;
    case 1:
        work->unk_002++;
        if (work->unk_002 > 5) {
            work->unk_002 = 0;
            work->unk_008++;
            if (work->unk_008 > 15) {
                work->unk_008 = 16;
                TaskCreate(&gWlogoPooTaskPool, &gTaskDescWlogoPooObj, (void*)0);
                TaskCreate(&gWlogoPooTaskPool, &gTaskDescWlogoPooObj, (void*)1);
                TaskCreate(&gWlogoPooTaskPool, &gTaskDescWlogoPooObj, (void*)2);
                TaskCreate(&gWlogoPooTaskPool, &gTaskDescWlogoPooObj, (void*)3);
                work->unk_000++;
            }
            SetBgBlend(0, 16 - work->unk_008, work->unk_008);
        }
        break;
    case 2:
        work->unk_002++;
        if (work->unk_002 > 113) {
            work->unk_002 = 0;
            work->unk_000++;
        }
        break;
    case 3:
        work->unk_002++;
        if (work->unk_002 > 4) {
            work->unk_002 = 0;
            work->unk_008--;
            if (work->unk_008 == 0) {
                work->unk_008 = 0;
                SetBgBlend(0, 16, 0);
                DisableBg(0);
                return 0;
            }
            SetBgBlend(0, 16 - work->unk_008, work->unk_008);
        }
        break;
    }
    TaskPoolUpdate(&gWlogoPooTaskPool);
    TaskPoolDraw(&gWlogoPooTaskPool);
    return 1;
}

void task_wlogo_poo_2(WlogoPooWork* work) {
}

void task_wlogo_poo_3(WlogoPooWork* work) {
    TaskPoolDestroy(&gWlogoPooTaskPool);
}

void task_wlogo_poo_obj_0(WlogoPooObjWork* work, s32 arg) {
    work->unk_041 = arg;
    work->tiles = LoadObjTiles(gUnk_096249F4, 0x380);
    work->palette = LoadObjPalette(gUnk_096FAE64, 0x20);
    work->x = 0x8200;
    work->y = 0x4000;
    work->unk_02C = gUnk_09619A04[work->unk_041][0].unk_04;
    work->unk_030 = gUnk_09619A04[work->unk_041][0].unk_08;
    work->unk_034 = gUnk_09619A04[work->unk_041][0].unk_0C;
    work->unk_038 = gUnk_09619A04[work->unk_041][0].unk_10;
    work->unk_03C = 0;
    work->unk_03E = 0;
    work->unk_040 = 0;
    work->unk_042 = 1;
    work->unk_043 = gUnk_09EF1AEC[work->unk_041];
    AnimInit(&work->anim, gUnk_09EF376C, gUnk_09EF3734);
    AnimStart(&work->anim, work->unk_043, 1);
    work->gfx = AnimGetGfx(&work->anim);
}

u8 task_wlogo_poo_obj_1(WlogoPooObjWork* work) {
    work->x += work->unk_02C;
    work->y += work->unk_030;
    work->unk_02C += work->unk_034;
    work->unk_030 += work->unk_038;
    work->gfx = AnimUpdate(&work->anim);

    if (work->unk_040 != 0) {
        if (work->unk_03E > 150) {
            return 0;
        }
    } else if (work->unk_03E == gUnk_09619A04[work->unk_041][work->unk_03C].unk_00) {
        work->unk_03E = 0;
        work->unk_02C = gUnk_09619A04[work->unk_041][work->unk_03C].unk_04;
        work->unk_030 = gUnk_09619A04[work->unk_041][work->unk_03C].unk_08;
        work->unk_034 = gUnk_09619A04[work->unk_041][work->unk_03C].unk_0C;
        work->unk_038 = gUnk_09619A04[work->unk_041][work->unk_03C].unk_10;
        work->unk_03C++;
        if (work->unk_03C > 4) {
            work->unk_040++;
        }
    }
    work->unk_03E++;
    return 1;
}

void task_wlogo_poo_obj_2(WlogoPooObjWork* work) {
    if (work->unk_042 == 1) {
        DrawSprite(work->x >> 8, work->y >> 8, work->gfx, work->tiles, work->palette, 0, 0, 0);
    }
}

void task_wlogo_poo_obj_3(WlogoPooObjWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_wlogo_tt_0(WlogoTtWork* work) {
    s32 i;

    LoadBgPalette(0, gUnk_096FAE84, 0x20);
    LoadBgTiles(0, gUnk_09648EA4, 0x1260);
    LoadBgMap(0, gUnk_096BE464, 0x800);
    LoadPalette(&gUnk_096FAEA4[15 * 32], (void*)0x050001E0, 0x20);
    work->unk_002 = 0;
    work->unk_004 = 0;
    work->unk_000 = 0;
    work->unk_006 = 0;
    work->unk_007 = 0;
    work->unk_108 = 51;
    work->unk_10C = 51;
    SetBgBlend(0, 16 - work->unk_006, work->unk_006);
    work->unk_008 = AllocObjTiles(0x200, gUnk_09624F72);
    work->unk_00C = AllocObjTiles(0x200, gUnk_09624F72);
    work->unk_010 = AllocObjTiles(0x200, gUnk_09624F72);
    work->unk_014 = AllocObjTiles(0x3C0, gUnk_09624F72);
    work->unk_018 = LoadObjTiles(gUnk_0962848A, 0x7C0);
    work->palette = LoadObjPalette(gUnk_096FAE84, 0x20);
    LoadObjPaletteBank(work->palette->unk_06, &gUnk_096FAEA4[work->unk_007 * 32]);
    AnimInit(&work->anim[0], gUnk_09EF37DC, gUnk_09EF377C);
    AnimStart(&work->anim[0], 1, 0);
    work->unk_020 = AnimGetGfx(&work->anim[0]);
    AnimInit(&work->anim[1], gUnk_09EF37DC, gUnk_09EF377C);
    AnimStart(&work->anim[1], 2, 0);
    work->unk_024 = AnimGetGfx(&work->anim[1]);
    AnimInit(&work->anim[2], gUnk_09EF37DC, gUnk_09EF377C);
    AnimStart(&work->anim[2], 4, 0);
    work->unk_028 = AnimGetGfx(&work->anim[2]);
    AnimInit(&work->anim[3], gUnk_09EF37DC, gUnk_09EF377C);
    AnimStart(&work->anim[3], 4, 0);
    work->unk_02C = AnimGetGfx(&work->anim[3]);
    AnimInit(&work->anim[4], gUnk_09EF37DC, gUnk_09EF377C);
    AnimStart(&work->anim[4], 0, 0);
    work->unk_030 = AnimGetGfx(&work->anim[4]);
    AnimInit(&work->anim[5], gUnk_09EF37DC, gUnk_09EF377C);
    AnimStart(&work->anim[5], 0, 0);
    work->unk_034 = AnimGetGfx(&work->anim[5]);
    work->unk_038 = gUnk_09EF37F4[0];

    for (i = 0; i < 8; i++) {
        work->unk_100[i] = 0;
    }
    TaskPoolInit(&work->unk_114, 1);
    WlogoEnableHBlank();
    gUnk_0203AB38 = -0x299;
    work->unk_110 = 25;
}

#ifdef NON_MATCHING
u8 task_wlogo_tt_1(WlogoTtWork* work) {
    switch (work->unk_000) {
    case 0:
        work->unk_002++;
        if (work->unk_002 > 29) {
            work->unk_002 = 0;
            work->unk_000++;
        }
        break;
    case 1:
        work->unk_002++;
        if (work->unk_002 > 3) {
            work->unk_002 = 0;
            work->unk_006++;
            if (work->unk_006 > 15) {
                work->unk_006 = 16;
                work->unk_000++;
            }
            SetBgBlend(0, 16 - work->unk_006, work->unk_006);
        }
        break;
    case 2:
        gUnk_0203AB38 += work->unk_110;
        work->unk_110 = work->unk_110;

        if (gUnk_0203AB38 > 332) {
            work->unk_100[2] = 1;
            work->unk_002 = 0;
            work->unk_000++;
        }
        break;
    case 3:
        work->unk_028 = AnimUpdate(&work->anim[2]);

        if (work->unk_002 > 13) {
            work->unk_002 = 0;
            work->unk_004 = 0;
            work->unk_108 = gUnk_09EF1B08[0];
            work->unk_100[0] = 1;
            work->unk_000++;
        } else {
            work->unk_002++;
        }
        break;
    case 4:
        if (work->unk_002 > 10) {
            work->unk_002 = 0;
            work->unk_004++;
            if (work->unk_004 > 4) {
                work->unk_004 = 4;
            }
            work->unk_108 = gUnk_09EF1B08[work->unk_004];
        }
        work->unk_002++;

        if (AnimIsFinished(&work->anim[2])) {
            work->unk_100[2] = 0;
            work->unk_100[3] = 1;
            work->unk_002 = 0;
            work->unk_000++;
        } else {
            work->unk_020 = AnimUpdate(&work->anim[0]);
            work->unk_028 = AnimUpdate(&work->anim[2]);
        }
        break;
    case 5:
        work->unk_02C = AnimUpdate(&work->anim[3]);

        if (work->unk_002 > 13) {
            work->unk_002 = 0;
            work->unk_004 = 0;
            work->unk_10C = gUnk_09EF1B08[6];
            work->unk_100[1] = 1;
            work->unk_000++;
        } else {
            work->unk_002++;
        }
        break;
    case 6:
        if (work->unk_002 > 13) {
            work->unk_002 = 0;
            work->unk_004++;
            if (work->unk_004 > 2) {
                work->unk_004 = 2;
            }
            work->unk_10C = gUnk_09EF1B08[work->unk_004 + 6];
        }
        work->unk_002++;

        if (AnimIsFinished(&work->anim[3])) {
            work->unk_100[3] = 0;
            work->unk_100[4] = 1;
            work->unk_100[5] = 1;
            work->unk_100[6] = 1;
            TaskCreate(&work->unk_114, &gTaskDescWlogoTtLine, (void*)0);
            work->unk_002 = 0;
            work->unk_004 = 0;
            work->unk_000++;
        } else {
            work->unk_024 = AnimUpdate(&work->anim[1]);
            work->unk_02C = AnimUpdate(&work->anim[3]);
        }
        break;
    case 7:
        if (work->unk_006 != 0) {
            work->unk_006--;
            if (work->unk_006 == 0) {
                DisableBg(0);
            }
            SetBgBlend(0, 16 - work->unk_006, work->unk_006);
        } else if (work->unk_002 == 0) {
            WlogoDisableHBlank();
            work->unk_002++;
        } else if (work->unk_004 > 1) {
            work->unk_004 = 0;
            work->unk_007++;
            if (work->unk_007 == 4) {
                work->unk_000++;
            }
            LoadObjPaletteBank(work->palette->unk_06, &gUnk_096FAEA4[work->unk_007 * 32]);
        } else {
            work->unk_004++;
        }
        work->unk_030 = AnimUpdate(&work->anim[4]);
        work->unk_034 = AnimUpdate(&work->anim[5]);
        break;
    case 8:
        if (work->unk_004 > 1) {
            work->unk_004 = 0;
            work->unk_007++;
            if (work->unk_007 > 8) {
                work->unk_000++;
            } else {
                LoadObjPaletteBank(work->palette->unk_06, &gUnk_096FAEA4[work->unk_007 * 32]);
            }
        } else {
            work->unk_004++;
        }
        work->unk_030 = AnimUpdate(&work->anim[4]);
        work->unk_034 = AnimUpdate(&work->anim[5]);
        break;
    case 9:
        work->unk_100[6] = 0;
        LoadBgMap(0, gUnk_096BDC64, 0x800);
        LoadPalette(gUnk_096FAFA4, (void*)0x050001C0, 0x20);
        EnableBg(0);
        work->unk_006 = 16;
        SetBgBlend(0, 0, 16);
        work->unk_100[0] = 0;
        work->unk_100[1] = 0;
        work->unk_030 = AnimUpdate(&work->anim[4]);
        work->unk_034 = AnimUpdate(&work->anim[5]);
        work->unk_000++;
        break;
    case 10:
        if (AnimIsFinished(&work->anim[4])) {
            work->unk_100[4] = 0;
            work->unk_100[5] = 0;
            work->unk_004 = 0;
            work->unk_002 = 0;
            work->unk_007 = 8;
            work->unk_000++;
        } else {
            work->unk_030 = AnimUpdate(&work->anim[4]);
            work->unk_034 = AnimUpdate(&work->anim[5]);
        }
        break;
    case 11:
        if (work->unk_007 == 4) {
            work->unk_002 = 0;
            work->unk_000++;
        } else if (work->unk_004 > 1) {
            work->unk_004 = 0;
            work->unk_007--;
            LoadPalette(&gUnk_096FAEA4[work->unk_007 * 32], (void*)0x050001C0, 0x20);
        } else {
            work->unk_004++;
        }
        break;
    case 12:
        work->unk_002++;
        if (work->unk_002 > 113) {
            work->unk_002 = 0;
            work->unk_000++;
        }
        break;
    case 13:
        work->unk_002++;
        if (work->unk_002 > 4) {
            work->unk_002 = 0;
            work->unk_006--;
            if (work->unk_006 == 0) {
                work->unk_006 = 0;
                SetBgBlend(0, 16, 0);
                DisableBg(0);
                return 0;
            }
            SetBgBlend(0, 16 - work->unk_006, work->unk_006);
        }
        break;
    }
    TaskPoolUpdate(&work->unk_114);
    return 1;
}
#else
INCLUDE_ASM("wlogo/task_wlogo_tt_1.s");
#endif

void task_wlogo_tt_2(WlogoTtWork* work) {
    s32 affine;

    if (work->unk_100[4] == 1) {
        DrawSprite(72, 64, work->unk_030, work->unk_008, work->palette, 0, 0, 4);
    }

    if (work->unk_100[5] == 1) {
        DrawSprite(96, 80, work->unk_034, work->unk_008, work->palette, 0, 0, 6);
    }

    if (work->unk_100[0] == 1) {
        affine = AllocObjAffine(0, work->unk_108, 0x100, 0);
        DrawSprite(78, 72, work->unk_020, work->unk_00C, work->palette, affine, 0, 24);
    }

    if (work->unk_100[2] == 1) {
        DrawSprite(65, 65, work->unk_028, work->unk_014, work->palette, 0, 0, 20);
    }

    if (work->unk_100[1] == 1) {
        affine = AllocObjAffine(0, work->unk_10C, 0x100, 0);
        DrawSprite(108, 94, work->unk_024, work->unk_010, work->palette, affine, 0, 26);
    }

    if (work->unk_100[3] == 1) {
        DrawSprite(96, 87, work->unk_02C, work->unk_014, work->palette, 0, 0, 22);
    }

    if (work->unk_100[6] == 1) {
        DrawSprite(64, 64, work->unk_038, work->unk_018, work->palette, 0, 0, 32);
    }
    TaskPoolDraw(&work->unk_114);
}

void task_wlogo_tt_3(WlogoTtWork* work) {
    WlogoDisableHBlank();
    TaskPoolDestroy(&work->unk_114);
    ReleaseObjTiles(work->unk_008);
    ReleaseObjTiles(work->unk_00C);
    ReleaseObjTiles(work->unk_010);
    ReleaseObjTiles(work->unk_014);
    ReleaseObjPalette(work->palette);
}

void WlogoEnableHBlank(void) {
    SetHBlankCallback(WlogoHBlankIntr);
    EnableHBlankIntr();
}

void WlogoHBlankIntr(void) {
    vu16 line;

    gIntrCheck |= 2;
    line = REG_VCOUNT;
    line = (line + 1) % 228;
    if (line <= 96) {
        REG_BGHOFS(0) = 0;
    } else {
        REG_BGHOFS(0) = gUnk_0203AB38 * (line - 97) >> 8;
    }
}

void WlogoDisableHBlank(void) {
    ResetHBlankCallback();
    DisableHBlankIntr();
}

void task_wlogo_tt_obj_0(WlogoTtObjWork* work, WlogoTtObjArg* arg) {
    work->x = arg->unk_00;
    work->y = arg->unk_04;
    work->unk_02C = 0;
    work->unk_02E = 0;
    work->tiles = LoadObjTiles(gUnk_0962848A, 0x7C0);
    work->palette = LoadObjPalette(gUnk_096FAE84, 0x20);
    AnimInit(&work->anim, gUnk_09EF3804, gUnk_09EF37F4);
    AnimStart(&work->anim, 1, 0);
    work->gfx = AnimGetGfx(&work->anim);
}

u8 task_wlogo_tt_obj_1(WlogoTtObjWork* work) {
    work->x += 0x100;

    if (AnimIsFinished(&work->anim)) {
        return 0;
    }
    work->gfx = AnimUpdate(&work->anim);
    return 1;
}

void task_wlogo_tt_obj_2(WlogoTtObjWork* work) {
    DrawSprite(work->x >> 8, work->y >> 8, work->gfx, work->tiles, work->palette, 0, 0, 16);
}

void task_wlogo_tt_obj_3(WlogoTtObjWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_wlogo_tt_line_0(WlogoTtLineWork* work) {
    work->unk_000 = 0;
    work->unk_002 = 0;
    work->unk_004 = 0;
    TaskPoolInit(&work->unk_008, 33);
}

u8 task_wlogo_tt_line_1(WlogoTtLineWork* work) {
    WlogoTtObjArg arg;

    switch (work->unk_004) {
    case 0:
        if (work->unk_000 == gUnk_09EF1B68[work->unk_002][2]) {
            work->unk_000 = 0;
            arg.unk_00 = gUnk_09EF1B68[work->unk_002][0] << 8;
            arg.unk_04 = gUnk_09EF1B68[work->unk_002][1] << 8;
            TaskCreate(&work->unk_008, &gTaskDescWlogoTtObj, &arg);
            work->unk_002++;
            if (work->unk_002 == 31) {
                work->unk_004++;
            }
        } else {
            work->unk_000++;
        }
        break;
    case 1:
        if (work->unk_000 > 29) {
            work->unk_004++;
        }
        work->unk_000++;
        break;
    default:
        return 0;
    }
    TaskPoolUpdate(&work->unk_008);
    return 1;
}

void task_wlogo_tt_line_2(WlogoTtLineWork* work) {
    TaskPoolDraw(&work->unk_008);
}

void task_wlogo_tt_line_3(WlogoTtLineWork* work) {
    TaskPoolDestroy(&work->unk_008);
}

void task_wlogo_bks_0(WlogoBksWork* work) {
    LoadBgPalette(0, gUnk_096FB0A4, 0x20);
    LoadBgTiles(0, gUnk_0964A104, 0xD80);
    LoadBgMap(0, gUnk_096BEC64, 0x800);
    work->unk_002 = 0;
    work->unk_004 = 0;
    work->unk_000 = 0;
    work->unk_00A = 0;
    work->unk_006 = 0;
    work->unk_008 = 0;
    work->unk_032 = 0;
    work->unk_030 = 0;
    SetBgBlend(0, 16 - work->unk_00A, work->unk_00A);
    TaskPoolInit(&work->unk_03C, 15);
    work->tiles = AllocObjTiles(0x580, gUnk_09628DC0);
    work->palette = LoadObjPalette(gUnk_096FB0A4, 0x20);
    AnimInit(&work->anim, gUnk_09EF3850, gUnk_09EF380C);
    AnimStart(&work->anim, 12, 0);
    work->gfx = AnimGetGfx(&work->anim);
    work->unk_034 = 0;
    work->unk_038 = 0;
    work->unk_036 = 4;
    work->unk_037 = 6;
    StartBgWave(func_080B7C7C);
    SetBgWaveParams(0, work->unk_036, work->unk_037);
}

u8 task_wlogo_bks_1(WlogoBksWork* work) {
    switch (work->unk_000) {
    case 0:
        work->unk_002++;
        if (work->unk_002 > 29) {
            work->unk_002 = 0;
            EnableBgWave(0);
            work->unk_000++;
        }
        break;
    case 1:
        work->unk_002++;
        if (work->unk_002 > 5) {
            work->unk_002 = 0;
            work->unk_00A++;
            if (work->unk_00A > 15) {
                work->unk_00A = 16;
            }
            SetBgBlend(0, 16 - work->unk_00A, work->unk_00A);
        }
        work->unk_034++;
        if (work->unk_034 > 29) {
            work->unk_034 = 0;

            if (work->unk_036 <= 1) {
                work->unk_036 = 1;
                StopBgWave(0);
            } else {
                work->unk_036--;
                SetBgWaveParams(0, work->unk_036, work->unk_037);
            }
        }

        switch (work->unk_032) {
        case 20:
            TaskCreate(&work->unk_03C, &gTaskDescWlogoBksObj, (void*)13);
            break;
        case 30:
            TaskCreate(&work->unk_03C, &gTaskDescWlogoBksObj, (void*)12);
            TaskCreate(&work->unk_03C, &gTaskDescWlogoBksObj, (void*)0);
            break;
        case 40:
            TaskCreate(&work->unk_03C, &gTaskDescWlogoBksObj, (void*)11);
            TaskCreate(&work->unk_03C, &gTaskDescWlogoBksObj, (void*)1);
            break;
        case 50:
            TaskCreate(&work->unk_03C, &gTaskDescWlogoBksObj, (void*)10);
            TaskCreate(&work->unk_03C, &gTaskDescWlogoBksObj, (void*)2);
            break;
        case 60:
            TaskCreate(&work->unk_03C, &gTaskDescWlogoBksObj, (void*)9);
            TaskCreate(&work->unk_03C, &gTaskDescWlogoBksObj, (void*)3);
            break;
        case 70:
            TaskCreate(&work->unk_03C, &gTaskDescWlogoBksObj, (void*)4);
            TaskCreate(&work->unk_03C, &gTaskDescWlogoBksObj, (void*)8);
            break;
        case 80:
            TaskCreate(&work->unk_03C, &gTaskDescWlogoBksObj, (void*)7);
            TaskCreate(&work->unk_03C, &gTaskDescWlogoBksObj, (void*)5);
            break;
        case 90:
            TaskCreate(&work->unk_03C, &gTaskDescWlogoBksObj, (void*)6);
            break;
        case 115:
            work->unk_000++;
            break;
        }
        work->unk_032++;
        break;
    case 2:
        work->unk_030 = 1;
        StopBgWave(0);
        work->unk_004 = 1;
        work->unk_002 = 0;
        work->unk_000++;
        break;
    case 3:
        if (work->unk_004 <= 6) {
            if (++work->unk_002 >= gUnk_09EF1C48[work->unk_004]) {
                work->unk_002 = 0;
                LoadPalette(&gUnk_096FB0C4[gUnk_09EF1C50[work->unk_004] * 32], (void*)0x050001C0, 0x20);
                work->unk_004++;
            }
        }

        if (AnimIsFinished(&work->anim)) {
            StopBgWave(0);
            work->unk_002 = 0;
            work->unk_030 = 0;
            LoadPalette(gUnk_096FB0C4, (void*)0x050001C0, 0x20);
            LoadBgMap(0, gUnk_096BF464, 0x800);
            work->unk_000++;
        } else {
            work->gfx = AnimUpdate(&work->anim);
        }
        break;
    case 4:
        work->unk_002++;
        if (work->unk_002 > 113) {
            work->unk_002 = 0;
            work->unk_000++;
        }
        break;
    case 5:
        work->unk_002++;
        if (work->unk_002 > 4) {
            work->unk_002 = 0;
            work->unk_00A--;
            if (work->unk_00A == 0) {
                work->unk_00A = 0;
                SetBgBlend(0, 16, 0);
                DisableBg(0);
                return 0;
            }
            SetBgBlend(0, 16 - work->unk_00A, work->unk_00A);
        }
        break;
    }
    TaskPoolUpdate(&work->unk_03C);
    return 1;
}

void task_wlogo_bks_2(WlogoBksWork* work) {
    if (work->unk_030 == 1) {
        DrawSprite(64, 64, work->gfx, work->tiles, work->palette, 0, 0, 0);
    }
    TaskPoolDraw(&work->unk_03C);
}

void task_wlogo_bks_3(WlogoBksWork* work) {
    StopBgWave(0);
    TaskPoolDestroy(&work->unk_03C);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void func_080B7C7C(void) {
    gIntrCheck |= 2;
    HBlankIntrBgWave1(0);
}

void task_wlogo_bks_obj_0(WlogoBksObjWork* work, s32 arg) {
    work->unk_029 = arg;
    work->x = gUnk_09EF1CB6[work->unk_029][0] << 8;
    work->y = gUnk_09EF1CB6[work->unk_029][1] << 8;
    work->targetX = gUnk_09EF1C7E[work->unk_029][0] << 8;
    work->targetY = gUnk_09EF1C7E[work->unk_029][1] << 8;
    work->unk_03C = 0x100;
    work->unk_040 = 0x100;
    work->unk_024 = 0;
    work->unk_026 = 30;
    work->unk_028 = 0;
    work->unk_046 = 10;
    work->tiles = LoadObjTiles(gUnk_09628DC0, 0x800);
    work->palette = LoadObjPalette(gUnk_096FB0A4, 0x20);
    work->gfx = gUnk_09EF380C[gUnk_09EF1C70[work->unk_029]];
    work->unk_048 = gUnk_09EF1D0A[work->unk_029];
    work->unk_044 = 0;
}

u8 task_wlogo_bks_obj_1(WlogoBksObjWork* work) {
    switch (work->unk_028) {
    case 0:
        if (work->unk_026 > 0) {
            ApproachValue(&work->x, work->targetX, work->unk_026);
            ApproachValue(&work->y, work->targetY, work->unk_026);
            work->unk_026--;

            if (++work->unk_046 > 19) {
                work->unk_046 = 0;
            }
            work->unk_03C = gUnk_09EF180C[work->unk_046];
        } else {
            work->unk_024 = 0;
            work->unk_026 = 0;
            work->unk_028++;
        }
        break;
    case 1:
        if (work->unk_024 >= gUnk_09EF1CEE[work->unk_029]) {
            return 0;
        }
        work->unk_024++;
        break;
    }
    return 1;
}

void task_wlogo_bks_obj_2(WlogoBksObjWork* work) {
    s32 affine;

    affine = AllocObjAffine(0, work->unk_03C, work->unk_040, 1);
    DrawSprite(work->x >> 8, work->y >> 8, work->gfx, work->tiles, work->palette, affine, 0, work->unk_048);
}

void task_wlogo_bks_obj_3(WlogoBksObjWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void func_080B7E68(BosTmWork* w) {
    if (w->unk_28 & 0x20) {
        w->unk_48 = w->unk_14 + 0x1000;
        w->unk_54 = w->unk_14 - 0x700;
        w->unk_4C = w->unk_18 + 0x700;
        w->unk_58 = w->unk_18 - 0x400;
        w->unk_50 = w->unk_1C - 0x2200;
        w->unk_5C = w->unk_1C - 0x1C00;
    } else {
        w->unk_48 = w->unk_14 + 0x700;
        w->unk_54 = w->unk_14 - 0xE00;
        w->unk_4C = w->unk_18 - 0x400;
        w->unk_58 = w->unk_18 + 0x700;
        w->unk_50 = w->unk_1C - 0x1C00;
        w->unk_5C = w->unk_1C - 0x2200;
    }
}

void task_bos_tm_0(BosTmWork* w, BosTmShared* arg) {
    w->unk_28 = 0;

    if (arg != 0) {
        w->unk_28 = 8;
    }
    TaskPoolInit(&gBosTmTaskPool, 4);

    if (w->unk_28 & 8) {
        w->unk_00 = arg->x >> 8;
        w->unk_02 = arg->y >> 8;
        w->unk_04 = arg->z >> 8;
    } else {
        w->unk_00 = 0x15D;
        w->unk_02 = 0x16C;
        w->unk_04 = -0x3C;
        gBtlWork->unk_0CC = w->unk_00 << 8;
        gBtlWork->unk_0D0 = 0x156 << 8;
        gBtlWork->unk_0D4 = w->unk_04 << 8;
    }
    w->unk_08 = w->unk_00 << 8;
    w->unk_0C = w->unk_02 << 8;
    w->unk_10 = w->unk_04 << 8;
    w->unk_14 = w->unk_08;
    w->unk_18 = w->unk_0C;
    w->unk_1C = w->unk_10;
    w->unk_20 = 0;
    w->unk_24 = 0;
    w->unk_34 = 0;
    w->unk_36 = 0;
    w->unk_30 = 0;
    w->unk_32 = 55;
    w->unk_38 = 0;
    w->unk_3A = 0;
    w->unk_28 |= 0x30;
    w->unk_3B = 0;
    w->unk_3C = 16;
    w->unk_40 = 0;
    w->unk_42 = 0;
    w->unk_44 = 0;
    w->unk_60 = w;
    func_080B7E68(w);

    if (w->unk_28 & 8) {
        w->unk_2C = 15;
        gBosTmBodyTask = TaskCreate(&gBosTmTaskPool, &gTaskDescBosTmBody, w);
        gBosTmFootTask = TaskCreate(&gBosTmTaskPool, &gTaskDescBosTmFoot, w);
        gBosTmArmTask = TaskCreate(&gBosTmTaskPool, &gTaskDescBosTmArm, &w->unk_48);
    } else {
        w->unk_2C = 0;
        TaskCreate(&gBtlWork->unk_040, &gTaskDescBosMap, gUnk_09619C68);
        gBosTmTblTask = TaskCreate(&gBtlWork->unk_040, &gTaskDescBosTmTbl, w);
        gBosTmBodyTask = TaskCreate(&gBosTmTaskPool, &gTaskDescBosTmBody, w);
        gBosTmFootTask = TaskCreate(&gBosTmTaskPool, &gTaskDescBosTmFoot, w);
        gBosTmArmTask = TaskCreate(&gBosTmTaskPool, &gTaskDescBosTmArm, &w->unk_48);
        gBtlWork->unk_0D8 = 10;
    }
}

u8 task_bos_tm_1(BosTmWork* w) {
    WlogoObjParam param;
    u16 t;

    switch (w->unk_2C) {
    case 0:
    case 15:
        w->unk_36++;

        if ((s16)w->unk_36 > 8) {
            w->unk_36 = 0;
            w->unk_34++;

            if ((s16)w->unk_34 > 7) {
                w->unk_34 = 0;
            }
        }
        break;
    case 12:
        w->unk_34++;
        t = w->unk_30;

        if ((s16)t == 1) {
            w->unk_30 = t + 1;
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        w->unk_36++;

        if ((s16)w->unk_36 > 6) {
            w->unk_36 = 0;
            w->unk_34++;

            if ((s16)w->unk_34 > 9) {
                w->unk_34 = 0;
            }
        }
        break;
    case 13:
        if ((s16)w->unk_34 != 0) {
            if (!func_080C64A4()) {
                func_0801B008();
                return 0;
            }
        } else {
            param.tiles = 0x06010000 + (w->unk_40 << 5);
            param.unk_04 = w->unk_42;
            param.palette = 0x05000200 + (w->unk_44 << 5);
            param.unk_0C = 0x60;
            param.x = w->unk_14;
            param.y = w->unk_18;
            param.z = w->unk_1C;
            param.unk_1C = func_080B82D4;
            gUnk_0203AB50.x = w->unk_14;
            gUnk_0203AB50.y = w->unk_18;
            gUnk_0203AB50.z = w->unk_1C;
            param.unk_20 = &gUnk_0203AB50;
            func_080C640C(&param);
            w->unk_28 &= ~1;
            w->unk_34++;
        }
        break;
    case 2:
    case 3:
    case 9:
    case 11:
        w->unk_34++;
        break;
    case 17:
        break;
    }
    gUnk_0203AB44 = gBtlWork->unk_07C->unk_08 >> 8;
    gUnk_0203AB40 = gBtlWork->unk_07C->unk_1C >> 8;
    gUnk_0203AB3C = gBtlWork->unk_07C->unk_0C >> 8;
    gUnk_0203AB48 = gBtlWork->unk_0D0 >> 8;

    if ((gBtlWork->unk_068 & 0x20000000) && w->unk_2C != 13) {
        if (gBtlWork->unk_07C->unk_1C <= -0x2D00) {
            gBtlWork->unk_0D8 = -10;
        } else {
            gBtlWork->unk_0D8 = 10;
        }
    } else {
        if (gBtlWork->unk_07C->unk_0C <= -0x2D00) {
            gBtlWork->unk_0D8 = -10;
        } else {
            gBtlWork->unk_0D8 = 10;
        }
    }
    TaskPoolUpdate(&gBosTmTaskPool);
    func_080B7E68(w);
    w->unk_38++;
    return 1;
}

void task_bos_tm_2(BosTmWork* w) {
    TaskPoolDraw(&gBosTmTaskPool);
}

void task_bos_tm_3(BosTmWork* w) {
    TaskPoolDestroy(&gBosTmTaskPool);
}

void func_080B82D4(void) {
    func_08000DE8(&gBtlWork->unk_040, gBosTmTblTask);
    func_08000DE8(&gBosTmTaskPool, gBosTmBodyTask);
    func_08000DE8(&gBosTmTaskPool, gBosTmFootTask);
    func_08000DE8(&gBosTmTaskPool, gBosTmArmTask);
}

void func_080B8324(WlogoTtEffTop* p) {
    p->unk_000->unk_36 = 0;
    p->unk_000->unk_34 = 0;
    p->unk_000->unk_38 = 0;
}

void func_080B8334(WlogoTtEff* p, s16 a, s16 b, s16 c) {
    p->unk_004 = a << 8;
    p->unk_008 = b << 8;
    p->unk_00C = (c << 8) + 0x1900;
    func_0801B37C(p, gUnk_09619C94, p->unk_004, p->unk_008, p->unk_00C);
    p->unk_09E = 14;
    p->unk_0A0 = 40;
    p->unk_09C = 28;
    p->unk_034 |= 0x400;
    p->unk_034 |= 4;
}

void func_080B83A4(WlogoTtEff* p, s16 a, s16 b, s16 c) {
    p->unk_004 = a << 8;
    p->unk_008 = b << 8;
    p->unk_00C = c << 8;
}

void func_080B83B8(void* a) {
    func_0801B7D8(a);
}

void func_080B83C4(WlogoTtEff* p) {
    p->unk_484++;
    if (p->unk_484 > 5) {
        p->unk_484 = 0;
        p->unk_482++;
        if (p->unk_482 > 10) {
            p->unk_482 = 0;
        }
        p->unk_128 = gUnk_09EF1D58[p->unk_482];
    }
}

void func_080B8418(WlogoTtEffTop* p) {
    if (p->unk_000->unk_28 & 0x20) {
        p->unk_014 = p->unk_000->unk_14 + 0x400;
        p->unk_130 = p->unk_000->unk_14;
        p->unk_24C = p->unk_000->unk_14 + 0xC00;
        p->unk_368 = p->unk_000->unk_14 - 0x100;
    } else {
        p->unk_014 = p->unk_000->unk_14 - 0x400;
        p->unk_130 = p->unk_000->unk_14;
        p->unk_24C = p->unk_000->unk_14 - 0xC00;
        p->unk_368 = p->unk_000->unk_14 + 0x100;
    }
    p->unk_018 = p->unk_000->unk_18;
    p->unk_134 = p->unk_000->unk_18;
    p->unk_250 = p->unk_000->unk_18 + 0x100;
    p->unk_36C = p->unk_000->unk_18 - 0x400;
    p->unk_01C = p->unk_000->unk_1C - 0x2200;
    p->unk_138 = p->unk_000->unk_1C + 0x900;
    p->unk_254 = p->unk_000->unk_1C - 0x2100;
    p->unk_370 = p->unk_000->unk_1C - 0x1E00;
}

void func_080B8508(WlogoTtEffTop* p) {
    p->unk_128 = 0;
    p->unk_244 = 0;
    p->unk_35C = gUnk_09EF397C[0];
    p->unk_478 = gUnk_09EF3960[0];
    p->unk_000->unk_14 = p->unk_000->unk_08;
    p->unk_000->unk_18 = p->unk_000->unk_0C;
    p->unk_000->unk_1C = p->unk_000->unk_10;
    func_080B8418(p);
}

void func_080B8554(WlogoTtEffTop* p) {
    WlogoTtEffSrc* src;
    s32 dz;

    p->unk_128 = 226;
    p->unk_244 = 226;
    p->unk_35C = gUnk_09EF397C[0];
    p->unk_478 = gUnk_09EF3960[0];
    dz = 0xF00;
    src = p->unk_000;

    if (src->unk_28 & 0x20) {
        p->unk_000->unk_14 = p->unk_000->unk_08 - 0xA00;
        p->unk_000->unk_18 = p->unk_000->unk_0C;
        p->unk_000->unk_1C = p->unk_000->unk_10 + dz;
        p->unk_014 = p->unk_000->unk_08 - 0xF00;
        p->unk_130 = p->unk_000->unk_14 + 0x500;
        p->unk_24C = p->unk_000->unk_14 + 0x400;
        p->unk_368 = p->unk_000->unk_14 - 0x900;
    } else {
        p->unk_000->unk_14 = p->unk_000->unk_08 + 0xA00;
        p->unk_000->unk_18 = p->unk_000->unk_0C;
        p->unk_000->unk_1C = p->unk_000->unk_10 + 0xF00;
        p->unk_014 = p->unk_000->unk_08 + 0xF00;
        p->unk_130 = p->unk_000->unk_14 - 0x500;
        p->unk_24C = p->unk_000->unk_14 - 0x400;
        p->unk_368 = p->unk_000->unk_14 + 0x900;
    }
    p->unk_01C = p->unk_000->unk_1C - 0x1F00;
    p->unk_138 = p->unk_000->unk_1C + 0xE00;
    p->unk_254 = p->unk_000->unk_1C - 0x1F00;
    p->unk_370 = p->unk_000->unk_1C - 0x1C00;
}

void func_080B8688(WlogoTtEffTop* p) {
    p->unk_128 = 30;
    p->unk_244 = 10;
    p->unk_35C = gUnk_09EF397C[0];
    p->unk_478 = gUnk_09EF3960[0];

    if (p->unk_000->unk_28 & 0x20) {
        p->unk_000->unk_14 = p->unk_000->unk_08 + 0xA00;
        p->unk_000->unk_18 = p->unk_000->unk_0C;
        p->unk_000->unk_1C = p->unk_000->unk_10 + 0xF00;
        p->unk_014 = p->unk_000->unk_08 + 0xB00;
        p->unk_130 = p->unk_000->unk_14 - 0x500;
        p->unk_24C = p->unk_000->unk_14 + 0x900;
        p->unk_368 = p->unk_000->unk_14 - 0x400;
    } else {
        p->unk_000->unk_14 = p->unk_000->unk_08 - 0xA00;
        p->unk_000->unk_18 = p->unk_000->unk_0C;
        p->unk_000->unk_1C = p->unk_000->unk_10 + 0xF00;
        p->unk_014 = p->unk_000->unk_08 - 0xB00;
        p->unk_130 = p->unk_000->unk_14 + 0x500;
        p->unk_24C = p->unk_000->unk_14 - 0x900;
        p->unk_368 = p->unk_000->unk_14 + 0x400;
    }
    p->unk_01C = p->unk_000->unk_1C - 0x2200;
    p->unk_138 = p->unk_000->unk_1C + 0x900;
    p->unk_254 = p->unk_000->unk_1C - 0x1F00;
    p->unk_370 = p->unk_000->unk_1C - 0x1C00;
}

void func_080B87C0(WlogoTtEffTop* p, s16 a) {
    if (p->unk_000->unk_28 & 0x20) {
        p->unk_128 += gUnk_09EF1E14[a].unk_04;
        p->unk_244 += gUnk_09EF1E14[a].unk_0C;
        p->unk_014 += gUnk_09EF1E14[a].unk_00 << 8;
        p->unk_130 += gUnk_09EF1E14[a].unk_08 << 8;
        p->unk_24C += gUnk_09EF1E14[a].unk_10 << 8;
        p->unk_368 += gUnk_09EF1E14[a].unk_18 << 8;
        p->unk_000->unk_14 += gUnk_09EF1E14[a].unk_10 << 8;
    } else {
        p->unk_128 += gUnk_09EF1E14[a].unk_04;
        p->unk_244 += gUnk_09EF1E14[a].unk_0C;
        p->unk_014 -= gUnk_09EF1E14[a].unk_00 << 8;
        p->unk_130 -= gUnk_09EF1E14[a].unk_08 << 8;
        p->unk_24C -= gUnk_09EF1E14[a].unk_10 << 8;
        p->unk_368 -= gUnk_09EF1E14[a].unk_18 << 8;
        p->unk_000->unk_14 -= gUnk_09EF1E14[a].unk_10 << 8;
    }
    p->unk_01C += gUnk_09EF1E14[a].unk_02 << 8;
    p->unk_138 += gUnk_09EF1E14[a].unk_0A << 8;
    p->unk_254 += gUnk_09EF1E14[a].unk_12 << 8;
    p->unk_370 += gUnk_09EF1E14[a].unk_1A << 8;
    p->unk_000->unk_1C += gUnk_09EF1E14[a].unk_0A << 8;
    p->unk_35C = gUnk_09EF397C[gUnk_09EF1E14[a].unk_16];
    p->unk_478 = gUnk_09EF3960[gUnk_09EF1E14[a].unk_1E];
}

void func_080B895C(WlogoTtEffTop* p) {
    p->unk_128 = 0;
    p->unk_244 = 0;
    p->unk_35C = gUnk_09EF397C[0];
    p->unk_478 = gUnk_09EF3960[0];
    p->unk_000->unk_14 = p->unk_000->unk_08;
    p->unk_000->unk_18 = p->unk_000->unk_0C;
    p->unk_000->unk_1C = p->unk_000->unk_10 - 0x1500;
    func_080B8418(p);
}

INCLUDE_ASM("wlogo/func_080B89B0.s");
INCLUDE_ASM("wlogo/func_080B8FF4.s");
INCLUDE_ASM("wlogo/func_080B91A4.s");
void _080B949C(WlogoBtlObj* a, WlogoTtEffTop* b) {
    u16 t;

    if (a->unk_02C <= 0) {
        return;
    }

    if (b->unk_000->unk_08 < 0x8E00 || b->unk_000->unk_08 > 0x16F00) {
        a->unk_034 |= 0x100;
    } else {
        a->unk_034 &= ~0x100;
    }

    switch (func_0801ADAC(a)) {
    case 5:
        func_080B8324(b);
        func_080B9FC4(b);
        func_080B91A4(b);
        b->unk_000->unk_28 &= ~1;
        break;
    case 4:
        b->unk_000->unk_38 = 0;
        b->unk_000->unk_2C = 14;
        break;
    case 1:
    case 6:
    case 7:
        b->unk_48A = a->unk_02C;
        b->unk_000->unk_28 |= 1;
        b->unk_000->unk_30++;

        if (b->unk_48C - b->unk_48A >= 9999) {
            b->unk_000->unk_32 = 55;
            b->unk_000->unk_2C = 12;
            b->unk_000->unk_28 &= ~4;
        } else if (b->unk_000->unk_2C != 12) {
            b->unk_000->unk_32 = 20;
            b->unk_000->unk_28 |= 4;
        }
        break;
    case 3:
    case 8:
        func_0801AF4C(a);
        b->unk_000->unk_34 = 0;
        b->unk_000->unk_2C = 13;
        break;
    }

    if (b->unk_000->unk_28 & 1) {
        b->unk_000->unk_32--;

        if ((s16)b->unk_000->unk_32 <= 0) {
            b->unk_000->unk_30 = 0;
            b->unk_000->unk_28 &= ~1;
            func_0801AF08(a);

            if (b->unk_000->unk_28 & 4) {
                b->unk_000->unk_28 &= ~4;
            } else {
                func_080B8324(b);
                t = b->unk_000->unk_28 & 0x40;

                if (t) {
                    func_080B895C(b);
                    b->unk_000->unk_2C = 8;
                } else {
                    func_080B8508(b);
                    b->unk_000->unk_2C = 0;
                }
            }
        }
    }
    b->unk_48C = a->unk_02C;
}
