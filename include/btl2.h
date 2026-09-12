#ifndef GUARD_BTL2_H
#define GUARD_BTL2_H

#include "btl2_tasks.h"

#include <stdlib.h>
#include "fade.h"
#include "obj_api.h"
#include "battle_actor.h"
#include "display.h"
#include "types.h"
#include "engine_math.h"
#include "battle_work.h"
#include "game_state.h"
#include "m4a.h"
#include "key.h"
#include "anim.h"
#include "fld_types.h"
typedef struct FldActor {
    FldPos unk_00;
    s32 unk_10;
    u8 angle;
    u8 unk_15[0x25];
    u16 unk_3A;
    s32 unk_3C;
    u8 unk_40[0x10];
} FldActor;
typedef struct UnkStruct_02039BA0 {
    s32 unk_00;
    s32 unk_04;
    u8 unk_08[0x10];
    FldActor unk_18;
    s32 unk_68;
    u8 unk_6C[0x04];
    u32 unk_70;
} UnkStruct_02039BA0;

typedef struct FldWork {
    void* tiles;
    void* palette;
    u8 unk_08[0x0A];
    u16 unk_12;
    u8 unk_14[0x02];
    u16 unk_16;
    u8 unk_18[0x08];
    void* gfx;
    u8 unk_24[0x14];
    u8 unk_38[0x10];
    s32 unk_48;
    u8 unk_4C[0x18];
    u8 unk_64;
    u8 unk_65;
    u16 unk_66;
    u8 unk_68[0x04];
    s32 unk_6C;
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    s32 unk_7C;
    s32 unk_80;
    s32 unk_84;
    u8 unk_88[0x0C];
    s32 unk_94;
    s16 unk_98;
    u8 unk_9A[0x06];
    s32 unk_A0;
    u16 unk_A4;
    u8 unk_A6[0x02];
    s32 unk_A8;
    u16* unk_AC;
    s32 unk_B0;
    s32 unk_B4;
    s32 unk_B8;
    u8 unk_BC;
    u8 unk_BD[0x03];
} FldWork;

typedef struct BtlShadowWork {
    void* tiles;
    void* palette;
    BtlObj* actor;
    void* gfx;
} BtlShadowWork;

typedef struct BtlHpplyWork {
    s32 unk_00;
    u8 unk_04;
    u8 unk_05[0x03];
    void* palette2;
    void* palette;
    void* tiles;
    void* tiles2;
    void* tiles3;
    void* tiles4;
    void* gfx;
    void* gfx2;
    void* gfx3;
    AnimState unk_2C;
    AnimState unk_44;
    u8 unk_5C;
    u8 unk_5D;
    s16 unk_5E;
    s16 unk_60;
    s16 unk_62;
    s16 unk_64;
    u8 unk_66[0x02];
    u32 unk_68;
} BtlHpplyWork;

typedef struct BtlHpenmWork {
    void* tiles;
    void* tiles2;
    void* palette;
    void* tiles3;
    s32 unk_10;
    u8 unk_14;
    u8 unk_15[0x03];
    BtlObj* unk_18;
    s16 unk_1C;
    s16 unk_1E;
    u32 unk_20;
} BtlHpenmWork;

typedef struct BtlPauseWork {
    void* tiles;
    void* palette;
    void* gfx;
    void* gfx2;
    u8 unk_10;
    u8 unk_11[0x03];
    s32 x;
    s32 y;
    s32 x2;
    s32 y2;
    s16 unk_24;
    s16 unk_26;
} BtlPauseWork;

typedef struct BtlPopWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    s16 unk_30;
    s16 unk_32;
} BtlPopWork;

typedef struct BtlEscapeWork {
    void* tiles;
    void* palette;
    void* gfx;
    void* gfx2;
    void* gfx3;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s16 unk_20;
    u8 unk_22;
    u8 unk_23;
} BtlEscapeWork;

typedef struct BtlPrizeWork {
    s32 x;
    s32 y;
    s32 z;
    s32 unk_0C;
    void* tiles;
    void* palette;
    void* gfx;
    void* gfx2;
    s32 unk_20;
    s32 unk_24;
    s16 unk_28;
    u8 unk_2A;
    u8 unk_2B;
    u16 unk_2C;
    u8 unk_2E[0x02];
    s32 unk_30;
    s32 unk_34;
    u16 unk_38;
    s16 unk_3A;
    s32 unk_3C;
    s32 unk_40;
    u8 unk_44;
    u8 unk_45[0x03];
    BtlObj* unk_48;
} BtlPrizeWork;

typedef struct BtlPremireWork {
    s32 x;
    s32 y;
    s32 z;
    s32 unk_0C;
    void* tiles;
    void* palette;
    void* gfx;
    void* gfx2;
    s32 unk_20;
    s32 unk_24;
    s16 unk_28;
    u8 unk_2A;
    u8 unk_2B;
    u16 unk_2C;
    u8 unk_2E[0x02];
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3C;
    u8 unk_40;
    u8 unk_41[0x03];
    BtlObj* unk_44;
    AnimState anim;
} BtlPremireWork;

typedef struct BtlPremireSrc {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x06];
    s16 unk_12;
    s16 unk_14;
    s16 unk_16;
} BtlPremireSrc;

typedef struct BtlStartWork {
    s16 unk_00;
    s16 unk_02;
} BtlStartWork;

s32 func_080DFF1C(FldPos* p);
u8 func_080DFCDC(FldPos* p);
u8 func_080DFBDC(FldPos* p);
u8 _080DFE1C(FldPos* p);

extern UnkStruct_02039BA0* gUnk_02039BA0;

extern u8 gUnk_0203D990[];
extern u8 gUnk_0203D9D0[];
extern u8 gUnk_0203DA10[];
extern u8 gUnk_0203DA50[];
extern u8 gUnk_0203DA90[];
extern u8 gUnk_0203DAD0[];
extern u8 gMPlayInfo_BGM[];
extern u8 gUnk_0203DB50[];
extern u8 gUnk_0203DB90[];
extern u8 gUnk_0203DBD0[];
extern u8 gUnk_0203DC10[];
extern u8 gUnk_0203DC50[];
extern u8 gUnk_0203DC90[];
extern u8 gUnk_0203DCD0[];
extern u8 gUnk_0203DD10[];
extern u8 gUnk_0203DD50[];
extern u8 gUnk_0203DD90[];
extern u8 gUnk_0203DDD0[];
extern u8 gUnk_0203DE10[];
extern u8 gUnk_0203DE50[];
extern u8 gUnk_0203DEA0[];
extern u8 gUnk_0203DEE0[];
extern u8 gUnk_0203DF20[];
extern s16 gSineTable[];
extern FldAnimDef gUnk_0813C89C[][5];
extern u8 gUnk_08B1E7F4[];
extern u8 gUnk_08B1EB1C[];
extern u8 gUnk_08B1ED76[];
extern u8 gUnk_08B1EF0C[];
extern u8 gUnk_08B1F020[];
extern u8 gUnk_08B1F13A[];
extern u8 gUnk_08B1F2D6[];
extern u8 gUnk_08B1F472[];
extern u8 gUnk_08B1F60E[];
extern u8 gUnk_08B1F7AC[];
extern u8 gUnk_09EE11BC[];
extern u8 gUnk_09EE11C0[];
extern u8 gUnk_09EE11C4[];
extern u8 gUnk_09EE11C8[];
extern u8 gUnk_09EE11CC[];
extern u8 gUnk_09EE11D0[];
extern u8 gUnk_09EE11D4[];
extern u8 gUnk_09EE11D8[];
extern u8 gUnk_09EE11DC[];
extern u8 gUnk_09EE11E0[];
extern u8 gUnk_09EE11E4[];
extern u8 gUnk_09EE11E8[];
extern u8 gUnk_09EE11EC[];
extern u8 gUnk_09EE11F0[];
extern u8 gUnk_09EE11F4[];
extern u8 gUnk_09EE1204[];
extern u8 gUnk_08B208E8[];
extern u8 gUnk_08B208F2[];
extern u8 gUnk_08B208FC[];
extern u8 gUnk_08B20906[];
extern u8 gUnk_08B20910[];
extern u8 gUnk_08B2091A[];
extern u8 gUnk_08B20924[];
extern u8 gUnk_08B2092E[];
extern u8 gUnk_08B20938[];
extern u8 gUnk_08B20942[];
extern u8 gUnk_08B209E0[];
extern u8 gUnk_08B20D20[];
extern u8 gUnk_08B20D6E[];
extern u8 gUnk_08B213F0[];
extern u8 gUnk_08B21438[];
extern u8 gUnk_08B22BA8[];
extern u8 gUnk_08B22BBC[];
extern u8 gUnk_08B22CBC[];
extern u8 gUnk_08B22CE4[];
extern u8 gUnk_08B22EE4[];
extern u8 gUnk_08B22EFE[];
extern u8 gUnk_08B23CB0[];
extern u8 gUnk_08B23CBA[];
extern u8 gUnk_08B23E7C[];
extern u8 gUnk_08B23E8C[];
extern u8 gUnk_08B23E9C[];
extern u8 gUnk_08B23EAC[];
extern u8 gUnk_08B23EBC[];
extern u8 gUnk_08B23ED2[];
extern u8 gUnk_08B23EE8[];
extern u8 gUnk_08B23EFE[];
extern u8 gUnk_08B23F08[];
extern u8 gUnk_08B24016[];
extern u8 gUnk_08B24C98[];
extern u8 gUnk_08B24CA2[];
extern u8 gUnk_08B24CB2[];
extern u8 gUnk_08B24CC2[];
extern u8 gUnk_08B24CD2[];
extern u8 gUnk_08B24CE2[];
extern u8 gUnk_08B24CF8[];
extern u8 gUnk_08B24D0E[];
extern u8 gUnk_08B24D18[];
extern u8 gUnk_08B24D22[];
extern u8 gUnk_08B24D2C[];
extern u8 gUnk_08B24D42[];
extern u8 gUnk_08B24D58[];
extern u8 gUnk_08B24D6E[];
extern u8 gUnk_08B24DAA[];
extern u8 gUnk_08F683A4[];
extern u8 gUnk_08F69BA4[];
extern u8 gUnk_09618118[];
extern void* gUnk_09EE115C[];
extern void* gUnk_09EE11A4[];
extern u8 gUnk_09EDA918[];
extern u8 gUnk_09EE1244[];
extern u8 gUnk_09EE1278[];
extern u8 gUnk_09EE12A4[];
extern u8 gUnk_09EE12B0[];
extern u8 gUnk_09EE12BC[];
extern u8 gUnk_09EE12C8[];
extern u8 gUnk_09EE1420[];
extern u8 gUnk_09EE1498[];

void func_08031BC4(FldActor* act);
u8 func_08031D74(FldPos* p);
s32 func_08031DF8(FldPos* p);
u8 func_08031E48(FldPos* p, FldWork* work);
u8 func_08031EC4(FldActor* act);
s32 func_08031F1C(FldWork* work);
void func_08031F60(FldActor* act);
void func_08031F98(FldWork* work, s32 a, s32 b);

#endif /* GUARD_BTL2_H */
