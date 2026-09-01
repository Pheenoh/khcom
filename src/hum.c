#include "macros.h"
#include "hum.h"

void task_hum_cloud_0(CloudWork* work, void* obj) {
    func_0800E168(&work->base, gUnk_0813EF28);
    work->unk_188 = 0;
    work->base.unk_184 = (u32)gUnk_0813EDD0;
}
INCLUDE_ASM("hum/task_hum_cloud_1.s");
void task_hum_cloud_2(HumWork* work) {
    func_0800EFE8(work);
}
void task_hum_cloud_3(HumWork* work) {
    func_0800E380(work);
}

void func_0804B44C(CloudWork* work, s16 a, s32 b) {
    HumWork* w = &work->base;
    HumActor* act = &w->unk_040;

    if (act->unk_34 & 4) {
        work->base.unk_15C = act->unk_04 - (a << 8);
    } else {
        work->base.unk_15C = act->unk_04 + (a << 8);
    }
    w->unk_160 = act->unk_08;
    w->unk_170 = 0x16;
    w->unk_150 = 0;
    work->unk_188 = -b;
}

void func_0804B4BC(CloudWork* work, s32 a, s32 b) {
    work->base.unk_15C = a;
    work->base.unk_160 = b;
    work->base.unk_170 = 0x16;
    work->base.unk_150 = 0;
    work->unk_188 = -0x680;
}

INCLUDE_ASM("hum/func_0804B4F4.s");
INCLUDE_ASM("hum/task_hum_hook_moon_0.s");

u8 task_hum_hook_moon_1(HookMoonWork* work) {
    work->unk_08++;
    return 1;
}

INCLUDE_ASM("hum/task_hum_hook_moon_2.s");

void task_hum_hook_moon_3(HookMoonWork* work) {
    ReleaseObjTiles(work->unk_00);
    ReleaseObjPalette(work->unk_04);
}

INCLUDE_ASM("hum/task_hum_hook_bomb_0.s");
INCLUDE_ASM("hum/task_hum_hook_bomb_1.s");
INCLUDE_ASM("hum/task_hum_hook_bomb_2.s");
INCLUDE_ASM("hum/task_hum_hook_bomb_3.s");
INCLUDE_ASM("hum/func_0804D060.s");
INCLUDE_ASM("hum/task_hum_ansem_0.s");
INCLUDE_ASM("hum/task_hum_ansem_1.s");

void task_hum_ansem_2(HumWork* work) {
    func_0800EFE8(work);
}

INCLUDE_ASM("hum/task_hum_ansem_3.s");
INCLUDE_ASM("hum/task_hum_hades_0.s");
INCLUDE_ASM("hum/task_hum_hades_1.s");
INCLUDE_ASM("hum/task_hum_hades_2.s");
INCLUDE_ASM("hum/task_hum_hades_3.s");
INCLUDE_ASM("hum/func_0804F8F0.s");
INCLUDE_ASM("hum/func_0804F9A0.s");
INCLUDE_ASM("hum/func_0804F9C8.s");
INCLUDE_ASM("hum/func_0804FA70.s");
INCLUDE_ASM("hum/func_0804FAD4.s");
INCLUDE_ASM("hum/task_hum_mahluxia_0.s");
INCLUDE_ASM("hum/func_0804FD7C.s");
INCLUDE_ASM("hum/task_hum_mahluxia_1.s");
INCLUDE_ASM("hum/task_hum_mahluxia_2.s");
INCLUDE_ASM("hum/task_hum_mahluxia_3.s");
INCLUDE_ASM("hum/func_08050F10.s");
INCLUDE_ASM("hum/task_hum_laxene_0.s");
INCLUDE_ASM("hum/task_hum_laxene_1.s");

void task_hum_laxene_2(LaxeneWork* work) {
    func_0800EFE8(&work->base);
    TaskPoolDraw(&work->unk_194);
}

void task_hum_laxene_3(LaxeneWork* work) {
    m4aSongNumStop(0x2A2);
    func_0800E380(&work->base);
    TaskPoolDestroy(&work->unk_194);
}

INCLUDE_ASM("hum/task_hum_laxene_knf_0.s");
INCLUDE_ASM("hum/task_hum_laxene_knf_1.s");
INCLUDE_ASM("hum/task_hum_laxene_knf_2.s");
INCLUDE_ASM("hum/task_hum_laxene_knf_3.s");
INCLUDE_ASM("hum/func_0805273C.s");
INCLUDE_ASM("hum/task_hum_axcel_0.s");
INCLUDE_ASM("hum/task_hum_axcel_1.s");
INCLUDE_ASM("hum/func_08054100.s");
INCLUDE_ASM("hum/task_hum_axcel_2.s");
INCLUDE_ASM("hum/task_hum_axcel_3.s");
INCLUDE_ASM("hum/task_hum_axcel_ptc_0.s");
INCLUDE_ASM("hum/task_hum_axcel_ptc_1.s");
INCLUDE_ASM("hum/task_hum_axcel_ptc_2.s");
INCLUDE_ASM("hum/task_hum_axcel_ptc_3.s");
INCLUDE_ASM("hum/func_080543B4.s");
INCLUDE_ASM("hum/task_hum_vixen_0.s");
INCLUDE_ASM("hum/task_hum_vixen_1.s");

void task_hum_vixen_2(VixenWork* work) {
    func_0800EFE8(&work->base);
    TaskPoolDraw(&work->unk_1A4);
}

INCLUDE_ASM("hum/task_hum_vixen_3.s");
INCLUDE_ASM("hum/task_hum_vixen_ndl_0.s");
INCLUDE_ASM("hum/task_hum_vixen_ndl_1.s");
INCLUDE_ASM("hum/task_hum_vixen_ndl_2.s");

void task_hum_vixen_ndl_3(VixenNdlWork* work) {
    ReleaseObjPalette(work->unk_04);
}

INCLUDE_ASM("hum/task_hum_vixen_ice_0.s");
INCLUDE_ASM("hum/task_hum_vixen_ice_1.s");
INCLUDE_ASM("hum/task_hum_vixen_ice_2.s");

void task_hum_vixen_ice_3(VixenIceWork* work) {
    ReleaseObjTiles(work->unk_04);
    ReleaseObjPalette(work->unk_08);
    func_08012304(&work->unk_28);
}

INCLUDE_ASM("hum/task_hum_vixen_frz_0.s");
INCLUDE_ASM("hum/task_hum_vixen_frz_1.s");
INCLUDE_ASM("hum/task_hum_vixen_frz_2.s");

void task_hum_vixen_frz_3(VixenFrzWork* work) {
    ReleaseObjPalette(work->unk_04);
}

INCLUDE_ASM("hum/task_hum_vixen_frg_0.s");
INCLUDE_ASM("hum/task_hum_vixen_frg_1.s");
INCLUDE_ASM("hum/task_hum_vixen_frg_2.s");
INCLUDE_ASM("hum/task_hum_vixen_frg_3.s");
INCLUDE_ASM("hum/task_hum_lexceus_0.s");
INCLUDE_ASM("hum/task_hum_lexceus_1.s");
INCLUDE_ASM("hum/task_hum_lexceus_2.s");

void task_hum_lexceus_3(LexceusWork* work) {
    func_0800E380(&work->base);
    TaskPoolDestroy(&work->unk_1D8);
}

INCLUDE_ASM("hum/task_hum_lex_tmh_0.s");
INCLUDE_ASM("hum/task_hum_lex_tmh_1.s");
INCLUDE_ASM("hum/task_hum_lex_tmh_2.s");

void task_hum_lex_tmh_3(LexTmhWork* work) {
    ReleaseObjTiles(work->unk_40);
    ReleaseObjPalette(work->unk_44);
    ReleaseObjTiles(work->unk_00);
    ReleaseObjPalette(work->unk_04);
}

INCLUDE_ASM("hum/task_hum_lex_tmh0_0.s");
INCLUDE_ASM("hum/task_hum_lex_tmh0_1.s");
INCLUDE_ASM("hum/task_hum_lex_tmh0_2.s");

void task_hum_lex_tmh0_3(LexTmh0Work* work) {
    ReleaseObjTiles(work->unk_00);
    ReleaseObjPalette(work->unk_04);
}

INCLUDE_ASM("hum/task_hum_lex_rock_0.s");
INCLUDE_ASM("hum/task_hum_lex_rock_1.s");
INCLUDE_ASM("hum/task_hum_lex_rock_2.s");
INCLUDE_ASM("hum/task_hum_lex_rock_3.s");
INCLUDE_ASM("hum/task_hum_mahluxia_flw_0.s");
INCLUDE_ASM("hum/task_hum_mahluxia_flw_1.s");
INCLUDE_ASM("hum/task_hum_mahluxia_flw_2.s");

void task_hum_mahluxia_flw_3(MahluxiaFlwWork* work) {
    ReleaseObjTiles(work->unk_04);
    ReleaseObjPalette(work->unk_08);
}

INCLUDE_ASM("hum/func_08057CBC.s");
INCLUDE_ASM("hum/func_08057D30.s");
INCLUDE_ASM("hum/func_08057D68.s");
INCLUDE_ASM("hum/func_08057E2C.s");
INCLUDE_ASM("hum/func_08057E90.s");
INCLUDE_ASM("hum/task_hum_riku_0.s");
INCLUDE_ASM("hum/task_hum_riku_1.s");
INCLUDE_ASM("hum/task_hum_riku_2.s");

void task_hum_riku_3(HumWork* work) {
    func_0800E380(work);
}

INCLUDE_ASM("hum/task_hum_leon_0.s");
INCLUDE_ASM("hum/task_hum_leon_1.s");

void task_hum_leon_2(HumWork* work) {
    func_0800EFE8(work);
}

INCLUDE_ASM("hum/task_hum_leon_3.s");
INCLUDE_ASM("hum/task_hum_robe_0.s");
INCLUDE_ASM("hum/task_hum_robe_1.s");

void task_hum_robe_2(HumWork* work) {
    func_0800EFE8(work);
}

void task_hum_robe_3(HumWork* work) {
    func_0800E380(work);
}

INCLUDE_ASM("hum/MakeSaveHeaderData.s");
INCLUDE_ASM("hum/MakeSaveSystem.s");
INCLUDE_ASM("hum/MakeSaveFileLarge.s");
INCLUDE_ASM("hum/MakeSaveFileSmall.s");
INCLUDE_ASM("hum/ApplySaveHeaderData.s");
INCLUDE_ASM("hum/ApplySaveSystem.s");
INCLUDE_ASM("hum/ApplySaveFileLarge.s");
INCLUDE_ASM("hum/ApplySaveFileSmall.s");
INCLUDE_ASM("hum/func_0805A484.s");
INCLUDE_ASM("hum/func_0805A4D8.s");
INCLUDE_ASM("hum/func_0805A55C.s");
INCLUDE_ASM("hum/func_0805A574.s");
INCLUDE_ASM("hum/func_0805A638.s");
INCLUDE_ASM("hum/func_0805A698.s");
INCLUDE_ASM("hum/func_0805A7D0.s");
INCLUDE_ASM("hum/func_0805A8D0.s");
INCLUDE_ASM("hum/func_0805A95C.s");
INCLUDE_ASM("hum/func_0805AA9C.s");
