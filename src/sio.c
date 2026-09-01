#include "sio.h"

u8 func_08006B74(void) {
    return gUnk_02034054;
}

void func_08006B80(u16* a, u16* b) {
    if (a != 0) {
        *a = gUnk_02034046;
    }
    if (b != 0) {
        *b = gUnk_02034044;
    }
}

s32 func_08006BA0(u8* p) {
    return *(u16*)(p + 0x14) * *(u16*)(p + 0x16);
}

u8* func_08006BA8(void) {
    return gUnk_02034040;
}

u16 func_08006BB4(void) {
    if (REG_IME & 1) {
        if (REG_DISPSTAT & 8) {
            if (REG_IE & 1) {
                if (!(REG_DISPCNT & 0x80)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void func_08006BFC(IntrFunc fn) {
    gUnk_03006C70 = fn;
    if (!func_08006BB4()) {
        *gUnk_03006C5C = fn;
    }
}

void func_08006C24(void) {
    *gUnk_03006C5C = func_080004DC;
    gUnk_03006C70 = func_080004DC;
}

void func_08006C40(IntrFunc fn) {
    gUnk_03006C6C = fn;
    if (!func_08006BB4()) {
        *gUnk_03006C58 = fn;
    }
}

void func_08006C68(void) {
    *gUnk_03006C58 = func_080005A8;
    gUnk_03006C6C = func_080005A8;
}

void func_08006C84(IntrFunc fn) {
    gUnk_03006C64 = fn;
    if (!func_08006BB4()) {
        *gUnk_03006C74 = fn;
    }
}

void func_08006CAC(void) {
    *gUnk_03006C74 = func_080005A4;
    gUnk_03006C64 = func_080005A4;
}

void func_08006CC8(IntrFunc fn) {
    *gUnk_03006C14 = fn;
}

void func_08006CD4(void) {
    *gUnk_03006C14 = func_080005AC;
}

void func_08006CE8(IntrFunc fn) {
    *gUnk_03006C60 = fn;
}

void func_08006CF4(void) {
    *gUnk_03006C60 = func_080005AC;
}

void func_08006D08(void) {
    u16* p;
    u16 ime;
    u32 zero;

    p = &gUnk_0203406E;
    ime = REG_IME;
    REG_IME = 0;
    REG_IE &= 0xFF3F;
    REG_IME = ime;
    REG_RCNT = 0;
    REG_SIOCNT = 0x2000;
    REG_SIOCNT |= 0x4003;
    *p = REG_IME;
    func_08006BFC(func_08000660);
    func_08006CC8(func_080073B4);
    func_08006CE8(func_080073A4);
    REG_IME = 0;
    REG_IE |= 0x80;
    REG_IME = *p;
    REG_SIOMLT_SEND = 0;
    *(u64*)0x04000120 = 0;
    zero = 0;
    CpuSet(&zero, &gUnk_02039830, (sizeof(SioWork) / 4) | 0x05000000);
    gUnk_02034070 = 0;
    gUnk_02034071 = 0;
    gUnk_02034073 = 0;
    gUnk_020397D0 = 0;
    gUnk_02039800 = 0;
    gUnk_02039820 = 0;
    gUnk_020397D4 = 0;
    gUnk_020397F0 = 0;
    gUnk_02039828 = 0;
    gUnk_020397FC = 0;
    gUnk_02039824 = 0;
    gUnk_0203982C = 0;
    gUnk_02039B60 = 0;
    gUnk_02034074 = 0;
    gUnk_0203406C = 0;
    gUnk_02034076 = 0;
    gUnk_02034078 = 0;
    gUnk_02039804 = 0;
    gUnk_020397F8 = 0;
}

void func_08006E60(void) {
    func_08006D08();
    func_08006E74();
}

void func_08006E70(void) {
}

void func_08006E74(void) {
    u32 zero;

    gUnk_0203406E = REG_IME;
    REG_IME = 0;
    REG_IE &= 0xFF3F;
    REG_IME = gUnk_0203406E;
    REG_SIOCNT = 0;
    REG_TM3CNT_H = 0;
    REG_IF = 0xC0;
    zero = 0;
    CpuSet(&zero, &gUnk_02039830, (sizeof(SioWork) / 4) | 0x05000000);
}

u32 func_08006ED4(u8* a, u16* b, u16 (*c)[2]) {
    u32 r;
    u32 v;
    u32 w;
    u32 t0, t1, t2, t3, t4, t5;

    switch (gUnk_02039830.unk_01) {
    case 0:
        func_08006E74();
        gUnk_02039830.unk_01 = 1;
        break;
    case 1:
        func_08006D08();
        gUnk_02039830.unk_01 = 2;
        break;
    case 2:
        switch (*a) {
        default:
            func_080070B4();
            if (gUnk_02034074 == 0) {
                if (gUnk_02039830.unk_00 != 0 && gUnk_02039830.unk_03 == 2) {
                    gUnk_02039830.unk_10 = 1;
                    gUnk_02034074 = -1;
                }
            }
            break;
        case 1:
            if (gUnk_02039830.unk_00 != 0 && gUnk_02039830.unk_03 == 2) {
                gUnk_02039830.unk_10 = 1;
            }
            gUnk_02034074 = -1;
            break;
        case 2:
            gUnk_02039830.unk_01 = 0;
            REG_SIOMLT_SEND = 0;
            break;
        }
        break;
    case 3:
        func_080070DC();
        gUnk_02039830.unk_01 = 4;
    case 4:
        if (gUnk_02039830.unk_0E == 0) {
            func_0800712C(b);
        }
        func_08007210(c);
        break;
    }

    *a = 0;
    r = gUnk_02039830.unk_02 | (gUnk_02039830.unk_03 << 2);
    if (gUnk_02039830.unk_00 == 8) {
        r |= 0x20;
    }
    t0 = gUnk_02039830.unk_0C << 8;
    t1 = gUnk_02039830.unk_11 << 9;
    t2 = gUnk_02039830.unk_12 << 16;
    t3 = gUnk_02039830.unk_13 << 17;
    t4 = gUnk_02039830.unk_14 << 18;
    t5 = gUnk_02039830.unk_15 << 20;
    if (gUnk_02039830.unk_01 == 4) {
        v = r | 0x40 | t0 | t1 | t2 | t3 | t4 | t5;
    } else {
        v = r | t0 | t1 | t2 | t3 | t4 | t5;
    }
    w = v;
    if (gUnk_02039830.unk_02 > 1) {
        w |= 0x400000;
    }
    return w;
}

u32 func_0800702C(u8* a, u16* b, u16 (*c)[2]) {
    u32 r;
    u32 v;
    u32 w;
    u32 t0, t1, t2, t3, t4, t5;

    if (gUnk_02039830.unk_01 == 4) {
        if (gUnk_02039830.unk_0E == 0) {
            func_0800712C(b);
        }
        func_08007210(c);
    }

    r = gUnk_02039830.unk_02 | (gUnk_02039830.unk_03 << 2);
    if (gUnk_02039830.unk_00 == 8) {
        r |= 0x20;
    }
    t0 = gUnk_02039830.unk_0C << 8;
    t1 = gUnk_02039830.unk_11 << 9;
    t2 = gUnk_02039830.unk_12 << 16;
    t3 = gUnk_02039830.unk_13 << 17;
    t4 = gUnk_02039830.unk_14 << 18;
    t5 = gUnk_02039830.unk_15 << 20;
    if (gUnk_02039830.unk_01 == 4) {
        v = r | 0x40 | t0 | t1 | t2 | t3 | t4 | t5;
    } else {
        v = r | t0 | t1 | t2 | t3 | t4 | t5;
    }
    w = v;
    if (gUnk_02039830.unk_02 > 1) {
        w |= 0x400000;
    }
    return w;
}

void func_080070B4(void) {
    if ((REG_SIOCNT32 & 0xC) == 8 && gUnk_02039830.unk_02 == 0) {
        gUnk_02039830.unk_00 = 8;
    } else {
        gUnk_02039830.unk_00 = 0;
    }
}

void func_080070DC(void) {
    if (gUnk_02039830.unk_00 != 0) {
        REG_TM3CNT_L = 0xFF2D;
        REG_TM3CNT_H = 0x41;
        gUnk_0203406E = REG_IME;
        REG_IME = 0;
        REG_IE |= 0x40;
        REG_IME = gUnk_0203406E;
    }
}

void func_0800712C(u16* p) {
    u8 idx;
    u8 i;

    gUnk_0203406E = REG_IME;
    REG_IME = 0;
    if (gUnk_02039830.unk_11D < 32) {
        idx = gUnk_02039830.unk_11D + gUnk_02039830.unk_11C;
        if (idx > 31) {
            idx -= 32;
        }
        for (i = 0; i < 4; i++) {
            gUnk_02034076 |= *p;
            gUnk_02039830.unk_1C[i][idx] = *p;
            *p = 0;
            p++;
        }
    } else {
        gUnk_02039830.unk_14 |= 1;
    }
    if (gUnk_02034076 != 0) {
        gUnk_02039830.unk_11D++;
        gUnk_02034076 = 0;
    }
    REG_IME = gUnk_0203406E;
    gUnk_020397D0 = gUnk_02039830.unk_11D;
}

void func_08007210(u16 (*c)[2]) {
    u8 i;
    u8 j;

    gUnk_0203406E = REG_IME;
    REG_IME = 0;
    if (gUnk_02039830.unk_321 == 0) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < gUnk_02039830.unk_03; j++) {
                c[i][j] = 0;
            }
        }
        gUnk_02039830.unk_0C = 1;
    } else {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < gUnk_02039830.unk_03; j++) {
                c[i][j] = gUnk_02039830.unk_120[j][i][gUnk_02039B50];
            }
        }
        gUnk_02039830.unk_321--;
        gUnk_02039830.unk_320++;
        if (gUnk_02039830.unk_320 > 31) {
            gUnk_02039830.unk_320 = 0;
        }
        gUnk_02039830.unk_0C = 0;
    }
    REG_IME = gUnk_0203406E;
}

void func_08007318(void) {
    if (gUnk_02039830.unk_0E != 0) {
        gUnk_02034072--;
        if (gUnk_02034072 != 0) {
            return;
        }
        gUnk_02039830.unk_0E = 0;
    }
    if (gUnk_02039830.unk_00 != 0) {
        if (gUnk_02039830.unk_01 == 2) {
            func_08007444();
        } else if (gUnk_02039830.unk_01 == 4) {
            if (gUnk_02039830.unk_0D <= 4) {
                if (gUnk_02039830.unk_12 != 0) {
                    func_08007444();
                } else {
                    gUnk_02039830.unk_15 = 1;
                }
            } else if (gUnk_02039830.unk_15 == 0) {
                gUnk_02039830.unk_0D = 0;
                func_08007444();
            }
        }
    } else if (gUnk_02039830.unk_01 == 4 || gUnk_02039830.unk_01 == 2) {
        gUnk_02034070++;
        if (gUnk_02034070 > 6) {
            if (gUnk_02039830.unk_01 == 4) {
                gUnk_02039830.unk_15 = 2;
            }
            if (gUnk_02039830.unk_01 == 2) {
                gUnk_02039830.unk_02 = 0;
                gUnk_02039830.unk_03 = 0;
                gUnk_02039830.unk_11 = 0;
            }
        }
    }
}

void func_080073A4(void) {
    func_08007768();
    func_08007444();
}

void func_080073B4(void) {
    u32 cnt;

    cnt = REG_SIOCNT32;
    gUnk_02039830.unk_02 = (cnt << 26) >> 30;
    switch (gUnk_02039830.unk_01) {
    case 4:
        if (cnt & 0x40) {
            gUnk_02039830.unk_12 = 1;
        }
        func_08007550();
        func_08007694();
        func_08007798();
        break;
    case 2:
        if (func_08007454()) {
            if (gUnk_02039830.unk_00 != 0) {
                gUnk_02039830.unk_01 = 3;
                gUnk_02039830.unk_0D = 4;
            } else {
                gUnk_02039830.unk_01 = 4;
            }
        }
        break;
    }
    gUnk_02039830.unk_0D++;
    gUnk_02034070 = 0;
    if (gUnk_02039830.unk_0D == 4) {
        gUnk_02039800 = gUnk_02039830.unk_321;
    }
}

void func_08007444(void) {
    REG_SIOCNT |= 0x80;
}

u8 func_08007454(void) {
    u8 count;
    u16 min;
    u8 i;

    count = 0;
    min = 0xFFFF;
    if (gUnk_02039830.unk_10 == 1) {
        REG_SIOMLT_SEND = 0x8FFF;
    } else {
        REG_SIOMLT_SEND = 0xD5E0;
    }
    gUnk_02039830.unk_10 = 0;
    *(u64*)gUnk_02039830.unk_04 = *(u64*)0x04000120;
    for (i = 0; i < 2; i++) {
        if ((gUnk_02039830.unk_04[i] & ~3) == 0xD5E0 || gUnk_02039830.unk_04[i] == 0x8FFF) {
            count++;
            if (min > gUnk_02039830.unk_04[i] && gUnk_02039830.unk_04[i] != 0) {
                min = gUnk_02039830.unk_04[i];
            }
        } else if (gUnk_02039830.unk_04[i] == 0xFFFF) {
            if (i == gUnk_02039830.unk_02) {
                count = 0;
            }
        } else {
            count = 0;
            break;
        }
    }
    gUnk_02039830.unk_03 = count;
    if (gUnk_02039830.unk_03 == 2) {
        if (gUnk_02039830.unk_03 == gUnk_02034073 && gUnk_02039830.unk_04[0] == 0x8FFF) {
            return 1;
        }
        if (gUnk_02039830.unk_03 == 2) {
            gUnk_02039830.unk_11 = (min & 3) + 1;
        } else {
            gUnk_02039830.unk_11 = 0;
        }
    } else {
        gUnk_02039830.unk_11 = 0;
    }
    gUnk_02034073 = gUnk_02039830.unk_03;
    return 0;
}

void func_08007550(void) {
    u16 buf[4];
    u8 i;
    u8 idx;

    *(u64*)buf = *(u64*)0x04000120;
    if (gUnk_02039830.unk_18 == 0) {
        for (i = 0; i < gUnk_02039830.unk_03; i++) {
            if (gUnk_02039830.unk_16 != buf[i] && gUnk_0203406C != 0) {
                gUnk_02039830.unk_13 = 1;
            }
        }
        gUnk_02039830.unk_16 = 0;
        gUnk_0203406C = 1;
    } else {
        idx = gUnk_02039830.unk_320 + gUnk_02039830.unk_321;
        if (idx > 31) {
            idx -= 32;
        }
        if (gUnk_02039830.unk_321 < 32) {
            for (i = 0; i < gUnk_02039830.unk_03; i++) {
                gUnk_02039830.unk_16 += buf[i];
                gUnk_02034078 |= buf[i];
                gUnk_02039830.unk_120[i][gUnk_02039830.unk_19][idx] = buf[i];
                if (gUnk_02039830.unk_18 == 1 && gUnk_02039830.unk_0E == 0 && (buf[i] & 0x1000)) {
                    gUnk_02039830.unk_0E = 1;
                    gUnk_02034072 = 5;
                }
            }
        } else {
            gUnk_02039830.unk_14 |= 2;
        }
        gUnk_02039830.unk_19++;
        if (gUnk_02039830.unk_19 == 4 && gUnk_02034078 != 0) {
            gUnk_02039830.unk_321++;
            gUnk_02034078 = 0;
        }
    }
}

void func_08007694(void) {
    if (gUnk_02039830.unk_18 == 4) {
        REG_SIOMLT_SEND = gUnk_02039830.unk_16;
        if (gUnk_02034071 == 0) {
            gUnk_02039830.unk_11D--;
            gUnk_02039830.unk_11C++;
            if (gUnk_02039830.unk_11C > 31) {
                gUnk_02039830.unk_11C = 0;
            }
        } else {
            gUnk_02034071 = 0;
        }
    } else {
        if (gUnk_02039830.unk_18 == 0 && gUnk_02039830.unk_11D == 0) {
            gUnk_02034071 = 1;
        }
        if (gUnk_02034071 != 0) {
            REG_SIOMLT_SEND = 0;
        } else {
            REG_SIOMLT_SEND = gUnk_02039830.unk_1C[gUnk_02039830.unk_18][gUnk_02039830.unk_11C];
        }
        if (gUnk_02039830.unk_0E == 0 && gUnk_02039830.unk_18 == 0 && gUnk_02039830.unk_321 > 3) {
            REG_SIOMLT_SEND |= 0x1000;
        }
        gUnk_02039830.unk_18++;
    }
}

void func_08007768(void) {
    if (gUnk_02039830.unk_00 != 0) {
        REG_TM3CNT_H &= 0xFF7F;
        REG_TM3CNT_L = 0xFF2D;
    }
}

void func_08007798(void) {
    if (gUnk_02039830.unk_19 == 4) {
        gUnk_02039830.unk_18 = 0;
        gUnk_02039830.unk_19 = 0;
    } else if (gUnk_02039830.unk_00 != 0) {
        REG_TM3CNT_H |= 0x80;
    }
}

void func_080077C4(void) {
    u8 i;
    u8 j;

    gUnk_02039830.unk_11D = 0;
    gUnk_02039830.unk_11C = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 32; j++) {
            gUnk_02039830.unk_1C[i][j] = 0xEFFF;
        }
    }
}

void func_08007814(void) {
    u8 i;
    u8 j;
    u8 k;

    gUnk_02039830.unk_321 = 0;
    gUnk_02039830.unk_320 = 0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 32; k++) {
                gUnk_02039830.unk_120[i][j][k] = 0xEFFF;
            }
        }
    }
}

void func_08007874(void) {
    REG_RCNT = 0;
    REG_SIOCNT = 0;
    REG_SIODATA8 = 0;
    REG_SIODATA32 = 0;
    REG_SIOMLT_SEND = 0;
    REG_SIOMLT_RECV = 0;
    REG_SIOMULTI0 = 0;
    REG_SIOMULTI1 = 0;
    REG_SIOMULTI2 = 0;
    REG_SIOMULTI3 = 0;
}

void func_080078A4(void) {
    func_08007874();
    REG_IME = 0;
    func_08006C24();
    func_08006CD4();
    func_08006CF4();
    REG_IE = 0x2001;
    REG_DISPSTAT = 8;
    REG_IME = 1;
    func_08006E74();
}

u8 func_080078E8(void) {
    if (gUnk_02039830.unk_01 == 4) {
        return 1;
    }
    return 0;
}
