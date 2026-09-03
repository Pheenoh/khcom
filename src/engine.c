#include "macros.h"
#include "gba/syscall.h"
#include "malloc.h"
#include "engine.h"
#include "types.h"

u32 gUnk_0203401C;
u32 gUnk_02034020;
u16 gUnk_02034024;
u8 gUnk_02034026;
u32 gRandSeed;
u8 gUnk_0203402C[4];
u32 gRandomState[4];
u8* gUnk_02034040;
u16 gUnk_02034044;
u16 gUnk_02034046;
s32 gUnk_02034048;
u16 gUnk_0203404C;
u16 gUnk_0203404E;
s16 gUnk_02034050;
s16 gUnk_02034052;
u8 gUnk_02034054;
u16 gUnk_02034056;
u8 gUnk_02034058;
u32 gUnk_0203405C;
u32 gUnk_02034060;
u8 gUnk_02034064;
s16 gUnk_02034066;
s16 gUnk_02034068;
u16 gUnk_0203406A;

void* ListPoolActivate(void* node, void* pool);
void ListPoolActivateAfter(void* node, void* pool, void* after);
void ListPoolActivateBefore(void* node, void* pool, void* before);
void* ListPoolFirst(void* pool);
void* ListPoolNext(void* node);
void* ListPoolFirstFree(void* pool);
void* LoadPaletteWithEffect(void* src, void* dst, u16 size);
void ListPoolRelease(void* node, void* pool);
void SortSpriteEntries(void* arr, s32 lo, s32 hi);
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

extern u16 gBg0Cnt;
extern u16 gBg1Cnt;
extern u16 gBg2Cnt;
void func_080066F4(s16 x, s16 y);
void PushPaletteEffect(s32 a);
void PopPaletteEffect(void);

extern u16 gSystemFlags;
ObjTiles* AllocObjTiles(u16 size, void* owner);
u16 GetObjTileCount(u16 a, u16 b);
s32 GetAngleDiff(s32 a, s32 b);
s32 GetAngleDiff16(s32 a, s32 b);
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
void func_080066F4(s16 x, s16 y);
void PushPaletteEffect(s32 a);
void PopPaletteEffect(void);

extern u16 gSystemFlags;
ObjTiles* AllocObjTiles(u16 size, void* owner);
u16 GetObjTileCount(u16 a, u16 b);
s32 GetAngleDiff(s32 a, s32 b);
s32 GetAngleDiff16(s32 a, s32 b);
void func_08005C60(u16 a);

INCLUDE_ASM("engine/func_0800216C.s");
u8 func_080022D4(s16 x, s16 y, void* obj, void* e, s32 f, u16 g, u16 h) {
    u8* p;
    u8* q0;
    u8* q1;
    u8* q2;
    u8* q3;
    u8* q4;
    s32 ofs;

    if (e == 0 || ((ObjTiles*)obj)->unk_00 == 0) {
        return 0;
    }
    {
        p = gSpriteWork;
        ofs = *(u16*)(p + 0x28A8) * 24;
        *(u16*)(p + ofs + 0x1AB8) = x;
        ofs = *(u16*)(p + 0x28A8) * 24;
        *(u16*)(p + ofs + 0x1ABA) = y;
        ofs = *(u16*)(p + 0x28A8) * 24;
        q0 = p + 0x1AA8;
        *(void**)(q0 + ofs) = obj;
        ofs = *(u16*)(p + 0x28A8) * 24;
        q1 = p + 0x1AAC;
        *(void**)(q1 + ofs) = e;
        ofs = *(u16*)(p + 0x28A8) * 24;
        q2 = p + 0x1AB0;
        *(s32*)(q2 + ofs) = f;
        ofs = *(u16*)(p + 0x28A8) * 24;
        *(u16*)(p + ofs + 0x1ABE) = g;
        ofs = *(u16*)(p + 0x28A8) * 24;
        *(u16*)(p + ofs + 0x1ABC) = h;
        ofs = *(u16*)(p + 0x28A8) * 24;
        q3 = p + 0x1AB4;
        *(void**)(q3 + ofs) = ((ObjTiles*)obj)->unk_20;
        ofs = *(u16*)(p + 0x28A8) * 4;
        q4 = p + 0x26A8;
        *(u32*)(q4 + ofs) = (u32)(p + (*(u16*)(p + 0x28A8) * 24 + 0x1AA8));
        *(u16*)(p + 0x28A8) += 1;
    }
    return 1;
}

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

void func_08002488(u16 a, u16 b, void* c, void* d, void* e, u16 f) {
    u8* p;
    u8* q0;
    u8* q1;
    u8* q2;
    u8* q3;
    u8* q4;
    u8* q5;
    s32 ofs;
    u32 z;

    p = gSpriteWork;
    if (*(u16*)(p + 0x28A8) > 0x7F) {
        return;
    }
    ofs = *(u16*)(p + 0x28A8) * 24;
    q5 = p + ofs + 0x1AB8;
    z = 0;
    *(u16*)q5 = a;
    ofs = *(u16*)(p + 0x28A8) * 24;
    *(u16*)(p + ofs + 0x1ABA) = b;
    ofs = *(u16*)(p + 0x28A8) * 24;
    q0 = p + 0x1AA8;
    *(void**)(q0 + ofs) = d;
    ofs = *(u16*)(p + 0x28A8) * 24;
    q1 = p + 0x1AAC;
    *(void**)(q1 + ofs) = e;
    ofs = *(u16*)(p + 0x28A8) * 24;
    q2 = p + 0x1AB0;
    *(u32*)(q2 + ofs) = z;
    ofs = *(u16*)(p + 0x28A8) * 24;
    *(u16*)(p + ofs + 0x1ABE) = f;
    ofs = *(u16*)(p + 0x28A8) * 24;
    *(u16*)(p + ofs + 0x1ABC) = z;
    ofs = *(u16*)(p + 0x28A8) * 24;
    q3 = p + 0x1AB4;
    *(void**)(q3 + ofs) = c;
    ofs = *(u16*)(p + 0x28A8) * 4;
    q4 = p + 0x26A8;
    *(u32*)(q4 + ofs) = (u32)(p + (*(u16*)(p + 0x28A8) * 24 + 0x1AA8));
    *(u16*)(p + 0x28A8) += 1;
    *(u16*)(p + 0x28AA) += 1;
}

INCLUDE_ASM("engine/func_08002594.s");

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
    cur = ListPoolFirst(gSpriteWork + 0x1800);
    while (cur != 0) {
        if (cur->unk_00 == src && cur->unk_24 == 0) {
            cur->refCount++;
            return cur;
        }
        cur = ListPoolNext(cur->unk_0C);
    }
    node = ListPoolFirstFree(gSpriteWork + 0x1800);
    if (node == 0) {
        return 0;
    }
    node->unk_28 = 0;
    node->unk_08 = size / 32;
    node->unk_00 = src;
    node->refCount = 0;
    node->unk_20 = 0;
    node->unk_24 = 0;
    node->self = node;
    cur = ListPoolFirst(gSpriteWork + 0x1800);
    if (cur == 0) {
        node->unk_06 = *(u16*)(gSpriteWork + 0x1810);
        RequestDma3Copy(src, (void*)((node->unk_06 << 5) + 0x06010000), size);
        ListPoolActivate(node->unk_0C, gSpriteWork + 0x1800);
        return node;
    }
    node->unk_06 = *(u16*)(gSpriteWork + 0x1810);
    avail = cur->unk_06 - *(u16*)(gSpriteWork + 0x1810);
    if (node->unk_08 <= (s16)avail) {
        RequestDma3Copy(src, (void*)((node->unk_06 << 5) + 0x06010000), size);
        ListPoolActivateBefore(node->unk_0C, gSpriteWork + 0x1800, cur->unk_0C);
        return node;
    }

    for (;;) {
        if (cur == 0) {
            break;
        }
        next = ListPoolNext(cur->unk_0C);
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
            ListPoolActivateAfter(node->unk_0C, gSpriteWork + 0x1800, cur->unk_0C);
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
        ListPoolRelease(p + 0x0C, gSpriteWork + 0x1800);
    }
}

void func_08002880(u8* p) {
    *(void**)(p + 0x2C) = 0;
    ListPoolRelease(p + 0x0C, gSpriteWork + 0x1800);
}

void func_080028A0(u8* p) {
    *(void**)(p + 0x2C) = 0;
    ListPoolRelease(p + 0x0C, gSpriteWork + 0x1800);
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
    node = ListPoolFirstFree(gSpriteWork + 0x1800);
    if (node == 0) {
        return 0;
    }
    node->unk_28 = 1;
    node->unk_08 = size / 32;
    node->unk_00 = owner;
    node->refCount = 0;
    node->unk_20 = 0;
    node->unk_24 = 1;
    node->self = node;
    cur = ListPoolFirst(gSpriteWork + 0x1800);
    if (cur == 0) {
        node->unk_06 = *(u16*)(gSpriteWork + 0x1810);
        ListPoolActivate(node->unk_0C, gSpriteWork + 0x1800);
        return node;
    }
    node->unk_06 = *(u16*)(gSpriteWork + 0x1810);
    avail = cur->unk_06 - *(u16*)(gSpriteWork + 0x1810);
    if (node->unk_08 <= (s16)avail) {
        ListPoolActivateBefore(node->unk_0C, gSpriteWork + 0x1800, cur->unk_0C);
        return node;
    }

    for (;;) {
        if (cur == 0) {
            break;
        }
        next = ListPoolNext(cur->unk_0C);
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
            ListPoolActivateAfter(node->unk_0C, gSpriteWork + 0x1800, cur->unk_0C);
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
        ListPoolRelease(p + 0x0C, gSpriteWork + 0x1A94);
    }
}

void ReleaseObjPalette(u8* p) {
    if (p != 0 && *(u8**)(p + 36) == p) {
        func_08002BCC(p);
    }
}

u8* AllocObjAffineAngle(u8 a, u8 b) {
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

u8* AllocObjAffine(u8 a, s32 sx, s32 sy, u8 f) {
    u8* base;
    u8* e;
    s32 sin;
    s32 cos;

    if (*(u16*)(gSpriteWork + 0x2BAC) > 0x1F || (a == 0 && sx == 0x100 && sy == sx)) {
        return 0;
    }
    sin = gSineTable[a];
    cos = gSineTable[a + 0x40];
    base = gSpriteWork;
    e = base + 0x28AC + *(u16*)(base + 0x2BAC) * 24;
    *(u16*)(e + 0x00) = (cos << 8) / sx;
    *(u16*)(e + 0x02) = (sin << 8) / sy;
    *(u16*)(e + 0x04) = (-sin << 8) / sx;
    *(u16*)(e + 0x06) = (cos << 8) / sy;
    *(u16*)(e + 0x08) = *(u16*)(base + 0x2BAC);
    *(u8*)(e + 0x0A) = f;
    *(u32*)(e + 0x0C) = sx;
    *(u32*)(e + 0x10) = sy;
    *(u8*)(e + 0x14) = a;
    *(u16*)(gSpriteWork + 0x2BAC) += 1;

    return e;
}

u8* func_08002DA0(u8 a, s32 sx, s32 sy, u8 f) {
    u8* base;
    u8* e;
    s32 sin;
    s32 cos;

    if (*(u16*)(gSpriteWork + 0x2BAC) > 0x1F || (a == 0 && sx == 0x100 && sy == sx)) {
        return 0;
    }
    sin = gSineTable[a];
    cos = gSineTable[a + 0x40];
    base = gSpriteWork;
    e = base + 0x28AC + *(u16*)(base + 0x2BAC) * 24;
    *(u16*)(e + 0x00) = (cos << 8) / sx;
    *(u16*)(e + 0x02) = (sin << 8) / sx;
    *(u16*)(e + 0x04) = (-sin << 8) / sy;
    *(u16*)(e + 0x06) = (cos << 8) / sy;
    *(u16*)(e + 0x08) = *(u16*)(base + 0x2BAC);
    *(u8*)(e + 0x0A) = f;
    *(u32*)(e + 0x0C) = sx;
    *(u32*)(e + 0x10) = sy;
    *(u8*)(e + 0x14) = a;
    *(u16*)(gSpriteWork + 0x2BAC) += 1;

    return e;
}

u8* AllocObjAffineMatrix(u16 a, u16 b, u16 c, u16 d, u8 f) {
    u8* base;
    u8* e;
    u32 z;

    if (*(u16*)(gSpriteWork + 0x2BAC) > 0x1F) {
        return 0;
    }
    base = gSpriteWork;
    e = base + 0x28AC + *(u16*)(base + 0x2BAC) * 24;
    z = 0;
    *(u16*)(e + 0x00) = a;
    *(u16*)(e + 0x02) = b;
    *(u16*)(e + 0x04) = c;
    *(u16*)(e + 0x06) = d;
    *(u16*)(e + 0x08) = *(u16*)(base + 0x2BAC);
    *(u8*)(e + 0x0A) = f;
    *(u32*)(e + 0x0C) = 0x100;
    *(u32*)(e + 0x10) = 0x100;
    *(u8*)(e + 0x14) = z;
    *(u16*)(gSpriteWork + 0x2BAC) += 1;

    return e;
}

void SortSprites(void) {
    if (*(u16*)(gSpriteWork + 0x28A8) > 1) {
        SortSpriteEntries(gSpriteWork + 0x26A8, *(u16*)(gSpriteWork + 0x28AA),
                      *(u16*)(gSpriteWork + 0x28A8) - 1);
    }
    *(u16*)(gSpriteWork + 0x28AA) = 0;
}

INCLUDE_ASM("engine/func_08002F50.s");

void func_080034D8(u8 a) {
    gSpriteWork[0x2BAF] = a;
}

void SetObjMosaicSize(u8 a, u8 b) {
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
            sum += GetObjTileCount(p[0], p[1]);
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
        total += GetObjTileCount(p[0], p[1]);
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
        t->refCount = 0;
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
        t->refCount = 0;
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
        t->refCount = 0;
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
                    n = GetObjTileCount(b[0], b[1]);
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
ObjTiles* AllocObjPalette(u16 size) {
    ObjTiles* node;
    ObjTiles* cur;
    ObjTiles* next;
    s32 avail;
    s16 end;

    node = ListPoolFirstFree(gSpriteWork + 0x1A94);
    if (node == 0) {
        return 0;
    }
    node->unk_20 = 2;
    node->unk_08 = size / 32;
    node->unk_00 = 0;
    node->refCount = 0;
    *(ObjTiles**)((u8*)node + 0x24) = node;
    cur = ListPoolFirst(gSpriteWork + 0x1A94);
    if (cur == 0) {
        node->unk_06 = *(u16*)(gSpriteWork + 0x1AA4);
        ListPoolActivate(node->unk_0C, gSpriteWork + 0x1A94);
        return node;
    }
    node->unk_06 = *(u16*)(gSpriteWork + 0x1AA4);
    avail = cur->unk_06 - *(u16*)(gSpriteWork + 0x1AA4);
    if (node->unk_08 <= (s16)avail) {
        ListPoolActivateBefore(node->unk_0C, gSpriteWork + 0x1A94, cur->unk_0C);
        return node;
    }

    for (;;) {
        if (cur == 0) {
            break;
        }
        next = ListPoolNext(cur->unk_0C);
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
            ListPoolActivateAfter(node->unk_0C, gSpriteWork + 0x1A94, cur->unk_0C);
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

u8 CanAllocObjTiles(u16 n) {
    ObjTiles* cur;
    ObjTiles* next;
    u16 pos;
    s16 end;

    cur = ListPoolFirst(gSpriteWork + 0x1800);
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
        next = ListPoolNext(cur->unk_0C);
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
u8 CanAllocObjPalette(u16 n) {
    ObjTiles* cur;
    ObjTiles* next;
    u16 pos;
    s16 end;

    cur = ListPoolFirst(gSpriteWork + 0x1A94);
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
        next = ListPoolNext(cur->unk_0C);
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
void GetObjSize(u16 a, u16 b, u16* w, u16* h) {
    switch (((b << 16) | a) & 0xC000C000) {
    case 0x00000000:
        *w = 8;
        *h = 8;
        break;
    case 0x40000000:
        *w = 16;
        *h = 16;
        break;
    case 0x80000000:
        *w = 32;
        *h = 32;
        break;
    case 0xC0000000:
        *w = 64;
        *h = 64;
        break;
    case 0x00004000:
        *w = 16;
        *h = 8;
        break;
    case 0x40004000:
        *w = 32;
        *h = 8;
        break;
    case 0x80004000:
        *w = 32;
        *h = 16;
        break;
    case 0xC0004000:
        *w = 64;
        *h = 32;
        break;
    case 0x00008000:
        *w = 8;
        *h = 16;
        break;
    case 0x40008000:
        *w = 8;
        *h = 32;
        break;
    case 0x80008000:
        *w = 16;
        *h = 32;
        break;
    case 0xC0008000:
        *w = 32;
        *h = 64;
        break;
    default:
        *w = 0;
        *h = 0;
        break;
    }
}

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

void func_08003FCC(void* a, s32 v, s32* outX, s32* outY) {
    u8* p = a;

    *outX = func_08003E2C((s16*)p, v, *(s32**)(p + 0x0C), *(s32**)(p + 0x18), *(s32**)(p + 0x10));
    *outY = func_08003E2C((s16*)p, v, *(s32**)(p + 0x0C), *(s32**)(p + 0x1C), *(s32**)(p + 0x14));
}

void func_0800400C(void* a) {
    u8* p = a;

    EwramFree(*(void**)(p + 0x04));
    EwramFree(*(void**)(p + 0x08));
    EwramFree(*(void**)(p + 0x0C));
    EwramFree(*(void**)(p + 0x10));
    EwramFree(*(void**)(p + 0x14));
}
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

#ifndef VERSION_EU
void VTransInit(void) {
    u32 zero;

    SetIwramHeapName(sVTransHeapName);
    gDma3Requests = IwramAlloc(0x10B0);
    zero = 0;
    CpuSet(&zero, gDma3Requests, 0x0500042C);
}
#else
INCLUDE_ASM("engine/VTransInit.s");
#endif

void VTransFree(void) {
    IwramFree(gDma3Requests);
}

#ifndef VERSION_EU
void VTransReset(void) {
    Dma3Queue* q = gDma3Requests;

    q->requestCount = 0;
    q->unk_10A2 = 0;
    q->unk_10A4 = 0;
    q->unk_10A6 = 0;
    q->count = 0;
    q->unk_10AC = 0;
}
#else
INCLUDE_ASM("engine/VTransReset.s");
#endif

u8 RequestDma3Copy(void* src, void* dst, u16 size) {
    Dma3Queue* q;
    vu32* dma;

    if (size == 0) {
        return 0;
    }
    q = gDma3Requests;
    if (q->requestCount > 255) {
        return 0;
    }

    if ((gSystemFlags & 8) == 0) {
        q->requests[q->requestCount].src = src;
        q->requests[q->requestCount].dst = dst;
        q->requests[q->requestCount].size = size;
        q->requestCount = q->requestCount + 1;
    } else {
        dma = (vu32*)0x040000D4;
        dma[0] = (u32)src;
        dma[1] = (u32)dst;
        dma[2] = 0x80000000 | (size / 2);
        dma[2];
    }
    return 1;
}

#ifdef VERSION_EU
INCLUDE_ASM("engine/eu_080044C0.s");
#endif

u8 func_0800443C(void* a, u16 b) {
    Dma3Queue* q = gDma3Requests;

    if (q->count > 3) {
        return 0;
    }
    q->pending[q->count].unk_00 = a;
    q->pending[q->count].unk_04 = b;
    q->count = q->count + 1;

    return 1;
}
INCLUDE_ASM("engine/func_0800448C.s");

u8 func_080045AC(void* a, void* b, u8 c, u8 d, u8 e) {
    if (gDma3Requests->unk_10A4 > 7) {
        return 0;
    }
    gDma3Requests->unk_1000[gDma3Requests->unk_10A4].unk_00 = a;
    gDma3Requests->unk_1000[gDma3Requests->unk_10A4].unk_04 = b;
    gDma3Requests->unk_1000[gDma3Requests->unk_10A4].unk_08 = c & 0x1F;
    gDma3Requests->unk_1000[gDma3Requests->unk_10A4].unk_09 = d & 0x1F;
    gDma3Requests->unk_1000[gDma3Requests->unk_10A4].unk_0A = e;
    gDma3Requests->unk_10A4 = gDma3Requests->unk_10A4 + 1;

    return 1;
}

#ifndef VERSION_EU
u8 func_08004678(void* a) {
    Dma3Queue* q = gDma3Requests;

    if (q->unk_10A6 > 7) {
        return 0;
    }
    q->unk_1060[q->unk_10A6] = a;
    q->unk_10A6 = q->unk_10A6 + 1;

    return 1;
}
#else
INCLUDE_ASM("engine/func_08004678.s");
#endif

#ifndef VERSION_EU
u32 func_080046B4(void) {
    Dma3Queue* q = gDma3Requests;

    return q->unk_10AC;
}
#else
INCLUDE_ASM("engine/func_080046B4.s");
#endif

INCLUDE_ASM("engine/FlushDma3Queue.s");
INCLUDE_ASM("engine/func_08004938.s");

#ifndef VERSION_EU
void BgInit(void) {
    BgEntry** p;
    u32 zero;

    SetIwramHeapName(sBgHeapName);
    p = &gBgEntries;
    *p = IwramAlloc(0x40);
    zero = 0;
    CpuSet(&zero, *p, 0x05000010);
}
#else
INCLUDE_ASM("engine/BgInit.s");
#endif

void BgFree(void) {
    IwramFree(gBgEntries);
}

void* func_08004BD8(BgEntry* e, u16 x, u16 y) {
    u8 col = (x >> 8) % e->unk_08;
    u8 row = (y >> 8) % e->unk_09;

    return ((void**)e->unk_04)[e->unk_08 * row + col];
}

INCLUDE_ASM("engine/func_08004C20.s");

#ifndef VERSION_EU
void BgReset(void) {
    gBackdropColor = 0;
    DisableBg(0);
    DisableBg(1);
    DisableBg(2);
    DisableBg(3);
    SetBgMosaicSize(0, 0);
    gBldCnt = 0;
}
#else
INCLUDE_ASM("engine/BgReset.s");
#endif

#ifndef VERSION_EU
void SetBgMode0(void) {
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
        u8* p = (u8*)gBgEntries;
        s32 o = i * 16;
        p += 4;
        p += o;
        *(void**)p = 0;
    }
}
#else
INCLUDE_ASM("engine/SetBgMode0.s");
#endif
#ifndef VERSION_EU
void SetBgMode1(void) {
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
    SetBgAffine(2, 0, 0x100, 0x100, 0, 0);

    for (i = 0; i <= 3; i++) {
        u8* p = (u8*)gBgEntries;
        s32 o = i * 16;
        p += 4;
        p += o;
        *(void**)p = 0;
    }
}
#else
INCLUDE_ASM("engine/SetBgMode1.s");
#endif
#ifndef VERSION_EU
void SetBgMode2(void) {
    s32 i;

    gDispCnt = (gDispCnt & 0xFFF8) | 2;
    gBg2Cnt = 0x6080;
    gBg3Cnt = 0x4081;
    SetupBg(2, 0, 15, 0);
    SetupBg(3, 2, 31, 0);
    SetBgAffine(2, 0, 0x100, 0x100, 0, 0);
    SetBgAffine(3, 0, 0x100, 0x100, 0, 0);

    for (i = 0; i <= 3; i++) {
        u8* p = (u8*)gBgEntries;
        s32 o = i * 16;
        p += 4;
        p += o;
        *(void**)p = 0;
    }
}
#else
INCLUDE_ASM("engine/SetBgMode2.s");
#endif
void SetBgMode3(void) {
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

#ifndef VERSION_EU
void func_0800516C(s32 bg, void* src, u8 w, u8 h) {
    u8* p;
    u8* q;
    s32 ofs;
    u32 z;

    if (gDispCnt & 7) {
        if (bg == 2 || bg == 3) {
            return;
        }
    }

    EnableBg(bg);
    p = (u8*)gBgEntries;
    ofs = bg * 16;
    q = p + 4;
    *(void**)(q + ofs) = src;
    p += ofs;
    z = 0;
    ((BgEntry*)p)->unk_08 = w;
    ((BgEntry*)((u8*)gBgEntries + ofs))->unk_09 = h;
    ((BgEntry*)((u8*)gBgEntries + ofs))->unk_0A = z;
    ((BgEntry*)((u8*)gBgEntries + ofs))->unk_0C = z;
    ((BgEntry*)((u8*)gBgEntries + ofs))->unk_00 = 1;
}
#else
INCLUDE_ASM("engine/func_0800516C.s");
#endif

#ifndef VERSION_EU
void func_080051C4(s32 bg, u16 x, u16 y) {
    BgEntry* e = &gBgEntries[bg];

    if (e->unk_04 == 0) {
        return;
    }
    e->unk_0A = x;
    e->unk_0C = y;
    func_08004C20(x, y, e, (void*)(((*gBgControl[bg] & 0x1F00) << 3) + 0x06000000), 0, 0, 0x1F, 0x15);
    SetBgScroll(bg, x & 7, y & 7);
    e->unk_00 = 0;
}
#else
INCLUDE_ASM("engine/func_080051C4.s");
#endif
INCLUDE_ASM("engine/func_08005244.s");

#ifndef VERSION_EU
u16 func_08005458(s32 bg) {
    BgEntry* e = &gBgEntries[bg];

    if (e->unk_04 == 0) {
        return 0;
    }
    return e->unk_0A;
}
#else
INCLUDE_ASM("engine/func_08005458.s");
#endif

#ifndef VERSION_EU
u16 func_08005474(s32 bg) {
    BgEntry* e = &gBgEntries[bg];

    if (e->unk_04 == 0) {
        return 0;
    }
    return e->unk_0C;
}
#else
INCLUDE_ASM("engine/func_08005474.s");
#endif

void SetBgMosaic(s32 bg, u8 on) {
    if (on) {
        *gBgControl[bg] |= 0x40;
    } else {
        *gBgControl[bg] &= 0xFFBF;
    }
}

void SetBgMosaicSize(u8 a, u8 b) {
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

void SetBgAffine(s32 bg, u8 rot, s32 sx, s32 sy, s32 dx, s32 dy) {
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

void SetBackdropColor(u8 r, u8 g, u8 b) {
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

#ifdef VERSION_EU
INCLUDE_ASM("engine/eu_080059D4.s");
#endif

#ifdef NON_MATCHING
s32 GetAngleDiff(s32 a, s32 b) {
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
INCLUDE_ASM("engine/GetAngleDiff.s");
#endif

s32 GetAngleDiff16(s32 a, s32 b) {
    s32 x = a & 0xFFFF;
    s32 y = b & 0xFFFF;
    s32 d = x - y;
    s32 c;

    if (d <= -0x8000) {
        return (x + 0x10000) - y;
    }
    c = 0x10000;

    if (d > 0x7FFF) {
        return (x - c) - y;
    }
    return d;
}

void ApproachAngle(u16* p, u16 target, u16 shift) {
    s16 d;
    u16 v;

    if (*p == target) {
        return;
    }
    d = GetAngleDiff((s16)target, (s16)*p);
    if (d == 0) {
        return;
    }
    v = d >> shift;
    *p = v + *p;
}

void ApproachAngle16(u16* p, u16 target, u16 shift) {
    s32 d = GetAngleDiff16(target, *p);

    if (d != 0) {
        *p = (d >> shift) + *p;
    }
}

void ApproachValue(s32* value, s32 target, u16 steps) {
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

s32 Lerp8(s32 a, s32 b, s32 t) {
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

void* AnimUpdate(AnimState* a) {
    void* gfx = AnimGetGfx(a);
    AnimFrame* frames = a->frames;
    u16 index;

    if (frames == 0) {
        return 0;
    }
    a->timer++;
    index = a->frame;

    if (a->timer >= frames[index].duration) {
        a->frame = index + 1;
        a->timer = 0;

        if (a->frame >= a->frameCount) {
            if (a->flags & 1) {
                a->frame = 0;
            } else {
                a->frame = index;
            }
            a->flags |= 0x1000;
        }
    }

    return gfx;
}

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

u16 AnimGetId(AnimState* a) {
    return a->animId;
}

u16 AnimGetFrame(AnimState* a) {
    return a->frame;
}

u16 AnimGetGfxIndex(AnimState* a) {
    return a->frames[a->frame].gfxIndex;
}

void AnimSetFrame(AnimState* a, u16 frame) {
    if (frame < a->frameCount) {
        a->frame = frame;
        a->timer = 0;
        a->flags &= 0xEFFF;
    }
}

void AnimReset(AnimState* a) {
    a->frame = 0;
    a->timer = 0;
    a->flags &= 0xEFFF;
}

void FadeInit(void) {
    u32 zero;

    SetIwramHeapName(sFadeHeapName);
    gFadeWork = IwramAlloc(0x598);
    zero = 0;
    CpuSet(&zero, gFadeWork, 0x05000166);
}

void FadeFree(void) {
    IwramFree(gFadeWork);
}

void FadeReset(void) {
    u32 zero = 0;

    CpuSet(&zero, gFadeWork, 0x05000166);
}

#ifdef NON_MATCHING
void LoadPalette(void* src, void* dst, s32 size) {
    PaletteSlot* base;
    s32 idx;
    s32 count;
    s32 i;
    void* p;

    base = (PaletteSlot*)gFadeWork;
    count = (u16)size / 32;
    idx = ((s32)dst - 0x05000000) / 32;
    p = LoadPaletteWithEffect(src, dst, size);

    for (i = 0; i < count; i++) {
        base[idx + i].unk_00 = (u8*)p + i * 32;
        base[idx + i].unk_04 = (u8*)dst + i * 32;
        base[idx + i].unk_29 = 1;
    }
}
#else
INCLUDE_ASM("engine/LoadPalette.s");
#endif

void func_08005C60(u16 a) {
    PaletteSlot* p = (PaletteSlot*)gFadeWork;

    p += a;
    p->unk_00 = 0;
}

INCLUDE_ASM("engine/func_08005C78.s");
void func_08006120(s32 a, u16 b) {
    u8* base = gFadeWork;
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
    u8* base = gFadeWork;
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
    u8* base = gFadeWork;
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
    u8* base = gFadeWork;

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
    u8* base = gFadeWork;
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
    p = (PaletteSlot*)gFadeWork;
    p += slot;
    p->unk_28 = value;
}

u8 func_08006314(void) {
    if (*(u16*)(gFadeWork + 0x594) & 1) {
        return 1;
    }
    return 0;
}

u16 _08006338(void) {
    switch (*(u32*)(gFadeWork + 0x590)) {
    case 1:
    case 2:
        return 0x7FFF;
    case 3:
        return 0x1F;
    case 4:
        return 0x7C00;
    case 5:
        return 0x3E0;
    case 0:
    default:
        return 0;
    }
}

u16 func_08006390(void) {
    return *(u32*)(gFadeWork + 0x580) >> 8;
}

void func_080063A8(void) {
    u16 v = *(u16*)(gFadeWork + 0x594) | 2;

    *(u16*)(gFadeWork + 0x594) = v;
}

void func_080063C4(u8 on) {
    if (on) {
        u16 v = *(u16*)(gFadeWork + 0x594) | 4;

        *(u16*)(gFadeWork + 0x594) = v;
    } else {
        *(u16*)(gFadeWork + 0x594) &= 0xFFFB;
    }
}

void MosaicReset(void) {
    gUnk_0203401C = 0;
    gUnk_02034020 = 0;
    gUnk_02034024 = 0;
    gUnk_02034026 = 0;
}

void MosaicUpdate(void) {
    u16 t;
    u8 v;

    if (gUnk_02034024 != 0) {
        ApproachValue((s32*)&gUnk_0203401C, gUnk_02034020, gUnk_02034024--);
        t = gUnk_0203401C >> 8;
        v = t;
        SetBgMosaicSize(v, v);
        SetObjMosaicSize(v, v);
    } else if (gUnk_02034026 != 0) {
        gUnk_02034026 = 0;
        func_080034D8(0);
    }
}

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
    PushPaletteEffect(0);
    LoadBgPalette(gUnk_02034048, *(void**)(a + 0x08), *(u16*)(a + 0x0C));
    PopPaletteEffect();
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

void func_08006B28(u16 a) {
    gUnk_0203406A = a;
}

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
