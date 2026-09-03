#ifndef GUARD_TASKPOOL_H
#define GUARD_TASKPOOL_H

#include "types.h"

typedef struct ListNode {
    void* owner;
    u8 unk_04[0x04];
    struct ListNode* next;
    u16 flags;
} ListNode;

typedef struct TaskPool {
    ListNode head;
    void* tasks;
} TaskPool;

typedef struct TaskDesc {
    const char* name;
    void (*init)(void* work, void* arg);
    void* update;
    void (*draw)(void* work);
    void (*destroy)(void* work);
    s32 workSize;
} TaskDesc;


#endif
