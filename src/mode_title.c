#include "macros.h"
#include "mode_title.h"

#ifndef VERSION_EU
void mode_title_0(void) {
    gUnk_02034ECA = 0;
    func_0801CB44();
    SaveLoadHeader();
    func_08093BB4();
    func_08093C04();
    gUnk_02034EC2 = 0;
    gUnk_02034EC4 = EwramAlloc(0x400);
    func_08004E64();
    SetupBg(0, 0, 0x1D, 0);
    SetBgPriority(0, 3);
    if (gUnk_02039BB0.unk_008 & 0x200) {
        LoadBgMap(0, gUnk_09840798, 0x800);
    } else {
        LoadBgMap(0, gUnk_0983E398, 0x800);
    }
    func_0800501C(0);
    SetupBg(1, 0, 0x1E, 0);
    SetBgPriority(1, 3);
    if (gUnk_02039BB0.unk_008 & 0x200) {
        LoadBgTiles(1, gUnk_097D3658, 0x7FA0);
        LoadBgMap(1, gUnk_09840F98, 0x800);
    } else {
        LoadBgTiles(1, gUnk_097C77B8, 0x7FA0);
        LoadBgMap(1, gUnk_0983EB98, 0x800);
    }
    func_0800501C(1);
    func_080C736C();
    func_080C73A4(0, 0, 0);
    SetupBg(2, 2, 0x1F, 0xB);
    func_080055EC(2, 0x4000);
    SetBgPriority(2, 2);
    LoadBgTiles(2, gUnk_097CF758, 0x3F00);
    LoadBgPalette(2, gUnk_0984A618, 0xA0);
    LoadBgMap(2, gUnk_0983FB98, 0x400);
    gUnk_0203C548 = 0x7800;
    gUnk_0203C54C = 0x5A00;
    gUnk_0203C544 = 0x1000;
    func_08005690(2, 0, gUnk_0203C544 >> 4, gUnk_0203C544 >> 4, gUnk_0203C548, gUnk_0203C54C);
    TaskPoolInit(&gUnk_02034EA0, 4);
    gUnk_02034EB8 = 0;
    gUnk_02034EBC = 0;
    func_08006120(0, 0x4C);
    gUnk_02034E98 = 0;
    m4aSongNumStart(0);
    gUnk_02034EC0 = 0x1E;
}
#else
INCLUDE_ASM("mode_title/mode_title_0.s");
#endif

void mode_title_1(void) {
    switch (gUnk_02034E98) {
    case 0:
        if (func_08006314()) {
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
        if (gUnk_02039BB0.unk_008 & 0x200) {
            func_080058FC(&gUnk_0203C548, 0x3F3F, gUnk_02034EC0);
        } else {
            func_080058FC(&gUnk_0203C548, 0xB0C1, gUnk_02034EC0);
        }
        func_080058FC(&gUnk_0203C54C, 0x6A37, gUnk_02034EC0);
        func_080058FC(&gUnk_0203C544, 0xBD0, gUnk_02034EC0);
        func_08005690(2, 0, gUnk_0203C544 / 16, gUnk_0203C544 / 16, gUnk_0203C548, gUnk_0203C54C);
        gUnk_02034EC0--;
        if (gUnk_02034EC0 == 0x46) {
            func_080C75A4(1, 0x46);
            if (gUnk_02034EC0 == 0x46) {
                func_08006184(1, 0x46);
            }
        }
        if (gUnk_02034EC0 == 0) {
            gUnk_02034E98 = 2;
            gUnk_02034EC0 = 2;
        }
        break;
    case 2:
        if (func_08006314()) {
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
        if (func_08006314()) {
            break;
        }
        if (gUnk_02034EC0 != 0) {
            gUnk_02034EC0--;
            break;
        }
        gUnk_02034E98 = 4;
        gUnk_02034EC8 = 0;
        gUnk_03007554 = 0x1343;
        gUnk_03007564 = 0x10;
        gUnk_02034EC0 = 4;
        func_08004FC8(1);
        break;
    case 4:
        if (gUnk_02034EC0 != 0) {
            gUnk_02034EC0--;
            break;
        }
        gUnk_02034EC0 = 4;
        gUnk_02034EC8++;
        gUnk_03007564 = (gUnk_02034EC8 << 8) | (16 - gUnk_02034EC8);
        if (gUnk_02034EC8 > 15) {
            gUnk_03007554 = 0;
            func_080D5B04();
            gUnk_02034E98 = 5;
        }
        break;
    case 5:
        if (!func_080D6790()) {
            break;
        }
        if (!(GetKeysPressed() & 8) && !(GetKeysPressed() & 1)) {
            break;
        }
        m4aSongNumStart(0x66);
        if (SaveRepairSystem() == 2) {
            gUnk_02034EC2 = 3;
        } else if (SaveRepairFileLarge(0) == 2 || SaveRepairFileLarge(1) == 2) {
            gUnk_02034EC2 = 1;
        } else if ((gUnk_02039BB0.unk_008 & 0x20) &&
                   (SaveRepairFileSmall(0) == 2 || SaveRepairFileSmall(1) == 2)) {
            gUnk_02034EC2 = 1;
        } else {
            gUnk_02034EC2 = 0;
        }
        func_08000DE8(&gUnk_02034EA0, gUnk_02034EB8);
        func_08000DE8(&gUnk_02034EA0, gUnk_02034EBC);
        gUnk_02034EB4 = TaskCreate(&gUnk_02034EA0, &gUnk_09EF4E90, &gUnk_02034EC2);
        func_0800501C(0);
        gUnk_02034E98 = 6;
        gUnk_02034EC8 = 0;
        gUnk_03007554 = 0x250;
        gUnk_03007564 = ((16 - gUnk_02034EC8) << 8) | gUnk_02034EC8;
        gUnk_02034EC0 = 4;
        break;
    case 6:
        if (gUnk_02034EC0 != 0) {
            gUnk_02034EC0--;
            break;
        }
        gUnk_02034EC0 = 4;
        gUnk_02034EC8++;
        gUnk_03007564 = ((16 - gUnk_02034EC8) << 8) | gUnk_02034EC8;
        if (gUnk_02034EC8 > 15) {
            gUnk_03007554 = 0;
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
        gUnk_03007564 = ((16 - gUnk_02034EC8) << 8) | gUnk_02034EC8;
        if (gUnk_02034EC8 > 15) {
            gUnk_03007554 = 0;
            func_08000DE8(&gUnk_02034EA0, gUnk_02034EB4);
            gUnk_02034EB8 = TaskCreate(&gUnk_02034EA0, &gUnk_09EF4E60, 0);
            gUnk_02034EBC = TaskCreate(&gUnk_02034EA0, &gUnk_09EF4E78, 0);
            func_08004FC8(0);
            gUnk_02034E98 = 5;
        }
        break;
    case 8:
        if ((GetKeysPressed() & 8) || (GetKeysPressed() & 1)) {
            switch (gUnk_02034EC2) {
            case 0:
            case 4:
            case 5:
                m4aSongNumStart(0x93);
                break;
            default:
                m4aSongNumStart(0x66);
                break;
            }
            func_080D5B30();
        } else if (GetKeysPressed() & 2) {
            m4aSongNumStart(0x68);
            gUnk_02034ECA = 1;
            func_080D5B30();
        }
        break;
    case 9:
        if (!func_08006314()) {
            func_080D59B4();
        }
        break;
    }

    if (!func_08006314() && gUnk_02034E98 != 6) {
        TaskPoolUpdate(&gUnk_02034EA0);
    }
    TaskPoolDraw(&gUnk_02034EA0);
    func_080C73D8();
    if (gUnk_02034E98 <= 4 && (GetKeysPressed() & 9)) {
        m4aSongNumStart(0x65);
        if (gUnk_02034E98 <= 3) {
            func_080D5A4C(2);
        }
        func_080D5B04();
        gUnk_02034E98 = 5;
    }
}

void mode_title_2(void) {
    TaskPoolDestroy(&gUnk_02034EA0);
    REG_IME = 0;
    REG_IE &= 0xFFFB;
    REG_DISPSTAT &= 0xFFDF;
    REG_IME = 1;
    func_08006C68();
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
    work->unk_00 = LoadObjTiles(gUnk_0976E9F4, 0x240);
    work->unk_08 = gUnk_09EF659C;
    if (gUnk_02039BB0.unk_008 & 0x200) {
        work->unk_0C = LoadObjTiles(gUnk_09776076, 0x43C0);
        work->unk_14 = gUnk_09EF669C;
        work->unk_10 = LoadObjPalette(gUnk_0984AA18, 0x20);
    } else {
        work->unk_0C = LoadObjTiles(gUnk_0976EC54, 0xE0);
        work->unk_14 = gUnk_09EF65A4;
        work->unk_10 = LoadObjPalette(gUnk_0984A6D8, 0x20);
    }
    work->unk_18 = LoadObjTiles(gUnk_0976ED5A, 0x380);
    work->unk_20 = gUnk_09EF65AC;
    work->unk_24 = LoadObjTiles(gUnk_0976F0F6, 0xC0);
    work->unk_2C = gUnk_09EF65B4;
    work->unk_30 = LoadObjTiles(gUnk_0976F1F0, 0xAC0);
    work->unk_38 = gUnk_09EF65BC;
    work->unk_3C = LoadObjTiles(gUnk_0976FD96, 0x1140);
    work->unk_44 = gUnk_09EF65C4;
    work->unk_04 = LoadObjPalette(gUnk_0984A6B8, 0x20);
    work->unk_1C = LoadObjPalette(gUnk_0984A6F8, 0x20);
    work->unk_28 = LoadObjPalette(gUnk_0984A6F8, 0x20);
    work->unk_34 = LoadObjPalette(gUnk_0984A718, 0x20);
    work->unk_40 = LoadObjPalette(gUnk_0984A738, 0x20);
    work->unk_4C = 0;
    work->unk_48 = 0xC00;
    work->unk_50 = 0;
    gUnk_02034ECC = 0;
}
