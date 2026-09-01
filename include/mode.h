#ifndef GUARD_MODE_H
#define GUARD_MODE_H

#include "types.h"

typedef struct Mode {
    const char* name;
    void (*unk_04)(s32 arg);
    void (*unk_08)(void);
    void (*unk_0C)(void);
} Mode;

#endif
