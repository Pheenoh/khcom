#ifndef GUARD_CARD_H
#define GUARD_CARD_H

#include "types.h"

#define CARD_ID_MASK 0xFFF
#define DECK_SIZE 99

typedef struct CardDef {
    u8 unk_00[0x1C];
    u16 unk_1C;
    u8 unk_1E[0x0C];
    u8 unk_2A;
    u8 unk_2B[0x09];
} CardDef;

extern CardDef gCardDefs[];
extern u16 gCardCollection[];
extern u16 gCardCount;

typedef struct Deck {
    u16 cards[DECK_SIZE];
    u8 unk_C6[0x14];
    u16 unk_DA;
    u16 unk_DC;
    u16 unk_DE;
} Deck;

extern Deck gDecks[];
extern u8 gActiveDeck;
extern u32 gUnk_02034AA4;
extern u8 gUnk_02039DDC;
extern u8 gUnk_02034ACC;
extern u32 gUnk_02034AD0;
extern u8 gUnk_0203A9D4;
extern u8 gUnk_0203A9D8;

void func_0807E1F4(void);
void func_0807E200(void);
void func_0807E20C(void);
void func_0807E218(void);
void func_0807E224(void);
void func_0807E230(void);
void func_0807E23C(void);
void func_0807E248(void);
void func_0807E254(void);

Deck* GetActiveDeck(void);
Deck* GetDeck(u8 index);
u16 CountCardsById(u16 cardId);
u8 func_08085B84(u16 index);
u16 func_08085B5C(u16 index);
u8 GetActiveDeckIndex(void);
void SetActiveDeckIndex(u8 index);
u16 func_08085770(u8 index);
u16 func_08085B38(u8 index);
u8* func_080857BC(u8 index);

#endif /* GUARD_CARD_H */
