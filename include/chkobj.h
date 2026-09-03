#ifndef GUARD_CHKOBJ_H
#define GUARD_CHKOBJ_H

#include "types.h"
#include "anim.h"
#include "taskpool.h"

typedef struct ObjDef {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u16 animCount;
    u16 unk_0E;
    void* palette;
    const char* aobName;
    const char* aclName;
    u16 paletteSize;
    u16 unk_1E;
} ObjDef;

typedef struct ChkObjWork {
    TaskPool pool;
    s16 unk_14;
    s16 animId;
    s16 unk_18;
    u8 unk_1A[0x02];
    void* tiles;
    void* palette;
    AnimState anim;
    void* gfx;
    u8 paused;
    u8 unk_41;
    u16 unk_42;
    s16 unk_44;
    s16 unk_46;
} ChkObjWork;

#endif
