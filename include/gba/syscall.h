#ifndef GUARD_GBA_SYSCALL_H
#define GUARD_GBA_SYSCALL_H

#include "types.h"

#define CPU_SET_SRC_FIXED 0x01000000
#define CPU_SET_32BIT     0x04000000

typedef struct BgAffineSrcData {
    s32 texX;
    s32 texY;
    s16 scrX;
    s16 scrY;
    s16 sx;
    s16 sy;
    u16 alpha;
} BgAffineSrcData;

typedef struct BgAffineDstData {
    s16 pa;
    s16 pb;
    s16 pc;
    s16 pd;
    s32 dx;
    s32 dy;
} BgAffineDstData;

void BgAffineSet(BgAffineSrcData* src, BgAffineDstData* dst, s32 count);
void SoftReset(s32 flags);
void CpuSet(void* src, void* dst, u32 ctrl);
void CpuFastSet(void* src, void* dst, s32 ctrl);
void RegisterRamReset(u32 flags);
void VBlankIntrWait(void);
u32 Sqrt(u32 value);

#endif
