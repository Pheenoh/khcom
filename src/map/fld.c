#include "task_descriptors.h"
#include "map_api.h"
#include "fld.h"
#include "gba/keys.h"
#include "task_animation_assets.h"
#include "sprites_btl.h"
#include "sprites_evt.h"
#include "sprites_fld.h"
#include "sprites_riku.h"
#include "sprites_sora.h"
#include "world_types.h"

const AnimDef gUnk_0813C89C[15][5] = {
    { { gSor1bb00Frames, gSor1bb00Anims, gSor1bb00Tiles, 0, { 0, 0, 0 } }, { gSor1ff00Frames, gSor1ff00Anims, gSor1ff00Tiles, 0, { 0, 0, 0 } }, { gSor1fl00Frames, gSor1fl00Anims, gSor1fl00Tiles, 0, { 0, 0, 0 } }, { gSor1ll00Frames, gSor1ll00Anims, gSor1ll00Tiles, 0, { 0, 0, 0 } }, { gSor1bl00Frames, gSor1bl00Anims, gSor1bl00Tiles, 0, { 0, 0, 0 } } },
    { { gSor1bb01Frames, gSor1bb01Anims, gSor1bb01Tiles, 0, { 0, 0, 0 } }, { gSor1ff01Frames, gSor1ff01Anims, gSor1ff01Tiles, 0, { 0, 0, 0 } }, { gSor1fl01Frames, gSor1fl01Anims, gSor1fl01Tiles, 0, { 0, 0, 0 } }, { gSor1ll01Frames, gSor1ll01Anims, gSor1ll01Tiles, 0, { 0, 0, 0 } }, { gSor1bl01Frames, gSor1bl01Anims, gSor1bl01Tiles, 0, { 0, 0, 0 } } },
    { { gSor1bb02Frames, gSor1bb02Anims, gSor1bb02Tiles, 0, { 0, 0, 0 } }, { gSor1ff02Frames, gSor1ff02Anims, gSor1ff02Tiles, 0, { 0, 0, 0 } }, { gSor1fl02Frames, gSor1fl02Anims, gSor1fl02Tiles, 0, { 0, 0, 0 } }, { gSor1ll02Frames, gSor1ll02Anims, gSor1ll02Tiles, 0, { 0, 0, 0 } }, { gSor1bl02Frames, gSor1bl02Anims, gSor1bl02Tiles, 0, { 0, 0, 0 } } },
    { { gSor1bb03Frames, gSor1bb03Anims, gSor1bb03Tiles, 0, { 0, 0, 0 } }, { gSor1ff03Frames, gSor1ff03Anims, gSor1ff03Tiles, 0, { 0, 0, 0 } }, { gSor1fl03Frames, gSor1fl03Anims, gSor1fl03Tiles, 0, { 0, 0, 0 } }, { gSor1ll03Frames, gSor1ll03Anims, gSor1ll03Tiles, 0, { 0, 0, 0 } }, { gSor1bl03Frames, gSor1bl03Anims, gSor1bl03Tiles, 0, { 0, 0, 0 } } },
    { { gSor1bb03Frames, gSor1bb03Anims, gSor1bb03Tiles, 1, { 0, 0, 0 } }, { gSor1ff03Frames, gSor1ff03Anims, gSor1ff03Tiles, 1, { 0, 0, 0 } }, { gSor1fl03Frames, gSor1fl03Anims, gSor1fl03Tiles, 1, { 0, 0, 0 } }, { gSor1ll03Frames, gSor1ll03Anims, gSor1ll03Tiles, 1, { 0, 0, 0 } }, { gSor1bl03Frames, gSor1bl03Anims, gSor1bl03Tiles, 1, { 0, 0, 0 } } },
    { { gSor1bb03Frames, gSor1bb03Anims, gSor1bb03Tiles, 2, { 0, 0, 0 } }, { gSor1ff03Frames, gSor1ff03Anims, gSor1ff03Tiles, 2, { 0, 0, 0 } }, { gSor1fl03Frames, gSor1fl03Anims, gSor1fl03Tiles, 2, { 0, 0, 0 } }, { gSor1ll03Frames, gSor1ll03Anims, gSor1ll03Tiles, 2, { 0, 0, 0 } }, { gSor1bl03Frames, gSor1bl03Anims, gSor1bl03Tiles, 2, { 0, 0, 0 } } },
    { { gSor1bb03Frames, gSor1bb03Anims, gSor1bb03Tiles, 3, { 0, 0, 0 } }, { gSor1ff03Frames, gSor1ff03Anims, gSor1ff03Tiles, 3, { 0, 0, 0 } }, { gSor1fl03Frames, gSor1fl03Anims, gSor1fl03Tiles, 3, { 0, 0, 0 } }, { gSor1ll03Frames, gSor1ll03Anims, gSor1ll03Tiles, 3, { 0, 0, 0 } }, { gSor1bl03Frames, gSor1bl03Anims, gSor1bl03Tiles, 3, { 0, 0, 0 } } },
    { { gSor1bb03Frames, gSor1bb03Anims, gSor1bb03Tiles, 4, { 0, 0, 0 } }, { gSor1ff03Frames, gSor1ff03Anims, gSor1ff03Tiles, 4, { 0, 0, 0 } }, { gSor1fl03Frames, gSor1fl03Anims, gSor1fl03Tiles, 4, { 0, 0, 0 } }, { gSor1ll03Frames, gSor1ll03Anims, gSor1ll03Tiles, 4, { 0, 0, 0 } }, { gSor1bl03Frames, gSor1bl03Anims, gSor1bl03Tiles, 4, { 0, 0, 0 } } },
    { { gSor1bl05Frames, gSor1bl05Anims, gSor1bl05Tiles, 0, { 0, 0, 0 } }, { gSor1bl05Frames, gSor1bl05Anims, gSor1bl05Tiles, 0, { 0, 0, 0 } }, { gSor1bl05Frames, gSor1bl05Anims, gSor1bl05Tiles, 0, { 0, 0, 0 } }, { gSor1bl05Frames, gSor1bl05Anims, gSor1bl05Tiles, 0, { 0, 0, 0 } }, { gSor1bl05Frames, gSor1bl05Anims, gSor1bl05Tiles, 0, { 0, 0, 0 } } },
    { { gSor1bb11Frames, gSor1bb11Anims, gSor1bb11Tiles, 0, { 0, 0, 0 } }, { gSor1bl11Frames, gSor1bl11Anims, gSor1bl11Tiles, 0, { 0, 0, 0 } }, { gSor1bl11Frames, gSor1bl11Anims, gSor1bl11Tiles, 0, { 0, 0, 0 } }, { gSor1bl11Frames, gSor1bl11Anims, gSor1bl11Tiles, 0, { 0, 0, 0 } }, { gSor1bl11Frames, gSor1bl11Anims, gSor1bl11Tiles, 0, { 0, 0, 0 } } },
    { { gSor1bb11Frames, gSor1bb11Anims, gSor1bb11Tiles, 1, { 0, 0, 0 } }, { gSor1bl11Frames, gSor1bl11Anims, gSor1bl11Tiles, 1, { 0, 0, 0 } }, { gSor1bl11Frames, gSor1bl11Anims, gSor1bl11Tiles, 1, { 0, 0, 0 } }, { gSor1bl11Frames, gSor1bl11Anims, gSor1bl11Tiles, 1, { 0, 0, 0 } }, { gSor1bl11Frames, gSor1bl11Anims, gSor1bl11Tiles, 1, { 0, 0, 0 } } },
    { { gSor1bb11Frames, gSor1bb11Anims, gSor1bb11Tiles, 2, { 0, 0, 0 } }, { gSor1bl11Frames, gSor1bl11Anims, gSor1bl11Tiles, 2, { 0, 0, 0 } }, { gSor1bl11Frames, gSor1bl11Anims, gSor1bl11Tiles, 2, { 0, 0, 0 } }, { gSor1bl11Frames, gSor1bl11Anims, gSor1bl11Tiles, 2, { 0, 0, 0 } }, { gSor1bl11Frames, gSor1bl11Anims, gSor1bl11Tiles, 2, { 0, 0, 0 } } },
    { { gSor1bl15Frames, gSor1bl15Anims, gSor1bl15Tiles, 0, { 0, 0, 0 } }, { gSor1fl15Frames, gSor1fl15Anims, gSor1fl15Tiles, 0, { 0, 0, 0 } }, { gSor1fl15Frames, gSor1fl15Anims, gSor1fl15Tiles, 0, { 0, 0, 0 } }, { gSor1fl15Frames, gSor1fl15Anims, gSor1fl15Tiles, 0, { 0, 0, 0 } }, { gSor1bl15Frames, gSor1bl15Anims, gSor1bl15Tiles, 0, { 0, 0, 0 } } },
    { { gSor1bb10Frames, gSor1bb10Anims, gSor1bb10Tiles, 0, { 0, 0, 0 } }, { gSor1ff10Frames, gSor1ff10Anims, gSor1ff10Tiles, 0, { 0, 0, 0 } }, { gSor1fl10Frames, gSor1fl10Anims, gSor1fl10Tiles, 0, { 0, 0, 0 } }, { gSor1ll10Frames, gSor1ll10Anims, gSor1ll10Tiles, 0, { 0, 0, 0 } }, { gSor1bl10Frames, gSor1bl10Anims, gSor1bl10Tiles, 0, { 0, 0, 0 } } },
    { { gSor1bb61Frames, gSor1bb61Anims, gSor1bb61Tiles, 0, { 0, 0, 0 } }, { gSor1ff61Frames, gSor1ff61Anims, gSor1ff61Tiles, 0, { 0, 0, 0 } }, { gSor1fl61Frames, gSor1fl61Anims, gSor1fl61Tiles, 0, { 0, 0, 0 } }, { gSor1ll61Frames, gSor1ll61Anims, gSor1ll61Tiles, 0, { 0, 0, 0 } }, { gSor1bl61Frames, gSor1bl61Anims, gSor1bl61Tiles, 0, { 0, 0, 0 } } },
};

const u16 gUnk_0813CD4C[8][8] = {
    { 122, 123, 124, 125, 122, 123, 135, 0 },
    { 122, 123, 124, 125, 122, 123, 135, 0 },
    { 126, 127, 128, 129, 126, 127, 136, 0 },
    { 126, 127, 128, 129, 126, 127, 136, 0 },
    { 109, 110, 111, 112, 133, 133, 134, 0 },
    { 122, 123, 124, 125, 122, 123, 135, 0 },
    { 122, 123, 124, 125, 122, 123, 135, 0 },
    { 109, 110, 111, 112, 122, 123, 135, 0 },
};

TaskDesc gTaskDescFldSora = { "task_fld_sora", task_fld_sora_0, task_fld_sora_1, task_fld_sora_2, task_fld_sora_3, 0xC0 };

const AnimDef gUnk_0813CDDC[15][5] = {
    { { gUnk_09EDF4C0, gUnk_09EDF4C4, gUnk_08933A34, 0, { 0, 0, 0 } }, { gRikuFf00Frames, gRikuFf00Anims, gRikuFf00Tiles, 0, { 0, 0, 0 } }, { gRikuFl00Frames, gRikuFl00Anims, gRikuFl00Tiles, 0, { 0, 0, 0 } }, { gUnk_09EDF4C8, gUnk_09EDF4CC, gUnk_08933D94, 0, { 0, 0, 0 } }, { gRikuBl00Frames, gRikuBl00Anims, gRikuBl00Tiles, 0, { 0, 0, 0 } } },
    { { gUnk_09EDF4F4, gUnk_09EDF514, gUnk_08935BC2, 0, { 0, 0, 0 } }, { gUnk_09EDF4D0, gUnk_09EDF4F0, gUnk_0893416A, 0, { 0, 0, 0 } }, { gRik1fl01Frames, gRik1fl01Anims, gRik1fl01Tiles, 0, { 0, 0, 0 } }, { gRik1ll01Frames, gRik1ll01Anims, gRik1ll01Tiles, 0, { 0, 0, 0 } }, { gRik1bl01Frames, gRik1bl01Anims, gRik1bl01Tiles, 0, { 0, 0, 0 } } },
    { { gRik1bb02Frames, gRik1bb02Anims, gRik1bb02Tiles, 0, { 0, 0, 0 } }, { gRik1ff02Frames, gRik1ff02Anims, gRik1ff02Tiles, 0, { 0, 0, 0 } }, { gRik1fl02Frames, gRik1fl02Anims, gRik1fl02Tiles, 0, { 0, 0, 0 } }, { gRik1ll02Frames, gRik1ll02Anims, gRik1ll02Tiles, 0, { 0, 0, 0 } }, { gRik1bl02Frames, gRik1bl02Anims, gRik1bl02Tiles, 0, { 0, 0, 0 } } },
    { { gRik1bb03Frames, gRik1bb03Anims, gRik1bb03Tiles, 0, { 0, 0, 0 } }, { gRik1ff03Frames, gRik1ff03Anims, gRik1ff03Tiles, 0, { 0, 0, 0 } }, { gRik1fl03Frames, gRik1fl03Anims, gRik1fl03Tiles, 0, { 0, 0, 0 } }, { gRik1ll03Frames, gRik1ll03Anims, gRik1ll03Tiles, 0, { 0, 0, 0 } }, { gRik1bl03Frames, gRik1bl03Anims, gRik1bl03Tiles, 0, { 0, 0, 0 } } },
    { { gRik1bb03Frames, gRik1bb03Anims, gRik1bb03Tiles, 1, { 0, 0, 0 } }, { gRik1ff03Frames, gRik1ff03Anims, gRik1ff03Tiles, 1, { 0, 0, 0 } }, { gRik1fl03Frames, gRik1fl03Anims, gRik1fl03Tiles, 1, { 0, 0, 0 } }, { gRik1ll03Frames, gRik1ll03Anims, gRik1ll03Tiles, 1, { 0, 0, 0 } }, { gRik1bl03Frames, gRik1bl03Anims, gRik1bl03Tiles, 1, { 0, 0, 0 } } },
    { { gRik1bb03Frames, gRik1bb03Anims, gRik1bb03Tiles, 2, { 0, 0, 0 } }, { gRik1ff03Frames, gRik1ff03Anims, gRik1ff03Tiles, 2, { 0, 0, 0 } }, { gRik1fl03Frames, gRik1fl03Anims, gRik1fl03Tiles, 2, { 0, 0, 0 } }, { gRik1ll03Frames, gRik1ll03Anims, gRik1ll03Tiles, 2, { 0, 0, 0 } }, { gRik1bl03Frames, gRik1bl03Anims, gRik1bl03Tiles, 2, { 0, 0, 0 } } },
    { { gRik1bb03Frames, gRik1bb03Anims, gRik1bb03Tiles, 3, { 0, 0, 0 } }, { gRik1ff03Frames, gRik1ff03Anims, gRik1ff03Tiles, 3, { 0, 0, 0 } }, { gRik1fl03Frames, gRik1fl03Anims, gRik1fl03Tiles, 3, { 0, 0, 0 } }, { gRik1ll03Frames, gRik1ll03Anims, gRik1ll03Tiles, 3, { 0, 0, 0 } }, { gRik1bl03Frames, gRik1bl03Anims, gRik1bl03Tiles, 3, { 0, 0, 0 } } },
    { { gRik1bb03Frames, gRik1bb03Anims, gRik1bb03Tiles, 4, { 0, 0, 0 } }, { gRik1ff03Frames, gRik1ff03Anims, gRik1ff03Tiles, 4, { 0, 0, 0 } }, { gRik1fl03Frames, gRik1fl03Anims, gRik1fl03Tiles, 4, { 0, 0, 0 } }, { gRik1ll03Frames, gRik1ll03Anims, gRik1ll03Tiles, 4, { 0, 0, 0 } }, { gRik1bl03Frames, gRik1bl03Anims, gRik1bl03Tiles, 4, { 0, 0, 0 } } },
    { { gUnk_09EDF5F4, gUnk_09EDF60C, gUnk_0893DCDC, 0, { 0, 0, 0 } }, { gUnk_09EDF5F4, gUnk_09EDF60C, gUnk_0893DCDC, 0, { 0, 0, 0 } }, { gUnk_09EDF5F4, gUnk_09EDF60C, gUnk_0893DCDC, 0, { 0, 0, 0 } }, { gUnk_09EDF5F4, gUnk_09EDF60C, gUnk_0893DCDC, 0, { 0, 0, 0 } }, { gUnk_09EDF5F4, gUnk_09EDF60C, gUnk_0893DCDC, 0, { 0, 0, 0 } } },
    { { gUnk_09EDF640, gUnk_09EDF660, gUnk_08940D90, 0, { 0, 0, 0 } }, { gUnk_09EDF614, gUnk_09EDF634, gUnk_0893F080, 0, { 0, 0, 0 } }, { gUnk_09EDF614, gUnk_09EDF634, gUnk_0893F080, 0, { 0, 0, 0 } }, { gUnk_09EDF614, gUnk_09EDF634, gUnk_0893F080, 0, { 0, 0, 0 } }, { gUnk_09EDF614, gUnk_09EDF634, gUnk_0893F080, 0, { 0, 0, 0 } } },
    { { gUnk_09EDF640, gUnk_09EDF660, gUnk_08940D90, 1, { 0, 0, 0 } }, { gUnk_09EDF614, gUnk_09EDF634, gUnk_0893F080, 1, { 0, 0, 0 } }, { gUnk_09EDF614, gUnk_09EDF634, gUnk_0893F080, 1, { 0, 0, 0 } }, { gUnk_09EDF614, gUnk_09EDF634, gUnk_0893F080, 1, { 0, 0, 0 } }, { gUnk_09EDF614, gUnk_09EDF634, gUnk_0893F080, 1, { 0, 0, 0 } } },
    { { gUnk_09EDF640, gUnk_09EDF660, gUnk_08940D90, 2, { 0, 0, 0 } }, { gUnk_09EDF614, gUnk_09EDF634, gUnk_0893F080, 2, { 0, 0, 0 } }, { gUnk_09EDF614, gUnk_09EDF634, gUnk_0893F080, 2, { 0, 0, 0 } }, { gUnk_09EDF614, gUnk_09EDF634, gUnk_0893F080, 2, { 0, 0, 0 } }, { gUnk_09EDF614, gUnk_09EDF634, gUnk_0893F080, 2, { 0, 0, 0 } } },
    { { gUnk_09EDF680, gUnk_09EDF68C, gUnk_089434C8, 0, { 0, 0, 0 } }, { gUnk_09EDF66C, gUnk_09EDF678, gUnk_089429AE, 0, { 0, 0, 0 } }, { gUnk_09EDF66C, gUnk_09EDF678, gUnk_089429AE, 0, { 0, 0, 0 } }, { gUnk_09EDF66C, gUnk_09EDF678, gUnk_089429AE, 0, { 0, 0, 0 } }, { gUnk_09EDF680, gUnk_09EDF68C, gUnk_089434C8, 0, { 0, 0, 0 } } },
    { { gRik1bb10Frames, gRik1bb10Anims, gRik1bb10Tiles, 0, { 0, 0, 0 } }, { gRik1ff10Frames, gRik1ff10Anims, gRik1ff10Tiles, 0, { 0, 0, 0 } }, { gRik1fl10Frames, gRik1fl10Anims, gRik1fl10Tiles, 0, { 0, 0, 0 } }, { gRikuBt11Frames, gRikuBt11Anims, gRikuBt11Tiles, 0, { 0, 0, 0 } }, { gRik1bl10Frames, gRik1bl10Anims, gRik1bl10Tiles, 0, { 0, 0, 0 } } },
    { { gRikuBb17Frames, gRikuBb17Anims, gRikuBb17Tiles, 0, { 0, 0, 0 } }, { gRikuFf17Frames, gRikuFf17Anims, gRikuFf17Tiles, 0, { 0, 0, 0 } }, { gRikuFl17Frames, gRikuFl17Anims, gRikuFl17Tiles, 0, { 0, 0, 0 } }, { gRikuLl17Frames, gRikuLl17Anims, gRikuLl17Tiles, 0, { 0, 0, 0 } }, { gRikuBl17Frames, gRikuBl17Anims, gRikuBl17Tiles, 0, { 0, 0, 0 } } },
};

const u16 gUnk_0813D28C[8][8] = {
    { 122, 123, 124, 125, 122, 123, 135, 0 },
    { 122, 123, 124, 125, 122, 123, 135, 0 },
    { 126, 127, 128, 129, 126, 127, 136, 0 },
    { 126, 127, 128, 129, 126, 127, 136, 0 },
    { 109, 110, 111, 112, 133, 133, 134, 0 },
    { 122, 123, 124, 125, 122, 123, 135, 0 },
    { 122, 123, 124, 125, 122, 123, 135, 0 },
    { 109, 110, 111, 112, 122, 123, 135, 0 },
};

void func_08031BC4(FldActor* act) {
    if ((GetKeysHeld() & DPAD_LEFT) && (GetKeysHeld() & DPAD_DOWN)) {
        act->angle = 173;
    } else if ((GetKeysHeld() & DPAD_UP) && (GetKeysHeld() & DPAD_LEFT)) {
        act->angle = 211;
    } else if ((GetKeysHeld() & DPAD_UP) && (GetKeysHeld() & DPAD_RIGHT)) {
        act->angle = 45;
    } else if ((GetKeysHeld() & DPAD_RIGHT) && (GetKeysHeld() & DPAD_DOWN)) {
        act->angle = 83;
    } else if ((GetKeysHeld() & DPAD_DOWN) && GetKeyReleaseTime(DPAD_LEFT) <= 4) {
        act->angle = 173;
    } else if ((GetKeysHeld() & DPAD_DOWN) && GetKeyReleaseTime(DPAD_RIGHT) <= 4) {
        act->angle = 83;
    } else if ((GetKeysHeld() & DPAD_UP) && GetKeyReleaseTime(DPAD_LEFT) <= 4) {
        act->angle = 211;
    } else if ((GetKeysHeld() & DPAD_UP) && GetKeyReleaseTime(DPAD_RIGHT) <= 4) {
        act->angle = 45;
    } else if ((GetKeysHeld() & DPAD_LEFT) && GetKeyReleaseTime(DPAD_UP) <= 4) {
        act->angle = 211;
    } else if ((GetKeysHeld() & DPAD_LEFT) && GetKeyReleaseTime(DPAD_DOWN) <= 4) {
        act->angle = 173;
    } else if ((GetKeysHeld() & DPAD_RIGHT) && GetKeyReleaseTime(DPAD_UP) <= 4) {
        act->angle = 45;
    } else if ((GetKeysHeld() & DPAD_RIGHT) && GetKeyReleaseTime(DPAD_DOWN) <= 4) {
        act->angle = 83;
    } else if (GetKeysHeld() & DPAD_DOWN) {
        act->angle = 128;
    } else if (GetKeysHeld() & DPAD_UP) {
        act->angle = 0;
    } else if (GetKeysHeld() & DPAD_LEFT) {
        act->angle = 192;
    } else if (GetKeysHeld() & DPAD_RIGHT) {
        act->angle = 64;
    }
}

u8 func_08031D74(FldPos* p) {
    FldPos a;
    FldPos b;
    s32 v1;
    s32 v2;

    a = *p;
    b = *p;
    a.y -= 1536;
    b.y += 1536;

    v1 = func_080DFF1C(&a);
    if (v1 > a.unk_0C) {
        a.unk_0C = v1;
    }
    v2 = func_080DFF1C(&b);
    if (v2 > b.unk_0C) {
        b.unk_0C = v2;
    }

    if (func_080DFBDC(&a) != 0) {
        return 1;
    }

    if (func_080DFBDC(&b) != 0) {
        return 1;
    }
    p->unk_0C = v2 > v1 ? v1 : v2;
    return 0;
}

s32 func_08031DF8(FldPos* p) {
    FldPos a;
    FldPos b;
    s32 v1;
    s32 v2;

    a = *p;
    b = *p;
    a.y -= 1536;
    b.y += 1536;
    v1 = func_080DFF1C(&a);
    v2 = func_080DFF1C(&b);
    if (v2 > v1) {
        v2 = v1;
    }
    return v2;
}

u8 func_08031E48(FldPos* p, FldWork* work) {
    FldPos a;
    FldPos b;
    u8 r;

    a = *p;
    b = *p;
    a.y -= 1536;
    b.y += 1536;

    r = _080DFE1C(&a);
    if (r != 0) {
        work->unk_B0 = a.x;
        work->unk_B4 = a.y;
        return r;
    }
    r = _080DFE1C(&b);
    if (r != 0) {
        work->unk_B0 = b.x;
        work->unk_B4 = b.y;
        return r;
    }
    return 0;
}

u8 func_08031EC4(FldActor* act) {
    FldPos a;

    a = act->fieldPosition;
    a.x += gSineTable[act->angle] * 8;
    a.y -= gSineTable[act->angle + 64] * 8;

    if (func_080DFCDC(&a) != 0) {
        return 1;
    }
    return 0;
}

s32 func_08031F1C(FldWork* work) {
    FldActor* act;
    s32 v;

    act = &gFieldState->actor;

    if (work->flags & 1) {
        if (act->fieldPosition.unk_0C < work->unk_78) {
            v = act->fieldPosition.unk_0C;
        } else {
            v = work->unk_78;
        }

        work->unk_BC = 1;
    } else {
        work->unk_BC = 0;
        v = act->fieldPosition.unk_0C;
    }

    return v;
}

void func_08031F60(FldActor* act) {
    u8 old = act->angle;

    func_08031BC4(act);

    if (old != act->angle) {
        s32 v;

        if (abs((s8)GetAngleDiff(old, act->angle)) > 100) {
            v = 0;
        } else {
            v = act->unk_10 >> 1;
        }
        act->unk_10 = v;
    }
}

void func_08031F98(FldWork* work, s32 a, s32 b) {
    const FldAnimDef* e;
    u16 flags = b;
    s32 idx;

    switch (gFieldState->actor.angle) {
    case 45:
        idx = 4;
        work->unk_A4 |= 2;
        break;
    case 64:
        idx = 3;
        work->unk_A4 |= 2;
        break;
    case 83:
        idx = 2;
        work->unk_A4 |= 2;
        break;
    case 128:
        idx = 1;
        work->unk_A4 &= 0xFFFD;
        break;
    case 173:
        idx = 2;
        work->unk_A4 &= 0xFFFD;
        break;
    case 192:
        idx = 3;
        work->unk_A4 &= 0xFFFD;
        break;
    case 211:
        idx = 4;
        work->unk_A4 &= 0xFFFD;
        break;
    case 0:
    default:
        idx = 0;
        work->unk_A4 &= 0xFFFD;
        break;
    }

    if (work->unk_A8 == a) {
        flags |= 4;
    }
    work->unk_A8 = a;

    e = &gUnk_0813C89C[a][idx];
    AnimChangeWithTables(&work->anim, e->animId, flags, e->anims, e->gfxTable);
    SetObjTileSource(work->tiles, e->tiles);
}

void task_fld_sora_0(FldWork* work) {
    FldActor* act;

    act = &gFieldState->actor;
    work->tiles = AllocObjTiles(0x500, 0);
    work->palette = LoadObjPalette(gSoraPalette, 32);
    act->unk_1A = 16;
    work->unk_BC = 0;
    work->unk_9C = 0;
    work->unk_9D = 0;
    work->unk_9E = 0;
    work->unk_98 = 0;
    work->unk_A4 = 8;
    work->unk_A8 = 16;
    act->unk_32 = 0;
    act->unk_30 = 0;

    if (gGameState.unk_000 != 0) {
        act->fieldPosition = gGameState.fieldPosition;
        act->angle = gGameState.unk_024;
        act->unk_10 = gGameState.unk_028;
        work->unk_94 = gGameState.unk_030;
        work->unk_A0 = gGameState.unk_02C;
        work->unk_B0 = gGameState.unk_034;
        work->unk_B4 = gGameState.unk_038;
        work->unk_B8 = gGameState.unk_03C;
    } else {
        act->fieldPosition.x = gFieldState->unk_DC;
        act->fieldPosition.y = gFieldState->unk_E0;
        act->fieldPosition.z = 0;
        act->angle = gFieldState->unk_E4;
        func_080DFF4C(&act->fieldPosition);
        act->fieldPosition.z = act->fieldPosition.unk_0C;
        act->fieldPosition.y -= act->fieldPosition.unk_0C;
        act->unk_10 = 0;
        work->unk_94 = 0;
        work->unk_A0 = 0;
    }

    AnimInit(work->anim, 0, 0);
    func_08031F98(work, 0, 1);
    work->gfx = AnimGetGfx(work->anim);

    switch (gGameState.world) {
    case WORLD_NEVER_LAND:
        work->unk_AC = gUnk_0813CD4C[1];
        break;
    case WORLD_ATLANTICA:
        work->unk_AC = gUnk_0813CD4C[2];
        break;
    case WORLD_MONSTRO:
        work->unk_AC = gUnk_0813CD4C[3];
        break;
    case WORLD_WONDERLAND:
        work->unk_AC = gUnk_0813CD4C[4];
        break;
    case WORLD_HALLOWEEN_TOWN:
        work->unk_AC = gUnk_0813CD4C[5];
        break;
    case 0:
    case WORLD_OLYMPUS_COLISEUM:
    case WORLD_CASTLE_OBLIVION:
        work->unk_AC = gUnk_0813CD4C[6];
        break;
    case WORLD_DESTINY_ISLANDS:
        work->unk_AC = gUnk_0813CD4C[7];
        break;
    default:
        work->unk_AC = gUnk_0813CD4C[0];
        break;
    }

    TaskPoolInit(work->tasks, 2);
    TaskCreate(work->tasks, &gTaskDescFldShadow, &gFieldState->actor);
    ColliderInit(work->unk_38, 1, 4, 32);
    ColliderSetPosition(work->unk_38, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
}
u8 func_08032268(FldWork* work, void* task) {
    FldActor* act;
    s16* p;
    s32 flags;

    act = &gFieldState->actor;
    flags = gFieldState->flags;

    if (flags & 0x100000) {
        func_08031F98(work, 12, 0);
    } else if (flags & 0x80000) {
        func_08031F98(work, 1, 1);
    } else {
        func_08031F98(work, 0, 1);
    }

    if ((gFieldState->flags & 0x40000) == 0) {
        FadeSetPaletteExcluded(work->palette->index + 16, 0);
        work->unk_94 = 0;
        work->unk_98 = 0;
        SetTaskUpdate(task, (TaskUpdateFunc)task_fld_sora_1);
        TaskPoolUpdate(work->tasks);
    } else {
        p = &work->unk_98;

        if (*p == 0) {
            FadeSetPaletteExcluded(work->palette->index + 16, 1);
            act->unk_10 = 0;
            work->unk_BC = 0;
        }

        TaskPoolUpdate(work->tasks);
        work->gfx = AnimUpdate(work->anim);
        ColliderSetPosition(work->unk_38, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
        (*p)++;
    }

    return 1;
}
u8 func_0803234C(FldWork* work, void* task) {
    FldActor* act;
    s32 x;
    s32 y;
    s32 z;

    act = &gFieldState->actor;
    x = act->fieldPosition.x;
    y = act->fieldPosition.y;
    gFieldState->unk_68 = 0;

    switch (work->unk_94) {
    case 13:
        m4aSongNumStart(SONG_SYS_GIMICJP);
        work->unk_94 = 14;
        work->unk_A0 = -0x800;
        work->unk_98 = 0;
        act->unk_10 = 0;
        work->unk_B0 = work->unk_7C;
        work->unk_B4 = work->unk_80;
    case 14:
        if (work->unk_A0 > -0x300) {
            func_08031F98(work, 11, 0);
            act->unk_10 = 0x180;
            act->fieldPosition.x += gSineTable[act->angle] * act->unk_10 >> 8;
            act->fieldPosition.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;
        } else {
            func_08031F98(work, 4, 0);
            act->fieldPosition.x += (work->unk_B0 - act->fieldPosition.x) >> 3;
            act->fieldPosition.y += (work->unk_B4 - act->fieldPosition.y) >> 3;
        }

        work->unk_A0 = (work->unk_B8 - (z = act->fieldPosition.z + 0xF00)) >> 3;
        act->fieldPosition.z += work->unk_A0;
        work->unk_A0 += 0x42;

        if (work->unk_A0 >= 0) {
            work->unk_98 = 0;
            work->unk_94 = 4;
            work->unk_A4 |= 4;
            SetTaskUpdate(task, (TaskUpdateFunc)func_080324DC);
        } else {
            work->unk_98++;
        }

        break;
    }

    if (func_08031D74(&act->fieldPosition) != 0) {
        act->fieldPosition.x = x;
        act->fieldPosition.y = y;
    }

    ColliderSetPosition(work->unk_38, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
    func_080E0298(act->fieldPosition.x, act->fieldPosition.y + act->fieldPosition.z);
    work->gfx = AnimUpdate(work->anim);
    TaskPoolUpdate(work->tasks);
    return 1;
}
u8 func_080324DC(FldWork* work, void* task) {
    FldPos p1;
    FldPos p2;
    s32 sx;
    s32 sy;
    s32 nx;
    s32 ny;
    s32 z;
    FldActor* act;

    act = &gFieldState->actor;
    z = func_08031F1C(work);
    sx = act->fieldPosition.x;
    sy = act->fieldPosition.y;
    gFieldState->unk_68 = 0;

    if ((work->unk_A4 & 4) == 0) {
        func_08031F60(act);
    }

    switch (work->unk_94) {
    case 12:
        if (work->unk_98 == 0) {
            gFieldState->unk_68 = 0;
            func_08031F98(work, 14, 0);
        }

        act->fieldPosition.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->fieldPosition.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;

        if (AnimGetFrame(work->anim) > 3) {
            act->fieldPosition.z += work->unk_A0;
            work->unk_A0 += 66;

            if (act->fieldPosition.z > z) {
                act->fieldPosition.z = z;
                work->unk_A0 = 0;
            }
        } else {
            work->unk_A0 = 0;
        }

        act->unk_10 -= 38;

        if (act->unk_10 < 0) {
            act->unk_10 = 0;
        }

        switch (AnimGetFrame(work->anim)) {
        case 3:
        case 4:
            switch (act->angle) {
            case 45:
            case 211:
                nx = act->fieldPosition.x + gSineTable[act->angle] * 12;
                ny = act->fieldPosition.y + -gSineTable[act->angle + 64] * 12;
                break;
            case 64:
            case 192:
                nx = act->fieldPosition.x + gSineTable[act->angle] * 27;
                ny = act->fieldPosition.y + -gSineTable[act->angle + 64] * 27;
                break;
            case 0:
            case 83:
            case 128:
            case 173:
            default:
                nx = act->fieldPosition.x + gSineTable[act->angle] * 20;
                ny = act->fieldPosition.y + -gSineTable[act->angle + 64] * 20;
                break;
            }

            func_080E02C0(nx, ny, act->fieldPosition.z - 0x800);
            break;
        }

        if (AnimIsFinished(work->anim) != 0) {
            if (work->unk_A0 < 0) {
                work->unk_94 = 3;
            } else {
                work->unk_94 = 4;
            }
        } else {
            work->unk_98++;
        }

        break;
    case 2:
        if (work->unk_98 == 0) {
            func_08031F98(work, 3, 0);
            act->unk_10 >>= 1;
        }

        act->fieldPosition.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->fieldPosition.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;

        if (work->unk_98 > 3) {
            work->unk_B8 = gUnk_0203C7AC->unk_1C;

            if (work->unk_B8 == 0) {
                if (GetRandom() % 2 != 0) {
                    m4aSongNumStart(SONG_SYS_SR_I_VO00);
                } else {
                    m4aSongNumStart(SONG_SYS_SR_I_VO01);
                }

                work->unk_94 = 3;
                work->unk_A0 = -1331;
                act->unk_10 <<= 1;
                work->unk_98 = 0;
                act->fieldPosition.z += work->unk_A0;
                work->unk_A0 += 66;
            } else {
                act->angle = gUnk_0203C7AC->unk_18;
                work->unk_B8 = act->fieldPosition.z - work->unk_B8;
                work->unk_94 = 13;
                SetTaskUpdate(task, (TaskUpdateFunc)func_0803234C);
                work->unk_98 = 0;
            }
        } else {
            work->unk_98++;
        }

        break;
    case 3:
        if ((GetKeysHeld() & DPAD_ANY) != 0) {
            act->unk_10 += 17;

            if (act->unk_10 > 512) {
                act->unk_10 = 512;
            }
        } else {
            act->unk_10 -= 38;

            if (act->unk_10 < 0) {
                act->unk_10 = 0;
            }
        }

        if (work->unk_A0 > -512) {
            func_08031F98(work, 5, 0);
        } else {
            func_08031F98(work, 4, 0);
        }

        act->fieldPosition.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->fieldPosition.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;
        act->fieldPosition.z += work->unk_A0;
        work->unk_A0 += 66;

        if (work->unk_A0 < 0) {
            if ((GetKeysHeld() & B_BUTTON) == 0) {
                work->unk_A0 += 64;
            }
        }

        if ((GetKeysPressed() & A_BUTTON) != 0) {
            work->unk_98 = 0;
            work->unk_94 = 12;
        } else if (work->unk_A0 > 0) {
            work->unk_98 = 0;
            work->unk_94 = 4;
        } else {
            work->unk_98++;
        }

        break;
    case 4:
        if ((GetKeysHeld() & DPAD_ANY) != 0) {
            act->unk_10 += 17;

            if (act->unk_10 > 512) {
                act->unk_10 = 512;
            }
        } else {
            act->unk_10 -= 38;

            if (act->unk_10 < 0) {
                act->unk_10 = 0;
            }
        }

        if (work->unk_A0 < 0x200) {
            func_08031F98(work, 5, 0);
        } else {
            func_08031F98(work, 6, 0);
        }

        act->fieldPosition.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->fieldPosition.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;
        act->fieldPosition.z += work->unk_A0;
        work->unk_A0 += 66;

        if ((GetKeysPressed() & A_BUTTON) != 0) {
            work->unk_98 = 0;
            work->unk_94 = 12;
        } else if (act->fieldPosition.z > z) {
            act->fieldPosition.z = z;
            work->unk_A0 = 0;

            if (work->unk_94 != 5) {
                work->unk_94 = 5;
                work->unk_98 = 0;
            }
        }

        break;
    case 5:
        if (work->unk_98 == 0) {
            func_08031F98(work, 7, 0);
            m4aSongNumStart(work->unk_AC[3]);
        }

        act->unk_10 = 0;

        if ((GetKeysPressed() & B_BUTTON) != 0) {
            work->unk_A4 &= ~4;
            work->unk_98 = 0;
            work->unk_94 = 2;
        } else if (work->unk_98 > 6) {
            gFieldState->flags &= ~0x800000;
            work->unk_A4 &= ~4;
            work->unk_94 = 0;
            work->unk_98 = 0;
            SetTaskUpdate(task, (TaskUpdateFunc)task_fld_sora_1);
        } else {
            work->unk_98++;
        }

        break;
    }

    if (work->unk_64 != 0) {
        switch (work->unk_6C) {
        case 3:
        case 5:
        case 11:
            break;
        default:
            if ((work->flags & 1) == 0) {
                act->unk_10 = 230 * act->unk_10 >> 8;
                act->fieldPosition.x += work->unk_70;
                act->fieldPosition.y += work->unk_74;
            }
            break;
        }
    }

    if (func_08031D74(&act->fieldPosition) != 0) {
        act->fieldPosition.x = sx;
        act->fieldPosition.y = sy;

        switch (func_08031E48(&act->fieldPosition, work)) {
        case 2:
            work->unk_98 = 0;
            work->unk_94 = 6;
            act->angle = 211;
            SetTaskUpdate(task, (TaskUpdateFunc)func_08032C3C);
            break;
        case 1:
            work->unk_98 = 0;
            work->unk_94 = 6;
            act->angle = 45;
            SetTaskUpdate(task, (TaskUpdateFunc)func_08032C3C);
            break;
        default:
            if (work->unk_94 == 4 && act->fieldPosition.unk_0C - act->fieldPosition.z > 0xFFF) {
                p1 = act->fieldPosition;
                p1.y -= 0x400;
                p1.z = act->fieldPosition.z - 0x3000;
                p2 = p1;
                p2.z += 768;

                if (func_08031D74(&p1) == 0 && func_08031D74(&p2) != 0) {
                    work->unk_98 = 0;
                    work->unk_94 = 8;
                    gFieldState->unk_68 = 0;
                    SetTaskUpdate(task, (TaskUpdateFunc)func_08033150);
                }
            } else {
                act->unk_10 = 230 * act->unk_10 >> 8;
            }
            break;
        }
    }

    ColliderSetPosition(work->unk_38, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
    func_080E0298(act->fieldPosition.x, act->fieldPosition.y + act->fieldPosition.z);
    work->gfx = AnimUpdate(work->anim);
    TaskPoolUpdate(work->tasks);

    if ((gFieldState->flags & 0x40000) != 0) {
        work->unk_98 = 0;
        SetTaskUpdate(task, (TaskUpdateFunc)func_08032268);
        TaskPoolUpdate(work->tasks);
    }

    return 1;
}
u8 func_08032C3C(FldWork* work, void* task) {
    FldActor* act;
    FldPos p;
    s32 x;
    s32 y;
    s32 limit;
    s32 d;
    s32 ny;
    s32 nx;
    s32 tx;
    s32 ty;

    act = &gFieldState->actor;
    limit = func_08031F1C(work);
    x = act->fieldPosition.x;
    y = act->fieldPosition.y;
    gFieldState->unk_68 = 0;

    switch (work->unk_94) {
    case 6:
        if (work->unk_98 == 0) {
            work->unk_B8 = (act->fieldPosition.z >> 12) << 12;
            work->unk_98++;
            tx = (work->unk_B0 >> 11) / 4;
            ty = (work->unk_B4 >> 11) / 2;
            nx = (tx << 13) | 0x1000;
            ny = (ty << 12) | 0x800;
            x = nx;
            act->fieldPosition.x = nx;
            y = ny;
            act->fieldPosition.y = ny;
            m4aSongNumStart(work->unk_AC[5]);
            act->fieldPosition.unk_0C = func_080DFF1C(&act->fieldPosition);
        }

        func_08031F98(work, 8, 1);
        work->unk_16 = ((act->fieldPosition.z >> 8) + 4) & 31;
        work->gfx = AnimGetGfx(work->anim);

        if (work->unk_12 == 0) {
            switch (work->unk_16) {
            case 8:
                m4aSongNumStart(work->unk_AC[4]);
                break;
            case 24:
                m4aSongNumStart(work->unk_AC[5]);
                break;
            }
        }

        d = (((work->unk_B8 >> 12) << 12) - act->fieldPosition.z) >> 1;

        if (abs(d) <= 24) {
            d = 0;
        } else if (d > 384) {
            d = 384;
        } else if (d < -384) {
            d = -384;
        }

        act->fieldPosition.z += d;

        if (d < 0) {
            act->fieldPosition.x += gSineTable[act->angle];
            act->fieldPosition.y -= gSineTable[act->angle + 64];
            p = act->fieldPosition;
            p.z = work->unk_B8 - 0x2800;

            if (func_08031D74(&p) == 0) {
                act->unk_10 = 204;
                work->unk_A0 = -0x580;
                work->unk_A4 |= 4;
                work->unk_94 = 7;
                work->unk_98 = 0;
                m4aSongNumStart(work->unk_AC[6]);
            }
        } else if (d > 0) {
            if (act->fieldPosition.z >= limit) {
                act->fieldPosition.z = limit;
                act->angle += 0x80;
                act->fieldPosition.x += gSineTable[act->angle] * 10;
                act->fieldPosition.y += -gSineTable[act->angle + 64] * 10;
                func_08031F98(work, 0, 1);
                work->gfx = AnimGetGfx(work->anim);
                work->unk_94 = 0;
                work->unk_98 = 0;
                SetTaskUpdate(task, (TaskUpdateFunc)task_fld_sora_1);
            }
        } else if (d == 0) {
            if ((GetKeysHeld() & DPAD_UP) || ((GetKeysHeld() & DPAD_LEFT) && act->angle == 0xD3) ||
                ((GetKeysHeld() & DPAD_RIGHT) && act->angle == 0x2D)) {
                work->unk_B8 = ((work->unk_B8 >> 12) - 1) << 12;
            } else if ((GetKeysHeld() & DPAD_DOWN) || ((GetKeysHeld() & DPAD_RIGHT) && act->angle == 0xD3) ||
                       ((GetKeysHeld() & DPAD_LEFT) && act->angle == 0x2D)) {
                work->unk_B8 = ((work->unk_B8 >> 12) + 1) << 12;
            }
        }

        if (GetKeysPressed() & B_BUTTON) {
            work->unk_A0 = 0;
            work->unk_98 = 0;
            work->unk_94 = 4;
            act->angle += 0x80;
            act->unk_10 = 0x80;
            work->unk_A4 |= 4;
            act->fieldPosition.x += gSineTable[act->angle] * 10;
            act->fieldPosition.y += -gSineTable[act->angle + 64] * 10;
            func_08031F98(work, 6, 0);
            work->gfx = AnimGetGfx(work->anim);
            SetTaskUpdate(task, (TaskUpdateFunc)func_080324DC);
        }

        break;
    case 7:
        func_08031F98(work, 11, 0);
        act->fieldPosition.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->fieldPosition.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;
        work->unk_A0 += 0x42;
        act->fieldPosition.z += work->unk_A0;

        if (work->unk_A0 > 0) {
            work->unk_98 = 0;
            work->unk_94 = 4;
            SetTaskUpdate(task, (TaskUpdateFunc)func_080324DC);
        } else {
            work->unk_98++;
        }

        work->gfx = AnimUpdate(work->anim);
        break;
    }

    if (func_08031D74(&act->fieldPosition) != 0) {
        act->fieldPosition.x = x;
        act->fieldPosition.y = y;
    }

    ColliderSetPosition(work->unk_38, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
    func_080E0298(act->fieldPosition.x, act->fieldPosition.y + act->fieldPosition.z);
    TaskPoolUpdate(work->tasks);
    return 1;
}
u8 func_08033054(FldWork* work, void* task) {
    FldActor* act;

    act = &gFieldState->actor;

    if ((GetKeysPressed() & B_BUTTON) || (GetKeysPressed() & DPAD_DOWN) ||
        (act->angle == 0xD3 && (GetKeysPressed() & DPAD_RIGHT)) ||
        (act->angle == 0x2D && (GetKeysPressed() & DPAD_LEFT))) {
        work->unk_98 = 0;
        work->unk_94 = 4;
        work->unk_A0 = 0;
        act->angle += 0x80;
        gFieldState->unk_68 = 0;
        SetTaskUpdate(task, (TaskUpdateFunc)func_080324DC);
        return 1;
    }

    if ((GetKeysHeld() & DPAD_UP) ||
        (act->angle == 0xD3 && (GetKeysHeld() & DPAD_LEFT)) ||
        (act->angle == 0x2D && (GetKeysHeld() & DPAD_RIGHT))) {
        work->unk_98 = 0;
        work->unk_94 = 10;
        act->unk_10 = 0x133;
        work->unk_A0 = -0x5C0;
        work->unk_A4 |= 4;
        m4aSongNumStart(SONG_SYS_SR_CATJP);
        gFieldState->unk_68 = 0;
        return 1;
    }

    return 0;
}
u8 func_08033150(FldWork* work, void* task) {
    FldActor* act;
    FldPos p;
    u8 ret;
    s32 x;
    s32 y;

    act = &gFieldState->actor;
    ret = 0;
    x = act->fieldPosition.x;
    y = act->fieldPosition.y;
    gFieldState->unk_68 = 0;

    switch (work->unk_94) {
    case 8:
        if (work->unk_98 == 0) {
            p = act->fieldPosition;
            p.y -= 0xA00;
            act->fieldPosition.z = func_080DFF1C(&p) + 0x2B00;
            m4aSongNumStart(SONG_SYS_SR_CATCH);
            act->angle = func_080DFF94(act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
            func_08031F98(work, 9, 0);
        }

        if (work->unk_98 > 15) {
            ret = func_08033054(work, task);
        }

        act->fieldPosition.x += gSineTable[act->angle];
        act->fieldPosition.y -= gSineTable[act->angle + 64];

        if (AnimIsFinished(work->anim) != 0 && ret == 0) {
            work->unk_94 = 9;
        } else {
            work->unk_98++;
        }

        break;
    case 9:
        func_08031F98(work, 10, 0);
        func_08033054(work, task);
        break;
    case 10:
        func_08031F98(work, 11, 0);
        act->fieldPosition.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->fieldPosition.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;
        act->fieldPosition.z += work->unk_A0;
        work->unk_A0 += 0x42;

        if (work->unk_A0 > 0) {
            work->unk_98 = 0;
            work->unk_94 = 4;
            SetTaskUpdate(task, (TaskUpdateFunc)func_080324DC);
        } else {
            work->unk_98++;
        }

        break;
    }

    work->gfx = AnimUpdate(work->anim);

    if (func_08031D74(&act->fieldPosition) != 0) {
        act->fieldPosition.x = x;
        act->fieldPosition.y = y;
    }

    ColliderSetPosition(work->unk_38, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
    func_080E0298(act->fieldPosition.x, act->fieldPosition.y + act->fieldPosition.z);
    TaskPoolUpdate(work->tasks);
    return 1;
}
u8 func_08033334(FldWork* work, void* task) {
    FldActor* act;

    act = &gFieldState->actor;

    switch (work->unk_94) {
    case 15:
        if (work->unk_98 == 0) {
            work->unk_A4 |= 0x10;
            act->angle = 45;
            func_08031F98(work, 2, 1);

            if (gGameState.floor == 0) {
                act->fieldPosition.x = 0x32000;
            } else {
                act->fieldPosition.x = 0x22000;
            }

            act->fieldPosition.y = 0xF000;
            work->unk_9A = 30;
            act->fieldPosition.z = 0;
            act->fieldPosition.unk_0C = 0;
            work->unk_B0 = act->fieldPosition.x + 0x2000;
            work->unk_B4 = act->fieldPosition.y - 0x1000;
            work->unk_B8 = act->fieldPosition.unk_0C - 0x2800;
        }

        if (work->unk_9A > 0) {
            ApproachValue(&act->fieldPosition.x, work->unk_B0, work->unk_9A);
            ApproachValue(&act->fieldPosition.y, work->unk_B4, work->unk_9A);
            ApproachValue(&act->fieldPosition.z, work->unk_B8, work->unk_9A);
            act->fieldPosition.unk_0C = act->fieldPosition.z;
            work->unk_9A--;
        }

        if (work->unk_12 == 0) {
            switch (work->unk_16) {
            case 3:
                m4aSongNumStart(work->unk_AC[0]);
                break;
            case 7:
                m4aSongNumStart(work->unk_AC[1]);
                break;
            }
        }

        if (work->unk_9A <= 0) {
            work->unk_98 = 0;

            if (work->unk_A4 & 0x20) {
                work->unk_94 = 16;
            } else {
                work->unk_94 = 17;
            }
        } else {
            work->unk_98++;
        }

        break;
    case 16:
        if (work->unk_98 == 0) {
            work->unk_9A = 25;
            work->unk_B0 = act->fieldPosition.x + 0x2000;
            work->unk_B4 = act->fieldPosition.y - 0x1000;
        }

        if (work->unk_9A > 0) {
            ApproachValue(&act->fieldPosition.x, work->unk_B0, work->unk_9A);
            ApproachValue(&act->fieldPosition.y, work->unk_B4, work->unk_9A);
            work->unk_9A--;
        }

        if (work->unk_12 == 0) {
            switch (work->unk_16) {
            case 3:
                m4aSongNumStart(work->unk_AC[0]);
                break;
            case 7:
                m4aSongNumStart(work->unk_AC[1]);
                break;
            }
        }

        if (work->unk_9A <= 0) {
            work->unk_98 = 0;
            work->unk_94 = 18;
        } else {
            work->unk_98++;
        }

        break;
    case 17:
        if (work->unk_98 == 0) {
            work->unk_9A = 25;
            work->unk_B0 = act->fieldPosition.x + 0x2000;
            work->unk_B4 = act->fieldPosition.y - 0x1000;
        }

        if (work->unk_9A > 0) {
            ApproachValue(&act->fieldPosition.x, work->unk_B0, work->unk_9A);
            ApproachValue(&act->fieldPosition.y, work->unk_B4, work->unk_9A);
            work->unk_9A--;
        }

        if (work->unk_12 == 0) {
            switch (work->unk_16) {
            case 3:
                m4aSongNumStart(work->unk_AC[0]);
                break;
            case 7:
                m4aSongNumStart(work->unk_AC[1]);
                break;
            }
        }

        if (work->unk_9A <= 0) {
            work->unk_98 = 0;
            work->unk_94 = 19;
        } else {
            work->unk_98++;
        }

        break;
    case 18:
        if (work->unk_98 == 0) {
            func_08031F98(work, 12, 0);
            FadeSetPaletteExcluded(work->palette->index + 16, 1);
        }

        if (work->unk_98 == 40) {
            CreateWorldSelBeforeTask(work->tasks, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
        }

        if (work->unk_98 > 140) {
            work->unk_98 = 0;
            work->unk_94 = 19;
        } else {
            work->unk_98++;
        }

        break;
    case 19:
        func_080DFC7C();
        break;
    }

    ColliderSetPosition(work->unk_38, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
    func_080E0298(act->fieldPosition.x, act->fieldPosition.y + act->fieldPosition.z);
    work->gfx = AnimUpdate(work->anim);
    TaskPoolUpdate(work->tasks);
    return 1;
}
u8 func_0803366C(FldWork* work, void* task) {
    FldActor* act;
    s32 x;
    s32 y;
    s32 nx;
    s32 ny;

    act = &gFieldState->actor;
    x = act->fieldPosition.x;
    y = act->fieldPosition.y;

    if (work->unk_94 == 11) {
        if (work->unk_98 == 0) {
            func_08031F98(work, 13, 0);
            act->unk_10 = 0;
            gFieldState->unk_68 = 0;
            work->unk_9A = 0;
            m4aSongNumStart(SONG_SYS_SR_AT_VO00);
        }

        if (work->unk_12 == 0) {
            switch (act->angle) {
            case 173:
                switch (AnimGetFrame(work->anim)) {
                case 0:
                    act->fieldPosition.x -= 0x500;
                    act->fieldPosition.y += 0x400;
                    break;
                case 1:
                    act->fieldPosition.x -= 0x200;
                    break;
                case 2:
                    act->fieldPosition.x -= 0x300;
                    break;
                }

                break;
            case 83:
                switch (AnimGetFrame(work->anim)) {
                case 0:
                    act->fieldPosition.x += 0x500;
                    act->fieldPosition.y += 0x400;
                    break;
                case 1:
                    act->fieldPosition.x += 0x200;
                    break;
                case 2:
                    act->fieldPosition.x += 0x300;
                    break;
                }

                break;
            case 211:
                switch (AnimGetFrame(work->anim)) {
                case 0:
                    act->fieldPosition.x -= 0x500;
                    act->fieldPosition.y -= 0x200;
                    break;
                case 1:
                    act->fieldPosition.x -= 0x500;
                    break;
                case 2:
                    act->fieldPosition.x -= 0x200;
                    break;
                }

                break;
            case 45:
                switch (AnimGetFrame(work->anim)) {
                case 0:
                    act->fieldPosition.x += 0x500;
                    act->fieldPosition.y -= 0x200;
                    break;
                case 1:
                    act->fieldPosition.x += 0x500;
                    break;
                case 2:
                    act->fieldPosition.x += 0x200;
                    break;
                }

                break;
            case 128:
                switch (AnimGetFrame(work->anim)) {
                case 0:
                    act->fieldPosition.x -= 0x300;
                    act->fieldPosition.y += 0x400;
                    break;
                case 1:
                    act->fieldPosition.x += 0x100;
                    act->fieldPosition.y += 0x100;
                    break;
                case 2:
                    act->fieldPosition.y += 0x200;
                    break;
                case 3:
                    act->fieldPosition.y += 0x100;
                    break;
                }

                break;
            case 64:
                switch (AnimGetFrame(work->anim)) {
                case 0:
                    act->fieldPosition.x += 0x700;
                    act->fieldPosition.y += 0x100;
                    break;
                case 1:
                    act->fieldPosition.x += 0x300;
                    break;
                case 2:
                    act->fieldPosition.x += 0x200;
                    break;
                }

                break;
            case 192:
                switch (AnimGetFrame(work->anim)) {
                case 0:
                    act->fieldPosition.x -= 0x700;
                    act->fieldPosition.y += 0x100;
                    break;
                case 1:
                    act->fieldPosition.x -= 0x300;
                    break;
                case 2:
                    act->fieldPosition.x -= 0x200;
                    break;
                }

                break;
            case 0:
                switch (AnimGetFrame(work->anim)) {
                case 0:
                    act->fieldPosition.y -= 0x400;
                    break;
                case 1:
                    act->fieldPosition.y -= 0x400;
                    break;
                case 2:
                    act->fieldPosition.x -= 0x100;
                    act->fieldPosition.y += 0x100;
                    break;
                case 3:
                    act->fieldPosition.y -= 0x100;
                    break;
                }

                break;
            }
        }

        if (AnimGetFrame(work->anim) == 2) {
            switch (act->angle) {
            case 45:
            case 211:
                nx = act->fieldPosition.x + gSineTable[act->angle] * 12;
                ny = act->fieldPosition.y + -gSineTable[act->angle + 64] * 12;
                break;
            case 64:
            case 192:
                nx = act->fieldPosition.x + gSineTable[act->angle] * 27;
                ny = act->fieldPosition.y + -gSineTable[act->angle + 64] * 27;
                break;
            case 0:
            case 83:
            case 128:
            case 173:
            default:
                nx = act->fieldPosition.x + gSineTable[act->angle] * 20;
                ny = act->fieldPosition.y + -gSineTable[act->angle + 64] * 20;
                break;
            }

            func_080E02C0(nx, ny, act->fieldPosition.z - 0x800);
        }

        if (AnimIsFinished(work->anim) != 0) {
            switch (act->angle) {
            case 173:
                act->fieldPosition.x -= 0x200;
                act->fieldPosition.y += 0x200;
                break;
            case 83:
                act->fieldPosition.x += 0x200;
                act->fieldPosition.y += 0x200;
                break;
            case 45:
            case 211:
                act->fieldPosition.y -= 0x400;
                break;
            case 128:
                act->fieldPosition.y += 0x200;
                break;
            case 0:
                act->fieldPosition.y -= 0x200;
                break;
            }

            func_08031F98(work, 0, 0);
            work->unk_94 = 0;
            SetTaskUpdate(task, (TaskUpdateFunc)task_fld_sora_1);
        } else {
            work->unk_98++;
        }
    }

    if (work->unk_64 != 0) {
        switch (work->unk_6C) {
        case 5:
        case 3:
        case 11:
            break;
        default:
            if ((work->flags & 1) == 0) {
                act->fieldPosition.x += work->unk_70;
                act->fieldPosition.y += work->unk_74;
            }

            break;
        }
    }

    if (func_08031D74(&act->fieldPosition) != 0) {
        act->fieldPosition.x = x;
        act->fieldPosition.y = y;
    }

    ColliderSetPosition(work->unk_38, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
    func_080E0298(act->fieldPosition.x, act->fieldPosition.y + act->fieldPosition.z);
    work->gfx = AnimUpdate(work->anim);
    TaskPoolUpdate(work->tasks);

    if (gFieldState->flags & 0x40000) {
        work->unk_98 = 0;
        SetTaskUpdate(task, (TaskUpdateFunc)func_08032268);
    }

    return 1;
}
u8 task_fld_sora_1(FldWork* work, void* task) {
    FldPos p1;
    FldPos p2;
    FldPos p3;
    FldPos p4;
    s32 sx;
    s32 sy;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 dw;
    s32 z;
    s32 r;
    u8 a;
    u8 b;
    FldActor* act;

    act = &gFieldState->actor;

    if ((work->unk_A4 & 8) != 0) {
        work->unk_A4 &= ~8;

        switch (work->unk_94) {
        case 12:
            work->unk_94 = 3;
        case 2:
        case 3:
        case 4:
            gFieldState->flags |= 0x800000;
        case 5:
            SetTaskUpdate(task, (TaskUpdateFunc)func_080324DC);
            gFieldState->unk_68 = 0;
            break;
        case 6:
        case 7:
            SetTaskUpdate(task, (TaskUpdateFunc)func_08032C3C);
            gFieldState->unk_68 = 0;
            work->unk_98 = 1;
            break;
        case 8:
        case 9:
        case 10:
            SetTaskUpdate(task, (TaskUpdateFunc)func_08033150);
            gFieldState->unk_68 = 0;
            break;
        default:
            work->unk_94 = 0;
            break;
        }

        ColliderSetPosition(work->unk_38, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
        func_080E0298(act->fieldPosition.x, act->fieldPosition.y + act->fieldPosition.z);
        work->gfx = AnimUpdate(work->anim);
        TaskPoolUpdate(work->tasks);
        return 1;
    } else if (func_080DFC24() != 0) {
        work->unk_98 = 0;
        SetTaskUpdate(task, (TaskUpdateFunc)func_08033334);
        TaskPoolUpdate(work->tasks);
        work->unk_94 = 15;

        if (func_080DFC24() == 1) {
            work->unk_A4 |= 0x20;
        }

        return 1;
    } else if ((gFieldState->flags & 0x40000) != 0) {
        work->unk_98 = 0;
        SetTaskUpdate(task, (TaskUpdateFunc)func_08032268);
        TaskPoolUpdate(work->tasks);
        return 1;
    } else {
        sx = act->fieldPosition.x;
        sy = act->fieldPosition.y;

        if (work->unk_94 <= 1) {
            if ((gFieldState->flags & 0x4000) == 0) {
                func_08031F60(act);
            }

            if ((gFieldState->flags & 0x4000) == 0 && (GetKeysHeld() & DPAD_ANY) != 0) {
                act->unk_10 += 128;
                func_08031F98(work, 2, 1);

                if (act->unk_10 > 0x266) {
                    act->unk_10 = 0x266;
                }

                if (work->unk_12 == 0) {
                    switch (work->unk_16) {
                    case 3:
                        m4aSongNumStart(work->unk_AC[0]);
                        break;
                    case 7:
                        m4aSongNumStart(work->unk_AC[1]);
                        break;
                    }
                }
            } else {
                func_08031F98(work, 0, 1);
                act->unk_10 -= 128;

                if (act->unk_10 < 0) {
                    act->unk_10 = 0;
                }
            }

            act->fieldPosition.x += gSineTable[act->angle] * act->unk_10 >> 8;
            act->fieldPosition.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;

            if ((GetKeysPressed() & B_BUTTON) != 0) {
                gFieldState->unk_68 = 0;
                gFieldState->flags |= 0x800000;
                work->unk_98 = 0;
                work->unk_94 = 2;
                SetTaskUpdate(task, (TaskUpdateFunc)func_080324DC);
                m4aSongNumStart(work->unk_AC[2]);
            } else if ((GetKeysPressed() & A_BUTTON) != 0) {
                work->unk_98 = 0;
                gFieldState->unk_68 = 0;
                work->unk_94 = 11;
                SetTaskUpdate(task, (TaskUpdateFunc)func_0803366C);
            }
        } else if (AnimIsFinished(work->anim) != 0) {
            work->unk_94 = 0;
        }

        if (work->unk_64 != 0) {
            switch (work->unk_6C) {
            case 3:
            case 5:
            case 11:
                break;
            default:
                if ((work->flags & 1) == 0) {
                    act->unk_10 = 230 * act->unk_10 >> 8;
                    act->fieldPosition.x += work->unk_70;
                    act->fieldPosition.y += work->unk_74;
                }
                break;
            }
        }

        if (func_08031D74(&act->fieldPosition) != 0) {
            act->fieldPosition.x = sx;
            act->fieldPosition.y = sy;
            r = func_08031E48(&act->fieldPosition, work);

            if (r != 0) {
                switch (r) {
                case 2:
                    work->unk_98 = 0;
                    work->unk_94 = 6;
                    act->angle = 211;
                    gFieldState->unk_68 = 0;
                    SetTaskUpdate(task, (TaskUpdateFunc)func_08032C3C);
                    break;
                case 1:
                    work->unk_98 = 0;
                    work->unk_94 = 6;
                    act->angle = 45;
                    gFieldState->unk_68 = 0;
                    SetTaskUpdate(task, (TaskUpdateFunc)func_08032C3C);
                    break;
                }
            } else {
                if (func_08031EC4(&act->fieldPosition) != 0) {
                    FadeSetPaletteExcluded(work->palette->index + 16, 1);
                    gFieldState->flags |= 16;
                    return 1;
                }

                switch (act->angle) {
                case 173:
                    dx = -256;
                    dy = 0;
                    dz = 0;
                    dw = 384;
                    break;
                case 83:
                    dx = 256;
                    dy = 0;
                    dz = 0;
                    dw = 384;
                    break;
                case 211:
                    dx = -256;
                    dy = 0;
                    dz = 0;
                    dw = -384;
                    break;
                case 45:
                    dx = 256;
                    dy = 0;
                    dz = 0;
                    dw = -384;
                    break;
                case 128:
                    dx = -512;
                    dy = 192;
                    dz = 512;
                    dw = 192;
                    break;
                case 0:
                    dx = -512;
                    dy = -192;
                    dz = 512;
                    dw = -192;
                    break;
                case 64:
                    dx = 384;
                    dy = -307;
                    dz = 384;
                    dw = 307;
                    break;
                case 192:
                    dx = -384;
                    dy = -307;
                    dz = -384;
                    dw = 307;
                    break;
                default:
                    dw = 0;
                    dz = 0;
                    dy = 0;
                    dx = 0;
                    break;
                }

                p2 = act->fieldPosition;
                p1 = p2;
                p1.x += dx;
                p1.y += dy;
                p2.x += dz;
                p2.y += dw;
                a = func_08031D74(&p1);
                b = func_08031D74(&p2);

                if (a != 0) {
                    if (b == 0) {
                        p3 = act->fieldPosition;
                        p3.x += dz;
                        p3.y += dw;
                        p3.unk_0C = func_08031DF8(&p3);

                        if (p3.unk_0C >= p3.z) {
                            act->fieldPosition = p3;
                        }
                    }
                } else if (b != 0) {
                    p4 = act->fieldPosition;
                    p4.x += dx;
                    p4.y += dy;
                    p4.unk_0C = func_08031DF8(&p4);

                    if (p4.unk_0C >= p4.z) {
                        act->fieldPosition = p4;
                    }
                }

                act->unk_10 = 0;
            }
        }

        z = func_08031F1C(work);

        if (act->fieldPosition.unk_0C == 0x100000) {
            act->fieldPosition.unk_0C = act->fieldPosition.z;
        } else if (z != act->fieldPosition.z) {
            act->unk_10 >>= 2;
            work->unk_A0 = 0;
            work->unk_98 = 0;
            gFieldState->unk_68 = 0;
            gFieldState->flags |= 0x800000;
            work->unk_94 = 4;
            SetTaskUpdate(task, (TaskUpdateFunc)func_080324DC);
        } else if (z != act->fieldPosition.unk_0C) {
            gFieldState->unk_68 = 0;
        }
    }

    ColliderSetPosition(work->unk_38, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
    func_080E0298(act->fieldPosition.x, act->fieldPosition.y + act->fieldPosition.z);
    work->gfx = AnimUpdate(work->anim);
    TaskPoolUpdate(work->tasks);
    return 1;
}

void task_fld_sora_2(FldWork* work) {
    FldActor* act;
    u16 depth;
    s32 pri;
    s32 x;
    s32 y;
    s32 z;

    act = &gFieldState->actor;
    pri = (work->unk_A4 & 2) ? 0x801 : 0x800;

    if (work->unk_BC != 0) {
        depth = -0x1006 - (work->unk_80 >> 8) * 4;

        if (work->unk_84 <= work->unk_48) {
            act->unk_3A = 0;
            act->unk_3C = func_080DFF1C(&act->fieldPosition);
        } else {
            act->unk_3C = work->unk_78;
            act->unk_3A = depth + 1;
        }
    } else {
        depth = -0x1004 - (act->fieldPosition.y >> 8) * 4;

        if (work->unk_A4 & 0x10) {
            act->unk_3C = act->fieldPosition.unk_0C;
        } else {
            act->unk_3C = func_080DFF1C(&act->fieldPosition);
        }

        if (act->unk_3C != act->fieldPosition.unk_0C) {
            act->unk_3A = 0;
        } else {
            act->unk_3A = depth + 1;
        }
    }

    x = (act->fieldPosition.x >> 8) - (gFieldState->x >> 8);
    y = (act->fieldPosition.y >> 8) + (act->fieldPosition.z >> 8) - (gFieldState->y >> 8);
    DrawSprite(x, y, work->gfx, work->tiles, work->palette, 0, pri, depth);
    TaskPoolDraw(work->tasks);
}

void task_fld_sora_3(FldWork* work) {
    FldActor* act;

    act = &gFieldState->actor;
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ColliderUnregister(work->unk_38);

    if (gGameState.unk_000 != 0) {
        gGameState.unk_028 = act->unk_10;
        gGameState.fieldPosition = act->fieldPosition;
        gGameState.unk_024 = act->angle;
        gGameState.unk_030 = work->unk_94;
        gGameState.unk_02C = work->unk_A0;
        gGameState.unk_034 = work->unk_B0;
        gGameState.unk_038 = work->unk_B4;
        gGameState.unk_03C = work->unk_B8;
    } else {
        gGameState.unk_024 = act->angle;
    }

    TaskPoolDestroy(work->tasks);
}

void func_08034368(FldActor* act) {
    if ((GetKeysHeld() & DPAD_LEFT) && (GetKeysHeld() & DPAD_DOWN)) {
        act->angle = 0xAD;
    } else if ((GetKeysHeld() & DPAD_UP) && (GetKeysHeld() & DPAD_LEFT)) {
        act->angle = 0xD3;
    } else if ((GetKeysHeld() & DPAD_UP) && (GetKeysHeld() & DPAD_RIGHT)) {
        act->angle = 0x2D;
    } else if ((GetKeysHeld() & DPAD_RIGHT) && (GetKeysHeld() & DPAD_DOWN)) {
        act->angle = 0x53;
    } else if ((GetKeysHeld() & DPAD_DOWN) && GetKeyReleaseTime(DPAD_LEFT) <= 4) {
        act->angle = 0xAD;
    } else if ((GetKeysHeld() & DPAD_DOWN) && GetKeyReleaseTime(DPAD_RIGHT) <= 4) {
        act->angle = 0x53;
    } else if ((GetKeysHeld() & DPAD_UP) && GetKeyReleaseTime(DPAD_LEFT) <= 4) {
        act->angle = 0xD3;
    } else if ((GetKeysHeld() & DPAD_UP) && GetKeyReleaseTime(DPAD_RIGHT) <= 4) {
        act->angle = 0x2D;
    } else if ((GetKeysHeld() & DPAD_LEFT) && GetKeyReleaseTime(DPAD_UP) <= 4) {
        act->angle = 0xD3;
    } else if ((GetKeysHeld() & DPAD_LEFT) && GetKeyReleaseTime(DPAD_DOWN) <= 4) {
        act->angle = 0xAD;
    } else if ((GetKeysHeld() & DPAD_RIGHT) && GetKeyReleaseTime(DPAD_UP) <= 4) {
        act->angle = 0x2D;
    } else if ((GetKeysHeld() & DPAD_RIGHT) && GetKeyReleaseTime(DPAD_DOWN) <= 4) {
        act->angle = 0x53;
    } else if (GetKeysHeld() & DPAD_DOWN) {
        act->angle = 0x80;
    } else if (GetKeysHeld() & DPAD_UP) {
        act->angle = 0;
    } else if (GetKeysHeld() & DPAD_LEFT) {
        act->angle = 0xC0;
    } else if (GetKeysHeld() & DPAD_RIGHT) {
        act->angle = 0x40;
    }
}

u8 func_08034518(FldPos* p) {
    FldPos a;
    FldPos b;
    s32 lo;
    s32 hi;
    s32 v;

    a = *p;
    b = *p;
    a.y -= 0x600;
    b.y += 0x600;

    lo = func_080DFF1C(&a);

    if (lo > a.unk_0C) {
        a.unk_0C = lo;
    }

    hi = func_080DFF1C(&b);

    if (hi > b.unk_0C) {
        b.unk_0C = hi;
    }

    if (func_080DFBDC(&a) != 0 || func_080DFBDC(&b) != 0) {
        return 1;
    }

    v = hi;

    if (v > lo) {
        v = lo;
    }

    p->unk_0C = v;
    return 0;
}

s32 func_0803459C(FldPos* p) {
    FldPos a;
    FldPos b;
    s32 lo;
    s32 hi;

    a = *p;
    b = *p;
    a.y -= 0x600;
    b.y += 0x600;

    lo = func_080DFF1C(&a);
    hi = func_080DFF1C(&b);

    if (hi > lo) {
        hi = lo;
    }

    return hi;
}

u8 func_080345EC(FldPos* p, FldWork* work) {
    FldPos a;
    FldPos b;
    u8 hit;

    a = *p;
    b = *p;
    a.y -= 0x600;
    b.y += 0x600;

    hit = _080DFE1C(&a);

    if (hit != 0) {
        work->unk_B0 = a.x;
        work->unk_B4 = a.y;
        return hit;
    }

    hit = _080DFE1C(&b);

    if (hit != 0) {
        work->unk_B0 = b.x;
        work->unk_B4 = b.y;
        return hit;
    }

    return 0;
}

u8 func_08034668(FldActor* act) {
    FldPos v;

    v = act->fieldPosition;
    v.x += gSineTable[act->angle] * 8;
    v.y -= gSineTable[act->angle + 64] * 8;

    if (func_080DFCDC(&v) != 0) {
        return 1;
    }

    return 0;
}

s32 func_080346C0(FldWork* work) {
    FldActor* act;
    s32 v;

    act = &gFieldState->actor;

    if (work->flags & 1) {
        if (act->fieldPosition.unk_0C < work->unk_78) {
            v = act->fieldPosition.unk_0C;
        } else {
            v = work->unk_78;
        }

        work->unk_BC = 1;
    } else {
        work->unk_BC = 0;
        v = act->fieldPosition.unk_0C;
    }

    return v;
}

void func_08034704(FldActor* act) {
    u8 dir;
    s32 diff;

    dir = act->angle;
    func_08034368(act);

    if (dir != act->angle) {
        diff = (s8)GetAngleDiff(dir, act->angle);

        if (diff < 0) {
            diff = -diff;
        }

        if (diff > 100) {
            act->unk_10 = 0;
        } else {
            act->unk_10 = act->unk_10 >> 1;
        }
    }
}

void func_0803473C(FldWork* work, s32 index, u16 flags) {
    const FldAnimDef* def;
    s32 dir;

    switch (gFieldState->actor.angle) {
    case 0x2D:
        dir = 4;
        work->unk_A4 |= 2;
        break;
    case 0x40:
        dir = 3;
        work->unk_A4 |= 2;
        break;
    case 0x53:
        dir = 2;
        work->unk_A4 |= 2;
        break;
    case 0x80:
        dir = 1;
        work->unk_A4 &= 0xFFFD;
        break;
    case 0xAD:
        dir = 2;
        work->unk_A4 &= 0xFFFD;
        break;
    case 0xC0:
        dir = 3;
        work->unk_A4 &= 0xFFFD;
        break;
    case 0xD3:
        dir = 4;
        work->unk_A4 &= 0xFFFD;
        break;
    case 0x00:
    default:
        dir = 0;
        work->unk_A4 &= 0xFFFD;
        break;
    }

    if (work->unk_A8 == index) {
        flags |= 4;
    }

    work->unk_A8 = index;
    def = &gUnk_0813CDDC[index][dir];
    AnimChangeWithTables(work->anim, def->animId, flags, def->anims, def->gfxTable);
    SetObjTileSource(work->tiles, def->tiles);
}

void task_fld_riku_0(FldWork* work) {
    FldActor* act;

    act = &gFieldState->actor;
    work->tiles = AllocObjTiles(0xA00, 0);
    work->palette = LoadObjPalette(gRikuPalette, 32);
    act->unk_1A = 16;
    work->unk_BC = 0;
    work->unk_9C = 0;
    work->unk_9D = 0;
    work->unk_9E = 0;
    work->unk_98 = 0;
    work->unk_A4 = 8;
    work->unk_A8 = 16;
    act->unk_32 = 0;
    act->unk_30 = 0;

    if (gGameState.unk_000 != 0) {
        act->fieldPosition = gGameState.fieldPosition;
        act->angle = gGameState.unk_024;
        act->unk_10 = gGameState.unk_028;
        work->unk_94 = gGameState.unk_030;
        work->unk_A0 = gGameState.unk_02C;
        work->unk_B0 = gGameState.unk_034;
        work->unk_B4 = gGameState.unk_038;
        work->unk_B8 = gGameState.unk_03C;
    } else {
        act->fieldPosition.x = gFieldState->unk_DC;
        act->fieldPosition.y = gFieldState->unk_E0;
        act->fieldPosition.z = 0;
        act->angle = gFieldState->unk_E4;
        func_080DFF4C(&act->fieldPosition);
        act->fieldPosition.z = act->fieldPosition.unk_0C;
        act->fieldPosition.y -= act->fieldPosition.unk_0C;
        act->unk_10 = 0;
        work->unk_94 = 0;
        work->unk_A0 = 0;
    }

    AnimInit(work->anim, 0, 0);
    func_0803473C(work, 0, 1);
    work->gfx = AnimGetGfx(work->anim);

    switch (gGameState.world) {
    case WORLD_NEVER_LAND:
        work->unk_AC = gUnk_0813D28C[1];
        break;
    case WORLD_ATLANTICA:
        work->unk_AC = gUnk_0813D28C[2];
        break;
    case WORLD_MONSTRO:
        work->unk_AC = gUnk_0813D28C[3];
        break;
    case WORLD_WONDERLAND:
        work->unk_AC = gUnk_0813D28C[4];
        break;
    case WORLD_HALLOWEEN_TOWN:
        work->unk_AC = gUnk_0813D28C[5];
        break;
    case 0:
    case WORLD_OLYMPUS_COLISEUM:
    case WORLD_CASTLE_OBLIVION:
        work->unk_AC = gUnk_0813D28C[6];
        break;
    case WORLD_DESTINY_ISLANDS:
        work->unk_AC = gUnk_0813D28C[7];
        break;
    default:
        work->unk_AC = gUnk_0813D28C[0];
        break;
    }

    TaskPoolInit(work->tasks, 2);
    TaskCreate(work->tasks, &gTaskDescFldShadow, &gFieldState->actor);
    ColliderInit(work->unk_38, 1, 4, 32);
    ColliderSetPosition(work->unk_38, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
}
u8 func_08034A0C(FldWork* work, void* task) {
    FldActor* act;
    s16* p;
    s32 flags;

    act = &gFieldState->actor;
    flags = gFieldState->flags;

    if (flags & 0x100000) {
        func_0803473C(work, 12, 0);
    } else if (flags & 0x80000) {
        func_0803473C(work, 1, 1);
    } else {
        func_0803473C(work, 0, 1);
    }

    if ((gFieldState->flags & 0x40000) == 0) {
        FadeSetPaletteExcluded(work->palette->index + 16, 0);
        work->unk_94 = 0;
        work->unk_98 = 0;
        SetTaskUpdate(task, (TaskUpdateFunc)task_fld_riku_1);
        TaskPoolUpdate(work->tasks);
    } else {
        p = &work->unk_98;

        if (*p == 0) {
            FadeSetPaletteExcluded(work->palette->index + 16, 1);
            act->unk_10 = 0;
            work->unk_BC = 0;
        }

        TaskPoolUpdate(work->tasks);
        work->gfx = AnimUpdate(work->anim);
        ColliderSetPosition(work->unk_38, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
        (*p)++;
    }

    return 1;
}
u8 func_08034AF0(FldWork* work, void* task) {
    FldActor* act;
    s32 x;
    s32 y;
    s32 z;

    act = &gFieldState->actor;
    x = act->fieldPosition.x;
    y = act->fieldPosition.y;
    gFieldState->unk_68 = 0;

    switch (work->unk_94) {
    case 13:
        m4aSongNumStart(SONG_SYS_GIMICJP);
        work->unk_94 = 14;
        work->unk_A0 = -0x800;
        work->unk_98 = 0;
        act->unk_10 = 0;
        work->unk_B0 = work->unk_7C;
        work->unk_B4 = work->unk_80;
        break;
    case 14:
        if (work->unk_A0 > -0x300) {
            func_0803473C(work, 11, 0);
            act->unk_10 = 0x180;
            act->fieldPosition.x += gSineTable[act->angle] * act->unk_10 >> 8;
            act->fieldPosition.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;
        } else {
            func_0803473C(work, 4, 0);
            act->fieldPosition.x += (work->unk_B0 - act->fieldPosition.x) >> 3;
            act->fieldPosition.y += (work->unk_B4 - act->fieldPosition.y) >> 3;
        }

        work->unk_A0 = (work->unk_B8 - (z = act->fieldPosition.z + 0xF00)) >> 3;
        act->fieldPosition.z += work->unk_A0;
        work->unk_A0 += 0x42;

        if (work->unk_A0 >= 0) {
            work->unk_98 = 0;
            work->unk_94 = 4;
            work->unk_A4 |= 4;
            SetTaskUpdate(task, (TaskUpdateFunc)func_08034C88);
        } else {
            work->unk_98++;
        }

        break;
    }

    if (func_08034518(&act->fieldPosition) != 0) {
        act->fieldPosition.x = x;
        act->fieldPosition.y = y;
    }

    ColliderSetPosition(work->unk_38, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
    func_080E0298(act->fieldPosition.x, act->fieldPosition.y + act->fieldPosition.z);
    work->gfx = AnimUpdate(work->anim);
    TaskPoolUpdate(work->tasks);
    return 1;
}
u8 func_08034C88(FldWork* work, void* task) {
    FldPos p1;
    FldPos p2;
    s32 sx;
    s32 sy;
    s32 nx;
    s32 ny;
    s32 z;
    FldActor* act;

    act = &gFieldState->actor;
    z = func_080346C0(work);
    sx = act->fieldPosition.x;
    sy = act->fieldPosition.y;
    gFieldState->unk_68 = 0;

    if ((work->unk_A4 & 4) == 0) {
        func_08034704(act);
    }

    switch (work->unk_94) {
    case 12:
        if (work->unk_98 == 0) {
            gFieldState->unk_68 = 0;
            func_0803473C(work, 14, 0);
        }

        act->fieldPosition.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->fieldPosition.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;

        if (AnimGetFrame(work->anim) > 3) {
            act->fieldPosition.z += work->unk_A0;
            work->unk_A0 += 66;

            if (act->fieldPosition.z > z) {
                act->fieldPosition.z = z;
                work->unk_A0 = 0;
            }
        } else {
            work->unk_A0 = 0;
        }

        act->unk_10 -= 38;

        if (act->unk_10 < 0) {
            act->unk_10 = 0;
        }

        switch (AnimGetFrame(work->anim)) {
        case 1:
            switch (act->angle) {
            case 45:
            case 211:
                nx = act->fieldPosition.x + gSineTable[act->angle] * 12;
                ny = act->fieldPosition.y + -gSineTable[act->angle + 64] * 12;
                break;
            case 64:
            case 192:
                nx = act->fieldPosition.x + gSineTable[act->angle] * 27;
                ny = act->fieldPosition.y + -gSineTable[act->angle + 64] * 27;
                break;
            case 0:
            case 83:
            case 128:
            case 173:
            default:
                nx = act->fieldPosition.x + gSineTable[act->angle] * 20;
                ny = act->fieldPosition.y + -gSineTable[act->angle + 64] * 20;
                break;
            }

            func_080E02C0(nx, ny, act->fieldPosition.z - 0x800);
            break;
        }

        if (AnimIsFinished(work->anim) != 0) {
            if (work->unk_A0 < 0) {
                work->unk_94 = 3;
            } else {
                work->unk_94 = 4;
            }
        } else {
            work->unk_98++;
        }

        break;
    case 2:
        if (work->unk_98 == 0) {
            func_0803473C(work, 3, 0);
            act->unk_10 >>= 1;
        }

        act->fieldPosition.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->fieldPosition.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;

        if (work->unk_98 > 3) {
            work->unk_B8 = gUnk_0203C7AC->unk_1C;

            if (work->unk_B8 == 0) {
                if (GetRandom() % 2 != 0) {
                    m4aSongNumStart(SONG_SND_225);
                } else {
                    m4aSongNumStart(SONG_SND_226);
                }

                work->unk_94 = 3;
                work->unk_A0 = -1536;
                act->unk_10 <<= 1;
                work->unk_98 = 0;
                act->fieldPosition.z += work->unk_A0;
                work->unk_A0 += 66;
            } else {
                act->angle = gUnk_0203C7AC->unk_18;
                work->unk_B8 = act->fieldPosition.z - work->unk_B8;
                work->unk_94 = 13;
                SetTaskUpdate(task, (TaskUpdateFunc)func_08034AF0);
                work->unk_98 = 0;
            }
        } else {
            work->unk_98++;
        }

        break;
    case 3:
        if ((GetKeysHeld() & DPAD_ANY) != 0) {
            act->unk_10 += 17;

            if (act->unk_10 > 512) {
                act->unk_10 = 512;
            }
        } else {
            act->unk_10 -= 38;

            if (act->unk_10 < 0) {
                act->unk_10 = 0;
            }
        }

        if (work->unk_A0 > -512) {
            func_0803473C(work, 5, 0);
        } else {
            func_0803473C(work, 4, 0);
        }

        act->fieldPosition.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->fieldPosition.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;
        act->fieldPosition.z += work->unk_A0;
        work->unk_A0 += 66;

        if (work->unk_A0 < 0) {
            if ((GetKeysHeld() & B_BUTTON) == 0) {
                work->unk_A0 += 64;
            }
        }

        if ((GetKeysPressed() & A_BUTTON) != 0) {
            work->unk_98 = 0;
            work->unk_94 = 12;
        } else if (work->unk_A0 > 0) {
            work->unk_98 = 0;
            work->unk_94 = 4;
        } else {
            work->unk_98++;
        }

        break;
    case 4:
        if ((GetKeysHeld() & DPAD_ANY) != 0) {
            act->unk_10 += 17;

            if (act->unk_10 > 512) {
                act->unk_10 = 512;
            }
        } else {
            act->unk_10 -= 38;

            if (act->unk_10 < 0) {
                act->unk_10 = 0;
            }
        }

        if (work->unk_A0 < 0x200) {
            func_0803473C(work, 5, 0);
        } else {
            func_0803473C(work, 6, 0);
        }

        act->fieldPosition.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->fieldPosition.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;
        act->fieldPosition.z += work->unk_A0;
        work->unk_A0 += 66;

        if ((GetKeysPressed() & A_BUTTON) != 0) {
            work->unk_98 = 0;
            work->unk_94 = 12;
        } else if (act->fieldPosition.z > z) {
            act->fieldPosition.z = z;
            work->unk_A0 = 0;

            if (work->unk_94 != 5) {
                work->unk_94 = 5;
                work->unk_98 = 0;
            }
        }

        break;
    case 5:
        if (work->unk_98 == 0) {
            func_0803473C(work, 7, 0);
            m4aSongNumStart(work->unk_AC[3]);
        }

        act->unk_10 = 0;

        if ((GetKeysPressed() & B_BUTTON) != 0) {
            work->unk_A4 &= ~4;
            work->unk_98 = 0;
            work->unk_94 = 2;
        } else if (work->unk_98 > 6) {
            gFieldState->flags &= ~0x800000;
            work->unk_A4 &= ~4;
            work->unk_94 = 0;
            work->unk_98 = 0;
            SetTaskUpdate(task, (TaskUpdateFunc)task_fld_riku_1);
        } else {
            work->unk_98++;
        }

        break;
    }

    if (work->unk_64 != 0) {
        switch (work->unk_6C) {
        case 3:
        case 5:
        case 11:
            break;
        default:
            if ((work->flags & 1) == 0) {
                act->unk_10 = 230 * act->unk_10 >> 8;
                act->fieldPosition.x += work->unk_70;
                act->fieldPosition.y += work->unk_74;
            }
            break;
        }
    }

    if (func_08034518(&act->fieldPosition) != 0) {
        act->fieldPosition.x = sx;
        act->fieldPosition.y = sy;

        switch (func_080345EC(&act->fieldPosition, work)) {
        case 2:
            work->unk_98 = 0;
            work->unk_94 = 6;
            act->angle = 211;
            SetTaskUpdate(task, (TaskUpdateFunc)func_080353DC);
            break;
        case 1:
            work->unk_98 = 0;
            work->unk_94 = 6;
            act->angle = 45;
            SetTaskUpdate(task, (TaskUpdateFunc)func_080353DC);
            break;
        default:
            if (work->unk_94 == 4 && act->fieldPosition.unk_0C - act->fieldPosition.z > 0xFFF) {
                p1 = act->fieldPosition;
                p1.y -= 0x400;
                p1.z = act->fieldPosition.z - 0x3000;
                p2 = p1;
                p2.z += 768;

                if (func_08034518(&p1) == 0 && func_08034518(&p2) != 0) {
                    work->unk_98 = 0;
                    work->unk_94 = 8;
                    gFieldState->unk_68 = 0;
                    SetTaskUpdate(task, (TaskUpdateFunc)func_080358F0);
                }
            } else {
                act->unk_10 = 230 * act->unk_10 >> 8;
            }
            break;
        }
    }

    ColliderSetPosition(work->unk_38, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
    func_080E0298(act->fieldPosition.x, act->fieldPosition.y + act->fieldPosition.z);
    work->gfx = AnimUpdate(work->anim);
    TaskPoolUpdate(work->tasks);

    if ((gFieldState->flags & 0x40000) != 0) {
        work->unk_98 = 0;
        SetTaskUpdate(task, (TaskUpdateFunc)func_08034A0C);
    }

    return 1;
}
u8 func_080353DC(FldWork* work, void* task) {
    FldActor* act;
    FldPos p;
    s32 x;
    s32 y;
    s32 limit;
    s32 d;
    s32 ny;
    s32 nx;
    s32 tx;
    s32 ty;

    act = &gFieldState->actor;
    limit = func_080346C0(work);
    x = act->fieldPosition.x;
    y = act->fieldPosition.y;
    gFieldState->unk_68 = 0;

    switch (work->unk_94) {
    case 6:
        if (work->unk_98 == 0) {
            work->unk_B8 = (act->fieldPosition.z >> 12) << 12;
            work->unk_98++;
            tx = (work->unk_B0 >> 11) / 4;
            ty = (work->unk_B4 >> 11) / 2;
            nx = (tx << 13) | 0x1000;
            ny = (ty << 12) | 0x800;
            x = nx;
            act->fieldPosition.x = nx;
            y = ny;
            act->fieldPosition.y = ny;
            m4aSongNumStart(work->unk_AC[5]);
            act->fieldPosition.unk_0C = func_080DFF1C(&act->fieldPosition);
        }

        func_0803473C(work, 8, 1);
        work->unk_16 = ((act->fieldPosition.z >> 8) + 4) & 31;
        work->gfx = AnimGetGfx(work->anim);

        if (work->unk_12 == 0) {
            switch (work->unk_16) {
            case 8:
                m4aSongNumStart(work->unk_AC[4]);
                break;
            case 24:
                m4aSongNumStart(work->unk_AC[5]);
                break;
            }
        }

        d = (((work->unk_B8 >> 12) << 12) - act->fieldPosition.z) >> 1;

        if (abs(d) <= 24) {
            d = 0;
        } else if (d > 384) {
            d = 384;
        } else if (d < -384) {
            d = -384;
        }

        act->fieldPosition.z += d;

        if (d < 0) {
            act->fieldPosition.x += gSineTable[act->angle];
            act->fieldPosition.y -= gSineTable[act->angle + 64];
            p = act->fieldPosition;
            p.z = work->unk_B8 - 0x2800;

            if (func_08034518(&p) == 0) {
                act->unk_10 = 204;
                work->unk_A0 = -0x580;
                work->unk_A4 |= 4;
                work->unk_94 = 7;
                work->unk_98 = 0;
                m4aSongNumStart(work->unk_AC[6]);
            }
        } else if (d > 0) {
            if (act->fieldPosition.z >= limit) {
                act->fieldPosition.z = limit;
                act->angle += 0x80;
                act->fieldPosition.x += gSineTable[act->angle] * 10;
                act->fieldPosition.y += -gSineTable[act->angle + 64] * 10;
                func_0803473C(work, 0, 1);
                work->gfx = AnimGetGfx(work->anim);
                work->unk_94 = 0;
                work->unk_98 = 0;
                SetTaskUpdate(task, (TaskUpdateFunc)task_fld_riku_1);
            }
        } else if (d == 0) {
            if ((GetKeysHeld() & DPAD_UP) || ((GetKeysHeld() & DPAD_LEFT) && act->angle == 0xD3) ||
                ((GetKeysHeld() & DPAD_RIGHT) && act->angle == 0x2D)) {
                work->unk_B8 = ((work->unk_B8 >> 12) - 1) << 12;
            } else if ((GetKeysHeld() & DPAD_DOWN) || ((GetKeysHeld() & DPAD_RIGHT) && act->angle == 0xD3) ||
                       ((GetKeysHeld() & DPAD_LEFT) && act->angle == 0x2D)) {
                work->unk_B8 = ((work->unk_B8 >> 12) + 1) << 12;
            }
        }

        if (GetKeysPressed() & B_BUTTON) {
            work->unk_A0 = 0;
            work->unk_98 = 0;
            work->unk_94 = 4;
            act->angle += 0x80;
            act->unk_10 = 0x80;
            work->unk_A4 |= 4;
            act->fieldPosition.x += gSineTable[act->angle] * 10;
            act->fieldPosition.y += -gSineTable[act->angle + 64] * 10;
            func_0803473C(work, 6, 0);
            work->gfx = AnimGetGfx(work->anim);
            SetTaskUpdate(task, (TaskUpdateFunc)func_08034C88);
        }

        break;
    case 7:
        func_0803473C(work, 11, 0);
        act->fieldPosition.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->fieldPosition.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;
        work->unk_A0 += 0x42;
        act->fieldPosition.z += work->unk_A0;

        if (work->unk_A0 > 0) {
            work->unk_98 = 0;
            work->unk_94 = 4;
            SetTaskUpdate(task, (TaskUpdateFunc)func_08034C88);
        } else {
            work->unk_98++;
        }

        work->gfx = AnimUpdate(work->anim);
        break;
    }

    if (func_08034518(&act->fieldPosition) != 0) {
        act->fieldPosition.x = x;
        act->fieldPosition.y = y;
    }

    ColliderSetPosition(work->unk_38, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
    func_080E0298(act->fieldPosition.x, act->fieldPosition.y + act->fieldPosition.z);
    TaskPoolUpdate(work->tasks);
    return 1;
}
u8 func_080357F4(FldWork* work, void* task) {
    FldActor* act;

    act = &gFieldState->actor;

    if ((GetKeysPressed() & B_BUTTON) || (GetKeysPressed() & DPAD_DOWN) ||
        (act->angle == 0xD3 && (GetKeysPressed() & DPAD_RIGHT)) ||
        (act->angle == 0x2D && (GetKeysPressed() & DPAD_LEFT))) {
        work->unk_98 = 0;
        work->unk_94 = 4;
        work->unk_A0 = 0;
        act->angle += 0x80;
        gFieldState->unk_68 = 0;
        SetTaskUpdate(task, (TaskUpdateFunc)func_08034C88);
        return 1;
    }

    if ((GetKeysHeld() & DPAD_UP) ||
        (act->angle == 0xD3 && (GetKeysHeld() & DPAD_LEFT)) ||
        (act->angle == 0x2D && (GetKeysHeld() & DPAD_RIGHT))) {
        work->unk_98 = 0;
        work->unk_94 = 10;
        act->unk_10 = 0x133;
        work->unk_A0 = -0x5C0;
        work->unk_A4 |= 4;
        m4aSongNumStart(SONG_SYS_SR_CATJP);
        gFieldState->unk_68 = 0;
        return 1;
    }

    return 0;
}
u8 func_080358F0(FldWork* work, void* task) {
    FldActor* act;
    FldPos p;
    u8 ret;
    s32 x;
    s32 y;

    act = &gFieldState->actor;
    ret = 0;
    x = act->fieldPosition.x;
    y = act->fieldPosition.y;
    gFieldState->unk_68 = 0;

    switch (work->unk_94) {
    case 8:
        if (work->unk_98 == 0) {
            p = act->fieldPosition;
            p.y -= 0xA00;
            act->fieldPosition.z = func_080DFF1C(&p) + 0x2B00;
            m4aSongNumStart(SONG_SYS_SR_CATCH);
            act->angle = func_080DFF94(act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
            func_0803473C(work, 9, 0);
        }

        if (work->unk_98 > 15) {
            ret = func_080357F4(work, task);
        }

        act->fieldPosition.x += gSineTable[act->angle];
        act->fieldPosition.y -= gSineTable[act->angle + 64];

        if (AnimIsFinished(work->anim) != 0 && ret == 0) {
            work->unk_94 = 9;
        } else {
            work->unk_98++;
        }

        break;
    case 9:
        func_0803473C(work, 10, 0);
        func_080357F4(work, task);
        break;
    case 10:
        func_0803473C(work, 11, 0);
        act->fieldPosition.x += gSineTable[act->angle] * act->unk_10 >> 8;
        act->fieldPosition.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;
        act->fieldPosition.z += work->unk_A0;
        work->unk_A0 += 0x42;

        if (work->unk_A0 > 0) {
            work->unk_98 = 0;
            work->unk_94 = 4;
            SetTaskUpdate(task, (TaskUpdateFunc)func_08034C88);
        } else {
            work->unk_98++;
        }

        break;
    }

    work->gfx = AnimUpdate(work->anim);

    if (func_08034518(&act->fieldPosition) != 0) {
        act->fieldPosition.x = x;
        act->fieldPosition.y = y;
    }

    ColliderSetPosition(work->unk_38, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
    func_080E0298(act->fieldPosition.x, act->fieldPosition.y + act->fieldPosition.z);
    TaskPoolUpdate(work->tasks);
    return 1;
}
u8 func_08035AD4(FldWork* work, void* task) {
    FldActor* act;

    act = &gFieldState->actor;

    switch (work->unk_94) {
    case 15:
        if (work->unk_98 == 0) {
            work->unk_A4 |= 0x10;
            act->angle = 45;
            func_0803473C(work, 2, 1);

            act->fieldPosition.x = 0x22000;
            act->fieldPosition.y = 0xF000;
            work->unk_9A = 30;
            act->fieldPosition.z = 0;
            act->fieldPosition.unk_0C = 0;
            work->unk_B0 = act->fieldPosition.x + 0x2000;
            work->unk_B4 = act->fieldPosition.y - 0x1000;
            work->unk_B8 = act->fieldPosition.unk_0C - 0x2800;
        }

        if (work->unk_9A > 0) {
            ApproachValue(&act->fieldPosition.x, work->unk_B0, work->unk_9A);
            ApproachValue(&act->fieldPosition.y, work->unk_B4, work->unk_9A);
            ApproachValue(&act->fieldPosition.z, work->unk_B8, work->unk_9A);
            act->fieldPosition.unk_0C = act->fieldPosition.z;
            work->unk_9A--;
        }

        if (work->unk_12 == 0) {
            switch (work->unk_16) {
            case 3:
                m4aSongNumStart(work->unk_AC[0]);
                break;
            case 7:
                m4aSongNumStart(work->unk_AC[1]);
                break;
            }
        }

        if (work->unk_9A <= 0) {
            work->unk_98 = 0;

            if (work->unk_A4 & 0x20) {
                work->unk_94 = 16;
            } else {
                work->unk_94 = 17;
            }
        } else {
            work->unk_98++;
        }

        break;
    case 16:
        if (work->unk_98 == 0) {
            work->unk_9A = 25;
            work->unk_B0 = act->fieldPosition.x + 0x2000;
            work->unk_B4 = act->fieldPosition.y - 0x1000;
        }

        if (work->unk_9A > 0) {
            ApproachValue(&act->fieldPosition.x, work->unk_B0, work->unk_9A);
            ApproachValue(&act->fieldPosition.y, work->unk_B4, work->unk_9A);
            work->unk_9A--;
        }

        if (work->unk_12 == 0) {
            switch (work->unk_16) {
            case 3:
                m4aSongNumStart(work->unk_AC[0]);
                break;
            case 7:
                m4aSongNumStart(work->unk_AC[1]);
                break;
            }
        }

        if (work->unk_9A <= 0) {
            work->unk_98 = 0;
            work->unk_94 = 18;
        } else {
            work->unk_98++;
        }

        break;
    case 17:
        if (work->unk_98 == 0) {
            work->unk_9A = 25;
            work->unk_B0 = act->fieldPosition.x + 0x2000;
            work->unk_B4 = act->fieldPosition.y - 0x1000;
        }

        if (work->unk_9A > 0) {
            ApproachValue(&act->fieldPosition.x, work->unk_B0, work->unk_9A);
            ApproachValue(&act->fieldPosition.y, work->unk_B4, work->unk_9A);
            work->unk_9A--;
        }

        if (work->unk_12 == 0) {
            switch (work->unk_16) {
            case 3:
                m4aSongNumStart(work->unk_AC[0]);
                break;
            case 7:
                m4aSongNumStart(work->unk_AC[1]);
                break;
            }
        }

        if (work->unk_9A <= 0) {
            work->unk_98 = 0;
            work->unk_94 = 19;
        } else {
            work->unk_98++;
        }

        break;
    case 18:
        if (work->unk_98 == 0) {
            func_0803473C(work, 12, 0);
            FadeSetPaletteExcluded(work->palette->index + 16, 1);
        }

        if (work->unk_98 == 40) {
            CreateWorldSelBeforeTask(work->tasks, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
        }

        if (work->unk_98 > 140) {
            work->unk_98 = 0;
            work->unk_94 = 19;
        } else {
            work->unk_98++;
        }

        break;
    case 19:
        func_080DFC7C();
        break;
    }

    ColliderSetPosition(work->unk_38, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
    func_080E0298(act->fieldPosition.x, act->fieldPosition.y + act->fieldPosition.z);
    work->gfx = AnimUpdate(work->anim);
    TaskPoolUpdate(work->tasks);
    return 1;
}
u8 func_08035DFC(FldWork* work, void* task) {
    FldActor* act;
    s32 x;
    s32 y;
    s32 nx;
    s32 ny;

    act = &gFieldState->actor;
    x = act->fieldPosition.x;
    y = act->fieldPosition.y;

    if (work->unk_94 == 11) {
        if (work->unk_98 == 0) {
            func_0803473C(work, 13, 0);
            act->unk_10 = 0;
            gFieldState->unk_68 = 0;
            work->unk_9A = 0;
            m4aSongNumStart(SONG_SND_227);
        }

        if (work->unk_12 == 0) {
            switch (act->angle) {
            case 173:
                switch (AnimGetFrame(work->anim)) {
                case 0:
                    act->fieldPosition.x -= 0x500;
                    act->fieldPosition.y += 0x400;
                    break;
                case 1:
                    act->fieldPosition.x -= 0x200;
                    break;
                case 2:
                    act->fieldPosition.x -= 0x300;
                    break;
                }

                break;
            case 83:
                switch (AnimGetFrame(work->anim)) {
                case 0:
                    act->fieldPosition.x += 0x500;
                    act->fieldPosition.y += 0x400;
                    break;
                case 1:
                    act->fieldPosition.x += 0x200;
                    break;
                case 2:
                    act->fieldPosition.x += 0x300;
                    break;
                }

                break;
            case 211:
                switch (AnimGetFrame(work->anim)) {
                case 0:
                    act->fieldPosition.x -= 0x500;
                    act->fieldPosition.y -= 0x200;
                    break;
                case 1:
                    act->fieldPosition.x -= 0x500;
                    break;
                case 2:
                    act->fieldPosition.x -= 0x200;
                    break;
                }

                break;
            case 45:
                switch (AnimGetFrame(work->anim)) {
                case 0:
                    act->fieldPosition.x += 0x500;
                    act->fieldPosition.y -= 0x200;
                    break;
                case 1:
                    act->fieldPosition.x += 0x500;
                    break;
                case 2:
                    act->fieldPosition.x += 0x200;
                    break;
                }

                break;
            case 128:
                switch (AnimGetFrame(work->anim)) {
                case 0:
                    act->fieldPosition.x -= 0x300;
                    act->fieldPosition.y += 0x400;
                    break;
                case 1:
                    act->fieldPosition.x += 0x100;
                    act->fieldPosition.y += 0x100;
                    break;
                case 2:
                    act->fieldPosition.y += 0x200;
                    break;
                case 3:
                    act->fieldPosition.y += 0x100;
                    break;
                }

                break;
            case 64:
                switch (AnimGetFrame(work->anim)) {
                case 0:
                    act->fieldPosition.x += 0x700;
                    act->fieldPosition.y += 0x100;
                    break;
                case 1:
                    act->fieldPosition.x += 0x300;
                    break;
                case 2:
                    act->fieldPosition.x += 0x200;
                    break;
                }

                break;
            case 192:
                switch (AnimGetFrame(work->anim)) {
                case 0:
                    act->fieldPosition.x -= 0x700;
                    act->fieldPosition.y += 0x100;
                    break;
                case 1:
                    act->fieldPosition.x -= 0x300;
                    break;
                case 2:
                    act->fieldPosition.x -= 0x200;
                    break;
                }

                break;
            case 0:
                switch (AnimGetFrame(work->anim)) {
                case 0:
                    act->fieldPosition.y -= 0x400;
                    break;
                case 1:
                    act->fieldPosition.y -= 0x400;
                    break;
                case 2:
                    act->fieldPosition.x -= 0x100;
                    act->fieldPosition.y += 0x100;
                    break;
                case 3:
                    act->fieldPosition.y -= 0x100;
                    break;
                }

                break;
            }
        }

        if (AnimGetFrame(work->anim) == 3) {
            switch (act->angle) {
            case 45:
            case 211:
                nx = act->fieldPosition.x + gSineTable[act->angle] * 12;
                ny = act->fieldPosition.y + -gSineTable[act->angle + 64] * 12;
                break;
            case 64:
            case 192:
                nx = act->fieldPosition.x + gSineTable[act->angle] * 27;
                ny = act->fieldPosition.y + -gSineTable[act->angle + 64] * 27;
                break;
            case 0:
            case 83:
            case 128:
            case 173:
            default:
                nx = act->fieldPosition.x + gSineTable[act->angle] * 20;
                ny = act->fieldPosition.y + -gSineTable[act->angle + 64] * 20;
                break;
            }

            func_080E02C0(nx, ny, act->fieldPosition.z - 0x800);
        }

        if (AnimIsFinished(work->anim) != 0) {
            switch (act->angle) {
            case 173:
                act->fieldPosition.x -= 0x200;
                act->fieldPosition.y += 0x200;
                break;
            case 83:
                act->fieldPosition.x += 0x200;
                act->fieldPosition.y += 0x200;
                break;
            case 45:
            case 211:
                act->fieldPosition.y -= 0x400;
                break;
            case 128:
                act->fieldPosition.y += 0x200;
                break;
            case 0:
                act->fieldPosition.y -= 0x200;
                break;
            }

            func_0803473C(work, 0, 0);
            work->unk_94 = 0;
            SetTaskUpdate(task, (TaskUpdateFunc)task_fld_riku_1);
        } else {
            work->unk_98++;
        }
    }

    if (work->unk_64 != 0) {
        switch (work->unk_6C) {
        case 5:
        case 3:
        case 11:
            break;
        default:
            if ((work->flags & 1) == 0) {
                act->fieldPosition.x += work->unk_70;
                act->fieldPosition.y += work->unk_74;
            }

            break;
        }
    }

    if (func_08034518(&act->fieldPosition) != 0) {
        act->fieldPosition.x = x;
        act->fieldPosition.y = y;
    }

    ColliderSetPosition(work->unk_38, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
    func_080E0298(act->fieldPosition.x, act->fieldPosition.y + act->fieldPosition.z);
    work->gfx = AnimUpdate(work->anim);
    TaskPoolUpdate(work->tasks);

    if (gFieldState->flags & 0x40000) {
        work->unk_98 = 0;
        SetTaskUpdate(task, (TaskUpdateFunc)func_08034A0C);
        TaskPoolUpdate(work->tasks);
    }

    return 1;
}
u8 task_fld_riku_1(FldWork* work, void* task) {
    FldPos p1;
    FldPos p2;
    FldPos p3;
    FldPos p4;
    s32 sx;
    s32 sy;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 dw;
    s32 z;
    s32 r;
    u8 a;
    u8 b;
    FldActor* act;

    act = &gFieldState->actor;

    if ((work->unk_A4 & 8) != 0) {
        work->unk_A4 &= ~8;

        switch (work->unk_94) {
        case 12:
            work->unk_94 = 3;
        case 2:
        case 3:
        case 4:
        case 5:
            SetTaskUpdate(task, (TaskUpdateFunc)func_08034C88);
            gFieldState->unk_68 = 0;
            break;
        case 6:
        case 7:
            SetTaskUpdate(task, (TaskUpdateFunc)func_080353DC);
            gFieldState->unk_68 = 0;
            work->unk_98 = 1;
            break;
        case 8:
        case 9:
        case 10:
            SetTaskUpdate(task, (TaskUpdateFunc)func_080358F0);
            gFieldState->unk_68 = 0;
            break;
        default:
            work->unk_94 = 0;
            break;
        }

        ColliderSetPosition(work->unk_38, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
        func_080E0298(act->fieldPosition.x, act->fieldPosition.y + act->fieldPosition.z);
        work->gfx = AnimUpdate(work->anim);
        TaskPoolUpdate(work->tasks);
        return 1;
    } else if (func_080DFC24() != 0) {
        work->unk_98 = 0;
        SetTaskUpdate(task, (TaskUpdateFunc)func_08035AD4);
        TaskPoolUpdate(work->tasks);
        work->unk_94 = 15;

        if (func_080DFC24() == 1) {
            work->unk_A4 |= 0x20;
        }

        return 1;
    } else if ((gFieldState->flags & 0x40000) != 0) {
        work->unk_98 = 0;
        SetTaskUpdate(task, (TaskUpdateFunc)func_08034A0C);
        TaskPoolUpdate(work->tasks);
        return 1;
    } else {
        sx = act->fieldPosition.x;
        sy = act->fieldPosition.y;

        if (work->unk_94 <= 1) {
            if ((gFieldState->flags & 0x4000) == 0) {
                func_08034704(act);
            }

            if ((gFieldState->flags & 0x4000) == 0 && (GetKeysHeld() & DPAD_ANY) != 0) {
                act->unk_10 += 128;
                func_0803473C(work, 2, 1);

                if (act->unk_10 > 0x300) {
                    act->unk_10 = 0x300;
                }

                if (work->unk_12 == 0) {
                    switch (work->unk_16) {
                    case 3:
                        m4aSongNumStart(work->unk_AC[0]);
                        break;
                    case 7:
                        m4aSongNumStart(work->unk_AC[1]);
                        break;
                    }
                }
            } else {
                func_0803473C(work, 0, 1);
                act->unk_10 -= 128;

                if (act->unk_10 < 0) {
                    act->unk_10 = 0;
                }
            }

            act->fieldPosition.x += gSineTable[act->angle] * act->unk_10 >> 8;
            act->fieldPosition.y += -gSineTable[act->angle + 64] * act->unk_10 >> 8;

            if ((GetKeysPressed() & B_BUTTON) != 0) {
                gFieldState->flags |= 0x800000;
                gFieldState->unk_68 = 0;
                work->unk_98 = 0;
                work->unk_94 = 2;
                SetTaskUpdate(task, (TaskUpdateFunc)func_08034C88);
                m4aSongNumStart(work->unk_AC[2]);
            } else if ((GetKeysPressed() & A_BUTTON) != 0) {
                work->unk_98 = 0;
                gFieldState->unk_68 = 0;
                work->unk_94 = 11;
                SetTaskUpdate(task, (TaskUpdateFunc)func_08035DFC);
            }
        } else if (AnimIsFinished(work->anim) != 0) {
            work->unk_94 = 0;
        }

        if (work->unk_64 != 0) {
            switch (work->unk_6C) {
            case 3:
            case 5:
            case 11:
                break;
            default:
                if ((work->flags & 1) == 0) {
                    act->unk_10 = 230 * act->unk_10 >> 8;
                    act->fieldPosition.x += work->unk_70;
                    act->fieldPosition.y += work->unk_74;
                }
                break;
            }
        }

        if (func_08034518(&act->fieldPosition) != 0) {
            act->fieldPosition.x = sx;
            act->fieldPosition.y = sy;
            r = func_080345EC(&act->fieldPosition, work);

            if (r != 0) {
                switch (r) {
                case 2:
                    work->unk_98 = 0;
                    work->unk_94 = 6;
                    act->angle = 211;
                    gFieldState->unk_68 = 0;
                    SetTaskUpdate(task, (TaskUpdateFunc)func_080353DC);
                    break;
                case 1:
                    work->unk_98 = 0;
                    work->unk_94 = 6;
                    act->angle = 45;
                    gFieldState->unk_68 = 0;
                    SetTaskUpdate(task, (TaskUpdateFunc)func_080353DC);
                    break;
                }
            } else {
                if (func_08034668(&act->fieldPosition) != 0) {
                    FadeSetPaletteExcluded(work->palette->index + 16, 1);
                    gFieldState->flags |= 16;
                    return 1;
                }

                switch (act->angle) {
                case 173:
                    dx = -256;
                    dy = 0;
                    dz = 0;
                    dw = 384;
                    break;
                case 83:
                    dx = 256;
                    dy = 0;
                    dz = 0;
                    dw = 384;
                    break;
                case 211:
                    dx = -256;
                    dy = 0;
                    dz = 0;
                    dw = -384;
                    break;
                case 45:
                    dx = 256;
                    dy = 0;
                    dz = 0;
                    dw = -384;
                    break;
                case 128:
                    dx = -512;
                    dy = 192;
                    dz = 512;
                    dw = 192;
                    break;
                case 0:
                    dx = -512;
                    dy = -192;
                    dz = 512;
                    dw = -192;
                    break;
                case 64:
                    dx = 384;
                    dy = -307;
                    dz = 384;
                    dw = 307;
                    break;
                case 192:
                    dx = -384;
                    dy = -307;
                    dz = -384;
                    dw = 307;
                    break;
                default:
                    dw = 0;
                    dz = 0;
                    dy = 0;
                    dx = 0;
                    break;
                }

                p2 = act->fieldPosition;
                p1 = p2;
                p1.x += dx;
                p1.y += dy;
                p2.x += dz;
                p2.y += dw;
                a = func_08034518(&p1);
                b = func_08034518(&p2);

                if (a != 0) {
                    if (b == 0) {
                        p3 = act->fieldPosition;
                        p3.x += dz;
                        p3.y += dw;
                        p3.unk_0C = func_0803459C(&p3);

                        if (p3.unk_0C >= p3.z) {
                            act->fieldPosition = p3;
                        }
                    }
                } else if (b != 0) {
                    p4 = act->fieldPosition;
                    p4.x += dx;
                    p4.y += dy;
                    p4.unk_0C = func_0803459C(&p4);

                    if (p4.unk_0C >= p4.z) {
                        act->fieldPosition = p4;
                    }
                }

                act->unk_10 = 0;
            }
        }

        z = func_080346C0(work);

        if (act->fieldPosition.unk_0C == 0x100000) {
            act->fieldPosition.unk_0C = act->fieldPosition.z;
        } else if (z != act->fieldPosition.z) {
            act->unk_10 >>= 2;
            work->unk_A0 = 0;
            work->unk_98 = 0;
            gFieldState->unk_68 = 0;
            gFieldState->flags |= 0x800000;
            work->unk_94 = 4;
            SetTaskUpdate(task, (TaskUpdateFunc)func_08034C88);
        } else if (z != act->fieldPosition.unk_0C) {
            gFieldState->unk_68 = 0;
        }
    }

    ColliderSetPosition(work->unk_38, act->fieldPosition.x, act->fieldPosition.y, act->fieldPosition.z);
    func_080E0298(act->fieldPosition.x, act->fieldPosition.y + act->fieldPosition.z);
    work->gfx = AnimUpdate(work->anim);
    TaskPoolUpdate(work->tasks);
    return 1;
}

void task_fld_riku_2(FldWork* work) {
    FldActor* act;
    u16 depth;
    s32 pri;
    s32 x;
    s32 y;
    s32 z;

    act = &gFieldState->actor;
    pri = (work->unk_A4 & 2) ? 0x801 : 0x800;

    if (work->unk_BC != 0) {
        depth = -0x1006 - (work->unk_80 >> 8) * 4;

        if (work->unk_84 <= work->unk_48) {
            act->unk_3A = 0;
            act->unk_3C = func_080DFF1C(&act->fieldPosition);
        } else {
            act->unk_3C = work->unk_78;
            act->unk_3A = depth + 1;
        }
    } else {
        depth = -0x1004 - (act->fieldPosition.y >> 8) * 4;

        if (work->unk_A4 & 0x10) {
            act->unk_3C = act->fieldPosition.unk_0C;
        } else {
            act->unk_3C = func_080DFF1C(&act->fieldPosition);
        }

        if (act->unk_3C != act->fieldPosition.unk_0C) {
            act->unk_3A = 0;
        } else {
            act->unk_3A = depth + 1;
        }
    }

    x = (act->fieldPosition.x >> 8) - (gFieldState->x >> 8);
    y = (act->fieldPosition.y >> 8) + (act->fieldPosition.z >> 8) - (gFieldState->y >> 8);
    DrawSprite(x, y, work->gfx, work->tiles, work->palette, 0, pri, depth);
    TaskPoolDraw(work->tasks);
}

void task_fld_riku_3(FldWork* work) {
    FldActor* act;

    act = &gFieldState->actor;
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
    ColliderUnregister(work->unk_38);

    if (gGameState.unk_000 != 0) {
        gGameState.unk_028 = act->unk_10;
        gGameState.fieldPosition = act->fieldPosition;
        gGameState.unk_024 = act->angle;
        gGameState.unk_030 = work->unk_94;
        gGameState.unk_02C = work->unk_A0;
        gGameState.unk_034 = work->unk_B0;
        gGameState.unk_038 = work->unk_B4;
        gGameState.unk_03C = work->unk_B8;
    } else {
        gGameState.unk_024 = act->angle;
    }

    TaskPoolDestroy(work->tasks);
}

void task_fld_shadow_0(FldShadowWork* work, FldActor* obj) {
    work->actor = obj;
    work->x = obj->fieldPosition.x;
    work->y = obj->fieldPosition.y;
    work->tiles = LoadObjTiles(gUnk_08B22BBC, 0x100);
    work->palette = LoadObjPalette(gUnk_08F69BE4, 32);
    AnimInit(work->anim, gUnk_09EE1384, gUnk_09EE1380);
    AnimStart(work->anim, 0, 1);
}

s32 task_fld_shadow_1(FldShadowWork* work) {
    work->x = work->actor->fieldPosition.x;
    work->y = work->actor->fieldPosition.y;
    return 1;
}

void task_fld_shadow_2(FldShadowWork* work) {
    FldActor* obj;
    void* spr;
    s32 z;
    s32 size;
    s32 sprite;
    s32 x;
    s32 y;

    obj = work->actor;

    if (obj->unk_3A == 0) {
        return;
    }

    spr = AnimUpdate(work->anim);
    z = obj->unk_3C;

    if (obj->fieldPosition.z >= z) {
        sprite = 0;
    } else {
        size = 0x100 - (z - obj->fieldPosition.z) / 128;

        if (size <= 0x18) {
            size = 0x19;
        }

        sprite = AllocObjAffine(0, size, size, 0);
    }

    x = (work->x >> 8) - (gFieldState->x >> 8);
    y = (work->y >> 8) + (z >> 8) - (gFieldState->y >> 8);
    DrawSprite(x, y, spr, work->tiles, work->palette, sprite, 0x800, obj->unk_3A);
}

void task_fld_shadow_3(FldShadowWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

TaskDesc gTaskDescFldRiku = { "task_fld_riku", task_fld_riku_0, task_fld_riku_1, task_fld_riku_2, task_fld_riku_3, 0xC0 };

TaskDesc gTaskDescFldShadow = { "task_fld_shadow", task_fld_shadow_0, task_fld_shadow_1, task_fld_shadow_2, task_fld_shadow_3, 0x2C };
