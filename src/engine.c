#include "macros.h"
#include "gba/syscall.h"
#include "malloc.h"
#include "engine.h"
#include "types.h"

void* func_08000BC8(void* node, void* pool);
void func_08000BF4(void* node, void* pool, void* after);
void func_08000C24(void* node, void* pool, void* before);
void* func_08000C8C(void* pool);
void* func_08000CD4(void* node);
void* func_08000D0C(void* pool);
void* func_08007E00(void* src, void* dst, u16 size);
void func_08000C54(void* node, void* pool);
extern s16 gSineTable[];
extern u16 gBg0Cnt;
extern u16 gBg1Cnt;
extern u16 gBg2Cnt;
extern u16 gBg3Cnt;

typedef struct BgAffineSrcData {
    s32 texX;
    s32 texY;
    s16 scrX;
    s16 scrY;
    s16 sx;
    s16 sy;
    u16 alpha;
} BgAffineSrcData;

typedef struct BgAffineDstData {
    s16 pa;
    s16 pb;
    s16 pc;
    s16 pd;
    s32 dx;
    s32 dy;
} BgAffineDstData;

void BgAffineSet(BgAffineSrcData* src, BgAffineDstData* dst, s32 count);

extern u8* gUnk_03007574;
extern u16 gBg0Cnt;
extern u16 gBg1Cnt;
extern u16 gBg2Cnt;
extern u16 gUnk_0203404C;
extern u16 gUnk_0203404E;
extern u16 gUnk_02034056;
extern u16 gUnk_0203406A;
extern u16 gUnk_02034044;
extern u16 gUnk_02034046;
extern u8 gUnk_02034054;
extern u8 gUnk_02034058;
extern u32 gUnk_0203405C;
extern u32 gUnk_02034060;
extern u8 gUnk_02034064;
void func_080066F4(s16 x, s16 y);
void func_08007E68(s32 a);
void func_08007E7C(void);

extern u16 gUnk_03006C78;
ObjTiles* AllocObjTiles(u16 size, void* owner);
u16 func_08001DB0(u16 a, u16 b);
s32 func_08005824(s32 a, s32 b);
s32 func_0800585C(s32 a, s32 b);
void func_08005C60(u16 a);

extern u16 gBldY;
extern u16 gWin0H;
extern u16 gWin1H;
extern u16 gWin0V;
extern u16 gWin1V;
extern u16 gWinIn;
extern u16 gWinOut;
extern u16 gBg2PA;
extern u16 gBg2PB;
extern u16 gBg2PC;
extern u16 gBg2PD;
extern u32 gBg2X;
extern u32 gBg2Y;
extern u16 gBg3PA;
extern u16 gBg3PB;
extern u16 gBg3PC;
extern u16 gBg3PD;
extern u32 gBg3X;
extern u32 gBg3Y;
extern u16 gUnk_0203404C;
extern u16 gUnk_0203404E;
extern u16 gUnk_02034056;
extern u16 gUnk_0203406A;
extern u16 gUnk_02034044;
extern u16 gUnk_02034046;
extern u8 gUnk_02034054;
extern u8 gUnk_02034058;
extern u32 gUnk_0203405C;
extern u32 gUnk_02034060;
extern u8 gUnk_02034064;
void func_080066F4(s16 x, s16 y);
void func_08007E68(s32 a);
void func_08007E7C(void);

extern u16 gUnk_03006C78;
ObjTiles* AllocObjTiles(u16 size, void* owner);
u16 func_08001DB0(u16 a, u16 b);
s32 func_08005824(s32 a, s32 b);
s32 func_0800585C(s32 a, s32 b);
void func_08005C60(u16 a);

INCLUDE_ASM("engine/func_0800216C.s");
#ifdef NON_MATCHING
u8 func_080022D4(s16 x, s16 y, void* obj, void* e, s32 f, u16 g, u16 h) {
    u8* p;

    if (e != 0 && ((ObjTiles*)obj)->unk_00 != 0) {
        p = gSpriteWork;
        *(u16*)(p + 0x1AB8 + *(u16*)(p + 0x28A8) * 24) = x;
        *(u16*)(p + 0x1ABA + *(u16*)(p + 0x28A8) * 24) = y;
        *(void**)(p + 0x1AA8 + *(u16*)(p + 0x28A8) * 24) = obj;
        *(void**)(p + 0x1AAC + *(u16*)(p + 0x28A8) * 24) = e;
        *(s32*)(p + 0x1AB0 + *(u16*)(p + 0x28A8) * 24) = f;
        *(u16*)(p + 0x1ABE + *(u16*)(p + 0x28A8) * 24) = g;
        *(u16*)(p + 0x1ABC + *(u16*)(p + 0x28A8) * 24) = h;
        *(u32*)(p + 0x1AB4 + *(u16*)(p + 0x28A8) * 24) = ((ObjTiles*)obj)->unk_20;
        *(u32*)(p + 0x26A8 + *(u16*)(p + 0x28A8) * 4) =
            (u32)(p + *(u16*)(p + 0x28A8) * 24 + 0x1AA8);
        *(u16*)(p + 0x28A8) += 1;
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("engine/func_080022D4.s");
#endif

u8 DrawSprite(u16 x, u16 y, void* c, void* obj, void* e, s32 f, u16 g, u16 h) {
    if (*(u16*)(gSpriteWork + 0x28A8) <= 127 && obj != 0) {
        switch (*(u32*)((u8*)obj + 0x28)) {
        case 0:
            return func_08002060((s16)x, (s16)y, c, obj, e, f, g, h);
        case 1:
            return func_0800216C((s16)x, (s16)y, c, obj, e, f, g, h);
        case 2:
            return func_080022D4((s16)x, (s16)y, obj, e, f, g, h);
        }
    }
    return 0;
}

#ifdef NON_MATCHING
void func_08002488(u16 a, u16 b, void* c, void* d, void* e, u16 f) {
    u8* p;
    u32 z;

    p = gSpriteWork;
    if (*(u16*)(p + 0x28A8) > 0x7F) {
        return;
    }
    z = 0;
    *(u16*)(p + *(u16*)(p + 0x28A8) * 24 + 0x1AB8) = a;
    *(u16*)(p + *(u16*)(p + 0x28A8) * 24 + 0x1ABA) = b;
    *(void**)(p + *(u16*)(p + 0x28A8) * 24 + 0x1AA8) = d;
    *(void**)(p + *(u16*)(p + 0x28A8) * 24 + 0x1AAC) = e;
    *(u32*)(p + *(u16*)(p + 0x28A8) * 24 + 0x1AB0) = z;
    *(u16*)(p + *(u16*)(p + 0x28A8) * 24 + 0x1ABE) = f;
    *(u16*)(p + *(u16*)(p + 0x28A8) * 24 + 0x1ABC) = z;
    *(void**)(p + *(u16*)(p + 0x28A8) * 24 + 0x1AB4) = c;
    *(u32*)(p + *(u16*)(p + 0x28A8) * 4 + 0x26A8) = (u32)(p + *(u16*)(p + 0x28A8) * 24 + 0x1AA8);
    *(u16*)(p + 0x28A8) += 1;
    *(u16*)(p + 0x28AA) += 1;
}
#else
INCLUDE_ASM("engine/func_08002488.s");
#endif

ObjTiles* LoadObjTiles(void* src, u16 size) {
    ObjTiles* node;
    ObjTiles* cur;
    ObjTiles* next;
    s32 avail;
    s16 end;

    if (size == 0) {
        return 0;
    }
    if (src == 0) {
        return 0;
    }
    cur = func_08000C8C(gSpriteWork + 0x1800);
    while (cur != 0) {
        if (cur->unk_00 == src && cur->unk_24 == 0) {
            cur->unk_04++;
            return cur;
        }
        cur = func_08000CD4(cur->unk_0C);
    }
    node = func_08000D0C(gSpriteWork + 0x1800);
    if (node == 0) {
        return 0;
    }
    node->unk_28 = 0;
    node->unk_08 = size / 32;
    node->unk_00 = src;
    node->unk_04 = 0;
    node->unk_20 = 0;
    node->unk_24 = 0;
    node->unk_2C = node;
    cur = func_08000C8C(gSpriteWork + 0x1800);
    if (cur == 0) {
        node->unk_06 = *(u16*)(gSpriteWork + 0x1810);
        RequestDma3Copy(src, (void*)((node->unk_06 << 5) + 0x06010000), size);
        func_08000BC8(node->unk_0C, gSpriteWork + 0x1800);
        return node;
    }
    node->unk_06 = *(u16*)(gSpriteWork + 0x1810);
    avail = cur->unk_06 - *(u16*)(gSpriteWork + 0x1810);
    if (node->unk_08 <= (s16)avail) {
        RequestDma3Copy(src, (void*)((node->unk_06 << 5) + 0x06010000), size);
        func_08000C24(node->unk_0C, gSpriteWork + 0x1800, cur->unk_0C);
        return node;
    }
    for (;;) {
        if (cur == 0) {
            break;
        }
        next = func_08000CD4(cur->unk_0C);
        node->unk_06 = cur->unk_06 + cur->unk_08;
        if (node->unk_06 + node->unk_08 > *(u16*)(gSpriteWork + 0x1812)) {
            break;
        }
        if (next != 0) {
            end = next->unk_06 - node->unk_06;
        } else {
            end = *(u16*)(gSpriteWork + 0x1812) - node->unk_06;
        }
        if (node->unk_08 <= end) {
            RequestDma3Copy(src, (void*)((node->unk_06 << 5) + 0x06010000), size);
            func_08000BF4(node->unk_0C, gSpriteWork + 0x1800, cur->unk_0C);
            return node;
        }
        cur = next;
    }
    return 0;
}

void func_0800284C(u8* p) {
    if ((s16)*(u16*)(p + 4) > 0) {
        *(u16*)(p + 4) -= 1;
    } else {
        *(void**)(p + 0x2C) = 0;
        func_08000C54(p + 0x0C, gSpriteWork + 0x1800);
    }
}

void func_08002880(u8* p) {
    *(void**)(p + 0x2C) = 0;
    func_08000C54(p + 0x0C, gSpriteWork + 0x1800);
}

void func_080028A0(u8* p) {
    *(void**)(p + 0x2C) = 0;
    func_08000C54(p + 0x0C, gSpriteWork + 0x1800);
}

void ReleaseObjTiles(void* a) {
    u8* p = a;
    u8* q;

    if (p == 0) {
        return;
    }
    q = *(u8**)(p + 0x2C);
    if (q != p) {
        return;
    }
    switch (*(u32*)(q + 0x28)) {
    case 0:
        func_0800284C(q);
        break;
    case 1:
        func_08002880(q);
        break;
    case 2:
        func_080028A0(q);
        break;
    }
}

ObjTiles* AllocObjTiles(u16 size, void* owner) {
    ObjTiles* node;
    ObjTiles* cur;
    ObjTiles* next;
    s32 avail;
    s16 end;

    if (size == 0) {
        return 0;
    }
    node = func_08000D0C(gSpriteWork + 0x1800);
    if (node == 0) {
        return 0;
    }
    node->unk_28 = 1;
    node->unk_08 = size / 32;
    node->unk_00 = owner;
    node->unk_04 = 0;
    node->unk_20 = 0;
    node->unk_24 = 1;
    node->unk_2C = node;
    cur = func_08000C8C(gSpriteWork + 0x1800);
    if (cur == 0) {
        node->unk_06 = *(u16*)(gSpriteWork + 0x1810);
        func_08000BC8(node->unk_0C, gSpriteWork + 0x1800);
        return node;
    }
    node->unk_06 = *(u16*)(gSpriteWork + 0x1810);
    avail = cur->unk_06 - *(u16*)(gSpriteWork + 0x1810);
    if (node->unk_08 <= (s16)avail) {
        func_08000C24(node->unk_0C, gSpriteWork + 0x1800, cur->unk_0C);
        return node;
    }
    for (;;) {
        if (cur == 0) {
            break;
        }
        next = func_08000CD4(cur->unk_0C);
        node->unk_06 = cur->unk_06 + cur->unk_08;
        if (node->unk_06 + node->unk_08 > *(u16*)(gSpriteWork + 0x1812)) {
            break;
        }
        if (next != 0) {
            end = next->unk_06 - node->unk_06;
        } else {
            end = *(u16*)(gSpriteWork + 0x1812) - node->unk_06;
        }
        if (node->unk_08 <= end) {
            func_08000BF4(node->unk_0C, gSpriteWork + 0x1800, cur->unk_0C);
            return node;
        }
        cur = next;
    }
    return 0;
}

void func_08002A10(void* a, void* b) {
    *(void**)a = b;
}

INCLUDE_ASM("engine/LoadObjPalette.s");

void LoadObjPaletteBank(u16 bank, void* src) {
    LoadPalette(src, (void*)((bank << 5) + 0x05000200), 32);
}

void func_08002BCC(void* a) {
    u8* p = a;

    if ((s16)*(u16*)(p + 4) > 0) {
        *(u16*)(p + 4) -= 1;
    } else {
        *(u32*)(p + 0x24) = 0;
        func_08005C60(*(u16*)(p + 6) + 0x10);
        func_08000C54(p + 0x0C, gSpriteWork + 0x1A94);
    }
}

void ReleaseObjPalette(u8* p) {
    if (p != 0 && *(u8**)(p + 36) == p) {
        func_08002BCC(p);
    }
}

u8* func_08002C28(u8 a, u8 b) {
    u8* base;
    u8* e;
    s32 sin;
    s32 cos;

    if (*(u16*)(gSpriteWork + 0x2BAC) <= 0x1F && a != 0) {
        base = gSpriteWork;
        sin = gSineTable[a];
        cos = gSineTable[a + 0x40];
        e = base + 0x28AC + *(u16*)(base + 0x2BAC) * 24;
        *(u16*)(e + 0x00) = cos;
        *(u16*)(e + 0x02) = sin;
        *(u16*)(e + 0x04) = -sin;
        *(u16*)(e + 0x06) = cos;
        *(u16*)(e + 0x08) = *(u16*)(base + 0x2BAC);
        *(u8*)(e + 0x0A) = b;
        *(u32*)(e + 0x0C) = 0x100;
        *(u32*)(e + 0x10) = 0x100;
        *(u8*)(e + 0x14) = a;
        *(u16*)(gSpriteWork + 0x2BAC) += 1;
        return e;
    }
    return 0;
}
INCLUDE_ASM("engine/AllocObjAffine.s");
INCLUDE_ASM("engine/func_08002F50.s");

void func_080034D8(u8 a) {
    gSpriteWork[0x2BAF] = a;
}

void func_080034EC(u8 a, u8 b) {
    a &= 0xF;
    b &= 0xF;
    gMosaic = (gMosaic & 0xFF) | (a << 8) | (b << 12);
}

void func_08003510(u8 a) {
    gSpriteWork[0x2BAE] = a;
}

u16 func_08003524(u16** a, u16 n) {
    u16* p;
    u16 count;
    u16 sum;
    u16 max;
    u16 i;
    u16 j;

    max = 0;
    for (i = 0; i < n; i++) {
        p = a[i];
        count = p[0];
        p++;
        sum = 0;
        for (j = 0; j < count; j++) {
            sum += func_08001DB0(p[0], p[1]);
            p += 3;
        }
        if (max < sum) {
            max = sum;
        }
    }
    return max * 32;
}

u16 func_08003598(u16* p) {
    u16 count = *p++;
    u16 total = 0;
    u16 i;

    for (i = 0; i < count; i++) {
        total += func_08001DB0(p[0], p[1]);
        p += 3;
    }
    return (u16)(total << 5);
}

u8 func_080035CC(s16 x, u16 y, u16 a, u16 b, u16 c, s16 d) {
    if (x + d < 0) {
        return 1;
    }
    if (x - (s16)c > 0xF0) {
        return 1;
    }
    if ((s16)y + (s16)b < 0) {
        return 1;
    }
    if ((s16)y - (s16)a > 0xA0) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("engine/func_08003620.s");

void func_0800380C(ObjTiles* t, u16 slot, void* src, u16 size) {
    if (slot + (size >> 5) <= 0x400) {
        t->unk_28 = 0;
        t->unk_08 = size >> 5;
        t->unk_00 = src;
        t->unk_04 = 0;
        t->unk_20 = 0;
        t->unk_24 = 0;
        t->unk_06 = slot;
        RequestDma3Copy(src, (void*)((t->unk_06 << 5) + 0x06010000), size);
    }
}

void func_08003858(ObjTiles* t, u16 slot, u16 size, void* src) {
    if (slot + (size >> 5) <= 0x400) {
        t->unk_28 = 1;
        t->unk_08 = size >> 5;
        t->unk_00 = src;
        t->unk_04 = 0;
        t->unk_20 = 0;
        t->unk_24 = 1;
        t->unk_06 = slot;
    }
}

void func_0800388C(ObjTiles* t, u16 slot, void* src, u16 size) {
    if (slot + (size >> 5) <= 0x10) {
        t->unk_20 = 0;
        t->unk_08 = size >> 5;
        t->unk_00 = src;
        t->unk_04 = 0;
        t->unk_06 = slot;
        RequestDma3Copy(src, (void*)((t->unk_06 << 5) + 0x05000200), size);
    }
}

ObjTiles* func_080038C8(u16 a) {
    ObjTiles* t = AllocObjTiles(a, 0);

    if (t != 0) {
        t->unk_28 = 2;
    }
    return t;
}

u8 func_080038E4(ObjTiles* a, u16* b, void* c) {
    u16 count;
    s32 j;
    u16 acc;
    u16 n;

    if (b != 0 && c != 0 && a->unk_28 == 2) {
        if (a->unk_20 != (u32)b || a->unk_00 != c) {
            a->unk_00 = c;
            a->unk_20 = (u32)b;
            count = *b;
            b++;
            acc = 0;
            if (count != 0) {
                j = count;
                do {
                    n = func_08001DB0(b[0], b[1]);
                    RequestDma3Copy((u8*)a->unk_00 + ((b[2] & 0x3FF) << 5),
                                    (void*)(((a->unk_06 + acc) << 5) + 0x06010000), n * 32);
                    acc = acc + n;
                    b += 3;
                    j--;
                } while (j != 0);
            }
            return 1;
        }
    }
    return 0;
}
ObjTiles* func_08003970(u16 size) {
    ObjTiles* node;
    ObjTiles* cur;
    ObjTiles* next;
    s32 avail;
    s16 end;

    node = func_08000D0C(gSpriteWork + 0x1A94);
    if (node == 0) {
        return 0;
    }
    node->unk_20 = 2;
    node->unk_08 = size / 32;
    node->unk_00 = 0;
    node->unk_04 = 0;
    *(ObjTiles**)((u8*)node + 0x24) = node;
    cur = func_08000C8C(gSpriteWork + 0x1A94);
    if (cur == 0) {
        node->unk_06 = *(u16*)(gSpriteWork + 0x1AA4);
        func_08000BC8(node->unk_0C, gSpriteWork + 0x1A94);
        return node;
    }
    node->unk_06 = *(u16*)(gSpriteWork + 0x1AA4);
    avail = cur->unk_06 - *(u16*)(gSpriteWork + 0x1AA4);
    if (node->unk_08 <= (s16)avail) {
        func_08000C24(node->unk_0C, gSpriteWork + 0x1A94, cur->unk_0C);
        return node;
    }
    for (;;) {
        if (cur == 0) {
            break;
        }
        next = func_08000CD4(cur->unk_0C);
        node->unk_06 = cur->unk_06 + cur->unk_08;
        if (node->unk_06 + node->unk_08 > *(u16*)(gSpriteWork + 0x1AA6)) {
            break;
        }
        if (next != 0) {
            end = next->unk_06 - node->unk_06;
        } else {
            end = *(u16*)(gSpriteWork + 0x1AA6) - node->unk_06;
        }
        if (node->unk_08 <= end) {
            func_08000BF4(node->unk_0C, gSpriteWork + 0x1A94, cur->unk_0C);
            return node;
        }
        cur = next;
    }
    return 0;
}

void func_08003A70(ObjTiles* t, void* src) {
    if (t->unk_20 == 2) {
        LoadPalette(src, (void*)((t->unk_06 << 5) + 0x05000200), (u16)(t->unk_08 << 5));
    }
}

u8 func_08003A98(u16 n) {
    ObjTiles* cur;
    ObjTiles* next;
    u16 pos;
    s16 end;

    cur = func_08000C8C(gSpriteWork + 0x1800);
    if (cur == 0) {
        return 1;
    }
    pos = *(u16*)(gSpriteWork + 0x1810);
    if (n <= (s16)(cur->unk_06 - pos)) {
        return 1;
    }
    for (;;) {
        if (cur == 0) {
            break;
        }
        next = func_08000CD4(cur->unk_0C);
        pos = cur->unk_06 + cur->unk_08;
        if ((s16)pos + n > *(u16*)(gSpriteWork + 0x1812)) {
            break;
        }
        if (next != 0) {
            end = next->unk_06 - pos;
        } else {
            end = *(u16*)(gSpriteWork + 0x1812) - pos;
        }
        if (n <= end) {
            return 1;
        }
        cur = next;
    }
    return 0;
}
u8 func_08003B24(u16 n) {
    ObjTiles* cur;
    ObjTiles* next;
    u16 pos;
    s16 end;

    cur = func_08000C8C(gSpriteWork + 0x1A94);
    if (cur == 0) {
        return 1;
    }
    pos = *(u16*)(gSpriteWork + 0x1AA4);
    if (n <= (s16)(cur->unk_06 - pos)) {
        return 1;
    }
    for (;;) {
        if (cur == 0) {
            break;
        }
        next = func_08000CD4(cur->unk_0C);
        pos = cur->unk_06 + cur->unk_08;
        if ((s16)pos + n > *(u16*)(gSpriteWork + 0x1AA6)) {
            break;
        }
        if (next != 0) {
            end = next->unk_06 - pos;
        } else {
            end = *(u16*)(gSpriteWork + 0x1AA6) - pos;
        }
        if (n <= end) {
            return 1;
        }
        cur = next;
    }
    return 0;
}
INCLUDE_ASM("engine/func_08003BB0.s");

s32 func_08003C9C(s32 a) {
    s32 x;
    s32 prev;

    if (a > 0) {
        x = 0x100;
        if (a > 0x100) {
            x = a;
        }
        do {
            prev = x;
            x = ((a << 8) / prev + prev) / 2;
        } while (x < prev);
        return prev;
    }
    return 0;
}

INCLUDE_ASM("engine/func_08003CD4.s");
s32 func_08003E2C(s16* n, s32 v, s32* a, s32* c, s32* b) {
    s32 lo;
    s32 hi;
    s32 mid;
    s32 dx;
    s32 t;
    s32 y0;
    s32 y1;
    s32 r;
    s32 cnt;

    cnt = *n;
    lo = 0;
    hi = cnt - 1;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (a[mid] < v) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    if (lo > 0) {
        lo--;
    }
    dx = a[lo + 1] - a[lo];
    t = v - a[lo];
    y1 = b[lo + 1];
    y0 = b[lo];
    r = (((t * (y1 - y0)) >> 8) << 8) / dx;
    r = (t * (r + y0 * 3)) >> 8;
    r += ((c[lo + 1] - c[lo]) << 8) / dx - ((dx * (y0 * 2 + y1)) >> 8);
    return ((t * r) >> 8) + c[lo];
}
INCLUDE_ASM("engine/func_08003ED4.s");
void InitDisplayRegs(void) {
    gDispCnt = 0x40;
    gMosaic = 0;
    gBldCnt = 0;
    gBldAlpha = 0;
    gBldY = 0;
    gWin0H = 0;
    gWin1H = 0;
    gWin0V = 0;
    gWin1V = 0;
    gWinIn = 0;
    gWinOut = 0;
    gBg0Cnt = 0;
    gBg1Cnt = 0;
    gBg2Cnt = 0;
    gBg3Cnt = 0;
    gBg0HOfs = 0;
    gBg0VOfs = 0;
    gBg1HOfs = 0;
    gBg1VOfs = 0;
    gBg2HOfs = 0;
    gBg2VOfs = 0;
    gBg3HOfs = 0;
    gBg3VOfs = 0;
    gBg2PA = 0x100;
    gBg2PB = 0;
    gBg2PC = 0;
    gBg2PD = 0x100;
    gBg2X = 0;
    gBg2Y = 0;
    gBg3PA = 0x100;
    gBg3PB = 0;
    gBg3PC = 0;
    gBg3PD = 0x100;
    gBg3X = 0;
    gBg3Y = 0;
}
void CommitDisplayRegs(void) {
    *(vu16*)0x0400004c = gMosaic;
    *(vu16*)0x04000050 = gBldCnt;
    *(vu16*)0x04000052 = gBldAlpha;
    *(vu16*)0x04000054 = gBldY;
    *(vu16*)0x04000040 = gWin0H;
    *(vu16*)0x04000042 = gWin1H;
    *(vu16*)0x04000044 = gWin0V;
    *(vu16*)0x04000046 = gWin1V;
    *(vu16*)0x04000048 = gWinIn;
    *(vu16*)0x0400004a = gWinOut;
    *(vu16*)0x04000008 = gBg0Cnt;
    *(vu16*)0x0400000a = gBg1Cnt;
    *(vu16*)0x0400000c = gBg2Cnt;
    *(vu16*)0x0400000e = gBg3Cnt;
    *(vu16*)0x04000010 = gBg0HOfs;
    *(vu16*)0x04000012 = gBg0VOfs;
    *(vu16*)0x04000014 = gBg1HOfs;
    *(vu16*)0x04000016 = gBg1VOfs;
    *(vu16*)0x04000018 = gBg2HOfs;
    *(vu16*)0x0400001a = gBg2VOfs;
    *(vu16*)0x0400001c = gBg3HOfs;
    *(vu16*)0x0400001e = gBg3VOfs;
    *(vu16*)0x04000020 = gBg2PA;
    *(vu16*)0x04000022 = gBg2PB;
    *(vu16*)0x04000024 = gBg2PC;
    *(vu16*)0x04000026 = gBg2PD;
    *(vu32*)0x04000028 = gBg2X;
    *(vu32*)0x0400002c = gBg2Y;
    *(vu16*)0x04000030 = gBg3PA;
    *(vu16*)0x04000032 = gBg3PB;
    *(vu16*)0x04000034 = gBg3PC;
    *(vu16*)0x04000036 = gBg3PD;
    *(vu32*)0x04000038 = gBg3X;
    *(vu32*)0x0400003c = gBg3Y;
    *(vu16*)0x04000000 = gDispCnt;
    *(vu16*)0x05000000 = gBackdropColor;
}

void func_08004314(void) {
    u32 zero;

    SetIwramHeapName(gUnk_08121680);
    gDma3Requests = IwramAlloc(0x10B0);
    zero = 0;
    CpuSet(&zero, gDma3Requests, 0x0500042C);
}

void func_08004350(void) {
    IwramFree(gDma3Requests);
}

void func_08004364(void) {
    Dma3Queue* q = (Dma3Queue*)gDma3Requests;

    q->unk_10A0 = 0;
    q->unk_10A2 = 0;
    q->unk_10A4 = 0;
    q->unk_10A6 = 0;
    q->count = 0;
    q->unk_10AC = 0;
}

u8 RequestDma3Copy(void* src, void* dst, u16 size) {
    Dma3Queue* q;
    vu32* dma;

    if (size == 0) {
        return 0;
    }
    q = (Dma3Queue*)gDma3Requests;
    if (q->unk_10A0 > 255) {
        return 0;
    }
    if ((gUnk_03006C78 & 8) == 0) {
        q->requests[q->unk_10A0].src = src;
        q->requests[q->unk_10A0].dst = dst;
        q->requests[q->unk_10A0].size = size;
        q->unk_10A0 = q->unk_10A0 + 1;
    } else {
        dma = (vu32*)0x040000D4;
        dma[0] = (u32)src;
        dma[1] = (u32)dst;
        dma[2] = 0x80000000 | (size / 2);
        dma[2];
    }
    return 1;
}

u8 func_0800443C(void* a, u16 b) {
    Dma3Queue* q = (Dma3Queue*)gDma3Requests;

    if (q->count > 3) {
        return 0;
    }
    q->pending[q->count].unk_00 = a;
    q->pending[q->count].unk_04 = b;
    q->count = q->count + 1;

    return 1;
}
INCLUDE_ASM("engine/func_0800448C.s");
#ifdef NON_MATCHING
u8 func_080045AC(void* a, void* b, u8 c, u8 d, u8 e) {
    if (*(u16*)(gUnk_03007574 + 0x10A4) > 7) {
        return 0;
    }
    *(void**)(gUnk_03007574 + 0x1000 + *(u16*)(gUnk_03007574 + 0x10A4) * 12) = a;
    *(void**)(gUnk_03007574 + 0x1004 + *(u16*)(gUnk_03007574 + 0x10A4) * 12) = b;
    *(u8*)(gUnk_03007574 + 0x1008 + *(u16*)(gUnk_03007574 + 0x10A4) * 12) = c & 0x1F;
    *(u8*)(gUnk_03007574 + 0x1009 + *(u16*)(gUnk_03007574 + 0x10A4) * 12) = d & 0x1F;
    *(u8*)(gUnk_03007574 + 0x100A + *(u16*)(gUnk_03007574 + 0x10A4) * 12) = e;
    *(u16*)(gUnk_03007574 + 0x10A4) += 1;
    return 1;
}
#else
INCLUDE_ASM("engine/func_080045AC.s");
#endif
INCLUDE_ASM("engine/func_08004678.s");
INCLUDE_ASM("engine/func_080046C8.s");
INCLUDE_ASM("engine/func_08004938.s");

void func_08004B8C(void) {
    BgEntry** p;
    u32 zero;

    SetIwramHeapName(gUnk_08121688);
    p = &gUnk_030074D4;
    *p = IwramAlloc(0x40);
    zero = 0;
    CpuSet(&zero, *p, 0x05000010);
}

void func_08004BC4(void) {
    IwramFree(gUnk_030074D4);
}

void* func_08004BD8(BgEntry* e, u16 x, u16 y) {
    u8 col = (x >> 8) % e->unk_08;
    u8 row = (y >> 8) % e->unk_09;

    return ((void**)e->unk_04)[e->unk_08 * row + col];
}

INCLUDE_ASM("engine/func_08004C20.s");

void func_08004D74(void) {
    gBackdropColor = 0;
    DisableBg(0);
    DisableBg(1);
    DisableBg(2);
    DisableBg(3);
    func_080054C8(0, 0);
    gBldCnt = 0;
}

void func_08004DB0(void) {
    s32 i;

    gDispCnt = gDispCnt & 0xFFF8;
    gBg0Cnt = 0;
    gBg1Cnt = 1;
    gBg2Cnt = 2;
    gBg3Cnt = 3;
    SetupBg(0, 0, 7, 0);
    SetupBg(1, 1, 15, 4);
    SetupBg(2, 2, 23, 8);
    SetupBg(3, 3, 31, 12);
    SetBgScroll(0, 0, 0);
    SetBgScroll(1, 0, 0);
    SetBgScroll(2, 0, 0);
    SetBgScroll(3, 0, 0);
    for (i = 0; i <= 3; i++) {
        u8* p = (u8*)gUnk_030074D4;
        s32 o = i * 16;
        p += 4;
        p += o;
        *(void**)p = 0;
    }
}
void func_08004E64(void) {
    s32 i;

    gDispCnt = (gDispCnt & 0xFFF8) | 1;
    gBg0Cnt = 0;
    gBg1Cnt = 1;
    gBg2Cnt = 0x82;
    SetupBg(0, 0, 7, 0);
    SetupBg(1, 1, 15, 0);
    SetupBg(2, 2, 23, 0);
    SetBgScroll(0, 0, 0);
    SetBgScroll(1, 0, 0);
    func_08005690(2, 0, 0x100, 0x100, 0, 0);
    for (i = 0; i <= 3; i++) {
        u8* p = (u8*)gUnk_030074D4;
        s32 o = i * 16;
        p += 4;
        p += o;
        *(void**)p = 0;
    }
}
void func_08004F08(void) {
    s32 i;

    gDispCnt = (gDispCnt & 0xFFF8) | 2;
    gBg2Cnt = 0x6080;
    gBg3Cnt = 0x4081;
    SetupBg(2, 0, 15, 0);
    SetupBg(3, 2, 31, 0);
    func_08005690(2, 0, 0x100, 0x100, 0, 0);
    func_08005690(3, 0, 0x100, 0x100, 0, 0);
    for (i = 0; i <= 3; i++) {
        u8* p = (u8*)gUnk_030074D4;
        s32 o = i * 16;
        p += 4;
        p += o;
        *(void**)p = 0;
    }
}
void func_08004FA0(void) {
    gDispCnt = (gDispCnt & 0xFFF8) | 3;
    SetBgScroll(2, 0, 0);
}

void EnableBg(s32 bg) {
    switch ((u32)bg) {
    case 0:
        gDispCnt |= 0x100;
        break;
    case 1:
        gDispCnt |= 0x200;
        break;
    case 2:
        gDispCnt |= 0x400;
        break;
    case 3:
        gDispCnt |= 0x800;
        break;
    }
}

void DisableBg(s32 bg) {
    switch ((u32)bg) {
    case 0:
        gDispCnt &= 0xFEFF;
        break;
    case 1:
        gDispCnt &= 0xFDFF;
        break;
    case 2:
        gDispCnt &= 0xFBFF;
        break;
    case 3:
        gDispCnt &= 0xF7FF;
        break;
    }
}

void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette) {
    vu16* p = gBgControl[bg];

    *p = (*p & 0xFFF3) | (charBase << 2);
    *p = (*p & 0xE0FF) | (screenBase << 8);
    gBgPaletteBank[bg] = palette;
}

void LoadBgTiles(s32 bg, void* src, u16 size) {
    EnableBg(bg);
    RequestDma3Copy(src, GetBgCharBase(bg), size);
}

void LoadBgPalette(s32 bg, void* src, u16 size) {
    EnableBg(bg);
    LoadPalette(src, (void*)((gBgPaletteBank[bg] << 5) + 0x05000000), size);
}

void LoadBgMap(s32 bg, void* src, u16 size) {
    EnableBg(bg);
    RequestDma3Copy(src, GetBgScreenBase(bg), size);
}

void* GetBgCharBase(s32 bg) {
    return (void*)(((*gBgControl[bg] & 0x0C) << 12) + 0x06000000);
}

void* GetBgScreenBase(s32 bg) {
    return (void*)(((*gBgControl[bg] & 0x1F00) << 3) + 0x06000000);
}

#ifdef NON_MATCHING
void func_0800516C(s32 bg, void* src, u8 w, u8 h) {
    if (gDispCnt & 7) {
        if (bg == 2 || bg == 3) {
            return;
        }
    }
    EnableBg(bg);
    gUnk_030074D4[bg].unk_04 = src;
    gUnk_030074D4[bg].unk_08 = w;
    gUnk_030074D4[bg].unk_09 = h;
    gUnk_030074D4[bg].unk_0A = 0;
    gUnk_030074D4[bg].unk_0C = 0;
    gUnk_030074D4[bg].unk_00 = 1;
}
#else
INCLUDE_ASM("engine/func_0800516C.s");
#endif
void func_080051C4(s32 bg, u16 x, u16 y) {
    BgEntry* e = &gUnk_030074D4[bg];

    if (e->unk_04 == 0) {
        return;
    }
    e->unk_0A = x;
    e->unk_0C = y;
    func_08004C20(x, y, e, (void*)(((*gBgControl[bg] & 0x1F00) << 3) + 0x06000000), 0, 0, 0x1F, 0x15);
    SetBgScroll(bg, x & 7, y & 7);
    e->unk_00 = 0;
}
INCLUDE_ASM("engine/func_08005244.s");

void SetBgMosaic(s32 bg, u8 on) {
    if (on) {
        *gBgControl[bg] |= 0x40;
    } else {
        *gBgControl[bg] &= 0xFFBF;
    }
}

void func_080054C8(u8 a, u8 b) {
    a &= 0xF;
    b &= 0xF;
    gMosaic = (gMosaic & 0xFF00) | a | (b << 4);
}

void SetBgScroll(s32 bg, s32 x, s32 y) {
    x &= 0x1FF;
    y &= 0x1FF;
    switch ((u32)bg) {
    case 0:
        gBg0HOfs = x;
        gBg0VOfs = y;
        break;
    case 1:
        gBg1HOfs = x;
        gBg1VOfs = y;
        break;
    case 2:
        gBg2HOfs = x;
        gBg2VOfs = y;
        break;
    case 3:
        gBg3HOfs = x;
        gBg3VOfs = y;
        break;
    }
}

u8 GetBgScrollX(u32 a) {
    u16 v;

    switch (a) {
    case 0:
        v = gBg0HOfs;
        break;
    case 1:
        v = gBg1HOfs;
        break;
    case 2:
        v = gBg2HOfs;
        break;
    case 3:
        v = gBg3HOfs;
        break;
    default:
        return 0;
    }
    return v;
}

u8 GetBgScrollY(u32 a) {
    u16 v;

    switch (a) {
    case 0:
        v = gBg0VOfs;
        break;
    case 1:
        v = gBg1VOfs;
        break;
    case 2:
        v = gBg2VOfs;
        break;
    case 3:
        v = gBg3VOfs;
        break;
    default:
        return 0;
    }
    return v;
}

void SetBgPriority(s32 bg, u16 priority) {
    vu16* p = gBgControl[bg];

    *p &= 0xFFFC;
    *p |= priority;
}

void SetBgSize(s32 bg, u16 v) {
    vu16* p = gBgControl[bg];

    *p &= 0x3FFF;
    *p |= v;
}

void SetBgColorMode(s32 bg, u16 v) {
    if (v == 0x80) {
        vu16* p = gBgControl[bg];

        *p &= 0xFFFF;
        *p |= 0x80;
    } else {
        vu16* p = gBgControl[bg];

        *p &= 0xFF7F;
        *p |= 0;
    }
}

void SetBgOverflow(s32 bg, u8 on) {
    if (on) {
        *gBgControl[bg] |= 0x2000;
    } else {
        *gBgControl[bg] &= 0xDFFF;
    }
}

void func_08005690(s32 bg, u8 rot, s32 sx, s32 sy, s32 dx, s32 dy) {
    BgAffineSrcData src;
    BgAffineDstData dst;

    src.texX = 0;
    src.texY = 0;
    src.scrX = 0x78;
    src.scrY = 0x50;
    src.sx = 0x10000 / sx;
    src.sy = 0x10000 / sy;
    src.alpha = -rot << 8;
    BgAffineSet(&src, &dst, 1);
    switch (bg) {
    case 2:
        gBg2PA = dst.pa;
        gBg2PB = dst.pb;
        gBg2PC = dst.pc;
        gBg2PD = dst.pd;
        gBg2X = dst.dx + dx;
        gBg2Y = dst.dy + dy;
        break;
    case 3:
        gBg3PA = dst.pa;
        gBg3PB = dst.pb;
        gBg3PC = dst.pc;
        gBg3PD = dst.pd;
        gBg3X = dst.dx + dx;
        gBg3Y = dst.dy + dy;
        break;
    }
}

void func_08005778(u8 r, u8 g, u8 b) {
    g &= 0x1F;
    b &= 0x1F;
    gUnk_030074CC = (b << 10) | (g << 5) | (r & 0x1F);
    gBackdropColor = gUnk_030074CC;
}

void SetBgBlend(s32 a, u16 b, u16 c) {
    switch ((u32)a) {
    case 0:
        gBldCnt = 0x1E01;
        break;
    case 1:
        gBldCnt = 0x1D02;
        break;
    case 2:
        gBldCnt = 0x1B04;
        break;
    default:
        gBldCnt = 0x1708;
        break;
    }
    gBldCnt |= 0x40;
    gBldAlpha = (b << 8) | c;
}

void SetBlendAlpha(u16 a, u16 b) {
    gBldAlpha = (a << 8) | b;
}

#ifdef NON_MATCHING
s32 func_08005824(s32 a, s32 b) {
    s32 x = a & 0xFF;
    s32 y = b & 0xFF;
    s32 d = x - y;

    if (d <= -0x80) {
        return d + 0x100;
    }
    if (d > 0x7F) {
        return (x - 0x100) - y;
    }
    return d;
}
#else
INCLUDE_ASM("engine/func_08005824.s");
#endif
INCLUDE_ASM("engine/func_0800585C.s");

void func_0800589C(u16* p, u16 target, u16 shift) {
    s16 d;
    u16 v;

    if (*p == target) {
        return;
    }
    d = func_08005824((s16)target, (s16)*p);
    if (d == 0) {
        return;
    }
    v = d >> shift;
    *p = v + *p;
}

void func_080058D4(u16* p, u16 target, u16 shift) {
    s32 d = func_0800585C(target, *p);

    if (d != 0) {
        *p = (d >> shift) + *p;
    }
}

void func_080058FC(s32* value, s32 target, u16 steps) {
    s32 cur;
    s32 delta;

    cur = *value;
    delta = target - cur;

    if (steps == 0) {
        steps = 1;
    }

    *value = cur + delta / steps;
}

s32 func_08005920(u16 a) {
    a >>= 1;
    if (a == 0) {
        a = 1;
    }
    return a;
}

void func_0800592C(s32* p, s32 target, u16 steps) {
    s32 d = target - *p;

    *p += d / func_08005920(steps);
}

s32 func_08005954(s32 a, s32 b, s32 t) {
    return (a * (0x100 - t) >> 8) + (b * t >> 8);
}

void AnimInit(AnimState* a, s32 b, s32 c) {
    a->gfxTable = (u32*)c;
    a->anims = (AnimHeader**)b;
    a->frames = 0;
}

void func_08005974(AnimState* a, u16 animId, u16 flags, s32 b, s32 c) {
    if (a->gfxTable != (u32*)c || a->anims != (AnimHeader**)b || a->animId != animId) {
        a->gfxTable = (u32*)c;
        a->anims = (AnimHeader**)b;
        AnimStart(a, animId, flags);
    }
}

void AnimStart(AnimState* a, u16 animId, u16 flags) {
    AnimHeader* h = a->anims[animId];

    a->frameCount = h->frameCount;
    if (a->frameCount == 0) {
        a->frames = 0;
        return;
    }
    a->frames = (AnimFrame*)&h->unk_06;
    if ((flags & 4) == 0) {
        a->timer = 0;
        if (flags & 2) {
            a->frame = GetRandom() % a->frameCount;
        } else {
            a->frame = 0;
        }
    }
    a->flags = flags;
    a->animId = animId;
}

void AnimChange(AnimState* a, u16 id, u16 flags) {
    AnimHeader* h;

    if (a->animId == id) {
        return;
    }
    h = a->anims[id];
    a->frameCount = h->frameCount;
    if (a->frameCount == 0) {
        a->frames = 0;
        return;
    }
    a->frames = (AnimFrame*)&h->unk_06;
    if ((flags & 4) == 0) {
        a->timer = 0;
        if (flags & 2) {
            a->frame = GetRandom() % a->frameCount;
        } else {
            a->frame = 0;
        }
    }
    a->flags = flags;
    a->animId = id;
}

#ifdef NON_MATCHING
void* AnimUpdate(AnimState* a) {
    void* gfx = AnimGetGfx(a);
    AnimFrame* frames = a->frames;
    u16 index;

    if (frames == 0) {
        return 0;
    }
    a->timer++;
    index = a->frame;
    if (a->timer < frames[index].duration) {
        return gfx;
    }
    a->frame = index + 1;
    a->timer = 0;
    if (a->frame < a->frameCount) {
        return gfx;
    }
    if (a->flags & 1) {
        a->frame = 0;
    } else {
        a->frame = index;
    }
    a->flags |= 0x1000;
    return gfx;
}
#else
INCLUDE_ASM("engine/AnimUpdate.s");
#endif

u8 func_08005AC4(AnimState* a) {
    if (a->frames == 0) {
        return 0;
    }
    if (!(a->flags & 1)) {
        if (a->flags & 0x1000) {
            return 0;
        }
    }
    if (a->timer + 1 >= a->frames[a->frame].duration) {
        return 1;
    }

    return 0;
}

void* AnimGetGfx(AnimState* a) {
    void* result;

    if (a->frames != 0) {
        result = (void*)a->gfxTable[a->frames[a->frame].gfxIndex];
    } else {
        result = 0;
    }

    return result;
}

u8 AnimIsFinished(AnimState* a) {
    if (a->flags & 0x1000) {
        return 1;
    }

    return 0;
}

u16 func_08005B30(AnimState* a) {
    return a->animId;
}

u16 func_08005B34(AnimState* a) {
    return a->frame;
}

u16 func_08005B38(AnimState* a) {
    return a->frames[a->frame].gfxIndex;
}

void func_08005B44(AnimState* a, u16 frame) {
    if (frame < a->frameCount) {
        a->frame = frame;
        a->timer = 0;
        a->flags &= 0xEFFF;
    }
}

void func_08005B64(AnimState* a) {
    a->frame = 0;
    a->timer = 0;
    a->flags &= 0xEFFF;
}

void func_08005B78(void) {
    u32 zero;

    SetIwramHeapName(gUnk_0812168C);
    gUnk_03007568 = IwramAlloc(0x598);
    zero = 0;
    CpuSet(&zero, gUnk_03007568, 0x05000166);
}

void func_08005BB0(void) {
    IwramFree(gUnk_03007568);
}

void func_08005BC4(void) {
    u32 zero = 0;

    CpuSet(&zero, gUnk_03007568, 0x05000166);
}

#ifdef NON_MATCHING
void LoadPalette(void* src, void* dst, s32 size) {
    u8* base;
    u8* flag;
    PaletteSlot* e;
    s32 idx;
    s32 count;
    void* p;

    base = gUnk_03007568;
    count = (u16)size / 32;
    idx = ((s32)dst - 0x05000000) / 32;
    p = func_08007E00(src, dst, size);
    if (count != 0) {
        e = (PaletteSlot*)(base + idx * 44);
        flag = base + idx * 44 + 0x29;
        do {
            e->unk_00 = p;
            e->unk_04 = dst;
            *flag = 1;
            flag += 44;
            dst = (u8*)dst + 32;
            e++;
            p = (u8*)p + 32;
            count--;
        } while (count != 0);
    }
}
#else
INCLUDE_ASM("engine/LoadPalette.s");
#endif

void func_08005C60(u16 a) {
    PaletteSlot* p = (PaletteSlot*)gUnk_03007568;

    p += a;
    p->unk_00 = 0;
}

INCLUDE_ASM("engine/func_08005C78.s");
void func_08006120(s32 a, u16 b) {
    u8* base = gUnk_03007568;
    u32 z;

    if (*(u16*)(base + 0x594) & 2) {
        if (*(u16*)(base + 0x594) & 1) {
            return;
        }
    }
    z = 0;
    *(u16*)(base + 0x594) = 1;
    *(u16*)(base + 0x58C) = b;
    *(u32*)(base + 0x580) = 0x1F00;
    *(u32*)(base + 0x584) = z;
    *(u32*)(base + 0x588) = z;
    *(u32*)(base + 0x590) = a;
}
void func_08006184(s32 a, u16 b) {
    u8* base = gUnk_03007568;
    u32 z;

    if (*(u16*)(base + 0x594) & 2) {
        if (*(u16*)(base + 0x594) & 1) {
            return;
        }
    }
    z = 0;
    *(u16*)(base + 0x594) = 1;
    *(u16*)(base + 0x58C) = b;
    *(u32*)(base + 0x580) = z;
    *(u32*)(base + 0x584) = 0x1F00;
    *(u32*)(base + 0x588) = z;
    *(u32*)(base + 0x590) = a;
}
void func_080061E8(s32 a, u16 b) {
    u8* base = gUnk_03007568;
    u32 z;

    if (*(u16*)(base + 0x594) & 2) {
        if (*(u16*)(base + 0x594) & 1) {
            return;
        }
    }
    z = 0;
    *(u16*)(base + 0x594) = 1;
    *(u16*)(base + 0x58C) = b;
    *(u32*)(base + 0x584) = z;
    *(u32*)(base + 0x590) = a;
}

void func_08006238(s32 a, u16 b, u16 c) {
    u8* base = gUnk_03007568;

    if (*(u16*)(base + 0x594) & 2) {
        if (*(u16*)(base + 0x594) & 1) {
            return;
        }
    }
    *(u16*)(base + 0x594) = 1;
    *(u16*)(base + 0x58C) = c;
    *(u32*)(base + 0x584) = b << 8;
    *(u32*)(base + 0x590) = a;
}

void func_08006290(s32 a, u16 b, u16 c) {
    u8* base = gUnk_03007568;
    u32 z;

    if (*(u16*)(base + 0x594) & 2) {
        if (*(u16*)(base + 0x594) & 1) {
            return;
        }
    }
    z = 0;
    *(u16*)(base + 0x594) = 1;
    *(u16*)(base + 0x58C) = c;
    *(u32*)(base + 0x580) = b << 8;
    *(u32*)(base + 0x588) = z;
    *(u32*)(base + 0x584) = z;
    *(u32*)(base + 0x590) = a;
}

void func_080062F4(u16 slot, u8 value) {
    PaletteSlot* p;

    if (slot > 0x1F) {
        return;
    }
    p = (PaletteSlot*)gUnk_03007568;
    p += slot;
    p->unk_28 = value;
}

u8 func_08006314(void) {
    if (*(u16*)(gUnk_03007568 + 0x594) & 1) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("engine/_08006338.s");

u16 func_08006390(void) {
    return *(u32*)(gUnk_03007568 + 0x580) >> 8;
}

void func_080063A8(void) {
    u16 v = *(u16*)(gUnk_03007568 + 0x594) | 2;

    *(u16*)(gUnk_03007568 + 0x594) = v;
}

void func_080063C4(u8 on) {
    if (on) {
        u16 v = *(u16*)(gUnk_03007568 + 0x594) | 4;

        *(u16*)(gUnk_03007568 + 0x594) = v;
    } else {
        *(u16*)(gUnk_03007568 + 0x594) &= 0xFFFB;
    }
}

void func_08006404(void) {
    gUnk_0203401C = 0;
    gUnk_02034020 = 0;
    gUnk_02034024 = 0;
    gUnk_02034026 = 0;
}

INCLUDE_ASM("engine/func_0800642C.s");

void func_08006494(u16 a, u16 b) {
    gUnk_02034024 = a;
    gUnk_0203401C = b << 8;
    gUnk_02034020 = 0;
    gUnk_02034026 = 1;
    SetBgMosaic(0, 1);
    SetBgMosaic(1, 1);
    SetBgMosaic(2, 1);
    SetBgMosaic(3, 1);
    func_080034D8(1);
}

void func_080064E8(u16 a, u16 b) {
    gUnk_02034024 = a;
    gUnk_0203401C = 0;
    gUnk_02034020 = b << 8;
    gUnk_02034026 = 1;
    SetBgMosaic(0, 1);
    SetBgMosaic(1, 1);
    SetBgMosaic(2, 1);
    SetBgMosaic(3, 1);
    func_080034D8(1);
}

u8 func_0800653C(void) {
    return gUnk_02034026;
}

void SeedRand(u32 seed) {
    gRandSeed = seed;
}

u32 Rand(void) {
    gRandSeed = (gRandSeed * 0x41C64E6D + 12345) & 0x7FFF;
    return gRandSeed;
}

void SeedRandom(u32 seed) {
    SeedRand(seed);
    gRandomState[0] = Rand();
    gRandomState[1] = Rand();
    gRandomState[2] = Rand();
    gRandomState[3] = Rand();
}

u16 GetRandom(void) {
    u32 x;

    x = gRandomState[1];
    x <<= 1;
    if (gRandomState[0] & 0x80000000) {
        x++;
    }
    x <<= 1;
    if (gRandomState[0] & 0x40000000) {
        x++;
    }
    gRandomState[3] <<= 1;
    if (gRandomState[2] & 0x80000000) {
        gRandomState[3]++;
    }
    x ^= gRandomState[3];
    gRandomState[3] = gRandomState[2];
    gRandomState[2] = gRandomState[1];
    gRandomState[1] = gRandomState[0];
    gRandomState[0] = x;
    x &= 0x7FFF;
    return x;
}

void func_080065FC(s32 bg, u16 b, u16 c) {
    gUnk_02034048 = bg;
    gUnk_02034040 = 0;
    gUnk_02034050 = 0;
    gUnk_02034052 = 0;
    gUnk_02034054 = 1;
    if (c == 0) {
        gUnk_02034058 = 0;
        switch (b) {
        case 0x4000:
        case 0x8000:
            gUnk_02034056 = 0x1000;
            break;
        case 0xC000:
            gUnk_02034056 = 0x2000;
            break;
        case 0:
        default:
            gUnk_02034056 = 0x800;
            break;
        }
    } else {
        gUnk_02034058 = 1;
        switch (b) {
        case 0x4000:
            gUnk_02034056 = 0x400;
            break;
        case 0x8000:
            gUnk_02034056 = 0x1000;
            break;
        case 0xC000:
            gUnk_02034056 = 0x4000;
            break;
        case 0:
        default:
            gUnk_02034056 = 0x100;
            break;
        }
    }
    SetBgSize(bg, b);
    DisableBg(bg);
}
void func_080066F4(s16 x, s16 y) {
    if (gUnk_02034058 != 0) {
        gUnk_02034050 = -x;
        gUnk_02034052 = -y;
    } else {
        gUnk_02034050 = (*(u16*)(gUnk_02034040 + 0x10) << 2) - x;
        gUnk_02034052 = (*(u16*)(gUnk_02034040 + 0x12) << 2) - y;
    }
}

void func_0800675C(u8 a, s32 b, s32 c) {
    gUnk_02034064 = a;
    gUnk_0203405C = b;
    gUnk_02034060 = c;
}

void func_08006778(u8* a, s32 x, s32 y) {
    gUnk_02034040 = a;
    func_080066F4((s16)x, (s16)y);
    if (gUnk_02034058 != 0) {
        gUnk_0203404C = *(u16*)(a + 0x0E) << 6;
    } else {
        gUnk_0203404C = *(u16*)(a + 0x0E) << 5;
    }
    gUnk_0203404E = 0x8000 / gUnk_0203404C;
    gUnk_02034066 = -1;
    gUnk_02034068 = -1;
    gUnk_02034044 = 0;
    gUnk_02034046 = 0;
    gUnk_02034054 = 0;
    gUnk_0203406A = *(u16*)(a + 0x16);
    if (gUnk_02034058 != 0) {
        gUnk_0203405C = 0x100;
        gUnk_02034060 = 0x100;
        gUnk_02034064 = 0;
    }
    func_08007E68(0);
    LoadBgPalette(gUnk_02034048, *(void**)(a + 0x08), *(u16*)(a + 0x0C));
    func_08007E7C();
    LoadBgMap(gUnk_02034048, *(void**)(a + 0x04), gUnk_02034056);
}
void func_0800685C(s32 bg, u8 rot, s32 sx, s32 sy, s16 cx, s16 cy) {
    BgAffineSrcData src;
    BgAffineDstData dst;

    src.texX = *(u16*)(gUnk_02034040 + 0x10) << 10;
    src.texY = *(u16*)(gUnk_02034040 + 0x12) << 10;
    src.scrX = -cx;
    src.scrY = -cy;
    src.sx = 0x10000 / sx;
    src.sy = 0x10000 / sy;
    src.alpha = -rot << 8;
    BgAffineSet(&src, &dst, 1);
    switch (bg) {
    case 2:
        gBg2PA = dst.pa;
        gBg2PB = dst.pb;
        gBg2PC = dst.pc;
        gBg2PD = dst.pd;
        gBg2X = dst.dx;
        gBg2Y = dst.dy;
        break;
    case 3:
        gBg3PA = dst.pa;
        gBg3PB = dst.pb;
        gBg3PC = dst.pc;
        gBg3PD = dst.pd;
        gBg3X = dst.dx;
        gBg3Y = dst.dy;
        break;
    }
}
INCLUDE_ASM("engine/func_08006954.s");

void func_08006B34(u16 a) {
    gUnk_02034066 = a;
}

void func_08006B40(u16 a) {
    gUnk_02034068 = a;
}

void func_08006B4C(void) {
    gUnk_02034040 = 0;
    gUnk_02034054 = 1;
    DisableBg(gUnk_02034048);
}
