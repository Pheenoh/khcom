#include "macros.h"
#include "bos2.h"

INCLUDE_ASM("bos2/task_bos_tm_body_0.s");
INCLUDE_ASM("bos2/task_bos_tm_body_1.s");
INCLUDE_ASM("bos2/task_bos_tm_body_2.s");
INCLUDE_ASM("bos2/task_bos_tm_body_3.s");
INCLUDE_ASM("bos2/func_080BA08C.s");

void func_080BA0E4(s32* p, s32 a, s32 b, s32 c) {
    p[1] = (s16)a << 8;
    p[2] = (s16)b << 8;
    p[3] = (s16)c << 8;
}

void func_080BA0F8(u8* work) {
    func_08012304(work + 0x40);
}

INCLUDE_ASM("bos2/func_080BA104.s");
INCLUDE_ASM("bos2/func_080BA2B0.s");
INCLUDE_ASM("bos2/task_bos_tm_foot_0.s");
INCLUDE_ASM("bos2/task_bos_tm_foot_1.s");
INCLUDE_ASM("bos2/task_bos_tm_foot_2.s");

void task_bos_tm_foot_3(TmFootWork* work) {
    if ((*(u16*)((u8*)*(void**)((u8*)work + 0x47C) + 40) & 8) == 0) {
        func_080BA0F8((u8*)work + 0x24C);
        func_080BA0F8((u8*)work + 0x364);
    }

    func_080028C0((void*)work->unk_008);
    func_08002C10((void*)work->unk_014);
    func_08002C10((void*)work->unk_018);
}

INCLUDE_ASM("bos2/func_080BB1B8.s");

void task_bos_tm_clb_0(TmClbWork* work, void* arg) {
    void* p;

    work->unk_004 = (u32)func_080026A4(gUnk_09652E84, 0x1D80);
    work->unk_008 = (u32)func_08002A14(gUnk_096FB2A4, 0x60);
    work->unk_000 = (u32)arg;
    p = ((void**)arg)[2];
    work->unk_00C = *(u16*)((u8*)p + 12);
    work->unk_010 = *(u32*)p;
    work->unk_014 = *(u32*)((u8*)p + 4);
    work->unk_018 = *(u32*)((u8*)p + 8);
}

INCLUDE_ASM("bos2/task_bos_tm_clb_1.s");
INCLUDE_ASM("bos2/task_bos_tm_clb_2.s");

void task_bos_tm_clb_3(TmClbWork* work) {
    func_080028C0((void*)work->unk_004);
    func_08002C10((void*)work->unk_008);
}

void func_080BB428(u8* dst, u8* src) {
    s32 i;

    i = 3;

    do {
        *(u16*)(dst + 20) = *src;
        src += 4;
        dst += 0x34;
    } while (--i >= 0);
}

void func_080BB43C(u8* work, u8* src, u16 a, u8* dst) {
    if (*(u8**)(work + 8) != src) {
        *(u8**)(work + 8) = src;
        *(u16*)(work + 0) = 0;
        *(u16*)(work + 2) = 0;
        *(u16*)(work + 4) = a;
        func_080BB428(dst, src + 4);
    }
}

INCLUDE_ASM("bos2/func_080BB464.s");
INCLUDE_ASM("bos2/func_080BB4C0.s");
INCLUDE_ASM("bos2/func_080BB518.s");
INCLUDE_ASM("bos2/func_080BB588.s");
INCLUDE_ASM("bos2/func_080BB5E8.s");
INCLUDE_ASM("bos2/task_bos_tm_arm_0.s");
INCLUDE_ASM("bos2/func_080BC304.s");
INCLUDE_ASM("bos2/task_bos_tm_arm_1.s");
INCLUDE_ASM("bos2/task_bos_tm_arm_2.s");

void task_bos_tm_arm_3(TmArmWork* work) {
    func_080028C0((void*)work->unk_000);
    func_080028C0((void*)work->unk_238);
    func_08002C10((void*)work->unk_004);
    func_08002C10((void*)work->unk_008);
    func_08000F0C(&work->unk_1B4);
}

INCLUDE_ASM("bos2/task_bos_tm_tbl_0.s");
INCLUDE_ASM("bos2/task_bos_tm_tbl_1.s");

void task_bos_tm_tbl_3(TmTblWork* work) {
    func_08012304(&work->unk_004);
    func_0800501C(1);
}

INCLUDE_ASM("bos2/task_bos_jf_0.s");
INCLUDE_ASM("bos2/task_bos_jf_1.s");

void task_bos_jf_2(JfWork* work) {
    func_08000EE0(&work->unk_254);
}

INCLUDE_ASM("bos2/task_bos_jf_3.s");
INCLUDE_ASM("bos2/func_080BD7F8.s");
INCLUDE_ASM("bos2/task_bos_jf_map_0.s");
INCLUDE_ASM("bos2/task_bos_jf_map_1.s");
INCLUDE_ASM("bos2/func_080BDAAC.s");
INCLUDE_ASM("bos2/func_080BDB58.s");
INCLUDE_ASM("bos2/task_bos_jf_lamp_0.s");
INCLUDE_ASM("bos2/task_bos_jf_lamp_1.s");
INCLUDE_ASM("bos2/task_bos_jf_lamp_2.s");
INCLUDE_ASM("bos2/task_bos_jf_lamp_3.s");
INCLUDE_ASM("bos2/func_080BE380.s");
INCLUDE_ASM("bos2/func_080BE3DC.s");
INCLUDE_ASM("bos2/func_080BE478.s");
INCLUDE_ASM("bos2/task_bos_jf_majin_0.s");
INCLUDE_ASM("bos2/task_bos_jf_majin_1.s");
INCLUDE_ASM("bos2/task_bos_jf_majin_2.s");
INCLUDE_ASM("bos2/task_bos_jf_majin_3.s");
INCLUDE_ASM("bos2/func_080C0258.s");
INCLUDE_ASM("bos2/task_bos_jf_rock_0.s");
INCLUDE_ASM("bos2/task_bos_jf_rock_1.s");
INCLUDE_ASM("bos2/task_bos_jf_rock_2.s");
INCLUDE_ASM("bos2/task_bos_jf_rock_3.s");
INCLUDE_ASM("bos2/task_bos_jf_borderline_0.s");
INCLUDE_ASM("bos2/task_bos_jf_borderline_1.s");
INCLUDE_ASM("bos2/task_bos_jf_borderline_2.s");

void task_bos_jf_borderline_3(JfBorderlineWork* work) {
    func_080028C0((void*)work->unk_004);
    func_08002C10((void*)work->unk_008);
}

INCLUDE_ASM("bos2/func_080C1A48.s");
INCLUDE_ASM("bos2/task_bos_dsd_0.s");
INCLUDE_ASM("bos2/task_bos_dsd_1.s");

void task_bos_dsd_2(DsdWork* work) {
    func_08000EE0(&work->unk_37C);
}

void task_bos_dsd_3(DsdWork* work) {
    u32* a;
    u32* b;

    a = &work->unk_110;
    b = &work->unk_220;
    func_08000F0C(&work->unk_37C);
    func_08012304(&work->unk_260);
    func_0801B7D8(work);
    func_0801B7D8(a);
    func_0801B7D8(b);
}

void func_080C211C(u8 index) {
    func_0800516C(1, gUnk_09EF2AA4 + index * 0x10, 2, 2);
}

INCLUDE_ASM("bos2/func_080C213C.s");
INCLUDE_ASM("bos2/task_bos_dsd_main_0.s");
INCLUDE_ASM("bos2/task_bos_dsd_main_1.s");
INCLUDE_ASM("bos2/task_bos_dsd_main_2.s");
INCLUDE_ASM("bos2/task_bos_dsd_main_3.s");
INCLUDE_ASM("bos2/func_080C2734.s");
INCLUDE_ASM("bos2/func_080C2828.s");
INCLUDE_ASM("bos2/func_080C288C.s");
INCLUDE_ASM("bos2/func_080C297C.s");
INCLUDE_ASM("bos2/func_080C29F4.s");
INCLUDE_ASM("bos2/func_080C2F68.s");
INCLUDE_ASM("bos2/func_080C3504.s");
INCLUDE_ASM("bos2/task_bos_dsd_map_0.s");
INCLUDE_ASM("bos2/task_bos_dsd_map_1.s");
INCLUDE_ASM("bos2/task_bos_dsd_ita_0.s");
INCLUDE_ASM("bos2/task_bos_dsd_ita_1.s");
INCLUDE_ASM("bos2/task_bos_dsd_ita_2.s");

void task_bos_dsd_ita_3(DsdItaWork* work) {
    func_08012304(&work->unk_004);
}

INCLUDE_ASM("bos2/func_080C427C.s");

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

INCLUDE_ASM("bos2/task_bos_dsd_rock_0.s");
INCLUDE_ASM("bos2/task_bos_dsd_rock_1.s");
INCLUDE_ASM("bos2/task_bos_dsd_rock_2.s");

void task_bos_dsd_rock_3(void) {
}

INCLUDE_ASM("bos2/task_bos_dsd_circle_0.s");
INCLUDE_ASM("bos2/task_bos_dsd_circle_1.s");
INCLUDE_ASM("bos2/task_bos_dsd_circle_2.s");

void task_bos_dsd_circle_3(void) {
}

INCLUDE_ASM("bos2/task_bos_dsd_energy1_0.s");
INCLUDE_ASM("bos2/task_bos_dsd_energy1_1.s");
INCLUDE_ASM("bos2/task_bos_dsd_energy1_2.s");
INCLUDE_ASM("bos2/task_bos_dsd_energy1_3.s");
INCLUDE_ASM("bos2/task_bos_dsd_energy2_0.s");
INCLUDE_ASM("bos2/task_bos_dsd_energy2_1.s");
INCLUDE_ASM("bos2/task_bos_dsd_energy2_2.s");

void task_bos_dsd_energy2_3(void) {
}

ALIGN_ZERO(2);
