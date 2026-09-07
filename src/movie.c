#include "macros.h"
#include "gba/syscall.h"
#include "types.h"

#define REG_VCNT (*(vu16*)0x04000006)
#define REG_IME (*(vu16*)0x04000208)

#define MOVIE_TICKS_PER_FRAME 228
#define MOVIE_SECONDS_PER_TICK 0.000073433f

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

MoviePlayer* gMoviePlayer;
u8 gUnk_0203C7C8[8];
MovieHeap gMovieHeap;


void SndStreamInit(u32 rate, u32 channels);
void SndStreamUpdate(void);
void SndStreamLock(u32 ch, u32 len, void** dst1, s32* len1, void** dst2, s32* len2);
void SndStreamSetCallbacks(MovieAllocFunc a, MovieAllocFunc b, MovieFreeFunc c, MovieFreeFunc d);
void SndStreamClose(void);
void SndStreamStart(void);
void SndStreamUnlock(u32 ch);

void MovieSetCallbacks(MovieAllocFunc a, MovieAllocFunc b, MovieFreeFunc c, MovieFreeFunc d);
s32 MovieStart(void* a);
void MoviePlay(s32 (*a)(s32), s32 b);
void MovieClose(void);
void MovieUpdate(void);
void MovieSetHeapCallbacks(MovieAllocFunc a, MovieAllocFunc b, MovieFreeFunc c, MovieFreeFunc d);
void MovieAdvanceTicks(void);
u8* MovieGetTicks(void);
float MovieTicksToSeconds(s32 a);
void MovieSetupVideoCodec(MoviePlayer* p, void* a, void* b, void* c, u32 w, u32 h);
void MovieSetupAudioCodec(MoviePlayer* p, void* a, u32 b);
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

void MovieSetCallbacks(MovieAllocFunc a, MovieAllocFunc b, MovieFreeFunc c, MovieFreeFunc d) {
    MovieSetHeapCallbacks(a, b, c, d);
    SndStreamSetCallbacks(a, b, c, d);
}

s32 MovieStart(void* a) {
    void* dstA1;
    void* dstA2;
    void* dstB1;
    void* dstB2;
    s32 lenA1;
    s32 lenA2;
    s32 lenB1;
    s32 lenB2;
    s32 i;
    u32 channels;

    gMoviePlayer = MovieOpen(a);
    if (gMoviePlayer == 0) {
        return 0;
    }
    channels = MovieGetChannels(gMoviePlayer);
    if (channels != 0) {
        SndStreamInit(MovieGetSampleRate(gMoviePlayer), channels);

        for (i = 0; i < 4; i++) {
            if (channels == 1) {
                SndStreamLock(0, MovieGetAudioBlockSamples(gMoviePlayer), &dstA1, &lenA1, &dstA2, &lenA2);
                MovieDecodeAudioBlock(gMoviePlayer, dstA1, lenA1, dstA2, lenA2, dstB1, lenB1, dstB2, lenB2);
                SndStreamUnlock(0);
                MovieAdvanceAudioBlock(gMoviePlayer);
            } else {
                SndStreamLock(0, MovieGetAudioBlockSamples(gMoviePlayer), &dstA1, &lenA1, &dstA2, &lenA2);
                SndStreamLock(1, MovieGetAudioBlockSamples(gMoviePlayer), &dstB1, &lenB1, &dstB2, &lenB2);
                MovieDecodeAudioBlock(gMoviePlayer, dstA1, lenA1, dstA2, lenA2, dstB1, lenB1, dstB2, lenB2);
                SndStreamUnlock(0);
                SndStreamUnlock(1);
                MovieAdvanceAudioBlock(gMoviePlayer);
            }
        }
    }
    return 1;
}

void MoviePlay(s32 (*a)(s32), s32 b) {
    void* dstA1;
    void* dstA2;
    void* dstB1;
    void* dstB2;
    s32 lenA1;
    s32 lenA2;
    s32 lenB1;
    s32 lenB2;
    u32 channels;
    s32 ok;
    s32 w;
    s32 h;
    s32 x;
    s32 y;

    MovieGetSize(gMoviePlayer, &w, &h);
    x = (240 - w) >> 1;
    y = (160 - h) >> 1;
    MovieDrawFrame(gMoviePlayer, (u16*)0x06000000 + (y * 240 + x));
    MovieAdvanceFrame(gMoviePlayer);
    SndStreamStart();
    channels = MovieGetChannels(gMoviePlayer);
    if (channels != 0) {
        ok = 1;
    } else {
        ok = 0;
    }

    while (1) {
        while (MovieSyncFrame(gMoviePlayer) == 0) {
        }
        MovieDrawFrame(gMoviePlayer, (u16*)0x06000000 + (y * 240 + x));

        if (MovieAdvanceFrame(gMoviePlayer) == 0) {
            break;
        }

        if (ok != 0) {
            if (channels == 1) {
                SndStreamLock(0, MovieGetAudioBlockSamples(gMoviePlayer), &dstA1, &lenA1, &dstA2, &lenA2);
                MovieDecodeAudioBlock(gMoviePlayer, dstA1, lenA1, dstA2, lenA2, dstB1, lenB1, dstB2, lenB2);
                SndStreamUnlock(0);

                if (MovieAdvanceAudioBlock(gMoviePlayer) == 0) {
                    ok = 0;
                }
            } else {
                SndStreamLock(0, MovieGetAudioBlockSamples(gMoviePlayer), &dstA1, &lenA1, &dstA2, &lenA2);
                SndStreamLock(1, MovieGetAudioBlockSamples(gMoviePlayer), &dstB1, &lenB1, &dstB2, &lenB2);
                MovieDecodeAudioBlock(gMoviePlayer, dstA1, lenA1, dstA2, lenA2, dstB1, lenB1, dstB2, lenB2);
                SndStreamUnlock(0);
                SndStreamUnlock(1);

                if (MovieAdvanceAudioBlock(gMoviePlayer) == 0) {
                    ok = 0;
                }
            }
        }

        if (a != 0 && a(b) != 0) {
            break;
        }
    }
}

void MovieClose(void) {
    if (MovieGetChannels(gMoviePlayer)) {
        SndStreamClose();
    }
    MovieFree(gMoviePlayer);
}

void MovieUpdate(void) {
    SndStreamUpdate();
    MovieAdvanceTicks();
}

void MovieSetHeapCallbacks(MovieAllocFunc a, MovieAllocFunc b, MovieFreeFunc c, MovieFreeFunc d) {
    gMovieHeap.iwramAlloc = a;
    gMovieHeap.ewramAlloc = b;
    gMovieHeap.iwramFree = c;
    gMovieHeap.ewramFree = d;
    gMovieHeap.ticks = 0;
}

void MovieAdvanceTicks(void) {
    gMovieHeap.ticks = gMovieHeap.ticks + MOVIE_TICKS_PER_FRAME;
}

u8* MovieGetTicks(void) {
    u8* t;
    u16 vc;

    REG_IME = 0;
    vc = REG_VCNT;
    if (vc > 159) {
        t = gMovieHeap.ticks + (vc - MOVIE_TICKS_PER_FRAME);
    } else {
        t = gMovieHeap.ticks + vc;
    }
    REG_IME = 1;
    return t;
}

float MovieTicksToSeconds(s32 a) {
    return a * MOVIE_SECONDS_PER_TICK;
}

INCLUDE_ASM("movie/MovieSetupVideoCodec.s");
INCLUDE_ASM("movie/MovieSetupAudioCodec.s");

MoviePlayer* MovieOpen(void* a) {
    u32* q;
    u32 len;
    u32 n;
    u16 v1;
    u16 v2;
    MoviePlayer* p;

    p = gMovieHeap.iwramAlloc(sizeof(MoviePlayer));
    p->data = a;
    p->videoDone = 0;
    p->unk_8D = 2;
    q = a;
    p->width = *q;
    q++;
    p->height = *q;
    q++;
    p->frameRate = *(float*)q;
    q++;
    p->frameCount = *q;
    q++;
    p->audioBlockCount = *q;
    q++;
    p->channels = *q;
    q++;
    p->sampleRate = *q;
    q++;
    p->audioCodecId = *q;
    q++;
    p->secondsPerFrame = 1.0f / p->frameRate;
    len = *q;
    q++;
    p->frameTypes = (u8*)q;
    q = (u32*)((u8*)q + len);
    len = *q;
    q++;
    n = *q;
    q++;
    v1 = *(u16*)q;
    p->frameSizes = (u16*)((u8*)q + 2);
    q = (u32*)((u8*)q + len);
    p->videoData = (u8*)q;
    p->videoPos = (u8*)q;
    q = (u32*)((u8*)q + n);

    if ((p->width & 7) != 0 || p->width > 288 || (p->height & 7) != 0) {
        gMovieHeap.iwramFree(p);
        return 0;
    }
    MovieSetupVideoCodec(p, &p->unk_7C, &p->unk_80, &p->unk_84, p->width, p->height);
    p->frameBuf = gMovieHeap.ewramAlloc(p->width * p->height * 2);
    p->workBuf = gMovieHeap.ewramAlloc(p->width * p->height * 2);

    if (p->channels != 0) {
        p->unk_8D = 0;
        len = *q;
        q++;
        p->unk_54 = (u8*)q;
        q = (u32*)((u8*)q + len);
        len = *q;
        q++;
        n = *q;
        q++;
        v2 = *(u16*)q;
        p->audioBlockSizes = (u16*)((u8*)q + 2);
        q = (u32*)((u8*)q + len);
        p->audioData = (u8*)q;
        p->audioPos = (u8*)q;
        q = (u32*)((u8*)q + n);
        p->audioBuf = gMovieHeap.ewramAlloc(0x2000);
        MovieSetupAudioCodec(p, &p->unk_88, p->audioCodecId);
    }
    p->decodeBuf = gMovieHeap.iwramAlloc(v1 > v2 ? v1 : v2);
    p->frameIndex = 0;
    p->audioBlockIndex = 0;
    p->timingStarted = 0;
    p->framePresent = 1;
    return p;
}

void MovieFree(MoviePlayer* a) {
    MoviePlayer* p = a;

    gMovieHeap.iwramFree(p->unk_00);
    gMovieHeap.iwramFree(p->unk_04);
    gMovieHeap.iwramFree(p->unk_08);
    gMovieHeap.ewramFree(p->frameBuf);
    gMovieHeap.ewramFree(p->workBuf);

    if (p->channels != 0) {
        gMovieHeap.ewramFree(p->audioBuf);
    }
    gMovieHeap.iwramFree(p->decodeBuf);
    gMovieHeap.iwramFree(p);
}

void MovieDecodeFrame(MoviePlayer* a) {
    void* t;
    MoviePlayer* p = a;

    switch (p->frameTypes[p->frameIndex]) {
    case 0:
        p->unk_7C(p->workBuf, p->width, p->height, p->decodeBuf);
        break;
    case 1:
        p->unk_84(p->frameBuf, p->workBuf, p->decodeBuf);
        break;
    case 2:
        p->unk_84(p->frameBuf, p->workBuf, p->decodeBuf);
        p->unk_80(p->workBuf, p->width, p->height);
        break;
    }
    p->frameDecoded = 1;
    t = p->frameBuf;
    p->frameBuf = p->workBuf;
    p->workBuf = t;
}

s32 MovieDrawFrame(MoviePlayer* a, void* dst) {
    MoviePlayer* p = a;

    if (p->videoDone != 0) {
        return 0;
    }
    CpuFastSet(p->videoPos, p->decodeBuf, (*(p->frameSizes + p->frameIndex) >> 2) & 0xFFFF);
    MovieDecodeFrame(p);

    if (p->framePresent != 0) {
        CpuFastSet(p->frameBuf, dst, (p->width * p->height / 2) & 0x1FFFFF);
    }
    return p->framePresent;
}

u32 MovieDrawFrameRect(MoviePlayer* a, u32 x, u32 y, u32 w, u32 rows, void* dst, u32 dstStride) {
    MoviePlayer* p = a;
    u16 i;
    u8* d;
    u8* s;

    CpuFastSet(p->videoPos, p->decodeBuf, (*(p->frameSizes + p->frameIndex) >> 2) & 0xFFFF);
    MovieDecodeFrame(p);

    if (p->framePresent != 0) {
        d = dst;
        s = (u8*)p->frameBuf + x * 2 + (p->width << 1) * y;

        for (i = 0; i < rows; i++) {
            CpuFastSet(s, d, ((w << 1) >> 2) & 0x1FFFFF);
            d = d + dstStride;
            s = s + (p->width << 1);
        }
    }
    return p->framePresent;
}

u32 MovieCopyFrameRect(MoviePlayer* a, u32 x, u32 y, u32 w, u32 rows, void* dst, u32 dstStride) {
    MoviePlayer* p = a;
    u16 i;
    u8* d;
    u8* s;

    d = dst;
    s = (u8*)p->frameBuf + x * 2 + (p->width << 1) * y;

    for (i = 0; i < rows; i++) {
        CpuFastSet(s, d, ((w << 1) >> 2) & 0x1FFFFF);
        d = d + dstStride;
        s = s + (p->width << 1);
    }
    return p->framePresent;
}

s32 MovieAdvanceFrame(MoviePlayer* a) {
    MoviePlayer* p = a;

    p->frameIndex++;
    if (p->videoDone != 0 || p->frameIndex == p->frameCount) {
        p->videoDone = 1;
        return 0;
    }

    if (p->timingStarted == 0) {
        p->timingStarted = 1;
        p->startTicks = MovieGetTicks();
    }
    p->videoPos = p->videoPos + *(p->frameSizes + p->frameIndex - 1);
    return 1;
}

u32 MovieGetAudioBlockSamples(MoviePlayer* a) {
    MoviePlayer* p = a;

    if (p->channels == 1) {
        return *(u32*)p->audioPos / 2;
    } else {
        return *(u32*)p->audioPos / 4;
    }
}

void MovieDecodeAudioBlock(MoviePlayer* a, void* dstA1, s32 lenA1, void* dstA2, s32 lenA2, void* dstB1, s32 lenB1, void* dstB2, s32 lenB2) {
    s32 n;
    void* q;
    MoviePlayer* p = a;

    if (p->unk_8D != 0) {
        return;
    }
    CpuFastSet(p->audioPos, p->decodeBuf, (*(p->audioBlockSizes + p->audioBlockIndex) >> 2) & 0xFFFF);
    n = *(s32*)p->decodeBuf;

    if (p->channels == 1) {
        q = (u8*)p->decodeBuf + 4;
        p->unk_88(q, p->audioBuf, n);
        CpuFastSet(p->audioBuf, dstA1, (lenA1 / 4) & 0x1FFFFF);

        if (lenA2 != 0) {
            CpuFastSet((u8*)p->audioBuf + lenA1, dstA2, (lenA2 / 4) & 0x1FFFFF);
        }
    } else {
        n >>= 1;
        q = (u8*)p->decodeBuf + 4;
        p->unk_88(q, p->audioBuf, n);
        q = (u8*)q + ((*(p->audioBlockSizes + p->audioBlockIndex) - 4) >> 1);
        CpuFastSet(p->audioBuf, dstA1, (lenA1 / 4) & 0x1FFFFF);

        if (lenA2 != 0) {
            CpuFastSet((u8*)p->audioBuf + lenA1, dstA2, (lenA2 / 4) & 0x1FFFFF);
        }
        p->unk_88(q, p->audioBuf, n);
        CpuFastSet(p->audioBuf, dstB1, (lenB1 / 4) & 0x1FFFFF);

        if (lenB2 != 0) {
            CpuFastSet((u8*)p->audioBuf + lenB1, dstB2, (lenB2 / 4) & 0x1FFFFF);
        }
    }
}

s32 MovieAdvanceAudioBlock(MoviePlayer* a) {
    MoviePlayer* p = a;

    p->audioBlockIndex++;
    if (p->unk_8D != 0 || p->audioBlockIndex == p->audioBlockCount) {
        if (p->unk_8D != 2) {
            p->unk_8D = 1;
        }
        return 0;
    }

    if (p->channels != 0) {
        p->audioPos = p->audioPos + *(p->audioBlockSizes + p->audioBlockIndex - 1);
    }
    return 1;
}

s32 MovieSyncFrame(MoviePlayer* a) {
    u8* t;
    float now;
    float target;
    MoviePlayer* p = a;

    if (p->videoDone != 0 && p->unk_8D != 0) {
        p->videoDone = 0;

        if (p->unk_8D != 2) {
            p->unk_8D = 0;
        }
        p->audioBlockIndex = 0;
        p->audioPos = p->audioData;
        p->frameIndex = 0;
        p->videoPos = p->videoData;
        p->frameDecoded = 0;
        p->timingStarted = 1;
        p->startTicks = MovieGetTicks();
        return 1;
    }

    if (p->timingStarted == 0) {
        p->frameDecoded = 0;
        p->timingStarted = 1;
        p->startTicks = MovieGetTicks();
    }
    t = MovieGetTicks();
    now = MovieTicksToSeconds(t - p->startTicks);
    target = p->secondsPerFrame * (p->frameIndex + 1);

    if (p->frameDecoded != 0) {
        p->frameDecoded = 0;

        if (now >= target + 0.01f) {
            p->framePresent = 0;
            return 1;
        }
        p->framePresent = 1;
    }
    return now >= target;
}

u32 MovieGetChannels(MoviePlayer* a) {
    MoviePlayer* p = a;

    return p->channels;
}

u32 MovieGetSampleRate(MoviePlayer* a) {
    MoviePlayer* p = a;

    return p->sampleRate;
}

void MovieGetSize(MoviePlayer* a, s32* w, s32* h) {
    MoviePlayer* p = a;

    *w = p->width;
    *h = p->height;
}

asm(".include \"asm/movie_codec.inc\"");
