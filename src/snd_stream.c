#include "types.h"
#include "snd_stream.h"

SoundStream gSndStream;

#define REG_SOUNDCNT_H (*(vu16*)0x04000082)
#define REG_SOUNDCNT_X (*(vu16*)0x04000084)
#define REG_SOUNDBIAS (*(vu16*)0x04000088)
#define REG_ADDR_FIFO_A ((void*)0x040000A0)
#define REG_ADDR_FIFO_B ((void*)0x040000A4)
#define REG_DMA1SAD (*(void* volatile*)0x040000BC)
#define REG_DMA1DAD (*(void* volatile*)0x040000C0)
#define REG_DMA1CNT (*(vu32*)0x040000C4)
#define REG_DMA2SAD (*(void* volatile*)0x040000C8)
#define REG_DMA2DAD (*(void* volatile*)0x040000CC)
#define REG_DMA2CNT (*(vu32*)0x040000D0)
#define REG_TM0CNT_L (*(vu16*)0x04000100)
#define REG_TM0CNT_H (*(vu16*)0x04000102)

#define DMA_DEST_FIXED 0x0040
#define DMA_REPEAT 0x0200
#define DMA_32BIT 0x0400
#define DMA_START_SPECIAL 0x3000
#define DMA_ENABLE 0x8000

#define DMA_SOUND_FIFO                                                        \
    ((DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT |               \
      DMA_DEST_FIXED)                                                         \
     << 16)

#define TIMER_ENABLE 0x0080

#define SOUND_BIAS_RESOLUTION 0x4000

#define SOUND_MASTER_ENABLE 0x0080

#define GBA_CLOCK 16780000.0f
#define GBA_REFRESH 59.727f

#define FRAMES_PER_BUFFER 30

void* memset(void* dst, s32 c, unsigned long n);

void SndStreamInit(u32 rate, u32 channels) {
    u32 i;

    gSndStream.unk_38 = rate;
    gSndStream.unk_3C = 0x10000 - (s32)(GBA_CLOCK / rate + 0.5f);
    gSndStream.unk_30 = (s32)(rate / GBA_REFRESH + 0.5f);
    gSndStream.unk_34 = gSndStream.unk_30 * FRAMES_PER_BUFFER;
    gSndStream.unk_40 = channels;
    gSndStream.unk_44 = 0;
    gSndStream.unk_28 = 0;
    gSndStream.unk_2C = 0;

    for (i = 0; i < channels; i++) {
        gSndStream.unk_00[i] =
            gSndStream.unk_4C((gSndStream.unk_34 + 3) & ~3);
        memset(gSndStream.unk_00[i], 0, gSndStream.unk_34);
        gSndStream.unk_08[i] = 0;
        gSndStream.unk_10[i] = 0;
        gSndStream.unk_18[i] = 0;
        gSndStream.unk_20[i] = 0;
    }

    if (channels == 1) {
        REG_SOUNDCNT_H = 0x0B04;
        REG_SOUNDCNT_X = SOUND_MASTER_ENABLE;
        REG_DMA1SAD = gSndStream.unk_00[0];
        REG_DMA1DAD = REG_ADDR_FIFO_A;
        REG_DMA1CNT = DMA_SOUND_FIFO;
    } else {
        REG_SOUNDCNT_H = 0xA90C;
        REG_SOUNDCNT_X = SOUND_MASTER_ENABLE;
        REG_DMA1SAD = gSndStream.unk_00[0];
        REG_DMA1DAD = REG_ADDR_FIFO_A;
        REG_DMA1CNT = DMA_SOUND_FIFO;
        REG_DMA2SAD = gSndStream.unk_00[1];
        REG_DMA2DAD = REG_ADDR_FIFO_B;
        REG_DMA2CNT = DMA_SOUND_FIFO;
    }
}

void SndStreamUpdate(void) {
    if (gSndStream.unk_44 != 0) {
        gSndStream.unk_28 += gSndStream.unk_30;
        if (gSndStream.unk_28 == gSndStream.unk_34) {
            gSndStream.unk_28 = 0;
        }
        gSndStream.unk_2C += gSndStream.unk_30;

        if (gSndStream.unk_40 == 1) {
            REG_DMA1CNT = 0;
            REG_DMA1SAD =
                (u8*)gSndStream.unk_00[0] + gSndStream.unk_28;
            REG_DMA1DAD = REG_ADDR_FIFO_A;
            REG_DMA1CNT = DMA_SOUND_FIFO;
        } else {
            REG_DMA1CNT = 0;
            REG_DMA1SAD =
                (u8*)gSndStream.unk_00[0] + gSndStream.unk_28;
            REG_DMA1DAD = REG_ADDR_FIFO_A;
            REG_DMA1CNT = DMA_SOUND_FIFO;
            REG_DMA2CNT = 0;
            REG_DMA2SAD =
                (u8*)gSndStream.unk_00[1] + gSndStream.unk_28;
            REG_DMA2DAD = REG_ADDR_FIFO_B;
            REG_DMA2CNT = DMA_SOUND_FIFO;
        }
        REG_SOUNDBIAS = (REG_SOUNDBIAS & 0x3FFF) | SOUND_BIAS_RESOLUTION;
    }
}

void SndStreamLock(u32 ch, u32 len, void** dst1, u32* len1, void** dst2,
                   u32* len2) {
    u32 avail;

    avail = gSndStream.unk_34 - gSndStream.unk_08[ch];
    if (avail < len) {
        *dst1 = (u8*)gSndStream.unk_00[ch] + gSndStream.unk_08[ch];
        *len1 = avail;
        *dst2 = gSndStream.unk_00[ch];
        *len2 = len - avail;
        gSndStream.unk_18[ch] = len - avail;
        gSndStream.unk_20[ch] += len;
    } else {
        *dst1 = (u8*)gSndStream.unk_00[ch] + gSndStream.unk_08[ch];
        *len1 = len;
        *dst2 = 0;
        *len2 = 0;
        gSndStream.unk_18[ch] += len;
        gSndStream.unk_20[ch] += len;
    }

    if (gSndStream.unk_18[ch] == gSndStream.unk_34) {
        gSndStream.unk_18[ch] = 0;
    }
}

void SndStreamSetCallbacks(void (*a)(void), void* (*b)(u32), void (*c)(void),
                   void (*d)(void*)) {
    gSndStream.unk_48 = a;
    gSndStream.unk_4C = b;
    gSndStream.unk_50 = c;
    gSndStream.unk_54 = d;
}

void SndStreamClose(void) {
    u32 i;

    SndStreamStop();

    for (i = 0; i < gSndStream.unk_40; i++) {
        gSndStream.unk_54(gSndStream.unk_00[i]);
    }
}

void SndStreamStart(void) {
    REG_TM0CNT_L = gSndStream.unk_3C;
    REG_TM0CNT_H = TIMER_ENABLE;
    gSndStream.unk_44 = 1;
}

void SndStreamStop(void) {
    if (gSndStream.unk_44 != 0) {
        REG_TM0CNT_H = 0;
        gSndStream.unk_44 = 0;

        if (gSndStream.unk_40 == 1) {
            REG_DMA1CNT = 0;
        } else {
            REG_DMA1CNT = 0;
            REG_DMA2CNT = 0;
        }
    }
}

void SndStreamUnlock(u32 ch) {
    gSndStream.unk_08[ch] = gSndStream.unk_18[ch];
    gSndStream.unk_10[ch] = gSndStream.unk_20[ch];
}
