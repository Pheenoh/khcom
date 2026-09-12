#ifndef GUARD_BOSS_TM_H
#define GUARD_BOSS_TM_H

#include "types.h"
#include "battle_actor_types.h"

typedef struct TmWork {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u8 unk_06[0x2];
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    u16 unk_28;
    u8 unk_2A[0x2];
    u32 unk_2C;
    s16 unk_30;
    s16 unk_32;
    s16 unk_34;
    s16 unk_36;
    s16 unk_38;
    s8 unk_3A;
    u8 unk_3B;
    s32 unk_3C;
    u16 unk_40;
    u16 unk_42;
    u16 unk_44;
    u8 unk_46[0x2];
    s32 unk_48;
    s32 unk_4C;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5C;
    struct TmWork* unk_60;
} TmWork;

typedef struct TmBodyWork {
    TmWork* unk_000;
    void* tiles;
    void* palette;
    void* palette2;
    BtlObj unk_010;
    u8 unk_120[0x4];
    void* gfx;
    u8 unk_128;
    u8 unk_129[0x3];
    BtlObj unk_12C;
    u8 unk_23C[0x4];
    void* gfx2;
    u8 unk_244;
    u8 unk_245[0x3];
    BtlObj unk_248;
    u8 unk_358[0x4];
    void* gfx3;
    u8 unk_360;
    u8 unk_361[0x3];
    BtlObj unk_364;
    u8 unk_474[0x4];
    void* gfx4;
    u8 unk_47C;
    u8 unk_47D[0x3];
    s16 unk_480;
    s16 unk_482;
    s16 unk_484;
    s16 unk_486;
    u8 unk_488;
    u8 unk_489;
    s16 unk_48A;
    s16 unk_48C;
    s16 unk_48E;
    u8 unk_490;
    u8 unk_491;
    s16 unk_492;
} TmBodyWork;

typedef char TmWork_size[(sizeof(TmWork) == 0x64) ? 1 : -1];
typedef char TmBodyWork_size[(sizeof(TmBodyWork) == 0x494) ? 1 : -1];

extern BtlObj gUnk_0203AB50;

void func_080B8324(TmBodyWork* p);
void func_080B8334(BtlObj* p, s16 a, s16 b, s16 c);
void func_080B83A4(BtlObj* p, s16 a, s16 b, s16 c);
void func_080B83B8(BtlObj* a);
void func_080B83C4(TmBodyWork* p);
void func_080B8418(TmBodyWork* p);
void func_080B8508(TmBodyWork* p);
void func_080B8554(TmBodyWork* p);
void func_080B8688(TmBodyWork* p);
void func_080B87C0(TmBodyWork* p, s16 a);
void func_080B895C(TmBodyWork* p);
void func_080B89B0(TmBodyWork* p);
void func_080B8A00(TmBodyWork* p);
void func_080B8FF4(TmBodyWork* p, s16 a);
void func_080B91A4(TmBodyWork* p);
void _080B949C(BtlObj* a, TmBodyWork* b);
void func_080B9FC4(TmBodyWork* p);

#endif
