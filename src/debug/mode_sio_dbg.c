#include "macros.h"
#include "registration_data.h"
#include "mode_sio_dbg.h"
#include "mode_chkbtl.h"
#include "mode_sio_api.h"
#include "game_state.h"
#include "obj_api.h"
#include "display.h"
#include "key.h"
#include "gba/keys.h"
#include "mode.h"
#include "mode_test_api.h"

#ifdef VERSION_EU
u16 gUnk_0203C3C4 EWRAM_COMMON(4);
#else
s8 gUnk_0203C3C4 EWRAM_COMMON(4);
#endif
u16 gUnk_0203C3C8 EWRAM_COMMON(4);
u16 gUnk_0203C3CC EWRAM_COMMON(4);
u16 gUnk_0203C3D0 EWRAM_COMMON(4);
#ifdef VERSION_EU
u16 gUnk_0203C3D4 EWRAM_COMMON(4);
u16 gUnkEu_0203C9B4 EWRAM_COMMON(4);
u16 gUnkEu_0203C9B8 EWRAM_COMMON(4);
u16 gUnkEu_0203C9BC EWRAM_COMMON(4);
u16 gUnkEu_0203C9C0 EWRAM_COMMON(4);
u16 gUnkEu_0203C9C4 EWRAM_COMMON(4);
#else
s8 gUnk_0203C3D4 EWRAM_COMMON(4);
#endif

const char* gUnk_09EF34F0[] = {
#ifdef VERSION_EU
    "\x82\x50\x82\x6f\x81\x40\x82\x6b\x82\x64\x82\x75\x82\x64\x82\x6b\x81\x40\x81\x40\x81\x40\x81\x46",
    "\x82\x50\x82\x6f\x81\x40\x82\x67\x82\x6f\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46",
    "\x82\x50\x82\x6f\x81\x40\x82\x62\x82\x6f\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46",
    "\x82\x50\x82\x6f\x81\x40\x82\x76\x82\x68\x82\x6d\x81\x40\x81\x40\x82\x6d\x82\x74\x82\x6c\x81\x46",
    "\x82\x50\x82\x6f\x81\x40\x82\x6b\x82\x6e\x82\x72\x82\x64\x81\x40\x82\x6d\x82\x74\x82\x6c\x81\x46",
    "\x82\x51\x82\x6f\x81\x40\x82\x6b\x82\x64\x82\x75\x82\x64\x82\x6b\x81\x40\x81\x40\x81\x40\x81\x46",
    "\x82\x51\x82\x6f\x81\x40\x82\x67\x82\x6f\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46",
    "\x82\x51\x82\x6f\x81\x40\x82\x62\x82\x6f\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46",
    "\x82\x51\x82\x6f\x81\x40\x82\x76\x82\x68\x82\x6d\x81\x40\x81\x40\x82\x6d\x82\x74\x82\x6c\x81\x46",
    "\x82\x51\x82\x6f\x81\x40\x82\x6b\x82\x6e\x82\x72\x82\x64\x81\x40\x82\x6d\x82\x74\x82\x6c\x81\x46",
    "\x82\x62\x82\x60\x82\x71\x82\x63\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46",
    "\x82\x60\x82\x61\x82\x68\x82\x6b\x82\x68\x82\x73\x82\x78\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46",
#else
    "\x82\x6b\x82\x64\x82\x75\x82\x64\x82\x6b\x81\x40\x81\x40\x81\x46",
    "\x82\x67\x82\x6f\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46",
    "\x82\x62\x82\x6f\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x46",
    "\x82\x62\x82\x60\x82\x71\x82\x63\x81\x40\x81\x40\x81\x40\x81\x46",
    "\x82\x60\x82\x61\x82\x68\x82\x6b\x82\x68\x82\x73\x82\x78\x81\x46",
#endif
};

#ifndef VERSION_EU
const char* gUnk_09EF3504[] = {
    "\x82\x60\x82\x6b\x82\x6b\x81\x40\x81\x40\x81\x40",
    "\x82\x6d\x82\x6e\x82\x71\x82\x6c\x82\x60\x82\x6b",
};
#endif

const char gUnk_0961A9C8[] = "\x81\x84";

const char gUnk_0961A9CC[] = "\x82\x61\x82\x60\x82\x73\x82\x73\x82\x6b\x82\x64\x81\x40\x82\x62\x82\x6e\x82\x6d\x82\x65\x82\x68\x82\x66";

const char gUnk_0961A9E8[] = "\x81\x40";

Mode gModeSioDbgFlg = {
    "mode_sio_dbg_flg",
    mode_sio_dbg_flg_0,
    mode_sio_dbg_flg_1,
    mode_sio_dbg_flg_2,
};

static s8 gUnk_02034CF4;
static s8 gUnk_02034CF5;

void mode_sio_dbg_flg_0(s32 arg) {
#ifdef VERSION_EU
    s32 zero;
#else
    s32 i;
#endif

    SetBgMode0();
    SetupBg(0, 0, 0x0F, 0);
    EnableBg(0);
    func_0805FA8C(0, 0x5400, 0x500);
    func_0805FA60(0, gWhitePalette, 0x20, 0x0F);
    gUnk_02034CF4 = 0;
#ifdef VERSION_EU
    zero = 0;
#endif
    func_0805FCB0(8, 0x24, 2, gUnk_0961A9C8);
    gUnk_02034CF5 = sizeof(gUnk_09EF34F0) / sizeof(gUnk_09EF34F0[0]);
    func_0805FCB0(0x0C, 0x12, 2, gUnk_0961A9CC);

#ifdef VERSION_EU
    func_0805FCB0(0x14, 0x24, 2, gUnk_09EF34F0[0]);
    func_0805FCB0(0x14, 0x2D, 2, gUnk_09EF34F0[1]);
    func_0805FCB0(0x14, 0x36, 2, gUnk_09EF34F0[2]);
    func_0805FCB0(0x14, 0x3F, 2, gUnk_09EF34F0[3]);
    func_0805FCB0(0x14, 0x48, 2, gUnk_09EF34F0[4]);
    func_0805FCB0(0x14, 0x5A, 2, gUnk_09EF34F0[5]);
    func_0805FCB0(0x14, 0x63, 2, gUnk_09EF34F0[6]);
    func_0805FCB0(0x14, 0x6C, 2, gUnk_09EF34F0[7]);
    func_0805FCB0(0x14, 0x75, 2, gUnk_09EF34F0[8]);
    func_0805FCB0(0x14, 0x7E, 2, gUnk_09EF34F0[9]);
    gUnkEu_0203C9B4 = 1;
    gUnk_0203C3C4 = 80;
    gUnk_0203C3D0 = 275;
    gUnk_0203C3CC = zero;
    gUnkEu_0203C9B8 = zero;
    gUnkEu_0203C9C4 = 1;
    gUnkEu_0203C9C0 = 80;
    gUnk_0203C3C8 = 275;
    gUnkEu_0203C9BC = zero;
    gUnk_0203C3D4 = zero;
    func_0805FC04(0x78, 0x24, 2, gUnkEu_0203C9B4);
    func_0805FC04(0x78, 0x2D, 2, gUnk_0203C3C4);
    func_0805FC04(0x78, 0x36, 2, gUnk_0203C3D0);
    func_0805FC04(0x78, 0x3F, 2, gUnk_0203C3CC);
    func_0805FC04(0x78, 0x48, 2, gUnkEu_0203C9B8);
    func_0805FC04(0x78, 0x5A, 2, gUnkEu_0203C9C4);
    func_0805FC04(0x78, 0x63, 2, gUnkEu_0203C9C0);
    func_0805FC04(0x78, 0x6C, 2, gUnk_0203C3C8);
    func_0805FC04(0x78, 0x75, 2, gUnkEu_0203C9BC);
    func_0805FC04(0x78, 0x7E, 2, gUnk_0203C3D4);
#else
    for (i = 0; i < gUnk_02034CF5; i++) {
        func_0805FCB0(0x14, i * 9 + 0x24, 2, gUnk_09EF34F0[i]);
    }

    gUnk_0203C3C8 = 50;
    gUnk_0203C3CC = 500;
    gUnk_0203C3D0 = 500;
    gUnk_0203C3C4 = 0;
    gUnk_0203C3D4 = 0;
    func_0805FC04(0x64, 0x24, 2, gUnk_0203C3C8);
    func_0805FC04(0x64, 0x2D, 2, gUnk_0203C3CC);
    func_0805FC04(0x64, 0x36, 2, gUnk_0203C3D0);
    func_0805FCB0(0x64, 0x3F, 2, gUnk_09EF3504[gUnk_0203C3C4]);
    func_0805FCB0(0x64, 0x48, 2, gUnk_09EF3504[gUnk_0203C3D4]);
#endif
}

void mode_sio_dbg_flg_1(void) {
    u8 prev;

    prev = gUnk_02034CF4;

#ifdef VERSION_EU
    if (GetKeysRepeat() & DPAD_UP) {
        if (gUnk_02034CF4 == 0) {
            gUnk_02034CF4 = 10;
        } else if (gUnk_02034CF4 == 6) {
            gUnk_02034CF4 = 4;
        } else {
            gUnk_02034CF4--;
        }
    }

    if (GetKeysRepeat() & DPAD_DOWN) {
        if (gUnk_02034CF4 == 10) {
            gUnk_02034CF4 = 0;
        } else if (gUnk_02034CF4 == 4) {
            gUnk_02034CF4 = 6;
        } else {
            gUnk_02034CF4++;
        }
    }
#else
    if (GetKeysRepeat() & DPAD_UP) {
        gUnk_02034CF4--;
    }

    if (GetKeysRepeat() & DPAD_DOWN) {
        gUnk_02034CF4++;
    }
#endif

    if (prev != gUnk_02034CF4) {
#ifndef VERSION_EU
        if (gUnk_02034CF4 < 0) {
            gUnk_02034CF4 = gUnk_02034CF5 - 1;
        } else if (gUnk_02034CF4 >= gUnk_02034CF5) {
            gUnk_02034CF4 = 0;
        }
#endif

        func_0805FCB0(8, (prev + 4) * 9, 2, gUnk_0961A9E8);
        func_0805FCB0(8, (gUnk_02034CF4 + 4) * 9, 2, gUnk_0961A9C8);
    }

    switch (gUnk_02034CF4) {
#ifdef VERSION_EU
    case 0:
        if (GetKeysRepeat() & DPAD_LEFT) {
            if (gUnkEu_0203C9B4 > 1) {
                gUnkEu_0203C9B4--;
            }
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            if (gUnkEu_0203C9B4 <= 98) {
                gUnkEu_0203C9B4++;
            }
        }
        func_0805FC04(0x78, 0x24, 2, gUnkEu_0203C9B4);
        break;
    case 1:
        if (GetKeysRepeat() & DPAD_LEFT) {
            if (gUnk_0203C3C4 > 80) {
                gUnk_0203C3C4 -= 15;
            }
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            if (gUnk_0203C3C4 <= 559) {
                gUnk_0203C3C4 += 15;
            }
        }
        func_0805FC04(0x78, 0x2D, 2, gUnk_0203C3C4);
        break;
    case 2:
        if (GetKeysRepeat() & DPAD_LEFT) {
            if (gUnk_0203C3D0 > 275) {
                gUnk_0203C3D0 -= 25;
            }
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            if (gUnk_0203C3D0 <= 974) {
                gUnk_0203C3D0 += 25;
            }
        }
        func_0805FC04(0x78, 0x36, 2, gUnk_0203C3D0);
        break;
    case 3:
        if (GetKeysRepeat() & DPAD_LEFT) {
            if (gUnk_0203C3CC > 1) {
                gUnk_0203C3CC--;
            }
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            if (gUnk_0203C3CC <= 998) {
                gUnk_0203C3CC++;
            }
        }
        func_0805FC04(0x78, 0x3F, 2, gUnk_0203C3CC);
        break;
    case 4:
        if (GetKeysRepeat() & DPAD_LEFT) {
            if (gUnkEu_0203C9B8 > 1) {
                gUnkEu_0203C9B8--;
            }
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            if (gUnkEu_0203C9B8 <= 998) {
                gUnkEu_0203C9B8++;
            }
        }
        func_0805FC04(0x78, 0x48, 2, gUnkEu_0203C9B8);
        break;
    case 6:
        if (GetKeysRepeat() & DPAD_LEFT) {
            if (gUnkEu_0203C9C4 > 1) {
                gUnkEu_0203C9C4--;
            }
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            if (gUnkEu_0203C9C4 <= 98) {
                gUnkEu_0203C9C4++;
            }
        }
        func_0805FC04(0x78, 0x5A, 2, gUnkEu_0203C9C4);
        break;
    case 7:
        if (GetKeysRepeat() & DPAD_LEFT) {
            if (gUnkEu_0203C9C0 > 80) {
                gUnkEu_0203C9C0 -= 15;
            }
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            if (gUnkEu_0203C9C0 <= 559) {
                gUnkEu_0203C9C0 += 15;
            }
        }
        func_0805FC04(0x78, 0x63, 2, gUnkEu_0203C9C0);
        break;
    case 8:
        if (GetKeysRepeat() & DPAD_LEFT) {
            if (gUnk_0203C3C8 > 275) {
                gUnk_0203C3C8 -= 25;
            }
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            if (gUnk_0203C3C8 <= 974) {
                gUnk_0203C3C8 += 25;
            }
        }
        func_0805FC04(0x78, 0x6C, 2, gUnk_0203C3C8);
        break;
    case 9:
        if (GetKeysRepeat() & DPAD_LEFT) {
            if (gUnkEu_0203C9BC > 1) {
                gUnkEu_0203C9BC--;
            }
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            if (gUnkEu_0203C9BC <= 998) {
                gUnkEu_0203C9BC++;
            }
        }
        func_0805FC04(0x78, 0x75, 2, gUnkEu_0203C9BC);
        break;
    case 10:
        if (GetKeysRepeat() & DPAD_LEFT) {
            if (gUnk_0203C3D4 > 1) {
                gUnk_0203C3D4--;
            }
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            if (gUnk_0203C3D4 <= 998) {
                gUnk_0203C3D4++;
            }
        }
        func_0805FC04(0x78, 0x7E, 2, gUnk_0203C3D4);
        break;
#else
    case 0:
        if (GetKeysHeld() & DPAD_LEFT) {
            if (gUnk_0203C3C8 > 1) {
                gUnk_0203C3C8--;
            }
        }

        if (GetKeysHeld() & DPAD_RIGHT) {
            if (gUnk_0203C3C8 <= 98) {
                gUnk_0203C3C8++;
            }
        }
        func_0805FC04(0x64, 0x24, 2, gUnk_0203C3C8);
        break;
    case 1:
        if (GetKeysHeld() & DPAD_LEFT) {
            if (gUnk_0203C3CC > 5) {
                gUnk_0203C3CC -= 5;
            }
        }

        if (GetKeysHeld() & DPAD_RIGHT) {
            if (gUnk_0203C3CC <= 994) {
                gUnk_0203C3CC += 5;
            }
        }
        func_0805FC04(0x64, 0x2D, 2, gUnk_0203C3CC);
        break;
    case 2:
        if (GetKeysHeld() & DPAD_LEFT) {
            if (gUnk_0203C3D0 > 5) {
                gUnk_0203C3D0 -= 5;
            }
        }

        if (GetKeysHeld() & DPAD_RIGHT) {
            if (gUnk_0203C3D0 <= 994) {
                gUnk_0203C3D0 += 5;
            }
        }
        func_0805FC04(0x64, 0x36, 2, gUnk_0203C3D0);
        break;
    case 3:
        break;
    case 4:
        break;
#endif
    }

    if (GetKeysPressed() & (A_BUTTON | B_BUTTON | START_BUTTON)) {
        gUnk_0203A9E4 = 1;
        func_08085CB0();
        ModeRequest(&gModeSioBtlConnect, 0);
    } else {
        func_080605A4(0);
        func_08060598();
    }
}

void mode_sio_dbg_flg_2(void) {
    func_080609A0();
}

#ifdef VERSION_EU
void func_080C7350(void) {
    gUnk_0203AAC0.unk_04 = gUnkEu_0203C9B4;
    gUnk_0203AAC0.unk_02 = gUnk_0203AAC0.unk_00 = gUnk_0203C3C4;
    gGameState.progression.cp = gUnk_0203C3D0;
    gUnk_0203AAC0.unk_06 = gUnk_0203C3CC;
    gUnk_0203AAC0.unk_08 = gUnkEu_0203C9B8;
    gUnk_0203AAC0.unk_0C = -1;
    gUnk_0203AAC0.unk_14 = -1;
    gUnk_0203AAC0.unk_0A = 4;
    gUnk_0203AAC0.unk_1E = 0x1234;
    gUnk_0203AAC0.unk_1C = 0x1FFE;
    gUnk_0203AA10.unk_04 = gUnkEu_0203C9C4;
    gUnk_0203AA10.unk_02 = gUnk_0203AA10.unk_00 = gUnkEu_0203C9C0;
    gUnk_0203AA10.unk_06 = gUnkEu_0203C9BC;
    gUnk_0203AA10.unk_08 = gUnk_0203C3D4;
    gUnk_0203AA10.unk_0C = -1;
    gUnk_0203AA10.unk_14 = -1;
    gUnk_0203AA10.unk_0A = 4;
    gUnk_0203AA10.unk_1E = 0x1234;
    gUnk_0203AA10.unk_1C = 0x1FFE;
}
#else
void func_080C7350(void) {
    gUnk_0203AAC0.unk_04 = gUnk_0203C3C8;
    gUnk_0203AAC0.unk_02 = gUnk_0203C3CC;
}
#endif
