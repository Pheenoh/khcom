#include "task_descriptors.h"
#include "acgtrans.h"

const char gTaskNameAcgtrans[] = "task_acgtrans";

void task_acgtrans_0(AcgTransWork* work, AcgTransConfig* cfg) {
    work->dst = cfg->dst;
    work->src = cfg->src;
    work->size = cfg->size;
    work->chunkSize = work->size / cfg->frames;
    if (work->chunkSize == 0) {
        work->chunkSize = 1;
    }
    work->transferredBytes = 0;
    work->bg = cfg->bg;
    DisableBg(cfg->bg);
}

s32 task_acgtrans_1(AcgTransWork* work) {
    s16 rest = work->size - (work->transferredBytes + work->chunkSize);

    if (rest > 0) {
        RequestDma3Copy(work->src, work->dst, work->chunkSize);
        work->src += work->chunkSize;
        work->dst += work->chunkSize;
        work->transferredBytes += work->chunkSize;
        DisableBg(work->bg);
        return 1;
    }

    work->chunkSize += rest;
    RequestDma3Copy(work->src, work->dst, work->chunkSize);
    DisableBg(work->bg);
    return 0;
}

void CreateBgTileTransferTask(void* a, s32 bg, u16 tile, u16 count, u16 frames, u32 src) {
    AcgTransConfig cfg;

    cfg.src = src;
    cfg.dst = GetBgCharBase(bg) + (tile << 5);
    cfg.size = count << 5;
    cfg.frames = frames;
    cfg.bg = bg;

    if (cfg.frames == 0) {
        cfg.frames = 1;
    }
    TaskCreate(a, &gTaskDescAcgtrans, &cfg);
}

TaskDesc gTaskDescAcgtrans = { gTaskNameAcgtrans, task_acgtrans_0, task_acgtrans_1, 0, 0, 0x14 };
