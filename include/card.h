#ifndef GUARD_CARD_H
#define GUARD_CARD_H

#include "types.h"
#include "card_types.h"
#include "game.h"
#include "mode.h"

#define CARD_ID_MASK 0xFFF

extern CardDef gCardDefs[];
extern u16 gCardCollection[];
extern u16 gCardCount;

extern Deck gDecks[];
extern u8 gActiveDeck;
extern u32 gUnk_02034AA4;
extern u32 gUnk_02034AA8;
extern u8 gUnk_02034AD8;
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
    u8 unk_1C[0x04];
    void* unk_20;
    u8 unk_24[0x22];
    u8 unk_46;
    u8 unk_47;
    CardDef* unk_48;
    s32 unk_4C;
    s32 unk_50;
    u8 unk_54[0x10];
    u8 unk_64[0x14];
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
extern u8 gUnk_02034AE0[];
extern u8 gUnk_02034B08[];
extern u8 gUnk_02034B20[];
extern void* gUnk_02034AD4;
extern u8 gUnk_02034B1C;
extern u16 gUnk_0203A9DC;
extern u8 gUnk_09EE75D8[];
extern void** gUnk_09EE3CA0[];
extern u16 gUnk_0903BFD4[];
extern void* gUnk_09EE91A8[];
extern u8 gUnk_094233B8[];
extern u8 gUnk_08125E24[];
extern u8 gUnk_096148D8[];
extern u8 gUnk_09417378[];
extern u8 gUnk_02034AF8;
extern void* gUnk_09EEAF4C[];
extern u8* gUnk_0203A9D0;
extern void** gUnk_09EE3FB4[];
extern u8 gUnk_081283C0[];
extern void** gUnk_09EEA28C;
extern void* gUnk_02034B34;
extern u8 gUnk_0203A9E0;
extern vu16 gUnk_03006C78;
extern Mode gUnk_09EF15A8;
extern Mode gUnk_09ECEB40;
extern u8 gUnk_09EE7608[];
extern u8 gUnk_09EE7620[];
extern u8 gUnk_09EE7638[];
extern u8 gUnk_09EE7650[];
extern u8 gUnk_09EE79D4[];
extern u8 gUnk_09EE8ED8[];
extern u8 gUnk_09EE76F0[];
extern u8 gUnk_09EE7774[];
extern u8 gUnk_09EE77A4[];
extern u8 gUnk_09EE77BC[];
extern u8 gUnk_09EE781C[];
extern u8 gUnk_09EE8F08[];
extern s32* gUnk_09EE275C[];
extern u8 gUnk_0203A8C0[];

typedef struct UnkStruct_0807FA0C {
    u8 unk_00[0x14];
    void* unk_14;
    void* unk_18;
    u8 unk_1C[0x28];
    void* unk_44[0x04];
} UnkStruct_0807FA0C;

typedef struct UnkStruct_080A1C48 {
    u8 unk_00[0x04];
    void* unk_04[0x0A];
    void* unk_2C[0x0A];
} UnkStruct_080A1C48;

typedef struct UnkStruct_080991CC {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C;
    u8 unk_0D;
    u8 unk_0E[0x02];
} UnkStruct_080991CC;

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
    u8 unk_14F;
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
    u8 unk_2C[0x18];
    s32 unk_44;
    u8 unk_48[0x02];
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
    u16 unk_08;
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

typedef struct MapcardWork {
    u8 unk_00[0x28];
    void* unk_28;
    u8 unk_2C[0x0C];
    u8 unk_38[0x14];
    s32 unk_4C;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5C;
    s32 unk_60;
    u8 unk_64[0x08];
    u16 unk_6C;
    u8 unk_6E;
    u8 unk_6F;
    u8 unk_70[0x08];
} MapcardWork;

typedef struct UnkStruct_08095A5C {
    s16 unk_00;
    u16 unk_02;
    u8 unk_04[0x09];
    u8 unk_0D;
    u8 unk_0E[0x02];
    u8 unk_10[0x18];
    u8 unk_28[0x18];
    u8 unk_40[0x18];
    void* unk_58;
    void* unk_5C;
    void* unk_60;
} UnkStruct_08095A5C;

typedef struct MapcardArgs {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    void* unk_04;
    void* unk_08;
    u8 unk_0C[0x0C];
} MapcardArgs;

typedef struct ReloadGageArgs {
    void* unk_00;
    void* unk_04;
    s32 unk_08;
    u16 unk_0C;
    u8 unk_0E;
    u8 unk_0F;
} ReloadGageArgs;

typedef struct PrizeCardWork {
    UnkStruct_080038C8* unk_00;
    UnkStruct_080038C8* unk_04;
    UnkStruct_080038C8* unk_08;
    UnkStruct_080038C8* unk_0C;
    UnkStruct_080038C8* unk_10;
    UnkStruct_080038C8* unk_14;
    UnkStruct_080038C8* unk_18;
    UnkStruct_080038C8* unk_1C;
    u8 unk_20[0x2C];
    u8 unk_4C[0x5C];
    s32 unk_A8;
    s32 unk_AC;
    u8 unk_B0[0x18];
    u32 unk_C8;
    s32 unk_CC;
    s32 unk_D0;
    s32 unk_D4;
    s32 unk_D8;
    s32 unk_DC;
    s16 unk_E0;
    s16 unk_E2;
    s16 unk_E4;
    s16 unk_E6;
    s16 unk_E8;
    s16 unk_EA;
    s16 unk_EC;
    u8 unk_EE[0x04];
    s16 unk_F2;
    s16 unk_F4;
    u8 unk_F6;
    u8 unk_F7;
    u8 unk_F8;
    u8 unk_F9;
    u8 unk_FA;
    u8 unk_FB;
    u8 unk_FC[0x04];
} PrizeCardWork;

typedef struct ReloadGageWork {
    u8 unk_00[0x20];
    UnkStruct_08095A5C* unk_20;
    u8 unk_24[0x1C];
    u32 unk_40;
    u8 unk_44[0x02];
    u8 unk_46;
    u8 unk_47[0x05];
    s32 unk_4C;
    s32 unk_50;
    u8 unk_54[0x24];
    u32 unk_78;
    u8 unk_7C[0x08];
    s32 unk_84;
    u8 unk_88[0x14];
    s16 unk_9C;
    u8 unk_9E[0x02];
    u8 unk_A0;
    u8 unk_A1;
    u8 unk_A2;
    u8 unk_A3[0x05];
} ReloadGageWork;

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
extern s16 gUnk_02034AB4;
extern u8 gUnk_02034AB8[];
extern u8 gUnk_09EE7548[];
extern void** gUnk_09EE75B8[];
extern void* gUnk_09EE75C8[];
extern void* gUnk_09EE7588[];
extern void* gUnk_09EE7598[];
extern s32 gUnk_09033FF4[];
extern u8 gUnk_090A261E[];
extern u8 gUnk_096144D8[];
extern u8 gUnk_090A4A0C[];
extern u8 gUnk_090A51F6[];
extern u8 gUnk_09EEB064[];
extern u8 gUnk_09EEB050[];
extern u8 gUnk_09EEB07C[];
extern u8 gUnk_09EEB068[];
extern s16 gUnk_09035950[];
extern s16 gUnk_09035956[];
extern u8 gUnk_093F7172[];
extern u8 gUnk_09508098[];
extern u8 gUnk_09618C58[];
extern u8 gUnk_08C8C824[];
extern u8 gUnk_08F68A84[];
extern u8 gUnk_08EF4384[];
extern u8 gUnk_09EE7804[];
extern u8 gUnk_09EE7560[];
extern u8 gUnk_09EE4BB0[];
extern u8 gUnk_09EE7680[];
extern u8 gUnk_090A583E[];
extern u8 gUnk_090A418E[];
extern u8 gUnk_090A3E46[];
extern u8 gUnk_096144F8[];
extern u8 gUnk_09516AB8[];
extern u8 gUnk_095132B8[];
extern void* gUnk_0203A890[];
extern u8 gUnk_093FEEB8[];
extern u8 gUnk_093FD438[];
extern u8 gUnk_093F47E4[];
extern u8 gUnk_09EF1194[];
extern u8 gUnk_09EF1180[];
extern u8 gUnk_09515AB8[];
extern u8 gUnk_095182B8[];
extern u8 gUnk_09514AB8[];
extern u8 gUnk_09614458[];
extern u8 gUnk_09614478[];
extern u8 gUnk_09614498[];
extern u8 gUnk_096144B8[];
extern u8 gUnk_09614406[];
extern u8 gUnk_08F69BA4[];
extern u8 gUnk_0905ED36[];
extern u8 gUnk_0905EAE8[];
extern u8 gUnk_09611AB8[];

typedef struct UnkStruct_02039BA0 {
    s32 unk_00;
    s32 unk_04;
    u8 unk_08[0x10];
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    u8 unk_24[0x4C];
    u32 unk_70;
} UnkStruct_02039BA0;

extern UnkStruct_02039BA0* gUnk_02039BA0;

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

void func_08066588(s16 a, s16 b, void* c, void* d, s32 e, u8 f);

#endif /* GUARD_CARD_H */
