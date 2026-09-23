#include "mode_wlogo.h"
#include "registration_data.h"
#include "mode_sio.h"
#include "msg_api.h"
#include "monsgage.h"
#include "world_intro_assets.h"
#include "gba/keys.h"

#ifdef VERSION_EU
extern u8 gUnkEu_08F7A224[];
extern u8 gUnkEu_08F7ADFC[];
extern u8 gUnkEu_08F7B958[];
extern u8 gUnkEu_08F7A7A8[];
extern u8 gUnkEu_08F7BE78[];
extern u8 gUnkEu_08F79960[];
extern u8 gUnkEu_08F7C6CC[];
extern u8 gUnkEu_08F7C274[];
extern u8 gUnkEu_08F7B498[];
extern u8 gUnkEu_08F79520[];
extern u8 gUnkEu_08F7CB08[];
extern u8 gUnkEu_08F7CFB4[];
extern u8 gUnkEu_08CA8D3C[];
extern u8 gUnkEu_08CB0D3C[];
extern u8 gUnkEu_08CB8D3C[];
extern u8 gUnkEu_08CACD3C[];
extern u8 gUnkEu_08CBCD3C[];
extern u8 gUnkEu_08CA0D3C[];
extern u8 gUnkEu_08CC4BFC[];
extern u8 gUnkEu_08CC0BFC[];
extern u8 gUnkEu_08CB4D3C[];
extern u8 gUnkEu_08C9CD3C[];
extern u8 gUnkEu_08CC8BFC[];
extern u8 gUnkEu_08CCCBFC[];
#endif

void func_080B4154(void);
void func_080B4210(u8 a);

u8* gWorldNames[13] = {
#if defined(VERSION_US)
    (u8*)gUnk_0815A534,
    (u8*)gUnk_0815A59A,
    (u8*)gUnk_0815A57C,
    (u8*)gUnk_0815A5AA,
    (u8*)gUnk_0815A5BE,
    (u8*)gUnk_0815A54A,
    (u8*)gUnk_0815A5D4,
    (u8*)gUnk_0815A62A,
    (u8*)gUnk_0815A56C,
    (u8*)gUnk_0815A518,
    (u8*)gUnk_0815A5F2,
    (u8*)gUnk_0815A60E,
    (u8*)gUnk_0815A64A,
#elif defined(VERSION_JP)
    (u8*)gUnkJp_0814E59C,
    (u8*)gUnkJp_0814E5AC,
    (u8*)gUnkJp_0814E5B8,
    (u8*)gUnkJp_0814E5E4,
    (u8*)gUnkJp_0814E5F4,
    (u8*)gUnkJp_0814E5CC,
    (u8*)gUnkJp_0814E618,
    (u8*)gUnkJp_0814E62C,
    (u8*)gUnkJp_0814E590,
    (u8*)gUnkJp_0814E57C,
    (u8*)gUnkJp_0814E604,
    (u8*)gUnkJp_0814E644,
    (u8*)gUnkJp_0814E658,
#elif defined(VERSION_EU)
    (u8*)&gUnkEu_0888E410,
    (u8*)&gUnkEu_0888E450,
    (u8*)&gUnkEu_0888E4C0,
    (u8*)&gUnkEu_0888E578,
    (u8*)&gUnkEu_0888E5DC,
    (u8*)&gUnkEu_0888E530,
    (u8*)&gUnkEu_0888E6BC,
    (u8*)&gUnkEu_0888E72C,
    (u8*)&gUnkEu_0888E3A0,
    (u8*)&gUnkEu_0888E364,
    (u8*)&gUnkEu_0888E654,
    (u8*)&gUnkEu_0888E78C,
    (u8*)&gUnkEu_0888E804,
#endif
};

u8 gUnk_09EF15FC[13] = {
    4,
    5,
    6,
    2,
    7,
    3,
    8,
    9,
    1,
    10,
    0,
    11,
    12,
};

static u8 gUnk_02034B58;
static s8 gUnk_02034B59;
static u8 gUnk_02034B5A;
static u8 gUnk_02034B5B;
#ifdef VERSION_EU
static TextSlot gUnk_02034B60[80];
#else
static TextSlot gUnk_02034B60[20];
#endif
static struct ObjPalette* gUnk_02034C00;
static TaskPool gUnk_02034C08;
static Task* gUnk_02034C1C;
static TaskPool gUnk_02034C20;
static Task* gUnk_02034C34;

void mode_wLogo_0(s32 arg) {
    gUnk_02034B59 = arg;
    func_080B4154();
}

void mode_wLogo_1(void) {
    u8* p;

    switch (gUnk_02034B58) {
    case 0:
        DrawTextSlots(35, 75, gUnk_02034B60, gUnk_02034C00, 20, gUnk_02034B5B);

        if (GetKeysPressed() & DPAD_LEFT) {
            gUnk_02034B59--;
            if (gUnk_02034B59 < 0) {
                gUnk_02034B59 = 12;
            }
#ifdef VERSION_EU
            gUnk_02034B5B = LoadTextSlots(eu_0805E924(gWorldNames[gUnk_02034B59]), gUnk_02034B60);
#else
            gUnk_02034B5B = LoadTextSlots(gWorldNames[gUnk_02034B59], gUnk_02034B60);
#endif
        }

        if (GetKeysPressed() & DPAD_RIGHT) {
            gUnk_02034B59++;
            if (gUnk_02034B59 > 12) {
                gUnk_02034B59 = 0;
            }
            p = &gUnk_02034B5B;
#ifdef VERSION_EU
            *p = LoadTextSlots(eu_0805E924(gWorldNames[gUnk_02034B59]), gUnk_02034B60);
#else
            *p = LoadTextSlots(gWorldNames[gUnk_02034B59], gUnk_02034B60);
#endif
        }

        if (GetKeysPressed() & 1) {
            FadeStartOut(0, 16);
            DisableBg(0);
            DisableBg(1);
            gUnk_02034B58++;
        }

        if (GetKeysPressed() & 2) {
            ModeRequest(&gModeDebug, 0);
        }
        break;
    case 1:
        func_080B4210(gUnk_09EF15FC[gUnk_02034B59]);
        gUnk_02034B58++;
        break;
    case 2:
        if (IsTaskActive(gUnk_02034C1C)) {
            TaskPoolUpdate(&gUnk_02034C08);
            TaskPoolDraw(&gUnk_02034C08);
        } else {
            gUnk_02034B58++;
        }
        break;
    case 3:
        gUnk_02034B5A++;
        if (gUnk_02034B5A > 10) {
            ModeRequest(&gModeWLogo, gUnk_02034B59);
        }
        break;
    }
}

void mode_wLogo_2(void) {
    FreeTextSlots(gUnk_02034B60, 20);
    ReleaseObjPalette(gUnk_02034C00);

    if (gUnk_02034B58 != 0) {
        if (gUnk_02034B58 == 3) {
            TaskPoolDestroy(&gUnk_02034C08);
        }
    }
}

void func_080B4154(void) {
    u8* p;
    FadeStartIn(0, 16);
    SetBgMode0();
    SetupBg(1, 2, 31, 0);
    SetBgSize(1, 0);
    LoadBgTiles(1, gUnk_096ACA44, 0xBC0);
    LoadBgPalette(1, gUnk_096FBA04, 0x40);
    LoadBgMap(1, gUnk_096F5464, 0x800);
    DisableBg(0);
    EnableBg(1);
    gUnk_02034B58 = 0;
    gUnk_02034B5A = 0;
    InitTextSlots(gUnk_02034B60, 20);
    p = &gUnk_02034B5B;
#ifdef VERSION_EU
    *p = LoadTextSlots(eu_0805E924(gWorldNames[gUnk_02034B59]), gUnk_02034B60);
#else
    *p = LoadTextSlots(gWorldNames[gUnk_02034B59], gUnk_02034B60);
#endif
    gUnk_02034C00 = LoadObjPalette(gUnk_096FBCC4, 32);
}

void func_080B4210(u8 a) {
    FadeStartIn(0, 16);
    SetBgMode1();
    SetupBg(0, 0, 7, 14);
    SetBgPriority(0, 0);
    SetBgOverflow(0, 1);
    SetBgSize(0, 0);
    SetupBg(2, 2, 24, 0);
    SetBgPriority(2, 2);
    SetBgOverflow(2, 1);
    SetBgSize(2, 0x8000);
    TaskPoolInit(&gUnk_02034C08, 2);

    switch (a) {
    case 4:
#ifdef VERSION_EU
        LoadBgTiles(2, gUnkEu_08CA8D3C, 0x4000);
#else
        LoadBgTiles(2, gUnk_08C84824, 0x4000);
#endif
        LoadBgPalette(2, gUnk_08F68904, 0xC0);
#ifdef VERSION_EU
        eu_080059F4(2, gUnkEu_08F7A224);
#else
        LoadBgMap(2, gUnk_08EF2384, 0x1000);
#endif
        gUnk_02034C1C = TaskCreate(&gUnk_02034C08, &gTaskDescWlogoWon, 0);
        break;
    case 5:
#ifdef VERSION_EU
        LoadBgTiles(2, gUnkEu_08CB0D3C, 0x4000);
#else
        LoadBgTiles(2, gUnk_08C8C824, 0x4000);
#endif
        LoadBgPalette(2, gUnk_08F68A84, 0x100);
#ifdef VERSION_EU
        eu_080059F4(2, gUnkEu_08F7ADFC);
#else
        LoadBgMap(2, gUnk_08EF4384, 0x1000);
#endif
        gUnk_02034C1C = TaskCreate(&gUnk_02034C08, &gTaskDescWlogoMons, 0);
        break;
    case 6:
#ifdef VERSION_EU
        LoadBgTiles(2, gUnkEu_08CB8D3C, 0x4000);
#else
        LoadBgTiles(2, gUnk_08C94824, 0x4000);
#endif
        LoadBgPalette(2, gUnk_08F68C84, 0xE0);
#ifdef VERSION_EU
        eu_080059F4(2, gUnkEu_08F7B958);
#else
        LoadBgMap(2, gUnk_08EF6384, 0x1000);
#endif
        gUnk_02034C1C = TaskCreate(&gUnk_02034C08, &gTaskDescWlogoHwt, 0);
        break;
    case 2:
#ifdef VERSION_EU
        LoadBgTiles(2, gUnkEu_08CACD3C, 0x4000);
#else
        LoadBgTiles(2, gUnk_08C88824, 0x4000);
#endif
        LoadBgPalette(2, gUnk_08F689C4, 0xC0);
#ifdef VERSION_EU
        eu_080059F4(2, gUnkEu_08F7A7A8);
#else
        LoadBgMap(2, gUnk_08EF3384, 0x1000);
#endif
        gUnk_02034C1C = TaskCreate(&gUnk_02034C08, &gTaskDescWlogoAtl, 0);
        break;
    case 7:
#ifdef VERSION_EU
        LoadBgTiles(2, gUnkEu_08CBCD3C, 0x3EC0);
#else
        LoadBgTiles(2, gUnk_08C98824, 0x3EC0);
#endif
        LoadBgPalette(2, gUnk_08F68D64, 0x140);
#ifdef VERSION_EU
        eu_080059F4(2, gUnkEu_08F7BE78);
#else
        LoadBgMap(2, gUnk_08EF7384, 0x1000);
#endif
        gUnk_02034C1C = TaskCreate(&gUnk_02034C08, &gTaskDescWlogoNvl, 0);
        break;
    case 3:
#ifdef VERSION_EU
        LoadBgTiles(2, gUnkEu_08CA0D3C, 0x4000);
#else
        LoadBgTiles(2, gUnk_08C7C824, 0x4000);
#endif
        LoadBgPalette(2, gUnk_08F686E4, 0xE0);
#ifdef VERSION_EU
        eu_080059F4(2, gUnkEu_08F79960);
#else
        LoadBgMap(2, gUnk_08EF0384, 0x1000);
#endif
        gUnk_02034C1C = TaskCreate(&gUnk_02034C08, &gTaskDescWlogoCol, 0);
        break;
    case 8:
#ifdef VERSION_EU
        LoadBgTiles(2, gUnkEu_08CC4BFC, 0x4000);
#else
        LoadBgTiles(2, gUnk_08CA06E4, 0x4000);
#endif
        LoadBgPalette(2, gUnk_08F68FC4, 0xE0);
#ifdef VERSION_EU
        eu_080059F4(2, gUnkEu_08F7C6CC);
#else
        LoadBgMap(2, gUnk_08EF9384, 0x1000);
#endif
        gUnk_02034C1C = TaskCreate(&gUnk_02034C08, &gTaskDescWlogoHlw, 0);
        break;
    case 9:
#ifdef VERSION_EU
        LoadBgTiles(2, gUnkEu_08CC0BFC, 0x4000);
#else
        LoadBgTiles(2, gUnk_08C9C6E4, 0x4000);
#endif
        LoadBgPalette(2, gUnk_08F68EA4, 0x120);
#ifdef VERSION_EU
        eu_080059F4(2, gUnkEu_08F7C274);
#else
        LoadBgMap(2, gUnk_08EF8384, 0x1000);
#endif
        gUnk_02034C1C = TaskCreate(&gUnk_02034C08, &gTaskDescWlogoDil, 0);
        break;
    case 1:
#ifdef VERSION_EU
        LoadBgTiles(2, gUnkEu_08CB4D3C, 0x4000);
#else
        LoadBgTiles(2, gUnk_08C90824, 0x4000);
#endif
        LoadBgPalette(2, gUnk_08F68B84, 0x100);
#ifdef VERSION_EU
        eu_080059F4(2, gUnkEu_08F7B498);
#else
        LoadBgMap(2, gUnk_08EF5384, 0x1000);
#endif
        gUnk_02034C1C = TaskCreate(&gUnk_02034C08, &gTaskDescWlogoAgr, 0);
        break;
    case 10:
#ifdef VERSION_EU
        LoadBgTiles(2, gUnkEu_08C9CD3C, 0x4000);
#else
        LoadBgTiles(2, gUnk_08C78824, 0x4000);
#endif
        LoadBgPalette(2, gUnk_08F68624, 0xC0);
#ifdef VERSION_EU
        eu_080059F4(2, gUnkEu_08F79520);
#else
        LoadBgMap(2, gUnk_08EEF384, 0x1000);
#endif
        gUnk_02034C1C = TaskCreate(&gUnk_02034C08, &gTaskDescWlogoTvt, 0);
        break;
    case 0:
#ifdef VERSION_EU
        LoadBgTiles(2, gUnkEu_08CA8D3C, 0x4000);
#else
        LoadBgTiles(2, gUnk_08C84824, 0x4000);
#endif
        LoadBgPalette(2, gUnk_08F68904, 0xC0);
#ifdef VERSION_EU
        eu_080059F4(2, gUnkEu_08F7A224);
#else
        LoadBgMap(2, gUnk_08EF2384, 0x1000);
#endif
        gUnk_02034C1C = TaskCreate(&gUnk_02034C08, &gTaskDescWlogoPoo, 0);
        break;
    case 11:
#ifdef VERSION_EU
        LoadBgTiles(2, gUnkEu_08CC8BFC, 0x4000);
#else
        LoadBgTiles(2, gUnk_08CA46E4, 0x4000);
#endif
        LoadBgPalette(2, gUnk_08F690A4, 0x140);
#ifdef VERSION_EU
        eu_080059F4(2, gUnkEu_08F7CB08);
#else
        LoadBgMap(2, gUnk_08EFA384, 0x1000);
#endif
        gUnk_02034C1C = TaskCreate(&gUnk_02034C08, &gTaskDescWlogoTt, 0);
        break;
    case 12:
#ifdef VERSION_EU
        LoadBgTiles(2, gUnkEu_08CCCBFC, 0x4000);
#else
        LoadBgTiles(2, gUnk_08CA86E4, 0x4000);
#endif
        LoadBgPalette(2, gUnk_08F691E4, 0xE0);
#ifdef VERSION_EU
        eu_080059F4(2, gUnkEu_08F7CFB4);
#else
        LoadBgMap(2, gUnk_08EFB384, 0x1000);
#endif
        gUnk_02034C1C = TaskCreate(&gUnk_02034C08, &gTaskDescWlogoBks, 0);
        break;
    }
    SetBgAffine(2, 0, 256, 256, 0x10000, 0x16800);
}

void task_wLogo_0(WLogoTaskWork* work, u8 arg) {
    work->unk_00 = arg;
    work->unk_04 = -0x5A00;
    work->timer = 0;
    TaskPoolInit(&gUnk_02034C20, 2);

    switch (work->unk_00) {
    case 4:
        gUnk_02034C34 = TaskCreate(&gUnk_02034C20, &gTaskDescWlogoWon, 0);
        break;
    case 5:
        gUnk_02034C34 = TaskCreate(&gUnk_02034C20, &gTaskDescWlogoMons, 0);
        break;
    case 6:
        gUnk_02034C34 = TaskCreate(&gUnk_02034C20, &gTaskDescWlogoHwt, 0);
        break;
    case 2:
        gUnk_02034C34 = TaskCreate(&gUnk_02034C20, &gTaskDescWlogoAtl, 0);
        break;
    case 7:
        gUnk_02034C34 = TaskCreate(&gUnk_02034C20, &gTaskDescWlogoNvl, 0);
        break;
    case 3:
        gUnk_02034C34 = TaskCreate(&gUnk_02034C20, &gTaskDescWlogoCol, 0);
        break;
    case 8:
        gUnk_02034C34 = TaskCreate(&gUnk_02034C20, &gTaskDescWlogoHlw, 0);
        break;
    case 1:
        gUnk_02034C34 = TaskCreate(&gUnk_02034C20, &gTaskDescWlogoAgr, 0);
        break;
    case 9:
        gUnk_02034C34 = TaskCreate(&gUnk_02034C20, &gTaskDescWlogoDil, 0);
        break;
    case 10:
        gUnk_02034C34 = TaskCreate(&gUnk_02034C20, &gTaskDescWlogoTvt, 0);
        break;
    case 0:
        gUnk_02034C34 = TaskCreate(&gUnk_02034C20, &gTaskDescWlogoPoo, 0);
        break;
    case 11:
        gUnk_02034C34 = TaskCreate(&gUnk_02034C20, &gTaskDescWlogoTt, 0);
        break;
    case 12:
        gUnk_02034C34 = TaskCreate(&gUnk_02034C20, &gTaskDescWlogoBks, 0);
        break;
    default:
        gUnk_02034C34 = TaskCreate(&gUnk_02034C20, &gTaskDescWlogoWon, 0);
        break;
    }

    if (work->unk_00 == 0) {
        func_080CA6A8(0, work->unk_04);
    } else {
        func_080E02A8(0, work->unk_04);
    }
}

u8 task_wLogo_1(WLogoTaskWork* work) {
    if (work->unk_00 == 0) {
        work->timer++;
        if (work->timer <= 314) {
            func_080CA6A8(0, 76);
        }
    } else {
        work->timer++;
        if (work->timer <= 314) {
            func_080E02A8(0, 76);
        }
    }

    if (IsTaskActive(gUnk_02034C34) != 0) {
        TaskPoolUpdate(&gUnk_02034C20);
        TaskPoolDraw(&gUnk_02034C20);
        return 1;
    }
    return 0;
}

void task_wLogo_2(WLogoTaskWork* work) {
}

void task_wLogo_3(WLogoTaskWork* work) {
    TaskPoolDestroy(&gUnk_02034C20);
    SetBgBlend(0, 0, 16);
}

const char gModeNameWLogo[] = "mode_wLogo";

Mode gModeWLogo = {
    gModeNameWLogo,
    (void (*)(s32))mode_wLogo_0,
    (void (*)(void))mode_wLogo_1,
    (void (*)(void))mode_wLogo_2,
};

const char gTaskNameWLogo[] = "task_wLogo";

TaskDesc gTaskDescWLogo = {
    gTaskNameWLogo,
    (void (*)(void*, void*))task_wLogo_0,
    task_wLogo_1,
    (void (*)(void*))task_wLogo_2,
    (void (*)(void*))task_wLogo_3,
    0xC,
};
