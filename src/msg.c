#include "map_api.h"
#include "msg_api.h"
#include "intr.h"
#include "m4a_song.h"
#include "obj_api.h"
#include "pallet.h"
#include "display.h"
#include "text.h"
#include "macros.h"
#include "anim.h"
#include "msg.h"

#ifdef VERSION_EU
extern void* gUnkEu_08890E1C[];
extern void* gUnkEu_08890E44[];
extern u8 gUnkEu_0919B63A[];
extern void* gUnkEu_09F5D7E4[];
extern u8 gUnkEu_095A3D74[];
u8 eu_0806C734(EventSeqWork* work);
u8 eu_0806C7C8(EventSeqWork* work);
u8 eu_0806C848(EventSeqWork* work);
u8 eu_0806C974(EventSeqWork* work);
extern u32 gLanguage;
#define LANGSTR(x) (((void**)(x))[gLanguage])
#else
#define LANGSTR(x) (x)
#endif

static Ent02034A80* gUnk_02034A80;
static Ent080658B8* gUnk_02034A84;
static Ent080658B8* gUnk_02034A88;
#ifndef VERSION_EU
static Ent02034A8C* gUnk_02034A8C;
#endif
static u8 gUnk_02034A90;
static u8 gUnk_02034A91;

struct UnkStruct_02039DD0* gUnk_02039DD0;

void func_0806180C(u16 a) {
    ModeRequest(gUnk_09EE274C, a);
}
#ifdef VERSION_EU
#define MSG_CODE(n) ((n) - 2)
#else
#define MSG_CODE(n) (n)
#endif

void func_08061824(void) {
    SetBackdropColor(0, 0, 0);

    switch (gUnk_02034A78 & 0x7FFF) {
    case 41:
    case 49:
    case MSG_CODE(176):
    case MSG_CODE(185):
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        m4aSongNumStart(106);
        func_080A4188(&gUnk_02034A60, 173);
        break;
    case 34:
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        m4aSongNumStart(106);
        func_080A4188(&gUnk_02034A60, 133);
        break;
    case 88:
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        m4aSongNumStart(106);
        func_080A4188(&gUnk_02034A60, 134);
        break;
    case MSG_CODE(136):
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        m4aSongNumStart(106);
        func_080A4188(&gUnk_02034A60, 139);
        break;
    case MSG_CODE(137):
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        m4aSongNumStart(106);
        func_080A4188(&gUnk_02034A60, 160);
        break;
    case MSG_CODE(139):
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        m4aSongNumStart(106);
        func_080A4188(&gUnk_02034A60, 159);
        break;
    case MSG_CODE(140):
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        m4aSongNumStart(106);
        func_080A4188(&gUnk_02034A60, 136);
        break;
    case MSG_CODE(141):
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        m4aSongNumStart(106);
        func_080A4188(&gUnk_02034A60, 137);
        break;
    case MSG_CODE(142):
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        m4aSongNumStart(106);
        func_080A4188(&gUnk_02034A60, 135);
        break;
    case 61:
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        m4aSongNumStart(106);
        func_080A4188(&gUnk_02034A60, 138);
        break;
    case 126:
        m4aSongNumStart(106);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        func_080A4188(&gUnk_02034A60, 162);
        break;
    case 114:
        m4aSongNumStart(106);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        func_080A4188(&gUnk_02034A60, 161);
        break;
    case 57:
        m4aSongNumStart(106);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        func_080A4188(&gUnk_02034A60, 163);
        break;
    case MSG_CODE(143):
    case MSG_CODE(144):
        m4aSongNumStart(106);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        func_080A4188(&gUnk_02034A60, 165);
        break;
    case MSG_CODE(145):
    case MSG_CODE(146):
    case MSG_CODE(147):
    case MSG_CODE(148):
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        func_080A4188(&gUnk_02034A60, 166);
        break;
    case 3:
    case 44:
    case 53:
    case 74:
    case 94:
    case 101:
    case 108:
    case 115:
    case 120:
    case MSG_CODE(129):
    case MSG_CODE(151):
    case MSG_CODE(177):
    case MSG_CODE(186):
    case MSG_CODE(192):
        m4aSongNumStart(106);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        func_080A4188(&gUnk_02034A60, 168);
        break;
    case 54:
    case 75:
    case 89:
    case 96:
    case 102:
    case 109:
    case 116:
    case 121:
    case MSG_CODE(130):
    case MSG_CODE(152):
    case MSG_CODE(188):
        m4aSongNumStart(106);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        func_080A4188(&gUnk_02034A60, 169);
        break;
    case 5:
        m4aSongNumStart(106);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        func_080A4188(&gUnk_02034A60, 175);
        break;
    case 6:
    case 80:
    case 90:
    case 97:
    case 103:
    case 111:
    case 117:
    case 123:
    case MSG_CODE(131):
    case MSG_CODE(153):
        m4aSongNumStart(106);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        func_080A4188(&gUnk_02034A60, 170);
        break;
    case 119:
        m4aSongNumStart(106);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        func_080A4188(&gUnk_02034A60, 172);
        break;
    case 60:
        m4aSongNumStart(106);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        func_080A4188(&gUnk_02034A60, 164);
        break;
    case 27:
    case MSG_CODE(156):
    case MSG_CODE(166):
        m4aSongNumStart(106);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        func_08006120(0, 1);
        func_080A4188(&gUnk_02034A60, 174);
        break;
    }
}
void func_08061FC8(void) {
    switch (gUnk_02034A78) {
    case 0:
        gGameState.unk_17C = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 94:
        gGameState.unk_17C = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 74:
        gGameState.unk_17C = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 88:
        gGameState.unk_17C = 19;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        func_0800FB2C(62);
        break;
    case 93:
        gGameState.unk_17C = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 107:
        gGameState.unk_17C = 7;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        func_0800FB2C(61);
        break;
    case 114:
        gGameState.unk_17C = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 103:
        gGameState.unk_17C = 11;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        func_0800FB2C(63);
        break;
    case 106:
        gGameState.unk_17C = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case MSG_CODE(131):
        gGameState.unk_17C = 67;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        func_0800FB2C(65);
        break;
    case MSG_CODE(133):
        gGameState.unk_17C = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 117:
        gGameState.unk_17C = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 116:
    case 118:
        gGameState.unk_17C = 35;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        func_0800FB2C(64);
        break;
    case 119:
        gGameState.unk_17C = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 120:
        gGameState.unk_17C = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 44:
        gGameState.unk_17C = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 59:
        gGameState.unk_17C = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 52:
    case MSG_CODE(149):
        gGameState.unk_17C = 0;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case MSG_CODE(155):
        gGameState.unk_17C = 128;
        func_0800FB2C(69);
        break;
    case MSG_CODE(174):
    case MSG_CODE(186):
        gGameState.unk_17C = 0;
        break;
    case MSG_CODE(185):
    case MSG_CODE(190):
        gGameState.unk_17C = 128;
        break;
    case MSG_CODE(156):
        gGameState.flags &= ~0x100;
        func_0800FB2C(66);
        func_0800FB2C(67);
        func_0800FB2C(68);
        break;
    }
}
void func_0806250C(void) {
    switch (gUnk_02034A78) {
    case 0:
        gGameState.unk_180 = 0x200;
        break;
    case 5:
        func_08084458(266);
        break;
    case 11:
        gGameState.unk_180 = 61;
        break;
    case 27:
        gGameState.unk_180 = 0x4C2;
        break;
    case 41:
        gGameState.unk_180 = 0x800;
        break;
    case 49:
        gGameState.unk_180 = 256;
        break;
    case 60:
        gGameState.unk_180 = 0x1000;
        func_08084458(136);
        break;
    case 57:
        func_08084458(124);
        break;
    case 3:
    case 44:
    case 53:
    case 61:
    case 74:
    case 88:
    case 94:
    case 101:
    case 108:
    case 115:
    case 120:
    case MSG_CODE(129):
    case MSG_CODE(151):
    case MSG_CODE(177):
    case MSG_CODE(186):
    case MSG_CODE(192):
        func_080938F8(221);
        break;
    case 4:
    case 54:
    case 75:
    case 89:
    case 96:
    case 102:
    case 109:
    case 116:
    case 121:
    case MSG_CODE(130):
    case MSG_CODE(152):
    case MSG_CODE(188):
        func_080938F8(231);
        break;
    case 6:
    case 80:
    case 90:
    case 97:
    case 103:
    case 111:
    case 117:
    case 123:
    case MSG_CODE(131):
    case MSG_CODE(153):
        func_080938F8(241);
        break;
    case 114:
        func_08084458(276);
        break;
    case 119:
        func_08084458(304);
        break;
    case 126:
        func_08084458(324);
        break;
    case MSG_CODE(137):
        func_08084458(64);
        break;
    case MSG_CODE(139):
        func_08084458(431);
        break;
    case MSG_CODE(143):
    case MSG_CODE(144):
        func_08084458(285);
        break;
    case MSG_CODE(149):
        gGameState.unk_180 = 128;
        break;
    case MSG_CODE(156):
        gGameState.unk_180 = 593;
        break;
    case MSG_CODE(166):
        gGameState.unk_180 = 46;
        break;
    case MSG_CODE(176):
        gGameState.unk_180 = 256;
        break;
    case MSG_CODE(185):
        gGameState.unk_180 = 0x800;
        break;
    case MSG_CODE(191):
        gGameState.unk_180 = 0x1000;
        break;
    }
}
void func_0806297C(void) {
    UnkStruct_09EE3FB4* m = gUnk_09EE3FB4[gUnk_02034A78];

    switch (gUnk_02034A78) {
    case 68:
        ModeRequest(gUnk_09EE274C, 69);
        break;
    case 83:
    case 84:
        gGameState.unk_00D = 5;
        ModeRequest(gModeBattle, m->unk_20);
        break;
    }
}
u8 func_080629CC(void) {
    switch (gUnk_02034A78) {
    case 0x44:
    case 0x53:
    case 0x54:
        func_080E04EC();
        return 1;
    }
    return 0;
}
void func_080629F8(void) {
    switch (gUnk_02034A78) {
    case 2:
        func_0800FC14(0);
        break;
    case MSG_CODE(136):
        func_0800FB2C(41);
        break;
    case MSG_CODE(140):
        func_0800FB2C(40);
        break;
    case MSG_CODE(141):
        func_0800FB2C(50);
        break;
    case MSG_CODE(142):
        func_0800FB2C(43);
        break;
    case 34:
        func_0800FB2C(38);
        break;
    case 88:
        func_0800FB2C(42);
        break;
    case 108:
        func_0800FC14(1);
        break;
    case 74:
        func_0800FC14(5);
        break;
    case 120:
        func_0800FC14(8);
        break;
    case 94:
        func_0800FC14(10);
        break;
    case 101:
        func_0800FC14(2);
        break;
    case 115:
        func_0800FC14(4);
        break;
    case MSG_CODE(129):
        func_0800FC14(11);
        break;
    case 87:
        func_0800FC14(3);
        break;
    case 59:
        func_0800FC14(13);
        break;
    case 61:
        func_0800FB2C(8);
        break;
    case 67:
        func_0800FC14(15);
        func_0800FC14(16);
        break;
    }
}
#ifdef VERSION_EU
#define MSG_SAVE_ID_LO 0x8D
#else
#define MSG_SAVE_ID_LO 0x8F
#endif

void func_08062CE4(void) {
    switch (gUnk_02034A78) {
    case MSG_SAVE_ID_LO + 0:
    case MSG_SAVE_ID_LO + 1:
    case MSG_SAVE_ID_LO + 2:
    case MSG_SAVE_ID_LO + 3:
    case MSG_SAVE_ID_LO + 4:
    case MSG_SAVE_ID_LO + 5:
        if (gGameState.flags & 0x10) {
            SaveWriteFileLarge(1);
        } else {
            SaveWriteFileLarge(0);
        }
        func_080DF828();
        break;
    }
}
void func_08062D20(void) {
    switch (gUnk_02034A78) {
    case MSG_SAVE_ID_LO + 0:
    case MSG_SAVE_ID_LO + 1:
    case MSG_SAVE_ID_LO + 2:
    case MSG_SAVE_ID_LO + 3:
    case MSG_SAVE_ID_LO + 4:
    case MSG_SAVE_ID_LO + 5:
        func_080DF828();
        break;
    }
}
void func_08062D3C(void) {
    switch (gUnk_02034A78) {
    case 0x43:
        func_0800FDD0(16);
        break;
    case 0x3F:
        func_0800FDD0(41);
        break;
    }
}
void func_08062D64(void) {
    u8 i;
    u8 j;

    gUnk_02034A80 = EwramAlloc(0xF78);
    gUnk_02034A90 = 0;

    for (i = 0; i < 45; i++) {
        gUnk_02034A80[i].unk_00 = 0;
        gUnk_02034A80[i].unk_04 = 0;
        gUnk_02034A80[i].unk_48 = 0;
        gUnk_02034A80[i].unk_50 = 0;

        for (j = 0; j < 16; j++) {
            gUnk_02034A80[i].unk_08[j] = 0;
        }
    }
}
void func_08062DC8(s32 x, s32 y, u8* s) {
    u8 i;
    u8 len;
    u8 idx;

    idx = 0;

    if (gUnk_02034A90 > 44) {
        return;
    }

    if (gUnk_02034A80 == NULL) {
        return;
    }

    gUnk_02034A80[gUnk_02034A90].unk_00 = x;
    gUnk_02034A80[gUnk_02034A90].unk_04 = y;
    gUnk_02034A80[gUnk_02034A90].unk_51 = 0;
    len = func_0809D280(s);

    if (len > 15) {
        len = 16;
    }
    gUnk_02034A80[gUnk_02034A90].unk_50 = len;

    for (i = 0; i < len; i++) {
        s16 c;

        gUnk_02034A80[gUnk_02034A90].unk_08[i] = (u32)func_080038C8(32);
        c = s[i];

        if ((u8)(c - 48) <= 9) {
            idx = c - 48;
        }

        if ((u8)(c - 65) <= 25) {
            idx = c - 55;
        }

        if (c == 47) {
            idx = 36;
        }

        if (c == 45) {
            idx = 37;
        }

        if (c == 95) {
            idx = 38;
        }

        if (c == 46) {
            idx = 39;
        }

        if (c == 43) {
            idx = 40;
        }

        if (c == 33) {
            idx = 41;
        }

        if (c == 63) {
            idx = 42;
        }

        if (c == 35) {
            idx = 43;
        }

        if (s[i] == 37) {
            idx = 44;
        }
        func_080038E4((void*)gUnk_02034A80[gUnk_02034A90].unk_08[i], gUnk_09EEC538[idx], gUnk_090D4180);
    }
    gUnk_02034A80[gUnk_02034A90].unk_48 = (u32)LoadObjPalette(gUnk_08F69BE4, 32);
    gUnk_02034A90++;
}
#ifndef VERSION_EU
void func_08062F18(s32 x, s32 y, u8* s) {
    u8 i;
    u8 len;
    u8 k;
    u8 idx;

    idx = 0;

    if (gUnk_02034A90 > 44) {
        return;
    }

    if (gUnk_02034A80 == NULL) {
        return;
    }

    gUnk_02034A80[gUnk_02034A90].unk_00 = x;
    gUnk_02034A80[gUnk_02034A90].unk_04 = y;
    gUnk_02034A80[gUnk_02034A90].unk_51 = 1;
    len = func_0809D280(s);

    if (len > 15) {
        len = 16;
    }
    gUnk_02034A80[gUnk_02034A90].unk_50 = len;

    for (i = 0, k = 0; i < len; i++) {
        s32 c = s[i];

        if ((u8)(c - 48) <= 9) {
            idx = c - 48;
        }

        if ((u8)(c - 65) <= 25) {
            idx = c - 52;
        }
        gUnk_02034A80[gUnk_02034A90].unk_08[k] = (u32)func_080038C8(128);
        func_080038E4((void*)gUnk_02034A80[gUnk_02034A90].unk_08[k], gUnk_09EEB204[idx], gUnk_090AB5B2);
        k++;
    }
    gUnk_02034A80[gUnk_02034A90].unk_48 = (u32)LoadObjPalette(&gUnk_096147B8[0x40], 32);
    gUnk_02034A90++;
}
#endif
void func_08063034(s32 x, s32 y, s32 n) {
    u8 buf[20];
    u8 i;

    if (n >= 0) {
        buf[0] = n / 10000000;
        buf[1] = n / 1000000 - buf[0] * 10;
        buf[2] = n / 100000 - buf[0] * 100 - buf[1] * 10;
        buf[3] = n / 10000 - buf[0] * 1000 - buf[1] * 100 - buf[2] * 10;
        buf[4] = n / 1000 - buf[0] * 10000 - buf[1] * 1000 - buf[2] * 100 - buf[3] * 10;
        buf[5] = n / 100 - buf[0] * 100000 - buf[1] * 10000 - buf[2] * 1000 - buf[3] * 100 - buf[4] * 10;
        buf[6] = n / 10 - buf[0] * 1000000 - buf[1] * 100000 - buf[2] * 10000 - buf[3] * 1000 - buf[4] * 100 - buf[5] * 10;
        buf[7] = n - (buf[0] * 10000000 + buf[1] * 1000000 + buf[2] * 100000 + buf[3] * 10000 + buf[4] * 1000 + buf[5] * 100 + buf[6] * 10);
        buf[0] += 0x30;
        buf[1] += 0x30;
        buf[2] += 0x30;
        buf[3] += 0x30;
        buf[4] += 0x30;
        buf[5] += 0x30;
        buf[6] += 0x30;
        buf[7] += 0x30;
        buf[8] = 0;
        for (i = 0; i <= 6; i++) {
            if (buf[i] > 0x30) {
                break;
            }
        }

        func_08062DC8(x, y, &buf[i]);
    } else {
        n = -n;
        buf[1] = n / 10000000;
        buf[2] = n / 1000000 - buf[1] * 10;
        buf[3] = n / 100000 - buf[1] * 100 - buf[2] * 10;
        buf[4] = n / 10000 - buf[1] * 1000 - buf[2] * 100 - buf[3] * 10;
        buf[5] = n / 1000 - buf[1] * 10000 - buf[2] * 1000 - buf[3] * 100 - buf[4] * 10;
        buf[6] = n / 100 - buf[1] * 100000 - buf[2] * 10000 - buf[3] * 1000 - buf[4] * 100 - buf[5] * 10;
        buf[7] = n / 10 - buf[1] * 1000000 - buf[2] * 100000 - buf[3] * 10000 - buf[4] * 1000 - buf[5] * 100 - buf[6] * 10;
        buf[8] = n - (buf[1] * 10000000 + buf[2] * 1000000 + buf[3] * 100000 + buf[4] * 10000 + buf[5] * 1000 + buf[6] * 100 + buf[7] * 10);
        buf[0] = 0x2D;
        buf[1] += 0x30;
        buf[2] += 0x30;
        buf[3] += 0x30;
        buf[4] += 0x30;
        buf[5] += 0x30;
        buf[6] += 0x30;
        buf[7] += 0x30;
        buf[8] += 0x30;
        buf[9] = 0;
        for (i = 1; i <= 7; i++) {
            if (buf[i] > 0x30) {
                break;
            }
        }

        buf[i - 1] = 0x2D;
        func_08062DC8(x, y, &buf[i - 1]);
    }
}
void func_080634C4(void) {
    s32 x;
    s32 y;
    s32 step;
    u8 i;
    u8 j;

    step = 8;

    for (i = 0; i < gUnk_02034A90; i++) {
        switch (gUnk_02034A80[i].unk_51) {
        case 0:
            step = 8;
            break;
        case 1:
            step = 10;
            break;
        }

        x = gUnk_02034A80[i].unk_00;
        y = gUnk_02034A80[i].unk_04;

        for (j = 0; j < gUnk_02034A80[i].unk_50; j++) {
            DrawSprite((x >> 8) + j * step, y >> 8, NULL, (void*)gUnk_02034A80[i].unk_08[j], (void*)gUnk_02034A80[i].unk_48, 0, 0, 50);
            ReleaseObjTiles((void*)gUnk_02034A80[i].unk_08[j]);
        }
        ReleaseObjPalette((u8*)gUnk_02034A80[i].unk_48);
    }
    gUnk_02034A90 = 0;
}

void func_080635C4(void) {
    u8 i;
    u8 j;

    for (i = 0; i < gUnk_02034A90; i++) {
        gUnk_02034A80[i].unk_00 = 0;
        gUnk_02034A80[i].unk_04 = 0;
        ReleaseObjPalette((u8*)gUnk_02034A80[i].unk_48);

        for (j = 0; j < gUnk_02034A80[i].unk_50; j++) {
            ReleaseObjTiles((void*)gUnk_02034A80[i].unk_08[j]);
        }
    }
    gUnk_02034A90 = 0;
}
void func_08063658(void) {
    func_080635C4();

    if (gUnk_02034A80 != NULL) {
        EwramFree(gUnk_02034A80);
    }
    gUnk_02034A80 = NULL;
}
#ifndef VERSION_EU
void* func_08063678(s32 a) {
    u8 i;
    u8 j;

    gUnk_02034A80 = EwramAlloc(0x840);
    gUnk_02034A90 = 0;

    for (i = 0; i < 24; i++) {
        gUnk_02034A80[i].unk_00 = 0;
        gUnk_02034A80[i].unk_04 = 0;
        gUnk_02034A80[i].unk_48 = 0;
        gUnk_02034A80[i].unk_50 = 0;
        gUnk_02034A80[i].unk_52 = 0;
        gUnk_02034A80[i].unk_53 = 0;

        for (j = 0; j < 16; j++) {
            gUnk_02034A80[i].unk_08[j] = 0;
        }

        switch (a) {
        case 0:
            gUnk_02034A80[i].unk_48 = (u32)LoadObjPalette(gUnk_09614718, 32);
            break;
        case 1:
            gUnk_02034A80[i].unk_48 = (u32)LoadObjPalette(gUnk_09614738, 32);
            break;
        case 2:
            gUnk_02034A80[i].unk_48 = (u32)LoadObjPalette(gUnk_09614758, 32);
            break;
        }
    }
    return (void*)gUnk_02034A80->unk_48;
}
#endif
#ifndef VERSION_EU
#ifndef VERSION_JP
void func_08063744(s32 x, s32 y, u16* s, u8 slot, u8 a) {
#else
void func_08063744(s32 x, s32 y, u8* s, u8 slot, u8 a) {
#endif
    u16 g;
    u16 lo;
    u8 kind;
    u8 i;
    u8 j;

    g = 0;
    i = 0;
    j = 0;

    if (slot > 23) {
        return;
    }

    if (gUnk_02034A80 == NULL) {
        return;
    }

    gUnk_02034A80[slot].unk_00 = x;
    gUnk_02034A80[slot].unk_04 = y;
    gUnk_02034A80[slot].unk_51 = 1;
    gUnk_02034A80[slot].unk_52 = 1;
    gUnk_02034A80[slot].unk_53 = i;
    gUnk_02034A80[slot].unk_54 = a;

    while (*s != 0) {
        u16 v;

        v = *(u16*)s;
        v = (v >> 8) | (v << 8);
        s += 2;

        switch (v & 0xFF00) {
        case 0x8100:
            v &= 0xFF;

            switch (v) {
            case 0x40:
                g = 0;
                break;
            case 0x41:
                g = 0xF5;
                break;
            case 0x42:
                g = 0xF6;
                break;
            case 0x45:
                g = 0xF9;
                break;
            case 0x48:
                g = 0xF1;
                break;
            case 0x49:
                g = 0xF0;
                break;
            case 0x5B:
                g = 0xFD;
                break;
            case 0x5C:
                g = 0xFC;
                break;
            case 0x60:
                g = 0xFE;
                break;
            case 0x63:
                g = 0xFB;
                break;
            case 0x75:
                g = 0xE8;
                break;
            case 0x76:
                g = 0xE9;
                break;
            case 0x77:
                g = 0xEA;
                break;
            case 0x78:
                g = 0xEB;
                break;
            case 0x69:
                g = 0xEC;
                break;
            case 0x6A:
                g = 0xED;
                break;
            case 0xA8:
                g = 0xE7;
                break;
            case 0xA9:
                g = 0xE6;
                break;
            }
            kind = 0;
            break;
        case 0x8200:
            lo = v & 0xFF;

            if (lo >= 0x60 && lo <= 0x79) {
                g = v + 0x7DAB;
            }

            if (lo >= 0x81 && lo <= 0x9A) {
                g = v + 0x7DA4;
            }

            if (lo >= 0x4F && lo <= 0x58) {
                g = v + 0x7DB2;
            }

            if (lo >= 0x9F && lo <= 0xF1) {
                g = v + 0x7DA0;
            }
            kind = 0;
            break;
        case 0x8300:
            lo = v & 0xFF;

            if (lo >= 0x40 && lo <= 0x7E) {
                g = v + 0x7D52;
            }

            if (lo >= 0x80 && lo <= 0x94) {
                g = v + 0x7D51;
            }
            kind = 0;
            break;
        case 0x8800:
            v &= 0xFF;

            if (v == 0xC5) {
                g = 9;
            }
            kind = 1;
            break;
        case 0x8900:
            switch (v & 0xFF) {
            case 0x9C:
                g = 4;
                break;
            case 0xA4:
                g = 0x31;
                break;
            case 0xAF:
                g = 0x1A;
                break;
            case 0xBD:
                g = 0x2F;
                break;
            }
            kind = 1;
            break;
        case 0x8A00:
            switch (v & 0xFF) {
            case 0x4F:
                g = 8;
                break;
            case 0x6D:
                g = 0x11;
                break;
            }
            kind = 1;
            break;
        case 0x8B00:
            switch (v & 0xFF) {
            case 0x41:
                g = 0x1E;
                break;
            case 0x43:
                g = 0x26;
                break;
            case 0x4C:
                g = 0x19;
                break;
            }
            kind = 1;
            break;
        case 0x8C00:
            switch (v & 0xFF) {
            case 0x4E:
                g = 6;
                break;
            case 0x78:
                g = 0x16;
                break;
            case 0xF5:
                g = 0x0B;
                break;
            case 0xAB:
                g = 0x37;
                break;
            case 0xA9:
                g = 0x0C;
                break;
            }
            kind = 1;
            break;
        case 0x8D00:
            switch (v & 0xFF) {
            case 0x73:
                g = 0x1F;
                break;
            case 0x90:
                g = 0x17;
                break;
            case 0xDF:
                g = 0x2E;
                break;
            }
            kind = 1;
            break;
        case 0x8E00:
            switch (v & 0xFF) {
            case 0xB8:
                g = 0x0D;
                break;
            case 0x76:
                g = 0x1C;
                break;
            case 0x84:
                g = 0x2C;
                break;
            case 0x9E:
                g = 0x1B;
                break;
            case 0xA1:
                g = 0x36;
                break;
            case 0xA9:
                g = 0x0F;
                break;
            case 0xD2:
                g = 0x15;
                break;
            case 0xD7:
                g = 0x12;
                break;
            }
            kind = 1;
            break;
        case 0x8F00:
            switch (v & 0xFF) {
            case 0x6F:
                g = 0x1D;
                break;
            case 0x8A:
                g = 0x21;
                break;
            case 0x97:
                g = 0x30;
                break;
            case 0xEA:
                g = 0x20;
                break;
            }
            kind = 1;
            break;
        case 0x9000:
            switch (v & 0xFF) {
            case 0x53:
                g = 3;
                break;
            case 0xD8:
                g = 1;
                break;
            case 0x6C:
                g = 0x2B;
                break;
            }
            kind = 1;
            break;
        case 0x9100:
            switch (v & 0xFF) {
            case 0xDE:
                g = 0x35;
                break;
            case 0xE5:
                g = 0;
                break;
            case 0x7A:
                g = 2;
                break;
            }
            kind = 1;
            break;
        case 0x9200:
            switch (v & 0xFF) {
            case 0x40:
                g = 0x27;
                break;
            case 0x42:
                g = 0x23;
                break;
            case 0x4E:
                g = 0x28;
                break;
            case 0x6D:
                g = 0x0E;
                break;
            case 0x86:
                g = 0x0A;
                break;
            }
            kind = 1;
            break;
        case 0x9300:
            v &= 0xFF;

            if (v == 0x90) {
                g = 45;
            }
            kind = 1;
            break;
        case 0x9400:
            switch (v & 0xFF) {
            case 0xDE:
                g = 0x29;
                break;
            case 0xC6:
                g = 0x2A;
                break;
            }
            kind = 1;
            break;
        case 0x9500:
            switch (v & 0xFF) {
            case 0x7C:
                g = 0x25;
                break;
            case 0xAA:
                g = 0x10;
                break;
            }
            kind = 1;
            break;
        case 0x9600:
            switch (v & 0xFF) {
            case 0x59:
                g = 5;
                break;
            case 0x6C:
                g = 0x24;
                break;
            case 0x82:
                g = 0x13;
                break;
            case 0xBD:
                g = 0x33;
                break;
            case 0xB0:
                g = 0x18;
                break;
            }
            kind = 1;
            break;
        case 0x9700:
            switch (v & 0xFF) {
            case 0x45:
                g = 0x14;
                break;
            case 0x46:
                g = 0x22;
                break;
            case 0x6C:
                g = 0x32;
                break;
            case 0x88:
                g = 0x38;
                break;
            case 0xDF:
                g = 0x34;
                break;
            case 0xE1:
                g = 7;
                break;
            }
            kind = 1;
            break;
        default:
            g = 0;
            kind = 0;
            break;
        }

        if (gUnk_02034A80[slot].unk_08[j] != 0) {
            ReleaseObjTiles((void*)gUnk_02034A80[slot].unk_08[j]);
        }
        g = ((u16*)gUnk_09EEB204[g])[3];

        switch (kind) {
        case 0:
            gUnk_02034A80[slot].unk_08[j] = (u32)LoadObjTiles(&gUnk_090AB5B2[g * 32], 128);
            break;
        case 1:
            gUnk_02034A80[slot].unk_08[j] = (u32)LoadObjTiles(&gUnk_090B3FBE[g * 32], 128);
            break;
        }
        j++;
        i++;
    }

    for (j = i; j < 16; j++) {
        if (gUnk_02034A80[slot].unk_08[j] != 0) {
            ReleaseObjTiles((void*)gUnk_02034A80[slot].unk_08[j]);
            gUnk_02034A80[slot].unk_08[j] = 0;
        }
    }
    gUnk_02034A80[slot].unk_50 = i;
}
#endif
#ifndef VERSION_EU
void func_08063EE4(s32 a, s32 b, u8 v, u8 d, u8 e) {
    u8 buf[4];

    buf[0] = 0x78;
    buf[1] = v / 10;
    buf[2] = v - buf[1] * 10;
    buf[3] = 0;
    buf[1] += 0x30;
    buf[2] += 0x30;
    func_08063F60(a, b, buf, d, e);
}
#endif
#ifndef VERSION_EU
void func_08063F60(s32 x, s32 y, u8* s, u8 slot, u8 a) {
    u8 i;
    u8 len;
    u8 j;
    s16 idx;
    u8 count;

    idx = 0;

    if (slot > 23) {
        return;
    }

    if (gUnk_02034A80 == NULL) {
        return;
    }

    gUnk_02034A80[slot].unk_00 = x;
    gUnk_02034A80[slot].unk_04 = y;
    gUnk_02034A80[slot].unk_51 = 2;
    gUnk_02034A80[slot].unk_52 = 1;
    gUnk_02034A80[slot].unk_54 = a;
    len = func_0809D280(s);

    if (len > 15) {
        len = 16;
    }

    i = 0;
    j = 0;
    count = len;

    for (; i < len; i++) {
        if ((u8)(s[i] - 48) <= 9) {
            idx = (u8)(s[i] + 209);
        }

        if ((u8)(s[i] - 65) <= 25) {
            idx = (u8)(s[i] + 202);
        }

        if ((u8)(s[i] - 97) <= 25) {
            idx = (u8)(s[i] + 196);
        }

        if (gUnk_02034A80[slot].unk_08[j] != 0) {
            ReleaseObjTiles((void*)gUnk_02034A80[slot].unk_08[j]);
        }
        idx = ((u8*)gUnk_09EEB204[idx])[6];
        gUnk_02034A80[slot].unk_08[j] = (u32)LoadObjTiles(&gUnk_090AB5B2[idx * 32], 128);
        j++;
    }

    len = count;

    for (j = len; j < 16; j++) {
        if (gUnk_02034A80[slot].unk_08[j] != 0) {
            ReleaseObjTiles((void*)gUnk_02034A80[slot].unk_08[j]);
            gUnk_02034A80[slot].unk_08[j] = 0;
        }
    }
    gUnk_02034A80[slot].unk_50 = len;
}
#endif
#ifndef VERSION_EU
void func_080640E0(void) {
    s32 x;
    s32 y;
    void* g;
    u8 i;
    u8 j;
    u8 dx;

    for (i = 0; i < 24; i++) {
        if (gUnk_02034A80[i].unk_52 != 1) {
            continue;
        }

        if (gUnk_02034A80[i].unk_54 == 0) {
            g = (void*)gUnk_02034A80[i].unk_48;
        } else {
            g = (void*)gUnk_02034A80[i].unk_4C;
        }
        x = gUnk_02034A80[i].unk_00;
        y = gUnk_02034A80[i].unk_04;
        dx = 0;

        for (j = 0; j < gUnk_02034A80[i].unk_50; j++) {
            DrawSprite((x >> 8) + dx, y >> 8, gUnk_09EEB204[0], (void*)gUnk_02034A80[i].unk_08[j], g, 0, 0, 50);

            if (gUnk_02034A80[i].unk_51 == 1) {
                dx += 10;
            } else if (gUnk_02034A80[i].unk_51 == 2) {
                dx += 10;
            }
        }
    }
}
#endif

#ifndef VERSION_EU
void func_080641CC(u8 i) {
    gUnk_02034A80[i].unk_52 = 0;
}
void func_080641E8(u8 i) {
    if (gUnk_02034A80[i].unk_50 != 0) {
        gUnk_02034A80[i].unk_52 = 1;
    }
}
void func_0806420C(void* a, void* b, u8 i) {
    gUnk_02034A80[i].unk_00 = a;
    gUnk_02034A80[i].unk_04 = b;
}
#endif
#ifndef VERSION_EU
void func_0806422C(void) {
    u8 i;
    u8 j;

    for (i = 0; i < 24; i++) {
        for (j = 0; j < 16; j++) {
            if (gUnk_02034A80[i].unk_08[j] != 0) {
                ReleaseObjTiles((void*)gUnk_02034A80[i].unk_08[j]);
            }
        }
        func_080062F4(((Handle0806180C*)gUnk_02034A80[i].unk_48)->unk_06, 0);
        ReleaseObjPalette((u8*)gUnk_02034A80[i].unk_48);
    }
    EwramFree(gUnk_02034A80);
    gUnk_02034A80 = NULL;
}
#endif
#ifndef VERSION_EU
void func_080642A8(u8 bg) {
    u8 i;
    u8 j;

    GetBgCharBase(bg);
    GetBgScreenBase(bg);
    gUnk_02034A8C = EwramAlloc(400);

    for (i = 0; i < 10; i++) {
        gUnk_02034A8C[i].unk_00 = 0;
        gUnk_02034A8C[i].unk_01 = 0;
        gUnk_02034A8C[i].unk_22 = 0;
        gUnk_02034A8C[i].unk_24 = bg;
        gUnk_02034A8C[i].unk_23 = 16;
        gUnk_02034A8C[i].unk_25 = 0;

        for (j = 0; j < 16; j++) {
            gUnk_02034A8C[i].unk_02[j] = 0;
        }
    }

    gUnk_02034A91 = 0;
}
#endif
#ifndef VERSION_EU
void func_08064338(u8 a, u8 b, u8 c, u8 d, u8 e, u8 f) {
    u8 buf[5];

    buf[1] = d / 10;
    buf[3] = d - buf[1] * 10;
    buf[0] = 0x82;
    buf[1] += 0x4F;
    buf[2] = 0x82;
    buf[3] += 0x4F;
    buf[4] = 0;
    func_080643D4(a, b, c, buf, e, f);
}
#endif
#ifndef VERSION_EU
void func_080643D4(u8 a, u8 b, u8 c, u8* s, u8 e, u8 f) {
    u32 off = 0x7DAB;
    u16 glyph;
    u8 i;
    u8 j;
    u16 w;
    u16 lo;

    glyph = 0;
    i = 0;
    j = 0;

    if (e > 23) {
        return;
    }

    if (gUnk_02034A8C == NULL) {
        return;
    }

    gUnk_02034A8C[e].unk_00 = a;
    gUnk_02034A8C[e].unk_01 = b;
    gUnk_02034A8C[e].unk_23 = c;
    gUnk_02034A8C[e].unk_25 = 1;
    gUnk_02034A8C[e].unk_26 = f;

    while (*s != 0) {
        w = *(u16*)s;
        w = (w >> 8) | (w << 8);
        s += 2;

        if (c > 8) {
            switch (w & 0xFF00) {
            case 0x8100:
                if ((w & 0xFF) > 0x5A) {
                    glyph = 0xFD;
                }

                if ((w & 0xFF) == 0x40) {
                    glyph = 0xFFFF;
                }
                break;
            case 0x8200:
                lo = w & 0xFF;

                if (lo >= 0x60 && lo <= 0x79) {
                    glyph = w + off;
                }

                if (lo >= 0x81 && lo <= 0x9A) {
                    glyph = w + 0x7DA4;
                }

                if (lo >= 0x4F && lo <= 0x58) {
                    glyph = w + 0x7DB2;
                }

                if (lo >= 0x9F && lo <= 0xF1) {
                    glyph = w + 0x7DA0;
                }
                break;
            case 0x8300:
                lo = w & 0xFF;

                if (lo >= 0x40 && lo <= 0x7E) {
                    glyph = w + 0x7D52;
                }

                if (lo >= 0x80 && lo <= 0x94) {
                    glyph = w + 0x7D51;
                }
                break;
            }
        } else {
            switch (w & 0xFF00) {
            case 0x8100:
                w &= 0xFF;

                if (w == 0x40) {
                    glyph = 0xFFFF;
                }
                break;
            case 0x8200:
                lo = w & 0xFF;

                if (lo >= 0x4F && lo <= 0x58) {
                    glyph = w + 0x7DC1;
                }

                if (lo >= 0x81 && lo <= 0x84) {
                    glyph = w + 0x7D99;
                }

                if (lo == 0x98) {
                    glyph = 15;
                }
                break;
            }
        }

        gUnk_02034A8C[e].unk_02[j] = glyph;
        j++;
        i++;
    }
    gUnk_02034A8C[e].unk_22 = i;

    if (gUnk_02034A91 == 0) {
        func_08004678(func_08064624);
        gUnk_02034A91 = 1;
    }
}
#endif
#ifndef VERSION_EU
#ifdef NON_MATCHING
void func_08064624(void) {
    u8* screen;
    u8 n;
    u8 k;
    u16* src;
    u8* dst;
    u8* p;
    u8 tx;
    u8 ty;
    u8 sx;
    u8 h;
    u16 glyph;
    u8 sy;
    u8 y;
    u8 yy;
    u8 pal;
    u32 cur;
    u32 pix;
    u16 tile;
    for (n = 0; n < 10; n++) {
        if (gUnk_02034A8C[n].unk_25 != 1) {
            continue;
        }
        gUnk_02034A8C[n].unk_25 = 0;

        for (k = 0; k < gUnk_02034A8C[n].unk_22; k++) {
            glyph = gUnk_02034A8C[n].unk_02[k];
            pal = gUnk_02034A8C[n].unk_26;
            h = gUnk_02034A8C[n].unk_23;

            if (h > 8) {
                tx = (k * 12 + gUnk_02034A8C[n].unk_00) >> 3;
                ty = gUnk_02034A8C[n].unk_01 >> 3;
                sx = k * 12 + gUnk_02034A8C[n].unk_00 - tx * 8;
                sy = gUnk_02034A8C[n].unk_01 - ty * 8;
                dst = (u8*)GetBgCharBase(gUnk_02034A8C[n].unk_24) + (tx + 1) * 32 + ty * 1024;
                screen = GetBgScreenBase(gUnk_02034A8C[n].unk_24);
                tile = ((u16*)gUnk_09EEB204[glyph])[3];
                src = (u16*)&gUnk_090AB5B2[tile * 32];
                p = dst;

                for (y = sy, yy = 0; y < sy + h; y++, yy += 2) {
                    if (glyph == 0xFFFF) {
                        pix = 0;
                        cur = 0;
                    } else {
                        s32 q;
                        cur = *(u32*)(p + (y & 7) * 4 + (u8)(y >> 3) * 1024);
                        q = yy & 15;
                        q += (yy >> 4) * 32;
                        pix = src[q] | ((u32)src[q + 1] << 16);
                    }
                    *(u32*)(p + (y & 7) * 4 + (u8)(y >> 3) * 1024) = cur | (pix << (sx * 4));

                    if (sx != 0) {
                        *(u32*)(p + (y & 7) * 4 + (u8)(y >> 3) * 1024 + 32) = pix >> (32 - sx * 4);
                    }
                }

                {
                    s32 t0;
                    s32 ty1;
                    s32 t1;
                    s32 tx2;
                    t0 = ty * 32;
                    *(u16*)(screen + tx * 2 + ty * 64) = (tx + 1 + t0) | (pal << 12);
                    ty1 = ty + 1;
                    t1 = ty1 * 32;
                    *(u16*)(screen + tx * 2 + ty1 * 64) = (tx + 1 + t1) | (pal << 12);

                    if (sy != 0) {
                        s32 r = ty + 2;
                        s32 t = r * 32;
                        *(u16*)(screen + tx * 2 + r * 64) = (tx + 1 + t) | (pal << 12);
                    }
                    tx2 = tx + 2;

                    if (sx != 0) {
                        *(u16*)(screen + tx * 2 + ty * 64 + 2) = (tx2 + t0) | (pal << 12);
                        *(u16*)(screen + tx * 2 + ty1 * 64 + 2) = (tx2 + t1) | (pal << 12);

                        if (sy != 0) {
                            s32 r = ty + 2;
                            s32 t = r * 32;
                            *(u16*)(screen + tx * 2 + r * 64 + 2) = (tx2 + t) | (pal << 12);
                        }
                    }
                }

                for (y = sy, yy = 0; y < sy + h; y++, yy += 2) {
                    if (glyph == 0xFFFF) {
                        cur = 0;
                        pix = 0;
                    } else {
                        cur = *(u32*)(p + (y & 7) * 4 + (u8)(y >> 3) * 1024 + 32);
                        pix = src[(yy & 15) + (yy >> 4) * 32 + 16] |
                              ((u32)src[(yy & 15) + (yy >> 4) * 32 + 17] << 16);
                    }
                    *(u32*)(p + (y & 7) * 4 + (u8)(y >> 3) * 1024 + 32) = cur | (pix << (sx * 4));

                    if (sy != 0) {
                        s32 r = ty + 2;
                        s32 t = r * 32;
                        *(u16*)(screen + tx * 2 + r * 64 + 2) = (tx + 2 + t) | (pal << 12);
                    }

                    if (sx != 0) {
                        *(u32*)(p + (y & 7) * 4 + (u8)(y >> 3) * 1024 + 64) = pix >> (32 - sx * 4);
                        *(u16*)(screen + tx * 2 + ty * 64 + 4) = (tx + 3 + ty * 32) | (pal << 12);
                        {
                            s32 ty1 = ty + 1;
                            s32 t1 = ty1 * 32;
                            *(u16*)(screen + tx * 2 + ty1 * 64 + 4) = (tx + 3 + t1) | (pal << 12);

                            if (sy != 0) {
                                s32 r = ty + 2;
                                *(u16*)(screen + tx * 2 + r * 64 + 4) = (tx + 3 + r * 32) | (pal << 12);
                            }
                        }
                    }
                }

                {
                    s32 tx2;
                    s32 t0;
                    s32 ty1;
                    s32 t1;
                    tx2 = tx + 2;
                    t0 = ty * 32;
                    *(u16*)(screen + tx * 2 + ty * 64 + 2) = (tx2 + t0) | (pal << 12);
                    ty1 = ty + 1;
                    t1 = ty1 * 32;
                    *(u16*)(screen + tx * 2 + ty1 * 64 + 2) = (tx2 + t1) | (pal << 12);

                    if (sx != 0) {
                        *(u16*)(screen + tx * 2 + ty * 64 + 4) = (tx + 3 + t0) | (pal << 12);
                        *(u16*)(screen + tx * 2 + ty1 * 64 + 4) = (tx + 3 + t1) | (pal << 12);

                        if (sy != 0) {
                            s32 r = ty + 2;
                            s32 t = r * 32;
                            *(u16*)(screen + tx * 2 + r * 64 + 4) = (tx + 3 + t) | (pal << 12);
                        }
                    }
                }
            } else {
                tx = (k * 8 + gUnk_02034A8C[n].unk_00) >> 3;
                ty = gUnk_02034A8C[n].unk_01 >> 3;
                sx = k * 8 + gUnk_02034A8C[n].unk_00 - tx * 8;
                sy = gUnk_02034A8C[n].unk_01 - ty * 8;
                dst = (u8*)GetBgCharBase(gUnk_02034A8C[n].unk_24) + (tx + 1) * 32 + ty * 1024;
                screen = GetBgScreenBase(gUnk_02034A8C[n].unk_24);
                tile = ((u16*)gUnk_09EEB188[glyph])[3];
                src = (u16*)&gUnk_090AA506[tile * 32];
                p = dst;

                for (y = sy, yy = 0; y < sy + h; y++, yy += 2) {
                    if (glyph == 0xFFFF) {
                        cur = 0;
                        pix = 0;
                    } else {
                        s32 q;
                        cur = *(u32*)(p + (y & 7) * 4 + (u8)(y >> 3) * 1024);
                        q = yy & 15;
                        q += (yy >> 4) * 32;
                        pix = src[q] | ((u32)src[q + 1] << 16);
                    }
                    *(u32*)(p + (y & 7) * 4 + (u8)(y >> 3) * 1024) = cur | (pix << (sx * 4));

                    if (sx != 0) {
                        *(u32*)(p + (y & 7) * 4 + (u8)(y >> 3) * 1024 + 32) = pix >> (32 - sx * 4);
                    }
                }

                {
                    s32 t0;
                    s32 ty1;
                    s32 t1;
                    t0 = ty * 32;
                    *(u16*)(screen + tx * 2 + ty * 64) = (tx + 1 + t0) | (pal << 12);
                    ty1 = ty + 1;
                    t1 = ty1 * 32;
                    *(u16*)(screen + tx * 2 + ty1 * 64) = (tx + 1 + t1) | (pal << 12);

                    if (sy != 0) {
                        s32 r = ty + 2;
                        s32 t = r * 32;
                        *(u16*)(screen + tx * 2 + r * 64) = (tx + 1 + t) | (pal << 12);
                    }

                    if (sx != 0) {
                        *(u16*)(screen + tx * 2 + ty * 64 + 2) = (tx + 2 + ty * 32) | (pal << 12);
                        *(u16*)(screen + tx * 2 + ty1 * 64 + 2) = (tx + 2 + ty1 * 32) | (pal << 12);

                        if (sy != 0) {
                            s32 r = ty + 2;
                            s32 t = r * 32;
                            *(u16*)(screen + tx * 2 + r * 64 + 2) = (tx + 2 + t) | (pal << 12);
                        }
                    }
                }
            }
        }
    }
    gUnk_02034A91 = 0;
}
#else
INCLUDE_ASM("msg/func_08064624.s");
#endif
#endif
#ifndef VERSION_EU
void func_08064B68(void) {
    EwramFree(gUnk_02034A8C);
    gUnk_02034A8C = NULL;
}
#endif
u16 func_08064B80(s32 a) {
    s32 i;

    gUnk_02034A84 = EwramAlloc(0xC00);

    for (i = 0; i < 128; i++) {
        gUnk_02034A84[i].unk_00 = 0;
        gUnk_02034A84[i].unk_04 = 0;
        gUnk_02034A84[i].unk_08 = NULL;
        gUnk_02034A84[i].unk_0C = NULL;
        gUnk_02034A84[i].unk_10 = NULL;
        gUnk_02034A84[i].unk_15 = 0;
        gUnk_02034A84[i].unk_14 = 0;

        switch (a) {
        case 0:
            gUnk_02034A84[i].unk_0C = LoadObjPalette(gUnk_09614758, 32);
            break;
        case 1:
            gUnk_02034A84[i].unk_0C = LoadObjPalette(gUnk_09614718, 32);
            break;
        case 2:
            gUnk_02034A84[i].unk_0C = LoadObjPalette(gUnk_09614738, 32);
            break;
        }

        func_080062F4(gUnk_02034A84[i].unk_0C->unk_06 + 16, 1);
    }

    gUnk_02034A90 = 0;
    return gUnk_02034A84->unk_0C->unk_06;
}
u16 func_08064C34(s32 a) {
    s32 i;

    gUnk_02034A84 = EwramAlloc(0xC00);

    for (i = 0; i < 128; i++) {
        gUnk_02034A84[i].unk_00 = 0;
        gUnk_02034A84[i].unk_04 = 0;
        gUnk_02034A84[i].unk_08 = NULL;
        gUnk_02034A84[i].unk_0C = NULL;
        gUnk_02034A84[i].unk_10 = NULL;
        gUnk_02034A84[i].unk_15 = 0;
        gUnk_02034A84[i].unk_14 = 0;

        switch (a) {
        case 0:
            gUnk_02034A84[i].unk_0C = LoadObjPalette(gUnk_09614758, 32);
            break;
        case 1:
            gUnk_02034A84[i].unk_0C = LoadObjPalette(gUnk_09614718, 32);
            break;
        case 2:
            gUnk_02034A84[i].unk_0C = LoadObjPalette(gUnk_09614738, 32);
            break;
        }

        gUnk_02034A84[i].unk_10 = _08066468(5);
        func_080062F4(gUnk_02034A84[i].unk_0C->unk_06 + 16, 1);
        func_080062F4(gUnk_02034A84[i].unk_10->unk_06 + 16, 1);
    }

    gUnk_02034A90 = 0;
    return gUnk_02034A84->unk_0C->unk_06;
}

u16 func_08064D04(s32 a) {
    s32 i;

    gUnk_02034A84 = EwramAlloc(0xC00);

    for (i = 0; i < 128; i++) {
        gUnk_02034A84[i].unk_00 = 0;
        gUnk_02034A84[i].unk_04 = 0;
        gUnk_02034A84[i].unk_08 = NULL;
        gUnk_02034A84[i].unk_0C = NULL;
        gUnk_02034A84[i].unk_10 = NULL;
        gUnk_02034A84[i].unk_15 = 0;
        gUnk_02034A84[i].unk_14 = 0;

        switch (a) {
        case 0:
            gUnk_02034A84[i].unk_0C = LoadObjPalette(gUnk_09614758, 32);
            break;
        case 1:
            gUnk_02034A84[i].unk_0C = LoadObjPalette(gUnk_09614718, 32);
            break;
        case 2:
            gUnk_02034A84[i].unk_0C = LoadObjPalette(gUnk_09614738, 32);
            break;
        }

        gUnk_02034A84[i].unk_10 = _08066468(3);
        func_080062F4(gUnk_02034A84[i].unk_0C->unk_06 + 16, 1);
        func_080062F4(gUnk_02034A84[i].unk_10->unk_06 + 16, 1);
    }

    gUnk_02034A90 = 0;
    return gUnk_02034A84->unk_0C->unk_06;
}

#ifdef VERSION_US
s32 func_08064DD4(u16* a) {
#else
s32 func_08064DD4(u8* a) {
#endif
    u16 sum;
    s32 v;

    sum = 0;

    while (*a != 0) {
        v = 0;

        if (*a != 10) {
#ifdef VERSION_US
            if ((u16)(*a - 32) <= 223) {
#else
            if (*a > 31) {
#endif
                v = *a;
            } else {
                switch (*a) {
                case 0xE000:
                    v = 25;
                    break;
                case 0x2191:
                    v = 10;
                    break;
                case 0x2193:
                    v = 11;
                    break;
                case 0x2190:
                    v = 12;
                    break;
                case 0x2192:
                    v = 13;
                    break;
                case 0x300C:
                    v = 1;
                    break;
                case 0x300D:
                    v = 2;
                    break;
                case 0x300E:
                    v = 3;
                    break;
                case 0x300F:
                    v = 4;
                    break;
                case 0x203B:
                    v = 6;
                    break;
                case 0x266A:
                    v = 18;
                    break;
                case 0x2642:
                    v = 8;
                    break;
                case 0x2640:
                    v = 9;
                    break;
                case 0x2605:
                    v = 21;
                    break;
                }
            }

            sum = (u16)(gUnk_08F7D438[v] + ((s32)(sum << 16) >> 16));
        }

        a++;
    }

    return (s16)sum;
}

#ifdef VERSION_EU
#define MSG_LATIN_CHAR(p) (*(u8*)(p))
#define MSG_LATIN_CODE(wide, byte) (byte)
#define MSG_LATIN_STEP 1
#else
#define MSG_LATIN_CHAR(p) (*(u16*)(p))
#define MSG_LATIN_CODE(wide, byte) (wide)
#define MSG_LATIN_STEP 2
#endif
u8 func_08064EF4(s32 x, s32 y, s32 s, s32* d) {
    s32 cx;
    s32 cy;
    s32 f;

    cx = 0;
    cy = 0;
    f = 0;

    if (gUnk_02034A84 == NULL) {
        return 0;
    }

    gUnk_02034A90 = 0;

    while (MSG_LATIN_CHAR(s) != 0) {
        s32 v = 0;

        gUnk_02034A84[gUnk_02034A90].unk_00 = x + cx;
        gUnk_02034A84[gUnk_02034A90].unk_04 = y + cy;
        gUnk_02034A84[gUnk_02034A90].unk_15 = 1;

        if (MSG_LATIN_CHAR(s) == MSG_LATIN_CODE(0x4079, 29)) {
            f = 1;
            s += MSG_LATIN_STEP;
        }

        if (MSG_LATIN_CHAR(s) == MSG_LATIN_CODE(0x4000, 30)) {
            f = 0;
            s += MSG_LATIN_STEP;
        }

        gUnk_02034A84[gUnk_02034A90].unk_14 = f;

        if (MSG_LATIN_CHAR(s) == MSG_LATIN_CODE(10, 31)) {
            cx = 0;
            cy += 0xC00;
        } else {
#ifdef VERSION_EU
            v = MSG_LATIN_CHAR(s);
#else
            if ((u16)(MSG_LATIN_CHAR(s) - 32) <= 223) {
                v = MSG_LATIN_CHAR(s);
            } else {
                switch (MSG_LATIN_CHAR(s)) {
                case 0xE000:
                    v = 25;
                    break;
                case 0x2191:
                    v = 10;
                    break;
                case 0x2193:
                    v = 11;
                    break;
                case 0x2190:
                    v = 12;
                    break;
                case 0x2192:
                    v = 13;
                    break;
                case 0x300C:
                    v = 1;
                    break;
                case 0x300D:
                    v = 2;
                    break;
                case 0x300E:
                    v = 3;
                    break;
                case 0x300F:
                    v = 4;
                    break;
                case 0x203B:
                    v = 6;
                    break;
                case 0x266A:
                    v = 18;
                    break;
                case 0x2642:
                    v = 8;
                    break;
                case 0x2640:
                    v = 9;
                    break;
                case 0x2605:
                    v = 21;
                    break;
                case 0x25A0:
                    v = 17;
                    break;
                }
            }

#endif
            if (gUnk_02034A84[gUnk_02034A90].unk_08 != NULL) {
                ReleaseObjTiles(gUnk_02034A84[gUnk_02034A90].unk_08);
                gUnk_02034A84[gUnk_02034A90].unk_08 = NULL;
            }

            cx += (s16)gUnk_08F7D438[v] << 8;

            if (v != 32) {
#ifdef VERSION_EU
                v = ((u16*)gUnk_09EEB204[v])[3];
                gUnk_02034A84[gUnk_02034A90].unk_08 = LoadObjTiles(&gUnkEu_0919B63A[v * 32], 128);
#else
                v = ((u16*)gUnk_09EEC134[v])[3];
                gUnk_02034A84[gUnk_02034A90].unk_08 = LoadObjTiles(&gUnk_090CBFB2[v * 32], 128);
#endif
            }

            gUnk_02034A90++;

            if (cx > 0x9B00) {
                cx = 0;
                cy += 0xC00;
            }
        }
        s += MSG_LATIN_STEP;

        if (cy > 0x1800) {
            *d = s;
            return gUnk_02034A90;
        }
    }

    *d = 0;
    return gUnk_02034A90;
}
#ifdef VERSION_EU
u8 func_08065170(s32 x, s32 y, u8* s) {
#else
u8 func_08065170(s32 x, s32 y, u16* s) {
#endif
    s32 cx;
    s32 cy;
    s32 f;

    cx = 0;
    cy = 0;
    f = 0;

    if (gUnk_02034A84 == NULL) {
        return 0;
    }

    gUnk_02034A90 = 0;

    while (*s != 0) {
        s32 v = 0;

        gUnk_02034A84[gUnk_02034A90].unk_00 = x + cx;
        gUnk_02034A84[gUnk_02034A90].unk_04 = y + cy;
        gUnk_02034A84[gUnk_02034A90].unk_15 = 1;

        if (*s == MSG_LATIN_CODE(0x4079, 29)) {
            f = 1;
            s++;
        }

        if (*s == MSG_LATIN_CODE(0x4000, 30)) {
            f = 0;
            s++;
        }

        gUnk_02034A84[gUnk_02034A90].unk_14 = f;

        if (*s == MSG_LATIN_CODE(10, 31)) {
            cx = 0;
            cy += 0xC00;
        } else {
#ifdef VERSION_EU
            v = *s;
#else
            if ((u16)(*s - 32) <= 223) {
                v = *s;
            } else {
                switch (*s) {
                case 0xE000:
                    v = 25;
                    break;
                case 0x2191:
                    v = 10;
                    break;
                case 0x2193:
                    v = 11;
                    break;
                case 0x2190:
                    v = 12;
                    break;
                case 0x2192:
                    v = 13;
                    break;
                case 0x300C:
                    v = 1;
                    break;
                case 0x300D:
                    v = 2;
                    break;
                case 0x300E:
                    v = 3;
                    break;
                case 0x300F:
                    v = 4;
                    break;
                case 0x203B:
                    v = 6;
                    break;
                case 0x266A:
                    v = 18;
                    break;
                case 0x2642:
                    v = 8;
                    break;
                case 0x2640:
                    v = 9;
                    break;
                case 0x2605:
                    v = 21;
                    break;
                case 0x25A0:
                    v = 17;
                    break;
                }
            }

#endif
            if (gUnk_02034A84[gUnk_02034A90].unk_08 != NULL) {
                ReleaseObjTiles(gUnk_02034A84[gUnk_02034A90].unk_08);
                gUnk_02034A84[gUnk_02034A90].unk_08 = NULL;
            }

            cx += (s16)gUnk_08F7D438[v] << 8;

            if (v != 32) {
#ifdef VERSION_EU
                v = ((u16*)gUnk_09EEB204[v])[3];
                gUnk_02034A84[gUnk_02034A90].unk_08 = LoadObjTiles(&gUnkEu_0919B63A[v * 32], 128);
#else
                v = ((u16*)gUnk_09EEC134[v])[3];
                gUnk_02034A84[gUnk_02034A90].unk_08 = LoadObjTiles(&gUnk_090CBFB2[v * 32], 128);
#endif
            }

            gUnk_02034A90++;

            if (cx > 0x9B00) {
                cx = 0;
                cy += 0xC00;
            }
        }
        s++;
    }
    return gUnk_02034A90;
}
#ifndef VERSION_EU
u8 func_080653D4(s32 x, s32 y, u8* s) {
    u16 w;
    u8 t;
    s32 cx;
    s32 cy;
    s32 px;

    w = 0;
    t = 0;
    cx = 0;
    cy = 0;
    px = 0;

    if (gUnk_02034A84 == NULL) {
        return 0;
    }

    gUnk_02034A90 = 0;

    while (*s != 0) {
        u16 v;

        w = 0;
        gUnk_02034A84[gUnk_02034A90].unk_00 = x + cx;
        do {
            gUnk_02034A84[gUnk_02034A90].unk_04 = y + cy;
        } while (0);
        gUnk_02034A84[gUnk_02034A90].unk_15 = 1;

        if (*(u16*)s == 0x6E6E) {
            cx = 0;
            cy += 0xC00;
            s += 2;
        } else {
            v = *(u16*)s;
            v = (v / 256) | (v << 8);
            s += 2;

            if ((v & 0xFF00) == 0x8100) {
                switch (v & 0xFF) {
                case 0x40:
                    w = 0;
                    t = 0;
                    break;
                case 0x41:
                    w = 0xF5;
                    t = 0;
                    break;
                case 0x42:
                    w = 0xF6;
                    t = 0;
                    break;
                case 0x44:
                    w = 0xF7;
                    t = 0;
                    break;
                case 0x45:
                    w = 0xF9;
                    t = 0;
                    break;
                case 0x48:
                    w = 0xF1;
                    t = 0;
                    break;
                case 0x49:
                    w = 0xF0;
                    t = 0;
                    break;
                case 0x58:
                    w = 20;
                    t = 2;
                    break;
                case 0x5B:
                    w = 0xFD;
                    t = 0;
                    break;
                case 0x5C:
                    w = 0xFC;
                    t = 0;
                    break;
                case 0x60:
                    w = 0xFE;
                    t = 0;
                    break;
                case 0x63:
                    w = 0xFB;
                    t = 0;
                    break;
                case 0x75:
                    w = 0xE8;
                    t = 0;
                    break;
                case 0x76:
                    w = 0xE9;
                    t = 0;
                    break;
                case 0x77:
                    w = 0xEA;
                    t = 0;
                    break;
                case 0x78:
                    w = 0xEB;
                    t = 0;
                    break;
                case 0x66:
                    w = 0xFF;
                    t = 0;
                    break;
                case 0x69:
                    w = 0xEC;
                    t = 0;
                    break;
                case 0x6A:
                    w = 0xED;
                    t = 0;
                    break;
                case 0xA8:
                    w = 0xE7;
                    t = 0;
                    break;
                case 0xA9:
                    w = 0xE6;
                    t = 0;
                    break;
                case 0x7B:
                    w = 0xDF;
                    t = 0;
                    break;
                case 0x7C:
                    w = 0xFC;
                    t = 0;
                    break;
                case 0xA6:
                    w = 0xEE;
                    t = 0;
                    break;
                case 0x81:
                    w = 0xEF;
                    t = 0;
                    break;
                case 0x93:
                    w = 0xF2;
                    t = 0;
                    break;
                case 0x96:
                    w = 0xF4;
                    t = 0;
                    break;
                case 0x5E:
                    w = 0xF3;
                    t = 0;
                    break;
                case 0x43:
                    w = 0xF8;
                    t = 0;
                    break;
                case 0x9A:
                    w = 0x8E;
                    t = 0;
                    break;
                }

                if (gUnk_02034A90 != 0 &&
                    (v == 0x8141 || v == 0x8142 || v > 0x8177 || v == 0x8144 ||
                     (v == 0x8148 || v == 0x8149)) &&
                    cx == 0 && cy > 0) {
                    cx = px + 0xA00;
                    cy -= 0xC00;
                    gUnk_02034A84[gUnk_02034A90].unk_00 = x + cx;
                    gUnk_02034A84[gUnk_02034A90].unk_04 = y + cy;
                }
            } else {
                func_08066E40(v, &w, &t);
            }

            if (gUnk_02034A84[gUnk_02034A90].unk_08 != NULL) {
                ReleaseObjTiles(gUnk_02034A84[gUnk_02034A90].unk_08);
            }
            px = cx;

            if ((u16)(v - 0x8260) <= 58) {
                cx += 0xA00;
            } else {
                cx += 0xA00;
            }

            if (cx > 0x8C00) {
                cx = 0;
                cy += 0xC00;
            }

            switch (t) {
            case 0:
                w = ((u16*)gUnk_09EEB204[w])[3];
                gUnk_02034A84[gUnk_02034A90].unk_08 = LoadObjTiles(&gUnk_090AB5B2[w * 32], 128);
                break;
            case 1:
                w = ((u16*)gUnk_09EEB608[w])[3];
                gUnk_02034A84[gUnk_02034A90].unk_08 = LoadObjTiles(&gUnk_090B3FBE[w * 32], 128);
                break;
            case 2:
                w = ((u16*)gUnk_09EEBA0C[w])[3];
                gUnk_02034A84[gUnk_02034A90].unk_08 = LoadObjTiles(&gUnk_090BC9CA[w * 32], 128);
                break;
            case 3:
                w = ((u16*)gUnk_09EEBE10[w])[3];
                gUnk_02034A84[gUnk_02034A90].unk_08 = LoadObjTiles(&gUnk_090C51A6[w * 32], 128);
                break;
            }

            gUnk_02034A90++;
        }
    }

    return gUnk_02034A90;
}
#endif

void func_080658B8(u8 n) {
    u8 i;

    for (i = 0; i < n; i++) {
        Ent080658B8* b = gUnk_02034A84;

        if (b[i].unk_15 == 1) {
            s32 x = b[i].unk_00;
            s32 y = b[i].unk_04;

            if (b[i].unk_14 != 0) {
                if (b[i].unk_08 != NULL) {
                    func_08002488(x >> 8, y >> 8, gUnk_09EEB204[0], b[i].unk_08, b[i].unk_10, 0);
                }
            } else {
                if (b[i].unk_08 != NULL) {
                    func_08002488(x >> 8, y >> 8, gUnk_09EEB204[0], b[i].unk_08, b[i].unk_0C, 0);
                }
            }
        }
    }
}

void func_08065940(void) {
    u8 i;

    for (i = 0; i < 128; i++) {
        if (gUnk_02034A84[i].unk_08 != NULL) {
            ReleaseObjTiles(gUnk_02034A84[i].unk_08);
        }

        if (gUnk_02034A84[i].unk_0C != NULL) {
            ReleaseObjPalette(gUnk_02034A84[i].unk_0C);
        }

        if (gUnk_02034A84[i].unk_10 != NULL) {
            ReleaseObjPalette(gUnk_02034A84[i].unk_10);
        }
    }
    EwramFree(gUnk_02034A84);
}

void _08065994(void) {
    u8 i;

    for (i = 0; i < 128; i++) {
        gUnk_02034A84[i].unk_15 = 0;
    }
}

#ifndef VERSION_EU
u16 func_080659BC(u8 v, TextSlot* out) {
    u8 buf[8];
    u8 q;

    q = v / 10;
    if (q != 0) {
        buf[1] = v / 10;
        buf[3] = v - buf[1] * 10;
        buf[0] = 0x82;
        buf[1] += 0x4F;
        buf[2] = 0x82;
        buf[3] += 0x4F;
        buf[4] = 0;
    } else {
        buf[1] = v + 0x4F;
        buf[0] = 0x82;
        buf[2] = 0;
    }
    return func_080660C0(buf, out);
}
#endif
void func_08065A30(void** p, u8 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        *p++ = NULL;
    }
}
void func_08065A44(void** p, u8 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        if (*p != NULL) {
            ReleaseObjTiles(*p);
            *p = NULL;
        }
        p++;
    }
}

u16 func_08065A70(u8 v, TextSlot* out) {
#ifdef VERSION_JP
    u8 buf[8];
    s32 q;

    q = v / 10;
    if ((u8)q != 0) {
        buf[1] = v / 10;
        buf[3] = v - buf[1] * 10;
        buf[0] = 0x82;
        buf[1] += 0x4F;
        buf[2] = 0x82;
        buf[3] += 0x4F;
        buf[4] = 0;
    } else {
        buf[1] = v + 0x4F;
        buf[0] = 0x82;
        buf[2] = 0;
    }
#else
#ifdef VERSION_EU
    u8 buf[4];
    u8* p;
    u8 c;
    u8 end;
#else
    u16 buf[4];
    u16* p;
    u8 q;
    u16 c;
    u16 end;
#endif

    if (v > 9) {
        p = buf;
#ifdef VERSION_EU
        c = v / 10 + '0';
#else
        q = v / 10;
        c = q + '0';
#endif
        end = 0;
        p[0] = c;
#ifdef VERSION_EU
        buf[1] = v - (u8)(v / 10) * 10 + '0';
#else
        buf[1] = v - q * 10 + '0';
#endif
        buf[2] = end;
    } else {
        buf[0] = v + '0';
        buf[1] = 0;
    }
#endif
    return func_08065B6C((u16*)buf, out);
}

void func_08065ACC(TextSlot* p, s32 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        p->tiles = NULL;
        p->unk_05 = 0;
        p++;
    }
}

void func_08065AE0(TextSlot* p, s32 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        if (p->tiles != NULL) {
            ReleaseObjTiles(p->tiles);
            p->tiles = NULL;
        }
        p->unk_05 = 0;
        p++;
    }
}

s16 func_08065B08(TextSlot* p, u8 n) {
    s16 x;
    s32 i;

    x = 0;

    for (i = 0; i < n; i++) {
        if (p[i].tiles != NULL) {
            if (p[i].unk_05 != -1) {
                x += p[i].unk_05;
            } else {
                x += 3;
            }
        } else {
            return x;
        }
    }
    return x;
}

#ifdef VERSION_EU
s16 eu_0806629C(TextSlot* p, u8 n) {
    s16 max = 0;
    s16 x = 0;
    s32 i;

    for (i = 0; i < n; i++) {
        if (p[i].tiles != NULL) {
            if (p[i].unk_05 != -1) {
                x += p[i].unk_05;
            } else {
                x += 3;
            }
        } else {
            if (x > max) {
                max = x;
            }
            x = 0;
        }
    }
    if (max > x) {
        return max;
    }
    return x;
}
#endif

#if defined(VERSION_JP) || defined(VERSION_EU)
#define MSG_CHAR(p) (*(u8*)(p))
#else
#define MSG_CHAR(p) (*(p))
#endif

s32 func_08065B54(u16* s) {
#ifdef VERSION_JP
    u16* p = s;
    u16 n = 0;
#elif defined(VERSION_EU)
    u16 n = 0;
    u8* p = (u8*)s;
#else
    u16 n = 0;
    u16* p = s;
#endif

    while (MSG_CHAR(p) != 0) {
        n++;
        p++;
    }
    return n;
}

u16 func_08065B6C(u16* a, TextSlot* b) {
#ifdef VERSION_JP
    return func_08065D10(a, b);
#else
    return func_08065B7C(a, b);
#endif
}

s32 func_08065B7C(u16* a, TextSlot* b) {
    s32 n;

    n = 0;
    gUnk_02034A90 = n;

    while (MSG_CHAR(a) != 0) {
        s32 v = 0;

#ifdef VERSION_EU
        if (MSG_CHAR(a) == 31) {
#else
        if (MSG_CHAR(a) == 10) {
#endif
            if (b->tiles != NULL) {
                ReleaseObjTiles(b->tiles);
                b->tiles = NULL;
            }
            b->unk_05 = 0;
        } else {
#ifdef VERSION_EU
            v = MSG_CHAR(a);
#else
#ifdef VERSION_JP
            if (MSG_CHAR(a) > 31) {
#else
            if ((u16)(MSG_CHAR(a) - 32) <= 223) {
#endif
                v = MSG_CHAR(a);
            } else {
                switch (MSG_CHAR(a)) {
                case 0xE000:
                    v = 25;
                    break;
                case 0x2191:
                    v = 10;
                    break;
                case 0x2193:
                    v = 11;
                    break;
                case 0x2190:
                    v = 12;
                    break;
                case 0x2192:
                    v = 13;
                    break;
                case 0x300C:
                    v = 1;
                    break;
                case 0x300D:
                    v = 2;
                    break;
                case 0x300E:
                    v = 3;
                    break;
                case 0x300F:
                    v = 4;
                    break;
                case 0x203B:
                    v = 6;
                    break;
                case 0x266A:
                    v = 18;
                    break;
                case 0x2642:
                    v = 8;
                    break;
                case 0x2640:
                    v = 9;
                    break;
                case 0x2605:
                    v = 21;
                    break;
                case 0x25A0:
                    v = 17;
                    break;
                default:
                    v = 0;
                    break;
                }
            }

#endif
            if (b->tiles != NULL) {
                ReleaseObjTiles(b->tiles);
                b->tiles = NULL;
            }

            if (v != 32) {
                b->unk_05 = gUnk_08F7D438[v];
            } else {
                b->unk_05 = 255;
            }
#ifdef VERSION_EU
            v = ((u16*)gUnk_09EEB204[v])[3];
            b->tiles = LoadObjTiles(&gUnkEu_0919B63A[v * 32], 128);
#else
            v = ((u16*)gUnk_09EEC134[v])[3];
            b->tiles = LoadObjTiles(&gUnk_090CBFB2[v * 32], 128);
#endif
            b->unk_04 = n;
        }
        gUnk_02034A90++;
        b++;
#if defined(VERSION_EU) || defined(VERSION_JP)
        a = (u16*)((u8*)a + 1);
#else
        a++;
#endif
    }
    return gUnk_02034A90;
}
#ifndef VERSION_EU
s32 func_08065D10(u16* a, TextSlot* b) {
    u8 buf[2];
    u16* c;
    u16 w;
    u8 t;
    u8 n;

    w = 0;
    t = 0;
    n = 0;

    while (MSG_CHAR(a) != 0) {
        u16 v;

#ifdef VERSION_JP
        buf[0] = ((u8*)a)[0];
        buf[1] = ((u8*)a)[1];
#else
        buf[0] = a[0];
        buf[1] = a[1];
#endif
        c = (u16*)buf;

        if (*c == 0x6E6E) {
#ifdef VERSION_JP
            a = (u16*)((u8*)a + 2);
#else
            a += 2;
#endif

            if (b->tiles != 0) {
                ReleaseObjTiles(b->tiles);
            }

            b->tiles = 0;
            b->unk_05 = 0;
        } else {
            v = *c;
            v = (v / 256) | (v << 8);
#ifdef VERSION_JP
            a = (u16*)((u8*)a + 2);
#else
            a += 2;
#endif

            if ((v & 0xFF00) == 0x8100) {
                v &= 0xFF;

                switch (v) {
                case 0x40:
                    w = 0;
                    t = 0;
                    break;
                case 0x41:
                    w = 0xF5;
                    t = 0;
                    break;
                case 0x42:
                    w = 0xF6;
                    t = 0;
                    break;
                case 0x45:
                    w = 0xF9;
                    t = 0;
                    break;
                case 0x46:
                    w = 0xFA;
                    t = 0;
                    break;
                case 0x48:
                    w = 0xF1;
                    t = 0;
                    break;
                case 0x49:
                    w = 0xF0;
                    t = 0;
                    break;
                case 0x58:
                    w = 20;
                    t = 2;
                    break;
                case 0x5B:
                    w = 0xFD;
                    t = 0;
                    break;
                case 0x5C:
                    w = 0xFC;
                    t = 0;
                    break;
                case 0x60:
                    w = 0xFE;
                    t = 0;
                    break;
                case 0x63:
                    w = 0xFB;
                    t = 0;
                    break;
                case 0x75:
                    w = 0xE8;
                    t = 0;
                    break;
                case 0x76:
                    w = 0xE9;
                    t = 0;
                    break;
                case 0x77:
                    w = 0xEA;
                    t = 0;
                    break;
                case 0x78:
                    w = 0xEB;
                    t = 0;
                    break;
                case 0x66:
                    w = 0xFF;
                    t = 0;
                    break;
                case 0x69:
                    w = 0xEC;
                    t = 0;
                    break;
                case 0x6A:
                    w = 0xED;
                    t = 0;
                    break;
                case 0xA8:
                    w = 0xE7;
                    t = 0;
                    break;
                case 0xA9:
                    w = 0xE6;
                    t = 0;
                    break;
                case 0x7B:
                    w = 0xDF;
                    t = 0;
                    break;
                case 0x7C:
                    w = 0xFC;
                    t = 0;
                    break;
                case 0xA6:
                    w = 0xEE;
                    t = 0;
                    break;
                case 0x81:
                    w = 0xEF;
                    t = 0;
                    break;
                case 0x93:
                    w = 0xF2;
                    t = 0;
                    break;
                case 0x96:
                    w = 0xF4;
                    t = 0;
                    break;
                case 0x5E:
                    w = 0xF3;
                    t = 0;
                    break;
                case 0x43:
                    w = 0xF8;
                    t = 0;
                    break;
                case 0x9A:
                    w = 0x8E;
                    t = 0;
                    break;
                }
            } else {
                func_08066E40(v, &w, &t);
            }

            if (b->tiles != 0) {
                ReleaseObjTiles(b->tiles);
                b->tiles = 0;
            }

            switch (t) {
            case 0:
                w = ((u16*)gUnk_09EEB204[w])[3];
                b->tiles = LoadObjTiles(&gUnk_090AB5B2[w * 32], 128);
                break;
            case 1:
                w = ((u16*)gUnk_09EEB608[w])[3];
                b->tiles = LoadObjTiles(&gUnk_090B3FBE[w * 32], 128);
                break;
            case 2:
                w = ((u16*)gUnk_09EEBA0C[w])[3];
                b->tiles = LoadObjTiles(&gUnk_090BC9CA[w * 32], 128);
                break;
            case 3:
                w = ((u16*)gUnk_09EEBE10[w])[3];
                b->tiles = LoadObjTiles(&gUnk_090C51A6[w * 32], 128);
                break;
            }

            b->unk_05 = 10;
        }

        b++;
        n++;
    }

    return n;
}
#endif
#ifndef VERSION_EU
#ifndef VERSION_JP
s32 func_080660C0(u16* a, void** p) {
#else
s32 func_080660C0(u8* a, void** p) {
#endif
    u8 buf[2];
    u16* c;
    u16 w;
    u8 t;
    u8 n;

    w = 0;
    t = 0;
    n = 0;

    while (*a != 0) {
        u16 v;

        buf[0] = a[0];
        buf[1] = a[1];
        c = (u16*)buf;

        if (*c == 0x6E6E) {
            a += 2;

            if (*p != 0) {
                ReleaseObjTiles(*p);
            }

            *p++ = 0;
        } else {
            v = *c;
            v = (v / 256) | (v << 8);
            a += 2;

            if ((v & 0xFF00) == 0x8100) {
                v &= 0xFF;

                switch (v) {
                case 0x40:
                    w = 0;
                    t = 0;
                    break;
                case 0x41:
                    w = 0xF5;
                    t = 0;
                    break;
                case 0x42:
                    w = 0xF6;
                    t = 0;
                    break;
                case 0x45:
                    w = 0xF9;
                    t = 0;
                    break;
                case 0x46:
                    w = 0xFA;
                    t = 0;
                    break;
                case 0x48:
                    w = 0xF1;
                    t = 0;
                    break;
                case 0x49:
                    w = 0xF0;
                    t = 0;
                    break;
                case 0x58:
                    w = 20;
                    t = 2;
                    break;
                case 0x5B:
                    w = 0xFD;
                    t = 0;
                    break;
                case 0x5C:
                    w = 0xFC;
                    t = 0;
                    break;
                case 0x60:
                    w = 0xFE;
                    t = 0;
                    break;
                case 0x63:
                    w = 0xFB;
                    t = 0;
                    break;
                case 0x75:
                    w = 0xE8;
                    t = 0;
                    break;
                case 0x76:
                    w = 0xE9;
                    t = 0;
                    break;
                case 0x77:
                    w = 0xEA;
                    t = 0;
                    break;
                case 0x78:
                    w = 0xEB;
                    t = 0;
                    break;
                case 0x66:
                    w = 0xFF;
                    t = 0;
                    break;
                case 0x69:
                    w = 0xEC;
                    t = 0;
                    break;
                case 0x6A:
                    w = 0xED;
                    t = 0;
                    break;
                case 0xA8:
                    w = 0xE7;
                    t = 0;
                    break;
                case 0xA9:
                    w = 0xE6;
                    t = 0;
                    break;
                case 0x7B:
                    w = 0xDF;
                    t = 0;
                    break;
                case 0x7C:
                    w = 0xFC;
                    t = 0;
                    break;
                case 0xA6:
                    w = 0xEE;
                    t = 0;
                    break;
                case 0x81:
                    w = 0xEF;
                    t = 0;
                    break;
                case 0x93:
                    w = 0xF2;
                    t = 0;
                    break;
                case 0x96:
                    w = 0xF4;
                    t = 0;
                    break;
                case 0x5E:
                    w = 0xF3;
                    t = 0;
                    break;
                case 0x43:
                    w = 0xF8;
                    t = 0;
                    break;
                case 0x9A:
                    w = 0x8E;
                    t = 0;
                    break;
                }
            } else {
                func_08066E40(v, &w, &t);
            }

            if (*p != 0) {
                ReleaseObjTiles(*p);
                *p = 0;
            }

            switch (t) {
            case 0:
                w = ((u16*)gUnk_09EEB204[w])[3];
                *p = LoadObjTiles(&gUnk_090AB5B2[w * 32], 128);
                break;
            case 1:
                w = ((u16*)gUnk_09EEB608[w])[3];
                *p = LoadObjTiles(&gUnk_090B3FBE[w * 32], 128);
                break;
            case 2:
                w = ((u16*)gUnk_09EEBA0C[w])[3];
                *p = LoadObjTiles(&gUnk_090BC9CA[w * 32], 128);
                break;
            case 3:
                w = ((u16*)gUnk_09EEBE10[w])[3];
                *p = LoadObjTiles(&gUnk_090C51A6[w * 32], 128);
                break;
            }

            p++;
        }

        n++;
    }

    return n;
}
#endif
void* _08066468(s32 a) {
    void* r = NULL;

    switch (a) {
    case 0:
        r = LoadObjPalette(gUnk_09614758, 32);
        break;
    case 1:
        r = LoadObjPalette(gUnk_09614718, 32);
        break;
    case 2:
        r = LoadObjPalette(gUnk_09614738, 32);
        break;
    case 3:
        r = LoadObjPalette(gUnk_09614798, 32);
        break;
    case 4:
        r = LoadObjPalette(gUnk_096147B8, 32);
        break;
    case 5:
        r = LoadObjPalette(gUnk_09614778, 32);
        break;
    }
    return r;
}

void func_080664D8(s16 x, s16 y, TextSlot* p, void* d, u16 h, u8 n) {
    s16 x0 = x;
    s16 cy = y;
    u8 i;

#ifndef VERSION_JP
    cy -= 2;
#endif

    for (i = 0; i < n; i++) {
        if (p->tiles == NULL) {
            cy += 12;
            x = x0;
        } else if (p->unk_05 != -1) {
            DrawSprite(x, cy, gUnk_09EEB204[0], p->tiles, d, 0, 0, h);
            x += p->unk_05;
        } else {
            x += 3;
        }
        p++;
    }
}

void func_08066588(s16 x, s32 y, TextSlot* p, void* d, s32 e, u8 n) {
    s16 x0 = x;
    s16 cy = y;
    u8 i;

#ifndef VERSION_JP
    cy -= 2;
#endif

    for (i = 0; i < n; i++) {
        if (p->tiles == NULL) {
            cy += 12;
            x = x0;
        } else if (p->unk_05 != -1) {
            func_08002488(x, cy, gUnk_09EEB204[0], p->tiles, d, 0);
            x += p->unk_05;
        } else {
            x += 3;
        }
        p++;
    }
}

void func_0806662C(s16 x, s32 y, TextSlot* p, void* d, u16 g, u16 h, u8 n) {
    s16 x0 = x;
    s16 cy = y;
    u8 i;

#ifndef VERSION_JP
    cy -= 2;
#endif

    for (i = 0; i < n; i++) {
        if (p->tiles == NULL) {
            cy += 12;
            x = x0;
        } else if (p->unk_05 != -1) {
            DrawSprite(x, cy, gUnk_09EEB204[0], p->tiles, d, 0, g, h);
            x += p->unk_05;
        } else {
            x += 3;
        }
        p++;
    }
}

void func_080666F0(s16 x, s32 y, TextSlot* p, void* d, void* e, u16 h, u8 n) {
    s16 x0 = x;
    s16 cy = y;
    u8 i;

#ifndef VERSION_JP
    cy -= 2;
#endif

    for (i = 0; i < n; i++) {
        if (p->tiles == NULL) {
            cy += 12;
            x = x0;
        } else if (p->unk_05 != -1) {
            if (p->unk_04 == 0) {
                DrawSprite(x, cy, gUnk_09EEB204[0], p->tiles, d, 0, 0, h);
            } else {
                DrawSprite(x, cy, gUnk_09EEB204[0], p->tiles, e, 0, 0, h);
            }
            x += p->unk_05;
        } else {
            x += 3;
        }
        p++;
    }
}

void func_080667D8(s16 x, s32 y, void** p, void* d, u16 h, u8 n) {
    s16 cy = y;
    s16 x0 = x;
    u8 i;

    for (i = 0; i < n; i++) {
        if (*p == NULL) {
            cy += 12;
            x = x0;
        } else {
            DrawSprite(x, cy, gUnk_09EEB204[0], *p, d, 0, 0, h);
            x += 10;
        }
        p++;
    }
}
void func_08066864(s16 x, s32 y, void** p, void* d, s32 e, u16 h, u8 n) {
    s16 cy = y;
    s16 x0 = x;
    u8 i;

    for (i = 0; i < n; i++) {
        if (*p == NULL) {
            cy += 12;
            x = x0;
        } else {
            DrawSprite(x, cy, gUnk_09EEB204[0], *p, d, 0, 0, h);
            x += 10;
        }
        p++;
    }
}

void* func_080668F0(void) {
    return LoadObjTiles(gUnk_090D4180, 0x5A0);
}

void* func_08066904(void) {
    return LoadObjPalette(gUnk_08F69BE4, 0x20);
}

void func_08066918(void* a, void* b) {
    ReleaseObjTiles(a);
    ReleaseObjPalette(b);
}

u16 func_0806692C(u8* s, u16* out) {
    u16 g = 0;
    u8 n;
    u8 i;

    if (out == NULL) {
        return 0;
    }
    n = func_0809D280(s);
    for (i = 0; i < n; i++) {
        if ((u8)(s[i] - '0') <= 9) {
            g = s[i] - '0';
        }

        if ((u8)(s[i] - 'A') <= 25) {
            g = s[i] - 0x37;
        }

        if ((u8)(s[i] - 'a') <= 25) {
            g = s[i] - 0x57;
        }

        if (s[i] == '/') {
            g = 0x24;
        }

        if (s[i] == '-') {
            g = 0x25;
        }

        if (s[i] == '_') {
            g = 0x26;
        }

        if (s[i] == '.') {
            g = 0x27;
        }

        if (s[i] == '+') {
            g = 0x28;
        }

        if (s[i] == '!') {
            g = 0x29;
        }

        if (s[i] == '?') {
            g = 0x2A;
        }

        if (s[i] == '#') {
            g = 0x2B;
        }

        if (s[i] == '%') {
            g = 0x2C;
        }
        *out++ = g;
    }
    return n;
}

u16 _080669DC(s32 v, u16* out) {
    s32 t[11];
    u8 s[12];
    s32 acc;
    s32 d;
    s32 i;

    acc = 0;

    if (v >= 0) {
        d = 1000000000;

        for (i = 0; i <= 9; i++) {
            t[i] = v / d - acc;
            acc = (acc + t[i]) * 10;
            d /= 10;
        }

        for (i = 0; i <= 9; i++) {
            s[i] = t[i] + '0';
        }
        s[10] = 0;

        for (i = 0; i <= 9; i++) {
            if (s[i] > '0') {
                break;
            }
        }
        return func_0806692C(&s[i], out);
    }
    d = -1000000000;

    for (i = 1; i <= 10; i++) {
        t[i] = v / d - acc;
        acc = (acc + t[i]) * 10;
        d /= 10;
    }
    s[0] = '-';

    for (i = 1; i <= 10; i++) {
        s[i] = t[i] + '0';
    }
    s[11] = 0;

    for (i = 1; i <= 10; i++) {
        if (s[i] > '0') {
            break;
        }
    }
    s[i - 1] = '-';
    return func_0806692C(&s[i - 1], out);
}



u16 func_08066AF8(s32 v, u16* out) {
    u8 buf[11];
    u8* p;
    s32 i;

    buf[0] = '0';
    buf[1] = 'x';
    buf[2] = (v & 0xF0000000) >> 28;
    buf[3] = (v & 0x0F000000) >> 24;
    buf[4] = (v & 0x00F00000) >> 20;
    buf[5] = (v & 0x000F0000) >> 16;
    buf[6] = (v & 0x0000F000) >> 12;
    buf[7] = (v & 0x00000F00) >> 8;
    buf[8] = (v & 0x000000F0) >> 4;
    buf[9] = v & 0xF;
    buf[10] = 0;
    p = &buf[2];

    for (i = 0; i < 8; i++) {
        if (*p <= 9) {
            *p += 0x30;
        } else {
            *p += 0x37;
        }
        p++;
    }
    return func_0806692C(buf, out);
}

u16 _08066B84(u32 v, u16* out, u8 mode) {
    u8 a[2];
    u8 b[9];
    u8 c[17];
    u8 d[33];

    switch (mode) {
    case 0:
        a[0] = v;
        a[0] += '0';
        a[1] = 0;
        return func_0806692C(a, out);
    case 1:
        b[0] = (v >> 7) + '0';
        b[1] = ((v >> 6) & 1) + '0';
        b[2] = ((v >> 5) & 1) + '0';
        b[3] = ((v >> 4) & 1) + '0';
        b[4] = ((v >> 3) & 1) + '0';
        b[5] = ((v >> 2) & 1) + '0';
        b[6] = ((v >> 1) & 1) + '0';
        b[7] = (v & 1) + '0';
        b[8] = 0;
        return func_0806692C(b, out);
    case 2:
        c[0] = (v >> 15) + '0';
        c[1] = ((v >> 14) & 1) + '0';
        c[2] = ((v >> 13) & 1) + '0';
        c[3] = ((v >> 12) & 1) + '0';
        c[4] = ((v >> 11) & 1) + '0';
        c[5] = ((v >> 10) & 1) + '0';
        c[6] = ((v >> 9) & 1) + '0';
        c[7] = ((v >> 8) & 1) + '0';
        c[8] = ((v >> 7) & 1) + '0';
        c[9] = ((v >> 6) & 1) + '0';
        c[10] = ((v >> 5) & 1) + '0';
        c[11] = ((v >> 4) & 1) + '0';
        c[12] = ((v >> 3) & 1) + '0';
        c[13] = ((v >> 2) & 1) + '0';
        c[14] = ((v >> 1) & 1) + '0';
        c[15] = (v & 1) + '0';
        c[16] = 0;
        return func_0806692C(c, out);
    case 3:
        d[0] = (v >> 31) + '0';
        d[1] = ((v >> 30) & 1) + '0';
        d[2] = ((v >> 29) & 1) + '0';
        d[3] = ((v >> 28) & 1) + '0';
        d[4] = ((v >> 27) & 1) + '0';
        d[5] = ((v >> 26) & 1) + '0';
        d[6] = ((v >> 25) & 1) + '0';
        d[7] = ((v >> 24) & 1) + '0';
        d[8] = ((v >> 23) & 1) + '0';
        d[9] = ((v >> 22) & 1) + '0';
        d[10] = ((v >> 21) & 1) + '0';
        d[11] = ((v >> 20) & 1) + '0';
        d[12] = ((v >> 19) & 1) + '0';
        d[13] = ((v >> 18) & 1) + '0';
        d[14] = ((v >> 17) & 1) + '0';
        d[15] = ((v >> 16) & 1) + '0';
        d[16] = ((v >> 15) & 1) + '0';
        d[17] = ((v >> 14) & 1) + '0';
        d[18] = ((v >> 13) & 1) + '0';
        d[19] = ((v >> 12) & 1) + '0';
        d[20] = ((v >> 11) & 1) + '0';
        d[21] = ((v >> 10) & 1) + '0';
        d[22] = ((v >> 9) & 1) + '0';
        d[23] = ((v >> 8) & 1) + '0';
        d[24] = ((v >> 7) & 1) + '0';
        d[25] = ((v >> 6) & 1) + '0';
        d[26] = ((v >> 5) & 1) + '0';
        d[27] = ((v >> 4) & 1) + '0';
        d[28] = ((v >> 3) & 1) + '0';
        d[29] = ((v >> 2) & 1) + '0';
        d[30] = ((v >> 1) & 1) + '0';
        d[31] = (v & 1) + '0';
        return func_0806692C(d, out);
    }
}
s32 func_08066DC0(s16 x, s16 y, u16* s, void* d, void* e, u16 h, u8 n) {
    u8 i;

    for (i = 0; i < n; i++) {
        DrawSprite(x + i * 8, y, gUnk_09EEC538[*s], d, e, 0, 0, h);
        s++;
    }
}
void func_08066E40(u16 a, u16* b, u8* c) {
    switch (a & 0xFF00) {
    case 0x8200: {
        u16 v = a & 0xFF;
        if ((u16)(v - 96) <= 25) {
            *b = a + 0x7DAB;
        }
        if ((u16)(v - 129) <= 25) {
            *b = a + 0x7DA4;
        }
        if ((u16)(v - 79) <= 9) {
            *b = a + 0x7DB2;
        }
        if ((u16)(v - 159) <= 82) {
            *b = a + 0x7DA0;
        }
        *c = 0;
        break;
    }
    case 0x8300: {
        u16 v = a & 0xFF;
        if ((u16)(v - 64) <= 62) {
            *b = a + 0x7D52;
        }
        if ((u16)(v - 128) <= 20) {
            *b = a + 0x7D51;
        }
        *c = 0;
        break;
    }
    case 0x8700:
        switch (a & 0xFF) {
        case 0x56:
            *b = 143;
            *c = 0;
            break;
        case 0x5D:
            *b = 142;
            *c = 0;
            break;
        default:
            *b = 0;
            *c = 0;
            break;
        }
        break;
    case 0x8800:
        switch (a & 0xFF) {
        case 0xC5:
            *b = 9;
            *c = 1;
            break;
        case 0xC3:
            *b = 84;
            *c = 1;
            break;
        case 0xF3:
            *b = 86;
            *c = 1;
            break;
        case 0xEA:
            *b = 104;
            *c = 1;
            break;
        case 0xF9:
            *b = 153;
            *c = 1;
            break;
        case 0xE1:
            *b = 179;
            *c = 1;
            break;
        case 0xC8:
            *b = 182;
            *c = 1;
            break;
        case 0xAB:
            *b = 208;
            *c = 1;
            break;
        case 0xF6:
            *b = 247;
            *c = 1;
            break;
        case 0xB5:
            *b = 250;
            *c = 1;
            break;
        case 0xD3:
            *b = 3;
            *c = 2;
            break;
        case 0xC0:
            *b = 17;
            *c = 2;
            break;
        case 0xCD:
            *b = 57;
            *c = 2;
            break;
        case 0xE7:
            *b = 105;
            *c = 2;
            break;
        case 0xF8:
            *b = 164;
            *c = 2;
            break;
        case 0xF5:
            *b = 184;
            *c = 2;
            break;
        case 0xA4:
            *b = 192;
            *c = 2;
            break;
        case 0xA3:
            *b = 207;
            *c = 2;
            break;
        case 0xC4:
            *b = 63;
            *c = 3;
            break;
        case 0xAC:
            *b = 78;
            *c = 3;
            break;
        case 0xDF:
            *b = 102;
            *c = 3;
            break;
        case 0xDA:
            *b = 118;
            *c = 3;
            break;
        case 0xD9:
            *b = 135;
            *c = 3;
            break;
        case 0xCA:
            *b = 136;
            *c = 3;
            break;
        case 0xD0:
            *b = 187;
            *c = 3;
            break;
        default:
            *b = 0;
            *c = 0;
            break;
        }
        break;
    case 0x8900:
        switch (a & 0xFF) {
        case 0x9C:
            *b = 4;
            *c = 1;
            break;
        case 0xAF:
            *b = 26;
            *c = 1;
            break;
        case 0xBD:
            *b = 47;
            *c = 1;
            break;
        case 0xA4:
            *b = 49;
            *c = 1;
            break;
        case 0x69:
            *b = 74;
            *c = 1;
            break;
        case 0x93:
            *b = 75;
            *c = 1;
            break;
        case 0xF6:
            *b = 95;
            *c = 1;
            break;
        case 0xEF:
            *b = 98;
            *c = 1;
            break;
        case 0x52:
            *b = 103;
            *c = 1;
            break;
        case 0xB4:
            *b = 107;
            *c = 1;
            break;
        case 0xC6:
            *b = 121;
            *c = 1;
            break;
        case 0x5E:
            *b = 124;
            *c = 1;
            break;
        case 0x42:
            *b = 160;
            *c = 1;
            break;
        case 0xBB:
            *b = 198;
            *c = 1;
            break;
        case 0xEE:
            *b = 205;
            *c = 1;
            break;
        case 0xBA:
            *b = 1;
            *c = 2;
            break;
        case 0x98:
            *b = 8;
            *c = 2;
            break;
        case 0xBC:
            *b = 15;
            *c = 2;
            break;
        case 0xF0:
            *b = 61;
            *c = 2;
            break;
        case 0xF1:
            *b = 65;
            *c = 2;
            break;
        case 0xCA:
            *b = 89;
            *c = 2;
            break;
        case 0x6A:
            *b = 101;
            *c = 2;
            break;
        case 0xE4:
            *b = 104;
            *c = 2;
            break;
        case 0xB9:
            *b = 120;
            *c = 2;
            break;
        case 0xAE:
            *b = 124;
            *c = 2;
            break;
        case 0xC1:
            *b = 152;
            *c = 2;
            break;
        case 0x70:
            *b = 155;
            *c = 2;
            break;
        case 0xF7:
            *b = 177;
            *c = 2;
            break;
        case 0xDF:
            *b = 200;
            *c = 2;
            break;
        case 0xE6:
            *b = 201;
            *c = 2;
            break;
        case 0xBF:
            *b = 218;
            *c = 2;
            break;
        case 0x65:
            *b = 240;
            *c = 2;
            break;
        case 0x7A:
            *b = 244;
            *c = 2;
            break;
        case 0xC8:
            *b = 13;
            *c = 3;
            break;
        case 0x41:
            *b = 51;
            *c = 3;
            break;
        case 0x8F:
            *b = 55;
            *c = 3;
            break;
        case 0x9E:
            *b = 80;
            *c = 3;
            break;
        case 0x45:
            *b = 113;
            *c = 3;
            break;
        case 0xCE:
            *b = 129;
            *c = 3;
            break;
        case 0x9F:
            *b = 142;
            *c = 3;
            break;
        case 0xD7:
            *b = 148;
            *c = 3;
            break;
        case 0xC2:
            *b = 150;
            *c = 3;
            break;
        case 0x8A:
            *b = 154;
            *c = 3;
            break;
        case 0xD4:
            *b = 181;
            *c = 3;
            break;
        case 0xFC:
            *b = 188;
            *c = 3;
            break;
        default:
            *b = 0;
            *c = 0;
            break;
        }
        break;
    case 0x8A00:
        switch (a & 0xFF) {
        case 0x4F:
            *b = 8;
            *c = 1;
            break;
        case 0x6D:
            *b = 17;
            *c = 1;
            break;
        case 0xB5:
            *b = 61;
            *c = 1;
            break;
        case 0x4B:
            *b = 76;
            *c = 1;
            break;
        case 0xA3:
            *b = 81;
            *c = 1;
            break;
        case 0x45:
            *b = 83;
            *c = 1;
            break;
        case 0xD4:
            *b = 101;
            *c = 1;
            break;
        case 0x43:
            *b = 123;
            *c = 1;
            break;
        case 0xEB:
            *b = 139;
            *c = 1;
            break;
        case 0xB4:
            *b = 167;
            *c = 1;
            break;
        case 0x79:
            *b = 188;
            *c = 1;
            break;
        case 0x58:
            *b = 199;
            *c = 1;
            break;
        case 0xAA:
            *b = 252;
            *c = 1;
            break;
        case 0xB1:
            *b = 9;
            *c = 2;
            break;
        case 0xEF:
            *b = 13;
            *c = 2;
            break;
        case 0xE7:
            *b = 54;
            *c = 2;
            break;
        case 0xE8:
            *b = 59;
            *c = 2;
            break;
        case 0xC3:
            *b = 64;
            *c = 2;
            break;
        case 0xC8:
            *b = 84;
            *c = 2;
            break;
        case 0xF1:
            *b = 140;
            *c = 2;
            break;
        case 0x6F:
            *b = 143;
            *c = 2;
            break;
        case 0x4A:
            *b = 146;
            *c = 2;
            break;
        case 0x51:
            *b = 149;
            *c = 2;
            break;
        case 0xD6:
            *b = 178;
            *c = 2;
            break;
        case 0x69:
            *b = 248;
            *c = 2;
            break;
        case 0x47:
            *b = 3;
            *c = 3;
            break;
        case 0x77:
            *b = 14;
            *c = 3;
            break;
        case 0xEC:
            *b = 46;
            *c = 3;
            break;
        case 0xAE:
            *b = 56;
            *c = 3;
            break;
        case 0xED:
            *b = 76;
            *c = 3;
            break;
        case 0xB7:
            *b = 85;
            *c = 3;
            break;
        case 0x88:
            *b = 88;
            *c = 3;
            break;
        case 0xA5:
            *b = 145;
            *c = 3;
            break;
        case 0xFA:
            *b = 162;
            *c = 3;
            break;
        case 0xAB:
            *b = 166;
            *c = 3;
            break;
        default:
            *b = 0;
            *c = 0;
            break;
        }
        break;
    case 0x8B00:
        switch (a & 0xFF) {
        case 0x4C:
            *b = 25;
            *c = 1;
            break;
        case 0x41:
            *b = 30;
            *c = 1;
            break;
        case 0x43:
            *b = 38;
            *c = 1;
            break;
        case 0x5E:
            *b = 62;
            *c = 1;
            break;
        case 0xB3:
            *b = 70;
            *c = 1;
            break;
        case 0xFC:
            *b = 72;
            *c = 1;
            break;
        case 0xAD:
            *b = 73;
            *c = 1;
            break;
        case 0x63:
            *b = 89;
            *c = 1;
            break;
        case 0x9F:
            *b = 129;
            *c = 1;
            break;
        case 0xDF:
            *b = 134;
            *c = 1;
            break;
        case 0xA6:
            *b = 158;
            *c = 1;
            break;
        case 0xEA:
            *b = 173;
            *c = 1;
            break;
        case 0xE6:
            *b = 180;
            *c = 1;
            break;
        case 0xBB:
            *b = 189;
            *c = 1;
            break;
        case 0xC1:
            *b = 200;
            *c = 1;
            break;
        case 0xB0:
            *b = 207;
            *c = 1;
            break;
        case 0x4E:
            *b = 214;
            *c = 1;
            break;
        case 0x86:
            *b = 221;
            *c = 1;
            break;
        case 0x74:
            *b = 239;
            *c = 1;
            break;
        case 0x7E:
            *b = 253;
            *c = 1;
            break;
        case 0xB9:
            *b = 7;
            *c = 2;
            break;
        case 0x46:
            *b = 19;
            *c = 2;
            break;
        case 0x5A:
            *b = 24;
            *c = 2;
            break;
        case 0x7D:
            *b = 27;
            *c = 2;
            break;
        case 0x92:
            *b = 40;
            *c = 2;
            break;
        case 0x96:
            *b = 43;
            *c = 2;
            break;
        case 0x7B:
            *b = 66;
            *c = 2;
            break;
        case 0xB6:
            *b = 88;
            *c = 2;
            break;
        case 0xF3:
            *b = 99;
            *c = 2;
            break;
        case 0x5D:
            *b = 108;
            *c = 2;
            break;
        case 0xC8:
            *b = 126;
            *c = 2;
            break;
        case 0xA3:
            *b = 153;
            *c = 2;
            break;
        case 0x81:
            *b = 195;
            *c = 2;
            break;
        case 0xEC:
            *b = 198;
            *c = 2;
            break;
        case 0x91:
            *b = 203;
            *c = 2;
            break;
        case 0x50:
            *b = 204;
            *c = 2;
            break;
        case 0xF0:
            *b = 208;
            *c = 2;
            break;
        case 0x8E:
            *b = 213;
            *c = 2;
            break;
        case 0x70:
            *b = 214;
            *c = 2;
            break;
        case 0xBF:
            *b = 220;
            *c = 2;
            break;
        case 0xB5:
            *b = 235;
            *c = 2;
            break;
        case 0x76:
            *b = 237;
            *c = 2;
            break;
        case 0xF4:
            *b = 239;
            *c = 2;
            break;
        case 0x40:
            *b = 254;
            *c = 2;
            break;
        case 0x60:
            *b = 255;
            *c = 2;
            break;
        case 0x83:
            *b = 5;
            *c = 3;
            break;
        case 0x95:
            *b = 43;
            *c = 3;
            break;
        case 0xEF:
            *b = 45;
            *c = 3;
            break;
        case 0x4D:
            *b = 66;
            *c = 3;
            break;
        case 0xBD:
            *b = 71;
            *c = 3;
            break;
        case 0x90:
            *b = 99;
            *c = 3;
            break;
        case 0x7A:
            *b = 123;
            *c = 3;
            break;
        case 0x9B:
            *b = 131;
            *c = 3;
            break;
        case 0xA5:
            *b = 158;
            *c = 3;
            break;
        case 0x78:
            *b = 167;
            *c = 3;
            break;
        case 0xE0:
            *b = 169;
            *c = 3;
            break;
        case 0xC9:
            *b = 179;
            *c = 3;
            break;
        case 0xCA:
            *b = 184;
            *c = 3;
            break;
        case 0xCF:
            *b = 186;
            *c = 3;
            break;
        default:
            *b = 0;
            *c = 0;
            break;
        }
        break;
    case 0x8C00:
        switch (a & 0xFF) {
        case 0x4E:
            *b = 6;
            *c = 1;
            break;
        case 0xF5:
            *b = 11;
            *c = 1;
            break;
        case 0xA9:
            *b = 12;
            *c = 1;
            break;
        case 0x78:
            *b = 22;
            *c = 1;
            break;
        case 0xAB:
            *b = 55;
            *c = 1;
            break;
        case 0xBE:
            *b = 67;
            *c = 1;
            break;
        case 0xAE:
            *b = 80;
            *c = 1;
            break;
        case 0xB3:
            *b = 91;
            *c = 1;
            break;
        case 0x76:
            *b = 116;
            *c = 1;
            break;
        case 0x60:
            *b = 128;
            *c = 1;
            break;
        case 0x9F:
            *b = 138;
            *c = 1;
            break;
        case 0xFB:
            *b = 152;
            *c = 1;
            break;
        case 0xC8:
            *b = 203;
            *c = 1;
            break;
        case 0xC4:
            *b = 215;
            *c = 1;
            break;
        case 0xBB:
            *b = 216;
            *c = 1;
            break;
        case 0xA4:
            *b = 220;
            *c = 1;
            break;
        case 0xC0:
            *b = 233;
            *c = 1;
            break;
        case 0xB4:
            *b = 246;
            *c = 1;
            break;
        case 0xB1:
            *b = 12;
            *c = 2;
            break;
        case 0x69:
            *b = 33;
            *c = 2;
            break;
        case 0x88:
            *b = 46;
            *c = 2;
            break;
        case 0x59:
            *b = 49;
            *c = 2;
            break;
        case 0xE4:
            *b = 60;
            *c = 2;
            break;
        case 0x41:
            *b = 73;
            *c = 2;
            break;
        case 0xE3:
            *b = 76;
            *c = 2;
            break;
        case 0x8B:
            *b = 90;
            *c = 2;
            break;
        case 0xFC:
            *b = 96;
            *c = 2;
            break;
        case 0xDD:
            *b = 97;
            *c = 2;
            break;
        case 0x57:
            *b = 106;
            *c = 2;
            break;
        case 0xAF:
            *b = 111;
            *c = 2;
            break;
        case 0x99:
            *b = 117;
            *c = 2;
            break;
        case 0xB5:
            *b = 129;
            *c = 2;
            break;
        case 0xB8:
            *b = 175;
            *c = 2;
            break;
        case 0xE5:
            *b = 183;
            *c = 2;
            break;
        case 0x8F:
            *b = 211;
            *c = 2;
            break;
        case 0xB6:
            *b = 226;
            *c = 2;
            break;
        case 0x8A:
            *b = 238;
            *c = 2;
            break;
        case 0xC3:
            *b = 251;
            *c = 2;
            break;
        case 0x79:
            *b = 9;
            *c = 3;
            break;
        case 0xEB:
            *b = 19;
            *c = 3;
            break;
        case 0x8C:
            *b = 31;
            *c = 3;
            break;
        case 0x95:
            *b = 37;
            *c = 3;
            break;
        case 0xF0:
            *b = 57;
            *c = 3;
            break;
        case 0xCC:
            *b = 70;
            *c = 3;
            break;
        case 0xF8:
            *b = 98;
            *c = 3;
            break;
        case 0xEA:
            *b = 100;
            *c = 3;
            break;
        case 0x82:
            *b = 122;
            *c = 3;
            break;
        case 0xB9:
            *b = 171;
            *c = 3;
            break;
        case 0x6E:
            *b = 172;
            *c = 3;
            break;
        case 0x87:
            *b = 189;
            *c = 3;
            break;
        case 0x5E:
            *b = 191;
            *c = 3;
            break;
        default:
            *b = 0;
            *c = 0;
            break;
        }
        break;
    case 0x8D00:
        switch (a & 0xFF) {
        case 0x90:
            *b = 23;
            *c = 1;
            break;
        case 0x73:
            *b = 31;
            *c = 1;
            break;
        case 0xDF:
            *b = 46;
            *c = 1;
            break;
        case 0x9E:
            *b = 127;
            *c = 1;
            break;
        case 0xC5:
            *b = 133;
            *c = 1;
            break;
        case 0xA2:
            *b = 143;
            *c = 1;
            break;
        case 0x6C:
            *b = 157;
            *c = 1;
            break;
        case 0xA1:
            *b = 164;
            *c = 1;
            break;
        case 0xC4:
            *b = 187;
            *c = 1;
            break;
        case 0xCB:
            *b = 228;
            *c = 1;
            break;
        case 0xEC:
            *b = 230;
            *c = 1;
            break;
        case 0x87:
            *b = 23;
            *c = 2;
            break;
        case 0x8F:
            *b = 26;
            *c = 2;
            break;
        case 0xD9:
            *b = 29;
            *c = 2;
            break;
        case 0x91:
            *b = 38;
            *c = 2;
            break;
        case 0x44:
            *b = 81;
            *c = 2;
            break;
        case 0xA5:
            *b = 91;
            *c = 2;
            break;
        case 0x72:
            *b = 134;
            *c = 2;
            break;
        case 0x52:
            *b = 139;
            *c = 2;
            break;
        case 0xB6:
            *b = 141;
            *c = 2;
            break;
        case 0xC3:
            *b = 147;
            *c = 2;
            break;
        case 0xCF:
            *b = 179;
            *c = 2;
            break;
        case 0x58:
            *b = 202;
            *c = 2;
            break;
        case 0x82:
            *b = 215;
            *c = 2;
            break;
        case 0xDD:
            *b = 224;
            *c = 2;
            break;
        case 0xD7:
            *b = 230;
            *c = 2;
            break;
        case 0x48:
            *b = 231;
            *c = 2;
            break;
        case 0x4C:
            *b = 243;
            *c = 2;
            break;
        case 0xFB:
            *b = 250;
            *c = 2;
            break;
        case 0x5C:
            *b = 15;
            *c = 3;
            break;
        case 0x93:
            *b = 39;
            *c = 3;
            break;
        case 0xBD:
            *b = 40;
            *c = 3;
            break;
        case 0xAC:
            *b = 92;
            *c = 3;
            break;
        case 0xDB:
            *b = 108;
            *c = 3;
            break;
        case 0x55:
            *b = 121;
            *c = 3;
            break;
        case 0xBB:
            *b = 128;
            *c = 3;
            break;
        case 0xAA:
            *b = 185;
            *c = 3;
            break;
        default:
            *b = 0;
            *c = 0;
            break;
        }
        break;
    case 0x8E00:
        switch (a & 0xFF) {
        case 0xB8:
            *b = 13;
            *c = 1;
            break;
        case 0xA9:
            *b = 15;
            *c = 1;
            break;
        case 0xD7:
            *b = 18;
            *c = 1;
            break;
        case 0xD2:
            *b = 21;
            *c = 1;
            break;
        case 0x9E:
            *b = 27;
            *c = 1;
            break;
        case 0x76:
            *b = 28;
            *c = 1;
            break;
        case 0x84:
            *b = 44;
            *c = 1;
            break;
        case 0xA1:
            *b = 54;
            *c = 1;
            break;
        case 0xA6:
            *b = 87;
            *c = 1;
            break;
        case 0x71:
            *b = 102;
            *c = 1;
            break;
        case 0xC0:
            *b = 111;
            *c = 1;
            break;
        case 0x9F:
            *b = 155;
            *c = 1;
            break;
        case 0x9D:
            *b = 156;
            *c = 1;
            break;
        case 0x96:
            *b = 161;
            *c = 1;
            break;
        case 0x8E:
            *b = 191;
            *c = 1;
            break;
        case 0xE8:
            *b = 197;
            *c = 1;
            break;
        case 0x6D:
            *b = 219;
            *c = 1;
            break;
        case 0x70:
            *b = 232;
            *c = 1;
            break;
        case 0xE6:
            *b = 241;
            *c = 1;
            break;
        case 0xE3:
            *b = 249;
            *c = 1;
            break;
        case 0x63:
            *b = 10;
            *c = 2;
            break;
        case 0x64:
            *b = 22;
            *c = 2;
            break;
        case 0xB6:
            *b = 28;
            *c = 2;
            break;
        case 0xF1:
            *b = 31;
            *c = 2;
            break;
        case 0x80:
            *b = 48;
            *c = 2;
            break;
        case 0xE5:
            *b = 75;
            *c = 2;
            break;
        case 0x4F:
            *b = 78;
            *c = 2;
            break;
        case 0xD3:
            *b = 80;
            *c = 2;
            break;
        case 0x67:
            *b = 86;
            *c = 2;
            break;
        case 0x5A:
            *b = 87;
            *c = 2;
            break;
        case 0xE7:
            *b = 102;
            *c = 2;
            break;
        case 0xD8:
            *b = 112;
            *c = 2;
            break;
        case 0x97:
            *b = 122;
            *c = 2;
            break;
        case 0x8B:
            *b = 136;
            *c = 2;
            break;
        case 0x51:
            *b = 151;
            *c = 2;
            break;
        case 0x6E:
            *b = 166;
            *c = 2;
            break;
        case 0x7E:
            *b = 169;
            *c = 2;
            break;
        case 0xF3:
            *b = 194;
            *c = 2;
            break;
        case 0xF4:
            *b = 199;
            *c = 2;
            break;
        case 0x78:
            *b = 227;
            *c = 2;
            break;
        case 0x55:
            *b = 242;
            *c = 2;
            break;
        case 0xED:
            *b = 246;
            *c = 2;
            break;
        case 0x40:
            *b = 16;
            *c = 3;
            break;
        case 0x77:
            *b = 25;
            *c = 3;
            break;
        case 0xCC:
            *b = 42;
            *c = 3;
            break;
        case 0x91:
            *b = 50;
            *c = 3;
            break;
        case 0xA8:
            *b = 81;
            *c = 3;
            break;
        case 0xFB:
            *b = 124;
            *c = 3;
            break;
        case 0xD4:
            *b = 125;
            *c = 3;
            break;
        case 0x9A:
            *b = 140;
            *c = 3;
            break;
        case 0xEA:
            *b = 146;
            *c = 3;
            break;
        case 0x61:
            *b = 159;
            *c = 3;
            break;
        case 0xCB:
            *b = 164;
            *c = 3;
            break;
        case 0xBF:
            *b = 196;
            *c = 3;
            break;
        default:
            *b = 0;
            *c = 0;
            break;
        }
        break;
    case 0x8F00:
        switch (a & 0xFF) {
        case 0x6F:
            *b = 29;
            *c = 1;
            break;
        case 0xEA:
            *b = 32;
            *c = 1;
            break;
        case 0x8A:
            *b = 33;
            *c = 1;
            break;
        case 0x97:
            *b = 48;
            *c = 1;
            break;
        case 0x95:
            *b = 68;
            *c = 1;
            break;
        case 0xE3:
            *b = 183;
            *c = 1;
            break;
        case 0xE4:
            *b = 185;
            *c = 1;
            break;
        case 0x80:
            *b = 194;
            *c = 1;
            break;
        case 0xD0:
            *b = 204;
            *c = 1;
            break;
        case 0x50:
            *b = 217;
            *c = 1;
            break;
        case 0xE7:
            *b = 224;
            *c = 1;
            break;
        case 0x94:
            *b = 226;
            *c = 1;
            break;
        case 0x64:
            *b = 236;
            *c = 1;
            break;
        case 0xAD:
            *b = 21;
            *c = 2;
            break;
        case 0x57:
            *b = 35;
            *c = 2;
            break;
        case 0xD8:
            *b = 39;
            *c = 2;
            break;
        case 0x9F:
            *b = 45;
            *c = 2;
            break;
        case 0x89:
            *b = 63;
            *c = 2;
            break;
        case 0x8F:
            *b = 70;
            *c = 2;
            break;
        case 0x5D:
            *b = 83;
            *c = 2;
            break;
        case 0xC1:
            *b = 142;
            *c = 2;
            break;
        case 0xC4:
            *b = 144;
            *c = 2;
            break;
        case 0x91:
            *b = 145;
            *c = 2;
            break;
        case 0xE1:
            *b = 148;
            *c = 2;
            break;
        case 0xF3:
            *b = 186;
            *c = 2;
            break;
        case 0xE9:
            *b = 189;
            *c = 2;
            break;
        case 0x49:
            *b = 190;
            *c = 2;
            break;
        case 0xEE:
            *b = 191;
            *c = 2;
            break;
        case 0xE6:
            *b = 196;
            *c = 2;
            break;
        case 0x5B:
            *b = 206;
            *c = 2;
            break;
        case 0x75:
            *b = 209;
            *c = 2;
            break;
        case 0x68:
            *b = 225;
            *c = 2;
            break;
        case 0xAC:
            *b = 229;
            *c = 2;
            break;
        case 0x9D:
            *b = 233;
            *c = 2;
            break;
        case 0x5A:
            *b = 0;
            *c = 3;
            break;
        case 0xCE:
            *b = 2;
            *c = 3;
            break;
        case 0x83:
            *b = 22;
            *c = 3;
            break;
        case 0xF0:
            *b = 28;
            *c = 3;
            break;
        case 0x70:
            *b = 84;
            *c = 3;
            break;
        case 0xC6:
            *b = 130;
            *c = 3;
            break;
        case 0x5C:
            *b = 139;
            *c = 3;
            break;
        case 0xA2:
            *b = 165;
            *c = 3;
            break;
        case 0xED:
            *b = 175;
            *c = 3;
            break;
        default:
            *b = 0;
            *c = 0;
            break;
        }
        break;
    case 0x9000:
        switch (a & 0xFF) {
        case 0xD8:
            *b = 1;
            *c = 1;
            break;
        case 0x53:
            *b = 3;
            *c = 1;
            break;
        case 0x6C:
            *b = 43;
            *c = 1;
            break;
        case 0xB0:
            *b = 65;
            *c = 1;
            break;
        case 0xED:
            *b = 66;
            *c = 1;
            break;
        case 0x5B:
            *b = 69;
            *c = 1;
            break;
        case 0xA2:
            *b = 82;
            *c = 1;
            break;
        case 0x51:
            *b = 94;
            *c = 1;
            break;
        case 0xBA:
            *b = 97;
            *c = 1;
            break;
        case 0xE0:
            *b = 112;
            *c = 1;
            break;
        case 0x45:
            *b = 117;
            *c = 1;
            break;
        case 0xB6:
            *b = 130;
            *c = 1;
            break;
        case 0xB3:
            *b = 149;
            *c = 1;
            break;
        case 0x4D:
            *b = 151;
            *c = 1;
            break;
        case 0x48:
            *b = 169;
            *c = 1;
            break;
        case 0xA8:
            *b = 175;
            *c = 1;
            break;
        case 0xAC:
            *b = 184;
            *c = 1;
            break;
        case 0x5E:
            *b = 231;
            *c = 1;
            break;
        case 0x65:
            *b = 251;
            *c = 1;
            break;
        case 0xE2:
            *b = 255;
            *c = 1;
            break;
        case 0x56:
            *b = 4;
            *c = 2;
            break;
        case 0x46:
            *b = 34;
            *c = 2;
            break;
        case 0xD3:
            *b = 41;
            *c = 2;
            break;
        case 0x67:
            *b = 44;
            *c = 2;
            break;
        case 0xE6:
            *b = 68;
            *c = 2;
            break;
        case 0x69:
            *b = 69;
            *c = 2;
            break;
        case 0x62:
            *b = 71;
            *c = 2;
            break;
        case 0x85:
            *b = 100;
            *c = 2;
            break;
        case 0xB5:
            *b = 109;
            *c = 2;
            break;
        case 0x94:
            *b = 173;
            *c = 2;
            break;
        case 0x58:
            *b = 210;
            *c = 2;
            break;
        case 0x84:
            *b = 20;
            *c = 3;
            break;
        case 0xCC:
            *b = 21;
            *c = 3;
            break;
        case 0x7D:
            *b = 23;
            *c = 3;
            break;
        case 0xAF:
            *b = 35;
            *c = 3;
            break;
        case 0xD4:
            *b = 49;
            *c = 3;
            break;
        case 0xF5:
            *b = 73;
            *c = 3;
            break;
        case 0x41:
            *b = 83;
            *c = 3;
            break;
        case 0xC2:
            *b = 95;
            *c = 3;
            break;
        case 0xB8:
            *b = 97;
            *c = 3;
            break;
        case 0x5F:
            *b = 104;
            *c = 3;
            break;
        case 0xC3:
            *b = 105;
            *c = 3;
            break;
        case 0xAB:
            *b = 106;
            *c = 3;
            break;
        case 0x44:
            *b = 109;
            *c = 3;
            break;
        case 0xDA:
            *b = 127;
            *c = 3;
            break;
        case 0x55:
            *b = 132;
            *c = 3;
            break;
        case 0xA7:
            *b = 163;
            *c = 3;
            break;
        default:
            *b = 0;
            *c = 0;
            break;
        }
        break;
    case 0x9100:
        switch (a & 0xFF) {
        case 0xE5:
            *b = 0;
            *c = 1;
            break;
        case 0x7A:
            *b = 2;
            *c = 1;
            break;
        case 0xDE:
            *b = 53;
            *c = 1;
            break;
        case 0xD2:
            *b = 59;
            *c = 1;
            break;
        case 0x52:
            *b = 64;
            *c = 1;
            break;
        case 0xAB:
            *b = 90;
            *c = 1;
            break;
        case 0xCC:
            *b = 135;
            *c = 1;
            break;
        case 0x81:
            *b = 137;
            *c = 1;
            break;
        case 0x7B:
            *b = 145;
            *c = 1;
            break;
        case 0xA9:
            *b = 163;
            *c = 1;
            break;
        case 0x9C:
            *b = 181;
            *c = 1;
            break;
        case 0x8A:
            *b = 196;
            *c = 1;
            break;
        case 0x66:
            *b = 201;
            *c = 1;
            break;
        case 0xE8:
            *b = 212;
            *c = 1;
            break;
        case 0x95:
            *b = 235;
            *c = 1;
            break;
        case 0x4E:
            *b = 5;
            *c = 2;
            break;
        case 0x4F:
            *b = 50;
            *c = 2;
            break;
        case 0x9B:
            *b = 51;
            *c = 2;
            break;
        case 0xA7:
            *b = 98;
            *c = 2;
            break;
        case 0x84:
            *b = 103;
            *c = 2;
            break;
        case 0xBD:
            *b = 107;
            *c = 2;
            break;
        case 0xDD:
            *b = 113;
            *c = 2;
            break;
        case 0xAE:
            *b = 115;
            *c = 2;
            break;
        case 0x44:
            *b = 121;
            *c = 2;
            break;
        case 0xAF:
            *b = 127;
            *c = 2;
            break;
        case 0xCA:
            *b = 137;
            *c = 2;
            break;
        case 0xBC:
            *b = 150;
            *c = 2;
            break;
        case 0x88:
            *b = 154;
            *c = 2;
            break;
        case 0x49:
            *b = 158;
            *c = 2;
            break;
        case 0xC5:
            *b = 165;
            *c = 2;
            break;
        case 0x67:
            *b = 170;
            *c = 2;
            break;
        case 0x53:
            *b = 171;
            *c = 2;
            break;
        case 0x5F:
            *b = 176;
            *c = 2;
            break;
        case 0xD4:
            *b = 187;
            *c = 2;
            break;
        case 0xCE:
            *b = 212;
            *c = 2;
            break;
        case 0xB6:
            *b = 223;
            *c = 2;
            break;
        case 0xB1:
            *b = 6;
            *c = 3;
            break;
        case 0xA4:
            *b = 32;
            *c = 3;
            break;
        case 0xE4:
            *b = 48;
            *c = 3;
            break;
        case 0xE3:
            *b = 72;
            *c = 3;
            break;
        case 0xB0:
            *b = 74;
            *c = 3;
            break;
        case 0x97:
            *b = 86;
            *c = 3;
            break;
        case 0x50:
            *b = 103;
            *c = 3;
            break;
        case 0xBE:
            *b = 119;
            *c = 3;
            break;
        case 0xF0:
            *b = 137;
            *c = 3;
            break;
        case 0x77:
            *b = 149;
            *c = 3;
            break;
        case 0x96:
            *b = 161;
            *c = 3;
            break;
        case 0xAC:
            *b = 173;
            *c = 3;
            break;
        case 0xE6:
            *b = 192;
            *c = 3;
            break;
        case 0x9D:
            *b = 195;
            *c = 3;
            break;
        default:
            *b = 0;
            *c = 0;
            break;
        }
        break;
    case 0x9200:
        switch (a & 0xFF) {
        case 0x86:
            *b = 10;
            *c = 1;
            break;
        case 0x6D:
            *b = 14;
            *c = 1;
            break;
        case 0x42:
            *b = 35;
            *c = 1;
            break;
        case 0x40:
            *b = 39;
            *c = 1;
            break;
        case 0x4E:
            *b = 40;
            *c = 1;
            break;
        case 0x69:
            *b = 77;
            *c = 1;
            break;
        case 0x6E:
            *b = 79;
            *c = 1;
            break;
        case 0x8B:
            *b = 93;
            *c = 1;
            break;
        case 0xB7:
            *b = 120;
            *c = 1;
            break;
        case 0x54:
            *b = 122;
            *c = 1;
            break;
        case 0xBC:
            *b = 132;
            *c = 1;
            break;
        case 0x45:
            *b = 177;
            *c = 1;
            break;
        case 0x75:
            *b = 178;
            *c = 1;
            break;
        case 0xEA:
            *b = 206;
            *c = 1;
            break;
        case 0xCA:
            *b = 222;
            *c = 1;
            break;
        case 0x6B:
            *b = 225;
            *c = 1;
            break;
        case 0xB2:
            *b = 245;
            *c = 1;
            break;
        case 0xC9:
            *b = 254;
            *c = 1;
            break;
        case 0xC7:
            *b = 6;
            *c = 2;
            break;
        case 0x78:
            *b = 25;
            *c = 2;
            break;
        case 0x50:
            *b = 85;
            *c = 2;
            break;
        case 0x44:
            *b = 92;
            *c = 2;
            break;
        case 0x8D:
            *b = 133;
            *c = 2;
            break;
        case 0x87:
            *b = 135;
            *c = 2;
            break;
        case 0xEF:
            *b = 138;
            *c = 2;
            break;
        case 0x6C:
            *b = 219;
            *c = 2;
            break;
        case 0x85:
            *b = 221;
            *c = 2;
            break;
        case 0x6A:
            *b = 222;
            *c = 2;
            break;
        case 0xF6:
            *b = 12;
            *c = 3;
            break;
        case 0xBE:
            *b = 58;
            *c = 3;
            break;
        case 0x66:
            *b = 69;
            *c = 3;
            break;
        case 0x63:
            *b = 77;
            *c = 3;
            break;
        case 0xA7:
            *b = 94;
            *c = 3;
            break;
        case 0x5A:
            *b = 101;
            *c = 3;
            break;
        case 0x8E:
            *b = 107;
            *c = 3;
            break;
        case 0xE8:
            *b = 138;
            *c = 3;
            break;
        case 0x65:
            *b = 153;
            *c = 3;
            break;
        case 0xB4:
            *b = 157;
            *c = 3;
            break;
        case 0xE1:
            *b = 178;
            *c = 3;
            break;
        default:
            *b = 0;
            *c = 0;
            break;
        }
        break;
    case 0x9300:
        switch (a & 0xFF) {
        case 0x90:
            *b = 45;
            *c = 1;
            break;
        case 0x9A:
            *b = 57;
            *c = 1;
            break;
        case 0x96:
            *b = 63;
            *c = 1;
            break;
        case 0xAE:
            *b = 100;
            *c = 1;
            break;
        case 0x78:
            *b = 105;
            *c = 1;
            break;
        case 0xFC:
            *b = 106;
            *c = 1;
            break;
        case 0xC1:
            *b = 108;
            *c = 1;
            break;
        case 0xE0:
            *b = 136;
            *c = 1;
            break;
        case 0x7B:
            *b = 148;
            *c = 1;
            break;
        case 0x60:
            *b = 150;
            *c = 1;
            break;
        case 0xA6:
            *b = 168;
            *c = 1;
            break;
        case 0x66:
            *b = 172;
            *c = 1;
            break;
        case 0x47:
            *b = 202;
            *c = 1;
            break;
        case 0x56:
            *b = 227;
            *c = 1;
            break;
        case 0x6E:
            *b = 47;
            *c = 2;
            break;
        case 0xAF:
            *b = 55;
            *c = 2;
            break;
        case 0xAA:
            *b = 58;
            *c = 2;
            break;
        case 0x61:
            *b = 67;
            *c = 2;
            break;
        case 0xB4:
            *b = 72;
            *c = 2;
            break;
        case 0xEF:
            *b = 82;
            *c = 2;
            break;
        case 0xFA:
            *b = 131;
            *c = 2;
            break;
        case 0xCB:
            *b = 159;
            *c = 2;
            break;
        case 0xF1:
            *b = 168;
            *c = 2;
            break;
        case 0x73:
            *b = 180;
            *c = 2;
            break;
        case 0x7C:
            *b = 182;
            *c = 2;
            break;
        case 0xC5:
            *b = 232;
            *c = 2;
            break;
        case 0xCD:
            *b = 245;
            *c = 2;
            break;
        case 0x49:
            *b = 252;
            *c = 2;
            break;
        case 0x87:
            *b = 1;
            *c = 3;
            break;
        case 0xB1:
            *b = 26;
            *c = 3;
            break;
        case 0xB9:
            *b = 44;
            *c = 3;
            break;
        case 0x5D:
            *b = 47;
            *c = 3;
            break;
        case 0x54:
            *b = 61;
            *c = 3;
            break;
        case 0x72:
            *b = 65;
            *c = 3;
            break;
        case 0xE4:
            *b = 89;
            *c = 3;
            break;
        case 0x79:
            *b = 90;
            *c = 3;
            break;
        case 0xBE:
            *b = 93;
            *c = 3;
            break;
        case 0xAC:
            *b = 126;
            *c = 3;
            break;
        case 0xC7:
            *b = 134;
            *c = 3;
            break;
        case 0x58:
            *b = 147;
            *c = 3;
            break;
        case 0x8A:
            *b = 152;
            *c = 3;
            break;
        case 0x64:
            *b = 170;
            *c = 3;
            break;
        case 0x5F:
            *b = 190;
            *c = 3;
            break;
        case 0xF7:
            *b = 197;
            *c = 3;
            break;
        default:
            *b = 0;
            *c = 0;
            break;
        }
        break;
    case 0x9400:
        switch (a & 0xFF) {
        case 0xDE:
            *b = 41;
            *c = 1;
            break;
        case 0xC6:
            *b = 42;
            *c = 1;
            break;
        case 0x7A:
            *b = 144;
            *c = 1;
            break;
        case 0xF5:
            *b = 195;
            *c = 1;
            break;
        case 0x8E:
            *b = 218;
            *c = 1;
            break;
        case 0x6A:
            *b = 223;
            *c = 1;
            break;
        case 0xAD:
            *b = 229;
            *c = 1;
            break;
        case 0xFC:
            *b = 240;
            *c = 1;
            break;
        case 0x73:
            *b = 244;
            *c = 1;
            break;
        case 0xDF:
            *b = 18;
            *c = 2;
            break;
        case 0xBB:
            *b = 30;
            *c = 2;
            break;
        case 0xF2:
            *b = 32;
            *c = 2;
            break;
        case 0x92:
            *b = 36;
            *c = 2;
            break;
        case 0xED:
            *b = 37;
            *c = 2;
            break;
        case 0x43:
            *b = 42;
            *c = 2;
            break;
        case 0x4F:
            *b = 52;
            *c = 2;
            break;
        case 0x4C:
            *b = 53;
            *c = 2;
            break;
        case 0x59:
            *b = 62;
            *c = 2;
            break;
        case 0xB2:
            *b = 74;
            *c = 2;
            break;
        case 0x97:
            *b = 114;
            *c = 2;
            break;
        case 0x67:
            *b = 119;
            *c = 2;
            break;
        case 0x46:
            *b = 160;
            *c = 2;
            break;
        case 0xE9:
            *b = 205;
            *c = 2;
            break;
        case 0x83:
            *b = 216;
            *c = 2;
            break;
        case 0xE0:
            *b = 228;
            *c = 2;
            break;
        case 0x5C:
            *b = 236;
            *c = 2;
            break;
        case 0xD4:
            *b = 7;
            *c = 3;
            break;
        case 0xBC:
            *b = 8;
            *c = 3;
            break;
        case 0x96:
            *b = 10;
            *c = 3;
            break;
        case 0xB1:
            *b = 11;
            *c = 3;
            break;
        case 0xBD:
            *b = 24;
            *c = 3;
            break;
        case 0x9B:
            *b = 41;
            *c = 3;
            break;
        case 0x77:
            *b = 67;
            *c = 3;
            break;
        case 0x9A:
            *b = 68;
            *c = 3;
            break;
        case 0x4D:
            *b = 82;
            *c = 3;
            break;
        case 0x4E:
            *b = 96;
            *c = 3;
            break;
        case 0xF1:
            *b = 110;
            *c = 3;
            break;
        case 0x7B:
            *b = 151;
            *c = 3;
            break;
        case 0xA0:
            *b = 176;
            *c = 3;
            break;
        case 0xE7:
            *b = 183;
            *c = 3;
            break;
        case 0x65:
            *b = 193;
            *c = 3;
            break;
        default:
            *b = 0;
            *c = 0;
            break;
        }
        break;
    case 0x9500:
        switch (a & 0xFF) {
        case 0xAA:
            *b = 16;
            *c = 1;
            break;
        case 0x7C:
            *b = 37;
            *c = 1;
            break;
        case 0x95:
            *b = 85;
            *c = 1;
            break;
        case 0x73:
            *b = 88;
            *c = 1;
            break;
        case 0xCF:
            *b = 92;
            *c = 1;
            break;
        case 0xA8:
            *b = 96;
            *c = 1;
            break;
        case 0xCA:
            *b = 109;
            *c = 1;
            break;
        case 0xFB:
            *b = 110;
            *c = 1;
            break;
        case 0x83:
            *b = 114;
            *c = 1;
            break;
        case 0xB7:
            *b = 115;
            *c = 1;
            break;
        case 0xA0:
            *b = 118;
            *c = 1;
            break;
        case 0xC2:
            *b = 126;
            *c = 1;
            break;
        case 0xE0:
            *b = 146;
            *c = 1;
            break;
        case 0xF3:
            *b = 147;
            *c = 1;
            break;
        case 0x40:
            *b = 165;
            *c = 1;
            break;
        case 0xBD:
            *b = 171;
            *c = 1;
            break;
        case 0x76:
            *b = 186;
            *c = 1;
            break;
        case 0xF8:
            *b = 213;
            *c = 1;
            break;
        case 0xD4:
            *b = 248;
            *c = 1;
            break;
        case 0x69:
            *b = 2;
            *c = 2;
            break;
        case 0x4B:
            *b = 16;
            *c = 2;
            break;
        case 0xB5:
            *b = 56;
            *c = 2;
            break;
        case 0xFA:
            *b = 110;
            *c = 2;
            break;
        case 0x9A:
            *b = 116;
            *c = 2;
            break;
        case 0x94:
            *b = 123;
            *c = 2;
            break;
        case 0x89:
            *b = 157;
            *c = 2;
            break;
        case 0xA1:
            *b = 172;
            *c = 2;
            break;
        case 0xD6:
            *b = 234;
            *c = 2;
            break;
        case 0x60:
            *b = 4;
            *c = 3;
            break;
        case 0xF1:
            *b = 27;
            *c = 3;
            break;
        case 0x82:
            *b = 38;
            *c = 3;
            break;
        case 0xD0:
            *b = 59;
            *c = 3;
            break;
        case 0x97:
            *b = 62;
            *c = 3;
            break;
        case 0x90:
            *b = 75;
            *c = 3;
            break;
        case 0x9C:
            *b = 87;
            *c = 3;
            break;
        case 0xBA:
            *b = 111;
            *c = 3;
            break;
        case 0x5C:
            *b = 116;
            *c = 3;
            break;
        case 0x58:
            *b = 155;
            *c = 3;
            break;
        case 0xB6:
            *b = 160;
            *c = 3;
            break;
        case 0xD2:
            *b = 194;
            *c = 3;
            break;
        default:
            *b = 0;
            *c = 0;
            break;
        }
        break;
    case 0x9600:
        switch (a & 0xFF) {
        case 0x59:
            *b = 5;
            *c = 1;
            break;
        case 0x82:
            *b = 19;
            *c = 1;
            break;
        case 0xB0:
            *b = 24;
            *c = 1;
            break;
        case 0x6C:
            *b = 36;
            *c = 1;
            break;
        case 0xBD:
            *b = 51;
            *c = 1;
            break;
        case 0x7B:
            *b = 71;
            *c = 1;
            break;
        case 0xBE:
            *b = 113;
            *c = 1;
            break;
        case 0x40:
            *b = 125;
            *c = 1;
            break;
        case 0x9E:
            *b = 131;
            *c = 1;
            break;
        case 0xD9:
            *b = 142;
            *c = 1;
            break;
        case 0xF1:
            *b = 162;
            *c = 1;
            break;
        case 0x5C:
            *b = 170;
            *c = 1;
            break;
        case 0xB3:
            *b = 176;
            *c = 1;
            break;
        case 0xA1:
            *b = 190;
            *c = 1;
            break;
        case 0xBC:
            *b = 193;
            *c = 1;
            break;
        case 0xB2:
            *b = 209;
            *c = 1;
            break;
        case 0xE2:
            *b = 211;
            *c = 1;
            break;
        case 0xDF:
            *b = 242;
            *c = 1;
            break;
        case 0xF2:
            *b = 243;
            *c = 1;
            break;
        case 0x5D:
            *b = 0;
            *c = 2;
            break;
        case 0xAD:
            *b = 14;
            *c = 2;
            break;
        case 0xDA:
            *b = 79;
            *c = 2;
            break;
        case 0xCA:
            *b = 94;
            *c = 2;
            break;
        case 0xC0:
            *b = 125;
            *c = 2;
            break;
        case 0x88:
            *b = 130;
            *c = 2;
            break;
        case 0xEC:
            *b = 161;
            *c = 2;
            break;
        case 0xBB:
            *b = 163;
            *c = 2;
            break;
        case 0x96:
            *b = 167;
            *c = 2;
            break;
        case 0x57:
            *b = 174;
            *c = 2;
            break;
        case 0x9C:
            *b = 185;
            *c = 2;
            break;
        case 0xC2:
            *b = 197;
            *c = 2;
            break;
        case 0xF0:
            *b = 217;
            *c = 2;
            break;
        case 0xA7:
            *b = 253;
            *c = 2;
            break;
        case 0xF3:
            *b = 18;
            *c = 3;
            break;
        case 0xA2:
            *b = 29;
            *c = 3;
            break;
        case 0x4B:
            *b = 33;
            *c = 3;
            break;
        case 0xE9:
            *b = 36;
            *c = 3;
            break;
        case 0x64:
            *b = 52;
            *c = 3;
            break;
        case 0xC5:
            *b = 53;
            *c = 3;
            break;
        case 0xBA:
            *b = 54;
            *c = 3;
            break;
        case 0x60:
            *b = 91;
            *c = 3;
            break;
        case 0xD8:
            *b = 117;
            *c = 3;
            break;
        case 0xFB:
            *b = 120;
            *c = 3;
            break;
        case 0x87:
            *b = 143;
            *c = 3;
            break;
        case 0x68:
            *b = 199;
            *c = 3;
            break;
        default:
            *b = 0;
            *c = 0;
            break;
        }
        break;
    case 0x9700:
        switch (a & 0xFF) {
        case 0xE1:
            *b = 7;
            *c = 1;
            break;
        case 0x45:
            *b = 20;
            *c = 1;
            break;
        case 0x46:
            *b = 34;
            *c = 1;
            break;
        case 0x6C:
            *b = 50;
            *c = 1;
            break;
        case 0xDF:
            *b = 52;
            *c = 1;
            break;
        case 0x88:
            *b = 56;
            *c = 1;
            break;
        case 0x70:
            *b = 60;
            *c = 1;
            break;
        case 0x79:
            *b = 78;
            *c = 1;
            break;
        case 0xC7:
            *b = 99;
            *c = 1;
            break;
        case 0x9D:
            *b = 140;
            *c = 1;
            break;
        case 0x52:
            *b = 141;
            *c = 1;
            break;
        case 0x44:
            *b = 154;
            *c = 1;
            break;
        case 0xCD:
            *b = 159;
            *c = 1;
            break;
        case 0x5C:
            *b = 166;
            *c = 1;
            break;
        case 0xA3:
            *b = 174;
            *c = 1;
            break;
        case 0x98:
            *b = 192;
            *c = 1;
            break;
        case 0x76:
            *b = 237;
            *c = 1;
            break;
        case 0x8A:
            *b = 11;
            *c = 2;
            break;
        case 0x74:
            *b = 77;
            *c = 2;
            break;
        case 0x8E:
            *b = 93;
            *c = 2;
            break;
        case 0xA7:
            *b = 95;
            *c = 2;
            break;
        case 0x68:
            *b = 118;
            *c = 2;
            break;
        case 0xE7:
            *b = 128;
            *c = 2;
            break;
        case 0x56:
            *b = 132;
            *c = 2;
            break;
        case 0x59:
            *b = 156;
            *c = 2;
            break;
        case 0x90:
            *b = 181;
            *c = 2;
            break;
        case 0xE2:
            *b = 193;
            *c = 2;
            break;
        case 0x4C:
            *b = 241;
            *c = 2;
            break;
        case 0xDE:
            *b = 247;
            *c = 2;
            break;
        case 0xB7:
            *b = 249;
            *c = 2;
            break;
        case 0x63:
            *b = 17;
            *c = 3;
            break;
        case 0xA0:
            *b = 30;
            *c = 3;
            break;
        case 0xAC:
            *b = 34;
            *c = 3;
            break;
        case 0x83:
            *b = 60;
            *c = 3;
            break;
        case 0x5E:
            *b = 64;
            *c = 3;
            break;
        case 0xBC:
            *b = 79;
            *c = 3;
            break;
        case 0x7A:
            *b = 112;
            *c = 3;
            break;
        case 0x64:
            *b = 115;
            *c = 3;
            break;
        case 0xB9:
            *b = 144;
            *c = 3;
            break;
        case 0x8B:
            *b = 156;
            *c = 3;
            break;
        case 0xAA:
            *b = 174;
            *c = 3;
            break;
        case 0xCA:
            *b = 180;
            *c = 3;
            break;
        case 0xA6:
            *b = 182;
            *c = 3;
            break;
        case 0x6E:
            *b = 198;
            *c = 3;
            break;
        default:
            *b = 0;
            *c = 0;
            break;
        }
        break;
    case 0x9800:
        switch (a & 0xFF) {
        case 0x41:
            *b = 58;
            *c = 1;
            break;
        case 0x62:
            *b = 119;
            *c = 1;
            break;
        case 0x5E:
            *b = 234;
            *c = 1;
            break;
        case 0x63:
            *b = 238;
            *c = 1;
            break;
        case 0x59:
            *b = 162;
            *c = 2;
            break;
        case 0x66:
            *b = 188;
            *c = 2;
            break;
        case 0x72:
            *b = 133;
            *c = 3;
            break;
        case 0x48:
            *b = 141;
            *c = 3;
            break;
        case 0x42:
            *b = 168;
            *c = 3;
            break;
        case 0x61:
            *b = 177;
            *c = 3;
            break;
        default:
            *b = 0;
            *c = 0;
            break;
        }
        break;
    case 0x9C00:
        switch (a & 0xFF) {
        case 0xC9:
            *b = 210;
            *c = 1;
            break;
        default:
            *b = 0;
            *c = 0;
            break;
        }
        break;
    default:
        *b = 0;
        *c = 0;
        break;
    }
}

void func_0806BA0C(s16 v, u8* out) {
    s16 acc = 0;
    s16 div;
    s16 i;

    if (v >= 0) {
        div = 1000;

        for (i = 0; i < 4; i++) {
            u8* q = &out[i];
            *q = v / div - acc;
            acc = (acc + *q) * 10;
            div /= 10;
        }
    }
}

u16 func_0806BA74(s32 mode, s32 flag) {
    s32 i;

    gUnk_02034A88 = EwramAlloc(0xC00);

    for (i = 0; i < 128; i++) {
        gUnk_02034A88[i].unk_00 = 0;
        gUnk_02034A88[i].unk_04 = 0;
        gUnk_02034A88[i].unk_08 = NULL;
        gUnk_02034A88[i].unk_0C = NULL;
        gUnk_02034A88[i].unk_10 = NULL;
        gUnk_02034A88[i].unk_15 = 0;

        switch (mode) {
        case 0:
            gUnk_02034A88[i].unk_0C = LoadObjPalette(gUnk_09614758, 0x20);
            break;
        case 1:
            gUnk_02034A88[i].unk_0C = LoadObjPalette(gUnk_09614718, 0x20);
            break;
        case 2:
            gUnk_02034A88[i].unk_0C = LoadObjPalette(gUnk_09614738, 0x20);
            break;
        }

        if (flag == 0) {
            gUnk_02034A88[i].unk_10 = _08066468(3);
        } else {
            gUnk_02034A88[i].unk_10 = _08066468(5);
        }
        func_080062F4(gUnk_02034A88[i].unk_0C->unk_06 + 0x10, 1);
        func_080062F4(gUnk_02034A88[i].unk_10->unk_06 + 0x10, 1);
    }
    gUnk_02034A90 = 0;
    return gUnk_02034A88[0].unk_0C->unk_06;
}

u8 func_0806BB44(s32 x, s32 y, s32 s, s32* d) {
    s32 cx;
    s32 cy;
    s32 f;

    cx = 0;
    cy = 0;
    f = 0;

    if (gUnk_02034A88 == NULL) {
        return 0;
    }

    gUnk_02034A90 = 0;

    while (MSG_LATIN_CHAR(s) != 0) {
        s32 v;

        gUnk_02034A88[gUnk_02034A90].unk_00 = x + cx;
        gUnk_02034A88[gUnk_02034A90].unk_04 = y + cy;
        gUnk_02034A88[gUnk_02034A90].unk_15 = 1;

        if (MSG_LATIN_CHAR(s) == MSG_LATIN_CODE(0x4079, 29)) {
            f = 1;
            s += MSG_LATIN_STEP;
        }

        if (MSG_LATIN_CHAR(s) == MSG_LATIN_CODE(0x4000, 30)) {
            f = 0;
            s += MSG_LATIN_STEP;
        }

        if (MSG_LATIN_CHAR(s) == MSG_LATIN_CODE(10, 31)) {
            cx = 0;
            cy += 0xC00;
        } else {
#ifdef VERSION_EU
            v = MSG_LATIN_CHAR(s);
#else
            if ((u16)(MSG_LATIN_CHAR(s) - 32) <= 223) {
                v = MSG_LATIN_CHAR(s);
            } else {
                switch (MSG_LATIN_CHAR(s)) {
                case 0xE000:
                    v = 25;
                    break;
                case 0x2191:
                    v = 10;
                    break;
                case 0x2193:
                    v = 11;
                    break;
                case 0x2190:
                    v = 12;
                    break;
                case 0x2192:
                    v = 13;
                    break;
                case 0x300C:
                    v = 1;
                    break;
                case 0x300D:
                    v = 2;
                    break;
                case 0x300E:
                    v = 3;
                    break;
                case 0x300F:
                    v = 4;
                    break;
                case 0x203B:
                    v = 6;
                    break;
                case 0x266A:
                    v = 18;
                    break;
                case 0x2642:
                    v = 8;
                    break;
                case 0x2640:
                    v = 9;
                    break;
                case 0x2605:
                    v = 21;
                    break;
                case 0x25A0:
                    v = 17;
                    break;
                default:
                    v = 0;
                    break;
                }
            }

#endif
            gUnk_02034A88[gUnk_02034A90].unk_14 = f;

            if (gUnk_02034A88[gUnk_02034A90].unk_08 != NULL) {
                ReleaseObjTiles(gUnk_02034A88[gUnk_02034A90].unk_08);
                gUnk_02034A88[gUnk_02034A90].unk_08 = NULL;
            }

            cx += (s16)gUnk_08F7D438[v] << 8;

            if (v != 32) {
#ifdef VERSION_EU
                v = ((u16*)gUnk_09EEB204[v])[3];
                gUnk_02034A88[gUnk_02034A90].unk_08 = LoadObjTiles(&gUnkEu_0919B63A[v * 32], 128);
#else
                v = ((u16*)gUnk_09EEC134[v])[3];
                gUnk_02034A88[gUnk_02034A90].unk_08 = LoadObjTiles(&gUnk_090CBFB2[v * 32], 128);
#endif
            }

            gUnk_02034A90++;

            if (cx > 0x9B00) {
                cx = 0;
                cy += 0xC00;
            }
        }
        s += MSG_LATIN_STEP;

        if (cy > 0x1800) {
            *d = s;
            return gUnk_02034A90;
        }
    }

    *d = 0;
    return gUnk_02034A90;
}
#ifndef VERSION_EU
u8 func_0806BDB8(s32 x, s32 y, u8* s, u8** d) {
    u16 w;
    u8 t;
    s32 cx;
    s32 cy;
    s32 px;

    w = 0;
    t = 0;
    cx = 0;
    cy = 0;
    px = 0;

    if (gUnk_02034A88 == NULL) {
        return 0;
    }

    gUnk_02034A90 = 0;

    while (*s != 0) {
        u16 v;

        w = 0;
        gUnk_02034A88[gUnk_02034A90].unk_00 = x + cx;
        gUnk_02034A88[gUnk_02034A90].unk_04 = y + cy;
        gUnk_02034A88[gUnk_02034A90].unk_15 = 1;
        gUnk_02034A88[gUnk_02034A90].unk_14 = 0;

        if (*(u16*)s == 0x6E6E) {
            cx = 0;
            cy += 0xC00;
            s += 2;
        } else {
            v = *(u16*)s;
            v = (v / 256) | (v << 8);
            s += 2;

            if ((v & 0xFF00) == 0x8100) {
                switch (v & 0xFF) {
                case 0x40:
                    w = 0;
                    t = 0;
                    break;
                case 0x41:
                    w = 0xF5;
                    t = 0;
                    break;
                case 0x42:
                    w = 0xF6;
                    t = 0;
                    break;
                case 0x44:
                    w = 0xF7;
                    t = 0;
                    break;
                case 0x45:
                    w = 0xF9;
                    t = 0;
                    break;
                case 0x48:
                    w = 0xF1;
                    t = 0;
                    break;
                case 0x49:
                    w = 0xF0;
                    t = 0;
                    break;
                case 0x58:
                    w = 20;
                    t = 2;
                    break;
                case 0x5B:
                    w = 0xFD;
                    t = 0;
                    break;
                case 0x5C:
                    w = 0xFC;
                    t = 0;
                    break;
                case 0x60:
                    w = 0xFE;
                    t = 0;
                    break;
                case 0x63:
                    w = 0xFB;
                    t = 0;
                    break;
                case 0x75:
                    w = 0xE8;
                    t = 0;
                    break;
                case 0x76:
                    w = 0xE9;
                    t = 0;
                    break;
                case 0x77:
                    w = 0xEA;
                    t = 0;
                    break;
                case 0x78:
                    w = 0xEB;
                    t = 0;
                    break;
                case 0x66:
                    w = 0xFF;
                    t = 0;
                    break;
                case 0x69:
                    w = 0xEC;
                    t = 0;
                    break;
                case 0x6A:
                    w = 0xED;
                    t = 0;
                    break;
                case 0xA8:
                    w = 0xE7;
                    t = 0;
                    break;
                case 0xA9:
                    w = 0xE6;
                    t = 0;
                    break;
                case 0x7B:
                    w = 0xDF;
                    t = 0;
                    break;
                case 0x7C:
                    w = 0xFC;
                    t = 0;
                    break;
                case 0xA6:
                    w = 0xEE;
                    t = 0;
                    break;
                case 0x81:
                    w = 0xEF;
                    t = 0;
                    break;
                case 0x93:
                    w = 0xF2;
                    t = 0;
                    break;
                case 0x96:
                    w = 0xF4;
                    t = 0;
                    break;
                case 0x5E:
                    w = 0xF3;
                    t = 0;
                    break;
                case 0x43:
                    w = 0xF8;
                    t = 0;
                    break;
                case 0x9A:
                    w = 0x8E;
                    t = 0;
                    break;
                }

                if (gUnk_02034A90 != 0 &&
                    (v == 0x8141 || v == 0x8142 || v > 0x8177 || v == 0x8144 ||
                     (v == 0x8148 || v == 0x8149)) &&
                    cx == 0 && cy > 0) {
                    cx = px + 0xA00;
                    cy -= 0xC00;
                    gUnk_02034A88[gUnk_02034A90].unk_00 = x + cx;
                    gUnk_02034A88[gUnk_02034A90].unk_04 = y + cy;
                }
            } else {
                func_08066E40(v, &w, &t);
            }

            if (gUnk_02034A88[gUnk_02034A90].unk_08 != NULL) {
                ReleaseObjTiles(gUnk_02034A88[gUnk_02034A90].unk_08);
            }
            px = cx;
            cx += 0xA00;

            if (cx > 0x8C00) {
                cx = 0;
                cy += 0xC00;
            }

            switch (t) {
            case 0:
                w = ((u16*)gUnk_09EEB204[w])[3];
                gUnk_02034A88[gUnk_02034A90].unk_08 = LoadObjTiles(&gUnk_090AB5B2[w * 32], 128);
                break;
            case 1:
                w = ((u16*)gUnk_09EEB608[w])[3];
                gUnk_02034A88[gUnk_02034A90].unk_08 = LoadObjTiles(&gUnk_090B3FBE[w * 32], 128);
                break;
            case 2:
                w = ((u16*)gUnk_09EEBA0C[w])[3];
                gUnk_02034A88[gUnk_02034A90].unk_08 = LoadObjTiles(&gUnk_090BC9CA[w * 32], 128);
                break;
            case 3:
                w = ((u16*)gUnk_09EEBE10[w])[3];
                gUnk_02034A88[gUnk_02034A90].unk_08 = LoadObjTiles(&gUnk_090C51A6[w * 32], 128);
                break;
            }

            gUnk_02034A90++;
        }

        if (cy > 0x1800) {
            if (*s != 0) {
                v = *(u16*)s;

                if ((u16)((v / 256) | (v << 8)) == 0x8142) {
                    *d = 0;
                } else {
                    *d = s;
                    return gUnk_02034A90;
                }
            } else {
                *d = 0;
            }
        }
    }

    *d = 0;
    return gUnk_02034A90;
}
#endif

void func_0806C2C0(u8 n) {
    u8 i;

    for (i = 0; i < n; i++) {
        Ent080658B8* b = gUnk_02034A88;

        if (b[i].unk_15 == 1) {
            s32 x = b[i].unk_00;
            s32 y = b[i].unk_04;

            if (b[i].unk_08 != NULL) {
                if (b[i].unk_14 == 0) {
                    DrawSprite(x >> 8, y >> 8, gUnk_09EEB204[0], b[i].unk_08, b[i].unk_0C, 0, 0, 0);
                } else {
                    DrawSprite(x >> 8, y >> 8, gUnk_09EEB204[0], b[i].unk_08, b[i].unk_10, 0, 0, 0);
                }
            }
        }
    }
}

void func_0806C34C(void) {
    u8 i;

    for (i = 0; i < 128; i++) {
        if (gUnk_02034A88[i].unk_08 != NULL) {
            ReleaseObjTiles(gUnk_02034A88[i].unk_08);
        }

        if (gUnk_02034A88[i].unk_0C != NULL) {
            ReleaseObjPalette(gUnk_02034A88[i].unk_0C);
        }

        if (gUnk_02034A88[i].unk_10 != NULL) {
            ReleaseObjPalette(gUnk_02034A88[i].unk_10);
        }
    }
    EwramFree(gUnk_02034A88);
}

void _0806C3A0(u8 n, void* a) {
    u8 i;

    for (i = 0; i < n; i++) {
        Ent080658B8* b = gUnk_02034A84;

        if (b[i].unk_15 == 1) {
            s32 x = b[i].unk_00;
            s32 y = b[i].unk_04;

            if (b[i].unk_08 != NULL) {
                if (b[i].unk_14 == 0) {
                    func_08002488(x >> 8, y >> 8, gUnk_09EEB204[0], b[i].unk_08, a, 0);
                } else {
                    func_08002488(x >> 8, y >> 8, gUnk_09EEB204[0], b[i].unk_08,
                                  b[i].unk_10, 0);
                }
            }
        }
    }
}
u16 func_0806C42C(s16 v, u16* out) {
    u8 buf[8];
    u8* p;
    s32 i;

    buf[0] = (v & 0xF000) >> 12;
    buf[1] = (v & 0x0F00) >> 8;
    buf[2] = (v & 0x00F0) >> 4;
    buf[3] = v & 0xF;
    buf[4] = 0;
    p = buf;

    for (i = 0; i < 4; i++) {
        if (*p <= 9) {
            *p += 0x30;
        } else {
            *p += 0x37;
        }
        p++;
    }
    return func_0806692C(buf, out);
}
#ifndef VERSION_EU
#ifndef VERSION_JP
s32 func_0806C490(u16* a) {
#else
s32 func_0806C490(u8* a) {
#endif
    u8 buf[2];
    u16* c;
    u16 w;
    u8 t;
    u8* dst;
    u8 n;

    w = 0;
    dst = (u8*)0x06014000;
    t = 0;
    n = 0;

    while (*a != 0) {
        u16 v;

        buf[0] = a[0];
        buf[1] = a[1];
        c = (u16*)buf;

        if (*c == 0x6E6E) {
            a += 2;
        } else {
            v = *c;
            v = (v / 256) | (v << 8);
            a += 2;

            if ((v & 0xFF00) == 0x8100) {
                v &= 0xFF;

                switch (v) {
        case 0x40:
            w = 0;
            t = 0;
            break;
        case 0x41:
            w = 0xF5;
            t = 0;
            break;
        case 0x42:
            w = 0xF6;
            t = 0;
            break;
        case 0x45:
            w = 0xF9;
            t = 0;
            break;
        case 0x46:
            w = 0xFA;
            t = 0;
            break;
        case 0x48:
            w = 0xF1;
            t = 0;
            break;
        case 0x49:
            w = 0xF0;
            t = 0;
            break;
        case 0x58:
            w = 20;
            t = 2;
            break;
        case 0x5B:
            w = 0xFD;
            t = 0;
            break;
        case 0x5C:
            w = 0xFC;
            t = 0;
            break;
        case 0x60:
            w = 0xFE;
            t = 0;
            break;
        case 0x63:
            w = 0xFB;
            t = 0;
            break;
        case 0x75:
            w = 0xE8;
            t = 0;
            break;
        case 0x76:
            w = 0xE9;
            t = 0;
            break;
        case 0x77:
            w = 0xEA;
            t = 0;
            break;
        case 0x78:
            w = 0xEB;
            t = 0;
            break;
        case 0x66:
            w = 0xFF;
            t = 0;
            break;
        case 0x69:
            w = 0xEC;
            t = 0;
            break;
        case 0x6A:
            w = 0xED;
            t = 0;
            break;
        case 0xA8:
            w = 0xE7;
            t = 0;
            break;
        case 0xA9:
            w = 0xE6;
            t = 0;
            break;
        case 0x7B:
            w = 0xDF;
            t = 0;
            break;
        case 0x7C:
            w = 0xFC;
            t = 0;
            break;
        case 0xA6:
            w = 0xEE;
            t = 0;
            break;
        case 0x81:
            w = 0xEF;
            t = 0;
            break;
        case 0x93:
            w = 0xF2;
            t = 0;
            break;
        case 0x96:
            w = 0xF4;
            t = 0;
            break;
        case 0x5E:
            w = 0xF3;
            t = 0;
            break;
        case 0x43:
            w = 0xF8;
            t = 0;
            break;
        case 0x9A:
            w = 0x8E;
            t = 0;
            break;
                }
            } else {
                func_08066E40(v, &w, &t);
            }

            switch (t) {
        case 0:
            w = ((u16*)gUnk_09EEB204[w])[3];
            CpuSet(&gUnk_090AB5B2[w * 32], dst, 0x40);
            break;
        case 1:
            w = ((u16*)gUnk_09EEB608[w])[3];
            CpuSet(&gUnk_090B3FBE[w * 32], dst, 0x40);
            break;
        case 2:
            w = ((u16*)gUnk_09EEBA0C[w])[3];
            CpuSet(&gUnk_090BC9CA[w * 32], dst, 0x40);
            break;
        case 3:
            w = ((u16*)gUnk_09EEBE10[w])[3];
            CpuSet(&gUnk_090C51A6[w * 32], dst, 0x40);
            break;
            }

            dst += 128;
        }

        n++;
    }

    return n;
}
#endif
#ifndef VERSION_EU
#ifndef VERSION_JP
s32 func_0806C81C(u16* a, u16 b) {
#else
s32 func_0806C81C(u8* a, u16 b) {
#endif
    u8 buf[2];
    u16* c;
    u16 w;
    u8 t;
    u8* dst;
    u8 n;

    w = 0;
    dst = (u8*)0x06014000 + b * 32;
    t = 0;
    n = 0;

    while (*a != 0) {
        u16 v;

        buf[0] = a[0];
        buf[1] = a[1];
        c = (u16*)buf;

        if (*c == 0x6E6E) {
            a += 2;
        } else {
            v = *c;
            v = (v / 256) | (v << 8);
            a += 2;

            if ((v & 0xFF00) == 0x8100) {
                v &= 0xFF;

                switch (v) {
                case 0x40:
                    w = 0;
                    t = 0;
                    break;
                case 0x41:
                    w = 0xF5;
                    t = 0;
                    break;
                case 0x42:
                    w = 0xF6;
                    t = 0;
                    break;
                case 0x45:
                    w = 0xF9;
                    t = 0;
                    break;
                case 0x46:
                    w = 0xFA;
                    t = 0;
                    break;
                case 0x48:
                    w = 0xF1;
                    t = 0;
                    break;
                case 0x49:
                    w = 0xF0;
                    t = 0;
                    break;
                case 0x58:
                    w = 20;
                    t = 2;
                    break;
                case 0x5B:
                    w = 0xFD;
                    t = 0;
                    break;
                case 0x5C:
                    w = 0xFC;
                    t = 0;
                    break;
                case 0x60:
                    w = 0xFE;
                    t = 0;
                    break;
                case 0x63:
                    w = 0xFB;
                    t = 0;
                    break;
                case 0x75:
                    w = 0xE8;
                    t = 0;
                    break;
                case 0x76:
                    w = 0xE9;
                    t = 0;
                    break;
                case 0x77:
                    w = 0xEA;
                    t = 0;
                    break;
                case 0x78:
                    w = 0xEB;
                    t = 0;
                    break;
                case 0x66:
                    w = 0xFF;
                    t = 0;
                    break;
                case 0x69:
                    w = 0xEC;
                    t = 0;
                    break;
                case 0x6A:
                    w = 0xED;
                    t = 0;
                    break;
                case 0xA8:
                    w = 0xE7;
                    t = 0;
                    break;
                case 0xA9:
                    w = 0xE6;
                    t = 0;
                    break;
                case 0x7B:
                    w = 0xDF;
                    t = 0;
                    break;
                case 0x7C:
                    w = 0xFC;
                    t = 0;
                    break;
                case 0xA6:
                    w = 0xEE;
                    t = 0;
                    break;
                case 0x81:
                    w = 0xEF;
                    t = 0;
                    break;
                case 0x93:
                    w = 0xF2;
                    t = 0;
                    break;
                case 0x96:
                    w = 0xF4;
                    t = 0;
                    break;
                case 0x5E:
                    w = 0xF3;
                    t = 0;
                    break;
                case 0x43:
                    w = 0xF8;
                    t = 0;
                    break;
                case 0x9A:
                    w = 0x8E;
                    t = 0;
                    break;
                }
            } else {
                func_08066E40(v, &w, &t);
            }

            switch (t) {
            case 0:
                w = ((u16*)gUnk_09EEB204[w])[3];
                CpuSet(&gUnk_090AB5B2[w * 32], dst, 0x40);
                break;
            case 1:
                w = ((u16*)gUnk_09EEB608[w])[3];
                CpuSet(&gUnk_090B3FBE[w * 32], dst, 0x40);
                break;
            case 2:
                w = ((u16*)gUnk_09EEBA0C[w])[3];
                CpuSet(&gUnk_090BC9CA[w * 32], dst, 0x40);
                break;
            case 3:
                w = ((u16*)gUnk_09EEBE10[w])[3];
                CpuSet(&gUnk_090C51A6[w * 32], dst, 0x40);
                break;
            }

            dst += 128;
        }

        n++;
    }

    return n;
}
#endif
#if defined(VERSION_JP) || defined(VERSION_EU)
u8 func_0806CBAC(u8* a, u16* b, u16 tile) {
#else
u8 func_0806CBAC(u16* a, u16* b, u16 tile) {
#endif
    u8* dst = (u8*)0x06014000 + tile * 32;
    s32 flag = 0;
    gUnk_02034A90 = 0;
    *b = 0;
    while (*a != 0) {
        s32 v = 0;
#ifdef VERSION_EU
        if (*a == 31) {
#else
        if (*a == 10) {
#endif
            *b = 0;
        } else {
#ifdef VERSION_EU
            v = *a;
#else
#ifdef VERSION_JP
            if (*a > 31) {
#else
            if ((u16)(*a - 32) <= 223) {
#endif
                v = *a;
            } else {
                switch (*a) {
                case 0xE000:
                    v = 25;
                    break;
                case 0x2191:
                    v = 10;
                    break;
                case 0x2193:
                    v = 11;
                    break;
                case 0x2190:
                    v = 12;
                    break;
                case 0x2192:
                    v = 13;
                    break;
                case 0x300C:
                    v = 1;
                    break;
                case 0x300D:
                    v = 2;
                    break;
                case 0x300E:
                    v = 3;
                    break;
                case 0x300F:
                    v = 4;
                    break;
                case 0x203B:
                    v = 6;
                    break;
                case 0x266A:
                    v = 18;
                    break;
                case 0x2642:
                    v = 8;
                    break;
                case 0x2640:
                    v = 9;
                    break;
                case 0x2605:
                    v = 21;
                    break;
                case 0x25A0:
                    v = 17;
                    break;
                default:
                    v = 0;
                    break;
                }
            }
#endif
            if (v != 32) {
                *b = gUnk_08F7D438[v];
#ifdef VERSION_EU
                v = ((u16*)gUnk_09EEB204[v])[3];
                CpuSet(&gUnkEu_0919B63A[v * 32], dst, 0x40);
#else
                v = ((u16*)gUnk_09EEC134[v])[3];
                CpuSet(&gUnk_090CBFB2[v * 32], dst, 0x40);
#endif
                dst += 128;
                gUnk_02034A90++;
                b++;
                flag = 1;
            } else if (flag != 0) {
                b[-1] += 3;
            }
        }
        a++;
    }
    return gUnk_02034A90;
}
void func_0806CD30(s32 a) {
    switch (a) {
    case 0:
        LoadBgPalette(0, gUnk_096145D8, 0x40);
        break;
    case 1:
        LoadBgPalette(0, gUnk_09614618, 0x40);
        break;
    }
}
#ifdef VERSION_JP
#define MSG_CONT_BG_TILES 0x1A40
#define MSG_CONT_X 0xA400
#else
#define MSG_CONT_BG_TILES 0x1AA0
#define MSG_CONT_X 0xBC00
#endif

void func_0806CD60(ContinueWork* p) {
    u8 i;

    SetBgMode1();
    p->unk_60 = 0;
    SetBackdropColor(0, 0, 0);
    SetupBg(0, 0, 31, 0);
    SetupBg(2, 2, 28, 10);
    SetBgPriority(2, 0);
    SetBgPriority(0, 1);
    SetBgPriority(1, 2);
#ifdef VERSION_EU
    eu_080059D4(0, gUnkEu_09F5D7E4[gLanguage]);
    eu_080059F4(0, gUnkEu_095A3D74);
#else
    LoadBgTiles(0, gUnk_0941A418, MSG_CONT_BG_TILES);
    LoadBgMap(0, gUnk_0951CAB8, 0x800);
#endif
    func_080065FC(2, 0x8000, 128);
    func_08006778(gUnk_09EDA7E0, 120, 46);
    func_08006B34(0);
    p->tiles3 = LoadObjTiles(gUnk_090A7D9A, 192);
    p->palette3 = LoadObjPalette(gUnk_096146F8, 32);
    func_0806CD30(p->unk_60);
    p->tiles = AllocObjTiles(512, 0);
    PushPaletteEffect(0);
    p->palette = LoadObjPalette(gUnk_09614658, 160);
    PopPaletteEffect();
    func_08002A10(p->tiles, gUnk_090A6B26);
    AnimInit(&p->unk_20, gUnk_09EEB108, gUnk_09EEB0C4);
    AnimStart(&p->unk_20, 0, 1);
    p->tiles2 = AllocObjTiles(1024, 0);
    p->palette2 = LoadObjPalette(gUnk_08F683A4, 32);
    func_08002A10(p->tiles2, gUnk_090A7F0A);
    AnimInit(&p->unk_38, gUnk_09EEB14C, gUnk_09EEB11C);
    AnimStart(&p->unk_38, 0, 1);
    p->unk_58 = -2048;
    p->unk_5C = 0xA000;
    p->unk_6B = 16;
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
    case 1:
    case 4:
    case 5:
    case 6:
        p->unk_50 = 0xBC00;
        break;
    case 2:
    case 3:
        p->unk_50 = 0xC000;
        break;
    }
#else
    p->unk_50 = MSG_CONT_X;
#endif
    p->unk_54 = 0x4000;
    p->unk_64 = 0;
    p->unk_66 = 0;
    func_08006120(1, 24);

    for (i = 0; i < 5; i++) {
        func_080062F4(((Handle0806180C*)p->palette)->unk_06 + i, 0);
    }
    p->unk_66 = 0x1000;
    p->unk_6A = 0;
}
void func_0806CF04(ContinueWork* p) {
    u8 i;

    SetBgMode1();
    p->unk_60 = 0;
    SetBackdropColor(0, 0, 0);
    SetupBg(0, 0, 31, 0);
    SetupBg(2, 2, 28, 10);
    SetBgPriority(2, 0);
    SetBgPriority(0, 1);
    SetBgPriority(1, 2);
#ifdef VERSION_EU
    eu_080059D4(0, gUnkEu_09F5D7E4[gLanguage]);
    eu_080059F4(0, gUnkEu_095A3D74);
#else
    LoadBgTiles(0, gUnk_0941A418, MSG_CONT_BG_TILES);
    LoadBgMap(0, gUnk_0951CAB8, 0x800);
#endif
    func_080065FC(2, 0x8000, 128);
    func_08006778(gUnk_09EDA7E0, 120, 46);
    func_08006B34(0);
    p->tiles3 = LoadObjTiles(gUnk_090A7D9A, 192);
    p->palette3 = LoadObjPalette(gUnk_096146F8, 32);
    func_0806CD30(p->unk_60);
    p->tiles = AllocObjTiles(512, 0);
    PushPaletteEffect(0);
    p->palette = LoadObjPalette(gUnk_09614658, 160);
    PopPaletteEffect();
    func_08002A10(p->tiles, gUnk_090A6B26);
    AnimInit(&p->unk_20, gUnk_09EEB108, gUnk_09EEB0C4);
    AnimStart(&p->unk_20, 0, 1);
    p->tiles2 = AllocObjTiles(1024, 0);
    p->palette2 = LoadObjPalette(gUnk_09618118, 32);
    func_08002A10(p->tiles2, gUnk_090A8FC4);
    AnimInit(&p->unk_38, gUnk_09EEB180, gUnk_09EEB150);
    AnimStart(&p->unk_38, 0, 1);
    p->unk_58 = -2048;
    p->unk_5C = 0xA000;
    p->unk_6B = 16;
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
    case 1:
    case 4:
    case 5:
    case 6:
        p->unk_50 = 0xBC00;
        break;
    case 2:
    case 3:
        p->unk_50 = 0xC000;
        break;
    }
#else
    p->unk_50 = MSG_CONT_X;
#endif
    p->unk_54 = 0x4000;
    p->unk_64 = 0;
    p->unk_66 = 0;
    func_08006120(1, 24);

    for (i = 0; i < 5; i++) {
        func_080062F4(((Handle0806180C*)p->palette)->unk_06 + i, 0);
    }
    p->unk_66 = 0x1000;
    p->unk_6A = 0;
}
s32 func_0806D0A8(ContinueWork* p) {
    s32* t;

    func_08006954();
    p->gfx = AnimUpdate(&p->unk_20);
    p->gfx2 = AnimUpdate(&p->unk_38);
    gBldCnt = 0xB54;
    gBldAlpha = p->unk_66;

    if (p->unk_6A == 0) {
        if (func_08006314() == 0) {
            p->unk_6A = 1;
        }
    }

    if (p->unk_6A == 1) {
        if (p->unk_6B > 0) {
            ApproachValue(&p->unk_58, 0, p->unk_6B);
            ApproachValue(&p->unk_5C, 0x9800, p->unk_6B);
            p->unk_6B--;
        }

        if (p->unk_66 < 0x1010) {
            p->unk_66++;
        } else {
            p->unk_66 = 0x1010;
        }

        if ((GetKeysPressed() & 0x40) != 0) {
            if (p->unk_60 == 1) {
                p->unk_60 = 0;
                m4aSongNumStart(101);
            }
        }

        if ((GetKeysPressed() & 0x80) != 0) {
            if (p->unk_60 == 0) {
                p->unk_60 = 1;
                m4aSongNumStart(101);
            }
        }

        if ((GetKeysHeld() & 1) != 0) {
            switch (p->unk_60) {
            case 0:
                func_08006184(0, 96);
                break;
            case 1:
                func_08006184(0, 96);
                break;
            }

            m4aSongNumStart(102);
            p->unk_6A = 2;
            p->unk_6B = 16;
        }
    }

    if (p->unk_6A == 2) {
        if (p->unk_6B > 0) {
            ApproachValue(&p->unk_58, -2048, p->unk_6B);
            ApproachValue(&p->unk_5C, 0xA000, p->unk_6B);
            p->unk_6B--;
        }

        if (p->unk_66 > 0x1000) {
            p->unk_66--;
        } else {
            p->unk_66 = 0x1000;
        }

        if (func_08006314() == 0) {
            DisableBg(0);
            DisableBg(2);
            LoadBgMap(0, gUnk_08125E24, 0x800);
            LoadBgMap(2, gUnk_08125E24, 0x800);
            p->unk_6A = 3;
        }
    }

    func_0806CD30(p->unk_60);
    t = &gUnk_08F7DAC4[14];
    p->unk_54 += (t[p->unk_60] - p->unk_54) >> 3;
    p->unk_64 += 4;
}
void func_0806D288(ContinueWork* p) {
    DrawSprite(p->unk_50 >> 8, p->unk_54 >> 8, p->gfx, p->tiles, p->palette, 0, 4, 100);
    DrawSprite(120, 120, p->gfx2, p->tiles2, p->palette2, 0, 0, 100);
}
void Continue_3(ContinueWork* p) {
    DisableBg(0);
    DisableBg(2);
    LoadBgMap(0, gUnk_08125E24, 0x800);
    LoadBgMap(2, gUnk_08125E24, 0x800);
    ReleaseObjTiles(p->tiles2);
    ReleaseObjPalette(p->palette2);
    ReleaseObjPalette(p->palette);
    ReleaseObjTiles(p->tiles);
    ReleaseObjTiles(p->tiles3);
    ReleaseObjPalette(p->palette3);
    gBldCnt = 0;
}
void event_seq_0(EventSeqWork* work, u8* a) {
#ifdef VERSION_EU
    Ent09EE3CA0* u;
#endif

    gUnk_02039DD0 = NULL;
    gBtlWork = NULL;
    work->unk_28 = 0;
    work->unk_2C = a[0];
    work->unk_2E = a[1];
    work->unk_34 = gUnk_09EE3FB4[work->unk_2C];
    work->unk_30 = 0;
    work->unk_31 = 0;
    gUnk_02039DC8->unk_8A = 0;
    work->unk_2F = 0;
    work->unk_32 = 0;
#ifdef VERSION_EU
    work->unk_3D = 0;
    work->unk_3A = 0;
    work->unk_3B = 0;
    work->unk_3C = 0;
#endif

    if (gUnk_02039DC8 != NULL) {
        gUnk_02039DC8->unk_7A = 1;
        gUnk_02039DC8->unk_7B = 0;
        gUnk_02039DC8->unk_78 = 0;
        gUnk_02039DC8->unk_79 = 0;
        gUnk_02039DC8->unk_7F = 0;
        gUnk_02039DC8->unk_68 = 0;
        gUnk_02039DC8->unk_6A = 0;
        gUnk_02039DC8->unk_80 = 0;
        gUnk_02039DC8->unk_82 = 0;
        gUnk_02039DC8->unk_84 = 0;
        gUnk_02039DC8->unk_85 = 0;
        gUnk_02039DC8->unk_83 = 0;
#ifndef VERSION_EU
        func_0800443C(GetBgCharBase(1), 0x8000);
#endif

        if (work->unk_34->unk_08->unk_14 & 0x80) {
            SetBackdropColor(31, 31, 31);
            func_08006120(1, 0x40);
        }
#ifdef VERSION_EU
        u = gUnk_09EE3CA0[work->unk_2C];
        if (u != NULL) {
            if (u->unk_04 != NULL) {
                if ((u->unk_2D & 1) != 0) {
                    SetupBg(0, 3, 31, 14);
                    SetupBg(1, 0, 29, 0);
                    SetupBg(2, 2, 30, 0);
                    SetupBg(3, 0, 28, 0);
                } else {
                    SetupBg(0, 3, 31, 14);
                    SetupBg(1, 2, 30, 0);
                    SetupBg(2, 0, 22, 0);
                    SetupBg(3, 0, 23, 0);
                }
            }
            if (u->unk_24 != 0) {
                if (u->unk_2E[0] == 1 || u->unk_2E[0] == 3) {
                    eu_080059D4(2, u->unk_00);
                } else {
                    LoadBgTiles(2, u->unk_00, u->unk_18);
                }
                LoadBgPalette(2, u->unk_08, u->unk_1C);
                SetBgColorMode(2, 128);
                SetBgSize(2, 0x8000);
                if (u->unk_2E[0] == 2 || u->unk_2E[0] == 3) {
                    eu_080059F4(2, *u->unk_0C);
                } else {
                    LoadBgMap(2, *u->unk_0C, 0x1000);
                }
                SetBgAffine(2, 0, 256, 256, 0, 0);
            } else {
                eu_0806C734(work);
                eu_0806C7C8(work);
                eu_0806C848(work);
            }
        }
        if ((work->unk_34->unk_08->unk_14 & 0xFF0) == 0) {
            func_08006120(0, 64);
        } else if ((work->unk_34->unk_08->unk_14 & 0xFF0) == 0x80) {
            func_08006120(1, 120);
        }
        work->unk_38 = 0;
        eu_0806C974(work);
#endif
    }
}

#ifdef VERSION_EU
u8 eu_0806C734(EventSeqWork* work) {
    Ent09EE3CA0* u = gUnk_09EE3CA0[work->unk_2C];
    if (u != NULL) {
        if (u->unk_2E[0] == 1 || u->unk_2E[0] == 3) {
            eu_080059D4(3, u->unk_00);
        } else {
            LoadBgTiles(3, u->unk_00, u->unk_18);
        }
        LoadBgPalette(3, u->unk_08, u->unk_1C);
        if (u->unk_0C != NULL) {
            if (u->unk_2E[0] == 2 || u->unk_2E[0] == 3) {
                work->unk_3A = 1;
                eu_08005A1C(3, u->unk_0C, u->unk_1E, u->unk_1F);
            } else {
                work->unk_3A = 0;
                func_0800516C(3, u->unk_0C, u->unk_1E, u->unk_1F);
            }
            func_080051C4(3, 0, 0);
        }
    }
    return 1;
}
u8 eu_0806C7C8(EventSeqWork* work) {
    Ent09EE3CA0* u = gUnk_09EE3CA0[work->unk_2C];
    if (u != NULL) {
        if (u->unk_10 != NULL) {
            if (u->unk_2E[0] == 2 || u->unk_2E[0] == 3) {
                work->unk_3B = 1;
                eu_08005A1C(2, u->unk_10, u->unk_1E, u->unk_1F);
            } else {
                work->unk_3B = 0;
                func_0800516C(2, u->unk_10, u->unk_1E, u->unk_1F);
            }
            func_080051C4(2, 0, 0);
            gUnk_02039DC8->unk_78 = 1;
        } else {
            DisableBg(2);
        }
    }
    return 1;
}
u8 eu_0806C848(EventSeqWork* work) {
    Ent09EE3CA0* u = gUnk_09EE3CA0[work->unk_2C];
    if (u != NULL) {
        if (u->unk_04 != NULL) {
            if ((u->unk_2D & 1) != 0) {
                LoadBgTiles(2, u->unk_04, u->unk_1A);
            } else if (u->unk_2E[0] == 1 || u->unk_2E[0] == 3) {
                eu_080059D4(1, u->unk_04);
            } else {
                LoadBgTiles(1, u->unk_04, u->unk_1A);
            }
        }
        if (u->unk_14 != NULL) {
            if ((u->unk_2D & 2) != 0) {
                gBldCnt = 0x1844;
                gBldAlpha = 0x050E;
                SetBgPriority(2, 1);
                gUnk_02039DC8->unk_6E = 0x1D42;
                gUnk_02039DC8->unk_70 = 0x050E;
            } else {
                gUnk_02039DC8->unk_6E = 0;
                gUnk_02039DC8->unk_70 = 0;
            }
            if (u->unk_2E[0] == 2 || u->unk_2E[0] == 3) {
                work->unk_3C = 1;
                eu_08005A1C(1, u->unk_14, u->unk_1E, u->unk_1F);
            } else {
                work->unk_3C = 0;
                func_0800516C(1, u->unk_14, u->unk_1E, u->unk_1F);
            }
            func_080051C4(1, 0, 0);
            gUnk_02039DC8->unk_79 = 1;
        } else {
            DisableBg(1);
        }
    }
    return 1;
}
u8 eu_0806C974(EventSeqWork* work) {
    Ent09EE3CA0* u = gUnk_09EE3CA0[work->unk_2C];
    Obj0806180C* q = work->unk_34->unk_08;
    u16 i;
    gUnk_02039DC8->unk_50 = q->unk_04;
    gUnk_02039DC8->unk_54 = q->unk_08;
    gUnk_02039DC8->unk_48 = gUnk_02039DC8->unk_50 - 0x7800;
    gUnk_02039DC8->unk_4C = gUnk_02039DC8->unk_54 - 0x5000;
    gUnk_02039DC8->unk_64 = 0;
    gUnk_02039DC8->unk_6C = 0;
    gUnk_02039DC8->unk_7C = 0;
    gUnk_02039DC8->unk_87 = 0;
    gUnk_02039DC8->unk_81 = 0;
    gUnk_02039DC8->unk_88 = 0;
    gUnk_02039DC8->unk_89 = 0;
    gUnk_02039DC8->unk_7D = 0;
    gUnk_02039DC8->unk_7E = 0;
    gUnk_02039DC8->unk_60 = 0;
    if (u->unk_20 != 5) {
        gUnk_02039DC8->unk_44 = u->unk_20;
        work->unk_3D = 1;
    } else {
        gUnk_02039DC8->unk_44 = u->unk_20;
    }
    for (i = 0; i < 16; i++) {
        gUnk_02039DC8->unk_00[i] = NULL;
    }
    return 1;
}
#endif
u8 event_seq_1(EventSeqWork* work, void* a) {
    EventSeqArg arg;
#ifndef VERSION_EU
    s32 flag;
#endif
    Ent09EE3CA0* u;
    UnkStruct_09EE3FB4* t;
#ifndef VERSION_EU
    Obj0806180C* q;
    u16 i;
#endif
    u8 j;

#ifndef VERSION_EU
    flag = 0;
#endif
    u = gUnk_09EE3CA0[work->unk_2C];
#ifndef VERSION_EU

    if (u != NULL) {
        if (u->unk_04 != NULL) {
            if ((u->unk_2D & 1) != 0) {
                SetupBg(0, 3, 31, 14);
                SetupBg(1, 0, 29, 0);
                SetupBg(2, 2, 30, 0);
                SetupBg(3, 0, 28, 0);
            } else {
                SetupBg(0, 3, 31, 14);
                SetupBg(1, 2, 30, 0);
                SetupBg(2, 0, 22, 0);
                SetupBg(3, 0, 23, 0);
            }
        }

        if (u->unk_24 != 0) {
            LoadBgTiles(2, u->unk_00, u->unk_18);
            LoadBgPalette(2, u->unk_08, u->unk_1C);
            SetBgColorMode(2, 128);
            SetBgSize(2, 0x8000);
            LoadBgMap(2, *u->unk_0C, 0x1000);
            SetBgAffine(2, 0, 256, 256, 0, 0);
        } else {
            LoadBgTiles(3, u->unk_00, u->unk_18);
            LoadBgPalette(3, u->unk_08, u->unk_1C);

            if (u->unk_04 != NULL) {
                if ((u->unk_2D & 1) != 0) {
                    LoadBgTiles(2, u->unk_04, u->unk_1A);
                } else {
                    LoadBgTiles(1, u->unk_04, u->unk_1A);
                }
            }

            if (u->unk_0C != NULL) {
                func_0800516C(3, u->unk_0C, u->unk_1E, u->unk_1F);
                func_080051C4(3, 0, 0);
            }

            if (u->unk_10 != NULL) {
                func_0800516C(2, u->unk_10, u->unk_1E, u->unk_1F);
                func_080051C4(2, 0, 0);
                gUnk_02039DC8->unk_78 = 1;
            } else {
                DisableBg(2);
            }

            if (u->unk_14 != NULL) {
                if ((u->unk_2D & 2) != 0) {
                    gBldCnt = 0x1844;
                    gBldAlpha = 0x050E;
                    SetBgPriority(2, 1);
                    gUnk_02039DC8->unk_6E = 0x1D42;
                    gUnk_02039DC8->unk_70 = 0x050E;
                } else {
                    gUnk_02039DC8->unk_6E = 0;
                    gUnk_02039DC8->unk_70 = 0;
                }

                func_0800516C(1, u->unk_14, u->unk_1E, u->unk_1F);
                func_080051C4(1, 0, 0);
                gUnk_02039DC8->unk_79 = 1;
            } else {
                DisableBg(1);
            }
        }
    }

    q = work->unk_34->unk_08;
    gUnk_02039DC8->unk_50 = q->unk_04;
    gUnk_02039DC8->unk_54 = q->unk_08;
    gUnk_02039DC8->unk_48 = gUnk_02039DC8->unk_50 - 0x7800;
    gUnk_02039DC8->unk_4C = gUnk_02039DC8->unk_54 - 0x5000;
    gUnk_02039DC8->unk_64 = 0;
    gUnk_02039DC8->unk_6C = 0;
    gUnk_02039DC8->unk_7C = 0;
    gUnk_02039DC8->unk_87 = 0;
    gUnk_02039DC8->unk_81 = 0;
    gUnk_02039DC8->unk_88 = 0;
    gUnk_02039DC8->unk_89 = 0;
    gUnk_02039DC8->unk_7D = 0;
    gUnk_02039DC8->unk_7E = 0;
    gUnk_02039DC8->unk_60 = 0;

    if (u->unk_20 != 5) {
        gUnk_02039DC8->unk_44 = u->unk_20;
        flag = 1;
    } else {
        gUnk_02039DC8->unk_44 = 5;
    }

    i = 0;
    t = work->unk_34;

    while (i < 16) {
        gUnk_02039DC8->unk_00[i] = NULL;
        i++;
    }

#else
    t = work->unk_34;
#endif

    TaskPoolInit(&work->unk_00, t->unk_00 + 8);
    TaskPoolInit(&work->unk_14, 1);
    work->unk_28 = (u32)TaskCreate(&work->unk_14, gTaskDescMsgwin, &work->unk_2C);

    for (j = 0; j < t->unk_00; j++) {
        arg.unk_00 = work->unk_2C;
        arg.unk_02 = t->unk_04[j].unk_04;
        arg.unk_03 = j;

        if (arg.unk_02 > 94) {
            work->unk_32 = 1;
            gUnk_02039DC8->unk_60 = arg.unk_02;
        }

        TaskCreate(&work->unk_00, gTaskDescEventChara, &arg);
    }

    TaskCreate(&work->unk_00, gTaskDescView, &work->unk_2C);
    TaskCreate(&work->unk_00, gTaskDescEvSound, &work->unk_2C);
    TaskCreate(&work->unk_00, gTaskDescEVBGEFFECT, &work->unk_2C);

#ifdef VERSION_EU
    if (work->unk_3D != 0) {
#else
    if (flag != 0) {
#endif
        TaskCreate(&work->unk_00, gTaskDescMapAnim, NULL);
    }

#ifndef VERSION_EU
    if ((work->unk_34->unk_08->unk_14 & 0xFF0) == 0) {
        func_08006120(0, 64);
    } else if ((work->unk_34->unk_08->unk_14 & 0xFF0) == 0x80) {
        func_08006120(1, 120);
    }

    work->unk_38 = 0;
#endif

    if (u != NULL) {
        if (u->unk_28 != 0) {
            TaskCreate(&work->unk_00, gTaskDescEvMapObj, &work->unk_2C);
        }

        if ((u->unk_2D & 1) != 0) {
            func_080CA35C();
            TaskCreate(&work->unk_00, gTaskDescPooMapanime, NULL);
        }
    }

    SetTaskUpdate(a, (void*)func_0806D830);
    return 1;
}
u8 func_0806D808(void) {
    u8 r = func_08006314();
    u8 v;

    if (r != 0) {
        v = 1;
    } else {
        gUnk_02039DC8->unk_7A = 0;
        m4aMPlayAllStop();
        v = 0;
    }
    return v;
}
u8 func_0806D830(EventSeqWork* p, void* a) {
    UnkStruct_09EE3FB4* t;
    u8 i;

    if (gUnk_02039DC8 == NULL) {
        return 0;
    }

    if ((GetKeysHeld() & 8) != 0) {
        switch (p->unk_2C) {
        case 68:
        case 83:
        case 84:
            break;
        default:
            gUnk_02039DC8->unk_8A++;
            break;
        }
    } else {
        gUnk_02039DC8->unk_8A = 0;
    }

    if (gUnk_02039DC8->unk_8A > 64 || gUnk_02039DC8->unk_83 == 1) {
        gUnk_02039DC8->unk_8A = 64;
        p->unk_2F = 1;
        gUnk_02039DC8->unk_82 = 1;
        func_08006184(0, 64);
        SetTaskUpdate(a, (u32)func_0806D808);

        for (i = 0; i < 32; i++) {
            func_080062F4(i, 0);
        }
        return 1;
    }

    if (p->unk_38 == p->unk_34->unk_24) {
        gUnk_02039DC8->unk_64 |= 2;
    } else {
        s32 t = p->unk_34->unk_08->unk_14 & 0xFF0;

        if (t == 0) {
            func_08006120(0, 64);
        } else if (t == 128) {
            func_08006120(1, 120);
        }
        p->unk_38++;
    }
    TaskPoolUpdate(&p->unk_00);
    TaskPoolUpdate(&p->unk_14);

    if (p->unk_32 != 0) {
        gBtlWork->unk_000 = gUnk_02039DC8->unk_48;
        gBtlWork->unk_004 = gUnk_02039DC8->unk_4C;
    }

    if ((gUnk_02039DC8->unk_64 & 3) == 2) {
        gUnk_02039DC8->unk_6C++;
    }

    t = gUnk_09EE3FB4[p->unk_2C];

    if (gUnk_02039DC8->unk_6C >= t->unk_18 && p->unk_2F == 0 && func_08006314() == 0) {
        if (gUnk_02039DC8->unk_7F == 0) {
            func_08006184(0, 64);
        }
        p->unk_2F = 1;
        gUnk_02039DC8->unk_82 = 1;
    }

    if (p->unk_2F == 1) {
        for (i = 0; i < 32; i++) {
            func_080062F4(i, 0);
        }

        if (func_08006314() == 0) {
            gUnk_02039DC8->unk_7A = 0;
            return 0;
        }
    }
    return 1;
}
void event_seq_2(EventSeqWork* p) {
    TaskPoolDraw(&p->unk_14);

    if (p->unk_32 != 0) {
        TaskPoolDraw(&gBtlWork->taskPools[0]);
    }
    TaskPoolDraw(&p->unk_00);
}
void event_seq_3(EventSeqWork* p) {
    TaskPoolDestroy(&p->unk_00);

    if (p->unk_28 != 0) {
        TaskPoolDestroy(&p->unk_14);
    }
#ifdef VERSION_EU
    if (p->unk_3A != 0) {
        eu_08005ADC(3);
    }

    if (p->unk_3B != 0) {
        eu_08005ADC(2);
    }

    if (p->unk_3C != 0) {
        eu_08005ADC(1);
    }
#endif
}
void event_chara_0(Work0806180C* p, u32* a) {
    s32 v0;
    s32 v1;

    TaskPoolInit(&p->unk_010, 8);
    *(s32*)&p->unk_024 = *a;
    p->unk_000 = gUnk_09EE3FB4[p->unk_024]->unk_04[p->unk_027].unk_00;
    p->unk_1A0 = 0;
    p->unk_1A4 = p->unk_000->unk_04;
    p->unk_188 = 0;
    p->unk_18C = 0;
    p->unk_198 = 0;
    p->unk_1A9 = 0;
    p->unk_1AA = 0;
    p->unk_180 = 0;
    p->unk_184 = 0;
    p->tiles = NULL;
    p->palette = NULL;
    p->gfx = NULL;
    p->unk_1B1 = 0;
    p->unk_1B2 = 0;
    p->unk_1B3 = 0;
    p->unk_1B5 = 0;
    p->unk_1B0 = 0;
    p->unk_1B6 = 1;
    p->unk_1B8 = 0;
    gUnk_02039DC8->unk_00[p->unk_027] = (Ent08074EC8*)p->unk_028;

    switch (p->unk_026) {
    case 95:
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        gBtlWork->unk_068 = 0;
        p->unk_1B3 = 1;
        gBtlWork->unk_000 = gUnk_02039DC8->unk_48;
        gBtlWork->unk_004 = gUnk_02039DC8->unk_4C;
        gBtlWork->unk_024 = 0x100;
        gBtlWork->unk_018 = 0;
        gBtlWork->unk_028 = 0x100;
        gBtlWork->unk_008 = gUnk_02039DC8->unk_48;
        gBtlWork->unk_00C = gUnk_02039DC8->unk_4C;
        gBtlWork->unk_010 = 0x10000;
        gBtlWork->unk_014 = 0x14000;
        gBtlWork->unk_01C = 0x10000;
        gBtlWork->unk_020 = 0x14000;
        gBtlWork->unk_01A = 15;
        p->unk_02C = p->unk_000->unk_08;
        p->unk_030 = p->unk_000->unk_0C;
        p->unk_034 = p->unk_000->unk_10;
        TaskCreate(&p->unk_010, gTaskDescBosTm, p->unk_028);
        break;
    case 96:
        gBtlWork = EwramAlloc(464);
        SetBgPriority(0, 2);
        SetBgPriority(1, 1);
        SetBgPriority(2, 0);
        BtlWorkInit();
        gBtlWork->unk_07C = (BtlObj*)p->unk_054;
        gBtlWork->unk_068 = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        gBtlWork->unk_004 = 0x5400;
        gBtlWork->unk_024 = 0x100;
        gBtlWork->unk_018 = 0;
        func_0801A920(128, 424, 294, 384);
        gUnk_02039DC8->unk_00[16] = TaskCreate(&p->unk_010, gTaskDescBosPc, NULL);
        break;
    case 97:
        gBtlWork = EwramAlloc(464);
        SetBgPriority(0, 2);
        SetBgPriority(1, 1);
        SetBgPriority(2, 0);
        BtlWorkInit();
        gBtlWork->unk_07C = (BtlObj*)p->unk_054;
        gBtlWork->unk_068 = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        gBtlWork->unk_004 = 0x5400;
        gBtlWork->unk_024 = 0x100;
        gBtlWork->unk_018 = 0;
        func_0801A920(128, 424, 294, 384);
        gUnk_02039DC8->unk_00[16] = TaskCreate(&p->unk_010, gTaskDescBosPc, &p->unk_010);
        p->unk_1B4 = 0;
        gUnk_02039DC8->unk_48 = v0 = gBtlWork->unk_000;
        gUnk_02039DC8->unk_4C = v1 = gBtlWork->unk_004;
        gUnk_02039DC8->unk_50 = gBtlWork->unk_008;
        gUnk_02039DC8->unk_54 = gBtlWork->unk_00C;
        gUnk_02039DC8->unk_58 = v0;
        gUnk_02039DC8->unk_5C = v1;
        break;
    case 100:
        SetBgSize(1, 0x4000);
        SetBgPriority(0, 2);
        SetBgPriority(1, 1);
        SetBgPriority(2, 0);
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        gBtlWork->unk_07C = (BtlObj*)p->unk_054;
        gBtlWork->unk_068 = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        gBtlWork->unk_004 = 0x5400;
        gBtlWork->unk_024 = 0x100;
        gBtlWork->unk_018 = 0;
        func_0801A920(128, 368, 480, 512);
        gUnk_02039DC8->unk_00[16] = TaskCreate(&p->unk_010, gTaskDescBosLst, &p->unk_010);
        break;
    case 101:
        SetupBg(0, 0, 24, 0);
        SetupBg(1, 0, 26, 0);
        SetupBg(2, 2, 28, 14);
        SetBgPriority(0, 2);
        SetBgPriority(1, 1);
        SetBgPriority(2, 0);
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        gBtlWork->unk_07C = (BtlObj*)p->unk_054;
        gBtlWork->unk_068 = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        gBtlWork->unk_008 = 0x26600;
        gBtlWork->unk_00C = 0x12800;
        gBtlWork->unk_000 = 0x26600;
        gBtlWork->unk_004 = 0x12800;
        gBtlWork->unk_010 = 0x26600;
        gBtlWork->unk_014 = 0x12800;
        p->unk_02C = 0x2A200;
        p->unk_030 = 0x15E00;
        p->unk_034 = -0x3800;
        func_0801A920(420, 612, 328, 384);
        TaskCreate(&p->unk_010, gTaskDescBosJf, p->unk_028);
        break;
    case 103:
        SetupBg(0, 0, 24, 0);
        SetupBg(1, 0, 26, 0);
        SetupBg(2, 2, 28, 14);
        SetBgPriority(0, 2);
        SetBgPriority(1, 1);
        SetBgPriority(2, 0);
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        gBtlWork->unk_068 = 0;
        p->unk_1B3 = 1;
        gBtlWork->unk_008 = 0x12C00;
        gBtlWork->unk_00C = 0x16800;
        gBtlWork->unk_000 = 0x12C00;
        gBtlWork->unk_004 = 0x16800;
        gBtlWork->unk_010 = 0x12C00;
        gBtlWork->unk_014 = 0x16800;
        gUnk_02039DC8->unk_48 = gBtlWork->unk_008 - 0x7800;
        gUnk_02039DC8->unk_4C = gBtlWork->unk_00C - 0x5000;
        gUnk_02039DC8->unk_50 = gBtlWork->unk_008;
        gUnk_02039DC8->unk_54 = gBtlWork->unk_00C;
        gUnk_02039DC8->unk_68 = 0;
        gUnk_02039DC8->unk_6A = 0;
        p->unk_02C = p->unk_000->unk_08;
        p->unk_030 = p->unk_000->unk_0C;
        p->unk_034 = p->unk_000->unk_10;
        func_0801A920(0, 256, 328, 424);
        TaskCreate(&p->unk_010, gTaskDescBosDsd, p->unk_028);
        break;
    case 98:
        SetupBg(0, 0, 24, 0);
        SetupBg(1, 0, 26, 0);
        SetupBg(2, 2, 28, 10);
        SetBgPriority(0, 3);
        SetBgPriority(1, 2);
        SetBgPriority(2, 1);
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        gBtlWork->unk_07C = (BtlObj*)p->unk_054;
        gBtlWork->unk_068 = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        TaskCreate(&p->unk_010, gTaskDescBosBoogie, NULL);
        gBtlWork->unk_0B3 = 5;
        break;
    case 99:
        SetupBg(0, 0, 24, 0);
        SetupBg(1, 0, 26, 0);
        SetupBg(2, 2, 28, 10);
        SetBgPriority(0, 3);
        SetBgPriority(1, 2);
        SetBgPriority(2, 1);
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        gBtlWork->unk_07C = (BtlObj*)p->unk_054;
        gBtlWork->unk_068 = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        TaskCreate(&p->unk_010, gTaskDescBosUrsula, NULL);
        gBtlWork->unk_0B3 = 5;
        break;
    case 104:
        SetupBg(0, 0, 24, 0);
        SetupBg(1, 0, 26, 0);
        SetupBg(2, 2, 28, 10);
        SetBgPriority(0, 3);
        SetBgPriority(1, 2);
        SetBgPriority(2, 1);
        gBtlWork = EwramAlloc(464);
        BtlWorkInit();
        gBtlWork->unk_07C = (BtlObj*)p->unk_054;
        gBtlWork->unk_068 = 4;
        TaskPoolInit(&gBtlWork->taskPools[0], 32);
        TaskPoolInit(&gBtlWork->taskPools[1], 1);
        p->unk_1B3 = 1;
        TaskCreate(&p->unk_010, gTaskDescBosGa, (void*)1);
        gBtlWork->unk_0B3 = 5;
        break;
    default:
        if ((p->unk_000->unk_18 & 0x2000) == 0) {
            func_0801CD98(&p->unk_010, p->unk_028, p->unk_026, p->unk_000->unk_00, p->unk_000->unk_08, p->unk_000->unk_0C, p->unk_000->unk_10);
            p->unk_1B4 = 1;
        } else {
            p->unk_1B4 = 0;
        }

        func_08072C34(p);
        break;
    }

    if (p->unk_1B4 != 0) {
        func_0806F94C(p);
    }
}
u8 event_chara_1(Work0806180C* p, void* a) {
    u8 t;
    s32 v0;
    s32 v1;

    t = func_0806E570(p);

    if (p->unk_1B4 != 0) {
        func_0806E7A8(p);
    }
    func_08070AD4(p);

    if (t != 0) {
        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
            ((void (*)(Work0806180C*, void*))p->unk_000[p->unk_1A0].unk_1C)(p, a);
        }

        if (p->unk_000[p->unk_1A0].unk_20 != NULL) {
            p->unk_000[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }

    if (p->unk_000[p->unk_1A0].unk_18 & 0x100) {
        p->unk_03C |= 4;
    } else {
        p->unk_03C &= ~4;
    }

    if (p->unk_000[p->unk_1A0].unk_18 & 0x200) {
        gUnk_02039DC8->unk_64 |= 1;
        gUnk_02039DC8->unk_64 |= 4;
        p->unk_19C = 0;
        SetTaskUpdate(a, (void*)func_080700D4);
    }
    TaskPoolUpdate(&p->unk_010);

    if (p->unk_1B3 != 0) {
        switch (p->unk_026) {
        case 0x62:
            gUnk_02039DC8->unk_58 = gUnk_02039DC8->unk_48 = gBtlWork->unk_010;
            gUnk_02039DC8->unk_5C = gUnk_02039DC8->unk_4C = gBtlWork->unk_014;
            TaskPoolUpdate(&gBtlWork->taskPools[1]);
            break;
        case 0x63:
            gBtlWork->unk_004 = gBtlWork->unk_00C;
            gBtlWork->unk_010 = gUnk_02039DC8->unk_48;
            gBtlWork->unk_014 = gUnk_02039DC8->unk_4C;
            gUnk_02039DC8->unk_58 = gUnk_02039DC8->unk_48;
            gUnk_02039DC8->unk_5C = gUnk_02039DC8->unk_4C;
            TaskPoolUpdate(&gBtlWork->taskPools[0]);
            TaskPoolUpdate(&gBtlWork->taskPools[1]);
            break;
        case 0x65:
            gUnk_02039DC8->unk_48 = v0 = gBtlWork->unk_000;
            gUnk_02039DC8->unk_4C = v1 = gBtlWork->unk_004;
            gUnk_02039DC8->unk_50 = gBtlWork->unk_008;
            gUnk_02039DC8->unk_54 = gBtlWork->unk_00C;
            gUnk_02039DC8->unk_58 = v0;
            gUnk_02039DC8->unk_5C = v1;
            break;
        case 0x61:
            gBtlWork->unk_010 = gUnk_02039DC8->unk_50;
            gBtlWork->unk_014 = gUnk_02039DC8->unk_54;
            break;
        case 0x67:
            break;
        }
    }

    if (p->unk_026 == 0) {
        if (gBtlWork != NULL) {
            gBtlWork->unk_07C->unk_004 = p->unk_02C - 0x7800;
            gBtlWork->unk_07C->unk_008 = p->unk_030 - 0x5000;
            gBtlWork->unk_07C->unk_00C = 0;
        }
    }

    if (p->unk_1B5 != 0) {
        return 0;
    }

    if (p->unk_000[p->unk_1A0].unk_18 & 0x100000) {
        if (gFrameCounter % 6 == 0) {
            u16 v = GetRandom() % 7 + 4;

            gBldAlpha = ((16 - v) << 8) | v;
        }
    }
    return 1;
}
static inline s16 GetEventCharaScreenX(Work0806180C* p) {
    return (p->unk_180 >> 8) - (gUnk_02039DC8->unk_58 >> 8);
}

void event_chara_2(Work0806180C* p) {
    Ent0806E9BC* e;
    s32 save;
    s32 x;
    s32 y;
    u16 h;

    save = p->unk_034;
    e = &p->unk_000[p->unk_1A0];

    if (e->unk_18 & 0x80) {
        p->unk_034 = gSineTable[p->unk_1B0] * 2 + save;
    } else if (e->unk_18 & 0x40000) {
        p->unk_034 = gSineTable[p->unk_1B0] * 3 + save;
    }

    if (p->unk_1B6 != 0) {
        TaskPoolDraw(&p->unk_010);
    }

    if (p->unk_026 == 99) {
        TaskPoolDraw(&gBtlWork->taskPools[0]);
    }

    if (p->tiles != NULL) {
        h = p->unk_03E;

        if (p->unk_1B1 == 0) {
            h &= 0xFFFE;
        } else {
            h |= 1;
        }
        x = GetEventCharaScreenX(p);
        y = (p->unk_184 >> 8) + gUnk_0903380C[p->unk_026].unk_00 - (gUnk_02039DC8->unk_5C >> 8);
        DrawSprite(x, y, p->gfx, p->tiles, p->palette, 0, h, 50);
    }
    p->unk_034 = save;
}
void event_chara_3(Work0806180C* p) {
    TaskPoolDestroy(&p->unk_010);

    if (p->unk_1B3 != 0) {
        TaskPoolDestroy(&gBtlWork->taskPools[0]);
        TaskPoolDestroy(&gBtlWork->taskPools[1]);
        EwramFree(gBtlWork);
    }
}
u8 func_0806E570(Work0806180C* p) {
    Ent0806E9BC* e = &p->unk_000[p->unk_1A0];
    u16 v;

    if (p->unk_000[p->unk_1A0].unk_04 > gUnk_02039DC8->unk_6C) {
        return 0;
    }

    if ((p->unk_000[p->unk_1A0].unk_18 & 0x8000) != 0) {
        return 0;
    }

    p->unk_1A0++;
    p->unk_1A4 = p->unk_000[p->unk_1A0].unk_04 - gUnk_02039DC8->unk_6C;
    p->unk_17C = p->unk_000[p->unk_1A0].unk_00;

    if ((p->unk_000[p->unk_1A0].unk_18 & 0x4000) != 0) {
        func_0801CD98(&p->unk_010, p->unk_028, p->unk_026, p->unk_000[p->unk_1A0].unk_00,
                      p->unk_000[p->unk_1A0].unk_08, p->unk_000[p->unk_1A0].unk_0C,
                      p->unk_000[p->unk_1A0].unk_10);
        p->unk_1B4 = 1;
        func_08072C34(p);
    }

    if ((p->unk_000[p->unk_1A0].unk_18 & 0x10000) != 0) {
        p->unk_1B5 = 1;
    }

    if ((p->unk_000[p->unk_1A0].unk_18 & 0x800) != 0) {
        LoadPalette(&gUnk_096148D8[0x100], (void*)(p->unk_044 * 32 + 0x05000200), 32);
    } else if ((p->unk_000[p->unk_1A0 - 1].unk_18 & 0x800) != 0) {
        LoadPalette(gUnk_0813B09C[p->unk_026][2], (void*)(p->unk_044 * 32 + 0x05000200), 32);
    }

    if ((p->unk_000[p->unk_1A0].unk_18 & 0x100000) != 0) {
        gBldCnt = 0xF40;
        v = p->unk_03E;
        func_0801CE00(p->unk_028, v | 4);
    } else {
        v = p->unk_03E;
        func_0801CE00(p->unk_028, p->unk_03E & 0xFFFB);
        p->unk_1B8 = 0;
    }

    if (p->unk_1B4 != 0) {
        if ((p->unk_000[p->unk_1A0].unk_18 & 15) == 2) {
            EvtObjSetPos(p->unk_028, p->unk_000[p->unk_1A0].unk_08, p->unk_000[p->unk_1A0].unk_0C, p->unk_000[p->unk_1A0].unk_10);
        }

        func_0801CD74(p->unk_028, p->unk_17C);
        func_0806F94C(p);
        return 1;
    }

    if (p->unk_000[p->unk_1A0].unk_00 == 0x3AF) {
        func_0810B350(gUnk_02039DC8->unk_00[16]);
    }

    if (p->unk_000[p->unk_1A0].unk_00 == 0x3AB) {
        func_0810C2C4(gUnk_02039DC8->unk_00[16]);
    }

    return 0;
}
void func_0806E7A8(Work0806180C* p) {
    Ent0806E9BC* e = &p->unk_000[p->unk_1A0];
    Ent0806E7A8* t;

    if (e->unk_00 == 0x3A7) {
        t = ListPoolFirst(&gBtlWork->unk_080);

        if (t != NULL) {
            t->unk_34 |= 2;
        }
    }

    switch (e->unk_18 & 15) {
    case 2:
        EvtObjSetPos(p->unk_028, p->unk_000[p->unk_1A0].unk_08, p->unk_000[p->unk_1A0].unk_0C, p->unk_000[p->unk_1A0].unk_10);
        break;
    case 3:
        ApproachValue(&p->unk_02C, p->unk_000[p->unk_1A0].unk_08, p->unk_1A4);
        ApproachValue(&p->unk_030, p->unk_000[p->unk_1A0].unk_0C, p->unk_1A4);
        ApproachValue(&p->unk_034, p->unk_000[p->unk_1A0].unk_10, p->unk_1A4);
        p->unk_1A4--;

        if (p->unk_1A4 == 0) {
            if ((p->unk_000[p->unk_1A0].unk_18 & 0x1000) == 0) {
                func_0806E9BC(p);
            }
        }
        break;
    case 4:
        if ((e->unk_18 & 32) == 0) {
            p->unk_19C = gUnk_0903380C[p->unk_026].unk_02;
        } else {
            p->unk_19C = gUnk_0903380C[p->unk_026].unk_04;
        }

        if (e->unk_14 == 1) {
            p->unk_034 -= p->unk_19C;
        } else if (e->unk_14 == 2) {
            p->unk_034 += p->unk_19C;
        } else {
            p->unk_02C += (gSineTable[e->unk_14 & 0xFF] * p->unk_19C) >> 8;
            p->unk_030 += (-gSineTable[(e->unk_14 & 0xFF) + 64] * p->unk_19C) >> 8;
        }
        break;
    }

    if ((e->unk_18 & 0x80) != 0) {
        p->unk_1B0 += 4;
    } else if ((e->unk_18 & 0x40000) != 0) {
        p->unk_1B0 += 4;
    } else {
        p->unk_1B0 = 0;
    }

    if ((e->unk_18 & 0x80000) != 0) {
        p->unk_1B6 ^= 1;
    } else {
        p->unk_1B6 = 1;
    }
}

void func_0806E9BC(Work0806180C* p) {
    Ent0806E9BC* e = &p->unk_000[p->unk_1A0];

    func_0801CD74(p->unk_028, e->unk_14);
}

u8 _0806E9DC(Work0806180C* p, void* a) {
    p->unk_188 = 0x800;
    p->unk_18C = 0;
    p->unk_1A8 = 0;
    p->unk_198 = p->unk_034;
    TaskPoolUpdate(&p->unk_010);
    SetTaskUpdate(a, (void*)func_0806EA28);
    return 1;
}
u8 func_0806EA28(Work0806180C* p, void* a) {
    u16 x;
    u16 y;
    u8 t;

    x = (p->unk_02C >> 8) - (gUnk_02039DC8->unk_58 >> 8);
    y = (p->unk_030 >> 8) + (p->unk_034 >> 8) - (gUnk_02039DC8->unk_5C >> 8);
    t = func_0806E570(p);
    func_0806E7A8(p);
    func_08070AD4(p);

    if (p->unk_1A8 == 0) {
        p->unk_034 -= p->unk_188 / 4;
        p->unk_188 -= p->unk_18C / 4;
        p->unk_18C += 51;
    } else {
        p->unk_1A8--;
        if (p->unk_1A8 == 0) {
            if (p->unk_026 == 10) {
                m4aSongNumStart(0x144);
                func_08076110(0x144, x, y);
            }
        }
    }

    if (p->unk_034 > p->unk_198) {
        p->unk_034 = p->unk_198;
        p->unk_188 = 0x800;
        p->unk_18C = 0;
        p->unk_1A8 = 17;
    }

    if (t != 0) {
        p->unk_034 = p->unk_198;

        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->unk_000[p->unk_1A0].unk_20 != NULL) {
            p->unk_000[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
u8 func_0806EB94(Work0806180C* p, void* a) {
    p->unk_188 = 0xC00;
    p->unk_18C = 0;
    p->unk_1A8 = 0;
    p->unk_198 = p->unk_034;
    TaskPoolUpdate(&p->unk_010);
    SetTaskUpdate(a, (void*)func_0806EBE0);
    return 1;
}
u8 func_0806EBE0(Work0806180C* p, void* a) {
    u8 t;

    t = func_0806E570(p);
    func_0806E7A8(p);
    func_08070AD4(p);

    if (p->unk_1A8 == 0) {
        p->unk_034 -= p->unk_188 / 4;
        p->unk_188 -= p->unk_18C / 4;
        p->unk_18C += 51;
    } else {
        p->unk_1A8--;
    }

    if (p->unk_034 > p->unk_198) {
        p->unk_034 = p->unk_198;
        p->unk_188 = 0;
        p->unk_18C = 0;
        p->unk_1A8 = 17;
    }

    if (t != 0) {
        p->unk_034 = p->unk_198;

        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->unk_000[p->unk_1A0].unk_20 != NULL) {
            p->unk_000[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
u8 func_0806ECE0(Work0806180C* p, void* a) {
    p->unk_188 = 0x300;
    p->unk_18C = 0;
    p->unk_1A8 = 0;
    p->unk_198 = p->unk_034;
    TaskPoolUpdate(&p->unk_010);
    SetTaskUpdate(a, (void*)func_0806ED2C);
    return 1;
}
u8 func_0806ED2C(Work0806180C* p, void* a) {
    u8 t;

    t = func_0806E570(p);
    func_08070AD4(p);
    func_0806E7A8(p);

    if (p->unk_1A8 == 0) {
        p->unk_034 -= p->unk_188;
        p->unk_188 -= p->unk_18C;
        p->unk_18C += 51;
    } else {
        p->unk_1A8--;
    }

    if (p->unk_034 > p->unk_198) {
        p->unk_034 = p->unk_198;
        p->unk_188 = 0x800;
        p->unk_18C = 0;
        p->unk_1A8 = 17;
    }

    if (t != 0) {
        p->unk_034 = p->unk_198;

        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->unk_000[p->unk_1A0].unk_20 != NULL) {
            p->unk_000[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
u8 func_0806EE20(Work0806180C* p, void* a) {
    p->unk_188 = 0x300;
    p->unk_18C = 0;
    p->unk_1A8 = 0;
    p->unk_198 = p->unk_034;
    TaskPoolUpdate(&p->unk_010);
    SetTaskUpdate(a, (void*)func_0806EE6C);
    return 1;
}
u8 func_0806EE6C(Work0806180C* p, void* a) {
    u8 t;

    t = func_0806E570(p);
    func_0806E7A8(p);
    func_08070AD4(p);

    if (p->unk_1A8 == 0) {
        p->unk_034 -= p->unk_188;
        p->unk_188 -= p->unk_18C;
        p->unk_18C += 51;
    } else {
        p->unk_1A8--;
    }

    if (p->unk_034 > 0) {
        p->unk_034 = 0;
        p->unk_1A8 = 17;
    }

    if (t != 0) {
        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->unk_000[p->unk_1A0].unk_20 != NULL) {
            p->unk_000[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
u8 func_0806EF40(void* work, void* a) {
    Work0806180C* p = work;
    Ent0806E9BC* e;
    u16 z;

    func_0806E7A8(p);
    func_08070AD4(p);

    if (func_0806E570(p) != 0) {
        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
        }

        if (p->unk_000[p->unk_1A0].unk_20 != NULL) {
            p->unk_000[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    z = p->unk_03E;
    z |= 4;
    func_0801CE00(p->unk_028, z);
    gBldCnt = 0xF40;
    gBldAlpha = 16;
    p->unk_1AA = 0;
    p->unk_1A9 = 16;
    SetTaskUpdate(a, (void*)func_0806F02C);

    if (p->unk_026 == 3) {
        e = &p->unk_000[p->unk_1A0];
        if ((e->unk_18 & 0x80000) == 0) {
            m4aSongNumStart(0x14A);
        }
    }
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
u8 func_0806F02C(Work0806180C* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_1AA++;
    if (p->unk_1AA % 2 == 0) {
        if (p->unk_1A9 != 0) {
            p->unk_1A9--;
        }
    }
    gBldAlpha = ((16 - p->unk_1A9) << 8) | p->unk_1A9;

    if (func_0806E570(p) != 0) {
        gBldCnt = 0;

        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->unk_000[p->unk_1A0].unk_20 != NULL) {
            p->unk_000[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
        {
            u16 z = p->unk_03E;

            z &= 0xFFFB;
            func_0801CE00(p->unk_028, z);
        }
    }
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
u8 func_0806F114(void* work, void* a) {
    Work0806180C* p = work;
    Ent0806E9BC* e;
    u16 z;

    func_0806E7A8(p);
    func_08070AD4(p);

    if (func_0806E570(p) != 0) {
        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
        }

        if (p->unk_000[p->unk_1A0].unk_20 != NULL) {
            p->unk_000[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    z = p->unk_03E;
    z |= 4;
    func_0801CE00(p->unk_028, z);
    gBldCnt = 0xF40;
    gBldAlpha = 0x1000;
    p->unk_1AA = 0;
    p->unk_1A9 = 0;
    SetTaskUpdate(a, (void*)func_0806F204);

    if (p->unk_026 == 3) {
        e = &p->unk_000[p->unk_1A0];
        if ((e->unk_18 & 0x80000) == 0) {
            m4aSongNumStart(0x14B);
        }
    }
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
u8 func_0806F204(Work0806180C* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_1AA++;
    if (p->unk_1AA % 2 == 0) {
        if (p->unk_1A9 <= 15) {
            p->unk_1A9++;
        }
    }
    gBldAlpha = ((16 - p->unk_1A9) << 8) | p->unk_1A9;

    if (func_0806E570(p) != 0) {
        gBldCnt = 0;

        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->unk_000[p->unk_1A0].unk_20 != NULL) {
            p->unk_000[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
        {
            u16 z = p->unk_03E;

            z &= 0xFFFB;
            func_0801CE00(p->unk_028, z);
        }
    }
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
u8 func_0806F2EC(void* work, void* a) {
    Work0806180C* p = work;
    u16 z;

    func_0806E7A8(p);
    func_08070AD4(p);

    if (func_0806E570(p) != 0) {
        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
        }

        if (p->unk_000[p->unk_1A0].unk_20 != NULL) {
            p->unk_000[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    z = p->unk_03E;
    z |= 4;
    func_0801CE00(p->unk_028, z);
    gBldCnt = 0xF40;
    gBldAlpha = 16;
    p->unk_1AA = 0;
    p->unk_1A9 = 0;
    SetTaskUpdate(a, (void*)func_0806F3A8);
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
u8 func_0806F3A8(Work0806180C* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_1AA++;
    if (p->unk_1AA % 2 == 0) {
        if (p->unk_1A9 <= 15) {
            p->unk_1A9++;
        }
    }
    gBldAlpha = (p->unk_1A9 << 8) | 16;

    if (func_0806E570(p) != 0) {
        gBldCnt = 0;

        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->unk_000[p->unk_1A0].unk_20 != NULL) {
            p->unk_000[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
u8 func_0806F47C(void* work, void* a) {
    Work0806180C* p = work;
    u16 z;

    func_0806E7A8(p);
    func_08070AD4(p);

    if (func_0806E570(p) != 0) {
        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
        }

        if (p->unk_000[p->unk_1A0].unk_20 != NULL) {
            p->unk_000[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    z = p->unk_03E;
    z |= 4;
    func_0801CE00(p->unk_028, z);
    gBldCnt = 0xF40;
    gBldAlpha = 0x1010;
    p->unk_1AA = 0;
    p->unk_1A9 = 16;
    SetTaskUpdate(a, (void*)func_0806F53C);
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
u8 func_0806F53C(Work0806180C* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_1AA++;
    if (p->unk_1AA % 2 == 0) {
        if (p->unk_1A9 != 0) {
            p->unk_1A9--;
        }
    }
    gBldAlpha = (p->unk_1A9 << 8) | 16;

    if (func_0806E570(p) != 0) {
        gBldCnt = 0;

        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->unk_000[p->unk_1A0].unk_20 != NULL) {
            p->unk_000[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
u8 func_0806F610(Work0806180C* p, void* a) {
    p->unk_18C = 0;
    p->unk_198 = 0;
    p->unk_190 = p->unk_02C;
    p->unk_194 = p->unk_034;
    SetTaskUpdate(a, (void*)func_0806F64C);
    return 1;
}
u8 func_0806F64C(Work0806180C* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_02C += gSineTable[(u8)p->unk_18C] * (p->unk_198 >> 8);
    p->unk_030 += -gSineTable[(u8)p->unk_18C + 64] * (p->unk_198 >> 9);
    p->unk_18C += 2;

    if (p->unk_198 < 0x200) {
        p->unk_198 += 25;
    }

    if (func_0806E570(p) != 0) {
        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->unk_000[p->unk_1A0].unk_20 != NULL) {
            p->unk_000[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
u8 func_0806F734(Work0806180C* p, void* a) {
    p->unk_18C = 0;
    p->unk_198 = 0;
    p->unk_190 = p->unk_02C;
    p->unk_194 = p->unk_034;
    SetTaskUpdate(a, (void*)func_0806F770);
    return 1;
}
u8 func_0806F770(Work0806180C* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_02C += gSineTable[(u8)p->unk_18C] * (p->unk_198 >> 8);
    p->unk_030 += -gSineTable[(u8)p->unk_18C + 64] * (p->unk_198 >> 9);
    p->unk_18C += 6;

    if (p->unk_198 < 0x200) {
        p->unk_198 += 25;
    }

    if (func_0806E570(p) != 0) {
        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->unk_000[p->unk_1A0].unk_20 != NULL) {
            p->unk_000[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
u8 func_0806F858(Work0806180C* p, void* a) {
    p->unk_18C = 1;
    p->unk_198 = 0;
    p->unk_190 = p->unk_02C;
    p->unk_194 = p->unk_034;
    SetTaskUpdate(a, (void*)func_0806F898);
    return 1;
}
u8 func_0806F898(Work0806180C* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);

    if (p->unk_198 == 2) {
        p->unk_034 += p->unk_18C << 10;
        p->unk_18C = -p->unk_18C;
        p->unk_198 = 0;
    } else {
        p->unk_198++;
    }

    if (func_0806E570(p) != 0) {
        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->unk_000[p->unk_1A0].unk_20 != NULL) {
            p->unk_000[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
void func_0806F94C(Work0806180C* p) {
    u16 z;

    z = p->unk_03E;

    if (p->unk_000[p->unk_1A0].unk_18 & 0x40) {
        if (p->unk_000[p->unk_1A0].unk_18 & 0x10) {
            z |= 0x401;
            z &= 0xF7FF;
            func_0801CE00(p->unk_028, z);
        } else {
            z |= 0x801;
            z &= 0xFBFF;
            func_0801CE00(p->unk_028, z);

            if ((p->unk_000[p->unk_1A0].unk_18 & 0x400) == 0) {
                z |= 0x801;
                func_0801CE00(p->unk_028, z);
            } else {
                z |= 1;
                z &= 0xF7FF;
                func_0801CE00(p->unk_028, z);
            }
        }
    } else {
        if (p->unk_000[p->unk_1A0].unk_18 & 0x10) {
            z |= 0x400;
            z &= 0xF7FF;
            z &= 0xFFFE;
            func_0801CE00(p->unk_028, z);
        } else {
            z |= 0x800;
            z &= 0xFBFF;
            z &= 0xFFFE;
            func_0801CE00(p->unk_028, z);

            if ((p->unk_000[p->unk_1A0].unk_18 & 0x400) == 0) {
                z |= 0x800;
                z &= 0xFFFE;
                func_0801CE00(p->unk_028, z);
            } else {
                z &= 0xF7FF;
                z &= 0xFFFE;
                func_0801CE00(p->unk_028, z);
            }
        }
    }
}
u8 func_0806FA84(Work0806180C* p, void* a) {
    p->unk_1AA = 0;
    p->unk_1A9 = 0;
    SetTaskUpdate(a, (void*)func_0806FAB8);
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
u8 func_0806FAB8(Work0806180C* p, void* a) {
    u16 buf[2];

    memcpy(buf, gUnk_09033C8C, 4);
    func_0801CD74(p->unk_028, buf[p->unk_1A9]);
    p->unk_1AA++;
    if (p->unk_1AA == 12) {
        p->unk_1AA = 0;
        p->unk_1A9 ^= 1;
    }

    if (func_0806E570(p) != 0) {
        if (p->tiles != NULL) {
            ReleaseObjTiles(p->tiles);
        }

        if (p->palette != NULL) {
            ReleaseObjPalette(p->palette);
        }
        p->tiles = NULL;
        p->palette = NULL;

        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }
    }
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
u8 func_0806FB6C(void* work, void* a) {
    Work0806180C* p = work;
    u16 z;

    func_0806E7A8(p);
    func_08070AD4(p);

    if (func_0806E570(p) != 0) {
        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
        }

        if (p->unk_000[p->unk_1A0].unk_20 != NULL) {
            p->unk_000[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    z = p->unk_03E;
    z |= 4;
    func_0801CE00(p->unk_028, z);
    gBldCnt = 0xF40;
    gBldAlpha = 16;
    p->unk_1AA = 0;
    p->unk_1A9 = 16;
    SetTaskUpdate(a, (void*)func_0806FC28);
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
u8 func_0806FC28(Work0806180C* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_1AA++;
    if (p->unk_1AA % 2 == 0) {
        if (p->unk_1A9 != 0) {
            p->unk_1A9--;
        }
    }
    gBldAlpha = p->unk_1A9;

    if (func_0806E570(p) != 0) {
        gBldCnt = 0;

        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->unk_000[p->unk_1A0].unk_20 != NULL) {
            p->unk_000[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
u8 func_0806FCF4(void* work, void* a) {
    Work0806180C* p = work;
    u16 z;

    func_0806E7A8(p);
    func_08070AD4(p);

    if (func_0806E570(p) != 0) {
        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
        }

        if (p->unk_000[p->unk_1A0].unk_20 != NULL) {
            p->unk_000[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    z = p->unk_03E;
    z |= 4;
    func_0801CE00(p->unk_028, z);
    gBldCnt = 0xF40;
    gBldAlpha = 0;
    p->unk_1AA = 0;
    p->unk_1A9 = 16;
    SetTaskUpdate(a, (void*)func_0806FDB0);
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
u8 func_0806FDB0(Work0806180C* p, void* a) {
    func_0806E7A8(p);
    func_08070AD4(p);
    p->unk_1AA++;
    if (p->unk_1AA % 2 == 0) {
        if (p->unk_1A9 != 0) {
            p->unk_1A9--;
        }
    }
    gBldAlpha = (16 - p->unk_1A9) | (p->unk_1A9 << 8);
    gBldAlpha = (p->unk_1A9 << 8) | 16;

    if (func_0806E570(p) != 0) {
        gBldCnt = 0;

        if (p->unk_000[p->unk_1A0].unk_1C != NULL) {
            SetTaskUpdate(a, p->unk_000[p->unk_1A0].unk_1C);
        } else {
            SetTaskUpdate(a, (void*)event_chara_1);
        }

        if (p->unk_000[p->unk_1A0].unk_20 != NULL) {
            p->unk_000[p->unk_1A0].unk_20(p);
            p->unk_1B2 = 1;
        } else {
            p->unk_1B2 = 0;
        }
    }
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
void func_0806FE90(Work0806180C* p) {
    u16 keys = GetKeysHeld();

    switch (keys & 0xF0) {
    case 0x40:
        if (GetKeyReleaseTime(0x20) <= 4) {
            p->unk_1AB = 211;
        } else if (GetKeyReleaseTime(0x10) <= 4) {
            p->unk_1AB = 45;
        } else {
            p->unk_1AB = 0;
        }
        break;
    case 0x80:
        if (GetKeyReleaseTime(0x20) <= 4) {
            p->unk_1AB = 173;
        } else if (GetKeyReleaseTime(0x10) <= 4) {
            p->unk_1AB = 83;
        } else {
            p->unk_1AB = 128;
        }
        break;
    case 0x20:
        if (GetKeyReleaseTime(0x40) <= 4) {
            p->unk_1AB = 211;
        } else if (GetKeyReleaseTime(0x80) <= 4) {
            p->unk_1AB = 173;
        } else {
            p->unk_1AB = 192;
        }
        break;
    case 0x10:
        if (GetKeyReleaseTime(0x40) <= 4) {
            p->unk_1AB = 45;
        } else if (GetKeyReleaseTime(0x80) <= 4) {
            p->unk_1AB = 83;
        } else {
            p->unk_1AB = 64;
        }
        break;
    case 0x50:
        p->unk_1AB = 45;
        break;
    case 0x60:
        p->unk_1AB = 211;
        break;
    case 0x90:
        p->unk_1AB = 83;
        break;
    case 0xA0:
        p->unk_1AB = 173;
        break;
    }
}

void func_08070008(Work0806180C* p) {
    u8 old = p->unk_1AB;

    func_0806FE90(p);

    if (old != p->unk_1AB) {
        if (abs((s8)GetAngleDiff(old, p->unk_1AB)) > 100) {
            p->unk_19C = 0;
        } else {
            p->unk_19C >>= 1;
        }
    }
}

void func_08070058(Work0806180C* p, s32 a) {
    u16 f;

    f = p->unk_03E;

    switch (p->unk_1AB) {
    case 0xD3:
        f &= 0xFFFE;
        break;
    case 0x2D:
    case 0x40:
    case 0x53:
        f |= 1;
        break;
    case 0x00:
    case 0x80:
    case 0xAD:
    case 0xC0:
        f &= 0xFFFE;
        break;
    }

    if (a != p->unk_17C) {
        func_0801CD74(p->unk_028, a);
        p->unk_17C = a;
    }
    func_0801CE00(p->unk_028, f);
}
u8 func_080700D4(Work0806180C* p, void* a) {
    u16 keys;
    s32 v;

    keys = GetKeysHeld();
    func_0806FE90(p);

    switch (p->unk_1AB) {
    case 0x00:
        if ((keys & 1) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 5);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 10);
        }
        break;
    case 0x80:
        if ((keys & 1) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 6);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 11);
        }
        break;
    case 0xC0:
        if ((keys & 1) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 8);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 13);
        }
        break;
    case 0x40:
        if ((keys & 1) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 8);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 13);
        }
        break;
    case 0xD3:
        if ((keys & 1) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 9);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 14);
        }
        break;
    case 0x2D:
        if ((keys & 1) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 9);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 14);
        }
        break;
    case 0xAD:
        if ((keys & 1) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 7);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 12);
        }
        break;
    case 0x53:
        if ((keys & 1) != 0) {
            p->unk_1AD = 1;
            func_08070058(p, 7);
        } else {
            p->unk_1AD = 2;
            func_08070058(p, 12);
        }
        break;
    }

    if ((keys & 0xF0) != 0) {
        v = p->unk_19C + 51;
        p->unk_19C = v;

        switch (p->unk_1AD) {
        case 1:
            if (v > gUnk_0903380C[p->unk_026].unk_02) {
                p->unk_19C = gUnk_0903380C[p->unk_026].unk_02;
            }
            break;
        case 2:
            if (v > gUnk_0903380C[p->unk_026].unk_04) {
                p->unk_19C = gUnk_0903380C[p->unk_026].unk_04;
            }
            break;
        }
    } else {
        p->unk_19C -= 102;

        if (p->unk_19C < 0) {
            p->unk_19C = 0;
        }

        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 0);
            break;
        case 0x80:
            func_08070058(p, 1);
            break;
        case 0xC0:
            func_08070058(p, 3);
            break;
        case 0x40:
            func_08070058(p, 3);
            break;
        case 0xAD:
            func_08070058(p, 2);
            break;
        case 0x53:
            func_08070058(p, 2);
            break;
        case 0xD3:
            func_08070058(p, 4);
            break;
        case 0x2D:
            func_08070058(p, 4);
            break;
        }
    }

    if ((GetKeysPressed() & 2) != 0) {
        p->unk_1AF = 0;
        p->unk_1A8 = 0;
        SetTaskUpdate(a, (void*)func_0807048C);
    }

    v = p->unk_02C + (gSineTable[p->unk_1AB] * p->unk_19C >> 8);
    p->unk_02C = v;
    p->unk_030 += p->unk_19C * -gSineTable[p->unk_1AB + 64] >> 8;

    if (p->unk_026 == 0) {
        if (gBtlWork != NULL) {
            gBtlWork->unk_07C->unk_004 = v - 0x7800;
            gBtlWork->unk_07C->unk_008 = p->unk_030 - 0x5000;
            gBtlWork->unk_07C->unk_00C = 0;
        }
    }

    p->unk_1AC = p->unk_1AB;
    p->unk_1AE = p->unk_1AD;
    TaskPoolUpdate(&p->unk_010);
    return 1;
}
u8 func_0807048C(Work0806180C* p, void* a) {
    u16 keys = GetKeysHeld();

    if ((keys & 0xF0) != 0) {
        p->unk_19C += 5;
    }

    switch (p->unk_1AF) {
    case 0:
        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 38);
            break;
        case 0x80:
            func_08070058(p, 44);
            break;
        case 0xC0:
            func_08070058(p, 56);
            break;
        case 0x40:
            func_08070058(p, 56);
            break;
        case 0xAD:
            func_08070058(p, 50);
            break;
        case 0x53:
            func_08070058(p, 50);
            break;
        case 0xD3:
            func_08070058(p, 62);
            break;
        case 0x2D:
            func_08070058(p, 62);
            break;
        }

        p->unk_02C += gSineTable[p->unk_1AB] * (p->unk_19C >> 2) >> 8;
        p->unk_030 += -gSineTable[p->unk_1AB + 64] * (p->unk_19C >> 2) >> 8;

        if (p->unk_1A8 > 3) {
            p->unk_1AF = 1;
            p->unk_18C = -0x540;
            p->unk_198 = p->unk_034;
            p->unk_1A8 = 0;
        } else {
            p->unk_1A8++;
        }
        break;
    case 1:
        func_08070008(p);

        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 39);
            break;
        case 0x80:
            func_08070058(p, 45);
            break;
        case 0xC0:
            func_08070058(p, 57);
            break;
        case 0x40:
            func_08070058(p, 57);
            break;
        case 0xAD:
            func_08070058(p, 51);
            break;
        case 0x53:
            func_08070058(p, 51);
            break;
        case 0xD3:
            func_08070058(p, 63);
            break;
        case 0x2D:
            func_08070058(p, 63);
            break;
        }

        p->unk_02C += gSineTable[p->unk_1AB] * p->unk_19C >> 8;
        p->unk_030 += p->unk_19C * -gSineTable[p->unk_1AB + 64] >> 8;
        p->unk_18C += 51;
        p->unk_034 += p->unk_18C;

        if ((GetKeysHeld() & 2) == 0) {
            p->unk_18C += 64;
        }

        if (p->unk_18C > -0x200) {
            p->unk_1AF = 2;
            p->unk_1A8 = 0;
        }
        break;
    case 2:
        func_08070008(p);

        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 40);
            break;
        case 0x80:
            func_08070058(p, 46);
            break;
        case 0xC0:
            func_08070058(p, 58);
            break;
        case 0x40:
            func_08070058(p, 58);
            break;
        case 0xAD:
            func_08070058(p, 52);
            break;
        case 0x53:
            func_08070058(p, 52);
            break;
        case 0xD3:
            func_08070058(p, 64);
            break;
        case 0x2D:
            func_08070058(p, 64);
            break;
        }

        p->unk_02C += gSineTable[p->unk_1AB] * p->unk_19C >> 8;
        p->unk_030 += p->unk_19C * -gSineTable[p->unk_1AB + 64] >> 8;
        p->unk_18C += 51;
        p->unk_034 += p->unk_18C;

        if ((GetKeysHeld() & 2) == 0) {
            p->unk_18C += 64;
        }

        if (p->unk_18C > 0) {
            p->unk_1AF = 3;
            p->unk_1A8 = 0;
        }
        break;
    case 3:
        func_08070008(p);

        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 40);
            break;
        case 0x80:
            func_08070058(p, 46);
            break;
        case 0xC0:
            func_08070058(p, 58);
            break;
        case 0x40:
            func_08070058(p, 58);
            break;
        case 0xAD:
            func_08070058(p, 52);
            break;
        case 0x53:
            func_08070058(p, 52);
            break;
        case 0xD3:
            func_08070058(p, 64);
            break;
        case 0x2D:
            func_08070058(p, 64);
            break;
        }

        p->unk_02C += gSineTable[p->unk_1AB] * p->unk_19C >> 8;
        p->unk_030 += p->unk_19C * -gSineTable[p->unk_1AB + 64] >> 8;
        p->unk_034 += p->unk_18C;
        p->unk_18C += 51;

        if (p->unk_18C > 0x1FF) {
            p->unk_1AF = 4;
            p->unk_1A8 = 0;
        }
        break;
    case 4:
        func_08070008(p);

        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 41);
            break;
        case 0x80:
            func_08070058(p, 47);
            break;
        case 0xC0:
            func_08070058(p, 59);
            break;
        case 0x40:
            func_08070058(p, 59);
            break;
        case 0xAD:
            func_08070058(p, 53);
            break;
        case 0x53:
            func_08070058(p, 53);
            break;
        case 0xD3:
            func_08070058(p, 65);
            break;
        case 0x2D:
            func_08070058(p, 65);
            break;
        }

        p->unk_02C += gSineTable[p->unk_1AB] * p->unk_19C >> 8;
        p->unk_030 += p->unk_19C * -gSineTable[p->unk_1AB + 64] >> 8;
        p->unk_034 += p->unk_18C;
        p->unk_18C += 51;

        if (p->unk_034 > p->unk_198) {
            p->unk_034 = p->unk_198;
            p->unk_1AF = 5;
            p->unk_1A8 = 0;
        }
        break;
    case 5:
        switch (p->unk_1AB) {
        case 0x00:
            func_08070058(p, 42);
            break;
        case 0x80:
            func_08070058(p, 48);
            break;
        case 0xC0:
            func_08070058(p, 60);
            break;
        case 0x40:
            func_08070058(p, 60);
            break;
        case 0xAD:
            func_08070058(p, 54);
            break;
        case 0x53:
            func_08070058(p, 54);
            break;
        case 0xD3:
            func_08070058(p, 66);
            break;
        case 0x2D:
            func_08070058(p, 66);
            break;
        }

        p->unk_19C = 204 * p->unk_19C >> 8;

        if ((GetKeysPressed() & 2) != 0) {
            p->unk_1AF = 1;
            p->unk_18C = -0x540;
        } else if (p->unk_1A8 > 10) {
            p->unk_1AC = 255;
            SetTaskUpdate(a, (void*)func_080700D4);
        } else {
            p->unk_1A8++;
        }
        break;
    }

    TaskPoolUpdate(&p->unk_010);
    return 1;
}
#ifdef VERSION_EU
#define MSG_SOUND_ID_9E 0x9C
#define MSG_SOUND_ID_B1 0xAF
#else
#define MSG_SOUND_ID_9E 0x9E
#define MSG_SOUND_ID_B1 0xB1
#endif

s32 func_08070AD4(Work0806180C* p) {
    u16 x;
    u16 y;

    x = (p->unk_02C >> 8) - (gUnk_02039DC8->unk_58 >> 8);
    y = (p->unk_030 >> 8) + (p->unk_034 >> 8) - (gUnk_02039DC8->unk_5C >> 8);

    switch (p->unk_000[p->unk_1A0].unk_00) {
    case 0x2EB:
    case 0x2F1:
    case 0x2F2:
        if (p->unk_024 != MSG_SOUND_ID_9E) {
            if (p->unk_040->timer == 0) {
                if (p->unk_040->frame == 2) {
                    m4aSongNumStart(0x3BE);
                    func_08076110(0x3BE, x, y);
                }
                if (p->unk_040->frame == 6) {
                    m4aSongNumStart(0x3BF);
                    func_08076110(0x3BF, x, y);
                }
            }
        }
        break;
    case 0x2E6:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 2) {
                m4aSongNumStart(0x3AC);
                func_08076110(0x3AC, x, y);
            }
            if (p->unk_040->frame == 6) {
                m4aSongNumStart(0x3AD);
                func_08076110(0x3AD, x, y);
            }
        }
        break;
    case 0x375:
        if (p->unk_040->timer == 1) {
            if (p->unk_040->frame == 0) {
                m4aSongNumStart(0x3B4);
                func_08076110(0x3B4, x, y);
            }
            if (p->unk_040->frame == 4) {
                m4aSongNumStart(0x3B5);
                func_08076110(0x3B5, x, y);
            }
        }
        break;
    case 0x398:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 2) {
                m4aSongNumStart(0x175);
                func_08076110(0x175, x, y);
            }
        }
        break;
    case 0x399:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 2) {
                m4aSongNumStart(0x176);
                func_08076110(0x176, x, y);
            }
        }
        break;
    case 0x5E:
        if (p->unk_040->timer == 9) {
            if (p->unk_040->frame == 3) {
                m4aSongNumStart(0x12E);
            }
        }
        break;
    case 0x1C2:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 1) {
                m4aSongNumStart(0x3AC);
                func_08076110(0x3AC, x, y);
            }
            if (p->unk_040->frame == 5) {
                m4aSongNumStart(0x3AD);
                func_08076110(0x3AD, x, y);
            }
        }
        break;
    case 0x1C0:
    case 0x1C1:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 1) {
                m4aSongNumStart(0x3AC);
                func_08076110(0x3AC, x, y);
            }
            if (p->unk_040->frame == 5) {
                m4aSongNumStart(0x3AD);
                func_08076110(0x3AD, x, y);
            }
        }
        break;
    case 0x34B:
    case 0x34C:
        if (p->unk_040->timer == 1) {
            if (p->unk_040->frame == 0) {
                m4aSongNumStart(0x3B4);
                func_08076110(0x3B4, x, y);
            }
            if (p->unk_040->frame == 4) {
                m4aSongNumStart(0x3B5);
                func_08076110(0x3B5, x, y);
            }
        }
        break;
    case 0x2B2:
        if (p->unk_040->timer == 1) {
            if (p->unk_040->frame == 0) {
                m4aSongNumStart(0x3B4);
                func_08076110(0x3B4, x, y);
            }
            if (p->unk_040->frame == 4) {
                m4aSongNumStart(0x3B5);
                func_08076110(0x3B5, x, y);
            }
        }
        break;
    case 0x204:
    case 0x206:
    case 0x207:
    case 0x208:
    case 0x209:
    case 0x20A:
    case 0x20B:
    case 0x2C7:
    case 0x2C8:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 3) {
                if ((u16)(p->unk_024 - MSG_SOUND_ID_B1) <= 1) {
                    m4aSongNumStart(0x384);
                    func_08076110(0x384, x, y);
                } else {
                    m4aSongNumStart(0x3B2);
                    func_08076110(0x3B2, x, y);
                }
            }
            if (p->unk_040->frame == 7) {
                if ((u16)(p->unk_024 - MSG_SOUND_ID_B1) <= 1) {
                    m4aSongNumStart(0x385);
                    func_08076110(0x385, x, y);
                } else {
                    m4aSongNumStart(0x3B3);
                    func_08076110(0x3B3, x, y);
                }
            }
        }
        break;
    case 0x2C5:
    case 0x2C6:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 2) {
                if ((u16)(p->unk_024 - MSG_SOUND_ID_B1) <= 1) {
                    m4aSongNumStart(0x384);
                    func_08076110(0x384, x, y);
                } else {
                    m4aSongNumStart(0x3B2);
                    func_08076110(0x3B2, x, y);
                }
            }
            if (p->unk_040->frame == 5) {
                if ((u16)(p->unk_024 - MSG_SOUND_ID_B1) <= 1) {
                    m4aSongNumStart(0x385);
                    func_08076110(0x385, x, y);
                } else {
                    m4aSongNumStart(0x3B3);
                    func_08076110(0x3B3, x, y);
                }
            }
        }
        break;
    case 0x371:
    case 0x372:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 3) {
                m4aSongNumStart(0x3B0);
                func_08076110(0x3B0, x, y);
            }
            if (p->unk_040->frame == 7) {
                m4aSongNumStart(0x3B1);
                func_08076110(0x3B1, x, y);
            }
        }
        break;
    case 0x1EE:
    case 0x1F6:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 1) {
                m4aSongNumStart(0x3A2);
                func_08076110(0x3A2, x, y);
            }
            if (p->unk_040->frame == 4) {
                m4aSongNumStart(0x3A3);
                func_08076110(0x3A3, x, y);
            }
        }
        break;
    case 0x345:
        if (p->unk_040->timer == 1) {
            if (p->unk_040->frame == 0) {
                m4aSongNumStart(0x39E);
                func_08076110(0x39E, x, y);
            }
            if (p->unk_040->frame == 4) {
                m4aSongNumStart(0x39F);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x344:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 2) {
                m4aSongNumStart(0x39E);
                func_08076110(0x39E, x, y);
            }
            if (p->unk_040->frame == 5) {
                m4aSongNumStart(0x39F);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x341:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 3) {
                m4aSongNumStart(0x39E);
                func_08076110(0x39E, x, y);
            }
            if (p->unk_040->frame == 9) {
                m4aSongNumStart(0x39F);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x30C:
    case 0x30D:
    case 0x30E:
    case 0x30F:
    case 0x310:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 3) {
                m4aSongNumStart(0x39E);
                func_08076110(0x39E, x, y);
            }
            if (p->unk_040->frame == 9) {
                m4aSongNumStart(0x39F);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x275:
    case 0x276:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 1) {
                m4aSongNumStart(0x3AE);
                func_08076110(0x3AE, x, y);
            }
            if (p->unk_040->frame == 5) {
                m4aSongNumStart(0x3AF);
                func_08076110(0x3AF, x, y);
            }
        }
        break;
    case 0x277:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 3) {
                m4aSongNumStart(0x3AE);
                func_08076110(0x3AE, x, y);
            }
            if (p->unk_040->frame == 7) {
                m4aSongNumStart(0x3AF);
                func_08076110(0x3AF, x, y);
            }
        }
        break;
    case 0x2A5:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 3) {
                m4aSongNumStart(0x3AA);
                func_08076110(0x3AA, x, y);
            }
            if (p->unk_040->frame == 7) {
                m4aSongNumStart(0x3AB);
                func_08076110(0x3AB, x, y);
            }
        }
        break;
    case 0x2A8:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 2) {
                m4aSongNumStart(0x3A0);
                func_08076110(0x3A0, x, y);
            }
            if (p->unk_040->frame == 6) {
                m4aSongNumStart(0x3A1);
                func_08076110(0x3A1, x, y);
            }
        }
        break;
    case 0x271:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 1) {
                m4aSongNumStart(0x3A2);
                func_08076110(0x3A2, x, y);
            }
            if (p->unk_040->frame == 5) {
                m4aSongNumStart(0x3A3);
                func_08076110(0x3A3, x, y);
            }
        }
        break;
    case 0x241:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 1) {
                m4aSongNumStart(0x3A8);
                func_08076110(0x3A8, x, y);
            }
            if (p->unk_040->frame == 4) {
                m4aSongNumStart(0x3A9);
                func_08076110(0x3A9, x, y);
            }
        }
        break;
    case 0x17A:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 2) {
                m4aSongNumStart(0x3B0);
                func_08076110(0x3B0, x, y);
            }
            if (p->unk_040->frame == 5) {
                m4aSongNumStart(0x3B1);
                func_08076110(0x3B1, x, y);
            }
        }
        break;
    case 0x178:
    case 0x179:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 2) {
                m4aSongNumStart(0x3B0);
                func_08076110(0x3B0, x, y);
            }
            if (p->unk_040->frame == 6) {
                m4aSongNumStart(0x3B1);
                func_08076110(0x3B1, x, y);
            }
        }
        break;
    case 0x19C:
    case 0x19D:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 2) {
                m4aSongNumStart(0x3B4);
                func_08076110(0x3B4, x, y);
            }
            if (p->unk_040->frame == 6) {
                m4aSongNumStart(0x3B5);
                func_08076110(0x3B5, x, y);
            }
        }
        break;
    case 0x14A:
    case 0x14B:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 0) {
                m4aSongNumStart(0x3B6);
                func_08076110(0x3B6, x, y);
            }
            if (p->unk_040->frame == 4) {
                m4aSongNumStart(0x3B7);
                func_08076110(0x3B7, x, y);
            }
        }
        break;
    case 0x157:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 0) {
                m4aSongNumStart(0x3A6);
                func_08076110(0x3A6, x, y);
            }
            if (p->unk_040->frame == 4) {
                m4aSongNumStart(0x3A7);
                func_08076110(0x3A7, x, y);
            }
        }
        break;
    case 0x23E:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 1) {
                m4aSongNumStart(0x3B2);
                func_08076110(0x3B2, x, y);
            }
            if (p->unk_040->frame == 5) {
                m4aSongNumStart(0x3B3);
                func_08076110(0x3B3, x, y);
            }
        }
        break;
    case 0x16C:
    case 0x16E:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 1) {
                m4aSongNumStart(0x3A0);
                func_08076110(0x3A0, x, y);
            }
            if (p->unk_040->frame == 5) {
                m4aSongNumStart(0x3A1);
                func_08076110(0x3A1, x, y);
            }
        }
        break;
    case 0x122:
    case 0x123:
    case 0x128:
    case 0x129:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 2) {
                m4aSongNumStart(0x3A2);
                func_08076110(0x3A2, x, y);
            }
            if (p->unk_040->frame == 6) {
                m4aSongNumStart(0x3A3);
                func_08076110(0x3A3, x, y);
            }
        }
        break;
    case 0xDF:
    case 0xE0:
    case 0xE1:
    case 0xE2:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 1) {
                if (p->unk_024 == 0x61) {
                    m4aSongNumStart(0x3AE);
                    func_08076110(0x3AE, x, y);
                } else {
                    m4aSongNumStart(0x3B2);
                    func_08076110(0x3B2, x, y);
                }
            }
            if (p->unk_040->frame == 5) {
                if (p->unk_024 == 0x61) {
                    m4aSongNumStart(0x3AF);
                    func_08076110(0x3AF, x, y);
                } else {
                    m4aSongNumStart(0x3B3);
                    func_08076110(0x3B3, x, y);
                }
            }
        }
        break;
    case 0xD6:
    case 0xD9:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 1) {
                m4aSongNumStart(0x3B0);
                func_08076110(0x3B0, x, y);
            }
            if (p->unk_040->frame == 5) {
                m4aSongNumStart(0x3B1);
                func_08076110(0x3B1, x, y);
            }
        }
        break;
    case 0xCA:
    case 0xCB:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 1) {
                m4aSongNumStart(0x3BA);
                func_08076110(0x3BA, x, y);
            }
            if (p->unk_040->frame == 4) {
                m4aSongNumStart(0x3BB);
                func_08076110(0x3BB, x, y);
            }
        }
        break;
    case 0xD3:
    case 0xD4:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 1) {
                m4aSongNumStart(0x3BC);
                func_08076110(0x3BC, x, y);
            }
            if (p->unk_040->frame == 4) {
                m4aSongNumStart(0x3BD);
                func_08076110(0x3BD, x, y);
            }
        }
        break;
    case 0x10A:
    case 0x10B:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 1) {
                m4aSongNumStart(0x39E);
                func_08076110(0x39E, x, y);
            }
            if (p->unk_040->frame == 4) {
                m4aSongNumStart(0x39F);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x83:
    case 0x88:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 3) {
                m4aSongNumStart(0x130);
                func_08076110(0x130, x, y);
            }
        }
        break;
    case 0x12:
    case 0x13:
    case 0x66:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 1) {
                m4aSongNumStart(0x12E);
                func_08076110(0x12E, x, y);
            }
        }
        break;
    case 0x5:
    case 0x6:
    case 0x7:
    case 0x8:
    case 0x9:
        if (((Ent09EE3CA0*)gUnk_09EE3CA0[p->unk_024]) != 0) {
            if (p->unk_040->timer == 0) {
                if (p->unk_040->frame == 1) {
                    func_08072918((Actor0806180C*)p, ((Ent09EE3CA0*)gUnk_09EE3CA0[p->unk_024])->unk_2C, 1);
                }
                if (p->unk_040->frame == 5) {
                    func_08072918((Actor0806180C*)p, ((Ent09EE3CA0*)gUnk_09EE3CA0[p->unk_024])->unk_2C, 0);
                }
            }
        }
        break;
    case 0x75:
    case 0x77:
    case 0x288:
    case 0x28C:
        if (((Ent09EE3CA0*)gUnk_09EE3CA0[p->unk_024]) != 0) {
            if (p->unk_040->timer == 0) {
                if (p->unk_040->frame == 2) {
                    func_08072A64((Actor0806180C*)p, ((Ent09EE3CA0*)gUnk_09EE3CA0[p->unk_024])->unk_2C, 1);
                }
                if (p->unk_040->frame == 6) {
                    func_08072A64((Actor0806180C*)p, ((Ent09EE3CA0*)gUnk_09EE3CA0[p->unk_024])->unk_2C, 0);
                }
            }
        }
        break;
    case 0x78:
    case 0x79:
    case 0x289:
    case 0x28D:
        if (((Ent09EE3CA0*)gUnk_09EE3CA0[p->unk_024]) != 0) {
            if (p->unk_040->timer == 0) {
                if (p->unk_040->frame == 3) {
                    func_08072A64((Actor0806180C*)p, ((Ent09EE3CA0*)gUnk_09EE3CA0[p->unk_024])->unk_2C, 1);
                }
                if (p->unk_040->frame == 7) {
                    func_08072A64((Actor0806180C*)p, ((Ent09EE3CA0*)gUnk_09EE3CA0[p->unk_024])->unk_2C, 0);
                }
            }
        }
        break;
    case 0x95:
    case 0x97:
    case 0x98:
    case 0x99:
    case 0x265:
    case 0x266:
    case 0x267:
        if (((Ent09EE3CA0*)gUnk_09EE3CA0[p->unk_024]) != 0) {
            if (p->unk_040->timer == 0) {
                if (p->unk_040->frame == 3) {
                    func_08072B4C((Actor0806180C*)p, ((Ent09EE3CA0*)gUnk_09EE3CA0[p->unk_024])->unk_2C, 1);
                }
                if (p->unk_040->frame == 7) {
                    func_08072B4C((Actor0806180C*)p, ((Ent09EE3CA0*)gUnk_09EE3CA0[p->unk_024])->unk_2C, 0);
                }
            }
        }
        break;
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
        if (((Ent09EE3CA0*)gUnk_09EE3CA0[p->unk_024]) != 0) {
            if (p->unk_040->timer == 0) {
                if (p->unk_040->frame == 3) {
                    func_08072918((Actor0806180C*)p, ((Ent09EE3CA0*)gUnk_09EE3CA0[p->unk_024])->unk_2C, 1);
                }
                if (p->unk_040->frame == 7) {
                    func_08072918((Actor0806180C*)p, ((Ent09EE3CA0*)gUnk_09EE3CA0[p->unk_024])->unk_2C, 0);
                }
            }
        }
        break;
    case 0xB8:
    case 0xBA:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 2) {
                m4aSongNumStart(0x3B4);
                func_08076110(0x3B4, x, y);
            }
            if (p->unk_040->frame == 6) {
                m4aSongNumStart(0x3B5);
                func_08076110(0x3B5, x, y);
            }
        }
        break;
    case 0xBB:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 0) {
                m4aSongNumStart(0x140);
                func_08076110(0x140, x, y);
            }
        }
        break;
    case 0xC1:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 0) {
                m4aSongNumStart(0x14E);
                func_08076110(0x14E, x, y);
            }
        }
        break;
    case 0xE9:
    case 0xEA:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 1) {
                m4aSongNumStart(0x144);
                func_08076110(0x144, x, y);
            }
        }
        break;
    case 0xF2:
    case 0xF3:
    case 0xF4:
    case 0xF8:
    case 0xF9:
    case 0xFA:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 1) {
                m4aSongNumStart(0x39D);
                func_08076110(0x39D, x, y);
            }
            if (p->unk_040->frame == 5) {
                m4aSongNumStart(0x39C);
                func_08076110(0x39C, x, y);
            }
        }
        break;
    case 0xF5:
    case 0xF6:
    case 0xF7:
    case 0xFB:
    case 0xFC:
    case 0xFD:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 1) {
                m4aSongNumStart(0x39C);
                func_08076110(0x39C, x, y);
            }
            if (p->unk_040->frame == 4) {
                m4aSongNumStart(0x39D);
                func_08076110(0x39D, x, y);
            }
        }
        break;
    case 0x280:
    case 0x281:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 7) {
                m4aSongNumStart(0x3B0);
                func_08076110(0x3B0, x, y);
            }
            if (p->unk_040->frame == 2) {
                m4aSongNumStart(0x3B1);
                func_08076110(0x3B1, x, y);
            }
        }
        break;
    case 0x18D:
    case 0x18E:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 6) {
                m4aSongNumStart(0x3A2);
                func_08076110(0x3A2, x, y);
            }
            if (p->unk_040->frame == 2) {
                m4aSongNumStart(0x3A3);
                func_08076110(0x3A3, x, y);
            }
        }
        break;
    case 0x18F:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 4) {
                m4aSongNumStart(0x26B);
            }
        }
        break;
    case 0x159:
    case 0x15D:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 6) {
                m4aSongNumStart(0x3B0);
                func_08076110(0x3B0, x, y);
            }
            if (p->unk_040->frame == 2) {
                m4aSongNumStart(0x3B1);
                func_08076110(0x3B1, x, y);
            }
        }
        break;
    case 0x15E:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 0) {
                m4aSongNumStart(0x14E);
                func_08076110(0x14E, x, y);
            }
        }
        break;
    case 0x185:
    case 0x186:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 6) {
                m4aSongNumStart(0x3A2);
                func_08076110(0x3A2, x, y);
            }
            if (p->unk_040->frame == 2) {
                m4aSongNumStart(0x3A3);
                func_08076110(0x3A3, x, y);
            }
        }
        break;
    case 0x187:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 7) {
                m4aSongNumStart(0x3A2);
                func_08076110(0x3A2, x, y);
            }
            if (p->unk_040->frame == 3) {
                m4aSongNumStart(0x3A3);
                func_08076110(0x3A3, x, y);
            }
        }
        break;
    case 0x2E7:
    case 0x2E8:
        if (p->unk_040->timer == 1) {
            if (p->unk_040->frame == 0) {
                m4aSongNumStart(0x155);
                func_08076110(0x155, x, y);
            }
        }
        break;
    case 0x2AE:
    case 0x2AF:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 6) {
                m4aSongNumStart(0x3AC);
                func_08076110(0x3AC, x, y);
            }
            if (p->unk_040->frame == 2) {
                m4aSongNumStart(0x3AD);
                func_08076110(0x3AD, x, y);
            }
        }
        break;
    case 0x1C5:
    case 0x1C6:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 6) {
                m4aSongNumStart(0x3AC);
                func_08076110(0x3AC, x, y);
            }
            if (p->unk_040->frame == 2) {
                m4aSongNumStart(0x3AD);
                func_08076110(0x3AD, x, y);
            }
        }
        break;
    case 0x27A:
    case 0x27D:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 6) {
                m4aSongNumStart(0x3B4);
                func_08076110(0x3B4, x, y);
            }
            if (p->unk_040->frame == 2) {
                m4aSongNumStart(0x3B5);
                func_08076110(0x3B5, x, y);
            }
        }
        break;
    case 0x10F:
    case 0x11B:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 6) {
                m4aSongNumStart(0x39E);
                func_08076110(0x39E, x, y);
            }
            if (p->unk_040->frame == 2) {
                m4aSongNumStart(0x39F);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x110:
    case 0x11C:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 5) {
                m4aSongNumStart(0x39E);
                func_08076110(0x39E, x, y);
            }
            if (p->unk_040->frame == 2) {
                m4aSongNumStart(0x39F);
                func_08076110(0x39F, x, y);
            }
        }
        break;
    case 0x118:
        if (p->unk_040->timer == 1) {
            if (p->unk_040->frame == 0) {
                m4aSongNumStart(0x156);
                func_08076110(0x156, x, y);
            }
        }
        break;
    case 0x29E:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 3) {
                m4aSongNumStart(0xC5);
                func_08076110(0xC5, x, y);
            }
        }
        break;
    case 0x2A2:
        if (p->unk_040->timer == 0) {
            if (p->unk_040->frame == 1) {
                m4aSongNumStart(0x157);
            }
        }
        break;
    case 0x1DE:
        if (p->unk_040->timer == 1) {
            if (p->unk_040->frame == 0) {
                m4aSongNumStart(0x227);
                func_08076110(0x227, x, y);
            }
        }
        break;
    }
}

void func_08072918(Actor0806180C* a, u8 kind, u8 flag) {
    u16 x;
    u16 y;

    x = (a->unk_2C >> 8) - (gUnk_02039DC8->unk_58 >> 8);
    y = (a->unk_30 >> 8) + (a->unk_34 >> 8) - (gUnk_02039DC8->unk_5C >> 8);

    switch (kind) {
    case 0:
        if (flag != 0) {
            m4aSongNumStart(0x384);
            func_08076110(0x384, x, y);
        } else {
            m4aSongNumStart(0x385);
            func_08076110(0x385, x, y);
        }
        break;
    case 1:
        if (flag == 0) {
            m4aSongNumStart(0x389);
            func_08076110(0x389, x, y);
        } else {
            m4aSongNumStart(0x388);
            func_08076110(0x388, x, y);
        }
        break;
    case 2:
        if ((a->unk_24 == 0x4B && gUnk_02039DC8->unk_6C > 0x2BC) || (a->unk_24 == 0x36 && gUnk_02039DC8->unk_6C <= 0x4F)) {
            if (flag != 0) {
                m4aSongNumStart(0x388);
                func_08076110(0x388, x, y);
            } else {
                m4aSongNumStart(0x389);
                func_08076110(0x389, x, y);
            }

            if (flag != 0) {
                m4aSongNumStart(0x388);
                func_08076110(0x388, x, y);
            } else {
                m4aSongNumStart(0x389);
                func_08076110(0x389, x, y);
            }
        } else {
            if (flag != 0) {
                m4aSongNumStart(0x38C);
                func_08076110(0x38C, x, y);
            } else {
                m4aSongNumStart(0x38D);
                func_08076110(0x38D, x, y);
            }
        }
        break;
    case 3:
        if (flag != 0) {
            m4aSongNumStart(0x388);
            func_08076110(0x388, x, y);
        } else {
            m4aSongNumStart(0x389);
            func_08076110(0x389, x, y);
        }
        break;
    }
}

void func_08072A64(Actor0806180C* a, u8 kind, u8 flag) {
    u16 x;
    u16 y;

    x = (a->unk_2C >> 8) - (gUnk_02039DC8->unk_58 >> 8);
    y = (a->unk_30 >> 8) + (a->unk_34 >> 8) - (gUnk_02039DC8->unk_5C >> 8);

    switch (kind) {
    case 0:
        if (flag != 0) {
            m4aSongNumStart(0x394);
            func_08076110(0x394, x, y);
        } else {
            m4aSongNumStart(0x395);
            func_08076110(0x395, x, y);
        }
        break;
    case 1:
        if (flag == 0) {
            m4aSongNumStart(0x391);
            func_08076110(0x391, x, y);
        } else {
            m4aSongNumStart(0x390);
            func_08076110(0x390, x, y);
        }
        break;
    case 2:
        if (a->unk_24 == 0x4B && gUnk_02039DC8->unk_6C > 0x2BC) {
            if (flag == 0) {
                m4aSongNumStart(0x391);
                func_08076110(0x391, x, y);
            } else {
                m4aSongNumStart(0x390);
                func_08076110(0x390, x, y);
            }
        } else {
            if (flag != 0) {
                m4aSongNumStart(0x398);
                func_08076110(0x398, x, y);
            } else {
                m4aSongNumStart(0x399);
                func_08076110(0x399, x, y);
            }
        }
        break;
    case 3:
        if (flag != 0) {
            m4aSongNumStart(0x390);
            func_08076110(0x390, x, y);
        } else {
            m4aSongNumStart(0x391);
            func_08076110(0x391, x, y);
        }
        break;
    }
}

void func_08072B4C(Actor0806180C* a, u8 kind, u8 flag) {
    u16 x;
    u16 y;

    x = (a->unk_2C >> 8) - (gUnk_02039DC8->unk_58 >> 8);
    y = (a->unk_30 >> 8) + (a->unk_34 >> 8) - (gUnk_02039DC8->unk_5C >> 8);

    switch (kind) {
    case 0:
        if (flag != 0) {
            m4aSongNumStart(0x396);
            func_08076110(0x396, x, y);
        } else {
            m4aSongNumStart(0x397);
            func_08076110(0x397, x, y);
        }
        break;
    case 1:
        if (flag == 0) {
            m4aSongNumStart(0x393);
            func_08076110(0x393, x, y);
        } else {
            m4aSongNumStart(0x392);
            func_08076110(0x392, x, y);
        }
        break;
    case 2:
        if (a->unk_24 == 0x4B && gUnk_02039DC8->unk_6C > 0x2BC) {
            if (flag == 0) {
                m4aSongNumStart(0x393);
                func_08076110(0x393, x, y);
            } else {
                m4aSongNumStart(0x392);
                func_08076110(0x392, x, y);
            }
        } else {
            if (flag != 0) {
                m4aSongNumStart(0x39A);
                func_08076110(0x39A, x, y);
            } else {
                m4aSongNumStart(0x39B);
                func_08076110(0x39B, x, y);
            }
        }
        break;
    case 3:
        if (flag != 0) {
            m4aSongNumStart(0x392);
            func_08076110(0x392, x, y);
        } else {
            m4aSongNumStart(0x393);
            func_08076110(0x393, x, y);
        }
        break;
    }
}

void func_08072C34(Work0806180C* p) {
    switch (p->unk_026) {
    case 6:
    case 16:
    case 20:
    case 21:
    case 22:
    case 32:
        p->unk_03C |= 8;
        break;
    case 37:
        func_08075E60(p);
    case 8:
    case 10:
    case 33:
    case 38:
    case 39:
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
        p->unk_03C |= 0x10;
        break;
    case 0:
        break;
    }
}
#ifdef VERSION_EU
#define MSG_WIN_ID_A 0x84
#define MSG_WIN_ID_B 0x9A
#else
#define MSG_WIN_ID_A 0x86
#define MSG_WIN_ID_B 0x9C
#endif

void func_08072D98(MsgWinWork* p, u8* arg) {
    UnkStruct_09EE3FB4* t;

    p->unk_28 = arg[0];

    switch (p->unk_28) {
    case 11:
        p->unk_1C = func_08064D04(0);
        break;
    case 3:
    case MSG_WIN_ID_A:
    case MSG_WIN_ID_B:
        p->unk_1C = func_08064C34(0);
        break;
    default:
        p->unk_1C = func_08064B80(0);
        break;
    }

    if (gUnk_09EE3CA0[p->unk_28] != NULL) {
        p->unk_38 = 0;
    } else {
        p->unk_38 = 2;
    }
    LoadBgTiles(p->unk_38, gUnk_094233B8, 0x500);
    LoadBgPalette(p->unk_38, gUnk_096148D8, 32);
    LoadBgMap(p->unk_38, gUnk_08125E24, 0x800);
    SetBgPriority(p->unk_38, 0);
    t = gUnk_09EE3FB4[p->unk_28];
    p->palette = NULL;
    p->unk_1E = 0;
    p->unk_24 = 0;
    p->unk_25 = 0;
    p->unk_26 = 0;
    p->unk_27 = 0;
    p->unk_29 = 0;
    p->unk_2A = 0;
    p->unk_3C = t->unk_0C;
    p->unk_2B = 0;
    p->unk_18 = 0;
    p->unk_40 = 0;
    gUnk_02039DC8->unk_81 = 0;
    gUnk_02039DC8->unk_7D = 0;
    gUnk_02039DC8->unk_8B = 0;
    TaskPoolInit(p, 2);
    func_08073E0C(p, &p->unk_2C, p->unk_3C->unk_00, p->unk_3C->unk_04, p->unk_3C->unk_08);
}

u8 func_08072EAC(MsgWinWork* p, void* a) {
    MsgLine0806180C* e;

    if (p->unk_29 == 0) {
        if (gUnk_02039DC8->unk_80 == 0) {
            func_08073508(p);
        }
    } else {
        func_080736F8(p);
    }

    if (p->unk_2A != 0) {
        gUnk_02039DC8->unk_87 = p->unk_20;

        if (gUnk_02039DC8->unk_7C != 0) {
            if (gUnk_02039DC8->unk_89 != 0) {
                gUnk_02039DC8->unk_89--;
            } else {
                e = &p->unk_3C[p->unk_27];

                if (e->unk_00 == 62) {
                    void* pal;

                    pal = (void*)0x050001E0;
                    LoadBgTiles(p->unk_38, gUnk_0950E2F8, 0x140);
                    LoadBgMap(p->unk_38, gUnk_096112B8, 0x800);
                    LoadPalette(gUnk_09611AB8, pal, 32);

                    if ((e->unk_14 & 0x80) != 0) {
                        func_080062F4(15, 1);
                    }
                    gUnk_02039DC8->unk_81 = 1;

                    switch (e->unk_08) {
                    case 0:
                    case 2:
                        SetBgScroll(p->unk_38, (u16)-0x28, 0);
                        break;
                    case 1:
                    case 3:
                        SetBgScroll(p->unk_38, (u16)-0x28, (u16)-0x60);
                        break;
                    }

                    if (p->palette == NULL) {
                        p->palette = LoadObjPalette(gUnk_09614718, 32);

                        if ((e->unk_14 & 0x80) != 0) {
                            func_080062F4(((Handle0806180C*)p->palette)->unk_06 + 16, 1);
                        }
                    }
                    _08073E6C(&p->unk_2C);
                    SetTaskUpdate(a, (void*)func_08073294);
                    gUnk_02039DC8->unk_8B = 1;
                } else {
                    LoadBgTiles(p->unk_38, gUnk_094233B8, 0x500);
                    LoadBgPalette(p->unk_38, gUnk_096148D8, 32);
                    func_0800516C(p->unk_38, gUnk_09EE4724[p->unk_20], 2, 1);
                    func_080051C4(p->unk_38, p->unk_18, 0);
                    SetTaskUpdate(a, (void*)func_08073294);
                    _08073E6C(&p->unk_2C);
                    gUnk_02039DC8->unk_81 = 1;

                    if (p->palette != NULL) {
                        ReleaseObjPalette(p->palette);
                        p->palette = NULL;
                    }
                    gUnk_02039DC8->unk_8B = 0;
                }
            }
        } else {
        e = &p->unk_3C[p->unk_27];

        if (e->unk_00 == 62) {
            void* pal;

            pal = (void*)0x050001E0;
            LoadBgTiles(p->unk_38, gUnk_0950E2F8, 0x140);
            LoadBgMap(p->unk_38, gUnk_096112B8, 0x800);
            LoadPalette(gUnk_09611AB8, pal, 32);

            if ((e->unk_14 & 0x80) != 0) {
                func_080062F4(15, 1);
            }
            gUnk_02039DC8->unk_81 = 1;

            switch (e->unk_08) {
            case 0:
            case 2:
                SetBgScroll(p->unk_38, (u16)-0x18, 0);
                break;
            case 1:
            case 3:
                SetBgScroll(p->unk_38, (u16)-0x18, (u16)-0x60);
                break;
            }

            if (p->palette == NULL) {
                p->palette = LoadObjPalette(gUnk_09614718, 32);

                if ((e->unk_14 & 0x80) != 0) {
                func_080062F4(((Handle0806180C*)p->palette)->unk_06 + 16, 1);
                }
            }
            _08073E6C(&p->unk_2C);
            SetTaskUpdate(a, (void*)func_08073294);
            gUnk_02039DC8->unk_8B = 1;
        } else {
            LoadBgTiles(p->unk_38, gUnk_094233B8, 0x500);
            LoadBgPalette(p->unk_38, gUnk_096148D8, 32);
            func_0800516C(p->unk_38, gUnk_09EE4724[p->unk_20], 2, 1);
            func_080051C4(p->unk_38, p->unk_18, 0);
            SetTaskUpdate(a, (void*)func_08073294);
            _08073E6C(&p->unk_2C);
            gUnk_02039DC8->unk_81 = 1;

            if (p->palette != NULL) {
                ReleaseObjPalette(p->palette);
                p->palette = NULL;
            }
            gUnk_02039DC8->unk_8B = 0;
        }
        }
    }

    if (gUnk_02039DC8->unk_82 == 1) {
        func_080062F4(p->unk_1C + 16, 0);
        func_080062F4(14, 0);
    } else {
        func_080062F4(p->unk_1C + 16, 1);
        func_080062F4(14, 1);
    }
    TaskPoolUpdate(p);
    return 1;
}
u8 func_08073170(MsgWinWork* p, void* a) {
    if (p->unk_29 == 0) {
        if (gUnk_02039DC8->unk_80 == 0) {
            func_08073508(p);
        }
    } else {
        func_080736F8(p);
    }

    if (p->unk_2A != 0) {
        gUnk_02039DC8->unk_87 = p->unk_20;

        if (gUnk_02039DC8->unk_7C != 0) {
            if (gUnk_02039DC8->unk_89 != 0) {
                gUnk_02039DC8->unk_89--;
            } else {
                SetTaskUpdate(a, (void*)func_08073294);
                _08073E6C(&p->unk_2C);
                gUnk_02039DC8->unk_81 = 1;
            }
        } else {
            SetTaskUpdate(a, (void*)func_08073294);
            _08073E6C(&p->unk_2C);
            gUnk_02039DC8->unk_81 = 1;
        }
    }

    if (gUnk_02039DC8->unk_82 == 1) {
        func_080062F4(p->unk_1C + 16, 0);
        func_080062F4(14, 0);
    } else {
        func_080062F4(p->unk_1C + 16, 1);
        func_080062F4(14, 1);
    }
    TaskPoolUpdate(p);
    return 1;
}
void func_08073238(MsgWinWork* p) {
    MsgLine0806180C* e = &p->unk_3C[p->unk_27];

    if (e->unk_00 != 62) {
        func_080658B8(p->unk_24);
    } else {
        _0806C3A0(p->unk_24, p->palette);
    }
    TaskPoolDraw(p);
}
void func_08073274(MsgWinWork* p) {
    if (p->palette != NULL) {
        ReleaseObjPalette(p->palette);
    }
    func_08065940();
    TaskPoolDestroy(p);
}
u8 func_08073294(MsgWinWork* p, void* a) {
    MsgLine0806180C* e = &p->unk_3C[p->unk_27];

    ApproachValue(&p->unk_18, gUnk_09033CA0[p->unk_20], p->unk_1E);

    if (e->unk_00 != 62) {
        func_08005244(p->unk_38, p->unk_18, 0);
    }

    if (p->unk_1E != 0) {
        p->unk_1E--;
    } else {
        p->unk_1E = 0;

        if ((e->unk_14 & 0xF) == 0) {
            gUnk_02039DC8->unk_7B = 1;
        }
        SetTaskUpdate(a, (void*)func_08073318);
    }
    TaskPoolUpdate(p);
    return 1;
}
u8 func_08073318(MsgWinWork* p, void* a) {
    MsgLine0806180C* e = &p->unk_3C[p->unk_27];

    func_0807361C(p);

    if (e->unk_00 == 62) {
        p->unk_24 = p->unk_26;
    } else if (GetKeysPressed() & 1) {
        if (p->unk_24 < p->unk_26) {
            p->unk_24 = p->unk_26;
        }
    }

    if (p->unk_2B == 1 && gUnk_02039DC8->unk_7D == 0) {
        s32 text = p->unk_40;
        if (text != 0) {
            p->unk_1E = 0;
            p->unk_29 = 0;
            p->unk_2A = 1;
            p->unk_34 = 1;
            SetTaskUpdate(a, (void*)func_08073170);
        } else {
            _08065994();

            if ((e->unk_14 & 0x8000) == 0) {
                if (p->unk_3C[p->unk_27 + 1].unk_08 != 4) {
                    p->unk_1E = 8;
                    func_08073E74(&p->unk_2C);
                    SetTaskUpdate(a, (void*)func_0807344C);
                    gUnk_02039DC8->unk_81 = text;
                    p->unk_34 = text;
                } else {
                    p->unk_1E = text;
                    p->unk_29 = text;
                    p->unk_2A = text;
                    p->unk_27++;
                    gUnk_02039DC8->unk_64 &= ~1;
                    p->unk_34 = 1;
                    SetTaskUpdate(a, (void*)func_08072EAC);
                }
            } else {
                p->unk_1E = 8;
                func_08073E74(&p->unk_2C);
                SetTaskUpdate(a, (void*)func_0807344C);
                gUnk_02039DC8->unk_81 = text;
                p->unk_34 = text;
            }
        }
        p->unk_2B = 0;
    }
    TaskPoolUpdate(p);
    return 1;
}
u8 func_0807344C(MsgWinWork* p, void* a) {
    MsgLine0806180C* e = &p->unk_3C[p->unk_27];

    ApproachValue(&p->unk_18, gUnk_09033C98[p->unk_20], p->unk_1E);

    if (e->unk_00 != 62) {
        func_08005244(p->unk_38, p->unk_18, 0);
    } else {
        DisableBg(p->unk_38);
    }

    if (p->unk_1E != 0) {
        p->unk_1E--;
    } else {
        p->unk_1E = 0;

        if ((gUnk_02039DC8->unk_64 & 4) == 0) {
            gUnk_02039DC8->unk_64 &= ~1;
        }
        gUnk_02039DC8->unk_7C = 0;

        if ((e->unk_14 & 0x8000) == 0) {
            p->unk_2A = 0;
            p->unk_29 = 0;
            p->unk_27++;
            SetTaskUpdate(a, (void*)func_08072EAC);
        }
    }
    TaskPoolUpdate(p);
    return 1;
}
void func_08073508(MsgWinWork* p) {
    MsgLine0806180C* e = &p->unk_3C[p->unk_27];
    s32 n;

    n = e->unk_08;

    if (n != 4) {
        p->unk_20 = n;
        p->unk_18 = gUnk_09033C98[n];
    }

    if ((e->unk_14 & 0x20) != 0) {
        p->unk_2C.unk_03 = 1;
    } else {
        p->unk_2C.unk_03 = 0;
    }
    func_08073E34(&p->unk_2C, e->unk_00, e->unk_04, p->unk_20);

#ifdef VERSION_JP
    if (e->unk_00 == 62) {
        p->unk_26 = func_080653D4(0x2E00, gUnk_09033CB8[p->unk_20], (u8*)e->unk_10);
    } else {
        p->unk_26 = func_080653D4(gUnk_09033CA8[p->unk_20], gUnk_09033CB8[p->unk_20], (u8*)e->unk_10);
    }
#else
    if (e->unk_00 == 62) {
        if (p->unk_40 != 0) {
            p->unk_26 = func_08064EF4(0x2E00, gUnk_09033CB8[p->unk_20] - 0x200, p->unk_40, &p->unk_40);
        } else {
            p->unk_26 = func_08064EF4(0x2E00, gUnk_09033CB8[p->unk_20] - 0x200, LANGSTR(e->unk_10), &p->unk_40);
        }
    } else {
        if (p->unk_40 != 0) {
            p->unk_26 = func_08064EF4(gUnk_09033CA8[p->unk_20], gUnk_09033CB8[p->unk_20] - 0x200, p->unk_40, &p->unk_40);
        } else {
            p->unk_26 = func_08064EF4(gUnk_09033CA8[p->unk_20], gUnk_09033CB8[p->unk_20] - 0x200, LANGSTR(e->unk_10), &p->unk_40);
        }
    }
#endif
    p->unk_25 = 0;
    p->unk_24 = 0;
    p->unk_29 = 1;
}

void func_0807361C(MsgWinWork* p) {
    MsgLine0806180C* e = &p->unk_3C[p->unk_27];
    u8 v;

    if (p->unk_25 >= e->unk_0C) {
        if (p->unk_24 < p->unk_26) {
            p->unk_24++;
            m4aSongNumStart(0x74);
        } else {
            gUnk_02039DC8->unk_7B = 0;

            if (p->unk_2B == 0) {
                if ((p->unk_3C[p->unk_27].unk_14 & 0x8000) == 0) {
                    if ((p->unk_3C[p->unk_27].unk_14 & 0x40) == 0) {
                        TaskCreate(p, &gTaskDescMsgface[1], &p->unk_3C[p->unk_27 + 1].unk_08);
                    } else {
                        TaskCreate(p, &gTaskDescMsgface[2], &p->unk_3C[p->unk_27 + 1].unk_08);
                    }
                } else {
                    v = 0;

                    if ((p->unk_3C[p->unk_27].unk_14 & 0x40) == 0) {
                        TaskCreate(p, &gTaskDescMsgface[1], &v);
                    } else {
                        TaskCreate(p, &gTaskDescMsgface[2], &v);
                    }
                }
                p->unk_2B = 1;
            }
        }
        p->unk_25 = 0;
    } else {
        p->unk_25++;
    }
}
void func_080736F8(MsgWinWork* p) {
    MsgLine0806180C* e = &p->unk_3C[p->unk_27];

    if (gUnk_02039DC8->unk_6C >= e->unk_16) {
        if (p->unk_2A == 0) {
            gUnk_02039DC8->unk_64 |= 1;
            p->unk_2A = 1;
            p->unk_1E = 8;

            if ((e->unk_14 & 0x10) != 0) {
                gUnk_02039DC8->unk_7C = 1;
                gUnk_02039DC8->unk_88 = e->unk_00;
                gUnk_02039DC8->unk_89 = 32;
            } else {
                gUnk_02039DC8->unk_7C = 0;
            }
        }
    }
}
void msgface_0(MsgFaceWork* p, MsgFaceCtl* ctl) {
    MsgFaceAnim* anim;
    u32 n;

    p->tiles = AllocObjTiles(0x12C0, 0);
    p->palette = AllocObjPalette(32);
    p->unk_38 = ctl;
    p->unk_30 = 0;
    p->x = gUnk_09033CD0[n = p->unk_38->unk_04];
    p->y = gUnk_09033CF0[n];
    p->unk_2C = 0x100;
    p->unk_31 = 0;
    p->unk_32 = 0;
    p->unk_34 = 1;

    if (p->unk_38->unk_00 != 62) {
        anim = gUnk_09EE45DC[p->unk_38->unk_00];
    } else {
        anim = gUnk_09EE45DC[0];
    }

    if (p->unk_38->unk_04 <= 1) {
        p->unk_33 = 1;
    } else if (p->unk_38->unk_04 <= 3) {
        p->unk_33 = 0;
    }

    if (p->unk_38->unk_00 != 62) {
        func_08002A10(p->tiles, anim[p->unk_38->unk_01].unk_00);
        func_08003A70(p->palette, anim[p->unk_38->unk_01].unk_04);
        AnimInit(p->anim, anim[p->unk_38->unk_01].unk_0C, anim[p->unk_38->unk_01].unk_08);
        AnimStart(p->anim, 0, anim[p->unk_38->unk_01].unk_11);
        p->gfx = AnimGetGfx(p->anim);
    } else {
        func_08002A10(p->tiles, anim->unk_00);
        func_08003A70(p->palette, anim->unk_04);
        AnimInit(p->anim, anim->unk_0C, anim->unk_08);
        AnimStart(p->anim, 0, anim->unk_11);
        p->gfx = AnimGetGfx(p->anim);
    }
}
u8 msgface_1(MsgFaceWork* p, void* a) {
    MsgFaceAnim* anim = NULL;
    u32 n;

    if (p->unk_38->unk_00 != 62) {
        anim = gUnk_09EE45DC[p->unk_38->unk_00];
        p->unk_34 = 1;
    } else {
        p->unk_34 = 0;
    }

    switch (p->unk_38->unk_02) {
    case 1:
        if (p->unk_38->unk_08 == 0) {
            p->x = gUnk_09033CD0[n = p->unk_38->unk_04];
            p->y = gUnk_09033CF0[n];
        }
        p->unk_30 = 8;

        if (anim != NULL) {
            if (p->unk_38->unk_03 == 1) {
                func_08003A70(p->palette, &gUnk_096148D8[0x100]);
            } else {
                func_08003A70(p->palette, anim[p->unk_38->unk_01].unk_04);
            }
        }

        SetTaskUpdate(a, (void*)func_08073B04);
        break;
    case 2:
        p->unk_30 = 8;
        p->unk_31 = 0;
        SetTaskUpdate(a, (void*)func_08073B54);
        break;
    case 4:
        p->unk_30 = 4;

        if (p->unk_38->unk_04 <= 1) {
            p->unk_2C = -255;
        } else if (p->unk_38->unk_04 <= 3) {
            p->unk_2C = 256;
        }

        p->y = gUnk_09033CF0[p->unk_38->unk_04];
        SetTaskUpdate(a, (void*)func_08073CA4);
        break;
    case 3:
        SetTaskUpdate(a, (void*)func_08073B9C);
        break;
    }

    if (gUnk_02039DC8->unk_7B == 1) {
        if (p->unk_32 == 0) {
            if (anim != NULL && anim[p->unk_38->unk_01].unk_10 > 1) {
                AnimStart(p->anim, 1, anim[p->unk_38->unk_01].unk_11);
            }

            p->unk_32 = 1;
        }
    } else {
        if (p->unk_32 == 1) {
            if (anim != NULL) {
                AnimStart(p->anim, 0, anim[p->unk_38->unk_01].unk_11);
            }

            p->unk_32 = 0;
        }
    }

    if (gUnk_02039DC8->unk_82 == 1) {
        func_080062F4(((Handle0806180C*)p->palette)->unk_06 + 16, 0);
    } else {
        func_080062F4(((Handle0806180C*)p->palette)->unk_06 + 16, 1);
    }

    p->gfx = AnimUpdate(p->anim);
    return 1;
}
void msgface_2(MsgFaceWork* p) {
    s32 t;
    u8 v;

    if (p->unk_34 != 0) {
        t = AllocObjAffine(0, p->unk_2C, 256, 0);
        if (t != 0) {
            DrawSprite(p->x >> 8, p->y >> 8, p->gfx, p->tiles, p->palette, t, 0, 50);
        } else {
            v = p->unk_33;
            if (v != 0) {
                DrawSprite(p->x >> 8, p->y >> 8, p->gfx, p->tiles, p->palette, t, 1, 50);
            } else {
                DrawSprite(p->x >> 8, p->y >> 8, p->gfx, p->tiles, p->palette, v, v, 50);
            }
        }
    }
}
void msgface_3(MsgFaceWork* p) {
    ReleaseObjTiles(p->tiles);
    ReleaseObjPalette(p->palette);
}
u8 func_08073B04(MsgFaceWork* p, void* a) {
    ApproachValue(&p->x, gUnk_09033CE0[p->unk_38->unk_04], p->unk_30);
    p->unk_30--;
    if (p->unk_30 == 0) {
        p->unk_38->unk_02 = 0;
        p->unk_31 = 1;
        SetTaskUpdate(a, (void*)msgface_1);
    }
    return 1;
}
u8 func_08073B54(MsgFaceWork* p, void* a) {
    ApproachValue(&p->x, gUnk_09033CD0[p->unk_38->unk_04], p->unk_30);
    p->unk_30--;
    if (p->unk_30 == 0) {
        p->unk_38->unk_02 = 0;
        SetTaskUpdate(a, (void*)msgface_1);
    }
    return 1;
}
u8 func_08073B9C(MsgFaceWork* p, void* a) {
    MsgFaceAnim* t;
    s32 n;

    t = NULL;

    if (p->unk_38->unk_00 != 62) {
        t = gUnk_09EE45DC[p->unk_38->unk_00];
        p->unk_34 = 1;
    } else {
        p->unk_34 = 0;
    }

    if (p->unk_38->unk_04 <= 1) {
        p->unk_33 = 1;
    } else if (p->unk_38->unk_04 <= 3) {
        p->unk_33 = 0;
    }

    if (t != NULL) {
        func_08002A10(p->tiles, t[p->unk_38->unk_01].unk_00);
        func_08003A70(p->palette, t[p->unk_38->unk_01].unk_04);
        AnimInit(p->anim, t[p->unk_38->unk_01].unk_0C, t[p->unk_38->unk_01].unk_08);
        AnimStart(p->anim, 0, t[p->unk_38->unk_01].unk_11);
        p->gfx = AnimGetGfx(p->anim);
        p->unk_31 = 0;
        p->unk_30 = 8;
        p->unk_38->unk_02 = 0;
    }
    p->x = gUnk_09033CD0[n = p->unk_38->unk_04];
    p->y = gUnk_09033CF0[n];
    p->unk_2C = 256;
    p->unk_30 = 8;
    SetTaskUpdate(a, (void*)msgface_1);
    return 1;
}

u8 func_08073CA4(MsgFaceWork* p, void* a) {
    MsgFaceAnim* t;

    if (p->unk_2C < 0) {
        ApproachValue(&p->unk_2C, -2, p->unk_30);
    } else {
        ApproachValue(&p->unk_2C, 2, p->unk_30);
    }
    p->unk_30--;

    if (p->unk_30 == 0) {
        t = NULL;

        if (p->unk_38->unk_00 != 62) {
            t = gUnk_09EE45DC[p->unk_38->unk_00];
        }

        if (p->unk_38->unk_04 <= 1) {
            p->unk_33 = 1;
        } else if (p->unk_38->unk_04 <= 3) {
            p->unk_33 = 0;
        }

        if (t != NULL) {
            func_08002A10(p->tiles, t[p->unk_38->unk_01].unk_00);
            func_08003A70(p->palette, t[p->unk_38->unk_01].unk_04);
            AnimInit(p->anim, t[p->unk_38->unk_01].unk_0C, t[p->unk_38->unk_01].unk_08);
            AnimStart(p->anim, 0, t[p->unk_38->unk_01].unk_11);
            p->gfx = AnimGetGfx(p->anim);
            p->unk_31 = 0;
            p->unk_30 = 8;
        }
        SetTaskUpdate(a, (void*)func_08073DA4);
    }
    return 1;
}

u8 func_08073DA4(MsgFaceWork* p, void* a) {
    if (p->unk_2C < 0) {
        ApproachValue(&p->unk_2C, -255, p->unk_30);
    } else {
        ApproachValue(&p->unk_2C, 256, p->unk_30);
    }
    p->unk_30--;
    if (p->unk_30 == 0) {
        p->unk_31 = 1;
        p->unk_38->unk_02 = 0;
        p->unk_2C = 256;
        SetTaskUpdate(a, (void*)msgface_1);
    }
    return 1;
}
void func_08073E0C(void* pool, Work08073E34* p, u8 a, u8 b, u8 c) {
    p->unk_00 = a;
    p->unk_01 = b;
    p->unk_04 = c;
    p->unk_02 = 0;
    p->unk_03 = 0;
    TaskCreate(pool, gTaskDescMsgface, p);
}

void func_08073E34(Work08073E34* p, u8 a, u8 b, u8 c) {
    u8 v;

    if (p->unk_00 != a) {
        v = 3;
    } else {
        if (p->unk_01 == b && p->unk_04 == c) {
            return;
        }
        v = 4;
    }
    p->unk_02 = v;
    p->unk_00 = a;
    p->unk_01 = b;
    p->unk_04 = c;
}

void _08073E6C(Work08073E34* p) {
    p->unk_02 = 1;
}
void func_08073E74(Work08073E34* p) {
    p->unk_02 = 2;
}
void msgwait_0(MsgWaitWork* p, u8* arg) {
    p->unk_103 = arg[0];
    p->tiles = AllocObjTiles(64, 0);
    p->palette = LoadObjPalette(gUnk_08F69BA4, 32);
    LoadObjPaletteBank(p->palette->unk_06, gUnk_08F69BA4);
    func_080062F4(p->palette->unk_06 + 16, 1);
    func_08002A10(p->tiles, gUnk_09320796);
    AnimInit(p->unk_DC, gUnk_09EEFD38, gUnk_09EEFCAC);
    AnimStart(p->unk_DC, 2, 1);
    p->unk_102 = 0;
    gUnk_02039DC8->unk_7D = 1;
}
u8 msgwait_1(MsgWaitWork* p, void* a) {
    p->gfx = AnimUpdate(p->unk_DC);

    if (GetKeysPressed() & 1) {
        AnimStart(p->unk_DC, 3, 1);

        if (p->unk_103 == 4) {
            gUnk_02039DC8->unk_7D = 0;
            m4aSongNumStart(0x66);
            return 0;
        } else {
            SetTaskUpdate(a, (void*)func_08073F78);
            m4aSongNumStart(0x66);
        }
    }
    return 1;
}
u8 func_08073F78(MsgWaitWork* p) {
    u8 r;

    p->gfx = AnimUpdate(p->unk_DC);
    p->unk_102++;
    if (p->unk_102 <= 15) {
        r = 1;
    } else {
        gUnk_02039DC8->unk_7D = 0;
        r = 0;
    }
    return r;
}
void msgwait_2(MsgWaitWork* p) {
    u8 v = gUnk_02039DC8->unk_8B;

    if (v != 0) {
        DrawSprite(120, gUnk_09033D08[gUnk_02039DC8->unk_87][1] >> 8, p->gfx,
                   p->tiles, p->palette, 0, 0, 0);
    } else {
        DrawSprite(gUnk_09033D08[gUnk_02039DC8->unk_87][0] >> 8,
                   gUnk_09033D08[gUnk_02039DC8->unk_87][1] >> 8, p->gfx, p->tiles,
                   p->palette, 0, 0, 0);
    }
}
void msgwait_3(MsgWaitWork* p) {
    func_080062F4(p->palette->unk_06 + 16, 0);
    ReleaseObjTiles(p->tiles);
    ReleaseObjPalette(p->palette);
}
void msgwait_yesno_0(MsgWaitYesNoWork* p, u8* a) {
    p->unk_103 = *a;
    p->unk_00 = AllocObjTiles(64, 0);
    p->unk_14 = LoadObjPalette(gUnk_08F69BA4, 32);
    LoadObjPaletteBank(((Handle0806180C*)p->unk_14)->unk_06, gUnk_08F69BA4);
    func_080062F4(((Handle0806180C*)p->unk_14)->unk_06 + 16, 1);
    func_08002A10(p->unk_00, gUnk_09320796);
    AnimInit((AnimState*)p->anim, gUnk_09EEFD38, gUnk_09EEFCAC);
    AnimStart((AnimState*)p->anim, 2, 1);
    p->unk_102 = 0;
    p->unk_04 = AllocObjTiles(288, 0);
    p->unk_08 = LoadObjPalette(gUnk_09614418, 32);
    LoadObjPaletteBank(((Handle0806180C*)p->unk_08)->unk_06, gUnk_09614418);
    func_08002A10(p->unk_04, gUnk_090A4664);
    AnimInit((AnimState*)p->unk_C4, gUnk_09EEB03C, gUnk_09EEB008);
    AnimStart((AnimState*)p->unk_C4, 2, 1);
    p->unk_C0 = AnimGetGfx((AnimState*)p->unk_C4);
    p->unk_0C = LoadObjTiles(gUnk_093F7C9C, 4032);
    p->unk_10 = LoadObjPalette(gUnk_09611AB8, 32);
    LoadObjPaletteBank(((Handle0806180C*)p->unk_10)->unk_06, gUnk_09611AB8);
    func_080062F4(((Handle0806180C*)p->unk_14)->unk_06 + 16, 1);
    func_08065ACC(p->unk_1C, 10);
    func_08065ACC(p->unk_6C, 10);
    p->unk_18 = _08066468(1);
#ifdef VERSION_EU
    p->unk_F4 = func_08065B6C(eu_0805E924(gUnkEu_08890E1C), p->unk_1C);
    p->unk_F5 = func_08065B6C(eu_0805E924(gUnkEu_08890E44), p->unk_6C);
#else
    p->unk_F4 = func_08065B6C(gUnk_08159E10, p->unk_1C);
    p->unk_F5 = func_08065B6C(gUnk_08159E18, p->unk_6C);
#endif
    p->unk_F8 = 0x5800;
    p->unk_100 = 1;
    p->unk_FC = gUnk_09033D28[1];
    p->unk_102 = 0;
    gUnk_02039DC8->unk_7D = 1;
    gUnk_02039DC8->unk_85 = 1;
    gUnk_02039DC8->unk_84 = 0;
    p->unk_104 = 0;
}
u8 func_0807420C(MsgWaitYesNoWork* p, void* a) {
    switch (GetKeysPressed()) {
    case 64:
        if (p->unk_100 != 0) {
            p->unk_100--;
            m4aSongNumStart(101);
        }
        p->unk_102 = 1;
        break;
    case 128:
        if (p->unk_100 == 0) {
            p->unk_100++;
            m4aSongNumStart(101);
        }
        p->unk_102 = 1;
        break;
    case 1:
    case 8:
        if (p->unk_100 == 0) {
            gUnk_02039DC8->unk_84 = 1;
        } else {
            gUnk_02039DC8->unk_84 = 0;

            if (gUnk_02039DC8->unk_74 == 68) {
                gUnk_02039DC8->unk_83 = 1;
                gUnk_02039DC8->unk_8A = 255;
            }
        }
        m4aSongNumStart(102);
        gUnk_02039DC8->unk_7D = 0;
        return 0;
    case 2:
        gUnk_02039DC8->unk_84 = 0;

        if (gUnk_02039DC8->unk_74 == 68) {
            gUnk_02039DC8->unk_83 = 1;
            gUnk_02039DC8->unk_8A = 255;
        }
        m4aSongNumStart(102);
        gUnk_02039DC8->unk_7D = 0;
        return 0;
    }

    if (p->unk_102 != 0) {
        ApproachValue(&p->unk_FC, gUnk_09033D28[p->unk_100], p->unk_102);
        p->unk_102--;
    }
    p->gfx = AnimUpdate(p->anim);
    return 1;
}
u8 msgwait_yesno_1(MsgWaitYesNoWork* p, void* a) {
    p->gfx = AnimUpdate(p->anim);

    if (GetKeysPressed() & 1) {
        AnimStart(p->anim, 3, 1);
        p->unk_104 = 1;
        m4aSongNumStart(0x67);
        SetTaskUpdate(a, (void*)func_0807420C);
    }
    return 1;
}
void msgwait_yesno_2(MsgWaitYesNoWork* p) {
    switch (p->unk_104) {
    case 0:
        if (gUnk_02039DC8->unk_8B != 0) {
            DrawSprite(120, gUnk_09033D08[gUnk_02039DC8->unk_87][1] >> 8, p->gfx, p->unk_00, p->unk_14, 0, 0, 0);
        } else {
            DrawSprite(gUnk_09033D08[gUnk_02039DC8->unk_87][0] >> 8, gUnk_09033D08[gUnk_02039DC8->unk_87][1] >> 8, p->gfx, p->unk_00, p->unk_14, 0, 0, 0);
        }
        break;
    case 1:
        DrawSprite(120, 80, gUnk_09EF126C[1], p->unk_0C, p->unk_10, 0, 0, 10);
        DrawSprite(p->unk_F8 >> 8, p->unk_FC >> 8, p->unk_C0, p->unk_04, p->unk_08, 0, 1, 9);
        func_080664D8((240 - func_08065B08(p->unk_1C, p->unk_F4)) >> 1, 67, p->unk_1C, p->unk_18, 0, p->unk_F4);
        func_080664D8((240 - func_08065B08(p->unk_6C, p->unk_F5)) >> 1, 82, p->unk_6C, p->unk_18, 0, p->unk_F5);
        break;
    }
}
void msgwait_yesno_3(MsgWaitYesNoWork* p) {
    ReleaseObjTiles(p->unk_04);
    ReleaseObjTiles(p->unk_0C);
    ReleaseObjPalette(p->unk_10);
    ReleaseObjPalette(p->unk_08);
    ReleaseObjPalette(p->unk_18);
    func_08065AE0(p->unk_1C, 10);
    func_08065AE0(p->unk_6C, 10);
}
void func_08074504(void) {
    vu16 v;

    v = *(vu16*)0x04000006;
    v = (v + 1) % 228;

    if (v < 160) {
        if (gUnk_02039DCC->unk_02 == 1) {
            *(vu16*)0x04000018 = gUnk_02039DCC->unk_04[v];
            *(vu16*)0x0400001C = gUnk_02039DCC->unk_04[v];
        }
    }
}
void func_08074564(void) {
    gIntrCheck |= 2;
    func_08074504();
}
void view_0(Work08074DC4* p, u8* arg) {
    UnkStruct_09EE3FB4* t;
    Ent09EE3CA0* u;
    Obj0806180C* q;
    u8 n;

    gUnk_02039DCC = (UnkStruct_02039DCC*)p->unk_18;
    p->unk_16 = 0;
    p->unk_1A = 0;
    p->unk_08 = arg[0];
    p->unk_09 = 0;
    p->unk_10 = 0;
    p->unk_12 = 0;
    p->unk_14 = 0;
    p->unk_15 = 0;
    t = gUnk_09EE3FB4[p->unk_08];
    u = gUnk_09EE3CA0[p->unk_08];
    q = t->unk_08;
    p->unk_0C = q;

    if (q->unk_10 != 255) {
        n = func_08074E40(p);
        q = (Obj0806180C*)gUnk_02039DC8->unk_00[n];
        p->unk_00 = q->unk_04;
        p->unk_04 = q->unk_08;
    } else {
        p->unk_00 = q->unk_04;
        p->unk_04 = q->unk_08;
    }
    gUnk_02039DC8->unk_48 = p->unk_00 - 0x7800;
    gUnk_02039DC8->unk_4C = p->unk_04 - 0x5000;
    gUnk_02039DC8->unk_50 = p->unk_00;
    gUnk_02039DC8->unk_54 = p->unk_04;
    gUnk_02039DC8->unk_68 = 0;
    gUnk_02039DC8->unk_6A = 0;

    if (u != NULL) {
        if (u->unk_24 != 0) {
            SetBgAffine(2, 0, 0x100, 0x100, gUnk_02039DC8->unk_50, gUnk_02039DC8->unk_54);
        } else {
            if (p->unk_08 == 77) {
                func_08005244(3, (gUnk_02039DC8->unk_48 >> 8) + 8 + gUnk_02039DC8->unk_68, (gUnk_02039DC8->unk_4C >> 8) + 40);
            } else {
                func_08005244(3, (gUnk_02039DC8->unk_48 >> 8) + gUnk_02039DC8->unk_68, gUnk_02039DC8->unk_4C >> 8);
            }

            if (gUnk_02039DC8->unk_78 != 0) {
                func_08005244(2, (gUnk_02039DC8->unk_48 >> 8) + gUnk_02039DC8->unk_68, gUnk_02039DC8->unk_4C >> 8);
            }

            if (gUnk_02039DC8->unk_79 != 0) {
                func_08005244(1, (gUnk_02039DC8->unk_48 >> 8) + gUnk_02039DC8->unk_68, gUnk_02039DC8->unk_4C >> 8);
            }
        }
    }
}

void func_080746D8(void) {
    u8 i;

    for (i = 0; i < 16; i++) {
        func_080062F4(i + 16, 0);
    }
}

#ifdef VERSION_EU
#define MSG_VIEW_ID_B4 0xB2
#else
#define MSG_VIEW_ID_B4 0xB4
#endif

u8 view_1(Work08074DC4* p, u8* task) {
    Ent09EE3CA0* u = gUnk_09EE3CA0[p->unk_08];
    Obj0806180C* e;
    Ent08074EC8* q;
    u8 n;

    if (gUnk_02039DC8->unk_60 == 98) {
        return 1;
    }

    if (gUnk_02039DC8->unk_60 == 101) {
        return 1;
    }

    if (gUnk_02039DC8->unk_7C == 0) {
        e = &p->unk_0C[p->unk_09];

        if (gUnk_02039DC8->unk_6C >= *(u16*)&e->unk_00 && !(e->unk_14 & 0x8000)) {
            p->unk_09++;
            e = &p->unk_0C[p->unk_09];
            p->unk_15 = 0;

            if (e->unk_1C != NULL) {
                ((void (*)(Work08074DC4*))e->unk_1C)(p);
            }

            switch (e->unk_14 & 15) {
            case 0:
                p->unk_14 = 0;
                break;
            case 1:
                p->unk_14 = 1;
                p->unk_10 = e->unk_18;
                break;
            }
        }

        if ((e->unk_14 & 15) != 2) {
            if (e->unk_10 == 255) {
                p->unk_00 = e->unk_04;
                p->unk_04 = e->unk_08;
            } else {
                n = func_08074E40(p);
                q = gUnk_02039DC8->unk_00[n];
                p->unk_00 = q->unk_04;
                p->unk_04 = q->unk_08 + q->unk_0C + e->unk_0C;
            }
        }

        if (e->unk_14 & 0x10) {
            if (p->unk_15 == 0) {
                func_080746D8();
                func_08006120(2, e->unk_18);

                if (!(e->unk_14 & 0x10000)) {
                    m4aSongNumStart(0x14F);
                }

                gUnk_02039DC8->unk_7F = 0;
                p->unk_15 = 1;
            }
        }

        if (e->unk_14 & 0x20) {
            if (p->unk_15 == 0) {
                func_080746D8();
                func_08006184(1, e->unk_18);
                gUnk_02039DC8->unk_7F = 1;
                p->unk_15 = 1;

                if (e->unk_14 & 0x8000) {
                    m4aSongNumStart(0x159);
                }
            }
        }

        if (e->unk_14 & 0x40) {
            if (p->unk_15 == 0) {
                func_080746D8();
                func_08006184(0, e->unk_18);
                gUnk_02039DC8->unk_7F = 1;
                p->unk_15 = 1;
            }
        }

        if (e->unk_14 & 0x80) {
            if (p->unk_15 == 0) {
                func_08006120(1, e->unk_18);
                gUnk_02039DC8->unk_7F = 0;
                p->unk_15 = 1;
            }
        }

        if (e->unk_14 & 0x100) {
            if (p->unk_15 == 0) {
                func_080746D8();
                func_08006120(0, e->unk_18);
                gUnk_02039DC8->unk_7F = 0;
                p->unk_15 = 1;
            }
        }

        if (e->unk_14 & 0x200) {
            if (p->unk_15 == 0) {
                func_080746D8();
                func_08006290(2, 16, e->unk_18);

                if (!(e->unk_14 & 0x10000)) {
                    m4aSongNumStart(332);
                }

                p->unk_15 = 1;
            }
        }

        if (e->unk_14 & 0x20000) {
            StartBgWave(func_08074564);
            p->unk_1A = 1;
        }

        if (e->unk_14 & 0x40000) {
            p->unk_1A = 0;
            ResetHBlankCallback();
            DisableHBlankIntr();
        }

        if (e->unk_14 & 0x4000) {
            if (p->unk_15 == 0) {
                func_08006120(7, e->unk_18);
            }

            p->unk_15 = 1;
        }

        if (e->unk_14 & 0x2000) {
            gUnk_02039DC8->unk_68 = GetRandom() % 4;
            gUnk_02039DC8->unk_6A = GetRandom() % 4;
        } else if (e->unk_14 & 0x400) {
            gUnk_02039DC8->unk_68 = GetRandom() % 8;
            gUnk_02039DC8->unk_6A = GetRandom() % 8;
        } else if (e->unk_14 & 0x800) {
            gUnk_02039DC8->unk_68 = GetRandom() % 16;
            gUnk_02039DC8->unk_6A = GetRandom() % 16;
        } else if (e->unk_14 & 0x1000) {
            gUnk_02039DC8->unk_68 = 0;
            gUnk_02039DC8->unk_6A = gSineTable[(p->unk_12 >> 3) & 0xFF] >> 5;
            p->unk_12 += 4;
        } else {
            gUnk_02039DC8->unk_68 = 0;
            gUnk_02039DC8->unk_6A = 0;
        }

        if (p->unk_14 != 0) {
            func_08074DC4(p);
        } else {
            func_08074D14(p);
        }

        if (u != NULL) {
            if (u->unk_24 != 0) {
                SetBgAffine(2, 0, 0x100, 0x100, gUnk_02039DC8->unk_50, gUnk_02039DC8->unk_54);
            } else {
                if (p->unk_08 == 77) {
                    func_08005244(3, (gUnk_02039DC8->unk_58 >> 8) + 8, (gUnk_02039DC8->unk_5C >> 8) + 40);
                } else {
                    func_08005244(3, gUnk_02039DC8->unk_58 >> 8, gUnk_02039DC8->unk_5C >> 8);
                }

                if (gUnk_02039DC8->unk_78 != 0) {
                    func_08005244(2, gUnk_02039DC8->unk_58 >> 8, gUnk_02039DC8->unk_5C >> 8);
                }

                if (gUnk_02039DC8->unk_79 != 0) {
                    func_08005244(1, gUnk_02039DC8->unk_58 >> 8, gUnk_02039DC8->unk_5C >> 8);
                }
            }
        } else {
            switch (p->unk_08) {
            case 77:
            case 78:
                gBtlWork->unk_000 = gUnk_02039DC8->unk_58;
                gBtlWork->unk_004 = gUnk_02039DC8->unk_5C;
                gBtlWork->unk_008 = gUnk_02039DC8->unk_58;
                gBtlWork->unk_00C = gUnk_02039DC8->unk_5C;
                gBtlWork->unk_010 = gUnk_02039DC8->unk_58;
                gBtlWork->unk_014 = gUnk_02039DC8->unk_5C;
                func_08005244(0, (gUnk_02039DC8->unk_58 >> 8) + 8, (gUnk_02039DC8->unk_5C >> 8) + 40);
                func_08005244(1, gUnk_02039DC8->unk_58 >> 8, gUnk_02039DC8->unk_5C >> 8);
                break;
            case 105:
                gBtlWork->unk_000 = gUnk_02039DC8->unk_58;
                gBtlWork->unk_004 = gUnk_02039DC8->unk_5C;
                gBtlWork->unk_008 = gUnk_02039DC8->unk_58;
                gBtlWork->unk_00C = gUnk_02039DC8->unk_5C;
                gBtlWork->unk_010 = gUnk_02039DC8->unk_58;
                gBtlWork->unk_014 = gUnk_02039DC8->unk_5C;
                func_08005244(0, gUnk_02039DC8->unk_58 >> 8, gUnk_02039DC8->unk_5C >> 8);
                break;
            case MSG_VIEW_ID_B4:
                break;
            default:
                gBtlWork->unk_000 = gUnk_02039DC8->unk_58;
                gBtlWork->unk_004 = gUnk_02039DC8->unk_5C;
                gBtlWork->unk_008 = gUnk_02039DC8->unk_58;
                gBtlWork->unk_00C = gUnk_02039DC8->unk_5C;
                gBtlWork->unk_010 = gUnk_02039DC8->unk_58;
                gBtlWork->unk_014 = gUnk_02039DC8->unk_5C;
                func_08005244(0, gUnk_02039DC8->unk_58 >> 8, gUnk_02039DC8->unk_5C >> 8);
                func_08005244(1, gUnk_02039DC8->unk_58 >> 8, gUnk_02039DC8->unk_5C >> 8);
                break;
            }
        }
    } else {
        n = func_08074E88(p, gUnk_02039DC8->unk_88);
        p->unk_00 = gUnk_02039DC8->unk_00[n]->unk_04;

        switch (gUnk_02039DC8->unk_87) {
        case 0:
        case 2:
            p->unk_04 = gUnk_02039DC8->unk_00[n]->unk_08 + gUnk_02039DC8->unk_00[n]->unk_0C + gUnk_09033758[n];
            break;
        case 1:
        case 3:
            p->unk_04 = gUnk_02039DC8->unk_00[n]->unk_08 + gUnk_02039DC8->unk_00[n]->unk_0C;
            break;
        }

        p->unk_10 = gUnk_02039DC8->unk_89;
        func_08074DC4(p);

        if (u != NULL) {
            if (u->unk_24 != 0) {
                SetBgAffine(2, 0, 0x100, 0x100, gUnk_02039DC8->unk_50, gUnk_02039DC8->unk_54);
            } else {
                if (p->unk_08 == 77) {
                    func_08005244(3, (gUnk_02039DC8->unk_58 >> 8) + 8, (gUnk_02039DC8->unk_5C >> 8) + 40);
                } else {
                    func_08005244(3, gUnk_02039DC8->unk_58 >> 8, gUnk_02039DC8->unk_5C >> 8);
                }

                if (gUnk_02039DC8->unk_78 != 0) {
                    func_08005244(2, gUnk_02039DC8->unk_58 >> 8, gUnk_02039DC8->unk_5C >> 8);
                }

                if (gUnk_02039DC8->unk_79 != 0) {
                    func_08005244(1, gUnk_02039DC8->unk_58 >> 8, gUnk_02039DC8->unk_5C >> 8);
                }
            }
        } else {
            gBtlWork->unk_000 = gUnk_02039DC8->unk_58;
            gBtlWork->unk_004 = gUnk_02039DC8->unk_5C;
            func_08005244(0, (gUnk_02039DC8->unk_58 >> 8) + 8, (gUnk_02039DC8->unk_5C >> 8) + 40);
            func_08005244(1, gUnk_02039DC8->unk_58 >> 8, gUnk_02039DC8->unk_5C >> 8);
        }
    }

    if (gUnk_02039DC8->unk_64 & 4) {
        SetTaskUpdate(task, (u32)_08074EC8);
    }

    if (u != NULL && (u->unk_2D & 1)) {
        func_080CA368(3, gUnk_02039DC8->unk_48 >> 8, gUnk_02039DC8->unk_4C >> 8);
    }

    func_08075010((Work08075010*)p);
    return 1;
}
void view_2(void) {
}
void view_3(void) {
}

void func_08074D00(Work08074DC4* p) {
    gUnk_02039DC8->unk_50 = p->unk_00;
    gUnk_02039DC8->unk_54 = p->unk_04;
}

void func_08074D14(Work08074DC4* a) {
    Obj0806180C* e;
    s32 x;
    s32 y;

    func_08074D00(a);
    x = gUnk_02039DC8->unk_50 - 0x7800;
    y = gUnk_02039DC8->unk_54 - 0x5000;
    e = &a->unk_0C[a->unk_09];
    if (e->unk_14 & 0x2C00) {
        gUnk_02039DC8->unk_48 = x;
        gUnk_02039DC8->unk_4C = y;
    } else {
        gUnk_02039DC8->unk_48 += (x - gUnk_02039DC8->unk_48) >> 3;
        gUnk_02039DC8->unk_4C += (y - gUnk_02039DC8->unk_4C) >> 3;
    }
    gUnk_02039DC8->unk_58 = gUnk_02039DC8->unk_48 + (gUnk_02039DC8->unk_68 << 8);
    gUnk_02039DC8->unk_5C = gUnk_02039DC8->unk_4C + (gUnk_02039DC8->unk_6A << 8);
}

void func_08074D98(Work08074DC4* a) {
    s32 x;
    s32 y;

    func_08074D00(a);
    x = gUnk_02039DC8->unk_50 - 0x7800;
    y = gUnk_02039DC8->unk_54 - 0x5000;
    gUnk_02039DC8->unk_48 = x;
    gUnk_02039DC8->unk_4C = y;
}

void func_08074DC4(Work08074DC4* a) {
    s32 x;
    s32 y;

    func_08074D00(a);
    x = gUnk_02039DC8->unk_50 - 0x7800;
    y = gUnk_02039DC8->unk_54 - 0x5000;

    if (a->unk_10 != 0) {
        ApproachValue(&gUnk_02039DC8->unk_48, x, a->unk_10);
        ApproachValue(&gUnk_02039DC8->unk_4C, y, a->unk_10);
        a->unk_10--;
    } else {
        gUnk_02039DC8->unk_48 = x;
        gUnk_02039DC8->unk_4C = y;
    }
    gUnk_02039DC8->unk_58 = gUnk_02039DC8->unk_48 + (gUnk_02039DC8->unk_68 << 8);
    gUnk_02039DC8->unk_5C = gUnk_02039DC8->unk_4C + (gUnk_02039DC8->unk_6A << 8);
}

u8 func_08074E40(Work08074DC4* p) {
    UnkStruct_09EE3FB4* t = gUnk_09EE3FB4[p->unk_08];
    u8 n = t->unk_00;
    AnimEntry0806180C* q = t->unk_04;
    Obj0806180C* e = &p->unk_0C[p->unk_09];
    u8 i;

    for (i = 0; i < n; i++) {
        if (e->unk_10 == q[i].unk_04) {
            return i;
        }
    }
    return 0xFF;
}

u8 func_08074E88(Work08074DC4* p, u8 v) {
    UnkStruct_09EE3FB4* t = gUnk_09EE3FB4[p->unk_08];
    u8 n = t->unk_00;
    AnimEntry0806180C* q = t->unk_04;
    u8 i;

    for (i = 0; i < n; i++) {
        if (v == q[i].unk_04) {
            return i;
        }
    }
    return 0xFF;
}

u8 _08074EC8(Work08074DC4* p) {
    Ent09EE3CA0* t;
    Ent08074EC8* q;
    u8 n;

    n = func_08074E88(p, 0);
    t = gUnk_09EE3CA0[p->unk_08];
    q = gUnk_02039DC8->unk_00[n];
    p->unk_00 = q->unk_04;
    p->unk_04 = q->unk_08 + q->unk_0C;

    if (t != NULL) {
        if (t->unk_24 != 0) {
            func_08074D98(p);
            SetBgAffine(2, 0, 0x100, 0x100, gUnk_02039DC8->unk_50, gUnk_02039DC8->unk_54);
        } else {
            func_08074D14(p);

            if (p->unk_08 == 77) {
                func_08005244(3, (gUnk_02039DC8->unk_48 >> 8) + 8 + gUnk_02039DC8->unk_68, (gUnk_02039DC8->unk_4C >> 8) + 40);
            } else {
                func_08005244(3, (gUnk_02039DC8->unk_48 >> 8) + gUnk_02039DC8->unk_68, gUnk_02039DC8->unk_4C >> 8);
            }

            if (gUnk_02039DC8->unk_78 != 0) {
                func_08005244(2, gUnk_02039DC8->unk_48 >> 8, gUnk_02039DC8->unk_4C >> 8);
            }

            if (gUnk_02039DC8->unk_79 != 0) {
                func_08005244(1, gUnk_02039DC8->unk_48 >> 8, gUnk_02039DC8->unk_4C >> 8);
            }
        }
    } else {
        func_08074D14(p);
        gBtlWork->unk_000 = gUnk_02039DC8->unk_48;
        gBtlWork->unk_004 = gUnk_02039DC8->unk_4C;
        func_08005244(0, (gUnk_02039DC8->unk_48 >> 8) + 8, (gUnk_02039DC8->unk_4C >> 8) + 40);
        func_08005244(1, gUnk_02039DC8->unk_48 >> 8, gUnk_02039DC8->unk_4C >> 8);
    }
    return 1;
}

void func_08075010(Work08075010* p) {
    u8 i;
    s32 v;

    if (p->unk_1A == 1) {
        for (i = 0; i < 160; i++) {
            p->unk_1C[i] = (gUnk_02039DC8->unk_58 >> 8) + (v = (u8)gSineTable[((i + p->unk_16) * 2) & 0xFF]) / 32;
        }
        p->unk_16++;
    }
}

s16 func_08075064(u8 a) {
    s16 n = 0;

    switch (a) {
    case 0:
        while (gUnk_09033D50[n] != -1) {
            n++;
        }
        break;
    case 1:
        while (gUnk_09033E76[n] != -1) {
            n++;
        }
        break;
    }
    return n;
}
