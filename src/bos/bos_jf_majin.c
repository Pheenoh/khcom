#include "macros.h"
#include "bos2.h"
#include "sprites_bos2.h"

void* gUnk_0203B4F0[4] EWRAM_COMMON(16);
void* gUnk_0203B500 EWRAM_COMMON(4);
u8 gUnk_0203B504[12] EWRAM_COMMON(4);
u8 gUnk_0203B510[0x800] EWRAM_COMMON(16);

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
                m4aSongNumStart(SONG_BTL_JF_UP);
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
            m4aSongNumStart(SONG_BTL_LB_RUMB);
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

            m4aSongNumStart(SONG_EF_JF_BEEM);
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

            m4aSongNumStart(SONG_EF_JF_BEEM);
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

        FadeToAmount(0, gBtlWork->fadeAmount, 8);
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
            m4aSongNumStart(SONG_BTL_IRON_GIMICBREAK);
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
            m4aSongNumStart(SONG_EF_FIRE01);
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
            m4aSongNumStart(SONG_BTL_JF_BALLTHR);
            work->unk_194 = 1;
            work->state++;
        }

        if (work->jf->unk_238 == 7 || work->jf->unk_238 == 11) {
            m4aSongNumStart(SONG_EF_FIRE01);
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
            m4aSongNumStart(SONG_EF_JF_BALLHIT);
            func_08014020(work->x - 0x800, work->y + work->z - 0x2400, 0);
            work->unk_194 = 0;
            work->state = 3;
        }

        if (work->jf->unk_238 == 7 || work->jf->unk_238 == 11) {
            m4aSongNumStart(SONG_EF_FIRE01);
            work->unk_17C = 0;
            work->unk_194 = 0;
            work->unk_15C = 0;
            work->state = 5;
        }

        switch ((s8)func_080C1370(work->x, work->y, work->z - 0x2000)) {
        case 1:
            m4aSongNumStart(SONG_EF_FIRE01);
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

const s16 gUnk_0961A6A8[49] = {
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
    (TaskInitFunc)task_bos_jf_majin_0,
    (TaskUpdateFunc)task_bos_jf_majin_1,
    (TaskFunc)task_bos_jf_majin_2,
    (TaskFunc)task_bos_jf_majin_3,
    0x84,
};

s8 gUnk_09EF2A38[9] __attribute__((aligned(1))) = { 9, 10, 11, 12, 13, 14, 15, 26, 0 };

s8 gUnk_09EF2A41 __attribute__((aligned(1))) = -1;

s16 gUnk_09EF2A42[12] __attribute__((aligned(2))) = { 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 55 };

const char gTaskNameBosDsd[] = "task_bos_dsd";

TaskDesc gTaskDescBosJfRock = {
    gTaskNameBosJfRock,
    (TaskInitFunc)task_bos_jf_rock_0,
    (TaskUpdateFunc)task_bos_jf_rock_1,
    (TaskFunc)task_bos_jf_rock_2,
    (TaskFunc)task_bos_jf_rock_3,
    0x198,
};

TaskDesc gTaskDescBosJfBorderline = {
    gTaskNameBosJfBorderline,
    (TaskInitFunc)task_bos_jf_borderline_0,
    (TaskUpdateFunc)task_bos_jf_borderline_1,
    (TaskFunc)task_bos_jf_borderline_2,
    (TaskFunc)task_bos_jf_borderline_3,
    0xB8,
};

TaskDesc gTaskDescBosDsd = {
    gTaskNameBosDsd,
    (TaskInitFunc)task_bos_dsd_0,
    (TaskUpdateFunc)task_bos_dsd_1,
    (TaskFunc)task_bos_dsd_2,
    (TaskFunc)task_bos_dsd_3,
    0x394,
};
