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
#include "sprites_deck_menu.h"
#include "sprites_card_pictures.h"

#ifdef VERSION_EU
extern void* gUnkEu_09F7434C[];
extern u16 gUnkEu_090D1DF4[];
extern u8* gUnkEu_09F74374[];
extern s16 gUnkEu_090D1DFE[];
extern s16 gUnkEu_090D1E04[];

#define LANGSTR(x) (((void**)(x))[gLanguage])
#else
#define LANGSTR(x) (x)
#endif
u16 func_080857D4(u8 slot);
void func_080A6F60(void** p);
void func_080A7180(u8 a);
void func_080A6EB4(u8* work, s32 id);
void func_080A5C60(u8* work, u16 card);
void func_08090170(DeckCard2Work* node);
void func_080A6FAC(UnkStruct_080A6FAC* w);
u8 func_080A5FF4(u8* work, void* a);
s32 func_080A6388(u8* work);
u8 func_080A7300(u8* work);
u8 func_080A734C(u8* work);
DeckCard2Work* func_080A6AE8(u8* work);
u8 func_080A5D3C(UnkStruct_080A5D3C* w, void* a);
void func_080A6968(u8* work);
void func_080A7264(void** p);
void func_080A7210(u8* work);
u16 CountCollectionCards(void);
u16 CountCardsInDecks(void);
Deck* GetDeck(u8 index);
u16 GetDeckCpCost(u8 index);
u8* GetDeckName(u8 index);
u16 func_080857D4(u8 slot);
u16 GetDeckCardCount(u8 index);
u8 GetActiveDeckIndex(void);
void func_08090170(DeckCard2Work* node);

void func_080A584C(u8* work, void* a) {
    u16 v;

    *(void**)&work[0x4F4] = a;
    SetBgMode0();
    SetBackdropColor(0, 0, 0);
    SetupBg(0, 0, 31, 0);
#ifdef VERSION_EU
    SetupBg(1, 0, 29, 0);
    SetupBg(2, 0, 28, 0);
#else
    SetupBg(1, 2, 23, 0);
    SetupBg(2, 1, 15, 0);
#endif
    SetupBg(3, 0, 30, 0);
    RequestDma3Clear(GetBgCharBase(0), 0x4000);
    RequestDma3Clear(GetBgCharBase(1), 0x4000);
    RequestDma3Clear(GetBgCharBase(2), 0x4000);
    RequestDma3Clear(GetBgCharBase(3), 0x4000);
    SetBgPriority(0, 0);
    SetBgPriority(1, 1);
    SetBgPriority(2, 2);
    FadeStartIn(0, 16);
    ListPoolInit(&work[0x434]);
    TaskPoolInit((TaskPool*)&work[0x40C], 99);
    TaskPoolInit((TaskPool*)&work[0x420], 1);
    ((UnkStruct_080A5D3C*)work)->unk_4F8 = GetActiveDeckIndex();
    func_080A6838(work, 0);
    *(void**)&work[0] = AllocObjTiles(0x120, 0);
    SetObjTileSource(*(void**)&work[0], gUnk_090A4664);
    AnimInit((AnimState*)&work[0x444], gUnk_09EEB03C, gUnk_09EEB008);
    AnimStart((AnimState*)&work[0x444], 0, 1);
    *(void**)&work[0x400] = AnimGetGfx((AnimState*)&work[0x444]);
    *(s32*)&work[0x48C] = gUnk_09041EB4[0] << 8;
    *(s32*)&work[0x490] = gUnk_09041EBA[0] << 8;
    *(u16*)&work[0x4C6] = 0;
    *(void**)&work[0x10] = LoadObjTiles(gUnk_090A44C4, 32);
    *(void**)&work[0x14] = LoadObjPalette(gUnk_09614418, 32);
    work[0x50A] = 0;
    *(void**)&work[0x04] = AllocObjTiles(0x280, 0);
    func_080A7284(work, 0);
    *(void**)&work[0x3D8] = LoadObjPalette(gUnk_09614438, 32);
    *(s32*)&work[0x24] = 0;
    *(s32*)&work[0x18] = 0;
    *(s32*)&work[0x1C] = 0;
    *(s32*)&work[0x20] = 0;
    *(s32*)&work[0x28] = 0;
    *(s32*)&work[0x2C] = 0;
    *(s32*)&work[0x08] = 0;
    *(s32*)&work[0x0C] = 0;
    *(u16*)&work[0x4C8] = 0;
    *(u16*)&work[0x4CA] = 0;
    work[0x4E8] = 0;
    work[0x4E9] = 0;
    work[0x4EC] = 4;
    work[0x500] = 0;
    *(s32*)&work[0x3DC] = 0;
    *(s32*)&work[0x3E0] = 0;
    work[0x4FF] = 0;
    work[0x4E6] = 0;
    work[0x4EF] = func_080857D4(0);
    work[0x4F0] = func_080857D4(1);
    work[0x4F1] = func_080857D4(2);
    work[0x4F2] = func_080857D4(3);
    work[0x4F9] = 0;
    *(u16*)&work[0x4DC] = 0;
    *(s32*)&work[0x3E8] = 0;
    work[0x501] = 0;
    work[0x504] = 0;
    work[0x505] = 16;
    work[0x506] = 16;
    *(s32*)&work[0x49C] = 0x7800;
    *(s32*)&work[0x4A4] = -0x800;
    *(s32*)&work[0x4A0] = 0xA400;
    *(s32*)&work[0x4A8] = 0xA000;
    *(s32*)&work[0x4AC] = -0x8000;
    work[0x508] = 0;
#ifdef VERSION_EU
    *(void**)&work[0x3CC] = LoadObjTiles(gUnkEu_09F7434C[gLanguage], gUnkEu_090D1DF4[gLanguage]);
#else
    *(void**)&work[0x3CC] = LoadObjTiles(gUnk_090A418E, 0x320);
#endif
    *(void**)&work[0x3C4] = LoadObjTiles(gUnk_090A583E, 0x620);
    *(void**)&work[0x3C8] = LoadObjPalette(gUnk_096144F8, 32);
    *(u16*)&work[0x4BC] = 79;
    v = gUnk_09041EEE[((UnkStruct_080A5D3C*)work)->unk_4F8];
    *(u16*)&work[0x4BE] = v;
    *(u16*)&work[0x4C0] = 225;
    v = gUnk_09041EEE[((UnkStruct_080A5D3C*)work)->unk_4F8];
    *(u16*)&work[0x4C2] = v;
    work[0x503] = 0;
    work[0x507] = 0;
    work[0x4FA] = 0;
    work[0x4FB] = 0;
    work[0x4FC] = 0;
    work[0x4FD] = 0;
    work[0x50C] = 0;
    InitTextSlots(&work[0x30], 8);
    InitTextSlots(&work[0x70], 8);
    InitTextSlots(&work[0xB0], 8);
    InitTextSlots(&work[0xF0], 30);
    InitTextSlots(&work[0x1E0], 60);
    *(u16*)&work[0x4D8] = 94;
    *(u16*)&work[0x4DA] = 126;
    work[0x50B] = 0;
}

void func_080A5C20(u8* work) {
    DrawTextSlots(*(s16*)&work[0x4D8], *(s16*)&work[0x4DA], &work[0x1E0],
                  *(void**)&work[0x14], 20, work[0x4FE]);
}

void func_080A5C60(u8* work, u16 card) {
    CardDef* d;
    void* s;

    d = &gCardDefs[card];
    s = gUnk_09EE8F48[d->unk_1C];
    work[0x4FE] = LoadTextSlots(LANGSTR(s), &work[0x1E0]);
}

u8 func_080A5C9C(u8* work, void* a) {
#ifdef VERSION_EU
    LoadBgTiles(3, gUnk_09402F78, 0x5400);

    switch (gLanguage) {
    case 1:
        RequestDma3Copy(gUnkEu_094E20E4, (u8*)GetBgCharBase(3) + 0x3800, 0x1C00);
        break;
    case 2:
        RequestDma3Copy(gUnkEu_094E74E4, (u8*)GetBgCharBase(3) + 0x3800, 0x1C00);
        break;
    case 3:
        RequestDma3Copy(gUnkEu_094E58E4, (u8*)GetBgCharBase(3) + 0x3800, 0x1C00);
        break;
    case 4:
        RequestDma3Copy(gUnkEu_094E3CE4, (u8*)GetBgCharBase(3) + 0x3800, 0x1C00);
        break;
    }

    LoadBgPalette(3, gUnk_09614118, 0x1E0);
    LoadBgMap(3, gUnk_0951B2B8, 0x800);
    LoadBgMap(0, gUnk_08125E24, 0x800);
    LoadBgMap(1, gUnk_08125E24, 0x800);
    LoadBgMap(2, gUnk_08125E24, 0x800);
#else
    LoadBgTiles(3, gUnk_09402F78, 0x4000);
    LoadBgPalette(3, gUnk_09614118, 0x1E0);
    LoadBgMap(3, gUnk_0951B2B8, 0x800);
    LoadBgMap(0, gUnk_08125E24, 0x800);
    LoadBgTiles(1, gUnk_09406F78, 0xC00);
    LoadBgMap(1, gUnk_08125E24, 0x800);
    LoadBgMap(2, gUnk_08125E24, 0x800);
#endif
    SetBgScroll(0, (u16)-88, (u16)-108);
    SetBgScroll(1, (u16)-88, (u16)-16);
    SetTaskUpdate(a, (void*)func_080A5D3C);
    return 1;
}

u8 func_080A5D3C(UnkStruct_080A5D3C* w, void* a) {
    u8* base;
    u16* pal;

    base = (u8*)GetBgCharBase(1);
    pal = (u16*)0x05000100;
    LoadPalette(gUnk_09614118 + 0x1E0, pal, 32);
#ifdef VERSION_EU
    RequestDma3Copy(gUnkEu_09F74374[gLanguage] + 0x20, base + 0x2D80, 0x1E0);
    LoadBgMap(0, gUnk_095172B8, 0x800);
    LoadBgMap(1, gUnk_09516AB8, 0x800);
#else
    RequestDma3Copy(gUnk_0940FC58, base + 0x1A0, 0x1E0);
    LoadBgMap(0, gUnk_09516AB8 + 0x800, 0x800);
    LoadBgMap(1, gUnk_0951B2B8 + 0x800, 0x800);
#endif
    func_080A6B40(w->unk_4EF, 0);
    func_080A6B40(w->unk_4F0, 1);
    func_080A6B40(w->unk_4F1, 2);
    func_080A6B40(w->unk_4F2, 3);
    func_080A6C50(0);
    func_080A6D0C();
    w->unk_494 = 0x4800;
    w->unk_498 = 0x2800;
    w->unk_4C8[1] = w->unk_4F8;
#ifdef VERSION_EU
    ApproachValue(&w->unk_48C, gUnkEu_090D1DFE[w->unk_4C8[0]] << 8, w->unk_4EC);
    ApproachValue(&w->unk_490, gUnkEu_090D1E04[w->unk_4C8[1]] << 8, w->unk_4EC);
#else
    ApproachValue(&w->unk_48C, gUnk_09041EB4[w->unk_4C8[0]] << 8, w->unk_4EC);
    ApproachValue(&w->unk_490, gUnk_09041EBA[w->unk_4C8[1]] << 8, w->unk_4EC);
#endif
    w->unk_4E6 = 1;
    func_080A6BB4((u8*)w);
    func_080A6E3C((u8*)w);
    w->unk_509 = 0;
    w->unk_4EC = 16;
    SetTaskUpdate(a, func_080A5EA0);
    return 1;
}

u8 func_080A5EA0(UnkStruct_080A5D3C* w, void* a) {
    u8 n;

    if (FadeIsActive() == 0) {
        switch (w->unk_509) {
        case 0:
            ApproachValue(&w->unk_4A4, 0, w->unk_4EC);
            ApproachValue(&w->unk_4A8, 0x9800, w->unk_4EC);
            w->unk_4EC--;

            if (w->unk_4EC == 0) {
                w->unk_4EC = 16;
                w->unk_509++;
            }
            break;
        case 1:
            ApproachValue(&w->unk_4AC, 0, w->unk_4EC);
            n = --w->unk_4EC;

            if (n == 0) {
                LoadBgMap(3, gUnk_095162B8, 0x800);
                ReleaseObjTiles(w->tiles2);
                w->tiles2 = 0;
                ReleaseObjTiles(w->tiles);
                w->tiles = 0;
                ReleaseObjPalette(w->palette);
                w->palette = 0;
                SetTaskUpdate(a, (void*)func_080A5F70);
            }
            break;
        }
    }

    return 1;
}

u8 func_080A5F70(u8* work, void* a) {
    *(s32*)&work[0x48C] = gUnk_09035950[*(s16*)&work[0x4C8]] << 8;
    *(s32*)&work[0x490] = gUnk_09035956[*(s16*)&work[0x4CA]] << 8;
    work[0x4E6] = 0;
    func_080A6BB4(work);
    func_080A6FAC((UnkStruct_080A6FAC*)work);
    work[0x50A] = 1;
    SetTaskUpdate(a, (void*)func_080A5FF4);
    return 1;
}

u8 func_080A5FF4(u8* work, void* a) {
    u16 x;

    *(void**)&work[0x400] = AnimUpdate((AnimState*)&work[0x444]);
    *(void**)&work[0x404] = AnimUpdate((AnimState*)&work[0x45C]);

    if (FadeIsActive() != 0) {
        TaskPoolUpdate((TaskPool*)&work[0x40C]);
        return 1;
    }

    if (work[0x501] != 0) {
        ApproachValue((s32*)&work[0x48C], gUnk_09035950[*(s16*)&work[0x4C8]] << 8, work[0x4EC]);
        ApproachValue((s32*)&work[0x490], gUnk_09035956[*(s16*)&work[0x4CA]] << 8, work[0x4EC]);

        if (work[0x4EC] != 0) {
            work[0x4EC]--;
        }

        TaskPoolUpdate((TaskPool*)&work[0x40C]);
        TaskPoolUpdate((TaskPool*)&work[0x420]);

        if (GetKeysPressed() & START_BUTTON) {
            work[0x504] = 1;
        }
        work[0x507] = 4;
        return 1;
    }

    if (*(s8*)&work[0x507] > 0) {
        TaskPoolUpdate((TaskPool*)&work[0x40C]);
        TaskPoolUpdate((TaskPool*)&work[0x420]);
        work[0x507]--;
        return 1;
    }

    if (work[0x504] != 0) {
        if (func_080A7300(work) != 0 && func_080A734C(work) != 0) {
            SetTaskUpdate(a, (void*)func_080A6388);
            FadeStartOut(0, 4);
            m4aSongNumStart(103);
            return 1;
        }
        work[0x504] = 0;
    }

    switch (GetKeysRepeat()) {
    case DPAD_UP:
        if (*(s16*)&work[0x4CA] > 0) {
            (*(s16*)&work[0x4CA])--;
            work[0x4EC] = 4;
            m4aSongNumStart(121);
        } else {
            func_080A6A38(work);
        }
        func_080A6FAC((UnkStruct_080A6FAC*)work);
        break;
    case DPAD_DOWN:
        if (*(s16*)&work[0x4CA] <= 2) {
            (*(s16*)&work[0x4CA])++;
            work[0x4EC] = 4;
            m4aSongNumStart(121);
        } else {
            func_080A69A0(work);

            if (work[0x508] != 0) {
                if (*(u16*)&work[0x4BA] <= 3) {
                    *(s32*)&work[0x4B4] = gUnk_09035956[*(s16*)&work[0x4BA]] << 8;
                } else {
                    *(s32*)&work[0x4B4] = 0xFFFF0000;
                }
            }
        }
        func_080A6FAC((UnkStruct_080A6FAC*)work);
        break;
    case DPAD_LEFT:
        if (*(s16*)&work[0x4C8] > 0) {
            (*(s16*)&work[0x4C8])--;
            work[0x4EC] = 4;
            m4aSongNumStart(121);
        }
        func_080A6FAC((UnkStruct_080A6FAC*)work);
        break;
    case DPAD_RIGHT:
        if (*(s16*)&work[0x4C8] <= 1) {
            (*(s16*)&work[0x4C8])++;
            work[0x4EC] = 4;
            m4aSongNumStart(121);
        }
        func_080A6FAC((UnkStruct_080A6FAC*)work);
        break;
    case START_BUTTON:
        work[0x50C] = 7;
        m4aSongNumStart(103);
        FadeStartOut(0, 4);
        SetTaskUpdate(a, (void*)func_080A6388);
        return 1;
    case B_BUTTON:
        work[0x50C] = 8;
        m4aSongNumStart(103);
        SetTaskUpdate(a, (void*)func_080A63B8);
        return 1;
    }

    *(s32*)&work[0x3DC] = (s32)func_080A6AE8(work);
    ApproachValue((s32*)&work[0x48C], gUnk_09035950[*(s16*)&work[0x4C8]] << 8, work[0x4EC]);
    ApproachValue((s32*)&work[0x490], gUnk_09035956[*(s16*)&work[0x4CA]] << 8, work[0x4EC]);

    if (work[0x4EC] != 0) {
        work[0x4EC]--;
    }

    *(s32*)&work[0x3E0] = *(s32*)&work[0x3DC];
    x = *(u16*)&work[0x4C8];
    work[0x4E8] = x;
    x = *(u16*)&work[0x4CA];
    work[0x4E9] = x;
    TaskPoolUpdate((TaskPool*)&work[0x40C]);
    TaskPoolUpdate((TaskPool*)&work[0x420]);
    return 1;
}

s32 func_080A6388(u8* work) {
    if (FadeIsActive() == 0) {
        return 0;
    }

    TaskPoolUpdate(&work[0x40C]);
    TaskPoolUpdate(&work[0x420]);
    return 1;
}

u8 func_080A63B8(u8* work, void* a) {
#ifdef VERSION_EU
    *(void**)&work[0x3CC] = LoadObjTiles(gUnkEu_09F7434C[gLanguage], gUnkEu_090D1DF4[gLanguage]);
#else
    *(void**)&work[0x3CC] = LoadObjTiles(gUnk_090A418E, 0x320);
#endif
    *(void**)&work[0x3C4] = LoadObjTiles(gUnk_090A583E, 0x620);
    *(void**)&work[0x3C8] = LoadObjPalette(gUnk_096144F8, 32);
    LoadBgMap(3, gUnk_0951B2B8, 0x800);
    *(s32*)&work[0x49C] = 0x7800;
    *(s32*)&work[0x4A4] = 0;
    *(s32*)&work[0x4A0] = 0xA400;
    *(s32*)&work[0x4A8] = 0x9800;
    *(s32*)&work[0x4AC] = 0;
    work[0x505] = 16;
    work[0x506] = 16;
    work[0x50A] = 0;
    SetTaskUpdate(a, (void*)func_080A6474);
    return 1;
}

u8 func_080A6474(u8* work, void* a) {
    u8* p;

    p = &work[0x506];

    if ((s8)*p > 0) {
        ApproachValue(&work[0x4AC], -0x8000, (u16)(s8)*p);
        (*p)--;
    } else {
        p = &work[0x505];

        if ((s8)*p > 0) {
            ApproachValue(&work[0x4A4], -0x800, (u16)(s8)*p);
            ApproachValue(&work[0x4A8], 0xA000, (u16)(s8)*p);
            (*p)--;
        } else {
            FadeStartOut(0, 4);
            SetTaskUpdate(a, (void*)func_080A6388);
        }
    }

    return 1;
}

void func_080A6500(u8* work) {
    if (*(void**)&work[0x3CC] != 0) {
#ifdef VERSION_EU
        DrawSprite(*(s32*)&work[0x4AC] >> 8, 0, gUnkEu_09F74360[gLanguage][0], *(void**)&work[0x3CC], *(void**)&work[0x3C8], 0, 0, 10);
#elif defined(VERSION_JP)
        DrawSprite(*(s32*)&work[0x4AC] >> 8, 0, gUnk_09EEAFF0, *(void**)&work[0x3CC], *(void**)&work[0x3C8], 0, 0, 10);
#else
        DrawSprite(*(s32*)&work[0x4AC] >> 8, 0, gUnk_09EEAFF8, *(void**)&work[0x3CC], *(void**)&work[0x3C8], 0, 0, 10);
#endif
    }

    if (*(void**)&work[0x3C4] != 0) {
        DrawSprite(*(s32*)&work[0x49C] >> 8, *(s32*)&work[0x4A4] >> 8, gUnk_09EEB080[0], *(void**)&work[0x3C4],
                   *(void**)&work[0x3C8], 0, 0xC00, 10000);
        DrawSprite(*(s32*)&work[0x4A0] >> 8, *(s32*)&work[0x4A8] >> 8, gUnk_09EEB080[1], *(void**)&work[0x3C4],
                   *(void**)&work[0x3C8], 0, 0xC00, 10000);
    }

    if (work[0x50A] != 0) {
        DrawSprite((*(s32*)&work[0x48C] >> 8) - 16, (*(s32*)&work[0x490] >> 8) - 30, *(void**)&work[0x400],
                   *(void**)&work[0x0], *(void**)&work[0x14], 0, *(u16*)&work[0x4C6], 3);
        DrawSprite((*(s32*)&work[0x48C] >> 8) - 16, (*(s32*)&work[0x490] >> 8) - 20, *(void**)&work[0x404],
                   *(void**)&work[0x4], *(void**)&work[0x3D8], 0, 0, 8);
    }

    DrawSprite(*(s32*)&work[0x494] >> 8, *(s32*)&work[0x498] >> 8, gUnk_09EEB000, *(void**)&work[0x10],
               *(void**)&work[0x14], 0, 0x800, 10);

    if (*(void**)&work[0x18] != 0) {
        DrawSprite(168, 86, *(void**)&work[0x3EC], *(void**)&work[0x18], *(void**)&work[0x28], 0, 0, 20);
    }

    if (*(void**)&work[0x1C] != 0) {
        DrawSprite(168, 86, *(void**)&work[0x3F0], *(void**)&work[0x1C], *(void**)&work[0x2C], 0, 0, 21);
    }

    if (*(void**)&work[0x20] != 0) {
        DrawSprite(168, 86, *(void**)&work[0x3F4], *(void**)&work[0x20], *(void**)&work[0x28], 0, 0, 19);
    }

    if (work[0x50B] != 0) {
        if (work[0x4FD] != 0) {
            DrawTextSlots(100, 112, &work[0xF0], *(void**)&work[0x3D8], 20, work[0x4FD]);
        }

        func_080A5C20(work);
    }

    TaskPoolDraw(&work[0x40C]);
    TaskPoolDraw(&work[0x420]);
}

void func_080A676C(u8* work) {
    func_080A6968(work);
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjTiles(*(void**)&work[0x04]);
    ReleaseObjTiles(*(void**)&work[0x10]);
    ReleaseObjPalette(*(void**)&work[0x14]);
    func_080A7264((void**)work);

    if (*(void**)&work[0x3CC] != 0) {
        ReleaseObjTiles(*(void**)&work[0x3CC]);
    }

    if (*(void**)&work[0x3C4] != 0) {
        ReleaseObjTiles(*(void**)&work[0x3C4]);
    }

    if (*(void**)&work[0x3C8] != 0) {
        ReleaseObjPalette(*(void**)&work[0x3C8]);
    }

    FreeTextSlots(&work[0x30], 8);
    FreeTextSlots(&work[0x70], 8);
    FreeTextSlots(&work[0xB0], 8);
    FreeTextSlots(&work[0xF0], 30);
    FreeTextSlots(&work[0x1E0], 60);
    ReleaseObjPalette(*(void**)&work[0x3D8]);
    TaskPoolDestroy(&work[0x40C]);
    TaskPoolDestroy(&work[0x420]);
    func_080A7210(work);
    **(u8**)&work[0x4F4] = work[0x50C];
}

void func_080A6838(UnkStruct_080A5D3C* w, u8 kind) {
    DeckCard2Args args;
    u16* cards;
    u8 i;
    s8 x;
    s8 y;

    cards = GetDeck(w->unk_4F8)->cards;
    x = 0;
    y = 0;
    for (i = 0; i < DECK_SIZE; i++) {
        if (cards[i] != 0xFFFF) {
            if (kind == 0) {
                args.unk_00 = &w->pool;
                args.unk_04 = gCardCollection[cards[i]] & 0x8FFF;
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 0;
                args.unk_0C = &cards[i];
                TaskCreate(&w->tasks, &gTaskDescDeckCard2, &args);
                x++;
            } else if (gCardDefs[gCardCollection[cards[i]] & CARD_ID_MASK].unk_2A == kind - 1) {
                args.unk_00 = &w->pool;
                args.unk_04 = gCardCollection[cards[i]] & 0x8FFF;
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 0;
                args.unk_0C = &cards[i];
                TaskCreate(&w->tasks, &gTaskDescDeckCard2, &args);
                x++;
            }
            if (x > 2) {
                x = 0;
                y++;
            }
        }
    }
    w->unk_494 = 0x4800;
    w->unk_498 = 0x2800;
    w->unk_4ED[1] = 4;
}
void func_080A6968(u8* work) {
    DeckCard2Work* node;

    node = ListPoolFirst(&work[0x434]);

    while (node != 0) {
        node->unk_4A = 1;
        node = ListPoolNext(&node->node);
    }

    TaskPoolUpdate(&work[0x40C]);
}

void func_080A69A0(u8* work) {
    DeckCard2Work* node;

    node = ListPoolFirst(&work[0x434]);

    if ((s8)work[0x4EE] == 33) {
        return;
    }

    while (node != 0) {
        node->unk_24--;

        if (node->unk_24 < 0) {
            node->y = 0x20000;
            func_08090170(node);
        }

        node = ListPoolNext(&node->node);
    }

    m4aSongNumStart(0x79);
    work[0x4EE]++;
    *(s32*)&work[0x498] += 0x300;

    if (*(s32*)&work[0x498] > 0x7C00) {
        *(s32*)&work[0x498] = 0x7C00;
    }

    if (work[0x508] != 0) {
        (*(u16*)&work[0x4BA])--;
    }
}

u8 func_080A6A38(u8* work) {
    DeckCard2Work* node;

    node = ListPoolFirst(&work[0x434]);

    if (node == 0) {
        *(s32*)&work[0x498] -= 0x300;

        if (*(s32*)&work[0x498] < 0x2800) {
            *(s32*)&work[0x498] = 0x2800;
            return 0;
        }

        return 1;
    }

    if (node->unk_24 == 0) {
        return 0;
    }

    do {
        node->unk_24++;

        if (node->unk_24 > 3) {
            node->y = 0x20000;
            func_08090170(node);
        }

        node = ListPoolNext(&node->node);
    } while (node != 0);

    m4aSongNumStart(0x79);
    work[0x4EE]--;
    *(s32*)&work[0x498] -= 0x300;

    if (*(s32*)&work[0x498] < 0x2800) {
        *(s32*)&work[0x498] = 0x2800;
    }

    return 1;
}

DeckCard2Work* func_080A6AE8(u8* work) {
    DeckCard2Work* node;

    node = ListPoolFirst(&work[0x434]);

    while (node != 0) {
        if (*(s16*)&work[0x4C8] == node->unk_22 &&
            *(s16*)&work[0x4CA] == node->unk_24) {
            return node;
        }

        node = ListPoolNext(&node->node);
    }

    return 0;
}

void func_080A6B40(u8 a, u8 b) {
    u8 d[2];
    u8* base;

    d[0] = a / 10;
    d[1] = a - (u8)(a / 10) * 10;
    base = (u8*)GetBgCharBase(3);
    RequestDma3Copy(&gUnk_0940F7B8[(d[0] + 1) * 32], base + (b * 64 + 0x360), 32);
    RequestDma3Copy(&gUnk_0940F7B8[(d[1] + 1) * 32], base + (b * 64 + 0x360) + 32, 32);
}

void func_080A6BB4(u8* work) {
    u16 t;

    switch (work[0x4E6]) {
    case 0:
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        AnimStart(&work[0x444], 0, 1);
        *(u16*)&work[0x4C6] &= ~1;
        break;
    case 1:
    case 3:
        AnimStart(&work[0x444], 2, 1);
        t = *(u16*)&work[0x4C6] | 1;
        *(u16*)&work[0x4C6] = t;
        break;
    }
}

void func_080A6C50(u8 deck) {
    u8 d[2];
    u8 e[2];
    u32 base;
    u16 n;

    base = 0;
    n = GetDeckCardCount(deck);
    d[0] = n / 10;
    d[1] = n - (u16)(n / 10) * 10;
    e[0] = 9;
    e[1] = 9;

    switch (deck) {
    case 0:
        base = GetBgCharBase(1);
        break;
    case 1:
        base = GetBgCharBase(1);
        break;
    case 2:
        base = GetBgCharBase(1);
        break;
    }

#ifdef VERSION_EU
    RequestDma3Copy(&gUnk_0940F938[(d[0] + 1) * 32], (u8*)base + 0x2C00, 32);
    RequestDma3Copy(&gUnk_0940F938[(d[1] + 1) * 32], (u8*)base + 0x2C20, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[0] + 1) * 32], (u8*)base + 0x2C40, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[1] + 1) * 32], (u8*)base + 0x2C60, 32);
#else
    RequestDma3Copy(&gUnk_0940F938[(d[0] + 1) * 32], (u8*)base + 0x20, 32);
    RequestDma3Copy(&gUnk_0940F938[(d[1] + 1) * 32], (u8*)base + 0x40, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[0] + 1) * 32], (u8*)base + 0x60, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[1] + 1) * 32], (u8*)base + 0x80, 32);
#endif
}

void func_080A6D0C(void) {
    u8 d[3];
    u8 e[3];
    u16 a;
    u16 b;
    u32 base;

    a = CountCardsInDecks();
    b = CountCollectionCards();
    d[0] = a / 100;
    d[1] = a / 10 - d[0] * 10;
    d[2] = a - d[0] * 100 - d[1] * 10;
    e[0] = b / 100;
    e[1] = b / 10 - e[0] * 10;
    e[2] = b - e[0] * 100 - e[1] * 10;
    base = GetBgCharBase(3);
    RequestDma3Copy(&gUnk_0940F938[(d[0] + 1) * 32], (void*)(base + 0x2A0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d[1] + 1) * 32], (void*)(base + 0x2C0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d[2] + 1) * 32], (void*)(base + 0x2E0), 32);
    RequestDma3Copy(&gUnk_0940F938[(e[0] + 1) * 32], (void*)(base + 0x300), 32);
    RequestDma3Copy(&gUnk_0940F938[(e[1] + 1) * 32], (void*)(base + 0x320), 32);
    RequestDma3Copy(&gUnk_0940F938[(e[2] + 1) * 32], (void*)(base + 0x340), 32);
}

void func_080A6E3C(u8* work) {
    FreeTextSlots(&work[0x30], 8);
    FreeTextSlots(&work[0x70], 8);
    FreeTextSlots(&work[0xB0], 8);
    work[0x4FA] = LoadTextSlots(GetDeckName(0), &work[0x30]);
    work[0x4FB] = LoadTextSlots(GetDeckName(1), &work[0x70]);
    work[0x4FC] = LoadTextSlots(GetDeckName(2), &work[0xB0]);
}

void func_080A6EB4(u8* work, s32 id) {
    CardDef* def;

    def = &gCardDefs[id];
#ifdef VERSION_EU
    work[0x4FD] = LoadTextSlots(eu_0805E924(def->name), &work[0xF0]);
#else
    work[0x4FD] = LoadTextSlots(def->name, &work[0xF0]);
#endif

    switch (def->unk_2A) {
    case 0:
        LoadPalette(gUnk_09614458,
                    (void*)((*(UnkStruct_080038C8**)&work[0x3D8])->index * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x3D8])->count << 5));
        break;
    case 1:
        LoadPalette(gUnk_09614478,
                    (void*)((*(UnkStruct_080038C8**)&work[0x3D8])->index * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x3D8])->count << 5));
        break;
    case 2:
        LoadPalette(gUnk_09614498,
                    (void*)((*(UnkStruct_080038C8**)&work[0x3D8])->index * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x3D8])->count << 5));
        break;
    case 3:
        LoadPalette(gUnk_096144B8,
                    (void*)((*(UnkStruct_080038C8**)&work[0x3D8])->index * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x3D8])->count << 5));
        break;
    }
}

void func_080A6F60(void** p) {
    if (p[9] != 0) {
        ReleaseObjTiles(p[9]);
        p[9] = 0;
    }

    if (p[6] != 0) {
        ReleaseObjTiles(p[6]);
        ReleaseObjPalette(p[10]);
        ReleaseObjTiles(p[7]);
        ReleaseObjPalette(p[11]);

        if (p[8] != 0) {
            ReleaseObjTiles(p[8]);
            p[8] = 0;
        }

        p[6] = 0;
        p[10] = 0;
        p[7] = 0;
        p[11] = 0;
    }
}

void func_080A6FAC(UnkStruct_080A6FAC* w) {
    DeckCard2Work* node;
    CardDef* def;
    void* dst;
    u16 id;
    u32 t;

    id = 0xFFFF;
    node = ListPoolFirst(&w->pool);

    while (node != 0) {
        if (node->unk_24 == w->unk_4CA && node->unk_22 == w->unk_4C8) {
            id = node->cardId;
            break;
        }

        node = ListPoolNext(&node->node);
    }

    func_080A6F60((void**)w);

    if (id != 0xFFFF) {
        if (id & 0x8000) {
            w->tiles4 = AllocObjTiles(0x280, 0);
            SetObjTileSource(w->tiles4, gUnk_0908B1B4);
            AnimInit(&w->anim, gUnk_09EEA164, gUnk_09EEA148);
            AnimStart(&w->anim, 0, 1);
            w->gfx = AnimGetGfx(&w->anim);
        }

        t = id & CARD_ID_MASK;
        def = &gCardDefs[t];
        w->tiles = LoadObjTiles(gUnk_08F709B0[def->unk_2A].tiles, 768);
        w->tiles2 = LoadObjTiles(def->tiles, 512);
        w->palette2 = LoadObjPalette(def->palette, 32);
        w->palette = LoadObjPalette(gUnk_09611AB8, 32);
        w->gfx2 = gUnk_08F709B0[def->unk_2A].gfx;
        w->gfx3 = def->gfx;

        if (def->unk_2A != 3) {
            w->tiles3 = LoadObjTiles(gUnk_0905EAE8, 480);
            w->gfx4 = gUnk_09EE981C[def->unk_20];
        }

        func_080A7180(def->unk_2C);
        dst = gUnk_05000160;
        LoadPalette(&gUnk_09614118[def->unk_2A * 32 + 0x200], dst, 32);
        func_080A6EB4((u8*)w, t);
        func_080A5C60((u8*)w, t);
        w->unk_50B = 1;
    } else {
        func_080A7180(0);
        w->unk_50B = 0;
    }
}

void func_080A7180(u8 a) {
    u8 v[2];
    u32 base;

    base = GetBgCharBase(3);

    if (a != 0) {
        v[0] = a / 10;
        v[1] = a - v[0] * 10;
        RequestDma3Copy(&gUnk_0940FA98[(v[0] + 3) * 32], (void*)(base + 0xCE0), 32);
        RequestDma3Copy(&gUnk_0940FA98[(v[1] + 3) * 32], (void*)(base + 0xD00), 32);
    } else {
        RequestDma3Copy(gUnk_0940FAD8, (void*)(base + 0xCE0), 32);
        RequestDma3Copy(gUnk_0940FAD8, (void*)(base + 0xD00), 32);
    }
}
void func_080A7210(u8* work) {
    void** p;
    u16 i;

    if (*(void**)&work[0x3E8] != 0) {
        for (i = 0; i < *(u16*)&work[0x4DC]; i++) {
            EwramFree(((UnkStruct_0808E2F0*)*(void**)&work[0x3E8])[i].unk_1C);
        }

        p = (void**)&work[0x3E8];
        EwramFree(*p);
        *p = 0;
    }
}
void func_080A7264(void** p) {
    if (p[2] != 0) {
        ReleaseObjTiles(p[2]);
        ReleaseObjPalette(p[3]);
        p[2] = 0;
        p[3] = 0;
    }
}
void func_080A7284(u8* work, u8 mode) {
    switch (mode) {
    case 0:
        SetObjTileSource(*(void**)&work[4], gUnk_090A4A0C);
        AnimInit(&work[0x45C], gUnk_09EEB064, gUnk_09EEB050);
        AnimStart(&work[0x45C], 0, 1);
        *(void**)&work[0x404] = AnimGetGfx(&work[0x45C]);
        break;
    case 1:
        SetObjTileSource(*(void**)&work[4], gUnk_090A51F6);
        AnimInit(&work[0x45C], gUnk_09EEB07C, gUnk_09EEB068);
        AnimStart(&work[0x45C], 0, 1);
        *(void**)&work[0x404] = AnimGetGfx(&work[0x45C]);
        break;
    }
}
u8 func_080A7300(u8* work) {
    if (GetDeckCpCost(GetActiveDeckIndex()) > gGameState.progression.cp) {
        TaskCreate(&work[0x420], &gUnk_09EE7FA8, &work[0x501]);
        m4aSongNumStart(0x69);
        return 0;
    }

    return 1;
}
u8 func_080A734C(u8* work) {
    if (func_080857D4(0) == 0) {
        m4aSongNumStart(0x69);
        TaskCreate(&work[0x420], &gUnk_09EE7FC0, &work[0x501]);
        return 0;
    }

    return 1;
}
u8 func_080A7388(u8* work, s16 x, s16 y, u16 dir) {
    DeckCard2Work* node;

    node = ListPoolFirst(&work[0x434]);

    while (node != 0) {
        if (node->unk_22 == x && node->unk_24 == y) {
            return 1;
        }

        node = ListPoolNext(&node->node);
    }

    switch (dir) {
    case 64:
        return func_080A7388(work, x, y - 1, 64);
    case 128:
        return func_080A7388(work, x, y + 1, 128);
    case 32:
        return func_080A7388(work, x - 1, y, 32);
    case 16:
        return func_080A7388(work, x + 1, y, 16);
    }

    return 0;
}

void func_080A584C(u8* work, void* a);

#ifdef VERSION_EU
void* gUnkEu_09F7434C[5] = { gUnk_090A418E, gUnkEu_091926B2, gUnkEu_0919308A, gUnkEu_09192D42, gUnkEu_091929FA };

void** gUnkEu_09F74360[5] = {
    &gUnk_09EEAFF8,
    &gUnkEu_09F77100,
    &gUnkEu_09F77118,
    &gUnkEu_09F77110,
    &gUnkEu_09F77108,
};

u8* gUnkEu_09F74374[5] = { gUnkEu_094EAD64, gUnkEu_094E90E4, gUnkEu_094EA2E4, gUnkEu_094E9CE4, gUnkEu_094E96E4 };
#endif

const char gTaskName_09EE8EF0[] = "Deckmenu2";

TaskDesc gUnk_09EE8EF0 = {
    gTaskName_09EE8EF0,
    (void (*)(void*, void*))func_080A584C,
    func_080A5C9C,
    (void (*)(void*))func_080A6500,
    (void (*)(void*))func_080A676C,
    0x510,
};
