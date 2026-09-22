#ifndef GUARD_BOSS_PC_DATA_H
#define GUARD_BOSS_PC_DATA_H

#include "types.h"

typedef struct PcAnimStep {
    u16 unk_00;
    u8 unk_02[0x2];
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    u8 unk_0A[0x2];
    u16 unk_0C;
    s16 unk_0E;
    s16 unk_10;
    s16 unk_12;
    s16 unk_14;
    s16 unk_16;
    s16 unk_18;
    u8 unk_1A[0x2];
    u16 unk_1C;
    s16 unk_1E;
    s16 unk_20;
    s16 unk_22;
} PcAnimStep;

extern const PcAnimStep gUnk_09A4AF34[];
extern const PcAnimStep gUnk_09A4B174[];
extern const PcAnimStep gUnk_09A4B3B4[];
extern const PcAnimStep gUnk_09A4B5F4[];
extern const PcAnimStep gUnk_09A4B834[];
extern const PcAnimStep gUnk_09A4BBDC[];
extern const PcAnimStep gUnk_09A4BD20[];
extern const PcAnimStep gUnk_09A4BEAC[];
extern const PcAnimStep gUnk_09A4C278[];
extern const PcAnimStep gUnk_09A4C470[];
extern const PcAnimStep gUnk_09A4C5B4[];
extern const PcAnimStep gUnk_09A4C6F8[];
extern const PcAnimStep gUnk_09A4C818[];
extern const PcAnimStep gUnk_09A4C860[];

typedef struct PcSpriteCmd {
    u8 unk_00;
    u8 unk_01;
    s16 unk_02;
    s16 x;
    s16 y;
    s16 unk_08;
    u16 unk_0A;
} PcSpriteCmd;

extern const PcSpriteCmd gUnk_09A3DF34[];
extern const PcSpriteCmd gUnk_09A3E198[];
extern const PcSpriteCmd gUnk_09A3E3FC[];
extern const PcSpriteCmd gUnk_09A3E660[];
extern const PcSpriteCmd gUnk_09A3E8C4[];
extern const PcSpriteCmd gUnk_09A3EB04[];
extern const PcSpriteCmd gUnk_09A3ED44[];
extern const PcSpriteCmd gUnk_09A3EF84[];
extern const PcSpriteCmd gUnk_09A3F1C4[];
extern const PcSpriteCmd gUnk_09A3F3E0[];
extern const PcSpriteCmd gUnk_09A3F5D8[];
extern const PcSpriteCmd gUnk_09A3F7F4[];
extern const PcSpriteCmd gUnk_09A3F9EC[];
extern const PcSpriteCmd gUnk_09A3FC2C[];
extern const PcSpriteCmd gUnk_09A3FE90[];
extern const PcSpriteCmd gUnk_09A400F4[];
extern const PcSpriteCmd gUnk_09A40358[];
extern const PcSpriteCmd gUnk_09A405BC[];
extern const PcSpriteCmd gUnk_09A40820[];
extern const PcSpriteCmd gUnk_09A409F4[];
extern const PcSpriteCmd gUnk_09A40B80[];
extern const PcSpriteCmd gUnk_09A40D0C[];
extern const PcSpriteCmd gUnk_09A40E98[];
extern const PcSpriteCmd gUnk_09A410FC[];
extern const PcSpriteCmd gUnk_09A41360[];
extern const PcSpriteCmd gUnk_09A415A0[];
extern const PcSpriteCmd gUnk_09A417BC[];
extern const PcSpriteCmd gUnk_09A419D8[];
extern const PcSpriteCmd gUnk_09A41BD0[];
extern const PcSpriteCmd gUnk_09A41DA4[];
extern const PcSpriteCmd gUnk_09A41F78[];
extern const PcSpriteCmd gUnk_09A4214C[];
extern const PcSpriteCmd gUnk_09A42344[];
extern const PcSpriteCmd gUnk_09A4253C[];
extern const PcSpriteCmd gUnk_09A42734[];
extern const PcSpriteCmd gUnk_09A42974[];
extern const PcSpriteCmd gUnk_09A42BD8[];
extern const PcSpriteCmd gUnk_09A42E3C[];
extern const PcSpriteCmd gUnk_09A430A0[];
extern const PcSpriteCmd gUnk_09A432BC[];
extern const PcSpriteCmd gUnk_09A434B4[];
extern const PcSpriteCmd gUnk_09A43718[];
extern const PcSpriteCmd gUnk_09A4397C[];
extern const PcSpriteCmd gUnk_09A43BE0[];
extern const PcSpriteCmd gUnk_09A43D48[];
extern const PcSpriteCmd gUnk_09A43FAC[];
extern const PcSpriteCmd gUnk_09A44210[];
extern const PcSpriteCmd gUnk_09A44474[];
extern const PcSpriteCmd gUnk_09A446D8[];
extern const PcSpriteCmd gUnk_09A4493C[];
extern const PcSpriteCmd gUnk_09A44BA0[];
extern const PcSpriteCmd gUnk_09A44E04[];
extern const PcSpriteCmd gUnk_09A45044[];
extern const PcSpriteCmd gUnk_09A451F4[];
extern const PcSpriteCmd gUnk_09A453C8[];
extern const PcSpriteCmd gUnk_09A455C0[];
extern const PcSpriteCmd gUnk_09A457DC[];
extern const PcSpriteCmd gUnk_09A459B0[];
extern const PcSpriteCmd gUnk_09A45B84[];
extern const PcSpriteCmd gUnk_09A45D34[];
extern const PcSpriteCmd gUnk_09A45F50[];
extern const PcSpriteCmd gUnk_09A46124[];
extern const PcSpriteCmd gUnk_09A462F8[];
extern const PcSpriteCmd gUnk_09A4655C[];
extern const PcSpriteCmd gUnk_09A467C0[];
extern const PcSpriteCmd gUnk_09A46994[];
extern const PcSpriteCmd gUnk_09A46B8C[];
extern const PcSpriteCmd gUnk_09A46DA8[];
extern const PcSpriteCmd gUnk_09A46FC4[];
extern const PcSpriteCmd gUnk_09A47204[];
extern const PcSpriteCmd gUnk_09A47444[];
extern const PcSpriteCmd gUnk_09A47684[];
extern const PcSpriteCmd gUnk_09A478C4[];
extern const PcSpriteCmd gUnk_09A47AE0[];
extern const PcSpriteCmd gUnk_09A47D20[];
extern const PcSpriteCmd gUnk_09A47F84[];
extern const PcSpriteCmd gUnk_09A480EC[];
extern const PcSpriteCmd gUnk_09A48308[];
extern const PcSpriteCmd gUnk_09A48500[];
extern const PcSpriteCmd gUnk_09A48764[];
extern const PcSpriteCmd gUnk_09A489C8[];
extern const PcSpriteCmd gUnk_09A48C2C[];
extern const PcSpriteCmd gUnk_09A48E90[];
extern const PcSpriteCmd gUnk_09A48FF8[];
extern const PcSpriteCmd gUnk_09A49214[];
extern const PcSpriteCmd gUnk_09A4940C[];
extern const PcSpriteCmd gUnk_09A49670[];
extern const PcSpriteCmd gUnk_09A498D4[];
extern const PcSpriteCmd gUnk_09A49B38[];
extern const PcSpriteCmd gUnk_09A49D9C[];
extern const PcSpriteCmd gUnk_09A4A000[];
extern const PcSpriteCmd gUnk_09A4A264[];
extern const PcSpriteCmd gUnk_09A4A4C8[];
extern const PcSpriteCmd gUnk_09A4A708[];
extern const PcSpriteCmd gUnk_09A4A924[];
extern const PcSpriteCmd gUnk_09A4AAD4[];

typedef struct PcGfxSet {
    void* tiles;
    u16 tilesSize;
    u8 unk_06[0x02];
    void* map;
    u16 mapSize;
    u8 unk_0E[0x02];
} PcGfxSet;

extern const PcGfxSet gUnk_09A4AC84[];

typedef struct PcShot {
    s32 unk_00;
    s32 unk_04;
    u16 unk_08;
    u8 unk_0A[0x2];
    s32 unk_0C;
} PcShot;

extern const u16 gUnk_09A4C9EC[];
extern const s16 gUnk_09A4C9F2[];
extern const PcShot gUnk_09A4C9F8[];

extern const s8 gUnk_09A4CA94[];
extern const s8 gUnk_09A4CAB5[];

extern const u16 gUnk_09A4CABE[];
extern const s16 gUnk_09A4CAC4[];

#endif
