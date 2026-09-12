#ifndef GUARD_MOVIE_H
#define GUARD_MOVIE_H

#include "snd_stream.h"
#include "types.h"

typedef void* (*MovieAllocFunc)(u32);
typedef void (*MovieFreeFunc)(void*);

typedef struct MovieHeap {
    MovieAllocFunc iwramAlloc;
    MovieAllocFunc ewramAlloc;
    MovieFreeFunc iwramFree;
    MovieFreeFunc ewramFree;
    u8* ticks;
} MovieHeap;

typedef struct MoviePlayer {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* data;
    u8* videoData;
    u8* videoPos;
    u8* audioData;
    u8* audioPos;
    void* frameBuf;
    void* workBuf;
    void* audioBuf;
    u32 width;
    u32 height;
    float frameRate;
    u32 frameCount;
    u32 audioBlockCount;
    u32 channels;
    u32 sampleRate;
    u32 audioCodecId;
    u8* frameTypes;
    u16* frameSizes;
    u8* unk_54;
    u16* audioBlockSizes;
    void* decodeBuf;
    u32 frameIndex;
    u32 audioBlockIndex;
    u8* startTicks;
    u32 timingStarted;
    float secondsPerFrame;
    u32 frameDecoded;
    u32 framePresent;
    void (*unk_7C)(void*, u32, u32, void*);
    void (*unk_80)(void*, u32, u32);
    void (*unk_84)(void*, void*, void*);
    void (*unk_88)(void*, void*, s32);
    u8 videoDone;
    u8 unk_8D;
} MoviePlayer;

extern MoviePlayer* gMoviePlayer;
extern u8 gUnk_0203C7C8[8];
extern MovieHeap gMovieHeap;

void MovieSetHeapCallbacks(MovieAllocFunc a, MovieAllocFunc b, MovieFreeFunc c, MovieFreeFunc d);
void MovieAdvanceTicks(void);
u8* MovieGetTicks(void);
float MovieTicksToSeconds(s32 a);
void MovieSetupVideoCodec(MoviePlayer* p, void* a, void* b, void* c, s32 w, s32 h);
void MovieSetupAudioCodec(MoviePlayer* p, void* a, s32 b);
MoviePlayer* MovieOpen(void* a);
void MovieFree(MoviePlayer* a);
void MovieDecodeFrame(MoviePlayer* a);
s32 MovieDrawFrame(MoviePlayer* a, void* dst);
s32 MovieAdvanceFrame(MoviePlayer* a);
u32 MovieGetAudioBlockSamples(MoviePlayer* a);
void MovieDecodeAudioBlock(MoviePlayer* a, void* dstA1, s32 lenA1, void* dstA2, s32 lenA2, void* dstB1, s32 lenB1, void* dstB2, s32 lenB2);
s32 MovieAdvanceAudioBlock(MoviePlayer* a);
s32 MovieSyncFrame(MoviePlayer* a);
u32 MovieGetChannels(MoviePlayer* a);
u32 MovieGetSampleRate(MoviePlayer* a);
void MovieGetSize(MoviePlayer* a, s32* w, s32* h);

void MovieSetCallbacks(MovieAllocFunc a, MovieAllocFunc b, MovieFreeFunc c, MovieFreeFunc d);
s32 MovieStart(void* a);
void MoviePlay(s32 (*a)(s32), s32 b);
void MovieClose(void);
void MovieUpdate(void);

#endif
