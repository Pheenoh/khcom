#include "macros.h"
#include "mode_status.h"

void mode_status_0(void) {
    func_08004D74();
    func_08004DB0();
    SetupBg(0, 0, 0x1F, 0);
    SetupBg(2, 0, 0x1E, 0);
    SetupBg(3, 0, 0x1D, 0);
    SetBgPriority(0, 1);
    SetBgPriority(2, 2);
    SetBgPriority(3, 3);
    LoadBgTiles(3, gUnk_097FFB98, 0x2100);
    LoadBgPalette(3, gUnk_0984B118, 0xA0);
    LoadBgMap(3, gUnk_09848198, 0x500);

    if (gUnk_02039BB0.unk_008 & 8) {
        LoadBgMap(2, gUnk_09847C98, 0x500);
    } else {
        LoadBgMap(2, gUnk_09847798, 0x500);
    }

    LoadBgMap(0, gUnk_09848B98, 0x500);
    func_0800501C(0);
    func_080D733C();
    TaskPoolInit(&gUnk_02034EE0, 4);
    gUnk_02034EF4 = TaskCreate(&gUnk_02034EE0, &gUnk_09EF4F08, 0);
    TaskCreate(&gUnk_02034EE0, &gUnk_09EF4EF0, 0);
    func_08006120(0, 0x10);
}

void mode_status_1(void) {
    func_0801CC80();
    TaskPoolUpdate(&gUnk_02034EE0);
    TaskPoolDraw(&gUnk_02034EE0);

    if (!func_08000F48(gUnk_02034EF4) && !func_08006314()) {
        func_080E052C(gUnk_02034EF8);
    }
}

void mode_status_2(void) {
    TaskPoolDestroy(&gUnk_02034EE0);
}

void func_080D7568(u8 a) {
    gUnk_02034EF8 = a;
}
