#include "mode.h"

extern const char gModeNameDebug[];

void mode_debug_0(s32 arg);
void mode_debug_1(void);
void mode_debug_2(void);

Mode gModeDebug = { gModeNameDebug, mode_debug_0, mode_debug_1, mode_debug_2 };
