#include "gba/syscall.h"
#include "listpool.h"
#include "malloc.h"
#include "sprite.h"

SpriteWork* gSpriteWork;

extern u8 sSpriteHeapName[];

extern u16 gDispCnt;

void SetObjMosaicSize(u8 a, u8 b);

void EnableObj(void);
void DisableObj(void);
void SetObjTileRange(u16 a, u16 b);
void SetObjPaletteRange(u16 a, u16 b);

void SpriteInit(void) {
    u32 zero;

    SetIwramHeapName(sSpriteHeapName);
    gSpriteWork = IwramAlloc(sizeof(SpriteWork));
    zero = 0;
    CpuSet(&zero, gSpriteWork, 0x05000000 | (sizeof(SpriteWork) / 4));
}

void SpriteFree(void) {
    IwramFree(gSpriteWork);
}

u16 GetObjTileCount(u16 a, u16 b) {
    switch ((((u32)b << 16) | a) & 0xC000C000) {
    case 0x00000000:
        return 1;
    case 0x80000000:
        return 0x10;
    case 0xC0000000:
        return 0x40;
    case 0x00004000:
    case 0x00008000:
        return 2;
    case 0x40000000:
    case 0x40004000:
    case 0x40008000:
        return 4;
    case 0x80004000:
    case 0x80008000:
        return 8;
    case 0xC0004000:
    case 0xC0008000:
        return 0x20;
    }
    return 0;
}

void SortSpriteEntries(SpriteEntry** arr, s32 lo, s32 hi) {
    SpriteEntry* t;
    u16 pivot;
    s32 i;
    s32 j;

    pivot = arr[(lo + hi) >> 1]->unk_14;
    i = lo;
    j = hi;

    for (;;) {
        while (arr[i]->unk_14 < pivot) {
            i++;
        }
        while (pivot < arr[j]->unk_14) {
            j--;
        }
        if (i >= j) {
            break;
        }
        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
        i++;
        j--;
    }
    if (lo < i - 1) {
        SortSpriteEntries(arr, lo, i - 1);
    }
    if (j + 1 < hi) {
        SortSpriteEntries(arr, j + 1, hi);
    }
}

void EnableObj(void) {
    gDispCnt |= 0x1000;
}

void DisableObj(void) {
    gDispCnt &= 0xEFFF;
}

void SetObjTileRange(u16 a, u16 b) {
    s32 v;

    gSpriteWork->tilePool.rangeStart = a;
    v = a + b;
    gSpriteWork->tilePool.rangeEnd = v;

    if ((u16)v > 0x400) {
        gSpriteWork->tilePool.rangeEnd = 0x400;
    }
}

void SetObjPaletteRange(u16 a, u16 b) {
    s32 v;

    gSpriteWork->palettePool.rangeStart = a;
    v = a + b;
    gSpriteWork->palettePool.rangeEnd = v;

    if ((u16)v > 0x10) {
        gSpriteWork->palettePool.rangeEnd = 0x10;
    }
}

void SpriteReset(void) {
    s32 i;

    EnableObj();
    ListPoolInit(&gSpriteWork->tilePool);

    for (i = 0; i < 128; i++) {
        ListPoolAddFree(gSpriteWork->tiles[i].unk_0C, &gSpriteWork->tilePool, &gSpriteWork->tiles[i]);
    }
    ListPoolInit(&gSpriteWork->palettePool);

    for (i = 0; i < 16; i++) {
        ListPoolAddFree(gSpriteWork->palettes[i].unk_0C, &gSpriteWork->palettePool,
                      &gSpriteWork->palettes[i]);
    }
    gSpriteWork->entryCount = 0;
    gSpriteWork->affineCount = 0;
    gSpriteWork->sortLo = 0;
    SetObjMosaicSize(0, 0);
    gSpriteWork->unk_2BAE = 0;
    gSpriteWork->unk_2BAF = 0;
    SetObjTileRange(0, 0x400);
    SetObjPaletteRange(0, 0x10);
}

u8 func_08002060(s16 x, s16 y, void* c, void* obj, void* e, s32 f, u16 g, u16 h) {
    SpriteWork* p;

    if (e != 0 && c != 0) {
        p = gSpriteWork;
        p->entries[p->entryCount].unk_10 = x;
        p->entries[p->entryCount].unk_12 = y;
        p->entries[p->entryCount].unk_00 = obj;
        p->entries[p->entryCount].unk_04 = e;
        p->entries[p->entryCount].unk_08 = f;
        p->entries[p->entryCount].unk_16 = g;
        p->entries[p->entryCount].unk_14 = h;
        p->entries[p->entryCount].unk_0C = c;
        p->sortPtrs[p->entryCount] = &p->entries[p->entryCount];
        p->entryCount += 1;
        return 1;
    }
    return 0;
}
