#include "registration_data.h"
#include "system_state.h"
#include "map_api.h"
#include "mode_status_api.h"
#include "display.h"
#include "mode_status.h"
#include "sprites_status.h"

#ifdef VERSION_EU
extern u8 gUnkEu_097D8300[];
extern u8 gUnkEu_097D8F00[];
extern u8 gUnkEu_097D9B00[];
extern u8 gUnkEu_097DA700[];
#endif

TaskPool gStatusTaskPool __attribute__((aligned(8)));
Task* gStatusBarTask;
u8 gUnk_02034EF8;

void mode_status_0(void) {
    BgReset();
    SetBgMode0();
    SetupBg(0, 0, 0x1F, 0);
    SetupBg(2, 0, 0x1E, 0);
    SetupBg(3, 0, 0x1D, 0);
    SetBgPriority(0, 1);
    SetBgPriority(2, 2);
    SetBgPriority(3, 3);
#ifdef VERSION_EU
    LoadBgTiles(3, gUnk_097FFB98, 0x2060);

    switch (gLanguage) {
    case 1:
        RequestDma3Copy(gUnkEu_097D8300, (u8*)GetBgCharBase(3) + 0x1800, 0xC00);
        break;
    case 2:
        RequestDma3Copy(gUnkEu_097DA700, (u8*)GetBgCharBase(3) + 0x1800, 0xC00);
        break;
    case 3:
        RequestDma3Copy(gUnkEu_097D9B00, (u8*)GetBgCharBase(3) + 0x1800, 0xC00);
        break;
    case 4:
        RequestDma3Copy(gUnkEu_097D8F00, (u8*)GetBgCharBase(3) + 0x1800, 0xC00);
        break;
    case 0:
    default:
        break;
    }
#else
    LoadBgTiles(3, gUnk_097FFB98, 0x2100);
#endif
    LoadBgPalette(3, gUnk_0984B118, 0xA0);
    LoadBgMap(3, gUnk_09848198, 0x500);

    if (gGameState.flags & 8) {
        LoadBgMap(2, gUnk_09847C98, 0x500);
    } else {
        LoadBgMap(2, gUnk_09847798, 0x500);
    }

    LoadBgMap(0, gUnk_09848B98, 0x500);
    DisableBg(0);
    func_080D733C();
    TaskPoolInit(&gStatusTaskPool, 4);
    gStatusBarTask = TaskCreate(&gStatusTaskPool, &gTaskDescStatusBar, 0);
    TaskCreate(&gStatusTaskPool, &gTaskDescStatus, 0);
    FadeStartIn(0, 0x10);
}

void mode_status_1(void) {
    UpdatePlayTime();
    TaskPoolUpdate(&gStatusTaskPool);
    TaskPoolDraw(&gStatusTaskPool);

    if (!IsTaskActive(gStatusBarTask) && !FadeIsActive()) {
        func_080E052C(gUnk_02034EF8);
    }
}

void mode_status_2(void) {
    TaskPoolDestroy(&gStatusTaskPool);
}

void func_080D7568(u8 a) {
    gUnk_02034EF8 = a;
}

Mode gModeStatus = {
    "mode_status",
    (ModeInitFunc)mode_status_0,
    mode_status_1,
    mode_status_2,
};
