#ifndef GUARD_M4A_SONG_H
#define GUARD_M4A_SONG_H

#include "types.h"

void m4aSongNumStart(u16 song);
void m4aSongNumStartOrChange(u16 song);
void m4aSongNumStartOrContinue(u16 song);
void m4aSongNumStop(u16 song);
void m4aSongNumContinue(u16 song);

#endif
