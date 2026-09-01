#include "mode_battle.h"

void mode_battle_0(u32 mode) {
    void** p;
    vu32 zero;

    gUnk_02039B84 = EwramAlloc(sizeof(BattleWork));
    gUnk_02039B9C = 0;
    func_08019270();
    func_0801C068();
    gUnk_02039B84->unk_10C = mode;
    gUnk_02039BB0.unk_008 &= ~0x40;

    switch (mode) {
    case 0x94 ... 0x9C:
        gUnk_02039B84->unk_068 |= 4;
        break;
    case 0xB2 ... 0xB8:
        gUnk_02039B84->unk_068 |= 0x800000000;
    case 0x9D ... 0xB1:
        gUnk_02039B84->unk_068 |= 0x800;
        p = &gUnk_02039B9C;
        *p = EwramAlloc(sizeof(BattleWork));
        zero = 0;
        CpuSet((void*)&zero, gUnk_02039B9C, CPU_SET_32BIT | CPU_SET_SRC_FIXED | (sizeof(BattleWork) / 4));
        break;
    }

    if (gUnk_02039B84->unk_068 & 4) {
        func_08004E64();

        switch (mode) {
        case 0x9C:
            m4aSongNumStart(42);
            break;
        case 0x95:
        case 0x97:
        case 0x99:
        case 0x9B:
            m4aSongNumStart(41);
            break;
        case 0x94:
        case 0x96:
        case 0x98:
        case 0x9A:
        default:
            m4aSongNumStart(3);
            break;
        }

        gUnk_02039B84->unk_1C4 = 2;

        switch (mode) {
        case 0x98:
        case 0x9C:
            SetupBg(0, 0, 22, 0);
            SetupBg(1, 0, 24, 0);
            SetupBg(2, 2, 28, 10);
            SetBgPriority(0, 2);
            SetBgPriority(2, 0);
            SetBgPriority(1, 1);
            func_08005654(2, 0);
            func_080055EC(1, 0x4000);
            break;
        case 0x94:
        case 0x95:
        case 0x96:
        case 0x97:
        case 0x99:
        case 0x9A:
        case 0x9B:
        default:
            SetupBg(0, 0, 24, 0);
            SetupBg(1, 0, 26, 0);
            SetupBg(2, 2, 28, 10);
            SetBgPriority(0, 2);
            SetBgPriority(2, 0);
            SetBgPriority(1, 1);
            func_08005654(2, 0);
            break;
        }
    } else if (gUnk_02039B84->unk_068 & 0x800000000) {
        m4aSongNumStart(4);
        gUnk_02039B84->unk_1C4 = 3;
        gUnk_02039B84->unk_1C6 = 2;
        func_08004F08();
        SetupBg(gUnk_02039B84->unk_1C6, 0, 12, 0);
        SetupBg(gUnk_02039B84->unk_1C4, 2, 28, 10);
        SetBgPriority(gUnk_02039B84->unk_1C6, 2);
        SetBgPriority(gUnk_02039B84->unk_1C4, 0);
        func_08005654(gUnk_02039B84->unk_1C6, 1);
        func_08005654(gUnk_02039B84->unk_1C4, 0);
    } else if (gUnk_02039B84->unk_068 & 0x800) {
        gUnk_02039B84->unk_1C4 = 2;
        gUnk_02039B84->unk_1C6 = 3;

        switch (mode) {
        case 0xA1:
        case 0xA8 ... 0xAC:
            m4aSongNumStart(35);
            break;
        case 0x9D:
        case 0x9F:
            m4aSongNumStart(4);
            break;
        case 0xA5:
            m4aSongNumStart(37);
            break;
        case 0x9E:
        case 0xA0:
            m4aSongNumStart(41);
            break;
        case 0xB1:
            m4aSongNumStart(29);
            break;
        default:
            m4aSongNumStart(14);
            break;
        }

        func_08004F08();
        SetupBg(3, 0, 12, 0);
        SetupBg(2, 2, 28, 10);
        SetBgPriority(3, 2);
        SetBgPriority(2, 0);
        func_08005654(3, 1);
        func_08005654(2, 0);
    } else {
        gUnk_02039B84->unk_1C4 = 2;
        gUnk_02039B84->unk_1C6 = 3;

        switch (gUnk_02039BB0.unk_00D) {
        case 1:
        case 2:
            m4aSongNumStart(1);
            break;
        case 3:
            m4aSongNumStart(23);
            break;
        case 4:
            m4aSongNumStart(17);
            break;
        case 5:
            if (mode == 0x79) {
                m4aSongNumStart(4);
            } else {
                m4aSongNumStart(9);
            }
            break;
        case 6:
            m4aSongNumStart(20);
            break;
        case 7:
            m4aSongNumStart(16);
            break;
        case 8:
            m4aSongNumStart(11);
            break;
        case 10:
            m4aSongNumStart(26);
            break;
        case 11:
            m4aSongNumStart(12);
            break;
        case 9:
            m4aSongNumStart(40);
            break;
        case 12:
            m4aSongNumStart(39);
            break;
        case 13:
            m4aSongNumStart(43);
            break;
        }

        func_08004F08();
        SetupBg(3, 0, 12, 0);
        SetupBg(2, 2, 28, 10);
        SetBgPriority(3, 2);
        SetBgPriority(2, 0);
        func_08005654(3, 1);
        func_08005654(2, 0);
    }

    TaskPoolInit(&gUnk_02039B84->unk_02C, 40);
    TaskPoolInit(&gUnk_02039B84->unk_040, 32);
    TaskPoolInit(&gUnk_02039B84->unk_054, 1);
    func_08012798(0x80, gUnk_02039B84->unk_1C4);
    func_0801227C();

    if (gUnk_02039BB0.unk_008 & 8) {
        TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDAE58, 0);
    } else {
        TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDAE40, 0);
    }

    if (gUnk_02039B84->unk_068 & 4) {
        gUnk_02039B84->unk_068 |= 0x400000000;

        switch (mode) {
        case 0x9A:
            func_0801A920(0, 0x100, 0x148, 0x1A8);
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EF2A8C, 0);
            gUnk_02039B84->unk_0B3 = 10;
            break;
        case 0x94:
            func_0801A920(-32, 0x120, 0x120, 0x180);
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EF8E94, 0);
            gUnk_02039B84->unk_0B3 = 5;
            break;
        case 0x99:
            func_0801A920(0, 0xE0, 0x118, 0x180);
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EF8EAC, 0);
            gUnk_02039B84->unk_0B3 = 5;
            break;
        case 0x96:
            func_0801A920(0x80, 0x180, 0x140, 0x180);
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EF1D40, 0);
            gUnk_02039B84->unk_0B3 = 12;
            break;
        case 0x97:
            func_0801A920(0, 0x200, 0, 0x200);
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EF51C0, 0);
            gUnk_02039B84->unk_0B3 = 5;
            break;
        case 0x98:
            func_0801A920(0x80, 0x1A8, 0x126, 0x180);
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EF9DEC, 0);
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDB590, gUnk_02039B84->unk_07C);
            gUnk_02039B84->unk_0B3 = 12;
            break;
        case 0x9C:
            func_0801A920(0x80, 0x170, 0x1E0, 0x200);
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EF9E54, 0);
            gUnk_02039B84->unk_0B3 = 10;
            break;
        case 0x9B:
            func_0801A920(0x80, 0x170, 0x228, 0x278);
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EF5010, 0);
            gUnk_02039B84->unk_128 = &func_0801050C;
            gUnk_02039B84->unk_0B3 = 5;
            break;
        default:
            func_0801A920(0x1A4, 0x264, 0x148, 0x180);
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EF2744, 0);
            gUnk_02039B84->unk_128 = &func_080BD4A8;
            gUnk_02039B84->unk_0B3 = 10;
            break;
        }
    } else if (gUnk_02039B84->unk_068 & 0x800000000) {
        func_0801A920(0x68, 0x198, 0x160, 0x1A2);

        if (mode == 0xB2) {
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDB7D0, 0);
            TaskCreate(&gUnk_02039B84->unk_040, &gUnk_09EDE4B8, 0);
        } else {
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDB7B8, 0);
            TaskCreate(&gUnk_02039B84->unk_040, &gUnk_09EDE4B8, (void*)1);
        }

        gUnk_02039BB0.unk_00D = 11;
        TaskCreate(&gUnk_02039B84->unk_040, &gUnk_09EDAE70, 0);
    } else if (gUnk_02039B84->unk_068 & 0x800) {
        gUnk_02039B84->unk_068 |= 0x400000000;

        switch (mode) {
        case 0x9E:
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDB5C0, 0);
            func_0801A920(0x68, 0x198, 0x160, 0x1A2);
            break;
        case 0xA6:
        case 0xB1:
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDB608, 0);
            func_0801A920(0x50, 0x1B0, 0x160, 0x1A2);
            break;
        case 0x9F:
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDB5A8, 0);
            func_0801A920(0x50, 0x1B0, 0x160, 0x1A2);
            break;
        case 0xA0:
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDB620, 0);
            func_0801A920(0x50, 0x1B0, 0x160, 0x1A2);
            break;
        case 0xA5:
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDB638, 0);
            func_0801A920(0x50, 0x1B0, 0x160, 0x1A2);
            break;
        case 0xA3:
        case 0xAE:
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDB650, 0);
            func_0801A920(0x50, 0x1B0, 0x160, 0x1A2);
            break;
        case 0xA2:
        case 0xAD:
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDB680, 0);
            func_0801A920(0x50, 0x1B0, 0x160, 0x1A2);
            break;
        case 0xA4:
        case 0xAF:
        case 0xB0:
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDB6B0, 0);
            func_0801A920(0x50, 0x1B0, 0x160, 0x1A2);
            break;
        case 0xA7:
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDB728, 0);
            func_0801A920(0x50, 0x1B0, 0x160, 0x1A2);
            break;
        case 0x9D:
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDB7B8, 0);
            func_0801A920(0x50, 0x1B0, 0x160, 0x1A2);
            break;
        default:
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDB7A0, 0);
            func_0801A920(0x50, 0x1B0, 0x160, 0x1A2);
            break;
        }

        TaskCreate(&gUnk_02039B84->unk_040, &gUnk_09EDAE70, 0);
    } else {
        func_0801A920(0x68, 0x198, 0x160, 0x1A2);

        if (mode <= 0x92) {
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDB3B0, gUnk_09EDA2A0[mode]);
        } else if (gUnk_03006C10 & 1) {
            func_0800AB8C();
        }

        TaskCreate(&gUnk_02039B84->unk_040, &gUnk_09EDAE70, 0);

        if (mode == 0x79) {
            gUnk_02039B84->unk_068 |= 0x400000000;
            gUnk_02039BB0.unk_008 |= 0x400;
            TaskCreate(&gUnk_02039B84->unk_02C, &gUnk_09EDE440, 0);
        }
    }

    if (!(gUnk_02039B84->unk_068 & 0x800000000)) {
        TaskCreate(&gUnk_02039B84->unk_054, &gUnk_09EDAED0, 0);
    }

    func_08006120(0, 60);
    gUnk_02039BB0.unk_010++;
}

void mode_battle_1(void) {
    TaskPoolUpdate(&gUnk_02039B84->unk_054);
    TaskPoolDraw(&gUnk_02039B84->unk_054);

    if (gUnk_02039B84->unk_074 > 0) {
        TaskPoolDraw(&gUnk_02039B84->unk_040);
        TaskPoolDraw(&gUnk_02039B84->unk_02C);
        gUnk_02039B84->unk_074--;
    } else {
        if (gUnk_02039B84->unk_070 == 0) {
            _08019CB4();

            if (gUnk_02039B84->unk_072 <= 0) {
                TaskPoolUpdate(&gUnk_02039B84->unk_02C);
            } else {
                gUnk_02039B84->unk_072--;
            }

            if (!(gUnk_02039B84->unk_068 & 0x200000000000000)) {
                func_08012824();
            }

            func_080125A4();
            TaskPoolDraw(&gUnk_02039B84->unk_040);

            if (gUnk_02039B84->unk_068 & 0x800000) {
                gUnk_02039B84->unk_068 &= ~0x800000;
            }

            func_0801CC80();
        }

        if (!(gUnk_02039B84->unk_068 & 0x2000)) {
            TaskPoolDraw(&gUnk_02039B84->unk_02C);
        }
    }
}

void mode_battle_2(void) {
    gUnk_02039BB0.unk_008 &= ~4;
    func_08012810();
    TaskPoolDestroy(&gUnk_02039B84->unk_054);
    TaskPoolDestroy(&gUnk_02039B84->unk_040);
    TaskPoolDestroy(&gUnk_02039B84->unk_02C);
    func_0801C104();

    if (gUnk_02039B84->unk_068 & 0x800) {
        EwramFree(gUnk_02039B9C);
    }

    EwramFree(gUnk_02039B84);
}
