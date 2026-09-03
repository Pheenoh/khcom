#include "macros.h"
#include "mode_dummy.h"

const DummyEntry gUnk_08130A4C[10] = {
    { "\x83\x49\x81\x5b\x83\x76\x83\x6a\x83\x93\x83\x4f", "\x83\x80\x81\x5b\x83\x72\x81\x5b\x81\x40\x91\x90\x8c\xb4\x81\x60\x8f\xe9\x8a\x4f\x8a\xcf", 0 },
    { "\x82\x50\x8a\x4b", "\x83\x8f\x81\x5b\x83\x8b\x83\x68\x91\x49\x91\xf0\x83\x60\x83\x85\x81\x5b\x83\x67\x83\x8a\x83\x41\x83\x8b", 1 },
    { "\x83\x67\x83\x89\x83\x94\x83\x40\x81\x5b\x83\x58\x83\x5e\x83\x45\x83\x93", "\x83\x8b\x81\x5b\x83\x80\x83\x4e\x83\x8a\x83\x47\x83\x43\x83\x67\x83\x60\x83\x85\x81\x5b\x83\x67\x83\x8a\x83\x41\x83\x8b", 2 },
    { "\x83\x67\x83\x89\x83\x94\x83\x40\x81\x5b\x83\x58\x83\x5e\x83\x45\x83\x93", "\x83\x6f\x83\x67\x83\x8b\x83\x60\x83\x85\x81\x5b\x83\x67\x83\x8a\x83\x41\x83\x8b", 3 },
    { "\x82\x53\x8a\x4b", "\x83\x80\x81\x5b\x83\x72\x81\x5b\x82\xc8\x82\xa2\x82\xb5\x82\x50\x96\x87\x8a\x47", 4 },
    { "\x82\x55\x8a\x4b", "\x83\x80\x81\x5b\x83\x72\x81\x5b", 5 },
    { "\x82\x50\x82\x50\x8a\x4b", "\x83\x80\x81\x5b\x83\x72\x81\x5b\x82\xc8\x82\xa2\x82\xb5\x82\x50\x96\x87\x8a\x47", 6 },
    { "\x82\x50\x82\x51\x8a\x4b", "\x83\x80\x81\x5b\x83\x72\x81\x5b", 7 },
    { "\x82\x50\x82\x52\x8a\x4b", "\x83\x80\x81\x5b\x83\x72\x81\x5b", 8 },
    { "\x83\x58\x83\x5e\x83\x62\x83\x74\x83\x8d\x81\x5b\x83\x8b", "\x82\x73\x82\x67\x82\x64\x81\x40\x82\x64\x82\x6d\x82\x63", 9 },
};

#ifndef VERSION_EU
void mode_dummy_0(u32 arg) {
    const DummyEntry* entry;

    func_08006120(0, 0x10);
    func_08004DB0();
    SetupBg(0, 0, 0x0F, 0);
    EnableBg(0);
    func_0805FA8C(0, 0x5400, 0x500);
    func_0805FA60(0, gUnk_08128304, 0x20, 0x0F);
    SetupBg(1, 1, 0x0C, 8);
    LoadBgTiles(1, gUnk_08C6B0C4, 0x7C20);
    LoadBgPalette(1, gUnk_08F683C4, 0x20);
    LoadBgMap(1, gUnk_08EEE384, 0x800);
    EnableBg(1);
    gUnk_020348BC = arg;

    if (arg > 9) {
        gUnk_020348BC = 0;
        func_0805FCB0(0, 0, 2, "\x83\x47\x83\x89\x81\x5b\x81\x46\x96\xb3\x8c\xf8\x82\xc8\x88\xf8\x90\x94");
    } else {
        gUnk_020348BC = arg;
        entry = &gUnk_08130A4C[arg];
        func_0805FCB0(0, 0, 2, entry->name);
        func_0805FCB0(0x10, 0x18, 2, entry->desc);
    }
}
#else
INCLUDE_ASM("mode_dummy/mode_dummy_0.s");
#endif

void func_0800C064(void) {
    const DummyEntry* entry;

    if (!func_08006314()) {
        entry = &gUnk_08130A4C[gUnk_020348BC];

        switch (entry->unk_08) {
        case 0:
            ModeRequestHeapReset(&gUnk_09EDE4D0, 1);
            break;
        case 1:
            gUnk_02039BB0.unk_180 = 0x200;
            ModeRequest(&gUnk_09EF8F9C, 0);
            break;
        case 2:
            func_080DF380();
            func_080E04EC();
            break;
        case 3:
            func_0806180C(6);
            break;
        case 4:
            func_0806180C(0x14);
            break;
        case 5:
            func_0806180C(0x1C);
            break;
        case 6:
            func_0806180C(0x2C);
            break;
        case 7:
            func_0806180C(0x3D);
            break;
        case 8:
            func_0806180C(0x49);
            break;
        case 9:
        default:
            ModeRequest(&gUnk_09EF4EC0, 0);
            break;
        }
    } else {
        func_080605A4(0);
        func_08060598();
        SetBgScroll(1, (gFrameCounter << 14) >> 16, 0);
        UpdatePlayTime();
    }
}

void mode_dummy_1(void) {
    if (!func_08006314() && (GetKeysPressed() & 9)) {
        func_08006184(0, 0x10);
        func_08001248(func_0800C064);
    }

    func_080605A4(0);
    func_08060598();
    SetBgScroll(1, (gFrameCounter << 14) >> 16, 0);
    UpdatePlayTime();
}

void mode_dummy_2(void) {
    func_080609A0();
}

ALIGN_ZERO(2);

const char gUnk_08130BDC[12] = "mode_dummy";
