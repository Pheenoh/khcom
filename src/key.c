#include "macros.h"
#include "intr.h"
#include "gba/syscall.h"
#include "malloc.h"
#include "main.h"
#include "gba/keys.h"
#include "key.h"

extern u8 sEwramHeapName[];
extern u8 sIwramHeapName[];

extern u32 gFrameCounter;
extern u32 gUnk_03006C68;
extern u16 gUnk_03006C78;
extern u32 gUnk_03006C10;
extern u32 gUnk_02039828;
extern u32 gUnk_02039820;
extern u16 gUnk_03006C00;

extern u16 gKeysRepeat;
extern u16 gUnk_02034006;
extern u8 gUnk_02034008;
extern u8 gUnk_02034009;
extern u8 gUnk_0203400A;
extern u8 gUnk_0203400B;
extern u8 gUnk_0203400C;
extern u8 gUnk_0203400D;
extern u8 gUnk_0203400E;
extern u8 gUnk_0203400F;
extern u8 gUnk_02034010;
extern u8 gUnk_02034011;
extern u8 gUnk_02034012;
extern u8 gUnk_02034013;
extern u8 gUnk_02034014;
extern u8 gUnk_02034015;
extern u8 gUnk_02034016;
extern u8 gUnk_02034017;
extern u8 gUnk_02034018;
extern u8 gUnk_02034019;
extern u8 gUnk_0203401A;
extern u8 gUnk_0203401B;

void InitSystem(void);
void func_080C55DC(void);
void func_08001100(void);

u16 GetKeysRepeat(void);
void func_080013A8(void);
u8 func_08001470(u16 key);
u8 func_08001534(u16 key);
u16 func_080015F8(u16 a, u16 b);
u16 func_080016EC(void);


u16 GetKeysHeld(void) {
    return gKeysHeld;
}

u16 GetKeysPressed(void) {
    return gKeysPressed;
}

u16 GetKeysRepeat(void) {
    return gKeysRepeat;
}

void func_080013A8(void) {
    gKeysHeld = 0;
    gKeysPressed = 0;
    gKeysRepeat = 0;
    gUnk_02034006 = 0;
    gUnk_02034008 = 0;
    gUnk_02034009 = 0;
    gUnk_0203400A = 0;
    gUnk_0203400B = 0;
    gUnk_0203400E = 0;
    gUnk_0203400F = 0;
    gUnk_0203400C = 0;
    gUnk_0203400D = 0;
    gUnk_02034010 = 0;
    gUnk_02034011 = 0;
    gUnk_02034012 = 0xFF;
    gUnk_02034013 = 0xFF;
    gUnk_02034014 = 0xFF;
    gUnk_02034015 = 0xFF;
    gUnk_02034018 = 0xFF;
    gUnk_02034019 = 0xFF;
    gUnk_02034016 = 0xFF;
    gUnk_02034017 = 0xFF;
    gUnk_0203401A = 0xFF;
    gUnk_0203401B = 0xFF;
}

u8 func_08001470(u16 key) {
    switch (key) {
    case DPAD_LEFT:
        return gUnk_02034008;
    case DPAD_RIGHT:
        return gUnk_02034009;
    case DPAD_UP:
        return gUnk_0203400A;
    case DPAD_DOWN:
        return gUnk_0203400B;
    case L_BUTTON:
        return gUnk_0203400E;
    case R_BUTTON:
        return gUnk_0203400F;
    case A_BUTTON:
        return gUnk_0203400C;
    case B_BUTTON:
        return gUnk_0203400D;
    case START_BUTTON:
        return gUnk_02034010;
    case SELECT_BUTTON:
        return gUnk_02034011;
    }
}

u8 func_08001534(u16 key) {
    switch (key) {
    case DPAD_LEFT:
        return gUnk_02034012;
    case DPAD_RIGHT:
        return gUnk_02034013;
    case DPAD_UP:
        return gUnk_02034014;
    case DPAD_DOWN:
        return gUnk_02034015;
    case L_BUTTON:
        return gUnk_02034018;
    case R_BUTTON:
        return gUnk_02034019;
    case A_BUTTON:
        return gUnk_02034016;
    case B_BUTTON:
        return gUnk_02034017;
    case START_BUTTON:
        return gUnk_0203401A;
    case SELECT_BUTTON:
        return gUnk_0203401B;
    }
}

u16 func_080015F8(u16 a, u16 b) {
    u16 r = 0;
    u8 va = func_08001534(a);
    u8 vb = func_08001534(b);

    if (va == 2) {
        gUnk_02034006 &= ~a;
    }
    if (vb == 2) {
        gUnk_02034006 &= ~b;
    }
    if (((GetKeysPressed() & a) && (GetKeysHeld() & b)) || ((GetKeysPressed() & b) && (GetKeysHeld() & a))) {
        gUnk_02034006 |= a | b;
        r = a | b;
    }
    if ((gUnk_02034006 & a) == 0) {
        if (func_08001470(a) == 5 || va == 1) {
            gUnk_02034006 |= a;
            r = a;
        }
    }
    if ((gUnk_02034006 & b) == 0) {
        if (func_08001470(b) == 5 || vb == 1) {
            gUnk_02034006 |= b;
            r = b;
        }
    }
    return r;
}

u16 func_080016EC(void) {
    u16 r = 0;
    u8 up = func_08001534(DPAD_UP);
    u8 down = func_08001534(DPAD_DOWN);
    u8 left = func_08001534(DPAD_LEFT);
    u8 right = func_08001534(DPAD_RIGHT);

    if (up == 2) {
        gUnk_02034006 &= ~DPAD_UP;
    }
    if (down == 2) {
        gUnk_02034006 &= ~DPAD_DOWN;
    }
    if (left == 2) {
        gUnk_02034006 &= ~DPAD_LEFT;
    }
    if (right == 2) {
        gUnk_02034006 &= ~DPAD_RIGHT;
    }
    if (((GetKeysPressed() & DPAD_UP) && (GetKeysHeld() & DPAD_LEFT)) || ((GetKeysPressed() & DPAD_LEFT) && (GetKeysHeld() & DPAD_UP))) {
        gUnk_02034006 |= (DPAD_UP | DPAD_LEFT);
        r = (DPAD_UP | DPAD_LEFT);
    }
    if (((GetKeysPressed() & DPAD_UP) && (GetKeysHeld() & DPAD_RIGHT)) || ((GetKeysPressed() & DPAD_RIGHT) && (GetKeysHeld() & DPAD_UP))) {
        gUnk_02034006 |= (DPAD_UP | DPAD_RIGHT);
        r = (DPAD_UP | DPAD_RIGHT);
    }
    if (((GetKeysPressed() & DPAD_DOWN) && (GetKeysHeld() & DPAD_LEFT)) || ((GetKeysPressed() & DPAD_LEFT) && (GetKeysHeld() & DPAD_DOWN))) {
        gUnk_02034006 |= (DPAD_DOWN | DPAD_LEFT);
        r = (DPAD_DOWN | DPAD_LEFT);
    }
    if (((GetKeysPressed() & DPAD_DOWN) && (GetKeysHeld() & DPAD_RIGHT)) || ((GetKeysPressed() & DPAD_RIGHT) && (GetKeysHeld() & DPAD_DOWN))) {
        gUnk_02034006 |= (DPAD_DOWN | DPAD_RIGHT);
        r = (DPAD_DOWN | DPAD_RIGHT);
    }
    if ((gUnk_02034006 & DPAD_UP) == 0) {
        if (func_08001470(DPAD_UP) == 10 || up == 1) {
            gUnk_02034006 |= DPAD_UP;
            r = DPAD_UP;
        }
    }
    if ((gUnk_02034006 & DPAD_DOWN) == 0) {
        if (func_08001470(DPAD_DOWN) == 10 || down == 1) {
            gUnk_02034006 |= DPAD_DOWN;
            r = DPAD_DOWN;
        }
    }
    if ((gUnk_02034006 & DPAD_LEFT) == 0) {
        if (func_08001470(DPAD_LEFT) == 10 || left == 1) {
            gUnk_02034006 |= DPAD_LEFT;
            r = DPAD_LEFT;
        }
    }
    if ((gUnk_02034006 & DPAD_RIGHT) == 0) {
        if (func_08001470(DPAD_RIGHT) == 10 || right == 1) {
            gUnk_02034006 |= DPAD_RIGHT;
            r = DPAD_RIGHT;
        }
    }
    return r;
}

void UpdateKeyState(void) {
    u16 keys;

    keys = *(vu16*)0x04000130 ^ KEYS_MASK;
    gKeysPressed = keys & ~gKeysHeld;
    gKeysHeld = keys;

    if (gKeysHeld & DPAD_LEFT) {
        gUnk_02034008++;
        gUnk_02034012 = 0;
        if (gUnk_02034008 > 32) {
            gUnk_02034008 = 29;
        }
    } else {
        gUnk_02034008 = 0;
        if (gUnk_02034012 < 255) {
            gUnk_02034012++;
        }
    }
    if (gKeysHeld & DPAD_RIGHT) {
        gUnk_02034009++;
        gUnk_02034013 = 0;
        if (gUnk_02034009 > 32) {
            gUnk_02034009 = 29;
        }
    } else {
        gUnk_02034009 = 0;
        if (gUnk_02034013 < 255) {
            gUnk_02034013++;
        }
    }
    if (gKeysHeld & DPAD_UP) {
        gUnk_0203400A++;
        gUnk_02034014 = 0;
        if (gUnk_0203400A > 32) {
            gUnk_0203400A = 29;
        }
    } else {
        gUnk_0203400A = 0;
        if (gUnk_02034014 < 255) {
            gUnk_02034014++;
        }
    }
    if (gKeysHeld & DPAD_DOWN) {
        gUnk_0203400B++;
        gUnk_02034015 = 0;
        if (gUnk_0203400B > 32) {
            gUnk_0203400B = 29;
        }
    } else {
        gUnk_0203400B = 0;
        if (gUnk_02034015 < 255) {
            gUnk_02034015++;
        }
    }
    if (gKeysHeld & L_BUTTON) {
        gUnk_0203400E++;
        gUnk_02034018 = 0;
        if (gUnk_0203400E > 32) {
            gUnk_0203400E = 29;
        }
    } else {
        gUnk_0203400E = 0;
        if (gUnk_02034018 < 255) {
            gUnk_02034018++;
        }
    }
    if (gKeysHeld & R_BUTTON) {
        gUnk_0203400F++;
        gUnk_02034019 = 0;
        if (gUnk_0203400F > 32) {
            gUnk_0203400F = 29;
        }
    } else {
        gUnk_0203400F = 0;
        if (gUnk_02034019 < 255) {
            gUnk_02034019++;
        }
    }
    if (gKeysHeld & A_BUTTON) {
        gUnk_0203400C++;
        gUnk_02034016 = 0;
        if (gUnk_0203400C > 32) {
            gUnk_0203400C = 29;
        }
    } else {
        gUnk_0203400C = 0;
        if (gUnk_02034016 < 255) {
            gUnk_02034016++;
        }
    }
    if (gKeysHeld & B_BUTTON) {
        gUnk_0203400D++;
        gUnk_02034017 = 0;
        if (gUnk_0203400D > 32) {
            gUnk_0203400D = 29;
        }
    } else {
        gUnk_0203400D = 0;
        if (gUnk_02034017 < 255) {
            gUnk_02034017++;
        }
    }
    if (gKeysHeld & START_BUTTON) {
        gUnk_02034010++;
        gUnk_0203401A = 0;
        if (gUnk_02034010 > 32) {
            gUnk_02034010 = 29;
        }
    } else {
        gUnk_02034010 = 0;
        if (gUnk_0203401A < 255) {
            gUnk_0203401A++;
        }
    }
    if (gKeysHeld & SELECT_BUTTON) {
        gUnk_02034011++;
        gUnk_0203401B = 0;
        if (gUnk_02034011 > 32) {
            gUnk_02034011 = 29;
        }
    } else {
        gUnk_02034011 = 0;
        if (gUnk_0203401B < 255) {
            gUnk_0203401B++;
        }
    }
    gKeysRepeat = 0;
    if (gUnk_02034008 == 1 || gUnk_02034008 == 32) {
        gKeysRepeat |= DPAD_LEFT;
    }
    if (gUnk_02034009 == 1 || gUnk_02034009 == 32) {
        gKeysRepeat |= DPAD_RIGHT;
    }
    if (gUnk_0203400A == 1 || gUnk_0203400A == 32) {
        gKeysRepeat |= DPAD_UP;
    }
    if (gUnk_0203400B == 1 || gUnk_0203400B == 32) {
        gKeysRepeat |= DPAD_DOWN;
    }
    if (gUnk_0203400E == 1 || gUnk_0203400E == 32) {
        gKeysRepeat |= L_BUTTON;
    }
    if (gUnk_0203400F == 1 || gUnk_0203400F == 32) {
        gKeysRepeat |= R_BUTTON;
    }
    if (gUnk_0203400C == 1 || gUnk_0203400C == 32) {
        gKeysRepeat |= A_BUTTON;
    }
    if (gUnk_0203400D == 1 || gUnk_0203400D == 32) {
        gKeysRepeat |= B_BUTTON;
    }
    if (gUnk_02034010 == 1 || gUnk_02034010 == 32) {
        gKeysRepeat |= START_BUTTON;
    }
    if (gUnk_02034011 == 1 || gUnk_02034011 == 32) {
        gKeysRepeat |= SELECT_BUTTON;
    }
}
