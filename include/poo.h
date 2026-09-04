#ifndef GUARD_POO_H
#define GUARD_POO_H

#include "types.h"
#include "taskpool.h"
#include "main.h"
#include "obj.h"
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

typedef struct PooActor {
    PooPos unk_00;
    s32 unk_10;
    u8 unk_14;
    u8 unk_15[0x2B];
} PooActor;

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

typedef struct UnkStruct_0203C4B4 {
    PooHit unk_00[6];
    u16 unk_30;
    u8 unk_32;
} UnkStruct_0203C4B4;

typedef struct PooWork {
    void* tiles;
    PaletteSlot* palette;
    void* gfx;
    u8 unk_0C[0x0A];
    u16 unk_16;
    u8 unk_18[0x0C];
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
    u8 unk_4C[0x2C];
    u8 unk_78;
    u8 unk_79[0x03];
    u8 unk_7C[0x14];
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
    u8 unk_DC[0x0C];
    u8 unk_E8;
    u8 unk_E9[0x03];
    s32 unk_EC;
    s32 unk_F0;
    u16 unk_F4;
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
    void* tiles;
    void* palette;
    void* gfx;
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
    s32 unk_00;
    s32 unk_04;
    u32 unk_08;
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
    void* tiles;
    void* palette;
    PooPos* unk_10;
    u8 unk_14[0x18];
    s32 unk_2C;
    void* gfx;
} PooScaleWork;

typedef struct PooBalloonObjWork {
    void* unk_00;
    void* unk_04;
    void* gfx;
    u8 unk_0C[0x18];
    PooPos* unk_24;
} PooBalloonObjWork;

typedef struct PooObjWork {
    void* tiles;
    void* palette;
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
    void* tiles;
    void* palette;
    u8 unk_08[0x18];
    u16 unk_20;
    u16 unk_22;
    PooPos unk_24;
    PooPos unk_34;
    PooPos unk_44;
    PooPos unk_54;
    PooPos unk_64;
    u8 unk_74[0x5C];
    PooNode unk_D0;
    u8 unk_EC[0x04];
    s32 unk_F0;
    TaskPool unk_F4;
    u16 unk_108;
    u16 unk_10A;
} PooHoneyWork;

typedef struct PooLeafArgs {
    s32 unk_00;
    s32 unk_04;
    u8 unk_08[0x08];
    u16 unk_10;
    u16 unk_12;
} PooLeafArgs;

typedef struct PooPileArgs {
    s32 unk_00;
    s32 unk_04;
    u8 unk_08[0x08];
    s32 unk_10;
} PooPileArgs;

typedef struct PooPileWork {
    void* tiles;
    void* palette;
    void* gfx;
    u8 unk_0C[0x18];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    u8 unk_30[0x04];
    u8 unk_34[0x5C];
    PooNode unk_90;
    u8 unk_AC[0x04];
    u16 unk_B0;
    u16 unk_B2;
    TaskPool unk_B4;
    s32 unk_C8;
    u8 unk_CC;
    u8 unk_CD[0x03];
} PooPileWork;

typedef struct PooPigletWork {
    void* tiles;
    void* palette;
    void* gfx;
    u8 unk_0C[0x18];
    u8 unk_24;
    u8 unk_25;
    u16 unk_26;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    u8 unk_38[0x5C];
    TaskPool unk_94;
    s32 unk_A8;
    u16 unk_AC;
    u16 unk_AE;
    u16 unk_B0;
    u16 unk_B2;
    u16 unk_B4;
    u16 unk_B6;
} PooPigletWork;

typedef struct PooEeyoreWork {
    void* tiles;
    void* palette;
    void* gfx;
    u8 unk_0C[0x18];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u8 unk_34[0x5C];
    TaskPool unk_90;
    s32 unk_A4;
    u16 unk_A8;
    u16 unk_AA;
    u8 unk_AC;
    u8 unk_AD;
    u16 unk_AE;
} PooEeyoreWork;

typedef struct PooRabbitWork {
    void* tiles;
    void* palette;
    void* gfx;
    u8 unk_0C[0x18];
    u8 unk_24;
    u8 unk_25[0x03];
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    TaskPool unk_38;
    u8 unk_4C[0x5C];
    s32 unk_A8;
    u16 unk_AC;
    u16 unk_AE;
    u16 unk_B0;
    u16 unk_B2;
} PooRabbitWork;

typedef struct PooGfxDesc {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
} PooGfxDesc;

typedef struct PooTiggerArgs {
    void* unk_00;
    void* unk_04;
    void* unk_08;
} PooTiggerArgs;

typedef struct PooTiggerWork {
    void* tiles;
    void* palette;
    void* gfx;
    u8 unk_0C[0x18];
    u8 unk_24;
    u8 unk_25;
    u16 unk_26;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    u8 unk_38[0x10];
    s32 unk_48;
    u8 unk_4C[0x2C];
    s32 unk_78;
    u8 unk_7C[0x04];
    s32 unk_80;
    s32 unk_84;
    u8 unk_88[0x0C];
    TaskPool unk_94;
    s32 unk_A8;
    s32 unk_AC;
    s32 unk_B0;
    u8 unk_B4[0x04];
    u8 unk_B8;
    u8 unk_B9;
    s16 unk_BA;
    u16 unk_BC;
    u16 unk_BE;
    s32 unk_C0;
    u8 unk_C4[0x04];
    u16 unk_C8;
    u16 unk_CA;
    s32 unk_CC;
    u8 unk_D0;
    u8 unk_D1;
    u16 unk_D2;
} PooTiggerWork;

typedef struct PooBalloonWork {
    void* tiles;
    void* palette;
    void* gfx;
    u8 unk_0C[0x18];
    PooPos unk_24;
    u8 unk_34[0x5C];
    PooNode unk_90;
    u8 unk_AC[0x04];
    TaskPool unk_B0;
    Task* unk_C4;
    s32 unk_C8;
    u16 unk_CC;
    u16 unk_CE;
} PooBalloonWork;

typedef struct PooOwlBalloonWork {
    void* tiles;
    void* palette;
    void* gfx;
    u8 unk_0C[0x18];
    PooPos unk_24;
    u8 unk_34[0x5C];
    PooNode unk_90;
    u8 unk_AC[0x04];
    TaskPool unk_B0;
    Task* unk_C4;
    u16 unk_C8;
    u16 unk_CA;
} PooOwlBalloonWork;

typedef struct PooPrizeWork {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10[0x5C];
    void* tiles;
    void* palette;
    void* unk_74;
    void* unk_78;
    void (*unk_7C)(struct PooPrizeWork* w);
    u8 unk_80[0x02];
    u16 unk_82;
    u8 unk_84[0x08];
    u8 unk_8C;
    u8 unk_8D;
    u16 unk_8E;
    s32 unk_90;
    u16 unk_94;
    u8 unk_96;
    u8 unk_97;
} PooPrizeWork;

typedef struct PooEeyoreTailWork {
    void* tiles;
    void* palette;
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
    void* unk_08;
    u8 unk_0C[0x18];
    PooPos unk_24;
    PooPos unk_34;
    s16 unk_44;
    s16 unk_46;
    void* unk_48;
    void* unk_4C;
    void* unk_50;
    u8 unk_54[0x18];
    PooPos unk_6C;
    PooPos unk_7C;
    s16 unk_8C;
    s16 unk_8E;
    u16 unk_90;
    u16 unk_92;
    PooPos* unk_94;
} PooFreeBalloonWork;

typedef struct PooMapObjHitDesc {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
} PooMapObjHitDesc;

typedef struct PooSpawn {
    s32 unk_00;
    s32 unk_04;
    TaskDesc* unk_08;
} PooSpawn;

typedef struct PooSpawnArgs {
    PooPos unk_00;
    u16 unk_10;
    u16 unk_12;
} PooSpawnArgs;

typedef struct PooMapObjHitArgs {
    s32 unk_00;
    s32 unk_04;
    u8 unk_08[0x08];
    const PooMapObjHitDesc* unk_10;
    s32 unk_14;
    u16 unk_18;
    u16 unk_1A;
} PooMapObjHitArgs;

typedef struct PooMapObjHitWork {
    void* tiles;
    void* palette;
    void* gfx;
    u8 unk_0C[0x18];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    u8 unk_30[0x04];
    const PooMapObjHitDesc* unk_34;
    u8 unk_38;
    u8 unk_39;
    u16 unk_3A;
    u8 unk_3C[0x10];
    s32 unk_4C;
    s32 unk_50;
    u8 unk_54[0x44];
    s32 unk_98;
    u16 unk_9C;
    u16 unk_9E;
} PooMapObjHitWork;

typedef struct PooLeafWork {
    void* tiles;
    void* palette;
    void* gfx;
    u8 unk_0C[0x18];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    u8 unk_30[0x04];
    u8 unk_34[0x2E];
    u16 unk_62;
    u8 unk_64[0x2C];
    u8 unk_90;
    u8 unk_91;
    u16 unk_92;
    u16 unk_94;
    u16 unk_96;
} PooLeafWork;

typedef struct PooOwlWork {
    void* tiles;
    void* palette;
    void* gfx;
    u8 unk_0C[0x0A];
    u16 unk_16;
    u8 unk_18[0x0C];
    PooPos unk_24;
    TaskPool unk_34;
    u8 unk_48;
    u8 unk_49;
    u16 unk_4A;
    u16 unk_4C;
    u16 unk_4E;
} PooOwlWork;

typedef struct PooStumpWork {
    void* tiles;
    void* palette;
    void* unk_08;
    u8 unk_0C[0x18];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    u8 unk_30[0x04];
    u8 unk_34[0x5C];
} PooStumpWork;

typedef struct PooFootmarkWork {
    void* tiles;
    void* palette;
    void* unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    u8 unk_18[0x04];
    PooNode unk_1C;
    u8 unk_38[0x04];
} PooFootmarkWork;

typedef struct PooBoardWork {
    void* tiles;
    void* palette;
    void* unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    u8 unk_18[0x04];
    u8 unk_1C[0x5C];
} PooBoardWork;

typedef struct PooVegetableWork {
    void* tiles;
    void* palette;
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
    void* palette;
    void* unk_08;
    u8 unk_0C[0x18];
    void* unk_24;
    void* unk_28;
    u8 unk_2C[0x18];
    s32 unk_44;
    s32 unk_48;
    s32 unk_4C;
    u8 unk_50[0x04];
    u8 unk_54[0x2E];
    u16 unk_82;
    u8 unk_84[0x2C];
    u8 unk_B0;
    u8 unk_B1;
    u16 unk_B2;
    u16 unk_B4;
    u16 unk_B6;
} PooTanpopoWork;

typedef struct PooHoneycombWork {
    void* tiles;
    void* palette;
    void* unk_08;
    u8 unk_0C[0x18];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u16 unk_34;
    u16 unk_36;
    u8 unk_38[0x5C];
    u16 unk_94;
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

typedef struct PooBeeSub {
    s32 unk_00;
    s32 unk_04;
    u8 unk_08[0x08];
    s32 unk_10;
    s32 unk_14;
    u8 unk_18[0x08];
} PooBeeSub;

typedef struct PooBeeWork {
    void* unk_00;
    void* unk_04;
    void* gfx;
    u8 unk_0C[0x18];
    PooBeeSub unk_24[4];
    s32 unk_A4;
    s32 unk_A8;
    s32 unk_AC;
    s32 unk_B0;
    s32 unk_B4;
    s32 unk_B8;
    u8 unk_BC[0x0A];
    u16 unk_C6;
    u8 unk_C8;
    u8 unk_C9[0x03];
} PooBeeWork;

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
    void* palette;
    u8 unk_08[0x04];
    void* unk_0C;
    u8 unk_10[0x04];
    void* unk_14;
    u8 unk_18[0x2C];
} PooWagonWork;

typedef struct PooWheelWork {
    void* tiles;
    void* palette;
    void* gfx;
    u8 unk_0C[0x18];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u16 unk_34;
    u16 unk_36;
    s32 unk_38;
    s32 unk_3C;
    u8 unk_40;
    u8 unk_41[0x03];
} PooWheelWork;

typedef struct PooCabbageWork {
    void* tiles;
    void* palette;
    void* gfx;
    u8 unk_0C[0x18];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
    u8 unk_44[0x5C];
    s32 unk_A0;
    u16 unk_A4;
    u16 unk_A6;
    TaskPool unk_A8;
    s32 unk_BC;
    s32 unk_C0;
    s32 unk_C4;
    u8 unk_C8;
    u8 unk_C9;
    u16 unk_CA;
    u16 unk_CC;
    u16 unk_CE;
    u8 unk_D0;
    u8 unk_D1;
    u8 unk_D2;
    u8 unk_D3;
    u16 unk_D4;
    u16 unk_D6;
} PooCabbageWork;

typedef struct PooCabbageBornWork {
    TaskPool unk_00;
    u16 unk_14;
    u16 unk_16;
} PooCabbageBornWork;

typedef struct PooMapButterflyWork {
    void* unk_00;
    void* unk_04;
    void* gfx;
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
    void* gfx;
    u8 unk_08[0x18];
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
    s32 unk_44;
    u8 unk_48;
    u8 unk_49[0x03];
    s32 unk_4C;
    u8 unk_50;
    u8 unk_51;
    u16 unk_52;
    u8 unk_54[0x14];
} PooBflyPart;

typedef struct PooMapBeeWork {
    void* unk_00;
    void* unk_04;
    void* gfx;
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
    void* tiles;
    void* palette;
    void* gfx;
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

typedef struct PooCabbageAfterEventWork {
    void* tiles;
    void* palette;
    void* unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u16 unk_1C;
    u16 unk_1E;
} PooCabbageAfterEventWork;

typedef struct PooRabbitAfterEventWork {
    void* tiles;
    void* palette;
    void* gfx;
    u8 unk_0C[0x18];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    TaskPool unk_34;
    u8 unk_48[0x5C];
    u16 unk_A4;
    u16 unk_A6;
} PooRabbitAfterEventWork;

typedef struct PooBeeAfterEventWork {
    void* unk_00;
    void* unk_04;
    void* palette;
    void* unk_0C;
    void* unk_10;
    u8 unk_14[0x18];
    u8 unk_2C[0x18];
    s32 unk_44;
    s32 unk_48;
    s32 unk_4C;
    u32 unk_50;
} PooBeeAfterEventWork;

typedef struct PooMapAnimeWork {
    PooAnim unk_00[2];
} PooMapAnimeWork;

typedef struct PooSparkWork {
    PooPos unk_00;
    u8 unk_10[0x18];
    void* tiles;
    void* palette;
    u8 unk_30[0x04];
} PooSparkWork;

typedef struct PooButterflyWork {
    PooBflyPart unk_00[2];
    void* palette;
    s32 unk_D4;
    s32 unk_D8;
    s32 unk_DC;
    s32 unk_E0;
} PooButterflyWork;

typedef struct PooSoraWork {
    void* tiles;
    void* palette;
    u8 unk_08[0x08];
    s32 unk_10;
    u8 unk_14;
    u8 unk_15[0x0B];
    void* gfx;
    TaskPool unk_24;
    u8 unk_38[0x2C];
    u8 unk_64;
    u8 unk_65;
    u16 unk_66;
    u8 unk_68[0x08];
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    u8 unk_7C[0x18];
    s32 unk_94;
    s16 unk_98;
    s16 unk_9A;
    s32 unk_9C;
    u16 unk_A0;
    u16 unk_A2;
    s32 unk_A4;
    u16 unk_A8;
    u16 unk_AA;
    u8 unk_AC;
    u8 unk_AD[0x03];
    PooNode unk_B0;
    u8 unk_CC[0x04];
} PooSoraWork;

typedef struct PooTrapWork {
    void* tiles;
    void* palette;
    void* unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    u8 unk_18[0x04];
    u8 unk_1C[0x5C];
    TaskPool unk_78;
    u8 unk_8C;
    u8 unk_8D[0x03];
    PooNode unk_90;
    u8 unk_AC[0x04];
} PooTrapWork;

typedef struct PooRooWork {
    void* tiles;
    void* palette;
    void* gfx;
    u8 unk_0C[0x18];
    u8 unk_24;
    u8 unk_25[0x03];
    PooPos unk_28;
    PooPos* unk_38;
    u8 unk_3C[0x5C];
    TaskPool unk_98;
    s32 unk_AC;
    s32 unk_B0;
    u32 unk_B4;
    u16 unk_B8;
    u16 unk_BA;
} PooRooWork;

typedef struct GameState {
    u8 unk_00[0x08];
    u32 flags;
    u8 world;
    u8 unk_0D;
    s8 floor;
} GameState;

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
extern UnkStruct_0203C4B4* gUnk_0203C4B4;
extern const s32 gUnk_096FDA74[];
extern GameState gGameState;
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
extern PooPos* gUnk_0203C3EC;
extern u32 gUnk_0203C3F4;
extern PooSpot gUnk_096FC05C[];
extern PooSpot gUnk_096FC2F0[];
extern s32 gUnk_0203C400;
extern s32 gUnk_0203C404;
extern TaskDesc gTaskDescPooShadowscale;
extern u16 gUnk_0203C40C;
extern u16 gUnk_0203C3F8;
extern u16* gUnk_09EF4208[];
extern PooPos* gUnk_02039BA0;
extern s32 gUnk_0203C3FC;
extern s32 gUnk_0203C408;
extern s32 gUnk_0203C3DC;
extern s32 gUnk_0203C3E8;
extern u32 gUnk_0203C3F0;
extern u8 gUnk_096FD3E8[];
extern const s32 gUnk_096FD43C[];
extern TaskDesc gTaskDescPooPile;
extern u8 gUnk_097561D4[];
extern u8 gUnk_09755F34[];
extern const PooAnimDesc gUnk_096FD47C[];
extern const PooAnimDesc gUnk_096FCF54[][5];
extern const PooAnimDesc gUnk_096FD59C[];
extern u8 gUnk_097565FC[];
extern u8 gUnk_097565E8[];
extern u8 gUnk_09EF602C[];
extern u8 gUnk_09EF6024[];
extern TaskDesc gTaskDescPooTanpopo;
extern TaskDesc gTaskDescPooLeaf;
extern u8 gUnk_09849D58[];
extern u8 gUnk_09849C58[];
extern u8 gUnk_09849D38[];
extern u8 gUnk_097561E8[];
extern u8 gUnk_09755F54[];
extern u8 gUnk_09849D18[];
extern u8 gUnk_09849D78[];
extern u8 gUnk_09849C78[];
extern u8 gUnk_09849CB8[];
extern u8 gUnk_09849C18[];
extern u8 gUnk_09849C98[];
extern u8 gUnk_0974B4D8[];
extern u8 gUnk_09758C94[];
extern u8 gUnk_09849DD8[];
extern u8 gUnk_09849DF8[];
extern u8 gUnk_0975C3E2[];
extern u8 gUnk_0975E40E[];
extern u8 gUnk_0975EC8E[];
extern u8 gUnk_09849E18[];
extern u8 gUnk_0974FB26[];
extern u8 gUnk_09849D98[];
extern u8 gUnk_09756ACE[];
extern u8 gUnk_09EF6130[];
extern u8 gUnk_09EF6138[];
extern u8 gUnk_09EF613C[];
extern u8 gUnk_09EF6154[];
extern u8 gUnk_09732FB6[];
extern u8 gUnk_09849B78[];
extern u8 gUnk_097471E2[];
extern u8 gUnk_09756810[];
extern u8 gUnk_097448BA[];
extern u8 gUnk_09849DB8[];
extern u8 gUnk_09756E28[];
extern u8 gUnk_09EF5EF8[];
extern u8 gUnk_09EF5FA0[];
extern TaskDesc gTaskDescPooShadowdodai;
extern u8 gUnk_09758B9C[];
extern u8 gUnk_09758BF4[];
extern u8 gUnk_09EF60AC[];
extern u8 gUnk_09EF6078[];
extern u8 gUnk_09EF5AD0[];
extern u8 gUnk_09EF5AE0[];
extern u8 gUnk_09EF5E38[];
extern u8 gUnk_09EF5E44[];
extern TaskDesc gTaskDescPooShadow;
extern u8 gUnk_09EF5DC4[];
extern u8 gUnk_09EF5E24[];
extern u8 gUnk_09746EDC[];
extern u8 gUnk_09EF5EA8[];
extern u8 gUnk_09EF5EE4[];
extern TaskDesc gTaskDescPooOwlballoon;
extern u8 gUnk_09EF610C[];
extern u8 gUnk_09EF612C[];
extern u8 gUnk_09EF5FF8[];
extern u8 gUnk_09EF5C8C[];
extern u8 gUnk_09EF5C6C[];
extern u8 gUnk_09756C50[];
extern u8 gUnk_09756D16[];
extern TaskDesc gTaskDescPooCabbage;
extern TaskDesc gTaskDescPooMapobjhit;
extern const PooMapObjHitDesc gUnk_096FD8A4[];
extern TaskDesc gTaskDescPooButterfly;
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
extern void* gStockMesDispWork;
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
extern const PooSpawn gUnk_096FC6F8[];
extern const s32 gUnk_096FD61C[];
extern s32 gUnk_096FD5FC[];
extern const PooGfxDesc gUnk_096FD5DC[];
extern const PooGfxDesc gUnk_096FD57C[];
extern const PooGfxDesc gUnk_096FD4BC[];

extern const PooSpot gUnk_096FD778[];
extern u8 gUnk_09EF5D68[];
extern u8 gUnk_09EF5DA8[];
extern u8 gUnk_09EF5AE4[];
extern u8 gUnk_09EF5B1C[];
extern u8 gUnk_09EF6060[];
extern u8 gUnk_09849C38[];
extern u8 gUnk_09EF5AA0[];
extern u8 gUnk_09EF5AB4[];
extern u8 gUnk_09EF5AB8[];
extern u8 gUnk_09EF5ACC[];
extern u8 gUnk_09732272[];
extern u8 gUnk_0973291E[];
extern u8 gUnk_09849B38[];
extern u8 gUnk_09849B58[];
extern u8 gUnk_097339E8[];
extern u8 gUnk_09742CC2[];
extern u8 gUnk_09849BF8[];
extern u8 gUnk_09849BD8[];
extern u8 gUnk_09849CF8[];
extern u8 gUnk_09753154[];
extern const PooPoint gUnk_096FD730[];
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
extern const s16 gSineTable[];
extern TaskDesc gTaskDescPooMapbee;
extern u8 gUnk_09EF6158[];
extern u8 gUnk_097606E8[];
extern u8 gUnk_09849E38[];
extern u8 gUnk_09EF6200[];
extern u8 gUnk_09849BB8[];
extern TaskDesc gTaskDescPooMapbutterfly;
extern u8 gUnk_096FD400[];
extern PooActor gUnk_0203C420;

#define REG_DISPSTAT (*(vu16*)0x04000004)
#define REG_BG3CNT (*(vu16*)0x0400000C)
#define REG_BG1HOFS (*(vu16*)0x04000018)

void* memcpy(void* dst, const void* src, unsigned long n);

void task_poo_mapbee_0(PooMapBeeWork* w, PooPos* p);
void task_poo_zzz_2(PooZzzWork* w);
s32 func_080D0210(s32 a, s32 b);
u8 task_poo_wagonwheel_1(PooWheelWork* w);
u8 task_poo_gauge_1(PooGaugeWork* w);
void task_poo_roo_0(PooRooWork* w, PooPos* p);
u8 task_poo_roo_1(PooRooWork* w);
void task_poo_roo_2(PooRooWork* w);
void task_poo_shadowdodai_2(PooShadowWork* w);
void task_poo_pooh_3(PooWork* w);
void LoadObjPaletteBank(u16 bank, void* src);
u8 task_poo_butterflyRight_1(PooButterflyWork* w);
void task_poo_butterflyRight_2(PooButterflyWork* w);
u8 task_poo_butterflyLeft_1(PooButterflyWork* w);
void task_poo_butterflyLeft_2(PooButterflyWork* w);
u8 task_poo_mapbeeborn_1(PooMapBornWork* w);
u8 task_poo_mapbutterflyborn_1(PooMapBornWork* w);
u8 task_poo_leaf_1(PooLeafWork* w);
u8 func_080CA4E8(s16 x, s16 y, s16 h, s16 vy, s16 w, s16 vx, s32* ox, s32* oy);
u8 IsTaskActive(Task* t);
u16 func_080C7BF8(u8 kind, u8 count, s32 x, s32 y, s32 z);
void func_080CE710(PooTiggerWork* w, u16 b);
void func_0800592C(s32* a, s32 b, u16 c);
u8 task_poo_tiggerroo_1(PooTiggerWork* w);
void task_poo_tiggerroo_2(PooTiggerWork* w);
s32 func_080CFEA0(PooPos* p);
u8 task_poo_eeyoretail_1(PooEeyoreTailWork* w);
void func_080C8B60(PooMover* w, s32 b, u8 c);
void task_poo_shadowscale_2(PooScaleWork* w);
void task_poo_wagon_0(PooCamera* w);
u8 task_poo_wagon_1(PooCamera* w);
void task_poo_zzz_0(PooZzzWork* w, u8* arg);
void AnimReset(void* a);
s32 GetAngle(s32 x0, s32 y0, s32 x1, s32 y1);
s32 AllocObjAffine(s32 a, s32 b, s32 c, s32 d);
u8 func_080C9D84(void);
void func_080D2190(PooBflyPart* p);
u8 task_poo_owlballoon_1(PooOwlBalloonWork* w);
s32 func_080C8A50(PooWork* w);
PooNode* func_080CCC98(void);
void func_080CE818(PooTiggerWork* w);
void func_080CFF58(u32* a, u32* b, u16 c);
void func_080D1078(PooSpot* p);
void task_poo_eeyoretail_0(PooEeyoreTailWork* w);
void task_poo_honeycomb_0(PooHoneycombWork* w);
void task_poo_spark_2(PooSparkWork* w);
s32 func_080CCBF8(PooNode* n);
void ApproachValue(u32* value, u32 target, u16 steps);
void m4aSongNumStart(u16 n);
u16 func_080C9EAC(void* pool, u16 b);
u8 func_080CA3A0(PooPos* p);
u8 func_080CA3FC(PooActor* p, s32 x, s32 y, s32* ox, s32* oy);
void task_poo_gauge_0(PooGaugeWork* w);
void task_poo_mapbeeborn_0(PooMapBornWork* w, PooPos* p);
void task_poo_mapbutterflyborn_0(PooMapBornWork* w, PooPos* p);
void task_poo_butterfly_0(PooButterflyWork* w, PooPos* p);
void task_poo_freeballoon_0(PooFreeBalloonWork* w, PooPos* p);
void task_poo_butterfly_3(PooButterflyWork* w);
void task_poo_mapbutterfly_0(PooMapButterflyWork* w, PooPos* p);
void task_poo_shadowdodai_0(PooShadowWork* w, PooShadowArgs* a);
void task_poo_shadowscale_0(PooScaleWork* w, PooShadowArgs* a);
void func_080D1990(void* pool, u32 a, s32 x, s32 y, u16 e);
u8 func_080035CC(s16 a, s16 b, s32 c, s32 d, s32 e, s32 f);
void task_poo_zzz_3(PooZzzWork* w);
void func_080CE2C4(PooRabbitWork* w, s32 b, u16 c);
void func_080D206C(PooBflyPart* p);
void task_poo_roo_footmark_0(PooFootmarkWork* w);
void task_poo_spark_0(PooSparkWork* w, PooPos* p);
void task_poo_trap_0(PooTrapWork* w, PooPos* p);
u8 func_080D1650(void);
void func_080C98B8(PooWork* w);
void func_080C7FEC(PooWork* w, u32 a);
void func_080C8C40(PooWork* w, PooNode* n);
u8 task_poo_pooh_1(PooWork* w);
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
void task_poo_bee_0(PooBeeWork* w);
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
void task_poo_owlballoon_3(PooOwlBalloonWork* w);
void func_08000D20(ListNode* node, void* pool, void* owner);
void func_08000D28(ListNode* node, void* pool);
u8 func_080DDDEC(void* p, void* q, u8 c);
u16 GetRandom(void);
void func_08012324(void* a, s32 x, s32 y, s32 z);
void func_08005974(void* a, u16 b, u16 c, void* d, void* e);
void func_08002A10(void* a, void* b);
s32 func_080C8B38(PooAim* w, PooPos* p, u8* c);
u8 task_poo_map_1(PooMapWork* w);
u16 func_080CA36C(u16 x, u16 y);
u8 func_080CA648(PooPos* p);
void func_080CA9DC(PooSoraWork* w);
void func_080CAA50(PooSoraWork* w, s32 b, u16 c);
void func_080CAB24(PooActor* p);
void func_080C7684(s32 a, s32 b, s32 c);
s32 func_080CAA14(PooSoraWork* w);
void task_poo_sora_3(PooSoraWork* w);
u8 task_poo_sora_1(PooSoraWork* w, u8* t);
u8 func_080CB5A8(PooSoraWork* w, u8* t);
void task_poo_trapballoon_2(PooBalloonWork* w);
u8 func_080CA560(PooPos* p, s32 x, s32 y);
u16 GetKeysHeld(void);
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
s8 GetAngleDiff(u8 a, u8 b);
u8 func_08012660(void* p, s32 bit);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, s32 g, u16 h);
s32 abs(s32 a);
void func_0802F208(void);
s32 func_0802F268(void);
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
void task_poo_owl_3(PooOwlWork* w);
void task_poo_poohstump_3(PooStumpWork* w);
void task_poo_roo_footmark_3(PooFootmarkWork* w);
u8 task_poo_spark_1(PooSparkWork* w);
void task_poo_ti_board_3(PooBoardWork* w);
void task_poo_tigerstump_3(PooStumpWork* w);
void task_poo_vegetable_3(PooVegetableWork* w);
u8 func_080D220C(PooBflyPart* p, void* pal);
void task_poo_mapobjhit_3(PooObjWork* w);
void func_080D1B94(PooPrizeWork* w);
u16 func_080C9EFC(void* pool, u16 b);
u8 task_poo_honeycomb_1(PooHoneycombWork* w);
u8 task_poo_eeyore_1(PooEeyoreWork* w);
void task_poo_mapobjhit_2(PooMapObjHitWork* w);
void task_poo_ti_board_2(PooBoardWork* w);
void task_poo_cabbageAfterEvent_2(PooCabbageAfterEventWork* w);
void func_080CE8B4(PooTiggerWork* w);
void task_poo_tigger_0(PooTiggerWork* w);
void task_poo_tiggerroo_0(PooTiggerWork* w);
void task_poo_trap_2(PooTrapWork* w);
void func_080CE77C(PooTiggerWork* w, u16 b);
void task_poo_wagonwheel_0(PooWheelWork* w);
void task_poo_trapballoon_0(PooBalloonWork* w, PooPos* p);
void task_poo_owlballoon_0(PooOwlBalloonWork* w, PooPos* p);
u8 func_080CA8D4(PooSoraWork* w, PooPos* p);
u8 func_080C9DAC(void);
void func_080CA6A8(s32 a, s32 b);
u8 func_080CA960(PooPos* p);
void task_poo_owl_0(PooOwlWork* w);
u8 task_poo_owl_1(PooOwlWork* w);
void task_poo_rabbitAfterEvent_0(PooRabbitAfterEventWork* w);
void task_poo_balloon_2(PooBalloonObjWork* w);
void func_080122AC(void* p, s32 b, s32 c, s32 d);
void task_poo_mapbeeborn_2(PooMapBornWork* w);
void task_poo_mapbutterflyborn_2(PooMapBornWork* w);
void task_poo_mapbutterfly_2(PooMapButterflyWork* w);
void task_poo_freeballoon_2(PooFreeBalloonWork* w);
void task_poo_mapobjhit_0(PooMapObjHitWork* w, PooMapObjHitArgs* a);
void task_poo_mapbee_2(PooMapBeeWork* w);
void func_080C7CB0(s32 a);
u8 func_080C7CBC(void);
void task_poo_leaf_0(PooLeafWork* w, PooLeafArgs* a);
void task_poo_beeAfterEvent_0(PooBeeAfterEventWork* w);
u8 task_poo_tanpopo_1(PooTanpopoWork* w);
void task_poo_pile_0(PooPileWork* w, PooPileArgs* a);
u8 task_poo_cabbageAfterEvent_1(PooCabbageAfterEventWork* w);
void func_080CE960(s32 x, s32 y, s32 z, u8 c);
u8 func_080C8BD4(void);
void func_080C8AB8(PooWork* w);
void task_poo_pitAndButterfly_0(PooTrapWork* w, PooPos* p);
u8 func_080C887C(PooWork* w);
void func_080C8AE0(PooWork* w);
s32 func_080D01BC(s32 x, s32 y);
u8 func_080C871C(PooWork* w);
void func_080C7B84(u32 a);
void func_0800FDD0(s32 a);
void task_poo_mapbutterflyborn_3(PooMapBornWork* w);
void task_poo_trap_3(PooTrapWork* w);
u8 task_poo_pitAndButterfly_1(PooTrapWork* w);
void task_poo_pitAndButterfly_2(PooTrapWork* w);
void task_poo_pitAndButterfly_3(PooTrapWork* w);
u8 task_poo_rabbitAfterEvent_1(PooRabbitAfterEventWork* w);
void task_poo_rabbitAfterEvent_3(PooRabbitAfterEventWork* w);
void func_080D0050(s32* a, s32* b);
u8 func_080D1738(void);
void task_poo_cabbageAfterEvent_0(PooCabbageAfterEventWork* w);
u16 func_080D172C(void);
u32 func_080C8AD4(u32 a);
void task_poo_bee_3(PooObjWork* w);
void task_poo_cabbageAfterEvent_3(PooObjWork* w);
u8 func_080D0E3C(void);
void func_080C8A28(PooWork* w);
u8 task_poo_beeAfterEvent_1(PooBeeAfterEventWork* w);
void task_poo_beeAfterEvent_3(PooBeeAfterEventWork* w);

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
void func_080C8A3C(PooWork* w);
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
void func_080C89B4(PooWork* w, PooSpot* b, u16 c);
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
extern u8 gUnk_0203C3D8;
u16 func_080CA67C(PooPos* p);
u16 func_080CBAB0(PooPos* p);
void func_080C7BCC(u16 a);
u16 AnimGetFrame(void* a);
void* GetBgCharBase(s32 bg);
void* GetBgScreenBase(s32 bg);
u8 RequestDma3Copy(void* src, void* dst, u16 size);
void LoadPalette(void* src, void* dst, s32 size);
void SetBlendAlpha(u16 a, u16 b);
void func_08006238(s32 a, s32 b, s32 c);
void func_080062F4(u16 a, s32 b);

#endif /* GUARD_POO_H */
