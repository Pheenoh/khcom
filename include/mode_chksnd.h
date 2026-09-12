#ifndef GUARD_MODE_CHKSND_H
#define GUARD_MODE_CHKSND_H

#include "card_api.h"

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

void mode_chksnd_0(void);
void mode_chksnd_1(void);
void mode_chksnd_2(void);

#endif /* GUARD_MODE_CHKSND_H */
