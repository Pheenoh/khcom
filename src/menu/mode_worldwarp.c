#include "gba/keys.h"
#include "key.h"
#include "monsgage.h"
#include "types.h"
#include "jiminy_data.h"
#include "jiminy_text_assets.h"
#include "mode_chkobj_assets.h"
#include "mode_ms.h"
#include "ms_charge.h"
#include "mode_mapinspect.h"
#include "worldinspect_assets.h"
#include <stddef.h>
#include "registration_data.h"
#include "system_state.h"
#include "map_api.h"
#include "mode_worldwarp.h"
#include "sprites_worldinspect.h"

#ifdef VERSION_EU
extern u8 gUnkEu_09A4FBC0[];
extern u8 gUnkEu_09A50BC0[];
extern u8 gUnkEu_09A51BC0[];
extern u8 gUnkEu_09A52BC0[];
extern u8 gUnkEu_09A4F3C0[];
extern u8 gUnkEu_09A503C0[];
extern u8 gUnkEu_09A513C0[];
extern u8 gUnkEu_09A523C0[];
extern u8 gUnkEu_09A56780[];
extern u8 gUnk_09A53380[];
extern u8 gUnkEu_09A5CF80[];
extern u8 gUnk_09A59B80[];
extern u8 gUnkEu_09A57480[];
extern u8 gUnk_09A54080[];
extern u8 gUnkEu_09A5DC80[];
extern u8 gUnk_09A5A880[];
extern u8 gUnkEu_09A58180[];
extern u8 gUnk_09A54D80[];
extern u8 gUnkEu_09A5E980[];
extern u8 gUnk_09A5B580[];
extern u8 gUnkEu_09A58E80[];
extern u8 gUnk_09A55A80[];
extern u8 gUnkEu_09A5F680[];
extern u8 gUnk_09A5C280[];
extern u8 gUnkEu_099AAC2C[];
extern u8 gUnkEu_099ABA18[];
extern u8 gUnkEu_099ABFA0[];
extern u8 gUnkEu_099AC468[];
extern u8 gUnkEu_099AC9F0[];
#endif

static s16 gUnk_020354E8;
static s16 gUnk_020354EA;
static s16 gUnk_020354F0[13];
static s16 gUnk_0203550A;
static void* gUnk_0203550C;
static struct ObjTiles* gUnk_02035510;
static struct ObjPalette* gUnk_02035514;
static struct ObjTiles* gUnk_02035518;
static struct ObjPalette* gUnk_0203551C;
static AnimState gUnk_02035520;
static AnimState gUnk_02035538;
static struct ObjTiles* gUnk_02035550;
static struct ObjPalette* gUnk_02035554;
static AnimState gUnk_02035558;
static void* gUnk_02035570[14];
static void* gUnk_020355A8[14];
static void* gUnk_020355E0[14];
#ifdef VERSION_EU
static TextSlot gUnk_02035618[48];
#else
static TextSlot gUnk_02035618[24];
#endif
static u8 gUnk_020356D8;
#ifdef VERSION_EU
static TextSlot gUnk_020356E0[48];
#else
static TextSlot gUnk_020356E0[24];
#endif
static u8 gUnk_020357A0;
static s16 gUnk_020357A2;
static s16 gUnk_020357A4;
static s32 gUnk_020357A8[2];
static s32 gUnk_020357B0;
static s32 gUnk_020357B4;
static s32 gUnk_020357B8;

extern u8 gUnk_0999F400[];
extern u8 gUnk_0999F416[];
extern u8 gUnk_0999F44A[];
#ifdef VERSION_EU
extern u8 gUnkEu_099AABA4[];
extern u8 gUnkEu_099AABBA[];
extern u8 gUnkEu_099AABEE[];
extern u8 gUnkEu_099AB990[];
extern u8 gUnkEu_099AB9A6[];
extern u8 gUnkEu_099AB9DA[];
extern u8 gUnkEu_099ABF18[];
extern u8 gUnkEu_099ABF2E[];
extern u8 gUnkEu_099ABF62[];
extern u8 gUnkEu_099AC3E0[];
extern u8 gUnkEu_099AC3F6[];
extern u8 gUnkEu_099AC42A[];
extern u8 gUnkEu_099AC968[];
extern u8 gUnkEu_099AC97E[];
extern u8 gUnkEu_099AC9B2[];
extern u8 gUnk_09A53380[];
extern u8 gUnk_09A59B80[];
extern u8 gUnk_09A54080[];
extern u8 gUnk_09A5A880[];
extern u8 gUnk_09A54D80[];
extern u8 gUnk_09A5B580[];
extern u8 gUnk_09A55A80[];
extern u8 gUnk_09A5C280[];
#endif

const WarpRect gWarpRects[4] = {
    {2, 1, 20, 2},
    {2, 5, 0, 13},
    {2, 5, 3, 13},
    {4, 6, 6, 13},
};

WarpIcon gWarpIcons[13] = {
    {7, 8, 1, 3, 22, 16, 0, 21, 18, {0, 0}},
    {6, 9, 2, 0, 15, 16, 0, 14, 18, {0, 0}},
    {5, 10, 3, 1, 8, 16, 0, 7, 18, {0, 0}},
    {4, 12, 0, 2, 1, 16, 1, 0, 14, {0, 0}},
    {11, 3, 7, 5, 1, 12, 0, 7, 14, {0, 0}},
    {10, 2, 4, 6, 8, 12, 0, 14, 14, {0, 0}},
    {9, 1, 5, 7, 15, 12, 0, 21, 14, {0, 0}},
    {8, 0, 6, 4, 22, 12, 2, 28, 10, {0, 0}},
    {0, 7, 9, 11, 22, 8, 0, 21, 10, {0, 0}},
    {1, 6, 10, 8, 15, 8, 0, 14, 10, {0, 0}},
    {2, 5, 11, 9, 8, 8, 0, 7, 10, {0, 0}},
    {12, 4, 8, 10, 1, 8, 3, 0, 5, {0, 0}},
    {3, 11, 12, 12, 3, 3, 0, 0, 0, {0, 0}},
};

WorldSelectDef gWorldSelectDefs[14] = {
#if defined(VERSION_US)
    {NULL, 0, {0, 0}, NULL, 0, {0, 0}, NULL, NULL},
    {gUnk_09A3D65C, 32, {0, 0}, gUnk_099A0B5C, 576, {0, 0}, gUnk_099A0B3C, gUnk_0815A56C},
    {gUnk_09A3D69C, 32, {0, 0}, gUnk_099A0F70, 512, {0, 0}, gUnk_099A0F5C, gUnk_0815A5AA},
    {gUnk_09A3D63C, 32, {0, 0}, gUnk_099A08BA, 640, {0, 0}, gUnk_099A08A0, gUnk_0815A54A},
    {gUnk_09A3D5DC, 32, {0, 0}, gUnk_099A0206, 544, {0, 0}, gUnk_099A01EC, gUnk_0815A534},
    {gUnk_09A3D67C, 32, {0, 0}, gUnk_099A0DBC, 416, {0, 0}, gUnk_099A0D9C, gUnk_0815A59A},
    {gUnk_09A3D6BC, 32, {0, 0}, gUnk_099A118A, 544, {0, 0}, gUnk_099A1170, gUnk_0815A57C},
    {gUnk_09A3D6DC, 32, {0, 0}, gUnk_099A13CC, 544, {0, 0}, gUnk_099A13AC, gUnk_0815A5BE},
    {gUnk_09A3D71C, 32, {0, 0}, gUnk_099A181A, 768, {0, 0}, gUnk_099A1800, gUnk_0815A5D4},
    {gUnk_09A3D5FC, 32, {0, 0}, gUnk_099A0442, 544, {0, 0}, gUnk_099A0428, gUnk_0815A62A},
    {gUnk_09A3D61C, 32, {0, 0}, gUnk_099A067E, 544, {0, 0}, gUnk_099A0664, gUnk_0815A518},
    {gUnk_09A3D73C, 32, {0, 0}, gUnk_099A1B30, 512, {0, 0}, gUnk_099A1B1C, gUnk_0815A60E},
    {gUnk_09A3D75C, 32, {0, 0}, gUnk_099A1D44, 512, {0, 0}, gUnk_099A1D30, gUnk_0815A64A},
    {gUnk_09A3D6FC, 32, {0, 0}, gUnk_099A1600, 512, {0, 0}, gUnk_099A15EC, gUnk_0815A5F2},
#elif defined(VERSION_JP)
    {NULL, 0, {0, 0}, NULL, 0, {0, 0}, NULL, NULL},
    {gUnk_09A3D65C, 32, {0, 0}, gUnk_099A0B5C, 576, {0, 0}, gUnk_099A0B3C, gUnkJp_0814E590},
    {gUnk_09A3D69C, 32, {0, 0}, gUnk_099A0F70, 512, {0, 0}, gUnk_099A0F5C, gUnkJp_0814E5E4},
    {gUnk_09A3D63C, 32, {0, 0}, gUnk_099A08BA, 640, {0, 0}, gUnk_099A08A0, gUnkJp_0814E5CC},
    {gUnk_09A3D5DC, 32, {0, 0}, gUnk_099A0206, 544, {0, 0}, gUnk_099A01EC, gUnkJp_0814E59C},
    {gUnk_09A3D67C, 32, {0, 0}, gUnk_099A0DBC, 416, {0, 0}, gUnk_099A0D9C, gUnkJp_0814E5AC},
    {gUnk_09A3D6BC, 32, {0, 0}, gUnk_099A118A, 544, {0, 0}, gUnk_099A1170, gUnkJp_0814E5B8},
    {gUnk_09A3D6DC, 32, {0, 0}, gUnk_099A13CC, 544, {0, 0}, gUnk_099A13AC, gUnkJp_0814E5F4},
    {gUnk_09A3D71C, 32, {0, 0}, gUnk_099A181A, 768, {0, 0}, gUnk_099A1800, gUnkJp_0814E618},
    {gUnk_09A3D5FC, 32, {0, 0}, gUnk_099A0442, 544, {0, 0}, gUnk_099A0428, gUnkJp_0814E62C},
    {gUnk_09A3D61C, 32, {0, 0}, gUnk_099A067E, 544, {0, 0}, gUnk_099A0664, gUnkJp_0814E57C},
    {gUnk_09A3D73C, 32, {0, 0}, gUnk_099A1B30, 512, {0, 0}, gUnk_099A1B1C, gUnkJp_0814E644},
    {gUnk_09A3D75C, 32, {0, 0}, gUnk_099A1D44, 512, {0, 0}, gUnk_099A1D30, gUnkJp_0814E658},
    {gUnk_09A3D6FC, 32, {0, 0}, gUnk_099A1600, 512, {0, 0}, gUnk_099A15EC, gUnkJp_0814E604},
#elif defined(VERSION_EU)
    {NULL, 0, {0, 0}, NULL, 0, {0, 0}, NULL, NULL},
    {gUnk_09A3D65C, 32, {0, 0}, gUnk_099A0B5C, 576, {0, 0}, gUnk_099A0B3C, &gUnkEu_0888E3A0},
    {gUnk_09A3D69C, 32, {0, 0}, gUnk_099A0F70, 512, {0, 0}, gUnk_099A0F5C, &gUnkEu_0888E578},
    {gUnk_09A3D63C, 32, {0, 0}, gUnk_099A08BA, 640, {0, 0}, gUnk_099A08A0, &gUnkEu_0888E530},
    {gUnk_09A3D5DC, 32, {0, 0}, gUnk_099A0206, 544, {0, 0}, gUnk_099A01EC, &gUnkEu_0888E410},
    {gUnk_09A3D67C, 32, {0, 0}, gUnk_099A0DBC, 416, {0, 0}, gUnk_099A0D9C, &gUnkEu_0888E450},
    {gUnk_09A3D6BC, 32, {0, 0}, gUnk_099A118A, 544, {0, 0}, gUnk_099A1170, &gUnkEu_0888E4C0},
    {gUnk_09A3D6DC, 32, {0, 0}, gUnk_099A13CC, 544, {0, 0}, gUnk_099A13AC, &gUnkEu_0888E5DC},
    {gUnk_09A3D71C, 32, {0, 0}, gUnk_099A181A, 768, {0, 0}, gUnk_099A1800, &gUnkEu_0888E6BC},
    {gUnk_09A3D5FC, 32, {0, 0}, gUnk_099A0442, 544, {0, 0}, gUnk_099A0428, &gUnkEu_0888E72C},
    {gUnk_09A3D61C, 32, {0, 0}, gUnk_099A067E, 544, {0, 0}, gUnk_099A0664, &gUnkEu_0888E364},
    {gUnk_09A3D73C, 32, {0, 0}, gUnk_099A1B30, 512, {0, 0}, gUnk_099A1B1C, &gUnkEu_0888E78C},
    {gUnk_09A3D75C, 32, {0, 0}, gUnk_099A1D44, 512, {0, 0}, gUnk_099A1D30, &gUnkEu_0888E804},
    {gUnk_09A3D6FC, 32, {0, 0}, gUnk_099A1600, 512, {0, 0}, gUnk_099A15EC, &gUnkEu_0888E654},
#endif
};
void func_081004EC(u8 pal, u16 w, s16 h, u16* map, s16 x, s16 y) {
    s16 i;
    s16 j;
    s16 n;
    u16 v;

    n = w;
    v = pal << 12;
    map += x + y * 32;

    for (j = 0; j < h; j++) {
        for (i = 0; i < n; i++) {
            *map = (*map & 0xFFF) | v;
            map++;
        }
        map += 32 - n;
    }
}

void func_0810057C(s16 w, s16 h, u16* src, s16 sx, s16 sy, u16* dst, s16 dx, s16 dy) {
    s16 i;
    s16 j;
    s16 n;

    n = w;
    src += sx + sy * 32;
    dst += dx + dy * 32;

    for (j = 0; j < h; j++) {
        for (i = 0; i < n; i++) {
            *dst++ = *src++;
        }
        src += 32 - n;
        dst += 32 - n;
    }
}

u8 func_08100608(s16 a) {
    if (a <= 0) {
        return 0;
    }
#ifdef VERSION_EU
    return LoadTextSlots(eu_0805E924(gWorldSelectDefs[a].name), gUnk_02035618);
#else
    return LoadTextSlots(gWorldSelectDefs[a].name, gUnk_02035618);
#endif
}

u8 func_0810063C(s16 a) {
    if (a <= 0) {
        return 0;
    }
#ifdef VERSION_EU
    return LoadTextSlots(eu_0805E924(gWorldSelectDefs[a].name), gUnk_020356E0);
#else
    return LoadTextSlots(gWorldSelectDefs[a].name, gUnk_020356E0);
#endif
}

void func_08100670(s16 a, u8* b, void* c) {
    RequestDma3Copy(b + a * 256, c, 0x100);
}

u16 WorldInspectReadMenuKeys(void) {
    s32 keys;

    keys = GetKeysPressed() & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON);
    keys |= GetKeysRepeat() & (DPAD_ANY | L_BUTTON | R_BUTTON);
    return keys;
}

void func_081006AC(void) {
    s16 prev;
    u16 keys;

    prev = gUnk_020354E8;
    keys = WorldInspectReadMenuKeys();

    if (keys & A_BUTTON) {
        if (gUnk_020354E8 == gGameState.floor) {
            gUnk_0203550A = -1;
            LoadBgMap(0, gUnk_09A35A1C, 0x500);
            gUnk_020357A4 = 16;
            gUnk_020357A2 = 3;
            m4aSongNumStart(SONG_SYS_CLOSE);
        } else {
            if (gUnk_020354F0[gUnk_020354E8] >= 0) {
                gUnk_0203550A = gUnk_020354E8;
                LoadBgMap(0, gUnk_09A35A1C, 0x500);
                gUnk_020357A4 = 16;
                gUnk_020357A2 = 3;
                m4aSongNumStart(SONG_SYS_WORLDSTART);
            } else {
                m4aSongNumStart(SONG_SYS_BEEP);
            }
        }
    } else if (keys & B_BUTTON) {
        gUnk_0203550A = -1;
        LoadBgMap(0, gUnk_09A35A1C, 0x500);
        gUnk_020357A4 = 16;
        gUnk_020357A2 = 3;
        m4aSongNumStart(SONG_SYS_CLOSE);
    } else if (keys & DPAD_UP) {
        do {
            gUnk_020354E8 = gWarpIcons[gUnk_020354E8].up;
            if (gUnk_020354E8 == prev) {
                break;
            }
        } while (gUnk_020354F0[gUnk_020354E8] == -1);
    } else if (keys & DPAD_DOWN) {
        do {
            gUnk_020354E8 = gWarpIcons[gUnk_020354E8].down;
            if (gUnk_020354E8 == prev) {
                break;
            }
        } while (gUnk_020354F0[gUnk_020354E8] == -1);
    } else if (keys & DPAD_LEFT) {
        do {
            gUnk_020354E8 = gWarpIcons[gUnk_020354E8].left;
            if (gUnk_020354E8 == prev) {
                break;
            }
        } while (gUnk_020354F0[gUnk_020354E8] == -1);
    } else if (keys & DPAD_RIGHT) {
        do {
            gUnk_020354E8 = gWarpIcons[gUnk_020354E8].right;
            if (gUnk_020354E8 == prev) {
                break;
            }
        } while (gUnk_020354F0[gUnk_020354E8] == -1);
    }

    if (gUnk_020354E8 != prev) {
#ifdef VERSION_EU
        switch (gLanguage) {
        case 0:
            if ((gGameState.flags & 8) == 0) {
                func_08100670(gUnk_020354E8, gUnk_09A0D63C, (u8*)GetBgCharBase(0) + 0x20);
            } else {
                func_08100670(gUnk_020354E8, gUnk_09A0F03C, (u8*)GetBgCharBase(0) + 0x20);
            }
            break;
        case 1:
            if ((gGameState.flags & 8) == 0) {
                func_08100670(gUnk_020354E8, gUnk_09A53380, (u8*)GetBgCharBase(0) + 0x20);
            } else {
                func_08100670(gUnk_020354E8, gUnk_09A59B80, (u8*)GetBgCharBase(0) + 0x20);
            }
            break;
        case 4:
            if ((gGameState.flags & 8) == 0) {
                func_08100670(gUnk_020354E8, gUnk_09A54080, (u8*)GetBgCharBase(0) + 0x20);
            } else {
                func_08100670(gUnk_020354E8, gUnk_09A5A880, (u8*)GetBgCharBase(0) + 0x20);
            }
            break;
        case 3:
            if ((gGameState.flags & 8) == 0) {
                func_08100670(gUnk_020354E8, gUnk_09A54D80, (u8*)GetBgCharBase(0) + 0x20);
            } else {
                func_08100670(gUnk_020354E8, gUnk_09A5B580, (u8*)GetBgCharBase(0) + 0x20);
            }
            break;
        case 2:
        default:
            if ((gGameState.flags & 8) == 0) {
                func_08100670(gUnk_020354E8, gUnk_09A55A80, (u8*)GetBgCharBase(0) + 0x20);
            } else {
                func_08100670(gUnk_020354E8, gUnk_09A5C280, (u8*)GetBgCharBase(0) + 0x20);
            }
            break;
        }
#else
        if ((gGameState.flags & 8) == 0) {
            func_08100670(gUnk_020354E8, gUnk_09A0D63C, (u8*)GetBgCharBase(0) + 0x20);
        } else {
            func_08100670(gUnk_020354E8, gUnk_09A0F03C, (u8*)GetBgCharBase(0) + 0x20);
        }
#endif
        gUnk_020357A0 = func_0810063C(gUnk_020354F0[gUnk_020354E8]);
        m4aSongNumStart(SONG_SYS_CLICK);
    }
}

void func_08100980(void) {
    s32 i;
#ifdef VERSION_EU
    u8* tile0;
    u8* tile1;
    u8* tile2;

    switch (gLanguage) {
    case 0:
        tile0 = gUnkEu_099AABA4;
        tile1 = gUnkEu_099AABBA;
        tile2 = gUnkEu_099AABEE;
        break;
    case 1:
        tile0 = gUnkEu_099AB990;
        tile1 = gUnkEu_099AB9A6;
        tile2 = gUnkEu_099AB9DA;
        break;
    case 4:
        tile0 = gUnkEu_099ABF18;
        tile1 = gUnkEu_099ABF2E;
        tile2 = gUnkEu_099ABF62;
        break;
    case 3:
        tile0 = gUnkEu_099AC3E0;
        tile1 = gUnkEu_099AC3F6;
        tile2 = gUnkEu_099AC42A;
        break;
    case 2:
    default:
        tile0 = gUnkEu_099AC968;
        tile1 = gUnkEu_099AC97E;
        tile2 = gUnkEu_099AC9B2;
        break;
    }

    DrawSprite(gUnk_020357B0 >> 8, 0, tile0, gUnk_02035510, gUnk_02035514, 0, 0xC00, 0xBB8);
    if (gUnk_020357A2 != 2) {
        DrawSprite(0x80, gUnk_020357A8[0] >> 8, tile1, gUnk_02035510, gUnk_02035514, 0, 0xC00, 0xBB9);
        DrawSprite(0x80, gUnk_020357A8[1] >> 8, tile2, gUnk_02035510, gUnk_02035514, 0, 0xC00, 0xBB9);
    }
#else
    if (gUnk_020357A2 != 2) {
        DrawSprite(gUnk_020357B0 >> 8, 0, gUnk_0999F400, gUnk_02035510, gUnk_02035514, 0, 0xC00, 0xBB8);
        DrawSprite(0x80, gUnk_020357A8[0] >> 8, gUnk_0999F416, gUnk_02035510, gUnk_02035514, 0, 0xC00, 0xBB9);
        DrawSprite(0x80, gUnk_020357A8[1] >> 8, gUnk_0999F44A, gUnk_02035510, gUnk_02035514, 0, 0xC00, 0xBB9);
    }
#endif

    if (gUnk_020357A2 == 2) {
        DrawSprite((s16)(gWarpIcons[gUnk_020354E8].x * 8 + 22),
            (s16)(gWarpIcons[gUnk_020354E8].y * 8 + 12),
            AnimUpdate(&gUnk_02035520), gUnk_02035518, gUnk_0203551C, 0, 0x800, 0x898);
        ApproachValueHalf(&gUnk_020357B4, (gWarpIcons[gUnk_020354E8].x << 11) + 0x2000);
        ApproachValueHalf(&gUnk_020357B8, (gWarpIcons[gUnk_020354E8].y << 11) + 0xFFFFFA00);
        DrawSprite(gUnk_020357B4 >> 8, gUnk_020357B8 >> 8, AnimUpdate(&gUnk_02035558),
            gUnk_02035550, gUnk_02035554, 0, 0x800, 0x7D0);
    }

    for (i = 0; i <= 12; i++) {
        if (gUnk_020355E0[i] != 0) {
            DrawSprite((s16)(gWarpIcons[i].x * 8 + 16), (s16)(gWarpIcons[i].y * 8 + 16),
                gUnk_020355E0[i], gUnk_02035570[i], gUnk_020355A8[i], 0, 0x800, (u16)(i + 0x834));
        }
    }

    if (gUnk_020355E0[gGameState.floor] != 0) {
#ifdef VERSION_EU
        DrawSprite(0x66, 0x10, gUnk_020355E0[gGameState.floor], gUnk_02035570[gGameState.floor],
            gUnk_020355A8[gGameState.floor], 0, 0, 2);
#else
        DrawSprite(0x70, 0x10, gUnk_020355E0[gGameState.floor], gUnk_02035570[gGameState.floor],
            gUnk_020355A8[gGameState.floor], 0, 0, 2);
#endif
    }

    if (gUnk_020356D8 != 0) {
#ifdef VERSION_EU
        DrawTextSlots(0x78, 0x0C, gUnk_02035618, gUnk_0203551C, 0, gUnk_020356D8);
#else
        DrawTextSlots(0x80, 0x0C, gUnk_02035618, gUnk_0203551C, 0, gUnk_020356D8);
#endif
    }

    DrawSprite(0xB0, 0x1A, AnimUpdate(&gUnk_02035538), gUnk_02035518, gUnk_0203551C, 0, 0, 2);

    if (gUnk_020355E0[gUnk_020354E8] != 0) {
#ifdef VERSION_EU
        DrawSprite(0x66, 0x30, gUnk_020355E0[gUnk_020354E8], gUnk_02035570[gUnk_020354E8],
            gUnk_020355A8[gUnk_020354E8], 0, 0, 2);
#else
        DrawSprite(0x70, 0x30, gUnk_020355E0[gUnk_020354E8], gUnk_02035570[gUnk_020354E8],
            gUnk_020355A8[gUnk_020354E8], 0, 0, 2);
#endif
    }

    if (gUnk_020357A0 != 0) {
#ifdef VERSION_EU
        DrawTextSlots(0x78, 0x2C, gUnk_020356E0, gUnk_02035554, 0, gUnk_020357A0);
#else
        DrawTextSlots(0x80, 0x2C, gUnk_020356E0, gUnk_02035554, 0, gUnk_020357A0);
#endif
    }
}

void mode_worldwarp_0(void) {
    s32 i;
    void** p;
    vu32* dma;

    gUnk_020354EA = func_080DF750() + 1;
    p = &gUnk_0203550C;
    *p = EwramAlloc(0x500);
    SpriteReset();
    FadeStartIn(0, 16);
    SetBgMode0();
    SetupBg(0, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(2, 0, 30, 0);
    SetupBg(3, 0, 31, 0);
    SetBgPriority(0, 3);
    SetBgPriority(1, 2);
    SetBgPriority(2, 1);
    SetBgPriority(3, 0);
    gUnk_020354E8 = gGameState.floor;
    gUnk_0203550A = -1;

    for (i = 0; i <= 12; i++) {
        if (i < gUnk_020354EA) {
            gUnk_020354F0[i] = gGameState.floors[i].world;
        } else {
            gUnk_020354F0[i] |= 0xFFFFu;
        }
    }

    gUnk_020357A2 = 0;
    gUnk_020357A4 = 16;
    gUnk_020357A8[0] = -0x800;
    gUnk_020357A8[1] = 0xA800;
    gUnk_020357B0 = -0x8000;
    gUnk_020357B4 = (gWarpIcons[gUnk_020354E8].x << 11) + 0x2000;
    gUnk_020357B8 = (gWarpIcons[gUnk_020354E8].y << 11) - 0x600;
    LoadBgPalette(0, gUnk_09A3D37C, 0x200);

    for (i = 0; i <= 12; i++) {
        if (gUnk_020354F0[i] > 0) {
            gUnk_020355A8[i] = LoadObjPalette(gWorldSelectDefs[gUnk_020354F0[i]].palette, gWorldSelectDefs[gUnk_020354F0[i]].paletteSize);
            gUnk_02035570[i] = LoadObjTiles(gWorldSelectDefs[gUnk_020354F0[i]].tiles, gWorldSelectDefs[gUnk_020354F0[i]].tilesSize);
            gUnk_020355E0[i] = gWorldSelectDefs[gUnk_020354F0[i]].sprite;
        } else {
            gUnk_020355A8[i] = 0;
            gUnk_02035570[i] = 0;
            gUnk_020355E0[i] = 0;
        }
    }

    LoadBgTiles(0, gUnk_09A06A7C, 0x6BC0);
#ifdef VERSION_EU
    if (gGameState.flags & 8) {
        switch (gLanguage) {
        case 1:
            RequestDma3Copy(gUnkEu_09A4FBC0, (u8*)GetBgCharBase(0) + 0x6400, 0x800);
            break;
        case 4:
            RequestDma3Copy(gUnkEu_09A50BC0, (u8*)GetBgCharBase(0) + 0x6400, 0x800);
            break;
        case 3:
            RequestDma3Copy(gUnkEu_09A51BC0, (u8*)GetBgCharBase(0) + 0x6400, 0x800);
            break;
        case 2:
            RequestDma3Copy(gUnkEu_09A52BC0, (u8*)GetBgCharBase(0) + 0x6400, 0x800);
            break;
        }
    } else {
        switch (gLanguage) {
        case 1:
            RequestDma3Copy(gUnkEu_09A4F3C0, (u8*)GetBgCharBase(0) + 0x800, 0x800);
            break;
        case 4:
            RequestDma3Copy(gUnkEu_09A503C0, (u8*)GetBgCharBase(0) + 0x800, 0x800);
            break;
        case 3:
            RequestDma3Copy(gUnkEu_09A513C0, (u8*)GetBgCharBase(0) + 0x800, 0x800);
            break;
        case 2:
            RequestDma3Copy(gUnkEu_09A523C0, (u8*)GetBgCharBase(0) + 0x800, 0x800);
            break;
        }
    }
#endif

    LoadBgMap(0, gUnk_09A35A1C, 0x500);
    dma = (vu32*)REG_ADDR_DMA3;
    dma[0] = (u32)gUnk_09A3641C;
    dma[1] = (u32)gUnk_0203550C;
    dma[2] = (DMA_ENABLE << 16) | 0x280;
    dma[2];

    for (i = 0; i <= 12; i++) {
        if (gUnk_020354F0[i] >= 0) {
            func_0810057C(7, 4, gUnk_09A3691C, 0, 0, gUnk_0203550C, gWarpIcons[i].x, gWarpIcons[i].y);
        }
    }

    for (i = 0; i < gUnk_020354EA - 1; i++) {
        if (gUnk_020354F0[i] >= 0 && gUnk_020354F0[i + 1] >= 0) {
            func_0810057C(gWarpRects[gWarpIcons[i].rect].width, gWarpRects[gWarpIcons[i].rect].height,
                gUnk_09A3691C, gWarpRects[gWarpIcons[i].rect].x,
                gWarpRects[gWarpIcons[i].rect].y, gUnk_0203550C,
                gWarpIcons[i].x2, gWarpIcons[i].y2);
        }
    }

    for (i = 0; i < gUnk_020354EA; i++) {
        if (gUnk_020354F0[i] >= 0) {
            if ((gGameState.flags & 8) == 0) {
                if (i <= 8) {
                    func_0810057C(3, 1, gUnk_09A3691C, i * 3, 9, gUnk_0203550C,
                        gWarpIcons[i].x + 3, gWarpIcons[i].y + 2);
                } else {
                    func_0810057C(4, 1, gUnk_09A3691C, (i - 9) * 4, 10, gUnk_0203550C,
                        gWarpIcons[i].x + 3, gWarpIcons[i].y + 2);
                }
            } else if (i <= 2) {
                func_0810057C(4, 1, gUnk_09A3691C, i * 4, 21, gUnk_0203550C,
                    gWarpIcons[i].x + 3, gWarpIcons[i].y + 2);
            } else {
                func_0810057C(3, 1, gUnk_09A3691C, (i - 3) * 3, 22, gUnk_0203550C,
                    gWarpIcons[i].x + 3, gWarpIcons[i].y + 2);
            }
        }
    }

    for (i = 0; i < gUnk_020354EA; i++) {
        if (gUnk_020354E8 == i) {
            func_081004EC(3, 7, 4, gUnk_0203550C, gWarpIcons[i].x, gWarpIcons[i].y);
        } else {
            func_081004EC(2, 7, 4, gUnk_0203550C, gWarpIcons[i].x, gWarpIcons[i].y);
        }
    }

    LoadBgMap(1, gUnk_0203550C, 0x500);

#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        if ((gGameState.flags & 8) == 0) {
            func_08100670(gGameState.floor, gUnk_09A0E33C, (u8*)GetBgCharBase(0) + 0x120);
            func_08100670(gUnk_020354E8, gUnk_09A0D63C, (u8*)GetBgCharBase(0) + 0x20);
        } else {
            func_08100670(gGameState.floor, gUnk_09A0FD3C, (u8*)GetBgCharBase(0) + 0x120);
            func_08100670(gUnk_020354E8, gUnk_09A0F03C, (u8*)GetBgCharBase(0) + 0x20);
        }
        break;
    case 1:
        if ((gGameState.flags & 8) == 0) {
            func_08100670(gGameState.floor, gUnkEu_09A56780, (u8*)GetBgCharBase(0) + 0x120);
            func_08100670(gUnk_020354E8, gUnk_09A53380, (u8*)GetBgCharBase(0) + 0x20);
        } else {
            func_08100670(gGameState.floor, gUnkEu_09A5CF80, (u8*)GetBgCharBase(0) + 0x120);
            func_08100670(gUnk_020354E8, gUnk_09A59B80, (u8*)GetBgCharBase(0) + 0x20);
        }
        break;
    case 4:
        if ((gGameState.flags & 8) == 0) {
            func_08100670(gGameState.floor, gUnkEu_09A57480, (u8*)GetBgCharBase(0) + 0x120);
            func_08100670(gUnk_020354E8, gUnk_09A54080, (u8*)GetBgCharBase(0) + 0x20);
        } else {
            func_08100670(gGameState.floor, gUnkEu_09A5DC80, (u8*)GetBgCharBase(0) + 0x120);
            func_08100670(gUnk_020354E8, gUnk_09A5A880, (u8*)GetBgCharBase(0) + 0x20);
        }
        break;
    case 3:
        if ((gGameState.flags & 8) == 0) {
            func_08100670(gGameState.floor, gUnkEu_09A58180, (u8*)GetBgCharBase(0) + 0x120);
            func_08100670(gUnk_020354E8, gUnk_09A54D80, (u8*)GetBgCharBase(0) + 0x20);
        } else {
            func_08100670(gGameState.floor, gUnkEu_09A5E980, (u8*)GetBgCharBase(0) + 0x120);
            func_08100670(gUnk_020354E8, gUnk_09A5B580, (u8*)GetBgCharBase(0) + 0x20);
        }
        break;
    case 2:
    default:
        if ((gGameState.flags & 8) == 0) {
            func_08100670(gGameState.floor, gUnkEu_09A58E80, (u8*)GetBgCharBase(0) + 0x120);
            func_08100670(gUnk_020354E8, gUnk_09A55A80, (u8*)GetBgCharBase(0) + 0x20);
        } else {
            func_08100670(gGameState.floor, gUnkEu_09A5F680, (u8*)GetBgCharBase(0) + 0x120);
            func_08100670(gUnk_020354E8, gUnk_09A5C280, (u8*)GetBgCharBase(0) + 0x20);
        }
        break;
    }
#else
    if ((gGameState.flags & 8) == 0) {
        func_08100670(gGameState.floor, gUnk_09A0E33C, (u8*)GetBgCharBase(0) + 0x120);
        func_08100670(gUnk_020354E8, gUnk_09A0D63C, (u8*)GetBgCharBase(0) + 0x20);
    } else {
        func_08100670(gGameState.floor, gUnk_09A0FD3C, (u8*)GetBgCharBase(0) + 0x120);
        func_08100670(gUnk_020354E8, gUnk_09A0F03C, (u8*)GetBgCharBase(0) + 0x20);
    }
#endif
    gUnk_02035514 = LoadObjPalette(gUnk_09A3D57C, 32);
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        gUnk_02035510 = LoadObjTiles(gUnkEu_099AAC2C, 0x500);
        break;
    case 1:
        gUnk_02035510 = LoadObjTiles(gUnkEu_099ABA18, 0x500);
        break;
    case 4:
        gUnk_02035510 = LoadObjTiles(gUnkEu_099ABFA0, 0x440);
        break;
    case 3:
        gUnk_02035510 = LoadObjTiles(gUnkEu_099AC468, 0x500);
        break;
    case 2:
    default:
        gUnk_02035510 = LoadObjTiles(gUnkEu_099AC9F0, 0x500);
        break;
    }
#else
    gUnk_02035510 = LoadObjTiles(gUnk_0999F488, 0x500);
#endif
    gUnk_0203551C = LoadObjPalette(gUnk_09A3D59C, 32);
    gUnk_02035518 = LoadObjTiles(gUnk_0999FA20, 0x680);
    AnimInit(&gUnk_02035520, gUnk_09EF9898, gUnk_09EF9870);
    AnimStart(&gUnk_02035520, 0, 1);
    AnimInit(&gUnk_02035538, gUnk_09EF9898, gUnk_09EF9870);
    AnimStart(&gUnk_02035538, 1, 1);
    gUnk_02035554 = LoadObjPalette(gUnk_09A3D5BC, 32);
    gUnk_02035550 = LoadObjTiles(gUnk_099A012C, 192);
    AnimInit(&gUnk_02035558, gUnk_09EF98B0, gUnk_09EF98A0);
    AnimStart(&gUnk_02035558, 0, 1);
#ifdef VERSION_EU
    InitTextSlots(gUnk_02035618, 48);
    InitTextSlots(gUnk_020356E0, 48);
#else
    InitTextSlots(gUnk_02035618, 24);
    InitTextSlots(gUnk_020356E0, 24);
#endif
    gUnk_020356D8 = func_08100608(gUnk_020354F0[gGameState.floor]);
    gUnk_020357A0 = func_0810063C(gUnk_020354F0[gUnk_020354E8]);
    EnableBg(0);
    EnableBg(1);
    DisableBg(2);
    DisableBg(3);
}

void mode_worldwarp_1(void) {
    UpdatePlayTime();

    switch (gUnk_020357A2) {
    case 0:
        ApproachValue(&gUnk_020357A8[0], 0, gUnk_020357A4);
        ApproachValue(&gUnk_020357A8[1], 0x9800, gUnk_020357A4);

        if (--gUnk_020357A4 <= 0) {
            gUnk_020357A4 = 16;
            gUnk_020357A2 = 1;
        }
        break;
    case 1:
        ApproachValue(&gUnk_020357B0, 0, gUnk_020357A4);

        if (--gUnk_020357A4 <= 0) {
            LoadBgMap(0, gUnk_09A35F1C, 0x500);
            gUnk_020357A2 = 2;
        }
        break;
    case 2:
        func_081006AC();
        break;
    case 3:
        ApproachValue(&gUnk_020357B0, -0x8000, gUnk_020357A4);

        if (--gUnk_020357A4 <= 0) {
            gUnk_020357A4 = 16;
            gUnk_020357A2 = 4;
        }
        break;
    case 4:
        ApproachValue(&gUnk_020357A8[0], -0x800, gUnk_020357A4);
        ApproachValue(&gUnk_020357A8[1], 0xA800, gUnk_020357A4);

        if (--gUnk_020357A4 <= 0) {
            gUnk_020357A4 = 16;
            FadeStartOut(0, 16);
            gUnk_020357A2 = 5;
        }
        break;
    case 5:
        if (!FadeIsActive()) {
            if (gUnk_0203550A >= 0) {
                func_080DF9E0(gUnk_0203550A);
            } else {
                func_080E04EC();
            }
        }
        break;
    }
    func_08100980();
}

void mode_worldwarp_2(void) {
    s32 i;

    ReleaseObjPalette(gUnk_02035514);
    ReleaseObjTiles(gUnk_02035510);
    ReleaseObjPalette(gUnk_0203551C);
    ReleaseObjTiles(gUnk_02035518);
    ReleaseObjPalette(gUnk_02035554);
    ReleaseObjTiles(gUnk_02035550);

    for (i = 0; i <= 12; i++) {
        if (gUnk_020355A8[i] != 0) {
            ReleaseObjPalette(gUnk_020355A8[i]);
        }

        if (gUnk_02035570[i] != 0) {
            ReleaseObjTiles(gUnk_02035570[i]);
        }
    }
#ifdef VERSION_EU
    FreeTextSlots(gUnk_02035618, 48);
#else
    FreeTextSlots(gUnk_02035618, 24);
#endif
#ifdef VERSION_EU
    FreeTextSlots(gUnk_020356E0, 48);
#else
    FreeTextSlots(gUnk_020356E0, 24);
#endif
    EwramFree(gUnk_0203550C);
}

const char gModeNameWorldwarp[] = "mode_worldwarp";

Mode gModeWorldwarp = {
    gModeNameWorldwarp,
    (ModeInitFunc)mode_worldwarp_0,
    mode_worldwarp_1,
    mode_worldwarp_2,
};
