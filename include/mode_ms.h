#include "moogle_data.h"
#include "card_def_data.h"
#include "card_lookup_data.h"
#include "card_animation_data.h"
#include "registration_data.h"
#ifndef GUARD_MODE_MS_H
#define GUARD_MODE_MS_H

#include "card_description_data.h"

#include "animation_resource_data.h"

#include "graphics_state.h"

#include "worldwarp_state.h"

#include "obj.h"

#include "card_types.h"

#include "ms_types.h"

#include "card_api.h"

#include "map_api.h"
#include "mode_worldwarp_api.h"

#include "mode_ms_api.h"

#include "mode_test_api.h"

#include "player_progression.h"

#include "text.h"
#include "fade.h"
#include "obj_api.h"
#include "display.h"
#include "types.h"
#include "engine_math.h"
#include "game_state.h"
#include "text_types.h"
#include "key.h"
#include "taskpool.h"
#include "fld_types.h"
#include "anim.h"
#include "mode.h"
#include "malloc.h"
#include "m4a.h"




typedef struct MooglePackCardWork {
    FldRes* palette;
    void* tiles;
    void* gfx;
    FldRes* palette2;
    void* tiles2;
    s32 backSprite;
    AnimState anim;
    u16 flipAngle;
    u16 unk_32;
    s32 scale;
    u16 state;
    u16 unk_3A;
    s32 x;
    s32 y;
    u16 timer;
    u8 premium;
    u8 revealed;
} MooglePackCardWork;



void func_08102688(u16 a, u16 b, u16 c);
u8 func_081026C4(u16 a, u16 b, u16 c);
void func_08102704(u16 a);
void func_08102728(u16 a);
u8 func_0810274C(u16 a);
void func_08102774(void);
u8 func_081027B4(s16 a);
s32 MoogleShopReadMenuKeys(void);
u16 func_08103F3C(void);
void func_08102984(s16 a);
void func_08103CD8(s16 a);
void mode_ms_top_2(void);
void func_08102DC8(void);
void mode_ms_shop_1(void);
void func_08104404(void);
void mode_ms_top_0(u32 a);
void mode_ms_shop_0(void);
void func_081041B4(void);
void mode_ms_shop_2(void);
void func_08103D54(s16 a);
void func_08103D7C(void);
void func_08103DE8(void);

void func_080A4234(void* pool, u32 a, u16 b);
void mode_ms_top_1(void);

void func_0810264C(u16 a, u16 b, u16 c);
u8 func_0810329C(u16 a);
void func_08102AB4(s16 x, s16 y);
void func_08103F94(s16 a, s16 b);
void func_081028F8(u16 w, s16 h, u16* src, s16 sx, s16 sy, u16* dst, s16 dx, s16 dy);

extern u8 gUnk_0203C590[];
extern u8 gUnk_09A3ABDC[];

extern u8 gUnk_09A3D79C[];
extern u8 gUnk_09A10A3C[];
extern u8 gUnk_09A123DC[];
extern u8 gUnk_09A36EDC[];
extern u8 gUnk_09A373DC[];
extern u8 gUnk_09A378DC[];
extern u8 gUnk_09A37DDC[];
extern u8 gUnk_09A3D7FC[];
extern u8 gUnk_099A2B62[];
extern u8 gUnk_09A3D85C[];
extern u8 gUnk_099A36F8[];
extern u8 gUnk_09EF99D0[];
extern u8 gUnk_09EF99A8[];
extern u8 gUnk_08F683A4[];
extern u8 gUnk_088C56C6[];
extern u8 gUnk_08F69BA4[];
extern u8 gUnk_08B22BBC[];
extern u8 gUnk_09617D58[];
extern u8 gUnk_092028EC[];
extern u32 gFrameCounter;
extern u8 gUnk_09A17D1C[];
extern u8 gUnk_09A3DA1C[];
extern s16 gSineTable[];
extern u8 gUnk_09A3DB1C[];
extern u8 gUnk_099A4B9A[];
extern u8 gUnk_09EF9A48[];
extern u8 gUnk_09EF9A20[];
extern u8 gUnk_09611AB8[];
extern u8 gUnk_0905EAE8[];
extern u8 gUnk_0905ED36[];
extern u8 gUnk_09A3DB7C[];
extern u8 gUnk_0908B1B4[];
extern u8 gUnk_09A3D87C[];
extern u8 gUnk_09A1251C[];
extern u8 gUnk_09A18D7C[];
extern u8 gUnk_09A382DC[];
extern u8 gUnk_09A3AD5C[];
extern u8 gUnk_09A3DA7C[];
extern u8 gUnk_099A3CE4[];
extern u8 gUnk_09EF99F8[];
extern u8 gUnk_09EF99D8[];
extern u8 gUnk_09A18EBC[];
#endif /* GUARD_MODE_MS_H */
