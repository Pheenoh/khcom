#include "macros.h"
#include "intr.h"
#include "gba/syscall.h"
#include "key.h"
#include "malloc.h"

typedef struct Node {
    void* unk_00;
    struct Node* prev;
    struct Node* next;
    u16 unk_0C;
    struct Node* unk_10;
} Node;

typedef struct NodeList {
    Node* unk_00;
    Node* unk_04;
    Node* unk_08;
    Node* unk_0C;
} NodeList;

extern u8 sEwramHeapName[];
extern u8 sIwramHeapName[];

extern u32 gFrameCounter;
extern u32 gVBlankCounter;
extern u16 gSystemFlags;
extern u32 gUnk_03006C10;
extern u32 gSioPlayerId;
extern u32 gSioStatus;
extern u16 gFrameSyncFlags;

void func_080C55DC(void);
void ModeUpdate(void);
void* func_08000CD4(Node* node);
void* func_08000CF0(Node* node);


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
INCLUDE_ASM("malloc/HeapInit.s");
#endif

void EwramHeapInit(void* addr, u32 size) {
    SetEwramHeapName(sEwramHeapName);
    HeapInit(addr, size, &gEwramHeap);
}

void IwramHeapInit(void* addr, u32 size) {
    SetIwramHeapName(sIwramHeapName);
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

s32 EwramGetBlockSize(void* p) {
    return HeapGetBlockSize(p, &gEwramHeap);
}

s32 IwramGetBlockSize(void* p) {
    return HeapGetBlockSize(p, &gIwramHeap);
}

s32 HeapGetFreeTotal(Heap* heap) {
    HeapBlock* b;
    s32 total;

    b = heap->start->nextFree;
    total = 0;

    while (b != 0 && b->size > 0) {
        total += b->size;
        b = b->nextFree;
    }
    return total;
}

s32 EwramGetFreeTotal(void) {
    return HeapGetFreeTotal(&gEwramHeap);
}

s32 IwramGetFreeTotal(void) {
    return HeapGetFreeTotal(&gIwramHeap);
}

void func_08000A60(Heap* heap) {
    HeapBlock* b;

    for (b = heap->start; b != 0; b = b->next) {
        *(volatile s32*)&b->size;
    }
}

void func_08000A70(void) {
    func_08000A60(&gEwramHeap);
}

void func_08000A80(void) {
    func_08000A60(&gIwramHeap);
}

void func_08000A90(u8 v) {
    gEwramHeap.unk_08 = v;
}

void func_08000A9C(u8 v) {
    gIwramHeap.unk_08 = v;
}

void func_08000AA8(Heap* heap) {
    HeapBlock* b;

    for (b = heap->start; b != 0; b = b->next) {
        *(volatile s32*)&b->size;
    }
}

void func_08000AB8(void) {
    func_08000AA8(&gEwramHeap);
}

void func_08000AC8(void) {
    func_08000AA8(&gIwramHeap);
}

void SetEwramHeapName(void* name) {
    gEwramHeap.name = name;
}

void SetIwramHeapName(void* name) {
    gIwramHeap.name = name;
}

void* GetEwramHeapName(void) {
    return gEwramHeap.name;
}

void* GetIwramHeapName(void) {
    return gIwramHeap.name;
}

void ListAppend(Node* node, Node** head, Node** tail) {
    if (*head == 0) {
        *head = node;
    }

    node->prev = *tail;

    if (*tail != 0) {
        (*tail)->next = node;
    }

    node->next = 0;
    *tail = node;
}

void ListInsertAfter(Node* node, Node** head, Node** tail, Node* after) {
    Node* next;

    if (after != 0) {
        node->prev = after;
        next = after->next;
        node->next = next;
        after->next = node;

        if (next != 0) {
            next->prev = node;
        } else {
            *tail = node;
        }
    } else {
        ListAppend(node, head, tail);
    }
}

void ListInsertBefore(Node* node, Node** head, Node** tail, Node* before) {
    Node* prev;

    if (before != 0) {
        node->next = before;
        prev = before->prev;
        node->prev = prev;
        before->prev = node;

        if (prev != 0) {
            prev->next = node;
        } else {
            *head = node;
        }
    } else {
        ListAppend(node, head, tail);
    }
}

void ListRemove(Node* node, Node** head, Node** tail) {
    if (node->prev == 0) {
        if (node->next == 0) {
            *head = 0;
            *tail = 0;
        } else {
            node->next->prev = node->prev;
            *head = node->next;
        }
    } else {
        if (node->next == 0) {
            *tail = node->prev;
            node->prev->next = node->next;
        } else {
            node->next->prev = node->prev;
            node->prev->next = node->next;
        }
    }
}

void func_08000BA4(NodeList* list) {
    list->unk_00 = 0;
    list->unk_04 = 0;
    list->unk_08 = 0;
    list->unk_0C = 0;
}

void func_08000BB0(Node* node, NodeList* list, void* owner) {
    ListAppend(node, &list->unk_00, &list->unk_04);
    node->unk_00 = owner;
    node->unk_0C = 0;
}

void func_08000BC8(void* a, void* b) {
    Node* node;
    NodeList* list;

    node = a;
    list = b;
    ListRemove(node, &list->unk_00, &list->unk_04);
    ListAppend(node, &list->unk_08, &list->unk_0C);
    node->unk_0C |= 1;
    node->unk_10 = node;
}

void func_08000BF4(Node* node, NodeList* list, Node* after) {
    ListRemove(node, &list->unk_00, &list->unk_04);
    ListInsertAfter(node, &list->unk_08, &list->unk_0C, after);
    node->unk_0C |= 1;
    node->unk_10 = node;
}

void func_08000C24(Node* node, NodeList* list, Node* before) {
    ListRemove(node, &list->unk_00, &list->unk_04);
    ListInsertBefore(node, &list->unk_08, &list->unk_0C, before);
    node->unk_0C |= 1;
    node->unk_10 = node;
}

void* func_08000C54(Node* node, NodeList* list) {
    Node* next;

    next = node->next;
    ListRemove(node, &list->unk_08, &list->unk_0C);
    ListAppend(node, &list->unk_00, &list->unk_04);
    node->unk_0C &= 0xFFFE;

    if (next != 0) {
        return next->unk_00;
    }

    return 0;
}

void* func_08000C8C(NodeList* list) {
    Node* n;
    void* result;

    n = list->unk_08;

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

void* func_08000CB0(NodeList* list) {
    Node* n;
    void* result;

    n = list->unk_0C;

    if (n != 0) {
        if (n->unk_0C & 2) {
            return func_08000CF0(n);
        }

        result = n->unk_00;
    } else {
        result = 0;
    }

    return result;
}

void* func_08000CD4(Node* node) {
    Node* n;
    void* result;

    n = node->next;

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

void* func_08000CF0(Node* node) {
    Node* n;
    void* result;

    n = node->prev;

    if (n != 0) {
        if (n->unk_0C & 2) {
            return func_08000CF0(n);
        }

        result = n->unk_00;
    } else {
        result = 0;
    }

    return result;
}

void* func_08000D0C(NodeList* list) {
    Node* n;

    n = list->unk_00;

    if (n != 0) {
        return n->unk_00;
    }

    return 0;
}

void func_08000D1C(void) {
}

void func_08000D20(Node* node, NodeList* list, void* owner) {
    node->unk_00 = owner;
    node->unk_0C = 0;
}

void func_08000D28(Node* node, NodeList* list) {
    ListAppend(node, &list->unk_08, &list->unk_0C);
    node->unk_0C |= 1;
    node->unk_10 = node;
}

void func_08000D48(Node* node, NodeList* list, Node* after) {
    ListInsertAfter(node, &list->unk_08, &list->unk_0C, after);
    node->unk_0C |= 1;
    node->unk_10 = node;
}

void func_08000D6C(Node* node, NodeList* list, Node* before) {
    ListInsertBefore(node, &list->unk_08, &list->unk_0C, before);
    node->unk_0C |= 1;
    node->unk_10 = node;
}

void* func_08000D90(Node* node, NodeList* list) {
    Node* next;

    next = node->next;
    ListRemove(node, &list->unk_08, &list->unk_0C);
    node->unk_0C &= 0xFFFE;

    if (next != 0) {
        return next->unk_00;
    }

    return 0;
}
