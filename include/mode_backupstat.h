#ifndef GUARD_MODE_BACKUPSTAT_H
#define GUARD_MODE_BACKUPSTAT_H

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

void func_0805FA8C(u8 a, s16 b, s16 c);
void func_0805FCB0(u8 a, u8 b, u32 c, const char* d);
void func_080605A4(u8 a);
int SaveCheckHeaderSlot(s16 slot);
int SaveCheckSystemSlot(s16 slot);
int SaveCheckFileLargeSlot(s16 file, s16 slot);
int SaveCheckFileSmallSlot(s16 file, s16 slot);
void SaveSetHeaderState(s16 slot, s16 state);
void SaveSetSystemState(s16 slot, s16 state);
void SaveSetFileLargeState(s16 file, s16 slot, s16 state);
void SaveSetFileSmallState(s16 file, s16 slot, s16 state);

void mode_backupstat_0(void);
void mode_backupstat_1(void);
void mode_backupstat_2(void);
void func_081097F4(void);

#endif /* GUARD_MODE_BACKUPSTAT_H */
