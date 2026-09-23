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
#include "sprites_map.h"

u8 gUnk_02034AB8[20];

u8 gUnk_02034ACC;

u32 gUnk_02034AD0;

MapCardUiResources gUnk_0203A890 EWRAM_COMMON(16);

u8 gUnk_0203A8C0[270] EWRAM_COMMON(16);

extern void* gUnk_09EE7578[];
extern AnimHeader** gUnk_09EE7588[];
extern void** gUnk_09EE7598[];
extern void* gUnk_09EE75A8[];
extern void** gUnk_09EE75B8[];
extern AnimHeader** gUnk_09EE75C8[];
extern u8 gUnk_09618CD8[];
extern u8 gUnk_093F4578[];
extern u8 gUnk_09618D18[];
#ifdef VERSION_EU
extern u8 gUnkEu_08CB0D3C[];
extern u8 gUnkEu_08F7ADFC[];
extern u8 gUnkEu_09F72C10[];
extern u8 gUnkEu_09529A04[];
extern u8 gUnkEu_0952DDE4[];
extern u8 gUnkEu_0952E0E4[];
extern u8 gUnkEu_0952DFE4[];
extern u8 gUnkEu_0952DEE4[];
extern u8 gUnkEu_09543324[];
#endif
u16 func_08093B08(u16 a);
s32* func_080E04E0(void);
u8 Reload_Gage_1(ReloadGageWork* w, void* a);
u8 func_080954C4(ReloadGageWork* w, void* a);
u8 func_0809217C(MapSelectWork* w, void* a);
void func_08093C44(u16 a, MapSelectWork* w);
s32 func_08093E34(u16 a, MapSelectWork* w);
u8 func_08092234(MapSelectWork* w, void* a);
u8 func_08092A34(MapSelectWork* w, void* a);
u8 func_080923E0(MapSelectWork* w, void* a);
#ifdef VERSION_EU
extern u8 gUnkEu_094C6C22[];
extern u8 gUnkEu_094C789A[];
extern u8 gUnkEu_094C7472[];
extern u8 gUnkEu_094C704A[];
#endif
extern u8 gUnk_0908B1B4[];
void func_080949A0(MapcardWork* w);
u8 func_08094A18(MapcardWork* w, void* a);
s32 RemoveMapCard(u16 a);
u8 func_0809254C(MapSelectWork* w, void* a);
u8 func_080928E4(MapSelectWork* w, void* a);
u8 func_08092E2C(MapSelectWork* w);
s32 func_08093838(MapSelectWork* w);
void func_08094DEC(MapcardWork* w);
void func_08094E90(MapcardWork* w);

void WORLDSELECT_0(void) {
    SetBgMode2();
    SetupBg(3, 0, 12, 0);
    SetupBg(2, 2, 28, 10);
    SetBgSize(3, 0x8000);
#ifdef VERSION_EU
    LoadBgTiles(3, gUnkEu_08CB0D3C, 0x4000);
    LoadBgPalette(3, gUnk_08F68A84, 0x100);
    eu_080059F4(3, gUnkEu_08F7ADFC);
#else
    LoadBgTiles(3, gUnk_08C8C824, 0x4000);
    LoadBgPalette(3, gUnk_08F68A84, 0x100);
    LoadBgMap(3, gUnk_08EF4384, 0x1000);
#endif
    SetBgAffine(3, 0, 0x100, 0x100, 0x10000, 0x16800);
    TaskPoolInit(gUnk_02034AB8, 1);
#ifdef VERSION_EU
    TaskCreate(gUnk_02034AB8, gUnkEu_09F72C10, 0);
#else
    TaskCreate(gUnk_02034AB8, &gUnk_09EE7804, 0);
#endif
}
void WORLDSELECT_1(void) {
    TaskPoolUpdate(gUnk_02034AB8);
    TaskPoolDraw(gUnk_02034AB8);
}
void WORLDSELECT_2(void) {
    TaskPoolDestroy(gUnk_02034AB8);
}
extern u8 gUnk_093F5422[];
extern u8 gUnk_093F6734[];
extern u8 gUnk_093F5C40[];
void func_0809332C(MapSelectWork* w);
void MapSelect_0(MapSelectWork* w, u8* a) {
    u32 zero;
    s32 n;

    func_080A42B4();
    zero = 0;
    CpuSet(&zero, w, 0x050000B9);
    w->unk_294 = a;
    *a = 0;
    w->unk_286 = 0;
    w->unk_2BF = 0;
    w->unk_298 = 0;
    w->card2 = 0;
    gUnk_02034ACC = 0;
    w->unk_29C = 0;
    w->unk_29D = 0;
    w->unk_2C0 = 0;
    w->unk_2BE = func_080DF500();
    n = (u8)func_080E0378() + 1;
    *(u16*)w->unk_27E = n;
    if (n == 10) {
        *(u16*)w->unk_27E = 0;
    }
    w->tiles3 = 0;
    if (w->unk_2BE == 0) {
        if (*(u16*)w->unk_27E == 0) {
            w->tiles4 = AllocSpriteFrameTiles(0x80);
            UpdateSpriteFrameTiles(w->tiles4, gUnk_09EF1198[0], gUnk_0950C478);
        } else {
            w->tiles4 = AllocSpriteFrameTiles(0x180);
            UpdateSpriteFrameTiles(w->tiles4, gUnk_09EF1198[1], gUnk_0950C478);
            RequestDma3Copy((u8*)w->tiles4->src + (*(u16*)w->unk_27E << 7),
                           (void*)(0x06010000 + ((w->tiles4->index + 4) << 5)), 0x80);
            RequestDma3Copy((u8*)w->tiles4->src + 0x500,
                           (void*)(0x06010000 + (w->tiles4->index << 5)), 0x80);
        }
        w->tiles2 = LoadObjTiles(gUnk_08F709B0[4].tiles2, 0x300);
        w->palette = LoadObjPalette(gUnk_09618D38, 32);
        FadeSetPaletteExcluded((u16)(w->palette->index + 16), 1);
    } else {
        w->tiles4 = 0;
        w->tiles2 = 0;
        w->palette = LoadObjPalette(gUnk_09618D38, 32);
        FadeSetPaletteExcluded((u16)(w->palette->index + 16), 1);
    }
    gUnk_0203A890.tiles = AllocObjTiles(0x280, 0);
    SetObjTileSource(gUnk_0203A890.tiles, gUnk_0908B1B4);
    AnimInit(&gUnk_0203A890.anim, gUnk_09EEA164, gUnk_09EEA148);
    AnimStart(&gUnk_0203A890.anim, 0, 1);
    gUnk_0203A890.gfx = AnimGetGfx(&gUnk_0203A890.anim);
    w->tiles = AllocObjTiles(0x3C0, 0);
    *(void**)w->unk_040 = LoadObjPalette(gUnk_09618D18, 32);
    SetObjTileSource(w->tiles, gUnk_093F47E4);
    AnimInit((AnimState*)w->unk_1F8, gUnk_09EF1194, gUnk_09EF1180);
    AnimStart((AnimState*)w->unk_1F8, 0, 1);
    w->gfx = AnimGetGfx((AnimState*)w->unk_1F8);
    *(void**)&w->unk_040[4] = AllocObjTiles(0x120, 0);
    *(void**)&w->unk_040[8] = LoadObjPalette(gUnk_09618CD8, 32);
    SetObjTileSource(*(void**)&w->unk_040[4], gUnk_093F4578);
    AnimInit((AnimState*)&w->unk_1F8[0x18], gUnk_09EF1170, gUnk_09EF1150);
    AnimStart((AnimState*)&w->unk_1F8[0x18], 0, 1);
    *(void**)w->unk_278 = AnimGetGfx((AnimState*)&w->unk_1F8[0x18]);
    *(void**)&w->unk_040[0x1A8] = LoadObjTiles(gUnk_093F5422, 0xC0);
    w->y3 = -0x800;
    w->y4 = 0xA000;
    w->unk_290 = 16;
    w->unk_28F = 16;
    w->unk_27C = func_08093384();
    TaskPoolInit(&w->tasks, w->unk_27C + 10);
    ListPoolInit(&w->cards);
    w->unk_2E0 = EwramAlloc(w->unk_27C * 4);
    func_080933D8(w->unk_2E0);
    func_0809332C(w);
#ifdef VERSION_EU
    gUnk_0203A890.extraTiles = LoadObjTiles(gUnkEu_09F6FF30[gLanguage], gUnkEu_090CED64[gLanguage]);
#else
    gUnk_0203A890.extraTiles = LoadObjTiles(gUnk_093F6734, 0x360);
#endif
    gUnk_0203A890.palette = *(void**)&w->unk_040[8];
#ifdef VERSION_EU
    gUnk_0203A890.sprites = gUnkEu_09F6FF44[gLanguage];
#else
    gUnk_0203A890.sprites = gUnk_09EF11F8;
#endif
    *(void**)&w->unk_040[0x1A0] = LoadObjTiles(gUnk_093F5C40, 32);
    w->unk_284 = 0;
    w->unk_285 = 0;
    w->card = ListPoolFirst(&w->cards);
    *(MapcardWork**)w->unk_1F0 = 0;
    m4aSongNumStart(118);
    gUnk_02034AD0 = 0;
    w->x2 = 0x1600;
    w->y2 = 0x16400;
    w->unk_28D[0] = 0;
    *(s32*)w->unk_260 = 0;
    w->unk_264 = 0x1600;
    *(s32*)w->unk_268 = 0x6400;
    w->unk_28D[1] = 0;
    w->unk_28B = 0;
    if (w->card != 0) {
        w->x = w->card->x;
        w->y = w->card->y;
        w->card->unk_6C |= 0x100;
    } else {
        w->x = -0x6400;
        w->y = -0x6400;
    }
    w->x3 = -0xA000;
    *(s32*)w->unk_24C = 0;
    *(void**)&w->unk_040[0x18C] = _08066468(1);
    w->unk_287[0] = 0;
    w->unk_287[1] = 0;
    w->unk_287[2] = 0;
    InitTextSlots(&w->unk_040[12], 48);
    if (w->card != 0) {
        *(MapcardWork**)w->unk_1F0 = w->card;
        w->unk_287[0] = LoadTextSlots(func_08093C18(gUnk_09EE4C80[w->card->unk_20].unk_20), &w->unk_040[12]);
    }
    w->unk_244 = 0x19100;
    FadeSetPaletteExcluded((u16)((*(ObjPalette**)&w->unk_040[8])->index + 16), 1);
    FadeSetPaletteExcluded((u16)((*(ObjPalette**)w->unk_040)->index + 16), 1);
    FadeSetPaletteExcluded(15, 1);
    FadeSetPaletteExcluded((u16)((*(ObjPalette**)&w->unk_040[0x18C])->index + 16), 1);
    *(void**)&w->unk_040[0x1A4] = 0;
    w->unk_299 = 9;
    w->unk_29A = 9;
    w->unk_29B = 0;
    w->unk_2C1 = 0;
}
u8 MapSelect_1(MapSelectWork* w, void* a) {
#ifdef VERSION_EU
    LoadBgTiles(1, gUnk_09508098, 0x2020);

    switch (gLanguage) {
    case 0:
        w->tiles3 = LoadObjTiles(gUnk_093F7172, 0x400);
        break;
    case 1:
        w->tiles3 = LoadObjTiles(gUnkEu_094C6C22, 0x400);
        RequestDma3Copy(gUnkEu_0952DDE4, (u8*)GetBgCharBase(1) + 0x1AA0, 0x100);
        break;
    case 2:
        w->tiles3 = LoadObjTiles(gUnkEu_094C789A, 0x400);
        RequestDma3Copy(gUnkEu_0952E0E4, (u8*)GetBgCharBase(1) + 0x1AA0, 0x100);
        break;
    case 3:
        w->tiles3 = LoadObjTiles(gUnkEu_094C7472, 0x400);
        RequestDma3Copy(gUnkEu_0952DFE4, (u8*)GetBgCharBase(1) + 0x1AA0, 0x100);
        break;
    case 4:
        w->tiles3 = LoadObjTiles(gUnkEu_094C704A, 0x400);
        RequestDma3Copy(gUnkEu_0952DEE4, (u8*)GetBgCharBase(1) + 0x1AA0, 0x100);
        break;
    }
#else
    w->tiles3 = LoadObjTiles(gUnk_093F7172, 0x400);
    LoadBgTiles(1, gUnk_09508098, 0x2020);
#endif
    LoadPalette(gUnk_09618C58, (void*)0x05000180, 32);
    LoadPalette(&gUnk_09618C58[0x40], (void*)0x050001C0, 64);
    FadeSetPaletteExcluded(12, 1);
    FadeSetPaletteExcluded(14, 1);
    FadeSetPaletteExcluded(15, 1);
    w->unk_286++;
    DisableBg(1);
    SetTaskUpdate(a, (void*)func_0809217C);
    return 1;
}
u8 func_0809217C(MapSelectWork* w, void* a) {
    s32 n;

    SetBgMapBlocks(1, gUnk_09EE4BB0, 1, 2);
    w->unk_240 = 0;
    ScrollBgMapTo(1, 0, 0);
    EnableBg(1);

    if (w->unk_2BE == 1) {
        w->unk_2DA = func_080E8D00();
        w->unk_2DC = func_080E8D1C(0);
        n = w->unk_2DA;

        while (n != 0) {
            n--;
        }

        w->unk_2C4 = *(void**)&w->unk_040[0x08];
        w->unk_2CC = 0;
        w->unk_238 =
            ((void**)TaskCreate(w, &gTaskDescSELMAPEVKEY, &w->unk_2C4))[1];
    }

    func_08093C44(((u8*)w->card)[32], w);
    SetTaskUpdate(a, (void*)func_08092234);
    return 1;
}
u8 func_08094404(MapSelectWork* w, void* a);

u8 func_08092234(MapSelectWork* w, void* a) {
    MapcardWork* n;

    if (w->unk_290 != 0) {
        ApproachValue(&w->y3, 0, w->unk_290);
        ApproachValue(&w->y4, 0x9800, w->unk_290);
        w->unk_290--;
    } else {
        ApproachValue(&w->unk_240, 0x10000, w->unk_28F);
        ApproachValue(&w->x3, 0, w->unk_28F);
        ScrollBgMapTo(1, 0, (u32)w->unk_240 >> 8);

        if (w->unk_28F != 0) {
            w->unk_28F--;
        } else {
            if ((gGameState.progression.unk_82 & 8) == 0) {
                w->unk_2C1 = 1;
                func_080A42B4();
                w->unk_2C2 = 95;
                SetTaskUpdate(a, (void*)func_0809423C);
            } else if ((gGameState.progression.unk_82 & 0x40) == 0 && w->unk_2BE == 1) {
                func_080A42B4();
                w->unk_2C2 = 109;
                SetTaskUpdate(a, (void*)func_08094404);
                gGameState.progression.unk_82 |= 0x40;
            } else {
                n = ListPoolFirst(&w->cards);
                SetBgMapBlocks(1, gUnk_09EE4BB0, 1, 2);

                while (n != 0) {
                    n->unk_6C |= 2;
                    n = ListPoolNext(&n->node);
                }

                if (w->unk_27C <= 6) {
                    w->unk_285 = 0;
                } else {
                    w->unk_285 = w->unk_27C / 6;
#ifdef VERSION_EU
                    if ((u16)(w->unk_27C % 6) == 0) {
                        w->unk_285--;
                    }
#endif
                }

                w->y2 = 0x6400;
                w->y = 0x7A00;
                w->unk_244 = 0x9100;
                SetTaskUpdate(a, (void*)func_08092A34);
                w->unk_2C0 = 1;
            }
        }
    }

    TaskPoolUpdate(&w->tasks);
    return 1;
}

u8 func_080923E0(MapSelectWork* w, void* a) {
    s8 v;

    if (w->card->unk_6F == 0) {
        LoadBgTiles(1, &gUnk_09508098[0x2020], 0x23C0);
#ifdef VERSION_EU
        switch (gLanguage) {
        case 0:
            break;
        case 1:
            RequestDma3Copy(gUnkEu_0952DDE4, (u8*)GetBgCharBase(1) + 0x1EA0, 0x100);
            break;
        case 2:
            RequestDma3Copy(gUnkEu_0952E0E4, (u8*)GetBgCharBase(1) + 0x1EA0, 0x100);
            break;
        case 3:
            RequestDma3Copy(gUnkEu_0952DFE4, (u8*)GetBgCharBase(1) + 0x1EA0, 0x100);
            break;
        case 4:
            RequestDma3Copy(gUnkEu_0952DEE4, (u8*)GetBgCharBase(1) + 0x1EA0, 0x100);
            break;
        }
#endif
        LoadBgMap(1, &gUnk_0960F2B8[0x1800], 0x800);
        func_08093D28(w->card->unk_20, w);
        v = func_08093E34(w->card->unk_20, w);
        SetTaskUpdate(a, (void*)func_0809254C);
        ReleaseObjTiles(w->tiles);
        w->tiles = AllocObjTiles(0x1E0, 0);
        SetObjTileSource(w->tiles, &gUnk_093F47E4[0xD88]);
        AnimInit(w->unk_1F8, gUnk_09EF11CC, gUnk_09EF11B8);
        AnimStart(w->unk_1F8, 0, 1);
        w->gfx = AnimGetGfx(w->unk_1F8);
        w->unk_280 = w->x2 >> 8;
        w->unk_282 = w->y2 >> 8;

        if (v > 4) {
            w->unk_29C = v - 5;
            w->unk_29D = 1;
        } else {
            w->unk_29C = v;
            w->unk_29D = 0;
        }

        w->unk_28B = 4;
        w->unk_28C = 4;
        w->unk_2C0 = 0;
    }

    SetObjMosaicSize(w->unk_299, w->unk_29A);

    if (w->unk_29B == 2) {
        if (w->unk_299 != 0) {
            w->unk_299--;
        }

        if (w->unk_29A != 0) {
            w->unk_29A--;
        }

        w->unk_29B = 0;
    }

    w->unk_29B++;
    TaskPoolUpdate(&w->tasks);
    return 1;
}
u8 func_0809254C(MapSelectWork* w, void* a) {
    u16 keys;
    s16 sel;
    u8 n;

    keys = GetKeysPressed();
    sel = (s8)w->unk_29C + (s8)w->unk_29D * 5;

    if ((gGameState.progression.unk_82 & 8) == 0) {
        if (w->unk_28B == 0) {
            SetTaskUpdate(a, (void*)func_0809438C);
            TaskPoolUpdate(&w->tasks);
            return 1;
        }
        keys = 0;
    }

    switch (keys & 0x30F) {
    case 2:
#ifdef VERSION_EU
        LoadBgTiles(1, gUnkEu_09529A04, 0x2020);

        switch (gLanguage) {
        case 0:
            break;
        case 1:
            RequestDma3Copy(gUnkEu_0952DDE4, (u8*)GetBgCharBase(1) + 0x1AA0, 0x100);
            break;
        case 2:
            RequestDma3Copy(gUnkEu_0952E0E4, (u8*)GetBgCharBase(1) + 0x1AA0, 0x100);
            break;
        case 3:
            RequestDma3Copy(gUnkEu_0952DFE4, (u8*)GetBgCharBase(1) + 0x1AA0, 0x100);
            break;
        case 4:
            RequestDma3Copy(gUnkEu_0952DEE4, (u8*)GetBgCharBase(1) + 0x1AA0, 0x100);
            break;
        }

        LoadBgMap(1, gUnkEu_09543324, 0x800);
#else
        LoadBgTiles(1, gUnk_09508098, 0x2020);
        LoadBgMap(1, &gUnk_0960F2B8[0x1000], 0x800);
#endif
        w->card->unk_6C &= 0xFDFF;
        SetTaskUpdate(a, (void*)func_080928E4);
        m4aSongNumStart(104);
        break;
    case 1:
        n = (u8)func_080E8D64((u32)&gUnk_09EE4C80[w->card->unk_20 + (s16)sel] + 0x20);

        if (n == 1) {
            if (gUnk_0203A8C0[w->card->unk_20 + (s16)sel] != 0) {
                if (w->unk_2BE == 1) {
                    m4aSongNumStart(140);

                    if (func_08093B08(w->card->unk_20) == 0) {
                        w->card->unk_74 = sel;
                        w->card->unk_6C |= 0x40;
                    }

                    RemoveMapCard(w->card->unk_20 + sel);

                    if ((u8)func_080E8E24((u32)&gUnk_09EE4C80[w->card->unk_20 + (s16)sel] + 0x20) == 1) {
                        w->unk_2DA = func_080E8D00();
                        ((u8*)w->unk_238)[0x122]++;
                        ((u8*)w->unk_238)[0x11A] = 8;

                        if (w->unk_2DA == 0) {
                            w->card->unk_74 = sel;
                            w->card->unk_6C |= 0x40;
                            *w->unk_294 = 2;
                            w->unk_28F = 16;
                            w->unk_290 = 16;
                            w->unk_285 = 0;
                            w->unk_284 = 0;
                            w->unk_2CC = n;
                            SetTaskUpdate(a, (void*)func_08092E2C);
                            return 1;
                        }
                    }

                    func_08093C44(w->card->unk_20, w);
                    func_08093D28(w->card->unk_20, w);

                    if ((s8)func_08093E34(w->card->unk_20, w) == -1) {
#ifdef VERSION_EU
                        LoadBgTiles(1, gUnkEu_09529A04, 0x2020);

                        switch (gLanguage) {
                        case 0:
                            break;
                        case 1:
                            RequestDma3Copy(gUnkEu_0952DDE4, (u8*)GetBgCharBase(1) + 0x1AA0, 0x100);
                            break;
                        case 2:
                            RequestDma3Copy(gUnkEu_0952E0E4, (u8*)GetBgCharBase(1) + 0x1AA0, 0x100);
                            break;
                        case 3:
                            RequestDma3Copy(gUnkEu_0952DFE4, (u8*)GetBgCharBase(1) + 0x1AA0, 0x100);
                            break;
                        case 4:
                            RequestDma3Copy(gUnkEu_0952DEE4, (u8*)GetBgCharBase(1) + 0x1AA0, 0x100);
                            break;
                        }

                        LoadBgMap(1, gUnkEu_09543324, 0x800);
#else
                        LoadBgTiles(1, gUnk_09508098, 0x2020);
                        LoadBgMap(1, &gUnk_0960F2B8[0x1000], 0x800);
#endif
                        w->card->unk_6C &= 0xFDFF;
                        func_08094548(w);
                        SetTaskUpdate(a, (void*)func_080928E4);
                    }
                    break;
                }

                w->card->unk_74 = sel;
                w->card->unk_6C |= 0x40;
                RemoveMapCard(w->card->unk_20 + sel);
                *w->unk_294 = 2;
                w->unk_28F = 16;
                w->unk_290 = 16;
                SetTaskUpdate(a, (void*)func_08092E2C);
                m4aSongNumStart(140);
                w->unk_285 = 0;
                w->unk_284 = 0;
                w->unk_2CC = n;
                return 1;
            }
        }
        m4aSongNumStart(105);
        break;
    }

    *(void**)&w->unk_278 = AnimUpdate((AnimState*)&w->unk_1F8[0x18]);
    w->gfx = AnimUpdate((AnimState*)w->unk_1F8);
    gUnk_0203A890.gfx = AnimUpdate(&gUnk_0203A890.anim);
    TaskPoolUpdate(&w->tasks);
    func_08093F5C((u8*)w);
    SetObjMosaicSize(w->unk_299, w->unk_29A);

    if (w->unk_29B == 2) {
        if (w->unk_299 != 0) {
            w->unk_299--;
        }

        if (w->unk_29A != 0) {
            w->unk_29A--;
        }

        w->unk_29B = 0;
    }

    w->unk_29B++;
    TaskPoolUpdate(&w->tasks);
    return 1;
}
u8 func_080928E4(MapSelectWork* w, void* a) {
    MapcardWork* node;

    if (func_08093384() == 0) {
        return 0;
    }

    if (w->card->unk_6F == 0) {
        node = (MapcardWork*)ListPoolFirst(&w->cards);

        while (node != 0) {
            if (w->card != node) {
                node->unk_6C |= 2;
            }

            node = (MapcardWork*)ListPoolNext(&node->node);
        }

        SetTaskUpdate(a, (void*)func_08092A34);
        ReleaseObjTiles(w->tiles);
        w->tiles = AllocObjTiles(0x3C0, 0);
        SetObjTileSource(w->tiles, gUnk_093F47E4);
        AnimInit(w->unk_1F8, gUnk_09EF1194, gUnk_09EF1180);
        AnimStart(w->unk_1F8, 0, 1);
        w->gfx = AnimGetGfx(w->unk_1F8);
        w->x2 = w->unk_280 << 8;
        w->y2 = w->unk_282 << 8;
        w->x = w->card->x;
        w->y = w->card->y;
        w->unk_2C0 = 1;
    }

    SetObjMosaicSize(w->unk_299, w->unk_29A);

    if (w->unk_29B == 2) {
        if (w->unk_299 != 0) {
            w->unk_299--;
        }

        if (w->unk_29A != 0) {
            w->unk_29A--;
        }

        w->unk_29B = 0;
    }

    w->unk_29B++;
    TaskPoolUpdate(&w->tasks);
    return 1;
}
u8 func_08092A34(MapSelectWork* w, void* a) {
    u16 keys = GetKeysPressed();
    MapcardWork* p;

    func_08093708(w);
    SetObjMosaicSize(w->unk_299, w->unk_29A);
    if (w->unk_29B == 2) {
        if (w->unk_299 != 0) {
            w->unk_299--;
        }
        if (w->unk_29A != 0) {
            w->unk_29A--;
        }
        w->unk_29B = 0;
    }
    w->unk_29B++;
    switch (keys & 0x30F) {
    case 1:
        if (w->card != 0) {
            if (w->card->unk_20 >= 220) {
                if ((u8)func_080E8D64((u32)&gUnk_09EE4C80[w->card->unk_20] + 0x48) == 1) {
                    if (gUnk_0203A8C0[w->card->unk_20 + 1] != 0) {
                        m4aSongNumStart(140);
                        RemoveMapCard(w->card->unk_20 + 1);
                        if ((u8)func_080E8E24((u32)&gUnk_09EE4C80[w->card->unk_20] + 0x48) == 1) {
                            w->unk_2DA = func_080E8D00();
                            ((u8*)w->unk_238)[0x122]++;
                            ((u8*)w->unk_238)[0x11A] = 8;
                            if (w->unk_2DA == 0) {
                                w->card->unk_74 = 1;
                                w->card->unk_6C |= 0x40;
                                for (p = ListPoolFirst(&w->cards); p != 0; p = ListPoolNext(&p->node)) {
                                    if (w->card != p) {
                                        p->unk_6C &= 0xFFFD;
                                    }
                                }
                                *w->unk_294 = 2;
                                w->unk_28F = 16;
                                w->unk_290 = 16;
                                w->unk_285 = 0;
                                w->unk_284 = 0;
                                w->unk_2CC = 1;
                                SetTaskUpdate(a, (u32)func_08092E2C);
                                return 1;
                            }
                        }
                        break;
                    }
                }
            } else {
                if (func_08093B08(w->card->unk_20) != 0) {
                    for (p = ListPoolFirst(&w->cards); p != 0; p = ListPoolNext(&p->node)) {
                        if (w->card != p) {
                            p->unk_6C &= 0xFFFD;
                        }
                    }
                    if (w->card != 0) {
                        w->unk_23C = w->card->x;
                        w->card->unk_6C |= 0x200;
                    }
                    m4aSongNumStart(102);
                    SetTaskUpdate(a, (u32)func_080923E0);
                    return 1;
                }
            }
        }
        m4aSongNumStart(105);
        break;
    case 2:
        if (w->unk_2C1 == 0) {
            for (p = ListPoolFirst(&w->cards); p != 0; p = ListPoolNext(&p->node)) {
                p->unk_6C &= 0xFFFD;
            }
            w->unk_2BF = 1;
            w->unk_28F = 16;
            w->unk_290 = 16;
            SetTaskUpdate(a, (u32)func_08092E2C);
            m4aSongNumStart(103);
            gUnk_02034AD0 = 0;
            w->unk_285 = 0;
            w->unk_284 = 0;
            w->unk_2CC = 2;
        } else {
            m4aSongNumStart(105);
        }
        break;
    }
    func_08093434((u8*)w);
    if (w->unk_298 == 0) {
        if (w->card != *(MapcardWork**)w->unk_1F0) {
            if (w->card != 0) {
                w->unk_287[0] = LoadTextSlots(func_08093C18(gUnk_09EE4C80[w->card->unk_20].unk_20), &w->unk_040[12]);
                func_08093C44(w->card->unk_20, w);
            } else {
                w->unk_287[0] = 0;
                w->unk_287[1] = 0;
                w->unk_287[2] = 0;
            }
            *(MapcardWork**)w->unk_1F0 = w->card;
            w->unk_28B = 4;
        } else if (w->card != 0) {
            ApproachValue(&w->x, w->card->x, w->unk_28B);
            ApproachValue(&w->y, w->card->y, w->unk_28B);
            if (w->unk_28B != 0) {
                w->unk_28B--;
            }
        }
    }
    *(void**)w->unk_278 = AnimUpdate((AnimState*)&w->unk_1F8[0x18]);
    w->gfx = AnimUpdate((AnimState*)w->unk_1F8);
    gUnk_0203A890.gfx = AnimUpdate(&gUnk_0203A890.anim);
    TaskPoolUpdate(&w->tasks);
    return 1;
}
u8 func_08092E2C(MapSelectWork* w) {
    ApproachValue(&w->unk_240, 0, w->unk_28F);
    ApproachValue(&w->x3, -0xA000, w->unk_28F);
    ApproachValue(&w->y2, 0x16400, w->unk_28F);
    ApproachValue(&w->y, 0x17A00, w->unk_28F);
    ApproachValue(&w->unk_244, 0x19100, w->unk_28F);
    ScrollBgMapTo(1, 0, (u32)w->unk_240 >> 8);
    w->unk_2C0 = 0;

    if (w->unk_299 <= 8) {
        w->unk_299++;
    }

    if (w->unk_29A <= 8) {
        w->unk_29A++;
    }

    SetObjMosaicSize(w->unk_299, w->unk_29A);

    if (w->unk_28F != 0) {
        w->unk_28F--;
    } else if (w->unk_290 != 0) {
        ApproachValue(&w->y3, -0x800, w->unk_290);
        ApproachValue(&w->y4, 0xA000, w->unk_290);
        w->unk_290--;
    } else {
        if (w->unk_2BF != 0 || (w->card->unk_6C & 0x80)) {
            return 0;
        }
    }

    TaskPoolUpdate(&w->tasks);
    return 1;
}
void MapSelect_2(MapSelectWork* w) {
    if (w->tiles3 != 0 && *(void**)&w->unk_040[8] != 0) {
        DrawSprite((s16)(w->x3 >> 8), (s16)(*(s32*)w->unk_24C >> 8),
#ifdef VERSION_EU
                   gUnkEu_09F6FF70[gLanguage][0],
#else
                   gUnk_09EF1228[0],
#endif
                   w->tiles3, *(void**)&w->unk_040[8], 0, 0, 80);
    }
    if (w->unk_2BE == 1) {
        switch (gUnk_09EE4C80[w->card->unk_20].backIndex) {
        case 0:
            break;
        case 2:
            DrawSprite((s16)((w->card->x >> 8) + 4), (s16)((w->card->y >> 8) - 32), gUnk_0203A890.sprites[3], gUnk_0203A890.extraTiles, gUnk_0203A890.palette, 0, 0, 20);
            break;
        case 3:
            DrawSprite((s16)((w->card->x >> 8) + 4), (s16)((w->card->y >> 8) - 32), gUnk_0203A890.sprites[7], gUnk_0203A890.extraTiles, gUnk_0203A890.palette, 0, 0, 20);
            break;
        case 1:
            DrawSprite((s16)((w->card->x >> 8) + 4), (s16)((w->card->y >> 8) - 32), gUnk_0203A890.sprites[5], gUnk_0203A890.extraTiles, gUnk_0203A890.palette, 0, 0, 20);
            break;
        case 4:
            break;
        }
    }
    if ((u8)func_080A42C8() == 0) {
        DrawSprite((s16)((w->x >> 8) - 23), (s16)((w->y >> 8) - 27), w->gfx, w->tiles, *(void**)&w->unk_040[0], 0, 0, 41);
        DrawSprite((s16)((w->x2 >> 8) - 16), (s16)((w->y2 >> 8) - 12), *(void**)w->unk_278, *(void**)&w->unk_040[4], *(void**)&w->unk_040[8], 0, 0, 40);
    }
    if (w->unk_2C0 != 0) {
        DrawSprite(224,
#ifdef VERSION_EU
                   (s16)((18 / w->unk_285) * w->unk_284 + 108),
#else
                   (s16)((17 / w->unk_285) * w->unk_284 + 108),
#endif
                   gUnk_09EEB000, *(void**)&w->unk_040[0x1A0], w->palette, 0, 0, 40);
    }
    if (w->unk_2BE == 0 && w->unk_299 != 9 && w->unk_29A != 9) {
        DrawSprite(120, 56, 0, w->tiles4, w->palette, 0, 8, 60);
        DrawSprite(120, 56, gUnk_08F709B0[4].gfx2, w->tiles2, w->palette, 0, 8, 60);
    }
    DrawSprite(128, (s16)(w->y3 >> 8), gUnk_09EF11AC[0], *(void**)&w->unk_040[0x1A8], *(void**)&w->unk_040[8], 0, 0x800, 80);
    DrawSprite(128, (s16)(w->y4 >> 8), gUnk_09EF11AC[1], *(void**)&w->unk_040[0x1A8], *(void**)&w->unk_040[8], 0, 0x800, 80);
    DrawTextSlots(16, (s16)(w->unk_244 >> 8), &w->unk_040[12], *(void**)&w->unk_040[0x18C], 50, w->unk_287[0]);
    TaskPoolDraw(&w->tasks);
}
void MapSelect_3(MapSelectWork* w) {
    TaskPoolDestroy(&w->tasks);

    if (w->unk_2E0 != 0) {
        EwramFree(w->unk_2E0);
    }

    FadeSetPaletteExcluded((*(UnkStruct_080038C8**)&w->unk_040[0x08])->index + 16, 0);
    FadeSetPaletteExcluded((*(UnkStruct_080038C8**)&w->unk_040[0x00])->index + 16, 0);
    FadeSetPaletteExcluded(15, 0);
    FadeSetPaletteExcluded((*(UnkStruct_080038C8**)&w->unk_040[0x18C])->index + 16, 0);
    ReleaseObjTiles(*(void**)&w->unk_040[0x04]);
    ReleaseObjPalette(*(void**)&w->unk_040[0x08]);
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(*(void**)&w->unk_040[0x00]);
    ReleaseObjTiles(w->tiles3);

    if (w->tiles4 != 0) {
        ReleaseObjTiles(w->tiles4);
    }

    if (w->tiles2 != 0) {
        ReleaseObjTiles(w->tiles2);
    }

    if (w->palette != 0) {
        ReleaseObjPalette(w->palette);
    }

    ReleaseObjTiles(*(void**)&w->unk_040[0x1A8]);
    FreeTextSlots(&w->unk_040[0x0C], 48);
    ReleaseObjPalette(*(void**)&w->unk_040[0x18C]);
    *w->unk_294 = 1;
    ReleaseObjTiles(*(void**)&w->unk_040[0x1A0]);
    ReleaseObjTiles(gUnk_0203A890.tiles);
    ReleaseObjTiles(gUnk_0203A890.extraTiles);
}
void func_0809332C(MapSelectWork* w) {
    MapcardArgs args;
    u16* q;
    u16 i;

    for (i = 0; i < w->unk_27C; i++) {
        q = (u16*)w->unk_2E0;
        args.unk_00 = q[i * 2];
        args.unk_01 = i;
        args.unk_02 = w->unk_27C;
        args.unk_03 = q[i * 2 + 1];
        args.unk_08 = &w->cards;
        args.unk_04 = w;
        CreateMapCard(&args, (u8*)w);
    }
}

u16 func_08093384(void) {
    u16 count;
    u16 i;
    u16 j;

    count = 0;

    for (j = 0; j < 27; j++) {
        for (i = j * 10; i < j * 10 + 10; i++) {
            if (gUnk_0203A8C0[i] != 0) {
                count++;
                break;
            }
        }
    }

    return count;
}

void func_080933D8(UnkStruct_080933D8* p) {
    u16 i;
    u16 j;

    for (i = 0; i <= 26; i++) {
        j = i * 10;

        while (j < i * 10 + 10) {
            if (gUnk_0203A8C0[j] != 0) {
                p->unk_00 = i * 10;
                p->unk_02 = gUnk_0203A8C0[j];
                p++;
                break;
            }

            j++;
        }
    }
}

void func_08093434(MapSelectWork* work) {
    MapcardWork* a;
    MapcardWork* b;
    MapcardWork* found;
    MapcardWork* p;
    MapcardWork* c;
    s8 cnt;

    if (work->unk_298 != 0) {
        return;
    }

    if (work->card == 0) {
        return;
    }

    switch (GetKeysRepeat() & 0xF0) {
    case 16:
        p = (MapcardWork*)ListPoolNext(&work->card->node);

        if (p != 0 && (p->unk_6C & 1)) {
            work->unk_264 = p->x;
            work->unk_28C = 4;
            work->card->unk_6C &= 0xFEFF;
            work->card = (MapcardWork*)ListPoolNext(&work->card->node);
            work->card->unk_6C |= 0x100;
            m4aSongNumStart(121);
        }
        break;
    case 32:
        p = ListPoolPrev(&work->card->node);

        if (p != 0 && (p->unk_6C & 1)) {
            work->unk_264 = p->x;
            work->unk_28C = 4;
            work->card->unk_6C &= 0xFEFF;
            work->card = ListPoolPrev(&work->card->node);
            work->card->unk_6C |= 0x100;
            m4aSongNumStart(121);
        }
        break;
    case 128:
        a = (MapcardWork*)ListPoolFirst(&work->cards);
        b = 0;
        found = 0;
        cnt = 0;

        while (a != 0) {
            if (a->unk_6C & 1) {
                b = a;
                break;
            }

            a = (MapcardWork*)ListPoolNext(&a->node);
        }

counting:
        if (b != 0) {
            if (b->unk_6C & 1) {
                cnt++;
                b = (MapcardWork*)ListPoolNext(&b->node);
                goto counting;
            }

            if (cnt == 6) {
                found = b;
            }
        }

        if (found != 0) {
            work->card2 = found;
            work->unk_298 = 1;

            if (a != 0) {
                do {
                    if (a->unk_6C & 1) {
                        a->x = -0x6400;
                        a->unk_6C &= 0xFEFF;
                        a = (MapcardWork*)ListPoolNext(&a->node);
                    } else {
                        break;
                    }
                } while (a != 0);
            }

            m4aSongNumStart(121);
        }

        b = (MapcardWork*)ListPoolFirst(&work->cards);

        while (b != 0) {
            if (b->x == -0x6400) {
                a->unk_6C &= 0xFEFF;
            }

            b = (MapcardWork*)ListPoolNext(&b->node);
        }
        break;
    case 64:
        a = (MapcardWork*)ListPoolFirst(&work->cards);
        b = 0;

        while (a != 0) {
            if (a->unk_6C & 1) {
                b = a;
                break;
            }

            a = (MapcardWork*)ListPoolNext(&a->node);
        }

        if (ListPoolPrev(&a->node) != 0) {
            work->card2 = ListPoolPrev(&a->node);
            work->unk_298 = 2;

            if (b != 0) {
                c = b;

                do {
                    if ((c->unk_6C & 1) == 0) {
                        break;
                    }

                    b->x = -0x6400;
                    b = c = (MapcardWork*)ListPoolNext(&b->node);
                } while (b != 0);
            }

            m4aSongNumStart(121);
        }

        b = (MapcardWork*)ListPoolFirst(&work->cards);

        while (b != 0) {
            if (b->x == -0x6400) {
                a->unk_6C &= 0xFEFF;
            }

            b = (MapcardWork*)ListPoolNext(&b->node);
        }
        break;
    }

    ApproachValue(&work->x2, work->unk_264, work->unk_28C);

    if (work->unk_28C != 0) {
        work->unk_28C--;
    }
}

void func_08093708(MapSelectWork* w) {
    MapcardWork* node;
    s8 i;

    switch (w->unk_298) {
    case 0:
        break;
    case 1:
        node = w->card2;
        i = 0;
        while (node != 0) {
            node->x = gUnk_09EE7520[i++] << 8;
            if (i == 6) {
                break;
            }
            node = ListPoolNext(&node->node);
        }
        w->unk_298 = 0;
        func_08093838(w);
        if (w->card != 0) {
            w->unk_264 = w->card->x;
            w->unk_28C = 4;
        }
        w->unk_284++;
        break;
    case 2:
        node = w->card2;
        i = 5;
        while (node != 0) {
            node->x = gUnk_09EE7520[i--] << 8;
            if (i < 0) {
                break;
            }
            node = ListPoolPrev(&node->node);
        }
        w->unk_298 = 0;
        func_08093838(w);
        if (w->card != 0) {
            w->unk_264 = w->card->x;
            w->unk_28C = 4;
        }
        w->unk_284--;
        break;
    }
}

s32 func_08093838(MapSelectWork* w) {
    MapcardWork* node;
    s32 best;
    s32 d;
    u16 r;
    void* z;
    u8* q;

    node = (MapcardWork*)ListPoolFirst(&w->cards);
    best = 0x100;
    z = 0;
    w->card = z;

    while (node != 0) {
        if (node->x != -0x6400) {
            d = (node->x >> 8) - (w->x2 >> 8);
            r = Sqrt(d * d);

            if (best > r) {
                best = r;
                w->card = node;
            }
        }

        node = (MapcardWork*)ListPoolNext(&node->node);
    }

    q = (u8*)w->card;

    if (q != 0) {
        q += 0x6C;
        r = *(u16*)q | 0x100;
        *(u16*)q = r;

        return (((MapcardWork*)w->card)->x - w->x2) >> 8;
    }

    return 0;
}
u16 CountMapCards(void) {
    u8 sum;
    s32 i;

    sum = 0;

    for (i = 0; i <= 0x10D; i++) {
        sum += gUnk_0203A8C0[i];
    }

    return sum;
}

s32 AddMapCard(u16 a) {
    if (func_08093B38() <= 98) {
        if (gUnk_0203A8C0[a] <= 8) {
            gUnk_0203A8C0[a]++;

            switch (gUnk_09EE4C80[a].unk_20) {
            case 0:
                func_0800FDD0(209);
                break;
            case 1:
                func_0800FDD0(210);
                break;
            case 2:
                func_0800FDD0(211);
                break;
            case 3:
                func_0800FDD0(212);
                break;
            case 4:
                func_0800FDD0(213);
                break;
            case 5:
                func_0800FDD0(214);
                break;
            case 6:
                func_0800FDD0(215);
                break;
            case 7:
                func_0800FDD0(216);
                break;
            case 8:
                func_0800FDD0(217);
                break;
            case 9:
                func_0800FDD0(218);
                break;
            case 10:
                func_0800FDD0(219);
                break;
            case 11:
                func_0800FDD0(220);
                break;
            case 12:
                func_0800FDD0(221);
                break;
            case 13:
                func_0800FDD0(222);
                break;
            case 14:
                func_0800FDD0(223);
                break;
            case 15:
                func_0800FDD0(224);
                break;
            case 16:
                func_0800FDD0(225);
                break;
            case 17:
                func_0800FDD0(226);
                break;
            case 18:
                func_0800FDD0(227);
                break;
            case 19:
                func_0800FDD0(228);
                break;
            case 20:
                func_0800FDD0(229);
                break;
            case 21:
                func_0800FDD0(230);
                break;
            case 22:
                func_0800FDD0(231);
                break;
            case 23:
                func_0800FDD0(232);
                break;
            case 24:
                func_0800FDD0(233);
                break;
            case 25:
                func_0800FDD0(234);
                break;
            }

            return 1;
        }
    } else {
        if (gUnk_09EE4C80[a].unk_20 > 21) {
            gUnk_0203A8C0[a]++;

            switch (gUnk_09EE4C80[a].unk_20) {
            case 22:
                func_0800FDD0(231);
                break;
            case 23:
                func_0800FDD0(232);
                break;
            case 24:
                func_0800FDD0(233);
                break;
            case 25:
                func_0800FDD0(234);
                break;
            }

            return 1;
        }
    }

    return 0;
}

s32 RemoveMapCard(u16 a) {
    if (gUnk_0203A8C0[a] != 0) {
        gUnk_0203A8C0[a]--;
        return 1;
    }

    return 0;
}

s32 AddRandomMapCard(void) {
    AddMapCard(GetRandom() % 270);
}

u16 func_08093B08(u16 a) {
    u16 sum;
    s32 i;

    sum = 0;

    for (i = a; i < a + 10; i++) {
        sum += gUnk_0203A8C0[i];
    }

    return sum;
}

u16 func_08093B38(void) {
    u16 sum;
    s32 i;

    sum = 0;

    for (i = 0; i < 220; i++) {
        sum += gUnk_0203A8C0[i];
    }

    return sum;
}

u16 func_08093B58(void) {
    u16 sum;
    s32 i;

    sum = 0;

    for (i = 0; i < 27; i++) {
        sum += gUnk_0203A8C0[i * 10];
    }

    return sum;
}

void CreateMapCardSelection(void* a, void* b) {
    TaskCreate(a, &gTaskDescMapSelect, b);
}

void ClearMapCardInventory(void) {
    u16 i;

    for (i = 0; i < 270; i++) {
        gUnk_0203A8C0[i] = 0;
    }
}

void InitMapCardInventory(void) {
#ifdef VERSION_EU
    s32 i;
#endif

    ClearMapCardInventory();

#ifdef VERSION_EU
    if (gUnk_03006C10 & 8) {
        AddMapCard(211);
        AddMapCard(191);

        for (i = 0; i <= 219; i += 10) {
            if (CountMapCards() <= 98) {
                AddMapCard(i);
            }
        }

        AddMapCard(221);
        AddMapCard(231);
        AddMapCard(241);
        AddMapCard(251);
    } else {
        AddMapCard(191);
    }
#else
    if (!(gUnk_03006C10 & 8)) {
        AddMapCard(191);
    }
#endif
}

u8 func_08093BD4(void) {
    return gUnk_02034ACC;
}

void func_08093BE0(void) {
    gUnk_02034ACC = 1;
}

void func_08093BEC(u32 a) {
    gUnk_02034AD0 = a;
}

u32 func_08093BF8(void) {
    return gUnk_02034AD0;
}

void func_08093C04(void) {
    gUnk_02034AD0 = 0;
    gUnk_02034ACC = 0;
}

void* func_08093C18(u16 a) {
#ifdef VERSION_EU
    return eu_0805E924(gUnk_09EF7048[a]);
#else
    return gUnk_09EF7048[a];
#endif
}

u8 HasMapCard(u16 a) {
    if (gUnk_0203A8C0[a] != 0) {
        return 1;
    }

    return 0;
}

void func_08093C44(u16 a, MapSelectWork* w) {
    u16 i;
    u16 j;
    u8* pal;
    s32 k;
    s32 k2;
    MapCardDef* card;
    MapCardDef* cards;

    for (i = 0; i < 22; i++) {
        pal = w->unk_29E;
        pal[i] = gUnk_09619098[i + 32];
    }

    for (i = 22; i < 32; i++) {
        pal = w->unk_29E;
        pal[i] = gUnk_09618C58[i + 64];
    }

    for (i = a, j = 2; i < a + 10; i++, j += 2) {
        cards = gUnk_09EE4C80;
        card = &cards[a];
        pal = w->unk_29E;

        if (gUnk_0203A8C0[i] != 0) {
            if (card->backIndex != 4) {
                pal[j] = -1;
                k = j + 1;
                pal[k] = 0x7F;
            } else {
                pal[j] = gUnk_09618C58[j];
                k2 = j + 1;
                pal[k2] = gUnk_09618C58[k2];
            }
        }
    }

    LoadPalette(w->unk_29E, (void*)0x050001C0, 32);
}

void func_08093D28(u16 a, MapSelectWork* w) {
    u16 i;
    u16 j;
    u8* pal;
    MapcardWork** mp;
    s32 k;

    for (i = 0; i < 22; i++) {
        pal = w->unk_29E;
        pal[i] = gUnk_09619098[i + 32];
    }

    for (i = 22, j = 2; i < 26; i++, j++) {
        mp = &w->card;
        pal = w->unk_29E;

        switch ((*mp)->cardDef->backIndex) {
        case 1:
            pal[i] = gUnk_09619098[j + 0x60];
            break;
        case 2:
            pal[i] = gUnk_09619098[j + 0x40];
            break;
        case 3:
            pal[i] = gUnk_09619098[j + 0xA0];
            break;
        case 4:
            pal[i] = gUnk_09619098[j + 0x80];
            break;
        }
    }

    for (i = 26; i < 32; i++) {
        pal = w->unk_29E;
        pal[i] = gUnk_09618C58[i];
    }

    for (i = a, j = 2; i < a + 10; i++, j += 2) {
        pal = w->unk_29E;

        if (gUnk_0203A8C0[i] != 0) {
            pal[j] = -1;
            k = j + 1;
            pal[k] = 0x7F;
        }
    }

    LoadPalette(w->unk_29E, (void*)0x05000180, 32);
}

s32 func_08093E34(u16 a, MapSelectWork* w) {
    u16 i;
    u16 j;
    u8 count;
    u8* src;
    u32 base;

    for (i = a, j = 0; i < a + 10; i++, j++) {
        if (gUnk_0203A8C0[i] != 0) {
            count = gUnk_0203A8C0[i];

            if (count > 9) {
                count = 9;
                gUnk_0203A8C0[i] = count;
            }

            src = &gUnk_09507F38[(count + 1) * 32];
            base = GetBgCharBase(1);
            base += gUnk_09EE4BE0[i - a] * 32;
            RequestDma3Copy(src, (void*)base, 32);
            w->unk_2D0[j] = count;
        } else {
            base = GetBgCharBase(1);
            base += gUnk_09EE4BE0[i - a] * 32;
            RequestDma3Copy(gUnk_09507F58, (void*)base, 32);
            w->unk_2D0[j] = 0;
        }
    }

    for (i = 0; i < 10; i++) {
        if (w->unk_2D0[i] != 0) {
            return (s8)i;
        }
    }

    return -1;
}

s32 func_08093F1C(MapSelectWork* w) {
    u8* p;
    s32 base;
    u8 i;

    i = 4;
    base = (s8)w->unk_29D * 5;
    p = w->unk_2D0;

    do {
        if (p[i + base] == 0) {
            i--;
        } else {
            return (s8)i;
        }
    } while (i != 0);

    return -1;
}

void func_08093F5C(MapSelectWork* w) {
    s8 c0;
    s8 y0;
    s32 z;

    c0 = w->unk_29C;
    y0 = w->unk_29D;
    z = 0;

    switch (GetKeysRepeat() & 0xF0) {
    case 16:
        do {
            if ((s8)w->unk_29C <= 3) {
                w->unk_29C++;
            } else {
                w->unk_29C = 0;
                w->unk_29D ^= 1;
            }
        } while (w->unk_2D0[(s8)w->unk_29C + (s8)w->unk_29D * 5] == 0);

        w->unk_28C = 4;
        break;
    case 32:
        do {
            if ((s8)w->unk_29C > 0) {
                w->unk_29C--;
            } else {
                w->unk_29C = 4;
                w->unk_29D ^= 1;
            }
        } while (w->unk_2D0[(s8)w->unk_29C + (s8)w->unk_29D * 5] == 0);

        w->unk_28C = 4;
        break;
    case 64:
        w->unk_29D ^= 1;
        c0 = w->unk_29C;

        while (w->unk_2D0[(s8)w->unk_29C + (s8)w->unk_29D * 5] == 0) {
            if ((s8)w->unk_29C > 3) {
                z = 1;
                goto up_done;
            }

            w->unk_29C++;
            z = 0;
        }

    up_done:
        if (z == 1) {
            w->unk_29C = func_08093F1C(w);

            if ((s8)w->unk_29C == -1) {
                w->unk_29D ^= 1;
                w->unk_29C = c0;
            }
        }

        w->unk_28C = 4;
        break;
    case 128:
        w->unk_29D ^= 1;
        c0 = w->unk_29C;

        while (w->unk_2D0[(s8)w->unk_29C + (s8)w->unk_29D * 5] == 0) {
            if ((s8)w->unk_29C > 3) {
                z = 1;
                goto down_done;
            }

            w->unk_29C++;
            z = 0;
        }

    down_done:
        if (z == 1) {
            w->unk_29C = func_08093F1C(w);

            if ((s8)w->unk_29C == -1) {
                w->unk_29D ^= 1;
                w->unk_29C = c0;
            }
        }

        w->unk_28C = 4;
        break;
    }

    if (c0 != (s8)w->unk_29C || y0 != (s8)w->unk_29D) {
        m4aSongNumStart(121);
    }

    ApproachValue(&w->x2, gUnk_09EE4BB8[(s8)w->unk_29C] << 8, w->unk_28C);
    ApproachValue(&w->y2, gUnk_09EE4BC2[(s8)w->unk_29D] << 8, w->unk_28C);
    ApproachValue(&w->x, gUnk_09EE4BB8[(s8)w->unk_29C] << 8, w->unk_28B);
    ApproachValue(&w->y, (gUnk_09EE4BC2[(s8)w->unk_29D] + 34) << 8,
                  w->unk_28B);

    if (w->unk_28B != 0) {
        w->unk_28B--;
    }

    if (w->unk_28C != 0) {
        w->unk_28C--;
    }
}

u8 func_0809423C(MapSelectWork* w, void* a) {
    MapcardWork* n;
    u8 v;

    SetObjMosaicSize(w->unk_299, w->unk_29A);

    if (w->unk_29B == 2) {
        if (w->unk_299 != 0) {
            w->unk_299--;
        }

        if (w->unk_29A != 0) {
            w->unk_29A--;
        }

        w->unk_29B = 0;
    }

    w->unk_29B++;

    if (!func_080A42C8()) {
        if (w->unk_286 == 8) {
            w->unk_286 = 0;

            if (w->unk_2C2 <= 98) {
                func_080A4188((u8*)w, w->unk_2C2);
                w->unk_2C2++;
            } else {
                n = (MapcardWork*)ListPoolFirst(&w->cards);
                SetBgMapBlocks(1, gUnk_09EE4BB0, 1, 2);

                while (n != 0) {
                    n->unk_6C |= 2;
                    n = (MapcardWork*)ListPoolNext(&n->node);
                }

                if (w->unk_27C <= 6) {
                    w->unk_285 = 0;
                } else {
                    v = w->unk_27C / 6;
                    w->unk_285 = v;
                }
                w->y2 = 0x6400;
                w->y = 0x7A00;
                w->unk_244 = 0x9100;
                SetTaskUpdate(a, (void*)func_08092A34);
                w->unk_2C0 = 1;
                w->unk_2C2 = 99;
                return 1;
            }
        } else {
            w->unk_286++;
        }
    }

    TaskPoolUpdate(&w->tasks);
    return 1;
}

u8 func_0809438C(MapSelectWork* w, void* a) {
    u8 r;

    r = func_080A42C8();

    if (r == 0) {
        if (w->unk_286 == 8) {
            w->unk_286 = 0;

            if (w->unk_2C2 <= 0x66) {
                func_080A4188((u8*)w, w->unk_2C2);
                w->unk_2C2++;
            } else {
                gGameState.progression.unk_82 |= 8;
                SetTaskUpdate(a, (void*)func_0809254C);
            }
        } else {
            w->unk_286++;
        }
    }

    TaskPoolUpdate(&w->tasks);
    return 1;
}

u8 func_08094404(MapSelectWork* w, void* a) {
    MapcardWork* node;
    u32 pages;

    SetObjMosaicSize(w->unk_299, w->unk_29A);
    if (w->unk_29B == 2) {
        if (w->unk_299 != 0) {
            w->unk_299--;
        }
        if (w->unk_29A != 0) {
            w->unk_29A--;
        }
        w->unk_29B = 0;
    }
    w->unk_29B++;

    if (!func_080A42C8()) {
        if (w->unk_286 == 8) {
            w->unk_286 = 0;
            if (w->unk_2C2 <= 0x71) {
                func_080A4188((u8*)w, w->unk_2C2);
                w->unk_2C2++;
            } else {
                node = ListPoolFirst(&w->cards);
                SetBgMapBlocks(1, gUnk_09EE4BB0, 1, 2);
                while (node != 0) {
                    node->unk_6C |= 2;
                    node = ListPoolNext(&node->node);
                }
                if (w->unk_27C <= 6) {
                    w->unk_285 = 0;
                } else {
                    pages = w->unk_27C / 6;
                    w->unk_285 = pages;
                }
                w->y2 = 0x6400;
                w->y = 0x7A00;
                w->unk_244 = 0x9100;
                SetTaskUpdate(a, (void*)func_08092A34);
                w->unk_2C0 = 1;
                return 1;
            }
        } else {
            w->unk_286++;
        }
    }
    TaskPoolUpdate(&w->tasks);
    return 1;
}

void func_08094548(MapSelectWork* w) {
    MapcardWork* n;
    s32 v;
    s32 i;

    v = w->unk_23C >> 8;

    for (i = 0; i < 6; i++) {
        if (v == gUnk_09EE7520[i]) {
            break;
        }
    }

    n = ListPoolRemove(&w->card->node, &w->cards);
    w->card->unk_6C |= 0x400;
    w->card = n;

    while (n != 0) {
        n->unk_21--;

        if (i <= 5) {
            n->x = gUnk_09EE7520[i] << 8;
            i++;
        }

        n = (MapcardWork*)ListPoolNext(&n->node);
    }

    for (n = (MapcardWork*)ListPoolFirst(&w->cards); n != 0; n = (MapcardWork*)ListPoolNext(&n->node)) {
        n->unk_6C |= 2;
    }

    if (w->card == 0) {
        w->card = ListPoolLast(&w->cards);

        if (w->card == 0) {
            w->unk_264 = 0x1600;
        } else {
            w->unk_264 = w->card->x;
        }
    } else {
        w->unk_264 = w->card->x;
    }
}

void Mapcard_0(MapcardWork* w, MapcardArgs* a) {
    w->tiles = 0;
    w->unk_04 = 0;
    w->tiles2 = 0;
    w->palette = 0;
    *(MapcardArgs*)&w->unk_20 = *a;
    w->x = w->unk_21 <= 5 ? gUnk_09EE7520[w->unk_21] << 8 : -0x6400;
    w->y = 0x10500;
    w->unk_6A = 50;
    w->unk_5C = 0;
    w->unk_60 = 0;
    w->unk_64 = 0;
    w->unk_6C = 0;
    w->unk_6E = 0;
    w->unk_6F = 16;
    w->unk_70 = 0;
    w->unk_68 = 0x100;
    w->unk_71 = 0;
    w->unk_72 = 0;
    w->unk_74 = gUnk_09EE4C80[w->unk_20].unk_22;
    w->cardDef = &gUnk_09EE4C80[w->unk_20];
    w->cardBack = &gUnk_09EE4BF4[w->cardDef->backIndex];
    func_08094E90(w);
    func_08094DA8(w);
    func_08094CE4(w);
}

s32 func_080948F0(MapcardWork* w, void* a);

u8 Mapcard_1(MapcardWork* w, void* a) {
    if (w->unk_6C & 0xC) {
        w->unk_6F = 12;
        func_08094DEC(w);
        SetTaskUpdate(a, (void*)func_080948F0);
    }

    if (w->unk_6C & 0x200) {
        w->unk_6E = 0;
        w->unk_6F = 8;
        SetTaskUpdate(a, (void*)func_080947B4);
    }

    if (w->unk_6C & 0x40) {
        w->unk_6E = 0;
        w->unk_6F = 8;
        SetTaskUpdate(a, (void*)func_08094934);
    }

    if (w->unk_6C & 0x400) {
        return 0;
    }

    w->unk_6E = 0;
    func_08094DA8(w);
    func_08094CE4(w);
    return 1;
}

u8 func_080947B4(MapcardWork* w, void* a) {
    ApproachValue(&w->x, gUnk_09EE7520[0] << 8, w->unk_6F);
    w->unk_6F--;

    if (!(w->unk_6C & 0x200)) {
        w->unk_6F = 8;
        SetTaskUpdate(a, (void*)func_0809486C);
    }

    if (w->unk_6C & 0x100) {
        w->unk_6E += 8;
    } else {
        w->unk_6E = 0;
    }

    if (w->unk_6C & 0x40) {
        w->unk_6E = 0;
        w->unk_6F = 8;
        SetTaskUpdate(a, (void*)func_08094934);
    }

    if (w->unk_6C & 0x400) {
        return 0;
    }

    func_08094DA8(w);
    func_08094CE4(w);
    return 1;
}

u8 func_0809486C(MapcardWork* w, void* a) {
    ApproachValue(&w->x, gUnk_09EE7520[w->unk_21 % 6] << 8, w->unk_6F);
    w->unk_6F--;

    if (w->unk_6F == 0) {
        SetTaskUpdate(a, Mapcard_1);
    }

    if (w->unk_6C & 0x100) {
        w->unk_6E += 8;
    } else {
        w->unk_6E = 0;
    }

    func_08094DA8(w);
    func_08094CE4(w);
    return 1;
}

s32 func_080948F0(MapcardWork* w, void* a) {
    u8 t;

    t = func_08094E4C(w);
    func_08094DA8(w);
    func_08094CE4(w);

    if (t == 0) {
        w->unk_6C &= 0xFFF3;
        SetTaskUpdate(a, Mapcard_1);
    }

    return 1;
}

u8 func_08094934(MapcardWork* w, void* a) {
    w->unk_6E = 0;
    ApproachValue(&w->x, 0x7800, w->unk_6F);
    ApproachValue(&w->y, 0x3800, w->unk_6F);

    if (w->unk_6F != 0) {
        w->unk_6F--;
    } else {
        w->unk_70++;

        if (w->unk_70 > 15) {
            func_080949A0(w);
            SetTaskUpdate(a, (void*)func_08094A18);
        }
    }

    func_08094CE4(w);
    return 1;
}

void func_080949A0(MapcardWork* w) {
    s32 v[2];
    s32 dx;
    s32 dy;
    s32* p = func_080E04E0();

    dx = (p[0] >> 8) - (gUnk_02039BA0->x >> 8);
    dy = (p[1] >> 8) + (p[2] >> 8) - (gUnk_02039BA0->y >> 8) - 24;
    v[0] = dx * 256 - w->x;
    v[1] = dy * 256 - w->y;
    w->unk_64 = NormalizeVector2D8(&v[0], &v[1]);
    w->unk_54 = -v[0];
    w->unk_58 = -v[1];
    w->unk_60 = 0x300;
    w->unk_5C = 25;
    w->unk_6E = 0;
    w->unk_68 = 0x100;
}

u8 func_08094A18(MapcardWork* w, void* a) {
    s32* p;
    s32 dx;
    s32 dy;
    s32 d;
    s32 x;
    s32 y;
    u16 t;
    u16 f;

    p = func_080E04E0();
    dx = (p[0] >> 8) - (gUnk_02039BA0->x >> 8);
    dy = (p[1] >> 8) + (p[2] >> 8) - (gUnk_02039BA0->y >> 8) - 24;

    if (w->unk_60 < 0) {
        x = (dx << 8) - w->x;
        y = (dy << 8) - w->y;
        NormalizeVector2D8(&x, &y);
        w->unk_54 = -x;
        w->unk_58 = -y;
    }

    {
        u8* q = &w->unk_6E;
        *q += 24;
        t = *(u16*)(q - 6);
        *(u16*)(q - 6) = (s16)t > 25 ? t - 12 : 25;
    }
    w->x += (w->unk_54 * w->unk_60) >> 8;
    w->y += (w->unk_58 * w->unk_60) >> 8;
    d = VectorLength2D((dx << 8) - w->x, (dy << 8) - w->y);
    w->unk_64 = d;
    w->unk_60 -= w->unk_5C;
    w->unk_5C += 2;

    if ((*(u8**)((u8*)w + 0x24))[0x2BE] != 1) {
        if (d <= 0x7FF) {
            func_08093BE0();
            f = w->unk_6C | 0x80;
            w->unk_6C = f;
            func_08093BEC((u32)&gUnk_09EE4C80[w->unk_20 + w->unk_74] + 0x20);
        }
    } else {
        if (d <= 0x7FF && (*(u8**)((u8*)w + 0x24))[0x2DA] == 0) {
            func_08093BE0();
            f = w->unk_6C | 0x80;
            w->unk_6C = f;
            func_08093BEC((u32)&gUnk_09EE4C80[w->unk_20 + w->unk_74] + 0x20);
        }
    }

    return 1;
}

void Mapcard_2(MapcardWork* w) {
    s32 aff;
    u16 y;
    void* sprite;

    if (func_080A42C8() == 0) {
        y = (w->y >> 8) + (gSineTable[w->unk_6E] >> 8);

        if (w->unk_6C & 1) {
            if (w->x > 0) {
                if (w->x <= 0xEFFF) {
                    goto draw;
                }
            }

            do {
                return;
            } while (0);

        draw:
            aff = 0;

            if (w->unk_6C & 0x40) {
                aff = AllocObjAffine(w->unk_6E, (s16)w->unk_68, (s16)w->unk_68, 1);
            }

            if (gUnk_09EE4C80[w->unk_20].backIndex == 4) {
                DrawSprite(w->x >> 8, y, gUnk_0203A890.gfx, gUnk_0203A890.tiles, *(void**)&w->unk_10[4], aff, 0,
                           (u16)(w->unk_6A - 2));
            }

            sprite = w->cardBack->sprites[0];
            DrawSprite(w->x >> 8, y, sprite, *(void**)&w->unk_10[0], *(void**)&w->unk_10[4], aff, 0, w->unk_6A);
            sprite = w->cardDef->sprites[0];
            DrawSprite(w->x >> 8, y, sprite, w->tiles2, w->palette, aff, 0, (u16)(w->unk_6A + 1));
        }
    }
}

void Mapcard_3(MapcardWork* w) {
    if (w->unk_6C & 1) {
        ReleaseObjTiles(w->tiles2);
        ReleaseObjPalette(w->palette);
        ReleaseObjTiles(*(void**)&w->unk_10[0]);
        ReleaseObjPalette(*(void**)&w->unk_10[4]);
    }
}

u8 func_08094CB0(s32* p) {
    if (p[19] >= -4096) {
        if (p[19] <= 0x10000) {
            if (p[20] >= -5120) {
                if (p[20] <= 0xC000) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

void func_08094CE4(MapcardWork* w) {
    UnkStruct_08094CE4_A* a;
    UnkStruct_08094CE4_B* b;
    u16 t;

    if (func_08094CB0((s32*)w)) {
        if (!(w->unk_6C & 1)) {
            a = (UnkStruct_08094CE4_A*)w->cardDef;
            b = (UnkStruct_08094CE4_B*)w->cardBack;
            w->tiles2 = LoadObjTiles(a->tiles, a->tilesSize);
            w->palette = LoadObjPalette(a->palette, 32);
            *(void**)&w->unk_10[0] = LoadObjTiles(b->tiles, b->tilesSize);
            *(void**)&w->unk_10[4] = LoadObjPalette(b->palette, 32);
            w->tiles = LoadObjTiles(gUnk_0905EAE8, 0x1E0);
            FadeSetPaletteExcluded(((UnkStruct_080038C8*)w->palette)->index + 16, 1);
            FadeSetPaletteExcluded(((UnkStruct_080038C8*)*(void**)&w->unk_10[4])->index + 16, 1);
            t = w->unk_6C | 1;
            w->unk_6C = t;
        }
    } else if (w->unk_6C & 1) {
        ReleaseObjTiles(w->tiles);
        ReleaseObjTiles(w->tiles2);
        ReleaseObjPalette(w->palette);
        ReleaseObjTiles(*(void**)&w->unk_10[0]);
        ReleaseObjPalette(*(void**)&w->unk_10[4]);
        w->unk_6C &= ~1;
    }
}

void func_08094DA8(MapcardWork* w) {
    if (w->unk_6C & 2) {
        ApproachValue(&w->y, 0x7900, w->unk_6F);
    } else {
        ApproachValue(&w->y, 0x10500, w->unk_6F);
    }

    if (w->unk_6F != 0) {
        w->unk_6F--;
    }
}
void func_08094DEC(MapcardWork* w) {
    if ((w->unk_6C & 4) && w->unk_60 - w->unk_5C > 0x8000) {
        w->unk_5C += 0x10000;
    }

    if ((w->unk_6C & 8) && w->unk_60 < w->unk_5C) {
        w->unk_5C -= 0x10000;
    }

    ApproachValue(&w->unk_5C, w->unk_60, w->unk_6F);
    w->unk_6F--;
}
u8 func_08094E4C(MapcardWork* w) {
    ApproachValue(&w->unk_5C, w->unk_60, w->unk_6F);

    if (w->unk_6F != 0) {
        w->unk_6F--;
        return 1;
    }

    return 0;
}
void* CreateMapCard(void* a, void* b) {
    return ((void**)TaskCreate(b, &gTaskDescMapcard, a))[1];
}
void func_08094E90(MapcardWork* w) {
    ListNodeInit(&w->node, w->pool, w);
    ListPoolAppend(&w->node, w->pool);
}
void Reload_Gage_0(ReloadGageWork* w, ReloadGageArgs* a) {
    UnkStruct_08095A5C* d;
    ReloadChildArgs args;
    u16 v;
    s8 n;
    s8 i;

    w->tiles = 0;
    w->tiles2 = 0;
    w->tiles4 = 0;
    w->tiles3 = 0;
    w->tiles5 = 0;
    w->palette = 0;
    w->unk_A1 = 0;
    *(ReloadGageArgs*)&w->pool2 = *a;
    w->unk_78 = 0;
    w->unk_9C = 16;
    w->unk_84 = 0;
    w->unk_9F = 0;
    w->unk_A0 = 4;
    w->unk_88 = 0x2400;
    w->unk_80 = 0;
    w->unk_7C = 0;
    w->unk_20 = EwramAlloc(0x68);
    w->unk_A2 = 0;
    w->unk_A3 = 0;
    d = w->unk_20;
    v = a->unk_0C;

    if ((s16)v >= 0) {
        d->unk_64 = v;
    } else {
        d->unk_64 = -1;
    }

    if (d->unk_64 > 17) {
        d->unk_64 = 18;
    }

    d->unk_65 = 0;
    w->pool = EwramAlloc(0x10);

    switch (w->unk_40) {
    case 1:
        w->unk_8C = gUnk_09033FF4[0][0];
        w->unk_90 = gUnk_09033FF4[0][1];
        w->unk_4C = gUnk_09033FF4[4][0];
        w->unk_50 = gUnk_09033FF4[4][1];
        w->unk_94 = w->unk_98 = 0x2000;
        w->unk_78 |= 0x8000000;
        break;
    case 2:
        w->unk_8C = gUnk_0903401C[0][0];
        w->unk_90 = gUnk_0903401C[0][1];
        w->unk_4C = gUnk_0903401C[4][0];
        w->unk_50 = gUnk_0903401C[4][1];
        w->unk_94 = w->unk_98 = -0x2000;
        break;
    }

    w->unk_54 = 0x100;
    w->unk_58 = 0;
    ListPoolInit(w->pool);
    ListNodeInit(&w->node, w->pool2, w);
    ListPoolAppend(&w->node, w->pool2);
    w->tiles2 = LoadObjTiles(gUnk_09EE75A8[w->unk_46], 0x280);
    w->tiles3 = AllocObjTiles(0x200, 0);
    SetObjTileSource(w->tiles3, gUnk_09EE75A8[1]);
    w->tiles4 = AllocObjTiles(0x80, 0);
    SetObjTileSource(w->tiles4, gUnk_09EE75A8[1]);
    func_08095B50(w->unk_20, w, w->unk_46);
    w->tiles = LoadObjTiles(gUnk_0905F03C, 0x80);
    w->palette = LoadObjPalette(gUnk_08F69BA4, 32);
    w->tiles5 = AllocObjTiles(0x100, 0);
    SetObjTileSource(w->tiles5, gUnk_09EE7578[w->unk_46]);
    func_08095A78(w->unk_20, w->tiles5, w->unk_46, d->unk_64);
    w->unk_78 |= 0x1000026;

    if (d->unk_64 >= 0) {
        TaskPoolInit(&w->tasks, d->unk_64 + 1);
        n = d->unk_64;

        if (d->unk_64 > 3) {
            n = 3;
        }

        for (i = 0; i < n; i++) {
            args.unk_00 = w->pool;
            args.unk_0C = i;
            args.unk_04 = &w->unk_4C;
            args.unk_08 = &w->unk_50;
            *(u16*)args.unk_10 = 0;
            args.unk_0D = w->unk_46;
            args.unk_0E = w->unk_40;
            TaskCreate(&w->tasks, &gTaskDescReloadChildren, &args);
        }
    } else {
        TaskPoolInit(&w->tasks, 1);
    }
}

u8 Reload_Gage_1(ReloadGageWork* w, void* a) {
    ReloadChildArgs args;
    UnkStruct_08095A5C* p;
    ReloadChildWork* node;
    ReloadChildWork* child;
    s32 flags;
    u8 v;

    p = w->unk_20;
    v = 0;

    switch (w->unk_40) {
    case 1:
        if (gUnk_02039DD4->unk_0D2 == w->unk_46) {
            v = gUnk_02039DD4->unk_0E7;
            gUnk_02039DD4->unk_0E7 = 0;
        }
        break;
    case 2:
        if (gUnk_02039DD4->unk_0D4 == w->unk_46) {
            v = gUnk_02039DD4->unk_0E8;
            gUnk_02039DD4->unk_0E8 = 0;
        }
        break;
    }

    if ((w->unk_78 & 0x44) == 0x44) {
        if (v == 1) {
            if ((s8)p->unk_65 == 2) {
                switch (w->unk_40) {
                case 1:
                    if ((gBtlWork->unk_068 & 0x1000000) == 0) {
                        m4aSongNumStart(200);
                        gBtlWork->unk_068 |= 0x1000000;
                    }
                    break;
                case 2:
                    if ((gUnk_02039B9C->unk_068 & 0x1000000) == 0) {
                        m4aSongNumStart(200);
                        gUnk_02039B9C->unk_068 |= 0x1000000;
                    }
                    break;
                }

                node = (ReloadChildWork*)ListPoolFirst(w->pool);

                while (node != 0) {
                    node->unk_1C &= 0xFFFD;
                    node = (ReloadChildWork*)ListPoolNext(&node->node);
                }

                if (w->unk_9F == 0) {
                    w->unk_58 += 25;

                    if (w->unk_58 > 0x100) {
                        w->unk_58 = 0x100;
                        w->unk_9F = 1;
                    }
                } else {
                    w->unk_A0 += 3;
                    func_08095C00(w->unk_20, w);

                    if (w->unk_A0 == 10) {
                        w->unk_A0 = 4;
                        w->unk_58 = 0;
                        w->unk_9F = 0;
                        child = (ReloadChildWork*)ListPoolFirst(w->pool);

                        while (child != 0) {
                            child->unk_1C |= 1;
                            child->unk_18--;
                            child = (ReloadChildWork*)ListPoolNext(&child->node);
                        }

                        p->unk_64--;

                        if (p->unk_64 > 2) {
                            args.unk_00 = w->pool;
                            args.unk_0C = 3;
                            args.unk_04 = &w->unk_4C;
                            args.unk_08 = &w->unk_50;
                            *(u16*)args.unk_10 = 0;
                            args.unk_0D = w->unk_46;
                            args.unk_0E = w->unk_40;
                            child = ((ReloadChildWork**)TaskCreate(&w->tasks, &gTaskDescReloadChildren, &args))[1];
                            flags = child->unk_1C | 1;
                            flags &= 0xFFFD;
                            child->unk_1C = flags;
                            child->unk_18--;
                        }

                        w->unk_9C = 8;
                        w->unk_A2 = 1;
                        func_08095C20(w->unk_20);
                        m4aSongNumStart(201);
                    }
                }

                switch (w->unk_40) {
                case 1:
                    if (gBtlWork->unk_0F4 == 9) {
                        p->unk_65 = 1;
                    } else if (gBtlWork->unk_0F4 == 43) {
                        p->unk_65 = 254;
                    } else {
                        p->unk_65 = 0;
                    }
                    break;
                case 2:
                    if (gUnk_02039B9C->unk_0F4 == 9) {
                        p->unk_65 = 1;
                    } else if (gUnk_02039B9C->unk_0F4 == 43) {
                        p->unk_65 = 254;
                    } else {
                        p->unk_65 = 0;
                    }
                    break;
                }
            }

            func_08095BAC(w->unk_20, w);
            p->unk_65++;
        } else {
            func_08095BC8(w->unk_20, w);
            p->unk_65 = 0;
            w->unk_78 |= 0x8000000;
            m4aSongNumStop(200);

            switch (w->unk_40) {
            case 1:
                gBtlWork->unk_068 &= ~0x1000000;
                break;
            case 2:
                gUnk_02039B9C->unk_068 &= ~0x1000000;
                break;
            }

            node = (ReloadChildWork*)ListPoolFirst(w->pool);

            while (node != 0) {
                node->unk_1C |= 2;
                node = (ReloadChildWork*)ListPoolNext(&node->node);
            }
        }
    }

    if (p->unk_64 < 0) {
        if ((w->unk_78 & 0x4000000) == 0) {
            w->unk_78 |= 0x4000000;
            m4aSongNumStart(202);
        }

        if (FadeGetAmount() == 0) {
            FadeFromAmount(2, 16, 20);
        }

        return 0;
    }

    func_08095B04(w->unk_20, w);

    if (w->unk_A2 == 1 && w->unk_9C == 1) {
        func_08095AD8(w->unk_20, p->unk_64);
    }

    func_080958E0(w);

    if (w->unk_78 & 0x4000) {
        return 0;
    }

    func_08095A5C(w->unk_20);
    w->unk_5C[3] += 4;

    if ((w->unk_78 & 0x20) == 0) {
        SetTaskUpdate(a, (void*)func_080954C4);
        m4aSongNumStop(200);

        switch (w->unk_40) {
        case 1:
            gBtlWork->unk_068 &= ~0x1000000;
            break;
        case 2:
            gUnk_02039B9C->unk_068 &= ~0x1000000;
            break;
        }
    }

    TaskPoolUpdate(&w->tasks);
    return 1;
}

u8 func_080954C4(ReloadGageWork* w, void* a) {
    if (w->unk_A1 == 7) {
        return 0;
    }

    w->unk_84 += -w->unk_84 >> 1;
    w->unk_4C += (gUnk_09033FF4[4][0] - w->unk_4C) >> 1;
    w->unk_50 += (gUnk_09033FF4[4][1] - w->unk_50) >> 1;

    if (w->unk_78 & 0x20) {
        SetTaskUpdate(a, (void*)Reload_Gage_1);
    }

    return 1;
}
void Reload_Gage_2(CardDisplayWork* p) {
    u8* q;
    s32 affine;
    void* gfx;
    s32 t;

    q = p->unk_20;
    gfx = gUnk_08F709B0[p->unk_46].gfx2;
    DrawSprite((p->x >> 8) + (*(s32*)&q[4] >> 8),
               (p->y >> 8) + (gSineTable[p->unk_5F] >> 8),
               gfx, p->tiles2,
               gUnk_02039DD4->palette, 0, 0x400, 50);

    if (p->unk_58 > 0) {
        affine = AllocObjAffine(0, 0x100, p->unk_58, 0);
        DrawSprite((p->x >> 8) + (*(s32*)&q[4] >> 8),
                   (p->y >> 8) + (t = (gSineTable[p->unk_5F] >> 8) + 17),
                   *(void**)&q[0x58], p->tiles3, gUnk_02039DD4->palette, affine,
                   0x400, 49);

        if (p->unk_9F == 1) {
            DrawSprite((p->x >> 8) + (*(s32*)&q[4] >> 8),
                       (p->y >> 8) + (gSineTable[p->unk_5F] >> 8),
                       *(void**)&q[0x5C], p->tiles4, gUnk_02039DD4->palette, 0,
                       0x400, 49);
        }
    }

    if (*(void**)&q[0x60] != 0) {
        DrawSprite((p->x >> 8) + (*(s32*)&q[4] >> 8),
                   (p->y >> 8) + (gSineTable[p->unk_5F] >> 8),
                   *(void**)&q[0x60], *(void**)&p->unk_10[0],
                   gUnk_02039DD4->palette, 0, 0x400, 48);
    }

    TaskPoolDraw(&p->unk_24[0]);
}
void Reload_Gage_3(CardDisplayWork* p) {
    TaskPoolDestroy(&p->unk_24[0]);
    ReleaseObjPalette(p->palette);
    ReleaseObjTiles(p->tiles);
    ReleaseObjTiles(p->tiles2);
    ReleaseObjTiles(p->tiles3);
    ReleaseObjTiles(p->tiles4);
    ReleaseObjTiles(*(void**)&p->unk_10[0]);
    EwramFree(*(void**)&p->unk_1C[0]);
    EwramFree(p->unk_20);

    switch (*(s32*)&p->unk_40[0]) {
    case 1:
        gBtlWork->unk_068 &= ~0x1000000;

        switch (gBtlWork->unk_0F4) {
        case 9:
        case 10:
        case 25:
        case 30:
        case 40:
        case 43:
        case 54:
            gBtlWork->unk_0F8--;
            break;
        }
        break;
    case 2:
        gUnk_02039B9C->unk_068 &= ~0x1000000;

        switch (gUnk_02039B9C->unk_0F4) {
        case 9:
        case 10:
        case 25:
        case 30:
        case 40:
        case 43:
        case 54:
            gUnk_02039B9C->unk_0F8--;
            break;
        }
        break;
    }

    ListPoolRemove(&p->node, p->pool);
}
void func_080958E0(ReloadGageWork* w) {
    ApproachValue(&w->unk_94, w->unk_98, w->unk_A3);
    if (w->unk_A3 != 0) {
        w->unk_A3--;
    }
    w->unk_84 += (w->unk_88 - w->unk_84) >> 1;
    if (w->unk_9C > 0) {
        w->unk_9C--;
        w->unk_78 &= ~0x40;
    } else {
        w->unk_9C = 0;
        w->unk_78 |= 0x40;
    }

    switch (w->unk_40) {
    case 1:
        w->unk_8C = gSineTable[(w->unk_94 >> 8) & 0xFF] * 80 + gUnk_09033FF4[0][0];
        w->unk_90 = -gSineTable[((w->unk_94 >> 8) & 0xFF) + 0x40] * 80 + gUnk_09033FF4[0][1];
        w->unk_4C = gSineTable[0x20] * (w->unk_84 >> 8) + w->unk_8C;
        w->unk_50 = -gSineTable[0x60] * (w->unk_84 >> 8) + w->unk_90;
        break;
    case 2:
        w->unk_8C = gSineTable[(w->unk_94 >> 8) & 0xFF] * 80 + gUnk_0903401C[0][0];
        w->unk_90 = -gSineTable[((w->unk_94 >> 8) & 0xFF) + 0x40] * 80 + gUnk_0903401C[0][1];
        w->unk_4C = gSineTable[0xE0] * (w->unk_84 >> 8) + w->unk_8C;
        w->unk_50 = -gSineTable[0x120] * (w->unk_84 >> 8) + w->unk_90;
        break;
    }
}
void func_08095A5C(UnkStruct_08095A5C* p) {
    p->unk_00 = gSineTable[(u8)p->unk_02] >> 8;
    p->unk_02 += 16;
}
void func_08095A78(UnkStruct_08095A5C* p, void* a, u8 b, u8 c) {
    AnimInit(&p->anim, gUnk_09EE7588[b], gUnk_09EE7598[b]);

    if ((s8)c >= 0) {
        AnimStart(&p->anim, (u16)(s8)c, 0);
    } else {
        AnimStart(&p->anim, 0, 0);
    }

    p->gfx3 = AnimGetGfx(&p->anim);
}
void func_08095AD8(UnkStruct_08095A5C* p, u16 a) {
    void* gfx;

    if (a <= 18) {
        AnimStart(&p->anim, a, 0);
        gfx = AnimGetGfx(&p->anim);
    } else {
        gfx = 0;
    }

    p->gfx3 = gfx;
}
s32 func_08095B04(u8* p, ReloadGageWork* w) {
    if (w->unk_9C > 0 && w->unk_A2 == 1) {
        switch (w->unk_40) {
        case 1:
            ApproachValue(&p[4], -0x3000, (u16)w->unk_9C);
            break;
        case 2:
            ApproachValue(&p[4], 0x12000, (u16)w->unk_9C);
            break;
        }
    } else {
        *(u32*)&p[4] = 0;
    }
}
void func_08095B50(UnkStruct_08095A5C* p, ReloadGageWork* w, u8 idx) {
    p->unk_0D = 2;
    AnimInit(&p->anim2, gUnk_09EE75C8[idx], gUnk_09EE75B8[idx]);
    AnimStart(&p->anim2, 1, 1);
    p->gfx = gUnk_09EE75B8[idx][3];
    AnimInit(&p->anim3, gUnk_09EE75C8[idx], gUnk_09EE75B8[idx]);
    AnimStart(&p->anim3, 2, 1);
    p->gfx2 = gUnk_09EE75B8[idx][6];
}
void func_08095BAC(UnkStruct_08095A5C* p) {
    p->gfx = AnimUpdate(&p->anim2);
    p->gfx2 = AnimUpdate(&p->anim3);
}
void func_08095BC8(UnkStruct_08095A5C* p, ReloadGageWork* w) {
    p->gfx = gUnk_09EE75B8[w->unk_46][3];
    p->gfx2 = gUnk_09EE75B8[w->unk_46][w->unk_A0 + 2];
}
void func_08095C00(UnkStruct_08095A5C* p) {
    if (p->unk_0D <= 3) {
        p->unk_0D++;
    }

    AnimStart(&p->anim3, p->unk_0D, 5);
}
void func_08095C20(u8* p) {
    p[13] = 2;
}
void* func_08095C28(u8* w, u16 b, void* pool, u8 mode) {
    ReloadGageArgs args;

    args.unk_00 = &w[(s8)w[0xB8] * 16 + 0x54];
    args.unk_04 = 0;

    switch (mode) {
    case 1:
        if (gBtlWork->unk_0F4 == 10) {
            args.unk_0C = b - 2;
        } else {
            args.unk_0C = b;
        }
        break;
    case 2:
        if (gUnk_02039B9C->unk_0F4 == 10) {
            args.unk_0C = b - 2;
        } else {
            args.unk_0C = b;
        }
        break;
    }

    args.unk_08 = mode;
    args.unk_0E = w[0xB8];
    return ((void**)TaskCreate(pool, &gTaskDescReloadGage, &args))[1];
}

const char gUnk_090359BC[] = "WORLDSELECT";
#ifdef VERSION_EU
const u16 gUnkEu_090CED64[5] = {
    864, 864, 864, 864, 864,
};
#endif

Mode gModeWORLDSELECT = {
    gUnk_090359BC,
    (void (*)(s32))WORLDSELECT_0,
    WORLDSELECT_1,
    WORLDSELECT_2,
};
#ifdef VERSION_EU
void* gUnkEu_09F6FF30[5] = {
    gUnk_093F6734, gUnkEu_094C9860, gUnk_093F6734, gUnkEu_094C9860, gUnkEu_094C9C20,
};

void** gUnkEu_09F6FF44[5] = {
    gUnk_09EF11F8, gUnkEu_09F7C454, gUnk_09EF11F8, gUnkEu_09F7C454, gUnkEu_09F7C47C,
};
#endif

const void* gUnk_09EE4BB0[2] = {
    gUnk_08125E24, gUnk_096102B8,
};

s16 gUnk_09EE4BB8[5] = {
    59, 99, 139, 179, 219,
};

s16 gUnk_09EE4BC2[2] = {
    88, 112,
};
#ifdef VERSION_EU
void** gUnkEu_09F6FF70[5] = {
    gUnk_09EF1228, gUnkEu_09F7C414, gUnkEu_09F7C42C, gUnkEu_09F7C424, gUnkEu_09F7C41C,
};
#endif

const char gTaskNameMapSelect[] = "MapSelect";

TaskDesc gTaskDescMapSelect = {
    gTaskNameMapSelect,
    (void (*)(void*, void*))MapSelect_0,
    MapSelect_1,
    (void (*)(void*))MapSelect_2,
    (void (*)(void*))MapSelect_3,
    0x2E4,
};

u16 gUnk_09EE4BE0[10] = {
    72, 77, 82, 87, 92, 168, 173, 178, 183, 188,
};

MapCardBackDef gUnk_09EE4BF4[5] = {
    { gUnk_093F61B2, gUnk_09618D78, gUnk_09EF11E8, gUnk_0905E3BA, gUnk_09EE97F4, 640, 32, { 128, 2, 0, 0 } },
    { gUnk_093F5C7A, gUnk_09618D78, gUnk_09EF11D8, gUnk_0905C862, gUnk_09EE9764, 640, 32, { 128, 2, 0, 0 } },
    { gUnk_093F5F16, gUnk_09618D78, gUnk_09EF11E0, gUnk_0905D64E, gUnk_09EE97AC, 640, 32, { 128, 2, 0, 0 } },
    { gUnk_093F61B2, gUnk_09618D78, gUnk_09EF11E8, gUnk_0905AC8A, gUnk_09EE96D4, 640, 32, { 128, 2, 0, 0 } },
    { gUnk_093F644E, gUnk_09618D78, gUnk_09EF11F0, gUnk_0905E3BA, gUnk_09EE97F4, 640, 32, { 128, 2, 0, 0 } },
};

MapCardDef gUnk_09EE4C80[260] = {
    { gUnk_093EF27C, gUnk_096185B8, gUnk_09EF0FB0, gUnk_093F2148, gUnk_09618898, gUnk_09EF1068, 512, 32, 256, 2, 0, 1, 0, 2, 0 },
    { gUnk_093EF27C, gUnk_096185B8, gUnk_09EF0FB0, gUnk_093F2148, gUnk_09618898, gUnk_09EF1068, 512, 32, 256, 2, 0, 1, 1, 2, 0 },
    { gUnk_093EF27C, gUnk_096185B8, gUnk_09EF0FB0, gUnk_093F2148, gUnk_09618898, gUnk_09EF1068, 512, 32, 256, 2, 0, 1, 2, 2, 0 },
    { gUnk_093EF27C, gUnk_096185B8, gUnk_09EF0FB0, gUnk_093F2148, gUnk_09618898, gUnk_09EF1068, 512, 32, 256, 2, 0, 1, 3, 2, 0 },
    { gUnk_093EF27C, gUnk_096185B8, gUnk_09EF0FB0, gUnk_093F2148, gUnk_09618898, gUnk_09EF1068, 512, 32, 256, 2, 0, 1, 4, 2, 0 },
    { gUnk_093EF27C, gUnk_096185B8, gUnk_09EF0FB0, gUnk_093F2148, gUnk_09618898, gUnk_09EF1068, 512, 32, 256, 2, 0, 1, 5, 2, 0 },
    { gUnk_093EF27C, gUnk_096185B8, gUnk_09EF0FB0, gUnk_093F2148, gUnk_09618898, gUnk_09EF1068, 512, 32, 256, 2, 0, 1, 6, 2, 0 },
    { gUnk_093EF27C, gUnk_096185B8, gUnk_09EF0FB0, gUnk_093F2148, gUnk_09618898, gUnk_09EF1068, 512, 32, 256, 2, 0, 1, 7, 2, 0 },
    { gUnk_093EF27C, gUnk_096185B8, gUnk_09EF0FB0, gUnk_093F2148, gUnk_09618898, gUnk_09EF1068, 512, 32, 256, 2, 0, 1, 8, 2, 0 },
    { gUnk_093EF27C, gUnk_096185B8, gUnk_09EF0FB0, gUnk_093F2148, gUnk_09618898, gUnk_09EF1068, 512, 32, 256, 2, 0, 1, 9, 2, 0 },
    { gUnk_093EF068, gUnk_09618598, gUnk_09EF0FA8, gUnk_093F2034, gUnk_09618878, gUnk_09EF1060, 512, 32, 256, 2, 0, 0, 0, 2, 0 },
    { gUnk_093EF068, gUnk_09618598, gUnk_09EF0FA8, gUnk_093F2034, gUnk_09618878, gUnk_09EF1060, 512, 32, 256, 2, 0, 0, 1, 2, 0 },
    { gUnk_093EF068, gUnk_09618598, gUnk_09EF0FA8, gUnk_093F2034, gUnk_09618878, gUnk_09EF1060, 512, 32, 256, 2, 0, 0, 2, 2, 0 },
    { gUnk_093EF068, gUnk_09618598, gUnk_09EF0FA8, gUnk_093F2034, gUnk_09618878, gUnk_09EF1060, 512, 32, 256, 2, 0, 0, 3, 2, 0 },
    { gUnk_093EF068, gUnk_09618598, gUnk_09EF0FA8, gUnk_093F2034, gUnk_09618878, gUnk_09EF1060, 512, 32, 256, 2, 0, 0, 4, 2, 0 },
    { gUnk_093EF068, gUnk_09618598, gUnk_09EF0FA8, gUnk_093F2034, gUnk_09618878, gUnk_09EF1060, 512, 32, 256, 2, 0, 0, 5, 2, 0 },
    { gUnk_093EF068, gUnk_09618598, gUnk_09EF0FA8, gUnk_093F2034, gUnk_09618878, gUnk_09EF1060, 512, 32, 256, 2, 0, 0, 6, 2, 0 },
    { gUnk_093EF068, gUnk_09618598, gUnk_09EF0FA8, gUnk_093F2034, gUnk_09618878, gUnk_09EF1060, 512, 32, 256, 2, 0, 0, 7, 2, 0 },
    { gUnk_093EF068, gUnk_09618598, gUnk_09EF0FA8, gUnk_093F2034, gUnk_09618878, gUnk_09EF1060, 512, 32, 256, 2, 0, 0, 8, 2, 0 },
    { gUnk_093EF068, gUnk_09618598, gUnk_09EF0FA8, gUnk_093F2034, gUnk_09618878, gUnk_09EF1060, 512, 32, 256, 2, 0, 0, 9, 2, 0 },
    { gUnk_093EFCE0, gUnk_09618658, gUnk_09EF0FD8, gUnk_093F26AC, gUnk_09618938, gUnk_09EF1090, 512, 32, 256, 2, 0, 6, 0, 2, 0 },
    { gUnk_093EFCE0, gUnk_09618658, gUnk_09EF0FD8, gUnk_093F26AC, gUnk_09618938, gUnk_09EF1090, 512, 32, 256, 2, 0, 6, 1, 2, 0 },
    { gUnk_093EFCE0, gUnk_09618658, gUnk_09EF0FD8, gUnk_093F26AC, gUnk_09618938, gUnk_09EF1090, 512, 32, 256, 2, 0, 6, 2, 2, 0 },
    { gUnk_093EFCE0, gUnk_09618658, gUnk_09EF0FD8, gUnk_093F26AC, gUnk_09618938, gUnk_09EF1090, 512, 32, 256, 2, 0, 6, 3, 2, 0 },
    { gUnk_093EFCE0, gUnk_09618658, gUnk_09EF0FD8, gUnk_093F26AC, gUnk_09618938, gUnk_09EF1090, 512, 32, 256, 2, 0, 6, 4, 2, 0 },
    { gUnk_093EFCE0, gUnk_09618658, gUnk_09EF0FD8, gUnk_093F26AC, gUnk_09618938, gUnk_09EF1090, 512, 32, 256, 2, 0, 6, 5, 2, 0 },
    { gUnk_093EFCE0, gUnk_09618658, gUnk_09EF0FD8, gUnk_093F26AC, gUnk_09618938, gUnk_09EF1090, 512, 32, 256, 2, 0, 6, 6, 2, 0 },
    { gUnk_093EFCE0, gUnk_09618658, gUnk_09EF0FD8, gUnk_093F26AC, gUnk_09618938, gUnk_09EF1090, 512, 32, 256, 2, 0, 6, 7, 2, 0 },
    { gUnk_093EFCE0, gUnk_09618658, gUnk_09EF0FD8, gUnk_093F26AC, gUnk_09618938, gUnk_09EF1090, 512, 32, 256, 2, 0, 6, 8, 2, 0 },
    { gUnk_093EFCE0, gUnk_09618658, gUnk_09EF0FD8, gUnk_093F26AC, gUnk_09618938, gUnk_09EF1090, 512, 32, 256, 2, 0, 6, 9, 2, 0 },
    { gUnk_093EFEF4, gUnk_09618678, gUnk_09EF0FE0, gUnk_093F27C0, gUnk_09618958, gUnk_09EF1098, 512, 32, 256, 2, 0, 7, 0, 2, 0 },
    { gUnk_093EFEF4, gUnk_09618678, gUnk_09EF0FE0, gUnk_093F27C0, gUnk_09618958, gUnk_09EF1098, 512, 32, 256, 2, 0, 7, 1, 2, 0 },
    { gUnk_093EFEF4, gUnk_09618678, gUnk_09EF0FE0, gUnk_093F27C0, gUnk_09618958, gUnk_09EF1098, 512, 32, 256, 2, 0, 7, 2, 2, 0 },
    { gUnk_093EFEF4, gUnk_09618678, gUnk_09EF0FE0, gUnk_093F27C0, gUnk_09618958, gUnk_09EF1098, 512, 32, 256, 2, 0, 7, 3, 2, 0 },
    { gUnk_093EFEF4, gUnk_09618678, gUnk_09EF0FE0, gUnk_093F27C0, gUnk_09618958, gUnk_09EF1098, 512, 32, 256, 2, 0, 7, 4, 2, 0 },
    { gUnk_093EFEF4, gUnk_09618678, gUnk_09EF0FE0, gUnk_093F27C0, gUnk_09618958, gUnk_09EF1098, 512, 32, 256, 2, 0, 7, 5, 2, 0 },
    { gUnk_093EFEF4, gUnk_09618678, gUnk_09EF0FE0, gUnk_093F27C0, gUnk_09618958, gUnk_09EF1098, 512, 32, 256, 2, 0, 7, 6, 2, 0 },
    { gUnk_093EFEF4, gUnk_09618678, gUnk_09EF0FE0, gUnk_093F27C0, gUnk_09618958, gUnk_09EF1098, 512, 32, 256, 2, 0, 7, 7, 2, 0 },
    { gUnk_093EFEF4, gUnk_09618678, gUnk_09EF0FE0, gUnk_093F27C0, gUnk_09618958, gUnk_09EF1098, 512, 32, 256, 2, 0, 7, 8, 2, 0 },
    { gUnk_093EFEF4, gUnk_09618678, gUnk_09EF0FE0, gUnk_093F27C0, gUnk_09618958, gUnk_09EF1098, 512, 32, 256, 2, 0, 7, 9, 2, 0 },
    { gUnk_093EF8B8, gUnk_09618618, gUnk_09EF0FC8, gUnk_093F2484, gUnk_096188F8, gUnk_09EF1080, 512, 32, 256, 2, 0, 4, 0, 2, 0 },
    { gUnk_093EF8B8, gUnk_09618618, gUnk_09EF0FC8, gUnk_093F2484, gUnk_096188F8, gUnk_09EF1080, 512, 32, 256, 2, 0, 4, 1, 2, 0 },
    { gUnk_093EF8B8, gUnk_09618618, gUnk_09EF0FC8, gUnk_093F2484, gUnk_096188F8, gUnk_09EF1080, 512, 32, 256, 2, 0, 4, 2, 2, 0 },
    { gUnk_093EF8B8, gUnk_09618618, gUnk_09EF0FC8, gUnk_093F2484, gUnk_096188F8, gUnk_09EF1080, 512, 32, 256, 2, 0, 4, 3, 2, 0 },
    { gUnk_093EF8B8, gUnk_09618618, gUnk_09EF0FC8, gUnk_093F2484, gUnk_096188F8, gUnk_09EF1080, 512, 32, 256, 2, 0, 4, 4, 2, 0 },
    { gUnk_093EF8B8, gUnk_09618618, gUnk_09EF0FC8, gUnk_093F2484, gUnk_096188F8, gUnk_09EF1080, 512, 32, 256, 2, 0, 4, 5, 2, 0 },
    { gUnk_093EF8B8, gUnk_09618618, gUnk_09EF0FC8, gUnk_093F2484, gUnk_096188F8, gUnk_09EF1080, 512, 32, 256, 2, 0, 4, 6, 2, 0 },
    { gUnk_093EF8B8, gUnk_09618618, gUnk_09EF0FC8, gUnk_093F2484, gUnk_096188F8, gUnk_09EF1080, 512, 32, 256, 2, 0, 4, 7, 2, 0 },
    { gUnk_093EF8B8, gUnk_09618618, gUnk_09EF0FC8, gUnk_093F2484, gUnk_096188F8, gUnk_09EF1080, 512, 32, 256, 2, 0, 4, 8, 2, 0 },
    { gUnk_093EF8B8, gUnk_09618618, gUnk_09EF0FC8, gUnk_093F2484, gUnk_096188F8, gUnk_09EF1080, 512, 32, 256, 2, 0, 4, 9, 2, 0 },
    { gUnk_093EF6A4, gUnk_096185F8, gUnk_09EF0FC0, gUnk_093F2370, gUnk_096188D8, gUnk_09EF1078, 512, 32, 256, 2, 0, 3, 0, 2, 0 },
    { gUnk_093EF6A4, gUnk_096185F8, gUnk_09EF0FC0, gUnk_093F2370, gUnk_096188D8, gUnk_09EF1078, 512, 32, 256, 2, 0, 3, 1, 2, 0 },
    { gUnk_093EF6A4, gUnk_096185F8, gUnk_09EF0FC0, gUnk_093F2370, gUnk_096188D8, gUnk_09EF1078, 512, 32, 256, 2, 0, 3, 2, 2, 0 },
    { gUnk_093EF6A4, gUnk_096185F8, gUnk_09EF0FC0, gUnk_093F2370, gUnk_096188D8, gUnk_09EF1078, 512, 32, 256, 2, 0, 3, 3, 2, 0 },
    { gUnk_093EF6A4, gUnk_096185F8, gUnk_09EF0FC0, gUnk_093F2370, gUnk_096188D8, gUnk_09EF1078, 512, 32, 256, 2, 0, 3, 4, 2, 0 },
    { gUnk_093EF6A4, gUnk_096185F8, gUnk_09EF0FC0, gUnk_093F2370, gUnk_096188D8, gUnk_09EF1078, 512, 32, 256, 2, 0, 3, 5, 2, 0 },
    { gUnk_093EF6A4, gUnk_096185F8, gUnk_09EF0FC0, gUnk_093F2370, gUnk_096188D8, gUnk_09EF1078, 512, 32, 256, 2, 0, 3, 6, 2, 0 },
    { gUnk_093EF6A4, gUnk_096185F8, gUnk_09EF0FC0, gUnk_093F2370, gUnk_096188D8, gUnk_09EF1078, 512, 32, 256, 2, 0, 3, 7, 2, 0 },
    { gUnk_093EF6A4, gUnk_096185F8, gUnk_09EF0FC0, gUnk_093F2370, gUnk_096188D8, gUnk_09EF1078, 512, 32, 256, 2, 0, 3, 8, 2, 0 },
    { gUnk_093EF6A4, gUnk_096185F8, gUnk_09EF0FC0, gUnk_093F2370, gUnk_096188D8, gUnk_09EF1078, 512, 32, 256, 2, 0, 3, 9, 2, 0 },
    { gUnk_093F17E4, gUnk_096187F8, gUnk_09EF1040, gUnk_093F34B0, gUnk_09618AD8, gUnk_09EF10F8, 512, 32, 256, 2, 0, 19, 0, 2, 0 },
    { gUnk_093F17E4, gUnk_096187F8, gUnk_09EF1040, gUnk_093F34B0, gUnk_09618AD8, gUnk_09EF10F8, 512, 32, 256, 2, 0, 19, 1, 2, 0 },
    { gUnk_093F17E4, gUnk_096187F8, gUnk_09EF1040, gUnk_093F34B0, gUnk_09618AD8, gUnk_09EF10F8, 512, 32, 256, 2, 0, 19, 2, 2, 0 },
    { gUnk_093F17E4, gUnk_096187F8, gUnk_09EF1040, gUnk_093F34B0, gUnk_09618AD8, gUnk_09EF10F8, 512, 32, 256, 2, 0, 19, 3, 2, 0 },
    { gUnk_093F17E4, gUnk_096187F8, gUnk_09EF1040, gUnk_093F34B0, gUnk_09618AD8, gUnk_09EF10F8, 512, 32, 256, 2, 0, 19, 4, 2, 0 },
    { gUnk_093F17E4, gUnk_096187F8, gUnk_09EF1040, gUnk_093F34B0, gUnk_09618AD8, gUnk_09EF10F8, 512, 32, 256, 2, 0, 19, 5, 2, 0 },
    { gUnk_093F17E4, gUnk_096187F8, gUnk_09EF1040, gUnk_093F34B0, gUnk_09618AD8, gUnk_09EF10F8, 512, 32, 256, 2, 0, 19, 6, 2, 0 },
    { gUnk_093F17E4, gUnk_096187F8, gUnk_09EF1040, gUnk_093F34B0, gUnk_09618AD8, gUnk_09EF10F8, 512, 32, 256, 2, 0, 19, 7, 2, 0 },
    { gUnk_093F17E4, gUnk_096187F8, gUnk_09EF1040, gUnk_093F34B0, gUnk_09618AD8, gUnk_09EF10F8, 512, 32, 256, 2, 0, 19, 8, 2, 0 },
    { gUnk_093F17E4, gUnk_096187F8, gUnk_09EF1040, gUnk_093F34B0, gUnk_09618AD8, gUnk_09EF10F8, 512, 32, 256, 2, 0, 19, 9, 2, 0 },
    { gUnk_093F19F8, gUnk_09618818, gUnk_09EF1048, gUnk_093F35C4, gUnk_09618AF8, gUnk_09EF1100, 512, 32, 256, 2, 0, 20, 0, 2, 0 },
    { gUnk_093F19F8, gUnk_09618818, gUnk_09EF1048, gUnk_093F35C4, gUnk_09618AF8, gUnk_09EF1100, 512, 32, 256, 2, 0, 20, 1, 2, 0 },
    { gUnk_093F19F8, gUnk_09618818, gUnk_09EF1048, gUnk_093F35C4, gUnk_09618AF8, gUnk_09EF1100, 512, 32, 256, 2, 0, 20, 2, 2, 0 },
    { gUnk_093F19F8, gUnk_09618818, gUnk_09EF1048, gUnk_093F35C4, gUnk_09618AF8, gUnk_09EF1100, 512, 32, 256, 2, 0, 20, 3, 2, 0 },
    { gUnk_093F19F8, gUnk_09618818, gUnk_09EF1048, gUnk_093F35C4, gUnk_09618AF8, gUnk_09EF1100, 512, 32, 256, 2, 0, 20, 4, 2, 0 },
    { gUnk_093F19F8, gUnk_09618818, gUnk_09EF1048, gUnk_093F35C4, gUnk_09618AF8, gUnk_09EF1100, 512, 32, 256, 2, 0, 20, 5, 2, 0 },
    { gUnk_093F19F8, gUnk_09618818, gUnk_09EF1048, gUnk_093F35C4, gUnk_09618AF8, gUnk_09EF1100, 512, 32, 256, 2, 0, 20, 6, 2, 0 },
    { gUnk_093F19F8, gUnk_09618818, gUnk_09EF1048, gUnk_093F35C4, gUnk_09618AF8, gUnk_09EF1100, 512, 32, 256, 2, 0, 20, 7, 2, 0 },
    { gUnk_093F19F8, gUnk_09618818, gUnk_09EF1048, gUnk_093F35C4, gUnk_09618AF8, gUnk_09EF1100, 512, 32, 256, 2, 0, 20, 8, 2, 0 },
    { gUnk_093F19F8, gUnk_09618818, gUnk_09EF1048, gUnk_093F35C4, gUnk_09618AF8, gUnk_09EF1100, 512, 32, 256, 2, 0, 20, 9, 2, 0 },
    { gUnk_093F1C0C, gUnk_09618838, gUnk_09EF1050, gUnk_093F36D8, gUnk_09618B18, gUnk_09EF1108, 512, 32, 256, 2, 0, 21, 0, 2, 0 },
    { gUnk_093F1C0C, gUnk_09618838, gUnk_09EF1050, gUnk_093F36D8, gUnk_09618B18, gUnk_09EF1108, 512, 32, 256, 2, 0, 21, 1, 2, 0 },
    { gUnk_093F1C0C, gUnk_09618838, gUnk_09EF1050, gUnk_093F36D8, gUnk_09618B18, gUnk_09EF1108, 512, 32, 256, 2, 0, 21, 2, 2, 0 },
    { gUnk_093F1C0C, gUnk_09618838, gUnk_09EF1050, gUnk_093F36D8, gUnk_09618B18, gUnk_09EF1108, 512, 32, 256, 2, 0, 21, 3, 2, 0 },
    { gUnk_093F1C0C, gUnk_09618838, gUnk_09EF1050, gUnk_093F36D8, gUnk_09618B18, gUnk_09EF1108, 512, 32, 256, 2, 0, 21, 4, 2, 0 },
    { gUnk_093F1C0C, gUnk_09618838, gUnk_09EF1050, gUnk_093F36D8, gUnk_09618B18, gUnk_09EF1108, 512, 32, 256, 2, 0, 21, 5, 2, 0 },
    { gUnk_093F1C0C, gUnk_09618838, gUnk_09EF1050, gUnk_093F36D8, gUnk_09618B18, gUnk_09EF1108, 512, 32, 256, 2, 0, 21, 6, 2, 0 },
    { gUnk_093F1C0C, gUnk_09618838, gUnk_09EF1050, gUnk_093F36D8, gUnk_09618B18, gUnk_09EF1108, 512, 32, 256, 2, 0, 21, 7, 2, 0 },
    { gUnk_093F1C0C, gUnk_09618838, gUnk_09EF1050, gUnk_093F36D8, gUnk_09618B18, gUnk_09EF1108, 512, 32, 256, 2, 0, 21, 8, 2, 0 },
    { gUnk_093F1C0C, gUnk_09618838, gUnk_09EF1050, gUnk_093F36D8, gUnk_09618B18, gUnk_09EF1108, 512, 32, 256, 2, 0, 21, 9, 2, 0 },
    { gUnk_093F0958, gUnk_09618718, gUnk_09EF1008, gUnk_093F2D24, gUnk_096189F8, gUnk_09EF10C0, 512, 32, 256, 1, 0, 12, 0, 1, 0 },
    { gUnk_093F0958, gUnk_09618718, gUnk_09EF1008, gUnk_093F2D24, gUnk_096189F8, gUnk_09EF10C0, 512, 32, 256, 1, 0, 12, 1, 1, 0 },
    { gUnk_093F0958, gUnk_09618718, gUnk_09EF1008, gUnk_093F2D24, gUnk_096189F8, gUnk_09EF10C0, 512, 32, 256, 1, 0, 12, 2, 1, 0 },
    { gUnk_093F0958, gUnk_09618718, gUnk_09EF1008, gUnk_093F2D24, gUnk_096189F8, gUnk_09EF10C0, 512, 32, 256, 1, 0, 12, 3, 1, 0 },
    { gUnk_093F0958, gUnk_09618718, gUnk_09EF1008, gUnk_093F2D24, gUnk_096189F8, gUnk_09EF10C0, 512, 32, 256, 1, 0, 12, 4, 1, 0 },
    { gUnk_093F0958, gUnk_09618718, gUnk_09EF1008, gUnk_093F2D24, gUnk_096189F8, gUnk_09EF10C0, 512, 32, 256, 1, 0, 12, 5, 1, 0 },
    { gUnk_093F0958, gUnk_09618718, gUnk_09EF1008, gUnk_093F2D24, gUnk_096189F8, gUnk_09EF10C0, 512, 32, 256, 1, 0, 12, 6, 1, 0 },
    { gUnk_093F0958, gUnk_09618718, gUnk_09EF1008, gUnk_093F2D24, gUnk_096189F8, gUnk_09EF10C0, 512, 32, 256, 1, 0, 12, 7, 1, 0 },
    { gUnk_093F0958, gUnk_09618718, gUnk_09EF1008, gUnk_093F2D24, gUnk_096189F8, gUnk_09EF10C0, 512, 32, 256, 1, 0, 12, 8, 1, 0 },
    { gUnk_093F0958, gUnk_09618718, gUnk_09EF1008, gUnk_093F2D24, gUnk_096189F8, gUnk_09EF10C0, 512, 32, 256, 1, 0, 12, 9, 1, 0 },
    { gUnk_093F0744, gUnk_096186F8, gUnk_09EF1000, gUnk_093F2C10, gUnk_096189D8, gUnk_09EF10B8, 512, 32, 256, 1, 0, 11, 0, 1, 0 },
    { gUnk_093F0744, gUnk_096186F8, gUnk_09EF1000, gUnk_093F2C10, gUnk_096189D8, gUnk_09EF10B8, 512, 32, 256, 1, 0, 11, 1, 1, 0 },
    { gUnk_093F0744, gUnk_096186F8, gUnk_09EF1000, gUnk_093F2C10, gUnk_096189D8, gUnk_09EF10B8, 512, 32, 256, 1, 0, 11, 2, 1, 0 },
    { gUnk_093F0744, gUnk_096186F8, gUnk_09EF1000, gUnk_093F2C10, gUnk_096189D8, gUnk_09EF10B8, 512, 32, 256, 1, 0, 11, 3, 1, 0 },
    { gUnk_093F0744, gUnk_096186F8, gUnk_09EF1000, gUnk_093F2C10, gUnk_096189D8, gUnk_09EF10B8, 512, 32, 256, 1, 0, 11, 4, 1, 0 },
    { gUnk_093F0744, gUnk_096186F8, gUnk_09EF1000, gUnk_093F2C10, gUnk_096189D8, gUnk_09EF10B8, 512, 32, 256, 1, 0, 11, 5, 1, 0 },
    { gUnk_093F0744, gUnk_096186F8, gUnk_09EF1000, gUnk_093F2C10, gUnk_096189D8, gUnk_09EF10B8, 512, 32, 256, 1, 0, 11, 6, 1, 0 },
    { gUnk_093F0744, gUnk_096186F8, gUnk_09EF1000, gUnk_093F2C10, gUnk_096189D8, gUnk_09EF10B8, 512, 32, 256, 1, 0, 11, 7, 1, 0 },
    { gUnk_093F0744, gUnk_096186F8, gUnk_09EF1000, gUnk_093F2C10, gUnk_096189D8, gUnk_09EF10B8, 512, 32, 256, 1, 0, 11, 8, 1, 0 },
    { gUnk_093F0744, gUnk_096186F8, gUnk_09EF1000, gUnk_093F2C10, gUnk_096189D8, gUnk_09EF10B8, 512, 32, 256, 1, 0, 11, 9, 1, 0 },
    { gUnk_093F0B6C, gUnk_09618738, gUnk_09EF1010, gUnk_093F2E38, gUnk_09618A18, gUnk_09EF10C8, 512, 32, 256, 1, 0, 13, 0, 1, 0 },
    { gUnk_093F0B6C, gUnk_09618738, gUnk_09EF1010, gUnk_093F2E38, gUnk_09618A18, gUnk_09EF10C8, 512, 32, 256, 1, 0, 13, 1, 1, 0 },
    { gUnk_093F0B6C, gUnk_09618738, gUnk_09EF1010, gUnk_093F2E38, gUnk_09618A18, gUnk_09EF10C8, 512, 32, 256, 1, 0, 13, 2, 1, 0 },
    { gUnk_093F0B6C, gUnk_09618738, gUnk_09EF1010, gUnk_093F2E38, gUnk_09618A18, gUnk_09EF10C8, 512, 32, 256, 1, 0, 13, 3, 1, 0 },
    { gUnk_093F0B6C, gUnk_09618738, gUnk_09EF1010, gUnk_093F2E38, gUnk_09618A18, gUnk_09EF10C8, 512, 32, 256, 1, 0, 13, 4, 1, 0 },
    { gUnk_093F0B6C, gUnk_09618738, gUnk_09EF1010, gUnk_093F2E38, gUnk_09618A18, gUnk_09EF10C8, 512, 32, 256, 1, 0, 13, 5, 1, 0 },
    { gUnk_093F0B6C, gUnk_09618738, gUnk_09EF1010, gUnk_093F2E38, gUnk_09618A18, gUnk_09EF10C8, 512, 32, 256, 1, 0, 13, 6, 1, 0 },
    { gUnk_093F0B6C, gUnk_09618738, gUnk_09EF1010, gUnk_093F2E38, gUnk_09618A18, gUnk_09EF10C8, 512, 32, 256, 1, 0, 13, 7, 1, 0 },
    { gUnk_093F0B6C, gUnk_09618738, gUnk_09EF1010, gUnk_093F2E38, gUnk_09618A18, gUnk_09EF10C8, 512, 32, 256, 1, 0, 13, 8, 1, 0 },
    { gUnk_093F0B6C, gUnk_09618738, gUnk_09EF1010, gUnk_093F2E38, gUnk_09618A18, gUnk_09EF10C8, 512, 32, 256, 1, 0, 13, 9, 1, 0 },
    { gUnk_093F0D80, gUnk_09618758, gUnk_09EF1018, gUnk_093F2F4C, gUnk_09618A38, gUnk_09EF10D0, 512, 32, 256, 1, 0, 14, 0, 1, 0 },
    { gUnk_093F0D80, gUnk_09618758, gUnk_09EF1018, gUnk_093F2F4C, gUnk_09618A38, gUnk_09EF10D0, 512, 32, 256, 1, 0, 14, 1, 1, 0 },
    { gUnk_093F0D80, gUnk_09618758, gUnk_09EF1018, gUnk_093F2F4C, gUnk_09618A38, gUnk_09EF10D0, 512, 32, 256, 1, 0, 14, 2, 1, 0 },
    { gUnk_093F0D80, gUnk_09618758, gUnk_09EF1018, gUnk_093F2F4C, gUnk_09618A38, gUnk_09EF10D0, 512, 32, 256, 1, 0, 14, 3, 1, 0 },
    { gUnk_093F0D80, gUnk_09618758, gUnk_09EF1018, gUnk_093F2F4C, gUnk_09618A38, gUnk_09EF10D0, 512, 32, 256, 1, 0, 14, 4, 1, 0 },
    { gUnk_093F0D80, gUnk_09618758, gUnk_09EF1018, gUnk_093F2F4C, gUnk_09618A38, gUnk_09EF10D0, 512, 32, 256, 1, 0, 14, 5, 1, 0 },
    { gUnk_093F0D80, gUnk_09618758, gUnk_09EF1018, gUnk_093F2F4C, gUnk_09618A38, gUnk_09EF10D0, 512, 32, 256, 1, 0, 14, 6, 1, 0 },
    { gUnk_093F0D80, gUnk_09618758, gUnk_09EF1018, gUnk_093F2F4C, gUnk_09618A38, gUnk_09EF10D0, 512, 32, 256, 1, 0, 14, 7, 1, 0 },
    { gUnk_093F0D80, gUnk_09618758, gUnk_09EF1018, gUnk_093F2F4C, gUnk_09618A38, gUnk_09EF10D0, 512, 32, 256, 1, 0, 14, 8, 1, 0 },
    { gUnk_093F0D80, gUnk_09618758, gUnk_09EF1018, gUnk_093F2F4C, gUnk_09618A38, gUnk_09EF10D0, 512, 32, 256, 1, 0, 14, 9, 1, 0 },
    { gUnk_093F15D0, gUnk_096187D8, gUnk_09EF1038, gUnk_093F339C, gUnk_09618AB8, gUnk_09EF10F0, 512, 32, 256, 1, 0, 18, 0, 1, 0 },
    { gUnk_093F15D0, gUnk_096187D8, gUnk_09EF1038, gUnk_093F339C, gUnk_09618AB8, gUnk_09EF10F0, 512, 32, 256, 1, 0, 18, 1, 1, 0 },
    { gUnk_093F15D0, gUnk_096187D8, gUnk_09EF1038, gUnk_093F339C, gUnk_09618AB8, gUnk_09EF10F0, 512, 32, 256, 1, 0, 18, 2, 1, 0 },
    { gUnk_093F15D0, gUnk_096187D8, gUnk_09EF1038, gUnk_093F339C, gUnk_09618AB8, gUnk_09EF10F0, 512, 32, 256, 1, 0, 18, 3, 1, 0 },
    { gUnk_093F15D0, gUnk_096187D8, gUnk_09EF1038, gUnk_093F339C, gUnk_09618AB8, gUnk_09EF10F0, 512, 32, 256, 1, 0, 18, 4, 1, 0 },
    { gUnk_093F15D0, gUnk_096187D8, gUnk_09EF1038, gUnk_093F339C, gUnk_09618AB8, gUnk_09EF10F0, 512, 32, 256, 1, 0, 18, 5, 1, 0 },
    { gUnk_093F15D0, gUnk_096187D8, gUnk_09EF1038, gUnk_093F339C, gUnk_09618AB8, gUnk_09EF10F0, 512, 32, 256, 1, 0, 18, 6, 1, 0 },
    { gUnk_093F15D0, gUnk_096187D8, gUnk_09EF1038, gUnk_093F339C, gUnk_09618AB8, gUnk_09EF10F0, 512, 32, 256, 1, 0, 18, 7, 1, 0 },
    { gUnk_093F15D0, gUnk_096187D8, gUnk_09EF1038, gUnk_093F339C, gUnk_09618AB8, gUnk_09EF10F0, 512, 32, 256, 1, 0, 18, 8, 1, 0 },
    { gUnk_093F15D0, gUnk_096187D8, gUnk_09EF1038, gUnk_093F339C, gUnk_09618AB8, gUnk_09EF10F0, 512, 32, 256, 1, 0, 18, 9, 1, 0 },
    { gUnk_093F11A8, gUnk_09618798, gUnk_09EF1028, gUnk_093F3174, gUnk_09618A78, gUnk_09EF10E0, 512, 32, 256, 1, 0, 16, 0, 1, 0 },
    { gUnk_093F11A8, gUnk_09618798, gUnk_09EF1028, gUnk_093F3174, gUnk_09618A78, gUnk_09EF10E0, 512, 32, 256, 1, 0, 16, 1, 1, 0 },
    { gUnk_093F11A8, gUnk_09618798, gUnk_09EF1028, gUnk_093F3174, gUnk_09618A78, gUnk_09EF10E0, 512, 32, 256, 1, 0, 16, 2, 1, 0 },
    { gUnk_093F11A8, gUnk_09618798, gUnk_09EF1028, gUnk_093F3174, gUnk_09618A78, gUnk_09EF10E0, 512, 32, 256, 1, 0, 16, 3, 1, 0 },
    { gUnk_093F11A8, gUnk_09618798, gUnk_09EF1028, gUnk_093F3174, gUnk_09618A78, gUnk_09EF10E0, 512, 32, 256, 1, 0, 16, 4, 1, 0 },
    { gUnk_093F11A8, gUnk_09618798, gUnk_09EF1028, gUnk_093F3174, gUnk_09618A78, gUnk_09EF10E0, 512, 32, 256, 1, 0, 16, 5, 1, 0 },
    { gUnk_093F11A8, gUnk_09618798, gUnk_09EF1028, gUnk_093F3174, gUnk_09618A78, gUnk_09EF10E0, 512, 32, 256, 1, 0, 16, 6, 1, 0 },
    { gUnk_093F11A8, gUnk_09618798, gUnk_09EF1028, gUnk_093F3174, gUnk_09618A78, gUnk_09EF10E0, 512, 32, 256, 1, 0, 16, 7, 1, 0 },
    { gUnk_093F11A8, gUnk_09618798, gUnk_09EF1028, gUnk_093F3174, gUnk_09618A78, gUnk_09EF10E0, 512, 32, 256, 1, 0, 16, 8, 1, 0 },
    { gUnk_093F11A8, gUnk_09618798, gUnk_09EF1028, gUnk_093F3174, gUnk_09618A78, gUnk_09EF10E0, 512, 32, 256, 1, 0, 16, 9, 1, 0 },
    { gUnk_093F13BC, gUnk_096187B8, gUnk_09EF1030, gUnk_093F3288, gUnk_09618A98, gUnk_09EF10E8, 512, 32, 256, 1, 0, 17, 0, 1, 0 },
    { gUnk_093F13BC, gUnk_096187B8, gUnk_09EF1030, gUnk_093F3288, gUnk_09618A98, gUnk_09EF10E8, 512, 32, 256, 1, 0, 17, 1, 1, 0 },
    { gUnk_093F13BC, gUnk_096187B8, gUnk_09EF1030, gUnk_093F3288, gUnk_09618A98, gUnk_09EF10E8, 512, 32, 256, 1, 0, 17, 2, 1, 0 },
    { gUnk_093F13BC, gUnk_096187B8, gUnk_09EF1030, gUnk_093F3288, gUnk_09618A98, gUnk_09EF10E8, 512, 32, 256, 1, 0, 17, 3, 1, 0 },
    { gUnk_093F13BC, gUnk_096187B8, gUnk_09EF1030, gUnk_093F3288, gUnk_09618A98, gUnk_09EF10E8, 512, 32, 256, 1, 0, 17, 4, 1, 0 },
    { gUnk_093F13BC, gUnk_096187B8, gUnk_09EF1030, gUnk_093F3288, gUnk_09618A98, gUnk_09EF10E8, 512, 32, 256, 1, 0, 17, 5, 1, 0 },
    { gUnk_093F13BC, gUnk_096187B8, gUnk_09EF1030, gUnk_093F3288, gUnk_09618A98, gUnk_09EF10E8, 512, 32, 256, 1, 0, 17, 6, 1, 0 },
    { gUnk_093F13BC, gUnk_096187B8, gUnk_09EF1030, gUnk_093F3288, gUnk_09618A98, gUnk_09EF10E8, 512, 32, 256, 1, 0, 17, 7, 1, 0 },
    { gUnk_093F13BC, gUnk_096187B8, gUnk_09EF1030, gUnk_093F3288, gUnk_09618A98, gUnk_09EF10E8, 512, 32, 256, 1, 0, 17, 8, 1, 0 },
    { gUnk_093F13BC, gUnk_096187B8, gUnk_09EF1030, gUnk_093F3288, gUnk_09618A98, gUnk_09EF10E8, 512, 32, 256, 1, 0, 17, 9, 1, 0 },
    { gUnk_093F0108, gUnk_09618698, gUnk_09EF0FE8, gUnk_093F28D4, gUnk_09618978, gUnk_09EF10A0, 512, 32, 256, 3, 0, 8, 0, 3, 0 },
    { gUnk_093F0108, gUnk_09618698, gUnk_09EF0FE8, gUnk_093F28D4, gUnk_09618978, gUnk_09EF10A0, 512, 32, 256, 3, 0, 8, 1, 3, 0 },
    { gUnk_093F0108, gUnk_09618698, gUnk_09EF0FE8, gUnk_093F28D4, gUnk_09618978, gUnk_09EF10A0, 512, 32, 256, 3, 0, 8, 2, 3, 0 },
    { gUnk_093F0108, gUnk_09618698, gUnk_09EF0FE8, gUnk_093F28D4, gUnk_09618978, gUnk_09EF10A0, 512, 32, 256, 3, 0, 8, 3, 3, 0 },
    { gUnk_093F0108, gUnk_09618698, gUnk_09EF0FE8, gUnk_093F28D4, gUnk_09618978, gUnk_09EF10A0, 512, 32, 256, 3, 0, 8, 4, 3, 0 },
    { gUnk_093F0108, gUnk_09618698, gUnk_09EF0FE8, gUnk_093F28D4, gUnk_09618978, gUnk_09EF10A0, 512, 32, 256, 3, 0, 8, 5, 3, 0 },
    { gUnk_093F0108, gUnk_09618698, gUnk_09EF0FE8, gUnk_093F28D4, gUnk_09618978, gUnk_09EF10A0, 512, 32, 256, 3, 0, 8, 6, 3, 0 },
    { gUnk_093F0108, gUnk_09618698, gUnk_09EF0FE8, gUnk_093F28D4, gUnk_09618978, gUnk_09EF10A0, 512, 32, 256, 3, 0, 8, 7, 3, 0 },
    { gUnk_093F0108, gUnk_09618698, gUnk_09EF0FE8, gUnk_093F28D4, gUnk_09618978, gUnk_09EF10A0, 512, 32, 256, 3, 0, 8, 8, 3, 0 },
    { gUnk_093F0108, gUnk_09618698, gUnk_09EF0FE8, gUnk_093F28D4, gUnk_09618978, gUnk_09EF10A0, 512, 32, 256, 3, 0, 8, 9, 3, 0 },
    { gUnk_093EF490, gUnk_096185D8, gUnk_09EF0FB8, gUnk_093F225C, gUnk_096188B8, gUnk_09EF1070, 512, 32, 256, 3, 0, 2, 0, 3, 0 },
    { gUnk_093EF490, gUnk_096185D8, gUnk_09EF0FB8, gUnk_093F225C, gUnk_096188B8, gUnk_09EF1070, 512, 32, 256, 3, 0, 2, 1, 3, 0 },
    { gUnk_093EF490, gUnk_096185D8, gUnk_09EF0FB8, gUnk_093F225C, gUnk_096188B8, gUnk_09EF1070, 512, 32, 256, 3, 0, 2, 2, 3, 0 },
    { gUnk_093EF490, gUnk_096185D8, gUnk_09EF0FB8, gUnk_093F225C, gUnk_096188B8, gUnk_09EF1070, 512, 32, 256, 3, 0, 2, 3, 3, 0 },
    { gUnk_093EF490, gUnk_096185D8, gUnk_09EF0FB8, gUnk_093F225C, gUnk_096188B8, gUnk_09EF1070, 512, 32, 256, 3, 0, 2, 4, 3, 0 },
    { gUnk_093EF490, gUnk_096185D8, gUnk_09EF0FB8, gUnk_093F225C, gUnk_096188B8, gUnk_09EF1070, 512, 32, 256, 3, 0, 2, 5, 3, 0 },
    { gUnk_093EF490, gUnk_096185D8, gUnk_09EF0FB8, gUnk_093F225C, gUnk_096188B8, gUnk_09EF1070, 512, 32, 256, 3, 0, 2, 6, 3, 0 },
    { gUnk_093EF490, gUnk_096185D8, gUnk_09EF0FB8, gUnk_093F225C, gUnk_096188B8, gUnk_09EF1070, 512, 32, 256, 3, 0, 2, 7, 3, 0 },
    { gUnk_093EF490, gUnk_096185D8, gUnk_09EF0FB8, gUnk_093F225C, gUnk_096188B8, gUnk_09EF1070, 512, 32, 256, 3, 0, 2, 8, 3, 0 },
    { gUnk_093EF490, gUnk_096185D8, gUnk_09EF0FB8, gUnk_093F225C, gUnk_096188B8, gUnk_09EF1070, 512, 32, 256, 3, 0, 2, 9, 3, 0 },
    { gUnk_093F031C, gUnk_096186B8, gUnk_09EF0FF0, gUnk_093F29E8, gUnk_09618998, gUnk_09EF10A8, 512, 32, 256, 3, 0, 9, 0, 3, 0 },
    { gUnk_093F031C, gUnk_096186B8, gUnk_09EF0FF0, gUnk_093F29E8, gUnk_09618998, gUnk_09EF10A8, 512, 32, 256, 3, 0, 9, 1, 3, 0 },
    { gUnk_093F031C, gUnk_096186B8, gUnk_09EF0FF0, gUnk_093F29E8, gUnk_09618998, gUnk_09EF10A8, 512, 32, 256, 3, 0, 9, 2, 3, 0 },
    { gUnk_093F031C, gUnk_096186B8, gUnk_09EF0FF0, gUnk_093F29E8, gUnk_09618998, gUnk_09EF10A8, 512, 32, 256, 3, 0, 9, 3, 3, 0 },
    { gUnk_093F031C, gUnk_096186B8, gUnk_09EF0FF0, gUnk_093F29E8, gUnk_09618998, gUnk_09EF10A8, 512, 32, 256, 3, 0, 9, 4, 3, 0 },
    { gUnk_093F031C, gUnk_096186B8, gUnk_09EF0FF0, gUnk_093F29E8, gUnk_09618998, gUnk_09EF10A8, 512, 32, 256, 3, 0, 9, 5, 3, 0 },
    { gUnk_093F031C, gUnk_096186B8, gUnk_09EF0FF0, gUnk_093F29E8, gUnk_09618998, gUnk_09EF10A8, 512, 32, 256, 3, 0, 9, 6, 3, 0 },
    { gUnk_093F031C, gUnk_096186B8, gUnk_09EF0FF0, gUnk_093F29E8, gUnk_09618998, gUnk_09EF10A8, 512, 32, 256, 3, 0, 9, 7, 3, 0 },
    { gUnk_093F031C, gUnk_096186B8, gUnk_09EF0FF0, gUnk_093F29E8, gUnk_09618998, gUnk_09EF10A8, 512, 32, 256, 3, 0, 9, 8, 3, 0 },
    { gUnk_093F031C, gUnk_096186B8, gUnk_09EF0FF0, gUnk_093F29E8, gUnk_09618998, gUnk_09EF10A8, 512, 32, 256, 3, 0, 9, 9, 3, 0 },
    { gUnk_093EFACC, gUnk_09618638, gUnk_09EF0FD0, gUnk_093F2598, gUnk_09618918, gUnk_09EF1088, 512, 32, 256, 3, 0, 5, 0, 3, 0 },
    { gUnk_093EFACC, gUnk_09618638, gUnk_09EF0FD0, gUnk_093F2598, gUnk_09618918, gUnk_09EF1088, 512, 32, 256, 3, 0, 5, 1, 3, 0 },
    { gUnk_093EFACC, gUnk_09618638, gUnk_09EF0FD0, gUnk_093F2598, gUnk_09618918, gUnk_09EF1088, 512, 32, 256, 3, 0, 5, 2, 3, 0 },
    { gUnk_093EFACC, gUnk_09618638, gUnk_09EF0FD0, gUnk_093F2598, gUnk_09618918, gUnk_09EF1088, 512, 32, 256, 3, 0, 5, 3, 3, 0 },
    { gUnk_093EFACC, gUnk_09618638, gUnk_09EF0FD0, gUnk_093F2598, gUnk_09618918, gUnk_09EF1088, 512, 32, 256, 3, 0, 5, 4, 3, 0 },
    { gUnk_093EFACC, gUnk_09618638, gUnk_09EF0FD0, gUnk_093F2598, gUnk_09618918, gUnk_09EF1088, 512, 32, 256, 3, 0, 5, 5, 3, 0 },
    { gUnk_093EFACC, gUnk_09618638, gUnk_09EF0FD0, gUnk_093F2598, gUnk_09618918, gUnk_09EF1088, 512, 32, 256, 3, 0, 5, 6, 3, 0 },
    { gUnk_093EFACC, gUnk_09618638, gUnk_09EF0FD0, gUnk_093F2598, gUnk_09618918, gUnk_09EF1088, 512, 32, 256, 3, 0, 5, 7, 3, 0 },
    { gUnk_093EFACC, gUnk_09618638, gUnk_09EF0FD0, gUnk_093F2598, gUnk_09618918, gUnk_09EF1088, 512, 32, 256, 3, 0, 5, 8, 3, 0 },
    { gUnk_093EFACC, gUnk_09618638, gUnk_09EF0FD0, gUnk_093F2598, gUnk_09618918, gUnk_09EF1088, 512, 32, 256, 3, 0, 5, 9, 3, 0 },
    { gUnk_093F0F94, gUnk_09618778, gUnk_09EF1020, gUnk_093F3060, gUnk_09618A58, gUnk_09EF10D8, 512, 32, 256, 3, 0, 15, 0, 3, 0 },
    { gUnk_093F0F94, gUnk_09618778, gUnk_09EF1020, gUnk_093F3060, gUnk_09618A58, gUnk_09EF10D8, 512, 32, 256, 3, 0, 15, 1, 3, 0 },
    { gUnk_093F0F94, gUnk_09618778, gUnk_09EF1020, gUnk_093F3060, gUnk_09618A58, gUnk_09EF10D8, 512, 32, 256, 3, 0, 15, 2, 3, 0 },
    { gUnk_093F0F94, gUnk_09618778, gUnk_09EF1020, gUnk_093F3060, gUnk_09618A58, gUnk_09EF10D8, 512, 32, 256, 3, 0, 15, 3, 3, 0 },
    { gUnk_093F0F94, gUnk_09618778, gUnk_09EF1020, gUnk_093F3060, gUnk_09618A58, gUnk_09EF10D8, 512, 32, 256, 3, 0, 15, 4, 3, 0 },
    { gUnk_093F0F94, gUnk_09618778, gUnk_09EF1020, gUnk_093F3060, gUnk_09618A58, gUnk_09EF10D8, 512, 32, 256, 3, 0, 15, 5, 3, 0 },
    { gUnk_093F0F94, gUnk_09618778, gUnk_09EF1020, gUnk_093F3060, gUnk_09618A58, gUnk_09EF10D8, 512, 32, 256, 3, 0, 15, 6, 3, 0 },
    { gUnk_093F0F94, gUnk_09618778, gUnk_09EF1020, gUnk_093F3060, gUnk_09618A58, gUnk_09EF10D8, 512, 32, 256, 3, 0, 15, 7, 3, 0 },
    { gUnk_093F0F94, gUnk_09618778, gUnk_09EF1020, gUnk_093F3060, gUnk_09618A58, gUnk_09EF10D8, 512, 32, 256, 3, 0, 15, 8, 3, 0 },
    { gUnk_093F0F94, gUnk_09618778, gUnk_09EF1020, gUnk_093F3060, gUnk_09618A58, gUnk_09EF10D8, 512, 32, 256, 3, 0, 15, 9, 3, 0 },
    { gUnk_093F0530, gUnk_096186D8, gUnk_09EF0FF8, gUnk_093F2AFC, gUnk_096189B8, gUnk_09EF10B0, 512, 32, 256, 3, 0, 10, 0, 3, 0 },
    { gUnk_093F0530, gUnk_096186D8, gUnk_09EF0FF8, gUnk_093F2AFC, gUnk_096189B8, gUnk_09EF10B0, 512, 32, 256, 3, 0, 10, 1, 3, 0 },
    { gUnk_093F0530, gUnk_096186D8, gUnk_09EF0FF8, gUnk_093F2AFC, gUnk_096189B8, gUnk_09EF10B0, 512, 32, 256, 3, 0, 10, 2, 3, 0 },
    { gUnk_093F0530, gUnk_096186D8, gUnk_09EF0FF8, gUnk_093F2AFC, gUnk_096189B8, gUnk_09EF10B0, 512, 32, 256, 3, 0, 10, 3, 3, 0 },
    { gUnk_093F0530, gUnk_096186D8, gUnk_09EF0FF8, gUnk_093F2AFC, gUnk_096189B8, gUnk_09EF10B0, 512, 32, 256, 3, 0, 10, 4, 3, 0 },
    { gUnk_093F0530, gUnk_096186D8, gUnk_09EF0FF8, gUnk_093F2AFC, gUnk_096189B8, gUnk_09EF10B0, 512, 32, 256, 3, 0, 10, 5, 3, 0 },
    { gUnk_093F0530, gUnk_096186D8, gUnk_09EF0FF8, gUnk_093F2AFC, gUnk_096189B8, gUnk_09EF10B0, 512, 32, 256, 3, 0, 10, 6, 3, 0 },
    { gUnk_093F0530, gUnk_096186D8, gUnk_09EF0FF8, gUnk_093F2AFC, gUnk_096189B8, gUnk_09EF10B0, 512, 32, 256, 3, 0, 10, 7, 3, 0 },
    { gUnk_093F0530, gUnk_096186D8, gUnk_09EF0FF8, gUnk_093F2AFC, gUnk_096189B8, gUnk_09EF10B0, 512, 32, 256, 3, 0, 10, 8, 3, 0 },
    { gUnk_093F0530, gUnk_096186D8, gUnk_09EF0FF8, gUnk_093F2AFC, gUnk_096189B8, gUnk_09EF10B0, 512, 32, 256, 3, 0, 10, 9, 3, 0 },
    { gUnk_093F3E50, gUnk_09618BD8, gUnk_09EF1138, gUnk_093F3900, gUnk_09618B58, gUnk_09EF1118, 512, 32, 256, 4, 0, 22, 0, 4, 0 },
    { gUnk_093F3E50, gUnk_09618BD8, gUnk_09EF1138, gUnk_093F3900, gUnk_09618B58, gUnk_09EF1118, 512, 32, 256, 4, 0, 22, 1, 4, 0 },
    { gUnk_093F3E50, gUnk_09618BD8, gUnk_09EF1138, gUnk_093F3900, gUnk_09618B58, gUnk_09EF1118, 512, 32, 256, 4, 0, 22, 2, 4, 0 },
    { gUnk_093F3E50, gUnk_09618BD8, gUnk_09EF1138, gUnk_093F3900, gUnk_09618B58, gUnk_09EF1118, 512, 32, 256, 4, 0, 22, 3, 4, 0 },
    { gUnk_093F3E50, gUnk_09618BD8, gUnk_09EF1138, gUnk_093F3900, gUnk_09618B58, gUnk_09EF1118, 512, 32, 256, 4, 0, 22, 4, 4, 0 },
    { gUnk_093F3E50, gUnk_09618BD8, gUnk_09EF1138, gUnk_093F3900, gUnk_09618B58, gUnk_09EF1118, 512, 32, 256, 4, 0, 22, 5, 4, 0 },
    { gUnk_093F3E50, gUnk_09618BD8, gUnk_09EF1138, gUnk_093F3900, gUnk_09618B58, gUnk_09EF1118, 512, 32, 256, 4, 0, 22, 6, 4, 0 },
    { gUnk_093F3E50, gUnk_09618BD8, gUnk_09EF1138, gUnk_093F3900, gUnk_09618B58, gUnk_09EF1118, 512, 32, 256, 4, 0, 22, 7, 4, 0 },
    { gUnk_093F3E50, gUnk_09618BD8, gUnk_09EF1138, gUnk_093F3900, gUnk_09618B58, gUnk_09EF1118, 512, 32, 256, 4, 0, 22, 8, 4, 0 },
    { gUnk_093F3E50, gUnk_09618BD8, gUnk_09EF1138, gUnk_093F3900, gUnk_09618B58, gUnk_09EF1118, 512, 32, 256, 4, 0, 22, 9, 4, 0 },
    { gUnk_093F4064, gUnk_09618BF8, gUnk_09EF1140, gUnk_093F3A14, gUnk_09618B78, gUnk_09EF1120, 512, 32, 256, 4, 0, 23, 0, 4, 0 },
    { gUnk_093F4064, gUnk_09618BF8, gUnk_09EF1140, gUnk_093F3A14, gUnk_09618B78, gUnk_09EF1120, 512, 32, 256, 4, 0, 23, 1, 4, 0 },
    { gUnk_093F4064, gUnk_09618BF8, gUnk_09EF1140, gUnk_093F3A14, gUnk_09618B78, gUnk_09EF1120, 512, 32, 256, 4, 0, 23, 2, 4, 0 },
    { gUnk_093F4064, gUnk_09618BF8, gUnk_09EF1140, gUnk_093F3A14, gUnk_09618B78, gUnk_09EF1120, 512, 32, 256, 4, 0, 23, 3, 4, 0 },
    { gUnk_093F4064, gUnk_09618BF8, gUnk_09EF1140, gUnk_093F3A14, gUnk_09618B78, gUnk_09EF1120, 512, 32, 256, 4, 0, 23, 4, 4, 0 },
    { gUnk_093F4064, gUnk_09618BF8, gUnk_09EF1140, gUnk_093F3A14, gUnk_09618B78, gUnk_09EF1120, 512, 32, 256, 4, 0, 23, 5, 4, 0 },
    { gUnk_093F4064, gUnk_09618BF8, gUnk_09EF1140, gUnk_093F3A14, gUnk_09618B78, gUnk_09EF1120, 512, 32, 256, 4, 0, 23, 6, 4, 0 },
    { gUnk_093F4064, gUnk_09618BF8, gUnk_09EF1140, gUnk_093F3A14, gUnk_09618B78, gUnk_09EF1120, 512, 32, 256, 4, 0, 23, 7, 4, 0 },
    { gUnk_093F4064, gUnk_09618BF8, gUnk_09EF1140, gUnk_093F3A14, gUnk_09618B78, gUnk_09EF1120, 512, 32, 256, 4, 0, 23, 8, 4, 0 },
    { gUnk_093F4064, gUnk_09618BF8, gUnk_09EF1140, gUnk_093F3A14, gUnk_09618B78, gUnk_09EF1120, 512, 32, 256, 4, 0, 23, 9, 4, 0 },
    { gUnk_093F4278, gUnk_09618C18, gUnk_09EF1148, gUnk_093F3B28, gUnk_09618B98, gUnk_09EF1128, 512, 32, 256, 4, 0, 24, 0, 4, 0 },
    { gUnk_093F4278, gUnk_09618C18, gUnk_09EF1148, gUnk_093F3B28, gUnk_09618B98, gUnk_09EF1128, 512, 32, 256, 4, 0, 24, 1, 4, 0 },
    { gUnk_093F4278, gUnk_09618C18, gUnk_09EF1148, gUnk_093F3B28, gUnk_09618B98, gUnk_09EF1128, 512, 32, 256, 4, 0, 24, 2, 4, 0 },
    { gUnk_093F4278, gUnk_09618C18, gUnk_09EF1148, gUnk_093F3B28, gUnk_09618B98, gUnk_09EF1128, 512, 32, 256, 4, 0, 24, 3, 4, 0 },
    { gUnk_093F4278, gUnk_09618C18, gUnk_09EF1148, gUnk_093F3B28, gUnk_09618B98, gUnk_09EF1128, 512, 32, 256, 4, 0, 24, 4, 4, 0 },
    { gUnk_093F4278, gUnk_09618C18, gUnk_09EF1148, gUnk_093F3B28, gUnk_09618B98, gUnk_09EF1128, 512, 32, 256, 4, 0, 24, 5, 4, 0 },
    { gUnk_093F4278, gUnk_09618C18, gUnk_09EF1148, gUnk_093F3B28, gUnk_09618B98, gUnk_09EF1128, 512, 32, 256, 4, 0, 24, 6, 4, 0 },
    { gUnk_093F4278, gUnk_09618C18, gUnk_09EF1148, gUnk_093F3B28, gUnk_09618B98, gUnk_09EF1128, 512, 32, 256, 4, 0, 24, 7, 4, 0 },
    { gUnk_093F4278, gUnk_09618C18, gUnk_09EF1148, gUnk_093F3B28, gUnk_09618B98, gUnk_09EF1128, 512, 32, 256, 4, 0, 24, 8, 4, 0 },
    { gUnk_093F4278, gUnk_09618C18, gUnk_09EF1148, gUnk_093F3B28, gUnk_09618B98, gUnk_09EF1128, 512, 32, 256, 4, 0, 24, 9, 4, 0 },
    { gUnk_093F1E20, gUnk_09618858, gUnk_09EF1058, gUnk_093F37EC, gUnk_09618B38, gUnk_09EF1110, 512, 32, 256, 4, 0, 25, 0, 4, 0 },
    { gUnk_093F1E20, gUnk_09618858, gUnk_09EF1058, gUnk_093F37EC, gUnk_09618B38, gUnk_09EF1110, 512, 32, 256, 4, 0, 25, 1, 4, 0 },
    { gUnk_093F1E20, gUnk_09618858, gUnk_09EF1058, gUnk_093F37EC, gUnk_09618B38, gUnk_09EF1110, 512, 32, 256, 4, 0, 25, 2, 4, 0 },
    { gUnk_093F1E20, gUnk_09618858, gUnk_09EF1058, gUnk_093F37EC, gUnk_09618B38, gUnk_09EF1110, 512, 32, 256, 4, 0, 25, 3, 4, 0 },
    { gUnk_093F1E20, gUnk_09618858, gUnk_09EF1058, gUnk_093F37EC, gUnk_09618B38, gUnk_09EF1110, 512, 32, 256, 4, 0, 25, 4, 4, 0 },
    { gUnk_093F1E20, gUnk_09618858, gUnk_09EF1058, gUnk_093F37EC, gUnk_09618B38, gUnk_09EF1110, 512, 32, 256, 4, 0, 25, 5, 4, 0 },
    { gUnk_093F1E20, gUnk_09618858, gUnk_09EF1058, gUnk_093F37EC, gUnk_09618B38, gUnk_09EF1110, 512, 32, 256, 4, 0, 25, 6, 4, 0 },
    { gUnk_093F1E20, gUnk_09618858, gUnk_09EF1058, gUnk_093F37EC, gUnk_09618B38, gUnk_09EF1110, 512, 32, 256, 4, 0, 25, 7, 4, 0 },
    { gUnk_093F1E20, gUnk_09618858, gUnk_09EF1058, gUnk_093F37EC, gUnk_09618B38, gUnk_09EF1110, 512, 32, 256, 4, 0, 25, 8, 4, 0 },
    { gUnk_093F1E20, gUnk_09618858, gUnk_09EF1058, gUnk_093F37EC, gUnk_09618B38, gUnk_09EF1110, 512, 32, 256, 4, 0, 25, 9, 4, 0 },
};

s16 gUnk_09EE7520[6] = {
    20,
    57,
    94,
    131,
    168,
    205,
};

UnkStruct_09EE752C gUnk_09EE752C[7] = {
    { 0, 5, 0, 0 },
    { 1, 5, 0, 0 },
    { 2, 5, 0, 0 },
    { 3, 5, 0, 0 },
    { 4, 5, 0, 0 },
    { 5, 5, 0, 0 },
    { 0, 100, 0, 0 },
};

const char gTaskNameMapcard[] = "Mapcard";

TaskDesc gTaskDescMapcard = {
    gTaskNameMapcard,
    (void (*)(void*, void*))Mapcard_0,
    Mapcard_1,
    (void (*)(void*))Mapcard_2,
    (void (*)(void*))Mapcard_3,
    0x78,
};

const char gTaskNameReloadGage[] = "Reload Gage";

TaskDesc gTaskDescReloadGage = {
    gTaskNameReloadGage,
    (void (*)(void*, void*))Reload_Gage_0,
    Reload_Gage_1,
    (void (*)(void*))Reload_Gage_2,
    (void (*)(void*))Reload_Gage_3,
    0xA8,
};

void* gUnk_09EE7578[4] = {
    gUnk_0909A4E0,
    gUnk_0909AB98,
    gUnk_09099E28,
    gUnk_0909AB98,
};

AnimHeader** gUnk_09EE7588[4] = {
    gUnk_09EEA4E0,
    gUnk_09EEA578,
    gUnk_09EEA448,
    gUnk_09EEA578,
};

void** gUnk_09EE7598[4] = {
    gUnk_09EEA494,
    gUnk_09EEA52C,
    gUnk_09EEA3FC,
    gUnk_09EEA52C,
};

void* gUnk_09EE75A8[4] = {
    gUnk_0909FDCA,
    gUnk_090A0C86,
    gUnk_0909EFDE,
    gUnk_0909EFDE,
};

void** gUnk_09EE75B8[4] = {
    gUnk_09EEAF04,
    gUnk_09EEAEBC,
    gUnk_09EEAE74,
    gUnk_09EEAEBC,
};

AnimHeader** gUnk_09EE75C8[4] = {
    gUnk_09EEAF38,
    gUnk_09EEAEF0,
    gUnk_09EEAEA8,
    gUnk_09EEAEF0,
};
