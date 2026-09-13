#include "system_state.h"
#ifndef GUARD_CARD_H
#define GUARD_CARD_H

#include "chara_link_state.h"

#include "msg_types.h"

#include "field_state.h"

#include "card_ui_types.h"
#include "card_ui_state.h"

#include "obj_resource_types.h"

#include "card_api.h"

#include "card_deck.h"
#include "card_state.h"

#include "types.h"
#include "game_state.h"
#include "text_types.h"
#include "obj.h"
#include "taskpool.h"
#include "listpool.h"
#include "card_types.h"
#include "fld_types.h"
#include "game.h"
#include "mode.h"

void func_080A0944(u16 a, u16* p);
void func_080A096C(u16 a, u16* p);

#define CARD_ID_MASK 0xFFF

#ifdef VERSION_EU
#define CARDWORK(off) ((off) + 4)
#else
#define CARDWORK(off) (off)
#endif

extern CardDef gCardDefs[];

typedef struct CardDisplayWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    u8 unk_10[0x04];
    void* palette;
    void* unk_18;
    u8 unk_1C[0x04];
    void* unk_20;
    u8 unk_24[0x14];
    ListPool* unk_38;
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
    ListNode unk_64;
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
} CardDisplayWork;
extern u8 gTaskDescMapSelect[];
extern u8 gTaskDescPrizeCardInit[];
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
typedef struct CardListWork {
    ListPool cards;
    struct UnkStruct_0809C534* selectedCard;
    TaskPool effectTasks;
    u8 effectCount;
    u8 unk_29;
    u8 unk_2A[2];
} CardListWork;

typedef char CardListWork_size[(sizeof(CardListWork) == 0x2C) ? 1 : -1];

extern u8 gUnk_081283C0[];
extern void** gUnk_09EEA28C;
extern vu16 gSystemFlags;
extern Mode gModeSioChgCard;
extern Mode gModeBattle;
extern u8 gTaskDescPrizeCardInitBoss[];
extern u8 gTaskDescPrizeBoss[];
extern u8 gTaskDescDispCardname[];
extern u8 gTaskDescVersion[];
extern u8 gUnk_09EE7650[];
extern u8 gTaskDescEVBGEFFECT[];
extern u8 gTaskDescWorldSelBefore[];
extern u8 gTaskDescREVCOUNT[];
extern u8 gTaskDescScrollbar[];
extern u8 gUnk_09EE77A4[];
extern u8 gUnk_09EE77BC[];
extern u8 gUnk_09EE781C[];
extern u8 gTaskDescHCEffectName[];
extern u8 gTaskDescLevelUp[];
extern u8 gUnk_09402F78[];
extern u8 gUnk_09614118[];
extern u8 gUnk_096142F8[];
extern u8 gUnk_05000160[];
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

typedef struct UnkStruct_0807FA0C {
    u8 unk_00[0x14];
    void* unk_14;
    void* unk_18;
    u8 unk_1C[0x28];
    void* unk_44[0x04];
} UnkStruct_0807FA0C;

typedef struct EventMapObjectWork {
    u8 unk_00[0x04];
    void* tiles[0x0A];
    void* palettes[0x0A];
    u8 unk_54[0x04];
    void* definition;
} EventMapObjectWork;

struct MapCardDef;
struct MapCardBackDef;

typedef struct UnkStruct_08096F94 {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    void* unk_14;
    void* unk_18;
    void* unk_1C;
    struct MapCardDef* unk_20;
    struct MapCardBackDef* unk_24;
    TaskPool unk_28;
    u16 unk_3C;
    u16 unk_3E;
    s32 unk_40;
    u8 unk_44[0x2C];
    u8 unk_70;
    u8 unk_71[0x2F];
    s32 unk_A0;
    s32 unk_A4;
    s32 unk_A8;
    s32 unk_AC;
    s32 unk_B0;
    s32 unk_B4;
    s32 unk_B8;
    s32 unk_BC;
    s32 unk_C0;
    s32 unk_C4;
    s16 unk_C8;
    s16 unk_CA;
    u16 unk_CC;
    s16 unk_CE;
    s16 unk_D0;
    s16 unk_D2;
    s16 unk_D4;
    s16 unk_D6;
    s16 unk_D8;
    s16 unk_DA;
    u16 unk_DC;
    u8 unk_DE;
    u8 unk_DF;
    u8 unk_E0;
    u8 unk_E1;
    u8 unk_E2;
    u8 unk_E3;
    u8 unk_E4;
    u8 unk_E5;
    u8 unk_E6;
    u8 unk_E7;
    u8 unk_E8;
} UnkStruct_08096F94;

typedef char UnkStruct_08096F94_sizechk[(sizeof(struct UnkStruct_08096F94) == 0xEC) ? 1 : -1];

typedef struct UnkStruct_02034B38 {
    s8 unk_00;
    u8 unk_01;
    u16 unk_02;
    u16 unk_04;
    u8 unk_06[0x02];
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    void* unk_14;
    void* unk_18;
    void* unk_1C[3];
    void* unk_28;
    void* unk_2C;
    void* unk_30;
    void* unk_34;
    void* unk_38;
    void* unk_3C;
    void* unk_40;
    void* unk_44;
    void* unk_48;
    AnimState unk_4C;
    s32 unk_64;
    u16 unk_68;
    u8 unk_6A[0x02];
} UnkStruct_02034B38;

typedef struct UnkStruct_0809B200 {
    u8 unk_000[0x30];
    void* unk_030[1];
} UnkStruct_0809B200;

typedef struct UnkStruct_0809A02C {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    void* unk_14;
    void* unk_18;
    CardDef* unk_1C;
    TaskPool unk_20;
    u8 unk_34[0x04];
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
    s32 unk_44;
    u8 unk_48[0xFC];
    u8 unk_144[0x2C];
    u8 unk_170;
    u8 unk_171[0x2F];
    s32 unk_1A0;
    s32 unk_1A4;
    s32 unk_1A8;
    s32 unk_1AC;
    s32 unk_1B0;
    s32 unk_1B4;
    s16 unk_1B8;
    s16 unk_1BA;
    s16 unk_1BC;
    s16 unk_1BE;
    s16 unk_1C0;
    u16 unk_1C2;
    u16 unk_1C4;
    u8 unk_1C6;
    u8 unk_1C7;
    u8 unk_1C8;
    u8 unk_1C9;
    u8 unk_1CA;
    u8 unk_1CB;
    u8 unk_1CC;
    u8 unk_1CD;
    u8 unk_1CE;
    u8 unk_1CF;
    u16 unk_1D0;
} UnkStruct_0809A02C;

typedef char UnkStruct_0809A02C_sizechk[(sizeof(struct UnkStruct_0809A02C) == 0x1D4) ? 1 : -1];

typedef char CardStat_sizechk[(sizeof(struct CardStat) == 0x18) ? 1 : -1];

typedef struct UnkStruct_080993D4 {
    u8 unk_000[0xE4];
    s16 unk_0E4;
} UnkStruct_080993D4;

typedef struct RevCountArgs {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C;
    u8 unk_0D;
    u8 unk_0E[0x02];
} RevCountArgs;

typedef struct RevCountWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    AnimState unk_0C;
    u8 unk_24;
    u8 unk_25;
    u16 unk_26;
    u8 unk_28;
    u8 unk_29[0x03];
    RevCountArgs unk_2C;
    s32 unk_3C;
    s32 unk_40;
} RevCountWork;

typedef char UnkStruct_08098CE4_sizechk[(sizeof(struct RevCountWork) == 0x44) ? 1 : -1];

typedef struct UnkStruct_09EE7D84 {
    void** unk_00;
    u8 unk_04;
} UnkStruct_09EE7D84;

typedef struct UnkStruct_02034AFC {
    u8 unk_000[0x10C];
    u64 unk_10C;
    u8 unk_114[0x28];
    s16 unk_13C;
    u8 unk_13E[0x07];
    u8 unk_145;
    u8 unk_146[0x08];
    u8 unk_14E;
    u8 unk_14F;
} UnkStruct_02034AFC;

extern UnkStruct_09EE7D84* gUnk_09EE7D84[];
extern s16 gUnk_09037FBA[];
extern s32 gUnk_09037FFC[];
extern s32 gUnk_0903800C[];
extern u16 gUnk_0903801C[];
extern u16 gUnk_09EE48F4[];
extern u8 gUnk_09EE496C[];
extern u8 gUnk_09EE499C[];
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
extern u8 gUnk_093FBAB8[][0x80];
extern void* gUnk_09EF12C8[];
extern u8 gUnk_09EE4B28[];
extern u8 gUnk_09619178[];
typedef struct WorldSelAnim {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02[0x2];
} WorldSelAnim;

extern WorldSelAnim gUnk_09EE8E60[];
extern u8 gUnk_093FB1AC[];
extern u8 gUnk_09619378[];
extern u8 gUnk_093FB0CC[];
extern s32 gUnk_09033D08[][2];
extern s32 gUnk_09041E80[];
extern s32 gUnk_09041E9C[];
extern s16 gUnk_09041EB4[];
extern s16 gUnk_09041F30[];
extern s16 gUnk_09041F34[];
extern u16 gUnk_09041F3E[];
extern s16 gUnk_09041EBA[];
extern u16 gUnk_09041EEE[];
extern s16 gUnk_09041F04[];
extern s16 gUnk_09041F1A[];
extern s16 gUnk_09041F0A[];
extern u8 gUnk_093F7C9C[];
extern u8 gUnk_08159E18[];
extern u8 gUnk_08159F38[];
extern u8 gUnk_08159FBC[];
extern u8 gUnk_0815C204[];
extern u8 gUnk_0815C1C2[];
extern u8 gUnk_08159E10[];
extern u8 gUnk_09EEB008[];
extern u8 gUnk_09EEB03C[];
extern u8 gUnk_090A4664[];
extern u8 gUnk_09614418[];
extern u8 gUnk_09614438[];
extern u8 gUnk_093F8C8E[];
extern u8 gUnk_09985F44[];
extern u8 gUnk_099597E4[];
extern u8 gUnk_09EEFCAC[];
extern u8 gUnk_09EEFD38[];
extern u8 gUnk_09320796[];
extern u8 gUnk_08F69BE4[];
extern u8 gUnk_09EE7FD8[];
extern u8 gUnk_09EE7FA8[];

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

typedef struct DeckCard2Work {
    u8 unk_00[0x04];
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    CardDef* unk_14;
    CardBack* unk_18;
    ListPool* unk_1C;
    u16 unk_20;
    s16 unk_22;
    s16 unk_24;
    u8 unk_26;
    u8 unk_27;
    void* unk_28;
    ListNode unk_2C;
    s32 unk_40;
    s32 unk_44;
    u16 unk_48;
    u8 unk_4A;
    u8 unk_4B[0x02];
    u8 unk_4D;
} DeckCard2Work;

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
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    void* unk_14;
    void* unk_18;
    void* unk_1C;
    void* unk_20;
    void* unk_24;
    void* unk_28;
    u8 unk_2C[0x18];
    void* unk_44;
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
    ListNode unk_58;
    s16 unk_6C;
    s16 unk_6E;
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
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    void* unk_14;
    void* unk_18;
    void* unk_1C;
    void* unk_20;
    void* unk_24;
    TextSlot unk_28[8];
    TextSlot unk_68[8];
    TextSlot unk_A8[8];
    u8 unk_E8[0x3D4];
    void* unk_4BC;
    u8 unk_4C0[0xC];
    struct UnkStruct_08084D78* unk_4CC;
    struct UnkStruct_08084D78* unk_4D0;
    void* unk_4D4;
    void* unk_4D8;
    void* unk_4DC;
    u8 unk_4E0[8];
    void* unk_4E8;
    void* unk_4EC;
    u8 unk_4F0[4];
    u8 unk_4F4[0x120];
    TaskPool unk_614;
    TaskPool unk_628;
    ListPool unk_63C;
    AnimState unk_64C;
    AnimState unk_664;
    u8 unk_67C[0x18];
    s32 unk_694;
    s32 unk_698;
    s32 unk_69C;
    s32 unk_6A0;
    u8 unk_6A4[0x14];
    s32 unk_6B8;
    s32 unk_6BC;
    u8 unk_6C0[0xE];
    u16 unk_6CE;
    s16 unk_6D0;
    s16 unk_6D2;
    s16 unk_6D4;
    s16 unk_6D6;
    s16 unk_6D8;
    s16 unk_6DA;
    s16 unk_6DC;
    s16 unk_6DE;
    u16 unk_6E0;
    u8 unk_6E2[0xA];
    s16 unk_6EC;
    s16 unk_6EE;
#ifdef VERSION_EU
    u8 unk_6F0[0x168];
#else
    u8 unk_6F0;
    u8 unk_6F1[3];
    u8 unk_6F4;
    u8 unk_6F5;
    u8 unk_6F6;
    u8 unk_6F7;
    u8 unk_6F8;
    u8 unk_6F9;
    u8 unk_6FA;
    u8 unk_6FB[5];
    u8 unk_700;
    u8 unk_701;
    u8 unk_702;
    u8 unk_703;
    u8 unk_704;
    u8 unk_705;
    u8 unk_706;
    u8 unk_707[6];
    u8 unk_70D;
    u8 unk_70E[2];
    u8 unk_710;
    u8 unk_711[3];
    u8 unk_714;
    u8 unk_715;
    u16 unk_716;
    u8 unk_718[0x13C];
#endif
    s32 unk_854;
    u8 unk_858[0x54];
    s16 unk_8AC;
    s16 unk_8AE;
} UnkStruct_0808C940;

typedef char UnkStruct_0808C940_sizechk[(sizeof(struct UnkStruct_0808C940) ==
#ifdef VERSION_EU
    0x8B4
#else
    0x8B0
#endif
) ? 1 : -1];

typedef struct UnkStruct_0808E2F0 {
    u16 unk_00[0x0B];
    u16 unk_16;
    u8 unk_18[0x04];
    u16* unk_1C;
} UnkStruct_0808E2F0;

typedef struct UnkStruct_080AAB08 {
    u8 unk_000[0x4CC];
    UnkStruct_0808E2F0* unk_4CC;
    u8 unk_4D0[0x1FC];
    u16 unk_6CC;
    u8 unk_6CE[2];
    s16 unk_6D0;
    u16 unk_6D2;
} UnkStruct_080AAB08;

typedef struct UnkStruct_080A6FAC {
    u8 unk_000[0x18];
    void* unk_018;
    void* unk_01C;
    void* unk_020;
    void* unk_024;
    void* unk_028;
    void* unk_02C;
    u8 unk_030[0x3BC];
    void* unk_3EC;
    void* unk_3F0;
    void* unk_3F4;
    u8 unk_3F8[0x10];
    void* gfx;
    u8 unk_40C[0x28];
    ListPool unk_434;
    AnimState unk_444;
    AnimState unk_45C;
    AnimState anim;
    u8 unk_48C[0x3C];
    s16 unk_4C8;
    s16 unk_4CA;
    u8 unk_4CC[0x3F];
    u8 unk_50B;
} UnkStruct_080A6FAC;

typedef struct UnkStruct_0808DB04 {
    u8 unk_000[0x18];
    void* unk_018;
    void* unk_01C;
    void* unk_020;
    void* unk_024;
    void* unk_028;
    u8 unk_02C[0x04];
    void* unk_030;
    void* unk_034;
    u8 unk_038[0x484];
    void* unk_4BC;
    void* unk_4C0;
    u8 unk_4C4[0x10];
    UnkStruct_0808E2F0* unk_4D4;
    UnkStruct_0808E2F0* unk_4D8;
    void* unk_4DC;
    void* unk_4E0;
    void* unk_4E4;
    u8 unk_4E8[0x10];
    void* gfx;
#ifdef VERSION_EU
    u8 unk_4FC[0x2D0];
#else
    u8 unk_4FC[0x2CC];
#endif
    TaskPool unk_7C8;
    TaskPool unk_7DC;
    ListPool unk_7F0;
    AnimState unk_800;
    AnimState unk_818;
    AnimState anim;
    s32 unk_848;
    s32 unk_84C;
    s32 unk_850;
    s32 unk_854;
    u8 unk_858[0x1C];
    s16 unk_874;
    s16 unk_876;
    s16 unk_878;
    u8 unk_87A[0x06];
    u16 unk_880;
    u8 unk_882[0x02];
    s16 unk_884;
    u16 unk_886;
    u8 unk_888[0x0C];
    s16 unk_894;
    s16 unk_896;
    u16 unk_898;
    u8 unk_89A[8];
    u16 unk_8A2;
    u16 unk_8A4;
    u16 unk_8A6;
    u16 unk_8A8;
    u8 unk_8AA[2];
    u8 unk_8AC;
    u8 unk_8AD[0x04];
    u8 unk_8B1;
    u8 unk_8B2[0x03];
    s8 unk_8B5;
    s8 unk_8B6;
    u8 unk_8B7;
    u8 unk_8B8[0x08];
    u8 unk_8C0;
    u8 unk_8C1;
    u8 unk_8C2[0x05];
    u8 unk_8C7;
    u8 unk_8C8[0x08];
    u8 unk_8D0;
    u8 unk_8D1[0x03];
    u16 unk_8D4;
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
    CardDisplayWork* unk_1C[3];
    CardDisplayWork* unk_28[3];
    CardDisplayWork* unk_34[4];
    CardDisplayWork* unk_44[4];
    ListPool unk_54[4];
    u16 unk_94[4];
    u16 unk_9C[4];
    s16 unk_A4;
    s16 unk_A6;
    u16 unk_A8[4];
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

typedef struct HcEffectNameWork {
    s16 unk_00;
    u8 unk_02[0x06];
    void* unk_08;
    void* unk_0C;
    void* palette;
    void* tiles;
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
} HcEffectNameWork;

typedef struct ReloadChildArgs {
    void* unk_00;
    s32* unk_04;
    s32* unk_08;
    u8 unk_0C;
    u8 unk_0D;
    u8 unk_0E;
    u8 unk_0F;
    u8 unk_10[0x04];
} ReloadChildArgs;

typedef struct ReloadChildWork {
    void* tiles;
    void* palette;
    void* unk_08;
    u8 unk_0C[0x04];
    s32* unk_10;
    s32* unk_14;
    u8 unk_18;
    u8 unk_19;
    u8 unk_1A;
    u8 unk_1B;
    u16 unk_1C;
    u8 unk_1E[0x02];
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    u8 unk_2C[0x04];
    ListNode unk_30;
    u8 unk_44;
    u8 unk_45;
    u8 unk_46;
} ReloadChildWork;

typedef char UnkStruct_08098BE8_sizechk[(sizeof(struct ReloadChildWork) == 0x48) ? 1 : -1];

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

typedef struct PremiumCardEffectWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    AnimState unk_0C;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4C;
    s32 unk_50;
} PremiumCardEffectWork;

typedef char PremiumCardEffectWork_sizechk[(sizeof(struct PremiumCardEffectWork) == 0x54) ? 1 : -1];

typedef struct CardNameWork {
    void* unk_00;
    UnkStruct_080038C8* unk_04;
    TextSlot unk_08[32];
    TextSlot unk_108[32];
    TextSlot unk_208[2];
    void* unk_218;
    void* unk_21C;
    s16 unk_220;
    s16 unk_222;
    s16 unk_224;
    u8 unk_226;
    u8 unk_227;
} CardNameWork;

typedef char CardNameWork_sizechk[(sizeof(struct CardNameWork) == 0x228) ? 1 : -1];

typedef struct DarkPointWork {
    void* tiles;
    s32 x;
    u8 unk_08[0x02];
    s8 slideTimer;
    u8 unk_0B;
    u8 hundreds;
    u8 tens;
    u8 ones;
} DarkPointWork;

typedef char DarkPointWork_sizechk[(sizeof(struct DarkPointWork) == 0x10) ? 1 : -1];

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
    CardSlot* unk_44[4];
    u8 unk_54[0x54];
    s16 unk_A8[4];
    s16 unk_B0[4];
    s8 unk_B8;
    u8 unk_B9;
    u8 unk_BA;
    u8 unk_BB;
    u8 unk_BC[4];
    u8 unk_C0[4];
    u8 unk_C4[5];
    u8 unk_C9;
} UnkStruct_08078754;

typedef char UnkStruct_08078754_sizechk[(sizeof(struct UnkStruct_08078754) == 0xCC) ? 1 : -1];

extern MapCardDef gUnk_09EE4C80[];
extern MapCardBackDef gUnk_09EE4BF4[];

typedef struct MapcardWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    u8 unk_10[0x08];
    MapCardDef* unk_18;
    MapCardBackDef* unk_1C;
    u8 unk_20;
    u8 unk_21;
    u8 unk_22[0x06];
    ListPool* unk_28;
    u8 unk_2C[0x0C];
    ListNode unk_38;
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
    s8 unk_64;
    u8 unk_65;
    u8 unk_66[0x02];
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

typedef struct NumberPlusArgs {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
} NumberPlusArgs;

typedef struct NumberPlusWork {
    void* tiles;
    void* palette;
    NumberPlusArgs unk_08;
    s16 unk_24;
    s16 unk_26;
    u8 unk_28;
    u8 unk_29;
} NumberPlusWork;

typedef struct MapTileAnimationFrame {
    u16 tileOffset;
    u8 duration;
    u8 unk_03;
} MapTileAnimationFrame;

typedef struct MapTileAnimationTrack {
    MapTileAnimationFrame* frames;
    u8* tiles;
    u8 frameCount;
    u8 unk_09;
    s16 destOffset;
    u16 copySize;
    u8 unk_0E[0x02];
} MapTileAnimationTrack;

typedef struct MapTileAnimationDef {
    MapTileAnimationTrack* tracks;
    u8 trackCount;
} MapTileAnimationDef;

typedef struct MapTileAnimationWork {
    u8 unk_00;
    u8 frameTimers[8];
    u8 frameIndices[8];
    u8 unk_11[3];
    MapTileAnimationDef* definition;
} MapTileAnimationWork;

typedef struct UnkStruct_09EE752C {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
} UnkStruct_09EE752C;

typedef struct PrizeCardArgs {
    s32 unk_00[8];
} PrizeCardArgs;

typedef struct PrizeCardTaskArgs {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C[0x14];
    s32 unk_20;
} PrizeCardTaskArgs;

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
    u16 unk_14;
    u8 unk_16;
    u8 unk_17;
} ScrollBarWork;

typedef char ScrollBarWork_sizechk[(sizeof(struct ScrollBarWork) == 0x18) ? 1 : -1];

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
    s16 unk_EE;
    s16 unk_F0;
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
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    void* unk_14;
    u8 unk_18[0x04];
    ListPool* unk_1C;
    UnkStruct_08095A5C* unk_20;
    TaskPool unk_24;
    ListPool* unk_38;
    void* unk_3C;
    u32 unk_40;
    u8 unk_44[0x02];
    u8 unk_46;
    u8 unk_47[0x05];
    s32 unk_4C;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    u8 unk_5C[0x08];
    ListNode unk_64;
    u32 unk_78;
    s32 unk_7C;
    s32 unk_80;
    s32 unk_84;
    s32 unk_88;
    s32 unk_8C;
    s32 unk_90;
    s32 unk_94;
    s32 unk_98;
    s16 unk_9C;
    u8 unk_9E;
    u8 unk_9F;
    u8 unk_A0;
    u8 unk_A1;
    u8 unk_A2;
    u8 unk_A3;
    u8 unk_A4[0x04];
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
extern u16 gUnk_0903612C[];
extern u16 gUnk_090359FC[];
extern CardBack gUnk_08F709B0[];
extern UnkStruct_09EE8008 gUnk_09EE8008[];
extern u8 gUnk_09EE8E48[];
extern u8 gUnk_09EE8E30[];
extern u8 gUnk_09EE8E18[];
extern Deck gUnk_09041FA0;
extern u16 gUnk_09041F70[];
extern void* gUnk_09EF7048[];
extern u16 gUnk_09EE4AC8[];
extern u16 gUnk_09EE4AD6[];
extern u16 gUnk_09EE4AE4[];
extern s16 gSineTable[];
extern u32 gUnk_09036210[];
extern s16 gUnk_09036278[];
extern u8 gUnk_0903628A[];
extern void* gUnk_09EE9894[];
extern void* gUnk_09EE98C0[];
extern u8 gUnk_09036380[];
extern u8 gUnk_0891ED26[];
extern u8 gUnk_09EDF38C[];
extern u8 gUnk_09EDF374[];
extern u8 gUnk_088E33C2[];
extern u8 gUnk_09EDEE14[];
extern u8 gUnk_09EDEE08[];
extern u8 gUnk_09036300[];
extern void* gUnk_09EE4724[];
extern u8 gUnk_09EE778C[];
extern u8 gTaskDescBosscard[];
extern void* gUnk_09EF1198[];
extern u8 gUnk_09EF1220[];
extern u8 gUnk_09EF1224[];
extern u8 gUnk_0950C478[];
extern u8 gUnk_09618D38[];
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
extern void* gUnk_09EE75A8[];
extern s32 gUnk_09033FF4[][2];
extern s32 gUnk_09033FA8[];
extern const s32 gUnk_09033FB8[];
extern s32 gUnk_0903401C[][2];
extern s32 gUnk_0903404C[];
extern s16 gUnk_09EE7520[];
extern u8 gUnk_090A261E[];
extern u8 gUnk_096144D8[];
extern u8 gUnk_090A4A0C[];
extern u8 gUnk_090A51F6[];
extern void** gUnk_02034B38;
extern u8 gUnk_096ACA44[];
extern u8 gUnk_096FBA04[];
extern u8 gUnk_096F5464[];
extern u8 gUnk_09628DC0[];
extern u8 gUnk_0962B090[];
extern u8 gUnk_096FBAA4[];
extern u8 gUnk_0962AD62[];
extern u8 gUnk_096FBA44[];
extern void* gUnk_09EF3884[];
extern u8 gUnk_0962B286[];
extern u8 gUnk_096FBA64[];
extern u8 gUnk_0962B8BE[];
extern u8 gUnk_096FBA84[];
extern void* gUnk_09EF38B4[];
extern void* gUnk_09EF3894[];
extern Mode gModeSioBtlConnect;
extern Mode gModeMenuLoad;
extern Mode gModeTitle;
extern void* gUnk_09EF38BC[];
extern void* gUnk_09EF38C8[];

extern u8 gUnk_090451C0[];
extern void* gUnk_09EE4A2C[];
extern u16* gUnk_09EE4A68[];
extern u16* gUnk_09EE4A98[];
extern const u16 gUnk_090356BA[];
extern const u16 gUnk_090356D2[];
extern UnkStruct_09EE752C gUnk_09EE752C[];
extern u8 gUnk_09EEA4E0[];
extern u8 gUnk_09EEA494[];
extern u8 gUnk_09EEB064[];
extern u8 gUnk_09EEB050[];
extern u8 gUnk_09EEB07C[];
extern void* gUnk_09EEB080[];
extern void* gUnk_09EEAFF8;
extern void* gUnk_09EEB000;
extern u8 gUnk_09EEB068[];
extern s16 gUnk_09035950[];
extern s16 gUnk_09035956[];
extern s16 gUnk_090356EC[];
extern s16 gUnk_090356F2[];
extern s16 gUnk_09035702[];
extern s16 gUnk_0903571A[];
extern s16 gUnk_0903571E[];
typedef struct UnkStruct_09035730 {
    s32 unk_00[2];
} UnkStruct_09035730;

extern UnkStruct_09035730 gUnk_09035730;
extern u8 gUnk_093F7172[];
extern u8 gUnk_09508098[];
extern u8 gUnk_09618C58[];
extern u8 gUnk_09619098[];
extern u8 gUnk_08C8C824[];
extern u8 gUnk_08F68A84[];
extern u8 gUnk_08EF4384[];
extern u8 gUnk_09EE7804[];
extern u8 gUnk_09EE7560[];
extern void* gUnk_09EE7578[];
extern u8 gTaskDescReloadChildren[];
extern u8 gUnk_0905F03C[];
extern u8 gUnk_09EE4BB0[];
extern u8 gTaskDescSELMAPEVKEY[];
extern void* gUnk_09EE7698[];
extern void* gUnk_09EE76C0[];
extern void** gUnk_09EE76D0[];
extern u8 gUnk_090A583E[];
extern u8 gUnk_090A418E[];
extern u8 gUnk_090A44C4[];
extern u8 gUnk_090A3E46[];
extern u8 gUnk_096144F8[];
extern u8 gUnk_09516AB8[];
extern u8 gUnk_095132B8[];
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
extern u8 gUnk_09519AB8[];
extern u8 gUnk_0951A2B8[];
extern u8 gUnk_0951AAB8[];
extern u8 gUnk_095172B8[];
extern u8 gUnk_09517AB8[];
extern u8 gUnk_09518AB8[];
extern u8 gUnk_095192B8[];
extern u8 gUnk_09514AB8[];
extern u8 gUnk_09614458[];
extern u8 gUnk_09614478[];
extern u8 gUnk_09614498[];
extern u8 gUnk_096144B8[];
extern u8 gUnk_09614406[];
extern u8 gUnk_08F69BA4[];
extern Deck gUnk_09034084[];
extern u8 gUnk_0905ED36[];
extern u8 gUnk_0905EAE8[];
extern u8 gUnk_09611AB8[];
extern u8 gUnk_0950E2F8[];
extern u8 gUnk_09EDE8CC[];
extern u8 gUnk_09EEF89C[];
extern u8 gUnk_088B6560[];
extern u8 gUnk_092EB78A[];
extern u8 gUnk_09614798[];
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

typedef struct SpotlightWork {
    u8 unk_00;
    u8 unk_01[0x03];
    s32 unk_04;
    s32 unk_08;
    u16 unk_0C;
    u8 unk_0E[0x02];
    u8* unk_10;
    u8 unk_14;
} SpotlightWork;

typedef struct CardEffectWork {
    void* tiles;
    void* palette;
    u8 anim[0x18];
    void* gfx;
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
} CardEffectWork;

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

typedef struct BossPrizeWork {
    UnkStruct_080038C8* unk_00;
    UnkStruct_080038C8* unk_04;
    UnkStruct_080038C8* unk_08;
    UnkStruct_080038C8* unk_0C;
    UnkStruct_080038C8* unk_10;
    UnkStruct_080038C8* unk_14;
    UnkStruct_080038C8* unk_18;
    UnkStruct_080038C8* unk_1C;
    TaskPool unk_20;
    CardStat unk_34;
    u8 unk_4C[0x5C];
    s32 unk_A8;
    s32 unk_AC;
    s32 unk_B0;
    s32 unk_B4;
    s32 unk_B8;
    s32 unk_BC;
    s32 unk_C0;
    s32 unk_C4;
    s32 unk_C8;
    s32 unk_CC;
    s16 unk_D0;
    s16 unk_D2;
    s16 unk_D4;
    u16 unk_D6;
    u16 unk_D8;
    s16 unk_DA;
    s16 unk_DC;
    s16 unk_DE;
    s16 unk_E0;
    s16 unk_E2;
    s16 unk_E4;
    u8 unk_E6;
    u8 unk_E7;
    u8 unk_E8;
    u8 unk_E9;
    u8 unk_EA;
    u8 unk_EB;
    u8 unk_EC;
    u8 unk_ED;
    u8 unk_EE;
    u8 unk_EF;
} BossPrizeWork;

typedef char BossPrizeWork_sizechk[(sizeof(struct BossPrizeWork) == 0xF0) ? 1 : -1];

typedef struct EventMapObjectPlacement {
    s32 x : 24;
    s32 unk_03 : 8;
    s32 y : 24;
    s32 unk_07 : 8;
    u8 spriteIndex;
    u8 unk_09[0x03];
} EventMapObjectPlacement;

typedef struct EventMapObjectDef {
    UnkStruct_09035DCC* tileResources;
    UnkStruct_09035DCC* paletteResources;
    void** sprites;
    EventMapObjectPlacement* placements;
    u16 placementCount;
} EventMapObjectDef;

typedef struct CardDisplayArgs {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C;
    u8 unk_0D;
    u8 unk_0E;
    u8 unk_0F;
} CardDisplayArgs;

typedef struct MapSelectWork {
    TaskPool tasks;
    ListPool cards;
    u8 unk_024[8];
    UnkStruct_080038C8* unk_02C;
    ObjPalette* unk_030;
    void* unk_034;
    void* unk_038;
    void* tiles;
    u8 unk_040[0x1AC];
    MapcardWork* unk_1EC;
    u8 unk_1F0[0x04];
    MapcardWork* unk_1F4;
    u8 unk_1F8[0x40];
    void* unk_238;
    s32 unk_23C;
    s32 unk_240;
    s32 unk_244;
    s32 unk_248;
    u8 unk_24C[0x04];
    s32 unk_250;
    s32 unk_254;
    s32 unk_258;
    s32 unk_25C;
    u8 unk_260[0x04];
    s32 unk_264;
    u8 unk_268[0x04];
    s32 unk_26C;
    s32 unk_270;
    void* gfx;
    u8 unk_278[0x04];
    u16 unk_27C;
    u8 unk_27E[0x02];
    s16 unk_280;
    s16 unk_282;
    u8 unk_284;
    u8 unk_285;
    u8 unk_286;
    u8 unk_287[0x04];
    u8 unk_28B;
    u8 unk_28C;
    u8 unk_28D[0x02];
    u8 unk_28F;
    u8 unk_290;
    u8 unk_291[0x03];
    u8* unk_294;
    u8 unk_298;
    u8 unk_299;
    u8 unk_29A;
    u8 unk_29B;
    u8 unk_29C;
    u8 unk_29D;
    u8 unk_29E[0x20];
    u8 unk_2BE;
    u8 unk_2BF;
    u8 unk_2C0;
    u8 unk_2C1;
    u8 unk_2C2;
    u8 unk_2C3;
    void* unk_2C4;
    u8 unk_2C8[0x04];
    s32 unk_2CC;
    u8 unk_2D0[0x0A];
    u8 unk_2DA;
    u8 unk_2DB;
    void* unk_2DC;
    void* unk_2E0;
} MapSelectWork;

typedef char MapSelectWork_size[(sizeof(struct MapSelectWork) == 0x2E4) ? 1 : -1];

typedef struct UnkStruct_08F7CBA8 {
    void* unk_00;
#ifndef VERSION_EU
    u8 unk_04[0x04];
#endif
    void** unk_08;
    u16 unk_0C;
    u16 unk_0E;
} UnkStruct_08F7CBA8;

extern UnkStruct_08F7CBA8 gUnk_08F7CBA8[];

typedef struct UnkStruct_080A23A0_Args {
    u8* unk_00;
    u32 unk_04;
} UnkStruct_080A23A0_Args;

typedef struct UnkStruct_080A2678 {
    TextSlot unk_000[20];
    TextSlot unk_0A0[20];
    TextSlot unk_140[20];
#ifndef VERSION_JP
    TextSlot unk_1E0[20];
#endif
    void* unk_280;
    void* unk_284;
    void* unk_288;
    u16 unk_28C;
    u8 unk_28E[2];
    s32 unk_290;
    s32 unk_294;
    s32 unk_298;
    s32 unk_29C;
    s32 unk_2A0;
    s32 unk_2A4;
    s32 unk_2A8;
    s8 unk_2AC;
    u8 unk_2AD;
    u8 unk_2AE;
    u8 unk_2AF;
#ifndef VERSION_JP
    u8 unk_2B0;
#endif
    u8 unk_2B1;
    u8* unk_2B4;
} UnkStruct_080A2678;

typedef struct DeckConfirmWork {
    u8 unk_000[0x280];
    u8 unk_280[0x280];
    u8 unk_500[0x280];
    void* tiles;
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
} DeckConfirmWork;

typedef struct UnkStruct_080A5D3C {
    u8 unk_000[0x3C4];
    void* unk_3C4;
    void* unk_3C8;
    void* unk_3CC;
    u8 unk_3D0[0x3C];
    TaskPool unk_40C;
    TaskPool unk_420;
    ListPool unk_434;
    AnimState unk_444;
    AnimState unk_45C;
    AnimState unk_474;
    s32 unk_48C;
    s32 unk_490;
    s32 unk_494;
    s32 unk_498;
    s32 unk_49C;
    s32 unk_4A0;
    s32 unk_4A4;
    s32 unk_4A8;
    s32 unk_4AC;
    u8 unk_4B0[0x18];
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

typedef char UnkStruct_080A5D3C_sizechk[(sizeof(struct UnkStruct_080A5D3C) == 0x50C) ? 1 : -1];

typedef struct LevelUpEffectArgs {
    s32 unk_00;
    s32 unk_04;
    u8 unk_08;
    u8 unk_09[3];
    void* unk_0C;
    void* unk_10;
    u8* unk_14;
} LevelUpEffectArgs;

typedef struct UnkStruct_080A1B4C {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} UnkStruct_080A1B4C;

typedef struct CardEffectArgs {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C;
    u8* unk_10;
} CardEffectArgs;

typedef struct LevelUpEffectWork {
    void* tiles;
    void* palette;
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
} LevelUpEffectWork;

typedef struct UnkStruct_0809FBCC {
#ifdef VERSION_EU
    u8 unk_000[0xD2];
#else
    u8 unk_000[0x77A];
#endif
    s16 unk_77A;
    s16 unk_77C;
    u8 unk_77E[0x32];
    u8 unk_7B0;
    u8 unk_7B1;
    u8 unk_7B2[3];
} UnkStruct_0809FBCC;

typedef struct UnkStruct_080ABA80 {
    s32 unk_00[6];
} UnkStruct_080ABA80;

extern const UnkStruct_080ABA80 gUnk_09045188;
extern const UnkStruct_080ABA80 gUnk_09033FD0;

typedef struct UnkStruct_0809A368_Args {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} UnkStruct_0809A368_Args;

typedef struct WorldSelBeforeWork {
    void* unk_00;
    void* palette;
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
} WorldSelBeforeWork;

typedef struct WorldSelBeforeArgs {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} WorldSelBeforeArgs;

typedef struct DeckCard2Args {
    void* unk_00;
    u16 unk_04;
    s16 unk_06;
    s16 unk_08;
    u8 unk_0A;
    u8 unk_0B;
    u16* unk_0C;
} DeckCard2Args;

typedef struct EventBgEffectFrame {
    u16 duration;
    u16 tilesOffset;
} EventBgEffectFrame;

typedef struct EventBgEffectDef {
    void** maps;
    u8* tiles;
    void* palette;
    u16 tilesSize;
    u16 paletteSize;
    u8 unk_10[0x04];
    EventBgEffectFrame* frames;
    u8 frameCount;
    s8 loopFrame;
} EventBgEffectDef;

typedef struct EventBgEffectEntry {
    u8 unk_00[0x02];
    u16 unk_02;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C[0x04];
} EventBgEffectEntry;

typedef struct EventBgEffectWork {
    EventBgEffectEntry* unk_00;
    u8 unk_04[0x08];
    u16 unk_0C;
    u16 unk_0E;
    u8 unk_10[0x02];
    u8 unk_12;
    u8 unk_13;
    u8 unk_14;
    u8 unk_15;
    u8 unk_16;
} EventBgEffectWork;

extern EventBgEffectDef* gUnk_09EE79B4[];

typedef struct ReloadArgs {
    u32 unk_00;
    u8* unk_04;
} ReloadArgs;

typedef struct ReloadWork {
    void* tiles;
    void* palette;
    void* gfx;
    u8 anim[0x18];
    s32 unk_24;
    s32 unk_28;
    u8 unk_2C;
    u8 unk_2D;
    u8 unk_2E[0x02];
    u8* unk_30;
    u8 unk_34;
} ReloadWork;

extern SpriteFrameResourceDef gUnk_08F7CF18[];

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

typedef struct UnkStruct_080A4DCC {
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
    u16 unk_134;
    u16 unk_136;
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
} UnkStruct_080A4DCC;

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
    u8 unk_14D;
    u8 unk_14E;
    u8 unk_14F;
} UnkStruct_080A3F5C;

typedef char UnkStruct_080A3F5C_sizechk[(sizeof(struct UnkStruct_080A3F5C) == 0x150) ? 1 : -1];

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

extern void* gUnk_09EE981C[];
extern void* gUnk_09EE1380[];
extern u8 gUnk_0940F938[];
extern s16 gUnk_090361B0[];
extern s16 gUnk_090361B8[];
extern s16 gUnk_090361C0[];

typedef struct BossCardWork {
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
} BossCardWork;

extern u8 gUnk_08F7DAC4[];
extern CardBack gUnk_08F70A28[];
extern s16 gUnk_0903595E[];
extern s16 gUnk_09035964[];
extern s32 gUnk_09033D28[];

typedef struct UnkStruct_080A97D4 {
    void* unk_00;
    u16 unk_04;
    s16 unk_06;
    s16 unk_08;
    u8 unk_0A;
    u8 unk_0B;
    u32 unk_0C;
} UnkStruct_080A97D4;

typedef struct UnkStruct_08084D78 {
    u16 unk_00[0x0A];
    u16 unk_14;
    u16 unk_16;
    u16 unk_18;
    u8 unk_1A[0x02];
    u16* unk_1C;
} UnkStruct_08084D78;

typedef struct UnkStruct_0808F358 {
    u8 unk_000[0x784];
    u8 unk_784[20];
    u8 unk_798[0x28];
    s16 unk_7C0;
    s16 unk_7C2;
    u8 unk_7C4;
} UnkStruct_0808F358;

s32 func_0808F358(UnkStruct_0808F358* work);
extern u8* gUnk_09EE4B0C[];

void func_0807E230(void);
void func_0807E254(void);

Deck* GetActiveDeck(void);
Deck* GetDeck(u8 index);
u8 func_08085B84(u16 index);
u16 func_08085B5C(u16 index);
void SetActiveDeckIndex(u8 index);
u16 GetDeckCpCost(u8 index);

void func_08066588(s16 a, s16 b, void* c, void* d, s32 e, u8 f);
void func_0807B410(void* pool);
void func_080933D8(UnkStruct_080933D8* p);
u8 func_0807B60C(void);
u8 func_08081888(void);
u16 func_08078754(UnkStruct_08078754* w, u8 n);
u8 func_0809C448(u8* work, void* a);
u8 func_0807BE54(CardDisplayWork* p, void* a);
u8 func_08088EB4(u8* work, void* a);
void func_08078330(CardSlot* slots, s32 deckIndex);
u8 func_0807CBC0(CardDisplayWork* p, void* a);
u8 func_0807D930(CardDisplayWork* p, void* a);
u8 func_08094934(MapcardWork* w, void* a);
u8 SpotLight_1(SpotlightWork* w, void* a);
u8 func_08098FDC(RevCountWork* w);
void REV_COUNT_0(RevCountWork* w, RevCountArgs* a);
u8 REV_COUNT_1(RevCountWork* w, void* a);
void REV_COUNT_2(RevCountWork* w);
void REV_COUNT_3(RevCountWork* w);
u8 func_080990CC(RevCountWork* w, void* a);
void func_0809A4E0(UnkStruct_0809A02C* w, u8 kind);
void func_0809A02C(UnkStruct_0809A02C* w, s32* args);
void func_0809A1B8(UnkStruct_0809A02C* w, s32* args);
s32 func_0809A54C(UnkStruct_0809A02C* w, void* a);
s32 func_0809A840(UnkStruct_0809A02C* w, void* a);
u8 func_0809AB2C(UnkStruct_0809A02C* w);
s32 func_0809AD60(UnkStruct_0809A02C* w, void* a);
s32 func_0809AD98(UnkStruct_0809A02C* w, void* a);
s32 func_0809AF84(UnkStruct_0809A02C* w, void* a);
void func_0809B200(UnkStruct_0809A02C* w);
void func_0809B3F4(UnkStruct_0809A02C* w);
void func_0809B59C(UnkStruct_0809A02C* w);
void func_0809B5F4(UnkStruct_0809A02C* w);
void func_08090100(DeckCard2Work* n);
u8 Card_EFFECT_1(CardEffectWork* w);
void func_0809D1FC(u8 bg);
u8 func_080A3640(UnkStruct_080A3F5C* w, void* a);
u8 func_08083B20(UnkStruct_08083B20* w, u8 b);
void func_08096F94(UnkStruct_08096F94* w, s32* args);
u8 func_08097138(UnkStruct_08096F94* w, void* a);
void func_08097390(UnkStruct_08096F94* w);
void func_08097688(UnkStruct_08096F94* w);
void func_080999A4(BossPrizeWork* w);
u8 StockInfo_1(u8* work, void* a);
void func_08090A54(CardDisplayWork* p, void* a);
u8 func_0809438C(MapSelectWork* w, void* a);
void func_080A6E3C(u8* work);
void func_080AA328(u8* work);
void func_08083F08(u8 kind, u16* out);
void func_0808E364(u8* work, u8 kind);
void func_08096638(PrizeCardWork* w);
void func_080978B0(UnkStruct_08096F94* w);
void func_08099928(BossPrizeWork* w);
void func_08097834(PrizeCardWork* w);
void PrizeBoss_0(BossPrizeWork* w, s32* args);
u8 PrizeBoss_1(BossPrizeWork* w, void* a);
void PrizeBoss_2(BossPrizeWork* w);
void PrizeBoss_3(BossPrizeWork* w);
u8 func_0809C710(u8* work, void* a);
void func_080AAA8C(u8* work, u8 kind);
u8 func_0808FA0C(u8* work, void* a);
void func_0807FAD8(UnkStruct_08080268* w);
void InitDecks(void);
void func_08090ACC(CardDisplayWork* p, void* a);
u8 func_0809486C(MapcardWork* w, void* a);
void SpotLight_0(SpotlightWork* w, u8* src);
u8 func_08099048(RevCountWork* w, void* a);
u8 func_0809ACDC(UnkStruct_0809A02C* w);
u8 func_0809C4B0(u8* work, void* a);
void func_0809D87C(u16 a, u16 b, u16 c, u16 bits);
void func_080A09C0(u16 n, u16* out);
u8 func_080A5F70(u8* work, void* a);
u8 func_08097600(UnkStruct_08096F94* w);
u8 func_0809CBF8(u8* work, void* a);
u8 func_080A6474(u8* work, void* a);
void RecalculateInactiveDeckCpCosts(void);
u8 RELOAD_1(u8* work, void* a);
u8 func_08099C4C(BossPrizeWork* w);
void func_080A1BB8(EventMapObjectWork* w, void** t);
void Mode_riku_deckTutorial_1(void);
void func_0807A6C8(UnkStruct_08080268* w);
u8 func_0807B578(UnkStruct_08080268* w, void* a);
void func_0807FA44(UnkStruct_08080268* w);
u8 func_080829D0(CardDisplayWork* p, void* a);
void card_enemy_0(CardDisplayWork* p, CardDisplayArgs* a);
void func_080A3A04(UnkStruct_080A3F5C* w);
void card_not_have_2(CardDisplayWork* p);
u8 func_0809C078(u8* work, void* a);
void func_0809D900(u16 a, u16 b, u16 c, u32 v);
void func_080A69A0(u8* work);
void func_080A99A0(u8* work);
void func_08078D98(u8* work, u8 kind, u8 c);
u8 func_0807CB24(CardDisplayWork* p, void* a);
u8 card_enemy_1(CardDisplayWork* p, void* a);
void func_080A6BB4(u8* work);
void func_080A6B40(u8 a, u8 b);
void func_080A9AE8(u8* work);
u8 func_0807D4E4(CardDisplayWork* p);
u8 func_08082F50(CardDisplayWork* p);
void func_0808CD48(u8* work);
void Mode_Premire_0(void);
void func_080A1DAC(EventBgEffectWork* w);
u8 func_080A207C(EventBgEffectWork* w);
u8 func_080A5C9C(u8* work, void* a);
void func_080837FC(CardDisplayWork* p);
u8 map_anim_1(MapTileAnimationWork* w);
u8 Mapcard_1(MapcardWork* w, void* a);
void RELOAD_0(ReloadWork* w, ReloadArgs* a);
void func_0809C1EC(u8* work);
void NO_Card_2(CardDisplayWork* p);
void ClearDeck(u8 deck);
void func_0807A75C(UnkStruct_08080268* w);
u8 func_0807BA54(void);
u8 func_0807CE9C(CardDisplayWork* p);
u8 func_08082B48(CardDisplayWork* p);
void RemoveCardFromDeck(u16* p, u8 deck);
void func_0808D4E4(u8 kind, u8 slot);
u8 func_080909A4(CardDisplayWork* p);
u8 func_080A6A38(u8* work);
u8 func_080A9A38(u8* work);
void func_080AA148(u8 kind, u8 slot);
void Ev_mapObj_2(EventMapObjectWork* w);
void func_080984E4(UnkStruct_080984E4* w);
u8 card_reload_1(CardDisplayWork* p, void* a);
void func_0808E7D8(u8* work);
u8 func_080947B4(MapcardWork* w, void* a);
u8 func_080A63B8(u8* work, void* a);
s16 func_080859A0(s32 mode, Deck* d);
u8 func_080A3DD0(UnkStruct_080A3F5C* w);
u8 func_08098AE4(ReloadChildWork* w, void* a);
void DeckCard2_2(DeckCard2Work* n);
void func_08081760(UnkStruct_08080268* w);
void func_08094CE4(MapcardWork* w);
void func_0808D0A4(u8 deck);
void func_080A9E40(u8 deck);
void func_080A6C50(u8 deck);
u8 func_0809B840(u8* work);
u8 func_0809B9F4(u8* work);
u8 DeckCard2_1(DeckCard2Work* n);
void func_080A676C(u8* work);
void func_08078914(UnkStruct_08078754* w, u8 n);
u8 func_08082154(CardDisplayWork* p, void* a);
void Bosscard_0(BossCardWork* w, u32* a);
void func_080985A0(UnkStruct_08098670* w, u16 b, s16 c, s16 d);
void RemoveCardFromActiveDeck(u16 slot);
u8 func_0807C3E8(CardDisplayWork* p, void* a);
u8 func_0808E934(u8* work, s16 x, s16 y, u16 dir);
void Mapcard_0(MapcardWork* w, MapcardArgs* a);
u8 AddCardToDeck(u16 card, u8 deck);
void func_08084D78(UnkStruct_08084D78* out, u8 deck, u8 mode, u16 n, void* p);
void func_080AB228(void);
u16 func_08093384(void);
void LVUP_EFFECT_0(LevelUpEffectWork* w, LevelUpEffectArgs* a);
void Deck_Clear_0(DeckConfirmWork* w, u8* a);
void Deck_Yes_No_0(DeckConfirmWork* w, u8* a);
void LVUP_EFFECT_2(LevelUpEffectWork* w);
u8 func_0809CB0C(u8* work, void* a);
void Lvup_Logo_0(LevelUpEffectWork* w, LevelUpEffectArgs* a);
void func_0807F99C(UnkStruct_08080268* w);
u8 func_080A3E8C(UnkStruct_080A3F5C* w, void* a);
u8 func_080A5EA0(UnkStruct_080A5D3C* w, void* a);
void func_080A4C1C(UnkStruct_080A3F5C* w);
void func_080A53E4(UnkStruct_080A3F5C* w);
void func_08090864(CardDisplayWork* p);
void func_08099CDC(BossPrizeWork* w);
void func_0809C110(u8* work);
void func_0809CE88(PremiumCardEffectWork* w, s16* a);
void func_0809CF64(PremiumCardEffectWork* w, s16* a);
void RELOAD_CHILDREN_2(ReloadChildWork* w);
u8 func_080AADD4(u8* work, s16 x, s16 y, u16 dir);
u8 func_08090550(CardDisplayWork* p, void* a);
u8 AddCardToActiveDeck(u16 card);
void func_08084AC8(u16 a);
void func_08085A58(s32 a, u16* out);
void func_080A2E14(DeckConfirmWork* w);
void func_080A2EF8(DeckConfirmWork* w);
u8 func_0808CA78(u8* work, u8 a);
void func_0808C2F0(u8* work);
void HCEffectName_2(HcEffectNameWork* w);
u8 func_080A3558(UnkStruct_080A3F5C* w, void* a);
void func_08090B50(CardDisplayWork* p, void* a);
void RELOAD_CHILDREN_0(ReloadChildWork* w, ReloadChildArgs* a);
u8 Bosscard_1(u8* work, void* a);
void func_08094548(MapSelectWork* w);
u8 func_08099B60(BossPrizeWork* w, void* a);
void func_08083714(UnkStruct_08083B20* w);
void func_080836C4(UnkStruct_08095A5C* p, void* a, u8 b, s8 c);
u8 func_08082A64(CardDisplayWork* p, void* a);
void func_0808E3E0(u8* work);
u8 func_080A18F4(LevelUpEffectWork* w);
u8 func_0809753C(UnkStruct_08096F94* w, void* a);
void func_0809B76C(u8* work, void** src);
void func_0809B920(u8* work, void** src);
void func_0808D438(u8 kind, u8 slot);
u8 func_0807BD64(CardDisplayWork* p, void* a);
u8 func_0807D3A0(CardDisplayWork* p, void* a);
u8 func_08082E0C(CardDisplayWork* p, void* a);
u8 func_08090DB0(CardDisplayWork* p, void* a);
void card_reload_0(CardDisplayWork* p, CardDisplayArgs* a);
void func_08091048(CardDisplayWork* p, CardDisplayArgs* a);
void func_0807DAD0(CardDisplayWork* p);
void Reload_Card_0(CardDisplayWork* p, CardDisplayArgs* a);
void func_08091138(CardDisplayWork* p, CardDisplayArgs* a);
u8 func_0809C620(u8* work, void* a);
u8 EV_BG_EFFECT_1(EventBgEffectWork* w, void* a);
void func_0809C534(UnkStruct_0809C534* w, UnkStruct_0809C534_Args* a);
void Card_EFFECT_0(CardEffectWork* w, CardEffectArgs* a);
void deckexchange_3(u8* work);
void func_0807BB04(void);
void func_080818E4(void);
u8 func_0809DA64(s32 a, u16 n);
void StockInfo_0(u8* work, void* a);
u8 func_080A3754(UnkStruct_080A3F5C* w, void* a);
u8 func_08082C98(CardDisplayWork* p, void* a);
u8 Reload_Card_1(CardDisplayWork* p, void* a);
u8 func_0808686C(u8* work, void* a);
u8 func_0807C4BC(CardDisplayWork* p, void* a);
u8 func_080A5034(UnkStruct_080A3F5C* w, void* a);
u8 func_0808E474(UnkStruct_0808DB04* w);
u8 func_080A3A98(UnkStruct_080A3F5C* w, void* a);
u8 func_08082224(CardDisplayWork* p, void* a);
u8 func_08081B70(CardDisplayWork* p, void* a);
u8 func_0807D68C(CardDisplayWork* p, void* a);
u8 func_0808A7E4(u8* work, void* a);
u8 func_080A5198(UnkStruct_080A3F5C* w, void* a);
void func_080A52BC(UnkStruct_080A3F5C* w);
void func_080A6D0C(void);
void WorldSel_Before_0(WorldSelBeforeWork* w, WorldSelBeforeArgs* a);
void func_0807BC24(CardDisplayWork* p, CardDisplayArgs* a);
void func_08081A3C(CardDisplayWork* p, CardDisplayArgs* a);
u8 RELOAD_CHILDREN_1(ReloadChildWork* w, void* a);
u8 func_0807CFA8(CardDisplayWork* p, void* a);
u8 func_08097404(UnkStruct_08096F94* w, void* a);
u8 func_080824C8(CardDisplayWork* p, void* a);
u8 func_0809423C(MapSelectWork* w, void* a);
u8 func_08099A18(BossPrizeWork* w, void* a);
void HCEffectName_0(HcEffectNameWork* w, u8* a);
u8 func_08082348(CardDisplayWork* p, void* a);
u8 func_0809C2D0(u8* work, void* a);
u8 func_08090C3C(CardDisplayWork* p, void* a);

void CardName_0(CardNameWork* w);
void DarkPoint_0(DarkPointWork* w);
s32 DarkPoint_1(DarkPointWork* w);
void DarkPoint_2(DarkPointWork* w);
void DarkPoint_3(void** p);
void func_080A33C4(UnkStruct_080A3F5C* w, void* a);
#ifndef VERSION_EU
void func_080A8C58(UnkStruct_0808C940* w, u8 b);
#ifndef VERSION_EU
u8 func_080A7ABC(UnkStruct_0808C940* w, void* a);
void func_080A9B84(UnkStruct_0808C940* w, u8 b);
#endif
#endif

#endif /* GUARD_CARD_H */
