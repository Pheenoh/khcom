#ifndef GUARD_CARD_H
#define GUARD_CARD_H

#include "types.h"
#include "game.h"

#define CARD_ID_MASK 0xFFF
#define DECK_SIZE 99

typedef struct CardDef {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    void* unk_14;
    void* unk_18;
    u16 unk_1C;
    u16 unk_1E;
    u8 unk_20;
    u8 unk_21[0x03];
    u32 unk_24;
    u16 unk_28;
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

typedef struct UnkStruct_02034AAC {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x0C];
    void* unk_14;
    void* unk_18;
    u8 unk_1C[0x2A];
    u8 unk_46;
    u8 unk_47;
    CardDef* unk_48;
    u8 unk_4C[0x2C];
    u32 unk_78;
    u8 unk_7C[0x25];
    u8 unk_A1;
    u8 unk_A2[0x03];
    u8 unk_A5;
} UnkStruct_02034AAC;

extern UnkStruct_02034AAC* gUnk_02034AAC;
extern UnkStruct_02034AAC* gUnk_02034A98;
extern UnkStruct_02039B84* gUnk_02039B9C;
extern u8 gUnk_02039DD8;
extern u8 gUnk_0203A9E8;
extern void* gUnk_0203A854;
extern u8 gUnk_09EE4BC8[];
extern u8 gUnk_09EE75F0[];
extern u8 gUnk_0203A8C0[];

typedef struct UnkStruct_09EE7D84 {
    void** unk_00;
    u8 unk_04;
} UnkStruct_09EE7D84;

typedef struct UnkStruct_02034AFC {
    u8 unk_000[0x10C];
    u64 unk_10C;
    u8 unk_114[0x31];
    u8 unk_145;
    u8 unk_146[0x08];
    u8 unk_14E;
} UnkStruct_02034AFC;

extern UnkStruct_09EE7D84* gUnk_09EE7D84[];
extern UnkStruct_02034AFC* gUnk_02034AFC;
extern UnkStruct_02034AFC* gUnk_02034B00;

typedef struct UnkStruct_02039BB0 {
    u8 unk_000[0x08];
    u32 unk_008;
    u8 unk_00C[0xEE];
    s16 unk_0FA;
    u8 unk_0FC[0x0C];
    u8 unk_108;
    u8 unk_109[0x6F];
    u16 unk_178;
} UnkStruct_02039BB0;

extern UnkStruct_02039BB0 gUnk_02039BB0;
extern s16 gUnk_09037FBA[];
extern u16 gUnk_09EE48F4[];
extern u8 gUnk_09EE7FA8[];

typedef struct CardBack {
    void* unk_00;
    u8 unk_04[0x08];
    void* unk_0C;
    void* unk_10;
    u8 unk_14[0x04];
} CardBack;

typedef struct UnkStruct_09EE8008 {
    u32 unk_00;
    u8 unk_04[0x0C];
    u16 unk_10;
    u16 unk_12;
} UnkStruct_09EE8008;

typedef struct UnkStruct_080A4188 {
    u32 unk_00;
    u32 unk_04 : 16;
    u32 unk_06 : 8;
    u32 unk_07 : 8;
} UnkStruct_080A4188;

typedef struct UnkStruct_0807B410 {
    u32 unk_00;
    u8 unk_04[0xB4];
    u8 unk_B8[0x10];
} UnkStruct_0807B410;

typedef struct UnkStruct_0808E890 {
    u8 unk_00[0x22];
    s16 unk_22;
    s16 unk_24;
    u8 unk_26[0x06];
    u8 unk_2C[0x1E];
    u8 unk_4A;
} UnkStruct_0808E890;

typedef struct UnkStruct_0809C9A4 {
    u8 unk_00[0x4A];
    s16 unk_4A;
    s16 unk_4C;
    u8 unk_4E;
    u8 unk_4F;
    s16 unk_50;
} UnkStruct_0809C9A4;

typedef struct UnkStruct_0808C940 {
    u8 unk_000[0x6EE];
    s16 unk_6EE;
    u8 unk_6F0[0x164];
    s32 unk_854;
    u8 unk_858[0x54];
    s16 unk_8AC;
    s16 unk_8AE;
} UnkStruct_0808C940;

typedef struct UnkStruct_0808E2F0 {
    u8 unk_00[0x1C];
    void* unk_1C;
} UnkStruct_0808E2F0;

typedef struct UnkStruct_0808DB04 {
    u8 unk_000[0x4D4];
    UnkStruct_0808E2F0* unk_4D4;
    u8 unk_4D8[0x3C0];
    u16 unk_898;
} UnkStruct_0808DB04;

typedef struct UnkStruct_080A324C {
    u8 unk_000;
    u8 unk_001[0x10E];
    u16 unk_110[999];
    u16 unk_8DE;
    Deck unk_8E0[3];
} UnkStruct_080A324C;

typedef struct UnkStruct_08080268 {
    u8 unk_00[0x28];
    UnkStruct_02034AAC* unk_28[3];
    u8 unk_34[0x86];
    u8 unk_BA;
} UnkStruct_08080268;

typedef struct UnkStruct_08098670 {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    void* unk_14;
    void* unk_18;
    void* unk_1C;
    void* unk_20;
    s32 unk_24;
    s32 unk_28;
} UnkStruct_08098670;

typedef struct UnkStruct_080038C8 {
    u8* unk_00;
    u8 unk_04[0x02];
    u16 unk_06;
} UnkStruct_080038C8;

typedef struct CardSlot {
    u32 unk_00;
    u16 unk_04;
    u8 unk_06;
    u8 unk_07;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0A;
    u8 unk_0B;
} CardSlot;

typedef struct UnkStruct_08078754 {
    u8 unk_00[0x44];
    CardSlot* unk_44[25];
    s16 unk_A8[25];
} UnkStruct_08078754;

typedef struct UnkStruct_09035DCC {
    u16* unk_00;
    u16 unk_04;
    u16 unk_06;
} UnkStruct_09035DCC;

extern UnkStruct_09035DCC gUnk_09035DCC[];
extern UnkStruct_09035DCC gUnk_090360BC[];
extern u16 gUnk_090359FC[];
extern CardBack gUnk_08F709B0[];
extern UnkStruct_09EE8008 gUnk_09EE8008[];
extern u8 gUnk_09EE8E48[];
extern u8 gUnk_09EE8E30[];
extern u8 gUnk_09EE8E18[];
extern Deck gUnk_09041FA0;
extern u16 gUnk_09041F70[];
extern void* gUnk_09EF7048[];
extern u32 gUnk_03006C10;
extern u16 gUnk_09EE4AC8[];
extern u16 gUnk_09EE4AD6[];
extern u16 gUnk_09EE4AE4[];
extern Deck* gUnk_0203A850;
extern s16 gSineTable[];
extern u32 gUnk_09036210[];
extern u8 gUnk_09EE778C[];
extern u8 gUnk_09EE4A14[];
extern void* gUnk_09EF1198[];
extern u8 gUnk_0950C478[];
extern u8 gUnk_0940FA98[];
extern u8 gUnk_0940FAD8[];
extern void* gUnk_09EE8F48[];
extern u8 gUnk_09EE7FC0[];

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
