#ifndef GUARD_MODE_CHKSND_H
#define GUARD_MODE_CHKSND_H

#include "types.h"
#include "main.h"
#include "mode.h"
typedef struct ChkSndEntry {
    const char* name;
    u16 songNum;
} ChkSndEntry;
extern ChkSndEntry gChkSndEntries[];
extern Mode gModeDebug;
extern TaskDesc gTaskDescPrint;

void ModeRequest(Mode* mode, s32 b);
u16 GetKeysRepeat(void);
void SetBgMode0(void);
void func_0809D2B0(u8 x, u8 y, u8 c, const char* s);
void func_0809D458(u16 x, u16 y, u16 c, s32 v);
void m4aSongNumStart(u16 id);
void m4aMPlayAllStop(void);

void mode_chksnd_0(void);
void mode_chksnd_1(void);
void mode_chksnd_2(void);

#endif /* GUARD_MODE_CHKSND_H */
