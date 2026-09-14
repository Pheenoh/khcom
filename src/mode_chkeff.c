#include "display.h"
#include "mode_chkeff.h"
#include "movie_debug_data.h"
#include "gba/keys.h"

ChkEffWork* gChkEffWork;
#ifdef VERSION_EU
MovieDebugWork* gUnkEu_020348C4;
extern u8 gUnkEu_08F6A73C[];
extern u8 gUnkEu_08F79038[];
#endif

const char gUnk_081309E0[8] = "PAUSE";
const char gUnk_081309E8[8] = "     ";
const char gUnk_081309F0[40] = "                                      ";
const char gUnk_08130A18[8] = "alp A";
const char gUnk_08130A20[8] = "alp B";
const char gUnk_08130A28[8] = "scale";
const char gUnk_08130A30[4] = "num";
const char gUnk_08130A34[4] = "pic";
const char gUnk_08130A38[8] = "frame";

void mode_chkeff_0(void) {
    gChkEffWork = EwramAlloc(sizeof(ChkEffWork));
    SetBgMode1();
    SetupBg(0, 0, 7, 0);
    SetupBg(1, 1, 12, 8);
    SetupBg(2, 2, 28, 10);
    SetBgBlend(2, 16, 16);
    SetBgPriority(2, 0);
    SetBgPriority(0, 1);
    SetBgPriority(1, 2);
#ifdef VERSION_EU
    eu_080059D4(1, gUnkEu_08F6A73C);
    eu_080059F4(1, gUnkEu_08F79038);
    LoadBgPalette(1, gUnk_08F683C4, 0x20);
#else
    LoadBgTiles(1, gUnk_08C6B0C4, 0x7C20);
    LoadBgPalette(1, gUnk_08F683C4, 0x20);
    LoadBgMap(1, gUnk_08EEE384, 0x800);
#endif
    FadeSetPaletteExcluded(8, 1);
    FadeSetPaletteExcluded(9, 1);
    FadeSetPaletteExcluded(10, 1);
    FadeSetPaletteExcluded(11, 1);
    FadeSetPaletteExcluded(12, 1);
    FadeSetPaletteExcluded(13, 1);
    FadeSetPaletteExcluded(14, 1);
    FadeSetPaletteExcluded(15, 1);
    BgAnimInit(2, 0x8000, 0x80);
    TaskPoolInit(&gChkEffWork->pool, 1);
    TaskCreate(&gChkEffWork->pool, &gTaskDescPrint, 0);
    gChkEffWork->unk_14 = 0;
    gChkEffWork->paused = 0;
    gChkEffWork->scrollX = 0;
    gChkEffWork->scrollY = 0;
    gChkEffWork->scale = 0x100;
    gChkEffWork->unk_1C = 0;
    gChkEffWork->alphaA = 16;
    gChkEffWork->alphaB = 16;
    BgAnimStart(gUnk_09ED9A1C[0], 0x78, 0x50);
}

void mode_chkeff_1(void) {
    ChkEffWork** wp;
    void* obj;
    s16 prev;
    u16 a;
    u16 b;

    if (GetKeysPressed() & 2) {
        ModeRequest(&gModeDebug, 0);
    } else {
        if (GetKeysPressed() & 8) {
            gChkEffWork->paused = !gChkEffWork->paused;
        }

        prev = gChkEffWork->unk_14;

        if (GetKeysRepeat() & DPAD_LEFT) {
            gChkEffWork->unk_14--;
        }

        if (GetKeysRepeat() & DPAD_RIGHT) {
            gChkEffWork->unk_14++;
        }

        if (gChkEffWork->unk_14 < 0) {
            gChkEffWork->unk_14 = 82;
        }

        if ((u16)gChkEffWork->unk_14 > 82) {
            gChkEffWork->unk_14 = 0;
        }

        obj = gUnk_09ED9A1C[gChkEffWork->unk_14];

        if (prev != gChkEffWork->unk_14) {
            gChkEffWork->paused = 0;
            BgAnimStart(obj, 120, 80);
        }

        if (GetKeysRepeat() & DPAD_UP) {
            gChkEffWork->scale += 8;
        } else if (GetKeysRepeat() & DPAD_DOWN) {
            gChkEffWork->scale -= 8;
        }

        if (GetKeysPressed() & 4) {
            gChkEffWork->scale = 0x100;
            gChkEffWork->unk_1C = 0;
        }

        if (GetKeysRepeat() & L_BUTTON) {
            gChkEffWork->alphaA++;
            gChkEffWork->alphaA %= 17;
        }

        if (GetKeysRepeat() & R_BUTTON) {
            gChkEffWork->alphaB++;
            gChkEffWork->alphaB %= 17;
        }

        if (gChkEffWork->scale <= 9) {
            gChkEffWork->scale = 10;
        }

        if (gChkEffWork->scale > 0xA00) {
            gChkEffWork->scale = 0xA00;
        }

        if (BgAnimIsStopped() && (GetKeysHeld() & 1)) {
            BgAnimStart(obj, 120, 80);
        }

        if (gChkEffWork->paused != 0) {
            func_0809D2B0(0, 0, 0, gUnk_081309E0);
        } else {
            func_0809D2B0(0, 0, 0, gUnk_081309E8);
        }

        wp = &gChkEffWork;
        func_0809D2B0(0, 14, 0, gUnk_081309F0);
        func_0809D2B0(0, 15, 0, gUnk_081309F0);
        func_0809D2B0(0, 16, 0, gUnk_081309F0);
        func_0809D2B0(0, 17, 0, gUnk_081309F0);
        func_0809D2B0(0, 18, 0, gUnk_081309F0);
        func_0809D2B0(0, 19, 0, gUnk_081309F0);
        BgAnimGetFrameState(&a, &b);
        func_0809D2B0(0, 14, 0, gUnk_08130A18);
        func_0809D458(6, 14, 0, (*wp)->alphaA);
        func_0809D2B0(0, 15, 0, gUnk_08130A20);
        func_0809D458(6, 15, 0, (*wp)->alphaB);
        func_0809D2B0(0, 16, 0, gUnk_08130A28);
        func_0809D458(6, 16, 0, (*wp)->scale);
        func_0809D2B0(0, 17, 0, gUnk_08130A30);
        func_0809D458(6, 17, 0, (*wp)->unk_14);
        func_0809D2B0(0, 18, 0, gUnk_08130A34);
        func_0809D458(6, 18, 0, a);
        func_0809D2B0(0, 19, 0, gUnk_08130A38);
        func_0809D458(6, 19, 0, b);
        TaskPoolUpdate(&(*wp)->pool);
        TaskPoolDraw(&(*wp)->pool);
        BgAnimSetTransform((*wp)->unk_1C, (*wp)->scale, (*wp)->scale);
        SetBlendAlpha((*wp)->alphaA, (*wp)->alphaB);

        if ((*wp)->paused == 0 || (GetKeysRepeat() & 1)) {
            BgAnimUpdate();
        }

        SetBgScroll(1, gChkEffWork->scrollX, gChkEffWork->scrollY);

        if ((gFrameCounter & 3) == 0) {
            gChkEffWork->scrollY--;
        }
    }
}

void mode_chkeff_2(void) {
    TaskPoolDestroy(&gChkEffWork->pool);
    EwramFree(gChkEffWork);
}

#ifdef VERSION_EU
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
#endif

const char gModeNameChkeff[12] = "mode_chkeff";
