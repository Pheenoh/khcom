#include "macros.h"
#include "monsgage.h"

void task_monsgage_0(MonsgageWork* work) {
    work->unk_00 = AllocObjTiles(0x200, gUnk_08B255B4);
    work->unk_04 = AllocObjTiles(0x80, gUnk_08B255B4);
    work->palette = LoadObjPalette(gUnk_08F69BA4, 32);
    work->unk_10 = 0;
    work->unk_0C = 0;
    work->unk_14 = gUnk_08B2556C;
    work->unk_18 = gUnk_08B2557C;
    work->unk_1C = 0;
    work->unk_20 = 0;
    work->unk_24 = 1;
}

s32 task_monsgage_1(MonsgageWork* work) {
    if (gBtlWork->unk_0A0 != 0) {
        if (gBtlWork->unk_0A0 == 4) {
            return 0;
        }

        switch (work->unk_20) {
        case 0:
            if (work->unk_1C == 0) {
                work->unk_24 = 1;
                work->unk_18 = gUnk_08B2557C;
            }

            if (work->unk_1C > 120) {
                work->unk_20 = 1;
                work->unk_1C = 0;
            } else {
                work->unk_1C++;
            }
            break;
        case 1:
            if (work->unk_1C == 0) {
                work->unk_18 = gUnk_08B25586;
            }

            if (work->unk_1C % 8 < 4) {
                work->unk_24 = 1;
            } else {
                work->unk_24 = 0;
            }

            if ((work->unk_1C % 4) == 0) {
                work->unk_0C--;
                if (work->unk_0C < 0) {
                    work->unk_0C = 0;
                }
            }

            if (gBtlWork->unk_068 & 0x10000) {
                gBtlWork->unk_068 &= ~0x10000;
                work->unk_1C = 0;
                work->unk_0C += 25;
                if (work->unk_0C <= 255) {
                    work->unk_20 = 0;
                } else {
                    work->unk_0C = 256;
                    work->unk_20 = 2;
                }
            } else {
                work->unk_1C++;
            }
            break;
        case 2:
            if (work->unk_1C == 0) {
                work->unk_18 = gUnk_08B25590;
                work->unk_14 = gUnk_08B2559A;
                gBtlWork->unk_068 |= 0x0100000000000000;
                gBtlWork->unk_068 |= 0x100000;
            }

            if (work->unk_1C % 8 < 4) {
                work->unk_24 = 1;
            } else {
                work->unk_24 = 0;
            }

            if (work->unk_1C > 99 && gBtlWork->unk_0EE == 0) {
                gBtlWork->unk_068 |= 0x200000000;
            }
            work->unk_1C++;
            break;
        }
        work->unk_10 += (work->unk_0C - work->unk_10) >> 2;
    }
    return 1;
}

void task_monsgage_2(MonsgageWork* work) {
    s32 affine;

    if (gBtlWork->unk_0A0 != 0) {
        DrawSprite(172, 12, work->unk_14, work->unk_00, work->palette, 0, 0x410, 3);

        if (work->unk_24 != 0) {
            if (work->unk_10 * 2 > 4) {
                if (work->unk_10 * 2 > 256) {
                    affine = AllocObjAffine(0, work->unk_10 * 2, 256, 1);
                } else {
                    affine = AllocObjAffine(0, work->unk_10 * 2, 256, 0);
                }
                DrawSprite(174, 16, work->unk_18, work->unk_04, work->palette, affine, 0x410, 2);
            }
        }
    }
}

void task_monsgage_3(MonsgageWork* work) {
    ReleaseObjTiles(work->unk_00);
    ReleaseObjTiles(work->unk_04);
    ReleaseObjPalette(work->palette);
}
