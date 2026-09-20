#include "pcm_audio.h"
#include "sroll_api.h"
#include "m4a.h"

const SoundEntry gUnk_09EFAA7C[13] = {
    {5734, 96, 62610},
    {7884, 132, 63408},
    {10512, 176, 63940},
    {13379, 224, 64282},
    {15768, 264, 64472},
    {18157, 304, 64612},
    {21024, 352, 64738},
    {26758, 448, 64909},
    {31536, 528, 65004},
    {36314, 608, 65073},
    {40137, 672, 65118},
    {42048, 704, 65137},
    {0, 0, 0},
};

static s32 gUnk_020380A0;
static s32 gUnk_020380A4;
static s8 gUnk_020380A8[0x2C0];
static s8 gUnk_02038368[0x2C0];

#define DMA_SOUND_FIFO                                                        \
    ((DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT | DMA_DEST_FIXED) << 16)

#define SOUND_MASTER_ENABLE 0x0080

u8 LookupPcmPlaybackConfig(u32 id, u16* rate, u32* count) {
    s32 i = 0;

    do {
        if (gUnk_09EFAA7C[i].unk_00 == id) {
            *rate = gUnk_09EFAA7C[i].unk_08;
            *count = gUnk_09EFAA7C[i].unk_04;
            return 1;
        }
        i++;
    } while (gUnk_09EFAA7C[i].unk_00 != 0);
    return 0;
}

u8 PcmPlaybackInit(u32 id) {
    u16 rate;
    s32 i;

    if (!LookupPcmPlaybackConfig(id, &rate, (u32*)&gUnk_020380A4)) {
        return 0;
    }
    REG_SOUNDCNT_H = 0x0B06;
    REG_SOUNDCNT_X = SOUND_MASTER_ENABLE;
    REG_DMA1DAD = (s32)&REG_FIFO_A;
    REG_TM0CNT_L = rate;
    REG_DMA1CNT = DMA_SOUND_FIFO;

    for (i = 0; i < gUnk_020380A4; i++) {
        gUnk_020380A8[i] = gUnk_02038368[i] = 0;
    }
    gUnk_020380A0 = 1;
    REG_DMA1SAD = (s32)gUnk_020380A8;
    return 1;
}

void PcmPlaybackStart(void) {
    REG_TM0CNT_H = TIMER_ENABLE;
    REG_DMA1CNT |= DMA_ENABLE << 16;
}

void PcmPlaybackStop(void) {
    REG_DMA1CNT = 0;
    REG_TM0CNT_H = 0;
    REG_SOUNDCNT_H |= 0x800;
}

void PcmPlaybackUpdate(void) {
    s32* src;
    s8* dst;
    s32 pos;
    s32 i;

    src = GetDecodedAudioBuffer();
    pos = GetDecodedAudioReadPosition();
    REG_DMA1CNT ^= DMA_ENABLE << 16;
    REG_DMA1SAD = (s32)(gUnk_020380A0 == 1 ? gUnk_02038368 : gUnk_020380A8);
    REG_DMA1CNT ^= DMA_ENABLE << 16;
    gUnk_020380A0 = gUnk_020380A0 == 1 ? 2 : 1;
    dst = gUnk_020380A0 == 1 ? gUnk_02038368 : gUnk_020380A8;

    if (pos + gUnk_020380A4 <= 0x7FF) {
        for (i = 0; i < gUnk_020380A4; i++) {
            dst[i] = src[pos] >> 8;
            pos++;
        }
        SetDecodedAudioReadPosition(pos);
    } else {
        for (i = 0; i < 0x800 - pos; i++) {
            dst[i] = src[pos + i] >> 8;
        }

        for (; i < gUnk_020380A4; i++) {
            dst[i] = src[pos + i - 0x800] >> 8;
        }
        SetDecodedAudioReadPosition(pos + gUnk_020380A4 - 0x800);
    }
}
