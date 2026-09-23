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
#include "events_134_196.h"
#include "sprites_deck_menu.h"
#include "sprites_evt.h"
#include "sprites_msg.h"
#include "sprites_card.h"

UnkStruct_02034AFC* gUnk_02034AFC;

u8 gUnk_0203A9D4 EWRAM_COMMON(4);

u8 gUnk_0203A9D8 EWRAM_COMMON(4);

#ifdef VERSION_EU
extern void* gUnkEu_08890E1C[];
extern void* gUnkEu_08890E44[];

#define LANGSTR(x) (((void**)(x))[gLanguage])
#else
#define LANGSTR(x) (x)
#endif
s32 func_080A40EC(u64* src);
s32 func_080A4D7C(u64* src);
u8 func_080A36B0(UnkStruct_080A3F5C* w, void* a);
u8 func_080A3BB0(UnkStruct_080A3F5C* w, void* a);
u8 func_080A3F5C(UnkStruct_080A3F5C* w, void* a);
u8 func_0806BB44(s32 x, s32 y, s32 s, s32* d);
#ifdef VERSION_JP
u8 func_0806BDB8(s32 x, s32 y, s32 s, s32* d);
#endif
u8 func_080A4010(UnkStruct_080A3F5C* w, void* a);

void func_080A33C4(UnkStruct_080A3F5C* w, void* a) {
    vu32 zero;

    zero = 0;
    CpuSet((void*)&zero, w, 0x05000054);
    ((UnkStruct_02034AFC*)w)->unk_13C = func_0806BA74(0, 0);
    *(u64*)&w->unk_10C = *(u64*)a;
    w->messageDef = &gUnk_09EE8008[*(u16*)&w->unk_110];
    w->tiles3 = 0;
    w->palette = 0;
    w->tiles4 = 0;
    w->palette2 = 0;
    w->tiles = 0;
    w->palette3 = 0;
    w->tiles2 = 0;
    w->palette4 = 0;
    w->unk_0C0 = 0;
    w->x = gUnk_09033C98[w->messageDef->unk_04];
    w->unk_11C = 0;
    w->unk_120 = 0;
    w->unk_124 = 0;
    w->gfx4 = 0;
    w->gfx = 0;
    w->gfx2 = 0;
    w->gfx3 = 0;
    *(s32*)&w->unk_138 = 0;
    ((UnkStruct_02034AFC*)w)->unk_13C = 0;
    w->unk_13E = 0;
    w->unk_140 = 8;
    w->unk_141 = 0;
    w->unk_142 = 0;
    w->unk_143 = 0;
    w->unk_144 = 0;
    w->unk_145 = 0;
    w->unk_146[0] = 0;
    w->unk_146[1] = 0;
    w->unk_148 = 1;
    w->unk_149 = 0;
    w->unk_14A[0] = 0;
    w->unk_14A[1] = 0;
    w->unk_14C = 0;
    w->unk_14D = 0;
    w->unk_14E = 0;
    w->unk_14F = 1;

    switch ((u32)w->messageDef->unk_04) {
    case 0:
    case 1:
        w->unk_14D = 1;
        break;
    case 2:
    case 3:
        w->unk_14D = 0;
        break;
    }

    gUnk_0203A9D4 = 1;
    gUnk_0203A9D8 = 0;
    SetBgScroll(w->unk_10C, 0, 0);

    switch (w->unk_113) {
    case 0:
    case 1:
        SetBgPriority(w->unk_10C, 0);
        break;
    case 2:
    case 3:
        break;
    }

    gUnk_02034AFC = (UnkStruct_02034AFC*)w;
}

u8 func_080A3558(UnkStruct_080A3F5C* w, void* a) {
    const MsgFaceAnim* tbl;

    ApproachValue(&w->x, gUnk_09033CA0[w->messageDef->unk_04], w->unk_140);
    ApproachValue(&w->unk_11C, gUnk_09033CE0[w->messageDef->unk_04], w->unk_140);
    ScrollBgMapTo(w->unk_10C, w->x, 0);
    w->gfx = AnimUpdate(w->anim);

    if (w->unk_140 != 0) {
        w->unk_140--;
    } else {
        tbl = gUnk_09EE45DC[w->messageDef->unk_00];

        if (tbl[w->messageDef->unk_08].unk_10 > 1) {
            AnimStart(w->anim, 1, tbl[w->messageDef->unk_08].unk_11);
        }

        switch (w->unk_113) {
        case 0:
            SetTaskUpdate(a, (void*)func_080A3A98);
            break;
        case 1:
            SetTaskUpdate(a, (void*)func_080A3F5C);
            break;
        }
    }

    return 1;
}

u8 func_080A3640(UnkStruct_080A3F5C* w, void* a) {
    LoadBgTiles(w->unk_10C, gUnk_094233B8, 1280);
    LoadBgPalette(w->unk_10C, gUnk_096148D8, 32);
    SetBgMapBlocks(w->unk_10C, gUnk_09EE4724[((NumberPlusArgs*)w->messageDef)->unk_04], 2, 1);
    ScrollBgMapTo(w->unk_10C, *(u16*)&w->x, 0);
    SetTaskUpdate(a, (void*)func_080A36B0);
    return 1;
}

u8 func_080A36B0(UnkStruct_080A3F5C* w, void* a) {
#ifdef VERSION_JP
    w->unk_143 = func_0806BDB8(gUnk_09033CA8[w->messageDef->unk_04],
                               gUnk_09033CB8[w->messageDef->unk_04],
                               (s32)w->messageDef->text,
                               (s32*)&w->unk_138);
#else
    s32* p;

    p = (s32*)&w->unk_138;

    if (*p != 0) {
        w->unk_143 = func_0806BB44(gUnk_09033CA8[w->messageDef->unk_04],
                                   gUnk_09033CB8[w->messageDef->unk_04] - 0x200,
                                   *p, p);
    } else {
        w->unk_143 = func_0806BB44(gUnk_09033CA8[w->messageDef->unk_04],
                                   gUnk_09033CB8[w->messageDef->unk_04] - 0x200,
                                   (s32)LANGSTR(w->messageDef->text), p);
    }
#endif

    InitTextSlots((TextSlot*)w->unk_020, 10);
    InitTextSlots((TextSlot*)w->unk_070, 10);
    SetTaskUpdate(a, (void*)func_080A3754);

    return 1;
}
u8 func_080A3754(UnkStruct_080A3F5C* w, void* a) {
    CardMessageDef* sel;
    const MsgFaceAnim* e;

    w->unk_149 = 1;
    sel = w->messageDef;

    if (sel->unk_00 != 62) {
        e = gUnk_09EE45DC[sel->unk_00];
        w->tiles3 = AllocObjTiles(0xD80, 0);
        w->palette = LoadObjPalette(e[w->messageDef->unk_08].palette, 32);
        SetObjTileSource(w->tiles3, e[w->messageDef->unk_08].tiles);
        AnimInit(w->anim, e[w->messageDef->unk_08].anims, e[w->messageDef->unk_08].gfxTable);
        AnimStart(w->anim, 0, e[w->messageDef->unk_08].unk_11);
        w->gfx = AnimGetGfx(w->anim);
        w->unk_11C = gUnk_09033CD0[w->messageDef->unk_04];
        w->unk_120 = gUnk_09033CF0[w->messageDef->unk_04];
    } else {
        w->tiles3 = 0;
        w->palette = 0;
    }

    SetTaskUpdate(a, (void*)func_080A3558);
    return 1;
}
void func_080A3848(UnkStruct_080A3F5C* w) {
    void** p;

    if (w->unk_149 != 0) {
        func_0806C2C0(w->unk_141);
    }

    if (w->tiles3 != 0) {
        if (w->unk_14D != 0) {
            DrawSprite(w->unk_11C >> 8, w->unk_120 >> 8, w->gfx, w->tiles3, w->palette, 0, 1, 0);
        } else {
            DrawSprite(w->unk_11C >> 8, w->unk_120 >> 8, w->gfx, w->tiles3, w->palette, 0, 0, 0);
        }

        if (w->tiles4 != 0 && w->unk_148 != 0) {
            DrawSprite(gUnk_09033D08[w->messageDef->unk_04][0] >> 8, gUnk_09033D08[w->messageDef->unk_04][1] >> 8,
                       w->gfx2, w->tiles4, w->palette2, 0, 0, 10);
        }
    }

    if (w->tiles != 0) {
        DrawSprite(w->unk_124 >> 8, w->gfx4 >> 8, w->gfx3, w->tiles, w->palette3, 0, 1, 9);
    }

    if (w->tiles2 != 0) {
        p = &gUnk_09EF126C;
        DrawSprite(120, 80, p[1], w->tiles2, w->palette4, 0, 0, 10);
        DrawTextSlots((240 - w->unk_146[0] * 10) >> 1, 67, w->unk_020, w->unk_0C0, 0, w->unk_146[0]);
        DrawTextSlots((240 - w->unk_146[1] * 10) >> 1, 82, w->unk_070, w->unk_0C0, 0, w->unk_146[1]);
    }
}

void func_080A3A04(UnkStruct_080A3F5C* w) {
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

    if (w->palette3 != 0) {
        ReleaseObjPalette(w->palette3);
    }

    if (w->tiles2 != 0) {
        ReleaseObjTiles(w->tiles2);
    }

    if (w->palette4 != 0) {
        ReleaseObjPalette(w->palette4);
    }

    if (w->unk_0C0 != 0) {
        ReleaseObjPalette((u8*)w->unk_0C0);
    }

    FreeTextSlots((TextSlot*)w->unk_020, 10);
    FreeTextSlots((TextSlot*)w->unk_070, 10);
    gUnk_0203A9D4 = 0;
    gUnk_02034AFC = 0;
}

u8 func_080A3A98(UnkStruct_080A3F5C* w, void* a) {
    CardMessageDef* sel;
    const MsgFaceAnim* e;

    w->gfx = AnimUpdate(w->anim);

    if (GetKeysPressed() & A_BUTTON) {
        w->unk_141 = w->unk_143;
    }

    w->unk_142++;
    sel = w->messageDef;

    if (w->unk_142 >= sel->unk_0A) {
        if (w->unk_141 < w->unk_143) {
            w->unk_141++;
            m4aSongNumStart(SONG_SYS_MESSAGE);
        } else {
            e = gUnk_09EE45DC[sel->unk_00];
            AnimStart(w->anim, 0, e[sel->unk_08].unk_11);

            if (w->tiles4 == 0) {
                w->tiles4 = AllocObjTiles(0x40, 0);
                w->palette2 = LoadObjPalette(gUnk_08F69BE4, 32);
                SetObjTileSource(w->tiles4, gUnk_09320796);
                AnimInit(w->anim2, gUnk_09EEFD38, gUnk_09EEFCAC);
                AnimStart(w->anim2, 2, 1);
                w->gfx2 = AnimGetGfx(w->anim2);
            }

            w->unk_148 = 1;
            SetTaskUpdate(a, (void*)func_080A3BB0);
        }

        w->unk_142 = 0;
    }

    return 1;
}
u8 func_080A3BB0(UnkStruct_080A3F5C* w, void* a) {
    const MsgFaceAnim* e;
    u8* pal;

    w->gfx2 = AnimUpdate(w->anim2);
    w->gfx = AnimUpdate(w->anim);
    if (GetKeysPressed() & A_BUTTON) {
        m4aSongNumStart(SONG_SYS_KETTEI);
        if (*(s32*)w->unk_138 != 0) {
#ifdef VERSION_JP
            *((u8*)w + offsetof(UnkStruct_080A3F5C, unk_143)) = func_0806BDB8(gUnk_09033CA8[w->messageDef->unk_04],
                                      gUnk_09033CB8[w->messageDef->unk_04],
                                      *(s32*)w->unk_138, (s32*)w->unk_138);
#else
            *((u8*)w + offsetof(UnkStruct_080A3F5C, unk_143)) = func_0806BB44(gUnk_09033CA8[w->messageDef->unk_04],
                                      gUnk_09033CB8[w->messageDef->unk_04] - 0x200,
                                      *(s32*)w->unk_138, (s32*)w->unk_138);
#endif
            w->unk_142 = 0;
            w->unk_141 = 0;
            e = gUnk_09EE45DC[w->messageDef->unk_00];
            if (e[w->messageDef->unk_08].unk_10 > 1) {
                AnimStart(w->anim, 1, e[w->messageDef->unk_08].unk_11);
            }
            w->unk_148 = 0;
            SetTaskUpdate(a, func_080A3A98);
        } else if (!(w->messageDef->flags & 1)) {
            AnimStart(w->anim2, 3, 1);
            SetTaskUpdate(a, func_080A3DD0);
            w->unk_13E = 0;
            w->unk_140 = 8;
        } else {
            ReleaseObjTiles(w->tiles4);
            ReleaseObjPalette(w->palette2);
            w->tiles4 = 0;
            w->palette2 = 0;
            w->tiles = AllocObjTiles(0x120, 0);
            pal = gUnk_09614418;
            w->palette3 = LoadObjPalette(pal, 32);
            LoadObjPaletteBank(((UnkStruct_080038C8*)w->palette3)->index, pal);
            SetObjTileSource(w->tiles, gUnk_090A4664);
            AnimInit(w->anim3, gUnk_09EEB03C, gUnk_09EEB008);
            AnimStart(w->anim3, 2, 1);
            w->gfx3 = AnimGetGfx(w->anim3);
            w->tiles2 = LoadObjTiles(gUnk_093F7C9C, 0xFC0);
            w->palette4 = LoadObjPalette(gUnk_09611AB8, 32);
            w->unk_144 = 0;
            w->unk_124 = 0x5800;
            w->gfx4 = gUnk_09033D28[w->unk_144];
#ifdef VERSION_EU
            w->unk_146[0] = LoadTextSlots(eu_0805E924(gUnkEu_08890E1C), w->unk_020);
            w->unk_146[1] = LoadTextSlots(eu_0805E924(gUnkEu_08890E44), w->unk_070);
#else
            w->unk_146[0] = LoadTextSlots(gUnk_08159E10, w->unk_020);
            w->unk_146[1] = LoadTextSlots(gUnk_08159E18, w->unk_070);
#endif
            w->unk_0C0 = (s32)_08066468(1);
            SetTaskUpdate(a, func_080A3E8C);
        }
    }
    return 1;
}

u8 func_080A3DD0(UnkStruct_080A3F5C* w) {
    if (w->tiles4 != 0) {
        w->gfx2 = AnimUpdate(w->anim2);
    }

    w->gfx = AnimUpdate(w->anim);
    w->unk_13E++;

    if (w->unk_13E > 15) {
        w->unk_149 = 0;
        w->unk_148 = 0;
        ApproachValue(&w->x, gUnk_09033C98[w->messageDef->unk_04], w->unk_140);
        ApproachValue(&w->unk_11C, gUnk_09033CD0[w->messageDef->unk_04], w->unk_140);
        ScrollBgMapTo(w->unk_10C, w->x, 0);

        if (w->unk_140 == 0) {
            return 0;
        }

        w->unk_140--;
    }

    return 1;
}

u8 func_080A3E8C(UnkStruct_080A3F5C* w, void* a) {
    w->gfx = AnimUpdate(w->anim);
    w->gfx3 = AnimUpdate(w->anim3);

    switch (GetKeysRepeat()) {
    case DPAD_UP:
    case DPAD_DOWN:
        w->unk_144 ^= 1;
        w->unk_145 = 4;
        break;
    case A_BUTTON:
    case START_BUTTON:
        m4aSongNumStart(SONG_SYS_KETTEI);

        if (w->unk_144 == 0) {
            gUnk_0203A9D8 = 1;
        } else {
            gUnk_0203A9D8 = 0;
        }

        SetTaskUpdate(a, (void*)func_080A3DD0);
        break;
    }

    if (w->unk_145 != 0) {
        ApproachValue(&w->gfx4, gUnk_09033D28[w->unk_144], w->unk_145);
        w->unk_145--;
    }

    return 1;
}

u8 func_080A3F5C(UnkStruct_080A3F5C* w, void* a) {
    const MsgFaceAnim* e;

    w->gfx = AnimUpdate(w->anim);

    if (GetKeysPressed() & A_BUTTON) {
        w->unk_141 = w->unk_143;
    }

    w->unk_142++;

    if (w->unk_142 >= w->messageDef->unk_0A) {
        if (w->unk_141 < w->unk_143) {
            w->unk_141++;
            m4aSongNumStart(SONG_SYS_MESSAGE);
        } else {
            e = gUnk_09EE45DC[w->messageDef->unk_00];
            AnimStart(w->anim, 0, e[w->messageDef->unk_08].unk_11);
            SetTaskUpdate(a, (void*)func_080A4010);
        }

        w->unk_142 = 0;
    }

    return 1;
}
u8 func_080A4010(UnkStruct_080A3F5C* w, void* a) {
#ifndef VERSION_JP
    s32* p;
#endif

    w->gfx = AnimUpdate(w->anim);

    if (w->unk_14F == 0) {
        SetTaskUpdate(a, (void*)func_080A3DD0);
    } else if (w->unk_14E == 1) {
        w->unk_14E = 0;
        w->messageDef = &gUnk_09EE8008[*(u16*)&w->unk_110];
#ifdef VERSION_JP
        w->unk_143 = func_0806BDB8(gUnk_09033CA8[w->messageDef->unk_04],
                                   gUnk_09033CB8[w->messageDef->unk_04],
                                   (s32)w->messageDef->text, (s32*)&w->unk_138);
#else
        p = (s32*)&w->unk_138;

        if (*p != 0) {
            w->unk_143 = func_0806BB44(gUnk_09033CA8[w->messageDef->unk_04],
                                       gUnk_09033CB8[w->messageDef->unk_04] - 0x200, *p, p);
        } else {
            w->unk_143 = func_0806BB44(gUnk_09033CA8[w->messageDef->unk_04],
                                       gUnk_09033CB8[w->messageDef->unk_04] - 0x200,
                                       (s32)LANGSTR(w->messageDef->text), p);
        }
#endif

        w->unk_141 = w->unk_143;
    }

    return 1;
}

s32 func_080A40EC(u64* src) {
    if (gUnk_02034AFC != 0) {
        gUnk_02034AFC->unk_10C = *src;
        gUnk_02034AFC->unk_14E = 1;

        return 1;
    }

    return 0;
}

void func_080A411C(void* pool, u32 a, u16 b) {
    UnkStruct_080A4188 args;

    args.unk_00 = a;
    args.unk_04 = b;
    args.unk_07 = 0;

    if (gUnk_09EE8008[b].unk_00 == 62) {
        if (gUnk_09EE8008[b].flags & 2) {
            TaskCreate(pool, &gUnk_09EE8E48, &args);
        } else {
            TaskCreate(pool, &gUnk_09EE8E30, &args);
        }
    } else {
        TaskCreate(pool, &gUnk_09EE8E18, &args);
    }
}

void func_080A4188(void* pool, u16 b) {
    UnkStruct_080A4188 args;

    args.unk_00 = 0;
    args.unk_04 = b;
    args.unk_07 = 2;

    if (gUnk_09EE8008[b].flags & 2) {
        TaskCreate(pool, &gUnk_09EE8E48, &args);
    } else {
        TaskCreate(pool, &gUnk_09EE8E30, &args);
    }
}

void func_080A41F0(void* pool, u16 a) {
    UnkStruct_080A4188 args;

    func_080A42C8();
    args.unk_00 = 0;
    args.unk_04 = a;
    args.unk_07 = 3;
    TaskCreate(pool, &gUnk_09EE8E30, &args);
}

void func_080A4234(void* pool, u32 a, u16 b) {
    UnkStruct_080A4188 args;

    args.unk_00 = a;
    args.unk_04 = b;
    args.unk_07 = 1;

    if (func_080A42C8() != 0) {
        if ((u8)func_080A40EC((u64*)&args) == 0) {
            func_080A4D7C((u64*)&args);
        }
    } else if (gUnk_09EE8008[b].unk_00 == 62) {
        TaskCreate(pool, &gUnk_09EE8E30, &args);
    } else {
        TaskCreate(pool, &gUnk_09EE8E18, &args);
    }
}

void func_080A42B4(void) {
    gUnk_0203A9D4 = 0;
    gUnk_0203A9D8 = 0;
}

u8 func_080A42C8(void) {
    return gUnk_0203A9D4;
}

u8 func_080A42D4(void) {
    return gUnk_0203A9D8;
}

u8 func_080A42E0(void) {
    if (gUnk_02034AFC != 0) {
        gUnk_02034AFC->unk_14F = 0;
        return 1;
    }

    return func_080A4DAC();
}

CardMessageDef gUnk_09EE8008[] = {
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F660F4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0901048C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F5B8,
#endif
        0,
        0,
    },
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66108,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010454,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F642,
#endif
        0,
        0,
    },
    {
        1, 3, 4, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6611C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010410,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F6A2,
#endif
        0,
        0,
    },
    {
        1, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66130,
#elif defined(VERSION_JP)
        gCardMessageTextJp_090103D0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F714,
#endif
        0,
        0,
    },
    {
        1, 3, 3, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66144,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010394,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F778,
#endif
        0,
        0,
    },
    {
        1, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66158,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010348,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F7F0,
#endif
        0,
        0,
    },
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6616C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010314,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F87C,
#endif
        0,
        0,
    },
    {
        1, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66180,
#elif defined(VERSION_JP)
        gCardMessageTextJp_090102E0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F8E4,
#endif
        0,
        0,
    },
    {
        1, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66194,
#elif defined(VERSION_JP)
        gCardMessageTextJp_090102A0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F94C,
#endif
        0,
        0,
    },
    {
        1, 3, 3, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F661A8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010250,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F9BC,
#endif
        0,
        0,
    },
    {
        1, 3, 3, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F661BC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010218,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FA2A,
#endif
        0,
        0,
    },
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F661D0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_090101DC,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FAB2,
#endif
        0,
        0,
    },
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F661E4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_090101A0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FB04,
#endif
        0,
        0,
    },
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F661F8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010184,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FB76,
#endif
        0,
        0,
    },
    {
        1, 3, 3, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6620C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010154,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FBAC,
#endif
        0,
        0,
    },
    {
        1, 3, 4, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66220,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010124,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FBFA,
#endif
        0,
        0,
    },
    {
        1, 3, 2, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66234,
#elif defined(VERSION_JP)
        gCardMessageTextJp_090100E8,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FC6A,
#endif
        0,
        0,
    },
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66248,
#elif defined(VERSION_JP)
        gCardMessageTextJp_090100A4,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FCDE,
#endif
        0,
        0,
    },
    {
        1, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6625C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010078,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FD46,
#endif
        0,
        0,
    },
    {
        1, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66270,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0901003C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FDAA,
#endif
        0,
        0,
    },
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66284,
#elif defined(VERSION_JP)
        gCardMessageTextJp_09010000,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FE34,
#endif
        0,
        0,
    },
    {
        1, 3, 2, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66298,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FFD0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FEA2,
#endif
        0,
        0,
    },
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F662AC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FF8C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FEF8,
#endif
        0,
        0,
    },
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F662C0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FF54,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FF4E,
#endif
        0,
        0,
    },
    {
        1, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F662D4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FF08,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903FFC4,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F662E8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FED0,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040042,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F662FC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FEA0,
#elif defined(VERSION_US)
        gCardMessageTextUs_090400DC,
#endif
        0,
        0,
    },
    {
        2, 3, 3, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66310,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FE58,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040170,
#endif
        0,
        0,
    },
    {
        2, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66324,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FE14,
#elif defined(VERSION_US)
        gCardMessageTextUs_090401E4,
#endif
        0,
        0,
    },
    {
        2, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66338,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FDE8,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904026E,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6634C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FDC0,
#elif defined(VERSION_US)
        gCardMessageTextUs_090402D0,
#endif
        0,
        0,
    },
    {
        2, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66360,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FD8C,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040328,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66374,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FD50,
#elif defined(VERSION_US)
        gCardMessageTextUs_090403A0,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66388,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FD18,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904041C,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6639C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FCD0,
#elif defined(VERSION_US)
        gCardMessageTextUs_090404AA,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F663B0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FC80,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040552,
#endif
        0,
        0,
    },
    {
        2, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F663C4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FC38,
#elif defined(VERSION_US)
        gCardMessageTextUs_090405D8,
#endif
        0,
        0,
    },
    {
        2, 3, 4, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F663D8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FC00,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040662,
#endif
        0,
        0,
    },
    {
        2, 3, 3, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F663EC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FBCC,
#elif defined(VERSION_US)
        gCardMessageTextUs_090406E4,
#endif
        0,
        0,
    },
    {
        2, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66400,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FB90,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040758,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66414,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FB5C,
#elif defined(VERSION_US)
        gCardMessageTextUs_090407B2,
#endif
        0,
        0,
    },
    {
        2, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66428,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FB20,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904083C,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6643C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FAE8,
#elif defined(VERSION_US)
        gCardMessageTextUs_090408CC,
#endif
        0,
        0,
    },
    {
        2, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66450,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FA90,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040932,
#endif
        0,
        0,
    },
    {
        2, 3, 4, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66464,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FA60,
#elif defined(VERSION_US)
        gCardMessageTextUs_090409E6,
#endif
        0,
        0,
    },
    {
        2, 3, 3, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66478,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FA2C,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040A5C,
#endif
        0,
        0,
    },
    {
        2, 3, 2, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6648C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900FA04,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040AEE,
#endif
        0,
        0,
    },
    {
        2, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F664A0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F9C4,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040B46,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F664B4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F998,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040BA8,
#endif
        0,
        0,
    },
    {
        2, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F664C8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F968,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040C0C,
#endif
        0,
        0,
    },
    {
        60, 3, 4, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F664DC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F934,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040C98,
#endif
        0,
        0,
    },
    {
        60, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F664F0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F8F4,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040D0E,
#endif
        0,
        0,
    },
    {
        27, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66504,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F8D0,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040D90,
#endif
        0,
        0,
    },
    {
        36, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F69614,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F8B0,
#elif defined(VERSION_US)
        gEventTextUs_0900868C,
#endif
        1,
        0,
    },
    {
        47, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F68368,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F880,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C10C,
#endif
        0,
        0,
    },
    {
        48, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F68354,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F844,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C186,
#endif
        0,
        0,
    },
    {
        50, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F68340,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F820,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C0D4,
#endif
        0,
        0,
    },
    {
        50, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6832C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F7E0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C060,
#endif
        0,
        0,
    },
    {
        51, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F683A4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F798,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C20C,
#endif
        0,
        0,
    },
    {
        49, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F68390,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F75C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C2F4,
#endif
        0,
        0,
    },
    {
        49, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6837C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F720,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C272,
#endif
        0,
        0,
    },
    {
        61, 3, 4, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6C97C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F6E8,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040DDA,
#endif
        0,
        0,
    },
    {
        61, 3, 1, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6C990,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F6B4,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040E4C,
#endif
        0,
        0,
    },
    {
        61, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6C9A4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F668,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040ED6,
#endif
        0,
        0,
    },
    {
        7, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F660CC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F638,
#elif defined(VERSION_US)
        gCardMessageTextUs_090411BA,
#endif
        0,
        0,
    },
    {
        7, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F660E0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F608,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041224,
#endif
        0,
        0,
    },
    {
        7, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F660B8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F5E8,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041176,
#endif
        0,
        0,
    },
    {
        7, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F660E0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F5C8,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041E66,
#endif
        0,
        0,
    },
    {
        7, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F660E0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F5A0,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041E66,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66068,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F588,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C03C,
#endif
        3,
        0,
    },
    {
        3, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63E44,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F554,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C37E,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63E58,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F50C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C410,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63E6C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F4D4,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C656,
#endif
        0,
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63E80,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F4AC,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C6F0,
#endif
        0,
        0,
    },
    {
        62, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63E94,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F498,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C76E,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63EA8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F424,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C79A,
#endif
        0,
        0,
    },
    {
        62, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63EBC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F40C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C86C,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63ED0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F3A8,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C898,
#endif
        0,
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63EE4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F2E8,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C97C,
#endif
        0,
        0,
    },
    {
        62, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63EF8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F2A8,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903CAD0,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63F0C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F274,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903CB7C,
#endif
        0,
        0,
    },
    {
        62, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63F20,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F40C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903CBE4,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63F34,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F234,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903CC10,
#endif
        0,
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63F48,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F1FC,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903CC80,
#endif
        0,
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63F5C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F1B4,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903CCF2,
#endif
        0,
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63F70,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F180,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903CD96,
#endif
        0,
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63F84,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F134,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903CE0C,
#endif
        0,
        0,
    },
    {
        62, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63F98,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F0EC,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903CEC4,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63FAC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900F010,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903CF58,
#endif
        0,
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63FC0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EF60,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903D0BE,
#endif
        0,
        0,
    },
    {
        62, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63FD4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EF2C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903D1FA,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63FE8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EEE4,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903D294,
#endif
        0,
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F63FFC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EE28,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903D32E,
#endif
        0,
        0,
    },
    {
        62, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64010,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EE00,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903D47A,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        3, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64024,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900ED7C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903D4C2,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64164,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900ED44,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903E7EC,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64178,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900ED0C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903E854,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6418C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900ECD4,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903E8C4,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F641A0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EC94,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903E91C,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F641B4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EC58,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903E9C8,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F641C8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EC14,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903EA78,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F641DC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EBD8,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903EB28,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F641F0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EB18,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903EB8E,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64204,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EAA0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903ED16,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64204,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900EA28,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903ED16,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64218,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E980,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903EE14,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6422C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E914,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903EF68,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64240,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E8E8,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F02C,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64254,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E854,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F098,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64268,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E824,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F180,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6427C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E7F0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F1E2,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64290,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E7C4,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F25A,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F642A4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E768,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F2D0,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F642B8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E710,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F410,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64038,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E648,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903D5E8,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6404C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E5E4,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903D774,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64060,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E528,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903D872,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64074,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E4F4,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903DA40,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64088,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E450,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903DA92,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6409C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E3E8,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903DC44,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F640B0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E398,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903DD36,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F640C4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E364,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903DDCA,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F640D8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E2EC,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903DE28,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F640EC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E240,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903DF44,
#endif
        0,
        0,
    },
    {
        62, 1, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64100,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E210,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903E0CA,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        31, 1, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64114,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E144,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903E142,
#endif
        0,
        0,
    },
    {
        62, 1, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64128,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E0F8,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903E2C8,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        31, 1, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6413C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900E00C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903E370,
#endif
        0,
        0,
    },
    {
        31, 0, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F64150,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DF14,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903E5D4,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F682F0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DED0,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040F4E,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F68304,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DE50,
#elif defined(VERSION_US)
        gCardMessageTextUs_09040FE2,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F68318,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DE04,
#elif defined(VERSION_US)
        gCardMessageTextUs_090410E8,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6459C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DD60,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903C4C2,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66518,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DD34,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041492,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6652C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DCEC,
#elif defined(VERSION_US)
        gCardMessageTextUs_090414BE,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66540,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DCC8,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041522,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66554,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DCA4,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041548,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66568,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DC74,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041568,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6657C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DC20,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041594,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66590,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DBFC,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041606,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F665A4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DBD0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904162C,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F665B8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DBA4,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904165C,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F665CC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DB78,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041690,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F665E0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DB4C,
#elif defined(VERSION_US)
        gCardMessageTextUs_090416C0,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F665F4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DB1C,
#elif defined(VERSION_US)
        gCardMessageTextUs_090416EA,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66608,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DAF0,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041718,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6661C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DAC4,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904174A,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66630,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DA94,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041774,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66644,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DA64,
#elif defined(VERSION_US)
        gCardMessageTextUs_090417A4,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66658,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DA40,
#elif defined(VERSION_US)
        gCardMessageTextUs_090417DA,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6666C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900DA14,
#elif defined(VERSION_US)
        gCardMessageTextUs_090417FC,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66680,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D9E4,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041830,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66694,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D9C0,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904185E,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F666A8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D99C,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041886,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F666BC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D974,
#elif defined(VERSION_US)
        gCardMessageTextUs_090418AC,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F666D0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D948,
#elif defined(VERSION_US)
        gCardMessageTextUs_090418DC,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F666E4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D91C,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904190C,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F666F8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D8F8,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904193C,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6670C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D8CC,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904195C,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66798,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D8B0,
#elif defined(VERSION_US)
        gCardMessageTextUs_090419E2,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66784,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D88C,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041A08,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F667C0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D870,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041A38,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F667E8,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D854,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041A5C,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F667FC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D834,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041AE2,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66810,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D810,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041CAC,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66824,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D7DC,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041B10,
#endif
        1,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66838,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D7C4,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041B6C,
#endif
        1,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F642CC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D728,
#elif defined(VERSION_US)
        gCardMessageTextUs_0903F492,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66748,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D700,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041BA0,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6675C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D6D8,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041BDC,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66770,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D6B4,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041C14,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F6684C,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D68C,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041C46,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F667D4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D670,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041C7C,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66734,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D650,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041D06,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66720,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D650,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041CD6,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F667AC,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D610,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041D38,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F66018,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D5E0,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041D98,
#endif
        0,
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F697E0,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D560,
#elif defined(VERSION_US)
        gCardMessageTextUs_0904128A,
#endif
#if defined(VERSION_EU)
        4,
#elif defined(VERSION_JP)
        0,
#elif defined(VERSION_US)
        4,
#endif
        0,
    },
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_EU)
        &gUnkEu_09F660A4,
#elif defined(VERSION_JP)
        gCardMessageTextJp_0900D500,
#elif defined(VERSION_US)
        gCardMessageTextUs_090413BE,
#endif
        0,
        0,
    },
#ifndef VERSION_EU
    {
        62, 3, 0, 3, 0,
#if defined(VERSION_JP)
        gCardMessageTextJp_0900D4C0,
#elif defined(VERSION_US)
        gCardMessageTextUs_09041DE2,
#endif
        0,
        0,
    },
#endif
};

const char gTaskName_09EE8E18[] = "msgwin";

TaskDesc gUnk_09EE8E18 = {
    gTaskName_09EE8E18,
    (void (*)(void*, void*))func_080A33C4,
    func_080A3640,
    (void (*)(void*))func_080A3848,
    (void (*)(void*))func_080A3A04,
    0x150,
};
