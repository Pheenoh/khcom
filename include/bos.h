#ifndef GUARD_BOS_H
#define GUARD_BOS_H

#include "bos_tasks.h"

#include "types.h"
#include "game.h"

typedef struct BosShadowWork {
    void* tiles;
    void* palette;
    BtlObj* unk_08;
} BosShadowWork;

typedef struct BosMapConfig {
    void* tiles;
    u16 tilesSize;
    u16 unk_06;
    void* palette;
    u16 paletteSize;
    u16 unk_0E;
    u8 unk_10[0x10];
} BosMapConfig;


#endif /* GUARD_BOS_H */
