#include "macros.h"
#include "mode_debug.h"

#ifndef VERSION_EU
void mode_debug_0(void) {
    m4aMPlayAllStop();
    gUnk_02034898 = EwramAlloc(sizeof(DebugWork));
    func_08006120(1, 16);
    func_0801CB44();
    func_08004DB0();
    SetupBg(0, 0, 15, 0);
    SetupBg(1, 2, 31, 0);
    func_08005610(1, 0x80);
    func_080055EC(1, 0);
    LoadBgTiles(1, gUnk_08C72CE4, 0x5B40);
    LoadBgPalette(1, gUnk_08F683E4, 0x200);
    LoadBgMap(1, gUnk_08EEEB84, 0x800);
    func_08004FC8(1);
    func_08005778(31, 31, 31);
    func_08004FC8(0);
    func_0805FA8C(0, 0x5400, 0x500);
    func_0805FA60(0, gUnk_08F68604, 0x20, 0x0F);
    gUnk_02034898->unk_04 = LoadObjTiles(gUnk_08950902, 0x2E0);
    gUnk_02034898->unk_08 = LoadObjPalette(gUnk_08F685E4, 0x20);
    AnimInit(&gUnk_02034898->unk_0C, gUnk_09EDF774, gUnk_09EDF764);
    AnimStart(&gUnk_02034898->unk_0C, 0, 1);
    func_0805FCB0(0, 0, 2, gUnk_081283CC);

    if (func_08007E50() < 0) {
        func_0805FCB0(168, 150, 2, gUnk_081283E0);
    } else if (func_08007E50() > 0) {
        func_0805FCB0(168, 150, 2, gUnk_081283F0);
    } else {
        func_0805FCB0(144, 150, 2, gUnk_08128400);
    }

    gUnk_02034898->unk_00 = 0;
    gUnk_02034898->unk_01 = -1;
}
#else
INCLUDE_ASM("mode_debug/mode_debug_0.s");
#endif

#ifndef VERSION_EU
void mode_debug_1(void) {
    s16 v;
    s8 old;
    void* gfx;

    v = func_08007E50();

    switch (GetKeysPressed() & 0x300) {
        case 0x100:
            if (v <= 23) {
                func_08007E5C(v + 1);
                func_080010CC(&gUnk_09ECEB64, 0);
                return;
            }
            break;
        case 0x200:
            if (v > -24) {
                func_08007E5C(v - 1);
                func_080010CC(&gUnk_09ECEB64, 0);
                return;
            }
            break;
    }

    if (GetKeysRepeat() & 0x40) {
        gUnk_02034898->unk_00--;
        m4aSongNumStart(101);
    }

    if (GetKeysRepeat() & 0x80) {
        gUnk_02034898->unk_00++;
        m4aSongNumStart(101);
    }

    switch (gUnk_02034898->unk_00) {
        case 0:
            if (GetKeysPressed() & 9) {
                func_080010CC(&gUnk_09EF4EC0, 0);
                return;
            }
            break;
        case 1:
            if (GetKeysPressed() & 9) {
                func_080010CC(&gUnk_09ED8634, 0);
                return;
            }
            break;
        case 2:
            if (GetKeysPressed() & 9) {
                func_080010CC(&gUnk_09EF69D0, 0);
                return;
            }
            break;
        case 3:
            if (GetKeysPressed() & 9) {
                func_080010CC(&gUnk_09ED9B68, 0);
                return;
            }
            break;
        case 4:
            if (GetKeysPressed() & 9) {
                func_080010CC(&gUnk_09ED9A0C, 0);
                return;
            }
            break;
        case 5:
            if (GetKeysPressed() & 9) {
                func_080010CC(&gUnk_09EE47AC, 0);
                return;
            }
            break;
        case 6:
            if (GetKeysPressed() & 9) {
                SaveLoadHeader();
                func_08085FB0();
                func_08085C3C();
                func_080010CC(&gUnk_09EF12F8, 0);
                return;
            }
            break;
        case 7:
            if (GetKeysPressed() & 9) {
                func_080010CC(&gUnk_09ECEB54, 0);
            }
            break;
        case 8:
            if (GetKeysPressed() & 9) {
                func_080010CC(&gUnk_09EF3C88, 0);
            }
            break;
        case 9:
            if (GetKeysPressed() & 9) {
                func_080010CC(&gUnk_09ED9B88, 0);
            }
            break;
        case 10:
            if (GetKeysPressed() & 9) {
                func_080010CC(&gUnk_09EF160C, 0);
            }
            break;
        case 11:
            if (GetKeysPressed() & 9) {
                SaveClearHeader();
                SaveClearFileLarge(0);
                SaveClearFileLarge(1);
                SaveClearFileSmall(0);
                SaveClearFileSmall(1);
                SaveClearSystem();
                func_080010CC(&gUnk_09ECEB64, 0);
            }
            break;
        case 12:
            if (GetKeysPressed() & 9) {
                func_0800FDD0(0);
                func_0800FDD0(17);
                func_0800FDD0(18);
                func_0800FDD0(19);
                func_0800FDD0(20);
                func_0800FDD0(21);
                func_0800FDD0(22);
                func_080010CC(&gUnk_09EF9674, 0);
            }
            break;
        case 13:
            if (GetKeysPressed() & 9) {
                func_080010E0(&gUnk_09EDE4D0, 1);
            }
            break;
        case 14:
            if (GetKeysPressed() & 9) {
                func_080010E0(&gUnk_09EDE4D0, 2);
            }
            break;
        case 15:
            if (GetKeysPressed() & 9) {
                func_080010E0(&gUnk_09EDE4D0, 3);
            }
            break;
        case 16:
            if (GetKeysPressed() & 9) {
                func_080010E0(&gUnk_09EDE4D0, 4);
            }
            break;
        case 17:
            if (GetKeysPressed() & 9) {
                func_080010E0(&gUnk_09EDE4D0, 5);
            }
            break;
        case 18:
            gUnk_02034898->unk_00 = 0;
            break;
        case -1:
            gUnk_02034898->unk_00 = 17;
            break;
    }

    old = gUnk_02034898->unk_01;
    gUnk_02034898->unk_01 = gUnk_02034898->unk_00 / 9;

    if (GetKeysRepeat() & 0x20) {
        gUnk_02034898->unk_01--;

        if (gUnk_02034898->unk_01 < 0) {
            gUnk_02034898->unk_01 = 2;
        }

        gUnk_02034898->unk_00 = gUnk_02034898->unk_01 * 9;
    } else if (GetKeysRepeat() & 0x10) {
        gUnk_02034898->unk_01++;

        if (gUnk_02034898->unk_01 > 2) {
            gUnk_02034898->unk_01 = 0;
        }

        gUnk_02034898->unk_00 = gUnk_02034898->unk_01 * 9;
    }

    if (old != gUnk_02034898->unk_01) {
        switch (gUnk_02034898->unk_01) {
        case 0:
            func_0805FCB0(24, 12, 2, gUnk_08128418);
            func_0805FCB0(24, 28, 2, gUnk_0812842C);
            func_0805FCB0(24, 44, 2, gUnk_08128440);
            func_0805FCB0(24, 60, 2, gUnk_08128454);
            func_0805FCB0(24, 76, 2, gUnk_08128468);
            func_0805FCB0(24, 92, 2, gUnk_0812847C);
            func_0805FCB0(24, 108, 2, gUnk_08128490);
            func_0805FCB0(24, 124, 2, gUnk_081284A4);
            func_0805FCB0(24, 140, 2, gUnk_081284B8);
            break;
        default:
            func_0805FCB0(24, 12, 2, gUnk_081284CC);
            func_0805FCB0(24, 28, 2, gUnk_081284E0);
            func_0805FCB0(24, 44, 2, gUnk_081284F4);
            func_0805FCB0(24, 60, 2, gUnk_08128508);
            func_0805FCB0(24, 76, 2, gUnk_0812851C);
            func_0805FCB0(24, 92, 2, gUnk_08128530);
            func_0805FCB0(24, 108, 2, gUnk_08128544);
            func_0805FCB0(24, 124, 2, gUnk_08128558);
            func_0805FCB0(24, 140, 2, gUnk_0812856C);
            break;
        }
    }

    if (GetKeysPressed() & 4) {
        func_080010CC(&gUnk_09ED9B88, 0);
    }

    func_080605A4(0);
    func_08060598();
    gfx = AnimUpdate(&gUnk_02034898->unk_0C);
    DrawSprite(9, gUnk_02034898->unk_00 % 9 * 16 + 13, gfx, gUnk_02034898->unk_04,
               gUnk_02034898->unk_08, 0, 0, 0);
}
#else
INCLUDE_ASM("mode_debug/mode_debug_1.s");
#endif

void mode_debug_2(void) {
    func_080609A0();
    ReleaseObjTiles(gUnk_02034898->unk_04);
    ReleaseObjPalette(gUnk_02034898->unk_08);
    EwramFree(gUnk_02034898);
}

void func_0800B30C(ObjDef* def) {
    func_08005974(&gUnk_0203489C->unk_24, gUnk_0203489C->unk_16, 0, def->unk_04, def->unk_00);
    func_08002A10(gUnk_0203489C->unk_1C, def->unk_08);
    ReleaseObjPalette(gUnk_0203489C->unk_20);
    gUnk_0203489C->unk_20 = LoadObjPalette(def->unk_10, def->unk_1C);
}
