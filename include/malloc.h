#ifndef GUARD_MALLOC_H
#define GUARD_MALLOC_H

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

void HeapInit(void* addr, u32 size, Heap* heap);
void* HeapAlloc(u32 size, Heap* heap);
void HeapFree(void* p, Heap* heap);
s32 HeapGetBlockSize(void* p, Heap* heap);
void HeapUnlinkFreeBlock(HeapBlock* b);
u8 HeapContains(void* p, Heap* heap);
HeapBlock* HeapFindFreeBlock(s32 size, Heap* heap);
void EwramHeapInit(void* addr, u32 size);
void IwramHeapInit(void* addr, u32 size);
void* EwramAlloc(u32 size);
void* IwramAlloc(u32 size);
void EwramFree(void* p);
void IwramFree(void* p);
void SetEwramHeapName(void* name);
void SetIwramHeapName(void* name);

#endif
