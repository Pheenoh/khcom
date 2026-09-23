#ifndef GUARD_ROMCRI_H
#define GUARD_ROMCRI_H

#include "romcri_tasks.h"

#include "pallet.h"
#include "display.h"
#include "types.h"
#include "game_state.h"
#include "formation_types.h"
#include "enemy_tile_counts.h"

typedef struct RomcriEffWork {
    s16 unk_00;
    u8 angle;
    u8 unk_03;
} RomcriEffWork;

typedef struct RomcriEff2Work {
    s16 unk_00;
    u8 angle;
    u8 unk_03;
} RomcriEff2Work;

u16 func_0803FDC8(const BtlFormEntry* list);

#endif /* GUARD_ROMCRI_H */
