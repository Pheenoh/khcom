#include "display.h"
#include "pallet.h"
#include "sio_api.h"
#include "util.h"
#include "macros.h"
#include "chara.h"

CharaObj* gCharaObj;
u8 gUnk_02034CDC[4];
TaskPool gCharaTaskPool;
#include "gba/keys.h"

void task_chara_mask_fade_0(MaskFadeWork* work, MaskFadeArgs* args) {
    s32 i;

    work->unk_000 = args->unk_00;
    work->unk_004 = args->unk_04;
    work->unk_00A = 0;
    work->unk_008 = 1;
    work->unk_006 = args->unk_06;

    for (i = 0; i < work->unk_004; i++) {
        work->unk_04C[i] = GetRandom() % 5;
    }
}

u8 task_chara_mask_fade_1(MaskFadeWork* work) {
    s32 i;
    s32 j;

    if (++work->unk_00A > work->unk_006) {
        work->unk_00A = 0;

        for (i = 0; i < work->unk_004; i++) {
            CpuFastSet(work->unk_000 + i * 32, work->unk_00C, 8);

            for (j = 0; j <= 31; j++) {
                work->unk_02C[j] = work->unk_00C[j] & gUnk_09EF2F08[j + work->unk_008 * 32 + work->unk_04C[i] * 288];
            }
            CpuFastSet(work->unk_02C, work->unk_000 + i * 32, 8);
        }
        work->unk_008++;
        if (work->unk_008 > 8) {
            work->unk_008 = 0;
            return 0;
        }
    }
    return 1;
}

void task_chara_mask_fade_2(void) {
}

void task_chara_mask_fade_3(void) {
}

void task_chgCardObj_0(ChgCardObjWork* work, ChgCardObjParam* param) {
    s32 x;
    s32 y;

    work->unk_08 = param->unk_00;
    work->unk_0C = param->unk_04;
    work->unk_10 = param->unk_08;
    work->unk_14 = param->unk_0C;
    work->unk_18 = param->unk_10;
    work->unk_1C = param->unk_14;
    work->unk_20 = param->unk_18;
    work->unk_24 = param->unk_1C;
    work->unk_28 = param->unk_20;
    work->unk_2C = 0x100;
    work->unk_2A = 0;
    work->unk_2B = 0;
    work->unk_34 = 0x300;
    work->unk_30 = 2;
    x = work->unk_20 - *work->unk_08;
    y = work->unk_24 - *work->unk_0C;
    work->unk_40 = func_0805F5A4(&x, &y);
    work->unk_38 = -x;
    work->unk_3C = -y;
    work->unk_00 = 0;
    work->unk_02 = 0;
    work->unk_04 = 0;
}

static inline u8 ChgCardRotation(ChgCardObjWork* work, u8 rotation) {
    u8 phase;

    if (work->unk_2C < 0) {
        phase = -rotation;
    } else {
        phase = rotation;
    }
    return phase;
}

u8 task_chgCardObj_1(ChgCardObjWork* work) {
    u8 phase;
    u8 zero;
    u8 angleA;
    s32 x;
    s32 y;
    s32* p10;
    s32* p14;

    switch (work->unk_04) {
    case 0:
        if (work->unk_00 >= work->unk_28) {
            work->unk_00 = 0;
            work->unk_04++;
        } else {
            work->unk_00++;
        }
        break;
    case 1:
        *work->unk_08 += (work->unk_38 * work->unk_34) >> 8;
        *work->unk_0C += (work->unk_3C * work->unk_34) >> 8;
        *work->unk_18 += 32;
        angleA = work->unk_2A + ((64 - work->unk_2A) >> 4);
        zero = 0;
        work->unk_2A = angleA;
        work->unk_2B = zero;
        work->unk_40 = func_0805F588(work->unk_20 - *work->unk_08, work->unk_24 - *work->unk_0C);
        work->unk_34 -= work->unk_30;
        work->unk_30 += 2;
        phase = ChgCardRotation(work, 128);
        p10 = work->unk_10;
        *p10 = (-gSineTable[((work->unk_2B + phase) & 0xFF) + 64] * work->unk_2C) >> 8;
        p14 = work->unk_14;
        *p14 = (-gSineTable[((work->unk_2A + 128) & 0xFF) + 64] * work->unk_2C) >> 8;

        if (*p10 >= -2 && *p10 <= 2) {
            *p10 = 2;
        }

        if (*p14 >= -2 && *p14 <= 2) {
            *p14 = 2;
        }

        if (work->unk_34 < 0) {
            x = work->unk_20 - *work->unk_08;
            y = work->unk_24 - *work->unk_0C;
            func_0805F5A4(&x, &y);
            work->unk_38 = -x;
            work->unk_3C = -y;

            if (work->unk_40 <= 0x7FF) {
                m4aSongNumStart(0x6A);
                *work->unk_1C = zero;
                return 0;
            }
        }
        break;
    }
    return 1;
}

void task_chgCardObj_2(void) {
}

void task_chgCardObj_3(void) {
}

u8 func_080C54B4(void) {
    u32* p;

    p = &gSioStatus;
    *p = func_08006ED4(gUnk_0203982C, gUnk_02039B68, gUnk_020397E0);
    gSioPlayerId = gSioStatus & 3;
    gUnk_020397FC = (gSioStatus & 0x1C) >> 2;
    gUnk_02039824 = (gSioStatus & 0xE00) >> 9;

    if ((gSioStatus & 0x40) && gSioPlayerId <= 1) {
        func_080C5AA4();

        if ((gSioStatus & 0x100) == 0) {
            gUnk_02039B60 = func_080C5B50();
        }

        if (gSioStatus & 0x7F0000) {
            if (gUnk_0203C3A8 == 1) {
                gUnk_020397D4++;
                if (gUnk_020397D4 > 180) {
                    gUnk_02039B60 = 1;
                }
            }
        }

        if (gUnk_02039B60 == 1) {
            gSystemFlags &= 0xFFFE;
            gUnk_020397F0 = gSioStatus;
            ModeRequest(&gModeSioError, 0);
            return gUnk_02039B60;
        }
    } else {
        if (GetKeysPressed() & 2) {
            gUnk_0203BEA4 = 10;
        }

        if (gUnk_0203BEA4 > 0) {
            gUnk_0203BEA4--;
            if (gUnk_0203BEA4 == 0) {
                func_080078A4();

                if (gUnk_0203BEAC != 0) {
                    gUnk_0203BEAC();
                }
            }
        }
    }
    return gUnk_02039B60;
}

u8 func_080C55DC(void) {
    u32* p;

    p = &gSioStatus;
    *p = func_0800702C(gUnk_0203982C, gUnk_02039B68, gUnk_020397E0);
    gSioPlayerId = gSioStatus & 3;
    gUnk_020397FC = (gSioStatus & 0x1C) >> 2;
    gUnk_02039824 = (gSioStatus & 0xE00) >> 9;

    if ((gSioStatus & 0x40) && gSioPlayerId <= 1) {
        if (gUnk_020397F8 != 0) {
            gUnk_02039B60 = gUnk_020397F8();
        }

        if (gUnk_02039804 != 0) {
            gUnk_02039804();
        }

        if (gSioStatus & 0x7F0000) {
            if (gUnk_0203C3A8 == 1) {
                gUnk_020397D4++;
                if (gUnk_020397D4 > 180) {
                    gSystemFlags &= 0xFFFE;
                    gUnk_020397F0 = gSioStatus;
                    ModeRequest(&gModeSioError, 0);
                    gUnk_02039B60 = 1;
                }
            }
        }
    }
    return gUnk_02039B60;
}


u8 func_080C56BC(void) {
    u32* p;

    p = &gSioStatus;
    *p = func_08006ED4(gUnk_0203982C, gUnk_02039B68, gUnk_020397E0);
    gSioPlayerId = gSioStatus & 3;
    gUnk_020397FC = (gSioStatus & 0x1C) >> 2;
    gUnk_02039824 = (gSioStatus & 0xE00) >> 9;

    if ((gSioStatus & 0x40) && gSioPlayerId <= 1) {
        func_080C5C24();

        if ((gSioStatus & 0x100) == 0) {
            gUnk_02039B60 = func_080C5C7C();
        }

        if (gSioStatus & 0x7F0000) {
            if (gUnk_0203C3A8 == 1) {
                gUnk_020397D4++;
                if (gUnk_020397D4 > 180) {
                    gUnk_02039B60 = 1;
                }
            }
        }

        if (gUnk_02039B60 == 1) {
            gSystemFlags &= 0xFFFE;
            gUnk_020397F0 = gSioStatus;
            ModeRequest(&gModeSioError, 0);
            return gUnk_02039B60;
        }
    }
    return gUnk_02039B60;
}

void func_080C57A4(void) {
    func_08083D68();
    func_08083DD4();
}

void func_080C57B4(void) {
    if (gSystemFlags & 1) {
        func_080078A4();
        gSystemFlags &= 0xFFFE;
    }

    if (gSystemFlags & 0x10) {
        gSystemFlags &= 0xFFEF;
    }

    if (gUnk_0203C374 == 1) {
        func_080C57A4();
        gUnk_0203C374 = 0;
    }
}

void func_080C5808(void) {
    s32 i;

    for (i = 0; i < 100; i++) {
        gUnk_0203C050[i] = 0;
        gUnk_0203BEC0[i] = 0;
        gUnk_0203BD10[i] = 0;
        gUnk_0203C1E0[i] = 0;
    }
    gUnk_0203C370 = 0;
    gUnk_0203BEBC = 0;
}

void func_080C5850(u16 a, u16 b, u16 c, u16 d) {
    gUnk_0203C050[gUnk_0203C370] = (gUnk_0203BEBC << 24) | a;
    gUnk_0203BEC0[gUnk_0203C370] = (gUnk_0203BEBC << 24) | b;
    gUnk_0203BD10[gUnk_0203C370] = (gUnk_0203BEBC << 24) | c;
    gUnk_0203C1E0[gUnk_0203C370] = (gUnk_0203BEBC << 24) | d;
    gUnk_0203C370++;
    if (gUnk_0203C370 > 99) {
        gUnk_0203C370 = 0;
    }
    func_080C58DC();
}

void func_080C58D0(void) {
    gUnk_0203BEBC = 0;
}

void func_080C58DC(void) {
    gUnk_0203BEBC = (gUnk_0203BEBC + 1) & 0xFF;
}

void func_080C58F0(void) {
    gUnk_0203BEA0 = 0;
    gUnk_0203BEB0 = gVBlankCounter;
}

void func_080C590C(void) {
    gUnk_0203BEA0 = (gVBlankCounter - gUnk_0203BEB0) & 0xFFFF;
}

s32 func_080C5930(void) {
    if (gSioStatus & 0x7F0000) {
        return 1;
    }
    return 0;
}

void func_080C594C(void) {
    SioReset();
    func_080C5A3C(func_080C5A30, 0, 0);
    gUnk_0203BEB8 = 0;
    gUnk_0203BEA8 = 0;
}

u8 func_080C5978(void) {
    switch (gUnk_0203BEB8) {
    case 0:
        func_080C56BC();
        break;
    case 1:
        gUnk_0203BEA8++;
        if (gUnk_0203BEA8 > 4) {
            gUnk_0203BEA8 = 0;
            func_080C5DC0(func_080C5E58, func_080C5ECC);
            gSystemFlags |= 1;
            gSystemFlags &= 0xFFEF;
            gUnk_0203BEB8++;
        }
        break;
    case 2:
        gUnk_0203BEA8++;
        if (gUnk_0203BEA8 > 4) {
            gUnk_02039B68[1] = 0x2811;

            if (gUnk_020397E0[1][0] == 0x2811 && gUnk_020397E0[1][1] == gUnk_020397E0[1][0]) {
                gUnk_0203BEA8 = 0;
                gUnk_0203BEB8++;
            }
        }
        break;
    default:
        return 1;
    }
    return 0;
}

void func_080C5A30(void) {
    gUnk_0203BEB8 = 1;
}

void func_080C5A3C(void (*a)(void), void (*b)(void), u8 c) {
#ifdef VERSION_JP
    gUnk_0203C3B0 = (c & 0xF) | 0xC0F0;
#else
#ifdef VERSION_EU
    gUnk_0203C3B0 = (c & 0xF) | 0xC2F0;
#else
    gUnk_0203C3B0 = (c & 0xF) | 0xC1F0;
#endif
#endif
    gUnk_0203C3A0 = 0;
    gUnk_0203C3A8 = 0;
    gUnk_0203C38C = 0;
    gUnk_0203C3AC = a;
    gUnk_0203BEAC = b;
    gUnk_0203BEA4 = 0;
    gUnk_02039B68[0] = 0xDDDD;
    gUnk_02039B68[1] = 0xDDDD;
}

s32 func_080C5AA4(void) {
    u16* param;
    u16* send;
    s32 firstAddress;
    s32 address;
    s32 value;
    s32 clearValue;
    u16* words;
    s32 clearAddress;

    if (gUnk_0203C3A8 == 0) {
        if (gUnk_0203C3A0 == 0) {
            if (GetKeysPressed() & 1) {
                gUnk_02039B68[0] = 0xFEFE;
                send = gUnk_02039B68;
                param = &gUnk_0203C3B0;
            } else if (GetKeysPressed() & 2) {
                gUnk_02039B68[0] = 0xAFAF;
                send = gUnk_02039B68;
                param = &gUnk_0203C3B0;
            } else {
                send = gUnk_02039B68;
                param = &gUnk_0203C3B0;
                firstAddress = (s32)send;
                value = 0;
                address = (s32)(send + 3);
                do {
                    *(u16*)address = value;
                    address -= sizeof(u16);
                } while (address >= firstAddress);
            }
            send[1] = *param;
        } else {
            gUnk_02039B68[0] = 0xECEC;
        }
    } else {
        words = gUnk_02039B68;
        clearValue = 0;
        clearAddress = (s32)(words + 3);
        do {
            *(u16*)clearAddress = clearValue;
            clearAddress -= sizeof(u16);
        } while (clearAddress >= (s32)words);
    }
    return 0;
}
s32 func_080C5B50(void) {
    u16 c;
    u16 v;

    if (gUnk_0203C3A8 == 0) {
        if (gUnk_0203C3A0 == 0) {
            if (gUnk_020397E0[0][0] == 0xFEFE || gUnk_020397E0[0][1] == 0xFEFE) {
                if (gUnk_020397E0[1][0] == gUnk_0203C3B0 && gUnk_020397E0[1][1] == gUnk_020397E0[1][0]) {
                    gUnk_0203C3A0 = 1;
                }
            } else {
                c = 0xAFAF;
                if (gUnk_020397E0[0][0] == c || gUnk_020397E0[0][1] == c) {
                    func_080078A4();
                    v = gSioPlayerId == 0 ? gUnk_020397E0[0][0] : gUnk_020397E0[0][1];
                    if (v == c) {
                        if (gUnk_0203BEAC != 0) {
                            gUnk_0203BEAC();
                        }
                    }
                }
            }
        } else if (gUnk_020397E0[0][0] == 0xECEC) {
            gUnk_0203C3A8 = 1;

            if (gUnk_0203C3AC != 0) {
                gUnk_0203C3AC();
            }
        } else {
            gUnk_0203C38C++;
            if (gUnk_0203C38C > 10) {
                return 1;
            }
        }
    }
    return 0;
}

s32 func_080C5C24(void) {
    u16* base;
    u16* p;
    u16 v;

    if (gUnk_0203C3A8 == 0) {
        if (gUnk_0203C3A0 == 0) {
            gUnk_02039B68[0] = 0xFEFE;
        } else {
            gUnk_02039B68[0] = 0xECEC;
        }
    } else {
        base = gUnk_02039B68;
        v = 0;
        p = base + 3;
        do {
            *p = v;
            p--;
        } while ((s32)p >= (s32)base);
    }
    return 0;
}

s32 func_080C5C7C(void) {
    if (gUnk_0203C3A8 == 0) {
        if (gUnk_0203C3A0 == 0) {
            if (gUnk_020397E0[0][0] == 0xFEFE || gUnk_020397E0[0][1] == 0xFEFE) {
                gUnk_0203C3A0 = 1;
            }
        } else if (gUnk_020397E0[0][0] == 0xECEC) {
            gUnk_0203C3A8 = 1;

            if (gUnk_0203C3AC != 0) {
                gUnk_0203C3AC();
            }
        } else {
            gUnk_0203C38C++;
            if (gUnk_0203C38C > 10) {
                return 1;
            }
        }
    }
    return 0;
}

void func_080C5D00(void) {
    func_080C5D10();
    func_080C5D24();
}

void func_080C5D10(void) {
    u16* base;
    u16* p;
    u16 v;

    base = gUnk_02039B58;
    v = 0;
    p = base + 3;
    do {
        *p = v;
        p--;
    } while ((s32)p >= (s32)base);
}

void func_080C5D24(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 off;

    i = 0;
    do {
        off = i * 4;
        k = i + 1;

        for (j = 1; j >= 0; j--) {
            *(u16*)((u8*)gUnk_02039810 + off + j * 2) = 0;
        }
        i = k;
    } while (i <= 3);
}


s32 func_080C5D50(void) {
    gUnk_02039B58[0] = 0xACD;
    gUnk_02039B68[0] = gUnk_02039B58[0];
    gUnk_02039B68[1] = gUnk_02039B58[1];
    gUnk_02039B68[2] = gUnk_02039B58[2];
    gUnk_02039B68[3] = gUnk_02039B58[3];
    func_080C5D10();
    return 0;
}

s32 func_080C5D80(void) {
    if (gUnk_020397E0[0][0] == 0xACD) {
        gUnk_02039810[0][0] = gUnk_020397E0[0][0];
        gUnk_02039810[1][0] = gUnk_020397E0[1][0];
        gUnk_02039810[2][0] = gUnk_020397E0[2][0];
        gUnk_02039810[3][0] = gUnk_020397E0[3][0];
    }

    if (gUnk_020397E0[0][1] == 0xACD) {
        gUnk_02039810[0][1] = gUnk_020397E0[0][1];
        gUnk_02039810[1][1] = gUnk_020397E0[1][1];
        gUnk_02039810[2][1] = gUnk_020397E0[2][1];
        gUnk_02039810[3][1] = gUnk_020397E0[3][1];
    }
    return 0;
}

void func_080C5DC0(s32 (*a)(void), s32 (*b)(void)) {
    u16* base;
    u16* p;
    u16 v;
    s32 i;
    s32 j;
    s32 k;
    s32 off;
    s32 (**pb)(void);
    u16* p1;
    u16* p2;
    s32 (**pa)(void);

    gUnk_0203C38C = 0;
    gUnk_020397F0 = 0;
    gUnk_02039B60 = 0;
    pa = &gUnk_02039804;
    pb = &gUnk_020397F8;
    p1 = &gUnk_0203C3B4;
    p2 = &gUnk_0203C388;
    base = gUnk_02039B68;
    v = 0;
    p = base + 3;
    do {
        *p = v;
        p--;
    } while ((s32)p >= (s32)base);
    i = 0;
    do {
        off = i * 2;
        k = i + 1;

        for (j = 3; j >= 0; j--) {
            *(u16*)((u8*)gUnk_020397E0 + off + j * 4) = 0;
        }
        i = k;
    } while (i <= 1);
    *pa = a;
    *pb = b;
    *p1 = 0;
    *p2 = 0;
}


s32 func_080C5E58(void) {
    if (gSioPlayerId == 0) {
        gUnk_02039B68[0] = 0xACD;
        gUnk_02039B68[1] = GetKeysHeld() & KEYS_MASK;
        gUnk_02039B68[2] = gUnk_0203C3B4;
        gUnk_02039B68[3] = gUnk_0203C388;
    } else {
        gUnk_02039B68[0] = 0xACD;
        gUnk_02039B68[1] = GetKeysHeld() & KEYS_MASK;
        gUnk_02039B68[2] = 0x1234;
        gUnk_02039B68[3] = 0x3456;
    }
    return 0;
}

s32 func_080C5ECC(void) {
    if (gSioPlayerId == 0) {
        if (gUnk_020397E0[0][0] == 0xACD && gUnk_020397E0[0][1] == gUnk_020397E0[0][0]) {
            gUnk_0203C3B4 = gUnk_020397E0[1][0];
            gUnk_0203C388 = gUnk_020397E0[1][1];
            gSioStatus &= ~0x100;
        } else {
            gSioStatus |= 0x100;
        }

        if (gUnk_020397E0[0][0] == 0xACD) {
            SioKeyStateUpdateA(gUnk_020397E0[2][0]);
            SioKeyStateUpdateB(gUnk_020397E0[3][0]);
            gSioStatus &= ~0x100;
        } else {
            gSioStatus |= 0x100;
        }
    } else {
        if (gUnk_020397E0[0][0] == 0xACD) {
            SioKeyStateUpdateA(gUnk_020397E0[2][0]);
            SioKeyStateUpdateB(gUnk_020397E0[3][0]);
            gSioStatus &= ~0x100;
        } else {
            gSioStatus |= 0x100;
        }
    }
    return 0;
}


void func_080C5F94(void) {
    u16* a;
    u16* b;

    a = func_08083C94();
    gUnk_0203C37C = a;
    b = func_08083D7C();
    gUnk_0203C398 = b;
    gUnk_0203C374 = 1;
    gUnk_0203C378 = 59;
    gUnk_0203C394 = 1;
    gUnk_0203C3A4 = 0;
    gUnk_0203C380 = 0;
    gUnk_0203C384 = 0;
    gUnk_0203C3B8 = 0;
    gUnk_0203C390 = gUnk_0203C37C;
    gUnk_0203C39C = gUnk_0203C398;
}


s32 func_080C6008(void) {
    u16 n;

    if (gUnk_0203C380 == 0) {
        if (gUnk_0203C3A4 == 0) {
            gUnk_02039B68[0] = 0x1BFE;
        } else {
            gUnk_02039B68[0] = 0xC5A0;
        }
    } else {
        if (gUnk_0203C394 <= 3) {
            gUnk_02039B68[0] = 0xACD;
            gUnk_02039B68[1] = 0xDDDD;
            gUnk_02039B68[2] = 0xDDDD;
            gUnk_02039B68[3] = 0xDDDD;
        } else if (gUnk_0203C394 <= gUnk_0203C378) {
            n = gUnk_0203C394 - 3;
            gUnk_02039B68[0] = 0xACD;
            gUnk_02039B68[1] = gUnk_0203C394;
            gUnk_02039B68[2] = gUnk_0203C390[n * 2 - 2];
            gUnk_02039B68[3] = gUnk_0203C390[n * 2 - 1];
        } else {
            gUnk_02039B68[0] = 0xACD;
            gUnk_02039B68[1] = gUnk_0203C394;
            gUnk_02039B68[2] = 0;
            gUnk_02039B68[3] = 0;
        }
        gUnk_0203C394++;
    }
    return 0;
}


s32 func_080C60D8(void) {
    u16 n;

    if (gUnk_0203C380 == 0) {
        if (gUnk_0203C3A4 == 0) {
            if (gUnk_020397E0[0][0] == 0x1BFE || gUnk_020397E0[0][1] == 0x1BFE) {
                gUnk_0203C3A4 = 1;
            }
        } else if (gUnk_020397E0[0][0] == 0xC5A0 && gUnk_020397E0[0][1] == gUnk_020397E0[0][0]) {
            gUnk_0203C380 = 1;
            gUnk_0203C394 = 1;
        }
    } else if (gSioPlayerId == 0) {
        if (gUnk_020397E0[1][1] != 0xDDDD && gUnk_020397E0[1][1] > 3) {
            if (gUnk_020397E0[1][1] > gUnk_0203C378) {
                return 2;
            }
            n = gUnk_020397E0[1][1] - 3;
            gUnk_0203C39C[n * 2 - 2] = gUnk_020397E0[2][1];
            gUnk_0203C39C[n * 2 - 1] = gUnk_020397E0[3][1];
        }
    } else {
        if (gUnk_020397E0[1][0] != 0xDDDD && gUnk_020397E0[1][0] > 3) {
            if (gUnk_020397E0[1][0] > gUnk_0203C378) {
                return 2;
            }
            n = gUnk_020397E0[1][0] - 3;
            gUnk_0203C39C[n * 2 - 2] = gUnk_020397E0[2][0];
            gUnk_0203C39C[n * 2 - 1] = gUnk_020397E0[3][0];
        }
    }
    return 0;
}


#ifdef VERSION_EU
void eu_080C24D8(void) {
    s32 i;
    s16 count;

    count = 112;
    for (i = 0; i < count; i++) {
        gUnk_0203C39C[i] = gUnk_0203C390[i];
    }
}
#endif

void func_080C61D4(void) {
    s32 i;
    CharaLinkData* send;
    u16* recv;

    send = &gUnk_0203AAC0;
    recv = gUnk_0203AA10;
    send->unk_00 = gGameState.hp;
    gUnk_0203AAC0.unk_02 = gGameState.maxHp;
    gUnk_0203AAC0.unk_04 = gGameState.level;
    gUnk_0203AAC0.unk_06 = gUnk_0203A9EC;
    gUnk_0203AAC0.unk_08 = gUnk_0203A9F0;
    gUnk_0203AAC0.unk_0A = gGameState.ap;
    gUnk_0203AAC0.unk_0C = gGameState.unk_10C;
    gUnk_0203AAC0.unk_14 = gGameState.unk_114;
    gUnk_0203AAC0.unk_1C = 0;

    for (i = 0; i < 13; i++) {
        if ((u8)(gGameState.floors[i].world - 1) <= 11) {
            gUnk_0203AAC0.unk_1C |= 1 << gGameState.floors[i].world;
        }
    }

    if (gSioPlayerId == 0) {
        SeedRandom(gFrameCounter & 0xFFFF);
        gUnk_0203AAC0.unk_1E = GetRandom() % 0xFFFF;
    } else {
        gUnk_0203AAC0.unk_1E = 0;
    }
    gUnk_0203C378 = 11;
    gUnk_0203C394 = 1;
    gUnk_0203C3A4 = 0;
    gUnk_0203C380 = 0;
    gUnk_0203C384 = 0;
    gUnk_0203C390 = (u16*)send;
    gUnk_0203C39C = recv;
}

void func_080C62F0(void (*a)(void)) {
    gUnk_0203C3A4 = 0;
    gUnk_0203C380 = 0;
    gUnk_0203C384 = 0;
    gUnk_0203C3AC = a;
}

s32 func_080C6314(void) {
    if (gUnk_0203C380 == 0) {
        if (gUnk_0203C3A4 == 0) {
            gUnk_02039B68[0] = 0xFEFE;
        } else if (gUnk_0203C384 == 0) {
            gUnk_02039B68[0] = 0xECEC;
        } else {
            gUnk_02039B68[0] = 0xDF89;
        }
    }
    return 0;
}

s32 func_080C6378(void) {
    if (gUnk_0203C380 == 0) {
        if (gUnk_0203C3A4 == 0) {
            if (gUnk_020397E0[0][0] == 0xFEFE || gUnk_020397E0[0][1] == 0xFEFE) {
                gUnk_0203C3A4 = 1;
            }
        } else if (gUnk_020397E0[0][0] != 0xDF89) {
            if (gSioPlayerId == 0 && gUnk_020397E0[0][0] == 0xECEC &&
                gUnk_020397E0[0][1] == gUnk_020397E0[0][0]) {
                gUnk_0203C384 = 1;
            }
        } else {
            if (gUnk_0203C3AC != 0) {
                gUnk_0203C3AC();
            }
            gUnk_0203C380 = 1;
        }
    }
    return 0;
}

#ifdef VERSION_EU
s32 eu_080C273C(void) {
    return 0;
}

s32 eu_080C2740(void) {
    u16 held;
    u16 keys;
    u16 r;

    held = GetKeysHeld() & 0x3FF;
    keys = 0;

    if (gUnkEu_0203C970 != 0) {
        keys = gUnkEu_0203C97C;
        gUnkEu_0203C970--;
    } else {
        gUnkEu_0203C970 = GetRandom() % 91 + 30;

        r = GetRandom();
        switch (r & 7) {
        case 0:
            gUnkEu_0203C97C = 0x10;
            break;
        case 1:
            gUnkEu_0203C97C = 0x20;
            break;
        case 2:
            gUnkEu_0203C97C = 0x40;
            break;
        case 3:
            gUnkEu_0203C97C = 0x80;
            break;
        case 4:
            gUnkEu_0203C97C = 0x50;
            break;
        case 5:
            gUnkEu_0203C97C = 0x90;
            break;
        case 6:
            gUnkEu_0203C97C = 0x60;
            break;
        case 7:
            gUnkEu_0203C97C = 0xA0;
            break;
        }
    }

    if (gUnkEu_0203C964 != 0) {
        keys |= 1;
        gUnkEu_0203C964--;
    } else {
        gUnkEu_0203C964 = GetRandom() % 61 + 60;
    }

    if ((u16)(GetRandom() % 30) == 0) {
        keys |= 0x200;
    }

    if ((u16)(GetRandom() % 50) == 0) {
        keys |= 0x300;
    }
    SioKeyStateUpdateA(held);
    SioKeyStateUpdateB(keys);
    return 0;
}
#endif

void func_080C640C(CharaObjParam2* param) {
    s32 i;

    gCharaObj = EwramAlloc(0x1094);
    gCharaObj->unk_0C = param->unk_00;
    gCharaObj->unk_10 = param->unk_04;
    gCharaObj->unk_24 = param->unk_08;
    gCharaObj->unk_28 = param->unk_0C;
    gCharaObj->unk_00 = param->unk_10;
    gCharaObj->unk_04 = param->unk_14;
    gCharaObj->unk_08 = param->unk_18;
    gCharaObj->unk_3A = 0;
    gCharaObj->unk_3C = -76;
    gCharaObj->unk_40 = 0;
    gCharaObj->unk_42 = 0;
    gCharaObj->unk_44 = 0;
    gCharaObj->unk_1048 = param->unk_1C;
    gCharaObj->unk_2C = 0;
    gCharaObj->unk_30 = 0;
    gCharaObj->unk_34 = 0;
    gCharaObj->unk_38 = 0;
    gCharaObj->unk_104C = param->unk_20;

    for (i = 0; i < 32; i++) {
        gCharaObj->unk_1050[i] = 0;
    }
    TaskPoolInit(&gCharaTaskPool, 2);
}

u8 func_080C64A4(void) {
    CharaPrizeArgs prize;
    MaskFadeArgs fade;

    switch (gCharaObj->unk_44) {
    case 0:
        if (!func_080128EC()) {
            gCharaObj->unk_44++;
        }
        break;
    case 1:
        if (++gCharaObj->unk_42 > 59) {
            gCharaObj->unk_42 = 0;
            gCharaObj->unk_44++;
        }
        break;
    case 2:
        CpuSet((void*)0x05000000, gCharaObj->unk_46, 0x200);
        func_080149BC(gCharaObj->unk_00, gCharaObj->unk_04 + gCharaObj->unk_08 - 0x1000);
        m4aSongNumStart(0x228);
        gCharaObj->unk_44++;
        break;
    case 3:
        gCharaObj->unk_3A++;
        FadePaletteToBlack(gCharaObj->unk_46, (u16*)0x05000000, 320, gCharaObj->unk_3A);
        if (++gCharaObj->unk_42 > 9) {
            gCharaObj->unk_42 = 0;
            gCharaObj->unk_44++;
        }
        break;
    case 4:
        gCharaObj->unk_3A = 0;
        CpuSet((void*)0x05000000, gCharaObj->unk_846, 0x200);
        gCharaObj->unk_44++;
        break;
    case 5:
        if (++gCharaObj->unk_42 > 89) {
            gCharaObj->unk_42 = 0;
            gCharaObj->unk_44++;
        }
        break;
    case 6:
        if (gCharaObj->unk_40 > 1) {
            gCharaObj->unk_40 = 0;
            gCharaObj->unk_3A++;
        }
        gCharaObj->unk_40++;
        if (gCharaObj->unk_28 != 0) {
            FadePaletteToWhite((u16*)gCharaObj->unk_24, (u16*)gCharaObj->unk_24, gCharaObj->unk_28, gCharaObj->unk_3A);
        }
        if (gCharaObj->unk_42 == 20) {
            func_08006B4C();
            m4aSongNumStart(0x229);
            fade.unk_00 = (u8*)gCharaObj->unk_0C;
            fade.unk_04 = gCharaObj->unk_10;
            fade.unk_06 = 1;
            TaskCreate(&gCharaTaskPool, &gUnk_09EF34A8, &fade);
        }
        if (++gCharaObj->unk_42 > 39) {
            gCharaObj->unk_42 = 0;
            m4aSongNumStop(0x229);
            gCharaObj->unk_44++;
        }
        break;
    case 7:
        gCharaObj->unk_3A = 0;
        gCharaObj->unk_40 = 0;
        m4aSongNumStart(0x22A);
        func_08006184(2, 20);
        func_080063A8();
        gCharaObj->unk_44++;
        break;
    case 8:
        if (gCharaObj->unk_40 > 1) {
            gCharaObj->unk_40 = 0;
            gCharaObj->unk_3A++;
        }
        gCharaObj->unk_40++;
        if (++gCharaObj->unk_42 > 37) {
            gCharaObj->unk_42 = 0;
            gCharaObj->unk_44++;
        }
        break;
    case 9:
        if (++gCharaObj->unk_42 > 20) {
            gCharaObj->unk_42 = 0;
            gCharaObj->unk_44++;
        }
        break;
    case 10:
        gCharaObj->unk_40 = 0;
        if (gCharaObj->unk_1048 != 0) {
            ((void (*)(void))gCharaObj->unk_1048)();
        }
        gCharaObj->unk_44++;
        break;
    case 11:
        gCharaObj->unk_3A -= 2;
        FadePaletteToWhite(gCharaObj->unk_846, (u16*)0x05000000, 1024, gCharaObj->unk_3A);
        if (++gCharaObj->unk_42 > 8) {
            gCharaObj->unk_42 = 0;
            gCharaObj->unk_44++;
        }
        break;
    case 12:
        func_08014B30(gCharaObj->unk_00, gCharaObj->unk_04 + gCharaObj->unk_08 - 0x1000);
        prize.x = gCharaObj->unk_00;
        prize.y = gCharaObj->unk_04;
        prize.z = gCharaObj->unk_08;
        func_08096DC4(&gBtlWork->taskPools[0], &prize);
        func_0801B918((void*)gCharaObj->unk_104C);
        gCharaObj->unk_44++;
        break;
    case 13:
        func_0801475C(76, 0, gCharaObj->unk_3C);
        if (++gCharaObj->unk_42 > 79) {
            gCharaObj->unk_42 = 0;
            gCharaObj->unk_44++;
        }
        break;
    case 14:
        gCharaObj->unk_3C = 0;
        gCharaObj->unk_44++;
        break;
    case 15:
        func_0801475C(0, 0, gCharaObj->unk_3C);
        gCharaObj->unk_3C -= 25;
        if (++gCharaObj->unk_42 > 39) {
            gCharaObj->unk_42 = 0;
            gCharaObj->unk_44++;
        }
        break;
    case 16:
        func_08006B4C();
        gCharaObj->unk_3A = 11;
        gCharaObj->unk_44++;
        break;
    case 17:
        gCharaObj->unk_3A--;
        FadePaletteToBlack(gCharaObj->unk_46, (u16*)0x05000000, 320, gCharaObj->unk_3A);
        if (++gCharaObj->unk_42 > 10) {
            gCharaObj->unk_42 = 0;
            CharaObjFree();
            gCharaObj->unk_44++;
        }
        break;
    default:
        return 0;
    }
    TaskPoolUpdate(&gCharaTaskPool);
    TaskPoolDraw(&gCharaTaskPool);
    return 1;
}

void CharaObjFree(void) {
    EwramFree(gCharaObj);
    TaskPoolDestroy(&gCharaTaskPool);
}

void func_080C6894(CharaObjParam* param) {
    s32 i;
    u16 idx;

    gCharaObj = EwramAlloc(0x1094);
    gCharaObj->unk_1090 = 0;
    gCharaObj->unk_0C = param->unk_00;
    gCharaObj->unk_10 = param->unk_04;
    gCharaObj->unk_14 = param->unk_08;
    gCharaObj->unk_18 = param->unk_0C;
    gCharaObj->unk_1C = param->unk_10;
    gCharaObj->unk_20 = param->unk_14;
    gCharaObj->unk_24 = param->unk_18;
    gCharaObj->unk_28 = param->unk_1C;
    gCharaObj->unk_2C = param->unk_20;
    gCharaObj->unk_30 = param->unk_24;
    gCharaObj->unk_34 = param->unk_28;
    gCharaObj->unk_38 = param->unk_2C;
    gCharaObj->unk_00 = param->unk_30;
    gCharaObj->unk_04 = param->unk_34;
    gCharaObj->unk_08 = param->unk_38;
    gCharaObj->unk_3A = 0;
    gCharaObj->unk_3C = -76;
    gCharaObj->unk_40 = 0;
    gCharaObj->unk_42 = 0;
    gCharaObj->unk_44 = 0;
    gCharaObj->unk_1048 = param->unk_3C;
    gCharaObj->unk_104C = param->unk_40;
    gCharaObj->unk_1090 = param->unk_44;

    for (i = 0; i < 10; i++) {
        gCharaObj->unk_1050[i] = 1;
    }

    for (i = 10; i < 32; i++) {
        gCharaObj->unk_1050[i] = 0;
    }
    idx = gCharaObj->unk_24 >> 5;

    if (gCharaObj->unk_28 == 32) {
        gCharaObj->unk_1050[(s16)idx] = 1;
    }
    TaskPoolInit(&gCharaTaskPool, 4);
}

void func_080C6990(u16 a, u8 b) {
    if (a <= 31) {
        gCharaObj->unk_1050[a] = b;
    }
}

u8 func_080C69B4(void) {
    s32 i;
    CharaPrizeArgs prize;
    MaskFadeArgs fade0;
    MaskFadeArgs fade1;
    MaskFadeArgs fade2;
    MaskFadeArgs fade3;

    switch (gCharaObj->unk_44) {
    case 0:
        if (!func_080128EC()) {
            gCharaObj->unk_44++;
        }
        break;
    case 1:
        if (++gCharaObj->unk_42 > 59) {
            gCharaObj->unk_42 = 0;
            gCharaObj->unk_44++;
        }
        break;
    case 2:
        func_080149BC(gCharaObj->unk_00, gCharaObj->unk_04 + gCharaObj->unk_08 - 0x1000);
        m4aSongNumStart(0x228);
        for (i = 0; i < 32; i++) {
            func_08007F20(i, gCharaObj->unk_1050[i]);
        }
        gCharaObj->unk_44++;
        break;
    case 3:
        CpuSet((void*)0x05000000, gCharaObj->unk_46, 0x200);
        gCharaObj->unk_44++;
        break;
    case 4:
        gCharaObj->unk_3A++;
        FadeAllPalettesToBlack(gCharaObj->unk_46, gCharaObj->unk_3A);
        if (++gCharaObj->unk_42 > 9) {
            gCharaObj->unk_42 = 0;
            gCharaObj->unk_44++;
        }
        break;
    case 5:
        gCharaObj->unk_3A = 0;
        gCharaObj->unk_44++;
        break;
    case 6:
        if (++gCharaObj->unk_42 > 89) {
            gCharaObj->unk_42 = 0;
            gCharaObj->unk_44++;
        }
        break;
    case 7:
        if (gCharaObj->unk_40 > 1) {
            gCharaObj->unk_40 = 0;
            gCharaObj->unk_3A++;
        }
        gCharaObj->unk_40++;
        if (gCharaObj->unk_42 == 20) {
            func_08006B4C();
            m4aSongNumStart(0x229);
            fade0.unk_00 = (u8*)gCharaObj->unk_0C;
            fade0.unk_04 = gCharaObj->unk_10;
            fade0.unk_06 = 1;
            if (fade0.unk_04 != 0) {
                TaskCreate(&gCharaTaskPool, &gUnk_09EF34A8, &fade0);
            }
            fade1.unk_00 = (u8*)gCharaObj->unk_14;
            fade1.unk_04 = gCharaObj->unk_18;
            fade1.unk_06 = 1;
            if (fade1.unk_04 != 0) {
                TaskCreate(&gCharaTaskPool, &gUnk_09EF34A8, &fade1);
            }
            fade2.unk_00 = (u8*)gCharaObj->unk_1C;
            fade2.unk_04 = gCharaObj->unk_20;
            fade2.unk_06 = 1;
            if (fade2.unk_04 != 0) {
                TaskCreate(&gCharaTaskPool, &gUnk_09EF34A8, &fade2);
            }
            fade3.unk_00 = (u8*)gCharaObj->unk_2C;
            fade3.unk_04 = gCharaObj->unk_30;
            fade3.unk_06 = 1;
            if (fade3.unk_04 != 0) {
                TaskCreate(&gCharaTaskPool, &gUnk_09EF34A8, &fade3);
            }
        }
        if (gCharaObj->unk_28 != 0) {
            FadePaletteToWhite((u16*)gCharaObj->unk_24, (u16*)gCharaObj->unk_24, gCharaObj->unk_28, gCharaObj->unk_3A);
        }
        if (gCharaObj->unk_38 != 0) {
            FadePaletteToWhite((u16*)gCharaObj->unk_34, (u16*)gCharaObj->unk_34, gCharaObj->unk_38, gCharaObj->unk_3A);
        }
        if (++gCharaObj->unk_42 > 39) {
            gCharaObj->unk_42 = 0;
            m4aSongNumStop(0x229);
            gCharaObj->unk_44++;
        }
        break;
    case 8:
        gCharaObj->unk_3A = 0;
        gCharaObj->unk_40 = 0;
        m4aSongNumStart(0x22A);
        func_08006184(2, 20);
        func_080063A8();
        gCharaObj->unk_44++;
        break;
    case 9:
        if (gCharaObj->unk_40 > 1) {
            gCharaObj->unk_40 = 0;
            gCharaObj->unk_3A++;
        }
        gCharaObj->unk_40++;
        if (++gCharaObj->unk_42 > 37) {
            gCharaObj->unk_42 = 0;
            gCharaObj->unk_44++;
        }
        break;
    case 10:
        if (++gCharaObj->unk_42 > 20) {
            gCharaObj->unk_42 = 0;
            gCharaObj->unk_44++;
        }
        break;
    case 11:
        gCharaObj->unk_40 = 0;
        if (gCharaObj->unk_1048 != 0) {
            ((void (*)(void))gCharaObj->unk_1048)();
        }
        gCharaObj->unk_3A = 32;
        gCharaObj->unk_44++;
        break;
    case 12:
        FadeAllPalettesToWhite(gCharaObj->unk_46, gCharaObj->unk_3A);
        if ((gCharaObj->unk_3A -= 2) <= 0) {
            gCharaObj->unk_3A = 0;
            gCharaObj->unk_42 = 0;
            gCharaObj->unk_44++;
        }
        break;
    case 13:
        FadeAllPalettesToBlack(gCharaObj->unk_46, gCharaObj->unk_3A);
        if ((gCharaObj->unk_3A += 2) > 11) {
            gCharaObj->unk_3A = 12;
            gCharaObj->unk_42 = 0;
            gCharaObj->unk_44++;
        }
        break;
    case 14:
        prize.x = gCharaObj->unk_00;
        prize.y = gCharaObj->unk_04;
        prize.z = gCharaObj->unk_08;
        func_08096DC4(&gBtlWork->taskPools[0], &prize);
        func_0801B918((void*)gCharaObj->unk_104C);
        if ((gCharaObj->unk_1090 & 1) == 0) {
            func_08014B30(gCharaObj->unk_00, gCharaObj->unk_04 + gCharaObj->unk_08 - 0x1000);
            gCharaObj->unk_42 = 0;
            gCharaObj->unk_44++;
        } else {
            gCharaObj->unk_3A = 12;
            gCharaObj->unk_42 = 0;
            gCharaObj->unk_44 = 19;
        }
        break;
    case 15:
        func_0801475C(76, 0, gCharaObj->unk_3C);
        if (++gCharaObj->unk_42 > 79) {
            gCharaObj->unk_42 = 0;
            gCharaObj->unk_44++;
        }
        break;
    case 16:
        gCharaObj->unk_3C = 0;
        gCharaObj->unk_44++;
        break;
    case 17:
        func_0801475C(0, 0, gCharaObj->unk_3C);
        gCharaObj->unk_3C -= 25;
        if (++gCharaObj->unk_42 > 39) {
            gCharaObj->unk_42 = 0;
            gCharaObj->unk_44++;
        }
        break;
    case 18:
        func_08006B4C();
        gCharaObj->unk_3A = 12;
        gCharaObj->unk_44++;
        break;
    case 19:
        gCharaObj->unk_3A--;
        FadeAllPalettesToBlack(gCharaObj->unk_46, gCharaObj->unk_3A);
        if (gCharaObj->unk_3A <= 0) {
            gCharaObj->unk_3A = 0;
            gCharaObj->unk_42 = 0;
            CharaObjFree();
            gCharaObj->unk_44++;
        }
        break;
    default:
        return 0;
    }
    TaskPoolUpdate(&gCharaTaskPool);
    TaskPoolDraw(&gCharaTaskPool);
    return 1;
}

void func_080C6E7C(u8* src, u8* dst, u16 size, s16 count) {
    s32 i;
    s32 n;

    i = count;
    n = i;
    for (i = 0; i < n; i++) {
        RequestDma3Copy(src + i * 0x400, dst + i * 0x400, size * 32);
    }
}

void func_080C6EB0(u8* src, u8* dst, u16 size, s16 count) {
    s32 i;
    s32 n;

    i = count;
    n = i;
    for (i = 0; i < n; i++) {
        RequestDma3Copy(src + i * 0x40, dst + i * 0x40, size * 2);
    }
}
