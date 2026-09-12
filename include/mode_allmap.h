#ifndef GUARD_MODE_ALLMAP_H
#define GUARD_MODE_ALLMAP_H

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

#define REG_DISPSTAT (*(vu16*)0x04000004)
#define REG_IE (*(vu16*)0x04000200)
#define REG_IME (*(vu16*)0x04000208)
typedef struct AllmapRoomWork {
    u32 tiles;
    u32 palette;
    u32 unk_008;
    void* unk_00C[4];
    void* gfx[4];
    AnimState anim[4];
    u16 unk_08C;
    u16 unk_08E;
    u32 unk_090;
    u32 unk_094;
    u8 unk_098;
    u8 unk_099;
    u16 unk_09A;
    u16 unk_09C;
    u8 unk_09E[0x02];
} AllmapRoomWork;

typedef struct AllmapRoomOrder {
    s32 unk_00[16];
} AllmapRoomOrder;

typedef struct AllmapRoomDirs {
    s32 unk_00[4];
} AllmapRoomDirs;

extern u16 gUnk_02034E38;
extern u16 gUnk_02034E3A;
extern u8 gUnk_0203C4C0[];
extern u32 gUnk_0203C4E0;
extern TaskPool gUnk_0203C4F0;
extern void* gUnk_0203C504;
extern u16 gUnk_0203C508;
extern u8 gUnk_0203C510[];
extern void* gUnk_0203C530;
extern u16 gUnk_0203C534;
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

void func_080D2F20(void);
void func_080D2F64(void);
void func_080D3008(void);
void func_080D3034(s16 a);
void func_080D3050(void);
void func_080D30C8(void);
void func_080D313C(void);
void func_080D4D44(void);
void func_080D4EBC(void);
void func_080D51D8(void);
void func_080D53A8(void);
u8 func_080D5944(u8 a, s32 b);
u8* func_080DED98(u8 a);
u16 func_080DEE44(u8 a, u8 b);
u8 func_080DF51C(u8 a);
void func_080E052C(u8 a);

void mode_allmap_0(s32 a);
void func_080D3370(void);
void mode_allmap_1(void);
void mode_allmap_2(void);
void func_080D352C(u8 a);
u8 func_080D3538(u8 a, u8 b);
u8 func_080D3564(u8 a, u8 b);
u8 func_080D358C(u8 a, u8 b);
s32 func_080D35B0(AllmapRoomWork* work);
s32 func_080D37BC(u8 a);

#endif /* GUARD_MODE_ALLMAP_H */
