#ifndef GUARD_POO_DATA_H
#define GUARD_POO_DATA_H

#include "types.h"

typedef struct PooPoint {
    s32 unk_00;
    s32 unk_04;
} PooPoint;

typedef struct PooSpot {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} PooSpot;

typedef struct PooMapBgDesc {
    void* unk_00;
    u16 unk_04;
    u16 unk_06;
    void* unk_08;
    u16 unk_0C;
    u16 unk_0E;
    void* unk_10;
    u16 unk_14;
    u8 unk_16;
    u8 unk_17;
} PooMapBgDesc;

extern PooSpot gUnk_096FC05C[];
extern PooSpot gUnk_096FC2F0[];
extern const PooPoint gUnk_096FC6B0[];
extern PooMapBgDesc gUnk_096FC6E0;
extern const PooSpot gUnk_096FD778[];

#endif
