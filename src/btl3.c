#include "macros.h"
#include "btl3.h"

void task_btl_form_0(BtlFormWork* work, BtlFormList* list) {
    s32 i;

    gUnk_02039B84->unk_068 |= 0x2000000;
    work->unk_20 = 0;
    work->unk_08 = list;
    work->unk_0C = list->unk_04[0];
    work->unk_00 = work->unk_0C->unk_08;
    work->unk_10 = 1;
    work->unk_02 = 0;
    work->unk_04 = 0;
    work->unk_22 = 0;
    work->unk_24 = 100;
    gUnk_02039B84->unk_120 = 0;

    for (i = 0; i < list->unk_00; i++) {
        gUnk_02039B84->unk_120 += list->unk_04[i]->unk_00;
    }
}

u8 task_btl_form_1(BtlFormWork* work) {
    BtlFormList* list;
    BtlFormStep* step;
    UnkStruct_02039B84* obj;
    s32 x;
    s32 y;
    s32 z;

    if (gUnk_02039B84->unk_068 & 0x0100000000000000) {
        return 0;
    }

    if (work->unk_20 & 2) {
        list = work->unk_08;
        if (list->unk_08 >= work->unk_22 + gUnk_02039B84->unk_0EC) {
            if (work->unk_22 == 0) {
                return 0;
            }
            work->unk_0C = list->unk_04[work->unk_10];
            work->unk_00 = work->unk_0C->unk_08;
            work->unk_02 = 0;
            work->unk_04 = 0;
            work->unk_20 &= ~2;
            work->unk_10++;
            work->unk_24 = 100;
        }
    } else if (work->unk_0C->unk_00 <= work->unk_04) {
        if (work->unk_24-- <= 0) {
            work->unk_20 |= 2;
            if (gUnk_02039BB0.unk_1B8 != 4) {
                gUnk_02039BB0.unk_008 &= ~4;
            }
            if (work->unk_10 >= work->unk_08->unk_00) {
                work->unk_22 = 0;
                return 0;
            }
            work->unk_22 = func_0803FDC8(work->unk_08->unk_04[work->unk_10]);
        }
    } else {
        if (work->unk_00 > 0) {
            work->unk_00--;
        } else {
            if (work->unk_00 == 0) {
                obj = gUnk_02039B84->unk_07C;
                work->unk_14 = (obj->unk_004 + 0x10000) >> 1;
                work->unk_18 = obj->unk_008;
                work->unk_1C = 0;
                if (obj->unk_034 & 4) {
                    if (GetRandom() % 5 != 0) {
                        work->unk_20 |= 1;
                    } else {
                        work->unk_20 &= ~1;
                    }
                } else {
                    if (GetRandom() % 5 == 0) {
                        work->unk_20 |= 1;
                    } else {
                        work->unk_20 &= ~1;
                    }
                }
                work->unk_00 = 0xFFFF;
            }
            step = &work->unk_0C->unk_04[work->unk_04];
            if (work->unk_02 >= step->unk_0A) {
                if (work->unk_20 & 1) {
                    x = work->unk_14 - (step->unk_04 << 8);
                } else {
                    x = work->unk_14 + (step->unk_04 << 8);
                }
                y = work->unk_18 + (step->unk_06 << 8);
                z = work->unk_1C + (step->unk_08 << 8);
                func_0801BDDC(step->unk_00, x, y, z);
                work->unk_04++;
            } else {
                work->unk_02++;
            }
        }
    }

    return 1;
}

void task_btl_form_3(void) {
    gUnk_02039B84->unk_068 &= ~0x2000000;
}

void task_btl_born_0(BtlBornWork* work, BtlBornArgs* args) {
    work->unk_00 = args->unk_04;
    work->unk_0C = args->unk_00;
    work->unk_10 = args->unk_10;
    work->unk_12 = args->unk_12;
}

u8 task_btl_born_1(BtlBornWork* work) {
    if (func_080128EC() == 0) {
        func_0801A8A4(&work->unk_00.unk_00, &work->unk_00.unk_04, -24, -12);

        if (func_08008974(0x22D) == 0) {
            m4aSongNumStart(0x22D);
        }

        if (func_08003A98(work->unk_12) == 0) {
            gUnk_02039B84->unk_120--;
            return 0;
        }

        if (func_08003B24(1) == 0) {
            gUnk_02039B84->unk_120--;
            return 0;
        }

        if (work->unk_10 & 1) {
            func_08013EDC(work->unk_00.unk_00, work->unk_00.unk_04,
                          work->unk_00.unk_08 - 0x1000, 0x200);
        } else {
            func_08013EDC(work->unk_00.unk_00, work->unk_00.unk_04,
                          work->unk_00.unk_08 - 0x800, 0x100);
        }

        TaskCreate(&gUnk_02039B84->unk_02C, work->unk_0C, work);
        return 0;
    }

    return 1;
}

void func_08040150(BtlRaidWork* work, s32* outX, s32* outY, s32* outZ) {
    s16 dx;
    s16 dz;

    switch (func_08005B34(&work->unk_0C)) {
    case 0:
    case 1:
        dx = -15;
        dz = -6;
        break;
    case 2:
    case 3:
        dx = -15;
        dz = 6;
        break;
    case 4:
    case 5:
        dx = 0;
        dz = 8;
        break;
    case 6:
    case 7:
        dx = 15;
        dz = 6;
        break;
    case 8:
    case 9:
        dx = 15;
        dz = -6;
        break;
    case 10:
    case 11:
    default:
        dx = 0;
        dz = -8;
        break;
    }

    if (work->unk_3C == 0) {
        dx = -dx;
    }

    *outX = work->unk_24 + (dx << 8);
    *outY = work->unk_28;
    *outZ = work->unk_2C + (dz << 8);
}

void task_btl_raid_0(BtlRaidWork* work, BtlRaidArgs* args) {
    s32 x;
    s32 y;
    s32 z;

    work->unk_48 = args->unk_1C;

    if (args->unk_12 != 0) {
        work->unk_3C = 1;
    } else {
        work->unk_3C = 0;
    }

    if (args->unk_14 != 0) {
        work->unk_3D = 1;
        work->unk_00 = gUnk_02039B84->unk_114;
        work->unk_5C = gUnk_02039B84->unk_07C;
        work->unk_04 = LoadObjPalette(gUnk_08F683A4, 32);
    } else {
        work->unk_3D = 0;
        work->unk_00 = gUnk_02039B84->unk_114;
        work->unk_5C = gUnk_02039B9C->unk_07C;
        work->unk_04 = LoadObjPalette(gUnk_096FAC64, 32);
    }

    AnimInit(&work->unk_0C, 0, 0);
    func_08005974(&work->unk_0C, 0, 1, gUnk_09EDF154, gUnk_09EDF124);
    func_08002A10(work->unk_00, gUnk_08901C8A);
    work->unk_24 = args->unk_00;
    work->unk_28 = args->unk_04;
    work->unk_2C = args->unk_08;
    work->unk_38 = 100;
    work->unk_40 = 0;
    work->unk_44 = 256;
    work->unk_30 = 0x800;
    work->unk_54 = 10;
    work->unk_56 = 2;
    work->unk_68 = 568;

    switch (work->unk_48) {
    case 0:
        work->unk_4C = 86;
        break;
    case 1:
        work->unk_4C = 100;
        break;
    case 2:
        work->unk_4C = 101;
        func_08040150(work, &x, &y, &z);
        func_08017260(x, y, z, 332);
        work->unk_54 = 16;
        work->unk_68 = 505;
        break;
    case 3:
        work->unk_4C = 102;
        func_08040150(work, &x, &y, &z);
        func_080172F8(x, y, z, 332);
        work->unk_54 = 16;
        work->unk_68 = 509;
        break;
    case 4:
        work->unk_4C = 103;
        work->unk_56 |= 1;
        work->unk_54 = 8;
        break;
    case 5:
        work->unk_4C = 104;
        work->unk_56 |= 1;
        work->unk_54 = 8;
        break;
    case 6:
        work->unk_4C = 105;
        work->unk_40 = 3;
        if (work->unk_3C != 0) {
            work->unk_58 = 192;
        } else {
            work->unk_58 = 64;
        }
        work->unk_38 = 0;
        work->unk_5A = GetRandom() % 5 + 0xFFFE;
        break;
    case 7:
        work->unk_4C = 111;
        work->unk_40 = 4;
        if (work->unk_3C != 0) {
            work->unk_58 = 192;
        } else {
            work->unk_58 = 64;
        }
        work->unk_38 = 0;
        work->unk_3A = 0;
        break;
    }

    work->unk_60 = LoadObjTiles(gUnk_08B22CE4, 0x200);
    work->unk_64 = LoadObjPalette(gUnk_08F69BA4, 32);
    m4aSongNumStart(0x237);
}

UnkStruct_02039B84* func_08040458(BtlRaidWork* work) {
    UnkStruct_02039B84* obj;

    if (gUnk_02039B84->unk_068 & 0x4000) {
        if (work->unk_3D != 0) {
            obj = gUnk_02039B9C->unk_07C;
        } else {
            obj = gUnk_02039B84->unk_07C;
        }

        if (obj->unk_02C <= 0) {
            return 0;
        }

        return obj;
    }

    if (gUnk_02039B84->unk_078 == 0) {
        return func_08000C8C(gUnk_02039B84->unk_080);
    }

    return gUnk_02039B84->unk_078;
}

u8 task_btl_raid_1(BtlRaidWork* work) {
    UnkStruct_02039B84* obj;
    u16 hit;
    s32 x;
    s32 y;
    s32 z;

    if ((work->unk_3D != 0 ? gUnk_02039B84 : gUnk_02039B9C)->unk_068 & 0x40000000) {
        return 0;
    }

    func_0802F284(work->unk_24, work->unk_28, work->unk_2C + 0x1800);

    switch (work->unk_40) {
    case 4:
        work->unk_24 += gSineTable[(u8)work->unk_58] * 5;
        work->unk_2C += -gSineTable[(u8)work->unk_58 + 64] * 5;
        if (work->unk_2C > 0) {
            work->unk_2C = 0;
        }

        obj = func_08040458(work);

        if (obj != 0) {
            if (work->unk_3A <= 0) {
                func_0800589C(&work->unk_58,
                              func_0801CB6C(work->unk_24, work->unk_2C, obj->unk_004,
                                            obj->unk_00C - (obj->unk_0A2 << 8)),
                              2);
            } else {
                work->unk_3A--;
            }

            work->unk_28 += (obj->unk_008 - work->unk_28) >> 3;

            if (func_08011F78(work->unk_4C, work->unk_24, work->unk_28, work->unk_2C, 8, 8, 8) != 0) {
                m4aSongNumStart(work->unk_68);
                if (obj->unk_034 & 2) {
                    work->unk_3A = 20;
                }
            }
        }

        if (obj == 0 || work->unk_38 > 180) {
            work->unk_40 = 5;
            work->unk_38 = 0;
        } else {
            work->unk_38++;
        }
        break;
    case 3:
        work->unk_24 += gSineTable[(u8)work->unk_58] * 8;
        work->unk_28 -= gSineTable[(u8)work->unk_58 + 64] * 4;
        hit = func_0801A8A4(&work->unk_24, &work->unk_28, 0, 0);

        switch (hit) {
        case 1:
            work->unk_58 = GetRandom() % 65 + 32;
            break;
        case 2:
            work->unk_58 = GetRandom() % 65 + 160;
            break;
        case 4:
            work->unk_58 = GetRandom() % 65 + 0xFFE0;
            break;
        case 3:
            work->unk_58 = GetRandom() % 65 + 96;
            break;
        }

        if (func_08011F78(work->unk_4C, work->unk_24, work->unk_28, work->unk_2C, 8, 8, 32) != 0) {
            m4aSongNumStart(work->unk_68);
        }

        if (hit != 0) {
            if (work->unk_38 > 180) {
                work->unk_40 = 5;
                work->unk_38 = 0;
                break;
            }
            work->unk_5A = GetRandom() % 5 + 0xFFFE;
        }

        work->unk_38++;
        break;
    case 5:
        if (work->unk_38 == 0) {
            work->unk_3A = 16;
        }
        func_080058FC(&work->unk_24, work->unk_5C->unk_004, work->unk_3A);
        func_080058FC(&work->unk_28, work->unk_5C->unk_008, work->unk_3A);
        func_080058FC(&work->unk_2C, work->unk_5C->unk_00C - 0x1000, work->unk_3A);
        work->unk_3A--;
        if (work->unk_3A <= 3) {
            return 0;
        }
        work->unk_38++;
        break;
    case 0:
        func_080058FC(&work->unk_30, -0x800, work->unk_38);
        if (work->unk_3C != 0) {
            work->unk_24 = work->unk_24 - work->unk_30;
        } else {
            work->unk_24 = work->unk_24 + work->unk_30;
        }

        if (work->unk_56 & 1) {
            if (func_08011E3C(work->unk_24, work->unk_28, work->unk_2C, work->unk_54, work->unk_54, 32) != 0) {
                work->unk_40 = 2;
                work->unk_38 = 0;
                break;
            }
        } else {
            if (func_08011F78(work->unk_4C, work->unk_24, work->unk_28, work->unk_2C,
                              work->unk_54, work->unk_54, 32) != 0) {
                m4aSongNumStart(work->unk_68);
            }
        }

        if (work->unk_38 <= 0) {
            switch (work->unk_48) {
            case 2:
            case 3:
                func_08006B4C();
                break;
            }
            return 0;
        }

        switch (func_0801A8A4(&work->unk_24, &work->unk_28, -20, 0)) {
        case 1:
        case 2:
            work->unk_40 = 1;
            work->unk_3A = work->unk_38 >> 2;
            work->unk_34 = work->unk_30;
            break;
        }
        work->unk_38--;
        break;
    case 1:
        func_080058FC(&work->unk_30, -work->unk_34, work->unk_3A);
        if (work->unk_3C != 0) {
            work->unk_24 = work->unk_24 - work->unk_30;
        } else {
            work->unk_24 = work->unk_24 + work->unk_30;
        }
        if (func_08011F78(work->unk_4C, work->unk_24, work->unk_28, work->unk_2C,
                          work->unk_54, work->unk_54, 32) != 0) {
            m4aSongNumStart(work->unk_68);
        }
        if (work->unk_3A <= 0) {
            work->unk_38 = 100 - work->unk_38;
            func_08019A30();
            work->unk_40 = 0;
        } else {
            work->unk_3A--;
        }
        break;
    case 2:
        if (work->unk_38 == 0) {
            work->unk_3A = 30;
            switch (work->unk_48) {
            case 4:
                func_080155BC(work->unk_24, work->unk_28, 0, work->unk_4C);
                break;
            case 5:
                func_08014EC0(work->unk_24, work->unk_28, 0, work->unk_4C);
                break;
            }
        }

        if (work->unk_3A > 0) {
            func_080058FC(&work->unk_44, 25, work->unk_3A);
            work->unk_3A--;
            if (work->unk_3A <= 0) {
                work->unk_56 &= ~2;
            }
        }

        if (!(work->unk_56 & 2) && func_080128EC() == 0) {
            return 0;
        }

        work->unk_38++;
        break;
    }

    switch (work->unk_48) {
    case 2:
    case 3:
        func_08040150(work, &x, &y, &z);
        func_08014780(x, y, z);
        break;
    }

    work->unk_08 = AnimUpdate(&work->unk_0C);
    return 1;
}

void task_btl_raid_2(BtlRaidWork* work) {
    s16 sx;
    s16 sy;
    u16 flags;
    s32 affine;
    s32 scale;

    if (work->unk_56 & 2) {
        flags = func_0801AF1C(work->unk_28);
        WorldToScreen(&sx, &sy, work->unk_24, work->unk_28, work->unk_2C);
        scale = gUnk_02039B84->unk_024 * work->unk_44 >> 8;

        if (scale == 256) {
            affine = 0;
            if (work->unk_3C == 0) {
                flags |= 1;
            }
        } else {
            if (work->unk_3C == 0) {
                affine = AllocObjAffine(0, -scale, scale, 1);
            } else {
                affine = AllocObjAffine(0, scale, scale, 1);
            }
        }

        DrawSprite(sx, sy, work->unk_08, work->unk_00, work->unk_04, affine, flags,
                   -4100 - (((work->unk_28 + 0x1000) >> 8) * 4));
        WorldToScreen(&sx, &sy, work->unk_24, work->unk_28, 0);
        DrawSprite(sx, sy, gUnk_08B22CBC, work->unk_60, work->unk_64, 0, flags, 0xFFFE);
    }
}

void task_btl_raid_3(BtlRaidWork* work) {
    ReleaseObjPalette(work->unk_04);
    ReleaseObjTiles(work->unk_60);
    ReleaseObjPalette(work->unk_64);
}

void task_btl_badstatus_0(BtlBadStatusWork* work, UnkStruct_02039B84* obj) {
    work->unk_28 = 0;
    work->unk_24 = obj;
    work->unk_00 = AllocObjTiles(128, 0);
    work->unk_04 = LoadObjPalette(gUnk_08F69BA4, 32);
    work->unk_08 = LoadObjPalette(gUnk_09611AB8, 32);
    work->unk_2C = work->unk_04;
    AnimInit(&work->unk_0C, 0, 0);
    func_08019068(gUnk_0813E8F4, &work->unk_0C, 0, 1, work->unk_00);
}

u8 task_btl_badstatus_1(BtlBadStatusWork* work) {
    UnkStruct_02039B84* obj;
    u32 state;

    obj = work->unk_24;
    state = obj->unk_0E8;

    if (state == 0) {
        return 1;
    }

    if (state != work->unk_28) {
        work->unk_28 = state;

        switch (state) {
        case 2:
            func_08019068(gUnk_0813E8F4, &work->unk_0C, 0, 1, work->unk_00);
            work->unk_2C = work->unk_04;
            break;
        case 5:
            func_08019068(gUnk_0813E8F4, &work->unk_0C, 2, 1, work->unk_00);
            work->unk_2C = work->unk_08;
            break;
        case 3:
            func_08019068(gUnk_0813E8F4, &work->unk_0C, 3, 1, work->unk_00);
            work->unk_2C = work->unk_04;
            break;
        case 4:
            func_08019068(gUnk_0813E8F4, &work->unk_0C, 4, 1, work->unk_00);
            work->unk_2C = work->unk_08;
            break;
        case 1:
        default:
            func_08019068(gUnk_0813E8F4, &work->unk_0C, 1, 1, work->unk_00);
            work->unk_2C = work->unk_04;
            break;
        }
    }

    obj->unk_0EC--;

    if (obj->unk_0EC <= 0) {
        obj->unk_0E8 = 0;
        work->unk_28 = 0;
    }

    return 1;
}

void task_btl_badstatus_2(BtlBadStatusWork* work) {
    UnkStruct_02039B84* obj;
    void* gfx;
    u16 flags;
    s16 sx;
    s16 sy;

    obj = work->unk_24;

    if (obj->unk_0E8 != 0) {
        flags = func_0801AF1C(obj->unk_008);

        if (gUnk_02039B84->unk_070 != 0) {
            gfx = AnimGetGfx(&work->unk_0C);
        } else {
            gfx = AnimUpdate(&work->unk_0C);
        }

        WorldToScreen(&sx, &sy, obj->unk_004, obj->unk_008,
                      obj->unk_00C - ((obj->unk_09C + 8) << 8));
        DrawSprite(sx, sy, gfx, work->unk_00, work->unk_2C, 0, flags,
                   -4101 - ((obj->unk_008 >> 8) * 4));
    }
}

void task_btl_badstatus_3(BtlBadStatusWork* work) {
    ReleaseObjTiles(work->unk_00);
    ReleaseObjPalette(work->unk_04);
    ReleaseObjPalette(work->unk_08);
}

UnkStruct_02039B84* func_08040C8C(BtlAiWork* work) {
    UnkStruct_02039B84* list[10];
    UnkStruct_02039B84* p;
    s16 count;

    if (gUnk_02039B84->unk_068 & 0x4000) {
        if (work->unk_163 != 0) {
            p = gUnk_02039B9C->unk_07C;
        } else {
            p = gUnk_02039B84->unk_07C;
        }

        if (p->unk_02C <= 0) {
            return 0;
        }

        return p;
    }

    count = 0;
    p = func_08000C8C(gUnk_02039B84->unk_080);

    while (p != 0) {
        if (!(p->unk_034 & 0x01000000)) {
            list[count] = p;
            count++;
            if (count > 9) {
                break;
            }
        }
        p = func_08000CD4(&p->unk_0B8);
    }

    if (count == 0) {
        return 0;
    }

    p = list[work->unk_16C % count];
    work->unk_16C++;
    return p;
}

UnkStruct_02039B84* func_08040D54(BtlAiWork* work) {
    UnkStruct_02039B84* list[10];
    UnkStruct_02039B84* p;
    s16 count;
    s32 d;

    if (gUnk_02039B84->unk_068 & 0x4000) {
        if (work->unk_163 != 0) {
            p = gUnk_02039B9C->unk_07C;
        } else {
            p = gUnk_02039B84->unk_07C;
        }

        if (p->unk_02C <= 0) {
            return 0;
        }

        return p;
    }

    count = 0;
    p = func_08000C8C(gUnk_02039B84->unk_080);

    while (p != 0) {
        if (!(p->unk_034 & 0x01000000)) {
            d = work->unk_044 - p->unk_00C;
            if (d >= 0 ? d <= 0x3000 : p->unk_00C - work->unk_044 <= 0x3000) {
                list[count] = p;
                count++;
                if (count > 9) {
                    break;
                }
            }
        }
        p = func_08000CD4(&p->unk_0B8);
    }

    if (count == 0) {
        return 0;
    }

    p = list[GetRandom() % count];
    return p;
}

ALIGN_ZERO(2);
