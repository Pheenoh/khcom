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
void func_08000D20(void* node, void* pool, void* owner);
void func_08000D28(void* node, void* pool);
void func_08000D48(void* node, void* pool, void* after);
void func_08000D6C(void* node, void* pool, void* before);
void* func_08000D90(void* node, void* pool);

#endif
