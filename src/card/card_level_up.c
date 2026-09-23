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
#include "sprites_evt.h"
#include "sprites_fld.h"
#include "sprites_level_up.h"
#include "sprites_sora.h"
#include "sprites_msg.h"
#include "sprites_card.h"

u8 gUnk_02034AF8;

extern u8 gUnk_09618CD8[];
extern u8 gUnk_09613E98[];
#ifdef VERSION_EU
extern void** gUnkEu_09F72E10[];
extern u8 gUnkEu_0916F992[];
extern u8 gUnkEu_0917063A[];
extern u8 gUnkEu_09170202[];
extern u8 gUnkEu_0916FDCA[];
extern void* gUnkEu_09F72D08[];
#endif
u8 func_0809FE14(void);
struct LevelUpWork;
u8 func_0809F730(struct LevelUpWork* w, void* a);
u8 func_080A0A44(struct LevelUpWork* w, void* a);
u8 func_080A11CC(LevelUpWork* w, void* a);
extern u8 gUnk_0908CAEC[];
extern u8 gUnk_0908D05E[];
extern s16 gUnk_09037FB4[];
extern u8 gUnk_08F683A4[];
extern u8 gUnk_09618118[];
#ifdef VERSION_EU
extern void* gUnkEu_09F72D1C[];
extern u16 gUnkEu_090D1328[];
#endif
void Level_Up_0(LevelUpWork* w) {
    s16 x;
    s16 y;

    w->tiles4 = 0;
    w->palette5 = 0;
    w->unk_000[0] = 0;
    w->unk_000[1] = 0;
    w->unk_000[2] = 0;
    w->unk_000[3] = 0;
    w->unk_000[4] = 0;
    w->unk_000[5] = 0;
    w->unk_000[6] = 0;
    w->unk_000[7] = 0;
    w->palette = 0;
    w->palette2 = 0;
    w->tiles = 0;
    w->palette3 = 0;
    w->tiles2 = 0;
    w->tiles3 = 0;
    w->palette4 = 0;
    w->unk_7C8[0] = 1;
    w->unk_7C8[1] = 1;
    w->unk_7C8[2] = 1;
    if (gUnk_02039DD4 != 0) {
        gUnk_02039DD4->unk_0E9 = 1;
    }
#ifndef VERSION_EU
    InitTextSlots(w->text[0], 36);
    InitTextSlots(w->text[1], 36);
    InitTextSlots(w->text[2], 36);
    InitTextSlots(w->text[3], 36);
    InitTextSlots(w->text[4], 36);
    InitTextSlots(w->text[5], 36);
    w->unk_000[6] = LoadObjTiles(gUnk_0908CAEC, 0x500);
#else
    w->unk_000[6] = LoadObjTiles(gUnkEu_09F72D1C[gLanguage], gUnkEu_090D1328[gLanguage]);
    w->tiles5[0] = AllocSpriteFrameTiles(0x500);
    w->tiles5[1] = AllocSpriteFrameTiles(0x500);
    w->tiles5[2] = AllocSpriteFrameTiles(0x500);
#endif
    w->unk_000[7] = LoadObjPalette(gUnk_09613E98 + 0x60, 32);
    FadeSetPaletteExcluded(((ObjPalette*)w->unk_000[7])->index + 16, 1);
    w->tiles2 = LoadObjTiles(gUnk_0908D05E, 0x3C0);
    TaskPoolInit(&w->pool, 10);
    if (!(gGameState.flags & 8)) {
        w->tiles4 = AllocObjTiles(0x500, 0);
        w->palette5 = AllocObjPalette(32);
        UpdateAllocatedObjPalette(w->palette5, gUnk_08F683A4);
        FadeSetPaletteExcluded(((ObjPalette*)w->palette5)->index + 16, 1);
        WorldToScreen(&x, &y, gBtlWork->actor->x,
                      gBtlWork->actor->y,
                      gBtlWork->actor->z);
        SetObjTileSource(w->tiles4, gUnk_088E33C2);
        AnimInit(&w->anim2, gUnk_09EDEE14, gUnk_09EDEE08);
        AnimStart(&w->anim2, 0, 1);
    } else {
        w->tiles4 = AllocObjTiles(0x800, 0);
        w->palette5 = AllocObjPalette(32);
        UpdateAllocatedObjPalette(w->palette5, gUnk_09618118);
        FadeSetPaletteExcluded(((ObjPalette*)w->palette5)->index + 16, 1);
        WorldToScreen(&x, &y, gBtlWork->actor->x,
                      gBtlWork->actor->y,
                      gBtlWork->actor->z);
        SetObjTileSource(w->tiles4, gUnk_0891ED26);
        AnimInit(&w->anim2, gUnk_09EDF38C, gUnk_09EDF374);
        AnimStart(&w->anim2, 0, 1);
    }
    if (gBtlWork->flags & 0x2000) {
        w->x7 = 0x1C400;
        w->y6 = 0x5000;
    } else {
        w->x7 = x << 8;
        w->y6 = y << 8;
    }
    w->gfx = AnimGetGfx(&w->anim2);
    if (!(gBtlWork->flags & 4)) {
        w->unk_7C6 = 0;
        gDispCnt = (gDispCnt & 0xFFF8) | 1;
        gBg1Cnt &= 0xFF7F;
        SetBgSize(1, 0);
        SetupBg(2, 0, 12, 0);
        SetupBg(1, 2, 24, 0);
        SetupBg(0, 2, 25, 0);
        LoadBgMap(1, gUnk_08125E24, 0x800);
        LoadBgMap(0, gUnk_08125E24, 0x800);
        EnableBg(2);
        DisableBg(1);
        DisableBg(0);
        gBg2Cnt = gBg3Cnt;
        gBg2PA = gBg3PA;
        gBg2PB = gBg3PB;
        gBg2PC = gBg3PC;
        gBg2PD = gBg3PD;
        gBg2X = gBg3X;
        gBg2Y = gBg3Y;
    } else {
        w->unk_7C6 = 1;
        switch ((u32)gBtlWork->unk_10C) {
        case 151:
            SetBgSize(0, 0);
            SetupBg(0, 0, 26, 0);
            LoadBgMap(0, gUnk_08125E24, 0x800);
            DisableBg(0);
            break;
        case 152:
            SetBgSize(1, 0);
            SetupBg(1, 1, 24, 0);
            LoadBgMap(1, gUnk_08125E24, 0x800);
            DisableBg(1);
            break;
        case 148:
            SetBgSize(1, 0);
            SetupBg(1, 2, 26, 0);
            LoadBgMap(1, gUnk_08125E24, 0x800);
            DisableBg(1);
            break;
        default:
            SetBgSize(1, 0);
            LoadBgMap(1, gUnk_08125E24, 0x800);
            DisableBg(1);
            break;
        }
    }
    gBldCnt &= 0xFFBF;
    w->x6 = -128;
    w->x4[0] = -128;
    w->x4[1] = -128;
    w->x4[2] = -128;
    w->y4[0] = 16;
    w->y4[1] = 64;
    w->y4[2] = 112;
    w->unk_7B5 = 24;
    w->unk_7B1 = 16;
    w->unk_7B2[0] = 16;
    w->unk_7B2[1] = 16;
    w->unk_7B2[2] = 16;
    w->x5[0] = 8;
    w->x5[1] = 8;
    w->x5[2] = 8;
    w->y5[0] = 31;
    w->y5[1] = 79;
    w->y5[2] = 127;
    w->x = 128;
    w->x2 = 128;
    w->y = -0x800;
    w->y2 = 0xA000;
    w->unk_7BF = 16;
    w->unk_77A = 0;
    w->unk_77C = 256;
    w->x3 = 132;
    w->y3 = gUnk_09037FB4[0];
    w->unk_7BD = 0;
    w->unk_7B0 = 0;
    w->unk_7C7 = 0;
    func_080A096C(gGameState.progression.level, w->unk_77E);
    func_080A096C(gGameState.progression.maxHp, w->unk_784);
    func_080A09C0((u16)gGameState.progression.cp, w->unk_78C);
    func_080A096C(gGameState.progression.dp, w->unk_794);
    func_080A0944(gGameState.progression.ap, w->unk_79C);
    w->unk_7A4 = 0;
    w->unk_7C2[1] = 0;
    w->unk_7C2[0] = 0;
    w->unk_7BE = 0;
    w->unk_7C1 = 0;
    w->unk_7C0 = 16;
    w->unk_7C5 = 0;
}
#ifdef VERSION_EU
#define CARD_E7A4_DST 0x20
#else
#define CARD_E7A4_DST 0x2480
#endif
void func_0809E7A4(void) {
    u32 base;

    if (gBtlWork->unk_10C == 151) {
        base = GetBgCharBase(0);
        RequestDma3Copy(gUnk_093FEEB8, (void*)(base + CARD_E7A4_DST), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x400], (void*)(base + CARD_E7A4_DST + 0x120), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x800], (void*)(base + CARD_E7A4_DST + 0x240), 288);
        RequestDma3Copy(&gUnk_093FEEB8[288], (void*)(base + CARD_E7A4_DST + 0x360), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x520], (void*)(base + CARD_E7A4_DST + 0x480), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x920], (void*)(base + CARD_E7A4_DST + 0x5A0), 288);
#ifdef VERSION_EU
        RequestDma3Copy((u8*)gUnkEu_09F72D08[gLanguage] + 0xC00, (void*)(base + 0x800), 0xA80);
#else
        RequestDma3Copy(gUnk_093FD438, (void*)(base + 0x2C00), 0xA80);
#endif
    } else {
        base = GetBgCharBase(1);
        RequestDma3Copy(gUnk_093FEEB8, (void*)(base + CARD_E7A4_DST), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x400], (void*)(base + CARD_E7A4_DST + 0x120), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x800], (void*)(base + CARD_E7A4_DST + 0x240), 288);
        RequestDma3Copy(&gUnk_093FEEB8[288], (void*)(base + CARD_E7A4_DST + 0x360), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x520], (void*)(base + CARD_E7A4_DST + 0x480), 288);
        RequestDma3Copy(&gUnk_093FEEB8[0x920], (void*)(base + CARD_E7A4_DST + 0x5A0), 288);
#ifdef VERSION_EU
        RequestDma3Copy((u8*)gUnkEu_09F72D08[gLanguage] + 0xC00, (void*)(base + 0x800), 0xA80);
#else
        RequestDma3Copy(gUnk_093FD438, (void*)(base + 0x2C00), 0xA80);
#endif
    }
}
extern u8 gUnk_090950F4[];
extern u8 gUnk_09091D36[];
extern u16* gUnk_09EE78D4[];
extern u16* gUnk_09EE78F0[];
extern void* gUnk_09EE7914[];
extern u8 gUnk_09613EB8[];
extern u8 gUnk_09613ED8[];
extern u8 gUnk_09613F18[];
extern u8 gUnk_09613F38[];
extern u8 gUnk_09613F98[];
extern u8 gUnk_09613FB8[];
extern u8 gUnk_09613FD8[];
extern u8 gUnk_09613FF8[];
#ifdef VERSION_EU
extern u8 gUnkEu_09172200[];
extern u8 gUnkEu_091759BA[];
#endif
u8 func_0809F390(LevelUpWork* w, void* a);
extern const void* gUnk_09EE790C[];
extern u8 gUnk_09614018[];
extern u8 gUnk_09614098[];
#ifdef VERSION_EU
extern u8 gUnkEu_094D53C4[];
extern u8 gUnkEu_094D6BC4[];
extern u8 gUnkEu_094D63C4[];
extern u8 gUnkEu_094D5BC4[];
#endif
void func_0809E7A4(void);

u8 Level_Up_1(LevelUpWork* w, void* a) {
    s32 x[3];
#ifdef VERSION_EU
    enum { tileSize = 0xC80, mapSize = 0x500, bgSize = 0x2C00 };
#else
    enum { tileSize = 0xD80, mapSize = 0x800, bgSize = 0x3680 };
#endif
    if (w->unk_7C2[1] == 0) {
        w->unk_7A4++;
        if (w->unk_7A4 > 7) {
            if (w->unk_7C6 == 0) {
                LoadBgTiles(1, gUnk_093FF8F8, bgSize);
#ifdef VERSION_EU
                switch (gLanguage) {
                case 0:
                    break;
                case 1:
                    RequestDma3Copy(gUnkEu_094D53C4, (void*)(GetBgCharBase(1) + 0x2400), 0x800);
                    RequestDma3Copy(gUnkEu_09F72D08[gLanguage], (void*)(GetBgCharBase(1) + 0x800), 0xC00);
                    break;
                case 2:
                    RequestDma3Copy(gUnkEu_094D6BC4, (void*)(GetBgCharBase(1) + 0x2400), 0x800);
                    RequestDma3Copy(gUnkEu_09F72D08[gLanguage], (void*)(GetBgCharBase(1) + 0x800), 0xC00);
                    break;
                case 3:
                    RequestDma3Copy(gUnkEu_094D63C4, (void*)(GetBgCharBase(1) + 0x2400), 0x800);
                    RequestDma3Copy(gUnkEu_09F72D08[gLanguage], (void*)(GetBgCharBase(1) + 0x800), 0xC00);
                    break;
                case 4:
                    RequestDma3Copy(gUnkEu_094D5BC4, (void*)(GetBgCharBase(1) + 0x2400), 0x800);
                    RequestDma3Copy(gUnkEu_09F72D08[gLanguage], (void*)(GetBgCharBase(1) + 0x800), 0xC00);
                    break;
                }
#endif
                if (!(gGameState.flags & 8)) {
                    LoadPalette(gUnk_09614018, (void*)0x05000140, 0x80);
                } else {
                    func_0809E7A4();
                    LoadPalette(gUnk_09614098, (void*)0x05000140, 0x80);
                }
                LoadBgMap(1, gUnk_0950F2B8, mapSize);
                SetBgMapBlocks(1, gUnk_09EE790C, 2, 1);
                RedrawBgMapAt(1, 0, 0);
            } else {
                if (gBtlWork->unk_10C == 151) {
                    LoadBgTiles(0, gUnk_093FF8F8, bgSize);
#ifdef VERSION_EU
                    switch (gLanguage) {
                    case 0:
                        break;
                    case 1:
                        RequestDma3Copy(gUnkEu_094D53C4, (void*)(GetBgCharBase(0) + 0x2400), 0x800);
                        RequestDma3Copy(gUnkEu_09F72D08[gLanguage], (void*)(GetBgCharBase(0) + 0x800), 0xC00);
                        break;
                    case 2:
                        RequestDma3Copy(gUnkEu_094D6BC4, (void*)(GetBgCharBase(0) + 0x2400), 0x800);
                        RequestDma3Copy(gUnkEu_09F72D08[gLanguage], (void*)(GetBgCharBase(0) + 0x800), 0xC00);
                        break;
                    case 3:
                        RequestDma3Copy(gUnkEu_094D63C4, (void*)(GetBgCharBase(0) + 0x2400), 0x800);
                        RequestDma3Copy(gUnkEu_09F72D08[gLanguage], (void*)(GetBgCharBase(0) + 0x800), 0xC00);
                        break;
                    case 4:
                        RequestDma3Copy(gUnkEu_094D5BC4, (void*)(GetBgCharBase(0) + 0x2400), 0x800);
                        RequestDma3Copy(gUnkEu_09F72D08[gLanguage], (void*)(GetBgCharBase(0) + 0x800), 0xC00);
                        break;
                    }
#endif
                    if (!(gGameState.flags & 8)) {
                        LoadPalette(gUnk_09614018, (void*)0x05000140, 0x80);
                    } else {
                        func_0809E7A4();
                        LoadPalette(gUnk_09614098, (void*)0x05000140, 0x80);
                    }
                    SetBgMapBlocks(0, gUnk_09EE790C, 2, 1);
                    RedrawBgMapAt(0, 0, 0);
                } else {
                    LoadBgTiles(1, gUnk_093FF8F8, bgSize);
#ifdef VERSION_EU
                    switch (gLanguage) {
                    case 0:
                        break;
                    case 1:
                        RequestDma3Copy(gUnkEu_094D53C4, (void*)(GetBgCharBase(1) + 0x2400), 0x800);
                        RequestDma3Copy(gUnkEu_09F72D08[gLanguage], (void*)(GetBgCharBase(1) + 0x800), 0xC00);
                        break;
                    case 2:
                        RequestDma3Copy(gUnkEu_094D6BC4, (void*)(GetBgCharBase(1) + 0x2400), 0x800);
                        RequestDma3Copy(gUnkEu_09F72D08[gLanguage], (void*)(GetBgCharBase(1) + 0x800), 0xC00);
                        break;
                    case 3:
                        RequestDma3Copy(gUnkEu_094D63C4, (void*)(GetBgCharBase(1) + 0x2400), 0x800);
                        RequestDma3Copy(gUnkEu_09F72D08[gLanguage], (void*)(GetBgCharBase(1) + 0x800), 0xC00);
                        break;
                    case 4:
                        RequestDma3Copy(gUnkEu_094D5BC4, (void*)(GetBgCharBase(1) + 0x2400), 0x800);
                        RequestDma3Copy(gUnkEu_09F72D08[gLanguage], (void*)(GetBgCharBase(1) + 0x800), 0xC00);
                        break;
                    }
#endif
                    if (!(gGameState.flags & 8)) {
                        LoadPalette(gUnk_09614018, (void*)0x05000140, 0x80);
                    } else {
                        func_0809E7A4();
                        LoadPalette(gUnk_09614098, (void*)0x05000140, 0x80);
                    }
                    SetBgMapBlocks(1, gUnk_09EE790C, 2, 1);
                    RedrawBgMapAt(1, 0, 0);
                }
            }
            FadeSetPaletteExcluded(10, 1);
            FadeSetPaletteExcluded(11, 1);
            FadeSetPaletteExcluded(12, 1);
            FadeSetPaletteExcluded(13, 1);
            w->unk_7C2[1] = 1;
            w->unk_7A4 = 0;
            return 1;
        }
        return 1;
    }
    if (w->unk_7C2[0] == 0) {
        w->unk_7A4++;
        if (w->unk_7A4 > 7) {
            if (!(gGameState.flags & 8)) {
                w->unk_000[0] = AllocSpriteFrameTiles(tileSize);
                w->unk_000[1] = AllocSpriteFrameTiles(tileSize);
                w->unk_000[2] = AllocSpriteFrameTiles(tileSize);
#ifdef VERSION_EU
                if (gLanguage != 3) {
#endif
                    UpdateSpriteFrameTiles(w->unk_000[0], gUnk_09EEA2BC[0], gUnk_090950F4);
                    UpdateSpriteFrameTiles(w->unk_000[1], gUnk_09EEA2BC[1], gUnk_090950F4);
                    UpdateSpriteFrameTiles(w->unk_000[2], gUnk_09EEA2BC[2], gUnk_090950F4);
#ifdef VERSION_EU
                } else {
                    UpdateSpriteFrameTiles(w->unk_000[0], gUnkEu_09F7626C[0], gUnkEu_09172200);
                    UpdateSpriteFrameTiles(w->unk_000[1], gUnkEu_09F7626C[1], gUnkEu_09172200);
                    UpdateSpriteFrameTiles(w->unk_000[2], gUnkEu_09F7626C[2], gUnkEu_09172200);
                }
#endif
                w->unk_000[4] = LoadObjPalette(gUnk_09613F18, 32);
                w->unk_000[5] = LoadObjPalette(gUnk_09613F38, 32);
            } else {
                w->unk_000[0] = AllocSpriteFrameTiles(tileSize);
                w->unk_000[1] = AllocSpriteFrameTiles(tileSize);
                w->unk_000[2] = AllocSpriteFrameTiles(tileSize);
#ifdef VERSION_EU
                if (gLanguage != 3) {
#endif
                    UpdateSpriteFrameTiles(w->unk_000[0], gUnk_09EEA29C[0], gUnk_09091D36);
                    UpdateSpriteFrameTiles(w->unk_000[1], gUnk_09EEA29C[1], gUnk_09091D36);
                    UpdateSpriteFrameTiles(w->unk_000[2], gUnk_09EEA29C[2], gUnk_09091D36);
#ifdef VERSION_EU
                } else {
                    UpdateSpriteFrameTiles(w->unk_000[0], gUnkEu_09F762A4[0], gUnkEu_091759BA);
                    UpdateSpriteFrameTiles(w->unk_000[1], gUnkEu_09F762A4[1], gUnkEu_091759BA);
                    UpdateSpriteFrameTiles(w->unk_000[2], gUnkEu_09F762A4[2], gUnkEu_091759BA);
                }
#endif
                w->unk_000[4] = LoadObjPalette(gUnk_09613EB8, 32);
                w->unk_000[5] = LoadObjPalette(gUnk_09613ED8, 32);
            }
#ifdef VERSION_EU
            switch (gLanguage) {
            case 0:
                w->tiles3 = LoadObjTiles(gUnk_0908C686, 0x3E0);
                break;
            case 1:
                w->tiles3 = LoadObjTiles(gUnkEu_0916F992, 0x3E0);
                break;
            case 2:
                w->tiles3 = LoadObjTiles(gUnkEu_0917063A, 0x3E0);
                break;
            case 3:
                w->tiles3 = LoadObjTiles(gUnkEu_09170202, 0x3E0);
                break;
            case 4:
                w->tiles3 = LoadObjTiles(gUnkEu_0916FDCA, 0x3E0);
                break;
            default:
                w->tiles3 = LoadObjTiles(gUnk_0908C686, 0x3E0);
                break;
            }
#else
            w->tiles3 = LoadObjTiles(gUnk_0908C686, 0x3E0);
#endif
            w->palette4 = LoadObjPalette(gUnk_09611AB8, 32);
            FadeSetPaletteExcluded(((ObjPalette*)w->unk_000[4])->index + 16, 1);
            FadeSetPaletteExcluded(((ObjPalette*)w->unk_000[5])->index + 16, 1);
            FadeSetPaletteExcluded(((ObjPalette*)w->palette4)->index + 16, 1);
            w->tiles = AllocObjTiles(0x3C0, 0);
            w->palette3 = LoadObjPalette(gUnk_09618CD8, 32);
            FadeSetPaletteExcluded(((ObjPalette*)w->palette3)->index + 16, 1);
            SetObjTileSource(w->tiles, gUnk_093F4578);
            AnimInit(&w->anim, gUnk_09EF1170, gUnk_09EF1150);
            AnimStart(&w->anim, 2, 1);
            w->gfx2 = AnimGetGfx(&w->anim);
            w->unk_7C2[0] = 1;
            w->unk_7A4 = 0;
            FadeToAmount(0, 8, 16);
        }
        return 1;
    }
    w->gfx = AnimUpdate(&w->anim2);
    if (w->unk_7C0 != 0) {
        ApproachValue(&w->x7, 0xBE00, w->unk_7C0);
        ApproachValue(&w->y6, 0x5000, w->unk_7C0);
        w->unk_7C0--;
    }
    if (w->unk_7BF != 0) {
        ApproachValue(&w->y, 0, w->unk_7BF);
        ApproachValue(&w->y2, 0x9800, w->unk_7BF);
        w->unk_7BF--;
    } else {
        s32 x3 = w->unk_77A << 8;
        s32 x4 = w->unk_77C << 8;
        ApproachValue(&x3, 0x10000, w->unk_7B5);
        ApproachValue(&x4, 0, w->unk_7B5);
        if (gBtlWork->unk_10C == 151) {
            ScrollBgMapTo(0, (u16)(x3 >> 8), 0);
        } else {
            ScrollBgMapTo(1, (u16)(x3 >> 8), 0);
        }
        w->unk_77A = x3 >> 8;
        w->unk_77C = x4 >> 8;
        if (w->unk_7B5 > 0) {
            w->unk_7B5--;
        }
        if (w->unk_7B5 <= 11) {
            s32 x5 = w->x6 << 8;
            ApproachValue(&x5, 0, w->unk_7B1);
            w->x6 = x5 >> 8;
            if (w->unk_7B1 > 0) {
                w->unk_7B1--;
            }
            if (w->unk_7B1 <= 6) {
                x[0] = w->x4[0] << 8;
                x[1] = w->x4[1] << 8;
                x[2] = w->x4[2] << 8;
                ApproachValue(&x[0], 0x1000, w->unk_7B2[0]);
                if (w->unk_7B2[0] > 0) {
                    w->unk_7B2[0]--;
                }
                if (w->unk_7B2[0] <= 6) {
                    ApproachValue(&x[1], 0x1000, w->unk_7B2[1]);
                    if (w->unk_7B2[1] > 0) {
                        w->unk_7B2[1]--;
                    }
                }
                if (w->unk_7B2[1] <= 6) {
                    ApproachValue(&x[2], 0x1000, w->unk_7B2[2]);
                    if (w->unk_7B2[2] > 0) {
                        w->unk_7B2[2]--;
                    }
                }
                w->x4[0] = x[0] >> 8;
                w->x4[1] = x[1] >> 8;
                w->x4[2] = x[2] >> 8;
                if (w->unk_7B2[2] == 0) {
                    u8 i;
                    if (gBtlWork->unk_10C == 151) {
                        LoadBgMap(0, gUnk_095112B8, mapSize);
                    } else {
                        LoadBgMap(1, gUnk_095112B8, mapSize);
                    }
                    w->unk_7BD = 1;
                    if (!(gGameState.flags & 8)) {
                        if ((s16)gGameState.progression.maxHp > 559) {
#ifdef VERSION_EU
                            UpdateSpriteFrameTiles(w->tiles5[0], gUnkEu_09F72D58[gLanguage][6], gUnkEu_09F72D44[gLanguage]);
#else
                            w->unk_7B7[0] = LoadTextSlots(gUnk_09EE78D4[6], w->text[0]);
                            w->unk_7B7[3] = 0;
#endif
                            w->unk_7C8[0] = 0;
                        } else {
#ifdef VERSION_EU
                            UpdateSpriteFrameTiles(w->tiles5[0], gUnkEu_09F72D58[gLanguage][0], gUnkEu_09F72D44[gLanguage]);
#else
                            w->unk_7B7[0] = LoadTextSlots(gUnk_09EE78D4[0], w->text[0]);
                            w->unk_7B7[3] = LoadTextSlots(gUnk_09EE78D4[3], w->text[3]);
#endif
                        }
                        if (gGameState.progression.cp > 1899) {
#ifdef VERSION_EU
                            UpdateSpriteFrameTiles(w->tiles5[1], gUnkEu_09F72D58[gLanguage][6], gUnkEu_09F72D44[gLanguage]);
#else
                            w->unk_7B7[1] = LoadTextSlots(gUnk_09EE78D4[6], w->text[1]);
                            w->unk_7B7[4] = 0;
#endif
                            w->unk_7C8[1] = 0;
                        } else {
#ifdef VERSION_EU
                            UpdateSpriteFrameTiles(w->tiles5[1], gUnkEu_09F72D58[gLanguage][1], gUnkEu_09F72D44[gLanguage]);
#else
                            w->unk_7B7[1] = LoadTextSlots(gUnk_09EE78D4[1], w->text[1]);
                            w->unk_7B7[4] = LoadTextSlots(gUnk_09EE78D4[4], w->text[4]);
#endif
                        }
                        if (gGameState.progression.unk_80 > 10) {
#ifdef VERSION_EU
                            UpdateSpriteFrameTiles(w->tiles5[2], gUnkEu_09F72D58[gLanguage][6], gUnkEu_09F72D44[gLanguage]);
#else
                            w->unk_7B7[2] = LoadTextSlots(gUnk_09EE78D4[6], w->text[2]);
                            w->unk_7B7[5] = 0;
#endif
                            w->unk_7C8[2] = 0;
                        } else if ((u8)func_080A2370() == 0) {
#ifdef VERSION_EU
                            UpdateSpriteFrameTiles(w->tiles5[2], gUnkEu_09F72D58[gLanguage][6], gUnkEu_09F72D44[gLanguage]);
#else
                            w->unk_7B7[2] = LoadTextSlots(gUnk_09EE78D4[6], w->text[2]);
                            w->unk_7B7[5] = 0;
#endif
                            w->unk_7C8[2] = 0;
                        } else {
#ifdef VERSION_EU
                            UpdateSpriteFrameTiles(w->tiles5[2], gUnkEu_09F72D58[gLanguage][2], gUnkEu_09F72D44[gLanguage]);
#else
                            w->unk_7B7[2] = LoadTextSlots(gUnk_09EE78D4[2], w->text[2]);
                            w->unk_7B7[5] = LoadTextSlots(gUnk_09EE78D4[5], w->text[5]);
#endif
                        }
                        w->palette = LoadObjPalette(gUnk_09613F98, 32);
                        w->palette2 = LoadObjPalette(gUnk_09613FB8, 32);
                    } else {
                        if ((s16)gGameState.progression.maxHp > 559) {
#ifdef VERSION_EU
                            UpdateSpriteFrameTiles(w->tiles5[0], gUnkEu_09F72D58[gLanguage][6], gUnkEu_09F72D44[gLanguage]);
#else
                            w->unk_7B7[0] = LoadTextSlots(gUnk_09EE78F0[6], w->text[0]);
                            w->unk_7B7[3] = 0;
#endif
                            w->unk_7C8[0] = 0;
                        } else {
#ifdef VERSION_EU
                            UpdateSpriteFrameTiles(w->tiles5[0], gUnkEu_09F72D58[gLanguage][3], gUnkEu_09F72D44[gLanguage]);
#else
                            w->unk_7B7[0] = LoadTextSlots(gUnk_09EE78F0[0], w->text[0]);
                            w->unk_7B7[3] = LoadTextSlots(gUnk_09EE78F0[3], w->text[3]);
#endif
                        }
                        if ((s16)gGameState.progression.ap > 29) {
#ifdef VERSION_EU
                            UpdateSpriteFrameTiles(w->tiles5[1], gUnkEu_09F72D58[gLanguage][6], gUnkEu_09F72D44[gLanguage]);
#else
                            w->unk_7B7[1] = LoadTextSlots(gUnk_09EE78D4[6], w->text[1]);
                            w->unk_7B7[4] = 0;
#endif
                            w->unk_7C8[1] = 0;
                        } else if ((u8)func_080A151C() == 0) {
#ifdef VERSION_EU
                            UpdateSpriteFrameTiles(w->tiles5[1], gUnkEu_09F72D58[gLanguage][6], gUnkEu_09F72D44[gLanguage]);
#else
                            w->unk_7B7[1] = LoadTextSlots(gUnk_09EE78D4[6], w->text[1]);
                            w->unk_7B7[4] = 0;
#endif
                            w->unk_7C8[1] = 0;
                        } else {
#ifdef VERSION_EU
                            UpdateSpriteFrameTiles(w->tiles5[1], gUnkEu_09F72D58[gLanguage][4], gUnkEu_09F72D44[gLanguage]);
#else
                            w->unk_7B7[1] = LoadTextSlots(gUnk_09EE78F0[1], w->text[1]);
                            w->unk_7B7[4] = LoadTextSlots(gUnk_09EE78F0[4], w->text[4]);
#endif
                        }
                        if ((s16)gGameState.progression.dp > 299) {
#ifdef VERSION_EU
                            UpdateSpriteFrameTiles(w->tiles5[2], gUnkEu_09F72D58[gLanguage][6], gUnkEu_09F72D44[gLanguage]);
#else
                            w->unk_7B7[2] = LoadTextSlots(gUnk_09EE78D4[6], w->text[2]);
                            w->unk_7B7[5] = 0;
#endif
                            w->unk_7C8[2] = 0;
                        } else {
#ifdef VERSION_EU
                            UpdateSpriteFrameTiles(w->tiles5[2], gUnkEu_09F72D58[gLanguage][5], gUnkEu_09F72D44[gLanguage]);
#else
                            w->unk_7B7[2] = LoadTextSlots(gUnk_09EE78F0[2], w->text[2]);
                            w->unk_7B7[5] = LoadTextSlots(gUnk_09EE78F0[5], w->text[5]);
#endif
                        }
                        w->palette = LoadObjPalette(gUnk_09613FD8, 32);
                        w->palette2 = LoadObjPalette(gUnk_09613FF8, 32);
                    }
                    FadeSetPaletteExcluded(((ObjPalette*)w->palette)->index + 16, 1);
                    FadeSetPaletteExcluded(((ObjPalette*)w->palette2)->index + 16, 1);
                    for (i = 0; i < 3; i++) {
                        if (w->unk_7C8[i] == 1) {
                            break;
                        }
                    }
                    w->unk_7B0 = i;
                    w->y3 = gUnk_09037FB4[w->unk_7B0];
                    SetTaskUpdate(a, (void*)func_0809F390);
                    if (gBtlWork->unk_10C == 151) {
                        LoadBgMap(0, gUnk_09EE7914[w->unk_7B0], 0x800);
                    } else {
                        LoadBgMap(1, gUnk_09EE7914[w->unk_7B0], 0x800);
                    }
                }
            }
        }
    }
    TaskPoolUpdate(&w->pool);
    return 1;
}

u8 func_0809F390(LevelUpWork* w, void* a) {
    s32 x;
    s8 i;
    u8* q;
#ifdef VERSION_EU
    enum { mapOffset = 0x20C0, mapSize = 0x500, palOffset = 0x2320 };
#else
    enum { mapOffset = 0x7C0, mapSize = 0x800, palOffset = 0x24A0 };
#endif

    if (GetKeysRepeat() & 0x80) {
        i = w->unk_7B0;
        q = w->unk_7C8;

        do {
            i++;

            if (i > 2) {
                i = 0;
            }
        } while (q[i] == 0);

        if (i != w->unk_7B0) {
            m4aSongNumStart(101);
        }

        w->unk_7B0 = i;

        if (gBtlWork->unk_10C == 151) {
            LoadBgMap(0, gUnk_09EE7914[w->unk_7B0], 0x800);
        } else {
            LoadBgMap(1, gUnk_09EE7914[w->unk_7B0], 0x800);
        }

        w->unk_7B6 = 8;
    }

    if (GetKeysRepeat() & 0x40) {
        i = w->unk_7B0;
        q = w->unk_7C8;

        do {
            i--;

            if (i < 0) {
                i = 2;
            }
        } while (q[i] == 0);

        if (i != w->unk_7B0) {
            m4aSongNumStart(101);
        }

        w->unk_7B0 = i;

        if (gBtlWork->unk_10C == 151) {
            LoadBgMap(0, gUnk_09EE7914[w->unk_7B0], 0x800);
        } else {
            LoadBgMap(1, gUnk_09EE7914[w->unk_7B0], 0x800);
        }

        w->unk_7B6 = 8;
    }

    while (GetKeysRepeat() & 1) {
        w->unk_7BD = 2;

        if (gBtlWork->unk_10C == 151) {
            LoadBgMap(0, &gUnk_0950E2F8[mapOffset], mapSize);
        } else {
            LoadBgMap(1, &gUnk_0950E2F8[mapOffset], mapSize);
        }

        w->unk_7B2[0] = 16;
        w->unk_7B2[1] = 16;
        w->unk_7B2[2] = 16;
        m4aSongNumStart(102);
        ReleaseObjTiles(w->tiles);
        ReleaseObjPalette(w->palette3);
        w->tiles = AllocObjTiles(128, 0);
        w->palette3 = LoadObjPalette(&gUnk_09611AB8[palOffset], 32);
        FadeSetPaletteExcluded(((ObjPalette*)w->palette3)->index + 16, 1);
        SetObjTileSource(w->tiles, &gUnk_0908C686[0x2B0A]);
        AnimInit(&w->anim, &gUnk_09EEA1EC[0x25], &gUnk_09EEA19C[0x34]);
        AnimStart(&w->anim, 0, 1);
        w->gfx2 = AnimGetGfx(&w->anim);
        w->unk_7B6 = 16;
        w->x3 = 136;

        if (!(gGameState.flags & 8)) {
            SetObjTileSource(w->tiles4, gUnk_088B6560);
            AnimInit(&w->anim2, gUnk_09EDE918, gUnk_09EDE8CC);
            AnimStart(&w->anim2, 1, 0);
        } else {
            SetObjTileSource(w->tiles4, gUnk_092EB78A);
            AnimInit(&w->anim2, gUnk_09EEF8C0, gUnk_09EEF89C);
            AnimStart(&w->anim2, 1, 0);
        }

        SetTaskUpdate(a, (void*)func_0809F730);
        return 1;
    }

    x = w->y3 << 8;
    ApproachValue(&x, gUnk_09037FB4[w->unk_7B0] << 8, w->unk_7B6);
    w->unk_7B6--;
    w->y3 = x >> 8;
    w->gfx2 = AnimUpdate(&w->anim);
    w->unk_7BE++;

    if (w->unk_7BE == 32) {
        w->unk_7BE = 0;
        w->unk_7C1 ^= 1;
    }

    w->gfx = AnimUpdate(&w->anim2);
    TaskPoolUpdate(&w->pool);
    return 1;
}

extern const void* gUnk_09EE790C[];
u8 func_0809FBCC(u8* work, void* a);

u8 func_0809F730(LevelUpWork* w, void* a) {
    u8 i;

    if (w->unk_7C5 == 0) {
#ifndef VERSION_US
        LevelUpEffectArgs args;
        args.x = 192;
        args.y = 60;
        args.unk_08 = 0;
        args.unk_0C = 0;
        TaskCreate(&w->pool, &gTaskDescLVUPEFFECT, &args);
        m4aSongNumStart(148);
#endif
        w->unk_7C5++;
    }
    for (i = 0; i < 3; i++) {
        if (i != w->unk_7B0) {
            s32 x = w->x4[i] << 8;
            s32 y = w->x5[i] << 8;
            ApproachValue(&x, -0x10000, w->unk_7B2[i]);
            ApproachValue(&y, -0xF800, w->unk_7B2[i]);
            w->x4[i] = x >> 8;
            w->x5[i] = y >> 8;
        } else {
            s32 x = w->y4[i] << 8;
            s32 y = w->y5[i] << 8;
            ApproachValue(&x, 0x2000, w->unk_7B2[i]);
            ApproachValue(&y, 0x3100, w->unk_7B2[i]);
            w->y4[i] = x >> 8;
            w->y5[i] = y >> 8;
        }
        if (w->unk_7B2[i] > 0) {
            w->unk_7B2[i]--;
        }
    }
    if (w->unk_7B2[0] == 0) {
        for (i = 0; i < 3; i++) {
            if (i != w->unk_7B0 && w->unk_000[i] != 0) {
                ReleaseObjTiles(w->unk_000[i]);
                w->unk_000[i] = 0;
            }
        }
        if (w->unk_7C7 == 0) {
            switch (w->unk_7B0) {
            case 0: {
                s32 amount = LevelUpMaxHp();
                StatIncreaseDisplayArgs args;
                w->unk_7C4 = 1;
                args.amount = amount;
                args.done = &w->unk_7C4;
                args.flags = 0x8000;
                TaskCreate(&w->pool, &gTaskDescLvupMsg, &args);
                break;
            }
            case 1:
                if (!(gGameState.flags & 8)) {
                    s32 amount = LevelUpCp();
                    StatIncreaseDisplayArgs args;
                    w->unk_7C4 = 1;
                    args.amount = amount;
                    args.done = &w->unk_7C4;
                    args.flags = 0;
                    TaskCreate(&w->pool, &gTaskDescLvupMsg, &args);
                } else {
                    s32 amount = LevelUpAp();
                    StatIncreaseDisplayArgs args;
                    w->unk_7C4 = 1;
                    args.amount = amount;
                    args.done = &w->unk_7C4;
                    args.flags = 0;
                    gGameState.progression.unk_80++;
                    TaskCreate(&w->pool, &gTaskDescLvupMsg, &args);
                }
                break;
            case 2:
                if (!(gGameState.flags & 8)) {
                    w->unk_7C4 = 1;
                    TaskCreate(&w->pool, &gTaskDescStockInfo, &w->unk_7C4);
                } else {
                    s32 amount = LevelUpDp();
                    StatIncreaseDisplayArgs args;
                    w->unk_7C4 = 1;
                    args.amount = amount;
                    args.done = &w->unk_7C4;
                    args.flags = 0x4000;
                    TaskCreate(&w->pool, &gTaskDescLvupMsg, &args);
                }
                break;
            }
            func_080A096C(gGameState.progression.maxHp, w->unk_784);
            func_080A09C0((u16)gGameState.progression.cp, w->unk_78C);
            func_080A096C(gGameState.progression.dp, w->unk_794);
            func_080A0944(gGameState.progression.ap, w->unk_79C);
            w->unk_7C7 = 1;
        }
    }
    {
        s32 y = w->y3 << 8;
        ApproachValue(&y, 0x3000, w->unk_7B6);
        w->unk_7B6--;
        w->y3 = y >> 8;
    }
    TaskPoolUpdate(&w->pool);
    w->unk_7BE++;
    if (w->unk_7BE == 32) {
        w->unk_7BE = 0;
        w->unk_7C1 ^= 1;
    }
    if (w->unk_7A4 == 180) {
        if (GetKeysPressed() & 1) {
            if (gBtlWork->unk_10C == 151) {
                SetBgMapBlocks(0, gUnk_09EE790C, 2, 1);
            } else {
                SetBgMapBlocks(1, gUnk_09EE790C, 2, 1);
            }
            w->unk_7B1 = 16;
            w->unk_7B5 = 16;
            w->unk_7B2[w->unk_7B0] = 16;
            w->unk_7BF = 16;
            w->unk_7BD = 3;
            w->unk_7C1 = 0;
            w->unk_7C4 = 0;
            gBtlWork->unk_0FA--;
            if (gBtlWork->unk_0FA == 0) {
                SetTaskUpdate(a, (void*)func_0809FBCC);
            } else {
                SetTaskUpdate(a, (void*)func_080A11CC);
            }
            m4aSongNumStart(102);
        }
    } else {
        w->unk_7A4++;
    }
    w->gfx2 = AnimUpdate(&w->anim);
    w->gfx = AnimUpdate(&w->anim2);
    return 1;
}
u8 func_0809FBCC(u8* work, void* a) {
    s32 v1;
    s32 v2;
    s32 v3;
    s32 v4;
    s32 v0;
    u8 t;
    s8 n;
    u8* q;
    s32 ofs;
    u8* q1;
    u8* q2;

    ofs = (s8)work[offsetof(LevelUpWork, unk_7B0)] * 2;
    q1 = &work[offsetof(LevelUpWork, x4)];
    v1 = *(s16*)(q1 + ofs) << 8;
    ofs = (s8)work[offsetof(LevelUpWork, unk_7B0)] * 2;
    q2 = &work[offsetof(LevelUpWork, x5)];
    v2 = *(s16*)(q2 + ofs) << 8;
    v3 = *(s16*)&work[offsetof(LevelUpWork, unk_77A)] << 8;
    v4 = *(s16*)&work[offsetof(LevelUpWork, unk_77C)] << 8;
    v0 = *(s16*)&work[offsetof(LevelUpWork, x6)] << 8;
    ApproachValue(&v0, -0x8000, (s8)work[offsetof(LevelUpWork, unk_7B1)]);
    ApproachValue(&v1, -0x8000, (s8)((UnkStruct_0809FBCC*)work)->unk_7B2[(s8)work[offsetof(LevelUpWork, unk_7B0)]]);
    ApproachValue(&v2, -0xF800, (s8)((UnkStruct_0809FBCC*)work)->unk_7B2[(s8)work[offsetof(LevelUpWork, unk_7B0)]]);
    ofs = (s8)work[offsetof(LevelUpWork, unk_7B0)] * 2;
    *(s16*)(q1 + ofs) = v1 >> 8;
    ofs = (s8)work[offsetof(LevelUpWork, unk_7B0)] * 2;
    *(s16*)(q2 + ofs) = v2 >> 8;
    *(s16*)&work[offsetof(LevelUpWork, x6)] = v0 >> 8;
    work[offsetof(LevelUpWork, unk_7B1)]--;
    ofs = (s8)work[offsetof(LevelUpWork, unk_7B0)];
    q = ((UnkStruct_0809FBCC*)work)->unk_7B2;
    q += ofs;
    (*q)--;
    ApproachValue(&v3, 0, (s8)work[offsetof(LevelUpWork, unk_7B5)]);
    ApproachValue(&v4, 0x10000, (s8)work[offsetof(LevelUpWork, unk_7B5)]);
    ApproachValue(&work[offsetof(LevelUpWork, x7)], 0x1BE00, (s8)work[offsetof(LevelUpWork, unk_7B5)]);
    ApproachValue(&work[offsetof(LevelUpWork, y6)], 0x4800, (s8)work[offsetof(LevelUpWork, unk_7B5)]);

    if (gBtlWork->unk_10C == 151) {
        ScrollBgMapTo(0, v3 >> 8, 0);
    } else {
        ScrollBgMapTo(1, v3 >> 8, 0);
    }

    ((UnkStruct_0809FBCC*)work)->unk_77A = v3 >> 8;
    ((UnkStruct_0809FBCC*)work)->unk_77C = v4 >> 8;
    t = work[offsetof(LevelUpWork, unk_7B5)];

    if ((s8)t > 0) {
        work[offsetof(LevelUpWork, unk_7B5)] = t - 1;
    }

    n = work[offsetof(LevelUpWork, unk_7B5)];

    if (n == 0) {
        if (work[offsetof(LevelUpWork, unk_7BF)] != 0) {
            ApproachValue(&work[offsetof(LevelUpWork, y)], -0x800, work[offsetof(LevelUpWork, unk_7BF)]);
            ApproachValue(&work[offsetof(LevelUpWork, y2)], 0xA000, work[offsetof(LevelUpWork, unk_7BF)]);
            work[offsetof(LevelUpWork, unk_7BF)]--;
        } else {
            SetTaskUpdate(a, (void*)func_0809FE14);
        }
    }

    *(void**)&work[offsetof(LevelUpWork, gfx)] = AnimUpdate(&work[offsetof(LevelUpWork, anim2)]);
    TaskPoolUpdate(&work[offsetof(LevelUpWork, pool)]);
    return 1;
}
u8 func_0809FE14(void) {
    if (FadeIsActive() == 0) {
        return 0;
    }
    return 1;
}

void func_080A0734(s16 x, s16 y, void* tiles, void* pal, void** gfx, u16* digits, u8 kind);

void Level_Up_2(LevelUpWork* w) {
    u8 i = 0;

    if (w->unk_7C2[0] != 0) {
        switch (w->unk_7BD) {
        case 0:
            DrawSprite(w->x6, 0,
#ifdef VERSION_EU
                       gUnk_09EEA1BC[gLanguage][10],
#else
                       gUnk_09EEA1BC[10],
#endif
                       w->unk_000[6], w->unk_000[7], 0, 0, 50);
            if (w->unk_000[0] != 0) {
#ifdef VERSION_EU
                if (gLanguage != 3) {
#endif
                    DrawSprite(w->x4[0], w->y4[0], gUnk_09EEA2BC[0], w->unk_000[0], w->unk_000[4], 0, 0, 50);
#ifdef VERSION_EU
                } else {
                    DrawSprite(w->x4[0], w->y4[0], gUnkEu_09F7626C[0], w->unk_000[0], w->unk_000[4], 0, 0, 50);
                }
#endif
            }
            if (w->unk_000[1] != 0) {
#ifdef VERSION_EU
                if (gLanguage != 3) {
#endif
                    DrawSprite(w->x4[1], w->y4[1], gUnk_09EEA2BC[1], w->unk_000[1], w->unk_000[4], 0, 0, 50);
#ifdef VERSION_EU
                } else {
                    DrawSprite(w->x4[1], w->y4[1], gUnkEu_09F7626C[1], w->unk_000[1], w->unk_000[4], 0, 0, 50);
                }
#endif
            }
            if (w->unk_000[2] != 0) {
#ifdef VERSION_EU
                if (gLanguage != 3) {
#endif
                    DrawSprite(w->x4[2], w->y4[2], gUnk_09EEA2BC[2], w->unk_000[2], w->unk_000[4], 0, 0, 50);
#ifdef VERSION_EU
                } else {
                    DrawSprite(w->x4[2], w->y4[2], gUnkEu_09F7626C[2], w->unk_000[2], w->unk_000[4], 0, 0, 50);
                }
#endif
            }
            DrawSprite(w->x, w->y >> 8, gUnk_09EEA1EC[0], w->tiles2, w->unk_000[7], 0, 0x400, 51);
            DrawSprite(w->x2, w->y2 >> 8, gUnk_09EEA1EC[1], w->tiles2, w->unk_000[7], 0, 0x400, 51);
            break;
        case 1:
            for (; i < 3; i++) {
                if (i == w->unk_7B0) {
#ifdef VERSION_EU
                    DrawSprite(w->x5[i] + 5, w->y5[i] - 4, 0, w->tiles5[i], w->palette, 0, 0, 40);
#else
                    DrawTextSlots(w->x5[i] + 22, w->y5[i] - 5, w->text[i], w->palette, 40, w->unk_7B7[i]);
                    DrawTextSlots(w->x5[i] + 4, w->y5[i] + 13, w->text[i + 3], w->palette, 40, w->unk_7B7[i + 3]);
#endif
                } else {
#ifdef VERSION_EU
                    DrawSprite(w->x5[i] + 3, w->y5[i] - 2, 0, w->tiles5[i], w->palette2, 0, 0, 40);
#else
                    DrawTextSlots(w->x5[i] + 20, w->y5[i] - 3, w->text[i], w->palette2, 40, w->unk_7B7[i]);
                    DrawTextSlots(w->x5[i] + 2, w->y5[i] + 15, w->text[i + 3], w->palette2, 40, w->unk_7B7[i + 3]);
#endif
                }
            }
            DrawSprite(w->x3, w->y3, w->gfx2, w->tiles, w->palette3, 0, 0, 40);
            break;
        case 2:
            for (; i < 3; i++) {
                if (i == w->unk_7B0) {
#ifdef VERSION_EU
                    DrawSprite(w->x5[i] + 4, w->y5[i] - 3, 0, w->tiles5[i], w->palette, 0, 0, 40);
#else
                    DrawTextSlots(w->x5[i] + 22, w->y5[i] - 5, w->text[i], w->palette, 40, w->unk_7B7[i]);
                    DrawTextSlots(w->x5[i] + 4, w->y5[i] + 13, w->text[i + 3], w->palette, 40, w->unk_7B7[i + 3]);
#endif
                    DrawSprite(w->x4[i], w->y4[i], gUnk_09EEA2D8[i], w->unk_000[i], w->unk_000[5], 0, 0, 50);
                } else {
                    if (w->unk_000[i] != 0) {
#ifdef VERSION_EU
                        DrawSprite(w->x5[i] + 2, w->y5[i] - 1, 0, w->tiles5[i], w->palette2, 0, 0, 40);
#else
                        DrawTextSlots(w->x5[i] + 20, w->y5[i] - 3, w->text[i], w->palette2, 40, w->unk_7B7[i]);
                        DrawTextSlots(w->x5[i] + 2, w->y5[i] + 15, w->text[i + 3], w->palette2, 40, w->unk_7B7[i + 3]);
#endif
#ifdef VERSION_EU
                        if (gLanguage != 3) {
#endif
                            DrawSprite(w->x4[i], w->y4[i], gUnk_09EEA2BC[i], w->unk_000[i], w->unk_000[4], 0, 0, 50);
#ifdef VERSION_EU
                        } else {
                            DrawSprite(w->x4[i], w->y4[i], gUnkEu_09F7626C[i], w->unk_000[i], w->unk_000[4], 0, 0, 50);
                        }
#endif
                    }
                }
            }
            DrawSprite(w->x3, w->y3, w->gfx2, w->tiles, w->palette3, 0, 0, 40);
            break;
        case 3:
#ifdef VERSION_EU
            DrawSprite(w->x5[w->unk_7B0] + 2, w->y5[w->unk_7B0] - 1, 0, w->tiles5[w->unk_7B0], w->palette, 0, 0, 40);
#else
            DrawTextSlots(w->x5[w->unk_7B0] + 22, w->y5[w->unk_7B0] - 5, w->text[w->unk_7B0], w->palette, 40, w->unk_7B7[w->unk_7B0]);
            DrawTextSlots(w->x5[w->unk_7B0] + 4, w->y5[w->unk_7B0] + 13, w->text[w->unk_7B0 + 3], w->palette, 40, w->unk_7B7[w->unk_7B0 + 3]);
#endif
            DrawSprite(w->x4[w->unk_7B0], w->y4[w->unk_7B0], 0, w->unk_000[w->unk_7B0], w->unk_000[5], 0, 0, 50);
            DrawSprite(w->x6, 0,
#ifdef VERSION_EU
                       gUnk_09EEA1BC[gLanguage][10],
#else
                       gUnk_09EEA1BC[10],
#endif
                       w->unk_000[6], w->unk_000[7], 0, 0, 50);
            DrawSprite(w->x, w->y >> 8, gUnk_09EEA1EC[0], w->tiles2, w->unk_000[7], 0, 0x400, 51);
            DrawSprite(w->x2, w->y2 >> 8, gUnk_09EEA1EC[1], w->tiles2, w->unk_000[7], 0, 0x400, 51);
            break;
        }
#ifdef VERSION_JP
        if (w->unk_7C1 != 0) {
            DrawSprite(192, 82, gUnk_09EEA19C[0], w->tiles3, w->palette4, 0, 0, 10);
        }
#endif
        if (!(gGameState.flags & 8)) {
            func_080A0734(w->unk_77C + 214, 17, w->unk_000[6], w->unk_000[7],
#ifdef VERSION_EU
                       gUnk_09EEA1BC[gLanguage],
#else
                       gUnk_09EEA1BC,
#endif
                       w->unk_77E, 0);
            func_080A0734(w->unk_77C + 214, 111, w->unk_000[6], w->unk_000[7],
#ifdef VERSION_EU
                       gUnk_09EEA1BC[gLanguage],
#else
                       gUnk_09EEA1BC,
#endif
                       w->unk_784, 1);
            func_080A0734(w->unk_77C + 206, 132, w->unk_000[6], w->unk_000[7],
#ifdef VERSION_EU
                       gUnk_09EEA1BC[gLanguage],
#else
                       gUnk_09EEA1BC,
#endif
                       w->unk_78C, 2);
        } else {
            func_080A0734(w->unk_77C + 214, 17, w->unk_000[6], w->unk_000[7],
#ifdef VERSION_EU
                       gUnk_09EEA1BC[gLanguage],
#else
                       gUnk_09EEA1BC,
#endif
                       w->unk_77E, 0);
            func_080A0734(w->unk_77C + 214, 106, w->unk_000[6], w->unk_000[7],
#ifdef VERSION_EU
                       gUnk_09EEA1BC[gLanguage],
#else
                       gUnk_09EEA1BC,
#endif
                       w->unk_784, 1);
            func_080A0734(w->unk_77C + 214, 122, w->unk_000[6], w->unk_000[7],
#ifdef VERSION_EU
                       gUnk_09EEA1BC[gLanguage],
#else
                       gUnk_09EEA1BC,
#endif
                       w->unk_79C, 4);
            func_080A0734(w->unk_77C + 214, 137, w->unk_000[6], w->unk_000[7],
#ifdef VERSION_EU
                       gUnk_09EEA1BC[gLanguage],
#else
                       gUnk_09EEA1BC,
#endif
                       w->unk_794, 3);
        }
    }
    DrawSprite(w->x7 >> 8, w->y6 >> 8, w->gfx, w->tiles4, w->palette5, 0, 0x400, 40);
    TaskPoolDraw(&w->pool);
}

void Level_Up_3(u8* work) {
#ifdef VERSION_EU
    if (*(void**)&work[0x20] != 0) {
        ReleaseObjTiles(*(void**)&work[0x20]);
    }

    if (*(void**)&work[0x24] != 0) {
        ReleaseObjTiles(*(void**)&work[0x24]);
    }

    if (*(void**)&work[0x28] != 0) {
        ReleaseObjTiles(*(void**)&work[0x28]);
    }
#else
    FreeTextSlots(&work[0x20], 36);
    FreeTextSlots(&work[0x140], 36);
    FreeTextSlots(&work[0x260], 36);
    FreeTextSlots(&work[0x380], 36);
    FreeTextSlots(&work[0x4A0], 36);
    FreeTextSlots(&work[0x5C0], 36);
#endif

    if (*(void**)&work[0x18] != 0) {
        ReleaseObjTiles(*(void**)&work[0x18]);
    }

    if (*(void**)&work[0x1C] != 0) {
        ReleaseObjPalette(*(void**)&work[0x1C]);
    }

    if (*(void**)&work[0x00] != 0) {
        ReleaseObjTiles(*(void**)&work[0x00]);
    }

    if (*(void**)&work[0x04] != 0) {
        ReleaseObjTiles(*(void**)&work[0x04]);
    }

    if (*(void**)&work[0x08] != 0) {
        ReleaseObjTiles(*(void**)&work[0x08]);
    }

    if (*(void**)&work[0x10] != 0) {
        ReleaseObjPalette(*(void**)&work[0x10]);
    }

    if (*(void**)&work[0x14] != 0) {
        ReleaseObjPalette(*(void**)&work[0x14]);
    }

    if (*(void**)&work[offsetof(LevelUpWork, palette)] != 0) {
        ReleaseObjPalette(*(void**)&work[offsetof(LevelUpWork, palette)]);
    }

    if (*(void**)&work[offsetof(LevelUpWork, palette2)] != 0) {
        ReleaseObjPalette(*(void**)&work[offsetof(LevelUpWork, palette2)]);
    }

    if (*(void**)&work[offsetof(LevelUpWork, tiles)] != 0) {
        ReleaseObjTiles(*(void**)&work[offsetof(LevelUpWork, tiles)]);
    }

    if (*(void**)&work[offsetof(LevelUpWork, palette3)] != 0) {
        ReleaseObjPalette(*(void**)&work[offsetof(LevelUpWork, palette3)]);
    }

    if (*(void**)&work[offsetof(LevelUpWork, tiles2)] != 0) {
        ReleaseObjTiles(*(void**)&work[offsetof(LevelUpWork, tiles2)]);
    }

    if (*(void**)&work[offsetof(LevelUpWork, tiles3)] != 0) {
        ReleaseObjTiles(*(void**)&work[offsetof(LevelUpWork, tiles3)]);
    }

    if (*(void**)&work[offsetof(LevelUpWork, palette4)] != 0) {
        ReleaseObjPalette(*(void**)&work[offsetof(LevelUpWork, palette4)]);
    }

    if (*(void**)&work[offsetof(LevelUpWork, tiles4)] != 0) {
        ReleaseObjTiles(*(void**)&work[offsetof(LevelUpWork, tiles4)]);
    }

    if (*(void**)&work[offsetof(LevelUpWork, palette5)] != 0) {
        ReleaseObjPalette(*(void**)&work[offsetof(LevelUpWork, palette5)]);
    }

    TaskPoolDestroy(&work[offsetof(LevelUpWork, pool)]);
}
void func_080A0734(s16 x, s16 y, void* tiles, void* pal, void** gfx, u16* digits, u8 kind) {
    switch (kind) {
    case 0:
        DrawSprite(x + 8, y, gfx[digits[1]], tiles, pal, 0, 0, 0);
        x += 16;
        DrawSprite(x, y, gfx[digits[2]], tiles, pal, 0, 0, 0);
        break;
    case 1:
        DrawSprite(x, y, gfx[digits[0]], tiles, pal, 0, 0, 0);
        DrawSprite(x + 8, y, gfx[digits[1]], tiles, pal, 0, 0, 0);
        x += 16;
        DrawSprite(x, y, gfx[digits[2]], tiles, pal, 0, 0, 0);
        break;
    case 2:
        DrawSprite(x, y, gfx[digits[0]], tiles, pal, 0, 0, 0);
        DrawSprite(x + 8, y, gfx[digits[1]], tiles, pal, 0, 0, 0);
        DrawSprite(x + 16, y, gfx[digits[2]], tiles, pal, 0, 0, 0);
        x += 24;
        DrawSprite(x, y, gfx[digits[3]], tiles, pal, 0, 0, 0);
        break;
    case 4:
        DrawSprite(x + 8, y, gfx[digits[1]], tiles, pal, 0, 0, 0);
        x += 16;
        DrawSprite(x, y, gfx[digits[2]], tiles, pal, 0, 0, 0);
        break;
    case 3:
        DrawSprite(x, y, gfx[digits[0]], tiles, pal, 0, 0, 0);
        DrawSprite(x + 8, y, gfx[digits[1]], tiles, pal, 0, 0, 0);
        x += 16;
        DrawSprite(x, y, gfx[digits[2]], tiles, pal, 0, 0, 0);
        break;
    }
}

void func_080A0944(u16 a, u16* p) {
    u16 q;
    u16 r;

    q = a / 10;
    r = a - q * 10;
    p[1] = q;
    p[2] = r;
}

void func_080A096C(u16 a, u16* p) {
    u16 h;
    u16 t;
    u16 o;

    h = a / 100;
    t = a / 10 - h * 10;
    o = a - h * 100 - t * 10;
    p[0] = h;
    p[1] = t;
    p[2] = o;
}

void func_080A09C0(u16 n, u16* out) {
    u16 d3;
    u16 d2;
    u16 d1;
    u16 d0;

    d3 = n / 1000;
    d2 = n / 100 - d3 * 10;
    d1 = n / 10 - d2 * 10 - d3 * 100;
    d0 = n - d3 * 1000 - d2 * 100 - d1 * 10;
    out[0] = d3;
    out[1] = d2;
    out[2] = d1;
    out[3] = d0;
}

u8 func_080A0A44(LevelUpWork* w, void* a) {
#ifdef VERSION_EU
    enum { tileSize = 0xC80, mapSize = 0x500 };
#else
    enum { tileSize = 0xD80, mapSize = 0x800 };
#endif
    if (w->unk_7C2[0] == 0) {
        w->unk_7A4++;
        if (w->unk_7A4 > 7) {
#ifdef VERSION_EU
            w->tiles5[0] = AllocSpriteFrameTiles(0x500);
            w->tiles5[1] = AllocSpriteFrameTiles(0x500);
            w->tiles5[2] = AllocSpriteFrameTiles(0x500);
#endif
            if (!(gGameState.flags & 8)) {
                w->unk_000[0] = AllocSpriteFrameTiles(tileSize);
                w->unk_000[1] = AllocSpriteFrameTiles(tileSize);
                w->unk_000[2] = AllocSpriteFrameTiles(tileSize);
#ifdef VERSION_EU
                if (gLanguage != 3) {
#endif
                    UpdateSpriteFrameTiles(w->unk_000[0], gUnk_09EEA2BC[0], gUnk_090950F4);
                    UpdateSpriteFrameTiles(w->unk_000[1], gUnk_09EEA2BC[1], gUnk_090950F4);
                    UpdateSpriteFrameTiles(w->unk_000[2], gUnk_09EEA2BC[2], gUnk_090950F4);
#ifdef VERSION_EU
                } else {
                    UpdateSpriteFrameTiles(w->unk_000[0], gUnkEu_09F7626C[0], gUnkEu_09172200);
                    UpdateSpriteFrameTiles(w->unk_000[1], gUnkEu_09F7626C[1], gUnkEu_09172200);
                    UpdateSpriteFrameTiles(w->unk_000[2], gUnkEu_09F7626C[2], gUnkEu_09172200);
                }
#endif
                w->unk_000[4] = LoadObjPalette(gUnk_09613F18, 32);
                w->unk_000[5] = LoadObjPalette(gUnk_09613F38, 32);
            } else {
                w->unk_000[0] = AllocSpriteFrameTiles(tileSize);
                w->unk_000[1] = AllocSpriteFrameTiles(tileSize);
                w->unk_000[2] = AllocSpriteFrameTiles(tileSize);
#ifdef VERSION_EU
                if (gLanguage != 3) {
#endif
                    UpdateSpriteFrameTiles(w->unk_000[0], gUnk_09EEA29C[0], gUnk_09091D36);
                    UpdateSpriteFrameTiles(w->unk_000[1], gUnk_09EEA29C[1], gUnk_09091D36);
                    UpdateSpriteFrameTiles(w->unk_000[2], gUnk_09EEA29C[2], gUnk_09091D36);
#ifdef VERSION_EU
                } else {
                    UpdateSpriteFrameTiles(w->unk_000[0], gUnkEu_09F762A4[0], gUnkEu_091759BA);
                    UpdateSpriteFrameTiles(w->unk_000[1], gUnkEu_09F762A4[1], gUnkEu_091759BA);
                    UpdateSpriteFrameTiles(w->unk_000[2], gUnkEu_09F762A4[2], gUnkEu_091759BA);
                }
#endif
                w->unk_000[4] = LoadObjPalette(gUnk_09613EB8, 32);
                w->unk_000[5] = LoadObjPalette(gUnk_09613ED8, 32);
            }
#ifdef VERSION_EU
            switch (gLanguage) {
            case 0:
                w->tiles3 = LoadObjTiles(gUnk_0908C686, 0x3E0);
                break;
            case 1:
                w->tiles3 = LoadObjTiles(gUnkEu_0916F992, 0x3E0);
                break;
            case 2:
                w->tiles3 = LoadObjTiles(gUnkEu_0917063A, 0x3E0);
                break;
            case 3:
                w->tiles3 = LoadObjTiles(gUnkEu_09170202, 0x3E0);
                break;
            case 4:
                w->tiles3 = LoadObjTiles(gUnkEu_0916FDCA, 0x3E0);
                break;
            default:
                w->tiles3 = LoadObjTiles(gUnk_0908C686, 0x3E0);
                break;
            }
#else
            w->tiles3 = LoadObjTiles(gUnk_0908C686, 0x3E0);
#endif
            w->palette4 = LoadObjPalette(gUnk_09611AB8, 32);
            FadeSetPaletteExcluded(((ObjPalette*)w->unk_000[4])->index + 16, 1);
            FadeSetPaletteExcluded(((ObjPalette*)w->unk_000[5])->index + 16, 1);
            FadeSetPaletteExcluded(((ObjPalette*)w->palette4)->index + 16, 1);
            w->tiles = AllocObjTiles(0x3C0, 0);
            w->palette3 = LoadObjPalette(gUnk_09618CD8, 32);
            FadeSetPaletteExcluded(((ObjPalette*)w->palette3)->index + 16, 1);
            SetObjTileSource(w->tiles, gUnk_093F4578);
            AnimInit(&w->anim, gUnk_09EF1170, gUnk_09EF1150);
            AnimStart(&w->anim, 2, 1);
            w->gfx2 = AnimGetGfx(&w->anim);
            w->unk_7C2[0] = 1;
            w->unk_7A4 = 0;
            FadeToAmount(0, 8, 16);
        }
        return 1;
    }
    w->gfx = AnimUpdate(&w->anim2);
    {
        s32 x0 = w->x4[0] << 8;
        s32 x1 = w->x4[1] << 8;
        s32 x2 = w->x4[2] << 8;
        ApproachValue(&x0, 0x1000, w->unk_7B2[0]);
        if (w->unk_7B2[0] > 0) {
            w->unk_7B2[0]--;
        }
        if (w->unk_7B2[0] <= 6) {
            ApproachValue(&x1, 0x1000, w->unk_7B2[1]);
            if (w->unk_7B2[1] > 0) {
                w->unk_7B2[1]--;
            }
        }
        if (w->unk_7B2[1] <= 6) {
            ApproachValue(&x2, 0x1000, w->unk_7B2[2]);
            if (w->unk_7B2[2] > 0) {
                w->unk_7B2[2]--;
            }
        }
        w->x4[0] = x0 >> 8;
        w->x4[1] = x1 >> 8;
        w->x4[2] = x2 >> 8;
    }
    if (w->unk_7B2[2] == 0) {
        u8 i;
        if (gBtlWork->unk_10C == 151) {
            LoadBgMap(0, gUnk_095112B8, mapSize);
        } else {
            LoadBgMap(1, gUnk_095112B8, mapSize);
        }
        w->unk_7BD = 1;
        if (!(gGameState.flags & 8)) {
            if ((s16)gGameState.progression.maxHp > 559) {
#ifdef VERSION_EU
                UpdateSpriteFrameTiles(w->tiles5[0], gUnkEu_09F72D58[gLanguage][6], gUnkEu_09F72D44[gLanguage]);
#else
                w->unk_7B7[0] = LoadTextSlots(gUnk_09EE78D4[6], w->text[0]);
                w->unk_7B7[3] = 0;
#endif
                w->unk_7C8[0] = 0;
            } else {
#ifdef VERSION_EU
                UpdateSpriteFrameTiles(w->tiles5[0], gUnkEu_09F72D58[gLanguage][0], gUnkEu_09F72D44[gLanguage]);
#else
                w->unk_7B7[0] = LoadTextSlots(gUnk_09EE78D4[0], w->text[0]);
                w->unk_7B7[3] = LoadTextSlots(gUnk_09EE78D4[3], w->text[3]);
#endif
            }
            if (gGameState.progression.cp > 1899) {
#ifdef VERSION_EU
                UpdateSpriteFrameTiles(w->tiles5[1], gUnkEu_09F72D58[gLanguage][6], gUnkEu_09F72D44[gLanguage]);
#else
                w->unk_7B7[1] = LoadTextSlots(gUnk_09EE78D4[6], w->text[1]);
                w->unk_7B7[4] = 0;
#endif
                w->unk_7C8[1] = 0;
            } else {
#ifdef VERSION_EU
                UpdateSpriteFrameTiles(w->tiles5[1], gUnkEu_09F72D58[gLanguage][1], gUnkEu_09F72D44[gLanguage]);
#else
                w->unk_7B7[1] = LoadTextSlots(gUnk_09EE78D4[1], w->text[1]);
                w->unk_7B7[4] = LoadTextSlots(gUnk_09EE78D4[4], w->text[4]);
#endif
            }
            if (gGameState.progression.unk_80 > 10) {
#ifdef VERSION_EU
                UpdateSpriteFrameTiles(w->tiles5[2], gUnkEu_09F72D58[gLanguage][6], gUnkEu_09F72D44[gLanguage]);
#else
                w->unk_7B7[2] = LoadTextSlots(gUnk_09EE78D4[6], w->text[2]);
                w->unk_7B7[5] = 0;
#endif
                w->unk_7C8[2] = 0;
            } else if ((u8)func_080A2370() == 0) {
#ifdef VERSION_EU
                UpdateSpriteFrameTiles(w->tiles5[2], gUnkEu_09F72D58[gLanguage][6], gUnkEu_09F72D44[gLanguage]);
#else
                w->unk_7B7[2] = LoadTextSlots(gUnk_09EE78D4[6], w->text[2]);
                w->unk_7B7[5] = 0;
#endif
                w->unk_7C8[2] = 0;
            } else {
#ifdef VERSION_EU
                UpdateSpriteFrameTiles(w->tiles5[2], gUnkEu_09F72D58[gLanguage][2], gUnkEu_09F72D44[gLanguage]);
#else
                w->unk_7B7[2] = LoadTextSlots(gUnk_09EE78D4[2], w->text[2]);
                w->unk_7B7[5] = LoadTextSlots(gUnk_09EE78D4[5], w->text[5]);
#endif
            }
            w->palette = LoadObjPalette(gUnk_09613F98, 32);
            w->palette2 = LoadObjPalette(gUnk_09613FB8, 32);
        } else {
            if ((s16)gGameState.progression.maxHp > 559) {
#ifdef VERSION_EU
                UpdateSpriteFrameTiles(w->tiles5[0], gUnkEu_09F72D58[gLanguage][6], gUnkEu_09F72D44[gLanguage]);
#else
                w->unk_7B7[0] = LoadTextSlots(gUnk_09EE78F0[6], w->text[0]);
                w->unk_7B7[3] = 0;
#endif
                w->unk_7C8[0] = 0;
            } else {
#ifdef VERSION_EU
                UpdateSpriteFrameTiles(w->tiles5[0], gUnkEu_09F72D58[gLanguage][3], gUnkEu_09F72D44[gLanguage]);
#else
                w->unk_7B7[0] = LoadTextSlots(gUnk_09EE78F0[0], w->text[0]);
                w->unk_7B7[3] = LoadTextSlots(gUnk_09EE78F0[3], w->text[3]);
#endif
            }
            if ((s16)gGameState.progression.ap > 29) {
#ifdef VERSION_EU
                UpdateSpriteFrameTiles(w->tiles5[1], gUnkEu_09F72D58[gLanguage][6], gUnkEu_09F72D44[gLanguage]);
#else
                w->unk_7B7[1] = LoadTextSlots(gUnk_09EE78D4[6], w->text[1]);
                w->unk_7B7[4] = 0;
#endif
                w->unk_7C8[1] = 0;
            } else if ((u8)func_080A151C() == 0) {
#ifdef VERSION_EU
                UpdateSpriteFrameTiles(w->tiles5[1], gUnkEu_09F72D58[gLanguage][6], gUnkEu_09F72D44[gLanguage]);
#else
                w->unk_7B7[1] = LoadTextSlots(gUnk_09EE78D4[6], w->text[1]);
                w->unk_7B7[4] = 0;
#endif
                w->unk_7C8[1] = 0;
            } else {
#ifdef VERSION_EU
                UpdateSpriteFrameTiles(w->tiles5[1], gUnkEu_09F72D58[gLanguage][4], gUnkEu_09F72D44[gLanguage]);
#else
                w->unk_7B7[1] = LoadTextSlots(gUnk_09EE78F0[1], w->text[1]);
                w->unk_7B7[4] = LoadTextSlots(gUnk_09EE78F0[4], w->text[4]);
#endif
            }
            if ((s16)gGameState.progression.dp > 299) {
#ifdef VERSION_EU
                UpdateSpriteFrameTiles(w->tiles5[2], gUnkEu_09F72D58[gLanguage][6], gUnkEu_09F72D44[gLanguage]);
#else
                w->unk_7B7[2] = LoadTextSlots(gUnk_09EE78D4[6], w->text[2]);
                w->unk_7B7[5] = 0;
#endif
                w->unk_7C8[2] = 0;
            } else {
#ifdef VERSION_EU
                UpdateSpriteFrameTiles(w->tiles5[2], gUnkEu_09F72D58[gLanguage][5], gUnkEu_09F72D44[gLanguage]);
#else
                w->unk_7B7[2] = LoadTextSlots(gUnk_09EE78F0[2], w->text[2]);
                w->unk_7B7[5] = LoadTextSlots(gUnk_09EE78F0[5], w->text[5]);
#endif
            }
            w->palette = LoadObjPalette(gUnk_09613FD8, 32);
            w->palette2 = LoadObjPalette(gUnk_09613FF8, 32);
        }
        FadeSetPaletteExcluded(((ObjPalette*)w->palette)->index + 16, 1);
        FadeSetPaletteExcluded(((ObjPalette*)w->palette2)->index + 16, 1);
        for (i = 0; i < 3; i++) {
            if (w->unk_7C8[i] == 1) {
                break;
            }
        }
        w->unk_7B0 = i;
        w->y3 = gUnk_09037FB4[w->unk_7B0];
        SetTaskUpdate(a, (void*)func_0809F390);
        if (gBtlWork->unk_10C == 151) {
            LoadBgMap(0, gUnk_09EE7914[w->unk_7B0], 0x800);
        } else {
            LoadBgMap(1, gUnk_09EE7914[w->unk_7B0], 0x800);
        }
    }
    TaskPoolUpdate(&w->pool);
    return 1;
}

u8 func_080A11CC(LevelUpWork* w, void* a) {
    s32 x;
    s32 y;
    s8 n;

    x = w->x4[w->unk_7B0] << 8;
    y = w->x5[w->unk_7B0] << 8;
    ApproachValue(&x, -0x8000, w->unk_7B2[w->unk_7B0]);
    ApproachValue(&y, -0xF800, w->unk_7B2[w->unk_7B0]);
    w->x4[w->unk_7B0] = x >> 8;
    w->x5[w->unk_7B0] = y >> 8;
    w->unk_7B2[w->unk_7B0]--;

    if (w->unk_7B5 > 0) {
        w->unk_7B5--;
    }

    n = w->unk_7B5;

    if (n == 0) {
        if (w->unk_7BF != 0) {
            ApproachValue(&w->y, 0, w->unk_7BF);
            ApproachValue(&w->y2, 0x9800, w->unk_7BF);
            w->unk_7BF--;
        } else {
            if (w->unk_000[0] != 0) {
                ReleaseObjTiles(w->unk_000[0]);
            }

            if (w->unk_000[1] != 0) {
                ReleaseObjTiles(w->unk_000[1]);
            }

            if (w->unk_000[2] != 0) {
                ReleaseObjTiles(w->unk_000[2]);
            }
#ifdef VERSION_EU

            if (w->tiles5[0] != 0) {
                ReleaseObjTiles(w->tiles5[0]);
            }

            if (w->tiles5[1] != 0) {
                ReleaseObjTiles(w->tiles5[1]);
            }

            if (w->tiles5[2] != 0) {
                ReleaseObjTiles(w->tiles5[2]);
            }
#endif

            if (w->unk_000[4] != 0) {
                ReleaseObjPalette(w->unk_000[4]);
            }

            if (w->unk_000[5] != 0) {
                ReleaseObjPalette(w->unk_000[5]);
            }

            if (w->palette != 0) {
                ReleaseObjPalette(w->palette);
            }

            if (w->palette2 != 0) {
                ReleaseObjPalette(w->palette2);
            }

            if (w->tiles != 0) {
                ReleaseObjTiles(w->tiles);
            }

            if (w->palette3 != 0) {
                ReleaseObjPalette(w->palette3);
            }

            if (w->tiles3 != 0) {
                ReleaseObjTiles(w->tiles3);
            }

            if (w->palette4 != 0) {
                ReleaseObjPalette(w->palette4);
            }

            w->x4[0] = 0xFF80;
            w->x4[1] = 0xFF80;
            w->x4[2] = 0xFF80;
            w->y4[0] = 16;
            w->y4[1] = 64;
            w->y4[2] = 112;
            w->unk_7B5 = 24;
            w->unk_7B1 = 16;
            w->unk_7B2[0] = 16;
            w->unk_7B2[1] = 16;
            w->unk_7B2[2] = 16;
            w->x5[0] = 8;
            w->x5[1] = 8;
            w->x5[2] = 8;
            w->y5[0] = 31;
            w->y5[1] = 79;
            w->y5[2] = 127;
            w->x3 = 132;
            w->y3 = gUnk_09037FB4[0];

            if ((gGameState.flags & 8) == 0) {
                SetObjTileSource(w->tiles4, gUnk_088E33C2);
                AnimInit(&w->anim2, gUnk_09EDEE14, gUnk_09EDEE08);
                AnimStart(&w->anim2, 0, 1);
            } else {
                SetObjTileSource(w->tiles4, gUnk_0891ED26);
                AnimInit(&w->anim2, gUnk_09EDF38C, gUnk_09EDF374);
                AnimStart(&w->anim2, 0, 1);
            }

            w->unk_7C2[0] = 0;
            w->unk_7BD = 0;
            w->unk_7C5 = 0;
            w->unk_7A4 = 0;
            w->unk_7C7 = 0;
            SetTaskUpdate(a, (void*)func_080A0A44);
        }
    }

    w->unk_7C8[0] = 1;
    w->unk_7C8[1] = 1;
    w->unk_7C8[2] = 1;
    w->gfx = AnimUpdate(&w->anim2);
    TaskPoolUpdate(&w->pool);
    return 1;
}

s32 func_080A151C(void) {
    if (gGameState.progression.level >= gUnk_09037FBA[gGameState.progression.unk_80]) {
        return 1;
    }

    return 0;
}

void func_080A1554(u8* work) {
    s16 x;
    s16 y;
    s32* t;

    t = *(s32**)&work[0x0C];

    if (t != 0) {
        WorldToScreen(&x, &y, t[1], t[2], t[3]);
        *(s32*)&work[0x64] = x;
        *(s32*)&work[0x68] = y - 16;
    }
}
void LVUP_EFFECT_0(LevelUpEffectWork* w, LevelUpEffectArgs* a) {
    s32 i;
    LevelUpEffectArgs args;

    w->unk_0C = a->unk_0C;
    w->unk_64 = a->x;
    w->unk_68 = a->y;
    w->unk_30 = 30;
    w->unk_97 = a->unk_08;
    func_080A1554((u8*)w);
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
    w->palette = LoadObjPalette(gUnk_09611AB8, 32);

    for (i = 0; i < 4; i++) {
        w->unk_10[i] = (w->unk_64 << 8) + gUnk_09037FFC[i];
        w->unk_20[i] = (w->unk_68 << 8) + gUnk_0903800C[i];
        w->angle[i] = gUnk_0903801C[i];
        w->x[i] = w->unk_30 * gSineTable[w->angle[i] & 0xFF] + w->unk_10[i];
        w->y[i] = -gSineTable[(w->angle[i] & 0xFF) + 64] * w->unk_30 + w->unk_20[i];
        w->unk_54[i] = 0;
    }

    w->unk_94 = 0;
    w->unk_95 = 0;
    w->unk_96 = 24;
    TaskPoolInit(w->tasks, 4);

    if (w->unk_0C != 0 && gUnk_02034AF8 == 0) {
        args.x = w->x[0];
        args.y = w->y[0];
        args.unk_0C = w->unk_0C;
        args.unk_10 = w->tiles;
        args.unk_14 = w->palette;
        TaskCreate(w->tasks, &gTaskDescLvupLogo, &args);
        gUnk_02034AF8 = 1;
    }
}
u8 LVUP_EFFECT_1(LevelUpEffectWork* w, void* a) {
    s32 i;

    func_080A1554((u8*)w);

    if ((s8)w->unk_96 > 0) {
        for (i = 0; i < 4; i++) {
            ApproachValue(&w->unk_10[i], w->unk_64 << 8, (s8)w->unk_96);
            ApproachValue(&w->unk_20[i], w->unk_68 << 8, (s8)w->unk_96);
        }

        w->unk_96--;
    } else {
        for (i = 0; i < 4; i++) {
            w->angle[i] += 6;
            w->unk_10[i] = w->unk_64 << 8;
            w->unk_20[i] = w->unk_68 << 8;
        }

        if ((s16)w->angle[0] > 0x100) {
            w->unk_30--;
        }
    }

    for (i = 0; i < 4; i++) {
        w->x[i] = gSineTable[w->angle[i] & 0xFF] * w->unk_30 + w->unk_10[i];
        w->y[i] = -gSineTable[(w->angle[i] & 0xFF) + 64] * w->unk_30 + w->unk_20[i];
    }

    w->unk_95++;
    TaskPoolUpdate(&w->tasks);

    if (w->unk_30 == 0) {
        for (i = 0; i < 4; i++) {
            switch (i) {
            case 0:
                w->unk_7C[0] = 0x300;
                w->unk_6C[0] = -0x180;
                w->angle[0] = 8;
                break;
            case 1:
                w->unk_7C[1] = 0x300;
                w->unk_6C[1] = -0x180;
                w->angle[1] = -8;
                break;
            case 2:
                w->unk_7C[2] = 0x300;
                w->unk_6C[2] = -0x180;
                w->angle[2] = 16;
                break;
            case 3:
                w->unk_7C[3] = 0x300;
                w->unk_6C[3] = -0x180;
                w->angle[3] = -16;
                break;
            }
        }

        w->unk_94 = 1;
        SetTaskUpdate(a, (void*)func_080A18F4);
    }

    return 1;
}
u8 func_080A18F4(LevelUpEffectWork* w) {
    s32 i;

    for (i = 0; i < 4; i++) {
        w->unk_6C[i] += 25;
        w->y[i] += w->unk_6C[i];
        w->x[i] += gSineTable[(u8)w->angle[i]] * (w->unk_7C[i] >> 8);
    }

    w->unk_95++;

    if (w->unk_95 % 8 == 0 && (s8)w->unk_95 > 1) {
        w->unk_94++;
    }

    TaskPoolUpdate(&w->tasks);

    if (w->y[0] > 0xA000) {
        return 0;
    }

    return 1;
}

void LVUP_EFFECT_2(LevelUpEffectWork* w) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (w->unk_94 <= 5) {
#ifdef VERSION_EU
            DrawSprite(w->x[i] >> 8, w->y[i] >> 8, gUnkEu_09F72E10[gLanguage][w->unk_94], w->tiles, w->palette, 0, 0, 20);
#else
            DrawSprite(w->x[i] >> 8, w->y[i] >> 8, gUnk_09EE7938[w->unk_94], w->tiles, w->palette, 0, 0, 20);
#endif
        }
    }

    TaskPoolDraw(w->tasks);
}

void LVUP_EFFECT_3(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjPalette(*(void**)&work[0x04]);
    TaskPoolDestroy(&work[0x98]);

    if (gBtlWork->flags & 0x20000) {
        gBtlWork->flags &= ~0x20000;
    }
}

#ifdef VERSION_EU
void* gUnkEu_09F72D08[5] = { gUnkEu_094CF704, gUnkEu_094D72E4, gUnkEu_094DB664, gUnkEu_094D9FE4, gUnkEu_094D8964 };

void* gUnkEu_09F72D1C[5] = { gUnk_0908CAEC, gUnkEu_09170AA0, gUnkEu_09171B2C, gUnkEu_091715A8, gUnkEu_09171024 };

void** gUnk_09EEA1BC[5] = {
    gUnkEu_09F75FF4,
    gUnkEu_09F761AC,
    gUnkEu_09F7623C,
    gUnkEu_09F7620C,
    gUnkEu_09F761DC,
};

void* gUnkEu_09F72D44[5] = {
    gUnkEu_09178D40,
    gUnkEu_09179CEE,
    gUnkEu_0917CFE2,
    gUnkEu_0917BFA6,
    gUnkEu_0917AF3A,
};

void** gUnkEu_09F72D58[5] = {
    gUnkEu_09F762C4,
    gUnkEu_09F762E4,
    gUnkEu_09F76344,
    gUnkEu_09F76324,
    gUnkEu_09F76304,
};
#endif
#ifndef VERSION_EU
u16* gUnk_09EE78D4[7] = { gUnk_0815A066, gUnk_0815A0BA, gUnk_0815B1D2, gUnk_0815A078, gUnk_0815A0CC, gUnk_0815B1A8, gUnk_09037FAC };

u16* gUnk_09EE78F0[7] = { gUnk_0815A066, gUnk_0815A116, gUnk_0815A158, gUnk_0815A0F4, gUnk_0815A130, gUnk_0815A176, gUnk_09037FAC };
#endif

const void* gUnk_09EE790C[2] = { gUnk_08125E24, gUnk_0950F2B8 };

void* gUnk_09EE7914[3] = { gUnk_095112B8, gUnk_09511AB8, gUnk_095122B8 };

const char gTaskNameLevelUp[] = "Level_Up";

TaskDesc gTaskDescLevelUp = {
    gTaskNameLevelUp,
    (void (*)(void*, void*))Level_Up_0,
    Level_Up_1,
    (void (*)(void*))Level_Up_2,
    (void (*)(void*))Level_Up_3,
#ifdef VERSION_EU
    0x124,
#else
    0x7CC,
#endif
};
#ifdef VERSION_EU
void* gUnk_09EE7938[6] = { gUnkEu_09163774, gUnkEu_0916377E, gUnkEu_09163788, gUnkEu_09163792, gUnkEu_0916379C, gUnkEu_091637A6 };

void* gUnkEu_09F72DB0[6] = { gUnkEu_0916F94C, gUnkEu_0916F956, gUnkEu_0916F960, gUnkEu_0916F96A, gUnkEu_0916F974, gUnkEu_0916F97E };

void* gUnkEu_09F72DC8[6] = { gUnkEu_0916FD84, gUnkEu_0916FD8E, gUnkEu_0916FD98, gUnkEu_0916FDA2, gUnkEu_0916FDAC, gUnkEu_0916FDB6 };

void* gUnkEu_09F72DE0[6] = { gUnkEu_091701BC, gUnkEu_091701C6, gUnkEu_091701D0, gUnkEu_091701DA, gUnkEu_091701E4, gUnkEu_091701EE };

void* gUnkEu_09F72DF8[6] = { gUnkEu_091705F4, gUnkEu_091705FE, gUnkEu_09170608, gUnkEu_09170612, gUnkEu_0917061C, gUnkEu_09170626 };

void** gUnkEu_09F72E10[5] = { gUnk_09EE7938, gUnkEu_09F72DB0, gUnkEu_09F72DF8, gUnkEu_09F72DE0, gUnkEu_09F72DC8 };
#elif defined(VERSION_JP)
void* gUnk_09EE7938[6] = { gUnkJp_09047EB0, gUnkJp_09047EBA, gUnkJp_09047EC4, gUnkJp_09047ECE, gUnkJp_09047ED8, gUnkJp_09047EE2 };
#else
void* gUnk_09EE7938[6] = { gUnkUs_0908C640, gUnkUs_0908C64A, gUnkUs_0908C654, gUnkUs_0908C65E, gUnkUs_0908C668, gUnkUs_0908C672 };
#endif

const char gTaskNameLVUPEFFECT[] = "LVUP_EFFECT";

TaskDesc gTaskDescLVUPEFFECT = {
    gTaskNameLVUPEFFECT,
    (void (*)(void*, void*))LVUP_EFFECT_0,
    LVUP_EFFECT_1,
    (void (*)(void*))LVUP_EFFECT_2,
    (void (*)(void*))LVUP_EFFECT_3,
    0xAC,
};
