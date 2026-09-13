#ifndef GUARD_BACKUPSTAT_DATA_H
#define GUARD_BACKUPSTAT_DATA_H

#include "types.h"

typedef struct BackupStatEntry {
    const char* name;
    s32 unk_04;
} BackupStatEntry;

extern BackupStatEntry gUnk_099937E4[];
extern const char* gUnk_09EF9668[];

#endif
