#include "macros.h"
#include <string.h>
#include "types.h"
#include "snd_stream.h"
#include "gba/io_reg.h"

SoundStream gSndStream EWRAM_COMMON(16);

#define DMA_SOUND_FIFO                                                        \
    ((DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT |               \
      DMA_DEST_FIXED)                                                         \
     << 16)

#define GBA_CLOCK 16780000.0f
#define GBA_REFRESH 59.727f

#define FRAMES_PER_BUFFER 30

void SndStreamInit(u32 rate, u32 channels) {
    u32 i;

    gSndStream.sampleRate = rate;
    gSndStream.timerReload = 0x10000 - (s32)(GBA_CLOCK / rate + 0.5f);
    gSndStream.samplesPerFrame = (s32)(rate / GBA_REFRESH + 0.5f);
    gSndStream.bufferSize = gSndStream.samplesPerFrame * FRAMES_PER_BUFFER;
    gSndStream.channels = channels;
    gSndStream.playing = 0;
    gSndStream.dmaOffset = 0;
    gSndStream.unk_2C = 0;

    for (i = 0; i < channels; i++) {
        gSndStream.buffers[i] =
            gSndStream.alloc((gSndStream.bufferSize + 3) & ~3);
        memset(gSndStream.buffers[i], 0, gSndStream.bufferSize);
        gSndStream.writePos[i] = 0;
        gSndStream.unk_10[i] = 0;
        gSndStream.unk_18[i] = 0;
        gSndStream.unk_20[i] = 0;
    }

    if (channels == 1) {
        REG_SOUNDCNT_H = 0x0B04;
        REG_SOUNDCNT_X = SOUND_MASTER_ENABLE;
        REG_DMA1SAD = (u32)gSndStream.buffers[0];
        REG_DMA1DAD = REG_ADDR_FIFO_A;
        REG_DMA1CNT = DMA_SOUND_FIFO;
    } else {
        REG_SOUNDCNT_H = 0xA90C;
        REG_SOUNDCNT_X = SOUND_MASTER_ENABLE;
        REG_DMA1SAD = (u32)gSndStream.buffers[0];
        REG_DMA1DAD = REG_ADDR_FIFO_A;
        REG_DMA1CNT = DMA_SOUND_FIFO;
        REG_DMA2SAD = (u32)gSndStream.buffers[1];
        REG_DMA2DAD = REG_ADDR_FIFO_B;
        REG_DMA2CNT = DMA_SOUND_FIFO;
    }
}

void SndStreamUpdate(void) {
    if (gSndStream.playing != 0) {
        gSndStream.dmaOffset += gSndStream.samplesPerFrame;
        if (gSndStream.dmaOffset == gSndStream.bufferSize) {
            gSndStream.dmaOffset = 0;
        }
        gSndStream.unk_2C += gSndStream.samplesPerFrame;

        if (gSndStream.channels == 1) {
            REG_DMA1CNT = 0;
            REG_DMA1SAD =
                (u32)((u8*)gSndStream.buffers[0] + gSndStream.dmaOffset);
            REG_DMA1DAD = REG_ADDR_FIFO_A;
            REG_DMA1CNT = DMA_SOUND_FIFO;
        } else {
            REG_DMA1CNT = 0;
            REG_DMA1SAD =
                (u32)((u8*)gSndStream.buffers[0] + gSndStream.dmaOffset);
            REG_DMA1DAD = REG_ADDR_FIFO_A;
            REG_DMA1CNT = DMA_SOUND_FIFO;
            REG_DMA2CNT = 0;
            REG_DMA2SAD =
                (u32)((u8*)gSndStream.buffers[1] + gSndStream.dmaOffset);
            REG_DMA2DAD = REG_ADDR_FIFO_B;
            REG_DMA2CNT = DMA_SOUND_FIFO;
        }
        REG_SOUNDBIAS = (REG_SOUNDBIAS & 0x3FFF) | SOUND_BIAS_RESOLUTION;
    }
}

void SndStreamLock(u32 ch, u32 len, void** dst1, u32* len1, void** dst2,
                   u32* len2) {
    u32 avail;

    avail = gSndStream.bufferSize - gSndStream.writePos[ch];
    if (avail < len) {
        *dst1 = (u8*)gSndStream.buffers[ch] + gSndStream.writePos[ch];
        *len1 = avail;
        *dst2 = gSndStream.buffers[ch];
        *len2 = len - avail;
        gSndStream.unk_18[ch] = len - avail;
        gSndStream.unk_20[ch] += len;
    } else {
        *dst1 = (u8*)gSndStream.buffers[ch] + gSndStream.writePos[ch];
        *len1 = len;
        *dst2 = 0;
        *len2 = 0;
        gSndStream.unk_18[ch] += len;
        gSndStream.unk_20[ch] += len;
    }

    if (gSndStream.unk_18[ch] == gSndStream.bufferSize) {
        gSndStream.unk_18[ch] = 0;
    }
}

void SndStreamSetCallbacks(void* (*a)(u32), void* (*b)(u32), void (*c)(void*),
                   void (*d)(void*)) {
    gSndStream.unk_48 = a;
    gSndStream.alloc = b;
    gSndStream.unk_50 = c;
    gSndStream.free = d;
}

void SndStreamClose(void) {
    u32 i;

    SndStreamStop();

    for (i = 0; i < gSndStream.channels; i++) {
        gSndStream.free(gSndStream.buffers[i]);
    }
}

void SndStreamStart(void) {
    REG_TM0CNT_L = gSndStream.timerReload;
    REG_TM0CNT_H = TIMER_ENABLE;
    gSndStream.playing = 1;
}

void SndStreamStop(void) {
    if (gSndStream.playing != 0) {
        REG_TM0CNT_H = 0;
        gSndStream.playing = 0;

        if (gSndStream.channels == 1) {
            REG_DMA1CNT = 0;
        } else {
            REG_DMA1CNT = 0;
            REG_DMA2CNT = 0;
        }
    }
}

void SndStreamUnlock(u32 ch) {
    gSndStream.writePos[ch] = gSndStream.unk_18[ch];
    gSndStream.unk_10[ch] = gSndStream.unk_20[ch];
}
