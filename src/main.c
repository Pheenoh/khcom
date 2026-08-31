#include "macros.h"
#include "main.h"

INCLUDE_ASM("main/func_08000240.s");
INCLUDE_ASM("main/func_08000248.s");
INCLUDE_ASM("main/func_08000250.s");
INCLUDE_ASM("main/func_08000258.s");
INCLUDE_ASM("main/func_080002D4.s");
INCLUDE_ASM("main/func_08000300.s");
INCLUDE_ASM("main/func_080007A8.s");
INCLUDE_ASM("main/func_080007B8.s");
INCLUDE_ASM("main/func_080007D4.s");
INCLUDE_ASM("main/func_08000800.s");
INCLUDE_ASM("main/func_08000860.s");
INCLUDE_ASM("main/func_08000884.s");
INCLUDE_ASM("main/func_080008A8.s");

void* func_08000918(u32 size) {
    return func_080008A8(size, gUnk_030074A8);
}

INCLUDE_ASM("main/func_08000928.s");
INCLUDE_ASM("main/func_08000938.s");

void func_080009C4(void* p) {
    func_08000938(p, gUnk_030074A8);
}

INCLUDE_ASM("main/func_080009D4.s");
INCLUDE_ASM("main/func_080009E4.s");
INCLUDE_ASM("main/func_08000AD8.s");
INCLUDE_ASM("main/func_08000AE4.s");
INCLUDE_ASM("main/func_08000B08.s");
INCLUDE_ASM("main/func_08000B24.s");
INCLUDE_ASM("main/func_08000B48.s");
INCLUDE_ASM("main/func_08000B6C.s");
INCLUDE_ASM("main/func_08000BA4.s");
INCLUDE_ASM("main/func_08000BB0.s");
INCLUDE_ASM("main/func_08000BC8.s");
INCLUDE_ASM("main/func_08000BF4.s");
INCLUDE_ASM("main/func_08000C24.s");
INCLUDE_ASM("main/func_08000C54.s");

Task* func_08000C8C(ListNode* node) {
    ListNode* n;
    Task* result;

    n = node->unk_08;

    if (n != 0) {
        if (n->unk_0C & 2) {
            return func_08000CD4(n);
        }

        result = n->unk_00;
    } else {
        result = 0;
    }

    return result;
}

INCLUDE_ASM("main/func_08000CB0.s");

Task* func_08000CD4(ListNode* node) {
    ListNode* n;
    Task* result;

    n = node->unk_08;

    if (n != 0) {
        if (n->unk_0C & 2) {
            return func_08000CD4(n);
        }

        result = n->unk_00;
    } else {
        result = 0;
    }

    return result;
}

INCLUDE_ASM("main/func_08000CF0.s");
INCLUDE_ASM("main/func_08000D0C.s");
INCLUDE_ASM("main/func_08000D20.s");
INCLUDE_ASM("main/func_08000D28.s");
INCLUDE_ASM("main/func_08000D6C.s");
INCLUDE_ASM("main/func_08000D90.s");
INCLUDE_ASM("main/func_08000DBC.s");
INCLUDE_ASM("main/func_08000DE8.s");

Task* func_08000E14(void* a, TaskDesc* desc, void* arg) {
    Task* task;

    task = func_08000D0C();

    if (task == 0) {
        return 0;
    }

    if (desc->unk_14 > 0) {
        task->unk_04 = func_08000918(desc->unk_14);

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

INCLUDE_ASM("main/func_08000E64.s");

void func_08000EA4(TaskPool* a) {
    Task* t;

    t = func_08000C8C(&a->head);

    while (t != 0) {
        if (t->unk_20 != 0 && t->unk_20(t->unk_04, t) == 0) {
            t = func_08000DBC(a, t);
        } else {
            t = func_08000CD4(&t->unk_0C);
        }
    }
}

void func_08000EE0(TaskPool* a) {
    Task* t;

    t = func_08000C8C(&a->head);

    while (t != 0) {
        if (t->unk_00->unk_0C != 0) {
            t->unk_00->unk_0C(t->unk_04);
        }

        t = func_08000CD4(&t->unk_0C);
    }
}

void func_08000F0C(TaskPool* a) {
    Task* t;

    t = func_08000C8C(&a->head);

    while (t != 0) {
        t = func_08000DBC(a, t);
    }

    func_080009C4(a->unk_10);
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

INCLUDE_ASM("main/func_08000F48.s");
INCLUDE_ASM("main/func_08000F60.s");
INCLUDE_ASM("main/func_08000F84.s");

void func_08000F8C(u8* p, u32 v) {
    *(u32*)(p + 32) = v;
}

s32 func_08000F90(void) {
    return 0;
}

INCLUDE_ASM("main/func_08000F94.s");
INCLUDE_ASM("main/func_08000FB4.s");
INCLUDE_ASM("main/func_080010CC.s");
INCLUDE_ASM("main/func_080010E0.s");
INCLUDE_ASM("main/func_08001248.s");
INCLUDE_ASM("main/func_08001254.s");
INCLUDE_ASM("main/func_080012A8.s");

u16 func_08001384(void) {
    return gUnk_02034000;
}

u16 func_08001390(void) {
    return gUnk_02034002;
}

INCLUDE_ASM("main/func_0800139C.s");
INCLUDE_ASM("main/func_08001470.s");
INCLUDE_ASM("main/func_08001534.s");
INCLUDE_ASM("main/func_080015F8.s");
INCLUDE_ASM("main/func_08001D60.s");
INCLUDE_ASM("main/func_08001DB0.s");
INCLUDE_ASM("main/func_08001E64.s");
INCLUDE_ASM("main/func_08001EF8.s");
INCLUDE_ASM("main/func_08001F20.s");
INCLUDE_ASM("main/func_08001F5C.s");
INCLUDE_ASM("main/func_08001F98.s");
INCLUDE_ASM("main/func_08002060.s");
