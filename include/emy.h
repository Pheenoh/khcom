#ifndef GUARD_EMY_H
#define GUARD_EMY_H

#include "task_descriptors.h"

#include "enemy_types.h"

#include "emy_tasks.h"

#include "display.h"
#include "player_progression.h"

#include "m4a_song.h"
#include "obj_api.h"
#include "btl_effect.h"
#include "btl_collision.h"
#include "battle_actor.h"
#include "types.h"
#include "engine_math.h"
#include "listpool.h"
#include "battle_work.h"
#include "game_state.h"
#include "anim.h"
#include "taskpool.h"
#include "enemy_common.h"
#include "btl_api.h"

typedef struct EmySpawn {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x06];
    s16 unk_12;
    u16 unk_14;
    u8 unk_16[0x0A];
} EmySpawn;

typedef struct Emy03Work {
    EmyWork base;
    u32 unk_184;
    u32 unk_188;
    u32 unk_18C;
} Emy03Work;

typedef struct Emy04Work {
    EmyWork base;
    u8 unk_184;
    u8 unk_185;
    s16 unk_186;
} Emy04Work;

typedef struct Emy06Work {
    EmyWork base;
    s32 unk_184;
} Emy06Work;

typedef struct Emy07Work {
    EmyWork base;
    s16 unk_184;
    u8 unk_186;
    u8 unk_187;
} Emy07Work;

typedef struct Emy08Work {
    EmyWork base;
    void* palette;
    void* unk_188;
    u16 unk_18C;
} Emy08Work;

typedef struct Emy16Work {
    EmyWork base;
    void* unk_184;
    void* unk_188;
    TaskPool tasks;
    u8 unk_1A0;
} Emy16Work;

typedef struct Emy16bWork {
    void* tiles;
    void* palette;
    u8 anim[0x18];
    s32 x;
    s32 y;
    s32 z;
    u8 unk_02C;
    u8 unk_02D[0x03];
    s32 vz;
    s32 vx;
    u32 state;
    s16 unk_03C;
    u8 unk_03E[0x02];
    u32 collider;
    u8 unk_044[0x28];
    u8 unk_06C;
    u8 unk_06D[0x2F];
    u8 unk_09C;
    u8 unk_09D;
    u8 unk_09E[0x02];
} Emy16bWork;

typedef struct Emy16pWork {
    void* tiles;
    void* palette;
    u8 anim[0x18];
    s32 x;
    s32 y;
    s32 z;
    u8 unk_02C;
    u8 unk_02D[0x03];
    s32 vz;
} Emy16pWork;

typedef struct Emy18Work {
    EmyWork base;
    u16 unk_184;
} Emy18Work;

typedef struct Emy19Work {
    EmyWork base;
    s32 unk_184;
} Emy19Work;

typedef struct Emy21Work {
    EmyWork base;
    s32 unk_184;
} Emy21Work;

typedef struct Emy22Work {
    EmyWork base;
    u8 unk_184;
} Emy22Work;

typedef struct Emy23Work {
    EmyWork base;
    s32 unk_184;
} Emy23Work;

typedef struct Emy28Work {
    EmyWork base;
    u16 unk_184;
} Emy28Work;

typedef struct Emy29Work {
    EmyWork base;
    s16 state;
    s16 unk_186;
} Emy29Work;

typedef struct Emy31Work {
    EmyWork base;
    u32 state;
    u32 unk_188;
    u32 unk_18C;
    u32 unk_190;
} Emy31Work;

typedef struct Emy37Work {
    EmyWork base;
    u8 unk_184;
    u8 unk_185[0x03];
    u32 unk_188;
    u16 angle;
} Emy37Work;

typedef struct Emy39Work {
    EmyWork base;
    s32 unk_184;
} Emy39Work;

typedef struct Emy41Work {
    EmyWork base;
    u32 unk_184;
    u32 unk_188;
    u32 unk_18C;
} Emy41Work;

typedef struct Emy81Work {
    EmyWork base;
    s32 unk_184;
    s32 unk_188;
    s32 unk_18C;
    s32 unk_190;
} Emy81Work;

typedef struct Emy82Work {
    EmyWork base;
    u16 unk_184;
} Emy82Work;

typedef struct Emy83Work {
    EmyWork base;
    void* task;
    TaskPool tasks;
    s32 unk_19C;
    s32 unk_1A0;
    s16 unk_1A4;
} Emy83Work;

typedef struct Emy83bWork {
    void* tiles;
    void* palette;
    u8 unk_008[0x0A];
    u16 unk_012;
    u8 unk_014[0x0C];
    s32 x;
    s32 y;
    s32 z;
    u32 state;
    s16 timer;
    u8 unk_032[0x02];
    u32 collider;
    u8 unk_038[0x58];
} Emy83bWork;

typedef struct Emy83sWork {
    void* tiles;
    void* palette;
    s32 x;
    s32 y;
    s32 z;
    s32 vz;
    s32 unk_018;
    s32 unk_01C;
    u16 unk_020;
    s16 unk_022;
} Emy83sWork;

extern u8 gUnk_08A20BCE[];
extern u8 gUnk_08A23630[];
extern u8 gUnk_08B1D828[];
extern u8 gUnk_08B1D832[];
extern u8 gUnk_08B1D846[];
extern u8 gUnk_08B1B854[];
extern u8 gUnk_08F698C4[];
extern u8 gUnk_08F699C4[];
extern u8 gUnk_08F69B84[];
extern u32 gFrameCounter;

void func_0803B468(Emy29Work* work, s16 anim, s16 dx, s16 dy, s16 dz);
u8 func_0803DD44(EmyWork* work);

#endif /* GUARD_EMY_H */
