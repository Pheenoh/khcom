#include "macros.h"
#include "chara.h"

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

#ifdef NON_MATCHING
u8 task_chgCardObj_1(ChgCardObjWork* work) {
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
        work->unk_2A += (64 - work->unk_2A) >> 4;
        work->unk_2B = 0;
        work->unk_40 = func_0805F588(work->unk_20 - *work->unk_08, work->unk_24 - *work->unk_0C);
        work->unk_34 -= work->unk_30;
        work->unk_30 += 2;
        p10 = work->unk_10;
        *p10 = (-gSineTable[((work->unk_2B + 128) & 0xFF) + 64] * work->unk_2C) >> 8;
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
                *work->unk_1C = 0;
                return 0;
            }
        }
        break;
    }
    return 1;
}
#else
INCLUDE_ASM("chara/task_chgCardObj_1.s");
#endif

void task_chgCardObj_2(void) {
}

void task_chgCardObj_3(void) {
}

u8 func_080C54B4(void) {
    u32* p;

    p = &gUnk_02039820;
    *p = func_08006ED4(gUnk_0203982C, gUnk_02039B68, gUnk_020397E0);
    gUnk_02039828 = gUnk_02039820 & 3;
    gUnk_020397FC = (gUnk_02039820 & 0x1C) >> 2;
    gUnk_02039824 = (gUnk_02039820 & 0xE00) >> 9;
    if ((gUnk_02039820 & 0x40) && gUnk_02039828 <= 1) {
        func_080C5AA4();
        if ((gUnk_02039820 & 0x100) == 0) {
            gUnk_02039B60 = func_080C5B50();
        }
        if (gUnk_02039820 & 0x7F0000) {
            if (gUnk_0203C3A8 == 1) {
                gUnk_020397D4++;
                if (gUnk_020397D4 > 180) {
                    gUnk_02039B60 = 1;
                }
            }
        }
        if (gUnk_02039B60 == 1) {
            gUnk_03006C78 &= 0xFFFE;
            gUnk_020397F0 = gUnk_02039820;
            func_080010CC(&gUnk_09EF15B8, 0);
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

    p = &gUnk_02039820;
    *p = func_0800702C(gUnk_0203982C, gUnk_02039B68, gUnk_020397E0);
    gUnk_02039828 = gUnk_02039820 & 3;
    gUnk_020397FC = (gUnk_02039820 & 0x1C) >> 2;
    gUnk_02039824 = (gUnk_02039820 & 0xE00) >> 9;
    if ((gUnk_02039820 & 0x40) && gUnk_02039828 <= 1) {
        if (gUnk_020397F8 != 0) {
            gUnk_02039B60 = gUnk_020397F8();
        }
        if (gUnk_02039804 != 0) {
            gUnk_02039804();
        }
        if (gUnk_02039820 & 0x7F0000) {
            if (gUnk_0203C3A8 == 1) {
                gUnk_020397D4++;
                if (gUnk_020397D4 > 180) {
                    gUnk_03006C78 &= 0xFFFE;
                    gUnk_020397F0 = gUnk_02039820;
                    func_080010CC(&gUnk_09EF15B8, 0);
                    gUnk_02039B60 = 1;
                }
            }
        }
    }
    return gUnk_02039B60;
}


u8 func_080C56BC(void) {
    u32* p;

    p = &gUnk_02039820;
    *p = func_08006ED4(gUnk_0203982C, gUnk_02039B68, gUnk_020397E0);
    gUnk_02039828 = gUnk_02039820 & 3;
    gUnk_020397FC = (gUnk_02039820 & 0x1C) >> 2;
    gUnk_02039824 = (gUnk_02039820 & 0xE00) >> 9;
    if ((gUnk_02039820 & 0x40) && gUnk_02039828 <= 1) {
        func_080C5C24();
        if ((gUnk_02039820 & 0x100) == 0) {
            gUnk_02039B60 = func_080C5C7C();
        }
        if (gUnk_02039820 & 0x7F0000) {
            if (gUnk_0203C3A8 == 1) {
                gUnk_020397D4++;
                if (gUnk_020397D4 > 180) {
                    gUnk_02039B60 = 1;
                }
            }
        }
        if (gUnk_02039B60 == 1) {
            gUnk_03006C78 &= 0xFFFE;
            gUnk_020397F0 = gUnk_02039820;
            func_080010CC(&gUnk_09EF15B8, 0);
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
    if (gUnk_03006C78 & 1) {
        func_080078A4();
        gUnk_03006C78 &= 0xFFFE;
    }
    if (gUnk_03006C78 & 0x10) {
        gUnk_03006C78 &= 0xFFEF;
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
    gUnk_0203BEB0 = gUnk_03006C68;
}

void func_080C590C(void) {
    gUnk_0203BEA0 = (gUnk_03006C68 - gUnk_0203BEB0) & 0xFFFF;
}

s32 func_080C5930(void) {
    if (gUnk_02039820 & 0x7F0000) {
        return 1;
    }
    return 0;
}

void func_080C594C(void) {
    func_08006E60();
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
            gUnk_03006C78 |= 1;
            gUnk_03006C78 &= 0xFFEF;
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

#ifdef VERSION_US
void func_080C5A3C(void (*a)(void), void (*b)(void), u8 c) {
    gUnk_0203C3B0 = (c & 0xF) | 0xC1F0;
    gUnk_0203C3A0 = 0;
    gUnk_0203C3A8 = 0;
    gUnk_0203C38C = 0;
    gUnk_0203C3AC = a;
    gUnk_0203BEAC = b;
    gUnk_0203BEA4 = 0;
    gUnk_02039B68[0] = 0xDDDD;
    gUnk_02039B68[1] = 0xDDDD;
}
#else
INCLUDE_ASM("chara/func_080C5A3C.s");
#endif

#ifdef NON_MATCHING
s32 func_080C5AA4(void) {
    u16* base;
    u16* p;
    u16 v;
    u16* base2;
    u16* p2;

    if (gUnk_0203C3A8 == 0) {
        if (gUnk_0203C3A0 == 0) {
            if (GetKeysPressed() & 1) {
                gUnk_02039B68[0] = 0xFEFE;
            } else if (GetKeysPressed() & 2) {
                gUnk_02039B68[0] = 0xAFAF;
            } else {
                base = gUnk_02039B68;
                v = 0;
                p = &gUnk_02039B68[3];
                do {
                    *p = v;
                    p--;
                } while ((s32)p >= (s32)base);
            }
            gUnk_02039B68[1] = gUnk_0203C3B0;
        } else {
            gUnk_02039B68[0] = 0xECEC;
        }
    } else {
        base2 = gUnk_02039B68;
        v = 0;
        p2 = base2 + 3;
        do {
            *p2 = v;
            p2--;
        } while ((s32)p2 >= (s32)base2);
    }
    return 0;
}
#else
INCLUDE_ASM("chara/func_080C5AA4.s");
#endif
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
                    v = gUnk_02039828 == 0 ? gUnk_020397E0[0][0] : gUnk_020397E0[0][1];
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

#ifdef NON_MATCHING
void func_080C5DC0(s32 (*a)(void), s32 (*b)(void)) {
    u16* base;
    u16* p;
    u16 v;
    s32 i;
    s32 j;
    s32 k;
    s32 off;
    s32 (**pa)(void);
    s32 (**pb)(void);
    u16* p1;
    u16* p2;

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
#else
INCLUDE_ASM("chara/func_080C5DC0.s");
#endif

s32 func_080C5E58(void) {
    if (gUnk_02039828 == 0) {
        gUnk_02039B68[0] = 0xACD;
        gUnk_02039B68[1] = GetKeysHeld() & 0x3FF;
        gUnk_02039B68[2] = gUnk_0203C3B4;
        gUnk_02039B68[3] = gUnk_0203C388;
    } else {
        gUnk_02039B68[0] = 0xACD;
        gUnk_02039B68[1] = GetKeysHeld() & 0x3FF;
        gUnk_02039B68[2] = 0x1234;
        gUnk_02039B68[3] = 0x3456;
    }
    return 0;
}

s32 func_080C5ECC(void) {
    if (gUnk_02039828 == 0) {
        if (gUnk_020397E0[0][0] == 0xACD && gUnk_020397E0[0][1] == gUnk_020397E0[0][0]) {
            gUnk_0203C3B4 = gUnk_020397E0[1][0];
            gUnk_0203C388 = gUnk_020397E0[1][1];
            gUnk_02039820 &= ~0x100;
        } else {
            gUnk_02039820 |= 0x100;
        }
        if (gUnk_020397E0[0][0] == 0xACD) {
            func_08008944(gUnk_020397E0[2][0]);
            func_0800895C(gUnk_020397E0[3][0]);
            gUnk_02039820 &= ~0x100;
        } else {
            gUnk_02039820 |= 0x100;
        }
    } else {
        if (gUnk_020397E0[0][0] == 0xACD) {
            func_08008944(gUnk_020397E0[2][0]);
            func_0800895C(gUnk_020397E0[3][0]);
            gUnk_02039820 &= ~0x100;
        } else {
            gUnk_02039820 |= 0x100;
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
    } else if (gUnk_02039828 == 0) {
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


#ifdef NON_MATCHING
void func_080C61D4(void) {
    s32 i;
    u8* q;

    gUnk_0203AAC0.unk_00 = gUnk_02039BB0.unk_032;
    gUnk_0203AAC0.unk_02 = gUnk_02039BB0.unk_0F8;
    gUnk_0203AAC0.unk_04 = gUnk_02039BB0.unk_108;
    gUnk_0203AAC0.unk_06 = gUnk_0203A9EC;
    gUnk_0203AAC0.unk_08 = gUnk_0203A9F0;
    gUnk_0203AAC0.unk_0A = gUnk_02039BB0.unk_0FE;
    gUnk_0203AAC0.unk_0C = gUnk_02039BB0.unk_10C;
    gUnk_0203AAC0.unk_10 = gUnk_02039BB0.unk_110;
    gUnk_0203AAC0.unk_14 = gUnk_02039BB0.unk_114;
    gUnk_0203AAC0.unk_18 = gUnk_02039BB0.unk_118;
    gUnk_0203AAC0.unk_1C = 0;
    q = gUnk_02039BB0.unk_186;
    for (i = 12; i >= 0; i--) {
        if ((u8)(*q - 1) <= 11) {
            gUnk_0203AAC0.unk_1C |= 1 << *q;
        }
        q += 4;
    }
    if (gUnk_02039828 == 0) {
        SeedRandom(gUnk_03007480 & 0xFFFF);
        gUnk_0203AAC0.unk_1E = GetRandom() % 0xFFFF;
    } else {
        gUnk_0203AAC0.unk_1E = 0;
    }
    gUnk_0203C378 = 11;
    gUnk_0203C394 = 1;
    gUnk_0203C3A4 = 0;
    gUnk_0203C380 = 0;
    gUnk_0203C384 = 0;
    gUnk_0203C390 = (u16*)&gUnk_0203AAC0;
    gUnk_0203C39C = gUnk_0203AA10;
}
#else
INCLUDE_ASM("chara/func_080C61D4.s");
#endif

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
            if (gUnk_02039828 == 0 && gUnk_020397E0[0][0] == 0xECEC &&
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

void func_080C640C(CharaObjParam2* param) {
    s32 i;

    gUnk_02034CD8 = EwramAlloc(0x1094);
    gUnk_02034CD8->unk_0C = param->unk_00;
    gUnk_02034CD8->unk_10 = param->unk_04;
    gUnk_02034CD8->unk_24 = param->unk_08;
    gUnk_02034CD8->unk_28 = param->unk_0C;
    gUnk_02034CD8->unk_00 = param->unk_10;
    gUnk_02034CD8->unk_04 = param->unk_14;
    gUnk_02034CD8->unk_08 = param->unk_18;
    gUnk_02034CD8->unk_3A = 0;
    gUnk_02034CD8->unk_3C = -76;
    gUnk_02034CD8->unk_40 = 0;
    gUnk_02034CD8->unk_42 = 0;
    gUnk_02034CD8->unk_44 = 0;
    gUnk_02034CD8->unk_1048 = param->unk_1C;
    gUnk_02034CD8->unk_2C = 0;
    gUnk_02034CD8->unk_30 = 0;
    gUnk_02034CD8->unk_34 = 0;
    gUnk_02034CD8->unk_38 = 0;
    gUnk_02034CD8->unk_104C = param->unk_20;
    for (i = 0; i < 32; i++) {
        gUnk_02034CD8->unk_1050[i] = 0;
    }
    TaskPoolInit(gUnk_02034CE0, 2);
}

INCLUDE_ASM("chara/func_080C64A4.s");

void func_080C6878(void) {
    EwramFree(gUnk_02034CD8);
    TaskPoolDestroy(gUnk_02034CE0);
}

void func_080C6894(CharaObjParam* param) {
    s32 i;
    u16 idx;

    gUnk_02034CD8 = EwramAlloc(0x1094);
    gUnk_02034CD8->unk_1090 = 0;
    gUnk_02034CD8->unk_0C = param->unk_00;
    gUnk_02034CD8->unk_10 = param->unk_04;
    gUnk_02034CD8->unk_14 = param->unk_08;
    gUnk_02034CD8->unk_18 = param->unk_0C;
    gUnk_02034CD8->unk_1C = param->unk_10;
    gUnk_02034CD8->unk_20 = param->unk_14;
    gUnk_02034CD8->unk_24 = param->unk_18;
    gUnk_02034CD8->unk_28 = param->unk_1C;
    gUnk_02034CD8->unk_2C = param->unk_20;
    gUnk_02034CD8->unk_30 = param->unk_24;
    gUnk_02034CD8->unk_34 = param->unk_28;
    gUnk_02034CD8->unk_38 = param->unk_2C;
    gUnk_02034CD8->unk_00 = param->unk_30;
    gUnk_02034CD8->unk_04 = param->unk_34;
    gUnk_02034CD8->unk_08 = param->unk_38;
    gUnk_02034CD8->unk_3A = 0;
    gUnk_02034CD8->unk_3C = -76;
    gUnk_02034CD8->unk_40 = 0;
    gUnk_02034CD8->unk_42 = 0;
    gUnk_02034CD8->unk_44 = 0;
    gUnk_02034CD8->unk_1048 = param->unk_3C;
    gUnk_02034CD8->unk_104C = param->unk_40;
    gUnk_02034CD8->unk_1090 = param->unk_44;
    for (i = 0; i < 10; i++) {
        gUnk_02034CD8->unk_1050[i] = 1;
    }
    for (i = 10; i < 32; i++) {
        gUnk_02034CD8->unk_1050[i] = 0;
    }
    idx = gUnk_02034CD8->unk_24 >> 5;
    if (gUnk_02034CD8->unk_28 == 32) {
        gUnk_02034CD8->unk_1050[(s16)idx] = 1;
    }
    TaskPoolInit(gUnk_02034CE0, 4);
}

void func_080C6990(u16 a, u8 b) {
    if (a <= 31) {
        gUnk_02034CD8->unk_1050[a] = b;
    }
}

INCLUDE_ASM("chara/func_080C69B4.s");

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
