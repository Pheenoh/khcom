#include "macros.h"
#include "msg.h"

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
INCLUDE_ASM("msg/func_08061824.s");
INCLUDE_ASM("msg/func_08061FC8.s");
INCLUDE_ASM("msg/func_0806250C.s");
void func_0806297C(void) {
    UnkStruct_09EE3FB4* m = gUnk_09EE3FB4[gUnk_02034A78];

    switch (gUnk_02034A78) {
    case 68:
        ModeRequest(gUnk_09EE274C, 69);
        break;
    case 83:
    case 84:
        gGameState.unk_0D = 5;
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
INCLUDE_ASM("msg/func_080629F8.s");
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
#ifdef NON_MATCHING
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
        u8 c;

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
#else
INCLUDE_ASM("msg/func_08062DC8.s");
#endif
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
#else
INCLUDE_ASM("msg/func_08062F18.s");
#endif
INCLUDE_ASM("msg/func_08063034.s");
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
#else
INCLUDE_ASM("msg/func_08063678.s");
#endif
INCLUDE_ASM("msg/func_08063744.s");
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
#else
INCLUDE_ASM("msg/func_08063EE4.s");
#endif
INCLUDE_ASM("msg/func_08063F60.s");
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
#else
INCLUDE_ASM("msg/func_080640E0.s");
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
#else
INCLUDE_ASM("msg/func_0806422C.s");
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
#else
INCLUDE_ASM("msg/func_080642A8.s");
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
#else
INCLUDE_ASM("msg/func_08064338.s");
#endif
INCLUDE_ASM("msg/func_080643D4.s");
INCLUDE_ASM("msg/func_08064624.s");
#ifndef VERSION_EU
void func_08064B68(void) {
    EwramFree(gUnk_02034A8C);
    gUnk_02034A8C = NULL;
}
#else
INCLUDE_ASM("msg/func_08064B68.s");
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

INCLUDE_ASM("msg/func_08064DD4.s");
INCLUDE_ASM("msg/func_08064EF4.s");
INCLUDE_ASM("msg/func_08065170.s");
INCLUDE_ASM("msg/func_080653D4.s");

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
#else
INCLUDE_ASM("msg/func_080659BC.s");
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

#ifdef VERSION_US
u16 func_08065A70(u8 v, TextSlot* out) {
    u16 buf[4];
    u16* p;
    u8 q;
    u16 c;
    u16 end;

    if (v > 9) {
        p = buf;
        q = v / 10;
        c = q + '0';
        end = 0;
        p[0] = c;
        buf[1] = v - q * 10 + '0';
        buf[2] = end;
    } else {
        buf[0] = v + '0';
        buf[1] = 0;
    }
    return func_08065B6C(buf, out);
}
#else
INCLUDE_ASM("msg/func_08065A70.s");
#endif

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

#ifdef NON_MATCHING
s16 func_08065B08(TextSlot* p, u8 n) {
    s16 x;
    s32 i;

    x = 0;

    for (i = 0; i < n; i++) {
        if (p[i].tiles == NULL) {
            return x;
        }

        if (p[i].unk_05 == -1) {
            x += 3;
        } else {
            x += p[i].unk_05;
        }
    }
    return x;
}
#else
INCLUDE_ASM("msg/func_08065B08.s");
#endif

#ifndef VERSION_EU
#ifdef VERSION_JP
#define MSG_CHAR(p) (*(u8*)(p))
#else
#define MSG_CHAR(p) (*(p))
#endif

s32 func_08065B54(u16* s) {
#ifdef VERSION_JP
    u16* p = s;
    u16 n = 0;
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
#else
INCLUDE_ASM("msg/func_08065B54.s");
#endif

#ifndef VERSION_JP
u16 func_08065B6C(u16* a, TextSlot* b) {
    return func_08065B7C(a, b);
}
#else
INCLUDE_ASM("msg/func_08065B6C.s");
#endif

INCLUDE_ASM("msg/func_08065B7C.s");
INCLUDE_ASM("msg/func_08065D10.s");
INCLUDE_ASM("msg/func_080660C0.s");
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

void func_080664D8(s16 x, s32 y, Ent08066588* p, void* d, u16 h, u8 n) {
    s16 x0 = x;
    s16 cy = y;
    u8 i;

#ifndef VERSION_JP
    cy -= 2;
#endif

    for (i = 0; i < n; i++) {
        if (p->unk_00 == NULL) {
            cy += 12;
            x = x0;
        } else if (p->unk_05 != -1) {
            DrawSprite(x, cy, gUnk_09EEB204[0], p->unk_00, d, 0, 0, h);
            x += p->unk_05;
        } else {
            x += 3;
        }
        p++;
    }
}

#ifndef VERSION_JP
void func_08066588(s16 x, s32 y, Ent08066588* p, void* d, s32 e, u8 n) {
    s16 x0 = x;
    s16 cy = y;
    u8 i;

    cy -= 2;

    for (i = 0; i < n; i++) {
        if (p->unk_00 == NULL) {
            cy += 12;
            x = x0;
        } else if (p->unk_05 != -1) {
            func_08002488(x, cy, gUnk_09EEB204[0], p->unk_00, d, 0);
            x += p->unk_05;
        } else {
            x += 3;
        }
        p++;
    }
}
#else
INCLUDE_ASM("msg/func_08066588.s");
#endif
INCLUDE_ASM("msg/func_0806662C.s");
INCLUDE_ASM("msg/func_080666F0.s");
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

INCLUDE_ASM("msg/_08066B84.s");
s32 func_08066DC0(s16 x, s16 y, u16* s, void* d, void* e, u16 h, u8 n) {
    u8 i;

    for (i = 0; i < n; i++) {
        DrawSprite(x + i * 8, y, gUnk_09EEC538[*s], d, e, 0, 0, h);
        s++;
    }
}
INCLUDE_ASM("msg/func_08066E40.s");

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

INCLUDE_ASM("msg/func_0806BB44.s");
INCLUDE_ASM("msg/func_0806BDB8.s");

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
INCLUDE_ASM("msg/func_0806C490.s");
INCLUDE_ASM("msg/func_0806C81C.s");
INCLUDE_ASM("msg/func_0806CBAC.s");
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
INCLUDE_ASM("msg/func_0806CD60.s");
INCLUDE_ASM("msg/func_0806CF04.s");
INCLUDE_ASM("msg/func_0806D0A8.s");
void func_0806D288(ContinueWork* p) {
    DrawSprite(p->unk_50 >> 8, p->unk_54 >> 8, p->unk_18, p->unk_00, p->unk_04, 0, 4, 100);
    DrawSprite(120, 120, p->unk_1C, p->unk_08, p->unk_0C, 0, 0, 100);
}
void Continue_3(ContinueWork* p) {
    DisableBg(0);
    DisableBg(2);
    LoadBgMap(0, gUnk_08125E24, 0x800);
    LoadBgMap(2, gUnk_08125E24, 0x800);
    ReleaseObjTiles(p->unk_08);
    ReleaseObjPalette(p->unk_0C);
    ReleaseObjPalette(p->unk_04);
    ReleaseObjTiles(p->unk_00);
    ReleaseObjTiles(p->unk_10);
    ReleaseObjPalette(p->unk_14);
    gBldCnt = 0;
}
#ifndef VERSION_EU
void event_seq_0(EventSeqWork* work, u8* a) {
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
        func_0800443C(GetBgCharBase(1), 0x8000);

        if (work->unk_34->unk_08->unk_14 & 0x80) {
            SetBackdropColor(31, 31, 31);
            func_08006120(1, 0x40);
        }
    }
}
#else
INCLUDE_ASM("msg/event_seq_0.s");
#endif

INCLUDE_ASM("msg/event_seq_1.s");
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
INCLUDE_ASM("msg/func_0806D830.s");
void event_seq_2(EventSeqWork* p) {
    TaskPoolDraw(&p->unk_14);

    if (p->unk_32 != 0) {
        TaskPoolDraw(&gBtlWork->unk_2C);
    }
    TaskPoolDraw(&p->unk_00);
}
#ifndef VERSION_EU
void event_seq_3(EventSeqWork* p) {
    TaskPoolDestroy(&p->unk_00);

    if (p->unk_28 != 0) {
        TaskPoolDestroy(&p->unk_14);
    }
}
#else
INCLUDE_ASM("msg/event_seq_3.s");
#endif
INCLUDE_ASM("msg/event_chara_0.s");
INCLUDE_ASM("msg/event_chara_1.s");
#ifdef NON_MATCHING
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
        TaskPoolDraw(&gBtlWork->unk_2C);
    }

    if (p->tiles != NULL) {
        h = p->unk_03E;

        if (p->unk_1B1 == 0) {
            h &= 0xFFFE;
        } else {
            h |= 1;
        }
        x = (p->unk_180 >> 8) - (gUnk_02039DC8->unk_58 >> 8);
        y = (p->unk_184 >> 8) + gUnk_0903380C[p->unk_026][0] - (gUnk_02039DC8->unk_5C >> 8);
        DrawSprite(x, y, p->unk_00C, p->tiles, p->palette, 0, h, 50);
    }
    p->unk_034 = save;
}
#else
INCLUDE_ASM("msg/event_chara_2.s");
#endif
void event_chara_3(Work0806180C* p) {
    TaskPoolDestroy(&p->unk_010);

    if (p->unk_1B3 != 0) {
        TaskPoolDestroy(&gBtlWork->unk_2C);
        TaskPoolDestroy(&gBtlWork->unk_40);
        EwramFree(gBtlWork);
    }
}
INCLUDE_ASM("msg/func_0806E570.s");
INCLUDE_ASM("msg/func_0806E7A8.s");

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
#ifdef NON_MATCHING
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

            if (p->unk_000[p->unk_1A0].unk_18 & 0x400) {
                z &= 0xF7FF;
                z &= 0xFFFE;
                func_0801CE00(p->unk_028, z);
            } else {
                func_0801CE00(p->unk_028, (z | 0x800) & 0xFFFE);
            }
        }
    }
}
#else
INCLUDE_ASM("msg/func_0806F94C.s");
#endif
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
INCLUDE_ASM("msg/func_0806FE90.s");

void func_08070008(Work0806180C* p) {
    u8 old = p->unk_1AB;

    func_0806FE90(p);

    if (old != p->unk_1AB) {
        if (abs(GetAngleDiff(old, p->unk_1AB)) > 100) {
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
INCLUDE_ASM("msg/func_080700D4.s");
INCLUDE_ASM("msg/func_0807048C.s");
INCLUDE_ASM("msg/func_08070AD4.s");
INCLUDE_ASM("msg/func_08072914.s");

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

INCLUDE_ASM("msg/func_08072C34.s");
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

INCLUDE_ASM("msg/func_08072EAC.s");
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
#ifdef NON_MATCHING
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
        if (p->unk_40 != 0) {
            p->unk_1E = 0;
            p->unk_29 = 0;
            p->unk_2A = 1;
            p->unk_34 = 1;
            SetTaskUpdate(a, (void*)func_08073170);
        } else {
            _08065994();

            if ((e->unk_14 & 0x8000) == 0 && p->unk_3C[p->unk_27 + 1].unk_08 == 4) {
                p->unk_1E = 0;
                p->unk_29 = 0;
                p->unk_2A = 0;
                p->unk_27++;
                gUnk_02039DC8->unk_64 &= ~1;
                p->unk_34 = 1;
                SetTaskUpdate(a, (void*)func_08072EAC);
            } else {
                p->unk_1E = 8;
                func_08073E74(&p->unk_2C);
                SetTaskUpdate(a, (void*)func_0807344C);
                gUnk_02039DC8->unk_81 = 0;
                p->unk_34 = 0;
            }
        }
        p->unk_2B = 0;
    }
    TaskPoolUpdate(p);
    return 1;
}
#else
INCLUDE_ASM("msg/func_08073318.s");
#endif
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
#ifdef VERSION_US
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

    if (e->unk_00 == 62) {
        if (p->unk_40 != 0) {
            p->unk_26 = func_08064EF4(0x2E00, gUnk_09033CB8[p->unk_20] - 0x200, p->unk_40, &p->unk_40);
        } else {
            p->unk_26 = func_08064EF4(0x2E00, gUnk_09033CB8[p->unk_20] - 0x200, e->unk_10, &p->unk_40);
        }
    } else {
        if (p->unk_40 != 0) {
            p->unk_26 = func_08064EF4(gUnk_09033CA8[p->unk_20], gUnk_09033CB8[p->unk_20] - 0x200, p->unk_40, &p->unk_40);
        } else {
            p->unk_26 = func_08064EF4(gUnk_09033CA8[p->unk_20], gUnk_09033CB8[p->unk_20] - 0x200, e->unk_10, &p->unk_40);
        }
    }
    p->unk_25 = 0;
    p->unk_24 = 0;
    p->unk_29 = 1;
}
#else
INCLUDE_ASM("msg/func_08073508.s");
#endif

#ifdef NON_MATCHING
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
                        TaskCreate(p, &gTaskDescMsgface[1], (u8*)&p->unk_3C[p->unk_27] + 32);
                    } else {
                        TaskCreate(p, &gTaskDescMsgface[2], (u8*)&p->unk_3C[p->unk_27] + 32);
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
#else
INCLUDE_ASM("msg/func_0807361C.s");
#endif
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
    p->unk_24 = gUnk_09033CD0[n = p->unk_38->unk_04];
    p->unk_28 = gUnk_09033CF0[n];
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
        AnimInit(p->unk_0C, anim[p->unk_38->unk_01].unk_0C, anim[p->unk_38->unk_01].unk_08);
        AnimStart(p->unk_0C, 0, anim[p->unk_38->unk_01].unk_11);
        p->unk_08 = AnimGetGfx(p->unk_0C);
    } else {
        func_08002A10(p->tiles, anim->unk_00);
        func_08003A70(p->palette, anim->unk_04);
        AnimInit(p->unk_0C, anim->unk_0C, anim->unk_08);
        AnimStart(p->unk_0C, 0, anim->unk_11);
        p->unk_08 = AnimGetGfx(p->unk_0C);
    }
}
INCLUDE_ASM("msg/msgface_1.s");
void msgface_2(MsgFaceWork* p) {
    s32 t;
    u8 v;

    if (p->unk_34 != 0) {
        t = AllocObjAffine(0, p->unk_2C, 256, 0);
        if (t != 0) {
            DrawSprite(p->unk_24 >> 8, p->unk_28 >> 8, p->unk_08, p->tiles, p->palette, t, 0, 50);
        } else {
            v = p->unk_33;
            if (v != 0) {
                DrawSprite(p->unk_24 >> 8, p->unk_28 >> 8, p->unk_08, p->tiles, p->palette, t, 1, 50);
            } else {
                DrawSprite(p->unk_24 >> 8, p->unk_28 >> 8, p->unk_08, p->tiles, p->palette, v, v, 50);
            }
        }
    }
}
void msgface_3(MsgFaceWork* p) {
    ReleaseObjTiles(p->tiles);
    ReleaseObjPalette(p->palette);
}
u8 func_08073B04(MsgFaceWork* p, void* a) {
    ApproachValue(&p->unk_24, gUnk_09033CE0[p->unk_38->unk_04], p->unk_30);
    p->unk_30--;
    if (p->unk_30 == 0) {
        p->unk_38->unk_02 = 0;
        p->unk_31 = 1;
        SetTaskUpdate(a, (void*)msgface_1);
    }
    return 1;
}
u8 func_08073B54(MsgFaceWork* p, void* a) {
    ApproachValue(&p->unk_24, gUnk_09033CD0[p->unk_38->unk_04], p->unk_30);
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
        AnimInit(p->unk_0C, t[p->unk_38->unk_01].unk_0C, t[p->unk_38->unk_01].unk_08);
        AnimStart(p->unk_0C, 0, t[p->unk_38->unk_01].unk_11);
        p->unk_08 = AnimGetGfx(p->unk_0C);
        p->unk_31 = 0;
        p->unk_30 = 8;
        p->unk_38->unk_02 = 0;
    }
    p->unk_24 = gUnk_09033CD0[n = p->unk_38->unk_04];
    p->unk_28 = gUnk_09033CF0[n];
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
            AnimInit(p->unk_0C, t[p->unk_38->unk_01].unk_0C, t[p->unk_38->unk_01].unk_08);
            AnimStart(p->unk_0C, 0, t[p->unk_38->unk_01].unk_11);
            p->unk_08 = AnimGetGfx(p->unk_0C);
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
    p->unk_00 = AllocObjTiles(64, 0);
    p->unk_14 = LoadObjPalette(gUnk_08F69BA4, 32);
    LoadObjPaletteBank(p->unk_14->unk_06, gUnk_08F69BA4);
    func_080062F4(p->unk_14->unk_06 + 16, 1);
    func_08002A10(p->unk_00, gUnk_09320796);
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
                   p->unk_00, p->unk_14, 0, 0, 0);
    } else {
        DrawSprite(gUnk_09033D08[gUnk_02039DC8->unk_87][0] >> 8,
                   gUnk_09033D08[gUnk_02039DC8->unk_87][1] >> 8, p->gfx, p->unk_00,
                   p->unk_14, 0, 0, 0);
    }
}
void msgwait_3(MsgWaitWork* p) {
    func_080062F4(p->unk_14->unk_06 + 16, 0);
    ReleaseObjTiles(p->unk_00);
    ReleaseObjPalette(p->unk_14);
}
INCLUDE_ASM("msg/msgwait_yesno_0.s");
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
    p->gfx = AnimUpdate(p->unk_DC);
    return 1;
}
u8 msgwait_yesno_1(MsgWaitYesNoWork* p, void* a) {
    p->gfx = AnimUpdate(p->unk_DC);

    if (GetKeysPressed() & 1) {
        AnimStart(p->unk_DC, 3, 1);
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
#ifdef NON_MATCHING
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
    }
    p->unk_00 = q->unk_04;
    p->unk_04 = q->unk_08;
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
#else
INCLUDE_ASM("msg/view_0.s");
#endif

void func_080746D8(void) {
    u8 i;

    for (i = 0; i < 16; i++) {
        func_080062F4(i + 16, 0);
    }
}

INCLUDE_ASM("msg/view_1.s");
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
        gBtlWork->unk_00 = gUnk_02039DC8->unk_48;
        gBtlWork->unk_04 = gUnk_02039DC8->unk_4C;
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
