#include "macros.h"
#include "gba/syscall.h"
#include "malloc.h"
#include "engine.h"
#include "sprite.h"
#include "types.h"

u32 gUnk_0203401C;
u32 gUnk_02034020;
u16 gUnk_02034024;
u8 gMosaicActive;
u32 gRandSeed;
u8 gUnk_0203402C[4];
u32 gRandomState[4];
UnkBgAnim* gUnk_02034040;
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
s16 GetAngleDiff(s32 a, s32 b);
s32 GetAngleDiff16(s32 a, s32 b);
void func_08005C60(u16 a);
void func_08003CD4(UnkSpline* p, s32* d, s32* xs, s32* e);
void func_080051C4(s32 bg, u16 x, u16 y);
s32 abs(s32 a);

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
s16 GetAngleDiff(s32 a, s32 b);
s32 GetAngleDiff16(s32 a, s32 b);
void func_08005C60(u16 a);

u8 func_0800216C(s16 x, s16 y, void* c, void* obj, void* e, s32 f, u16 g, u16 h) {
    SpriteWork* p;
    SpriteWork* w;
    u16 n;
    s32 i;
    u16 cnt;
    u16 base;

    if (e == 0 || c == 0) {
        return 0;
    }
    p = gSpriteWork;
    p->entries[p->entryCount].unk_10 = x;
    p->entries[p->entryCount].unk_12 = y;
    p->entries[p->entryCount].unk_00 = obj;
    p->entries[p->entryCount].unk_04 = e;
    p->entries[p->entryCount].unk_08 = f;
    p->entries[p->entryCount].unk_16 = g;
    p->entries[p->entryCount].unk_14 = h;
    p->entries[p->entryCount].unk_0C = c;

    if (((ObjTiles*)obj)->unk_20 != (u32)c) {
        ((ObjTiles*)obj)->unk_20 = (u32)c;
        n = *(u16*)c;
        c = (u16*)c + 1;
        base = 0;

        if (n != 0) {
            i = n;
            do {
                cnt = GetObjTileCount(((ObjTileListEntry*)c)->unk_00, ((ObjTileListEntry*)c)->unk_02);
                RequestDma3Copy((u8*)((ObjTiles*)obj)->unk_00 + ((((ObjTileListEntry*)c)->unk_04 & 0x3FF) << 5), (void*)(((((ObjTiles*)obj)->unk_06 + base) << 5) + 0x06010000), cnt << 5);
                base += cnt;
                c = (u16*)c + 3;
            } while (--i);
        }
    }
    w = gSpriteWork;
    w->sortPtrs[w->entryCount] = &w->entries[w->entryCount];
    w->entryCount += 1;
    return 1;
}
u8 func_080022D4(s16 x, s16 y, void* obj, void* e, s32 f, u16 g, u16 h) {
    SpriteWork* p;

    if (e == 0 || ((ObjTiles*)obj)->unk_00 == 0) {
        return 0;
    }
    {
        p = gSpriteWork;
        p->entries[p->entryCount].unk_10 = x;
        p->entries[p->entryCount].unk_12 = y;
        p->entries[p->entryCount].unk_00 = obj;
        p->entries[p->entryCount].unk_04 = e;
        p->entries[p->entryCount].unk_08 = f;
        p->entries[p->entryCount].unk_16 = g;
        p->entries[p->entryCount].unk_14 = h;
        p->entries[p->entryCount].unk_0C = (void*)((ObjTiles*)obj)->unk_20;
        p->sortPtrs[p->entryCount] = &p->entries[p->entryCount];
        p->entryCount += 1;
    }
    return 1;
}
u8 DrawSprite(u16 x, u16 y, void* c, void* obj, void* e, s32 f, u16 g, u16 h) {
    if (gSpriteWork->entryCount <= 127 && obj != 0) {
        switch (((ObjTiles*)obj)->unk_28) {
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
    SpriteWork* p;
    u16* q5;
    u32 z;

    p = gSpriteWork;
    if (p->entryCount > 0x7F) {
        return;
    }
    q5 = (u16*)((u32)p + p->entryCount * 24 + ((u32)&p->entries[0].unk_10 - (u32)p));
    z = 0;
    *q5 = a;
    p->entries[p->entryCount].unk_12 = b;
    p->entries[p->entryCount].unk_00 = d;
    p->entries[p->entryCount].unk_04 = e;
    p->entries[p->entryCount].unk_08 = z;
    p->entries[p->entryCount].unk_16 = f;
    p->entries[p->entryCount].unk_14 = z;
    p->entries[p->entryCount].unk_0C = c;
    p->sortPtrs[p->entryCount] = &p->entries[p->entryCount];
    p->entryCount += 1;
    p->sortLo += 1;
}

void func_08002594(u16 a, u16 b, void* c, void* d, void* e, void* f, u16 g) {
    SpriteWork* p;
    u16* q5;
    u32 z;

    p = gSpriteWork;
    if (p->entryCount > 0x7F) {
        return;
    }
    q5 = (u16*)((u32)p + p->entryCount * 24 + ((u32)&p->entries[0].unk_10 - (u32)p));
    z = 0;
    *q5 = a;
    p->entries[p->entryCount].unk_12 = b;
    p->entries[p->entryCount].unk_00 = d;
    p->entries[p->entryCount].unk_04 = e;
    p->entries[p->entryCount].unk_08 = f;
    p->entries[p->entryCount].unk_16 = g;
    p->entries[p->entryCount].unk_14 = z;
    p->entries[p->entryCount].unk_0C = c;
    p->sortPtrs[p->entryCount] = &p->entries[p->entryCount];
    p->entryCount += 1;
    p->sortLo += 1;
}

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
    cur = ListPoolFirst(&gSpriteWork->tilePool);
    while (cur != 0) {
        if (cur->unk_00 == src && cur->unk_24 == 0) {
            cur->refCount++;
            return cur;
        }
        cur = ListPoolNext(cur->unk_0C);
    }
    node = ListPoolFirstFree(&gSpriteWork->tilePool);
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
    cur = ListPoolFirst(&gSpriteWork->tilePool);
    if (cur == 0) {
        node->unk_06 = gSpriteWork->tilePool.rangeStart;
        RequestDma3Copy(src, (void*)((node->unk_06 << 5) + 0x06010000), size);
        ListPoolActivate(node->unk_0C, &gSpriteWork->tilePool);
        return node;
    }
    node->unk_06 = gSpriteWork->tilePool.rangeStart;
    avail = cur->unk_06 - gSpriteWork->tilePool.rangeStart;
    if (node->unk_08 <= (s16)avail) {
        RequestDma3Copy(src, (void*)((node->unk_06 << 5) + 0x06010000), size);
        ListPoolActivateBefore(node->unk_0C, &gSpriteWork->tilePool, cur->unk_0C);
        return node;
    }

    for (;;) {
        if (cur == 0) {
            break;
        }
        next = ListPoolNext(cur->unk_0C);
        node->unk_06 = cur->unk_06 + cur->unk_08;
        if (node->unk_06 + node->unk_08 > gSpriteWork->tilePool.rangeEnd) {
            break;
        }

        if (next != 0) {
            end = next->unk_06 - node->unk_06;
        } else {
            end = gSpriteWork->tilePool.rangeEnd - node->unk_06;
        }

        if (node->unk_08 <= end) {
            RequestDma3Copy(src, (void*)((node->unk_06 << 5) + 0x06010000), size);
            ListPoolActivateAfter(node->unk_0C, &gSpriteWork->tilePool, cur->unk_0C);
            return node;
        }
        cur = next;
    }
    return 0;
}

void func_0800284C(ObjTiles* p) {
    if ((s16)p->refCount > 0) {
        p->refCount -= 1;
    } else {
        p->self = 0;
        ListPoolRelease(p->unk_0C, &gSpriteWork->tilePool);
    }
}
void func_08002880(ObjTiles* p) {
    p->self = 0;
    ListPoolRelease(p->unk_0C, &gSpriteWork->tilePool);
}
void func_080028A0(ObjTiles* p) {
    p->self = 0;
    ListPoolRelease(p->unk_0C, &gSpriteWork->tilePool);
}
void ReleaseObjTiles(void* a) {
    ObjTiles* p = a;
    ObjTiles* q;

    if (p == 0) {
        return;
    }
    q = p->self;
    if (q != p) {
        return;
    }

    switch (q->unk_28) {
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
    node = ListPoolFirstFree(&gSpriteWork->tilePool);
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
    cur = ListPoolFirst(&gSpriteWork->tilePool);
    if (cur == 0) {
        node->unk_06 = gSpriteWork->tilePool.rangeStart;
        ListPoolActivate(node->unk_0C, &gSpriteWork->tilePool);
        return node;
    }
    node->unk_06 = gSpriteWork->tilePool.rangeStart;
    avail = cur->unk_06 - gSpriteWork->tilePool.rangeStart;
    if (node->unk_08 <= (s16)avail) {
        ListPoolActivateBefore(node->unk_0C, &gSpriteWork->tilePool, cur->unk_0C);
        return node;
    }

    for (;;) {
        if (cur == 0) {
            break;
        }
        next = ListPoolNext(cur->unk_0C);
        node->unk_06 = cur->unk_06 + cur->unk_08;
        if (node->unk_06 + node->unk_08 > gSpriteWork->tilePool.rangeEnd) {
            break;
        }

        if (next != 0) {
            end = next->unk_06 - node->unk_06;
        } else {
            end = gSpriteWork->tilePool.rangeEnd - node->unk_06;
        }

        if (node->unk_08 <= end) {
            ListPoolActivateAfter(node->unk_0C, &gSpriteWork->tilePool, cur->unk_0C);
            return node;
        }
        cur = next;
    }
    return 0;
}

void func_08002A10(void* a, void* b) {
    *(void**)a = b;
}

ObjPaletteNode* LoadObjPalette(void* src, u16 size) {
    ObjPaletteNode* node;
    ObjPaletteNode* cur;
    ObjPaletteNode* next;
    s32 avail;
    s16 end;

    if (size == 0) {
        return 0;
    }

    if (src == 0) {
        return 0;
    }

    for (cur = ListPoolFirst(&gSpriteWork->palettePool); cur != 0; cur = ListPoolNext(cur->unk_0C)) {
        if (cur->unk_00 == src) {
            cur->refCount++;
            return cur;
        }
    }
    node = ListPoolFirstFree(&gSpriteWork->palettePool);
    if (node == 0) {
        return 0;
    }
    node->unk_20 = 0;
    node->unk_08 = size / 32;
    node->unk_00 = src;
    node->refCount = 0;
    node->self = node;
    cur = ListPoolFirst(&gSpriteWork->palettePool);
    if (cur == 0) {
        node->unk_06 = gSpriteWork->palettePool.rangeStart;
        LoadPalette(src, (void*)((node->unk_06 << 5) + 0x05000200), size);
        ListPoolActivate(node->unk_0C, &gSpriteWork->palettePool);
        return node;
    }
    node->unk_06 = gSpriteWork->palettePool.rangeStart;
    avail = cur->unk_06 - gSpriteWork->palettePool.rangeStart;
    if (node->unk_08 <= (s16)avail) {
        LoadPalette(src, (void*)((node->unk_06 << 5) + 0x05000200), size);
        ListPoolActivateBefore(node->unk_0C, &gSpriteWork->palettePool, cur->unk_0C);
        return node;
    }

    for (;;) {
        if (cur == 0) {
            break;
        }
        next = ListPoolNext(cur->unk_0C);
        node->unk_06 = cur->unk_06 + cur->unk_08;
        if (node->unk_06 + node->unk_08 > gSpriteWork->palettePool.rangeEnd) {
            break;
        }

        if (next != 0) {
            end = next->unk_06 - node->unk_06;
        } else {
            end = gSpriteWork->palettePool.rangeEnd - node->unk_06;
        }

        if (node->unk_08 <= end) {
            LoadPalette(src, (void*)((node->unk_06 << 5) + 0x05000200), size);
            ListPoolActivateAfter(node->unk_0C, &gSpriteWork->palettePool, cur->unk_0C);
            return node;
        }
        cur = next;
    }
    return 0;
}

void LoadObjPaletteBank(u16 bank, void* src) {
    LoadPalette(src, (void*)((bank << 5) + 0x05000200), 32);
}

void func_08002BCC(ObjPaletteNode* p) {
    if ((s16)p->refCount > 0) {
        p->refCount -= 1;
    } else {
        p->self = 0;
        func_08005C60(p->unk_06 + 0x10);
        ListPoolRelease(p->unk_0C, &gSpriteWork->palettePool);
    }
}
void ReleaseObjPalette(ObjPaletteNode* p) {
    if (p != 0 && p->self == p) {
        func_08002BCC(p);
    }
}
u8* AllocObjAffineAngle(u8 a, u8 b) {
    ObjAffine* e;
    s32 sin;
    s32 cos;

    if (gSpriteWork->affineCount <= 0x1F && a != 0) {
        sin = gSineTable[a];
        cos = gSineTable[a + 0x40];
        e = &gSpriteWork->affine[gSpriteWork->affineCount];
        e->pa = cos;
        e->pb = sin;
        e->pc = -sin;
        e->pd = cos;
        e->index = gSpriteWork->affineCount;
        e->unk_0A = b;
        e->sx = 0x100;
        e->sy = 0x100;
        e->angle = a;
        gSpriteWork->affineCount += 1;
        return (u8*)e;
    }
    return 0;
}
u8* AllocObjAffine(u8 a, s32 sx, s32 sy, u8 f) {
    ObjAffine* e;
    s32 sin;
    s32 cos;

    if (gSpriteWork->affineCount > 0x1F || (a == 0 && sx == 0x100 && sy == sx)) {
        return 0;
    }
    sin = gSineTable[a];
    cos = gSineTable[a + 0x40];
    e = &gSpriteWork->affine[gSpriteWork->affineCount];
    e->pa = (cos << 8) / sx;
    e->pb = (sin << 8) / sy;
    e->pc = (-sin << 8) / sx;
    e->pd = (cos << 8) / sy;
    e->index = gSpriteWork->affineCount;
    e->unk_0A = f;
    e->sx = sx;
    e->sy = sy;
    e->angle = a;
    gSpriteWork->affineCount += 1;

    return (u8*)e;
}
u8* func_08002DA0(u8 a, s32 sx, s32 sy, u8 f) {
    ObjAffine* e;
    s32 sin;
    s32 cos;

    if (gSpriteWork->affineCount > 0x1F || (a == 0 && sx == 0x100 && sy == sx)) {
        return 0;
    }
    sin = gSineTable[a];
    cos = gSineTable[a + 0x40];
    e = &gSpriteWork->affine[gSpriteWork->affineCount];
    e->pa = (cos << 8) / sx;
    e->pb = (sin << 8) / sx;
    e->pc = (-sin << 8) / sy;
    e->pd = (cos << 8) / sy;
    e->index = gSpriteWork->affineCount;
    e->unk_0A = f;
    e->sx = sx;
    e->sy = sy;
    e->angle = a;
    gSpriteWork->affineCount += 1;

    return (u8*)e;
}
u8* AllocObjAffineMatrix(u16 a, u16 b, u16 c, u16 d, u8 f) {
    ObjAffine* e;
    u32 z;

    if (gSpriteWork->affineCount > 0x1F) {
        return 0;
    }
    e = &gSpriteWork->affine[gSpriteWork->affineCount];
    z = 0;
    e->pa = a;
    e->pb = b;
    e->pc = c;
    e->pd = d;
    e->index = gSpriteWork->affineCount;
    e->unk_0A = f;
    e->sx = 0x100;
    e->sy = 0x100;
    e->angle = z;
    gSpriteWork->affineCount += 1;

    return (u8*)e;
}
void SortSprites(void) {
    if (gSpriteWork->entryCount > 1) {
        SortSpriteEntries(gSpriteWork->sortPtrs, gSpriteWork->sortLo,
                      gSpriteWork->entryCount - 1);
    }
    gSpriteWork->sortLo = 0;
}

#ifdef NON_MATCHING
static inline void EngineObjSize(u16 a, u16 b, u16* w, u16* h) {
    switch ((((u32)b << 16) | a) & 0xC000C000) {
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

void func_08002F50(void) {
    u16* oam;
    s32 i;
    s32 j;
    s32 count;
    s32 emitted;
    u8 mosaic;
    SpriteEntry** entries;
    SpriteEntry* entry;
    ObjAffine* affine;
    u16* parts;
    u16 partCount;
    u16 tileOffset;
    u16 attr0;
    u16 attr1;
    u16 attr2;
    u16 width;
    u16 height;
    s16 x;
    s16 y;
    s32 xx;
    s32 yy;
    s32 angle;
    s32 cosIndex;
    s32 sinIndex;
    u16 palette;
    ObjTiles* tiles;
    u16 flip;

    if (gSpriteWork->unk_2BAE != 0) {
        return;
    }
    oam = (u16*)0x07000000;
    for (i = 0; i < gSpriteWork->affineCount; i++) {
        oam += 3;
        *oam = gSpriteWork->affine[i].pa;
        oam += 4;
        *oam = gSpriteWork->affine[i].pb;
        oam += 4;
        *oam = gSpriteWork->affine[i].pc;
        oam += 4;
        *oam = gSpriteWork->affine[i].pd;
        oam++;
    }
    gSpriteWork->affineCount = 0;
    emitted = 0;
    oam = (u16*)0x07000000;
    count = gSpriteWork->entryCount;
    entries = gSpriteWork->sortPtrs;
    mosaic = gSpriteWork->unk_2BAF;
    for (i = 0; i < count; i++) {
        entry = entries[i];
        parts = entry->unk_0C;
        affine = (ObjAffine*)entry->unk_08;
        partCount = *parts++;
        tileOffset = 0;
        if (mosaic != 0 && (entry->unk_16 & 0x10) == 0) {
            entry->unk_16 |= 8;
        }
        for (j = 0; j < partCount; j++) {
            attr0 = *parts++;
            attr1 = *parts++;
            attr2 = *parts++;
            y = attr0 & 0xFF;
            if (y & 0x80) {
                y = 0xFF ^ y;
                y = 0xFFFF ^ y;
            }
            x = attr1 & 0x1FF;
            if (x & 0x100) {
                x = 0x1FF ^ x;
                x = 0xFFFF ^ x;
            }
            EngineObjSize(attr0, attr1, &width, &height);
            if (affine != 0) {
                x += (s16)width >> 1;
                y += (s16)height >> 1;
                if (affine->angle != 0) {
                    angle = -affine->angle;
                    cosIndex = (angle + 64) & 255;
                    sinIndex = angle & 255;
                    xx = (s32)((u32)gSineTable[cosIndex] * x + (u32)gSineTable[sinIndex] * y);
                    yy = (s32)((u32)gSineTable[cosIndex + 64] * x + (u32)gSineTable[sinIndex + 64] * y);
                    xx = (s32)((u32)affine->sx * xx) >> 8;
                    yy = (s32)((u32)affine->sy * yy) >> 8;
                } else {
                    xx = (s32)((u32)affine->sx * x);
                    yy = (s32)((u32)affine->sy * y);
                }
                x = (s16)(xx >> 8) - ((s16)width >> 1);
                y = (s16)(yy >> 8) - ((s16)height >> 1);
                if (affine->unk_0A != 0) {
                    x -= (s16)width >> 1;
                    y -= (s16)height >> 1;
                    width *= 2;
                    height *= 2;
                }
                if (affine->unk_0A != 0) {
                    attr0 |= 0x300;
                } else {
                    attr0 |= 0x100;
                }
                attr1 |= affine->index << 9;
            } else {
                flip = entry->unk_16 & 2;
                if (flip) {
                    attr1 ^= flip << 12;
                    y = -y - height;
                }
                flip = entry->unk_16 & 1;
                if (flip) {
                    attr1 ^= flip << 12;
                    x = -x - width;
                }
            }
            x += entry->unk_10;
            y += entry->unk_12;
            if (x > 239 || x <= -(s16)width || y > 159 || y <= -(s16)height) {
                if (((ObjTiles*)entry->unk_00)->unk_24 != 0) {
                    tileOffset += GetObjTileCount(attr0, attr1);
                }
                continue;
            }
            oam[0] = (attr0 & 0xFF00) | (y & 0xFF);
            oam[1] = (attr1 & 0xFE00) | (x & 0x1FF);
            tiles = entry->unk_00;
            if (tiles->unk_24 != 0) {
                palette = (attr2 >> 12) + ((ObjPaletteNode*)entry->unk_04)->unk_06;
                oam[2] = (attr2 & 0xC00) | (tileOffset + tiles->unk_06) | (palette << 12);
                tileOffset += GetObjTileCount(oam[0], oam[1]);
            } else {
                palette = (attr2 >> 12) + ((ObjPaletteNode*)entry->unk_04)->unk_06;
                oam[2] = ((attr2 & 0xFFF) + tiles->unk_06) | (palette << 12);
            }
            oam[0] |= (entry->unk_16 & 8) << 9;
            oam[0] |= (entry->unk_16 & 4) << 8;
            oam[2] |= entry->unk_16 & 0xC00;
            oam += 4;
            emitted++;
        }
    }
    for (i = emitted; i < 128; i++) {
        *oam = 0x200;
        oam += 4;
    }
    gSpriteWork->entryCount = 0;
}
#else
INCLUDE_ASM("engine/func_08002F50.s");
#endif

void func_080034D8(u8 a) {
    gSpriteWork->unk_2BAF = a;
}

void SetObjMosaicSize(u8 a, u8 b) {
    a &= 0xF;
    b &= 0xF;
    gMosaic = (gMosaic & 0xFF) | (a << 8) | (b << 12);
}

void func_08003510(u8 a) {
    gSpriteWork->unk_2BAE = a;
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

u8 func_08003620(u16* oam, s16 x, s16 y) {
    u16 i;
    u16 n;
    u16 attr0;
    u16 attr1;
    s16 dx;
    s16 dy;
    s16 t;
    s16 w;
    s16 h;
    s16* pw;
    s16* ph;

    n = *oam++;

    for (i = 0; i < n; i++) {
        attr0 = *oam++;
        attr1 = *oam;
        oam += 2;
        dx = attr1 & 0x1FF;
        t = dx;

        if (t & 0x100) {
            dx = t ^ 0x1FF;
            dx = ~dx;
        }
        dy = attr0 & 0xFF;
        t = dy;

        if (t & 0x80) {
            dy = t ^ 0xFF;
            dy = ~dy;
        }
        x += dx;
        y += dy;
        pw = &w;
        ph = &h;

    switch (((attr1 << 16) | attr0) & 0xC000C000) {
    case 0x00000000:
        *pw = 8;
        *ph = 8;
        break;
    case 0x40000000:
        *pw = 16;
        *ph = 16;
        break;
    case 0x80000000:
        do {
            *pw = 32;
            *ph = 32;
        } while (0);
        break;
    case 0xC0000000:
        *pw = 64;
        *ph = 64;
        break;
    case 0x00004000:
        *pw = 16;
        *ph = 8;
        break;
    case 0x40004000:
        *pw = 32;
        *ph = 8;
        break;
    case 0x80004000:
        *pw = 32;
        *ph = 16;
        break;
    case 0xC0004000:
        *pw = 64;
        *ph = 32;
        break;
    case 0x00008000:
        *pw = 8;
        *ph = 16;
        break;
    case 0x40008000:
        *pw = 8;
        *ph = 32;
        break;
    case 0x80008000:
        *pw = 16;
        *ph = 32;
        break;
    case 0xC0008000:
        *pw = 32;
        *ph = 64;
        break;
    default:
        *pw = 0;
        *ph = 0;
        break;
    }


        if (x <= 239 && x > -w && y <= 159 && y > -h) {
            return 0;
        }
    }
    return 1;
}

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
ObjPaletteNode* AllocObjPalette(u16 size) {
    ObjPaletteNode* node;
    ObjPaletteNode* cur;
    ObjPaletteNode* next;
    s32 avail;
    s16 end;

    node = ListPoolFirstFree(&gSpriteWork->palettePool);
    if (node == 0) {
        return 0;
    }
    node->unk_20 = 2;
    node->unk_08 = size / 32;
    node->unk_00 = 0;
    node->refCount = 0;
    node->self = node;
    cur = ListPoolFirst(&gSpriteWork->palettePool);
    if (cur == 0) {
        node->unk_06 = gSpriteWork->palettePool.rangeStart;
        ListPoolActivate(node->unk_0C, &gSpriteWork->palettePool);
        return node;
    }
    node->unk_06 = gSpriteWork->palettePool.rangeStart;
    avail = cur->unk_06 - gSpriteWork->palettePool.rangeStart;
    if (node->unk_08 <= (s16)avail) {
        ListPoolActivateBefore(node->unk_0C, &gSpriteWork->palettePool, cur->unk_0C);
        return node;
    }

    for (;;) {
        if (cur == 0) {
            break;
        }
        next = ListPoolNext(cur->unk_0C);
        node->unk_06 = cur->unk_06 + cur->unk_08;
        if (node->unk_06 + node->unk_08 > gSpriteWork->palettePool.rangeEnd) {
            break;
        }

        if (next != 0) {
            end = next->unk_06 - node->unk_06;
        } else {
            end = gSpriteWork->palettePool.rangeEnd - node->unk_06;
        }

        if (node->unk_08 <= end) {
            ListPoolActivateAfter(node->unk_0C, &gSpriteWork->palettePool, cur->unk_0C);
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

    cur = ListPoolFirst(&gSpriteWork->tilePool);
    if (cur == 0) {
        return 1;
    }
    pos = gSpriteWork->tilePool.rangeStart;
    if (n <= (s16)(cur->unk_06 - pos)) {
        return 1;
    }

    for (;;) {
        if (cur == 0) {
            break;
        }
        next = ListPoolNext(cur->unk_0C);
        pos = cur->unk_06 + cur->unk_08;
        if ((s16)pos + n > gSpriteWork->tilePool.rangeEnd) {
            break;
        }

        if (next != 0) {
            end = next->unk_06 - pos;
        } else {
            end = gSpriteWork->tilePool.rangeEnd - pos;
        }

        if (n <= end) {
            return 1;
        }
        cur = next;
    }
    return 0;
}
u8 CanAllocObjPalette(u16 n) {
    ObjPaletteNode* cur;
    ObjPaletteNode* next;
    u16 pos;
    s16 end;

    cur = ListPoolFirst(&gSpriteWork->palettePool);
    if (cur == 0) {
        return 1;
    }
    pos = gSpriteWork->palettePool.rangeStart;
    if (n <= (s16)(cur->unk_06 - pos)) {
        return 1;
    }

    for (;;) {
        if (cur == 0) {
            break;
        }
        next = ListPoolNext(cur->unk_0C);
        pos = cur->unk_06 + cur->unk_08;
        if ((s16)pos + n > gSpriteWork->palettePool.rangeEnd) {
            break;
        }

        if (next != 0) {
            end = next->unk_06 - pos;
        } else {
            end = gSpriteWork->palettePool.rangeEnd - pos;
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

void func_08003CD4(UnkSpline* p, s32* d, s32* xs, s32* e) {
    s32* a;
    s32* b;
    s32 n;
    s32 i;
    s32 q;

    n = p->unk_00;
    a = p->unk_04;
    b = p->unk_08;
    e[0] = 0;
    e[n - 1] = 0;

    for (i = 0; i < n - 1; i++) {
        a[i] = d[i + 1] - d[i];
        b[i + 1] = ((xs[i + 1] - xs[i]) << 8) / a[i];
    }
    e[1] = (b[2] - b[1]) - ((a[0] * e[0]) >> 8);
    b[1] = (d[2] - d[0]) << 1;

    for (i = 1; i < n - 2; i++) {
        q = (a[i] << 8) / b[i];
        e[i + 1] = (b[i + 2] - b[i + 1]) - ((e[i] * q) >> 8);
        b[i + 1] = ((d[i + 2] - d[i]) << 1) - ((q * a[i]) >> 8);
    }
    e[n - 2] -= (a[n - 2] * e[n - 1]) >> 8;

    for (i = n - 2; i > 0; i--) {
        e[i] = ((e[i] - ((a[i] * e[i + 1]) >> 8)) << 8) / b[i];
    }
}
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
void func_08003ED4(UnkSpline* p, s32* xs, s32* ys, s16 n) {
    s32 i;
    s32 len;
    s32* d;
    s32* e;
    s32* f;
    s32 dx;
    s32 dy;
    s32 size;

    size = n * 4;
    len = 0;
    p->unk_00 = n;
    p->unk_04 = EwramAlloc(size);
    p->unk_08 = EwramAlloc(size);
    p->unk_0C = EwramAlloc(size);
    p->unk_10 = EwramAlloc(size);
    p->unk_14 = EwramAlloc(size);
    p->unk_18 = xs;
    p->unk_1C = ys;
    d = p->unk_0C;
    e = p->unk_10;
    f = p->unk_14;
    d[0] = len;

    for (i = 1; i < n; i++) {
        dx = xs[i] - xs[i - 1];
        dy = ys[i] - ys[i - 1];
        d[i] = d[i - 1] + func_08003C9C(((dx * dx) >> 8) + ((dy * dy) >> 8));
    }

    for (i = 1; i < n; i++) {
        d[i] = (d[i] << 8) / d[n - 1];
    }

    func_08003CD4(p, d, xs, e);
    func_08003CD4(p, d, ys, f);
}

void func_08003FCC(UnkSpline* p, s32 v, s32* outX, s32* outY) {
    *outX = func_08003E2C(&p->unk_00, v, p->unk_0C, p->unk_18, p->unk_10);
    *outY = func_08003E2C(&p->unk_00, v, p->unk_0C, p->unk_1C, p->unk_14);
}

void func_0800400C(UnkSpline* p) {
    EwramFree(p->unk_04);
    EwramFree(p->unk_08);
    EwramFree(p->unk_0C);
    EwramFree(p->unk_10);
    EwramFree(p->unk_14);
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

void VTransInit(void) {
    u32 zero;

    SetIwramHeapName(sVTransHeapName);
    gDma3Requests = IwramAlloc(sizeof(Dma3Queue));
    zero = 0;
    CpuSet(&zero, gDma3Requests, 0x05000000 | (sizeof(Dma3Queue) / 4));
}

void VTransFree(void) {
    IwramFree(gDma3Requests);
}

void VTransReset(void) {
    Dma3Queue* q = gDma3Requests;

    q->requestCount = 0;
    q->unk_10A2 = 0;
    q->unk_10A4 = 0;
    q->unk_10A6 = 0;
    q->count = 0;
#ifdef VERSION_EU
    q->unk_10AA = 0;
#endif
    q->unk_10AC = 0;
}

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
void LZ77UnCompVram(void* src, void* dst);

u8 eu_080044C0(void* src, void* dst) {
    Dma3Queue* q = gDma3Requests;
    u16 flags;
    if (q->unk_10AA > 31) {
        return 0;
    }
    flags = gSystemFlags & 8;
    if (flags == 0) {
        q->unkEu_10A0[q->unk_10AA].src = src;
        q->unkEu_10A0[q->unk_10AA].dst = dst;
        q->unkEu_10A0[q->unk_10AA].size = flags;
        q->unk_10AA++;
    } else {
        LZ77UnCompVram(src, dst);
    }
    return 1;
}
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
u8 func_0800448C(void* src, void* dst, u8 x, u8 y, u8 w, u8 h, s8 sw, s8 sh) {
    if (gDma3Requests->unk_10A2 > 63) {
        return 0;
    }

    if (sw <= 0 || sh <= 0) {
        return 0;
    }
    gDma3Requests->unk_0C00[gDma3Requests->unk_10A2].unk_00 = src;
    gDma3Requests->unk_0C00[gDma3Requests->unk_10A2].unk_04 = dst;
    gDma3Requests->unk_0C00[gDma3Requests->unk_10A2].unk_08 = x;
    gDma3Requests->unk_0C00[gDma3Requests->unk_10A2].unk_09 = y;
    gDma3Requests->unk_0C00[gDma3Requests->unk_10A2].unk_0A = w;
    gDma3Requests->unk_0C00[gDma3Requests->unk_10A2].unk_0B = h;
    gDma3Requests->unk_0C00[gDma3Requests->unk_10A2].unk_0C = sw;
    gDma3Requests->unk_0C00[gDma3Requests->unk_10A2].unk_0D = sh;
    gDma3Requests->unk_10A2 = gDma3Requests->unk_10A2 + 1;
    return 1;
}

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

u8 func_08004678(void* a) {
    Dma3Queue* q = gDma3Requests;

    if (q->unk_10A6 > 7) {
        return 0;
    }
    q->unk_1060[q->unk_10A6] = a;
    q->unk_10A6 = q->unk_10A6 + 1;

    return 1;
}

u32 func_080046B4(void) {
    Dma3Queue* q = gDma3Requests;

    return q->unk_10AC;
}

#ifdef NON_MATCHING
void FlushDma3Queue(void) {
    Dma3Queue* q;
    Dma3Request* req;
    Dma3Blit* blits;
    Dma3Fill* fills;
    Dma3Fill* f;
    s32 sy;
    s32 dy;
    Dma3Pending* pend;
    void (**cb)(void);
    void (**p)(void);
    u16 n;
    s32 i;
    s32 j;
    s32 row;
    s32 col;
    u16 zero;
    vu32* dma;
#ifdef VERSION_EU
    Dma3Request* compressed;
#endif

    q = gDma3Requests;
    req = q->requests;
    blits = q->unk_0C00;
    fills = q->unk_1000;
    cb = (void (**)(void))q->unk_1060;
    pend = q->pending;
#ifdef VERSION_EU
    compressed = q->unkEu_10A0;
#endif
    q->unk_10AC = 0;
    n = q->unk_10A6;

    if (n != 0) {
        i = n;
        p = cb;
        do {
            (*p++)();
        } while (--i);
    }
    gDma3Requests->unk_10A6 = 0;
    n = gDma3Requests->requestCount;

    if (n != 0) {
        i = n;
        do {
            dma = (vu32*)0x040000D4;
            dma[0] = (u32)req->src;
            dma[1] = (u32)req->dst;
            dma[2] = (req->size >> 1) | 0x80000000;
            dma[2];
            gDma3Requests->unk_10AC += req->size;
            req++;
        } while (--i);
    }
    gDma3Requests->requestCount = 0;
#ifdef VERSION_EU
    n = gDma3Requests->unk_10AA;
    if (n != 0) {
        i = n;
        do {
            LZ77UnCompVram(compressed->src, compressed->dst);
            compressed++;
        } while (--i);
    }
    gDma3Requests->unk_10AA = 0;
#endif
    n = gDma3Requests->unk_10A4;

    for (i = 0; i < n; i++) {
        if (fills[i].unk_0A != 0) {
            f = &fills[i];

            for (j = 0; j < 32; j++) {
                ((u16*)f->unk_04)[(((f->unk_09 + j) & 31) << 5) + f->unk_08] = ((u16*)f->unk_00)[j];
            }
        } else {
            f = &fills[i];

            for (j = 0; j < 32; j++) {
                ((u16*)f->unk_04)[(f->unk_09 << 5) + ((f->unk_08 + j) & 31)] = ((u16*)f->unk_00)[j];
            }
        }
    }
    gDma3Requests->unk_10A4 = 0;
    n = gDma3Requests->unk_10A2;

    for (i = 0; i < n; i++) {
        for (row = 0; row < blits[i].unk_0D; row++) {
            sy = ((blits[i].unk_09 + row) & 31) << 5;
            dy = ((blits[i].unk_0B + row) & 31) << 5;

            for (col = 0; col < blits[i].unk_0C; col++) {
                ((u16*)blits[i].unk_04)[((blits[i].unk_0A + col) & 31) + dy] = ((u16*)blits[i].unk_00)[((blits[i].unk_08 + col) & 31) + sy];
            }
        }
    }
    gDma3Requests->unk_10A2 = 0;
    n = gDma3Requests->count;

    if (n != 0) {
        i = n;
        do {
            zero = 0;
            dma = (vu32*)0x040000D4;
            dma[0] = (u32)&zero;
            dma[1] = (u32)pend->unk_00;
            dma[2] = (pend->unk_04 >> 1) | 0x81000000;
            dma[2];
            gDma3Requests->unk_10AC += pend->unk_04;
            pend++;
        } while (--i);
    }
    gDma3Requests->count = 0;
}
#else
INCLUDE_ASM("engine/FlushDma3Queue.s");
#endif
#ifdef NON_MATCHING
void func_08004938(void) {
    Dma3Queue* q;
    Dma3Request* req;
    Dma3Blit* blits;
    Dma3Fill* fills;
    Dma3Fill* f;
    s32 sy;
    s32 dy;
    Dma3Pending* pend;
    void (**cb)(void);
    void (**p)(void);
    u16 n;
    s32 i;
    s32 row;
    s32 col;
    s32 sourceIndex;
    u16 zero;
#ifdef VERSION_EU
    Dma3Request* compressed;
#endif

    q = gDma3Requests;
    req = q->requests;
    blits = q->unk_0C00;
    fills = q->unk_1000;
    cb = (void (**)(void))q->unk_1060;
    pend = q->pending;
#ifdef VERSION_EU
    compressed = q->unkEu_10A0;
#endif
    q->unk_10AC = 0;
    n = q->unk_10A6;

    if (n != 0) {
        p = cb;
        i = n;
        do {
            (*p++)();
        } while (--i);
    }
    gDma3Requests->unk_10A6 = 0;
    n = gDma3Requests->requestCount;

    if (n != 0) {
        i = n;
        do {
            CpuSet(req->src, req->dst, req->size >> 1);
            gDma3Requests->unk_10AC += req->size;
            req++;
        } while (--i);
    }
    gDma3Requests->requestCount = 0;
#ifdef VERSION_EU
    n = gDma3Requests->unk_10AA;
    if (n != 0) {
        i = n;
        do {
            LZ77UnCompVram(compressed->src, compressed->dst);
            compressed++;
        } while (--i);
    }
    gDma3Requests->unk_10AA = 0;
#endif
    n = gDma3Requests->unk_10A4;

    for (i = 0; i < n; i++) {
        if (fills[i].unk_0A != 0) {
            row = 0;
            f = &fills[i];

            for (; row < 32; row++) {
                ((u16*)f->unk_04)[(((f->unk_09 + row) & 31) << 5) + f->unk_08] = ((u16*)f->unk_00)[row];
            }
        } else {
            col = 0;
            f = &fills[i];

            for (; col < 32; col++) {
                ((u16*)f->unk_04)[((f->unk_08 + col) & 31) + (f->unk_09 << 5)] = ((u16*)f->unk_00)[col];
            }
        }
    }
    gDma3Requests->unk_10A4 = 0;
    n = gDma3Requests->unk_10A2;

    for (i = 0; i < n; i++) {
        for (row = 0; row < blits[i].unk_0D; row++) {
            sy = ((blits[i].unk_09 + row) & 31) << 5;
            dy = ((blits[i].unk_0B + row) & 31) << 5;

            for (col = 0; col < blits[i].unk_0C; col++) {
                sourceIndex = (blits[i].unk_08 + col) & 31;
                ((u16*)blits[i].unk_04)[((blits[i].unk_0A + col) & 31) + dy] = ((u16*)blits[i].unk_00)[sourceIndex + sy];
            }
        }
    }
    gDma3Requests->unk_10A2 = 0;
    n = gDma3Requests->count;

    if (n != 0) {
        i = n;
        do {
            zero = 0;
            CpuSet(&zero, pend->unk_00, (pend->unk_04 >> 1) | 0x01000000);
            gDma3Requests->unk_10AC += pend->unk_04;
            pend++;
        } while (--i);
    }
    gDma3Requests->count = 0;
}
#else
INCLUDE_ASM("engine/func_08004938.s");
#endif

void BgInit(void) {
    BgEntry** p;
    u32 zero;

    SetIwramHeapName(sBgHeapName);
    p = &gBgEntries;
    *p = IwramAlloc(BG_ENTRY_COUNT * sizeof(BgEntry));
    zero = 0;
    CpuSet(&zero, *p, 0x05000000 | (BG_ENTRY_COUNT * sizeof(BgEntry) / 4));
}

void BgFree(void) {
    IwramFree(gBgEntries);
}

void* func_08004BD8(BgEntry* e, u16 x, u16 y) {
    u8 col = (x >> 8) % e->unk_08;
    u8 row = (y >> 8) % e->unk_09;

    return ((void**)e->unk_04)[e->unk_08 * row + col];
}

void func_08004C20(u16 x, u16 y, BgEntry* e, void* dst, u8 sx, u8 sy, u8 w, u8 h) {
    u8 tx;
    u8 ty;
    s8 w1;
    s8 w2;
    s8 h1;
    s8 h2;
    u16 x2;
    u16 y2;
    u8 sx2;
    u8 sy2;
    s32 ox;
    s32 oy;

    tx = (x & 0xFF) >> 3;
    ty = (y & 0xFF) >> 3;
    w1 = 32 - tx;

    if (w1 >= w) {
        w1 = w;
        w2 = 0;
    } else {
        w2 = w - w1;
    }
    h1 = 32 - ty;

    if (h1 >= h) {
        h1 = h;
        h2 = 0;
    } else {
        h2 = h - h1;
    }
    func_0800448C(func_08004BD8(e, x, y), dst, tx, ty, sx, sy, w1, h1);
    x2 = x + 256;
    func_0800448C(func_08004BD8(e, x2, y), dst, 0, ty, sx2 = sx - (ox = tx - 32), sy, w2, h1);
    y2 = y + 256;
    func_0800448C(func_08004BD8(e, x, y2), dst, tx, 0, sx, sy2 = sy - (oy = ty - 32), w1, h2);
    func_0800448C(func_08004BD8(e, x2, y2), dst, 0, 0, sx2, sy2, w2, h2);
}

void BgReset(void) {
#ifdef VERSION_EU
    u32 zero;

    zero = 0;
    CpuSet(&zero, gBgEntries, 0x05000000 | (BG_ENTRY_COUNT * sizeof(BgEntry) / 4));
#endif
    gBackdropColor = 0;
    DisableBg(0);
    DisableBg(1);
    DisableBg(2);
    DisableBg(3);
    SetBgMosaicSize(0, 0);
    gBldCnt = 0;
}

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
        s32 o = i * sizeof(BgEntry);
        p += 4;
        p += o;
        *(void**)p = 0;
    }
}

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
        s32 o = i * sizeof(BgEntry);
        p += 4;
        p += o;
        *(void**)p = 0;
    }
}

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
        s32 o = i * sizeof(BgEntry);
        p += 4;
        p += o;
        *(void**)p = 0;
    }
}

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
    ofs = bg * sizeof(BgEntry);
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
#ifdef NON_MATCHING
void func_08005244(s32 bg, u16 x, u16 y) {
    BgEntry* e;
    s8 dx;
    s8 dy;
    u32 sx;
    u32 sy;
    s32 tx;
    s32 ty;
    s32 cx;
    s32 cy;
    void* dst;

    e = &gBgEntries[bg];
    if (e->unk_04 == 0) {
        return;
    }

    if (e->unk_00 != 0) {
        func_080051C4(bg, x, y);
        return;
    }
    dx = (x >> 3) - (e->unk_0A >> 3);
    dy = (y >> 3) - (e->unk_0C >> 3);

    if (abs(dx) > 29 || abs(dy) > 19) {
        func_080051C4(bg, x, y);
        return;
    }
    sx = GetBgScrollX(bg);
    sy = GetBgScrollY(bg);
    SetBgScroll(bg, (u16)(sx + (x - e->unk_0A)), (u16)(sy + (y - e->unk_0C)));

    if (dx != 0 || dy != 0) {
        dst = (void*)(((*gBgControl[bg] & 0x1F00) << 3) + 0x06000000);
        tx = sx >> 3;
        ty = sy >> 3;
        cx = GetBgScrollX(bg) >> 3;
        cy = GetBgScrollY(bg) >> 3;

        if (dx > 0) {
            if (dx > 31) {
                dx = 31;
            }
            func_08004C20(e->unk_0A + 248, y, e, dst, tx + 31, cy, dx, 21);
        } else if (dx < 0) {
            dx = -dx;

            if (dx > 31) {
                dx = 31;
            }
            func_08004C20(e->unk_0A - (dx << 3), y, e, dst, tx - dx, cy, dx, 21);
        }

        if (dy > 0) {
            if (dy > 21) {
                dy = 21;
            }
            func_08004C20(x, e->unk_0C + 168, e, dst, cx, ty + 21, 31, dy);
        } else if (dy < 0) {
            dy = -dy;

            if (dy > 21) {
                dy = 21;
            }
            func_08004C20(x, e->unk_0C - (dy << 3), e, dst, cx, ty - dy, 31, dy);
        }
    }
    e->unk_0A = x;
    e->unk_0C = y;
}
#else
INCLUDE_ASM("engine/func_08005244.s");
#endif

u16 func_08005458(s32 bg) {
    BgEntry* e = &gBgEntries[bg];

    if (e->unk_04 == 0) {
        return 0;
    }
    return e->unk_0A;
}

u16 func_08005474(s32 bg) {
    BgEntry* e = &gBgEntries[bg];

    if (e->unk_04 == 0) {
        return 0;
    }
    return e->unk_0C;
}

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
u8 eu_080044C0(void* src, void* dst);

void eu_080059D4(s32 bg, void* src) {
    EnableBg(bg);
    eu_080044C0(src, GetBgCharBase(bg));
}

void eu_080059F4(s32 bg, void* src) {
    EnableBg(bg);
    eu_080044C0(src, GetBgScreenBase(bg));
}

u32 eu_08005A14(u32* src) {
    return *src >> 8;
}

void LZ77UnCompWram(void* src, void* dst);

u8 eu_08005A1C(s32 bg, void* src, u8 w, u8 h) {
    BgEntry* e;
    s32 count;
    s32 i;
    if ((gDispCnt & 7) != 0 && (bg == 2 || bg == 3)) {
        return 0;
    }
    e = &gBgEntries[bg];
    if (e->unkEu_10 != 0) {
        return 0;
    }
    count = w * h;
    e->unkEu_10 = EwramAlloc(count * sizeof(void*));
    if (e->unkEu_10 == 0) {
        return 0;
    }
    for (i = 0; i < count; i++) {
        e->unkEu_10[i] = EwramAlloc(eu_08005A14(((u32**)src)[i]));
        if (e->unkEu_10[i] == 0) {
            return 0;
        }
        LZ77UnCompWram(((u32**)src)[i], e->unkEu_10[i]);
    }
    EnableBg(bg);
    e->unk_04 = e->unkEu_10;
    e->unk_08 = w;
    e->unk_09 = h;
    e->unk_0A = 0;
    e->unk_0C = 0;
    e->unk_00 = 1;
    return 1;
}

void eu_08005ADC(s32 bg) {
    BgEntry* e = &gBgEntries[bg];
    s32 count;
    s32 i;
    if (e->unkEu_10 != 0) {
        count = e->unk_08 * e->unk_09;
        for (i = 0; i < count; i++) {
            EwramFree(e->unkEu_10[i]);
        }
        EwramFree(e->unkEu_10);
        e->unkEu_10 = 0;
    }
}
#endif

s16 GetAngleDiff(s32 a, s32 b) {
    s32 x = a & 0xFF;
    s32 y = b & 0xFF;
    s32 d = x - y;

    if (d <= -0x80) {
        return (x + 0x100) - y;
    }

    if (d > 0x7F) {
        return (x + 0xFFFFFF00) - y;
    }
    return d;
}


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
    gFadeWork = IwramAlloc(sizeof(FadeWork));
    zero = 0;
    CpuSet(&zero, gFadeWork, 0x05000000 | (sizeof(FadeWork) / 4));
}

void FadeFree(void) {
    IwramFree(gFadeWork);
}

void FadeReset(void) {
    u32 zero = 0;

    CpuSet(&zero, gFadeWork, 0x05000000 | (sizeof(FadeWork) / 4));
}

void LoadPalette(void* src, void* dst, u16 size) {
    PaletteSlot* base;
    s32 idx;
    s32 count;
    s32 i;

    base = gFadeWork->slots;
    count = (u16)size / 32;
    idx = ((s32)dst - 0x05000000) / 32;
    src = LoadPaletteWithEffect(src, dst, size);

    for (i = 0; i < count; i++) {
        base[idx + i].unk_00 = (u8*)src + i * 32;
        base[idx + i].unk_04 = (u8*)dst + i * 32;
        base[idx + i].unk_29 = 1;
    }
}


void func_08005C60(u16 a) {
    PaletteSlot* p = gFadeWork->slots;

    p += a;
    p->unk_00 = 0;
}


void func_08005C78(void) {
    s32 i;
    s32 j;
    s32 changed;
    u16 amount;
    PaletteSlot* slot;
    u16* src;
    u16* dst;
    s16 r;
    s16 g;
    s16 b;
    s16 gray;
    s16 red;
    s16 green;
    s16 blue;
    u16 color;

    if (gFadeWork->unk_584 != 0 || gFadeWork->unk_580 != 0) {
        changed = gFadeWork->unk_580 != gFadeWork->unk_588;
        amount = gFadeWork->unk_580 >> 8;
        for (i = 0; i < 32; i++) {
            slot = &gFadeWork->slots[i];
            src = slot->unk_00;
            if (src == 0) {
                continue;
            }
            if (slot->unk_28 != 0 && (gFadeWork->unk_594 & 2) == 0) {
                continue;
            }
            if (slot->unk_29 != 0) {
                slot->unk_29 = 0;
            } else if (!changed) {
                continue;
            }
            dst = (u16*)slot->unk_08;
            for (j = 0; j < 16; j++) {
                color = *src++;
                r = color & 31;
                g = (color >> 5) & 31;
                b = (color >> 10) & 31;
                switch (gFadeWork->unk_590) {
                case 0:
                    r -= amount;
                    g -= amount;
                    b -= amount;
                    if (r < 0) r = 0;
                    if (g < 0) g = 0;
                    if (b < 0) b = 0;
                    break;
                case 1:
                    if (r < amount) r = amount;
                    if (g < amount) g = amount;
                    if (b < amount) b = amount;
                    break;
                case 3:
                    r += amount;
                    g -= amount;
                    b -= amount;
                    if (r > 31) r = 31;
                    if (g < 0) g = 0;
                    if (b < 0) b = 0;
                    break;
                case 5:
                    r -= amount;
                    g += amount;
                    b -= amount;
                    if (r < 0) r = 0;
                    if (g > 31) g = 31;
                    if (b < 0) b = 0;
                    break;
                case 4:
                    r -= amount;
                    g -= amount;
                    b += amount;
                    if (r < 0) r = 0;
                    if (g < 0) g = 0;
                    if (b > 31) b = 31;
                    break;
                case 2:
                    r += amount;
                    g += amount;
                    b += amount;
                    if (r > 31) r = 31;
                    if (g > 31) g = 31;
                    if (b > 31) b = 31;
                    break;
                case 6:
                    gray = ((r + g + b) >> 2) * amount;
                    r = (gray + r * (31 - amount)) >> 5;
                    g = (gray + g * (31 - amount)) >> 5;
                    b = (gray + b * (31 - amount)) >> 5;
                    break;
                case 7:
                    red = (31 - r) * amount;
                    green = (31 - g) * amount;
                    blue = (31 - b) * amount;
                    r = (red + r * (31 - amount)) / 31;
                    g = (green + g * (31 - amount)) / 31;
                    b = (blue + b * (31 - amount)) / 31;
                    break;
                case 8:
                    gray = 31 * amount;
                    if ((r + g + b) / 3 > 12) {
                        r = (gray + r * (31 - amount)) / 31;
                        g = (gray + g * (31 - amount)) / 31;
                        b = (gray + b * (31 - amount)) / 31;
                    } else {
                        r = r * (31 - amount) / 31;
                        g = g * (31 - amount) / 31;
                        b = b * (31 - amount) / 31;
                    }
                    break;
                case 9:
                    r -= amount;
                    g -= amount * 2;
                    b -= amount;
                    if (r < 0) r = 0;
                    if (g < 0) g = 0;
                    if (b < 0) b = 0;
                    break;
                case 10:
                    r -= amount;
                    g -= amount * 2;
                    b -= amount * 2;
                    if (r < 0) r = 0;
                    if (g < 0) g = 0;
                    if (b < 0) b = 0;
                    break;
                }
                *dst++ = b * 1024 | g * 32 | r;
            }
            RequestDma3Copy(slot->unk_08, slot->unk_04, 32);
        }
    }
    gFadeWork->unk_588 = gFadeWork->unk_580;
    if (gFadeWork->unk_58C != 0) {
        if ((gFadeWork->unk_594 & 4) == 0) {
            ApproachValue((s32*)&gFadeWork->unk_580, gFadeWork->unk_584, gFadeWork->unk_58C);
            gFadeWork->unk_58C--;
        }
        if (gFadeWork->unk_58C == 0 && gFadeWork->unk_580 == 0) {
            for (i = 0; i < 32; i++) {
                slot = &gFadeWork->slots[i];
                RequestDma3Copy(slot->unk_00, slot->unk_04, 32);
            }
        }
    } else {
        gFadeWork->unk_594 = 0;
    }
}
void func_08006120(s32 a, u16 b) {
    FadeWork* base = gFadeWork;
    u32 z;

    if (base->unk_594 & 2) {
        if (base->unk_594 & 1) {
            return;
        }
    }
    z = 0;
    base->unk_594 = 1;
    base->unk_58C = b;
    base->unk_580 = 0x1F00;
    base->unk_584 = z;
    base->unk_588 = z;
    base->unk_590 = a;
}
void func_08006184(s32 a, u16 b) {
    FadeWork* base = gFadeWork;
    u32 z;

    if (base->unk_594 & 2) {
        if (base->unk_594 & 1) {
            return;
        }
    }
    z = 0;
    base->unk_594 = 1;
    base->unk_58C = b;
    base->unk_580 = z;
    base->unk_584 = 0x1F00;
    base->unk_588 = z;
    base->unk_590 = a;
}
void func_080061E8(s32 a, u16 b) {
    FadeWork* base = gFadeWork;
    u32 z;

    if (base->unk_594 & 2) {
        if (base->unk_594 & 1) {
            return;
        }
    }
    z = 0;
    base->unk_594 = 1;
    base->unk_58C = b;
    base->unk_584 = z;
    base->unk_590 = a;
}

void func_08006238(s32 a, u16 b, u16 c) {
    FadeWork* base = gFadeWork;

    if (base->unk_594 & 2) {
        if (base->unk_594 & 1) {
            return;
        }
    }
    base->unk_594 = 1;
    base->unk_58C = c;
    base->unk_584 = b << 8;
    base->unk_590 = a;
}

void func_08006290(s32 a, u16 b, u16 c) {
    FadeWork* base = gFadeWork;
    u32 z;

    if (base->unk_594 & 2) {
        if (base->unk_594 & 1) {
            return;
        }
    }
    z = 0;
    base->unk_594 = 1;
    base->unk_58C = c;
    base->unk_580 = b << 8;
    base->unk_588 = z;
    base->unk_584 = z;
    base->unk_590 = a;
}

void func_080062F4(u16 slot, u8 value) {
    PaletteSlot* p;

    if (slot > 0x1F) {
        return;
    }
    p = gFadeWork->slots;
    p += slot;
    p->unk_28 = value;
}

u8 func_08006314(void) {
    if (gFadeWork->unk_594 & 1) {
        return 1;
    }
    return 0;
}

u16 _08006338(void) {
    switch (gFadeWork->unk_590) {
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
    return gFadeWork->unk_580 >> 8;
}

void func_080063A8(void) {
    u16 v = gFadeWork->unk_594 | 2;

    gFadeWork->unk_594 = v;
}

void func_080063C4(u8 on) {
    if (on) {
        u16 v = gFadeWork->unk_594 | 4;

        gFadeWork->unk_594 = v;
    } else {
        gFadeWork->unk_594 &= 0xFFFB;
    }
}

void MosaicReset(void) {
    gUnk_0203401C = 0;
    gUnk_02034020 = 0;
    gUnk_02034024 = 0;
    gMosaicActive = 0;
}

void MosaicUpdate(void) {
    s16 t;
    u8 v;

    if (gUnk_02034024 != 0) {
        ApproachValue((s32*)&gUnk_0203401C, gUnk_02034020, gUnk_02034024--);
        t = gUnk_0203401C >> 8;
        v = t;
        SetBgMosaicSize(v, v);
        SetObjMosaicSize(v, v);
    } else if (gMosaicActive != 0) {
        gMosaicActive = 0;
        func_080034D8(0);
    }
}

void func_08006494(u16 a, u16 b) {
    gUnk_02034024 = a;
    gUnk_0203401C = b << 8;
    gUnk_02034020 = 0;
    gMosaicActive = 1;
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
    gMosaicActive = 1;
    SetBgMosaic(0, 1);
    SetBgMosaic(1, 1);
    SetBgMosaic(2, 1);
    SetBgMosaic(3, 1);
    func_080034D8(1);
}

u8 MosaicIsActive(void) {
    return gMosaicActive;
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
        gUnk_02034050 = (gUnk_02034040->unk_10 << 2) - x;
        gUnk_02034052 = (gUnk_02034040->unk_12 << 2) - y;
    }
}

void func_0800675C(u8 a, s32 b, s32 c) {
    gUnk_02034064 = a;
    gUnk_0203405C = b;
    gUnk_02034060 = c;
}

void func_08006778(UnkBgAnim* a, s32 x, s32 y) {
    gUnk_02034040 = a;
    func_080066F4((s16)x, (s16)y);

    if (gUnk_02034058 != 0) {
        gUnk_0203404C = a->unk_0E << 6;
    } else {
        gUnk_0203404C = a->unk_0E << 5;
    }
    gUnk_0203404E = 0x8000 / gUnk_0203404C;
    gUnk_02034066 = -1;
    gUnk_02034068 = -1;
    gUnk_02034044 = 0;
    gUnk_02034046 = 0;
    gUnk_02034054 = 0;
    gUnk_0203406A = a->unk_16;

    if (gUnk_02034058 != 0) {
        gUnk_0203405C = 0x100;
        gUnk_02034060 = 0x100;
        gUnk_02034064 = 0;
    }
    PushPaletteEffect(0);
    LoadBgPalette(gUnk_02034048, a->unk_08, a->unk_0C);
    PopPaletteEffect();
    LoadBgMap(gUnk_02034048, a->unk_04, gUnk_02034056);
}
void func_0800685C(s32 bg, u8 rot, s32 sx, s32 sy, s16 cx, s16 cy) {
    BgAffineSrcData src;
    BgAffineDstData dst;

    src.texX = gUnk_02034040->unk_10 << 10;
    src.texY = gUnk_02034040->unk_12 << 10;
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
void func_08006954(void) {
    u8* src;
    u16 q;
    u16 off;
    u16 len;
    s16 over;
    s32 vis;

    if (gUnk_02034040 == 0) {
        return;
    }

    if (gUnk_02034046 >= gUnk_02034040->unk_14) {
        if (gUnk_02034066 >= 0) {
            gUnk_02034046 = gUnk_02034066;
            gUnk_02034044 = 0;
        } else {
            func_08006B4C();
        }
        return;
    }

    if (gUnk_02034058 != 0) {
        func_0800685C(gUnk_02034048, gUnk_02034064, gUnk_0203405C, gUnk_02034060, gUnk_02034050, gUnk_02034052);
        vis = 1;
    } else {
        SetBgScroll(gUnk_02034048, (u16)gUnk_02034050, (u16)gUnk_02034052);
        if (gUnk_02034050 > -256 && gUnk_02034050 < 128 && gUnk_02034052 < 128 && gUnk_02034052 > -256) {
            vis = 1;
        } else {
            vis = 0;
        }
    }

    if (vis != 0) {
        EnableBg(gUnk_02034048);

        if (gUnk_02034044 == 0) {
            q = gUnk_02034046 / gUnk_0203404E;
            off = gUnk_02034046 % gUnk_0203404E * gUnk_0203404C;
            src = (u8*)gUnk_02034040->unk_00[q].unk_00 + off;
            over = off + gUnk_0203404C - gUnk_02034040->unk_00[q].unk_04;

            if (over > 0) {
                len = gUnk_0203404C - over;
                RequestDma3Copy(src, GetBgCharBase(gUnk_02034048), len);
                func_0800443C((u8*)GetBgCharBase(gUnk_02034048) + len, over);
            } else {
                RequestDma3Copy(src, GetBgCharBase(gUnk_02034048), gUnk_0203404C);
            }
        }
    } else {
        DisableBg(gUnk_02034048);
    }
    gUnk_02034044++;

    if (gUnk_02034044 >= gUnk_0203406A) {
        gUnk_02034044 = 0;

        if (gUnk_02034046 != gUnk_02034068) {
            gUnk_02034046++;
        }
    }
}

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
