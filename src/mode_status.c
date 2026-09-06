#include "macros.h"
#include "mode_status.h"

#ifdef VERSION_EU
extern u32 gLanguage;
extern u8 gUnkEu_097D8300[];
extern u8 gUnkEu_097D8F00[];
extern u8 gUnkEu_097D9B00[];
extern u8 gUnkEu_097DA700[];
void* GetBgCharBase(s32 bg);
u8 RequestDma3Copy(void* src, void* dst, u16 size);
#endif

TaskPool gUnk_02034EE0;
Task* gUnk_02034EF4;
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
    TaskPoolInit(&gUnk_02034EE0, 4);
    gUnk_02034EF4 = TaskCreate(&gUnk_02034EE0, &gTaskDescStatusBar, 0);
    TaskCreate(&gUnk_02034EE0, &gTaskDescStatus, 0);
    func_08006120(0, 0x10);
}

void mode_status_1(void) {
    UpdatePlayTime();
    TaskPoolUpdate(&gUnk_02034EE0);
    TaskPoolDraw(&gUnk_02034EE0);

    if (!IsTaskActive(gUnk_02034EF4) && !func_08006314()) {
        func_080E052C(gUnk_02034EF8);
    }
}

void mode_status_2(void) {
    TaskPoolDestroy(&gUnk_02034EE0);
}

void func_080D7568(u8 a) {
    gUnk_02034EF8 = a;
}
