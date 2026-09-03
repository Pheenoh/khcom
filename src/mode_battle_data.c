#include "mode.h"

extern const char gUnk_08126624[];

void mode_battle_0(s32 arg);
void mode_battle_1(void);
void mode_battle_2(void);

Mode gModeBattle = { gUnk_08126624, mode_battle_0, mode_battle_1, mode_battle_2 };
