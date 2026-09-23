#ifndef GUARD_TASKPOOL_H
#define GUARD_TASKPOOL_H

#include "types.h"
#include "listpool.h"

typedef struct TaskPool {
    ListPool head;
    void* tasks;
} TaskPool;

struct Task;

typedef void (*TaskInitFunc)(void* work, void* arg);
typedef u8 (*TaskUpdateFunc)(void* work, struct Task* task);
typedef void (*TaskFunc)(void* work);

typedef struct TaskDesc {
    const char* name;
    TaskInitFunc init;
    TaskUpdateFunc update;
    TaskFunc draw;
    TaskFunc destroy;
    s32 workSize;
} TaskDesc;

typedef struct Task {
    TaskDesc* desc;
    void* work;
    u8 unk_08[0x04];
    ListNode node;
    TaskUpdateFunc update;
} Task;

typedef char TaskPool_size[(sizeof(TaskPool) == 0x14) ? 1 : -1];
typedef char Task_size[(sizeof(Task) == 0x24) ? 1 : -1];

Task* TaskCreate(TaskPool* pool, TaskDesc* desc, void* arg);
Task* TaskDestroy(TaskPool* pool, Task* task);
void func_08000DE8(TaskPool* pool, Task* task);
u8 IsTaskActive(Task* task);
u8 IsTaskActiveNamed(Task* task, const char* name);
const char* GetTaskName(Task* task);
void SetTaskUpdate(Task* task, TaskUpdateFunc update);
void TaskPoolInit(TaskPool* pool, s32 count);
void TaskPoolUpdate(TaskPool* pool);
void TaskPoolDraw(TaskPool* pool);
void TaskPoolDestroy(TaskPool* pool);

#endif
