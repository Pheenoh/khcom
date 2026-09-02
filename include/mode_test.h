#ifndef GUARD_MODE_TEST_H
#define GUARD_MODE_TEST_H

#include "types.h"
#include "anim.h"
#include "mode.h"
#include "taskpool.h"
#include "gba/syscall.h"

#define CPU_SET_SRC_FIXED 0x01000000
#define CPU_SET_32BIT     0x04000000

typedef struct FldObj {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10[0x0A];
    s16 unk_1A;
    ListNode unk_1C;
    u8 unk_2C[0x04];
    u16 unk_30;
    u8 unk_32[0x02];
} FldObj;

typedef struct UnkStruct_02039BA0 {
    s32 unk_00;
    s32 unk_04;
    u8 unk_08[0x10];
    s32 unk_18;
    s32 unk_1C;
    u8 unk_20[0x04];
    s32 unk_24;
    u8 unk_28[0x04];
    u8 unk_2C;
    u8 unk_2D[0x2B];
    ListNode unk_58;
    FldObj* unk_68;
    u8 unk_6C[0x04];
    u32 unk_70;
} UnkStruct_02039BA0;

typedef struct UnkStruct_02039DC8 {
    u8 unk_00[0x74];
    s32 unk_74;
    u8 unk_78[0x02];
    u8 unk_7A;
    u8 unk_7B;
    u8 unk_7C[0x10];
} UnkStruct_02039DC8;

typedef struct UnkStruct_09EE3CA0 {
    u8 unk_00[0x24];
    u8 unk_24;
    u8 unk_25[0x03];
} UnkStruct_09EE3CA0;

typedef struct UnkStruct_09EE3FB4_08 {
    u8 unk_00[0x14];
    u32 unk_14;
} UnkStruct_09EE3FB4_08;

typedef struct UnkStruct_09EE3FB4 {
    u8 unk_00[0x08];
    UnkStruct_09EE3FB4_08* unk_08;
} UnkStruct_09EE3FB4;

typedef struct EvtArg {
    u32 unk_00 : 8;
    u32 unk_08 : 8;
    u32 unk_10 : 16;
} EvtArg;

typedef struct UnkStruct_02039DC4 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} UnkStruct_02039DC4;

typedef struct CardStat {
    u16 unk_00;
    u16 unk_02;
    u8 unk_04;
    u8 unk_05[0x03];
    u32 unk_08;
    u16 unk_0C;
    u8 unk_0E;
    u8 unk_0F;
    u16 unk_10;
    u8 unk_12[0x06];
} CardStat;

typedef struct CardDef {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    void* unk_14;
    void* unk_18;
    CardStat unk_1C;
} CardDef;

typedef struct UnkStruct_02039BB0 {
    u8 unk_000[0x08];
    u32 unk_008;
} UnkStruct_02039BB0;

typedef struct MenuWork {
    void* unk_00;
    void* unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10;
    u8 unk_11;
    u8 unk_12[0x02];
} MenuWork;

typedef struct ContinueWork {
    u8 unk_00[0x60];
    s32 unk_60;
    u8 unk_64[0x06];
    u8 unk_6A;
    u8 unk_6B;
} ContinueWork;

typedef struct UnkStruct_02034A5C {
    TaskDesc* unk_00;
    ContinueWork* unk_04;
} UnkStruct_02034A5C;

typedef struct UnkStruct_02034A1C {
    u16 unk_00[61];
    u8 unk_7A;
    u8 unk_7B;
    u8 unk_7C;
    u8 unk_7D;
    u8 unk_7E[6];
} UnkStruct_02034A1C;

typedef struct LockonWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    FldObj* unk_0C[8];
    u8 unk_2C;
    s8 unk_2D;
    s8 unk_2E;
    u8 unk_2F;
    u8 unk_30;
    u8 unk_31[3];
    AnimState unk_34;
    u8 unk_4C;
    u8 unk_4D[3];
} LockonWork;

void* EwramAlloc(s32 size);
void EwramFree(void* p);
u16 GetKeysRepeat(void);
void* LoadObjTiles(void* a, s32 b);
void ReleaseObjTiles(void* a);
void* AllocObjTiles(s32 a, s32 b);
void func_08002A10(void* a, void* b);
void* LoadObjPalette(void* a, s32 b);
void ReleaseObjPalette(void* a);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, s32 h);
void AnimInit(AnimState* a, void* b, void* c);
void AnimStart(AnimState* a, u16 animId, u16 flags);
void* AnimGetGfx(AnimState* a);
void* AnimUpdate(AnimState* a);
u32 Sqrt(u32 a);
void* GetBgCharBase(s32 bg);
void* GetBgScreenBase(s32 bg);
void EnableBg(s32 bg);
void LoadPalette(void* src, void* dst, s32 size);
void TaskPoolInit(TaskPool* pool, s32 count);
void TaskPoolUpdate(TaskPool* pool);
void TaskPoolDraw(TaskPool* pool);
void TaskPoolDestroy(TaskPool* pool);
void* TaskCreate(TaskPool* pool, TaskDesc* desc, void* arg);
void ModeRequest(Mode* mode, s32 arg);
void UpdatePlayTime(void);
void func_080B0754(void);
void func_080E052C(u8 a);
void m4aMPlayAllStop(void);
void m4aSongNumStart(u16 id);
u16 GetKeysPressed(void);
void func_0801CB0C(void);
void func_08006184(s32 a, u16 b);
u8 func_08006314(void);
void func_080E04EC(void);
void func_08004DB0(void);
void func_08004E64(void);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void SetBgPriority(s32 bg, u16 priority);
void DisableBg(s32 bg);
void func_08006120(s32 a, s32 b);
void func_080A42B4(void);
void func_08061824(void);
u8 func_080A42C8(void);
FldObj* func_08000C8C(ListNode* node);
FldObj* func_08000CD4(ListNode* node);

void mode_test_0(void);
void mode_test_1(void);
void mode_test_2(void);
void func_0805F1C0(s32* p, s32 v);
s32 func_0805F588(s32 a, s32 b);
s32 func_0805F5A4(s32* x, s32* y);
void func_0805F66C(LockonWork* w);
void func_0805F728(s32* x, s32* y);
void func_0805F770(void);
void func_0805F7B0(s32 a);
void func_0805F7BC(void);
void func_0805F7C8(u8 a);
u8 func_0805F8F0(u8 a);
void func_0805F904(void);
void func_0805FA60(s32 a, void* b, s32 c, u8 d);
void func_0805FA8C(u8 bg, u16 b, u16 c);
void func_0805FB78(s32 a);
void func_0805FB84(u8 x, u8 y, u32 c, u8 v);
void func_0805FC04(u8 x, u8 y, u32 c, u16 v);
void func_0805FCB0(u8 x, u8 y, u32 c, const char* s);
u16 func_080609AC(u16 a);
u16 func_08060A2C(u16 a);
void func_08060A74(void);
void func_08060AD8(void);
void func_08060BAC(void);
void func_08060BBC(MenuWork* w);
u8 func_08060C18(MenuWork* w);
void func_08060E64(MenuWork* w);
void func_08060EA0(MenuWork* w);
void func_08060ED8(void);
void func_08060F1C(void);
void func_08060F64(void);
void task_lockon_0(LockonWork* w);
s8 func_0805F5D8(s32 a, s32 b, LockonWork* w, s8 n, s8* list);
u8 func_0805F6B4(u16 a, s32 b, s32 c, FldObj* d);
void func_08060F74(s32 arg);
void func_0806119C(void);
void func_080617E8(void);
u8 task_lockon_1(LockonWork* w);
void task_lockon_2(LockonWork* w);
void task_lockon_3(LockonWork* w);
void func_0805F7E8(u8 x, u8 y, u16* s);
void func_08060470(u8 bg);
void func_08060598(void);
void func_0806098C(void);
void func_080609A0(void);

extern void* gUnk_02034A08;
extern void* gUnk_02034A0C;
extern s32 gUnk_02034A10;
extern u8 gUnk_02034A18;
extern UnkStruct_02034A1C* gUnk_02034A1C;
extern u8 gUnk_02034A20;
extern u8 gUnk_02034A21;
extern s32 gUnk_02034A24;
extern s32 gUnk_02034A28;
extern void* gUnk_02034A2C;
extern UnkStruct_02039BA0* gUnk_02039BA0;
extern UnkStruct_02039DC4* gUnk_02039DC4;
extern UnkStruct_02039DC8* gUnk_02039DC8;
extern u8 gUnk_02034A74;
extern s32 gUnk_02034A78;
extern u16 gBldCnt;
extern u16 gBldAlpha;
extern UnkStruct_09EE3CA0* gUnk_09EE3CA0[];
extern UnkStruct_09EE3FB4* gUnk_09EE3FB4[];
extern TaskDesc gUnk_09EE46D4;
extern u8 gUnk_02034A7C;
extern Mode gUnk_09EE47AC;
extern TaskPool gUnk_02034A60;
extern const s16 gSineTable[];
extern TaskPool gUnk_02034A30;
extern TaskPool gUnk_02034A48;
extern UnkStruct_02034A5C* gUnk_02034A5C;
extern u8 gUnk_02034A44;
extern u32 gUnk_03006C10;
extern vu16 gSystemFlags;
extern UnkStruct_02039BB0 gUnk_02039BB0;
extern void* gUnk_09EE14D4[];
extern CardDef gCardDefs[];
extern Mode gUnk_09ECEB54;
extern Mode gUnk_09EE2704;
extern Mode gUnk_09EF14DC;
extern Mode gUnk_09EF4DB0;
extern TaskDesc gUnk_09EE2834;
extern TaskDesc gUnk_09EE284C;
extern TaskDesc gUnk_09EE4AF4;
extern TaskDesc gUnk_09EE8EF0;
extern u8 gUnk_08B24DAA[];
extern u8 gUnk_090D4DD0[];
extern u8 gUnk_090D7C84[];
extern u8 gUnk_0941DD38[];
extern u8 gUnk_096148B8[];
extern void* gUnk_09EEC600[];
extern u8 gUnk_09EEC660[];
extern u8 gUnk_09EEC66C[];
extern u8 gUnk_08F69BA4[];
extern u8 gUnk_08F69BE4[];

#endif /* GUARD_MODE_TEST_H */
