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
#include "sprites_boss_tm.h"
#include "link_menus.h"

s8 gUnk_0203A9E4 EWRAM_COMMON(4);

u8 gUnk_0203A9E8 EWRAM_COMMON(4);

static void** gUnk_02034B38;

void func_0809D1FC(u8 bg);
void func_0809D26C(void);
void func_0809D3F0(void);
void task_print_0(void) {
    func_0809D1FC(0);
}
s32 task_print_1(void) {
    return 1;
}
void task_print_2(void) {
    func_0809D3F0();
}
void task_print_3(void) {
    func_0809D26C();
}
void mode_sio_battle_0(s32 a) {
    UnkStruct_02034B38* w;
    void* gfx;
    s32 i;

    gUnk_02034B38 = EwramAlloc(sizeof(UnkStruct_02034B38));
    FadeStartIn(0, 16);
    SetBgMode0();
    SetupBg(0, 0, 7, 0);
    SetupBg(1, 0, 31, 0);
    LoadBgTiles(1, gUnk_096ACA44, 0xBC0);
    LoadBgPalette(1, gUnk_096FBA04, 64);
    LoadBgMap(1, gUnk_096F5464, 0x800);
    EnableBg(1);
    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_01 = 0;
    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02 = 0;
    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_04 = 0;
    ((UnkStruct_02034B38*)gUnk_02034B38)->x = -0x8000;
    ((UnkStruct_02034B38*)gUnk_02034B38)->y = -0x800;
    ((UnkStruct_02034B38*)gUnk_02034B38)->y2 = 0xA000;
    ((UnkStruct_02034B38*)gUnk_02034B38)->tiles = LoadObjTiles(gUnk_0962AD62, 0x240);
    ((UnkStruct_02034B38*)gUnk_02034B38)->palette = LoadObjPalette(gUnk_096FBA44, 32);

    for (i = 0; i < 3; i++) {
        ((UnkStruct_02034B38*)gUnk_02034B38)->gfx2[i] = gUnk_09EF3884[i];
    }

#ifdef VERSION_EU
    ((UnkStruct_02034B38*)gUnk_02034B38)->palette2 = LoadObjPalette(gUnk_096FBA64, 32);
    ((UnkStruct_02034B38*)gUnk_02034B38)->palette3 = LoadObjPalette(gUnk_096FBA84, 32);

    switch (gLanguage) {
    case 0:
        ((UnkStruct_02034B38*)gUnk_02034B38)->tiles2 = LoadObjTiles(gUnkEu_095EDAAA, 0x600);
        ((UnkStruct_02034B38*)gUnk_02034B38)->tiles3 = LoadObjTiles(gUnkEu_095EE0E2, 0x600);
        break;
    case 3:
        ((UnkStruct_02034B38*)gUnk_02034B38)->tiles2 = LoadObjTiles(gUnkEu_095EFFFA, 0x600);
        ((UnkStruct_02034B38*)gUnk_02034B38)->tiles3 = LoadObjTiles(gUnkEu_095F0632, 0x600);
        break;
    case 1:
        ((UnkStruct_02034B38*)gUnk_02034B38)->tiles2 = LoadObjTiles(gUnkEu_095EE71A, 0x600);
        ((UnkStruct_02034B38*)gUnk_02034B38)->tiles3 = LoadObjTiles(gUnkEu_095EED52, 0x600);
        break;
    case 4:
        ((UnkStruct_02034B38*)gUnk_02034B38)->tiles2 = LoadObjTiles(gUnkEu_095EF38A, 0x600);
        ((UnkStruct_02034B38*)gUnk_02034B38)->tiles3 = LoadObjTiles(gUnkEu_095EF9C2, 0x600);
        break;
    case 2:
    default:
        ((UnkStruct_02034B38*)gUnk_02034B38)->tiles2 = LoadObjTiles(gUnkEu_095F0C6A, 0x600);
        ((UnkStruct_02034B38*)gUnk_02034B38)->tiles3 = LoadObjTiles(gUnkEu_095F12A2, 0x600);
        break;
    }
#else
    ((UnkStruct_02034B38*)gUnk_02034B38)->tiles2 = LoadObjTiles(gUnk_0962B286, 0x600);
    ((UnkStruct_02034B38*)gUnk_02034B38)->palette2 = LoadObjPalette(gUnk_096FBA64, 32);
    ((UnkStruct_02034B38*)gUnk_02034B38)->tiles3 = LoadObjTiles(gUnk_0962B8BE, 0x600);
    ((UnkStruct_02034B38*)gUnk_02034B38)->palette3 = LoadObjPalette(gUnk_096FBA84, 32);
#endif
    ((UnkStruct_02034B38*)gUnk_02034B38)->tiles4 = LoadObjTiles(gUnk_0962B090, 0x1C0);
    ((UnkStruct_02034B38*)gUnk_02034B38)->palette4 = LoadObjPalette(gUnk_096FBAA4, 32);
    AnimInit(&((UnkStruct_02034B38*)gUnk_02034B38)->anim, gUnk_09EF38B4, gUnk_09EF3894);
    AnimStart(&((UnkStruct_02034B38*)gUnk_02034B38)->anim, 1, 1);
    gfx = AnimGetGfx(&((UnkStruct_02034B38*)gUnk_02034B38)->anim);
    w = (UnkStruct_02034B38*)gUnk_02034B38;
    w->gfx = gfx;
    w->unk_68 = a;

    switch (w->unk_68) {
    case 0:
    case 1:
        if (w->unk_68 == 0) {
            if (gUnk_0203A9E8 != 1) {
                gUnk_0203A9E8 = 0;
                w->unk_00 = 1;
            } else {
                gUnk_0203A9E8 = 1;
                w->unk_00 = 0;
            }
        } else {
            gUnk_0203A9E8 = 1;
            w->unk_00 = 0;
        }

#ifdef VERSION_EU
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_64 = ((UnkStruct_02034B38*)gUnk_02034B38)->unk_00 * 0x1C00 + 0x3300;

        switch (gLanguage) {
        case 0:
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnkEu_09F7EB38[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnkEu_09F7EB44[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            break;
        case 3:
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnkEu_09F7EB80[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnkEu_09F7EB8C[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            break;
        case 1:
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnkEu_09F7EB50[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnkEu_09F7EB5C[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            break;
        case 4:
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnkEu_09F7EB68[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnkEu_09F7EB74[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            break;
        case 2:
        default:
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnkEu_09F7EB98[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnkEu_09F7EBA4[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            break;
        }
#else
        ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnk_09EF38BC[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
        ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnk_09EF38C8[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_64 = ((UnkStruct_02034B38*)gUnk_02034B38)->unk_00 * 0x1C00 + 0x3300;
#endif
        break;
    case 2:
#ifdef VERSION_EU
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_64 = ((UnkStruct_02034B38*)gUnk_02034B38)->unk_00 * 0x1C00 + 0x3300;
        gUnk_0203A9E8 = 1;
        w->unk_00 = 0;

        switch (gLanguage) {
        case 0:
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnkEu_09F7EB38[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnkEu_09F7EB44[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            break;
        case 3:
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnkEu_09F7EB80[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnkEu_09F7EB8C[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            break;
        case 1:
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnkEu_09F7EB50[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnkEu_09F7EB5C[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            break;
        case 4:
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnkEu_09F7EB68[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnkEu_09F7EB74[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            break;
        case 2:
        default:
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnkEu_09F7EB98[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnkEu_09F7EBA4[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            break;
        }
#else
        w->unk_00 = 0;
        ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnk_09EF38BC[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
        ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnk_09EF38C8[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_64 = ((UnkStruct_02034B38*)gUnk_02034B38)->unk_00 * 0x1C00 + 0x3300;
        gUnk_0203A9E8 = 1;
#endif
        break;
    case 3:
        w->unk_00 = 0;
#ifdef VERSION_EU
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_64 = ((UnkStruct_02034B38*)gUnk_02034B38)->unk_00 * 0x1C00 + 0x3300;
        gUnk_0203A9E8 = 1;

        switch (gLanguage) {
        case 0:
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnkEu_09F7EB38[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnkEu_09F7EB44[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            break;
        case 3:
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnkEu_09F7EB80[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnkEu_09F7EB8C[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            break;
        case 1:
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnkEu_09F7EB50[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnkEu_09F7EB5C[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            break;
        case 4:
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnkEu_09F7EB68[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnkEu_09F7EB74[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            break;
        case 2:
        default:
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnkEu_09F7EB98[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnkEu_09F7EBA4[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            break;
        }
#else
        ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnk_09EF38BC[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
        ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnk_09EF38C8[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_64 = ((UnkStruct_02034B38*)gUnk_02034B38)->unk_00 * 0x1C00 + 0x3300;
        gUnk_0203A9E8 = 1;
#endif
        break;
    case 0xFFFF:
        break;
    }

    gUnk_0203C374 = 0;
    gUnk_0203A9E4 = 0;
}

void mode_sio_battle_1(void) {
    switch ((s8)((UnkStruct_02034B38*)gUnk_02034B38)->unk_01) {
    case 0:
        if ((s16)((UnkStruct_02034B38*)gUnk_02034B38)->unk_04 == 0) {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02 = 16;
        }

        ApproachValue(&((UnkStruct_02034B38*)gUnk_02034B38)->y, 0, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02);
        ApproachValue(&((UnkStruct_02034B38*)gUnk_02034B38)->y2, 0x9800, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02);
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02--;

        if ((s16)((UnkStruct_02034B38*)gUnk_02034B38)->unk_02 > 0) {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_04++;
        } else {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_01 = 1;
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_04 = 0;
        }
        break;
    case 1:
        if ((s16)((UnkStruct_02034B38*)gUnk_02034B38)->unk_04 == 0) {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02 = 16;
        }

        ApproachValue(&((UnkStruct_02034B38*)gUnk_02034B38)->x, 0, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02);
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02--;

        if ((s16)((UnkStruct_02034B38*)gUnk_02034B38)->unk_02 > 0) {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_04++;
        } else {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_01 = 5;
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_04 = 0;
        }
        break;
    case 5:
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_01 = 6;
        break;
    case 6:
        if (gUnk_0203A9E8 == 1) {
            if (GetKeysPressed() & 0x40) {
                m4aSongNumStart(101);
                ((UnkStruct_02034B38*)gUnk_02034B38)->unk_00--;

                if (((UnkStruct_02034B38*)gUnk_02034B38)->unk_00 < 0) {
                    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_00 = 1;
                }
            }

            if (GetKeysPressed() & 0x80) {
                m4aSongNumStart(101);
                ((UnkStruct_02034B38*)gUnk_02034B38)->unk_00++;

                if (((UnkStruct_02034B38*)gUnk_02034B38)->unk_00 > 1) {
                    ((UnkStruct_02034B38*)gUnk_02034B38)->unk_00 = 0;
                }
            }
        } else {
            if (GetKeysPressed() & 0xC0) {
                m4aSongNumStart(105);
            }
        }

#ifdef VERSION_EU
        switch (gLanguage) {
        case 0:
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnkEu_09F7EB38[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnkEu_09F7EB44[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            break;
        case 3:
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnkEu_09F7EB80[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnkEu_09F7EB8C[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            break;
        case 1:
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnkEu_09F7EB50[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnkEu_09F7EB5C[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            break;
        case 4:
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnkEu_09F7EB68[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnkEu_09F7EB74[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            break;
        case 2:
        default:
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnkEu_09F7EB98[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnkEu_09F7EBA4[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
            break;
        }
#else
        ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3 = gUnk_09EF38BC[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
        ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4 = gUnk_09EF38C8[((UnkStruct_02034B38*)gUnk_02034B38)->unk_00];
#endif

        if (GetKeysPressed() & 9) {
            m4aSongNumStart(102);

            switch (((UnkStruct_02034B38*)gUnk_02034B38)->unk_00) {
            case 0:
                ModeRequest(&gModeSioBtlConnect, 0);
                break;
            case 1:
                ModeRequest(&gModeMenuLoad, 1);
                break;
            }
        }

        if (GetKeysPressed() & 2) {
            m4aSongNumStart(104);
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_01 = 2;
        }
        break;
    case 2:
        if ((s16)((UnkStruct_02034B38*)gUnk_02034B38)->unk_04 == 0) {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02 = 16;
        }

        ApproachValue(&((UnkStruct_02034B38*)gUnk_02034B38)->x, -0x8000, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02);
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02--;

        if ((s16)((UnkStruct_02034B38*)gUnk_02034B38)->unk_02 > 0) {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_04++;
        } else {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_01 = 3;
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_04 = 0;
        }
        break;
    case 3:
        if ((s16)((UnkStruct_02034B38*)gUnk_02034B38)->unk_04 == 0) {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02 = 16;
        }

        ApproachValue(&((UnkStruct_02034B38*)gUnk_02034B38)->y, -0x800, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02);
        ApproachValue(&((UnkStruct_02034B38*)gUnk_02034B38)->y2, 0xA000, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02);
        ((UnkStruct_02034B38*)gUnk_02034B38)->unk_02--;

        if ((s16)((UnkStruct_02034B38*)gUnk_02034B38)->unk_02 > 0) {
            ((UnkStruct_02034B38*)gUnk_02034B38)->unk_04++;
        } else {
            ModeRequest(&gModeTitle, 0);
            return;
        }
        break;
    }

    ((UnkStruct_02034B38*)gUnk_02034B38)->gfx = AnimUpdate(&((UnkStruct_02034B38*)gUnk_02034B38)->anim);
    DrawSprite(((UnkStruct_02034B38*)gUnk_02034B38)->x >> 8, 0, ((UnkStruct_02034B38*)gUnk_02034B38)->gfx2[0], ((UnkStruct_02034B38*)gUnk_02034B38)->tiles, ((UnkStruct_02034B38*)gUnk_02034B38)->palette, 0, 0x400, -16);
    DrawSprite(128, ((UnkStruct_02034B38*)gUnk_02034B38)->y >> 8, ((UnkStruct_02034B38*)gUnk_02034B38)->gfx2[1], ((UnkStruct_02034B38*)gUnk_02034B38)->tiles, ((UnkStruct_02034B38*)gUnk_02034B38)->palette, 0, 0x400, -1);
    DrawSprite(128, ((UnkStruct_02034B38*)gUnk_02034B38)->y2 >> 8, ((UnkStruct_02034B38*)gUnk_02034B38)->gfx2[2], ((UnkStruct_02034B38*)gUnk_02034B38)->tiles, ((UnkStruct_02034B38*)gUnk_02034B38)->palette, 0, 0x400, -1);
    DrawSprite(72, 48, ((UnkStruct_02034B38*)gUnk_02034B38)->gfx3, ((UnkStruct_02034B38*)gUnk_02034B38)->tiles2, ((UnkStruct_02034B38*)gUnk_02034B38)->palette2, 0, 0x400, -32);
    DrawSprite(72, 48, ((UnkStruct_02034B38*)gUnk_02034B38)->gfx4, ((UnkStruct_02034B38*)gUnk_02034B38)->tiles3, ((UnkStruct_02034B38*)gUnk_02034B38)->palette3, 0, 0x400, -32);
    ApproachValueHalf(&((UnkStruct_02034B38*)gUnk_02034B38)->unk_64, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_00 * 7 * 1024 + 0x3300);
    DrawSprite(64, ((UnkStruct_02034B38*)gUnk_02034B38)->unk_64 >> 8, ((UnkStruct_02034B38*)gUnk_02034B38)->gfx, ((UnkStruct_02034B38*)gUnk_02034B38)->tiles4, ((UnkStruct_02034B38*)gUnk_02034B38)->palette4, 0, 0x400, -48);
}

void mode_sio_battle_2(void) {
    ReleaseObjTiles(gUnk_02034B38[5]);
    ReleaseObjPalette(gUnk_02034B38[6]);
    ReleaseObjTiles(gUnk_02034B38[10]);
    ReleaseObjPalette(gUnk_02034B38[11]);
    ReleaseObjTiles(gUnk_02034B38[13]);
    ReleaseObjPalette(gUnk_02034B38[14]);
    ReleaseObjTiles(gUnk_02034B38[16]);
    ReleaseObjPalette(gUnk_02034B38[17]);
    EwramFree(gUnk_02034B38);
}

void func_080AEB94(void) {
    gUnk_0203A9E8 = 0;
}

const char gTaskNamePrint[] = "task_print";

TaskDesc gTaskDescPrint = {
    gTaskNamePrint,
    (void (*)(void*, void*))task_print_0,
    task_print_1,
    (void (*)(void*))task_print_2,
    (void (*)(void*))task_print_3,
    0x4,
};
