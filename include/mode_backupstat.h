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

extern BackupStatEntry gUnk_099937E4[];
extern const char gUnk_09993874[];
extern const char gUnk_09993878[];
extern const char gUnk_09993880[];
extern const char gUnk_09993888[];
extern const char* gUnk_09EF9668[];
extern u8 gWhitePalette[];

void mode_backupstat_0(void);
void mode_backupstat_1(void);
void mode_backupstat_2(void);
void func_081097F4(void);

#endif /* GUARD_MODE_BACKUPSTAT_H */
