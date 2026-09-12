#ifndef GUARD_ROMCRI_H
#define GUARD_ROMCRI_H

#include "romcri_tasks.h"

#include "pallet.h"
#include "display.h"
#include "types.h"
#include "game_state.h"

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

typedef struct RomcriEntry {
    u32 unk_00;
    u8 unk_04[0x08];
} RomcriEntry;

typedef struct RomcriList {
    s16 unk_00;
    u8 unk_02[0x02];
    RomcriEntry* unk_04;
} RomcriList;


extern u8 gUnk_08ED21E4[];
extern u8 gUnk_08ED6CA4[];
extern u8 gUnk_08EDBB44[];
extern u8 gUnk_08EE3064[];
extern u8 gUnk_08F4C384[];
extern u8 gUnk_08F4CB84[];
extern u8 gUnk_08F4D384[];
extern u8 gUnk_08F4DB84[];
extern u8 gUnk_08F4E384[];
extern u8 gUnk_08F4EB84[];
extern u8 gUnk_08F4F384[];
extern u8 gUnk_08F4FB84[];
extern u8 gUnk_08F50384[];
extern u8 gUnk_08F50B84[];
extern u8 gUnk_08F51384[];
extern u8 gUnk_08F51B84[];
extern u8 gUnk_08F52384[];
extern u8 gUnk_08F52B84[];
extern u8 gUnk_08F53384[];
extern u8 gUnk_08F53B84[];
extern u8 gUnk_08F54384[];
extern u8 gUnk_08F54B84[];
extern u8 gUnk_08F55384[];
extern u8 gUnk_08F55B84[];
extern u8 gUnk_08F56384[];
extern u8 gUnk_08F56B84[];
extern u8 gUnk_08F57384[];
extern u8 gUnk_08F57B84[];
extern u8 gUnk_08F58384[];
extern u8 gUnk_08F58B84[];
extern u8 gUnk_08F59384[];
extern u8 gUnk_08F59B84[];
extern u8 gUnk_08F5A384[];
extern u8 gUnk_08F5AB84[];
extern u8 gUnk_08F5B384[];
extern u8 gUnk_08F5BB84[];
extern u8 gUnk_08F5C384[];
extern u8 gUnk_08F5CB84[];
extern u8 gUnk_08F5D384[];
extern u8 gUnk_08F5DB84[];
extern u8 gUnk_08F6D9E4[];
extern u8 gUnk_08F6DA04[];
extern const u16 gUnk_09EDA4EC[];


u16 func_0803FDC8(RomcriList* list);

#endif /* GUARD_ROMCRI_H */
