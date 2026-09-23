#include "card_api.h"
#include "display.h"
#include "gba/keys.h"
#include "key.h"
#include "malloc.h"
#include "mode_chkmov.h"
#include "registration_data.h"
#include "taskpool.h"

#ifdef VERSION_EU

MovieDebugWork* gUnkEu_020348C4;

extern const char gMovieDebugTextEu_0812F6A8[];
extern const char gMovieDebugTextEu_0812F6B4[];
extern const char gMovieDebugTextEu_0812F6BC[];
extern const char gMovieDebugTextEu_0812F6C4[];
extern const char gMovieDebugTextEu_0812F6CC[];
extern const char gMovieDebugTextEu_0812F6D4[];
extern const char gMovieDebugTextEu_0812F6F4[];
extern const char gMovieDebugTextEu_0812F6F8[];

extern const MovieDebugEntry gMovieDebugEntriesEu[5];

void eu_0800C76C(s32 arg) {
    gUnkEu_020348C4 = EwramAlloc(sizeof(MovieDebugWork));
    SetBgMode0();
    gUnkEu_020348C4->index = 0;
    TaskPoolInit(&gUnkEu_020348C4->pool, 10);
    TaskCreate(&gUnkEu_020348C4->pool, &gTaskDescPrint, 0);
}

void eu_0800C7A0(void) {
    u16 cancel = GetKeysPressed() & B_BUTTON;

    if (cancel) {
        ModeRequest(&gModeDebug, 0);
        return;
    }

    if (GetKeysRepeat() & DPAD_LEFT) {
        gUnkEu_020348C4->index--;
    }

    if (GetKeysRepeat() & DPAD_RIGHT) {
        gUnkEu_020348C4->index++;
    }

    if (gUnkEu_020348C4->index < 0) {
        gUnkEu_020348C4->index = 4;
    }

    if (gUnkEu_020348C4->index > 4) {
        gUnkEu_020348C4->index = 0;
    }

    if (GetKeysPressed() & A_BUTTON) {
        ModeRequestHeapReset(&gModeMovie, gMovieDebugEntriesEu[gUnkEu_020348C4->index].movie);
        return;
    }

    func_0809D2B0(0, 0, 0, gMovieDebugTextEu_0812F6D4);
    func_0809D458(0, 0, 0, gUnkEu_020348C4->index);
    func_0809D2B0(5, 0, 0, gMovieDebugTextEu_0812F6F4);
    func_0809D2B0(7, 0, 0, gMovieDebugEntriesEu[gUnkEu_020348C4->index].label);
    TaskPoolUpdate(&gUnkEu_020348C4->pool);
    TaskPoolDraw(&gUnkEu_020348C4->pool);
}

void eu_0800C898(void) {
    TaskPoolDestroy(&gUnkEu_020348C4->pool);
    EwramFree(gUnkEu_020348C4);
}

const MovieDebugEntry gMovieDebugEntriesEu[5] = {
    {1, gMovieDebugTextEu_0812F6CC},
    {2, gMovieDebugTextEu_0812F6C4},
    {3, gMovieDebugTextEu_0812F6BC},
    {4, gMovieDebugTextEu_0812F6B4},
    {5, gMovieDebugTextEu_0812F6A8},
};

const char gMovieDebugTextEu_0812F6A8[] = "RIKU_ENDING";

const char gMovieDebugTextEu_0812F6B4[] = "ENDING";

const char gMovieDebugTextEu_0812F6BC[] = "12F_E2";

const char gMovieDebugTextEu_0812F6C4[] = "6F_GOAL";

const char gMovieDebugTextEu_0812F6CC[] = "OPENING";

const char gMovieDebugTextEu_0812F6D4[] = "                              ";

const char gMovieDebugTextEu_0812F6F4[] = ": ";

const char gMovieDebugTextEu_0812F6F8[] = "mode_chkmov";

Mode gModeMovieDebugEu = {
    gMovieDebugTextEu_0812F6F8,
    eu_0800C76C,
    eu_0800C7A0,
    eu_0800C898,
};

#endif
