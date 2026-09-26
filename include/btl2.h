#include "battle_localized_data.h"
#ifndef GUARD_BTL2_H
#define GUARD_BTL2_H


#include "bg_animation_data.h"

#include "field_state.h"

#include "map_api.h"
#include "btl2_tasks.h"

#include <stdlib.h>
#include "fade.h"
#include "obj_api.h"
#include "battle_actor.h"
#include "display.h"
#include "types.h"
#include "engine_math.h"
#include "battle_work.h"
#include "game_state.h"
#include "m4a.h"
#include "m4a_catalog_data.h"
#include "key.h"
#include "anim.h"
#include "bos4_api.h"

typedef struct BtlShadowWork {
    void* tiles;
    void* palette;
    BtlObj* actor;
    void* gfx;
} BtlShadowWork;

typedef struct BtlHpplyWork {
    s32 unk_00;
    u8 unk_04;
    u8 unk_05[0x03];
    void* palette2;
    void* palette;
    void* tiles;
    void* tiles2;
    void* tiles3;
    void* tiles4;
    void* gfx;
    void* gfx2;
    void* gfx3;
    AnimState anim2;
    AnimState anim;
    u8 unk_5C;
    u8 unk_5D;
    s16 timer;
    s16 unk_60;
    s16 unk_62;
    s16 unk_64;
    u8 unk_66[0x02];
    u32 unk_68;
} BtlHpplyWork;

typedef struct BtlHpenmWork {
    void* tiles;
    void* tiles2;
    void* palette;
    void* tiles3;
    s32 unk_10;
    u8 unk_14;
    u8 unk_15[0x03];
    BtlObj* actor;
    s16 unk_1C;
    s16 unk_1E;
    u32 unk_20;
} BtlHpenmWork;

typedef struct BtlPauseWork {
    void* tiles;
    void* palette;
    void* gfx;
    void* gfx2;
    u8 unk_10;
    u8 unk_11[0x03];
    s32 x;
    s32 y;
    s32 x2;
    s32 y2;
    s16 unk_24;
    s16 unk_26;
} BtlPauseWork;

typedef struct BtlPopWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    s16 timer;
    s16 unk_32;
} BtlPopWork;

typedef struct BtlEscapeWork {
    void* tiles;
    void* palette;
    void* gfx;
    void* gfx2;
    void* gfx3;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s16 timer;
    u8 unk_22;
    u8 unk_23;
} BtlEscapeWork;

typedef struct BtlPrizeWork {
    s32 x;
    s32 y;
    s32 z;
    s32 unk_0C;
    void* tiles;
    void* palette;
    void* gfx;
    void* gfx2;
    s32 vz;
    s32 unk_24;
    s16 unk_28;
    u8 unk_2A;
    u8 unk_2B;
    u16 flags;
    u8 unk_2E[0x02];
    s32 unk_30;
    s32 unk_34;
    u16 unk_38;
    s16 unk_3A;
    s32 vx;
    s32 vy;
    u8 angle;
    u8 unk_45[0x03];
    BtlObj* actor;
} BtlPrizeWork;

typedef struct BtlPremireWork {
    s32 x;
    s32 y;
    s32 z;
    s32 unk_0C;
    void* tiles;
    void* palette;
    void* gfx;
    void* gfx2;
    s32 vz;
    s32 unk_24;
    s16 unk_28;
    u8 unk_2A;
    u8 unk_2B;
    u16 flags;
    u8 unk_2E[0x02];
    s32 unk_30;
    s32 unk_34;
    s32 vx;
    s32 vy;
    u8 angle;
    u8 unk_41[0x03];
    BtlObj* actor;
    AnimState anim;
} BtlPremireWork;

typedef struct BtlPremireSrc {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x06];
    s16 unk_12;
    s16 unk_14;
    s16 unk_16;
} BtlPremireSrc;

typedef struct BtlStartWork {
    s16 unk_00;
    s16 unk_02;
} BtlStartWork;

extern u8 gUnk_08B1E7F4[];
extern u8 gUnk_08B1EB1C[];
extern u8 gUnk_08B1ED76[];
extern u8 gUnk_08B1EF0C[];
extern u8 gUnk_08B1F020[];
extern u8 gUnk_08B1F13A[];
extern u8 gUnk_08B1F2D6[];
extern u8 gUnk_08B1F472[];
extern u8 gUnk_08B1F60E[];
extern u8 gUnk_08B1F7AC[];
extern u8 gBPuraizuFrame0[];
extern u8 gBPuraizuFrame1[];
extern u8 gBPuraizuFrame2[];
extern u8 gBPuraizuFrame3[];
extern u8 gBPuraizuFrame4[];
extern u8 gBPuraizuFrame5[];
extern u8 gBPuraizuFrame6[];
extern u8 gBPuraizuFrame7[];
extern u8 gBPuraizuFrame8[];
extern u8 gBPuraizuFrame9[];
extern u8 gBPuraizuTiles[];
extern u8 gBHpgagEFrame0[];
extern u8 gBHpgagEFrame1[];
extern u8 gBHpgagEFrame2[];
extern u8 gBHpgagEFrame3[];
extern u8 gBHpgagEFrame4[];
extern u8 gBHpgagEFrame5[];
extern u8 gBHpgagEFrame6[];
extern u8 gBHpgagEFrame7[];
extern u8 gBHpgagEFrame8[];
extern u8 gBHpgagEFrame9[];
extern u8 gBHpgagEFrame10[];
extern u8 gBHpgagEFrame11[];
extern u8 gBHpgagEFrame12[];
extern u8 gBHpgagEFrame13[];
extern u8 gBHpgagETiles[];
extern u8 gSoraPalette[];
extern u8 gBStatesPalette[];
extern u8 gRikuPalette[];

#endif /* GUARD_BTL2_H */
