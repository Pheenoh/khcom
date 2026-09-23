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
#include "sprites_level_up.h"

#ifdef VERSION_EU
extern u8 gUnkEu_0916F992[];
extern u8 gUnkEu_0917063A[];
extern u8 gUnkEu_09170202[];
extern u8 gUnkEu_0916FDCA[];
#endif
extern u8* gUnk_02039DC8;
void func_080A1554(u8* work);

void Lvup_Logo_0(LevelUpEffectWork* w, LevelUpEffectArgs* a) {
    w->x[0] = a->x;
    w->unk_64 = a->x;
    w->y[0] = a->y;
    w->unk_68 = a->y;
    w->unk_0C = a->unk_0C;
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        w->tiles = LoadObjTiles(gUnk_0908C686, 0x3E0);
        break;
    case 1:
        w->tiles = LoadObjTiles(gUnkEu_0916F992, 0x3E0);
        break;
    case 2:
        w->tiles = LoadObjTiles(gUnkEu_0917063A, 0x3E0);
        break;
    case 3:
        w->tiles = LoadObjTiles(gUnkEu_09170202, 0x3E0);
        break;
    case 4:
        w->tiles = LoadObjTiles(gUnkEu_0916FDCA, 0x3E0);
        break;
    default:
        w->tiles = LoadObjTiles(gUnk_0908C686, 0x3E0);
        break;
    }
#else
    w->tiles = LoadObjTiles(gUnk_0908C686, 0x3E0);
#endif
    LoadObjPalette(gUnk_09611AB8, 32);
    w->tiles = a->unk_10;
    w->palette = a->unk_14;
    FadeSetPaletteExcluded(*(u16*)(a->unk_14 + 6) + 16, 1);
    w->unk_94 = 0;
    w->unk_95 = 0;
    w->unk_6C[0] = -0x280;
    m4aSongNumStart(0x23A);
}

s32 Lvup_Logo_1(u8* work) {
    *(s32*)&work[0x44] += *(s32*)&work[0x6C];
    *(s32*)&work[0x6C] += 25;
    func_080A1554(work);
    *(s32*)&work[0x34] = *(s32*)&work[0x64] << 8;
    ((s8*)work)[0x95]++;

    if (((s8*)work)[0x95] == 60) {
        return 0;
    }

    return 1;
}
void Lvup_Logo_2(u8* work) {
    DrawSprite(*(s32*)&work[0x34] >> 8, *(s32*)&work[0x44] >> 8,
               gUnk_09EEA19C[((s8*)work)[0x94]], *(void**)&work[0x00],
               *(void**)&work[0x04], 0, 0, 10);
}
void Lvup_Logo_3(void** p) {
    ReleaseObjTiles(p[0]);
    ReleaseObjPalette(p[1]);
    gUnk_02034AF8 = 0;
}

u8 func_080A1B4C(UnkStruct_080A1B4C* p, void* pool) {
    LevelUpEffectArgs args;

    gUnk_02034AF8 = 0;

    if (gBtlWork->flags & 0x20000) {
        return 0;
    }

    args.x = p->unk_04;
    args.y = p->unk_08;
    args.unk_08 = 0;
    args.unk_0C = p;
    TaskCreate(pool, &gTaskDescLVUPEFFECT, &args);
    gBtlWork->flags |= 0x20000;
    return 1;
}

void func_080A1BB8(EventMapObjectWork* w, EventBackgroundDef* t) {
    EventMapObjectDef* q;
    EventMapObjectPlacement* entries;
    u8 i;

    q = t->mapObjects;
    entries = q->placements;

    for (i = 0; i < 10; i++) {
        w->tiles[i] = 0;
        w->palettes[i] = 0;
    }

    for (i = 0; i < q->placementCount; i++) {
        if (w->tiles[entries[i].spriteIndex] == 0) {
            w->tiles[entries[i].spriteIndex] = LoadObjTiles(q->tileResources[entries[i].spriteIndex].data, q->tileResources[entries[i].spriteIndex].size);
            w->palettes[entries[i].spriteIndex] = LoadObjPalette(q->paletteResources[entries[i].spriteIndex].data, q->paletteResources[entries[i].spriteIndex].size);
        }
    }
}

void func_080A1C48(u8* work) {
    EventMapObjectWork* w;
    u8 i;

    w = (EventMapObjectWork*)work;

    for (i = 0; i <= 9; i++) {
        if (w->tiles[i] != 0) {
            ReleaseObjTiles(w->tiles[i]);
            ReleaseObjPalette(w->palettes[i]);
        }
    }
}
void Ev_mapObj_0(u8* work, u8* a) {
    EventBackgroundDef* t;

    work[0] = a[0];
    t = gUnk_09EE3CA0[work[0]];

    if (t->mapObjects != 0) {
        func_080A1BB8(work, t);
        *(void**)&work[0x58] = t->mapObjects;
    }
}

u8 Ev_mapObj_1(u8* work) {
    EventMapObjectWork* w;
    u8* p;
    u8* q;
    u8 i;

    w = (EventMapObjectWork*)work;
    p = *(u8**)&work[0x58];
    q = *(u8**)&p[0x0C];

    for (i = 0; i < *(u16*)&p[0x10]; i++) {
        FadeSetPaletteExcluded(*(u16*)((u8*)w->palettes[q[i * 12 + 8]] + 6) + 16, 0);
    }

    return 1;
}

void Ev_mapObj_2(EventMapObjectWork* w) {
    EventMapObjectDef* q;
    EventMapObjectPlacement* entries;
    EventMapObjectPlacement* e;
    u8 i;

    q = w->definition;
    entries = q->placements;

    for (i = 0; i < q->placementCount; i++) {
        e = &entries[i];
        DrawSprite(e->x - (*(s32*)&gUnk_02039DC8[0x58] >> 8), e->y - (*(s32*)&gUnk_02039DC8[0x5C] >> 8), q->sprites[e->spriteIndex], w->tiles[e->spriteIndex], w->palettes[e->spriteIndex], 0, 0x800, (u16)(-0x1004 - e->y * 4));
    }
}

void Ev_mapObj_3(u8* work) {
    func_080A1C48(work);
}

const char gTaskNameLvupLogo[] = "Lvup_Logo";

TaskDesc gTaskDescLvupLogo = {
    gTaskNameLvupLogo,
    (void (*)(void*, void*))Lvup_Logo_0,
    Lvup_Logo_1,
    (void (*)(void*))Lvup_Logo_2,
    (void (*)(void*))Lvup_Logo_3,
    0xAC,
};

const char gTaskNameEvMapObj[] = "Ev_mapObj";

TaskDesc gTaskDescEvMapObj = {
    gTaskNameEvMapObj,
    (void (*)(void*, void*))Ev_mapObj_0,
    Ev_mapObj_1,
    (void (*)(void*))Ev_mapObj_2,
    (void (*)(void*))Ev_mapObj_3,
    0x5C,
};

void* gUnk_09EE7998[7] = { gUnk_0951F2B8, gUnk_0951FAB8, gUnk_095202B8, gUnk_095212B8, gUnk_09520AB8, gUnk_09521AB8, gUnk_095222B8 };
