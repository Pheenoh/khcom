#ifndef GUARD_MODE_BACKUPSTAT_H
#define GUARD_MODE_BACKUPSTAT_H

#include "types.h"
#include "taskpool.h"
#include "evt_types.h"
#include "main.h"
#include "mode.h"

typedef struct PcAnimStep {
    u16 unk_00;
    u8 unk_02[0x1C];
    s16 unk_1E;
    s16 unk_20;
    s16 unk_22;
} PcAnimStep;

typedef struct PcSpriteCmd {
    u8 unk_00;
    u8 unk_01;
    s16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u8 unk_08[0x04];
} PcSpriteCmd;

typedef struct PcSpriteDef {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
} PcSpriteDef;

typedef struct PcGfxSet {
    void* unk_00;
    u16 unk_04;
    u8 unk_06[0x02];
    void* unk_08;
    u16 unk_0C;
    u8 unk_0E[0x02];
} PcGfxSet;

typedef struct PcEnv {
    s16 unk_00;
    u8 unk_02[0x03];
    u8 unk_05;
    u8 unk_06[0x0E];
} PcEnv;

typedef struct PcOam {
    u16 count;
    u16 attr[0x95];
} PcOam;

typedef struct PcWork {
    u8 unk_000[0x0A];
    s16 unk_00A;
    s16 unk_00C;
    u8 unk_00E[0x0A];
    u8 unk_018;
    u8 unk_019[0x07];
    s32 unk_020;
    s32 unk_024;
    s32 unk_028;
    PcAnimStep* unk_02C;
    s16 unk_030;
    s16 unk_032;
    s16 unk_034;
    s16 unk_036;
    u8 unk_038;
    u8 unk_039;
    s16 unk_03A;
    s16 unk_03C;
    u8 unk_03E[0x02];
    void* unk_040;
    void* unk_044[2];
    void* unk_04C;
    void* unk_050;
    u8 unk_054[0x280];
    Task* unk_2D4[4];
    Task* unk_2E4;
    PcEnv unk_2E8;
    PcOam unk_2FC[24];
} PcWork;

typedef struct PcSpawnArg {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    void* unk_10;
} PcSpawnArg;

typedef struct BtlWork {
    s32 unk_000;
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
    u8 unk_010[0x1C];
    TaskPool unk_02C;
    u8 unk_040[0x3C];
    PcSpawnArg* unk_07C;
    u8 unk_080[0x58];
    u16 unk_0D8;
    u8 unk_0DA[0xF6];
} BtlWork;

typedef struct BackupStatEntry {
    const char* name;
    s32 unk_04;
} BackupStatEntry;

extern BtlWork* gBtlWork;
extern UnkStruct_02039DC8* gUnk_02039DC8;
extern PcAnimStep gUnk_09A4C278[];
extern PcGfxSet gUnk_09A4AC84[];
extern PcSpriteDef* gUnk_09EFBB18[];
extern u8 gUnk_09D69274[];
extern u8 gUnk_08F69BC4[];
extern Mode gModeDebug;
extern BackupStatEntry gUnk_099937E4[];
extern const char gUnk_09993874[];
extern const char gUnk_09993878[];
extern const char gUnk_09993880[];
extern const char gUnk_09993888[];
extern const char* gUnk_09EF9668[];
extern u8 gWhitePalette[];
extern TaskDesc gTaskDescBosPcFlt;
extern TaskDesc gTaskDescBosPcAcd;
extern u8 gUnk_09D69374[];
extern u8 gUnk_05000080[];
extern u16 gUnk_09A4C9EC[];
extern s16 gUnk_09A4C9F2[];
extern PcAnimStep gUnk_09A4AF34[];
extern u8 gUnk_09A3DF34[];
extern PcSpriteCmd* gUnk_09EF9C34[];
extern void* gUnk_09EFAB18[];
extern u8 gUnk_05000000[];
extern PcAnimStep* gUnk_09EF9DB4[];

u16 func_0801AF1C(s32 a);
void LoadPalette(void* src, void* dst, s32 size);
u8 func_0801CA00(void* a);
void WorldToScreen(s16* a, s16* b, s32 c, s32 d, s32 e);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, s32 h);
void LoadBgTiles(s32 bg, void* src, u16 size);
void LoadBgMap(s32 bg, void* src, u16 size);
void SetBgScroll(s32 a, u16 b, u16 c);
void SetBgMode0(void);
void EnableBg(s32 a);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
u16 GetKeysRepeat(void);
void ModeRequest(Mode* mode, s32 arg);
void func_0805FA60(s32 a, void* b, s32 c, u8 d);
void func_0805FA8C(u8 a, s16 b, s16 c);
void func_0805FCB0(u8 a, u8 b, u32 c, const char* d);
void func_08060598(void);
void func_080605A4(u8 a);
void func_080609A0(void);
int SaveCheckHeaderSlot(s16 slot);
int SaveCheckSystemSlot(s16 slot);
int SaveCheckFileLargeSlot(s16 file, s16 slot);
int SaveCheckFileSmallSlot(s16 file, s16 slot);
void SaveSetHeaderState(s16 slot, s16 state);
void SaveSetSystemState(s16 slot, s16 state);
void SaveSetFileLargeState(s16 file, s16 slot, s16 state);
void SaveSetFileSmallState(s16 file, s16 slot, s16 state);

s32 func_08109EA8(s32 a);
void mode_backupstat_0(void);
void mode_backupstat_1(void);
void mode_backupstat_2(void);
void func_081097F4(void);
PcAnimStep* func_08109EB0(PcWork* work);
void* func_08109ECC(PcWork* work);
void func_08109EF8(PcWork* work, s32 a);
void func_08109F20(PcWork* work);
void func_0810A018(PcWork* work);
u16 func_08109FF0(PcWork* work, s32 a);
u16 func_0810A000(PcWork* work, s32 a, s32 b);
void func_0810A444(PcWork* work);
void func_0810A454(PcWork* work);
void func_0810A498(PcWork* work);
u8 func_0810A424(PcWork* work);
void func_0810A4C4(PcWork* work);
void func_0810A4CC(PcWork* work, u16 a, s32 b, s32 c, s32 d, u8 e);
void func_0810A51C(PcWork* work, TaskPool* pool);

#endif /* GUARD_MODE_BACKUPSTAT_H */
