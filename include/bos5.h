#ifndef GUARD_BOS5_H
#define GUARD_BOS5_H

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
#include "bos5_api.h"
#include "poo_api.h"
#include "room_api.h"
#include "btl_api.h"

typedef struct GaEntryDesc {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    void* unk_08;
    u8 unk_0C[0x4];
    void* unk_10;
} GaEntryDesc;

typedef struct GaEntryPos {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    u16 unk_06;
} GaEntryPos;

typedef struct GaEntry {
    u16 unk_00;
    u16 unk_02;
    void* unk_04;
    u16 unk_08;
    u8 unk_0A[0x12];
    GaEntryDesc unk_1C[2];
    GaEntryPos unk_44[1];
} GaEntry;

typedef struct MdAnimFrame {
    u16 unk_00;
    u16 unk_02;
} MdAnimFrame;

typedef struct MdAnimDef {
    MdAnimFrame* unk_00;
    u16 unk_04;
    u16 unk_06;
} MdAnimDef;

extern MdAnimDef gUnk_09992E24[];

typedef struct MdAnim {
    u16 unk_00;
    u16 unk_02;
    MdAnimFrame* unk_04;
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    u16 unk_0E;
} MdAnim;

typedef struct MdSub {
    u32 unk_000;
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
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
    s32 unk_00C;
    s32 unk_010;
    s32 unk_014;
    u32 palette;
    u32 tiles;
    u32 unk_020;
    u16 unk_024;
    u8 unk_026[0x2];
} MdHahenWork;

typedef struct MdDaiTarget {
    u16 unk_00;
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
    u32 unk_01C;
    u8 unk_020[0x58];
    MdDaiTarget* unk_078;
    s16 unk_07C;
    u16 unk_07E;
    void* unk_080;
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
    MdSub unk_038;
    s32 x;
    s32 y;
    s32 z;
    s32 unk_154;
    s32 unk_158;
    s16 unk_15C;
    s16 unk_15E;
    s16 unk_160;
    u8 unk_162;
    u8 unk_163;
    u32 unk_164;
    u32 unk_168;
    MdFireTarget* unk_16C;
} MdFireWork;

typedef struct MdFireArg {
    void* unk_00;
    s16 unk_04;
    u16 unk_06;
    s32 unk_08;
} MdFireArg;

typedef struct MdFirePoint {
    s16 unk_00;
    s16 unk_02;
    u16 unk_04;
    u16 unk_06;
} MdFirePoint;

typedef struct MdFireDef {
    MdFirePoint* unk_00;
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
    void* unk_0C;
    void* unk_10;
    void* unk_14;
} MdSlot;

extern MdModel gUnk_09992F70[];
extern u8 gUnk_09A3CDDC[];
extern u8 gUnk_099EDE7C[];
extern u8 gUnk_099A8914[];

typedef struct MdGfx {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    s16 unk_0C;
    s16 unk_0E;
    s16 unk_10;
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
    TaskPool unk_02C;
    TaskPool unk_040;
    TaskPool unk_054;
    MdSub sub[1];
    u16 unk_178;
    u16 unk_17A;
    MdGfx unk_17C[2];
    MdAnim unk_1A4;
    u16 unk_1B4;
    u8 unk_1B6[0x2];
} MdWork;

extern s16 gSineTable[];
extern u8 gUnk_09A3C9BC[];
extern u8 gUnk_09999ED0[];
extern u32 gUnk_09EF9740[];

void func_080FCC14(MdFireWork* work);
u8 func_080FCCB4(MdFireWork* work);

extern u8 gUnk_09992114[];
extern GaEntry gUnk_09992108[];

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

extern u8 gUnk_09A02EFC[];
extern u8 gUnk_09A020FC[];

typedef struct MdMapData {
    void* unk_00;
    u16 unk_04;
    u8 unk_06[0x2];
    void* unk_08;
    u16 unk_0C;
    u8 unk_0E[0x2];
    u32 unk_10;
} MdMapData;

typedef struct MdMapWork {
    u32 unk_00;
} MdMapWork;

void task_bos_ga_0(GaWork* work, s32 arg);
s32 task_bos_md_dai_1(MdDaiWork* work);
void task_bos_md_fire_0(MdFireWork* work, MdFireArg* arg);
void func_080FCF78(MdFireWork* work);
extern s16 gSineTable[];
extern MdFireDef gUnk_09992EF8[];
extern u8 gUnk_09992F28[];
extern u8 gUnk_09A3C99C[];
extern u8 gUnk_099E367C[];
extern u8 gUnk_09EF9BC0[];
extern u8 gUnk_09EF9BB0[];
extern u8 gTaskDescBosMdFire[];
void task_bos_md_dai_2(MdDaiWork* work);
extern u8 gUnk_09999E0C[];
extern u8 gUnk_09999E1C[];
extern u8 gTaskDescBosMdHahen[];
u8 task_bos_ga_1(GaWork* work);
void func_080FB000(GaWork* work, GaEntryWork* p);
u8 func_080F854C(GaWork* work);
u8 func_080F8AC8(GaWork* work);
u8 func_080F8F9C(GaWork* work);
u8 func_080F9EDC(GaWork* work);
u8 func_080FA644(GaWork* work);
u8 func_080FABE4(GaWork* work);
extern u8 gTaskDescBosMap[];
extern u8 gUnk_0999202C[];
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
extern u8 gUnk_0999CB90[];
extern u8 gUnk_0999C394[];
extern u8 gUnk_0999C3C8[];
extern void* gUnk_09EF9770[];
void mode_worldselect_1(void);
void func_080FDC04(void);
void func_080FE47C(void);
extern u8 gUnk_09A315DC[];
extern u8 gUnk_09A31FDC[];
void mode_worldselect_0(void);
extern u16 gUnk_02039D30;
extern u8 gUnk_09A3C9DC[];
extern u8 gUnk_099F1E7C[];
extern u8 gUnk_09A310DC[];
extern u8 gUnk_09A31ADC[];
extern u8 gUnk_09EDABA0[];
extern u8 gUnk_09A3CC5C[];
extern u8 gUnk_0999B052[];
extern u8 gUnk_09A3CC7C[];
extern u8 gUnk_0999CBB6[];
extern u8 gUnk_0999C410[];
extern s32 gUnk_020354D0;
extern s32 gUnk_020354C8[];
extern s32 gUnk_020354D8;
extern s32 gUnk_020354DC;
extern struct ObjTiles* gUnk_02035120;
extern struct ObjPaletteNode* gUnk_02035124;
extern struct ObjTiles* gUnk_02035128;
extern struct ObjPaletteNode* gUnk_02035148;
extern struct ObjTiles* gUnk_0203514C;
extern void* gUnk_020351C8[];
extern void* gUnk_02035198[];
extern AnimState gUnk_02035130;
extern AnimState gUnk_02035150;
extern u8 gUnk_020351F8[];
extern u8 gUnk_020352C0[];
extern u8 gUnk_0203511A;
extern u8 gUnk_0999CF38[];
extern u8 gUnk_0999CF54[];
extern u8 gUnk_0999CF88[];
extern void* gUnk_020354B8[];
extern u8 gUnk_020354A0;
extern u16 gUnk_020354C2;
extern u8 gUnk_020352B8;
extern u8 gUnk_09A3CC3C[];
extern u8 gUnk_0999A394[];
extern u8 gUnk_0999A350[];

typedef struct MdWorldNav {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    u8 unk_0C[0x8];
} MdWorldNav;

extern MdWorldNav gUnk_09EF8FAC[];
extern void* gUnk_020354A8[];
extern void* gUnk_020354B0[];
extern void* gUnk_02035168[];
extern u8 gUnk_020354E0;
extern s16 gUnk_02035118;
extern u8 gUnk_09A324DC[];
extern u8 gUnk_09A3D07C[];
extern struct ObjPaletteNode* gUnk_0203511C;
extern s16 gUnk_020354C0;
void func_080FDB1C(s16 model, s16 n);
void mode_worldselect_2(void);
void func_080FE89C(void);
extern u16 gBldCnt;
extern u16 gBldAlpha;
void func_080FE900(void);
extern void* gUnk_09EF8F24[];
extern u8 gTaskDescBosMdMap[];
extern u8 gUnk_099920E8[];
extern u8 gUnk_099D42FC[];
extern u8 gUnk_099920D8[];
extern u8 gTaskDescBosMdDai[];
void func_080FBA4C(MdWork* work);
extern u8 gUnk_08F69BC4[];
extern u8 gUnk_09A3C97C[];
void task_bos_md_2(MdWork* work);
typedef struct MdMsg {
    u32 unk_00;
    void* unk_04;
    u16 unk_08;
    u8 unk_0A[0x0E];
    void* unk_18;
    u16 unk_1C;
    u16 unk_1E;
    void* unk_20;
    u16 unk_24;
    u16 unk_26;
    void* unk_28;
    void* unk_2C;
    u16 unk_30;
    u16 unk_32;
} MdMsg;

extern MdMsg gUnk_09EF909C[];
extern void* gUnk_09EE9138[];
extern u8 gUnk_020351F8[];
extern u8 gUnk_020352C0[];
u8 func_080FF25C(s16 id);
void func_080FC3FC(MdWork* work);
void func_080FC360(MdWork* work);

u8 func_080FC17C(MdWork* work);
void func_080FC29C(MdWork* work);
void task_bos_md_map_0(MdMapWork* work, MdMapData* p);
s32 task_bos_md_map_1(MdMapWork* work);
s32 func_080FF310(void);

#endif /* GUARD_BOS5_H */
