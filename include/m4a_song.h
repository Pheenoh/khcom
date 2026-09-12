#ifndef GUARD_M4A_SONG_H
#define GUARD_M4A_SONG_H

#include "types.h"

void m4aSongNumStart(u16 song);
void m4aSongNumStartOrChange(u16 song);
void m4aSongNumStartOrContinue(u16 song);
void m4aSongNumStop(u16 song);
void m4aSongNumContinue(u16 song);

struct MusicPlayerInfo;

void m4aMPlayVolumeControl(struct MusicPlayerInfo* mplayInfo, u16 trackBits, u16 volume);
void m4aMPlayAllStop(void);

#endif
