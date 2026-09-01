#include "macros.h"
#include "ms.h"

void task_ms_shop_hosi_0(MsShopHosiWork* work, MsShopHosiArg* arg) {
    work->unk_00 = arg->unk_00 << 8;
    work->unk_04 = arg->unk_02 << 8;
    work->unk_08 = gSineTable[arg->unk_08] * arg->unk_0C >> 8;
    work->unk_0C = -gSineTable[arg->unk_08 + 0x40] * arg->unk_0C >> 8;
    work->unk_10 = 0;
    work->unk_12 = work->unk_14 = GetRandom() % 8 + 4;
    work->unk_18 = arg->unk_04;
    work->unk_1C = LoadObjTiles(gUnk_099A6962, 0x1E0);
}

s32 task_ms_shop_hosi_1(MsShopHosiWork* work) {
    s32 result;

    result = 1;
    work->unk_00 += work->unk_08;
    work->unk_0C += 10;
    work->unk_04 += work->unk_0C;

    if (--work->unk_12 <= 0) {
        work->unk_12 = work->unk_14;
        work->unk_10++;
        if (work->unk_10 > 5) {
            result = 0;
        }
    }

    return result;
}

void task_ms_shop_hosi_2(MsShopHosiWork* work) {
    if (work->unk_12 & 1) {
        DrawSprite(work->unk_00 >> 8, work->unk_04 >> 8, gUnk_09EF9A4C[work->unk_10], work->unk_1C, work->unk_18, 0, 0, 0);
    }
}

void task_ms_shop_hosi_3(MsShopHosiWork* work) {
    ReleaseObjTiles(work->unk_1C);
}

void func_08109620(void) {
    func_081025AC();
}

void func_0810962C(void* a) {
    func_081025D4(a);
}

void func_08109638(void* a) {
    func_08102610(a);
}

ALIGN_ZERO(2);
