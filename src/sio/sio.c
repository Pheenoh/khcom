#include "macros.h"
#include "display.h"
#include "intr.h"
#include "sio_api.h"
#include "sio.h"

u8 gUnk_020397D0 EWRAM_COMMON(4);
s16 gUnk_020397D4 EWRAM_COMMON(4);
u16 gUnk_020397E0[4][2] EWRAM_COMMON(16);
u32 gUnk_020397F0 EWRAM_COMMON(4);
s32 (*gUnk_020397F8)(void) EWRAM_COMMON(8);
u8 gUnk_020397FC EWRAM_COMMON(4);
u8 gUnk_02039800 EWRAM_COMMON(4);
s32 (*gUnk_02039804)(void) EWRAM_COMMON(4);
u16 gUnk_02039810[4][2] EWRAM_COMMON(16);
u32 gSioStatus EWRAM_COMMON(4);
u8 gUnk_02039824 EWRAM_COMMON(4);
u32 gSioPlayerId EWRAM_COMMON(4);
u8 gUnk_0203982C EWRAM_COMMON(4);
SioWork gSioWork EWRAM_COMMON(16);
u16 gUnk_02039B58[4] EWRAM_COMMON(8);
u8 gUnk_02039B60 EWRAM_COMMON(4);
u16 gUnk_02039B68[4] EWRAM_COMMON(8);

extern IntrFunc* gIntrTableSerial;
extern IntrFunc* gIntrTableVCount;
extern IntrFunc* gIntrTableVBlank;
extern IntrFunc* gIntrTableTimer3;
extern IntrFunc gHBlankCallback;
extern IntrFunc gVCountCallback;
extern IntrFunc gVBlankCallback;
extern IntrFunc* gIntrTableHBlank;

u8 gUnk_0203406C;
u16 gUnk_0203406E;
u8 gUnk_02034070;
u8 gUnk_02034071;
u8 gUnk_02034072;
u8 gUnk_02034073;
s8 gUnk_02034074;
u16 gUnk_02034076;
u16 gUnk_02034078;

u16 IsVBlankIntrLive(void) {
    if (REG_IME & 1) {
        if (REG_DISPSTAT & DISPSTAT_VBLANK_INTR) {
            if (REG_IE & INTR_FLAG_VBLANK) {
                if (!(REG_DISPCNT & DISPCNT_FORCED_BLANK)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void SetVBlankCallback(IntrFunc fn) {
    gVBlankCallback = fn;

    if (!IsVBlankIntrLive()) {
        *gIntrTableVBlank = fn;
    }
}

void ResetVBlankCallback(void) {
    *gIntrTableVBlank = VBlankIntr;
    gVBlankCallback = VBlankIntr;
}

void SetVCountCallback(IntrFunc fn) {
    gVCountCallback = fn;

    if (!IsVBlankIntrLive()) {
        *gIntrTableVCount = fn;
    }
}

void ResetVCountCallback(void) {
    *gIntrTableVCount = VCountIntrDummy;
    gVCountCallback = VCountIntrDummy;
}

void SetHBlankCallback(IntrFunc fn) {
    gHBlankCallback = fn;

    if (!IsVBlankIntrLive()) {
        *gIntrTableHBlank = fn;
    }
}

void ResetHBlankCallback(void) {
    *gIntrTableHBlank = HBlankIntrDummy;
    gHBlankCallback = HBlankIntrDummy;
}

void SetSerialCallback(IntrFunc fn) {
    *gIntrTableSerial = fn;
}

void ResetSerialCallback(void) {
    *gIntrTableSerial = SerialIntrDummy;
}

void SetTimer3Callback(IntrFunc fn) {
    *gIntrTableTimer3 = fn;
}

void ResetTimer3Callback(void) {
    *gIntrTableTimer3 = SerialIntrDummy;
}

void SioInit(void) {
    u16* p;
    u16 ime;
    u32 zero;

    p = &gUnk_0203406E;
    ime = REG_IME;
    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_IME = ime;
    REG_RCNT = 0;
    REG_SIOCNT = SIO_MULTI_MODE;
    REG_SIOCNT |= (SIO_INTR_ENABLE | SIO_115200_BPS);
    *p = REG_IME;
    SetVBlankCallback(VBlankIntrSio);
    SetSerialCallback(SioSerialIntr);
    SetTimer3Callback(SioTimer3Intr);
    REG_IME = 0;
    REG_IE |= INTR_FLAG_SERIAL;
    REG_IME = *p;
    REG_SIOMLT_SEND = 0;
    *(u64*)REG_ADDR_SIOMULTI0 = 0;
    zero = 0;
    CpuSet(&zero, &gSioWork, (sizeof(SioWork) / 4) | 0x05000000);
    gUnk_02034070 = 0;
    gUnk_02034071 = 0;
    gUnk_02034073 = 0;
    gUnk_020397D0 = 0;
    gUnk_02039800 = 0;
    gSioStatus = 0;
    gUnk_020397D4 = 0;
    gUnk_020397F0 = 0;
    gSioPlayerId = 0;
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

void SioReset(void) {
    SioInit();
    SioStop();
}

void func_08006E70(void) {
}

void SioStop(void) {
    u32 zero;

    gUnk_0203406E = REG_IME;
    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_IME = gUnk_0203406E;
    REG_SIOCNT = 0;
    REG_TM3CNT_H = 0;
    REG_IF = (INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    zero = 0;
    CpuSet(&zero, &gSioWork, (sizeof(SioWork) / 4) | 0x05000000);
}

u32 func_08006ED4(u8* a, u16* b, u16 (*c)[2]) {
    u32 r;
    u32 v;
    u32 w;
    u32 t0, t1, t2, t3, t4, t5;

    switch (gSioWork.unk_01) {
    case 0:
        SioStop();
        gSioWork.unk_01 = 1;
        break;
    case 1:
        SioInit();
        gSioWork.unk_01 = 2;
        break;
    case 2:
        switch (*a) {
        default:
            func_080070B4();

            if (gUnk_02034074 == 0) {
                if (gSioWork.unk_00 != 0 && gSioWork.playerCount == 2) {
                    gSioWork.unk_10 = 1;
                    gUnk_02034074 = -1;
                }
            }
            break;
        case 1:
            if (gSioWork.unk_00 != 0 && gSioWork.playerCount == 2) {
                gSioWork.unk_10 = 1;
            }
            gUnk_02034074 = -1;
            break;
        case 2:
            gSioWork.unk_01 = 0;
            REG_SIOMLT_SEND = 0;
            break;
        }
        break;
    case 3:
        func_080070DC();
        gSioWork.unk_01 = 4;
    case 4:
        if (gSioWork.unk_0E == 0) {
            func_0800712C(b);
        }
        func_08007210(c);
        break;
    }

    *a = 0;
    r = gSioWork.playerId | (gSioWork.playerCount << 2);

    if (gSioWork.unk_00 == 8) {
        r |= 0x20;
    }
    t0 = gSioWork.unk_0C << 8;
    t1 = gSioWork.unk_11 << 9;
    t2 = gSioWork.unk_12 << 16;
    t3 = gSioWork.unk_13 << 17;
    t4 = gSioWork.unk_14 << 18;
    t5 = gSioWork.unk_15 << 20;

    if (gSioWork.unk_01 == 4) {
        v = r | 0x40 | t0 | t1 | t2 | t3 | t4 | t5;
    } else {
        v = r | t0 | t1 | t2 | t3 | t4 | t5;
    }
    w = v;

    if (gSioWork.playerId > 1) {
        w |= 0x400000;
    }
    return w;
}

u32 func_0800702C(u8* a, u16* b, u16 (*c)[2]) {
    u32 r;
    u32 v;
    u32 w;
    u32 t0, t1, t2, t3, t4, t5;

    if (gSioWork.unk_01 == 4) {
        if (gSioWork.unk_0E == 0) {
            func_0800712C(b);
        }
        func_08007210(c);
    }

    r = gSioWork.playerId | (gSioWork.playerCount << 2);

    if (gSioWork.unk_00 == 8) {
        r |= 0x20;
    }
    t0 = gSioWork.unk_0C << 8;
    t1 = gSioWork.unk_11 << 9;
    t2 = gSioWork.unk_12 << 16;
    t3 = gSioWork.unk_13 << 17;
    t4 = gSioWork.unk_14 << 18;
    t5 = gSioWork.unk_15 << 20;

    if (gSioWork.unk_01 == 4) {
        v = r | 0x40 | t0 | t1 | t2 | t3 | t4 | t5;
    } else {
        v = r | t0 | t1 | t2 | t3 | t4 | t5;
    }
    w = v;

    if (gSioWork.playerId > 1) {
        w |= 0x400000;
    }
    return w;
}

void func_080070B4(void) {
    if (((*(vu32*)REG_ADDR_SIOCNT) & (SIO_MULTI_SI | SIO_MULTI_SD)) == SIO_MULTI_SD && gSioWork.playerId == 0) {
        gSioWork.unk_00 = 8;
    } else {
        gSioWork.unk_00 = 0;
    }
}

void func_080070DC(void) {
    if (gSioWork.unk_00 != 0) {
        REG_TM3CNT_L = 0xFF2D;
        REG_TM3CNT_H = (TIMER_INTR_ENABLE | TIMER_64CLK);
        gUnk_0203406E = REG_IME;
        REG_IME = 0;
        REG_IE |= INTR_FLAG_TIMER3;
        REG_IME = gUnk_0203406E;
    }
}

void func_0800712C(u16* p) {
    u8 idx;
    u8 i;

    gUnk_0203406E = REG_IME;
    REG_IME = 0;

    if (gSioWork.sendCount < 32) {
        idx = gSioWork.sendCount + gSioWork.sendReadIdx;
        if (idx > 31) {
            idx -= 32;
        }

        for (i = 0; i < 4; i++) {
            gUnk_02034076 |= *p;
            gSioWork.sendBuf[i][idx] = *p;
            *p = 0;
            p++;
        }
    } else {
        gSioWork.unk_14 |= 1;
    }

    if (gUnk_02034076 != 0) {
        gSioWork.sendCount++;
        gUnk_02034076 = 0;
    }
    REG_IME = gUnk_0203406E;
    gUnk_020397D0 = gSioWork.sendCount;
}

void func_08007210(u16 (*c)[2]) {
    u8 i;
    u8 j;

    gUnk_0203406E = REG_IME;
    REG_IME = 0;

    if (gSioWork.recvCount == 0) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < gSioWork.playerCount; j++) {
                c[i][j] = 0;
            }
        }
        gSioWork.unk_0C = 1;
    } else {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < gSioWork.playerCount; j++) {
                c[i][j] = gSioWork.recvBuf[j][i][gSioWork.recvReadIdx];
            }
        }
        gSioWork.recvCount--;
        gSioWork.recvReadIdx++;
        if (gSioWork.recvReadIdx > 31) {
            gSioWork.recvReadIdx = 0;
        }
        gSioWork.unk_0C = 0;
    }
    REG_IME = gUnk_0203406E;
}

void func_08007318(void) {
    if (gSioWork.unk_0E != 0) {
        gUnk_02034072--;
        if (gUnk_02034072 != 0) {
            return;
        }
        gSioWork.unk_0E = 0;
    }

    if (gSioWork.unk_00 != 0) {
        if (gSioWork.unk_01 == 2) {
            SioStartTransfer();
        } else if (gSioWork.unk_01 == 4) {
            if (gSioWork.unk_0D <= 4) {
                if (gSioWork.unk_12 != 0) {
                    SioStartTransfer();
                } else {
                    gSioWork.unk_15 = 1;
                }
            } else if (gSioWork.unk_15 == 0) {
                gSioWork.unk_0D = 0;
                SioStartTransfer();
            }
        }
    } else if (gSioWork.unk_01 == 4 || gSioWork.unk_01 == 2) {
        gUnk_02034070++;
        if (gUnk_02034070 > 6) {
            if (gSioWork.unk_01 == 4) {
                gSioWork.unk_15 = 2;
            }

            if (gSioWork.unk_01 == 2) {
                gSioWork.playerId = 0;
                gSioWork.playerCount = 0;
                gSioWork.unk_11 = 0;
            }
        }
    }
}

void SioTimer3Intr(void) {
    func_08007768();
    SioStartTransfer();
}

void SioSerialIntr(void) {
    u32 cnt;

    cnt = (*(vu32*)REG_ADDR_SIOCNT);
    gSioWork.playerId = (cnt << 26) >> 30;

    switch (gSioWork.unk_01) {
    case 4:
        if (cnt & SIO_ERROR) {
            gSioWork.unk_12 = 1;
        }
        func_08007550();
        func_08007694();
        func_08007798();
        break;
    case 2:
        if (func_08007454()) {
            if (gSioWork.unk_00 != 0) {
                gSioWork.unk_01 = 3;
                gSioWork.unk_0D = 4;
            } else {
                gSioWork.unk_01 = 4;
            }
        }
        break;
    }
    gSioWork.unk_0D++;
    gUnk_02034070 = 0;

    if (gSioWork.unk_0D == 4) {
        gUnk_02039800 = gSioWork.recvCount;
    }
}

void SioStartTransfer(void) {
    REG_SIOCNT |= SIO_START;
}

u8 func_08007454(void) {
    u8 count;
    u16 min;
    u8 i;

    count = 0;
    min = 0xFFFF;

    if (gSioWork.unk_10 == 1) {
        REG_SIOMLT_SEND = 0x8FFF;
    } else {
        REG_SIOMLT_SEND = 0xD5E0;
    }
    gSioWork.unk_10 = 0;
    *(u64*)gSioWork.recv = *(u64*)REG_ADDR_SIOMULTI0;

    for (i = 0; i < 2; i++) {
        if ((gSioWork.recv[i] & ~3) == 0xD5E0 || gSioWork.recv[i] == 0x8FFF) {
            count++;

            if (min > gSioWork.recv[i] && gSioWork.recv[i] != 0) {
                min = gSioWork.recv[i];
            }
        } else if (gSioWork.recv[i] == 0xFFFF) {
            if (i == gSioWork.playerId) {
                count = 0;
            }
        } else {
            count = 0;
            break;
        }
    }
    gSioWork.playerCount = count;
    if (gSioWork.playerCount == 2) {
        if (gSioWork.playerCount == gUnk_02034073 && gSioWork.recv[0] == 0x8FFF) {
            return 1;
        }

        if (gSioWork.playerCount == 2) {
            gSioWork.unk_11 = (min & 3) + 1;
        } else {
            gSioWork.unk_11 = 0;
        }
    } else {
        gSioWork.unk_11 = 0;
    }
    gUnk_02034073 = gSioWork.playerCount;
    return 0;
}

void func_08007550(void) {
    u16 buf[4];
    u8 i;
    u8 idx;

    *(u64*)buf = *(u64*)REG_ADDR_SIOMULTI0;

    if (gSioWork.unk_18 == 0) {
        for (i = 0; i < gSioWork.playerCount; i++) {
            if (gSioWork.unk_16 != buf[i] && gUnk_0203406C != 0) {
                gSioWork.unk_13 = 1;
            }
        }
        gSioWork.unk_16 = 0;
        gUnk_0203406C = 1;
    } else {
        idx = gSioWork.recvReadIdx + gSioWork.recvCount;
        if (idx > 31) {
            idx -= 32;
        }

        if (gSioWork.recvCount < 32) {
            for (i = 0; i < gSioWork.playerCount; i++) {
                gSioWork.unk_16 += buf[i];
                gUnk_02034078 |= buf[i];
                gSioWork.recvBuf[i][gSioWork.unk_19][idx] = buf[i];

                if (gSioWork.unk_18 == 1 && gSioWork.unk_0E == 0 && (buf[i] & 0x1000)) {
                    gSioWork.unk_0E = 1;
                    gUnk_02034072 = 5;
                }
            }
        } else {
            gSioWork.unk_14 |= 2;
        }
        gSioWork.unk_19++;
        if (gSioWork.unk_19 == 4 && gUnk_02034078 != 0) {
            gSioWork.recvCount++;
            gUnk_02034078 = 0;
        }
    }
}

void func_08007694(void) {
    if (gSioWork.unk_18 == 4) {
        REG_SIOMLT_SEND = gSioWork.unk_16;

        if (gUnk_02034071 == 0) {
            gSioWork.sendCount--;
            gSioWork.sendReadIdx++;
            if (gSioWork.sendReadIdx > 31) {
                gSioWork.sendReadIdx = 0;
            }
        } else {
            gUnk_02034071 = 0;
        }
    } else {
        if (gSioWork.unk_18 == 0 && gSioWork.sendCount == 0) {
            gUnk_02034071 = 1;
        }

        if (gUnk_02034071 != 0) {
            REG_SIOMLT_SEND = 0;
        } else {
            REG_SIOMLT_SEND = gSioWork.sendBuf[gSioWork.unk_18][gSioWork.sendReadIdx];
        }

        if (gSioWork.unk_0E == 0 && gSioWork.unk_18 == 0 && gSioWork.recvCount > 3) {
            REG_SIOMLT_SEND |= 0x1000;
        }
        gSioWork.unk_18++;
    }
}

void func_08007768(void) {
    if (gSioWork.unk_00 != 0) {
        REG_TM3CNT_H &= ~TIMER_ENABLE;
        REG_TM3CNT_L = 0xFF2D;
    }
}

void func_08007798(void) {
    if (gSioWork.unk_19 == 4) {
        gSioWork.unk_18 = 0;
        gSioWork.unk_19 = 0;
    } else if (gSioWork.unk_00 != 0) {
        REG_TM3CNT_H |= TIMER_ENABLE;
    }
}

void func_080077C4(void) {
    u8 i;
    u8 j;

    gSioWork.sendCount = 0;
    gSioWork.sendReadIdx = 0;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 32; j++) {
            gSioWork.sendBuf[i][j] = 0xEFFF;
        }
    }
}

void func_08007814(void) {
    u8 i;
    u8 j;
    u8 k;

    gSioWork.recvCount = 0;
    gSioWork.recvReadIdx = 0;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 32; k++) {
                gSioWork.recvBuf[i][j][k] = 0xEFFF;
            }
        }
    }
}

void SioClearRegs(void) {
    REG_RCNT = 0;
    REG_SIOCNT = 0;
    REG_SIODATA8 = 0;
    *(vu16*)REG_ADDR_SIODATA32 = 0;
    REG_SIOMLT_SEND = 0;
    REG_SIOMLT_RECV = 0;
    REG_SIOMULTI0 = 0;
    REG_SIOMULTI1 = 0;
    REG_SIOMULTI2 = 0;
    REG_SIOMULTI3 = 0;
}

void func_080078A4(void) {
    SioClearRegs();
    REG_IME = 0;
    ResetVBlankCallback();
    ResetSerialCallback();
    ResetTimer3Callback();
    REG_IE = (INTR_FLAG_VBLANK | INTR_FLAG_GAMEPAK);
    REG_DISPSTAT = DISPSTAT_VBLANK_INTR;
    REG_IME = 1;
    SioStop();
}

u8 func_080078E8(void) {
    if (gSioWork.unk_01 == 4) {
        return 1;
    }
    return 0;
}
