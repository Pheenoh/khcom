#include "macros.h"
#include "card_localized_data.h"
#include "card_label_sprite_data.h"
#include "card_reload_sprite_data.h"
#include "card_sprite_data.h"
#include "msg_localized_data.h"
#include "registration_data.h"
#include "system_state.h"
#include "map_api.h"
#include "msg_api.h"
#include "mode_sio_api.h"
#include "card_battle.h"
#include "mode_test_api.h"
#include "player_progression.h"
#include "m4a_song.h"
#include "game_state.h"
#include <string.h>
#include "text.h"
#include "monsgage.h"
#include "fade.h"
#include "btl_collision.h"
#include "obj_api.h"
#include "battle_actor.h"
#include "display.h"
#include "engine_math.h"
#include "listpool.h"
#include "anim.h"
#include "obj.h"
#include "text_types.h"
#include "taskpool.h"
#include "key.h"
#include "gba/syscall.h"
#include "malloc.h"
#include "card.h"
#include "card_reload_assets.h"
#include "map_card_assets.h"
#include "card_localized_assets.h"
#include "card_help_assets.h"
#include "card_message_assets.h"
#include "card_description_assets.h"
#include <stddef.h>
#include "game.h"
#include "bos4_api.h"
#include "sprites_number_plus.h"
#include "battle_backgrounds.h"

u8 gUnk_02034AE0[20];
#ifndef VERSION_EU
u8 gUnk_02034AF4[4];
#endif

#ifdef VERSION_EU
extern void** gUnkEu_09F72CC4[];
extern void* gUnkEu_09F72CB0[];
extern u8 gUnkEu_09F72D80[];

#define LANGSTR(x) (((void**)(x))[gLanguage])
#else
#define LANGSTR(x) (x)
#endif
u8 HCEffectName_1(HcEffectNameWork* w, void* a);
u8 func_0809DE30(HcEffectNameWork* w, void* a);
u16 func_080792D0(u16* p);
void func_08085C3C(void);
void func_08085FB0(void);

void Mode_Premire_0(void) {
    func_08085FB0();
    func_08085C3C();
    SetBgMode2();
    SetupBg(3, 0, 12, 0);
    SetupBg(2, 2, 28, 10);
    SetBgSize(3, 0x8000);
#ifdef VERSION_EU
    LoadBgTiles(3, gUnk_08C8C824, 0x4000);
    LoadBgPalette(3, gUnk_08F68A84, 0x100);
    eu_080059F4(3, gUnk_08EF4384);
#else
    LoadBgTiles(3, gUnk_08C8C824, 0x4000);
    LoadBgPalette(3, gUnk_08F68A84, 0x100);
    LoadBgMap(3, gUnk_08EF4384, 0x1000);
#endif
    SetBgAffine(3, 0, 0x100, 0x100, 0x10000, 0x16800);
    TaskPoolInit(gUnk_02034AE0, 1);
#ifdef VERSION_EU
    TaskCreate(gUnk_02034AE0, gUnkEu_09F72D80, 0);
#else
    TaskCreate(gUnk_02034AE0, &gTaskDescLevelUp, 0);
#endif
}

void Mode_Premire_1(void) {
    TaskPoolUpdate(gUnk_02034AE0);
    TaskPoolDraw(gUnk_02034AE0);
}
void Mode_Premire_2(void) {
    TaskPoolDestroy(gUnk_02034AE0);
}
u8 func_0809DA64(s32 a, u16 n) {
    switch (n) {
    case 0:
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 16:
    case 17:
    case 19:
    case 20:
    case 21:
    case 24:
    case 25:
    case 29:
    case 30:
    case 31:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 42:
    case 51:
    case 53:
        return 6;
    case 41:
    case 45:
    case 50:
        return 2;
    case 18:
    case 46:
        return 3;
    case 15:
    case 28:
    case 47:
        return 5;
    case 23:
    case 26:
    case 27:
        return 4;
    case 48:
        return 1;
    }

    return 0;
}
void HCEffectName_0(HcEffectNameWork* w, u8* a) {
    void** tiles;

    w->unk_19 = a[0];
    w->timer = 0;
    w->unk_1C = 32;
    w->palette = LoadObjPalette(gUnk_08F69BA4, 32);
    w->tiles2 = AllocSpriteFrameTiles(0x3C0);
    w->tiles3 = AllocSpriteFrameTiles(32);
    w->unk_20 = 0;
    w->unk_27 = 1;

    switch (w->unk_19) {
    case 1:
        w->x = 48;
        w->unk_1E = gUnk_02039DD4->unk_0CC;
#ifdef VERSION_EU
        w->unk_26 = func_0809DA64((s32)w, gUnk_02039DD4->unk_0CC);
#endif
        tiles = LANGSTR(gUnk_08F7CBA8[gUnk_02039DD4->unk_0CC].unk_08);
        UpdateSpriteFrameTiles(w->tiles2, tiles[gUnk_08F7CBA8[gUnk_02039DD4->unk_0CC].unk_0C], LANGSTR(gUnk_08F7CBA8[gUnk_02039DD4->unk_0CC].unk_00));
#ifdef VERSION_EU
        UpdateSpriteFrameTiles(w->tiles3, gUnkEu_09F72CC4[gLanguage][w->unk_26], gUnkEu_09F72CB0[gLanguage]);
#else
        w->unk_26 = func_0809DA64((s32)w, gUnk_02039DD4->unk_0CC);
        UpdateSpriteFrameTiles(w->tiles3, gUnk_09EF12C8[w->unk_26], gUnk_093FB954);
#endif

        if (gUnk_02039DD4->unk_0CC == 0) {
            w->unk_27 = 0;
        }
        break;
    case 2:
        w->x = 162;
        w->unk_1E = gUnk_02039DD4->unk_0CE;
#ifdef VERSION_EU
        w->unk_26 = func_0809DA64((s32)w, gUnk_02039DD4->unk_0CE);
#endif
        tiles = LANGSTR(gUnk_08F7CBA8[gUnk_02039DD4->unk_0CE].unk_08);
        UpdateSpriteFrameTiles(w->tiles2, tiles[gUnk_08F7CBA8[gUnk_02039DD4->unk_0CE].unk_0C], LANGSTR(gUnk_08F7CBA8[gUnk_02039DD4->unk_0CE].unk_00));
#ifdef VERSION_EU
        UpdateSpriteFrameTiles(w->tiles3, gUnkEu_09F72CC4[gLanguage][w->unk_26], gUnkEu_09F72CB0[gLanguage]);
#else
        w->unk_26 = func_0809DA64((s32)w, gUnk_02039DD4->unk_0CE);
        UpdateSpriteFrameTiles(w->tiles3, gUnk_09EF12C8[w->unk_26], gUnk_093FB954);
#endif

        if (gUnk_02039DD4->unk_0CE == 0) {
            w->unk_27 = 0;
        }
        break;
    }

    w->tiles = LoadObjTiles(gUnk_08B25ADE, 0x360);
    w->unk_22 = 0;
    w->unk_23 = 0;
    w->unk_24 = 0;
    w->unk_25 = 0;
}
u8 HCEffectName_1(HcEffectNameWork* w, void* a) {
    u8 done;
    s32 div;
    UnkStruct_02039DD4* d;

    done = func_0809DE18((u8*)w);

    if (done != 0) {
#ifdef VERSION_EU
        func_0806BA0C((s16)gBtlWork->unk_0F8, &w->unk_22);
#endif
        SetTaskUpdate(a, (void*)func_0809DE30);
        return 1;
    }

    switch (w->unk_19) {
    case 1:
        div = gUnk_08F7CBA8[gBtlWork->unk_0F4].unk_0E << 8;
        w->unk_1C = (u32)(((s16)gBtlWork->unk_0F8 << 16) / div) >> 3;
        d = gUnk_02039DD4;

        if (d->unk_0CC == 0) {
            d->unk_0EB = 0;
            return 0;
        }

        if (d->unk_0CC != w->unk_1E) {
            d->unk_0EB = 0;
            return 0;
        }

        if (d->unk_0EB == 1) {
            d->unk_0EB = 0;
            return 0;
        }

        if ((s16)gBtlWork->unk_0F8 <= 0) {
            d->unk_0CC = 0;
            gBtlWork->unk_0F4 = 0;
            d->unk_0EB = 0;
            return 0;
        }

        func_0806BA0C((s16)gBtlWork->unk_0F8, &w->unk_22);
        break;
    case 2:
        div = gUnk_08F7CBA8[gUnk_02039B9C->unk_0F4].unk_0E << 8;
        w->unk_1C = (u32)(((s16)gUnk_02039B9C->unk_0F8 << 16) / div) >> 3;
        d = gUnk_02039DD4;

        if (d->unk_0CE == 0) {
            d->unk_0EC = 0;
            return 0;
        }

        if (d->unk_0CE != w->unk_1E) {
            d->unk_0EC = 0;
            return 0;
        }

        if (d->unk_0EC == 1) {
            d->unk_0EC = 0;
            return 0;
        }

        if ((s16)gUnk_02039B9C->unk_0F8 <= 0) {
            d->unk_0CE = 0;
            gUnk_02039B9C->unk_0F4 = 0;
            d->unk_0EC = 0;
            return 0;
        }

        func_0806BA0C((s16)gUnk_02039B9C->unk_0F8, &w->unk_22);
        break;
    }

    w->timer++;

    if ((s16)w->unk_1C <= 2) {
        w->unk_1C = 2;
    }

    if ((s16)w->timer >= (s16)w->unk_1C) {
        w->unk_27 ^= 1;
        w->timer = 0;
    }

    return 1;
}
u8 func_0809DE18(u8* p) {
    if (p[25] != 1) {
        if (p[25] != 2) {
            return 0;
        }
    }

    if (*(u16*)&p[30] != 37) {
        return 0;
    }

    return 1;
}
u8 func_0809DE30(HcEffectNameWork* w, void* a) {
    void** tiles;

    switch (w->unk_19) {
    case 1:
        if (gUnk_02039DD4->unk_0CC != 37) {
            w->unk_1E = gUnk_02039DD4->unk_0CC;
            if (gUnk_02039DD4->unk_0CC == 0) {
                gUnk_02039DD4->unk_0EB = 0;
                return 0;
            }
#ifdef VERSION_EU
            w->unk_26 = func_0809DA64((s32)w, gUnk_02039DD4->unk_0CC);
#endif
            tiles = LANGSTR(gUnk_08F7CBA8[gUnk_02039DD4->unk_0CC].unk_08);
            UpdateSpriteFrameTiles(w->tiles2, tiles[gUnk_08F7CBA8[gUnk_02039DD4->unk_0CC].unk_0C],
                         LANGSTR(gUnk_08F7CBA8[gUnk_02039DD4->unk_0CC].unk_00));
#ifdef VERSION_EU
            UpdateSpriteFrameTiles(w->tiles3, gUnkEu_09F72CC4[gLanguage][w->unk_26],
                         gUnkEu_09F72CB0[gLanguage]);
#else
            w->unk_26 = func_0809DA64((s32)w, gUnk_02039DD4->unk_0CC);
            UpdateSpriteFrameTiles(w->tiles3, gUnk_09EF12C8[w->unk_26], gUnk_093FB954);
#endif
            SetTaskUpdate(a, (void*)HCEffectName_1);
        } else {
            u16 id = func_080792D0(&w->unk_20);
            w->unk_1E = id;
            tiles = LANGSTR(gUnk_08F7CBA8[id].unk_08);
            UpdateSpriteFrameTiles(w->tiles2, tiles[gUnk_08F7CBA8[id].unk_0C],
                         LANGSTR(gUnk_08F7CBA8[id].unk_00));
        }
        break;
    case 2:
        if (gUnk_02039DD4->unk_0CE != 37) {
            w->unk_1E = gUnk_02039DD4->unk_0CE;
            if (gUnk_02039DD4->unk_0CE == 0) {
                gUnk_02039DD4->unk_0EB = 0;
                return 0;
            }
#ifdef VERSION_EU
            w->unk_26 = func_0809DA64((s32)w, gUnk_02039DD4->unk_0CE);
#endif
            tiles = LANGSTR(gUnk_08F7CBA8[gUnk_02039DD4->unk_0CE].unk_08);
            UpdateSpriteFrameTiles(w->tiles2, tiles[gUnk_08F7CBA8[gUnk_02039DD4->unk_0CE].unk_0C],
                         LANGSTR(gUnk_08F7CBA8[gUnk_02039DD4->unk_0CE].unk_00));
#ifdef VERSION_EU
            UpdateSpriteFrameTiles(w->tiles3, gUnkEu_09F72CC4[gLanguage][w->unk_26],
                         gUnkEu_09F72CB0[gLanguage]);
#else
            w->unk_26 = func_0809DA64((s32)w, gUnk_02039DD4->unk_0CE);
            UpdateSpriteFrameTiles(w->tiles3, gUnk_09EF12C8[w->unk_26], gUnk_093FB954);
#endif
            SetTaskUpdate(a, (void*)HCEffectName_1);
        } else {
            u16 id = func_080792D0(&w->unk_20);
            w->unk_1E = id;
            tiles = LANGSTR(gUnk_08F7CBA8[id].unk_08);
            UpdateSpriteFrameTiles(w->tiles2, tiles[gUnk_08F7CBA8[id].unk_0C],
                         LANGSTR(gUnk_08F7CBA8[id].unk_00));
        }
        break;
    }
    return 1;
}

void HCEffectName_2(HcEffectNameWork* w) {
#ifdef VERSION_EU
    s32 pri;

    if (w->unk_27 == 1) {
        pri = 0x410;
        DrawSprite(w->x, 0x90, 0, w->tiles2, w->palette, 0, pri, 10);
        DrawSprite(w->x, 0x8A, gUnk_09EE1538[15], w->tiles, w->palette, 0, pri, 10);
        DrawSprite(w->x + 8, 0x8A, gUnk_09EE1538[w->unk_24 + 4], w->tiles, w->palette, 0, pri, 10);
        DrawSprite(w->x + 16, 0x8A, gUnk_09EE1538[w->unk_25 + 4], w->tiles, w->palette, 0, pri, 10);
        DrawSprite(w->x + 24, 0x8A, 0, w->tiles3, w->palette, 0, pri, 10);
        DrawSprite(w->x + 32, 0x8A, gUnk_09EE1538[14], w->tiles, w->palette, 0, pri, 10);
    }
#else
    if (w->unk_27 == 1) {
        DrawSprite(w->x, 0x90, 0, w->tiles2, w->palette, 0, 0x400, 10);
        DrawSprite(w->x, 0x8A, gUnk_09EE1538[15], w->tiles, w->palette, 0, 0x400, 10);
        DrawSprite(w->x + 8, 0x8A, gUnk_09EE1538[w->unk_24 + 4], w->tiles, w->palette, 0, 0x400, 10);
        DrawSprite(w->x + 16, 0x8A, gUnk_09EE1538[w->unk_25 + 4], w->tiles, w->palette, 0, 0x400, 10);
        DrawSprite(w->x + 24, 0x8A, 0, w->tiles3, w->palette, 0, 0x400, 10);
        DrawSprite(w->x + 32, 0x8A, gUnk_09EE1538[14], w->tiles, w->palette, 0, 0x400, 10);
    }
#endif
}

void HCEffectName_3(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x08]);
    ReleaseObjTiles(*(void**)&work[0x14]);
    ReleaseObjTiles(*(void**)&work[0x0C]);
    ReleaseObjPalette(*(void**)&work[0x10]);
    gUnk_02039DD4->unk_0D8 = 0;
    gUnk_02039DD4->unk_0E5 = 0;
    gUnk_02039DD4->unk_0C8 = 256;
}

void NumberPlus_0(NumberPlusWork* w, NumberPlusArgs* args) {
    w->args = *args;
    w->tiles = LoadObjTiles(gUnk_090451C0, 128);
    w->palette = LoadObjPalette(gUnk_08F69BA4, 32);
    w->unk_24 = w->args.unk_04 >> 8;
    w->unk_26 = (w->args.unk_08 >> 8) - 20;
    w->unk_28 = 16;
    w->unk_29 = 0;
}

s32 NumberPlus_1(u8* work) {
    s32 v;

    v = *(s16*)&work[0x26] << 8;

    if (work[0x28] != 0) {
        ApproachValue(&v, *(s32*)&work[0x10] - 0x2800, work[0x28]);
        *(s16*)&work[0x26] = v >> 8;
        work[0x28]--;
        return 1;
    }

    return 0;
}
void NumberPlus_2(u8* work) {
    DrawSprite(*(s16*)&work[0x24], *(s16*)&work[0x26], gUnk_09EE91A8[0],
               *(void**)&work[0x00], *(void**)&work[0x04], 0, 16, 0);
}
void NumberPlus_3(void** p) {
    ReleaseObjTiles(p[0]);
    ReleaseObjPalette(p[1]);
}

Mode gUnk_09EE7894 = {
    gUnk_09037F80,
    (void (*)(s32))Mode_Premire_0,
    Mode_Premire_1,
    Mode_Premire_2,
};
#ifdef VERSION_EU
void* gUnkEu_09F72CB0[5] = { gUnk_093FB954, gUnkEu_094CE490, gUnkEu_094CE820, gUnkEu_094CE6F0, gUnkEu_094CE5C0 };

void** gUnkEu_09F72CC4[5] = { gUnk_09EF12C8, gUnkEu_09F7C55C, gUnkEu_09F7C57C, gUnkEu_09F7C59C, gUnkEu_09F7C5BC };
#endif

const char gTaskNameHCEffectName[] = "HCEffectName";

TaskDesc gTaskDescHCEffectName = {
    gTaskNameHCEffectName,
    (void (*)(void*, void*))HCEffectName_0,
    HCEffectName_1,
    (void (*)(void*))HCEffectName_2,
    (void (*)(void*))HCEffectName_3,
    0x28,
};

const char gTaskNameNumberPlus[] = "NumberPlus";

TaskDesc gTaskDescNumberPlus = {
    gTaskNameNumberPlus,
    (void (*)(void*, void*))NumberPlus_0,
    NumberPlus_1,
    (void (*)(void*))NumberPlus_2,
    (void (*)(void*))NumberPlus_3,
    0x2C,
};
