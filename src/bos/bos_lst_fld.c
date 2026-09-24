#include "bos7.h"
#include "sprites_bos7.h"
#include "sprites_bos6.h"
#include "gba/io_reg.h"

const s8 gUnk_09A4FBF4[33] = {
    4, 4, 4, 4, -4, -4, -4, -4, 3, 3, 3, 3, -3, -3, -3, -3, 2, 2, 2, 2, -2, -2, -2, -2, 1, 1, 1, 1, -1, -1, -1, -1, 0,
};

const s8 gUnk_09A4FC15[9] = {
    1, 2, 2, 1, -1, -2, -2, -1, 0,
};

const s32 gUnk_09A4FC20[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,
};

const s32 gUnk_09A4FD20 = 0;

const s8* gUnk_09EF9E6C[2] = { gUnk_09A4FBF4, gUnk_09A4FC15 };

TaskDesc gTaskDescBosLstFld = {
    "task_bos_lst_fld",
    (TaskInitFunc)task_bos_lst_fld_0,
    (TaskUpdateFunc)task_bos_lst_fld_1,
    (TaskFunc)task_bos_lst_fld_2,
    (TaskFunc)task_bos_lst_fld_3,
    0x1304,
};

u8 gUnk_02036014;
s16 gUnk_02036016;
s16 gUnk_02036018;
s32 gUnk_0203601C;

s32 func_0810FE84(s32 x) {
    return x * x;
}

s32 func_0810FE8C(s32 x) {
    return x * x;
}

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
    gBtlWork->scale = 0x100;
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
    dma = (vu32*)REG_ADDR_DMA3;
    dma[0] = (vu32)gUnk_09A4D234;
    dma[1] = (vu32)work->unk_0C4;
    dma[2] = (DMA_ENABLE << 16) | 0x340;
    dma[2];
    dma[0] = (vu32)gUnk_09A4F2B4;
    dma[1] = (vu32)work->unk_744;
    dma[2] = (DMA_ENABLE << 16) | 0x4A0;
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

        if (gBtlWork->flags & 0x2000000000000) {
            b = (gBtlWork->y2 - gBtlWork->y) >> 3;
        } else if (gBtlWork->flags & 0x200000) {
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
            ScanlineDmaInit(REG_ADDR_BG0HOFS, work->unk_1084[work->unk_018 & 1], ((DMA_ENABLE | DMA_REPEAT | DMA_START_HBLANK | DMA_DEST_RELOAD) << 16) | 0x1);
            break;
        case 1:
            LoadBgMap(0, gUnk_09D4BA74, 0x800);
            ScanlineDmaInit(REG_ADDR_BG0HOFS, work->unk_744, ((DMA_ENABLE | DMA_REPEAT | DMA_START_HBLANK | DMA_DEST_RELOAD) << 16) | 0x1);
            break;
        case 2:
            work->unk_020 = -(work->unk_014 * 120);

            if (work->unk_014 > 0) {
                LoadBgMap(0, gUnk_09D4C274, 0x800);
            } else {
                LoadBgMap(0, gUnk_09D4CA74, 0x800);
            }

            ScanlineDmaInit(REG_ADDR_BG0VOFS, work->unk_1084[work->unk_018 & 1], ((DMA_ENABLE | DMA_REPEAT | DMA_START_HBLANK | DMA_DEST_RELOAD) << 16) | 0x1);
            break;
        case 3:
            work->unk_01C = 0;
            LoadBgMap(0, gUnk_09D4C274, 0x800);
            ScanlineDmaInit(REG_ADDR_BG0VOFS, work->unk_0C4, ((DMA_ENABLE | DMA_REPEAT | DMA_START_HBLANK | DMA_DEST_RELOAD) << 16) | 0x1);
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
