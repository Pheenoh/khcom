#ifndef GUARD_EMY_H
#define GUARD_EMY_H

#include "animation_resource_data.h"

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
    s32 unk_030;
    s32 unk_034;
    u32 unk_038;
    s16 unk_03C;
    u8 unk_03E[0x02];
    u32 unk_040;
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
    s32 unk_030;
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
    s16 unk_184;
    s16 unk_186;
} Emy29Work;

typedef struct Emy31Work {
    EmyWork base;
    u32 unk_184;
    u32 unk_188;
    u32 unk_18C;
    u32 unk_190;
} Emy31Work;

typedef struct Emy37Work {
    EmyWork base;
    u8 unk_184;
    u8 unk_185[0x03];
    u32 unk_188;
    u16 unk_18C;
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
    void* unk_184;
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
    u32 unk_02C;
    s16 unk_030;
    u8 unk_032[0x02];
    u32 unk_034;
    u8 unk_038[0x58];
} Emy83bWork;

typedef struct Emy83sWork {
    void* tiles;
    void* palette;
    s32 x;
    s32 y;
    s32 z;
    s32 unk_014;
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
extern u8 gTaskDescBtlPrize[];
extern void* gTaskDescEmy16B;
extern void* gTaskDescEmy16P;
extern void* gTaskDescEmy83B;
extern void* gTaskDescEmy83S;
extern AnimDef gUnk_0813D35C[7];
extern EmyDef gUnk_0813D3CC;
extern AnimDef gUnk_0813D434[2];
extern EmyDef gUnk_0813D454;
extern AnimDef gUnk_0813D4BC[2];
extern EmyDef gUnk_0813D4DC;
extern AnimDef gUnk_0813D544[2];
extern EmyDef gUnk_0813D564;
extern AnimDef gUnk_0813D5CC;
extern EmyDef gUnk_0813D5DC;
extern AnimDef gUnk_0813D644[2];
extern EmyDef gUnk_0813D664;
extern AnimDef gUnk_0813D6CC[7];
extern EmyDef gUnk_0813D73C;
extern AnimDef gUnk_0813D7A4[6];
extern EmyDef gUnk_0813D804;
extern AnimDef gUnk_0813D86C[2];
extern EmyDef gUnk_0813D88C;
extern AnimDef gUnk_0813D8F4[5];
extern EmyDef gUnk_0813D944;
extern AnimDef gUnk_0813D9AC[2];
extern EmyDef gUnk_0813D9CC;
extern AnimDef gUnk_0813DA54[4];
extern EmyDef gUnk_0813DA94;
extern AnimDef gUnk_0813DAFC[5];
extern EmyDef gUnk_0813DB4C;
extern AnimDef gUnk_0813DBB4[4];
extern EmyDef gUnk_0813DBF4;
extern AnimDef gUnk_0813DC5C[2];
extern EmyDef gUnk_0813DC7C;
extern AnimDef gUnk_0813DCE4[2];
extern EmyDef gUnk_0813DD04;
extern AnimDef gUnk_0813DD6C[2];
extern EmyDef gUnk_0813DD8C;
extern AnimDef gUnk_0813DDF4[2];
extern EmyDef gUnk_0813DE14;
extern AnimDef gUnk_0813DE7C[2];
extern EmyDef gUnk_0813DE9C;
extern AnimDef gUnk_0813DF04[4];
extern EmyDef gUnk_0813DF44;
extern AnimDef gUnk_0813DFAC[2];
extern EmyDef gUnk_0813DFCC;
extern EmyDef gUnk_0813E0B4;
extern AnimDef gUnk_0813E034[8];
extern AnimDef gUnk_0813E11C[3];
extern EmyDef gUnk_0813E14C;
extern EmyDef gUnk_0813E264;
extern AnimDef gUnk_0813E1B4[11];
extern AnimDef gUnk_0813E2CC[2];
extern EmyDef gUnk_0813E2EC;
extern AnimDef gUnk_0813E354[2];
extern EmyDef gUnk_0813E374;
extern AnimDef gUnk_0813E3DC[2];
extern EmyDef gUnk_0813E3FC;
extern AnimDef gUnk_0813E464[2];
extern EmyDef gUnk_0813E484;
extern AnimDef gUnk_0813E4EC[5];
extern EmyDef gUnk_0813E53C;
extern EmyDef gUnk_0813E604;
extern AnimDef gUnk_0813E5A4[6];
extern EmyDef gUnk_0813E6AC;
extern AnimDef gUnk_0813E734;
extern AnimDef gUnk_0813E66C[4];
extern EmyDef gUnk_0813E744;
extern AnimDef gUnk_0813E7B4;
extern EmyDef gUnk_0813E7C4;
extern EmyDef gUnk_0813E834;

void func_0803B468(Emy29Work* work, s16 anim, s16 dx, s16 dy, s16 dz);
u8 func_0803DD44(EmyWork* work);

extern AnimDef gUnk_0813D32C[3];

extern AnimDef gUnk_0813D404[3];

extern AnimDef gUnk_0813D48C[3];

extern AnimDef gUnk_0813D514[3];

extern AnimDef gUnk_0813D59C[3];

extern AnimDef gUnk_0813D614[3];

extern AnimDef gUnk_0813D69C[3];

extern AnimDef gUnk_0813D774[3];

extern AnimDef gUnk_0813D83C[3];

extern AnimDef gUnk_0813D8C4[3];

extern AnimDef gUnk_0813D97C[3];

extern AnimDef gUnk_0813DA24[3];

extern AnimDef gUnk_0813DACC[3];

extern AnimDef gUnk_0813DB84[3];

extern AnimDef gUnk_0813DC2C[3];

extern AnimDef gUnk_0813DCB4[3];

extern AnimDef gUnk_0813DD3C[3];

extern AnimDef gUnk_0813DDC4[3];

extern AnimDef gUnk_0813DE4C[3];

extern AnimDef gUnk_0813DED4[3];

extern AnimDef gUnk_0813DF7C[3];

extern AnimDef gUnk_0813E004[3];

extern AnimDef gUnk_0813E0EC[3];

extern AnimDef gUnk_0813E184[3];

extern AnimDef gUnk_0813E29C[3];

extern AnimDef gUnk_0813E324[3];

extern AnimDef gUnk_0813E3AC[3];

extern AnimDef gUnk_0813E434[3];

extern AnimDef gUnk_0813E4BC[3];

extern AnimDef gUnk_0813E574[3];

extern AnimDef gUnk_0813E63C[3];

extern AnimDef gUnk_0813E704[3];

extern AnimDef gUnk_0813E784[3];

extern AnimDef gUnk_0813E804[3];

#endif /* GUARD_EMY_H */
