#ifndef GUARD_FRD_H
#define GUARD_FRD_H

#include "frd_tasks.h"

#include "display.h"
#include "m4a_song.h"
#include "fade.h"
#include "btl_effect.h"
#include "btl_collision.h"
#include "obj_api.h"
#include "battle_actor.h"
#include "types.h"
#include "engine_math.h"
#include "battle_work.h"
#include "game_state.h"
#include "anim.h"
#include "taskpool.h"
#include "smn_api.h"

typedef struct FrdArgs {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
} FrdArgs;

typedef struct FrdDonaldWork {
    TaskPool unk_000;
    BtlObj* unk_014;
    void* tiles;
    void* palette;
    BtlObj unk_020;
    AnimState anim;
    s32 unk_148;
    u8 unk_14C;
    u8 unk_14D;
    s16 unk_14E;
    s16 unk_150;
    u8 unk_152[0x02];
    s32 unk_154;
    s32 unk_158;
    s32 unk_15C;
    s16 unk_160;
    u8 unk_162[0x02];
} FrdDonaldWork;

typedef struct FrdGoofyWork {
    TaskPool unk_000;
    BtlObj* unk_014;
    void* tiles;
    void* palette;
    BtlObj unk_020;
    AnimState anim;
    u32 unk_148;
    u8 unk_14C;
    u8 unk_14D;
    s16 unk_14E;
    s16 unk_150;
    u8 unk_152[0x02];
    s32 unk_154;
    s32 unk_158;
    s32 unk_15C;
    u8 unk_160;
    u8 unk_161[0x03];
} FrdGoofyWork;

typedef struct FrdArielWork {
    TaskPool unk_000;
    BtlObj* unk_014;
    void* tiles;
    void* palette;
    BtlObj unk_020;
    AnimState anim;
    u32 unk_148;
    u8 unk_14C;
    u8 unk_14D;
    s16 unk_14E;
    s16 unk_150;
    u8 unk_152[0x02];
    s32 unk_154;
    s16 unk_158;
    u8 unk_15A[0x02];
    s32 unk_15C;
    s32 unk_160;
} FrdArielWork;

typedef struct FrdJackWork {
    TaskPool unk_000;
    BtlObj* unk_014;
    void* tiles;
    void* palette;
    BtlObj unk_020;
    AnimState anim;
    s32 unk_148;
    u8 unk_14C;
    u8 unk_14D;
    s16 unk_14E;
    s16 unk_150;
    s16 unk_152;
    s32 unk_154;
    s32 unk_158;
    s32 unk_15C;
    s32 unk_160;
    s32 unk_164;
    s16 unk_168;
    u8 unk_16A[0x02];
} FrdJackWork;

typedef struct FrdPanWork {
    TaskPool unk_000;
    BtlObj* unk_014;
    void* tiles;
    void* palette;
    BtlObj unk_020;
    AnimState anim;
    u32 unk_148;
    u8 unk_14C;
    u8 unk_14D;
    s16 unk_14E;
    s16 unk_150;
    s16 unk_152;
    s16 unk_154;
    s16 unk_156;
    s32 unk_158;
    s32 unk_15C;
    s32 unk_160;
    s32 unk_164;
    s32 unk_168;
    u8 unk_16C;
    u8 unk_16D[0x03];
} FrdPanWork;

typedef struct FrdAladdinWork {
    TaskPool unk_000;
    BtlObj* unk_014;
    void* tiles;
    void* palette;
    BtlObj unk_020;
    AnimState anim;
    u32 unk_148;
    u8 unk_14C;
    u8 unk_14D;
    s16 unk_14E;
    s16 unk_150;
    s16 unk_152;
    s32 unk_154;
    s32 unk_158;
    u8 unk_15C[0x04];
} FrdAladdinWork;

typedef struct FrdBeastWork {
    TaskPool unk_000;
    BtlObj* unk_014;
    void* tiles;
    void* palette;
    BtlObj unk_020;
    AnimState anim;
    s32 unk_148;
    u8 unk_14C;
    u8 unk_14D;
    s16 unk_14E;
    s32 unk_150;
    s32 unk_154;
    s32 unk_158;
    s32 unk_15C;
} FrdBeastWork;

extern u8 gTaskDescBtlShadow[];
extern u8 gTaskDescSmnTinkeff[];
extern s16 gSineTable[];
extern u8 gUnk_09617C58[];
extern u8 gUnk_0813EB8C[];
extern u8 gUnk_08F68384[];
extern u8 gUnk_0813EBFC[];
extern u8 gUnk_09617DF8[];
extern u8 gUnk_0813EC5C[];
extern u8 gUnk_09617DB8[];
extern u8 gUnk_0813EC9C[];
extern u8 gUnk_09617DD8[];
extern u8 gUnk_0813ECFC[];
extern u8 gUnk_09617D98[];
extern u8 gUnk_0813ED4C[];
extern u8 gUnk_09617E18[];
extern u8 gUnk_0813ED90[];

u8 func_080474A8(FrdJackWork* work);
void func_0802F1E8(void);
void func_08048A68(FrdPanWork* work);
void func_08048980(FrdPanWork* work);
void func_0801D288(void);
u8 func_080465F0(FrdGoofyWork* work);
u8 func_080490FC(FrdAladdinWork* work);

#endif /* GUARD_FRD_H */
