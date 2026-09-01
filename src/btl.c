#include "macros.h"
#include "btl.h"

INCLUDE_ASM("btl/task_btl_lockon_0.s");
INCLUDE_ASM("btl/func_0801D288.s");
INCLUDE_ASM("btl/task_btl_lockon_1.s");
INCLUDE_ASM("btl/task_btl_lockon_2.s");
void task_btl_lockon_3(BtlLockonWork* work) {
    ReleaseObjTiles(work->unk_000);
    ReleaseObjPalette(work->unk_004);
}
void task_btl_area_0(BtlAreaWork* work) {
    work->unk_008 = 0;
    work->unk_000 = LoadObjPalette(gUnk_08F69BA4, 0x20);
    work->unk_004 = LoadObjTiles(gUnk_08B1EA00, 0xE0);
    work->unk_00A = 0;
    work->unk_009 = 1;
}
INCLUDE_ASM("btl/task_btl_area_1.s");
INCLUDE_ASM("btl/task_btl_area_2.s");
void task_btl_area_3(BtlAreaWork* work) {
    ReleaseObjTiles(work->unk_004);
    ReleaseObjPalette(work->unk_000);
}
void func_0801DC40(BtlSoraWork* work) {
    u16 a = work->unk_15A | 0x80;
    u16 b;

    work->unk_15A = a;
    b = work->unk_0B0 | 2;
    work->unk_0B0 = b;
}
void func_0801DC5C(BtlSoraWork* work) {
    u16 a = work->unk_15A & 0xFF7F;
    u16 b;

    work->unk_15A = a;
    b = work->unk_0B0 & 0xFFFD;
    work->unk_0B0 = b;
}
INCLUDE_ASM("btl/func_0801DC80.s");
INCLUDE_ASM("btl/func_0801DD08.s");
void func_0801DD90(BtlSoraWork* work) {
    s32 x;
    s32 y;
    s32 z;

    if (work->unk_172 != 0) {
        func_080140C0(&x, &y, &z);
        func_0802F284(x, gUnk_02039B84->unk_07C->unk_08, gUnk_02039B84->unk_07C->unk_0C);
    }
}
void func_0801DDC4(BtlSoraWork* work) {
    if (work->unk_172 != 0) {
        func_0802F284(work->unk_044, work->unk_048, work->unk_04C);
    }
}
INCLUDE_ASM("btl/func_0801DDE4.s");
INCLUDE_ASM("btl/func_0801DE1C.s");
INCLUDE_ASM("btl/func_0801DEB8.s");
INCLUDE_ASM("btl/func_0801DEF4.s");
INCLUDE_ASM("btl/func_0801DF10.s");
INCLUDE_ASM("btl/task_btl_sora_0.s");
void func_0801E4E4(BtlSoraWork* work, u32 a) {
    work->unk_038 = a;
    work->unk_156 = 0;
    work->unk_154 = 0;
    func_0801AF08(&work->unk_040);
}
INCLUDE_ASM("btl/func_0801E508.s");
INCLUDE_ASM("btl/func_0801E518.s");
INCLUDE_ASM("btl/func_0801E678.s");
INCLUDE_ASM("btl/func_0801E6DC.s");
INCLUDE_ASM("btl/func_0801E794.s");
INCLUDE_ASM("btl/func_0801E7D4.s");
INCLUDE_ASM("btl/task_btl_sora_1.s");
INCLUDE_ASM("btl/task_btl_sora_2.s");
INCLUDE_ASM("btl/task_btl_sora_3.s");
INCLUDE_ASM("btl/func_08027428.s");
INCLUDE_ASM("btl/func_08027444.s");
INCLUDE_ASM("btl/func_08027468.s");
INCLUDE_ASM("btl/func_080274F0.s");
INCLUDE_ASM("btl/func_0802753C.s");
INCLUDE_ASM("btl/func_08027570.s");
INCLUDE_ASM("btl/func_080275D4.s");
INCLUDE_ASM("btl/func_080276D4.s");
INCLUDE_ASM("btl/func_0802770C.s");
INCLUDE_ASM("btl/func_080277A8.s");
INCLUDE_ASM("btl/func_080277E4.s");
INCLUDE_ASM("btl/func_080277FC.s");
INCLUDE_ASM("btl/func_08027A64.s");
INCLUDE_ASM("btl/func_080280BC.s");
INCLUDE_ASM("btl/func_080280E0.s");
INCLUDE_ASM("btl/func_08028228.s");
INCLUDE_ASM("btl/func_0802828C.s");
INCLUDE_ASM("btl/func_0802830C.s");
INCLUDE_ASM("btl/func_08028370.s");
INCLUDE_ASM("btl/func_08028428.s");
INCLUDE_ASM("btl/func_08028468.s");
INCLUDE_ASM("btl/func_080284C8.s");
