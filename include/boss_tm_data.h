#ifndef GUARD_BOSS_TM_DATA_H
#define GUARD_BOSS_TM_DATA_H

#include "types.h"

typedef struct WlogoTtEffStep {
    s16 unk_00;
    s16 unk_02;
    u8 unk_04;
    u8 unk_05[0x3];
    s16 unk_08;
    s16 unk_0A;
    u8 unk_0C;
    u8 unk_0D[0x3];
    s16 unk_10;
    s16 unk_12;
    u8 unk_14[0x2];
    s16 unk_16;
    s16 unk_18;
    s16 unk_1A;
    u8 unk_1C[0x2];
    s16 unk_1E;
} WlogoTtEffStep;

typedef struct TmFootStep {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    s16 unk_0E;
    s16 unk_10;
    s16 unk_12;
    u8 unk_14[0x4];
    s16 unk_18;
    s16 unk_1A;
    u8 unk_1C[0x4];
} TmFootStep;

extern u8 gUnk_09EF1D58[11];
extern s16 gUnk_09EF1D64[8];
extern s16 gUnk_09EF1D74[10];
extern WlogoTtEffStep gUnk_09EF1D88[3];
extern WlogoTtEffStep gUnk_09EF1DE8;
extern s16 gUnk_09EF1E08[3];
extern s16 gUnk_09EF1E0E;
extern s16 gUnk_09EF1E10;
extern s16 gUnk_09EF1E12;
extern WlogoTtEffStep gUnk_09EF1E14[16];
extern WlogoTtEffStep gUnk_09EF2014;
extern WlogoTtEffStep gUnk_09EF2034[9];
extern WlogoTtEffStep gUnk_09EF2154;
extern WlogoTtEffStep gUnk_09EF2174;
extern s8 gUnk_09EF2194[4];
extern u8 gUnk_09EF21B0[8];
extern s16 gUnk_09EF21B8[5];
extern s16 gUnk_09EF21C2;
extern TmFootStep gUnk_09EF21C4[3];
extern TmFootStep gUnk_09EF2224;
extern TmFootStep gUnk_09EF2244[16];
extern TmFootStep gUnk_09EF2444;
extern TmFootStep gUnk_09EF2464[10];
extern TmFootStep gUnk_09EF25A4[9];
extern TmFootStep gUnk_09EF26C4;

#endif
