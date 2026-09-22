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
#define LANGSTR(x) (((void**)(x))[gLanguage])
#else
#define LANGSTR(x) (x)
#endif
s32 func_080A22A4(u8* work);

void StockInfo_0(u8* work, void* a) {
    u8 i;

    *(void**)&work[0x14] = a;
    TaskPoolInit(&work[0x18], 1);
    *(void**)&work[0] = LoadObjTiles(gUnk_0908FCEE, 0x12A0);
    *(void**)&work[4] = LoadObjPalette(gUnk_09613F78, 32);

    for (i = 16; i < 32; i++) {
        FadeSetPaletteExcluded(i, 1);
    }

    *(s32*)&work[8] = 0x4C00;
    *(s32*)&work[0xC] = 0xBC00;
    work[0x10] = 16;

    switch (gGameState.progression.unk_80) {
    case 0:
        func_0800FB2C(0);
        break;
    case 1:
        func_0800FB2C(2);
        break;
    case 2:
        func_0800FB2C(4);
        break;
    case 3:
        func_0800FB2C(1);
        break;
    case 4:
        func_0800FB2C(5);
        break;
    case 5:
        func_0800FB2C(3);
        break;
    case 6:
        func_0800FB2C(36);
        break;
    case 7:
        func_0800FB2C(6);
        break;
    case 8:
        func_0800FB2C(46);
        break;
    case 9:
        func_0800FB2C(7);
        break;
    case 10:
        func_0800FB2C(32);
        break;
    }
}

u8 StockInfo_1(u8* work, void* a) {
    if ((s8)work[0x10] > 0) {
        ApproachValue(&work[0x0C], 0x6C00, (u16)(s8)work[0x10]);
        work[0x10]--;
    } else {
        m4aSongNumStart(0xCA);
        func_080D8EB4(&work[0x18], gUnk_0903BFBC[gGameState.progression.unk_80], 0, 0, 0x50);
        SetTaskUpdate(a, (void*)func_080A22A4);
    }

    return 1;
}

s32 func_080A22A4(u8* work) {
    if ((*(u8**)&work[0x14])[0] == 0) {
        return 0;
    }

    TaskPoolUpdate(&work[0x18]);
    return 1;
}
void StockInfo_2(u8* work) {
    DrawSprite(*(s32*)&work[0x08] >> 8, *(s32*)&work[0x0C] >> 8, gUnk_09EEA28C,
               *(void**)&work[0x00], *(void**)&work[0x04], 0, 0, 50);
    TaskPoolDraw(&work[0x18]);
}
void StockInfo_3(u8* work) {
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjPalette(*(void**)&work[0x04]);
    gGameState.progression.unk_80++;
    TaskPoolDestroy(&work[0x18]);
}

void* func_080A2334(u16 a, u8 b) {
    if (b < gUnk_09EE7D84[a]->unk_04) {
        return LANGSTR(gUnk_09EE7D84[a]->texts[b]);
    }

    return 0;
}

u8 func_080A235C(u16 a) {
    return gUnk_09EE7D84[a]->unk_04;
}
u8 func_080A2370(void) {
    if (gGameState.progression.level >= gUnk_0903BFD4[gGameState.progression.unk_80]) {
        return 1;
    }

    return 0;
}
