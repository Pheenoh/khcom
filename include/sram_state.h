#ifndef GUARD_SRAM_STATE_H
#define GUARD_SRAM_STATE_H

#include "types.h"

extern void (*ReadSramFast)(const u8* src, u8* dest, u32 size);
extern u32 (*VerifySramFast)(const u8* src, u8* dest, u32 size);

#endif
