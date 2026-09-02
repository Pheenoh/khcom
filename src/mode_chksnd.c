#include "macros.h"
#include "mode_chksnd.h"
#include "gba/keys.h"

void mode_chksnd_0(void) {
    func_08004DB0();
    gUnk_020348B4 = 0;
    TaskPoolInit(&gUnk_020348A0, 10);
    TaskCreate(&gUnk_020348A0, &gUnk_09EE9190, 0);
}

#ifndef VERSION_EU
void mode_chksnd_1(void) {
    u16 keys;

    keys = GetKeysPressed() & 2;

    if (keys != 0) {
        func_080010CC(&gUnk_09ECEB64, 0);
    } else {
        if (GetKeysRepeat() & DPAD_LEFT) {
            gUnk_020348B4--;
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            gUnk_020348B4++;
        }

        if (GetKeysPressed() & 1) {
            m4aSongNumStart(gUnk_09ED8644[gUnk_020348B4].unk_04);
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
        TaskPoolUpdate(&gUnk_020348A0);
        TaskPoolDraw(&gUnk_020348A0);
    }
}
#else
INCLUDE_ASM("mode_chksnd/mode_chksnd_1.s");
#endif

void mode_chksnd_2(void) {
    m4aMPlayAllStop();
    TaskPoolDestroy(&gUnk_020348A0);
}
