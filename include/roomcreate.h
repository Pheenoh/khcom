#ifndef GUARD_ROOMCREATE_H
#define GUARD_ROOMCREATE_H

#include "types.h"
#include "taskpool.h"
#include "fld_types.h"
typedef struct FldActor {
    FldPos unk_00;
    s32 unk_10;
    u8 angle;
    u8 unk_15[0x3B];
} FldActor;

typedef struct UnkStruct_02039BA0 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10[0x08];
    FldActor unk_18;
    FldActor* unk_68;
    u8 unk_6C[0x04];
    u32 unk_70;
} UnkStruct_02039BA0;

typedef struct RoomCreateWork {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    u8 unk_24;
    u8 unk_25;
    s16 unk_26;
    u8 unk_28;
    u8 unk_29;
    u8 unk_2A[0x02];
    TaskPool unk_2C;
    s32 unk_40;
} RoomCreateWork;

extern UnkStruct_02039BA0* gUnk_02039BA0;
extern s16 gSineTable[];
extern u8 gMPlayInfo_BGM[];
extern TaskDesc gTaskDescRomcriEff;
extern TaskDesc gTaskDescRomcriEff2;
extern TaskDesc gTaskDescSpotLight;

struct Task;

struct Task* TaskCreate(TaskPool* pool, TaskDesc* desc, void* arg);
void TaskPoolInit(TaskPool* pool, s32 count);
void TaskPoolUpdate(TaskPool* pool);
void TaskPoolDraw(TaskPool* a);
void TaskPoolDestroy(TaskPool* pool);
void SetBgPriority(s32 bg, u16 priority);
void DisableBg(s32 bg);
void ApproachValue(s32* value, s32 target, u16 steps);
void func_08006120(s32 a, s32 b);
void func_080062F4(u16 a, s32 b);
void func_08093B78(TaskPool* pool, u8* p);
void func_08093C04(void);
u8 func_080DFD84(FldPos* p);
void func_080E0298(s32 a, s32 b);
void func_080E0418(void);
void func_080E042C(void);
void m4aSongNumStart(u16 song);
void m4aMPlayVolumeControl(void* mplay, u16 trackBits, u16 volume);

void task_roomcreate_0(RoomCreateWork* work);
u8 task_roomcreate_1(RoomCreateWork* work);
void task_roomcreate_2(RoomCreateWork* work);
void task_roomcreate_3(RoomCreateWork* work);

#endif /* GUARD_ROOMCREATE_H */
