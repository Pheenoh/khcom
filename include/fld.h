#ifndef GUARD_FLD_H
#define GUARD_FLD_H

#include "field_state.h"

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
