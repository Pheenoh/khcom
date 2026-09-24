#include "macros.h"
#include "registration_data.h"
#include "title_api.h"
#include "map_api.h"
#include "task.h"
#include "system_state.h"
#include "mode_title.h"
#include "sprites_title.h"

s32 gTitleBgScale EWRAM_COMMON(4);
s32 gTitleBgX EWRAM_COMMON(4);
s32 gTitleBgY EWRAM_COMMON(4);

u32 gUnk_02034E98;
u32 gUnk_02034E9C;
TaskPool gTitleTaskPool __attribute__((aligned(8)));
Task* gTitleMenuTask;
Task* gTitleLogoTask;
Task* gTitleObjTask;
u16 gUnk_02034EC0;
s16 gUnk_02034EC2;
u8* gUnk_02034EC4;
u16 gUnk_02034EC8;
u8 gUnk_02034ECA;
u8 gUnk_02034ECB;
u8 gUnk_02034ECC;

#ifdef VERSION_EU
extern u8 gUnkEu_09814E40[];
#endif

void func_080D5978(u16 a, void* b, u16 c) {
    RequestDma3Copy(b, gUnk_02034EC4 + a * 32, c);
}

void func_080D5998(void) {
    LoadPalette(gUnk_02034EC4, (void*)0x05000000, 0x400);
}

void func_080D59B4(void) {
    if (gUnk_02034ECA != 0) {
        ModeRequest(&gModeTitle, 0);
        return;
    }

    switch (gUnk_02034EC2) {
    case 3:
        SaveLoadSystem();
        SaveClearSystem();
        func_080E04EC();
        return;
    case 1:
        ModeRequest(&gModeMenuLoad, 0);
        return;
    case 2:
        func_080AEB94();
        ModeRequest(&gModeSioBattle, 0);
        return;
    case 4:
        func_0801CD20();
        ModeRequest(&gModeMenuNew, 0);
        return;
    case 5:
        func_0801CCB4();
        ModeRequest(&gModeMenuNew, 0);
        return;
    case 0:
    default:
        ModeRequest(&gModeMenuNew, 0);
        return;
    }
}

void func_080D5A4C(u16 a) {
    if ((gGameState.flags & 0x200) != 0) {
        LoadBgPalette(1, gUnk_0984A818, 0x200);
        func_080D5978(0, gUnk_0984A818, 0x200);
    } else {
        LoadBgPalette(1, gUnk_0984A418, 0x200);
        func_080D5978(0, gUnk_0984A418, 0x200);
    }
    EnableBg(0);
    DisableBg(1);
    DisableBg(2);

    if (IsTaskActive(gTitleLogoTask) == 0) {
        gTitleLogoTask = TaskCreate(&gTitleTaskPool, &gTaskDescTitleLogo, 0);
    }

    if (IsTaskActive(gTitleObjTask) == 0) {
        gTitleObjTask = TaskCreate(&gTitleTaskPool, &gTaskDescTitleObj, 0);
    }
    FadeStartIn(2, a);
}

void func_080D5B04(void) {
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
        LoadBgMap(0, gUnk_0983F398, 0x800);
        break;
    case 2:
        LoadBgMap(0, gUnkEu_09814E40, 0x800);
        break;
    }
#else
    LoadBgMap(0, gUnk_0983F398, 0x800);
#endif
    SetBgBlend(0, 5, 16);
    EnableBg(1);
    m4aSongNumStart(SONG_BGM_TITLE);
}

void func_080D5B30(void) {
    m4aMPlayFadeOut(gMPlayTable[gSongTable[6].ms].info, 5);
    FadeStartOut(0, 90);
    func_080C75A4(0, 90);
    gUnk_02034E98 = 9;
}

void mode_title_0(void) {
    gUnk_02034ECA = 0;
    func_0801CB44();
    SaveLoadHeader();
    InitMapCardInventory();
    func_08093C04();
    gUnk_02034EC2 = 0;
    gUnk_02034EC4 = EwramAlloc(0x400);
    SetBgMode1();
    SetupBg(0, 0, 0x1D, 0);
    SetBgPriority(0, 3);

    if (gGameState.flags & 0x200) {
#ifdef VERSION_EU
        eu_080059F4(0, gUnk_09840798);
#else
        LoadBgMap(0, gUnk_09840798, 0x800);
#endif
    } else {
#ifdef VERSION_EU
        eu_080059F4(0, gUnk_0983E398);
#else
        LoadBgMap(0, gUnk_0983E398, 0x800);
#endif
    }
    DisableBg(0);
    SetupBg(1, 0, 0x1E, 0);
    SetBgPriority(1, 3);

    if (gGameState.flags & 0x200) {
#ifdef VERSION_EU
        eu_080059D4(1, gUnk_097D3658);
        eu_080059F4(1, gUnk_09840F98);
#else
        LoadBgTiles(1, gUnk_097D3658, 0x7FA0);
        LoadBgMap(1, gUnk_09840F98, 0x800);
#endif
    } else {
#ifdef VERSION_EU
        eu_080059D4(1, gUnk_097C77B8);
        eu_080059F4(1, gUnk_0983EB98);
#else
        LoadBgTiles(1, gUnk_097C77B8, 0x7FA0);
        LoadBgMap(1, gUnk_0983EB98, 0x800);
#endif
    }
    DisableBg(1);
    func_080C736C();
    func_080C73A4(0, 0, 0);
    SetupBg(2, 2, 0x1F, 0xB);
    SetBgSize(2, 0x4000);
    SetBgPriority(2, 2);
    LoadBgTiles(2, gUnk_097CF758, 0x3F00);
    LoadBgPalette(2, gUnk_0984A618, 0xA0);
    LoadBgMap(2, gUnk_0983FB98, 0x400);
    gTitleBgX = 0x7800;
    gTitleBgY = 0x5A00;
    gTitleBgScale = 0x1000;
    SetBgAffine(2, 0, gTitleBgScale >> 4, gTitleBgScale >> 4, gTitleBgX, gTitleBgY);
    TaskPoolInit(&gTitleTaskPool, 4);
    gTitleLogoTask = 0;
    gTitleObjTask = 0;
    FadeStartIn(0, 0x4C);
    gUnk_02034E98 = 0;
    m4aSongNumStart(0);
    gUnk_02034EC0 = 0x1E;
}

void mode_title_1(void) {
    switch (gUnk_02034E98) {
    case 0:
        if (FadeIsActive()) {
            break;
        }

        if (gUnk_02034EC0 != 0) {
            gUnk_02034EC0--;
            if (gUnk_02034EC0 != 0) {
                break;
            }
        }
        gUnk_02034E98 = 1;
        gUnk_02034EC0 = 100;
        break;
    case 1:
        if (gGameState.flags & 0x200) {
            ApproachValue(&gTitleBgX, 0x3F3F, gUnk_02034EC0);
        } else {
            ApproachValue(&gTitleBgX, 0xB0C1, gUnk_02034EC0);
        }
        ApproachValue(&gTitleBgY, 0x6A37, gUnk_02034EC0);
        ApproachValue(&gTitleBgScale, 0xBD0, gUnk_02034EC0);
        SetBgAffine(2, 0, gTitleBgScale / 16, gTitleBgScale / 16, gTitleBgX, gTitleBgY);
        gUnk_02034EC0--;
        if (gUnk_02034EC0 == 0x46) {
            func_080C75A4(1, 0x46);

            if (gUnk_02034EC0 == 0x46) {
                FadeStartOut(1, 0x46);
            }
        }

        if (gUnk_02034EC0 == 0) {
            gUnk_02034E98 = 2;
            gUnk_02034EC0 = 2;
        }
        break;
    case 2:
        if (FadeIsActive()) {
            break;
        }
        gUnk_02034EC0--;
        if (gUnk_02034EC0 != 0) {
            break;
        }
        func_080D5A4C(15);
        gUnk_02034E98 = 3;
        gUnk_02034EC0 = 0x28;
        break;
    case 3:
        if (FadeIsActive()) {
            break;
        }

        if (gUnk_02034EC0 != 0) {
            gUnk_02034EC0--;
            break;
        }
        gUnk_02034E98 = 4;
        gUnk_02034EC8 = 0;
        gBldCnt = (BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_OBJ);
        gBldAlpha = 0x10;
        gUnk_02034EC0 = 4;
        EnableBg(1);
        break;
    case 4:
        if (gUnk_02034EC0 != 0) {
            gUnk_02034EC0--;
            break;
        }
        gUnk_02034EC0 = 4;
        gUnk_02034EC8++;
        gBldAlpha = (gUnk_02034EC8 << 8) | (16 - gUnk_02034EC8);

        if (gUnk_02034EC8 > 15) {
            gBldCnt = 0;
            func_080D5B04();
            gUnk_02034E98 = 5;
        }
        break;
    case 5:
        if (!func_080D6790()) {
            break;
        }

        if (!(GetKeysPressed() & START_BUTTON) && !(GetKeysPressed() & A_BUTTON)) {
            break;
        }
        m4aSongNumStart(SONG_SYS_KETTEI);

        if (SaveRepairSystem() == 2) {
            gUnk_02034EC2 = 3;
        } else if (SaveRepairFileLarge(0) == 2 || SaveRepairFileLarge(1) == 2) {
            gUnk_02034EC2 = 1;
        } else if ((gGameState.flags & 0x20) &&
                   (SaveRepairFileSmall(0) == 2 || SaveRepairFileSmall(1) == 2)) {
            gUnk_02034EC2 = 1;
        } else {
            gUnk_02034EC2 = 0;
        }
        func_08000DE8(&gTitleTaskPool, gTitleLogoTask);
        func_08000DE8(&gTitleTaskPool, gTitleObjTask);
        gTitleMenuTask = TaskCreate(&gTitleTaskPool, &gTaskDescTitleMenu, &gUnk_02034EC2);
        DisableBg(0);
        gUnk_02034E98 = 6;
        gUnk_02034EC8 = 0;
        gBldCnt = (BLDCNT_TGT1_OBJ | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1);
        gBldAlpha = ((16 - gUnk_02034EC8) << 8) | gUnk_02034EC8;
        gUnk_02034EC0 = 4;
        break;
    case 6:
        if (gUnk_02034EC0 != 0) {
            gUnk_02034EC0--;
            break;
        }
        gUnk_02034EC0 = 4;
        gUnk_02034EC8++;
        gBldAlpha = ((16 - gUnk_02034EC8) << 8) | gUnk_02034EC8;

        if (gUnk_02034EC8 > 15) {
            gBldCnt = 0;
            gUnk_02034E98 = 8;
        }
        break;
    case 7:
        if (gUnk_02034EC0 != 0) {
            gUnk_02034EC0--;
            break;
        }
        gUnk_02034EC0 = 1;
        gUnk_02034EC8--;
        gBldAlpha = ((16 - gUnk_02034EC8) << 8) | gUnk_02034EC8;

        if (gUnk_02034EC8 > 15) {
            gBldCnt = 0;
            func_08000DE8(&gTitleTaskPool, gTitleMenuTask);
            gTitleLogoTask = TaskCreate(&gTitleTaskPool, &gTaskDescTitleLogo, 0);
            gTitleObjTask = TaskCreate(&gTitleTaskPool, &gTaskDescTitleObj, 0);
            EnableBg(0);
            gUnk_02034E98 = 5;
        }
        break;
    case 8:
        if ((GetKeysPressed() & START_BUTTON) || (GetKeysPressed() & A_BUTTON)) {
            switch (gUnk_02034EC2) {
            case 0:
            case 4:
            case 5:
                m4aSongNumStart(SONG_SYS_START);
                break;
            default:
                m4aSongNumStart(SONG_SYS_KETTEI);
                break;
            }
            func_080D5B30();
        } else if (GetKeysPressed() & B_BUTTON) {
            m4aSongNumStart(SONG_SYS_CLOSE);
            gUnk_02034ECA = 1;
            func_080D5B30();
        }
        break;
    case 9:
        if (!FadeIsActive()) {
            func_080D59B4();
        }
        break;
    }

    if (!FadeIsActive() && gUnk_02034E98 != 6) {
        TaskPoolUpdate(&gTitleTaskPool);
    }
    TaskPoolDraw(&gTitleTaskPool);
    func_080C73D8();

    if (gUnk_02034E98 <= 4 && (GetKeysPressed() & (A_BUTTON | START_BUTTON))) {
        m4aSongNumStart(SONG_SYS_CLICK);

        if (gUnk_02034E98 <= 3) {
            func_080D5A4C(2);
        }
        func_080D5B04();
        gUnk_02034E98 = 5;
    }
}

void mode_title_2(void) {
    TaskPoolDestroy(&gTitleTaskPool);
    REG_IME = 0;
    REG_IE &= ~INTR_FLAG_VCOUNT;
    REG_DISPSTAT &= ~DISPSTAT_VCOUNT_INTR;
    REG_IME = 1;
    ResetVCountCallback();
    EwramFree(gUnk_02034EC4);
}

u8 func_080D6280(void) {
    if (gUnk_02034E98 > 2) {
        return 1;
    }
    return 0;
}

u8 func_080D6294(void) {
    if (gUnk_02034E98 > 4) {
        return 1;
    }
    return 0;
}

void func_080D62A8(TitleLogoWork* work) {
    work->sprites[0].tiles = LoadObjTiles(gUnk_0976E9F4, 0x240);
    work->sprites[0].gfx = gUnk_09EF659C;

    if (gGameState.flags & 0x200) {
        work->sprites[1].tiles = LoadObjTiles(gUnk_09776076, 0x43C0);
        work->sprites[1].gfx = gUnk_09EF669C;
        work->sprites[1].palette = LoadObjPalette(gUnk_0984AA18, 0x20);
    } else {
        work->sprites[1].tiles = LoadObjTiles(gUnk_0976EC54, 0xE0);
        work->sprites[1].gfx = gUnk_09EF65A4;
        work->sprites[1].palette = LoadObjPalette(gUnk_0984A6D8, 0x20);
    }
    work->sprites[2].tiles = LoadObjTiles(gUnk_0976ED5A, 0x380);
    work->sprites[2].gfx = gUnk_09EF65AC;
    work->sprites[3].tiles = LoadObjTiles(gUnk_0976F0F6, 0xC0);
    work->sprites[3].gfx = gUnk_09EF65B4;
    work->sprites[4].tiles = LoadObjTiles(gUnk_0976F1F0, 0xAC0);
    work->sprites[4].gfx = gUnk_09EF65BC;
    work->sprites[5].tiles = LoadObjTiles(gUnk_0976FD96, 0x1140);
    work->sprites[5].gfx = gUnk_09EF65C4;
    work->sprites[0].palette = LoadObjPalette(gUnk_0984A6B8, 0x20);
    work->sprites[2].palette = LoadObjPalette(gUnk_0984A6F8, 0x20);
    work->sprites[3].palette = LoadObjPalette(gUnk_0984A6F8, 0x20);
    work->sprites[4].palette = LoadObjPalette(gUnk_0984A718, 0x20);
    work->sprites[5].palette = LoadObjPalette(gUnk_0984A738, 0x20);
    work->scale = 0;
    work->unk_48 = 0xC00;
    work->unk_50 = 0;
    gUnk_02034ECC = 0;
}

Mode gModeTitle = {
    "mode_title",
    (ModeInitFunc)mode_title_0,
    mode_title_1,
    mode_title_2,
};
