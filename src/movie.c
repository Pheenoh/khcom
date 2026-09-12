#include "snd_stream.h"
#include "macros.h"
#include "gba/syscall.h"
#include "movie.h"

#define REG_VCNT (*(vu16*)0x04000006)
#define REG_IME (*(vu16*)0x04000208)

#define MOVIE_TICKS_PER_FRAME 228
#define MOVIE_SECONDS_PER_TICK 0.000073433f

MoviePlayer* gMoviePlayer;
u8 gUnk_0203C7C8[8];
MovieHeap gMovieHeap;


void MovieSetCallbacks(MovieAllocFunc a, MovieAllocFunc b, MovieFreeFunc c, MovieFreeFunc d) {
    MovieSetHeapCallbacks(a, b, c, d);
    SndStreamSetCallbacks(a, b, c, d);
}

s32 MovieStart(void* a) {
    void* dstA1;
    void* dstA2;
    void* dstB1;
    void* dstB2;
    u32 lenA1;
    u32 lenA2;
    u32 lenB1;
    u32 lenB2;
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
    u32 lenA1;
    u32 lenA2;
    u32 lenB1;
    u32 lenB2;
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
