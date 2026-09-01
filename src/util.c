#include "util.h"
#include "m4a.h"

extern u8 gUnk_0812171C[];

void func_08000AE4(void* name);
void* IwramAlloc(u32 size);
void IwramFree(void* p);

u16 func_0800833C(KeyState* k) {
    return k->held;
}

u16 func_08008340(KeyState* k) {
    return k->trg;
}

u16 func_08008344(KeyState* k) {
    return k->rep;
}

void func_08008348(KeyState* k) {
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

u8 func_08008384(KeyState* k, u16 key) {
    switch (key) {
    case 0x20:
        return k->on[0];
    case 0x10:
        return k->on[1];
    case 0x40:
        return k->on[2];
    case 0x80:
        return k->on[3];
    case 0x200:
        return k->on[6];
    case 0x100:
        return k->on[7];
    case 0x1:
        return k->on[4];
    case 0x2:
        return k->on[5];
    case 0x8:
        return k->on[8];
    case 0x4:
        return k->on[9];
    }
}

u8 func_080083F8(KeyState* k, u16 key) {
    switch (key) {
    case 0x20:
        return k->off[0];
    case 0x10:
        return k->off[1];
    case 0x40:
        return k->off[2];
    case 0x80:
        return k->off[3];
    case 0x200:
        return k->off[6];
    case 0x100:
        return k->off[7];
    case 0x1:
        return k->off[4];
    case 0x2:
        return k->off[5];
    case 0x8:
        return k->off[8];
    case 0x4:
        return k->off[9];
    }
}

u16 func_0800846C(KeyState* k, u16 a, u16 b) {
    u16 r = 0;
    u8 ca = func_080083F8(k, a);
    u8 cb = func_080083F8(k, b);

    if (ca == 2) {
        k->unk_6 &= ~a;
    }
    if (cb == 2) {
        k->unk_6 &= ~b;
    }
    if (((func_08008340(k) & a) && (func_0800833C(k) & b)) ||
        ((func_08008340(k) & b) && (func_0800833C(k) & a))) {
        k->unk_6 |= a | b;
        r = a | b;
    }
    if (!(k->unk_6 & a)) {
        if (func_08008384(k, a) == 5 || ca == 1) {
            k->unk_6 |= a;
            r = a;
        }
    }
    if (!(k->unk_6 & b)) {
        if (func_08008384(k, b) == 5 || cb == 1) {
            k->unk_6 |= b;
            r = b;
        }
    }
    return r;
}

void func_08008558(KeyState* k, u16 keys) {
    k->trg = keys & ~k->held;
    k->held = keys;
    if (k->held & 0x20) {
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
    if (k->held & 0x10) {
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
    if (k->held & 0x40) {
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
    if (k->held & 0x80) {
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
    if (k->held & 0x200) {
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
    if (k->held & 0x100) {
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
    if (k->held & 0x1) {
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
    if (k->held & 0x2) {
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
    if (k->held & 0x8) {
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
    if (k->held & 0x4) {
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
        k->rep |= 0x20;
    }
    if (k->on[1] == 1 || k->on[1] == 32) {
        k->rep |= 0x10;
    }
    if (k->on[2] == 1 || k->on[2] == 32) {
        k->rep |= 0x40;
    }
    if (k->on[3] == 1 || k->on[3] == 32) {
        k->rep |= 0x80;
    }
    if (k->on[6] == 1 || k->on[6] == 32) {
        k->rep |= 0x200;
    }
    if (k->on[7] == 1 || k->on[7] == 32) {
        k->rep |= 0x100;
    }
    if (k->on[4] == 1 || k->on[4] == 32) {
        k->rep |= 0x1;
    }
    if (k->on[5] == 1 || k->on[5] == 32) {
        k->rep |= 0x2;
    }
    if (k->on[8] == 1 || k->on[8] == 32) {
        k->rep |= 0x8;
    }
    if (k->on[9] == 1 || k->on[9] == 32) {
        k->rep |= 0x4;
    }
}

void func_08008808(void) {
    func_08000AE4(gUnk_0812171C);
    gUnk_0203407C = IwramAlloc(sizeof(KeyState));
    gUnk_02034080 = IwramAlloc(sizeof(KeyState));
    func_08008348(gUnk_0203407C);
    func_08008348(gUnk_02034080);
    gUnk_02034084 = 0;
}

void func_0800884C(void) {
    IwramFree(gUnk_02034080);
    IwramFree(gUnk_0203407C);
}

u16 func_0800886C(void) {
    return func_0800833C(gUnk_0203407C);
}

u16 func_08008884(void) {
    return func_0800833C(gUnk_02034080);
}

u16 func_0800889C(void) {
    return func_08008340(gUnk_0203407C);
}

u16 func_080088B4(void) {
    return func_08008340(gUnk_02034080);
}

u16 func_080088CC(void) {
    return func_08008344(gUnk_0203407C);
}

u16 func_080088E4(void) {
    return func_08008344(gUnk_02034080);
}

u16 func_080088FC(u16 a, u16 b) {
    return func_0800846C(gUnk_0203407C, a, b);
}

u16 func_08008920(u16 a, u16 b) {
    return func_0800846C(gUnk_02034080, a, b);
}

void func_08008944(u16 keys) {
    func_08008558(gUnk_0203407C, keys);
}

void func_0800895C(u16 keys) {
    func_08008558(gUnk_02034080, keys);
}

s32 func_08008974(u16 songNum) {
    u8 idx = gSongTable[songNum].ms;
    SongHeader* header = gSongTable[songNum].header;
    MusicPlayerInfo* info = gMPlayTable[idx].info;
    s32 r = 0;

    if (header == info->songHeader) {
        r = (u16)info->status != 0;
    }
    return r;
}

void func_080089A8(u16 songNum) {
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
