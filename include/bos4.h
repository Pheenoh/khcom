#ifndef GUARD_BOS4_H
#define GUARD_BOS4_H

#include "types.h"
#include "game.h"

typedef struct BoogieKnifereaderWork {
    u8 unk_000[0x8];
    u32 unk_008;
    u8 unk_00C[0x10];
    u32 unk_01C;
    u8 unk_020[0x120];
} BoogieKnifereaderWork;

typedef struct UrsulaBubbleWork {
    u32 unk_000;
    u32 unk_004;
    u8 unk_008[0x38];
    u16 unk_040;
    u8 unk_042[0x2];
} UrsulaBubbleWork;

typedef struct UrsulaMapanimeWork {
    u32 unk_000;
    u8 unk_004[0x4];
    u32 unk_008;
    u32 unk_00C;
    u32 unk_010;
    u8 unk_014[0x10];
    u32 unk_024;
    u8 unk_028;
    u8 unk_029[0x3];
} UrsulaMapanimeWork;

typedef struct UrsulaBorderWork {
    u32 unk_000;
    u32 unk_004;
} UrsulaBorderWork;

typedef struct BoogieSakuWork {
    u32 unk_000;
    u32 unk_004;
    u32 unk_008;
    u8 unk_00C[0x14];
    u16 unk_020;
    u8 unk_022[0x2];
    u32 unk_024;
    u32 unk_028;
    u8 unk_02C[0x10];
    u32 unk_03C;
    u8 unk_040;
    u8 unk_041[0x3];
} BoogieSakuWork;

typedef struct BoogieKnifeWork {
    u32 unk_000;
    u16 unk_004;
    u8 unk_006[0x2];
    u32 unk_008;
    u32 unk_00C;
    u32 unk_010;
    u32 unk_014;
    u8 unk_018[0x18];
    u32 unk_030;
    u32 unk_034;
    u32 unk_038;
    u8 unk_03C[0x30];
    u32 unk_06C;
    u8 unk_070[0xCC];
    u32 unk_13C;
    u32 unk_140;
    u8 unk_144[0x4];
    u32 unk_148;
    u32 unk_14C;
    u32 unk_150;
    u32 unk_154;
} BoogieKnifeWork;

typedef struct UrsulaBacktakoWork {
    u32 unk_000;
    u32 unk_004;
    u32 unk_008;
    u32 unk_00C;
    u8 unk_010[0x4];
    u16 unk_014;
    u8 unk_016[0xA];
    u16 unk_020;
    u8 unk_022;
    u8 unk_023[0x1];
    u32 unk_024;
    u32 unk_028;
    u32 unk_02C;
    u32 unk_030;
    u32 unk_034;
    u32 unk_038;
    u32 unk_03C;
    u32 unk_040;
} UrsulaBacktakoWork;

typedef struct BoogieKaihukuWork {
    u32 unk_000;
    u16 unk_004;
    u8 unk_006[0x2];
    u32 unk_008;
    u32 unk_00C;
    u32 unk_010;
    u32 unk_014;
    u8 unk_018[0x28];
    u32 unk_040;
    u32 unk_044;
    u32 unk_048;
    u32 unk_04C;
    u8 unk_050[0x24];
    u32 unk_074;
    u32 unk_078;
    u8 unk_07C[0xD8];
    u32 unk_154;
} BoogieKaihukuWork;

u8 func_080DEBAC(u8 a);
void func_080DEC44(void);
u8* func_080DED98(u8 a);
void func_080D2C78(s32 a);
void func_080D2DB0(s32 a);
void func_080D2DC4(s32 a);
s32 func_080E5590(u8 a);
void func_080E04EC(void);

u16 func_080DDEA0(u16* p);
void func_080DDEA4(s32 a);
void func_080DDEB0(s32 a);
void func_080DDEBC(s32 a);
void func_080DDDDC(u8* p, void* q);
u8* func_080DEE18(u8 index);
u8 func_080DEE28(u8 a, u8 b);
u32 func_080DF804(u8 index);
void func_080DF730(u8 a, u8 b);
void func_080DF814(void);
s32 func_080DFB7C(u8 a);
u8 func_080DC510(void);
u8 func_080DC528(void);
u8 func_080DA73C(void);
u8 func_080DB428(u8* p);
u8 func_080DC628(void);
u8 func_080DCA78(u8 a);
void task_bos_ursula_border_3(UrsulaBorderWork* work);
void task_bos_ursula_backtako_3(UrsulaBacktakoWork* work);
void task_bos_boogie_saku_3(BoogieSakuWork* work);
void task_bos_boogie_knife_3(BoogieKnifeWork* work);
void task_bos_boogie_kaihuku_3(BoogieKaihukuWork* work);
void func_0801B7D8(void* a);
void func_08012304(void* a);
void func_080028C0(void* a);
void func_08002C10(void* a);
void func_08000F0C(void* a);

void task_bos_boogie_knifereader_2(BoogieKnifereaderWork* work);
void task_bos_boogie_knifereader_3(BoogieKnifereaderWork* work);
void task_bos_boogie_mapanime_2(void);
void task_bos_boogie_mapanime_3(void);
void task_bos_ursula_thunder_2(void);
void task_bos_ursula_thunder_3(void);
void task_bos_ursula_map_3(void);
s32 task_bos_ursula_border_1(void);
void task_bos_ursula_bubble_2(UrsulaBubbleWork* work);
void task_bos_ursula_bubble_3(UrsulaBubbleWork* work);
void task_bos_ursula_mapanime_2(UrsulaMapanimeWork* work);
void task_bos_ursula_mapanime_3(UrsulaMapanimeWork* work);

#endif /* GUARD_BOS4_H */
