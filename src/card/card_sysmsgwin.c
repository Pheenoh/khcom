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
#include "sprites_evt.h"
#include "sprites_msg.h"
#include "sprites_map.h"
#include "sprites_card.h"

UnkStruct_02034AFC* gUnk_02034B00;
#ifndef VERSION_EU
u8 gUnk_02034B04[4];
#endif

#ifdef VERSION_EU
extern s32 gUnkEu_090D1DC0[];
extern void* gUnkEu_08890E1C[];
extern void* gUnkEu_08890E44[];

#define LANGSTR(x) (((void**)(x))[gLanguage])
#else
#define LANGSTR(x) (x)
#endif
u8 func_080A470C(UnkStruct_080A3F5C* w, void* a);
s32 func_080A4910(UnkStruct_080A3F5C* w);
u8 func_080A4958(UnkStruct_080A3F5C* w, void* a);
u8 func_080A4CC8(UnkStruct_080A3F5C* w, void* a);
s32 func_080A4D7C(u64* src);
s32 func_080A5150(UnkStruct_080A3F5C* w);
u8 func_0806BB44(s32 x, s32 y, s32 s, s32* d);
#ifdef VERSION_JP
u8 func_0806BDB8(s32 x, s32 y, s32 s, s32* d);
#endif
void func_080A430C(UnkStruct_080A4DCC* w, void* a) {
    vu32 zero = 0;

    CpuSet((void*)&zero, w, 0x05000052);
    *(u64*)&w->unk_10C = *(u64*)a;
    w->messageDef = &gUnk_09EE8008[*(u16*)&w->unk_110];
    if (w->messageDef->flags & 4) {
        w->unk_134 = func_0806BA74(1, 1);
    } else {
        w->unk_134 = func_0806BA74(1, 0);
    }
    FadeSetPaletteExcluded(w->unk_134 + 16, 1);
    w->unk_138[4] = 0;
    w->unk_138[0] = 8;
    w->unk_138[1] = 0;
    w->unk_138[2] = 0;
    w->unk_138[3] = 0;
    w->unk_143 = 0;
    w->unk_130 = 0;
    w->tiles = 0;
    w->palette = 0;
    w->unk_008 = 0;
    w->unk_00C = 0;
    w->unk_018 = 0;
    w->unk_01C = 0;
    w->unk_010 = 0;
    w->unk_014 = 0;
    w->unk_0C0 = 0;
    w->unk_142 = 1;
    w->unk_141 = 1;
    w->unk_144 = 0;
    ((u8*)&w->unk_13E)[1] = 0;
    w->unk_140 = 0;
    w->unk_145 = 0;
    w->unk_146[0] = 1;
#ifdef VERSION_JP
    w->unk_138[3] = func_0806BDB8(0x2E00, gUnk_09033CB8[w->messageDef->unk_04],
                                   (s32)w->messageDef->text, (s32*)&w->unk_130);
#else
    if (w->unk_130 != 0) {
#ifdef VERSION_EU
        w->unk_138[3] = func_0806BB44(0x2E00, gUnkEu_090D1DC0[w->messageDef->unk_04] - 0x200,
                                       (s32)LANGSTR(w->messageDef->text), (s32*)&w->unk_130);
#else
        w->unk_138[3] = func_0806BB44(0x2E00, gUnk_09041E80[w->messageDef->unk_04] - 0x200,
                                       (s32)w->messageDef->text, (s32*)&w->unk_130);
#endif
    } else {
#ifdef VERSION_EU
        w->unk_138[3] = func_0806BB44(0x2E00, gUnkEu_090D1DC0[w->messageDef->unk_04] - 0x200,
                                       (s32)LANGSTR(w->messageDef->text), (s32*)&w->unk_130);
#else
        w->unk_138[3] = func_0806BB44(0x2E00, gUnk_09041E80[w->messageDef->unk_04] - 0x200,
                                       (s32)w->messageDef->text, (s32*)&w->unk_130);
#endif
    }
#endif
    InitTextSlots(w->unk_020, 10);
    InitTextSlots(w->unk_070, 10);
    gUnk_0203A9D4 = 1;
    gUnk_0203A9D8 = 0;
    w->unk_138[1] = w->unk_138[3];
    switch (w->unk_113) {
    case 0:
        w->tiles = AllocObjTiles(0x40, 0);
        w->palette = LoadObjPalette(gUnk_08F69BA4, 32);
        FadeSetPaletteExcluded(((UnkStruct_080038C8*)w->palette)->index + 16, 1);
        SetObjTileSource(w->tiles, gUnk_09320796);
        AnimInit(w->anim, gUnk_09EEFD38, gUnk_09EEFCAC);
        AnimStart(w->anim, 2, 1);
        w->gfx = (s32)AnimGetGfx(w->anim);
        SetBgPriority(w->unk_10C, 0);
        break;
    case 1:
        SetBgPriority(w->unk_10C, 0);
        break;
    case 2:
        w->tiles = AllocObjTiles(0x40, 0);
        w->palette = LoadObjPalette(gUnk_08F69BA4, 32);
        FadeSetPaletteExcluded(((UnkStruct_080038C8*)w->palette)->index + 16, 1);
        SetObjTileSource(w->tiles, gUnk_09320796);
        AnimInit(w->anim, gUnk_09EEFD38, gUnk_09EEFCAC);
        AnimStart(w->anim, 2, 1);
        w->gfx = (s32)AnimGetGfx(w->anim);
        break;
    }
    gUnk_02034B00 = (UnkStruct_02034AFC*)w;
}

u8 func_080A4578(UnkStruct_080A3F5C* w, void* a) {
    void* pal;

    switch (w->unk_113) {
    case 0:
    case 1:
        pal = &gUnk_050001C0[0x20];
        LoadBgTiles(w->unk_10C, gUnk_0950E2F8, 0x140);
        LoadBgMap(w->unk_10C, gUnk_096112B8, 0x800);
        LoadPalette(gUnk_09611AB8, pal, 32);

        switch ((u32)w->messageDef->unk_04) {
        case 0:
        case 2:
            SetBgScroll(w->unk_10C, (u16)-24, 0);
            break;
        case 1:
        case 3:
            SetBgScroll(w->unk_10C, (u16)-24, (u16)-94);
            break;
        default:
            SetBgScroll(w->unk_10C, (u16)-24, (u16)-94);
            break;
        }
        break;
    case 2:
    case 3:
        switch ((u32)w->messageDef->unk_04) {
        case 0:
        case 2:
            w->unk_120 = 0x7800;
            w->unk_124 = 0x2200;
            break;
        case 1:
        default:
            w->unk_120 = 0x7800;
            w->unk_124 = 0x7E00;
            break;
        }

        w->tiles2 = LoadObjTiles(&gUnk_093F8C8E[0xC1E], 0x1800);

        if (w->tiles2 == 0) {
            w->unk_146[1] = 1;
            w->tiles2 = LoadObjTiles(&gUnk_0950E2F8[0x140], 0x680);
        } else {
            w->unk_146[1] = 0;
        }

        w->palette4 = LoadObjPalette(gUnk_09611AB8, 32);
        FadeSetPaletteExcluded(w->palette4->index + 16, 1);
        break;
    }

    switch (w->unk_113) {
    case 0:
    case 2:
        SetTaskUpdate(a, (TaskUpdateFunc)func_080A470C);
        break;
    case 1:
    case 3:
        SetTaskUpdate(a, (TaskUpdateFunc)func_080A4CC8);
        break;
    }

    return 1;
}

u8 func_080A470C(UnkStruct_080A3F5C* w, void* a) {
    u8* pal;

    if (w->tiles3 != 0) {
        *(void**)&w->gfx4 = AnimUpdate(w->anim2);
    }

    if (GetKeysPressed() & A_BUTTON) {
        m4aSongNumStart(SONG_SYS_KETTEI);
        if (w->gfx2 != 0) {
#ifdef VERSION_JP
            w->unk_138[3] = func_0806BDB8(0x2E00, gUnk_09033CB8[w->messageDef->unk_04],
                                           (s32)w->gfx2, (s32*)&w->gfx2);
#elif defined(VERSION_EU)
            w->unk_138[3] = func_0806BB44(0x2E00, gUnkEu_090D1DC0[w->messageDef->unk_04] - 0x200,
                                           (s32)w->gfx2, (s32*)&w->gfx2);
#else
            w->unk_138[3] = func_0806BB44(0x2E00, gUnk_09041E80[w->messageDef->unk_04] - 0x200,
                                           (s32)w->gfx2, (s32*)&w->gfx2);
#endif
            w->unk_138[1] = w->unk_138[3];
        } else if (!(w->messageDef->flags & 1)) {
            AnimStart(w->anim2, 3, 1);
            w->unk_142 = 0;
            SetTaskUpdate(a, (TaskUpdateFunc)func_080A4910);
            ((s16*)&w->gfx3)[1] = 0;
            w->unk_138[0] = 8;
        } else {
            ReleaseObjTiles(w->tiles3);
            ReleaseObjPalette(w->palette);
            w->tiles3 = 0;
            w->palette = 0;
            w->tiles4 = AllocObjTiles(0x120, 0);
            pal = gUnk_09614418;
            w->palette2 = LoadObjPalette(pal, 32);
#ifdef VERSION_EU
            FadeSetPaletteExcluded(((UnkStruct_080038C8*)w->palette2)->index + 16, 1);
#else
            FadeSetPaletteExcluded(w->palette4->index + 16, 1);
#endif
            LoadObjPaletteBank(((UnkStruct_080038C8*)w->palette2)->index, pal);
            SetObjTileSource(w->tiles4, gUnk_090A4664);
            AnimInit(w->anim3, gUnk_09EEB03C, gUnk_09EEB008);
            AnimStart(w->anim3, 2, 1);
            w->gfx = AnimGetGfx(w->anim3);
            w->unk_13D = 1;
            w->x = 0x5800;
            w->unk_11C = gUnk_09033D28[w->unk_13D] - 0x500;
#ifdef VERSION_EU
            ((u8*)&w->unk_13E)[1] = LoadTextSlots(eu_0805E924(gUnkEu_08890E1C), w->unk_020);
            w->unk_140 = LoadTextSlots(eu_0805E924(gUnkEu_08890E44), w->unk_070);
#else
            ((u8*)&w->unk_13E)[1] = LoadTextSlots(gUnk_08159E10, w->unk_020);
            w->unk_140 = LoadTextSlots(gUnk_08159E18, w->unk_070);
#endif
            w->unk_0C0 = (s32)_08066468(1);
            w->unk_144 = 1;
            w->tiles = LoadObjTiles(gUnk_093F7C9C, 0xFC0);
            w->palette3 = LoadObjPalette(gUnk_09611AB8, 32);
#ifdef VERSION_EU
            FadeSetPaletteExcluded(((UnkStruct_080038C8*)w->palette3)->index + 16, 1);
#else
            FadeSetPaletteExcluded(w->palette4->index + 16, 1);
#endif
            SetTaskUpdate(a, (TaskUpdateFunc)func_080A4958);
        }
    }
    return 1;
}
s32 func_080A4910(UnkStruct_080A3F5C* w) {
    if (w->tiles3 != 0) {
        *(void**)&w->gfx4 = AnimUpdate(w->anim2);
    }

    ((s16*)&w->gfx3)[1] += 1;

    if (((s16*)&w->gfx3)[1] > 15) {
        ((u8*)w)[0x141] = 0;
        return 0;
    }

    return 1;
}
u8 func_080A4958(UnkStruct_080A3F5C* w, void* a) {
    w->gfx = AnimUpdate(w->anim3);

    switch (GetKeysPressed()) {
    case DPAD_UP:
        if (w->unk_13D != 0) {
            w->unk_13D--;
            m4aSongNumStart(SONG_SYS_CLICK);
        }

        ((u8*)&w->unk_13E)[0] = 4;
        break;
    case DPAD_DOWN:
        if (w->unk_13D == 0) {
            w->unk_13D++;
            m4aSongNumStart(SONG_SYS_CLICK);
        }

        ((u8*)&w->unk_13E)[0] = 4;
        break;
    case A_BUTTON:
    case START_BUTTON:
        m4aSongNumStart(SONG_SYS_KETTEI);

        if (w->unk_13D == 0) {
            gUnk_0203A9D8 = 1;
        } else {
            gUnk_0203A9D8 = 0;
        }

        w->unk_142 = 0;
        SetTaskUpdate(a, (TaskUpdateFunc)func_080A4910);
        break;
    }

    if (((u8*)&w->unk_13E)[0] != 0) {
        ApproachValue(&w->unk_11C, gUnk_09033D28[w->unk_13D] - 0x500, ((u8*)&w->unk_13E)[0]);
        ((u8*)&w->unk_13E)[0]--;
    }

    return 1;
}

void func_080A4A50(UnkStruct_080A3F5C* w) {
    func_0806C2C0(w->unk_138[1]);

    switch (w->unk_113) {
    case 2:
    case 3:
        if (w->tiles2 != 0) {
            if (w->unk_146[1] != 0) {
                DrawSprite(w->unk_120 >> 8, w->unk_124 >> 8, (&gUnk_09EF12E8[2])[0],
                           w->tiles2, w->palette4, 0, 0, 10);
            } else {
                DrawSprite(w->unk_120 >> 8, w->unk_124 >> 8, (&gUnk_09EF1278[2])[0],
                           w->tiles2, w->palette4, 0, 0, 10);
            }
        }
        break;
    }

    if (w->tiles3 != 0) {
        if (w->unk_141 != 0) {
            DrawSprite(120, gUnk_09033D08[w->messageDef->unk_04][1] >> 8, *(void**)&w->gfx4,
                       w->tiles3, w->palette, 0, 0, 5);
        }
    }

    if (w->tiles4 != 0) {
        DrawSprite(w->x >> 8, w->unk_11C >> 8, w->gfx,
                   w->tiles4, w->palette2, 0, 1, 5);
    }

    if (w->unk_144 != 0) {
        DrawSprite(120, 75, gUnk_09EF126C[1], w->tiles, w->palette3, 0, 0, 10);
        DrawTextSlots((240 - GetTextSlotsWidth((TextSlot*)w->unk_020, ((u8*)&w->unk_13E)[1])) >> 1, 62, w->unk_020,
                      (void*)w->unk_0C0, 0, ((u8*)&w->unk_13E)[1]);
        DrawTextSlots((240 - GetTextSlotsWidth((TextSlot*)w->unk_070, w->unk_140)) >> 1, 77, w->unk_070,
                      (void*)w->unk_0C0, 0, w->unk_140);
    }
}

void func_080A4C1C(UnkStruct_080A3F5C* w) {
    if (w->unk_113 <= 1) {
        DisableBg(w->unk_10C);
    }

    func_0806C34C();

    if (w->tiles3 != 0) {
        ReleaseObjTiles(w->tiles3);
    }

    if (w->palette != 0) {
        ReleaseObjPalette(w->palette);
    }

    if (w->tiles4 != 0) {
        ReleaseObjTiles(w->tiles4);
    }

    if (w->palette2 != 0) {
        ReleaseObjPalette(w->palette2);
    }

    if (w->tiles != 0) {
        ReleaseObjTiles(w->tiles);
    }

    if (w->tiles2 != 0) {
        ReleaseObjTiles(w->tiles2);
    }

    if (w->palette4 != 0) {
        ReleaseObjPalette(w->palette4);
    }

    if (w->palette3 != 0) {
        ReleaseObjPalette(w->palette3);
    }

    if (w->unk_0C0 != 0) {
        ReleaseObjPalette((u8*)w->unk_0C0);
    }

    FreeTextSlots((TextSlot*)w->unk_020, 10);
    FreeTextSlots((TextSlot*)w->unk_070, 10);
    gUnk_0203A9D4 = 0;
    gUnk_02034B00 = 0;
}
#ifndef VERSION_JP
u8 func_080A4CC8(UnkStruct_080A3F5C* w, void* a) {
    s32* p;
    u8 x;

    if (w->unk_146[0] == 0) {
        return 0;
    }

    if (w->unk_145 == 1) {
        w->unk_145 = 0;
        w->messageDef = &gUnk_09EE8008[*(u16*)&w->unk_110];
        p = (s32*)&w->gfx2;

        if (*p != 0) {
            w->unk_138[3] = func_0806BB44(
                0x2E00,
                gUnk_09041E80[w->messageDef->unk_04] - 0x200,
                *p, p);
        } else {
            w->unk_138[3] = func_0806BB44(
                0x2E00,
                gUnk_09041E80[w->messageDef->unk_04] - 0x200,
                (s32)LANGSTR(w->messageDef->text),
                p);
        }

        x = w->unk_138[3];
        w->unk_138[1] = x;
    }

    return 1;
}
#else
u8 func_080A4CC8(UnkStruct_080A3F5C* w, void* a) {
    if (w->unk_146[0] == 0) {
        return 0;
    }

    if (w->unk_145 == 1) {
        w->unk_145 = 0;
        w->messageDef = &gUnk_09EE8008[*(u16*)&w->unk_110];
        w->unk_138[3] = func_0806BDB8(
            0x2E00,
            gUnk_09033CB8[w->messageDef->unk_04],
            (s32)(w->messageDef->text),
            (s32*)&w->gfx2);
        w->unk_138[1] = w->unk_138[3];
    }

    return 1;
}
#endif
s32 func_080A4D7C(u64* src) {
    if (gUnk_02034B00 != 0) {
        gUnk_02034B00->unk_10C = *src;
        gUnk_02034B00->unk_145 = 1;

        return 1;
    }

    return 0;
}

s32 func_080A4DAC(void) {
    if (gUnk_02034B00 != 0) {
        gUnk_02034B00->unk_146[0] = 0;
        return 1;
    }

    return 0;
}
void func_080A4DCC(UnkStruct_080A4DCC* w, void* a) {
    vu32 zero = 0;

    CpuSet((void*)&zero, w, 0x05000052);
    *(u64*)&w->unk_10C = *(u64*)a;
    w->messageDef = &gUnk_09EE8008[*(u16*)&w->unk_110];
    w->unk_134 = func_0806BA74(1, 0);
    FadeSetPaletteExcluded(w->unk_134 + 16, 1);
    w->unk_138[4] = 0;
    w->unk_138[0] = 8;
    w->unk_138[1] = 0;
    w->unk_138[2] = 0;
    w->unk_138[3] = 0;
    w->unk_143 = 0;
    w->unk_130 = 0;
    w->tiles = 0;
    w->palette = 0;
    w->unk_008 = 0;
    w->unk_00C = 0;
    w->unk_018 = 0;
    w->unk_01C = 0;
    w->unk_010 = 0;
    w->unk_014 = 0;
    w->unk_0C0 = 0;
    w->unk_142 = 1;
    w->unk_141 = 1;
    w->unk_144 = 0;
    ((u8*)&w->unk_13E)[1] = 0;
    w->unk_140 = 0;
    w->unk_145 = 0;
    w->unk_146[0] = 1;
#ifdef VERSION_JP
    w->unk_138[3] = func_0806BDB8(0x4000, 0x4000, (s32)w->messageDef->text, (s32*)&w->unk_130);
#else
    if (w->unk_130 != 0) {
#ifdef VERSION_EU
        switch (gLanguage) {
        case 0:
        case 1:
            w->unk_138[3] = func_0806BB44(0x4D00, 0x4000, (s32)LANGSTR(w->messageDef->text), (s32*)&w->unk_130);
            break;
        case 2:
            w->unk_138[3] = func_0806BB44(0x4100, 0x4000, (s32)LANGSTR(w->messageDef->text), (s32*)&w->unk_130);
            break;
        case 4:
            w->unk_138[3] = func_0806BB44(0x4400, 0x4000, (s32)LANGSTR(w->messageDef->text), (s32*)&w->unk_130);
            break;
        case 3:
            w->unk_138[3] = func_0806BB44(0x4600, 0x4000, (s32)LANGSTR(w->messageDef->text), (s32*)&w->unk_130);
            break;
        default:
            w->unk_138[3] = func_0806BB44(0x4D00, 0x4000, (s32)LANGSTR(w->messageDef->text), (s32*)&w->unk_130);
            break;
        }
#else
        w->unk_138[3] = func_0806BB44(0x4D00, 0x4000, (s32)LANGSTR(w->messageDef->text), (s32*)&w->unk_130);
#endif
    } else {
#ifdef VERSION_EU
        switch (gLanguage) {
        case 0:
        case 1:
            w->unk_138[3] = func_0806BB44(0x4D00, 0x4000, (s32)LANGSTR(w->messageDef->text), (s32*)&w->unk_130);
            break;
        case 2:
            w->unk_138[3] = func_0806BB44(0x4100, 0x4000, (s32)LANGSTR(w->messageDef->text), (s32*)&w->unk_130);
            break;
        case 4:
            w->unk_138[3] = func_0806BB44(0x4400, 0x4000, (s32)LANGSTR(w->messageDef->text), (s32*)&w->unk_130);
            break;
        case 3:
            w->unk_138[3] = func_0806BB44(0x4600, 0x4000, (s32)LANGSTR(w->messageDef->text), (s32*)&w->unk_130);
            break;
        default:
            w->unk_138[3] = func_0806BB44(0x4D00, 0x4000, (s32)LANGSTR(w->messageDef->text), (s32*)&w->unk_130);
            break;
        }
#else
        w->unk_138[3] = func_0806BB44(0x4D00, 0x4000, (s32)LANGSTR(w->messageDef->text), (s32*)&w->unk_130);
#endif
    }
#endif
    InitTextSlots(w->unk_020, 10);
    InitTextSlots(w->unk_070, 10);
    gUnk_0203A9D4 = 1;
    gUnk_0203A9D8 = 0;
    w->unk_138[1] = w->unk_138[3];
    gUnk_02034B00 = (UnkStruct_02034AFC*)w;
}

u8 func_080A4F14(UnkStruct_080A3F5C* w, void* a) {
    void* pal;
    switch (w->unk_113) {
    case 0:
    case 1:
        pal = (void*)0x050001E0;
        LoadBgTiles(w->unk_10C, gUnk_099597E4, 0x140);
        LoadBgMap(w->unk_10C, gUnk_09985F44, 0x800);
        LoadPalette(gUnk_09611AB8, pal, 32);
        switch ((u32)w->messageDef->unk_04) {
        case 0:
        case 2:
            SetBgScroll(w->unk_10C, 0, 0);
            break;
        case 1:
        case 3:
            SetBgScroll(w->unk_10C, 0, 0);
            break;
        default:
            SetBgScroll(w->unk_10C, 0, 0);
            break;
        }
        break;
    case 2:
    case 3:
        switch ((u32)w->messageDef->unk_04) {
        case 0:
        case 2:
            w->unk_120 = 0x7800;
            w->unk_124 = 0x2000;
            break;
        case 1:
        default:
            w->unk_120 = 0x7800;
            w->unk_124 = 0x8200;
            break;
        }
        w->tiles2 = LoadObjTiles(gUnk_093F8C8E, 0xC00);
        w->palette4 = (UnkStruct_080038C8*)LoadObjPalette(gUnk_09611AB8, 32);
        FadeSetPaletteExcluded(w->palette4->index + 16, 1);
        break;
    }
    if (w->unk_113 == 0 || w->unk_113 == 2) {
        SetTaskUpdate(a, (TaskUpdateFunc)func_080A5034);
    }
    return 1;
}

u8 func_080A5034(UnkStruct_080A3F5C* w, void* a) {
    u8* pal;

    w->tiles4 = AllocObjTiles(0x120, 0);
    pal = gUnk_09614418;
    w->palette2 = LoadObjPalette(pal, 32);
#ifdef VERSION_EU
    FadeSetPaletteExcluded(((UnkStruct_080038C8*)w->palette2)->index + 16, 1);
#else
    FadeSetPaletteExcluded(w->palette4->index + 16, 1);
#endif
    LoadObjPaletteBank(((UnkStruct_080038C8*)w->palette2)->index, pal);
    SetObjTileSource(w->tiles4, gUnk_090A4664);
    AnimInit(w->anim3, gUnk_09EEB03C, gUnk_09EEB008);
    AnimStart(w->anim3, 2, 1);
    w->gfx = AnimGetGfx(w->anim3);
    w->unk_13D = 1;
    w->x = 0x8500;
    w->unk_11C = 0x5000;
#ifdef VERSION_EU
    ((u8*)&w->unk_13E)[1] = LoadTextSlots(eu_0805E924(gUnkEu_08890E1C), w->unk_020);
    w->unk_140 = LoadTextSlots(eu_0805E924(gUnkEu_08890E44), w->unk_070);
#else
    ((u8*)&w->unk_13E)[1] = LoadTextSlots(gUnk_08159E10, w->unk_020);
    w->unk_140 = LoadTextSlots(gUnk_08159E18, w->unk_070);
#endif
    w->unk_0C0 = (s32)_08066468(1);
    w->unk_144 = 1;
    w->tiles = LoadObjTiles(gUnk_093F7C9C, 0xFC0);
    w->palette3 = LoadObjPalette(gUnk_09611AB8, 32);
#ifdef VERSION_EU
    FadeSetPaletteExcluded(((UnkStruct_080038C8*)w->palette3)->index + 16, 1);
#else
    FadeSetPaletteExcluded(w->palette4->index + 16, 1);
#endif
    SetTaskUpdate(a, (TaskUpdateFunc)func_080A5198);
    return 1;
}
s32 func_080A5150(UnkStruct_080A3F5C* w) {
    if (w->tiles3 != 0) {
        *(void**)&w->gfx4 = AnimUpdate(w->anim2);
    }

    ((s16*)&w->gfx3)[1] += 1;

    if (((s16*)&w->gfx3)[1] > 15) {
        ((u8*)w)[0x141] = 0;
        return 0;
    }

    return 1;
}
u8 func_080A5198(UnkStruct_080A3F5C* w, void* a) {
    s32 tbl[2];

    *(u64*)tbl = *(u64*)gUnk_09041E9C;
    w->gfx = AnimUpdate(w->anim3);

    switch (GetKeysPressed()) {
    case DPAD_LEFT:
        if (w->unk_13D != 0) {
            w->unk_13D--;
            m4aSongNumStart(SONG_SYS_CLICK);
        }

        ((u8*)&w->unk_13E)[0] = 1;
        break;
    case DPAD_RIGHT:
        if (w->unk_13D == 0) {
            w->unk_13D++;
            m4aSongNumStart(SONG_SYS_CLICK);
        }

        ((u8*)&w->unk_13E)[0] = 1;
        break;
    }

    switch (GetKeysPressed()) {
    case A_BUTTON:
    case START_BUTTON:
        m4aSongNumStart(SONG_SYS_KETTEI);

        if (w->unk_13D == 0) {
            gUnk_0203A9D8 = 1;
        } else {
            gUnk_0203A9D8 = 0;
        }

        w->unk_142 = 0;
        SetTaskUpdate(a, (TaskUpdateFunc)func_080A5150);
        break;
    case B_BUTTON:
        m4aSongNumStart(SONG_SYS_CLOSE);
        gUnk_0203A9D8 = 0;
        w->unk_142 = 0;
        SetTaskUpdate(a, (TaskUpdateFunc)func_080A5150);
        break;
    }

    if (((u8*)&w->unk_13E)[0] != 0) {
        ApproachValue(&w->x, tbl[w->unk_13D], ((u8*)&w->unk_13E)[0]);
        ((u8*)&w->unk_13E)[0]--;
    }

    return 1;
}
void func_080A52BC(UnkStruct_080A3F5C* w) {
    func_0806C2C0(w->unk_138[1]);

    switch (w->unk_113) {
    case 2:
    case 3:
        if (w->tiles2 != 0) {
            DrawSprite(w->unk_120 >> 8, w->unk_124 >> 8, gUnk_09EF1278[0], w->tiles2, w->palette4, 0, 0, 20);
        }
        break;
    }

    if (w->tiles3 != 0 && w->unk_141 != 0) {
        DrawSprite(120, gUnk_09033D08[w->messageDef->unk_04][1] >> 8, w->gfx4, w->tiles3, w->palette, 0, 0, 10);
    }

    if (w->tiles4 != 0) {
        DrawSprite(w->x >> 8, w->unk_11C >> 8, w->gfx, w->tiles4, w->palette2, 0, 1, 10);
    }

    DrawTextSlots(89, 86, w->unk_020, w->unk_0C0, 0, ((u8*)&w->unk_13E)[1]);
    DrawTextSlots(135, 86, w->unk_070, w->unk_0C0, 0, w->unk_140);
}

void func_080A53E4(UnkStruct_080A3F5C* w) {
    if (w->unk_113 <= 1) {
        DisableBg(w->unk_10C);
    }

    func_0806C34C();

    if (w->tiles3 != 0) {
        ReleaseObjTiles(w->tiles3);
    }

    if (w->palette != 0) {
        ReleaseObjPalette(w->palette);
    }

    if (w->tiles4 != 0) {
        ReleaseObjTiles(w->tiles4);
    }

    if (w->palette2 != 0) {
        ReleaseObjPalette(w->palette2);
    }

    if (w->tiles != 0) {
        ReleaseObjTiles(w->tiles);
    }

    if (w->tiles2 != 0) {
        ReleaseObjTiles(w->tiles2);
    }

    if (w->palette4 != 0) {
        ReleaseObjPalette(w->palette4);
    }

    if (w->palette3 != 0) {
        ReleaseObjPalette(w->palette3);
    }

    if (w->unk_0C0 != 0) {
        ReleaseObjPalette((u8*)w->unk_0C0);
    }

    FreeTextSlots((TextSlot*)w->unk_020, 10);
    FreeTextSlots((TextSlot*)w->unk_070, 10);
    gUnk_0203A9D4 = 0;
    gUnk_02034B00 = 0;
}

const char gTaskNameSysmsgwin[] = "sysmsgwin";

TaskDesc gUnk_09EE8E30 = {
    gTaskNameSysmsgwin,
    (TaskInitFunc)func_080A430C,
    (TaskUpdateFunc)func_080A4578,
    (TaskFunc)func_080A4A50,
    (TaskFunc)func_080A4C1C,
    0x148,
};

TaskDesc gUnk_09EE8E48 = {
    gTaskNameSysmsgwin,
    (TaskInitFunc)func_080A4DCC,
    (TaskUpdateFunc)func_080A4F14,
    (TaskFunc)func_080A52BC,
    (TaskFunc)func_080A53E4,
    0x148,
};
