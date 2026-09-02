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
    MovieAllocFunc unk_00;
    MovieAllocFunc unk_04;
    MovieFreeFunc unk_08;
    MovieFreeFunc unk_0C;
    u8* unk_10;
} MovieHeap;

typedef struct MoviePlayer {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    u8* unk_10;
    u8* unk_14;
    u8* unk_18;
    u8* unk_1C;
    void* unk_20;
    void* unk_24;
    void* unk_28;
    u32 unk_2C;
    u32 unk_30;
    float unk_34;
    u32 unk_38;
    u32 unk_3C;
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;
    u8* unk_4C;
    u16* unk_50;
    u8* unk_54;
    u16* unk_58;
    void* unk_5C;
    u32 unk_60;
    u32 unk_64;
    u8* unk_68;
    u32 unk_6C;
    float unk_70;
    u32 unk_74;
    u32 unk_78;
    void (*unk_7C)(void*, u32, u32, void*);
    void (*unk_80)(void*, u32, u32);
    void (*unk_84)(void*, void*, void*);
    void (*unk_88)(void*, void*, s32);
    u8 unk_8C;
    u8 unk_8D;
} MoviePlayer;

extern MoviePlayer* gUnk_0203C7C4;
extern MovieHeap gUnk_0203C7D0;


void SndStreamInit(u32 rate, u32 channels);
void SndStreamUpdate(void);
void SndStreamLock(u32 ch, u32 len, void** dst1, s32* len1, void** dst2, s32* len2);
void SndStreamSetCallbacks(MovieAllocFunc a, MovieAllocFunc b, MovieFreeFunc c, MovieFreeFunc d);
void SndStreamClose(void);
void SndStreamStart(void);
void SndStreamUnlock(u32 ch);

void func_081181BC(MovieAllocFunc a, MovieAllocFunc b, MovieFreeFunc c, MovieFreeFunc d);
s32 func_081181EC(void* a);
void func_08118344(s32 (*a)(s32), s32 b);
void func_08118538(void);
void func_08118564(void);
void func_08118578(MovieAllocFunc a, MovieAllocFunc b, MovieFreeFunc c, MovieFreeFunc d);
void func_081185B0(void);
u8* func_081185CC(void);
float func_08118630(s32 a);
void func_0811865C(MoviePlayer* p, void* a, void* b, void* c, u32 w, u32 h);
void func_08118ADC(MoviePlayer* p, void* a, u32 b);
MoviePlayer* func_08118C34(void* a);
void func_08118EEC(MoviePlayer* a);
void func_08118F7C(MoviePlayer* a);
s32 func_0811904C(MoviePlayer* a, void* dst);
s32 func_08119224(MoviePlayer* a);
u32 func_081192B0(MoviePlayer* a);
void func_081192E8(MoviePlayer* a, void* dstA1, s32 lenA1, void* dstA2, s32 lenA2, void* dstB1, s32 lenB1, void* dstB2, s32 lenB2);
s32 func_08119480(MoviePlayer* a);
s32 func_0811950C(MoviePlayer* a);
u32 func_08119654(MoviePlayer* a);
u32 func_08119670(MoviePlayer* a);
void func_0811968C(MoviePlayer* a, s32* w, s32* h);

void func_081181BC(MovieAllocFunc a, MovieAllocFunc b, MovieFreeFunc c, MovieFreeFunc d) {
    func_08118578(a, b, c, d);
    SndStreamSetCallbacks(a, b, c, d);
}

s32 func_081181EC(void* a) {
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

    gUnk_0203C7C4 = func_08118C34(a);
    if (gUnk_0203C7C4 == 0) {
        return 0;
    }
    channels = func_08119654(gUnk_0203C7C4);
    if (channels != 0) {
        SndStreamInit(func_08119670(gUnk_0203C7C4), channels);
        for (i = 0; i < 4; i++) {
            if (channels == 1) {
                SndStreamLock(0, func_081192B0(gUnk_0203C7C4), &dstA1, &lenA1, &dstA2, &lenA2);
                func_081192E8(gUnk_0203C7C4, dstA1, lenA1, dstA2, lenA2, dstB1, lenB1, dstB2, lenB2);
                SndStreamUnlock(0);
                func_08119480(gUnk_0203C7C4);
            } else {
                SndStreamLock(0, func_081192B0(gUnk_0203C7C4), &dstA1, &lenA1, &dstA2, &lenA2);
                SndStreamLock(1, func_081192B0(gUnk_0203C7C4), &dstB1, &lenB1, &dstB2, &lenB2);
                func_081192E8(gUnk_0203C7C4, dstA1, lenA1, dstA2, lenA2, dstB1, lenB1, dstB2, lenB2);
                SndStreamUnlock(0);
                SndStreamUnlock(1);
                func_08119480(gUnk_0203C7C4);
            }
        }
    }
    return 1;
}

void func_08118344(s32 (*a)(s32), s32 b) {
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

    func_0811968C(gUnk_0203C7C4, &w, &h);
    x = (240 - w) >> 1;
    y = (160 - h) >> 1;
    func_0811904C(gUnk_0203C7C4, (u16*)0x06000000 + (y * 240 + x));
    func_08119224(gUnk_0203C7C4);
    SndStreamStart();
    channels = func_08119654(gUnk_0203C7C4);
    if (channels != 0) {
        ok = 1;
    } else {
        ok = 0;
    }
    while (1) {
        while (func_0811950C(gUnk_0203C7C4) == 0) {
        }
        func_0811904C(gUnk_0203C7C4, (u16*)0x06000000 + (y * 240 + x));
        if (func_08119224(gUnk_0203C7C4) == 0) {
            break;
        }
        if (ok != 0) {
            if (channels == 1) {
                SndStreamLock(0, func_081192B0(gUnk_0203C7C4), &dstA1, &lenA1, &dstA2, &lenA2);
                func_081192E8(gUnk_0203C7C4, dstA1, lenA1, dstA2, lenA2, dstB1, lenB1, dstB2, lenB2);
                SndStreamUnlock(0);
                if (func_08119480(gUnk_0203C7C4) == 0) {
                    ok = 0;
                }
            } else {
                SndStreamLock(0, func_081192B0(gUnk_0203C7C4), &dstA1, &lenA1, &dstA2, &lenA2);
                SndStreamLock(1, func_081192B0(gUnk_0203C7C4), &dstB1, &lenB1, &dstB2, &lenB2);
                func_081192E8(gUnk_0203C7C4, dstA1, lenA1, dstA2, lenA2, dstB1, lenB1, dstB2, lenB2);
                SndStreamUnlock(0);
                SndStreamUnlock(1);
                if (func_08119480(gUnk_0203C7C4) == 0) {
                    ok = 0;
                }
            }
        }
        if (a != 0 && a(b) != 0) {
            break;
        }
    }
}

void func_08118538(void) {
    if (func_08119654(gUnk_0203C7C4)) {
        SndStreamClose();
    }
    func_08118EEC(gUnk_0203C7C4);
}

void func_08118564(void) {
    SndStreamUpdate();
    func_081185B0();
}

void func_08118578(MovieAllocFunc a, MovieAllocFunc b, MovieFreeFunc c, MovieFreeFunc d) {
    gUnk_0203C7D0.unk_00 = a;
    gUnk_0203C7D0.unk_04 = b;
    gUnk_0203C7D0.unk_08 = c;
    gUnk_0203C7D0.unk_0C = d;
    gUnk_0203C7D0.unk_10 = 0;
}

void func_081185B0(void) {
    gUnk_0203C7D0.unk_10 = gUnk_0203C7D0.unk_10 + MOVIE_TICKS_PER_FRAME;
}

u8* func_081185CC(void) {
    u8* t;
    u16 vc;

    REG_IME = 0;
    vc = REG_VCNT;
    if (vc > 159) {
        t = gUnk_0203C7D0.unk_10 + (vc - MOVIE_TICKS_PER_FRAME);
    } else {
        t = gUnk_0203C7D0.unk_10 + vc;
    }
    REG_IME = 1;
    return t;
}

float func_08118630(s32 a) {
    return a * MOVIE_SECONDS_PER_TICK;
}

INCLUDE_ASM("m4a/func_0811865C.s");
INCLUDE_ASM("m4a/func_08118ADC.s");

MoviePlayer* func_08118C34(void* a) {
    u32* q;
    u32 len;
    u32 n;
    u16 v1;
    u16 v2;
    MoviePlayer* p;

    p = gUnk_0203C7D0.unk_00(sizeof(MoviePlayer));
    p->unk_0C = a;
    p->unk_8C = 0;
    p->unk_8D = 2;
    q = a;
    p->unk_2C = *q;
    q++;
    p->unk_30 = *q;
    q++;
    p->unk_34 = *(float*)q;
    q++;
    p->unk_38 = *q;
    q++;
    p->unk_3C = *q;
    q++;
    p->unk_40 = *q;
    q++;
    p->unk_44 = *q;
    q++;
    p->unk_48 = *q;
    q++;
    p->unk_70 = 1.0f / p->unk_34;
    len = *q;
    q++;
    p->unk_4C = (u8*)q;
    q = (u32*)((u8*)q + len);
    len = *q;
    q++;
    n = *q;
    q++;
    v1 = *(u16*)q;
    p->unk_50 = (u16*)((u8*)q + 2);
    q = (u32*)((u8*)q + len);
    p->unk_10 = (u8*)q;
    p->unk_14 = (u8*)q;
    q = (u32*)((u8*)q + n);
    if ((p->unk_2C & 7) != 0 || p->unk_2C > 288 || (p->unk_30 & 7) != 0) {
        gUnk_0203C7D0.unk_08(p);
        return 0;
    }
    func_0811865C(p, &p->unk_7C, &p->unk_80, &p->unk_84, p->unk_2C, p->unk_30);
    p->unk_20 = gUnk_0203C7D0.unk_04(p->unk_2C * p->unk_30 * 2);
    p->unk_24 = gUnk_0203C7D0.unk_04(p->unk_2C * p->unk_30 * 2);
    if (p->unk_40 != 0) {
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
        p->unk_58 = (u16*)((u8*)q + 2);
        q = (u32*)((u8*)q + len);
        p->unk_18 = (u8*)q;
        p->unk_1C = (u8*)q;
        q = (u32*)((u8*)q + n);
        p->unk_28 = gUnk_0203C7D0.unk_04(0x2000);
        func_08118ADC(p, &p->unk_88, p->unk_48);
    }
    p->unk_5C = gUnk_0203C7D0.unk_00(v1 > v2 ? v1 : v2);
    p->unk_60 = 0;
    p->unk_64 = 0;
    p->unk_6C = 0;
    p->unk_78 = 1;
    return p;
}

void func_08118EEC(MoviePlayer* a) {
    MoviePlayer* p = a;

    gUnk_0203C7D0.unk_08(p->unk_00);
    gUnk_0203C7D0.unk_08(p->unk_04);
    gUnk_0203C7D0.unk_08(p->unk_08);
    gUnk_0203C7D0.unk_0C(p->unk_20);
    gUnk_0203C7D0.unk_0C(p->unk_24);
    if (p->unk_40 != 0) {
        gUnk_0203C7D0.unk_0C(p->unk_28);
    }
    gUnk_0203C7D0.unk_08(p->unk_5C);
    gUnk_0203C7D0.unk_08(p);
}

void func_08118F7C(MoviePlayer* a) {
    void* t;
    MoviePlayer* p = a;

    switch (p->unk_4C[p->unk_60]) {
    case 0:
        p->unk_7C(p->unk_24, p->unk_2C, p->unk_30, p->unk_5C);
        break;
    case 1:
        p->unk_84(p->unk_20, p->unk_24, p->unk_5C);
        break;
    case 2:
        p->unk_84(p->unk_20, p->unk_24, p->unk_5C);
        p->unk_80(p->unk_24, p->unk_2C, p->unk_30);
        break;
    }
    p->unk_74 = 1;
    t = p->unk_20;
    p->unk_20 = p->unk_24;
    p->unk_24 = t;
}

s32 func_0811904C(MoviePlayer* a, void* dst) {
    MoviePlayer* p = a;

    if (p->unk_8C != 0) {
        return 0;
    }
    CpuFastSet(p->unk_14, p->unk_5C, (*(p->unk_50 + p->unk_60) >> 2) & 0xFFFF);
    func_08118F7C(p);
    if (p->unk_78 != 0) {
        CpuFastSet(p->unk_20, dst, (p->unk_2C * p->unk_30 / 2) & 0x1FFFFF);
    }
    return p->unk_78;
}

u32 func_081190C8(MoviePlayer* a, u32 x, u32 y, u32 w, u32 rows, void* dst, u32 dstStride) {
    MoviePlayer* p = a;
    u16 i;
    u8* d;
    u8* s;

    CpuFastSet(p->unk_14, p->unk_5C, (*(p->unk_50 + p->unk_60) >> 2) & 0xFFFF);
    func_08118F7C(p);
    if (p->unk_78 != 0) {
        d = dst;
        s = (u8*)p->unk_20 + x * 2 + (p->unk_2C << 1) * y;
        for (i = 0; i < rows; i++) {
            CpuFastSet(s, d, ((w << 1) >> 2) & 0x1FFFFF);
            d = d + dstStride;
            s = s + (p->unk_2C << 1);
        }
    }
    return p->unk_78;
}

u32 func_08119190(MoviePlayer* a, u32 x, u32 y, u32 w, u32 rows, void* dst, u32 dstStride) {
    MoviePlayer* p = a;
    u16 i;
    u8* d;
    u8* s;

    d = dst;
    s = (u8*)p->unk_20 + x * 2 + (p->unk_2C << 1) * y;
    for (i = 0; i < rows; i++) {
        CpuFastSet(s, d, ((w << 1) >> 2) & 0x1FFFFF);
        d = d + dstStride;
        s = s + (p->unk_2C << 1);
    }
    return p->unk_78;
}

s32 func_08119224(MoviePlayer* a) {
    MoviePlayer* p = a;

    p->unk_60++;
    if (p->unk_8C != 0 || p->unk_60 == p->unk_38) {
        p->unk_8C = 1;
        return 0;
    }
    if (p->unk_6C == 0) {
        p->unk_6C = 1;
        p->unk_68 = func_081185CC();
    }
    p->unk_14 = p->unk_14 + *(p->unk_50 + p->unk_60 - 1);
    return 1;
}

u32 func_081192B0(MoviePlayer* a) {
    MoviePlayer* p = a;

    if (p->unk_40 == 1) {
        return *(u32*)p->unk_1C / 2;
    } else {
        return *(u32*)p->unk_1C / 4;
    }
}

void func_081192E8(MoviePlayer* a, void* dstA1, s32 lenA1, void* dstA2, s32 lenA2, void* dstB1, s32 lenB1, void* dstB2, s32 lenB2) {
    s32 n;
    void* q;
    MoviePlayer* p = a;

    if (p->unk_8D != 0) {
        return;
    }
    CpuFastSet(p->unk_1C, p->unk_5C, (*(p->unk_58 + p->unk_64) >> 2) & 0xFFFF);
    n = *(s32*)p->unk_5C;
    if (p->unk_40 == 1) {
        q = (u8*)p->unk_5C + 4;
        p->unk_88(q, p->unk_28, n);
        CpuFastSet(p->unk_28, dstA1, (lenA1 / 4) & 0x1FFFFF);
        if (lenA2 != 0) {
            CpuFastSet((u8*)p->unk_28 + lenA1, dstA2, (lenA2 / 4) & 0x1FFFFF);
        }
    } else {
        n >>= 1;
        q = (u8*)p->unk_5C + 4;
        p->unk_88(q, p->unk_28, n);
        q = (u8*)q + ((*(p->unk_58 + p->unk_64) - 4) >> 1);
        CpuFastSet(p->unk_28, dstA1, (lenA1 / 4) & 0x1FFFFF);
        if (lenA2 != 0) {
            CpuFastSet((u8*)p->unk_28 + lenA1, dstA2, (lenA2 / 4) & 0x1FFFFF);
        }
        p->unk_88(q, p->unk_28, n);
        CpuFastSet(p->unk_28, dstB1, (lenB1 / 4) & 0x1FFFFF);
        if (lenB2 != 0) {
            CpuFastSet((u8*)p->unk_28 + lenB1, dstB2, (lenB2 / 4) & 0x1FFFFF);
        }
    }
}

s32 func_08119480(MoviePlayer* a) {
    MoviePlayer* p = a;

    p->unk_64++;
    if (p->unk_8D != 0 || p->unk_64 == p->unk_3C) {
        if (p->unk_8D != 2) {
            p->unk_8D = 1;
        }
        return 0;
    }
    if (p->unk_40 != 0) {
        p->unk_1C = p->unk_1C + *(p->unk_58 + p->unk_64 - 1);
    }
    return 1;
}

s32 func_0811950C(MoviePlayer* a) {
    u8* t;
    float now;
    float target;
    MoviePlayer* p = a;

    if (p->unk_8C != 0 && p->unk_8D != 0) {
        p->unk_8C = 0;
        if (p->unk_8D != 2) {
            p->unk_8D = 0;
        }
        p->unk_64 = 0;
        p->unk_1C = p->unk_18;
        p->unk_60 = 0;
        p->unk_14 = p->unk_10;
        p->unk_74 = 0;
        p->unk_6C = 1;
        p->unk_68 = func_081185CC();
        return 1;
    }
    if (p->unk_6C == 0) {
        p->unk_74 = 0;
        p->unk_6C = 1;
        p->unk_68 = func_081185CC();
    }
    t = func_081185CC();
    now = func_08118630(t - p->unk_68);
    target = p->unk_70 * (p->unk_60 + 1);
    if (p->unk_74 != 0) {
        p->unk_74 = 0;
        if (now >= target + 0.01f) {
            p->unk_78 = 0;
            return 1;
        }
        p->unk_78 = 1;
    }
    return now >= target;
}

u32 func_08119654(MoviePlayer* a) {
    MoviePlayer* p = a;

    return p->unk_40;
}

u32 func_08119670(MoviePlayer* a) {
    MoviePlayer* p = a;

    return p->unk_44;
}

void func_0811968C(MoviePlayer* a, s32* w, s32* h) {
    MoviePlayer* p = a;

    *w = p->unk_2C;
    *h = p->unk_30;
}

INCLUDE_ASM("m4a/func_081196B4.s");
