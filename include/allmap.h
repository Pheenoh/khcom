#include "card_lookup_data.h"
#include "registration_data.h"
#ifndef GUARD_ALLMAP_H
#define GUARD_ALLMAP_H


#include "poo_api.h"

#include "obj.h"

#include "field_state.h"

#include "allmap_types.h"

#include "card_api.h"

#include "map_api.h"
#include "task.h"
#include "mode_pooh_api.h"

#include "mode_allmap_api.h"

#include "save_api.h"

#include <string.h>
#include <stdlib.h>
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
#include "m4a.h"
#include "anim.h"
#include "mode.h"
#include "key.h"
#include "bos4_api.h"
#include "allmap_api.h"
#include "mode_battle_data.h"

typedef struct AllmapRoomnameWork {
    u8 unk_000[0xC8];
#ifdef VERSION_EU
    u8 unkEu_0C8[0x60];
#endif
    void* palette;
    u8 unk_0CC;
    u8 unk_0CD;
    u16 x;
} AllmapRoomnameWork;

typedef struct AllmapRoomArg {
    u32 unk_00 : 16;
    u32 unk_02 : 16;
    u32 unk_04 : 8;
    u32 unk_05 : 8;
    u32 unk_06 : 16;
} AllmapRoomArg;

typedef struct AllmapBarWork {
    void* tiles;
    void* tiles2;
    void* palette;
    u16 unk_0C;
    u8 unk_0E[0x02];
    s32 y;
    s32 unk_14;
    s32 y2;
    s32 unk_1C;
    s32 x;
    s32 unk_24;
    u32 state;
    u8 unk_2C;
    u8 unk_2D;
    u8 unk_2E[0x802];
} AllmapBarWork;

typedef struct AllmapCursorPos {
    u16 x;
    u16 y;
} AllmapCursorPos;

typedef struct AllmapCursorWork {
    void* tiles;
    void* palette;
    void* gfx;
    AnimState anim;
    s16 unk_24;
    s16 unk_26;
    s32 unk_28;
    s32 unk_2C;
    AllmapCursorPos pos;
    s32 x;
    s32 y;
    s32 unk_3C;
    s32 unk_40;
    u16 unk_44;
    u8 unk_46[0x02];
} AllmapCursorWork;

typedef struct AllmapState {
    TaskPool tasks;
    Task* roomTasks[32];
    Task* cursorTask;
    Task* roomnameTask;
    Task* pushaTask;
    s16 unk_A0;
    s16 unk_A2;
    s32 unk_A4;
    s32 unk_A8;
    s16 unk_AC;
    s16 unk_AE;
    s16 unk_B0;
    s16 unk_B2;
    u16 unk_B4;
    u16 unk_B6;
    u16 unk_B8;
    u16 unk_BA;
    s32 unk_BC;
    u8 unk_C0;
    u8 unk_C1[0x03];
} AllmapState;

typedef struct AllmapDoorEntry {
    void* tiles;
    void* tiles2;
    u8 unk_08[0x04];
    ObjPalette* palette;
    ObjPalette* palette2;
    ObjPalette* palette3;
    void* gfx;
    void* gfx2;
    u8 unk_20[0x14];
} AllmapDoorEntry;

typedef struct AllmapDoorinfoWork {
    AllmapCursorPos pos;
    u8 unk_004;
    u8 unk_005[0x03];
    void* gfx2[4];
    void* tiles;
    AllmapDoorEntry doors[4];
    void* palette;
    void* tiles2;
    void* palette2;
    void* gfx;
    s16 unk_0FC;
    s16 unk_0FE;
    u16 unk_100;
    u8 unk_102[0x02];
    s32 x;
    s32 y;
    s32 unk_10C;
    s32 unk_110;
    u16 unk_114;
    u8 unk_116;
    u8 unk_117;
} AllmapDoorinfoWork;

typedef struct AllmapPushaWork {
    void* tiles;
    void* palette;
    void* gfx;
    AllmapCursorWork* cursor;
    u16 angle;
    s16 y2;
    TaskPool tasks;
    Task* task;
    s16 x;
    s16 y;
} AllmapPushaWork;

void func_080D510C(AllmapState* s);
void func_080D55E4(void);
void func_080D53F8(void);
void func_080D58AC(u16 a, u16 b, u16 c, u16 d);
void func_08098778(AllmapDoorEntry* e);
u8 func_080D3A70(u8 a, u8 b);
u8 func_080D3AB8(u8 a, u8 b);
s16 func_080D3D40(u16 a);
s32 func_080D3DCC(u8 a);
void func_080D3ED0(void);
void func_080D3F10(AllmapBarWork* work);
void func_080D3FD4(AllmapBarWork* work);
u8 func_080D422C(AllmapCursorPos a);
void func_080D42D4(AllmapDoorinfoWork* work);
void func_080D44D4(AllmapDoorinfoWork* work);
void func_080D484C(AllmapDoorinfoWork* work);
void func_080D49EC(AllmapDoorinfoWork* work);
u8 IsStockMesDispActive(void);
s32 func_080D5494(AllmapCursorPos a);
void func_080D576C(u8 a, u16 b, u16 c);
void* func_080986FC(u8 a);
void func_08098014(AllmapDoorEntry* a, void* b);
void func_08098598(s32 a, s32 b, AllmapDoorEntry* c);

extern u8 gUnk_0203C590[];
extern u8 gUnk_05000160[];
extern u8 gUnk_0976D880[];
extern u8 gUnk_0976DB68[];
extern u8 gUnk_0976DB9C[];
extern u8 gUnk_0976DC9C[];
extern u8 gUnk_0983AD98[];
extern u8 gUnk_0983B298[];
extern u8 gUnk_0983B7B4[];
extern u8 gUnk_0984A078[];
extern u8 gUnk_0984A0F8[];
extern u8 gUnk_0984A118[];
extern u8 gUnk_0984A138[];
extern u8 gUnk_0984A1D8[];
extern u8 gUnk_09618D38[];
extern u8 gUnk_0905E3BA[];
extern u8 gUnk_0984A1F8[];

extern u8 gUnk_0203C538;
extern s16 gUnk_0203C53C;
extern s16 gUnk_0203C540;

#endif /* GUARD_ALLMAP_H */
