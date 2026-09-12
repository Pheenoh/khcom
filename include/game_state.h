#ifndef GUARD_GAME_STATE_H
#define GUARD_GAME_STATE_H

#include "types.h"
#include "save_types.h"

typedef struct GameState {
    u8 unk_000;
    u8 unk_001[0x03];
    u32 randomSeed;
    u32 flags;
    u8 world;
    u8 unk_00D;
    s8 floor;
    u8 unk_00F;
    u16 unk_010;
    u8 unk_012[0x12];
    u8 unk_024;
    u8 unk_025[0x0D];
    s16 hp;
    u8 unk_034[0xC4];
    s16 maxHp;
    s16 cp;
    s16 dp;
    s16 ap;
    u32 exp;
    u32 nextExp;
    u8 level;
    u8 unk_109[0x03];
    u64 unk_10C;
    u64 unk_114;
    u64 unk_11C;
    u64 unk_124;
    u64 unk_12C;
    u64 unk_134[8];
    u32 mooglePoints;
    u16 unk_178;
    u16 unk_17A;
    u16 unk_17C;
    u16 unk_17E;
    u16 unk_180;
    u8 unk_182[0x36];
    u32 unk_1B8;
    SaveFileSummary fileSummaries[4];
    u32 playTime;
    u16 unk_1E0;
    u16 unk_1E2;
    u8 unk_1E4;
    u8 unk_1E5[0x03];
    u64 unk_1E8;
    u64 unk_1F0;
    u16 unk_1F8;
    u16 unk_1FA;
    u8 unk_1FC;
    u8 unk_1FD[0x03];
    u64 unk_200;
    u64 unk_208;
} GameState;

typedef char GameState_size[(sizeof(GameState) == 0x210) ? 1 : -1];

extern GameState gGameState;

#endif
