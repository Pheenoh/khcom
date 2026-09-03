#include "macros.h"
#include "romcri.h"

#ifndef VERSION_EU
void task_romcri_eff_0(RomcriEffWork* work, s32 arg) {
    SetupBg(1, 0, 23, 12);
    work->angle = arg;
    work->unk_00 = 0;
    DisableBg(1);
    PushPaletteEffect(0);
    LoadBgPalette(1, gUnk_08F6D9E4, 0x20);
    PopPaletteEffect();
    SetBgPriority(1, 0);
    SetBgBlend(1, 16, 16);

    switch (work->angle) {
    case 0xAD:
        LoadBgTiles(1, gUnk_08ED21E4, 0x4AC0);
        SetBgScroll(1, -35, -23);
        break;
    case 0x53:
        LoadBgTiles(1, gUnk_08ED21E4, 0x4AC0);
        SetBgScroll(1, -77, -23);
        break;
    case 0xD3:
        LoadBgTiles(1, gUnk_08EDBB44, 0x7520);
        SetBgScroll(1, -39, 2);
        break;
    case 0x2D:
        LoadBgTiles(1, gUnk_08EDBB44, 0x7520);
        SetBgScroll(1, -71, 3);
        break;
    }
}
#else
INCLUDE_ASM("romcri/task_romcri_eff_0.s");
#endif

u8 task_romcri_eff_1(RomcriEffWork* work) {
    switch (work->angle) {
    case 0xAD:
        switch (work->unk_00) {
        case 0:
            LoadBgMap(1, gUnk_08F4C384, 0x800);
            break;
        case 4:
            LoadBgMap(1, gUnk_08F4CB84, 0x800);
            break;
        case 8:
            LoadBgMap(1, gUnk_08F4D384, 0x800);
            break;
        case 12:
            LoadBgMap(1, gUnk_08F4DB84, 0x800);
            break;
        case 16:
            LoadBgTiles(1, gUnk_08ED6CA4, 0x4EA0);
            LoadBgMap(1, gUnk_08F50384, 0x800);
            break;
        case 20:
            LoadBgMap(1, gUnk_08F50B84, 0x800);
            break;
        case 24:
            LoadBgMap(1, gUnk_08F51384, 0x800);
            break;
        case 28:
            LoadBgMap(1, gUnk_08F51B84, 0x800);
            break;
        case 32:
            return 0;
        }
        break;
    case 0x53:
        switch (work->unk_00) {
        case 0:
            LoadBgMap(1, gUnk_08F4E384, 0x800);
            break;
        case 4:
            LoadBgMap(1, gUnk_08F4EB84, 0x800);
            break;
        case 8:
            LoadBgMap(1, gUnk_08F4F384, 0x800);
            break;
        case 12:
            LoadBgMap(1, gUnk_08F4FB84, 0x800);
            break;
        case 16:
            LoadBgTiles(1, gUnk_08ED6CA4, 0x4EA0);
            LoadBgMap(1, gUnk_08F52384, 0x800);
            break;
        case 20:
            LoadBgMap(1, gUnk_08F52B84, 0x800);
            break;
        case 24:
            LoadBgMap(1, gUnk_08F53384, 0x800);
            break;
        case 28:
            LoadBgMap(1, gUnk_08F53B84, 0x800);
            break;
        case 32:
            return 0;
        }
        break;
    case 0x2D:
        switch (work->unk_00) {
        case 0:
            LoadBgMap(1, gUnk_08F54384, 0x800);
            break;
        case 4:
            LoadBgMap(1, gUnk_08F54B84, 0x800);
            break;
        case 8:
            LoadBgMap(1, gUnk_08F55384, 0x800);
            break;
        case 12:
            LoadBgMap(1, gUnk_08F55B84, 0x800);
            break;
        case 16:
            LoadBgMap(1, gUnk_08F56384, 0x800);
            break;
        case 20:
            LoadBgMap(1, gUnk_08F56B84, 0x800);
            break;
        case 24:
            LoadBgMap(1, gUnk_08F57384, 0x800);
            break;
        case 28:
            LoadBgMap(1, gUnk_08F57B84, 0x800);
            break;
        case 32:
            return 0;
        }
        break;
    case 0xD3:
        switch (work->unk_00) {
        case 0:
            LoadBgMap(1, gUnk_08F58384, 0x800);
            break;
        case 4:
            LoadBgMap(1, gUnk_08F58B84, 0x800);
            break;
        case 8:
            LoadBgMap(1, gUnk_08F59384, 0x800);
            break;
        case 12:
            LoadBgMap(1, gUnk_08F59B84, 0x800);
            break;
        case 16:
            LoadBgMap(1, gUnk_08F5A384, 0x800);
            break;
        case 20:
            LoadBgMap(1, gUnk_08F5AB84, 0x800);
            break;
        case 24:
            LoadBgMap(1, gUnk_08F5B384, 0x800);
            break;
        case 28:
            LoadBgMap(1, gUnk_08F5BB84, 0x800);
            break;
        case 32:
            return 0;
        }
        break;
    }

    work->unk_00++;
    return 1;
}

void task_romcri_eff_3(void) {
    DisableBg(1);
}

void task_romcri_eff2_0(RomcriEff2Work* work, s32 arg) {
    SetupBg(1, 0, 23, 12);
    work->unk_00 = 0;
    work->unk_03 = 0;
    work->angle = arg;
    DisableBg(1);
    PushPaletteEffect(0);
    LoadBgPalette(1, gUnk_08F6DA04, 0x20);
    PopPaletteEffect();
    SetBgPriority(1, 0);
    SetBgBlend(1, 16, 16);
    LoadBgTiles(1, gUnk_08EE3064, 0xA20);

    if (gGameState.flags & 8) {
        switch (work->angle) {
        case 0x2D:
            SetBgScroll(1, -100, 4);
            break;
        case 0xD3:
            SetBgScroll(1, -73, 5);
            break;
        case 0x53:
            SetBgScroll(1, -101, -18);
            break;
        case 0xAD:
            SetBgScroll(1, -75, -19);
            break;
        }
    } else {
        switch (work->angle) {
        case 0x2D:
            SetBgScroll(1, -100, -6);
            break;
        case 0xD3:
            SetBgScroll(1, -73, -5);
            break;
        case 0x53:
            SetBgScroll(1, -101, -28);
            break;
        case 0xAD:
            SetBgScroll(1, -75, -29);
            break;
        }
    }
}

u8 task_romcri_eff2_1(RomcriEff2Work* work) {
    if (work->unk_00 % 4 == 0) {
        switch (work->unk_03) {
        case 0:
            LoadBgMap(1, gUnk_08F5C384, 0x800);
            break;
        case 1:
            EnableBg(1);
            LoadBgMap(1, gUnk_08F5CB84, 0x800);
            break;
        case 2:
            LoadBgMap(1, gUnk_08F5D384, 0x800);
            break;
        case 3:
            LoadBgMap(1, gUnk_08F5DB84, 0x800);
            break;
        case 4:
            LoadBgMap(1, gUnk_08F5D384, 0x800);
            break;
        case 5:
            LoadBgMap(1, gUnk_08F5CB84, 0x800);
            break;
        }

        work->unk_03++;

        if (work->unk_03 > 5) {
            work->unk_03 = 0;
        }
    }

    if (work->unk_00 > 30 && work->unk_03 == 0) {
        return 0;
    }

    work->unk_00++;
    return 1;
}

void task_romcri_eff2_3(void) {
    DisableBg(1);
}

u16 func_0803FDC8(RomcriList* list) {
    u16 total;
    s32 i;

    total = 0;

    for (i = 0; i < list->unk_00; i++) {
        total += gUnk_09EDA4EC[list->unk_04[i].unk_00];
    }

    return total;
}
