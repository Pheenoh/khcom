#ifndef GUARD_MS_H
#define GUARD_MS_H

#include "obj_api.h"
#include "types.h"
#include "engine.h"

typedef struct MsShopHosiArg {
    s16 x;
    s16 y;
    void* palette;
    u8 unk_08;
    u8 unk_09[0x3];
    s32 unk_0C;
} MsShopHosiArg;

typedef struct MsShopHosiWork {
    s32 x;
    s32 y;
    s32 velX;
    s32 velY;
    s16 unk_10;
    s16 unk_12;
    s16 unk_14;
    u8 unk_16[0x2];
    void* palette;
    void* tiles;
} MsShopHosiWork;

void func_081025AC(void);
void func_081025D4(void* a);
void func_08102610(void* a);

void task_ms_shop_hosi_0(MsShopHosiWork* work, MsShopHosiArg* arg);
s32 task_ms_shop_hosi_1(MsShopHosiWork* work);
void task_ms_shop_hosi_2(MsShopHosiWork* work);
void task_ms_shop_hosi_3(MsShopHosiWork* work);
void func_08109620(void);
void func_0810962C(void* a);
void func_08109638(void* a);

extern s16 gSineTable[];
extern u8 gUnk_099A6962[];
extern void* gUnk_09EF9A4C[];

#endif /* GUARD_MS_H */
