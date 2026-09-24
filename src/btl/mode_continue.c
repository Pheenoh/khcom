#include "mode_continue.h"
#include "continue_ui.h"
#include "registration_data.h"
#include "map_api.h"
#include "mode.h"
#include "m4a_song.h"
#include "mode_test.h"
#include "gba/keys.h"
#include "mode_test_api.h"


TaskPool gContinueTaskPool;
Task* gUnk_02034A5C;

static void Continue_0(void) {
    TaskPoolInit(&gContinueTaskPool, 2);

    if ((gGameState.flags & 8) == 0) {
        gUnk_02034A5C = TaskCreate(&gContinueTaskPool, &gUnk_09EE2834, 0);
    } else {
        gUnk_02034A5C = TaskCreate(&gContinueTaskPool, &gUnk_09EE284C, 0);
    }
}

void func_08060F1C(void) {
    ContinueWork* w;

    TaskPoolUpdate(&gContinueTaskPool);
    TaskPoolDraw(&gContinueTaskPool);
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

static void Continue_2(void) {
    TaskPoolDestroy(&gContinueTaskPool);
}

Mode gModeContinue = {
    "Continue",
    (ModeInitFunc)Continue_0,
    func_08060F1C,
    Continue_2,
};
