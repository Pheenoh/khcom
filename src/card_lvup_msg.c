#include "macros.h"
#include "card_localized_data.h"
#include "card_animation_data.h"
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

u8 func_080A25E0(LvupMsgWork* w, void* a);
void func_080A27EC(u8* work);
extern u8 gUnk_0815A09A[];
extern u8 gUnk_0815A198[];
extern u8 gUnk_0815A0EE[];
extern u8 gUnk_0815A152[];
extern u8 gUnk_0815A0A0[];
#ifdef VERSION_EU
extern u8 gUnkEu_08895EDC[];
#endif
void func_080A23A0(LvupMsgWork* w, LvupMsgArgs* a) {
    struct UnkStruct_080A23A0_Packed args = *(struct UnkStruct_080A23A0_Packed*)a;

    InitTextSlots(w->unk_000, 20);
    InitTextSlots(w->unk_0A0, 20);
    InitTextSlots(w->unk_140, 20);
#ifndef VERSION_JP
    InitTextSlots(w->unk_1E0, 20);
    w->unk_2B0 = LoadTextSlots((u8*)gUnk_0903BFD4 + 0x24, w->unk_1E0);
#endif
    w->unk_28C = a->unk_04 >> 16;
    w->unk_2B4 = a->unk_00;
    if (args.unk_04 & 0x8000) {
#ifdef VERSION_EU
        w->unk_2AD = LoadTextSlots(eu_0805E924(gUnk_0815A09A), w->unk_000);
#else
        w->unk_2AD = LoadTextSlots(gUnk_0815A09A, w->unk_000);
#endif
    } else if (args.unk_04 & 0x4000) {
#ifdef VERSION_EU
        w->unk_2AD = LoadTextSlots(eu_0805E924(gUnk_0815A198), w->unk_000);
#else
        w->unk_2AD = LoadTextSlots(gUnk_0815A198, w->unk_000);
#endif
    } else if (!(gGameState.flags & 8)) {
#ifdef VERSION_EU
        w->unk_2AD = LoadTextSlots(eu_0805E924(gUnk_0815A0EE), w->unk_000);
#else
        w->unk_2AD = LoadTextSlots(gUnk_0815A0EE, w->unk_000);
#endif
    } else {
#ifdef VERSION_EU
        w->unk_2AD = LoadTextSlots(eu_0805E924(gUnk_0815A152), w->unk_000);
#else
        w->unk_2AD = LoadTextSlots(gUnk_0815A152, w->unk_000);
#endif
    }
    w->unk_2AE = LoadTwoDigitTextSlots((u8)w->unk_28C, w->unk_0A0);
#ifdef VERSION_EU
    if ((args.unk_04 & 0x8000) && gLanguage == 4) {
        w->unk_2AF = LoadTextSlots(eu_0805E924(gUnkEu_08895EDC), w->unk_140);
    } else {
        w->unk_2AF = LoadTextSlots(eu_0805E924(gUnk_0815A0A0), w->unk_140);
    }
#else
    w->unk_2AF = LoadTextSlots(gUnk_0815A0A0, w->unk_140);
#endif
    w->unk_280 = _08066468(1);
    FadeSetPaletteExcluded(((u16*)w->unk_280)[3] + 16, 1);
    w->x = 0x1000;
    w->x2 = 0x3000;
    w->x3 = 0x4200;
    w->y2 = 0xC800;
    w->y3 = 0xC800;
    w->y4 = 0xC800;
    w->y = 0xCE00;
    w->unk_2AC = 14;
    w->unk_2B1 = 0;
    w->x = ((144 - (GetTextSlotsWidth(w->unk_000, w->unk_2AD)
#ifndef VERSION_JP
                         + GetTextSlotsWidth(w->unk_1E0, w->unk_2B0)
#endif
                         + GetTextSlotsWidth(w->unk_0A0, w->unk_2AE)
                         + GetTextSlotsWidth(w->unk_140, w->unk_2AF))) / 2) << 8;
#ifdef VERSION_EU
    w->tiles = AllocSpriteFrameTiles(0x780);
    UpdateSpriteFrameTiles(w->tiles, gUnk_09EF126C[0], gUnk_093F7C9C);
#else
    w->tiles = LoadObjTiles(gUnk_093F7C9C, 0xFC0);
#endif
    w->palette = LoadObjPalette(gUnk_09611AB8, 32);
}

s32 func_080A25B8(LvupMsgWork* w, void* a) {
    SetTaskUpdate(a, func_080A25E0);
    w->unk_2B1++;
    return 1;
}
u8 func_080A25E0(LvupMsgWork* w, void* a) {
    s8* counter = &w->unk_2AC;

    if (*counter > 0) {
        ApproachValue(&w->y, 0x6C00, *counter);
        ApproachValue(&w->y2, 0x6600, *counter);
        ApproachValue(&w->y3, 0x6600, *counter);
        ApproachValue(&w->y4, 0x6600, *counter);
        (*counter)--;
    } else if (*counter == 0) {
        m4aSongNumStart(202);
        w->unk_2AC = -1;
    }

    if (*w->unk_2B4 == 0) {
        return 0;
    }
    return 1;
}
void func_080A2678(LvupMsgWork* w) {
#ifdef VERSION_JP
    w->x2 = w->x + w->unk_2AD * 0xA00;
    w->x3 = w->x2 + w->unk_2AE * 0xA00;
#elif defined(VERSION_EU)
    switch (gLanguage) {
    case 0:
        w->x3 = w->x + ((GetTextSlotsWidth(w->unk_000, w->unk_2AD) + 3) << 8);
        w->x2 = w->x3 + ((GetTextSlotsWidth(w->unk_140, w->unk_2AF) + 3) << 8);
        DrawTextSlots((w->x2 >> 8) + GetTextSlotsWidth(w->unk_0A0, w->unk_2AE), w->y3 >> 8,
                      w->unk_1E0, w->unk_280, 40, w->unk_2B0);
        break;
    case 1:
        w->x3 = w->x + ((GetTextSlotsWidth(w->unk_000, w->unk_2AD) + 3) << 8);
        w->x2 = w->x3 + ((GetTextSlotsWidth(w->unk_140, w->unk_2AF) + 3) << 8);
        DrawTextSlots((w->x2 >> 8) + GetTextSlotsWidth(w->unk_0A0, w->unk_2AE), w->y3 >> 8,
                      w->unk_1E0, w->unk_280, 40, w->unk_2B0);
        break;
    case 2:
        w->x2 = w->x + ((GetTextSlotsWidth(w->unk_000, w->unk_2AD) + 3) << 8);
        w->x3 = w->x2 + ((GetTextSlotsWidth(w->unk_0A0, w->unk_2AE) + 3) << 8);
        break;
    case 3:
        w->x3 = w->x + ((GetTextSlotsWidth(w->unk_000, w->unk_2AD) + 3) << 8);
        w->x2 = w->x3 + ((GetTextSlotsWidth(w->unk_140, w->unk_2AF) + 3) << 8);
        DrawTextSlots((w->x2 >> 8) + GetTextSlotsWidth(w->unk_0A0, w->unk_2AE), w->y3 >> 8,
                      w->unk_1E0, w->unk_280, 40, w->unk_2B0);
        break;
    case 4:
        w->x3 = w->x + ((GetTextSlotsWidth(w->unk_000, w->unk_2AD) + 3) << 8);
        w->x2 = w->x3 + ((GetTextSlotsWidth(w->unk_140, w->unk_2AF) + 3) << 8);
        DrawTextSlots((w->x2 >> 8) + GetTextSlotsWidth(w->unk_0A0, w->unk_2AE), w->y3 >> 8,
                      w->unk_1E0, w->unk_280, 40, w->unk_2B0);
        break;
    }
#else
    w->x3 = w->x + ((GetTextSlotsWidth(w->unk_000, w->unk_2AD) + 3) << 8);
    w->x2 = w->x3 + ((GetTextSlotsWidth(w->unk_140, w->unk_2AF) + 3) << 8);
#endif
#ifdef VERSION_EU
    DrawSprite(72, w->y >> 8, 0, w->tiles, w->palette, 0, 0, 41);
#else
    DrawSprite(72, w->y >> 8, gUnk_09EF126C[0], w->tiles, w->palette, 0, 0, 41);
#endif
    DrawTextSlots(w->x >> 8, w->y2 >> 8, w->unk_000, w->unk_280, 40, w->unk_2AD);
    DrawTextSlots(w->x2 >> 8, w->y3 >> 8, w->unk_0A0, w->unk_280, 40, w->unk_2AE);
    DrawTextSlots(w->x3 >> 8, w->y4 >> 8, w->unk_140, w->unk_280, 40, w->unk_2AF);
#ifdef VERSION_US
    DrawTextSlots((w->x2 >> 8) + GetTextSlotsWidth(w->unk_0A0, w->unk_2AE), w->y3 >> 8,
                  w->unk_1E0, w->unk_280, 40, w->unk_2B0);
#endif
}
void func_080A27EC(u8* work) {
    FreeTextSlots((TextSlot*)work, 20);
    FreeTextSlots((TextSlot*)&work[0xA0], 20);
    FreeTextSlots((TextSlot*)&work[0x140], 20);
#ifdef VERSION_JP
    ReleaseObjPalette(*(u8**)&work[0x1E0]);
    ReleaseObjTiles(*(void**)&work[0x1E4]);
    ReleaseObjPalette(*(u8**)&work[0x1E8]);
#else
    FreeTextSlots((TextSlot*)&work[0x1E0], 20);
    ReleaseObjPalette(*(u8**)&work[0x280]);
    ReleaseObjTiles(*(void**)&work[0x284]);
    ReleaseObjPalette(*(u8**)&work[0x288]);
#endif
}

const char gTaskNameLvupMsg[] = "Lvup msg";

TaskDesc gTaskDescLvupMsg = {
    gTaskNameLvupMsg,
    (void (*)(void*, void*))func_080A23A0,
    func_080A25B8,
    (void (*)(void*))func_080A2678,
    (void (*)(void*))func_080A27EC,
#ifdef VERSION_JP
    0x218,
#else
    0x2B8,
#endif
};
