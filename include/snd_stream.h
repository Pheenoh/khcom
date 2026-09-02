#ifndef GUARD_SND_STREAM_H
#define GUARD_SND_STREAM_H

#include "types.h"

typedef struct {
    void* unk_00[2];
    u32 unk_08[2];
    u32 unk_10[2];
    u32 unk_18[2];
    u32 unk_20[2];
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3C;
    u32 unk_40;
    u32 unk_44;
    void (*unk_48)(void);
    void* (*unk_4C)(u32);
    void (*unk_50)(void);
    void (*unk_54)(void*);
} SoundStream;

extern SoundStream gSndStream;

void SndStreamInit(u32 rate, u32 channels);
void SndStreamUpdate(void);
void SndStreamLock(u32 ch, u32 len, void** dst1, u32* len1, void** dst2, u32* len2);
void SndStreamSetCallbacks(void (*a)(void), void* (*b)(u32), void (*c)(void), void (*d)(void*));
void SndStreamClose(void);
void SndStreamStart(void);
void SndStreamStop(void);
void SndStreamUnlock(u32 ch);

#endif /* GUARD_SND_STREAM_H */
