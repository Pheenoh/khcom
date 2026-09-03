#ifndef GUARD_FRD_H
#define GUARD_FRD_H

#include "types.h"
#include "anim.h"
#include "taskpool.h"

typedef struct GameState {
    u8 unk_000[0x0C];
    u8 world;
    u8 unk_00D[0x03];
} GameState;

typedef struct FrdArgs {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
} FrdArgs;

typedef struct BtlWork {
    s32 unk_000;
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
    s32 unk_010;
    s32 unk_014;
    s32 unk_018;
    s32 unk_01C;
    s32 unk_020;
    s32 unk_024;
    s32 unk_028;
    s16 unk_02C;
    s16 unk_02E;
    u32 unk_030;
    u64 unk_034;
    u8 unk_03C[0x2C];
    u64 unk_068;
    u8 unk_070;
    u8 unk_071[0x07];
    struct BtlWork* unk_078;
    struct BtlWork* unk_07C;
    u8 unk_080[0x1C];
    u8 unk_09C[0x17];
    u8 unk_0B3;
    u8 unk_0B4[0x04];
    u8 unk_0B8[0x14];
    u16 unk_0CC;
    u16 unk_0CE;
    u32 unk_0D0;
    u32 unk_0D4;
    u16 unk_0D8;
    s16 unk_0DA;
    s16 unk_0DC;
    s16 unk_0DE;
    s16 unk_0E0;
    u8 unk_0E2[0x02];
    u8* unk_0E4;
    u8 unk_0E8[0x24];
    s32 unk_10C;
    void* unk_110;
    void* unk_114;
    u8 unk_118[0x10];
    void (*unk_128)(s32* a, s32* b, s32* c, s32* d);
    u8 unk_12C[0x9C];
} BtlWork;

typedef struct FrdBody {
    s32 unk_00;
    s32 x;
    s32 y;
    s32 z;
    s32 unk_10;
    u8 unk_14[0x20];
    u64 flags;
    u8 unk_3C[0x90];
    u16 unk_CC;
    u8 unk_CE[0x42];
} FrdBody;

typedef struct FrdDonaldWork {
    TaskPool unk_000;
    BtlWork* unk_014;
    void* unk_018;
    void* palette;
    FrdBody unk_020;
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
    BtlWork* unk_014;
    void* unk_018;
    void* palette;
    FrdBody unk_020;
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
    BtlWork* unk_014;
    void* unk_018;
    void* palette;
    FrdBody unk_020;
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
    BtlWork* unk_014;
    void* unk_018;
    void* palette;
    FrdBody unk_020;
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
    BtlWork* unk_014;
    void* unk_018;
    void* palette;
    FrdBody unk_020;
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
    BtlWork* unk_014;
    void* unk_018;
    void* palette;
    FrdBody unk_020;
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
    BtlWork* unk_014;
    void* unk_018;
    void* palette;
    FrdBody unk_020;
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

extern GameState gGameState;
extern BtlWork* gBtlWork;
extern BtlWork* gUnk_02039B9C;

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

void ReleaseObjPalette(void* a);
void TaskPoolDestroy(TaskPool* a);
void* AnimGetGfx(AnimState* a);
u16 func_0801AF1C(s32 a);
void WorldToScreen(s16* a, s16* b, s32 c, s32 d, s32 e);
s32 AllocObjAffine(s32 a, s32 b, s32 c, s32 d);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, u16 h);
void TaskPoolDraw(TaskPool* a);
u8 func_0801C6D4(s32* a, s32* b, s32* c, s32* d);
void m4aSongNumStart(u16 n);
void* LoadObjPalette(void* src, s32 size);
void AnimInit(AnimState* a, void* b, void* c);
void func_08019068(void* a, AnimState* b, s32 c, s32 d, void* e);
void func_08017260(s32 a, s32 b, s32 c, s32 d);
void func_08045494(FrdBody* body, u8 a, s16 b, s16 c);
void TaskPoolInit(TaskPool* a, s32 count);
void TaskCreate(TaskPool* pool, void* desc, void* arg);
u16 AnimGetGfxIndex(AnimState* a);
u16 AnimGetFrame(AnimState* a);
u8 AnimIsFinished(AnimState* a);
void* AnimUpdate(AnimState* a);
void TaskPoolUpdate(TaskPool* a);
s32 func_08011F78(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void func_0802F1E8(void);
void ApproachValue(s32* value, s32 target, u16 steps);
void func_08019A30(void);
void func_0800592C(s32* a, s32 b, u16 c);
void func_08006238(s32 a, s32 b, s32 c);
void func_080061E8(s32 a, u16 b);
void func_08048A68(FrdPanWork* work);
void func_0801D288(void);
u16 GetRandom(void);
u8 func_080465F0(FrdGoofyWork* work);
u32 func_0801A8A4(s32* a, s32* b, s32 c, s32 d);
u8 func_080490FC(FrdAladdinWork* work);

#endif /* GUARD_FRD_H */
