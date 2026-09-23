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

void WorldSel_Before_0(WorldSelBeforeWork* w, WorldSelBeforeArgs* a) {
    u8 i;

    FadeToAmount(0, 16, 8);
    *(WorldSelBeforeArgs*)&w->x = *a;
    w->tiles = LoadObjTiles(gUnk_093FB0CC, 0xC0);
    w->palette = LoadObjPalette(gUnk_09619378, 32);
    w->tiles2 = LoadObjTiles(gUnk_093FB1AC, 0x4A0);
    w->palette2 = AllocObjPalette(32);
    w->unk_A2 = 6;
    w->unk_1C = 0;
    w->unk_1D = 0;
    w->unk_A3 = 0;
    UpdateAllocatedObjPalette(w->palette2, &gUnk_09619178[gUnk_09EE8E60[w->unk_1C].unk_00 << 5]);
    FadeSetPaletteExcluded(((UnkStruct_080038C8*)w->palette)->index + 16, 1);
    FadeSetPaletteExcluded(w->palette2->index + 16, 1);

    for (i = 0; i < w->unk_A2; i++) {
        w->angle[i] = 0x80;
        w->z2[i] = 0;
        w->x2[i] = gSineTable[w->angle[i]] * 24 + w->x;
        w->y2[i] = -gSineTable[w->angle[i] + 64] * 12 + w->y;
    }

    m4aSongNumStart(0xD4);
}
s32 WorldSel_Before_1(WorldSelBeforeWork* w) {
    u8 i;

    if (w->unk_A3 < w->unk_A2) {
        w->z2[w->unk_A3] -= (s32)(24.0f / (256.0f / (float)w->unk_A2 * 0.25f) * 256.0f);

        if (w->z2[w->unk_A3] <= -6144) {
            w->unk_A3++;
        }
    }

    for (i = 0; i < w->unk_A3; i++) {
        w->x2[i] = gSineTable[w->angle[i]] * 24 + w->x;
        w->y2[i] = -gSineTable[w->angle[i] + 64] * 12 + w->y;
        w->angle[i] += 4;
    }

    if (++w->unk_1D == gUnk_09EE8E60[w->unk_1C].unk_01) {
        do {
            w->unk_1C = w->unk_1C > 28 ? 0 : w->unk_1C + 1;
        } while (0);

        w->unk_1D = 0;
        UpdateAllocatedObjPalette(w->palette2, &gUnk_09619178[gUnk_09EE8E60[w->unk_1C].unk_00 << 5]);
    }

    return 1;
}
void WorldSel_Before_2(WorldSelBeforeWork* w) {
    u8 i;

    for (i = 0; i < w->unk_A2; i++) {
        DrawSprite((w->x2[i] >> 8) - (gUnk_02039BA0->x >> 8),
                   (w->y2[i] >> 8) + ((w->z + w->z2[i]) >> 8) - (gUnk_02039BA0->y >> 8),
                   (&gUnk_09EF1278[4])[0], w->tiles, w->palette, 0, 0x800,
                   (u16)(-0x1004 - (w->y2[i] >> 8) * 4));
    }

    DrawSprite((w->x >> 8) - (gUnk_02039BA0->x >> 8) - 32,
               (w->y >> 8) + (w->z >> 8) - (gUnk_02039BA0->y >> 8) - 16,
               (&gUnk_09EF1278[6])[0], w->tiles2, w->palette2, 0, 0x800,
               (u16)(-0x1004 - ((w->y - 512) >> 8) * 4));
}

void WorldSel_Before_3(void** p) {
    ReleaseObjTiles(p[0]);
    ReleaseObjTiles(p[2]);
    ReleaseObjPalette(p[1]);
    ReleaseObjPalette(p[3]);
}
void func_080A581C(u8* work) {
    TaskCreate(&work[0x10], &gTaskDescWorldSelBefore, work);
}

void func_080A5830(void* a, s32 b, s32 c, s32 d) {
    s32 args[3];

    args[0] = b;
    args[1] = c;
    args[2] = d;
    TaskCreate(a, &gTaskDescWorldSelBefore, args);
}

WorldSelAnim gUnk_09EE8E60[30] = {
    { 0, 10, { 0, 0 } },
    { 1, 6, { 0, 0 } },
    { 2, 4, { 0, 0 } },
    { 3, 4, { 0, 0 } },
    { 4, 4, { 0, 0 } },
    { 5, 4, { 0, 0 } },
    { 6, 4, { 0, 0 } },
    { 7, 4, { 0, 0 } },
    { 8, 4, { 0, 0 } },
    { 9, 4, { 0, 0 } },
    { 10, 4, { 0, 0 } },
    { 11, 4, { 0, 0 } },
    { 12, 4, { 0, 0 } },
    { 13, 4, { 0, 0 } },
    { 14, 6, { 0, 0 } },
    { 15, 10, { 0, 0 } },
    { 14, 6, { 0, 0 } },
    { 13, 4, { 0, 0 } },
    { 12, 4, { 0, 0 } },
    { 11, 4, { 0, 0 } },
    { 10, 4, { 0, 0 } },
    { 9, 4, { 0, 0 } },
    { 8, 4, { 0, 0 } },
    { 7, 4, { 0, 0 } },
    { 6, 4, { 0, 0 } },
    { 5, 4, { 0, 0 } },
    { 4, 4, { 0, 0 } },
    { 3, 4, { 0, 0 } },
    { 2, 4, { 0, 0 } },
    { 1, 6, { 0, 0 } },
};

const char gTaskNameWorldSelBefore[] = "WorldSel Before";

TaskDesc gTaskDescWorldSelBefore = {
    gTaskNameWorldSelBefore,
    (void (*)(void*, void*))WorldSel_Before_0,
    WorldSel_Before_1,
    (void (*)(void*))WorldSel_Before_2,
    (void (*)(void*))WorldSel_Before_3,
    0xB8,
};
