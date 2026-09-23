#include "util.h"
#include "malloc.h"
#include "m4a.h"

const u8 sSioKeyHeapName[8] = "SIOKEY";

KeyState* gSioKeyStateA;
KeyState* gSioKeyStateB;
u16 gUnk_02034084;

u16 KeyGetHeld(KeyState* k) {
    return k->held;
}

u16 KeyGetPressed(KeyState* k) {
    return k->trg;
}

u16 KeyGetRepeat(KeyState* k) {
    return k->rep;
}

void KeyStateClear(KeyState* k) {
    k->held = 0;
    k->trg = 0;
    k->rep = 0;
    k->unk_6 = 0;
    k->on[0] = 0;
    k->on[1] = 0;
    k->on[2] = 0;
    k->on[3] = 0;
    k->on[6] = 0;
    k->on[7] = 0;
    k->on[4] = 0;
    k->on[5] = 0;
    k->on[8] = 0;
    k->on[9] = 0;
    k->off[0] = -1;
    k->off[1] = -1;
    k->off[2] = -1;
    k->off[3] = -1;
    k->off[6] = -1;
    k->off[7] = -1;
    k->off[4] = -1;
    k->off[5] = -1;
    k->off[8] = -1;
    k->off[9] = -1;
}

u8 KeyGetHoldFrames(KeyState* k, u16 key) {
    switch (key) {
    case DPAD_LEFT:
        return k->on[0];
    case DPAD_RIGHT:
        return k->on[1];
    case DPAD_UP:
        return k->on[2];
    case DPAD_DOWN:
        return k->on[3];
    case L_BUTTON:
        return k->on[6];
    case R_BUTTON:
        return k->on[7];
    case A_BUTTON:
        return k->on[4];
    case B_BUTTON:
        return k->on[5];
    case START_BUTTON:
        return k->on[8];
    case SELECT_BUTTON:
        return k->on[9];
    }
}

u8 KeyGetOffFrames(KeyState* k, u16 key) {
    switch (key) {
    case DPAD_LEFT:
        return k->off[0];
    case DPAD_RIGHT:
        return k->off[1];
    case DPAD_UP:
        return k->off[2];
    case DPAD_DOWN:
        return k->off[3];
    case L_BUTTON:
        return k->off[6];
    case R_BUTTON:
        return k->off[7];
    case A_BUTTON:
        return k->off[4];
    case B_BUTTON:
        return k->off[5];
    case START_BUTTON:
        return k->off[8];
    case SELECT_BUTTON:
        return k->off[9];
    }
}

u16 KeyReadChord(KeyState* k, u16 a, u16 b) {
    u16 r = 0;
    u8 ca = KeyGetOffFrames(k, a);
    u8 cb = KeyGetOffFrames(k, b);

    if (ca == 2) {
        k->unk_6 &= ~a;
    }

    if (cb == 2) {
        k->unk_6 &= ~b;
    }

    if (((KeyGetPressed(k) & a) && (KeyGetHeld(k) & b)) ||
        ((KeyGetPressed(k) & b) && (KeyGetHeld(k) & a))) {
        k->unk_6 |= a | b;
        r = a | b;
    }

    if (!(k->unk_6 & a)) {
        if (KeyGetHoldFrames(k, a) == 5 || ca == 1) {
            k->unk_6 |= a;
            r = a;
        }
    }

    if (!(k->unk_6 & b)) {
        if (KeyGetHoldFrames(k, b) == 5 || cb == 1) {
            k->unk_6 |= b;
            r = b;
        }
    }
    return r;
}

void KeyStateUpdate(KeyState* k, u16 keys) {
    k->trg = keys & ~k->held;
    k->held = keys;
    if (k->held & DPAD_LEFT) {
        k->on[0]++;
        k->off[0] = 0;

        if (k->on[0] > 32) {
            k->on[0] = 29;
        }
    } else {
        k->on[0] = 0;

        if (k->off[0] < 255) {
            k->off[0]++;
        }
    }

    if (k->held & DPAD_RIGHT) {
        k->on[1]++;
        k->off[1] = 0;

        if (k->on[1] > 32) {
            k->on[1] = 29;
        }
    } else {
        k->on[1] = 0;

        if (k->off[1] < 255) {
            k->off[1]++;
        }
    }

    if (k->held & DPAD_UP) {
        k->on[2]++;
        k->off[2] = 0;

        if (k->on[2] > 32) {
            k->on[2] = 29;
        }
    } else {
        k->on[2] = 0;

        if (k->off[2] < 255) {
            k->off[2]++;
        }
    }

    if (k->held & DPAD_DOWN) {
        k->on[3]++;
        k->off[3] = 0;

        if (k->on[3] > 32) {
            k->on[3] = 29;
        }
    } else {
        k->on[3] = 0;

        if (k->off[3] < 255) {
            k->off[3]++;
        }
    }

    if (k->held & L_BUTTON) {
        k->on[6]++;
        k->off[6] = 0;

        if (k->on[6] > 32) {
            k->on[6] = 29;
        }
    } else {
        k->on[6] = 0;

        if (k->off[6] < 255) {
            k->off[6]++;
        }
    }

    if (k->held & R_BUTTON) {
        k->on[7]++;
        k->off[7] = 0;

        if (k->on[7] > 32) {
            k->on[7] = 29;
        }
    } else {
        k->on[7] = 0;

        if (k->off[7] < 255) {
            k->off[7]++;
        }
    }

    if (k->held & A_BUTTON) {
        k->on[4]++;
        k->off[4] = 0;

        if (k->on[4] > 32) {
            k->on[4] = 29;
        }
    } else {
        k->on[4] = 0;

        if (k->off[4] < 255) {
            k->off[4]++;
        }
    }

    if (k->held & B_BUTTON) {
        k->on[5]++;
        k->off[5] = 0;

        if (k->on[5] > 32) {
            k->on[5] = 29;
        }
    } else {
        k->on[5] = 0;

        if (k->off[5] < 255) {
            k->off[5]++;
        }
    }

    if (k->held & START_BUTTON) {
        k->on[8]++;
        k->off[8] = 0;

        if (k->on[8] > 32) {
            k->on[8] = 29;
        }
    } else {
        k->on[8] = 0;

        if (k->off[8] < 255) {
            k->off[8]++;
        }
    }

    if (k->held & SELECT_BUTTON) {
        k->on[9]++;
        k->off[9] = 0;

        if (k->on[9] > 32) {
            k->on[9] = 29;
        }
    } else {
        k->on[9] = 0;

        if (k->off[9] < 255) {
            k->off[9]++;
        }
    }
    k->rep = 0;

    if (k->on[0] == 1 || k->on[0] == 32) {
        k->rep |= DPAD_LEFT;
    }

    if (k->on[1] == 1 || k->on[1] == 32) {
        k->rep |= DPAD_RIGHT;
    }

    if (k->on[2] == 1 || k->on[2] == 32) {
        k->rep |= DPAD_UP;
    }

    if (k->on[3] == 1 || k->on[3] == 32) {
        k->rep |= DPAD_DOWN;
    }

    if (k->on[6] == 1 || k->on[6] == 32) {
        k->rep |= L_BUTTON;
    }

    if (k->on[7] == 1 || k->on[7] == 32) {
        k->rep |= R_BUTTON;
    }

    if (k->on[4] == 1 || k->on[4] == 32) {
        k->rep |= A_BUTTON;
    }

    if (k->on[5] == 1 || k->on[5] == 32) {
        k->rep |= B_BUTTON;
    }

    if (k->on[8] == 1 || k->on[8] == 32) {
        k->rep |= START_BUTTON;
    }

    if (k->on[9] == 1 || k->on[9] == 32) {
        k->rep |= SELECT_BUTTON;
    }
}

void SioKeyInit(void) {
    SetIwramHeapName(sSioKeyHeapName);
    gSioKeyStateA = IwramAlloc(sizeof(KeyState));
    gSioKeyStateB = IwramAlloc(sizeof(KeyState));
    KeyStateClear(gSioKeyStateA);
    KeyStateClear(gSioKeyStateB);
    gUnk_02034084 = 0;
}

void SioKeyFree(void) {
    IwramFree(gSioKeyStateB);
    IwramFree(gSioKeyStateA);
}

u16 SioKeyGetHeldA(void) {
    return KeyGetHeld(gSioKeyStateA);
}

u16 SioKeyGetHeldB(void) {
    return KeyGetHeld(gSioKeyStateB);
}

u16 SioKeyGetPressedA(void) {
    return KeyGetPressed(gSioKeyStateA);
}

u16 SioKeyGetPressedB(void) {
    return KeyGetPressed(gSioKeyStateB);
}

u16 SioKeyGetRepeatA(void) {
    return KeyGetRepeat(gSioKeyStateA);
}

u16 SioKeyGetRepeatB(void) {
    return KeyGetRepeat(gSioKeyStateB);
}

u16 SioKeyReadChordA(u16 a, u16 b) {
    return KeyReadChord(gSioKeyStateA, a, b);
}

u16 SioKeyReadChordB(u16 a, u16 b) {
    return KeyReadChord(gSioKeyStateB, a, b);
}

void SioKeyStateUpdateA(u16 keys) {
    KeyStateUpdate(gSioKeyStateA, keys);
}

void SioKeyStateUpdateB(u16 keys) {
    KeyStateUpdate(gSioKeyStateB, keys);
}

u8 IsSongPlaying(u16 songNum) {
    u8 idx = gSongTable[songNum].ms;
    SongHeader* header = gSongTable[songNum].header;
    MusicPlayerInfo* info = gMPlayTable[idx].info;
    s32 r = 0;

    if (header == info->songHeader) {
        r = (u16)info->status != 0;
    }
    return r;
}

void StopSong(u16 songNum) {
    u8 idx = gSongTable[songNum].ms;
    SongHeader* header = gSongTable[songNum].header;
    MusicPlayerInfo* info = gMPlayTable[idx].info;

    if (header == info->songHeader) {
        if (info->status & MUSICPLAYER_STATUS_TRACK) {
            info->status = MUSICPLAYER_STATUS_PAUSE;
            info->songHeader = 0;
        }
    }
}
