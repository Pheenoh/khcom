#include "card_def_data.h"
#ifndef GUARD_MS_CHARGE_H
#define GUARD_MS_CHARGE_H

#include "registration_data.h"
#include "map_card_data.h"
#include "obj.h"
#include "card_ui_types.h"
#include "card_api.h"
#include "map_api.h"
#include "game_state.h"
#include "malloc.h"
#include "anim.h"
#include "mode.h"

#include "card_description_data.h"

#include "card_types.h"

#include "ms_types.h"

#include "ms_charge_api.h"
#include "mode_ms_top_api.h"

#include "mode_test_api.h"

#include "display.h"
#include "engine_math.h"

#include <string.h>
#include "text.h"
#include "fade.h"
#include "obj_api.h"
#include "types.h"
#include "text_types.h"
#include "key.h"
#include "engine.h"
#include "m4a.h"

extern u8 gUnk_09A3DE7C[];

s16 CountCollectionCards(void);
s16 CountCardsInDecks(void);
void ClearCardCollectionSlot(u16* p);

s16 func_08104A84(s16 a);
s16 func_08104AA4(s16 a);
s16 func_08104AEC(void);
void func_08104B48(void);
s16 func_08104E9C(s16 a, s16 b);
s16 func_08104EB4(void);
u16 func_08104ED8(u16 index);
void func_08105334(void);
u8 func_08105404(MsCard* card);
u8 func_08105440(MsCard* card);
void func_08105464(MsCard* card);
void func_081054D0(MsCard* card);
s32 func_081055E8(u16 id, u8 flag, s16 count);
s32 MsChargeReadMenuKeys(void);
s32 func_08105D24(MsCard* card, u16 col);

extern u8 gUnk_092028EC[];
extern u8 gUnk_08159E10[];
extern u8 gUnk_08159E18[];
extern u8 gUnk_08159F38[];
extern u8 gUnk_0815C204[];
extern u8 gUnk_09611AB8[];
extern u8 gUnk_09617D58[];
void mode_ms_charge_1(void);
void mode_ms_charge_2(void);
void mode_ms_charge_0(void);

#endif
