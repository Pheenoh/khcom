#ifndef GUARD_LISTPOOL_H
#define GUARD_LISTPOOL_H

#include "types.h"

typedef struct ListNode {
    void* owner;
    struct ListNode* prev;
    struct ListNode* next;
    u16 flags;
    struct ListNode* self;
} ListNode;

typedef struct ListPool {
    ListNode* freeHead;
    ListNode* freeTail;
    ListNode* activeHead;
    ListNode* activeTail;
} ListPool;

typedef char ListNode_size[(sizeof(ListNode) == 0x14) ? 1 : -1];
typedef char ListPool_size[(sizeof(ListPool) == 0x10) ? 1 : -1];

void ListPoolInit(void* pool);
void ListPoolAddFree(void* node, void* pool, void* owner);
void ListPoolActivate(void* node, void* pool);
void ListPoolActivateAfter(void* node, void* pool, void* after);
void ListPoolActivateBefore(void* node, void* pool, void* before);
void* ListPoolRelease(void* node, void* pool);
void* ListPoolFirst(void* pool);
void* ListPoolLast(void* pool);
void* ListPoolNext(void* node);
void* ListPoolPrev(void* node);
void* ListPoolFirstFree(void* pool);
void ListNodeInit(void* node, void* pool, void* owner);
void ListPoolAppend(void* node, void* pool);
void ListPoolInsertAfter(void* node, void* pool, void* after);
void ListPoolInsertBefore(void* node, void* pool, void* before);
void* ListPoolRemove(void* node, void* pool);

#endif
