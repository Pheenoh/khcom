#include "mode_deck.h"
#include "registration_data.h"
#include "map_api.h"
#include "mode.h"
#include "m4a_song.h"
#include "mode_test.h"
#include "gba/keys.h"
#include "mode_test_api.h"


static TaskPool gUnk_02034A30;
static u8 gUnk_02034A44;

void func_08060A74(void) {
    gUnk_02034A44 = 0;
    TaskPoolInit(&gUnk_02034A30, 1);

    if ((gGameState.flags & 8) == 0) {
        TaskCreate(&gUnk_02034A30, &gUnk_09EE4AF4, &gUnk_02034A44);
    } else {
        TaskCreate(&gUnk_02034A30, &gUnk_09EE8EF0, &gUnk_02034A44);
    }

    if (gSystemFlags & 1) {
        m4aMPlayAllStop();
    }
}

void func_08060AD8(void) {
    if (gSystemFlags & 1) {
        func_080B0754();
    } else {
        UpdatePlayTime();
    }

    TaskPoolUpdate(&gUnk_02034A30);
    TaskPoolDraw(&gUnk_02034A30);

    if (gUnk_02034A44 == 7) {
        if (gUnk_03006C10 & 1) {
            ModeRequest(&gModeChkbtl, 0);
        } else if (gSystemFlags & 1) {
            ModeRequest(&gModeSioBtlOption, 1);
        } else {
            func_080E052C(0);
        }
    }

    if (gUnk_02034A44 == 8) {
        if (gUnk_03006C10 & 1) {
            ModeRequest(&gModeChkbtl, 0);
        } else if (gSystemFlags & 1) {
            ModeRequest(&gModeSioBtlOption, 1);
        } else {
            func_080E052C(1);
        }
    }
}

void func_08060BAC(void) {
    TaskPoolDestroy(&gUnk_02034A30);
}
void menu_0(MenuWork* w) {
    gUnk_02039BA0->unk_70 |= 0x1000;
    gUnk_02039BA0->unk_70 |= 0x80;
    gUnk_02039BA0->unk_70 |= 0x2000;
    w->x = 0xF000;
    w->y = 0x4800;
    w->unk_11 = 0;
    w->unk_10 = 0;
    w->tiles = LoadObjTiles(gUnk_090D4DD0, 0x2E80);
    w->palette = LoadObjPalette(gUnk_096148B8, 0x20);
    m4aSongNumStart(103);
}

u8 menu_1(MenuWork* w) {
    switch (w->unk_10) {
    case 0:
        w->x += (0xBC00 - w->x) >> 1;

        if ((w->x >> 8) == 0xBC) {
            w->unk_10 = 1;
        }

        if (GetKeysPressed() & B_BUTTON) {
            w->unk_10 = 4;
        }

        break;
    case 1:
        if (GetKeysRepeat() & DPAD_UP) {
            if (w->unk_11 != 0) {
                w->unk_11--;
            } else {
                w->unk_11 = 5;
            }

            m4aSongNumStart(101);
        }

        if (GetKeysRepeat() & DPAD_DOWN) {
            if (w->unk_11 <= 4) {
                w->unk_11++;
            } else {
                w->unk_11 = 0;
            }

            m4aSongNumStart(101);
        }

        if (GetKeysPressed() & A_BUTTON) {
            switch (w->unk_11) {
            case 0:
                w->unk_10 = 2;
                w->unk_11 = 6;
                m4aSongNumStart(103);
                break;
            case 2:
                func_0801CB0C();
                FadeStartOut(0, 32);
                w->unk_10 = 4;
                m4aSongNumStart(102);
                break;
            case 1:
            case 3:
            case 4:
                m4aSongNumStart(105);
                break;
            case 5:
                m4aSongNumStart(105);
                break;
            }
        }

        if (GetKeysPressed() & B_BUTTON) {
            w->unk_10 = 5;
            m4aSongNumStart(104);
        }

        break;
    case 2:
        if (GetKeysRepeat() & DPAD_UP) {
            if (w->unk_11 > 6) {
                w->unk_11--;
            } else {
                w->unk_11 = 9;
            }

            m4aSongNumStart(101);
        }

        if (GetKeysRepeat() & DPAD_DOWN) {
            if (w->unk_11 <= 8) {
                w->unk_11++;
            } else {
                w->unk_11 = 6;
            }

            m4aSongNumStart(101);
        }

        if (GetKeysPressed() & B_BUTTON) {
            w->unk_10 = 1;
            w->unk_11 = 0;
            m4aSongNumStart(104);
        }

        if (GetKeysPressed() & A_BUTTON) {
            switch (w->unk_11) {
            case 6:
                w->unk_11 = 0;
                w->unk_10 = 1;
                m4aSongNumStart(102);
                break;
            case 7:
                w->unk_11 = 0;
                w->unk_10 = 1;
                m4aSongNumStart(102);
                break;
            case 8:
                w->unk_11 = 0;
                w->unk_10 = 1;
                m4aSongNumStart(102);
                break;
            case 9:
                func_0801CB0C();
                FadeStartOut(0, 32);
                w->unk_10 = 4;
                m4aSongNumStart(102);
                break;
            }
        }

        break;
    case 4:
        w->x += (0x11800 - w->x) >> 1;

        if ((w->x >> 8) > 274) {
            if (FadeIsActive() == 0) {
                if (w->unk_11 != 2) {
                    if (w->unk_11 == 9) {
                        ModeRequest(&gModeDeck, 0);
                    }
                } else {
                    ModeRequest(&gModeAllmap, 0);
                }

                w->unk_10 = 5;
            }
        }

        break;
    case 5:
        w->x += (0x11800 - w->x) >> 1;

        if ((w->x >> 8) > 274) {
            return 0;
        }

        break;
    case 3:
    default:
        break;
    }

    return 1;
}

void menu_2(MenuWork* w) {
    DrawSprite(w->x >> 8, w->y >> 8, gUnk_09EEC600[w->unk_11], w->tiles, w->palette, 0, 0, 80);
}

void menu_3(MenuWork* w) {
    ReleaseObjTiles(w->tiles);
    ReleaseObjPalette(w->palette);
    gUnk_02039BA0->unk_70 &= ~0x1000;
    gUnk_02039BA0->unk_70 &= ~0x80;
    gUnk_02039BA0->unk_70 &= ~0x2000;
}


const char gModeNameDeck[] = "Mode_Deck";
const char gTaskNameMenu[] = "menu";
Mode gModeDeck = { gModeNameDeck, (void (*)(s32))func_08060A74, func_08060AD8, func_08060BAC };

TaskDesc gUnk_09EE2714 = { gTaskNameMenu, (void (*)(void*, void*))menu_0, menu_1, (void (*)(void*))menu_2, (void (*)(void*))menu_3, sizeof(MenuWork) };
