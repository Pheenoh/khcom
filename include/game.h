#ifndef GUARD_GAME_H
#define GUARD_GAME_H

#include "obj_api.h"
#include "btl_collision.h"
#include "battle_actor.h"
#include "display.h"
#include "types.h"
#include "battle_work.h"
#include "taskpool.h"
#include "anim.h"
#include "btl_api.h"

struct CardDisplayWork;

typedef struct UnkStruct_02039DD4 {
    struct CardDisplayWork* unk_000[6];
    struct CardDisplayWork* unk_018[6];
    void* tiles;
    void* tiles2;
    void* tiles3;
    void* tiles4;
    void* unk_040;
    void* tiles5;
    void* tiles6;
    void* tiles7;
    void* unk_050;
    void* palette;
    void* palette2;
    u32 unk_05C;
    u32 unk_060;
    AnimState unk_064;
    AnimState unk_07C;
    void* unk_094;
    void* unk_098;
    TaskPool unk_09C;
    u32 unk_0B0;
    u32 unk_0B4;
    u32 unk_0B8;
    u32 unk_0BC;
    u16 unk_0C0;
    u16 unk_0C2;
    u16 unk_0C4;
    u16 unk_0C6;
    u16 unk_0C8;
    u16 unk_0CA;
    u16 unk_0CC;
    u16 unk_0CE;
    u8 unk_0D0;
    u8 unk_0D1;
    u8 unk_0D2;
    u8 unk_0D3;
    u8 unk_0D4;
    u8 unk_0D5;
    u8 unk_0D6;
    u8 unk_0D7;
    u8 unk_0D8;
    u8 unk_0D9;
    u8 unk_0DA[0x02];
    u8 unk_0DC;
    u8 unk_0DD;
    u8 unk_0DE;
    u8 unk_0DF;
    u8 unk_0E0;
    u8 unk_0E1;
    u8 unk_0E2;
    u8 unk_0E3;
    u8 unk_0E4;
    u8 unk_0E5;
    u8 unk_0E6;
    u8 unk_0E7;
    u8 unk_0E8;
    u8 unk_0E9;
    u8 unk_0EA;
    u8 unk_0EB;
    u8 unk_0EC;
    u8 unk_0ED;
    u8 unk_0EE;
    u8 unk_0EF;
    u16 unk_0F0;
    u8 unk_0F2[0x02];
    u32 unk_0F4;
    u32 unk_0F8;
    u16 unk_0FC;
    u16 unk_0FE;
    s16 unk_100;
    s16 unk_102;
    s16 unk_104;
    s16 unk_106;
    u8 unk_108[0x04];
} UnkStruct_02039DD4;

extern UnkStruct_02039DD4* gUnk_02039DD4;

extern u8 gUnk_09EF2AA4[];

extern u8 gUnk_0203C590[];
extern u32 gUnk_09EF69FC[];
extern void* gUrsulaWork;

extern u8 gUnk_08B22BA8[];
extern u8 gUnk_08B22EE4[];
extern u8 gUnk_08B22EFE[];
extern u16 gUnk_0203C3BC;
extern u16 gUnk_0203C3C0;
extern u8 gUnk_08B22BBC[];
extern u8 gUnk_08F69BA4[];

#endif /* GUARD_GAME_H */
