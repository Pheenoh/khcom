#include "macros.h"
#include "mode_chkeff.h"

ChkEffWork* gChkEffWork;
#ifdef VERSION_EU
u32 gUnkEu_020348C4;
#endif
#include "gba/keys.h"

const char gUnk_081309E0[8] = "PAUSE";
const char gUnk_081309E8[8] = "     ";
const char gUnk_081309F0[40] = "                                      ";
const char gUnk_08130A18[8] = "alp A";
const char gUnk_08130A20[8] = "alp B";
const char gUnk_08130A28[8] = "scale";
const char gUnk_08130A30[4] = "num";
const char gUnk_08130A34[4] = "pic";
const char gUnk_08130A38[8] = "frame";

#ifndef VERSION_EU
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
    LoadBgTiles(1, gUnk_08C6B0C4, 0x7C20);
    LoadBgPalette(1, gUnk_08F683C4, 0x20);
    LoadBgMap(1, gUnk_08EEE384, 0x800);
    func_080062F4(8, 1);
    func_080062F4(9, 1);
    func_080062F4(10, 1);
    func_080062F4(11, 1);
    func_080062F4(12, 1);
    func_080062F4(13, 1);
    func_080062F4(14, 1);
    func_080062F4(15, 1);
    func_080065FC(2, 0x8000, 0x80);
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
    func_08006778(gUnk_09ED9A1C[0], 0x78, 0x50);
}
#else
INCLUDE_ASM("mode_chkeff/mode_chkeff_0.s");
#endif

#ifdef NON_MATCHING
void mode_chkeff_1(void) {
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
            func_08006778(obj, 120, 80);
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

        if (func_08006B74() && (GetKeysHeld() & 1)) {
            func_08006778(obj, 120, 80);
        }

        if (gChkEffWork->paused != 0) {
            func_0809D2B0(0, 0, 0, gUnk_081309E0);
        } else {
            func_0809D2B0(0, 0, 0, gUnk_081309E8);
        }

        func_0809D2B0(0, 14, 0, gUnk_081309F0);
        func_0809D2B0(0, 15, 0, gUnk_081309F0);
        func_0809D2B0(0, 16, 0, gUnk_081309F0);
        func_0809D2B0(0, 17, 0, gUnk_081309F0);
        func_0809D2B0(0, 18, 0, gUnk_081309F0);
        func_0809D2B0(0, 19, 0, gUnk_081309F0);
        func_08006B80(&a, &b);
        func_0809D2B0(0, 14, 0, gUnk_08130A18);
        func_0809D458(6, 14, 0, gChkEffWork->alphaA);
        func_0809D2B0(0, 15, 0, gUnk_08130A20);
        func_0809D458(6, 15, 0, gChkEffWork->alphaB);
        func_0809D2B0(0, 16, 0, gUnk_08130A28);
        func_0809D458(6, 16, 0, gChkEffWork->scale);
        func_0809D2B0(0, 17, 0, gUnk_08130A30);
        func_0809D458(6, 17, 0, gChkEffWork->unk_14);
        func_0809D2B0(0, 18, 0, gUnk_08130A34);
        func_0809D458(6, 18, 0, a);
        func_0809D2B0(0, 19, 0, gUnk_08130A38);
        func_0809D458(6, 19, 0, b);
        TaskPoolUpdate(&gChkEffWork->pool);
        TaskPoolDraw(&gChkEffWork->pool);
        func_0800675C(gChkEffWork->unk_1C, gChkEffWork->scale, gChkEffWork->scale);
        SetBlendAlpha(gChkEffWork->alphaA, gChkEffWork->alphaB);

        if (gChkEffWork->paused == 0 || (GetKeysRepeat() & 1)) {
            func_08006954();
        }

        SetBgScroll(1, gChkEffWork->scrollX, gChkEffWork->scrollY);

        if ((gFrameCounter & 3) == 0) {
            gChkEffWork->scrollY--;
        }
    }
}
#else
INCLUDE_ASM("mode_chkeff/mode_chkeff_1.s");
#endif

void mode_chkeff_2(void) {
    TaskPoolDestroy(&gChkEffWork->pool);
    EwramFree(gChkEffWork);
}

const char gModeNameChkeff[12] = "mode_chkeff";
