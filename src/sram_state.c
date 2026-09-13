#include "sram_state.h"

void (*ReadSramFast)(const u8* src, u8* dest, u32 size);
u32 (*VerifySramFast)(const u8* src, u8* dest, u32 size);
