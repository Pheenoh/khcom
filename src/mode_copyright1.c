#include "macros.h"
#include "mode_copyright1.h"

void mode_copyright1_0(s32 arg) {
    if (arg == 0) {
        gUnk_02034ED4 = 1;
    } else {
        gUnk_02034ED4 = 0;
    }

    gUnk_02034ED8 = 0;

    if (SaveRepairHeader() == 1) {
        gUnk_02034ED8 = 1;
        SaveClearHeader();
        SaveClearSystem();
        SaveClearFileLarge(0);
        SaveClearFileLarge(1);
        SaveClearFileSmall(0);
        SaveClearFileSmall(1);
    }

    if (SaveRepairFileLarge(0) == 1) {
        gUnk_02034ED8 = 1;
        SaveClearFileLarge(0);
    }

    if (SaveRepairFileLarge(1) == 1) {
        gUnk_02034ED8 = 1;
        SaveClearFileLarge(1);
    }

    if (SaveRepairFileSmall(0) == 1) {
        gUnk_02034ED8 = 1;
        SaveClearFileSmall(0);
    }

    if (SaveRepairFileSmall(1) == 1) {
        gUnk_02034ED8 = 1;
        SaveClearFileSmall(1);
    }

    if (SaveRepairSystem() == 1) {
        gUnk_02034ED8 = 1;
        SaveClearSystem();
    }

    m4aSongNumStart(0);
    func_08004DB0();
    SetupBg(0, 0, 0x1F, 0);
    SetBgPriority(0, 3);

    if (gUnk_02034ED4 != 0) {
        LoadBgTiles(0, gUnk_09801DD8, 0x4FC0);
        LoadBgPalette(0, gUnk_0984B298, 0x1C0);
        LoadBgMap(0, gUnk_09849098, 0x800);
    } else {
        LoadBgTiles(0, gUnk_097DB5F8, 0x4FC0);
        LoadBgPalette(0, gUnk_0984AA38, 0x200);
        LoadBgMap(0, gUnk_09841798, 0x800);
    }

    func_08006120(1, 0x43);
    gUnk_02034ED6 = 60;
}

void mode_copyright1_1(void) {
    if (gUnk_02034ED8 != 0) {
        func_080010CC(&gUnk_09EF6AF0, 0);
    } else if (!func_08006314()) {
        if (gUnk_02034ED6 != 0) {
            if (--gUnk_02034ED6 == 0) {
                func_08006184(1, 0x43);
            }
        } else if (gUnk_02034ED4 != 0) {
            func_080010CC(&gUnk_09EF4EC0, 1);
        } else {
            func_080010CC(&gUnk_09EF4ED0, 1);
        }
    }
}

void mode_copyright1_2(void) {
}

ALIGN_ZERO(2);
