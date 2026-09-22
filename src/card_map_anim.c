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

Deck gDecks[3] EWRAM_COMMON(16);

u16 gCardCollection[999] EWRAM_COMMON(16);

Deck* gUnk_0203A850 EWRAM_COMMON(4);

void* gUnk_0203A854 EWRAM_COMMON(4);

u16 gCardCount EWRAM_COMMON(4);

Deck* sub_08083EFC(void);
extern u8* gUnk_02039DC8;

void map_anim_0(MapTileAnimationWork* p) {
    u8 i;

    p->definition = gUnk_09EE4A2C[*(s32*)&gUnk_02039DC8[0x44]];

    if (p->definition != 0) {
        for (i = 0; i < p->definition->trackCount; i++) {
            p->frameTimers[i] = 0;
            p->frameIndices[i] = 0;
        }
    }

    p->unk_00 = 0;
}

u8 map_anim_1(MapTileAnimationWork* w) {
    const MapTileAnimationDef* a;
    const MapTileAnimationTrack* e;
    const MapTileAnimationFrame* f;
    const MapTileAnimationFrame* f2;
    u8 i;
    u8* dst;

    a = w->definition;

    if (a == 0) {
        return 1;
    }

    for (i = w->unk_00; i < (a = w->definition)->trackCount; i++) {
        e = &a->tracks[i];
        f = &e->frames[w->frameIndices[i]];
        w->frameTimers[i]++;

        if (w->frameTimers[i] == f->duration) {
            w->frameIndices[i]++;

            if (w->frameIndices[i] == e->frameCount) {
                w->frameIndices[i] = 0;
            }

            f2 = &e->frames[w->frameIndices[i]];
            dst = (u8*)GetBgCharBase(3) + 0x7000;
            RequestDma3Copy(e->tiles + f2->tileOffset, dst + e->destOffset, e->copySize);
            w->frameTimers[i] = 0;
        }
    }

    return 1;
}

void map_anim_2(void) {
}
void map_anim_3(void) {
}

Deck* func_08083C94(void) {
    Deck* active;
    void** p;
    s32 i;

    active = GetActiveDeck();
    p = &gUnk_0203A854;
    *p = EwramAlloc(sizeof(Deck));

    for (i = 0; i < 99; i++) {
        ((Deck*)gUnk_0203A854)->cards[i] |= 0xFFFF;
    }

    for (i = 0; i < 99; i++) {
        if (active->cards[i] != 0xFFFF) {
            ((Deck*)gUnk_0203A854)->cards[i] = gCardCollection[active->cards[i]];
        } else {
            ((Deck*)gUnk_0203A854)->cards[i] |= 0xFFFF;
        }
    }

    for (i = 0; i < 20; i++) {
        ((Deck*)gUnk_0203A854)->unk_C6[i] = gDecks[GetActiveDeckIndex()].unk_C6[i];
    }

    ((Deck*)gUnk_0203A854)->unk_DA = GetDeckCpCost(GetActiveDeckIndex());
    ((Deck*)gUnk_0203A854)->unk_DC = GetDeckCardCount(GetActiveDeckIndex());
    return gUnk_0203A854;
}

void func_08083D68(void) {
    EwramFree(gUnk_0203A854);
}

Deck* func_08083D7C(void) {
    s32 i;

    gUnk_0203A850 = EwramAlloc(sizeof(Deck));

    for (i = 0; i < 99; i++) {
        gUnk_0203A850->cards[i] |= 0xFFFF;
    }

    for (i = 0; i < 20; i++) {
        gUnk_0203A850->unk_C6[i] = 0;
    }

    gUnk_0203A850->unk_DA = 0;
    gUnk_0203A850->unk_DC = 0;
    return gUnk_0203A850;
}

void func_08083DD4(void) {
    EwramFree(gUnk_0203A850);
}

u16 func_08083DE8(void) {
    return gUnk_0203A850->unk_DC;
}

u16 func_08083DF8(u8 slot) {
    u16* cards;
    u16 count;
    u16 i;

    count = 0;
    cards = gUnk_0203A850->cards;

    for (i = 0; i < DECK_SIZE; i++) {
        if (cards[i] != 0xFFFF) {
            if (gCardDefs[cards[i] & CARD_ID_MASK].unk_2A == slot) {
                count++;
            }
        }
    }

    return count;
}

u16 func_08083E54(u8 mode) {
    u8 slot;
    u16* cards;
    u16 count;
    u16 i;

    count = 0;
    cards = gUnk_0203A850->cards;

    switch (mode) {
    case 0:
        for (i = 0; i < DECK_SIZE; i++) {
            if (cards[i] != 0xFFFF) {
                slot = gCardDefs[cards[i] & CARD_ID_MASK].unk_2A;

                if (slot <= 2) {
                    count++;
                }
            }
        }
        break;
    case 3:
        for (i = 0; i < DECK_SIZE; i++) {
            if (cards[i] != 0xFFFF) {
                if (gCardDefs[cards[i] & CARD_ID_MASK].unk_2A == 3) {
                    count++;
                }
            }
        }
        break;
    }

    return count;
}

Deck* sub_08083EFC(void) {
    return gUnk_0203A850;
}

void func_08083F08(u8 kind, u16* out) {
    Deck* deck;
    u16 i;

    deck = sub_08083EFC();

    for (i = 0; i < 99; i++) {
        if (deck->cards[i] != 0xFFFF) {
            switch (kind) {
            case 0:
                if (gCardDefs[deck->cards[i] & CARD_ID_MASK].unk_2A <= 2) {
                    *out++ = deck->cards[i];
                }
                break;
            case 3:
                if (gCardDefs[deck->cards[i] & CARD_ID_MASK].unk_2A == 3) {
                    *out++ = deck->cards[i];
                }
                break;
            }
        }
    }
}

void func_08083F84(u16 a) {
    s16 v;

    v = func_08084458(a);

    if (gCardDefs[a].unk_20 + GetDeckCpCost(GetActiveDeckIndex()) <=
            gGameState.progression.cp &&
        v != -1) {
        AddCardToActiveDeck(v);
    }
}

void InitCardCollection(void) {
    u16 i;

    for (i = 0; i < 999; i++) {
        gCardCollection[i] = CARD_ID_MASK;
    }

    gCardCount = 911;
}

u16 CountCardsById(u16 cardId) {
    u16 i;
    u16 count;

    i = 0;
    count = 0;

    for (; i < gCardCount; i++) {
        if ((gCardCollection[i] & CARD_ID_MASK) == cardId) {
            count++;
        }
    }
    
    return count;
}

s16 func_08084068(u16 cardId) {
    u16 i;

    i = 0;

    if (CountCardsById(cardId) > 98) {
        return -1;
    }

    while (gCardCollection[i] != CARD_ID_MASK) {
        i++;

        if (i == gCardCount) {
            return -1;
        }
    }

    if (gCardDefs[cardId & CARD_ID_MASK].unk_1E & 8) {
        return -1;
    }

    gCardCollection[i] = cardId;

    return i;
}

s32 func_080840E4(void) {
    s32 count;
    s32 i;

    count = 0;

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] == CARD_ID_MASK) {
            count++;
        }
    }

    if (count > 0) {
        return 0;
    }

    return 1;
}

void func_08084124(u16 cardId) {
    u16 v;
    u8 n;

    v = gCardDefs[cardId & CARD_ID_MASK].unk_1C;

    if (v > 0x61) {
        if (gCardCount > 999) {
            gCardCount = 999;
        }
        return;
    }

    switch (v) {
    case 0:
        n = 119;
        break;
    case 8:
        n = 127;
        break;
    case 1:
        n = 120;
        break;
    case 2:
        n = 121;
        break;
    case 3:
        n = 122;
        break;
    case 4:
        n = 123;
        break;
    case 5:
        n = 124;
        break;
    case 6:
        n = 125;
        break;
    case 7:
        n = 126;
        break;
    case 9:
        n = 128;
        break;
    case 10:
        n = 129;
        break;
    case 11:
        n = 130;
        break;
    case 12:
        n = 131;
        break;
    case 13:
        n = 132;
        break;
    case 16:
        n = 133;
        break;
    case 14:
        n = 134;
        break;
    case 15:
        n = 135;
        break;
    case 18:
        n = 136;
        break;
    case 19:
        n = 137;
        break;
    case 20:
        n = 138;
        break;
    case 21:
        n = 139;
        break;
    case 22:
        n = 140;
        break;
    case 23:
        n = 141;
        break;
    case 24:
        n = 142;
        break;
    case 25:
        n = 143;
        break;
    case 26:
        n = 144;
        break;
    case 27:
        n = 145;
        break;
    case 28:
        n = 146;
        break;
    case 29:
        n = 147;
        break;
    case 30:
        n = 148;
        break;
    case 31:
        n = 149;
        break;
    case 32:
        n = 150;
        break;
    case 33:
        n = 151;
        break;
    case 34:
        n = 152;
        break;
    case 35:
        n = 153;
        break;
    case 36:
        n = 154;
        break;
    case 37:
        n = 155;
        break;
    case 38:
        n = 156;
        break;
    case 47:
        n = 164;
        break;
    case 50:
        n = 165;
        break;
    case 51:
        n = 166;
        break;
    case 52:
        n = 167;
        break;
    case 53:
        n = 168;
        break;
    case 61:
        n = 169;
        break;
    case 73:
        n = 170;
        break;
    case 74:
        n = 171;
        break;
    case 48:
        n = 172;
        break;
    case 54:
        n = 173;
        break;
    case 55:
        n = 174;
        break;
    case 56:
        n = 175;
        break;
    case 57:
        n = 176;
        break;
    case 59:
        n = 177;
        break;
    case 60:
        n = 178;
        break;
    case 62:
        n = 179;
        break;
    case 64:
        n = 180;
        break;
    case 65:
        n = 181;
        break;
    case 66:
        n = 182;
        break;
    case 67:
        n = 183;
        break;
    case 68:
        n = 184;
        break;
    case 70:
        n = 185;
        break;
    case 71:
        n = 186;
        break;
    case 72:
        n = 187;
        break;
    case 49:
        n = 188;
        break;
    case 58:
        n = 189;
        break;
    case 63:
        n = 190;
        break;
    case 69:
        n = 191;
        break;
    case 76:
        n = 192;
        break;
    case 77:
        n = 193;
        break;
    case 75:
        n = 194;
        break;
    case 81:
        n = 204;
        break;
    case 78:
        n = 195;
        break;
    case 86:
        n = 200;
        break;
    case 80:
        n = 197;
        break;
    case 79:
        n = 201;
        break;
    case 85:
        n = 198;
        break;
    case 87:
        n = 199;
        break;
    case 89:
        n = 203;
        break;
    case 88:
        n = 202;
        break;
    case 84:
        n = 196;
        break;
    case 90:
        n = 247;
        break;
    case 91:
        n = 206;
        break;
    case 92:
        n = 205;
        break;
    case 93:
        n = 207;
        break;
    case 94:
        n = 208;
        break;
    case 82:
    case 83:
        n = 246;
        break;
    case 96:
        n = 248;
        break;
    case 97:
        n = 249;
        break;
    default:
        if (gCardCount > 999) {
            gCardCount = 999;
        }
        return;
    }

    if (func_0800FF00(n) == 0) {
        gCardCount++;
    }

    if (gCardCount > 999) {
        gCardCount = 999;
    }
}

s16 func_08084458(u16 cardId) {
    u16 i = 0;

    if (CountCardsById(cardId) > 98) {
        return -1;
    }
    func_08084124(cardId);
    while (gCardCollection[i] != CARD_ID_MASK) {
        i++;
        if (i == gCardCount) {
            return -1;
        }
    }
    if (gCardDefs[cardId & CARD_ID_MASK].unk_1E & 8) {
        return -1;
    }
    gCardCollection[i] = cardId;
    switch (gCardDefs[cardId & CARD_ID_MASK].unk_1C) {
    case 0:
        func_0800FC14(0);
        func_0800FDD0(119);
        break;
    case 8:
        func_0800FC14(8);
        func_0800FDD0(127);
        break;
    case 1:
        func_0800FC14(1);
        func_0800FDD0(120);
        break;
    case 2:
        func_0800FC14(2);
        func_0800FDD0(121);
        break;
    case 3:
        func_0800FC14(3);
        func_0800FDD0(122);
        break;
    case 4:
        func_0800FC14(4);
        func_0800FDD0(123);
        break;
    case 5:
        func_0800FC14(5);
        func_0800FDD0(124);
        break;
    case 6:
        func_0800FC14(6);
        func_0800FDD0(125);
        break;
    case 7:
        func_0800FC14(7);
        func_0800FDD0(126);
        break;
    case 9:
        func_0800FC14(9);
        func_0800FDD0(128);
        break;
    case 10:
        func_0800FC14(10);
        func_0800FDD0(129);
        break;
    case 11:
        func_0800FC14(11);
        func_0800FDD0(130);
        break;
    case 12:
        func_0800FC14(12);
        func_0800FDD0(131);
        break;
    case 13:
        func_0800FC14(13);
        func_0800FDD0(132);
        break;
    case 16:
        func_0800FC14(14);
        func_0800FDD0(133);
        break;
    case 14:
        func_0800FC14(15);
        func_0800FDD0(134);
        break;
    case 15:
        func_0800FC14(16);
        func_0800FDD0(135);
        break;
    case 18:
        func_0800FC14(17);
        func_0800FB2C(9);
        func_0800FB2C(10);
        func_0800FDD0(136);
        break;
    case 19:
        func_0800FC14(18);
        func_0800FB2C(11);
        func_0800FB2C(12);
        func_0800FDD0(137);
        break;
    case 20:
        func_0800FC14(19);
        func_0800FB2C(13);
        func_0800FB2C(14);
        func_0800FDD0(138);
        break;
    case 21:
        func_0800FC14(20);
        func_0800FB2C(15);
        func_0800FB2C(16);
        func_0800FDD0(139);
        break;
    case 22:
        func_0800FC14(21);
        func_0800FB2C(17);
        func_0800FB2C(18);
        func_0800FDD0(140);
        break;
    case 23:
        func_0800FC14(22);
        func_0800FB2C(19);
        func_0800FB2C(20);
        func_0800FDD0(141);
        break;
    case 24:
        func_0800FC14(23);
        func_0800FB2C(21);
        func_0800FB2C(22);
        func_0800FDD0(142);
        break;
    case 25:
        func_0800FC14(24);
        func_0800FB2C(47);
        func_0800FDD0(143);
        func_0800FDD0(23);
        break;
    case 26:
        func_0800FC14(25);
        func_0800FB2C(52);
        func_0800FDD0(144);
        break;
    case 27:
        func_0800FC14(26);
        func_0800FB2C(49);
        func_0800FB2C(50);
        func_0800FDD0(145);
        func_0800FDD0(25);
        break;
    case 28:
        func_0800FC14(27);
        func_0800FB2C(48);
        func_0800FDD0(146);
        func_0800FDD0(24);
        break;
    case 29:
        func_0800FC14(28);
        func_0800FB2C(53);
        func_0800FDD0(147);
        break;
    case 30:
        func_0800FC14(29);
        func_0800FB2C(51);
        func_0800FDD0(148);
        func_0800FDD0(26);
        break;
    case 31:
        func_0800FC14(30);
        func_0800FB2C(54);
        func_0800FB2C(55);
        func_0800FDD0(149);
        break;
    case 32:
        func_0800FC14(31);
        func_0800FDD0(150);
        break;
    case 33:
        func_0800FC14(32);
        func_0800FDD0(151);
        break;
    case 34:
        func_0800FC14(33);
        func_0800FDD0(152);
        break;
    case 35:
        func_0800FC14(34);
        func_0800FDD0(153);
        break;
    case 36:
        func_0800FC14(35);
        func_0800FDD0(154);
        break;
    case 37:
        func_0800FC14(36);
        func_0800FDD0(155);
        break;
    case 38:
        func_0800FC14(37);
        func_0800FDD0(156);
        break;
    case 47:
        func_0800FDD0(164);
        break;
    case 50:
        func_0800FDD0(165);
        break;
    case 51:
        func_0800FDD0(166);
        break;
    case 52:
        func_0800FDD0(167);
        break;
    case 53:
        func_0800FDD0(168);
        break;
    case 61:
        func_0800FDD0(169);
        break;
    case 73:
        func_0800FDD0(170);
        break;
    case 74:
        func_0800FDD0(171);
        break;
    case 48:
        func_0800FDD0(172);
        break;
    case 54:
        func_0800FDD0(173);
        break;
    case 55:
        func_0800FDD0(174);
        break;
    case 56:
        func_0800FDD0(175);
        break;
    case 57:
        func_0800FDD0(176);
        break;
    case 59:
        func_0800FDD0(177);
        break;
    case 60:
        func_0800FDD0(178);
        break;
    case 62:
        func_0800FDD0(179);
        break;
    case 64:
        func_0800FDD0(180);
        break;
    case 65:
        func_0800FDD0(181);
        break;
    case 66:
        func_0800FDD0(182);
        break;
    case 67:
        func_0800FDD0(183);
        break;
    case 68:
        func_0800FDD0(184);
        break;
    case 70:
        func_0800FDD0(185);
        break;
    case 71:
        func_0800FDD0(186);
        break;
    case 72:
        func_0800FDD0(187);
        break;
    case 49:
        func_0800FDD0(188);
        break;
    case 58:
        func_0800FDD0(189);
        break;
    case 63:
        func_0800FDD0(190);
        break;
    case 69:
        func_0800FDD0(191);
        break;
    case 76:
        func_0800FDD0(192);
        break;
    case 77:
        func_0800FDD0(193);
        break;
    case 75:
        func_0800FDD0(194);
        break;
    case 81:
        func_0800FDD0(204);
        break;
    case 78:
        func_0800FDD0(195);
        break;
    case 86:
        func_0800FDD0(200);
        break;
    case 80:
        func_0800FDD0(197);
        break;
    case 79:
        func_0800FDD0(201);
        break;
    case 85:
        func_0800FDD0(198);
        break;
    case 87:
        func_0800FDD0(199);
        break;
    case 89:
        func_0800FDD0(203);
        break;
    case 88:
        func_0800FDD0(202);
        break;
    case 84:
        func_0800FDD0(196);
        break;
    case 90:
        func_0800FDD0(247);
        break;
    case 91:
        func_0800FDD0(206);
        break;
    case 92:
        func_0800FDD0(205);
        break;
    case 93:
        func_0800FDD0(207);
        break;
    case 94:
        func_0800FDD0(208);
        break;
    case 82:
    case 83:
        func_0800FDD0(246);
        break;
    case 96:
        func_0800FDD0(248);
        break;
    case 97:
        func_0800FDD0(249);
        break;
    }
    func_08084AC8(gCardDefs[cardId].unk_1C);
    return i;
}

void func_08084AC8(u16 a) {
    if (gGameState.flags & 8) {
        switch (a) {
        case 0x51:
            func_0800FC14(44);
            break;
        case 0x4E:
            func_0800FC14(38);
            break;
        case 0x56:
            func_0800FC14(45);
            break;
        case 0x50:
            func_0800FC14(40);
            break;
        case 0x4F:
            func_0800FC14(42);
            break;
        case 0x55:
            func_0800FC14(39);
            break;
        case 0x57:
            func_0800FC14(41);
            break;
        case 0x59:
            func_0800FC14(43);
            break;
        case 0x58:
            func_0800FC14(48);
            break;
        case 0x54:
            func_0800FC14(50);
            break;
        case 0x5A:
            func_0800FC14(51);
            break;
        case 0x5D:
            func_0800FC14(54);
            break;
        case 0x60:
            func_0800FC14(57);
            break;
        }
    }
}

u16 func_08084BAC(void) {
    u16 count;
    u16 i;

    count = i = 0;

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] != CARD_ID_MASK) {
            count++;
        }
    }

    return count;
}

u16 func_08084BF0(void) {
    u16 count;
    u16 i;

    count = i = 0;

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] != CARD_ID_MASK && (gCardCollection[i] & 0x7000)) {
            count++;
        }
    }

    return count;
}

u16 func_08084C40(u8 deck, u8 mode, u16* out) {
    u16 count;
    u16 total;
    u16 mask;
    u16* present;
    u16 i;
    u32 zero;

    mask = total = count = 0;
    present = EwramAlloc(0x23C);
    zero = 0;
    CpuSet(&zero, present, 0x0500008F);

    if (mode == 1) {
        switch (deck) {
        case 0:
            mask = 0x1000;
            break;
        case 1:
            mask = 0x2000;
            break;
        case 2:
            mask = 0x4000;
            break;
        }
    } else {
        mask = 0x7000;
    }

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] == CARD_ID_MASK) {
            continue;
        }
        if (gCardCollection[i] & mask) {
            continue;
        }
        if (!(gCardCollection[i] & 0x8000)) {
            present[gCardDefs[gCardCollection[i] & CARD_ID_MASK].unk_1C] = 1;
        } else {
            present[gCardDefs[gCardCollection[i] & CARD_ID_MASK].unk_1C + 0x8F] = 1;
        }
    }

    for (i = 0; i < 0x11E; i++) {
        if (present[i] != 0) {
            total += present[i];
            out[count++] = i;
        }
    }

    EwramFree(present);
    return total;
}

extern u8 gUnk_098EB224[];
extern u8 gUnk_098EAF64[];
extern u8 gUnk_098EADE4[];
extern u8 gUnk_098EACC4[];
extern u8 gUnk_098EAA84[];
extern u8 gUnk_098EA844[];
extern u8 gUnk_094F4238[];
extern u8 gUnk_094EABF8[];
extern u8 gUnk_0948A918[];
extern u8 gUnk_09469B58[];
extern u8 gUnk_09468FF8[];

const MapTileAnimationFrame gUnk_09035348[4] = {
    {0, 18, 0},
    {1024, 12, 0},
    {2048, 12, 0},
    {1024, 12, 0},
};

const MapTileAnimationFrame gUnk_09035358[4] = {
    {0, 15, 0},
    {3232, 15, 0},
    {6464, 15, 0},
    {9696, 15, 0},
};

const MapTileAnimationTrack gUnk_09035368[2] = {
    {gUnk_09035348, gUnk_09468FF8, 4, 0, 3232, 864, {0, 0}},
    {gUnk_09035358, gUnk_09469B58, 4, 0, 0, 3232, {0, 0}},
};

const MapTileAnimationDef gUnk_09035388 = {
    gUnk_09035368, 2, 1, 0,
};

const MapTileAnimationFrame gUnk_09035390[4] = {
    {0, 70, 0},
    {192, 7, 0},
    {384, 15, 0},
    {192, 7, 0},
};

const MapTileAnimationFrame gUnk_090353A0[4] = {
    {0, 25, 0},
    {192, 7, 0},
    {384, 15, 0},
    {192, 7, 0},
};

const MapTileAnimationFrame gUnk_090353B0[4] = {
    {0, 10, 0},
    {96, 10, 0},
    {192, 10, 0},
    {96, 10, 0},
};

const MapTileAnimationFrame gUnk_090353C0[4] = {
    {0, 50, 0},
    {128, 7, 0},
    {256, 10, 0},
    {128, 10, 0},
};

const MapTileAnimationFrame gUnk_090353D0[4] = {
    {0, 10, 0},
    {352, 20, 0},
    {0, 7, 0},
    {352, 150, 0},
};

const MapTileAnimationFrame gUnk_090353E0[4] = {
    {0, 50, 0},
    {128, 5, 0},
    {0, 7, 0},
    {128, 5, 0},
};

const MapTileAnimationTrack gUnk_090353F0[6] = {
    {gUnk_09035390, gUnk_098EA844, 4, 0, 2048, 192, {0, 0}},
    {gUnk_090353A0, gUnk_098EAA84, 4, 0, 2240, 192, {0, 0}},
    {gUnk_090353B0, gUnk_098EACC4, 4, 0, 2432, 96, {0, 0}},
    {gUnk_090353C0, gUnk_098EADE4, 4, 0, 2528, 128, {0, 0}},
    {gUnk_090353D0, gUnk_098EAF64, 4, 0, 3072, 352, {0, 0}},
    {gUnk_090353E0, gUnk_098EB224, 4, 0, 3424, 128, {0, 0}},
};

const MapTileAnimationDef gUnk_09035450 = {
    gUnk_090353F0, 6, 0, 0,
};

const MapTileAnimationFrame gUnk_09035458[5] = {
    {0, 6, 0},
    {1024, 6, 0},
    {2048, 6, 0},
    {3072, 6, 0},
    {4096, 6, 0},
};

const MapTileAnimationTrack gUnk_0903546C = {
    gUnk_09035458, gUnk_0948A918, 5, 0, 3072, 896, {0, 0},
};

const MapTileAnimationDef gUnk_0903547C = {
    &gUnk_0903546C, 1, 1, 0,
};

const MapTileAnimationFrame gUnk_09035484[4] = {
    {0, 30, 0},
    {3072, 30, 0},
    {6144, 30, 0},
    {9216, 30, 0},
};

const MapTileAnimationTrack gUnk_09035494 = {
    gUnk_09035484, gUnk_094EABF8, 4, 0, -15360, 3072, {0, 0},
};

const MapTileAnimationDef gUnk_090354A4 = {
    &gUnk_09035494, 1, 1, 0,
};

const MapTileAnimationFrame gUnk_090354AC[6] = {
    {0, 20, 0},
    {1024, 20, 0},
    {2048, 20, 0},
    {3072, 20, 0},
    {4096, 20, 0},
    {5120, 20, 0},
};

const MapTileAnimationTrack gUnk_090354C4 = {
    gUnk_090354AC, gUnk_094F4238, 6, 0, -5120, 1024, {0, 0},
};

const MapTileAnimationDef gUnk_090354D4 = {
    &gUnk_090354C4, 1, 1, 0,
};

const MapTileAnimationDef* gUnk_09EE4A2C[6] = {
    &gUnk_09035388,
    &gUnk_09035450,
    &gUnk_0903547C,
    &gUnk_090354A4,
    &gUnk_090354D4,
    NULL,
};

const MapTileAnimationDef* gUnk_09EE4A44 = {
    NULL,
};

const MapTileAnimationDef* gUnk_09EE4A48 = {
    NULL,
};

const MapTileAnimationDef* gUnk_09EE4A4C = {
    NULL,
};

const char gTaskNameMapAnim[] = "map_anim";

TaskDesc gTaskDescMapAnim = {
    gTaskNameMapAnim,
    (void (*)(void*, void*))map_anim_0,
    map_anim_1,
    (void (*)(void*))map_anim_2,
    (void (*)(void*))map_anim_3,
    0x18,
};

const u16 gUnk_090354E8[21] __attribute__((aligned(4))) = {
    667,
    666,
    664,
    663,
    667,
    666,
    664,
    663,
    667,
    666,
    664,
    663,
    667,
    666,
    664,
    663,
    667,
    666,
    664,
    663,
    397,
};

const u16 gUnk_09035512[20] = {
    665,
    665,
    665,
    665,
    664,
    664,
    664,
    664,
    663,
    663,
    663,
    663,
    662,
    662,
    662,
    662,
    661,
    661,
    661,
    661,
};

const u16 gUnk_0903553A[21] = {
    661,
    662,
    663,
    664,
    665,
    666,
    667,
    668,
    669,
    661,
    661,
    661,
    661,
    661,
    661,
    661,
    661,
    661,
    660,
    660,
    660,
};

const u16 gUnk_09035564[12] = {
    663,
    664,
    665,
    663,
    664,
    665,
    663,
    664,
    665,
    663,
    664,
    665,
};

const u16 gUnk_0903557C[20] = {
    667,
    665,
    664,
    661,
    667,
    665,
    664,
    661,
    667,
    666,
    664,
    661,
    667,
    666,
    664,
    661,
    667,
    666,
    664,
    661,
};

const u16 gUnk_090355A4[18] = {
    667,
    667,
    666,
    666,
    665,
    665,
    664,
    664,
    665,
    665,
    666,
    666,
    667,
    667,
    667,
    666,
    665,
    664,
};

const u16 gUnk_090355C8[17] = {
    667,
    666,
    665,
    664,
    663,
    662,
    661,
    660,
    661,
    662,
    663,
    664,
    665,
    666,
    667,
    668,
    669,
};

const u16 gUnk_090355EA[16] = {
    669,
    668,
    667,
    668,
    667,
    666,
    667,
    666,
    665,
    666,
    665,
    664,
    665,
    664,
    663,
    389,
};

const u16 gUnk_0903560A[19] = {
    660,
    661,
    663,
    665,
    667,
    660,
    662,
    664,
    666,
    668,
    666,
    664,
    662,
    660,
    667,
    665,
    663,
    662,
    660,
};

const u16 gUnk_09035630[5] = {
    664,
    665,
    666,
    667,
    668,
};

const u16 gUnk_0903563A[25] = {
    669,
    666,
    663,
    668,
    665,
    662,
    667,
    664,
    661,
    666,
    663,
    660,
    669,
    667,
    665,
    663,
    661,
    660,
    662,
    664,
    666,
    668,
    660,
    662,
    669,
};

const u16 gUnk_0903566C[30] = {
    668,
    668,
    668,
    667,
    667,
    667,
    666,
    666,
    666,
    669,
    669,
    669,
    666,
    667,
    668,
    669,
    668,
    666,
    667,
    669,
    669,
    666,
    667,
    668,
    399,
    390,
    660,
    660,
    660,
    660,
};

const u16 gUnk_090356A8 = 483;

const u16 gUnk_090356AA = 492;

const u16 gUnk_090356AC = 471;

const u16 gUnk_090356AE = 456;

const u16 gUnk_090356B0 = 489;

const u16 gUnk_090356B2 = 501;

const u16 gUnk_090356B4 = 507;

const u16 gUnk_090356B6 = 516;

const u16 gUnk_090356B8 = 450;

const u16 gUnk_090356BA[12] = {
    21,
    20,
    21,
    12,
    20,
    18,
    17,
    16,
    19,
    5,
    25,
    30,
};

const u16 gUnk_090356D2[12] = {
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    0,
    1,
    0,
    0,
};
