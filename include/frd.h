#ifndef GUARD_FRD_H
#define GUARD_FRD_H

#include "obj_api.h"
#include "battle_actor.h"
#include "types.h"
#include "engine_math.h"
#include "battle_work.h"
#include "game_state.h"
#include "anim.h"
#include "taskpool.h"

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

u16 func_0801AF1C(s32 a);
u8 func_0801C6D4(s32* a, s32* b, s32* c, s32* d);
void m4aSongNumStart(u16 n);
void func_08019068(void* a, AnimState* b, s32 c, s32 d, void* e);
void func_08017260(s32 a, s32 b, s32 c, s32 d);
void func_08045494(BtlObj* body, u8 a, s16 b, s16 c);
u8 func_0804544C(FrdDonaldWork* work);
void func_08006B4C(void);
u8 func_080128EC(void);
void func_08012E44(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g,s32 h,s32 i);
void func_08013308(u16 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g,u8 h,s32 i);
void func_08015834(u16 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g,s32 h);
void func_08013CB4(u16 a,s32 b,s32 c,s32 d,s32 e,s32 f);
void func_080147A8(s32 x,s32 y,s32 z);
void func_08014780(s32 x,s32 y,s32 z);
void func_08012AAC(u16 a,s32 x,s32 y,s32 z);
void func_08019050(s32 a,s32 b,s32 c,s32 d);
u8 task_frd_donald_1(FrdDonaldWork* work);
u8 func_080474A8(FrdJackWork* work);
void func_08014D78(u16 a, s32 x, s32 y, s32 z, s32 p, s32 q, s32 r, u8 f, s32 w);
u8 task_frd_jack_1(FrdJackWork* work);
s32 func_08011F78(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void func_0802F1E8(void);
void func_08019A30(void);
void func_08006238(s32 a, s32 b, s32 c);
void func_080061E8(s32 a, u16 b);
void func_08048A68(FrdPanWork* work);
u8 task_frd_pan_1(FrdPanWork* work);
void func_08048980(FrdPanWork* work);
void func_0801D288(void);
u8 func_080465F0(FrdGoofyWork* work);
u32 func_0801A8A4(s32* a, s32* b, s32 c, s32 d);
u8 func_080490FC(FrdAladdinWork* work);

#endif /* GUARD_FRD_H */
