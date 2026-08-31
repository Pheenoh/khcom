#include "macros.h"
#include "mode_chksnd.h"

void mode_chksnd_0(void) {
    func_08004DB0();
    gUnk_020348B4 = 0;
    func_08000E64(&gUnk_020348A0, 10);
    func_08000E14(&gUnk_020348A0, &gUnk_09EE9190, 0);
}

void mode_chksnd_1(void) {
    u16 keys;

    keys = func_08001390() & 2;

    if (keys != 0) {
        func_080010CC(&gUnk_09ECEB64, 0);
    } else {
        if (func_0800139C() & 0x20) {
            gUnk_020348B4--;
        }

        if (func_0800139C() & 0x10) {
            gUnk_020348B4++;
        }

        if (func_08001390() & 1) {
            func_0811FE70(gUnk_09ED8644[gUnk_020348B4].unk_04);
        }

        if (gUnk_020348B4 < 0) {
            gUnk_020348B4 = 632;
        }

        if ((u16)gUnk_020348B4 > 632) {
            gUnk_020348B4 = 0;
        }

        func_0809D2B0(0, 0, 0, gUnk_081309B0);
        func_0809D458(0, 0, 0, gUnk_09ED8644[gUnk_020348B4].unk_04);
        func_0809D2B0(5, 0, 0, gUnk_081309D0);
        func_0809D2B0(7, 0, 0, gUnk_09ED8644[gUnk_020348B4].name);
        func_08000EA4(&gUnk_020348A0);
        func_08000EE0(&gUnk_020348A0);
    }
}

void mode_chksnd_2(void) {
    func_0811FFA4();
    func_08000F0C(&gUnk_020348A0);
}
