#include "macros.h"
#include "battle.h"

u16 gUnk_020348CC[2];
u16 gUnk_020348D0[2];
u16 gUnk_020348D4[2];
u16 gUnk_020348D8[2];
u16 gUnk_020348DC[2];
u16 gUnk_020348E0;
u16 gUnk_020348E2;
#ifndef VERSION_EU
u8 gUnk_020348E4[4];
#endif

void func_08010548(u16 keys, s32 i) {
    if (keys & 0x200) {
        gUnk_020348CC[i]++;
        gUnk_020348D4[i] = 0;

        if (gUnk_020348CC[i] > 32) {
            gUnk_020348CC[i] = 29;
        }
    } else {
        gUnk_020348CC[i] = 0;

        if (gUnk_020348D4[i] < 255) {
            gUnk_020348D4[i]++;
        }
    }

    if (keys & 0x100) {
        gUnk_020348D0[i]++;
        gUnk_020348D8[i] = 0;

        if (gUnk_020348D0[i] > 32) {
            gUnk_020348D0[i] = 29;
        }
    } else {
        gUnk_020348D0[i] = 0;

        if (gUnk_020348D8[i] < 255) {
            gUnk_020348D8[i]++;
        }
    }
}
s32 func_08010600(u16 a, u16 b, s32 i) {
    s32 ret = 0;

    func_08010548(a, i);

    if (gUnk_020348D4[i] == 2) {
        gUnk_020348DC[i] &= 0xFDFF;
    }
    if (gUnk_020348D8[i] == 2) {
        gUnk_020348DC[i] &= 0xFEFF;
    }

    if (((b & 0x200) && (a & 0x100)) || ((b & 0x100) && (a & 0x200))) {
        gUnk_020348DC[i] |= 0x300;
        ret = 0x300;
    }

    if (!(gUnk_020348DC[i] & 0x200)) {
        if (gUnk_020348CC[i] == 5 || gUnk_020348D4[i] == 1) {
            gUnk_020348DC[i] |= 0x200;
            ret = 0x200;
        }
    }

    if (!(gUnk_020348DC[i] & 0x100)) {
        if (gUnk_020348D0[i] == 5 || gUnk_020348D8[i] == 1) {
            gUnk_020348DC[i] |= 0x100;
            ret = 0x100;
        }
    }
    return ret;
}
void func_0801071C(void) {
    s32 a;
    s32 b;

    a = 0;
    CpuSet(&a, gBtlWork, 0x05000074);
    b = 0;
    CpuSet(&b, gUnk_02039B9C, 0x05000074);
    gBtlWork->unk_0A0 = 0;
    gBtlWork->unk_0FC = -0x10000;
    gBtlWork->unk_12C = 66;
    gBtlWork->unk_0B3 = 10;
    gBtlWork->unk_068 |= 0x4000;
    gUnk_020348CC[0] = 0;
    gUnk_020348D0[0] = 0;
    gUnk_020348D4[0] = 0;
    gUnk_020348D8[0] = 0;
    gUnk_020348CC[1] = 0;
    gUnk_020348D0[1] = 0;
    gUnk_020348D4[1] = 0;
    gUnk_020348D8[1] = 0;
    gUnk_020348DC[0] = 0;
    gUnk_020348DC[1] = 0;
    gUnk_020348E0 = 0;
    gUnk_020348E2 = 0;
}
void func_080107D4(void) {
    BtlWork* w;
    BtlObj* o;
    u16 held;
    u16 pressed;
    s32 res;
    u8 f;

    w = gUnk_02039B9C;

    if (gBtlWork->unk_068 & 0x1000) {
        held = SioKeyGetHeldB();
        pressed = SioKeyGetPressedB();
    } else {
        held = SioKeyGetHeldA();
        pressed = SioKeyGetPressedA();
    }

    if (gUnk_02039B9C->unk_068 & 0x10000000000000) {
        if (held & 1) {
            if (!(held & 0x300)) {
                func_0807E2F4();
            }
        }
    }

    if (gUnk_02039B9C->unk_068 & 0x1000000) {
        gUnk_020348E2 = 5;
        return;
    }

    if ((s16)gUnk_02039B9C->unk_1CC > 0) {
        if (--gUnk_02039B9C->unk_1CC == 0) {
            func_0807E260();
        }
        return;
    }

    if ((s16)gUnk_020348E2 > 0) {
        gUnk_020348E2--;
    }

    res = (u16)func_08010600(held, pressed, 1);

    switch (res) {
    case 0x200:
        func_0807E1F4();
        break;
    case 0x100:
        func_0807E200();
        break;
    }

    if (pressed & 4) {
        func_0807E260();
    }

    f = func_0807E29C();

    if (f != 0) {
        w->unk_0E2 = 0;
        w->unk_0E3 = 0;
    } else {
        if ((held & 0x200) && !(held & 0x100)) {
            if (w->unk_0E2 <= 254) {
                w->unk_0E2++;
            }
        } else {
            w->unk_0E2 = f;
        }

        if ((held & 0x100) && !(held & 0x200)) {
            if (w->unk_0E3 <= 254) {
                w->unk_0E3++;
            }
        } else {
            w->unk_0E3 = 0;
        }
    }

    if (w->unk_0E2 > 32) {
        func_0807E1F4();
    }

    if (w->unk_0E3 > 32) {
        func_0807E200();
    }
    o = w->unk_07C;

    if (o->unk_034 & 0x200) {
        return;
    }

    if (gBtlWork->unk_068 & 0x40) {
        return;
    }

    if (gBtlWork->unk_068 & 0x10000000) {
        return;
    }

    if (gBtlWork->unk_068 & 0x800000) {
        return;
    }

    if (o->unk_034 & 2) {
        return;
    }

    if (res == 0x300) {
        if (func_0807B3F8() > 2) {
            func_0807E224();
        } else {
            func_0807E218();
        }
    }

    if (pressed & 1) {
        func_0807E20C();

        if (func_08081838() == 3) {
            if (func_0807E34C() == 0) {
                gUnk_02039B9C->unk_1CC = 15;
            }
        }
    }
}

void func_08010A24(void) {
    BtlWork* w;
    BtlObj* o;
    u16 held;
    u16 pressed;
    s32 res;
    u8 f;

    w = gBtlWork;

    if (w->unk_068 & 0x1000) {
        held = SioKeyGetHeldA();
        pressed = SioKeyGetPressedA();
    } else {
        held = SioKeyGetHeldB();
        pressed = SioKeyGetPressedB();
    }

    if (gBtlWork->unk_068 & 0x10000000000000) {
        if (held & 1) {
            if (!(held & 0x300)) {
                func_080763F0();
            }
        }
    }

    if (gBtlWork->unk_068 & 0x1000000) {
        gUnk_020348E0 = 5;
        return;
    }

    if ((s16)gBtlWork->unk_1CC > 0) {
        if (--gBtlWork->unk_1CC == 0) {
            func_08076394();
        }
        return;
    }

    if ((s16)gUnk_020348E0 > 0) {
        gUnk_020348E0--;
    }

    res = (u16)func_08010600(held, pressed, 0);

    switch (res) {
    case 0x200:
        func_08076318();
        break;
    case 0x100:
        func_08076324();
        break;
    }

    if (pressed & 4) {
        func_08076394();
    }

    f = func_080763D0();

    if (f != 0) {
        w->unk_0E2 = 0;
        w->unk_0E3 = 0;
    } else {
        if ((held & 0x200) && !(held & 0x100)) {
            if (w->unk_0E2 <= 254) {
                w->unk_0E2++;
            }
        } else {
            w->unk_0E2 = f;
        }

        if ((held & 0x100) && !(held & 0x200)) {
            if (w->unk_0E3 <= 254) {
                w->unk_0E3++;
            }
        } else {
            w->unk_0E3 = 0;
        }
    }

    if (w->unk_0E2 > 32) {
        func_08076318();
    }

    if (w->unk_0E3 > 32) {
        func_08076324();
    }

    o = w->unk_07C;

    if (o->unk_034 & 0x200) {
        return;
    }

    if (gBtlWork->unk_068 & 0x20000000) {
        return;
    }

    if (gBtlWork->unk_068 & 0x8000000) {
        return;
    }

    if (gBtlWork->unk_068 & 0x800000) {
        return;
    }

    if (o->unk_034 & 2) {
        return;
    }

    if (res == 0x300) {
        if (func_0807B3E0() > 2) {
            func_08076348();
        } else {
            func_0807633C();
        }
    }

    if (pressed & 1) {
        func_08076330();

        if (func_0807B3C8() == 3) {
            if (func_0807643C() == 0) {
                gBtlWork->unk_1CC = 15;
            }
        }
    }
}

void func_08010C70(void) {
    gBtlWork->unk_0A0 = 1;

    if (!(gBtlWork->unk_068 & 0x800000)) {
        gBtlWork->unk_068 |= 0x20;
    }
    gBtlWork->unk_068 &= ~0x40;
    gBtlWork->unk_068 &= ~0x20000000;
}

void func_08010CC8(void) {
    BtlObj* player = gBtlWork->unk_07C;
    BtlObj* other = gUnk_02039B9C->unk_07C;
    s32 entered;
    s32 i;
    s32 busy;
    u8 rank;
    if (gBtlWork->unk_0F4 == 53 || gUnk_02039B9C->unk_0F4 == 53) {
        gBtlWork->unk_12C = 38;
    } else {
        gBtlWork->unk_12C = 66;
    }
    switch ((u32)gBtlWork->unk_0A0) {
    case 1:
    case 2:
        if (gBtlWork->unk_068 & 0x1000) {
            func_08010A24();
            func_080107D4();
        } else {
            func_080107D4();
            func_08010A24();
        }
        break;
    }
    TaskPoolUpdate(&gBtlWork->taskPools[1]);
    if (gBtlWork->unk_068 & 0x800000) {
        gBtlWork->unk_068 |= 0x400000;
        gBtlWork->unk_068 &= ~2ULL;
        gUnk_02039B9C->unk_068 &= ~2ULL;
        gBtlWork->unk_0A0 = 1;
        if (gBtlWork->unk_0A4 != 0) {
            gBtlWork->unk_068 &= ~0x40ULL;
            other->unk_034 |= 0x10000;
            func_08006290(2, 10, 4);
        } else {
            gBtlWork->unk_068 &= ~0x20000000ULL;
            player->unk_034 |= 0x10000;
            func_08006290(3, 10, 4);
        }
        func_08006494(16, 15);
        func_08019050(1, 256, gBtlWork->unk_010, gBtlWork->unk_014);
        gBtlWork->unk_0E4 = 0;
    }
    if (gBtlWork->unk_068 & 0x400) {
        entered = 1;
        gBtlWork->unk_068 &= ~0x400ULL;
        if (gBtlWork->unk_0A4 != 0) {
            gBtlWork->unk_068 |= 0x20000000;
            player->unk_034 |= 1;
        } else {
            gBtlWork->unk_068 |= 0x40;
            other->unk_034 |= 1;
        }
        gBtlWork->unk_0A0 = 2;
        gBtlWork->unk_0E4 = 0;
    } else {
        entered = 0;
    }
    if ((gBtlWork->unk_068 & 0x400000000000ULL) && gBtlWork->unk_0A0 != 4) {
        gBtlWork->unk_0A0 = 4;
        gBtlWork->unk_0E4 = 0;
    }
    switch ((u32)gBtlWork->unk_0A0) {
    case 1:
        break;
    case 0:
        if (gBtlWork->unk_0E4 == 0) {
            gBtlWork->unk_0E8 = 0;
            gBtlWork->unk_0E4 = 1;
        }
        if (func_08006314()) return;
        if (gBtlWork->unk_0E4 == 1) {
            for (i = 0; i < 32; i++) {
                if (gBtlWork->unk_0FC & (s32)(1U << i)) func_080062F4(i, 1);
            }
            gBtlWork->unk_0E4 = 2;
        }
        if (IsTaskActive((Task*)gBtlWork->unk_0E8)) return;
        if (gBtlWork->unk_0E4 == 2) {
            TaskCreate(&gBtlWork->taskPools[0], &gTaskDescBtlVslockon, 0);
            TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBtlHpply, 0);
            TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBtlHpoth, 0);
            if (gBtlWork->unk_068 & 0x1000) {
                TaskCreate(&gBtlWork->taskPools[1], &gTaskDescCardBattleSora, 0);
                TaskCreate(&gBtlWork->taskPools[1], &gTaskDescCardBattleRiku, 0);
            } else {
                TaskCreate(&gBtlWork->taskPools[1], &gTaskDescCardBattleRiku, 0);
                TaskCreate(&gBtlWork->taskPools[1], &gTaskDescCardBattleSora, 0);
            }
            func_08076360();
            func_080838E8();
            gBtlWork->unk_0E4 = 3;
        } else if (gBtlWork->unk_0E4 == 3) {
            gBtlWork->unk_0A0 = 1;
            gBtlWork->unk_0E4 = 0;
        }
        break;
    case 4:
        if (gBtlWork->unk_0E4 == 0) {
            func_08076374();
            func_080838EC();
            gBtlWork->unk_068 |= 0x20;
            gUnk_02039B9C->unk_068 |= 0x40000000;
            gBtlWork->unk_068 |= 0x40000000;
            func_08019050(8, 256, gBtlWork->unk_010, gBtlWork->unk_014);
            gBtlWork->unk_0F4 = 0;
            gUnk_02039B9C->unk_0F4 = 0;
        }
        if (gBtlWork->unk_0E4 == 140) {
            func_08006184(1, 100);
            func_080063A8();
            gBtlWork->unk_068 |= 0x400000;
            gBtlWork->unk_072 = 100;
        } else if (gBtlWork->unk_0E4 > 140 && !func_08006314()) {
            m4aMPlayAllStop();
            if (player->unk_02C <= 0) ModeRequest(&gModeSioBtlCardget, 1);
            else ModeRequest(&gModeSioBtlCardget, 0);
            return;
        }
        gBtlWork->unk_0E4++;
        break;
    case 2:
        if (entered) return;
        busy = 0;
        if (player->unk_034 & 0x10) busy = 1;
        if (other->unk_034 & 0x10) busy = 1;
        if (busy) return;
        rank = func_080ABED0();
        gBtlWork->unk_0E4 = 0;
        if (gBtlWork->unk_068 & 0x20000000) {
            if (gBtlWork->unk_0B2 >= (s8)rank) gBtlWork->unk_068 &= ~2ULL;
            if (gBtlWork->unk_068 & 2) player->unk_034 |= 1;
            else func_08010C70();
        } else {
            if (gUnk_02039B9C->unk_0B2 >= (s8)rank) gUnk_02039B9C->unk_068 &= ~2ULL;
            if (gUnk_02039B9C->unk_068 & 2) other->unk_034 |= 1;
            else func_08010C70();
        }
        break;
    }
}
