#include "btl.h"
#include "task_animation_assets.h"

const char gTaskNameBtlLockon[] = "task_btl_lockon";
const char gTaskNameBtlArea[] = "task_btl_area";

AnimDef gUnk_0813BA2C[77] __attribute__((section(".rodata_btl_000"))) = {
    { gUnk_09EDEDB8, gUnk_09EDEDEC, gUnk_088E0BC0, 0, { 0, 0, 0 } },
    { gUnk_09EDEE08, gUnk_09EDEE14, gUnk_088E33C2, 0, { 0, 0, 0 } },
    { gUnk_09EDEE40, gUnk_09EDEE54, gUnk_088E56C6, 4, { 0, 0, 0 } },
    { gUnk_09EDEE40, gUnk_09EDEE54, gUnk_088E56C6, 3, { 0, 0, 0 } },
    { gUnk_09EDEE40, gUnk_09EDEE54, gUnk_088E56C6, 0, { 0, 0, 0 } },
    { gUnk_09EDEE40, gUnk_09EDEE54, gUnk_088E56C6, 1, { 0, 0, 0 } },
    { gUnk_09EDEE40, gUnk_09EDEE54, gUnk_088E56C6, 2, { 0, 0, 0 } },
    { gUnk_09EDEE68, gUnk_09EDEE7C, gUnk_088E67B6, 4, { 0, 0, 0 } },
    { gUnk_09EDEE68, gUnk_09EDEE7C, gUnk_088E67B6, 3, { 0, 0, 0 } },
    { gUnk_09EDEE68, gUnk_09EDEE7C, gUnk_088E67B6, 0, { 0, 0, 0 } },
    { gUnk_09EDEE68, gUnk_09EDEE7C, gUnk_088E67B6, 1, { 0, 0, 0 } },
    { gUnk_09EDEE68, gUnk_09EDEE7C, gUnk_088E67B6, 2, { 0, 0, 0 } },
    { gUnk_09EDEF38, gUnk_09EDEF50, gUnk_088ED77A, 4, { 0, 0, 0 } },
    { gUnk_09EDEF38, gUnk_09EDEF50, gUnk_088ED77A, 3, { 0, 0, 0 } },
    { gUnk_09EDEF38, gUnk_09EDEF50, gUnk_088ED77A, 0, { 0, 0, 0 } },
    { gUnk_09EDEF38, gUnk_09EDEF50, gUnk_088ED77A, 1, { 0, 0, 0 } },
    { gUnk_09EDEF38, gUnk_09EDEF50, gUnk_088ED77A, 2, { 0, 0, 0 } },
    { gUnk_09EDEE90, gUnk_09EDEEB0, gUnk_088E7974, 4, { 0, 0, 0 } },
    { gUnk_09EDEE90, gUnk_09EDEEB0, gUnk_088E7974, 3, { 0, 0, 0 } },
    { gUnk_09EDEE90, gUnk_09EDEEB0, gUnk_088E7974, 0, { 0, 0, 0 } },
    { gUnk_09EDEE90, gUnk_09EDEEB0, gUnk_088E7974, 1, { 0, 0, 0 } },
    { gUnk_09EDEE90, gUnk_09EDEEB0, gUnk_088E7974, 2, { 0, 0, 0 } },
    { gUnk_09EDEFA8, gUnk_09EDEFBC, gUnk_088F19DC, 4, { 0, 0, 0 } },
    { gUnk_09EDEFA8, gUnk_09EDEFBC, gUnk_088F19DC, 3, { 0, 0, 0 } },
    { gUnk_09EDEFA8, gUnk_09EDEFBC, gUnk_088F19DC, 0, { 0, 0, 0 } },
    { gUnk_09EDEFA8, gUnk_09EDEFBC, gUnk_088F19DC, 1, { 0, 0, 0 } },
    { gUnk_09EDEFA8, gUnk_09EDEFBC, gUnk_088F19DC, 2, { 0, 0, 0 } },
    { gUnk_09EDF040, gUnk_09EDF05C, gUnk_088F8678, 5, { 0, 0, 0 } },
    { gUnk_09EDF040, gUnk_09EDF05C, gUnk_088F8678, 4, { 0, 0, 0 } },
    { gUnk_09EDF040, gUnk_09EDF05C, gUnk_088F8678, 1, { 0, 0, 0 } },
    { gUnk_09EDF040, gUnk_09EDF05C, gUnk_088F8678, 2, { 0, 0, 0 } },
    { gUnk_09EDF040, gUnk_09EDF05C, gUnk_088F8678, 3, { 0, 0, 0 } },
    { gUnk_09EDEFD0, gUnk_09EDEFF0, gUnk_088F2F5C, 4, { 0, 0, 0 } },
    { gUnk_09EDEFD0, gUnk_09EDEFF0, gUnk_088F2F5C, 3, { 0, 0, 0 } },
    { gUnk_09EDEFD0, gUnk_09EDEFF0, gUnk_088F2F5C, 0, { 0, 0, 0 } },
    { gUnk_09EDEFD0, gUnk_09EDEFF0, gUnk_088F2F5C, 1, { 0, 0, 0 } },
    { gUnk_09EDEFD0, gUnk_09EDEFF0, gUnk_088F2F5C, 2, { 0, 0, 0 } },
    { gUnk_09EDEEC4, gUnk_09EDEEEC, gUnk_088E967C, 0, { 0, 0, 0 } },
    { gUnk_09EDEDB8, gUnk_09EDEDEC, gUnk_088E0BC0, 2, { 0, 0, 0 } },
    { gUnk_09EDEDB8, gUnk_09EDEDEC, gUnk_088E0BC0, 3, { 0, 0, 0 } },
    { gUnk_09EDEDB8, gUnk_09EDEDEC, gUnk_088E0BC0, 4, { 0, 0, 0 } },
    { gUnk_09EDEDB8, gUnk_09EDEDEC, gUnk_088E0BC0, 6, { 0, 0, 0 } },
    { gUnk_09EDEEF4, gUnk_09EDEF08, gUnk_088EAF1C, 0, { 0, 0, 0 } },
    { gUnk_09EDEF0C, gUnk_09EDEF28, gUnk_088EBFDA, 0, { 0, 0, 0 } },
    { gUnk_09EDEF0C, gUnk_09EDEF28, gUnk_088EBFDA, 1, { 0, 0, 0 } },
    { gUnk_09EDEF0C, gUnk_09EDEF28, gUnk_088EBFDA, 2, { 0, 0, 0 } },
    { gUnk_09EDEF0C, gUnk_09EDEF28, gUnk_088EBFDA, 3, { 0, 0, 0 } },
    { gUnk_09EDEF84, gUnk_09EDEF98, gUnk_088F05DC, 3, { 0, 0, 0 } },
    { gUnk_09EDEF84, gUnk_09EDEF98, gUnk_088F05DC, 2, { 0, 0, 0 } },
    { gUnk_09EDEF84, gUnk_09EDEF98, gUnk_088F05DC, 0, { 0, 0, 0 } },
    { gUnk_09EDEF84, gUnk_09EDEF98, gUnk_088F05DC, 1, { 0, 0, 0 } },
    { gUnk_09EDEF64, gUnk_09EDEF80, gUnk_088EEAD4, 0, { 0, 0, 0 } },
    { gUnk_09EDEAEC, gUnk_09EDEB08, gUnk_088CA102, 0, { 0, 0, 0 } },
    { gUnk_09EDF0AC, gUnk_09EDF0C4, gUnk_088FCCCE, 0, { 0, 0, 0 } },
    { gUnk_09EDF0D4, gUnk_09EDF114, gUnk_088FDE7A, 0, { 0, 0, 0 } },
    { gUnk_09EDF0D4, gUnk_09EDF114, gUnk_088FDE7A, 1, { 0, 0, 0 } },
    { gUnk_09EDF0D4, gUnk_09EDF114, gUnk_088FDE7A, 2, { 0, 0, 0 } },
    { gUnk_09EDF0D4, gUnk_09EDF114, gUnk_088FDE7A, 3, { 0, 0, 0 } },
    { gUnk_09EDF0AC, gUnk_09EDF0C4, gUnk_088FCCCE, 1, { 0, 0, 0 } },
    { gUnk_09EDF0AC, gUnk_09EDF0C4, gUnk_088FCCCE, 3, { 0, 0, 0 } },
    { gUnk_09EDF158, gUnk_09EDF1B0, gUnk_08902C3C, 0, { 0, 0, 0 } },
    { gUnk_09EDF158, gUnk_09EDF1B0, gUnk_08902C3C, 1, { 0, 0, 0 } },
    { gUnk_09EDF158, gUnk_09EDF1B0, gUnk_08902C3C, 2, { 0, 0, 0 } },
    { gUnk_09EDF158, gUnk_09EDF1B0, gUnk_08902C3C, 3, { 0, 0, 0 } },
    { gUnk_09EDF1C0, gUnk_09EDF1F8, gUnk_08908DE6, 0, { 0, 0, 0 } },
    { gUnk_09EDF1C0, gUnk_09EDF1F8, gUnk_08908DE6, 1, { 0, 0, 0 } },
    { gUnk_09EDF1C0, gUnk_09EDF1F8, gUnk_08908DE6, 2, { 0, 0, 0 } },
    { gUnk_09EDF1C0, gUnk_09EDF1F8, gUnk_08908DE6, 3, { 0, 0, 0 } },
    { gUnk_09EDF20C, gUnk_09EDF244, gUnk_0890C34E, 0, { 0, 0, 0 } },
    { gUnk_09EDF248, gUnk_09EDF268, gUnk_0890FCE0, 0, { 0, 0, 0 } },
    { gUnk_09EDF26C, gUnk_09EDF290, gUnk_08911BC8, 0, { 0, 0, 0 } },
    { gUnk_09EDF294, gUnk_09EDF2C4, gUnk_08914288, 0, { 0, 0, 0 } },
    { gUnk_09EDF294, gUnk_09EDF2C4, gUnk_08914288, 1, { 0, 0, 0 } },
    { gUnk_09EDF294, gUnk_09EDF2C4, gUnk_08914288, 2, { 0, 0, 0 } },
    { gUnk_09EDF2D0, gUnk_09EDF2FC, gUnk_089173FC, 0, { 0, 0, 0 } },
    { gUnk_09EDF2D0, gUnk_09EDF2FC, gUnk_089173FC, 1, { 0, 0, 0 } },
    { gUnk_09EDF2D0, gUnk_09EDF2FC, gUnk_089173FC, 2, { 0, 0, 0 } },
};

AnimDef gUnk_0813BEFC[6][5] __attribute__((section(".rodata_btl_000"))) = {
    { { gUnk_09EDE944, gUnk_09EDE964, gUnk_088BC6DE, 0, { 0, 0, 0 } }, { gUnk_09EDED60, gUnk_09EDED80, gUnk_088DDAF6, 0, { 0, 0, 0 } }, { gUnk_09EDEA10, gUnk_09EDEA30, gUnk_088C2D72, 0, { 0, 0, 0 } }, { gUnk_09EDEA94, gUnk_09EDEAB4, gUnk_088C75A0, 0, { 0, 0, 0 } }, { gUnk_09EDEB8C, gUnk_09EDEBAC, gUnk_088CF9CE, 0, { 0, 0, 0 } } },
    { { gUnk_09EDE968, gUnk_09EDE984, gUnk_088BDB36, 0, { 0, 0, 0 } }, { gUnk_09EDED84, gUnk_09EDEDA0, gUnk_088DF374, 0, { 0, 0, 0 } }, { gUnk_09EDEA34, gUnk_09EDEA50, gUnk_088C439E, 0, { 0, 0, 0 } }, { gUnk_09EDEAB8, gUnk_09EDEAD4, gUnk_088C8DB2, 0, { 0, 0, 0 } }, { gUnk_09EDEBB0, gUnk_09EDEBCC, gUnk_088D1294, 0, { 0, 0, 0 } } },
    { { gUnk_09EDE968, gUnk_09EDE984, gUnk_088BDB36, 1, { 0, 0, 0 } }, { gUnk_09EDED84, gUnk_09EDEDA0, gUnk_088DF374, 1, { 0, 0, 0 } }, { gUnk_09EDEA34, gUnk_09EDEA50, gUnk_088C439E, 1, { 0, 0, 0 } }, { gUnk_09EDEAB8, gUnk_09EDEAD4, gUnk_088C8DB2, 1, { 0, 0, 0 } }, { gUnk_09EDEBB0, gUnk_09EDEBCC, gUnk_088D1294, 1, { 0, 0, 0 } } },
    { { gUnk_09EDE968, gUnk_09EDE984, gUnk_088BDB36, 2, { 0, 0, 0 } }, { gUnk_09EDED84, gUnk_09EDEDA0, gUnk_088DF374, 2, { 0, 0, 0 } }, { gUnk_09EDEA34, gUnk_09EDEA50, gUnk_088C439E, 2, { 0, 0, 0 } }, { gUnk_09EDEAB8, gUnk_09EDEAD4, gUnk_088C8DB2, 2, { 0, 0, 0 } }, { gUnk_09EDEBB0, gUnk_09EDEBCC, gUnk_088D1294, 2, { 0, 0, 0 } } },
    { { gUnk_09EDE968, gUnk_09EDE984, gUnk_088BDB36, 3, { 0, 0, 0 } }, { gUnk_09EDED84, gUnk_09EDEDA0, gUnk_088DF374, 3, { 0, 0, 0 } }, { gUnk_09EDEA34, gUnk_09EDEA50, gUnk_088C439E, 3, { 0, 0, 0 } }, { gUnk_09EDEAB8, gUnk_09EDEAD4, gUnk_088C8DB2, 3, { 0, 0, 0 } }, { gUnk_09EDEBB0, gUnk_09EDEBCC, gUnk_088D1294, 3, { 0, 0, 0 } } },
    { { gUnk_09EDE968, gUnk_09EDE984, gUnk_088BDB36, 4, { 0, 0, 0 } }, { gUnk_09EDED84, gUnk_09EDEDA0, gUnk_088DF374, 4, { 0, 0, 0 } }, { gUnk_09EDEA34, gUnk_09EDEA50, gUnk_088C439E, 4, { 0, 0, 0 } }, { gUnk_09EDEAB8, gUnk_09EDEAD4, gUnk_088C8DB2, 4, { 0, 0, 0 } }, { gUnk_09EDEBB0, gUnk_09EDEBCC, gUnk_088D1294, 4, { 0, 0, 0 } } },
};

u16 gUnk_0813C0DC[4][4] __attribute__((section(".rodata_btl_000"))) = {
    { 532, 533, 534, 535 },
    { 536, 537, 538, 539 },
    { 540, 541, 542, 543 },
    { 122, 123, 124, 125 },
};

s32 gUnk_0813C0FC[18] __attribute__((section(".rodata_btl_000"))) = {
    12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57, 60, 63,
};

s32 gUnk_0813C144[18] __attribute__((section(".rodata_btl_000"))) = {
    13, 16, 19, 22, 25, 28, 31, 34, 37, 40, 43, 46, 49, 52, 55, 58, 61, 64,
};

s32 gUnk_0813C18C[18] __attribute__((section(".rodata_btl_000"))) = {
    14, 17, 20, 23, 26, 29, 32, 35, 38, 41, 44, 47, 50, 53, 56, 59, 62, 65,
};

SoraAttackDef gUnk_0813C1D4 __attribute__((section(".rodata_btl_000"))) = { 2, gUnk_0813C0FC, 151, 500, 0, 0, 0, NULL };

SoraAttackDef gUnk_0813C1EC __attribute__((section(".rodata_btl_000"))) = { 7, gUnk_0813C144, 153, 501, 0, 0, 0, NULL };

SoraAttackDef gUnk_0813C204 __attribute__((section(".rodata_btl_000"))) = { 12, gUnk_0813C0FC, 151, 500, 0, 0, 0, NULL };

SoraAttackDef gUnk_0813C21C __attribute__((section(".rodata_btl_000"))) = { 17, gUnk_0813C18C, 155, 502, 0, 2, 0, NULL };

SoraAttackDef gUnk_0813C234 __attribute__((section(".rodata_btl_000"))) = { 27, gUnk_0813C0FC, 152, 501, -640, 1, 0, &gUnk_0813C1D4 };

SoraAttackDef gUnk_0813C24C __attribute__((section(".rodata_btl_000"))) = { 22, gUnk_0813C144, 150, 500, 0, 1, 0, &gUnk_0813C1D4 };

SoraAttackDef gUnk_0813C264 __attribute__((section(".rodata_btl_000"))) = { 27, gUnk_0813C0FC, 152, 501, 0, 1, 0, &gUnk_0813C1EC };

SoraAttackDef gUnk_0813C27C __attribute__((section(".rodata_btl_000"))) = { 32, gUnk_0813C18C, 155, 502, 0, 3, 0, &gUnk_0813C21C };

u8 gUnk_0813C294[5] __attribute__((section(".rodata_btl_000"))) = {
    10, 12, 15, 18, 20,
};

AnimDef gUnk_0813C2AC[35] __attribute__((section(".rodata_btl_001"))) = {
    { gUnk_09EDF374, gUnk_09EDF38C, gUnk_0891ED26, 0, { 0, 0, 0 } },
    { gUnk_09EDF428, gUnk_09EDF464, gUnk_0892935E, 1, { 0, 0, 0 } },
    { gUnk_09EDF404, gUnk_09EDF418, gUnk_08927806, 3, { 0, 0, 0 } },
    { gUnk_09EDF428, gUnk_09EDF464, gUnk_0892935E, 2, { 0, 0, 0 } },
    { gUnk_09EDF474, gUnk_09EDF498, gUnk_0892E268, 0, { 0, 0, 0 } },
    { gUnk_09EDF428, gUnk_09EDF464, gUnk_0892935E, 2, { 0, 0, 0 } },
    { gUnk_09EDF4A0, gUnk_09EDF4B8, gUnk_089315B4, 1, { 0, 0, 0 } },
    { gUnk_09EDF390, gUnk_09EDF3A8, gUnk_089209A6, 0, { 0, 0, 0 } },
    { gUnk_09EDF390, gUnk_09EDF3A8, gUnk_089209A6, 1, { 0, 0, 0 } },
    { gUnk_09EDF3B0, gUnk_09EDF3C4, gUnk_08922670, 0, { 0, 0, 0 } },
    { gUnk_09EDF3C8, gUnk_09EDF3E4, gUnk_08923C74, 0, { 0, 0, 0 } },
    { gUnk_09EDF3E8, gUnk_09EDF400, gUnk_08925B44, 0, { 0, 0, 0 } },
    { gUnk_09EE23B8, gUnk_09EE23D0, gUnk_08C492E2, 0, { 0, 0, 0 } },
    { gUnk_09EE23D8, gUnk_09EE23F8, gUnk_08C4AEA0, 0, { 0, 0, 0 } },
    { gUnk_09EE23FC, gUnk_09EE2410, gUnk_08C4D30E, 0, { 0, 0, 0 } },
    { gUnk_09EE2414, gUnk_09EE243C, gUnk_08C4EAE2, 0, { 0, 0, 0 } },
    { gUnk_09EE2414, gUnk_09EE243C, gUnk_08C4EAE2, 1, { 0, 0, 0 } },
    { gUnk_09EE2414, gUnk_09EE243C, gUnk_08C4EAE2, 2, { 0, 0, 0 } },
    { gUnk_09EE2414, gUnk_09EE243C, gUnk_08C4EAE2, 3, { 0, 0, 0 } },
    { gUnk_09EE2414, gUnk_09EE243C, gUnk_08C4EAE2, 4, { 0, 0, 0 } },
    { gUnk_09EE2458, gUnk_09EE2480, gUnk_08C51312, 0, { 0, 0, 0 } },
    { gUnk_09EE2490, gUnk_09EE24C0, gUnk_08C5411E, 0, { 0, 0, 0 } },
    { gUnk_09EE24C8, gUnk_09EE24E4, gUnk_08C579A4, 0, { 0, 0, 0 } },
    { gUnk_09EE24EC, gUnk_09EE2518, gUnk_08C5997A, 0, { 0, 0, 0 } },
    { gUnk_09EE24EC, gUnk_09EE2518, gUnk_08C5997A, 2, { 0, 0, 0 } },
    { gUnk_09EE25A8, gUnk_09EE25CC, gUnk_08C63E3C, 0, { 0, 0, 0 } },
    { gUnk_09EE2524, gUnk_09EE2554, gUnk_08C5C794, 0, { 0, 0, 0 } },
    { gUnk_09EE2524, gUnk_09EE2554, gUnk_08C5C794, 1, { 0, 0, 0 } },
    { gUnk_09EE2524, gUnk_09EE2554, gUnk_08C5C794, 2, { 0, 0, 0 } },
    { gUnk_09EE2560, gUnk_09EE2578, gUnk_08C5FFFA, 0, { 0, 0, 0 } },
    { gUnk_09EE2560, gUnk_09EE2578, gUnk_08C5FFFA, 1, { 0, 0, 0 } },
    { gUnk_09EE2560, gUnk_09EE2578, gUnk_08C5FFFA, 2, { 0, 0, 0 } },
    { gUnk_09EE2584, gUnk_09EE25A4, gUnk_08C61980, 0, { 0, 0, 0 } },
    { gUnk_09EE2458, gUnk_09EE2480, gUnk_08C51312, 1, { 0, 0, 0 } },
    { gUnk_09EE2458, gUnk_09EE2480, gUnk_08C51312, 3, { 0, 0, 0 } },
};

AnimDef gUnk_0813C4DC[6][5] __attribute__((section(".rodata_btl_001"))) = {
    { { gUnk_09EEFA70, gUnk_09EEFA90, gUnk_092FF906, 0, { 0, 0, 0 } }, { gUnk_09EEFA4C, gUnk_09EEFA6C, gUnk_092FDDC6, 0, { 0, 0, 0 } }, { gUnk_09EEF93C, gUnk_09EEF95C, gUnk_092F31E0, 0, { 0, 0, 0 } }, { gUnk_09EEF994, gUnk_09EEF9B4, gUnk_092F65A2, 0, { 0, 0, 0 } }, { gUnk_09EEF9B8, gUnk_09EEF9D8, gUnk_092F881A, 0, { 0, 0, 0 } } },
    { { gUnk_09EDF518, gUnk_09EDF530, gUnk_0893757C, 0, { 0, 0, 0 } }, { gUnk_09EDF544, gUnk_09EDF55C, gUnk_08938A14, 0, { 0, 0, 0 } }, { gUnk_09EDF570, gUnk_09EDF588, gUnk_08939F00, 0, { 0, 0, 0 } }, { gUnk_09EDF59C, gUnk_09EDF5B4, gUnk_0893B3D2, 0, { 0, 0, 0 } }, { gUnk_09EDF5C8, gUnk_09EDF5E0, gUnk_0893C7C6, 0, { 0, 0, 0 } } },
    { { gUnk_09EDF518, gUnk_09EDF530, gUnk_0893757C, 1, { 0, 0, 0 } }, { gUnk_09EDF544, gUnk_09EDF55C, gUnk_08938A14, 1, { 0, 0, 0 } }, { gUnk_09EDF570, gUnk_09EDF588, gUnk_08939F00, 1, { 0, 0, 0 } }, { gUnk_09EDF59C, gUnk_09EDF5B4, gUnk_0893B3D2, 1, { 0, 0, 0 } }, { gUnk_09EDF5C8, gUnk_09EDF5E0, gUnk_0893C7C6, 1, { 0, 0, 0 } } },
    { { gUnk_09EDF518, gUnk_09EDF530, gUnk_0893757C, 2, { 0, 0, 0 } }, { gUnk_09EDF544, gUnk_09EDF55C, gUnk_08938A14, 2, { 0, 0, 0 } }, { gUnk_09EDF570, gUnk_09EDF588, gUnk_08939F00, 2, { 0, 0, 0 } }, { gUnk_09EDF59C, gUnk_09EDF5B4, gUnk_0893B3D2, 2, { 0, 0, 0 } }, { gUnk_09EDF5C8, gUnk_09EDF5E0, gUnk_0893C7C6, 2, { 0, 0, 0 } } },
    { { gUnk_09EDF518, gUnk_09EDF530, gUnk_0893757C, 3, { 0, 0, 0 } }, { gUnk_09EDF544, gUnk_09EDF55C, gUnk_08938A14, 3, { 0, 0, 0 } }, { gUnk_09EDF570, gUnk_09EDF588, gUnk_08939F00, 3, { 0, 0, 0 } }, { gUnk_09EDF59C, gUnk_09EDF5B4, gUnk_0893B3D2, 3, { 0, 0, 0 } }, { gUnk_09EDF5C8, gUnk_09EDF5E0, gUnk_0893C7C6, 3, { 0, 0, 0 } } },
    { { gUnk_09EDF518, gUnk_09EDF530, gUnk_0893757C, 4, { 0, 0, 0 } }, { gUnk_09EDF544, gUnk_09EDF55C, gUnk_08938A14, 4, { 0, 0, 0 } }, { gUnk_09EDF570, gUnk_09EDF588, gUnk_08939F00, 4, { 0, 0, 0 } }, { gUnk_09EDF59C, gUnk_09EDF5B4, gUnk_0893B3D2, 4, { 0, 0, 0 } }, { gUnk_09EDF5C8, gUnk_09EDF5E0, gUnk_0893C7C6, 4, { 0, 0, 0 } } },
};

u16 gUnk_0813C6BC[4][4] __attribute__((section(".rodata_btl_001"))) = {
    { 532, 533, 534, 535 },
    { 536, 537, 538, 539 },
    { 540, 541, 542, 543 },
    { 122, 123, 124, 125 },
};

s32 gUnk_0813C6DC[3] __attribute__((section(".rodata_btl_001"))) = {
    0, 1, 2,
};

RikuAttackDef gUnk_0813C6E8 __attribute__((section(".rodata_btl_001"))) = { 1, 15, 0, gUnk_0813C6DC, 255, 655, 0, 0, 0, NULL };

RikuAttackDef gUnk_0813C704 __attribute__((section(".rodata_btl_001"))) = { 2, 17, 0, &gUnk_0813C6DC[1], 254, 656, 0, 0, 0, NULL };

RikuAttackDef gUnk_0813C720 __attribute__((section(".rodata_btl_001"))) = { 3, 15, 0, gUnk_0813C6DC, 256, 655, 0, 0, 0, NULL };

RikuAttackDef gUnk_0813C73C __attribute__((section(".rodata_btl_001"))) = { 4, 21, 0, &gUnk_0813C6DC[2], 258, 657, 0, 0, 0, NULL };

RikuAttackDef gUnk_0813C758 __attribute__((section(".rodata_btl_001"))) = { 6, 15, 0, gUnk_0813C6DC, 256, 656, -640, 1, 0, &gUnk_0813C6E8 };

RikuAttackDef gUnk_0813C774 __attribute__((section(".rodata_btl_001"))) = { 5, 15, 0, &gUnk_0813C6DC[1], 254, 655, 0, 1, 0, &gUnk_0813C6E8 };

RikuAttackDef gUnk_0813C790 __attribute__((section(".rodata_btl_001"))) = { 5, 15, 0, gUnk_0813C6DC, 255, 656, 0, 1, 0, &gUnk_0813C704 };

RikuAttackDef gUnk_0813C7AC __attribute__((section(".rodata_btl_001"))) = { 6, 15, 0, &gUnk_0813C6DC[2], 257, 657, 0, 1, 0, &gUnk_0813C73C };

const s8 gUnk_0813C7D8[32] __attribute__((section(".rodata_btl_002"))) = {
    4, 4, 4, 4, -4, -4, -4, -4, 3, 3, 3, 3, -3, -3, -3, -3, 2, 2, 2, 2, -2, -2, -2, -2, 1, 1, 1, 1, -1, -1, -1, -1,
};
