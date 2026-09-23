#include "room_data.h"
#include "registration_data.h"
#ifndef GUARD_BOS5_H
#define GUARD_BOS5_H

#include "worldselect_assets.h"
#include "battle_actor_types.h"

#include "bg_animation_data.h"

#include "obj.h"

#include "ga_types.h"

#include "prize_types.h"

#include "card_api.h"

#include "map_api.h"
#include "msg_api.h"
#include "m4a_song.h"
#include "text.h"
#include "fade.h"
#include "btl_effect.h"
#include "btl_collision.h"
#include "obj_api.h"
#include "battle_actor.h"
#include "display.h"
#include "types.h"
#include "malloc.h"
#include "engine_math.h"
#include "battle_work.h"
#include "game_state.h"
#include "text_types.h"
#include "key.h"
#include "taskpool.h"
#include "anim.h"
#include "bos4_api.h"
#include "poo_api.h"
#include "room_api.h"
#include "btl_api.h"

typedef struct GaEntryDesc {
    u16 x;
    u16 y;
    u16 z;
    u16 unk_06;
    void* src;
    u32 unk_0C;
    void* sprite;
} GaEntryDesc;

typedef struct GaEntryPos {
    s16 x;
    s16 y;
    s16 z;
    u16 unk_06;
} GaEntryPos;

typedef struct GaEntry {
    u16 unk_00;
    u16 unk_02;
    void* tiles;
    u16 tilesSize;
    u16 unk_0A;
    const void* blocks[4];
    GaEntryDesc desc[2];
    GaEntryPos pos[1];
} GaEntry;

typedef struct MdAnimFrame {
    u16 gfxIndex;
    u16 duration;
} MdAnimFrame;

typedef struct MdAnimDef {
    const MdAnimFrame* frames;
    u16 frameCount;
    u16 unk_06;
} MdAnimDef;

extern const MdAnimFrame gUnk_09992D34[4];
extern const MdAnimFrame gUnk_09992D44[4];
extern const MdAnimFrame gUnk_09992D54[4];
extern const MdAnimFrame gUnk_09992D64[2];
extern const MdAnimFrame gUnk_09992D6C[2];
extern const MdAnimFrame gUnk_09992D74[10];
extern const MdAnimFrame gUnk_09992D9C[8];
extern const MdAnimFrame gUnk_09992DBC[6];
extern const MdAnimFrame gUnk_09992DD4[8];
extern const MdAnimFrame gUnk_09992DF4[11];
extern const MdAnimFrame gUnk_09992E20[1];
extern const MdAnimDef gMdAnimDefs[11];

typedef struct MdAnim {
    u16 animId;
    u16 unk_02;
    const MdAnimFrame* frames;
    s16 frameCount;
    s16 frame;
    s16 timer;
    u16 unk_0E;
} MdAnim;

typedef struct MdSub {
    u32 unk_000;
    s32 x;
    s32 y;
    s32 z;
    u8 unk_010[0x1C];
    s16 unk_02C;
    s16 unk_02E;
    u8 unk_030[0x4];
    u64 unk_034;
    u8 unk_03C[0x4];
    u8 unk_040[0xD0];
} MdSub;

typedef struct MdHahenWork {
    s32 x;
    s32 y;
    s32 z;
    s32 vx;
    s32 vy;
    s32 vz;
    u32 palette;
    u32 tiles;
    void* gfx;
    u16 timer;
    u8 unk_026[0x2];
} MdHahenWork;

typedef struct MdDaiTarget {
    u16 flags;
} MdDaiTarget;

typedef struct MdDaiWork {
    s32 x;
    s32 y;
    s32 z;
    s32 unk_00C;
    s16 unk_010;
    u8 unk_012[0x2];
    u32 palette;
    u32 tiles;
    u32 collider;
    u8 unk_020[0x58];
    MdDaiTarget* target;
    s16 unk_07C;
    u16 state;
    void* pool;
} MdDaiWork;

typedef struct MdFireTarget {
    u16 unk_00;
} MdFireTarget;

typedef struct MdFireWork {
    u32 unk_000;
    s16 unk_004;
    s16 unk_006;
    s16 unk_008;
    u8 unk_00A[0x2];
    u32 palette;
    u32 palette2;
    u32 tiles;
    AnimState anim;
    u32 unk_030;
    s16 unk_034;
    u8 unk_036[0x2];
    MdSub sub;
    s32 x;
    s32 y;
    s32 z;
    s32 vx;
    s32 vy;
    s16 unk_15C;
    s16 unk_15E;
    s16 unk_160;
    u8 angle;
    u8 unk_163;
    u32 unk_164;
    u32 unk_168;
    MdFireTarget* target;
} MdFireWork;

typedef struct MdFireArg {
    void* pool;
    s16 unk_04;
    u16 unk_06;
    s32 unk_08;
} MdFireArg;

typedef struct MdFirePoint {
    s16 x;
    s16 y;
    u16 unk_04;
    u16 unk_06;
} MdFirePoint;

typedef struct MdFireDef {
    const MdFirePoint* points;
    s16 unk_04;
    u16 unk_06;
} MdFireDef;

typedef struct MdModel {
    u16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    void* unk_14;
#ifdef VERSION_EU
    u16 unkEu_18;
    u16 unkEu_1A;
#endif
} MdModel;

typedef struct MdSlot {
    s16 unk_00;
    u8 unk_02[0x6];
    u8 unk_08;
    u8 unk_09[0x3];
    void* palette;
    void* tiles;
    void* gfx;
} MdSlot;

typedef struct WorldselectTileSizes {
    u16 sizes[5];
} WorldselectTileSizes;

#ifdef VERSION_EU
extern const WorldselectTileSizes gUnkEu_099991E0;
#endif
extern const MdModel gMdModels[13];

typedef struct MdGfx {
    void* tiles;
    void* src;
    void* sprite;
    s16 x;
    s16 y;
    s16 z;
    u16 unk_12;
} MdGfx;

typedef struct MdWork {
    u32 unk_000;
    u32 unk_004;
    u32 unk_008;
    u16 unk_00C;
    u16 unk_00E;
    u32 unk_010[1];
    u16 unk_014;
    s16 unk_016;
    u16 unk_018;
    s16 unk_01A;
    u8 unk_01C;
    u8 unk_01D[0x3];
    u8* palette;
    u8* palette2;
    void* unk_028;
    TaskPool tasks;
    TaskPool tasks2;
    TaskPool tasks3;
    MdSub sub[1];
    u16 unk_178;
    u16 unk_17A;
    MdGfx gfx[2];
    MdAnim anim;
    u16 unk_1B4;
    u8 unk_1B6[0x2];
} MdWork;

extern u8 gUnk_09A3C9BC[];

void func_080FCC14(MdFireWork* work);
u8 func_080FCCB4(MdFireWork* work);

extern const GaEntry gGaEntries[41];

s32 task_bos_md_hahen_1(MdHahenWork* work);
void task_bos_md_hahen_2(MdHahenWork* work);
void task_bos_md_dai_0(MdDaiWork* work, s32* src);
void task_bos_md_hahen_0(MdHahenWork* work, s32* src);
u8 task_bos_md_fire_1(MdFireWork* work);
void task_bos_md_fire_2(MdFireWork* work);
void task_bos_md_3(MdWork* work);
void func_080FD9B8(s16 model, s16 slot);
void func_080FDA28(s16 model, s16 slot);
s16 func_080FDA98(s16 model, s16 slot);
extern u32 gFrameCounter;

void task_bos_ga_2(GaWork* work);
void task_bos_ga_3(GaWork* work);
void task_bos_md_hahen_3(MdHahenWork* work);
void task_bos_md_fire_3(MdFireWork* work);
void task_bos_md_dai_3(MdDaiWork* work);
void func_080FB8E8(MdWork* work, u16 index);
void func_080FB908(MdWork* work, u16 index);

typedef struct MdMapData {
    void* tiles;
    u16 tilesSize;
    u8 unk_06[0x2];
    void* palette;
    u16 paletteSize;
    u8 unk_0E[0x2];
    void* map[4];
} MdMapData;

typedef struct MdMapWork {
    u32 unk_00;
} MdMapWork;

void task_bos_ga_0(GaWork* work, s32 arg);
s32 task_bos_md_dai_1(MdDaiWork* work);
void task_bos_md_fire_0(MdFireWork* work, MdFireArg* arg);
void func_080FCF78(MdFireWork* work);
extern const MdFirePoint gUnk_09992E98[4];
extern const MdFirePoint gUnk_09992EB8[4];
extern const MdFirePoint gUnk_09992ED8[4];
extern const MdFireDef gMdFireDefs[6];
extern const EmyKind gUnk_09992F28;
extern u8 gUnk_09A3C99C[];
void task_bos_md_dai_2(MdDaiWork* work);
u8 task_bos_ga_1(GaWork* work);
void func_080FB000(GaWork* work, GaEntryWork* p);
u8 func_080F854C(GaWork* work);
u8 func_080F8AC8(GaWork* work);
u8 func_080F8F9C(GaWork* work);
u8 func_080F9EDC(GaWork* work);
u8 func_080FA644(GaWork* work);
u8 func_080FABE4(GaWork* work);
extern u8 gUnk_09A3C89C[];
void func_080FB930(MdWork* work, u16 id);
void func_080FB8DC(MdWork* work, s32 state);
void func_080FBA14(MdWork* work, s16 id);
u8 func_080FBA9C(MdWork* work);
u8 func_080FBAB8(MdWork* work);
u8 func_080FBC4C(MdWork* work);
u8 func_080FBDD4(MdWork* work);
u8 func_080FBFA8(MdWork* work);
s32 task_bos_md_1(MdWork* work);
void task_bos_md_0(MdWork* work, void* arg);
void func_080FE854(void);
void mode_worldselect_1(void);
void func_080FDC04(void);
void func_080FE47C(void);
void mode_worldselect_0(void);
extern u8 gUnk_09A3C9DC[];
extern u8 gUnk_09A3CC5C[];
extern u8 gUnk_09A3CC7C[];

void func_080FDB1C(s16 model, s16 n);
void mode_worldselect_2(void);
void func_080FE89C(void);

void func_080FE900(void);
extern const MdMapData gMdMapData;
extern u8 gUnk_09A3C8BC[];
extern const EmyKind gUnk_099920D8;
void func_080FBA4C(MdWork* work);
extern u8 gUnk_08F69BC4[];
extern u8 gUnk_09A3C97C[];
void task_bos_md_2(MdWork* work);
void func_080FC3FC(MdWork* work);
void func_080FC360(MdWork* work);

u8 func_080FC17C(MdWork* work);
void func_080FC29C(MdWork* work);
void task_bos_md_map_0(MdMapWork* work, MdMapData* p);
s32 task_bos_md_map_1(MdMapWork* work);

#endif /* GUARD_BOS5_H */
