#include "types.h"

typedef struct {
    u32 unk_00;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
} VsPoint;

typedef struct {
    u32 count;
    const VsPoint* points;
    u32 unk_08;
} VsPointList;

const VsPoint gUnk_08130E6C[] = {
    { 0, 25, -25, 0, 0 },
    { 0, 65, -12, 0, 1 },
    { 0, 85, 12, 0, 2 },
    { 0, 55, 25, 0, 3 },
    { 0, -55, 25, 0, 4 },
    { 0, -85, 12, 0, 5 },
    { 0, -65, -12, 0, 6 },
    { 0, -25, -25, 0, 7 },
};

const VsPointList gUnk_08130ECC = { 8, gUnk_08130E6C, 60 };

const VsPoint gUnk_08130ED8[] = {
    { 0, 90, 0, 0, 0 },
    { 0, 55, 25, 0, 1 },
    { 0, 40, 0, 0, 2 },
    { 0, 25, -25, 0, 3 },
    { 0, -25, -25, 0, 4 },
    { 0, -55, 25, 0, 5 },
    { 0, -64, 0, 0, 6 },
};

const VsPointList gUnk_08130F2C = { 7, gUnk_08130ED8, 60 };

const VsPoint gUnk_08130F38[] = {
    { 0, 25, -25, 0, 0 },
    { 0, 40, 0, 0, 1 },
    { 0, 25, 25, 0, 2 },
    { 0, -25, 25, 0, 3 },
    { 0, -40, 0, 0, 4 },
    { 0, -25, -25, 0, 5 },
};

const VsPointList gUnk_08130F80 = { 6, gUnk_08130F38, 60 };

const VsPoint gUnk_08130F8C[] = {
    { 0, 25, -25, 0, 0 },
    { 0, 40, 0, 0, 1 },
    { 0, 55, 25, 0, 2 },
    { 0, -55, -25, 0, 3 },
    { 0, -40, 0, 0, 4 },
    { 0, -25, 25, 0, 5 },
};

const VsPointList gUnk_08130FD4 = { 6, gUnk_08130F8C, 60 };

const VsPoint gUnk_08130FE0[] = {
    { 0, 90, 0, 0, 0 },
    { 0, 64, 0, 0, 1 },
    { 0, 40, 0, 0, 2 },
    { 0, -40, 0, 0, 3 },
    { 0, -64, 0, 0, 4 },
    { 0, -90, 0, 0, 5 },
};

const VsPointList gUnk_08131028 = { 6, gUnk_08130FE0, 60 };

const VsPoint gUnk_08131034[] = {
    { 0, 25, -25, 0, 0 },
    { 0, 40, 0, 0, 1 },
    { 0, 55, 25, 0, 2 },
    { 0, 65, -12, 0, 3 },
    { 0, 85, 12, 0, 4 },
};

const VsPointList gUnk_08131070 = { 5, gUnk_08131034, 60 };

const VsPoint gUnk_0813107C[] = {
    { 0, 25, -25, 0, 0 },
    { 0, 55, 25, 0, 1 },
    { 0, 90, 0, 0, 2 },
    { 0, -65, -12, 0, 3 },
    { 0, -85, 12, 0, 4 },
};

const VsPointList gUnk_081310B8 = { 5, gUnk_0813107C, 60 };

const VsPoint gUnk_081310C4[] = {
    { 0, 65, -12, 0, 0 },
    { 0, 85, 12, 0, 1 },
    { 0, -25, -25, 0, 2 },
    { 0, -40, 0, 0, 3 },
    { 0, -55, 25, 0, 4 },
};

const VsPointList gUnk_08131100 = { 5, gUnk_081310C4, 60 };

const VsPoint gUnk_0813110C[] = {
    { 0, 25, -25, 0, 0 },
    { 0, 65, -12, 0, 1 },
    { 0, 90, 0, 0, 2 },
    { 0, 85, 12, 0, 3 },
    { 0, 55, 25, 0, 4 },
};

const VsPointList gUnk_08131148 = { 5, gUnk_0813110C, 60 };

const VsPoint gUnk_08131154[] = {
    { 0, 25, -25, 0, 0 },
    { 0, 55, 25, 0, 1 },
    { 0, 65, -12, 0, 2 },
    { 0, 85, 12, 0, 3 },
};

const VsPointList gUnk_08131184 = { 4, gUnk_08131154, 60 };

const VsPoint gUnk_08131190[] = {
    { 0, 40, 0, 0, 0 },
    { 0, 65, -12, 0, 1 },
    { 0, 85, 12, 0, 2 },
    { 0, 90, 0, 0, 3 },
};

const VsPointList gUnk_081311C0 = { 4, gUnk_08131190, 60 };

const VsPoint gUnk_081311CC[] = {
    { 0, 65, -12, 0, 0 },
    { 0, 85, 12, 0, 1 },
    { 0, -65, -12, 0, 2 },
    { 0, -85, 12, 0, 3 },
};

const VsPointList gUnk_081311FC = { 4, gUnk_081311CC, 60 };

const VsPoint gUnk_08131208[] = {
    { 0, -55, 25, 0, 0 },
    { 0, -85, 12, 0, 1 },
    { 0, -65, -12, 0, 2 },
    { 0, -25, -25, 0, 3 },
};

const VsPointList gUnk_08131238 = { 4, gUnk_08131208, 60 };

const VsPoint gUnk_08131244[] = {
    { 0, 40, 0, 0, 0 },
    { 0, 65, -12, 0, 1 },
    { 0, 85, 12, 0, 2 },
};

const VsPointList gUnk_08131268 = { 3, gUnk_08131244, 60 };

const VsPoint gUnk_08131274[] = {
    { 0, 65, -12, 0, 0 },
    { 0, 85, 12, 0, 1 },
    { 0, 90, 0, 0, 2 },
};

const VsPointList gUnk_08131298 = { 3, gUnk_08131274, 60 };

const VsPoint gUnk_081312A4[] = {
    { 0, 65, -12, 0, 0 },
    { 0, 85, 12, 0, 1 },
    { 0, -40, 0, 0, 2 },
};

const VsPointList gUnk_081312C8 = { 3, gUnk_081312A4, 60 };

const VsPoint gUnk_081312D4[] = {
    { 0, 25, -25, 0, 0 },
    { 0, 64, 0, 0, 1 },
    { 0, 55, 25, 0, 2 },
};

const VsPointList gUnk_081312F8 = { 3, gUnk_081312D4, 60 };

const VsPoint gUnk_08131304[] = {
    { 0, -25, 25, 0, 0 },
    { 0, -64, 0, 0, 1 },
    { 0, -55, -25, 0, 2 },
};

const VsPointList gUnk_08131328 = { 3, gUnk_08131304, 60 };

const VsPoint gUnk_08131334[] = {
    { 0, -65, -12, 0, 0 },
    { 0, -85, 12, 0, 1 },
    { 0, 40, 0, 0, 2 },
};

const VsPointList gUnk_08131358 = { 3, gUnk_08131334, 60 };

const VsPoint gUnk_08131364[] = {
    { 0, 65, -12, 0, 0 },
    { 0, 85, 12, 0, 1 },
};

const VsPointList gUnk_0813137C = { 2, gUnk_08131364, 60 };

const VsPoint gUnk_08131388[] = {
    { 0, 25, -25, 0, 0 },
    { 0, 55, 25, 0, 1 },
};

const VsPointList gUnk_081313A0 = { 2, gUnk_08131388, 60 };

const VsPoint gUnk_081313AC[] = {
    { 0, 40, 0, 0, 0 },
    { 0, -40, 0, 0, 1 },
};

const VsPointList gUnk_081313C4 = { 2, gUnk_081313AC, 60 };

const VsPoint gUnk_081313D0[] = {
    { 0, 40, 0, 0, 0 },
    { 0, 90, 0, 0, 1 },
};

const VsPointList gUnk_081313E8 = { 2, gUnk_081313D0, 60 };

const VsPoint gUnk_081313F4[] = {
    { 0, -65, -12, 0, 0 },
    { 0, -85, 12, 0, 1 },
};

const VsPointList gUnk_0813140C = { 2, gUnk_081313F4, 60 };

const VsPoint gUnk_08131418[] = {
    { 0, -55, 25, 0, 0 },
    { 0, -25, -25, 0, 1 },
};

const VsPointList gUnk_08131430 = { 2, gUnk_08131418, 60 };

const VsPoint gUnk_0813143C[] = {
    { 0, 64, 0, 0, 0 },
};

const VsPointList gUnk_08131448 = { 1, gUnk_0813143C, 60 };

const VsPoint gUnk_08131454[] = {
    { 1, 25, -25, -30, 0 },
    { 1, 40, 0, -30, 1 },
    { 1, 55, 25, -30, 2 },
    { 1, 65, -12, -40, 3 },
    { 1, 85, 12, -40, 4 },
};

const VsPointList gUnk_08131490 = { 5, gUnk_08131454, 60 };

const VsPoint gUnk_0813149C[] = {
    { 1, 25, -25, -30, 0 },
    { 1, 55, 25, -30, 1 },
    { 1, 65, -12, -40, 2 },
    { 1, 85, 12, -40, 3 },
};

const VsPointList gUnk_081314CC = { 4, gUnk_0813149C, 60 };

const VsPoint gUnk_081314D8[] = {
    { 1, 40, 0, -30, 0 },
    { 1, 65, -12, -40, 1 },
    { 1, 85, 12, -40, 2 },
};

const VsPointList gUnk_081314FC = { 3, gUnk_081314D8, 60 };

const VsPoint gUnk_08131508[] = {
    { 1, 65, -12, -40, 0 },
    { 1, 85, 12, -40, 1 },
    { 1, -40, 0, -30, 2 },
};

const VsPointList gUnk_0813152C = { 3, gUnk_08131508, 60 };

const VsPoint gUnk_08131538[] = {
    { 1, 65, -12, -40, 0 },
    { 1, 85, 12, -40, 1 },
};

const VsPointList gUnk_08131550 = { 2, gUnk_08131538, 60 };

const VsPoint gUnk_0813155C[] = {
    { 1, -65, -12, -40, 0 },
    { 1, -85, 12, -40, 1 },
};

const VsPointList gUnk_08131574 = { 2, gUnk_0813155C, 60 };

const VsPoint gUnk_08131580[] = {
    { 1, 64, 0, -50, 0 },
};

const VsPointList gUnk_0813158C = { 1, gUnk_08131580, 60 };

const VsPoint gUnk_08131598[] = {
    { 1, 25, -25, -30, 0 },
};

const VsPointList gUnk_081315A4 = { 1, gUnk_08131598, 60 };

const VsPoint gUnk_081315B0[] = {
    { 1, -25, -25, -30, 0 },
};

const VsPointList gUnk_081315BC = { 1, gUnk_081315B0, 60 };

const VsPoint gUnk_081315C8[] = {
    { 1, 55, 25, -30, 0 },
};

const VsPointList gUnk_081315D4 = { 1, gUnk_081315C8, 60 };

const VsPoint gUnk_081315E0[] = {
    { 1, -55, 25, -30, 0 },
};

const VsPointList gUnk_081315EC = { 1, gUnk_081315E0, 60 };

const VsPoint gUnk_081315F8[] = {
    { 2, 25, -25, -30, 0 },
    { 2, 55, 25, -30, 1 },
    { 2, 90, 0, -50, 2 },
    { 2, -65, -12, -40, 3 },
    { 2, -85, 12, -40, 4 },
};

const VsPointList gUnk_08131634 = { 5, gUnk_081315F8, 60 };

const VsPoint gUnk_08131640[] = {
    { 2, 40, 0, -30, 0 },
    { 2, 65, -12, -40, 1 },
    { 2, 85, 12, -40, 2 },
    { 2, 90, 0, -50, 3 },
};

const VsPointList gUnk_08131670 = { 4, gUnk_08131640, 60 };

const VsPoint gUnk_0813167C[] = {
    { 2, 65, -12, -40, 0 },
    { 2, 85, 12, -40, 1 },
    { 2, 90, 0, -50, 2 },
};

const VsPointList gUnk_081316A0 = { 3, gUnk_0813167C, 60 };

const VsPoint gUnk_081316AC[] = {
    { 2, 25, -25, -30, 0 },
    { 2, 55, 25, -30, 1 },
};

const VsPointList gUnk_081316C4 = { 2, gUnk_081316AC, 60 };

const VsPoint gUnk_081316D0[] = {
    { 2, -65, -12, -40, 0 },
    { 2, -85, 12, -40, 1 },
};

const VsPointList gUnk_081316E8 = { 2, gUnk_081316D0, 60 };

const VsPoint gUnk_081316F4[] = {
    { 2, -55, 25, -30, 0 },
    { 2, -25, -25, -30, 1 },
};

const VsPointList gUnk_0813170C = { 2, gUnk_081316F4, 60 };

const VsPoint gUnk_08131718[] = {
    { 2, 64, 0, -50, 0 },
};

const VsPointList gUnk_08131724 = { 1, gUnk_08131718, 60 };

const VsPoint gUnk_08131730[] = {
    { 2, 40, 0, -30, 0 },
};

const VsPointList gUnk_0813173C = { 1, gUnk_08131730, 60 };

const VsPoint gUnk_08131748[] = {
    { 2, -64, 0, -50, 0 },
};

const VsPointList gUnk_08131754 = { 1, gUnk_08131748, 60 };

const VsPoint gUnk_08131760[] = {
    { 2, 25, -25, -30, 0 },
};

const VsPointList gUnk_0813176C = { 1, gUnk_08131760, 60 };

const VsPoint gUnk_08131778[] = {
    { 2, -25, -25, -30, 0 },
};

const VsPointList gUnk_08131784 = { 1, gUnk_08131778, 60 };

const VsPoint gUnk_08131790[] = {
    { 2, 55, 25, -30, 0 },
};

const VsPointList gUnk_0813179C = { 1, gUnk_08131790, 60 };

const VsPoint gUnk_081317A8[] = {
    { 2, -55, 25, -30, 0 },
};

const VsPointList gUnk_081317B4 = { 1, gUnk_081317A8, 60 };

const VsPoint gUnk_081317C0[] = {
    { 3, 65, -12, -40, 0 },
    { 3, 85, 12, -40, 1 },
    { 3, -25, -25, -30, 2 },
    { 3, -40, 0, -30, 3 },
    { 3, -55, 25, -30, 4 },
};

const VsPointList gUnk_081317FC = { 5, gUnk_081317C0, 60 };

const VsPoint gUnk_08131808[] = {
    { 3, 65, -12, -40, 0 },
    { 3, 85, 12, -40, 1 },
    { 3, -65, -12, -40, 2 },
    { 3, -85, 12, -40, 3 },
};

const VsPointList gUnk_08131838 = { 4, gUnk_08131808, 60 };

const VsPoint gUnk_08131844[] = {
    { 3, 65, -12, -40, 0 },
    { 3, 85, 12, -40, 1 },
    { 3, -40, 0, -30, 2 },
};

const VsPointList gUnk_08131868 = { 3, gUnk_08131844, 60 };

const VsPoint gUnk_08131874[] = {
    { 3, -25, 25, -30, 0 },
    { 3, -64, 0, -50, 1 },
    { 3, -55, -25, -30, 2 },
};

const VsPointList gUnk_08131898 = { 3, gUnk_08131874, 60 };

const VsPoint gUnk_081318A4[] = {
    { 3, 65, -12, -40, 0 },
    { 3, 85, 12, -40, 1 },
};

const VsPointList gUnk_081318BC = { 2, gUnk_081318A4, 60 };

const VsPoint gUnk_081318C8[] = {
    { 3, 25, -25, -30, 0 },
    { 3, 55, 25, -30, 1 },
};

const VsPointList gUnk_081318E0 = { 2, gUnk_081318C8, 60 };

const VsPoint gUnk_081318EC[] = {
    { 3, 40, 0, -30, 0 },
    { 3, -40, 0, -30, 1 },
};

const VsPointList gUnk_08131904 = { 2, gUnk_081318EC, 60 };

const VsPoint gUnk_08131910[] = {
    { 3, 40, 0, -30, 0 },
    { 3, 90, 0, -50, 1 },
};

const VsPointList gUnk_08131928 = { 2, gUnk_08131910, 60 };

const VsPoint gUnk_08131934[] = {
    { 3, -65, -12, -40, 0 },
    { 3, -85, 12, -40, 1 },
};

const VsPointList gUnk_0813194C = { 2, gUnk_08131934, 60 };

const VsPoint gUnk_08131958[] = {
    { 3, -55, 25, -30, 0 },
    { 3, -25, -25, -30, 1 },
};

const VsPointList gUnk_08131970 = { 2, gUnk_08131958, 60 };

const VsPoint gUnk_0813197C[] = {
    { 3, 64, 0, -50, 0 },
};

const VsPointList gUnk_08131988 = { 1, gUnk_0813197C, 60 };

const VsPoint gUnk_08131994[] = {
    { 3, 25, -25, -30, 0 },
};

const VsPointList gUnk_081319A0 = { 1, gUnk_08131994, 60 };

const VsPoint gUnk_081319AC[] = {
    { 3, -25, -25, -30, 0 },
};

const VsPointList gUnk_081319B8 = { 1, gUnk_081319AC, 60 };

const VsPoint gUnk_081319C4[] = {
    { 3, 55, 25, -30, 0 },
};

const VsPointList gUnk_081319D0 = { 1, gUnk_081319C4, 60 };

const VsPoint gUnk_081319DC[] = {
    { 3, -55, 25, -30, 0 },
};

const VsPointList gUnk_081319E8 = { 1, gUnk_081319DC, 60 };

const VsPoint gUnk_081319F4[] = {
    { 4, 65, -12, -40, 0 },
    { 4, 85, 12, -40, 1 },
    { 4, -25, -25, -30, 2 },
    { 4, -40, 0, -30, 3 },
    { 4, -55, 25, -30, 4 },
};

const VsPointList gUnk_08131A30 = { 5, gUnk_081319F4, 60 };

const VsPoint gUnk_08131A3C[] = {
    { 4, 65, -12, -40, 0 },
    { 4, 85, 12, -40, 1 },
    { 4, -65, -12, -40, 2 },
    { 4, -85, 12, -40, 3 },
};

const VsPointList gUnk_08131A6C = { 4, gUnk_08131A3C, 60 };

const VsPoint gUnk_08131A78[] = {
    { 4, 65, -12, -40, 0 },
    { 4, 85, 12, -40, 1 },
    { 4, -40, 0, -30, 2 },
};

const VsPointList gUnk_08131A9C = { 3, gUnk_08131A78, 60 };

const VsPoint gUnk_08131AA8[] = {
    { 4, -65, -12, -40, 0 },
    { 4, -85, 12, -40, 1 },
    { 4, 40, 0, -30, 2 },
};

const VsPointList gUnk_08131ACC = { 3, gUnk_08131AA8, 60 };

const VsPoint gUnk_08131AD8[] = {
    { 4, 65, -12, -40, 0 },
    { 4, 85, 12, -40, 1 },
};

const VsPointList gUnk_08131AF0 = { 2, gUnk_08131AD8, 60 };

const VsPoint gUnk_08131AFC[] = {
    { 4, 25, -25, -30, 0 },
    { 4, 55, 25, -30, 1 },
};

const VsPointList gUnk_08131B14 = { 2, gUnk_08131AFC, 60 };

const VsPoint gUnk_08131B20[] = {
    { 4, 40, 0, -30, 0 },
    { 4, -40, 0, -30, 1 },
};

const VsPointList gUnk_08131B38 = { 2, gUnk_08131B20, 60 };

const VsPoint gUnk_08131B44[] = {
    { 4, -65, -12, -40, 0 },
    { 4, -85, 12, -40, 1 },
};

const VsPointList gUnk_08131B5C = { 2, gUnk_08131B44, 60 };

const VsPoint gUnk_08131B68[] = {
    { 4, -55, 25, -30, 0 },
    { 4, -25, -25, -30, 1 },
};

const VsPointList gUnk_08131B80 = { 2, gUnk_08131B68, 60 };

const VsPoint gUnk_08131B8C[] = {
    { 4, 64, 0, -50, 0 },
};

const VsPointList gUnk_08131B98 = { 1, gUnk_08131B8C, 60 };

const VsPoint gUnk_08131BA4[] = {
    { 4, 25, -25, -30, 0 },
};

const VsPointList gUnk_08131BB0 = { 1, gUnk_08131BA4, 60 };

const VsPoint gUnk_08131BBC[] = {
    { 4, -25, -25, -30, 0 },
};

const VsPointList gUnk_08131BC8 = { 1, gUnk_08131BBC, 60 };

const VsPoint gUnk_08131BD4[] = {
    { 4, 55, 25, -30, 0 },
};

const VsPointList gUnk_08131BE0 = { 1, gUnk_08131BD4, 60 };

const VsPoint gUnk_08131BEC[] = {
    { 4, -55, 25, -30, 0 },
};

const VsPointList gUnk_08131BF8 = { 1, gUnk_08131BEC, 60 };

const VsPoint gUnk_08131C04[] = {
    { 5, 25, -25, -30, 0 },
    { 5, 40, 0, -30, 1 },
    { 5, 25, 25, -30, 2 },
    { 5, -25, 25, -30, 3 },
    { 5, -40, 0, -30, 4 },
    { 5, -25, -25, -30, 5 },
};

const VsPointList gUnk_08131C4C = { 6, gUnk_08131C04, 60 };

const VsPoint gUnk_08131C58[] = {
    { 5, 25, -25, -30, 0 },
    { 5, 40, 0, -30, 1 },
    { 5, 55, 25, -30, 2 },
    { 5, 65, -12, -40, 3 },
    { 5, 85, 12, -40, 4 },
};

const VsPointList gUnk_08131C94 = { 5, gUnk_08131C58, 60 };

const VsPoint gUnk_08131CA0[] = {
    { 5, 25, -25, -30, 0 },
    { 5, 55, 25, -30, 1 },
    { 5, 65, -12, -40, 2 },
    { 5, 85, 12, -40, 3 },
};

const VsPointList gUnk_08131CD0 = { 4, gUnk_08131CA0, 60 };

const VsPoint gUnk_08131CDC[] = {
    { 5, 65, -12, -40, 0 },
    { 5, 85, 12, -40, 1 },
    { 5, -65, -12, -40, 2 },
    { 5, -85, 12, -40, 3 },
};

const VsPointList gUnk_08131D0C = { 4, gUnk_08131CDC, 60 };

const VsPoint gUnk_08131D18[] = {
    { 5, 40, 0, -30, 0 },
    { 5, 65, -12, -40, 1 },
    { 5, 85, 12, -40, 2 },
};

const VsPointList gUnk_08131D3C = { 3, gUnk_08131D18, 60 };

const VsPoint gUnk_08131D48[] = {
    { 5, -25, 25, -30, 0 },
    { 5, -64, 0, -50, 1 },
    { 5, -55, -25, -30, 2 },
};

const VsPointList gUnk_08131D6C = { 3, gUnk_08131D48, 60 };

const VsPoint gUnk_08131D78[] = {
    { 5, 65, -12, -40, 0 },
    { 5, 85, 12, -40, 1 },
};

const VsPointList gUnk_08131D90 = { 2, gUnk_08131D78, 60 };

const VsPoint gUnk_08131D9C[] = {
    { 5, 64, 0, -50, 0 },
};

const VsPointList gUnk_08131DA8 = { 1, gUnk_08131D9C, 60 };

const VsPoint gUnk_08131DB4[] = {
    { 6, 65, -12, 0, 0 },
    { 6, 85, 12, 0, 1 },
    { 6, -65, -12, 0, 2 },
    { 6, -85, 12, 0, 3 },
};

const VsPointList gUnk_08131DE4 = { 4, gUnk_08131DB4, 60 };

const VsPoint gUnk_08131DF0[] = {
    { 6, 40, 0, 0, 0 },
    { 6, 65, -12, 0, 1 },
    { 6, 85, 12, 0, 2 },
};

const VsPointList gUnk_08131E14 = { 3, gUnk_08131DF0, 60 };

const VsPoint gUnk_08131E20[] = {
    { 6, 25, -25, 0, 0 },
    { 6, 55, 25, 0, 1 },
};

const VsPointList gUnk_08131E38 = { 2, gUnk_08131E20, 60 };

const VsPoint gUnk_08131E44[] = {
    { 6, 40, 0, 0, 0 },
    { 6, -40, 0, 0, 1 },
};

const VsPointList gUnk_08131E5C = { 2, gUnk_08131E44, 60 };

const VsPoint gUnk_08131E68[] = {
    { 6, 64, 0, 0, 0 },
};

const VsPointList gUnk_08131E74 = { 1, gUnk_08131E68, 60 };

const VsPoint gUnk_08131E80[] = {
    { 7, 65, -12, 0, 0 },
    { 7, 85, 12, 0, 1 },
    { 7, -65, -12, 0, 2 },
    { 7, -85, 12, 0, 3 },
};

const VsPointList gUnk_08131EB0 = { 4, gUnk_08131E80, 60 };

const VsPoint gUnk_08131EBC[] = {
    { 7, 65, -12, 0, 0 },
    { 7, 85, 12, 0, 1 },
    { 7, -40, 0, 0, 2 },
};

const VsPointList gUnk_08131EE0 = { 3, gUnk_08131EBC, 60 };

const VsPoint gUnk_08131EEC[] = {
    { 7, 65, -12, 0, 0 },
    { 7, 85, 12, 0, 1 },
};

const VsPointList gUnk_08131F04 = { 2, gUnk_08131EEC, 60 };

const VsPoint gUnk_08131F10[] = {
    { 7, 40, 0, 0, 0 },
    { 7, -40, 0, 0, 1 },
};

const VsPointList gUnk_08131F28 = { 2, gUnk_08131F10, 60 };

const VsPoint gUnk_08131F34[] = {
    { 7, 64, 0, 0, 0 },
};

const VsPointList gUnk_08131F40 = { 1, gUnk_08131F34, 60 };

const VsPoint gUnk_08131F4C[] = {
    { 9, 25, -25, 0, 0 },
    { 9, 40, 0, 0, 1 },
    { 9, 55, 25, 0, 2 },
    { 9, -55, -25, 0, 3 },
    { 9, -40, 0, 0, 4 },
    { 9, -25, 25, 0, 5 },
};

const VsPointList gUnk_08131F94 = { 6, gUnk_08131F4C, 60 };

const VsPoint gUnk_08131FA0[] = {
    { 9, 25, -25, 0, 0 },
    { 9, 55, 25, 0, 1 },
    { 9, 90, 0, 0, 2 },
    { 9, -65, -12, 0, 3 },
    { 9, -85, 12, 0, 4 },
};

const VsPointList gUnk_08131FDC = { 5, gUnk_08131FA0, 60 };

const VsPoint gUnk_08131FE8[] = {
    { 9, 65, -12, -40, 0 },
    { 9, 85, 12, -40, 1 },
    { 9, -25, -25, -30, 2 },
    { 9, -40, 0, -30, 3 },
    { 9, -55, 25, -30, 4 },
};

const VsPointList gUnk_08132024 = { 5, gUnk_08131FE8, 60 };

const VsPoint gUnk_08132030[] = {
    { 9, 25, -25, 0, 0 },
    { 9, 55, 25, 0, 1 },
    { 9, 65, -12, 0, 2 },
    { 9, 85, 12, 0, 3 },
};

const VsPointList gUnk_08132060 = { 4, gUnk_08132030, 60 };

const VsPoint gUnk_0813206C[] = {
    { 9, 40, 0, -30, 0 },
    { 9, 65, -12, -40, 1 },
    { 9, 85, 12, -40, 2 },
    { 9, 90, 0, -50, 3 },
};

const VsPointList gUnk_0813209C = { 4, gUnk_0813206C, 60 };

const VsPoint gUnk_081320A8[] = {
    { 9, 65, -12, 0, 0 },
    { 9, 85, 12, 0, 1 },
    { 9, -65, -12, 0, 2 },
    { 9, -85, 12, 0, 3 },
};

const VsPointList gUnk_081320D8 = { 4, gUnk_081320A8, 60 };

const VsPoint gUnk_081320E4[] = {
    { 9, 40, 0, -30, 0 },
    { 9, 65, -12, -40, 1 },
    { 9, 85, 12, -40, 2 },
};

const VsPointList gUnk_08132108 = { 3, gUnk_081320E4, 60 };

const VsPoint gUnk_08132114[] = {
    { 9, 65, -12, 0, 0 },
    { 9, 85, 12, 0, 1 },
    { 9, 90, 0, 0, 2 },
};

const VsPointList gUnk_08132138 = { 3, gUnk_08132114, 60 };

const VsPoint gUnk_08132144[] = {
    { 9, 65, -12, -40, 0 },
    { 9, 85, 12, -40, 1 },
    { 9, -40, 0, -30, 2 },
};

const VsPointList gUnk_08132168 = { 3, gUnk_08132144, 60 };

const VsPoint gUnk_08132174[] = {
    { 9, 25, -25, 0, 0 },
    { 9, 64, 0, 0, 1 },
    { 9, 55, 25, 0, 2 },
};

const VsPointList gUnk_08132198 = { 3, gUnk_08132174, 60 };

const VsPoint gUnk_081321A4[] = {
    { 9, -25, 25, 0, 0 },
    { 9, -64, 0, 0, 1 },
    { 9, -55, -25, 0, 2 },
};

const VsPointList gUnk_081321C8 = { 3, gUnk_081321A4, 60 };

const VsPoint gUnk_081321D4[] = {
    { 9, 65, -12, 0, 0 },
    { 9, 85, 12, 0, 1 },
};

const VsPointList gUnk_081321EC = { 2, gUnk_081321D4, 60 };

const VsPoint gUnk_081321F8[] = {
    { 9, 25, -25, -30, 0 },
    { 9, 55, 25, -30, 1 },
};

const VsPointList gUnk_08132210 = { 2, gUnk_081321F8, 60 };

const VsPoint gUnk_0813221C[] = {
    { 9, 40, 0, 0, 0 },
    { 9, -40, 0, 0, 1 },
};

const VsPointList gUnk_08132234 = { 2, gUnk_0813221C, 60 };

const VsPoint gUnk_08132240[] = {
    { 9, -65, -12, 0, 0 },
    { 9, -85, 12, 0, 1 },
};

const VsPointList gUnk_08132258 = { 2, gUnk_08132240, 60 };

const VsPoint gUnk_08132264[] = {
    { 9, 64, 0, -50, 0 },
};

const VsPointList gUnk_08132270 = { 1, gUnk_08132264, 60 };

const VsPoint gUnk_0813227C[] = {
    { 9, 40, 0, 0, 0 },
};

const VsPointList gUnk_08132288 = { 1, gUnk_0813227C, 60 };

const VsPoint gUnk_08132294[] = {
    { 9, -64, 0, 0, 0 },
};

const VsPointList gUnk_081322A0 = { 1, gUnk_08132294, 60 };

const VsPoint gUnk_081322AC[] = {
    { 9, -40, 0, 0, 0 },
};

const VsPointList gUnk_081322B8 = { 1, gUnk_081322AC, 60 };

const VsPoint gUnk_081322C4[] = {
    { 10, 40, 0, 0, 0 },
    { 10, 65, -12, 0, 1 },
    { 10, 85, 12, 0, 2 },
};

const VsPointList gUnk_081322E8 = { 3, gUnk_081322C4, 60 };

const VsPoint gUnk_081322F4[] = {
    { 10, 25, -25, 0, 0 },
    { 10, 55, 25, 0, 1 },
};

const VsPointList gUnk_0813230C = { 2, gUnk_081322F4, 60 };

const VsPoint gUnk_08132318[] = {
    { 10, -65, -12, 0, 0 },
    { 10, -85, 12, 0, 1 },
};

const VsPointList gUnk_08132330 = { 2, gUnk_08132318, 60 };

const VsPoint gUnk_0813233C[] = {
    { 10, 64, 0, 0, 0 },
};

const VsPointList gUnk_08132348 = { 1, gUnk_0813233C, 60 };

const VsPoint gUnk_08132354[] = {
    { 11, 65, -12, 0, 0 },
    { 11, 85, 12, 0, 1 },
    { 11, 90, 0, 0, 2 },
};

const VsPointList gUnk_08132378 = { 3, gUnk_08132354, 60 };

const VsPoint gUnk_08132384[] = {
    { 11, 40, 0, 0, 0 },
    { 11, -40, 0, 0, 1 },
};

const VsPointList gUnk_0813239C = { 2, gUnk_08132384, 60 };

const VsPoint gUnk_081323A8[] = {
    { 11, -55, 25, 0, 0 },
    { 11, -25, -25, 0, 1 },
};

const VsPointList gUnk_081323C0 = { 2, gUnk_081323A8, 60 };

const VsPoint gUnk_081323CC[] = {
    { 11, 64, 0, 0, 0 },
};

const VsPointList gUnk_081323D8 = { 1, gUnk_081323CC, 60 };

const VsPoint gUnk_081323E4[] = {
    { 12, 25, -25, -30, 0 },
    { 12, 55, 25, -30, 1 },
    { 12, 65, -12, -40, 2 },
    { 12, 85, 12, -40, 3 },
};

const VsPointList gUnk_08132414 = { 4, gUnk_081323E4, 60 };

const VsPoint gUnk_08132420[] = {
    { 12, 65, -12, -40, 0 },
    { 12, 85, 12, -40, 1 },
    { 12, -65, -12, -40, 2 },
    { 12, -85, 12, -40, 3 },
};

const VsPointList gUnk_08132450 = { 4, gUnk_08132420, 60 };

const VsPoint gUnk_0813245C[] = {
    { 12, 65, -12, -40, 0 },
    { 12, 85, 12, -40, 1 },
    { 12, 90, 0, -50, 2 },
};

const VsPointList gUnk_08132480 = { 3, gUnk_0813245C, 60 };

const VsPoint gUnk_0813248C[] = {
    { 12, 65, -12, -40, 0 },
    { 12, 85, 12, -40, 1 },
    { 12, -40, 0, -30, 2 },
};

const VsPointList gUnk_081324B0 = { 3, gUnk_0813248C, 60 };

const VsPoint gUnk_081324BC[] = {
    { 12, 40, 0, -30, 0 },
    { 12, -40, 0, -30, 1 },
};

const VsPointList gUnk_081324D4 = { 2, gUnk_081324BC, 60 };

const VsPoint gUnk_081324E0[] = {
    { 12, -55, 25, -30, 0 },
    { 12, -25, -25, -30, 1 },
};

const VsPointList gUnk_081324F8 = { 2, gUnk_081324E0, 60 };

const VsPoint gUnk_08132504[] = {
    { 12, 64, 0, -50, 0 },
};

const VsPointList gUnk_08132510 = { 1, gUnk_08132504, 60 };

const VsPoint gUnk_0813251C[] = {
    { 13, 25, -25, 0, 0 },
    { 13, 55, 25, 0, 1 },
    { 13, 90, 0, 0, 2 },
    { 13, -65, -12, 0, 3 },
    { 13, -85, 12, 0, 4 },
};

const VsPointList gUnk_08132558 = { 5, gUnk_0813251C, 60 };

const VsPoint gUnk_08132564[] = {
    { 13, 25, -25, 0, 0 },
    { 13, 55, 25, 0, 1 },
    { 13, 65, -12, 0, 2 },
    { 13, 85, 12, 0, 3 },
};

const VsPointList gUnk_08132594 = { 4, gUnk_08132564, 60 };

const VsPoint gUnk_081325A0[] = {
    { 13, 65, -12, 0, 0 },
    { 13, 85, 12, 0, 1 },
    { 13, -65, -12, 0, 2 },
    { 13, -85, 12, 0, 3 },
};

const VsPointList gUnk_081325D0 = { 4, gUnk_081325A0, 60 };

const VsPoint gUnk_081325DC[] = {
    { 13, 65, -12, 0, 0 },
    { 13, 85, 12, 0, 1 },
    { 13, -40, 0, 0, 2 },
};

const VsPointList gUnk_08132600 = { 3, gUnk_081325DC, 60 };

const VsPoint gUnk_0813260C[] = {
    { 13, 25, -25, 0, 0 },
    { 13, 55, 25, 0, 1 },
};

const VsPointList gUnk_08132624 = { 2, gUnk_0813260C, 60 };

const VsPoint gUnk_08132630[] = {
    { 13, -55, 25, 0, 0 },
    { 13, -25, -25, 0, 1 },
};

const VsPointList gUnk_08132648 = { 2, gUnk_08132630, 60 };

const VsPoint gUnk_08132654[] = {
    { 13, 64, 0, 0, 0 },
};

const VsPointList gUnk_08132660 = { 1, gUnk_08132654, 60 };

const VsPoint gUnk_0813266C[] = {
    { 13, 40, 0, 0, 0 },
};

const VsPointList gUnk_08132678 = { 1, gUnk_0813266C, 60 };

const VsPoint gUnk_08132684[] = {
    { 14, 40, 0, 0, 0 },
    { 14, 65, -12, 0, 1 },
    { 14, 85, 12, 0, 2 },
};

const VsPointList gUnk_081326A8 = { 3, gUnk_08132684, 60 };

const VsPoint gUnk_081326B4[] = {
    { 14, 65, -12, 0, 0 },
    { 14, 85, 12, 0, 1 },
};

const VsPointList gUnk_081326CC = { 2, gUnk_081326B4, 60 };

const VsPoint gUnk_081326D8[] = {
    { 14, 40, 0, 0, 0 },
    { 14, -40, 0, 0, 1 },
};

const VsPointList gUnk_081326F0 = { 2, gUnk_081326D8, 60 };

const VsPoint gUnk_081326FC[] = {
    { 14, -65, -12, 0, 0 },
    { 14, -85, 12, 0, 1 },
};

const VsPointList gUnk_08132714 = { 2, gUnk_081326FC, 60 };

const VsPoint gUnk_08132720[] = {
    { 14, 64, 0, 0, 0 },
};

const VsPointList gUnk_0813272C = { 1, gUnk_08132720, 60 };

const VsPoint gUnk_08132738[] = {
    { 14, -64, 0, 0, 0 },
};

const VsPointList gUnk_08132744 = { 1, gUnk_08132738, 60 };

const VsPoint gUnk_08132750[] = {
    { 15, 65, -12, -40, 0 },
    { 15, 85, 12, -40, 1 },
    { 15, 90, 0, -50, 2 },
};

const VsPointList gUnk_08132774 = { 3, gUnk_08132750, 60 };

const VsPoint gUnk_08132780[] = {
    { 15, 25, -25, -30, 0 },
    { 15, 55, 25, -30, 1 },
};

const VsPointList gUnk_08132798 = { 2, gUnk_08132780, 60 };

const VsPoint gUnk_081327A4[] = {
    { 15, 40, 0, -30, 0 },
    { 15, -40, 0, -30, 1 },
};

const VsPointList gUnk_081327BC = { 2, gUnk_081327A4, 60 };

const VsPoint gUnk_081327C8[] = {
    { 15, -65, -12, -40, 0 },
    { 15, -85, 12, -40, 1 },
};

const VsPointList gUnk_081327E0 = { 2, gUnk_081327C8, 60 };

const VsPoint gUnk_081327EC[] = {
    { 15, 64, 0, -50, 0 },
};

const VsPointList gUnk_081327F8 = { 1, gUnk_081327EC, 60 };

const VsPoint gUnk_08132804[] = {
    { 15, -64, 0, -50, 0 },
};

const VsPointList gUnk_08132810 = { 1, gUnk_08132804, 60 };

const VsPoint gUnk_0813281C[] = {
    { 16, 65, -12, -40, 0 },
    { 16, 85, 12, -40, 1 },
};

const VsPointList gUnk_08132834 = { 2, gUnk_0813281C, 60 };

const VsPoint gUnk_08132840[] = {
    { 16, -55, 25, -30, 0 },
    { 16, -25, -25, -30, 1 },
};

const VsPointList gUnk_08132858 = { 2, gUnk_08132840, 60 };

const VsPoint gUnk_08132864[] = {
    { 16, 64, 0, -50, 0 },
};

const VsPointList gUnk_08132870 = { 1, gUnk_08132864, 60 };

const VsPoint gUnk_0813287C[] = {
    { 16, -64, 0, -50, 0 },
};

const VsPointList gUnk_08132888 = { 1, gUnk_0813287C, 60 };

const VsPoint gUnk_08132894[] = {
    { 16, 25, -25, -30, 0 },
};

const VsPointList gUnk_081328A0 = { 1, gUnk_08132894, 60 };

const VsPoint gUnk_081328AC[] = {
    { 16, -25, -25, -30, 0 },
};

const VsPointList gUnk_081328B8 = { 1, gUnk_081328AC, 60 };

const VsPoint gUnk_081328C4[] = {
    { 16, 55, 25, -30, 0 },
};

const VsPointList gUnk_081328D0 = { 1, gUnk_081328C4, 60 };

const VsPoint gUnk_081328DC[] = {
    { 16, -55, 25, -30, 0 },
};

const VsPointList gUnk_081328E8 = { 1, gUnk_081328DC, 60 };

const VsPoint gUnk_081328F4[] = {
    { 17, 65, -12, 0, 0 },
    { 17, 85, 12, 0, 1 },
    { 17, -40, 0, 0, 2 },
};

const VsPointList gUnk_08132918 = { 3, gUnk_081328F4, 60 };

const VsPoint gUnk_08132924[] = {
    { 17, 25, -25, 0, 0 },
    { 17, 55, 25, 0, 1 },
};

const VsPointList gUnk_0813293C = { 2, gUnk_08132924, 60 };

const VsPoint gUnk_08132948[] = {
    { 17, 40, 0, 0, 0 },
    { 17, -40, 0, 0, 1 },
};

const VsPointList gUnk_08132960 = { 2, gUnk_08132948, 60 };

const VsPoint gUnk_0813296C[] = {
    { 17, 65, -12, 0, 0 },
    { 17, 85, 12, 0, 1 },
};

const VsPointList gUnk_08132984 = { 2, gUnk_0813296C, 60 };

const VsPoint gUnk_08132990[] = {
    { 17, -55, 25, 0, 0 },
    { 17, -25, -25, 0, 1 },
};

const VsPointList gUnk_081329A8 = { 2, gUnk_08132990, 60 };

const VsPoint gUnk_081329B4[] = {
    { 17, 64, 0, 0, 0 },
};

const VsPointList gUnk_081329C0 = { 1, gUnk_081329B4, 60 };

const VsPoint gUnk_081329CC[] = {
    { 17, -64, 0, 0, 0 },
};

const VsPointList gUnk_081329D8 = { 1, gUnk_081329CC, 60 };

const VsPoint gUnk_081329E4[] = {
    { 18, 40, 0, -30, 0 },
    { 18, 65, -12, -40, 1 },
    { 18, 85, 12, -40, 2 },
};

const VsPointList gUnk_08132A08 = { 3, gUnk_081329E4, 60 };

const VsPoint gUnk_08132A14[] = {
    { 18, 25, -25, -30, 0 },
    { 18, 55, 25, -30, 1 },
};

const VsPointList gUnk_08132A2C = { 2, gUnk_08132A14, 60 };

const VsPoint gUnk_08132A38[] = {
    { 18, -55, 25, -30, 0 },
    { 18, -25, -25, -30, 1 },
};

const VsPointList gUnk_08132A50 = { 2, gUnk_08132A38, 60 };

const VsPoint gUnk_08132A5C[] = {
    { 18, 64, 0, -50, 0 },
};

const VsPointList gUnk_08132A68 = { 1, gUnk_08132A5C, 60 };

const VsPoint gUnk_08132A74[] = {
    { 18, -64, 0, -50, 0 },
};

const VsPointList gUnk_08132A80 = { 1, gUnk_08132A74, 60 };

const VsPoint gUnk_08132A8C[] = {
    { 19, 25, -25, 0, 0 },
    { 19, 40, 0, 0, 1 },
    { 19, 55, 25, 0, 2 },
    { 19, 65, -12, 0, 3 },
    { 19, 85, 12, 0, 4 },
};

const VsPointList gUnk_08132AC8 = { 5, gUnk_08132A8C, 60 };

const VsPoint gUnk_08132AD4[] = {
    { 19, 65, -12, 0, 0 },
    { 19, 85, 12, 0, 1 },
    { 19, -65, -12, 0, 2 },
    { 19, -85, 12, 0, 3 },
};

const VsPointList gUnk_08132B04 = { 4, gUnk_08132AD4, 60 };

const VsPoint gUnk_08132B10[] = {
    { 19, 65, -12, 0, 0 },
    { 19, 85, 12, 0, 1 },
    { 19, 90, 0, 0, 2 },
};

const VsPointList gUnk_08132B34 = { 3, gUnk_08132B10, 60 };

const VsPoint gUnk_08132B40[] = {
    { 19, -65, -12, 0, 0 },
    { 19, -85, 12, 0, 1 },
    { 19, 40, 0, 0, 2 },
};

const VsPointList gUnk_08132B64 = { 3, gUnk_08132B40, 60 };

const VsPoint gUnk_08132B70[] = {
    { 19, 65, -12, 0, 0 },
    { 19, 85, 12, 0, 1 },
};

const VsPointList gUnk_08132B88 = { 2, gUnk_08132B70, 60 };

const VsPoint gUnk_08132B94[] = {
    { 19, -65, -12, 0, 0 },
    { 19, -85, 12, 0, 1 },
};

const VsPointList gUnk_08132BAC = { 2, gUnk_08132B94, 60 };

const VsPoint gUnk_08132BB8[] = {
    { 19, 40, 0, 0, 0 },
    { 19, -40, 0, 0, 1 },
};

const VsPointList gUnk_08132BD0 = { 2, gUnk_08132BB8, 60 };

const VsPoint gUnk_08132BDC[] = {
    { 19, 64, 0, 0, 0 },
};

const VsPointList gUnk_08132BE8 = { 1, gUnk_08132BDC, 60 };

const VsPoint gUnk_08132BF4[] = {
    { 20, 25, -25, -30, 0 },
    { 20, 55, 25, -30, 1 },
};

const VsPointList gUnk_08132C0C = { 2, gUnk_08132BF4, 60 };

const VsPoint gUnk_08132C18[] = {
    { 20, 40, 0, -30, 0 },
    { 20, -40, 0, -30, 1 },
};

const VsPointList gUnk_08132C30 = { 2, gUnk_08132C18, 60 };

const VsPoint gUnk_08132C3C[] = {
    { 20, -55, 25, -30, 0 },
    { 20, -25, -25, -30, 1 },
};

const VsPointList gUnk_08132C54 = { 2, gUnk_08132C3C, 60 };

const VsPoint gUnk_08132C60[] = {
    { 20, 64, 0, -50, 0 },
};

const VsPointList gUnk_08132C6C = { 1, gUnk_08132C60, 60 };

const VsPoint gUnk_08132C78[] = {
    { 20, -64, 0, -50, 0 },
};

const VsPointList gUnk_08132C84 = { 1, gUnk_08132C78, 60 };

const VsPoint gUnk_08132C90[] = {
    { 20, 25, -25, -30, 0 },
};

const VsPointList gUnk_08132C9C = { 1, gUnk_08132C90, 60 };

const VsPoint gUnk_08132CA8[] = {
    { 21, 65, -12, -40, 0 },
    { 21, 85, 12, -40, 1 },
};

const VsPointList gUnk_08132CC0 = { 2, gUnk_08132CA8, 60 };

const VsPoint gUnk_08132CCC[] = {
    { 21, 25, -25, -30, 0 },
    { 21, 55, 25, -30, 1 },
};

const VsPointList gUnk_08132CE4 = { 2, gUnk_08132CCC, 60 };

const VsPoint gUnk_08132CF0[] = {
    { 21, 40, 0, -30, 0 },
    { 21, -40, 0, -30, 1 },
};

const VsPointList gUnk_08132D08 = { 2, gUnk_08132CF0, 60 };

const VsPoint gUnk_08132D14[] = {
    { 21, 40, 0, -30, 0 },
    { 21, 90, 0, -50, 1 },
};

const VsPointList gUnk_08132D2C = { 2, gUnk_08132D14, 60 };

const VsPoint gUnk_08132D38[] = {
    { 21, -65, -12, -40, 0 },
    { 21, -85, 12, -40, 1 },
};

const VsPointList gUnk_08132D50 = { 2, gUnk_08132D38, 60 };

const VsPoint gUnk_08132D5C[] = {
    { 21, -55, 25, -30, 0 },
    { 21, -25, -25, -30, 1 },
};

const VsPointList gUnk_08132D74 = { 2, gUnk_08132D5C, 60 };

const VsPoint gUnk_08132D80[] = {
    { 21, 64, 0, -50, 0 },
};

const VsPointList gUnk_08132D8C = { 1, gUnk_08132D80, 60 };

const VsPoint gUnk_08132D98[] = {
    { 21, -64, 0, -50, 0 },
};

const VsPointList gUnk_08132DA4 = { 1, gUnk_08132D98, 60 };

const VsPoint gUnk_08132DB0[] = {
    { 21, 25, -25, -30, 0 },
};

const VsPointList gUnk_08132DBC = { 1, gUnk_08132DB0, 60 };

const VsPoint gUnk_08132DC8[] = {
    { 21, -25, -25, -30, 0 },
};

const VsPointList gUnk_08132DD4 = { 1, gUnk_08132DC8, 60 };

const VsPoint gUnk_08132DE0[] = {
    { 21, 55, 25, -30, 0 },
};

const VsPointList gUnk_08132DEC = { 1, gUnk_08132DE0, 60 };

const VsPoint gUnk_08132DF8[] = {
    { 21, -55, 25, -30, 0 },
};

const VsPointList gUnk_08132E04 = { 1, gUnk_08132DF8, 60 };

const VsPoint gUnk_08132E10[] = {
    { 22, 65, -12, -40, 0 },
    { 22, 85, 12, -40, 1 },
};

const VsPointList gUnk_08132E28 = { 2, gUnk_08132E10, 60 };

const VsPoint gUnk_08132E34[] = {
    { 22, 64, 0, -50, 0 },
};

const VsPointList gUnk_08132E40 = { 1, gUnk_08132E34, 60 };

const VsPoint gUnk_08132E4C[] = {
    { 22, -64, 0, -50, 0 },
};

const VsPointList gUnk_08132E58 = { 1, gUnk_08132E4C, 60 };

const VsPoint gUnk_08132E64[] = {
    { 23, 65, -12, -40, 0 },
    { 23, 85, 12, -40, 1 },
    { 23, 90, 0, -50, 2 },
};

const VsPointList gUnk_08132E88 = { 3, gUnk_08132E64, 60 };

const VsPoint gUnk_08132E94[] = {
    { 23, 40, 0, -30, 0 },
    { 23, -40, 0, -30, 1 },
};

const VsPointList gUnk_08132EAC = { 2, gUnk_08132E94, 60 };

const VsPoint gUnk_08132EB8[] = {
    { 23, 64, 0, -50, 0 },
};

const VsPointList gUnk_08132EC4 = { 1, gUnk_08132EB8, 60 };

const VsPoint gUnk_08132ED0[] = {
    { 23, -64, 0, -50, 0 },
};

const VsPointList gUnk_08132EDC = { 1, gUnk_08132ED0, 60 };

const VsPoint gUnk_08132EE8[] = {
    { 24, 40, 0, 0, 0 },
    { 24, 65, -12, 0, 1 },
    { 24, 85, 12, 0, 2 },
};

const VsPointList gUnk_08132F0C = { 3, gUnk_08132EE8, 60 };

const VsPoint gUnk_08132F18[] = {
    { 24, 65, -12, 0, 0 },
    { 24, 85, 12, 0, 1 },
    { 24, -40, 0, 0, 2 },
};

const VsPointList gUnk_08132F3C = { 3, gUnk_08132F18, 60 };

const VsPoint gUnk_08132F48[] = {
    { 24, 65, -12, 0, 0 },
    { 24, 85, 12, 0, 1 },
};

const VsPointList gUnk_08132F60 = { 2, gUnk_08132F48, 60 };

const VsPoint gUnk_08132F6C[] = {
    { 24, 64, 0, 0, 0 },
};

const VsPointList gUnk_08132F78 = { 1, gUnk_08132F6C, 60 };

const VsPoint gUnk_08132F84[] = {
    { 24, -64, 0, 0, 0 },
};

const VsPointList gUnk_08132F90 = { 1, gUnk_08132F84, 60 };

const VsPoint gUnk_08132F9C[] = {
    { 25, 65, -12, 0, 0 },
    { 25, 85, 12, 0, 1 },
};

const VsPointList gUnk_08132FB4 = { 2, gUnk_08132F9C, 60 };

const VsPoint gUnk_08132FC0[] = {
    { 25, 40, 0, 0, 0 },
    { 25, -40, 0, 0, 1 },
};

const VsPointList gUnk_08132FD8 = { 2, gUnk_08132FC0, 60 };

const VsPoint gUnk_08132FE4[] = {
    { 25, 64, 0, 0, 0 },
};

const VsPointList gUnk_08132FF0 = { 1, gUnk_08132FE4, 60 };

const VsPoint gUnk_08132FFC[] = {
    { 25, -64, 0, 0, 0 },
};

const VsPointList gUnk_08133008 = { 1, gUnk_08132FFC, 60 };

const VsPoint gUnk_08133014[] = {
    { 26, 25, -25, 0, 0 },
    { 26, 55, 25, 0, 1 },
};

const VsPointList gUnk_0813302C = { 2, gUnk_08133014, 60 };

const VsPoint gUnk_08133038[] = {
    { 26, 40, 0, 0, 0 },
    { 26, -40, 0, 0, 1 },
};

const VsPointList gUnk_08133050 = { 2, gUnk_08133038, 60 };

const VsPoint gUnk_0813305C[] = {
    { 26, -64, 0, 0, 0 },
};

const VsPointList gUnk_08133068 = { 1, gUnk_0813305C, 60 };

const VsPoint gUnk_08133074[] = {
    { 26, 64, 0, 0, 0 },
};

const VsPointList gUnk_08133080 = { 1, gUnk_08133074, 60 };

const VsPoint gUnk_0813308C[] = {
    { 27, 65, -12, -40, 0 },
    { 27, 85, 12, -40, 1 },
};

const VsPointList gUnk_081330A4 = { 2, gUnk_0813308C, 60 };

const VsPoint gUnk_081330B0[] = {
    { 27, 64, 0, -50, 0 },
};

const VsPointList gUnk_081330BC = { 1, gUnk_081330B0, 60 };

const VsPoint gUnk_081330C8[] = {
    { 27, -64, 0, -50, 0 },
};

const VsPointList gUnk_081330D4 = { 1, gUnk_081330C8, 60 };

const VsPoint gUnk_081330E0[] = {
    { 28, 25, -25, 0, 0 },
    { 28, 55, 25, 0, 1 },
};

const VsPointList gUnk_081330F8 = { 2, gUnk_081330E0, 60 };

const VsPoint gUnk_08133104[] = {
    { 28, 64, 0, 0, 0 },
};

const VsPointList gUnk_08133110 = { 1, gUnk_08133104, 60 };

const VsPoint gUnk_0813311C[] = {
    { 29, 25, -25, 0, 0 },
    { 29, 40, 0, 0, 1 },
    { 29, 55, 25, 0, 2 },
    { 29, 65, -12, 0, 3 },
    { 29, 85, 12, 0, 4 },
};

const VsPointList gUnk_08133158 = { 5, gUnk_0813311C, 60 };

const VsPoint gUnk_08133164[] = {
    { 29, 25, -25, 0, 0 },
    { 29, 55, 25, 0, 1 },
    { 29, 90, 0, 0, 2 },
    { 29, -65, -12, 0, 3 },
    { 29, -85, 12, 0, 4 },
};

const VsPointList gUnk_081331A0 = { 5, gUnk_08133164, 60 };

const VsPoint gUnk_081331AC[] = {
    { 29, 25, -25, 0, 0 },
    { 29, 55, 25, 0, 1 },
    { 29, 65, -12, 0, 2 },
    { 29, 85, 12, 0, 3 },
};

const VsPointList gUnk_081331DC = { 4, gUnk_081331AC, 60 };

const VsPoint gUnk_081331E8[] = {
    { 29, 40, 0, 0, 0 },
    { 29, 65, -12, 0, 1 },
    { 29, 85, 12, 0, 2 },
};

const VsPointList gUnk_0813320C = { 3, gUnk_081331E8, 60 };

const VsPoint gUnk_08133218[] = {
    { 29, 25, -25, 0, 0 },
    { 29, 64, 0, 0, 1 },
    { 29, 55, 25, 0, 2 },
};

const VsPointList gUnk_0813323C = { 3, gUnk_08133218, 60 };

const VsPoint gUnk_08133248[] = {
    { 29, -25, 25, 0, 0 },
    { 29, -64, 0, 0, 1 },
    { 29, -55, -25, 0, 2 },
};

const VsPointList gUnk_0813326C = { 3, gUnk_08133248, 60 };

const VsPoint gUnk_08133278[] = {
    { 29, 65, -12, 0, 0 },
    { 29, 85, 12, 0, 1 },
};

const VsPointList gUnk_08133290 = { 2, gUnk_08133278, 60 };

const VsPoint gUnk_0813329C[] = {
    { 29, 40, 0, 0, 0 },
    { 29, -40, 0, 0, 1 },
};

const VsPointList gUnk_081332B4 = { 2, gUnk_0813329C, 60 };

const VsPoint gUnk_081332C0[] = {
    { 29, -65, -12, 0, 0 },
    { 29, -85, 12, 0, 1 },
};

const VsPointList gUnk_081332D8 = { 2, gUnk_081332C0, 60 };

const VsPoint gUnk_081332E4[] = {
    { 29, -55, 25, 0, 0 },
    { 29, -25, -25, 0, 1 },
};

const VsPointList gUnk_081332FC = { 2, gUnk_081332E4, 60 };

const VsPoint gUnk_08133308[] = {
    { 29, 64, 0, 0, 0 },
};

const VsPointList gUnk_08133314 = { 1, gUnk_08133308, 60 };

const VsPoint gUnk_08133320[] = {
    { 30, 25, -25, 0, 0 },
    { 30, 40, 0, 0, 1 },
    { 30, 55, 25, 0, 2 },
    { 30, 65, -12, 0, 3 },
    { 30, 85, 12, 0, 4 },
};

const VsPointList gUnk_0813335C = { 5, gUnk_08133320, 60 };

const VsPoint gUnk_08133368[] = {
    { 30, 25, -25, 0, 0 },
    { 30, 55, 25, 0, 1 },
    { 30, 65, -12, 0, 2 },
    { 30, 85, 12, 0, 3 },
};

const VsPointList gUnk_08133398 = { 4, gUnk_08133368, 60 };

const VsPoint gUnk_081333A4[] = {
    { 30, 40, 0, 0, 0 },
    { 30, 65, -12, 0, 1 },
    { 30, 85, 12, 0, 2 },
};

const VsPointList gUnk_081333C8 = { 3, gUnk_081333A4, 60 };

const VsPoint gUnk_081333D4[] = {
    { 30, 25, -25, 0, 0 },
    { 30, 64, 0, 0, 1 },
    { 30, 55, 25, 0, 2 },
};

const VsPointList gUnk_081333F8 = { 3, gUnk_081333D4, 60 };

const VsPoint gUnk_08133404[] = {
    { 30, -25, 25, 0, 0 },
    { 30, -64, 0, 0, 1 },
    { 30, -55, -25, 0, 2 },
};

const VsPointList gUnk_08133428 = { 3, gUnk_08133404, 60 };

const VsPoint gUnk_08133434[] = {
    { 30, 65, -12, 0, 0 },
    { 30, 85, 12, 0, 1 },
};

const VsPointList gUnk_0813344C = { 2, gUnk_08133434, 60 };

const VsPoint gUnk_08133458[] = {
    { 30, -65, -12, 0, 0 },
    { 30, -85, 12, 0, 1 },
};

const VsPointList gUnk_08133470 = { 2, gUnk_08133458, 60 };

const VsPoint gUnk_0813347C[] = {
    { 30, -55, 25, 0, 0 },
    { 30, -25, -25, 0, 1 },
};

const VsPointList gUnk_08133494 = { 2, gUnk_0813347C, 60 };

const VsPoint gUnk_081334A0[] = {
    { 30, 64, 0, 0, 0 },
};

const VsPointList gUnk_081334AC = { 1, gUnk_081334A0, 60 };

const VsPoint gUnk_081334B8[] = {
    { 31, 25, -25, 0, 0 },
    { 31, 40, 0, 0, 1 },
    { 31, 25, 25, 0, 2 },
    { 31, -25, 25, 0, 3 },
    { 31, -40, 0, 0, 4 },
    { 31, -25, -25, 0, 5 },
};

const VsPointList gUnk_08133500 = { 6, gUnk_081334B8, 60 };

const VsPoint gUnk_0813350C[] = {
    { 31, 25, -25, 0, 0 },
    { 31, 40, 0, 0, 1 },
    { 31, 55, 25, 0, 2 },
    { 31, 65, -12, 0, 3 },
    { 31, 85, 12, 0, 4 },
};

const VsPointList gUnk_08133548 = { 5, gUnk_0813350C, 60 };

const VsPoint gUnk_08133554[] = {
    { 31, 25, -25, 0, 0 },
    { 31, 55, 25, 0, 1 },
    { 31, 90, 0, 0, 2 },
    { 31, -65, -12, 0, 3 },
    { 31, -85, 12, 0, 4 },
};

const VsPointList gUnk_08133590 = { 5, gUnk_08133554, 60 };

const VsPoint gUnk_0813359C[] = {
    { 31, 25, -25, 0, 0 },
    { 31, 55, 25, 0, 1 },
    { 31, 65, -12, 0, 2 },
    { 31, 85, 12, 0, 3 },
};

const VsPointList gUnk_081335CC = { 4, gUnk_0813359C, 60 };

const VsPoint gUnk_081335D8[] = {
    { 31, 40, 0, 0, 0 },
    { 31, 65, -12, 0, 1 },
    { 31, 85, 12, 0, 2 },
};

const VsPointList gUnk_081335FC = { 3, gUnk_081335D8, 60 };

const VsPoint gUnk_08133608[] = {
    { 31, -65, -12, 0, 0 },
    { 31, -85, 12, 0, 1 },
    { 31, 40, 0, 0, 2 },
};

const VsPointList gUnk_0813362C = { 3, gUnk_08133608, 60 };

const VsPoint gUnk_08133638[] = {
    { 31, 65, -12, 0, 0 },
    { 31, 85, 12, 0, 1 },
};

const VsPointList gUnk_08133650 = { 2, gUnk_08133638, 60 };

const VsPoint gUnk_0813365C[] = {
    { 31, 64, 0, 0, 0 },
};

const VsPointList gUnk_08133668 = { 1, gUnk_0813365C, 60 };

const VsPoint gUnk_08133674[] = {
    { 31, 40, 0, 0, 0 },
    { 31, -40, 0, 0, 1 },
};

const VsPointList gUnk_0813368C = { 2, gUnk_08133674, 60 };

const VsPoint gUnk_08133698[] = {
    { 31, -65, -12, 0, 0 },
    { 31, -85, 12, 0, 1 },
};

const VsPointList gUnk_081336B0 = { 2, gUnk_08133698, 60 };

const VsPoint gUnk_081336BC[] = {
    { 46, 65, -12, 0, 0 },
    { 46, 85, 12, 0, 1 },
    { 46, -40, 0, 0, 2 },
};

const VsPointList gUnk_081336E0 = { 3, gUnk_081336BC, 60 };

const VsPoint gUnk_081336EC[] = {
    { 46, -55, 25, 0, 0 },
    { 46, -25, -25, 0, 1 },
};

const VsPointList gUnk_08133704 = { 2, gUnk_081336EC, 60 };

const VsPoint gUnk_08133710[] = {
    { 46, 64, 0, 0, 0 },
};

const VsPointList gUnk_0813371C = { 1, gUnk_08133710, 60 };

const VsPoint gUnk_08133728[] = {
    { 47, 65, -12, 0, 0 },
    { 47, 85, 12, 0, 1 },
    { 47, 90, 0, 0, 2 },
};

const VsPointList gUnk_0813374C = { 3, gUnk_08133728, 60 };

const VsPoint gUnk_08133758[] = {
    { 47, 25, -25, 0, 0 },
    { 47, 55, 25, 0, 1 },
};

const VsPointList gUnk_08133770 = { 2, gUnk_08133758, 60 };

const VsPoint gUnk_0813377C[] = {
    { 47, 64, 0, 0, 0 },
};

const VsPointList gUnk_08133788 = { 1, gUnk_0813377C, 60 };

#ifndef VERSION_EU

typedef struct {
    u32 count;
    const VsPointList* const* lists;
    u32 unk_08;
} VsPointGroup;

extern const VsPointList* gUnk_09ED9BA8[];

const VsPointGroup gUnk_08133794[] = {
    { 14, &gUnk_09ED9BA8[0], 256 },
    { 4, &gUnk_09ED9BA8[14], 256 },
    { 1, &gUnk_09ED9BA8[18], 256 },
    { 2, &gUnk_09ED9BA8[19], 256 },
    { 5, &gUnk_09ED9BA8[21], 256 },
    { 1, &gUnk_09ED9BA8[26], 256 },
    { 1, &gUnk_09ED9BA8[27], 256 },
    { 1, &gUnk_09ED9BA8[28], 256 },
    { 1, &gUnk_09ED9BA8[29], 256 },
    { 1, &gUnk_09ED9BA8[30], 256 },
    { 1, &gUnk_09ED9BA8[31], 256 },
    { 2, &gUnk_09ED9BA8[32], 256 },
    { 2, &gUnk_09ED9BA8[34], 266 },
    { 3, &gUnk_09ED9BA8[36], 256 },
    { 3, &gUnk_09ED9BA8[39], 256 },
    { 3, &gUnk_09ED9BA8[42], 256 },
    { 4, &gUnk_09ED9BA8[45], 256 },
    { 1, &gUnk_09ED9BA8[49], 256 },
    { 3, &gUnk_09ED9BA8[50], 256 },
    { 4, &gUnk_09ED9BA8[53], 256 },
    { 4, &gUnk_09ED9BA8[57], 256 },
    { 2, &gUnk_09ED9BA8[61], 256 },
    { 1, &gUnk_09ED9BA8[63], 256 },
    { 3, &gUnk_09ED9BA8[64], 256 },
    { 2, &gUnk_09ED9BA8[67], 256 },
    { 2, &gUnk_09ED9BA8[69], 256 },
    { 3, &gUnk_09ED9BA8[71], 256 },
    { 3, &gUnk_09ED9BA8[74], 256 },
    { 3, &gUnk_09ED9BA8[77], 256 },
    { 3, &gUnk_09ED9BA8[80], 256 },
    { 3, &gUnk_09ED9BA8[83], 256 },
    { 4, &gUnk_09ED9BA8[86], 256 },
    { 3, &gUnk_09ED9BA8[90], 256 },
    { 3, &gUnk_09ED9BA8[93], 256 },
    { 2, &gUnk_09ED9BA8[96], 256 },
    { 4, &gUnk_09ED9BA8[98], 256 },
    { 3, &gUnk_09ED9BA8[102], 256 },
    { 3, &gUnk_09ED9BA8[105], 256 },
    { 3, &gUnk_09ED9BA8[108], 256 },
    { 4, &gUnk_09ED9BA8[111], 256 },
    { 3, &gUnk_09ED9BA8[115], 256 },
    { 3, &gUnk_09ED9BA8[118], 256 },
    { 2, &gUnk_09ED9BA8[121], 256 },
    { 3, &gUnk_09ED9BA8[123], 256 },
    { 4, &gUnk_09ED9BA8[126], 256 },
    { 4, &gUnk_09ED9BA8[130], 256 },
    { 4, &gUnk_09ED9BA8[134], 256 },
    { 3, &gUnk_09ED9BA8[138], 256 },
    { 3, &gUnk_09ED9BA8[141], 256 },
    { 4, &gUnk_09ED9BA8[144], 256 },
    { 6, &gUnk_09ED9BA8[148], 256 },
    { 3, &gUnk_09ED9BA8[154], 256 },
    { 3, &gUnk_09ED9BA8[157], 256 },
    { 2, &gUnk_09ED9BA8[160], 256 },
    { 2, &gUnk_09ED9BA8[162], 256 },
    { 3, &gUnk_09ED9BA8[164], 256 },
    { 3, &gUnk_09ED9BA8[167], 256 },
    { 1, &gUnk_09ED9BA8[170], 256 },
    { 4, &gUnk_09ED9BA8[171], 256 },
    { 5, &gUnk_09ED9BA8[175], 256 },
    { 4, &gUnk_09ED9BA8[180], 256 },
    { 4, &gUnk_09ED9BA8[184], 256 },
    { 3, &gUnk_09ED9BA8[188], 256 },
    { 2, &gUnk_09ED9BA8[191], 256 },
    { 2, &gUnk_09ED9BA8[193], 256 },
    { 3, &gUnk_09ED9BA8[195], 256 },
    { 4, &gUnk_09ED9BA8[198], 256 },
    { 3, &gUnk_09ED9BA8[202], 256 },
    { 1, &gUnk_09ED9BA8[205], 256 },
    { 2, &gUnk_09ED9BA8[206], 256 },
    { 5, &gUnk_09ED9BA8[208], 256 },
    { 1, &gUnk_09ED9BA8[213], 64 },
    { 2, &gUnk_09ED9BA8[214], 128 },
    { 2, &gUnk_09ED9BA8[216], 256 },
    { 2, &gUnk_09ED9BA8[218], 256 },
    { 2, &gUnk_09ED9BA8[220], 256 },
    { 2, &gUnk_09ED9BA8[222], 256 },
    { 3, &gUnk_09ED9BA8[224], 256 },
    { 3, &gUnk_09ED9BA8[227], 256 },
    { 4, &gUnk_09ED9BA8[230], 256 },
    { 2, &gUnk_09ED9BA8[234], 256 },
    { 2, &gUnk_09ED9BA8[236], 256 },
    { 4, &gUnk_09ED9BA8[238], 256 },
    { 3, &gUnk_09ED9BA8[242], 256 },
    { 4, &gUnk_09ED9BA8[245], 256 },
    { 5, &gUnk_09ED9BA8[249], 256 },
    { 3, &gUnk_09ED9BA8[254], 256 },
    { 5, &gUnk_09ED9BA8[257], 256 },
    { 3, &gUnk_09ED9BA8[262], 256 },
    { 4, &gUnk_09ED9BA8[265], 256 },
    { 4, &gUnk_09ED9BA8[269], 256 },
    { 4, &gUnk_09ED9BA8[273], 256 },
    { 5, &gUnk_09ED9BA8[277], 256 },
    { 3, &gUnk_09ED9BA8[282], 256 },
    { 3, &gUnk_09ED9BA8[285], 256 },
    { 2, &gUnk_09ED9BA8[288], 256 },
    { 2, &gUnk_09ED9BA8[290], 256 },
    { 3, &gUnk_09ED9BA8[292], 256 },
    { 4, &gUnk_09ED9BA8[295], 256 },
    { 4, &gUnk_09ED9BA8[299], 256 },
    { 4, &gUnk_09ED9BA8[303], 256 },
    { 2, &gUnk_09ED9BA8[307], 256 },
    { 3, &gUnk_09ED9BA8[309], 256 },
    { 3, &gUnk_09ED9BA8[312], 256 },
    { 3, &gUnk_09ED9BA8[315], 256 },
    { 3, &gUnk_09ED9BA8[318], 256 },
    { 3, &gUnk_09ED9BA8[321], 256 },
    { 3, &gUnk_09ED9BA8[324], 256 },
    { 3, &gUnk_09ED9BA8[327], 256 },
    { 2, &gUnk_09ED9BA8[330], 256 },
    { 3, &gUnk_09ED9BA8[332], 256 },
    { 4, &gUnk_09ED9BA8[335], 256 },
    { 3, &gUnk_09ED9BA8[339], 256 },
    { 3, &gUnk_09ED9BA8[342], 256 },
    { 3, &gUnk_09ED9BA8[345], 256 },
    { 2, &gUnk_09ED9BA8[348], 256 },
    { 4, &gUnk_09ED9BA8[350], 256 },
    { 4, &gUnk_09ED9BA8[354], 256 },
    { 4, &gUnk_09ED9BA8[358], 256 },
    { 4, &gUnk_09ED9BA8[362], 256 },
    { 4, &gUnk_09ED9BA8[366], 256 },
    { 4, &gUnk_09ED9BA8[370], 256 },
    { 3, &gUnk_09ED9BA8[374], 256 },
    { 6, &gUnk_09ED9BA8[377], 256 },
    { 5, &gUnk_09ED9BA8[383], 256 },
    { 3, &gUnk_09ED9BA8[388], 256 },
    { 9, &gUnk_09ED9BA8[391], 256 },
    { 4, &gUnk_09ED9BA8[400], 256 },
    { 4, &gUnk_09ED9BA8[404], 256 },
    { 8, &gUnk_09ED9BA8[408], 256 },
    { 5, &gUnk_09ED9BA8[416], 256 },
    { 3, &gUnk_09ED9BA8[421], 256 },
    { 2, &gUnk_09ED9BA8[424], 256 },
    { 1, &gUnk_09ED9BA8[426], 256 },
    { 1, &gUnk_09ED9BA8[427], 256 },
    { 2, &gUnk_09ED9BA8[428], 256 },
    { 1, &gUnk_09ED9BA8[430], 256 },
    { 2, &gUnk_09ED9BA8[431], 256 },
    { 2, &gUnk_09ED9BA8[433], 256 },
    { 1, &gUnk_09ED9BA8[435], 256 },
    { 1, &gUnk_09ED9BA8[436], 256 },
    { 3, &gUnk_09ED9BA8[437], 256 },
    { 3, &gUnk_09ED9BA8[440], 256 },
    { 3, &gUnk_09ED9BA8[443], 256 },
};

const VsPointList* gUnk_09ED9BA8[] = {
    &gUnk_08130ECC,
    &gUnk_08131238,
    &gUnk_08131430,
    &gUnk_08130F80,
    &gUnk_081311FC,
    &gUnk_08131358,
    &gUnk_081313C4,
    &gUnk_081311FC,
    &gUnk_08131328,
    &gUnk_081313E8,
    &gUnk_08131238,
    &gUnk_081312C8,
    &gUnk_08130F2C,
    &gUnk_08131448,
    &gUnk_081336E0,
    &gUnk_08133788,
    &gUnk_08133704,
    &gUnk_08133788,
    &gUnk_081326A8,
    &gUnk_081326A8,
    &gUnk_08132714,
    &gUnk_081326A8,
    &gUnk_081326F0,
    &gUnk_0813272C,
    &gUnk_081326CC,
    &gUnk_08132744,
    &gUnk_08131E74,
    &gUnk_08131E5C,
    &gUnk_08131DE4,
    &gUnk_08131F40,
    &gUnk_08131F28,
    &gUnk_08131EB0,
    &gUnk_08131184,
    &gUnk_08132FF0,
    &gUnk_08133650,
    &gUnk_081321C8,
    &gUnk_08131550,
    &gUnk_08133470,
    &gUnk_08132FF0,
    &gUnk_08132198,
    &gUnk_081336B0,
    &gUnk_0813344C,
    &gUnk_0813137C,
    &gUnk_08132FF0,
    &gUnk_081314CC,
    &gUnk_0813137C,
    &gUnk_08132258,
    &gUnk_08132FF0,
    &gUnk_08133008,
    &gUnk_0813335C,
    &gUnk_0813368C,
    &gUnk_08131358,
    &gUnk_0813152C,
    &gUnk_0813152C,
    &gUnk_08133008,
    &gUnk_08132FF0,
    &gUnk_081312C8,
    &gUnk_081314CC,
    &gUnk_0813344C,
    &gUnk_08133470,
    &gUnk_081320D8,
    &gUnk_08131100,
    &gUnk_08132210,
    &gUnk_08131F94,
    &gUnk_081313A0,
    &gUnk_081324B0,
    &gUnk_08131430,
    &gUnk_08132258,
    &gUnk_08132480,
    &gUnk_08132450,
    &gUnk_081324D4,
    &gUnk_081312F8,
    &gUnk_081321C8,
    &gUnk_081324D4,
    &gUnk_081312F8,
    &gUnk_08131238,
    &gUnk_081310B8,
    &gUnk_0813209C,
    &gUnk_08131430,
    &gUnk_0813140C,
    &gUnk_081324F8,
    &gUnk_081312C8,
    &gUnk_081312F8,
    &gUnk_08132414,
    &gUnk_08132258,
    &gUnk_081312F8,
    &gUnk_08131430,
    &gUnk_08132D2C,
    &gUnk_0813140C,
    &gUnk_08132D8C,
    &gUnk_0813323C,
    &gUnk_08132E04,
    &gUnk_08132DD4,
    &gUnk_08133428,
    &gUnk_08132DBC,
    &gUnk_08132DEC,
    &gUnk_081335CC,
    &gUnk_08132D50,
    &gUnk_081332B4,
    &gUnk_08133470,
    &gUnk_08133314,
    &gUnk_081334AC,
    &gUnk_081313C4,
    &gUnk_08133500,
    &gUnk_081311FC,
    &gUnk_081335CC,
    &gUnk_081332D8,
    &gUnk_08133314,
    &gUnk_081335CC,
    &gUnk_08133494,
    &gUnk_08133314,
    &gUnk_08132D2C,
    &gUnk_08131100,
    &gUnk_08132DBC,
    &gUnk_08132DEC,
    &gUnk_0813326C,
    &gUnk_081333F8,
    &gUnk_0813362C,
    &gUnk_08131268,
    &gUnk_08132FF0,
    &gUnk_0813230C,
    &gUnk_081316A0,
    &gUnk_081322E8,
    &gUnk_0813230C,
    &gUnk_08132FF0,
    &gUnk_08132330,
    &gUnk_081316A0,
    &gUnk_0813239C,
    &gUnk_081316E8,
    &gUnk_08131754,
    &gUnk_0813230C,
    &gUnk_081323D8,
    &gUnk_0813230C,
    &gUnk_081323D8,
    &gUnk_08132FF0,
    &gUnk_081323C0,
    &gUnk_08133008,
    &gUnk_081316C4,
    &gUnk_08132378,
    &gUnk_08132FF0,
    &gUnk_081316C4,
    &gUnk_081311FC,
    &gUnk_081322E8,
    &gUnk_08132FD8,
    &gUnk_08131100,
    &gUnk_081316C4,
    &gUnk_08132FF0,
    &gUnk_0813170C,
    &gUnk_08131670,
    &gUnk_081312F8,
    &gUnk_08132348,
    &gUnk_0813230C,
    &gUnk_0813239C,
    &gUnk_081323C0,
    &gUnk_08131184,
    &gUnk_08131B38,
    &gUnk_0813194C,
    &gUnk_081324F8,
    &gUnk_08132798,
    &gUnk_081332B4,
    &gUnk_08132FF0,
    &gUnk_0813326C,
    &gUnk_08131838,
    &gUnk_08131A6C,
    &gUnk_08131298,
    &gUnk_081324F8,
    &gUnk_08133008,
    &gUnk_08132774,
    &gUnk_08131898,
    &gUnk_08131928,
    &gUnk_081331A0,
    &gUnk_08132FD8,
    &gUnk_08131A6C,
    &gUnk_08132FF0,
    &gUnk_08131B80,
    &gUnk_08131148,
    &gUnk_08131238,
    &gUnk_081312F8,
    &gUnk_08131430,
    &gUnk_08131448,
    &gUnk_08132450,
    &gUnk_081327F8,
    &gUnk_08132810,
    &gUnk_081327F8,
    &gUnk_0813137C,
    &gUnk_081329C0,
    &gUnk_0813140C,
    &gUnk_081329D8,
    &gUnk_081327F8,
    &gUnk_0813362C,
    &gUnk_08132A80,
    &gUnk_08132984,
    &gUnk_0813368C,
    &gUnk_08132A08,
    &gUnk_081327E0,
    &gUnk_081311FC,
    &gUnk_0813368C,
    &gUnk_08132798,
    &gUnk_08132A2C,
    &gUnk_081329D8,
    &gUnk_08132A68,
    &gUnk_081329C0,
    &gUnk_081310B8,
    &gUnk_08132A50,
    &gUnk_08132810,
    &gUnk_08133590,
    &gUnk_0813362C,
    &gUnk_0813293C,
    &gUnk_08132A2C,
    &gUnk_081329A8,
    &gUnk_081311FC,
    &gUnk_08132A50,
    &gUnk_0813293C,
    &gUnk_081312F8,
    &gUnk_0813158C,
    &gUnk_081313A0,
    &gUnk_081313A0,
    &gUnk_081316C4,
    &gUnk_08131550,
    &gUnk_081316C4,
    &gUnk_08132270,
    &gUnk_081313A0,
    &gUnk_081322A0,
    &gUnk_08131550,
    &gUnk_081313C4,
    &gUnk_08132270,
    &gUnk_081322A0,
    &gUnk_08132270,
    &gUnk_081322A0,
    &gUnk_081316C4,
    &gUnk_081313A0,
    &gUnk_0813173C,
    &gUnk_0813158C,
    &gUnk_08132234,
    &gUnk_081311FC,
    &gUnk_081321EC,
    &gUnk_08131CD0,
    &gUnk_08132D50,
    &gUnk_08132834,
    &gUnk_081330BC,
    &gUnk_08132888,
    &gUnk_08132870,
    &gUnk_08132D08,
    &gUnk_08132DA4,
    &gUnk_08132D8C,
    &gUnk_08132798,
    &gUnk_08131D3C,
    &gUnk_08132870,
    &gUnk_081330D4,
    &gUnk_08132D8C,
    &gUnk_08132810,
    &gUnk_08132D8C,
    &gUnk_08132810,
    &gUnk_08132D8C,
    &gUnk_08131C4C,
    &gUnk_08132D8C,
    &gUnk_08132DA4,
    &gUnk_081330BC,
    &gUnk_081328A0,
    &gUnk_081328B8,
    &gUnk_081328D0,
    &gUnk_081328E8,
    &gUnk_08131D0C,
    &gUnk_081327BC,
    &gUnk_081330BC,
    &gUnk_08132834,
    &gUnk_08132DA4,
    &gUnk_08132D8C,
    &gUnk_08132888,
    &gUnk_08131CD0,
    &gUnk_08132858,
    &gUnk_081330BC,
    &gUnk_08132888,
    &gUnk_0813140C,
    &gUnk_08132678,
    &gUnk_08133080,
    &gUnk_08132624,
    &gUnk_081318E0,
    &gUnk_08131B80,
    &gUnk_08133080,
    &gUnk_08131AF0,
    &gUnk_0813194C,
    &gUnk_08131358,
    &gUnk_081324B0,
    &gUnk_08131358,
    &gUnk_08132414,
    &gUnk_08131B98,
    &gUnk_08131B98,
    &gUnk_08133050,
    &gUnk_08133080,
    &gUnk_081325D0,
    &gUnk_08131B38,
    &gUnk_08131184,
    &gUnk_081324D4,
    &gUnk_08131838,
    &gUnk_081312F8,
    &gUnk_081324D4,
    &gUnk_08132624,
    &gUnk_08133080,
    &gUnk_08132624,
    &gUnk_08131ACC,
    &gUnk_08131868,
    &gUnk_08132648,
    &gUnk_081325D0,
    &gUnk_08133068,
    &gUnk_08132624,
    &gUnk_08133080,
    &gUnk_081312F8,
    &gUnk_08132B34,
    &gUnk_08132C0C,
    &gUnk_08132DA4,
    &gUnk_08132D8C,
    &gUnk_081311C0,
    &gUnk_08133470,
    &gUnk_08132BD0,
    &gUnk_081311FC,
    &gUnk_08132D74,
    &gUnk_08132D8C,
    &gUnk_08132C30,
    &gUnk_081333F8,
    &gUnk_08132C9C,
    &gUnk_08132B34,
    &gUnk_08132DA4,
    &gUnk_08132D8C,
    &gUnk_08132B34,
    &gUnk_08132C54,
    &gUnk_08132B64,
    &gUnk_081310B8,
    &gUnk_08132B64,
    &gUnk_08132BD0,
    &gUnk_08132D2C,
    &gUnk_08133428,
    &gUnk_08132C54,
    &gUnk_08132B34,
    &gUnk_08132C6C,
    &gUnk_08131238,
    &gUnk_08132DBC,
    &gUnk_08132DBC,
    &gUnk_08132DEC,
    &gUnk_08130F80,
    &gUnk_08133110,
    &gUnk_081332D8,
    &gUnk_08132E28,
    &gUnk_08132EDC,
    &gUnk_08132D2C,
    &gUnk_0813320C,
    &gUnk_08132E58,
    &gUnk_08132E40,
    &gUnk_081330F8,
    &gUnk_08132EAC,
    &gUnk_081311FC,
    &gUnk_08132EAC,
    &gUnk_081313A0,
    &gUnk_08131430,
    &gUnk_08132E28,
    &gUnk_08132DA4,
    &gUnk_08132D8C,
    &gUnk_08132DA4,
    &gUnk_08133110,
    &gUnk_08132E58,
    &gUnk_08133110,
    &gUnk_08132EDC,
    &gUnk_08132CE4,
    &gUnk_0813326C,
    &gUnk_08132DBC,
    &gUnk_08132DEC,
    &gUnk_08131100,
    &gUnk_08133110,
    &gUnk_08132EDC,
    &gUnk_08133110,
    &gUnk_081311FC,
    &gUnk_08132EAC,
    &gUnk_08131184,
    &gUnk_08132D74,
    &gUnk_081310B8,
    &gUnk_08132F60,
    &gUnk_08132F78,
    &gUnk_08133110,
    &gUnk_081315A4,
    &gUnk_081317B4,
    &gUnk_081319B8,
    &gUnk_08131BE0,
    &gUnk_08132EAC,
    &gUnk_08132D08,
    &gUnk_08132DBC,
    &gUnk_08132DEC,
    &gUnk_08132E04,
    &gUnk_08132D74,
    &gUnk_08132E28,
    &gUnk_081330F8,
    &gUnk_08131838,
    &gUnk_08131550,
    &gUnk_081316C4,
    &gUnk_08131970,
    &gUnk_08131B5C,
    &gUnk_08132EC4,
    &gUnk_08131AF0,
    &gUnk_081318E0,
    &gUnk_0813170C,
    &gUnk_08131574,
    &gUnk_08132E28,
    &gUnk_08132F78,
    &gUnk_08132F90,
    &gUnk_08133110,
    &gUnk_081311FC,
    &gUnk_08132EAC,
    &gUnk_08132F90,
    &gUnk_08132F78,
    &gUnk_08133110,
    &gUnk_081315A4,
    &gUnk_081317B4,
    &gUnk_081319B8,
    &gUnk_08131BE0,
    &gUnk_08132EC4,
    &gUnk_08132E58,
    &gUnk_08132F60,
    &gUnk_08132F3C,
    &gUnk_08132F60,
    &gUnk_081311FC,
    &gUnk_08131430,
    &gUnk_08132F78,
    &gUnk_08131268,
    &gUnk_08132D8C,
    &gUnk_08132DA4,
    &gUnk_08133110,
    &gUnk_081311FC,
    &gUnk_08132E28,
    &gUnk_0813320C,
    &gUnk_08132E40,
    &gUnk_08132EC4,
    &gUnk_08132EAC,
    &gUnk_081313C4,
    &gUnk_08132EAC,
    &gUnk_08133110,
    &gUnk_08132EDC,
    &gUnk_08132CE4,
    &gUnk_08131100,
    &gUnk_08132270,
    &gUnk_08133314,
    &gUnk_0813158C,
    &gUnk_08132270,
    &gUnk_081334AC,
    &gUnk_0813158C,
    &gUnk_08132270,
    &gUnk_08133668,
    &gUnk_0813158C,
};

#endif
