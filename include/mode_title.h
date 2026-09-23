#include "registration_data.h"
#ifndef GUARD_MODE_TITLE_H
#define GUARD_MODE_TITLE_H

#include "anim.h"

#include "card_api.h"

#include "title_api.h"
#include "mode_pooh_api.h"

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

void func_080D5A4C(u16 a);
void func_080D5B04(void);
void func_080D5B30(void);
void func_080D59B4(void);

extern s32 gTitleBgScale;
extern s32 gTitleBgX;
extern s32 gTitleBgY;

#endif /* GUARD_MODE_TITLE_H */
