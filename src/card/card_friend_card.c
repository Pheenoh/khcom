#include "macros.h"
#include "card_localized_data.h"
#include "card_label_sprite_data.h"
#include "card_lookup_09EEA344_data.h"
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
#include "sprites_btl.h"
#include "sprites_card.h"
#include "sprites_premire_chance.h"

struct CardListWork* gUnk_0203A9D0 EWRAM_COMMON(4);

#ifdef VERSION_EU
extern void** gUnkEu_09F72BFC[5];
#endif
extern u8 gUnk_09618CD8[];
extern u8 gUnk_093F4578[];
extern u8 gUnk_0908BB80[];
extern u8 gUnk_09613E98[];
extern u8 gUnk_0908BFB2[];
extern u8 gUnk_09618D18[];
#ifdef VERSION_EU
extern u8 gUnkEu_0916292A[];
extern u8 gUnkEu_091633A4[];
extern u8 gUnkEu_09162FB8[];
extern u8 gUnkEu_09162C8C[];

#define LANGSTR(x) (((void**)(x))[gLanguage])
#else
#define LANGSTR(x) (x)
#endif
void CreateCardNameDisplay(void* a, void* b);
u8 func_0809BE80(u8* work, void* a);
void ConvertActiveDeckCardToPremium(u16 index);
s16 func_08084458(u16 cardId);
void ConvertActiveDeckCardToPremium(u16 index);
Deck* GetActiveDeck(void);
void CreateCardNameDisplay(void* a, void* b);

void Friend_card_0(UnkStruct_0809A02C* w, s32* args) {
    u8* p;

    w->cardId = args[3];
    w->unk_38 = args[0];
    w->unk_3C = args[1];
    w->unk_40 = args[2];
    w->unk_44 = 0;
    w->unk_1C6 = GetRandom();
    w->unk_1A4 = -(GetRandom() % 129 + 0x300);
    w->unk_1A8 = GetRandom() % 129 + 0x80;
    w->unk_1C7 = 0;
    w->unk_1C8 = 0;
    w->unk_1C9 = 24;
    w->unk_1B8 = 0x80;
    w->unk_1BA = 0x80;
    w->unk_1BC = 0x80;
    w->unk_1CA = 0;
    w->unk_1CB = 0;
    w->unk_1CC = 0;
    w->unk_1C4 = 0;
    w->unk_1CD = 1;
    w->cardDef = &gCardDefs[args[3]];

    if (w->cardDef->unk_1E & 8) {
        w->unk_1CE = 3;
    } else {
        w->unk_1CE = w->cardDef->unk_2A;
    }

    w->palette = LoadObjPalette(gUnk_09611AB8, 32);
    w->tiles3 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    w->tiles2 = LoadObjTiles(w->cardDef->tiles, 0x300);
    w->palette2 = LoadObjPalette(w->cardDef->palette, 32);
    w->tiles4 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->palette3 = LoadObjPalette(gUnk_08F69BA4, 32);
    p = w->unk_144;
    ColliderInit(p, 5, 8, 10);
    ColliderSetPosition(p, w->unk_38, w->unk_3C, w->unk_40);
    TaskPoolInit(&w->tasks, 1);
    gBtlWork->unk_0B0++;
}

void Heartless_card_0(UnkStruct_0809A02C* w, s32* args) {
    u8* p;

    w->cardId = args[3];
    w->unk_38 = args[0];
    w->unk_3C = args[1];
    w->unk_40 = args[2];
    w->unk_44 = 0;
    w->unk_1C6 = GetRandom();
    w->unk_1A4 = -(GetRandom() % 129 + 0x300);
    w->unk_1A8 = GetRandom() % 129 + 0x80;
    w->unk_1C7 = 0;
    w->unk_1C8 = 0;
    w->unk_1C9 = 24;
    w->unk_1B8 = 0x80;
    w->unk_1BA = 0x80;
    w->unk_1BC = 0x80;
    w->unk_1CA = 0;
    w->unk_1CB = 0;
    w->unk_1CC = 0;
    w->unk_1C4 = 0;
    w->unk_1CD = 1;
    w->cardDef = &gCardDefs[args[3]];

    if (w->cardDef->unk_1E & 8) {
        w->unk_1CE = 3;
    } else {
        w->unk_1CE = w->cardDef->unk_2A;
    }

    w->tiles = LoadObjTiles(gUnk_08F709B0[w->unk_1CE].tiles, 0x280);
    w->palette = LoadObjPalette(gUnk_09611AB8, 32);
    w->tiles3 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    w->tiles2 = LoadObjTiles(w->cardDef->tiles, 0x300);
    w->palette2 = LoadObjPalette(w->cardDef->palette, 32);
    w->tiles4 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->palette3 = LoadObjPalette(gUnk_08F69BA4, 32);
    p = w->unk_144;
    ColliderInit(p, 5, 8, 10);
    ColliderSetPosition(p, w->unk_38, w->unk_3C, w->unk_40);
    TaskPoolInit(&w->tasks, 1);
    gBtlWork->unk_0B0++;
}

void Gimmick_card_0(UnkStruct_0809A02C* w, GimmickCardArgs* args) {
    u8* p;

    w->cardId = args->unk_0C;
    w->unk_38 = args->unk_00;
    w->unk_3C = args->unk_04;
    w->unk_40 = args->unk_08;
    w->unk_44 = 0;
    w->unk_1C6 = GetRandom();
    w->unk_1A4 = -((u16)(GetRandom() % 129) + 0x300);
    w->unk_1A8 = (u16)(GetRandom() % 129) + 0x80;
    w->unk_1C7 = 0;
    w->unk_1C8 = 0;
    w->unk_1C9 = 24;
    w->unk_1B8 = 0x80;
    w->unk_1BA = 0x80;
    w->unk_1BC = 0x80;
    w->unk_1CA = 0;
    w->unk_1CB = 0;
    w->unk_1CC = 0;
    w->unk_1C4 = 0;
    w->unk_1CD = 1;
    w->cardDef = &gCardDefs[args->unk_0C];
    w->unk_1CE = w->cardDef->unk_2A;
    w->palette = LoadObjPalette(gUnk_09611AB8, 32);
    w->tiles3 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    w->tiles2 = LoadObjTiles(w->cardDef->tiles, 0x300);
    w->palette2 = LoadObjPalette(w->cardDef->palette, 32);
    w->tiles4 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->palette3 = LoadObjPalette(gUnk_08F69BA4, 32);
    p = w->unk_144;
    ColliderInit(p, 5, 8, 10);
    ColliderSetPosition(p, w->unk_38, w->unk_3C, w->unk_40);
    TaskPoolInit(&w->tasks, 1);
    gBtlWork->unk_0B0++;
}

void func_0809A4E0(UnkStruct_0809A02C* w, u8 kind) {
    s32 dx;
    s32 dy;
    s32 tx;
    s32 ty;

    if (kind == 1) {
        tx = 0x7800;
        ty = 0x5000;
    } else {
        tx = 0;
        ty = 0xA000;
    }

    dx = tx - w->unk_38;
    dy = ty - w->unk_3C;
    w->unk_1AC = NormalizeVector2D8(&dx, &dy);
    w->unk_1B0 = -dx;
    w->unk_1B4 = -dy;
    w->unk_1A8 = 0x300;
    w->unk_1A4 = 2;
}

s32 Friend_card_1(UnkStruct_0809A02C* w, void* a) {
    s16 sx;
    s32 t;
    u16 n;
    s16 sy;

    if (gBtlWork->unk_0A0 == 4) {
        return 0;
    }

    w->unk_1A4 += gBtlWork->unk_12C;
    w->unk_40 += w->unk_1A4;
    w->unk_38 += (gSineTable[w->unk_1C6] * w->unk_1A8) >> 8;
    w->unk_3C += (-gSineTable[w->unk_1C6 + 64] * w->unk_1A8) >> 8;

    if (ClampBattlePosition(&w->unk_38, &w->unk_3C, -10, -10) != 0) {
        w->unk_1C6 = (u8)(w->unk_1C6 + 112) + GetRandom() % 33;
    }

    if (w->unk_40 - 0x800 > w->unk_44) {
        w->unk_40 = w->unk_44 - 0x800;
        w->unk_1A4 = -((204 * w->unk_1A4) >> 8);
        w->unk_1C6 = GetAngle(w->unk_38, w->unk_3C,
                               gBtlWork->actor->x,
                               gBtlWork->actor->y);
        w->unk_1C6 = (u8)(w->unk_1C6 + 224) + GetRandom() % 65;

        if (w->unk_1A4 > -0x200) {
            w->unk_1A4 = -0x200;
        }
    }

    if (gBtlWork->unk_0F4 == 6) {
        ColliderSetRadius(w->unk_144, 50);
    } else {
        ColliderSetRadius(w->unk_144, 10);
    }

    if ((u8)func_0801C6D4(&w->unk_38, &w->unk_3C, &w->unk_40,
                          &w->unk_44) != 0) {
        w->unk_1C6 = (u8)(w->unk_1C6 + 112) + GetRandom() % 33;
    }

    if (w->unk_170 != 0) {
        m4aSongNumStart(106);
#ifdef VERSION_EU
        w->unk_1C2 = 10;
#endif

        if (gUnk_02039DD4 != 0) {
            WorldToScreen(&sx, &sy, w->unk_38, w->unk_3C,
                          w->unk_40);
            w->unk_38 = sx << 8;
            w->unk_3C = sy << 8;
            w->unk_1CA = 1;
            ColliderSetDisabled(w->unk_144, 1);
            func_0809A4E0(w, 0);
#ifdef VERSION_EU
            w->unk_1CD = 1;
#endif
            SetTaskUpdate(a, (u32)func_0809AB2C);
        }

        return 1;
    }

    ColliderSetPosition(w->unk_144, w->unk_38, w->unk_3C,
                  w->unk_40);
    w->unk_1B8 =
        (-gSineTable[((w->unk_1C7 + 128) & 0xFF) + 64] *
         w->unk_1BC) >> 8;
    w->unk_1BA =
        (-gSineTable[((w->unk_1C8 + 128) & 0xFF) + 64] *
         w->unk_1BC) >> 8;

    if ((u16)(w->unk_1B8 + 2) <= 4) {
        w->unk_1B8 = 2;
    }

    if ((u16)(w->unk_1BA + 2) <= 4) {
        w->unk_1BA = 2;
    }

    w->unk_1C7 += 2;
    w->unk_1C2 = -0x1004 - (w->unk_3C >> 8) * 4;
    TaskPoolUpdate(&w->tasks);

    if (gBtlWork->unk_068 & 0x800000000) {
        return 1;
    }

    n = w->unk_1C4;

    if (n > 359) {
        return 0;
    }

    t = n + 1;
    w->unk_1C4 = t;

    if (w->unk_1C4 > 279 && t % 4 == 0) {
        w->unk_1CD ^= 1;
    }

    return 1;
}
s32 Gimmick_card_1(UnkStruct_0809A02C* w, void* a) {
    s16 sx;
    s32 t;
    u16 n;
    s16 sy;

    if (gBtlWork->unk_0A0 == 4) {
        return 0;
    }

    w->unk_1A4 += 56;
    w->unk_40 += w->unk_1A4;
    w->unk_38 += (gSineTable[w->unk_1C6] * w->unk_1A8) >> 8;
    w->unk_3C += (-gSineTable[w->unk_1C6 + 64] * w->unk_1A8) >> 8;

    if (ClampBattlePosition(&w->unk_38, &w->unk_3C, -10, -10) != 0) {
        w->unk_1C6 = (u8)(w->unk_1C6 + 112) + GetRandom() % 33;
    }

    if (w->unk_40 - 0x800 > w->unk_44) {
        w->unk_40 = w->unk_44 - 0x800;
        w->unk_1A4 = -((204 * w->unk_1A4) >> 8);
        w->unk_1C6 = GetAngle(w->unk_38, w->unk_3C,
                               gBtlWork->actor->x,
                               gBtlWork->actor->y);
        w->unk_1C6 = (u8)(w->unk_1C6 + 224) + GetRandom() % 65;

        if (w->unk_1A4 > -0x200) {
            w->unk_1A4 = -0x200;
        }
    }

    if (gBtlWork->unk_0F4 == 6) {
        ColliderSetRadius(w->unk_144, 50);
    } else {
        ColliderSetRadius(w->unk_144, 10);
    }

    if ((u8)func_0801C6D4(&w->unk_38, &w->unk_3C, &w->unk_40,
                          &w->unk_44) != 0) {
        w->unk_1C6 = (u8)(w->unk_1C6 + 112) + GetRandom() % 33;
    }

    if (w->unk_170 != 0) {
        m4aSongNumStart(106);
#ifdef VERSION_EU
        w->unk_1C2 = 10;
#endif

        if (gUnk_02039DD4 != 0) {
            WorldToScreen(&sx, &sy, w->unk_38, w->unk_3C,
                          w->unk_40);
            w->unk_38 = sx << 8;
            w->unk_3C = sy << 8;
            w->unk_1CA = 1;
            ColliderSetDisabled(w->unk_144, 1);
            func_0809A4E0(w, 0);
#ifdef VERSION_EU
            w->unk_1CD = 1;
#endif
            SetTaskUpdate(a, (u32)func_0809AB2C);
        }

        return 1;
    }

    ColliderSetPosition(w->unk_144, w->unk_38, w->unk_3C,
                  w->unk_40);
    w->unk_1B8 =
        (-gSineTable[((w->unk_1C7 + 128) & 0xFF) + 64] *
         w->unk_1BC) >> 8;
    w->unk_1BA =
        (-gSineTable[((w->unk_1C8 + 128) & 0xFF) + 64] *
         w->unk_1BC) >> 8;

    if ((u16)(w->unk_1B8 + 2) <= 4) {
        w->unk_1B8 = 2;
    }

    if ((u16)(w->unk_1BA + 2) <= 4) {
        w->unk_1BA = 2;
    }

    w->unk_1C7 += 2;
    w->unk_1C2 = -0x1004 - (w->unk_3C >> 8) * 4;
    TaskPoolUpdate(&w->tasks);

    n = w->unk_1C4;

    if (n > 359) {
        *(u8*)&gUnk_02039DD4->unk_0DC -= 1;
        return 0;
    }

    t = n + 1;
    w->unk_1C4 = t;

    if (w->unk_1C4 > 279 && t % 4 == 0) {
        w->unk_1CD ^= 1;
    }

    return 1;
}
u8 func_0809AB2C(UnkStruct_0809A02C* w) {
    s32 dx;
    s32 dy;
    u16 t;

    if (gBtlWork->unk_0A0 == 4) {
        return 0;
    }

    if (w->unk_1A8 < 0) {
        dx = -w->unk_38;
        dy = 0xA000 - w->unk_3C;
        NormalizeVector2D8(&dx, &dy);
        w->unk_1B0 = -dx;
        w->unk_1B4 = -dy;

        if (w->unk_1AC < 0x800) {
            if (w->cardId >= 655 && w->cardId <= 659) {
                gUnk_02039DD4->unk_0BC = w->cardId;
            } else {
                gUnk_02039DD4->unk_0B8 = w->cardId;
            }

            return 0;
        }
    }

    w->unk_38 += (w->unk_1B0 * w->unk_1A8) >> 8;
    w->unk_3C += (w->unk_1B4 * w->unk_1A8) >> 8;
    w->unk_1C9 += 32;
    w->unk_1C8 += (64 - w->unk_1C8) >> 4;
    w->unk_1C7 = 0;
    w->unk_1AC = VectorLength2D(-w->unk_38, 0xA000 - w->unk_3C);
    w->unk_1A8 -= w->unk_1A4;
    w->unk_1A4 += 2;
    t = w->unk_1BC;

    if ((s16)t <= 255) {
        w->unk_1BC = t + 3;
    }

    w->unk_1B8 = (-gSineTable[((w->unk_1C7 + 128) & 0xFF) + 64] * w->unk_1BC) >> 8;
    w->unk_1BA = (-gSineTable[((w->unk_1C8 + 128) & 0xFF) + 64] * w->unk_1BC) >> 8;

    if ((u16)(w->unk_1B8 + 2) <= 4) {
        w->unk_1B8 = 2;
    }

    if ((u16)(w->unk_1BA + 2) <= 4) {
        w->unk_1BA = 2;
    }

    TaskPoolUpdate(&w->tasks);
    return 1;
}

u8 func_0809ACDC(UnkStruct_0809A02C* w) {
    s16 x;
    s16 y;

    w->unk_1C9 += 32;
    WorldToScreen(&x, &y, gBtlWork->actor->x, gBtlWork->actor->y, gBtlWork->actor->z);
    w->unk_38 += ((x << 8) - w->unk_38) >> 3;
    w->unk_3C += ((y << 8) - w->unk_3C) >> 3;
    w->unk_1B8 -= 10;
    w->unk_1BA -= 10;

    if (w->unk_1B8 <= 10) {
        return 0;
    }

    return 1;
}

s32 func_0809AD60(UnkStruct_0809A02C* w, void* a) {
    w->unk_1C4 += 1;

    if (w->unk_1C4 == 60) {
        SetTaskUpdate(a, func_0809ACDC);
    }

    TaskPoolUpdate(&w->tasks);
    return 1;
}
s32 func_0809AD98(UnkStruct_0809A02C* w, void* a) {
    s32 dx = 0;
    s32 dy = 0;
    s32 v;
    u16 t;

    if (w->unk_1A8 < 0) {
        dx = 0x7800 - w->unk_38;
        dy = 0x5000 - w->unk_3C;
        NormalizeVector2D8(&dx, &dy);
        w->unk_1B0 = -dx;
        w->unk_1B4 = -dy;

        if (w->unk_1AC < 0x800) {
            w->unk_1C8 = 0;
            w->unk_1C9 = 0;
            w->unk_1C7 = 0;
            w->unk_38 = 0x7800;
            w->unk_3C = 0x5000;
            *(u16*)&w->unk_1B8 = v = 0x100;
            *(u16*)&w->unk_1BA = v;
#ifdef VERSION_EU
            CreateCardNameDisplay(&w->tasks, eu_0805E924(gCardDefs[w->cardId].name));
#else
            CreateCardNameDisplay(&w->tasks, gCardDefs[w->cardId].name);
#endif
            SetTaskUpdate(a, (void*)func_0809AD60);
            w->unk_1C4 = 0;
            w->unk_1C2 = 50;
            return 1;
        }
    }

    w->unk_38 += (w->unk_1B0 * w->unk_1A8) >> 8;
    w->unk_3C += (w->unk_1B4 * w->unk_1A8) >> 8;
    w->unk_1C9 += 32;
    w->unk_1C8 += (64 - w->unk_1C8) >> 4;
    w->unk_1C7 = 0;
    w->unk_1AC = VectorLength2D(0x7800 - w->unk_38, 0x5000 - w->unk_3C);
    w->unk_1A8 -= w->unk_1A4;
    w->unk_1A4 += 2;
    t = w->unk_1BC;

    if ((s16)t <= 255) {
        w->unk_1BC = t + 3;
    }

    w->unk_1B8 = (-gSineTable[((w->unk_1C7 + 128) & 0xFF) + 64] * w->unk_1BC) >> 8;
    w->unk_1BA = (-gSineTable[((w->unk_1C8 + 128) & 0xFF) + 64] * w->unk_1BC) >> 8;

    if ((u16)(w->unk_1B8 + 2) <= 4) {
        w->unk_1B8 = 2;
    }

    if ((u16)(w->unk_1BA + 2) <= 4) {
        w->unk_1BA = 2;
    }

    TaskPoolUpdate(&w->tasks);
    return 1;
}
s32 Heartless_card_1(UnkStruct_0809A02C* w, void* a) {
    s16 x;
    s16 y;

    w->unk_1A4 += 0x38;
    w->unk_40 += w->unk_1A4;
    w->unk_38 += (gSineTable[w->unk_1C6] * w->unk_1A8) >> 8;
    w->unk_3C += (-gSineTable[w->unk_1C6 + 64] * w->unk_1A8) >> 8;

    if (ClampBattlePosition(&w->unk_38, &w->unk_3C, -10, -10) != 0) {
        w->unk_1C6 = (u8)(w->unk_1C6 + 0x70) + GetRandom() % 33;
    }

    if (w->unk_40 - 0x800 > w->unk_44) {
        w->unk_40 = w->unk_44 - 0x800;
        w->unk_1A4 = -((w->unk_1A4 * 204) >> 8);
        w->unk_1C6 = GetAngle(w->unk_38, w->unk_3C, gBtlWork->actor->x, gBtlWork->actor->y);
        w->unk_1C6 = (u8)(w->unk_1C6 + 0xE0) + GetRandom() % 65;

        if (w->unk_1A4 > -0x200) {
            w->unk_1A4 = -0x200;
        }
    }

    if (gBtlWork->unk_0F4 == 6) {
        ColliderSetRadius(w->unk_144, 50);
    } else {
        ColliderSetRadius(w->unk_144, 10);
    }

    if (func_0801C6D4(&w->unk_38, &w->unk_3C, &w->unk_40, &w->unk_44)) {
        w->unk_1C6 = (u8)(w->unk_1C6 + 0x70) + GetRandom() % 33;
    }

    if (w->unk_170 != 0) {
        m4aSongNumStart(0x6A);
#ifdef VERSION_EU
        w->unk_1C2 = 10;
#endif
        func_08084458(w->cardId);
        WorldToScreen(&x, &y, w->unk_38, w->unk_3C, w->unk_40);
        w->unk_38 = x << 8;
        w->unk_3C = y << 8;
        w->unk_1CA = 1;
        ColliderSetDisabled(w->unk_144, 1);
        func_0809A4E0(w, 1);
        SetTaskUpdate(a, (void*)func_0809AD98);
        return 1;
    }

    ColliderSetPosition(w->unk_144, w->unk_38, w->unk_3C, w->unk_40);
    w->unk_1B8 = (-gSineTable[((w->unk_1C7 + 128) & 0xFF) + 64] * w->unk_1BC) >> 8;
    w->unk_1BA = (-gSineTable[((w->unk_1C8 + 128) & 0xFF) + 64] * w->unk_1BC) >> 8;

    if ((u16)(w->unk_1B8 + 2) <= 4) {
        w->unk_1B8 = 2;
    }

    if ((u16)(w->unk_1BA + 2) <= 4) {
        w->unk_1BA = 2;
    }

    w->unk_1C7 += 2;
    w->unk_1C2 = -0x1004 - ((w->unk_3C >> 8) << 2);
    TaskPoolUpdate(&w->tasks);
    return 1;
}
void func_0809B200(UnkStruct_0809A02C* w) {
    s16 x;
    s16 y;
    s32 affine;
    s16 v;
    u8 kind;

    if (w->unk_1CD != 0) {
        if (w->unk_1CA == 0) {
            w->unk_1D0 = GetBattleSpritePriorityFlags(w->unk_3C);
            WorldToScreen(&x, &y, w->unk_38, w->unk_3C,
                          w->unk_40);
        } else {
            w->unk_1D0 = 0;
            x = w->unk_38 >> 8;
            y = w->unk_3C >> 8;
        }

        affine = AllocObjAffine(w->unk_1C9, w->unk_1B8,
                                w->unk_1BA, 0);
        DrawSprite(x, (u16)y - 8,
                   gUnk_08F709B0[w->cardDef->unk_2A].gfx,
                   ((UnkStruct_0809B200*)gUnk_02039DD4)->unk_030[w->cardDef->unk_2A],
                   w->palette, affine,
                   w->unk_1D0, w->unk_1C2);
        DrawSprite(x, (u16)y - 8, w->cardDef->gfx,
                   w->tiles2, w->palette2, affine,
                   w->unk_1D0, (u16)(w->unk_1C2 + 1));
        kind = w->cardDef->unk_20;
        DrawSprite(x, (u16)y - 8, gUnk_09EE981C[kind],
                   w->tiles3, w->palette, affine,
                   w->unk_1D0, (u16)(w->unk_1C2 - 2));
        v = 204 - ((w->unk_44 - w->unk_40) >> 7);

        if (v <= 2) {
            v = 2;
        }

        if (w->unk_1CA == 0) {
            WorldToScreen(&w->x, &w->y,
                          w->unk_38, w->unk_3C,
                          w->unk_44);
            DrawSprite(w->x, w->y,
                       gUnk_09EE1380[0], w->tiles4,
                       w->palette3, AllocObjAffine(0, v, v, 0),
                       w->unk_1D0, (u16)(w->unk_1C2 + 2));
        }

        TaskPoolDraw(&w->tasks);
    }
}
void Heartless_card_2(UnkStruct_0809A02C* w) {
    s16 x;
    s16 y;
    s32 affine;
    s16 v;

    if (w->unk_1CD != 0) {
        if (w->unk_1CA == 0) {
            w->unk_1D0 = GetBattleSpritePriorityFlags(w->unk_3C);
            WorldToScreen(&x, &y, w->unk_38, w->unk_3C,
                          w->unk_40);
        } else {
            w->unk_1D0 = 0;
            x = w->unk_38 >> 8;
            y = w->unk_3C >> 8;
        }

        affine = AllocObjAffine(w->unk_1C9, w->unk_1B8,
                                w->unk_1BA, 0);
        DrawSprite(x, (u16)y - 8,
                   gUnk_08F709B0[w->cardDef->unk_2A].gfx,
                   w->tiles, w->palette, affine,
                   w->unk_1D0, w->unk_1C2);
        DrawSprite(x, (u16)y - 8, w->cardDef->gfx,
                   w->tiles2, w->palette2, affine,
                   w->unk_1D0, (u16)(w->unk_1C2 + 1));
        v = 204 - ((w->unk_44 - w->unk_40) >> 7);

        if (v <= 2) {
            v = 2;
        }

        if (w->unk_1CA == 0) {
            WorldToScreen(&w->x, &w->y,
                          w->unk_38, w->unk_3C,
                          w->unk_44);
            DrawSprite(w->x, w->y,
                       gUnk_09EE1380[0], w->tiles4,
                       w->palette3, AllocObjAffine(0, v, v, 0),
                       w->unk_1D0, (u16)(w->unk_1C2 + 2));
        }

        TaskPoolDraw(&w->tasks);
    }
}

void func_0809B59C(UnkStruct_0809A02C* w) {
    ReleaseObjPalette(w->palette);
    ReleaseObjTiles(w->tiles2);
    ReleaseObjPalette(w->palette2);
    ReleaseObjTiles(w->tiles4);
    ReleaseObjPalette(w->palette3);
    ColliderUnregister(w->unk_144);
    TaskPoolDestroy(&w->tasks);
    gUnk_02039DD4->unk_0D6 = 0;
    gBtlWork->unk_0B0--;
}

void Heartless_card_3(UnkStruct_0809A02C* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    ReleaseObjTiles(w->tiles2);
    ReleaseObjPalette(w->palette2);
    ReleaseObjTiles(w->tiles4);
    ReleaseObjPalette(w->palette3);
    ColliderUnregister(w->unk_144);
    TaskPoolDestroy(&w->tasks);
    gBtlWork->unk_0B0--;
}

void func_0809B644(void* pool, s16 x, s16 y, s16 z, u8 idx) {
    s32 args[4];

    if (gUnk_02039DD4 != 0) {
        if (gUnk_02039DD4->unk_0DA[0] <= 4) {
            if (gUnk_02039DD4->unk_0D6 == 0) {
                args[0] = (s16)x << 8;
                args[1] = (s16)y << 8;
                args[2] = (s16)z << 8;
                args[3] = gUnk_09036210[idx] + GetRandom() % 9;
                TaskCreate(pool, &gTaskDescFriendCard, args);
                gUnk_02039DD4->unk_0D6++;
            }
        }
    }
}

void CreateHeartlessCardTask(void* pool, s16 a, s16 b, s16 c, u16 d) {
    s32 args[4];
    const s32* t;

    t = gUnk_09EE275C[d];
    args[0] = a << 8;
    args[1] = b << 8;
    args[2] = c << 8;
    args[3] = t[0];
    TaskCreate(pool, &gTaskDescHeartlessCard, args);
}

void func_0809B710(void* pool, u16 a, u16 b, u16 c, u16 d) {
    s32 args[4];

    if (gUnk_02039DD4 != 0 && gUnk_02039DD4->unk_0DC == 0) {
        gUnk_02039DD4->unk_0DC++;
        args[0] = (s16)a << 8;
        args[1] = (s16)b << 8;
        args[2] = (s16)c << 8;
        args[3] = d;
        TaskCreate(pool, &gTaskDescGimmickCard, args);
    }
}

void func_0809B76C(u8* work, void** src) {
    u8 i;
    void** dst;
    void** q;
    void** s;
    s32 z;
    UnkStruct_080038C8* obj;

    if (src != 0) {
        s = src;

        for (i = 0; i < 6; i++) {
            dst = (void**)&work[0x18];
            q = &dst[i];
            *q = s[i];
        }

        work[0x30] = 1;
    } else {
        work[0x30] = 0;
    }

    z = 0;
    work[0x11] = z;
    *(u16*)&work[4] = z;
    obj = AllocSpriteFrameTiles(0x3C0);
    *(UnkStruct_080038C8**)&work[8] = obj;

    if (work[0x30] == 0) {
#ifdef VERSION_EU
        void** t;
        void* u;

        t = (void**)LANGSTR(gUnk_08F7CF18[gUnk_02039DD4->unk_0C4].sprites);
        u = LANGSTR(gUnk_08F7CF18[gUnk_02039DD4->unk_0C4].tiles);
        UpdateSpriteFrameTiles(obj, t[gUnk_08F7CF18[gUnk_02039DD4->unk_0C4].spriteIndex], u);
#else
        UpdateSpriteFrameTiles(obj, gUnk_08F7CF18[gUnk_02039DD4->unk_0C4].sprites[gUnk_08F7CF18[gUnk_02039DD4->unk_0C4].spriteIndex], gUnk_08F7CF18[gUnk_02039DD4->unk_0C4].tiles);
#endif
    } else {
#ifdef VERSION_EU
        void** t;
        void* u;

        t = (void**)LANGSTR(gUnk_08F7CF18[*(u32*)&work[0x18]].sprites);
        u = LANGSTR(gUnk_08F7CF18[*(u32*)&work[0x18]].tiles);
        UpdateSpriteFrameTiles(obj, t[gUnk_08F7CF18[*(u32*)&work[0x18]].spriteIndex], u);
#else
        UpdateSpriteFrameTiles(obj, gUnk_08F7CF18[*(u32*)&work[0x18]].sprites[gUnk_08F7CF18[*(u32*)&work[0x18]].spriteIndex], gUnk_08F7CF18[*(u32*)&work[0x18]].tiles);
#endif
    }

    *(void**)&work[0xC] = LoadObjPalette(gUnk_08F69BA4, 32);
    work[0x31] = 1;
    *(u32*)&work[0x14] = gUnk_02039DD4->unk_0C4;
}

u8 func_0809B840(StockNameWork* w) {
#ifdef VERSION_EU
    void** t = (void**)LANGSTR(gUnk_08F7CF18[w->unk_18[w->unk_11]].sprites);
    void* u = LANGSTR(gUnk_08F7CF18[w->unk_18[w->unk_11]].tiles);
#endif

    if (gUnk_02039DD4->unk_0E3 == 0 || gUnk_02039DD4->unk_0C4 != w->unk_14) {
        return 0;
    }

    if ((gFrameCounter >> 5) & 1) {
        w->unk_31 = 1;
    } else {
        w->unk_31 = 0;
    }

    if (w->unk_30 == 1 && w->unk_31 != 0) {
        w->unk_11++;

        if (w->unk_18[w->unk_11] == -1) {
            w->unk_11 = 0;
        }

#ifdef VERSION_EU
        UpdateSpriteFrameTiles(w->tiles, t[gUnk_08F7CF18[w->unk_18[w->unk_11]].spriteIndex], u);
#else
        UpdateSpriteFrameTiles(w->tiles, gUnk_08F7CF18[w->unk_18[w->unk_11]].sprites[gUnk_08F7CF18[w->unk_18[w->unk_11]].spriteIndex], gUnk_08F7CF18[w->unk_18[w->unk_11]].tiles);
#endif
    }

    return 1;
}

void func_0809B8F0(u8* work) {
    if (work[0x31] != 0) {
        DrawSprite(64, 14, 0, *(void**)&work[0x08], *(void**)&work[0x0C], 0,
#ifdef VERSION_EU
                   0x410,
#else
                   0,
#endif
                   10);
    }
}
void func_0809B920(u8* work, void** src) {
    u8 i;
    void** dst;
    void** q;
    void** s;
    s32 z;
    UnkStruct_080038C8* obj;

    if (src != 0) {
        s = src;

        for (i = 0; i < 6; i++) {
            dst = (void**)&work[0x18];
            q = &dst[i];
            *q = s[i];
        }

        work[0x30] = 1;
    } else {
        work[0x30] = 0;
    }

    z = 0;
    work[0x11] = z;
    *(u16*)&work[4] = z;
    obj = AllocSpriteFrameTiles(0x3C0);
    *(UnkStruct_080038C8**)&work[8] = obj;

    if (work[0x30] == 0) {
#ifdef VERSION_EU
        void** t;
        void* u;

        t = (void**)LANGSTR(gUnk_08F7CF18[gUnk_02039DD4->unk_0C6].sprites);
        u = LANGSTR(gUnk_08F7CF18[gUnk_02039DD4->unk_0C6].tiles);
        UpdateSpriteFrameTiles(obj, t[gUnk_08F7CF18[gUnk_02039DD4->unk_0C6].spriteIndex], u);
#else
        UpdateSpriteFrameTiles(obj, gUnk_08F7CF18[gUnk_02039DD4->unk_0C6].sprites[gUnk_08F7CF18[gUnk_02039DD4->unk_0C6].spriteIndex], gUnk_08F7CF18[gUnk_02039DD4->unk_0C6].tiles);
#endif
    } else {
#ifdef VERSION_EU
        void** t;
        void* u;

        t = (void**)LANGSTR(gUnk_08F7CF18[*(u32*)&work[0x18]].sprites);
        u = LANGSTR(gUnk_08F7CF18[*(u32*)&work[0x18]].tiles);
        UpdateSpriteFrameTiles(obj, t[gUnk_08F7CF18[*(u32*)&work[0x18]].spriteIndex], u);
#else
        UpdateSpriteFrameTiles(obj, gUnk_08F7CF18[*(u32*)&work[0x18]].sprites[gUnk_08F7CF18[*(u32*)&work[0x18]].spriteIndex], gUnk_08F7CF18[*(u32*)&work[0x18]].tiles);
#endif
    }

    *(void**)&work[0xC] = LoadObjPalette(gUnk_08F69BA4, 32);
    work[0x31] = 1;
    *(u32*)&work[0x14] = gUnk_02039DD4->unk_0C6;
}

u8 func_0809B9F4(StockNameWork* w) {
#ifdef VERSION_EU
    void** t = (void**)LANGSTR(gUnk_08F7CF18[w->unk_18[w->unk_11]].sprites);
    void* u = LANGSTR(gUnk_08F7CF18[w->unk_18[w->unk_11]].tiles);
#endif

    if (gUnk_02039DD4->unk_0E4 == 0 || gUnk_02039DD4->unk_0C6 != w->unk_14) {
        return 0;
    }

    if ((gFrameCounter >> 5) & 1) {
        w->unk_31 = 0;
    } else {
        w->unk_31 = 1;
    }

    if (w->unk_30 == 1 && w->unk_31 != 0) {
        w->unk_11++;

        if (w->unk_18[w->unk_11] == -1) {
            w->unk_11 = 0;
        }

#ifdef VERSION_EU
        UpdateSpriteFrameTiles(w->tiles, t[gUnk_08F7CF18[w->unk_18[w->unk_11]].spriteIndex], u);
#else
        UpdateSpriteFrameTiles(w->tiles, gUnk_08F7CF18[w->unk_18[w->unk_11]].sprites[gUnk_08F7CF18[w->unk_18[w->unk_11]].spriteIndex], gUnk_08F7CF18[w->unk_18[w->unk_11]].tiles);
#endif
    }

    return 1;
}

void func_0809BAA4(u8* work) {
    if (gUnk_02039B9C->unk_0F4 != 28 && work[0x31] != 0) {
        DrawSprite(120, 14, 0, *(void**)&work[0x08], *(void**)&work[0x0C], 0, 0,
                   10);
    }
}
void func_0809BAE4(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x08]);
    ReleaseObjPalette(*(void**)&work[0x0C]);
    gUnk_02039DD4->unk_0D9 = 0;
    work[0x31] = 0;
    gUnk_02039DD4->unk_0CA = 256;
}
void func_0809BB18(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x08]);
    ReleaseObjPalette(*(void**)&work[0x0C]);
    gUnk_02039DD4->unk_0D8 = 0;
    work[0x31] = 0;
    gUnk_02039DD4->unk_0C8 = 256;
}

void func_0809BB4C(UnkStruct_0809BB4C* w) {
    u8 n = 0;
    u8 i;
    s32 j;
    u16* cards;
    u32 zero0 = 0;
    u32 zero1;
    u32 zero2;

    CpuSet(&zero0, w, 0x05000024);
    gUnk_0203A9D0 = EwramAlloc(0x2C);
    w->slots = EwramAlloc(0x4B0);
    zero1 = 0;
    CpuSet(&zero1, gUnk_0203A9D0, 0x0500000B);
    zero2 = 0;
    CpuSet(&zero2, w->slots, 0x0500012C);
    cards = GetActiveDeck()->cards;
    w->tiles2 = AllocObjTiles(0x120, 0);
    w->palette2 = LoadObjPalette(gUnk_09618CD8, 32);
    SetObjTileSource(w->tiles2, gUnk_093F4578);
    AnimInit(&w->anim, gUnk_09EF1170, gUnk_09EF1150);
    AnimStart(&w->anim, 0, 1);
    w->gfx = AnimGetGfx(&w->anim);
#ifdef VERSION_EU
    switch (gLanguage) {
    case 1:
        w->tiles = LoadObjTiles(gUnkEu_0916292A, 0x340);
        break;
    case 2:
        w->tiles = LoadObjTiles(gUnkEu_091633A4, 0x3C0);
        break;
    case 3:
        w->tiles = LoadObjTiles(gUnkEu_09162FB8, 0x3C0);
        break;
    case 4:
        w->tiles = LoadObjTiles(gUnkEu_09162C8C, 0x300);
        break;
    case 0:
        w->tiles = LoadObjTiles(gUnk_0908BB80, 0x3C0);
        break;
    default:
        w->tiles = LoadObjTiles(gUnk_0908BB80, 0x3C0);
        break;
    }
#else
    w->tiles = LoadObjTiles(gUnk_0908BB80, 0x3C0);
#endif
    w->palette = LoadObjPalette(gUnk_09613E98, 32);
    w->tiles5 = LoadObjTiles(gUnk_0908BFB2, 0x3C0);
    w->tiles3 = AllocObjTiles(0x3C0, 0);
    w->palette3 = LoadObjPalette(gUnk_09618D18, 32);
    SetObjTileSource(w->tiles3, gUnk_093F47E4);
    AnimInit(&w->anim2, gUnk_09EF1194, gUnk_09EF1180);
    AnimStart(&w->anim2, 0, 1);
    w->gfx2 = AnimGetGfx(&w->anim2);
    w->tiles4 = LoadObjTiles(gUnk_0905F03C, 0x80);
    w->palette4 = LoadObjPalette(gUnk_08F69BA4, 32);
    FadeToAmount(0, 16, 16);
    FadeSetPaletteExcluded((u16)(w->palette->index + 16), 1);
    FadeSetPaletteExcluded((u16)(w->palette3->index + 16), 1);
    FadeSetPaletteExcluded((u16)(w->palette2->index + 16), 1);
    FadeSetPaletteExcluded((u16)(w->palette4->index + 16), 1);

#ifdef VERSION_EU
    for (i = 0, n = 0; i < DECK_SIZE; i++) {
#else
    for (i = 0; i < DECK_SIZE; i++) {
#endif
        if (cards[i] != 0xFFFF) {
            if (!(gCardCollection[cards[i]] & 0x8000)) {
                if (gCardDefs[gCardCollection[cards[i]] & CARD_ID_MASK].unk_2A != 3) {
                    if (gCardDefs[gCardCollection[cards[i]] & CARD_ID_MASK].unk_2A != 2) {
                        w->slots[n].unk_00 = gCardCollection[cards[i]] & CARD_ID_MASK;
                        w->slots[n].unk_04 = i;
                        w->slots[n].unk_06 = n;
                        w->slots[n].unk_07 = 0;
                        n++;
                    }
                }
            }
        }
    }

    if (n < 10) {
        j = 0;

        do {
            if (cards[j] != 0xFFFF) {
                if (!(gCardCollection[cards[j]] & 0x8000)) {
                    if (gCardDefs[gCardCollection[cards[j]] & CARD_ID_MASK].unk_2A != 3) {
                        if (gCardDefs[gCardCollection[cards[j]] & CARD_ID_MASK].unk_2A != 2) {
                            w->slots[n].unk_00 = gCardCollection[cards[j]] & CARD_ID_MASK;
                            w->slots[n].unk_04 = j;
                            w->slots[n].unk_06 = n;
                            w->slots[n].unk_07 = 0;
                            n++;
                        }
                    }
                }
            }

            j++;

            if (j > 98) {
                j = 0;
            }
        } while (n < 10);
    }

    w->unk_50 = n;
    TaskPoolInit(&w->tasks, w->unk_50 + 1);
    ListPoolInit(&gUnk_0203A9D0->cards);
    gUnk_0203A9D0->selectedCard = 0;
    gUnk_0203A9D0->effectCount = 0;
    TaskPoolInit(&gUnk_0203A9D0->effectTasks, 24);
    func_0809C294((u8*)w);
    w->unk_51 = 10;
    w->unk_52 = 0;
    w->unk_84 = 0;
    w->unk_85 = 1;
    w->unk_86 = 1;
    w->unk_87 = 0;
    w->unk_8A = 0;
    w->unk_8B = 16;
    w->unk_8C = 16;
    w->unk_30 = 0xFF80;
    w->unk_34 = -0x800;
    w->unk_38 = 0xA000;
}

u8 func_0809BE80(u8* work, void* a) {
    UnkStruct_0809C534* n;
    s32 t;
    s32 z;

    if (work[0x85] != 0) {
        if ((GetKeysPressed() & 1) && work[0x84] == 0) {
            work[0x84] = 1;
            m4aSongNumStart(106);
        }

        if ((GetKeysPressed() & 2) && work[0x84] != 1) {
            m4aSongNumStart(104);
            work[0x8B] = 16;
            work[0x8C] = 16;
            SetTaskUpdate(a, (void*)func_0809C4B0);
            n = (UnkStruct_0809C534*)ListPoolFirst(&gUnk_0203A9D0->cards);

            while (n != 0) {
                n->unk_55 |= 0xFF;
                work[0x86] = 0;
                n = (UnkStruct_0809C534*)ListPoolNext(&n->node);
            }

            TaskPoolUpdate(&work[0x3C]);
            TaskPoolUpdate(&gUnk_0203A9D0->effectTasks);
            z = 0;
            work[0x87] = 1;
            work[0x85] = z;
            return 1;
        }
    }

    n = (UnkStruct_0809C534*)ListPoolFirst(&gUnk_0203A9D0->cards);

    if (work[0x84] == 0) {
        while (n != 0) {
            t = n->unk_53;

            if (t == 0) {
                m4aSongNumStart(101);

                if (n->unk_52 < work[0x50] - 1) {
                    n->unk_52++;
                } else {
                    n->unk_52 = t;
                }

                n->unk_53 = work[0x51];
                work[0x52] = 1;
            }

            n = (UnkStruct_0809C534*)ListPoolNext(&n->node);
        }
    } else {
        work[0x87] = 1;
        SetTaskUpdate(a, (void*)func_0809C2D0);
    }

    if (work[0x51] == 4 || work[0x51] == 10) {
        work[0x85] = 1;
    } else {
        work[0x85] = 0;
    }

    if (work[0x52] != 0) {
        if (work[0x51] > 4) {
            work[0x51]--;
        }

        work[0x52] = 0;
    }

    *(void**)&work[0x28] = AnimUpdate(&work[0x54]);
    *(void**)&work[0x2C] = AnimUpdate(&work[0x6C]);
    TaskPoolUpdate(&work[0x3C]);
    TaskPoolUpdate(&gUnk_0203A9D0->effectTasks);
    return 1;
}

u8 func_0809C078(u8* work, void* a) {
    s32 v;
    u8* p;
    u8* n;

    n = (u8*)ListPoolFirst(&gUnk_0203A9D0->cards);

    if (n != 0 && n[0x55] == 1) {
        SetTaskUpdate(a, (void*)func_0809BE80);
    }

    p = &work[0x8C];

    if (*p != 0) {
        ApproachValue(&work[0x34], 0, *p);
        ApproachValue(&work[0x38], 0x9800, *p);
    } else {
        v = *(s16*)&work[0x30] << 8;
        p = &work[0x8B];
        ApproachValue(&v, 0, *p);
        *(s16*)&work[0x30] = v >> 8;
    }

    (*p)--;
    TaskPoolUpdate(&work[0x3C]);
    TaskPoolUpdate(&gUnk_0203A9D0->effectTasks);
    return 1;
}

void func_0809C110(u8* work) {
    if (work[0x87] == 0) {
        DrawSprite(62, 50, *(void**)&work[0x28], *(void**)&work[0x08], *(void**)&work[0x0C], 0, 0, 0);
        DrawSprite(53, 64, *(void**)&work[0x2C], *(void**)&work[0x10], *(void**)&work[0x14], 0, 0, 0);
    }

    if (work[0x85] != 0) {
        DrawSprite(88, 70, gUnk_09EE98EC[0], *(void**)&work[0x18], *(void**)&work[0x1C], 0, 0, 0);
    }

#ifdef VERSION_EU
    DrawSprite(*(s16*)&work[0x30], 0, gUnkEu_09F72BFC[gLanguage][0], *(void**)&work[0x00], *(void**)&work[0x04], 0, 0, 0);
#else
    DrawSprite(*(s16*)&work[0x30], 0, gUnk_09EEA16C[0], *(void**)&work[0x00], *(void**)&work[0x04], 0, 0, 0);
#endif
    DrawSprite(120, *(s32*)&work[0x34] >> 8, gUnk_09EEA174[0], *(void**)&work[0x20], *(void**)&work[0x04], 0, 0, 60);
    DrawSprite(120, *(s32*)&work[0x38] >> 8, gUnk_09EEA174[1], *(void**)&work[0x20], *(void**)&work[0x04], 0, 0, 60);
    TaskPoolDraw(&work[0x3C]);
    TaskPoolDraw(&gUnk_0203A9D0->effectTasks);
}

void func_0809C1EC(u8* work) {
    TaskPoolDestroy(&gUnk_0203A9D0->effectTasks);
    EwramFree(*(void**)&work[0x24]);
    EwramFree(gUnk_0203A9D0);
    ReleaseObjTiles(*(void**)&work[0x08]);
    ReleaseObjTiles(*(void**)&work[0x10]);
    ReleaseObjTiles(*(void**)&work[0x18]);
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjTiles(*(void**)&work[0x20]);
    FadeSetPaletteExcluded((*(UnkStruct_080038C8**)&work[0x04])->index + 16, 0);
    FadeSetPaletteExcluded((*(UnkStruct_080038C8**)&work[0x14])->index + 16, 0);
    FadeSetPaletteExcluded((*(UnkStruct_080038C8**)&work[0x0C])->index + 16, 0);
    FadeSetPaletteExcluded((*(UnkStruct_080038C8**)&work[0x1C])->index + 16, 0);
    ReleaseObjPalette(*(void**)&work[0x0C]);
    ReleaseObjPalette(*(void**)&work[0x14]);
    ReleaseObjPalette(*(void**)&work[0x1C]);
    ReleaseObjPalette(*(void**)&work[0x04]);
    func_0800FDD0(0xF5);
    TaskPoolDestroy(&work[0x3C]);
}

void func_0809C294(u8* work) {
    u8 i;

    for (i = 0; i < work[0x50]; i++) {
        (*(u8**)&work[0x24])[i * 12 + 6] = i;
        TaskCreate(&work[0x3C], &gUnk_09EE781C, &(*(u8**)&work[0x24])[i * 12]);
    }
}
u8 func_0809C2D0(u8* work, void* a) {
    u8* n;
    u8* pool;
    u8 z;
    u8 t;
    u8* q;

    n = (u8*)ListPoolFirst(&gUnk_0203A9D0->cards);
    *(void**)&work[0x28] = AnimUpdate(&work[0x54]);
    *(void**)&work[0x2C] = AnimUpdate(&work[0x6C]);
    work[0x51] = 0;
    work[0x8A]++;
    work[0x85] = 0;

    if (work[0x86] != 0) {
        while (n != 0) {
            if (n[0x53] == 0) {
                if ((s8)n[0x52] == 3) {
                    n[0x55] = 2;
                    ConvertActiveDeckCardToPremium(*(u16*)&n[0x48]);
                } else {
                    n[0x55] = 3;
                }

                work[0x86] = 0;
            }

            n = (u8*)ListPoolNext(&n[0x58]);
        }
    }

    t = work[0x8A];
    pool = &work[0x3C];

    if (t == 30) {
        q = &work[0x87];
        z = 0;
        *q = 1;
        SetBgPriority(2, 0);
        BgAnimInit(2, 0x8000, 0x80);
        BgAnimStart(&gUnk_09EDA9A8, 120, 60);
        work[0x88] = BgAnimGetDuration(&gUnk_09EDA9A8);
        work[0x89] = z;
        gBldCnt = 0x1B44;
        gBldAlpha = 0x1010;
        BgAnimUpdate();
        FadeSetPaletteExcluded(10, 1);
        FadeSetPaletteExcluded(11, 1);
        FadeSetPaletteExcluded(12, 1);
        FadeSetPaletteExcluded(13, 1);
        FadeSetPaletteExcluded(14, 1);
        FadeSetPaletteExcluded(15, 1);
        TaskCreate(pool, &gTaskDescCardName, 0);
        SetTaskUpdate(a, (void*)func_0809C448);
    }

    TaskPoolUpdate(pool);
    TaskPoolUpdate(&gUnk_0203A9D0->effectTasks);
    return 1;
}

u8 func_0809C448(u8* work, void* a) {
    ListPoolFirst(&gUnk_0203A9D0->cards);
    BgAnimUpdate();
    *(void**)&work[0x28] = AnimUpdate(&work[0x54]);
    *(void**)&work[0x2C] = AnimUpdate(&work[0x6C]);
    TaskPoolUpdate(&work[0x3C]);
    TaskPoolUpdate(&gUnk_0203A9D0->effectTasks);

    if ((GetKeysPressed() & 1)
#ifdef VERSION_EU
        && work[0x89] > 8
#endif
    ) {
        work[0x8B] = 16;
        work[0x8C] = 16;
        SetTaskUpdate(a, (void*)func_0809C4B0);
    }

#ifdef VERSION_EU
    if (work[0x89] <= 254) {
        work[0x89]++;
    }
#endif

    return 1;
}

u8 func_0809C4B0(u8* work, void* a) {
    s32 v;
    u8* p;

    p = &work[0x8B];

    if (*p != 0) {
        v = *(s16*)&work[0x30] << 8;
        ApproachValue(&v, -0x8000, *p);
        *(s16*)&work[0x30] = v >> 8;
    } else {
        p = &work[0x8C];

        if (*p == 0) {
            return 0;
        }

        ApproachValue(&work[0x34], -0x800, *p);
        ApproachValue(&work[0x38], 0xA000, *p);
    }

    (*p)--;
    TaskPoolUpdate(&work[0x3C]);
    TaskPoolUpdate(&gUnk_0203A9D0->effectTasks);
    return 1;
}

struct UnkStruct_0809BB4C;
void func_0809BB4C(struct UnkStruct_0809BB4C* w);

const char gTaskNameFriendCard[] = "Friend card";

TaskDesc gTaskDescFriendCard = {
    gTaskNameFriendCard,
    (void (*)(void*, void*))Friend_card_0,
    Friend_card_1,
    (void (*)(void*))func_0809B200,
    (void (*)(void*))func_0809B59C,
    0x1D4,
};

const char gTaskNameHeartlessCard[] = "Heartless card";

TaskDesc gTaskDescHeartlessCard = {
    gTaskNameHeartlessCard,
    (void (*)(void*, void*))Heartless_card_0,
    Heartless_card_1,
    (void (*)(void*))Heartless_card_2,
    (void (*)(void*))Heartless_card_3,
    0x1D4,
};

const char gTaskNameGimmickCard[] = "Gimmick card";

TaskDesc gTaskDescGimmickCard = {
    gTaskNameGimmickCard,
    (void (*)(void*, void*))Gimmick_card_0,
    Gimmick_card_1,
    (void (*)(void*))func_0809B200,
    (void (*)(void*))func_0809B59C,
    0x1D4,
};

const char gTaskNameStockName[] = "StockName";

TaskDesc gUnk_09EE77D4 = {
    gTaskNameStockName,
    (void (*)(void*, void*))func_0809B76C,
    func_0809B840,
    (void (*)(void*))func_0809B8F0,
    (void (*)(void*))func_0809BB18,
    0x34,
};

TaskDesc gUnk_09EE77EC = {
    gTaskNameStockName,
    (void (*)(void*, void*))func_0809B920,
    func_0809B9F4,
    (void (*)(void*))func_0809BAA4,
    (void (*)(void*))func_0809BAE4,
    0x34,
};
#ifdef VERSION_EU
void** gUnkEu_09F72BFC[5] = { gUnk_09EEA16C, &gUnkEu_09F75FB4, &gUnkEu_09F75FCC, &gUnkEu_09F75FC4, &gUnkEu_09F75FBC };
#endif

const char gTaskName_09EE7804[] = "Premire Chance";

TaskDesc gUnk_09EE7804 = {
    gTaskName_09EE7804,
    (void (*)(void*, void*))func_0809BB4C,
    func_0809C078,
    (void (*)(void*))func_0809C110,
    (void (*)(void*))func_0809C1EC,
    0x90,
};
