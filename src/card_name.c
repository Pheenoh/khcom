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

void* gUnk_02034AD4;

u8 gUnk_02034AD8;

u8 gUnk_02034AD9;

u8 gUnk_02034ADA[6];

void func_0809D124(PremiumCardEffectWork* w);
void func_0809D1B0(PremiumCardEffectWork* w);
void func_0809D160(PremiumCardEffectWork* w);
#ifdef VERSION_JP
extern u8 gUnkJp_09009748[];
extern u8 gUnkJp_0900974C[];
#endif
#ifdef VERSION_EU
extern u8 gUnkEu_090CF64D[];
#endif
void CardName_0(CardNameWork* w) {
    UnkStruct_0809C534* q = gUnk_0203A9D0->selectedCard;
    UnkStruct_080038C8* pal;
    s32 v;
    s16 t;

    InitTextSlots(w->unk_08, 32);
    InitTextSlots(w->unk_108, 32);
#ifdef VERSION_EU
    InitTextSlots(w->unk_208, 32);
#else
    InitTextSlots(w->unk_208, 2);
#endif
    w->unk_218 = _08066468(1);
#ifdef VERSION_EU
    w->unk_226 = LoadTextSlots(eu_0805E924(q->cardDef->name), w->unk_08);
    w->unk_227 = LoadTextSlots((u16*)gUnkEu_09F6602C.strings[gLanguage], w->unk_108);
#else
    w->unk_226 = LoadTextSlots(q->cardDef->name, w->unk_08);
#ifdef VERSION_JP
    w->unk_228 = LoadTextSlots((u16*)gUnkJp_09009748, w->unk_208);
    w->unk_227 = LoadTextSlots((u16*)gUnkJp_0900974C, w->unk_108);
#else
    w->unk_227 = LoadTextSlots((u16*)&gUnk_09036278[22], w->unk_108);
#endif
#endif
#ifndef VERSION_JP
    w->palette = LoadObjPalette(gUnk_09614798, 32);
#endif
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
    case 2:
    case 3:
        w->unk_228 = 0;
        v = (230 - GetTextSlotsWidth(w->unk_08, w->unk_226)) / 2;
        w->unk_220 = v;
        t = (u16)w->unk_220 + GetTextSlotsWidth(w->unk_08, w->unk_226);
        w->unk_224 = t;
        v = (240 - GetTextSlotsWidth(w->unk_108, w->unk_227)) / 2;
        w->unk_222 = v;
        break;
    case 1:
        w->unk_228 = LoadTextSlots((u16*)&gUnk_09036278[22], w->unk_208);
        v = (230 - GetTextSlotsWidth(w->unk_08, w->unk_226)) / 2;
        w->unk_220 = v;
        t = (u16)w->unk_220 + GetTextSlotsWidth(w->unk_08, w->unk_226);
        w->unk_224 = t;
        v = (240 - GetTextSlotsWidth(w->unk_108, w->unk_227)) / 2;
        w->unk_222 = v;
        break;
    case 4:
        w->unk_228 = LoadTextSlots((u16*)gUnkEu_090CF64D, w->unk_208);
        v = (230 - GetTextSlotsWidth(w->unk_08, w->unk_226)) / 2;
        w->unk_220 = v;
        w->unk_224 = v - 3;
        v = (240 - GetTextSlotsWidth(w->unk_108, w->unk_227)) / 2;
        w->unk_222 = v;
        break;
    default:
        w->unk_228 = 0;
        break;
    }
#else
    v = (230 - GetTextSlotsWidth(w->unk_08, w->unk_226)) / 2;
    w->unk_220 = v;
    t = (u16)w->unk_220 + GetTextSlotsWidth(w->unk_08, w->unk_226);
    w->unk_224 = t;
    v = (240 - GetTextSlotsWidth(w->unk_108, w->unk_227)) / 2;
    w->unk_222 = v;
#endif
    w->tiles = LoadObjTiles(&gUnk_093F8C8E[0xC1E], 0x1800);
    pal = LoadObjPalette(gUnk_09611AB8, 32);
    w->unk_04 = pal;
    FadeSetPaletteExcluded(pal->index + 16, 1);
    FadeSetPaletteExcluded(((UnkStruct_080038C8*)w->unk_218)->index + 16, 1);
}
s32 CardName_1(void) {
    return 1;
}
#ifdef VERSION_EU
#define CARDNAME(off) ((off) + 0xF0)
#else
#define CARDNAME(off) (off)
#endif
#ifdef VERSION_JP
#define CARDNAME_PAL0 0x218
#else
#define CARDNAME_PAL0 CARDNAME(0x21C)
#endif
void CardName_2(u8* work) {
    void** p = &gUnk_09EF1278[2];

    DrawSprite(120, 126, *p, *(void**)&work[0x00], *(void**)&work[0x04], 0, 0, 50);
    DrawTextSlots(*(s16*)&work[CARDNAME(0x220)], 115, &work[0x08], *(void**)&work[CARDNAME_PAL0], 30, work[CARDNAME(0x226)]);
#ifndef VERSION_US
    DrawTextSlots(*(s16*)&work[CARDNAME(0x224)], 115, &work[0x208], *(void**)&work[CARDNAME(0x218)], 30, work[CARDNAME(0x228)]);
#endif
    DrawTextSlots(*(s16*)&work[CARDNAME(0x222)], 130, &work[0x108], *(void**)&work[CARDNAME(0x218)], 30, work[CARDNAME(0x227)]);
}
void CardName_3(u8* work) {
    FreeTextSlots((TextSlot*)&work[0x08], 32);
    FreeTextSlots((TextSlot*)&work[0x108], 32);
#ifdef VERSION_EU
    FreeTextSlots((TextSlot*)&work[0x208], 32);
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjPalette(*(void**)&work[0x308]);
    ReleaseObjPalette(*(void**)&work[0x04]);
    ReleaseObjPalette(*(void**)&work[0x30C]);
#else
    FreeTextSlots((TextSlot*)&work[0x208], 2);
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjPalette(*(void**)&work[0x218]);
    ReleaseObjPalette(*(void**)&work[0x04]);
#ifndef VERSION_JP
    ReleaseObjPalette(*(void**)&work[0x21C]);
#endif
#endif
}

void func_0809CE88(PremiumCardEffectWork* w, s16* a) {
    w->tiles = AllocObjTiles(128, 0);
    w->palette = LoadObjPalette(gUnk_09619158, 32);
    SetObjTileSource(w->tiles, gUnk_093F762E);
    AnimInit(&w->anim, gUnk_09EF1260, gUnk_09EF1230);
    AnimStart(&w->anim, GetRandom() % 3, 1);
    w->gfx = AnimGetGfx(&w->anim);
    w->unk_24 = a[1] << 8;
    w->unk_28 = a[2] << 8;
    w->unk_2C = 0;
    w->unk_40 = a[0] << 8;
    w->unk_3C = a[3];
    w->unk_4C = GetRandom() % 0x181 + 0x100;
    w->x = 0;
    w->y = 0;
    w->unk_38 = 0;
    w->unk_50 = -(GetRandom() % 0x81 + 0x200);
    gUnk_0203A9D0->effectCount++;
}

void func_0809CF64(PremiumCardEffectWork* w, s16* a) {
    w->tiles = AllocObjTiles(128, 0);
    w->palette = LoadObjPalette(gUnk_09619158, 32);
    SetObjTileSource(w->tiles, gUnk_093F762E);
    AnimInit(&w->anim, gUnk_09EF1260, gUnk_09EF1230);
    AnimStart(&w->anim, GetRandom() % 3, 1);
    w->gfx = AnimGetGfx(&w->anim);
    w->unk_24 = a[1] << 8;
    w->unk_28 = a[2] << 8;
    w->unk_2C = 0;
    w->unk_40 = a[0] << 8;
    w->unk_3C = a[3];
    w->unk_4C = GetRandom() % 0x81 + 0x200;
    w->x = 0;
    w->y = 0;
    w->unk_38 = 0;
    w->unk_50 = -(GetRandom() % 0x81 + 0x200);
    func_0809D124(w);
    gUnk_0203A9D0->effectCount++;
}

s32 func_0809D040(PremiumCardEffectWork* w) {
    func_0809D124(w);
    w->unk_3C += 8;

    if (w->unk_40 > 0) {
        w->unk_40 += -0x180;
        w->gfx = AnimUpdate(&w->anim);
        return 1;
    }

    return 0;
}
s32 Premire_EFFECT2_1(PremiumCardEffectWork* w) {
    func_0809D160(w);
    w->gfx = AnimUpdate(&w->anim);

    if (w->y > 0xB400) {
        return 0;
    }

    return 1;
}
s32 func_0809D09C(PremiumCardEffectWork* w) {
    func_0809D1B0(w);
    w->unk_3C += 8;
    w->gfx = AnimUpdate(&w->anim);

    if (w->unk_40 <= 0x800) {
        return 0;
    }

    return 1;
}
void func_0809D0CC(PremiumCardEffectWork* w) {
    DrawSprite(w->x >> 8, w->y >> 8, w->gfx, w->tiles, w->palette, 0, 0, 0);
}
void func_0809D0FC(PremiumCardEffectWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    gUnk_0203A9D0->effectCount--;
}

void func_0809D124(PremiumCardEffectWork* w) {
    w->x = gSineTable[w->unk_3C & 0xFF] * (w->unk_40 >> 8) + w->unk_24;
    w->y = -gSineTable[(w->unk_3C & 0xFF) + 64] * (w->unk_40 >> 8) + w->unk_28;
}

void func_0809D160(PremiumCardEffectWork* w) {
    w->unk_50 += 30;
    w->unk_2C += w->unk_50;
    w->unk_24 += gSineTable[w->unk_3C & 0xFF] * (w->unk_4C >> 8);
    w->unk_28 += -gSineTable[(w->unk_3C & 0xFF) + 64] * (w->unk_4C >> 8);
    w->x = w->unk_24;
    w->y = w->unk_28 + w->unk_2C;
}

void func_0809D1B0(PremiumCardEffectWork* w) {
    s32 v;
    s32 d;

    w->unk_44 = w->unk_24 - w->x;
    w->unk_48 = w->unk_28 - w->y;
    w->unk_40 = NormalizeVector2D8(&w->unk_44, &w->unk_48);
    v = w->unk_4C;
    d = v >> 8;
    w->x += w->unk_44 * d;
    w->y += w->unk_48 * d;

    if (w->unk_40 > 0) {
        w->unk_4C = v - 2;
    }
}

void func_0809D1FC(u8 bg) {
    void** p;

    SetBgScroll(bg, 0, 0);
    SetBackdropColor(0, 0, 0);
    LoadBgTiles(bg, gUnk_09036380, 0x1C00);
    LoadBgMap(bg, gUnk_08125E24, 0x800);
    LoadBgPalette(bg, gUnk_09036300, 0x80);
    EnableBg(bg);
    gUnk_02034AD9 = bg;
    p = &gUnk_02034AD4;
    *p = EwramAlloc(0x880);
}

void func_0809D26C(void) {
    EwramFree(gUnk_02034AD4);
}

u8 func_0809D280(u8* p) {
    u8 n;

    n = 0;

    if (p == 0) {
        return 0;
    }

    while (*p++ != 0) {
        if (*p != 0) {
            n++;
        }
    }

    return n + 1;
}

void func_0809D2B0(u8 a, u8 b, u8 c, u8* s) {
    u8 n;
    u8 i;

    if (gUnk_02034AD8 < 32) {
        n = func_0809D280(s);

        if (n > 32) {
            n = 32;
        }

        for (i = 0; i < n; i++) {
            ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_04[i] = s[i];
            ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_04[i] |= c << 12;
        }

        ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_01 = a;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_02 = b;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_03 = c;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_00 = n;
        RequestTilemapRectCopy(((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_04, (void*)GetBgScreenBase(gUnk_02034AD9), 0, 0,
                      ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_01,
                      ((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_02,
                      (s8)((UnkStruct_02034AD4*)gUnk_02034AD4)[gUnk_02034AD8].unk_00, 1);
        gUnk_02034AD8++;
    }
}

void func_0809D3F0(void) {
    gUnk_02034AD8 = 0;
}

void func_0809D3FC(void) {
    s16 i;

    for (i = 0; i < gUnk_02034AD8; i++) {
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[i].unk_00 = 0;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[i].unk_01 = 0;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[i].unk_02 = 0;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[i].unk_03 = 0;
        ((UnkStruct_02034AD4*)gUnk_02034AD4)[i].unk_04[0] = 0;
    }

    gUnk_02034AD8 = 0;
}

void func_0809D458(u16 x, u16 y, u16 color, s32 value) {
    s32 digits[8];
    u8 text[10];
    s32 i;

    if (value >= 0) {
        digits[0] = value / 10000000;
        digits[1] = value / 1000000 - 10 * digits[0];
        digits[2] = value / 100000 - 100 * digits[0] - 10 * digits[1];
        digits[3] = value / 10000 - 1000 * digits[0] - 100 * digits[1] - 10 * digits[2];
        digits[4] = value / 1000 - 10000 * digits[0] - 1000 * digits[1] - 100 * digits[2] - 10 * digits[3];
        digits[5] = value / 100 - 100000 * digits[0] - 10000 * digits[1] - 1000 * digits[2] - 100 * digits[3] - 10 * digits[4];
        digits[6] = value / 10 - 1000000 * digits[0] - 100000 * digits[1] - 10000 * digits[2] - 1000 * digits[3] - 100 * digits[4] - 10 * digits[5];
        digits[7] = value - (10000000 * digits[0] + 1000000 * digits[1] + 100000 * digits[2] + 10000 * digits[3] + 1000 * digits[4] + 100 * digits[5] + 10 * digits[6]);
        text[0] = digits[0] + '0';
        text[1] = digits[1] + '0';
        text[2] = digits[2] + '0';
        text[3] = digits[3] + '0';
        text[4] = digits[4] + '0';
        text[5] = digits[5] + '0';
        text[6] = digits[6] + '0';
        text[7] = digits[7] + '0';
        text[8] = 0;
        i = 0;

        if (text[i] <= '0') {
            do {
                i++;

                if (i > 6) {
                    break;
                }
            } while (text[i] <= '0');
        }

        func_0809D2B0(x, y, color, &text[i]);
    } else {
        digits[0] = value / -10000000;
        digits[1] = value / -1000000 - 10 * digits[0];
        digits[2] = value / -100000 - 100 * digits[0] - 10 * digits[1];
        digits[3] = value / -10000 - 1000 * digits[0] - 100 * digits[1] - 10 * digits[2];
        digits[4] = value / -1000 - 10000 * digits[0] - 1000 * digits[1] - 100 * digits[2] - 10 * digits[3];
        digits[5] = value / -100 - 100000 * digits[0] - 10000 * digits[1] - 1000 * digits[2] - 100 * digits[3] - 10 * digits[4];
        digits[6] = value / -10 - 1000000 * digits[0] - 100000 * digits[1] - 10000 * digits[2] - 1000 * digits[3] - 100 * digits[4] - 10 * digits[5];
        digits[7] = -value - (10000000 * digits[0] + 1000000 * digits[1] + 100000 * digits[2] + 10000 * digits[3] + 1000 * digits[4] + 100 * digits[5] + 10 * digits[6]);
        text[0] = '-';
        text[1] = digits[0] + '0';
        text[2] = digits[1] + '0';
        text[3] = digits[2] + '0';
        text[4] = digits[3] + '0';
        text[5] = digits[4] + '0';
        text[6] = digits[5] + '0';
        text[7] = digits[6] + '0';
        text[8] = digits[7] + '0';
        text[9] = 0;
        i = 1;

        if (text[i] <= '0') {
            do {
                i++;

                if (i > 7) {
                    break;
                }
            } while (text[i] <= '0');
        }

        text[--i] = '-';
        func_0809D2B0(x, y, color, &text[i]);
    }
}

void func_0809D87C(u16 a, u16 b, u16 c, u16 bits) {
    u16 v[16];
    u8 s[17];
    u16 i;
    u16 j;

    for (i = 0, j = 15; i < 16; i++, j--) {
        v[i] = bits & (1 << i);
        s[j] = (v[i] >> i) + '0';
    }

    s[16] = 0;
    func_0809D2B0(a, b, c, s);
}

void func_0809D900(u16 a, u16 b, u16 c, u32 v) {
    u8 s[11];
    s32 i;

    s[0] = '0';
    s[1] = 'x';
    s[2] = v >> 28;
    s[3] = (v & 0x0F000000) >> 24;
    s[4] = (v & 0x00F00000) >> 20;
    s[5] = (v & 0x000F0000) >> 16;
    s[6] = (v & 0x0000F000) >> 12;
    s[7] = (v & 0x00000F00) >> 8;
    s[8] = (v & 0x000000F0) >> 4;
    s[9] = v & 0x0000000F;

    for (i = 0; i < 8; i++) {
        s[i + 2] += s[i + 2] <= 9 ? '0' : '7';
    }

    s[10] = 0;
    func_0809D2B0(a, b, c, s);
}

const char gTaskName_09EE7834[] = "CardName";

TaskDesc gUnk_09EE7834 = {
    gTaskName_09EE7834,
    (void (*)(void*, void*))CardName_0,
    CardName_1,
    (void (*)(void*))CardName_2,
    (void (*)(void*))CardName_3,
#ifdef VERSION_EU
    0x31C,
#else
    0x22C,
#endif
};

const char gTaskName_09EE784C[] = "Premire_EFFECT";

TaskDesc gUnk_09EE784C = {
    gTaskName_09EE784C,
    (void (*)(void*, void*))func_0809CE88,
    func_0809D040,
    (void (*)(void*))func_0809D0CC,
    (void (*)(void*))func_0809D0FC,
    0x54,
};

const char gTaskName_09EE7864[] = "Premire_EFFECT2";

TaskDesc gUnk_09EE7864 = {
    gTaskName_09EE7864,
    (void (*)(void*, void*))func_0809CE88,
    Premire_EFFECT2_1,
    (void (*)(void*))func_0809D0CC,
    (void (*)(void*))func_0809D0FC,
    0x54,
};

TaskDesc gUnk_09EE787C = {
    gTaskName_09EE784C,
    (void (*)(void*, void*))func_0809CF64,
    func_0809D09C,
    (void (*)(void*))func_0809D0CC,
    (void (*)(void*))func_0809D0FC,
    0x54,
};
