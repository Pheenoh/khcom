#include "registration_data.h"
#include "chara_api.h"
#include "display.h"
#include "pallet.h"
#include "macros.h"
#include "bos2.h"
#include "battle_bounds.h"
#include "boss_map_block_assets.h"
#include "background_actor_assets.h"
#include "mode_battle_data.h"
#include "sprites_bos2.h"
#include "sprites_btl.h"

extern const u16* gUnk_09EF2AA4[46][4];
extern void* gUnk_09EF2D94[37];
extern const u16* gUnk_09EF2E68[4];

s16 gUnk_0203AC80 EWRAM_COMMON(8);
JfMapArg gJfMapArg EWRAM_COMMON(16);
s16 gUnk_0203ACB0 EWRAM_COMMON(4);
s16 gUnk_0203ACB4 EWRAM_COMMON(4);
s16 gUnk_0203ACC0 EWRAM_COMMON(16);
s16 gUnk_0203ACC4 EWRAM_COMMON(4);
s16 gUnk_0203ACC8 EWRAM_COMMON(4);
s16 gUnk_0203ACCC EWRAM_COMMON(4);
s8 gUnk_0203ACD0 EWRAM_COMMON(4);
s16 gUnk_0203ACD4 EWRAM_COMMON(4);
void* gUnk_0203ACD8 EWRAM_COMMON(4);
u32 gUnk_0203ACDC EWRAM_COMMON(4);
u8 gUnk_0203ACE0[0x800] EWRAM_COMMON(16);
s16 gUnk_0203B4E0 EWRAM_COMMON(4);
s16 gUnk_0203B4E4 EWRAM_COMMON(4);
s32 gUnk_0203B4E8 EWRAM_COMMON(4);
u32 gUnk_0203B4EC EWRAM_COMMON(4);
void* gUnk_0203B4F0[4] EWRAM_COMMON(16);
void* gUnk_0203B500 EWRAM_COMMON(4);
u8 gUnk_0203B504[12] EWRAM_COMMON(4);
u8 gUnk_0203B510[0x800] EWRAM_COMMON(16);

void task_bos_jf_0(JfWork* work, s32 a) {
    BtlObj* sub;
    BtlWork* q;
    s32 v1;
    s32 v2;

    gUnk_0203AC80 = 0;
    gUnk_0203ACB0 = 0;
    gUnk_0203ACB4 = 0;
    work->flags = 0;

    if (a != 0) {
        work->flags = 8;
    }

    gUnk_0203ACC4 = 7;
    gUnk_0203ACD4 = 0;
    gUnk_0203ACC0 = 0;
    gJfMapArg.tiles = gUnk_0965DC04;
    gJfMapArg.tilesSize = 0x8000;
    gJfMapArg.palette = gUnk_096FB404;
    gJfMapArg.paletteSize = 128;
    gJfMapArg.maps[0] = gUnk_096C4C64;
    gJfMapArg.maps[1] = gUnk_096C5464;
    gJfMapArg.maps[2] = gUnk_0203ACE0;
    gJfMapArg.maps[3] = gUnk_096C6464;
    TaskPoolInit(&work->tasks, 4);

    if (work->flags & 8) {
        TaskCreate(&work->tasks, &gTaskDescBosJfMap, &gJfMapArg);
    } else {
        TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBosJfMap, &gJfMapArg);
    }

    work->unk_268 = 0;
    work->unk_26A = 0;
    v1 = work->flags & 8;

    if (v1 != 0) {
        work->unk_238 = 10;
        work->unk_23C = 10;
    } else {
        work->unk_238 = 0;
        work->unk_23C = 0;
    }

    work->unk_240 = 0;
    work->unk_242 = 0;
    work->unk_244 = 0;
    work->unk_246 = 0;
    work->unk_248 = 8;
    work->unk_24A = 12;
    work->unk_24E = 0;
    work->unk_250 = 0;
    v2 = work->flags & 8;

    if (v2 != 0) {
        work->unk_22C = 0x2A200;
        work->unk_230 = 0x15E00;
        work->unk_234 = -0x3800;
        func_0801B37C(&work->body, gUnk_0961A668, work->unk_22C, work->unk_230, work->unk_234);
        work->body.flags |= 4;
        TaskCreate(&work->tasks, &gTaskDescBosJfMajin, work);
    } else {
        work->unk_220 = 0x29600;
        work->unk_224 = 0x15400;
        work->unk_228 = -0xB400;
        sub = &work->sub;
        func_0801B37C(sub, gUnk_0961A668, work->unk_220, work->unk_224, work->unk_228);
        sub->flags |= 0x400;
        sub->flags |= 0x200000000000;
        sub->flags &= ~4;
        sub->unk_024 = v2;
        work->sub.unk_0A2 = 4;
        work->unk_22C = 0x2A200;
        work->unk_230 = 0x15E00;
        work->unk_234 = -0x3800;
        func_0801B37C(&work->body, gUnk_0961A668, work->unk_22C, work->unk_230, work->unk_234);
        work->body.flags |= 4;
        work->body.flags |= 0x8000;
        work->body.flags |= 0x100000000;
        work->body.unk_09E = 32;
        work->body.unk_0A0 = 40;
        work->body.unk_09C = 28;
        func_0801BDD4(&work->body, sub);
        gBtlWork->unk_0D8 = 0xFF00;
        func_0801C298(0, 1);
        SetBattleActorPosition(0x23E00, 0x16800, -0x4000);
        func_0801C274(0x20600, 0x16800, -0x800);
        TaskCreate(&work->tasks, &gTaskDescBosJfLamp, work);
        TaskCreate(&work->tasks, &gTaskDescBosJfMajin, work);
        q = gBtlWork;
        q->unk_0CC = sub->x;
        q->unk_0D0 = sub->y;
        q->unk_0D4 = sub->z;
    }
}
u8 task_bos_jf_1(JfWork* work) {
    BtlObj* sub = &work->sub;
    BtlWork* q;
    u16 t;

    if (work->flags & 8) {
        TaskPoolUpdate(&work->tasks);
        return 1;
    }

    switch (func_0801ADAC(sub)) {
    case 5:
        work->unk_238 = work->unk_23C;
        work->unk_244 = 0;
        break;
    case 1:
    case 6:
    case 7:
        work->flags |= 1;
        work->unk_242 = 20;
        break;
    case 3:
    case 8:
        work->unk_238 = 9;
        work->unk_244 = 0;
        break;
    case 4:
        if (gGameState.flags & 8) {
            if (work->unk_250 == 0) {
                if (GetRandom() % 100 <= 19) {
                    _0801C1F8(0, sub->x, sub->y, sub->z);
                }
            }
        }

        work->unk_238 = 7;
        work->unk_244 = 0;
        break;
    }

    if (work->flags & 1) {
        if (--work->unk_242 <= 0) {
            work->unk_240 = 0;
            work->flags &= ~1;
            LoadPaletteWithEffect(gUnk_096FB584, (void*)0x05000000, 32);
            func_0801AF08(sub);

            if (sub->unk_02C > 0) {
                if (work->unk_238 != 1 && work->unk_238 != 6 && work->unk_238 != 7 &&
                    work->unk_238 != 11) {
                    work->unk_238 = 0;
                    work->unk_244 = 0;
                }
            }
        }
    }

    if ((gGameState.flags & 8) == 0) {
        if (sub->unk_024 & 0x20000000) {
            sub->unk_024 &= ~0x20000000;

            if ((work->flags & 1) == 0) {
                if (work->unk_250 == 0) {
                    _0801C1F8(0, sub->x, sub->y, sub->z);
                }
            }
        }
    }

    if (func_0801C1C0(0)) {
        work->unk_244 = 0;
        work->unk_238 = 11;
        work->flags |= 4;

        if (gBtlWork->flags & 0x40) {
            gBtlWork->flags |= 0x400000;
        }
    }

    t = work->unk_250;

    if ((s16)t > 0) {
        work->unk_250 = t - 1;
    }

    TaskPoolUpdate(&work->tasks);
    q = gBtlWork;
    q->unk_0CC = sub->x;
    q->unk_0D0 = sub->y;
    q->unk_0D4 = sub->z;

    if (work->flags & 2) {
        return 0;
    }

    gUnk_0203AC80 = q->actor->x >> 8;
    gUnk_0203ACB0 = q->actor->y >> 8;
    gUnk_0203ACB4 = q->actor->z >> 8;
    return 1;
}

void task_bos_jf_2(JfWork* work) {
    TaskPoolDraw(&work->tasks);
}

void task_bos_jf_3(JfWork* work) {
    if ((work->flags & 8) == 0) {
        func_0801B7D8(&work->sub);
        func_0801B7D8(&work->body);
    }

    TaskPoolDestroy(&work->tasks);
}

u8 func_080BD4A8(s32* p, s32* b, s32* a, s32* out) {
    s32 v1;
    s32 v2;
    s32 v3;
    s32 lo;
    s32 hi;
    s32 x;

    v1 = -((gUnk_0203ACC4 + 1) << 11);
    v2 = -((gUnk_0203ACD4 + 1) << 11);
    v3 = -((gUnk_0203ACC0 + 1) << 11);
    gBtlWork->actor->flags &= ~0x2000000;

    if (gUnk_0203ACC4 > gUnk_0203ACD4) {
        lo = 0x1F600;

        if (gUnk_0203ACD4 > gUnk_0203ACC0) {
            hi = 0x22E00;
            gUnk_0203B4E4 = 0;
            x = *p;

            if (x > hi) {
                *out = v3;
                return 0;
            }

            if (x > lo) {
                if (*a <= v2) {
                    *out = v2;
                    if (x > hi - 0x1000)
                        gBtlWork->actor->flags |= 0x2000000;
                } else {
                    *out = v3;
                    *p = hi;
                    return 1;
                }
            } else {
                if (*a <= v1) {
                    *out = v1;
                    if (x > lo - 0x1000)
                        gBtlWork->actor->flags |= 0x2000000;
                } else {
                    *out = v2;
                    *p = lo;
                    return 1;
                }
            }
        } else if (gUnk_0203ACD4 < gUnk_0203ACC0) {
            hi = 0x21200;
            gUnk_0203B4E4 = 1;
            x = *p;

            if (x <= lo) {
                if (*a <= v1) {
                    *out = v1;
                    if (x > lo - 0x1000)
                        gBtlWork->actor->flags |= 0x2000000;
                } else {
                    *out = v2;
                    *p = lo;
                    return 1;
                }
            } else {
                if (x < hi) {
                    *out = v2;
                    return 0;
                }

                if (*a <= v3) {
                    *out = v3;
                    if (x < hi + 0x1000)
                        gBtlWork->actor->flags |= 0x2000000;
                } else {
                    *out = v2;
                    *p = hi;
                    return 1;
                }
            }
        } else {
            gUnk_0203B4E4 = 2;
            x = *p;

            if (x > lo) {
                *out = v2;
                return 0;
            }

            if (*a <= v1) {
                *out = v1;
                if (x > lo - 0x1000)
                    gBtlWork->actor->flags |= 0x2000000;
            } else {
                *out = v2;
                *p = lo;
                return 1;
            }
        }
    } else if (gUnk_0203ACC4 < gUnk_0203ACD4) {
        lo = 0x1DA00;

        if (gUnk_0203ACD4 > gUnk_0203ACC0) {
            hi = 0x22E00;
            gUnk_0203B4E4 = 3;
            x = *p;

            if (x < lo) {
                *out = v1;
                return 0;
            }

            if (x > hi) {
                *out = v3;
                return 0;
            }

            if (*a <= v2) {
                *out = v2;
                if ((x < lo + 0x1000) || (x > hi - 0x1000))
                    gBtlWork->actor->flags |= 0x2000000;
            } else {
                if (x <= 0x205FF) {
                    *out = v1;
                    *p = lo;
                    return 1;
                }

                *out = v3;
                *p = hi;
                return 1;
            }
        } else if (gUnk_0203ACD4 < gUnk_0203ACC0) {
            hi = 0x21200;
            gUnk_0203B4E4 = 4;
            x = *p;

            if (x < lo) {
                *out = v1;
                return 0;
            }

            if (x < hi) {
                if (*a <= v2) {
                    *out = v2;
                    if (x < lo + 0x1000)
                        gBtlWork->actor->flags |= 0x2000000;
                } else {
                    *out = v1;
                    *p = lo;
                    return 1;
                }
            } else {
                if (*a <= v3) {
                    *out = v3;
                    if (x < hi + 0x1000)
                        gBtlWork->actor->flags |= 0x2000000;
                } else {
                    *out = v2;
                    *p = hi;
                    return 1;
                }
            }
        } else {
            gUnk_0203B4E4 = 5;
            x = *p;

            if (x < lo) {
                *out = v1;
                return 0;
            }

            if (*a <= v2) {
                *out = v2;
                if (x < lo + 0x1000)
                    gBtlWork->actor->flags |= 0x2000000;
            } else {
                *out = v1;
                *p = lo;
                return 1;
            }
        }
    } else {
        if (gUnk_0203ACD4 > gUnk_0203ACC0) {
            hi = 0x22E00;
            gUnk_0203B4E4 = 6;
            x = *p;

            if (x > hi) {
                *out = v3;
                return 0;
            }

            if (*a <= v2) {
                *out = v2;
                if (x > hi - 0x1000)
                    gBtlWork->actor->flags |= 0x2000000;
            } else {
                *out = v3;
                *p = hi;
                return 1;
            }
        } else if (gUnk_0203ACD4 < gUnk_0203ACC0) {
            hi = 0x21200;
            gUnk_0203B4E4 = 7;
            x = *p;

            if (x < hi) {
                *out = v2;
                return 0;
            }

            if (*a <= v3) {
                *out = v3;
                if (x < hi + 0x1000)
                    gBtlWork->actor->flags |= 0x2000000;
            } else {
                *out = v2;
                *p = hi;
                return 1;
            }
        } else {
            gUnk_0203B4E4 = 8;
            v1 = v2;
            *out = v1;
            return 0;
        }
    }

    return 0;
}

u8 func_080BD7F8(s32* p, s32* a, s32 b, s32* out) {
    s32 v1;
    s32 v2;
    s32 v3;

    v1 = -((gUnk_0203ACC4 + 1) << 11);
    v2 = -((gUnk_0203ACD4 + 1) << 11);
    v3 = -((gUnk_0203ACC0 + 1) << 11);

    if (*p <= 0x259FF) {
        if (*p <= 0x221FF) {
            if (*p <= 0x1E9FF) {
                if (*p <= 0x1B1FF) {
                    *out = 0;

                    if (*p > 0x1AE00) {
                        return 0;
                    }
                } else {
                    *out = v1;

                    if (*p <= 0x1B5FF) {
                        return 0;
                    }

                    if (*p > 0x1E600 && v1 != v2) {
                        return 0;
                    }
                }
            } else {
                *out = v2;

                if (*p <= 0x1EDFF && v1 != v2) {
                    return 0;
                }

                if (*p > 0x21E00 && v2 != v3) {
                    return 0;
                }
            }
        } else {
            *out = v3;

            if (*p <= 0x225FF && v2 != v3) {
                return 0;
            }

            if (*p > 0x25600) {
                return 0;
            }
        }
    } else {
        *out = 0;

        if (*p <= 0x25DFF) {
            return 0;
        }
    }

    return 1;
}

void task_bos_jf_map_0(JfMapWork* work, JfMapArg* arg) {
    RequestDma3Copy(gUnk_096C5C64, gUnk_0203ACE0, 0x800);
    gUnk_0203ACD8 = arg->maps;
    func_080BDAAC();
    LoadBgTiles(0, arg->tiles, arg->tilesSize);
    LoadBgPalette(0, arg->palette, arg->paletteSize);
    gBtlWork->unk_024 = 0x100;
    gBtlWork->unk_028 = 0x100;
    gBtlWork->x = 0x23E00;
    gBtlWork->y = 0x12800;
    gBtlWork->unk_000 = 0x23E00;
    gBtlWork->unk_004 = 0x12800;
    gBtlWork->x2 = 0x23E00;
    gBtlWork->y2 = 0x12800;
    gBtlWork->unk_01C = 0x23E00;
    gBtlWork->unk_020 = 0x12800;
    gBtlWork->unk_01A = 0xF;
    gBtlWork->unk_018 = 0;
    func_0802F1C8();
    ScrollBgMapTo(0, gBtlWork->unk_000 >> 8, gBtlWork->unk_004 >> 8);
    work->unk_00 = 0;
    work->unk_02 = 0;
    gUnk_0203ACD0 = 0;
    gUnk_0203B4E0 = 0;
    gUnk_0203ACC8 = 0;
    gUnk_0203ACCC = 0;
    gUnk_0203B4E8 = 0;
}

u8 task_bos_jf_map_1(JfMapWork* work) {
    s32 dx;
    s32 dy;

    work->unk_00++;

    if (work->unk_00 > 14) {
        work->unk_00 = 0;
        work->unk_02++;

        if (work->unk_02 > 7) {
            work->unk_02 = 0;
        }

        LoadPalette(gUnk_096FB484 + work->unk_02 * 32, (void*)0x05000020, 0x20);
    }

    func_0802F208();
    dx = (gBtlWork->x2 - gBtlWork->x) >> 3;
    dy = (gBtlWork->y2 - gBtlWork->y) >> 3;

    if (dx > 0x500) {
        dx = 0x500;
    } else if (dx < -0x500) {
        dx = -0x500;
    }

    gBtlWork->x += dx;
    gBtlWork->y += dy;
    gBtlWork->unk_000 = gBtlWork->x;
    gBtlWork->unk_004 = gBtlWork->y;

    if (gBtlWork->unk_000 < (gBtlWork->unk_0DA + 0x14) << 8) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DA + 0x14) << 8;
    } else if (gBtlWork->unk_000 > (gBtlWork->unk_0DC - 0x1C) << 8) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DC - 0x1C) << 8;
    }

    if (gBtlWork->unk_004 < (gBtlWork->unk_0DE - 0x90) << 8) {
        gBtlWork->unk_004 = (gBtlWork->unk_0DE - 0x90) << 8;
    } else if (gBtlWork->unk_004 > (gBtlWork->unk_0E0 - 0x48) << 8) {
        gBtlWork->unk_004 = (gBtlWork->unk_0E0 - 0x48) << 8;
    }

    gBtlWork->unk_004 += func_0802F268() + func_080BDB58();
    ScrollBgMapTo(0, (gBtlWork->unk_000 >> 8) + 8, (gBtlWork->unk_004 >> 8) + 0x28);

    return 1;
}

void func_080BDAAC(void) {
    func_080C6EB0(gUnk_09EF275C[0][gUnk_0203ACC4], gUnk_0203ACE0 + 0x24c, 7, 0x17);
    func_080C6EB0(gUnk_09EF275C[1][gUnk_0203ACD4], gUnk_0203ACE0 + 0x25a, 7, 0x17);
    func_080C6EB0(gUnk_09EF275C[0][gUnk_0203ACC0], gUnk_0203ACE0 + 0x268, 7, 0x17);
    SetBgMapBlocks(0, gUnk_0203ACD8, 2, 2);
}
void func_080BDB28(s16 a) {
    gUnk_0203ACD0 = 1;
    gUnk_0203B4E0 = 0;
    gUnk_0203ACC8 = 0;
    gUnk_0203ACCC = a;
    gUnk_0203B4E8 = 0;
}

s32 func_080BDB58(void) {
    if (gUnk_0203ACD0 == 1) {
        gUnk_0203ACC8++;

        if (gUnk_0203ACC8 < gUnk_0203ACCC) {
            if (gUnk_0203B4E0 % 4 == 0) {
                gUnk_0203B4E8 = 0x200;
            } else if (gUnk_0203B4E0 % 4 == 2) {
                gUnk_0203B4E8 = -0x200;
            }

            gUnk_0203B4E0++;
        } else {
            gUnk_0203ACD0 = 0;
        }
    }

    return gUnk_0203B4E8;
}

void task_bos_jf_lamp_0(JfLampWork* work, JfWork* arg) {
    JfLampSpeed speed;

    speed.integer = 0;
    speed.fraction = 0x80;
    work->jf = arg;
    work->unk_28 = speed.integer * 256 + speed.fraction;
    work->tiles = LoadObjTiles(gUnk_09682AA4, 0x2800);
    work->gfx = gUnk_09EF3A48[12];
    work->tiles2 = LoadObjTiles(gUnk_09682AA4, 0x2800);
    work->gfx2 = gUnk_09EF3A48[14];
    work->palette = LoadObjPalette(gUnk_096FB5A4, 0x60);
    work->palette2 = LoadObjPalette(gUnk_08F69BC4, 32);
    FadeSetPaletteExcluded(*(u16*)((u8*)work->palette + 6) + 16, 1);
    work->unk_2E = 0;
    work->unk_1C = 0;
    work->unk_1E = 0;
    work->unk_20 = GetRandom() % 0x79 + 0x1E0;
    work->unk_22 = 0;
    work->unk_24 = 1;
    work->unk_2D = 1;
    work->state = 0;
    work->unk_34 = 0;
    work->unk_38 = 0;
    work->angle = 0;
    TaskPoolInit(&work->tasks, 1);
    TaskCreate(&work->tasks, &gTaskDescBtlShadow, &(arg = work->jf)->sub);
}
u8 task_bos_jf_lamp_1(JfLampWork* work) {
    BtlObj* sub = &work->jf->sub;
    JfWork* jf = work->jf;
    u16* p;
    s32 d;

    if (jf->unk_238 <= 3) {
        if (++work->unk_22 > work->unk_20) {
            work->unk_22 = 0;
            m4aSongNumStart(274);
            work->unk_20 = GetRandom() % 121 + 480;
        }
    }

    if (work->jf->unk_238 == 9) {
        work->state = 5;
    }

    switch (work->state) {
    case 0:
        if (work->unk_34 == 0) {
            work->unk_38 = func_080BE278(work);
            d = (s16)((work->unk_38 >> 8) - (sub->x >> 8));

            if (d > 0) {
                sub->flags &= ~4;
            } else if (d < 0) {
                sub->flags |= 4;
            }

            work->unk_2E = 200;
            work->unk_34++;
        } else if (work->unk_2E > 0) {
            ApproachValue(&sub->x, work->unk_38, work->unk_2E);
            work->unk_2E--;
        } else {
            work->unk_34 = 0;
            work->state = 1;
        }

        sub->z = gSineTable[(u8)work->angle] * 20 - 0xB400;
        work->angle += 2;
        break;
    case 1:
        if (work->unk_34 == 0) {
            d = (s16)((gBtlWork->actor->x >> 8) - (sub->x >> 8));

            if (d > 0) {
                sub->flags &= ~4;
            } else if (d < 0) {
                sub->flags |= 4;
            }

            work->unk_34++;
        } else if (work->unk_34 > 60) {
            work->unk_34 = 0;
            work->state = 2;
        } else {
            work->unk_34++;
        }

        sub->z = gSineTable[(u8)work->angle] * 20 - 0xB400;
        work->angle += 2;
        break;
    case 2:
        if (work->unk_34 == 0) {
            if (jf->body.flags & 4) {
                work->unk_38 = 0x27800;
            } else {
                work->unk_38 = 0x19400;
            }

            d = (s16)((work->unk_38 >> 8) - (sub->x >> 8));

            if (d > 0) {
                sub->flags &= ~4;
            } else if (d < 0) {
                sub->flags |= 4;
            }

            work->unk_2E = 200;
            work->unk_34++;
        } else if (work->unk_2E > 0) {
            ApproachValue(&sub->x, work->unk_38, work->unk_2E);
            ApproachValue(&sub->z, -0xB400, work->unk_2E);
            work->unk_2E--;
        } else {
            work->unk_34 = 0;
            work->state = 3;
        }

        sub->z = gSineTable[(u8)work->angle] * 20 - 0xB400;
        work->angle += 2;
        break;
    case 3:
        if (work->unk_34 == 0) {
            d = (s16)((gBtlWork->actor->x >> 8) - (sub->x >> 8));

            if (d > 0) {
                sub->flags &= ~4;
            } else if (d < 0) {
                sub->flags |= 4;
            }

            work->unk_34++;
        } else if (work->unk_34 > 60) {
            work->unk_34 = 0;
            work->state = 0;
        } else {
            work->unk_34++;
        }

        sub->z = gSineTable[(u8)work->angle] * 20 - 0xB400;
        work->angle += 2;
        break;
    case 4:
        if (work->unk_34 == 0) {
            work->unk_2E = 20;
            sub->flags |= 4;
            work->unk_28 = -204;
            work->unk_34++;
        } else {
            if (work->unk_2E > 0) {
                ApproachValue(&sub->z, -0xA000, work->unk_2E);
                work->unk_2E--;
            } else {
                if (sub->x <= 0x19400) {
                    sub->flags &= ~4;
                    work->unk_28 = 204;
                }

                if (sub->x > 0x277FF) {
                    sub->flags |= 4;
                    work->unk_28 = -204;
                }

                sub->x += work->unk_28;
            }

            if (work->jf->unk_250 == 0) {
                work->unk_34 = 0;
                work->state = 2;
            }
        }
        break;
    case 5:
        break;
    }

    if (work->jf->unk_24E == 2) {
        work->unk_34 = 0;
        work->state = 4;
    }

    if (work->unk_1E > 3) {
        work->unk_1E = 0;
        work->unk_1C++;

        if (work->unk_1C > 5) {
            work->unk_1C = 0;
        }

        p = work->tiles2;
        RequestDma3Copy(gUnk_09685DA4 + (work->unk_1C << 9), gUnk_06010000 + (p[3] << 5), 512);
    }

    work->unk_1E++;
    work->unk_2D = func_080BD7F8(&sub->x, &sub->y, (s32)&sub->z, &sub->unk_010);
    ColliderSetPosition(&sub->collider, sub->x, sub->y, sub->z);
    TaskPoolUpdate(&work->tasks);

    return 1;
}

void task_bos_jf_lamp_2(JfLampWork* work) {
    BtlObj* sub = &((BtlObj*)work->jf)[1];
    void* pal;
    u16 mode;
    s16 x;
    s16 y;

    mode = GetBattleSpritePriorityFlags(sub->y);

    if (sub->flags & 4) {
        mode &= 0xFFFE;
    } else {
        mode |= 1;
    }

    if (gBtlWork->unk_070 == 0 && (work->jf->flags & 1) && (gFrameCounter & 1)) {
        pal = work->palette2;
    } else {
        pal = work->palette;
    }

    WorldToScreen(&x, &y, sub->x, sub->y, sub->z);
    DrawSprite(x, y, work->gfx, work->tiles, pal, 0, mode, (u16)(-4100 - (sub->y >> 8) * 4));
    DrawSprite(x, y - 14, work->gfx2, work->tiles2, work->palette, 0, mode,
               (u16)(-4101 - (sub->y >> 8) * 4));

    if (work->unk_2D == 1) {
        TaskPoolDraw(&work->tasks);
    }
}

void task_bos_jf_lamp_3(JfLampWork* work) {
    ReleaseObjTiles(work->tiles2);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ReleaseObjPalette(work->palette2);
    TaskPoolDestroy(&work->tasks);
}

s32 func_080BE278(JfLampWork* work) {
    s16 v;
    s32 r;

    if (work->jf->body.flags & 4) {
        switch (gUnk_0203B4E4) {
        case 5:
        case 6:
            r = 0x27800;
            break;
        case 1:
        case 4:
        case 7:
            r = 0x21800;
            break;
        case 8:
            v = GetRandom() % 3;

            if (v == 0) {
                r = 0x27800;
            } else if (v == 1) {
                r = 0x24600;
            } else {
                r = 0x21800;
            }
            break;
        case 0:
        case 2:
        case 3:
            r = 0x24600;
            break;
        default:
            r = 0;
            break;
        }

        return r;
    }

    switch (gUnk_0203B4E4) {
    case 0:
    case 2:
        r = 0x1F400;
        break;
    case 3:
    case 5:
    case 7:
        r = 0x19400;
        break;
    case 8:
        v = GetRandom() % 3;

        if (v == 0) {
            r = 0x19400;
        } else if (v == 1) {
            r = 0x1CE00;
        } else {
            r = 0x1F400;
        }
        break;
    case 1:
    case 4:
    case 6:
        r = 0x1CE00;
        break;
    default:
        r = 0;
        break;
    }

    return r;
}

void func_080BE380(u8 a, u16 b, JfMajinWork* work) {
    func_080BE3DC(a, work);
    SetBgMapBlocks(1, gUnk_0203B500, 2, 2);
    LoadBgTiles(1, gUnk_09EF28D0[a], b * 32);
    work->jf->flags &= ~0x10;
}
void func_080BE3DC(u8 a, JfMajinWork* work) {
    s16 n;

    if (work->jf->body.z < -0x8000) {
        RequestDma3Copy(gUnk_09EF280C[a], gUnk_0203B510, 0x800);
    } else {
        n = ((work->jf->body.z >> 8) + 0x88) / 8 + work->unk_6A;

        if (n > 0x20) {
            RequestDma3Clear(gUnk_0203B510, 0x800);
        } else {
            RequestDma3Copy(gUnk_09EF280C[a], gUnk_0203B510, (0x20 - n) * 64);
            RequestDma3Clear(gUnk_0203B510 + (0x20 - n) * 64, n * 64);
        }
    }
}
void func_080BE478(u8 a, JfMajinWork* work) {
    s16 n;

    if (work->jf->body.z >= -0x8000) {
        n = ((work->jf->body.z >> 8) + 0x88) / 8 + work->unk_6A;

        if (n > 0x20) {
            RequestDma3Clear(gUnk_0203B510, 0x800);
        } else {
            RequestDma3Copy(gUnk_09EF280C[a], gUnk_0203B510, (0x20 - n) * 64);
            RequestDma3Clear(gUnk_0203B510 + (0x20 - n) * 64, n * 64);
        }

        SetBgMapBlocks(1, gUnk_0203B500, 2, 2);
    }
}

#define GET_ACTOR_POSITION(actor, out_x, out_y, out_z) do { \
    (out_x) = (actor)->x; \
    (out_y) = (actor)->y; \
    (out_z) = (actor)->z; \
} while (0)

void task_bos_jf_majin_0(JfMajinWork* work, void* p) {
    JfWork* arg = p;
    s32 x;
    union {
        s32 coordinate;
        BtlWork* bounds;
    } y;
    s32 z;

    work->jf = arg;
    GET_ACTOR_POSITION(&arg->body, x, y.coordinate, z);
    work->unk_48 = 0;
    work->unk_46 = 0;
    work->unk_44 = 0;
    work->x = x;
    work->y2 = y.coordinate;
    work->z = z;
    work->unk_5C = 0;
    work->unk_5E = gUnk_0203ACC4;
    work->unk_60 = gUnk_0203ACD4;
    work->unk_62 = gUnk_0203ACC0;
    work->unk_64 = gUnk_0203ACC4;
    work->unk_66 = gUnk_0203ACD4;
    work->unk_68 = gUnk_0203ACC0;
    work->unk_49 = 0;
    work->unk_4A = 0;
    work->unk_4C = 0x133;
    work->unk_6A = 0;
    gUnk_0203B4F0[0] = gUnk_08125E24;
    gUnk_0203B4F0[1] = gUnk_08125E24;
    gUnk_0203B4F0[2] = gUnk_08125E24;
    gUnk_0203B4F0[3] = gUnk_0203B510;
    RequestDma3Copy(gUnk_096CAC64, gUnk_0203B510, 0x800);
    gUnk_0203B500 = gUnk_0203B4F0;
    LoadBgPalette(1, gUnk_096FB584, 32);
    LoadBgTiles(1, gUnk_09665C04, 0x2700);
    SetBgMapBlocks(1, gUnk_0203B500, 2, 2);
    work->tiles = LoadObjTiles(gUnk_09682AA4, 0x2800);
    work->palette = LoadObjPalette(gUnk_096FB5A4, 0x60);
    work->palette2 = LoadObjPalette(gUnk_08F69BC4, 32);
    work->unk_2C = 1;
    work->unk_30 = 0x2A200;
    work->unk_34 = 0x12600;
    work->y = 0;
    work->unk_3C = 0;
    x = 0x308;
    AnimInit(&work->anim, gUnk_09EF3B40, gUnk_09EF3A48);
    AnimStart(&work->anim, 1, 1);
    work->gfx = AnimGetGfx(&work->anim);
    y.bounds = gBtlWork;
    ScrollBgMapTo(1, ((y.bounds->unk_000 - arg->body.x) >> 8) + x,
                  ((z = y.bounds->unk_004 - (arg->body.y + arg->body.z)) >> 8) + 0x126);
    TaskPoolInit(&work->tasks, 2);
    TaskCreate(&work->tasks, &gTaskDescBosJfBorderline, work->jf);
}

#undef GET_ACTOR_POSITION

u8 task_bos_jf_majin_1(JfMajinWork* work) {
    JfWork* jf = work->jf;

    jf->flags |= 0x10;

    switch (work->jf->unk_238) {
    case 0:
        func_080BE9A0(work);
        break;
    case 1:
        func_080BEAE8(work);
        break;
    case 2:
        func_080BEDF4(work);
        break;
    case 3:
        func_080BF160(work);
        break;
    case 4:
        func_080BF4F4(work);
        break;
    case 5:
        func_080BF8C4(work);
        break;
    case 8:
        func_080BFDD4(work);
        break;
    case 6:
        func_080C02AC(work);
        break;
    case 7:
        func_080BFDD8(work);
        break;
    case 9:
        func_080BFFF8(work);
        break;
    case 10:
        func_080C0624(work);
        break;
    case 11:
        func_080BFEF0(work);
        break;
    }

    ColliderSetPosition(&jf->body.collider, jf->body.x, jf->body.y, jf->body.z);
    TaskPoolUpdate(&work->tasks);

    if (work->jf->flags & 0x10) {
        if (work->jf->unk_238 != 6) {
            func_080BE478(work->jf->unk_248, work);
        }
    }

    return 1;
}

void task_bos_jf_majin_2(JfMajinWork* work) {
    JfWork* jf = work->jf;
    void* gfx;
    u16 pal;
    s16 x;
    s16 y;

    if (gBtlWork->unk_070 == 0) {
        if (jf->flags & 1) {
            if (gFrameCounter & 1) {
                LoadPaletteWithEffect(gUnk_08F69BC4, (void*)0x05000000, 32);
                gfx = work->palette2;
            } else {
                LoadPaletteWithEffect(gUnk_096FB584, (void*)0x05000000, 32);
                gfx = work->palette;
            }
        } else {
            gfx = work->palette;
        }
    } else {
        LoadPaletteWithEffect(gUnk_096FB584, (void*)0x05000000, 32);
        gfx = work->palette;
    }

    ScrollBgMapTo(1, ((gBtlWork->unk_000 - jf->body.x) >> 8) + 776,
                  ((gBtlWork->unk_004 - (jf->body.y + jf->body.z)) >> 8) + 294);

    if (work->unk_2C == 1) {
        if (jf->body.flags & 4) {
            pal = GetBattleSpritePriorityFlags(jf->body.y);
        } else {
            pal = GetBattleSpritePriorityFlags(jf->body.y);
            pal |= 1;
        }

        WorldToScreen(&x, &y, jf->body.x, jf->body.y, jf->body.z);
        DrawSprite(x, work->y + (y - 61), work->gfx, work->tiles, gfx, 0, pal,
                   (u16)(-4100 - (jf->body.y >> 8) * 4));
    }

    TaskPoolDraw(&work->tasks);
}

void task_bos_jf_majin_3(JfMajinWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ReleaseObjPalette(work->palette2);
    TaskPoolDestroy(&work->tasks);
}
s32 func_080BE910(void) {
    s32 v = gBtlWork->actor->x;

    if (v < 0x1EA00) {
        return 0;
    }

    if (v < 0x22200) {
        return 1;
    }

    return 2;
}

s32 func_080BE940(JfMajinWork* work) {
    s32 v;

    if (work->jf->body.flags & 4) {
        v = gBtlWork->actor->x;

        if (v < 0x1EA00) {
            return 2;
        }

        if (v < 0x22200) {
            return 1;
        }

        return 0;
    }

    v = gBtlWork->actor->x;

    if (v > 0x22200) {
        return 2;
    }

    if (v > 0x1EA00) {
        return 1;
    }

    return 0;
}

void func_080BE9A0(JfMajinWork* work) {
    JfWork* jf = work->jf;

    if (jf->unk_244 == 0) {
        if (jf->body.flags & 4) {
            jf->unk_248 = 8;
            work->unk_5C = 8;
        } else {
            jf->unk_248 = 28;
            work->unk_5C = 28;
        }

        work->jf->unk_24A = 0;
        func_080BE380(work->jf->unk_248, 0x80, work);
        work->unk_3C = 0;
        work->unk_2C = 1;
        work->jf->unk_244++;
    } else {
        if (jf->unk_24A >= gUnk_0961A6A8[jf->unk_248]) {
            jf->unk_24A = 0;
            work->jf->unk_248++;
            work->unk_3C++;

            if (work->jf->unk_248 > work->unk_5C + 5) {
                work->jf->unk_248 = work->unk_5C;
                work->unk_3C = 0;
            }

            func_080BE380(work->jf->unk_248, 0x80, work);
        }

        work->jf->unk_24A++;
        work->gfx = AnimUpdate(&work->anim);
        work->y = gUnk_0961A70A[work->unk_3C];

        if (gBtlWork->unk_0A0 != 0) {
            if (GetRandom() % 80 == 0) {
                func_080C0714(work);
                work->jf->unk_244 = 0;
            }
        }
    }
}

void func_080BEAE8(JfMajinWork* work) {
    JfWork* jf = work->jf;

    if (jf->unk_244 == 0) {
        if (jf->body.flags & 4) {
            jf->unk_248 = 0;
        } else {
            jf->unk_248 = 7;
        }

        work->jf->unk_24A = 0;
        func_080BE380(work->jf->unk_248, 0xA0, work);
        work->unk_48 = 0;
        work->unk_46 = 0;
        work->unk_2C = 0;
        work->jf->unk_244++;
    } else {
        switch (work->unk_48) {
        case 0:
            if (jf->unk_24A >= gUnk_0961A6A8[jf->unk_248]) {
                jf->unk_24A = 0;

                if (jf->body.flags & 4) {
                    work->jf->unk_248++;

                    if (work->jf->unk_248 > 7) {
                        work->jf->unk_248 = 0;
                    }
                } else {
                    work->jf->unk_248--;

                    if (work->jf->unk_248 < 0) {
                        work->jf->unk_248 = 7;
                    }
                }

                func_080BE380(work->jf->unk_248, 0xA0, work);
            }

            work->jf->unk_24A++;
            jf->body.z += 0x400;
            work->unk_46++;

            if (work->unk_46 > 40) {
                work->unk_46 = 0;
                work->unk_48++;
            }

            if (work->unk_46 == 21) {
                jf->body.flags |= 0x1000000;
            }
            break;
        case 1:
            work->unk_46++;

            if (work->unk_46 > 60) {
                work->unk_46 = 0;
                work->jf->unk_24A = 0;

                if (jf->body.flags & 4) {
                    jf->body.flags &= ~4;
                    jf->body.x = 0x16A00;
                    work->jf->unk_248 = 3;
                } else {
                    jf->body.flags |= 4;
                    jf->body.x = 0x2A200;
                    work->jf->unk_248 = 3;
                }

                func_080BE380(work->jf->unk_248, 0xA0, work);
                m4aSongNumStart(0x277);
                work->unk_48++;
            }
            break;
        case 2:
            if (jf->unk_24A >= gUnk_0961A6A8[jf->unk_248]) {
                jf->unk_24A = 0;

                if (jf->body.flags & 4) {
                    work->jf->unk_248++;

                    if (work->jf->unk_248 > 7) {
                        work->jf->unk_248 = 0;
                    }
                } else {
                    work->jf->unk_248--;

                    if (work->jf->unk_248 < 0) {
                        work->jf->unk_248 = 7;
                    }
                }

                func_080BE380(work->jf->unk_248, 0xA0, work);
            }

            work->jf->unk_24A++;
            jf->body.z -= 0x400;
            work->unk_46++;

            if (work->unk_46 > 40) {
                work->unk_46 = 0;
                work->unk_48++;
            }

            if (work->unk_46 == 22) {
                jf->body.flags &= ~0x1000000;
            }
            break;
        default:
            work->jf->unk_244 = 0;
            work->jf->unk_238 = 0;
            break;
        }
    }
}
void func_080BEDF4(JfMajinWork* work) {
    JfWork* jf = work->jf;
    BtlObj* q = &jf->sub;

    if (jf->unk_244 == 0) {
        if (jf->body.flags & 4) {
            jf->unk_248 = 0;
            work->unk_5C = 14;
        } else {
            jf->unk_248 = 7;
            work->unk_5C = 34;
        }

        work->jf->unk_24A = 0;
        func_080BE380(work->jf->unk_248, 0xA0, work);
        work->unk_48 = 0;
        work->unk_46 = 0;
        work->unk_2C = 0;
        work->jf->unk_244++;
    } else {
        switch (work->unk_48) {
        case 0:
            if (work->jf->unk_24A >= gUnk_0961A6A8[work->jf->unk_248]) {
                work->jf->unk_24A = 0;

                if (jf->body.flags & 4) {
                    work->jf->unk_248++;

                    if (work->jf->unk_248 > 7) {
                        work->jf->unk_248 = 0;
                    }
                } else {
                    work->jf->unk_248--;

                    if (work->jf->unk_248 < 0) {
                        work->jf->unk_248 = 7;
                    }
                }

                func_080BE380(work->jf->unk_248, 0xA0, work);
            }

            work->jf->unk_24A++;
            jf->body.z += 0x400;
            work->unk_46++;

            if (work->unk_46 > 60) {
                work->unk_46 = 0;
                work->unk_48++;
            }

            if (work->unk_46 == 23) {
                jf->body.flags |= 0x1000000;
            }
            break;
        case 1:
            if (jf->body.flags & 4) {
                work->jf->unk_248 = 14;
                work->z = -0x2000 - ((gUnk_0203ACC0 + 1) << 11);
            } else {
                work->jf->unk_248 = 34;
                work->z = -0x2000 - ((gUnk_0203ACC4 + 1) << 11);
            }

            work->jf->unk_24A = 0;
            work->task = TaskCreate(&work->tasks, &gTaskDescBosJfRock, work->jf);
            func_080BE380(work->jf->unk_248, 0xA0, work);
            work->unk_44 = 120;
            work->unk_48++;
            break;
        case 2:
            if (work->unk_44 > 0) {
                ApproachValue(&jf->body.z, work->z, work->unk_44);
                work->unk_44--;

                if (work->unk_44 == 30) {
                    jf->body.flags &= ~0x1000000;
                }
            } else {
                work->unk_48++;
            }
            break;
        case 3:
            if (work->jf->unk_24A >= gUnk_0961A6A8[work->jf->unk_248]) {
                work->jf->unk_24A = 0;
                work->jf->unk_248++;

                if (work->jf->unk_248 > work->unk_5C + 4) {
                    if (jf->body.flags & 4) {
                        work->jf->unk_248 = 8;
                    } else {
                        work->jf->unk_248 = 28;
                    }

                    work->unk_2C = 1;
                    work->unk_48++;
                }

                func_080BE380(work->jf->unk_248, 0xA0, work);
            }

            work->jf->unk_24A++;
            break;
        case 4:
            if (IsTaskActive(work->task) == 0) {
                work->z = -0x3800;
                work->unk_44 = 10;
                work->unk_48++;
            }
            break;
        case 5:
            if (work->unk_44 > 0) {
                ApproachValue(&jf->body.z, work->z, work->unk_44);
                work->unk_44--;
            } else {
                work->unk_48++;
            }
            break;
        default:
            func_0801AF08(q);
            work->jf->unk_244 = 0;
            work->jf->unk_238 = 6;
            break;
        }
    }
}
void func_080BF160(JfMajinWork* work) {
    JfWork* jf = work->jf;
    BtlObj* q = &jf->sub;

    if (jf->unk_244 == 0) {
        if (jf->body.flags & 4) {
            jf->unk_248 = 19;
            work->jf->unk_24A = 0;
            work->unk_5C = 19;
            work->x = 0x27A00;
            work->z = -0x5200 - ((gUnk_0203ACC0 + 1) << 11);
        } else {
            jf->unk_248 = 39;
            work->jf->unk_24A = 0;
            work->unk_5C = 39;
            work->x = 0x19200;
            work->z = -0x5200 - ((gUnk_0203ACC4 + 1) << 11);
        }

        func_080BE380(work->jf->unk_248, 0xA0, work);
        work->unk_48 = 0;
        work->unk_46 = 0;
        work->unk_44 = 40;
        work->unk_2C = 0;
        work->jf->unk_244++;
    } else {
        switch (work->unk_48) {
        case 0:
            if (work->unk_44 > 0) {
                ApproachValue(&jf->body.x, work->x, work->unk_44);
                ApproachValue(&jf->body.z, work->z, work->unk_44);
                work->unk_44--;

                if (work->jf->unk_24A >= gUnk_0961A6A8[work->jf->unk_248]) {
                    work->jf->unk_24A = 0;
                    work->jf->unk_248++;

                    if (work->jf->unk_248 >= work->unk_5C + 1) {
                        work->jf->unk_248 = work->unk_5C + 1;
                    }

                    func_080BE380(work->jf->unk_248, 0xA0, work);
                }

                work->jf->unk_24A++;
            } else {
                work->unk_48++;
            }
            break;
        case 1:
            work->unk_46++;

            if (work->unk_46 > 20) {
                work->unk_46 = 0;
                work->unk_6A = 1;
                work->unk_48++;
            }
            break;
        case 2:
            jf->body.z += 0xA00;

            if (work->jf->unk_24A >= gUnk_0961A6A8[work->jf->unk_248]) {
                work->jf->unk_24A = 0;
                work->jf->unk_248++;

                if (work->jf->unk_248 == work->unk_5C + 4) {
                    work->unk_6A = 0;
                    work->unk_48++;
                }

                func_080BE380(work->jf->unk_248, 0xA0, work);
            }

            work->jf->unk_24A++;
            break;
        case 3:
            if (jf->body.flags & 4) {
                func_080147D8(jf->body.x - 0x3000, jf->body.y + jf->body.z + 0x1800);
                func_08011F78(0xE8, jf->body.x - 0x3000, jf->body.y, jf->body.z + 0x1800, 30, 30, 30);
            } else {
                func_080147D8(jf->body.x + 0x3000, jf->body.y + jf->body.z + 0x1800);
                func_08011F78(0xE8, jf->body.x + 0x3000, jf->body.y, jf->body.z + 0x1800, 30, 30, 30);
            }

            func_0802F1E8();
            m4aSongNumStart(0x210);
            work->unk_46 = 0;
            work->unk_48++;
            break;
        case 4:
            if (work->unk_46 == 10) {
                work->jf->unk_248 = work->unk_5C + 5;
                func_080BE380(work->jf->unk_248, 0xA0, work);
            }

            if (work->unk_46 > 20) {
                work->unk_46 = 0;

                if (jf->body.flags & 4) {
                    work->x = 0x2A200;
                } else {
                    work->x = 0x16A00;
                }

                work->z = -0x3800;
                work->unk_44 = 10;
                work->unk_48++;
            }

            work->unk_46++;
            break;
        case 5:
            if (work->unk_44 > 0) {
                ApproachValue(&jf->body.x, work->x, work->unk_44);
                ApproachValue(&jf->body.z, work->z, work->unk_44);
                work->unk_44--;
            } else {
                work->unk_48++;
            }
            break;
        default:
            func_0801AF08(q);
            work->jf->unk_244 = 0;
            work->jf->unk_238 = 6;
            break;
        }
    }
}
void func_080BF4F4(JfMajinWork* work) {
    JfWork* jf = work->jf;
    BtlObj* q = &jf->sub;

    if (jf->unk_244 == 0) {
        if (jf->body.flags & 4) {
            jf->unk_248 = 25;
            work->jf->unk_24A = 0;
            work->unk_5C = 25;
            work->x = 0x2A200;
            work->z = -0x2400 - ((gUnk_0203ACC0 + 1) << 11);
        } else {
            jf->unk_248 = 45;
            work->jf->unk_24A = 0;
            work->unk_5C = 45;
            work->x = 0x16A00;
            work->z = -0x2400 - ((gUnk_0203ACC4 + 1) << 11);
        }

        func_080BE380(work->jf->unk_248, 0x80, work);
        work->unk_48 = 0;
        work->unk_46 = 0;
        work->unk_44 = 40;
        work->unk_2C = 0;
        work->jf->unk_244++;
    } else {
        switch (work->unk_48) {
        case 0:
            if (work->unk_44 > 0) {
                ApproachValue(&jf->body.z, work->z, work->unk_44);
                work->unk_44--;
            } else {
                work->unk_48++;
            }
            break;
        case 1:
            if (jf->body.flags & 4) {
                jf->body.x += 0x100;
            } else {
                jf->body.x -= 0x100;
            }

            work->unk_46++;

            if (work->unk_46 > 20) {
                work->unk_46 = 0;
                work->jf->unk_248 = work->unk_5C + 1;
                func_080BE380(work->jf->unk_248, 0x80, work);
                work->unk_44 = 2;
                work->unk_48++;
            }
            break;
        case 2:
            if (work->unk_44 > 0) {
                ApproachValue(&jf->body.x, work->x, work->unk_44);
                work->unk_44--;
            } else {
                work->unk_48++;
                work->unk_44 = 0;
            }
            break;
        case 3:
            if (jf->body.flags & 4) {
                func_08016C40(jf->body.x - 0x1A00, jf->body.y, jf->body.z - 0x3100, 0x133, 160, 45);
            } else {
                func_08016C40(jf->body.x + 0x1A00, jf->body.y, jf->body.z - 0x3100, 0x133, 96, 45);
            }

            m4aSongNumStart(0x27A);
            jf->body.x = (work->x - 0x100) + (work->unk_44++ % 2) * 0x200;
            work->unk_46 = 0;
            work->unk_48++;
            break;
        case 4:
            jf->body.x = (work->x - 0x100) + (work->unk_44++ % 2) * 0x200;

            if (jf->body.flags & 4) {
                BgFxSetPosition(jf->body.x - 0x1A00, jf->body.y, jf->body.z - 0x3100);
            } else {
                BgFxSetPosition(jf->body.x + 0x1A00, jf->body.y, jf->body.z - 0x3100);
            }

            if (work->unk_46 > 10 && work->unk_46 % 10 == 9) {
                if (jf->body.flags & 4) {
                    func_08011F78(0xE9, jf->body.x - 0x6400, jf->body.y + 0xA00, jf->body.z + 0x2000, 20, 20, 20);
                } else {
                    func_08011F78(0xE9, jf->body.x + 0x6400, jf->body.y + 0xA00, jf->body.z + 0x2000, 20, 20, 20);
                }
            }

            if (work->unk_46 > 80) {
                work->unk_46 = 0;
                work->z = -0x3800;
                work->unk_44 = 10;
                work->jf->unk_248 = work->unk_5C + 2;
                func_080BE380(work->jf->unk_248, 0x80, work);
                work->unk_48++;
            }

            work->unk_46++;
            break;
        case 5:
            if (work->unk_44 > 0) {
                ApproachValue(&jf->body.x, work->x, work->unk_44);
                ApproachValue(&jf->body.z, work->z, work->unk_44);
                work->unk_44--;
            } else {
                work->unk_48++;
            }
            break;
        default:
            func_0801AF08(q);
            work->jf->unk_244 = 0;
            work->jf->unk_238 = 6;
            break;
        }
    }
}
void func_080BF8C4(JfMajinWork* work) {
    JfWork* jf = work->jf;
    BtlObj* q = &jf->sub;

    if (jf->unk_244 == 0) {
        if (jf->body.flags & 4) {
            jf->unk_248 = 25;
            work->jf->unk_24A = 0;
            work->unk_5C = 25;
            work->x = 0x2A200;
            work->y2 = gBtlWork->actor->y - 0x1400;
            work->z = -0x2400 - ((gUnk_0203ACC0 + 1) << 11);
        } else {
            jf->unk_248 = 45;
            work->jf->unk_24A = 0;
            work->unk_5C = 45;
            work->x = 0x16A00;
            work->y2 = gBtlWork->actor->y - 0x1400;
            work->z = -0x2400 - ((gUnk_0203ACC4 + 1) << 11);
        }

        func_080BE380(work->jf->unk_248, 0x80, work);
        work->unk_48 = 0;
        work->unk_46 = 0;
        work->unk_44 = 40;
        work->unk_2C = 0;
        work->jf->unk_244++;
    } else {
        switch (work->unk_48) {
        case 0:
            func_0802F274(jf->body.x, jf->body.y + jf->body.z);

            if (work->unk_44 > 0) {
                ApproachValue(&jf->body.y, work->y2, work->unk_44);
                ApproachValue(&jf->body.z, work->z, work->unk_44);
                work->unk_44--;
            } else {
                work->unk_48++;
            }
            break;
        case 1:
            if (jf->body.flags & 4) {
                jf->body.x += 0x100;
            } else {
                jf->body.x -= 0x100;
            }

            work->unk_46++;

            if (work->unk_46 > 20) {
                work->unk_46 = 0;
                work->jf->unk_248 = work->unk_5C + 1;
                func_080BE380(work->jf->unk_248, 0x80, work);
                work->unk_44 = 2;
                work->unk_48++;
            }
            break;
        case 2:
            if (work->unk_44 > 0) {
                ApproachValue(&jf->body.x, work->x, work->unk_44);
                work->unk_44--;
            } else {
                work->unk_48++;
                work->unk_44 = 0;
            }
            break;
        case 3:
            if (jf->body.flags & 4) {
                work->unk_49 = 148;
                work->unk_4C = 0x100;
                func_08016C40(jf->body.x - 0x1A00, jf->body.y, jf->body.z - 0x3100, 0x100, work->unk_49, 45);
                func_080147C8(0x133, 0x100);
            } else {
                work->unk_49 = 108;
                work->unk_4C = 0x133;
                func_08016C40(jf->body.x + 0x1A00, jf->body.y, jf->body.z - 0x3100, 0x100, work->unk_49, 45);
                func_080147C8(0x133, 0x100);
            }

            m4aSongNumStart(0x27A);
            jf->body.x = (work->x - 0x100) + (work->unk_44++ % 2) * 0x200;
            work->unk_46 = 0;
            work->unk_4A = 0;
            work->unk_48++;
            break;
        case 4:
            work->unk_44++;

            if (jf->body.flags & 4) {
                jf->body.x = (work->x - 0x100) + (work->unk_44 % 2) * 0x200;
                BgFxSetPosition(jf->body.x - 0x1A00, jf->body.y, jf->body.z - 0x3100);

                if (work->unk_49 <= 173 && work->unk_44 % 2 == 0) {
                    work->unk_49++;
                    func_080147B8(work->unk_49);
                    work->unk_4A++;
                    work->unk_4C = gUnk_09EF2994[work->unk_4A];
                    func_080147C8(0x133, work->unk_4C);
                }
            } else {
                jf->body.x = (work->x - 0x100) + (work->unk_44 % 2) * 0x200;
                BgFxSetPosition(jf->body.x + 0x1A00, jf->body.y, jf->body.z - 0x3100);

                if (work->unk_49 > 82 && work->unk_44 % 2 == 0) {
                    work->unk_49--;
                    func_080147B8(work->unk_49);
                    work->unk_4A++;
                    work->unk_4C = gUnk_09EF2994[work->unk_4A];
                    func_080147C8(0x133, work->unk_4C);
                }
            }

            if (work->unk_46 >= 11 && work->unk_46 <= 50) {
                if (jf->body.flags & 4) {
                    func_08011F78(0xEA, jf->body.x - 0x3200 - work->unk_4A * 3 * 512, jf->body.y + 0xA00, jf->body.z + 0x2C00, 20, 20, 20);
                } else {
                    func_08011F78(0xEA, jf->body.x + 0x3200 + work->unk_4A * 3 * 512, jf->body.y + 0xA00, jf->body.z + 0x2C00, 20, 20, 20);
                }
            }

            if (work->unk_46 > 80) {
                work->unk_46 = 0;
                work->y2 = 0x15E00;
                work->z = -0x3800;
                work->unk_44 = 10;
                work->jf->unk_248 = work->unk_5C + 2;
                func_080BE380(work->jf->unk_248, 0x80, work);
                work->unk_48++;
            } else {
                work->unk_46++;
            }
            break;
        case 5:
            if (work->unk_44 > 0) {
                ApproachValue(&jf->body.x, work->x, work->unk_44);
                ApproachValue(&jf->body.y, work->y2, work->unk_44);
                ApproachValue(&jf->body.z, work->z, work->unk_44);
                work->unk_44--;
            } else {
                work->unk_48++;
            }
            break;
        default:
            func_0801AF08(q);
            work->jf->unk_244 = 0;
            work->jf->unk_238 = 6;
            break;
        }
    }
}

void func_080BFDD4(JfMajinWork* work) {
}
void func_080BFDD8(JfMajinWork* work) {
    JfWork* jf = work->jf;
    BtlObj* q = &jf->sub;

    if (jf->unk_244 == 0) {
        if (jf->body.flags & 4) {
            jf->body.x = 0x2A200;
            jf->unk_248 = 8;
        } else {
            jf->body.x = 0x16A00;
            jf->unk_248 = 28;
        }

        jf->body.y = 0x15E00;
        jf->body.z = -0x3800;
        work->jf->unk_24A = 0;
        func_080BE380(work->jf->unk_248, 0x80, work);
        work->unk_3C = 0;
        work->unk_2C = 1;
        work->unk_6A = 0;
        jf->body.flags &= ~0x1000000;
        func_08019190(&jf->body, 9);
        work->jf->unk_244++;
    } else if (jf->unk_244 > 60) {
        func_0801AF08(q);
        work->jf->unk_244 = 0;

        if (jf->body.flags & 4) {
            work->jf->unk_248 = 8;
        } else {
            work->jf->unk_248 = 28;
        }

        work->jf->unk_24A = 0;
        work->jf->unk_238 = 6;
    } else {
        work->jf->unk_244++;
    }
}

void func_080BFEF0(JfMajinWork* work) {
    JfWork* jf = work->jf;
    BtlObj* q = &jf->sub;

    if (jf->unk_244 == 0) {
        if (jf->body.flags & 4) {
            jf->body.x = 0x2A200;
            jf->unk_248 = 8;
        } else {
            jf->body.x = 0x16A00;
            jf->unk_248 = 28;
        }

        jf->body.y = 0x15E00;
        jf->body.z = -0x3800;
        work->jf->unk_24A = 0;
        func_080BE380(work->jf->unk_248, 0x80, work);
        work->unk_3C = 0;
        work->unk_2C = 1;
        work->unk_6A = 0;
        jf->body.flags &= ~0x1000000;
        work->jf->unk_244++;
    } else {
        func_0801AF08(q);
        work->jf->unk_244 = 0;

        if (jf->body.flags & 4) {
            work->jf->unk_248 = 8;
        } else {
            work->jf->unk_248 = 28;
        }

        work->jf->unk_24A = 0;
        work->jf->unk_238 = 6;
    }
}

void func_080BFFF8(JfMajinWork* work) {
    JfWork* jf = work->jf;
    BtlObj* q = &jf->sub;
    PrizeCardArg fx;
    s32 v;

    if (jf->unk_244 == 0) {
        if (jf->body.flags & 4) {
            jf->unk_248 = 8;
            v = 0x2A200;
        } else {
            jf->unk_248 = 28;
            v = 0x16A00;
        }

        jf->body.x = v;

        jf->body.y = 0x15E00;
        jf->body.z = -0x3800;
        func_080BE380(work->jf->unk_248, 0x80, work);
        work->unk_2C = 1;
        func_0802F274(jf->body.x, jf->body.y + jf->body.z);
        func_0801AF4C(&jf->body);
        work->unk_48 = 0;
        work->unk_44 = 0;
        work->jf->unk_244++;
        return;
    }

    switch (work->unk_48) {
    case 0:
        func_0802F274(jf->body.x, jf->body.y + jf->body.z);

        if (work->unk_44 > 1) {
            work->unk_44 = 0;
            work->unk_48++;
        } else {
            work->unk_44++;
        }
        break;
    case 1:
        func_0802F274(jf->body.x, jf->body.y + jf->body.z);

        if (FadeIsActive() != 0) {
            break;
        }

        if (jf->body.flags & 4) {
            func_08014AAC(jf->body.x - 0x800, jf->body.y + jf->body.z - 0x800);
        } else {
            func_08014AAC(jf->body.x + 0x800, jf->body.y + jf->body.z - 0x800);
        }

        FadeToAmount(0, gBtlWork->unk_0B3, 8);
        work->unk_48++;
        break;
    case 2:
        func_0802F274(jf->body.x, jf->body.y + jf->body.z);

        if (work->unk_44 <= 119) {
            work->unk_44++;
        } else {
            func_0801536C();
            work->unk_48++;
        }
        break;
    case 3:
        if (func_080128EC() == 0) {
            if (q->x < 0x1B200) {
                q->x = 0x1BA00;
            }

            if (q->x > 0x25A00) {
                q->x = 0x25200;
            }

            fx.x = q->x;
            fx.y = q->y;
            fx.z = -0x7800;
            CreateBossPrizeCardTask(&gBtlWork->taskPools[0], &fx);
#ifdef VERSION_EU
            func_0801B918(q);
#else
            func_0801B918(&jf->body);
#endif
            gUnk_0203ACC4 = 0;
            gUnk_0203ACD4 = 0;
            gUnk_0203ACC0 = 0;
            func_080BDAAC();
            jf->body.x = 0;
            jf->body.y = 0;
            jf->body.z = 0;
            ScrollBgMapTo(1, (gBtlWork->unk_000 >> 8) + 776, (gBtlWork->unk_004 >> 8) + 294);
            work->unk_48++;
        } else {
            func_0802F274(jf->body.x, jf->body.y + jf->body.z);
        }
        break;
    default:
        func_0801B008();
        work->jf->flags |= 2;
        break;
    }
}

u8 func_080C0258(u16* p, s16 b, u8 c, u8 d) {
    if ((s16)*p == b) {
        return 1;
    }

    if ((s16)*p > b) {
        *p = *p - 1;
    } else {
        BtlObj* q;
        s32 v;

        *p = *p + 1;

        if (c == d) {
            q = gBtlWork->actor;
            v = -(((s16)*p + 1) << 11);

            if (q->z >= v) {
                q->z = v;
            }
        }
    }

    return 0;
}

void func_080C02AC(JfMajinWork* work) {
    JfWork* jf = work->jf;
    BtlObj* s = &work->jf->sub;
    s16 n = 0;
    s16 m;
    u8 v;

    if (jf->unk_250 > 0) {
        jf->unk_244 = 0;
        work->jf->unk_238 = 0;
        return;
    }

    switch (jf->unk_244) {
    case 0:
        if (jf->body.flags & 4) {
            jf->unk_248 = 8;
            work->unk_5C = 8;
        } else {
            jf->unk_248 = 28;
            work->unk_5C = 28;
        }

        work->jf->unk_24A = 0;
        func_080BE380(work->jf->unk_248, 0x80, work);
        work->unk_3C = 0;
        work->unk_2C = 1;

        if (work->jf->flags & 4) {
            work->jf->flags &= ~4;
            work->jf->unk_24E = 2;
            m = 14;
        } else if (s->unk_02C < s->unk_02E / 2) {
            switch (work->jf->unk_24E) {
            case 0:
                m = GetRandom() & 1;
                break;
            case 1:
            case 2:
                m = GetRandom() % 6 + 2;
                break;
            case 3:
                m = GetRandom() % 6 + 8;
                break;
            default:
                m = 0;
                break;
            }
        } else if (work->jf->unk_24E == 0) {
            m = GetRandom() % 6 + 8;
        } else {
            m = GetRandom() % 8;
        }

        work->unk_5E = gUnk_0203ACC4;
        work->unk_60 = gUnk_0203ACD4;
        work->unk_62 = gUnk_0203ACC0;
        work->unk_64 = gUnk_0961A710[m][0];
        work->unk_66 = gUnk_0961A710[m][1];
        work->unk_68 = gUnk_0961A710[m][2];
        work->unk_48 = 0;
        work->unk_46 = 0;
        work->unk_44 = 0;
        func_080BDB28(60);
        work->jf->unk_244++;
        break;
    case 1:
        work->unk_46++;

        if (work->unk_46 > 80) {
            work->unk_46 = 0;
            m4aSongNumStart(0x26A);
            work->jf->unk_244++;
        }
        break;
    default:
        work->unk_46++;

        if (work->unk_46 <= 1) {
            return;
        }

        work->unk_46 = 0;
        v = func_080BE910();
        n += (s8)func_080C0258(&work->unk_5E, work->unk_64, v, 0);
        n += (s8)func_080C0258(&work->unk_60, work->unk_66, v, 1);
        n += (s8)func_080C0258(&work->unk_62, work->unk_68, v, 2);

        if (n == 3) {
            if (s->unk_02C < s->unk_02E / 2) {
                switch (work->jf->unk_24E) {
                case 0:
                    work->jf->unk_24E = 3;
                    break;
                case 1:
                    work->jf->unk_24E = 0;
                    break;
                case 2:
                    work->jf->unk_24E = 0;
                    work->jf->unk_250 = 300;
                    break;
                case 3:
                    work->jf->unk_24E = 1;
                    break;
                }
            } else {
                switch (work->jf->unk_24E) {
                case 0:
                    work->jf->unk_24E = 1;
                    break;
                case 1:
                    work->jf->unk_24E = 0;
                    break;
                case 2:
                    work->jf->unk_24E = 0;
                    work->jf->unk_250 = 300;
                    break;
                }
            }

            work->jf->unk_244 = 0;
            work->jf->unk_238 = 0;
        } else {
            gUnk_0203ACC4 = work->unk_5E;
            gUnk_0203ACD4 = work->unk_60;
            gUnk_0203ACC0 = work->unk_62;
            func_080BDAAC();
        }
        break;
    }
}

void func_080C0624(JfMajinWork* work) {
    if (work->jf->unk_244 == 0) {
        work->jf->unk_248 = 8;
        work->unk_5C = 8;
        work->jf->unk_24A = 0;
        func_080BE380(work->jf->unk_248, 0x80, work);
        work->unk_3C = 0;
        work->unk_2C = 1;
        work->jf->unk_244++;
    } else {
        if (work->jf->unk_24A >= gUnk_0961A6A8[work->jf->unk_248]) {
            work->jf->unk_24A = 0;
            work->jf->unk_248++;
            work->unk_3C++;

            if (work->jf->unk_248 > work->unk_5C + 5) {
                work->jf->unk_248 = work->unk_5C;
                work->unk_3C = 0;
            }

            func_080BE380(work->jf->unk_248, 0x80, work);
        }

        work->jf->unk_24A++;
        work->gfx = AnimUpdate(&work->anim);
        work->y = gUnk_0961A70A[work->unk_3C];
    }
}

void func_080C0714(JfMajinWork* work) {
    BtlObj* s = &work->jf->sub;
    u8 v;
    s32 r;

    if (s->unk_02C < s->unk_02E / 2) {
        if (GetRandom() % 100 <= 9) {
            func_08083900(1);
        } else if (GetRandom() % 90 <= 19) {
            func_08083900(GetRandom() % 2 + 7);
        } else {
            func_08083900(GetRandom() % 4 + 3);
        }

        if (gUnk_0203ACC4 == gUnk_0203ACD4 && gUnk_0203ACC4 == gUnk_0203ACC0 && GetRandom() % 100 <= 79) {
            func_0801BCD4(s);
            work->jf->unk_23C = 5;
        } else {
            v = func_080BE940(work);

            switch (v) {
            case 0:
                func_0801BCD4(s);
                r = (s16)(GetRandom() % 100);

                if (r <= 39) {
                    func_0801BCD4(s);
                    work->jf->unk_23C = 3;
                } else if (r <= 79) {
                    func_0801BCD4(s);
                    work->jf->unk_23C = 4;
                } else {
                    func_0801BCD4(s);
                    work->jf->unk_23C = 2;
                }
                break;
            case 1:
                func_0801BCD4(s);
                work->jf->unk_23C = 2;
                break;
            case 2:
                if (GetRandom() % 100 <= 49) {
                    work->jf->unk_238 = 1;
                } else {
                    func_0801BCD4(s);
                    work->jf->unk_23C = 2;
                }
                break;
            }
        }
    } else {
        if (GetRandom() % 100 <= 29) {
            func_08083900(GetRandom() % 3 + 6);
        } else {
            func_08083900(GetRandom() % 6 + 1);
        }

        if (gUnk_0203ACC4 == gUnk_0203ACD4 && gUnk_0203ACC4 == gUnk_0203ACC0 && GetRandom() % 100 <= 19) {
            func_0801BCD4(s);
            work->jf->unk_23C = 5;
        } else {
            v = func_080BE940(work);

            switch (v) {
            case 0:
                func_0801BCD4(s);

                if (GetRandom() % 100 <= 59) {
                    func_0801BCD4(s);
                    work->jf->unk_23C = 3;
                } else {
                    func_0801BCD4(s);
                    work->jf->unk_23C = 4;
                }
                break;
            case 1:
                if (GetRandom() % 100 <= 79) {
                    func_0801BCD4(s);
                    work->jf->unk_23C = 2;
                } else {
                    func_0801BCD4(s);
                    work->jf->unk_23C = 4;
                }
                break;
            case 2:
                if (GetRandom() % 100 <= 69) {
                    work->jf->unk_238 = 1;
                } else {
                    func_0801BCD4(s);
                    work->jf->unk_23C = 2;
                }
                break;
            }
        }
    }
}
void task_bos_jf_rock_0(JfRockWork* work, JfWork* arg) {
    work->jf = arg;
    work->x = arg->body.x;
    work->y = arg->body.y + 0x500;
    work->z = arg->body.z - 0x4800;
    work->unk_03C = 0;
    work->unk_0F8 = 0xFE00;
    work->unk_060 = 0x20000;
    work->unk_13C = 0;
    work->unk_140 = 0;
    work->unk_144 = 0;
    work->vx = 0;
    work->vy = 0;
    work->vz = 0;
    work->unk_154 = 0;
    work->unk_028 = 0;
    work->unk_02A = 0;
    work->unk_194 = 0;

    if (arg->body.flags & 4) {
        work->x2 = arg->body.x + 0x2000;
        work->y2 = arg->body.y + 0xA00;
        work->z2 = arg->body.z - 0x1900;
        work->unk_144 = -((gUnk_0203ACC0 + 1) << 11) - 0x2000;
    } else {
        work->x2 = arg->body.x - 0x2000;
        work->y2 = arg->body.y + 0xA00;
        work->z2 = arg->body.z - 0x1900;
        work->unk_144 = -0x2000 - ((gUnk_0203ACC4 + 1) << 11);
    }

    work->unk_17C = 0;
    work->unk_17E = 0;
    work->unk_15A = 0;
    work->unk_158 = 0;
    work->unk_15C = 120;
    work->unk_15E = 0;
    work->state = 0;
    work->tiles = LoadObjTiles(gUnk_09682AA4, 0x2800);
    work->palette = LoadObjPalette(gUnk_096FB5A4, 0x60);
    AnimInit(&work->anim, gUnk_09EF3B40, gUnk_09EF3A48);
    AnimStart(&work->anim, gUnk_09EF2A38[work->unk_158], 0);
    work->gfx = AnimGetGfx(&work->anim);
    work->tiles2 = LoadObjTiles(gUnk_09682AA4, 0x2800);
    work->palette2 = LoadObjPalette(gUnk_096FB5A4, 0x60);
    work->gfx2 = gUnk_09EF3A48[gUnk_09EF2A42[work->unk_17E]];
    TaskPoolInit(&work->tasks, 1);
    TaskCreate(&work->tasks, &gTaskDescBosJfShadow, &work->unk_02C);
}
u8 task_bos_jf_rock_1(JfRockWork* work) {
    JfWork* jf = work->jf;
    BtlObj* b;
    s16 n;

    switch (work->state) {
    case 0:
        if (work->unk_15C > 40) {
            func_0802F274(work->x, work->y + work->z - 0x2000);
        }

        work->unk_02A++;

        if (work->unk_02A > 2) {
            work->unk_02A = 0;
            work->unk_028++;

            if (work->unk_028 > 8) {
                work->unk_028 = 0;
            }

            LoadObjPaletteBank(((u16*)work->palette)[3] + 2, gUnk_096FB604 + (work->unk_028 << 5));
        }

        if (work->unk_15C > 0) {
            ApproachValue(&work->z, work->unk_144 - 0x4800, work->unk_15C);
            ApproachValue(&work->z2, work->unk_144 - 0x1C00, work->unk_15C);
            work->unk_15C--;

            if (work->z <= -0xC00) {
                work->unk_158 = 8;
                work->unk_15A = 1;
            } else {
                n = 8 - ((work->z >> 8) + 12) / 8;

                if (n < 0) {
                    work->unk_158 = 0;
                    work->unk_15A = 0;
                } else {
                    work->unk_158 = n;
                    work->unk_15A = 1;
                }
            }

            AnimStart(&work->anim, gUnk_09EF2A38[work->unk_158], 0);
            work->gfx = AnimGetGfx(&work->anim);

            if (work->z2 <= -0x1000) {
                work->unk_17E = 11;
                work->unk_17C = 1;
            } else {
                n = 11 - ((work->z2 >> 8) + 16) / 8;

                if (n < 0) {
                    work->unk_17E = 0;
                    work->unk_17C = 0;
                } else {
                    work->unk_17E = n;
                    work->unk_17C = 1;
                }
            }

            work->gfx2 = gUnk_09EF3A48[gUnk_09EF2A42[work->unk_17E]];
        } else {
            work->unk_13C = (b = gBtlWork->actor)->x;
            work->unk_140 = b->y;
            work->unk_144 = b->z;
            work->vx = (work->unk_13C - work->x) / 40;
            work->vy = (work->unk_140 - work->y) / 40;
            work->vz = 0;
            work->unk_154 = (work->unk_144 - work->z) / 820;
            work->state++;
        }

        if (work->jf->unk_238 == 7 || work->jf->unk_238 == 11) {
            m4aSongNumStart(0x1F9);
            work->unk_17C = 0;
            work->unk_15C = 0;
            work->state = 5;
        }
        break;
    case 1:
        work->unk_02A++;

        if (work->unk_02A > 2) {
            work->unk_02A = 0;
            work->unk_028++;

            if (work->unk_028 > 8) {
                work->unk_028 = 0;
            }

            LoadObjPaletteBank(((u16*)work->palette)[3] + 2, gUnk_096FB604 + (work->unk_028 << 5));
        }

        work->unk_15E++;

        if (work->unk_15E > 3) {
            work->unk_15E = 0;

            if (jf->body.flags & 4) {
                work->x2 = jf->body.x + 0x1000;
                work->y2 = jf->body.y + 0xA00;
                work->z2 = jf->body.z - 0x1000;
            } else {
                work->x2 = jf->body.x - 0x1000;
                work->y2 = jf->body.y + 0xA00;
                work->z2 = jf->body.z - 0x1000;
            }

            work->gfx2 = gUnk_09EF3A48[15];
            m4aSongNumStart(632);
            work->unk_194 = 1;
            work->state++;
        }

        if (work->jf->unk_238 == 7 || work->jf->unk_238 == 11) {
            m4aSongNumStart(0x1F9);
            work->unk_17C = 0;
            work->unk_194 = 0;
            work->unk_15C = 0;
            work->state = 5;
        }
        break;
    case 2:
        work->unk_02A++;

        if (work->unk_02A > 2) {
            work->unk_02A = 0;
            work->unk_028++;

            if (work->unk_028 > 8) {
                work->unk_028 = 0;
            }

            LoadObjPaletteBank(((u16*)work->palette)[3] + 2, gUnk_096FB604 + (work->unk_028 << 5));
        }

        work->x += work->vx;
        work->y += work->vy;
        work->z += work->vz;
        work->vz += work->unk_154;

        if (work->unk_15E == 7) {
            work->unk_17C = 0;
        }

        if (func_08011F78(231, work->x, work->y, work->z - 0x2000, 28, 28, 28) == 1) {
            m4aSongNumStart(0x279);
            func_08014020(work->x - 0x800, work->y + work->z - 0x2400, 0);
            work->unk_194 = 0;
            work->state = 3;
        }

        if (work->jf->unk_238 == 7 || work->jf->unk_238 == 11) {
            m4aSongNumStart(0x1F9);
            work->unk_17C = 0;
            work->unk_194 = 0;
            work->unk_15C = 0;
            work->state = 5;
        }

        switch ((s8)func_080C1370(work->x, work->y, work->z - 0x2000)) {
        case 1:
            m4aSongNumStart(0x1F9);
            func_08014020(work->x - 0x800, work->y + work->z - 0x2400, 0);
            work->unk_194 = 0;
            work->state = 3;
            break;
        case 2:
            work->unk_194 = 0;
            work->state = 4;
            break;
        }

        work->unk_15E++;
        break;
    case 5:
        if (MosaicIsActive() == 0) {
            if (work->unk_15C == 0) {
                func_08014020(work->x - 0x800, work->y + work->z - 0x2400, 0);
                work->unk_15C++;
            } else {
                if (AnimIsFinished(&work->anim)) {
                    return 0;
                }

                work->gfx = AnimUpdate(&work->anim);
            }
        }
        break;
    case 3:
        if (AnimIsFinished(&work->anim)) {
            return 0;
        }

        work->gfx = AnimUpdate(&work->anim);
        break;
    default:
        return 0;
    }

    func_080BD7F8(&work->x, &work->y, (s32)&work->z, (s32*)&work->unk_03C);
    TaskPoolUpdate(&work->tasks);

    return 1;
}

void task_bos_jf_rock_2(JfRockWork* work) {
    JfWork* jf = work->jf;
    u16 pal;
    s32 prio;
    s16 x;
    s16 y;

    if (work->unk_15A == 1) {
        if (jf->body.flags & 4) {
            if (work->x <= 0x259FF) {
                pal = GetBattleSpritePriorityFlags(work->y);
                prio = 0xFD00;
            } else {
                pal = 0x400;
                prio = 0xFFF5;
            }
        } else if (work->x > 0x1B200) {
            pal = GetBattleSpritePriorityFlags(work->y);
            prio = 0xFD00;
        } else {
            pal = 0x400;
            prio = 0xFFF5;
        }

        WorldToScreen(&x, &y, work->x, work->y, work->z);
        DrawSprite(x, y, work->gfx, work->tiles, work->palette, 0, pal, prio);
    }

    if (work->unk_17C == 1) {
        if (jf->body.flags & 4) {
            pal = 0x400;
        } else {
            pal = 0x400;
            pal |= 1;
        }

        WorldToScreen(&x, &y, work->x2, work->y2, work->z2);
        DrawSprite(x, y, work->gfx2, work->tiles2, work->palette2, 0, pal, 0xFFF2);
    }

    if (work->unk_194 == 1) {
        TaskPoolDraw(&work->tasks);
    }
}

void task_bos_jf_rock_3(JfRockWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ReleaseObjTiles(work->tiles2);
    ReleaseObjPalette(work->palette2);
    TaskPoolDestroy(&work->tasks);
}

u8 func_080C1370(s32 a, s32 b, s32 c) {
    s32 t0 = -((gUnk_0203ACC4 + 1) << 11);
    s32 t1 = -((gUnk_0203ACD4 + 1) << 11);
    s32 t2 = -((gUnk_0203ACC0 + 1) << 11);
    s32 hi = a + 0x1C00;
    s32 lo = a - 0x1C00;
    s32 zh = c + 0x1C00;
    s32 zl = c - 0x1C00;

    if (zh >= t0 && hi > 0x1B200 && lo < 0x1EA00) {
        return 1;
    }

    if (zh >= t1 && hi > 0x1EA00 && lo < 0x22200) {
        return 1;
    }

    if (zh >= t2 && hi > 0x22200 && lo < 0x25A00) {
        return 1;
    }

    if (zl > 0 || lo > 0x2CA00 || hi < 0x14200) {
        return 2;
    }

    return 0;
}

void task_bos_jf_borderline_0(JfBorderlineWork* work, BosPos* arg) {
    work->jf = arg;
    func_080C1A48(work);
    work->unk_0A8 = 0xA00;
    work->unk_0AC = 0x3600;
    work->x = arg->x + work->unk_0A4;
    work->y = arg->y + work->unk_0A8;
    work->z = arg->z + work->unk_0AC;
    work->unk_0B0 = 0;
    work->unk_0B2 = 0;
    work->unk_0B4 = 0;
    work->unk_0B5 = 0;
    work->tiles = LoadObjTiles(gUnk_09682AA4, 0x2800);
    work->palette = LoadObjPalette(gUnk_096FB5A4, 0x60);
    AnimInit(&work->anim, gUnk_09EF3B40, gUnk_09EF3A48);
    AnimStart(&work->anim, 27, 1);
    work->gfx = AnimGetGfx(&work->anim);
    AnimInit(&work->anim2, gUnk_09EF3B40, gUnk_09EF3A48);
    AnimStart(&work->anim2, 8, 1);
    work->gfx2 = AnimGetGfx(&work->anim2);
    AnimInit(&work->anim3, gUnk_09EF3B40, gUnk_09EF3A48);
    AnimStart(&work->anim3, 7, 1);
    work->gfx3 = AnimGetGfx(&work->anim3);
    AnimInit(&work->anim4, gUnk_09EF3B40, gUnk_09EF3A48);
    AnimStart(&work->anim4, 28, 1);
    work->gfx4 = AnimGetGfx(&work->anim4);
    AnimInit(&work->anim5, gUnk_09EF3B40, gUnk_09EF3A48);
    AnimStart(&work->anim5, 6, 1);
    work->gfx5 = AnimGetGfx(&work->anim5);
    func_0801C298(*(u8*)((u8*)work->palette + 6) + 16, 0);
}

u8 task_bos_jf_borderline_1(JfBorderlineWork* work) {
    BosPos* p = work->jf;

    func_080C1A48(work);
    work->x = p->x + work->unk_0A4;
    work->y = p->y + work->unk_0A8;
    work->gfx = AnimUpdate(&work->anim);
    work->gfx2 = AnimUpdate(&work->anim2);
    work->gfx3 = AnimUpdate(&work->anim3);
    work->gfx4 = AnimUpdate(&work->anim4);
    work->gfx5 = AnimUpdate(&work->anim5);

    return 1;
}

void task_bos_jf_borderline_2(JfBorderlineWork* work) {
    s16 sx;
    s16 sy;

    WorldToScreen(&sx, &sy, work->x, work->y, work->z);

    switch (work->unk_0B5) {
    case 0:
        DrawSprite(sx - 16, sy - 1, work->gfx, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx - 16, sy - 1, work->gfx3, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx, sy + 1, work->gfx3, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx + 16, sy - 1, work->gfx3, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx + 16, sy - 1, work->gfx2, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx - 8, sy + 4, work->gfx, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx - 8, sy + 4, work->gfx3, work->tiles, work->palette, 0, 0x400,
            0xFF60);
        DrawSprite(sx + 8, sy + 4, work->gfx3, work->tiles, work->palette, 0, 0x400,
            0xFF60);
        DrawSprite(sx + 8, sy + 4, work->gfx2, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        break;
    case 1:
        DrawSprite(sx - 40, sy - 1, work->gfx, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx - 40, sy - 1, work->gfx3, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx - 24, sy + 1, work->gfx3, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx - 8, sy + 2, work->gfx3, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx + 8, sy + 2, work->gfx3, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx + 24, sy + 1, work->gfx3, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx + 40, sy - 1, work->gfx3, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx + 40, sy - 1, work->gfx2, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx - 32, sy + 4, work->gfx, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        DrawSprite(sx - 32, sy + 4, work->gfx3, work->tiles, work->palette, 0, 0x400,
            0xFF60);
        DrawSprite(sx - 16, sy + 6, work->gfx3, work->tiles, work->palette, 0, 0x400,
            0xFF60);
        DrawSprite(sx, sy + 7, work->gfx3, work->tiles, work->palette, 0, 0x400,
            0xFF60);
        DrawSprite(sx + 16, sy + 6, work->gfx3, work->tiles, work->palette, 0, 0x400,
            0xFF60);
        DrawSprite(sx + 32, sy + 4, work->gfx3, work->tiles, work->palette, 0, 0x400,
            0xFF60);
        DrawSprite(sx + 32, sy - 4, work->gfx2, work->tiles, work->palette, 0, 0x400,
            0xFFF0);
        break;
    }

    DrawSprite(sx, sy - 8, work->gfx5, work->tiles, work->palette, 0, 0x400, 0xFF00);
}

void task_bos_jf_borderline_3(JfBorderlineWork* work) {
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
}

void func_080C1A48(JfBorderlineWork* work) {
    JfWork* jf = (JfWork*)work->jf;

    switch (jf->unk_238) {
    case 0:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        if (jf->body.flags & 4) {
            work->unk_0A4 = -0x500;
        } else {
            work->unk_0A4 = 0x500;
        }
        break;
    case 3:
        if (jf->body.flags & 4) {
            work->unk_0A4 = -0x100;
        } else {
            work->unk_0A4 = 0x100;
        }
        break;
    case 4:
    case 5:
        if (jf->body.flags & 4) {
            work->unk_0A4 = 0x1000;
        } else {
            work->unk_0A4 = -0x1000;
        }
        break;
    case 1:
    case 2:
        if (jf->body.flags & 4) {
            work->unk_0A4 = -0xA00;
        } else {
            work->unk_0A4 = 0xA00;
        }

        work->unk_0B5 = 1;
        return;
    default:
        if (jf->body.flags & 4) {
            work->unk_0A4 = -0x500;
        } else {
            work->unk_0A4 = 0x500;
        }
        break;
    }

    work->unk_0B5 = 0;
}

void task_bos_dsd_0(DsdWork* work, void* arg) {
    s32 v;
    DsdWork* w;
    BtlObj* p1;
    BtlObj* p2;
    BtlWork* btl;

    work->flags = 0;

    if (arg != 0) {
        work->flags = 16;
    }

    TaskPoolInit(&work->tasks, 4);

    if (work->flags & 16) {
        TaskCreate(&work->tasks, &gTaskDescBosDsdMap, 0);
    } else {
        TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBosDsdMap, work);
    }

    work->unk_390 = 0;
    work->unk_392 = 0;

    if (work->flags & 16) {
        work->unk_334 = 9;
    } else {
        work->unk_334 = 1;
    }

    work->unk_338 = 1;
    work->unk_330 = 1;
    work->unk_33C = 0;
    work->unk_34C = 0;
    work->timer = 0;
    work->unk_350 = 0;
    work->unk_352 = 0;
    work->unk_354 = 0;
    work->unk_356 = 0;
    work->unk_35A = 0;
    work->unk_35C = -51;
    v = (s16)(work->flags & 16);

    if (v != 0) {
        work->unk_340 = 0xDC00;
        work->unk_344 = 0x16800;
        work->unk_348 = -0x6400;
        w = work;
        func_0801B37C(w, &gBosDsdEmyKind, work->unk_340, work->unk_344, work->unk_348);
        p1 = &w->body[1];
        func_0801B37C(p1, &gBosDsdEmyKind, 0xDC00, 0x16800, -0x8C00);
        p2 = &w->body[2];
        func_0801B37C(p2, &gBosDsdEmyKind, 0x9000, 0x16800, 0);
        TaskCreate(&w->tasks, &gTaskDescBosDsdMain, w);
    } else {
        work->unk_340 = 0xDC00;
        work->unk_344 = 0x16800;
        work->unk_348 = -0x6400;
        w = work;
        func_0801B37C(w, &gBosDsdEmyKind, work->unk_340, work->unk_344, work->unk_348);
        w->body[0].flags |= 0x1000000;
        w->body[0].flags |= 4;
        p1 = &w->body[1];
        func_0801B37C(p1, &gBosDsdEmyKind, 0xDC00, 0x16800, -0x8C00);
        p1->flags |= 4;
        p1->flags |= 0x400;
        p1->unk_0A2 = v;
        p1->unk_09E = 16;
        p1->unk_0A0 = 16;
        p1->unk_09C = 16;
        p2 = &w->body[2];
        func_0801B37C(p2, &gBosDsdEmyKind, 0x9000, 0x16800, v);
        p2->flags |= 0x003C000001000004ULL;
        p2->unk_0A2 = v;
        p2->unk_09E = 16;
        p2->unk_0A0 = 16;
        p2->unk_09C = 32;
        ColliderInit(&p2->collider, 7, 16, 32);
        ColliderSetPosition(&p2->collider, p2->x, p2->y, p2->z);
        ColliderSetDisabled(&p2->collider, 1);
        func_0801BDD4(p2, p1);
        gBtlWork->unk_0D8 = v;
        func_0801C298(0, 1);
        SetBattleActorPosition(0x6400, 0x16800, 0);
        func_0801C274(0x2800, 0x16800, 0);
        TaskCreate(&w->tasks, &gTaskDescBosDsdMain, w);
        btl = gBtlWork;
        btl->unk_0CC = w->body[0].x;
        btl->unk_0D0 = w->body[0].y;
        btl->unk_0D4 = w->body[0].z;
    }
}
u8 task_bos_dsd_1(DsdWork* work) {
    BtlWork* q;
    BtlObj* a = work->body;
    BtlObj* b = &work->body[1];

    if (work->flags & 0x10) {
        TaskPoolUpdate(&work->tasks);
        return 1;
    }

    switch (func_0801ADAC(b)) {
    case 5:
        work->unk_334 = 2;
        b->flags |= 0x1000000;
        work->unk_350 = 0;
        break;
    case 1:
    case 6:
    case 7:
        work->flags |= 1;
        work->timer = 20;
        break;
    case 3:
    case 8:
        work->unk_334 = 11;
        work->unk_350 = 0;
        break;
    case 4:
        work->unk_334 = 8;
        work->unk_350 = 0;
        break;
    }

    if (work->flags & 1) {
        work->timer--;

        if ((s16)work->timer <= 0) {
            work->unk_34C = 0;
            work->flags &= ~1;
            LoadPaletteWithEffect(gUnk_096FB744, (void*)0x05000000, 32);
            func_0801AF08(b);

            if (b->unk_02C > 0) {
                switch (work->unk_334) {
                case 0:
                case 1:
                case 4:
                case 5:
                case 8:
                    break;
                default:
                    work->unk_334 = 0;
                    work->unk_350 = 0;
                    break;
                }
            }
        }
    }

    if (func_0801C1C0(0)) {
        work->flags |= 8;
        TaskCreate(&work->tasks, &gTaskDescBosDsdIta, work);
    }

    if (work->unk_334 == 4) {
        if (gBtlWork->actor->z <= -0x1000) {
            gBtlWork->unk_0D8 = -30;
        } else {
            gBtlWork->unk_0D8 = 0;
        }
    } else {
        gBtlWork->unk_0D8 = 0;
    }

    TaskPoolUpdate(&work->tasks);
    q = gBtlWork;
    q->unk_0CC = a->x;
    q->unk_0D0 = a->y;
    q->unk_0D4 = a->z;

    if (work->flags & 2) {
        return 0;
    }

    return 1;
}

void task_bos_dsd_2(DsdWork* work) {
    TaskPoolDraw(&work->tasks);
}

void task_bos_dsd_3(DsdWork* work) {
    BtlObj* a;
    BtlObj* b;

    a = &work->body[1];
    b = &work->body[2];
    TaskPoolDestroy(&work->tasks);
    ColliderUnregister(&work->body[2].collider);
    func_0801B7D8(work);
    func_0801B7D8(a);
    func_0801B7D8(b);
}

void func_080C211C(u8 index) {
    SetBgMapBlocks(1, gUnk_09EF2AA4[index], 2, 2);
}

void func_080C213C(u8 index, u16 a) {
    SetBgMapBlocks(1, gUnk_09EF2AA4[index], 2, 2);
    LoadBgTiles(1, gUnk_09EF2D94[index], a * 32);
}

void task_bos_dsd_main_0(DsdMainWork* work, DsdWork* arg) {
    BtlObj* s = &work->body;

    work->dsd = arg;
    SetBgPriority(1, 1);
    SetBgPriority(0, 3);
    work->dsd->unk_334 = arg->unk_334;
    work->unk_008 = 0;
    work->unk_006 = 0;
    work->unk_004 = 0;
    work->unk_00A = 0;
    work->unk_054 = 1;
    work->unk_06C = 0;
    work->unk_070 = gBtlWork->unk_1CA;
    SetBgMapBlocks(1, gUnk_09EF2AA4, 2, 2);
    work->tiles = LoadObjTiles(gUnk_096983E4, 0x12A0);
    AnimInit(&work->anim, gUnk_09EF3C34, gUnk_09EF3C20);
    AnimStart(&work->anim, 0, 1);
    work->gfx = AnimGetGfx(&work->anim);
    arg->body[0].y++;
    arg->body[0].y--;
    work->tiles2 = LoadObjTiles(gUnk_096983E4, 0x12A0);
    AnimInit(&work->anim2, gUnk_09EF3C4C, gUnk_09EF3C38);
    AnimStart(&work->anim2, 0, 1);
    work->gfx2 = AnimGetGfx(&work->anim2);
    work->palette = LoadObjPalette(gUnk_096FB8C4, 32);
    work->palette2 = LoadObjPalette(gUnk_08F69BC4, 32);
    work->dsd->tiles = AllocObjTiles(0x800, gUnk_096A2F04);
    work->dsd->palette = LoadObjPalette(gUnk_096FB8E4, 32);
    work->dsd->tiles2 = LoadObjTiles(gUnk_096869A4, 0x740);
    work->dsd->palette2 = LoadObjPalette(gUnk_096FB864, 32);
    work->dsd->palette3 = LoadObjPalette(gUnk_096FB884, 32);
    work->dsd->tiles3 = LoadObjTiles(gUnk_08B22CE4, 0x200);
    work->dsd->palette4 = LoadObjPalette(gUnk_08F69BA4, 32);
    s->x = 0xDC00;
    s->y = 0x16800;
    s->z = 0;
    ColliderInit(&s->collider, 8, 24, 100);
    ColliderSetPosition(&s->collider, s->x, s->y, s->z);
    ScrollBgMapTo(1, ((gBtlWork->unk_000 - arg->body[0].x) >> 8) + 100,
                  ((gBtlWork->unk_004 - (arg->body[0].y + arg->body[0].z)) >> 8) + 280);
    TaskPoolInit(&work->tasks, 10);
    func_080C2828(work);
}

u8 task_bos_dsd_main_1(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* p = &work->body;

    func_080C2734(work);

    switch (work->dsd->unk_334) {
    case 0:
        work->dsd->unk_330 = work->dsd->unk_334;
        func_080C2BB0(work);
        break;
    case 1:
        work->dsd->unk_330 = work->dsd->unk_334;
        func_080C2944(work);
        break;
    case 2:
        work->dsd->unk_330 = work->dsd->unk_334;
        func_080C2A2C(work);
        break;
    case 3:
        work->dsd->unk_330 = work->dsd->unk_334;
        func_080C2CC0(work);
        break;
    case 4:
        work->dsd->unk_330 = work->dsd->unk_334;
        func_080C2FD8(work);
        break;
    case 5:
        work->dsd->unk_330 = work->dsd->unk_334;
        func_080C3188(work);
        break;
    case 6:
        work->dsd->unk_330 = work->dsd->unk_334;
        func_080C3574(work);
        break;
    case 7:
        work->dsd->unk_330 = work->dsd->unk_334;
        func_080C3754(work);
        break;
    case 8:
        func_080C386C(work);
        break;
    case 9:
        func_080C3C34(work);
        break;
    case 10:
        func_080C3868(work);
        break;
    case 11:
        func_080C3928(work);
        break;
    }

    ColliderSetPosition(&d->body[0].collider, d->body[0].x, d->body[0].y, d->body[0].z);
    ColliderSetPosition(&p->collider, p->x, p->y, p->z);
    TaskPoolUpdate(&work->tasks);
    work->unk_070 = gBtlWork->unk_1CA;

    return 1;
}

void task_bos_dsd_main_2(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    void* gfx;
    s16 x;
    s16 y;

    if (gBtlWork->unk_070 != 0) {
        LoadPaletteWithEffect(gUnk_096FB744, (void*)0x05000000, 32);
        gfx = work->palette;
    } else if (d->flags & 1) {
        if (gFrameCounter & 1) {
            LoadPaletteWithEffect(gUnk_08F69BC4, (void*)0x05000000, 32);
            gfx = work->palette2;
        } else {
            LoadPaletteWithEffect(gUnk_096FB744, (void*)0x05000000, 32);
            gfx = work->palette;
        }
    } else {
        gfx = work->palette;
    }

    ScrollBgMapTo(1, ((gBtlWork->unk_000 - d->body[0].x) >> 8) + 100,
                  ((gBtlWork->unk_004 - (d->body[0].y + d->body[0].z)) >> 8) + 280);

    if (work->unk_054 == 1) {
        GetBattleSpritePriorityFlags(d->body[0].y);
        WorldToScreen(&x, &y, d->body[0].x, d->body[0].y, -0x6400);
        DrawSprite(x - 96, y + 20, work->gfx, work->tiles, gfx, 0, 0x400,
                   (u16)(-4101 - (d->body[0].y >> 8) * 4));
        DrawSprite(x - 96, y + 20, work->gfx2, work->tiles2, gfx, 0, 0x800,
                   (u16)(-4099 - (d->body[0].y >> 8) * 4));
    }

    TaskPoolDraw(&work->tasks);
}

void task_bos_dsd_main_3(DsdMainWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjTiles(work->tiles2);
    ReleaseObjPalette(work->palette);
    ReleaseObjPalette(work->palette2);
    ReleaseObjTiles(work->dsd->tiles);
    ReleaseObjPalette(work->dsd->palette);
    ReleaseObjTiles(work->dsd->tiles2);
    ReleaseObjPalette(work->dsd->palette2);
    ReleaseObjPalette(work->dsd->palette3);
    ReleaseObjTiles(work->dsd->tiles3);
    ReleaseObjPalette(work->dsd->palette4);
    ColliderUnregister(&work->body.collider);
    TaskPoolDestroy(&work->tasks);
}

void func_080C2734(DsdMainWork* work) {
    BtlObj* q = &work->dsd->body[1];

    if (q->unk_02C > 0) {
        if (GetRandom() % 30 == 0) {
            TaskCreate(&work->tasks, &gTaskDescBosDsdRock, work->dsd);
        }

        if ((work->dsd->flags & 0x20) == 0) {
            gBtlWork->actor->x += work->dsd->unk_35C;
        }

        if (work->unk_070 != (s8)gBtlWork->unk_1CA) {
            if ((s8)gBtlWork->unk_1CA > 0) {
                work->dsd->flags |= 0x40;

                if ((s8)gBtlWork->unk_1CA > 14) {
                    work->dsd->unk_35C = 0x180;
                } else {
                    work->dsd->unk_35C = ((s8)gBtlWork->unk_1CA << 8) / 10;
                }
            } else if ((s8)gBtlWork->unk_1CA < 0) {
                work->dsd->flags |= 0x40;
                work->dsd->unk_35C = ((s8)gBtlWork->unk_1CA << 9) / 10;
            } else {
                work->dsd->flags &= ~0x40;
            }
        } else {
            work->dsd->flags &= ~0x40;
        }
    }
}

void func_080C2828(DsdMainWork* work) {
    DsdWork* p = work->dsd;
    BtlObj* q = &p->body[1];

    p->unk_354 = 0;
    work->unk_00A = 0;
    work->dsd->unk_356 = 0;
    func_080C213C(0, 0x60);
    work->unk_054 = 1;
    AnimStart(&work->anim, 0, 1);
    AnimStart(&work->anim2, 0, 1);
    p->body[0].z = -0x6400;
    q->z = -0x8C00;
}

void func_080C288C(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* q = &d->body[1];

    if (d->unk_356 >= gUnk_0961A7D0[d->unk_354]) {
        d->unk_356 = 0;
        work->dsd->unk_354++;

        if (work->dsd->unk_354 > work->unk_00A + 7) {
            work->dsd->unk_354 = work->unk_00A;
        }

        func_080C213C(work->dsd->unk_354, 0x60);
        d->body[0].z += gUnk_0961A82E[work->dsd->unk_354] << 8;
        q->z += gUnk_0961A82E[work->dsd->unk_354] << 8;
    }

    work->dsd->unk_356++;
    work->gfx = AnimUpdate(&work->anim);
    work->gfx2 = AnimUpdate(&work->anim2);
}

void func_080C2944(DsdMainWork* work) {
    func_080C288C(work);

    if (gBtlWork->unk_0A0 != 0) {
        if (GetRandom() % 80 == 0) {
            func_080C3C40(work);
        }
    }
}

void func_080C297C(DsdMainWork* work, s32 x, s32 y, s32 z) {
    BtlObj* q = &work->dsd->body[1];

    FadeSetPaletteExcluded(0, 0);
    FadeSetPaletteExcluded(0x13, 0);
    FadeToAmount(0, 0x14, 8);
    func_08018B04(x - 0x1400, y, z - 0xA00, 0x100);
    m4aSongNumStart(0x2D1);
    q->flags |= 0x01000000;
}

void func_080C29F4(DsdMainWork* work) {
    BtlObj* q = &work->dsd->body[1];

    FadeToOriginal(0, 8);
    FadeSetPaletteExcluded(0, 1);
    FadeSetPaletteExcluded(19, 1);
    q->flags &= ~0x1000000;
}

void func_080C2A2C(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* q = &d->body[1];
    BtlObj* p = &work->body;

    switch (d->unk_350) {
    case 0:
        func_080C297C(work, d->body[0].x, d->body[0].y, d->body[0].z);
        work->unk_006 = 0;
        work->dsd->unk_350++;
        break;
    case 1:
        work->unk_006++;

        if (work->unk_006 > 11) {
            DisableBg(1);
            work->unk_054 = 0;
            work->dsd->unk_350++;
        }
        break;
    case 2:
        switch (d->unk_338) {
        case 4:
        case 5:
            CreateBgTileTransferTask(&work->tasks, 1, 0, 0x2C8, 8, (u32)gUnk_09699684);
            break;
        case 6:
            CreateBgTileTransferTask(&work->tasks, 1, 0, 0x280, 8, (u32)gUnk_096A3F44);
            break;
        case 7:
            CreateBgTileTransferTask(&work->tasks, 1, 0, 0x200, 8, (u32)gUnk_096A8BA4);
            break;
        }

        work->unk_006 = 0;
        work->dsd->unk_350++;
        break;
    case 3:
        work->unk_006++;

        if (work->unk_006 > 9) {
            work->unk_006 = 0;
            d->unk_350++;
        }
        break;
    default:
        work->dsd->unk_350 = 0;

        switch (work->dsd->unk_338) {
        case 4:
        case 5:
            p->x = 0xDC00;
            p->y = 0x16800;
            p->z = -0x4000;
            work->dsd->unk_334 = 3;
            break;
        case 6:
            p->x = 0xBC00;
            p->y = 0x16800;
            p->z = 0;
            work->dsd->unk_334 = 6;
            break;
        case 7:
            p->x = 0xDC00;
            p->y = 0x16800;
            p->z = 0;
            work->dsd->unk_334 = 7;
            break;
        }

        q->flags &= ~0x1000000;
        break;
    }
}

void func_080C2BB0(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* q = &d->body[1];
    BtlObj* p = &work->body;

    switch (d->unk_350) {
    case 0:
        func_080C297C(work, d->body[0].x, d->body[0].y, d->body[0].z);
        work->unk_006 = 0;
        work->dsd->unk_350++;
        break;
    case 1:
        work->unk_006++;

        if (work->unk_006 > 4) {
            DisableBg(1);
            work->dsd->unk_350++;
        }
        break;
    case 2:
        CreateBgTileTransferTask(&work->tasks, 1, 0, 0x120, 3, (u32)gUnk_096874E4);
        work->unk_006 = 0;
        work->dsd->unk_350++;
        break;
    case 3:
        work->unk_006++;

        if (work->unk_006 > 4) {
            work->unk_006 = 0;
            func_080C2828(work);
            d->body[0].x = 0xDC00;
            q->x = 0xDC00;
            p->x = 0xDC00;
            p->y = 0x16800;
            p->z = 0;
            work->dsd->unk_350++;
        }
        break;
    case 4:
        if (func_080128EC() == 0) {
            func_080C29F4(work);
            work->dsd->unk_350++;
        }
        break;
    default:
        d->unk_350 = 0;
        work->dsd->unk_334 = 1;
        break;
    }
}

void func_080C2CC0(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* q = &d->body[1];

    switch (d->unk_350) {
    case 0:
        work->dsd->unk_354 = 8;
        work->unk_00A = 8;
        work->dsd->unk_356 = 0;
        work->unk_006 = 0;
        work->unk_004 = 30;
        func_080C213C(8, 0x80);
        EnableBg(1);
        d->body[0].x = 0x13C00;
        d->body[0].y = 0x16800;
        d->body[0].z = -0xAC00;
        q->x = 0x13C00;
        q->y = 0x16800;
        q->z = -0xD400;
        work->dsd->unk_350++;
        break;
    case 1:
        if (func_080128EC() != 0) {
            break;
        }

        func_080C29F4(work);
        work->dsd->unk_350++;
        break;
    case 2:
        if ((s16)work->unk_004 > 0) {
            ApproachValue(&d->body[0].x, 0xDC00, work->unk_004);
            ApproachValue(&d->body[0].z, -0x9400, work->unk_004);
            ApproachValue(&q->x, 0xDC00, work->unk_004);
            ApproachValue(&q->z, -0xBC00, work->unk_004);
            func_0802F274(d->body[0].x, d->body[0].y + d->body[0].z);
            work->unk_004--;
        } else {
            work->unk_006 = 0;
            work->dsd->unk_354 = 9;
            func_080C213C(work->dsd->unk_354, 0x80);
            q->x = 0xEC00;
            q->z = -0x9400;
            work->dsd->unk_350++;
        }
        break;
    case 3:
        work->unk_006++;

        if (work->unk_006 > 3) {
            work->unk_006 = 0;
            work->dsd->unk_354 = 10;
            func_080C213C(work->dsd->unk_354, 0x80);
            q->x = 0xFC00;
            q->z = -0x9400;
            work->dsd->unk_350++;
        }
        break;
    case 4:
        work->unk_006++;

        if (work->unk_006 > 1) {
            work->unk_006 = 0;
            d->body[0].x += 0x100;
            d->body[0].z += -0x100;
            work->dsd->unk_350++;
        }
        break;
    case 5:
        work->unk_006++;

        if (work->unk_006 > 1) {
            work->unk_006 = 0;
            d->body[0].x += -0x100;
            d->body[0].z += 0x100;
            work->dsd->unk_350++;
        }
        break;
    case 6:
        work->unk_006++;

        if (work->unk_006 > 25) {
            work->unk_006 = 0;
            work->dsd->unk_354 = 11;
            func_080C213C(work->dsd->unk_354, 0x80);
            q->x = 0xEC00;
            q->z = -0x9400;
            work->dsd->unk_350++;
        }
        break;
    case 7:
        work->unk_006++;

        if (work->unk_006 > 3) {
            work->unk_006 = 0;
            work->dsd->unk_354 = 12;
            func_080C213C(work->dsd->unk_354, 0x80);
            q->x = 0xB400;
            q->z = -0x8400;
            work->dsd->unk_350++;
        }
        break;
    case 8:
        work->unk_006++;

        if (work->unk_006 > 3) {
            work->unk_006 = 0;
            work->dsd->unk_350++;
        }
        break;
    default:
        d->unk_350 = 0;
        work->dsd->unk_334 = work->dsd->unk_338;
        break;
    }
}

void func_080C2F68(DsdMainWork* work) {
    if (work->dsd->unk_356 >= gUnk_0961A7D0[work->dsd->unk_354]) {
        work->dsd->unk_356 = 0;
        work->dsd->unk_354++;

        if (work->dsd->unk_354 > work->unk_00A + 7) {
            work->dsd->unk_354 = work->unk_00A;
        }

        func_080C213C(work->dsd->unk_354, 0x80);
    }

    work->dsd->unk_356++;
}

void func_080C2FD8(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* a = &d->body[1];
    BtlObj* b = &d->body[2];

    switch (d->unk_350) {
    case 0:
        work->dsd->unk_354 = 13;
        work->unk_00A = 13;
        work->dsd->unk_356 = 0;
        work->unk_006 = 0;
        func_080C213C(13, 0x80);
        b->x = 0x7600;
        b->y = 0x16800;
        b->z = 0;
        b->flags &= ~0x1000000;
        func_0802F1E8();
        m4aSongNumStart(0x2B9);
        func_0801801C(0x7800, 0x16800, 0, 0x100);
        ColliderSetDisabled(&b->collider, 0);
        work->dsd->unk_350++;
        break;
    case 1:
        func_080C2F68(work);
        work->unk_006++;

        if (work->unk_006 > 1) {
            work->unk_006 = 0;
            d->body[0].x += -0x100;
            d->body[0].z += 0x100;
            work->dsd->unk_350++;
        }
        break;
    case 2:
        func_080C2F68(work);
        work->unk_006++;

        if (work->unk_006 > 1) {
            work->unk_006 = 0;
            d->body[0].x += 0x100;
            d->body[0].z += -0x100;
            work->dsd->unk_350++;
        }
        break;
    case 3:
        func_080C2F68(work);

        if (func_080128EC() == 0) {
            func_0801AF08(a);
            work->unk_006 = 0;
            work->dsd->unk_350++;
        }
        break;
    case 4:
        func_080C2F68(work);
        work->unk_006++;

        if (work->unk_006 > 179) {
            work->unk_006 = 0;
            work->dsd->unk_350++;
        }
        break;
    case 5:
        func_080C213C(8, 0x80);
        b->flags |= 0x1000000;
        ColliderSetDisabled(&b->collider, 1);
        work->dsd->unk_350++;
        break;
    default:
        d->unk_350 = 0;
        work->dsd->unk_334 = 0;
        break;
    }
}

void func_080C3188(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* a = &d->body[1];
    BtlObj* b = &d->body[2];
    BtlObj* e;

    switch (d->unk_350) {
    case 0:
        work->dsd->unk_354 = 21;
        work->unk_00A = 21;
        work->dsd->unk_356 = 0;
        func_080C213C(work->dsd->unk_354, 0x80);
        TaskCreate(&work->tasks, &gTaskDescBosDsdCircle, work->dsd);
        func_080147D8(0x8000, 0x15400);
        func_08011F78(0x101, 0x8000, 0x16800, -0x1400, 16, 16, 16);
        m4aSongNumStart(0x2BC);
        work->dsd->unk_350++;
        break;
    case 1:
        if (++work->dsd->unk_356 >= gUnk_0961A7D0[work->dsd->unk_354]) {
            work->dsd->unk_356 = 0;
            work->dsd->unk_354++;
            a->z += 0x600;

            if (work->dsd->unk_354 > work->unk_00A + 6) {
                work->dsd->unk_354 = work->unk_00A + 6;
                work->dsd->unk_350++;
            }

            func_080C213C(work->dsd->unk_354, 0x80);
        }
        break;
    case 2:
        work->dsd->unk_354 = 28;
        work->unk_00A = 28;
        work->dsd->unk_356 = 0;
        work->unk_006 = 0;
        func_0801AF08(a);
        b->x = 0x9000;
        b->y = 0x16800;
        b->z = 0;
        b->flags &= ~0x1000000;
        work->dsd->unk_350++;
        break;
    case 3:
        if (++work->dsd->unk_356 >= gUnk_0961A7D0[work->dsd->unk_354]) {
            work->dsd->unk_356 = 0;
            work->dsd->unk_354++;

            if (work->dsd->unk_354 > work->unk_00A + 6) {
                work->dsd->unk_354 = work->unk_00A;
            }

            func_080C213C(work->dsd->unk_354, 0x80);
        }

        work->unk_006++;

        if (work->unk_006 > 299) {
            work->dsd->unk_350++;
        }
        break;
    case 4:
        work->dsd->unk_354 = 27;
        work->unk_00A = 27;
        work->dsd->unk_356 = 0;
        work->unk_006 = 0;
        b->flags |= 0x1000000;
        work->dsd->unk_350++;
        break;
    case 5:
        if (++work->dsd->unk_356 >= gUnk_0961A7D0[work->dsd->unk_354]) {
            work->dsd->unk_356 = 0;
            work->dsd->unk_354--;
            a->z -= 0x600;

            if (work->dsd->unk_354 < work->unk_00A - 6) {
                work->dsd->unk_354 = work->unk_00A - 6;

                if (gBtlWork->unk_0EC <= 0 && (work->dsd->flags & 8) == 0) {
                    _0801C1F8(0, d->body[0].x, d->body[0].y, d->body[0].z);
                }

                work->dsd->unk_350++;
            }

            func_080C213C(work->dsd->unk_354, 0x80);
        }
        break;
    case 6:
        work->unk_006 = 0;
        func_080C213C(8, 0x80);
        e = ListPoolFirst(&gBtlWork->pool);

        while (e != 0) {
            if (e->unk_000 == 0) {
                e->flags |= 0x40;
                m4aSongNumStart(0x227);
            }

            e = ListPoolNext(&e->node);
        }

        work->dsd->unk_350++;
        break;
    default:
        d->unk_350 = 0;
        work->dsd->unk_334 = 0;
        break;
    }
}

void func_080C3504(DsdMainWork* work) {
    if (work->dsd->unk_356 >= gUnk_0961A7D0[work->dsd->unk_354]) {
        work->dsd->unk_356 = 0;
        work->dsd->unk_354++;

        if (work->dsd->unk_354 > work->unk_00A + 4) {
            work->dsd->unk_354 = work->unk_00A;
        }

        func_080C211C(work->dsd->unk_354);
    }

    work->dsd->unk_356++;
}

void func_080C3574(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* q = &d->body[1];

    switch (d->unk_350) {
    case 0:
        work->dsd->unk_354 = 36;
        work->unk_00A = 36;
        work->dsd->unk_356 = 0;
        work->unk_004 = 30;
        work->unk_054 = 0;
        func_080C211C(work->dsd->unk_354);
        q->x = 0xDC00;
        q->z = -0x6000;
        work->dsd->unk_350++;
        break;
    case 1:
        if (func_080128EC() != 0) {
            break;
        }

        func_080C29F4(work);
        work->unk_006 = 0;
        work->unk_004 = 0;
        work->dsd->unk_350++;
        break;
    case 2:
        func_080C3504(work);
        work->unk_184 = TaskCreate(&work->tasks, &gTaskDescBosDsdEnergy1, work->dsd);
        work->dsd->unk_350++;
        break;
    case 3:
        func_080C3504(work);

        if (IsTaskActive(work->unk_184) != 0) {
            break;
        }

        if (work->dsd->unk_35A == 0) {
            work->dsd->unk_350 = 6;
            break;
        }

        work->unk_006++;

        if (work->unk_006 > 4) {
            work->unk_006 = 0;
            work->unk_188 = TaskCreate(&work->tasks, &gTaskDescBosDsdEnergy1, work->dsd);
            work->dsd->unk_350++;
        }
        break;
    case 4:
        func_080C3504(work);

        if (IsTaskActive(work->unk_188) != 0) {
            break;
        }

        if (work->dsd->unk_35A == 1) {
            work->dsd->unk_350 = 6;
            break;
        }

        work->unk_006++;

        if (work->unk_006 > 4) {
            work->unk_006 = 0;
            work->unk_18C = TaskCreate(&work->tasks, &gTaskDescBosDsdEnergy1, work->dsd);
            work->dsd->unk_350++;
        }
        break;
    case 5:
        func_080C3504(work);

        if (IsTaskActive(work->unk_18C) != 0) {
            break;
        }

        work->dsd->unk_350++;
        break;
    case 6:
        func_080C3504(work);
        func_0801AF08(q);
        work->dsd->unk_350++;
        break;
    default:
        d->unk_350 = 0;
        work->dsd->unk_334 = 0;
        break;
    }
}

void func_080C3754(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* q = &d->body[1];

    switch (d->unk_350) {
    case 0:
        work->dsd->unk_354 = 41;
        work->unk_00A = 41;
        work->dsd->unk_356 = 0;
        work->unk_004 = 30;
        work->unk_054 = 0;
        func_080C211C(work->dsd->unk_354);
        work->unk_006 = 0;
        q->x = 0xE400;
        q->z = -0x5C00;
        work->dsd->unk_350++;
        break;
    case 1:
        if (func_080128EC() != 0) {
            break;
        }

        func_080C29F4(work);
        work->unk_004 = 0;
        work->dsd->unk_350++;
        break;
    case 2:
        func_080C3504(work);
        LoadPalette(gUnk_096FB744, (void*)0x05000000, 32);
        work->unk_06C = TaskCreate(&work->tasks, &gTaskDescBosDsdEnergy2, work->dsd);
        work->dsd->unk_350++;
        break;
    case 3:
        func_080C3504(work);

        if (IsTaskActive(work->unk_06C) != 0) {
            break;
        }

        work->dsd->unk_350++;
        break;
    case 4:
        func_080C3504(work);
        func_0801AF08(q);
        work->dsd->unk_350++;
        break;
    default:
        d->unk_350 = 0;
        work->dsd->unk_334 = 0;
        break;
    }
}

void func_080C3868(DsdMainWork* work) {
}

void func_080C386C(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* a = &d->body[1];
    BtlObj* b = &d->body[2];

    if (d->unk_330 == 2 || d->unk_330 == 3) {
        func_0801AF08(a);
        b->flags |= 0x1000000;
        ColliderSetDisabled(&b->collider, 1);
        work->dsd->unk_350 = 0;
        work->dsd->unk_334 = 0;
    } else if (d->unk_350 > 60) {
        func_0801AF08(a);
        b->flags |= 0x1000000;
        ColliderSetDisabled(&b->collider, 1);
        work->dsd->unk_350 = 0;
        work->dsd->unk_334 = 0;
    } else {
        d->unk_350++;
    }
}

void func_080C3928(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* a = &d->body[1];
    BtlObj* b = &d->body[2];
    BtlObj* c = &work->body;
    BtlObj* e;
    CharaObjParam param;

    switch (d->unk_350) {
    case 0:
        e = ListPoolFirst(&gBtlWork->pool);

        while (e != 0) {
            if (e->unk_000 == 0) {
                e->flags |= 0x40;
                m4aSongNumStart(0x227);
            }

            e = ListPoolNext(&e->node);
        }

        work->dsd->unk_350++;
        break;
    case 1:
        func_0801AF4C(a);
        ColliderSetDisabled(&a->collider, 1);
        ColliderSetDisabled(&b->collider, 1);
        ColliderSetDisabled(&c->collider, 1);
        FadeSetPaletteExcluded(0, 0);
        FadeSetPaletteExcluded(19, 0);
        FadeToAmount(0, 20, 8);
        func_08018B04(a->x - 0x1400, a->y, a->z - 0xA00, 0x100);
        m4aSongNumStart(0x2D1);
        work->unk_006 = 0;
        work->dsd->unk_350++;
        func_0802F274(d->body[0].x - 0x1400, d->body[0].y + d->body[0].z + 0x3000);
        break;
    case 2:
        func_0802F274(d->body[0].x - 0x1400, d->body[0].y + d->body[0].z + 0x3000);
        work->unk_006++;

        if (work->unk_006 > 11) {
            DisableBg(1);
            work->unk_054 = 0;
            work->dsd->unk_350++;
        }
        break;
    case 3:
        func_080C213C(36, 0xE0);
        EnableBg(1);
        func_0802F274(d->body[0].x - 0x1400, d->body[0].y + d->body[0].z + 0x3000);
        work->dsd->unk_350++;
        break;
    case 4:
        func_0802F274(d->body[0].x - 0x1400, d->body[0].y + d->body[0].z + 0x3000);

        if (func_080128EC() != 0) {
            break;
        }

        FadeToOriginal(0, 8);
        FadeSetPaletteExcluded(0, 1);
        FadeSetPaletteExcluded(19, 1);
        work->dsd->unk_350++;
        break;
    case 5:
        func_0802F274(d->body[0].x - 0x1400, d->body[0].y + d->body[0].z + 0x3000);
        work->dsd->unk_350++;
        break;
    case 6:
        func_0802F274(d->body[0].x - 0x1400, d->body[0].y + d->body[0].z + 0x3000);
        param.unk_00 = 0;
        param.unk_04 = 0;
        param.unk_08 = 0;
        param.unk_0C = 0;
        param.unk_10 = 0;
        param.unk_14 = 0;
        param.unk_18 = 0;
        param.unk_1C = 0;
        param.unk_20 = 0x6000000;
        param.unk_24 = 0xE0;
        param.unk_28 = 0x5000000;
        param.unk_2C = 32;
        param.unk_30 = d->body[0].x - 0x1400;
        param.unk_34 = d->body[0].y;
        param.unk_38 = d->body[0].z + 0x3000;
        param.unk_3C = 0;
        param.unk_40 = (u32)a;
        param.unk_44 = 1;
        func_080C6894(&param);
        work->dsd->unk_350++;
        break;
    case 7:
        if (func_080C69B4() == 0) {
            d->body[0].x = 300;
            d->body[0].y = 0;
            d->body[0].z = 0;
            ScrollBgMapTo(1, ((gBtlWork->unk_000 - 300) >> 8) + 100, (gBtlWork->unk_004 >> 8) + 280);
            func_0801B008();
            work->dsd->unk_350++;
        } else {
            func_0802F274(d->body[0].x - 0x1800, d->body[0].y + d->body[0].z + 0x3000);
        }
        break;
    default:
        d->flags |= 2;
        break;
    }
}

void func_080C3C34(DsdMainWork* work) {
    func_080C288C(work);
}

void func_080C3C40(DsdMainWork* work) {
    DsdWork* d = work->dsd;
    BtlObj* a = &d->body[1];

    if (a->unk_02C < a->unk_02E / 3) {
        d->unk_35A = 2;

        if (GetRandom() % 100 <= 9) {
            func_08083900(1);
        } else if (GetRandom() % 90 <= 49) {
            func_08083900(GetRandom() % 2 + 8);
        } else {
            func_08083900(GetRandom() % 3 + 5);
        }
    } else if (a->unk_02C < a->unk_02E / 3 * 2) {
        d->unk_35A = 1;

        if (GetRandom() % 100 <= 29) {
            func_08083900(GetRandom() % 2 + 8);
        } else {
            func_08083900(GetRandom() % 3 + 4);
        }
    } else {
        d->unk_35A = 0;

        if (GetRandom() % 100 <= 59) {
            func_08083900(GetRandom() % 3 + 7);
        } else {
            func_08083900(GetRandom() % 4 + 3);
        }
    }

    switch (work->dsd->unk_33C) {
    case 0:
        work->dsd->unk_338 = 5;
        break;
    case 1:
        work->dsd->unk_338 = 6;
        break;
    case 2:
        work->dsd->unk_338 = 4;
        break;
    case 3:
        work->dsd->unk_338 = 7;
        break;
    default:
        work->dsd->unk_338 = 0;
        break;
    }

    work->dsd->unk_33C++;

    if (work->dsd->unk_33C > 3) {
        work->dsd->unk_33C = 0;
    }

    func_0801BCD4(a);
}

void task_bos_dsd_map_0(void) {
    LoadBgTiles(0, gUnk_096874E4, 0x8000);
    LoadBgPalette(0, gUnk_096FB744, 0x120);
    SetBgMapBlocks(0, gUnk_09EF2E68, 2, 2);
    gBtlWork->unk_024 = 0x100;
    gBtlWork->unk_028 = 0x100;
    gBtlWork->x = 0xA000;
    gBtlWork->y = 0x13600;
    gBtlWork->unk_000 = 0xA000;
    gBtlWork->unk_004 = 0x13600;
    gBtlWork->x2 = 0xA000;
    gBtlWork->y2 = 0x13600;
    gBtlWork->unk_01C = 0xA000;
    gBtlWork->unk_020 = 0x13600;
    gBtlWork->unk_01A = 0xF;
    gBtlWork->unk_018 = 0;
    func_0802F1C8();
    ScrollBgMapTo(0, gBtlWork->unk_000 >> 8, gBtlWork->unk_004 >> 8);
}

u8 task_bos_dsd_map_1(void) {
    s32 dx;
    s32 dy;

    func_0802F208();
    dx = (gBtlWork->x2 - gBtlWork->x) >> 3;
    dy = (gBtlWork->y2 - gBtlWork->y) >> 3;

    if (dx > 0x500) {
        dx = 0x500;
    } else if (dx < -0x500) {
        dx = -0x500;
    }

    gBtlWork->x += dx;
    gBtlWork->y += dy;
    gBtlWork->unk_000 = gBtlWork->x;
    gBtlWork->unk_004 = gBtlWork->y;

    if (gBtlWork->unk_000 < (gBtlWork->unk_0DA + 0x78) << 8) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DA + 0x78) << 8;
    } else if (gBtlWork->unk_000 > (gBtlWork->unk_0DC - 0x78) << 8) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DC - 0x78) << 8;
    }

    if (gBtlWork->unk_004 < 0x5000) {
        gBtlWork->unk_004 = 0x5000;
    } else if (gBtlWork->unk_004 > (gBtlWork->unk_0E0 - 0x50) << 8) {
        gBtlWork->unk_004 = (gBtlWork->unk_0E0 - 0x50) << 8;
    }

    gBtlWork->unk_004 += func_0802F268();
    ScrollBgMapTo(0, (gBtlWork->unk_000 >> 8) - 0x78, (gBtlWork->unk_004 >> 8) - 0x28);

    return 1;
}

void task_bos_dsd_ita_0(DsdItaWork* work, void* arg) {
    work->dsd = arg;
    work->unk_074 = 0x1E;
    work->unk_076 = 0;
    work->unk_078 = 0;
    work->state = 0;
    work->x = 0x12C00;
    work->y = 0x17C00;
    work->z = -0x7800;
    work->vz = 0x100;
    work->unk_070 = 0x19;
    work->flags = 0;
    work->unk_07E = 0;
    work->unk_080 = 0;
    ColliderInit(&work->collider, 7, 0x20, 3);
    ColliderSetPosition(&work->collider, work->x, work->y, work->z);
    work->gfx = (u32)gUnk_09EF3BF8[0];
    work->gfx2 = (u32)gUnk_09EF3C18;
}

u8 task_bos_dsd_ita_1(DsdItaWork* work) {
    BtlObj* a = &work->dsd->body[1];

    func_080C427C(work);

    switch (work->state) {
    case 0:
        if (work->unk_074 > 0) {
            ApproachValue(&work->x, 0x1400, work->unk_074);
            ApproachValue(&work->z, -0x1400, work->unk_074);
            work->unk_074--;
        } else {
            work->state = 1;
        }
        break;
    case 1:
        if (work->dsd->flags & 32) {
            work->state = 2;
        }

        func_080C4398(work);
        break;
    case 2:
        if (work->dsd->flags & 32) {
            func_080C43E4(&work->x, a->x - 12800);
            func_080C43E4(&work->y, a->y);
            func_080C43E4(&work->z, a->z + 0x500);
        } else if (work->unk_078 > 49) {
            work->state = 3;
        } else {
            work->unk_078++;
        }

        func_080C4398(work);
        break;
    case 3:
        if (work->z < 0) {
            work->z += work->vz;
            work->vz += work->unk_070;
        } else {
            work->z = 0;
        }

        if (work->dsd->flags & 32) {
            work->unk_078 = 0;
            work->state = 2;
        }

        func_080C4398(work);
        break;
    case 4:
        if (work->unk_074 > 0) {
            ApproachValue(&work->x, -0x5000, work->unk_074);
            ApproachValue(&work->z, -0x1400, work->unk_074);
            work->unk_074--;
        } else {
            work->state++;
        }
        break;
    default:
        work->dsd->flags &= ~8;
        return 0;
    }

    ColliderSetPosition(&work->collider, work->x, work->y, work->z);

    return 1;
}

void task_bos_dsd_ita_2(DsdItaWork* work) {
    u16 pal;
    u16 prio;
    s32 affine;
    s32 scale;
    s32 flag;
    s16 x;
    s16 y;

    if (work->dsd->flags & 32) {
        pal = 0x800;
        prio = -4100 - ((work->y - 0x4000) >> 8) * 4;
    } else {
        pal = GetBattleSpritePriorityFlags(work->y);
        prio = -4102 - (work->y >> 8) * 4;
    }

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, work->gfx, work->dsd->tiles2, work->dsd->palette2, 0, pal, prio);

    if (work->z >= 0 && gBtlWork->unk_024 == 0x100) {
        affine = 0;
    } else {
        scale = 0x100 - -work->z / 128;

        if (scale <= 0x7F) {
            scale = 0x80;
        }

        flag = 0;

        if (scale > 0x100) {
            flag = 1;
        }

        affine = AllocObjAffine(0, scale, scale, flag);
    }

    WorldToScreen(&x, &y, work->x, work->y, 0);
    DrawSprite(x, y, work->gfx2, work->dsd->tiles2, work->dsd->palette3, affine, 0xC00, 0xFFF0);
}

void task_bos_dsd_ita_3(DsdItaWork* work) {
    ColliderUnregister(&work->collider);
}

void func_080C427C(DsdItaWork* work) {
    s32 v;
    s16 k;

    if (gBtlWork->unk_0F0 == (u32)&work->collider) {
        v = work->dsd->flags & 32;

        if (v == 0) {
            work->flags |= 1;
            work->dsd->flags |= 32;
            work->unk_07E = v;
        }
    } else if (work->dsd->flags & 32) {
        work->dsd->flags &= ~32;
        work->flags |= 2;
        work->unk_07E = 0;
    }

    if (work->flags & 2) {
        k = gUnk_0961A860[work->unk_07E];
        work->unk_080 -= k << 8;

        if (k == 0) {
            work->flags &= 0xFFFD;
            work->unk_080 = 0;
        } else {
            work->unk_07E++;
        }
    } else if (work->flags & 1) {
        k = gUnk_0961A860[work->unk_07E];
        work->unk_080 += k << 8;

        if (k == 0) {
            work->flags &= 0xFFFE;
        } else {
            work->unk_07E++;
        }
    }
}

void func_080C4398(DsdItaWork* work) {
    if ((s16)work->unk_076 >= 600) {
        work->unk_074 = 30;
        work->state = 4;
    } else {
        work->unk_076++;
    }

    if (work->dsd->unk_334 == 11) {
        work->state = 4;
    }
}

void func_080C43E4(s32* p, s32 target) {
    s32 cur;
    s32 delta;

    cur = *p;
    delta = (target - cur) >> 1;

    if (target > cur) {
        if (delta > 0x4FF) {
            delta = 0x500;
        }
    } else if (target < cur) {
        if (delta <= -0x500) {
            delta = -0x500;
        }
    } else {
        return;
    }

    *p = cur + delta;
}

void task_bos_dsd_rock_0(DsdRockWork* work, DsdWork* arg) {
    s32 r;
    u8 ang;

    work->dsd = arg;
    work->unk_20 = GetRandom() % 2;
    work->gfx = gUnk_09EF3BF8[GetRandom() % 3 + 1];

    if (work->dsd->unk_35C > 0) {
        if (work->unk_20 != 0) {
            r = GetRandom() % 0x301 + 0x700;
            ang = GetRandom() % 13 + 58;
            work->x = gBtlWork->unk_000 - 0x8800;
            work->y = (gBtlWork->unk_0E0 - 140) << 8;
        } else {
            r = GetRandom() % 0x201 + 0x400;
            ang = -(GetRandom() % 13 + 58);
            work->x = gBtlWork->unk_000 + 0x8800;
            work->y = (gBtlWork->unk_0DE - 140) << 8;
        }
    } else {
        if (work->unk_20 != 0) {
            r = GetRandom() % 0x301 + 0x700;
            ang = -(GetRandom() % 13 + 58);
            work->x = gBtlWork->unk_000 + 0x8800;
            work->y = (gBtlWork->unk_0E0 - 140) << 8;
        } else {
            r = GetRandom() % 0x201 + 0x400;
            ang = GetRandom() % 13 + 58;
            work->x = gBtlWork->unk_000 - 0x8800;
            work->y = (gBtlWork->unk_0DE - 140) << 8;
        }
    }

    work->z = (GetRandom() % 101) << 8;
    work->vx = gSineTable[ang] * r >> 8;
    work->vz = -gSineTable[ang + 0x40] * r >> 8;
}

u8 task_bos_dsd_rock_1(DsdRockWork* work) {
    if ((work->dsd->flags & 0x40) != 0) {
        work->vx = -work->vx;
        work->vz = -work->vz;
    } else {
        work->x += work->vx;
        work->z += work->vz;
    }

    if (work->x > gBtlWork->unk_000 + 0x8800 || work->x < gBtlWork->unk_000 - 0x8800) {
        return 0;
    }

    return 1;
}
void task_bos_dsd_rock_2(DsdRockWork* work) {
    s32 affine;
    s32 h;
    s32 prio;
    s16 x;
    s16 y;

    if (work->unk_20 != 0) {
        affine = 0;
        h = 10;
        prio = 0x400;
    } else {
        affine = AllocObjAffine(0, 0x59, 0x59, 0);
        h = 0xFFF5;
        prio = 0xC00;
    }

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, work->gfx, work->dsd->tiles2, work->dsd->palette2, affine, prio, h);
}

void task_bos_dsd_rock_3(void) {
}

void task_bos_dsd_circle_0(DsdCircleWork* work, void* arg) {
    work->dsd = arg;
    work->x = (gUnk_0961A89E[0] << 8) + 0xDC00;
    work->y = (gUnk_0961A8B0[0] << 8) + 0x16800;
    work->z = 0;
    work->unk_14 = 0;
    work->unk_16 = 0;
    work->unk_1A = 0;
    work->unk_1C = 0;
    work->unk_18 = 0;
    work->gfx = gUnk_09EF3C50[0];
}

u8 task_bos_dsd_circle_1(DsdCircleWork* work) {
    DsdWork* d = work->dsd;

    if (d->unk_334 == 8 || d->unk_334 == 0) {
        if (work->unk_18 > 66) {
            return 0;
        }

        work->unk_18++;
        return 1;
    }

    switch (d->unk_350) {
    case 1:
        work->unk_1A = work->dsd->unk_354 - 21;
        work->gfx = gUnk_09EF3C50[work->unk_1A];
        work->x = (gUnk_0961A89E[work->unk_1A] << 8) + 0xDC00;
        work->y = (gUnk_0961A8B0[work->unk_1A] << 8) + 0x16800;
        break;
    case 2:
        break;
    case 3:
        work->unk_14++;

        if (work->unk_14 >= gUnk_0961A894[work->unk_16]) {
            work->unk_14 = 0;
            work->unk_16++;

            if (work->unk_16 > 7) {
                work->unk_16 = 0;
            }

            LoadObjPaletteBank(((u16*)work->dsd->palette)[3],
                               &gUnk_096FB904[work->unk_16 * 32]);
        }

        if (work->unk_1C == 60 || work->unk_1C == 110) {
            func_0801BDDC(0, work->x + ((GetRandom() % 101 - 50) << 8),
                          work->y + ((GetRandom() % 17 - 8) << 8), 0);
        }

        work->unk_1C++;
        break;
    case 4:
        LoadObjPaletteBank(((u16*)work->dsd->palette)[3], gUnk_096FB904);
        work->unk_1A = work->dsd->unk_354 - 21;
        break;
    case 5:
        work->unk_1A = work->dsd->unk_354 - 21;
        work->gfx = gUnk_09EF3C50[work->unk_1A];
        work->x = (gUnk_0961A89E[work->unk_1A] << 8) + 0xDC00;
        work->y = (gUnk_0961A8B0[work->unk_1A] << 8) + 0x16800;
        break;
    case 6:
        work->unk_1A = 0;
        work->gfx = gUnk_09EF3C50[work->unk_1A];
        work->x = (gUnk_0961A89E[work->unk_1A] << 8) + 0xDC00;
        work->y = (gUnk_0961A8B0[work->unk_1A] << 8) + 0x16800;
        break;
    case 7:
        return 0;
    }

    if (work->dsd->unk_334 == 11) {
        if (func_080128EC() == 1) {
            BgAnimStop();
        }

        return 0;
    }

    return 1;
}

void task_bos_dsd_circle_2(DsdCircleWork* work) {
    s16 x;
    s16 y;

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, work->gfx, work->dsd->tiles, work->dsd->palette, 0, 0xC00, 0xFFFF);
}

void task_bos_dsd_circle_3(void) {
}

void task_bos_dsd_energy1_0(DsdEnergy1Work* work, void* arg) {
    work->dsd = arg;
    work->x = 0xBC00;
    work->y = 0x16800;
    work->z = -0x2400;
    work->unk_10 = 0;
    work->unk_14 = 0;
    work->unk_18 = 0;
    work->angle = 0xF4;
    work->unk_29 = 0xF4;
    work->unk_2C = 0x800;
    work->unk_30 = 0x19;
    work->state = 0;
    work->unk_36 = 0;
    work->unk_38 = 0;
    work->unk_3C = 0xF;
    work->unk_3A = 0x3C;
    work->unk_48 = 0;
    work->vx = gSineTable[work->angle] * work->unk_2C >> 8;
    work->vy = 0;
    work->vz = -gSineTable[work->angle + 0x40] * work->unk_2C >> 8;
    work->gfx = gUnk_08B22CBC;
}

u8 task_bos_dsd_energy1_1(DsdEnergy1Work* work) {
    switch (work->state) {
    case 0:
        func_08013EDC(work->x, work->y, work->z, 0x100);
        work->state++;
        break;
    case 1:
        if (func_080128EC() != 0) {
            break;
        }

        func_08014588(work->x, work->y, work->z, 0x100, work->unk_3C, 0);
        m4aSongNumStart(0x2BD);
        work->state++;
        break;
    case 2:
        work->unk_38++;

        if (work->unk_38 >= work->unk_3C) {
            work->unk_48 = 1;
            work->unk_38 = 0;
            work->unk_36 = 10;
            work->vy = (gBtlWork->unk_134 - work->y) / 15;
            work->state++;
        }
        break;
    case 3:
        func_080C4C54(work);
        break;
    case 4:
        func_080C4CCC(work);
        break;
    case 5:
        BgFxAddPosition(work->vx, work->vy, work->vz);
        work->x += work->vx;
        work->y += work->vy;
        work->z += work->vz;
        break;
    }

    if (func_08011F78(0x102, work->x, work->y, work->z, 16, 16, 16) == 1) {
        func_08014790(0);
        m4aSongNumStart(0x2A1);
        work->unk_48 = 0;
        return 0;
    }

    if (work->z >= -0x800 || work->x <= -0x2000 || work->x > 0x11FFF ||
        work->dsd->unk_334 == 8 || work->dsd->unk_334 == 11) {
        func_08014790(0);
        work->unk_48 = 0;
        return 0;
    }

    return 1;
}

void task_bos_dsd_energy1_2(DsdEnergy1Work* work) {
    s32 affine;
    s32 scale;
    s32 flag;
    s16 x;
    s16 y;

    if (work->unk_48 == 1) {
        if (work->z >= 0 && gBtlWork->unk_024 == 0x100) {
            affine = 0;
        } else {
            scale = 0x200 - -work->z / 128;

            if (scale <= 0x7F) {
                scale = 0x80;
            }

            flag = 0;

            if (scale > 0x100) {
                flag = 1;
            }

            affine = AllocObjAffine(0, scale, scale, flag);
        }

        WorldToScreen(&x, &y, work->x, work->y, 0);
        DrawSprite(x, y, work->gfx, work->dsd->tiles3, work->dsd->palette4, affine, 0xC00, 0xFFF0);
    }
}

void task_bos_dsd_energy1_3(void) {
}

void func_080C4C54(DsdEnergy1Work* work) {
    work->vx = gSineTable[work->angle] * work->unk_2C >> 8;
    work->vz = -gSineTable[work->angle + 0x40] * work->unk_2C >> 8;
    work->unk_2C -= 76;
    work->angle -= 3;
    work->x += work->vx;
    work->y += work->vy;
    work->z += work->vz;
    BgFxAddPosition(work->vx, work->vy, work->vz);

    if ((s16)work->unk_38 > 15) {
        work->state++;
    } else {
        work->unk_38++;
    }
}

void func_080C4CCC(DsdEnergy1Work* work) {
    u16 d;

    if (work->unk_40 > 0) {
        work->unk_40 = 0;
        work->unk_29 = GetAngle(work->x, work->z, gBtlWork->unk_130, gBtlWork->unk_138);

        if (work->unk_29 >= work->angle) {
            d = work->unk_29 - work->angle;

            if ((s16)d > 10) {
                d = 10;
            }
        } else {
            d = work->unk_29 - work->angle;

            if ((s16)d < -10) {
                d = -10;
            }
        }

        work->angle += d;
        work->vx = gSineTable[work->angle] * work->unk_2C >> 8;
        work->vy = 0;
        work->vz = -gSineTable[work->angle + 0x40] * work->unk_2C >> 8;
    }

    work->unk_40++;
    work->unk_2C += 25;
    BgFxAddPosition(work->vx, work->vy, work->vz);
    work->x += work->vx;
    work->y += work->vy;
    work->z += work->vz;
}

void task_bos_dsd_energy2_0(DsdEnergy2Work* work, void* arg) {
    work->dsd = arg;
    work->x = 0xBC00;
    work->y = 0x16800;
    work->z = -0x2C00;
    work->state = 0;
    work->unk_2E = 0;
    work->unk_30 = 0;
    work->unk_32 = 0xF;
    work->unk_10 = 0x80;
    work->unk_14 = 0x80;
    work->vx = 0;
    work->vy = 0;
    work->vz = -0x500;
    work->unk_34 = 0;
    work->unk_3C = 0;
    work->gfx = gUnk_08B22CBC;
    func_08014588(work->x, work->y, work->z, work->unk_10, work->unk_32, 0);
    m4aSongNumStart(0x2C0);

    switch (work->dsd->unk_35A) {
    case 1:
        work->unk_35 = 5;
        break;
    case 2:
        work->unk_35 = 7;
        break;
    case 0:
    default:
        work->unk_35 = 3;
        break;
    }
}

u8 task_bos_dsd_energy2_1(DsdEnergy2Work* work) {
    BtlObj* p;

    switch (work->state) {
    case 0:
        func_080147C8(work->unk_10, work->unk_14);
        work->unk_10 += 25;
        work->unk_14 += 25;

        if (work->unk_30 >= work->unk_32) {
            func_0802F274(work->x, work->y + work->z);
            work->state++;
        } else {
            work->unk_30++;
        }
        break;
    case 1:
        BgFxAddPosition(work->vx, work->vy, work->vz);
        work->x += work->vx;
        work->y += work->vy;
        work->z += work->vz;
        func_0802F274(work->x, work->y + work->z);

        if (work->z <= -0xF000) {
            work->state++;
        }
        break;
    case 2:
        func_08017F70(work->x, work->y, work->z, 0x103);
        m4aSongNumStart(0x2C1);
        func_0802F274(work->x, work->y + work->z);
        work->state++;
        break;
    case 3:
        func_0802F274(work->x, work->y + work->z);

        if (func_080128EC() == 0) {
            work->state++;
        }
        break;
    case 4:
        FadeToAmount(0, gBtlWork->unk_0B3, 8);
        work->state++;
        break;
    case 5:
        work->x = (p = gBtlWork->actor)->x + (-0x4000 + GetRandom() % 0x8001);

        if (work->x < -0xFFF || work->x > 0x10FFF) {
            work->x = p->x;
        }

        work->y = gBtlWork->actor->y - 0x2400 + GetRandom() % 0x4001;
        work->z = -0xF000;
        work->vz = 0x600;
        func_08014588(work->x, work->y, work->z, 0x100, work->unk_32, 0);
        work->unk_3C = 1;
        work->unk_30 = 0;
        work->state++;
        break;
    case 6:
        BgFxAddPosition(0, 0, work->vz);
        work->z += work->vz;

        if (func_08011F78(0x104, work->x, work->y, work->z, 16, 16, 16) == 1) {
            m4aSongNumStart(0x29E);
            func_08014790(0);
            work->unk_3C = 0;
            work->state = 7;
        }

        if (work->z >= -0x800) {
            func_08014790(0);
            m4aSongNumStart(0x2BF);
            work->unk_3C = 0;
            work->state = 7;
        }

        work->unk_30++;
        break;
    case 7:
        if (work->unk_34 >= (s8)work->unk_35 - 1) {
            if (func_080128EC() == 0) {
                BgAnimStop();
                FadeToOriginal(0, 8);
                work->state++;
            }

            return 1;
        }

        if (work->unk_30 > 49) {
            work->unk_30 = 0;
            work->unk_34++;
            work->state = 5;
        } else {
            work->unk_30++;
        }
        break;
    default:
        return 0;
    }

    if (work->dsd->unk_334 == 8 || work->dsd->unk_334 == 11) {
        if (func_080128EC() == 1) {
            BgAnimStop();
            FadeToOriginal(0, 8);
        }

        work->unk_3C = 0;
        return 0;
    }

    return 1;
}

void task_bos_dsd_energy2_2(DsdEnergy2Work* work) {
    s32 affine;
    s32 scale;
    s32 flag;
    s16 x;
    s16 y;

    if (work->unk_3C == 1) {
        if (work->z >= 0 && gBtlWork->unk_024 == 0x100) {
            affine = 0;
        } else {
            scale = 0x200 - -work->z / 128;

            if (scale <= 0x7F) {
                scale = 0x80;
            }

            flag = 0;

            if (scale > 0x100) {
                flag = 1;
            }

            affine = AllocObjAffine(0, scale, scale, flag);
        }

        WorldToScreen(&x, &y, work->x + 0x100, work->y, 0);
        DrawSprite(x, y, work->gfx, work->dsd->tiles3, work->dsd->palette4, affine, 0xC00, 0xFFF0);
    }
}

void task_bos_dsd_energy2_3(void) {
}

const char gTaskNameBosJf[] = "task_bos_jf";

TaskDesc gTaskDescBosJf = {
    gTaskNameBosJf,
    (void (*)(void*, void*))task_bos_jf_0,
    task_bos_jf_1,
    (void (*)(void*))task_bos_jf_2,
    (void (*)(void*))task_bos_jf_3,
    0x26C,
};

void* gUnk_09EF275C[2][15] = {
    {
        gUnk_096C6C64,
        gUnk_096C6C64 + 14,
        gUnk_096C6C64 + 28,
        gUnk_096C6C64 + 42,
        gUnk_096C7464,
        gUnk_096C7464 + 14,
        gUnk_096C7464 + 28,
        gUnk_096C7464 + 42,
        gUnk_096C7C64,
        gUnk_096C7C64 + 14,
        gUnk_096C7C64 + 28,
        gUnk_096C7C64 + 42,
        gUnk_096C8464,
        gUnk_096C8464 + 14,
        gUnk_096C8464 + 28,
    },
    {
        gUnk_096C8C64,
        gUnk_096C8C64 + 14,
        gUnk_096C8C64 + 28,
        gUnk_096C8C64 + 42,
        gUnk_096C9464,
        gUnk_096C9464 + 14,
        gUnk_096C9464 + 28,
        gUnk_096C9464 + 42,
        gUnk_096C9C64,
        gUnk_096C9C64 + 14,
        gUnk_096C9C64 + 28,
        gUnk_096C9C64 + 42,
        gUnk_096CA464,
        gUnk_096CA464 + 14,
        gUnk_096CA464 + 28,
    },
};

const char gTaskNameBosJfMap[] = "task_bos_jf_map";

TaskDesc gTaskDescBosJfMap = {
    gTaskNameBosJfMap,
    (void (*)(void*, void*))task_bos_jf_map_0,
    task_bos_jf_map_1,
    0,
    0,
    0x4,
};

u8 gUnk_09EF27EC[8] = { 0, 1, 1, 0, 0, 0, 0, 0 };

const char gTaskNameBosJfLamp[] = "task_bos_jf_lamp";

const s16 gUnk_0961A6A8[49] __attribute__((aligned(4))) = {
    9, 9, 8, 8, 8, 8, 8, 8, 30, 6, 6, 12, 6, 6, 2, 8,
    8, 8, 8, 12, 2, 2, 2, 2, 12, 12, 12, 12, 30, 6, 6, 12,
    6, 6, 2, 8, 8, 8, 8, 12, 2, 2, 2, 2, 12, 12, 12, 12,
    0,
};

const s8 gUnk_0961A70A[6] = { 0, -1, -2, -2, -1, 0 };

const u16 gUnk_0961A710[16][3] = {
    { 0, 0, 0 },
    { 7, 7, 7 },
    { 7, 0, 0 },
    { 0, 7, 0 },
    { 0, 0, 7 },
    { 7, 7, 0 },
    { 7, 0, 7 },
    { 0, 7, 7 },
    { 0, 7, 14 },
    { 0, 14, 7 },
    { 7, 0, 14 },
    { 7, 14, 0 },
    { 14, 0, 7 },
    { 14, 7, 0 },
    { 14, 14, 14 },
    { 0, 0, 0 },
};

TaskDesc gTaskDescBosJfLamp = {
    gTaskNameBosJfLamp,
    (void (*)(void*, void*))task_bos_jf_lamp_0,
    task_bos_jf_lamp_1,
    (void (*)(void*))task_bos_jf_lamp_2,
    (void (*)(void*))task_bos_jf_lamp_3,
    0x58,
};

void* gUnk_09EF280C[48] __attribute__((aligned(4))) = {
    gUnk_096D5C64,
    gUnk_096D6464,
    gUnk_096D6C64,
    gUnk_096D7464,
    gUnk_096D7C64,
    gUnk_096D8464,
    gUnk_096D8C64,
    gUnk_096D9464,
    gUnk_096CAC64,
    gUnk_096CB464,
    gUnk_096CBC64,
    gUnk_096CC464,
    gUnk_096CCC64,
    gUnk_096CD464,
    gUnk_096D0C64,
    gUnk_096D1464,
    gUnk_096D1C64,
    gUnk_096D2464,
    gUnk_096D2C64,
    gUnk_096D9C64,
    gUnk_096DA464,
    gUnk_096DAC64,
    gUnk_096DB464,
    gUnk_096DBC64,
    gUnk_096DC464,
    gUnk_096DFC64,
    gUnk_096E0464,
    gUnk_096E0C64,
    gUnk_096CDC64,
    gUnk_096CE464,
    gUnk_096CEC64,
    gUnk_096CF464,
    gUnk_096CFC64,
    gUnk_096D0464,
    gUnk_096D3464,
    gUnk_096D3C64,
    gUnk_096D4464,
    gUnk_096D4C64,
    gUnk_096D5464,
    gUnk_096DCC64,
    gUnk_096DD464,
    gUnk_096DDC64,
    gUnk_096DE464,
    gUnk_096DEC64,
    gUnk_096DF464,
    gUnk_096E1464,
    gUnk_096E1C64,
    gUnk_096E2464,
};

const u16* gUnk_09EF28CC __attribute__((aligned(4))) = gUnk_08125E24;

void* gUnk_09EF28D0[48] __attribute__((aligned(4))) = {
    gUnk_09671DE4,
    gUnk_09672CE4,
    gUnk_09673964,
    gUnk_096748A4,
    gUnk_09675A24,
    gUnk_09676984,
    gUnk_09677604,
    gUnk_096784C4,
    gUnk_09665C04,
    gUnk_09668304,
    gUnk_09669164,
    gUnk_09669F64,
    gUnk_0966ADA4,
    gUnk_0966BB64,
    gUnk_0966C944,
    gUnk_0966DAC4,
    gUnk_0966EBA4,
    gUnk_0966FAE4,
    gUnk_09670C64,
    gUnk_09679584,
    gUnk_0967A764,
    gUnk_0967B924,
    gUnk_0967CA84,
    gUnk_0967DC04,
    gUnk_0967ED84,
    gUnk_0967FF04,
    gUnk_09680E24,
    gUnk_09681C64,
    gUnk_09665C04,
    gUnk_09668304,
    gUnk_09669164,
    gUnk_09669F64,
    gUnk_0966ADA4,
    gUnk_0966BB64,
    gUnk_0966C944,
    gUnk_0966DAC4,
    gUnk_0966EBA4,
    gUnk_0966FAE4,
    gUnk_09670C64,
    gUnk_09679584,
    gUnk_0967A764,
    gUnk_0967B924,
    gUnk_0967CA84,
    gUnk_0967DC04,
    gUnk_0967ED84,
    gUnk_0967FF04,
    gUnk_09680E24,
    gUnk_09681C64,
};

void* gUnk_09EF2990 __attribute__((aligned(4))) = 0;

u32 gUnk_09EF2994[27] __attribute__((aligned(4))) = { 256, 266, 276, 286, 296, 307, 317, 327, 337, 348, 358, 368, 378, 389, 399, 409, 419, 432, 445, 458, 471, 486, 501, 517, 532, 547, 563 };

u32 gUnk_09EF2A00 __attribute__((aligned(4))) = 578;

u32 gUnk_09EF2A04 __attribute__((aligned(4))) = 593;

u32 gUnk_09EF2A08 __attribute__((aligned(4))) = 609;

u32 gUnk_09EF2A0C __attribute__((aligned(4))) = 622;

u32 gUnk_09EF2A10 __attribute__((aligned(4))) = 637;

u32 gUnk_09EF2A14 __attribute__((aligned(4))) = 652;

u32 gUnk_09EF2A18 __attribute__((aligned(4))) = 668;

u32 gUnk_09EF2A1C __attribute__((aligned(4))) = 683;

const char gTaskNameBosJfMajin[] = "task_bos_jf_majin";

const char gTaskNameBosJfRock[] = "task_bos_jf_rock";

const char gTaskNameBosJfBorderline[] = "task_bos_jf_borderline";

const EmyKind gBosDsdEmyKind = { 38, 1000, 16, 16, 40, 60, 0 };

TaskDesc gTaskDescBosJfMajin = {
    gTaskNameBosJfMajin,
    (void (*)(void*, void*))task_bos_jf_majin_0,
    task_bos_jf_majin_1,
    (void (*)(void*))task_bos_jf_majin_2,
    (void (*)(void*))task_bos_jf_majin_3,
    0x84,
};

s8 gUnk_09EF2A38[9] __attribute__((aligned(1))) = { 9, 10, 11, 12, 13, 14, 15, 26, 0 };

s8 gUnk_09EF2A41 __attribute__((aligned(1))) = -1;

s16 gUnk_09EF2A42[12] __attribute__((aligned(2))) = { 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 55 };

const char gTaskNameBosDsd[] = "task_bos_dsd";

const s16 gUnk_0961A7D0[47] __attribute__((aligned(4))) = {
    10, 10, 10, 10, 10, 10, 10, 10, 4, 2, 2, 10, 10, 10, 10, 10,
    10, 10, 10, 10, 10, 4, 4, 4, 4, 4, 4, 4, 10, 10, 10, 10,
    10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0,
};

const s8 gUnk_0961A82E[10] = { -1, 1, 1, 1, 1, -1, -1, -1, 0, 0 };

const char gTaskNameBosDsdMain[] = "task_bos_dsd_main";

const char gTaskNameBosDsdMap[] = "task_bos_dsd_map";

const s16 gUnk_0961A860[6] __attribute__((aligned(4))) = { 3, 2, 1, 1, 0, 0 };

const char gTaskNameBosDsdIta[] = "task_bos_dsd_ita";

const char gTaskNameBosDsdRock[] = "task_bos_dsd_rock";

const s8 gUnk_0961A894[10] __attribute__((aligned(4))) = { 6, 12, 10, 9, 7, 8, 9, 10, 0, 0 };

const s16 gUnk_0961A89E[9] = { -97, -98, -98, -94, -92, -88, -82, 0, 0 };

const s16 gUnk_0961A8B0[10] = { 2, 2, 2, 0, 0, 0, -1, 0, 0, 0 };

const char gTaskNameBosDsdCircle[] = "task_bos_dsd_circle";

const char gTaskNameBosDsdEnergy1[] = "task_bos_dsd_energy1";

const char gTaskNameBosDsdEnergy2[] = "task_bos_dsd_energy2";

TaskDesc gTaskDescBosJfRock = {
    gTaskNameBosJfRock,
    (void (*)(void*, void*))task_bos_jf_rock_0,
    task_bos_jf_rock_1,
    (void (*)(void*))task_bos_jf_rock_2,
    (void (*)(void*))task_bos_jf_rock_3,
    0x198,
};

TaskDesc gTaskDescBosJfBorderline = {
    gTaskNameBosJfBorderline,
    (void (*)(void*, void*))task_bos_jf_borderline_0,
    task_bos_jf_borderline_1,
    (void (*)(void*))task_bos_jf_borderline_2,
    (void (*)(void*))task_bos_jf_borderline_3,
    0xB8,
};

TaskDesc gTaskDescBosDsd = {
    gTaskNameBosDsd,
    (void (*)(void*, void*))task_bos_dsd_0,
    task_bos_dsd_1,
    (void (*)(void*))task_bos_dsd_2,
    (void (*)(void*))task_bos_dsd_3,
    0x394,
};

const u16* gUnk_09EF2AA4[46][4] = {
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E3C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E4464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E4C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E5464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E5C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E5464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E4C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E4464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E7464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E6C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E6464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E6C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E7464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E7C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E8464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E8C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E9464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E9C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E9464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E8C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096E8464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EA464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EAC64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EB464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EBC64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EC464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096ECC64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096ED464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EDC64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EE464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EEC64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EF464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EFC64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EF464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EEC64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096EE464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096F0464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096F0C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096F1464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096F1C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096F2464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096F2C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096F3464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096F3C64, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096F4464, gUnk_08125E24 },
    { gUnk_08125E24, gUnk_08125E24, gUnk_096F4C64, gUnk_08125E24 },
};

const u16* gUnk_09EF2D84 = gUnk_08125E24;

const u16* gUnk_09EF2D88 = gUnk_08125E24;

const u16* gUnk_09EF2D8C = gUnk_08125E24;

const u16* gUnk_09EF2D90 = gUnk_08125E24;

void* gUnk_09EF2D94[37] = {
    gUnk_096874E4,
    gUnk_0968F4E4,
    gUnk_096918A4,
    gUnk_09693C64,
    gUnk_09696024,
    gUnk_09693C64,
    gUnk_096918A4,
    gUnk_0968F4E4,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_0969EF04,
    gUnk_0969FF04,
    gUnk_096A0F04,
    gUnk_096A1F04,
    gUnk_096A0F04,
    gUnk_0969FF04,
    gUnk_0969EF04,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_09699684,
    gUnk_0969EF04,
    gUnk_0969FF04,
    gUnk_096A0F04,
    gUnk_096A1F04,
    gUnk_096A0F04,
    gUnk_0969FF04,
    gUnk_0969EF04,
    gUnk_096A3F44,
};

void* gUnk_09EF2E28 = gUnk_096A3F44;

void* gUnk_09EF2E2C = gUnk_096A3F44;

void* gUnk_09EF2E30 = gUnk_096A3F44;

void* gUnk_09EF2E34 = gUnk_096A3F44;

void* gUnk_09EF2E38 = gUnk_096A8BA4;

void* gUnk_09EF2E3C = gUnk_096A8BA4;

void* gUnk_09EF2E40 = gUnk_096A8BA4;

void* gUnk_09EF2E44 = gUnk_096A8BA4;

void* gUnk_09EF2E48 = gUnk_096A8BA4;

void* gUnk_09EF2E4C = 0;

TaskDesc gTaskDescBosDsdMain = {
    gTaskNameBosDsdMain,
    (void (*)(void*, void*))task_bos_dsd_main_0,
    task_bos_dsd_main_1,
    (void (*)(void*))task_bos_dsd_main_2,
    (void (*)(void*))task_bos_dsd_main_3,
    0x190,
};

const u16* gUnk_09EF2E68[4] = {
#if defined(VERSION_US)
    gBossMapBlockUs_096E2C64,
    gBossMapBlockUs_08125E24,
    gBossMapBlockUs_096E3464,
    gBossMapBlockUs_08125E24,
#elif defined(VERSION_JP)
    gBossMapBlockJp_0969B440,
    gBossMapBlockJp_08125EA0,
    gBossMapBlockJp_0969BC40,
    gBossMapBlockJp_08125EA0,
#elif defined(VERSION_EU)
    gBossMapBlockEu_096AA98C,
    gBossMapBlockEu_08124944,
    gBossMapBlockEu_096AB18C,
    gBossMapBlockEu_08124944,
#endif
};

TaskDesc gTaskDescBosDsdMap = {
    gTaskNameBosDsdMap,
    (void (*)(void*, void*))task_bos_dsd_map_0,
    task_bos_dsd_map_1,
    0,
    0,
    0x4,
};

TaskDesc gTaskDescBosDsdIta = {
    gTaskNameBosDsdIta,
    (void (*)(void*, void*))task_bos_dsd_ita_0,
    task_bos_dsd_ita_1,
    (void (*)(void*))task_bos_dsd_ita_2,
    (void (*)(void*))task_bos_dsd_ita_3,
    0x90,
};

TaskDesc gTaskDescBosDsdRock = {
    gTaskNameBosDsdRock,
    (void (*)(void*, void*))task_bos_dsd_rock_0,
    task_bos_dsd_rock_1,
    (void (*)(void*))task_bos_dsd_rock_2,
    (void (*)(void*))task_bos_dsd_rock_3,
    0x24,
};

TaskDesc gTaskDescBosDsdCircle = {
    gTaskNameBosDsdCircle,
    (void (*)(void*, void*))task_bos_dsd_circle_0,
    task_bos_dsd_circle_1,
    (void (*)(void*))task_bos_dsd_circle_2,
    (void (*)(void*))task_bos_dsd_circle_3,
    0x20,
};

TaskDesc gTaskDescBosDsdEnergy1 = {
    gTaskNameBosDsdEnergy1,
    (void (*)(void*, void*))task_bos_dsd_energy1_0,
    task_bos_dsd_energy1_1,
    (void (*)(void*))task_bos_dsd_energy1_2,
    (void (*)(void*))task_bos_dsd_energy1_3,
    0x4C,
};

TaskDesc gTaskDescBosDsdEnergy2 = {
    gTaskNameBosDsdEnergy2,
    (void (*)(void*, void*))task_bos_dsd_energy2_0,
    task_bos_dsd_energy2_1,
    (void (*)(void*))task_bos_dsd_energy2_2,
    (void (*)(void*))task_bos_dsd_energy2_3,
    0x40,
};
