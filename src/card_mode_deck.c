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

#ifndef VERSION_EU
u8 gUnk_02034B08[20];

u8 gUnk_02034B1C;

u8 gUnk_02034B1D[3];
#endif

void func_080AB22C(u8 a);
void func_080AB334(u8 a);
void func_080AB4AC(u8 a);
void func_080AB1F8(u8 a, u16 b);
void func_080AB964(void);
void func_080AB968(void);
s16 func_08084458(u16 cardId);
u8 AddCardToActiveDeck(u16 card);
void SetActiveDeckIndex(u8 index);
u8 GetActiveDeckIndex(void);
#ifndef VERSION_EU
void func_080AAF78(void) {
    gUnk_02034B1C = 0;
    gUnk_0203A9DC = 2048;
    TaskPoolInit(gUnk_02034B08, 1);
    TaskCreate(gUnk_02034B08, &gTaskDescDeckexchange, &gUnk_02034B1C);
}
void func_080AAFB4(void) {
    if (gSystemFlags & 1) {
        func_080B31A0();
    } else {
        UpdatePlayTime();
    }

    TaskPoolUpdate(gUnk_02034B08);
    TaskPoolDraw(gUnk_02034B08);

    if (gUnk_02034B1C == 6) {
        ModeRequest(&gModeSioChgCard, gUnk_0203A9DC);
    }
}
void func_080AB008(void) {
    TaskPoolDestroy(gUnk_02034B08);
}
#endif
void DarkPoint_0(DarkPointWork* w) {
    w->tiles = LoadObjTiles(gUnk_093FB6C4, 576);
    w->slideTimer = 8;
    w->x = -0x2000;
    func_0806BA0C(gBtlWork->unk_1C8, &w->unk_0B);
}
s32 DarkPoint_1(DarkPointWork* w) {
    func_0806BA0C(gBtlWork->unk_1C8, &w->unk_0B);

    if (w->slideTimer > 0) {
        ApproachValue(&w->x, 0, (u16)w->slideTimer);
        w->slideTimer--;
    }

    return 1;
}
void DarkPoint_2(DarkPointWork* w) {
    DrawSprite(w->x >> 8, 27, gUnk_09EF1298[0], w->tiles, gUnk_02039DD4->palette, 0, 0, 30);

    if (w->hundreds != 0) {
        DrawSprite((w->x >> 8) + 11, 30, gUnk_09EF1298[w->hundreds + 1], w->tiles, gUnk_02039DD4->palette, 0, 0, 29);
        DrawSprite((w->x >> 8) + 17, 30, gUnk_09EF1298[w->tens + 1], w->tiles, gUnk_02039DD4->palette, 0, 0, 29);
        DrawSprite((w->x >> 8) + 23, 30, gUnk_09EF1298[w->ones + 1], w->tiles, gUnk_02039DD4->palette, 0, 0, 29);
    } else if (w->tens != 0) {
        DrawSprite((w->x >> 8) + 15, 30, gUnk_09EF1298[w->tens + 1], w->tiles, gUnk_02039DD4->palette, 0, 0, 29);
        DrawSprite((w->x >> 8) + 21, 30, gUnk_09EF1298[w->ones + 1], w->tiles, gUnk_02039DD4->palette, 0, 0, 29);
    } else {
        DrawSprite((w->x >> 8) + 17, 30, gUnk_09EF1298[w->ones + 1], w->tiles, gUnk_02039DD4->palette, 0, 0, 29);
    }
}
void DarkPoint_3(void** p) {
    ReleaseObjTiles(p[0]);
}

void func_080AB1F8(u8 a, u16 b) {
    u8 saved;

    saved = GetActiveDeckIndex();
    SetActiveDeckIndex(a);
    AddCardToActiveDeck(b);
    SetActiveDeckIndex(saved);
}
#ifdef VERSION_EU
void func_080AB228(void) {
    u16 i;
    u16 n;

    n = 0;
    gCardCount = 999;

    for (i = 0; i < 170; i++) {
        gCardCollection[n++] = i;
    }

    for (i = 170; i < 380; i++) {
        gCardCollection[n++] = i;
    }

    for (i = 380; i < 450; i++) {
        gCardCollection[n++] = i;
    }

    for (i = 380; i < 450; i++) {
        gCardCollection[n++] = i;
    }

    for (i = 450; i < 526; i += 3) {
        gCardCollection[n++] = i;
    }

    gCardCollection[n++] = 528;
    gCardCollection[n++] = 529;
    gCardCollection[n++] = 532;
    gCardCollection[n++] = 535;
    gCardCollection[n++] = 538;
    gCardCollection[n++] = 541;
    gCardCollection[n++] = 543;
    gCardCollection[n++] = 542;
    gCardCollection[n++] = 544;
    gCardCollection[n++] = 545;
    gCardCollection[n++] = 551;
    gCardCollection[n++] = 552;
    gCardCollection[n++] = 553;
    gCardCollection[n++] = 554;
    gCardCollection[n++] = 555;
    gCardCollection[n++] = 556;
    gCardCollection[n++] = 557;
    gCardCollection[n++] = 558;
    gCardCollection[n++] = 559;
    gCardCollection[n++] = 560;
    gCardCollection[n++] = 561;
    gCardCollection[n++] = 563;
    gCardCollection[n++] = 564;

    for (i = 0; i < 170; i++) {
        if (n < 999) {
            gCardCollection[n++] = i | 0x8000;
        }
    }

    for (i = 170; i < 240; i++) {
        if (n < 999) {
            gCardCollection[n++] = i | 0x8000;
        }
    }

    for (i = 0; i < 95; i++) {
        gCardCollection[n++] = 6;
    }
}
#else
void func_080AB228(void) {
}
#endif
void func_080AB22C(u8 a) {
    func_080AB1F8(a, 0);
    func_080AB1F8(a, 1);
    func_080AB1F8(a, 2);
    func_080AB1F8(a, 3);
    func_080AB1F8(a, 4);
    func_080AB1F8(a, 5);
    func_080AB1F8(a, 6);
    func_080AB1F8(a, 7);
    func_080AB1F8(a, 8);
    func_080AB1F8(a, 9);
    func_080AB1F8(a, 73);
    func_080AB1F8(a, 74);
    func_080AB1F8(a, 75);
    func_080AB1F8(a, 76);
    func_080AB1F8(a, 77);
    func_080AB1F8(a, 78);
    func_080AB1F8(a, 79);
    func_080AB1F8(a, 80);
    func_080AB1F8(a, 81);
    func_080AB1F8(a, 82);
    func_080AB1F8(a, 83);
    func_080AB1F8(a, 84);
    func_080AB1F8(a, 85);
    func_080AB1F8(a, 86);
    func_080AB1F8(a, 87);
    func_080AB1F8(a, 88);
    func_080AB1F8(a, 89);
    func_080AB1F8(a, 90);
    func_080AB1F8(a, 91);
    func_080AB1F8(a, 92);
    func_080AB1F8(a, 93);
}

void func_080AB334(u8 a) {
    func_080AB1F8(a, func_08084458(5));
    func_080AB1F8(a, func_08084458(7));
    func_080AB1F8(a, func_08084458(4));
    func_080AB1F8(a, func_08084458(5));
    func_080AB1F8(a, func_08084458(4));
    func_080AB1F8(a, func_08084458(3));
    func_080AB1F8(a, func_08084458(4));
    func_080AB1F8(a, func_08084458(5));
    func_080AB1F8(a, func_08084458(6));
    func_080AB1F8(a, func_08084458(7));
    func_080AB1F8(a, func_08084458(6));
    func_080AB1F8(a, func_08084458(5));
    func_080AB1F8(a, func_08084458(4));
    func_080AB1F8(a, func_08084458(3));
    func_080AB1F8(a, func_08084458(4));
    func_080AB1F8(a, func_08084458(5));
    func_080AB1F8(a, func_08084458(186));
    func_080AB1F8(a, func_08084458(185));
    func_080AB1F8(a, func_08084458(207));
    func_080AB1F8(a, func_08084458(205));
}

void func_080AB4AC(u8 a) {
    func_080AB1F8(a, 0);
    func_080AB1F8(a, 1);
    func_080AB1F8(a, 2);
    func_080AB1F8(a, 3);
    func_080AB1F8(a, 4);
    func_080AB1F8(a, 5);
    func_080AB1F8(a, 6);
    func_080AB1F8(a, 7);
    func_080AB1F8(a, 8);
    func_080AB1F8(a, 9);
    func_080AB1F8(a, 173);
    func_080AB1F8(a, 176);
    func_080AB1F8(a, 178);
    func_080AB1F8(a, 181);
    func_080AB1F8(a, 184);
    func_080AB1F8(a, 189);
    func_080AB1F8(a, 192);
    func_080AB1F8(a, 195);
    func_080AB1F8(a, 197);
    func_080AB1F8(a, 202);
    func_080AB1F8(a, 204);
    func_080AB1F8(a, 207);
    func_080AB1F8(a, 213);
    func_080AB1F8(a, 216);
    func_080AB1F8(a, 219);
    func_080AB1F8(a, 224);
    func_080AB1F8(a, 225);
    func_080AB1F8(a, 228);
    func_080AB1F8(a, 234);
    func_080AB1F8(a, 235);
    func_080AB1F8(a, 238);
    func_080AB1F8(a, 255);
    func_080AB1F8(a, 257);
    func_080AB1F8(a, 258);
    func_080AB1F8(a, 245);
    func_080AB1F8(a, 247);
    func_080AB1F8(a, 248);
    func_080AB1F8(a, 265);
    func_080AB1F8(a, 267);
    func_080AB1F8(a, 268);
    func_080AB1F8(a, 275);
    func_080AB1F8(a, 277);
    func_080AB1F8(a, 278);
    func_080AB1F8(a, 285);
    func_080AB1F8(a, 287);
    func_080AB1F8(a, 288);
    func_080AB1F8(a, 295);
    func_080AB1F8(a, 297);
    func_080AB1F8(a, 298);
    func_080AB1F8(a, 305);
    func_080AB1F8(a, 307);
    func_080AB1F8(a, 308);
    func_080AB1F8(a, 315);
    func_080AB1F8(a, 317);
    func_080AB1F8(a, 318);
    func_080AB1F8(a, 325);
    func_080AB1F8(a, 327);
    func_080AB1F8(a, 328);
    func_080AB1F8(a, 335);
    func_080AB1F8(a, 337);
    func_080AB1F8(a, 338);
    func_080AB1F8(a, 345);
    func_080AB1F8(a, 347);
    func_080AB1F8(a, 348);
    func_080AB1F8(a, 355);
    func_080AB1F8(a, 357);
    func_080AB1F8(a, 358);
    func_080AB1F8(a, 365);
    func_080AB1F8(a, 367);
    func_080AB1F8(a, 368);
    func_080AB1F8(a, 375);
    func_080AB1F8(a, 377);
    func_080AB1F8(a, 378);
    func_080AB1F8(a, 450);
    func_080AB1F8(a, 459);
    func_080AB1F8(a, 462);
    func_080AB1F8(a, 465);
    func_080AB1F8(a, 468);
    func_080AB1F8(a, 492);
    func_080AB1F8(a, 528);
    func_080AB1F8(a, 529);
    func_080AB1F8(a, 453);
    func_080AB1F8(a, 471);
    func_080AB1F8(a, 474);
    func_080AB1F8(a, 477);
    func_080AB1F8(a, 480);
    func_080AB1F8(a, 486);
    func_080AB1F8(a, 489);
    func_080AB1F8(a, 495);
    func_080AB1F8(a, 501);
    func_080AB1F8(a, 504);
    func_080AB1F8(a, 507);
    func_080AB1F8(a, 510);
    func_080AB1F8(a, 513);
    func_080AB1F8(a, 519);
    func_080AB1F8(a, 522);
}

void func_080AB880(void) {
    func_08084458(7);
    func_08084458(6);
    func_08084458(5);
    func_08084458(5);
    func_08084458(4);
    func_08084458(3);
    func_08084458(4);
    func_08084458(3);
    func_08084458(2);
    func_08084458(2);
    func_08084458(1);
    func_08084458(0);
    func_08084458(185);
    func_08084458(386);
    func_08084458(207);
}

void func_080AB8E4(void) {
    func_080AB1F8(0, 0);
    func_080AB1F8(0, 1);
    func_080AB1F8(0, 2);
    func_080AB1F8(0, 3);
    func_080AB1F8(0, 4);
    func_080AB1F8(0, 5);
    func_080AB1F8(0, 6);
    func_080AB1F8(0, 7);
    func_080AB1F8(0, 8);
    func_080AB1F8(0, 9);
    func_080AB1F8(0, 10);
    func_080AB1F8(0, 11);
    func_080AB1F8(0, 12);
    func_080AB1F8(0, 13);
    func_080AB1F8(0, 14);
}

void func_080AB964(void) {
}

void func_080AB968(void) {
}

#ifndef VERSION_EU
Mode gUnk_09EE8F20 = {
    gUnk_09041F58,
    (void (*)(s32))func_080AAF78,
    func_080AAFB4,
    func_080AB008,
};
#endif

const char gTaskNameDarkPoint[] = "DarkPoint";

TaskDesc gTaskDescDarkPoint = {
    gTaskNameDarkPoint,
    (void (*)(void*, void*))DarkPoint_0,
    DarkPoint_1,
    (void (*)(void*))DarkPoint_2,
    (void (*)(void*))DarkPoint_3,
    0x10,
};

CardDescriptionText* gUnk_09EE8F48[98] = {
#if defined(VERSION_EU)
    &gUnkEu_09F5EA0C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090106C0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042080,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EA20,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090106F4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090420FC,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EA34,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010728,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042176,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EA48,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010760,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090421EE,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EA5C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010794,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904226A,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EA70,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090107CC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090422E4,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EA84,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010800,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904235E,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EA98,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010834,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090423D6,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EAAC,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010868,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042452,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EAC0,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_0901089C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090424CC,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EAD4,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090108D0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904254E,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EAE8,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010904,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090425CA,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EAFC,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010938,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042646,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EB10,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_0901096C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090426C0,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EB24,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090109A0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904273C,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EB38,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090109D8,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090427BC,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EB4C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010A0C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042840,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EB60,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010A40,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904434A,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EB74,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010A6C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042F40,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EB88,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010A8C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042F6A,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EB9C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010AAC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042F92,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EBB0,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010ACC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042FC6,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EBC4,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010AE0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042FDE,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EBD8,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010B10,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090428BC,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EBEC,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010B2C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043042,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EC00,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010B60,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042912,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EC14,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010B84,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904309C,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EC28,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010BB4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042984,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EC3C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010BE4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090429E6,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EC50,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010C0C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042A40,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EC64,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010C38,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090430F0,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EC78,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010C58,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042AA0,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EC8C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010C6C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904315A,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5ECA0,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010CA8,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042AFC,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5ECB4,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010CE4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090431C6,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5ECC8,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010D20,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043230,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5ECDC,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010D5C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904329A,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5ECF0,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010D98,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042B5C,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5ED04,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010DD4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043302,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5ED18,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010E10,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904336A,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5ED2C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010E4C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090433DA,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5ED40,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010E6C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043426,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5ED54,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010E88,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043474,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5ED68,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010EBC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090434E0,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5ED7C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010EF4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043540,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5ED90,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010F08,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043586,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EDA4,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010F30,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09045146,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EDB8,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010F68,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090435E4,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EDCC,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010F94,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043632,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EDE0,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011018,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043746,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EDF4,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_0901111C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090438CA,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EE08,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011144,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904391C,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EE1C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_0901116C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043976,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EE30,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011194,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090439CE,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EE44,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010FB4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043678,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EE58,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09010FE4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090436E0,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EE6C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090111F8,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043A80,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EE80,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090110BC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043814,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EE94,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011050,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090437B0,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EEA8,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011224,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042C02,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EEBC,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090112D8,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043B7C,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EED0,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_0901108C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042BB4,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EEE4,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011344,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043BDE,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EEF8,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011314,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042C88,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EF0C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011248,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042C32,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EF20,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090112B0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043B0E,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EF34,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090110F0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043880,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EF48,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011278,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043AB0,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EF5C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011370,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043C2C,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EF70,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090113D0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043CE2,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EF84,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_0901139C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043C82,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EF98,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090111BC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043A1E,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EFAC,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011500,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043F00,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EFC0,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090113F8,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043D42,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EFD4,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011428,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043DA6,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EFE8,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011460,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043DF0,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5EFFC,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011488,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043E56,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F010,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090114C4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043E9E,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F024,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_0901152C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043F4A,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F038,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011654,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904408C,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F04C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_0901159C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090442E0,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F060,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090116F8,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042D38,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F074,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011810,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042CE4,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F074,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011810,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042CE4,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F088,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011564,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09043FA0,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F09C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090115D8,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042D90,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F0B0,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011638,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044060,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F0C4,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_0901160C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044000,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F0D8,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011684,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090440E6,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F0EC,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090116BC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044160,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F100,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011770,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090441C2,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F114,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011724,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042DF2,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F128,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011754,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042E4C,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F13C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090117AC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904422C,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F150,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090117D4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044282,
#endif
#if defined(VERSION_EU)
    0,
#elif defined(VERSION_JP)
    0,
#elif defined(VERSION_US)
    0,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F164,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011844,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042E7C,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F178,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011870,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09042EEA,
#endif
};

CardDescriptionText* gUnk_09EE90D0[26] = {
#if defined(VERSION_EU)
    &gUnkEu_09F5F18C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011B30,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044886,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F1A0,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011B5C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090448CE,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F1B4,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011B84,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044922,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F1C8,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011BB0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044980,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F1DC,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011BE0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090449D8,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F1F0,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011C18,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044A44,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F204,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011C44,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044A96,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F218,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011C74,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044AF4,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F22C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011CA4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044B56,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F240,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011CB8,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044B8E,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F254,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011CE0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044BEA,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F268,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011D08,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044C48,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F27C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011D3C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044CA2,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F290,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011D70,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044CFE,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F2A4,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011DA4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044D56,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F2B8,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011DE0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044DBE,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F2CC,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011E04,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044E06,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F2E0,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011E40,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044E6E,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F2F4,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011E78,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044EC6,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F308,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011EB4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044F16,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F31C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011EEC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044F80,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F330,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011F1C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044FD4,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F344,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011F48,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09045026,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F358,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011F78,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904506E,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F36C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011FA8,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090450B6,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F380,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011FD8,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090450FE,
#endif
};

CardDescriptionText* gUnk_09EE9138[14] = {
#if defined(VERSION_EU)
    &gUnkEu_09F5F394,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_0901192C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904446C,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F3A8,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090119EC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090445B4,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F3BC,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090119B4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904455E,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F3D0,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011984,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044514,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F3E4,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090118D0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090443B2,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F3F8,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011960,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090444C4,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F40C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090118FC,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_0904440A,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F420,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011A04,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090445FA,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F434,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011AA0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090446FC,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F448,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_090118A0,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090447B6,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F45C,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011A74,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_090446A8,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F470,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011AD4,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044758,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F484,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011A3C,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044654,
#endif
#if defined(VERSION_EU)
    &gUnkEu_09F5F498,
#elif defined(VERSION_JP)
    gCardDescriptionTextJp_09011B04,
#elif defined(VERSION_US)
    gCardDescriptionTextUs_09044816,
#endif
};
