#include "mode_debug_api.h"
#include "mode.h"

extern const char gModeNameDebug[];


Mode gModeDebug = { gModeNameDebug, mode_debug_0, mode_debug_1, mode_debug_2 };
