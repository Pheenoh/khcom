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
