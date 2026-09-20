#ifndef GUARD_MODE_BACKUPSTAT_H
#define GUARD_MODE_BACKUPSTAT_H

#include "mode_test_api.h"

#include "save_api.h"

#include "display.h"
#include "types.h"
#include "taskpool.h"
#include "evt_types.h"
#include "main.h"
#include "mode.h"
#include "key.h"



typedef struct BackupStatEntry {
    const char* name;
    s32 unk_04;
} BackupStatEntry;


void mode_backupstat_0(void);
void mode_backupstat_1(void);
void mode_backupstat_2(void);
void func_081097F4(void);

#endif /* GUARD_MODE_BACKUPSTAT_H */
