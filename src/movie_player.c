#include "macros.h"
#include "gba/syscall.h"
#include "movie.h"

extern u8 gUnk_0811CE44[];
extern u8 gUnk_0811CE48[];
extern u8 gUnk_0811D10C[];
extern u8 gUnk_0811D184[];
extern u8 gUnk_0811D1A4[];
extern u8 gUnk_0811D1B0[];
extern u16 gUnk_09D6D1E4[];

void* memcpy(void* dst, const void* src, unsigned long n);

extern u8 gUnk_081196B4[];
extern u8 MovieVideoCodecEnd[];
extern u8 MovieVideoCodecConstants[];
extern u8 gUnk_08119714[];
extern u8 gUnk_08119DB8[];
extern u8 gUnk_08119E70[];
extern u8 gUnk_0811C9E4[];
extern u8 gUnk_0811CDE4[];
extern u8 gUnk_09D6D184[];
extern s32 gUnk_09D6D298[];

void MovieSetupVideoCodec(MoviePlayer* p, void* a, void* b, void* c, s32 w, s32 h) {
    u32 size1;
    u32 size2;
    s32 i;
    s32 x;
    s32 y;
    s32* table;
    u32* pos;
    u32 instruction;

    size1 = MovieVideoCodecEnd - gUnk_081196B4;
    size2 = gUnk_0811CE44 - gUnk_08119E70;
    p->unk_00 = gMovieHeap.iwramAlloc(size1);
    memcpy(p->unk_00, gUnk_081196B4, size1);
    *(void**)a = (u8*)p->unk_00 - (gUnk_081196B4 - gUnk_08119714);
    *(void**)b = (u8*)p->unk_00 - (gUnk_081196B4 - gUnk_08119DB8);
    memcpy((u8*)p->unk_00 - (gUnk_081196B4 - MovieVideoCodecConstants), gUnk_09D6D184, 96);
    p->unk_04 = gMovieHeap.iwramAlloc(size2);
    memcpy(p->unk_04, gUnk_08119E70, size2);
    *(void**)c = (u8*)p->unk_04 - (gUnk_08119E70 - gUnk_0811CDE4);
    table = (s32*)((u8*)p->unk_04 - (gUnk_08119E70 - gUnk_0811C9E4));

    for (pos = p->unk_04; (u8*)pos < (u8*)p->unk_04 + size2; pos++) {
        instruction = *pos;
        if ((instruction & 0xEF000000) == 0xEF000000) {
            u8 kind;
            s32 offsets[] = {0, 4, 8, 12};
            s32 encoded;
            u8 rotate;
            u8 immediate;
            s32 shift;
            s32 value;
            s32 j;
            s32 rotated;

            switch (kind = (instruction & 0x00F00000) >> 20) {
            case 0:
            case 1:
                if (kind == 0) {
                    encoded = 0xE5800000;
                } else {
                    encoded = 0xE5900000;
                }
                encoded |= ((instruction & 0x000F0000) >> 16) << 12;
                encoded |= ((instruction & 0x0000F000) >> 12) << 16;
                encoded |= ((w << 1) * ((instruction & 0xF0) >> 4) + offsets[instruction & 15]) & 0xFFF;
                *pos = encoded;
                break;
            case 3:
            case 4:
                if (kind == 3) {
                    encoded = 0xE2800000;
                } else if (kind == 4) {
                    encoded = 0xE2400000;
                }
                encoded |= ((instruction & 0x000F0000) >> 16) << 12;
                encoded |= ((instruction & 0x0000F000) >> 12) << 16;
                value = (w << 1) * ((instruction & 0xF0) >> 4) + offsets[instruction & 15];
                for (shift = 0; shift < 16; shift++) {
                    if ((value & gUnk_09D6D298[shift]) == value) {
                        j = 32 - shift * 2;
                        rotated = ((value & ((1U << j) - 1)) << (32 - j)) + (value >> j);
                        immediate = rotated & 0xFF;
                        rotate = shift;
                        break;
                    }
                }
                encoded |= (rotate << 8) | immediate;
                *pos = encoded;
                break;
            case 2:
                rotated = 0xE3A00000;
                rotated |= ((instruction & 0x000F0000) >> 16) << 12;
                if ((instruction & 15) == 0) {
                    value = (w << 1) >> 4;
                    for (j = 0; j < 16; j++) {
                        if ((value & gUnk_09D6D298[j]) == value) {
                            shift = 32 - j * 2;
                            encoded = ((value & ((1U << shift) - 1)) << (32 - shift)) + (value >> shift);
                            rotate = encoded & 0xFF;
                            immediate = j;
                            break;
                        }
                    }
                } else {
                    value = (h << 1) >> 4;
                    for (j = 0; j < 16; j++) {
                        if ((value & gUnk_09D6D298[j]) == value) {
                            shift = 32 - j * 2;
                            encoded = ((value & ((1U << shift) - 1)) << (32 - shift)) + (value >> shift);
                            rotate = encoded & 0xFF;
                            immediate = j;
                            break;
                        }
                    }
                }
                rotated |= (immediate << 8) | rotate;
                *pos = rotated;
                break;
            default:
                break;
            }
        }
    }
    i = 0;
    for (y = -8; y < 8; y++) {
        for (x = -8; x < 8; x++) {
            table[i++] = (y * w + x) * 2;
        }
    }
}


void MovieSetupAudioCodec(MoviePlayer* p, void* a, s32 b) {
    u32 size;
    s32 j;
    s32 i;
    s32 v;
    s16* dest;
    u32 pad;

    size = gUnk_0811D1B0 - gUnk_0811CE44;
    p->unk_08 = gMovieHeap.iwramAlloc(size);
    memcpy(p->unk_08, gUnk_0811CE44, size);
    switch (b) {
    case 0:
        *(void**)a = (u8*)p->unk_08 - (gUnk_0811CE44 - gUnk_0811D184);
        break;
    case 1:
        *(void**)a = (u8*)p->unk_08 - (gUnk_0811CE44 - gUnk_0811D1A4);
        break;
    case 2:
        *(void**)a = (u8*)p->unk_08 - (gUnk_0811CE44 - gUnk_0811D10C);
        dest = (s16*)((u8*)p->unk_08 - (gUnk_0811CE44 - gUnk_0811CE48));
        for (i = 0; i <= 0x58; i++) {
            v = gUnk_09D6D1E4[i];
            for (j = 0; j <= 3; j++) {
                if (j <= 1) {
                    dest[(i << 2) + j] = j * v + v / 2;
                } else {
                    dest[(i << 2) + j] = -((j & 1) * v + v / 2);
                }
            }
        }
        break;
    }
}

ALIGN_ZERO(2);

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
