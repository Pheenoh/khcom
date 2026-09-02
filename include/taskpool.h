#ifndef GUARD_TASKPOOL_H
#define GUARD_TASKPOOL_H

#include "types.h"

typedef struct ListNode {
    void* unk_00;
    u8 unk_04[0x04];
    struct ListNode* unk_08;
    u16 unk_0C;
} ListNode;

typedef struct TaskPool {
    ListNode head;
    void* unk_10;
} TaskPool;

typedef struct TaskDesc {
    const char* name;
    void (*unk_04)(void* work, void* arg);
    void* unk_08;
    void (*unk_0C)(void* work);
    void (*unk_10)(void* work);
    s32 unk_14;
} TaskDesc;


#endif
