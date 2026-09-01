#ifndef GUARD_UNK_0806180C_H
#define GUARD_UNK_0806180C_H

#include "types.h"

typedef struct TextSlot {
    void* unk_00;
    u8 unk_04;
    s8 unk_05;
    u8 unk_06;
    u8 unk_07;
} TextSlot;

#define NULL ((void*)0)

typedef struct TextCtx {
    u8 unk_00[0x50];
    s32 unk_50;
    s32 unk_54;
} TextCtx;

extern TextCtx* gUnk_02039DC8;
extern u8 gUnk_090D4180[];
extern u8 gUnk_08F69BE4[];

void func_08065ACC(TextSlot* p, s32 n);
void func_08065AE0(TextSlot* p, s32 n);
s16 func_08065B08(TextSlot* p, u8 n);
s32 func_08065B54(u16* p);
u16 func_08065B6C(u16* a, TextSlot* b);
s32 func_08065B7C(u16* a, TextSlot* b);
void* func_080668F0(void);
void* func_08066904(void);
void func_08066918(void* a, void* b);
void func_08074D00(s32* p);

void* LoadObjTiles(void* a, s32 b);
void* LoadObjPalette(void* a, s32 b);
void ReleaseObjTiles(void* a);
void ReleaseObjPalette(void* a);

#endif /* GUARD_UNK_0806180C_H */
