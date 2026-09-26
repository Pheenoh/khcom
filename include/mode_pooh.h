#include "registration_data.h"
#ifndef GUARD_MODE_POOH_H
#define GUARD_MODE_POOH_H


#include "chara_types.h"

#include "prize_types.h"

#include "card_api.h"
#include "msg_api.h"
#include "mode_pooh_api.h"

#include "mode_test_api.h"

#include "anim.h"
#include <string.h>
#include "fade.h"
#include "btl_collision.h"
#include "obj_api.h"
#include "display.h"
#include "types.h"
#include "engine_math.h"
#include "game_state.h"
#include "taskpool.h"
#include "main.h"
#include "mode.h"
#include "obj.h"
#include "key.h"
#include "m4a.h"
#include "bos4_api.h"
#include "poo_api.h"


typedef struct PoohPos {
    s32 x;
    s32 y;
    s32 z;
    s32 unk_0C;
} PoohPos;

typedef struct PoohNear {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
} PoohNear;

typedef struct PoohHit {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
    s16 unk_08;
    s16 unk_0A;
} PoohHit;

extern u32 gUnk_02034DAC;

extern u8 gPoohPalette[];
extern u8 gTrap0001Palette[];
extern u8 gTrap0002Palette[];
extern u8 gTrap0003Palette[];
extern const PoohHit gUnk_096FC010;
extern const s8 gUnk_096FC01C[8][8];

void func_080C75E0(u32 a, u16 b);
void func_080C7608(u32 a, u16 b, u16 c);
u8 func_080C7638(void);
void func_080C7644(u32 a, u16 b, u16 c);
void func_080C7714(void);
void func_080C774C(void);
void mode_pooh_0(s32 arg);
void mode_pooh_1(void);
void mode_pooh_2(void);
u16 func_080C7C80(void);
void func_080C7D60(PoohWork* w);
void func_080C7DF8(PoohWork* w);
void func_080C7E98(PoohWork* w);
void func_080C7F18(PoohWork* w);
u8 func_080C7F4C(u8 a);
u8 func_080C7F94(PoohWork* w);

#endif /* GUARD_MODE_POOH_H */
