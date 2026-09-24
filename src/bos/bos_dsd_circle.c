#include "bos2.h"
#include "sprites_bos2.h"
#include "sprites_btl.h"

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
        m4aSongNumStart(SONG_SND_701);
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
        m4aSongNumStart(SONG_EF_RAC_BEEMENTRY);
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
        if (work->z >= 0 && gBtlWork->scale == 0x100) {
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
    m4aSongNumStart(SONG_SND_704);

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
        m4aSongNumStart(SONG_SND_705);
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
        FadeToAmount(0, gBtlWork->fadeAmount, 8);
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
            m4aSongNumStart(SONG_BTL_RK_LIMITENTRY);
            func_08014790(0);
            work->unk_3C = 0;
            work->state = 7;
        }

        if (work->z >= -0x800) {
            func_08014790(0);
            m4aSongNumStart(SONG_SND_703);
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
        if (work->z >= 0 && gBtlWork->scale == 0x100) {
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

const s8 gUnk_0961A894[10] = { 6, 12, 10, 9, 7, 8, 9, 10, 0, 0 };

const s16 gUnk_0961A89E[9] = { -97, -98, -98, -94, -92, -88, -82, 0, 0 };

const s16 gUnk_0961A8B0[10] = { 2, 2, 2, 0, 0, 0, -1, 0, 0, 0 };

TaskDesc gTaskDescBosDsdCircle = {
    "task_bos_dsd_circle",
    (TaskInitFunc)task_bos_dsd_circle_0,
    (TaskUpdateFunc)task_bos_dsd_circle_1,
    (TaskFunc)task_bos_dsd_circle_2,
    (TaskFunc)task_bos_dsd_circle_3,
    0x20,
};

TaskDesc gTaskDescBosDsdEnergy1 = {
    "task_bos_dsd_energy1",
    (TaskInitFunc)task_bos_dsd_energy1_0,
    (TaskUpdateFunc)task_bos_dsd_energy1_1,
    (TaskFunc)task_bos_dsd_energy1_2,
    (TaskFunc)task_bos_dsd_energy1_3,
    0x4C,
};

TaskDesc gTaskDescBosDsdEnergy2 = {
    "task_bos_dsd_energy2",
    (TaskInitFunc)task_bos_dsd_energy2_0,
    (TaskUpdateFunc)task_bos_dsd_energy2_1,
    (TaskFunc)task_bos_dsd_energy2_2,
    (TaskFunc)task_bos_dsd_energy2_3,
    0x40,
};
