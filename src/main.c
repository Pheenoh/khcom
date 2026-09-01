#include "macros.h"
#include "main.h"

extern u8 gUnk_081213DC[];
extern u8 gUnk_081213E8[];

extern u32 gFrameCounter;
extern u32 gUnk_03006C68;
extern u16 gUnk_03006C78;
extern u32 gUnk_03006C10;
extern u32 gUnk_02039828;
extern u32 gUnk_02039820;
extern u16 gUnk_03006C00;

void InitSystem(void);
void EnableVBlankIntr(void);
void UpdateKeyState(void);
void func_080C55DC(void);
void func_08001100(void);
void ApplyIntrCallbacks(void);
void VBlankIntrWait(void);

void SetEwramHeapName(void* name);
void SetIwramHeapName(void* name);

INCLUDE_ASM("main/func_08000240.s");
INCLUDE_ASM("main/func_08000248.s");
INCLUDE_ASM("main/func_08000250.s");
INCLUDE_ASM("main/func_08000258.s");
INCLUDE_ASM("main/EnableVBlankIntr.s");
INCLUDE_ASM("main/DisableVBlankIntr.s");
INCLUDE_ASM("main/EnableHBlankIntr.s");
INCLUDE_ASM("main/DisableHBlankIntr.s");
INCLUDE_ASM("main/InitSystem.s");
#ifdef NON_MATCHING
void AgbMain(void) {
    s32 bit;

    gFrameCounter = 0;
    gUnk_03006C68 = 0;
    gUnk_03006C78 = 0;
    gUnk_03006C10 = 0;
    gUnk_02039828 = 0;
    gUnk_02039820 = 0;
    InitSystem();
    EnableVBlankIntr();
    bit = 4;
    for (;;) {
        UpdateKeyState();
        if (gUnk_03006C78 & 1) {
            func_080C55DC();
            if (gUnk_02039820 & 0x100) {
                goto next;
            }
        }
        if ((gUnk_03006C00 & bit) == 0) {
            func_08001100();
            gUnk_03006C00 |= 4;
        }
    next:
        ApplyIntrCallbacks();
        VBlankIntrWait();
        gFrameCounter++;
    }
}
#else
INCLUDE_ASM("main/AgbMain.s");
#endif
INCLUDE_ASM("main/VBlankIntr.s");
INCLUDE_ASM("main/HBlankIntrDummy.s");
INCLUDE_ASM("main/VCountIntrDummy.s");
INCLUDE_ASM("main/SerialIntrDummy.s");
INCLUDE_ASM("main/InitIntrTable.s");
INCLUDE_ASM("main/ApplyIntrCallbacks.s");
INCLUDE_ASM("main/VBlankIntrSio.s");
INCLUDE_ASM("main/func_08000714.s");

void HeapUnlinkFreeBlock(HeapBlock* b) {
    b->prevFree->nextFree = b->nextFree;
    b->nextFree->prevFree = b->prevFree;
}

u8 HeapContains(void* p, Heap* heap) {
    if (p != 0 && (u32)p > (u32)heap->start && (u32)p < (u32)heap->end) {
        return 1;
    }
    
    return 0;
}

HeapBlock* HeapFindFreeBlock(s32 size, Heap* heap) {
    HeapBlock* b;

    b = heap->start->nextFree;
    while (b != 0 && b != heap->end) {
        if (b->size >= size) {
            return b;
        }
        b = b->nextFree;
    }
    return 0;
}

#ifdef NON_MATCHING
void HeapInit(void* addr, u32 size, Heap* heap) {
    HeapBlock* head;
    HeapBlock* tail;
    HeapBlock* first;
    void* name;

    size &= ~31;
    head = addr;
    tail = (HeapBlock*)((u8*)addr + (size - 32));
    heap->start = head;
    heap->end = tail;
    first = (HeapBlock*)((u8*)addr + 32);
    head->size = -32;
    head->prevFree = 0;
    head->nextFree = first;
    head->prev = 0;
    head->next = first;
    name = heap->name;
    head->name = name;
    head->self = head;
    tail->size = -1;
    tail->prevFree = first;
    tail->nextFree = 0;
    tail->prev = first;
    tail->next = 0;
    tail->name = name;
    tail->self = tail;
    first->size = size - 64;
    first->prevFree = head;
    first->nextFree = tail;
    first->prev = head;
    first->next = tail;
    first->name = name;
    first->self = first;
    heap->unk_08 = 0;
}
#else
INCLUDE_ASM("main/HeapInit.s");
#endif

void EwramHeapInit(void* addr, u32 size) {
    SetEwramHeapName(gUnk_081213DC);
    HeapInit(addr, size, &gEwramHeap);
}

void IwramHeapInit(void* addr, u32 size) {
    SetIwramHeapName(gUnk_081213E8);
    HeapInit(addr, size, &gIwramHeap);
}

void* HeapAlloc(u32 size, Heap* heap) {
    HeapBlock* b;
    HeapBlock* prev;
    s32 rem;

    if (size == 0) {
        return 0;
    }

    size = (size + 63) & ~31;
    b = HeapFindFreeBlock(size, heap);

    if (b == 0) {
        return 0;
    }

    if (b->size < (s32)(size + 64)) {
        size = b->size;
        HeapUnlinkFreeBlock(b);
    } else {
        prev = b;
        rem = prev->size - size;
        prev->size = rem;
        b = (HeapBlock*)((u8*)prev + rem);
        b->next = prev->next;
        b->prev = prev;
        prev->next = b;
        b->next->prev = b;
    }

    b->size = -size;
    b->prevFree = 0;
    b->nextFree = 0;

    if (heap->unk_08 != 0) {
        b->unk_14 = 1;
    } else {
        b->unk_14 = 0;
    }

    b->name = heap->name;
    b->self = b;

    return b + 1;
}

void* EwramAlloc(u32 size) {
    return HeapAlloc(size, &gEwramHeap);
}

void* IwramAlloc(u32 size) {
    return HeapAlloc(size, &gIwramHeap);
}

void HeapFree(void* p, Heap* heap) {
    HeapBlock* b;
    HeapBlock* n;
    HeapBlock* head;
    s32 size;

    if (p == 0) {
        return;
    }

    b = (HeapBlock*)p - 1;

    if (b->self != b) {
        return;
    }

    if (!HeapContains(p, heap)) {
        return;
    }

    size = -b->size;

    if (size < 0) {
        return;
    }

    b->size = size;
    n = b->prev;

    if (n->size > 0) {
        HeapUnlinkFreeBlock(n);
        n->size += size;
        n->next = b->next;
        b->next->prev = n;
        b->prev = 0;
        b->next = 0;
        b = n;
    }

    n = b->next;

    if (n->size > 0) {
        HeapUnlinkFreeBlock(n);
        b->size += n->size;
        b->next = n->next;
        n->next->prev = b;
        n->prev = 0;
        n->next = 0;
    }

    head = heap->start;
    b->prevFree = head;
    b->nextFree = head->nextFree;
    head->nextFree->prevFree = b;
    head->nextFree = b;
    b->self = 0;
}

void EwramFree(void* p) {
    HeapFree(p, &gEwramHeap);
}

void IwramFree(void* p) {
    HeapFree(p, &gIwramHeap);
}

s32 HeapGetBlockSize(void* p, Heap* heap) {
    s32 size;

    if (HeapContains(p, heap)) {
        size = -((HeapBlock*)p - 1)->size;

        if (size > 0) {
            return size;
        }
    }

    return 0;
}

INCLUDE_ASM("main/func_08000A08.s");
INCLUDE_ASM("main/func_08000A18.s");
INCLUDE_ASM("main/HeapGetFreeTotal.s");
INCLUDE_ASM("main/func_08000A40.s");
INCLUDE_ASM("main/func_08000A50.s");
INCLUDE_ASM("main/func_08000A60.s");
INCLUDE_ASM("main/func_08000A70.s");
INCLUDE_ASM("main/func_08000A80.s");
INCLUDE_ASM("main/func_08000A90.s");
INCLUDE_ASM("main/func_08000A9C.s");
INCLUDE_ASM("main/func_08000AA8.s");
INCLUDE_ASM("main/func_08000AB8.s");
INCLUDE_ASM("main/func_08000AC8.s");
INCLUDE_ASM("main/SetEwramHeapName.s");
INCLUDE_ASM("main/SetIwramHeapName.s");
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
INCLUDE_ASM("main/TaskDestroy.s");
INCLUDE_ASM("main/func_08000DE8.s");

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

INCLUDE_ASM("main/TaskPoolInit.s");

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
INCLUDE_ASM("main/func_08001100.s");
INCLUDE_ASM("main/func_08001248.s");
INCLUDE_ASM("main/func_08001254.s");
INCLUDE_ASM("main/func_080012A8.s");

u16 GetKeysHeld(void) {
    return gKeysHeld;
}

u16 GetKeysPressed(void) {
    return gKeysPressed;
}

INCLUDE_ASM("main/GetKeysRepeat.s");
INCLUDE_ASM("main/func_08001470.s");
INCLUDE_ASM("main/func_08001534.s");
INCLUDE_ASM("main/func_080015F8.s");
INCLUDE_ASM("main/UpdateKeyState.s");
INCLUDE_ASM("main/SpriteInit.s");
INCLUDE_ASM("main/SpriteFree.s");
INCLUDE_ASM("main/func_08001DB0.s");
INCLUDE_ASM("main/func_08001E64.s");
INCLUDE_ASM("main/func_08001EF8.s");
INCLUDE_ASM("main/func_08001F20.s");
INCLUDE_ASM("main/func_08001F5C.s");
INCLUDE_ASM("main/func_08001F98.s");
INCLUDE_ASM("main/func_08002060.s");
