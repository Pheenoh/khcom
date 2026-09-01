#ifndef GUARD_KEY_H
#define GUARD_KEY_H

#include "types.h"

u16 GetKeysHeld(void);
u16 GetKeysPressed(void);
void UpdateKeyState(void);

extern u16 gKeysHeld;

extern u16 gKeysPressed;

#endif
