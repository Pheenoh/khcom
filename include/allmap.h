#ifndef GUARD_ALLMAP_H
#define GUARD_ALLMAP_H

#include "types.h"
#include "text_types.h"
#include "taskpool.h"
#include "main.h"
#include "m4a.h"
#include "anim.h"
#include "mode.h"
typedef struct AllmapRoomWork {
    void* tiles;
    void* palette;
    void* unk_008;
    void* unk_00C[4];
    void* unk_01C[4];
    AnimState unk_02C[4];
    s16 unk_08C;
    s16 unk_08E;
    s32 unk_090;
    s32 unk_094;
    u8 unk_098;
    u8 unk_099;
    u16 unk_09A;
    u16 unk_09C;
    u8 unk_09E[0x02];
} AllmapRoomWork;

typedef struct AllmapRoomnameWork {
    u8 unk_000[0xC8];
    void* palette;
    u8 unk_0CC;
    u8 unk_0CD;
    u16 unk_0CE;
} AllmapRoomnameWork;

typedef struct UnkStruct_02039BA0 {
    u8 unk_00[0x70];
    u32 unk_70;
} UnkStruct_02039BA0;

typedef struct AllmapRoomArg {
    u32 unk_00 : 16;
    u32 unk_02 : 16;
    u32 unk_04 : 8;
    u32 unk_05 : 8;
    u32 unk_06 : 16;
} AllmapRoomArg;

typedef struct GameState {
    u8 unk_00[0x08];
    u32 flags;
} GameState;

typedef struct AllmapBarWork {
    void* unk_00;
    void* unk_04;
    void* palette;
    u16 unk_0C;
    u8 unk_0E[0x02];
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    u32 unk_28;
    u8 unk_2C;
    u8 unk_2D;
    u8 unk_2E[0x802];
} AllmapBarWork;

typedef struct AllmapCursorPos {
    u16 unk_00;
    u16 unk_02;
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
    AllmapCursorPos unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
    u16 unk_44;
    u8 unk_46[0x02];
} AllmapCursorWork;

typedef struct UnkStruct_0203C4B4 {
    TaskPool unk_00;
    Task* unk_14[32];
    Task* unk_94;
    Task* unk_98;
    Task* unk_9C;
    s16 unk_A0;
    s16 unk_A2;
    u8 unk_A4[0x08];
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
} UnkStruct_0203C4B4;

typedef struct AllmapPal {
    u8 unk_00[0x06];
    u16 unk_06;
} AllmapPal;

typedef struct AllmapDoorEntry {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x04];
    AllmapPal* unk_0C;
    AllmapPal* unk_10;
    AllmapPal* unk_14;
    void* unk_18;
    void* unk_1C;
    u8 unk_20[0x14];
} AllmapDoorEntry;

typedef struct AllmapDoorinfoWork {
    AllmapCursorPos unk_000;
    u8 unk_004;
    u8 unk_005[0x03];
    void* unk_008[4];
    void* unk_018;
    AllmapDoorEntry unk_01C[4];
    void* palette;
    void* unk_0F0;
    void* unk_0F4;
    void* unk_0F8;
    s16 unk_0FC;
    s16 unk_0FE;
    u16 unk_100;
    u8 unk_102[0x02];
    s32 unk_104;
    s32 unk_108;
    s32 unk_10C;
    s32 unk_110;
    u16 unk_114;
    u8 unk_116;
    u8 unk_117;
} AllmapDoorinfoWork;

typedef struct AllmapPushaWork {
    void* tiles;
    void* palette;
    void* unk_08;
    AllmapCursorWork* unk_0C;
    u16 unk_10;
    s16 unk_12;
    TaskPool unk_14;
    Task* unk_28;
    s16 unk_2C;
    s16 unk_2E;
} AllmapPushaWork;

void* AllocObjTiles(s32 a, void* b);
void SaveClearSystem(void);
int SaveLoadSystem(void);
void ModeRequest(Mode* mode, s32 arg);
void func_0801CCB4(void);
void func_0801CD20(void);
void func_080AEB94(void);
void func_080E04EC(void);
u8 func_080987C0(u8 a);
void* AnimGetGfx(AnimState* a);
void AnimInit(AnimState* a, s32 b, s32 c);
void AnimStart(AnimState* a, u16 animId, u16 flags);
void* AnimUpdate(AnimState* a);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, u16 h);
void* GetBgScreenBase(s32 bg);
u16 GetKeysRepeat(void);
void LoadBgMap(s32 bg, void* src, u16 size);
void LoadBgPalette(s32 bg, void* src, u16 size);
void* LoadObjPalette(void* a, s32 b);
void* LoadObjTiles(void* a, s32 b);
void LoadPalette(void* src, void* dst, s32 size);
void ReleaseObjPalette(u8* p);
void ReleaseObjTiles(void* a);
u8 RequestDma3Copy(void* src, void* dst, u16 size);
s32 abs(s32 x);
void func_08000DE8(TaskPool* a, Task* t);
u8 IsTaskActive(Task* t);
u16 func_08003524(void* a, s32 b);
void EnableBg(s32 a);
void DisableBg(s32 bg);
void SetBgBlend(s32 a, s32 b, s32 c);
void ApproachValue(s32* value, s32 target, u16 steps);
void func_0800592C(s32* value, s32 target, u16 steps);
void func_08006120(s32 a, u16 b);
void func_08006184(s32 a, u16 b);
void func_080061E8(s32 a, u16 b);
void func_08006238(s32 a, s32 b, s32 c);
void func_080062F4(u16 a, s32 b);
u8 func_08006314(void);
void func_080063A8(void);
void func_08065ACC(TextSlot* p, s32 n);
void func_08065AE0(TextSlot* p, s32 n);
s16 func_08065B08(TextSlot* p, u8 n);
u16 func_08065B6C(u16* a, TextSlot* b);
void func_080664D8(s16 a, s16 b, void* c, void* d, s32 e, u8 f);
void* func_08093C18(u8 a);
void func_08098670(AllmapDoorEntry* e, s32 b);
void func_08098778(AllmapDoorEntry* e);
void func_080C75A4(s32 a, u16 b);
void func_080D352C(u8 a);
u8 func_080D3564(u8 a, u8 b);
u8 func_080D358C(u8 a, u8 b);
s32 func_080D35B0(AllmapRoomWork* work);
s32 func_080D37BC(u8 a);
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
u8 func_080D4D1C(void);
void func_080D4D44(void);
s32 func_080D5494(AllmapCursorPos a);
void func_080D576C(u8 a, u16 b, u16 c);
u8 func_080D5944(u8 a, u16 b);
void func_080D5978(u16 a, void* b, u16 c);
u8* func_080DED98(u8 a);
u8* func_080DEE18(u8 a);
u8 func_080DF51C(u8 a);
void* memcpy(void* dst, const void* src, unsigned long n);

extern s16 gSineTable[];
extern s16 gUnk_02034EC2;
extern u8 gUnk_02034ECA;
extern Mode gModeSioBattle;
extern Mode gModeTitle;
extern Mode gModeMenuNew;
extern Mode gModeMenuLoad;
extern u32 gUnk_02034E98;
extern TaskPool gTitleTaskPool;
extern Task* gTitleLogoTask;
extern Task* gTitleObjTask;
extern u8* gUnk_02034EC4;
extern UnkStruct_02039BA0* gUnk_02039BA0;
extern GameState gGameState;
extern void* gStockMesDispWork;
extern UnkStruct_0203C4B4* gUnk_0203C4B4;
extern u32 gUnk_0203C4E0;
extern void* gUnk_0203C504;
extern u16 gUnk_0203C508;
extern void* gUnk_0203C530;
extern u8 gUnk_0203C538;
extern s16 gUnk_0203C53C;
extern s16 gUnk_0203C540;
extern u8 gUnk_0203C590[];
extern u8 gUnk_05000160[];
extern u8 gUnk_08125E24[];
extern s16 gUnk_096FDC10[][2];
extern u16 gUnk_096FDC30[][2];
extern u8 gUnk_096FDC40[][4];
extern s16 gUnk_096FDC50[4][4];
extern u8 gUnk_0976B340[];
extern u8 gUnk_0976D7C0[];
extern u8 gUnk_0976D880[];
extern u8 gUnk_0976D8A6[];
extern u8 gUnk_0976DB68[];
extern u8 gUnk_0976DB9C[];
extern u8 gUnk_0976DBDA[];
extern u8 gUnk_0976DC9C[];
extern u8 gUnk_0976DCB0[];
extern u8 gUnk_0983AD98[];
extern u8 gUnk_0983B298[];
extern u8 gUnk_0983B7B4[];
extern u8 gUnk_0983F398[];
extern u8 gUnk_0984A078[];
extern u8 gUnk_0984A0F8[];
extern u8 gUnk_0984A138[];
extern u8 gUnk_0984A1D8[];
extern u8 gUnk_0984A1F8[];
extern u8 gUnk_0984A418[];
extern u8 gUnk_0984A818[];
extern TaskDesc gTaskDescAllmapRoom;
extern TaskDesc gTaskDescAllmapRoomname;
extern TaskDesc gTaskDescAllmapDoorinfo;
extern TaskDesc gTaskDescAllmapPusha;
extern TaskDesc gTaskDescTitleLogo;
extern TaskDesc gTaskDescTitleObj;
extern void* gUnk_09EF6424[];
extern void* gUnk_09EF64B4[];
extern u8 gUnk_09EF64C4[];

#endif /* GUARD_ALLMAP_H */
