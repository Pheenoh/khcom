#include "task.h"

u8 GetAngle(s32 x0, s32 y0, s32 x1, s32 y1) {
    s32 dx;
    s32 dy;
    u8 angle;

    dx = x1 - x0;
    dy = y1 - y0;
    angle = 0;

    if (dx == 0 && dy == 0) {
        angle = 0;
    } else if (dx > 0 && dy < 0) {
        dy = -dy;

        if (dx <= dy) {
            angle = ((0x200000 / dy) * dx) >> 16;
        } else {
            angle = 0x40 - (((0x200000 / dx) * dy) >> 16);
        }
    } else if (dx > 0 && dy > 0) {
        if (dx <= dy) {
            angle = 0x7F - (((0x200000 / dy) * dx) >> 16);
        } else {
            angle = (((0x200000 / dx) * dy) >> 16) + 0x3F;
        }
    } else if (dx < 0 && dy > 0) {
        dx = -dx;

        if (dx <= dy) {
            angle = (((0x200000 / dy) * dx) >> 16) - 0x80;
        } else {
            angle = -0x40 - (((0x200000 / dx) * dy) >> 16);
        }
    } else if (dx < 0 && dy < 0) {
        dx = -dx;
        dy = -dy;

        if (dx <= dy) {
            angle = -1 - (((0x200000 / dy) * dx) >> 16);
        } else {
            angle = (((0x200000 / dx) * dy) >> 16) - 0x41;
        }
    } else if (dx == 0 && dy < 0) {
        angle = 0;
    } else if (dx == 0 && dy > 0) {
        angle = 0x80;
    } else if (dx < 0 && dy == 0) {
        angle = 0xC0;
    } else if (dx > 0 && dy == 0) {
        angle = 0x40;
    }

    return angle;
}

void UpdatePlayTime(void) {
    if (gFrameCounter % 60 == 0) {
        if (gGameState.playTime <= 0x57E3E) {
            gGameState.playTime++;
        }
    }
}

void func_0801CCB4(void) {
    func_080DFAF4(0, 0);
    gGameState.unk_17A = 0xE7FF;
    gGameState.unk_17C = 0x80;
    _08085D04(0);
    gGameState.flags |= 8;
    gGameState.flags |= 0x100;
    func_0800FDD0(0);
    func_0800FDD0(0x15);
    func_0800FDD0(0xED);
    func_0800FDD0(0x11);
    func_0800FDD0(0x16);
    func_0800FDD0(0xEF);
    func_0800FDD0(0xF3);
}

void func_0801CD20(void) {
    gGameState.unk_17C = 3;
    func_08085C3C();
    gGameState.flags &= ~8;
    func_0800FDD0(0x11);
    func_0800FDD0(0x12);
    func_0800FDD0(0x13);
    func_0800FDD0(0x14);
    func_0800FDD0(0x15);
    func_0800FDD0(0x16);
    func_080DFAF4(0, 10);
}
