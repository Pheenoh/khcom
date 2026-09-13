#ifndef GUARD_WORLD_INTRO_DATA_H
#define GUARD_WORLD_INTRO_DATA_H

#include "types.h"

typedef struct WlogoWonEntry {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u16 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    u16 unk_12;
} WlogoWonEntry;

typedef struct WlogoAgrEntry {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    u8 unk_06;
    u8 unk_07;
    u16 unk_08;
    u16 unk_0A;
    u8 unk_0C;
    u8 unk_0D[0x3];
} WlogoAgrEntry;

typedef struct WlogoTtMotion {
    s32 first[6];
    s32 second[6];
} WlogoTtMotion;

extern WlogoWonEntry gUnk_09EF167C[];
extern WlogoWonEntry gUnk_09EF1744[];
extern s32 gUnk_09EF180C[];
extern WlogoAgrEntry gUnk_09EF191C[];
extern WlogoTtMotion gUnk_09EF1B08;
extern s16 gUnk_09EF1B68[][3];
extern s8 gUnk_09EF1C48[];
extern s8 gUnk_09EF1C50[];
extern u8 gUnk_09EF1C70[];
extern s16 gUnk_09EF1C7E[][2];
extern s16 gUnk_09EF1CB6[][2];
extern s16 gUnk_09EF1CEE[];
extern u16 gUnk_09EF1D0A[];

#endif
