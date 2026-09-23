#include "card_label_sprite_data.h"
#include "card_reload_sprite_data.h"
#ifndef GUARD_MODE_MAPINSPECT_H
#define GUARD_MODE_MAPINSPECT_H

#include "registration_data.h"
#include "card_description_data.h"
#include "map_card_data.h"
#include "card_ui_types.h"
#include "card_api.h"
#include "mode_ms_top_api.h"
#include "key.h"
#include "malloc.h"
#include "mode.h"
#include "m4a.h"

#include "obj.h"

#include "map_api.h"

#include "game_state.h"
#include "text.h"
#include "fade.h"
#include "obj_api.h"
#include "display.h"
#include "types.h"
#include "engine_math.h"
#include "text_types.h"
#include "ms_types.h"
#include "main.h"
#include "anim.h"
extern u8 gUnk_08159E10[];
extern u8 gUnk_08159E18[];
extern u8 gUnk_08159FBC[];
extern u8 gUnk_0815C136[];
extern u8 gUnk_09611AB8[];

s16 func_0810712C(s16 a);
s16 func_0810714C(void);
void func_081071AC(void);
s16 func_08107220(s16 a);
u8 func_08107268(void);
s16 func_081075C0(s16 a, s16 b);
s16 func_081075D8(void);
u16 func_08107D24(void);
void func_08108170(MapCardInventoryEntry* p, u16 row);
void func_08107938(void);
u8 func_081079A8(MapCardInventoryEntry* p);
u8 func_081079E4(MapCardInventoryEntry* p);
void func_08107A08(MapCardInventoryEntry* p);
void func_08107A74(MapCardInventoryEntry* p);
void func_08107D44(void);
void func_08107FF0(void);
void func_08108208(void);
void func_081083EC(void);
void func_081085E8(void);
void func_08108650(void);
void func_08107B84(void);
struct MapCardInventoryEntry* func_0810718C(void);
void func_081078F0(s16 a);
void func_081075FC(void);
void func_0810764C(void);
void func_081076D4(void);
void func_08107280(void);
void func_081073F0(void);

#endif /* GUARD_MODE_MAPINSPECT_H */
