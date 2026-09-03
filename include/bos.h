#ifndef GUARD_BOS_H
#define GUARD_BOS_H

#include "types.h"
#include "game.h"

typedef struct BosShadowWork {
    void* tiles;
    void* palette;
    BtlWork* unk_08;
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

void task_bos_map_0(s32 unused, BosMapConfig* cfg);
s32 task_bos_map_1(void);
void task_bos_shadow_0(BosShadowWork* work, BtlWork* obj);
s32 task_bos_shadow_1(void);
void task_bos_shadow_2(BosShadowWork* work);
void task_bos_shadow_3(BosShadowWork* work);

#endif /* GUARD_BOS_H */
