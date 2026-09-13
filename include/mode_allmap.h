#ifndef GUARD_MODE_ALLMAP_H
#define GUARD_MODE_ALLMAP_H

#include "allmap_bottom_state.h"

#include "allmap_scroll_state.h"

#include "allmap_top_state.h"

#include "allmap_types.h"

#include "map_api.h"
#include "mode_allmap_api.h"

#include "display.h"
#include "game_state.h"
#include "fade.h"
#include "obj_api.h"
#include "types.h"
#include "m4a.h"
#include "taskpool.h"
#include "intr.h"
#include "gba/syscall.h"
#include "main.h"
#include "anim.h"
#include "engine.h"
#include "bos4_api.h"
#include "poo_api.h"
#include "allmap_api.h"

#define REG_DISPSTAT (*(vu16*)0x04000004)
#define REG_IE (*(vu16*)0x04000200)
#define REG_IME (*(vu16*)0x04000208)

typedef struct AllmapRoomOrder {
    s32 unk_00[16];
} AllmapRoomOrder;

typedef struct AllmapRoomDirs {
    s32 unk_00[4];
} AllmapRoomDirs;

extern u16 gUnk_02034E38;
extern u16 gUnk_02034E3A;
extern TaskPool gUnk_0203C4F0;
extern u8 gMPlayInfo_BGM[];
extern u8 gUnk_05000140[];
extern u8 gUnk_08125E24[];
extern AllmapRoomOrder gUnk_096FDB70;
extern AllmapRoomDirs gUnk_096FDBB0;
extern u8 gUnk_0976B340[];
extern u8 gUnk_0976DEDC[];
extern u8 gUnk_0976E4D4[];
extern u8 gUnk_097B62B8[];
extern u8 gUnk_0983AD98[];
extern u8 gUnk_0984A0F8[];
extern u8 gUnk_09849F78[];
extern u8 gUnk_09EF64FC[];
extern u8 gUnk_09EF653C[];
extern u8 gUnk_09EF654C[];
extern u8 gUnk_09EF658C[];
extern TaskDesc gTaskDescAllmapBar;

void func_080D4EBC(void);
void func_080D51D8(void);
void func_080D53A8(void);

void mode_allmap_0(s32 a);
void func_080D3370(void);
void mode_allmap_1(void);
void mode_allmap_2(void);
u8 func_080D3538(u8 a, u8 b);

#endif /* GUARD_MODE_ALLMAP_H */
