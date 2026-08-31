#include "macros.h"
#include "bos5.h"

INCLUDE_ASM("bos5/task_bos_ga_0.s");
INCLUDE_ASM("bos5/task_bos_ga_1.s");

void task_bos_ga_2(GaWork* work) {
    GaEntryWork* p;
    u32 i;

    i = 0;
    p = work->entries;

    do {
        func_080F83E0(work, p);
        p++;
        i++;
    } while (i <= 5);
}

void task_bos_ga_3(GaWork* work) {
    GaEntryWork* p;
    u32 i;

    i = 0;
    p = work->entries;

    do {
        func_080F8374(p);
        p++;
        i++;
    } while (i <= 5);

    func_080028C0((void*)work->unk_A28);
    func_08002C10((void*)work->unk_A30);
    func_08002C10((void*)work->unk_A34);
}

INCLUDE_ASM("bos5/func_080FB8DC.s");

void func_080FB8E8(s32 unused, u16 index) {
    func_0800516C(1, gUnk_09992114 + index * 0x4C, 2, 2);
}

void func_080FB908(s32 unused, u16 index) {
    func_080050B8(1, gUnk_09992108[index].unk_04, gUnk_09992108[index].unk_08);
}

INCLUDE_ASM("bos5/func_080FB930.s");
INCLUDE_ASM("bos5/func_080FBA14.s");
INCLUDE_ASM("bos5/func_080FBA4C.s");
INCLUDE_ASM("bos5/func_080FC3FC.s");
INCLUDE_ASM("bos5/task_bos_md_0.s");
INCLUDE_ASM("bos5/task_bos_md_1.s");
INCLUDE_ASM("bos5/task_bos_md_2.s");
INCLUDE_ASM("bos5/task_bos_md_3.s");
INCLUDE_ASM("bos5/task_bos_md_map_0.s");
INCLUDE_ASM("bos5/task_bos_md_map_1.s");
INCLUDE_ASM("bos5/func_080FCC14.s");
INCLUDE_ASM("bos5/func_080FCCB4.s");
INCLUDE_ASM("bos5/task_bos_md_fire_0.s");
INCLUDE_ASM("bos5/task_bos_md_fire_1.s");
INCLUDE_ASM("bos5/task_bos_md_fire_2.s");

void task_bos_md_fire_3(MdFireWork* work) {
    func_08012304(&work->unk_078);
    func_0801B7D8(&work->unk_038);
    func_08002C10((void*)work->unk_00C);
    func_08002C10((void*)work->unk_010);
    func_080028C0((void*)work->unk_014);
}

INCLUDE_ASM("bos5/task_bos_md_dai_0.s");
INCLUDE_ASM("bos5/task_bos_md_dai_1.s");
INCLUDE_ASM("bos5/task_bos_md_dai_2.s");

void task_bos_md_dai_3(MdDaiWork* work) {
    func_08012304(&work->unk_01C);
    func_08002C10((void*)work->unk_014);
    func_080028C0((void*)work->unk_018);
    gUnk_02039B84->unk_068 &= 0xFFFFFFFFFFEFFFFF;
}

INCLUDE_ASM("bos5/task_bos_md_hahen_0.s");

s32 task_bos_md_hahen_1(MdHahenWork* work) {
    s32 result;

    result = 1;
    work->unk_000 += work->unk_00C;
    work->unk_004 += work->unk_010;

    if (work->unk_004 <= 0x117FF) {
        work->unk_010 = -work->unk_010;
    }

    work->unk_008 += work->unk_014;
    work->unk_014 += 102;

    if (work->unk_008 > 0) {
        work->unk_008 = 0;
        work->unk_014 = -(work->unk_014 * 8 / 10);
        work->unk_024--;

        if ((s16)work->unk_024 <= 0) {
            result = 0;
        }
    }

    return result;
}

void task_bos_md_hahen_2(MdHahenWork* work) {
    s16 x;
    s16 y;
    u16 frame;
    s32 flag;

    flag = gUnk_03007480 & 1;

    if (flag != 0) {
        return;
    }

    func_0801909C(&x, &y, work->unk_000, work->unk_004, work->unk_008);
    frame = func_0801AF1C(work->unk_004);
    func_080023E0(x, y, (void*)work->unk_020, (void*)work->unk_01C, (void*)work->unk_018,
                  flag, frame, (u16)(-4100 - (work->unk_004 >> 8) * 4));
}

void task_bos_md_hahen_3(MdHahenWork* work) {
    func_08002C10((void*)work->unk_018);
    func_080028C0((void*)work->unk_01C);
}

void func_080FD9B8(u16 model, u16 slot) {
    void* src;
    s32 size;

    if (gUnk_09992F70[(s16)model].unk_02 == 13 && func_080D2DD8()) {
        src = gUnk_09A3CDDC;
        size = 0x40;
    } else {
        src = gUnk_09992F70[(s16)model].unk_08;
        size = 0x20;
    }

    gUnk_02034FF8[(s16)slot].unk_0C = func_08002A14(src, size);
}

void func_080FDA28(u16 model, u16 slot) {
    void* src;

    if (gUnk_09992F70[(s16)model].unk_02 == 13 && func_080D2DD8()) {
        src = gUnk_099EDE7C;
    } else {
        src = gUnk_09992F70[(s16)model].unk_0C;
    }

    gUnk_02034FF8[(s16)slot].unk_10 = func_080026A4(src, 0x1000);
}

s16 func_080FDA98(u16 model, u16 slot) {
    if (gUnk_09992F70[(s16)model].unk_02 == 13 && func_080D2DD8()) {
        gUnk_02034FF8[(s16)slot].unk_14 = gUnk_099A8914;
    } else {
        gUnk_02034FF8[(s16)slot].unk_14 = gUnk_09992F70[(s16)model].unk_10;
    }
}

INCLUDE_ASM("bos5/func_080FDB1C.s");
INCLUDE_ASM("bos5/func_080FE89C.s");
INCLUDE_ASM("bos5/func_080FF10C.s");
INCLUDE_ASM("bos5/func_080FF19C.s");
INCLUDE_ASM("bos5/func_080FF228.s");
INCLUDE_ASM("bos5/func_080FF2B8.s");
INCLUDE_ASM("bos5/func_080FF310.s");
INCLUDE_ASM("bos5/func_080FF8CC.s");
