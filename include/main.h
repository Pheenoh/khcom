#ifndef GUARD_MAIN_H
#define GUARD_MAIN_H

#include "types.h"

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

void* func_080008A8(u32 size, void* heap);
void func_08000938(void* p, void* heap);
void* func_08000918(u32 size);
void func_080009C4(void* p);
Task* func_08000C8C(ListNode* node);
Task* func_08000CD4(ListNode* node);
Task* func_08000D0C(void);
Task* func_08000DBC(TaskPool* a, Task* t);
void func_08000BA4(TaskPool* a);
void func_08000BB0(void* a, void* b);
void func_08000BC8(void* a, void* b);
Task* func_08000E14(void* a, TaskDesc* desc, void* arg);
void func_08000E64(TaskPool* a, s32 count);
void func_08000EA4(TaskPool* a);
void func_08000EE0(TaskPool* a);
void func_08000F0C(TaskPool* a);
void func_08000F30(TaskPool* a);
void func_08000F8C(u8* p, u32 v);
s32 func_08000F90(void);
u16 func_08001384(void);
u16 func_08001390(void);

extern u8 gUnk_030074A8[];
extern u16 gUnk_02034000;
extern u16 gUnk_02034002;

#endif /* GUARD_MAIN_H */
