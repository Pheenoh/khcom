#ifndef GUARD_POO_H
#define GUARD_POO_H

#include "types.h"
#include "main.h"

typedef struct PaletteSlot {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x20];
    u8 unk_28;
    u8 unk_29;
    u8 unk_2A[0x02];
} PaletteSlot;

typedef struct PooAim {
    u8 unk_00[0x2E];
    u16 unk_2E;
    u8 unk_30[0x10];
    s32 unk_40;
} PooAim;

typedef struct PooPal {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
} PooPal;

typedef struct PooShadowInfo {
    u16 unk_00;
    u16 unk_02;
    s32 unk_04;
} PooShadowInfo;

typedef struct PooPos {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} PooPos;

typedef struct PooState {
    PooPos unk_00;
    PooPos unk_10;
    s32 unk_20;
    u32 unk_24;
    u16 unk_28;
    u16 unk_2A;
    u32 unk_2C[4];
    u16 unk_3C;
    u16 unk_3E;
    u16 unk_40;
    u16 unk_42;
} PooState;

typedef struct PooHit {
    void* unk_00;
    u16 unk_04;
    u8 unk_06;
    u8 unk_07;
} PooHit;

typedef struct PooHitList {
    PooHit unk_00[6];
    u16 unk_30;
    u8 unk_32;
} PooHitList;

typedef struct PooWork {
    void* unk_00;
    PaletteSlot* unk_04;
    u8 unk_08[0x04];
    u8 unk_0C[0x18];
    u8 unk_24;
    u8 unk_25;
    u16 unk_26;
    PooPos unk_28;
    u8 unk_38;
    u8 unk_39;
    u8 unk_3A;
    u8 unk_3B;
    s32 unk_3C;
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
    u8 unk_4C[0x44];
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[0x10];
    s32 unk_A8;
    u16 unk_AC;
    u8 unk_AE[0x02];
    TaskPool unk_B0;
    Task* unk_C4;
    u8 unk_C8[0x0E];
    u8 unk_D6;
    u8 unk_D7[0x03];
    u16 unk_DA;
    u8 unk_DC[0x1A];
    u8 unk_F6;
    u8 unk_F7[0x03];
    u8 unk_FA;
} PooWork;

typedef struct PooMapWork {
    void* unk_00;
    TaskPool unk_04;
} PooMapWork;

typedef struct PooShadowWork {
    s32 unk_00;
    s32 unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    PooPos* unk_14;
    PooShadowInfo* unk_18;
    u8 unk_1C[0x18];
} PooShadowWork;

typedef struct PooShadowArgs {
    PooPos* unk_00;
    PooShadowInfo* unk_04;
    s32 unk_08;
} PooShadowArgs;

typedef struct PooHitBox {
    void* unk_00;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
} PooHitBox;

typedef struct PooTileDesc {
    void* unk_00;
    void* unk_04;
    void* unk_08;
} PooTileDesc;

typedef struct PooGaugeWork {
    void* unk_00;
    PooPal* unk_04;
    void* unk_08;
    void* unk_0C;
    u8 unk_10;
    u8 unk_11;
    u16 unk_12;
} PooGaugeWork;

typedef struct PooMapBornWork {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C[0x04];
    PooPos unk_10;
    u8 unk_20[0x2E];
    u16 unk_4E;
    u8 unk_50[0x2C];
    u8 unk_7C;
    u8 unk_7D[0x03];
    TaskPool unk_80;
    Task* unk_94;
    u8 unk_98;
    u8 unk_99;
    u8 unk_9A[0x02];
} PooMapBornWork;

typedef struct PooScaleWork {
    s32 unk_00;
    s32 unk_04;
    void* unk_08;
    void* unk_0C;
    PooPos* unk_10;
    u8 unk_14[0x18];
    s32 unk_2C;
    void* unk_30;
} PooScaleWork;

typedef struct PooObjWork {
    void* unk_00;
    void* unk_04;
} PooObjWork;

typedef struct PooObjWork3 {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C[0x08];
} PooObjWork3;

typedef struct PooBalloonArgs {
    void* unk_00;
    s32 unk_04;
    s32 unk_08;
} PooBalloonArgs;

typedef struct PooNode {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    void* unk_08;
    ListNode unk_0C;
} PooNode;

typedef struct PooAnim {
    u8 unk_00[0x08];
    void* unk_08;
} PooAnim;

typedef struct PooAnimWork {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x04];
    u8 unk_0C[0x1A];
    u16 unk_26;
} PooAnimWork;

typedef struct PooFrame {
    u16 unk_00;
    u16 unk_02;
} PooFrame;

typedef struct PooAnimData {
    u8 unk_00[0x04];
    u16 unk_04;
    u16 unk_06;
    PooFrame unk_08[1];
} PooAnimData;

typedef struct PooAnimDesc {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u16 unk_0C;
    u16 unk_0E;
} PooAnimDesc;

typedef struct PooStumpArgs {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x08];
    s32 unk_10;
} PooStumpArgs;

typedef struct PooHoneyWork {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x6C];
    u8 unk_74[0x5C];
    PooNode unk_D0;
    u8 unk_EC[0x08];
    TaskPool unk_F4;
    u8 unk_108[0x04];
} PooHoneyWork;

typedef struct PooPileWork {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x2C];
    u8 unk_34[0x5C];
    PooNode unk_90;
    u8 unk_AC[0x08];
    TaskPool unk_B4;
    u8 unk_C8[0x04];
    u8 unk_CC;
    u8 unk_CD[0x03];
} PooPileWork;

typedef struct PooPigletWork {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x30];
    u8 unk_38[0x5C];
    TaskPool unk_94;
    u8 unk_A8[0x10];
} PooPigletWork;

typedef struct PooEeyoreWork {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x2C];
    u8 unk_34[0x5C];
    TaskPool unk_90;
    u8 unk_A4[0x08];
    u8 unk_AC;
    u8 unk_AD[0x03];
} PooEeyoreWork;

typedef struct PooRabbitWork {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x04];
    u8 unk_0C[0x2C];
    TaskPool unk_38;
    u8 unk_4C[0x5C];
    s32 unk_A8;
    u8 unk_AC[0x08];
} PooRabbitWork;

typedef struct PooTiggerWork {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x04];
    u8 unk_0C[0x18];
    u8 unk_24;
    u8 unk_25;
    u16 unk_26;
    u8 unk_28[0x10];
    u8 unk_38[0x5C];
    TaskPool unk_94;
    u8 unk_A8[0x08];
    s32 unk_B0;
    u8 unk_B4[0x04];
    u8 unk_B8;
    u8 unk_B9[0x03];
    u16 unk_BC;
    u16 unk_BE;
    s32 unk_C0;
    u8 unk_C4[0x10];
} PooTiggerWork;

typedef struct PooBalloonWork {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x1C];
    s32 unk_24;
    s32 unk_28;
    u8 unk_2C[0x08];
    u8 unk_34[0x5C];
    PooNode unk_90;
    u8 unk_AC[0x04];
    TaskPool unk_B0;
    u8 unk_C4[0x0C];
} PooBalloonWork;

typedef struct PooPrizeWork {
    u8 unk_00[0x10];
    u8 unk_10[0x5C];
    void* unk_6C;
    void* unk_70;
    u8 unk_74[0x08];
    void (*unk_7C)(struct PooPrizeWork* w);
    u8 unk_80[0x18];
} PooPrizeWork;

typedef struct PooEeyoreTailWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u32 unk_0C;
    u32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u16 unk_1C;
    u16 unk_1E;
    u32 unk_20;
    TaskPool unk_24;
} PooEeyoreTailWork;

typedef struct PooFreeBalloonWork {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x40];
    void* unk_48;
    void* unk_4C;
    u8 unk_50[0x48];
} PooFreeBalloonWork;

typedef struct PooLeafWork {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x04];
    u8 unk_0C[0x18];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    u8 unk_30[0x04];
    u8 unk_34[0x2E];
    u16 unk_62;
    u8 unk_64[0x2C];
    u8 unk_90;
    u8 unk_91[0x03];
    u16 unk_94;
    u16 unk_96;
} PooLeafWork;

typedef struct PooOwlWork {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x2C];
    TaskPool unk_34;
    u8 unk_48[0x08];
} PooOwlWork;

typedef struct PooStumpWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C[0x18];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    u8 unk_30[0x04];
    u8 unk_34[0x5C];
} PooStumpWork;

typedef struct PooFootmarkWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    u8 unk_18[0x04];
    PooNode unk_1C;
    u8 unk_38[0x04];
} PooFootmarkWork;

typedef struct PooBoardWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    u8 unk_18[0x04];
    u8 unk_1C[0x5C];
} PooBoardWork;

typedef struct PooVegetableWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C[0x18];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u16 unk_34;
    u16 unk_36;
    u8 unk_38[0x5C];
} PooVegetableWork;

typedef struct PooTanpopoWork {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x1C];
    void* unk_24;
    u8 unk_28[0x2C];
    u8 unk_54[0x5C];
    u8 unk_B0[0x08];
} PooTanpopoWork;

typedef struct PooHoneycombWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C[0x18];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u16 unk_34;
    u16 unk_36;
    u8 unk_38[0x5C];
    u8 unk_94[0x02];
    u16 unk_96;
    s32 unk_98;
    u8 unk_9C;
    u8 unk_9D[0x03];
} PooHoneycombWork;

typedef struct PooMover {
    u8 unk_00[0x28];
    s32 unk_28;
    s32 unk_2C;
    u8 unk_30[0x08];
    u8 unk_38;
    u8 unk_39;
    u8 unk_3A;
    u8 unk_3B;
    s32 unk_3C;
    s32 unk_40;
    s32 unk_44;
} PooMover;

typedef struct PooPoint {
    s32 unk_00;
    s32 unk_04;
} PooPoint;

typedef struct PooCamera {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C[0x04];
    void* unk_10;
    u8 unk_14[0x04];
    void* unk_18;
    PooPos unk_1C;
    PooPos unk_2C;
    u8 unk_3C;
    u8 unk_3D;
    u16 unk_3E;
    u16 unk_40;
    u16 unk_42;
} PooCamera;

typedef struct PooSpot {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} PooSpot;

typedef struct PooWagonWork {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x04];
    void* unk_0C;
    u8 unk_10[0x04];
    void* unk_14;
    u8 unk_18[0x2C];
} PooWagonWork;

typedef struct PooWheelWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C[0x18];
    s32 unk_24;
    s32 unk_28;
    u8 unk_2C[0x08];
    u16 unk_34;
    u16 unk_36;
    s32 unk_38;
    s32 unk_3C;
    u8 unk_40;
    u8 unk_41[0x03];
} PooWheelWork;

typedef struct PooCabbageWork {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x3C];
    u8 unk_44[0x64];
    TaskPool unk_A8;
    u8 unk_BC[0x14];
    u8 unk_D0;
    u8 unk_D1[0x07];
} PooCabbageWork;

typedef struct PooCabbageBornWork {
    TaskPool unk_00;
    u16 unk_14;
    u16 unk_16;
} PooCabbageBornWork;

typedef struct PooMapButterflyWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C[0x18];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    u8 unk_30[0x04];
    u8 unk_34;
    u8 unk_35[0x03];
} PooMapButterflyWork;

typedef struct PooBflyPart {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x18];
    u32 unk_20;
    u32 unk_24;
    u8 unk_28[0x08];
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
    s32 unk_44;
    u8 unk_48;
    u8 unk_49[0x03];
    s32 unk_4C;
    u8 unk_50[0x02];
    u16 unk_52;
    u8 unk_54[0x14];
} PooBflyPart;

typedef struct PooMapBeeWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C[0x18];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    u8 unk_30[0x04];
    u8 unk_34;
    u8 unk_35;
    u16 unk_36;
} PooMapBeeWork;

typedef struct PooZzzWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C[0x18];
    void* unk_24;
} PooZzzWork;

typedef struct PooZzzDesc {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C;
    u8 unk_0D[0x03];
} PooZzzDesc;

typedef struct PooStumpDesc {
    void* unk_00;
    void* unk_04;
    u16 unk_08;
    u16 unk_0A;
} PooStumpDesc;

typedef struct PooBeeState {
    u8 unk_00[0x08];
    s32 unk_08;
} PooBeeState;

typedef struct PooMapAnimeWork {
    PooAnim unk_00[2];
} PooMapAnimeWork;

typedef struct PooSparkWork {
    PooPos unk_00;
    u8 unk_10[0x18];
    void* unk_28;
    void* unk_2C;
    u8 unk_30[0x04];
} PooSparkWork;

typedef struct PooButterflyWork {
    PooBflyPart unk_00[2];
    void* unk_D0;
    u8 unk_D4[0x10];
} PooButterflyWork;

typedef struct PooSoraWork {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x08];
    s32 unk_10;
    u8 unk_14;
    u8 unk_15[0x0F];
    TaskPool unk_24;
    u8 unk_38[0x2E];
    u16 unk_66;
    u8 unk_68[0x10];
    s32 unk_78;
    u8 unk_7C[0x18];
    s32 unk_94;
    s16 unk_98;
    u8 unk_9A[0x12];
    u8 unk_AC;
    u8 unk_AD[0x03];
    PooNode unk_B0;
    u8 unk_CC[0x04];
} PooSoraWork;

typedef struct PooTrapWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    u8 unk_18[0x04];
    u8 unk_1C[0x70];
    u8 unk_8C;
    u8 unk_8D[0x23];
} PooTrapWork;

typedef struct PooRooWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C[0x18];
    u8 unk_24;
    u8 unk_25[0x03];
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u8 unk_34[0x08];
    u8 unk_3C[0x5C];
    TaskPool unk_98;
    u8 unk_AC[0x08];
    s32 unk_B4;
    u8 unk_B8[0x04];
} PooRooWork;

typedef struct PooSetup {
    u8 unk_00[0x08];
    u32 unk_08;
    u8 unk_0C;
    u8 unk_0D;
    s8 unk_0E;
} PooSetup;

typedef struct PooBgSet {
    void* unk_00;
    void* unk_04;
    void* unk_08;
} PooBgSet;

typedef struct PooPalStep {
    u16 unk_00;
    u16 unk_02;
} PooPalStep;

extern PooState gUnk_0203C470;
extern u16 gUnk_0203C3E0;
extern u16 gUnk_0203C3E4;
extern PooHitList* gUnk_0203C4B4;
extern const s32 gUnk_096FDA74[];
extern PooSetup gUnk_02039BB0;
extern u16 gUnk_02034E38;
extern u16 gUnk_02034E3A;
extern u16* gUnk_0203C504;
extern u16* gUnk_0203C530;
extern u16* gUnk_0203C4C0[];
extern u16* gUnk_0203C510[];
extern u8 gUnk_0984A138[];
extern u8 gUnk_097B7218[];
extern u8 gUnk_097B8258[];
extern u8 gUnk_0983BC18[];
extern const PooBgSet gUnk_096FDA8C[];
extern const PooPalStep gUnk_096FDB40[];
extern u32 gUnk_02034DAC;
extern PooWork* gUnk_02034DA8;
extern PooPos* gUnk_0203C3EC;
extern u8 gUnk_02034DE0;
extern u8 gUnk_02034DE1;
extern u16 gUnk_02034E24;
extern u16 gUnk_02034E26;
extern u16 gUnk_02034E34;
extern u16 gUnk_02034E36;
extern u32 gUnk_0203C3F4;
extern u16 gUnk_02034DEC;
extern TaskPool gUnk_02034DF8;
extern u8 gUnk_096FC2F0[];
extern s32 gUnk_0203C400;
extern s32 gUnk_0203C404;
extern u16 gUnk_02034E18;
extern u32 gUnk_02034E1C;
extern TaskDesc gUnk_09EF4958;
extern u16 gUnk_0203C40C;
extern u16 gUnk_0203C3F8;
extern u16* gUnk_09EF4208[];
extern void* gUnk_02039BA0;
extern s32 gUnk_0203C3DC;
extern s32 gUnk_0203C3E8;
extern u32 gUnk_0203C3F0;
extern PooSoraWork* gUnk_02034DE8;
extern u8 gUnk_096FD3E8[];
extern const s32 gUnk_096FD43C[];
extern TaskDesc gUnk_09EF4A00;
extern u8 gUnk_097561D4[];
extern u8 gUnk_09755F34[];
extern const PooAnimDesc gUnk_096FD47C[];
extern const PooAnimDesc gUnk_096FD59C[];
extern u8 gUnk_097565FC[];
extern u8 gUnk_097565E8[];
extern u8 gUnk_09EF602C[];
extern u8 gUnk_09756C50[];
extern PooBeeState* gUnk_02034E30;
extern TaskDesc gUnk_09EF4C10;
extern const PooZzzDesc gUnk_09EF4C88[];
extern const PooStumpDesc gUnk_096FCAF4[];
extern const PooAnimDesc gUnk_096FD50C[];
extern u8 gUnk_09755A34[];
extern u8 gUnk_097559F4[];
extern u8 gUnk_09755A04[];
extern u8 gUnk_098A4B68[];
extern u8 gUnk_08F69BE4[];
extern u8 gUnk_09EF8CC0[];
extern u8 gUnk_09EF8CA0[];
extern u8 gUnk_0972BD8C[];
extern u8 gUnk_09849AB8[];
extern u8 gUnk_0972BD78[];
extern void* gUnk_0203C460;
extern const PooTileDesc gUnk_096FCB84[];
extern void* gUnk_09EF5B2C[];
extern u8 gUnk_097356F4[];
extern u8 gUnk_09849B98[];
extern u8 gUnk_09760986[];
extern u8 gUnk_09849E58[];
extern u8 gUnk_09EF6298[];
extern u8 gUnk_09EF6208[];
extern u8 gUnk_08B22BBC[];
extern u8 gUnk_09EE1384[];
extern u8 gUnk_09EE1380[];
extern const PooHitBox gUnk_096FC010;
extern const PooPoint gUnk_096FC6B0[];
extern s32 gUnk_02034DF0;
extern s32 gUnk_02034DF4;
extern const s32 gUnk_096FD61C[];
extern PooCamera* gUnk_02034E20;
extern const PooSpot gUnk_096FD778[];
extern u8 gUnk_09EF5D68[];
extern u8 gUnk_09744842[];
extern u8 gUnk_09EF5FF0[];
extern u8 gUnk_097567FC[];
extern u8 gUnk_09758C04[];
extern u8 gUnk_09758B70[];
extern u8 gUnk_09758C20[];
extern u8 gUnk_097257D8[];
extern u8 gUnk_09849A98[];
extern u8 gUnk_09EF5904[];
extern u8 gUnk_09EF5844[];
extern const s16 gUnk_08121400[];
extern TaskDesc gUnk_09EF4D20;
extern u8 gUnk_09EF6158[];
extern u8 gUnk_097606E8[];
extern u8 gUnk_09849E38[];
extern u8 gUnk_09EF6200[];
extern u8 gUnk_09849BB8[];
extern TaskDesc gUnk_09EF4D50;
extern u8 gUnk_096FD400[];
extern PooPos gUnk_0203C420;

#define REG_DISPSTAT (*(vu16*)0x04000004)
#define REG_BG3CNT (*(vu16*)0x0400000C)
#define REG_BG1HOFS (*(vu16*)0x04000018)

void* memcpy(void* dst, const void* src, unsigned long n);

void task_poo_mapbee_0(PooMapBeeWork* w, PooPos* p);
void task_poo_zzz_2(PooZzzWork* w);
s32 func_080D0210(s32 a, s32 b);
u8 task_poo_wagonwheel_1(PooWheelWork* w);
u8 task_poo_gauge_1(PooGaugeWork* w);
void task_poo_roo_2(PooRooWork* w);
void task_poo_shadowdodai_2(PooShadowWork* w);
void task_poo_pooh_3(PooWork* w);
void LoadObjPaletteBank(u16 bank, void* src);
u8 func_080D22F4(PooButterflyWork* w);
void func_080D2304(PooButterflyWork* w);
u8 func_080D2318(PooButterflyWork* w);
void func_080D2324(PooButterflyWork* w);
u8 task_poo_mapbeeborn_1(PooMapBornWork* w);
u8 task_poo_mapbutterflyborn_1(PooMapBornWork* w);
u8 task_poo_leaf_1(PooLeafWork* w);
u8 func_080CA4E8(s16 x, s16 y, s16 h, s16 vy, s16 w, s16 vx, s32* ox, s32* oy);
u8 func_08000F48(Task* t);
u16 func_080C7BF8(u8 kind, u8 count, s32 x, s32 y, s32 z);
void func_080CE710(PooTiggerWork* w, u16 b);
s32 func_080CFEA0(PooPos* p);
u8 task_poo_eeyoretail_1(PooEeyoreTailWork* w);
void func_080C8B60(PooMover* w, s32 b, u8 c);
void task_poo_shadowscale_2(PooScaleWork* w);
void task_poo_wagon_0(PooCamera* w);
void task_poo_zzz_0(PooZzzWork* w, u8* arg);
void func_08005B64(void* a);
s32 GetAngle(s32 x0, s32 y0, s32 x1, s32 y1);
s32 AllocObjAffine(s32 a, s32 b, s32 c, s32 d);
u8 func_080C9D84(void);
void func_080D2190(PooBflyPart* p);
u8 task_poo_owlballoon_1(PooBalloonWork* w);
s32 func_080C8A50(PooWork* w);
PooNode* func_080CCC98(void);
void func_080CE818(PooTiggerWork* w);
void func_080CFF58(u32* a, u32* b, u16 c);
void func_080D1078(PooSpot* p);
void task_poo_eeyoretail_0(PooEeyoreTailWork* w);
void task_poo_honeycomb_0(PooHoneycombWork* w);
void task_poo_spark_2(PooSparkWork* w);
s32 func_080CCBF8(PooNode* n);
void func_080058FC(u32* value, u32 target, u16 steps);
void m4aSongNumStart(u16 n);
u16 func_080C9EAC(void* pool, u16 b);
u8 func_080CA3A0(PooPos* p);
void task_poo_gauge_0(PooGaugeWork* w);
void task_poo_mapbeeborn_0(PooMapBornWork* w, PooPos* p);
void task_poo_mapbutterflyborn_0(PooMapBornWork* w, PooPos* p);
void task_poo_butterfly_3(PooButterflyWork* w);
void task_poo_mapbutterfly_0(PooMapButterflyWork* w, PooPos* p);
void task_poo_shadowdodai_0(PooShadowWork* w, PooShadowArgs* a);
void task_poo_shadowscale_0(PooScaleWork* w, PooShadowArgs* a);
u16 func_080D1990(void* pool, void* a, void* b, void* c, u16 d);
u8 func_080035CC(s16 a, s16 b, s32 c, s32 d, s32 e, s32 f);
void task_poo_zzz_3(PooZzzWork* w);
void func_080CE2C4(PooRabbitWork* w, s32 b, u16 c);
void func_080D206C(PooBflyPart* p);
void task_poo_roo_footmark_0(PooFootmarkWork* w);
void task_poo_spark_0(PooSparkWork* w, PooPos* p);
void task_poo_trap_0(PooTrapWork* w, PooPos* p);
u8 func_080D1650(void);
void func_080C98B8(PooWork* w);
u8 task_poo_mapbee_1(PooMapBeeWork* w);
void task_poo_roo_3(PooRooWork* w);
u8 func_080CF114(void);
u8 func_080CF12C(void);
void* AllocObjTiles(s32 size, void* src);
void AnimInit(void* a, void* b, void* c);
void* AnimGetGfx(void* a);
void AnimStart(void* a, u16 animId, u16 flags);
void* LoadObjPalette(void* src, s32 size);
void func_080C84E0(PooWork* w, u32 b);
u8 func_080C9910(void);
u8 func_08005AC4(void* a);
void task_poo_tanpopo_3(PooTanpopoWork* w);
void task_poo_ti_board_0(PooBoardWork* w, PooPos* p);
u8 task_poo_ti_board_1(PooBoardWork* w);
void task_poo_honeycomb_3(PooHoneycombWork* w);
void task_poo_vegetable_0(PooVegetableWork* w);
u8 task_poo_vegetable_1(PooVegetableWork* w);
u8 func_080CFF30(void);
void func_080CFFC0(s32* a, s32* b);
void func_080CFFF0(s32* a, s32* b);
void func_080D001C(s32* a, s32* b);
void task_poo_wagon_3(PooWagonWork* w);
void task_poo_wagonwheel_3(PooWheelWork* w);
void task_poo_spark_3(PooSparkWork* w);
u8 func_080D1050(void);
void task_poo_cabbage_3(PooCabbageWork* w);
void task_poo_cabbageborn_0(PooCabbageBornWork* w);
u8 task_poo_cabbageborn_1(PooCabbageBornWork* w);
void func_080D2034(PooBflyPart* p);
u8 task_poo_butterfly_1(PooButterflyWork* w);
void task_poo_mapbee_3(PooObjWork* w);
u8 task_poo_mapbutterfly_1(PooMapButterflyWork* w);
void func_080C9E84(void* pool);
void func_080D1FB8(PooBflyPart* p);

void* LoadObjTiles(void* src, s32 size);
u16 func_08003524(void* a, s32 b);
void m4aSongNumStop(u16 n);
void func_080CCB90(PooNode* n, u16 v, void* p);
void task_poo_honey_3(PooHoneyWork* w);
u8 task_poo_mapanime_1(PooMapAnimeWork* w);
s32 func_080CD198(void);
void task_poo_pile_3(PooPileWork* w);
void func_080CD550(void* pool, u16 b, void* c, void* d);
void task_poo_tigerstump_0(PooStumpWork* w, PooPos* p);
u8 task_poo_tigerstump_1(PooStumpWork* w);
void task_poo_poohstump_0(PooStumpWork* w, PooPos* p);
u8 task_poo_poohstump_1(PooStumpWork* w);
void func_080CD854(PooAnimWork* w, s32 b, u16 c);
void task_poo_piglet_3(PooPigletWork* w);
void task_poo_eeyore_3(PooEeyoreWork* w);
void task_poo_rabbit_3(PooRabbitWork* w);
u16 func_080CE880(PooAnimWork* w);
void task_poo_tiggerroo_3(PooTiggerWork* w);
void task_poo_trapballoon_3(PooBalloonWork* w);
void task_poo_owlballoon_3(PooBalloonWork* w);
void func_08000D20(ListNode* node, void* pool, void* owner);
void func_08000D28(ListNode* node, void* pool);
u8 func_080DDDEC(void* p, void* q);
u16 GetRandom(void);
void func_08012324(void* a, s32 x, s32 y, s32 z);
void func_08005974(void* a, u16 b, u16 c, void* d, void* e);
void func_08002A10(void* a, void* b);
s32 func_080C8B38(PooAim* w, PooPos* p, u8* c);
u8 task_poo_map_1(PooMapWork* w);
u16 func_080CA36C(u16 x, u16 y);
u8 func_080CA648(PooPos* p);
void func_080CA9DC(PooSoraWork* w);
s32 func_080CAA14(PooSoraWork* w);
void task_poo_sora_3(PooSoraWork* w);
u8 func_080CBA4C(void);
u8 func_080CBA74(void);
u8 task_poo_trap_1(PooTrapWork* w);
void task_poo_shadow_0(TaskPool* w, void* arg);
u8 func_080CC284(s16 x, s16 y);
s32 func_080CC488(u16 a);
void task_poo_gauge_2(PooObjWork3* w);
void func_080C9FBC(PooMapWork* w);
void func_080CA270(PooMapWork* w);
void func_08005244(s32 a, u16 b, u16 c);
void func_080CA724(PooSoraWork* w);
s8 func_08005824(u8 a, u8 b);
u8 func_08012660(void* p, s32 bit);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, s32 g, u16 h);
s32 abs(s32 a);
void task_poo_butterfly_2(PooButterflyWork* w);
u8 task_poo_prize_1(PooPrizeWork* w);
void task_poo_prize_3(PooPrizeWork* w);
u8 func_080CBA8C(void);
u8 func_080CFF0C(void);
void task_poo_eeyoretail_3(PooEeyoreTailWork* w);
void task_poo_freeballoon_3(PooFreeBalloonWork* w);
void task_poo_leaf_3(PooLeafWork* w);
void task_poo_mapanime_0(PooMapAnimeWork* w);
void task_poo_mapbeeborn_3(PooMapBornWork* w);
void task_poo_mapbutterflyborn_0(PooMapBornWork* w, PooPos* p);
void task_poo_owl_3(PooOwlWork* w);
void task_poo_poohstump_3(PooStumpWork* w);
void task_poo_roo_footmark_3(PooFootmarkWork* w);
u8 task_poo_spark_1(PooSparkWork* w);
void task_poo_ti_board_3(PooBoardWork* w);
void task_poo_tigerstump_3(PooStumpWork* w);
void task_poo_vegetable_3(PooVegetableWork* w);
void func_080D220C(void* a, void* b);

s32 func_080CFE34(PooPos* p);
void func_08012304(void* a);
void func_080DDDDC(void* p, void* q);
void* AnimUpdate(void* a);
u8 AnimIsFinished(void* a);
void task_poo_map_2(PooMapWork* w);
void task_poo_map_3(PooMapWork* w);
void func_080CA35C(void);
void func_080CA368(void);
void func_080CA0A8(void);
void func_080CA0B4(void);
u16 func_080CBB7C(void);
void func_080CCBE8(void);
void func_080D171C(void);
u8 task_poo_shadowdodai_1(PooShadowWork* w);
u8 task_poo_shadowscale_1(PooScaleWork* w);
void func_080C8A3C(void* a);
void func_080C9FA8(s32 a, s32 b);
void func_080CCBD4(PooNode* p);
u8 func_080CFA70(void);
u8 func_080CFCC0(void);
void func_080D16FC(void);
void task_poo_balloon_3(PooObjWork* w);
void task_poo_gauge_3(PooObjWork* w);
void task_poo_mapbutterfly_3(PooObjWork* w);
void task_poo_shadowdodai_3(PooShadowWork* w);
void task_poo_shadowscale_3(PooScaleWork* w);
void func_080CC178(void* pool, void* a, s32 b);
s32 func_080CD1DC(u32 a);
s32 func_080CD1F8(u32 a);
void func_080C89B4(void* a, void* b, s32 c);
void func_08000BA4(TaskPool* a);
void func_08000D90(ListNode* node, void* pool);
void ReleaseObjTiles(void* a);
void ReleaseObjPalette(void* a);
u16 func_080CCB80(u16* p);
void func_080CCB84(u16* p, u16 v);
u16 func_080CCB88(u16* p);
void func_080CCB8C(u16* p, u16 v);
u8 task_poo_balloon_1(void* w);
void task_poo_mapanime_2(void* w);
void task_poo_mapanime_3(void* w);
u8 task_poo_roo_footmark_1(void* w);
u8 task_poo_zzz_1(void* w);
void func_080CA09C(void);
void func_080CA0C0(void);
u16 func_080D06BC(void);
u16 func_080D06C8(void);
u16 func_080D1710(void);
void task_poo_cabbageborn_2(TaskPool* w);
void task_poo_cabbageborn_3(TaskPool* w);
u8 task_poo_shadow_1(TaskPool* w);
void task_poo_shadow_2(TaskPool* w);
void task_poo_shadow_3(TaskPool* w);
u8 func_080C9D48(void);
u8 func_080C9D5C(void);
u8 func_080C9D70(void);
u8 func_080C9D84(void);
u8 func_080C9D98(void);
u8 func_080C9DAC(void);
u8 func_080C9E28(void);
u8 func_080C9E4C(void);
u8 func_080C9E70(void);
void func_080D2BE0(void);
void func_080D2BF8(u16 a);
u8 func_080D2C1C(u16 a);
void func_080D2C48(void);
void func_080D2C78(void);
void func_080D2C8C(PooPos* p, s32 b);
void func_080D2CA8(PooPos* p, s32* b);
void func_080D2CC4(u16 a, u16 b);
void func_080D2CD0(u16* a, u16* b);
void func_080D2CE0(s16 a, s16 b);
void func_080D2CF4(u16* a, u16* b);
void func_080D2D0C(PooPos* p);
void func_080D2D24(PooPos* p);
void func_080D2D3C(s32 a);
u8 func_080D2D50(s32 a);
void func_080D2D6C(s32 a);
void func_080D2D80(s32 a);
u8 func_080D2D94(s32 a);
void func_080D2DB0(void* p);
void func_080D2DC4(const void* p);
u8 func_080D2DD8(void);
u16 func_080D2E28(void* a, u16 b);
void func_080D2E70(u16 a, u8 b);
void func_080D2E84(void);
void func_080D2E98(void);
u16 func_080D2EB8(void);
void func_080D2F10(u8 a);
void func_080D2F20(void);
void func_080D2F64(void);
void func_080D3008(void);
void func_080D3034(s16 a);
void func_080D3050(void);
void func_080D30C8(void);
void func_080D313C(void);

u8 func_080C76B0(void* p);
u16 func_080CA67C(PooPos* p);
u16 func_08005B34(void* a);
void* GetBgCharBase(s32 bg);
void* GetBgScreenBase(s32 bg);
u8 RequestDma3Copy(void* src, void* dst, u16 size);
void LoadPalette(void* src, void* dst, s32 size);
void SetBlendAlpha(u16 a, u16 b);
void func_08006238(s32 a, s32 b, s32 c);
void func_080062F4(u16 a, s32 b);

#endif /* GUARD_POO_H */
