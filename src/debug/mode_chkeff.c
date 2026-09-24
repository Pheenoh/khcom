#include "bg_animation_data.h"
#include "display.h"
#include "mode_chkeff.h"
#include "gba/keys.h"
#include "sprites_mode_debug.h"

extern BgAnimationDef* gUnk_09ED9A1C[83];

ChkEffWork* gChkEffWork;

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
    eu_080059D4(1, gUnk_08C6B0C4);
    eu_080059F4(1, gUnk_08EEE384);
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

    if (GetKeysPressed() & B_BUTTON) {
        ModeRequest(&gModeDebug, 0);
    } else {
        if (GetKeysPressed() & START_BUTTON) {
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

        if (GetKeysPressed() & SELECT_BUTTON) {
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

        if (BgAnimIsStopped() && (GetKeysHeld() & A_BUTTON)) {
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

        if ((*wp)->paused == 0 || (GetKeysRepeat() & A_BUTTON)) {
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

BgAnimationDef* gUnk_09ED9A1C[83] = {
    &gUnk_09EDA558,
    &gUnk_09EDA840,
    &gUnk_09EDA828,
    &gUnk_09EDA6C0,
    &gUnk_09EDA6D8,
    &gUnk_09EDA708,
    &gUnk_09EDA738,
    &gUnk_09EDA750,
    &gUnk_09EDA570,
    &gUnk_09EDA5B8,
    &gUnk_09EDA5E8,
    &gUnk_09EDA858,
    &gUnk_09EDA768,
    &gUnk_09EDA798,
    &gUnk_09EDA7B0,
    &gUnk_09EDA7C8,
    &gUnk_09EDA618,
    &gUnk_09EDA648,
    &gUnk_09EDA660,
    &gUnk_09EDAC30,
    &gUnk_09EDAC48,
    &gUnk_09EDA630,
    &gUnk_09EDAD38,
    &gUnk_09EDA678,
    &gUnk_09EDA690,
    &gUnk_09EDA6A8,
    &gUnk_09EDA888,
    &gUnk_09EDA7E0,
    &gUnk_09EDA7F8,
    &gUnk_09EDA810,
    &gUnk_09EDA948,
    &gUnk_09EDA960,
    &gUnk_09EDA600,
    &gUnk_09EDA8A0,
    &gUnk_09EDA8B8,
    &gUnk_09EDA8D0,
    &gUnk_09EDA8E8,
    &gUnk_09EDA900,
    &gUnk_09EDA918,
    &gUnk_09EDA930,
    &gUnk_09EDA978,
    &gUnk_09EDA990,
    &gUnk_09EDA9A8,
    &gUnk_09EDA9C0,
    &gUnk_09EDA9D8,
    &gUnk_09EDA9F0,
    &gUnk_09EDAA08,
    &gUnk_09EDAA68,
    &gUnk_09EDAA80,
    &gUnk_09EDAA98,
    &gUnk_09EDAAB0,
    &gUnk_09EDAAC8,
    &gUnk_09EDAAF8,
    &gUnk_09EDAA50,
    &gUnk_09EDAA20,
    &gUnk_09EDAB10,
    &gUnk_09EDAB40,
    &gUnk_09EDAB58,
    &gUnk_09EDAB28,
    &gUnk_09EDA5A0,
    &gUnk_09EDA6F0,
    &gUnk_09EDAB70,
    &gUnk_09EDAB88,
    &gUnk_09EDABA0,
    &gUnk_09EDABB8,
    &gUnk_09EDABD0,
    &gUnk_09EDABE8,
    &gUnk_09EDAC00,
    &gUnk_09EDAC18,
    &gUnk_09EDAC60,
    &gUnk_09EDACD8,
    &gUnk_09EDACC0,
    &gUnk_09EDAC78,
    &gUnk_09EDACF0,
    &gUnk_09EDAD08,
    &gUnk_09EDAD20,
    &gUnk_09EDAD50,
    &gUnk_09EDA870,
    &gUnk_09EDA588,
    &gUnk_09EDAD68,
    &gUnk_09EDAD80,
    &gUnk_09EDAD98,
    &gUnk_09EDADB0,
};

Mode gModeChkeff = { "mode_chkeff", (ModeInitFunc)mode_chkeff_0, mode_chkeff_1, mode_chkeff_2 };
