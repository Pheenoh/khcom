#include "macros.h"
#include "intr.h"
#include "gba/syscall.h"
#include "key.h"
#include "malloc.h"
#include "main.h"

extern u8 sEwramHeapName[];
extern u8 sIwramHeapName[];

extern u32 gFrameCounter;
extern u32 gUnk_03006C68;
extern u16 gUnk_03006C78;
extern u32 gUnk_03006C10;
extern u32 gUnk_02039828;
extern u32 gUnk_02039820;
extern u16 gUnk_03006C00;

void func_080C55DC(void);
Task* func_08000C54(ListNode* node, TaskPool* a);
void func_08000DE8(TaskPool* a, Task* t);
u8 func_08000F48(Task* t);
u8 func_08000F60(Task* t, const char* name);
const char* func_08000F84(Task* t);
void func_08001100(void);


Task* TaskDestroy(TaskPool* a, Task* t) {
    if (t->unk_00->unk_10 != 0) {
        ((void (*)(void*))t->unk_00->unk_10)(t->unk_04);
    }

    EwramFree(t->unk_04);

    return func_08000C54(&t->unk_0C, a);
}

void func_08000DE8(TaskPool* a, Task* t) {
    if (t->unk_00->unk_10 != 0) {
        ((void (*)(void*))t->unk_00->unk_10)(t->unk_04);
    }

    EwramFree(t->unk_04);

    func_08000C54(&t->unk_0C, a);
}

Task* TaskCreate(void* a, TaskDesc* desc, void* arg) {
    Task* task;

    task = func_08000D0C();

    if (task == 0) {
        return 0;
    }

    if (desc->unk_14 > 0) {
        task->unk_04 = EwramAlloc(desc->unk_14);

        if (task->unk_04 == 0) {
            return 0;
        }
    } else {
        task->unk_04 = 0;
    }

    task->unk_00 = desc;
    task->unk_20 = desc->unk_08;
    func_08000BC8(&task->unk_0C, a);

    if (desc->unk_04 != 0) {
        desc->unk_04(task->unk_04, arg);
    }

    return task;
}

void TaskPoolInit(TaskPool* a, s32 count) {
    Task* t;
    s32 i;

    a->unk_10 = EwramAlloc(count * sizeof(Task));

    if (a->unk_10 == 0) {
        return;
    }

    func_08000BA4(a);

    for (i = 0; i < count; i++) {
        t = &((Task*)a->unk_10)[i];
        func_08000BB0(&t->unk_0C, a, t);
    }
}

void TaskPoolUpdate(TaskPool* a) {
    Task* t;

    t = func_08000C8C(&a->head);

    while (t != 0) {
        if (t->unk_20 != 0 && t->unk_20(t->unk_04, t) == 0) {
            t = TaskDestroy(a, t);
        } else {
            t = func_08000CD4(&t->unk_0C);
        }
    }
}

void TaskPoolDraw(TaskPool* a) {
    Task* t;

    t = func_08000C8C(&a->head);

    while (t != 0) {
        if (t->unk_00->unk_0C != 0) {
            t->unk_00->unk_0C(t->unk_04);
        }

        t = func_08000CD4(&t->unk_0C);
    }
}

void TaskPoolDestroy(TaskPool* a) {
    Task* t;

    t = func_08000C8C(&a->head);

    while (t != 0) {
        t = TaskDestroy(a, t);
    }

    EwramFree(a->unk_10);
}

void func_08000F30(TaskPool* a) {
    Task* t;

    t = func_08000C8C(&a->head);

    if (t != 0) {
        do {
            t = func_08000CD4(&t->unk_0C);
        } while (t != 0);
    }
}

u8 func_08000F48(Task* t) {
    if (t == 0 || (t->unk_0C.unk_0C & 1) == 0) {
        return 0;
    }

    return 1;
}

u8 func_08000F60(Task* t, const char* name) {
    if (t == 0 || name == 0 || t->unk_00->name != name || (t->unk_0C.unk_0C & 1) == 0) {
        return 0;
    }

    return 1;
}

const char* func_08000F84(Task* t) {
    return t->unk_00->name;
}

void func_08000F8C(u8* p, u32 v) {
    *(u32*)(p + 32) = v;
}

s32 func_08000F90(void) {
    return 0;
}

INCLUDE_ASM("taskpool/func_08000F94.s");
INCLUDE_ASM("taskpool/func_08000FB4.s");
INCLUDE_ASM("taskpool/func_08001010.s");
INCLUDE_ASM("taskpool/func_08001058.s");
INCLUDE_ASM("taskpool/func_08001080.s");
INCLUDE_ASM("taskpool/func_0800109C.s");
INCLUDE_ASM("taskpool/func_080010A8.s");
INCLUDE_ASM("taskpool/func_080010B4.s");
INCLUDE_ASM("taskpool/func_080010CC.s");
INCLUDE_ASM("taskpool/func_080010E0.s");
INCLUDE_ASM("taskpool/func_08001100.s");
INCLUDE_ASM("taskpool/func_08001248.s");
INCLUDE_ASM("taskpool/func_08001254.s");
INCLUDE_ASM("taskpool/func_080012A8.s");
INCLUDE_ASM("taskpool/func_080012E0.s");
INCLUDE_ASM("taskpool/func_080012F8.s");
INCLUDE_ASM("taskpool/func_08001304.s");
