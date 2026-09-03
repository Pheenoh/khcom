#include "mode.h"

extern const char gUnk_08128580[];

void mode_debug_0(s32 arg);
void mode_debug_1(void);
void mode_debug_2(void);

Mode gModeDebug = { gUnk_08128580, mode_debug_0, mode_debug_1, mode_debug_2 };
