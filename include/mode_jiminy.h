#ifndef GUARD_MODE_JIMINY_H
#define GUARD_MODE_JIMINY_H

#include "graphics_state.h"

#include "jiminy_list.h"
#include "map_api.h"
#include "msg_api.h"
#include "mode.h"

#include "player_progression.h"

#include <stdlib.h>
#include "text.h"
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
extern u32 gLanguage;
extern u8 gUnkEu_08C9A5E2[];
extern u8 gUnkEu_08892334[];
extern u8 gUnkEu_08EF3EDC[];
extern u8 gUnkEu_08EF4EDC[];
extern u8 gUnkEu_08EF5EDC[];
extern u8 gUnkEu_08EF6EDC[];
extern u8 gUnkEu_08C9BD82[];
extern u8 gUnkEu_08C9BD8C[];
extern u8 gUnkEu_08C9BD9C[];
extern u8 gUnkEu_08C9BDAC[];
extern u8 gUnkEu_08C9A538[];
extern u8 gUnkEu_08C9A4CC[];
extern u8 gUnkEu_08C9A564[];
extern u8 gUnkEu_08C9A554[];
extern u8 gUnkEu_08C9A590[];
extern u8 gUnkEu_08C9A57A[];
extern u8 gUnkEu_08C9A5C2[];
extern u8 gUnkEu_08C9A5A6[];
extern u8 gUnkEu_08C9A4E2[];
extern u8 gUnkEu_08C9A516[];
extern u8 gUnk_09A3CDDC[];
#endif




extern JiminyWork* gJiminyWork;

extern JiminyEntry gUnk_08155554[];
extern s16 gSineTable[];

extern u8 gUnk_08C69C04[];
extern u8 gUnk_08C69C20[];
extern u8 gUnk_08C69C54[];
extern u8 gUnk_08C69C76[];
extern u8 gUnk_08C6A51C[];
extern u8 gUnk_08C6A526[];
extern u8 gUnk_08C6A69A[];
extern u8 gUnk_08C6A6A4[];
extern u8 gUnk_08C6A878[];
extern u8 gUnk_08C6A8F8[];
extern u8 gUnk_08F62B84[];
extern u8 gUnk_08159FE0[];
extern u8 gUnk_08C69C9C[];
extern u8 gUnk_08C6A54E[];
extern u8 gUnk_08C6A6B8[];
extern u8 gUnk_08C6A88C[];
extern u8 gUnk_08C6A958[];
extern u8 gUnk_08EE4A64[];
extern u8 gUnk_08F60B84[];
extern u8 gUnk_08F61B84[];
extern u8 gUnk_08F6DD64[];
extern u8 gUnk_08F6DD84[];
extern u8 gUnk_08F6DDA4[];
extern u8 gUnk_08F6DDC4[];
extern u8 gUnk_08F6DDE4[];
extern u8 gUnk_08F6DE04[];
extern u8 gUnk_08F6DE24[];
extern u8 gUnk_090FDBF4[];
extern u8 gUnk_0913F0C2[];
extern u8 gUnk_09611AB8[];
extern u8 gUnk_09614AB8[];
extern u8 gUnk_09614D58[];
extern u8 gUnk_09A3CC9C[];
extern u8 gUnk_09EE2668[];
extern u8 gUnk_09EE2678[];
extern u8 gUnk_09EECA44[];
extern u8 gUnk_09EECAA0[];
extern u8 gUnk_09EED2BC[];
extern u8 gUnk_09EED320[];

u8 func_0805AA9C(void);
void func_0805A8D0(void);
void func_08064B80(s32 a);
s32 func_08065170(s32 a, s32 b, void* c);
s32 func_080653D4(s32 a, s32 b, void* c);
void func_0805A95C(s32 a, s16 b, void* c, void* d, void* e, s32 f, s32 g, s32 h);

void func_0805BAE4(void);
void func_0805B9D0(s16 a, s16 b, s32 c, s16 d, s16 e, s16 f);
void SplitThreeDecimalDigits(s16 a, u8* out);

extern JiminyDetail gUnk_0815574C[];
extern JiminyDetail gUnk_08155C54[];
extern JiminyDetail gUnk_0815600C[];
extern JiminyDetail gUnk_0815631C[];
extern JiminyDetail gUnk_081564A4[];
extern JiminyDetail gUnk_0815662C[];
extern JiminyDetail gUnk_081570E4[];
extern JiminyDetail gUnk_08157694[];
extern JiminyDetail gUnk_08157B9C[];
extern JiminyDetail gUnk_08158114[];
extern JiminyDetail gUnk_081589D4[];
extern JiminyDetail gUnk_08155B04[];
extern JiminyDetail gUnk_081576CC[];
extern JiminyDetail gUnk_0815917C[];
extern JiminyDetail gUnk_0815948C[];
extern JiminyDetail gUnk_081595DC[];
extern u8 gUnk_08F64384[];
extern u8 gUnk_08F60384[];
extern u8 gUnk_08F5EB84[];
extern u8 gUnk_08F63384[];
extern u8 gUnk_08F5FB84[];
extern u8 gUnk_08F63B84[];
extern u8 gUnk_08F64B84[];
extern u8 gUnk_08EE78E4[];
extern u8 gUnk_08C6A530[];
extern u8 gUnk_08C6A53A[];
#ifdef VERSION_EU
extern u8 gUnkEu_09A9A880[];
extern u8 gUnkEu_09A9A8A0[];
extern u8 gUnkEu_099FBE00[];
void* eu_0805E968(void* text);
s32 eu_0805E9AC(void* text);
#endif

void mode_jiminy_1(void);

#endif
