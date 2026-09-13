#ifndef GUARD_MEMORY_REGIONS_H
#define GUARD_MEMORY_REGIONS_H

#include "types.h"

#define EWRAM_HEAP_SIZE 0x34000
#define IWRAM_HEAP_SIZE 0x6800

extern u8 gEwramHeapStart[EWRAM_HEAP_SIZE];
extern char SoundMainRAM_Buffer[0x400];
extern u8 gIwramHeapStart[IWRAM_HEAP_SIZE];

#endif
