#include "macros.h"
#include "card_localized_data.h"
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
#include "sprites_card_pictures.h"

s32 func_0809CBD0(u8* work);
void func_0809CAC8(void* work);
void func_0809C9A4(UnkStruct_0809C9A4* p);
void func_0809CA1C(u8* work);
u8 func_0809C9F4(UnkStruct_0809C9A4* p);
u8 func_0809CB78(u8* work, void* a);

const s16 gUnk_09036278[9] = { 0, 11, 23, 34, 46, 57, 68, 79, 90 };

const u8 gUnk_0903628A[9] = { 6, 4, 2, 0, 2, 4, 6, 8, 12 };

void func_0809C534(UnkStruct_0809C534* w, UnkStruct_0809C534_Args* a) {
    CardDef* def;

    w->unk_54 = 0;
    w->tiles4 = 0;

    if (a->unk_06 <= 8) {
        w->unk_4E = gUnk_09036278[a->unk_06];
    } else {
        w->unk_4E = 0xFFE0;
    }

    w->unk_52 = a->unk_06;
    w->unk_48 = a->unk_04;
    def = &gCardDefs[a->cardId];
    w->cardDef = def;

    if (def->flags & 0xC) {
        w->cardBack = &gUnk_08F709B0[1];
    } else {
        w->cardBack = &gUnk_08F709B0[def->unk_2A];
    }

    w->unk_50 = 0;
    func_0809C9A4((UnkStruct_0809C9A4*)w);
    ListNodeInit(&w->node, &gCardListWork->cards, w);
    ListPoolAppend(&w->node, &gCardListWork->cards);
    w->unk_55 = 0;
    w->scaleX = 0x100;
    w->scaleY = 0x100;
    w->x2 = 0;
    w->y2 = 0;
    w->unk_53 = 32;
    w->unk_74 = 0;
}
u8 func_0809C620(u8* work, void* a) {
    s32 v;
    u8 (*fn)(u8*, void*);
    u16 lim;

    v = *(s16*)&work[0x4E] << 8;

    if (*(s8*)&work[0x52] <= 8) {
        ApproachValue(&v, gUnk_09036278[*(s8*)&work[0x52]] << 8, work[0x53]);
        *(s16*)&work[0x4E] = v >> 8;
    } else {
        lim = 0xFFE0;
        *(u16*)&work[0x4E] = lim;
    }

    if (work[0x53] != 0) {
        work[0x53]--;
    }

    func_0809C9A4((UnkStruct_0809C9A4*)work);

    if (func_0809C9F4((UnkStruct_0809C9A4*)work)) {
        func_0809CA1C(work);
    } else {
        func_0809CAC8(work);
    }

    if ((s8)work[0x52] == 3) {
        gCardListWork->selectedCard = (UnkStruct_0809C534*)work;
    }

    switch (work[0x55]) {
    case 2:
        gCardListWork->unk_29 = 0;
        work[0x53] = 8;
        fn = func_0809CB0C;
        SetTaskUpdate(a, (TaskUpdateFunc)fn);
        return fn(work, a);
    case 3:
        work[0x53] = 10;
        SetTaskUpdate(a, (TaskUpdateFunc)func_0809CBF8);
        break;
    }

    return 1;
}

u8 func_0809C710(u8* work, void* a) {
    s32 v;

    v = *(s16*)&work[0x50] << 8;
    ApproachValue(&v, 0x6800, work[0x53]);
    *(s16*)&work[0x50] = v >> 8;
    work[0x53]--;
    func_0809C9A4((UnkStruct_0809C9A4*)work);

    if ((s8)work[0x52] <= 8) {
        func_0809CA1C(work);
    } else {
        func_0809CAC8(work);
    }

    if (work[0x53] == 0) {
        work[0x55] = 1;
        SetTaskUpdate(a, (TaskUpdateFunc)func_0809C620);
    }

    return 1;
}

void func_0809C78C(UnkStruct_0809C534* w) {
    s32 affine;

    if (w->unk_55 == 0xFF) {
        return;
    }

    if (w->unk_54 != 0) {
        affine = AllocObjAffine(0, w->scaleX, w->scaleY, 1);
        DrawSprite(w->x + w->x2, w->y + w->y2, w->cardDef->gfx, w->tiles, w->palette2, affine, 0x400,
                   gUnk_0903628A[w->unk_52] + 70);
        DrawSprite(w->x + w->x2, w->y + w->y2, w->cardBack->gfx, w->tiles2, w->palette3, affine, 0x400,
                   gUnk_0903628A[w->unk_52] + 69);

        if (w->unk_74 == 0) {
            DrawSprite(w->x + w->x2, w->y + w->y2, gUnk_09EE981C[w->cardDef->unk_20], w->tiles3, w->palette3,
                       affine, 0x400, gUnk_0903628A[w->unk_52] + 68);
        } else {
            DrawSprite(w->x + w->x2, w->y + w->y2, gUnk_09EE9894[w->cardDef->unk_20], w->tiles5, w->palette,
                       affine, 0x400, gUnk_0903628A[w->unk_52] + 68);
        }
    }

    if (w->unk_55 == 2 && w->tiles4 != 0) {
        DrawSprite(w->x + w->x2, w->y + w->y2, w->gfx, w->tiles4, w->palette3, 0, 0x400,
                   gUnk_0903628A[w->unk_52] + 67);
    }
}
void func_0809C98C(void** work) {
    func_0809CAC8(work);

    if (work[6] != 0) {
        ReleaseObjTiles(work[6]);
    }
}

void func_0809C9A4(UnkStruct_0809C9A4* p) {
    p->unk_4A = (gSineTable[p->angle] * p->unk_50) >> 8;
    p->unk_4C = ((-gSineTable[p->angle + 64] * p->unk_50) >> 8) + 160;
}

u8 func_0809C9F4(UnkStruct_0809C9A4* p) {
    if (p->unk_4A >= 0) {
        if (p->unk_4A <= 240) {
            if (p->unk_4C >= 0) {
                if (p->unk_4C <= 160) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

void func_0809CA1C(u8* work) {
    if (work[0x54] == 0) {
        *(void**)&work[0x0C] = LoadObjTiles(((void**)*(void**)&work[4])[3], 0x280);
        *(void**)&work[0x28] = LoadObjPalette(gUnk_09611AB8, 32);
        *(void**)&work[0x08] = LoadObjTiles(((void**)*(void**)&work[0])[1], 0x200);
        *(void**)&work[0x24] = LoadObjPalette(((void**)*(void**)&work[0])[2], 32);
        *(void**)&work[0x10] = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
        *(void**)&work[0x1C] = LoadObjTiles(gUnk_0905ED36, 0x140);
        *(void**)&work[0x20] = LoadObjPalette(gUnk_08F69BA4, 32);
        FadeSetPaletteExcluded((*(UnkStruct_080038C8**)&work[0x20])->index + 16, 1);
        FadeSetPaletteExcluded((*(UnkStruct_080038C8**)&work[0x28])->index + 16, 1);
        FadeSetPaletteExcluded((*(UnkStruct_080038C8**)&work[0x24])->index + 16, 1);
        work[0x54] = 1;
    }
}

void func_0809CAC8(void* p) {
    u8* work;

    work = (u8*)p;

    if (work[0x54] != 0) {
        ReleaseObjTiles(*(void**)&work[0x0C]);
        ReleaseObjPalette(*(void**)&work[0x28]);
        ReleaseObjTiles(*(void**)&work[0x08]);
        ReleaseObjPalette(*(void**)&work[0x24]);
        ReleaseObjTiles(*(void**)&work[0x10]);
        ReleaseObjPalette(*(void**)&work[0x20]);
        ReleaseObjTiles(*(void**)&work[0x1C]);
        work[0x54] = 0;
    }
}

u8 func_0809CB0C(u8* work, void* a) {
    s32 x;
    s32 y;

    x = *(s16*)&work[0x4A] << 8;
    y = *(s16*)&work[0x4C] << 8;
    ApproachValue(&x, 0x7800, work[0x53]);
    ApproachValue(&y, 0x4600, work[0x53]);
    *(s16*)&work[0x4A] = x >> 8;
    *(s16*)&work[0x4C] = y >> 8;
    work[0x53]--;

    if (work[0x53] == 0) {
        SetTaskUpdate(a, (TaskUpdateFunc)func_0809CB78);
    }

    return 1;
}

u8 func_0809CB78(u8* work, void* a) {
    *(void**)&work[0x18] = AllocObjTiles(640, 0);
    SetObjTileSource(*(void**)&work[0x18], gUnk_0908B1B4);
    AnimInit(&work[0x2C], gUnk_09EEA164, gUnk_09EEA148);
    AnimStart(&work[0x2C], 0, 1);
    *(void**)&work[0x44] = AnimGetGfx(&work[0x2C]);
    SetTaskUpdate(a, (TaskUpdateFunc)func_0809CBD0);
    return 1;
}

s32 func_0809CBD0(u8* work) {
    *(void**)&work[0x44] = AnimUpdate(&work[0x2C]);

    if (*(u16*)&work[0x36] == 0 && *(u16*)&work[0x3A] == 4) {
        work[0x74] = 1;
    }

    return 1;
}

u8 func_0809CBF8(u8* work, void* a) {
    s32 v;

    v = *(s16*)&work[0x4E] << 8;

    if ((s8)work[0x52] <= 2) {
        ApproachValue(&v, -0x2000, work[0x53]);
    }

    if (work[0x52] >= 4 && work[0x52] <= 7) {
        ApproachValue(&v, 0x4400, work[0x53]);
    }

    *(s16*)&work[0x4E] = v >> 8;

    if (work[0x53] != 0) {
        work[0x53]--;
    }

    func_0809C9A4((UnkStruct_0809C9A4*)work);

    if (func_0809C9F4((UnkStruct_0809C9A4*)work)) {
        func_0809CA1C(work);
    } else {
        func_0809CAC8(work);
    }

    return 1;
}

TaskDesc gUnk_09EE781C = {
    "Premire Chance",
    (TaskInitFunc)func_0809C534,
    (TaskUpdateFunc)func_0809C710,
    (TaskFunc)func_0809C78C,
    (TaskFunc)func_0809C98C,
    0x78,
};
