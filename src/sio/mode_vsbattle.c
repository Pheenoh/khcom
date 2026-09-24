#include "macros.h"
#include "mode_vsbattle.h"

u8 gUnk_02039B98 EWRAM_COMMON(4);

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
    gBtlWork->bg = 2;
    gBtlWork->unk_1C6 = 3;
    SetupBg(3, 0, 12, 0);
    SetupBg(2, 2, 28, 10);
    SetBgPriority(3, 2);
    SetBgPriority(2, 0);
    SetBgOverflow(3, 1);
    SetBgOverflow(2, 0);
    TaskPoolInit(&gBtlWork->taskPools[0], 32);
    TaskPoolInit(&gBtlWork->taskPools[1], 32);
    BgFxInit(0x80, gBtlWork->bg);
    ColliderPoolsInit();

    if (mode == 0) {
        arg.unk_04 = 1;
        arg.unk_00 = 0;
        TaskCreate(&gBtlWork->taskPools[0], &gTaskDescBtlSora, &arg);
        arg.unk_04 = 0;
        arg.unk_00 = 1;
        TaskCreate(&gBtlWork->taskPools[0], &gTaskDescBtlSora, &arg);
        gBtlWork->flags |= 0x1000;
    } else {
        arg2.unk_04 = 0;
        arg2.unk_00 = 0;
        TaskCreate(&gBtlWork->taskPools[0], &gTaskDescBtlSora, &arg2);
        arg2.unk_04 = 1;
        arg2.unk_00 = 1;
        TaskCreate(&gBtlWork->taskPools[0], &gTaskDescBtlSora, &arg2);
    }

    SetBattleBounds((s16)(0x100 - gUnk_02039B90), (s16)(gUnk_02039B90 + 0x100),
                  (s16)gUnk_02039B88, (s16)gUnk_02039B8C);
    TaskCreate(&gBtlWork->taskPools[1], &gTaskDescBtlMap, 0);
    gUnk_02039B98 = 0;
    FadeStartIn(0, 60);
}

void mode_vsbattle_1(void) {
    if (gBtlWork->unk_070 == 0) {
        func_08010CC8();

        if (gBtlWork->unk_072 <= 0) {
            TaskPoolUpdate(&gBtlWork->taskPools[0]);
        } else {
            gBtlWork->unk_072--;
        }

        BgFxUpdate();
        ColliderUpdateAll();
        TaskPoolDraw(&gBtlWork->taskPools[1]);

        if (gBtlWork->flags & 0x800000) {
            gBtlWork->flags &= ~0x800000;
        }
    }

    TaskPoolDraw(&gBtlWork->taskPools[0]);
}

void mode_vsbattle_2(void) {
    BgFxFree();
    TaskPoolDestroy(&gBtlWork->taskPools[1]);
    TaskPoolDestroy(&gBtlWork->taskPools[0]);
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
        m4aSongNumStart(SONG_BGM_ALICE_BTL);
        break;
    case 3:
        m4aSongNumStart(SONG_BGM_ALADDIN_BATTLE);
        break;
    case 4:
        m4aSongNumStart(SONG_BGM_MARMAID_BATTLE);
        break;
    case 5:
        m4aSongNumStart(SONG_BGM_PINOCCHIO_BTL);
        break;
    case 6:
        m4aSongNumStart(SONG_BGM_HERCULES_BATTLE);
        break;
    case 7:
        m4aSongNumStart(SONG_BGM_HALLOWEEN_BTL);
        break;
    case 8:
        m4aSongNumStart(SONG_BGM_PETERPAN_BTL);
        break;
    case 10:
        m4aSongNumStart(SONG_BGM_HOLLOW_BATTLE);
        break;
    case 11:
        m4aSongNumStart(SONG_BGM_TOWN_BTL);
        break;
    case 9:
        m4aSongNumStart(SONG_BGM_DESTINY_BATTLE);
        break;
    case 12:
        m4aSongNumStart(SONG_BGM_F13F_FORGET_BATTLE);
        break;
    case 13:
        m4aSongNumStart(SONG_BGM_TWILIGHT_BATTLE);
        break;
    default:
        m4aSongNumStart(SONG_BGM_BOSS1_WORLD);
        break;
    }
}

Mode gModeVsbattle = { "mode_vsbattle", (ModeInitFunc)mode_vsbattle_0, mode_vsbattle_1, mode_vsbattle_2 };
