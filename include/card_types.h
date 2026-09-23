#ifndef GUARD_CARD_TYPES_H
#define GUARD_CARD_TYPES_H

#include "types.h"

#define DECK_SIZE 99

typedef struct Deck {
    u16 cards[DECK_SIZE];
    u8 unk_C6[0x14];
    u16 unk_DA;
    u16 unk_DC;
    u16 unk_DE;
} Deck;

typedef struct CardDef {
    void* gfx;
    void* tiles;
    void* palette;
    void* name;
    void* gfx2;
    void* tiles2;
    void* palette2;
    u16 unk_1C;
    u16 flags;
    u8 unk_20;
    u8 unk_21[0x03];
    u32 unk_24;
    u16 unk_28;
    u8 unk_2A;
    u8 unk_2B;
    u16 unk_2C;
    u8 unk_2E[0x06];
} CardDef;

typedef struct CardBack {
    void* gfx;
    void* gfx2;
    void* unk_08;
    void* tiles;
    void* tiles2;
    void* tiles3;
} CardBack;

typedef struct CardStat {
    u16 unk_00;
    u16 unk_02;
    u8 unk_04;
    u8 unk_05[0x03];
    u32 unk_08;
    u16 unk_0C;
    u8 unk_0E;
    u8 unk_0F;
    u16 unk_10;
    u8 unk_12[0x06];
} CardStat;

#endif
