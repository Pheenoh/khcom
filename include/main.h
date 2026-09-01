#ifndef GUARD_MAIN_H
#define GUARD_MAIN_H

#include "types.h"

typedef struct HeapBlock {
    s32 size;
    struct HeapBlock* prevFree;
    struct HeapBlock* nextFree;
    struct HeapBlock* prev;
    struct HeapBlock* next;
    u32 unk_14;
    void* name;
    struct HeapBlock* self;
} HeapBlock;

typedef struct Heap {
    HeapBlock* start;
    HeapBlock* end;
    u8 unk_08;
    void* name;
} Heap;

typedef struct ListNode {
    void* unk_00;
    u8 unk_04[0x04];
    struct ListNode* unk_08;
    u16 unk_0C;
} ListNode;

typedef struct TaskDesc {
    const char* name;
    void (*unk_04)(void* work, void* arg);
    void* unk_08;
    void (*unk_0C)(void* work);
    void* unk_10;
    s32 unk_14;
} TaskDesc;

struct Task;

typedef struct Task {
    TaskDesc* unk_00;
    void* unk_04;
    u8 unk_08[0x04];
    ListNode unk_0C;
    u8 unk_1C[0x04];
    u8 (*unk_20)(void* work, struct Task* task);
} Task;

typedef struct TaskPool {
    ListNode head;
    void* unk_10;
} TaskPool;

void* HeapAlloc(u32 size, Heap* heap);
void HeapFree(void* p, Heap* heap);
void* EwramAlloc(u32 size);
void EwramFree(void* p);
Task* func_08000C8C(ListNode* node);
Task* func_08000CD4(ListNode* node);
Task* func_08000D0C(void);
Task* TaskDestroy(TaskPool* a, Task* t);
void func_08000BA4(TaskPool* a);
void func_08000BB0(void* a, void* b);
void func_08000BC8(void* a, void* b);
Task* TaskCreate(void* a, TaskDesc* desc, void* arg);
void TaskPoolInit(TaskPool* a, s32 count);
void TaskPoolUpdate(TaskPool* a);
void TaskPoolDraw(TaskPool* a);
void TaskPoolDestroy(TaskPool* a);
void func_08000F30(TaskPool* a);
void func_08000F8C(u8* p, u32 v);
s32 func_08000F90(void);
u16 GetKeysHeld(void);
u16 GetKeysPressed(void);

extern Heap gEwramHeap;
extern Heap gIwramHeap;
extern u16 gKeysHeld;
extern u16 gKeysPressed;

#endif /* GUARD_MAIN_H */
