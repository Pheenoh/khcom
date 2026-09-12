#ifndef GUARD_LISTPOOL_H
#define GUARD_LISTPOOL_H

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
