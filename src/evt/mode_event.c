#include "registration_data.h"
#include "map_api.h"
#include "mode.h"
#include "m4a_song.h"
#include "mode_test.h"
#include "gba/keys.h"
#include "mode_test_api.h"


TaskPool gEventTaskPool;
u8 gUnk_02034A74;
u32 gUnk_02034A78;
u8 gUnk_02034A7C;

#include "mode_event.h"

void Event_0(s32 arg) {
    EvtArg cfg;
    EventBackgroundDef* e;

    gEventState = EwramAlloc(0x8C);
    e = gUnk_09EE3CA0[arg & 0x7FFF];
    gBldCnt = 0;
    gBldAlpha = 0;
    gUnk_02034A78 = arg;
    gUnk_02034A74 = 0;

    if (e != 0) {
        if (e->unk_24 != 0) {
            SetBgMode1();
            SetupBg(0, 3, 31, 14);
            SetupBg(1, 0, 16, 0);
            SetupBg(2, 0, 17, 0);
            SetupBg(3, 0, 18, 0);
            SetBgPriority(0, 0);
            SetBgPriority(1, 1);
            SetBgPriority(2, 2);
            SetBgPriority(3, 3);
        } else {
            SetBgMode0();
            SetupBg(0, 3, 31, 14);
            SetupBg(1, 0, 21, 0);
            SetupBg(2, 0, 22, 0);
            SetupBg(3, 0, 23, 0);
            SetBgPriority(0, 0);
            SetBgPriority(1, 1);
            SetBgPriority(2, 2);
            SetBgPriority(3, 3);
            DisableBg(0);
            DisableBg(1);
            DisableBg(2);
            DisableBg(3);
        }
    } else {
        SetBgMode0();
        SetBgMode0();
        SetupBg(0, 0, 22, 0);
        SetupBg(1, 0, 24, 0);
        SetupBg(2, 2, 28, 14);
        SetBgPriority(0, 3);
        SetBgPriority(1, 2);
        SetBgPriority(2, 1);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
    }

    cfg.unk_00 = arg;
    gEventState->unk_74 = arg & 0x7FFF;

    if (arg & 0x8000) {
        cfg.unk_08 = 0;
    } else {
        cfg.unk_08 = 1;
    }

    if (gUnk_09EE3FB4[gUnk_02034A78 & 0x8000]->keyframes->unk_14 & 0x80) {
        FadeStartIn(1, 999);
    }

    TaskPoolInit(&gEventTaskPool, 2);
    TaskCreate(&gEventTaskPool, &gTaskDescEventSeq, &cfg);
    func_080A42B4();
    gUnk_02034A7C = 0;
}
void func_0806119C(void) {
    if (gEventState == 0) {
        ModeRequest(&gModeEventselect, 0);
    }

    if (gUnk_02034A74 == 0) {
        TaskPoolUpdate(&gEventTaskPool);
    } else if (GetKeysRepeat() & SELECT_BUTTON) {
        TaskPoolUpdate(&gEventTaskPool);
    }

    TaskPoolDraw(&gEventTaskPool);

    if (gEventState->unk_7A == 0) {
        if (gUnk_02034A7C == 0) {
            func_08061824();
            gUnk_02034A7C = 1;
        }

        if (gUnk_02034A7C == 1) {
            if (func_080A42C8() == 0) {
                ModeRequest(&gModeEventselect, 0);
            }
        }
    }

    if (GetKeysPressed() & START_BUTTON) {
        gUnk_02034A74 = 0;
    }
}

void func_08061248(void) {
    EventSequenceDef* p = gUnk_09EE3FB4[gUnk_02034A78];
    UpdatePlayTime();
    TaskPoolUpdate(&gEventTaskPool);
    TaskPoolDraw(&gEventTaskPool);
    if (gEventState->unk_7A != 0) {
        return;
    }
    if (gUnk_02034A7C == 0) {
        func_08061824();
        gUnk_02034A7C = 1;
    }
    if (gUnk_02034A7C != 1) {
        return;
    }
    if (func_080A42C8() != 0) {
        return;
    }
    func_08062D3C();
    if (func_080A42D4() == 1) {
        func_0806250C();
        func_08062CE4();
        return;
    }
    func_08061FC8();
    func_0806250C();
    func_080629F8();
    func_08062D20();
    if (gEventState->unk_85 != 0) {
        if (gEventState->unk_84 == 0) {
            if (func_080629CC() == 0) {
                func_080DF380();
                func_080E04EC();
            }
        } else {
            func_0806297C();
        }
        return;
    }
    if (p->unk_1A != 0) {
#ifdef VERSION_EU
        if (gUnk_02034A78 == 148) {
#else
        if (gUnk_02034A78 == 150) {
#endif
            ModeRequest(&gModeWorldselect, 0);
        } else {
            func_080DF380();
            func_080E04EC();
        }
        return;
    }
    if (p->unk_22 != 0xFFFF) {
        switch (p->unk_22) {
        case 12:
        case 14:
        case 17:
        case 20:
        case 23:
        case 28:
        case 32:
        case 35:
        case 38:
        case 42:
        case 47:
        case 50:
        case 53:
        case 58:
        case 68:
#ifdef VERSION_EU
        case 155:
        case 163:
        case 166:
        case 167:
        case 173:
        case 182:
        case 189:
#else
        case 157:
        case 165:
        case 168:
        case 169:
        case 175:
        case 184:
        case 191:
#endif
            func_080DF380();
            func_080E04EC();
            break;
        case 61:
            func_080DF480();
            func_080E04EC();
            break;
        default:
            ModeRequest(&gUnk_09EE274C, p->unk_22);
            break;
        }
        return;
    }
    if (p->unk_1B != 0) {
        if (p->unk_20 == 122) {
            gGameState.unk_00D = 7;
        } else if (p->unk_20 == 120) {
            gGameState.unk_00D = 1;
        } else if (p->unk_20 == 121) {
            gGameState.unk_00D = 5;
        } else if (p->unk_20 == 123) {
            gGameState.unk_00D = 3;
        } else if (p->unk_20 == 124) {
            gGameState.unk_00D = 3;
        }
        ModeRequest(&gModeBattle, p->unk_20);
        return;
    }
    if (p->unk_1C != 0) {
        FadeStartOut(0, 16);
        ModeRequest(&gModeTitle, 0);
        return;
    }
    if (p->unk_1D != 0) {
        ModeRequest(&gModeCopyright1, 0);
        return;
    }
    if (p->unk_1E != 0) {
        func_080DF380();
        ModeRequest(&gModeMapFld, 0);
        return;
    }
    if (p->unk_28 != 0xFFFF) {
        switch (p->unk_28) {
        case 2:
            ModeRequest(&gModeBattle, 178);
            break;
        case 4:
            ModeRequest(&gModeBattle, 179);
            break;
        case 12:
            ModeRequestHeapReset(&gModeMovie, 4);
            break;
        case 1:
            gGameState.unk_180 = 512;
            ModeRequest(&gModeWorldselect, 0);
            break;
        case 10:
            ModeRequestHeapReset(&gModeMovie, 2);
            break;
        case 11:
            ModeRequestHeapReset(&gModeMovie, 3);
            break;
        case 13:
            ModeRequestHeapReset(&gModeMovie, 5);
            break;
        case 3:
        case 5:
        case 6:
            func_080DF380();
            func_080E04EC();
            break;
        default:
            ModeRequest(&gModeDummy, p->unk_28);
            break;
        }
        return;
    }
    if (p->unk_2A != 0) {
        func_080DF380();
        func_080E04EC();
    } else if (p->unk_2B != 255) {
        func_080DF380();
        func_080E04EC();
    } else if (p->unk_2C != 255) {
        if (p->unk_2C == 0) {
            func_080DF380();
            ModeRequest(&gModePooh, 0);
        } else if (p->unk_2C <= 6) {
            ModeRequest(&gModePooh, 1);
        }
    }
}

void Event_2(void) {
    TaskPoolDestroy(&gEventTaskPool);
    EwramFree(gEventState);
    gEventState = 0;
}


Mode gUnk_09EE273C = {
    "Event",
    Event_0,
    func_0806119C,
    Event_2,
};

Mode gUnk_09EE274C = {
    "Event",
    Event_0,
    func_08061248,
    Event_2,
};
