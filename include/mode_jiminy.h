#include "jiminy_records_data.h"
#include "jiminy_records_assets.h"
#include "battle_localized_data.h"
#include "battle_localized_assets.h"
#include "system_state.h"
#ifndef GUARD_MODE_JIMINY_H
#define GUARD_MODE_JIMINY_H

#include "map_api.h"
#include "msg_api.h"
#include "mode.h"

#include "player_progression.h"

#include <stdlib.h>
#include "text.h"
#include "monsgage.h"
#include "fade.h"
#include "obj_api.h"
#include "display.h"
#include "types.h"
#include "engine_math.h"
#include "game_state.h"
#include "text_types.h"
#include "jiminy_types.h"
#include "main.h"
#include "anim.h"
#include "obj.h"
#include "m4a.h"
#include "poo_api.h"
#ifdef VERSION_EU
extern u8 gUnkEu_08892334[];
extern u8 gUnk_09A3CDDC[];
#endif

extern JiminyWork* gJiminyWork;

extern u8 gUnk_08159FE0[];
extern u8 gTalk0600Tiles[];
extern u8 gTalk2700Tiles[];
extern u8 gCard00Palette[];
extern u8 gTalk0600Palette[];
extern u8 gTalk2700Palette[];

void func_0805A484(void);
u8 func_0805AA9C(void);
void func_0805A8D0(void);
s32 func_08065170(s32 a, s32 b, void* c);
void func_0805A95C(s16 a, s16 b, u16** c, const u16* d, const u16* e, s16 f, s16 g, s16 h);

void func_0805BAE4(void);
void func_0805B9D0(s16 a, s16 b, s32 c, s16 d, s16 e, s16 f);
void SplitThreeDecimalDigits(s16 a, u8* out);

#ifdef VERSION_EU
extern u8 gUnkEu_09A9A880[];
extern u8 gUnkEu_09A9A8A0[];
extern u8 gUnkEu_099FBE00[];
#endif

void mode_jiminy_1(void);

#endif
