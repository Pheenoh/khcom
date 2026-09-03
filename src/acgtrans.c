#include "macros.h"
#include "acgtrans.h"

void task_acgtrans_0(AcgTransWork* work, AcgTransConfig* cfg) {
    work->dst = cfg->dst;
    work->src = cfg->src;
    work->size = cfg->size;
    work->unk_00A = work->size / cfg->unk_00A;
    if (work->unk_00A == 0) {
        work->unk_00A = 1;
    }
    work->unk_00C = 0;
    work->bg = cfg->bg;
    DisableBg(cfg->bg);
}

s32 task_acgtrans_1(AcgTransWork* work) {
    s16 rest = work->size - (work->unk_00C + work->unk_00A);

    if (rest > 0) {
        RequestDma3Copy(work->src, work->dst, work->unk_00A);
        work->src += work->unk_00A;
        work->dst += work->unk_00A;
        work->unk_00C += work->unk_00A;
        DisableBg(work->bg);
        return 1;
    }

    work->unk_00A += rest;
    RequestDma3Copy(work->src, work->dst, work->unk_00A);
    DisableBg(work->bg);
    return 0;
}

void func_0801D1C4(void* a, s32 bg, u16 tile, u16 count, u16 frames, u32 src) {
    AcgTransConfig cfg;

    cfg.src = src;
    cfg.dst = GetBgCharBase(bg) + (tile << 5);
    cfg.size = count << 5;
    cfg.unk_00A = frames;
    cfg.bg = bg;

    if (cfg.unk_00A == 0) {
        cfg.unk_00A = 1;
    }
    TaskCreate(a, gTaskDescAcgtrans, &cfg);
}
