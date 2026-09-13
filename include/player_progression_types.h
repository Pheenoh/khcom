#ifndef GUARD_PLAYER_PROGRESSION_TYPES_H
#define GUARD_PLAYER_PROGRESSION_TYPES_H

#include "types.h"

typedef struct PlayerProgression {
    s16 maxHp;
    s16 cp;
    s16 dp;
    s16 ap;
    u32 exp;
    u32 nextExp;
    u8 level;
    u8 unk_11[0x03];
    u64 unk_14;
    u64 unk_1C;
    u64 unk_24;
    u64 unk_2C;
    u64 unk_34;
    u64 unk_3C[8];
    u32 mooglePoints;
    u16 unk_80;
    u16 unk_82;
    u16 unk_84;
    u16 unk_86;
} PlayerProgression;

typedef char PlayerProgression_size[(sizeof(PlayerProgression) == 0x88) ? 1 : -1];

#endif
