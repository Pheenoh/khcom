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
extern u8 gUnk_02039DDC;
extern u8 gUnk_0203A9D4;
extern u8 gUnk_0203A9D8;

typedef struct UnkStruct_02034AAC {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    u8 unk_10[0x04];
    void* unk_14;
    void* unk_18;
    u8 unk_1C[0x04];
    void* unk_20;
    u8 unk_24[0x14];
    void* unk_38;
    u8 unk_3C[0x0A];
    u8 unk_46;
    u8 unk_47;
    CardDef* unk_48;
    s32 unk_4C;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    u8 unk_5C[0x02];
    u8 unk_5E;
    u8 unk_5F;
    u8 unk_60[0x04];
    u8 unk_64[0x14];
    u32 unk_78;
    s32 unk_7C;
    s32 unk_80;
    s32 unk_84;
    s32 unk_88;
    s32 unk_8C;
    s32 unk_90;
    s32 unk_94;
    s32 unk_98;
    u16 unk_9C;
    u8 unk_9E;
    u8 unk_9F;
    u8 unk_A0;
    u8 unk_A1;
    u8 unk_A2;
    u8 unk_A3;
    s8 unk_A4;
    u8 unk_A5;
    u8 unk_A6;
    u8 unk_A7;
} UnkStruct_02034AAC;
extern BtlWork* gUnk_02039B9C;
extern u8 gUnk_02039DD8;
extern u8 gUnk_0203A9E8;
extern void* gUnk_0203A854;
extern u8 gTaskDescMapSelect[];
extern u8 gTaskDescPrizeCardInit[];
extern u16 gUnk_0203A9DC;
extern u8 gUnk_09EE75D8[];
extern void** gUnk_09EE3CA0[];
extern u16 gUnk_0903BFD4[];
extern u16 gUnk_0903BFBC[];
extern u8 gUnk_0940F7B8[];
extern u8 gUnk_0940F918[];
extern void* gUnk_09EE7708[];
extern void* gUnk_09EE7714[];
extern void* gUnk_09EE7720[];
extern void* gUnk_09EE91A8[];
extern u8 gUnk_094233B8[];
extern void* gUnk_09EEA19C[];
extern u8 gUnk_093FB6C4[];
extern u8 gUnk_08125E24[];
extern u8 gUnk_096148D8[];
extern u8 gUnk_09417378[];
extern void* gUnk_09EEAF4C[];
extern u8 gUnk_09EEAFB0[];
extern u8 gUnk_0909A4E0[];
extern u8 gUnk_0909FDCA[];
extern u8 gUnk_090A0C86[];
extern u8 gUnk_09507F38[];
extern u8 gUnk_09507F58[];
extern u16 gUnk_09EE4BE0[];
extern void* gUnk_09EF1278[];
extern u8* gUnk_0203A9D0;
extern void** gUnk_09EE3FB4[];
extern u8 gUnk_081283C0[];
extern void** gUnk_09EEA28C;
extern u8 gUnk_0203A9E0;
extern vu16 gSystemFlags;
extern Mode gModeSioChgCard;
extern Mode gModeBattle;
extern u8 gTaskDescPrizeCardInitBoss[];
extern u8 gTaskDescDispCardname[];
extern u8 gTaskDescVersion[];
extern u8 gUnk_09EE7650[];
extern u8 gTaskDescEVBGEFFECT[];
extern u8 gUnk_09EE8ED8[];
extern u8 gTaskDescREVCOUNT[];
extern u8 gTaskDescScrollbar[];
extern u8 gUnk_09EE77A4[];
extern u8 gUnk_09EE77BC[];
extern u8 gUnk_09EE781C[];
extern u8 gTaskDescHCEffectName[];
extern u8 gTaskDescLevelUp[];
extern u8 gUnk_09402F78[];
extern u8 gUnk_09614118[];
extern u8 gUnk_0951B2B8[];
extern u8 gUnk_09406F78[];
extern void* gUnk_09EE7938[];
extern u8 gTaskDescLVUPEFFECT[];
extern u8 gTaskDescLvupLogo[];
extern u8 gTaskDescCardEFFECT[];
extern u8 gUnk_0908C686[];
extern u8 gUnk_0908FCEE[];
extern u8 gUnk_09613F78[];
extern void* gUnk_09EF12E8[];
extern u8 gTaskDescDeckexchange[];
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
    u8 unk_54[0x04];
    void* unk_58;
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
typedef struct GameState {
    u8 unk_000[0x08];
    u32 flags;
    u8 unk_00C[0xEE];
    s16 cp;
    u8 unk_0FC[0x0C];
    u8 level;
    u8 unk_109[0x6F];
    u16 unk_178;
    u16 unk_17A;
} GameState;

extern GameState gGameState;
extern s16 gUnk_09037FBA[];
extern s32 gUnk_09037FFC[];
extern s32 gUnk_0903800C[];
extern u16 gUnk_0903801C[];
extern u16 gUnk_09EE48F4[];
extern u8 gUnk_09EE49CC[];
extern u8 gUnk_09EE49FC[];
extern s32 gUnk_090352E4[];
extern u8 gUnk_09512AB8[];
extern u8 gUnk_08B22BBC[];
extern u8 gUnk_09EE7834[];
extern u8 gUnk_09EDA9A8[];
extern void* gUnk_09EF1298[];
extern u8 gUnk_08B25ADE[];
extern u8 gUnk_093FB954[];
extern void* gUnk_09EF12C8[];
extern u8 gUnk_09EE4B28[];
extern u8 gUnk_09619178[];
extern u8 gUnk_09EE8E60[];
extern u8 gUnk_093FB1AC[];
extern u8 gUnk_09619378[];
extern u8 gUnk_093FB0CC[];
extern s32 gUnk_09033D08[][2];
extern s32 gUnk_09041E9C[];
extern s16 gUnk_09041EB4[];
extern s16 gUnk_09041EBA[];
extern u8 gUnk_093F7C9C[];
extern u8 gUnk_08159E18[];
extern u8 gUnk_08159FBC[];
extern u8 gUnk_0815C1C2[];
extern u8 gUnk_08159E10[];
extern u8 gUnk_09EEB008[];
extern u8 gUnk_09EEB03C[];
extern u8 gUnk_090A4664[];
extern u8 gUnk_09614418[];
extern u8 gUnk_093F8C8E[];
extern u8 gUnk_09985F44[];
extern u8 gUnk_099597E4[];
extern u8 gUnk_09EEFCAC[];
extern u8 gUnk_09EEFD38[];
extern u8 gUnk_09320796[];
extern u8 gUnk_08F69BE4[];
extern u8 gUnk_09EE7FD8[];
extern u8 gUnk_09EE7FA8[];

typedef struct CardBack {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x04];
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
    u8 unk_00[0x04];
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    CardDef* unk_14;
    CardBack* unk_18;
    void* unk_1C;
    u16 unk_20;
    s16 unk_22;
    s16 unk_24;
    u8 unk_26;
    u8 unk_27;
    void* unk_28;
    u8 unk_2C[0x14];
    s32 unk_40;
    s32 unk_44;
    u16 unk_48;
    u8 unk_4A;
    u8 unk_4B[0x02];
    u8 unk_4D;
} UnkStruct_0808E890;

typedef struct UnkStruct_0808E3E0 {
    u8 unk_00[0x24];
    u16 unk_24;
} UnkStruct_0808E3E0;

typedef struct UnkStruct_0809C534_Args {
    s32 unk_00;
    u16 unk_04;
    u8 unk_06;
} UnkStruct_0809C534_Args;

typedef struct UnkStruct_0809C534 {
    CardDef* unk_00;
    CardBack* unk_04;
    u8 unk_08[0x10];
    u32 unk_18;
    u8 unk_1C[0x2C];
    u16 unk_48;
    s16 unk_4A;
    s16 unk_4C;
    u16 unk_4E;
    u16 unk_50;
    s8 unk_52;
    u8 unk_53;
    u8 unk_54;
    u8 unk_55;
    u8 unk_56[0x02];
    u8 unk_58[0x14];
    u16 unk_6C;
    u16 unk_6E;
    u16 unk_70;
    u16 unk_72;
    u8 unk_74;
} UnkStruct_0809C534;

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
    u16 unk_00[0x0B];
    u16 unk_16;
    u8 unk_18[0x04];
    u16* unk_1C;
} UnkStruct_0808E2F0;

typedef struct UnkStruct_0808DB04 {
    u8 unk_000[0x4D4];
    UnkStruct_0808E2F0* unk_4D4;
    u8 unk_4D8[0x3A8];
    u16 unk_880;
    u8 unk_882[0x02];
    s16 unk_884;
    u16 unk_886;
    u8 unk_888[0x10];
    u16 unk_898;
    u8 unk_89A[0x26];
    u8 unk_8C0;
} UnkStruct_0808DB04;

typedef struct UnkStruct_080A324C {
    u8 unk_000;
    u8 unk_001[0x10E];
    u16 unk_110[999];
    u16 unk_8DE;
    Deck unk_8E0[3];
} UnkStruct_080A324C;

typedef struct UnkStruct_08080268 {
    u8 unk_00[0x14];
    void* unk_14;
    void* unk_18;
    u8 unk_1C[0x0C];
    UnkStruct_02034AAC* unk_28[3];
    UnkStruct_02034AAC* unk_34[8];
    u8 unk_54[4][0x10];
    u16 unk_94[4];
    u16 unk_9C[4];
    s16 unk_A4;
    u8 unk_A6[0x0A];
    s16 unk_B0[4];
    s8 unk_B8;
    u8 unk_B9;
    u8 unk_BA;
    u8 unk_BB;
    u8 unk_BC[4];
    u8 unk_C0[4];
    u8 unk_C4[5];
    u8 unk_C9;
} UnkStruct_08080268;

typedef struct UnkStruct_0809DF7C {
    s16 unk_00;
    u8 unk_02[0x06];
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    void* unk_14;
    u8 unk_18;
    u8 unk_19;
    u16 unk_1A;
    u16 unk_1C;
    u16 unk_1E;
    u16 unk_20;
    u8 unk_22;
    u8 unk_23;
    u8 unk_24;
    u8 unk_25;
    u8 unk_26;
    u8 unk_27;
} UnkStruct_0809DF7C;

typedef struct UnkStruct_080988C0_Args {
    void* unk_00;
    s32* unk_04;
    s32* unk_08;
    u8 unk_0C;
    u8 unk_0D;
    u8 unk_0E;
    u8 unk_0F;
    u8 unk_10[0x04];
} UnkStruct_080988C0_Args;

typedef struct UnkStruct_08098BE8 {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C[0x04];
    s32* unk_10;
    s32* unk_14;
    u8 unk_18;
    u8 unk_19;
    u8 unk_1A[0x06];
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    u8 unk_2C[0x04];
    u8 unk_30[0x15];
    u8 unk_45;
    u8 unk_46;
} UnkStruct_08098BE8;

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

typedef struct UnkStruct_0807FD10_Args {
    void* unk_00;
    CardSlot* unk_04;
    u8 unk_08[0x04];
    u16 unk_0C;
    u8 unk_0E;
    u8 unk_0F;
} UnkStruct_0807FD10_Args;

typedef struct UnkStruct_08078754 {
    u8 unk_00[0x44];
    CardSlot* unk_44[25];
    s16 unk_A8[25];
} UnkStruct_08078754;

typedef struct UnkStruct_09EE4C80 {
    u8 unk_00[0x1E];
    u8 unk_1E;
    u8 unk_1F[0x03];
    u16 unk_22;
    u8 unk_24[0x04];
} UnkStruct_09EE4C80;

typedef struct UnkStruct_09EE4BF4 {
    u8 unk_00[0x1C];
} UnkStruct_09EE4BF4;

extern UnkStruct_09EE4C80 gUnk_09EE4C80[];
extern UnkStruct_09EE4BF4 gUnk_09EE4BF4[];

typedef struct MapcardWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    u8 unk_10[0x08];
    UnkStruct_09EE4C80* unk_18;
    UnkStruct_09EE4BF4* unk_1C;
    u8 unk_20;
    u8 unk_21;
    u8 unk_22[0x06];
    void* unk_28;
    u8 unk_2C[0x0C];
    u8 unk_38[0x14];
    s32 unk_4C;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5C;
    s32 unk_60;
    s32 unk_64;
    u16 unk_68;
    u16 unk_6A;
    u16 unk_6C;
    u8 unk_6E;
    u8 unk_6F;
    u8 unk_70;
    u8 unk_71;
    u8 unk_72;
    u8 unk_73;
    u8 unk_74;
    u8 unk_75[0x03];
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

typedef struct UnkStruct_02034AD4 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u16 unk_04[32];
} UnkStruct_02034AD4;

typedef struct UnkStruct_0809E0A4 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
} UnkStruct_0809E0A4;

typedef struct UnkWork_0809E0A4 {
    void* unk_00;
    void* unk_04;
    UnkStruct_0809E0A4 unk_08;
    s16 unk_24;
    s16 unk_26;
    u8 unk_28;
    u8 unk_29;
} UnkWork_0809E0A4;

typedef struct UnkStruct_08083BE4_Frame {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
} UnkStruct_08083BE4_Frame;

typedef struct UnkStruct_08083BE4_Entry {
    UnkStruct_08083BE4_Frame* unk_00;
    u8* unk_04;
    u8 unk_08;
    u8 unk_09;
    s16 unk_0A;
    u16 unk_0C;
    u8 unk_0E[0x02];
} UnkStruct_08083BE4_Entry;

typedef struct UnkStruct_08083BE4_Anim {
    UnkStruct_08083BE4_Entry* unk_00;
    u8 unk_04;
} UnkStruct_08083BE4_Anim;

typedef struct UnkStruct_08083B94 {
    u8 unk_00;
    u8 unk_01[8];
    u8 unk_09[8];
    u8 unk_11[3];
    UnkStruct_08083BE4_Anim* unk_14;
} UnkStruct_08083B94;

typedef struct UnkStruct_09EE752C {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
} UnkStruct_09EE752C;

typedef struct PrizeCardArgs {
    s32 unk_00[8];
} PrizeCardArgs;

typedef struct PrizeCardInitWork {
    TaskPool unk_00;
    u8 unk_14;
    PrizeCardArgs unk_18;
} PrizeCardInitWork;

typedef struct ScrollBarWork {
    u8 unk_00[0x08];
    u16 unk_08;
    u16 unk_0A;
    u16 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    u16 unk_12;
    u8 unk_14[0x02];
    u8 unk_16;
    u8 unk_17;
} ScrollBarWork;

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
    s32 unk_7C;
    s32 unk_80;
    s32 unk_84;
    u8 unk_88[0x14];
    s16 unk_9C;
    u8 unk_9E[0x02];
    u8 unk_A0;
    u8 unk_A1;
    u8 unk_A2;
    u8 unk_A3[0x05];
} ReloadGageWork;

typedef struct UnkStruct_08096C38_Item {
    u16 unk_00;
    u16 unk_02;
} UnkStruct_08096C38_Item;

typedef struct UnkStruct_08096C38 {
    UnkStruct_08096C38_Item* unk_00;
    u16 unk_04;
    u16 unk_06;
} UnkStruct_08096C38;

typedef struct UnkStruct_09035DCC {
    UnkStruct_08096C38* unk_00;
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
extern s16 gUnk_09036278[];
extern u8 gUnk_09036380[];
extern u8 gUnk_09036300[];
extern void* gUnk_09EE4724[];
extern u8 gUnk_09EE778C[];
extern u8 gTaskDescBosscard[];
extern void* gUnk_09EF1198[];
extern u8 gUnk_0950C478[];
extern u8 gUnk_0940FA98[];
extern u8 gUnk_0940FAD8[];
extern u8 gUnk_0940FC58[];
extern u8 gUnk_09410058[];
extern void* gUnk_09EE1538[];
extern void* gUnk_09EE8F48[];
extern u8 gUnk_09EE7FC0[];
extern u8 gTaskDescMapcard[];
extern void** gUnk_09EE75B8[];
extern void* gUnk_09EE75C8[];
extern void* gUnk_09EE7588[];
extern void* gUnk_09EE7598[];
extern s32 gUnk_09033FF4[];
extern s32 gUnk_09033FA8[];
extern s32 gUnk_0903401C[];
extern s32 gUnk_0903404C[];
extern s16 gUnk_09EE7520[];
extern u8 gUnk_090A261E[];
extern u8 gUnk_096144D8[];
extern u8 gUnk_090A4A0C[];
extern u8 gUnk_090A51F6[];
extern void** gUnk_02034B38;
extern u8 gUnk_090451C0[];
extern void* gUnk_09EE4A2C[];
extern UnkStruct_09EE752C gUnk_09EE752C[];
extern u8 gUnk_09EEA4E0[];
extern u8 gUnk_09EEA494[];
extern u8 gUnk_09EEB064[];
extern u8 gUnk_09EEB050[];
extern u8 gUnk_09EEB07C[];
extern u8 gUnk_09EEB068[];
extern s16 gUnk_09035950[];
extern s16 gUnk_09035956[];
extern u8 gUnk_093F7172[];
extern u8 gUnk_09508098[];
extern u8 gUnk_09618C58[];
extern u8 gUnk_09619098[];
extern u8 gUnk_08C8C824[];
extern u8 gUnk_08F68A84[];
extern u8 gUnk_08EF4384[];
extern u8 gUnk_09EE7804[];
extern u8 gUnk_09EE7560[];
extern u8 gUnk_09EE4BB0[];
extern u8 gTaskDescSELMAPEVKEY[];
extern void* gUnk_09EE7698[];
extern void* gUnk_09EE76C0[];
extern void** gUnk_09EE76D0[];
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
extern void* gUnk_09EEA344[];
extern void* gUnk_09EE98EC[];
extern void* gUnk_09EEA16C[];
extern void* gUnk_09EEA174[];
extern u8 gUnk_09619158[];
extern u8 gUnk_093F762E[];
extern u8 gUnk_09EF1260[];
extern u8 gUnk_09EF1230[];
extern u8 gUnk_095162B8[];
extern u8 gUnk_095182B8[];
extern u8 gUnk_095192B8[];
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
extern u8 gUnk_0908C3CE[];
extern u8 gUnk_09EEA180[];
extern u8 gUnk_09EEA198[];
extern Mode gUnk_09EE2704;
extern u8 gUnk_09501778[];
extern u8 gUnk_09618C38[];
extern u8 gUnk_0960F2B8[];
extern u8 gUnk_050001A0[];
extern u8 gUnk_050001C0[];
extern u8 gUnk_0500016C[];
extern u8 gUnk_06010000[];
extern u32 gFrameCounter;
extern u8 gUnk_095152B8[];
extern u8 gUnk_095152CC[];
extern u8 gUnk_095152E0[];
extern u8 gUnk_09515338[];
extern u8 gUnk_0951534C[];

typedef struct UnkStruct_080933D8 {
    u16 unk_00;
    u16 unk_02;
} UnkStruct_080933D8;

typedef struct UnkStruct_08097A14 {
    u8 unk_00;
    u8 unk_01[0x03];
    s32 unk_04;
    s32 unk_08;
    u16 unk_0C;
    u8 unk_0E[0x02];
    u8* unk_10;
    u8 unk_14;
} UnkStruct_08097A14;

typedef struct UnkStruct_08099E70 {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x18];
    void* unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s16 unk_30;
    s16 unk_32;
    u8 unk_34[0x04];
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
    u8 unk_44;
    u8 unk_45[0x03];
    u8* unk_48;
} UnkStruct_08099E70;

typedef struct UnkStruct_08083B20 {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    u8 unk_10[0x04];
    s32 unk_14;
    s32 unk_18;
    u8 unk_1C[0x04];
    UnkStruct_08095A5C* unk_20;
    u8 unk_24[0x08];
    s16 unk_2C;
    u8 unk_2E[0x04];
    u8 unk_32;
    u8 unk_33[0x13];
    u8 unk_46;
} UnkStruct_08083B20;

typedef struct UnkStruct_080978B0 {
    u8 unk_00[0xC8];
    s16 unk_C8;
    s16 unk_CA;
    u8 unk_CC[0x0E];
    s16 unk_DA;
    u8 unk_DC[0x03];
    u8 unk_DF;
    u8 unk_E0;
} UnkStruct_080978B0;

typedef struct UnkStruct_08099928 {
    u8 unk_00[0xD0];
    s16 unk_D0;
    s16 unk_D2;
    u8 unk_D4[0x02];
    u16 unk_D6;
    u16 unk_D8;
    u8 unk_DA[0x08];
    s16 unk_E2;
    u8 unk_E4[0x04];
    u8 unk_E8;
    u8 unk_E9;
} UnkStruct_08099928;

typedef struct UnkStruct_080A1BB8_Entry {
    s32 unk_00 : 24;
    s32 unk_03 : 8;
    s32 unk_04 : 24;
    s32 unk_07 : 8;
    u8 unk_08;
    u8 unk_09[0x03];
} UnkStruct_080A1BB8_Entry;

typedef struct UnkStruct_080A1BB8 {
    UnkStruct_09035DCC* unk_00;
    UnkStruct_09035DCC* unk_04;
    void** unk_08;
    UnkStruct_080A1BB8_Entry* unk_0C;
    u16 unk_10;
} UnkStruct_080A1BB8;

typedef struct UnkStruct_08090244 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C;
    u8 unk_0D;
    u8 unk_0E;
    u8 unk_0F;
} UnkStruct_08090244;

typedef struct UnkStruct_08093838 {
    u8 unk_000[0x14];
    u8 unk_014[0x1D8];
    MapcardWork* unk_1EC;
    u8 unk_1F0[0x04];
    MapcardWork* unk_1F4;
    u8 unk_1F8[0x60];
    s32 unk_258;
    u8 unk_25C[0x08];
    s32 unk_264;
    u8 unk_268[0x1C];
    u8 unk_284;
    u8 unk_285[0x07];
    u8 unk_28C;
    u8 unk_28D[0x0B];
    u8 unk_298;
} UnkStruct_08093838;

typedef struct UnkStruct_08F7CBA8 {
    void* unk_00;
    u8 unk_04[0x04];
    void** unk_08;
    u16 unk_0C;
    u16 unk_0E;
} UnkStruct_08F7CBA8;

extern UnkStruct_08F7CBA8 gUnk_08F7CBA8[];

typedef struct UnkStruct_080A2F54 {
    u8 unk_000[0x280];
    u8 unk_280[0x280];
    u8 unk_500[0x280];
    void* unk_780;
    void* unk_784;
    void* unk_788;
    u8 unk_78C;
    u8 unk_78D;
    u8 unk_78E;
    u8 unk_78F;
    s16 unk_790;
    s16 unk_792;
    s16 unk_794;
    s16 unk_796;
    s16 unk_798;
    s16 unk_79A;
    s16 unk_79C;
    u8 unk_79E[2];
    u8* unk_7A0;
    u8 unk_7A4;
} UnkStruct_080A2F54;

typedef struct UnkStruct_080A5D3C {
    u8 unk_000[0x48C];
    s32 unk_48C;
    s32 unk_490;
    s32 unk_494;
    s32 unk_498;
    u8 unk_49C[0x2C];
    s16 unk_4C8[2];
    u8 unk_4CC[0x1A];
    u8 unk_4E6;
    u8 unk_4E7[5];
    u8 unk_4EC;
    u8 unk_4ED[2];
    u8 unk_4EF;
    u8 unk_4F0;
    u8 unk_4F1;
    u8 unk_4F2;
    u8 unk_4F3[5];
    u8 unk_4F8;
    u8 unk_4F9[0x10];
    u8 unk_509;
} UnkStruct_080A5D3C;

typedef struct UnkStruct_080A1A44_Args {
    s32 unk_00;
    s32 unk_04;
    u8 unk_08;
    u8 unk_09[3];
    void* unk_0C;
    void* unk_10;
    u8* unk_14;
} UnkStruct_080A1A44_Args;

typedef struct UnkStruct_080A1B4C {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} UnkStruct_080A1B4C;

typedef struct UnkStruct_08099CDC_Args {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C;
    u8* unk_10;
} UnkStruct_08099CDC_Args;

typedef struct UnkStruct_080A18F4 {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    s32 unk_10[4];
    s32 unk_20[4];
    s32 unk_30;
    s32 unk_34[4];
    s32 unk_44[4];
    s32 unk_54[4];
    s32 unk_64;
    s32 unk_68;
    s32 unk_6C[4];
    s32 unk_7C[4];
    u16 unk_8C[4];
    s8 unk_94;
    u8 unk_95;
    u8 unk_96;
    u8 unk_97;
    u8 unk_98[0x14];
} UnkStruct_080A18F4;

typedef struct UnkStruct_0809A368_Args {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} UnkStruct_0809A368_Args;

typedef struct UnkStruct_080A5490 {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    UnkStruct_080038C8* unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u8 unk_1C;
    u8 unk_1D;
    u8 unk_1E[0x02];
    s32 unk_20[10];
    s32 unk_48[10];
    s32 unk_70[10];
    u8 unk_98[10];
    u8 unk_A2;
    u8 unk_A3;
} UnkStruct_080A5490;

typedef struct UnkStruct_080A5490_Args {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} UnkStruct_080A5490_Args;

typedef struct UnkStruct_080A6838_Args {
    void* unk_00;
    u16 unk_04;
    s16 unk_06;
    s16 unk_08;
    u8 unk_0A;
    u8 unk_0B;
    u16* unk_0C;
} UnkStruct_080A6838_Args;

typedef struct UnkStruct_080A1DAC_Frame {
    u16 unk_00;
    u16 unk_02;
} UnkStruct_080A1DAC_Frame;

typedef struct UnkStruct_080A1DAC_Desc {
    void** unk_00;
    u8* unk_04;
    void* unk_08;
    u16 unk_0C;
    u16 unk_0E;
    u8 unk_10[0x04];
    UnkStruct_080A1DAC_Frame* unk_14;
    u8 unk_18;
    s8 unk_19;
} UnkStruct_080A1DAC_Desc;

typedef struct UnkStruct_080A1DAC_Entry {
    u8 unk_00[0x02];
    u16 unk_02;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C[0x04];
} UnkStruct_080A1DAC_Entry;

typedef struct UnkStruct_080A1DAC {
    UnkStruct_080A1DAC_Entry* unk_00;
    u8 unk_04[0x08];
    u16 unk_0C;
    u16 unk_0E;
    u8 unk_10[0x02];
    u8 unk_12;
    u8 unk_13;
    u8 unk_14;
    u8 unk_15;
    u8 unk_16;
} UnkStruct_080A1DAC;

extern UnkStruct_080A1DAC_Desc* gUnk_09EE79B4[];

typedef struct UnkStruct_080991F8_Args {
    u32 unk_00;
    u8* unk_04;
} UnkStruct_080991F8_Args;

typedef struct UnkStruct_080991F8 {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C[0x18];
    s32 unk_24;
    s32 unk_28;
    u8 unk_2C;
    u8 unk_2D;
    u8 unk_2E[0x02];
    u8* unk_30;
    u8 unk_34;
} UnkStruct_080991F8;

typedef struct UnkStruct_08F7CF18 {
    void* unk_00;
    void** unk_04;
    u16 unk_08;
    u16 unk_0A;
} UnkStruct_08F7CF18;

extern UnkStruct_08F7CF18 gUnk_08F7CF18[];

typedef struct UnkStruct_080984E4 {
    u8 unk_00[0x08];
    UnkStruct_080038C8* unk_08;
    u8 unk_0C[0x14];
    s32 unk_20;
    u8 unk_24[0x0A];
    u16 unk_2E;
    u16 unk_30;
} UnkStruct_080984E4;

typedef struct UnkStruct_080A3F5C_Sel {
    s32 unk_00;
    s32 unk_04;
    u16 unk_08;
    u8 unk_0A;
} UnkStruct_080A3F5C_Sel;

typedef struct UnkStruct_080A3F5C_Entry {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    u8 unk_10;
    u8 unk_11;
    u8 unk_12[0x02];
} UnkStruct_080A3F5C_Entry;

extern UnkStruct_080A3F5C_Entry* gUnk_09EE45DC[];

typedef struct UnkStruct_080A3F5C {
    void* unk_000;
    void* unk_004;
    void* unk_008;
    void* unk_00C;
    void* unk_010;
    void* unk_014;
    void* unk_018;
    UnkStruct_080038C8* unk_01C;
    u8 unk_020[0x50];
    u8 unk_070[0x50];
    s32 unk_0C0;
    u8 unk_0C4[0x18];
    u8 unk_0DC[0x18];
    u8 unk_0F4[0x18];
    s32 unk_10C;
    u8 unk_110[0x03];
    u8 unk_113;
    UnkStruct_080A3F5C_Sel* unk_114;
    s32 unk_118;
    s32 unk_11C;
    s32 unk_120;
    s32 unk_124;
    s32 unk_128;
    void* unk_12C;
    void* unk_130;
    void* unk_134;
    u8 unk_138[0x05];
    u8 unk_13D;
    s16 unk_13E;
    u8 unk_140;
    u8 unk_141;
    u8 unk_142;
    u8 unk_143;
    u8 unk_144;
    u8 unk_145;
    u8 unk_146[0x02];
    u8 unk_148;
    u8 unk_149;
    u8 unk_14A[0x02];
    u8 unk_14C;
} UnkStruct_080A3F5C;
extern u16 gUnk_09033C98[];
extern u16 gUnk_09033CA0[];
extern s32 gUnk_09033CE0[];
extern s32 gUnk_09033CF0[];
extern s32 gUnk_09033CD0[];

typedef struct UnkStruct_08094CE4_A {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x10];
    u16 unk_18;
} UnkStruct_08094CE4_A;

typedef struct UnkStruct_08094CE4_B {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x0C];
    u16 unk_14;
} UnkStruct_08094CE4_B;

extern void* gUnk_0203A860[];
extern void* gUnk_09EE981C[];
extern u8 gUnk_0940F938[];
extern s16 gUnk_090361B0[];
extern s16 gUnk_090361B8[];
extern s16 gUnk_090361C0[];

typedef struct UnkStruct_08083930 {
    CardDef* unk_00;
    CardBack* unk_04;
    s32* unk_08;
    u8 unk_0C[0x18];
    s32 unk_24;
    u16 unk_28;
    u16 unk_2A;
    u16 unk_2C;
    u8 unk_2E;
    u8 unk_2F;
    u8 unk_30;
    u8 unk_31;
    u8 unk_32;
    u8 unk_33;
    u8 unk_34;
} UnkStruct_08083930;

extern u8 gUnk_08F7DAC4[];
extern CardBack gUnk_08F70A28[];
extern s16 gUnk_0903595E[];
extern s16 gUnk_09035964[];
extern s32 gUnk_09033D28[];

typedef struct UnkStruct_08084D78 {
    u16 unk_00[0x0A];
    u16 unk_14;
    u16 unk_16;
    u16 unk_18;
    u8 unk_1A[0x02];
    u16* unk_1C;
} UnkStruct_08084D78;

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
void func_0807B410(void* pool);
void func_080933D8(UnkStruct_080933D8* p);
u8 func_0807B60C(void);
u8 func_08081888(void);
Deck* func_08083D7C(void);
u16 func_08078754(UnkStruct_08078754* w, u8 n);
u8 func_0809C448(u8* work, void* a);
u8 func_0807BE54(UnkStruct_02034AAC* p, void* a);
u8 func_08088EB4(u8* work, void* a);
void func_08078330(CardSlot* slots, s32 deckIndex);
u8 func_0807CBC0(UnkStruct_02034AAC* p, void* a);
u8 func_0807D930(UnkStruct_02034AAC* p, void* a);
u8 func_08094934(u8* work, void* a);
u8 SpotLight_1(UnkStruct_08097A14* w, void* a);
u8 func_08098FDC(u8* work);
void func_0809A4E0(u8* work, u8 kind);
void func_08090100(UnkStruct_0808E890* n);
u8 Card_EFFECT_1(UnkStruct_08099E70* w);
void func_0809D1FC(u8 bg);
u8 func_080A3640(u8* work, void* a);
u8 func_08083B20(UnkStruct_08083B20* w, u8 b);
void func_08097390(u8* work);
void func_080999A4(u8* work);
u8 StockInfo_1(u8* work, void* a);
void func_08090A54(UnkStruct_02034AAC* p, void* a);
u8 func_0809438C(u8* work, void* a);
void func_080A6E3C(u8* work);
void func_080AA328(u8* work);
void func_08083F08(u8 kind, u16* out);
void func_0808E364(u8* work, u8 kind);
void func_08096638(PrizeCardWork* w);
void func_080978B0(UnkStruct_080978B0* w);
void func_08099928(UnkStruct_08099928* w);
void func_08097834(PrizeCardWork* w);
void PrizeBoss_3(u8* work);
u8 func_0809C710(u8* work, void* a);
void func_080AAA8C(u8* work, u8 kind);
u8 func_0808FA0C(u8* work, void* a);
void func_0807FAD8(UnkStruct_08080268* w);
void func_08085160(void);
void func_08090ACC(UnkStruct_02034AAC* p, void* a);
u8 func_0809486C(u8* work, void* a);
void SpotLight_0(UnkStruct_08097A14* w, u8* src);
u8 func_08099048(u8* work, void* a);
u8 func_0809ACDC(u8* work);
u8 func_0809C4B0(u8* work, void* a);
void func_0809D87C(u16 a, u16 b, u16 c, u16 bits);
void func_080A09C0(u16 n, u16* out);
u8 func_080A5F70(u8* work, void* a);
u8 func_08097600(u8* work);
u8 func_0809CBF8(u8* work, void* a);
void func_0807B668(UnkStruct_02039DD4* p);
u8 func_080A6474(u8* work, void* a);
void func_080855C8(void);
u8 RELOAD_1(u8* work, void* a);
u8 func_08099C4C(u8* work);
void func_080A1BB8(UnkStruct_080A1C48* w, void** t);
void Mode_riku_deckTutorial_1(void);
void func_0807A6C8(UnkStruct_08080268* w);
u8 func_0807B578(u8* work, void* a);
void func_0807FA44(UnkStruct_08080268* w);
u8 func_080829D0(UnkStruct_02034AAC* p, void* a);
void card_enemy_0(UnkStruct_02034AAC* p, UnkStruct_08090244* a);
void func_080A3A04(u8* work);
void card_not_have_2(UnkStruct_02034AAC* p);
u8 func_0809C078(u8* work, void* a);
void func_0809D900(u16 a, u16 b, u16 c, u32 v);
void func_080A69A0(u8* work);
void func_080A99A0(u8* work);
void func_08078D98(u8* work, u8 kind, u8 c);
u8 func_0807CB24(UnkStruct_02034AAC* p, void* a);
u8 card_enemy_1(UnkStruct_02034AAC* p, void* a);
void func_080A6BB4(u8* work);
void func_080A6B40(u8 a, u8 b);
void func_080A9AE8(u8* work);
u8 func_0807D4E4(UnkStruct_02034AAC* p);
u8 func_08082F50(UnkStruct_02034AAC* p);
void func_0808CD48(u8* work);
void Mode_Premire_0(void);
void func_080A1DAC(UnkStruct_080A1DAC* w);
u8 func_080A207C(UnkStruct_080A1DAC* w);
u8 func_080A5C9C(u8* work, void* a);
void func_080837FC(UnkStruct_02034AAC* p);
u8 map_anim_1(UnkStruct_08083B94* w);
u8 Mapcard_1(u8* work, void* a);
void RELOAD_0(UnkStruct_080991F8* w, UnkStruct_080991F8_Args* a);
void func_0809C1EC(u8* work);
void NO_Card_2(UnkStruct_02034AAC* p);
void func_080851E4(u8 deck);
void func_0807A75C(UnkStruct_08080268* w);
u8 func_0807BA54(void);
u8 func_0807CE9C(UnkStruct_02034AAC* p);
u8 func_08082B48(UnkStruct_02034AAC* p);
void func_08085518(u16* p, u8 deck);
void func_0808D4E4(u8 kind, u8 slot);
u8 func_080909A4(UnkStruct_02034AAC* p);
u8 func_080A6A38(u8* work);
u8 func_080A9A38(u8* work);
void func_080AA148(u8 kind, u8 slot);
void Ev_mapObj_2(UnkStruct_080A1C48* w);
void func_080984E4(UnkStruct_080984E4* w);
u8 card_reload_1(UnkStruct_02034AAC* p, void* a);
void func_0808E7D8(u8* work);
u8 func_080947B4(u8* work, void* a);
u8 func_080A63B8(u8* work, void* a);
s16 func_080859A0(s32 mode, Deck* d);
u8 func_080A3DD0(UnkStruct_080A3F5C* w);
u8 func_08098AE4(u8* work, void* a);
void DeckCard2_2(UnkStruct_0808E890* n);
void func_08081760(UnkStruct_02034AAC* p);
void func_08094CE4(u8* work);
void func_0808D0A4(u8 deck);
void func_080A9E40(u8 deck);
void func_080A6C50(u8 deck);
u8 func_0809B840(u8* work);
u8 func_0809B9F4(u8* work);
u8 DeckCard2_1(UnkStruct_0808E890* n);
void func_080A676C(u8* work);
void func_08078914(UnkStruct_08078754* w, u8 n);
u8 func_08082154(UnkStruct_02034AAC* p, void* a);
void Bosscard_0(UnkStruct_08083930* w, u32* a);
void func_080985A0(UnkStruct_08098670* w, u16 b, s16 c, s16 d);
void func_08085448(u16 slot);
u8 func_0807C3E8(UnkStruct_02034AAC* p, void* a);
u8 func_0808E934(u8* work, s16 x, s16 y, u16 dir);
void Mapcard_0(MapcardWork* w, MapcardArgs* a);
Deck* func_08083C94(void);
u8 func_08085374(u16 card, u8 deck);
void func_08084D78(UnkStruct_08084D78* out, u8 deck, u8 mode);
void func_080AB228(void);
u16 func_08093384(u8* work);
void LVUP_EFFECT_0(UnkStruct_080A18F4* w, UnkStruct_080A1A44_Args* a);
void Deck_Clear_0(UnkStruct_080A2F54* w, u8* a);
void Deck_Yes_No_0(UnkStruct_080A2F54* w, u8* a);
void LVUP_EFFECT_2(UnkStruct_080A18F4* w);
u8 func_0809CB0C(u8* work, void* a);
void Lvup_Logo_0(UnkStruct_080A18F4* w, UnkStruct_080A1A44_Args* a);
void func_080A32DC(u8* p);
void func_0807F99C(UnkStruct_08080268* w);
u8 func_080A1B4C(UnkStruct_080A1B4C* p, void* pool);
u8 func_080A3E8C(UnkStruct_080A3F5C* w, void* a);
u8 func_080A5EA0(u8* work, void* a);
void func_080A4C1C(u8* work);
void func_080A53E4(u8* work);
void func_08090864(UnkStruct_02034AAC* p);
void func_08099CDC(u8* work);
void func_0809C110(u8* work);
void func_0809CE88(u8* work, s16* a);
void func_0809CF64(u8* work, s16* a);
void RELOAD_CHILDREN_2(UnkStruct_08098BE8* w);
u8 func_080AADD4(u8* work, s16 x, s16 y, u16 dir);
u8 func_08090550(UnkStruct_02034AAC* p, void* a);
u8 func_08085290(u16 card);
void func_08084AC8(u16 a);
void func_08085A58(s32 a, u16* out);
void func_080A2E14(u8* work);
u8 func_0808CA78(u8* work, u8 a);
void func_0808C2F0(u8* work);
void HCEffectName_2(UnkStruct_0809DF7C* w);
u8 func_080A3558(UnkStruct_080A3F5C* w, void* a);
void func_08090B50(UnkStruct_02034AAC* p, void* a);
void RELOAD_CHILDREN_0(UnkStruct_08098BE8* w, UnkStruct_080988C0_Args* a);
u8 Bosscard_1(u8* work, void* a);
void func_08094548(u8* work);
u8 func_08099B60(u8* work, void* a);
void func_08083714(UnkStruct_08083B20* w);
void func_080836C4(UnkStruct_08095A5C* p, void* a, u8 b, s8 c);
u8 func_08082A64(UnkStruct_02034AAC* p, void* a);
void func_0808E3E0(u8* work);
u8 func_080A18F4(UnkStruct_080A18F4* w);
u8 func_0809753C(u8* work, void* a);
void func_0809B76C(u8* work, void** src);
void func_0809B920(u8* work, void** src);
void func_0808D438(u8 kind, u8 slot);
u8 func_0807BD64(UnkStruct_02034AAC* p, void* a);
u8 func_0807D3A0(UnkStruct_02034AAC* p, void* a);
u8 func_08082E0C(UnkStruct_02034AAC* p, void* a);
u8 func_08090DB0(UnkStruct_02034AAC* p, void* a);
void card_reload_0(UnkStruct_02034AAC* p, UnkStruct_08090244* a);
void func_08091048(UnkStruct_02034AAC* p, UnkStruct_08090244* a);
void func_0807DAD0(UnkStruct_02034AAC* p);
u8 func_080987C0(u16 n);
void Reload_Card_0(UnkStruct_02034AAC* p, UnkStruct_08090244* a);
void func_08091138(UnkStruct_02034AAC* p, UnkStruct_08090244* a);
u8 func_0809C620(u8* work, void* a);
u8 EV_BG_EFFECT_1(UnkStruct_080A1DAC* w, void* a);
void func_0809C534(UnkStruct_0809C534* w, UnkStruct_0809C534_Args* a);
void Card_EFFECT_0(UnkStruct_08099E70* w, UnkStruct_08099CDC_Args* a);
void deckexchange_3(u8* work);
void func_0807BB04(void);
void func_080818E4(void);
u8 func_0809DA64(s32 a, u16 n);
void StockInfo_0(u8* work, void* a);
u8 func_080A3754(UnkStruct_080A3F5C* w, void* a);
u8 func_08082C98(UnkStruct_02034AAC* p, void* a);
u8 Reload_Card_1(UnkStruct_02034AAC* p, void* a);
u8 func_0808686C(u8* work, void* a);
u8 func_0807C4BC(UnkStruct_02034AAC* p, void* a);
u8 func_080A5034(UnkStruct_080A3F5C* w, void* a);
u8 func_0808E474(UnkStruct_0808DB04* w);
u8 func_080A3A98(UnkStruct_080A3F5C* w, void* a);
u8 func_08082224(UnkStruct_02034AAC* p, void* a);
u8 func_08081B70(UnkStruct_02034AAC* p, void* a);
u8 func_0807D68C(UnkStruct_02034AAC* p, void* a);
u8 func_0808A7E4(u8* work, void* a);
u8 func_080A5198(UnkStruct_080A3F5C* w, void* a);
void func_080A52BC(UnkStruct_080A3F5C* w);
void func_080A6D0C(void);
void func_080A5490(UnkStruct_080A5490* w, UnkStruct_080A5490_Args* a);
void func_0807BC24(UnkStruct_02034AAC* p, UnkStruct_08090244* a);
void func_08081A3C(UnkStruct_02034AAC* p, UnkStruct_08090244* a);
u8 RELOAD_CHILDREN_1(u8* work, void* a);
u8 func_0807CFA8(UnkStruct_02034AAC* p, void* a);
u8 func_08097404(u8* work, void* a);
u8 func_080824C8(UnkStruct_02034AAC* p, void* a);
u8 func_0809423C(u8* work, void* a);
u8 func_08099A18(u8* work, void* a);
void HCEffectName_0(UnkStruct_0809DF7C* w, u8* a);
u8 func_08082348(UnkStruct_02034AAC* p, void* a);
u8 func_0809C2D0(u8* work, void* a);
u8 func_08090C3C(UnkStruct_02034AAC* p, void* a);

#endif /* GUARD_CARD_H */
