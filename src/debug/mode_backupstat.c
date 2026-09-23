#include "registration_data.h"
#include "mode_chkbtl.h"
#include "mode_backupstat.h"
#include "gba/keys.h"

const char* gUnk_09EF9668[3] = {
    "\x82\xC8\x82\xB5\x81\x40",
    "\x82\xB1\x82\xED\x82\xEA",
    "\x82\xA0\x82\xE8\x81\x40",
};

const BackupStatEntry gUnk_099937E4[6] = {
    {"\x82\x72\x82\x78\x82\x72\x82\x73\x82\x64\x82\x6C\x81\x40", 2},
    {"\x82\x72\x82\x6E\x82\x71\x82\x60\x81\x40\x81\x40\x82\x50", 64},
    {"\x82\x72\x82\x6E\x82\x71\x82\x60\x81\x40\x81\x40\x82\x51", 64},
    {"\x82\x71\x82\x68\x82\x6A\x82\x74\x81\x40\x81\x40\x82\x50", 512},
    {"\x82\x71\x82\x68\x82\x6A\x82\x74\x81\x40\x81\x40\x82\x51", 512},
    {"\x82\x72\x82\x74\x82\x72\x82\x6F\x82\x64\x82\x6D\x82\x63", 4},
};

s8 gUnk_02035FE8;
s8 gUnk_02035FE9;
const BackupStatEntry* gBackupStatEntries;
s16 gBackupStatStates[12];

void mode_backupstat_0(void) {
    s32 i;
    s32 j;

    SetBgMode0();
    SetupBg(0, 0, 15, 0);
    EnableBg(0);
    func_0805FA8C(0, 0x5400, 0x500);
    func_0805FA60(0, gWhitePalette, 32, 15);
    gUnk_02035FE8 = 0;
    func_0805FCB0(0, 0, 2, "\x81\x84");
    gUnk_02035FE9 = 6;
    gBackupStatEntries = gUnk_099937E4;

    for (i = 0; i < gUnk_02035FE9; i++) {
        for (j = 0; j <= 1; j++) {
            switch (i) {
            case 0:
                gBackupStatStates[i * 2 + j] = SaveCheckHeaderSlot(j);
                break;
            case 1:
                gBackupStatStates[i * 2 + j] = SaveCheckFileLargeSlot(0, j);
                break;
            case 2:
                gBackupStatStates[i * 2 + j] = SaveCheckFileLargeSlot(1, j);
                break;
            case 3:
                gBackupStatStates[i * 2 + j] = SaveCheckFileSmallSlot(0, j);
                break;
            case 4:
                gBackupStatStates[i * 2 + j] = SaveCheckFileSmallSlot(1, j);
                break;
            case 5:
                gBackupStatStates[i * 2 + j] = SaveCheckSystemSlot(j);
                break;
            }
        }
    }

    for (i = 0; i < gUnk_02035FE9 * 2; i++) {
        func_0805FCB0(12, i * 9, 2, gBackupStatEntries[i / 2].name);

        switch (i % 2) {
        case 0:
            func_0805FCB0(75, i * 9, 2, "\x81\x7C\x82\x50");
            break;
        case 1:
            func_0805FCB0(75, i * 9, 2, "\x81\x7C\x82\x51");
            break;
        }
        func_0805FCB0(120, i * 9, 2, gUnk_09EF9668[gBackupStatStates[i]]);
    }
}

void func_081097F4(void) {
    u16 slot;

    slot = gUnk_02035FE8 % 2;

    switch (gUnk_02035FE8 / 2) {
    case 0:
        SaveSetHeaderState(slot, gBackupStatStates[gUnk_02035FE8]);
        break;
    case 1:
        SaveSetFileLargeState(0, slot, gBackupStatStates[gUnk_02035FE8]);
        break;
    case 2:
        SaveSetFileLargeState(1, slot, gBackupStatStates[gUnk_02035FE8]);
        break;
    case 3:
        SaveSetFileSmallState(0, slot, gBackupStatStates[gUnk_02035FE8]);
        break;
    case 4:
        SaveSetFileSmallState(1, slot, gBackupStatStates[gUnk_02035FE8]);
        break;
    case 5:
        SaveSetSystemState(slot, gBackupStatStates[gUnk_02035FE8]);
        break;
    }
    func_0805FCB0(120, gUnk_02035FE8 * 9, 2, gUnk_09EF9668[gBackupStatStates[gUnk_02035FE8]]);
}

void mode_backupstat_1(void) {
    u8 prev;

    prev = gUnk_02035FE8;

    if (GetKeysRepeat() & DPAD_UP) {
        gUnk_02035FE8--;
    } else if (GetKeysRepeat() & DPAD_DOWN) {
        gUnk_02035FE8++;
    }

    if (prev != gUnk_02035FE8) {
        if (gUnk_02035FE8 < 0) {
            gUnk_02035FE8 = gUnk_02035FE9 * 2 - 1;
        } else if (gUnk_02035FE8 >= gUnk_02035FE9 * 2) {
            gUnk_02035FE8 = 0;
        }
        func_0805FCB0(0, prev * 9, 2, "\x81\x40");
        func_0805FCB0(0, gUnk_02035FE8 * 9, 2, "\x81\x84");
    }

    if ((GetKeysPressed() & DPAD_LEFT) != 0) {
        if (--gBackupStatStates[gUnk_02035FE8] < 0) {
            gBackupStatStates[gUnk_02035FE8] = 2;
        }
        func_081097F4();
    } else if (GetKeysPressed() & DPAD_RIGHT) {
        if (++gBackupStatStates[gUnk_02035FE8] > 2) {
            gBackupStatStates[gUnk_02035FE8] = 0;
        }
        func_081097F4();
    }

    if (GetKeysPressed() & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON)) {
        ModeRequest(&gModeDebug, 0);
    } else {
        func_080605A4(0);
        func_08060598();
    }
}

void mode_backupstat_2(void) {
    func_080609A0();
}

const char gModeNameBackupstat[] = "mode_backupstat";

Mode gModeBackupstat = {
    gModeNameBackupstat,
    (void (*)(s32))mode_backupstat_0,
    mode_backupstat_1,
    mode_backupstat_2,
};
