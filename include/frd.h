#ifndef GUARD_FRD_H
#define GUARD_FRD_H

#include "types.h"
#include "anim.h"
#include "taskpool.h"

typedef struct FrdArgs {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
} FrdArgs;

typedef struct FrdObj {
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
    s32 unk_078;
    struct FrdObj* unk_07C;
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
    u8 unk_118[0xB0];
} FrdObj;

typedef struct FrdBody {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    u8 unk_14[0x20];
    u64 unk_34;
    u8 unk_3C[0x90];
    u16 unk_CC;
    u8 unk_CE[0x42];
} FrdBody;

typedef struct FrdDonaldWork {
    TaskPool unk_000;
    FrdObj* unk_014;
    void* unk_018;
    void* unk_01C;
    FrdBody unk_020;
    AnimState unk_130;
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
    FrdObj* unk_014;
    void* unk_018;
    void* unk_01C;
    FrdBody unk_020;
    AnimState unk_130;
    s32 unk_148;
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
    FrdObj* unk_014;
    void* unk_018;
    void* unk_01C;
    FrdBody unk_020;
    AnimState unk_130;
    s32 unk_148;
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
    FrdObj* unk_014;
    void* unk_018;
    void* unk_01C;
    FrdBody unk_020;
    AnimState unk_130;
    s32 unk_148;
    u8 unk_14C;
    u8 unk_14D;
    s16 unk_14E;
    s16 unk_150;
    s16 unk_152;
    s32 unk_154;
    s16 unk_158;
    s16 unk_15A;
    s32 unk_15C;
    s32 unk_160;
    s32 unk_164;
    s16 unk_168;
    u8 unk_16A[0x02];
} FrdJackWork;

typedef struct FrdPanWork {
    TaskPool unk_000;
    FrdObj* unk_014;
    void* unk_018;
    void* unk_01C;
    FrdBody unk_020;
    AnimState unk_130;
    s32 unk_148;
    u8 unk_14C;
    u8 unk_14D;
    s16 unk_14E;
    s16 unk_150;
    s16 unk_152;
    s16 unk_154;
    s16 unk_156;
    s16 unk_158;
    s16 unk_15A;
    s32 unk_15C;
    s32 unk_160;
    s32 unk_164;
    s32 unk_168;
    u8 unk_16C;
    u8 unk_16D[0x03];
} FrdPanWork;

typedef struct FrdAladdinWork {
    TaskPool unk_000;
    FrdObj* unk_014;
    void* unk_018;
    void* unk_01C;
    FrdBody unk_020;
    AnimState unk_130;
    s32 unk_148;
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
    FrdObj* unk_014;
    void* unk_018;
    void* unk_01C;
    FrdBody unk_020;
    AnimState unk_130;
    s32 unk_148;
    u8 unk_14C;
    u8 unk_14D;
    s16 unk_14E;
    s32 unk_150;
    s32 unk_154;
    s32 unk_158;
    s32 unk_15C;
} FrdBeastWork;

extern FrdObj* gUnk_02039B84;
extern FrdObj* gUnk_02039B9C;

extern u8 gUnk_09EDAE88[];
extern s16 gSineTable[];

void ReleaseObjPalette(void* a);
void TaskPoolDestroy(TaskPool* a);
void* AnimGetGfx(AnimState* a);
u16 func_0801AF1C(s32 a);
void WorldToScreen(s16* a, s16* b, s32 c, s32 d, s32 e);
s32 AllocObjAffine(s32 a, s32 b, s32 c, s32 d);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, u16 h);
void TaskPoolDraw(TaskPool* a);
void func_0801C6D4(s32* a, s32* b, s32* c, s32* d);

#endif /* GUARD_FRD_H */
