#ifndef GUARD_MODE_H
#define GUARD_MODE_H

#include "types.h"

typedef void (*ModeInitFunc)(s32 arg);
typedef void (*ModeFunc)(void);

typedef struct Mode {
    const char* name;
    ModeInitFunc init;
    ModeFunc update;
    ModeFunc exit;
} Mode;

void ModeRequest(Mode* mode, s32 arg);
void ModeUpdate(void);
void ModeRequestHeapReset(Mode* mode, s32 arg);
void func_0805FA60(s32 a, void* b, s32 c, u8 d);
void func_08060598(void);
void func_080609A0(void);

extern Mode gModeDebug;
extern Mode gModeChkobj;
extern Mode gModeChkeff;
extern Mode gModeDummy;
extern Mode gModeDebflag;
extern Mode gModeVsbattle;

u8 IsModeStarted(void);
void func_08001080(void);
void SetModeUpdate(void (*fn)(void));
#ifdef VERSION_EU
void eu_0800115C(void);
#endif
void func_08001058(void (*a)(void), void (*b)(void));
void ModeFlushDisplay(void);
void ModeRunVBlankCallbacks(void);

#ifdef VERSION_EU
void ModeInit(u8 a);
#else
void ModeInit(void);
#endif

#endif
