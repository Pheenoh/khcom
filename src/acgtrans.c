#include "macros.h"
#include "acgtrans.h"

void task_acgtrans_0(AcgTransWork* work, AcgTransConfig* cfg) {
    work->unk_000 = cfg->unk_004;
    work->unk_004 = cfg->unk_000;
    work->unk_008 = cfg->unk_008;
    work->unk_00A = work->unk_008 / cfg->unk_00A;
    if (work->unk_00A == 0) {
        work->unk_00A = 1;
    }
    work->unk_00C = 0;
    work->unk_010 = cfg->unk_00C;
    func_0800501C(cfg->unk_00C);
}

s32 task_acgtrans_1(AcgTransWork* work) {
    s16 rest = work->unk_008 - (work->unk_00C + work->unk_00A);

    if (rest > 0) {
        func_080043B4(work->unk_004, work->unk_000, work->unk_00A);
        work->unk_004 += work->unk_00A;
        work->unk_000 += work->unk_00A;
        work->unk_00C += work->unk_00A;
        func_0800501C(work->unk_010);
        return 1;
    }

    work->unk_00A += rest;
    func_080043B4(work->unk_004, work->unk_000, work->unk_00A);
    func_0800501C(work->unk_010);
    return 0;
}

void func_0801D1C4(void* a, s32 bg, u16 tile, u16 count, u16 frames, u32 src) {
    AcgTransConfig cfg;

    cfg.unk_000 = src;
    cfg.unk_004 = func_08005130(bg) + (tile << 5);
    cfg.unk_008 = count << 5;
    cfg.unk_00A = frames;
    cfg.unk_00C = bg;
    if (cfg.unk_00A == 0) {
        cfg.unk_00A = 1;
    }
    func_08000E14(a, gUnk_09EDADF8, &cfg);
}
