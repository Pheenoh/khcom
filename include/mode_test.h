#include "event_index_data.h"
#include "mode_test_data.h"
#include "card_def_data.h"
#include "card_lookup_data.h"
#include "card_animation_data.h"
#include "registration_data.h"
#include "system_state.h"
#ifndef GUARD_MODE_TEST_H
#define GUARD_MODE_TEST_H

#include "animation_resource_data.h"

#include "graphics_state.h"

#include "msg_types.h"

#include "field_state.h"

#include "continue_types.h"

#include "fld_types.h"

#include "evt_types.h"

#include "card_types.h"

#include "card_api.h"

#include "map_api.h"
#include "mode_test_api.h"

#include "fade.h"
#include "btl_effect.h"
#include "btl_collision.h"
#include "obj_api.h"
#include "battle_actor.h"
#include "display.h"
#include "types.h"
#include "malloc.h"
#include "engine_math.h"
#include "listpool.h"
#include "battle_work.h"
#include "game_state.h"
#include "key.h"
#include "anim.h"
#include "mode.h"
#include "mode_battle_data.h"
#include "taskpool.h"
#include "gba/syscall.h"
#include "m4a.h"
#include "bos4_api.h"
#include "btl_api.h"

#define CPU_SET_SRC_FIXED 0x01000000
#define CPU_SET_32BIT     0x04000000

typedef struct UnkStruct_02034A1C {
    u16 unk_00[61];
    u8 unk_7A;
    u8 unk_7B;
    u8 unk_7C;
    u8 unk_7D;
    u8 unk_7E[2];
    u32 unk_80;
} UnkStruct_02034A1C;

typedef struct CharTile {
    u32 rows[8];
} CharTile;

#ifdef VERSION_EU
typedef struct UnkModeTestBody {
    s32 unk_00;
    s32 x;
    s32 y;
    s32 z;
    s32 ground;
    u8 unk_14[0x20];
    u64 flags;
    u8 unk_3C[4];
    u8 particles[0x8C];
    u16 depth;
    u8 unk_CE[0x42];
} UnkModeTestBody;

typedef struct UnkModeTestWork {
    TaskPool tasks;
    BtlObj* actor;
    void* tiles;
    void* palette;
    UnkModeTestBody body;
    AnimState anim;
    s32 state;
    u8 side;
    u8 card;
    s16 counter;
    s32 targetX;
    s32 targetY;
    s32 velocity;
    s32 speed;
    u8 bounce;
    u8 unk_161[3];
    s32 bob;
    s32 animcounter;
    s32 scale;
} UnkModeTestWork;

typedef struct UnkModeTestArgs {
    u16 card;
    u8 side;
    u8 unk_03;
} UnkModeTestArgs;

extern u8 gUnk_09849A98[];
extern u8 gUnkEu_08896524[];

#endif

typedef struct LockonWork {
    void* tiles;
    void* palette;
    void* gfx;
    FldObj* unk_0C[8];
    u8 unk_2C;
    s8 unk_2D;
    s8 unk_2E;
    u8 unk_2F;
    u8 unk_30;
    u8 unk_31[3];
    AnimState anim;
    u8 unk_4C;
    u8 unk_4D[3];
} LockonWork;

s32 func_0805F93C(u8 bg, u8 b, u8 c, u8 d, u8 e);
void func_080B0754(void);
void func_08061824(void);

void mode_test_0(void);
void mode_test_1(void);
void mode_test_2(void);
void func_0805F66C(LockonWork* w);
void func_0805F728(s32* x, s32* y);
void func_0805F770(void);
void func_0805F7B0(s32 a);
void func_0805F7BC(void);
void func_0805F7C8(u8 a);
u8 func_0805F8F0(u8 a);
void func_0805F904(void);
void func_0805FB78(s32 a);
void func_0805FB84(u8 x, u8 y, u32 c, u8 v);
void task_lockon_0(LockonWork* w);
s8 func_0805F5D8(s32 a, s32 b, LockonWork* w, s8 n, s8* list);
u8 func_0805F6B4(u16 a, s32 b, s32 c, FldObj* d);
void func_08062D3C(void);
void func_0806250C(void);
void func_08062CE4(void);
void func_08061FC8(void);
void func_080629F8(void);
void func_08062D20(void);
u8 func_080629CC(void);
void func_0806297C(void);
u8 task_lockon_1(LockonWork* w);
void task_lockon_2(LockonWork* w);
void task_lockon_3(LockonWork* w);
void func_0805F7E8(u8 x, u8 y, u16* s);
void func_08060470(u8 bg);
void func_0806098C(void);

extern s32* gUnk_02039DC4;
extern EventState* gUnk_02039DC8;

extern Mode gModeChkbtl;
extern u8 gUnk_08B24DAA[];
extern u8 gUnk_090D4DD0[];
extern u8 gUnk_090D7C84[];
extern u8 gUnk_0941BEB8[];
extern u8 gUnk_0941DD38[];
extern u8 gUnk_096148B8[];
extern u8 gUnk_08F69BA4[];
extern u8 gUnk_08F69BE4[];

extern vu16 gSystemFlags;
#endif /* GUARD_MODE_TEST_H */
