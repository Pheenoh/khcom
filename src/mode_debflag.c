#include "macros.h"
#include "mode_debflag.h"
#include "gba/keys.h"

void mode_debflag_0(s32 arg) {
    s32 i;

    func_08004DB0();
    SetupBg(0, 0, 0x0F, 0);
    EnableBg(0);
    func_0805FA8C(0, 0x5400, 0x500);
    func_0805FA60(0, gUnk_08128304, 0x20, 0x0F);
    gUnk_020348C0 = 0;
    func_0805FCB0(0, 0, 2, gUnk_08130E34);

    if (arg != 0) {
        gUnk_020348C1 = 7;
        gUnk_020348C4 = gUnk_08130DE0;
        gUnk_02039B94 = 1;
    } else {
        gUnk_020348C1 = 14;
        gUnk_020348C4 = gUnk_08130BE8;
        gUnk_02039B94 = 0;
    }

    for (i = 0; i < gUnk_020348C1; i++) {
        func_0805FCB0(0x0C, i * 9, 2, gUnk_020348C4[i].name);

        if (gUnk_03006C10 & gUnk_020348C4[i].mask) {
            func_0805FCB0(0x78, i * 9, 2, gUnk_08130E38);
        } else {
            func_0805FCB0(0x78, i * 9, 2, gUnk_08130E40);
        }
    }
}

void mode_debflag_1(void) {
    u8 prev;
    DebugFlag* entry;

    prev = gUnk_020348C0;

    if (GetKeysRepeat() & DPAD_UP) {
        gUnk_020348C0--;
    }

    if (GetKeysRepeat() & DPAD_DOWN) {
        gUnk_020348C0++;
    }

    if (prev != gUnk_020348C0) {
        if (gUnk_020348C0 < 0) {
            gUnk_020348C0 = gUnk_020348C1 - 1;
        } else if (gUnk_020348C0 >= gUnk_020348C1) {
            gUnk_020348C0 = 0;
        }

        func_0805FCB0(0, prev * 9, 2, gUnk_08130E48);
        func_0805FCB0(0, gUnk_020348C0 * 9, 2, gUnk_08130E34);
    }

    if (GetKeysPressed() & (DPAD_RIGHT | DPAD_LEFT)) {
        entry = &gUnk_020348C4[gUnk_020348C0];
        gUnk_03006C10 ^= entry->mask;

        if (gUnk_03006C10 & entry->mask) {
            func_0805FCB0(0x78, gUnk_020348C0 * 9, 2, gUnk_08130E38);
        } else {
            func_0805FCB0(0x78, gUnk_020348C0 * 9, 2, gUnk_08130E40);
        }
    }

    if (GetKeysPressed() & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON)) {
        if (gUnk_02039B94 != 0) {
            func_080E04EC();
        } else {
            func_080010CC(&gUnk_09ECEB64, 0);
        }
    } else {
        func_080605A4(0);
        func_08060598();
    }
}

void mode_debflag_2(void) {
    func_080609A0();
}

ALIGN_ZERO(2);
