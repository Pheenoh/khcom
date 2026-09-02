#include "macros.h"
#include "intr.h"
#include "gba/syscall.h"
#include "key.h"
#include "malloc.h"
#include "main.h"
#include "sprite.h"

extern u8 sEwramHeapName[];
extern u8 sIwramHeapName[];
extern u8 sSpriteHeapName[];

extern u32 gFrameCounter;
extern u32 gUnk_03006C68;
extern u16 gUnk_03006C78;
extern u32 gUnk_03006C10;
extern u32 gUnk_02039828;
extern u32 gUnk_02039820;
extern u16 gUnk_03006C00;
extern u8* gSpriteWork;
extern u16 gDispCnt;

void func_080C55DC(void);
void func_08001100(void);

void func_08001EF8(void);
void func_08001F0C(void);
void func_08001F20(u16 a, u16 b);
void func_08001F5C(u16 a, u16 b);

void SpriteInit(void) {
    u32 zero;

    SetIwramHeapName(sSpriteHeapName);
    gSpriteWork = IwramAlloc(0x2BB0);
    zero = 0;
    CpuSet(&zero, gSpriteWork, 0x05000AEC);
}

void SpriteFree(void) {
    IwramFree(gSpriteWork);
}

INCLUDE_ASM("sprite/func_08001DB0.s");
INCLUDE_ASM("sprite/func_08001E64.s");

void func_08001EF8(void) {
    gDispCnt |= 0x1000;
}

void func_08001F0C(void) {
    gDispCnt &= 0xEFFF;
}

void func_08001F20(u16 a, u16 b) {
    u8* p = gSpriteWork;
    s32 v;

    *(u16*)(p + 0x1810) = a;
    v = a + b;
    *(u16*)(p + 0x1812) = v;
    if ((u16)v > 0x400) {
        *(u16*)(p + 0x1812) = 0x400;
    }
}

void func_08001F5C(u16 a, u16 b) {
    u8* p = gSpriteWork;
    s32 v;

    *(u16*)(p + 0x1AA4) = a;
    v = a + b;
    *(u16*)(p + 0x1AA6) = v;
    if ((u16)v > 0x10) {
        *(u16*)(p + 0x1AA6) = 0x10;
    }
}

INCLUDE_ASM("sprite/func_08001F98.s");
INCLUDE_ASM("sprite/func_08002060.s");
