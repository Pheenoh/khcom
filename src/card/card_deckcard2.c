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

void func_08090170(DeckCard2Work* node);
u8 func_080901B8(u8* p);

void DeckCard2_0(DeckCard2Work* n, DeckCard2Args* a) {
    *(DeckCard2Args*)&n->pool = *a;
    n->tiles = 0;
    n->palette = 0;
    n->tiles2 = 0;
    n->palette2 = 0;
    n->flags = 0;

    switch (n->unk_26) {
    case 0:
        if ((u16)n->unk_24 <= 3) {
            n->x = gUnk_09035950[n->unk_22] << 8;
            n->y = gUnk_09035956[n->unk_24] << 8;
        } else {
            n->x = gUnk_09035950[n->unk_22] << 8;
            n->y = 0x20000;
        }
        break;
    case 1:
        if ((u16)n->unk_24 <= 3) {
            n->x = gUnk_0903595E[n->unk_22] << 8;
            n->y = gUnk_09035964[n->unk_24] << 8;
        } else {
            n->x = gUnk_0903595E[n->unk_22] << 8;
            n->y = 0x20000;
        }
        break;
    }

    if (n->cardId != 0xFFFF) {
        if (!(n->cardId & 0x8000)) {
            n->unk_4D = 0;
        } else {
            n->unk_4D = 1;
        }

        n->cardDef = &gCardDefs[n->cardId & 0xFFF];

        if (n->cardDef->flags & 0xC) {
            n->cardBack = &gUnk_08F709B0[3];
        } else {
            n->cardBack = &gUnk_08F709B0[n->cardDef->unk_2A];
        }
    }

    n->unk_4A = 0;
    ListNodeInit(&n->node, n->pool, n);
    ListPoolAppend(&n->node, n->pool);
}

u8 DeckCard2_1(DeckCard2Work* n) {
    if (n->unk_4A == 1) {
        return 0;
    }

    switch (n->unk_26) {
    case 0:
        if ((u16)n->unk_24 <= 3) {
            n->x = gUnk_09035950[n->unk_22] << 8;
            n->y = gUnk_09035956[n->unk_24] << 8;
        } else {
            n->x = gUnk_09035950[n->unk_22] << 8;
            n->y = 0x20000;
        }
        break;
    case 1:
        if ((u16)n->unk_24 <= 3) {
            n->x = gUnk_0903595E[n->unk_22] << 8;
            n->y = gUnk_09035964[n->unk_24] << 8;
        } else {
            n->x = gUnk_0903595E[n->unk_22] << 8;
            n->y = 0x20000;
        }
        break;
    }

    if (func_080901B8((u8*)n)) {
        func_08090100(n);
    } else {
        func_08090170(n);
    }
}

void DeckCard2_2(DeckCard2Work* n) {
    if (!(n->flags & 1)) {
        return;
    }

    if (n->tiles != 0 && n->palette != 0) {
        DrawSprite(n->x >> 8, n->y >> 8, n->cardDef->gfx2, n->tiles, n->palette, 0, 0, 0x33);

        if (n->unk_4D != 0) {
            DrawSprite(n->x >> 8, n->y >> 8, gUnk_0203A860.gfx, gUnk_0203A860.tiles, gUnk_0203A860.palette, 0, 0, 0x28);
        }
    }

    if (n->unk_26 == 0 && n->cardDef->unk_2A != 3) {
        DrawSprite((n->x >> 8) - 3, (n->y >> 8) - 4, gUnk_09EE981C[n->cardDef->unk_20], n->tiles2, n->palette2, 0, 0, 0x31);
    }
}

void DeckCard2_3(u8* p) {
    func_08090170((DeckCard2Work*)p);
    ListPoolRemove(&p[0x2C], *(void**)&p[0x1C]);
}

void func_08090100(DeckCard2Work* n) {
    if (n->cardId == 0xFFFF) {
        return;
    }

    if (n->flags & 1) {
        return;
    }

    n->palette2 = LoadObjPalette(gUnk_09611AB8, 32);
    n->tiles = LoadObjTiles(n->cardDef->tiles2, 0x200);
    n->palette = LoadObjPalette(n->cardDef->palette2, 32);
    n->tiles2 = LoadObjTiles(gUnk_0905EAE8, 0x1E0);

    if (n->tiles != 0 && n->palette != 0) {
        n->flags |= 1;
    }
}

void func_08090170(DeckCard2Work* node) {
    if (node->flags & 1) {
        ReleaseObjPalette(node->palette2);
        ReleaseObjTiles(node->tiles);
        ReleaseObjPalette(node->palette);
        ReleaseObjTiles(node->tiles2);
        node->flags &= 0xFFFE;
        node->tiles = 0;
        node->palette = 0;
        node->tiles2 = 0;
        node->palette2 = 0;
    }
}

u8 func_080901B8(u8* p) {
    s16 a;
    s16 b;

    a = *(s32*)&p[0x40] >> 8;
    b = *(s32*)&p[0x44] >> 8;

    if (a < 0) {
        return 0;
    }

    if (a > 240) {
        return 0;
    }

    if (b < 0) {
        return 0;
    }

    if (b > 160) {
        return 0;
    }

    return 1;
}

const char gTaskNameDeckCard2[] = "DeckCard2";

TaskDesc gTaskDescDeckCard2 = {
    gTaskNameDeckCard2,
    (void (*)(void*, void*))DeckCard2_0,
    DeckCard2_1,
    (void (*)(void*))DeckCard2_2,
    (void (*)(void*))DeckCard2_3,
    0x50,
};
