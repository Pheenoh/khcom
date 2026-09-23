#ifndef GUARD_MODE_WORLDWARP_H
#define GUARD_MODE_WORLDWARP_H


#include "obj.h"

#include "world_types.h"

#include "card_api.h"

#include "map_api.h"
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

extern u8 gUnk_09617D58[];
extern u8 gUnk_09A35F1C[];

extern u8 gUnk_09A378DC[];

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
extern u8 gUnk_09A3D59C[];
extern u8 gUnk_09A3D5BC[];

void mode_worldwarp_0(void);
void mode_worldwarp_1(void);
void mode_worldwarp_2(void);

typedef struct WarpIcon {
    s16 up;
    s16 down;
    s16 left;
    s16 right;
    s16 x;
    s16 y;
    s16 rect;
    s16 x2;
    s16 y2;
    u8 unk_12[0x02];
} WarpIcon;

typedef struct WarpRect {
    s16 width;
    s16 height;
    s16 x;
    s16 y;
} WarpRect;

#endif /* GUARD_MODE_WORLDWARP_H */
