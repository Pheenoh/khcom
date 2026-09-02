#include "macros.h"
#include "unk_080fb000.h"

void func_080FB000(GaWork* work, GaEntry* e) {
    s32 d1;
    s32 d2;
    s32 flag;
    s32 v;
    u16 t;

    if (e->unk_15A & 0x10) {
        return;
    }

    switch (func_0801ADAC(e)) {
    case 5:
        work->unk_A52 = 1;
        if (work->unk_000 == 10 || work->unk_004 == 10) {
            func_0801AF08(e);
        } else {
            d1 = gUnk_02039B84->unk_07C[1] - e->unk_124;
            d1 = (d1 * d1) >> 8;
            d2 = gUnk_02039B84->unk_07C[2] - e->unk_128;
            d2 = (d2 * d2) >> 8;
            if (work->entries[2].unk_15A & work->entries[3].unk_15A & work->entries[4].unk_15A & work->entries[5].unk_15A & 4) {
                switch (GetRandom() % 3) {
                case 0:
                    func_080F7F54(work, 7);
                    break;
                case 1:
                    func_080F7F54(work, 8);
                    break;
                case 2:
                    func_080F7F54(work, 9);
                    break;
                }
            } else if (d1 + d2 <= 0xE0FFF) {
                if (GetRandom() % 100 < 70) {
                    if ((work->entries[2].unk_15A & work->entries[3].unk_15A & 4) == 0) {
                        flag = 0;
                        if (gUnk_02039B84->unk_0CC <= gUnk_02039B84->unk_07C[1]) {
                            flag = 1;
                        }

                        if (work->unk_018 == flag) {
                            func_080F7F54(work, 4);
                        } else {
                            func_080F7F54(work, 5);
                        }
                    } else {
                        if (work->unk_A4C == 0) {
                            func_080F7F54(work, 6);
                        } else {
                            func_080F7F54(work, 3);
                        }
                    }
                } else {
                    if ((work->entries[4].unk_15A & work->entries[5].unk_15A & 4) == 0) {
                        if (work->unk_A4C == 0) {
                            func_080F7F54(work, 6);
                        } else {
                            func_080F7F54(work, 3);
                        }
                    } else {
                        flag = 0;
                        if (gUnk_02039B84->unk_0CC <= gUnk_02039B84->unk_07C[1]) {
                            flag = 1;
                        }

                        if (work->unk_018 == flag) {
                            func_080F7F54(work, 4);
                        } else {
                            func_080F7F54(work, 5);
                        }
                    }
                }
            } else if (d1 + d2 <= 0x270FFF) {
                if (GetRandom() % 100 < 50) {
                    if ((work->entries[2].unk_15A & work->entries[3].unk_15A & 4) == 0) {
                        flag = 0;
                        if (gUnk_02039B84->unk_0CC <= gUnk_02039B84->unk_07C[1]) {
                            flag = 1;
                        }

                        if (work->unk_018 == flag) {
                            func_080F7F54(work, 4);
                        } else {
                            func_080F7F54(work, 5);
                        }
                    } else {
                        if (work->unk_A4C == 0) {
                            func_080F7F54(work, 6);
                        } else {
                            func_080F7F54(work, 3);
                        }
                    }
                } else {
                    if ((work->entries[4].unk_15A & work->entries[5].unk_15A & 4) == 0) {
                        if (work->unk_A4C == 0) {
                            func_080F7F54(work, 6);
                        } else {
                            func_080F7F54(work, 3);
                        }
                    } else {
                        flag = 0;
                        if (gUnk_02039B84->unk_0CC <= gUnk_02039B84->unk_07C[1]) {
                            flag = 1;
                        }

                        if (work->unk_018 == flag) {
                            func_080F7F54(work, 4);
                        } else {
                            func_080F7F54(work, 5);
                        }
                    }
                }
            } else {
                if (GetRandom() % 100 < 30) {
                    if ((work->entries[2].unk_15A & work->entries[3].unk_15A & 4) == 0) {
                        flag = 0;
                        if (gUnk_02039B84->unk_0CC <= gUnk_02039B84->unk_07C[1]) {
                            flag = 1;
                        }

                        if (work->unk_018 == flag) {
                            func_080F7F54(work, 4);
                        } else {
                            func_080F7F54(work, 5);
                        }
                    } else {
                        if (work->unk_A4C == 0) {
                            func_080F7F54(work, 6);
                        } else {
                            func_080F7F54(work, 3);
                        }
                    }
                } else {
                    if ((work->entries[4].unk_15A & work->entries[5].unk_15A & 4) == 0) {
                        if (work->unk_A4C == 0) {
                            func_080F7F54(work, 6);
                        } else {
                            func_080F7F54(work, 3);
                        }
                    } else {
                        flag = 0;
                        if (gUnk_02039B84->unk_0CC <= gUnk_02039B84->unk_07C[1]) {
                            flag = 1;
                        }

                        if (work->unk_018 == flag) {
                            func_080F7F54(work, 4);
                        } else {
                            func_080F7F54(work, 5);
                        }
                    }
                }
            }
        }

        if (GetRandom() % 3 != 0) {
            if (work->unk_A4C == 0) {
                work->unk_A4C = 1;
            } else {
                work->unk_A4C = 0;
            }
        }
        break;
    case 1:
    case 6:
    case 7:
        e->unk_15A |= 2;
        e->unk_1A6 = 0;
        if (e->unk_1A0 == 0) {
            work->entries[1].unk_15A |= 2;
            work->entries[1].unk_1A6 = 0;
        }
        break;
    case 3:
    case 8:
        func_0801C2DC(e, 1);
        e->unk_15A |= 4;
        if (e->unk_1A0 == 0) {
            func_0801AF4C(e);
            e->unk_11C = 0;
            e->unk_15C = 0;
            work->entries[1].unk_11C = 0;
            work->entries[1].unk_15C = 0;
            func_080F7F54(work, 11);
        } else {
            e->unk_11C = 3;
            e->unk_15C = 0;
            if (work->unk_000 != 10 && work->unk_004 != 10) {
                if (work->unk_A52 != 0) {
                    func_0801AF08(&work->entries[0]);
                }
                func_080F7F54(work, 1);
            }
        }
        break;
    case 4:
        if (work->unk_000 != 10 && work->unk_004 != 10) {
            if (GetRandom() % 100 < 30) {
                _0801C1F8(0, e->unk_124, e->unk_128, e->unk_12C);
            }
            func_080F7F54(work, 1);
        }
        func_0801AF08(e);
        break;
    }

    switch (e->unk_11C) {
    case 0:
        v = (e->unk_124 - e->unk_004) >> 1;
        if (v > 0x600) {
            v = 0x600;
        } else if (v < -0x600) {
            v = -0x600;
        }
        e->unk_004 += v;
        v = (e->unk_128 - e->unk_008) >> 1;
        if (v > 0x600) {
            v = 0x600;
        } else if (v < -0x600) {
            v = -0x600;
        }
        e->unk_008 += v;
        v = ((e->unk_12C + e->unk_13C) - e->unk_00C) >> 1;
        if (v > 0x600) {
            v = 0x600;
        } else if (v < -0x600) {
            v = -0x600;
        }
        e->unk_00C += v;
        t = e->unk_112;
        ApproachAngle(&t, 0, 3);
        e->unk_112 = t;
        if (e->unk_15A & 1) {
            break;
        }
        e->unk_13C = gSineTable[e->unk_158] << 2;
        e->unk_158 += 4;
        break;
    case 1:
        func_080F7E84(e);
        break;
    case 3:
        if (e->unk_15C == 0) {
            e->unk_15A |= 2;
            e->unk_1A6 = 0;
            if (!func_080128EC()) {
                func_08013DB8(e->unk_004, e->unk_008 + e->unk_00C, 0, 0x100);
                e->unk_15C++;
            }
        } else if (e->unk_15C > 0) {
            if (work->entries[2].unk_15A & work->entries[3].unk_15A & work->entries[4].unk_15A & work->entries[5].unk_15A & 4) {
                func_0801C2DC(&work->entries[0], 0);
            }
            func_0801AF08(e);
            func_080F8374(e);
            return;
        }
        func_080F7E84(e);
        break;
    }

    if (e->unk_15A & 2) {
        e->unk_1A6++;
        if (e->unk_1A6 > 30) {
            func_0801AF08(e);
            e->unk_15A &= 0xFFFD;
            e->unk_1A6 = 0;
        }
    }
    e->unk_19C = AnimUpdate(&e->unk_180);
    if (e->unk_1A0 == 0) {
        work->unk_A2C = AnimUpdate(&work->unk_A10);
    }

    if (e->unk_06C != 0) {
        e->unk_004 += e->unk_078;
        e->unk_008 += e->unk_07C;
    }
    func_08012324(&e->unk_040, e->unk_004, e->unk_008, e->unk_00C + e->unk_13C);
    TaskPoolUpdate(&e->unk_16C);
}
