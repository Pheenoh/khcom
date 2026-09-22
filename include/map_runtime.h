#ifndef GUARD_MAP_RUNTIME_H
#define GUARD_MAP_RUNTIME_H

#include "map_types.h"
#include "text_types.h"

typedef struct UnkStruct_0984C868 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8* unk_04;
    UnkStruct_080DEDD8* unk_08;
} UnkStruct_0984C868;

typedef struct UnkStruct_080DF640 {
    u16 unk_00;
    u16 unk_02;
} UnkStruct_080DF640;

u8 func_080DEBAC(u8 a);
void func_080DEBD8(UnkStruct_080DEDD8* p);
void func_080DEC00(void);
void func_080DEC44(void);
UnkStruct_0984C868* func_080DED64(u8 a);
u8* func_080DED98(u8 a);
UnkStruct_080DEDD8* func_080DEDD8(u8 a);
UnkStruct_080DEE18* func_080DEE18(u8 index);
u8 func_080DEE28(u8 a, u8 b);
u16 func_080DEE44(u8 a, u8 b);
void func_080DEF20(void);
void func_080DF048(void);
void func_080DF244(void);
void func_080DF380(void);
void func_080DF480(void);
u8 func_080DF49C(void);
u8 func_080DF4D8(void);
u8 func_080DF500(void);
u8 func_080DF51C(u8 a);
s32 func_080DF548(u8 a);
void func_080DF570(u8 a);
u8 func_080DF5F4(void);
void func_080DF640(u8 a, UnkStruct_080DF640* p);
void func_080DF6D0(UnkStruct_0203C7AC* p, u8 a);
void func_080DF730(u8 a, u8 b);
u8 func_080DF750(void);
u32 func_080DF804(u8 index);
void func_080DF814(void);
void func_080DF828(void);
void func_080DF8C0(u8 a, u8 b);
void func_080DF964(void);
void func_080DF990(u8 a);
void func_080DF9A8(void);
void func_080DF9C4(void);
void func_080DF9E0(u8 a);
void func_080DFA18(u8 a);
void func_080DFA3C(void);
void func_080DFAA8(void);
void func_080DFAF4(u8 a, u8 b);
void func_080DFB2C(void);
struct UnkStruct_02034F24* func_080DFB7C(u8 a);
MapCell* func_080DFB8C(s32 x, s32 y);
u8 func_080DFBDC(UnkStruct_080DFF1C* p);
u8 func_080DFC24(void);
void func_080DFC7C(void);
u8 func_080DFC94(UnkStruct_080DFF1C* p, s32 x, s32 y);
u8 func_080DFCDC(UnkStruct_080DFF1C* p);
u8 func_080DFD84(UnkStruct_080DFF1C* p);
u8 _080DFE1C(UnkStruct_080DFF1C* p);
s32 func_080DFE7C(s32 x, s32 y, s32 z);

#ifdef VERSION_EU
extern const LocalizedText gMapWorldNameEu_088926FC;
#endif

#endif
