#include "task_descriptors.h"
#include "jiminy_records_data.h"
#ifndef GUARD_HUM_H
#define GUARD_HUM_H

#include "hum_types.h"

#include "card_api.h"

#include "jiminy_list.h"
#include "map_api.h"
#include "ms_api.h"
#include "hum_tasks.h"

#include "pallet.h"
#include "save_api.h"

#include "player_progression.h"

#include "m4a_song.h"
#include <string.h>
#include <stdlib.h>
#include "text.h"
#include "fade.h"
#include "btl_effect.h"
#include "btl_collision.h"
#include "obj_api.h"
#include "battle_actor.h"
#include "display.h"
#include "types.h"
#include "engine_math.h"
#include "battle_work.h"
#include "game_state.h"
#include "text_types.h"
#include "jiminy_types.h"
#include "save_types.h"
#include "key.h"
#include "anim.h"
#include "taskpool.h"
#include "obj.h"
#include "hum_common.h"
#include "bos3.h"
#include "bos4_api.h"
#include "btl_api.h"
#include "pc_api.h"

typedef struct VixenSub {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02[0x02];
    s32 x;
    s32 y;
} VixenSub;

typedef struct CloudWork {
    HumWork base;
    u32 unk_188;
    u16 state;
    u16 unk_18E;
    u16 unk_190;
    u8 unk_192[0x02];
} CloudWork;

typedef struct HookWork {
    HumWork base;
    u32 unk_188;
    s32 unk_18C;
    s32 unk_190;
    u16 angle;
    u16 unk_196;
    u16 flags;
    u8 unk_19A[0x02];
    TaskPool tasks;
    void* unk_1B0;
    void* unk_1B4;
    void* unk_1B8;
} HookWork;

typedef struct HookMoonWork {
    void* tiles;
    u8* palette;
    u16 angle;
    u8 unk_0A;
    u8 unk_0B;
} HookMoonWork;

typedef struct VixenNdlArgs {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x06];
    s16 unk_12;
    u16 unk_14;
    u16 unk_16;
    void* unk_18;
    u8 unk_1C[0x04];
} VixenNdlArgs;

typedef struct VixenNdlWork {
    void* tiles;
    void* palette;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 unk_2C;
    u8 unk_2D;
    u8 unk_2E;
    u8 unk_2F;
} VixenNdlWork;

typedef struct VixenFrzWork {
    void* tiles;
    void* palette;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u32 unk_2C;
    s16 timer;
    u16 unk_32;
    u16 unk_34;
    u16 unk_36;
} VixenFrzWork;

typedef struct VixenIceWork {
    u32 state;
    void* tiles;
    void* palette;
    AnimState anim;
    VixenSub* sub;
    u8 collider[0x5C];
    s16 unk_84;
    u16 unk_86;
    u16 unk_88;
    u8 unk_8A[0x02];
    s32 unk_8C;
    s32 unk_90;
} VixenIceWork;

typedef struct LexTmh0Work {
    void* tiles;
    void* palette;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 unk_2C;
    u8 unk_2D[0x03];
    s32 unk_30;
    s16 unk_34;
    u8 unk_36[0x02];
} LexTmh0Work;

typedef struct LexTmhWork {
    void* tiles;
    void* palette;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 unk_2C;
    u8 unk_2D;
    u16 unk_2E;
    s32 state;
    s32 unk_34;
    s32 unk_38;
    s32 vz;
    void* tiles2;
    void* palette2;
    u8 unk_48;
    u8 unk_49;
    s16 unk_4A;
} LexTmhWork;

typedef struct RikuSpawn {
    s32 x;
    s32 y;
    s32 z;
    u16 flags;
    u16 unk_0E;
    AnimState anim;
    u32 unk_28;
    s32 unk_2C;
} RikuSpawn;

typedef struct MahluxiaFlwWork {
    s32 state;
    void* tiles;
    void* palette;
    AnimState anim;
    u8 unk_24[0x04];
    s32 vz;
    s32 vx;
    s32 x;
    s32 y;
    s32 z;
} MahluxiaFlwWork;

typedef struct MahluxiaWork {
    HumWork base;
    HumSub sub;
    s32 unk_1C4;
    s16 unk_1C8;
    u16 unk_1CA;
    s32 angle;
    u16 flags;
    u8 unk_1D2[0x02];
    s32 unk_1D4;
    s16 unk_1D8;
    u8 unk_1DA[0x02];
    RikuSpawn spawns[9];
    s32 unk_38C;
    TaskPool tasks;
} MahluxiaWork;

typedef struct LaxeneKnfWork {
    void* tiles;
    void* palette;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 unk_2C;
    u8 unk_2D;
    u16 timer;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 state;
    s32 vx;
} LaxeneKnfWork;

typedef struct LaxeneWork {
    HumWork base;
    s32 unk_188;
    u16 unk_18C;
    u16 flags;
    u16 unk_190;
    u16 unk_192;
    TaskPool tasks;
} LaxeneWork;

typedef struct VixenWork {
    HumWork base;
    s32 unk_188;
    u8 unk_18C[0x0C];
    s32 unk_198;
    s32 unk_19C;
    u16 angle;
    u16 flags;
    TaskPool tasks;
    void* task;
    u8 unk_1BC;
    u8 unk_1BD[0x03];
    s32 unk_1C0;
    VixenSub sub[3];
    u8 unk_1E8[0x30];
} VixenWork;

typedef struct LexceusWork {
    HumWork base;
    u8 unk_188[0x38];
    s32 unk_1C0;
    s32 unk_1C4;
    u8 unk_1C8[0x02];
    u16 flags;
    s16 unk_1CC;
    u16 unk_1CE;
    s32 unk_1D0;
    s32 unk_1D4;
    TaskPool tasks;
    void* task;
    s32 unk_1F0;
    s32 unk_1F4;
    u16 unk_1F8;
    u16 unk_1FA;
    s32 unk_1FC;
    s32 unk_200;
} LexceusWork;

typedef struct HadesSub {
    s32 unk_00;
    s32 x;
    s32 y;
    s32 z;
    s32 x2;
    s32 y2;
    s32 z2;
    s32 x3;
    s32 y3;
    s32 z3;
} HadesSub;

typedef struct HadesWork {
    HumWork base;
    HumSub sub;
    s32 unk_1C4;
    u16 unk_1C8;
    u16 unk_1CA;
    s16 unk_1CC;
    u8 unk_1CE[0x02];
    s32 unk_1D0;
    void* tiles;
    void* tiles2;
    void* tiles3;
    AnimState anim;
    AnimState anim2;
    AnimState anim3;
    void* palette;
    HadesSub sub2[2];
    s32 unk_27C;
} HadesWork;

typedef struct LeonWork {
    HumWork base;
    u16 unk_188;
    u8 unk_18A;
    u8 unk_18B;
    u64 unk_18C;
    u64 unk_194;
} LeonWork;

typedef struct AnsemWork {
    HumWork base;
    HumSub sub;
    s32 unk_1C4;
    u16 unk_1C8;
    u16 unk_1CA;
    s16 unk_1CC;
    u8 unk_1CE[0x02];
    s32 unk_1D0;
    u8 unk_1D4[0x02];
    s16 unk_1D6;
    s16 unk_1D8;
    u8 unk_1DA[0x02];
} AnsemWork;

typedef struct VixenFrgDef {
    s16 unk_00;
    s16 unk_02;
    u16 unk_04;
    u16 unk_06;
} VixenFrgDef;

typedef struct VixenFrgSub {
    void* gfx;
    s32 x;
    s32 y;
    s32 z;
    s32 vz;
    s32 vx;
    s32 vy;
    u16 unk_1C;
    u16 unk_1E;
} VixenFrgSub;

typedef struct VixenFrgWork {
    u8 unk_00[0x30];
    void* tiles;
    void* palette;
    s16 unk_38;
    u16 unk_3A;
    VixenFrgSub sub[15];
    u8 unk_21C;
    u8 unk_21D[0x03];
} VixenFrgWork;

typedef struct RikuWork {
    HumWork base;
    HumSub sub;
    s32 unk_1C4;
    u16 unk_1C8;
    u16 flags;
    s16 unk_1CC;
    u16 unk_1CE;
    RikuSpawn spawns[9];
    u16 unk_380;
    u8 unk_382[0x02];
} RikuWork;

typedef struct HookBombWork {
    void* tiles;
    void* palette;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    u8 unk_2C;
    u8 unk_2D[0x03];
    s32 vz;
    u8 angle;
    u8 unk_35[0x03];
    s32 unk_38;
    s16 timer;
    u16 unk_3E;
    void* tiles2;
    void* palette2;
    u8 unk_48;
    u8 unk_49;
    s16 unk_4A;
    s16 unk_4C;
    u16 unk_4E;
    s32 unk_50;
} HookBombWork;

typedef struct LexRockSub {
    u8 unk_00;
    u8 unk_01[0x03];
    s32 x;
    s32 y;
    s32 z;
    s32 vz;
    s32 vx;
    s32 vy;
} LexRockSub;

typedef struct LexRockWork {
    void* tiles2[12];
    void* palette2;
    AnimState anim[12];
    s32 x;
    s32 y;
    s32 z;
    u8 unk_160;
    u8 unk_161;
    u16 state;
    u16 unk_164;
    s16 unk_166;
    LexRockSub sub[12];
    void* tiles;
    void* palette;
    u8 unk_2C0;
    u8 unk_2C1[0x03];
} LexRockWork;

typedef struct AxcelWork {
    HumWork base;
    HumSub sub;
    HumSub sub2;
    s32 unk_200;
    u16 unk_204;
    u16 flags;
    u16 unk_208;
    u16 unk_20A;
    s32 unk_20C;
    s32 unk_210;
    s32 unk_214;
    void* tiles;
    void* palette;
    TaskPool tasks;
    u16 unk_234;
    u16 unk_236;
} AxcelWork;

typedef struct AxcelPtcWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
} AxcelPtcWork;

typedef struct RobeWork {
    HumWork base;
    u16 unk_188;
    u8 unk_18A[0x02];
} RobeWork;

extern u8 gUnk_08BCB3D8[];
extern u8 gUnk_08EE4264[];
extern u8 gUnk_08F6DC84[];
extern u8 gUnk_09618478[];
extern u8 gUnk_08C3151E[];
extern u8 gUnk_08BD99F4[];
extern u8 gUnk_09618458[];
extern u8 gUnk_08F6DC64[];
extern u8 gUnk_08C3724C[];
extern u8 gUnk_09617F18[];
extern u8 gUnk_09617F38[];

extern vu32 gFrameCounter;
extern u8 gUnk_08F6DCA4[];
extern u8 gUnk_08F6DCC4[];
extern u8 gUnk_08F6DCE4[];
extern u8 gUnk_08C42BBE[];
extern u8 gUnk_08C46790[];
extern u8 gUnk_08F69BA4[];
extern u8 gUnk_08EE3A84[];
extern u8 gUnk_08C1E78C[];
extern u8 gUnk_08BAFB62[];
extern u8 gUnk_08F6DC44[];
extern u8 gUnk_08B59E52[];
extern JiminyWork* gJiminyWork;

void func_08054100(AxcelWork* work, HumSub* sub);
void func_08018724(s32 x, s32 y, s32 z, s32 f, s32 w);
void func_08057E90(RikuWork* work, RikuSpawn* p);
void func_08057E2C(RikuWork* work, RikuSpawn* dst);
void func_08016AF4(s32 x, s32 y, s32 z, u8 f, s32 w);
void func_080560AC(HumWork* work, s32 a);
s32 __modsi3(s32 a, s32 b);
void func_080A324C(void* p);
void CopyMapCardInventory(void* p);
void RestoreMapCardInventory(void* p);
u16 func_0805A55C(u16* p);
void func_0805A638(s32 a, u16** b);
void func_0805A4D8(s16 a, s16 b, s16 c);
void func_0805A7D0(void);
void func_0805A514(s16 a, s16 b, s16 c);
void func_0805A698(s16 a, s16 b, u16** d, const u16* c, const u16* e, s16 f, s16 g, s16 h);
u8 func_0800FF70(u16 a);

s32 func_0805A574(s32 idx);

struct PcCharaWork;

#endif /* GUARD_HUM_H */
