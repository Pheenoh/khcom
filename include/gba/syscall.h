#ifndef GUARD_GBA_SYSCALL_H
#define GUARD_GBA_SYSCALL_H

#include "types.h"

void SoftReset(s32 flags);
void CpuSet(void* src, void* dst, u32 ctrl);
void CpuFastSet(void* src, void* dst, s32 ctrl);
void VBlankIntrWait(void);

#endif
