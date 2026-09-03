#ifndef GUARD_SND_STREAM_H
#define GUARD_SND_STREAM_H

#include "types.h"

typedef struct {
    void* buffers[2];
    u32 writePos[2];
    u32 unk_10[2];
    u32 unk_18[2];
    u32 unk_20[2];
    u32 dmaOffset;
    u32 unk_2C;
    u32 samplesPerFrame;
    u32 bufferSize;
    u32 sampleRate;
    u32 timerReload;
    u32 channels;
    u32 playing;
    void (*unk_48)(void);
    void* (*alloc)(u32);
    void (*unk_50)(void);
    void (*free)(void*);
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
