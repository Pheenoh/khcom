#include "mode_test.h"


TaskPool gEventTaskPool;
u8 gUnk_02034A74;
u32 gUnk_02034A78;
u8 gUnk_02034A7C;

#include "msg.h"
#include "card_ids.h"

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

void func_0806180C(u16 a) {
    ModeRequest(&gUnk_09EE274C, a);
}
#ifdef VERSION_EU
#define MSG_CODE(n) ((n) - 2)
#else
#define MSG_CODE(n) (n)
#endif

void func_08061824(void) {
    SetBackdropColor(0, 0, 0);

    switch (gUnk_02034A78 & 0x7FFF) {
    case 41:
    case 49:
    case MSG_CODE(176):
    case MSG_CODE(185):
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        m4aSongNumStart(SONG_SYS_ITEMGET);
        CreateSysmsgwinTask(&gEventTaskPool, 173);
        break;
    case 34:
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        m4aSongNumStart(SONG_SYS_ITEMGET);
        CreateSysmsgwinTask(&gEventTaskPool, 133);
        break;
    case 88:
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        m4aSongNumStart(SONG_SYS_ITEMGET);
        CreateSysmsgwinTask(&gEventTaskPool, 134);
        break;
    case MSG_CODE(136):
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        m4aSongNumStart(SONG_SYS_ITEMGET);
        CreateSysmsgwinTask(&gEventTaskPool, 139);
        break;
    case MSG_CODE(137):
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        m4aSongNumStart(SONG_SYS_ITEMGET);
        CreateSysmsgwinTask(&gEventTaskPool, 160);
        break;
    case MSG_CODE(139):
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        m4aSongNumStart(SONG_SYS_ITEMGET);
        CreateSysmsgwinTask(&gEventTaskPool, 159);
        break;
    case MSG_CODE(140):
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        m4aSongNumStart(SONG_SYS_ITEMGET);
        CreateSysmsgwinTask(&gEventTaskPool, 136);
        break;
    case MSG_CODE(141):
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        m4aSongNumStart(SONG_SYS_ITEMGET);
        CreateSysmsgwinTask(&gEventTaskPool, 137);
        break;
    case MSG_CODE(142):
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        m4aSongNumStart(SONG_SYS_ITEMGET);
        CreateSysmsgwinTask(&gEventTaskPool, 135);
        break;
    case 61:
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        m4aSongNumStart(SONG_SYS_ITEMGET);
        CreateSysmsgwinTask(&gEventTaskPool, 138);
        break;
    case 126:
        m4aSongNumStart(SONG_SYS_ITEMGET);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        CreateSysmsgwinTask(&gEventTaskPool, 162);
        break;
    case 114:
        m4aSongNumStart(SONG_SYS_ITEMGET);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        CreateSysmsgwinTask(&gEventTaskPool, 161);
        break;
    case 57:
        m4aSongNumStart(SONG_SYS_ITEMGET);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        CreateSysmsgwinTask(&gEventTaskPool, 163);
        break;
    case MSG_CODE(143):
    case MSG_CODE(144):
        m4aSongNumStart(SONG_SYS_ITEMGET);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        CreateSysmsgwinTask(&gEventTaskPool, 165);
        break;
    case MSG_CODE(145):
    case MSG_CODE(146):
    case MSG_CODE(147):
    case MSG_CODE(148):
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        CreateSysmsgwinTask(&gEventTaskPool, 166);
        break;
    case 3:
    case 44:
    case 53:
    case 74:
    case 94:
    case 101:
    case 108:
    case 115:
    case 120:
    case MSG_CODE(129):
    case MSG_CODE(151):
    case MSG_CODE(177):
    case MSG_CODE(186):
    case MSG_CODE(192):
        m4aSongNumStart(SONG_SYS_ITEMGET);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        CreateSysmsgwinTask(&gEventTaskPool, 168);
        break;
    case 54:
    case 75:
    case 89:
    case 96:
    case 102:
    case 109:
    case 116:
    case 121:
    case MSG_CODE(130):
    case MSG_CODE(152):
    case MSG_CODE(188):
        m4aSongNumStart(SONG_SYS_ITEMGET);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        CreateSysmsgwinTask(&gEventTaskPool, 169);
        break;
    case 5:
        m4aSongNumStart(SONG_SYS_ITEMGET);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        CreateSysmsgwinTask(&gEventTaskPool, 175);
        break;
    case 6:
    case 80:
    case 90:
    case 97:
    case 103:
    case 111:
    case 117:
    case 123:
    case MSG_CODE(131):
    case MSG_CODE(153):
        m4aSongNumStart(SONG_SYS_ITEMGET);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        CreateSysmsgwinTask(&gEventTaskPool, 170);
        break;
    case 119:
        m4aSongNumStart(SONG_SYS_ITEMGET);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        CreateSysmsgwinTask(&gEventTaskPool, 172);
        break;
    case 60:
        m4aSongNumStart(SONG_SYS_ITEMGET);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        CreateSysmsgwinTask(&gEventTaskPool, 164);
        break;
    case 27:
    case MSG_CODE(156):
    case MSG_CODE(166):
        m4aSongNumStart(SONG_SYS_ITEMGET);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        FadeStartIn(0, 1);
        CreateSysmsgwinTask(&gEventTaskPool, 174);
        break;
    }
}
void func_08061FC8(void) {
    switch (gUnk_02034A78) {
    case 0:
        gGameState.progression.unk_84 = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 94:
        gGameState.progression.unk_84 = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 74:
        gGameState.progression.unk_84 = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 88:
        gGameState.progression.unk_84 = 19;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        func_0800FB2C(62);
        break;
    case 93:
        gGameState.progression.unk_84 = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 107:
        gGameState.progression.unk_84 = 7;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        func_0800FB2C(61);
        break;
    case 114:
        gGameState.progression.unk_84 = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 103:
        gGameState.progression.unk_84 = 11;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        func_0800FB2C(63);
        break;
    case 106:
        gGameState.progression.unk_84 = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case MSG_CODE(131):
        gGameState.progression.unk_84 = 67;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        func_0800FB2C(65);
        break;
    case MSG_CODE(133):
        gGameState.progression.unk_84 = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 117:
        gGameState.progression.unk_84 = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 116:
    case 118:
        gGameState.progression.unk_84 = 35;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        func_0800FB2C(64);
        break;
    case 119:
        gGameState.progression.unk_84 = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 120:
        gGameState.progression.unk_84 = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 44:
        gGameState.progression.unk_84 = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 59:
        gGameState.progression.unk_84 = 3;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case 52:
    case MSG_CODE(149):
        gGameState.progression.unk_84 = 0;
        func_0800FB2C(57);
        func_0800FB2C(59);
        func_0800FB2C(60);
        break;
    case MSG_CODE(155):
        gGameState.progression.unk_84 = 128;
        func_0800FB2C(69);
        break;
    case MSG_CODE(174):
    case MSG_CODE(186):
        gGameState.progression.unk_84 = 0;
        break;
    case MSG_CODE(185):
    case MSG_CODE(190):
        gGameState.progression.unk_84 = 128;
        break;
    case MSG_CODE(156):
        gGameState.flags &= ~0x100;
        func_0800FB2C(66);
        func_0800FB2C(67);
        func_0800FB2C(68);
        break;
    }
}
void func_0806250C(void) {
    switch (gUnk_02034A78) {
    case 0:
        gGameState.unk_180 = 0x200;
        break;
    case 5:
        func_08084458(CARD_ID(CARD_SIMBA, 6));
        break;
    case 11:
        gGameState.unk_180 = 61;
        break;
    case 27:
        gGameState.unk_180 = 0x4C2;
        break;
    case 41:
        gGameState.unk_180 = 0x800;
        break;
    case 49:
        gGameState.unk_180 = 256;
        break;
    case 60:
        gGameState.unk_180 = 0x1000;
        func_08084458(CARD_ID(CARD_OBLIVION, 6));
        break;
    case 57:
        func_08084458(CARD_ID(CARD_OATHKEEPER, 4));
        break;
    case 3:
    case 44:
    case 53:
    case 61:
    case 74:
    case 88:
    case 94:
    case 101:
    case 108:
    case 115:
    case 120:
    case MSG_CODE(129):
    case MSG_CODE(151):
    case MSG_CODE(177):
    case MSG_CODE(186):
    case MSG_CODE(192):
        AddMapCard(221);
        break;
    case 4:
    case 54:
    case 75:
    case 89:
    case 96:
    case 102:
    case 109:
    case 116:
    case 121:
    case MSG_CODE(130):
    case MSG_CODE(152):
    case MSG_CODE(188):
        AddMapCard(231);
        break;
    case 6:
    case 80:
    case 90:
    case 97:
    case 103:
    case 111:
    case 117:
    case 123:
    case MSG_CODE(131):
    case MSG_CODE(153):
        AddMapCard(241);
        break;
    case 114:
        func_08084458(CARD_ID(CARD_GENIE, 6));
        break;
    case 119:
        func_08084458(CARD_ID(CARD_TINKER_BELL, 4));
        break;
    case 126:
        func_08084458(CARD_ID(CARD_CLOUD, 4));
        break;
    case MSG_CODE(137):
        func_08084458(CARD_ID(CARD_SPELLBINDER, 4));
        break;
    case MSG_CODE(139):
        func_08084458(CARD_ID(CARD_ELIXIR, 1));
        break;
    case MSG_CODE(143):
    case MSG_CODE(144):
        func_08084458(CARD_ID(CARD_BAMBI, 5));
        break;
    case MSG_CODE(149):
        gGameState.unk_180 = 128;
        break;
    case MSG_CODE(156):
        gGameState.unk_180 = 593;
        break;
    case MSG_CODE(166):
        gGameState.unk_180 = 46;
        break;
    case MSG_CODE(176):
        gGameState.unk_180 = 256;
        break;
    case MSG_CODE(185):
        gGameState.unk_180 = 0x800;
        break;
    case MSG_CODE(191):
        gGameState.unk_180 = 0x1000;
        break;
    }
}
void func_0806297C(void) {
    EventSequenceDef* m = gUnk_09EE3FB4[gUnk_02034A78];

    switch (gUnk_02034A78) {
    case 68:
        ModeRequest(&gUnk_09EE274C, 69);
        break;
    case 83:
    case 84:
        gGameState.unk_00D = 5;
        ModeRequest(&gModeBattle, m->unk_20);
        break;
    }
}
u8 func_080629CC(void) {
    switch (gUnk_02034A78) {
    case 0x44:
    case 0x53:
    case 0x54:
        func_080E04EC();
        return 1;
    }
    return 0;
}
void func_080629F8(void) {
    switch (gUnk_02034A78) {
    case 2:
        func_0800FC14(0);
        break;
    case MSG_CODE(136):
        func_0800FB2C(41);
        break;
    case MSG_CODE(140):
        func_0800FB2C(40);
        break;
    case MSG_CODE(141):
        func_0800FB2C(50);
        break;
    case MSG_CODE(142):
        func_0800FB2C(43);
        break;
    case 34:
        func_0800FB2C(38);
        break;
    case 88:
        func_0800FB2C(42);
        break;
    case 108:
        func_0800FC14(1);
        break;
    case 74:
        func_0800FC14(5);
        break;
    case 120:
        func_0800FC14(8);
        break;
    case 94:
        func_0800FC14(10);
        break;
    case 101:
        func_0800FC14(2);
        break;
    case 115:
        func_0800FC14(4);
        break;
    case MSG_CODE(129):
        func_0800FC14(11);
        break;
    case 87:
        func_0800FC14(3);
        break;
    case 59:
        func_0800FC14(13);
        break;
    case 61:
        func_0800FB2C(8);
        break;
    case 67:
        func_0800FC14(15);
        func_0800FC14(16);
        break;
    }
}
#ifdef VERSION_EU
#define MSG_SAVE_ID_LO 0x8D
#else
#define MSG_SAVE_ID_LO 0x8F
#endif

void func_08062CE4(void) {
    switch (gUnk_02034A78) {
    case MSG_SAVE_ID_LO + 0:
    case MSG_SAVE_ID_LO + 1:
    case MSG_SAVE_ID_LO + 2:
    case MSG_SAVE_ID_LO + 3:
    case MSG_SAVE_ID_LO + 4:
    case MSG_SAVE_ID_LO + 5:
        if (gGameState.flags & 0x10) {
            SaveWriteFileLarge(1);
        } else {
            SaveWriteFileLarge(0);
        }
        func_080DF828();
        break;
    }
}
void func_08062D20(void) {
    switch (gUnk_02034A78) {
    case MSG_SAVE_ID_LO + 0:
    case MSG_SAVE_ID_LO + 1:
    case MSG_SAVE_ID_LO + 2:
    case MSG_SAVE_ID_LO + 3:
    case MSG_SAVE_ID_LO + 4:
    case MSG_SAVE_ID_LO + 5:
        func_080DF828();
        break;
    }
}
void func_08062D3C(void) {
    switch (gUnk_02034A78) {
    case 0x43:
        func_0800FDD0(16);
        break;
    case 0x3F:
        func_0800FDD0(41);
        break;
    }
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
