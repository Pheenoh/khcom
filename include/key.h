#ifndef GUARD_KEY_H
#define GUARD_KEY_H

#include "types.h"

u16 GetKeysHeld(void);
u16 GetKeysPressed(void);
u16 GetKeysRepeat(void);
u8 GetKeyReleaseTime(u16 key);
void UpdateKeyState(void);
void ResetKeyState(void);

extern u16 gKeysHeld;

extern u16 gKeysPressed;

u16 ReadKeyChord(u16 a, u16 b);
u16 ReadDpadChord(void);

#endif
