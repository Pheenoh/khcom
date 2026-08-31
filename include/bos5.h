#ifndef GUARD_BOS5_H
#define GUARD_BOS5_H

#include "types.h"
#include "game.h"

typedef struct GaEntry {
    void* unk_00;
    void* unk_04;
    u16 unk_08;
    u8 unk_0A[0x42];
} GaEntry;

typedef struct MdHahenWork {
    s32 unk_000;
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
    s32 unk_010;
    s32 unk_014;
    u32 unk_018;
    u32 unk_01C;
    u32 unk_020;
    u16 unk_024;
    u8 unk_026[0x2];
} MdHahenWork;

typedef struct MdDaiWork {
    u32 unk_000;
    u32 unk_004;
    u32 unk_008;
    u32 unk_00C;
    u16 unk_010;
    u8 unk_012[0x2];
    u32 unk_014;
    u32 unk_018;
    u32 unk_01C;
    u8 unk_020[0x58];
    u32 unk_078;
    u16 unk_07C;
    u16 unk_07E;
    u32 unk_080;
} MdDaiWork;

typedef struct MdFireWork {
    u32 unk_000;
    u8 unk_004[0x2];
    u16 unk_006;
    u16 unk_008;
    u8 unk_00A[0x2];
    u32 unk_00C;
    u32 unk_010;
    u32 unk_014;
    u32 unk_018;
    u8 unk_01C[0x14];
    u32 unk_030;
    u16 unk_034;
    u8 unk_036[0x2];
    u32 unk_038;
    u32 unk_03C;
    u32 unk_040;
    u32 unk_044;
    u8 unk_048[0x1C];
    u16 unk_064;
    u16 unk_066;
    u8 unk_068[0x4];
    u32 unk_06C;
    u32 unk_070;
    u8 unk_074[0x4];
    u32 unk_078;
    u8 unk_07C[0xCC];
    u32 unk_148;
    u32 unk_14C;
    u32 unk_150;
    u8 unk_154[0xA];
    u16 unk_15E;
    u16 unk_160;
    u8 unk_162[0xE];
} MdFireWork;

typedef struct GaEntryWork {
    u8 unk_000[0x1A8];
} GaEntryWork;

typedef struct GaWork {
    u32 unk_000;
    u32 unk_004;
    u32 unk_008;
    u8 unk_00C[0x2];
    u16 unk_00E;
    u16 unk_010;
    u16 unk_012;
    u16 unk_014;
    u8 unk_016[0x2];
    u32 unk_018;
    u8 unk_01C;
    u8 unk_01D[0x3];
    GaEntryWork entries[6];
    u8 unk_A10[0x18];
    u32 unk_A28;
    u8 unk_A2C[0x4];
    u32 unk_A30;
    u32 unk_A34;
    u8 unk_A38[0x18];
    u16 unk_A50;
    u8 unk_A52[0x2];
} GaWork;

typedef struct MdModel {
    u16 unk_00;
    s16 unk_02;
    u32 unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    u8 unk_14[0x04];
} MdModel;

typedef struct MdSlot {
    u8 unk_00[0x0C];
    void* unk_0C;
    void* unk_10;
    void* unk_14;
} MdSlot;

extern MdModel gUnk_09992F70[];
extern MdSlot gUnk_02034FF8[];
extern u8 gUnk_09A3CDDC[];
extern u8 gUnk_099EDE7C[];
extern u8 gUnk_099A8914[];

u8 func_080D2DD8(void);

typedef struct MdWork {
    u32 unk_000;
    u32 unk_004;
    u32 unk_008;
    u8 unk_00C[0x8];
    u16 unk_014;
    u16 unk_016;
    u16 unk_018;
    u16 unk_01A;
    u8 unk_01C;
    u8 unk_01D[0x3];
    u32 unk_020;
    u32 unk_024;
    u32 unk_028;
    u32 unk_02C;
    u8 unk_030[0x10];
    u32 unk_040;
    u8 unk_044[0x24];
    u32 unk_068;
    u8 unk_06C[0x30];
    u32 unk_09C;
    u32 unk_0A0;
    u8 unk_0A4[0x4];
    u32 unk_0A8;
    u8 unk_0AC[0xD0];
    u32 unk_17C;
    u8 unk_180[0x10];
    u32 unk_190;
    u8 unk_194[0x20];
    u16 unk_1B4;
    u8 unk_1B6[0x2];
} MdWork;

void func_0800501C(s32 bg);
void func_08012304(void* a);
void func_0801B7D8(void* a);
void ReleaseObjTiles(void* a);
void ReleaseObjPalette(void* a);
void TaskPoolDestroy(void* a);

s32 GetRandom(void);
void func_080058FC(void* a, s32 b, u16 c);
void* AnimUpdate(void* a);

extern s16 gSineTable[];
extern u8 gUnk_09A3C9BC[];
extern u8 gUnk_09999ED0[];
extern u32 gUnk_09EF9740[];

void func_080FCC14(MdFireWork* work);
u8 func_080FCCB4(MdFireWork* work);
void func_08012324();
void func_080122AC(void* a, s32 b, s32 c, s32 d);
void func_08012614(void* a, s32 b);
void func_080F83E0(void* a, void* b);
void func_080F8374(void* a);

extern u8 gUnk_09992114[];
extern GaEntry gUnk_09992108[];

s32 task_bos_md_hahen_1(MdHahenWork* work);
void task_bos_md_hahen_2(MdHahenWork* work);
void task_bos_md_dai_0(MdDaiWork* work, s32* src);
void task_bos_md_hahen_0(MdHahenWork* work, s32* src);
u8 task_bos_md_fire_1(MdFireWork* work);
void task_bos_md_fire_2(MdFireWork* work);
void task_bos_md_3(MdWork* work);
void func_080FD9B8(u16 model, u16 slot);
void func_080FDA28(u16 model, u16 slot);
s16 func_080FDA98(u16 model, u16 slot);
extern u32 gFrameCounter;

void task_bos_ga_2(GaWork* work);
void task_bos_ga_3(GaWork* work);
void task_bos_md_hahen_3(MdHahenWork* work);
void task_bos_md_fire_3(MdFireWork* work);
void task_bos_md_dai_3(MdDaiWork* work);
void func_080FB8E8(s32 unused, u16 index);
void func_080FB908(s32 unused, u16 index);

#endif /* GUARD_BOS5_H */
