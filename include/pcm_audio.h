#ifndef GUARD_PCM_AUDIO_H
#define GUARD_PCM_AUDIO_H

#include "types.h"

typedef struct SoundEntry {
    u32 sampleRate;
    u32 samplesPerBuffer;
    u32 timerReload;
} SoundEntry;

u8 LookupPcmPlaybackConfig(u32 sampleRate, u16* timerReload, u32* samplesPerBuffer);
u8 PcmPlaybackInit(u32 sampleRate);
void PcmPlaybackStart(void);
void PcmPlaybackStop(void);
void PcmPlaybackUpdate(void);

#endif
