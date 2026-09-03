#ifndef GUARD_ACGTRANS_H
#define GUARD_ACGTRANS_H

#include "types.h"
#include "game.h"

typedef struct AcgTransWork {
    u32 unk_000;
    u32 unk_004;
    u16 unk_008;
    u16 unk_00A;
    u16 unk_00C;
    u32 unk_010;
} AcgTransWork;

typedef struct AcgTransConfig {
    u32 unk_000;
    u32 unk_004;
    u16 unk_008;
    u16 unk_00A;
    u32 unk_00C;
} AcgTransConfig;

extern u8 gTaskDescAcgtrans[];

void* TaskCreate(void* a, void* desc, void* args);
s32 RequestDma3Copy(u32 src, u32 dst, u32 size);
u32 GetBgCharBase(s32 bg);

void task_acgtrans_0(AcgTransWork* work, AcgTransConfig* cfg);
s32 task_acgtrans_1(AcgTransWork* work);
void func_0801D1C4(void* a, s32 bg, u16 tile, u16 count, u16 frames, u32 src);

#endif /* GUARD_ACGTRANS_H */
