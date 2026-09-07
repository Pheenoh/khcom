#ifndef GUARD_SPRITE_H
#define GUARD_SPRITE_H

#include "types.h"
#include "taskpool.h"
#include "engine.h"

typedef struct ObjListPool {
    ListNode head;
    u16 rangeStart;
    u16 rangeEnd;
} ObjListPool;

typedef struct SpriteEntry {
    void* unk_00;
    void* unk_04;
    s32 unk_08;
    void* unk_0C;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    u16 unk_16;
} SpriteEntry;

typedef struct ObjAffine {
    u16 pa;
    u16 pb;
    u16 pc;
    u16 pd;
    u16 index;
    u8 unk_0A;
    u8 unk_0B;
    s32 sx;
    s32 sy;
    u8 angle;
    u8 unk_15[0x03];
} ObjAffine;

struct SpriteWork {
    ObjTiles tiles[128];
    ObjListPool tilePool;
    ObjPaletteNode palettes[16];
    ObjListPool palettePool;
    SpriteEntry entries[128];
    SpriteEntry* sortPtrs[128];
    u16 entryCount;
    u16 sortLo;
    ObjAffine affine[32];
    u16 affineCount;
    u8 unk_2BAE;
    u8 unk_2BAF;
};

typedef char SpriteWork_size[(sizeof(SpriteWork) == 0x2BB0) ? 1 : -1];
typedef char ObjTiles_size[(sizeof(ObjTiles) == 0x30) ? 1 : -1];
typedef char ObjPaletteNode_size[(sizeof(ObjPaletteNode) == 0x28) ? 1 : -1];
typedef char ObjListPool_size[(sizeof(ObjListPool) == 0x14) ? 1 : -1];
typedef char SpriteEntry_size[(sizeof(SpriteEntry) == 0x18) ? 1 : -1];
typedef char ObjAffine_size[(sizeof(ObjAffine) == 0x18) ? 1 : -1];

void SpriteInit(void);
void SpriteFree(void);
void SortSpriteEntries(SpriteEntry** arr, s32 lo, s32 hi);

#endif
