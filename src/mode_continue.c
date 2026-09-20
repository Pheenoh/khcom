#include "mode_continue.h"
#include "registration_data.h"
#include "map_api.h"
#include "mode.h"
#include "m4a_song.h"
#include "mode_test.h"
#include "gba/keys.h"
#include "mode_test_api.h"


TaskPool gUnk_02034A48;
Task* gUnk_02034A5C;

void func_08060ED8(void) {
    TaskPoolInit(&gUnk_02034A48, 2);

    if ((gGameState.flags & 8) == 0) {
        gUnk_02034A5C = TaskCreate(&gUnk_02034A48, &gUnk_09EE2834, 0);
    } else {
        gUnk_02034A5C = TaskCreate(&gUnk_02034A48, &gUnk_09EE284C, 0);
    }
}

void func_08060F1C(void) {
    ContinueWork* w;

    TaskPoolUpdate(&gUnk_02034A48);
    TaskPoolDraw(&gUnk_02034A48);
    w = gUnk_02034A5C->work;

    if (w->unk_6A == 3) {
        switch (w->unk_60) {
        case 0:
            func_080E04EC();
            break;
        case 1:
#ifdef VERSION_EU
            eu_0800115C();
#else
            SoftReset(255);
#endif
            break;
        }
    }
}

void func_08060F64(void) {
    TaskPoolDestroy(&gUnk_02034A48);
}

const char gModeNameContinue[] = "Continue";

Mode gModeContinue = {
    gModeNameContinue,
    (void (*)(s32))func_08060ED8,
    (void (*)(void))func_08060F1C,
    (void (*)(void))func_08060F64,
};
