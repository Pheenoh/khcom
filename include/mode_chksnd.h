#ifndef GUARD_MODE_CHKSND_H
#define GUARD_MODE_CHKSND_H

#include "types.h"
#include "taskpool.h"
#include "main.h"
#include "mode.h"
#include "engine.h"
#include "key.h"
#include "m4a.h"
typedef struct ChkSndEntry {
    const char* name;
    u16 songNum;
} ChkSndEntry;
extern ChkSndEntry gChkSndEntries[];
extern TaskDesc gTaskDescPrint;

void func_0809D2B0(u8 x, u8 y, u8 c, const char* s);
void func_0809D458(u16 x, u16 y, u16 c, s32 v);

void mode_chksnd_0(void);
void mode_chksnd_1(void);
void mode_chksnd_2(void);

#endif /* GUARD_MODE_CHKSND_H */
