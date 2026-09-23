#include "macros.h"
#include "registration_data.h"
#include "chara_api.h"
#include "intr.h"
#include "pallet.h"
#include "wlogo.h"
#include "boss_tm_assets.h"
#include "sprites_boss_tm.h"
#include "sprites_wlogo.h"

extern const WlogoHwtObjA gUnk_096194D0[6];
extern const WlogoHwtObjB gUnk_09619530[6][6];
extern const WlogoHwtObjB gUnk_096198D4[4];

extern WlogoWonEntry gUnk_09EF167C[];
extern WlogoWonEntry gUnk_09EF1744[];
extern s32 gUnk_09EF180C[];
extern WlogoAgrEntry gUnk_09EF191C[];
extern WlogoTtMotion gUnk_09EF1B08;
extern s16 gUnk_09EF1B68[][3];
extern s8 gUnk_09EF1C48[];
extern s8 gUnk_09EF1C50[];
extern u8 gUnk_09EF1C70[];
extern s16 gUnk_09EF1C7E[][2];
extern s16 gUnk_09EF1CB6[][2];
extern s16 gUnk_09EF1CEE[];
extern u16 gUnk_09EF1D0A[];
extern u8 gUnk_09EF1AEC[];

static TaskPool gWlogoHwtTaskPool;
static TaskPool gWlogoNvlTaskPool;
static TaskPool gWlogoNvlMovTaskPool;
static TaskPool gWlogoAgrTaskPool;
static TaskPool gWlogoPooTaskPool;
s32 gUnk_0203AB38 EWRAM_COMMON(4);

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
    work->state = 0;
    work->unk_02D = 0;
    work->unk_02E = 0;
    SetBgBlend(0, 16, 0);
    AnimInit(&work->anim, gUnk_09EF3544, gUnk_09EF351C);
    AnimStart(&work->anim, 0, 0);
    work->gfx = AnimGetGfx(&work->anim);
}

u8 task_wlogo_mons_1(WlogoMonsWork* work) {
    switch (work->state) {
    case 0:
        work->unk_02A++;
        if (work->unk_02A > 29) {
            work->unk_02A = 0;
            work->state++;
        }
        break;
    case 1:
        work->unk_02A++;
        if (work->unk_02A > 4) {
            work->unk_02A = 0;
            work->unk_02E++;
            if (work->unk_02E > 15) {
                work->unk_02E = 16;
                work->state++;
            }
            SetBgBlend(0, 16 - work->unk_02E, work->unk_02E);
        }
        break;
    case 2:
        work->unk_02A++;
        if (work->unk_02A > 29) {
            work->unk_02A = 0;
            work->unk_02D = 1;
            work->state++;
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
                LoadObjPaletteBank(work->palette->index, &gUnk_096FACC4[work->unk_028 * 32]);
                LoadPaletteWithEffect(&gUnk_096FACC4[work->unk_028 * 32], (void*)0x050001C0, 0x20);
            } else if (work->unk_028 > 11) {
                if (work->unk_028 <= 15) {
                    LoadObjPaletteBank(work->palette->index, &gUnk_096FACC4[(15 - work->unk_028) * 32]);
                    LoadPaletteWithEffect(&gUnk_096FACC4[(15 - work->unk_028) * 32], (void*)0x050001C0, 0x20);
                } else if (work->unk_028 == 20) {
                    work->unk_02D = 0;
                    RequestDma3Copy(gUnk_096B7464, GetBgScreenBase(0), 0x800);
                    work->state++;
                }
            }
            work->unk_028++;
        }
        break;
    case 4:
        work->unk_02A++;
        if (work->unk_02A > 49) {
            work->unk_02A = 0;
            work->state++;
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
    work->state = 0;
    work->unk_005 = 0;
    SetBgBlend(0, 16, 0);
    TaskPoolInit(&gWlogoHwtTaskPool, 4);
}

u8 task_wlogo_hwt_1(WlogoHwtWork* work) {
    switch (work->state) {
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
            work->state++;
        }
        break;
    case 1:
        work->unk_002++;
        if (work->unk_002 > 4) {
            work->unk_002 = 0;
            work->unk_005++;
            if (work->unk_005 > 15) {
                work->unk_005 = 16;
                work->state++;
            }
            SetBgBlend(0, 16 - work->unk_005, work->unk_005);
        }
        break;
    case 2:
        work->unk_002++;
        if (work->unk_002 > 119) {
            work->unk_002 = 0;
            work->state++;
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
                work->state++;
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
        work->gfx[i] = gUnk_09EF3924[i];
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
    work->state = 0;
    work->unk_0F3 = 0;
    SetBgBlend(0, 16, 0);
}

u8 task_wlogo_won_1(WlogoWonWork* work) {
    s32 i;

    switch (work->state) {
    case 0:
        work->unk_008++;
        if (work->unk_008 > 9) {
            work->unk_008 = 0;
            work->state++;
        }
        break;
    case 1:
        for (i = 0; i < 10; i++) {
            if (work->unk_0C0[i] == 0) {
                if (work->unk_0AC[i] > gUnk_09EF1744[i].unk_0C) {
                    work->unk_0C0[i]++;
                    work->unk_0AC[i] = 0;
                }
                work->unk_0AC[i]++;
                continue;
            }
            if (work->unk_0AC[i] > gUnk_09EF1744[i].unk_0E) {
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
            work->state++;
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
        }
        SetBgBlend(0, 16 - work->unk_0F3, work->unk_0F3);
        break;
    }
    return 1;
}

void task_wlogo_won_2(WlogoWonWork* work) {
    s32 i;
    s32 affine;

    if (work->state == 1) {
        for (i = 0; i < 10; i++) {
            affine = AllocObjAffine(work->unk_00A, gUnk_09EF180C[work->unk_0CA[i]], 0x100, 0);
            DrawSprite(work->x[i] >> 8, work->y[i] >> 8, work->gfx[i], work->tiles, work->palette, affine, 0, gUnk_09EF167C[i].unk_10);
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
    work->state = 0;
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
    switch (work->state) {
    case 0:
        work->unk_002++;
        if (work->unk_002 > 29) {
            work->unk_002 = 0;
            EnableBgWave(0);
            work->state++;
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
                work->state++;
            }
            SetBgBlend(0, 16 - work->unk_008, work->unk_008);
        }
        break;
    case 2:
        work->unk_002++;
        if (work->unk_002 > 113) {
            work->unk_002 = 0;
            work->state++;
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
    work->state = 0;
    work->unk_00A = 0;
    work->unk_004 = 0;
    work->unk_006 = 0;
    work->unk_008 = 0;
    SetBgBlend(0, 16, 0);
    TaskPoolInit(&gWlogoNvlTaskPool, 4);
}

u8 task_wlogo_nvl_1(WlogoNvlWork* work) {
    switch (work->state) {
    case 0:
        work->unk_002++;
        if (work->unk_002 > 29) {
            work->unk_002 = 0;
            work->state++;
        }
        break;
    case 1:
        work->unk_002++;
        if (work->unk_002 > 5) {
            work->unk_002 = 0;
            work->unk_00A++;
            if (work->unk_00A > 15) {
                work->unk_00A = 16;
                work->state++;
            }
            SetBgBlend(0, 16 - work->unk_00A, work->unk_00A);
        }
        break;
    case 2:
        work->unk_002++;
        if (work->unk_002 > 113) {
            work->unk_002 = 0;
            work->state++;
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
            arg.x = work->x;
            arg.y = work->y;
            arg.unk_08 = work->unk_020;
            TaskCreate(&gWlogoNvlMovTaskPool, &gTaskDescWlogoNvlObj, &arg);
            work->unk_020 = 1 - work->unk_020;
        }
        work->gfx = AnimUpdate(&work->anim);

        if (work->unk_01E == 40) {
            AnimChangeWithTables(&work->anim, 2, 0, gUnk_09EF35A4, gUnk_09EF3574);
        }

        if (work->unk_01E == 55) {
            AnimChangeWithTables(&work->anim, 4, 0, gUnk_09EF35A4, gUnk_09EF3574);
        }

        if (work->unk_01E == 75) {
            AnimChangeWithTables(&work->anim, 2, 0, gUnk_09EF35A4, gUnk_09EF3574);
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
    work->x = arg->x;
    work->y = arg->y;
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
    work->x = gUnk_0961C792.unk_00;
    work->y = gUnk_0961C792.unk_02;
    work->unk_02A = 0;
    work->state = 0;
    work->unk_030 = 0;
    work->unk_02C = 0;
    work->unk_02E = 0;
    work->unk_031 = 0;
    SetBgBlend(0, 16 - work->unk_030, work->unk_030);
    AnimInit(&work->anim, gUnk_09EF3610, gUnk_09EF35B8);
    AnimStart(&work->anim, 0, 0);
    work->gfx = AnimGetGfx(&work->anim);
}

u8 task_wlogo_col_1(WlogoColWork* work) {
    switch (work->state) {
    case 0:
        work->unk_02A++;
        if (work->unk_02A > 9) {
            work->unk_02A = 0;
            work->unk_031 = 1;
            work->state++;
        }
        break;
    case 1:
        if (AnimIsFinished(&work->anim)) {
            work->unk_031 = 0;
            work->state++;
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
                work->state++;
            }
            SetBgBlend(0, 16 - work->unk_030, work->unk_030);
        }
        break;
    case 3:
        if (++work->unk_02A > 120) {
            work->unk_02A = 0;
            work->state++;
        }
        if (++work->unk_02E > 4) {
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
    work->state = 0;
    work->unk_004 = 0;
    SetBgBlend(0, 16, 0);
}

u8 task_wlogo_hlw_1(WlogoHlwWork* work) {
    switch (work->state) {
    case 0:
        work->unk_002++;
        if (work->unk_002 > 29) {
            work->unk_002 = 0;
            work->state++;
        }
        break;
    case 1:
        work->unk_002++;
        if (work->unk_002 > 5) {
            work->unk_002 = 0;
            work->unk_004++;
            if (work->unk_004 > 15) {
                work->unk_004 = 16;
                work->state++;
            }
            SetBgBlend(0, 16 - work->unk_004, work->unk_004);
        }
        break;
    case 2:
        work->unk_002++;
        if (work->unk_002 > 113) {
            work->unk_002 = 0;
            work->state++;
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
    work->state = 0;
    work->unk_010 = 0;
    SetBgBlend(0, 16, 0);
}

u8 task_wlogo_dil_1(WlogoDilWork* work) {
    switch (work->state) {
    case 0:
        work->unk_00E++;
        if (work->unk_00E > 29) {
            work->unk_00E = 0;
            work->state++;
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
                work->state++;
            }
            SetBgBlend(0, 16 - work->unk_010, work->unk_010);
        }
        break;
    case 2:
        LoadBgMap(0, gUnk_096BBC64, 0x800);
        work->unk_010 = 0;
        SetBgBlend(0, 16, 0);
        work->state++;
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
                work->state++;
            }
            SetBgBlend(0, 16 - work->unk_010, work->unk_010);
        }
        break;
    case 4:
        work->unk_00E++;
        if (work->unk_00E > 113) {
            work->unk_00E = 0;
            work->state++;
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
    work->state = 0;
    work->unk_014 = 0;
    work->unk_016 = 0;
    SetBgBlend(0, 16, 0);
    TaskPoolInit(&gWlogoAgrTaskPool, 50);
}

u8 task_wlogo_agr_1(WlogoAgrWork* work) {
    WlogoAgrEntry a;
    WlogoAgrEntry b;

    switch (work->state) {
    case 0:
        work->unk_012++;
        if (work->unk_012 > 29) {
            work->unk_012 = 0;
            work->state++;
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
                work->state++;
            }
            SetBgBlend(0, 16 - work->unk_016, work->unk_016);
        }
        break;
    case 2:
        LoadBgMap(0, gUnk_096BA464, 0x800);
        work->unk_016 = 0;
        SetBgBlend(0, 16, 0);
        work->state++;
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
                work->state++;
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
            work->state++;
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
    work->state = 0;
    work->unk_030 = 0;
    work->unk_02C = 0;
    work->unk_02E = 0;
    work->unk_028 = 0;
    SetBgBlend(0, 16 - work->unk_030, work->unk_030);
    AnimInit(&work->anim, gUnk_09EF3730, gUnk_09EF36D8);
    AnimStart(&work->anim, 0, 0);
    work->gfx = AnimGetGfx(&work->anim);
}

u8 task_wlogo_tvt_1(WlogoTvtWork* work) {
    switch (work->state) {
    case 0:
        if (++work->unk_02A > 29) {
            work->unk_02A = 0;
            work->state++;
        }
        break;
    case 1:
        if (++work->unk_02E > 44) {
            work->unk_02E = 0;
            work->unk_02C = 1 - work->unk_02C;
            RequestDma3Copy(&gUnk_096474A4[work->unk_02C * 1024], (u8*)GetBgCharBase(0) + 32, 0x320);
        }
        if (++work->unk_02A > 3) {
            work->unk_02A = 0;
            work->unk_030++;
            if (work->unk_030 > 15) {
                work->unk_030 = 16;
                work->state++;
            }
            SetBgBlend(0, 16 - work->unk_030, work->unk_030);
        }
        break;
    case 2:
        if (++work->unk_02E > 44) {
            work->unk_02E = 0;
            work->unk_02C = 1 - work->unk_02C;
            RequestDma3Copy(&gUnk_096474A4[work->unk_02C * 1024], (u8*)GetBgCharBase(0) + 32, 0x320);
        }
        if (++work->unk_02A > 89) {
            work->unk_02A = 0;
            work->unk_028 = 1;
            work->state++;
        }
        break;
    case 3:
        if (++work->unk_02E > 44) {
            work->unk_02E = 0;
            work->unk_02C = 1 - work->unk_02C;
            RequestDma3Copy(&gUnk_096474A4[work->unk_02C * 1024], (u8*)GetBgCharBase(0) + 32, 0x320);
        }

        if (AnimIsFinished(&work->anim)) {
            LoadBgTiles(0, gUnk_09646884, 0xC00);
            work->unk_02C += 2;
            RequestDma3Copy(&gUnk_096474A4[work->unk_02C * 1024], (u8*)GetBgCharBase(0) + 32, 0x320);
            work->unk_028 = 0;
            work->state++;
        } else {
            work->gfx = AnimUpdate(&work->anim);
        }
        break;
    case 4:
        if (++work->unk_02E > 44) {
            work->unk_02E = 0;
            work->unk_02C = 5 - work->unk_02C;
            RequestDma3Copy(&gUnk_096474A4[work->unk_02C * 1024], (u8*)GetBgCharBase(0) + 32, 0x320);
        }
        if (++work->unk_02A > 113) {
            work->unk_02A = 0;
            work->unk_02C = 2;
            work->state++;
        }
        break;
    case 5:
        if (++work->unk_02E > 44) {
            work->unk_02E = 0;
            work->unk_02C = 5 - work->unk_02C;
            RequestDma3Copy(&gUnk_096474A4[work->unk_02C * 1024], (u8*)GetBgCharBase(0) + 32, 0x320);
        }
        if (++work->unk_02A > 4) {
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
    work->state = 0;
    work->unk_008 = 0;
    work->unk_004 = 0;
    work->unk_006 = 0;
    SetBgBlend(0, 16, 0);
    TaskPoolInit(&gWlogoPooTaskPool, 4);
}

u8 task_wlogo_poo_1(WlogoPooWork* work) {
    switch (work->state) {
    case 0:
        work->unk_002++;
        if (work->unk_002 > 29) {
            work->unk_002 = 0;
            work->state++;
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
                work->state++;
            }
            SetBgBlend(0, 16 - work->unk_008, work->unk_008);
        }
        break;
    case 2:
        work->unk_002++;
        if (work->unk_002 > 113) {
            work->unk_002 = 0;
            work->state++;
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
    work->state = 0;
    work->unk_006 = 0;
    work->unk_007 = 0;
    work->unk_108 = 51;
    work->unk_10C = 51;
    SetBgBlend(0, 16 - work->unk_006, work->unk_006);
    work->tiles = AllocObjTiles(0x200, gUnk_09624F72);
    work->tiles2 = AllocObjTiles(0x200, gUnk_09624F72);
    work->tiles3 = AllocObjTiles(0x200, gUnk_09624F72);
    work->tiles4 = AllocObjTiles(0x3C0, gUnk_09624F72);
    work->tiles5 = LoadObjTiles(gUnk_0962848A, 0x7C0);
    work->palette = LoadObjPalette(gUnk_096FAE84, 0x20);
    LoadObjPaletteBank(work->palette->index, &gUnk_096FAEA4[work->unk_007 * 32]);
    AnimInit(&work->anim[0], gUnk_09EF37DC, gUnk_09EF377C);
    AnimStart(&work->anim[0], 1, 0);
    work->gfx = AnimGetGfx(&work->anim[0]);
    AnimInit(&work->anim[1], gUnk_09EF37DC, gUnk_09EF377C);
    AnimStart(&work->anim[1], 2, 0);
    work->gfx2 = AnimGetGfx(&work->anim[1]);
    AnimInit(&work->anim[2], gUnk_09EF37DC, gUnk_09EF377C);
    AnimStart(&work->anim[2], 4, 0);
    work->gfx3 = AnimGetGfx(&work->anim[2]);
    AnimInit(&work->anim[3], gUnk_09EF37DC, gUnk_09EF377C);
    AnimStart(&work->anim[3], 4, 0);
    work->gfx4 = AnimGetGfx(&work->anim[3]);
    AnimInit(&work->anim[4], gUnk_09EF37DC, gUnk_09EF377C);
    AnimStart(&work->anim[4], 0, 0);
    work->gfx5 = AnimGetGfx(&work->anim[4]);
    AnimInit(&work->anim[5], gUnk_09EF37DC, gUnk_09EF377C);
    AnimStart(&work->anim[5], 0, 0);
    work->gfx6 = AnimGetGfx(&work->anim[5]);
    work->gfx7 = gUnk_09EF37F4[0];

    for (i = 0; i < 8; i++) {
        work->unk_100[i] = 0;
    }
    TaskPoolInit(&work->tasks, 1);
    WlogoEnableHBlank();
    gUnk_0203AB38 = -0x299;
    work->unk_110 = 25;
}

u8 task_wlogo_tt_1(WlogoTtWork* work) {
    switch (work->state) {
    case 0:
        work->unk_002++;
        if (work->unk_002 > 29) {
            work->unk_002 = 0;
            work->state++;
        }
        break;
    case 1:
        work->unk_002++;
        if (work->unk_002 > 3) {
            work->unk_002 = 0;
            work->unk_006++;
            if (work->unk_006 > 15) {
                work->unk_006 = 16;
                work->state++;
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
            work->state++;
        }
        break;
    case 3:
        work->gfx3 = AnimUpdate(&work->anim[2]);

        if (work->unk_002 > 13) {
            work->unk_002 = 0;
            work->unk_004 = 0;
            work->unk_108 = gUnk_09EF1B08.first[0];
            work->unk_100[0] = 1;
            work->state++;
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
            work->unk_108 = gUnk_09EF1B08.first[work->unk_004];
        }
        work->unk_002++;

        if (AnimIsFinished(&work->anim[2])) {
            work->unk_100[2] = 0;
            work->unk_100[3] = 1;
            work->unk_002 = 0;
            work->state++;
        } else {
            work->gfx = AnimUpdate(&work->anim[0]);
            work->gfx3 = AnimUpdate(&work->anim[2]);
        }
        break;
    case 5:
        work->gfx4 = AnimUpdate(&work->anim[3]);

        if (work->unk_002 > 13) {
            work->unk_002 = 0;
            work->unk_004 = 0;
            work->unk_10C = gUnk_09EF1B08.second[0];
            work->unk_100[1] = 1;
            work->state++;
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
            work->unk_10C = gUnk_09EF1B08.second[work->unk_004];
        }
        work->unk_002++;

        if (AnimIsFinished(&work->anim[3])) {
            work->unk_100[3] = 0;
            work->unk_100[4] = 1;
            work->unk_100[5] = 1;
            work->unk_100[6] = 1;
            TaskCreate(&work->tasks, &gTaskDescWlogoTtLine, (void*)0);
            work->unk_002 = 0;
            work->unk_004 = 0;
            work->state++;
        } else {
            work->gfx2 = AnimUpdate(&work->anim[1]);
            work->gfx4 = AnimUpdate(&work->anim[3]);
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
                work->state++;
            }
            LoadObjPaletteBank(work->palette->index, &gUnk_096FAEA4[work->unk_007 * 32]);
        } else {
            work->unk_004++;
        }
        work->gfx5 = AnimUpdate(&work->anim[4]);
        work->gfx6 = AnimUpdate(&work->anim[5]);
        break;
    case 8:
        if (work->unk_004 > 1) {
            work->unk_004 = 0;
            work->unk_007++;
            if (work->unk_007 > 8) {
                work->state++;
            } else {
                LoadObjPaletteBank(work->palette->index, &gUnk_096FAEA4[work->unk_007 * 32]);
            }
        } else {
            work->unk_004++;
        }
        work->gfx5 = AnimUpdate(&work->anim[4]);
        work->gfx6 = AnimUpdate(&work->anim[5]);
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
        work->gfx5 = AnimUpdate(&work->anim[4]);
        work->gfx6 = AnimUpdate(&work->anim[5]);
        work->state++;
        break;
    case 10:
        if (AnimIsFinished(&work->anim[4])) {
            work->unk_100[4] = 0;
            work->unk_100[5] = 0;
            work->unk_004 = 0;
            work->unk_002 = 0;
            work->unk_007 = 8;
            work->state++;
        } else {
            work->gfx5 = AnimUpdate(&work->anim[4]);
            work->gfx6 = AnimUpdate(&work->anim[5]);
        }
        break;
    case 11:
        if (work->unk_007 == 4) {
            work->unk_002 = 0;
            work->state++;
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
            work->state++;
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
    default:
        return 0;
    }
    TaskPoolUpdate(&work->tasks);
    return 1;
}

void task_wlogo_tt_2(WlogoTtWork* work) {
    s32 affine;

    if (work->unk_100[4] == 1) {
        DrawSprite(72, 64, work->gfx5, work->tiles, work->palette, 0, 0, 4);
    }

    if (work->unk_100[5] == 1) {
        DrawSprite(96, 80, work->gfx6, work->tiles, work->palette, 0, 0, 6);
    }

    if (work->unk_100[0] == 1) {
        affine = AllocObjAffine(0, work->unk_108, 0x100, 0);
        DrawSprite(78, 72, work->gfx, work->tiles2, work->palette, affine, 0, 24);
    }

    if (work->unk_100[2] == 1) {
        DrawSprite(65, 65, work->gfx3, work->tiles4, work->palette, 0, 0, 20);
    }

    if (work->unk_100[1] == 1) {
        affine = AllocObjAffine(0, work->unk_10C, 0x100, 0);
        DrawSprite(108, 94, work->gfx2, work->tiles3, work->palette, affine, 0, 26);
    }

    if (work->unk_100[3] == 1) {
        DrawSprite(96, 87, work->gfx4, work->tiles4, work->palette, 0, 0, 22);
    }

    if (work->unk_100[6] == 1) {
        DrawSprite(64, 64, work->gfx7, work->tiles5, work->palette, 0, 0, 32);
    }
    TaskPoolDraw(&work->tasks);
}

void task_wlogo_tt_3(WlogoTtWork* work) {
    WlogoDisableHBlank();
    TaskPoolDestroy(&work->tasks);
    ReleaseObjTiles(work->tiles);
    ReleaseObjTiles(work->tiles2);
    ReleaseObjTiles(work->tiles3);
    ReleaseObjTiles(work->tiles4);
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
    work->x = arg->x;
    work->y = arg->y;
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
    work->state = 0;
    TaskPoolInit(&work->tasks, 33);
}

u8 task_wlogo_tt_line_1(WlogoTtLineWork* work) {
    WlogoTtObjArg arg;

    switch (work->state) {
    case 0:
        if (work->unk_000 == gUnk_09EF1B68[work->unk_002][2]) {
            work->unk_000 = 0;
            arg.x = gUnk_09EF1B68[work->unk_002][0] << 8;
            arg.y = gUnk_09EF1B68[work->unk_002][1] << 8;
            TaskCreate(&work->tasks, &gTaskDescWlogoTtObj, &arg);
            work->unk_002++;
            if (work->unk_002 == 31) {
                work->state++;
            }
        } else {
            work->unk_000++;
        }
        break;
    case 1:
        if (work->unk_000 > 29) {
            work->state++;
        }
        work->unk_000++;
        break;
    default:
        return 0;
    }
    TaskPoolUpdate(&work->tasks);
    return 1;
}

void task_wlogo_tt_line_2(WlogoTtLineWork* work) {
    TaskPoolDraw(&work->tasks);
}

void task_wlogo_tt_line_3(WlogoTtLineWork* work) {
    TaskPoolDestroy(&work->tasks);
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
    TaskPoolInit(&work->tasks, 15);
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
            TaskCreate(&work->tasks, &gTaskDescWlogoBksObj, (void*)13);
            break;
        case 30:
            TaskCreate(&work->tasks, &gTaskDescWlogoBksObj, (void*)12);
            TaskCreate(&work->tasks, &gTaskDescWlogoBksObj, (void*)0);
            break;
        case 40:
            TaskCreate(&work->tasks, &gTaskDescWlogoBksObj, (void*)11);
            TaskCreate(&work->tasks, &gTaskDescWlogoBksObj, (void*)1);
            break;
        case 50:
            TaskCreate(&work->tasks, &gTaskDescWlogoBksObj, (void*)10);
            TaskCreate(&work->tasks, &gTaskDescWlogoBksObj, (void*)2);
            break;
        case 60:
            TaskCreate(&work->tasks, &gTaskDescWlogoBksObj, (void*)9);
            TaskCreate(&work->tasks, &gTaskDescWlogoBksObj, (void*)3);
            break;
        case 70:
            TaskCreate(&work->tasks, &gTaskDescWlogoBksObj, (void*)4);
            TaskCreate(&work->tasks, &gTaskDescWlogoBksObj, (void*)8);
            break;
        case 80:
            TaskCreate(&work->tasks, &gTaskDescWlogoBksObj, (void*)7);
            TaskCreate(&work->tasks, &gTaskDescWlogoBksObj, (void*)5);
            break;
        case 90:
            TaskCreate(&work->tasks, &gTaskDescWlogoBksObj, (void*)6);
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
    TaskPoolUpdate(&work->tasks);
    return 1;
}

void task_wlogo_bks_2(WlogoBksWork* work) {
    if (work->unk_030 == 1) {
        DrawSprite(64, 64, work->gfx, work->tiles, work->palette, 0, 0, 0);
    }
    TaskPoolDraw(&work->tasks);
}

void task_wlogo_bks_3(WlogoBksWork* work) {
    StopBgWave(0);
    TaskPoolDestroy(&work->tasks);
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
    work->state = 0;
    work->unk_046 = 10;
    work->tiles = LoadObjTiles(gUnk_09628DC0, 0x800);
    work->palette = LoadObjPalette(gUnk_096FB0A4, 0x20);
    work->gfx = gUnk_09EF380C[gUnk_09EF1C70[work->unk_029]];
    work->unk_048 = gUnk_09EF1D0A[work->unk_029];
    work->unk_044 = 0;
}

u8 task_wlogo_bks_obj_1(WlogoBksObjWork* work) {
    switch (work->state) {
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
            work->state++;
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

const char gTaskNameWlogoMons[] = "task_wlogo_mons";

const char gTaskNameWlogoHwt[] = "task_wlogo_hwt";

const WlogoHwtObjA gUnk_096194D0[6] = {
    { 17920, 46080, 384, 1, { 0, 0, 0 } },
    { 43520, 46080, 384, 0, { 0, 0, 0 } },
    { 33280, 46080, 384, 1, { 0, 0, 0 } },
    { 30720, 46080, 384, 0, { 0, 0, 0 } },
    { 35840, 19200, 384, 1, { 0, 0, 0 } },
    { 25600, 46080, 384, 0, { 0, 0, 0 } },
};

const WlogoHwtObjB gUnk_09619530[6][6] = {
    {
        { 40, { 0, 0 }, 102, -1536, -2, 51, 0, { 0, 0, 0 } },
        { 40, { 0, 0 }, 51, 128, 2, 0, 0, { 0, 0, 0 } },
        { 30, { 0, 0 }, 102, -768, -2, -25, 1, { 0, 0, 0 } },
        { 0, { 0, 0 }, 0, 0, 0, 0, 0, { 0, 0, 0 } },
        { 0, { 0, 0 }, 0, 0, 0, 0, 0, { 0, 0, 0 } },
        { 0, { 0, 0 }, 0, 0, 0, 0, 0, { 0, 0, 0 } },
    },
    {
        { 30, { 0, 0 }, -102, -1536, 2, 76, 0, { 0, 0, 0 } },
        { 40, { 0, 0 }, -51, 128, -2, 0, 0, { 0, 0, 0 } },
        { 40, { 0, 0 }, -102, -768, 2, -25, 1, { 0, 0, 0 } },
        { 0, { 0, 0 }, 0, 0, 0, 0, 0, { 0, 0, 0 } },
        { 0, { 0, 0 }, 0, 0, 0, 0, 0, { 0, 0, 0 } },
        { 0, { 0, 0 }, 0, 0, 0, 0, 0, { 0, 0, 0 } },
    },
    {
        { 30, { 0, 0 }, 102, -1536, 0, 51, 0, { 0, 0, 0 } },
        { 40, { 0, 0 }, 25, 128, 2, 0, 0, { 0, 0, 0 } },
        { 40, { 0, 0 }, 102, -768, 25, -51, 1, { 0, 0, 0 } },
        { 0, { 0, 0 }, 0, 0, 0, 0, 0, { 0, 0, 0 } },
        { 0, { 0, 0 }, 0, 0, 0, 0, 0, { 0, 0, 0 } },
        { 0, { 0, 0 }, 0, 0, 0, 0, 0, { 0, 0, 0 } },
    },
    {
        { 40, { 0, 0 }, -102, -1484, 0, 38, 0, { 0, 0, 0 } },
        { 40, { 0, 0 }, -25, 128, -2, 0, 0, { 0, 0, 0 } },
        { 30, { 0, 0 }, -102, -768, -25, -51, 1, { 0, 0, 0 } },
        { 0, { 0, 0 }, 0, 0, 0, 0, 0, { 0, 0, 0 } },
        { 0, { 0, 0 }, 0, 0, 0, 0, 0, { 0, 0, 0 } },
        { 0, { 0, 0 }, 0, 0, 0, 0, 0, { 0, 0, 0 } },
    },
    {
        { 30, { 0, 0 }, 51, -512, 0, 25, 0, { 0, 0, 0 } },
        { 40, { 0, 0 }, 25, 76, 2, 0, 0, { 0, 0, 0 } },
        { 30, { 0, 0 }, 51, -384, 5, -51, 1, { 0, 0, 0 } },
        { 0, { 0, 0 }, 0, 0, 0, 0, 0, { 0, 0, 0 } },
        { 0, { 0, 0 }, 0, 0, 0, 0, 0, { 0, 0, 0 } },
        { 0, { 0, 0 }, 0, 0, 0, 0, 0, { 0, 0, 0 } },
    },
    {
        { 120, { 0, 0 }, 0, -384, 0, -25, 1, { 0, 0, 0 } },
        { 40, { 0, 0 }, -25, 128, -2, 0, 0, { 0, 0, 0 } },
        { 40, { 0, 0 }, -51, -358, -25, -51, 1, { 0, 0, 0 } },
        { 0, { 0, 0 }, 0, 0, 0, 0, 0, { 0, 0, 0 } },
        { 0, { 0, 0 }, 0, 0, 0, 0, 0, { 0, 0, 0 } },
        { 0, { 0, 0 }, 0, 0, 0, 0, 0, { 0, 0, 0 } },
    },
};

const char gTaskNameWlogoHwtObj[] = "task_wlogo_hwt_obj";

const char gTaskNameWlogoWon[] = "task_wlogo_won";

const char gTaskNameWlogoAtl[] = "task_wlogo_atl";

const char gTaskNameWlogoNvl[] = "task_wlogo_nvl";

const WlogoHwtObjB gUnk_096198D4[4] = {
    { 20, { 0, 0 }, 768, 256, -5, -12, 0, { 0, 0, 0 } },
    { 20, { 0, 0 }, 921, -51, -46, -25, 0, { 0, 0, 0 } },
    { 20, { 0, 0 }, 0, -512, -46, 23, 0, { 0, 0, 0 } },
    { 20, { 0, 0 }, -921, -115, 19, -5, 1, { 0, 0, 0 } },
};

const char gTaskNameWlogoNvlMov[] = "task_wlogo_nvl_mov";

const char gTaskNameWlogoNvlObj[] = "task_wlogo_nvl_obj";

const char gTaskNameWlogoCol[] = "task_wlogo_col";

const char gTaskNameWlogoHlw[] = "task_wlogo_hlw";

const char gTaskNameWlogoDil[] = "task_wlogo_dil";

const char gTaskNameWlogoAgr[] = "task_wlogo_agr";

const char gTaskNameWlogoAgrSmoke[] = "task_wlogo_agr_smoke";

const char gTaskNameWlogoAgrFlash0[] = "task_wlogo_agr_flash0";

const char gTaskNameWlogoAgrFlash1[] = "task_wlogo_agr_flash1";

const char gTaskNameWlogoTvt[] = "task_wlogo_tvt";

const char gTaskNameWlogoPoo[] = "task_wlogo_poo";

const WlogoPooObjStep gUnk_09619A04[5][5] = {
    {
        { 20, { 0, 0 }, -128, 0, 0, -2 },
        { 20, { 0, 0 }, -128, -51, 0, -2 },
        { 20, { 0, 0 }, -128, -102, 0, -2 },
        { 20, { 0, 0 }, -128, -153, 0, -2 },
        { 10, { 0, 0 }, -128, -204, 0, 0 },
    },
    {
        { 20, { 0, 0 }, -128, 0, 0, 5 },
        { 20, { 0, 0 }, -128, 0, 0, -5 },
        { 20, { 0, 0 }, -128, 0, 0, 5 },
        { 20, { 0, 0 }, -128, 0, 0, -7 },
        { 10, { 0, 0 }, -128, -25, 0, 0 },
    },
    {
        { 20, { 0, 0 }, 128, 0, 0, -5 },
        { 20, { 0, 0 }, 128, 0, 0, 7 },
        { 20, { 0, 0 }, 128, 0, 0, -5 },
        { 20, { 0, 0 }, 128, 0, 0, 2 },
        { 10, { 0, 0 }, 128, -51, 0, 0 },
    },
    {
        { 20, { 0, 0 }, 128, 0, 0, 5 },
        { 20, { 0, 0 }, 128, 51, 0, 2 },
        { 20, { 0, 0 }, 128, 76, 0, -5 },
        { 20, { 0, 0 }, 128, 25, 0, -2 },
        { 10, { 0, 0 }, 128, 25, 0, 0 },
    },
    {
        { 0, { 0, 0 }, 0, 0, 0, 0 },
        { 0, { 0, 0 }, 0, 0, 0, 0 },
        { 0, { 0, 0 }, 0, 0, 0, 0 },
        { 0, { 0, 0 }, 0, 0, 0, 0 },
        { 0, { 0, 0 }, 0, 0, 0, 0 },
    },
};

const char gTaskNameWlogoPooObj[] = "task_wlogo_poo_obj";

const char gTaskNameWlogoTt[] = "task_wlogo_tt";

const char gTaskNameWlogoTtObj[] = "task_wlogo_tt_obj";

const char gTaskNameWlogoTtLine[] = "task_wlogo_tt_line";

const char gTaskNameWlogoBks[] = "task_wlogo_bks";

const char gTaskNameWlogoBksObj[] = "task_wlogo_bks_obj";

TaskDesc gTaskDescWlogoMons = {
    gTaskNameWlogoMons,
    (void (*)(void*, void*))task_wlogo_mons_0,
    task_wlogo_mons_1,
    (void (*)(void*))task_wlogo_mons_2,
    (void (*)(void*))task_wlogo_mons_3,
    0x30,
};

TaskDesc gTaskDescWlogoHwt = {
    gTaskNameWlogoHwt,
    (void (*)(void*, void*))task_wlogo_hwt_0,
    task_wlogo_hwt_1,
    (void (*)(void*))task_wlogo_hwt_2,
    (void (*)(void*))task_wlogo_hwt_3,
    0x8,
};

TaskDesc gTaskDescWlogoHwtObj = {
    gTaskNameWlogoHwtObj,
    (void (*)(void*, void*))task_wlogo_hwt_obj_0,
    task_wlogo_hwt_obj_1,
    (void (*)(void*))task_wlogo_hwt_obj_2,
    (void (*)(void*))task_wlogo_hwt_obj_3,
    0x4C,
};

WlogoWonEntry gUnk_09EF167C[10] = {
    {65280, 18432, 768, 10, 59, 35, 11},
    {64768, 18432, 819, 30, 50, 34, 15},
    {64768, 18432, 972, 46, 38, 33, 1},
    {65024, 18432, 1075, 72, 31, 32, 5},
    {64768, 18432, 1177, 90, 25, 31, 8},
    {64768, 18432, 1280, 100, 20, 30, 10},
    {65024, 22528, 1024, 60, 34, 28, 3},
    {64512, 22528, 1126, 82, 27, 27, 7},
    {65024, 22528, 1228, 96, 22, 26, 9},
    {64512, 22528, 1331, 104, 17, 25, 12},
};

WlogoWonEntry gUnk_09EF1744[10] = {
    {-2560, 18432, -512, 85, 44, 35, 18},
    {-2816, 18432, -512, 70, 52, 34, 14},
    {-3072, 18432, -512, 55, 60, 33, 10},
    {-3328, 18432, -512, 40, 68, 32, 6},
    {-3584, 18432, -512, 25, 76, 31, 2},
    {-3840, 18432, -512, 10, 84, 30, 18},
    {65024, 22528, 512, 40, 68, 28, 6},
    {64768, 22528, 512, 55, 60, 27, 10},
    {64512, 22528, 512, 70, 52, 26, 14},
    {64256, 22528, 512, 85, 44, 25, 18},
};

s32 gUnk_09EF180C[20] = {
    256,
    235,
    204,
    153,
    110,
    25,
    -110,
    -153,
    -204,
    -235,
    -256,
    -235,
    -204,
    -153,
    -110,
    25,
    110,
    153,
    204,
    235,
};

TaskDesc gTaskDescWlogoWon = {
    gTaskNameWlogoWon,
    (void (*)(void*, void*))task_wlogo_won_0,
    task_wlogo_won_1,
    (void (*)(void*))task_wlogo_won_2,
    (void (*)(void*))task_wlogo_won_3,
    0x108,
};

TaskDesc gTaskDescWlogoAtl = {
    gTaskNameWlogoAtl,
    (void (*)(void*, void*))task_wlogo_atl_0,
    task_wlogo_atl_1,
    (void (*)(void*))task_wlogo_atl_2,
    (void (*)(void*))task_wlogo_atl_3,
    0xC,
};

TaskDesc gTaskDescWlogoNvl = {
    gTaskNameWlogoNvl,
    (void (*)(void*, void*))task_wlogo_nvl_0,
    task_wlogo_nvl_1,
    (void (*)(void*))task_wlogo_nvl_2,
    (void (*)(void*))task_wlogo_nvl_3,
    0xC,
};

TaskDesc gTaskDescWlogoNvlMov = {
    gTaskNameWlogoNvlMov,
    (void (*)(void*, void*))task_wlogo_nvl_mov_0,
    task_wlogo_nvl_mov_1,
    (void (*)(void*))task_wlogo_nvl_mov_2,
    (void (*)(void*))task_wlogo_nvl_mov_3,
    0x4C,
};

TaskDesc gTaskDescWlogoNvlObj = {
    gTaskNameWlogoNvlObj,
    (void (*)(void*, void*))task_wlogo_nvl_obj_0,
    task_wlogo_nvl_obj_1,
    (void (*)(void*))task_wlogo_nvl_obj_2,
    (void (*)(void*))task_wlogo_nvl_obj_3,
    0x30,
};

TaskDesc gTaskDescWlogoCol = {
    gTaskNameWlogoCol,
    (void (*)(void*, void*))task_wlogo_col_0,
    task_wlogo_col_1,
    (void (*)(void*))task_wlogo_col_2,
    (void (*)(void*))task_wlogo_col_3,
    0x34,
};

TaskDesc gTaskDescWlogoHlw = {
    gTaskNameWlogoHlw,
    (void (*)(void*, void*))task_wlogo_hlw_0,
    task_wlogo_hlw_1,
    (void (*)(void*))task_wlogo_hlw_2,
    (void (*)(void*))task_wlogo_hlw_3,
    0x8,
};

TaskDesc gTaskDescWlogoDil = {
    gTaskNameWlogoDil,
    (void (*)(void*, void*))task_wlogo_dil_0,
    task_wlogo_dil_1,
    (void (*)(void*))task_wlogo_dil_2,
    (void (*)(void*))task_wlogo_dil_3,
    0x18,
};

WlogoAgrEntry gUnk_09EF191C[20] = {
    {99, 83, 10, 5, 0, 91, 85, 6, {0, 0, 0}},
    {88, 80, 20, 5, 0, 92, 85, 7, {0, 0, 0}},
    {84, 73, 26, 5, 0, 85, 73, 6, {0, 0, 0}},
    {101, 67, 32, 0, 0, 104, 67, 7, {0, 0, 0}},
    {118, 71, 36, 0, 0, 112, 66, 6, {0, 0, 0}},
    {128, 72, 40, 0, 0, 120, 68, 7, {0, 0, 0}},
    {142, 71, 46, 0, 0, 139, 72, 6, {0, 0, 0}},
    {149, 61, 50, 0, 0, 156, 71, 7, {0, 0, 0}},
    {166, 60, 54, 0, 0, 169, 57, 6, {0, 0, 0}},
    {141, 51, 60, 0, 1, 141, 62, 7, {0, 0, 0}},
    {125, 52, 66, 1, 1, 125, 54, 6, {0, 0, 0}},
    {114, 50, 72, 1, 1, 118, 42, 7, {0, 0, 0}},
    {100, 51, 78, 1, 1, 97, 53, 6, {0, 0, 0}},
    {88, 55, 82, 1, 1, 84, 65, 7, {0, 0, 0}},
    {78, 61, 88, 2, 1, 78, 56, 6, {0, 0, 0}},
    {98, 66, 92, 2, 1, 100, 66, 7, {0, 0, 0}},
    {117, 64, 98, 0, 1, 117, 69, 6, {0, 0, 0}},
    {122, 66, 104, 0, 1, 126, 66, 7, {0, 0, 0}},
    {135, 64, 110, 0, 1, 138, 59, 6, {0, 0, 0}},
    {0, 0, 0, 0, 0, 0, 0, 0, {0, 0, 0}},
};

TaskDesc gTaskDescWlogoAgr = {
    gTaskNameWlogoAgr,
    (void (*)(void*, void*))task_wlogo_agr_0,
    task_wlogo_agr_1,
    (void (*)(void*))task_wlogo_agr_2,
    (void (*)(void*))task_wlogo_agr_3,
    0x18,
};

TaskDesc gTaskDescWlogoAgrSmoke = {
    gTaskNameWlogoAgrSmoke,
    (void (*)(void*, void*))task_wlogo_agr_smoke_0,
    task_wlogo_agr_smoke_1,
    (void (*)(void*))task_wlogo_agr_smoke_2,
    (void (*)(void*))task_wlogo_agr_smoke_3,
    0x38,
};

TaskDesc gTaskDescWlogoAgrFlash0 = {
    gTaskNameWlogoAgrFlash0,
    (void (*)(void*, void*))task_wlogo_agr_flash0_0,
    task_wlogo_agr_flash0_1,
    (void (*)(void*))task_wlogo_agr_flash0_2,
    (void (*)(void*))task_wlogo_agr_flash0_3,
    0x2C,
};

TaskDesc gTaskDescWlogoAgrFlash1 = {
    gTaskNameWlogoAgrFlash1,
    (void (*)(void*, void*))task_wlogo_agr_flash1_0,
    task_wlogo_agr_flash1_1,
    (void (*)(void*))task_wlogo_agr_flash1_2,
    (void (*)(void*))task_wlogo_agr_flash1_3,
    0x2C,
};

TaskDesc gTaskDescWlogoTvt = {
    gTaskNameWlogoTvt,
    (void (*)(void*, void*))task_wlogo_tvt_0,
    task_wlogo_tvt_1,
    (void (*)(void*))task_wlogo_tvt_2,
    (void (*)(void*))task_wlogo_tvt_3,
    0x34,
};

TaskDesc gTaskDescWlogoPoo = {
    gTaskNameWlogoPoo,
    (void (*)(void*, void*))task_wlogo_poo_0,
    task_wlogo_poo_1,
    (void (*)(void*))task_wlogo_poo_2,
    (void (*)(void*))task_wlogo_poo_3,
    0xC,
};

u8 gUnk_09EF1AEC[4] = { 0, 0, 2, 2 };

TaskDesc gTaskDescWlogoPooObj = {
    gTaskNameWlogoPooObj,
    (void (*)(void*, void*))task_wlogo_poo_obj_0,
    task_wlogo_poo_obj_1,
    (void (*)(void*))task_wlogo_poo_obj_2,
    (void (*)(void*))task_wlogo_poo_obj_3,
    0x44,
};

WlogoTtMotion gUnk_09EF1B08 =
{{128, 25, 128, 204, 256, 0}, {76, 179, 256, 0, 0, 0}}
;

TaskDesc gTaskDescWlogoTt = {
    gTaskNameWlogoTt,
    (void (*)(void*, void*))task_wlogo_tt_0,
    task_wlogo_tt_1,
    (void (*)(void*))task_wlogo_tt_2,
    (void (*)(void*))task_wlogo_tt_3,
    0x128,
};

TaskDesc gTaskDescWlogoTtObj = {
    gTaskNameWlogoTtObj,
    (void (*)(void*, void*))task_wlogo_tt_obj_0,
    task_wlogo_tt_obj_1,
    (void (*)(void*))task_wlogo_tt_obj_2,
    (void (*)(void*))task_wlogo_tt_obj_3,
    0x30,
};

s16 gUnk_09EF1B68[33][3] = {
    {72, 76, 5},
    {111, 90, 5},
    {85, 82, 5},
    {120, 95, 5},
    {102, 72, 5},
    {135, 87, 5},
    {120, 79, 5},
    {140, 99, 5},
    {80, 73, 5},
    {116, 92, 5},
    {92, 78, 5},
    {105, 97, 5},
    {98, 84, 5},
    {130, 88, 5},
    {122, 76, 5},
    {115, 100, 5},
    {102, 72, 5},
    {119, 99, 5},
    {122, 79, 5},
    {130, 89, 5},
    {105, 74, 5},
    {135, 94, 5},
    {135, 83, 5},
    {125, 86, 5},
    {130, 80, 5},
    {120, 90, 5},
    {140, 75, 5},
    {155, 94, 5},
    {118, 72, 5},
    {135, 96, 5},
    {140, 78, 5},
    {142, 98, 5},
    {0, 0, 0},
};

TaskDesc gTaskDescWlogoTtLine = {
    gTaskNameWlogoTtLine,
    (void (*)(void*, void*))task_wlogo_tt_line_0,
    task_wlogo_tt_line_1,
    (void (*)(void*))task_wlogo_tt_line_2,
    (void (*)(void*))task_wlogo_tt_line_3,
    0x1C,
};

s8 gUnk_09EF1C48[8] = {
    6,
    6,
    6,
    10,
    7,
    7,
    7,
};

s8 gUnk_09EF1C50[8] = {
    1,
    2,
    3,
    4,
    3,
    2,
    1,
};

TaskDesc gTaskDescWlogoBks = {
    gTaskNameWlogoBks,
    (void (*)(void*, void*))task_wlogo_bks_0,
    task_wlogo_bks_1,
    (void (*)(void*))task_wlogo_bks_2,
    (void (*)(void*))task_wlogo_bks_3,
    0x50,
};

u8 gUnk_09EF1C70[14] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    4,
    8,
    9,
    8,
    10,
    11,
};

s16 gUnk_09EF1C7E[14][2] = {
    {90, 80},
    {99, 81},
    {107, 81},
    {114, 81},
    {121, 81},
    {127, 81},
    {98, 91},
    {113, 90},
    {121, 90},
    {125, 90},
    {131, 90},
    {136, 90},
    {143, 90},
    {150, 90},
};

s16 gUnk_09EF1CB6[14][2] = {
    {250, 190},
    {200, 190},
    {150, 190},
    {100, 190},
    {50, 190},
    {0, 190},
    {245, -30},
    {210, -30},
    {175, -30},
    {140, -30},
    {105, -30},
    {70, -30},
    {35, -30},
    {0, -30},
};

s16 gUnk_09EF1CEE[14] = {
    80,
    70,
    60,
    50,
    40,
    30,
    20,
    30,
    40,
    50,
    60,
    70,
    80,
    90,
};

u16 gUnk_09EF1D0A[14] = {
    11,
    9,
    7,
    5,
    3,
    1,
    2,
    4,
    6,
    8,
    10,
    12,
    13,
    14,
};

TaskDesc gTaskDescWlogoBksObj = {
    gTaskNameWlogoBksObj,
    (void (*)(void*, void*))task_wlogo_bks_obj_0,
    task_wlogo_bks_obj_1,
    (void (*)(void*))task_wlogo_bks_obj_2,
    (void (*)(void*))task_wlogo_bks_obj_3,
    0x4C,
};
