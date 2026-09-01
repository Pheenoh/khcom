#ifndef GUARD_ROOMCREATE_H
#define GUARD_ROOMCREATE_H

#include "types.h"

typedef struct ListNode {
    void* unk_00;
    u8 unk_04[0x04];
    struct ListNode* unk_08;
    u16 unk_0C;
} ListNode;

typedef struct TaskPool {
    ListNode head;
    void* unk_10;
} TaskPool;

typedef struct TaskDesc {
    const char* name;
    void (*unk_04)(void* work, void* arg);
    void* unk_08;
    void (*unk_0C)(void* work);
    void* unk_10;
    s32 unk_14;
} TaskDesc;

typedef struct FldPos {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} FldPos;

typedef struct FldActor {
    FldPos unk_00;
    s32 unk_10;
    u8 unk_14;
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
extern u8 gUnk_0203DB10[];
extern TaskDesc gUnk_09EDB380;
extern TaskDesc gUnk_09EDB398;
extern TaskDesc gUnk_09EE7668;

struct Task;

struct Task* TaskCreate(TaskPool* pool, TaskDesc* desc, void* arg);
void TaskPoolInit(TaskPool* pool, s32 count);
void TaskPoolUpdate(TaskPool* pool);
void TaskPoolDraw(TaskPool* pool);
void TaskPoolDestroy(TaskPool* pool);
void SetBgPriority(s32 bg, u16 priority);
void DisableBg(s32 bg);
void func_080058FC(s32* value, s32 target, u16 steps);
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
