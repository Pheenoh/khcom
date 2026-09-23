#include "registration_data.h"
#include "system_state.h"
#include "mode.h"
#include "bos7.h"
#include "bos7_api.h"
#include "sprites_bos7.h"

const s8* gUnk_09EF9E6C[2] = { gUnk_09A4FBF4, gUnk_09A4FC15 };

const char gTaskNameBosLstFld[] = "task_bos_lst_fld";

TaskDesc gTaskDescBosLstFld = {
    gTaskNameBosLstFld,
    (void (*)(void*, void*))task_bos_lst_fld_0,
    task_bos_lst_fld_1,
    (void (*)(void*))task_bos_lst_fld_2,
    (void (*)(void*))task_bos_lst_fld_3,
    0x1304,
};

const char gTaskNameBosLstEdg[] = "task_bos_lst_edg";

const EmyKind gUnk_09A4FD4C = { 0, 1, 8, 8, 0, 128, 0 };

const s32 gUnk_09A4FD5C[32] = {
    6, 12, 18, 25, 31, 37, 44, 50, 57, 64, 70, 77, 84, 91, 98, 106,
    113, 121, 128, 136, 145, 153, 162, 171, 180, 189, 199, 210, 220, 232, 243, 256,
};

const s32 gUnk_09A4FDDC[3] = { 0, -8, 8 };

const s32 gUnk_09A4FDE8[16] = { -1, -2, -3, -4, -5, -6, -7, -8, -7, -6, -5, -4, -3, -2, -1, 0 };

TaskDesc gTaskDescBosLstEdg = {
    gTaskNameBosLstEdg,
    (void (*)(void*, void*))task_bos_lst_edg_0,
    task_bos_lst_edg_1,
    (void (*)(void*))task_bos_lst_edg_2,
    (void (*)(void*))task_bos_lst_edg_3,
    0x4C,
};

LstAnimSet gUnk_09EF9EA4[4] = {
    { 5, 0, 4, 5 },
    { 5, 0, 4, 12 },
    { 5, 0, 4, 13 },
    { 5, 0, 4, 14 },
};

const char gTaskNameBosLstBit[] = "task_bos_lst_bit";

TaskDesc gTaskDescBosLstBit = {
    gTaskNameBosLstBit,
    (void (*)(void*, void*))task_bos_lst_bit_0,
    task_bos_lst_bit_1,
    (void (*)(void*))task_bos_lst_bit_2,
    (void (*)(void*))task_bos_lst_bit_3,
    0x1D0,
};

const char gTaskNameBosLstLsr[] = "task_bos_lst_lsr";

TaskDesc gTaskDescBosLstLsr = {
    gTaskNameBosLstLsr,
    (void (*)(void*, void*))task_bos_lst_lsr_0,
    task_bos_lst_lsr_1,
    (void (*)(void*))task_bos_lst_lsr_2,
    (void (*)(void*))task_bos_lst_lsr_3,
    0x5C,
};

const char gTaskNameBosLstPtl[] = "task_bos_lst_ptl";

const LstFalAnim gUnk_09A4FE64[8] = { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 } };

TaskDesc gTaskDescBosLstPtl = {
    gTaskNameBosLstPtl,
    (void (*)(void*, void*))task_bos_lst_ptl_0,
    task_bos_lst_ptl_1,
    (void (*)(void*))task_bos_lst_ptl_2,
    (void (*)(void*))task_bos_lst_ptl_3,
    0x38,
};

const char gTaskNameBosLstFal[] = "task_bos_lst_fal";

const EmyKind gUnk_09A4FE98 = { 0, 1, 8, 8, 0, 128, 0 };

const u32 gUnk_09A4FEA8[6][5] = {
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 128, 0, 0, 0 },
    { 0, 86, 171, 0, 0 },
    { 0, 64, 128, 192, 0 },
    { 0, 51, 102, 153, 204 },
};

TaskDesc gTaskDescBosLstFal = {
    gTaskNameBosLstFal,
    (void (*)(void*, void*))task_bos_lst_fal_0,
    task_bos_lst_fal_1,
    (void (*)(void*))task_bos_lst_fal_2,
    (void (*)(void*))task_bos_lst_fal_3,
    0x40,
};

const char gTaskNameBosLstCtr[] = "task_bos_lst_ctr";

TaskDesc gTaskDescBosLstCtr = {
    gTaskNameBosLstCtr,
    (void (*)(void*, void*))task_bos_lst_ctr_0,
    task_bos_lst_ctr_1,
    (void (*)(void*))task_bos_lst_ctr_2,
    (void (*)(void*))task_bos_lst_ctr_3,
    0x188,
};

const char gTaskNameBosLstSnp[] = "task_bos_lst_snp";

TaskDesc gTaskDescBosLstSnp = {
    gTaskNameBosLstSnp,
    (void (*)(void*, void*))task_bos_lst_snp_0,
    task_bos_lst_snp_1,
    (void (*)(void*))task_bos_lst_snp_2,
    (void (*)(void*))task_bos_lst_snp_3,
    0x38,
};

u8 gUnk_02036014;
s16 gUnk_02036016;
s16 gUnk_02036018;
s32 gUnk_0203601C;

void func_0810FE94(void) {
    gUnk_02036014 = 0;
    gUnk_02036016 = 0;
    gUnk_02036018 = 0;
    gUnk_0203601C = 0;
}

void func_0810FEBC(s16 a) {
    gUnk_02036016 = a;
    gUnk_02036018 = 0;
    gUnk_0203601C = 0;
}

void func_0810FEDC(void) {
    const s8* p;

    if (gUnk_02036014 != 0) {
        p = gUnk_09EF9E6C[gUnk_02036016];
        gUnk_0203601C += ((p[gUnk_02036018] << 12) - gUnk_0203601C) >> 3;
        gUnk_02036018++;
        if (p[gUnk_02036018] == 0) {
            gUnk_02036014 = 0;
            gUnk_0203601C = 0;
        }
    }
}

s32 func_0810FF44(void) {
    return gUnk_0203601C;
}

void func_0810FF50(Task* t, s32 a, s32 b) {
    LstFldWork* w = t->work;

    if (a != w->unk_010) {
        w->unk_010 = a;
        w->unk_008 = 0;
        w->unk_014 = b;
    }
}

void func_0810FF64(Task* t, s32 a) {
    LstFldWork* w = t->work;

    w->unk_000 = a;
}

void func_0810FF6C(Task* t, s32 a) {
    LstFldWork* w = t->work;

    w->unk_01C = ((a >> 8) * 5 >> 2) + 2;
}

void task_bos_lst_fld_0(LstFldWork* work, LstFldArg* arg) {
    vu32* dma;
    s32 i;

    LoadBgTiles(0, arg->tiles, arg->tilesSize);
    LoadBgPalette(0, arg->palette, arg->paletteSize);
    gBtlWork->unk_024 = 0x100;
    gBtlWork->unk_028 = 0x100;
    gBtlWork->x = 0xF800;
    gBtlWork->y = 0x1F000;
    gBtlWork->unk_000 = 0xF800;
    gBtlWork->unk_004 = 0x1F000;
    gBtlWork->x2 = 0xF800;
    gBtlWork->y2 = 0x1F000;
    gBtlWork->unk_01C = 0xF800;
    gBtlWork->unk_020 = 0x1F000;
    gBtlWork->unk_01A = 15;
    gBtlWork->unk_018 = 0;
    func_0802F1C8();
    func_0810FE94();
    dma = (vu32*)0x040000D4;
    dma[0] = (vu32)gUnk_09A4D234;
    dma[1] = (vu32)work->unk_0C4;
    dma[2] = 0x80000340;
    dma[2];
    dma[0] = (vu32)gUnk_09A4F2B4;
    dma[1] = (vu32)work->unk_744;
    dma[2] = 0x800004A0;
    dma[2];

    for (i = 0; i < 0x1A0; i++) {
        work->unk_0C4[i] = (gSineTable[(i + 64) & 255] >> 1) & 0x1FF;
    }

    work->unk_000 = 0;
    work->unk_01C = 0;
    work->unk_004 = 0;
    work->unk_008 = 0;
    work->unk_00C = 0;
    work->unk_018 = 0;
    work->unk_020 = 0;
    work->unk_022 = 0;
    work->unk_010 = 0;
    work->unk_014 = 0;
}

void func_08110058(u16* dst, u16* src, s32 count, s32 level) {
    s32 c;
    s32 m;
    s32 v;

    level = level <= 31 ? 31 & ~level : 0;
    count--;

    while (count != -1) {
        v = src[count];
        m = 0x1F;
        c = (v & m) * level >> 5 & m;
        m <<= 5;
        c |= (v & m) * level >> 5 & m;
        m <<= 5;
        c |= (v & m) * level >> 5 & m;
        dst[count] = c;
        count--;
    }
}

u8 task_bos_lst_fld_1(LstFldWork* work) {
    s32 a;
    s32 b;
    s32 i;

    func_0802F208();

    switch (work->unk_000) {
    case 1:
        a = ((gBtlWork->unk_0CC >> 8) - gBtlWork->x) >> 3;
        b = (gBtlWork->unk_0D0 + gBtlWork->unk_0D4 - gBtlWork->y) >> 3;
        break;
    case 2:
        a = (gBtlWork->x2 - gBtlWork->x) >> 3;
        b = (gBtlWork->actor->y + gBtlWork->actor->z -
              gBtlWork->y) >> 3;
        if (b > 256) {
            b = 256;
        }
        if (b < -256) {
            b = -256;
        }
        break;
    default:
        a = (gBtlWork->x2 - gBtlWork->x) >> 3;

        if (gBtlWork->unk_068 & 0x2000000000000) {
            b = (gBtlWork->y2 - gBtlWork->y) >> 3;
        } else if (gBtlWork->unk_068 & 0x200000) {
            if (gBtlWork->actor->z < -0xA000) {
                b = (gBtlWork->actor->y + gBtlWork->actor->z -
                      gBtlWork->y) >> 3;
            } else {
                b = 0;
            }
        } else {
            b = (gBtlWork->actor->y + gBtlWork->actor->z -
                  gBtlWork->y) >> 3;
        }
        break;
    }

    if (a > 0x500) {
        a += 0x500;
    } else if (a < -0x500) {
        a += -0x500;
    }

    gBtlWork->x += a;
    gBtlWork->y += b;
    gBtlWork->unk_000 = gBtlWork->x;
    gBtlWork->unk_004 = gBtlWork->y;
    func_0810FEDC();

    if (gBtlWork->unk_000 < (gBtlWork->unk_0DA + 120) << 8) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DA + 120) << 8;
    } else if (gBtlWork->unk_000 > (gBtlWork->unk_0DC - 120) << 8) {
        gBtlWork->unk_000 = (gBtlWork->unk_0DC - 120) << 8;
    }

    if (gBtlWork->unk_004 + 0x5000 > gBtlWork->unk_0E0 << 8) {
        gBtlWork->unk_004 = (gBtlWork->unk_0E0 - 80) << 8;
    }

    work->unk_018++;
    ScanlineDmaDisable();

    switch (work->unk_004) {
    case 0:
        work->unk_020 -= work->unk_00C * 4;

        for (i = 0; i <= 23; i++) {
            work->unk_1084[work->unk_018 & 1][i] = ((u32)work->unk_020 * 3 / 4) & 0x1FF;
        }
        for (; i <= 31; i++) {
            work->unk_1084[work->unk_018 & 1][i] = (work->unk_020 * 47 >> 6) & 0x1FF;
        }
        for (; i <= 39; i++) {
            work->unk_1084[work->unk_018 & 1][i] = (work->unk_020 * 46 >> 6) & 0x1FF;
        }
        for (; i <= 47; i++) {
            work->unk_1084[work->unk_018 & 1][i] = (work->unk_020 * 44 >> 6) & 0x1FF;
        }
        for (; i <= 55; i++) {
            work->unk_1084[work->unk_018 & 1][i] = (work->unk_020 * 42 >> 6) & 0x1FF;
        }
        for (; i <= 63; i++) {
            work->unk_1084[work->unk_018 & 1][i] = ((u32)work->unk_020 * 5 / 8) & 0x1FF;
        }
        for (; i <= 71; i++) {
            work->unk_1084[work->unk_018 & 1][i] = (work->unk_020 * 38 >> 6) & 0x1FF;
        }
        for (; i <= 79; i++) {
            work->unk_1084[work->unk_018 & 1][i] = ((u32)work->unk_020 * 9 / 16) & 0x1FF;
        }
        for (; i <= 159; i++) {
            work->unk_1084[work->unk_018 & 1][i] = work->unk_020 & 0x1FF;
        }

        ScanlineDmaQueueBuffer(work->unk_1084[work->unk_018 & 1]);
        ScanlineDmaEnable();
        break;
    case 1:
        work->unk_022 -= work->unk_00C * 4;
        ScanlineDmaQueueBuffer(&work->unk_744[work->unk_018 & 0x3FF]);
        ScanlineDmaEnable();
        break;
    case 3:
        work->unk_020 -= work->unk_01C * work->unk_00C;
        ScanlineDmaQueueBuffer(&work->unk_0C4[(u8)work->unk_018]);
        ScanlineDmaEnable();
        break;
    case 2:
        work->unk_020 -= work->unk_00C * 3;
        work->unk_022 += 3;

        for (i = 0; i <= 127; i++) {
            work->unk_1084[work->unk_018 & 1][i] = work->unk_022 & 0x1FF;
        }
        for (; i <= 159; i++) {
            a = ~(i * 2 - 256);
            work->unk_1084[work->unk_018 & 1][i] = (work->unk_022 + a) & 0x1FF;
        }

        ScanlineDmaQueueBuffer(work->unk_1084[work->unk_018 & 1]);
        ScanlineDmaEnable();
        break;
    }

    SetBgScroll(0, work->unk_020, work->unk_022);

    if (work->unk_008 == 31) {
        work->unk_004 = work->unk_010;
        work->unk_00C = work->unk_014;
        work->unk_020 = 0;
        work->unk_022 = 0;

        switch (work->unk_010) {
        case 0:
            LoadBgMap(0, gUnk_09D4B274, 0x800);
            ScanlineDmaInit(0x04000010, work->unk_1084[work->unk_018 & 1], 0xA2600001);
            break;
        case 1:
            LoadBgMap(0, gUnk_09D4BA74, 0x800);
            ScanlineDmaInit(0x04000010, work->unk_744, 0xA2600001);
            break;
        case 2:
            work->unk_020 = -(work->unk_014 * 120);

            if (work->unk_014 > 0) {
                LoadBgMap(0, gUnk_09D4C274, 0x800);
            } else {
                LoadBgMap(0, gUnk_09D4CA74, 0x800);
            }

            ScanlineDmaInit(0x04000012, work->unk_1084[work->unk_018 & 1], 0xA2600001);
            break;
        case 3:
            work->unk_01C = 0;
            LoadBgMap(0, gUnk_09D4C274, 0x800);
            ScanlineDmaInit(0x04000012, work->unk_0C4, 0xA2600001);
            break;
        default:
            LoadBgMap(0, gUnk_09D4D274, 0x800);
            break;
        }
    }

    if (work->unk_008 <= 63) {
        func_08110058(work->unk_024, gUnk_09D694F4, 80, gUnk_09A4FC20[work->unk_008]);
        LoadPalette(work->unk_024, 0x050000A0, 160);
        work->unk_008++;
    }

    return 1;
}

void task_bos_lst_fld_2(void) {
}

void task_bos_lst_fld_3(LstFldWork* work) {
    ScanlineDmaReset();
}

s32 func_08110658(s32 x) {
    return x * x;
}

s32 func_08110660(s32 x) {
    return x * x;
}

u8 func_08110668(LstWork* work) {
    LstState* s;

    s = work->state;
    return s->unk_000 != 4;
}

void task_bos_lst_edg_0(LstEdgWork* work, LstEdgArg* arg) {
    work->state = 0;
    work->unk_002 = 0;
    work->timer = 0;
    work->unk_006 = arg->unk_00;
    work->x = arg->x;
    work->y = arg->y;
    work->z = arg->z;
    work->unk_014 = arg->x;
    work->unk_018 = arg->y;
    work->unk_01C = arg->z;
    work->tiles = (u32)AllocObjTiles(0x80, gUnk_09C5C4E2);
    work->palette = (u32)LoadObjPalette(gUnk_09D69594, 0x60);
    AnimInit(&work->anim, gUnk_09EFAF1C, gUnk_09EFAEF8);
    AnimStart(&work->anim, 0, 1);
}

u8 task_bos_lst_edg_1(LstEdgWork* work) {
    BtlObj* p;

    switch (work->state) {
    case 0:
        work->unk_006--;
        if (work->unk_006 <= 0) {
            work->state = 1;
            work->unk_002 = 0;
            work->timer = 0;
            work->unk_006 = 0;
            p = gBtlWork->actor;
            work->unk_020 = p->x;
            work->unk_024 = p->y;
            work->unk_028 = -0x1000;
        }
        break;
    case 1:
        work->unk_020 = gBtlWork->actor->x;
        ApproachValueHalfSteps(&work->x, work->unk_020, 30);
        ApproachValueHalfSteps(&work->y, work->unk_024, 30);
        ApproachValueHalfSteps(&work->z, work->unk_028, 30);
        work->timer++;
        if (work->timer > 49) {
            work->state = 2;
            work->unk_002 = 0;
            work->timer = 0;
            work->unk_006 = 0;
        }
        func_08011F78(0x10C, work->x, work->y, work->z, 8, 8, 1);
        break;
    case 2:
        ApproachValueHalfSteps(&work->x, work->unk_014, 30);
        ApproachValueHalfSteps(&work->y, work->unk_018, 30);
        ApproachValueHalfSteps(&work->z, work->unk_01C, 30);
        work->timer++;
        if (work->timer > 49) {
            work->state = 3;
            work->unk_002 = 0;
            work->timer = 0;
            work->unk_006 = 0;
        }
        func_08011F78(0x10C, work->x, work->y, work->z, 8, 8, 1);
        break;
    case 3:
        work->state = 4;
        work->unk_002 = 0;
        work->timer = 0;
        work->unk_006 = 0;
        break;
    case 4:
        AnimStart(&work->anim, 1, 1);
        break;
    }

    AnimUpdate(&work->anim);

    return 1;
}

void task_bos_lst_edg_2(LstEdgWork* work) {
    s16 x;
    s16 y;
    u16 prio;
    u16 z;
    void* gfx;

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    prio = GetBattleSpritePriorityFlags(work->y);
    z = -0x1004 - (work->y >> 8) * 4;
    gfx = AnimGetGfx(&work->anim);
    DrawSprite(x, y, gfx, (void*)work->tiles, (void*)work->palette, 0, prio, z);
}

void task_bos_lst_edg_3(LstEdgWork* work) {
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
}

s32 func_0811089C(s32 x) {
    return x * x;
}

s32 func_081108A4(s32 x) {
    return x * x;
}

u8 func_081108AC(LstState* work, s32 kind) {
    LstFalArg arg;
    u8 result;

    result = 0;

    if (work->unk_00E != 0) {
        return 0;
    }

    if ((s16)*work->unk_020 <= 31) {
        arg.unk_00 = 0;
        if (kind == 1) {
            arg.x = work->unk_050;
            arg.y = work->unk_054;
            arg.z = work->unk_058;
        } else {
            arg.x = work->unk_028;
            arg.y = work->unk_02C;
            arg.z = work->unk_030;
        }
        arg.unk_12 = *work->unk_01C;
        arg.unk_14 = work->unk_020;
        TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBosLstFal, &arg);
        result = 1;
    }

    return result;
}

u8 func_08110918(LstWork* work) {
    LstState* s;
    u8 result;

    s = work->state;
    result = 1;

    if (s->unk_0A0.unk_2C <= 0 || s->unk_002 == 6) {
        result = 0;
    }

    return result;
}

u8 func_08110938(LstWork* work) {
    LstState* s;
    u8 result;

    s = work->state;
    result = func_08110918(work);

    if (result == 1 && s->unk_012 <= 0) {
        result = 0;
    }

    return result;
}

#ifdef VERSION_EU
u8 eu_0810F08C(LstWork* work) {
    LstState* s;
    u8 result;

    s = work->state;
    result = func_08110918(work);

    if (result == 1 && (s->unk_074 == 0x100 || s->unk_078 == 0x100)) {
        result = 0;
    }

    return result;
}
#endif

s16 func_0811095C(LstWork* work, s16 a) {
    LstState* s;

    s = work->state;

    if (func_08110918(work) == 1 && a == 0) {
        s->unk_010 = a;
        a = 1;
    }

    return a;
}

void func_08110984(LstWork* work) {
    LstState* s;
    u16 zero;

    s = work->state;
    zero = 0;
    s->unk_002 = 1;
    s->unk_004 = zero;
    s->unk_006 = zero;
    s->unk_008 = zero;
}

void func_08110994(LstWork* work, s16 a) {
    LstState* s;
    u16 zero;

    s = work->state;
    zero = 0;
    s->unk_002 = 2;
    s->unk_004 = zero;
    s->unk_006 = zero;
    s->unk_008 = zero;
    s->unk_012 = a;
}

void func_081109A8(LstWork* work) {
    LstState* s;
    u16 zero;

    s = work->state;
#ifdef VERSION_EU
    if ((u16)(s->unk_002 - 5) > 1) {
#endif
        zero = 0;
        s->unk_002 = 5;
        s->unk_004 = zero;
        s->unk_006 = zero;
        s->unk_008 = zero;
#ifdef VERSION_EU
    }
#endif
}

u8 func_081109B8(LstWork* work, u8 a) {
    LstState* s;
    u8 result;

    s = work->state;
    result = 0;
    func_08111660(s->unk_1C4);
    func_08111660(s->unk_1C8);
    func_08111660(s->unk_1CC);
    s->unk_012 = 0;

    if (s->unk_002 >= 5 && s->unk_002 <= 6) {
        return 0;
    }

    if (a == 1 && s->unk_010 == 0) {
        s->unk_0A0.unk_2C = 0;
        func_0801C2DC(&s->unk_0A0, 1);
        func_081108AC(s, 0);
        func_081108AC(s, 0);
        result = 1;
    }

#ifdef VERSION_EU
    AnimReset(&s->anim);
    AnimChange(&s->anim, gUnk_09EF9EA4[s->unk_000].unk_00, 1);

    if (s->unk_002 != 0 && s->unk_002 != 5) {
        s->unk_002 = 7;
        s->unk_004 = 0;
        s->unk_006 = 0;
        s->unk_008 = 0;

        if (gBtlWork->actor->z > -0xC000) {
            s->unk_058 = -0x6000;
        } else {
            s->unk_058 = gBtlWork->unk_0D4 - 0x5000;
        }
    }
#else
    s->unk_002 = 7;
    s->unk_004 = 0;
    s->unk_006 = 0;
    s->unk_008 = 0;
#endif

    return result;
}

s32 func_08110A38(s32 a, s32 b) {
    s32 v;
    s32 step;
    s32 i;

    if (a == 0 || b == 0) {
        return 0;
    }

    v = (b << 8) / a;
    if (v <= gUnk_09A4FD5C[0]) {
        return 0;
    }

    step = 8;
    i = 16;
    while (step != 0 && v != gUnk_09A4FD5C[i]) {
        if (v < gUnk_09A4FD5C[i]) {
            i -= step;
        } else {
            i += step;
        }
        step /= 2;
    }

    return i;
}

s32 func_08110A98(s32 x0, s32 y0, s32 x1, s32 y1) {
    s32 dx;
    s32 dy;
    s32 a;

    dx = x0 - x1;
    dy = y0 - y1;

    if (abs(dx) >= abs(dy)) {
        a = func_08110A38(abs(dx), abs(dy));
    } else {
        a = 63 - func_08110A38(abs(dy), abs(dx));
    }

    if (dx >= 0) {
        if (dy >= 0) {
            a = 63 - a;
            a = a + 192;
        }
    } else if (dy >= 0) {
        a = a + 128;
    } else {
        a = 63 - a;
        a = a + 64;
    }

    a = 255 - a;
    a = a + 65;

    return a & 255;
}

s32 func_08110B10(u8 a, u8 b) {
    s32 d;

    if (a > b) {
        d = a - b;
        if (d > 128) {
            d = d - 256;
        }
        return -d;
    }

    d = b - a;
    if (d > 128) {
        d = d - 256;
    }

    return d;
}

void task_bos_lst_bit_0(LstState* work, LstBitArg* arg) {
    LstBitSubArg sub;
    BtlObj* p;
    void* pool;

    work->unk_000 = 0;
    work->unk_002 = 0;
    work->unk_004 = 0;
    work->unk_006 = 0;
    work->unk_008 = 0;
    work->unk_00A = 0;
    work->unk_00C = 0;
    work->unk_00E = arg->unk_00;
    work->unk_010 = arg->unk_04;
    work->unk_012 = 0;
    work->unk_014 = GetRandom() % 32;
    work->unk_01C = arg->unk_08;
    work->unk_020 = arg->unk_0C;
    work->unk_024 = arg->unk_10;
    work->unk_028 = arg->unk_14;
    work->unk_02C = arg->unk_18;
    work->unk_030 = arg->unk_1C;
    work->unk_044 = arg->unk_14;
    work->unk_048 = arg->unk_18;
    work->unk_04C = arg->unk_1C;
    work->unk_040 = 0;
    work->unk_050 = arg->unk_20;
    work->unk_054 = arg->unk_24;
    work->unk_058 = arg->unk_28;
    p = gBtlWork->actor;
    work->unk_068 = p->x;
    work->unk_06C = p->y;
    work->unk_070 = p->z;
    work->angle = arg->unk_04 << 7;
    work->unk_074 = 2;
    work->unk_078 = 2;
    work->tiles = (u32)LoadObjTiles(gUnk_09CD0334, 0x900);
    work->palette = (u32)LoadObjPalette(gUnk_09D69594, 0x60);
    work->palette2 = (u32)LoadObjPalette(gUnk_08F69BC4, 0x20);
    AnimInit(&work->anim, gUnk_09EFBF18, gUnk_09EFBEC4);
    AnimStart(&work->anim, gUnk_09EF9EA4[work->unk_000].unk_00, 1);
    func_0801B37C(&work->unk_0A0, &gUnk_09A4FD4C, work->unk_028, work->unk_02C, work->unk_030);
    pool = &work->tasks;
    TaskPoolInit(pool, 4);
    sub.unk_00 = work->unk_00E;
    sub.unk_04 = work->unk_01C;
    sub.unk_08 = work->unk_020;
    work->unk_1C4 = TaskCreate(pool, &gTaskDescBosLstLsr, &sub);
    work->unk_1C8 = TaskCreate(pool, &gTaskDescBosLstLsr, &sub);
    work->unk_1CC = TaskCreate(pool, &gTaskDescBosLstLsr, &sub);
}

void func_08110C9C(LstState* work) {
    void* anim;

    anim = &work->unk_0A0;

    switch (func_0801ADAC(anim)) {
    case 1:
    case 6:
    case 7:
        work->unk_00A = 20;
        func_081108AC(work, 0);
        func_0801AF08(anim);
        break;
    case 3:
        func_0801C2DC(&work->unk_0A0, 1);
        func_081108AC(work, 0);
        func_081108AC(work, 0);
        func_0801AF08(anim);
        break;
    case 5:
        func_0801AF08(anim);
        break;
    case 4:
        func_0801AF08(anim);
        break;
    case 2:
        break;
    }
}

u8 task_bos_lst_bit_1(LstState* work) {
    Vec3 a;
    Vec3 b;
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;
    BtlObj* p;
    s32 d;
    u8 dir;
    LstObj* obj;

    obj = &work->unk_0A0;

    if (obj->unk_2C <= 0) {
        func_0801C2DC(obj, 1);
        return 1;
    }

    func_08110C9C(work);

    switch (work->unk_002) {
    case 0:
        ApproachValueHalfSteps(&work->unk_028, work->unk_050, 20);
        ApproachValueHalfSteps(&work->unk_02C, work->unk_054, 20);
        ApproachValueHalfSteps(&work->unk_030, work->unk_058, 20);
        ApproachValueHalfSteps(&work->unk_074, 0x100, 32);
        ApproachValueHalfSteps(&work->unk_078, 0x100, 32);
        work->unk_006++;

        if (work->unk_006 > 29) {
            work->unk_002 = 1;
            work->unk_004 = 0;
            work->unk_006 = 0;
            work->unk_008 = 0;
            work->unk_074 = 0x100;
            work->unk_078 = 0x100;
        }
        break;
    case 1:
        if (work->unk_006 == 0) {
            if (gBtlWork->unk_068 & 0x2000000000000) {
                work->unk_050 = (GetRandom() % 113 << 8) + 0xC000;
#ifndef VERSION_EU
                work->unk_054 = gBtlWork->actor->y;
#endif
            } else if (work->unk_00E == 0) {
                work->unk_050 = (GetRandom() % 113 << 8) + 0xC000;
                work->unk_054 = gBtlWork->actor->y + (gUnk_09A4FDDC[work->unk_010] << 8);
            } else {
                work->unk_050 = gBtlWork->actor->x;
                work->unk_054 = gBtlWork->actor->y;
            }

            AnimReset(&work->anim);
            AnimChange(&work->anim, gUnk_09EF9EA4[work->unk_000].unk_00, 1);
        }

        if (!(gBtlWork->unk_068 & 0x2000000000000)) {
            if (gBtlWork->actor->z > -0xC000) {
                work->unk_058 = -0x6000;
            } else {
                work->unk_058 = gBtlWork->unk_0D4 - 0x5000;
            }
        }

        work->unk_006++;

        if ((work->unk_014 & 31) == 0) {
            func_081108AC(work, 0);
        }

        ApproachValueHalfSteps(&work->unk_028, work->unk_050, 20);
        ApproachValueHalfSteps(&work->unk_02C, work->unk_054, 20);
        ApproachValueHalfSteps(&work->unk_030, work->unk_058, 20);
        break;
    case 2:
        if (work->unk_006 == 0) {
            work->unk_050 = gBtlWork->actor->x;
            work->unk_054 = gBtlWork->actor->y;

            if (gBtlWork->actor->z > -0xC000) {
                work->unk_058 = 0;
            } else {
                work->unk_058 = gBtlWork->unk_0D4;
            }

            AnimReset(&work->anim);
            AnimChange(&work->anim, gUnk_09EF9EA4[work->unk_000].unk_02, 0);
        }

        work->unk_006++;

        if (AnimGetId(&work->anim) == (s16)gUnk_09EF9EA4[work->unk_000].unk_02 && AnimIsFinished(&work->anim) == 1) {
            work->unk_002 = 3;
            work->unk_006 = 0;
            work->unk_018 = 1;
            work->unk_01A = work->unk_01B;
            work->unk_05C = work->unk_028 + work->unk_034;
            work->unk_060 = work->unk_02C + work->unk_038;
            work->unk_064 = work->unk_030 + work->unk_03C;
            m4aSongNumStart(0x2C4);
            AnimReset(&work->anim);
            AnimChange(&work->anim, gUnk_09EF9EA4[work->unk_000].unk_00, 1);
        }
        break;
    case 3:
        if (work->unk_006 == 0) {
            if (func_081115B4(work->unk_1C4) == 0) {
                a.x = work->unk_05C;
                a.y = work->unk_060;
                a.z = work->unk_064;
                b.x = work->unk_050;
                b.y = work->unk_054;
                b.z = work->unk_058;
                func_081115CC(work->unk_1C4, &a, &b, work->unk_01A, 0);
            }

            work->unk_006++;
        } else {
            work->unk_050 = gBtlWork->actor->x;
            work->unk_054 = gBtlWork->actor->y;

            if (gBtlWork->actor->z > -0xC000) {
                work->unk_058 = 0;
            } else {
                work->unk_058 = gBtlWork->unk_0D4;
            }

            if (func_081115B4(work->unk_1C4) == 0) {
                if (work->unk_012 > 1) {
                    work->unk_002 = 2;
                    work->unk_006 = 0;
                    work->unk_012--;
                } else {
                    work->unk_012 = 0;
                }
            }
        }
        break;
    case 4:
        if (work->unk_006 > 14) {
            break;
        }

        func_08011F78(0x10D, work->unk_050, work->unk_054, work->unk_058, 8, 8, 8);

        if ((work->unk_006 & 3) == 0) {
            func_081108AC(work, 1);
        }

        if (abs(work->unk_050 - gBtlWork->actor->x) < 0x180) {
            work->unk_050 = gBtlWork->actor->x;
        } else if (work->unk_050 > gBtlWork->actor->x) {
            work->unk_050 = work->unk_050 - 0x180;
        } else if (work->unk_050 < gBtlWork->actor->x) {
            work->unk_050 = work->unk_050 + 0x180;
        }

        if (abs(work->unk_054 - gBtlWork->actor->y) < 0x180) {
            work->unk_054 = gBtlWork->actor->y;
        } else if (work->unk_054 > gBtlWork->actor->y) {
            work->unk_054 = work->unk_054 - 0x180;
        } else if (work->unk_054 < gBtlWork->actor->y) {
            work->unk_054 = work->unk_054 + 0x180;
        }

        work->unk_006++;
        break;
    case 5:
        work->unk_050 = gBtlWork->unk_0CC;
        work->unk_054 = gBtlWork->unk_0D0 - 0x1400;
        work->unk_058 = gBtlWork->unk_0D4;
        ApproachValueHalfSteps(&work->unk_028, work->unk_050, 16);
        ApproachValueHalfSteps(&work->unk_02C, work->unk_054, 16);
        ApproachValueHalfSteps(&work->unk_030, work->unk_058, 16);
        ApproachValueHalfSteps(&work->unk_074, 0x200, 16);
        ApproachValueHalfSteps(&work->unk_078, 2, 16);
        work->unk_006++;

        if (work->unk_006 > 59) {
            work->unk_002 = 6;
            work->unk_004 = 0;
            work->unk_006 = 0;
            work->unk_008 = 0;
        }
        break;
    case 6:
        work->unk_074 = 0x100;
        work->unk_078 = 0x100;
        AnimReset(&work->anim);
        AnimChange(&work->anim, 4, 1);
        break;
    case 7:
        AnimChange(&work->anim, gUnk_09EF9EA4[work->unk_000].unk_00, 1);
        break;
    }

    WorldToScreen(&x1, &y1, work->unk_028 + work->unk_034, work->unk_02C + work->unk_038,
                  work->unk_030 + work->unk_03C);

    if (gBtlWork->unk_068 & 0x2000000000000) {
        WorldToScreen(&x2, &y2, work->unk_068, work->unk_06C, work->unk_070);
        work->angle += 2;
    } else {
        if (work->unk_00E == 0) {
            switch (work->unk_002) {
            case 2:
            case 3:
                work->angle += 2;
                WorldToScreen(&x2, &y2, work->unk_050, work->unk_054, work->unk_058);
                break;
            default:
                work->angle += 2;
                WorldToScreen(&x2, &y2, gBtlWork->actor->x, gBtlWork->actor->y,
                              gBtlWork->actor->z);
                break;
            }
        } else {
            switch (work->unk_002) {
            case 2:
            case 3:
            case 4:
                work->angle += 6;
                WorldToScreen(&x2, &y2, work->unk_050, work->unk_054, work->unk_058);
                break;
            default:
                work->angle += 2;
                WorldToScreen(&x2, &y2, gBtlWork->actor->x, gBtlWork->actor->y,
                              gBtlWork->actor->z);
                break;
            }
        }

        work->unk_068 = gBtlWork->actor->x;
        work->unk_06C = gBtlWork->actor->y;
        work->unk_070 = gBtlWork->actor->z;
    }

    work->angle &= 0xFF;

    if (work->unk_00E == 0) {
        work->unk_034 = (-gSineTable[(work->angle & 0xFF) + 64] * 3 >> 6) << 8;
        work->unk_038 = (gSineTable[work->angle & 0xFF] * 3 >> 6) << 8;
        work->unk_03C = work->unk_03C / 2;
    } else if (work->unk_010 == 0) {
        work->unk_034 = work->unk_034 / 2;
        work->unk_038 = work->unk_038 / 2;
        work->unk_03C = work->unk_03C / 2;
    } else {
        work->unk_034 = (-gSineTable[(work->angle & 0xFF) + 64] >> 3) << 8;
        work->unk_038 = (gSineTable[work->angle & 0xFF] * 3 >> 6) << 8;
        work->unk_03C = 0x800;
    }

    work->unk_040 = gUnk_09A4FDE8[(work->unk_00C >> 2) & 15] << 8;
    dir = func_08110A98(x2, y2, x1, y1);
    d = func_08110B10(work->unk_01B, dir);

    if (abs(d) <= 1) {
        work->unk_01B = dir;
    } else {
        work->unk_01B += d / 2;
    }

    obj->unk_04 = work->unk_028 + work->unk_034;
    obj->unk_08 = work->unk_02C + work->unk_038;
    obj->unk_0C = work->unk_030 + work->unk_03C + work->unk_040;
    AnimUpdate(&work->anim);
    TaskPoolUpdate(&work->tasks);
    work->unk_014++;
    work->unk_00C++;

    return 1;
}

void task_bos_lst_bit_2(LstState* work) {
    s16 x;
    s16 y;
    void* pal;
    s32 affine;
    u16 prio;
    u16 z;
    void* gfx;

    if (work->unk_0A0.unk_2C <= 0) {
        return;
    }

    pal = (void*)work->palette;
    if ((work->unk_00A & 1) != 0) {
        pal = (void*)work->palette2;
    }

    if (work->unk_00A > 0) {
        work->unk_00A = work->unk_00A - 1;
    }

    WorldToScreen(&x, &y, work->unk_028 + work->unk_034, work->unk_02C + work->unk_038,
                  work->unk_030 + work->unk_03C + work->unk_040);
    prio = GetBattleSpritePriorityFlags(work->unk_02C);
    z = -0x1004 - (work->unk_02C >> 8) * 4;
    affine = AllocObjAffine(work->unk_01B, work->unk_074, work->unk_078, 0);
    gfx = AnimGetGfx(&work->anim);
    DrawSprite(x, y, gfx, (void*)work->tiles, pal, affine, prio, z);
    TaskPoolDraw(&work->tasks);
}

void task_bos_lst_bit_3(LstBitWork* work) {
    func_0801B7D8(&work->unk_0A0);
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
    ReleaseObjPalette((void*)work->palette2);
    TaskPoolDestroy(&work->tasks);
}

s32 func_0811156C(s32 x) {
    return x * x;
}

s32 func_08111574(s32 x) {
    return x * x;
}

s32 func_0811157C(s32 n) {
    s32 x;
    s32 g;

    if (n <= 0) {
        return 0;
    }

    x = 1;
    g = n;
    while (x < g) {
        x <<= 1;
        g >>= 1;
    }

    do {
        g = x;
        x = (n / g + g) >> 1;
    } while (x < g);

    return g;
}

u8 func_081115B4(LstWork* work) {
    LstState* s;
    u8 result;

    s = work->state;
    result = 0;

    switch (s->unk_000) {
    case 2:
    case 3:
        result = 1;
        break;
    }

    return result;
}

void func_081115CC(LstWork* work, Vec3* a, Vec3* b, s32 c, u16 d) {
    LstState* s;
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;

    s = work->state;
    s->unk_000 = 1;
    *(u8*)&s->unk_002 = c;
    s->unk_012 = d;
    *(Vec3*)&s->unk_024 = *a;
    *(Vec3*)&s->unk_030 = *b;
    WorldToScreen(&x1, &y1, s->unk_024, s->unk_028, s->unk_02C);
    WorldToScreen(&x2, &y2, s->unk_030, s->unk_034, s->unk_038);
    s->unk_014 = (s16)func_0811157C((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / 16;

    if (s->unk_014 <= 1) {
        s->unk_014 = 2;
    }

    s->unk_010 = 0;
}

void func_08111660(LstLsrTask* t) {
    LstLsrWork* w;

    w = t->unk_04;
    w->state = 0;
    w->unk_010 = 0;
    AnimStart(&w->anim, 4, 0);
}

u8 func_08111678(LstLsrWork* work) {
    LstFalArg arg;
    u8 result;

    result = 0;

    if (work->unk_004 != 0) {
        return 0;
    }

    if ((s16)*work->unk_00C <= 31) {
        arg.unk_00 = 0;
        arg.x = work->x2;
        arg.y = work->y2;
        arg.z = work->z2;
        arg.unk_12 = *work->unk_008;
        arg.unk_14 = work->unk_00C;
        TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBosLstFal, &arg);
        result = 1;
    }

    return result;
}

void task_bos_lst_lsr_0(LstLsrWork* work, LstLsrArg* arg) {
    work->unk_004 = arg->unk_00;
    work->unk_008 = arg->unk_04;
    work->unk_00C = arg->unk_08;
    work->state = 0;
    work->tiles = (u32)LoadObjTiles(gUnk_09CD0334, 0x900);
    work->palette = (u32)LoadObjPalette(gUnk_09D69594, 0x60);
    AnimInit(&work->anim, gUnk_09EFBF18, gUnk_09EFBEC4);
    AnimStart(&work->anim, 4, 0);
}

u8 task_bos_lst_lsr_1(LstLsrWork* work) {
    switch (work->state) {
    case 0:
        break;
    case 1:
        work->unk_012--;
        if (work->unk_012 > 0) {
            break;
        }
        work->state = 2;
        work->unk_012 = 0;
    case 2:
        work->unk_010++;
        if (work->unk_010 >= work->unk_014) {
            work->state = 3;
            work->unk_010 = 0;
            AnimReset(&work->anim);
            AnimChange(&work->anim, 6, 1);
        }
        break;
    case 3:
        if (work->unk_010 > 15) {
            work->state = 0;
            work->unk_010 = 0;
            AnimChange(&work->anim, 4, 0);
        } else {
            func_08011F78(0x10D, work->x2, work->y2, work->z2, 8, 8, 8);
            if ((work->unk_010 & 3) == 0) {
                func_08111678(work);
            }
            if (abs(work->x2 - gBtlWork->actor->x) < 384) {
                work->x2 = gBtlWork->actor->x;
            } else if (work->x2 > gBtlWork->actor->x) {
                work->x2 = work->x2 - 384;
            } else if (work->x2 < gBtlWork->actor->x) {
                work->x2 = work->x2 + 384;
            }
            if (abs(work->y2 - gBtlWork->actor->y) < 384) {
                work->y2 = gBtlWork->actor->y;
            } else if (work->y2 > gBtlWork->actor->y) {
                work->y2 = work->y2 - 384;
            } else if (work->y2 < gBtlWork->actor->y) {
                work->y2 = work->y2 + 384;
            }
            work->unk_010++;
        }
        break;
    }

    AnimUpdate(&work->anim);

    return 1;
}

void task_bos_lst_lsr_2(LstLsrWork* work) {
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;
    u16 z;
    u16 x;
    u16 y;
    u16 prio;
    void* gfx;
    s32 oam;

    switch (work->state) {
    case 2:
        WorldToScreen(&x1, &y1, work->x2, work->y2, work->z2);
        prio = GetBattleSpritePriorityFlags(work->y2);
        z = -0x1004 - (work->y2 >> 8) * 4;
        WorldToScreen(&x2, &y2, work->x, work->y, work->z);
        oam = AllocObjAffineAngle(work->unk_002, 1);
        x = x2 + (x1 - x2) * work->unk_010 / work->unk_014;
        y = y2 + (y1 - y2) * work->unk_010 / work->unk_014;
        DrawSprite(x, y, gUnk_09EFBEC4[13], (void*)work->tiles, (void*)work->palette,
                   oam, prio, z);
        break;
    case 3:
        WorldToScreen(&x1, &y1, work->x2, work->y2, work->z2);
        prio = GetBattleSpritePriorityFlags(work->y2);
        z = -0x1004 - (work->y2 >> 8) * 4;
        oam = AllocObjAffine(0, 0x100 - work->unk_010 * 8, work->unk_010 * 16 + 0x100, 1);
        gfx = AnimGetGfx(&work->anim);
        DrawSprite(x1, y1, gfx, (void*)work->tiles, (void*)work->palette,
                   oam, prio | 4, z);
        break;
    }
}

void task_bos_lst_lsr_3(LstLsrWork* work) {
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
}

s32 func_081119F8(s32 x) {
    return x * x;
}

s32 func_08111A00(s32 x) {
    return x * x;
}

u8 func_08111A08(LstWork* work) {
    LstState* s;

    s = work->state;
    return s->unk_000 != 2;
}

void task_bos_lst_ptl_0(LstPtlWork* work, LstPtlArg* arg) {
    work->state = 0;
    work->unk_002 = 0;
    work->unk_004 = 0;
    work->unk_006 = arg->unk_00;
    work->unk_008 = arg->unk_04;
    work->unk_00C = arg->unk_08;
    work->unk_010 = 0;
    work->unk_014 = 0;
    work->tiles = (u32)LoadObjTiles(gUnk_09CD0C34, 0x200);
    work->palette = (u32)LoadObjPalette(gUnk_09D69594, 0x60);
    AnimInit(&work->anim, gUnk_09EFBF54, gUnk_09EFBF40);
    AnimStart(&work->anim, 0, 1);
}

u8 task_bos_lst_ptl_1(LstPtlWork* work) {
    u8 result;

    result = 1;

    switch (work->state) {
    case 0:
        work->unk_006--;
        if (work->unk_006 <= 0) {
            work->state = 1;
            work->unk_002 = 0;
            work->unk_004 = 0;
            work->unk_006 = 0;
            AnimReset(&work->anim);
            AnimChange(&work->anim, 1, 1);
        }
        break;
    case 1:
        work->unk_008 -= 0x80;
        work->unk_00C += 0x100;
        work->unk_010 = -gSineTable[((work->unk_004 * 8) & 0xFF) + 0x40];
        work->unk_014 = gSineTable[(work->unk_004 * 2) & 0xFF];
        work->unk_004++;
        if ((work->unk_00C >> 8) > 0xA8) {
            work->state = 2;
            work->unk_002 = 0;
            work->unk_004 = 0;
            work->unk_006 = 0;
        }
        break;
    case 2:
        AnimReset(&work->anim);
        AnimChange(&work->anim, 0, 1);
        break;
    }

    AnimUpdate(&work->anim);

    return result;
}

void task_bos_lst_ptl_2(LstPtlWork* work) {
    u16 x;
    u16 y;
    u16 prio;
    void* gfx;
    u16 z;

    x = (work->unk_008 >> 8) + (work->unk_010 * 12 >> 8);
    y = (work->unk_00C >> 8) + (work->unk_014 * 6 >> 8);
    prio = GetBattleSpritePriorityFlags(0x20100);
    z = 0xE7F8;
    gfx = AnimGetGfx(&work->anim);
    DrawSprite(x, y, gfx, (void*)work->tiles, (void*)work->palette, 0, prio, z);
}

void task_bos_lst_ptl_3(LstPtlWork* work) {
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
}

s32 func_08111BF4(s32 x) {
    return x * x;
}

s32 func_08111BFC(s32 x) {
    return x * x;
}

void task_bos_lst_fal_0(LstFalWork* work, LstFalArg* arg) {
    u16 anim;

    anim = gUnk_09A4FE64[GetRandom() & 7].anim;
    work->unk_000 = arg->unk_00;
    work->x = arg->x;
    work->y = arg->y;
    work->z = arg->z;
    work->unk_010 = (GetRandom() % 0x181 + 0x80) * arg->unk_12;
    work->unk_014 = GetRandom() % 0xC1 + 0x40;
    work->unk_018 = GetRandom() % 0x81 + 0x80;

    switch (arg->unk_00) {
    case 1:
        if ((GetRandom() & 1) != 0) {
            work->unk_010 = work->unk_010 * 512 >> 8;
            work->unk_014 = work->unk_014 * 384 >> 8;
            work->unk_018 = GetRandom() % 0x81 + 0x380;
        }
        break;
    case 2:
        work->unk_014 = GetRandom() % 0x81 + 0x180;
        break;
    case 3:
        work->unk_010 = work->unk_010 * 640 >> 8;
        break;
    case 4:
        work->unk_010 = (-gSineTable[arg->angle + 0x40] << 8) / 256;
        work->unk_014 = (gSineTable[arg->angle] << 8) / 256;
        break;
    case 5:
        work->unk_010 = GetRandom() % 0x201 - 0x100;
        work->unk_014 = GetRandom() % 0xC1 + 0xC0;
        work->unk_018 = GetRandom() % 0x381 + 0x80;
        break;
    }

    switch (anim) {
    case 4:
    case 5:
        work->unk_010 = work->unk_010 * 320 >> 8;
        work->unk_014 = work->unk_014 * 320 >> 8;
        break;
    }

    work->unk_01C = arg->unk_14;
    (*work->unk_01C)++;
    work->tiles = (u32)LoadObjTiles(gUnk_09CD1074, 0x700);
    work->palette = (u32)LoadObjPalette(gUnk_09D69594, 0x60);
    AnimInit(&work->anim, gUnk_09EFBFC4, gUnk_09EFBF64);
    AnimStart(&work->anim, anim, 1);
}

u8 task_bos_lst_fal_1(LstFalWork* work) {
    u16 x;
    s16 y;
    u8 result;
    s32 d;

    result = 1;
    work->x += work->unk_010;
    work->z += work->unk_014;

    if (work->unk_000 != 4) {
        if (work->unk_018 > 0) {
            d = 512;
            if (work->unk_018 <= 512) {
                d = work->unk_018;
            }
            work->z -= d;
            work->unk_018 = work->unk_018 - 25;
        } else {
            work->unk_018 = GetRandom() % 0x41 + 0x40;
        }
    }

    WorldToScreen((s16*)&x, &y, work->x, work->y, work->z);

    if ((u16)(x + 16) > 272 || y < -64 || y > 224) {
        result = 0;
    }

    AnimUpdate(&work->anim);

    return result;
}

void task_bos_lst_fal_2(LstFalWork* work) {
    s16 x;
    s16 y;
    void* gfx;
    u16 prio;

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    gfx = AnimGetGfx(&work->anim);
    prio = GetBattleSpritePriorityFlags(work->y) | 4;
    DrawSprite(x, y, gfx, (void*)work->tiles, (void*)work->palette, 0, prio,
               -0x1004 - (work->y >> 8) * 4);
}

void task_bos_lst_fal_3(LstFalWork* work) {
    if (work->tiles != 0) {
        ReleaseObjTiles((void*)work->tiles);
    }
    if (work->palette != 0) {
        ReleaseObjPalette((void*)work->palette);
    }
    (*work->unk_01C)--;
}

s32 func_08111F3C(s32 x) {
    return x * x;
}

s32 func_08111F44(s32 x) {
    return x * x;
}

u8 func_08111F4C(LstWork* work) {
    LstState* s;

    s = work->state;
    return s->unk_008 != 4;
}

s32 func_08111F60(s32 n) {
    s32 x;
    s32 g;

    if (n <= 0) {
        return 0;
    }

    x = 1;
    g = n;
    while (x < g) {
        x <<= 1;
        g >>= 1;
    }

    do {
        g = x;
        x = (n / g + g) >> 1;
    } while (x < g);

    return g;
}

void task_bos_lst_ctr_0(LstCtrWork* work, LstCtrArg* arg) {
    work->unk_000 = arg->unk_00;
    work->unk_004 = arg->unk_04;
    work->unk_006 = arg->unk_06;
    work->state = 0;
    work->unk_00A = 0;
    work->unk_00C = 0;
    work->unk_00E = arg->unk_08;
    work->unk_020 = 0;
    work->unk_024 = 0;
    work->unk_028 = 0;
    work->unk_014 = arg->x;
    work->unk_018 = arg->y;
    work->unk_01C = arg->z;
    work->x = arg->x;
    work->y = arg->y;
    work->z = arg->z;
    work->tiles = (u32)LoadObjTiles(gUnk_09C5C704, 0x500);
    work->palette = (u32)LoadObjPalette(gUnk_09D69594, 0x60);
    AnimInit(&work->anim, gUnk_09EFAF50, gUnk_09EFAF24);
    AnimStart(&work->anim, 3, 1);
}

u8 task_bos_lst_ctr_1(LstCtrWork* work) {
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;
    BtlObj* p;
    s32 c;

    work->unk_020 /= 2;
    work->unk_024 /= 2;
    work->unk_028 /= 2;

    switch (work->state) {
    case 0:
        c = (u16)work->unk_00C + 1;
        work->unk_00C = c;
        work->unk_00E--;
        if (work->unk_00E <= 0) {
            p = gBtlWork->actor;
            work->x2 = work->unk_014 - (work->unk_014 - p->x) / 4;
            work->y2 = p->y;
            work->z2 = -0x1000;
            work->state = 1;
            work->unk_00A = 0;
            work->unk_00C = 0;
            work->unk_00E = 0;
            WorldToScreen(&x1, &y1, work->x, work->y, work->z);
            WorldToScreen(&x2, &y2, work->x2, work->y2, work->z2);
            work->unk_010 = 0;
            work->unk_012 = (s16)func_08111F60((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / 9;
        } else {
            work->unk_020 =
                (-gSineTable[((gUnk_09A4FEA8[work->unk_004][work->unk_006] + c) & 0xFF) + 0x40] * 5 >> 6) << 8;
            work->unk_028 =
                ((gSineTable[(gUnk_09A4FEA8[work->unk_004][work->unk_006] + c) & 0xFF] * 3 >> 5) - 4) << 8;
        }
        break;
    case 1:
        work->unk_014 = work->x - (work->x - work->x2) * work->unk_00C / work->unk_012;
        work->unk_018 = work->y + (work->y2 - work->y) * work->unk_00C / work->unk_012;
        work->unk_01C = work->z + (work->z2 - work->z) * work->unk_00C / work->unk_012;
        work->unk_00C++;
        if (work->unk_00C >= work->unk_012) {
            work->state = 2;
            work->unk_00A = 0;
            work->unk_00C = 0;
            work->unk_00E = 0;
        }
        if (func_08011F78(0x10F, work->unk_014, work->unk_018, work->unk_01C, 8, 1, 4) != 0) {
            m4aSongNumStart(0x2BB);
        }
        break;
    case 2:
        work->unk_00C++;
        if (work->unk_00C > 2) {
            work->state = 3;
            work->unk_00A = 0;
            work->unk_00C = 0;
            work->unk_00E = 0;
            work->unk_014 = work->x2;
            work->unk_018 = work->y2;
            work->unk_01C = work->z2;
            AnimStart(&work->anim, 1, 0);
            m4aSongNumStart(0x2C6);
        }
        break;
    case 3:
        if (work->x > work->x2) {
            work->unk_010 = 0;
            work->unk_014 = work->unk_014 - 0x600;
            if (work->unk_014 < 0x6000) {
                work->state = 4;
                work->unk_00A = 0;
                work->unk_00C = 0;
                work->unk_00E = 0;
            }
        } else {
            work->unk_010 = 0x80;
            work->unk_014 = work->unk_014 + 0x600;
            if (work->unk_014 > 0x19000) {
                work->state = 4;
                work->unk_00A = 0;
                work->unk_00C = 0;
                work->unk_00E = 0;
            }
        }
        work->unk_01C = work->z2 - ((work->unk_00C >> 2) << 8);
        if (func_08011F78(0x10F, work->unk_014, work->unk_018, work->unk_01C, 8, 4, 4) != 0) {
            m4aSongNumStart(0x2BB);
        }
        work->unk_00C++;
        break;
    case 4:
        AnimStart(&work->anim, 2, 1);
        break;
    }

    AnimUpdate(&work->anim);

    return 1;
}

void task_bos_lst_ctr_2(LstCtrWork* work) {
    s16 x;
    s16 y;
    s32 affine;
    u16 prio;
    u16 z;
    void* gfx;
    s32 d;

    WorldToScreen(&x, &y, work->unk_014 + work->unk_020, work->unk_018 + work->unk_024,
                  work->unk_01C + work->unk_028);
    affine = 0;
    prio = GetBattleSpritePriorityFlags(work->unk_018 + work->unk_024) | 4;
    z = -0x1004 - ((work->unk_018 + work->unk_024) >> 8) * 4;

    switch (work->state) {
    case 0:
        d = work->unk_00C - work->unk_006 * 8;
        if (d <= 0) {
            return;
        }
        if (d <= 15) {
            affine = AllocObjAffine(0, 0x100, d * 16, 0);
        }
        break;
    case 1:
        affine = AllocObjAffine(0, 0x100 - work->unk_00C * 4, 0x100 - work->unk_00C * 4, 1);
        break;
    case 2:
        affine = AllocObjAffine(0, 0x100 - (work->unk_012 - work->unk_00C) * 4,
                                0x100 - work->unk_012 * 4, 1);
        break;
    default:
        if (work->unk_014 + work->unk_020 > work->x2) {
            prio |= 1;
        }
        break;
    }

    gfx = AnimGetGfx(&work->anim);
    DrawSprite(x, y, gfx, (void*)work->tiles, (void*)work->palette, affine, prio, z);
}

void task_bos_lst_ctr_3(LstCtrWork* work) {
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
}

s32 func_08112410(s32 x) {
    return x * x;
}

s32 func_08112418(s32 x) {
    return x * x;
}

void task_bos_lst_snp_0(LstSnpWork* work, LstSnpArg* arg) {
    work->unk_000 = 0;
    work->x = arg->x;
    work->y = arg->y;
    work->z = arg->z;
    work->unk_010 = (GetRandom() % 0x181 + 0x80) * arg->unk_0C;
    work->unk_014 = -(GetRandom() % 0x201 + 0x400);
    work->tiles = (u32)LoadObjTiles(gUnk_09CD0E34, 0x240);
    work->palette = (u32)LoadObjPalette(gUnk_09D69594, 0x60);
    m4aSongNumStart(0x2C3);
    AnimInit(&work->anim, gUnk_09EFBF60, gUnk_09EFBF5C);
    AnimStart(&work->anim, 0, 1);
}

u8 task_bos_lst_snp_1(LstSnpWork* work) {
    s16 x;
    s16 y;
    u8 result;

    result = 1;
    work->unk_000 += 8;
    work->x += work->unk_010;
    work->z += work->unk_014;
    work->unk_014 += 64;
    WorldToScreen(&x, &y, work->x, work->y, work->z);

    if (y > 192) {
        result = 0;
    }

    AnimUpdate(&work->anim);

    return result;
}

void task_bos_lst_snp_2(LstSnpWork* work) {
    s16 x;
    s16 y;
    s32 oam;
    void* gfx;
    u16 prio;

    WorldToScreen(&x, &y, work->x, work->y, work->z);
    oam = AllocObjAffineAngle(work->unk_000, 1);
    gfx = AnimGetGfx(&work->anim);
    prio = GetBattleSpritePriorityFlags(work->y) | 4;
    DrawSprite(x, y, gfx, (void*)work->tiles, (void*)work->palette, oam, prio,
               -0x1004 - (work->y >> 8) * 4);
}

void task_bos_lst_snp_3(LstSnpWork* work) {
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
}

s32 func_081125B4(s32 x) {
    return x * x;
}
