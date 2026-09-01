#include "macros.h"
#include "mode_chkbtl.h"

void mode_chkbtl_0(void) {
    func_08006120(0, 8);
    func_08004DB0();
    SetupBg(0, 0, 15, 0);
    EnableBg(0);
    func_0805FA8C(0, 0x5400, 0x500);
    func_0805FA60(0, gUnk_08128304, 0x20, 0x0F);
    func_0805FCB0(0, 0, 2, gUnk_08128324);
    func_0805FCB0(24, 32, 2, gUnk_0812834C);
    func_0805FCB0(24, 44, 2, gUnk_08128358);
    func_0805FCB0(24, 56, 2, gUnk_08128364);
    func_0805FCB0(24, 68, 2, gUnk_08128370);
    func_0805FCB0(62, 32, 2, gUnk_08126630[gUnk_09ECEB50->unk_02].unk_10);

    if (gUnk_08126630[gUnk_09ECEB50->unk_02].unk_04 == 2) {
        func_0805FCB0(62, 44, 2, gUnk_0812837C);
    } else {
        func_0805FCB0(62, 44, 2, gUnk_08128234[gUnk_09ECEB50->unk_01].unk_04);
    }

    func_0805FC04(62, 56, 2, gUnk_09ECEB50->unk_04 + 1);
    func_0805FC04(62, 68, 2, gUnk_09ECEB50->unk_06);

    if (!(gUnk_03006C10 & 1)) {
        func_08085FB0();
        func_08085CB0();
        gUnk_02039BB0.unk_FA = 9999;
        gUnk_03006C10 |= 1;
        gUnk_02039BB0.unk_17C = 0xFFFF;
    }
}

void mode_chkbtl_1(void) {
    s32 i;

    if (GetKeysRepeat() & 0x40) {
        gUnk_09ECEB50->unk_00--;
    }

    if (GetKeysRepeat() & 0x80) {
        gUnk_09ECEB50->unk_00++;
    }

    if (GetKeysRepeat() & 0xC0) {
        for (i = 0; i < 4; i++) {
            func_0805FCB0(12, i * 12 + 32, 2, gUnk_08128384);
        }
    }

    switch (gUnk_09ECEB50->unk_00) {
        case 0:
            if (GetKeysRepeat() & 0x20) {
                gUnk_09ECEB50->unk_02--;
            }

            if (GetKeysRepeat() & 0x10) {
                gUnk_09ECEB50->unk_02++;
            }

            if (gUnk_09ECEB50->unk_02 < 0) {
                gUnk_09ECEB50->unk_02 = 0xD0;
            } else if ((u16)gUnk_09ECEB50->unk_02 > 0xD0) {
                gUnk_09ECEB50->unk_02 = 0;
            }
            break;
        case 1:
            if (GetKeysRepeat() & 0x20) {
                gUnk_09ECEB50->unk_01--;
            }

            if (GetKeysRepeat() & 0x10) {
                gUnk_09ECEB50->unk_01++;
            }

            if (gUnk_09ECEB50->unk_01 < 0) {
                gUnk_09ECEB50->unk_01 = 12;
            } else if ((u8)gUnk_09ECEB50->unk_01 > 12) {
                gUnk_09ECEB50->unk_01 = 0;
            }
            break;
        case 2:
            if (GetKeysRepeat() & 0x20) {
                gUnk_09ECEB50->unk_04--;
            }

            if (GetKeysRepeat() & 0x10) {
                gUnk_09ECEB50->unk_04++;
            }

            if (gUnk_09ECEB50->unk_04 < 0) {
                gUnk_09ECEB50->unk_04 = 0;
            }

            if (gUnk_02039BB0.unk_08 & 8) {
                if (gUnk_09ECEB50->unk_04 > 11) {
                    gUnk_09ECEB50->unk_04 = 11;
                }
            } else {
                if (gUnk_09ECEB50->unk_04 > 12) {
                    gUnk_09ECEB50->unk_04 = 12;
                }
            }
            break;
        case 3:
            if (GetKeysRepeat() & 0x20) {
                gUnk_09ECEB50->unk_06--;
            }

            if (GetKeysRepeat() & 0x10) {
                gUnk_09ECEB50->unk_06++;
            }

            if (gUnk_09ECEB50->unk_06 <= 0) {
                gUnk_09ECEB50->unk_06 = 1;
            } else if (gUnk_09ECEB50->unk_06 > 560) {
                gUnk_09ECEB50->unk_06 = 560;
            }
            break;
        case 4:
            gUnk_09ECEB50->unk_00 = 0;
            break;
        case -1:
            gUnk_09ECEB50->unk_00 = 3;
            break;
    }

    func_0805FCB0(12, gUnk_09ECEB50->unk_00 * 12 + 32, 2, gUnk_08128388);

    if (GetKeysRepeat() & 0x30) {
        switch (gUnk_09ECEB50->unk_00) {
            case 0:
            case 1:
                func_0805FCB0(62, 32, 2, gUnk_0812838C);
                func_0805FCB0(62, 32, 2, gUnk_08126630[gUnk_09ECEB50->unk_02].unk_10);
                func_0805FCB0(62, 44, 2, gUnk_0812838C);

                if (gUnk_08126630[gUnk_09ECEB50->unk_02].unk_04 == 2) {
                    func_0805FCB0(62, 44, 2, gUnk_0812837C);
                } else {
                    func_0805FCB0(62, 44, 2, gUnk_08128234[gUnk_09ECEB50->unk_01].unk_04);
                }
                break;
            case 2:
                func_0805FC04(62, 56, 2, gUnk_09ECEB50->unk_04 + 1);
                break;
            case 3:
                func_0805FC04(62, 68, 2, gUnk_09ECEB50->unk_06);
                break;
        }
    }

    if (GetKeysPressed() & 4) {
        func_080010CC(&gUnk_09EE2704, 0);
    } else if (GetKeysPressed() & 9) {
        SeedRandom(gFrameCounter);
        gUnk_02039BB0.unk_0D = gUnk_08128234[gUnk_09ECEB50->unk_01].unk_00;
        gUnk_02039BB0.unk_0E = gUnk_09ECEB50->unk_04;
        gUnk_02039BB0.unk_32 = gUnk_09ECEB50->unk_06;
        gUnk_02039BB0.unk_F8 = gUnk_09ECEB50->unk_06;
        gUnk_02039BB0.unk_0C = gUnk_08126630[gUnk_09ECEB50->unk_02].unk_00;

        if (GetKeysHeld() & 0x200) {
            gUnk_02039BB0.unk_08 |= 4;
        } else {
            gUnk_02039BB0.unk_08 &= ~4;
        }

        if (gUnk_02039BB0.unk_08 & 8) {
            _08085D04(gUnk_09ECEB50->unk_04);
        }

        func_080010CC(&gUnk_09ECEB40, gUnk_08126630[gUnk_09ECEB50->unk_02].unk_08);
    } else if (GetKeysPressed() & 2) {
        func_080010CC(&gUnk_09ECEB64, 0);
        return;
    }

    func_080605A4(0);
    func_08060598();
}

void mode_chkbtl_2(void) {
    func_080609A0();
}

void func_0800AB8C(void) {
    ChkBtlEntry* entry;
    ChkBtlPos pos;

    entry = &gUnk_08126630[gUnk_09ECEB50->unk_02];

    if (entry->unk_08 == 0xB9) {
        pos.unk_00 = 0x15000;
        pos.unk_04 = 0x16000;
        pos.unk_08 = 0;
        TaskCreate(&gUnk_02039B84->unk_2C, entry->unk_0C, &pos);
    }
}

void func_0800ABD8(void) {
    gUnk_09ECEB50->unk_00 = 0;
    gUnk_09ECEB50->unk_01 = 0;
    gUnk_09ECEB50->unk_02 = 0;
    gUnk_09ECEB50->unk_04 = 0;
    gUnk_09ECEB50->unk_06 = gUnk_02039BB0.unk_F8;
    gUnk_03006C10 &= ~1;
    gUnk_02039B90 = 0x98;
    gUnk_02039B88 = 0x160;
    gUnk_02039B8C = 0x1A2;
}
