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

extern u8* gUnk_02039DC8;
u8 func_080A2024(u8* work, void* a);
void func_080A1E4C(u8* work);

void func_080A1DAC(EventBgEffectWork* w) {
    EventBgEffectEntry* e;
    EventBgEffectDef* d;

    e = &w->entries[w->unk_14];
    d = gUnk_09EE79B4[e->unk_02];
    w->unk_12 = e->unk_02;
    LoadBgTiles(0, d->tiles, d->tilesSize);
    LoadBgPalette(0, d->palette, d->paletteSize);
    LoadBgMap(0, d->maps[0], 0x800);
    SetBgScroll(0, (u16)((*(s32*)&gUnk_02039DC8[0x58] >> 8) - (e->unk_04 >> 8)), (u16)((*(s32*)&gUnk_02039DC8[0x5C] >> 8) - (e->unk_08 >> 8)));

    if (d->frames != 0) {
        w->unk_15 = 1;
    }

    SetBgBlend(0, 16, 16);
    gUnk_02039DC8[0x80] = 1;
    w->unk_0E = w->unk_0C = w->unk_16 = 0;
}

void func_080A1E4C(u8* work) {
    LoadBgTiles(0, gUnk_094233B8, 1280);
    LoadBgPalette(0, gUnk_096148D8, 32);
    LoadBgMap(0, gUnk_08125E24, 2048);
}

void func_080A1E80(u8* work) {
    u8* p;
    u16 v;
    u8 i;

    v = 16;
    p = *(u8**)&work[0] + work[0x14] * 16;

    for (i = 16; i <= 31; i++) {
        FadeSetPaletteExcluded(i, 1);
    }

    FadeSetPaletteExcluded(14, 1);

    if (*(s32*)&p[4] > 0) {
        v = *(s32*)&p[4];
    }

    if (*(u16*)&p[0xC] & 0x10) {
        FadeStartOut(0, v);
    } else {
        FadeToAmount(0, 16, v);
    }
}

void func_080A1ED8(u8* work) {
    u8* t;
    u16 v;

    v = 16;
    t = *(u8**)&work[0x00] + work[0x14] * 16;
    FadeSetPaletteExcluded(14, 1);

    if (*(s32*)&t[4] > 0) {
        v = *(s32*)&t[4];
    }

    if (*(u16*)&t[12] & 0x10) {
        FadeStartIn(0, v);
    } else {
        FadeToOriginal(0, v);
    }
}
void EV_BG_EFFECT_0(u8* a, u8* b) {
    u8 t;
    u8 z;

    t = b[0];
    z = 0;
    a[19] = t;
    a[20] = z;
    a[21] = z;
    *(void**)&a[0] = gUnk_09EE3FB4[a[19]]->bgEffects;
}
u8 EV_BG_EFFECT_1(EventBgEffectWork* w, void* a) {
    EventBgEffectEntry* e;
    EventBgEffectEntry* cur;
    u8 i;

    e = w->entries;

    if (e == 0) {
        return 0;
    }

    if (*(u16*)e[w->unk_14].unk_00 <= *(u16*)&gUnk_02039DC8[0x6C] && !(*(u16*)e[w->unk_14].unk_0C & 0x8000)) {
        w->unk_14++;
        cur = &e[w->unk_14];

        if (*(u16*)cur->unk_0C & 1) {
            func_080A1DAC(w);

            if (w->unk_15 != 0) {
                SetTaskUpdate(a, (void*)func_080A2024);
            }
        }

        if (*(u16*)cur->unk_0C & 4) {
            func_080A1E80((u8*)w);
        }

        if (*(u16*)cur->unk_0C & 8) {
            func_080A1ED8((u8*)w);
            w->unk_16 = 1;
        }

        if (*(u16*)cur->unk_0C & 2) {
            func_080A1E4C((u8*)w);
            gUnk_02039DC8[0x80] = 0;
            gBldCnt = *(u16*)&gUnk_02039DC8[0x6E];
            gBldAlpha = *(u16*)&gUnk_02039DC8[0x70];
        }
    }

    if (w->unk_16 == 1) {
        if (!FadeIsActive()) {
            w->unk_16 = 0;

            for (i = 16; i < 32; i++) {
                FadeSetPaletteExcluded(i, 0);
            }
        }
    }

    return 1;
}

u8 func_080A2024(u8* work, void* a) {
    u8* p;

    p = *(u8**)&work[0] + work[0x14] * 16;
    SetBgScroll(0, (u16)((*(s32*)&gUnk_02039DC8[0x58] >> 8) - (*(s32*)&p[4] >> 8)),
                (u16)((*(s32*)&gUnk_02039DC8[0x5C] >> 8) - (*(s32*)&p[8] >> 8)));

    if (func_080A207C(work) == 0) {
        SetTaskUpdate(a, (void*)EV_BG_EFFECT_1);
    }

    return 1;
}

u8 func_080A207C(EventBgEffectWork* w) {
    EventBgEffectDef* d;
    EventBgEffectFrame* tbl;

    if (w->unk_15 == 0) {
        return 0;
    }

    d = gUnk_09EE79B4[w->unk_12];
    tbl = d->frames;

    if (w->unk_0C < tbl[w->unk_0E].duration) {
        w->unk_0C++;
    } else {
        w->unk_0C = 0;

        if (w->unk_0E < d->frameCount - 1) {
            w->unk_0E++;
            RequestDma3Copy(d->tiles + tbl[w->unk_0E].tilesOffset, (void*)GetBgCharBase(0), d->tilesSize);
        } else {
            if (d->loopFrame == -1) {
                w->unk_15 = 0;
                return 0;
            }

            w->unk_0E = d->loopFrame;
            RequestDma3Copy(d->tiles + tbl[w->unk_0E].tilesOffset, (void*)GetBgCharBase(0), d->tilesSize);
        }
    }

    return 1;
}

void EV_BG_EFFECT_2(void) {
}
void EV_BG_EFFECT_3(void) {
}
void func_080A2124(u8* work) {
    TaskCreate(&work[0x10], &gTaskDescEVBGEFFECT, work);
}
