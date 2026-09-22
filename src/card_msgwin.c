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

    if (GetKeysPressed() & 1) {
        w->unk_141 = w->unk_143;
    }

    w->unk_142++;
    sel = w->messageDef;

    if (w->unk_142 >= sel->unk_0A) {
        if (w->unk_141 < w->unk_143) {
            w->unk_141++;
            m4aSongNumStart(0x74);
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
    if (GetKeysPressed() & 1) {
        m4aSongNumStart(102);
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
        } else if (!(w->messageDef->unk_10 & 1)) {
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
    case 0x40:
    case 0x80:
        w->unk_144 ^= 1;
        w->unk_145 = 4;
        break;
    case 1:
    case 8:
        m4aSongNumStart(0x66);

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

    if (GetKeysPressed() & 1) {
        w->unk_141 = w->unk_143;
    }

    w->unk_142++;

    if (w->unk_142 >= w->messageDef->unk_0A) {
        if (w->unk_141 < w->unk_143) {
            w->unk_141++;
            m4aSongNumStart(0x74);
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
        if (gUnk_09EE8008[b].unk_10 & 2) {
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

    if (gUnk_09EE8008[b].unk_10 & 2) {
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
