#ifndef GUARD_ROOMCREATE_H
#define GUARD_ROOMCREATE_H

#include "card_api.h"

#include "map_api.h"
#include "roomcreate_tasks.h"

#include "fade.h"
#include "types.h"
#include "m4a.h"
#include "taskpool.h"
#include "fld_types.h"
#include "engine.h"
#include "bos4_api.h"
typedef struct FldActor {
    FldPos unk_00;
    s32 unk_10;
    u8 angle;
    u8 unk_15[0x3B];
} FldActor;

typedef struct UnkStruct_02039BA0 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10[0x08];
    FldActor unk_18;
    FldActor* unk_68;
    u8 unk_6C[0x04];
    u32 unk_70;
} UnkStruct_02039BA0;

typedef struct RoomCreateWork {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
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

extern UnkStruct_02039BA0* gUnk_02039BA0;
extern s16 gSineTable[];
extern u8 gMPlayInfo_BGM[];
extern TaskDesc gTaskDescRomcriEff;
extern TaskDesc gTaskDescRomcriEff2;
extern TaskDesc gTaskDescSpotLight;

struct Task;

void func_08093B78(TaskPool* pool, u8* p);
void func_080E042C(void);

#endif /* GUARD_ROOMCREATE_H */
