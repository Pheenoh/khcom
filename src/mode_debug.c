#include "macros.h"
#include "mode_debug.h"

DebugWork* gDebugWork;
ChkObjWork* gChkObjWork;
#include "gba/keys.h"

#ifdef VERSION_US
const char gUnk_081283C0[12] = "N041001a";
#elif defined(VERSION_JP)
const char gUnk_081283C0[12] = "J041001a";
#else
const char gUnk_081283C0[12] = "E041220b";
#endif

#ifdef VERSION_EU
const char gUnkEu_08126FF4[0x4C] =
    "\x82\x64\x82\x4f\x82\x53\x82\x50\x82\x51\x82\x51\x82\x4f\x82\x82\x00\x00\x00\x00"
    "\x82\x63\x82\x60\x82\x71\x82\x6a\x82\x64\x82\x71\x00\x00\x00\x00"
    "\x82\x6b\x82\x68\x82\x66\x82\x67\x82\x73\x82\x64\x82\x71\x00\x00"
    "\x82\x61\x82\x71\x82\x68\x82\x66\x82\x67\x82\x73\x82\x6d\x82\x64\x82\x72\x82\x72\x00\x00\x00\x00";

const char gUnkEu_08127040[0x190] =
    "\x82\x6c\x82\x60\x82\x68\x82\x6d\x81\x40\x81\x40\x81\x40\x81\x40\x00\x00\x00\x00"
    "\x82\x6e\x82\x61\x82\x69\x82\x64\x82\x62\x82\x73\x81\x40\x81\x40\x00\x00\x00\x00"
    "\x82\x6c\x82\x60\x82\x6f\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x00\x00\x00\x00"
    "\x82\x64\x82\x65\x82\x65\x82\x64\x82\x62\x82\x73\x81\x40\x81\x40\x00\x00\x00\x00"
    "\x82\x72\x82\x6e\x82\x74\x82\x6d\x82\x63\x81\x40\x81\x40\x81\x40\x00\x00\x00\x00"
    "\x82\x64\x82\x75\x82\x64\x82\x6d\x82\x73\x81\x40\x81\x40\x81\x40\x00\x00\x00\x00"
    "\x82\x6b\x82\x68\x82\x6d\x82\x6a\x81\x40\x81\x40\x81\x40\x81\x40\x00\x00\x00\x00"
    "\x82\x61\x82\x60\x82\x73\x82\x73\x82\x6b\x82\x64\x81\x40\x81\x40\x00\x00\x00\x00"
    "\x82\x6f\x82\x6e\x82\x6e\x82\x67\x81\x40\x81\x40\x81\x40\x81\x40\x00\x00\x00\x00"
    "\x82\x65\x82\x6b\x82\x60\x82\x66\x81\x40\x81\x40\x81\x40\x81\x40\x00\x00\x00\x00"
    "\x82\x6b\x82\x6e\x82\x66\x82\x6e\x81\x40\x81\x40\x81\x40\x81\x40\x00\x00\x00\x00"
    "\x82\x63\x82\x64\x82\x6b\x81\x40\x82\x72\x82\x60\x82\x75\x82\x64\x00\x00\x00\x00"
    "\x82\x6e\x82\x6f\x82\x64\x81\x40\x82\x72\x82\x60\x82\x75\x82\x64\x00\x00\x00\x00"
    "\x82\x6c\x82\x6e\x82\x75\x82\x68\x82\x64\x81\x40\x81\x40\x81\x40\x00\x00\x00\x00"
    "\x82\x64\x82\x6d\x82\x63\x82\x71\x82\x6e\x82\x6b\x82\x6b\x81\x40\x00\x00\x00\x00"
    "\x82\x6b\x82\x60\x82\x6d\x82\x66\x82\x74\x82\x60\x82\x66\x82\x64\x00\x00\x00\x00"
    "\x82\x69\x82\x6e\x82\x74\x82\x71\x82\x6d\x82\x60\x82\x6b\x81\x40\x00\x00\x00\x00"
    "\x82\x76\x82\x6e\x82\x71\x82\x6b\x82\x63\x82\x72\x82\x64\x82\x6b\x00\x00\x00\x00"
    "\x82\x62\x82\x6e\x82\x6d\x82\x73\x82\x68\x82\x6d\x82\x74\x82\x64\x00\x00\x00\x00"
    "\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40\x00\x00\x00\x00";
#endif

#ifndef VERSION_EU
void mode_debug_0(void) {
    m4aMPlayAllStop();
    gDebugWork = EwramAlloc(sizeof(DebugWork));
    func_08006120(1, 16);
    func_0801CB44();
    SetBgMode0();
    SetupBg(0, 0, 15, 0);
    SetupBg(1, 2, 31, 0);
    SetBgColorMode(1, 0x80);
    SetBgSize(1, 0);
    LoadBgTiles(1, gUnk_08C72CE4, 0x5B40);
    LoadBgPalette(1, gUnk_08F683E4, 0x200);
    LoadBgMap(1, gUnk_08EEEB84, 0x800);
    EnableBg(1);
    SetBackdropColor(31, 31, 31);
    EnableBg(0);
    func_0805FA8C(0, 0x5400, 0x500);
    func_0805FA60(0, gUnk_08F68604, 0x20, 0x0F);
    gDebugWork->tiles = LoadObjTiles(gUnk_08950902, 0x2E0);
    gDebugWork->palette = LoadObjPalette(gUnk_08F685E4, 0x20);
    AnimInit(&gDebugWork->anim, gUnk_09EDF774, gUnk_09EDF764);
    AnimStart(&gDebugWork->anim, 0, 1);
#ifdef VERSION_JP
    func_0805FCB0(0, 0, 2, "\x82\x69\x82\x4f\x82\x53\x82\x50\x82\x4f\x82\x4f\x82\x50\x82\x81");
#else
    func_0805FCB0(0, 0, 2, "\x82\x6d\x82\x4f\x82\x53\x82\x50\x82\x4f\x82\x4f\x82\x50\x82\x81");
#endif

    if (GetPaletteEffect() < 0) {
        func_0805FCB0(168, 150, 2, "\x82\x63\x82\x60\x82\x71\x82\x6a\x82\x64\x82\x71");
    } else if (GetPaletteEffect() > 0) {
        func_0805FCB0(168, 150, 2, "\x82\x6b\x82\x68\x82\x66\x82\x67\x82\x73\x82\x64\x82\x71");
    } else {
        func_0805FCB0(144, 150, 2, "\x82\x61\x82\x71\x82\x68\x82\x66\x82\x67\x82\x73\x82\x6d\x82\x64\x82\x72\x82\x72");
    }

    gDebugWork->unk_00 = 0;
    gDebugWork->unk_01 = -1;
}
#else
INCLUDE_ASM("mode_debug/mode_debug_0.s");
#endif

#ifndef VERSION_EU
void mode_debug_1(void) {
    s16 v;
    s8 old;
    void* gfx;

    v = GetPaletteEffect();

    switch (GetKeysPressed() & (L_BUTTON | R_BUTTON)) {
    case 0x100:
        if (v <= 23) {
            SetPaletteEffect(v + 1);
            ModeRequest(&gModeDebug, 0);
            return;
        }
        break;
    case 0x200:
        if (v > -24) {
            SetPaletteEffect(v - 1);
            ModeRequest(&gModeDebug, 0);
            return;
        }
        break;
    }

    if (GetKeysRepeat() & DPAD_UP) {
        gDebugWork->unk_00--;
        m4aSongNumStart(101);
    }

    if (GetKeysRepeat() & DPAD_DOWN) {
        gDebugWork->unk_00++;
        m4aSongNumStart(101);
    }

    switch (gDebugWork->unk_00) {
    case 0:
        if (GetKeysPressed() & 9) {
            ModeRequest(&gModeCopyright1, 0);
            return;
        }
        break;
    case 1:
        if (GetKeysPressed() & 9) {
            ModeRequest(&gModeChkobj, 0);
            return;
        }
        break;
    case 2:
        if (GetKeysPressed() & 9) {
            ModeRequest(&gModeMapChk, 0);
            return;
        }
        break;
    case 3:
        if (GetKeysPressed() & 9) {
            ModeRequest(&gModeChkeff, 0);
            return;
        }
        break;
    case 4:
        if (GetKeysPressed() & 9) {
            ModeRequest(&gModeChksnd, 0);
            return;
        }
        break;
    case 5:
        if (GetKeysPressed() & 9) {
            ModeRequest(&gModeEventselect, 0);
            return;
        }
        break;
    case 6:
        if (GetKeysPressed() & 9) {
            SaveLoadHeader();
            func_08085FB0();
            func_08085C3C();
            ModeRequest(&gModeSioBattle, 0);
            return;
        }
        break;
    case 7:
        if (GetKeysPressed() & 9) {
            ModeRequest(&gModeChkbtl, 0);
        }
        break;
    case 8:
        if (GetKeysPressed() & 9) {
            ModeRequest(&gModePooh, 0);
        }
        break;
    case 9:
        if (GetKeysPressed() & 9) {
            ModeRequest(&gModeDebflag, 0);
        }
        break;
    case 10:
        if (GetKeysPressed() & 9) {
            ModeRequest(&gModeWLogo, 0);
        }
        break;
    case 11:
        if (GetKeysPressed() & 9) {
            SaveClearHeader();
            SaveClearFileLarge(0);
            SaveClearFileLarge(1);
            SaveClearFileSmall(0);
            SaveClearFileSmall(1);
            SaveClearSystem();
            ModeRequest(&gModeDebug, 0);
        }
        break;
    case 12:
        if (GetKeysPressed() & 9) {
            func_0800FDD0(0);
            func_0800FDD0(17);
            func_0800FDD0(18);
            func_0800FDD0(19);
            func_0800FDD0(20);
            func_0800FDD0(21);
            func_0800FDD0(22);
            ModeRequest(&gModeBackupstat, 0);
        }
        break;
    case 13:
        if (GetKeysPressed() & 9) {
            ModeRequestHeapReset(&gModeMovie, 1);
        }
        break;
    case 14:
        if (GetKeysPressed() & 9) {
            ModeRequestHeapReset(&gModeMovie, 2);
        }
        break;
    case 15:
        if (GetKeysPressed() & 9) {
            ModeRequestHeapReset(&gModeMovie, 3);
        }
        break;
    case 16:
        if (GetKeysPressed() & 9) {
            ModeRequestHeapReset(&gModeMovie, 4);
        }
        break;
    case 17:
        if (GetKeysPressed() & 9) {
            ModeRequestHeapReset(&gModeMovie, 5);
        }
        break;
    case 18:
        gDebugWork->unk_00 = 0;
        break;
    case -1:
        gDebugWork->unk_00 = 17;
        break;
    }

    old = gDebugWork->unk_01;
    gDebugWork->unk_01 = gDebugWork->unk_00 / 9;

    if (GetKeysRepeat() & DPAD_LEFT) {
        gDebugWork->unk_01--;

        if (gDebugWork->unk_01 < 0) {
            gDebugWork->unk_01 = 2;
        }

        gDebugWork->unk_00 = gDebugWork->unk_01 * 9;
    } else if (GetKeysRepeat() & DPAD_RIGHT) {
        gDebugWork->unk_01++;

        if (gDebugWork->unk_01 > 2) {
            gDebugWork->unk_01 = 0;
        }

        gDebugWork->unk_00 = gDebugWork->unk_01 * 9;
    }

    if (old != gDebugWork->unk_01) {
        switch (gDebugWork->unk_01) {
        case 0:
            func_0805FCB0(24, 12, 2, "\x82\x6c\x82\x60\x82\x68\x82\x6d\x81\x40\x81\x40\x81\x40\x81\x40");
            func_0805FCB0(24, 28, 2, "\x82\x6e\x82\x61\x82\x69\x82\x64\x82\x62\x82\x73\x81\x40\x81\x40");
            func_0805FCB0(24, 44, 2, "\x82\x6c\x82\x60\x82\x6f\x81\x40\x81\x40\x81\x40\x81\x40\x81\x40");
            func_0805FCB0(24, 60, 2, "\x82\x64\x82\x65\x82\x65\x82\x64\x82\x62\x82\x73\x81\x40\x81\x40");
            func_0805FCB0(24, 76, 2, "\x82\x72\x82\x6e\x82\x74\x82\x6d\x82\x63\x81\x40\x81\x40\x81\x40");
            func_0805FCB0(24, 92, 2, "\x82\x64\x82\x75\x82\x64\x82\x6d\x82\x73\x81\x40\x81\x40\x81\x40");
            func_0805FCB0(24, 108, 2, "\x82\x6b\x82\x68\x82\x6d\x82\x6a\x81\x40\x81\x40\x81\x40\x81\x40");
            func_0805FCB0(24, 124, 2, "\x82\x61\x82\x60\x82\x73\x82\x73\x82\x6b\x82\x64\x81\x40\x81\x40");
            func_0805FCB0(24, 140, 2, "\x82\x6f\x82\x6e\x82\x6e\x82\x67\x81\x40\x81\x40\x81\x40\x81\x40");
            break;
        default:
            func_0805FCB0(24, 12, 2, "\x82\x65\x82\x6b\x82\x60\x82\x66\x81\x40\x81\x40\x81\x40\x81\x40");
            func_0805FCB0(24, 28, 2, "\x82\x6b\x82\x6e\x82\x66\x82\x6e\x81\x40\x81\x40\x81\x40\x81\x40");
            func_0805FCB0(24, 44, 2, "\x82\x63\x82\x64\x82\x6b\x81\x40\x82\x72\x82\x60\x82\x75\x82\x64");
            func_0805FCB0(24, 60, 2, "\x82\x6e\x82\x6f\x82\x64\x81\x40\x82\x72\x82\x60\x82\x75\x82\x64");
            func_0805FCB0(24, 76, 2, "\x82\x6c\x82\x6e\x82\x75\x82\x68\x82\x64\x82\x50\x81\x40\x81\x40");
            func_0805FCB0(24, 92, 2, "\x82\x6c\x82\x6e\x82\x75\x82\x68\x82\x64\x82\x51\x81\x40\x81\x40");
            func_0805FCB0(24, 108, 2, "\x82\x6c\x82\x6e\x82\x75\x82\x68\x82\x64\x82\x52\x81\x40\x81\x40");
            func_0805FCB0(24, 124, 2, "\x82\x6c\x82\x6e\x82\x75\x82\x68\x82\x64\x82\x53\x81\x40\x81\x40");
            func_0805FCB0(24, 140, 2, "\x82\x6c\x82\x6e\x82\x75\x82\x68\x82\x64\x82\x54\x81\x40\x81\x40");
            break;
        }
    }

    if (GetKeysPressed() & 4) {
        ModeRequest(&gModeDebflag, 0);
    }

    func_080605A4(0);
    func_08060598();
    gfx = AnimUpdate(&gDebugWork->anim);
    DrawSprite(9, gDebugWork->unk_00 % 9 * 16 + 13, gfx, gDebugWork->tiles,
               gDebugWork->palette, 0, 0, 0);
}
#else
INCLUDE_ASM("mode_debug/mode_debug_1.s");
#endif

void mode_debug_2(void) {
    func_080609A0();
    ReleaseObjTiles(gDebugWork->tiles);
    ReleaseObjPalette(gDebugWork->palette);
    EwramFree(gDebugWork);
}

void func_0800B30C(ObjDef* def) {
    func_08005974(&gChkObjWork->anim, gChkObjWork->animId, 0, def->unk_04, def->unk_00);
    func_08002A10(gChkObjWork->tiles, def->unk_08);
    ReleaseObjPalette(gChkObjWork->palette);
    gChkObjWork->palette = LoadObjPalette(def->palette, def->paletteSize);
}

const char gModeNameDebug[12] = "mode_debug";
