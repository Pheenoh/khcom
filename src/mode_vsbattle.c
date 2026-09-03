#include "mode_vsbattle.h"
#include "macros.h"

u8 gUnk_02039B98;

void mode_vsbattle_0(u32 mode) {
    VsTaskArg arg;
    VsTaskArg arg2;
    BtlWork** p;

    gBtlWork = EwramAlloc(sizeof(BtlWork));
    p = &gUnk_02039B9C;
    *p = EwramAlloc(sizeof(BtlWork));

    if (gSioPlayerId == 0) {
        SeedRandom(gUnk_0203AAC0.unk_1E);
    } else {
        SeedRandom(gUnk_0203AA10.unk_1E);
    }

    func_0801071C();
    func_0801C068();
    func_0800C6B8();
    SetBgMode2();
    gBtlWork->unk_1C4 = 2;
    gBtlWork->unk_1C6 = 3;
    SetupBg(3, 0, 12, 0);
    SetupBg(2, 2, 28, 10);
    SetBgPriority(3, 2);
    SetBgPriority(2, 0);
    SetBgOverflow(3, 1);
    SetBgOverflow(2, 0);
    TaskPoolInit(&gBtlWork->unk_02C, 32);
    TaskPoolInit(&gBtlWork->unk_040, 32);
    func_08012798(0x80, gBtlWork->unk_1C4);
    func_0801227C();

    if (mode == 0) {
        arg.unk_04 = 1;
        arg.unk_00 = 0;
        TaskCreate(&gBtlWork->unk_02C, &gTaskDescBtlSora, &arg);
        arg.unk_04 = 0;
        arg.unk_00 = 1;
        TaskCreate(&gBtlWork->unk_02C, &gTaskDescBtlSora, &arg);
        gBtlWork->unk_068 |= 0x1000;
    } else {
        arg2.unk_04 = 0;
        arg2.unk_00 = 0;
        TaskCreate(&gBtlWork->unk_02C, &gTaskDescBtlSora, &arg2);
        arg2.unk_04 = 1;
        arg2.unk_00 = 1;
        TaskCreate(&gBtlWork->unk_02C, &gTaskDescBtlSora, &arg2);
    }

    func_0801A920(0x100 - gUnk_02039B90, gUnk_02039B90 + 0x100, gUnk_02039B88, gUnk_02039B8C);
    TaskCreate(&gBtlWork->unk_040, &gTaskDescBtlMap, 0);
    gUnk_02039B98 = 0;
    func_08006120(0, 60);
}

void mode_vsbattle_1(void) {
    if (gBtlWork->unk_070 == 0) {
        func_08010CC8();

        if (gBtlWork->unk_072 <= 0) {
            TaskPoolUpdate(&gBtlWork->unk_02C);
        } else {
            gBtlWork->unk_072--;
        }

        func_08012824();
        func_080125A4();
        TaskPoolDraw(&gBtlWork->unk_040);

        if (gBtlWork->unk_068 & 0x800000) {
            gBtlWork->unk_068 &= ~0x800000;
        }
    }

    TaskPoolDraw(&gBtlWork->unk_02C);
}

void mode_vsbattle_2(void) {
    func_08012810();
    TaskPoolDestroy(&gBtlWork->unk_040);
    TaskPoolDestroy(&gBtlWork->unk_02C);
    func_0801C104();
    EwramFree(gUnk_02039B9C);
    EwramFree(gBtlWork);
}

void func_0800C6B0(void) {
}

void func_0800C6B4(void) {
}

void func_0800C6B8(void) {
    switch (gGameState.unk_00D) {
    case 1:
        m4aSongNumStart(1);
        break;
    case 3:
        m4aSongNumStart(23);
        break;
    case 4:
        m4aSongNumStart(17);
        break;
    case 5:
        m4aSongNumStart(9);
        break;
    case 6:
        m4aSongNumStart(20);
        break;
    case 7:
        m4aSongNumStart(16);
        break;
    case 8:
        m4aSongNumStart(11);
        break;
    case 10:
        m4aSongNumStart(26);
        break;
    case 11:
        m4aSongNumStart(12);
        break;
    case 9:
        m4aSongNumStart(40);
        break;
    case 12:
        m4aSongNumStart(39);
        break;
    case 13:
        m4aSongNumStart(43);
        break;
    default:
        m4aSongNumStart(3);
        break;
    }
}

ALIGN_ZERO(2);
