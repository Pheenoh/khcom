#ifndef GUARD_FLD_H
#define GUARD_FLD_H

#include "types.h"
#include "taskpool.h"
#include "key.h"
#include "game.h"
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

extern UnkStruct_02039BA0* gUnk_02039BA0;

typedef struct GameState {
    u8 unk_00;
    u8 unk_01[0x13];
    FldPos unk_14;
    u8 unk_24;
    u8 unk_25[0x03];
    s32 unk_28;
    s32 unk_2C;
    u16 unk_30;
    u8 unk_32[0x02];
    s32 unk_34;
    s32 unk_38;
    s32 unk_3C;
} GameState;

extern GameState gGameState;
typedef struct FldWork {
    void* tiles;
    FldRes* palette;
    u8 unk_08[0x0A];
    u16 unk_12;
    u8 unk_14[0x02];
    u16 unk_16;
    u8 unk_18[0x08];
    void* unk_20;
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
extern FldAnimDef gUnk_0813CDDC[][5];

typedef struct FldShadowWork {
    s32 unk_00;
    s32 unk_04;
    void* tiles;
    void* palette;
    FldActor* unk_10;
    u8 unk_14[0x18];
} FldShadowWork;

void AnimInit(void* a, void* b, void* c);
void AnimStart(void* a, s32 b, s32 c);
void* AnimUpdate(void* a);
s8 GetAngleDiff(u8 a, u8 b);
void func_08002A10(void* a, void* b);
void func_08005974(void* a, u8 b, u16 c, void* d, void* e);
void func_0803473C(FldWork* work, s32 index, u16 flags);
u8 GetKeyReleaseTime(s32 a);
void TaskPoolUpdate(TaskPool* pool);
void SetTaskUpdate(void* task, void* fn);
u8 AnimIsFinished(void* a);
void func_080062F4(u16 a, s32 b);
void func_08012324(void* a, s32 x, s32 y, s32 z);
void func_080E0298(s32 a, s32 b);
void m4aSongNumStart(u16 a);
u8 func_080DFC24(void);
u8 func_08031D74(FldPos* p);
s32 func_08031DF8(FldPos* p);
u8 func_08031E48(FldPos* p, FldWork* work);
u8 func_08031EC4(FldPos* p);
s32 func_08031F1C(FldWork* work);
void func_08031F60(FldActor* act);
void func_08031F98(FldWork* work, s32 a, s32 b);

extern u8 gUnk_08B22BBC[];
extern u8 gUnk_08F69BE4[];
extern u8 gUnk_09EE1380[];
extern u8 gUnk_09EE1384[];
extern s16 gSineTable[];

s32 func_080DFF1C(FldPos* p);
u8 func_080DFCDC(FldPos* p);
u8 func_080DFBDC(FldPos* p);
u8 _080DFE1C(FldPos* p);

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
u8 task_fld_sora_1(FldWork* work, void* task);
void task_fld_sora_2(FldWork* work);
void task_fld_sora_3(FldWork* work);
void task_fld_riku_2(FldWork* work);
void task_fld_riku_3(FldWork* work);
void task_fld_shadow_0(FldShadowWork* work, FldActor* obj);
s32 task_fld_shadow_1(FldShadowWork* work);
void task_fld_shadow_2(FldShadowWork* work);
void task_fld_shadow_3(FldShadowWork* work);

#endif /* GUARD_FLD_H */
