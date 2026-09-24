#include "macros.h"
#include "boss_tm.h"
#include "boss_tm_assets.h"
#include "sprites_boss_tm.h"
#include "card_api.h"
#include "engine_math.h"
#include "system_state.h"
#include "acgtrans.h"
#include <string.h>

extern u8 gUnk_09EF1D58[11];
extern s16 gUnk_09EF1D64[8];
extern s16 gUnk_09EF1D74[10];
extern WlogoTtEffStep gUnk_09EF1D88[3];
extern s16 gUnk_09EF1E08[3];
extern WlogoTtEffStep gUnk_09EF1E14[16];
extern WlogoTtEffStep gUnk_09EF2034[9];
extern s8 gUnk_09EF2194[4];

BtlObj gUnk_0203AB50 EWRAM_COMMON(16);

const EmyKind gUnk_09619C94 = { 34, 1300, 28, 14, 20, 40, 1 };

const char gTaskNameBosTmBody[] = "task_bos_tm_body";

void func_080B8324(TmBodyWork* p) {
    p->tm->unk_36 = 0;
    p->tm->unk_34 = 0;
    p->tm->unk_38 = 0;
}

void func_080B8334(BtlObj* p, s16 a, s16 b, s16 c) {
    p->x = a << 8;
    p->y = b << 8;
    p->z = (c << 8) + 0x1900;
    func_0801B37C(p, &gUnk_09619C94, p->x, p->y, p->z);
    p->unk_09E = 14;
    p->unk_0A0 = 40;
    p->unk_09C = 28;
    p->flags |= 0x400;
    p->flags |= 4;
}

void func_080B83A4(BtlObj* p, s16 a, s16 b, s16 c) {
    p->x = a << 8;
    p->y = b << 8;
    p->z = c << 8;
}

void func_080B83B8(BtlObj* a) {
    func_0801B7D8(a);
}

void func_080B83C4(TmBodyWork* p) {
    p->unk_484++;
    if (p->unk_484 > 5) {
        p->unk_484 = 0;
        p->unk_482++;
        if (p->unk_482 > 10) {
            p->unk_482 = 0;
        }
        p->unk_128 = gUnk_09EF1D58[p->unk_482];
    }
}

void func_080B8418(TmBodyWork* p) {
    if (p->tm->flags & 0x20) {
        p->body.x = p->tm->x2 + 0x400;
        p->body2.x = p->tm->x2;
        p->body3.x = p->tm->x2 + 0xC00;
        p->body4.x = p->tm->x2 - 0x100;
    } else {
        p->body.x = p->tm->x2 - 0x400;
        p->body2.x = p->tm->x2;
        p->body3.x = p->tm->x2 - 0xC00;
        p->body4.x = p->tm->x2 + 0x100;
    }
    p->body.y = p->tm->y2;
    p->body2.y = p->tm->y2;
    p->body3.y = p->tm->y2 + 0x100;
    p->body4.y = p->tm->y2 - 0x400;
    p->body.z = p->tm->z2 - 0x2200;
    p->body2.z = p->tm->z2 + 0x900;
    p->body3.z = p->tm->z2 - 0x2100;
    p->body4.z = p->tm->z2 - 0x1E00;
}

void func_080B8508(TmBodyWork* p) {
    p->unk_128 = 0;
    p->unk_244 = 0;
    p->gfx3 = gUnk_09EF397C[0];
    p->gfx4 = gUnk_09EF3960[0];
    p->tm->x2 = p->tm->unk_08;
    p->tm->y2 = p->tm->unk_0C;
    p->tm->z2 = p->tm->unk_10;
    func_080B8418(p);
}

void func_080B8554(TmBodyWork* p) {
    TmWork* src;
    s32 dz;

    p->unk_128 = 226;
    p->unk_244 = 226;
    p->gfx3 = gUnk_09EF397C[0];
    p->gfx4 = gUnk_09EF3960[0];
    dz = 0xF00;
    src = p->tm;

    if (src->flags & 0x20) {
        p->tm->x2 = p->tm->unk_08 - 0xA00;
        p->tm->y2 = p->tm->unk_0C;
        p->tm->z2 = p->tm->unk_10 + dz;
        p->body.x = p->tm->unk_08 - 0xF00;
        p->body2.x = p->tm->x2 + 0x500;
        p->body3.x = p->tm->x2 + 0x400;
        p->body4.x = p->tm->x2 - 0x900;
    } else {
        p->tm->x2 = p->tm->unk_08 + 0xA00;
        p->tm->y2 = p->tm->unk_0C;
        p->tm->z2 = p->tm->unk_10 + 0xF00;
        p->body.x = p->tm->unk_08 + 0xF00;
        p->body2.x = p->tm->x2 - 0x500;
        p->body3.x = p->tm->x2 - 0x400;
        p->body4.x = p->tm->x2 + 0x900;
    }
    p->body.z = p->tm->z2 - 0x1F00;
    p->body2.z = p->tm->z2 + 0xE00;
    p->body3.z = p->tm->z2 - 0x1F00;
    p->body4.z = p->tm->z2 - 0x1C00;
}

void func_080B8688(TmBodyWork* p) {
    p->unk_128 = 30;
    p->unk_244 = 10;
    p->gfx3 = gUnk_09EF397C[0];
    p->gfx4 = gUnk_09EF3960[0];

    if (p->tm->flags & 0x20) {
        p->tm->x2 = p->tm->unk_08 + 0xA00;
        p->tm->y2 = p->tm->unk_0C;
        p->tm->z2 = p->tm->unk_10 + 0xF00;
        p->body.x = p->tm->unk_08 + 0xB00;
        p->body2.x = p->tm->x2 - 0x500;
        p->body3.x = p->tm->x2 + 0x900;
        p->body4.x = p->tm->x2 - 0x400;
    } else {
        p->tm->x2 = p->tm->unk_08 - 0xA00;
        p->tm->y2 = p->tm->unk_0C;
        p->tm->z2 = p->tm->unk_10 + 0xF00;
        p->body.x = p->tm->unk_08 - 0xB00;
        p->body2.x = p->tm->x2 + 0x500;
        p->body3.x = p->tm->x2 - 0x900;
        p->body4.x = p->tm->x2 + 0x400;
    }
    p->body.z = p->tm->z2 - 0x2200;
    p->body2.z = p->tm->z2 + 0x900;
    p->body3.z = p->tm->z2 - 0x1F00;
    p->body4.z = p->tm->z2 - 0x1C00;
}

void func_080B87C0(TmBodyWork* p, s16 a) {
    if (p->tm->flags & 0x20) {
        p->unk_128 += gUnk_09EF1E14[a].unk_04;
        p->unk_244 += gUnk_09EF1E14[a].unk_0C;
        p->body.x += gUnk_09EF1E14[a].unk_00 << 8;
        p->body2.x += gUnk_09EF1E14[a].unk_08 << 8;
        p->body3.x += gUnk_09EF1E14[a].unk_10 << 8;
        p->body4.x += gUnk_09EF1E14[a].unk_18 << 8;
        p->tm->x2 += gUnk_09EF1E14[a].unk_10 << 8;
    } else {
        p->unk_128 += gUnk_09EF1E14[a].unk_04;
        p->unk_244 += gUnk_09EF1E14[a].unk_0C;
        p->body.x -= gUnk_09EF1E14[a].unk_00 << 8;
        p->body2.x -= gUnk_09EF1E14[a].unk_08 << 8;
        p->body3.x -= gUnk_09EF1E14[a].unk_10 << 8;
        p->body4.x -= gUnk_09EF1E14[a].unk_18 << 8;
        p->tm->x2 -= gUnk_09EF1E14[a].unk_10 << 8;
    }
    p->body.z += gUnk_09EF1E14[a].unk_02 << 8;
    p->body2.z += gUnk_09EF1E14[a].unk_0A << 8;
    p->body3.z += gUnk_09EF1E14[a].unk_12 << 8;
    p->body4.z += gUnk_09EF1E14[a].unk_1A << 8;
    p->tm->z2 += gUnk_09EF1E14[a].unk_0A << 8;
    p->gfx3 = gUnk_09EF397C[gUnk_09EF1E14[a].unk_16];
    p->gfx4 = gUnk_09EF3960[gUnk_09EF1E14[a].unk_1E];
}

void func_080B895C(TmBodyWork* p) {
    p->unk_128 = 0;
    p->unk_244 = 0;
    p->gfx3 = gUnk_09EF397C[0];
    p->gfx4 = gUnk_09EF3960[0];
    p->tm->x2 = p->tm->unk_08;
    p->tm->y2 = p->tm->unk_0C;
    p->tm->z2 = p->tm->unk_10 - 0x1500;
    func_080B8418(p);
}

void func_080B89B0(TmBodyWork* p) {
    if ((s16)p->tm->unk_36 == 0) {
        p->tm->unk_08 += p->tm->unk_20;
        p->tm->unk_0C += p->tm->unk_24;
        p->tm->x2 = p->tm->unk_08;
        p->tm->y2 = p->tm->unk_0C;
        p->tm->z2 += gUnk_09EF1D74[(s16)p->tm->unk_34] << 8;
        func_080B8418(p);
    }
    func_080B83C4(p);
}

void func_080B8A00(TmBodyWork* p) {
    s16 i;
    s16 j;

    if ((s16)p->tm->unk_30 == 1) {
        p->tm->unk_34 = 0;
        p->tm->unk_36 = 0;
        if (p->tm->flags & 0x20) {
            p->unk_128 = gUnk_09EF1D88[(s16)p->tm->unk_34].unk_04;
            p->unk_244 = gUnk_09EF1D88[(s16)p->tm->unk_34].unk_0C;
            p->body.x = p->tm->unk_08 + ((gUnk_09EF1D88[(s16)p->tm->unk_34].unk_00 + 4) << 8);
            p->body2.x = p->tm->unk_08 + (gUnk_09EF1D88[(s16)p->tm->unk_34].unk_08 << 8);
            p->body3.x = p->tm->unk_08 + ((gUnk_09EF1D88[(s16)p->tm->unk_34].unk_10 + 12) << 8);
            p->body4.x = p->tm->unk_08 + ((gUnk_09EF1D88[(s16)p->tm->unk_34].unk_18 - 1) << 8);
            p->tm->x2 = p->tm->unk_08 + (gUnk_09EF1D88[(s16)p->tm->unk_34].unk_10 << 8);
        } else {
            p->unk_128 = gUnk_09EF1D88[(s16)p->tm->unk_34].unk_04;
            p->unk_244 = gUnk_09EF1D88[(s16)p->tm->unk_34].unk_0C;
            p->body.x = p->tm->unk_08 + ((-4 - gUnk_09EF1D88[(s16)p->tm->unk_34].unk_00) << 8);
            p->body2.x = p->tm->unk_08 - (gUnk_09EF1D88[(s16)p->tm->unk_34].unk_08 << 8);
            p->body3.x = p->tm->unk_08 + ((-12 - gUnk_09EF1D88[(s16)p->tm->unk_34].unk_10) << 8);
            p->body4.x = p->tm->unk_08 + ((1 - gUnk_09EF1D88[(s16)p->tm->unk_34].unk_18) << 8);
            p->tm->x2 = p->tm->unk_08 - (gUnk_09EF1D88[(s16)p->tm->unk_34].unk_10 << 8);
        }
        p->body.z = p->tm->unk_10 + ((gUnk_09EF1D88[(s16)p->tm->unk_34].unk_02 - 34 + gUnk_09EF1E08[2]) << 8);
        p->body2.z = p->tm->unk_10 + ((gUnk_09EF1D88[(s16)p->tm->unk_34].unk_0A + 9 + gUnk_09EF1E08[2]) << 8);
        p->body3.z = p->tm->unk_10 + ((gUnk_09EF1D88[(s16)p->tm->unk_34].unk_12 - 33 + gUnk_09EF1E08[2]) << 8);
        p->body4.z = p->tm->unk_10 + ((gUnk_09EF1D88[(s16)p->tm->unk_34].unk_1A - 30 + gUnk_09EF1E08[2]) << 8);
        p->tm->z2 = p->tm->unk_10 + ((gUnk_09EF1D88[(s16)p->tm->unk_34].unk_0A + 0 + gUnk_09EF1E08[2]) << 8);
    } else {
        if ((s16)p->tm->unk_34 < 3) {
            if (p->tm->flags & 0x20) {
                p->unk_128 += gUnk_09EF1D88[(s16)p->tm->unk_34].unk_04;
                p->unk_244 += gUnk_09EF1D88[(s16)p->tm->unk_34].unk_0C;
                p->body.x += gUnk_09EF1D88[(s16)p->tm->unk_34].unk_00 << 8;
                p->body2.x += gUnk_09EF1D88[(s16)p->tm->unk_34].unk_08 << 8;
                p->body3.x += gUnk_09EF1D88[(s16)p->tm->unk_34].unk_10 << 8;
                p->body4.x += gUnk_09EF1D88[(s16)p->tm->unk_34].unk_18 << 8;
                p->tm->x2 += gUnk_09EF1D88[(s16)p->tm->unk_34].unk_10 << 8;
            } else {
                p->unk_128 += gUnk_09EF1D88[(s16)p->tm->unk_34].unk_04;
                p->unk_244 += gUnk_09EF1D88[(s16)p->tm->unk_34].unk_0C;
                p->body.x -= gUnk_09EF1D88[(s16)p->tm->unk_34].unk_00 << 8;
                p->body2.x -= gUnk_09EF1D88[(s16)p->tm->unk_34].unk_08 << 8;
                p->body3.x -= gUnk_09EF1D88[(s16)p->tm->unk_34].unk_10 << 8;
                p->body4.x -= gUnk_09EF1D88[(s16)p->tm->unk_34].unk_18 << 8;
                p->tm->x2 -= gUnk_09EF1D88[(s16)p->tm->unk_34].unk_10 << 8;
            }
            j = 2 - p->tm->unk_34;
            p->body.z += (gUnk_09EF1D88[(s16)p->tm->unk_34].unk_02 + gUnk_09EF1E08[j]) << 8;
            p->body2.z += (gUnk_09EF1D88[(s16)p->tm->unk_34].unk_0A + gUnk_09EF1E08[j]) << 8;
            p->body3.z += (gUnk_09EF1D88[(s16)p->tm->unk_34].unk_12 + gUnk_09EF1E08[j]) << 8;
            p->body4.z += (gUnk_09EF1D88[(s16)p->tm->unk_34].unk_1A + gUnk_09EF1E08[j]) << 8;
            p->tm->z2 += (gUnk_09EF1D88[(s16)p->tm->unk_34].unk_0A + gUnk_09EF1E08[j]) << 8;
        }
        if ((s16)p->tm->unk_32 < 3) {
            i = p->tm->unk_32;
            if (p->tm->flags & 0x20) {
                p->unk_128 -= gUnk_09EF1D88[i].unk_04;
                p->unk_244 -= gUnk_09EF1D88[i].unk_0C;
                p->body.x -= gUnk_09EF1D88[i].unk_00 << 8;
                p->body2.x -= gUnk_09EF1D88[i].unk_08 << 8;
                p->body3.x -= gUnk_09EF1D88[i].unk_10 << 8;
                p->body4.x -= gUnk_09EF1D88[i].unk_18 << 8;
                p->tm->x2 -= gUnk_09EF1D88[i].unk_10 << 8;
            } else {
                p->unk_128 -= gUnk_09EF1D88[i].unk_04;
                p->unk_244 -= gUnk_09EF1D88[i].unk_0C;
                p->body.x += gUnk_09EF1D88[i].unk_00 << 8;
                p->body2.x += gUnk_09EF1D88[i].unk_08 << 8;
                p->body3.x += gUnk_09EF1D88[i].unk_10 << 8;
                p->body4.x += gUnk_09EF1D88[i].unk_18 << 8;
                p->tm->x2 += gUnk_09EF1D88[i].unk_10 << 8;
            }
            j = 2 - i;
            p->body.z -= (gUnk_09EF1D88[i].unk_02 + gUnk_09EF1E08[j]) << 8;
            p->body2.z -= (gUnk_09EF1D88[i].unk_0A + gUnk_09EF1E08[j]) << 8;
            p->body3.z -= (gUnk_09EF1D88[i].unk_12 + gUnk_09EF1E08[j]) << 8;
            p->body4.z -= (gUnk_09EF1D88[i].unk_1A + gUnk_09EF1E08[j]) << 8;
            p->tm->z2 -= (gUnk_09EF1D88[i].unk_0A + gUnk_09EF1E08[j]) << 8;
        }
    }
}

void func_080B8FF4(TmBodyWork* p, s16 a) {
    if (p->tm->flags & 0x20) {
        p->unk_128 += gUnk_09EF2034[a].unk_04;
        p->unk_244 += gUnk_09EF2034[a].unk_0C;
        p->body.x += gUnk_09EF2034[a].unk_00 << 8;
        p->body2.x += gUnk_09EF2034[a].unk_08 << 8;
        p->body3.x += gUnk_09EF2034[a].unk_10 << 8;
        p->body4.x += gUnk_09EF2034[a].unk_18 << 8;
        p->tm->x2 += gUnk_09EF2034[a].unk_10 << 8;
    } else {
        p->unk_128 += gUnk_09EF2034[a].unk_04;
        p->unk_244 += gUnk_09EF2034[a].unk_0C;
        p->body.x -= gUnk_09EF2034[a].unk_00 << 8;
        p->body2.x -= gUnk_09EF2034[a].unk_08 << 8;
        p->body3.x -= gUnk_09EF2034[a].unk_10 << 8;
        p->body4.x -= gUnk_09EF2034[a].unk_18 << 8;
        p->tm->x2 -= gUnk_09EF2034[a].unk_10 << 8;
    }
    p->body.z += gUnk_09EF2034[a].unk_02 << 8;
    p->body2.z += gUnk_09EF2034[a].unk_0A << 8;
    p->body3.z += gUnk_09EF2034[a].unk_12 << 8;
    p->body4.z += gUnk_09EF2034[a].unk_1A << 8;
    p->tm->z2 += gUnk_09EF2034[a].unk_0A << 8;
    p->gfx3 = gUnk_09EF397C[gUnk_09EF2034[a].unk_16];
    p->gfx4 = gUnk_09EF3960[gUnk_09EF2034[a].unk_1E];
}
s32 GetAbsoluteDifference(s32 a, s32 b) {
    if (a > b) {
        return a - b;
    }
    if (a < b) {
        return b - a;
    }
    return 0;
}
void func_080B91A4(TmBodyWork* p) {
    s32 st;
    s32 next;
    u16 rnd;

    if (p->tm->flags & 0x40) {
        p->tm->unk_2C = p->tm->unk_3C;
        return;
    }

    if (p->body2.unk_02C < p->body2.unk_02E / 2) {
        st = p->tm->unk_3A;

        if (st == 2) {
            if (p->tm->flags & 0x10) {
                p->tm->unk_2C = 1;
                p->tm->flags = p->tm->flags & ~0x10;
            } else if (GetAbsoluteDifference(gBtlWork->actor->x, p->tm->unk_08) <= 0x1DFF) {
                rnd = GetRandom() % 100;

                if (rnd > 20) {
                    p->tm->unk_2C = 9;
                } else {
                    p->tm->unk_2C = 1;
                }
            } else {
                p->tm->unk_2C = gUnk_09EF2194[GetRandom() % 4];

                if (p->tm->unk_2C == 3) {
                    p->tm->unk_2C = st;
                }

                if (p->tm->unk_2C == 4) {
                    p->tm->unk_2C = 1;
                }
            }
        } else if (st == 0) {
            if (GetAbsoluteDifference(gBtlWork->actor->x, p->tm->unk_08) <= 0x1DFF) {
                rnd = GetRandom() % 100;

                if (rnd > 30) {
                    p->tm->unk_2C = 9;
                } else {
                    p->tm->unk_2C = 1;
                }
            } else {
                p->tm->unk_2C = gUnk_09EF2194[GetRandom() % 4];

                if (p->tm->unk_2C == 4) {
                    if (p->tm->flags & 0x20) {
                        p->tm->flags |= 0x40;
                        p->tm->unk_2C = 4;
                        p->tm->unk_3C = 4;
                    } else {
                        p->tm->flags |= 0x40;
                        p->tm->unk_2C = 6;
                        p->tm->unk_3C = 6;
                    }
                    next = p->tm->unk_2C;

                    if (next == 3) {
                        rnd = GetRandom() % 100;

                        if (rnd <= 49) {
                            p->tm->unk_2C = 11;
                        } else {
                            p->tm->unk_2C = next;
                        }
                    }
                }
            }
        } else {
            rnd = GetRandom() % 100;

            if (rnd <= 59) {
                p->tm->unk_2C = 9;
            } else {
                p->tm->unk_2C = 10;
            }
        }
        st = p->tm->unk_2C;

        if (st == 1) {
            rnd = GetRandom() % 100;

            if (rnd <= 59) {
                p->tm->unk_2C = st;
            } else {
                p->tm->unk_2C = 10;
            }
        }
    } else {
        st = p->tm->unk_3A;

        if (st == 2) {
            if (p->tm->flags & 0x10) {
                p->tm->unk_2C = 1;
                p->tm->flags = p->tm->flags & ~0x10;
            } else if (GetAbsoluteDifference(gBtlWork->actor->x, p->tm->unk_08) <= 0x1DFF) {
                rnd = GetRandom() % 100;

                if (rnd > 20) {
                    p->tm->unk_2C = 9;
                } else {
                    p->tm->unk_2C = 1;
                }
            } else {
                p->tm->unk_2C = gUnk_09EF2194[GetRandom() % 4];

                if (p->tm->unk_2C == 3) {
                    p->tm->unk_2C = st;
                }

                if (p->tm->unk_2C == 4) {
                    p->tm->unk_2C = 1;
                }
            }
        } else if (st == 0) {
            if (GetAbsoluteDifference(gBtlWork->actor->x, p->tm->unk_08) <= 0x1DFF) {
                rnd = GetRandom() % 100;

                if (rnd > 30) {
                    p->tm->unk_2C = 9;
                } else {
                    p->tm->unk_2C = 1;
                }
            } else {
                p->tm->unk_2C = gUnk_09EF2194[GetRandom() % 4];

                if (p->tm->unk_2C == 4) {
                    if (p->tm->flags & 0x20) {
                        p->tm->flags |= 0x40;
                        p->tm->unk_2C = 4;
                        p->tm->unk_3C = 4;
                    } else {
                        p->tm->flags |= 0x40;
                        p->tm->unk_2C = 6;
                        p->tm->unk_3C = 6;
                    }
                }
            }
        } else {
            p->tm->unk_2C = 9;
        }
    }
}

void _080B949C(BtlObj* a, TmBodyWork* b) {
    u16 t;

    if (a->unk_02C <= 0) {
        return;
    }

    if (b->tm->unk_08 < 0x8E00 || b->tm->unk_08 > 0x16F00) {
        a->flags |= 0x100;
    } else {
        a->flags &= ~0x100;
    }

    switch (func_0801ADAC(a)) {
    case 5:
        func_080B8324(b);
        func_080B9FC4(b);
        func_080B91A4(b);
        b->tm->flags &= ~1;
        break;
    case 4:
        b->tm->unk_38 = 0;
        b->tm->unk_2C = 14;
        break;
    case 1:
    case 6:
    case 7:
        b->unk_48A = a->unk_02C;
        b->tm->flags |= 1;
        b->tm->unk_30++;

        if (b->unk_48C - b->unk_48A >= 9999) {
            b->tm->unk_32 = 55;
            b->tm->unk_2C = 12;
            b->tm->flags &= ~4;
        } else if (b->tm->unk_2C != 12) {
            b->tm->unk_32 = 20;
            b->tm->flags |= 4;
        }
        break;
    case 3:
    case 8:
        func_0801AF4C(a);
        b->tm->unk_34 = 0;
        b->tm->unk_2C = 13;
        break;
    }

    if (b->tm->flags & 1) {
        b->tm->unk_32--;

        if ((s16)b->tm->unk_32 <= 0) {
            b->tm->unk_30 = 0;
            b->tm->flags &= ~1;
            func_0801AF08(a);

            if (b->tm->flags & 4) {
                b->tm->flags &= ~4;
            } else {
                func_080B8324(b);
                t = b->tm->flags & 0x40;

                if (t) {
                    func_080B895C(b);
                    b->tm->unk_2C = 8;
                } else {
                    func_080B8508(b);
                    b->tm->unk_2C = 0;
                }
            }
        }
    }
    b->unk_48C = a->unk_02C;
}

void task_bos_tm_body_0(TmBodyWork* work, TmWork* arg) {
    work->tiles = LoadObjTiles(gUnk_09652E84, 0x1D80);
    work->palette = LoadObjPalette(gUnk_096FB2A4, 0x60);
    work->palette2 = LoadObjPalette(gUnk_08F69BC4, 32);
    work->gfx = gUnk_09EF3950;
    work->gfx2 = gUnk_09EF3958;
    work->gfx3 = gUnk_09EF397C[0];
    work->gfx4 = gUnk_09EF3960[0];
    work->tm = arg;
    work->tm->unk_40 = ((u16*)work->tiles)[3];
    work->tm->unk_42 += ((u16*)work->tiles)[4];
    work->tm->unk_44 = ((u16*)work->palette)[3];
    work->unk_480 = 0;
    work->unk_482 = 0;
    work->unk_484 = 0;
    work->unk_486 = 0;
    work->unk_128 = 0;
    work->unk_244 = 0;
    work->unk_360 = 0;
    work->unk_47C = 0;
    work->unk_488 = 0;
    work->unk_48A = 1300;
    work->unk_48C = 1300;
    work->unk_48E = 0;
    work->unk_490 = 10;
    work->unk_492 = 0;

    if (work->tm->flags & 8) {
        func_080B83A4(&work->body, work->tm->x + 4, work->tm->y,
                      work->tm->z - 34);
        func_080B83A4(&work->body2, work->tm->x, work->tm->y,
                      work->tm->z + 9);
        func_080B83A4(&work->body3, work->tm->x + 12, work->tm->y + 1,
                      work->tm->z - 33);
        func_080B83A4(&work->body4, work->tm->x - 1, work->tm->y - 4,
                      work->tm->z - 30);
    } else {
        func_080B83A4(&work->body, work->tm->x + 4, work->tm->y,
                      work->tm->z - 34);
        func_080B8334(&work->body2, work->tm->x, work->tm->y,
                      work->tm->z - 16);
        func_080B83A4(&work->body3, work->tm->x + 12, work->tm->y + 1,
                      work->tm->z - 33);
        func_080B83A4(&work->body4, work->tm->x - 1, work->tm->y - 4,
                      work->tm->z - 30);
        memcpy(&gUnk_0203AB50, &work->body2, 272);
    }
}
u8 task_bos_tm_body_1(TmBodyWork* work) {
    s16* table;
    u16 n;
    u16 flags;

    if (!(work->tm->flags & 8)) {
        _080B949C(&work->body2, work);
    }
    switch (work->tm->unk_2C) {
    case 0:
    case 15:
        if ((s16)work->tm->unk_38 == 0) {
            func_080B8508(work);
        } else {
            if (gBtlWork->unk_0A0 && (u16)(GetRandom() % 80) == 0) {
                func_0801BCD4(&work->body2);
            }
            if ((s16)work->tm->unk_36 == 0) {
                table = gUnk_09EF1D64;
                work->tm->z2 += table[(s16)work->tm->unk_34] << 8;
                work->body.z = work->tm->z2 - 0x2200;
                work->body2.z = work->tm->z2 + 0x900;
                work->body3.z = work->tm->z2 - 0x2100;
                work->body4.z = work->tm->z2 - 0x1E00;
            }
            func_080B83C4(work);
        }
        break;
    case 4:
        if ((s16)work->tm->unk_38 == 0) {
            func_080B895C(work);
            work->tm->unk_20 = -0x900;
            work->tm->unk_24 = 0;
        } else {
            func_080B89B0(work);
            if (work->tm->unk_08 <= 0x8E00) {
                work->tm->flags &= ~0x20;
                work->body2.flags &= ~4;
                work->tm->unk_2C = 5;
                work->tm->unk_3C = 5;
                func_080B8324(work);
                func_080B895C(work);
                work->tm->unk_20 = 0x900;
                work->tm->unk_24 = 0;
            }
        }
        break;
    case 5:
        if ((s16)work->tm->unk_38 == 0) {
            func_080B895C(work);
            work->tm->unk_20 = 0x900;
            work->tm->unk_24 = 0;
        } else {
            func_080B89B0(work);
            if (work->tm->unk_08 > 0x9FFF) {
                func_0801AF08(&work->body2);
                work->tm->flags &= ~0x40;
                work->tm->unk_2C = 0;
                work->tm->unk_3C = 16;
                func_080B8324(work);
                func_080B8508(work);
            }
        }
        break;
    case 6:
        if ((s16)work->tm->unk_38 == 0) {
            func_080B895C(work);
            work->tm->unk_20 = 0x900;
            work->tm->unk_24 = 0;
        } else {
            func_080B89B0(work);
            if (work->tm->unk_08 > 0x16EFF) {
                work->tm->flags |= 0x20;
                work->body2.flags |= 4;
                work->tm->unk_2C = 7;
                work->tm->unk_3C = 7;
                func_080B8324(work);
                func_080B895C(work);
                work->tm->unk_20 = -0x900;
                work->tm->unk_24 = 0;
            }
        }
        break;
    case 7:
        if ((s16)work->tm->unk_38 == 0) {
            func_080B895C(work);
            work->tm->unk_20 = -0x900;
            work->tm->unk_24 = 0;
        } else {
            func_080B89B0(work);
            if (work->tm->unk_08 <= 0x15D00) {
                func_0801AF08(&work->body2);
                work->tm->flags &= ~0x40;
                work->tm->unk_2C = 0;
                work->tm->unk_3C = 16;
                func_080B8324(work);
                func_080B8508(work);
            }
        }
        break;
    case 1:
    case 10:
        if ((s16)work->tm->unk_38 == 0) {
            func_080B8508(work);
        } else if (work->tm->flags & 2) {
            work->tm->flags &= ~2;
            func_0801AF08(&work->body2);
            work->tm->unk_2C = 0;
            func_080B8324(work);
            work->tm->z2 = (s16)work->tm->z << 8;
        }
        break;
    case 2:
    case 3:
        if ((s16)work->tm->unk_38 == 0) {
            func_080B8508(work);
        } else {
            n = work->tm->unk_34;
            if ((s16)work->tm->unk_34 <= 3) {
                func_080B87C0(work, (s16)work->tm->unk_34);
            } else if (n >= 66 && n <= 74) {
                func_080B87C0(work, n - 62);
            } else if (n >= 98 && n <= 100) {
                func_080B87C0(work, n - 85);
            }
            if (work->tm->flags & 2) {
                work->tm->flags &= ~2;
                func_0801AF08(&work->body2);
                work->tm->unk_2C = 0;
                func_080B8324(work);
                func_080B8508(work);
            }
        }
        break;
    case 11:
        if ((s16)work->tm->unk_38 == 0) {
            func_080B8508(work);
        } else {
            n = work->tm->unk_34;
            if ((s16)work->tm->unk_34 <= 3) {
                func_080B87C0(work, (s16)work->tm->unk_34);
            } else if (n >= 96 && n <= 104) {
                func_080B87C0(work, n - 92);
            } else if (n >= 128 && n <= 130) {
                func_080B87C0(work, n - 115);
            }
            if (work->tm->flags & 2) {
                work->tm->flags &= ~2;
                func_0801AF08(&work->body2);
                work->tm->unk_2C = 0;
                func_080B8324(work);
                func_080B8508(work);
            }
        }
        break;
    case 9:
        if ((s16)work->tm->unk_38 == 0) {
            func_080B8508(work);
        } else {
            n = work->tm->unk_34;
            if ((s16)work->tm->unk_34 <= 2) {
                func_080B8FF4(work, (s16)work->tm->unk_34);
            } else if (n >= 41 && n <= 46) {
                func_080B8FF4(work, n - 38);
            }
            if (work->tm->flags & 2) {
                work->tm->flags &= ~2;
                func_0801AF08(&work->body2);
                work->tm->unk_2C = 0;
                func_080B8324(work);
                func_080B8508(work);
            }
        }
        break;
    case 12:
        func_080B8A00(work);
        break;
    case 14:
        if ((s16)work->tm->unk_38 == 0) {
            func_080B8688(work);
            if (work->tm->flags & 0x40) {
                func_08083900(9);
            }
        } else if ((s16)work->tm->unk_38 > 59) {
            func_080B8324(work);
            work->tm->flags &= ~0x80;
            flags = work->tm->flags & 0x40;
            if (flags) {
                func_0801AF08(&work->body2);
                func_080B8688(work);
                work->tm->unk_2C = 8;
            } else {
                func_0801AF08(&work->body2);
                func_080B8508(work);
                work->tm->unk_2C = 0;
            }
        } else if (!(work->tm->flags & 0x80) && work->tm->unk_3A == 0 && (work->tm->flags & 1)) {
            if ((u16)(GetRandom() % 100) <= 30) {
                _0801C1F8(0, work->tm->unk_08, work->tm->unk_0C, work->tm->unk_10);
                work->tm->flags |= 0x80;
            } else {
                work->tm->flags |= 0x80;
            }
        }
        break;
    case 8:
        func_0801BCD4(&work->body2);
        break;
    case 13:
        if ((s16)work->tm->unk_34 == 0) {
            func_080B8554(work);
        }
        break;
    case 16:
    case 17:
        break;
    }
    return 1;
}
void task_bos_tm_body_2(TmBodyWork* work) {
    BtlObj* s0;
    BtlObj* s1;
    BtlObj* s2;
    BtlObj* s3;
    s32 a1;
    s32 a2;
    u16 mode;
    void* pal;
    s16 x;
    s16 y;

    if (work->tm->flags & 0x20) {
        a1 = AllocObjAffine(work->unk_128, 0x100, 0x100, 1);
        a2 = AllocObjAffine(work->unk_244, 0x100, 0x100, 1);
        mode = 0x800;
    } else {
        a1 = AllocObjAffine(work->unk_128, -0x100, 0x100, 1);
        a2 = AllocObjAffine(work->unk_244, -0x100, 0x100, 1);
        mode = 0x801;
    }

    if (gBtlWork->unk_070 != 0) {
        pal = work->palette;
    } else if (work->tm->flags & 1) {
        if (gFrameCounter & 1) {
            pal = work->palette2;
        } else {
            pal = work->palette;
        }
    } else {
        pal = work->palette;
    }

    s0 = &work->body;
    s1 = &work->body2;
    s2 = &work->body3;
    s3 = &work->body4;
    WorldToScreen(&x, &y, s0->x, s0->y, s0->z);
    DrawSprite(x, y, work->gfx, work->tiles, pal, a1, 0x800,
               (u16)(-4101 - (s0->y >> 8) * 4));
    WorldToScreen(&x, &y, s1->x, s1->y, s1->z - 0x1900);
    DrawSprite(x, y, work->gfx2, work->tiles, pal, a2, 0x800,
               (u16)(-4100 - (s1->y >> 8) * 4));
    WorldToScreen(&x, &y, s2->x, s2->y, s2->z);
    DrawSprite(x, y, work->gfx3, work->tiles, pal, 0, mode,
               (u16)(-4100 - (s2->y >> 8) * 4));
    WorldToScreen(&x, &y, s3->x, s3->y, s3->z);
    DrawSprite(x, y, work->gfx4, work->tiles, pal, 0, mode,
               (u16)(-4100 - (s3->y >> 8) * 4));
}

void task_bos_tm_body_3(TmBodyWork* work) {
    if ((work->tm->flags & 8) == 0) {
        func_080B83B8(&work->body2);
    }

    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ReleaseObjPalette(work->palette2);
}
void func_080B9FC4(TmBodyWork* work) {
    if (work->body2.unk_02C < work->body2.unk_02E / 2) {
        if (GetRandom() % 100 <= 9) {
            func_08083900(1);
        } else if (GetRandom() % 90 <= 19) {
            func_08083900(GetRandom() % 2 + 7);
        } else {
            func_08083900(GetRandom() % 4 + 3);
        }
    } else if (GetRandom() % 100 <= 29) {
        func_08083900(GetRandom() % 3 + 6);
    } else {
        func_08083900(GetRandom() % 6 + 1);
    }
}

u8 gUnk_09EF1D58[11] = { 0, 2, 5, 15, 18, 20, 20, 18, 15, 5, 2 };

s16 gUnk_09EF1D64[8] = { 8, -8, -12, 12, 8, -8, -12, 12 };

s16 gUnk_09EF1D74[10] = { -11, -8, -10, 10, 19, -11, -8, -10, 10, 19 };

WlogoTtEffStep gUnk_09EF1D88[3] = {
    { -8, 0, 246, { 0, 0, 0 }, -3, 2, 246, { 0, 0, 0 }, -6, 2, { 0, 0 }, 0, -6, 2, { 0, 0 }, 0 },
    { -6, 8, 246, { 0, 0, 0 }, -2, 7, 246, { 0, 0, 0 }, -6, 6, { 0, 0 }, 0, -6, 6, { 0, 0 }, 0 },
    { -4, 0, 246, { 0, 0, 0 }, 0, 0, 246, { 0, 0, 0 }, -3, 0, { 0, 0 }, 0, -3, 0, { 0, 0 }, 0 },
};

WlogoTtEffStep gUnk_09EF1DE8 = { 0, 0, 0, { 0, 0, 0 }, 0, 0, 0, { 0, 0, 0 }, 0, 0, { 0, 0 }, 0, 0, 0, { 0, 0 }, 0 };

s16 gUnk_09EF1E08[3] = { 15, 6, 0 };

s16 gUnk_09EF1E0E = -8;

s16 gUnk_09EF1E10 = -20;

s16 gUnk_09EF1E12 = -28;

WlogoTtEffStep gUnk_09EF1E14[16] = {
    { 2, -11, 15, { 0, 0, 0 }, 0, -11, 5, { 0, 0, 0 }, 0, -7, { 0, 0 }, 0, 0, -7, { 0, 0 }, 0 },
    { 7, -12, 15, { 0, 0, 0 }, 5, -12, 5, { 0, 0, 0 }, 4, -8, { 0, 0 }, 1, 4, -8, { 0, 0 }, 1 },
    { 1, -6, 15, { 0, 0, 0 }, -2, -6, 5, { 0, 0, 0 }, 5, -5, { 0, 0 }, 2, 5, -7, { 0, 0 }, 2 },
    { 4, 2, 15, { 0, 0, 0 }, 1, 0, 5, { 0, 0, 0 }, 1, 2, { 0, 0 }, 3, 1, 2, { 0, 0 }, 3 },
    { -4, -2, 241, { 0, 0, 0 }, -1, 0, 251, { 0, 0, 0 }, -6, -2, { 0, 0 }, 2, -6, -2, { 0, 0 }, 2 },
    { -2, 0, 241, { 0, 0, 0 }, -1, -1, 251, { 0, 0, 0 }, 0, -4, { 0, 0 }, 2, 0, -4, { 0, 0 }, 2 },
    { -6, -1, 241, { 0, 0, 0 }, -2, 0, 251, { 0, 0, 0 }, -4, -2, { 0, 0 }, 2, -4, -2, { 0, 0 }, 2 },
    { -2, 1, 241, { 0, 0, 0 }, 0, 2, 251, { 0, 0, 0 }, 0, 2, { 0, 0 }, 1, 0, 2, { 0, 0 }, 1 },
    { -6, 5, 248, { 0, 0, 0 }, 0, 6, 248, { 0, 0, 0 }, -2, 8, { 0, 0 }, 1, -2, 8, { 0, 0 }, 1 },
    { -5, 14, 248, { 0, 0, 0 }, -3, 14, 248, { 0, 0, 0 }, -7, 13, { 0, 0 }, 1, -7, 13, { 0, 0 }, 1 },
    { -4, 12, 248, { 0, 0, 0 }, -1, 11, 248, { 0, 0, 0 }, -2, 11, { 0, 0 }, 0, -2, 11, { 0, 0 }, 0 },
    { -6, 13, 248, { 0, 0, 0 }, -2, 9, 248, { 0, 0, 0 }, -5, 9, { 0, 0 }, 0, -5, 9, { 0, 0 }, 0 },
    { 1, 6, 248, { 0, 0, 0 }, 1, 10, 248, { 0, 0, 0 }, -1, 11, { 0, 0 }, 0, -1, 11, { 0, 0 }, 0 },
    { 0, -2, 8, { 0, 0, 0 }, -1, 0, 10, { 0, 0, 0 }, 1, -1, { 0, 0 }, 0, 1, -1, { 0, 0 }, 0 },
    { 7, -11, 8, { 0, 0, 0 }, 2, -12, 10, { 0, 0, 0 }, 7, -14, { 0, 0 }, 0, 7, -14, { 0, 0 }, 0 },
    { -4, -8, 9, { 0, 0, 0 }, 4, -9, 10, { 0, 0, 0 }, 5, -7, { 0, 0 }, 0, 5, -7, { 0, 0 }, 0 },
};

WlogoTtEffStep gUnk_09EF2014 = { 0, 0, 0, { 0, 0, 0 }, 0, 0, 0, { 0, 0, 0 }, 0, 0, { 0, 0 }, 0, 0, 0, { 0, 0 }, 0 };

WlogoTtEffStep gUnk_09EF2034[9] = {
    { 0, 2, 0, { 0, 0, 0 }, 0, 2, 0, { 0, 0, 0 }, 0, 2, { 0, 0 }, 0, 0, 2, { 0, 0 }, 0 },
    { -8, 6, 246, { 0, 0, 0 }, -3, 7, 246, { 0, 0, 0 }, -6, 7, { 0, 0 }, 0, -6, 7, { 0, 0 }, 0 },
    { -6, 8, 246, { 0, 0, 0 }, -2, 9, 246, { 0, 0, 0 }, -6, 9, { 0, 0 }, 0, -6, 9, { 0, 0 }, 0 },
    { -4, 0, 246, { 0, 0, 0 }, 0, 0, 246, { 0, 0, 0 }, -3, 0, { 0, 0 }, 0, -3, 0, { 0, 0 }, 0 },
    { 2, -2, 8, { 0, 0, 0 }, -1, 0, 10, { 0, 0, 0 }, 1, -1, { 0, 0 }, 0, 1, -1, { 0, 0 }, 0 },
    { 9, -11, 8, { 0, 0, 0 }, 2, -12, 10, { 0, 0, 0 }, 7, -14, { 0, 0 }, 0, 7, -14, { 0, 0 }, 0 },
    { 6, -8, 9, { 0, 0, 0 }, 4, -9, 10, { 0, 0, 0 }, 5, -7, { 0, 0 }, 0, 5, -7, { 0, 0 }, 0 },
    { 2, -11, 15, { 0, 0, 0 }, 0, -11, 5, { 0, 0, 0 }, 0, -7, { 0, 0 }, 1, 0, -7, { 0, 0 }, 1 },
    { 7, -12, 15, { 0, 0, 0 }, 5, -12, 5, { 0, 0, 0 }, 4, -8, { 0, 0 }, 2, 4, -8, { 0, 0 }, 2 },
};

WlogoTtEffStep gUnk_09EF2154 = { 0, 0, 0, { 0, 0, 0 }, 0, 0, 0, { 0, 0, 0 }, 0, 0, { 0, 0 }, 0, 0, 0, { 0, 0 }, 0 };

WlogoTtEffStep gUnk_09EF2174 = { 0, 0, 0, { 0, 0, 0 }, 0, 0, 0, { 0, 0, 0 }, 0, 0, { 0, 0 }, 0, 0, 0, { 0, 0 }, 0 };

s8 gUnk_09EF2194[4] = { 1, 3, 9, 4 };

TaskDesc gTaskDescBosTmBody = {
    gTaskNameBosTmBody,
    (TaskInitFunc)task_bos_tm_body_0,
    (TaskUpdateFunc)task_bos_tm_body_1,
    (TaskFunc)task_bos_tm_body_2,
    (TaskFunc)task_bos_tm_body_3,
    0x494,
};
