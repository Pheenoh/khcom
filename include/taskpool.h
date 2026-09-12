#ifndef GUARD_TASKPOOL_H
#define GUARD_TASKPOOL_H

#include "types.h"
#include "listpool.h"

typedef struct TaskPool {
    ListPool head;
    void* tasks;
} TaskPool;

typedef struct TaskDesc {
    const char* name;
    void (*init)(void* work, void* arg);
    void* update;
    void (*draw)(void* work);
    void (*destroy)(void* work);
    s32 workSize;
} TaskDesc;

typedef struct Task {
    TaskDesc* desc;
    void* work;
    u8 unk_08[0x04];
    ListNode node;
    u8 (*update)(void* work, struct Task* task);
} Task;

typedef char TaskPool_size[(sizeof(TaskPool) == 0x14) ? 1 : -1];
typedef char Task_size[(sizeof(Task) == 0x24) ? 1 : -1];

Task* TaskCreate(TaskPool* pool, TaskDesc* desc, void* arg);
Task* TaskDestroy(TaskPool* pool, Task* task);
void TaskPoolInit(TaskPool* pool, s32 count);
void TaskPoolUpdate(TaskPool* pool);
void TaskPoolDraw(TaskPool* pool);
void TaskPoolDestroy(TaskPool* pool);

#endif
