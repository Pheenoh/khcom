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
#include "sprites_btl.h"

void CreateCardNameDisplay(void* a, void* b);
u8 func_08096288(PrizeCardWork* w, void* a);
u8 func_08096390(PrizeCardWork* w);
u8 func_0809612C(PrizeCardWork* w, void* a);
u16 func_08096D48(u16 a, s32 b);
s16 func_08084458(u16 cardId);

void PrizeCard_0(PrizeCardWork* w, PrizeCardTaskArgs* p) {
    PrizeCardTaskArgs args;
    CardDef* def;
    CardBack* back;
    u8* q;

    args = *p;
    w->cardId = args.unk_20;
    def = &gCardDefs[args.unk_20];
    w->tiles = LoadObjTiles(def->tiles, 0x300);
    w->palette = LoadObjPalette(def->palette, 32);
    *(CardStat*)&w->unk_20[0x14] = *(CardStat*)&def->unk_1C;

    if (gCardDefs[w->cardId].unk_1E & 12) {
        back = &gUnk_08F709B0[3];
    } else {
        back = &gUnk_08F709B0[w->unk_20[0x22]];
    }

    w->tiles2 = LoadObjTiles(back->tiles, 0x280);
    w->tiles3 = LoadObjTiles(back->tiles3, 0x600);
    w->palette2 = LoadObjPalette(gUnk_09611AB8, 32);
    w->tiles4 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
    w->tiles5 = LoadObjTiles(gUnk_08B22BBC, 0x100);
    w->palette3 = LoadObjPalette(gUnk_08F69BA4, 32);
    w->unk_A8 = args.x;
    w->unk_AC = args.y;
    *(s32*)&w->unk_B0[0] = args.z;
    *(s32*)&w->unk_B0[4] = 0;
    w->unk_F6 = 24;
    func_080DFF4C(&w->unk_A8);
    w->unk_CC = -(GetRandom() % 129 + 0x300);
    w->unk_D0 = GetRandom() % 129 + 0x80;
    w->unk_F4 = GetRandom() % 256;
    w->unk_E0 = 0x80;
    w->unk_E2 = 0x80;
    w->unk_F2 = 0x80;
    w->unk_F7 = 0;
    w->unk_F8 = 0;
    q = &w->collider[0];
    ColliderInit(q, 5, 30, 10);
    ColliderSetDisabled(q, 1);
    ColliderSetPosition(q, w->unk_A8, w->unk_AC, *(s32*)&w->unk_B0[0]);
    w->unk_F9 = 0;
    w->unk_FC[0] = 0;
    w->unk_FA = 0;
    w->unk_FB = 0;
    TaskPoolInit((TaskPool*)w->unk_20, 1);
}
u8 PrizeCard_1(PrizeCardWork* w, void* a) {
    s32 k = 112;
    s16 x;
    s16 y;

    *(FldPos*)&w->unk_B0[8] = *(FldPos*)&w->unk_A8;
    w->unk_CC += 0x38;
    *(s32*)&w->unk_B0[0] += w->unk_CC;
    w->unk_A8 += (gSineTable[(u8)w->unk_F4] * w->unk_D0) >> 8;
    w->unk_AC += (-gSineTable[(u8)w->unk_F4 + 0x40] * w->unk_D0) >> 8;

    if (func_080DFBDC((FldPos*)&w->unk_A8) != 0) {
        w->unk_F4 = w->unk_F4 + k + GetRandom() % 33;

        do {
            w->unk_A8 = *(s32*)&w->unk_B0[8];
            w->unk_AC = *(s32*)&w->unk_B0[0xC];
        } while (0);
    } else {
        *(s32*)&w->unk_B0[4] = func_080DFF1C((FldPos*)&w->unk_A8);
    }

    if (*(s32*)&w->unk_B0[0] - 0x800 > *(s32*)&w->unk_B0[4]) {
        *(s32*)&w->unk_B0[0] = *(s32*)&w->unk_B0[4] - 0x800;
        w->unk_CC = -((w->unk_CC * 217) >> 8);

        if (w->unk_CC > -0x200) {
            w->unk_CC = -0x200;
        }
    }

    if (w->collider[0x2C] != 0) {
        w->unk_FC[0] = 1;
        m4aSongNumStart(0x6A);

        if (w->cardId <= 0x1C1) {
            func_08084458(w->cardId);
        }

        SetTaskUpdate(a, (void*)func_0809612C);
        x = (w->unk_A8 >> 8) - (gUnk_02039BA0->x >> 8);
        y = (w->unk_AC >> 8) + (*(s32*)&w->unk_B0[0] >> 8) - (gUnk_02039BA0->y >> 8);
        w->unk_A8 = x << 8;
        w->unk_AC = y << 8;
        ColliderSetDisabled(&w->collider[0], 1);
        w->unk_FA = 16;
        w->unk_E4 = 50;
        func_080960D8(w);
        return 1;
    }

    ColliderSetPosition(&w->collider[0], w->unk_A8, w->unk_AC, *(s32*)&w->unk_B0[0]);
    w->x = (w->unk_A8 >> 8) - (gUnk_02039BA0->x >> 8);
    w->y2 = (w->unk_AC >> 8) + (*(s32*)&w->unk_B0[0] >> 8) - (gUnk_02039BA0->y >> 8);
    w->x2 = (w->unk_A8 >> 8) - (gUnk_02039BA0->x >> 8);
    w->y = (w->unk_AC >> 8) + (*(s32*)&w->unk_B0[4] >> 8) - (gUnk_02039BA0->y >> 8);
    w->unk_E4 = -0x1004 - (w->unk_AC >> 8) * 4;
    func_08096638(w);
    w->unk_F8 += 2;

    if (w->unk_F9 == 20) {
        ColliderSetDisabled(&w->collider[0], 0);
    }

    if (w->unk_F9 <= 59) {
        w->unk_F9++;
    }

    if (gUnk_02039BA0->flags & 0x40000) {
        return 0;
    }

    return 1;
}
void func_080960D8(PrizeCardWork* w) {
    s32 cx = 0x7800;
    s32 cy = 0x5000;
    s32 v[2];

    v[0] = cx - w->unk_A8;
    v[1] = cy - w->unk_AC;
    w->unk_DC = NormalizeVector2D8(&v[0], &v[1]);
    w->unk_D4 = -v[0];
    w->unk_D8 = -v[1];
    w->unk_D0 = 0x300;
    w->unk_CC = 2;
}
u8 func_0809612C(PrizeCardWork* w, void* a) {
    s32 v[2];

    if (w->unk_D0 < 0) {
        v[0] = 0x7800 - w->unk_A8;
        v[1] = 0x5000 - w->unk_AC;
        NormalizeVector2D8(&v[0], &v[1]);
        w->unk_D4 = -v[0];
        w->unk_D8 = -v[1];

        if (w->unk_DC <= 0x7FF) {
            w->unk_FA = 0;
            w->unk_F6 = 0;
            SetTaskUpdate(a, (void*)func_08096288);
#ifdef VERSION_EU
            CreateCardNameDisplay(&w->unk_20, eu_0805E924(gCardDefs[w->cardId].name));
#else
            CreateCardNameDisplay(&w->unk_20, gCardDefs[w->cardId].name);
#endif
        }
    }

    w->unk_A8 += (w->unk_D4 * w->unk_D0) >> 8;
    w->unk_AC += (w->unk_D8 * w->unk_D0) >> 8;
    w->unk_F6 += 32;
    w->unk_F7 += (64 - w->unk_F7) >> 4;
    w->unk_F8 = 0;
    w->unk_DC = VectorLength2D(0x7800 - w->unk_A8, 0x5000 - w->unk_AC);
    w->unk_D0 -= w->unk_CC;
    w->unk_CC += 2;

    if (w->unk_F2 <= 255) {
        w->unk_F2 += 3;
    }

    w->x = w->unk_A8 >> 8;
    w->y2 = w->unk_AC >> 8;
    func_08096638(w);

    if (gUnk_02039BA0->flags & 0x40000) {
        return 0;
    }

    return 1;
}
u8 func_08096288(PrizeCardWork* w, void* a) {
    s32 v;

    v = w->unk_F6 << 8;
    ApproachValue(&w->unk_F7, 0, w->unk_FA);
    ApproachValue(&v, 0, w->unk_FA);
    ApproachValue(&w->unk_A8, 0x7800, w->unk_FA);
    ApproachValue(&w->unk_AC, 0x5800, w->unk_FA);
    w->unk_F6 = v >> 8;

    if (w->unk_FA != 0) {
        w->unk_FA--;
    }

    if (w->unk_F2 <= 255) {
        w->unk_F2 += 2;
    } else {
        w->unk_F2 = 256;
    }

    w->x = w->unk_A8 >> 8;
    w->y2 = w->unk_AC >> 8;
    func_08096638(w);
    w->unk_FB++;

    if (w->cardId > 0x1C2) {
        if (w->unk_FB == 120) {
            w->unk_FB = 0;
            SetTaskUpdate(a, (void*)func_08096390);
        }
    } else if (w->unk_FB == 30) {
        w->unk_FB = 0;
        SetTaskUpdate(a, (void*)func_08096390);
    }

    TaskPoolUpdate(&w->unk_20);

    if (gUnk_02039BA0->flags & 0x40000) {
        return 0;
    }

    return 1;
}
u8 func_08096390(PrizeCardWork* w) {
    w->unk_F6 += 32;
    w->unk_EA = (gUnk_02039BA0->actor.fieldPosition.x >> 8) - (gUnk_02039BA0->x >> 8);
    w->unk_EC = (gUnk_02039BA0->actor.fieldPosition.y >> 8) + (gUnk_02039BA0->actor.fieldPosition.z >> 8) -
                (gUnk_02039BA0->y >> 8);
    w->x += (w->unk_EA - w->x) >> 3;
    w->y2 += (w->unk_EC - w->y2) >> 3;
    w->unk_E0 -= 10;
    w->unk_E2 -= 10;

    if (w->unk_E0 > 10 && !(gUnk_02039BA0->flags & 0x40000)) {
        return 1;
    }

    return 0;
}
void PrizeCard_2(PrizeCardWork* w) {
    u16 pal;
    s32 affine;
    void* gfx;
    CardBack* back;
    CardDef* def;
    s16 v;
    s32 t;

    t = w->unk_FC[0];
    pal = 0;

    if (t == 0) {
        pal = 0x800;
    }

    if (w->unk_E0 == 0x100 && w->unk_F6 == 0) {
        affine = 0;
    } else {
        affine = AllocObjAffine(w->unk_F6, w->unk_E0, w->unk_E2, 1);
    }

    def = &gCardDefs[w->cardId];
    DrawSprite(w->x, (u16)w->y2 - 8, def->gfx, w->tiles, w->palette,
               affine, pal, (u16)(w->unk_E4 + 1));
    back = &gUnk_08F709B0[w->unk_20[0x22]];
    DrawSprite(w->x, (u16)w->y2 - 8, back->gfx, w->tiles2, w->palette2,
               affine, pal, (u16)w->unk_E4);
    gfx = gUnk_09EE981C[w->unk_20[0x18]];
    DrawSprite(w->x, (u16)w->y2 - 8, gfx, w->tiles4, w->palette2, affine,
               pal, (u16)(w->unk_E4 - 1));

    if (w->unk_FC[0] == 0) {
        v = 204 - ((*(s32*)&w->unk_B0[4] - *(s32*)&w->unk_B0[0]) >> 7);

        if (v <= 2) {
            v = 2;
        }

        DrawSprite(w->x2, w->y, gUnk_09EE1380[0],
                   w->tiles5, w->palette3, AllocObjAffine(0, v, v, 0), pal,
                   (u16)(w->unk_E4 + 2));
    }

    TaskPoolDraw(w->unk_20);
}

void PrizeCard_3(PrizeCardWork* w) {
    FadeSetPaletteExcluded(w->palette2->index + 16, 0);
    FadeSetPaletteExcluded(w->palette->index + 16, 0);
    ColliderUnregister(w->collider);
    ReleaseObjTiles(w->tiles);
    ReleaseObjTiles(w->tiles2);
    ReleaseObjTiles(w->tiles4);
    ReleaseObjTiles(w->tiles3);
    ReleaseObjTiles(w->tiles5);
    ReleaseObjPalette(w->palette);
    ReleaseObjPalette(w->palette2);
    ReleaseObjPalette(w->palette3);
    TaskPoolDestroy(w->unk_20);
}

void func_08096638(PrizeCardWork* w) {
    w->unk_E0 = (-gSineTable[((w->unk_F8 + 0x80) & 0xFF) + 0x40] * w->unk_F2) >> 8;
    w->unk_E2 = (-gSineTable[((w->unk_F7 + 0x80) & 0xFF) + 0x40] * w->unk_F2) >> 8;

    if ((u16)(w->unk_E0 + 2) <= 4) {
        w->unk_E0 = 2;
    }

    if ((u16)(w->unk_E2 + 2) <= 4) {
        w->unk_E2 = 2;
    }
}

void func_080966B4(void* a, s32 b, s32 c, s32 d) {
    s32 args[9];

    args[0] = b;
    args[1] = c;
    args[2] = d;
    args[8] = func_08096D48(gGameState.world, 0);
    func_08096700(a, args);
}
void func_080966E4(void* a, s32 b, s32 c, s32 d, s32 e) {
    s32 args[9];

    args[0] = b;
    args[1] = c;
    args[2] = d;
    args[8] = e;
    func_08096700(a, args);
}

void func_08096700(void* a, void* b) {
    TaskCreate(a, &gUnk_09EE75D8, b);
}

const char gTaskName_09EE75D8[] = "PrizeCard";

TaskDesc gUnk_09EE75D8 = {
    gTaskName_09EE75D8,
    (void (*)(void*, void*))PrizeCard_0,
    PrizeCard_1,
    (void (*)(void*))PrizeCard_2,
    (void (*)(void*))PrizeCard_3,
    0x100,
};
