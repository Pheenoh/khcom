#ifndef GUARD_MAIN_H
#define GUARD_MAIN_H

#include "types.h"
#include "listpool.h"
#include "key.h"
#include "malloc.h"
#include "taskpool.h"

struct Task;

void func_08000F30(TaskPool* a);
s32 func_08000F90(void);

void InitSystem(void);
void InitIntrTable(void);

void* GetEwramHeapStart(void);
u32 GetEwramHeapSize(void);

#endif /* GUARD_MAIN_H */
