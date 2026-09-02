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
extern u32 gVBlankCounter;
extern u16 gSystemFlags;
extern u32 gUnk_03006C10;
extern u32 gSioPlayerId;
extern u32 gSioStatus;
extern u16 gFrameSyncFlags;

extern u16 gKeysRepeat;
extern u16 gUnk_02034006;
extern u8 gKeyHoldLeft;
extern u8 gKeyHoldRight;
extern u8 gKeyHoldUp;
extern u8 gKeyHoldDown;
extern u8 gKeyHoldA;
extern u8 gKeyHoldB;
extern u8 gKeyHoldL;
extern u8 gKeyHoldR;
extern u8 gKeyHoldStart;
extern u8 gKeyHoldSelect;
extern u8 gKeyReleaseLeft;
extern u8 gKeyReleaseRight;
extern u8 gKeyReleaseUp;
extern u8 gKeyReleaseDown;
extern u8 gKeyReleaseA;
extern u8 gKeyReleaseB;
extern u8 gKeyReleaseL;
extern u8 gKeyReleaseR;
extern u8 gKeyReleaseStart;
extern u8 gKeyReleaseSelect;

void func_080C55DC(void);
void ModeUpdate(void);

u16 GetKeysRepeat(void);
void ResetKeyState(void);
u8 GetKeyHoldTime(u16 key);
u8 GetKeyReleaseTime(u16 key);
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

void ResetKeyState(void) {
    gKeysHeld = 0;
    gKeysPressed = 0;
    gKeysRepeat = 0;
    gUnk_02034006 = 0;
    gKeyHoldLeft = 0;
    gKeyHoldRight = 0;
    gKeyHoldUp = 0;
    gKeyHoldDown = 0;
    gKeyHoldL = 0;
    gKeyHoldR = 0;
    gKeyHoldA = 0;
    gKeyHoldB = 0;
    gKeyHoldStart = 0;
    gKeyHoldSelect = 0;
    gKeyReleaseLeft = 0xFF;
    gKeyReleaseRight = 0xFF;
    gKeyReleaseUp = 0xFF;
    gKeyReleaseDown = 0xFF;
    gKeyReleaseL = 0xFF;
    gKeyReleaseR = 0xFF;
    gKeyReleaseA = 0xFF;
    gKeyReleaseB = 0xFF;
    gKeyReleaseStart = 0xFF;
    gKeyReleaseSelect = 0xFF;
}

u8 GetKeyHoldTime(u16 key) {
    switch (key) {
    case DPAD_LEFT:
        return gKeyHoldLeft;
    case DPAD_RIGHT:
        return gKeyHoldRight;
    case DPAD_UP:
        return gKeyHoldUp;
    case DPAD_DOWN:
        return gKeyHoldDown;
    case L_BUTTON:
        return gKeyHoldL;
    case R_BUTTON:
        return gKeyHoldR;
    case A_BUTTON:
        return gKeyHoldA;
    case B_BUTTON:
        return gKeyHoldB;
    case START_BUTTON:
        return gKeyHoldStart;
    case SELECT_BUTTON:
        return gKeyHoldSelect;
    }
}

u8 GetKeyReleaseTime(u16 key) {
    switch (key) {
    case DPAD_LEFT:
        return gKeyReleaseLeft;
    case DPAD_RIGHT:
        return gKeyReleaseRight;
    case DPAD_UP:
        return gKeyReleaseUp;
    case DPAD_DOWN:
        return gKeyReleaseDown;
    case L_BUTTON:
        return gKeyReleaseL;
    case R_BUTTON:
        return gKeyReleaseR;
    case A_BUTTON:
        return gKeyReleaseA;
    case B_BUTTON:
        return gKeyReleaseB;
    case START_BUTTON:
        return gKeyReleaseStart;
    case SELECT_BUTTON:
        return gKeyReleaseSelect;
    }
}

u16 func_080015F8(u16 a, u16 b) {
    u16 r = 0;
    u8 va = GetKeyReleaseTime(a);
    u8 vb = GetKeyReleaseTime(b);

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
        if (GetKeyHoldTime(a) == 5 || va == 1) {
            gUnk_02034006 |= a;
            r = a;
        }
    }

    if ((gUnk_02034006 & b) == 0) {
        if (GetKeyHoldTime(b) == 5 || vb == 1) {
            gUnk_02034006 |= b;
            r = b;
        }
    }

    return r;
}

u16 func_080016EC(void) {
    u16 r = 0;
    u8 up = GetKeyReleaseTime(DPAD_UP);
    u8 down = GetKeyReleaseTime(DPAD_DOWN);
    u8 left = GetKeyReleaseTime(DPAD_LEFT);
    u8 right = GetKeyReleaseTime(DPAD_RIGHT);

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
        if (GetKeyHoldTime(DPAD_UP) == 10 || up == 1) {
            gUnk_02034006 |= DPAD_UP;
            r = DPAD_UP;
        }
    }

    if ((gUnk_02034006 & DPAD_DOWN) == 0) {
        if (GetKeyHoldTime(DPAD_DOWN) == 10 || down == 1) {
            gUnk_02034006 |= DPAD_DOWN;
            r = DPAD_DOWN;
        }
    }

    if ((gUnk_02034006 & DPAD_LEFT) == 0) {
        if (GetKeyHoldTime(DPAD_LEFT) == 10 || left == 1) {
            gUnk_02034006 |= DPAD_LEFT;
            r = DPAD_LEFT;
        }
    }

    if ((gUnk_02034006 & DPAD_RIGHT) == 0) {
        if (GetKeyHoldTime(DPAD_RIGHT) == 10 || right == 1) {
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
        gKeyHoldLeft++;
        gKeyReleaseLeft = 0;

        if (gKeyHoldLeft > 32) {
            gKeyHoldLeft = 29;
        }
    } else {
        gKeyHoldLeft = 0;

        if (gKeyReleaseLeft < 255) {
            gKeyReleaseLeft++;
        }
    }

    if (gKeysHeld & DPAD_RIGHT) {
        gKeyHoldRight++;
        gKeyReleaseRight = 0;

        if (gKeyHoldRight > 32) {
            gKeyHoldRight = 29;
        }
    } else {
        gKeyHoldRight = 0;

        if (gKeyReleaseRight < 255) {
            gKeyReleaseRight++;
        }
    }

    if (gKeysHeld & DPAD_UP) {
        gKeyHoldUp++;
        gKeyReleaseUp = 0;

        if (gKeyHoldUp > 32) {
            gKeyHoldUp = 29;
        }
    } else {
        gKeyHoldUp = 0;

        if (gKeyReleaseUp < 255) {
            gKeyReleaseUp++;
        }
    }

    if (gKeysHeld & DPAD_DOWN) {
        gKeyHoldDown++;
        gKeyReleaseDown = 0;

        if (gKeyHoldDown > 32) {
            gKeyHoldDown = 29;
        }
    } else {
        gKeyHoldDown = 0;

        if (gKeyReleaseDown < 255) {
            gKeyReleaseDown++;
        }
    }

    if (gKeysHeld & L_BUTTON) {
        gKeyHoldL++;
        gKeyReleaseL = 0;

        if (gKeyHoldL > 32) {
            gKeyHoldL = 29;
        }
    } else {
        gKeyHoldL = 0;

        if (gKeyReleaseL < 255) {
            gKeyReleaseL++;
        }
    }

    if (gKeysHeld & R_BUTTON) {
        gKeyHoldR++;
        gKeyReleaseR = 0;

        if (gKeyHoldR > 32) {
            gKeyHoldR = 29;
        }
    } else {
        gKeyHoldR = 0;

        if (gKeyReleaseR < 255) {
            gKeyReleaseR++;
        }
    }

    if (gKeysHeld & A_BUTTON) {
        gKeyHoldA++;
        gKeyReleaseA = 0;

        if (gKeyHoldA > 32) {
            gKeyHoldA = 29;
        }
    } else {
        gKeyHoldA = 0;

        if (gKeyReleaseA < 255) {
            gKeyReleaseA++;
        }
    }

    if (gKeysHeld & B_BUTTON) {
        gKeyHoldB++;
        gKeyReleaseB = 0;

        if (gKeyHoldB > 32) {
            gKeyHoldB = 29;
        }
    } else {
        gKeyHoldB = 0;

        if (gKeyReleaseB < 255) {
            gKeyReleaseB++;
        }
    }

    if (gKeysHeld & START_BUTTON) {
        gKeyHoldStart++;
        gKeyReleaseStart = 0;

        if (gKeyHoldStart > 32) {
            gKeyHoldStart = 29;
        }
    } else {
        gKeyHoldStart = 0;

        if (gKeyReleaseStart < 255) {
            gKeyReleaseStart++;
        }
    }

    if (gKeysHeld & SELECT_BUTTON) {
        gKeyHoldSelect++;
        gKeyReleaseSelect = 0;

        if (gKeyHoldSelect > 32) {
            gKeyHoldSelect = 29;
        }
    } else {
        gKeyHoldSelect = 0;

        if (gKeyReleaseSelect < 255) {
            gKeyReleaseSelect++;
        }
    }

    gKeysRepeat = 0;

    if (gKeyHoldLeft == 1 || gKeyHoldLeft == 32) {
        gKeysRepeat |= DPAD_LEFT;
    }

    if (gKeyHoldRight == 1 || gKeyHoldRight == 32) {
        gKeysRepeat |= DPAD_RIGHT;
    }

    if (gKeyHoldUp == 1 || gKeyHoldUp == 32) {
        gKeysRepeat |= DPAD_UP;
    }

    if (gKeyHoldDown == 1 || gKeyHoldDown == 32) {
        gKeysRepeat |= DPAD_DOWN;
    }

    if (gKeyHoldL == 1 || gKeyHoldL == 32) {
        gKeysRepeat |= L_BUTTON;
    }

    if (gKeyHoldR == 1 || gKeyHoldR == 32) {
        gKeysRepeat |= R_BUTTON;
    }

    if (gKeyHoldA == 1 || gKeyHoldA == 32) {
        gKeysRepeat |= A_BUTTON;
    }

    if (gKeyHoldB == 1 || gKeyHoldB == 32) {
        gKeysRepeat |= B_BUTTON;
    }

    if (gKeyHoldStart == 1 || gKeyHoldStart == 32) {
        gKeysRepeat |= START_BUTTON;
    }
    
    if (gKeyHoldSelect == 1 || gKeyHoldSelect == 32) {
        gKeysRepeat |= SELECT_BUTTON;
    }
}
