#ifndef GUARD_PCM_AUDIO_H
#define GUARD_PCM_AUDIO_H

#include "types.h"

typedef struct SoundEntry {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} SoundEntry;

u8 LookupPcmPlaybackConfig(u32 id, u16* rate, u32* count);
u8 PcmPlaybackInit(u32 id);
void PcmPlaybackStart(void);
void PcmPlaybackStop(void);
void PcmPlaybackUpdate(void);

#endif
