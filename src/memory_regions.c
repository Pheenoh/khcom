#include "memory_regions.h"

u8 gEwramHeapStart[EWRAM_HEAP_SIZE] __attribute__((common));
char SoundMainRAM_Buffer[0x400] __attribute__((aligned(4)));
u8 gIwramHeapStart[IWRAM_HEAP_SIZE] __attribute__((aligned(4)));
