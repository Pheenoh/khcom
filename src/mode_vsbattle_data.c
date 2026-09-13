#include "mode_vsbattle.h"
#include "mode.h"

const char gModeNameVsbattle[] = "mode_vsbattle";

Mode gModeVsbattle = { gModeNameVsbattle, (void (*)(s32))mode_vsbattle_0, mode_vsbattle_1, mode_vsbattle_2 };
