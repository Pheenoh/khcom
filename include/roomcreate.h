#include "registration_data.h"
#ifndef GUARD_ROOMCREATE_H
#define GUARD_ROOMCREATE_H

#include "field_state.h"

#include "card_api.h"

#include "map_api.h"
#include "roomcreate_tasks.h"

#include "fade.h"
#include "types.h"
#include "engine_math.h"
#include "m4a.h"
#include "m4a_catalog_data.h"
#include "taskpool.h"
#include "fld_types.h"
#include "engine.h"
#include "bos4_api.h"


typedef struct RoomCreateWork {
    s32 x;
    s32 y;
    s32 z;
    s32 x2;
    s32 y2;
    s32 z2;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    u8 unk_24;
    u8 unk_25;
    s16 unk_26;
    u8 unk_28;
    u8 unk_29;
    u8 unk_2A[0x02];
    TaskPool unk_2C;
    s32 unk_40;
} RoomCreateWork;

extern TaskDesc gTaskDescRomcriEff;
extern TaskDesc gTaskDescRomcriEff2;

struct Task;

void CreateMapCardSelection(TaskPool* pool, u8* p);
void func_080E042C(void);

#endif /* GUARD_ROOMCREATE_H */
