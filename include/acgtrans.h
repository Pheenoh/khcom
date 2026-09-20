#ifndef GUARD_ACGTRANS_H
#define GUARD_ACGTRANS_H

#include "task_descriptors.h"
#include "acgtrans_tasks.h"

#include "display.h"
#include "types.h"
#include "taskpool.h"
#include "game.h"

typedef struct AcgTransWork {
    u32 dst;
    u32 src;
    u16 size;
    u16 chunkSize;
    u16 transferredBytes;
    u32 bg;
} AcgTransWork;

typedef struct AcgTransConfig {
    u32 src;
    u32 dst;
    u16 size;
    u16 frames;
    u32 bg;
} AcgTransConfig;


void CreateBgTileTransferTask(void* a, s32 bg, u16 tile, u16 count, u16 frames, u32 src);

#endif /* GUARD_ACGTRANS_H */
