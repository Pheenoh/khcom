#include "task_descriptors.h"
#include "display.h"
#include "emy.h"
#include "task_animation_assets.h"
#include "sprites_emy.h"
#include "sprites_evt.h"

const AnimDef gUnk_0813D32C[3] = {
    { gEmy00L00Frames, gEmy00L00Anims, gEmy00L00Tiles, 0, { 0, 0, 0 } },
    { gEmy00L09Frames, gEmy00L09Anims, gEmy00L09Tiles, 0, { 0, 0, 0 } },
    { gEmy00L02Frames, gEmy00L02Anims, gEmy00L02Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813D35C[7] = {
    { gEmy00L07Frames, gEmy00L07Anims, gEmy00L07Tiles, 1, { 0, 0, 0 } },
    { gEmy00L12Frames, gEmy00L12Anims, gEmy00L12Tiles, 0, { 0, 0, 0 } },
    { gEmy00L06Frames, gEmy00L06Anims, gEmy00L06Tiles, 1, { 0, 0, 0 } },
    { gEmy00L06Frames, gEmy00L06Anims, gEmy00L06Tiles, 0, { 0, 0, 0 } },
    { gEmy00L04Frames, gEmy00L04Anims, gEmy00L04Tiles, 0, { 0, 0, 0 } },
    { gEmy00L10Frames, gEmy00L10Anims, gEmy00L10Tiles, 0, { 0, 0, 0 } },
    { gEmy00L11Frames, gEmy00L11Anims, gEmy00L11Tiles, 0, { 0, 0, 0 } },
};

const EmyDef gEmy00Def = { gEmy00Palette, gUnk_0813D32C, 384, 130, 10, 20, 64, 32, 16, 10, 3, { 0, 12, 32, 12, 16, 100, 0 } };

TaskDesc gTaskDescEmy00 = { "task_emy_00", task_emy_00_0, task_emy_00_1, task_emy_00_2, task_emy_00_3, 0x184 };

const AnimDef gUnk_0813D404[3] = {
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 0, { 0, 0, 0 } },
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 3, { 0, 0, 0 } },
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 2, { 0, 0, 0 } },
};

const AnimDef gUnk_0813D434[2] = {
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 1, { 0, 0, 0 } },
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 1, { 0, 0, 0 } },
};

const EmyDef gEmy01Def = { gEmy01Palette, gUnk_0813D404, 384, 130, 20, 20, 64, 32, 32, 10, 0, { 1, 33, 24, 12, 4, 100, 8 } };

TaskDesc gTaskDescEmy01 = { "task_emy_01", task_emy_01_0, task_emy_01_1, task_emy_01_2, task_emy_01_3, 0x184 };

const AnimDef gUnk_0813D48C[3] = {
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 0, { 0, 0, 0 } },
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 3, { 0, 0, 0 } },
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 2, { 0, 0, 0 } },
};

const AnimDef gUnk_0813D4BC[2] = {
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 6, { 0, 0, 0 } },
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 8, { 0, 0, 0 } },
};

const EmyDef gEmy02Def = { gEmy02Palette, gUnk_0813D48C, 460, 130, 20, 20, 64, 32, 32, 10, 0, { 2, 34, 24, 12, 4, 100, 8 } };

TaskDesc gTaskDescEmy02 = { "task_emy_02", task_emy_02_0, task_emy_02_1, task_emy_02_2, task_emy_02_3, 0x184 };

const AnimDef gUnk_0813D514[3] = {
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 0, { 0, 0, 0 } },
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 3, { 0, 0, 0 } },
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 2, { 0, 0, 0 } },
};

const AnimDef gUnk_0813D544[2] = {
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 7, { 0, 0, 0 } },
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 5, { 0, 0, 0 } },
};

const EmyDef gEmy03Def = { gEmy03Palette, gUnk_0813D514, 512, 130, 20, 20, 64, 32, 32, 10, 0, { 3, 36, 24, 12, 4, 100, 8 } };

TaskDesc gTaskDescEmy03 = { "task_emy_03", task_emy_03_0, task_emy_03_1, task_emy_03_2, task_emy_03_3, 0x190 };

const AnimDef gUnk_0813D59C[3] = {
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 0, { 0, 0, 0 } },
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 3, { 0, 0, 0 } },
    { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 2, { 0, 0, 0 } },
};

const AnimDef gUnk_0813D5CC = { gEmy01L00Frames, gEmy01L00Anims, gEmy01L00Tiles, 4, { 0, 0, 0 } };

const EmyDef gEmy04Def = { gEmy04Palette, gUnk_0813D59C, 332, 130, 20, 20, 0, 0, 0, 200, 0, { 4, 27, 24, 12, 4, 100, 8 } };

TaskDesc gTaskDescEmy04 = { "task_emy_04", task_emy_04_0, task_emy_04_1, task_emy_04_2, task_emy_04_3, 0x188 };

const AnimDef gUnk_0813D614[3] = {
    { gEmy0600Frames, gEmy0600Anims, gEmy0600Tiles, 0, { 0, 0, 0 } },
    { gEmy0603Frames, gEmy0603Anims, gEmy0603Tiles, 0, { 0, 0, 0 } },
    { gEmy0600Frames, gEmy0600Anims, gEmy0600Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813D644[2] = {
    { gEmy0610Frames, gEmy0610Anims, gEmy0610Tiles, 0, { 0, 0, 0 } },
    { gEmy0611Frames, gEmy0611Anims, gEmy0611Tiles, 0, { 0, 0, 0 } },
};

const EmyDef gEmy06Def = { gEmy06Palette, gUnk_0813D614, 230, 130, 20, 20, 70, 32, 48, 10, 0, { 5, 42, 32, 8, 16, 100, 0 } };

TaskDesc gTaskDescEmy06 = { "task_emy_06", task_emy_06_0, task_emy_06_1, task_emy_06_2, task_emy_06_3, 0x188 };

const AnimDef gUnk_0813D69C[3] = {
    { gEmy07Fl00Frames, gEmy07Fl00Anims, gEmy07Fl00Tiles, 0, { 0, 0, 0 } },
    { gEmy07Fl03Frames, gEmy07Fl03Anims, gEmy07Fl03Tiles, 0, { 0, 0, 0 } },
    { gEmy07Fl00Frames, gEmy07Fl00Anims, gEmy07Fl00Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813D6CC[7] = {
    { gEmy07Fl05Frames, gEmy07Fl05Anims, gEmy07Fl05Tiles, 0, { 0, 0, 0 } },
    { gEmy07Fl04Frames, gEmy07Fl04Anims, gEmy07Fl04Tiles, 0, { 0, 0, 0 } },
    { gEmy07Fl04tFrames, gEmy07Fl04tAnims, gEmy07Fl04tTiles, 0, { 0, 0, 0 } },
    { gEmy07Fl07Frames, gEmy07Fl07Anims, gEmy07Fl07Tiles, 0, { 0, 0, 0 } },
    { gEmy07Fl06Frames, gEmy07Fl06Anims, gEmy07Fl06Tiles, 0, { 0, 0, 0 } },
    { gEmy07Fl08Frames, gEmy07Fl08Anims, gEmy07Fl08Tiles, 0, { 0, 0, 0 } },
    { gEmy07Fl02Frames, gEmy07Fl02Anims, gEmy07Fl02Tiles, 0, { 0, 0, 0 } },
};

const EmyDef gEmy07Def = { gEmy07Palette, gUnk_0813D69C, 0, 130, 20, 20, 0, 0, 0, 1, 0, { 6, 40, 32, 12, 16, 100, 0 } };

TaskDesc gTaskDescEmy07 = { "task_emy_07", task_emy_07_0, task_emy_07_1, task_emy_07_2, task_emy_07_3, 0x188 };

const AnimDef gUnk_0813D774[3] = {
    { gEmy07Fl00Frames, gEmy07Fl00Anims, gEmy07Fl00Tiles, 0, { 0, 0, 0 } },
    { gEmy07Fl03Frames, gEmy07Fl03Anims, gEmy07Fl03Tiles, 0, { 0, 0, 0 } },
    { gEmy07Fl09Frames, gEmy07Fl09Anims, gEmy07Fl09Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813D7A4[6] = {
    { gEmy07Fl10Frames, gEmy07Fl10Anims, gEmy07Fl10Tiles, 0, { 0, 0, 0 } },
    { gUnk_09EDFFDC, gUnk_09EE0004, gUnk_089C292C, 0, { 0, 0, 0 } },
    { gEmy07Fl10tFrames, gEmy07Fl10tAnims, gEmy07Fl10tTiles, 0, { 0, 0, 0 } },
    { gEmy07Fl10fFrames, gEmy07Fl10fAnims, gEmy07Fl10fTiles, 0, { 0, 0, 0 } },
    { gEmy07Fl11tFrames, gEmy07Fl11tAnims, gEmy07Fl11tTiles, 0, { 0, 0, 0 } },
    { gEmy07Fl11fFrames, gEmy07Fl11fAnims, gEmy07Fl11fTiles, 0, { 0, 0, 0 } },
};

const EmyDef gEmy08Def = { gEmy07bPalette, gUnk_0813D774, 179, 130, 20, 20, 24, 24, 16, 5, 0, { 7, 999, 32, 12, 16, 100, 0 } };

TaskDesc gTaskDescEmy08 = { "task_emy_08", task_emy_08_0, task_emy_08_1, task_emy_08_2, task_emy_08_3, 0x190 };

const AnimDef gUnk_0813D83C[3] = {
    { gEmy14Ll00Frames, gEmy14Ll00Anims, gEmy14Ll00Tiles, 0, { 0, 0, 0 } },
    { gEmy14Ll03Frames, gEmy14Ll03Anims, gEmy14Ll03Tiles, 0, { 0, 0, 0 } },
    { gEmy14Ll01Frames, gEmy14Ll01Anims, gEmy14Ll01Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813D86C[2] = {
    { gEmy14Ll02Frames, gEmy14Ll02Anims, gEmy14Ll02Tiles, 0, { 0, 0, 0 } },
    { gEmy14Ll04Frames, gEmy14Ll04Anims, gEmy14Ll04Tiles, 0, { 0, 0, 0 } },
};

const EmyDef gEmy14Def = { gEmy14Palette, gUnk_0813D83C, 307, 130, 10, 20, 64, 32, 16, 10, 0, { 9, 32, 35, 12, 16, 100, 0 } };

TaskDesc gTaskDescEmy14 = { "task_emy_14", task_emy_14_0, task_emy_14_1, task_emy_14_2, task_emy_14_3, 0x184 };

const AnimDef gUnk_0813D8C4[3] = {
    { gEmy1500Frames, gEmy1500Anims, gEmy1500Tiles, 0, { 0, 0, 0 } },
    { gEmy1502Frames, gEmy1502Anims, gEmy1502Tiles, 0, { 0, 0, 0 } },
    { gEmy1501Frames, gEmy1501Anims, gEmy1501Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813D8F4[5] = {
    { gEmy1510Frames, gEmy1510Anims, gEmy1510Tiles, 0, { 0, 0, 0 } },
    { gEmy1510Frames, gEmy1510Anims, gEmy1510Tiles, 1, { 0, 0, 0 } },
    { gEmy1510Frames, gEmy1510Anims, gEmy1510Tiles, 2, { 0, 0, 0 } },
    { gEmy1511Frames, gEmy1511Anims, gEmy1511Tiles, 0, { 0, 0, 0 } },
    { gEmy1511Frames, gEmy1511Anims, gEmy1511Tiles, 1, { 0, 0, 0 } },
};

const EmyDef gEmy15Def = { gEmy15Palette, gUnk_0813D8C4, 192, 200, 2, 20, 64, 32, 32, 10, 0, { 10, 41, 35, 12, 16, 100, 0 } };

TaskDesc gTaskDescEmy15 = { "task_emy_15", task_emy_15_0, task_emy_15_1, task_emy_15_2, task_emy_15_3, 0x184 };

const AnimDef gUnk_0813D97C[3] = {
    { gEmy1600Frames, gEmy1600Anims, gEmy1600Tiles, 0, { 0, 0, 0 } },
    { gEmy1602Frames, gEmy1602Anims, gEmy1602Tiles, 0, { 0, 0, 0 } },
    { gEmy1601Frames, gEmy1601Anims, gEmy1601Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813D9AC[2] = {
    { gEmy1610Frames, gEmy1610Anims, gEmy1610Tiles, 0, { 0, 0, 0 } },
    { gEmy1611Frames, gEmy1611Anims, gEmy1611Tiles, 0, { 0, 0, 0 } },
};

const EmyDef gEmy16Def = { gEmy16Palette, gUnk_0813D97C, 307, 130, 20, 20, 99, 32, 32, 10, 0, { 11, 29, 16, 8, 16, 100, 0 } };

TaskDesc gTaskDescEmy16 = { "task_emy_16", task_emy_16_0, task_emy_16_1, task_emy_16_2, task_emy_16_3, 0x1A4 };

TaskDesc gTaskDescEmy16B = { "task_emy_16_b", task_emy_16_b_0, task_emy_16_b_1, task_emy_16_b_2, task_emy_16_b_3, 0xA0 };

TaskDesc gTaskDescEmy16P = { "task_emy_16_p", task_emy_16_p_0, task_emy_16_p_1, task_emy_16_p_2, task_emy_16_p_3, 0x34 };

const AnimDef gUnk_0813DA24[3] = {
    { gEmy1800Frames, gEmy1800Anims, gEmy1800Tiles, 0, { 0, 0, 0 } },
    { gEmy1802Frames, gEmy1802Anims, gEmy1802Tiles, 0, { 0, 0, 0 } },
    { gEmy1801Frames, gEmy1801Anims, gEmy1801Tiles, 1, { 0, 0, 0 } },
};

const AnimDef gUnk_0813DA54[4] = {
    { gEmy1810Frames, gEmy1810Anims, gEmy1810Tiles, 0, { 0, 0, 0 } },
    { gEmy1811Frames, gEmy1811Anims, gEmy1811Tiles, 0, { 0, 0, 0 } },
    { gEmy1801Frames, gEmy1801Anims, gEmy1801Tiles, 0, { 0, 0, 0 } },
    { gEmy1801Frames, gEmy1801Anims, gEmy1801Tiles, 2, { 0, 0, 0 } },
};

const EmyDef gEmy18Def = { gEmy18Palette, gUnk_0813DA24, 768, 150, 4, 20, 40, 24, 16, 10, 0, { 12, 45, 40, 8, 16, 100, 0 } };

TaskDesc gTaskDescEmy18 = { "task_emy_18", task_emy_18_0, task_emy_18_1, task_emy_18_2, task_emy_18_3, 0x188 };

const AnimDef gUnk_0813DACC[3] = {
    { gEmy1900Frames, gEmy1900Anims, gEmy1900Tiles, 0, { 0, 0, 0 } },
    { gEmy1902Frames, gEmy1902Anims, gEmy1902Tiles, 0, { 0, 0, 0 } },
    { gEmy1901Frames, gEmy1901Anims, gEmy1901Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813DAFC[5] = {
    { gEmy1910Frames, gEmy1910Anims, gEmy1910Tiles, 0, { 0, 0, 0 } },
    { gEmy1910Frames, gEmy1910Anims, gEmy1910Tiles, 1, { 0, 0, 0 } },
    { gEmy1910Frames, gEmy1910Anims, gEmy1910Tiles, 2, { 0, 0, 0 } },
    { gEmy1910Frames, gEmy1910Anims, gEmy1910Tiles, 3, { 0, 0, 0 } },
    { gEmy1911Frames, gEmy1911Anims, gEmy1911Tiles, 0, { 0, 0, 0 } },
};

const EmyDef gEmy19Def = { gEmy19Palette, gUnk_0813DACC, 256, 130, 20, 20, 80, 80, 32, 10, 0, { 13, 53, 32, 13, 16, 100, 0 } };

TaskDesc gTaskDescEmy19 = { "task_emy_19", task_emy_19_0, task_emy_19_1, task_emy_19_2, task_emy_19_3, 0x188 };

const AnimDef gUnk_0813DB84[3] = {
    { gEmy2100Frames, gEmy2100Anims, gEmy2100Tiles, 0, { 0, 0, 0 } },
    { gEmy2102Frames, gEmy2102Anims, gEmy2102Tiles, 0, { 0, 0, 0 } },
    { gEmy2101Frames, gEmy2101Anims, gEmy2101Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813DBB4[4] = {
    { gEmy2110Frames, gEmy2110Anims, gEmy2110Tiles, 0, { 0, 0, 0 } },
    { gEmy2111Frames, gEmy2111Anims, gEmy2111Tiles, 0, { 0, 0, 0 } },
    { gEmy2111Frames, gEmy2111Anims, gEmy2111Tiles, 1, { 0, 0, 0 } },
    { gEmy2111fFrames, gEmy2111fAnims, gEmy2111fTiles, 0, { 0, 0, 0 } },
};

const EmyDef gEmy21Def = { gEmy21Palette, gUnk_0813DB84, 396, 130, 20, 20, 80, 80, 16, 5, 0, { 14, 40, 32, 16, 16, 100, 0 } };

TaskDesc gTaskDescEmy21 = { "task_emy_21", task_emy_21_0, task_emy_21_1, task_emy_21_2, task_emy_21_3, 0x188 };

const AnimDef gUnk_0813DC2C[3] = {
    { gEmy2200Frames, gEmy2200Anims, gEmy2200Tiles, 0, { 0, 0, 0 } },
    { gEmy2202Frames, gEmy2202Anims, gEmy2202Tiles, 0, { 0, 0, 0 } },
    { gEmy2200Frames, gEmy2200Anims, gEmy2200Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813DC5C[2] = {
    { gEmy2210Frames, gEmy2210Anims, gEmy2210Tiles, 0, { 0, 0, 0 } },
    { gEmy2211Frames, gEmy2211Anims, gEmy2211Tiles, 0, { 0, 0, 0 } },
};

const EmyDef gEmy22Def = { gEmy22Palette, gUnk_0813DC2C, 192, 130, 20, 20, 64, 32, 32, 5, 0, { 15, 61, 40, 12, 24, 15, 8 } };

TaskDesc gTaskDescEmy22 = { "task_emy_22", task_emy_22_0, task_emy_22_1, task_emy_22_2, task_emy_22_3, 0x188 };

const AnimDef gUnk_0813DCB4[3] = {
    { gEmy2300Frames, gEmy2300Anims, gEmy2300Tiles, 0, { 0, 0, 0 } },
    { gEmy2302Frames, gEmy2302Anims, gEmy2302Tiles, 0, { 0, 0, 0 } },
    { gEmy2301Frames, gEmy2301Anims, gEmy2301Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813DCE4[2] = {
    { gEmy2310Frames, gEmy2310Anims, gEmy2310Tiles, 0, { 0, 0, 0 } },
    { gEmy2311Frames, gEmy2311Anims, gEmy2311Tiles, 0, { 0, 0, 0 } },
};

const EmyDef gEmy23Def = { gEmy23Palette, gUnk_0813DCB4, 192, 30, 2, 20, 64, 40, 32, 25, 0, { 16, 66, 36, 10, 16, 100, 0 } };

TaskDesc gTaskDescEmy23 = { "task_emy_23", task_emy_23_0, task_emy_23_1, task_emy_23_2, task_emy_23_3, 0x188 };

const AnimDef gUnk_0813DD3C[3] = {
    { gEmy2500Frames, gEmy2500Anims, gEmy2500Tiles, 0, { 0, 0, 0 } },
    { gEmy2502Frames, gEmy2502Anims, gEmy2502Tiles, 0, { 0, 0, 0 } },
    { gEmy2501Frames, gEmy2501Anims, gEmy2501Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813DD6C[2] = {
    { gEmy2510Frames, gEmy2510Anims, gEmy2510Tiles, 0, { 0, 0, 0 } },
    { gEmy2511Frames, gEmy2511Anims, gEmy2511Tiles, 0, { 0, 0, 0 } },
};

const EmyDef gEmy25Def = { gEmy25Palette, gUnk_0813DD3C, 253, 130, 20, 20, 24, 16, 16, 3, 0, { 17, 79, 40, 12, 32, 100, 0 } };

TaskDesc gTaskDescEmy25 = { "task_emy_25", task_emy_25_0, task_emy_25_1, task_emy_25_2, task_emy_25_3, 0x184 };

const AnimDef gUnk_0813DDC4[3] = {
    { gEmy2600Frames, gEmy2600Anims, gEmy2600Tiles, 0, { 0, 0, 0 } },
    { gEmy2602Frames, gEmy2602Anims, gEmy2602Tiles, 0, { 0, 0, 0 } },
    { gEmy2601Frames, gEmy2601Anims, gEmy2601Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813DDF4[2] = {
    { gEmy2610Frames, gEmy2610Anims, gEmy2610Tiles, 0, { 0, 0, 0 } },
    { gEmy2611Frames, gEmy2611Anims, gEmy2611Tiles, 0, { 0, 0, 0 } },
};

const EmyDef gEmy26Def = { gEmy26Palette, gUnk_0813DDC4, 192, 130, 20, 20, 64, 32, 32, 10, 0, { 18, 89, 36, 20, 16, 100, 4 } };

TaskDesc gTaskDescEmy26 = { "task_emy_26", task_emy_26_0, task_emy_26_1, task_emy_26_2, task_emy_26_3, 0x184 };

const AnimDef gUnk_0813DE4C[3] = {
    { gEmy2700Frames, gEmy2700Anims, gEmy2700Tiles, 0, { 0, 0, 0 } },
    { gEmy2702Frames, gEmy2702Anims, gEmy2702Tiles, 0, { 0, 0, 0 } },
    { gEmy2701Frames, gEmy2701Anims, gEmy2701Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813DE7C[2] = {
    { gEmy2710Frames, gEmy2710Anims, gEmy2710Tiles, 0, { 0, 0, 0 } },
    { gEmy2711Frames, gEmy2711Anims, gEmy2711Tiles, 0, { 0, 0, 0 } },
};

const EmyDef gEmy27Def = { gEmy27Palette, gUnk_0813DE4C, 192, 130, 20, 20, 64, 32, 64, 10, 0, { 19, 125, 32, 12, 16, 100, 0 } };

TaskDesc gTaskDescEmy27 = { "task_emy_27", task_emy_27_0, task_emy_27_1, task_emy_27_2, task_emy_27_3, 0x184 };

const AnimDef gUnk_0813DED4[3] = {
    { gEmy2800Frames, gEmy2800Anims, gEmy2800Tiles, 0, { 0, 0, 0 } },
    { gEmy2802Frames, gEmy2802Anims, gEmy2802Tiles, 0, { 0, 0, 0 } },
    { gEmy2801Frames, gEmy2801Anims, gEmy2801Tiles, 1, { 0, 0, 0 } },
};

const AnimDef gUnk_0813DF04[4] = {
    { gEmy2810Frames, gEmy2810Anims, gEmy2810Tiles, 0, { 0, 0, 0 } },
    { gEmy2811Frames, gEmy2811Anims, gEmy2811Tiles, 0, { 0, 0, 0 } },
    { gEmy2801Frames, gEmy2801Anims, gEmy2801Tiles, 0, { 0, 0, 0 } },
    { gEmy2801Frames, gEmy2801Anims, gEmy2801Tiles, 2, { 0, 0, 0 } },
};

const EmyDef gEmy28Def = { gEmy28Palette, gUnk_0813DED4, 1024, 150, 4, 20, 40, 24, 16, 25, 0, { 20, 45, 48, 8, 16, 100, 4 } };

TaskDesc gTaskDescEmy28 = { "task_emy_28", task_emy_28_0, task_emy_28_1, task_emy_28_2, task_emy_28_3, 0x188 };

const AnimDef gUnk_0813DF7C[3] = {
    { gEmy2900Frames, gEmy2900Anims, gEmy2900Tiles, 0, { 0, 0, 0 } },
    { gEmy2902Frames, gEmy2902Anims, gEmy2902Tiles, 0, { 0, 0, 0 } },
    { gEmy2900Frames, gEmy2900Anims, gEmy2900Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813DFAC[2] = {
    { gEmy2910Frames, gEmy2910Anims, gEmy2910Tiles, 0, { 0, 0, 0 } },
    { gEmy2911Frames, gEmy2911Anims, gEmy2911Tiles, 0, { 0, 0, 0 } },
};

const EmyDef gEmy29Def = { gEmy29Palette, gUnk_0813DF7C, 192, 300, 20, 20, 64, 64, 32, 30, 0, { 21, 80, 56, 22, 32, 100, 4 } };

TaskDesc gTaskDescEmy29 = { "task_emy_29", task_emy_29_0, task_emy_29_1, task_emy_29_2, task_emy_29_3, 0x188 };

const AnimDef gUnk_0813E004[3] = {
    { gEmy3000Frames, gEmy3000Anims, gEmy3000Tiles, 0, { 0, 0, 0 } },
    { gEmy3002Frames, gEmy3002Anims, gEmy3002Tiles, 0, { 0, 0, 0 } },
    { gEmy3001Frames, gEmy3001Anims, gEmy3001Tiles, 1, { 0, 0, 0 } },
};

const AnimDef gUnk_0813E034[8] = {
    { gEmy3001Frames, gEmy3001Anims, gEmy3001Tiles, 0, { 0, 0, 0 } },
    { gEmy3001Frames, gEmy3001Anims, gEmy3001Tiles, 2, { 0, 0, 0 } },
    { gEmy3010Frames, gEmy3010Anims, gEmy3010Tiles, 0, { 0, 0, 0 } },
    { gEmy3010Frames, gEmy3010Anims, gEmy3010Tiles, 1, { 0, 0, 0 } },
    { gEmy3010Frames, gEmy3010Anims, gEmy3010Tiles, 2, { 0, 0, 0 } },
    { gEmy3011Frames, gEmy3011Anims, gEmy3011Tiles, 0, { 0, 0, 0 } },
    { gEmy3011Frames, gEmy3011Anims, gEmy3011Tiles, 1, { 0, 0, 0 } },
    { gEmy3011Frames, gEmy3011Anims, gEmy3011Tiles, 2, { 0, 0, 0 } },
};

const EmyDef gEmy30Def = { gEmy30Palette, gUnk_0813E004, 1024, 150, 4, 20, 60, 32, 32, 30, 0, { 22, 45, 34, 30, 16, 100, 4 } };

TaskDesc gTaskDescEmy30 = { "task_emy_30", task_emy_30_0, task_emy_30_1, task_emy_30_2, task_emy_30_3, 0x184 };

const AnimDef gUnk_0813E0EC[3] = {
    { gEmy3100Frames, gEmy3100Anims, gEmy3100Tiles, 0, { 0, 0, 0 } },
    { gEmy3104Frames, gEmy3104Anims, gEmy3104Tiles, 0, { 0, 0, 0 } },
    { gEmy3100Frames, gEmy3100Anims, gEmy3100Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813E11C[3] = {
    { gEmy3105Frames, gEmy3105Anims, gEmy3105Tiles, 0, { 0, 0, 0 } },
    { gEmy3106Frames, gEmy3106Anims, gEmy3106Tiles, 0, { 0, 0, 0 } },
    { gEmy3107Frames, gEmy3107Anims, gEmy3107Tiles, 0, { 0, 0, 0 } },
};

const EmyDef gEmy31Def = { gEmy31Palette, gUnk_0813E0EC, 256, 100, 10, 20, 64, 32, 32, 10, 0, { 23, 95, 32, 12, 24, 100, 0 } };

TaskDesc gTaskDescEmy31 = { "task_emy_31", task_emy_31_0, task_emy_31_1, task_emy_31_2, task_emy_31_3, 0x194 };

const AnimDef gUnk_0813E184[3] = {
    { gEmy3700Frames, gEmy3700Anims, gEmy3700Tiles, 0, { 0, 0, 0 } },
    { gEmy3702Frames, gEmy3702Anims, gEmy3702Tiles, 0, { 0, 0, 0 } },
    { gEmy3701Frames, gEmy3701Anims, gEmy3701Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813E1B4[11] = {
    { gEmy3710Frames, gEmy3710Anims, gEmy3710Tiles, 0, { 0, 0, 0 } },
    { gEmy3711Frames, gEmy3711Anims, gEmy3711Tiles, 0, { 0, 0, 0 } },
    { gEmy3711Frames, gEmy3711Anims, gEmy3711Tiles, 1, { 0, 0, 0 } },
    { gEmy3711Frames, gEmy3711Anims, gEmy3711Tiles, 2, { 0, 0, 0 } },
    { gEmy3711Frames, gEmy3711Anims, gEmy3711Tiles, 3, { 0, 0, 0 } },
    { gEmy3720Frames, gEmy3720Anims, gEmy3720Tiles, 0, { 0, 0, 0 } },
    { gEmy3720Frames, gEmy3720Anims, gEmy3720Tiles, 1, { 0, 0, 0 } },
    { gEmy3720Frames, gEmy3720Anims, gEmy3720Tiles, 2, { 0, 0, 0 } },
    { gEmy3720Frames, gEmy3720Anims, gEmy3720Tiles, 3, { 0, 0, 0 } },
    { gEmy3721Frames, gEmy3721Anims, gEmy3721Tiles, 0, { 0, 0, 0 } },
    { gEmy3721Frames, gEmy3721Anims, gEmy3721Tiles, 1, { 0, 0, 0 } },
};

const EmyDef gEmy37Def = { gEmy37Palette, gUnk_0813E184, 409, 130, 20, 20, 64, 32, 32, 10, 3, { 24, 110, 38, 12, 20, 100, 0 } };

TaskDesc gTaskDescEmy37 = { "task_emy_37", task_emy_37_0, task_emy_37_1, task_emy_37_2, task_emy_37_3, 0x190 };

const AnimDef gUnk_0813E29C[3] = {
    { gEmy3800Frames, gEmy3800Anims, gEmy3800Tiles, 0, { 0, 0, 0 } },
    { gEmy3802Frames, gEmy3802Anims, gEmy3802Tiles, 0, { 0, 0, 0 } },
    { gEmy3801Frames, gEmy3801Anims, gEmy3801Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813E2CC[2] = {
    { gEmy3811Frames, gEmy3811Anims, gEmy3811Tiles, 0, { 0, 0, 0 } },
    { gEmy3810Frames, gEmy3810Anims, gEmy3810Tiles, 0, { 0, 0, 0 } },
};

const EmyDef gEmy38Def = { gEmy38Palette, gUnk_0813E29C, 76, 130, 80, 22, 64, 32, 32, 10, 0, { 25, 112, 56, 25, 32, 100, 4 } };

TaskDesc gTaskDescEmy38 = { "task_emy_38", task_emy_38_0, task_emy_38_1, task_emy_38_2, task_emy_38_3, 0x184 };

const AnimDef gUnk_0813E324[3] = {
    { gEmy3900Frames, gEmy3900Anims, gEmy3900Tiles, 0, { 0, 0, 0 } },
    { gEmy3902Frames, gEmy3902Anims, gEmy3902Tiles, 0, { 0, 0, 0 } },
    { gEmy3901Frames, gEmy3901Anims, gEmy3901Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813E354[2] = {
    { gEmy3910Frames, gEmy3910Anims, gEmy3910Tiles, 0, { 0, 0, 0 } },
    { gEmy3911Frames, gEmy3911Anims, gEmy3911Tiles, 0, { 0, 0, 0 } },
};

const EmyDef gEmy39Def = { gEmy39Palette, gUnk_0813E324, 102, 130, 100, 22, 64, 32, 32, 10, 0, { 26, 134, 56, 25, 32, 100, 4 } };

TaskDesc gTaskDescEmy39 = { "task_emy_39", task_emy_39_0, task_emy_39_1, task_emy_39_2, task_emy_39_3, 0x188 };

const AnimDef gUnk_0813E3AC[3] = {
    { gEmy4100Frames, gEmy4100Anims, gEmy4100Tiles, 0, { 0, 0, 0 } },
    { gEmy4102Frames, gEmy4102Anims, gEmy4102Tiles, 0, { 0, 0, 0 } },
    { gEmy4101Frames, gEmy4101Anims, gEmy4101Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813E3DC[2] = {
    { gEmy4110Frames, gEmy4110Anims, gEmy4110Tiles, 0, { 0, 0, 0 } },
    { gEmy4111Frames, gEmy4111Anims, gEmy4111Tiles, 0, { 0, 0, 0 } },
};

const EmyDef gEmy41Def = { gEmy41Palette, gUnk_0813E3AC, 192, 400, 50, 20, 64, 32, 32, 10, 0, { 27, 108, 56, 32, 20, 100, 4 } };

TaskDesc gTaskDescEmy41 = { "task_emy_41", task_emy_41_0, task_emy_41_1, task_emy_41_2, task_emy_41_3, 0x190 };

const AnimDef gUnk_0813E434[3] = {
    { gEmy4400Frames, gEmy4400Anims, gEmy4400Tiles, 0, { 0, 0, 0 } },
    { gEmy4402Frames, gEmy4402Anims, gEmy4402Tiles, 0, { 0, 0, 0 } },
    { gEmy4401Frames, gEmy4401Anims, gEmy4401Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813E464[2] = {
    { gEmy4410Frames, gEmy4410Anims, gEmy4410Tiles, 0, { 0, 0, 0 } },
    { gEmy4412Frames, gEmy4412Anims, gEmy4412Tiles, 0, { 0, 0, 0 } },
};

const EmyDef gEmy44Def = { gEmy44Palette, gUnk_0813E434, 192, 130, 90, 20, 60, 60, 16, 10, 0, { 28, 260, 48, 25, 32, 100, 4 } };

TaskDesc gTaskDescEmy44 = { "task_emy_44", task_emy_44_0, task_emy_44_1, task_emy_44_2, task_emy_44_3, 0x184 };

const AnimDef gUnk_0813E4BC[3] = {
    { gEmy8100Frames, gEmy8100Anims, gEmy8100Tiles, 0, { 0, 0, 0 } },
    { gEmy8102Frames, gEmy8102Anims, gEmy8102Tiles, 0, { 0, 0, 0 } },
    { gEmy8100Frames, gEmy8100Anims, gEmy8100Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813E4EC[5] = {
    { gEmy8110Frames, gEmy8110Anims, gEmy8110Tiles, 0, { 0, 0, 0 } },
    { gEmy8111Frames, gEmy8111Anims, gEmy8111Tiles, 0, { 0, 0, 0 } },
    { gEmy8105Frames, gEmy8105Anims, gEmy8105Tiles, 0, { 0, 0, 0 } },
    { gEmy8105Frames, gEmy8105Anims, gEmy8105Tiles, 1, { 0, 0, 0 } },
    { gEmy8105Frames, gEmy8105Anims, gEmy8105Tiles, 2, { 0, 0, 0 } },
};

const EmyDef gEmy81Def = { gEmy81Palette, gUnk_0813E4BC, 128, 130, 20, 15, 64, 32, 32, 10, 0, { 29, 66, 27, 13, 16, 100, 0 } };

TaskDesc gTaskDescEmy81 = { "task_emy_81", task_emy_81_0, task_emy_81_1, task_emy_81_2, task_emy_81_3, 0x194 };

const AnimDef gUnk_0813E574[3] = {
    { gEmy8200Frames, gEmy8200Anims, gEmy8200Tiles, 0, { 0, 0, 0 } },
    { gEmy8202Frames, gEmy8202Anims, gEmy8202Tiles, 0, { 0, 0, 0 } },
    { gEmy8201Frames, gEmy8201Anims, gEmy8201Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813E5A4[6] = {
    { gEmy8210jFrames, gEmy8210jAnims, gEmy8210jTiles, 0, { 0, 0, 0 } },
    { gEmy8210jFrames, gEmy8210jAnims, gEmy8210jTiles, 1, { 0, 0, 0 } },
    { gEmy8210jFrames, gEmy8210jAnims, gEmy8210jTiles, 2, { 0, 0, 0 } },
    { gEmy8210Frames, gEmy8210Anims, gEmy8210Tiles, 0, { 0, 0, 0 } },
    { gEmy8211Frames, gEmy8211Anims, gEmy8211Tiles, 0, { 0, 0, 0 } },
    { gEmy8212Frames, gEmy8212Anims, gEmy8212Tiles, 0, { 0, 0, 0 } },
};

const EmyDef gEmy82Def = { gEmy82Palette, gUnk_0813E574, 204, 3, 20, 20, 48, 32, 32, 1, 0, { 30, 66, 32, 10, 16, 100, 0 } };

TaskDesc gTaskDescEmy82 = { "task_emy_82", task_emy_82_0, task_emy_82_1, task_emy_82_2, task_emy_82_3, 0x188 };

const AnimDef gUnk_0813E63C[3] = {
    { gEmy8300Frames, gEmy8300Anims, gEmy8300Tiles, 0, { 0, 0, 0 } },
    { gEmy8302Frames, gEmy8302Anims, gEmy8302Tiles, 0, { 0, 0, 0 } },
    { gEmy8300Frames, gEmy8300Anims, gEmy8300Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813E66C[4] = {
    { gEmy8310Frames, gEmy8310Anims, gEmy8310Tiles, 0, { 0, 0, 0 } },
    { gEmy8311Frames, gEmy8311Anims, gEmy8311Tiles, 0, { 0, 0, 0 } },
    { gEmy8311Frames, gEmy8311Anims, gEmy8311Tiles, 1, { 0, 0, 0 } },
    { gEmy8311Frames, gEmy8311Anims, gEmy8311Tiles, 2, { 0, 0, 0 } },
};

const EmyDef gEmy83Def = { gEmy83Palette, gUnk_0813E63C, 192, 130, 20, 20, 50, 50, 50, 10, 0, { 31, 66, 35, 12, 24, 100, 0 } };

TaskDesc gTaskDescEmy83 = { "task_emy_83", task_emy_83_0, task_emy_83_1, task_emy_83_2, task_emy_83_3, 0x1A8 };

TaskDesc gTaskDescEmy83B = { "task_emy_83_b", task_emy_83_b_0, task_emy_83_b_1, task_emy_83_b_2, task_emy_83_b_3, 0x90 };

TaskDesc gTaskDescEmy83S = { "task_emy_83_s", task_emy_83_s_0, task_emy_83_s_1, task_emy_83_s_2, task_emy_83_s_3, 0x24 };

const AnimDef gUnk_0813E704[3] = {
    { gTrumpH00bFrames, gTrumpH00bAnims, gTrumpH00bTiles, 0, { 0, 0, 0 } },
    { gTrumpH02bFrames, gTrumpH02bAnims, gTrumpH02bTiles, 0, { 0, 0, 0 } },
    { gTrumpH03Frames, gTrumpH03Anims, gTrumpH03Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813E734 = { gTrumpH10Frames, gTrumpH10Anims, gTrumpH10Tiles, 0, { 0, 0, 0 } };

const EmyDef gEmyTrumpHDef = { gTrumpHPalette, gUnk_0813E704, 409, 130, 20, 20, 90, 32, 32, 10, 0, { 47, 200, 40, 16, 16, 100, 0 } };

TaskDesc gTaskDescEmyTrumpH = { "task_emy_trump_h", task_emy_trump_h_0, task_emy_trump_h_1, task_emy_trump_h_2, task_emy_trump_h_3, 0x184 };

const AnimDef gUnk_0813E784[3] = {
    { gTrumpS00bFrames, gTrumpS00bAnims, gTrumpS00bTiles, 0, { 0, 0, 0 } },
    { gTrumpS02bFrames, gTrumpS02bAnims, gTrumpS02bTiles, 0, { 0, 0, 0 } },
    { gTrumpS03Frames, gTrumpS03Anims, gTrumpS03Tiles, 0, { 0, 0, 0 } },
};

const AnimDef gUnk_0813E7B4 = { gTrumpS10Frames, gTrumpS10Anims, gTrumpS10Tiles, 0, { 0, 0, 0 } };

const EmyDef gEmyTrumpSDef = { gTrumpSPalette, gUnk_0813E784, 307, 130, 20, 20, 64, 32, 32, 10, 0, { 46, 200, 40, 16, 16, 100, 0 } };

TaskDesc gTaskDescEmyTrumpS = { "task_emy_trump_s", task_emy_trump_s_0, task_emy_trump_s_1, task_emy_trump_s_2, task_emy_trump_s_3, 0x184 };

const AnimDef gUnk_0813E804[3] = {
    { gUnk_09EE2608, gUnk_09EE2618, gUnk_08C69204, 0, { 0, 0, 0 } },
    { gUnk_09EE2608, gUnk_09EE2618, gUnk_08C69204, 0, { 0, 0, 0 } },
    { gUnk_09EE2608, gUnk_09EE2618, gUnk_08C69204, 0, { 0, 0, 0 } },
};

const EmyDef gEmyTestDef = { gUnk_08F6DD44, gUnk_0813E804, 0, 130, 20, 60, 64, 32, 32, 10, 0, { 28, 260, 16, 8, 16, 100, 0 } };

void task_emy_00_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy00Def, obj);
    work->flags |= 1;
    work->unk_150 = 0x12;
    work->unk_14C = 0x16;
}

u8 task_emy_00_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    u16 r;
    s32 pos;
    s32 pos2;
    u8 ret;

    w = work;
    act = &work->actor;

    if (_0800CBDC(work)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->unk_14C = 24;
            break;
        case 1:
            work->unk_14C = 25;
            break;
        }
    }

    switch (w->unk_14C) {
    case 24:
        AnimChangeWithDef(gUnk_0813D35C, &work->anim, 5, 0, work->tiles);
        func_0800C980(w, 31, 18, 11, 165, 40, SONG_BTL_MON_HIT00, 0, 0, 24);
        break;
    case 25:
        AnimChangeWithDef(gUnk_0813D35C, &work->anim, 6, 0, work->tiles);

        if (w->unk_154 == 10) {
            w->unk_168 = -0x400;
        }

        func_0800C980(w, 14, 35, 10, 166, 96, SONG_BTL_MON_HIT00, 0, 0, 24);
        break;
    case 19:
        AnimChangeWithDef(gUnk_0813D35C, &work->anim, 0, 0, work->tiles);

        if (AnimIsFinished(&w->anim)) {
            w->unk_14C = 20;
            ColliderSetDisabled(&act->collider, 1);
            act->flags |= 0x100;
            act->unk_0A2 = 0;
        }
        break;
    case 20:
        if (gBtlWork->flags & 0x40000) {
            func_0801C700(act, &pos, 0, 0);
            AnimChangeWithDef(gUnk_0813D35C, &work->anim, 1, 1, work->tiles);
            act->x += gSineTable[w->angle] * w->unk_164 >> 8;
            act->y += -gSineTable[w->angle + 64] * w->unk_164 >> 8;

            if (w->unk_154 > 100) {
                w->unk_14C = 21;
                ColliderSetDisabled(&act->collider, 0);
                act->flags &= ~0x100;
                act->unk_0A2 = 16;
                w->unk_154 = 0;
            } else {
                w->unk_154++;
            }

            if (act->x > pos) {
                act->flags |= 4;
            } else {
                act->flags &= ~4;
            }
        }
        break;
    case 22:
        AnimChangeWithDef(gUnk_0813D35C, &work->anim, 3, 0, work->tiles);

        if (w->unk_154 == 20) {
            act->flags &= ~0x100;

            if (gGameState.flags & 4) {
                func_0800CD40(w);
                break;
            }
        }

        if (AnimIsFinished(&w->anim)) {
            func_0800CD40(w);
            break;
        }

        w->unk_154++;
        break;
    case 21:
        AnimChangeWithDef(gUnk_0813D35C, &work->anim, 2, 0, work->tiles);

        if (w->unk_154 == 30) {
            act->flags &= ~0x100;
        }

        if (AnimIsFinished(&w->anim)) {
            act->flags &= ~0x300;
            w->unk_14C = 18;

#ifdef VERSION_EU
            w->unk_154 = 0;
#endif
        } else {
            w->unk_154++;
        }
        break;
    case 18:
        if (w->unk_154 == 0) {
            ColliderSetDisabled(&act->collider, 0);
            act->flags &= ~0x300;
            AnimChangeWithDef(work->def->animDef, &work->anim, 0, 3,
                work->tiles);
        }

        func_0801BCF8(act);

        if (GetRandom() % 120 == 0) {
            w->unk_14C = 4;

            if (GetRandom() % 2 == 0) {
                w->x = -((act->unk_0CE
                    + (-act->unk_0D0
                        + GetRandom() % (act->unk_0D0 - -act->unk_0D0 + 1)))
                    << 8);
            } else {
                w->x = (act->unk_0CE
                    + (-act->unk_0D0
                        + GetRandom() % (act->unk_0D0 - -act->unk_0D0 + 1)))
                    << 8;
            }
        } else if (GetRandom() % 200 == 0) {
            w->unk_14C = 19;
            act->flags |= 0x200;
            w->angle = GetRandom();
            w->unk_154 = 0;
            break;
        }

        if (GetRandom() % w->def->unk_0E == 0) {
            func_0801C700(act, &pos2, 0, 0);

            if (act->x > pos2) {
                act->flags |= 4;
            } else {
                act->flags &= ~4;
            }
        }

        w->unk_154++;
        break;
    }

    ret = _0800CDF0(w);

    if (w->unk_14C == 14) {
        AnimChangeWithDef(gUnk_0813D35C, &work->anim, 4, 1, work->tiles);
    }

    return ret;
}

void task_emy_00_2(EmyWork* work) {
    BtlObj* act;
    u16 pri;
    s32 affine;
    s32 rot;
    s32 scale;
    s32 zoom;
    s16 x;
    s16 y;

    if (work->unk_15A != 0) {
        act = &work->actor;
        pri = GetBattleSpritePriorityFlags(act->y) | work->unk_162;
        WorldToScreen(&x, &y, act->x, act->y, act->z);
        zoom = work->unk_180;

        if (zoom == 0x100) {
            if (act->flags & 4) {
                scale = gBtlWork->scale;
                rot = scale;
            } else if (gBtlWork->scale == zoom) {
                scale = zoom;
                rot = scale;
                pri |= 1;
            } else {
                rot = -gBtlWork->scale;
                scale = gBtlWork->scale;
            }
        } else {
            if (act->flags & 4) {
                rot = gBtlWork->scale * work->unk_17C >> 8;
                scale = gBtlWork->scale;
            } else {
                rot = -(gBtlWork->scale * work->unk_17C >> 8);
                scale = gBtlWork->scale;
            }

            scale = scale * zoom >> 8;
        }

        if (scale == 0x100 && rot == scale) {
            affine = 0;
        } else if (scale <= 0xFF) {
            affine = AllocObjAffine(0, rot, scale, 0);
        } else {
            affine = AllocObjAffine(0, rot, scale, 1);
        }

        if (func_0801CA00(act)) {
            DrawSprite(x, y, work->gfx, work->tiles, work->palette2, affine, pri,
                -0x1004 - (act->y >> 8) * 4);
        } else if (work->unk_14C == 0x14) {
            DrawSprite(x, y, work->gfx, work->tiles, work->palette, affine, pri, 0xFFFF);
        } else {
            DrawSprite(x, y, work->gfx, work->tiles, work->palette, affine, pri,
                -0x1004 - (act->y >> 8) * 4);
        }

        TaskPoolDraw(&work->tasks);
    }
}

void task_emy_00_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_01_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy01Def, obj);
    work->unk_150 = 7;
}

u8 task_emy_01_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    u16 r;
    s32 x;

    w = work;
    act = &work->actor;

    if (_0800CBDC(work)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->unk_14C = 0x12;
            break;
        case 1:
            work->unk_14C = 0x13;
            break;
        }
    }

    switch (work->unk_14C) {
    case 0x12: {
        s32 z;
        AnimChangeWithDef(gUnk_0813D434, &w->anim, 0, 0, w->tiles);
        work->unk_168 = 0;

        if (work->unk_154 != 0) {
            if (work->unk_154 == 0x16) {
                z = act->y;

                if (act->flags & 4) {
                    x = act->x - 0x6400;
                    func_08012E44(0, act->x - 0x2600, z, act->z - 0xC00, x, z, 0, 1,
                        0xA7);
                } else {
                    x = act->x + 0x6400;
                    func_08012E44(0, act->x + 0x2600, z, act->z - 0xC00, x, z, 0, 0,
                        0xA7);
                }
            }
        }

        if (work->unk_154 > 0x15 && !func_080128EC()) {
            func_0800CB4C(work);
        } else {
            work->unk_154++;
        }
        break;
    }
    case 0x13: {
        s32 z;
        AnimChangeWithDef(gUnk_0813D434, &w->anim, 1, 0, w->tiles);
        work->unk_168 = 0;

        if (work->unk_154 != 0) {
            if (work->unk_154 == 0x16) {
                z = act->y;

                if (act->flags & 4) {
                    x = act->x - 0x6400;
                    func_08012E44(1, act->x - 0x2600, z, act->z - 0xC00, x, z, 0, 1,
                        0xA8);
                } else {
                    x = act->x + 0x6400;
                    func_08012E44(1, act->x + 0x2600, z, act->z - 0xC00, x, z, 0, 0,
                        0xA8);
                }
            }
        }

        if (work->unk_154 > 0x15 && !func_080128EC()) {
            func_0800CB4C(work);
        } else {
            work->unk_154++;
        }
        break;
    }
    }

    return _0800CDF0(work);
}

void task_emy_01_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_01_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_02_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy02Def, obj);
    work->unk_150 = 7;
}

u8 task_emy_02_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    u16 r;
    s32 p;

    w = work;
    act = &work->actor;

    if (_0800CBDC(work)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->unk_14C = 0x12;
            break;
        case 1:
            work->unk_14C = 0x13;
            break;
        }
    }

    switch (work->unk_14C) {
    case 0x12: {
        s32 y;

        AnimChangeWithDef(gUnk_0813D4BC, &w->anim, 0, 0, w->tiles);
        work->unk_168 = 0;

        if (work->unk_154 == 0) {
        } else if (work->unk_154 == 22) {
            y = act->y;

            if (act->flags & 4) {
                p = act->x - 0x3C00;
                func_08013308(0, act->x - 0x2800, y, act->z - 0x800, p, y, 0, 1,
                    0xA9);
            } else {
                p = act->x + 0x3C00;
                func_08013308(0, act->x + 0x2800, y, act->z - 0x800, p, y, 0, 0,
                    0xA9);
            }
        }

        if (work->unk_154 > 21 && !func_080128EC()) {
            func_0800CB4C(work);
        } else {
            work->unk_154++;
        }
        break;
    }
    case 0x13: {
        s32 y;

        AnimChangeWithDef(gUnk_0813D4BC, &w->anim, 1, 0, w->tiles);
        work->unk_168 = 0;

        if (work->unk_154 == 0) {
        } else if (work->unk_154 == 3) {
            y = act->y;

            if (act->flags & 4) {
                p = act->x - 0x3C00;
                func_08013308(1, act->x - 0x2800, y, act->z - 0x800, p, y, 0, 1,
                    0xAA);
            } else {
                p = act->x + 0x3C00;
                func_08013308(1, act->x + 0x2800, y, act->z - 0x800, p, y, 0, 0,
                    0xAA);
            }
        }

        if (work->unk_154 > 2 && !func_080128EC()) {
            func_0800CB4C(work);
        } else {
            work->unk_154++;
        }
        break;
    }
    }

    return _0800CDF0(work);
}

void task_emy_02_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_02_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_03_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy03Def, obj);
    work->unk_150 = 7;
}

u8 task_emy_03_1(Emy03Work* work) {
    Emy03Work* w;
    BtlObj* act;
    u16 r;

    w = work;
    act = &work->base.actor;

    if (_0800CBDC(&work->base)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->base.unk_14C = 0x12;
            break;
        case 1:
            work->base.unk_14C = 0x13;
            break;
        }
    }

    switch (work->base.unk_14C) {
    case 0x12:
        if (work->base.unk_154 == 0) {
            work->base.unk_168 = -0x480;
            AnimChangeWithDef(gUnk_0813D544, &w->base.anim, 0, 0, w->base.tiles);
        } else if (work->base.unk_154 == 1) {
            func_080141FC(act);
            m4aSongNumStart(SONG_BTL_YELLOW_MOV);
        }

        if (func_0800C980(&work->base, 0x11, 0x17, 0x0A, 0xAB, 0x50, SONG_BTL_YELLOW_HIT, 0, 0, 0x0A) == 2) {
            BgAnimStop();
        }
        break;
    case 0x13:
        if (work->base.unk_154 == 0) {
            AnimChangeWithDef(gUnk_0813D544, &w->base.anim, 1, 0, w->base.tiles);
        } else if (work->base.unk_154 == 1) {
            func_0801C700(act, &w->unk_184, &w->unk_188, 0);
            w->unk_18C = 0;
            func_08015834(0, act->x, act->y, act->z - 0x1000, w->unk_184,
                w->unk_188, 0, 0xAC);
        }

        work->base.unk_168 = 0;

        if (AnimIsFinished(&work->base.anim) && !func_080128EC()) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_03_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_03_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_04_0(Emy04Work* work, void* obj) {
    func_0800C778(&work->base, &gEmy04Def, obj);
    work->base.unk_150 = 7;
    work->unk_184 = 0;
    work->unk_186 = 0;
}

u8 task_emy_04_1(Emy04Work* work) {
    Emy04Work* w;
    BtlObj* act;
    BtlObj* p;
    BtlObj* best;
    s16 bestv;

    w = work;
    act = &work->base.actor;

    if (_0800CBDC(&work->base)) {
        work->base.unk_14C = 0x12;
    }

    switch (work->base.unk_14C) {
    case 0x12:
        AnimChangeWithDef(&gUnk_0813D5CC, &work->base.anim, 0, 0, work->base.tiles);
        work->base.unk_168 = 0;

        if (work->unk_186 > 2) {
            func_08019190(act, 2);
            func_0800CB4C(&work->base);
            break;
        }

        if (work->base.unk_154 == 3) {
            best = 0;
            bestv = 0;

            for (p = ListPoolFirst(&gBtlWork->pool); p != 0;
                    p = ListPoolNext(&p->node)) {
                if (!(p->flags & 0x100)) {
                    if (bestv < p->unk_02E - p->unk_02C) {
                        bestv = p->unk_02E - p->unk_02C;
                        best = p;
                    }
                }
            }

            if (best == 0) {
                best = act;
            }

            if (best->unk_02C == best->unk_02E) {
                func_08019190(act, 2);
                func_0800CB4C(&work->base);
                break;
            }

            best->flags |= 0x20;
            best->unk_020 = -0x1E;
            func_08012AAC(0, best->x, best->y, best->z);
            w->unk_186++;
        }

        if (work->base.unk_154 > 0x0D) {
            if (!func_080128EC()) {
                func_0800CB4C(&work->base);
            }
        } else {
            work->base.unk_154++;
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_04_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_04_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_06_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy06Def, obj);
    work->unk_150 = 7;
}

u8 task_emy_06_1(Emy06Work* work) {
    Emy06Work* w;
    BtlObj* act;
    s32* p;
    u16 s;
    u16 m;
    s32 pos;
    s32 d;
    s32 t;
    s32 v;
    s32 e;
    s32 tx;
    s32 ty;

    w = work;
    act = &work->base.actor;

    if (_0800CBDC(&work->base)) {
        func_0801C700(act, 0, &pos, 0);
        d = act->y - pos;

        if (d >= 0 ? d <= 0xFFF : pos - act->y <= 0xFFF) {
            work->base.unk_14C = 0x13;
        } else {
            work->base.unk_14C = 0x12;
        }

        w->unk_184 = 0;
    }

    switch (work->base.unk_14C) {
    case 0x12:
        AnimChangeWithDef(gUnk_0813D644, &w->base.anim, 0, 0, w->base.tiles);
        work->base.unk_168 = 0;
        p = &gBtlWork->unk_138;
        t = act->z + 0xC00;
        act->z += (*p - t) >> 4;
        s = AnimGetFrame(&work->base.anim);

        if (s >= 5 && s <= 20) {
            m = work->base.unk_154;
            m &= 3;

            if (m == 0) {
                func_0801C700(act, &tx, &ty, 0);
                work->base.angle = GetAngle(act->x, act->y, tx, ty);
            }

            act->x += gSineTable[work->base.angle] * 2;
            act->y -= gSineTable[work->base.angle + 0x40] * 2;

            if (func_08011F78(0xAF, act->x, act->y, act->z - 0x800, 0x14, 0x14,
                    8)) {
                m4aSongNumStart(SONG_BTL_MON_HIT04);
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    case 0x13:
        AnimChangeWithDef(gUnk_0813D644, &w->base.anim, 1, 0, w->base.tiles);
        work->base.unk_168 = 0;
        p = &gBtlWork->unk_138;
        t = act->z + 0xC00;
        act->z += (*p - t) >> 4;
        s = AnimGetFrame(&work->base.anim);

        if (s >= 6 && s <= 16) {
            if (act->flags & 4) {
                v = act->x;
                v += 0x7800;
            } else {
                v = act->x;
                v -= 0x7800;
            }

            e = (act->unk_014 - v) >> 3;
            w->unk_184 += 0x33;

            if (e > w->unk_184) {
                e = w->unk_184;
            } else if (e < -w->unk_184) {
                e = -w->unk_184;
            }

            act->x += e;

            if (func_08011F78(0xB0, act->x, act->y, act->z - 0x800, 0x10, 0x10,
                    8)) {
                m4aSongNumStart(SONG_BTL_MON_HIT00);
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_06_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_06_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_07_0(Emy07Work* work, void* obj) {
    func_0800C778(&work->base, &gEmy07Def, obj);
    work->unk_184 = 0;
    work->unk_186 = 0;
    work->base.unk_150 = 0x12;
    work->base.actor.flags |= 0x1000;
    work->unk_187 = 0;
}

u8 task_emy_07_1(Emy07Work* work) {
    Emy07Work* w;
    BtlObj* act;
    EmySpawn spawn;
    u32 state;
    s32 pos;
    s32 pos2;

    w = work;
    act = &work->base.actor;
    state = work->base.unk_14C;

#ifdef VERSION_EU
    act->unk_02C = 0x7FFF;
#endif

    _0800CBDC(&work->base);

#ifdef VERSION_EU
    act->unk_02C = act->unk_02E;
#endif

    switch (work->base.unk_14C) {
    case 1:
    case 3:
    case 15:
        work->base.unk_14C = 26;

        switch (state) {
        case 21:
            w->unk_186 = 0;

            if (act->unk_024 & 0x10000000) {
                func_0801AF08(act);
                work->base.unk_14C = 20;
                work->base.unk_154 = 0;
            }
            break;
        case 22:
            w->unk_186 = 0;

            if (act->unk_024 & 0x20000000) {
                func_0801AF08(act);
                work->base.unk_14C = 20;
                work->base.unk_154 = 0;
            }
            break;
        case 23:
            w->unk_186 = 1;

            if (act->unk_024 & 0x40000000) {
                func_0801AF08(act);
                work->base.unk_14C = 20;
                work->base.unk_154 = 0;
            }
            break;
        }

        act->unk_02C = act->unk_02E;
        ColliderSetDisabled(&act->collider, 0);
        break;
    }

    switch (work->base.unk_14C) {
    case 18:
        AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 0, 3,
            w->base.tiles);
        func_0801C700(act, &pos, 0, 0);

        if (act->x < pos) {
            act->flags &= ~4;
        } else {
            act->flags |= 4;
        }

        if (GetRandom() % 60 == 0) {
            work->base.unk_154 = 0;

            switch (GetRandom() % 3) {
            case 1:
                work->base.unk_14C = 22;
                break;
            case 2:
                work->base.unk_14C = 23;
                break;
            case 0:
            default:
                work->base.unk_14C = 21;
                break;
            }
        } else {
            work->base.unk_154++;
        }
        break;
    case 21:
        AnimChangeWithDef(gUnk_0813D6CC, &w->base.anim, 3, 1, w->base.tiles);

        if (work->base.unk_154 > 300) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 18;
        } else {
            work->base.unk_154++;
        }
        break;
    case 22:
        AnimChangeWithDef(gUnk_0813D6CC, &w->base.anim, 4, 1, w->base.tiles);

        if (work->base.unk_154 > 300) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 18;
        } else {
            work->base.unk_154++;
        }
        break;
    case 23:
        AnimChangeWithDef(gUnk_0813D6CC, &w->base.anim, 5, 1, w->base.tiles);

        if (work->base.unk_154 > 300) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 18;
        } else {
            work->base.unk_154++;
        }
        break;
    case 20:
        if (w->unk_186 != 0) {
            AnimChangeWithDef(gUnk_0813D6CC, &w->base.anim, 2, 0, w->base.tiles);
        } else {
            AnimChangeWithDef(gUnk_0813D6CC, &w->base.anim, 1, 0, w->base.tiles);
        }

        if (work->base.unk_154 == 0) {
            m4aSongNumStart(SONG_BTL_WM_OK);
            work->base.unk_154 = 1;
            act->flags |= 0x100;
        }

        if (w->unk_184 == 2 && gFrameCounter % 10 == 0) {
            spawn.unk_12 = 1;
            spawn.unk_14 = 0;
            spawn.x = act->x;
            spawn.y = act->y;
            spawn.z = act->z - (act->unk_09C << 8);
            TaskCreate(&gBtlWork->taskPools[0], &gTaskDescBtlPrize,
                &spawn);
        }

        if (AnimIsFinished(&work->base.anim)) {
            w->unk_184++;

            if (w->unk_184 > 2) {
                work->base.unk_154 = 0;
                work->base.unk_14C = 25;
                w->unk_187 = 1;
                func_0800FDD0(110);
            } else {
                work->base.unk_154 = 0;
                work->base.unk_14C = 18;
                act->flags &= ~0x100;
            }
        }
        break;
    case 26:
        if (work->base.unk_154 == 0) {
            AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 1, 0,
                w->base.tiles);
        }

        func_0801C700(act, &pos2, 0, 0);

        if (act->x < pos2) {
            act->flags &= ~4;
        } else {
            act->flags |= 4;
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0801AF08(act);
            act->flags |= 0x100;
            work->base.unk_154 = 0;
            work->base.unk_14C = 19;
        } else {
            work->base.unk_154++;
        }
        break;
    case 19:
        AnimChangeWithDef(gUnk_0813D6CC, &w->base.anim, 0, 0, w->base.tiles);

        if (work->base.unk_154 == 0) {
            act->flags |= 0x100;
            work->base.unk_154 = 1;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 25;
        }
        break;
    case 25:
        AnimChangeWithDef(gUnk_0813D6CC, &w->base.anim, 6, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            if (w->unk_187 != 0) {
                func_0801B994(act);
                func_0801BBF0(act);
            }

            return 0;
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_07_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_07_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_08_0(Emy08Work* work, void* obj) {
    func_0800C778(&work->base, &gEmy08Def, obj);
    work->palette = LoadObjPalette(gEmy07mPalette, 0x20);
    work->unk_188 = work->base.palette;
    work->flags = 0;
}

u8 task_emy_08_1(Emy08Work* work) {
    Emy08Work* w;
    BtlObj* act;
    u16 r;
    s32 dx;
    s32 dy;

    w = work;
    act = &work->base.actor;

    if (_0800CBDC(&work->base)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->base.unk_14C = 0x12;
            break;
        case 1:
            work->base.unk_14C = 0x13;
            break;
        }
    }

    switch (work->base.unk_14C) {
    case 0:
        if (GetRandom() % 100 == 0) {
            if (w->flags & 2) {
                work->base.unk_14C = 23;
            } else {
                work->base.unk_14C = 22;
            }

            work->base.unk_154 = 0;
        }
        break;
    case 22:
        AnimChangeWithDef(gUnk_0813D7A4, &w->base.anim, 4, 0, w->base.tiles);

        if (AnimGetFrame(&work->base.anim) == 6) {
            act->flags |= 0x180000000;
            w->flags |= 2;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = work->base.unk_150;
        }
        break;
    case 23:
        AnimChangeWithDef(gUnk_0813D7A4, &w->base.anim, 5, 0, w->base.tiles);

        if (AnimGetFrame(&work->base.anim) == 4) {
            act->flags &= ~0x180000000;
            w->flags &= ~2;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = work->base.unk_150;
        }
        break;
    case 18:
        AnimChangeWithDef(gUnk_0813D7A4, &w->base.anim, 0, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
            act->flags |= 0x200;

            if (w->flags & 1) {
                work->base.unk_14C = 20;
            } else {
                work->base.unk_14C = 21;
            }
        } else if (work->base.anim.timer == 0) {
            dx = 0;
            dy = 0;

            switch (work->base.anim.frame) {
            case 1:
                dx = 2;
                break;
            case 2:
                dx = 2;
                dy = 1;
                break;
            case 3:
                dx = 2;
                dy = 1;
                break;
            case 4:
                dx = 2;
                dy = 1;
                break;
            case 5:
                dx = 3;
                dy = 1;
                break;
            case 6:
                dx = 3;
                break;
            case 7:
                dx = 2;

                if ((act->flags & 4)
                        ? func_08011F78(0xB1, act->x - 0x1400, act->y, act->z,
                            4, 4, 0x20)
                        : func_08011F78(0xB1, act->x + 0x1400, act->y, act->z,
                            4, 4, 0x20)) {
                    m4aSongNumStart(SONG_BTL_HANE_HIT);
                    w->flags |= 1;
                } else {
                    w->flags &= ~1;
                }
                break;
            }

            if (act->flags & 4) {
                act->x -= dx << 8;
            } else {
                act->x += dx << 8;
            }

            act->y -= dy << 8;
        }
        break;
    case 20:
        AnimChangeWithDef(gUnk_0813D7A4, &w->base.anim, 2, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = work->base.unk_150;
            act->flags &= ~0x200;
        } else {
            work->base.unk_154++;
        }
        break;
    case 21:
        AnimChangeWithDef(gUnk_0813D7A4, &w->base.anim, 3, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = work->base.unk_150;
            act->flags &= ~0x200;
        } else {
            work->base.unk_154++;
        }
        break;
    case 19:
        AnimChangeWithDef(gUnk_0813D7A4, &w->base.anim, 1, 0, w->base.tiles);

        if (work->base.anim.timer == 0
                && AnimGetFrame(&work->base.anim) == 7) {
            if (act->flags & 4) {
                func_080150D8(act->x, act->y, act->z - 0xA00, 1);
            } else {
                func_080150D8(act->x, act->y, act->z - 0xA00, 0);
            }
        }

        if (work->base.unk_154 == 60) {
            (act->flags & 4)
                ? func_08011F78(0xB2, act->x, act->y, act->z, 0x20, 0x20, 0x20)
                : func_08011F78(0xB2, act->x, act->y, act->z, 0x20, 0x20, 0x20);
        }

        if (AnimIsFinished(&work->base.anim) && !func_080128EC()) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_08_2(Emy08Work* work) {
    work->base.palette = (work->flags & 2) ? work->palette : work->unk_188;
    func_0800DF30(&work->base);
    work->base.palette = work->unk_188;
}

void task_emy_08_3(Emy08Work* work) {
    func_0800E0D0(&work->base);
    ReleaseObjPalette(work->palette);
}

void task_emy_14_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy14Def, obj);
}

u8 task_emy_14_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    s32 pos;
    s32 d;

    w = work;
    act = &work->actor;

    if (_0800CBDC(work)) {
        func_0801C700(act, &pos, 0, 0);
        d = act->x - pos;

        if (d >= 0 ? d <= 0x31FF : pos - act->x <= 0x31FF) {
            work->unk_14C = 0x12;
        } else {
            work->unk_14C = 0x13;
        }
    }

    switch (work->unk_14C) {
    case 0x12:
        AnimChangeWithDef(gUnk_0813D86C, &w->anim, 0, 0, w->tiles);
        func_0800C980(work, 0x0F, 0x0E, 0x14, 0xB3, 0x18, SONG_BTL_HANE_HIT, 0, 0, 0x16);
        break;
    case 0x13:
        AnimChangeWithDef(gUnk_0813D86C, &w->anim, 1, 0, w->tiles);
        func_0800C980(work, 0x14, 0x25, 0x06, 0xB4, 0x64, SONG_BTL_MON_HIT02, 0, 0, 0x14);
        break;
    }

    return _0800CDF0(work);
}

void task_emy_14_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_14_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_15_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy15Def, obj);
}

u8 task_emy_15_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    u16 r;

    w = work;
    act = &work->actor;

    if (_0800CBDC(work)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->unk_14C = 0x12;
            break;
        case 1:
            work->unk_14C = 0x15;
            break;
        }
    }

    switch (work->unk_14C) {
    case 0x12:
        AnimChangeWithDef(gUnk_0813D8F4, &w->anim, 0, 0, w->tiles);

        if (AnimIsFinished(&work->anim)) {
            work->unk_14C = 0x13;
            work->unk_154 = 0x1E;
        }
        break;
    case 0x13:
        AnimChangeWithDef(gUnk_0813D8F4, &w->anim, 1, 0, w->tiles);

        if (act->flags & 4) {
            ApproachValueHalfSteps(&act->x, act->unk_014 - 0x5000, work->unk_154);
        } else {
            ApproachValueHalfSteps(&act->x, act->unk_014 + 0x5000, work->unk_154);
        }

        work->unk_154--;

        if ((act->flags & 4)
                ? func_08011F78(0xB5, act->x - 0x1400, act->y, act->z, 5, 5, 4)
                : func_08011F78(0xB5, act->x + 0x1400, act->y, act->z, 5, 5, 4)) {
            m4aSongNumStart(SONG_BTL_HANE_HIT);
        }

        if (work->unk_154 <= 0) {
            work->unk_14C = 0x14;
            work->unk_154 = 0;
        }
        break;
    case 0x14:
        AnimChangeWithDef(gUnk_0813D8F4, &w->anim, 2, 0, w->tiles);

        if (AnimIsFinished(&work->anim)) {
            func_0800CB4C(work);
        }
        break;
    case 0x15:
        if (work->unk_154 == 0) {
            AnimChangeWithDef(gUnk_0813D8F4, &w->anim, 3, 0, w->tiles);
            work->unk_168 = -0x533;
        }

        if (work->unk_154 > 5) {
            work->unk_14C = 0x16;
            work->unk_154 = 0;
        } else {
            work->unk_154++;
        }
        break;
    case 0x16:
        AnimChangeWithDef(gUnk_0813D8F4, &w->anim, 4, 0, w->tiles);
        func_0800C980(work, 0x16, 0x16, 0x3C, 0xB6, 0x40, SONG_BTL_MON_HIT02, 0x10, -0x0C, 0x0C);
        break;
    }

    return _0800CDF0(work);
}

void task_emy_15_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_15_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_16_0(Emy16Work* work, void* obj) {
    func_0800C778(&work->base, &gEmy16Def, obj);
    work->unk_184 = 0;
    work->unk_188 = 0;
    TaskPoolInit(&work->tasks, 2);
}

u8 task_emy_16_1(Emy16Work* work) {
    Emy16Work* w;
    BtlObj* act;
    EmySpawn spawn;
    u16 r;

    w = work;
    act = &work->base.actor;

    if (_0800CBDC(&work->base)) {
        if (IsTaskActiveNamed(work->unk_188, gTaskDescEmy16B.name)) {
            work->base.unk_14C = 0x12;
        } else {
            r = GetRandom();

            switch (r & 1) {
            case 0:
                work->base.unk_14C = 0x12;
                break;
            case 1:
                work->base.unk_14C = 0x13;
                break;
            }
        }

        w->unk_1A0 = 0;
    }

    switch (work->base.unk_14C) {
    case 0x12:
        AnimChangeWithDef(gUnk_0813D9AC, &w->base.anim, 0, 0, w->base.tiles);

        if (AnimGetFrame(&work->base.anim) == 3 && work->base.anim.timer == 0) {
            if (act->flags & 4) {
                spawn.x = act->x - 0x1000;
                spawn.y = act->y;
                spawn.z = act->z - 0x1000;
                spawn.unk_12 = 1;
            } else {
                spawn.x = act->x + 0x1000;
                spawn.y = act->y;
                spawn.z = act->z - 0x1000;
                spawn.unk_12 = 0;
            }

            w->unk_184 = TaskCreate(&w->tasks, &gTaskDescEmy16P, &spawn);
            w->unk_1A0 = 1;
        }

        if (w->unk_1A0 != 0) {
            if (!IsTaskActiveNamed(w->unk_184, gTaskDescEmy16P.name)) {
                func_0800CB4C(&work->base);
            }
        }
        break;
    case 0x13:
        AnimChangeWithDef(gUnk_0813D9AC, &w->base.anim, 1, 0, w->base.tiles);

        if (AnimGetFrame(&work->base.anim) == 0x0A && work->base.anim.timer == 0) {
            if (act->flags & 4) {
                spawn.x = act->x - 0xC00;
                spawn.y = act->y;
                spawn.z = act->z - 0x200;
                spawn.unk_12 = 1;
            } else {
                spawn.x = act->x + 0xC00;
                spawn.y = act->y;
                spawn.z = act->z - 0x200;
                spawn.unk_12 = 0;
            }

            w->unk_188 = TaskCreate(&w->tasks, &gTaskDescEmy16B, &spawn);
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
        }
        break;
    }

    TaskPoolUpdate(&w->tasks);
    return _0800CDF0(&work->base);
}

void task_emy_16_2(Emy16Work* work) {
    func_0800DF30(&work->base);
    TaskPoolDraw(&work->tasks);
}

void task_emy_16_3(Emy16Work* work) {
    func_0800E0D0(&work->base);
    TaskPoolDestroy(&work->tasks);
}

void task_emy_16_b_0(Emy16bWork* work, EmySpawn* spawn) {
    if (spawn->unk_12 != 0) {
        work->unk_02C = 1;
    } else {
        work->unk_02C = 0;
    }

    work->palette = LoadObjPalette(gEmy16Palette, 0x20);
    work->tiles = AllocObjTiles(0x80, gEmy1611bTiles);
    AnimInit(work->anim, gEmy1611bAnims, gEmy1611bFrames);
    AnimStart(work->anim, 0, 1);
    work->state = 0;
    work->x = spawn->x;
    work->y = spawn->y;
    work->z = spawn->z;
    work->vx = 0x200;
    work->vz = -0x34C;
    work->unk_03C = 0;
    work->unk_09C = 1;
    work->unk_09D = 0;
    ColliderInit(&work->collider, 0x0C, 4, 3);
    ColliderSetDisabled(&work->collider, 1);
}

u8 task_emy_16_b_1(Emy16bWork* work) {
    switch (work->state) {
    case 0:
        if (work->unk_02C != 0) {
            work->x -= work->vx;
        } else {
            work->x += work->vx;
        }

        if (ClampBattlePosition(&work->x, &work->y, -0x10, 0) != 0) {
            work->vx = -work->vx;
        }

        if (work->unk_09D == 0
                && func_08011E3C(work->x, work->y, work->z, 4, 4, 4)) {
            work->vx = -(work->vx >> 1);
            work->unk_09D = 1;
        }

        if (work->z >= 0) {
            work->state = 1;
            work->unk_03C = 0;
        }
        break;
    case 1:
        if (work->unk_03C == 0) {
            ColliderSetDisabled(&work->collider, 0);
            AnimStart(work->anim, 1, 1);
        }

        if (work->unk_06C != 0) {
            work->unk_03C = 0;
            work->state = 2;
            ColliderSetDisabled(&work->collider, 1);
        } else if (work->unk_03C > 0x64) {
            work->unk_03C = 0;
            work->state = 3;
        } else {
            work->unk_03C++;
        }
        break;
    case 2:
        if (work->unk_03C != 0) {
            if (work->z >= 0) {
                work->unk_03C = 0;
                work->state = 3;
                break;
            }
        } else {
            AnimStart(work->anim, 2, 1);
            work->vz = -0x3CC;
        }

        work->unk_03C++;
        break;
    case 3:
        if ((work->unk_03C & 3) == 0) {
            work->unk_09C = work->unk_09C == 0;
        }

        if (work->unk_06C != 0) {
            work->unk_03C = 0;
            work->state = 2;
            ColliderSetDisabled(&work->collider, 1);
            work->unk_09C = 1;
        } else if (work->unk_03C > 0x3C) {
            return 0;
        } else {
            work->unk_03C++;
        }
        break;
    }

    work->z += work->vz;
    work->vz += 0x33;

    if (work->z >= 0) {
        work->vz = 0;
        work->z = 0;
    }

    ColliderSetPosition(&work->collider, work->x, work->y, work->z);
    AnimUpdate(work->anim);
    return 1;
}

void task_emy_16_b_2(Emy16bWork* work) {
    void* gfx;
    u16 pri;
    s32 affine;
    s32 angle;
    s16 x;
    s16 y;

    gfx = AnimGetGfx(work->anim);

    if (work->unk_09C != 0) {
        pri = GetBattleSpritePriorityFlags(work->y);
        WorldToScreen(&x, &y, work->x, work->y, work->z);
        angle = gBtlWork->scale;

        if (angle == 0x100) {
            affine = 0;

            if (work->unk_02C == 0) {
                pri |= 1;
            }
        } else if (work->unk_02C == 0) {
            affine = AllocObjAffine(0, -angle, angle, 1);
        } else {
            affine = AllocObjAffine(0, angle, angle, 1);
        }

        DrawSprite(x, y, gfx, work->tiles, work->palette, affine, pri,
            -0x1004 - (work->y >> 8) * 4);
    }
}

void task_emy_16_b_3(Emy16bWork* work) {
    ColliderUnregister(&work->collider);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_emy_16_p_0(Emy16pWork* work, EmySpawn* spawn) {
    if (spawn->unk_12 != 0) {
        work->unk_02C = 1;
    } else {
        work->unk_02C = 0;
    }

    work->palette = LoadObjPalette(gEmy16Palette, 0x20);
    work->tiles = AllocObjTiles(0x80, gEmy1610bTiles);
    AnimInit(work->anim, gEmy1610bAnims, gEmy1610bFrames);
    AnimStart(work->anim, 0, 1);
    work->x = spawn->x;
    work->y = spawn->y;
    work->z = spawn->z;
    work->vz = 0;
}

u8 task_emy_16_p_1(Emy16pWork* work) {
    if ((gBtlWork->flags & 0x40) == 0) {
        return 0;
    }

    if (work->unk_02C != 0) {
        work->x -= 0x400;
    } else {
        work->x += 0x400;
    }

    if (func_08011F78(0xB7, work->x, work->y, work->z, 4, 4, 4) != 0) {
        m4aSongNumStart(SONG_BTL_BW_PACHIN);
    }

    if (ClampBattlePosition(&work->x, &work->y, 0x10, 0) != 0) {
        return 0;
    }

    work->z += work->vz;
    work->vz += 0x2E;

    if (work->z >= 0) {
        work->vz = -0x400;
        work->z = 0;
    }

    AnimUpdate(work->anim);
    return 1;
}

void task_emy_16_p_2(Emy16pWork* work) {
    void* gfx;
    u16 pri;
    s16 x;
    s16 y;

    gfx = AnimGetGfx(work->anim);
    pri = GetBattleSpritePriorityFlags(work->y);
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, 0, pri,
        -0x1004 - ((work->y + 0x1000) >> 8) * 4);
}

void task_emy_16_p_3(Emy16pWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_emy_18_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy18Def, obj);
    work->actor.z = (GetRandom() % 0x1001) - 0x3000;
    work->unk_150 = 7;
}

u8 task_emy_18_1(Emy18Work* work) {
    Emy18Work* w;
    BtlObj* act;
    u16 r;

    w = work;
    act = &work->base.actor;

    if (_0800CBDC(&work->base)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->base.unk_14C = 18;
            break;
        case 1:
            work->base.unk_14C = 19;
            break;
        }

        w->unk_184 = 0xEFFF;
    }

    if (work->base.unk_14C == 8) {
        work->base.unk_14C = 20;
        work->base.unk_154 = 0;
    }

    switch (work->base.unk_14C) {
    case 20:
        AnimChangeWithDef(gUnk_0813DA54, &w->base.anim, 2, 0, w->base.tiles);
        work->base.unk_168 = 0;

        if (AnimGetFrame(&work->base.anim) == 5) {
            work->base.angle = GetAngle(act->x, act->y, work->base.x,
                work->base.y);
            work->base.unk_164 = work->base.def->unk_08;
            act->x += gSineTable[work->base.angle] * work->base.unk_164 >> 8;
            act->y += -gSineTable[work->base.angle + 64] * work->base.unk_164
                >> 8;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 22;
        }
        break;
    case 22:
        work->base.unk_168 = 0;
        AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 2, 3,
            w->base.tiles);

        if (gBtlWork->flags & 0x40000) {
            if (act->x > work->base.x) {
                act->flags |= 4;
            } else {
                act->flags &= ~4;
            }

            work->base.angle = GetAngle(act->x, act->y, work->base.x,
                work->base.y);
            work->base.unk_164 = work->base.def->unk_08;
            act->x += gSineTable[work->base.angle] * work->base.unk_164 >> 8;
            act->y += -gSineTable[work->base.angle + 64] * work->base.unk_164
                >> 8;
            act->z += (work->base.unk_178 - act->z) >> 3;

            if ((work->base.flags & 2) ||
                    ((act->x - work->base.x >= 0
                    ? act->x - work->base.x <= 0xFFF
                    : work->base.x - act->x <= 0xFFF) &&
                    (act->y - work->base.y >= 0
                        ? act->y - work->base.y <= 0xFFF
                        : work->base.y - act->y <= 0xFFF))) {
                work->base.unk_14C = 21;
                work->base.unk_154 = 0;
                break;
            }

            work->base.unk_154++;
        }
        break;
    case 21:
        AnimChangeWithDef(gUnk_0813DA54, &w->base.anim, 3, 0, w->base.tiles);
        work->base.unk_168 = 0;
        act->x += gSineTable[work->base.angle] * work->base.unk_164 >> 8;
        act->y += -gSineTable[work->base.angle + 64] * work->base.unk_164 >> 8;
        work->base.unk_164 -= 25;

        if (work->base.unk_164 < 0) {
            work->base.unk_164 = 0;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 7;
        }
        break;
    case 18:
        AnimChangeWithDef(gUnk_0813DA54, &w->base.anim, 0, 0, w->base.tiles);

        if (work->base.unk_154 <= 29) {
            work->base.unk_168 = 0;
            act->z += (-0x3500 - act->z) >> 3;
        } else if (work->base.unk_154 == 30) {
            work->base.unk_168 = 0x300;
        }

        if (func_0800C980(&work->base, 30, 10, 6, 185, 32, SONG_BTL_MON_HIT02, 24, -10, 16)
                == 1) {
            w->unk_184 = work->base.unk_154;
        }
        break;
    case 19:
        AnimChangeWithDef(gUnk_0813DA54, &w->base.anim, 1, 0, w->base.tiles);

        if (work->base.anim.timer == 0) {
            switch (AnimGetFrame(&work->base.anim)) {
            case 0:
                work->base.unk_168 = 0x300;
                break;
            case 3:
                work->base.unk_168 = -0x600;
                break;
            }
        }

        if (func_0800C980(&work->base, 21, 8, 7, 186, 32, SONG_BTL_MON_HIT00, 16, -30, 16)
                == 1) {
            w->unk_184 = work->base.unk_154;
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_18_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_18_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_19_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy19Def, obj);
}

u8 task_emy_19_1(Emy19Work* work) {
    Emy19Work* w;
    BtlObj* act;
    s32 pos;
    s32 d;

    w = work;
    act = &work->base.actor;

    if (_0800CBDC(&work->base)) {
        func_0801C700(act, &pos, 0, 0);
        d = act->x - pos;

        if (d >= 0 ? d <= 0x3BFF : pos - act->x <= 0x3BFF) {
            work->base.unk_14C = 0x17;
        } else {
            work->base.unk_14C = 0x12;
        }

        w->unk_184 = 0;
    }

    switch (work->base.unk_14C) {
    case 0x12:
        AnimChangeWithDef(gUnk_0813DAFC, &w->base.anim, 0, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_14C = 0x13;
            work->base.unk_154 = 0;
        }
        break;
    case 0x13:
        if (work->base.unk_154 == 0) {
            AnimChangeWithDef(gUnk_0813DAFC, &w->base.anim, 1, 0, w->base.tiles);
            work->base.unk_168 = -0x500;
            w->unk_184 = 0x500;
        }

        act->x = act->flags & 4 ? act->x - w->unk_184 : act->x + w->unk_184;
        w->unk_184 = w->unk_184 * 248 >> 8;

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_14C = 0x14;
            work->base.unk_154 = 0;
        } else {
            work->base.unk_154++;
        }
        break;
    case 0x14:
        AnimChangeWithDef(gUnk_0813DAFC, &w->base.anim, 2, 1, w->base.tiles);
        act->x = act->flags & 4 ? act->x - w->unk_184 : act->x + w->unk_184;
        w->unk_184 = w->unk_184 * 248 >> 8;

        if (act->z >= act->unk_010) {
            work->base.unk_168 = -0x500;
        }

        if (func_08011F78(0xBB, act->x, act->y, act->z, 10, 10, 10) != 0) {
            m4aSongNumStart(SONG_BTL_MON_SWORD03);
            w->unk_184 = -w->unk_184;
            work->base.unk_168 = -0x500;
        }

        if (work->base.unk_154 > 55) {
            work->base.unk_14C = 0x15;
            work->base.unk_154 = 0;
        } else {
            work->base.unk_154++;
        }
        break;
    case 0x15:
        AnimChangeWithDef(gUnk_0813DAFC, &w->base.anim, 3, 0, w->base.tiles);
        act->x = act->flags & 4 ? act->x - w->unk_184 : act->x + w->unk_184;
        w->unk_184 = w->unk_184 * 248 >> 8;

        if (act->z >= act->unk_010) {
            work->base.unk_14C = 0x16;
            work->base.unk_154 = 0;
        }
        break;
    case 0x16:
        AnimChangeWithDef(gUnk_0813DAFC, &w->base.anim, 0, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
        }
        break;
    case 0x17:
        AnimChangeWithDef(gUnk_0813DAFC, &w->base.anim, 4, 0, w->base.tiles);

        switch (AnimGetFrame(&work->base.anim)) {
        case 3:
            if (work->base.anim.timer == 0) {
                w->unk_184 = 0x400;
            }
            break;
        case 4:
            if (work->base.anim.timer == 0) {
                w->unk_184 = 0;
            }

            if ((act->flags & 4)
                    ? func_08011F78(0xBC, act->x - 0x1000, act->y, act->z, 16, 16, 32) != 0
                    : func_08011F78(0xBC, act->x + 0x1000, act->y, act->z, 16, 16, 32) != 0) {
                m4aSongNumStart(SONG_BTL_MON_SWORD02);
            }
            break;
        }

        act->x = act->flags & 4 ? act->x - w->unk_184 : act->x + w->unk_184;
        w->unk_184 = w->unk_184 * 240 >> 8;

        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_19_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_19_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_21_0(Emy21Work* work, void* obj) {
    func_0800C778(&work->base, &gEmy21Def, obj);
    work->unk_184 = 0;
}

u8 task_emy_21_1(Emy21Work* work) {
    Emy21Work* w;
    BtlObj* act;
    s32 pos;
    s32 d;

    w = work;
    act = &work->base.actor;

    if (_0800CBDC(&work->base)) {
        func_0801C700(act, &pos, 0, 0);
        d = pos - act->x;

        if (d >= 0 ? d <= 0x3FFF : act->x - pos <= 0x3FFF) {
            work->base.unk_14C = 0x12;
        } else {
            work->base.unk_14C = 0x14;
        }
    } else if (work->base.unk_14C == 5 && work->base.unk_154 == 0) {
        m4aSongNumStop(SONG_EF_TARU_BOMB);
    }

    switch (work->base.unk_14C) {
    case 0x12:
        if (work->base.unk_154 == 0) {
            AnimChangeWithDef(gUnk_0813DBB4, &w->base.anim, 0, 1, w->base.tiles);
        }

        if (work->base.unk_154 > 29) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 0x13;
        } else {
            work->base.unk_154++;
        }
        break;
    case 0x13: {
        u16 t;

        t = work->base.unk_154;

        if (t >= 12 && t <= 39) {
            if (act->flags & 4) {
                func_08011F78(0xBD, act->x, act->y, act->z, 30, 30, 32);
            } else {
                func_08011F78(0xBD, act->x, act->y, act->z, 30, 30, 32);
            }
        }

        switch (work->base.unk_154) {
        case 2:
            func_08019A30();
            func_08014020(work->base.actor.x, work->base.actor.y,
                work->base.actor.z - 0x1000);
            break;
        case 40:
            func_0801AF08(act);
            return 0;
        }

        work->base.unk_154++;
        break;
    }
    case 0x14:
        AnimChangeWithDef(gUnk_0813DBB4, &w->base.anim, 1, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 0x15;
        }
        break;
    case 0x15:
        if (work->base.unk_154 == 0) {
            AnimChangeWithDef(gUnk_0813DBB4, &w->base.anim, 2, 1, w->base.tiles);
            w->unk_184 = 0;
        }

        act->x = act->flags & 4 ? act->x - w->unk_184 : act->x + w->unk_184;
        w->unk_184 += 43;

        if ((act->flags & 4)
            ? func_08011F78(0xBE, act->x, act->y, act->z, 20, 32, 32)
            : func_08011F78(0xBE, act->x, act->y, act->z, 20, 32, 32)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 0x13;
        } else if (work->base.unk_154 > 28) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 0x16;
        } else {
            work->base.unk_154++;
        }
        break;
    case 0x16:
        AnimChangeWithDef(gUnk_0813DBB4, &w->base.anim, 3, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 0x13;
            break;
        }

        if (work->base.anim.timer == 0) {
            switch (AnimGetFrame(&work->base.anim)) {
            case 0:
            case 1:
                act->x -= 0x380;
                act->y += 0x80;
                break;
            case 2:
                act->x -= 0x680;
                act->y += 0x280;
                break;
            case 3:
                act->x -= 0x500;
                act->y += 0x280;
                break;
            case 4:
                act->x -= 0x580;
                act->y += 0xC0;
                break;
            case 5:
                act->x -= 0x280;
                act->y += 0x3C0;
                break;
            case 6:
                act->x -= 0x180;
                break;
            case 7:
                act->x += 0x80;
                act->y += 0x40;
                break;
            }
        }

        act->x = act->flags & 4 ? act->x - w->unk_184 : act->x + w->unk_184;
        w->unk_184 -= 46;

        if (w->unk_184 < 0) {
            w->unk_184 = 0;
        }

        work->base.unk_154++;
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_21_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_21_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_22_0(Emy22Work* work, void* obj) {
    func_0800C778(&work->base, &gEmy22Def, obj);
    work->base.unk_150 = 7;
    work->unk_184 = 0;
}

u8 task_emy_22_1(Emy22Work* work) {
    Emy22Work* w;
    BtlObj* act;
    s32 pos;
    s32 pos2;
    s32 pos3;

    w = work;
    act = &work->base.actor;

    if (_0800CBDC(&work->base)) {
        if (act->unk_02C < act->unk_02E) {
            work->base.unk_14C = 20;
        } else {
            work->base.unk_14C = 21;
        }
    }

    switch (work->base.unk_14C) {
    case 1:
        if (work->base.unk_154 == 0) {
            w->unk_184 = 1;
        }
        break;
    case 7:
        if (w->unk_184 != 0 && work->base.unk_154 == 0) {
            work->base.unk_14C = 18;
            work->base.unk_154 = 0;
            w->unk_184 = 0;
        }
        break;
    case 18:
        if (work->base.unk_154 == 0) {
            AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 0, 1,
                w->base.tiles);
            act->flags |= 0x300;
            work->base.unk_156 = 20;
            work->base.unk_154 = 1;
        }

        work->base.unk_168 = 0;

        if (work->base.unk_156 > 0) {
            ApproachValue(&work->base.unk_17C, 25, work->base.unk_156);

            if (--work->base.unk_156 > 0) {
                break;
            }
        }

        work->base.unk_14C = 19;
        work->base.unk_154 = 0;
        break;
    case 19:
        if (work->base.unk_154 == 0) {
            func_0801C700(act, &pos, 0, 0);
            AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 0, 1,
                w->base.tiles);

            if (act->x > pos) {
                act->flags |= 4;
            } else {
                act->flags &= ~4;
            }

            act->x = (gBtlWork->unk_0DA
                + GetRandom() % (gBtlWork->unk_0DC - gBtlWork->unk_0DA + 1))
                << 8;
            act->y = (gBtlWork->unk_0DE
                + GetRandom() % (gBtlWork->unk_0E0 - gBtlWork->unk_0DE + 1))
                << 8;
            act->z = gBtlWork->unk_138;
            work->base.unk_17C = 25;
            work->base.unk_156 = 20;
            work->base.unk_154 = 1;
            m4aSongNumStart(SONG_BTL_WARPIN);
        }

        work->base.unk_168 = 0;

        if (work->base.unk_156 > 0) {
            ApproachValue(&work->base.unk_17C, 0x100, work->base.unk_156);

            if (--work->base.unk_156 > 0) {
                break;
            }
        }

        act->flags &= ~0x300;
        work->base.unk_14C = work->base.unk_150;
        work->base.unk_154 = 0;
        break;
    case 20:
        if (work->base.unk_154 == 0) {
            func_0801C700(act, &pos2, 0, 0);

            if (act->x > pos2) {
                act->flags |= 4;
            } else {
                act->flags &= ~4;
            }
        }

        act->z += -act->z >> 4;
        AnimChangeWithDef(gUnk_0813DC5C, &w->base.anim, 0, 0, w->base.tiles);
        func_0800C980(&work->base, 27, 14, 40, 191, 24, SONG_BTL_MON_HIT00, 24, 0, 24);

        if (gBtlWork->actor->flags & 2) {
            act->unk_02C += act->unk_02E >> 3;

            if (act->unk_02C > act->unk_02E) {
                act->unk_02C = act->unk_02E;
            }

            func_08019190(act, 10);
        }
        break;
    case 21:
        if (work->base.unk_154 == 0) {
            func_0801C700(act, &pos3, 0, 0);

            if (act->x > pos3) {
                act->flags |= 4;
            } else {
                act->flags &= ~4;
            }
        }

        act->z += -act->z >> 4;
        AnimChangeWithDef(gUnk_0813DC5C, &w->base.anim, 1, 0, w->base.tiles);
        func_0800C980(&work->base, 50, 19, 30, 192, 16, SONG_BTL_MON_HIT00, 48, 0, 24);
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_22_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_22_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_23_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy23Def, obj);
    work->unk_150 = 7;
}

u8 task_emy_23_1(Emy23Work* work) {
    Emy23Work* w;
    BtlObj* act;
    s32 pos;
    s32 d;
    s32 t;

    w = work;
    act = &work->base.actor;

    if (_0800CBDC(&work->base)) {
        func_0801C700(act, &pos, 0, 0);
        d = act->x - pos;

        if (d >= 0 ? d <= 0x31FF : pos - act->x <= 0x31FF) {
            work->base.unk_14C = 0x13;
        } else {
            work->base.unk_14C = 0x12;
        }
    }

    switch (work->base.unk_14C) {
    case 0x12:
        AnimChangeWithDef(gUnk_0813DCE4, &w->base.anim, 0, 0, w->base.tiles);

        switch (AnimGetFrame(&work->base.anim)) {
        case 0:
        case 1:
        case 2:
            work->base.unk_168 = 0;
            act->z += (-0x4000 - act->z) >> 3;
            break;
        case 3:
            if (work->base.anim.timer == 0) {
                func_0801C700(act, &t, 0, 0);
                work->base.unk_168 = 0x200;
                w->unk_184 = t;
            }
        case 4:
        case 5:
            if (act->z >= act->unk_010) {
                work->base.unk_168 = -0x466;
            }

            act->x += (w->unk_184 - act->x) >> 4;

            if (func_08011F78(0xC1, act->x, act->y, act->z - 0x1000, 12, 16, 16)) {
                m4aSongNumStart(SONG_BTL_MON_SWORD00);
                work->base.unk_168 = -0x466;
            }
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
        }
        break;
    case 0x13:
        AnimChangeWithDef(gUnk_0813DCE4, &w->base.anim, 1, 0, w->base.tiles);
        act->z += -act->z >> 2;

        if (AnimGetFrame(&work->base.anim) == 3) {
            if ((act->flags & 4)
                    ? func_08011F78(0xC2, act->x - 0x1E00, act->y, act->z,
                        0x10, 0x10, 4)
                    : func_08011F78(0xC2, act->x + 0x1E00, act->y, act->z,
                        0x10, 0x10, 4)) {
                m4aSongNumStart(SONG_BTL_MON_SWORD00);
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_23_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_23_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_25_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy25Def, obj);
}

u8 task_emy_25_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    u16 r;
    s32 dx;
    u16 dy;
    u16 e;
    u16 f;

    w = work;
    act = &work->actor;

    if (_0800CBDC(work)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->unk_14C = 0x12;
            break;
        case 1:
            work->unk_14C = 0x13;
            break;
        }
    }

    switch (work->unk_14C) {
    case 0x12:
        AnimChangeWithDef(gUnk_0813DD6C, &w->anim, 0, 0, w->tiles);

        if (AnimIsFinished(&work->anim)) {
            func_0800CB4C(work);
        } else if (work->anim.timer == 0) {
            dx = 0;
            dy = 0;

            switch (work->anim.frame) {
            case 2:
                dx = 5;
                dy = -1;
                break;
            case 3:
                dx = 5;
                dy = -2;

                if ((act->flags & 4)
                        ? func_08011F78(0xC3, act->x - 0x2800, act->y, act->z,
                            0x10, 0x10, 0x20)
                        : func_08011F78(0xC3, act->x + 0x2800, act->y, act->z,
                            0x10, 0x10, 0x20)) {
                    m4aSongNumStart(SONG_BTL_HANE_HIT);
                }
                break;
            case 4:
                dx = 5;
                dy = -1;
                break;
            case 5:
                dx = 6;
                dy = -2;
                break;
            case 6:
                dx = 6;
                dy = -1;
                break;
            case 7:
                dx = 1;
                dy = -1;
                break;
            }

            if (act->flags & 4) {
                act->x -= dx << 8;
            } else {
                act->x += dx << 8;
            }

            act->y -= (s16)dy << 8;
        }
        break;
    case 0x13:
        AnimChangeWithDef(gUnk_0813DD6C, &w->anim, 1, 0, w->tiles);

        if (AnimIsFinished(&work->anim)) {
            func_0800CB4C(work);
        } else if (work->anim.timer == 0) {
            e = 0;
            f = 0;

            switch (work->anim.frame) {
            case 8:
                e = 4;
                break;
            case 9:
                e = 2;
                break;
            case 10:
                e = 2;
                f = -1;
                break;
            case 11:
                e = 4;
                break;
            case 12:
                e = 7;
                f = -2;
                break;
            case 13:
                e = 1;
                f = -2;
                break;
            case 26:
                e = -5;
                f = 1;
                break;
            case 27:
                e = -15;
                f = 4;
                break;
            }

            if (act->flags & 4) {
                act->x -= (s16)e << 8;
            } else {
                act->x += (s16)e << 8;
            }

            act->y -= (s16)f << 8;

            if (work->anim.frame >= 8 && work->anim.frame <= 22) {
                if ((act->flags & 4)
                        ? func_08011F78(0xC4, act->x, act->y, act->z, 0x30, 0x30,
                            0x20)
                        : func_08011F78(0xC4, act->x, act->y, act->z, 0x30, 0x30,
                            0x20)) {
                    m4aSongNumStart(SONG_BTL_MON_HIT00);
                }
            }
        }
        break;
    }

    return _0800CDF0(work);
}

void task_emy_25_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_25_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_26_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy26Def, obj);
    work->actor.z = (GetRandom() % 0x1001) - 0x3000;
    work->unk_150 = 7;
}

u8 task_emy_26_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    u16 r;
    s32 z;
    s32 x;
    s32 t;
    s32* p;

    w = work;
    act = &work->actor;

    if (_0800CBDC(work)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->unk_14C = 0x12;
            break;
        case 1:
            work->unk_14C = 0x13;
            break;
        }
    }

    switch (work->unk_14C) {
    case 0x12:
        AnimChangeWithDef(gUnk_0813DDF4, &w->anim, 0, 0, w->tiles);

        switch (AnimGetFrame(&work->anim)) {
        case 3:
            if (work->anim.timer == 0) {
                work->unk_168 = 0x300;
            }
            break;
        case 0:
        case 1:
        case 2:
            work->unk_168 = 0;
            p = &gBtlWork->unk_138;
            t = act->z + 0x3C00;
            act->z += (*p - t) >> 3;
            break;
        }

        func_0800C980(work, 0x20, 0x0C, 0x14, 0xC5, 0x28, SONG_BTL_HANE_HIT, 0x14, 0x0A, 0x0A);
        break;
    case 0x13:
        work->unk_168 = 0;

        switch (work->unk_154) {
        case 0:
            AnimChangeWithDef(gUnk_0813DDF4, &w->anim, 1, 0, w->tiles);
            work->unk_154++;
            break;
        case 1:
            if (AnimIsFinished(&work->anim)) {
                z = act->y;

                if (act->flags & 4) {
                    x = act->x - 0x6400;
                    func_08012E44(1, act->x - 0x2600, z, act->z - 0x2000, x, z, 0, 1,
                        0xC6);
                } else {
                    x = act->x + 0x6400;
                    func_08012E44(1, act->x + 0x2600, z, act->z - 0x2000, x, z, 0, 0,
                        0xC6);
                }

                work->unk_154++;
            }
            break;
        case 2:
            AnimChange(&work->anim, 1, 0);

            if (AnimIsFinished(&work->anim)) {
                work->unk_154++;
            }
            break;
        case 3:
            AnimChange(&work->anim, 1, 0);

            if (AnimIsFinished(&work->anim)) {
                func_0800CB4C(work);
            }
            break;
        }
        break;
    }

    return _0800CDF0(work);
}

void task_emy_26_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_26_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_27_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy27Def, obj);
}

u8 task_emy_27_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    u16 s;
    s32 d;
    s32 y;
    s32 tx;
    s32 ty;

    w = work;
    act = &work->actor;

    if (_0800CBDC(work)) {
        func_0801C700(act, 0, &y, 0);
        d = act->y - y;

        if (d >= 0 ? d <= 0xFFF : y - act->y <= 0xFFF) {
            work->unk_14C = 0x12;
        } else {
            work->unk_14C = 0x13;
        }
    }

    switch (work->unk_14C) {
    case 0x12:
        AnimChangeWithDef(gUnk_0813DE7C, &w->anim, 0, 0, w->tiles);

        if (AnimGetFrame(&work->anim) == 1 && work->anim.timer == 0) {
            m4aSongNumStart(SONG_BTL_SWORDFLASH);

            if (act->flags & 4) {
                func_08013480(act->x - 0xC00, act->y, act->z - 0x2200);
            } else {
                func_08013480(act->x + 0xC00, act->y, act->z - 0x2200);
            }
        }

        func_0800C980(work, 0x3D, 6, 0x14, 0xC8, 0x20, SONG_BTL_MON_SWORD04, 0x28, 0, 0x14);
        break;
    case 0x13:
        AnimChangeWithDef(gUnk_0813DE7C, &w->anim, 1, 1, w->tiles);
        func_0801C700(act, &tx, &ty, 0);

        if (work->unk_154 % 6 == 0) {
            work->angle = GetAngle(act->x, act->y, tx, ty);
        }

        act->x += gSineTable[work->angle];
        act->y -= gSineTable[work->angle + 0x40];

        if (act->x > tx) {
            act->flags |= 4;
        } else {
            act->flags &= ~4;
        }

        s = AnimGetFrame(&work->anim);

        if (s == 2 || s == 5) {
            if ((act->flags & 4)
                    ? func_08011F78(0xC7, act->x - 0x1000, act->y, act->z, 0x14,
                        0x14, 0x20)
                    : func_08011F78(0xC7, act->x + 0x1000, act->y, act->z, 0x14,
                        0x14, 0x20)) {
                m4aSongNumStart(SONG_BTL_MON_SWORD03);
            }
        }

        if (work->unk_154 > 0x78) {
            func_0800CB4C(work);
        } else {
            work->unk_154++;
        }
        break;
    }

    return _0800CDF0(work);
}

void task_emy_27_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_27_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_28_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy28Def, obj);
    work->actor.z = (GetRandom() % 0x1001) - 0x3000;
    work->unk_150 = 7;
}

u8 task_emy_28_1(Emy28Work* work) {
    Emy28Work* w;
    BtlObj* act;
    u16 r;

    w = work;
    act = &work->base.actor;

    if (_0800CBDC(&work->base)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->base.unk_14C = 18;
            break;
        case 1:
            work->base.unk_14C = 19;
            break;
        }

        w->unk_184 = 0xEFFF;
    }

    if (work->base.unk_14C == 8) {
        work->base.unk_14C = 20;
        work->base.unk_154 = 0;
    }

    switch (work->base.unk_14C) {
    case 20:
        AnimChangeWithDef(gUnk_0813DF04, &w->base.anim, 2, 0, w->base.tiles);
        work->base.unk_168 = 0;

        if (AnimGetFrame(&work->base.anim) == 1) {
            work->base.angle = GetAngle(act->x, act->y, work->base.x,
                work->base.y);
            work->base.unk_164 = work->base.def->unk_08;
            act->x += gSineTable[work->base.angle] * work->base.unk_164 >> 8;
            act->y += -gSineTable[work->base.angle + 64] * work->base.unk_164
                >> 8;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 22;
        }
        break;
    case 22:
        work->base.unk_168 = 0;
        AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 2, 3,
            w->base.tiles);

        if (gBtlWork->flags & 0x40000) {
            if (act->x > work->base.x) {
                act->flags |= 4;
            } else {
                act->flags &= ~4;
            }

            work->base.angle = GetAngle(act->x, act->y, work->base.x,
                work->base.y);
            work->base.unk_164 = work->base.def->unk_08;
            act->x += gSineTable[work->base.angle] * work->base.unk_164 >> 8;
            act->y += -gSineTable[work->base.angle + 64] * work->base.unk_164
                >> 8;
            act->z += (work->base.unk_178 - act->z) >> 3;

            if ((work->base.flags & 2) ||
                    ((act->x - work->base.x >= 0
                    ? act->x - work->base.x <= 0xFFF
                    : work->base.x - act->x <= 0xFFF) &&
                    (act->y - work->base.y >= 0
                        ? act->y - work->base.y <= 0xFFF
                        : work->base.y - act->y <= 0xFFF))) {
                work->base.unk_14C = 21;
                work->base.unk_154 = 0;
                break;
            }

            work->base.unk_154++;
        }
        break;
    case 21:
        AnimChangeWithDef(gUnk_0813DF04, &w->base.anim, 3, 0, w->base.tiles);
        work->base.unk_168 = 0;
        act->x += gSineTable[work->base.angle] * work->base.unk_164 >> 8;
        act->y += -gSineTable[work->base.angle + 64] * work->base.unk_164 >> 8;
        work->base.unk_164 -= 25;

        if (work->base.unk_164 < 0) {
            work->base.unk_164 = 0;
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 7;
        }
        break;
    case 18:
        AnimChangeWithDef(gUnk_0813DF04, &w->base.anim, 0, 0, w->base.tiles);

        if (work->base.anim.timer == 0) {
            switch (AnimGetFrame(&work->base.anim)) {
            case 0:
                work->base.unk_168 = 0x300;
                break;
            case 3:
                work->base.unk_168 = -0x600;
                break;
            }
        }

        if (func_0800C980(&work->base, 22, 10, 20, 201, 32, SONG_BTL_MON_HIT00, 16, -40, 32)
                == 1) {
            w->unk_184 = work->base.unk_154;
        }
        break;
    case 19:
        AnimChangeWithDef(gUnk_0813DF04, &w->base.anim, 1, 0, w->base.tiles);

        if (work->base.unk_154 <= 34) {
            work->base.unk_168 = 0;
            act->z += (-0x4000 - act->z) >> 3;
        } else if (work->base.unk_154 == 35) {
            work->base.unk_168 = 0x300;
        }

        if (work->base.anim.timer == 0 && AnimGetFrame(&work->base.anim) == 1) {
            if (act->flags & 4) {
                func_08013480(act->x + 0x1000, act->y, act->z - 0x3200);
            } else {
                func_08013480(act->x - 0x1000, act->y, act->z - 0x3200);
            }

            m4aSongNumStart(SONG_BTL_SWORDFLASH);
        }

        if (func_0800C980(&work->base, 35, 10, 14, 202, 32, SONG_BTL_MON_HIT04, 24, 32, 16)
                == 1) {
            w->unk_184 = work->base.unk_154;
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_28_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_28_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_29_0(Emy29Work* work, void* obj) {
    func_0800C778(&work->base, &gEmy29Def, obj);
    work->base.unk_16C = 0x180;
    work->base.unk_150 = 7;
    work->base.flags |= 1;
    work->state = 0;
    work->unk_186 = 0;
}

void func_0803B468(Emy29Work* work, s16 anim, s16 dx, s16 dy, s16 dz) {
    if (work->unk_186 > 0) {
        AnimChange(&work->base.anim, anim, 0);
        ApproachValue(&work->base.actor.x, work->base.actor.unk_014 + ((s16)dx << 8), work->unk_186);
        ApproachValue(&work->base.actor.y, work->base.actor.unk_018 + ((s16)dy << 8), work->unk_186);
        ApproachValue(&work->base.actor.z, (s16)dz << 8, work->unk_186);
        work->unk_186--;
    } else {
        work->unk_186 = 8;
        work->state++;
    }
}

u8 task_emy_29_1(Emy29Work* work) {
    Emy29Work* w;
    BtlObj* act;
    s32 pos;
    s32 d;
    s32 a;
    s32 t;
    s16 c;

    w = work;
    act = &work->base.actor;

    if (_0800CBDC(&work->base)) {
        func_0801C700(act, &pos, 0, 0);
        d = act->x - pos;

        if (d >= 0 ? d <= 0x27FF : pos - act->x <= 0x27FF) {
            work->base.unk_14C = 0x13;
        } else {
            work->base.unk_14C = 0x12;
        }
    }

    switch (work->base.unk_14C) {
    case 0x12:
        AnimChangeWithDef(gUnk_0813DFAC, &w->base.anim, 0, 0, w->base.tiles);
        work->base.unk_168 = 0;
        a = -gSineTable[(((u16)work->base.unk_154 * 2) & 0xFF) + 0x40] << 4;
        t = act->z + 0x1000;
        act->z += (a - t) >> 2;

        if (func_0800C980(&work->base, 0x16, 0x64, 0x18, 0xCB, 0xB4, SONG_BTL_KAMITUKI, 0, 0, 0x0C) == 1) {
            func_0800CB4C(&work->base);
        }
        break;
    case 0x13:
        c = work->base.unk_154;

        if (c == 0) {
            AnimChangeWithDef(gUnk_0813DFAC, &w->base.anim, 1, 0, w->base.tiles);
            w->state = 0;
            w->unk_186 = 8;
            work->base.unk_154++;
            m4aSongNumStart(SONG_BTL_BOYOYON);
        }

        switch (w->state) {
        case 0:
            func_0803B468(w, 0, -25, 5, -10);
            break;
        case 1:
            func_0803B468(w, 1, 25, 0, 0);
            break;
        case 2:
            func_0803B468(w, 2, -20, -5, -22);
            break;
        case 3:
            func_0803B468(w, 3, 5, -17, -8);
            break;
        case 4:
            func_0803B468(w, 4, -5, 17, -16);
            break;
        case 5:
            func_0803B468(w, 5, 0, -17, 0);
            break;
        case 6:
            func_0803B468(w, 6, 25, 0, -11);
            break;
        case 7:
            func_0803B468(w, 7, -25, 0, -4);
            break;
        case 8:
            func_0803B468(w, 8, 0, 0, 0);
            break;
        case 9:
            func_0800CB4C(&work->base);
            break;
        }

        if ((act->flags & 4)
                ? func_08011F78(0xCC, act->x, act->y, act->z, 0x0C, 0x0C, 0x0C)
                : func_08011F78(0xCC, act->x, act->y, act->z, 0x0C, 0x0C, 0x0C)) {
            m4aSongNumStart(SONG_BTL_MON_HIT01);
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_29_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_29_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_30_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy30Def, obj);
    work->actor.z = (GetRandom() % 0x1001) - 0x3000;
    work->unk_150 = 7;
}

u8 task_emy_30_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    s32 x;
    s32 y;
    s32 d;
    u16 r;

    w = work;
    act = &work->actor;
    func_0801C700(act, &x, &y, 0);

    if (_0800CBDC(work)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->unk_14C = 18;
            break;
        case 1:
            work->unk_14C = 21;
            break;
        }
    }

    if (work->unk_14C == 8) {
        work->unk_14C = 24;
        work->unk_154 = 0;
    }

    switch (work->unk_14C) {
    case 24:
        AnimChangeWithDef(gUnk_0813E034, &w->anim, 0, 0, w->tiles);
        work->unk_168 = 0;

        if (AnimGetFrame(&work->anim) == 1) {
            work->angle = GetAngle(act->x, act->y, work->x, work->y);
            work->unk_164 = work->def->unk_08;
            act->x += gSineTable[work->angle] * work->unk_164 >> 8;
            act->y += -gSineTable[work->angle + 64] * work->unk_164 >> 8;
        }

        if (AnimIsFinished(&work->anim)) {
            work->unk_154 = 0;
            work->unk_14C = 26;
        }
        break;
    case 26:
        work->unk_168 = 0;
        AnimChangeWithDef(w->def->animDef, &w->anim, 2, 3, w->tiles);

        if (gBtlWork->flags & 0x40000) {
            if (act->x > work->x) {
                act->flags |= 4;
            } else {
                act->flags &= ~4;
            }

            work->angle = GetAngle(act->x, act->y, work->x, work->y);
            work->unk_164 = work->def->unk_08;
            act->x += gSineTable[work->angle] * work->unk_164 >> 8;
            act->y += -gSineTable[work->angle + 64] * work->unk_164 >> 8;
            act->z += (work->unk_178 - act->z) >> 3;

            if ((work->flags & 2)
                || ((act->x - work->x >= 0
                        ? act->x - work->x
                        : work->x - act->x) <= 0xFFF
                    && (act->y - work->y >= 0
                        ? act->y - work->y
                        : work->y - act->y) <= 0xFFF)) {
                work->unk_14C = 25;
                work->unk_154 = 0;
            } else {
                work->unk_154++;
            }
        }
        break;
    case 25:
        AnimChangeWithDef(gUnk_0813E034, &w->anim, 1, 0, w->tiles);
        work->unk_168 = 0;
        act->x += gSineTable[work->angle] * work->unk_164 >> 8;
        act->y += -gSineTable[work->angle + 64] * work->unk_164 >> 8;
        work->unk_164 -= 25;

        if (work->unk_164 < 0) {
            work->unk_164 = 0;
        }

        if (AnimIsFinished(&work->anim)) {
            work->unk_154 = 0;
            work->unk_14C = 7;
        }
        break;
    case 18: {
    s32 currentX;
    s32 targetX;
        AnimChangeWithDef(gUnk_0813E034, &w->anim, 2, 0, w->tiles);
        work->unk_168 = 0;
        act->z += (-0x4000 - act->z) >> 3;
        act->y += (y - act->y) >> 3;

        currentX = act->x;
        targetX = x;

        if (currentX < targetX) {
            act->flags &= ~4;
            d = currentX + 0x1400;
        } else {
            act->flags |= 4;
            d = currentX - 0x1400;
        }

        act->x = currentX + ((targetX - d) >> 3);

        if (AnimIsFinished(&work->anim)) {
            work->unk_14C = 19;
            work->unk_154 = 0;
        }
        break;
    }
    case 19: {
    s32 currentX;
    s32 targetX;
        AnimChangeWithDef(gUnk_0813E034, &w->anim, 3, 1, w->tiles);
        work->unk_168 = 0;
        act->z += (-0x2000 - act->z) >> 3;
        act->y += (y - act->y) >> 4;

        currentX = act->x;
        targetX = x;

        if (currentX < targetX) {
            act->flags &= ~4;
            d = currentX + 0x1400;
        } else {
            act->flags |= 4;
            d = currentX - 0x1400;
        }

        act->x = currentX + ((targetX - d) >> 3);

        if (work->anim.timer == 0) {
            switch (AnimGetFrame(&work->anim)) {
            case 1:
            case 3:
                func_08019A30();

                if (func_08011F78(0xCD, act->x, act->y, act->z, 12, 12, 12)) {
                    m4aSongNumStart(SONG_BTL_KAMITUKI);
                }
                break;
            }
        }

        if (work->unk_154 > 100) {
            work->unk_154 = 0;
            work->unk_14C = 20;
        } else {
            work->unk_154++;
        }
        break;
    }
    case 20:
        AnimChangeWithDef(gUnk_0813E034, &w->anim, 4, 0, w->tiles);
        work->unk_168 = 0;

        if (AnimIsFinished(&work->anim)) {
            func_0800CB4C(work);
        }
        break;
    case 21:
        work->unk_168 = 0;

        if (work->unk_154 == 0) {
            AnimChangeWithDef(gUnk_0813E034, &w->anim, 5, 0, w->tiles);

            if (act->x > 0x10000) {
                act->flags |= 4;
                work->x = gBtlWork->unk_0DC * 256;
            } else {
                act->flags &= ~4;
                work->x = gBtlWork->unk_0DA * 256;
            }
        }

        act->x += (work->x - act->x) >> 4;
        act->y += (y - act->y) >> 4;
        act->z += (-0x800 - act->z) >> 4;

        if (AnimIsFinished(&work->anim) && (work->flags & 2)) {
            work->unk_154 = 0;
            work->unk_14C = 22;
            work->unk_164 = 0;
        } else {
            work->unk_154++;
        }
        break;
    case 22:
        AnimChangeWithDef(gUnk_0813E034, &w->anim, 6, 1, w->tiles);
        work->unk_168 = 0;
        work->unk_164 += 38;
        act->y += (y - act->y) >> 4;
        act->z += (-0x800 - act->z) >> 4;

        if (act->flags & 4) {
            if (func_08011F78(0xCE, act->x - 0x1400, act->y, act->z, 12, 12, 12)) {
                m4aSongNumStart(SONG_BTL_MON_HIT03);
            }

            act->x -= work->unk_164;

            if (act->x < (gBtlWork->unk_0DA + 32) * 256) {
                work->unk_14C = 23;
                work->unk_154 = 0;
            }
        } else {
            if (func_08011F78(0xCE, act->x + 0x1400, act->y, act->z, 12, 12, 12)) {
                m4aSongNumStart(SONG_BTL_MON_HIT03);
            }

            act->x += work->unk_164;

            if (act->x > (gBtlWork->unk_0DC - 32) * 256) {
                work->unk_14C = 23;
                work->unk_154 = 0;
            }
        }
        break;
    case 23:
        AnimChangeWithDef(gUnk_0813E034, &w->anim, 7, 0, w->tiles);
        work->unk_168 = 0;
        work->unk_164 -= 128;

        if (work->unk_164 < 0) {
            work->unk_164 = 0;
        }

        if (act->flags & 4) {
            act->x -= work->unk_164;
        } else {
            act->x += work->unk_164;
        }

        if (AnimIsFinished(&work->anim)) {
            func_0800CB4C(work);
        }
        break;
    }

    return _0800CDF0(work);
}

void task_emy_30_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_30_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_31_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy31Def, obj);
    work->unk_150 = 7;
}

u8 task_emy_31_1(Emy31Work* work) {
    Emy31Work* w;
    BtlObj* act;

    w = work;
    act = &work->base.actor;

    if (_0800CBDC(&work->base)) {
        switch ((u16)(GetRandom() % 3)) {
        case 0:
            work->base.unk_14C = 18;
            break;
        case 1:
            work->base.unk_14C = 19;
            break;
        case 2:
            work->base.unk_14C = 20;
            break;
        }

        w->state = 0;
    }

    switch (work->base.unk_14C) {
    case 18: {
        s32 x;
        s32 y;
        work->base.unk_168 = 0;

        switch (w->state) {
        case 0:
            if (work->base.unk_154 == 0) {
                AnimChangeWithDef(gUnk_0813E11C, &w->base.anim, 0, 0,
                    w->base.tiles);
            }

            if (AnimIsFinished(&work->base.anim)) {
                w->state = 1;
                work->base.unk_154 = 0;
            } else {
                work->base.unk_154++;
            }
            break;
        case 1:
            if (work->base.unk_154 == 0) {
                AnimStart(&work->base.anim, 1, 0);

                y = act->y;
                if (act->flags & 4) {
                    x = act->x - 0xC800;
                    func_08012E44(1, act->x - 0x4000, y, act->z,
                        x, y, 0, 1, 0xCF);
                } else {
                    x = act->x + 0xC800;
                    func_08012E44(1, act->x + 0x4000, y, act->z,
                        x, y, 0, 0, 0xCF);
                }
            }

            if (work->base.unk_154 > 30) {
                w->state = 3;
                work->base.unk_154 = 0;
            } else {
                work->base.unk_154++;
            }
            break;
        case 3:
            if (work->base.unk_154 == 0) {
                AnimStart(&work->base.anim, 2, 0);
            }

            if (AnimIsFinished(&work->base.anim)) {
                AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 0, 1,
                    w->base.tiles);
            }

            if (func_080128EC()) {
                work->base.unk_154++;
            } else {
                w->state = 0;
                func_0800CB4C(&work->base);
            }
            break;
        }
        break;
    }
    case 19: {
        s32 x;
        s32 y;
        work->base.unk_168 = 0;

        switch (w->state) {
        case 0:
            if (work->base.unk_154 == 0) {
                AnimChangeWithDef(gUnk_0813E11C, &w->base.anim, 1, 0,
                    w->base.tiles);
            }

            if (AnimIsFinished(&work->base.anim)) {
                w->state = 1;
                work->base.unk_154 = 0;
            } else {
                work->base.unk_154++;
            }
            break;
        case 1:
            if (work->base.unk_154 == 0) {
                AnimStart(&work->base.anim, 1, 1);

                y = act->y;
                if (act->flags & 4) {
                    x = act->x - 0x6400;
                    func_08013308(1, act->x - 0x4600, y, act->z,
                        x, y, 0, 1, 0xD0);
                } else {
                    x = act->x + 0x6400;
                    func_08013308(1, act->x + 0x4600, y, act->z,
                        x, y, 0, 0, 0xD0);
                }
            }

            if (work->base.unk_154 > 60) {
                w->state = 2;
                work->base.unk_154 = 0;
            } else {
                work->base.unk_154++;
            }
            break;
        case 2:
            if (work->base.unk_154 == 0) {
                AnimStart(&work->base.anim, 2, 0);
            }

            if (AnimIsFinished(&work->base.anim)) {
                AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 0, 1,
                    w->base.tiles);
            }

            if (func_080128EC()) {
                work->base.unk_154++;
            } else {
                w->state = 0;
                func_0800CB4C(&work->base);
            }
            break;
        }
        break;
    }
    case 20:
        work->base.unk_168 = 0;

        switch (w->state) {
        case 0:
            if (work->base.unk_154 == 0) {
                AnimChangeWithDef(gUnk_0813E11C, &w->base.anim, 2, 0,
                    w->base.tiles);
                func_0801C700(act, &w->unk_188, &w->unk_18C, &w->unk_190);
            }

            if (AnimIsFinished(&work->base.anim)) {
                w->state = 1;
                work->base.unk_154 = 0;
            } else {
                work->base.unk_154++;
            }
            break;
        case 1:
            if (work->base.unk_154 == 0) {
                AnimStart(&work->base.anim, 1, 0);
                work->base.unk_156 = 0;
            }

            if (AnimIsFinished(&work->base.anim)) {
                if (work->base.unk_156 == 0) {
                    if (act->flags & 4) {
                        func_08015834(1, act->x - 0x1600, act->y,
                            act->z - 0x3C00, w->unk_188, w->unk_18C,
                            w->unk_190, 0xD1);
                    } else {
                        func_08015834(1, act->x + 0x1600, act->y,
                            act->z - 0x3C00, w->unk_188, w->unk_18C,
                            w->unk_190, 0xD1);
                    }

                    work->base.unk_156++;
                }

                if (!func_080128EC()) {
                    w->state = 2;
                    work->base.unk_154 = 0;
                    break;
                }
            }
            work->base.unk_154++;
            break;
        case 2:
            if (work->base.unk_154 == 0) {
                AnimStart(&work->base.anim, 2, 0);
            }

            if (AnimIsFinished(&work->base.anim)) {
                w->state = 0;
                func_0800CB4C(&work->base);
            } else {
                work->base.unk_154++;
            }
            break;
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_31_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_31_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_37_0(Emy37Work* work, void* obj) {
    func_0800C778(&work->base, &gEmy37Def, obj);
    work->base.flags |= 1;
    work->base.unk_150 = 0x12;
    work->base.unk_14C = 0x1C;
    work->unk_184 = 0;
}

u8 task_emy_37_1(Emy37Work* work) {
    Emy37Work* w;
    BtlObj* act;

    w = work;
    act = &work->base.actor;

    if (_0800CBDC(&work->base)) {
        if (work->base.unk_14C == 20) {
            work->unk_184 = 0;
            act->flags &= ~0x100;
            work->base.unk_14C = 25;
            work->base.actor.unk_0A2 = 20;
        } else {
            work->base.unk_14C = 24;
        }
    }

    switch (work->base.unk_14C) {
    case 24:
        AnimChangeWithDef(gUnk_0813E1B4, &w->base.anim, 0, 0, w->base.tiles);
        func_0800C980(&work->base, 30, 14, 20, 0xD2, 70, SONG_BTL_MON_HIT00, 0, 0, 24);
        break;
    case 25:
        AnimChangeWithDef(gUnk_0813E1B4, &w->base.anim, 4, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 29;
        } else {
            work->base.unk_154++;
        }
        break;
    case 29:
        if (work->base.unk_154 == 0) {
            work->base.unk_168 = -0x399;
            AnimChangeWithDef(gUnk_0813E1B4, &w->base.anim, 1, 0, w->base.tiles);
        }

        if (work->base.unk_168 > 0) {
            work->base.unk_168 = 0;
        }

        if (func_08011F78(0xD3, act->x, act->y, act->z, 16, 8, 32)) {
            m4aSongNumStart(SONG_BTL_MON_HIT00);
        }

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 30;
        } else {
            work->base.unk_154++;
        }
        break;
    case 30:
        if (work->base.unk_154 == 0) {
            s32 x;
            s32 y;

            AnimChangeWithDef(gUnk_0813E1B4, &w->base.anim, 2, 1, w->base.tiles);
            w->unk_188 = 0;
            func_0801C700(act, &x, &y, 0);
            w->angle = GetAngle(act->x, act->y, x, y);
        }

        if (((u16)work->base.unk_154 % 4) == 0) {
            u8 angle;
            s32 x;
            s32 y;

            func_0801C700(act, &x, &y, 0);
            angle = GetAngle(act->x, act->y, x, y);
            ApproachAngle(&w->angle, angle, 4);
        }

        act->x += gSineTable[(u8)w->angle] * (s32)w->unk_188 >> 8;
        act->y += -gSineTable[(u8)w->angle + 64] * (s32)w->unk_188 >> 8;
        w->unk_188 += 12;

        if (func_08011F78(0xD3, act->x, act->y, act->z, 32, 16, 16)) {
            m4aSongNumStart(SONG_BTL_MON_HIT00);
            work->base.unk_154 = 120;
        }

        work->base.unk_168 = 0;

        if (work->base.unk_154 > 120) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    case 28:
        AnimChangeWithDef(gUnk_0813E1B4, &w->base.anim, 10, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            act->flags &= ~0x100;
            func_0800CD40(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    case 19:
        AnimChangeWithDef(gUnk_0813E1B4, &w->base.anim, 9, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_14C = 20;
            ColliderSetDisabled(&act->collider, 1);
            act->flags |= 0x100;
            act->unk_0A2 = 0;
        }
        break;
    case 20:
        if (gBtlWork->flags & 0x40000) {
            s32 x;
            s32 y;
            s32 dx;
            s32 dy;
            s32 sample;
            s32 offset;

            func_0801C700(act, &x, &y, 0);
            AnimChangeWithDef(gUnk_0813E1B4, &w->base.anim, 5, 1, w->base.tiles);
            sample = gSineTable[work->base.angle];
            offset = 70;
            offset *= sample;
            dx = x + offset;
            dy = y + -gSineTable[work->base.angle + 64] * 35;
            dx -= act->x;
            dx >>= 4;
            dy -= act->y;
            dy >>= 4;

            if (dx > 0x300) {
                dx = 0x300;
            } else if (dx < -0x300) {
                dx = -0x300;
            }

            if (dy > 0x300) {
                dy = 0x300;
            } else if (dy < -0x300) {
                dy = -0x300;
            }

            act->x += dx;
            act->y += dy;

            if (work->base.unk_154 == 0) {
                act->flags &= ~0x200;
            }

            func_0801BCF8(act);

            if (act->flags & 4) {
                work->base.angle -= 2;
                w->unk_184 = work->base.angle;
            } else {
                work->base.angle += 2;
                w->unk_184 = -work->base.angle;
            }

            if (work->base.unk_154 > 160) {
                w->unk_184 = 0;
                work->base.unk_14C = 21;
                ColliderSetDisabled(&act->collider, 0);
                act->flags &= ~0x100;
                act->unk_0A2 = 20;
                act->flags |= 0x200;
                work->base.unk_154 = 0;
            } else {
                work->base.unk_154++;
            }
        }
        break;
    case 21:
        AnimChangeWithDef(gUnk_0813E1B4, &w->base.anim, 6, 0, w->base.tiles);

        if (work->base.unk_154 == 30) {
            act->flags &= ~0x100;
        }

        if (AnimIsFinished(&work->base.anim)) {
            act->flags &= ~0x300;
            work->base.unk_14C = 26;
            work->base.unk_154 = 0;
        } else {
            work->base.unk_154++;
        }
        break;
    case 26:
        if (work->base.unk_154 == 0) {
            AnimChangeWithDef(gUnk_0813E1B4, &w->base.anim, 7, 0, w->base.tiles);
            work->base.unk_168 = -0x433;
        }

        if (work->base.unk_168 > 0) {
            work->base.unk_14C = 27;
            work->base.unk_154 = 0;
        } else {
            work->base.unk_154++;
        }
        break;
    case 27:
        if (work->base.unk_154 == 0) {
            AnimChangeWithDef(gUnk_0813E1B4, &w->base.anim, 8, 0, w->base.tiles);
        }

        if (act->z >= act->unk_010) {
            work->base.unk_14C = 18;
            work->base.unk_154 = 0;
        } else {
            work->base.unk_154++;
        }
        break;
    case 18:
        if (work->base.unk_154 == 0) {
            act->unk_0A2 = 20;
            ColliderSetDisabled(&act->collider, 0);
            act->flags &= ~0x300;
            AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 0, 3, w->base.tiles);
        }

        func_0801BCF8(act);

        if ((u16)(GetRandom() % 200U) == 0) {
            work->base.unk_14C = 4;

            if (GetRandom() % 2 == 0) {
                work->base.x = -((act->unk_0CE
                    + (-act->unk_0D0 + GetRandom() % (act->unk_0D0 - -act->unk_0D0 + 1))) * 256);
            } else {
                work->base.x = (act->unk_0CE
                    + (-act->unk_0D0 + GetRandom() % (act->unk_0D0 - -act->unk_0D0 + 1))) * 256;
            }
            break;
        } else if ((u16)(GetRandom() % 100U) == 0) {
            work->base.unk_14C = 19;
            act->flags |= 0x200;
            work->base.angle = GetRandom();
            work->base.unk_154 = 0;
            break;
        }

        if ((u16)((u32)GetRandom() % work->base.def->unk_0E) == 0) {
            s32 x;

            func_0801C700(act, &x, 0, 0);

            if (act->x > x) {
                act->flags |= 4;
            } else {
                act->flags &= ~4;
            }
        }

        work->base.unk_154++;
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_37_2(Emy37Work* work) {
    Emy37Work* w;
    BtlObj* act;
    u16 pri;
    s32 affine;
    s32 rot;
    s32 scale;
    s32 zoom;
    s16 x;
    s16 y;

    w = work;

    if (work->base.unk_15A != 0) {
        act = &work->base.actor;
        pri = GetBattleSpritePriorityFlags(act->y) | work->base.unk_162;
        WorldToScreen(&x, &y, act->x, act->y, act->z);

        zoom = work->base.unk_180;

        if (zoom == 0x100) {
            if (act->flags & 4) {
                scale = gBtlWork->scale;
                rot = scale;
            } else if (work->unk_184 == 0 && gBtlWork->scale == zoom) {
                scale = zoom;
                rot = scale;
                pri |= 1;
            } else {
                rot = -gBtlWork->scale;
                scale = gBtlWork->scale;
            }
        } else {
            if (act->flags & 4) {
                rot = gBtlWork->scale * work->base.unk_17C >> 8;
                scale = gBtlWork->scale;
            } else {
                rot = -(gBtlWork->scale * work->base.unk_17C >> 8);
                scale = gBtlWork->scale;
            }

            scale = scale * zoom >> 8;
        }

        if (w->unk_184) {
            affine = AllocObjAffine(w->unk_184, rot, scale, 1);
        } else if (scale == 0x100 && rot == scale) {
            affine = 0;
        } else if (scale <= 0xFF) {
            affine = AllocObjAffine(0, rot, scale, 0);
        } else {
            affine = AllocObjAffine(0, rot, scale, 1);
        }

        if (func_0801CA00(act)) {
            DrawSprite(x, y, work->base.gfx, work->base.tiles, work->base.palette2, affine,
                pri, -0x1004 - (act->y >> 8) * 4);
        } else if (work->base.unk_14C == 0x14) {
            DrawSprite(x, y, work->base.gfx, work->base.tiles, work->base.palette, affine,
                pri, 0xFFFF);
        } else {
            DrawSprite(x, y, work->base.gfx, work->base.tiles, work->base.palette, affine,
                pri, -0x1004 - (act->y >> 8) * 4);
        }

        TaskPoolDraw(&work->base.tasks);
    }
}

void task_emy_37_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_38_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy38Def, obj);
}

u8 task_emy_38_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    u16 r;
    u8 ret;

    w = work;
    act = &work->actor;

    if (_0800CBDC(work)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->unk_14C = 0x12;
            break;
        case 1:
            work->unk_14C = 0x13;
            break;
        }
    }

    switch (work->unk_14C) {
    case 0x12:
        AnimChangeWithDef(gUnk_0813E2CC, &w->anim, 0, 0, w->tiles);
        func_0800C980(work, 0x1E, 0x14, 0x2D, 0xD4, 0x32, SONG_BTL_MON_HIT01, 0, 0, 0x18);

        if (work->unk_154 == 0x1E) {
            work->unk_168 = -0x300;
        }
        break;
    case 0x13:
        AnimChangeWithDef(gUnk_0813E2CC, &w->anim, 1, 0, w->tiles);

        if (work->unk_154 == 0x3F) {
            func_08011F78(0xD5, act->x, act->y, act->z, 0x100, 0x100, 1);
            m4aSongNumStart(SONG_BTL_LB_RUMB);
            func_0802F1E8();
        }

        if (AnimIsFinished(&work->anim)) {
            func_0800CB4C(work);
        } else {
            work->unk_154++;
        }
        break;
    }

    ret = _0800CDF0(work);

    if ((gBtlWork->actor->x < work->actor.x && (work->actor.flags & 4)) ||
            (gBtlWork->actor->x > work->actor.x &&
                !(work->actor.flags & 4))) {
        work->actor.flags |= 0x8000;
    } else {
        work->actor.flags &= ~0x8000;
    }

    return ret;
}

void task_emy_38_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_38_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_39_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy39Def, obj);
}

u8 task_emy_39_1(Emy39Work* work) {
    Emy39Work* w;
    BtlObj* act;
    u16 r;
    s16 c;
    s32 z;
    s32 x;
    s32 p;
    s32 q;
    u8 ret;

    w = work;
    act = &work->base.actor;

    if (_0800CBDC(&work->base)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->base.unk_14C = 0x12;
            break;
        case 1:
            work->base.unk_14C = 0x13;
            break;
        }
    }

    switch (work->base.unk_14C) {
    case 0x12:
        AnimChangeWithDef(gUnk_0813E354, &w->base.anim, 0, 0, w->base.tiles);

        if (work->base.unk_154 == 0x30) {
            z = act->y;

            if (act->flags & 4) {
                x = act->x - 0x6400;
                func_08012E44(0, act->x - 0x4000, z, act->z - 0x2000, x, z, 0, 1,
                    0xD6);
            } else {
                x = act->x + 0x6400;
                func_08012E44(0, act->x + 0x4000, z, act->z - 0x2000, x, z, 0, 0,
                    0xD6);
            }
        }

        if (work->base.unk_154 > 0x30 && BgAnimIsStopped()) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    case 0x13:
        c = work->base.unk_154;

        if (c == 0) {
            AnimChangeWithDef(gUnk_0813E354, &w->base.anim, 1, 0, w->base.tiles);
            w->unk_184 = 0;
        }

        switch (AnimGetFrame(&work->base.anim)) {
        case 0:
            p = 24;
            q = 20;
            break;
        case 1:
            p = 30;
            q = 16;
            break;
        case 2:
            p = 24;
            q = 20;

            if (work->base.anim.timer == 0) {
                w->unk_184 = 0x200;
            }
            break;
        case 3:
            p = 24;
            q = 16;
            break;
        case 4:
            p = 48;
            q = 20;
            break;
        case 5:
            p = 30;
            q = 16;

            if (work->base.anim.timer == 0) {
                w->unk_184 = 0x200;
            }
            break;
        case 6:
            p = 48;
            q = 20;
            break;
        case 7:
        default:
            p = 24;
            q = 20;
            break;
        }

        if (act->flags & 4) {
            act->x -= w->unk_184;
        } else {
            act->x += w->unk_184;
        }

        w->unk_184 -= 0x19;

        if (w->unk_184 < 0) {
            w->unk_184 = 0;
        }

        if (func_08011F78(0xD7, act->x, act->y, act->z, p, q, 0x28)) {
            m4aSongNumStart(SONG_BTL_MON_HIT02);
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    }

    ret = _0800CDF0(&work->base);

    if ((gBtlWork->actor->x < work->base.actor.x
                && (work->base.actor.flags & 4))
            || (gBtlWork->actor->x > work->base.actor.x
                && !(work->base.actor.flags & 4))) {
        work->base.actor.flags |= 0x8000;
    } else {
        work->base.actor.flags &= ~0x8000;
    }

    return ret;
}

void task_emy_39_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_39_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_41_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy41Def, obj);
    work->unk_150 = 7;
}

u8 task_emy_41_1(Emy41Work* work) {
    Emy41Work* w;
    BtlObj* act;
    u16 r;
    s32 t;
    s32 a;

    w = work;
    act = &work->base.actor;

    if (_0800CBDC(&work->base)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->base.unk_14C = 0x12;
            break;
        case 1:
            work->base.unk_14C = 0x13;
            break;
        }
    }

    switch (work->base.unk_14C) {
    case 0x12:
        AnimChangeWithDef(gUnk_0813E3DC, &w->base.anim, 0, 0, w->base.tiles);
        work->base.unk_168 = 0;
        a = gSineTable[((u16)work->base.unk_154 * 4) & 0xFF] << 4;
        t = act->z + 0x1000;
        act->z += (a - t) >> 2;
        func_0800C980(&work->base, 0x14, 0x63, 0x1E, 0xD8, 0x40, SONG_BTL_MON_HIT02, 0, -0x10, 0x2C);
        break;
    case 0x13:
        if (work->base.unk_154 == 0) {
            AnimChangeWithDef(gUnk_0813E3DC, &w->base.anim, 1, 0, w->base.tiles);
            func_0801C700(act, &w->unk_184, &w->unk_188, 0);
            w->unk_18C = 0;
        }

        if (AnimGetFrame(&work->base.anim) == 4 && work->base.anim.timer == 0) {
            if (act->flags & 4) {
                func_08015834(1, act->x - 0x2C00, act->y, act->z, w->unk_184,
                    w->unk_188, w->unk_18C, 0xD9);
            } else {
                func_08015834(1, act->x + 0x2C00, act->y, act->z, w->unk_184,
                    w->unk_188, w->unk_18C, 0xD9);
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_41_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_41_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_44_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy44Def, obj);
}

u8 task_emy_44_1(EmyWork* work) {
    EmyWork* w;
    BtlObj* act;
    s32 pos;
    s32 d;
    u8 ret;

    w = work;
    act = &work->actor;

    if (_0800CBDC(work)) {
        func_0801C700(act, &pos, 0, 0);
        d = act->x - pos;

        if (d >= 0 ? d <= 0x4FFF : pos - act->x <= 0x4FFF) {
            work->unk_14C = 0x12;
        } else {
            work->unk_14C = 0x13;
        }
    }

    switch (work->unk_14C) {
    case 0x12:
        AnimChangeWithDef(gUnk_0813E464, &w->anim, 0, 0, w->tiles);

        switch (AnimGetFrame(&work->anim)) {
        case 1:
        case 2:
        case 3:
        case 4:
            if ((act->flags & 4)
                    ? func_08011F78(0xDA, act->x - 0x2000, act->y, act->z, 0x20,
                        0x10, 0x28)
                    : func_08011F78(0xDA, act->x + 0x2000, act->y, act->z, 0x20,
                        0x10, 0x28)) {
                m4aSongNumStart(SONG_BTL_DF_HIT);
            }
            break;
        }

        if (AnimIsFinished(&work->anim)) {
            func_0800CB4C(work);
        }
        break;
    case 0x13:
        AnimChangeWithDef(gUnk_0813E464, &w->anim, 1, 0, w->tiles);

        if (AnimGetFrame(&work->anim) == 7 && work->anim.timer == 0) {
            if (act->flags & 4) {
                func_08012E44(1, act->x - 0x4000, act->y, act->z - 0x400,
                    act->x - 0xB400, act->y, act->z - 0x400, 1, 0xDB);
            } else {
                func_08012E44(1, act->x + 0x4000, act->y, act->z - 0x400,
                    act->x + 0xB400, act->y, act->z - 0x400, 0, 0xDB);
            }
        }

        if (AnimIsFinished(&work->anim)) {
            func_0800CB4C(work);
        }
        break;
    }

    ret = _0800CDF0(work);

    if ((gBtlWork->actor->x < work->actor.x && (work->actor.flags & 4)) ||
            (gBtlWork->actor->x > work->actor.x &&
                !(work->actor.flags & 4))) {
        work->actor.flags |= 0x0C008000;
    } else {
        work->actor.flags &= ~0x0C008000;
    }

    return ret;
}

void task_emy_44_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_44_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_81_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmy81Def, obj);
}

static inline s32 EmyFacingX(BtlObj* actor, s32 offset) {
    return actor->flags & 4 ? actor->x - offset : actor->x + offset;
}

u8 task_emy_81_1(Emy81Work* work) {
    Emy81Work* w;
    BtlObj* act;
    u16 r;
    u16 frame;
    u16 idleFrame;
    s32 d;
    s32 hitX;
    s32 a;
    s32 z;
    s32 b;

    w = work;
    act = &work->base.actor;

    if (_0800CBDC(&work->base)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->base.unk_14C = 18;
            break;
        case 1:
            work->base.unk_14C = 19;
            break;
        }
    }

    switch (work->base.unk_14C) {
    case 0:
    case 4:
        idleFrame = AnimGetGfxIndex(&work->base.anim);

        if ((idleFrame == 2 || idleFrame == 6) && work->base.anim.timer == 0) {
            work->base.unk_168 = -0x133;
        }

        if (GetRandom() % 200 == 0) {
            work->base.unk_14C = 20;
            work->base.unk_154 = 0;
            w->unk_184 = 0;
        }
        break;
    case 20:
        AnimChangeWithDef(gUnk_0813E4EC, &w->base.anim, 2, 0, w->base.tiles);

        d = (-0x2800 - act->z) >> 4;

        if (d < -w->unk_184) {
            w->unk_184 += 25;
        } else {
            w->unk_184 = -d;
        }

        work->base.unk_168 = 0;

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_154 = 0;
            work->base.unk_14C = 21;
        } else {
            work->base.unk_154++;
        }
        break;
    case 21:
        if (work->base.unk_154 == 0) {
            func_0801C700(act, &a, &b, 0);
            AnimChangeWithDef(gUnk_0813E4EC, &w->base.anim, 3, 1, w->base.tiles);
            w->unk_18C = (a * 2) - act->x;
            w->unk_190 = (b * 2) - act->y;
            w->unk_184 = 0;
            w->unk_188 = 0;
        }

        work->base.unk_168 = 0;
        {
            s32 sample = gSineTable[((u16)work->base.unk_154 * 4) & 0xFF] * 10;
            s32 current = act->z;

            z = current + 0x2800;
            act->z = current + ((sample - z) >> 3);
        }

        d = (w->unk_18C - act->x) >> 4;

        if (d > w->unk_184) {
            d = w->unk_184;
            w->unk_184 += 51;
        } else if (d < -w->unk_184) {
            d = -w->unk_184;
            w->unk_184 += 51;
        } else {
            w->unk_184 = d < 0 ? -d : d;
        }

        act->x += d;
        d = (w->unk_190 - act->y) >> 4;

        if (d > w->unk_188) {
            d = w->unk_188;
            w->unk_188 = d + 2;
        } else if (d < -w->unk_188) {
            d = -w->unk_188;
            w->unk_188 += 2;
        } else {
            w->unk_188 = d < 0 ? -d : d;
        }

        act->y += d;

        if ((work->base.flags & 2)
                || ((w->unk_18C - act->x < 0
                        ? act->x - w->unk_18C
                        : w->unk_18C - act->x) <= 0x7FF
                    && (w->unk_190 - act->y < 0
                        ? act->y - w->unk_190
                        : w->unk_190 - act->y) <= 0x7FF)) {
            work->base.unk_14C = 22;
            work->base.unk_154 = 0;
        } else {
            work->base.unk_154++;
        }
        break;
    case 22:
        AnimChangeWithDef(gUnk_0813E4EC, &w->base.anim, 4, 0, w->base.tiles);
        work->base.unk_168 -= 25;

        if (act->z >= act->unk_010) {
            work->base.unk_14C = work->base.unk_150;
            work->base.unk_154 = 0;
        }
        break;
    case 18:
        if (work->base.unk_154 == 0) {
            AnimChangeWithDef(gUnk_0813E4EC, &w->base.anim, 0, 0, w->base.tiles);
        }

        {
            s32 currentX;
            s32 targetX;
            s32 adjustedX;

            if (act->flags & 4) {
                targetX = 0x3000;
                currentX = act->x;
                adjustedX = currentX + targetX;
            } else {
                targetX = -0x3000;
                currentX = act->x;
                adjustedX = currentX + targetX;
            }

            targetX = act->unk_014;
            targetX -= adjustedX;
            targetX >>= 4;
            currentX += targetX;
            act->x = currentX;
        }

        frame = AnimGetFrame(&work->base.anim);

        if (frame >= 3 && frame <= 6) {
            work->base.unk_168 = 0;
        }

        switch (frame) {
        case 1:
            if (work->base.anim.timer == 0) {
                work->base.unk_168 = -0x400;
            }
            break;
        case 3:
            hitX = EmyFacingX(act, 0x1600);

            if (func_08011F78(0xDC, hitX, act->y, act->z + 0x800, 10, 10, 10)) {
                m4aSongNumStart(SONG_BTL_MON_HIT04);
            }
            break;
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    case 19:
        if (work->base.unk_154 == 0) {
            AnimChangeWithDef(gUnk_0813E4EC, &w->base.anim, 1, 0, w->base.tiles);
        }

        {
            s32 currentX;
            s32 targetX;
            s32 adjustedX;

            if (act->flags & 4) {
                targetX = 0x4600;
                currentX = act->x;
                adjustedX = currentX + targetX;
            } else {
                targetX = -0x4600;
                currentX = act->x;
                adjustedX = currentX + targetX;
            }

            targetX = act->unk_014;
            targetX -= adjustedX;
            targetX >>= 4;
            currentX += targetX;
            act->x = currentX;
        }

        frame = AnimGetFrame(&work->base.anim);

        if (frame == 4) {
            s32 centerX = EmyFacingX(act, 0);

            if ((act->flags & 4)
                    ? func_08011F78(0xDD, centerX - 0x1800, act->y, act->z,
                        0x10, 0x10, 10)
                    : func_08011F78(0xDD, centerX + 0x1800, act->y, act->z,
                        0x10, 0x10, 10)) {
                m4aSongNumStart(SONG_BTL_MON_HIT00);
            }
        }

        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    }

    return _0800CDF0(&work->base);
}

void task_emy_81_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_81_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_82_0(Emy82Work* work, void* obj) {
    func_0800C778(&work->base, &gEmy82Def, obj);
    work->base.unk_150 = 0x15;
    work->unk_184 = 0;
}

u8 func_0803DD44(EmyWork* work) {
    BtlObj* act;
    s32 x;
    s32 y;
    s32 d;
    s32 t;
    s32 lo;
    s32 actorX;
    s32 actorY;
    s32 targetY;

    act = &work->actor;
    func_0801C700(act, &x, &y, 0);

    if (x < (gBtlWork->unk_0DA + 0x30) << 8) {
        d = x + 0x28;
    } else if (x > (gBtlWork->unk_0DC - 0x30) << 8) {
        d = x - 0x28;
    } else {
        t = (work->actor.unk_0CE + ((lo = -work->actor.unk_0D0) +
            GetRandom() % (work->actor.unk_0D0 - lo + 1))) << 8;

        if (act->x < x) {
            d = x - t;
        } else {
            d = x + t;
        }
    }

    targetY = y;
    actorX = act->x;
    actorY = act->y;
    return GetAngle(actorX, actorY, d, targetY);
}

u8 task_emy_82_1(Emy82Work* work) {
    Emy82Work* w;
    BtlObj* act;

    w = work;
    act = &work->base.actor;
    if (_0800CBDC(&work->base)) {
        switch ((u16)(GetRandom() % 3U)) {
        case 0:
            work->base.unk_14C = 18;
            break;
        case 1:
            if (gBtlWork->unk_0EE > 1) {
                work->base.unk_14C = 19;
            } else {
                work->base.unk_14C = 18;
            }
            break;
        case 2:
            work->base.unk_14C = 20;
            break;
        }
    }

    switch (work->base.unk_14C) {
    case 5:
        if (work->base.unk_154 == 0) {
            m4aSongNumStop(SONG_EF_RAPPA_CALL);
        }
        break;
    case 22:
        AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 2, 1, w->base.tiles);
        if (act->z < act->unk_010 && (gBtlWork->flags & 0x40000)) {
            act->x += gSineTable[work->base.angle] * work->base.unk_164 >> 8;
            act->y += -gSineTable[work->base.angle + 64] * work->base.unk_164 >> 8;
            if ((u16)((u32)GetRandom() % work->base.def->unk_0E) == 0) {
                s32 x;
                func_0801C700(act, &x, 0, 0);
                if (act->x > x) {
                    act->flags |= 4;
                } else {
                    act->flags &= ~4;
                }
            }
        } else {
            switch (AnimGetFrame(&work->base.anim)) {
            case 6:
                if (work->base.anim.timer > 2 && (u16)(GetRandom() % 15U) == 0) {
                    work->base.unk_14C = work->base.unk_150;
                }
                break;
            case 1:
                if (work->base.anim.timer == 0) {
                    work->base.angle = func_0803DD44(&work->base);
                    func_0801BCF8(act);
                    work->base.unk_168 = -0x3CC;
                }
                break;
            }
        }
        break;
    case 21:
        AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 0, 1, w->base.tiles);
        if ((u16)((u32)GetRandom() % work->base.def->unk_0E) == 0) {
            s32 x;
            func_0801C700(act, &x, 0, 0);
            if (act->x > x) {
                act->flags |= 4;
            } else {
                act->flags &= ~4;
            }
        }
        switch (AnimGetGfxIndex(&work->base.anim)) {
        case 0:
            if (work->base.anim.timer == 5 && (u16)((u32)GetRandom() % work->base.def->unk_0C) == 0) {
                work->base.unk_14C = 22;
                work->base.angle = func_0803DD44(&work->base);
            }
            break;
        case 2:
            if (work->base.anim.timer == 0 && act->z >= act->unk_010) {
                work->base.unk_168 = -0x4C0;
                func_0801BCF8(act);
            }
            break;
        }
        break;
    case 18:
        {
            s32 d;
            s32 currentX;
            s32 targetX;
            u32 frame;
            s32 hitX;
            if (work->base.unk_154 == 0) {
                AnimChangeWithDef(gUnk_0813E5A4, &w->base.anim, 3, 0, w->base.tiles);
                work->base.unk_168 = -0x400;
            }
            if (act->flags & 4) {
                targetX = 0x3000;
                currentX = act->x;
                d = currentX + targetX;
            } else {
                targetX = -0x3000;
                currentX = act->x;
                d = currentX + targetX;
            }
            targetX = act->unk_014;
            targetX -= d;
            targetX >>= 4;
            currentX += targetX;
            act->x = currentX;
            frame = AnimGetFrame(&work->base.anim);
            if (frame > 3) {
                work->base.unk_168 = 0;
            }
            if (frame == 4) {
                if (act->flags & 4) {
                    hitX = act->x - 0x1400;
                } else {
                    hitX = act->x + 0x1400;
                }
                if (func_08011F78(0xDE, hitX, act->y, act->z + 0x800, 10, 10, 20)) {
                    m4aSongNumStart(SONG_BTL_MON_HIT00);
                }
            } else if (frame == 5) {
                if (act->flags & 4) {
                    hitX = act->x - 0x1800;
                } else {
                    hitX = act->x + 0x1800;
                }
                if (func_08011F78(0xDE, hitX, act->y, act->z - 0x2300, 10, 10, 10)) {
                    m4aSongNumStart(SONG_BTL_MON_HIT00);
                }
            }
            if (AnimIsFinished(&work->base.anim)) {
                work->base.unk_14C = 23;
            } else {
                work->base.unk_154++;
            }
        }
        break;
    case 19:
        {
            u32 frame;
            if (work->base.unk_154 == 0) {
                AnimChangeWithDef(gUnk_0813E5A4, &w->base.anim, 4, 0, w->base.tiles);
            }
            frame = AnimGetFrame(&work->base.anim);
            if (frame > 1) {
                work->base.unk_168 = 0;
            }
            if (work->base.anim.timer == 0) {
                switch (frame) {
                case 1:
                    work->base.unk_168 = -0x100;
                    m4aSongNumStart(SONG_EF_RAPPA_CALL);
                    break;
                case 4:
                    {
                        BtlObj* best = 0;
                        BtlObj* actor;
                        s16 missing = 0;
                        for (actor = ListPoolFirst(&gBtlWork->pool); actor;
                             actor = ListPoolNext(&actor->node)) {
                            if (actor != act && !(actor->flags & 0x100)) {
                                if (missing <= actor->unk_02E - actor->unk_02C) {
                                    missing = actor->unk_02E - actor->unk_02C;
                                    best = actor;
                                }
                            }
                        }
                        if (best) {
                            m4aSongNumStart(SONG_EF_CAREL00);
                            best->flags |= 0x20;
                            best->unk_020 = 0xFFEC;
                        } else {
                            func_08019190(act, 2);
                        }
                    }
                    break;
                }
            }
            if (AnimIsFinished(&work->base.anim)) {
                work->base.unk_14C = 23;
            } else {
                work->base.unk_154++;
            }
        }
        break;
    case 20:
        {
            u32 frame;
            if (work->base.unk_154 == 0) {
                AnimChangeWithDef(gUnk_0813E5A4, &w->base.anim, 5, 0, w->base.tiles);
            }
            frame = AnimGetFrame(&work->base.anim);
            if ((u16)(frame - 2) <= 21) {
                work->base.unk_168 = 0;
            }
            if (work->base.anim.timer == 0) {
                switch (frame) {
                case 1:
                    work->base.unk_168 = -0x100;
                    m4aSongNumStart(SONG_EF_RAPPA_CALL);
                    break;
                case 24:
                    work->base.unk_168 = -0x380;
                    if (gBtlWork->unk_0EE <= 3 && (s16)w->unk_184 <= 2) {
                        u32 spawnFailure = 0;
                        s32 x;
                        s32 offset;
                        if (act->flags & 4) {
                            x = act->x;
                            offset = 0x2000;
                        } else {
                            x = act->x;
                            offset = -0x2000;
                        }
                        x += offset;
                        offset = act->y;
                        if (func_0801BDDC(9, x, offset, act->z - 0xC00) != spawnFailure) {
                            gBtlWork->unk_120++;
                            w->unk_184++;
                        } else {
                            func_08019190(act, 2);
                        }
                    } else {
                        func_08019190(act, 2);
                    }
                    break;
                }
            }
            if (AnimIsFinished(&work->base.anim)) {
                work->base.unk_14C = 23;
            } else {
                work->base.unk_154++;
            }
        }
        break;
    case 23:
        AnimChangeWithDef(gUnk_0813E5A4, &w->base.anim, 0, 0, w->base.tiles);
        work->base.unk_168 = 0;
        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_14C = 24;
        }
        break;
    case 24:
        AnimChangeWithDef(gUnk_0813E5A4, &w->base.anim, 1, 0, w->base.tiles);
        if (act->z >= act->unk_010) {
            work->base.unk_14C = 25;
        }
        break;
    case 25:
        AnimChangeWithDef(gUnk_0813E5A4, &w->base.anim, 2, 0, w->base.tiles);
        if (AnimGetFrame(&work->base.anim) == 1 && work->base.anim.timer == 0) {
            work->base.unk_168 = -0x333;
        }
        if (AnimIsFinished(&work->base.anim)) {
            func_0800CB4C(&work->base);
        }
        break;
    }
    return _0800CDF0(&work->base);
}

void task_emy_82_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_82_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_83_0(Emy83Work* work, void* obj) {
    func_0800C778(&work->base, &gEmy83Def, obj);
    work->task = 0;
    work->base.unk_150 = 0x16;
    TaskPoolInit(&work->tasks, 4);
}

u8 task_emy_83_1(Emy83Work* work) {
    Emy83Work* w;
    BtlObj* act;
    u16 r;
    u16 c;
    EmySpawn spawn;
    s32 pos;
    s32 x;
    s32 y;
    s32 z;
    u8 ret;

    w = work;
    act = &work->base.actor;

    if (_0800CBDC(&work->base)) {
        r = GetRandom();

        switch (r & 1) {
        case 0:
            work->base.unk_14C = 0x12;
            w->task = 0;
            break;
        case 1:
            work->base.unk_14C = 0x13;
            w->unk_1A4 = 0;
            break;
        }
    }

    switch (work->base.unk_14C) {
    case 0x16:
        AnimChangeWithDef(w->base.def->animDef, &w->base.anim, 0, 3, w->base.tiles);
        func_0801BCF8(act);
        func_0801C700(act, &pos, 0, 0);

        if (act->x < pos) {
            act->flags &= ~4;
        } else {
            act->flags |= 4;
        }
        break;
    case 0x12:
        AnimChangeWithDef(gUnk_0813E66C, &w->base.anim, 0, 0, w->base.tiles);
        c = work->base.anim.timer;

        if (c == 0) {
            switch (AnimGetFrame(&work->base.anim)) {
            case 3:
                func_0801C700(act, &w->unk_19C, &w->unk_1A0, 0);
                break;
            case 5:
                spawn.x = w->unk_19C;
                spawn.y = w->unk_1A0;
                spawn.z = c;
                w->task = TaskCreate(&w->tasks, &gTaskDescEmy83B, &spawn);
                break;
            }
        }

        if (AnimIsFinished(&work->base.anim) && !IsTaskActiveNamed(w->task, gTaskDescEmy83B.name)) {
            func_0800CB4C(&work->base);
        }
        break;
    case 0x13:
        AnimChangeWithDef(gUnk_0813E66C, &w->base.anim, 1, 0, w->base.tiles);

        if (AnimIsFinished(&work->base.anim)) {
            work->base.unk_14C = 0x14;
        }
        break;
    case 0x14:
        AnimChangeWithDef(gUnk_0813E66C, &w->base.anim, 2, 1, w->base.tiles);

        if (AnimGetGfxIndex(&work->base.anim) == 6 && work->base.anim.timer == 0) {
            if (act->flags & 4) {
                spawn.x = act->x - 0x1000;
                spawn.unk_12 = 1;
            } else {
                spawn.x = act->x + 0x1000;
                spawn.unk_12 = 0;
            }

            spawn.y = act->y;
            spawn.z = act->z - 0x1200;
            spawn.unk_14 = 0;
            TaskCreate(&w->tasks, &gTaskDescEmy83S, &spawn);
            spawn.unk_14 = 1;
            TaskCreate(&w->tasks, &gTaskDescEmy83S, &spawn);
            spawn.unk_14 = 2;
            TaskCreate(&w->tasks, &gTaskDescEmy83S, &spawn);
            w->unk_1A4++;
        }

        if (w->unk_1A4 > 2 && AnimIsFinished(&work->base.anim)) {
            work->base.unk_14C = 0x15;
            work->base.unk_154 = 0;
        } else {
            work->base.unk_154++;
        }
        break;
    case 0x15:
        AnimChangeWithDef(gUnk_0813E66C, &w->base.anim, 3, 0, w->base.tiles);

        if (work->base.unk_154 > 0x28) {
            func_0800CB4C(&work->base);
        } else {
            work->base.unk_154++;
        }
        break;
    }

    TaskPoolUpdate(&w->tasks);
    x = act->x;
    y = act->y;
    z = act->z;
    ret = _0800CDF0(&work->base);

    if (work->base.unk_14C != 0x0B) {
        act->x = x;
        act->y = y;
        act->z = z;
    }

    return ret;
}

void task_emy_83_2(Emy83Work* work) {
    func_0800DF30(&work->base);
    TaskPoolDraw(&work->tasks);
}

void task_emy_83_3(Emy83Work* work) {
    TaskPoolDestroy(&work->tasks);
    func_0800E0D0(&work->base);
}

void task_emy_83_b_0(Emy83bWork* work, EmySpawn* spawn) {
    work->state = 0;
    work->palette = LoadObjPalette(gEmy83Palette, 0x20);
    work->tiles = AllocObjTiles(0x80, gEmy8310bTiles);
    AnimInit(work->unk_008, gEmy8310bAnims, gEmy8310bFrames);
    AnimStart(work->unk_008, 0, 0);
    work->x = spawn->x;
    work->y = spawn->y;
    work->z = spawn->z;
    work->timer = 0;
    ColliderInit(&work->collider, 0x0C, 4, 0x10);
}

u8 task_emy_83_b_1(Emy83bWork* work) {
    if ((gBtlWork->flags & 0x40) == 0) {
        return 0;
    }

    switch (work->state) {
    case 0:
        if (work->timer > 0x0F) {
            work->state = 1;
            work->timer = 0;
        } else {
            work->timer++;
        }
        break;
    case 1:
        if (work->timer == 0) {
            AnimStart(work->unk_008, 1, 0);
        }

        if (AnimGetFrame(work->unk_008) == 1 && work->unk_012 == 0) {
            if (func_08011F78(0xE0, work->x, work->y, work->z, 4, 4, 0x10)) {
                m4aSongNumStart(SONG_BTL_HANE_HIT);
            }
        }

        if (work->timer > 0x1D) {
            work->state = 2;
            work->timer = 0;
        } else {
            work->timer++;
        }
        break;
    case 2:
    default:
        if (work->timer == 0) {
            AnimStart(work->unk_008, 2, 0);
        }

        if (AnimIsFinished(work->unk_008)) {
            return 0;
        }

        work->timer++;
        break;
    }

    ColliderSetPosition(&work->collider, work->x, work->y, work->z);
    AnimUpdate(work->unk_008);
    return 1;
}

void task_emy_83_b_2(Emy83bWork* work) {
    void* gfx;
    u16 pri;
    s16 x;
    s16 y;

    gfx = AnimGetGfx(work->unk_008);
    pri = GetBattleSpritePriorityFlags(work->y);
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gfx, work->tiles, work->palette, 0, pri,
        -0x1004 - ((work->y + 0x400) >> 8) * 4);
}

void task_emy_83_b_3(Emy83bWork* work) {
    ColliderUnregister(&work->collider);
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_emy_83_s_0(Emy83sWork* work, EmySpawn* spawn) {
    work->palette = LoadObjPalette(gEmy83Palette, 0x20);
    work->tiles = LoadObjTiles(gEmy8311bTiles, 0x40);
    work->x = spawn->x;
    work->y = spawn->y;
    work->z = spawn->z;
    work->vz = 0;
    work->unk_022 = 0;

    if (spawn->unk_12 != 0) {
        work->unk_018 = -(GetRandom() % 0x4CE + 0x133);
    } else {
        work->unk_018 = GetRandom() % 0x4CE + 0x133;
    }

    work->unk_01C = GetRandom() % 0x201 - 0x100;
    work->unk_020 = spawn->unk_14;
}

u8 task_emy_83_s_1(Emy83sWork* work) {
    s32 x;
    s32 y;

    if (gBtlWork->flags & 0x40) {
        x = work->x + work->unk_018;
        work->x = x;
        y = work->y + work->unk_01C;
        work->y = y;

        if (work->unk_022 % 3 == work->unk_020) {
            if (func_08011F78(0xE1, x, y, work->z, 2, 2, 2) != 0) {
                m4aSongNumStart(SONG_BTL_KAMITUKI);
            }
        }

        work->z += work->vz;
        work->vz += 0x14;

        if (work->z < 0) {
            work->unk_022++;
            return 1;
        }
    }

    return 0;
}

void task_emy_83_s_2(Emy83sWork* work) {
    u16 pri;
    s16 x;
    s16 y;

    pri = GetBattleSpritePriorityFlags(work->y);
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gEmy8311bFrame0, work->tiles, work->palette, 0, pri,
        -0x1004 - ((work->y + 0x400) >> 8) * 4);
    WorldToScreen(&x, &y, work->x, work->y, 0);
    DrawSprite(x, y, gEmy8311bFrame1, work->tiles, work->palette, 0, pri, -2);
}

void task_emy_83_s_3(Emy83sWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void task_emy_trump_h_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmyTrumpHDef, obj);
}

u8 task_emy_trump_h_1(EmyWork* work) {
    BtlObj* act;

    act = &work->actor;

    if (_0800CBDC(work)) {
        work->unk_14C = 0x13;
    }

    if (work->unk_14C == 3) {
        work->unk_14C = 0x12;
    }

    switch (work->unk_14C) {
    case 0x13:
        AnimChangeWithDef(&gUnk_0813E734, &work->anim, 0, 0, work->tiles);
        func_0800C980(work, 0x19, 8, 0x0A, 0x12B, 0x30, SONG_BTL_MON_SWORD00, 0x50, 0, 0x18);
        break;
    case 0x12:
        if (work->unk_154 == 0) {
            AnimChangeWithDef(work->def->animDef, &work->anim, 0, 0, work->tiles);
            m4aSongNumStart(SONG_BTL_CARDDEATH);
        }

        work->unk_17C = gSineTable[(u8)work->unk_154 + 0x40];
        work->unk_154 += 8;

        if (work->unk_154 > 0x13F) {
            func_0801B994(act);
            return 0;
        }

        work->unk_154++;
        break;
    }

    return _0800CDF0(work);
}

void task_emy_trump_h_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_trump_h_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_trump_s_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmyTrumpSDef, obj);
}

u8 task_emy_trump_s_1(EmyWork* work) {
    BtlObj* act;

    act = &work->actor;

    if (_0800CBDC(work)) {
        work->unk_14C = 0x13;
    }

    if (work->unk_14C == 3) {
        work->unk_14C = 0x12;
    }

    switch (work->unk_14C) {
    case 0x13:
        AnimChangeWithDef(&gUnk_0813E7B4, &work->anim, 0, 0, work->tiles);
        func_0800C980(work, 0x14, 0x1E, 0x0A, 0x12A, 0x46, SONG_BTL_MON_SWORD01, 0x10, 0, 0x18);

        if (work->unk_154 == 0x14) {
            work->unk_168 = -0x480;
        }
        break;
    case 0x12:
        if (work->unk_154 == 0) {
            AnimChangeWithDef(work->def->animDef, &work->anim, 0, 0, work->tiles);
            m4aSongNumStart(SONG_BTL_CARDDEATH);
        }

        work->unk_17C = gSineTable[(u8)work->unk_154 + 0x40];
        work->unk_154 += 8;

        if (work->unk_154 > 0x13F) {
            func_0801B994(act);
            return 0;
        }

        work->unk_154++;
        break;
    }

    return _0800CDF0(work);
}

void task_emy_trump_s_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_trump_s_3(EmyWork* work) {
    func_0800E0D0(work);
}

void task_emy_test_0(EmyWork* work, void* obj) {
    func_0800C778(work, &gEmyTestDef, obj);
    work->actor.unk_02E = 0xBB8;
    work->actor.unk_02C = 0xBB8;
    work->actor.flags |= 0x1000;
}

u8 task_emy_test_1(EmyWork* work) {
    _0800CBDC(work);
    return _0800CDF0(work);
}

void task_emy_test_2(EmyWork* work) {
    func_0800DF30(work);
}

void task_emy_test_3(EmyWork* work) {
    func_0800E0D0(work);
}

TaskDesc gTaskDescEmyTest = { "task_emy_test", task_emy_test_0, task_emy_test_1, task_emy_test_2, task_emy_test_3, 0x184 };
