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

#ifdef VERSION_EU
extern u8 gUnkEu_08895A00[];
extern void* gUnkEu_08890E1C[];
extern void* gUnkEu_08890E44[];
extern void* gUnkEu_08890EC0[];
extern void* gUnkEu_08895E94[];
extern void* gUnkEu_08895AF4[];
extern void* gUnkEu_08895C30[];
extern void* gUnkEu_08895CF8[];
extern void* gUnkEu_08895DBC[];
#endif
u8* GetDeckName(u8 index);
void SetActiveDeckIndex(u8 index);
u8 GetActiveDeckIndex(void);

void Deck_Equip_0(DeckConfirmWork* w, u8* a) {
    w->unk_78C = 0;
    w->unk_78D = 0;
    w->unk_78E = 0;
    InitTextSlots(w, 80);
    InitTextSlots(w->unk_280, 80);
    InitTextSlots(w->unk_500, 80);
    w->unk_78C = LoadTextSlots(GetDeckName(GetActiveDeckIndex()), w);
#ifdef VERSION_JP
    w->unk_78D = LoadTextSlots(&gUnk_0815C204[0x28], w->unk_280);
#elif defined(VERSION_EU)
    w->unk_78D = LoadTextSlots(eu_0805E924(gUnkEu_08895A00), w->unk_280);
#else
    w->unk_78D = LoadTextSlots(&gUnk_0815C204[0x58], w->unk_280);
#endif
    w->palette = LoadObjPalette(gUnk_09614418, 32);
    w->tiles = LoadObjTiles(gUnk_093F8C8E, 0xC00);
    w->palette2 = LoadObjPalette(gUnk_09611AB8, 32);
#ifdef VERSION_JP
    w->unk_78E = LoadTextSlots((u8*)gUnk_0903BFD4 + 0x30, w->unk_500);
    w->x = (233 - GetTextSlotsWidth(w, w->unk_78C) - GetTextSlotsWidth(w->unk_500, w->unk_78E)) / 2;
    w->x3 = w->x + GetTextSlotsWidth(w, w->unk_78C);
    w->y3 = 66;
    w->y = 66;
    w->x2 = (243 - GetTextSlotsWidth(w->unk_280, w->unk_78D)) / 2;
    w->y2 = 82;
#else
    w->x = (240 - GetTextSlotsWidth(w, w->unk_78C)) / 2;
#ifdef VERSION_EU
    w->x2 = (240 - GetTextSlotsWidth(w->unk_280, w->unk_78D)) / 2;
    if (gLanguage - 1 <= 1) {
        w->y = 66;
        w->y2 = 82;
    } else {
        w->y = 82;
        w->y2 = 66;
    }
#else
    w->y = 82;
    w->x2 = (240 - GetTextSlotsWidth(w->unk_280, w->unk_78D)) / 2;
    w->y2 = 66;
#endif
#endif
    w->unk_790 = 0;
    w->unk_7A4 = 0;
    w->unk_7A0 = a;
    *a = 1;
}
void func_080A2980(DeckConfirmWork* w, u8* a) {
    w->unk_78C = 0;
    w->unk_78D = 0;
    w->unk_78E = 0;
    InitTextSlots(w, 0x50);
    InitTextSlots(w->unk_280, 0x50);
    InitTextSlots(w->unk_500, 0x50);
#ifdef VERSION_JP
    w->unk_78C = 0;
    w->unk_78D = LoadTextSlots(&gUnk_0815C204[0x40], w->unk_280);
#elif defined(VERSION_EU)
    w->unk_78D = LoadTextSlots(eu_0805E924(gUnkEu_08895AF4), w->unk_280);
#else
    w->unk_78D = LoadTextSlots(&gUnk_08159F38[0x2A], w->unk_280);
#endif
    w->palette = LoadObjPalette(gUnk_09614418, 32);
    w->tiles = LoadObjTiles(gUnk_093F8C8E, 0xC00);
    w->palette2 = LoadObjPalette(gUnk_09611AB8, 32);
#ifdef VERSION_JP
    w->x2 = (207 - GetTextSlotsWidth(w->unk_280, w->unk_78D)) / 2;
    w->y2 = 62;
#elif defined(VERSION_EU)
    w->x2 = (240 - eu_0806629C(w->unk_280, w->unk_78D)) / 2;
    w->y2 = 68;
#else
    w->x2 = (240 - GetTextSlotsWidth(w->unk_280, w->unk_78D)) / 2;
    w->y2 = 68;
#endif
    w->unk_790 = 0;
    w->unk_7A4 = 0;
    w->unk_7A0 = a;
    a[0] = 1;
}

void func_080A2A80(DeckConfirmWork* w, u8* a) {
    w->unk_78C = 0;
    w->unk_78D = 0;
    InitTextSlots(w, 0x50);
    InitTextSlots(w->unk_280, 0x50);
    InitTextSlots(w->unk_500, 0x50);
#ifdef VERSION_JP
    w->unk_78C = 0;
    w->unk_78D = LoadTextSlots(&gUnk_0815C204[0x80], w->unk_280);
#elif defined(VERSION_EU)
    w->unk_78D = LoadTextSlots(eu_0805E924(gUnkEu_08895C30), w->unk_280);
#else
    w->unk_78D = LoadTextSlots(&gUnk_0815C204[0xEA], w->unk_280);
#endif
    w->palette = LoadObjPalette(gUnk_09614418, 32);
    w->tiles = LoadObjTiles(gUnk_093F8C8E, 0xC00);
    w->palette2 = LoadObjPalette(gUnk_09611AB8, 32);
    w->x = (250 - GetTextSlotsWidth(w, w->unk_78C)) / 2;
    w->y = 64;
#ifdef VERSION_JP
    w->x2 = (219 - GetTextSlotsWidth(w->unk_280, w->unk_78D)) / 2;
#elif defined(VERSION_EU)
    w->x2 = (240 - eu_0806629C(w->unk_280, w->unk_78D)) / 2;
#else
    w->x2 = (240 - GetTextSlotsWidth(w->unk_280, w->unk_78D)) / 2;
#endif
    w->y2 = 62;
    w->unk_790 = 0;
    w->unk_7A4 = 0;
    w->unk_7A0 = a;
    a[0] = 1;
}
#ifdef VERSION_JP
extern u8 gUnk_0814FBB0[];
extern u8 gUnk_0814FBBC[];
extern u8 gUnk_0814FBD4[];
#endif
void func_080A2BA4(DeckConfirmWork* w, u8* a) {
    w->unk_78C = 0;
    w->unk_78D = 0;
    InitTextSlots(w, 0x50);
    InitTextSlots(w->unk_280, 0x50);
    InitTextSlots(w->unk_500, 0x50);
#ifdef VERSION_JP
    w->unk_78C = LoadTextSlots(gUnk_0814FBB0, w);
    w->unk_78D = LoadTextSlots(gUnk_0814FBBC, w->unk_280);
#elif defined(VERSION_EU)
    w->unk_78D = LoadTextSlots(eu_0805E924(gUnkEu_08895CF8), w->unk_280);
#else
    w->unk_78D = LoadTextSlots(&gUnk_0815C204[0xA8], w->unk_280);
#endif
    w->palette = LoadObjPalette(gUnk_09614418, 32);
    w->tiles = LoadObjTiles(gUnk_093F8C8E, 0xC00);
    w->palette2 = LoadObjPalette(gUnk_09611AB8, 32);
    w->x = (242 - GetTextSlotsWidth(w, w->unk_78C)) / 2;
    w->y = 66;
    w->x2 = (242 - GetTextSlotsWidth(w->unk_280, w->unk_78D)) / 2;
#ifdef VERSION_JP
    w->y2 = 82;
#else
    w->y2 = 68;
#endif
    w->unk_790 = 0;
    w->unk_7A4 = 0;
    w->unk_7A0 = a;
    a[0] = 1;
}

void func_080A2CC4(DeckConfirmWork* w, u8* a) {
    w->unk_78C = 0;
    w->unk_78D = 0;
    InitTextSlots(w, 0x50);
    InitTextSlots(w->unk_280, 0x50);
    InitTextSlots(w->unk_500, 0x50);
#ifdef VERSION_JP
    w->unk_78C = LoadTextSlots(gUnk_0814FBB0, w);
    w->unk_78D = LoadTextSlots(gUnk_0814FBD4, w->unk_280);
#elif defined(VERSION_EU)
    w->unk_78D = LoadTextSlots(eu_0805E924(gUnkEu_08895DBC), w->unk_280);
#else
    w->unk_78D = LoadTextSlots(&gUnk_0815C204[0x6C], w->unk_280);
#endif
    w->palette = LoadObjPalette(gUnk_09614418, 32);
    w->tiles = LoadObjTiles(gUnk_093F8C8E, 0xC00);
    w->palette2 = LoadObjPalette(gUnk_09611AB8, 32);
    w->x = (243 - GetTextSlotsWidth(w, w->unk_78C)) / 2;
    w->y = 66;
    w->x2 = (243 - GetTextSlotsWidth(w->unk_280, w->unk_78D)) / 2;
#ifdef VERSION_JP
    w->y2 = 82;
#else
    w->y2 = 68;
#endif
    w->unk_7A4 = 0;
    w->unk_790 = 0;
    w->unk_7A0 = a;
    a[0] = 1;
}

s32 func_080A2DE4(void) {
    if ((GetKeysPressed() & 1) || (GetKeysPressed() & 8) ||
        (GetKeysPressed() & 2)) {
        return 0;
    }

    return 1;
}

void func_080A2E14(DeckConfirmWork* w) {
    DrawTextSlots(w->x, w->y, w, w->palette, 1, w->unk_78C);
    DrawTextSlots(w->x2, w->y2, w->unk_280, w->palette, 1, w->unk_78D);
    DrawTextSlots(w->x3, w->y3, w->unk_500, w->palette, 1, w->unk_78E);
    DrawSprite(120, 80, gUnk_09EF1278[0], w->tiles, w->palette2, 0, 0, 2);
}

void func_080A2EF8(DeckConfirmWork* w) {
    FreeTextSlots(w, 80);
    FreeTextSlots(w->unk_280, 80);
    FreeTextSlots(w->unk_500, 80);
    ReleaseObjPalette(w->palette);
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette2);
    w->unk_7A0[0] = 0;
}
#ifdef VERSION_JP
#define DECK_PROMPT_LEFT_DX 30
#define DECK_PROMPT_RIGHT_DX 35
#define DECK_CLEAR_TEXT_Y 66
#else
#define DECK_PROMPT_LEFT_DX 20
#define DECK_PROMPT_RIGHT_DX 20
#define DECK_CLEAR_TEXT_Y 61
#endif
void Deck_Yes_No_0(DeckConfirmWork* w, u8* a) {
    w->unk_78C = 0;
    w->unk_78D = 0;
    InitTextSlots(w, 0x50);
    InitTextSlots(w->unk_280, 0x50);
    InitTextSlots(w->unk_500, 0x50);
#ifdef VERSION_EU
    w->unk_78C = LoadTextSlots(eu_0805E924(gUnkEu_08890EC0), w);
    w->unk_78D = LoadTextSlots(eu_0805E924(gUnkEu_08890E1C), w->unk_280);
    w->unk_78E = LoadTextSlots(eu_0805E924(gUnkEu_08890E44), w->unk_500);
#else
    w->unk_78C = LoadTextSlots(gUnk_08159FBC, w);
    w->unk_78D = LoadTextSlots(gUnk_08159E10, w->unk_280);
    w->unk_78E = LoadTextSlots(gUnk_08159E18, w->unk_500);
#endif
    w->palette = LoadObjPalette(gUnk_09614418, 32);
    w->tiles = LoadObjTiles(gUnk_093F8C8E, 0xC00);
    w->palette2 = LoadObjPalette(gUnk_09611AB8, 32);
    w->x = (240 - GetTextSlotsWidth(w, w->unk_78C)) / 2;
    w->y = 66;
    w->x2 = (240 - GetTextSlotsWidth(w->unk_280, w->unk_78D)) / 2 - DECK_PROMPT_LEFT_DX;
    w->y2 = 88;
    w->x3 = (240 - GetTextSlotsWidth(w->unk_500, w->unk_78E)) / 2 + DECK_PROMPT_RIGHT_DX;
    w->y3 = 88;
    w->unk_790 = 0;
    w->unk_7A4 = 0;
    w->unk_7A0 = a;
    a[0] = 1;
}
s32 func_080A30C0(void) {
    if ((GetKeysPressed() & 1) || (GetKeysPressed() & 2)) {
        return 0;
    }

    return 1;
}
void Deck_Clear_0(DeckConfirmWork* w, u8* a) {
    w->unk_78C = 0;
    w->unk_78D = 0;
    InitTextSlots(w, 0x50);
    InitTextSlots(w->unk_280, 0x50);
    InitTextSlots(w->unk_500, 0x50);
#ifdef VERSION_EU
    w->unk_78C = LoadTextSlots(eu_0805E924(gUnkEu_08895E94), w);
    w->unk_78D = LoadTextSlots(eu_0805E924(gUnkEu_08890E1C), w->unk_280);
    w->unk_78E = LoadTextSlots(eu_0805E924(gUnkEu_08890E44), w->unk_500);
#else
    w->unk_78C = LoadTextSlots(gUnk_0815C1C2, w);
    w->unk_78D = LoadTextSlots(gUnk_08159E10, w->unk_280);
    w->unk_78E = LoadTextSlots(gUnk_08159E18, w->unk_500);
#endif
    w->palette = LoadObjPalette(gUnk_09614418, 32);
    w->tiles = LoadObjTiles(gUnk_093F8C8E, 0xC00);
    w->palette2 = LoadObjPalette(gUnk_09611AB8, 32);
    w->x = (240 - GetTextSlotsWidth(w, w->unk_78C)) / 2;
    w->x2 = (240 - GetTextSlotsWidth(w->unk_280, w->unk_78D)) / 2 - DECK_PROMPT_LEFT_DX;
    w->y2 = 88;
    w->x3 = (240 - GetTextSlotsWidth(w->unk_280, w->unk_78E)) / 2 + DECK_PROMPT_RIGHT_DX;
    w->y3 = 88;
    w->y = DECK_CLEAR_TEXT_Y;
    w->unk_790 = 0;
    w->unk_7A4 = 0;
    w->unk_7A0 = a;
    a[0] = 1;
}

void func_080A324C(UnkStruct_080A324C* p) {
    s32 i;

    for (i = 0; i < 270; i++) {
        p->unk_001[i] = gUnk_0203A8C0[i];
    }

    for (i = 0; i < 999; i++) {
        p->unk_110[i] = gCardCollection[i];
    }

    for (i = 0; i < 3; i++) {
        memcpy(&p->unk_8E0[i], &gDecks[i], sizeof(Deck));
    }

    p->unk_8DE = gCardCount;
    p->unk_000 = GetActiveDeckIndex();
}

void func_080A32DC(u8* p) {
    u16 i;
    u8* src;
    u8* dst;
    u8* src2;
    u16* dst2;
    Deck* dst3;
    u8* src3;
    Deck* d;

    for (i = 0; i < 0x10E; i++) {
        dst = gUnk_0203A8C0;
        src = &p[1];
        dst[i] = src[i];
    }

    for (i = 0; i < 0x3E7; i++) {
        dst2 = gCardCollection;
        src2 = &p[0x110];
        dst2[i] = *(u16*)(src2 + (i << 1));
    }

    for (i = 0; i < 3; i++) {
        dst3 = gDecks;
        d = &dst3[i];
        src3 = &p[i * 0xE0];
        memcpy(d, &src3[0x8E0], 0xE0);
    }

    gCardCount = *(u16*)&p[0x8DE];
    SetActiveDeckIndex(p[0]);
}

void CopyMapCardInventory(u8* p) {
    s32 i;

    for (i = 0; i <= 0x10D; i++) {
        p[i] = gUnk_0203A8C0[i];
    }
}
void RestoreMapCardInventory(u8* p) {
    u16 i;

    for (i = 0; i <= 0x10D; i++) {
        gUnk_0203A8C0[i] = p[i];
    }
}

const char gTaskNameDeckEquip[] = "Deck Equip";

TaskDesc gTaskDescDeckEquip = {
    gTaskNameDeckEquip,
    (void (*)(void*, void*))Deck_Equip_0,
    func_080A2DE4,
    (void (*)(void*))func_080A2E14,
    (void (*)(void*))func_080A2EF8,
    0x7A8,
};

const char gTaskNameDeckYesNo[] = "Deck_Yes_No";

TaskDesc gTaskDescDeckYesNo = {
    gTaskNameDeckYesNo,
    (void (*)(void*, void*))Deck_Yes_No_0,
    func_080A30C0,
    (void (*)(void*))func_080A2E14,
    (void (*)(void*))func_080A2EF8,
    0x7A8,
};

const char gTaskNameDeckClear[] = "Deck_Clear";

TaskDesc gTaskDescDeckClear = {
    gTaskNameDeckClear,
    (void (*)(void*, void*))Deck_Clear_0,
    func_080A30C0,
    (void (*)(void*))func_080A2E14,
    (void (*)(void*))func_080A2EF8,
    0x7A8,
};

const char gTaskNameDeckError[] = "Deck Error";

TaskDesc gUnk_09EE7FA8 = {
    gTaskNameDeckError,
    (void (*)(void*, void*))func_080A2980,
    func_080A2DE4,
    (void (*)(void*))func_080A2E14,
    (void (*)(void*))func_080A2EF8,
    0x7A8,
};

TaskDesc gUnk_09EE7FC0 = {
    gTaskNameDeckError,
    (void (*)(void*, void*))func_080A2A80,
    func_080A2DE4,
    (void (*)(void*))func_080A2E14,
    (void (*)(void*))func_080A2EF8,
    0x7A8,
};

TaskDesc gUnk_09EE7FD8 = {
    gTaskNameDeckError,
    (void (*)(void*, void*))func_080A2BA4,
    func_080A2DE4,
    (void (*)(void*))func_080A2E14,
    (void (*)(void*))func_080A2EF8,
    0x7A8,
};

TaskDesc gUnk_09EE7FF0 = {
    gTaskNameDeckError,
    (void (*)(void*, void*))func_080A2CC4,
    func_080A2DE4,
    (void (*)(void*))func_080A2E14,
    (void (*)(void*))func_080A2EF8,
    0x7A8,
};
#ifdef VERSION_EU
u8* gUnkEu_09F73464[5] = { gUnkEu_090D1DA5, gUnkEu_090D1DA5, gUnkEu_090D1DA5, gUnkEu_090D1DA5, gUnkEu_090D1DA5 };
#endif
