#ifndef GUARD_CARD_H
#define GUARD_CARD_H

#include "types.h"

#define CARD_ID_MASK 0xFFF
#define DECK_SIZE 99

typedef struct CardDef {
    u8 unk_00[0x2A];
    u8 unk_2A;
    u8 unk_2B[0x09];
} CardDef;

#define gCardDefs ((CardDef*)0x08F70AB0)
#define gCardCollection ((u16*)0x0203A080)
#define gCardCount (*(u16*)0x0203A858)
typedef struct Deck {
    u16 cards[DECK_SIZE];
    u8 unk_C6[0x16];
    u16 unk_DC;
    u16 unk_DE;
} Deck;

#define gDecks ((Deck*)0x02039DE0)
#define gActiveDeck (*(u8*)0x02034AB0)
#define gUnk_02034AA4 (*(u32*)0x02034AA4)

void func_0807E1F4(void);
void func_0807E200(void);
void func_0807E20C(void);
void func_0807E218(void);
void func_0807E224(void);
void func_0807E230(void);
void func_0807E23C(void);
void func_0807E248(void);
void func_0807E254(void);

Deck* func_08085740(void);
u16 func_0808401C(u16 cardId);
u8 func_08085B84(u16 index);
u8 func_08085FA4(void);

#endif /* GUARD_CARD_H */
