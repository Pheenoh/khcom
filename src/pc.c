#include "macros.h"
#include "pc.h"

void task_pc_acddmg_0(PcAcdDmgWork* work, UnkStruct_02039B84* obj) {
    work->unk_04 = obj;
    work->unk_02 = 0;
    work->unk_00 = 0x28;
    work->unk_08 = 0;
}

s32 task_pc_acddmg_1(PcAcdDmgWork* work) {
    UnkStruct_02039B84* obj;

    if (!(gUnk_02039B84->unk_068 & 0x100000)) {
        obj = work->unk_04;
        if (obj->unk_00C >= 0) {
            work->unk_08 = 1;

            if (work->unk_00 <= 0) {
                if (work->unk_02 % 60 == 0) {
                    obj->unk_034 |= 0x20000000;
                }
                work->unk_02++;
            } else {
                work->unk_00--;
            }
        } else {
            if (work->unk_08 != 0) {
                work->unk_08 = 0;
                work->unk_02 = 0;
                work->unk_00 = 0;
            }

            if (!(gUnk_02039B84->unk_068 & 0x8000)) {
                work->unk_00 = 0x28;
            }
        }
    }
    return 1;
}

void func_08049E70(PcCharaWork* work, s16 a, s32 b) {
    PcCharaWork* w = work;
    UnkStruct_02039B84* obj = (UnkStruct_02039B84*)work->unk_040;

    if (obj->unk_034 & 4) {
        work->unk_15C = obj->unk_004 - (a << 8);
    } else {
        work->unk_15C = obj->unk_004 + (a << 8);
    }
    w->unk_160 = obj->unk_008;
    w->unk_170 = 0x19;
    w->unk_150 = 0;
    work->unk_188 = -b;
    work->unk_18C = 0;
}

void func_08049EE4(PcCharaWork* work, s32 a, s32 b) {
    work->unk_15C = a;
    work->unk_160 = b;
    work->unk_170 = 0x19;
    work->unk_150 = 0;
    work->unk_188 = -0x500;
    work->unk_190 = 0;
}

void func_08049F24(PcCharaWork* work, s32 a, s32 b) {
    work->unk_15C = a;
    work->unk_160 = b;
    work->unk_170 = 0x21;
    work->unk_150 = 0;
}

s32 func_08049F50(PcCharaWork* work) {
    s32 x;
    s32 y;
    UnkStruct_02039B84* obj;

    obj = (UnkStruct_02039B84*)gUnk_02039B84->unk_07C;

    if ((u16)GetRandom() % 60 == 0) {
        func_0801C700(work->unk_040, &x, &y, 0);
        func_0800F368(work, 1);

        if (func_0800F504(work, 0x100, 0x100, 0x100)) {
            if (gUnk_02039B84->unk_068 & 0x8000) {
                func_08049E70(work, -0x63, 0x280);
            } else if (GetRandom() & 1) {
                if (obj->unk_034 & 4) {
                    func_08049EE4(work, x + 0x2800, y);
                } else {
                    func_08049EE4(work, x - 0x2800, y);
                }
            } else {
                func_08049E70(work, -0x50, 0x500);
            }
            return 1;
        }
    }
    return 0;
}
