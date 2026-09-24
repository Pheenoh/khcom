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
#include "sprites_card.h"
#include "sprites_deck_menu.h"
#include "sprites_card_pictures.h"
#include "card_ids.h"

u8 gActiveDeck;

u8 gUnk_02034AB1[3];

CardUiSpriteState gCardUiSpriteState EWRAM_COMMON(16);

u8 func_080892E8(u8* work, void* a);
#ifdef VERSION_EU
extern AnimHeader gUnk_090A44BA;
extern void* gUnkEu_09F6FD8C[];
extern void** gUnkEu_09F6FDA0[];
extern u16 gUnkEu_090CE9E0[];
extern void* gUnkEu_09F6FDB4[];
extern u16 gUnkEu_090CE9EA[];
extern void* gUnkEu_09F6FDDC[];
extern u16 gUnkEu_090CE9F4[];

#define LANGSTR(x) (((void**)(x))[gLanguage])
#else
#define LANGSTR(x) (x)
#endif
void func_0808DB04(void** p);
void func_0808CDE8(u8* work, u8 b);
u16 func_080857D4(u8 slot);
void SetDeckName(u8 index, const void* src);
void func_080AB22C(u8 a);
void func_080AB334(u8 a);
void func_080AB4AC(u8 a);
void func_0808DE28(u8 a);
s32 func_0808C8D0(s32 a);
void func_080AB964(void);
void func_080AB968(void);
u8 func_0808EC24(UnkStruct_0808DB04* w);
void func_0808EA0C(UnkStruct_0808DB04* w, u8 mode);
u8 func_08089558(u8* work, void* a);
u8 func_08088F24(UnkStruct_0808DB04* w, void* a);
u8 func_08089220(u8* work, void* a);
struct UnkStruct_0808F0C0;
u8 func_0808F3E8(struct UnkStruct_0808F0C0* w, void* a);
u8 func_0808F660(struct UnkStruct_0808F0C0* w, void* a);
extern s16 gUnk_0903570E[];
void func_0808D6C4(u8* work);
struct UnkStruct_080889DC;
u8 func_08086A14(struct UnkStruct_080889DC* w, void* a);
void func_0808E344(void** p);
struct UnkStruct_080889DC;
u8 func_080889DC(struct UnkStruct_080889DC* w, void* a);
u8 func_0808B238(u8* work, void* a);
u8 func_080897CC(struct UnkStruct_080889DC* w, void* a);
u8 func_08087CD4(struct UnkStruct_080889DC* w, void* a);
void func_08085DA0(u8 a);
u8 func_080882DC(u8* work, void* a);
u8 func_0808B30C(u8* work, void* a);
void func_0808C90C(u8* work);
void func_0808C3DC(u8* work, u8 b);
void func_0808DB50(UnkStruct_0808DB04* w);
u8 func_0808A218(u8* work, void* a);
u8 func_0808A650(u8* work, void* a);
u8 func_08089D20(u8* work, void* a);
u8 func_0808B068(u8* work, void* a);
u8 func_08089EC0(u8* work, void* a);
u8 func_080870FC(UnkStruct_0808DB04* w, void* a);
extern s16 gUnk_090356F8[];
s32 func_0808D828(u8* work);
extern u8 gUnk_09614318[];
void func_0808C940(UnkStruct_0808C940* w, s16 n);
void func_0808C974(UnkStruct_0808C940* w);
u8 func_080864A4(u8* work, void* a);
#ifdef VERSION_EU
extern u8* gUnkEu_09F6FE04[];
#endif
void func_0808CC58(u16 a, u8 b);
void func_08090170(DeckCard2Work* node);
u8 func_0808A114(UnkStruct_0808DB04* work, void* a);
u8 func_0808B208(u8* work);
u8 func_0808AB48(struct UnkStruct_080889DC* w, void* a);
u8 func_08087438(UnkStruct_0808DB04* w, void* a);
u8 func_0808778C(struct UnkStruct_080889DC* w, void* a);
u16 func_08084FAC(u8 slot);
u8 func_0808A910(UnkStruct_0808DB04* w, void* a);
void func_0808E2F0(UnkStruct_0808DB04* w);
void func_0808DD20(u8 a, u16 b);
void func_0808CBB4(u8 a, u8 b);
void ConvertActiveDeckCardToPremium(u16 index);
void InitCardCollection(void);
s16 func_08084458(u16 cardId);
u16 CountCollectionCards(void);
u16 CountCardsInDecks(void);

void func_08084D78(UnkStruct_08084D78* out, u8 deck, u8 mode, u16 n, void* p) {
    u16 mask;
    u16 i;
    s32 x;

    mask = 0;

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
            x = gCardDefs[gCardCollection[i] & CARD_ID_MASK].unk_1C;
            out[x].unk_14 = x;
            out[x].unk_16++;
        } else {
            x = gCardDefs[gCardCollection[i] & CARD_ID_MASK].unk_1C;
            out[x + 0x8F].unk_14 = x + 0x8F;
            out[x + 0x8F].unk_16++;
        }
    }
}

u16 func_08084E50(UnkStruct_08084D78* out, u8 deck, u8 mode, u16 n, void* p) {
    u16 mask;
    u16 i;
    u16 count;
    u32 id;
    u16 x;

    mask = 0;

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

    for (i = 0, count = 0; i < n; i++) {
        if (out[i].unk_16 != 0) {
            out[i].unk_1C = EwramAlloc(out[i].unk_16 * 2);
            count++;
        } else {
            out[i].unk_1C = 0;
        }

        out[i].unk_18 = 0;
    }

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] == CARD_ID_MASK) {
            continue;
        }

        if (gCardCollection[i] & mask) {
            continue;
        }

        if (!(gCardCollection[i] & 0x8000)) {
            id = gCardCollection[i] & CARD_ID_MASK;
            x = gCardDefs[id].unk_1C;

            if (id > 0x1C1) {
                out[x].unk_00[0]++;
            } else {
                out[x].unk_00[gCardDefs[id].unk_20]++;
            }

            out[x].unk_1C[out[x].unk_18++] = i;
        } else {
            id = gCardCollection[i] & CARD_ID_MASK;
            x = gCardDefs[id].unk_1C + 0x8F;

            if (id > 0x1C1) {
                out[x].unk_00[0]++;
            } else {
                out[x].unk_00[gCardDefs[id].unk_20]++;
            }

            out[x].unk_1C[out[x].unk_18++] = i;
        }
    }

    return count;
}
void func_08084FA8(void) {
}

u16 func_08084FAC(u8 slot) {
    u16 count;
    u16 i;

    count = 0;

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] != CARD_ID_MASK) {
            if (gCardDefs[gCardCollection[i] & CARD_ID_MASK].unk_2A == slot) {
                count++;
            }
        }
    }

    return count;
}

void func_0808500C(u8 mode, u16* out) {
    u16 mask;
    u16 i;

    mask = 0;
    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    out[3] = 0;

    switch (mode) {
    case 0:
        mask = 0x1000;
        break;
    case 1:
        mask = 0x2000;
        break;
    case 2:
        mask = 0x4000;
        break;
    case 3:
        mask = 0x7000;
        break;
    }

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] != CARD_ID_MASK) {
            if (!(gCardCollection[i] & mask)) {
                out[gCardDefs[gCardCollection[i] & CARD_ID_MASK].unk_2A]++;
            }
        }
    }
}

void ClearCardCollectionSlot(u16* p) {
    *p = CARD_ID_MASK;
}
void RemoveUnequippedCardById(u16 id) {
    s32 i;

    for (i = 0; i < gCardCount; i++) {
        if (gCardCollection[i] != CARD_ID_MASK &&
            (gCardCollection[i] & 0x7000) == 0 &&
            (gCardCollection[i] & CARD_ID_MASK) == id) {
            gCardCollection[i] = CARD_ID_MASK;
            return;
        }
    }
}

u8 func_0808510C(u16 id) {
    s32 i;

    if (gGameState.flags & 8) {
        return 0;
    }

    for (i = 0; i < gCardCount; i++) {
        if ((gCardCollection[i] & CARD_ID_MASK) == id) {
            return 1;
        }
    }

    return 0;
}

void InitDecks(void) {
    u16 i;
    u16 j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 99; j++) {
            gDecks[i].cards[j] |= 0xFFFF;
        }

        for (j = 0; j < 20; j++) {
            gDecks[i].unk_C6[j] = 0;
        }

        gDecks[i].unk_DA = 0;
        gDecks[i].unk_DC = 0;
    }
}

void ClearDeck(u8 deck) {
    u16 mask;
    u16 i;

    mask = 0;

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

    for (i = 0; i < 99; i++) {
        if (gDecks[deck].cards[i] != 0xFFFF) {
            gCardCollection[gDecks[deck].cards[i]] &= ~mask;
            gDecks[deck].cards[i] |= 0xFFFF;
        }
    }

    gDecks[deck].unk_DA = 0;
    gDecks[deck].unk_DC = 0;
}

u8 AddCardToActiveDeck(u16 card) {
    u16* cards;
    u16 i;
    u16 v;

    i = 0;
    cards = GetActiveDeck()->cards;

    while (cards[i] != 0xFFFF) {
        i++;

        if (i == 99) {
            return 0;
        }
    }

    cards[i] = card;

    switch (gActiveDeck) {
    case 0:
        gCardCollection[card] |= 0x1000;
        break;
    case 1:
        gCardCollection[card] |= 0x2000;
        break;
    case 2:
        gCardCollection[card] |= 0x4000;
        break;
    }

    v = GetCardCpCost(gCardCollection[card]);
    gDecks[gActiveDeck].unk_DA += v;
    gDecks[gActiveDeck].unk_DC++;
    return 1;
}

u8 AddCardToDeck(u16 card, u8 deck) {
    u16* cards;
    u16 i;
    u16 v;

    cards = GetDeck(deck)->cards;

    for (i = 0; i < 99 && cards[i] != 0xFFFF; i++) {
    }

    if (i == 99) {
        return 0;
    }

    cards[i] = card;

    switch (deck) {
    case 0:
        gCardCollection[card] |= 0x1000;
        break;
    case 1:
        gCardCollection[card] |= 0x2000;
        break;
    case 2:
        gCardCollection[card] |= 0x4000;
        break;
    }

    v = GetCardCpCost(gCardCollection[card]);
    gDecks[deck].unk_DA += v;
    gDecks[deck].unk_DC++;
    return 1;
}

void RemoveCardFromActiveDeck(u16 slot) {
    u16* cards;
    u16 v;

    cards = GetActiveDeck()->cards;

    if (cards[slot] != 0) {
        switch (gActiveDeck) {
        case 0:
            gCardCollection[cards[slot]] &= ~0x1000;
            break;
        case 1:
            gCardCollection[cards[slot]] &= ~0x2000;
            break;
        case 2:
            gCardCollection[cards[slot]] &= ~0x4000;
            break;
        }
    }

    v = GetCardCpCost(gCardCollection[cards[slot]]);
    gDecks[gActiveDeck].unk_DA -= v;
    gDecks[gActiveDeck].unk_DC--;
    cards[slot] = 0xFFFF;
}

void RemoveCardFromDeck(u16* p, u8 deck) {
    u16 v;

    switch (deck) {
    case 0:
        gCardCollection[*p] &= ~0x1000;
        break;
    case 1:
        gCardCollection[*p] &= ~0x2000;
        break;
    case 2:
        gCardCollection[*p] &= ~0x4000;
        break;
    }

    v = GetCardCpCost(gCardCollection[*p]);
    gDecks[deck].unk_DA -= v;
    gDecks[deck].unk_DC--;
    *p = 0xFFFF;
}

void RecalculateInactiveDeckCpCosts(void) {
    u8 i;
    u16 total;
    s32 j;
    Deck* deck;

    for (i = 0; i < 3; i++) {
        if (i == gActiveDeck) {
            continue;
        }

        total = 0;
        deck = GetDeck(i);

        for (j = 0; j < 99; j++) {
            if (deck->cards[j] != 0xFFFF) {
                total += GetCardCpCost(gCardCollection[deck->cards[j]]);
            }
        }

        gDecks[i].unk_DA = total;
    }
}

void ConvertActiveDeckCardToPremium(u16 index) {
    Deck* d;
    u16 v;

    d = GetActiveDeck();
    gDecks[gActiveDeck].unk_DA -= GetCardCpCost(gCardCollection[*(u16*)(index * 2 + (u32)d)]);
    gCardCollection[*(u16*)(index * 2 + (u32)d)] |= 0x8000;
    v = GetCardCpCost(gCardCollection[*(u16*)(index * 2 + (u32)d)]) + gDecks[gActiveDeck].unk_DA;
    gDecks[gActiveDeck].unk_DA = v;
    RecalculateInactiveDeckCpCosts();
}

s32 HasNonPremiumCardsInActiveDeck(void) {
    Deck* deck;
    s32 count;
    s32 i;

    count = 0;
    deck = GetActiveDeck();

    for (i = 0; i < DECK_SIZE; i++) {
        if (deck->cards[i] != 0xFFFF) {
            if (gCardCollection[deck->cards[i]] & 0x8000) {
                count++;
            }
        }
    }

    if (gDecks[gActiveDeck].unk_DC == count) {
        return 0;
    }

    return 1;
}

Deck* GetActiveDeck(void) {
    return &gDecks[gActiveDeck];
}

Deck* GetDeck(u8 index) {
    return &gDecks[index];
}

u16 GetDeckCpCost(u8 index) {
    return gDecks[index].unk_DA;
}

void SetDeckName(u8 index, const void* src) {
    u8* deck;
    u32 offset;
    u8* d;
    const u8* s;

#ifdef VERSION_US
    if (*(const u16*)src == 0) {
#else
    if (*(const u8*)src == 0) {
#endif
        return;
    }

    deck = (u8*)&gDecks;
    offset = index * (sizeof(Deck) / sizeof(u16));
    s = (const u8*)src;
    offset *= sizeof(u16);
    d = deck + offsetof(Deck, unk_C6);
    d += offset;

#ifdef VERSION_US
    do {
        d[0] = s[0];
        d[1] = s[1];
        d += 2;
        s += 2;
    } while (*(const u16*)s != 0);
#else
    do {
        *d = *s;
#ifdef VERSION_EU
        d++;
        s++;
#else
        s++;
        d++;
#endif
    } while (*(const u8*)s != 0);
#endif
}

u8* GetDeckName(u8 index) {
    return gDecks[index].unk_C6;
}

u16 func_080857D4(u8 slot) {
    u16* cards;
    u16 count;
    u16 i;

    count = 0;
    cards = GetActiveDeck()->cards;

    for (i = 0; i < DECK_SIZE; i++) {
        if (cards[i] != 0xFFFF) {
            if (gCardDefs[gCardCollection[cards[i]] & CARD_ID_MASK].unk_2A == slot) {
                count++;
            }
        }
    }

    return count;
}

u16 func_08085844(u8 slot, u8 deckIndex) {
    u16* cards;
    u16 count;
    u16 i;

    count = 0;
    cards = GetDeck(deckIndex)->cards;

    for (i = 0; i < DECK_SIZE; i++) {
        if (cards[i] != 0xFFFF) {
            if (gCardDefs[gCardCollection[cards[i]] & CARD_ID_MASK].unk_2A == slot) {
                count++;
            }
        }
    }

    return count;
}

s16 func_080858B8(s32 index) {
    u16 count;
    s16 i;
    u16* cards;

    count = 0;
    cards = GetActiveDeck()->cards;

    switch (index) {
    case 0:
        for (i = 0; i <= 98; i++) {
            if (cards[i] != 0xFFFF) {
                if ((u8)gCardDefs[gCardCollection[cards[i]] & CARD_ID_MASK].unk_2A <= 2) {
                    count = ((count << 16) + 0x10000) >> 16;
                }
            }
        }
        break;
    case 1:
        for (i = 0; i <= 98; i++) {
            if (cards[i] != 0xFFFF) {
                if ((u8)gCardDefs[gCardCollection[cards[i]] & CARD_ID_MASK].unk_2A == 3) {
                    count = ((count << 16) + 0x10000) >> 16;
                }
            }
        }
        break;
    }

    return count;
}

s16 func_080859A0(s32 mode, Deck* d) {
    s16 count;
    s16 i;

    count = 0;

    switch (mode) {
    case 0:
        for (i = 0; i < d->unk_DC; i++) {
            if (gCardDefs[d->cards[i] & CARD_ID_MASK].unk_2A <= 2) {
                count++;
            }
        }
        break;
    case 1:
        for (i = 0; i < d->unk_DC; i++) {
            if (gCardDefs[d->cards[i] & CARD_ID_MASK].unk_2A == 3) {
                count++;
            }
        }
        break;
    }

    return count;
}

void func_08085A58(s32 a, u16* out) {
    u16* cards;
    u16 i;

    cards = GetActiveDeck()->cards;

    switch (a) {
    case 0:
        for (i = 0; i < 99; i++) {
            if (cards[i] != 0xFFFF) {
                if (gCardDefs[gCardCollection[cards[i]] & 0xFFF].unk_2A <= 2) {
                    *out++ = gCardCollection[cards[i]] & 0x8FFF;
                }
            }
        }
        break;
    case 1:
        for (i = 0; i < 99; i++) {
            if (cards[i] != 0xFFFF) {
                if (gCardDefs[gCardCollection[cards[i]] & 0xFFF].unk_2A == 3) {
                    *out++ = gCardCollection[cards[i]] & 0x8FFF;
                }
            }
        }
        break;
    }
}

u16 GetDeckCardCount(u8 index) {
    return gDecks[index].unk_DC;
}

void SetActiveDeckIndex(u8 index) {
    gActiveDeck = index;
}

u16 func_08085B5C(u16 index) {
    return gCardDefs[gCardCollection[index] & CARD_ID_MASK].unk_1C;
}

u8 func_08085B84(u16 index) {
    return gCardDefs[gCardCollection[index] & CARD_ID_MASK].unk_2A;
}

s32 func_08085BAC(void) {
    Deck* deck;
    s32 a;
    s32 b;
    s32 i;

    a = 0;
    b = 0;
    deck = GetActiveDeck();

    for (i = 0; i < DECK_SIZE; i++) {
        if (deck->cards[i] != 0xFFFF) {
            if (func_08085B84(deck->cards[i]) != 2) {
                if (func_08085B84(deck->cards[i]) != 3) {
                    a++;
                }
            }
        }
    }

    for (i = 0; i < DECK_SIZE; i++) {
        if (deck->cards[i] != 0xFFFF) {
            if (gCardCollection[deck->cards[i]] & 0x8000) {
                b++;
            }
        }
    }

    if (b == a) {
        return 1;
    }

    return 0;
}

void func_08085C3C(void) {
    gActiveDeck = 0;
    InitCardCollection();
    InitDecks();

    if (gUnk_03006C10 & 0x10) {
        func_080AB228();
        func_080AB22C(2);
        func_080AB334(1);
        func_080AB4AC(0);
    } else {
        func_080AB880();
        func_080AB8E4();
        func_080AB964();
        func_080AB968();
    }

#ifdef VERSION_EU
    SetDeckName(0, gUnkEu_09F65FDC.strings[gLanguage]);
    SetDeckName(1, gUnkEu_09F65FF0.strings[gLanguage]);
    SetDeckName(2, gUnkEu_09F66004.strings[gLanguage]);
#elif defined(VERSION_JP)
    SetDeckName(0, gUnkJp_090089B0);
    SetDeckName(1, gUnkJp_090089BC);
    SetDeckName(2, gUnkJp_090089C8);
#else
    SetDeckName(0, gUnk_09EE4AC8);
    SetDeckName(1, gUnk_09EE4AD6);
    SetDeckName(2, gUnk_09EE4AE4);
#endif
}

void func_08085CB0(void) {
    gActiveDeck = 0;
    InitCardCollection();
    InitDecks();
    func_080AB228();
    func_080AB334(0);
    func_080AB22C(1);
    func_080AB4AC(2);
#ifdef VERSION_EU
    SetDeckName(0, gUnkEu_09F65FDC.strings[gLanguage]);
    SetDeckName(1, gUnkEu_09F65FF0.strings[gLanguage]);
    SetDeckName(2, gUnkEu_09F66004.strings[gLanguage]);
#elif defined(VERSION_JP)
    SetDeckName(0, gUnkJp_090089B0);
    SetDeckName(1, gUnkJp_090089BC);
    SetDeckName(2, gUnkJp_090089C8);
#else
    SetDeckName(0, gUnk_09EE4AC8);
    SetDeckName(1, gUnk_09EE4AD6);
    SetDeckName(2, gUnk_09EE4AE4);
#endif
}

void _08085D04(u8 a) {
    u8 n = 0;

    InitCardCollection();
    InitDecks();
    SetActiveDeckIndex(0);

    switch (a) {
    case 2:
        n = 1;
        break;
    case 3:
        n = 2;
        break;
    case 4:
        n = 3;
        break;
    case 5:
        n = 4;
        break;
    case 6:
        n = 5;
        break;
    case 7:
        n = 6;
        break;
    case 8:
        n = 7;
        break;
    case 9:
        n = 8;
        break;
    case 10:
        n = 9;
        break;
    case 11:
        n = 10;
        break;
    case 0:
    case 12:
        n = 11;
        break;
    case 1:
    case 13:
        n = 0;
        break;
    }

    func_08085DA0(n);
}
void func_08085DA0(u8 a) {
    s32 i;
    s32 j;

    for (i = 0, j = 0; i < gUnk_090356BA[a]; i++, j++) {
        func_08084458(gUnk_09EE4A68[a][i]);
        AddCardToActiveDeck(i);
    }

    for (i = 0; i < gUnk_090356D2[a]; j++, i++) {
        func_08084458(gUnk_09EE4A98[a][i]);
        AddCardToActiveDeck(j);
    }

    gCardCollection[200] = CARD_GUARD_ARMOR_1;
    gCardCollection[201] = CARD_PARASITE_CAGE_1;
    gCardCollection[202] = CARD_TRICKMASTER_1;
    gCardCollection[203] = CARD_DARKSIDE_1;
    gCardCollection[204] = CARD_HADES_9;
    gCardCollection[205] = CARD_JAFAR_1;
    gCardCollection[206] = CARD_OOGIE_BOOGIE_1;
    gCardCollection[207] = CARD_URSULA_1;
    gCardCollection[208] = CARD_HOOK_9;
    gCardCollection[209] = CARD_DRAGON_MALEFICENT_1;
    gCardCollection[210] = CARD_RIKU_9;
    gCardCollection[211] = CARD_VEXEN_9;
    gCardCollection[212] = CARD_LEXAEUS_9;
    gCardCollection[213] = CARD_ANSEM_9;

    if (func_0800FC5C(38) != 0) {
        AddCardToActiveDeck(200);
    }

    if (func_0800FC5C(42) != 0) {
        AddCardToActiveDeck(201);
    }

    if (func_0800FC5C(40) != 0) {
        AddCardToActiveDeck(202);
    }

    if (func_0800FC5C(44) != 0) {
        AddCardToActiveDeck(203);
    }

    if (func_0800FC5C(50) != 0) {
        AddCardToActiveDeck(204);
    }

    if (func_0800FC5C(39) != 0) {
        AddCardToActiveDeck(205);
    }

    if (func_0800FC5C(45) != 0) {
        AddCardToActiveDeck(206);
    }

    if (func_0800FC5C(41) != 0) {
        AddCardToActiveDeck(207);
    }

    if (func_0800FC5C(48) != 0) {
        AddCardToActiveDeck(208);
    }

    if (func_0800FC5C(43) != 0) {
        AddCardToActiveDeck(209);
    }

    if (func_0800FC5C(51) != 0) {
        AddCardToActiveDeck(210);
    }

    if (func_0800FC5C(54) != 0) {
        AddCardToActiveDeck(211);
    }

    if (func_0800FC5C(57) != 0) {
        AddCardToActiveDeck(212);
    }

    if (func_0800FC5C(56) != 0) {
        AddCardToActiveDeck(213);
    }
}

u8 GetActiveDeckIndex(void) {
    return gActiveDeck;
}

void func_08085FB0(void) {
}
static void Deckmenu2_0(u8* work, void* a) {
    u16 unk;
    *(void**)&work[CARDWORK(0x8BC)] = a;
    SetBgMode0();
    SetBackdropColor(0, 0, 0);
#ifdef VERSION_EU
    SetupBg(0, 0, 31, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(2, 0, 28, 0);
    SetupBg(3, 0, 30, 0);
#else
    SetupBg(0, 3, 31, 0);
    SetupBg(1, 2, 23, 0);
    SetupBg(2, 1, 15, 0);
    SetupBg(3, 0, 30, 0);
#endif
    SetBgPriority(0, 0);
    SetBgPriority(1, 1);
    SetBgPriority(2, 2);
    SetBgPriority(3, 3);
    FadeStartIn(0, 16);
    ListPoolInit(&work[CARDWORK(0x7F0)]);
    TaskPoolInit((TaskPool*)&work[CARDWORK(0x7C8)], 286);
    TaskPoolInit((TaskPool*)&work[CARDWORK(0x7DC)], 1);
    ((UnkStruct_0808DB04*)work)->unk_8C0 = GetActiveDeckIndex();
    func_0808C3DC(work, 0);
    *(void**)&work[0x00] = AllocObjTiles(0x120, 0);
    SetObjTileSource(*(void**)&work[0x00], gUnk_090A4664);
    AnimInit((AnimState*)&work[CARDWORK(0x800)], gUnk_09EEB03C, gUnk_09EEB008);
    AnimStart((AnimState*)&work[CARDWORK(0x800)], 0, 1);
    *(void**)&work[0x4F0] = AnimGetGfx((AnimState*)&work[CARDWORK(0x800)]);
    *(s32*)&work[CARDWORK(0x848)] = gUnk_090356EC[0] << 8;
    *(s32*)&work[CARDWORK(0x84C)] = gUnk_090356F2[0] << 8;
    *(u16*)&work[CARDWORK(0x882)] = 0;
#ifdef VERSION_EU
    *(void**)&work[0x10] = LoadObjTiles((u8*)&gUnk_090A44BA + 10, 32);
#else
    *(void**)&work[0x10] = LoadObjTiles(gUnk_090A44C4, 32);
#endif
    *(void**)&work[0x14] = LoadObjPalette(gUnk_09614418, 32);
#ifdef VERSION_EU
    *(void**)&work[0x4B8] = LoadObjTiles(gUnkEu_09F6FD8C[gLanguage], gUnkEu_090CE9E0[gLanguage]);
#else
    *(void**)&work[0x4B8] = LoadObjTiles(&gUnk_090A0C86[0x132C], 0x280);
#endif
#ifdef VERSION_EU
    *(void**)&work[0x4E8] = gUnkEu_09F6FDA0[gLanguage][0];
    *(void**)&work[0x4EC] = gUnkEu_09F6FDA0[gLanguage][1];
#else
    *(void**)&work[0x4E8] = *(void**)&gUnk_09EEAFD4;
    *(void**)&work[0x4EC] = *((void**)&gUnk_09EEAFD4 + 1);
#endif
    *(void**)&work[0x04] = AllocObjTiles(0x280, 0);
    func_0808E364(work, 0);
    *(void**)&work[0x4C4] = LoadObjPalette(gUnk_09614438, 32);
    gCardUiSpriteState.tiles = AllocObjTiles(0x100, 0);
    gCardUiSpriteState.palette = LoadObjPalette(gUnk_09611AB8, 32);
    SetObjTileSource(gCardUiSpriteState.tiles, gUnk_0908C3CE);
    AnimInit(&gCardUiSpriteState.anim, gUnk_09EEA198, gUnk_09EEA180);
    AnimStart(&gCardUiSpriteState.anim, 0, 1);
    gCardUiSpriteState.gfx = AnimUpdate(&gCardUiSpriteState.anim);
    *(s32*)&work[0x28] = 0;
    *(s32*)&work[0x1C] = 0;
    *(s32*)&work[0x20] = 0;
    *(s32*)&work[0x24] = 0;
    *(s32*)&work[0x30] = 0;
    *(s32*)&work[0x34] = 0;
    *(s32*)&work[0x08] = 0;
    *(s32*)&work[0x0C] = 0;
    *(s32*)&work[0x18] = 0;
    *(s32*)&work[0x4BC] = 0;
    *(s32*)&work[0x4C0] = 0;
    *(u16*)&work[CARDWORK(0x884)] = 0;
    *(u16*)&work[CARDWORK(0x886)] = 0;
    work[CARDWORK(0x8B3)] = 0;
    work[CARDWORK(0x8B4)] = 0;
    work[CARDWORK(0x8B7)] = 16;
    work[CARDWORK(0x8C8)] = 0;
    *(s32*)&work[0x4C8] = 0;
    *(s32*)&work[0x4CC] = 0;
    work[CARDWORK(0x8C7)] = 0;
    work[CARDWORK(0x8B1)] = 0;
    *(u16*)&work[CARDWORK(0x8A2)] = func_080857D4(0);
    *(u16*)&work[CARDWORK(0x8A4)] = func_080857D4(1);
    *(u16*)&work[CARDWORK(0x8A6)] = func_080857D4(2);
    *(u16*)&work[CARDWORK(0x8A8)] = func_080857D4(3);
    work[CARDWORK(0x8C1)] = 0;
    *(u16*)&work[CARDWORK(0x898)] = 0;
    *(s32*)&work[0x4D4] = 0;
    work[CARDWORK(0x8C9)] = 0;
    work[CARDWORK(0x8CB)] = 0;
    work[CARDWORK(0x8CC)] = 16;
    work[CARDWORK(0x8CD)] = 16;
    *(s32*)&work[CARDWORK(0x858)] = 0x7800;
    *(s32*)&work[CARDWORK(0x860)] = -0x800;
    *(s32*)&work[CARDWORK(0x85C)] = 0xA400;
    *(s32*)&work[CARDWORK(0x864)] = 0xA000;
    *(s32*)&work[CARDWORK(0x868)] = -0x8000;
    work[CARDWORK(0x8CF)] = 0;
    work[CARDWORK(0x8B0)] = 0;
    *(u16*)&work[CARDWORK(0x878)] = 95;
    *(u16*)&work[CARDWORK(0x87A)] = unk = 0xFFFE;
    *(u16*)&work[CARDWORK(0x87C)] = 135;
    *(u16*)&work[CARDWORK(0x87E)] = unk;
    work[CARDWORK(0x8CE)] = 0;
    work[CARDWORK(0x8C2)] = 0;
    work[CARDWORK(0x8C3)] = 0;
    work[CARDWORK(0x8C4)] = 0;
    work[CARDWORK(0x8C5)] = 0;
    InitTextSlots((TextSlot*)&work[0x38], 8);
    InitTextSlots((TextSlot*)&work[0x78], 8);
    InitTextSlots((TextSlot*)&work[0xB8], 8);
    InitTextSlots((TextSlot*)&work[0xF8], 30);
    InitTextSlots((TextSlot*)&work[0x1E8], 90);
    work[CARDWORK(0x8D0)] = 0;
    work[CARDWORK(0x8D2)] = 0;
}
static u8 Deckmenu2_1(u8* work, void* a) {
#ifdef VERSION_EU
    FadeStartIn(0, 16);

    if (work[0x8D4] == 0) {
        RequestDma3Clear(GetBgCharBase(0), 0x2000);
    }

    if (work[0x8D4] == 1) {
        RequestDma3Clear(GetBgCharBase(0) + 0x2000, 0x2000);
    }

    if (work[0x8D4] == 2) {
        RequestDma3Clear(GetBgCharBase(1), 0x2000);
    }

    if (work[0x8D4] == 3) {
        RequestDma3Clear(GetBgCharBase(1) + 0x2000, 0x2000);
    }

    if (work[0x8D4] == 4) {
        RequestDma3Clear(GetBgCharBase(2), 0x2000);
    }

    if (work[0x8D4] == 5) {
        RequestDma3Clear(GetBgCharBase(2) + 0x2000, 0x2000);
    }

    if (work[0x8D4] == 6) {
        RequestDma3Clear(GetBgCharBase(3), 0x2000);
    }

    if (work[0x8D4] == 7) {
        RequestDma3Clear(GetBgCharBase(3) + 0x2000, 0x2000);
    }

    work[0x8D4]++;

    if (work[0x8D4] == 8) {
        work[0x8D4] = 0;
        SetTaskUpdate(a, (TaskUpdateFunc)func_080864A4);
    }

    return 1;
#else
    FadeStartIn(0, 16);

    if (work[0x8D0] == 0) {
        RequestDma3Clear(GetBgCharBase(0), 0x2000);
    }

    if (work[0x8D0] == 1) {
        RequestDma3Clear(GetBgCharBase(0) + 0x2000, 0x2000);
    }

    if (work[0x8D0] == 2) {
        RequestDma3Clear(GetBgCharBase(1), 0x2000);
    }

    if (work[0x8D0] == 3) {
        RequestDma3Clear(GetBgCharBase(1) + 0x2000, 0x2000);
    }

    if (work[0x8D0] == 4) {
        RequestDma3Clear(GetBgCharBase(2), 0x2000);
    }

    if (work[0x8D0] == 5) {
        RequestDma3Clear(GetBgCharBase(2) + 0x2000, 0x2000);
    }

    if (work[0x8D0] == 6) {
        RequestDma3Clear(GetBgCharBase(3), 0x2000);
    }

    if (work[0x8D0] == 7) {
        RequestDma3Clear(GetBgCharBase(3) + 0x2000, 0x2000);
    }

    work[0x8D0]++;

    if (work[0x8D0] == 8) {
        work[0x8D0] = 0;
        SetTaskUpdate(a, (TaskUpdateFunc)func_080864A4);
    }

    return 1;
#endif
}
u8 func_08086650(UnkStruct_0808DB04* w, void* a);

u8 func_080864A4(u8* work, void* a) {
    FadeStartIn(0, 16);

    switch (work[CARDWORK(0x8D0)]) {
    case 0:
        LoadBgTiles(3, gUnk_09402F78, 0x2000);
        LoadBgPalette(3, gUnk_09614118, 0x1E0);
        break;
    case 1:
#ifdef VERSION_EU
        RequestDma3Copy(&gUnk_09402F78[0x2000],
                        (u8*)GetBgCharBase(3) + 0x2000, 0x1800);
#else
        RequestDma3Copy(&gUnk_09402F78[0x2000],
                        (u8*)GetBgCharBase(3) + 0x2000, 0x2000);
#endif
        break;
    case 2:
#ifdef VERSION_EU
        LoadBgMap(3, gUnk_095132B8, 0x800);
#else
        LoadBgMap(3, gUnk_09516AB8, 0x800);
#endif
        break;
    case 3:
#ifdef VERSION_EU
        switch (gLanguage) {
        case 0:
            RequestDma3Copy(gUnkEu_094E04E4, (u8*)GetBgCharBase(3) + 0x3800, 0x1C00);
            break;
        case 1:
            RequestDma3Copy(&gUnkEu_094E04E4[0x1C00], (u8*)GetBgCharBase(3) + 0x3800, 0x1C00);
            break;
        case 2:
            RequestDma3Copy(&gUnkEu_094E04E4[0x7000], (u8*)GetBgCharBase(3) + 0x3800, 0x1C00);
            break;
        case 3:
            RequestDma3Copy(&gUnkEu_094E04E4[0x5400], (u8*)GetBgCharBase(3) + 0x3800, 0x1C00);
            break;
        case 4:
            RequestDma3Copy(&gUnkEu_094E04E4[0x3800], (u8*)GetBgCharBase(3) + 0x3800, 0x1C00);
            break;
        }
#else
        LoadBgTiles(0, gUnk_09406F78, 0xC00);
#endif
        break;
    case 4:
        LoadBgMap(0, gUnk_08125E24, 0x800);
        break;
#ifndef VERSION_EU
    case 5:
        LoadBgTiles(1, &gUnk_09406F78[0xC00], 0x2000);
        break;
    case 6:
        RequestDma3Copy(&gUnk_09406F78[0x2C00],
                        (u8*)GetBgCharBase(1) + 0x2000, 0x1E20);
        break;
#endif
    case 7:
        LoadBgMap(1, gUnk_08125E24, 0x800);
        break;
#ifndef VERSION_EU
    case 8:
        LoadBgTiles(2, &gUnk_09406F78[0x4A20], 0x2000);
        break;
    case 9:
        RequestDma3Copy(&gUnk_09406F78[0x6A20],
                        (u8*)GetBgCharBase(2) + 0x2000, 0x1E20);
        break;
#endif
    case 10:
        LoadBgMap(2, gUnk_08125E24, 0x800);
        break;
    case 11:
        SetBgScroll(0, (u16)-88, (u16)-16);
        SetBgScroll(1, (u16)-88, (u16)-64);
        SetBgScroll(2, (u16)-88, (u16)-112);
        work[CARDWORK(0x8D0)] = 0;
        SetTaskUpdate(a, (TaskUpdateFunc)func_08086650);
        return 1;
    }

    work[CARDWORK(0x8D0)]++;
    return 1;
}
u8 func_08086650(UnkStruct_0808DB04* w, void* a) {
    FadeStartIn(0, 16);
    switch (w->unk_8D0) {
    case 0:
        LoadBgMap(0, gUnk_09519AB8, 0x180);
        LoadBgMap(1, gUnk_0951A2B8, 0x180);
        LoadBgMap(2, gUnk_0951AAB8, 0x180);
        w->unk_8D0++;
        break;
    case 1:
        func_0808CBB4(w->unk_8A2, 0);
        func_0808CBB4(w->unk_8A4, 1);
        func_0808CBB4(w->unk_8A6, 2);
        func_0808CBB4(w->unk_8A8, 3);
        func_0808CDE8((u8*)w, w->unk_8C0);
        w->unk_8D0++;
        break;
    case 2:
        func_0808D0A4(0);
        func_0808D0A4(1);
        func_0808D0A4(2);
        w->unk_8D0++;
        break;
    case 3:
        func_0808D258(0);
        func_0808D258(1);
        func_0808D258(2);
        w->unk_8D0++;
        break;
    case 4:
        func_0808D16C((u8)GetActiveDeckIndex());
        func_0808D594();
        w->x2 = 0x4800;
        w->y2 = 0x2800;
        w->unk_886 = w->unk_8C0;
        SetTaskUpdate(a, (TaskUpdateFunc)func_0808686C);
        w->unk_8B1 = 1;
        func_0808CD48((u8*)w);
        func_0808D6C4((u8*)w);
        w->x = gUnk_090356EC[w->unk_884] << 8;
        w->y = gUnk_090356F2[(s16)w->unk_886] << 8;
        w->tiles6 = LoadObjTiles(gUnk_090A583E, 0x620);
#ifdef VERSION_EU
        w->tiles = LoadObjTiles(gUnkEu_09F6FDDC[gLanguage], gUnkEu_090CE9F4[gLanguage]);
#elif defined(VERSION_US)
        if (gGameState.flags & 8) {
            w->tiles = LoadObjTiles(gUnk_090A418E, 0x320);
        } else {
            w->tiles = LoadObjTiles(gUnk_090A3E46, 0x320);
        }
#else
        w->tiles = LoadObjTiles(gUnk_090A418E, 0x320);
#endif
        w->palette3 = LoadObjPalette(gUnk_096144F8, 32);
        w->unk_8D0 = 0;
        w->unk_8B7 = 16;
        return 1;
    }
    return 1;
}
u8 func_0808686C(u8* work, void* a) {
    *(void**)&work[0x4F0] = AnimUpdate(&work[CARDWORK(0x800)]);
    *(void**)&work[0x4F4] = AnimUpdate(&work[CARDWORK(0x818)]);

    if (!FadeIsActive()) {
        switch (work[CARDWORK(0x8D0)]) {
        case 0:
            ApproachValue(&work[CARDWORK(0x860)], 0, work[CARDWORK(0x8B7)]);
            ApproachValue(&work[CARDWORK(0x864)], 0x9800, work[CARDWORK(0x8B7)]);
            work[CARDWORK(0x8B7)]--;

            if (work[CARDWORK(0x8B7)] == 0) {
                work[CARDWORK(0x8B7)] = 16;
                work[CARDWORK(0x8D0)]++;
            }
            break;
        case 1:
            ApproachValue(&work[CARDWORK(0x868)], 0, work[CARDWORK(0x8B7)]);
            work[CARDWORK(0x8B7)]--;

            if (work[CARDWORK(0x8B7)] == 0) {
                ReleaseObjTiles(*(void**)&work[0x4BC]);
                ReleaseObjTiles(*(void**)&work[0x18]);
                ReleaseObjPalette(*(void**)&work[0x4C0]);
                *(void**)&work[0x4BC] = 0;
                *(void**)&work[0x18] = 0;
                *(void**)&work[0x4C0] = 0;
                work[CARDWORK(0x8B0)] = 1;
                LoadBgMap(3, gUnk_09512AB8, 0x800);
                SetTaskUpdate(a, (TaskUpdateFunc)func_080889DC);
            }
            break;
        }
    }

    return 1;
}
u8 func_08086984(u8* work, void* a) {
    func_0808D6C4(work);
#ifdef VERSION_EU
    ApproachValueHalf(&work[0x84C], gUnk_09035950[*(s16*)&work[0x888]] << 8);
    ApproachValueHalf(&work[0x850], gUnk_09035956[*(s16*)&work[0x88A]] << 8);
    work[0x8BB]--;

    if (work[0x8BB] == 0) {
        work[0x8B5] = 0;
        func_0808CD48(work);
        SetTaskUpdate(a, (TaskUpdateFunc)func_08086A14);
    }
#else
    ApproachValueHalf(&work[0x848], gUnk_09035950[*(s16*)&work[0x884]] << 8);
    ApproachValueHalf(&work[0x84C], gUnk_09035956[*(s16*)&work[0x886]] << 8);
    work[0x8B7]--;

    if (work[0x8B7] == 0) {
        work[0x8B1] = 0;
        func_0808CD48(work);
        SetTaskUpdate(a, (TaskUpdateFunc)func_08086A14);
    }
#endif

    return 1;
}

u8 func_08086A14(UnkStruct_080889DC* w, void* a) {
    w->gfx = AnimUpdate(&w->anim2);
    w->gfx2 = AnimUpdate(&w->anim3);
    if ((u8)FadeIsActive() != 0) {
        TaskPoolUpdate(&w->taskpool);
        return 1;
    }
    if (w->unk_8C9 != 0) {
        ApproachValueHalf(&w->x, gUnk_09035950[w->unk_884] << 8);
        ApproachValueHalf(&w->y, gUnk_09035956[w->unk_886] << 8);
        if (w->unk_8B7 != 0) {
            w->unk_8B7--;
        }
        TaskPoolUpdate(&w->taskpool);
        TaskPoolUpdate(&w->cardpool);
        if (GetKeysPressed() & START_BUTTON) {
            w->unk_8CB = 1;
            w->unk_8D2 = 7;
        }
        w->unk_8CE = 4;
        return 1;
    }
    if (w->unk_8CE > 0) {
        TaskPoolUpdate(&w->taskpool);
        TaskPoolUpdate(&w->cardpool);
        w->unk_8CE--;
        return 1;
    }
    if (w->unk_8CB != 0) {
        if ((u8)func_0808E750((u8*)w) != 0 && (u8)func_0808E79C((u8*)w) != 0) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808B208);
            FadeStartOut(0, 4);
            m4aSongNumStart(SONG_SYS_CANSEL);
            return 1;
        } else {
            w->unk_8CB = 0;
        }
    }
    switch ((u16)GetKeysRepeat()) {
    case DPAD_UP:
        if (w->unk_886 > 0) {
            w->unk_886--;
            w->unk_8B7 = 1;
            m4aSongNumStart(SONG_SYS_CLICKI04B);
        } else {
            if ((u8)func_0808CA78((u8*)w, 1) == 0) {
                if (w->unk_8CF == 0) {
                    w->unk_884 = w->unk_8C1;
                    w->unk_8B7 = 1;
                    m4aSongNumStart(SONG_SYS_CLICKI04B);
                    w->unk_8B2 = w->unk_8B1;
                    w->unk_8B1 = 2;
                    AnimStart(&w->anim2, 0, 1);
                    SetTaskUpdate(a, (TaskUpdateFunc)func_080870FC);
                    func_0808DE28(0);
                    return 1;
                }
            } else {
                if (w->unk_8CF != 0) {
                    w->unk_876++;
                    if ((u16)w->unk_876 <= 3) {
                        w->y3 = gUnk_09035956[w->unk_876] << 8;
                    } else {
                        w->y3 = -0x10000;
                    }
                }
            }
        }
        break;
    case DPAD_DOWN:
        if (w->unk_886 <= 2) {
            w->unk_886++;
            w->unk_8B7 = 1;
            m4aSongNumStart(SONG_SYS_CLICKI04B);
        } else {
            func_0808C9CC((u8*)w);
            if (w->unk_8CF != 0) {
                if ((u16)w->unk_876 <= 3) {
                    w->y3 = gUnk_09035956[w->unk_876] << 8;
                } else {
                    w->y3 = -0x10000;
                }
            }
        }
        break;
    case DPAD_LEFT:
        if (w->unk_884 > 0) {
            w->unk_884--;
            w->unk_8B7 = 1;
            m4aSongNumStart(SONG_SYS_CLICKI04B);
        }
        break;
    case DPAD_RIGHT:
        if (w->unk_884 > 1) {
            if (w->unk_8CF == 0) {
                w->unk_884 = 0;
                w->unk_886 = w->unk_8C0;
                w->unk_8B7 = 1;
                w->unk_8B2 = w->unk_8B1;
                w->unk_8B1 = 1;
                func_0808CD48((u8*)w);
                m4aSongNumStart(SONG_SYS_CLICK);
                SetTaskUpdate(a, (TaskUpdateFunc)func_080889DC);
                return 1;
            }
        } else {
            w->unk_884++;
            w->unk_8B7 = 1;
            m4aSongNumStart(SONG_SYS_CLICKI04B);
        }
        break;
    }
    switch ((u16)GetKeysPressed()) {
    case B_BUTTON:
        if (w->unk_8CF == 0) {
            w->unk_884 = 0;
            w->unk_886 = w->unk_8C0;
            w->unk_8B7 = 1;
            w->unk_8B2 = w->unk_8B1;
            w->unk_8B1 = 1;
            func_0808CD48((u8*)w);
            m4aSongNumStart(SONG_SYS_CLICK);
            SetTaskUpdate(a, (TaskUpdateFunc)func_080889DC);
            return 1;
        } else {
            m4aSongNumStart(SONG_SYS_CLOSE);
            w->unk_8CF = 0;
            AnimStart(&w->anim2, 0, 1);
            return 1;
        }
    case A_BUTTON:
        if (w->unk_8C1 != 0) {
            return 1;
        }
        if (w->unk_8CF == 0) {
            m4aSongNumStart(SONG_SYS_KETEI2);
            w->unk_8CF = 1;
            w->unk_874 = w->unk_884;
            w->unk_876 = w->unk_886;
            w->x3 = gUnk_09035950[w->unk_874] << 8;
            w->y3 = gUnk_09035956[w->unk_876] << 8;
            AnimStart(&w->anim2, 4, 1);
        } else {
            if ((u8)func_0808EDA4((u8*)w) != 0) {
                m4aSongNumStart(SONG_SYS_KETEI2);
                w->unk_8CF = 0;
                AnimStart(&w->anim2, 0, 1);
            } else {
                m4aSongNumStart(SONG_SYS_BEEP);
            }
        }
        return 1;
    case START_BUTTON:
        if ((u8)func_0808E750((u8*)w) != 0 && (u8)func_0808E79C((u8*)w) != 0) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808B208);
            FadeStartOut(0, 4);
            m4aSongNumStart(SONG_SYS_CLOSE);
            w->unk_8D2 = 7;
        }
        return 1;
    case L_BUTTON:
        m4aSongNumStart(SONG_SYS_CANSEL);
        w->unk_8CF = 0;
        AnimStart(&w->anim2, 0, 1);
        SetTaskUpdate(a, (TaskUpdateFunc)func_08089EC0);
        return 1;
    case R_BUTTON:
        func_0808E2F0((UnkStruct_0808DB04*)w);
        m4aSongNumStart(SONG_SYS_CANSEL);
        w->unk_8CF = 0;
        AnimStart(&w->anim2, 0, 1);
        SetTaskUpdate(a, (TaskUpdateFunc)func_080892E8);
        return 1;
    }
    if (GetKeysPressed() & SELECT_BUTTON) {
        w->unk_8CF = 0;
        w->unk_886 = 0;
        w->unk_8AC = 4;
        func_0808E7D8((u8*)w);
        w->x2 = 0x4800;
        w->y2 = 0x2800;
        w->unk_884 = w->unk_8C1;
        w->unk_8B7 = 1;
        m4aSongNumStart(SONG_SYS_CLICKI04B);
        w->unk_8B1 = 2;
        AnimStart(&w->anim2, 0, 1);
        TaskPoolUpdate(&w->taskpool);
        TaskPoolUpdate(&w->cardpool);
        SetTaskUpdate(a, (TaskUpdateFunc)func_080870FC);
        func_0808DE28(0);
        return 1;
    }
    w->unk_4C8 = func_0808CB60((u8*)w);
    ApproachValueHalf(&w->x, gUnk_09035950[w->unk_884] << 8);
    ApproachValueHalf(&w->y, gUnk_09035956[w->unk_886] << 8);
    if (w->unk_8B7 != 0) {
        w->unk_8B7--;
    }
    w->unk_4CC = w->unk_4C8;
    w->unk_8B3[0] = w->unk_884;
    w->unk_8B3[1] = w->unk_886;
    TaskPoolUpdate(&w->taskpool);
    TaskPoolUpdate(&w->cardpool);
    return 1;
}

u8 func_080870FC(UnkStruct_0808DB04* w, void* a) {
    *(void**)&w->unk_4E8[8] = AnimUpdate(&w->anim2);
    if (w->unk_8C8[1] != 0) {
        ApproachValueHalf(&w->x, gUnk_090356F8[w->unk_884] << 8);
        ApproachValueHalf(&w->y, 0x1E00);
        TaskPoolUpdate(&w->tasks);
        TaskPoolUpdate(&w->tasks2);
        if (GetKeysPressed() & START_BUTTON) {
            w->unk_8D1[1] = 7;
            w->unk_8C8[3] = 1;
        }
        w->unk_8C8[6] = 4;
        return 1;
    }
    if (w->unk_8C8[3] != 0) {
        if ((u8)func_0808E750(w) != 0 && (u8)func_0808E79C(w) != 0) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808B208);
            FadeStartOut(0, 4);
            m4aSongNumStart(SONG_SYS_CANSEL);
            return 1;
        }
        w->unk_8C8[3] = 0;
    }
    switch (GetKeysRepeat()) {
    case DPAD_LEFT:
        if (w->unk_884 > 0) {
            w->unk_884--;
            w->unk_8B7 = 1;
            m4aSongNumStart(SONG_SYS_CLICK);
            w->unk_8C1 = w->unk_884;
            func_0808D438(w->unk_8C1, w->unk_8C7);
            func_0808C90C((u8*)w);
            func_0808C3DC((u8*)w, w->unk_8C1);
        }
        break;
    case DPAD_RIGHT:
        if (w->unk_884 < 4) {
            w->unk_884++;
            w->unk_8B7 = 1;
            m4aSongNumStart(SONG_SYS_CLICK);
            w->unk_8C1 = w->unk_884;
            func_0808D438(w->unk_8C1, w->unk_8C7);
            func_0808C90C((u8*)w);
            func_0808C3DC((u8*)w, w->unk_8C1);
        }
        break;
    }
    switch (GetKeysPressed()) {
    case B_BUTTON:
    case DPAD_DOWN:
        w->unk_884 = 0;
        w->unk_886 = 0;
        w->unk_8B7 = 1;
        m4aSongNumStart(SONG_SYS_CLICKI04B);
        if (w->unk_8B1 == 2) {
            w->unk_8B1 = 0;
            SetTaskUpdate(a, (TaskUpdateFunc)func_08086984);
        }
        if (w->unk_8B1 == 8) {
            w->unk_8B1 = 7;
            func_0808DB50(w);
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808A218);
        }
        w->x2 = 0x4800;
        w->y2 = 0x2800;
        *(u16*)&w->unk_8AC = 4;
        return 1;
    case R_BUTTON:
        func_0808E2F0(w);
        w->unk_8C8[2] = 1;
        SetTaskUpdate(a, (TaskUpdateFunc)func_080892E8);
        m4aSongNumStart(SONG_SYS_CANSEL);
        return 1;
    case L_BUTTON:
        if (w->unk_8B1 == 2) {
            m4aSongNumStart(SONG_SYS_CANSEL);
            SetTaskUpdate(a, (TaskUpdateFunc)func_08089EC0);
        }
        return 1;
    case START_BUTTON:
        if ((u8)func_0808E750(w) != 0 && (u8)func_0808E79C(w) != 0) {
            m4aSongNumStart(SONG_SYS_CLOSE);
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808B208);
            FadeStartOut(0, 16);
            w->unk_8D1[1] = 7;
        }
        return 1;
    }
    ApproachValueHalf(&w->x, gUnk_090356F8[w->unk_884] << 8);
    ApproachValueHalf(&w->y, 0x1E00);
    TaskPoolUpdate(&w->tasks);
    TaskPoolUpdate(&w->tasks2);
    return 1;
}

u8 func_08087438(UnkStruct_0808DB04* w, void* a) {
    UnkStruct_09035730 table = gUnk_09035730;

    *(void**)&w->unk_4E8[8] = AnimUpdate(&w->anim2);
    *(void**)&w->unk_4E8[12] = AnimUpdate(&w->anim3);
    if (GetKeysPressed() & DPAD_LEFT) {
        if (w->unk_8D1[0] != 0) {
            w->unk_8D1[0]--;
        }
        w->unk_8B7 = 1;
        m4aSongNumStart(SONG_SYS_CLICK);
    }
    if (GetKeysPressed() & DPAD_RIGHT) {
        if (w->unk_8D1[0] == 0) {
            w->unk_8D1[0]++;
        }
        w->unk_8B7 = 1;
        m4aSongNumStart(SONG_SYS_CLICK);
    }
    if (GetKeysPressed() & A_BUTTON) {
        if (w->unk_8D1[0] == 1) {
            w->unk_8B7 = 1;
            w->unk_8B1 = 11;
            func_0808CD48((u8*)w);
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808778C);
            TaskPoolUpdate(&w->tasks);
            TaskPoolUpdate(&w->tasks2);
            m4aSongNumStart(SONG_SYS_CANSEL);
            return 1;
        }
        w->unk_8B7 = 1;
        func_0808E58C(w);
        func_0808D594();
        func_0808500C(3, w->unk_89A);
        func_0808CC58(*(u16*)&w->unk_89A[0], 0);
        func_0808CC58(*(u16*)&w->unk_89A[2], 1);
        func_0808CC58(*(u16*)&w->unk_89A[4], 2);
        func_0808CC58(*(u16*)&w->unk_89A[6], 3);
        if ((u8)func_0808DED0(w, 0) == 0) {
            func_08087B98(w, 1);
            if (w->unk_8D4 != 0) {
                func_0808E364((u8*)w, 0);
                w->unk_884 = (s8)w->unk_8B2[3];
                w->unk_886 = (s8)w->unk_8B2[4];
                while ((u8)func_0808E890(w) == 0) {
                    w->unk_884--;
                    if (w->unk_884 < 0) {
                        w->unk_886--;
                        if ((s16)w->unk_886 < 0) {
                            func_0808CA78(w, 0);
                            w->unk_886 = 0;
                        }
                        w->unk_884 = 2;
                    }
                }
                w->x = gUnk_0903595E[w->unk_884] << 8;
                w->y = gUnk_09035964[(s16)w->unk_886] << 8;
                func_0808D828((u8*)w);
                w->unk_8B1 = 9;
                func_0808CD48((u8*)w);
                SetTaskUpdate(a, (TaskUpdateFunc)func_0808AB48);
                TaskPoolUpdate(&w->tasks);
                TaskPoolUpdate(&w->tasks2);
                return 1;
            } else {
                func_0808E364((u8*)w, 0);
                w->unk_884 = w->unk_8C1;
                w->unk_8B7 = 1;
                w->unk_8B1 = 10;
                func_0808CD48((u8*)w);
                SetTaskUpdate(a, (TaskUpdateFunc)func_080882DC);
                w->unk_8D4 = 0;
                TaskPoolUpdate(&w->tasks);
                TaskPoolUpdate(&w->tasks2);
                return 1;
            }
        } else {
            func_0808DDD0(w);
            w->unk_8B1 = 11;
            func_0808CD48((u8*)w);
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808778C);
            TaskPoolUpdate(&w->tasks);
            TaskPoolUpdate(&w->tasks2);
            return 1;
        }
    } else if (GetKeysPressed() & B_BUTTON) {
        w->unk_8B7 = 1;
        w->unk_8B1 = 11;
        func_0808CD48((u8*)w);
        m4aSongNumStart(SONG_SYS_CANSEL);
        SetTaskUpdate(a, (TaskUpdateFunc)func_0808778C);
        TaskPoolUpdate(&w->tasks);
        TaskPoolUpdate(&w->tasks2);
        return 1;
    } else {
        ApproachValueHalf(&w->x, table.unk_00[w->unk_8D1[0]] << 8);
        ApproachValueHalf(&w->y, 0x7200);
        TaskPoolUpdate(&w->tasks);
        TaskPoolUpdate(&w->tasks2);
        return 1;
    }
}

u8 func_0808778C(UnkStruct_080889DC* w, void* a) {
    u8 n;
    s16 v;

    if (w->unk_8C9 != 0) {
        TaskPoolUpdate(&w->taskpool);
        TaskPoolUpdate(&w->cardpool);

        if (GetKeysPressed() & START_BUTTON) {
            w->unk_8D2 = 7;
            w->unk_8CB = 1;
        }

        w->unk_8CE = 8;
        return 1;
    }

    if (w->unk_8CB != 0) {
        if ((u8)func_0808E750((u8*)w) != 0 && (u8)func_0808E79C((u8*)w) != 0) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808B208);
            FadeStartOut(0, 4);
            m4aSongNumStart(SONG_SYS_CANSEL);
            return 1;
        }

        w->unk_8CB = 0;
    }

    w->gfx = AnimUpdate(&w->anim2);
    w->gfx2 = AnimUpdate(&w->anim3);

    switch (GetKeysRepeat()) {
    case DPAD_LEFT:
    case (DPAD_LEFT | DPAD_UP):
    case (DPAD_LEFT | DPAD_DOWN):
        if (w->unk_884 > 0) {
            (w->unk_884)--;
            w->unk_8B7 = 1;

            if ((u8)func_0808DED0((u8*)w, 32) != 0) {
                m4aSongNumStart(SONG_SYS_CLICK);
            }
        }

        func_0808DDD0((u8*)w);
        break;
    case DPAD_RIGHT:
    case (DPAD_RIGHT | DPAD_UP):
    case (DPAD_RIGHT | DPAD_DOWN):
        if (w->unk_884 <= 0) {
            (w->unk_884)++;
            w->unk_8B7 = 1;

            if ((u8)func_0808DED0((u8*)w, 16) != 0) {
                m4aSongNumStart(SONG_SYS_CLICK);
            }
        }

        func_0808DDD0((u8*)w);
        break;
    case DPAD_UP:
        n = w->unk_886;

        if (w->unk_886 > 0) {
            w->unk_886 = w->unk_886 - 1;
        } else {
            w->unk_886 = 4;
        }

        w->unk_8B7 = 1;
        func_0808DED0((u8*)w, 64);

        if ((s8)n != w->unk_886) {
            m4aSongNumStart(SONG_SYS_CLICK);
        }

        func_0808DDD0((u8*)w);
        break;
    case DPAD_DOWN:
        n = w->unk_886;

        if (w->unk_886 <= 3) {
            w->unk_886 = w->unk_886 + 1;
        } else {
            w->unk_886 = 0;
        }

        w->unk_8B7 = 1;
        func_0808DED0((u8*)w, 128);

        if ((s8)n != w->unk_886) {
            m4aSongNumStart(SONG_SYS_CLICK);
        }

        func_0808DDD0((u8*)w);
        break;
    }

    switch (GetKeysPressed()) {
    case B_BUTTON:
        func_0808E364((u8*)w, 0);
        v = w->unk_8B5;
        w->unk_884 = v;
        v = w->unk_8B6;
        w->unk_886 = v;
        w->x = gUnk_0903595E[w->unk_884] << 8;
        w->y = gUnk_09035964[w->unk_886] << 8;
        func_0808D828((u8*)w);
        w->unk_8B1 = 9;
        m4aSongNumStart(SONG_SYS_CLOSE);
        SetTaskUpdate(a, (TaskUpdateFunc)func_0808AB48);
        return 1;
    case A_BUTTON:
        if (w->unk_8CE > 0) {
            return 1;
        }

        if ((u8)func_0808E474((u8*)w) == 0) {
            return 1;
        }

        TaskCreate(&w->cardpool, &gTaskDescDeckYesNo, &w->unk_8C9);
        w->unk_8D1 = 1;
        SetTaskUpdate(a, (TaskUpdateFunc)func_08087438);
        w->unk_8B7 = 1;
        w->unk_8B1 = 12;
        m4aSongNumStart(SONG_SYS_CLOSE);
        func_0808CD48((u8*)w);
        return 1;
    case START_BUTTON:
        if ((u8)func_0808E750((u8*)w) != 0 && (u8)func_0808E79C((u8*)w) != 0) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808B208);
            FadeStartOut(0, 4);
            m4aSongNumStart(SONG_SYS_CLOSE);
            w->unk_8D2 = 7;
        }

        return 1;
    }

    ApproachValueHalf(&w->x, gUnk_0903571A[w->unk_884] << 8);
    ApproachValueHalf(&w->y, (gUnk_0903571E[w->unk_886] - 16) << 8);

    if (w->unk_8CE > 0) {
        w->unk_8CE--;
    }

    TaskPoolUpdate(&w->taskpool);
    TaskPoolUpdate(&w->cardpool);
    return 1;
}

void func_08087B98(UnkStruct_0808DB04* w, u8 mode) {
    DeckCard2Work* node;
    DeckCard2Work* p;
    UnkStruct_0808E2F0* e;
    s32 i;

    node = ListPoolFirst(&w->pool);
    i = 0;
    e = &w->unk_4D4[w->unk_880];
    EwramFree(w->unk_4D4[w->unk_880].unk_1C);
    w->unk_4D4[w->unk_880].unk_1C = 0;

    for (i = w->unk_880; i < w->unk_898 - 1; i++) {
        w->unk_4D4[i] = w->unk_4D4[i + 1];
    }

    w->unk_898 -= 1;
    w->unk_8D4 -= 1;

    while (node != 0) {
        if (node->unk_22 == w->unk_8B5 && node->unk_24 == w->unk_8B6) {
            break;
        }

        node = ListPoolNext(&node->node);
    }

    p = ListPoolNext(&node->node);

    while (p != 0) {
        p->unk_22--;

        if (p->unk_22 < 0) {
            p->unk_22 = 2;
            p->unk_24--;
        }

        p = ListPoolNext(&p->node);
    }

    node->unk_4A = 1;
    TaskPoolUpdate(&w->tasks);
    func_0808D828((u8*)w);
#ifdef VERSION_EU
    func_0808C940((UnkStruct_0808C940*)w, (s16)w->unk_8D4);
#else
    func_0808C940((UnkStruct_0808C940*)w, (s16)w->unk_898);
#endif
    func_0808C974((UnkStruct_0808C940*)w);
}

u8 func_08087CD4(UnkStruct_080889DC* w, void* a) {
    u8 n;

    if (w->unk_8C9 != 0) {
        TaskPoolUpdate(&w->taskpool);
        TaskPoolUpdate(&w->cardpool);

        if (GetKeysPressed() & START_BUTTON) {
            w->unk_8D2 = 7;
            w->unk_8CB = 1;
        }

        return 1;
    }

    if (w->unk_8CB != 0) {
        if ((u8)func_0808E750((u8*)w) != 0 && (u8)func_0808E79C((u8*)w) != 0) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808B208);
            FadeStartOut(0, 4);
            m4aSongNumStart(SONG_SYS_CANSEL);
            return 1;
        }

        w->unk_8CB = 0;
    }

    w->gfx = AnimUpdate(&w->anim2);
    w->gfx2 = AnimUpdate(&w->anim3);

    switch ((u16)GetKeysRepeat()) {
    case DPAD_LEFT:
    case (DPAD_LEFT | DPAD_UP):
    case (DPAD_LEFT | DPAD_DOWN):
        if (w->unk_884 > 0) {
            (w->unk_884)--;
            w->unk_8B7 = 1;

            if ((u8)func_0808DED0((u8*)w, 32) != 0) {
                m4aSongNumStart(SONG_SYS_CLICK);
            }
        }

        func_0808DDD0((u8*)w);
        break;
    case DPAD_RIGHT:
    case (DPAD_RIGHT | DPAD_UP):
    case (DPAD_RIGHT | DPAD_DOWN):
        if (w->unk_884 <= 0) {
            (w->unk_884)++;
            w->unk_8B7 = 1;

            if ((u8)func_0808DED0((u8*)w, 16) != 0) {
                m4aSongNumStart(SONG_SYS_CLICK);
            }
        }

        func_0808DDD0((u8*)w);
        break;
    case DPAD_UP:
        n = w->unk_886;

        if (w->unk_886 > 0) {
            w->unk_886 = w->unk_886 - 1;
        } else {
            w->unk_886 = 4;
        }

        w->unk_8B7 = 1;
        func_0808DED0((u8*)w, 64);

        if ((s8)n != w->unk_886) {
            m4aSongNumStart(SONG_SYS_CLICK);
        }

        func_0808DDD0((u8*)w);
        break;
    case DPAD_DOWN:
        n = w->unk_886;

        if (w->unk_886 <= 3) {
            w->unk_886 = w->unk_886 + 1;
        } else {
            w->unk_886 = 0;
        }

        w->unk_8B7 = 1;
        func_0808DED0((u8*)w, 128);

        if ((s8)n != w->unk_886) {
            m4aSongNumStart(SONG_SYS_CLICK);
        }

        func_0808DDD0((u8*)w);
        break;
    }

    switch ((u16)GetKeysPressed()) {
    case B_BUTTON:
        func_0808E364((u8*)w, 0);
        n = w->unk_8B5;
        w->unk_884 = (s8)n;
        n = w->unk_8B6;
        w->unk_886 = (s8)n;
        w->x = gUnk_0903595E[w->unk_884] << 8;
        w->y = gUnk_09035964[w->unk_886] << 8;
        func_0808D828((u8*)w);
        func_0808DE28(0);
        w->unk_8B1 = 4;
        SetTaskUpdate(a, (TaskUpdateFunc)func_080897CC);
        m4aSongNumStart(SONG_SYS_CLOSE);
        return 1;
    case A_BUTTON:
        if ((u16)GetDeckCardCount(w->unk_8C0) <= 98) {
            func_0808E19C((u8*)w);
            func_0808D0A4(w->unk_8C0);
            func_0808D258(w->unk_8C0);
            w->unk_8A2 = func_08085844(0, w->unk_8C0);
            w->unk_8A4 = func_08085844(1, w->unk_8C0);
            w->unk_8A6 = func_08085844(2, w->unk_8C0);
            w->unk_8A8 = func_08085844(3, w->unk_8C0);
            func_0808CBB4((u8)w->unk_8A2, 0);
            func_0808CBB4((u8)w->unk_8A4, 1);
            func_0808CBB4((u8)w->unk_8A6, 2);
            func_0808CBB4((u8)w->unk_8A8, 3);
            func_0808D594();
            func_0808500C(w->unk_8C0, w->unk_89A);
            func_0808CC58(w->unk_89A[0], 0);
            func_0808CC58(w->unk_89A[1], 1);
            func_0808CC58(w->unk_89A[2], 2);
            func_0808CC58(w->unk_89A[3], 3);
            w->unk_8B7 = 1;
            if ((u8)func_0808DED0((u8*)w, 0) == 0) {
                func_08087B98((UnkStruct_0808DB04*)w, 0);
                if (w->unk_8D4 != 0) {
                    u8 ready;
                    func_0808E364((u8*)w, 0);
                    w->unk_884 = w->unk_8B5;
                    w->unk_886 = w->unk_8B6;
                    while ((ready = func_0808E890((u8*)w)) == 0) {
                        if (--w->unk_884 < 0) {
                            if (--w->unk_886 < 0) {
                                func_0808CA78((u8*)w, 0);
                                w->unk_886 = ready;
                            }
                            w->unk_884 = 2;
                        }
                    }
                    w->x = gUnk_0903595E[w->unk_884] << 8;
                    w->y = gUnk_09035964[w->unk_886] << 8;
                    func_0808D828((u8*)w);
                    w->unk_8B1 = 4;
                    SetTaskUpdate(a, (TaskUpdateFunc)func_080897CC);
                    return 1;
                } else {
                    func_0808E364((u8*)w, 0);
                    w->unk_884 = w->unk_8C1;
                    w->unk_8B7 = 1;
                    w->unk_8B1 = 6;
                    SetTaskUpdate(a, (TaskUpdateFunc)func_080882DC);
                    w->unk_8D4 = 0;
                    return 1;
                }
            } else {
                func_0808DDD0((u8*)w);
            }
        } else {
            m4aSongNumStart(SONG_SYS_BEEP);
            TaskCreate(&w->cardpool, &gUnk_09EE7FF0, &w->unk_8C9);
            return 1;
        }
        break;
    case L_BUTTON:
        func_0808E2F0((UnkStruct_0808DB04*)w);
        SetTaskUpdate(a, (TaskUpdateFunc)func_08089EC0);
        m4aSongNumStart(SONG_SYS_CANSEL);
        return 1;
    case START_BUTTON:
        if ((u8)func_0808E750((u8*)w) != 0 && (u8)func_0808E79C((u8*)w) != 0) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808B208);
            FadeStartOut(0, 4);
            m4aSongNumStart(SONG_SYS_CLOSE);
            w->unk_8D2 = 7;
        }
        return 1;
    }
    ApproachValueHalf(&w->x, gUnk_0903571A[w->unk_884] << 8);
    ApproachValueHalf(&w->y, gUnk_0903571E[w->unk_886] << 8);
    TaskPoolUpdate(&w->taskpool);
    TaskPoolUpdate(&w->cardpool);
    return 1;
}

u8 func_080882DC(u8* work, void* a) {
    u16 i;
    u16 n;

    *(void**)&work[0x4F0] = AnimUpdate((AnimState*)&work[CARDWORK(0x800)]);

    if (work[CARDWORK(0x8C9)] != 0) {
        ApproachValueHalf((s32*)&work[CARDWORK(0x848)], gUnk_09035702[*(s16*)&work[CARDWORK(0x884)]] << 8);
        ApproachValueHalf((s32*)&work[CARDWORK(0x84C)], 0x1E00);
        TaskPoolUpdate((TaskPool*)&work[CARDWORK(0x7C8)]);
        TaskPoolUpdate((TaskPool*)&work[CARDWORK(0x7DC)]);

        if (GetKeysPressed() & START_BUTTON) {
            work[CARDWORK(0x8D2)] = 7;
            work[CARDWORK(0x8CB)] = 1;
        }

        return 1;
    }

    if (work[CARDWORK(0x8CB)] != 0) {
        if ((u8)func_0808E750(work) != 0 && (u8)func_0808E79C(work) != 0) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808B208);
            FadeStartOut(0, 4);
            m4aSongNumStart(SONG_SYS_CANSEL);
            return 1;
        }

        work[CARDWORK(0x8CB)] = 0;
    }

    switch (GetKeysRepeat()) {
    case DPAD_LEFT:
        if (*(s16*)&work[CARDWORK(0x884)] > 1) {
            (*(s16*)&work[CARDWORK(0x884)])--;
            work[CARDWORK(0x8B7)] = 1;
            m4aSongNumStart(SONG_SYS_CLICK);
            n = *(u16*)&work[CARDWORK(0x884)];
            work[CARDWORK(0x8C1)] = n;
            func_0808D4E4(work[CARDWORK(0x8C1)], work[CARDWORK(0x8C7)]);
            func_0808C90C(work);

            if (work[CARDWORK(0x8B1)] == 6) {
                *(u16*)&work[CARDWORK(0x8D4)] = func_0808C60C(work, work[CARDWORK(0x8C1)], 0);
            } else {
                *(u16*)&work[CARDWORK(0x8D4)] = func_0808C60C(work, work[CARDWORK(0x8C1)], 1);
            }
        }

        for (i = 0; i <= 9; i++) {
            func_0808DD20(0, i);
        }
        break;
    case DPAD_RIGHT:
        if (*(s16*)&work[CARDWORK(0x884)] <= 4) {
            (*(s16*)&work[CARDWORK(0x884)])++;
            work[CARDWORK(0x8B7)] = 1;
            m4aSongNumStart(SONG_SYS_CLICK);
            n = *(u16*)&work[CARDWORK(0x884)];
            work[CARDWORK(0x8C1)] = n;
            func_0808D4E4(work[CARDWORK(0x8C1)], work[CARDWORK(0x8C7)]);
            func_0808C90C(work);

            if (work[CARDWORK(0x8B1)] == 6) {
                *(u16*)&work[CARDWORK(0x8D4)] = func_0808C60C(work, work[CARDWORK(0x8C1)], 0);
            } else {
                *(u16*)&work[CARDWORK(0x8D4)] = func_0808C60C(work, work[CARDWORK(0x8C1)], 1);
            }
        }

        for (i = 0; i <= 9; i++) {
            func_0808DD20(0, i);
        }
        break;
    case DPAD_DOWN:
        if (*(u16*)&work[CARDWORK(0x8D4)] != 0) {
            *(s16*)&work[CARDWORK(0x884)] = 0;
            *(s16*)&work[CARDWORK(0x886)] = 0;
            work[CARDWORK(0x8B7)] = 1;
            m4aSongNumStart(SONG_SYS_CLICKI04B);
            func_0808D828(work);

            if (work[CARDWORK(0x8B1)] == 6) {
                work[CARDWORK(0x8B1)] = 4;
                SetTaskUpdate(a, (TaskUpdateFunc)func_080897CC);
            }

            if (work[CARDWORK(0x8B1)] == 10) {
                work[CARDWORK(0x8B1)] = 9;
                SetTaskUpdate(a, (TaskUpdateFunc)func_0808AB48);
            }
        } else {
            m4aSongNumStart(SONG_SYS_BEEP);
        }

        *(s32*)&work[CARDWORK(0x850)] = 0xA000;
        *(s32*)&work[CARDWORK(0x854)] = 0x2800;
        *(u16*)&work[CARDWORK(0x8AC)] = 4;
        return 1;
    case B_BUTTON:
        if (*(u16*)&work[CARDWORK(0x8D4)] != 0) {
            *(s16*)&work[CARDWORK(0x884)] = 0;
            *(s16*)&work[CARDWORK(0x886)] = 0;
            work[CARDWORK(0x8B7)] = 1;
            m4aSongNumStart(SONG_SYS_CLICKI04B);
            func_0808D828(work);

            if (work[CARDWORK(0x8B1)] == 6) {
                work[CARDWORK(0x8B1)] = 4;
                SetTaskUpdate(a, (TaskUpdateFunc)func_080897CC);
            }

            if (work[CARDWORK(0x8B1)] == 10) {
                work[CARDWORK(0x8B1)] = 9;
                SetTaskUpdate(a, (TaskUpdateFunc)func_0808AB48);
            }
        } else {
            m4aSongNumStart(SONG_SYS_CANSEL);

            if (work[CARDWORK(0x8B1)] == 6) {
                SetTaskUpdate(a, (TaskUpdateFunc)func_08089D20);
            }

            if (work[CARDWORK(0x8B1)] == 10) {
                SetTaskUpdate(a, (TaskUpdateFunc)func_0808B068);
            }
        }

        *(s32*)&work[CARDWORK(0x850)] = 0xA000;
        *(s32*)&work[CARDWORK(0x854)] = 0x2800;
        *(u16*)&work[CARDWORK(0x8AC)] = 4;
        return 1;
    case L_BUTTON:
        if (work[CARDWORK(0x8B1)] == 6) {
            FadeStartIn(0, 1);
            func_0808E2F0((UnkStruct_0808DB04*)work);
            SetTaskUpdate(a, (TaskUpdateFunc)func_08089EC0);
            m4aSongNumStart(SONG_SYS_CANSEL);
            return 1;
        }
        break;
    case START_BUTTON:
        if ((u8)func_0808E750(work) != 0 && (u8)func_0808E79C(work) != 0) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808B208);
            FadeStartOut(0, 4);
            m4aSongNumStart(SONG_SYS_CLOSE);
            work[CARDWORK(0x8D2)] = 7;
        }

        return 1;
    }

    ApproachValueHalf((s32*)&work[CARDWORK(0x848)], gUnk_09035702[*(s16*)&work[CARDWORK(0x884)]] << 8);
    ApproachValueHalf((s32*)&work[CARDWORK(0x84C)], 0x1E00);
    TaskPoolUpdate((TaskPool*)&work[CARDWORK(0x7C8)]);
    TaskPoolUpdate((TaskPool*)&work[CARDWORK(0x7DC)]);
    return 1;
}

u8 func_08088768(u8* work, void* a) {
#ifdef VERSION_EU
    UnkStruct_09035730 tbl;

    tbl = gUnk_09035730;
    *(void**)&work[0x4F0] = AnimUpdate(&work[0x804]);
    *(void**)&work[0x4F4] = AnimUpdate(&work[0x81C]);

    if (GetKeysPressed() & DPAD_LEFT) {
        if (work[0x8D5] != 0) {
            work[0x8D5]--;
        }

        work[0x8BB] = 1;
        m4aSongNumStart(SONG_SYS_CLICK);
    }

    if (GetKeysPressed() & DPAD_RIGHT) {
        if (work[0x8D5] == 0) {
            work[0x8D5]++;
        }

        work[0x8BB] = 1;
        m4aSongNumStart(SONG_SYS_CLICK);
    }

    if (GetKeysPressed() & A_BUTTON) {
        if (work[0x8D5] == 1) {
            work[0x8BB] = 1;
            work[0x8B5] = 3;
            func_0808CD48(work);
            SetTaskUpdate(a, (TaskUpdateFunc)func_08088F24);
            TaskPoolUpdate(&work[0x7CC]);
            TaskPoolUpdate(&work[0x7E0]);
            m4aSongNumStart(SONG_SYS_CANSEL);
            return 1;
        }

        m4aSongNumStart(SONG_SYS_KETTEI);
        ClearDeck(work[0x8C4]);
        func_0808D0A4(work[0x8C4]);
        func_0808D258(work[0x8C4]);
        func_0808D594();
        *(u16*)&work[0x8A6] = func_08085844(0, work[0x8C4]);
        *(u16*)&work[0x8A8] = func_08085844(1, work[0x8C4]);
        *(u16*)&work[0x8AA] = func_08085844(2, work[0x8C4]);
        *(u16*)&work[0x8AC] = func_08085844(3, work[0x8C4]);
        func_0808CBB4(*(u16*)&work[0x8A6], 0);
        func_0808CBB4(*(u16*)&work[0x8A8], 1);
        func_0808CBB4(*(u16*)&work[0x8AA], 2);
        func_0808CBB4(*(u16*)&work[0x8AC], 3);
        func_0808C90C(work);
        TaskPoolUpdate(&work[0x7CC]);
        TaskPoolUpdate(&work[0x7E0]);
        work[0x8BB] = 1;
        work[0x8B5] = 3;
        func_0808CD48(work);
        SetTaskUpdate(a, (TaskUpdateFunc)func_08088F24);
    }

    if (GetKeysPressed() & B_BUTTON) {
        work[0x8BB] = 1;
        work[0x8B5] = 3;
        func_0808CD48(work);
        m4aSongNumStart(SONG_SYS_CANSEL);
        SetTaskUpdate(a, (TaskUpdateFunc)func_08088F24);
        TaskPoolUpdate(&work[0x7CC]);
        TaskPoolUpdate(&work[0x7E0]);
        return 1;
    }

    ApproachValueHalf((s32*)&work[0x84C], tbl.unk_00[work[0x8D5]] << 8);
    ApproachValueHalf((s32*)&work[0x850], 0x7200);
    TaskPoolUpdate(&work[0x7CC]);
    TaskPoolUpdate(&work[0x7E0]);
    return 1;
#else
    UnkStruct_09035730 tbl;

    tbl = gUnk_09035730;
    *(void**)&work[0x4F0] = AnimUpdate(&work[0x800]);
    *(void**)&work[0x4F4] = AnimUpdate(&work[0x818]);

    if (GetKeysPressed() & DPAD_LEFT) {
        if (work[0x8D1] != 0) {
            work[0x8D1]--;
        }

        work[0x8B7] = 1;
        m4aSongNumStart(SONG_SYS_CLICK);
    }

    if (GetKeysPressed() & DPAD_RIGHT) {
        if (work[0x8D1] == 0) {
            work[0x8D1]++;
        }

        work[0x8B7] = 1;
        m4aSongNumStart(SONG_SYS_CLICK);
    }

    if (GetKeysPressed() & A_BUTTON) {
        if (work[0x8D1] == 1) {
            work[0x8B7] = 1;
            work[0x8B1] = 3;
            func_0808CD48(work);
            SetTaskUpdate(a, (TaskUpdateFunc)func_08088F24);
            TaskPoolUpdate(&work[0x7C8]);
            TaskPoolUpdate(&work[0x7DC]);
            m4aSongNumStart(SONG_SYS_CANSEL);
            return 1;
        }

        m4aSongNumStart(SONG_SYS_KETTEI);
        ClearDeck(work[0x8C0]);
        func_0808D0A4(work[0x8C0]);
        func_0808D258(work[0x8C0]);
        func_0808D594();
        *(u16*)&work[0x8A2] = func_08085844(0, work[0x8C0]);
        *(u16*)&work[0x8A4] = func_08085844(1, work[0x8C0]);
        *(u16*)&work[0x8A6] = func_08085844(2, work[0x8C0]);
        *(u16*)&work[0x8A8] = func_08085844(3, work[0x8C0]);
        func_0808CBB4(*(u16*)&work[0x8A2], 0);
        func_0808CBB4(*(u16*)&work[0x8A4], 1);
        func_0808CBB4(*(u16*)&work[0x8A6], 2);
        func_0808CBB4(*(u16*)&work[0x8A8], 3);
        func_0808C90C(work);
        TaskPoolUpdate(&work[0x7C8]);
        TaskPoolUpdate(&work[0x7DC]);
        work[0x8B7] = 1;
        work[0x8B1] = 3;
        func_0808CD48(work);
        SetTaskUpdate(a, (TaskUpdateFunc)func_08088F24);
    }

    if (GetKeysPressed() & B_BUTTON) {
        work[0x8B7] = 1;
        work[0x8B1] = 3;
        func_0808CD48(work);
        m4aSongNumStart(SONG_SYS_CANSEL);
        SetTaskUpdate(a, (TaskUpdateFunc)func_08088F24);
        TaskPoolUpdate(&work[0x7C8]);
        TaskPoolUpdate(&work[0x7DC]);
        return 1;
    }

    ApproachValueHalf((s32*)&work[0x848], tbl.unk_00[work[0x8D1]] << 8);
    ApproachValueHalf((s32*)&work[0x84C], 0x7200);
    TaskPoolUpdate(&work[0x7C8]);
    TaskPoolUpdate(&work[0x7DC]);
    return 1;
#endif
}

u8 func_080889DC(UnkStruct_080889DC* w, void* a) {
    w->gfx = AnimUpdate(&w->anim2);
    w->gfx2 = AnimUpdate(&w->anim3);
#ifdef VERSION_EU
    if ((u8)FadeIsActive() != 0) {
        return 1;
    }
#endif
    if (w->unk_8C9 != 0) {
        ApproachValueHalf(&w->x, gUnk_090356EC[w->unk_884] << 8);
        ApproachValueHalf(&w->y, gUnk_090356F2[w->unk_886] << 8);
        TaskPoolUpdate(&w->taskpool);
        TaskPoolUpdate(&w->cardpool);
        if (GetKeysPressed() & START_BUTTON) {
            w->unk_8D2 = 7;
            w->unk_8CB = 1;
        }
        w->unk_8CE = 4;
        return 1;
    }
    if (w->unk_8CE > 0) {
        TaskPoolUpdate(&w->taskpool);
        TaskPoolUpdate(&w->cardpool);
        w->unk_8CE--;
        return 1;
    }
    if (w->unk_8CB != 0) {
        if ((u8)func_0808E750((u8*)w) != 0 && (u8)func_0808E79C((u8*)w) != 0) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808B208);
            FadeStartOut(0, 4);
            m4aSongNumStart(SONG_SYS_CANSEL);
            return 1;
        } else {
            w->unk_8CB = 0;
        }
    }
    switch ((u16)GetKeysRepeat()) {
    case DPAD_UP:
        if (w->unk_886 > 0) {
            w->unk_886--;
            w->unk_8B7 = 1;
            w->unk_8C0 = w->unk_886;
            func_0808C90C((u8*)w);
            func_0808C3DC((u8*)w, w->unk_8C1);
            w->unk_8A2 = func_08085844(0, w->unk_8C0);
            w->unk_8A4 = func_08085844(1, w->unk_8C0);
            w->unk_8A6 = func_08085844(2, w->unk_8C0);
            w->unk_8A8 = func_08085844(3, w->unk_8C0);
            func_0808CBB4((u8)w->unk_8A2, 0);
            func_0808CBB4((u8)w->unk_8A4, 1);
            func_0808CBB4((u8)w->unk_8A6, 2);
            func_0808CBB4((u8)w->unk_8A8, 3);
            m4aSongNumStart(SONG_SYS_CLICK);
        }
        break;
    case DPAD_DOWN:
        if (w->unk_886 < 2) {
            w->unk_886++;
            w->unk_8C0 = w->unk_886;
            w->unk_8B7 = 1;
            func_0808C90C((u8*)w);
            func_0808C3DC((u8*)w, w->unk_8C1);
            w->unk_8A2 = func_08085844(0, w->unk_8C0);
            w->unk_8A4 = func_08085844(1, w->unk_8C0);
            w->unk_8A6 = func_08085844(2, w->unk_8C0);
            w->unk_8A8 = func_08085844(3, w->unk_8C0);
            func_0808CBB4((u8)w->unk_8A2, 0);
            func_0808CBB4((u8)w->unk_8A4, 1);
            func_0808CBB4((u8)w->unk_8A6, 2);
            func_0808CBB4((u8)w->unk_8A8, 3);
            m4aSongNumStart(SONG_SYS_CLICK);
        }
        break;

    case DPAD_LEFT:
        if (w->unk_886 == 2) {
            w->unk_886 = 3;
        }
        w->unk_884 = 2;
        w->unk_8B7 = 1;
        SetTaskUpdate(a, (TaskUpdateFunc)func_08086984);
        m4aSongNumStart(SONG_SYS_CANSEL);
        return 1;
    }
    switch ((u16)GetKeysPressed()) {
    case A_BUTTON:
        w->unk_8B7 = 1;
        w->unk_8B2 = w->unk_8B1;
        m4aSongNumStart(SONG_SYS_CANSEL);
        SetTaskUpdate(a, (TaskUpdateFunc)func_08088EB4);
        return 1;
    case SELECT_BUTTON:
#ifndef VERSION_EU
        w->unk_8AC = 4;
#endif
        SetActiveDeckIndex(w->unk_8C0);
        func_0808D16C(w->unk_8C0);
        TaskCreate(&w->cardpool, &gTaskDescDeckEquip, &w->unk_8C9);
        m4aSongNumStart(SONG_SYS_DECKSET);
        break;
    case B_BUTTON:
        if ((u8)func_0808E750((u8*)w) != 0 && (u8)func_0808E79C((u8*)w) != 0) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808B238);
            w->unk_8D2 = 8;
            m4aSongNumStart(SONG_SYS_CLOSE);
        }
        return 1;
    case START_BUTTON:
        if ((u8)func_0808E750((u8*)w) != 0 && (u8)func_0808E79C((u8*)w) != 0) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808B208);
            FadeStartOut(0, 4);
            m4aSongNumStart(SONG_SYS_CLOSE);
            w->unk_8D2 = 7;
        }
        return 1;
    case L_BUTTON:
        func_0808E2F0((UnkStruct_0808DB04*)w);
        m4aSongNumStart(SONG_SYS_CANSEL);
        SetTaskUpdate(a, (TaskUpdateFunc)func_08089EC0);
        return 1;
    case R_BUTTON:
        func_0808E2F0((UnkStruct_0808DB04*)w);
        m4aSongNumStart(SONG_SYS_CANSEL);
        SetTaskUpdate(a, (TaskUpdateFunc)func_080892E8);
        return 1;
    }
    func_0808CDE8((u8*)w, w->unk_8C0);
    ApproachValueHalf(&w->x, gUnk_090356EC[w->unk_884] << 8);
    ApproachValueHalf(&w->y, gUnk_090356F2[w->unk_886] << 8);
    TaskPoolUpdate(&w->taskpool);
    TaskPoolUpdate(&w->cardpool);
    return 1;
}

u8 func_08088EB4(u8* work, void* a) {
    u8* p;
    u8 z;

#ifdef VERSION_EU
    *(void**)&work[8] = LoadObjTiles(gUnkEu_09F6FDB4[gLanguage], gUnkEu_090CE9EA[gLanguage]);
#else
    *(void**)&work[8] = LoadObjTiles(gUnk_090A261E, 0x1800);
#endif
    *(void**)&work[12] = LoadObjPalette(gUnk_096144D8, 32);
    func_0808E364(work, 1);
    p = &work[CARDWORK(0x8B1)];
    z = 0;
    *p = 3;
    work[CARDWORK(0x8C8)] = z;
    SetTaskUpdate(a, (TaskUpdateFunc)func_08088F24);
    TaskPoolUpdate(&work[CARDWORK(0x7C8)]);
    TaskPoolUpdate(&work[CARDWORK(0x7DC)]);
    return 1;
}
u8 func_08088F24(UnkStruct_0808DB04* w, void* a) {
    *(void**)&w->unk_4E8[8] = AnimUpdate(&w->anim2);
    *(void**)&w->unk_4E8[12] = AnimUpdate(&w->anim3);
    if (w->unk_8C8[1] != 0) {
        w->unk_8B1 = 1;
        func_0808CD48((u8*)w);
        SetTaskUpdate(a, (TaskUpdateFunc)func_08089220);
    }
    switch (GetKeysRepeat()) {
    case DPAD_UP:
        if (w->unk_8C8[0] != 0) {
            w->unk_8C8[0]--;
        } else {
            w->unk_8C8[0] = 5;
        }
        m4aSongNumStart(SONG_SYS_CLICK);
        w->unk_8B7 = 1;
        break;
    case DPAD_DOWN:
        if (w->unk_8C8[0] < 5) {
            w->unk_8C8[0]++;
        } else {
            w->unk_8C8[0] = 0;
        }
        w->unk_8B7 = 1;
        m4aSongNumStart(SONG_SYS_CLICK);
        break;
    }
    switch (GetKeysPressed()) {
    case B_BUTTON:
        w->unk_8B7 = 1;
        if (w->unk_8B2[0] == 0) {
            w->unk_8B1 = 0;
            func_0808CD48((u8*)w);
            func_0808E364((u8*)w, 0);
            m4aSongNumStart(SONG_SYS_CLOSE);
            SetTaskUpdate(a, (TaskUpdateFunc)func_08086A14);
            func_0808E344((void**)w);
        } else {
            w->unk_8B1 = 1;
            func_0808CD48((u8*)w);
            m4aSongNumStart(SONG_SYS_CLOSE);
            SetTaskUpdate(a, (TaskUpdateFunc)func_08089220);
        }
        break;
    case START_BUTTON:
        w->unk_8C8[3] = 1;
        w->unk_8B7 = 1;
        if (w->unk_8B2[0] == 0) {
            w->unk_8B1 = 0;
            func_0808CD48((u8*)w);
            func_0808E364((u8*)w, 0);
            m4aSongNumStart(SONG_SYS_CLOSE);
            SetTaskUpdate(a, (TaskUpdateFunc)func_08086A14);
            func_0808E344((void**)w);
        } else {
            m4aSongNumStart(SONG_SYS_CLOSE);
            SetTaskUpdate(a, (TaskUpdateFunc)func_08089220);
            w->unk_8D1[1] = 7;
        }
        break;
    case A_BUTTON:
        switch (w->unk_8C8[0]) {
        case 0:
            SetActiveDeckIndex(w->unk_8C0);
            func_0808D16C(w->unk_8C0);
            TaskCreate(&w->tasks2, &gTaskDescDeckEquip, &w->unk_8C8[1]);
            m4aSongNumStart(SONG_SYS_DECKSET);
            SetTaskUpdate(a, (TaskUpdateFunc)func_08089220);
            return 1;
        case 1:
            m4aSongNumStart(SONG_SYS_KETTEI);
            func_0808C90C((u8*)w);
            w->unk_8D0 = 0;
            func_0808E344((void**)w);
#ifdef VERSION_EU
            FadeStartIn(0, 16);
#endif
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808F3E8);
            break;
        case 2:
            m4aSongNumStart(SONG_SYS_KETTEI);
            w->unk_8B1 = 15;
            TaskCreate(&w->tasks2, &gTaskDescDeckClear, &w->unk_8C8[1]);
            w->unk_8D1[0] = 1;
            SetTaskUpdate(a, (TaskUpdateFunc)func_08088768);
            return 1;
        case 3:
            m4aSongNumStart(SONG_SYS_KETTEI);
            SetTaskUpdate(a, (TaskUpdateFunc)func_080892E8);
            break;
        case 4:
            m4aSongNumStart(SONG_SYS_KETTEI);
            SetTaskUpdate(a, (TaskUpdateFunc)func_08089EC0);
            break;
        case 5:
            m4aSongNumStart(SONG_SYS_KETTEI);
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808A7E4);
            break;
        }
        break;
    }
#ifdef VERSION_EU
    switch (gLanguage) {
    case 0:
        ApproachValueHalf(&w->x, 0x6600);
        break;
    case 1:
        ApproachValueHalf(&w->x, 0x6200);
        break;
    case 2:
        ApproachValueHalf(&w->x, 0x5E00);
        break;
    case 3:
        ApproachValueHalf(&w->x, 0x6200);
        break;
    case 4:
        ApproachValueHalf(&w->x, 0x5E00);
        break;
    default:
        ApproachValueHalf(&w->x, 0x6600);
        break;
    }
#else
    ApproachValueHalf(&w->x, 0x6600);
#endif
    ApproachValueHalf(&w->y, gUnk_0903570E[w->unk_8C8[0]] << 8);
    TaskPoolUpdate(&w->tasks);
    TaskPoolUpdate(&w->tasks2);
    return 1;
}
u8 func_08089220(u8* work, void* a) {
    *(void**)&work[0x4F0] = AnimUpdate(&work[CARDWORK(0x800)]);
    *(void**)&work[0x4F4] = AnimUpdate(&work[CARDWORK(0x818)]);
    func_0808E344((void**)work);
    func_0808E364(work, 0);

    switch (work[CARDWORK(0x8C8)]) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        if (work[CARDWORK(0x8B2)] == 0) {
            work[CARDWORK(0x8B1)] = 0;
            func_0808CD48(work);
            work[CARDWORK(0x8B7)] = 4;
            SetTaskUpdate(a, (TaskUpdateFunc)func_08086A14);
        } else {
            work[CARDWORK(0x8B1)] = 1;
            work[CARDWORK(0x8B7)] = 4;
            SetTaskUpdate(a, (TaskUpdateFunc)func_080889DC);
        }
        break;
    }

    TaskPoolUpdate(&work[CARDWORK(0x7C8)]);
    TaskPoolUpdate(&work[CARDWORK(0x7DC)]);
    return 1;
}
u8 func_080892E8(u8* work, void* a) {
    FadeStartIn(0, 4);

    switch (work[CARDWORK(0x8C0)]) {
    case 0:
#ifdef VERSION_EU
        SetupBg(0, 0, 31, 0);
#else
        SetupBg(0, 3, 31, 0);
#endif
#ifdef VERSION_EU
        SetupBg(1, 0, 28, 0);
#else
        SetupBg(1, 0, 23, 0);
#endif
#ifdef VERSION_EU
        SetupBg(2, 0, 29, 0);
#else
        SetupBg(2, 0, 15, 0);
#endif
        SetupBg(3, 0, 30, 0);
        LoadBgMap(0, gUnk_09519AB8, 0x180);
        LoadBgMap(1, gUnk_095182B8, 0x800);
        LoadBgMap(2, gUnk_09514AB8, 0x800);
        SetBgScroll(0, 0, 0xFFF0);
        SetBgScroll(1, 0, 0);
        SetBgScroll(2, 0, 0);
        *(u16*)&work[CARDWORK(0x888)] = 16;
        *(u16*)&work[CARDWORK(0x88E)] = 28;
        break;
    case 1:
        SetupBg(0, 0, 31, 0);
#ifdef VERSION_EU
        SetupBg(1, 0, 28, 0);
#else
        SetupBg(1, 2, 23, 0);
#endif
#ifdef VERSION_EU
        SetupBg(2, 0, 29, 0);
#else
        SetupBg(2, 0, 15, 0);
#endif
        SetupBg(3, 0, 30, 0);
        LoadBgMap(0, gUnk_095182B8, 0x800);
        LoadBgMap(1, gUnk_0951A2B8, 0x180);
        LoadBgMap(2, gUnk_09514AB8, 0x800);
        SetBgScroll(0, 0, 0);
        SetBgScroll(1, 0, 0xFFF0);
        SetBgScroll(2, 0, 0);
        *(u16*)&work[CARDWORK(0x88A)] = 16;
        *(u16*)&work[CARDWORK(0x890)] = 28;
        break;
    case 2:
        SetupBg(0, 0, 31, 0);
#ifdef VERSION_EU
        SetupBg(1, 0, 28, 0);
#else
        SetupBg(1, 0, 23, 0);
#endif
#ifdef VERSION_EU
        SetupBg(2, 0, 29, 0);
#else
        SetupBg(2, 1, 15, 0);
#endif
        SetupBg(3, 0, 30, 0);
        LoadBgMap(0, gUnk_095182B8, 0x800);
        LoadBgMap(1, gUnk_09514AB8, 0x800);
        LoadBgMap(2, gUnk_0951AAB8, 0x180);
        SetBgScroll(0, 0, 0);
        SetBgScroll(1, 0, 0);
        SetBgScroll(2, 0, 0xFFF0);
        *(u16*)&work[CARDWORK(0x88C)] = 16;
        *(u16*)&work[CARDWORK(0x892)] = 28;
        break;
    }

    func_0808500C(work[CARDWORK(0x8C0)], (u16*)&work[CARDWORK(0x89A)]);
    func_0808CC58(*(u16*)&work[CARDWORK(0x89A)], 0);
    func_0808CC58(*(u16*)&work[CARDWORK(0x89C)], 1);
    func_0808CC58(*(u16*)&work[CARDWORK(0x89E)], 2);
    func_0808CC58(*(u16*)&work[CARDWORK(0x8A0)], 3);
    work[CARDWORK(0x8D0)] = 0;
    SetTaskUpdate(a, (TaskUpdateFunc)func_08089558);
    TaskPoolUpdate(&work[CARDWORK(0x7C8)]);
    TaskPoolUpdate(&work[CARDWORK(0x7DC)]);
    return 1;
}

u8 func_08089558(u8* work, void* a) {
    UnkStruct_08084D78* e;
    u16 i;
    u16 n;
    u16 m;
    u32 b;
    s32 k;
    u8* p;
    u8* q;
    vu32 zero;

    FadeStartIn(0, 4);

    switch (work[CARDWORK(0x8D0)]) {
    case 0:
        q = &work[CARDWORK(0x8B1)];
        k = 0;
        *q = 4;
        *(u16*)&work[CARDWORK(0x894)] = 7;
        *(u16*)&work[CARDWORK(0x896)] = 130;
        func_0808E344((void**)work);
        func_0808E364(work, 0);
        func_0808C90C(work);
        LoadBgMap(3, gUnk_095142B8, 0x800);
        *(u16*)&work[CARDWORK(0x898)] = n = 0x11E;
        *(void**)&work[0x4D8] = EwramAlloc(n * 32);
        zero = 0;
        CpuSet((void*)&zero, *(void**)&work[0x4D8], (*(u16*)&work[CARDWORK(0x898)] * 8) | 0x05000000);
        *(s32*)&work[0x4D4] = k;
        break;
    case 1:
        func_08084D78(*(void**)&work[0x4D8], work[CARDWORK(0x8C0)], 1, *(u16*)&work[CARDWORK(0x898)], &work[0x4FC]);
        break;
    case 2:
        *(u16*)&work[CARDWORK(0x898)] = func_08084E50(*(void**)&work[0x4D8], work[CARDWORK(0x8C0)], 1, *(u16*)&work[CARDWORK(0x898)], &work[0x4FC]);
        break;
    case 3:
        if (*(u16*)&work[CARDWORK(0x898)] != 0) {
            func_0808FA8C(work);
        }
        break;
    case 4:
        for (i = 0; i < 0x11E; i++) {
            b = *(u32*)&work[0x4D8];
            e = (UnkStruct_08084D78*)(i * 32 + b);

            if (e->unk_16 != 0) {
                EwramFree(e->unk_1C);
            }
        }

        EwramFree(*(void**)&work[0x4D8]);
        break;
    case 5:
        p = &work[CARDWORK(0x8C1)];
        m = 0;
        *p = 5;
        *(u16*)&work[CARDWORK(0x8D4)] = func_0808C60C(work, 5, 0);
        func_0808CD48(work);
        *(s32*)&work[CARDWORK(0x848)] = gUnk_0903595E[0] << 8;
        *(s32*)&work[CARDWORK(0x84C)] = gUnk_09035964[0] << 8;
        work[CARDWORK(0x8C7)] = 2;
        *(u16*)&work[CARDWORK(0x884)] = m;
        *(u16*)&work[CARDWORK(0x886)] = m;
        func_0808D828(work);
        func_0808DE28(0);

        if (*(u16*)&work[CARDWORK(0x8D4)] != 0) {
            work[CARDWORK(0x8D0)] = 4;
            SetTaskUpdate(a, (TaskUpdateFunc)func_080897CC);
        } else {
            *(u16*)&work[CARDWORK(0x884)] = *p;
            work[CARDWORK(0x8B7)] = 1;
            work[CARDWORK(0x8B1)] = 6;
            SetTaskUpdate(a, (TaskUpdateFunc)func_080882DC);
        }
        break;
    }

    work[CARDWORK(0x8D0)]++;
    TaskPoolUpdate(&work[CARDWORK(0x7C8)]);
    TaskPoolUpdate(&work[CARDWORK(0x7DC)]);
    return 1;
}

u8 func_080897CC(UnkStruct_080889DC* w, void* a) {
    u16 i;

#ifdef VERSION_EU
    if ((u8)FadeIsActive() != 0) {
        return 1;
    }
#endif
    w->gfx = AnimUpdate(&w->anim2);
    w->gfx2 = AnimUpdate(&w->anim3);
    if (w->unk_8C9 != 0) {
        TaskPoolUpdate(&w->taskpool);
        TaskPoolUpdate(&w->cardpool);
        if (GetKeysPressed() & START_BUTTON) {
            w->unk_8D2 = 7;
            w->unk_8CB = 1;
        }
        return 1;
    }
    if (w->unk_8CB != 0) {
        if ((u8)func_0808E750((u8*)w) != 0 && (u8)func_0808E79C((u8*)w) != 0) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808B208);
            FadeStartOut(0, 4);
            m4aSongNumStart(SONG_SYS_CANSEL);
            return 1;
        } else {
            w->unk_8CB = 0;
        }
    }
    if (w->unk_8D0 == 0) {
        switch ((u16)GetKeysRepeat()) {
        case DPAD_UP:
            if (w->unk_886 > 0) {
                if ((u8)func_0808E8E8((u8*)w, w->unk_884, (s16)(w->unk_886 - 1)) != 0) {
                    w->unk_886--;
                    w->unk_8B7 = 1;
                    m4aSongNumStart(SONG_SYS_CLICKI04B);
                }
            } else {
                if ((u8)func_0808CA78((u8*)w, 1) == 0) {
                    w->unk_884 = w->unk_8C1;
                    w->unk_8B7 = 1;
                    m4aSongNumStart(SONG_SYS_CLICKI04B);
                    w->unk_8B1 = 6;
                    for (i = 0; i < 10; i++) {
                        func_0808DD20(0, i);
                    }
                    SetTaskUpdate(a, (TaskUpdateFunc)func_080882DC);
                    return 1;
                }
            }
            func_0808D828((u8*)w);
            break;
        case DPAD_DOWN:
            if (w->unk_886 <= 2) {
                if ((u8)func_0808E8E8((u8*)w, w->unk_884, (s16)(w->unk_886 + 1)) != 0) {
                    w->unk_886++;
                    w->unk_8B7 = 1;
                    m4aSongNumStart(SONG_SYS_CLICKI04B);
                }
            } else {
                if ((u8)func_0808E8E8((u8*)w, w->unk_884, (s16)(w->unk_886 + 1)) != 0) {
                    func_0808C9CC((u8*)w);
                }
            }
            func_0808D828((u8*)w);
            break;
        case DPAD_LEFT:
            if (w->unk_884 > 0) {
                if ((u8)func_0808E8E8((u8*)w, (s16)(w->unk_884 - 1), w->unk_886) != 0) {
                    w->unk_884--;
                    w->unk_8B7 = 1;
                    m4aSongNumStart(SONG_SYS_CLICKI04B);
                }
            }
            func_0808D828((u8*)w);
            break;
        case DPAD_RIGHT:
            if (w->unk_884 > 1) {
                w->unk_8B7 = 1;
                return 1;
            }
            if ((u8)func_0808E8E8((u8*)w, (s16)(w->unk_884 + 1), w->unk_886) != 0) {
                w->unk_884++;
                w->unk_8B7 = 1;
                m4aSongNumStart(SONG_SYS_CLICKI04B);
            }
            func_0808D828((u8*)w);
            break;
        }
        switch ((u16)GetKeysPressed()) {
        case A_BUTTON:
            if ((u8)func_0808E890((u8*)w) != 0) {
                w->unk_8B5 = w->unk_884;
                w->unk_8B6 = w->unk_886;
                w->unk_884 = 0;
                w->unk_886 = 0;
                if ((u8)func_0808DED0((u8*)w) != 0) {
                    m4aSongNumStart(SONG_SYS_KETTEI);
                    func_0808DDD0((u8*)w);
                    func_0808E364((u8*)w, 1);
                    w->unk_8B1 = 5;
                    w->x = gUnk_0903571A[w->unk_884] << 8;
                    w->y = gUnk_0903571E[w->unk_886] << 8;
                    SetTaskUpdate(a, (TaskUpdateFunc)func_08087CD4);
                    return 1;
                } else {
                    w->unk_884 = w->unk_8B5;
                    w->unk_886 = w->unk_8B6;
                    m4aSongNumStart(SONG_SYS_BEEP);
                    return 1;
                }
            } else {
                m4aSongNumStart(SONG_SYS_BEEP);
                return 1;
            }
        case B_BUTTON:
            FadeStartIn(0, 1);
            SetTaskUpdate(a, (TaskUpdateFunc)func_08089D20);
            m4aSongNumStart(SONG_SYS_CANSEL);
            return 1;
        case L_BUTTON:
            FadeStartIn(0, 1);
            func_0808E2F0((UnkStruct_0808DB04*)w);
            SetTaskUpdate(a, (TaskUpdateFunc)func_08089EC0);
            m4aSongNumStart(SONG_SYS_CANSEL);
            return 1;
        case START_BUTTON:
            if ((u8)func_0808E750((u8*)w) != 0 && (u8)func_0808E79C((u8*)w) != 0) {
                SetTaskUpdate(a, (TaskUpdateFunc)func_0808B208);
                FadeStartOut(0, 4);
                m4aSongNumStart(SONG_SYS_CLOSE);
                w->unk_8D2 = 7;
            }
            return 1;
        }
        if (GetKeysPressed() & SELECT_BUTTON) {
            w->unk_886 = 0;
            func_0808E7D8((u8*)w);
            w->unk_884 = w->unk_8C1;
            w->unk_8B7 = 1;
            w->x2 = 0xA000;
            w->y2 = 0x2800;
            w->unk_8AC = 4;
            m4aSongNumStart(SONG_SYS_CLICKI04B);
            w->unk_8B1 = 6;
            for (i = 0; i < 10; i++) {
                func_0808DD20(0, i);
            }
            TaskPoolUpdate(&w->taskpool);
            TaskPoolUpdate(&w->cardpool);
            SetTaskUpdate(a, (TaskUpdateFunc)func_080882DC);
            return 1;
        }
    } else {
        w->unk_8D0--;
    }
    ApproachValueHalf(&w->x, gUnk_0903595E[w->unk_884] << 8);
    ApproachValueHalf(&w->y, gUnk_09035964[w->unk_886] << 8);
    TaskPoolUpdate(&w->taskpool);
    TaskPoolUpdate(&w->cardpool);
    return 1;
}

u8 func_08089D20(u8* work, void* a) {
    u8* q;

    FadeStartIn(0, 4);
    q = &work[CARDWORK(0x8B1)];
    *q = 4;
    ((UnkStruct_0808DB04*)work)->unk_878 = 95;
    func_0808DB04((void**)work);
    SetupBg(3, 0, 30, 0);
#ifdef VERSION_EU
    SetupBg(2, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(0, 0, 31, 0);
#else
    SetupBg(2, 1, 15, 0);
    SetupBg(1, 2, 23, 0);
    SetupBg(0, 3, 31, 0);
#endif
    LoadBgMap(0, gUnk_08125E24, 0x800);
    LoadBgMap(1, gUnk_08125E24, 0x800);
    LoadBgMap(2, gUnk_08125E24, 0x800);
    func_0808CDE8(work, work[CARDWORK(0x8C0)]);
    LoadBgMap(3, gUnk_09512AB8, 0x800);
    func_0808E2F0((UnkStruct_0808DB04*)work);
    func_0808C90C(work);
    work[CARDWORK(0x8C1)] = 0;
    *(s16*)&work[CARDWORK(0x884)] = 0;
    ((UnkStruct_0808DB04*)work)->unk_886 = work[CARDWORK(0x8C0)];
    func_0808C3DC(work, work[CARDWORK(0x8C1)]);
    work[CARDWORK(0x8C7)] = 0;
    *q = 1;
    func_0808CD48(work);
    ApproachValueHalf(&work[CARDWORK(0x848)], gUnk_090356EC[*(s16*)&work[CARDWORK(0x884)]] << 8);
    ApproachValueHalf(&work[CARDWORK(0x84C)], gUnk_090356F2[*(s16*)&work[CARDWORK(0x886)]] << 8);
    SetTaskUpdate(a, (TaskUpdateFunc)func_080889DC);
    LoadPalette(&gUnk_09614418[32],
                (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->index * 32 +
                        0x05000200),
                (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->count << 5));
    TaskPoolUpdate(&work[CARDWORK(0x7C8)]);
    work += CARDWORK(0x7DC);
    TaskPoolUpdate(work);
    return 1;
}

u8 func_08089EC0(u8* work, void* a) {
    FadeStartIn(0, 4);

    switch (work[CARDWORK(0x8C0)]) {
    case 0:
#ifdef VERSION_EU
        SetupBg(0, 0, 31, 0);
#else
        SetupBg(0, 3, 31, 0);
#endif
#ifdef VERSION_EU
        SetupBg(1, 0, 28, 0);
#else
        SetupBg(1, 0, 23, 0);
#endif
#ifdef VERSION_EU
        SetupBg(2, 0, 29, 0);
#else
        SetupBg(2, 0, 15, 0);
#endif
        SetupBg(3, 0, 30, 0);
        LoadBgMap(0, gUnk_09519AB8, 0x180);
        LoadBgMap(1, gUnk_095172B8, 0x800);
        LoadBgMap(2, gUnk_09517AB8, 0x800);
        SetBgScroll(0, (u16)-88, (u16)-16);
        SetBgScroll(1, (u16)-88, (u16)-112);
        SetBgScroll(2, (u16)-140, (u16)-96);
        *(u16*)&work[CARDWORK(0x888)] = 102;
        *(u16*)&work[CARDWORK(0x88E)] = 28;
        break;
    case 1:
        SetupBg(0, 0, 31, 0);
#ifdef VERSION_EU
        SetupBg(1, 0, 28, 0);
#else
        SetupBg(1, 2, 23, 0);
#endif
#ifdef VERSION_EU
        SetupBg(2, 0, 29, 0);
#else
        SetupBg(2, 0, 15, 0);
#endif
        SetupBg(3, 0, 30, 0);
        LoadBgMap(0, gUnk_095172B8, 0x800);
        LoadBgMap(1, gUnk_0951A2B8, 0x180);
        LoadBgMap(2, gUnk_09517AB8, 0x800);
        SetBgScroll(0, (u16)-88, (u16)-112);
        SetBgScroll(1, (u16)-88, (u16)-16);
        SetBgScroll(2, (u16)-140, (u16)-96);
        *(u16*)&work[CARDWORK(0x88A)] = 102;
        *(u16*)&work[CARDWORK(0x890)] = 28;
        break;
    case 2:
        SetupBg(0, 0, 31, 0);
#ifdef VERSION_EU
        SetupBg(1, 0, 28, 0);
#else
        SetupBg(1, 0, 23, 0);
#endif
#ifdef VERSION_EU
        SetupBg(2, 0, 29, 0);
#else
        SetupBg(2, 1, 15, 0);
#endif
        SetupBg(3, 0, 30, 0);
        LoadBgMap(0, gUnk_095172B8, 0x800);
        LoadBgMap(1, gUnk_09517AB8, 0x800);
        LoadBgMap(2, gUnk_0951AAB8, 0x180);
        SetBgScroll(0, (u16)-88, (u16)-112);
        SetBgScroll(1, (u16)-140, (u16)-96);
        SetBgScroll(2, (u16)-88, (u16)-16);
        *(u16*)&work[CARDWORK(0x88C)] = 102;
        *(u16*)&work[CARDWORK(0x892)] = 28;
        break;
    }

    SetTaskUpdate(a, (TaskUpdateFunc)func_0808A114);
    TaskPoolUpdate(&work[CARDWORK(0x7C8)]);
    TaskPoolUpdate(&work[CARDWORK(0x7DC)]);
    return 1;
}
u8 func_0808A114(UnkStruct_0808DB04* work, void* a) {
    work->unk_894 = 94;
    work->unk_896 = 130;
    work->unk_8B1 = 7;
    func_0808E344((void**)work);
    func_0808E364((u8*)work, 0);
    func_0808CD48((u8*)work);
#ifdef VERSION_EU
    LoadBgMap(3, &gUnk_095132B8[0x800], 0x800);
#else
    LoadBgMap(3, gUnk_095132B8, 0x800);
#endif
    func_0808C90C(work);
    work->unk_8C1 = 0;
    work->unk_884 = 0;
    work->unk_886 = 0;
    func_0808C3DC(work, work->unk_8C1);
    work->x = gUnk_09035950[work->unk_884] << 8;
    work->y = gUnk_09035956[(s16)work->unk_886] << 8;
    func_0808DB50(work);
    work->unk_8C7 = 1;
    SetTaskUpdate(a, (TaskUpdateFunc)func_0808A218);
    TaskPoolUpdate(&work->tasks);
    TaskPoolUpdate(&work->tasks2);
    return 1;
}

u8 func_0808A218(u8* work, void* a) {
    u8 v;

    *(void**)&work[0x4F0] = AnimUpdate((AnimState*)&work[CARDWORK(0x800)]);
    *(void**)&work[0x4F4] = AnimUpdate((AnimState*)&work[CARDWORK(0x818)]);

#ifdef VERSION_EU
    if ((u8)FadeIsActive() != 0) {
        return 1;
    }
#endif

    if (work[CARDWORK(0x8C9)] != 0) {
        TaskPoolUpdate((TaskPool*)&work[CARDWORK(0x7C8)]);
        TaskPoolUpdate((TaskPool*)&work[CARDWORK(0x7DC)]);

        if (GetKeysPressed() & START_BUTTON) {
            work[CARDWORK(0x8D2)] = 7;
            work[CARDWORK(0x8CB)] = 1;
        }

        return 1;
    }

    if (work[CARDWORK(0x8CB)] != 0) {
        if ((u8)func_0808E750(work) != 0 && (u8)func_0808E79C(work) != 0) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808B208);
            FadeStartOut(0, 4);
            m4aSongNumStart(SONG_SYS_CANSEL);
            return 1;
        }

        work[CARDWORK(0x8CB)] = 0;
    }

    switch (GetKeysRepeat()) {
    case DPAD_LEFT:
        if (*(s16*)&work[CARDWORK(0x884)] > 0) {
            (*(s16*)&work[CARDWORK(0x884)])--;
            work[CARDWORK(0x8B7)] = 1;
            m4aSongNumStart(SONG_SYS_CLICKI04B);
        }

        func_0808DB50((UnkStruct_0808DB04*)work);
        break;
    case DPAD_RIGHT:
        if (*(s16*)&work[CARDWORK(0x884)] <= 1) {
            (*(s16*)&work[CARDWORK(0x884)])++;
            work[CARDWORK(0x8B7)] = 1;
            m4aSongNumStart(SONG_SYS_CLICKI04B);
        }

        func_0808DB50((UnkStruct_0808DB04*)work);
        break;
    case DPAD_UP:
        if (*(s16*)&work[CARDWORK(0x886)] > 0) {
            (*(s16*)&work[CARDWORK(0x886)])--;
            work[CARDWORK(0x8B7)] = 1;
            m4aSongNumStart(SONG_SYS_CLICKI04B);
        } else if ((u8)func_0808CA78(work, 1) == 0) {
            v = work[CARDWORK(0x8C1)];
            *(s16*)&work[CARDWORK(0x884)] = v;
            work[CARDWORK(0x8B7)] = 1;
            m4aSongNumStart(SONG_SYS_CLICKI04B);
            work[CARDWORK(0x8B1)] = 8;
            SetTaskUpdate(a, (TaskUpdateFunc)func_080870FC);
            func_0808DE28(0);
            return 1;
        }

        func_0808DB50((UnkStruct_0808DB04*)work);
        break;
    case DPAD_DOWN:
        if (*(s16*)&work[CARDWORK(0x886)] <= 2) {
            (*(s16*)&work[CARDWORK(0x886)])++;
            work[CARDWORK(0x8B7)] = 1;
            m4aSongNumStart(SONG_SYS_CLICKI04B);
        } else {
            func_0808C9CC(work);
        }

        func_0808DB50((UnkStruct_0808DB04*)work);
        break;
    }

    switch (GetKeysPressed()) {
    case A_BUTTON:
        func_0808E3E0(work);
        func_0808DB50((UnkStruct_0808DB04*)work);
        func_0808D0A4(work[CARDWORK(0x8C0)]);
        func_0808D258(work[CARDWORK(0x8C0)]);
        *(u16*)&work[CARDWORK(0x8A2)] = func_08085844(0, work[CARDWORK(0x8C0)]);
        *(u16*)&work[CARDWORK(0x8A4)] = func_08085844(1, work[CARDWORK(0x8C0)]);
        *(u16*)&work[CARDWORK(0x8A6)] = func_08085844(2, work[CARDWORK(0x8C0)]);
        *(u16*)&work[CARDWORK(0x8A8)] = func_08085844(3, work[CARDWORK(0x8C0)]);
        func_0808CBB4(work[CARDWORK(0x8A2)], 0);
        func_0808CBB4(work[CARDWORK(0x8A4)], 1);
        func_0808CBB4(work[CARDWORK(0x8A6)], 2);
        func_0808CBB4(work[CARDWORK(0x8A8)], 3);
        func_0808D594();
        break;
    case B_BUTTON:
        work[CARDWORK(0x8CA)] = 0;
        FadeStartIn(0, 1);
        SetTaskUpdate(a, (TaskUpdateFunc)func_0808A650);
        m4aSongNumStart(SONG_SYS_CANSEL);
        return 1;
    case R_BUTTON:
        work[CARDWORK(0x8CA)] = 1;
        func_0808E2F0((UnkStruct_0808DB04*)work);
        FadeStartIn(0, 1);
        SetTaskUpdate(a, (TaskUpdateFunc)func_080892E8);
        m4aSongNumStart(SONG_SYS_CANSEL);
        return 1;
    case START_BUTTON:
        if ((u8)func_0808E750(work) == 0) {
            return 1;
        }

        if ((u8)func_0808E79C(work) == 0) {
            return 1;
        }

        SetTaskUpdate(a, (TaskUpdateFunc)func_0808B208);
        FadeStartOut(0, 4);
        m4aSongNumStart(SONG_SYS_CLOSE);
        work[CARDWORK(0x8D2)] = 7;
        return 1;
    }

    if (GetKeysPressed() & SELECT_BUTTON) {
        *(s16*)&work[CARDWORK(0x886)] = 0;
        func_0808E7D8(work);
        v = work[CARDWORK(0x8C1)];
        *(s16*)&work[CARDWORK(0x884)] = v;
        work[CARDWORK(0x8B7)] = 1;
        *(s32*)&work[CARDWORK(0x850)] = 0x4800;
        *(s32*)&work[CARDWORK(0x854)] = 0x2800;
        *(u16*)&work[CARDWORK(0x8AC)] = 4;
        m4aSongNumStart(SONG_SYS_CLICKI04B);
        work[CARDWORK(0x8B1)] = 8;
        TaskPoolUpdate((TaskPool*)&work[CARDWORK(0x7C8)]);
        TaskPoolUpdate((TaskPool*)&work[CARDWORK(0x7DC)]);
        SetTaskUpdate(a, (TaskUpdateFunc)func_080870FC);
        func_0808DE28(0);
        return 1;
    }

    ApproachValueHalf((s32*)&work[CARDWORK(0x848)], gUnk_09035950[*(s16*)&work[CARDWORK(0x884)]] << 8);
    ApproachValueHalf((s32*)&work[CARDWORK(0x84C)], gUnk_09035956[*(s16*)&work[CARDWORK(0x886)]] << 8);
    TaskPoolUpdate((TaskPool*)&work[CARDWORK(0x7C8)]);
    TaskPoolUpdate((TaskPool*)&work[CARDWORK(0x7DC)]);
    return 1;
}

u8 func_0808A650(u8* work, void* a) {
    FadeStartIn(0, 4);
    ((UnkStruct_0808DB04*)work)->unk_878 = 95;
    func_0808DB04((void**)work);
    SetupBg(3, 0, 30, 0);
#ifdef VERSION_EU
    SetupBg(2, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(0, 0, 31, 0);
#else
    SetupBg(2, 1, 15, 0);
    SetupBg(1, 2, 23, 0);
    SetupBg(0, 3, 31, 0);
#endif
    LoadBgMap(0, gUnk_08125E24, 0x800);
    LoadBgMap(1, gUnk_08125E24, 0x800);
    LoadBgMap(2, gUnk_08125E24, 0x800);
    func_0808CDE8(work, work[CARDWORK(0x8C0)]);
    LoadBgMap(3, gUnk_09512AB8, 0x800);
    func_0808E2F0((UnkStruct_0808DB04*)work);
    func_0808C90C(work);
    work[CARDWORK(0x8C1)] = 0;
    *(s16*)&work[CARDWORK(0x884)] = 0;
    ((UnkStruct_0808DB04*)work)->unk_886 = work[CARDWORK(0x8C0)];
    func_0808C3DC(work, work[CARDWORK(0x8C1)]);
    work[CARDWORK(0x8C7)] = 0;
    work[CARDWORK(0x8B1)] = 1;
    func_0808CD48(work);
    ApproachValueHalf(&work[CARDWORK(0x848)], gUnk_090356EC[*(s16*)&work[CARDWORK(0x884)]] << 8);
    ApproachValueHalf(&work[CARDWORK(0x84C)], gUnk_090356F2[*(s16*)&work[CARDWORK(0x886)]] << 8);
    SetTaskUpdate(a, (TaskUpdateFunc)func_080889DC);
    LoadPalette(&gUnk_09614418[32],
                (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->index * 32 +
                        0x05000200),
                (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->count << 5));
    TaskPoolUpdate(&work[CARDWORK(0x7C8)]);
    work += CARDWORK(0x7DC);
    TaskPoolUpdate(work);
    return 1;
}

u8 func_0808A7E4(u8* work, void* a) {
    u8 z;
    u8* q;

    FadeStartIn(0, 4);
    SetupBg(3, 0, 30, 0);
    SetupBg(2, 0, 15, 0);
    SetupBg(1, 0, 23, 0);
    SetupBg(0, 0, 31, 0);
    SetBgScroll(0, 0, 0);
    SetBgScroll(1, 0, 0);
    SetBgScroll(2, 0, 16);
    LoadBgMap(3, gUnk_095192B8, 0x800);
    LoadBgMap(2, gUnk_095182B8, 0x800);
    LoadBgMap(1, gUnk_09514AB8, 0x800);
    DisableBg(0);
    func_0808500C(3, (u16*)&work[CARDWORK(0x89A)]);
    func_0808CC58(*(u16*)&work[CARDWORK(0x89A)], 0);
    func_0808CC58(*(u16*)&work[CARDWORK(0x89C)], 1);
    func_0808CC58(*(u16*)&work[CARDWORK(0x89E)], 2);
    func_0808CC58(*(u16*)&work[CARDWORK(0x8A0)], 3);
    q = &work[CARDWORK(0x8B1)];
    z = 0;
    *q = 9;
    func_0808E344((void**)work);
    func_0808E364(work, 0);
    func_0808C90C(work);
    work[CARDWORK(0x8D0)] = z;
    SetTaskUpdate(a, (TaskUpdateFunc)func_0808A910);
    TaskPoolUpdate(&work[CARDWORK(0x7C8)]);
    work += CARDWORK(0x7DC);
    TaskPoolUpdate(work);
    return 1;
}
u8 func_0808A910(UnkStruct_0808DB04* w, void* a) {
    u16 i;
    u32 zero;

    FadeStartIn(0, 4);

    switch (w->unk_8D0) {
    case 0:
        w->unk_898 = 286;
        w->unk_4D8 = EwramAlloc(w->unk_898 * sizeof(UnkStruct_0808E2F0));
        zero = 0;
        CpuSet(&zero, w->unk_4D8, 0x05000000 | (w->unk_898 * 8));
        w->unk_4D4 = 0;
        w->unk_894 = 7;
        w->unk_896 = 113;
        break;
    case 1:
        func_08084D78((UnkStruct_08084D78*)w->unk_4D8, w->unk_8C0, 0, w->unk_898, w->unk_4FC);
        break;
    case 2:
        w->unk_898 = func_08084E50((UnkStruct_08084D78*)w->unk_4D8, w->unk_8C0, 0, w->unk_898, w->unk_4FC);
        break;
    case 3:
        if (w->unk_898 != 0) {
            func_0808FA8C(w);
        }
        break;
    case 4:
        for (i = 0; i < 286; i++) {
            if (w->unk_4D8[i].unk_16 != 0) {
                EwramFree(w->unk_4D8[i].unk_1C);
            }
        }

        EwramFree(w->unk_4D8);
        break;
    case 5:
        w->unk_8C1 = 5;
        w->unk_8D4 = func_0808C60C((u8*)w, 5, 1);
        func_0808CD48((u8*)w);
        w->x = gUnk_0903595E[0] << 8;
        w->y = gUnk_09035964[0] << 8;
        w->unk_8C7 = 3;
        w->unk_884 = 0;
        w->unk_886 = 0;
        func_0808D828((u8*)w);

        if (w->unk_8D4 != 0) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808AB48);
        } else {
            w->unk_8B1 = 10;
            SetTaskUpdate(a, (TaskUpdateFunc)func_080882DC);
            w->unk_884 = w->unk_8C1;
            w->unk_8B7 = 1;
        }
        break;
    }

    w->unk_8D0++;
    TaskPoolUpdate(&w->tasks);
    TaskPoolUpdate(&w->tasks2);
    return 1;
}
u8 func_0808AB48(UnkStruct_080889DC* w, void* a) {
    u16 i;

    w->gfx = AnimUpdate(&w->anim2);
    w->gfx2 = AnimUpdate(&w->anim3);
    if (w->unk_8C9 != 0) {
        TaskPoolUpdate(&w->taskpool);
        TaskPoolUpdate(&w->cardpool);
        if (GetKeysPressed() & START_BUTTON) {
            w->unk_8D2 = 7;
            w->unk_8CB = 1;
        }
        return 1;
    }
    if (w->unk_8CB != 0) {
        if ((u8)func_0808E750((u8*)w) != 0 && (u8)func_0808E79C((u8*)w) != 0) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808B208);
            FadeStartOut(0, 4);
            m4aSongNumStart(SONG_SYS_CANSEL);
            return 1;
        } else {
            w->unk_8CB = 0;
        }
    }
    switch ((u16)GetKeysRepeat()) {
    case DPAD_UP:
        if (w->unk_886 > 0) {
            if ((u8)func_0808E8E8((u8*)w, w->unk_884, (s16)(w->unk_886 - 1)) != 0) {
                w->unk_886--;
                w->unk_8B7 = 1;
                m4aSongNumStart(SONG_SYS_CLICKI04B);
            }
        } else {
            if ((u8)func_0808CA78((u8*)w, 1) == 0) {
                w->unk_884 = w->unk_8C1;
                w->unk_8B7 = 1;
                m4aSongNumStart(SONG_SYS_CLICKI04B);
                w->unk_8B1 = 10;
                for (i = 0; i < 10; i++) {
                    func_0808DD20(0, i);
                }
                SetTaskUpdate(a, (TaskUpdateFunc)func_080882DC);
                return 1;
            }
        }
        func_0808D828((u8*)w);
        break;
    case DPAD_DOWN:
        if (w->unk_886 <= 2) {
            if ((u8)func_0808E8E8((u8*)w, w->unk_884, (s16)(w->unk_886 + 1)) != 0) {
                w->unk_886++;
                w->unk_8B7 = 1;
                m4aSongNumStart(SONG_SYS_CLICKI04B);
            }
        } else {
            if ((u8)func_0808E8E8((u8*)w, w->unk_884, (s16)(w->unk_886 + 1)) != 0) {
                func_0808C9CC((u8*)w);
            }
        }
        func_0808D828((u8*)w);
        break;
    case DPAD_LEFT:
        if (w->unk_884 > 0) {
            if ((u8)func_0808E8E8((u8*)w, (s16)(w->unk_884 - 1), w->unk_886) != 0) {
                w->unk_884--;
                w->unk_8B7 = 1;
                m4aSongNumStart(SONG_SYS_CLICKI04B);
            }
        }
        func_0808D828((u8*)w);
        break;
    case DPAD_RIGHT:
        if (w->unk_884 > 1) {
            w->unk_8B7 = 1;
            return 1;
        }
        if ((u8)func_0808E8E8((u8*)w, (s16)(w->unk_884 + 1), w->unk_886) != 0) {
            w->unk_884++;
            w->unk_8B7 = 1;
            m4aSongNumStart(SONG_SYS_CLICKI04B);
        }
        func_0808D828((u8*)w);
        break;
    }
    switch ((u16)GetKeysPressed()) {
    case A_BUTTON:
        if ((u8)func_0808E890((u8*)w) != 0) {
            w->unk_8B5 = w->unk_884;
            w->unk_8B6 = w->unk_886;
            w->unk_884 = 0;
            w->unk_886 = 0;
            func_0808E364((u8*)w, 1);
            if ((u8)func_0808DED0((u8*)w, 0) != 0) {
                m4aSongNumStart(SONG_SYS_KETTEI);
                func_0808DDD0((u8*)w);
                w->unk_8B1 = 11;
                w->x = gUnk_0903571A[w->unk_884] << 8;
                w->y = (gUnk_0903571E[w->unk_886] - 16) << 8;
                SetTaskUpdate(a, (TaskUpdateFunc)func_0808778C);
                return 1;
            } else {
                w->unk_884 = w->unk_8B5;
                w->unk_886 = w->unk_8B6;
                func_0808E364((u8*)w, 0);
                w->unk_8B1 = 9;
                m4aSongNumStart(SONG_SYS_BEEP);
                return 1;
            }
        } else {
            m4aSongNumStart(SONG_SYS_BEEP);
            return 1;
        }
    case B_BUTTON:
        FadeStartIn(0, 1);
        SetTaskUpdate(a, (TaskUpdateFunc)func_0808B068);
        m4aSongNumStart(SONG_SYS_CANSEL);
        return 1;
    case START_BUTTON:
        if ((u8)func_0808E750((u8*)w) != 0 && (u8)func_0808E79C((u8*)w) != 0) {
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808B208);
            FadeStartOut(0, 4);
            m4aSongNumStart(SONG_SYS_CLOSE);
            w->unk_8D2 = 7;
        }
        return 1;
    }
    if (GetKeysPressed() & SELECT_BUTTON) {
        func_0808E7D8((u8*)w);
        w->unk_884 = w->unk_8C1;
        w->unk_8B7 = 1;
        w->x2 = 0xA000;
        w->y2 = 0x2800;
        w->unk_8AC = 4;
        m4aSongNumStart(SONG_SYS_CLICKI04B);
        w->unk_8B1 = 10;
        for (i = 0; i < 10; i++) {
            func_0808DD20(0, i);
        }
        TaskPoolUpdate(&w->taskpool);
        TaskPoolUpdate(&w->cardpool);
        SetTaskUpdate(a, (TaskUpdateFunc)func_080882DC);
        return 1;
    }
    ApproachValueHalf(&w->x, gUnk_0903595E[w->unk_884] << 8);
    ApproachValueHalf(&w->y, gUnk_09035964[w->unk_886] << 8);
    TaskPoolUpdate(&w->taskpool);
    TaskPoolUpdate(&w->cardpool);
    return 1;
}

u8 func_0808B068(u8* work, void* a) {
    u8* q;

    FadeStartIn(0, 4);
    q = &work[CARDWORK(0x8B1)];
    *q = 9;
    ((UnkStruct_0808DB04*)work)->unk_878 = 95;
    func_0808DB04((void**)work);
    SetupBg(3, 0, 30, 0);
#ifdef VERSION_EU
    SetupBg(2, 0, 28, 0);
    SetupBg(1, 0, 29, 0);
    SetupBg(0, 0, 31, 0);
#else
    SetupBg(2, 1, 15, 0);
    SetupBg(1, 2, 23, 0);
    SetupBg(0, 3, 31, 0);
#endif
    LoadBgMap(0, gUnk_08125E24, 0x800);
    LoadBgMap(1, gUnk_08125E24, 0x800);
    LoadBgMap(2, gUnk_08125E24, 0x800);
    func_0808CDE8(work, work[CARDWORK(0x8C0)]);
    LoadBgMap(3, gUnk_09512AB8, 0x800);
    func_0808E2F0((UnkStruct_0808DB04*)work);
    func_0808C90C(work);
    work[CARDWORK(0x8C1)] = 0;
    *(s16*)&work[CARDWORK(0x884)] = 0;
    ((UnkStruct_0808DB04*)work)->unk_886 = work[CARDWORK(0x8C0)];
    func_0808C3DC(work, work[CARDWORK(0x8C1)]);
    work[CARDWORK(0x8C7)] = 0;
    *q = 1;
    func_0808CD48(work);
    ApproachValueHalf(&work[CARDWORK(0x848)], gUnk_090356EC[*(s16*)&work[CARDWORK(0x884)]] << 8);
    ApproachValueHalf(&work[CARDWORK(0x84C)], gUnk_090356F2[*(s16*)&work[CARDWORK(0x886)]] << 8);
    SetTaskUpdate(a, (TaskUpdateFunc)func_080889DC);
    LoadPalette(&gUnk_09614418[32],
                (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->index * 32 +
                        0x05000200),
                (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->count << 5));
    TaskPoolUpdate(&work[CARDWORK(0x7C8)]);
    work += CARDWORK(0x7DC);
    TaskPoolUpdate(work);
    return 1;
}

u8 func_0808B208(u8* work) {
    if (FadeIsActive() == 0) {
        return 0;
    }

    TaskPoolUpdate(&work[CARDWORK(0x7C8)]);
    TaskPoolUpdate(&work[CARDWORK(0x7DC)]);
    return 1;
}
u8 func_0808B238(u8* work, void* a) {
    *(void**)&work[0x4BC] = LoadObjTiles(gUnk_090A583E, 0x620);

#ifdef VERSION_EU
    *(void**)&work[0x18] = LoadObjTiles(gUnkEu_09F6FDDC[gLanguage], gUnkEu_090CE9F4[gLanguage]);
#elif defined(VERSION_US)
    if (gGameState.flags & 8) {
        *(void**)&work[0x18] = LoadObjTiles(gUnk_090A418E, 0x320);
    } else {
        *(void**)&work[0x18] = LoadObjTiles(gUnk_090A3E46, 0x320);
    }
#else
    *(void**)&work[0x18] = LoadObjTiles(gUnk_090A418E, 0x320);
#endif

    *(void**)&work[0x4C0] = LoadObjPalette(gUnk_096144F8, 32);
#ifdef VERSION_EU
    LoadBgMap(3, gUnk_095132B8, 0x800);
#else
    LoadBgMap(3, gUnk_09516AB8, 0x800);
#endif
    *(s32*)&work[CARDWORK(0x858)] = 0x7800;
    *(s32*)&work[CARDWORK(0x860)] = 0;
    *(s32*)&work[CARDWORK(0x85C)] = 0xA400;
    *(s32*)&work[CARDWORK(0x864)] = 0x9800;
    *(s32*)&work[CARDWORK(0x868)] = 0;
    work[CARDWORK(0x8CC)] = 16;
    work[CARDWORK(0x8CD)] = 16;
    work[CARDWORK(0x8B0)] = 0;
    SetTaskUpdate(a, (TaskUpdateFunc)func_0808B30C);
    return 1;
}

u8 func_0808B30C(u8* work, void* a) {
    if ((s8)work[CARDWORK(0x8CD)] > 0) {
        ApproachValue(&work[CARDWORK(0x868)], -0x8000, (u16)(s8)work[CARDWORK(0x8CD)]);
        work[CARDWORK(0x8CD)]--;
    } else if ((s8)work[CARDWORK(0x8CC)] > 0) {
        ApproachValue(&work[CARDWORK(0x860)], -0x800, (u16)(s8)work[CARDWORK(0x8CC)]);
        ApproachValue(&work[CARDWORK(0x864)], 0xA000, (u16)(s8)work[CARDWORK(0x8CC)]);
        work[CARDWORK(0x8CC)]--;
    } else {
        FadeStartOut(0, 4);
        SetTaskUpdate(a, (TaskUpdateFunc)func_0808B208);
    }

    return 1;
}

void func_0808B398(u8* work) {
    func_08066588(*(s16*)&work[CARDWORK(0x894)], *(s16*)&work[CARDWORK(0x896)], &work[0x1E8],
                  *(void**)&work[0x14], 20, work[CARDWORK(0x8C6)]);
}

void func_0808B3DC(u8* work, u8 flag) {
    if (flag == 0) {
        switch (work[CARDWORK(0x8C0)]) {
        case 0:
            DrawTextSlots(*(s16*)&work[CARDWORK(0x888)], *(s16*)&work[CARDWORK(0x88E)], &work[0x38], *(void**)&work[0x14], 20, work[CARDWORK(0x8C2)]);
            DrawTextSlots(*(s16*)&work[CARDWORK(0x88A)], *(s16*)&work[CARDWORK(0x890)], &work[0x78], *(void**)&work[0x4C4], 20, work[CARDWORK(0x8C3)]);
            DrawTextSlots(*(s16*)&work[CARDWORK(0x88C)], *(s16*)&work[CARDWORK(0x892)], &work[0xB8], *(void**)&work[0x4C4], 20, work[CARDWORK(0x8C4)]);
            break;
        case 1:
            DrawTextSlots(*(s16*)&work[CARDWORK(0x888)], *(s16*)&work[CARDWORK(0x88E)], &work[0x38], *(void**)&work[0x4C4], 20, work[CARDWORK(0x8C2)]);
            DrawTextSlots(*(s16*)&work[CARDWORK(0x88A)], *(s16*)&work[CARDWORK(0x890)], &work[0x78], *(void**)&work[0x14], 20, work[CARDWORK(0x8C3)]);
            DrawTextSlots(*(s16*)&work[CARDWORK(0x88C)], *(s16*)&work[CARDWORK(0x892)], &work[0xB8], *(void**)&work[0x4C4], 20, work[CARDWORK(0x8C4)]);
            break;
        case 2:
            DrawTextSlots(*(s16*)&work[CARDWORK(0x888)], *(s16*)&work[CARDWORK(0x88E)], &work[0x38], *(void**)&work[0x4C4], 20, work[CARDWORK(0x8C2)]);
            DrawTextSlots(*(s16*)&work[CARDWORK(0x88A)], *(s16*)&work[CARDWORK(0x890)], &work[0x78], *(void**)&work[0x4C4], 20, work[CARDWORK(0x8C3)]);
            DrawTextSlots(*(s16*)&work[CARDWORK(0x88C)], *(s16*)&work[CARDWORK(0x892)], &work[0xB8], *(void**)&work[0x14], 20, work[CARDWORK(0x8C4)]);
            break;
        }
    } else {
        switch (work[CARDWORK(0x8C0)]) {
        case 0:
            DrawTextSlots(*(s16*)&work[CARDWORK(0x888)], *(s16*)&work[CARDWORK(0x88E)], &work[0x38], *(void**)&work[0x14], 20, work[CARDWORK(0x8C2)]);
            break;
        case 1:
            DrawTextSlots(*(s16*)&work[CARDWORK(0x88A)], *(s16*)&work[CARDWORK(0x890)], &work[0x78], *(void**)&work[0x14], 20, work[CARDWORK(0x8C3)]);
            break;
        case 2:
            DrawTextSlots(*(s16*)&work[CARDWORK(0x88C)], *(s16*)&work[CARDWORK(0x892)], &work[0xB8], *(void**)&work[0x14], 20, work[CARDWORK(0x8C4)]);
            break;
        }
    }
}

static void Deckmenu2_2(UnkStruct_0808B66C* w) {
    gCardUiSpriteState.gfx = AnimUpdate(&gCardUiSpriteState.anim);
    if (w->unk_8C9 == 0) {
        if (w->unk_8B0 != 0) {
            DrawSprite((w->x3 >> 8) - 16, (w->y3 >> 8) - 30, w->gfx, w->tiles, w->palette, 0, w->unk_882, 3);
        }
    }
    if (w->unk_8B1 != 13) {
        DrawSprite(w->x4 >> 8, w->y4 >> 8, gUnk_09EEB000, w->tiles4, w->palette, 0, 0x800, 10);
    }
    if (w->tiles6 != 0) {
        DrawSprite(w->x5 >> 8, w->y5 >> 8, gUnk_09EEB080[0], w->tiles6, w->palette3, 0, 0xC00, 10000);
        DrawSprite(w->x6 >> 8, w->y6 >> 8, gUnk_09EEB080[1], w->tiles6, w->palette3, 0, 0xC00, 10000);
    }
    if (w->tiles12 != 0) {
        DrawSprite(w->x7 >> 8, 0,
#ifdef VERSION_EU
                   gUnkEu_09F6FDF0[gLanguage][0],
#else
                   gUnk_09EEAFF0,
#endif
                   w->tiles12, w->palette3, 0, 0, 10);
    }
    switch (w->unk_8B1) {
    case 0:
        if (w->unk_8CF != 0) {
            DrawSprite((w->x8 >> 8) - 16, (w->y7 >> 8) - 20, w->gfx2, w->tiles2, w->palette4, 0, 0, 8);
        }
        DrawSprite((w->x3 >> 8) - 16, (w->y3 >> 8) - 20, w->gfx2, w->tiles2, w->palette4, 0, 0, 8);
        func_0808B3DC((u8*)w, 0);
        DrawSprite(w->x, w->y, w->gfx7, w->tiles5, w->palette, 0, 0, 10);
        DrawSprite(w->x2, w->y2, w->gfx8, w->tiles5, w->palette, 0, 0, 10);
        break;
    case 3:
#ifdef VERSION_EU
        if (w->tiles3 != 0) {
            DrawSprite(120, 80, gUnkEu_09F6FDC8[gLanguage][0], w->tiles3, w->palette2, 0, 0, 8);
        }
#else
        DrawSprite(120, 80, gUnk_09EEAFE8, w->tiles3, w->palette2, 0, 0, 8);
#endif
        func_0808B3DC((u8*)w, 0);
        DrawSprite(w->x, w->y, w->gfx7, w->tiles5, w->palette, 0, 0, 10);
        DrawSprite(w->x2, w->y2, w->gfx8, w->tiles5, w->palette, 0, 0, 10);
        break;
    case 2:
        func_0808B3DC((u8*)w, 0);
        DrawSprite(w->x, w->y, w->gfx7, w->tiles5, w->palette, 0, 0, 10);
        DrawSprite(w->x2, w->y2, w->gfx8, w->tiles5, w->palette, 0, 0, 10);
        break;
    case 1:
        DrawSprite(w->x, w->y, w->gfx7, w->tiles5, w->palette, 0, 0, 10);
        DrawSprite(w->x2, w->y2, w->gfx8, w->tiles5, w->palette, 0, 0, 10);
        func_0808B3DC((u8*)w, 0);
        break;
    case 4:
        func_0808B3DC((u8*)w, 1);
        DrawSprite(w->x, w->y, w->gfx7, w->tiles5, w->palette, 0, 0, 10);
        DrawSprite((w->x3 >> 8) - 16, (w->y3 >> 8) - 20, w->gfx2, w->tiles2, w->palette4, 0, 0, 8);
        if (w->tiles7 != 0) {
            if (w->unk_8C9 == 0) {
                DrawSprite((w->x3 >> 8) - 16, (w->y3 >> 8) - 20, w->gfx2, w->tiles2, w->palette4, 0, 0, 8);
            }
            DrawSprite(24, 82, w->gfx4, w->tiles7, w->palette5, 0, 0x400, 100);
            DrawSprite(24, 82, w->gfx5, w->tiles8, w->palette6, 0, 0x400, 101);
            DrawTextSlots(10, 116, w->textSlots4, w->palette4, 20, w->textSlotCount4);
            if (w->tiles10 != 0) {
                w->gfx3 = AnimUpdate(&w->anim3);
                DrawSprite(24, 82, w->gfx3, w->tiles10, w->palette5, 0, 0, 1);
            }
        }
        if (w->unk_8C9 == 0) {
            func_0808B398((u8*)w);
        }
        break;
    case 7:
        func_0808B3DC((u8*)w, 1);
        DrawSprite(w->x2, w->y2, w->gfx8, w->tiles5, w->palette, 0, 0, 10);
        DrawSprite((w->x3 >> 8) - 16, (w->y3 >> 8) - 20, w->gfx2, w->tiles2, w->palette4, 0, 0, 8);
        if (w->tiles7 != 0) {
            DrawSprite(164, 82, w->gfx4, w->tiles7, w->palette5, 0, 0x400, 100);
            DrawSprite(164, 82, w->gfx5, w->tiles8, w->palette6, 0, 0x400, 101);
            if (w->tiles10 != 0) {
                w->gfx3 = AnimUpdate(&w->anim3);
                DrawSprite(164, 82, w->gfx3, w->tiles10, w->palette5, 0, 0, 1);
            }
            if (w->tiles9 != 0) {
                DrawSprite(164, 82, w->gfx6, w->tiles9, w->palette5, 0, 0, 19);
            }
            DrawTextSlots(100, 116, w->textSlots4, w->palette4, 20, w->textSlotCount4);
            if (w->unk_8C9 == 0) {
                func_0808B398((u8*)w);
            }
        }
        break;
    case 5:
        DrawSprite(w->x, w->y, w->gfx7, w->tiles5, w->palette, 0, 0, 10);
        DrawSprite((w->x3 >> 8) - 26, (w->y3 >> 8) - 13, w->gfx2, w->tiles2, w->palette4, 0, 0, 8);
        func_0808B3DC((u8*)w, 1);
        if (w->tiles7 != 0) {
            DrawSprite(24, 82, w->gfx4, w->tiles7, w->palette5, 0, 0x400, 100);
            DrawSprite(24, 82, w->gfx5, w->tiles8, w->palette6, 0, 0x400, 101);
            if (w->tiles10 != 0) {
                w->gfx3 = AnimUpdate(&w->anim3);
                DrawSprite(24, 82, w->gfx3, w->tiles10, w->palette5, 0, 0, 1);
            }
            DrawTextSlots(10, 116, w->textSlots4, w->palette4, 20, w->textSlotCount4);
        }
        if (w->unk_8C9 == 0) {
            func_0808B398((u8*)w);
        }
        break;
    case 6:
        DrawSprite(w->x, w->y, w->gfx7, w->tiles5, w->palette, 0, 0, 10);
        func_0808B3DC((u8*)w, 1);
        break;
    case 8:
        DrawSprite(w->x2, w->y2, w->gfx8, w->tiles5, w->palette, 0, 0, 10);
        func_0808B3DC((u8*)w, 1);
        break;
    case 9:
        DrawSprite((w->x3 >> 8) - 16, (w->y3 >> 8) - 20, w->gfx2, w->tiles2, w->palette4, 0, 0, 8);
        if (w->tiles7 != 0) {
            DrawSprite(24, 66, w->gfx4, w->tiles7, w->palette5, 0, 0x400, 100);
            DrawSprite(24, 66, w->gfx5, w->tiles8, w->palette6, 0, 0x400, 101);
            if (w->tiles10 != 0) {
                w->gfx3 = AnimUpdate(&w->anim3);
                DrawSprite(24, 66, w->gfx3, w->tiles10, w->palette5, 0, 0, 1);
            }
            DrawTextSlots(10, 100, w->textSlots4, w->palette4, 20, w->textSlotCount4);
        }
        if (w->unk_8C9 == 0) {
            func_0808B398((u8*)w);
        }
        break;
    case 11:
        DrawSprite((w->x3 >> 8) - 26, (w->y3 >> 8) - 13, w->gfx2, w->tiles2, w->palette4, 0, 0, 8);
        if (w->tiles7 != 0) {
            DrawSprite(24, 66, w->gfx4, w->tiles7, w->palette5, 0, 0x400, 100);
            DrawSprite(24, 66, w->gfx5, w->tiles8, w->palette6, 0, 0x400, 101);
            if (w->tiles10 != 0) {
                w->gfx3 = AnimUpdate(&w->anim3);
                DrawSprite(24, 66, w->gfx3, w->tiles10, w->palette5, 0, 0, 1);
            }
            DrawTextSlots(10, 100, w->textSlots4, w->palette4, 20, w->textSlotCount4);
        }
        if (w->unk_8C9 == 0) {
            func_0808B398((u8*)w);
        }
        break;
    case 13:
        DrawSprite(w->x9 >> 8, w->y8 >> 8, w->gfx9, w->tiles11, w->palette7, 0, 0, 20);
        DrawSprite(w->x10 >> 8, 18, 0, w->tiles13, w->palette7, 0, 0, 21);
        DrawTextSlots(138, 16, w->unk_744, w->palette, 20, w->textSlotCount6);
        break;
    case 12:
        DrawSprite((w->x3 >> 8) - 16, (w->y3 >> 8) - 30, w->gfx, w->tiles, w->palette, 0, w->unk_882, 0);
        if (w->tiles7 != 0) {
            DrawSprite(24, 66, w->gfx4, w->tiles7, w->palette5, 0, 0x400, 100);
            DrawSprite(24, 66, w->gfx5, w->tiles8, w->palette6, 0, 0x400, 101);
            if (w->tiles10 != 0) {
                w->gfx3 = AnimUpdate(&w->anim3);
                DrawSprite(24, 66, w->gfx3, w->tiles10, w->palette5, 0, 0, 1);
            }
            DrawTextSlots(10, 100, w->textSlots4, w->palette4, 20, w->textSlotCount4);
        }
        if (w->unk_8C9 == 0) {
            func_0808B398((u8*)w);
        }
        break;
    case 15:
        DrawSprite((w->x3 >> 8) - 16, (w->y3 >> 8) - 30, w->gfx, w->tiles, w->palette, 0, w->unk_882, 0);
        if (w->tiles7 != 0) {
            DrawSprite(24, 66, w->gfx4, w->tiles7, w->palette5, 0, 0x400, 100);
            DrawSprite(24, 66, w->gfx5, w->tiles8, w->palette6, 0, 0x400, 101);
            if (w->tiles10 != 0) {
                w->gfx3 = AnimUpdate(&w->anim3);
                DrawSprite(24, 66, w->gfx3, w->tiles10, w->palette5, 0, 0, 1);
            }
        }
        break;
    }
    TaskPoolDraw(&w->taskpool);
    TaskPoolDraw(&w->cardpool);
}

void func_0808C2F0(u8* work) {
    func_0808C90C(work);
    ReleaseObjTiles(*(void**)&work[0x00]);
    ReleaseObjTiles(*(void**)&work[0x04]);
    ReleaseObjTiles(*(void**)&work[0x10]);
    ReleaseObjPalette(*(void**)&work[0x14]);

    if (*(void**)&work[0x18] != 0) {
        ReleaseObjTiles(*(void**)&work[0x18]);
    }

    if (*(void**)&work[0x4BC] != 0) {
        ReleaseObjTiles(*(void**)&work[0x4BC]);
    }

    if (*(void**)&work[0x4C0] != 0) {
        ReleaseObjPalette(*(void**)&work[0x4C0]);
    }

    func_0808E344((void**)work);
    FreeTextSlots(&work[0x38], 8);
    FreeTextSlots(&work[0x78], 8);
    FreeTextSlots(&work[0xB8], 8);
    FreeTextSlots(&work[0xF8], 30);
    FreeTextSlots(&work[0x1E8], 90);
    ReleaseObjPalette(*(void**)&work[0x4C4]);
    TaskPoolDestroy(&work[CARDWORK(0x7C8)]);
    TaskPoolDestroy(&work[CARDWORK(0x7DC)]);
    func_0808E2F0((UnkStruct_0808DB04*)work);
    **(u8**)&work[CARDWORK(0x8BC)] = work[CARDWORK(0x8D2)];
    ReleaseObjTiles(*(void**)&work[0x4B8]);
    ReleaseObjTiles(gCardUiSpriteState.tiles);
    ReleaseObjPalette(gCardUiSpriteState.palette);
}

void func_0808C3DC(u8* work, u8 kind) {
    UnkStruct_080A97D4 args;
    u16* deck;
    u8 i;
    s8 x;
    s8 y;

    deck = (u16*)GetDeck(work[CARDWORK(0x8C0)]);
    x = 0;
    y = 0;

    if (kind == 0) {
        for (i = 0; i < 99; i++) {
            if (deck[i] != 0xFFFF) {
                if (kind == 0) {
                    args.unk_00 = &work[CARDWORK(0x7F0)];
                    args.cardId = gCardCollection[deck[i]] & 0x8FFF;
                    args.unk_06 = x;
                    args.unk_08 = y;
                    args.unk_0A = 0;
                    args.unk_0C = &deck[i];
                    TaskCreate(&work[CARDWORK(0x7C8)], &gTaskDescDeckCard2, &args);
                } else if (gCardDefs[gCardCollection[deck[i]] & 0xFFF].unk_2A == kind - 1) {
                    args.unk_00 = &work[CARDWORK(0x7F0)];
                    args.cardId = gCardCollection[deck[i]] & 0x8FFF;
                    args.unk_06 = x;
                    args.unk_08 = y;
                    args.unk_0A = 0;
                    args.unk_0C = &deck[i];
                    TaskCreate(&work[CARDWORK(0x7C8)], &gTaskDescDeckCard2, &args);
                }
            } else {
                args.unk_00 = &work[CARDWORK(0x7F0)];
                args.cardId = 0xFFFF;
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 0;
                args.unk_0C = &deck[i];
                TaskCreate(&work[CARDWORK(0x7C8)], &gTaskDescDeckCard2, &args);
            }

            x++;

            if (x > 2) {
                x = 0;
                y++;
            }
        }
    } else {
        for (i = 0; i < 99; i++) {
            if (deck[i] != 0xFFFF && gCardDefs[gCardCollection[deck[i]] & 0xFFF].unk_2A == kind - 1) {
                args.unk_00 = &work[CARDWORK(0x7F0)];
                args.cardId = gCardCollection[deck[i]] & 0x8FFF;
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 0;
                args.unk_0C = &deck[i];
                TaskCreate(&work[CARDWORK(0x7C8)], &gTaskDescDeckCard2, &args);
                x++;
            }

            if (x > 2) {
                x = 0;
                y++;
            }
        }
    }

    *(s32*)&work[CARDWORK(0x850)] = 0x4800;
    *(s32*)&work[CARDWORK(0x854)] = 0x2800;
    *(u16*)&work[CARDWORK(0x8AC)] = 4;
    func_0808C940((UnkStruct_0808C940*)work, 99);
}

s32 func_0808C60C(u8* work, u8 kind, u8 c) {
    UnkStruct_080A97D4 args;
    u16 i;
    u16 count;
    s8 x;
    s8 y;

    x = 0;
    y = 0;
    count = 0;

    if (c == 0) {
        for (i = 0; i < *(u16*)&work[CARDWORK(0x898)]; i++) {
            if (kind == 5) {
                if ((*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_16 != 0) {
                    args.unk_00 = &work[CARDWORK(0x7F0)];
                    args.cardId = func_0808C8D0(
                        (*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_00[10]);
                    args.unk_06 = x;
                    args.unk_08 = y;
                    args.unk_0A = 1;
                    args.unk_0C = 0;
                    TaskCreate(&work[CARDWORK(0x7C8)], &gTaskDescDeckCard2, &args);
                    x++;
                    count++;
                }
            } else if ((*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_16 != 0) {
                args.unk_00 = &work[CARDWORK(0x7F0)];
                args.cardId = func_0808C8D0(
                    (*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_00[10]);

                if (gCardDefs[args.cardId & 0xFFF].unk_2A == kind - 1) {
                    args.unk_06 = x;
                    args.unk_08 = y;
                    args.unk_0A = 1;
                    args.unk_0C = 0;
                    TaskCreate(&work[CARDWORK(0x7C8)], &gTaskDescDeckCard2, &args);
                    x++;
                    count++;
                }
            }

            if (x > 2) {
                x = 0;
                y++;
            }
        }
    } else {
        for (i = 0; i < *(u16*)&work[CARDWORK(0x898)]; i++) {
            if (kind == 5) {
                if ((*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_16 != 0) {
                    if ((u16)((*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_00[10] - 78) >
                        64) {
                        args.unk_00 = &work[CARDWORK(0x7F0)];
                        args.cardId = func_0808C8D0(
                            (*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_00[10]);
                        args.unk_06 = x;
                        args.unk_08 = y;
                        args.unk_0A = 1;
                        args.unk_0C = 0;
                        TaskCreate(&work[CARDWORK(0x7C8)], &gTaskDescDeckCard2, &args);
                        x++;
                        count++;
                    }
                }
            } else if ((*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_16 != 0) {
                args.unk_00 = &work[CARDWORK(0x7F0)];
                args.cardId = func_0808C8D0(
                    (*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_00[10]);

                if (gCardDefs[args.cardId & 0xFFF].unk_2A == kind - 1) {
                    if ((u16)((*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_00[10] - 78) >
                        64) {
                        args.unk_06 = x;
                        args.unk_08 = y;
                        args.unk_0A = 1;
                        args.unk_0C = 0;
                        TaskCreate(&work[CARDWORK(0x7C8)], &gTaskDescDeckCard2, &args);
                        x++;
                        count++;
                    }
                }
            }

            if (x > 2) {
                x = 0;
                y++;
            }
        }
    }

    *(s32*)&work[CARDWORK(0x850)] = 0xA000;
    *(s32*)&work[CARDWORK(0x854)] = 0x2800;
    *(u16*)&work[CARDWORK(0x8AC)] = 4;
    func_0808C940((UnkStruct_0808C940*)work, y * 3 + x);

    return count;
}

s32 func_0808C8D0(s32 a) {
    u32 i;

    for (i = 0; i < 950; i++) {
        if (gCardDefs[i].unk_1C == a) {
            return i;
        }

        if (gCardDefs[i].unk_1C + 143 == a) {
            return i | 0x8000;
        }
    }
}

void func_0808C90C(u8* work) {
    DeckCard2Work* t;

    t = ListPoolFirst(&work[CARDWORK(0x7F0)]);

    while (t != 0) {
        t->unk_4A = 1;
        t = ListPoolNext(&t->node);
    }

    TaskPoolUpdate(&work[CARDWORK(0x7C8)]);
}

void func_0808C940(UnkStruct_0808C940* w, s16 n) {
    w->unk_8AE = n / 3;

    if (n % 3 != 0) {
        w->unk_8AE = n / 3 + 1;
    }
}

void func_0808C974(UnkStruct_0808C940* w) {
    s32 v;

    v = 0x5400 / (w->unk_8AE - 4);
    w->unk_854 = v * (w->unk_8AC - 4) + 0x2800;

    if (w->unk_854 > 0x7C00) {
        w->unk_854 = 0x7C00;
    }

    if (w->unk_854 <= 0x27FF) {
        w->unk_854 = 0x2800;
    }
}

void func_0808C9CC(u8* work) {
    DeckCard2Work* node;

#ifdef VERSION_EU
    node = ListPoolFirst(&work[0x7F4]);

    if (*(s16*)&work[0x8B0] != *(s16*)&work[0x8B2]) {
        while (node != 0) {
            node->unk_24--;

            if (node->unk_24 < 0) {
                node->y = 0x20000;
                func_08090170(node);
            }

            node = ListPoolNext(&node->node);
        }

        m4aSongNumStart(SONG_SYS_CLICKI04B);
        *(u16*)&work[0x8B0] += 1;
        *(s32*)&work[0x858] += 0x300;

        if (*(s32*)&work[0x858] > 0x7C00) {
            *(s32*)&work[0x858] = 0x7C00;
        }

        if (work[0x8D3] != 0) {
            *(u16*)&work[0x87A] -= 1;
        }

        func_0808C974((UnkStruct_0808C940*)work);
    }
#else
    node = ListPoolFirst(&work[0x7F0]);

    if (*(s16*)&work[0x8AC] != *(s16*)&work[0x8AE]) {
        while (node != 0) {
            node->unk_24--;

            if (node->unk_24 < 0) {
                node->y = 0x20000;
                func_08090170(node);
            }

            node = ListPoolNext(&node->node);
        }

        m4aSongNumStart(SONG_SYS_CLICKI04B);
        *(u16*)&work[0x8AC] += 1;
        *(s32*)&work[0x854] += 0x300;

        if (*(s32*)&work[0x854] > 0x7C00) {
            *(s32*)&work[0x854] = 0x7C00;
        }

        if (work[0x8CF] != 0) {
            *(u16*)&work[0x876] -= 1;
        }

        func_0808C974((UnkStruct_0808C940*)work);
    }
#endif
}

u8 func_0808CA78(u8* work, u8 a) {
    DeckCard2Work* n;
    u8 b;
    u16 t;

    b = a;
    n = ListPoolFirst(&work[CARDWORK(0x7F0)]);

    if (*(s16*)&work[CARDWORK(0x8AC)] <= 4) {
        return 0;
    }

    if (n == 0) {
        *(s32*)&work[CARDWORK(0x854)] -= 0x300;

        t = *(u16*)&work[CARDWORK(0x8AC)];

        if ((s16)t > 4) {
            *(u16*)&work[CARDWORK(0x8AC)] = t - 1;
        }

        if (*(s32*)&work[CARDWORK(0x854)] < 0x2800) {
            *(s32*)&work[CARDWORK(0x854)] = 0x2800;
            return 0;
        }

        if (a != 0) {
            m4aSongNumStart(SONG_SYS_CLICKI04B);
        }
    } else {
        if (b != 0) {
            m4aSongNumStart(SONG_SYS_CLICKI04B);
        }

        do {
            n->unk_24++;

            if (n->unk_24 > 3) {
                n->y = 0x20000;
                func_08090170(n);
            }

            n = ListPoolNext(&n->node);
        } while (n != 0);

        *(u16*)&work[CARDWORK(0x8AC)] = *(u16*)&work[CARDWORK(0x8AC)] - 1;
        *(s32*)&work[CARDWORK(0x854)] -= 0x300;

        if (*(s32*)&work[CARDWORK(0x854)] < 0x2800) {
            *(s32*)&work[CARDWORK(0x854)] = 0x2800;
        }
    }

    func_0808C974((UnkStruct_0808C940*)work);
    return 1;
}

DeckCard2Work* func_0808CB60(u8* work) {
    DeckCard2Work* node;

    node = ListPoolFirst(&work[CARDWORK(0x7F0)]);

    while (node != 0) {
        if (*(s16*)&work[CARDWORK(0x884)] == node->unk_22 &&
            *(s16*)&work[CARDWORK(0x886)] == node->unk_24) {
            return node;
        }

        node = ListPoolNext(&node->node);
    }

    return 0;
}

void func_0808CBB4(u8 a, u8 b) {
    u8 d[2];
    u8* base;

    if (a == 0) {
        base = (u8*)GetBgCharBase(3);
        RequestDma3Copy(gUnk_0940F918, base + (b * 64 + 0x360), 32);
        RequestDma3Copy(gUnk_0940F918, base + (b * 64 + 0x360) + 32, 32);
    } else {
        d[0] = a / 10;
        d[1] = a - (u8)(a / 10) * 10;
        base = (u8*)GetBgCharBase(3);
        RequestDma3Copy(&gUnk_0940F7B8[(d[0] + 1) * 32], base + (b * 64 + 0x360), 32);
        RequestDma3Copy(&gUnk_0940F7B8[(d[1] + 1) * 32], base + (b * 64 + 0x360) + 32, 32);
    }
}

void func_0808CC58(u16 a, u8 b) {
    u8 d[3];
    u8* base;

    if (a == 0) {
        base = (u8*)GetBgCharBase(3);
        RequestDma3Copy(gUnk_0940F918, base + (b * 96 + 0x120), 32);
        RequestDma3Copy(gUnk_0940F918, base + (b * 96 + 0x120) + 32, 32);
        RequestDma3Copy(gUnk_0940F918, base + (b * 96 + 0x120) + 64, 32);
    } else {
        d[0] = a / 100;
        d[1] = a / 10 - d[0] * 10;
        d[2] = a - d[0] * 100 - d[1] * 10;
        base = (u8*)GetBgCharBase(3);
        RequestDma3Copy(&gUnk_0940F7B8[(d[0] + 1) * 32], base + (b * 96 + 0x120), 32);
        RequestDma3Copy(&gUnk_0940F7B8[(d[1] + 1) * 32], base + (b * 96 + 0x120) + 32, 32);
        RequestDma3Copy(&gUnk_0940F7B8[(d[2] + 1) * 32], base + (b * 96 + 0x120) + 64, 32);
    }
}

void func_0808CD48(u8* work) {
    u16 t;

    switch (work[CARDWORK(0x8B1)]) {
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
    case 13:
        AnimStart(&work[CARDWORK(0x800)], 0, 1);
        *(u16*)&work[CARDWORK(0x882)] &= ~1;
        break;
    case 1:
    case 3:
    case 12:
        AnimStart(&work[CARDWORK(0x800)], 2, 1);
        t = *(u16*)&work[CARDWORK(0x882)] | 1;
        *(u16*)&work[CARDWORK(0x882)] = t;
        break;
    }
}

void func_0808CDE8(u8* work, u8 b) {
    void* dst;
    switch (b) {
    case 0:
        dst = (void*)0x05000100;
        LoadPalette(gUnk_096142F8, dst, 32);
        dst = (void*)0x05000120;
        LoadPalette(&gUnk_09614118[0x120], dst, 32);
        dst = (void*)0x05000140;
        LoadPalette(&gUnk_09614118[0x140], dst, 32);
        LoadBgMap(0, &gUnk_09519AB8[0x180], 0x180);
        LoadBgMap(1, gUnk_0951A2B8, 0x180);
        LoadBgMap(2, gUnk_0951AAB8, 0x180);
        SetBgScroll(0, 0xFFB4, 0xFFF2);
        SetBgScroll(1, 0xFFA8, 0xFFC0);
        SetBgScroll(2, 0xFFA8, 0xFF90);
        *(u16*)&work[CARDWORK(0x888)] = 100;
        *(u16*)&work[CARDWORK(0x88E)] = 25;
        *(u16*)&work[CARDWORK(0x88A)] = 102;
        *(u16*)&work[CARDWORK(0x890)] = 75;
        *(u16*)&work[CARDWORK(0x88C)] = 102;
        *(u16*)&work[CARDWORK(0x892)] = 122;
        break;
    case 1:
        dst = (void*)0x05000120;
        LoadPalette(gUnk_096142F8, dst, 32);
        dst = (void*)0x05000100;
        LoadPalette(&gUnk_09614118[0x100], dst, 32);
        dst = (void*)0x05000140;
        LoadPalette(&gUnk_09614118[0x140], dst, 32);
        LoadBgMap(0, gUnk_09519AB8, 0x180);
        LoadBgMap(1, &gUnk_0951A2B8[0x180], 0x180);
        LoadBgMap(2, gUnk_0951AAB8, 0x180);
        SetBgScroll(0, 0xFFA8, 0xFFF0);
        SetBgScroll(1, 0xFFB4, 0xFFC2);
        SetBgScroll(2, 0xFFA8, 0xFF90);
        *(u16*)&work[CARDWORK(0x888)] = 102;
        *(u16*)&work[CARDWORK(0x88E)] = 27;
        *(u16*)&work[CARDWORK(0x88A)] = 100;
        *(u16*)&work[CARDWORK(0x890)] = 73;
        *(u16*)&work[CARDWORK(0x88C)] = 102;
        *(u16*)&work[CARDWORK(0x892)] = 122;
        break;
    case 2:
        dst = (void*)0x05000140;
        LoadPalette(gUnk_096142F8, dst, 32);
        dst = (void*)0x05000100;
        LoadPalette(&gUnk_09614118[0x100], dst, 32);
        dst = (void*)0x05000120;
        LoadPalette(&gUnk_09614118[0x120], dst, 32);
        LoadBgMap(0, gUnk_09519AB8, 0x180);
        LoadBgMap(1, gUnk_0951A2B8, 0x180);
        LoadBgMap(2, &gUnk_0951AAB8[0x180], 0x180);
        SetBgScroll(0, 0xFFA8, 0xFFF0);
        SetBgScroll(1, 0xFFA8, 0xFFC0);
        SetBgScroll(2, 0xFFB4, 0xFF92);
        *(u16*)&work[CARDWORK(0x888)] = 102;
        *(u16*)&work[CARDWORK(0x88E)] = 27;
        *(u16*)&work[CARDWORK(0x88A)] = 102;
        *(u16*)&work[CARDWORK(0x890)] = 75;
        *(u16*)&work[CARDWORK(0x88C)] = 100;
        *(u16*)&work[CARDWORK(0x892)] = 121;
        break;
    }
}

void func_0808D0A4(u8 deck) {
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
#ifdef VERSION_EU
        base = GetBgCharBase(0) + 0x2BE0;
#else
        base = GetBgCharBase(0);
#endif
        break;
    case 1:
#ifdef VERSION_EU
        base = GetBgCharBase(1) + 0x2F40;
#else
        base = GetBgCharBase(1);
#endif
        break;
    case 2:
#ifdef VERSION_EU
        base = GetBgCharBase(2) + 0x32A0;
#else
        base = GetBgCharBase(2);
#endif
        break;
    }

    RequestDma3Copy(&gUnk_0940F938[(d[0] + 1) * 32], (u8*)base + 0x20, 32);
    RequestDma3Copy(&gUnk_0940F938[(d[1] + 1) * 32], (u8*)base + 0x40, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[0] + 1) * 32], (u8*)base + 0x60, 32);
    RequestDma3Copy(&gUnk_0940F938[(e[1] + 1) * 32], (u8*)base + 0x80, 32);
}

void func_0808D16C(u8 mode) {
#ifdef VERSION_EU
    u8* bg0;
    u8* bg1;
    u8* bg2;
    u8* src;

    bg0 = (u8*)GetBgCharBase(0) + 0x2D80;
    bg1 = (u8*)GetBgCharBase(1) + 0x30E0;
    bg2 = (u8*)GetBgCharBase(2) + 0x3440;
    src = gUnkEu_09F6FE04[gLanguage];

    switch (mode) {
    case 0:
        RequestDma3Copy(src + 0x20, bg0, 0x1E0);
        RequestDma3Copy(src + 0x420, bg1, 0x1E0);
        RequestDma3Copy(src + 0x420, bg2, 0x1E0);
        break;
    case 1:
        RequestDma3Copy(src + 0x420, bg0, 0x1E0);
        RequestDma3Copy(src + 0x20, bg1, 0x1E0);
        RequestDma3Copy(src + 0x420, bg2, 0x1E0);
        break;
    case 2:
        RequestDma3Copy(src + 0x420, bg0, 0x1E0);
        RequestDma3Copy(src + 0x420, bg1, 0x1E0);
        RequestDma3Copy(src + 0x20, bg2, 0x1E0);
        break;
    }
#else
    u32 bg0;
    u32 bg1;
    u32 bg2;

    bg0 = GetBgCharBase(0);
    bg1 = GetBgCharBase(1);
    bg2 = GetBgCharBase(2);

    switch (mode) {
    case 0:
        RequestDma3Copy(gUnk_0940FC58, (u8*)bg0 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_0940FC58 + 0x400, (u8*)bg1 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_0940FC58 + 0x400, (u8*)bg2 + 0x1A0, 0x1E0);
        break;
    case 1:
        RequestDma3Copy(gUnk_09410058, (u8*)bg0 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_09410058 - 0x400, (u8*)bg1 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_09410058, (u8*)bg2 + 0x1A0, 0x1E0);
        break;
    case 2:
        RequestDma3Copy(gUnk_09410058, (u8*)bg0 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_09410058, (u8*)bg1 + 0x1A0, 0x1E0);
        RequestDma3Copy(gUnk_09410058 - 0x400, (u8*)bg2 + 0x1A0, 0x1E0);
        break;
    }
#endif
}

void func_0808D258(u8 mode) {
    u8 d1[4];
    u8 d2[4];
    u16 v;

    u32 base;

    base = 0;
    v = GetDeckCpCost(mode);

    d1[0] = v / 1000;
    d1[1] = v / 100 - d1[0] * 10;
    d1[2] = v / 10 - d1[0] * 100 - d1[1] * 10;
    d1[3] = v - d1[0] * 1000 - d1[1] * 100 - d1[2] * 10;
    d2[0] = gGameState.progression.cp / 1000;
    d2[1] = gGameState.progression.cp / 100 - d2[0] * 10;
    d2[2] = gGameState.progression.cp / 10 - d2[0] * 100 - d2[1] * 10;
    d2[3] = gGameState.progression.cp - d2[0] * 1000 - d2[1] * 100 - d2[2] * 10;

    switch (mode) {
    case 0:
#ifdef VERSION_EU
        base = GetBgCharBase(0) + 0x2BE0;
#else
        base = GetBgCharBase(0);
#endif
        break;
    case 1:
#ifdef VERSION_EU
        base = GetBgCharBase(1) + 0x2F40;
#else
        base = GetBgCharBase(1);
#endif
        break;
    case 2:
#ifdef VERSION_EU
        base = GetBgCharBase(2) + 0x32A0;
#else
        base = GetBgCharBase(2);
#endif
        break;
    }

    RequestDma3Copy(&gUnk_0940F938[(d1[0] + 1) * 32], (void*)(base + 0xA0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d1[1] + 1) * 32], (void*)(base + 0xC0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d1[2] + 1) * 32], (void*)(base + 0xE0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d1[3] + 1) * 32], (void*)(base + 0x100), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[0] + 1) * 32], (void*)(base + 0x120), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[1] + 1) * 32], (void*)(base + 0x140), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[2] + 1) * 32], (void*)(base + 0x160), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[3] + 1) * 32], (void*)(base + 0x180), 32);
}
#ifdef VERSION_EU
#define CARD_SLOT_OFFSET(slot, fixed) ((fixed) * 256)
#else
#define CARD_SLOT_OFFSET(slot, fixed) ((slot) * 256)
#endif
void func_0808D438(u8 kind, u8 slot) {
    u8* dst;

    dst = (u8*)GetBgScreenBase(3) + 0x80;

    switch (kind) {
    case 0:
        RequestDma3Copy(gUnk_095152B8 + CARD_SLOT_OFFSET(slot, 0), dst, 20);
        RequestDma3Copy(gUnk_095152B8 + 0x40 + CARD_SLOT_OFFSET(slot, 0), dst + 0x40, 20);
        break;
    case 1:
        RequestDma3Copy(gUnk_095152CC + CARD_SLOT_OFFSET(slot, 0), dst, 20);
        RequestDma3Copy(gUnk_095152CC + 0x40 + CARD_SLOT_OFFSET(slot, 0), dst + 0x40, 20);
        break;
    case 2:
        RequestDma3Copy(gUnk_095152E0 + CARD_SLOT_OFFSET(slot, 0), dst, 20);
        RequestDma3Copy(gUnk_095152E0 + 0x40 + CARD_SLOT_OFFSET(slot, 0), dst + 0x40, 20);
        break;
    case 3:
        RequestDma3Copy(gUnk_09515338 + CARD_SLOT_OFFSET(slot, 0), dst, 20);
        RequestDma3Copy(gUnk_09515338 + 0x40 + CARD_SLOT_OFFSET(slot, 0), dst + 0x40, 20);
        break;
    case 4:
        RequestDma3Copy(gUnk_0951534C + CARD_SLOT_OFFSET(slot, 0), dst, 20);
        RequestDma3Copy(gUnk_0951534C + 0x40 + CARD_SLOT_OFFSET(slot, 0), dst + 0x40, 20);
        break;
    }
}

void func_0808D4E4(u8 kind, u8 slot) {
    u8* dst;

    dst = (u8*)GetBgScreenBase(3) + 0xA8;

    switch (kind) {
    case 5:
        RequestDma3Copy(gUnk_095152B8 + CARD_SLOT_OFFSET(slot, 1), dst, 20);
        RequestDma3Copy(gUnk_095152B8 + 0x40 + CARD_SLOT_OFFSET(slot, 1), dst + 0x40, 20);
        break;
    case 4:
        RequestDma3Copy(gUnk_095152CC + CARD_SLOT_OFFSET(slot, 1), dst, 20);
        RequestDma3Copy(gUnk_095152CC + 0x40 + CARD_SLOT_OFFSET(slot, 1), dst + 0x40, 20);
        break;
    case 3:
        RequestDma3Copy(gUnk_095152E0 + CARD_SLOT_OFFSET(slot, 1), dst, 20);
        RequestDma3Copy(gUnk_095152E0 + 0x40 + CARD_SLOT_OFFSET(slot, 1), dst + 0x40, 20);
        break;
    case 2:
        RequestDma3Copy(gUnk_09515338 + CARD_SLOT_OFFSET(slot, 1), dst, 20);
        RequestDma3Copy(gUnk_09515338 + 0x40 + CARD_SLOT_OFFSET(slot, 1), dst + 0x40, 20);
        break;
    case 1:
        RequestDma3Copy(gUnk_0951534C + CARD_SLOT_OFFSET(slot, 1), dst, 20);
        RequestDma3Copy(gUnk_0951534C + 0x40 + CARD_SLOT_OFFSET(slot, 1), dst + 0x40, 20);
        break;
    }
}

void func_0808D594(void) {
    u8 d1[3];
    u8 d2[3];
    u16 a;
    u16 b;

    u32 base;

    a = CountCardsInDecks();
    b = CountCollectionCards();

    d1[0] = a / 100;
    d1[1] = a / 10 - d1[0] * 10;
    d1[2] = a - d1[0] * 100 - d1[1] * 10;
    d2[0] = b / 100;
    d2[1] = b / 10 - d2[0] * 10;
    d2[2] = b - d2[0] * 100 - d2[1] * 10;
    base = GetBgCharBase(3);
    RequestDma3Copy(&gUnk_0940F938[(d1[0] + 1) * 32], (void*)(base + 0x2A0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d1[1] + 1) * 32], (void*)(base + 0x2C0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d1[2] + 1) * 32], (void*)(base + 0x2E0), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[0] + 1) * 32], (void*)(base + 0x300), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[1] + 1) * 32], (void*)(base + 0x320), 32);
    RequestDma3Copy(&gUnk_0940F938[(d2[2] + 1) * 32], (void*)(base + 0x340), 32);
}

void func_0808D6C4(u8* work) {
    InitTextSlots(&work[0x38], 8);
    InitTextSlots(&work[0x78], 8);
    InitTextSlots(&work[0xB8], 8);
#ifdef VERSION_EU
    work[0x8C6] = LoadTextSlots(GetDeckName(0), &work[0x38]);
    work[0x8C7] = LoadTextSlots(GetDeckName(1), &work[0x78]);
    work[0x8C8] = LoadTextSlots(GetDeckName(2), &work[0xB8]);
#else
    work[0x8C2] = LoadTextSlots(GetDeckName(0), &work[0x38]);
    work[0x8C3] = LoadTextSlots(GetDeckName(1), &work[0x78]);
    work[0x8C4] = LoadTextSlots(GetDeckName(2), &work[0xB8]);
#endif
}

void func_0808D73C(u8* work, s32 id) {
    CardDef* def;

    def = &gCardDefs[id];
#ifdef VERSION_EU
    work[CARDWORK(0x8C5)] = LoadTextSlots(eu_0805E924(def->name), &work[0xF8]);
#else
    work[0x8C5] = LoadTextSlots(def->name, &work[0xF8]);
#endif

    switch (def->unk_2A) {
    case 0:
        LoadPalette(gUnk_09614458,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->index * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->count << 5));
        break;
    case 1:
        LoadPalette(gUnk_09614478,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->index * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->count << 5));
        break;
    case 2:
        LoadPalette(gUnk_09614498,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->index * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->count << 5));
        break;
    case 3:
        LoadPalette(gUnk_096144B8,
                    (void*)((*(UnkStruct_080038C8**)&work[0x4C4])->index * 32 +
                            0x05000200),
                    (u16)((*(UnkStruct_080038C8**)&work[0x4C4])->count << 5));
        break;
    }
}

void func_0808D7EC(u8* work, u16 index) {
    CardDef* d;
    void* s;

    d = &gCardDefs[index];
    s = gUnk_09EE8F48[d->unk_1C];
    work[CARDWORK(0x8C6)] = LoadTextSlots(LANGSTR(s), &work[0x1E8]);
}

s32 func_0808D828(u8* work) {
    DeckCard2Work* t;
    CardDef* def;
    void* dst;
    u16 id;
    u16 flag;
    u16 v;
    u8 i;
    u8 j;
    u16 k;

    id = 0xFFFF;
    t = ListPoolFirst(&work[CARDWORK(0x7F0)]);

    while (t != 0) {
        if (t->unk_24 == *(s16*)&work[CARDWORK(0x886)] &&
            t->unk_22 == *(s16*)&work[CARDWORK(0x884)]) {
            id = t->cardId;
            break;
        }

        t = ListPoolNext(&t->node);
    }

    func_0808DB04((void**)work);

    if (id != 0xFFFF) {
        flag = id & 0x8000;

        if (flag != 0) {
            *(void**)&work[0x28] = AllocObjTiles(0x280, 0);
            SetObjTileSource(*(void**)&work[0x28], gUnk_0908B1B4);
            AnimInit((AnimState*)&work[CARDWORK(0x830)], gUnk_09EEA164, gUnk_09EEA148);
            AnimStart((AnimState*)&work[CARDWORK(0x830)], 0, 1);
            *(void**)&work[0x4F8] = AnimGetGfx((AnimState*)&work[CARDWORK(0x830)]);
        }

        def = &gCardDefs[id & 0xFFF];
        *(void**)&work[0x1C] = LoadObjTiles(gUnk_08F709B0[def->unk_2A].tiles, 0x300);
        *(void**)&work[0x20] = LoadObjTiles(def->tiles, 0x200);
        *(void**)&work[0x34] = LoadObjPalette(def->palette, 32);
        *(void**)&work[0x30] = LoadObjPalette(gUnk_09611AB8, 32);
        *(void**)&work[0x4DC] = gUnk_08F709B0[def->unk_2A].gfx;
        *(void**)&work[0x4E0] = def->gfx;

        for (i = 0; i < *(u16*)&work[CARDWORK(0x898)]; i++) {
            if ((u16)(id & 0x8000) != 0) {
                if ((*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_00[10] ==
                    def->unk_1C + 143) {
                    break;
                }
            } else {
                if ((*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_00[10] ==
                    def->unk_1C) {
                    break;
                }
            }
        }

        *(u16*)&work[CARDWORK(0x880)] = i;
        dst = gUnk_05000160;
        LoadPalette(&gUnk_09614318[def->unk_2A * 32], dst, 32);

        for (j = 0; j <= 9; j++) {
            func_0808DD20((u8)(*(UnkStruct_0808E2F0**)&work[0x4D4])[i].unk_00[j], j);
        }

        v = id & 0xFFF;
        func_0808D73C(work, v);
        func_0808D7EC(work, v);

        if (work[CARDWORK(0x8B1)] >= 9 && work[CARDWORK(0x8B1)] <= 12) {
            if (def->unk_1C > 46) {
                LoadBgMap(2, gUnk_09518AB8, 0x800);
                func_0808DE28((u8)GetCardCpCost(id));
                return id;
            }

            LoadBgMap(2, gUnk_095182B8, 0x800);
            func_0808DE28(0);
        } else if (def->unk_1C > 46) {
            switch (work[CARDWORK(0x8C0)]) {
            case 0:
                LoadBgMap(1, gUnk_09518AB8, 0x800);
                break;
            case 1:
            case 2:
                LoadBgMap(0, gUnk_09518AB8, 0x800);
                break;
            }

            func_0808DE28(0);
        } else {
            switch (work[CARDWORK(0x8C0)]) {
            case 0:
                LoadBgMap(1, gUnk_095182B8, 0x800);
                break;
            case 1:
            case 2:
                LoadBgMap(0, gUnk_095182B8, 0x800);
                break;
            }

            func_0808DE28(0);
        }
    } else {
        for (k = 0; k <= 9; k++) {
            func_0808DD20(0, k);
        }

        func_0808DE28(0);
    }

    return id;
}

void func_0808DB04(void** p) {
    if (p[10] != 0) {
        ReleaseObjTiles(p[10]);
        p[10] = 0;
    }

    if (p[7] != 0) {
        ReleaseObjTiles(p[7]);
        ReleaseObjPalette(p[12]);
        ReleaseObjTiles(p[8]);
        ReleaseObjPalette(p[13]);

        if (p[9] != 0) {
            ReleaseObjTiles(p[9]);
            p[9] = 0;
        }

        p[7] = 0;
        p[12] = 0;
        p[8] = 0;
        p[13] = 0;
    }
}

void func_0808DB50(UnkStruct_0808DB04* w) {
    DeckCard2Work* node;
    CardDef* def;
    void* dst;
    u16 id;

    id = 0xFFFF;
    node = ListPoolFirst(&w->pool);

    while (node != 0) {
        if (node->unk_24 == (s16)w->unk_886 && node->unk_22 == w->unk_884) {
            id = node->cardId;
            break;
        }

        node = ListPoolNext(&node->node);
    }

    func_0808DB04((void**)w);

    if (id != 0xFFFF) {
        if (id & 0x8000) {
            w->tiles5 = AllocObjTiles(0x280, 0);
            SetObjTileSource(w->tiles5, gUnk_0908B1B4);
            AnimInit(&w->anim, gUnk_09EEA164, gUnk_09EEA148);
            AnimStart(&w->anim, 0, 1);
            w->gfx = AnimGetGfx(&w->anim);
        }

        def = &gCardDefs[id & CARD_ID_MASK];
        w->tiles2 = LoadObjTiles(gUnk_08F709B0[def->unk_2A].tiles, 768);
        w->tiles3 = LoadObjTiles(def->tiles, 512);
        w->palette2 = LoadObjPalette(def->palette, 32);
        w->palette = LoadObjPalette(gUnk_09611AB8, 32);
        w->gfx2 = gUnk_08F709B0[def->unk_2A].gfx;
        w->gfx3 = def->gfx;

        if ((id & CARD_ID_MASK) <= 0x1C1) {
            w->tiles4 = LoadObjTiles(gUnk_0905EAE8, 480);
            w->gfx4 = gUnk_09EE981C[def->unk_20];
        }

        func_0808DE28(GetCardCpCost(id));
        dst = gUnk_05000160;
        LoadPalette(&gUnk_09614118[def->unk_2A * 32 + 0x200], dst, 32);
        func_0808D73C((u8*)w, id & CARD_ID_MASK);
        func_0808D7EC((u8*)w, id & CARD_ID_MASK);
    } else {
        func_0808DE28(0);
    }
}

void func_0808DD20(u8 a, u16 b) {
    u8 v[2];
    u8* base;

    base = (u8*)GetBgCharBase(3);

    if (a != 0) {
        u8* dst;

        v[0] = a / 10;
        v[1] = a - v[0] * 10;
        RequestDma3Copy(&gUnk_0940FA98[(v[0] + 3) * 32], dst = base + (b * 64 + 0xD20), 32);
        RequestDma3Copy(&gUnk_0940FA98[(v[1] + 3) * 32], dst += 32, 32);
    } else {
        u8* dst;

        RequestDma3Copy(gUnk_0940FAD8, dst = base + (b * 64 + 0xD20), 32);
        RequestDma3Copy(gUnk_0940FAD8, dst += 32, 32);
        LoadPalette(gUnk_09614406, (void*)(b * 2 + 0x0500016C), 2);
    }
}

void func_0808DDD0(u8* work) {
    u16 t;

    t = func_0808C8D0(*(u16*)(*(u16*)&work[CARDWORK(0x880)] * 32 +
                              (u32)*(void**)&work[0x4D4] + 20));
    func_0808DE28(GetCardCpCost(t + *(s16*)&work[CARDWORK(0x884)] * 5 +
                                *(u16*)&work[CARDWORK(0x886)]));
}

void func_0808DE28(u8 a) {
    u8 d[2];
    u32 base;

    base = GetBgCharBase(3);

    if (a != 0) {
        d[0] = a / 10;
        d[1] = a - d[0] * 10;
        RequestDma3Copy(&gUnk_0940FA98[(d[0] + 3) * 32], (void*)(base + 0xCE0), 32);
        RequestDma3Copy(&gUnk_0940FA98[(d[1] + 3) * 32], (void*)(base + 0xD00), 32);
    } else {
        RequestDma3Copy(gUnk_0940FAD8, (void*)(base + 0xCE0), 32);
        RequestDma3Copy(gUnk_0940FAD8, (void*)(base + 0xD00), 32);
    }
}

u32 func_0808DEB8(u16* data) {
    u32 sum;
    u16* p;
    s32 i;

    sum = 0;
    p = data;
    i = 9;

    do {
        sum += *p++;
    } while (--i >= 0);

    return sum;
}

s32 func_0808DED0(UnkStruct_0808DB04* w, u16 keys) {
    UnkStruct_0808E2F0* p;
    u8 y0;
    u8 x0;
    u8 idx;
    s8 v;
    s8 d;
    s32 i;
    s32 sum;
    s32 n;
    u16 t;
    u16 t884;
    s16 k;
    u8* x;

    k = w->unk_884 * 5 + *(u8*)&w->unk_886;
    idx = k;
    p = &w->unk_4D4[w->unk_880];
    t884 = *(u16*)&w->unk_884;
    y0 = w->unk_884;
    x0 = *(u8*)&w->unk_886;

    if (p->unk_00[idx] != 0) {
        return 1;
    }

    switch (keys) {
    case 64:
        do {
            t = *(u16*)&w->unk_886;
            *(u16*)&w->unk_886 = (s16)t > 0 ? t - 1 : 4;
            idx = w->unk_884 * 5 + *(u8*)&w->unk_886;

            if (w->unk_884 == y0 && (s16)w->unk_886 == x0) {
                return 0;
            }
        } while (p->unk_00[idx] == 0);
        break;
    case 128:
        do {
            t = *(u16*)&w->unk_886;
            *(u16*)&w->unk_886 = (s16)t <= 3 ? t + 1 : 0;
            idx = w->unk_884 * 5 + *(u8*)&w->unk_886;

            if (w->unk_884 == y0 && (s16)w->unk_886 == x0) {
                return 0;
            }
        } while (p->unk_00[idx] == 0);
        break;
    case 32:
        if (p->unk_00[(s16)w->unk_886] != 0) {
            if ((s16)t884 > 0) {
                *(u16*)&w->unk_884 = t884 - 1;
            }

            break;
        }

        sum = 0;

        for (i = 0; i < 5; i++) {
            sum += p->unk_00[i];
        }

        if (sum == 0) {
            *(u16*)&w->unk_884 = 1;
            return 0;
        }

        x = (u8*)&w->unk_886;
        d = -1;
        n = *x + d;

        while (1) {
            v = n;

            if (v < 0) {
                v = 0;
            }

            if (v > 4) {
                v = 4;
            }

            if (p->unk_00[v] != 0) {
                break;
            }

            if (d < 0) {
                d = -d;
            } else {
                d = d + 1;
                d = -d;
            }

            n = d + *x;
        }

        goto store;
    case 16:
        if (p->unk_00[(s16)w->unk_886 + 5] != 0) {
            if ((s16)t884 <= 0) {
                *(u16*)&w->unk_884 = t884 + 1;
            }

            break;
        }

        sum = 0;

        for (i = 0; i < 5; i++) {
            sum += p->unk_00[i + 5];
        }

        if (sum == 0) {
            *(u16*)&w->unk_884 = 0;
            return 0;
        }

        x = (u8*)&w->unk_886;
        d = -1;
        n = *x + d;

        for (;;) {
            v = n;

            if (v < 0) {
                v = 0;
            }

            if (v > 4) {
                v = 4;
            }

            if (p->unk_00[v + 5] != 0) {
                break;
            }

            if (d < 0) {
                d = -d;
            } else {
                d = d + 1;
                d = -d;
            }

            n = d + *x;
        }

store:
        k = v;
        *(u16*)&w->unk_886 = k;
        break;
    case 0:
        do {
            t = *(u16*)&w->unk_886;

            if ((s16)t <= 3) {
                *(u16*)&w->unk_886 = t + 1;
            } else {
                *(u16*)&w->unk_886 = 0;
            }

            if (w->unk_884 == y0 && (s16)w->unk_886 == x0) {
                t884 = *(u16*)&w->unk_884;

                if ((s16)t884 <= 0) {
                    *(u16*)&w->unk_884 = t884 + 1;
                } else {
                    *(u16*)&w->unk_884 = 0;
                }

                *(u16*)&w->unk_886 = 0;

                if (func_0808DEB8(p->unk_00) == 0) {
                    return 0;
                }
            }

            idx = w->unk_884 * 5 + *(u8*)&w->unk_886;
        } while (p->unk_00[idx] == 0);
        break;
    }

    return 1;
}

s32 func_0808E19C(UnkStruct_0808DB04* w) {
    u16 mask;
    u16 idx;
    UnkStruct_0808E2F0* e;
    u16 i;
    u16 card;
    u16 v;
    u32 id;
    CardDef* def;

    mask = 0;
    idx = w->unk_884 * 5 + w->unk_886;

    switch (w->unk_8C0) {
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

    e = &w->unk_4D4[w->unk_880];

    if (e->unk_00[idx] == 0) {
        m4aSongNumStart(SONG_SYS_BEEP);
        return 0;
    }

    for (i = 0; i < e->unk_16; i++) {
        card = e->unk_1C[i];
        v = gCardCollection[card];

        if (!(mask & v)) {
            id = v & 0xFFF;
            def = &gCardDefs[id];

            if (id > 0x1C1) {
                if (idx == 0) {
                    AddCardToDeck(card, w->unk_8C0);
                    e->unk_00[idx]--;
                    func_0808DD20(e->unk_00[idx], idx);
                    m4aSongNumStart(SONG_SYS_KETTEI);
                    return e->unk_00[idx];
                }
            } else if (def->unk_20 == idx) {
                AddCardToDeck(card, w->unk_8C0);
                e->unk_00[idx]--;
                func_0808DD20(e->unk_00[idx], idx);
                m4aSongNumStart(SONG_SYS_KETTEI);
                return e->unk_00[idx];
            }
        }
    }

    m4aSongNumStart(SONG_SYS_BEEP);
}

void func_0808E2F0(UnkStruct_0808DB04* w) {
    u16 i;

    if (w->unk_4D4 != 0) {
        for (i = 0; i < w->unk_898; i++) {
            EwramFree(w->unk_4D4[i].unk_1C);
        }

        EwramFree(w->unk_4D4);
        w->unk_4D4 = 0;
    }
}

void func_0808E344(void** p) {
    if (p[2] != 0) {
        ReleaseObjTiles(p[2]);
        ReleaseObjPalette(p[3]);
        p[2] = 0;
        p[3] = 0;
    }
}

void func_0808E364(u8* work, u8 kind) {
    switch (kind) {
    case 0:
        SetObjTileSource(*(void**)&work[4], gUnk_090A4A0C);
#ifdef VERSION_EU
        AnimInit(&work[0x81C], gUnk_09EEB064, gUnk_09EEB050);
        AnimStart(&work[0x81C], 0, 1);
        *(void**)&work[0x4F4] = AnimGetGfx(&work[0x81C]);
#else
        AnimInit(&work[0x818], gUnk_09EEB064, gUnk_09EEB050);
        AnimStart(&work[0x818], 0, 1);
        *(void**)&work[0x4F4] = AnimGetGfx(&work[0x818]);
#endif
        break;
    case 1:
        SetObjTileSource(*(void**)&work[4], gUnk_090A51F6);
#ifdef VERSION_EU
        AnimInit(&work[0x81C], gUnk_09EEB07C, gUnk_09EEB068);
        AnimStart(&work[0x81C], 0, 1);
        *(void**)&work[0x4F4] = AnimGetGfx(&work[0x81C]);
#else
        AnimInit(&work[0x818], gUnk_09EEB07C, gUnk_09EEB068);
        AnimStart(&work[0x818], 0, 1);
        *(void**)&work[0x4F4] = AnimGetGfx(&work[0x818]);
#endif
        break;
    }
}

void func_0808E3E0(u8* work) {
    DeckCard2Work* n;

    n = ListPoolFirst(&work[CARDWORK(0x7F0)]);

    while (n != 0) {
        if (n->unk_24 == *(s16*)&work[CARDWORK(0x886)] && n->unk_22 == *(s16*)&work[CARDWORK(0x884)]) {
            if (n->cardId != 0xFFFF) {
                RemoveCardFromDeck(n->unk_28, work[CARDWORK(0x8C0)]);
                n->unk_4A = 1;
                ((UnkStruct_0808E3E0*)n)->unk_24 |= 0xFFFF;
                m4aSongNumStart(SONG_SYS_KETTEI);
            } else {
                m4aSongNumStart(SONG_SYS_BEEP);
            }

            return;
        }

        n = ListPoolNext(&n->node);
    }

    m4aSongNumStart(SONG_SYS_BEEP);
}
u8 func_0808E474(UnkStruct_0808DB04* w) {
    u16 idx;
    UnkStruct_0808E2F0* e;
    u16 i;
    u16 id;
    u16 c;
    CardDef* def;

    idx = w->unk_884 * 5 + w->unk_886;
    e = &w->unk_4D4[w->unk_880];

    if (e->unk_00[idx] == 0) {
        m4aSongNumStart(SONG_SYS_BEEP);
        return 1;
    }

    for (i = 0; i < e->unk_16; i++) {
        id = e->unk_1C[i];

        if (id == 0xFFFF) {
            continue;
        }

        c = gCardCollection[id] & CARD_ID_MASK;
        def = &gCardDefs[c];

        if (c > 0x1C2) {
            if (idx != 0) {
                continue;
            }

            if (def->unk_2A != 0) {
                return 1;
            }

            if (func_08084FAC(def->unk_2A) > 1) {
                return 1;
            }

            TaskCreate(&w->tasks2, &gUnk_09EE7FD8, &w->unk_888[0x41]);
            m4aSongNumStart(SONG_SYS_BEEP);
            return 0;
        } else {
            if (def->unk_20 != idx) {
                continue;
            }

            if (def->unk_2A != 0) {
                return 1;
            }

            if (func_08084FAC(def->unk_2A) > 1) {
                return 1;
            }

            TaskCreate(&w->tasks2, &gUnk_09EE7FD8, &w->unk_888[0x41]);
            m4aSongNumStart(SONG_SYS_BEEP);
            return 0;
        }
    }

    return 1;
}
u8 func_0808E58C(UnkStruct_0808DB04* w) {
    u16 idx;
    UnkStruct_0808E2F0* e;
    u16 i;
    u16 card;
    u16 id;
    CardDef* def;

    idx = w->unk_884 * 5 + w->unk_886;
    e = &w->unk_4D4[w->unk_880];

    if (e->unk_00[idx] == 0) {
        m4aSongNumStart(SONG_SYS_BEEP);
        return 1;
    }

    for (i = 0; i < e->unk_16; i++) {
        card = e->unk_1C[i];

        if (card != 0xFFFF) {
            id = gCardCollection[card] & CARD_ID_MASK;
            def = &gCardDefs[id];

            if (id >= 0x1C2) {
                if (idx == 0) {
                    if (def->unk_2A == 0) {
                        if (func_08084FAC(def->unk_2A) > 1) {
                            ClearCardCollectionSlot(&gCardCollection[card]);
                            e->unk_1C[i] = 0xFFFF;
                            e->unk_00[idx]--;
                            func_0808DD20(e->unk_00[idx], idx);
                            m4aSongNumStart(SONG_SYS_CARD_DELETE);
                            return 1;
                        } else {
                            TaskCreate(&w->tasks2, &gUnk_09EE7FD8, &w->unk_888[0x41]);
                            m4aSongNumStart(SONG_SYS_BEEP);
                            return 0;
                        }
                    } else {
                        ClearCardCollectionSlot(&gCardCollection[card]);
                        e->unk_1C[i] = 0xFFFF;
                        e->unk_00[idx]--;
                        func_0808DD20(e->unk_00[idx], idx);
                        m4aSongNumStart(SONG_SYS_CARD_DELETE);
                        return 1;
                    }
                }
            } else if (def->unk_20 == idx) {
                if (def->unk_2A == 0) {
                    if (func_08084FAC(def->unk_2A) > 1) {
                        ClearCardCollectionSlot(&gCardCollection[card]);
                        e->unk_1C[i] = 0xFFFF;
                        e->unk_00[idx]--;
                        func_0808DD20(e->unk_00[idx], idx);
                        m4aSongNumStart(SONG_SYS_CARD_DELETE);
                        return 1;
                    } else {
                        TaskCreate(&w->tasks2, &gUnk_09EE7FD8, &w->unk_888[0x41]);
                        m4aSongNumStart(SONG_SYS_BEEP);
                        return 0;
                    }
                } else {
                    ClearCardCollectionSlot(&gCardCollection[card]);
                    e->unk_1C[i] = 0xFFFF;
                    e->unk_00[idx]--;
                    func_0808DD20(e->unk_00[idx], idx);
                    m4aSongNumStart(SONG_SYS_CARD_DELETE);
                    return 1;
                }
            }
        }
    }

    m4aSongNumStart(SONG_SYS_BEEP);
    return 1;
}

s32 func_0808E750(u8* work) {
    if (GetDeckCpCost(GetActiveDeckIndex()) > gGameState.progression.cp) {
#ifdef VERSION_EU
        TaskCreate(&work[0x7E0], &gUnk_09EE7FA8, &work[0x8CD]);
#else
        TaskCreate(&work[0x7DC], &gUnk_09EE7FA8, &work[0x8C9]);
#endif
        m4aSongNumStart(SONG_SYS_BEEP);

        return 0;
    }

    return 1;
}

s32 func_0808E79C(u8* work) {
    if (func_080857D4(0) == 0) {
        m4aSongNumStart(SONG_SYS_BEEP);
#ifdef VERSION_EU
        TaskCreate(&work[0x7E0], &gUnk_09EE7FC0, &work[0x8CD]);
#else
        TaskCreate(&work[0x7DC], &gUnk_09EE7FC0, &work[0x8C9]);
#endif

        return 0;
    }

    return 1;
}

void func_0808E7D8(u8* work) {
#ifdef VERSION_EU
    DeckCard2Work* node;
    s16 x;
    s16 y;

    node = ListPoolFirst(&work[0x7F4]);
    x = 0;
    y = 0;

    while (node != 0) {
        node->unk_22 = x;
        node->unk_24 = y;
        x++;

        if (node->flags & 1) {
            ReleaseObjPalette(node->palette2);
            ReleaseObjTiles(node->tiles);
            ReleaseObjPalette(node->palette);
            ReleaseObjTiles(node->tiles2);
            node->flags &= ~1;
            node->tiles = 0;
            node->palette = 0;
            node->tiles2 = 0;
            node->palette2 = 0;
        }

        if (x > 2) {
            x = 0;
            y++;
        }

        node = ListPoolNext(&node->node);
    }

    *(s32*)&work[0x858] = 0x2800;
    *(u16*)&work[0x8B0] = 4;
#else
    DeckCard2Work* node;
    s16 x;
    s16 y;

    node = ListPoolFirst(&work[0x7F0]);
    x = 0;
    y = 0;

    while (node != 0) {
        node->unk_22 = x;
        node->unk_24 = y;
        x++;

        if (node->flags & 1) {
            ReleaseObjPalette(node->palette2);
            ReleaseObjTiles(node->tiles);
            ReleaseObjPalette(node->palette);
            ReleaseObjTiles(node->tiles2);
            node->flags &= ~1;
            node->tiles = 0;
            node->palette = 0;
            node->tiles2 = 0;
            node->palette2 = 0;
        }

        if (x > 2) {
            x = 0;
            y++;
        }

        node = ListPoolNext(&node->node);
    }

    *(s32*)&work[0x854] = 0x2800;
    *(u16*)&work[0x8AC] = 4;
#endif
}

s32 func_0808E890(u8* work) {
    DeckCard2Work* t;

    t = ListPoolFirst(&work[CARDWORK(0x7F0)]);

    while (t != 0) {
        if (t->unk_22 == *(s16*)&work[CARDWORK(0x884)]) {
            if (t->unk_24 == *(s16*)&work[CARDWORK(0x886)]) {
                return 1;
            }
        }

        t = ListPoolNext(&t->node);
    }

    return 0;
}

u8 func_0808E8E8(u8* work, u16 a, u16 b) {
    DeckCard2Work* node;

    node = ListPoolFirst(&work[CARDWORK(0x7F0)]);

    while (node != 0) {
        if (node->unk_22 == (s16)a && node->unk_24 == (s16)b) {
            return 1;
        }

        node = ListPoolNext(&node->node);
    }

    return 0;
}

u8 func_0808E934(u8* work, s16 x, s16 y, u16 dir) {
    DeckCard2Work* node;

    node = ListPoolFirst(&work[CARDWORK(0x7F0)]);

    while (node != 0) {
        if (node->unk_22 == x && node->unk_24 == y) {
            return 1;
        }

        node = ListPoolNext(&node->node);
    }

    switch (dir) {
    case 0x40:
        return func_0808E934(work, x, y - 1, 0x40);
    case 0x80:
        return func_0808E934(work, x, y + 1, 0x80);
    case 0x20:
        return func_0808E934(work, x - 1, y, 0x20);
    case 0x10:
        return func_0808E934(work, x + 1, y, 0x10);
    }

    return 0;
}

void func_0808EA0C(UnkStruct_0808DB04* w, u8 kind) {
    UnkStruct_080A97D4 args;
    u16* deck;
    u8 i;
    s8 x;
    s8 y;

    deck = (u16*)GetDeck(w->unk_8C0);
    x = 0;
    y = 4 - w->unk_8AC;

    if (kind == 0) {
        for (i = 0; i < 99; i++) {
            if (deck[i] != 0xFFFF) {
                if (kind == 0) {
                    args.unk_00 = &w->pool;
                    args.cardId = gCardCollection[deck[i]] & 0x8FFF;
                    args.unk_06 = x;
                    args.unk_08 = y;
                    args.unk_0A = 0;
                    args.unk_0C = &deck[i];
                    TaskCreate(&w->tasks, &gTaskDescDeckCard2, &args);
                } else if (gCardDefs[gCardCollection[deck[i]] & 0xFFF].unk_2A == kind - 1) {
                    args.unk_00 = &w->pool;
                    args.cardId = gCardCollection[deck[i]] & 0x8FFF;
                    args.unk_06 = x;
                    args.unk_08 = y;
                    args.unk_0A = 0;
                    args.unk_0C = &deck[i];
                    TaskCreate(&w->tasks, &gTaskDescDeckCard2, &args);
                }
            } else {
                args.unk_00 = &w->pool;
                args.cardId = 0xFFFF;
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 0;
                args.unk_0C = &deck[i];
                TaskCreate(&w->tasks, &gTaskDescDeckCard2, &args);
            }

            x++;

            if (x > 2) {
                x = 0;
                y++;
            }
        }
    } else {
        for (i = 0; i < 99; i++) {
            if (deck[i] != 0xFFFF && gCardDefs[gCardCollection[deck[i]] & 0xFFF].unk_2A == kind - 1) {
                args.unk_00 = &w->pool;
                args.cardId = gCardCollection[deck[i]] & 0x8FFF;
                args.unk_06 = x;
                args.unk_08 = y;
                args.unk_0A = 0;
                args.unk_0C = &deck[i];
                TaskCreate(&w->tasks, &gTaskDescDeckCard2, &args);
                x++;
            }

            if (x > 2) {
                x = 0;
                y++;
            }
        }
    }
}
u8 func_0808EC24(UnkStruct_0808DB04* w) {
    DeckCard2Work* p;
    DeckCard2Work* q;
    DeckCard2Work* last;
    DeckCard2Work* n;

    p = ListPoolFirst(&w->pool);
    last = ListPoolLast(&w->pool);
    q = 0;

    while (p != 0) {
        if (w->unk_884 == p->unk_22 && (s16)w->unk_886 == p->unk_24) {
            q = p;
            break;
        }

        p = ListPoolNext(&p->node);
    }

    if (p->cardId != 0xFFFF) {
        while (q != 0) {
            if (q->cardId == 0xFFFF) {
                break;
            }

            q = ListPoolNext(&q->node);
        }

        if (q != 0) {
            while (p != q) {
                n = (DeckCard2Work*)ListPoolPrev(&q->node);

                if (n != 0) {
                    *(u16*)q->unk_28 = *(u16*)n->unk_28;
                }

                q = (DeckCard2Work*)ListPoolPrev(&q->node);
            }

            *(u16*)p->unk_28 = 0xFFFF;
            func_0808C90C((u8*)w);
            TaskPoolUpdate(&w->tasks);
            func_0808EA0C(w, w->unk_8C1);
            w->unk_884++;

            if (w->unk_884 > 2) {
                w->unk_884 = 0;

                if ((s16)w->unk_886 <= 2) {
                    w->unk_886++;
                } else {
                    func_0808C9CC((u8*)w);
                }
            }

            w->unk_8B7 = 1;
            return 1;
        }
    } else {
        while (p != 0) {
            n = ListPoolNext(&p->node);

            if (n != 0) {
                *(u16*)p->unk_28 = *(u16*)n->unk_28;
            }

            p = ListPoolNext(&p->node);
        }

        *(u16*)last->unk_28 = 0xFFFF;
        func_0808C90C((u8*)w);
        TaskPoolUpdate(&w->tasks);
        func_0808EA0C(w, w->unk_8C1);
        return 1;
    }

    return 0;
}
u8 func_0808EDA4(UnkStruct_0808DB04* w) {
    DeckCard2Work* p;
    DeckCard2Work* q;
    DeckCard2Work* n;
    DeckCard2Work* prev;
    u16* a;
    u16* b;
    s16 x;
    s16 y;
    u16 u;
    u16 v;
    s32 pos;

    p = ListPoolFirst(&w->pool);
    q = ListPoolFirst(&w->pool);
    pos = *(s32*)&w->unk_884;

    if (pos == *(s32*)&w->unk_874) {
        return func_0808EC24(w);
    }

    while (p != 0) {
        if (w->unk_884 == p->unk_22 && (s16)w->unk_886 == p->unk_24) {
            break;
        }

        p = ListPoolNext(&p->node);
    }

    if (p == 0) {
        return 0;
    }

    while (q != 0) {
        if (w->unk_874 == q->unk_22 && w->unk_876 == q->unk_24) {
            break;
        }

        q = ListPoolNext(&q->node);
    }

    x = p->unk_22;
    y = p->unk_24;
    p->unk_22 = q->unk_22;
    p->unk_24 = q->unk_24;
    q->unk_22 = x;
    q->unk_24 = y;
    a = p->unk_28;
    u = *a;
    b = q->unk_28;
    v = *b;
    *a = v;
    *b = u;
    p->unk_28 = b;
    q->unk_28 = a;

    if (ListPoolPrev(&p->node) == (MapcardWork*)q) {
        ListPoolRemove(&p->node, &w->pool);
        ListPoolInsertBefore(&p->node, &w->pool, &q->node);

        for (n = ListPoolFirst(&w->pool); n != 0; n = ListPoolNext(&n->node)) {
            if (n == ListPoolNext(&n->node)) {
                break;
            }
        }
    } else if (ListPoolNext(&p->node) == q) {
        ListPoolRemove(&p->node, &w->pool);
        ListPoolInsertAfter(&p->node, &w->pool, &q->node);

        for (n = ListPoolFirst(&w->pool); n != 0; n = ListPoolNext(&n->node)) {
            if (n == ListPoolNext(&n->node)) {
                break;
            }
        }
    } else {
        prev = (DeckCard2Work*)ListPoolRemove(&p->node, &w->pool);
        ListPoolInsertBefore(&p->node, &w->pool, &q->node);
        ListPoolRemove(&q->node, &w->pool);

        if (prev == 0) {
            ListPoolAppend(&q->node, &w->pool);
        } else {
            ListPoolInsertBefore(&q->node, &w->pool, &prev->node);
        }
    }

    return 1;
}

u8 func_0808EF80(u8* work, u16 dir) {
    u16 row;
    u16 row2;

    row = *(u16*)&work[0x7C2];

    if ((s16)row == 3 && *(u16*)&work[0x7C0] > 9) {
        switch (dir) {
        case 0x40:
            *(u16*)&work[0x7C2] = row - 1;
            break;
        case 0x80:
            *(u16*)&work[0x7C2] = row + 1;
            break;
        case 0x20:
            *(u16*)&work[0x7C0] = 9;
            break;
        case 0x10:
            *(u16*)&work[0x7C0] = 0;
            break;
        }
    }

    if (work[0x7C7] == 0) {
        row2 = *(u16*)&work[0x7C2];

        if ((s16)row2 == 5 && (u16)(*(u16*)&work[0x7C0] - 5) <= 4) {
            switch (dir) {
            case 0x40:
                *(u16*)&work[0x7C2] = row2 - 1;
                break;
            case 0x80:
                *(u16*)&work[0x7C2] = row2 + 1;
                break;
            case 0x20:
                *(u16*)&work[0x7C0] = 4;
                break;
            case 0x10:
                *(u16*)&work[0x7C0] = 10;
                break;
            }
        }
    }

    if (*(s16*)&work[0x7C2] > 6) {
        *(s16*)&work[0x7C2] = 0;
    }

    if (*(s16*)&work[0x7C2] < 0) {
        *(s16*)&work[0x7C2] = 6;
    }

    if (*(s16*)&work[0x7C0] > 14) {
        *(s16*)&work[0x7C0] = 0;
    }

    if (*(s16*)&work[0x7C0] < 0) {
        *(s16*)&work[0x7C0] = 14;
    }

    if (*(s16*)&work[0x7C2] == 6 && *(s16*)&work[0x7C0] > 11) {
        if (*(s16*)&work[0x7C0] == 13 && dir == 0x20) {
            *(s16*)&work[0x7C0] = 11;
            AnimStart(&work[0x798], 0, 1);
        } else {
            *(s16*)&work[0x7C0] = 14;
            AnimStart(&work[0x798], 1, 1);
        }

        return 0;
    }

    return 1;
}

extern UnkStruct_09035898 gUnk_09035898[];
extern UnkStruct_09035898 gUnk_090358D0[];

u8 func_0808F0C0(UnkStruct_0808F0C0* w, u16 keys) {
    if (w->cursor.parts.y == 1 && (u16)w->cursor.parts.x > 10) {
        switch (keys) {
        case 64:
            w->cursor.parts.y--;
            break;
        case 128:
            w->cursor.parts.y++;
            break;
        case 32:
            w->cursor.parts.x = 10;
            break;
        case 16:
            w->cursor.parts.x = 0;
            break;
        }
    }
    if (w->cursor.parts.y == 3 && (u16)w->cursor.parts.x > 10) {
        switch (keys) {
        case 64:
            w->cursor.parts.y--;
            break;
        case 128:
            w->cursor.parts.y++;
            break;
        case 32:
            w->cursor.parts.x = 10;
            break;
        case 16:
            w->cursor.parts.x = 0;
            break;
        }
    }
#if defined(VERSION_JP) || defined(VERSION_EU)
#ifdef VERSION_JP
    if (w->cursor.parts.y == 4 && (u16)w->cursor.parts.x > 9) {
#else
    if (w->cursor.parts.y == 5 && (u16)w->cursor.parts.x > 9) {
#endif
        switch (keys) {
        case 64:
#ifdef VERSION_JP
            w->cursor.parts.y -= 2;
#else
            w->cursor.parts.y--;
#endif
            break;
        case 128:
            w->cursor.parts.y++;
            break;
        case 32:
            w->cursor.parts.x = 9;
            break;
        case 16:
            w->cursor.parts.x = 0;
            break;
        }
    }
#endif
    if (w->cursor.parts.x > 14) {
        w->cursor.parts.x = 0;
    }
    if (w->cursor.parts.x < 0) {
        w->cursor.parts.x = 14;
    }
#ifdef VERSION_EU
    if (w->cursor.parts.y > 7) {
#else
    if (w->cursor.parts.y > 6) {
#endif
        w->cursor.parts.y = 0;
    }
    if (w->cursor.parts.y < 0) {
#ifdef VERSION_EU
        w->cursor.parts.y = 7;
#else
        w->cursor.parts.y = 6;
#endif
    }
#ifndef VERSION_JP
    if (w->cursor.parts.x > gUnk_09035898[w->cursor.parts.y].unk_04 - 1) {
        w->cursor.parts.x = 0;
    }
    if (w->cursor.parts.x < 0) {
        w->cursor.parts.x = gUnk_09035898[w->cursor.parts.y].unk_04 - 1;
    }
    if (w->cursor.parts.y > gUnk_090358D0[w->cursor.parts.x].unk_04 - 1) {
        w->cursor.parts.y = 0;
    }
    if (w->cursor.parts.y < 0) {
        w->cursor.parts.y = gUnk_090358D0[w->cursor.parts.x].unk_04 - 1;
    }
#endif
#ifdef VERSION_EU
    if (w->cursor.parts.y == 7 && w->cursor.parts.x > 9) {
#else
    if (w->cursor.parts.y == 6 && w->cursor.parts.x > 9) {
#endif
        if (w->cursor.parts.x == 13 && keys == 32) {
            w->cursor.parts.x = 9;
            AnimStart(&w->anim, 0, 1);
#ifdef VERSION_EU
            w->unk_7C8 = 0;
#endif
        } else {
            w->cursor.parts.x = 14;
            AnimStart(&w->anim, 1, 1);
#ifdef VERSION_EU
            w->unk_7C8 = 1;
#endif
        }
        return 0;
    }
    return 1;
}
#ifdef VERSION_EU
extern UnkStruct_09035898 gUnkEu_090CEC30[];
extern UnkStruct_09035898 gUnkEu_090CEC70[];
u8 func_eu_0808E94C(UnkStruct_0808F0C0* w, u16 keys) {
    if (w->cursor.parts.y == 1 && (u16)w->cursor.parts.x > 5) {
        switch (keys) {
        case 64:
            w->cursor.parts.y--;
            break;
        case 128:
            w->cursor.parts.y++;
            break;
        case 32:
            w->cursor.parts.x = 5;
            break;
        case 16:
            w->cursor.parts.x = 0;
            break;
        }
    }
    if (w->cursor.parts.y == 4 && (u16)w->cursor.parts.x > 2) {
        switch (keys) {
        case 64:
            w->cursor.parts.y--;
            break;
        case 128:
            w->cursor.parts.y++;
            break;
        case 32:
            w->cursor.parts.x = 2;
            break;
        case 16:
            w->cursor.parts.x = 0;
            break;
        }
    }
    if (w->cursor.parts.x > 14) {
        w->cursor.parts.x = 0;
    }
    if (w->cursor.parts.x < 0) {
        w->cursor.parts.x = 14;
    }
    if (w->cursor.parts.y > 6) {
        w->cursor.parts.y = 0;
    }
    if (w->cursor.parts.y < 0) {
        w->cursor.parts.y = 6;
    }
    if (w->cursor.parts.x > gUnkEu_090CEC30[w->cursor.parts.y].unk_04 - 1) {
        w->cursor.parts.x = 0;
    }
    if (w->cursor.parts.x < 0) {
        w->cursor.parts.x = gUnkEu_090CEC30[w->cursor.parts.y].unk_04 - 1;
    }
    if (w->cursor.parts.y > gUnkEu_090CEC70[w->cursor.parts.x].unk_04 - 1) {
        w->cursor.parts.y = 0;
    }
    if (w->cursor.parts.y < 0) {
        w->cursor.parts.y = gUnkEu_090CEC70[w->cursor.parts.x].unk_04 - 1;
    }
    if (w->cursor.parts.y == 6 && w->cursor.parts.x > 1) {
        if (w->cursor.parts.x == 13 && keys == 32) {
            w->cursor.parts.x = 1;
            AnimStart(&w->anim, 0, 1);
            w->unk_7C8 = 0;
        } else {
            w->cursor.parts.x = 14;
            AnimStart(&w->anim, 1, 1);
            w->unk_7C8 = 1;
        }
        return 0;
    }
    return 1;
}
#endif
void func_0808F258(u8 a) {
    u32 base;

    base = GetBgCharBase(3);
    RequestDma3Copy(&gUnk_09417378[a * 64], (void*)(base + 32), 64);
}
void func_0808F284(u8* work) {
    u8* s;
    u8* d;
    s32 i;

#ifdef VERSION_EU
    s = GetDeckName(work[0x8C4]);
#else
    s = GetDeckName(work[0x8C0]);
#endif

    for (i = 0; i <= 19; i++) {
        d = &work[0x784];
        d[i] = s[i];
    }

    work[0x796] = 0;
    work[0x797] = 0;
}
void func_0808F2CC(u8* work) {
    u8* d;
    u8* s;
    s32 i;

    d = GetDeckName(work[CARDWORK(0x8C0)]);

    for (i = 0; i <= 19; i++) {
        s = &work[0x784];
        d[i] = s[i];
    }

    d[18] = 0;
    d[19] = 0;
}

void func_0808F304(u8* work) {
    u8* p;
    s32 t;
    u8 i;

    if (work[0x7C4] == 0) {
        m4aSongNumStart(SONG_SYS_BEEP);
        return;
    }

#ifdef VERSION_EU
    for (i = work[0x7C4] - 1; i <= 19; i++) {
        p = &work[0x784];
        p[i] = 0;
    }
#else
    for (i = work[0x7C4] - 1; i <= 8; i++) {
        p = &work[0x784];
        t = i * 2;
        p[t] = 0;
        t++;
        p[t] = 0;
    }
#endif

    m4aSongNumStart(SONG_SYS_CLOSE);
}

s32 func_0808F358(UnkStruct_0808F358* work) {
    const u8* src = NULL;
    u8* dst;
    s32 offset;
    s32 zero;
    s32 offset2;
    u8 value;
    u8* out;

    if (work->unk_7C4 <= 7) {
        m4aSongNumStart(SONG_SYS_KETTEI);
#ifdef VERSION_EU
        if (work->unk_7C7 == 2) {
            src = gUnkEu_09F6FE6C[work->unk_7C2];
        } else {
            src = gUnkEu_09F6FE8C[work->unk_7C2];
        }
#else
#ifdef VERSION_JP
        switch (work->unk_7C7) {
        case 0:
            src = gUnk_09EE4B0C[work->unk_7C2];
            break;
        case 1:
            src = gUnkJp_09EBC148[work->unk_7C2];
            break;
        case 2:
            src = gUnkJp_09EBC164[work->unk_7C2];
            break;
        }
#else
        src = gUnk_09EE4B0C[work->unk_7C2];
#endif
#endif
#ifdef VERSION_EU
        offset = work->unk_7C4;
        dst = work->unk_784;
        out = &dst[offset];
        value = src[work->unk_7C0];
        zero = 0;
        *out = value;
        offset2 = work->unk_7C4 + 1;
        dst[offset2] = zero;
#else
        offset = work->unk_7C4 * 2;
        dst = work->unk_784;
        out = &dst[offset];
        value = src[work->unk_7C0 * 2];
        zero = 0;
        *out = value;
        offset2 = work->unk_7C4 * 2;
        offset2++;
        dst[offset2] = src[work->unk_7C0 * 2 + 1];
        offset = (work->unk_7C4 + 1) * 2;
        dst[offset] = zero;
        offset = (work->unk_7C4 + 1) * 2;
        offset++;
        dst[offset] = zero;
#endif
        return 1;
    } else {
        m4aSongNumStart(SONG_SYS_BEEP);
        return 0;
    }
}
#ifdef VERSION_JP
void func_jp_0808F240(UnkStruct_0808F0C0* w) {
    switch (w->unk_7C7) {
    case 0:
        if (w->cursor.parts.y == 5 && (u16)(w->cursor.parts.x - 5) <= 4) {
            w->cursor.parts.x = 4;
        }
        break;
    case 1:
        switch (w->cursor.parts.y) {
        case 0:
        case 1:
        case 2:
            break;
        case 3:
            if (w->cursor.parts.x > 9) {
                w->cursor.parts.x = 9;
            }
            break;
        case 4:
        case 5:
        case 6:
            break;
        }
        break;
    case 2:
        switch (w->cursor.parts.y) {
        case 0:
            break;
        case 1:
            if (w->cursor.parts.x > 10) {
                w->cursor.parts.x = 10;
            }
            break;
        case 2:
        case 3:
            break;
        case 4:
            if (w->cursor.parts.x > 9) {
                w->cursor.parts.x = 9;
            }
            break;
        case 5:
            break;
        case 6:
            if (w->cursor.parts.x >= 10 && w->cursor.parts.x <= 13) {
                w->cursor.parts.x = 9;
            }
            break;
        }
        break;
    }
}
void func_jp_0808F240(UnkStruct_0808F0C0* w);
extern u8 gUnkJp_094D4594[];
extern u8 gUnkJp_094D4D94[];
void func_jp_0808F34C(UnkStruct_0808F0C0* w) {
    switch (w->unk_7C7) {
    case 0:
        LoadBgMap(3, gUnk_0951C2B8, 0x800);
        break;
    case 1:
        LoadBgMap(3, gUnkJp_094D4594, 0x800);
        break;
    case 2:
        LoadBgMap(3, gUnkJp_094D4D94, 0x800);
        break;
    }
    func_jp_0808F240(w);
}
#endif
#ifdef VERSION_EU
void func_eu_0808EC78(UnkStruct_0808F0C0* w) {
    switch (w->unk_7C7) {
    case 2:
        switch (w->cursor.parts.y) {
        case 0:
            break;
        case 1:
        case 3:
            if (w->cursor.parts.x > 10) {
                w->cursor.parts.x = 10;
            }
            break;
        case 2:
        case 4:
            break;
        case 5:
            if (w->cursor.parts.x > 9) {
                w->cursor.parts.x = 9;
            }
            break;
        case 6:
            if (w->unk_7C8 == 1) {
                w->cursor.parts.x = 14;
                w->cursor.parts.y = 7;
            }
            break;
        case 7:
            if (w->cursor.parts.x >= 10 && w->cursor.parts.x <= 13) {
                w->cursor.parts.x = 9;
            }
            break;
        }
        break;
    case 3:
        switch (w->cursor.parts.y) {
        case 0:
            break;
        case 1:
            if (w->cursor.parts.x > 5) {
                w->cursor.parts.x = 5;
            }
            break;
        case 2:
        case 3:
            break;
        case 4:
            if (w->cursor.parts.x > 2) {
                w->cursor.parts.x = 2;
            }
            break;
        case 5:
            break;
        case 6:
            if (w->unk_7C8 == 1) {
                w->cursor.parts.y = 6;
                w->cursor.parts.x = 14;
            } else if (w->cursor.parts.x > 1) {
                w->cursor.parts.x = 1;
            }
            break;
        case 7:
            if (w->cursor.parts.x == 14) {
                w->cursor.parts.y = 6;
            } else {
                w->cursor.parts.y = 6;
                w->cursor.parts.x = 0;
            }
            break;
        }
        break;
    }
}
void func_eu_0808EC78(UnkStruct_0808F0C0* w);
extern u8 gUnkEu_0953C324[];
void func_eu_0808EE08(UnkStruct_0808F0C0* w) {
    switch (w->unk_7C7) {
    case 2:
        LoadBgMap(3, gUnk_0951C2B8, 0x800);
        break;
    case 3:
        LoadBgMap(3, gUnkEu_0953C324, 0x800);
        break;
    }
    func_eu_0808EC78(w);
}
#endif
extern u8 gUnk_096145B8[];
extern u8 gUnk_090A5F1E[];
extern u8 gUnk_09614518[];
extern s16 gUnk_09035808[];
extern s16 gUnk_09035874[];
#ifdef VERSION_JP
extern u8 gUnkJp_093D1694[];
#endif
#ifdef VERSION_EU
extern void* gUnkEu_09F6FE30[];
extern void* gUnkEu_09F6FE58[];
extern void** gUnkEu_09F6FE44[];
extern u8 gUnkEu_094F03A4[];
extern u8 gUnkEu_094F1BA4[];
extern u8 gUnkEu_094F13A4[];
extern u8 gUnkEu_094F0BA4[];
#endif
u8 func_0808F3E8(UnkStruct_0808F0C0* w, void* a) {
    FadeStartIn(0, 16);
#ifdef VERSION_EU
    w->unk_8B0 = 0;
    w->unk_7C8 = 0;
#endif
    switch (w->unk_8D0) {
    case 0:
        w->unk_8B1 = 13;
        func_0808CD48(w);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
#ifdef VERSION_EU
        w->tiles = AllocObjTiles(0x400, 0);
#else
        w->tiles = AllocObjTiles(0x200, 0);
#endif
        w->palette = LoadObjPalette(gUnk_096145B8, 32);
        w->tiles2 = AllocSpriteFrameTiles(0x80);
#ifdef VERSION_EU
        SetObjTileSource(w->tiles, gUnkEu_09F6FE30[gLanguage]);
        AnimInit(&w->anim, gUnkEu_09F6FE58[gLanguage], gUnkEu_09F6FE44[gLanguage]);
#else
        SetObjTileSource(w->tiles, gUnk_090A5F1E);
        AnimInit(&w->anim, gUnk_09EEB0B8, gUnk_09EEB08C);
#endif
        AnimStart(&w->anim, 0, 1);
        w->gfx = AnimGetGfx(&w->anim);
#ifdef VERSION_EU
        UpdateSpriteFrameTiles(w->tiles2, gUnkEu_09F6FE44[gLanguage][10], gUnkEu_09F6FE30[gLanguage]);
#else
        UpdateSpriteFrameTiles(w->tiles2, gUnk_09EEB08C[10], gUnk_090A5F1E);
#endif
        FreeTextSlots(w->textSlots, 8);
        FreeTextSlots(w->textSlots2, 8);
        FreeTextSlots(w->textSlots3, 8);
        FreeTextSlots(w->textSlots4, 30);
        FreeTextSlots(w->unk_1E8, 90);
        InitTextSlots(w->textSlots6, 8);
        func_0808F284((u8*)w);
        w->textSlotCount6 = LoadTextSlots(w->unk_784, w->textSlots6);
        w->unk_7BC = ((s16)GetTextSlotsWidth((TextSlot*)w->textSlots6, w->textSlotCount6) << 8) + 0x8300;
        break;
    case 1:
#ifdef VERSION_JP
        LoadBgTiles(3, gUnk_09417438, 0x2000);
#else
        LoadBgTiles(3, gUnk_09417438, 0x1000);
#endif
        break;
    case 2:
#ifdef VERSION_JP
        RequestDma3Copy(gUnk_09418438, (u8*)GetBgCharBase(3) + 0x2000, 0x2000);
#else
        RequestDma3Copy(gUnk_09418438, (u8*)GetBgCharBase(3) + 0x1000, 0x1000);
#endif
        break;
    case 3:
#ifdef VERSION_JP
        RequestDma3Copy(gUnk_09419438, (u8*)GetBgCharBase(3) + 0x4000, 0x2000);
#elif defined(VERSION_EU)
        RequestDma3Copy(gUnk_09419438, (u8*)GetBgCharBase(3) + 0x2000, 0x2E40);
#else
        RequestDma3Copy(gUnk_09419438, (u8*)GetBgCharBase(3) + 0x2000, 0xFE0);
#endif
        break;
    case 4:
#ifdef VERSION_JP
        RequestDma3Copy(gUnkJp_093D1694, (u8*)GetBgCharBase(3) + 0x6000, 0x1000);
#elif defined(VERSION_EU)
        switch (gLanguage) {
        case 0:
            break;
        case 1:
            RequestDma3Copy(gUnkEu_094F03A4, (u8*)GetBgCharBase(3) + 0x4800, 0x800);
            break;
        case 2:
            RequestDma3Copy(gUnkEu_094F1BA4, (u8*)GetBgCharBase(3) + 0x4800, 0x800);
            break;
        case 3:
            RequestDma3Copy(gUnkEu_094F13A4, (u8*)GetBgCharBase(3) + 0x4800, 0x800);
            break;
        case 4:
            RequestDma3Copy(gUnkEu_094F0BA4, (u8*)GetBgCharBase(3) + 0x4800, 0x800);
            break;
        }
#endif
        break;
    case 5:
        LoadBgMap(3, gUnk_0951C2B8, 0x800);
        LoadBgPalette(3, gUnk_09614518, 0xA0);
        break;
    case 6:
        SetTaskUpdate(a, (TaskUpdateFunc)func_0808F660);
        w->x = gUnk_09035808[0] << 8;
        w->y = gUnk_09035874[0] << 8;
        w->unk_7C6 = 4;
        w->cursor.parts.x = 0;
        w->cursor.parts.y = 0;
#ifdef VERSION_JP
        w->unk_7C7 = 0;
#else
        w->unk_7C7 = 2;
#endif
        func_0808F258(w->unk_8C0);
        break;
    }
    w->unk_8D0++;
    TaskPoolUpdate(&w->taskpool);
    TaskPoolUpdate(&w->cardpool);
    return 1;
}
#ifdef VERSION_JP
void func_jp_0808F34C(UnkStruct_0808F0C0* w);
extern s16 gUnkJp_09008DEC[];
u8 func_jp_0808F638(UnkStruct_0808F0C0* w, void* a) {
    switch ((u16)GetKeysRepeat()) {
    case DPAD_RIGHT:
        if (w->unk_7C7 <= 1) {
            w->unk_7C7++;
            func_jp_0808F34C(w);
            m4aSongNumStart(SONG_SYS_CANSEL);
            w->unk_7C6 = 1;
        }
        break;
    case DPAD_LEFT:
        if (w->unk_7C7 != 0) {
            w->unk_7C7--;
            func_jp_0808F34C(w);
            m4aSongNumStart(SONG_SYS_CANSEL);
            w->unk_7C6 = 1;
        }
        break;
    case SELECT_BUTTON:
    case DPAD_DOWN:
        w->unk_7C6 = 1;
        SetTaskUpdate(a, (TaskUpdateFunc)func_0808F660);
        w->unk_8B1 = 13;
        m4aSongNumStart(SONG_SYS_CLICKI04B);
        return 1;
    }
    ApproachValueHalf(&w->x2, (gUnkJp_09008DEC[w->unk_7C7] + 8) << 8);
    ApproachValueHalf(&w->y2, 0x1A00);
    w->gfx = AnimUpdate(&w->anim);
    *(void**)&w->unk_1E8[0x308] = AnimUpdate(&w->anim2);
    TaskPoolUpdate(&w->taskpool);
    TaskPoolUpdate(&w->cardpool);
    return 1;
}
#elif defined(VERSION_EU)
extern s16 gUnkEu_090CECE8[];
u8 func_eu_0808F190(UnkStruct_0808F0C0* w, void* a) {
    u8* mode = &w->unk_7C7;

    w->unk_8B0 = 1;
    switch ((u16)GetKeysRepeat()) {
    case DPAD_RIGHT:
        w->unk_7C6 = 1;
        if (*mode <= 2) {
            (*mode)++;
            func_eu_0808EE08(w);
            m4aSongNumStart(SONG_SYS_CANSEL);
            w->unk_7C6 = 1;
        }
        break;
    case DPAD_LEFT:
        w->unk_7C6 = 1;
        if (*mode > 2) {
            (*mode)--;
            func_eu_0808EE08(w);
            m4aSongNumStart(SONG_SYS_CANSEL);
            w->unk_7C6 = 1;
        }
        break;
    case SELECT_BUTTON:
    case DPAD_DOWN:
        w->unk_7C6 = 1;
        SetTaskUpdate(a, (TaskUpdateFunc)func_0808F660);
        w->unk_8B1 = 13;
        m4aSongNumStart(SONG_SYS_CLICKI04B);
        w->unk_8B0 = 0;
        return 1;
    }
    if (w->unk_7C6 != 0) {
        if (w->unk_7C8 == 1) {
            if (gLanguage == 2) {
                w->x = 0xC800;
            } else if (gLanguage == 3) {
                w->x = 0xD100;
            } else {
                w->x = 0xD300;
            }
            w->y = 0x8C00;
        } else if (w->unk_7C7 == 2) {
            ApproachValue(&w->x, gUnk_09035898[w->cursor.parts.y].unk_00[w->cursor.parts.x] << 8, w->unk_7C6);
            ApproachValue(&w->y, gUnk_090358D0[w->cursor.parts.x].unk_00[w->cursor.parts.y] << 8, w->unk_7C6);
        } else {
            ApproachValue(&w->x, gUnkEu_090CEC30[w->cursor.parts.y].unk_00[w->cursor.parts.x] << 8, w->unk_7C6);
            ApproachValue(&w->y, gUnkEu_090CEC70[w->cursor.parts.x].unk_00[w->cursor.parts.y] << 8, w->unk_7C6);
        }
        w->unk_7C6--;
    }
    ApproachValueHalf(&w->x2, (gUnkEu_090CECE8[w->unk_7C7 - 2] + 8) << 8);
    ApproachValueHalf(&w->y2, 0x1A00);
    w->gfx = AnimUpdate(&w->anim);
    *(void**)&w->unk_1E8[0x308] = AnimUpdate(&w->anim2);
    TaskPoolUpdate(&w->taskpool);
    TaskPoolUpdate(&w->cardpool);
    return 1;
}
#endif
u8 func_0808F660(UnkStruct_0808F0C0* w, void* a) {
#ifdef VERSION_EU
    u8 mode = w->unk_7C7;
    s32 bottom = 6;
    if (mode == 2) {
        bottom = 7;
    }
#endif
    w->gfx = AnimUpdate(&w->anim);
    *(void**)&w->unk_1E8[0x308] = AnimUpdate(&w->anim2);
    switch ((u16)GetKeysRepeat()) {
    case DPAD_LEFT:
        w->unk_7C6 = 1;
        w->cursor.parts.x--;
        switch (w->unk_7C7) {
        case 0:
        case 1:
            if ((u8)func_0808EF80((u8*)w, 32) != 0) {
                AnimStart(&w->anim, 0, 1);
            }
            break;
        case 2:
            if ((u8)func_0808F0C0(w, 32) != 0) {
                AnimStart(&w->anim, 0, 1);
#ifdef VERSION_EU
                w->unk_7C8 = 0;
#endif
            }
            break;
#ifdef VERSION_EU
        case 3:
            if ((u8)func_eu_0808E94C(w, 32) != 0) {
                AnimStart(&w->anim, 0, 1);
                w->unk_7C8 = 0;
            }
            break;
#endif
        }
        m4aSongNumStart(SONG_SYS_CLICKI04B);
        break;
    case DPAD_RIGHT:
        w->unk_7C6 = 1;
        w->cursor.parts.x++;
        switch (w->unk_7C7) {
        case 0:
        case 1:
            if ((u8)func_0808EF80((u8*)w, 16) != 0) {
                AnimStart(&w->anim, 0, 1);
            }
            break;
        case 2:
            if ((u8)func_0808F0C0(w, 16) != 0) {
                AnimStart(&w->anim, 0, 1);
#ifdef VERSION_EU
                w->unk_7C8 = 0;
#endif
            }
            break;
#ifdef VERSION_EU
        case 3:
            if ((u8)func_eu_0808E94C(w, 16) != 0) {
                AnimStart(&w->anim, 0, 1);
                w->unk_7C8 = 0;
            }
            break;
#endif
        }
        m4aSongNumStart(SONG_SYS_CLICKI04B);
        break;
    case DPAD_UP:
        w->unk_7C6 = 1;
        w->cursor.parts.y--;
#if defined(VERSION_JP) || defined(VERSION_EU)
        if (w->cursor.parts.y < 0) {
            w->unk_7C6 = 1;
            w->cursor.parts.y = 0;
#ifdef VERSION_JP
            SetTaskUpdate(a, (TaskUpdateFunc)func_jp_0808F638);
#else
            SetTaskUpdate(a, (TaskUpdateFunc)func_eu_0808F190);
#endif
            m4aSongNumStart(SONG_SYS_CLICKI04B);
            return 1;
        }
#endif
        switch (w->unk_7C7) {
        case 0:
        case 1:
            if ((u8)func_0808EF80((u8*)w, 64) != 0) {
                AnimStart(&w->anim, 0, 1);
            }
            break;
        case 2:
            if ((u8)func_0808F0C0(w, 64) != 0) {
                AnimStart(&w->anim, 0, 1);
#ifdef VERSION_EU
                w->unk_7C8 = 0;
#endif
            }
            break;
#ifdef VERSION_EU
        case 3:
            if ((u8)func_eu_0808E94C(w, 64) != 0) {
                AnimStart(&w->anim, 0, 1);
                w->unk_7C8 = 0;
            }
            break;
#endif
        }
        m4aSongNumStart(SONG_SYS_CLICKI04B);
        break;
    case DPAD_DOWN:
        w->unk_7C6 = 1;
        w->cursor.parts.y++;
        switch (w->unk_7C7) {
        case 0:
        case 1:
            if ((u8)func_0808EF80((u8*)w, 128) != 0) {
                AnimStart(&w->anim, 0, 1);
            }
            break;
        case 2:
            if ((u8)func_0808F0C0(w, 128) != 0) {
                AnimStart(&w->anim, 0, 1);
#ifdef VERSION_EU
                w->unk_7C8 = 0;
#endif
            }
            break;
#ifdef VERSION_EU
        case 3:
            if ((u8)func_eu_0808E94C(w, 128) != 0) {
                AnimStart(&w->anim, 0, 1);
                w->unk_7C8 = 0;
            }
            break;
#endif
        }
        m4aSongNumStart(SONG_SYS_CLICKI04B);
        break;
    }
    switch ((u16)GetKeysPressed()) {
    case B_BUTTON:
        func_0808F304((u8*)w);
        w->textSlotCount6 = LoadTextSlots(w->unk_784, w->textSlots6);
        w->unk_7BC = ((s16)GetTextSlotsWidth((TextSlot*)w->textSlots6, w->textSlotCount6) << 8) + 0x8300;
        break;
    case A_BUTTON:
#ifdef VERSION_EU
        if (w->cursor.parts.x == 14 && w->cursor.parts.y == bottom) {
#else
        if (w->cursor.packed == 0x6000E) {
#endif
            func_0808F2CC((u8*)w);
            SetTaskUpdate(a, (TaskUpdateFunc)func_0808FA0C);
            m4aSongNumStart(SONG_SYS_KETTEI);
            FadeStartIn(0, 16);
        } else {
            if ((u8)func_0808F358((UnkStruct_0808F358*)w) != 0) {
                w->textSlotCount6 = LoadTextSlots(w->unk_784, w->textSlots6);
                w->unk_7BC = ((s16)GetTextSlotsWidth((TextSlot*)w->textSlots6, w->textSlotCount6) << 8) + 0x8300;
            } else {
                w->cursor.parts.x = 14;
#ifdef VERSION_EU
                w->cursor.parts.y = bottom;
#else
                w->cursor.parts.y = 6;
#endif
                AnimStart(&w->anim, 1, 1);
#ifdef VERSION_EU
                w->unk_7C8 = 1;
#endif
            }
        }
        break;
    case START_BUTTON:
        w->cursor.parts.x = 14;
#ifdef VERSION_EU
        w->cursor.parts.y = bottom;
        if (gLanguage == 2) {
            w->x = 0xC800;
        } else if (gLanguage == 3) {
            w->x = 0xD100;
        } else {
            w->x = 0xD300;
        }
        w->y = 0x8C00;
#else
        w->cursor.parts.y = 6;
#endif
        AnimStart(&w->anim, 1, 1);
        m4aSongNumStart(SONG_SYS_CLICKI04B);
#ifdef VERSION_EU
        w->unk_7C8 = 1;
#endif
        break;
#if defined(VERSION_JP) || defined(VERSION_EU)
    case R_BUTTON:
#ifdef VERSION_JP
        if (w->unk_7C7 <= 1) {
#else
        if (w->unk_7C7 <= 2) {
#endif
            w->unk_7C7++;
#ifdef VERSION_JP
            func_jp_0808F34C(w);
#else
            func_eu_0808EE08(w);
#endif
            m4aSongNumStart(SONG_SYS_CANSEL);
        }
        break;
    case L_BUTTON:
#ifdef VERSION_JP
        if (w->unk_7C7 != 0) {
#else
        if (w->unk_7C7 > 2) {
#endif
            w->unk_7C7--;
#ifdef VERSION_JP
            func_jp_0808F34C(w);
#else
            func_eu_0808EE08(w);
#endif
            m4aSongNumStart(SONG_SYS_CANSEL);
        }
        break;
    case SELECT_BUTTON:
        w->unk_7C6 = 1;
        m4aSongNumStart(SONG_SYS_CLICKI04B);
#ifdef VERSION_JP
        SetTaskUpdate(a, (TaskUpdateFunc)func_jp_0808F638);
        return 1;
#else
        w->x2 = (gUnkEu_090CECE8[w->unk_7C7] + 8) << 8;
        w->y2 = 0x1A00;
        SetTaskUpdate(a, (TaskUpdateFunc)func_eu_0808F190);
        break;
#endif
#endif
    }
    if (w->unk_7C6 != 0) {
#ifdef VERSION_EU
        if (w->cursor.parts.x == 14 && w->cursor.parts.y == bottom) {
            if (gLanguage == 2) {
                ApproachValue(&w->x, 0xC800, w->unk_7C6);
            } else if (gLanguage == 3) {
                ApproachValue(&w->x, 0xD100, w->unk_7C6);
            } else {
                ApproachValue(&w->x, 0xD300, w->unk_7C6);
            }
#else
        if (w->cursor.packed == 0x6000E) {
            ApproachValue(&w->x, 0xD300, w->unk_7C6);
#endif
            ApproachValue(&w->y, 0x8C00, w->unk_7C6);
#ifdef VERSION_EU
        } else if (w->unk_7C7 == 2) {
#else
        } else {
#endif
            ApproachValue(&w->x, gUnk_09035898[w->cursor.parts.y].unk_00[w->cursor.parts.x] << 8, w->unk_7C6);
            ApproachValue(&w->y, gUnk_090358D0[w->cursor.parts.x].unk_00[w->cursor.parts.y] << 8, w->unk_7C6);
#ifdef VERSION_EU
        } else {
            ApproachValue(&w->x, gUnkEu_090CEC30[w->cursor.parts.y].unk_00[w->cursor.parts.x] << 8, w->unk_7C6);
            ApproachValue(&w->y, gUnkEu_090CEC70[w->cursor.parts.x].unk_00[w->cursor.parts.y] << 8, w->unk_7C6);
#endif
        }
    }
    w->x2 = w->x + 0x800;
    w->y2 = w->y + 0x800;
    TaskPoolUpdate(&w->taskpool);
    TaskPoolUpdate(&w->cardpool);
    return 1;
}

u8 func_0808FA0C(u8* work, void* a) {
    FadeStartIn(0, 16);
    work[CARDWORK(0x8B1)] = 0;
    func_0808E364(work, 0);
    func_0808CD48(work);
    FreeTextSlots(&work[0x744], 8);
    ReleaseObjTiles(*(void**)&work[0x738]);
    ReleaseObjTiles(*(void**)&work[0x73C]);
    ReleaseObjPalette(*(void**)&work[0x740]);
    work[CARDWORK(0x8D0)] = 0;
    SetTaskUpdate(a, (TaskUpdateFunc)func_080864A4);
    func_0808C3DC(work, 0);
#ifdef VERSION_EU
    {
        u8* p;
        u8 n;

        p = &work[CARDWORK(0x8B0)];
        n = 1;
        *p = n;
        return n;
    }
#else
    return 1;
#endif
}

void func_0808FA8C(UnkStruct_0808FA8C* w) {
    u16 i;
    u16 j;
    u16 n;

    w->unk_4D4 = EwramAlloc(w->count * sizeof(UnkStruct_08084D78));
    for (i = 0, n = 0; i <= 16; i++) {
        if (w->unk_4D8[i].unk_16 != 0) {
            w->unk_4D4[n] = w->unk_4D8[i];
            w->unk_4D4[n].unk_1C = EwramAlloc(w->unk_4D8[i].unk_18 * 2);
            for (j = 0; j < w->unk_4D8[i].unk_18; j++) {
                w->unk_4D4[n].unk_1C[j] = w->unk_4D8[i].unk_1C[j];
            }
            n++;
        }
    }
    for (i = 143; i <= 159; i++) {
        if (w->unk_4D8[i].unk_16 != 0) {
            w->unk_4D4[n] = w->unk_4D8[i];
            w->unk_4D4[n].unk_1C = EwramAlloc(w->unk_4D8[i].unk_18 * 2);
            for (j = 0; j < w->unk_4D8[i].unk_18; j++) {
                w->unk_4D4[n].unk_1C[j] = w->unk_4D8[i].unk_1C[j];
            }
            n++;
        }
    }
    for (i = 18; i <= 31; i++) {
        if (w->unk_4D8[i].unk_16 != 0) {
            w->unk_4D4[n] = w->unk_4D8[i];
            w->unk_4D4[n].unk_1C = EwramAlloc(w->unk_4D8[i].unk_18 * 2);
            for (j = 0; j < w->unk_4D8[i].unk_18; j++) {
                w->unk_4D4[n].unk_1C[j] = w->unk_4D8[i].unk_1C[j];
            }
            n++;
        }
    }
    for (i = 161; i <= 174; i++) {
        if (w->unk_4D8[i].unk_16 != 0) {
            w->unk_4D4[n] = w->unk_4D8[i];
            w->unk_4D4[n].unk_1C = EwramAlloc(w->unk_4D8[i].unk_18 * 2);
            for (j = 0; j < w->unk_4D8[i].unk_18; j++) {
                w->unk_4D4[n].unk_1C[j] = w->unk_4D8[i].unk_1C[j];
            }
            n++;
        }
    }
    for (i = 32; i <= 142; i++) {
        if (w->unk_4D8[i].unk_16 != 0) {
            w->unk_4D4[n] = w->unk_4D8[i];
            w->unk_4D4[n].unk_1C = EwramAlloc(w->unk_4D8[i].unk_18 * 2);
            for (j = 0; j < w->unk_4D8[i].unk_18; j++) {
                w->unk_4D4[n].unk_1C[j] = w->unk_4D8[i].unk_1C[j];
            }
            n++;
        }
    }
}

static void Deckmenu2_0(u8* work, void* a);

const u16* gUnk_09EE4A68[12] = {
    gUnk_090354E8,
    gUnk_09035512,
    gUnk_0903553A,
    gUnk_09035564,
    gUnk_0903557C,
    gUnk_090355A4,
    gUnk_090355C8,
    gUnk_090355EA,
    gUnk_0903560A,
    gUnk_09035630,
    gUnk_0903563A,
    gUnk_0903566C,
};

const u16* gUnk_09EE4A98[12] = {
    &gUnk_090356A8,
    &gUnk_090356AA,
    &gUnk_090356AC,
    &gUnk_090356AE,
    &gUnk_090356B0,
    &gUnk_090356B2,
    &gUnk_090356B4,
    &gUnk_090356B6,
    &gUnk_090356B8,
    &gUnk_090356B8,
    gUnk_090356BA,
    gUnk_090356BA,
};
#ifdef VERSION_EU
u8 gUnkEu_09F6FD74[7] = { 'D', 'e', 'c', 'k', ' ', '1', 0 };

u8 gUnkEu_09F6FD7B[7] = { 'D', 'e', 'c', 'k', ' ', '2', 0 };

u8 gUnkEu_09F6FD82[7] = { 'D', 'e', 'c', 'k', ' ', '3', 0 };
#else
u16 gUnk_09EE4AC8[7] = { 'D', 'e', 'c', 'k', ' ', '1', 0 };

u16 gUnk_09EE4AD6[7] = { 'D', 'e', 'c', 'k', ' ', '2', 0 };

u16 gUnk_09EE4AE4[7] = { 'D', 'e', 'c', 'k', ' ', '3', 0 };
#endif
#ifdef VERSION_EU
void* gUnkEu_09F6FD8C[5] = { gUnk_090A1FB2, gUnkEu_09189F36, gUnkEu_0918A73A, gUnkEu_0918A48E, gUnkEu_0918A1E2 };

void** gUnkEu_09F6FDA0[5] = { &gUnk_09EEAFD4, &gUnkEu_09F77070, &gUnkEu_09F77094, &gUnkEu_09F77088, &gUnkEu_09F7707C };

void* gUnkEu_09F6FDB4[5] = { gUnk_090A261E, gUnkEu_0918B8F2, gUnkEu_0919016A, gUnkEu_0918E942, gUnkEu_0918D11A };

void** gUnkEu_09F6FDC8[5] = {
    &gUnk_09EEAFE8,
    &gUnkEu_09F770C0,
    &gUnkEu_09F770D8,
    &gUnkEu_09F770D0,
    &gUnkEu_09F770C8,
};

void* gUnkEu_09F6FDDC[5] = { gUnk_090A3E46, gUnkEu_09191992, gUnkEu_0919236A, gUnkEu_09192022, gUnkEu_09191CDA };

void** gUnkEu_09F6FDF0[5] = {
    &gUnk_09EEAFF0,
    &gUnkEu_09F770E0,
    &gUnkEu_09F770F8,
    &gUnkEu_09F770F0,
    &gUnkEu_09F770E8,
};

u8* gUnkEu_09F6FE04[5] = { gUnkEu_094EAD64, gUnkEu_094E90E4, gUnkEu_094EA2E4, gUnkEu_094E9CE4, gUnkEu_094E96E4 };
#endif

TaskDesc gUnk_09EE4AF4 = {
    "Deckmenu2",
    (TaskInitFunc)Deckmenu2_0,
    (TaskUpdateFunc)Deckmenu2_1,
    (TaskFunc)Deckmenu2_2,
    (TaskFunc)func_0808C2F0,
#ifdef VERSION_EU
    0x8DC,
#else
    0x8D8,
#endif
};
#ifdef VERSION_EU
void* gUnkEu_09F6FE30[5] = { gUnk_090A5F1E, gUnk_090A5F1E, gUnkEu_091965CA, gUnkEu_091959DA, gUnk_090A5F1E };

void** gUnkEu_09F6FE44[5] = { gUnk_09EEB08C, gUnk_09EEB08C, gUnkEu_09F7721C, gUnkEu_09F771E4, gUnk_09EEB08C };

void* gUnkEu_09F6FE58[5] = { gUnk_09EEB0B8, gUnk_09EEB0B8, gUnkEu_09F77248, gUnkEu_09F77210, gUnk_09EEB0B8 };
#endif
#ifdef VERSION_US
const u8* gUnk_09EE4B0C[7] = {
    gKeyboardTextUs_09035742,
    gKeyboardTextUs_09035762,
    gKeyboardTextUs_0903577A,
    gKeyboardTextUs_0903579A,
    gKeyboardTextUs_090357B2,
    gKeyboardTextUs_090357D2,
    gKeyboardTextUs_090357F2,
};
#endif
#ifdef VERSION_JP
const u8* gUnk_09EE4B0C[7] = {
    gKeyboardTextJp_09008AE0,
    gKeyboardTextJp_09008AC0,
    gKeyboardTextJp_09008AA0,
    gKeyboardTextJp_09008A88,
    gKeyboardTextJp_09008A68,
    gKeyboardTextJp_09008A48,
    gKeyboardTextJp_09008A2C,
};

const u8* gUnkJp_09EBC148[7] = {
    gKeyboardTextJp_09008BB4,
    gKeyboardTextJp_09008B94,
    gKeyboardTextJp_09008B74,
    gKeyboardTextJp_09008B5C,
    gKeyboardTextJp_09008B3C,
    gKeyboardTextJp_09008B1C,
    gKeyboardTextJp_09008B00,
};

const u8* gUnkJp_09EBC164[7] = {
    gKeyboardTextJp_09008C84,
    gKeyboardTextJp_09008C64,
    gKeyboardTextJp_09008C44,
    gKeyboardTextJp_09008C24,
    gKeyboardTextJp_09008C0C,
    gKeyboardTextJp_09008BEC,
    gKeyboardTextJp_09008BD4,
};
#endif
#ifdef VERSION_EU
const u8* gUnkEu_09F6FE6C[8] = {
    gKeyboardTextEu_090CEA56,
    gKeyboardTextEu_090CEA66,
    gKeyboardTextEu_090CEA72,
    gKeyboardTextEu_090CEA82,
    gKeyboardTextEu_090CEA8E,
    gKeyboardTextEu_090CEA9E,
    gKeyboardTextEu_090CEAA9,
    gKeyboardTextEu_090CEAB9,
};

const u8* gUnkEu_09F6FE8C[7] = {
    gKeyboardTextEu_090CEAC4,
    gKeyboardTextEu_090CEAD4,
    gKeyboardTextEu_090CEADF,
    gKeyboardTextEu_090CEAEF,
    gKeyboardTextEu_090CEAFF,
    gKeyboardTextEu_090CEB05,
    gKeyboardTextEu_090CEB15,
};
#endif
