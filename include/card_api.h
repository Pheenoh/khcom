#ifndef GUARD_CARD_API_H
#define GUARD_CARD_API_H

#include "types.h"

struct UnkStruct_02039DD4;
struct UnkStruct_08080268;
struct UnkStruct_08098670;
struct UnkStruct_080A1B4C;
struct UnkStruct_080ABA80;

void _08085D04(u8 a);
void func_08078E34(struct UnkStruct_08080268* w, u8 b, u8 c);
u8 func_0807B3C8(void);
u8 func_0807B3E0(void);
void func_0807B668(struct UnkStruct_02039DD4* p);
void func_0807E1A0(void);
void func_0807E1AC(void);
void func_0807E1B8(void);
void func_0807E1C4(void);
void func_0807E1D0(void);
void func_0807E1DC(void);
void func_0807E1E8(void);
void func_0807E1F4(void);
void func_0807E200(void);
void func_0807E20C(void);
void func_0807E218(void);
void func_0807E224(void);
void func_0807E23C(void);
void func_0807E248(void);
u8 func_0807E29C(void);
u8 func_08081828(void);
void func_08083900(u8 a);
void func_08083914(void);
s16 func_08084458(u16 cardId);
u8* func_080857BC(u8 index);
s16 func_080858B8(s32 index);
u16 func_08085B38(u8 index);
void func_08085C3C(void);
void func_08085CB0(void);
void func_08085FB0(void);
s32 func_080938F8(u16 a);
u16 func_08093B38(void);
void func_08093BB4(void);
void func_08093C04(void);
void* func_08093C18(u16 a);
void func_08096DC4(void* a, void* b);
void func_08098670(struct UnkStruct_08098670* p, u16 a);
u8 func_080987C0(u16 n);
void func_080991CC(void* pool, u8* a, void* b, u8* c, u8 d);
void func_0809B644(void* pool, s16 x, s16 y, s16 z, u8 idx);
void func_0809D2B0(u8 a, u8 b, u8 c, u8* s);
void func_0809D458(u16 x, u16 y, u16 color, s32 value);
u8 func_080A1B4C(struct UnkStruct_080A1B4C* p, void* pool);
void func_080A32DC(u8* p);
void func_080A411C(void* pool, u32 a, u16 b);
void func_080A4188(void* pool, u16 b);
void func_080A42B4(void);
u8 func_080A42C8(void);
u8 func_080A42D4(void);
u8 func_080A42E0(void);
s32 func_080ABA80(s32* out);
s32 func_080AC5E8(struct UnkStruct_02039DD4* g, u8 count, u8 kind, struct UnkStruct_080ABA80* arr, u8* flag);
s32 func_080AD144(struct UnkStruct_02039DD4* g, u8 count, u8 kind, struct UnkStruct_080ABA80* arr, u8* flag, void* b);

#endif
