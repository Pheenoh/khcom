#ifndef GUARD_ACGTRANS_H
#define GUARD_ACGTRANS_H

#include "acgtrans_tasks.h"

#include "display.h"
#include "types.h"
#include "taskpool.h"
#include "game.h"

typedef struct AcgTransWork {
    u32 dst;
    u32 src;
    u16 size;
    u16 unk_00A;
    u16 unk_00C;
    u32 bg;
} AcgTransWork;

typedef struct AcgTransConfig {
    u32 src;
    u32 dst;
    u16 size;
    u16 unk_00A;
    u32 bg;
} AcgTransConfig;

extern u8 gTaskDescAcgtrans[];

void func_0801D1C4(void* a, s32 bg, u16 tile, u16 count, u16 frames, u32 src);

#endif /* GUARD_ACGTRANS_H */
