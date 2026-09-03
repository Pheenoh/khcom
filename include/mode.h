#ifndef GUARD_MODE_H
#define GUARD_MODE_H

#include "types.h"

typedef struct Mode {
    const char* name;
    void (*init)(s32 arg);
    void (*update)(void);
    void (*exit)(void);
} Mode;

#endif
