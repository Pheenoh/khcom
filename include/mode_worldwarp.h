#include "worldwarp_data.h"
#ifndef GUARD_MODE_WORLDWARP_H
#define GUARD_MODE_WORLDWARP_H

#include "worldwarp_state.h"

#include "obj.h"

#include "world_types.h"

#include "card_api.h"

#include "map_api.h"
#include "mode_worldwarp_api.h"

#include "mode_ms_api.h"

#include "text.h"
#include "fade.h"
#include "obj_api.h"
#include "display.h"
#include "types.h"
#include "engine_math.h"
#include "game_state.h"
#include "text_types.h"
#include "taskpool.h"
#include "main.h"
#include "anim.h"
#include "m4a.h"
#include "bos4_api.h"
extern u16 gUnk_099931D0[];

extern u8 gUnk_09A3D77C[];
extern u8 gUnk_09617D58[];
extern u8 gUnk_09A35F1C[];

extern u8 gUnk_09A378DC[];

extern u8 gUnk_099A2AD4[];
extern u8 gUnk_099A2AF0[];
extern u8 gUnk_099A2B24[];
extern u8 gUnk_08B22BA8[];
extern u8 gUnk_09A3D37C[];
extern u8 gUnk_09A06A7C[];
extern u8 gUnk_09A35A1C[];
extern u8 gUnk_09A3641C[];
extern u8 gUnk_09A3691C[];
extern u8 gUnk_09A0E33C[];
extern u8 gUnk_09A0D63C[];
extern u8 gUnk_09A0FD3C[];
extern u8 gUnk_09A0F03C[];
extern u8 gUnk_09A3D57C[];
extern u8 gUnk_0999F488[];
extern u8 gUnk_09A3D59C[];
extern u8 gUnk_0999FA20[];
extern u8 gUnk_09A3D5BC[];
extern u8 gUnk_099A012C[];
extern u8 gUnk_09EF9898[];
extern u8 gUnk_09EF9870[];
extern u8 gUnk_09EF98B0[];
extern u8 gUnk_09EF98A0[];

void func_08100980(void);
void func_081006AC(void);
void func_0810057C(s16 a, s16 b, void* c, s16 d, s16 e, void* f, s16 g, s16 h);
void func_081004EC(s32 a, s32 b, s32 c, void* d, s32 e, s32 f);
u8 func_08100608(s16 a);
u8 func_0810063C(s16 a);
void func_08100670(s32 a, void* b, void* c);

void mode_worldwarp_0(void);
void mode_worldwarp_1(void);
void mode_worldwarp_2(void);
void SetMooglePoints(u32 a);

#endif /* GUARD_MODE_WORLDWARP_H */
