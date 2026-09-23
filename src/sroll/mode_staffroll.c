#include "registration_data.h"
#include "system_state.h"
#include "mode.h"
#include "bos7.h"
#include "mode_staffroll.h"
#include "bos7_api.h"
#include "sprites_title.h"
#include "sprites_staff_roll.h"
#include "gba/io_reg.h"

StaffRollWork* gStaffRollWork;

void func_081125BC(StaffRollWork* w) {
    w->unk_078 = 0;
    w->unk_07C = 0;
    w->unk_080 = 0;
    gBldCnt = 0;
    gBldY = 0;
}

u8 func_081125D8(StaffRollWork* w) {
    u8 result;

    result = 1;
    if (w->unk_080 >= w->unk_07C) {
        gBldCnt &= ~BLDCNT_EFFECT_MASK;
        result = 0;
    }

    return result;
}

void func_08112600(StaffRollWork* w) {
    u16 v;

    if (w->unk_080 < w->unk_07C) {
        v = ((w->unk_080 << 12) / w->unk_07C) << 8 >> 16;
        w->unk_080 = w->unk_080 + 1;
    } else {
        v = 16;
        gBldCnt &= ~BLDCNT_EFFECT_MASK;
        gBldAlpha = 0;
        gBldY = 0;
    }

    switch (w->unk_078) {
    case 0:
    case 2:
        gBldY = 16 - v;
        break;
    case 1:
    case 3:
        gBldY = v;
        break;
    case 4:
        gBldAlpha = v;
        break;
    case 5:
        gBldAlpha = 16 - v;
        break;
    }
}

void func_081126A8(StaffRollWork* w, u16 flags, s32 dur) {
    w->unk_078 = 0;
    w->unk_07C = dur;
    w->unk_080 = 0;
    gBldCnt = flags | 0xE0;
    gBldY = 16;
}

void func_081126D0(StaffRollWork* w, u16 flags, s32 dur) {
    w->unk_078 = 1;
    w->unk_07C = dur;
    w->unk_080 = 0;
    gBldCnt = flags | 0xE0;
    gBldY = 0;
}

void func_081126F8(StaffRollWork* w, u16 flags, s32 dur) {
    w->unk_078 = 4;
    w->unk_07C = dur;
    w->unk_080 = 0;
    gBldCnt = flags | 0x40;
    gBldAlpha = 0;
}

void func_08112720(StaffRollWork* w, u16 flags, s32 dur) {
    w->unk_078 = 5;
    w->unk_07C = dur;
    w->unk_080 = 0;
    gBldCnt = flags | 0x40;
    gBldAlpha = 16;
}

u8* func_08112748(StaffRollWork* w) {
    return &w->unk_13C[w->unk_0CC[w->unk_0D0 + 3] * 0x2C];
}

void func_08112768(StaffRollWork* w) {
    StaffRollLabelArg arg;
    EvtObj* e;
    s32 run;
    s32 x;
    s32 y;

    if (w->unk_0CC == 0) {
        return;
    }

    run = 1;

    while (run != 0) {
        if (w->unk_0D4 != w->unk_0CC[w->unk_0D0 + 2]) {
            switch (w->unk_0D8) {
            case 5:
                if (w->unk_0F4 > w->unk_0E0) {
                    x = w->unk_0E4 + (w->unk_0EC - w->unk_0E4) * w->unk_0E0 / w->unk_0F4;
                    y = w->unk_0E0;
                    y = w->unk_0E8 + (w->unk_0F0 - w->unk_0E8) * y / w->unk_0F4;
                } else {
                    x = w->unk_0EC;
                    y = w->unk_0F0;
                    w->unk_0D8 = -1;
                    w->unk_0E0 = 0;
                }
                e = (EvtObj*)&w->unk_13C[w->unk_0DC * 0x2C];
                EvtObjSetPos(e, x, y, 0);
                w->unk_0E0++;
                break;
            case 8:
                if (w->unk_0F4 <= w->unk_0E0) {
                    w->unk_0D8 = -1;
                    w->unk_0E0 = 0;
                }
                w->unk_0E0++;
                break;
            }
            break;
        }

        w->unk_0D8 = -1;
        w->unk_0E0 = 0;

        switch (w->unk_0CC[w->unk_0D0]) {
        case 0:
            run = 0;
            continue;
        case 1:
            w->unk_0D0 = 0;
            w->unk_0D4 = 0;
            continue;
        case 2:
            e = (EvtObj*)func_08112748(w);
            EvtObjSetAnim(e, w->unk_0CC[w->unk_0D0 + 4]);
            break;
        case 3:
            e = (EvtObj*)func_08112748(w);
            func_0801CE00(e, w->unk_0CC[w->unk_0D0 + 4] | 0x400);
            break;
        case 4:
            e = (EvtObj*)func_08112748(w);
            EvtObjSetPos(e, w->unk_0CC[w->unk_0D0 + 4] << 8, w->unk_0CC[w->unk_0D0 + 5] << 8, 0);
            break;
        case 5:
            e = (EvtObj*)func_08112748(w);
            w->unk_0D8 = 5;
            w->unk_0DC = w->unk_0CC[w->unk_0D0 + 3];
            w->unk_0E4 = e->x;
            w->unk_0E8 = e->y;
            w->unk_0EC = w->unk_0CC[w->unk_0D0 + 4] << 8;
            w->unk_0F0 = w->unk_0CC[w->unk_0D0 + 5] << 8;
            w->unk_0F4 = w->unk_0CC[w->unk_0D0 + 6];
            break;
        case 6:
            w->unk_124[w->unk_0CC[w->unk_0D0 + 3] + 3] =
                func_0801CE04(w->tasks2, &gTaskDescSrollBChar, (EvtObj*)func_08112748(w), w->unk_0CC[w->unk_0D0 + 4],
                              w->unk_0CC[w->unk_0D0 + 5], 0x2800, 0xF000, 0);
            break;
        case 7:
            func_08000DE8(w->tasks2, (void*)w->unk_124[w->unk_0CC[w->unk_0D0 + 3] + 3]);
            break;
        case 8:
            w->unk_0D8 = 5;
            w->unk_0F4 = w->unk_0CC[w->unk_0D0 + 4];
            break;
        case 9:
            FadeStartIn(0, (u16)w->unk_0CC[w->unk_0D0 + 4]);
            break;
        case 10:
            FadeStartOut(0, (u16)w->unk_0CC[w->unk_0D0 + 4]);
            break;
        case 11:
            e = (EvtObj*)func_08112748(w);
            e->unk_16 |= 4;
            func_081126F8(w, 0x2000, w->unk_0CC[w->unk_0D0 + 4]);
            break;
        case 12:
            e = (EvtObj*)func_08112748(w);
            e->unk_16 |= 4;
            func_08112720(w, 0x2000, w->unk_0CC[w->unk_0D0 + 4]);
            break;
        case 13:
            e = (EvtObj*)func_08112748(w);
            e->unk_16 |= 4;
            break;
        case 14:
            e = (EvtObj*)func_08112748(w);
            e->unk_16 &= 0xFFFB;
            break;
        case 15:
            e = (EvtObj*)func_08112748(w);
            arg.unk_00 = w->unk_0CC[w->unk_0D0 + 4];
            arg.x = e->x;
            arg.y = e->y;
            TaskCreate(w->tasks2, &gTaskDescSrollBCrtn, &arg);
            break;
        case 16:
            func_081149B0((void*)w->unk_124[w->unk_0CC[w->unk_0D0 + 3] + 3],
                          w->unk_0CC[w->unk_0D0 + 4]);
            break;
        default:
            continue;
        }

        w->unk_0D0 += w->unk_0CC[w->unk_0D0 + 1];
    }

    w->unk_0D4++;
}

void mode_StaffRoll_0(void) {
    StaffRollWork* w;
    StaffRollWork** p;

    p = &gStaffRollWork;
    w = EwramAlloc(0x418);
    *p = w;
    SetBackdropColor(0, 0, 0);
    SpriteReset();
    w->palette = (u32)LoadObjPalette(gUnk_09D6BE74, 0x100);
    w->unk_000 = 1;
    w->unk_001 = 1;
    w->unk_008 = 0;
    w->unk_00C = 0;
    w->unk_010 = 0;
    w->unk_014 = 0;
    func_081125BC(w);
    w->unk_084 = 0;
    w->unk_08C = 0;
    w->unk_088 = 0;
    w->unk_090 = -1;
    w->unk_094 = 0;
    w->unk_098 = 0;
    w->unk_0A4 = 0;
    w->unk_0A0 = 0;
    w->unk_0A8 = 0;
    w->unk_0AC = 0;
    w->unk_0B0 = -1;
    w->unk_0B8 = 0;
    w->unk_0BC = 0;
    w->unk_0C0 = 0;
    w->unk_0C4 = 0;
    w->unk_0C8 = 0;
    w->unk_0CC = 0;
    w->unk_0D0 = 0;
    w->unk_0D4 = 0;
    w->unk_0D8 = -1;
    w->unk_0E0 = 0;
    TaskPoolInit(w->tasks, 32);
    TaskPoolInit(w->tasks2, 32);
    w->unk_124[0] = 0;
    w->unk_124[1] = 0;
    w->unk_124[2] = 0;
    w->unk_124[4] = 0;
    w->unk_124[5] = 0;
    *(s32*)w->unk_13C = 0;
}

u8 func_08112C24(StaffRollWork* w) {
    u8 result;

    result = 1;
    if (w->unk_00C > 74) {
        result = 0;
    }
    w->unk_00C++;

    return result;
}

u8 func_08112C38(StaffRollWork* w) {
    StaffRollTaskArg arg;
    u8 result;
    s32 z;

    result = 1;

    if ((gGameState.flags & 8) != 0) {
        w->scene = gUnk_09A53D50;
    } else {
        w->scene = gUnk_09A538D8;
    }

    switch (w->unk_084) {
    case 0:
        SetBgMode1();
        SetupBg(0, 0, 28, 0);
        SetupBg(1, 0, 29, 0);
        SetupBg(2, 0, 30, 11);
        SetupBg(3, 0, 31, 0);
        SetBgPriority(0, 0);
        SetBgPriority(1, 0);
        SetBgPriority(2, 0);
        SetBgPriority(3, 0);
        SetBgSize(0, 0);
        SetBgSize(1, 0);
        SetBgSize(2, 0x4000);
        SetBgSize(3, 0x4000);
        SetBgScroll(0, 0, 0);
        SetBgScroll(1, 0, 0);
        SetBgScroll(2, 0, 0);
        SetBgScroll(3, 0, 0);
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        SetBgColorMode(0, 0x80);

        if (w->unk_090 != w->unk_094) {
            w->unk_090 = w->unk_094;

            if (w->scene[w->unk_090].unk_00 == 1) {
                SetBgColorMode(0, 0x80);
            } else {
                SetBgColorMode(0, 0);
            }

            EnableBg(0);
            LoadBgTiles(0, w->scene[w->unk_090].tiles, w->scene[w->unk_090].tilesSize);
            LoadBgMap(0, w->scene[w->unk_090].map, w->scene[w->unk_090].mapSize);
            LoadBgPalette(0, w->scene[w->unk_090].palette, w->scene[w->unk_090].paletteSize);
            SetBgScroll(0, (u16) - (w->scene[w->unk_090].x >> 8),
                        (u16) - (w->scene[w->unk_090].y >> 8));
        }

        w->unk_084 = 1;
        w->unk_08C = 0;
    case 1:
    {
        u8 t;

            if (w->unk_08C == 0) {
                if (w->scene[w->unk_090].unk_01 == 1) {
                    func_081126A8(w, 17, 30);
                } else {
                    func_081126A8(w, 16, 30);
                }
                w->unk_08C++;
            }

            func_08112600(w);
            t = func_081125D8(w);
            if (t != 0) {
                break;
            }

            arg.unk_00 = t;
            arg.unk_02 = w->scene[w->unk_090].unk_30;
            arg.unk_04 = t;
            arg.x = 0x14000;
            arg.y = w->scene[w->unk_090].targetY;
            arg.targetX = w->scene[w->unk_090].targetX;
            arg.targetY = w->scene[w->unk_090].targetY;
            w->unk_124[0] = (s32)TaskCreate(w->tasks, &gTaskDescSrollAName, &arg);
            arg.unk_00 = 1;
            arg.unk_02 = 1;
            arg.unk_04 = w->scene[w->unk_090].unk_32;
            arg.x = -0x5000;
            z = 0x7800;
            arg.targetX = z;
            w->unk_124[1] = (s32)TaskCreate(w->tasks, &gTaskDescSrollAName, &arg);
            arg.unk_00 = 2;
            arg.unk_02 = w->scene[w->unk_090].unk_30;
            arg.unk_04 = w->scene[w->unk_090].unk_32;
            arg.x = z;
            w->unk_124[2] = (s32)TaskCreate(w->tasks, &gTaskDescSrollAName, &arg);
            w->unk_084 = 2;
            w->unk_08C = t;
            break;
    }
    case 2:
        w->unk_088++;
        if (w->unk_088 >= w->scene[w->unk_090].unk_04) {
            w->unk_084 = 3;
            w->unk_08C = 0;
            w->unk_088 = 0;
            break;
        }
        if ((w->flags & 1) != 0 || (w->unk_004 & 0x100) != 0) {
            w->unk_084 = 3;
            w->unk_08C = 0;
            w->unk_088 = 0;
            break;
        }
        if ((w->flags & 2) == 0) {
            break;
        }
        func_08000DE8(w->tasks, (void*)w->unk_124[0]);
        func_08000DE8(w->tasks, (void*)w->unk_124[1]);
        func_08000DE8(w->tasks, (void*)w->unk_124[2]);
        w->unk_010 = 0x1518;
        w->unk_084 = 4;
        w->unk_08C = 0;
        w->unk_088 = 0;
        break;
    case 3:
    {
        u8 t;

            if (w->unk_08C == 0) {
                if (w->scene[w->unk_090].unk_02 == 1) {
                    func_081126D0(w, 17, 30);
                } else {
                    func_081126D0(w, 16, 30);
                }
                w->unk_08C++;
            }

            func_08112600(w);
            t = func_081125D8(w);
            if (t != 0) {
                break;
            }

            if (w->scene[w->unk_090].unk_02 == 1) {
                DisableBg(0);
            }

            func_08000DE8(w->tasks, (void*)w->unk_124[0]);
            func_08000DE8(w->tasks, (void*)w->unk_124[1]);
            func_08000DE8(w->tasks, (void*)w->unk_124[2]);
            w->unk_094 = w->unk_090 + 1;

            if (w->unk_094 > 21) {
                w->unk_084 = 4;
            } else {
                w->unk_084 = t;
            }

            w->unk_08C = 0;
            w->unk_088 = 0;
            break;
    }
    case 4:
    {
        s32 v;

        v = w->unk_098 + 64;
        w->unk_098 = v;

        if (v > 0x1BFF) {
            SetBgScroll(0, (u16) - (w->scene[w->unk_090].x >> 8),
                        (u16)(-(w->scene[w->unk_090].y >> 8) + 28));
            if (w->unk_098 > 0x4000) {
                w->unk_084 = 6;
                w->unk_08C = 0;
                w->unk_088 = 0;
            }
        } else {
            SetBgScroll(0, (u16) - (w->scene[w->unk_090].x >> 8),
                        (u16)(-(w->scene[w->unk_090].y >> 8) + (v >> 8)));
        }
        break;
    }
    case 5:
        break;
    case 6:
        if (w->unk_08C == 0) {
            func_081126D0(w, 17, 120);
            w->unk_08C++;
        }
        func_08112600(w);
        if (func_081125D8(w) == 0) {
            result = 0;
        }
        break;
    }

    return result;
}

#ifdef VERSION_JP
#define STAFFROLL_SCROLL_FRAMES 0x4321
#define STAFFROLL_SCROLL_SPEED 0x16000000
#define STAFFROLL_SCRIPT_PERIOD 635
#else
#ifdef VERSION_EU
#define STAFFROLL_SCROLL_FRAMES 0x431C
#define STAFFROLL_SCROLL_SPEED 0x15800000
#define STAFFROLL_SCRIPT_PERIOD 635
#else
#define STAFFROLL_SCROLL_FRAMES 0x431C
#define STAFFROLL_SCROLL_SPEED 0x13C00000
#define STAFFROLL_SCRIPT_PERIOD 627
#endif
#endif

u8 func_08113180(StaffRollWork* w) {
    u8 buf[80];
    StaffRollLogoArg logo;
    StaffRollSecnArg secn;
    u8 result;
    s32 i;
    u32 row;
    u8* s;
    s32 loop;
    s32 x;
    u32 y;
    s32 total;
    s32 wa;
    s32 wb;
    s32 wc;
    s32 w1;
    s32 n;
    s32 t;
    s32 sub;
    s32 idx;

    result = 1;

    switch (w->unk_0A4) {
    case 0:
        func_081125BC(w);
        SetBgMode1();
        SetupBg(0, 0, 28, 0);
        SetupBg(1, 0, 29, 0);
        SetupBg(2, 0, 30, 11);
        SetupBg(3, 0, 31, 0);
        SetBgPriority(0, 0);
        SetBgPriority(1, 0);
        SetBgPriority(2, 0);
        SetBgPriority(3, 0);
        SetBgSize(0, 0);
        SetBgSize(1, 0);
        SetBgSize(2, 0x4000);
        SetBgSize(3, 0x4000);
        SetBgScroll(0, 0, 0);
        SetBgScroll(1, 0, 0);
        SetBgScroll(2, 0, 0);
        SetBgScroll(3, 0, 0);
        EnableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);

        for (i = 0; i < 32; i++) {
            FadeSetPaletteExcluded(i, 1);
        }

        SrollTextInit(w->unk_1C0, gUnk_09A541C8);
        LoadBgPalette(0, gUnk_09D6BE14, 32);
        (*(volatile u16*)&gDispCnt) |= 0;
        gWinIn = (WININ_WIN0_BG0 | WININ_WIN0_BG1 | WININ_WIN0_BG2 | WININ_WIN0_BG3 | WININ_WIN0_OBJ);
        gWinOut = (WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ);
        gWin0H = 0x10E0;
        gWin0V = 0x898;
        w->unk_0A4 = 1;
        w->unk_0A8 = 0;
    case 1:
        w->unk_0B4 = STAFFROLL_SCROLL_SPEED / ((STAFFROLL_SCROLL_FRAMES - w->unk_010) << 8);
        w->unk_0A4 = 2;
        w->unk_0A8 = 0;
        break;
    case 2:
        w->unk_0B8 += w->unk_0B4;
        sub = w->unk_0B8 >> 8;
        row = w->unk_0B8 >> 11;

        if (sub % 8 == 0 && w->unk_0B0 != row) {
            s = gUnk_09EF9F54[row];

            if (w->unk_0A0 == 0 && s == 0) {
                w->unk_0B4 = 0;
                w->unk_0A0 = 1;
            }

            if (*s != '!') {
                SrollTextClearRect(w->unk_1C0, 0, (row + 20) & 31, 30, 2, 1);
            }

            if (w->unk_0A0 == 0) {
                SrollTextSetColors(w->unk_1C0, 15, 13, 0, 14);
                loop = 1;

                while (loop) {
                    switch (*s) {
                    case '!':
                        loop = 0;
                        break;
                    case '*':
                        switch (s[1]) {
                        case 'D':
                            logo.unk_10 = 0;
                            break;
                        case 'S':
                            logo.unk_10 = 1;
                            break;
                        case 'J':
                            logo.unk_10 = 2;
                            break;
                        }
                        logo.unk_00 = 0x7800;
                        logo.unk_04 = ((w->unk_0B8 >> 8) + 168) << 8;
                        logo.unk_08 = &w->unk_0B8;
                        logo.unk_0C = &w->unk_0B4;
                        TaskCreate(w->tasks2, &gTaskDescSrollBLogo, &logo);
                        loop = 0;
                        break;
                    case '<':
                        secn.unk_00 = w->unk_014;
                        secn.unk_04 = 0x17800;
                        secn.unk_08 = ((w->unk_0B8 >> 8) + 168) << 8;
                        secn.unk_0C = &w->unk_0B8;
                        secn.unk_10 = &w->unk_0B4;
                        TaskCreate(w->tasks2, &gTaskDescSrollBSecn, &secn);
                        w->unk_014++;
                        loop = 0;
                        break;
                    case '[':
                        secn.unk_00 = -1;
                        secn.unk_04 = 0x7800;
                        secn.unk_08 = ((w->unk_0B8 >> 8) + 168) << 8;
                        secn.unk_0C = &w->unk_0B8;
                        secn.unk_10 = &w->unk_0B4;
                        TaskCreate(w->tasks2, &gTaskDescSrollBSecn, &secn);
                        loop = 0;
                        break;
                    case '#':
                        SrollTextSelectFont(w->unk_1C0, s[1] - '0');
                        s += 2;
                        break;
                    case '@':
                        SrollTextSetColors(w->unk_1C0, 7, 5, 0, 6);
                        s++;
                        break;
                    case '~':
                        s++;
                        wa = SrollTextMeasureWidth(w->unk_1C0, s);
                        wb = SrollTextMeasureWidth(w->unk_1C0, gUnk_09EFA9C0);
                        wc = SrollTextMeasureWidth(w->unk_1C0, gUnk_09EFA9BC);
                        w1 = wa - wb + wc * 3;
                        x = (240 - w1) >> 1;
                        SrollTextSetColors(w->unk_1C0, 7, 5, 0, 6);

                        for (n = 0; s[n] != '~'; n++) {
                            buf[n] = s[n];
                        }

                        buf[n] = ' ';
                        buf[n + 1] = ' ';
                        buf[n + 2] = ' ';
                        buf[n + 3] = 0;
                        w1 = SrollTextMeasureWidth(w->unk_1C0, buf);
                        SrollTextDrawStringAtPixelX(w->unk_1C0, x, (row + 20) & 31, buf, 1);
                        s += n + 1;

                        for (n = 0; s[n] != 0; n++) {
                            buf[n] = s[n];
                        }

                        buf[n] = 0;
                        SrollTextSetColors(w->unk_1C0, 15, 13, 0, 14);
                        SrollTextDrawStringAtPixelX(w->unk_1C0, x + w1, (row + 20) & 31, buf, 1);
                        loop = 0;
                        break;
                    case '=':
                        SrollTextDrawStringAtPixelX(w->unk_1C0, (240 - SrollTextMeasureWidth(w->unk_1C0, s + 1)) >> 1, (row + 20) & 31, s + 1, 1);
                        loop = 0;
                        break;
                    case '-':
                        SrollTextDrawStringAtPixelX(w->unk_1C0, 0, (row + 20) & 31, s + 1, 1);
                        loop = 0;
                        break;
                    case '+':
                        SrollTextDrawStringAtPixelX(w->unk_1C0, 240 - SrollTextMeasureWidth(w->unk_1C0, s + 1), (row + 20) & 31, s + 1, 1);
                        loop = 0;
                        break;
                    default:
                        SrollTextDrawStringAtPixelX(w->unk_1C0, (240 - SrollTextMeasureWidth(w->unk_1C0, s)) >> 1, (row + 20) & 31, s, 1);
                        loop = 0;
                        break;
                    }
                }
            }
        }

        w->unk_0B0 = row;
        t = w->unk_0A8;

        if (t % STAFFROLL_SCRIPT_PERIOD == 60) {
            w->unk_0CC = 0;
            idx = t / STAFFROLL_SCRIPT_PERIOD;

            if (idx <= 16) {
                if ((gGameState.flags & 8) != 0) {
                    w->unk_0CC = gUnk_09EFA978[idx];
                } else {
                    w->unk_0CC = gUnk_09EFA934[idx];
                }
            }

            w->unk_0D0 = 0;
            w->unk_0D4 = 0;
            w->unk_0D8 = -1;
            w->unk_0E0 = 0;
        }

        w->unk_0A8++;
        SetBgScroll(0, 0, (u16)(w->unk_0B8 >> 8));

        if (w->unk_010 >= STAFFROLL_SCROLL_FRAMES || (w->flags & 2) != 0) {
            w->unk_0A4 = 4;
            w->unk_0A8 = 0;
        }
        break;
    case 4:
        w->unk_0A8++;
        if (w->unk_0A8 > 120) {
            w->unk_0A4 = 3;
            w->unk_0A8 = 0;
        }
        break;
    case 3:
        for (i = 0; i < 32; i++) {
            FadeSetPaletteExcluded(i, 0);
        }

        (*(volatile u16*)&gDispCnt) &= ~DISPCNT_WIN0_ON;
        gWinIn = 0;
        gWinOut = 0;
        gWin0H = 0;
        gWin0V = 0;
        result = 0;
        break;
    }

    func_08112768(w);
    TaskPoolUpdate(w->tasks2);
    TaskPoolDraw(w->tasks2);
    func_08112600(w);

    return result;
}

u8 func_0811394C(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0A4) {
    case 0:
        TaskPoolDestroy(w->tasks2);
        DisableBg(0);
        DisableBg(1);
        EnableBg(2);
        DisableBg(3);
        LoadBgTiles(2, gUnk_097CF758, 0x3F00);
        LoadBgMap(2, gUnk_0983FB98, 0x400);
        LoadBgPalette(2, gUnk_0984A618, 0xA0);
        SetBgAffine(2, 0, 0x100, 0x100, 0x7800, 0x5C00);
        w->unk_0A4 = 1;
        w->unk_0A8 = 0;
        break;
    case 1:
        if (w->unk_0A8 == 0) {
            FadeStartIn(0, 1);
            w->unk_0A8++;
        }
        t = FadeIsActive();
        if (t == 0) {
            w->unk_0A4 = 2;
            w->unk_0A8 = 0;
        }
        break;
    case 2:
        w->unk_0A8++;
        if (w->unk_0A8 > 179) {
            w->unk_0A4 = 3;
            w->unk_0A8 = 0;
        }
        break;
    case 3:
        if (w->unk_0A8 == 0) {
            FadeStartOut(0, 120);
            w->unk_0A8++;
        }
        t = FadeIsActive();
        if (t == 0) {
            w->unk_0A4 = 4;
            w->unk_0A8 = 0;
        }
        break;
    case 4:
        w->unk_0A8++;
        if (w->unk_0A8 > 119) {
            BlockAudioStop();
            result = 0;
        }
        break;
    }

    return result;
}

#ifdef VERSION_JP
#define STAFFROLL_HOLD_FRAMES 720
#else
#define STAFFROLL_HOLD_FRAMES 900
#endif

u8 func_08113A94(StaffRollWork* w) {
    u8 result;

    result = 1;

    switch (w->unk_0BC) {
    case 0:
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0BC = 1;
        w->unk_0C0 = 0;
        break;
    case 1:
        if (w->unk_0C0 == 0) {
            FadeStartIn(0, 60);
            w->unk_0C0++;
        }
        if (FadeIsActive() == 0) {
            if ((gGameState.flags & 8) != 0) {
                w->unk_124[0] = (s32)TaskCreate(w->tasks, &gTaskDescSrollCChar, (void*)1);
            } else {
                w->unk_124[0] = (s32)TaskCreate(w->tasks, &gTaskDescSrollCChar, (void*)0);
            }
            w->unk_0BC = 2;
            w->unk_0C0 = 0;
        }
        break;
    case 2:
        w->unk_0C0++;
        if ((gGameState.flags & 8) != 0) {
            if (w->unk_0C0 >= STAFFROLL_HOLD_FRAMES) {
                w->unk_0BC = 3;
                w->unk_0C0 = 0;
            }
        } else {
            if (w->unk_0C0 >= 900) {
                w->unk_0BC = 3;
                w->unk_0C0 = 0;
            }
        }
        break;
    case 3:
        if (w->unk_0C0 == 0) {
            FadeStartOut(0, 120);
            w->unk_0C0++;
        }
        if (FadeIsActive() == 0) {
            result = 0;
        }
        break;
    }

    return result;
}

u8 func_08113BB4(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0BC) {
    case 0:
        if (w->unk_0C0 <= 119) {
            w->unk_0C0++;
            break;
        }
        SetBgMode0();
        SetupBg(0, 0, 28, 0);
        SetupBg(1, 0, 30, 0);
        SetupBg(2, 0, 31, 0);
        SetupBg(3, 0, 31, 0);
        SetBgPriority(0, 0);
        SetBgPriority(1, 0);
        SetBgPriority(2, 0);
        SetBgPriority(3, 0);
        SetBgSize(0, 0x8000);
        SetBgSize(1, 0);
        SetBgSize(2, 0);
        SetBgSize(3, 0);
        SetBgScroll(0, 0, 0);
        SetBgScroll(1, 0, 0);
        SetBgScroll(2, 0, 0);
        SetBgScroll(3, 0, 0);
        EnableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        LoadBgTiles(0, gUnk_09D09674, 0x7200);
        LoadBgMap(0, gUnk_09D65274, 0x1000);
        LoadBgPalette(0, gUnk_09D6BF74, 0x200);
        SetBgScroll(0, 0, 160);
        w->unk_0BC = 1;
        w->unk_0C0 = 0;
    case 1:
        if (w->unk_0C0 == 0) {
            FadeStartIn(0, 120);
            w->unk_0C0++;
        }
        t = FadeIsActive();
        if (t == 0) {
            w->unk_0BC = 2;
            w->unk_0C0 = 0;
        }
        break;
    case 2:
        SetBgScroll(0, 0, (u16)(160 - (w->unk_0C0 >> 1)));
        if (w->unk_0C0 <= 255) {
            w->unk_0C0++;
        }
        if (w->unk_0C0 > 255) {
            w->unk_0BC = 3;
            w->unk_0C0 = 0;
        }
        break;
    case 3:
        w->unk_0C0++;
        if (w->unk_0C0 > 179) {
            w->unk_0BC = 4;
            w->unk_0C0 = 0;
        }
        break;
    case 4:
        if (w->unk_0C0 == 0) {
            SetBackdropColor(31, 31, 31);
            FadeStartOut(1, 120);
            w->unk_0C0++;
        }
        if (FadeIsActive() == 0) {
            SetBgScroll(0, 0, 0);
            result = 0;
        }
        break;
    }

    return result;
}

u8 func_08113DB8(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0BC) {
    case 0:
        LoadBgTiles(0, gUnk_09D10874, 0x53C0);
        LoadBgMap(0, gUnk_09D66274, 0x800);
        LoadBgPalette(0, gUnk_09D6C174, 0x200);
        w->unk_0BC = 1;
        w->unk_0C0 = 0;
    case 1:
        if (w->unk_0C0 == 0) {
            FadeStartIn(1, 120);
            w->unk_0C0++;
        }
        t = FadeIsActive();
        if (t == 0) {
            SetBackdropColor(0, 0, 0);
            w->unk_0BC = 2;
            w->unk_0C0 = 0;
        }
        break;
    case 2:
        w->unk_0C0++;
        if (w->unk_0C0 > 179) {
            w->unk_0BC = 3;
            w->unk_0C0 = 0;
        }
        break;
    case 3:
        if (w->unk_0C0 == 0) {
            FadeStartOut(0, 60);
            w->unk_0C0++;
        }
        if (FadeIsActive() == 0) {
            result = 0;
        }
        break;
    }

    return result;
}

u8 func_08113E94(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0BC) {
    case 0:
        if (w->unk_0C0 <= 119) {
            w->unk_0C0++;
            break;
        }
        SetBgMode0();
        SetupBg(0, 0, 28, 0);
        SetupBg(1, 0, 30, 0);
        SetupBg(2, 0, 31, 0);
        SetupBg(3, 0, 31, 0);
        SetBgPriority(0, 0);
        SetBgPriority(1, 0);
        SetBgPriority(2, 0);
        SetBgPriority(3, 0);
        SetBgSize(0, 0x8000);
        SetBgSize(1, 0);
        SetBgSize(2, 0);
        SetBgSize(3, 0);
        SetBgScroll(0, 0, 0);
        SetBgScroll(1, 0, 0);
        SetBgScroll(2, 0, 0);
        SetBgScroll(3, 0, 0);
        EnableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        LoadBgTiles(0, gUnk_09D15C34, 0x53C0);
        LoadBgMap(0, gUnk_09D66A74, 0x800);
        LoadBgPalette(0, gUnk_09D6C374, 0x200);
        w->unk_0BC = 1;
        w->unk_0C0 = 0;
    case 1:
        if (w->unk_0C0 == 0) {
            FadeStartIn(0, 120);
            w->unk_0C0++;
        }
        t = FadeIsActive();
        if (t == 0) {
            w->unk_0BC = 2;
            w->unk_0C0 = 0;
        }
        break;
    case 2:
        w->unk_0C0++;
        if (w->unk_0C0 > 179) {
            w->unk_0BC = 3;
            w->unk_0C0 = 0;
        }
        break;
    case 3:
        if (w->unk_0C0 == 0) {
            SetBackdropColor(31, 31, 31);
            FadeStartOut(1, 120);
            w->unk_0C0++;
        }
        if (FadeIsActive() == 0) {
            result = 0;
        }
        break;
    }

    return result;
}

u8 func_08114048(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0BC) {
    case 0:
        LoadBgTiles(0, gUnk_09D1AFF4, 0x53C0);
        LoadBgMap(0, gUnk_09D67274, 0x800);
        LoadBgPalette(0, gUnk_09D6C574, 0x200);
        w->unk_0BC = 1;
        w->unk_0C0 = 0;
    case 1:
        if (w->unk_0C0 == 0) {
            FadeStartIn(1, 120);
            w->unk_0C0++;
        }
        t = FadeIsActive();
        if (t == 0) {
            w->unk_0BC = 2;
            w->unk_0C0 = 0;
        }
        break;
    case 2:
        w->unk_0C0++;
        if (w->unk_0C0 > 179) {
            w->unk_0BC = 3;
            w->unk_0C0 = 0;
        }
        break;
    case 3:
        if (w->unk_0C0 == 0) {
            FadeStartOut(1, 120);
            w->unk_0C0++;
        }
        if (FadeIsActive() == 0) {
            result = 0;
        }
        break;
    }

    return result;
}

u8 func_0811411C(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0BC) {
    case 0:
        LoadBgTiles(0, gUnk_09D203B4, 0x53C0);
        LoadBgMap(0, gUnk_09D67A74, 0x800);
        LoadBgPalette(0, gUnk_09D6C774, 0x200);
        w->unk_0BC = 1;
        w->unk_0C0 = 0;
    case 1:
        if (w->unk_0C0 == 0) {
            FadeStartIn(1, 120);
            w->unk_0C0++;
        }
        t = FadeIsActive();
        if (t == 0) {
            SetBackdropColor(0, 0, 0);
            w->unk_0BC = 2;
            w->unk_0C0 = 0;
        }
        break;
    case 2:
        w->unk_0C0++;
        if (w->unk_0C0 > 179) {
            w->unk_0BC = 3;
            w->unk_0C0 = 0;
        }
        break;
    case 3:
        if (w->unk_0C0 == 0) {
            FadeStartOut(0, 60);
            w->unk_0C0++;
        }
        if (FadeIsActive() == 0) {
            result = 0;
        }
        break;
    }

    return result;
}

u8 func_081141F8(StaffRollWork* w) {
    u8 result;
    u8 t;

    result = 1;

    switch (w->unk_0C4) {
    case 0:
        DisableBg(0);
        EnableBg(1);
        DisableBg(2);
        DisableBg(3);
        SetBgScroll(1, 0, 0);
        SetBgColorMode(1, 0x80);

        if ((gGameState.flags & 8) != 0) {
#ifdef VERSION_EU
            switch (gLanguage) {
            case 0:
                LoadBgMap(1, gUnkEu_09DD69A0, 0x800);
                break;
            case 1:
                LoadBgMap(1, gUnkEu_09DD71A0, 0x800);
                break;
            case 4:
                LoadBgMap(1, gUnkEu_09DD79A0, 0x800);
                break;
            case 3:
                LoadBgMap(1, gUnkEu_09DD81A0, 0x800);
                break;
            case 2:
            default:
                LoadBgMap(1, gUnkEu_09DD89A0, 0x800);
                break;
            }
            LoadBgTiles(1, gUnk_09D2B334, 0x45C0);
            LoadBgPalette(1, gUnk_09D6CB74, 0x200);
#else
            LoadBgTiles(1, gUnk_09D2B334, 0x7F40);
            LoadBgMap(1, gUnk_09D68A74, 0x800);
            LoadBgPalette(1, gUnk_09D6CB74, 0x200);
#endif
        } else {
#ifdef VERSION_EU
            switch (gLanguage) {
            case 0:
                LoadBgMap(1, gUnk_09D68274, 0x800);
                break;
            case 1:
                LoadBgMap(1, gUnk_09D68A74, 0x800);
                break;
            case 4:
                LoadBgMap(1, gUnkEu_09DD51A0, 0x800);
                break;
            case 3:
                LoadBgMap(1, gUnkEu_09DD59A0, 0x800);
                break;
            case 2:
            default:
                LoadBgMap(1, gUnkEu_09DD61A0, 0x800);
                break;
            }
            LoadBgTiles(1, gUnk_09D25774, 0x5140);
            LoadBgPalette(1, gUnk_09D6C974, 0x200);
#else
            LoadBgTiles(1, gUnk_09D25774, 0x5BC0);
            LoadBgMap(1, gUnk_09D68274, 0x800);
            LoadBgPalette(1, gUnk_09D6C974, 0x200);
#endif
        }

        m4aSongNumStart(6);
        w->unk_0C4 = 1;
        w->unk_0C8 = 0;
        break;
    case 1:
        w->unk_0C8++;
        if (w->unk_0C8 > 59) {
            w->unk_0C4 = 2;
            w->unk_0C8 = 0;
        }
        break;
    case 2:
        if (w->unk_0C8 == 0) {
            FadeStartIn(0, 120);
            w->unk_0C8++;
        }
        t = FadeIsActive();
        if (t == 0) {
            w->unk_0C4 = 3;
            w->unk_0C8 = 0;
        }
        break;
    default:
        if ((GetKeysPressed() & (A_BUTTON | START_BUTTON)) != 0) {
            result = 0;
        }
        break;
    }

    return result;
}

void mode_StaffRoll_1(void) {
    StaffRollWork* w;
    u16 tmp;

    w = gStaffRollWork;
    w->unk_004 = 0;
    w->flags = 0;

    switch (w->unk_008) {
    case 0:
        if (func_08112C24(w) != 0) {
            break;
        }
        w->unk_008 = 1;
        w->unk_00C = 0;
        w->unk_010 = 0;
        BlockAudioStart();
    case 1:
    {
        vu32* dma;

        if (func_08112C38(w) != 0) {
            break;
        }
        w->unk_008 = 2;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)REG_ADDR_DMA3;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x2000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0A4 = 0;
        w->unk_0A8 = 0;
        break;
    }
    case 2:
    {
        vu32* dma;

        if (func_08113180(w) != 0) {
            break;
        }
        w->unk_008 = 3;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)REG_ADDR_DMA3;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x2000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0A4 = 0;
        w->unk_0A8 = 0;
        break;
    }
    case 3:
    {
        vu32* dma;

        if (func_0811394C(w) != 0) {
            break;
        }
        tmp = 0;
        dma = (vu32*)REG_ADDR_DMA3;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x2000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        if ((gGameState.flags & 8) != 0) {
            w->unk_008 = 7;
            w->unk_0BC = 0;
        } else {
            w->unk_008 = 5;
            w->unk_0BC = 0;
        }
        w->unk_00C = 0;
        w->unk_0C0 = 0;
        break;
    }
    case 4:
    {
        vu32* dma;

        if (func_08113A94(w) != 0) {
            break;
        }
        w->unk_008 = 10;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)REG_ADDR_DMA3;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x2000;
        dma[2];
        w->unk_0C4 = 0;
        w->unk_0C8 = 0;
        break;
    }
    case 5:
    {
        vu32* dma;

        if (func_08113BB4(w) != 0) {
            break;
        }
        w->unk_008 = 6;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)REG_ADDR_DMA3;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x2000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0BC = 0;
        w->unk_0C0 = 0;
        break;
    }
    case 6:
    {
        vu32* dma;

        if (func_08113DB8(w) != 0) {
            break;
        }
        w->unk_008 = 4;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)REG_ADDR_DMA3;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x2000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0BC = 0;
        w->unk_0C0 = 0;
        break;
    }
    case 7:
    {
        vu32* dma;

        if (func_08113E94(w) != 0) {
            break;
        }
        w->unk_008 = 8;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)REG_ADDR_DMA3;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x2000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0BC = 0;
        w->unk_0C0 = 0;
        break;
    }
    case 8:
    {
        vu32* dma;

        if (func_08114048(w) != 0) {
            break;
        }
        w->unk_008 = 9;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)REG_ADDR_DMA3;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x2000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0BC = 0;
        w->unk_0C0 = 0;
        break;
    }
    case 9:
    {
        vu32* dma;

        if (func_0811411C(w) != 0) {
            break;
        }
        w->unk_008 = 4;
        w->unk_00C = 0;
        tmp = 0;
        dma = (vu32*)REG_ADDR_DMA3;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06000000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06004000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x06008000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x20;
        dma[2];
        tmp = 0;
        dma[0] = (vu32)&tmp;
        dma[1] = 0x0600C000;
        dma[2] = ((DMA_ENABLE | DMA_SRC_FIXED) << 16) | 0x2000;
        dma[2];
        DisableBg(0);
        DisableBg(1);
        DisableBg(2);
        DisableBg(3);
        w->unk_0BC = 0;
        w->unk_0C0 = 0;
        break;
    }
    case 10:
        if (func_081141F8(w) != 0) {
            break;
        }
        w->unk_008 = 11;
        w->unk_00C = 0;
        break;
    case 11:
        if (w->unk_00C == 0) {
            FadeStartOut(0, 120);
        }
        w->unk_00C++;
        if (w->unk_00C > 120) {
#ifdef VERSION_EU
            eu_0800115C();
#else
            SoftReset(0xFF);
#endif
        }
        break;
    }

    TaskPoolUpdate(w->tasks);
    TaskPoolDraw(w->tasks);
    BlockAudioUpdate();
    w->unk_010++;
}

void mode_StaffRoll_2(void) {
    StaffRollWork* w;

    w = gStaffRollWork;
    ReleaseObjPalette((void*)w->palette);
    TaskPoolDestroy(w->tasks);

    if (gStaffRollWork != 0) {
        EwramFree(w);
        gStaffRollWork = 0;
    }
}

s32 func_08114748(s32 x) {
    return x * x;
}

s32 func_08114750(s32 x) {
    return x * x;
}

const char gModeNameStaffRoll[] = "mode_StaffRoll";

Mode gModeStaffRoll = {
    gModeNameStaffRoll,
    (void (*)(s32))mode_StaffRoll_0,
    (void (*)(void))mode_StaffRoll_1,
    (void (*)(void))mode_StaffRoll_2,
};
