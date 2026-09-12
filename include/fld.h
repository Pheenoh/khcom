#ifndef GUARD_FLD_H
#define GUARD_FLD_H

#include "map_types.h"

#include "map_api.h"
#include "fld_tasks.h"

#include "m4a_song.h"
#include <stdlib.h>
#include "fade.h"
#include "btl_collision.h"
#include "obj_api.h"
#include "types.h"
#include "engine_math.h"
#include "game_state.h"
#include "anim.h"
#include "taskpool.h"
#include "key.h"
#include "game.h"
#include "fld_types.h"
#include "bos4_api.h"
#include "btl2_api.h"


typedef struct UnkStruct_02039BA0 {
    s32 unk_00;
    s32 unk_04;
    u8 unk_08[0x10];
    FldActor unk_18;
    s32 unk_68;
    u8 unk_6C[0x04];
    u32 unk_70;
    u8 unk_74[0x68];
    s32 unk_DC;
    s32 unk_E0;
    u8 unk_E4;
} UnkStruct_02039BA0;

extern UnkStruct_02039BA0* gUnk_02039BA0;

typedef struct FldWork {
    void* tiles;
    FldRes* palette;
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
    u32 unk_6C;
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    s32 unk_7C;
    s32 unk_80;
    s32 unk_84;
    u8 unk_88[0x0C];
    u32 unk_94;
    s16 unk_98;
    s16 unk_9A;
    u8 unk_9C;
    u8 unk_9D;
    u16 unk_9E;
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
extern FldAnimDef gUnk_0813CDDC[][5];

typedef struct FldShadowWork {
    s32 unk_00;
    s32 unk_04;
    void* tiles;
    void* palette;
    FldActor* unk_10;
    u8 anim[0x18];
} FldShadowWork;

void func_0803473C(FldWork* work, s32 index, u16 flags);

void func_080A5830(void* a, s32 x, s32 y, s32 z);

extern TaskDesc gTaskDescFldShadow;
extern u16 gUnk_0813CD4C[][8];
extern u16 gUnk_0813D28C[][8];
extern u8 gUnk_08F683A4[];
extern u8 gUnk_09618118[];
extern u8 gUnk_08B22BBC[];
extern u8 gUnk_08F69BE4[];
extern u8 gUnk_09EE1380[];
extern u8 gUnk_09EE1384[];
extern s16 gSineTable[];

u8 func_08034518(FldPos* p);
s32 func_0803459C(FldPos* p);
u8 func_080345EC(FldPos* p, FldWork* work);
u8 func_08034668(FldActor* act);
s32 func_080346C0(FldWork* work);
void func_08034368(FldActor* act);
void func_08034704(FldActor* act);
u8 func_08032268(FldWork* work, void* task);
u8 func_0803234C(FldWork* work, void* task);
u8 func_080324DC(FldWork* work, void* task);
u8 func_08032C3C(FldWork* work, void* task);
u8 func_08033054(FldWork* work, void* task);
u8 func_08033150(FldWork* work, void* task);
u8 func_08033334(FldWork* work, void* task);
u8 func_0803366C(FldWork* work, void* task);
u8 func_08034AF0(FldWork* work, void* task);
u8 func_08034C88(FldWork* work, void* task);
u8 func_080353DC(FldWork* work, void* task);
u8 func_080357F4(FldWork* work, void* task);
u8 func_080358F0(FldWork* work, void* task);
u8 func_08035AD4(FldWork* work, void* task);
u8 func_08035DFC(FldWork* work, void* task);
u8 func_08034A0C(FldWork* work, void* task);

#endif /* GUARD_FLD_H */
