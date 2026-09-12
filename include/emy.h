#ifndef GUARD_EMY_H
#define GUARD_EMY_H

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

typedef struct EmyDef {
    void* unk_00;
    void* unk_04;
    s32 unk_08;
    u16 unk_0C;
    u16 unk_0E;
} EmyDef;

typedef struct EmySpawn {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x06];
    s16 unk_12;
    u16 unk_14;
    u8 unk_16[0x0A];
} EmySpawn;

typedef struct EmyWork {
    void* tiles;
    void* unk_004;
    void* unk_008;
    void* gfx;
    u32 anim;
    u8 unk_014[0x02];
    u16 unk_016;
    u8 unk_018[0x02];
    u16 unk_01A;
    u8 unk_01C[0x02];
    u16 unk_01E;
    u32 unk_020;
    u8 unk_024[0x04];
    TaskPool unk_028;
    BtlObj unk_03C;
    u32 unk_14C;
    u32 unk_150;
    s16 unk_154;
    s16 unk_156;
    u16 unk_158;
    u8 unk_15A;
    u8 unk_15B;
    EmyDef* unk_15C;
    u8 angle;
    u8 unk_161;
    u16 unk_162;
    s32 unk_164;
    s32 unk_168;
    u32 unk_16C;
    s32 unk_170;
    s32 unk_174;
    s32 unk_178;
    s32 unk_17C;
    s32 unk_180;
} EmyWork;

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
    TaskPool unk_18C;
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
    TaskPool unk_188;
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


void func_0802F1E8(void);


extern s16 gSineTable[];
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
extern u8 gUnk_09EE04AC[];
extern u8 gUnk_09EE04E0[];
extern u8 gUnk_09EE04F4[];
extern u8 gUnk_09EE04B4[];
extern u8 gUnk_09EE1090[];
extern u8 gUnk_09EE10A4[];
extern u8 gUnk_0813D35C[];
extern u8 gUnk_0813D3CC[];
extern u8 gUnk_0813D434[];
extern u8 gUnk_0813D454[];
extern u8 gUnk_0813D4BC[];
extern u8 gUnk_0813D4DC[];
extern u8 gUnk_0813D544[];
extern u8 gUnk_0813D564[];
extern u8 gUnk_0813D5CC[];
extern u8 gUnk_0813D5DC[];
extern u8 gUnk_0813D644[];
extern u8 gUnk_0813D664[];
extern u8 gUnk_0813D6CC[];
extern u8 gUnk_0813D73C[];
extern u8 gUnk_0813D7A4[];
extern u8 gUnk_0813D804[];
extern u8 gUnk_0813D86C[];
extern u8 gUnk_0813D88C[];
extern u8 gUnk_0813D8F4[];
extern u8 gUnk_0813D944[];
extern u8 gUnk_0813D9AC[];
extern u8 gUnk_0813D9CC[];
extern u8 gUnk_0813DA54[];
extern u8 gUnk_0813DA94[];
extern u8 gUnk_0813DAFC[];
extern u8 gUnk_0813DB4C[];
extern u8 gUnk_0813DBB4[];
extern u8 gUnk_0813DBF4[];
extern u8 gUnk_0813DC5C[];
extern u8 gUnk_0813DC7C[];
extern u8 gUnk_0813DCE4[];
extern u8 gUnk_0813DD04[];
extern u8 gUnk_0813DD6C[];
extern u8 gUnk_0813DD8C[];
extern u8 gUnk_0813DDF4[];
extern u8 gUnk_0813DE14[];
extern u8 gUnk_0813DE7C[];
extern u8 gUnk_0813DE9C[];
extern u8 gUnk_0813DF04[];
extern u8 gUnk_0813DF44[];
extern u8 gUnk_0813DFAC[];
extern u8 gUnk_0813DFCC[];
extern u8 gUnk_0813E0B4[];
extern u8 gUnk_0813E034[];
extern u8 gUnk_0813E11C[];
extern u8 gUnk_0813E14C[];
extern u8 gUnk_0813E264[];
extern u8 gUnk_0813E1B4[];
extern u8 gUnk_0813E2CC[];
extern u8 gUnk_0813E2EC[];
extern u8 gUnk_0813E354[];
extern u8 gUnk_0813E374[];
extern u8 gUnk_0813E3DC[];
extern u8 gUnk_0813E3FC[];
extern u8 gUnk_0813E464[];
extern u8 gUnk_0813E484[];
extern u8 gUnk_0813E4EC[];
extern u8 gUnk_0813E53C[];
extern u8 gUnk_0813E604[];
extern u8 gUnk_0813E5A4[];
extern u8 gUnk_0813E6AC[];
extern u8 gUnk_0813E734[];
extern u8 gUnk_0813E66C[];
extern u8 gUnk_0813E744[];
extern u8 gUnk_0813E7B4[];
extern u8 gUnk_0813E7C4[];
extern u8 gUnk_0813E834[];

void func_0803B468(Emy29Work* work, s16 anim, s16 dx, s16 dy, s16 dz);
u8 func_0803DD44(EmyWork* work);

#endif /* GUARD_EMY_H */
