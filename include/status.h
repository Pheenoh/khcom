#include "card_def_data.h"
#include "registration_data.h"
#ifndef GUARD_STATUS_H
#define GUARD_STATUS_H


#include "card_label_data.h"

#include "poo_api.h"

#include "bos4_api.h"

#include "card_ui_types.h"

#include "card_api.h"

#include "status_api.h"
#include "mode_status_api.h"

#include "player_progression.h"

#include "engine_math.h"

#include "card_deck.h"

#include "anim.h"
#include "text.h"
#include "fade.h"
#include "btl_effect.h"
#include "btl_collision.h"
#include "obj_api.h"
#include "battle_actor.h"
#include "types.h"
#include "battle_work.h"
#include "game_state.h"
#include "text_types.h"
#include "taskpool.h"
#include "main.h"
#include "engine.h"
#include "key.h"
#include "m4a.h"

typedef struct StatusEntry {
    s32 unk_000[72];
    u16 count;
    u16 unk_122;
} StatusEntry;

typedef struct StatusBarWork {
    void* tiles;
    void* palette;
    u16 unk_08;
    u16 unk_0A;
    s32 y;
    s32 targetY;
    s32 y2;
    s32 targetY2;
    s32 x;
    s32 targetX;
    u8 unk_24;
    u8 unk_25;
    u8 unk_26[0x6];
} StatusBarWork;

typedef struct StatusTabWork {
    void* tiles;
    void* tiles2;
    void* palette;
    void* palette2;
    void* gfx;
    void* gfx2;
    s32* unk_18;
} StatusTabWork;

typedef struct StatusSoraWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
} StatusSoraWork;

typedef struct StatusDecknameWork {
    u8 unk_00[0x50];
    void* palette;
    u8 unk_54;
    u8 unk_55[0x3];
    u8* unk_58;
} StatusDecknameWork;

typedef struct StatusCursorWork {
    void* tiles;
    void* tiles2;
    void* palette;
    void* palette2;
    void* gfx[2];
    AnimState anim[2];
    s16* unk_48;
    s16 unk_4C;
    u16 unk_4E;
    s32 y;
    s32 targetY;
    s32 x;
    s32 targetX;
} StatusCursorWork;

typedef struct StatusScrollcursorWork {
    void* tiles;
    void* palette;
    void* gfx;
    u16* unk_0C;
    u16 unk_10;
    s16 y;
} StatusScrollcursorWork;

typedef struct StatusMeswindowWork {
    TaskPool pool;
    void* unk_14;
    s32 unk_18;
    u8* unk_1C;
    u8 unk_20;
    u8 unk_21[3];
} StatusMeswindowWork;

typedef struct StatusMessageParam {
    void* unk_00;
    s16 x;
    s16 y;
} StatusMessageParam;

typedef struct StatusMessageWork {
    u8 unk_000[0x320];
    u8 unk_320;
    u8 unk_321[3];
    void* palette;
    StatusMessageParam param;
} StatusMessageWork;

typedef struct StatusFriendWork {
    void* tiles[3];
    void* palette[3];
    void* gfx[3];
    u16 unk_24;
    u16 unk_26;
} StatusFriendWork;

typedef struct StatusMesParam {
    u32 unk_00_00 : 16;
    u32 unk_00_16 : 16;
    u32 unk_04_00 : 8;
    u32 unk_04_08 : 8;
    u32 unk_04_16 : 16;
} StatusMesParam;

typedef struct StatusFriendEntry {
    u16 unk_00;
    u16 unk_02;
} StatusFriendEntry;

typedef struct StatusFriendTable {
    StatusFriendEntry entries[8];
} StatusFriendTable;

typedef struct StockMesDispWork {
    void* tiles;
    void* palette;
    void* tiles2;
    void* tiles3;
    void* palette2;
    void* palette3;
    void* gfx;
    void* gfx2;
    u16 unk_20;
    u16 unk_22;
    TaskPool tasks;
    void* unk_38;
    u16 x;
    u16 y;
    u8 unk_40;
    u8 unk_41;
    u16 unk_42;
    u8 unk_44;
    u8 unk_45[3];
} StockMesDispWork;

typedef struct StockMesDispParam {
    u32 unk_00;
    u32 unk_04;
} StockMesDispParam;

typedef struct StatusWork {
    TaskPool pool;
    u32 unk_14;
    u16 unk_18;
    s16 unk_1A;
    s16 unk_1C;
    u16 unk_1E;
} StatusWork;

typedef struct StatusStocklistWork {
    StatusEntry entries[4];
    void* tiles2[8];
    void* palette;
    void* tiles;
    void* palette2;
    void* gfx;
    s32* unk_4C0;
    u16 unk_4C4;
    u16 unk_4C6;
    u8 unk_4C8;
    u8 unk_4C9[3];
} StatusStocklistWork;

extern s32 gUnk_0203C550;

extern u8 gUnk_08F69BA4[];
extern u8 gUnk_097A2CF6[];
extern u8 gUnk_0984B258[];
extern u8 gUnk_097A2E16[];
extern u8 gUnk_0984B278[];
extern u8 gUnk_097A2DF8[];
extern u8 gUnk_09848198[];
extern u8 gUnk_09848698[];
extern u8 gUnk_097A18EC[];
extern u8 gUnk_0984B1B8[];
extern u8 gUnk_097A18CC[];
extern u8 gUnk_097A1864[];
extern u8 gUnk_097A1898[];
extern u8 gUnk_097A24A6[];
extern u8 gUnk_0984B218[];
extern u8 gUnk_097A28DA[];
extern u8 gUnk_0984B238[];
extern u8 gUnk_09618118[];
extern u8 gUnk_0891ED26[];
extern u8 gUnk_08F683A4[];
extern u8 gUnk_088E33C2[];
extern u8 gUnk_0984B1D8[];
extern u8 gUnk_097A1C54[];
extern u8 gUnk_097A2394[];
extern u8 gUnk_0984B1F8[];

u8 func_080D7B94(void);
void func_080D764C(StatusWork* work);
s16 func_080D78A8(void);
u16 func_080D82D4(void);
u16 func_080D8308(void);
u8 func_080D8340(void);
void func_080D8474(u16 a);
s32 func_080D855C(s16 a);
void func_080D8584(StatusEntry* e);
void func_080D8590(StatusEntry* e, s32 v);
s32 func_080D85A8(u32 a);
void* func_080A2334(u16 a, u8 b);
u8 func_080A235C(u16 a);
void* func_080D85C0(u16 a);
s32 func_080D85F8(s32 a);
s16 func_080D885C(StatusScrollcursorWork* work);
void func_080D8374(void);
void* CreateStockMesDispTask(void* a, u16 b, u8 c, u16 d, s32 e);
u8 func_080D8F04(void* a);

void func_080D78B8(StatusBarWork* work);
u8 func_080D7890(void);
void func_080D83F4(void);

#endif /* GUARD_STATUS_H */
