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
typedef struct WarpIcon {
    u8 unk_00[0x08];
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    s16 unk_0E;
    s16 unk_10;
    u8 unk_12[0x02];
} WarpIcon;

typedef struct WarpRect {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
} WarpRect;

typedef struct WarpGfx {
    u16 unk_00;
    s16 unk_02;
    void* unk_04;
    u16 unk_08;
    u8 unk_0A[0x02];
    void* unk_0C;
    u16 unk_10;
    u8 unk_12[0x02];
    void* unk_14;
    void* unk_18;
    u16 unk_1C;
    u8 unk_1E[0x02];
} WarpGfx;

typedef struct WarpDef {
    void* unk_00;
    u8 unk_04[0x06];
    u16 unk_0A;
    s16 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    s16 unk_12;
    u16 unk_14;
    u16 unk_16;
    s16 unk_18;
    u8 unk_1A[0x02];
    WarpGfx unk_1C[2];
} WarpDef;

extern const WarpDef gUnk_09993118[];
extern u16 gUnk_099931D0[];

extern u8 gUnk_09A3D77C[];
extern u8 gUnk_09617D58[];
extern u8 gUnk_09A35F1C[];

extern u8 gUnk_09A378DC[];

extern u8 gUnk_099A2AD4[];
extern u8 gUnk_099A2AF0[];
extern u8 gUnk_099A2B24[];
extern u8 gUnk_08B22BA8[];
extern WarpIcon gUnk_09EF9384[];
extern WorldSelectDef gUnk_09EF9488[];
extern WarpRect gUnk_099930E8[];
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
