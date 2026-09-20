#include "animation_resource_data.h"
#include "worldinspect_data.h"
#include "registration_data.h"
#include "system_state.h"
#include "map_api.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "text.h"
#include "monsgage.h"
#include "fade.h"
#include "obj_api.h"
#include "display.h"
#include "malloc.h"
#include "mode_worldinspect.h"
#include "game_state.h"
#include "gba/keys.h"
#include "anim.h"
#include "card_description_data.h"
#include "worldselect_assets.h"
#include "bos4_api.h"
#include "msg_api.h"
#include "worldinspect_assets.h"
#ifdef VERSION_EU
extern u8 gUnkEu_09A86E60[];
extern u8 gUnkEu_09A2D440[];
extern u8 gUnkEu_09A2E440[];
extern u8 gUnkEu_09A2F440[];
extern u8 gUnkEu_09A30440[];
extern u8 gUnkEu_09A2CC40[];
extern u8 gUnkEu_09A2DC40[];
extern u8 gUnkEu_09A2EC40[];
extern u8 gUnkEu_09A2FC40[];
extern u8 gUnkEu_099A4CDA[];
extern u8 gUnkEu_099A51AA[];
extern u8 gUnkEu_099A563A[];
extern u8 gUnkEu_099A5ACA[];
#endif


extern u8 gUnk_09A02EFC[];
extern u8 gUnk_09A020FC[];

static s16 gUnk_020350F8;
static s16 gUnk_020350FA;
static s16 gUnk_02035100[12];

#ifdef VERSION_EU
extern u8 gUnkEu_099A421C[];
extern u8 gUnkEu_099A4238[];
extern u8 gUnkEu_099A426C[];
extern u8 gUnkEu_099A4C4C[];
extern u8 gUnkEu_099A4C68[];
extern u8 gUnkEu_099A4C9C[];
extern u8 gUnkEu_099A511C[];
extern u8 gUnkEu_099A5138[];
extern u8 gUnkEu_099A516C[];
extern u8 gUnkEu_099A55AC[];
extern u8 gUnkEu_099A55C8[];
extern u8 gUnkEu_099A55FC[];
extern u8 gUnkEu_099A5A3C[];
extern u8 gUnkEu_099A5A58[];
extern u8 gUnkEu_099A5A8C[];
extern u8 gUnkEu_09A2B040[];
extern u8 gUnkEu_09A2BE40[];
extern u8 gUnkEu_09A30C00[];
extern u8 gUnkEu_09A34400[];
extern u8 gUnkEu_09A31A00[];
extern u8 gUnkEu_09A35200[];
extern u8 gUnkEu_09A32800[];
extern u8 gUnkEu_09A38C00[];
extern u8 gUnkEu_09A33600[];
extern u8 gUnkEu_09A39A00[];
#endif


typedef struct {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
} WorldinspectConn;


extern WorldinspectConn gUnk_099930BC[];
extern u8 gUnk_099FB53C[];
extern u8 gUnk_09A324DC[];
extern u8 gUnk_09A32EDC[];
extern u8 gUnk_09A333DC[];
extern u8 gUnk_09A3399C[];
extern u8 gUnk_09A33E9C[];
extern u8 gUnk_09A3CE7C[];
extern u8 gUnk_09A3D07C[];
extern u8 gUnk_09A3D09C[];
extern u8 gUnk_09A3D0BC[];
extern u8 gUnk_0999CFC6[];
extern u8 gUnk_0999D41A[];
extern u8 gUnk_0999D8A8[];

static s16 gUnk_02035118;
static u8 gUnk_0203511A;
static struct ObjPalette* gUnk_0203511C;
static struct ObjTiles* gUnk_02035120;
static struct ObjPalette* gUnk_02035124;
static struct ObjTiles* gUnk_02035128;
static AnimState gUnk_02035130;
static struct ObjPalette* gUnk_02035148;
static struct ObjTiles* gUnk_0203514C;
static AnimState gUnk_02035150;
static void* gUnk_02035168[12];
static void* gUnk_02035198[12];
static void* gUnk_020351C8[12];
#ifdef VERSION_EU
static TextSlot gUnk_020351F8[48];
#else
static TextSlot gUnk_020351F8[24];
#endif
static u8 gUnk_020352B8;
#ifdef VERSION_EU
static TextSlot gUnk_020352C0[120];
#else
static TextSlot gUnk_020352C0[60];
#endif
static u8 gUnk_020354A0;
static void* gUnk_020354A8[2];
static void* gUnk_020354B0[2];
static void* gUnk_020354B8[2];
static s16 gUnk_020354C0;
static s16 gUnk_020354C2;
static s32 gUnk_020354C8[2];
static s32 gUnk_020354D0;
static void* gUnk_020354D4;
static s32 gUnk_020354D8;
static s32 gUnk_020354DC;
static u8 gUnk_020354E0;

WorldinspectNav gUnk_09EF8FAC[12] = {
    { 7, 8, 1, 3, 22, 14, 0, 21, 16, { 0, 0 } },
    { 6, 9, 2, 0, 15, 14, 0, 14, 16, { 0, 0 } },
    { 5, 10, 3, 1, 8, 14, 0, 7, 16, { 0, 0 } },
    { 4, 11, 0, 2, 1, 14, 1, 0, 12, { 0, 0 } },
    { 11, 3, 7, 5, 1, 10, 0, 7, 12, { 0, 0 } },
    { 10, 2, 4, 6, 8, 10, 0, 14, 12, { 0, 0 } },
    { 9, 1, 5, 7, 15, 10, 0, 21, 12, { 0, 0 } },
    { 8, 0, 6, 4, 22, 10, 2, 28, 8, { 0, 0 } },
    { 0, 7, 9, 11, 22, 6, 0, 21, 8, { 0, 0 } },
    { 1, 6, 10, 8, 15, 6, 0, 14, 8, { 0, 0 } },
    { 2, 5, 11, 9, 8, 6, 0, 7, 8, { 0, 0 } },
    { 3, 4, 8, 10, 1, 6, 0, 0, 8, { 0, 0 } },
};

WorldinspectMsg gUnk_09EF909C[14] = {
    {
        0, 0, 0, 0, { 0, 0 }, 0, 0, { 0, 0 }, 0, 0, 0, { 0, 0 }, 0, 0, { 0, 0 }, 0,
        0,
        0, 0,
    },
    {
        1, 1, gUnk_09A3D65C, 32, { 0, 0 }, gUnk_099A0B5C, 576, { 0, 0 }, gUnk_099A0B3C, gUnk_09A3CD1C, 32, { 0, 0 }, gUnk_099E7E7C, 4096, { 0, 0 }, gUnk_099A8824,
#if defined(VERSION_EU)
        &gUnkEu_0888E3A0,
#elif defined(VERSION_JP)
        gUnkJp_0814E590,
#elif defined(VERSION_US)
        gUnk_0815A56C,
#endif
        0, 0,
    },
    {
        2, 2, gUnk_09A3D69C, 32, { 0, 0 }, gUnk_099A0F70, 512, { 0, 0 }, gUnk_099A0F5C, gUnk_09A3CD5C, 32, { 0, 0 }, gUnk_099E9E7C, 4096, { 0, 0 }, gUnk_099A8880,
#if defined(VERSION_EU)
        &gUnkEu_0888E578,
#elif defined(VERSION_JP)
        gUnkJp_0814E5E4,
#elif defined(VERSION_US)
        gUnk_0815A5AA,
#endif
        2, 2,
    },
    {
        4, 3, gUnk_09A3D63C, 32, { 0, 0 }, gUnk_099A08BA, 640, { 0, 0 }, gUnk_099A08A0, gUnk_09A3CCFC, 32, { 0, 0 }, gUnk_099E6E7C, 4096, { 0, 0 }, gUnk_099A87F8,
#if defined(VERSION_EU)
        &gUnkEu_0888E530,
#elif defined(VERSION_JP)
        gUnkJp_0814E5CC,
#elif defined(VERSION_US)
        gUnk_0815A54A,
#endif
        6, 6,
    },
    {
        8, 4, gUnk_09A3D5DC, 32, { 0, 0 }, gUnk_099A0206, 544, { 0, 0 }, gUnk_099A01EC, gUnk_09A3CC9C, 32, { 0, 0 }, gUnk_099E3E7C, 4096, { 0, 0 }, gUnk_099A8758,
#if defined(VERSION_EU)
        &gUnkEu_0888E410,
#elif defined(VERSION_JP)
        gUnkJp_0814E59C,
#elif defined(VERSION_US)
        gUnk_0815A534,
#endif
        4, 4,
    },
    {
        16, 5, gUnk_09A3D67C, 32, { 0, 0 }, gUnk_099A0DBC, 416, { 0, 0 }, gUnk_099A0D9C, gUnk_09A3CD3C, 32, { 0, 0 }, gUnk_099E8E7C, 4096, { 0, 0 }, gUnk_099A884C,
#if defined(VERSION_EU)
        &gUnkEu_0888E450,
#elif defined(VERSION_JP)
        gUnkJp_0814E5AC,
#elif defined(VERSION_US)
        gUnk_0815A59A,
#endif
        3, 3,
    },
    {
        32, 6, gUnk_09A3D6BC, 32, { 0, 0 }, gUnk_099A118A, 544, { 0, 0 }, gUnk_099A1170, gUnk_09A3CD7C, 32, { 0, 0 }, gUnk_099EAE7C, 4096, { 0, 0 }, gUnk_099A88A0,
#if defined(VERSION_EU)
        &gUnkEu_0888E4C0,
#elif defined(VERSION_JP)
        gUnkJp_0814E5B8,
#elif defined(VERSION_US)
        gUnk_0815A57C,
#endif
        5, 5,
    },
    {
        64, 7, gUnk_09A3D6DC, 32, { 0, 0 }, gUnk_099A13CC, 544, { 0, 0 }, gUnk_099A13AC, gUnk_09A3CD9C, 32, { 0, 0 }, gUnk_099EBE7C, 4096, { 0, 0 }, gUnk_099A88D4,
#if defined(VERSION_EU)
        &gUnkEu_0888E5DC,
#elif defined(VERSION_JP)
        gUnkJp_0814E5F4,
#elif defined(VERSION_US)
        gUnk_0815A5BE,
#endif
        1, 1,
    },
    {
        128, 8, gUnk_09A3D71C, 32, { 0, 0 }, gUnk_099A181A, 768, { 0, 0 }, gUnk_099A1800, gUnk_09A3CE1C, 32, { 0, 0 }, gUnk_099EEE7C, 4096, { 0, 0 }, gUnk_099A8930,
#if defined(VERSION_EU)
        &gUnkEu_0888E6BC,
#elif defined(VERSION_JP)
        gUnkJp_0814E618,
#elif defined(VERSION_US)
        gUnk_0815A5D4,
#endif
        7, 7,
    },
    {
        256, 9, gUnk_09A3D5FC, 32, { 0, 0 }, gUnk_099A0442, 544, { 0, 0 }, gUnk_099A0428, gUnk_09A3CCBC, 32, { 0, 0 }, gUnk_099E4E7C, 4096, { 0, 0 }, gUnk_099A8780,
#if defined(VERSION_EU)
        &gUnkEu_0888E72C,
#elif defined(VERSION_JP)
        gUnkJp_0814E62C,
#elif defined(VERSION_US)
        gUnk_0815A62A,
#endif
        8, 8,
    },
    {
        512, 10, gUnk_09A3D61C, 32, { 0, 0 }, gUnk_099A067E, 544, { 0, 0 }, gUnk_099A0664, gUnk_09A3CCDC, 32, { 0, 0 }, gUnk_099E5E7C, 4096, { 0, 0 }, gUnk_099A87C0,
#if defined(VERSION_EU)
        &gUnkEu_0888E364,
#elif defined(VERSION_JP)
        gUnkJp_0814E57C,
#elif defined(VERSION_US)
        gUnk_0815A518,
#endif
        9, 9,
    },
    {
        2048, 11, gUnk_09A3D73C, 32, { 0, 0 }, gUnk_099A1B30, 512, { 0, 0 }, gUnk_099A1B1C, gUnk_09A3CE3C, 32, { 0, 0 }, gUnk_099EFE7C, 4096, { 0, 0 }, gUnk_099A895C,
#if defined(VERSION_EU)
        &gUnkEu_0888E78C,
#elif defined(VERSION_JP)
        gUnkJp_0814E644,
#elif defined(VERSION_US)
        gUnk_0815A60E,
#endif
        10, 10,
    },
    {
        4096, 12, gUnk_09A3D75C, 32, { 0, 0 }, gUnk_099A1D44, 512, { 0, 0 }, gUnk_099A1D30, gUnk_09A3CE5C, 32, { 0, 0 }, gUnk_099F0E7C, 4096, { 0, 0 }, gUnk_099A897C,
#if defined(VERSION_EU)
        &gUnkEu_0888E804,
#elif defined(VERSION_JP)
        gUnkJp_0814E658,
#elif defined(VERSION_US)
        gUnk_0815A64A,
#endif
        11, 13,
    },
    {
        1024, 13, gUnk_09A3D6FC, 32, { 0, 0 }, gUnk_099A1600, 512, { 0, 0 }, gUnk_099A15EC, gUnk_09A3CDBC, 32, { 0, 0 }, gUnk_099ECE7C, 4096, { 0, 0 }, gUnk_099A8900,
#if defined(VERSION_EU)
        &gUnkEu_0888E654,
#elif defined(VERSION_JP)
        gUnkJp_0814E604,
#elif defined(VERSION_US)
        gUnk_0815A5F2,
#endif
        12, 12,
    },
};

void func_080FF10C(u8 pal, u16 w, s16 h, u16* map, s16 x, s16 y) {
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
void func_080FF19C(s16 w, s16 h, u16* src, s16 sx, s16 sy, u16* dst, s16 dx, s16 dy) {
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
u8 func_080FF228(s16 id) {
#ifdef VERSION_EU
    u8 ret = 0;

    if (id != 0) {
        ret = LoadTextSlots(eu_0805E924(gUnk_09EF909C[id].text), gUnk_020351F8);
    }
    return ret;
#else
    if (id == 0) {
        return 0;
    }

    return LoadTextSlots(gUnk_09EF909C[id].text, gUnk_020351F8);
#endif
}
u8 func_080FF25C(s16 id) {
    CardDescriptionText** tbl;
    CardDescriptionText** p;
    u16 i;

    if (id != 0) {
        tbl = gUnk_09EE9138;

        if (gGameState.flags & 8) {
            i = gUnk_09EF909C[id].descId2;
        } else {
            i = gUnk_09EF909C[id].descId;
        }

        p = &tbl[i];
#ifdef VERSION_EU
        {
            u8** langs = (*p)->strings;

            return LoadTextSlots((void*)langs[gLanguage], gUnk_020352C0);
        }
#else
        return LoadTextSlots((void*)*p, gUnk_020352C0);
#endif
    }

    return 0;
}

void func_080FF2B8(s16 index) {
    u8* src;

#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        if ((gGameState.flags & 8) == 0) {
            src = gUnkEu_09A2B040;
        } else {
            src = gUnkEu_09A2BE40;
        }
        break;
    case 1:
        if ((gGameState.flags & 8) == 0) {
            src = gUnkEu_09A30C00;
        } else {
            src = gUnkEu_09A34400;
        }
        break;
    case 4:
        if ((gGameState.flags & 8) == 0) {
            src = gUnkEu_09A31A00;
        } else {
            src = gUnkEu_09A35200;
        }
        break;
    case 3:
        if ((gGameState.flags & 8) == 0) {
            src = gUnkEu_09A32800;
        } else {
            src = gUnkEu_09A38C00;
        }
        break;
    case 2:
    default:
        if ((gGameState.flags & 8) == 0) {
            src = gUnkEu_09A33600;
        } else {
            src = gUnkEu_09A39A00;
        }
        break;
    }
#else
    if ((gGameState.flags & 8) == 0) {
        src = gUnk_09A020FC;
    } else {
        src = gUnk_09A02EFC;
    }
#endif

    if (index < gUnk_020350FA) {
        src += index * 256;
    } else {
        src += 0xD00;
    }

    RequestDma3Copy(src, (u8*)GetBgCharBase(0) + 32, 0x100);
}
s32 func_080FF310(void) {
    s32 keys;

    keys = GetKeysPressed() & 0xF;
    keys |= GetKeysRepeat() & 0x3F0;
    return keys;
}
void func_080FF330(void) {
    u16 keys;
    s16 old;
    s16 i;

    old = gUnk_020350F8;
    keys = func_080FF310();

    if (keys & 1) {
        if (gUnk_02035100[gUnk_020350F8] != 0) {
#ifdef VERSION_EU
            ReleaseObjPalette(gUnk_0203511C);
            gUnk_0203511C = 0;
#endif
            gUnk_020354A8[0] = LoadObjPalette(gUnk_09A3CC3C, 32);
            gUnk_020354B0[0] = LoadObjTiles(gUnk_0999A394, 0xC40);
            gUnk_020354B8[0] = gUnk_0999A350;

            if (gUnk_020350F8 <= 9) {
                for (i = 10; i < 12; i++) {
                    if (gUnk_02035168[i] != 0) {
                        ReleaseObjPalette(gUnk_02035168[i]);
                        gUnk_02035168[i] = 0;
                    }
                }
            } else {
                for (i = 4; i < 6; i++) {
                    if (gUnk_02035168[i] != 0) {
                        ReleaseObjPalette(gUnk_02035168[i]);
                        gUnk_02035168[i] = 0;
                    }
                }
            }

            if (gUnk_02035100[gUnk_020350F8] == 13 && func_080D2DD8()) {
                gUnk_020354A8[1] = LoadObjPalette(gUnk_09A3CDDC, 64);
                gUnk_020354B0[1] = LoadObjTiles(gUnk_099EDE7C, 0x1000);
                gUnk_020354B8[1] = gUnk_099A8914;
            } else {
                gUnk_020354A8[1] =
                    LoadObjPalette(gUnk_09EF909C[gUnk_02035100[gUnk_020350F8]].palette2,
                                   gUnk_09EF909C[gUnk_02035100[gUnk_020350F8]].paletteSize2);
                gUnk_020354B0[1] =
                    LoadObjTiles(gUnk_09EF909C[gUnk_02035100[gUnk_020350F8]].tiles2,
                                 gUnk_09EF909C[gUnk_02035100[gUnk_020350F8]].tilesSize2);
                gUnk_020354B8[1] = gUnk_09EF909C[gUnk_02035100[gUnk_020350F8]].sprite2;
            }

            gUnk_020354A0 = func_080FF25C(gUnk_02035100[gUnk_020350F8]);
            gBldCnt = 0x744;
            gBldAlpha = 0x808;
            EnableBg(2);
            EnableBg(3);
            m4aSongNumStart(102);
            gUnk_02035118 = 1;
        }
    } else if (keys & 2) {
        m4aSongNumStart(104);
        LoadBgMap(0, gUnk_09A324DC, 0x500);
#ifndef VERSION_EU
        gUnk_0203511C = LoadObjPalette(gUnk_09A3D07C, 32);
#endif
        gUnk_020354E0 = 1;
        gUnk_020354C2 = 16;
        gUnk_020354C0 = 3;
    } else if (keys & 8) {
        m4aSongNumStart(104);
        LoadBgMap(0, gUnk_09A324DC, 0x500);
#ifndef VERSION_EU
        gUnk_0203511C = LoadObjPalette(gUnk_09A3D07C, 32);
#endif
        gUnk_020354E0 = 0;
        FadeStartOut(0, 16);
        gUnk_020354C0 = 5;
    } else if (keys & 0x40) {
        while (1) {
            gUnk_020350F8 = gUnk_09EF8FAC[gUnk_020350F8].up;

            if (gUnk_020350F8 == old) {
                break;
            }

            if (gUnk_02035100[gUnk_020350F8] != 0) {
                break;
            }
        }
    } else if (keys & 0x80) {
        while (1) {
            gUnk_020350F8 = gUnk_09EF8FAC[gUnk_020350F8].down;

            if (gUnk_020350F8 == old) {
                break;
            }

            if (gUnk_02035100[gUnk_020350F8] != 0) {
                break;
            }
        }
    } else if (keys & 0x20) {
        while (1) {
            gUnk_020350F8 = gUnk_09EF8FAC[gUnk_020350F8].left;

            if (gUnk_020350F8 == old) {
                break;
            }

            if (gUnk_02035100[gUnk_020350F8] != 0) {
                break;
            }
        }
    } else if (keys & 0x10) {
        while (1) {
            gUnk_020350F8 = gUnk_09EF8FAC[gUnk_020350F8].right;

            if (gUnk_020350F8 == old) {
                break;
            }

            if (gUnk_02035100[gUnk_020350F8] != 0) {
                break;
            }
        }
    }

    if (gUnk_020350F8 != old) {
        func_080FF2B8(gUnk_020350F8);
        gUnk_020352B8 = func_080FF228(gUnk_02035100[gUnk_020350F8]);
        m4aSongNumStart(101);
    }
}
void func_080FF794(void) {
    u16 keys;
    s32 i;

    keys = func_080FF310();

    if (keys & 10) {
        m4aSongNumStart(104);

        for (i = 0; i < 2; i++) {
            ReleaseObjPalette(gUnk_020354A8[i]);
            ReleaseObjTiles(gUnk_020354B0[i]);
        }

        if (gUnk_020350F8 <= 9) {
            for (i = 10; i < 12; i++) {
                if (gUnk_02035100[i] != 0) {
                    gUnk_02035168[i] = LoadObjPalette(gUnk_09EF909C[gUnk_02035100[i]].palette,
                                                      gUnk_09EF909C[gUnk_02035100[i]].paletteSize);
                }
            }
        } else {
            for (i = 4; i < 6; i++) {
                if (gUnk_02035100[i] != 0) {
                    gUnk_02035168[i] = LoadObjPalette(gUnk_09EF909C[gUnk_02035100[i]].palette,
                                                      gUnk_09EF909C[gUnk_02035100[i]].paletteSize);
                }
            }
        }

        gBldCnt = 0;
        DisableBg(2);
        DisableBg(3);
        gUnk_020354E0 = 1;
        gUnk_02035118 = 0;

#ifdef VERSION_EU
        gUnk_0203511C = LoadObjPalette(gUnk_09A3D07C, 32);
#endif

        if (keys & 8) {
            LoadBgMap(0, gUnk_09A324DC, 0x500);
#ifndef VERSION_EU
            gUnk_0203511C = LoadObjPalette(gUnk_09A3D07C, 32);
#endif
            gUnk_020354E0 = 0;
            FadeStartOut(0, 16);
            gUnk_020354C0 = 5;
        }
    }
}
void func_080FF8CC(void) {
    s32 i;
    u16 prio;
#ifdef VERSION_EU
    void* first;
    void* second;
    void* third;

    switch (gLanguage) {
    case 0:
        first = gUnkEu_099A421C;
        second = gUnkEu_099A4238;
        third = gUnkEu_099A426C;
        break;
    case 1:
        first = gUnkEu_099A4C4C;
        second = gUnkEu_099A4C68;
        third = gUnkEu_099A4C9C;
        break;
    case 4:
        first = gUnkEu_099A511C;
        second = gUnkEu_099A5138;
        third = gUnkEu_099A516C;
        break;
    case 3:
        first = gUnkEu_099A55AC;
        second = gUnkEu_099A55C8;
        third = gUnkEu_099A55FC;
        break;
    case 2:
    default:
        first = gUnkEu_099A5A3C;
        second = gUnkEu_099A5A58;
        third = gUnkEu_099A5A8C;
        break;
    }

#endif

#ifdef VERSION_EU
    if (gUnk_0203511C != 0) {
#else
    if (gUnk_020354C0 != 2) {
#endif
        DrawSprite(gUnk_020354D0 >> 8, 0,
#ifdef VERSION_EU
                      first,
#else
                      gUnk_0999CF38,
#endif
                      gUnk_02035120, gUnk_0203511C, 0,
                      0xC00, 3000);
#ifdef VERSION_EU
    }

    if (gUnk_020354C0 != 2) {
#endif
        DrawSprite(112, gUnk_020354C8[0] >> 8,
#ifdef VERSION_EU
                      second,
#else
                      gUnk_0999CF54,
#endif
                      gUnk_02035120, gUnk_0203511C, 0,
                      0xC00, 3001);
        DrawSprite(112, gUnk_020354C8[1] >> 8,
#ifdef VERSION_EU
                      third,
#else
                      gUnk_0999CF88,
#endif
                      gUnk_02035120, gUnk_0203511C, 0,
                      0xC00, 3001);
    }

    prio = 0x400;

    if (gUnk_02035118 == 1) {
        prio |= 4;
    }

    if (gUnk_020354C0 == 2) {
        DrawSprite((s16)(gUnk_09EF8FAC[gUnk_020350F8].x * 8 + 22),
                      (s16)(gUnk_09EF8FAC[gUnk_020350F8].y * 8 + 12),
                      AnimUpdate(&gUnk_02035130), gUnk_02035128, gUnk_02035124, 0, prio, 2013);
        ApproachValueHalf(&gUnk_020354D8,
                      (gUnk_09EF8FAC[gUnk_020350F8].x << 11) + 0x2000);
        ApproachValueHalf(&gUnk_020354DC,
                      (gUnk_09EF8FAC[gUnk_020350F8].y << 11) + 0xFFFFFA00);
        DrawSprite(gUnk_020354D8 >> 8, gUnk_020354DC >> 8, AnimUpdate(&gUnk_02035150),
                      gUnk_0203514C, gUnk_02035148, 0, prio, 2000);
    }

    for (i = 0; i < 12; i++) {
        if (gUnk_020351C8[i] != 0 && gUnk_02035168[i] != 0) {
            DrawSprite((s16)(gUnk_09EF8FAC[i].x * 8 + 16), (s16)(gUnk_09EF8FAC[i].y * 8 + 16),
                          gUnk_020351C8[i], gUnk_02035198[i], gUnk_02035168[i], 0, prio,
                          (u16)(i + 2001));
        }
    }

    if (gUnk_020351C8[gUnk_020350F8] != 0) {
        DrawSprite(
#ifdef VERSION_EU
                      102,
#else
                      112,
#endif
                      32, gUnk_020351C8[gUnk_020350F8], gUnk_02035198[gUnk_020350F8],
                      gUnk_02035168[gUnk_020350F8], 0, 0, 0);
    }

    if (gUnk_020352B8 != 0) {
        DrawTextSlots(
#ifdef VERSION_EU
                      120,
#else
                      128,
#endif
                      28, gUnk_020351F8, gUnk_02035148, 1, gUnk_020352B8);
    }

    if (gUnk_02035118 == 1) {
        if (gUnk_020354A0 != 0) {
            DrawTextSlots(97, 56, gUnk_020352C0, gUnk_02035124, 0, gUnk_020354A0);
        }

        DrawSprite(47, (-gSineTable[gUnk_0203511A + 0x40] >> 5) + 84, gUnk_020354B8[0],
                      gUnk_020354B0[0], gUnk_020354A8[0], 0, 0, 1);
        DrawSprite(47, (-gSineTable[gUnk_0203511A + 0x40] >> 5) + 84, gUnk_020354B8[1],
                      gUnk_020354B0[1], gUnk_020354A8[1], 0, 0, 0);
    }
}

void mode_worldinspect_0(void) {
    s16 i;
    s32 floor;
    s16 id;
    void** p;
    u32 floorKeep;
    s16 fa;
    vu32* dma;

    p = &gUnk_020354D4;
    *p = EwramAlloc(0x500);
    SpriteReset();
    FadeStartIn(0, 16);
    SetBgMode0();
    SetupBg(0, 0, 0x1C, 0);
    SetupBg(1, 0, 0x1D, 0);
    SetupBg(2, 0, 0x1E, 0);
    SetupBg(3, 0, 0x1F, 0);
    SetBgPriority(0, 3);
    SetBgPriority(1, 2);
    SetBgPriority(2, 1);
    SetBgPriority(3, 0);
    floor = gGameState.floor;
    floorKeep = (u16)floor;
    gUnk_020350F8 = gGameState.floor > 11 ? 11 : floor;

    gUnk_020350FA = 0;

    for (i = 0; i <= 11; i++) {
        gUnk_02035100[i] = gGameState.floors[i].world;

        if (gUnk_02035100[i] != 0) {
            gUnk_020350FA = i + 1;
        }
    }

    for (i = 0, fa = gUnk_020350FA; i <= 13; i++) {
        if ((gGameState.unk_180 & gUnk_09EF909C[i].flags) != 0) {
            gUnk_02035100[fa++] = gUnk_09EF909C[i].world;

            if (fa > 11) {
                break;
            }
        }
    }

    gUnk_02035118 = 0;
    gUnk_0203511A = 0;
    gUnk_020354D8 = (gUnk_09EF8FAC[gUnk_020350F8].x << 11) + 0x2000;
    gUnk_020354DC = (gUnk_09EF8FAC[gUnk_020350F8].y << 11) - 0x600;
    gUnk_020354C0 = 0;
    gUnk_020354C2 = 16;
    gUnk_020354C8[0] = -0x800;
    gUnk_020354C8[1] = 0xA800;
    gUnk_020354D0 = -0x8000;
    LoadBgPalette(0, gUnk_09A3CE7C, 0x200);

    for (i = 0; i <= 11; i++) {
        if (gUnk_02035100[i] != 0) {
            id = gUnk_02035100[i];
            gUnk_02035168[i] = LoadObjPalette(gUnk_09EF909C[id].palette, gUnk_09EF909C[id].paletteSize);
            id = gUnk_02035100[i];
            gUnk_02035198[i] = LoadObjTiles(gUnk_09EF909C[id].tiles, gUnk_09EF909C[id].tilesSize);
            id = gUnk_02035100[i];
            gUnk_020351C8[i] = gUnk_09EF909C[id].sprite;
        } else {
            gUnk_02035168[i] = 0;
            gUnk_02035198[i] = 0;
            gUnk_020351C8[i] = 0;
        }
    }

    LoadBgTiles(0, gUnk_099FB53C, 0x6BC0);
#ifdef VERSION_EU
    if (gGameState.flags & 8) {
        switch (gLanguage) {
        case 1:
            RequestDma3Copy(gUnkEu_09A2D440, (u8*)GetBgCharBase(0) + 0x6400, 0x800);
            break;
        case 4:
            RequestDma3Copy(gUnkEu_09A2E440, (u8*)GetBgCharBase(0) + 0x6400, 0x800);
            break;
        case 3:
            RequestDma3Copy(gUnkEu_09A2F440, (u8*)GetBgCharBase(0) + 0x6400, 0x800);
            break;
        case 2:
            RequestDma3Copy(gUnkEu_09A30440, (u8*)GetBgCharBase(0) + 0x6400, 0x800);
            break;
        }
    } else {
        switch (gLanguage) {
        case 1:
            RequestDma3Copy(gUnkEu_09A2CC40, (u8*)GetBgCharBase(0) + 0x800, 0x800);
            break;
        case 4:
            RequestDma3Copy(gUnkEu_09A2DC40, (u8*)GetBgCharBase(0) + 0x800, 0x800);
            break;
        case 3:
            RequestDma3Copy(gUnkEu_09A2EC40, (u8*)GetBgCharBase(0) + 0x800, 0x800);
            break;
        case 2:
            RequestDma3Copy(gUnkEu_09A2FC40, (u8*)GetBgCharBase(0) + 0x800, 0x800);
            break;
        }
    }
#endif

    LoadBgMap(0, gUnk_09A324DC, 0x500);
    dma = (vu32*)0x040000D4;
    dma[0] = (u32)gUnk_09A32EDC;
    dma[1] = (u32)gUnk_020354D4;
    dma[2] = 0x80000280;
    dma[2];

    for (i = 0; i <= 11; i++) {
        if (gUnk_02035100[i] != 0) {
            func_080FF19C(7, 4, gUnk_09A333DC, 0, 0, gUnk_020354D4, gUnk_09EF8FAC[i].x, gUnk_09EF8FAC[i].y);
        }
    }

    for (i = 0; i < gUnk_020350FA - 1; i++) {
        if (gUnk_02035100[i] != 0 && gUnk_02035100[i + 1] != 0) {
            WorldinspectConn* conn = gUnk_099930BC;
            id = gUnk_09EF8FAC[i].rect;
            func_080FF19C(conn[id].unk_00, conn[id].unk_02, gUnk_09A333DC, conn[id].unk_04, conn[id].unk_06, gUnk_020354D4, gUnk_09EF8FAC[i].x2, gUnk_09EF8FAC[i].y2);
        }
    }

    for (i = 0; i < gUnk_020350FA; i++) {
        if (gUnk_02035100[i] != 0) {
            if ((gGameState.flags & 8) == 0) {
                if (i <= 8) {
                    func_080FF19C(3, 1, gUnk_09A333DC, i * 3, 9, gUnk_020354D4, gUnk_09EF8FAC[i].x + 3, gUnk_09EF8FAC[i].y + 2);
                } else {
                    func_080FF19C(4, 1, gUnk_09A333DC, (i - 9) * 4, 10, gUnk_020354D4, gUnk_09EF8FAC[i].x + 3, gUnk_09EF8FAC[i].y + 2);
                }
            } else {
                if (i <= 2) {
                    func_080FF19C(4, 1, gUnk_09A333DC, i * 4, 0x15, gUnk_020354D4, gUnk_09EF8FAC[i].x + 3, gUnk_09EF8FAC[i].y + 2);
                } else {
                    func_080FF19C(3, 1, gUnk_09A333DC, (i - 3) * 3, 0x16, gUnk_020354D4, gUnk_09EF8FAC[i].x + 3, gUnk_09EF8FAC[i].y + 2);
                }
            }
        }
    }

    for (i = 0; i < gUnk_020350FA; i++) {
        if ((s16)floorKeep == i) {
            func_080FF10C(3, 7, 4, gUnk_020354D4, gUnk_09EF8FAC[i].x, gUnk_09EF8FAC[i].y);
        } else {
            func_080FF10C(2, 7, 4, gUnk_020354D4, gUnk_09EF8FAC[i].x, gUnk_09EF8FAC[i].y);
        }
    }

    LoadBgMap(1, gUnk_020354D4, 0x500);
    LoadBgMap(2, gUnk_09A33E9C, 0x500);
    LoadBgMap(3, gUnk_09A3399C, 0x500);
    func_080FF2B8(gUnk_020350F8);
    gUnk_02035124 = LoadObjPalette(gUnk_09A3D09C, 0x20);
    gUnk_02035128 = LoadObjTiles(gUnk_0999D41A, 0x400);
    AnimInit(&gUnk_02035130, gUnk_09EF97C4, gUnk_09EF97B0);
    AnimStart(&gUnk_02035130, 0, 1);
    gUnk_02035148 = LoadObjPalette(gUnk_09A3D0BC, 0x20);
    gUnk_0203514C = LoadObjTiles(gUnk_0999D8A8, 0xC0);
    AnimInit(&gUnk_02035150, gUnk_09EF97DC, gUnk_09EF97CC);
    AnimStart(&gUnk_02035150, 0, 1);
#ifdef VERSION_EU
    InitTextSlots(gUnk_020351F8, 0x30);
#else
    InitTextSlots(gUnk_020351F8, 0x18);
#endif
    gUnk_020352B8 = func_080FF228(gUnk_02035100[gUnk_020350F8]);
#ifdef VERSION_EU
    InitTextSlots(gUnk_020352C0, 0x78);
#else
    InitTextSlots(gUnk_020352C0, 0x3C);
#endif
    gUnk_0203511C = LoadObjPalette(gUnk_09A3D07C, 0x20);
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        gUnk_02035120 = LoadObjTiles(gUnk_0999CFC6, 0x400);
        break;
    case 1:
        gUnk_02035120 = LoadObjTiles(gUnkEu_099A4CDA, 0x440);
        break;
    case 4:
        gUnk_02035120 = LoadObjTiles(gUnkEu_099A51AA, 0x400);
        break;
    case 3:
        gUnk_02035120 = LoadObjTiles(gUnkEu_099A563A, 0x400);
        break;
    case 2:
    default:
        gUnk_02035120 = LoadObjTiles(gUnkEu_099A5ACA, 0x440);
        break;
    }
#elif defined(VERSION_JP)
    gUnk_02035120 = LoadObjTiles(gUnk_0999CFC6, 0x3C0);
#else
    gUnk_02035120 = LoadObjTiles(gUnk_0999CFC6, 0x400);
#endif
    EnableBg(0);
    EnableBg(1);
    DisableBg(2);
    DisableBg(3);
}

void mode_worldinspect_1(void) {
    UpdatePlayTime();
    gUnk_0203511A += 2;

    switch (gUnk_020354C0) {
    case 0:
        ApproachValue(&gUnk_020354C8[0], 0, gUnk_020354C2);
        ApproachValue(&gUnk_020354C8[1], 0x9800, gUnk_020354C2);
        gUnk_020354C2--;
        if (gUnk_020354C2 <= 0) {
            gUnk_020354C2 = 16;
            gUnk_020354C0 = 1;
        }
        break;
    case 1:
        ApproachValue(&gUnk_020354D0, 0, gUnk_020354C2);
        gUnk_020354C2--;
        if (gUnk_020354C2 <= 0) {
#ifdef VERSION_EU
            LoadBgMap(0, gUnkEu_09A86E60, 0x500);
#else
            LoadBgMap(0, gUnk_09A329DC, 0x500);
            ReleaseObjPalette(gUnk_0203511C);
#endif
            gUnk_020354C0 = 2;
        }
        break;
    case 2:
        switch (gUnk_02035118) {
        case 0:
            func_080FF330();
            break;
        case 1:
            func_080FF794();
            break;
        }
        break;
    case 3:
        ApproachValue(&gUnk_020354D0, -0x8000, gUnk_020354C2);
        gUnk_020354C2--;
        if (gUnk_020354C2 <= 0) {
            gUnk_020354C2 = 16;
            gUnk_020354C0 = 4;
        }
        break;
    case 4:
        ApproachValue(&gUnk_020354C8[0], -0x800, gUnk_020354C2);
        ApproachValue(&gUnk_020354C8[1], 0xA800, gUnk_020354C2);
        gUnk_020354C2--;
        if (gUnk_020354C2 <= 0) {
            FadeStartOut(0, 16);
            gUnk_020354C0 = 5;
        }
        break;
    case 5:
        if (!FadeIsActive()) {
            func_080E052C(gUnk_020354E0);
        }
        break;
    }

    func_080FF8CC();
}

void mode_worldinspect_2(void) {
    s32 i;

    ReleaseObjPalette(gUnk_0203511C);
    ReleaseObjTiles(gUnk_02035120);
    ReleaseObjPalette(gUnk_02035124);
    ReleaseObjTiles(gUnk_02035128);
    ReleaseObjPalette(gUnk_02035148);
    ReleaseObjTiles(gUnk_0203514C);

    for (i = 0; i < 12; i++) {
        if (gUnk_02035168[i]) {
            ReleaseObjPalette(gUnk_02035168[i]);
        }

        if (gUnk_02035198[i]) {
            ReleaseObjTiles(gUnk_02035198[i]);
        }
    }

#ifdef VERSION_EU
    FreeTextSlots(gUnk_020351F8, 0x30);
#else
    FreeTextSlots(gUnk_020351F8, 0x18);
#endif
#ifdef VERSION_EU
    FreeTextSlots(gUnk_020352C0, 0x78);
#else
    FreeTextSlots(gUnk_020352C0, 0x3C);
#endif
    EwramFree(gUnk_020354D4);
}

const char gModeNameWorldinspect[] = "mode_worldinspect";

Mode gModeWorldinspect = {
    gModeNameWorldinspect,
    (void (*)(s32))mode_worldinspect_0,
    (void (*)(void))mode_worldinspect_1,
    (void (*)(void))mode_worldinspect_2,
};
