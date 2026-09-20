#include "registration_data.h"
#ifndef GUARD_MODE_TITLE_H
#define GUARD_MODE_TITLE_H

#include "actor_ui_resource_data.h"

#include "title_background_state.h"

#include "card_api.h"

#include "title_api.h"
#include "mode_sio2_api.h"

#include "save_api.h"

#include "display.h"
#include "fade.h"
#include "obj_api.h"
#include "types.h"
#include "game_state.h"
#include "taskpool.h"
#include "title_types.h"
#include "intr.h"
#include "main.h"
#include "engine.h"
#include "m4a.h"
#include "battle_actor.h"

#define REG_DISPSTAT (*(vu16*)0x04000004)
#define REG_IE (*(vu16*)0x04000200)
#define REG_IME (*(vu16*)0x04000208)

extern u8 gUnk_09840798[];
extern u8 gUnk_0983E398[];
extern u8 gUnk_097D3658[];
extern u8 gUnk_09840F98[];
extern u8 gUnk_097C77B8[];
extern u8 gUnk_0983EB98[];
extern u8 gUnk_097CF758[];
extern u8 gUnk_0984A618[];
extern u8 gUnk_0983FB98[];
extern u8 gUnk_0976E9F4[];
extern u8 gUnk_09776076[];
extern u8 gUnk_0976EC54[];
extern u8 gUnk_0976ED5A[];
extern u8 gUnk_0976F0F6[];
extern u8 gUnk_0976F1F0[];
extern u8 gUnk_0976FD96[];
extern u8 gUnk_0984AA18[];
extern u8 gUnk_0984A6D8[];
extern u8 gUnk_0984A6B8[];
extern u8 gUnk_0984A6F8[];
extern u8 gUnk_0984A718[];
extern u8 gUnk_0984A738[];

extern u8 gUnk_0983F398[];
extern u8 gUnk_0984A418[];
extern u8 gUnk_0984A818[];

void func_080D5A4C(u16 a);
void func_080D5B04(void);
void func_080D5B30(void);
void func_080D59B4(void);

#endif /* GUARD_MODE_TITLE_H */
