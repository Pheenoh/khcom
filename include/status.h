#ifndef GUARD_STATUS_H
#define GUARD_STATUS_H

#include "types.h"
#include "main.h"
#include "engine.h"

typedef struct UnkStruct_02039BB0 {
    u8 unk_000[0x08];
    u32 unk_008;
} UnkStruct_02039BB0;

typedef struct StatusGfxDef {
    u32 unk_00;
    u32* unk_04;
    u16 unk_08;
    u16 unk_0A;
} StatusGfxDef;

typedef struct StatusEntry {
    s32 unk_000[72];
    u16 unk_120;
    u16 unk_122;
} StatusEntry;

typedef struct StatusBarWork {
    void* unk_00;
    void* unk_04;
    u16 unk_08;
    u16 unk_0A;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    u8 unk_24;
    u8 unk_25;
    u8 unk_26[0x6];
} StatusBarWork;

typedef struct StatusTabWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    void* unk_14;
    s32* unk_18;
} StatusTabWork;

typedef struct StatusSoraWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    AnimState anim;
} StatusSoraWork;

typedef struct StatusDecknameWork {
    u8 unk_00[0x50];
    void* unk_50;
    u8 unk_54;
    u8 unk_55[0x3];
    u8* unk_58;
} StatusDecknameWork;

typedef struct StatusCursorWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10[2];
    AnimState anim[2];
    s16* unk_48;
    s16 unk_4C;
    u16 unk_4E;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5C;
} StatusCursorWork;

typedef struct StatusScrollcursorWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u16* unk_0C;
    u16 unk_10;
    s16 unk_12;
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
    s16 unk_04;
    s16 unk_06;
} StatusMessageParam;

typedef struct StatusMessageWork {
    u8 unk_000[0x320];
    u8 unk_320;
    u8 unk_321[3];
    void* unk_324;
    StatusMessageParam unk_328;
} StatusMessageWork;

typedef struct StatusFriendWork {
    void* unk_00[3];
    void* unk_0C[3];
    void* unk_18[3];
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

typedef struct StatusActor {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    u8 unk_14[0x10];
    s32 unk_24;
    u8 unk_28[0x0C];
    u64 unk_34;
    u8 unk_3C[0x7C];
    ListNode unk_B8;
} StatusActor;

typedef struct StatusActorPool {
    u8 unk_00[0x40];
    TaskPool unk_40;
    u8 unk_54[0x2C];
    ListNode unk_80;
    u8 unk_90[0x3C];
    s32 unk_CC;
    s32 unk_D0;
    s32 unk_D4;
} StatusActorPool;

typedef struct StatusDialogSub {
    s32 unk_00;
    u8 unk_04[0x10];
    AnimState unk_14;
} StatusDialogSub;

typedef struct StatusDialogWork {
    s32 unk_000;
    u16 unk_004;
    u16 unk_006;
    void* unk_008;
    void* unk_00C;
    void* unk_010;
    AnimState unk_014;
    TaskPool unk_02C;
    StatusActor unk_040;
    u8 unk_108[0x48];
    s32 unk_150;
    s32 unk_154;
    s32 unk_158;
    s32 unk_15C;
    s32 unk_160;
    void* unk_164;
    s32 unk_168;
    StatusDialogSub* unk_16C;
    u8 unk_170[0x04];
    u8 unk_174;
    u8 unk_175[0x03];
} StatusDialogWork;

typedef struct StatusObjDef {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
} StatusObjDef;

typedef struct StatusAnimDef {
    u32 unk_00;
    u32 unk_04;
    void* unk_08;
    u16 unk_0C;
    u16 unk_0E;
} StatusAnimDef;

typedef struct StatusFriendEntry {
    u16 unk_00;
    u16 unk_02;
} StatusFriendEntry;

typedef struct StatusFriendTable {
    StatusFriendEntry unk_00[8];
} StatusFriendTable;

typedef struct StatusCardDef {
    u8 unk_00[0x10];
    void* unk_10;
    void* unk_14;
    void* unk_18;
    u8 unk_1C[0x18];
} StatusCardDef;

typedef struct StockMesDispWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    void* unk_14;
    void* unk_18;
    void* unk_1C;
    u16 unk_20;
    u16 unk_22;
    TaskPool unk_24;
    void* unk_38;
    u16 unk_3C;
    u16 unk_3E;
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
    void* unk_490[8];
    void* unk_4B0;
    void* unk_4B4;
    void* unk_4B8;
    void* unk_4BC;
    s32* unk_4C0;
    u16 unk_4C4;
    u16 unk_4C6;
    u8 unk_4C8;
    u8 unk_4C9[3];
} StatusStocklistWork;

extern UnkStruct_02039BB0 gUnk_02039BB0;
extern s32 gUnk_0203C550;

extern TaskDesc gUnk_09EF4F20;
extern TaskDesc gUnk_09EF4F38;
extern TaskDesc gUnk_09EF4F50;
extern TaskDesc gUnk_09EF4F68;
extern TaskDesc gUnk_09EF4F80;
extern TaskDesc gUnk_09EF4F98;
extern TaskDesc gUnk_09EF4FB0;
extern TaskDesc gUnk_09EF4FC8;
extern TaskDesc gUnk_09EF4FE0;
extern TaskDesc gUnk_09EF4FF8;

extern u8 gUnk_08F69BA4[];
extern u8 gUnk_097A2CF6[];
extern u8 gUnk_0984B258[];
extern void* gUnk_09EF6948[];
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
extern void* gUnk_09EF6920[];
extern void* gUnk_09EF6934[];
extern u8 gUnk_097A24A6[];
extern u8 gUnk_0984B218[];
extern u8 gUnk_097A28DA[];
extern u8 gUnk_0984B238[];
extern u8 gUnk_09618118[];
extern u8 gUnk_0891ED26[];
extern u8 gUnk_09EDF38C[];
extern u8 gUnk_09EDF374[];
extern u8 gUnk_08F683A4[];
extern u8 gUnk_088E33C2[];
extern u8 gUnk_09EDEE14[];
extern u8 gUnk_09EDEE08[];
extern u8 gUnk_0984B1D8[];
extern void* gUnk_09EF68F0[];
extern void* gUnk_09EF6908[];
extern u8 gUnk_09EF6904[];
extern u8 gUnk_09EF691C[];
extern u8 gUnk_097A1C54[];
extern u8 gUnk_097A2394[];
extern u8 gUnk_0984B1F8[];
extern s32 gUnk_096FDD8C[];
extern StatusGfxDef gUnk_08F7CF18[];
extern StatusAnimDef gUnk_096FDE54[];
extern const StatusFriendTable gUnk_096FDE24;
extern StatusCardDef gCardDefs[];
extern u16 gUnk_02039D2C;
extern u8* gUnk_0203C460;
extern u8 gUnk_0203C564;
extern StatusActor* gUnk_0203C55C;
extern u8 gUnk_0984AF78[];
extern u8 gUnk_08F69BC4[];
extern StatusObjDef gUnk_096FDEE4[];
extern u8 gUnk_096FDF14[];
extern u8 gUnk_096FDF24[];
extern TaskDesc gUnk_09EF5070;
extern TaskDesc gUnk_09EF5058;
extern TaskDesc gUnk_09EF5088;
extern TaskDesc gTaskDescBosShadow;
extern StatusActorPool* gUnk_02039B84;
extern u8 gUnk_0203C558;
extern u16 gUnk_0203C554;
extern u16 gUnk_0203C560;
extern u8 gUnk_0203C568;
extern u8 gUnk_0203C56C;
extern u8 gUnk_0203C570;
extern TaskDesc gUnk_09EF50A0;
extern TaskDesc gUnk_09EF50D0;
extern TaskDesc gUnk_09EF50E8;

void* LoadObjTiles(void* src, s32 size);
void* AllocObjTiles(s32 a, void* b);
u16 func_08003524(void* a, s32 b);
void func_08065ACC(void* a, s32 b);
void func_08065AE0(void* a, s32 b);
u8 func_08065B6C(void* a, void* b);
u8* func_080857BC(u8 index);
u8 GetActiveDeckIndex(void);
void func_080664D8(s16 a, s16 b, void* c, void* d, s32 e, u8 f);
void func_0805F1C0(s32* p, s32 v);
void func_080038E4(void* a, u32 b, u32 c);
void* LoadObjPalette(void* src, s32 size);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, u16 h);
u8 func_0800FBCC(s32 a);
u8 func_0800FD20(s32 a);

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
u16 func_080D8B84(void** a, void** b, void** c);
void* func_080D8EB4(void* a, u16 b, u8 c, u16 d, s32 e);
u8 func_080D8F04(void* a);
void func_08000DE8(void* a, void* b);
void func_0800FD68(s32 a);
void func_0801BDDC(s32 a, s32 b, s32 c, s32 d);
void func_08005974(AnimState* a, u16 b, u16 c, u32 d, u32 e);
void func_080D9A14(void);
void m4aSongNumStart(u16 a);
void func_08006184(s32 a, u16 b);
void func_080D7568(u8 a);
void func_080D78B8(StatusBarWork* work);
u8 func_080D7890(void);
u16 GetKeysRepeat(void);
u16 func_0801AF1C(s32 a);
u8 func_0801CA00(void* a);
void WorldToScreen(s16* a, s16* b, s32 c, s32 d, s32 e);
void func_0801B7D8(void* a);
void func_0801A920(s32 a, s32 b, s32 c, s32 d);
void func_0801B37C(void* a, void* b, s32 c, s32 d, s32 e);
void func_0801C2DC(void* a, s32 b);
void func_080D900C(StatusDialogWork* work, s32 a, u16 b);
u8 func_08000F48(Task* t);
void func_080D83F4(void);

#endif /* GUARD_STATUS_H */
