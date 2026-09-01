#include "macros.h"
#include "bos4.h"

INCLUDE_ASM("bos4/task_bos_boogie_dice_0.s");
INCLUDE_ASM("bos4/task_bos_boogie_dice_1.s");
INCLUDE_ASM("bos4/task_bos_boogie_dice_2.s");
INCLUDE_ASM("bos4/task_bos_boogie_dice_3.s");
INCLUDE_ASM("bos4/func_080DA4DC.s");
INCLUDE_ASM("bos4/task_bos_boogie_explosiondice_0.s");
INCLUDE_ASM("bos4/task_bos_boogie_explosiondice_1.s");
INCLUDE_ASM("bos4/task_bos_boogie_explosiondice_2.s");
INCLUDE_ASM("bos4/task_bos_boogie_explosiondice_3.s");

u8 func_080DA73C(void) {
    if (*(s32*)((u8*)gUnk_02039B84->unk_07C + 8) <= 0x23EFF) {
        return 1;
    }

    return 0;
}

INCLUDE_ASM("bos4/task_bos_boogie_saku_0.s");
INCLUDE_ASM("bos4/task_bos_boogie_saku_1.s");
INCLUDE_ASM("bos4/func_080DA954.s");
INCLUDE_ASM("bos4/task_bos_boogie_saku_2.s");

void task_bos_boogie_saku_3(BoogieSakuWork* work) {
    ReleaseObjTiles((void*)work->unk_000);
    ReleaseObjPalette((void*)work->unk_004);
    TaskPoolDestroy(&work->unk_028);
}

INCLUDE_ASM("bos4/task_bos_boogie_map_0.s");
INCLUDE_ASM("bos4/task_bos_boogie_map_1.s");
INCLUDE_ASM("bos4/task_bos_boogie_mapanime_0.s");
INCLUDE_ASM("bos4/task_bos_boogie_mapanime_1.s");

void task_bos_boogie_mapanime_2(void) {
}

void task_bos_boogie_mapanime_3(void) {
}

INCLUDE_ASM("bos4/func_080DABFC.s");
INCLUDE_ASM("bos4/task_bos_boogie_disk_0.s");
INCLUDE_ASM("bos4/task_bos_boogie_disk_1.s");
INCLUDE_ASM("bos4/task_bos_boogie_disk_2.s");
INCLUDE_ASM("bos4/task_bos_boogie_disk_3.s");
INCLUDE_ASM("bos4/func_080DB04C.s");
INCLUDE_ASM("bos4/task_bos_boogie_knife_0.s");
INCLUDE_ASM("bos4/task_bos_boogie_knife_1.s");
INCLUDE_ASM("bos4/task_bos_boogie_knife_2.s");

void task_bos_boogie_knife_3(BoogieKnifeWork* work) {
    func_08012304(&work->unk_06C);
    ReleaseObjTiles((void*)work->unk_008);
    ReleaseObjPalette((void*)work->unk_00C);
    ReleaseObjPalette((void*)work->unk_010);
}

u8 func_080DB428(u8* p) {
    if (*(s32*)(p + 0x38) >= 0) {
        return 1;
    }

    return 0;
}

INCLUDE_ASM("bos4/func_080DB438.s");
INCLUDE_ASM("bos4/func_080DB468.s");
INCLUDE_ASM("bos4/task_bos_boogie_knifereader_0.s");
INCLUDE_ASM("bos4/task_bos_boogie_knifereader_1.s");

void task_bos_boogie_knifereader_2(BoogieKnifereaderWork* work) {
    TaskPoolDraw(&work->unk_008);
}

void task_bos_boogie_knifereader_3(BoogieKnifereaderWork* work) {
    func_0801B7D8(&work->unk_01C);
    TaskPoolDestroy(&work->unk_008);
}

INCLUDE_ASM("bos4/task_bos_boogie_kaihuku_0.s");
INCLUDE_ASM("bos4/task_bos_boogie_kaihuku_1.s");
INCLUDE_ASM("bos4/task_bos_boogie_kaihuku_2.s");

void task_bos_boogie_kaihuku_3(BoogieKaihukuWork* work) {
    func_0801B7D8(&work->unk_040);
    ReleaseObjTiles((void*)work->unk_008);
    ReleaseObjPalette((void*)work->unk_00C);
    ReleaseObjPalette((void*)work->unk_010);
}

INCLUDE_ASM("bos4/func_080DB978.s");
INCLUDE_ASM("bos4/func_080DBA14.s");
INCLUDE_ASM("bos4/func_080DBC00.s");
INCLUDE_ASM("bos4/func_080DBC68.s");

u8 func_080DC510(void) {
    return *(u64*)((u8*)gUnk_02034F0C + 0x58) & 4;
}

u8 func_080DC528(void) {
    if (*(u16*)((u8*)gUnk_02034F0C + 0x142) == 0) {
        return 0;
    }

    return 1;
}

INCLUDE_ASM("bos4/func_080DC544.s");
INCLUDE_ASM("bos4/func_080DC578.s");
INCLUDE_ASM("bos4/func_080DC5B0.s");
INCLUDE_ASM("bos4/func_080DC5E8.s");

u8 func_080DC628(void) {
    if (**(u32**)&gUnk_02034F0C == 4) {
        return 1;
    }

    return 0;
}

INCLUDE_ASM("bos4/task_bos_ursula_map_0.s");
INCLUDE_ASM("bos4/task_bos_ursula_map_1.s");

void task_bos_ursula_map_3(void) {
}

INCLUDE_ASM("bos4/task_bos_ursula_border_0.s");

s32 task_bos_ursula_border_1(void) {
    return 1;
}

INCLUDE_ASM("bos4/task_bos_ursula_border_2.s");

void task_bos_ursula_border_3(UrsulaBorderWork* work) {
    ReleaseObjTiles((void*)work->unk_000);
    ReleaseObjPalette((void*)work->unk_004);
}

INCLUDE_ASM("bos4/func_080DC9DC.s");

u8 func_080DCA78(u8 a) {
    if (a == func_080DC510()) {
        return 12;
    }

    return 6;
}

INCLUDE_ASM("bos4/task_bos_ursula_tako_0.s");
INCLUDE_ASM("bos4/task_bos_ursula_tako_1.s");
INCLUDE_ASM("bos4/task_bos_ursula_tako_2.s");
INCLUDE_ASM("bos4/task_bos_ursula_tako_3.s");
INCLUDE_ASM("bos4/func_080DD1FC.s");
INCLUDE_ASM("bos4/func_080DD248.s");
INCLUDE_ASM("bos4/task_bos_ursula_backtako_0.s");
INCLUDE_ASM("bos4/task_bos_ursula_backtako_1.s");
INCLUDE_ASM("bos4/task_bos_ursula_backtako_2.s");

void task_bos_ursula_backtako_3(UrsulaBacktakoWork* work) {
    ReleaseObjTiles((void*)work->unk_000);
    ReleaseObjPalette((void*)work->unk_004);
}

INCLUDE_ASM("bos4/task_bos_ursula_mapanime_0.s");
INCLUDE_ASM("bos4/task_bos_ursula_mapanime_1.s");

void task_bos_ursula_mapanime_2(UrsulaMapanimeWork* work) {
    TaskPoolDraw(&work->unk_010);
}

void task_bos_ursula_mapanime_3(UrsulaMapanimeWork* work) {
    TaskPoolDestroy(&work->unk_010);
}

INCLUDE_ASM("bos4/func_080DD69C.s");
INCLUDE_ASM("bos4/func_080DD7C4.s");
INCLUDE_ASM("bos4/func_080DD854.s");
INCLUDE_ASM("bos4/func_080DD8A8.s");
INCLUDE_ASM("bos4/task_bos_ursula_bubble_0.s");
INCLUDE_ASM("bos4/task_bos_ursula_bubble_1.s");

void task_bos_ursula_bubble_2(UrsulaBubbleWork* work) {
    TaskPoolDraw(&work->unk_004);
}

#ifndef VERSION_EU
void task_bos_ursula_bubble_3(UrsulaBubbleWork* work) {
    TaskPoolDestroy(&work->unk_004);
}
#else
INCLUDE_ASM("bos4/task_bos_ursula_bubble_3.s");
#endif

INCLUDE_ASM("bos4/func_080DD9B0.s");
INCLUDE_ASM("bos4/task_bos_ursula_bubble_single_0.s");
INCLUDE_ASM("bos4/task_bos_ursula_bubble_single_1.s");
INCLUDE_ASM("bos4/task_bos_ursula_bubble_single_2.s");
INCLUDE_ASM("bos4/task_bos_ursula_bubble_single_3.s");
INCLUDE_ASM("bos4/func_080DDD30.s");
INCLUDE_ASM("bos4/task_bos_ursula_thunder_0.s");
INCLUDE_ASM("bos4/task_bos_ursula_thunder_1.s");

void task_bos_ursula_thunder_2(void) {
}

void task_bos_ursula_thunder_3(void) {
}

void func_080DDDDC(u8* p, void* q) {
    *(u16*)(p + 0) = 0;
    *(u16*)(p + 2) = 0;
    *(u8*)(p + 4) = 1;
    *(void**)(p + 8) = q;
}

INCLUDE_ASM("bos4/func_080DDDEC.s");
INCLUDE_ASM("bos4/func_080DDE74.s");

u16 func_080DDEA0(u16* p) {
    return p[1];
}

void func_080DDEA4(s32 a) {
    func_080D2C78(a);
}

void func_080DDEB0(s32 a) {
    func_080D2DB0(a);
}

void func_080DDEBC(s32 a) {
    func_080D2DC4(a);
}

INCLUDE_ASM("bos4/func_080DDEC8.s");
INCLUDE_ASM("bos4/func_080DEBAC.s");
INCLUDE_ASM("bos4/func_080DEBD8.s");
INCLUDE_ASM("bos4/func_080DEC00.s");
INCLUDE_ASM("bos4/func_080DEC44.s");
INCLUDE_ASM("bos4/func_080DED64.s");
INCLUDE_ASM("bos4/func_080DED98.s");
INCLUDE_ASM("bos4/func_080DEDD8.s");

u8* func_080DEE18(u8 index) {
    return gUnk_0203C5AC + index * 0x10;
}

u8 func_080DEE28(u8 a, u8 b) {
    return func_080DED98(a)[b];
}

INCLUDE_ASM("bos4/func_080DEE44.s");
INCLUDE_ASM("bos4/func_080DF380.s");
INCLUDE_ASM("bos4/func_080DF51C.s");
INCLUDE_ASM("bos4/func_080DF548.s");
INCLUDE_ASM("bos4/func_080DF570.s");
INCLUDE_ASM("bos4/func_080DF5F4.s");
INCLUDE_ASM("bos4/func_080DF640.s");
INCLUDE_ASM("bos4/func_080DF6D0.s");

void func_080DF730(u8 a, u8 b) {
    gUnk_0203C590[6] = a;
    gUnk_0203C590[7] = func_080DEBAC(b);
    func_080DEC44();
}

INCLUDE_ASM("bos4/func_080DF750.s");

#ifndef VERSION_EU
u32 func_080DF804(u8 index) {
    return gUnk_09EF69FC[index];
}
#else
INCLUDE_ASM("bos4/func_080DF804.s");
#endif

void func_080DF814(void) {
    func_080DF730(0xFE, 1);
    func_080E04EC();
}

INCLUDE_ASM("bos4/func_080DF828.s");
INCLUDE_ASM("bos4/func_080DF8C0.s");
INCLUDE_ASM("bos4/func_080DF964.s");
INCLUDE_ASM("bos4/func_080DF990.s");
INCLUDE_ASM("bos4/func_080DF9A8.s");
INCLUDE_ASM("bos4/func_080DF9C4.s");
INCLUDE_ASM("bos4/func_080DF9E0.s");
INCLUDE_ASM("bos4/func_080DFA18.s");
INCLUDE_ASM("bos4/func_080DFA3C.s");
INCLUDE_ASM("bos4/func_080DFAA8.s");
INCLUDE_ASM("bos4/func_080DFAF4.s");
INCLUDE_ASM("bos4/func_080DFB2C.s");

s32 func_080DFB7C(u8 a) {
    return func_080E5590(a);
}

INCLUDE_ASM("bos4/func_080DFB8C.s");
INCLUDE_ASM("bos4/func_080DFBDC.s");
INCLUDE_ASM("bos4/func_080DFC24.s");
INCLUDE_ASM("bos4/func_080DFCDC.s");
INCLUDE_ASM("bos4/func_080DFD84.s");
INCLUDE_ASM("bos4/_080DFE1C.s");
