#ifndef GUARD_SAVE_API_H
#define GUARD_SAVE_API_H

#include "types.h"

void SaveClearSystem(void);
int SaveLoadSystem(void);
void SaveWriteHeader(s16 slot);
int SaveLoadHeader(void);
int SaveRepairHeader(void);
int SaveRepairFileLarge(u16 file);
int SaveRepairFileSmall(u16 file);
int SaveLoadFileLarge(u16 file);
int SaveLoadFileSmall(u16 file);
int SaveCheckHeaderSlot(s16 slot);
int SaveCheckSystemSlot(s16 slot);
int SaveCheckFileLargeSlot(s16 file, s16 slot);
int SaveCheckFileSmallSlot(s16 file, s16 slot);
void SaveSetHeaderState(s16 slot, s16 state);
void SaveSetSystemState(s16 slot, s16 state);
void SaveSetFileLargeState(s16 file, s16 slot, s16 state);
void SaveSetFileSmallState(s16 file, s16 slot, s16 state);
void SaveClearHeader(void);
void SaveClearFileLarge(u16 file);
void SaveClearFileSmall(u16 file);
void SaveWriteFileLarge(u16 file);
int SaveRepairSystem(void);

#endif
