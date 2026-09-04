#ifndef GUARD_MAIN_H
#define GUARD_MAIN_H

#include "types.h"
#include "key.h"
#include "malloc.h"
#include "taskpool.h"

struct Task;

Task* ListPoolFirst(ListNode* node);
Task* ListPoolNext(ListNode* node);
Task* ListPoolFirstFree(void);
Task* TaskDestroy(TaskPool* a, Task* t);
void ListPoolInit(TaskPool* a);
void ListPoolAddFree(ListNode* node, TaskPool* pool, void* owner);
void ListPoolActivate(void* a, void* b);
Task* TaskCreate(void* a, TaskDesc* desc, void* arg);
void TaskPoolInit(TaskPool* a, s32 count);
void TaskPoolUpdate(TaskPool* pool);
void TaskPoolDraw(TaskPool* a);
void TaskPoolDestroy(TaskPool* a);
void func_08000F30(TaskPool* a);
void SetTaskUpdate(u8* p, u32 v);
s32 func_08000F90(void);

void InitSystem(void);
void InitIntrTable(void);

#endif /* GUARD_MAIN_H */
