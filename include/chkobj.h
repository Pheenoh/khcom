#ifndef GUARD_CHKOBJ_H
#define GUARD_CHKOBJ_H

#include "types.h"
#include "anim.h"
#include "taskpool.h"

typedef struct ObjDef {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u16 unk_0C;
    u16 unk_0E;
    void* unk_10;
    const char* unk_14;
    const char* unk_18;
    u16 unk_1C;
    u16 unk_1E;
} ObjDef;

typedef struct ChkObjWork {
    TaskPool pool;
    s16 unk_14;
    s16 unk_16;
    s16 unk_18;
    u8 unk_1A[0x02];
    void* unk_1C;
    void* unk_20;
    AnimState unk_24;
    void* unk_3C;
    u8 unk_40;
    u8 unk_41;
    u16 unk_42;
    s16 unk_44;
    s16 unk_46;
} ChkObjWork;

#endif
