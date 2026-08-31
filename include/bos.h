#ifndef GUARD_BOS_H
#define GUARD_BOS_H

#include "types.h"
#include "game.h"

typedef struct BosShadowWork {
    void* unk_00;
    void* unk_04;
    UnkStruct_02039B84* unk_08;
} BosShadowWork;

typedef struct BosMapConfig {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
    void* unk_08;
    u16 unk_0C;
    u16 unk_0E;
    u8 unk_10[0x10];
} BosMapConfig;

void task_bos_map_0(s32 unused, BosMapConfig* cfg);
s32 task_bos_map_1(void);
void task_bos_shadow_0(BosShadowWork* work, UnkStruct_02039B84* obj);
s32 task_bos_shadow_1(void);
void task_bos_shadow_2(BosShadowWork* work);
void task_bos_shadow_3(BosShadowWork* work);

#endif /* GUARD_BOS_H */
