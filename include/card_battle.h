#ifndef GUARD_CARD_BATTLE_H
#define GUARD_CARD_BATTLE_H

#include "types.h"
#include "anim.h"
#include "taskpool.h"

struct CardDisplayWork;
struct CardSlot;
struct UnkStruct_08078754;
struct UnkStruct_08080268;

typedef struct UnkStruct_02039DD4 {
    struct CardDisplayWork* unk_000[6];
    struct CardDisplayWork* unk_018[3];
    struct CardDisplayWork* unk_024[3];
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
    AnimState anim;
    AnimState anim2;
    void* gfx;
    void* gfx2;
    TaskPool tasks;
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

extern struct CardDisplayWork* gUnk_02034A98;
extern UnkStruct_02039DD4* gUnk_02039DD4;

void func_080763F0(void);
void func_08076318(void);
void func_08076324(void);
void func_08076330(void);
void func_0807633C(void);
void func_08076348(void);
void func_08076394(void);
u8 func_080763D0(void);
u8 func_0807643C(void);
void func_08076360(void);
void func_08076374(void);
void func_08076300(void);
void func_080762B8(void);
void func_080762C4(void);
void func_080762D0(void);
void func_080762DC(void);
void func_080762E8(void);
void func_080762F4(void);
void func_08076284(void);
void func_08076290(void);
void func_0807629C(void);
void func_0807630C(void);
s32 func_08076F80(struct UnkStruct_08080268* w, u8* task);
struct CardSlot* func_08076674(struct UnkStruct_08078754* w, u8 slot, u16* n);
struct CardSlot* func_08076750(struct UnkStruct_08078754* w, u8 slot, u16* n);
void func_0807682C(struct UnkStruct_08080268* w, u8 slot);

typedef struct CardBattleWork {
    TaskPool tasks;
    void* tiles;
    void* palette;
    u8 unk_1C[0x28];
    void* unk_44[4];
    u8 unk_54[0x50];
    s16 x;
    u8 unk_A6[0x0A];
    s16 unk_B0;
    u8 unk_B2[0x07];
    u8 unk_B9;
    u8 unk_BA;
    u8 unk_BB[0x11];
} CardBattleWork;

typedef struct EventCardLink {
    u8 unk_00[0x3C];
    struct CardSlot* slot;
    u8 unk_40[0x24];
    u8 node[0x14];
} EventCardLink;

typedef struct {
    u32 slot : 8;
    u32 mode : 8;
    u32 unk_02 : 16;
    u8* state;
} EventReloadArgs;

#endif
