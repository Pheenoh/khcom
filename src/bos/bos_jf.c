#include "macros.h"
#include "bos2.h"
#include "sprites_bos2.h"

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
    gBtlWork->scale = 0x100;
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
            m4aSongNumStart(SONG_VO_EG_DAMAGE00);
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

TaskDesc gTaskDescBosJf = {
    "task_bos_jf",
    (TaskInitFunc)task_bos_jf_0,
    (TaskUpdateFunc)task_bos_jf_1,
    (TaskFunc)task_bos_jf_2,
    (TaskFunc)task_bos_jf_3,
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

TaskDesc gTaskDescBosJfMap = {
    "task_bos_jf_map",
    (TaskInitFunc)task_bos_jf_map_0,
    (TaskUpdateFunc)task_bos_jf_map_1,
    0,
    0,
    0x4,
};

u8 gUnk_09EF27EC[8] = { 0, 1, 1, 0, 0, 0, 0, 0 };

const char gTaskNameBosJfLamp[] = "task_bos_jf_lamp";

TaskDesc gTaskDescBosJfLamp = {
    gTaskNameBosJfLamp,
    (TaskInitFunc)task_bos_jf_lamp_0,
    (TaskUpdateFunc)task_bos_jf_lamp_1,
    (TaskFunc)task_bos_jf_lamp_2,
    (TaskFunc)task_bos_jf_lamp_3,
    0x58,
};
