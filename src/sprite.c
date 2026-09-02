#include "macros.h"
#include "intr.h"
#include "gba/syscall.h"
#include "key.h"
#include "malloc.h"
#include "sprite.h"

typedef struct SpriteEntry {
    void* unk_00;
    void* unk_04;
    s32 unk_08;
    void* unk_0C;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    u16 unk_16;
} SpriteEntry;

extern u8 sSpriteHeapName[];

extern u8* gSpriteWork;
extern u16 gDispCnt;

void func_08000BA4(void* pool);
void func_08000BB0(void* node, void* pool, void* owner);
void func_080034EC(u8 a, u8 b);

void func_08001E64(SpriteEntry** arr, s32 lo, s32 hi);
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

u16 func_08001DB0(u16 a, u16 b) {
    switch ((((u32)b << 16) | a) & 0xC000C000) {
    case 0x00000000:
        return 1;
    case 0x80000000:
        return 0x10;
    case 0xC0000000:
        return 0x40;
    case 0x00004000:
    case 0x00008000:
        return 2;
    case 0x40000000:
    case 0x40004000:
    case 0x40008000:
        return 4;
    case 0x80004000:
    case 0x80008000:
        return 8;
    case 0xC0004000:
    case 0xC0008000:
        return 0x20;
    }
    return 0;
}

void func_08001E64(SpriteEntry** arr, s32 lo, s32 hi) {
    SpriteEntry* t;
    u16 pivot;
    s32 i;
    s32 j;

    pivot = arr[(lo + hi) >> 1]->unk_14;
    i = lo;
    j = hi;
    for (;;) {
        while (arr[i]->unk_14 < pivot) {
            i++;
        }
        while (pivot < arr[j]->unk_14) {
            j--;
        }
        if (i >= j) {
            break;
        }
        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
        i++;
        j--;
    }
    if (lo < i - 1) {
        func_08001E64(arr, lo, i - 1);
    }
    if (j + 1 < hi) {
        func_08001E64(arr, j + 1, hi);
    }
}

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

void func_08001F98(void) {
    u8* p;
    s32 i;

    func_08001EF8();
    func_08000BA4(gSpriteWork + 0x1800);
    for (i = 0; i < 128; i++) {
        func_08000BB0(gSpriteWork + i * 0x30 + 0x0C, gSpriteWork + 0x1800, gSpriteWork + i * 0x30);
    }
    func_08000BA4(gSpriteWork + 0x1A94);
    for (i = 0; i < 16; i++) {
        func_08000BB0(gSpriteWork + 0x1814 + i * 0x28 + 0x0C, gSpriteWork + 0x1A94,
                      gSpriteWork + 0x1814 + i * 0x28);
    }
    p = gSpriteWork;
    *(u16*)(p + 0x28A8) = 0;
    *(u16*)(p + 0x2BAC) = 0;
    *(u16*)(p + 0x28AA) = 0;
    func_080034EC(0, 0);
    gSpriteWork[0x2BAE] = 0;
    gSpriteWork[0x2BAF] = 0;
    func_08001F20(0, 0x400);
    func_08001F5C(0, 0x10);
}

INCLUDE_ASM("sprite/func_08002060.s");
