#include "macros.h"
#include "card_localized_data.h"
#include "card_localized_09EE9C90_data.h"
#include "card_lookup_09EEA344_data.h"
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
        CreateStockMesDispTask(&work[0x18], gUnk_0903BFBC[gGameState.progression.unk_80], 0, 0, 0x50);
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

const CardHelpDef* gUnk_09EE7D84[] = {
    &gUnk_0903BD0C,
    &gUnk_0903BD14,
    &gUnk_0903BD1C,
    &gUnk_0903BD24,
    &gUnk_0903BD2C,
    &gUnk_0903BD34,
    &gUnk_0903BD3C,
    &gUnk_0903BD44,
    &gUnk_0903BD4C,
    &gUnk_0903BD54,
    &gUnk_0903BD5C,
    &gUnk_0903BD64,
    &gUnk_0903BD6C,
    &gUnk_0903BD74,
    &gUnk_0903BD84,
    &gUnk_0903BD7C,
    &gUnk_0903BD8C,
    &gUnk_0903BD94,
    &gUnk_0903BD9C,
    &gUnk_0903BDA4,
    &gUnk_0903BDAC,
    &gUnk_0903BDB4,
    &gUnk_0903BDBC,
    &gUnk_0903BDC4,
    &gUnk_0903BDCC,
    &gUnk_0903BDD4,
    &gUnk_0903BDDC,
    &gUnk_0903BDE4,
    &gUnk_0903BDEC,
    &gUnk_0903BDF4,
    &gUnk_0903BDFC,
    &gUnk_0903BE04,
    &gUnk_0903BE0C,
    &gUnk_0903BE14,
    &gUnk_0903BE1C,
    &gUnk_0903BE24,
    &gUnk_0903BE2C,
    &gUnk_0903BE34,
    &gUnk_0903BE3C,
    &gUnk_0903BE44,
    &gUnk_0903BE4C,
    &gUnk_0903BE54,
    &gUnk_0903BE5C,
    &gUnk_0903BE64,
    &gUnk_0903BE6C,
    &gUnk_0903BE74,
    &gUnk_0903BE7C,
    &gUnk_0903BE84,
    &gUnk_0903BE8C,
    &gUnk_0903BE94,
    &gUnk_0903BE9C,
    &gUnk_0903BEA4,
    &gUnk_0903BEAC,
    &gUnk_0903BEB4,
    &gUnk_0903BEBC,
    &gUnk_0903BEC4,
    &gUnk_0903BECC,
#if defined(VERSION_US) || defined(VERSION_JP)
    &gUnk_0903BED4,
#elif defined(VERSION_EU)
    0,
#endif
    &gUnk_0903BEDC,
    &gUnk_0903BEE4,
    &gUnk_0903BEEC,
    &gUnk_0903BEF4,
    &gUnk_0903BEFC,
    &gUnk_0903BF04,
    &gUnk_0903BF0C,
    &gUnk_0903BF14,
    &gUnk_0903BF1C,
    &gUnk_0903BF24,
#if defined(VERSION_US) || defined(VERSION_JP)
    &gUnk_0903BF2C,
#elif defined(VERSION_EU)
    0,
#endif
    &gUnk_0903BF34,
    &gUnk_0903BF3C,
    &gUnk_0903BF44,
    &gUnk_0903BF4C,
    &gUnk_0903BF54,
    &gUnk_0903BF5C,
    &gUnk_0903BF64,
    &gUnk_0903BF6C,
    &gUnk_0903BF74,
    &gUnk_0903BF7C,
    &gUnk_0903BF84,
    &gUnk_0903BF8C,
    &gUnk_0903BF94,
    &gUnk_0903BF9C,
    &gUnk_0903BFA4,
    &gUnk_0903BFAC,
#if defined(VERSION_US) || defined(VERSION_JP)
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
    &gUnk_0903BFB4,
#endif
};

const char gTaskNameStockInfo[] = "StockInfo";

TaskDesc gTaskDescStockInfo = {
    gTaskNameStockInfo,
    (void (*)(void*, void*))StockInfo_0,
    StockInfo_1,
    (void (*)(void*))StockInfo_2,
    (void (*)(void*))StockInfo_3,
    0x2C,
};
