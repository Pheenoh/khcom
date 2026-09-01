#include "macros.h"
#include "mode_dummy.h"

#ifndef VERSION_EU
void mode_dummy_0(u32 arg) {
    DummyEntry* entry;

    func_08006120(0, 0x10);
    func_08004DB0();
    SetupBg(0, 0, 0x0F, 0);
    func_08004FC8(0);
    func_0805FA8C(0, 0x5400, 0x500);
    func_0805FA60(0, gUnk_08128304, 0x20, 0x0F);
    SetupBg(1, 1, 0x0C, 8);
    LoadBgTiles(1, gUnk_08C6B0C4, 0x7C20);
    LoadBgPalette(1, gUnk_08F683C4, 0x20);
    LoadBgMap(1, gUnk_08EEE384, 0x800);
    func_08004FC8(1);
    gUnk_020348BC = arg;

    if (arg > 9) {
        gUnk_020348BC = 0;
        func_0805FCB0(0, 0, 2, gUnk_08130BC8);
    } else {
        gUnk_020348BC = arg;
        entry = &gUnk_08130A4C[arg];
        func_0805FCB0(0, 0, 2, entry->name);
        func_0805FCB0(0x10, 0x18, 2, entry->desc);
    }
}
#else
INCLUDE_ASM("mode_dummy/mode_dummy_0.s");
#endif

void func_0800C064(void) {
    DummyEntry* entry;

    if (!func_08006314()) {
        entry = &gUnk_08130A4C[gUnk_020348BC];

        switch (entry->unk_08) {
            case 0:
                func_080010E0(&gUnk_09EDE4D0, 1);
                break;
            case 1:
                gUnk_02039BB0.unk_180 = 0x200;
                func_080010CC(&gUnk_09EF8F9C, 0);
                break;
            case 2:
                func_080DF380();
                func_080E04EC();
                break;
            case 3:
                func_0806180C(6);
                break;
            case 4:
                func_0806180C(0x14);
                break;
            case 5:
                func_0806180C(0x1C);
                break;
            case 6:
                func_0806180C(0x2C);
                break;
            case 7:
                func_0806180C(0x3D);
                break;
            case 8:
                func_0806180C(0x49);
                break;
            case 9:
            default:
                func_080010CC(&gUnk_09EF4EC0, 0);
                break;
        }
    } else {
        func_080605A4(0);
        func_08060598();
        SetBgScroll(1, (gFrameCounter << 14) >> 16, 0);
        func_0801CC80();
    }
}

void mode_dummy_1(void) {
    if (!func_08006314() && (GetKeysPressed() & 9)) {
        func_08006184(0, 0x10);
        func_08001248(func_0800C064);
    }

    func_080605A4(0);
    func_08060598();
    SetBgScroll(1, (gFrameCounter << 14) >> 16, 0);
    func_0801CC80();
}

void mode_dummy_2(void) {
    func_080609A0();
}

ALIGN_ZERO(2);
