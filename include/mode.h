#ifndef GUARD_MODE_H
#define GUARD_MODE_H

#include "types.h"

typedef struct Mode {
    const char* name;
    void (*init)(s32 arg);
    void (*update)(void);
    void (*exit)(void);
} Mode;

void ModeRequest(Mode* mode, s32 arg);
void ModeRequestHeapReset(Mode* mode, s32 arg);
void func_0805FA60(s32 a, void* b, s32 c, u8 d);
void func_08060598(void);
void func_080609A0(void);

extern Mode gModeDebug;

#endif
