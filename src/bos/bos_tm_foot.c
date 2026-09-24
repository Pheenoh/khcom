#include "macros.h"
#include "registration_data.h"
#include "boss_tm.h"
#include "boss_tm_assets.h"
#include "sprites_boss_tm.h"
#include "engine_math.h"
#include "m4a_song.h"
#include "btl_effect.h"
#include "system_state.h"
#include "acgtrans.h"
#include "sprites_wlogo.h"

extern u8 gUnk_09EF21B0[8];
extern s16 gUnk_09EF21B8[5];
extern TmFootStep gBosTmFootSteps[3];
extern TmFootStep gUnk_09EF2244[16];
extern TmFootStep gUnk_09EF2464[10];
extern TmFootStep gUnk_09EF25A4[9];

s16 gUnk_0203AC60 EWRAM_COMMON(4);
s32 gUnk_0203AC64 EWRAM_COMMON(4);
s16 gUnk_0203AC68 EWRAM_COMMON(4);
s16 gUnk_0203AC6C EWRAM_COMMON(4);
s32 gUnk_0203AC70 EWRAM_COMMON(4);
u16 gUnk_0203AC74 EWRAM_COMMON(4);
s32 gUnk_0203AC78 EWRAM_COMMON(4);

const char gTaskNameBosTmFoot[] = "task_bos_tm_foot";

const char gTaskNameBosTmClb[] = "task_bos_tm_clb";

const TmAnimFrame gUnk_09619CDC[3] = {
    { 10, { 0, 0 }, { 175, 0, 0, 0, 160, 0, 0, 0, 140, 0, 0, 0, 0, 0, 0, 0 } },
    { 10, { 0, 0 }, { 175, 0, 0, 0, 155, 0, 0, 0, 145, 0, 0, 0, 180, 0, 0, 0 } },
    { 10, { 0, 0 }, { 175, 0, 0, 0, 165, 0, 0, 0, 152, 0, 0, 0, 220, 0, 0, 0 } },
};

const TmAnimFrame gUnk_09619D18[3] = {
    { 10, { 0, 0 }, { 80, 0, 0, 0, 102, 0, 0, 0, 95, 0, 0, 0, 160, 0, 0, 0 } },
    { 10, { 0, 0 }, { 90, 0, 0, 0, 128, 0, 0, 0, 220, 0, 0, 0, 240, 0, 0, 0 } },
    { 10, { 0, 0 }, { 76, 0, 0, 0, 128, 0, 0, 0, 160, 0, 0, 0, 224, 0, 0, 0 } },
};

const TmAnimFrame gUnk_09619D54[3] = {
    { 10, { 0, 0 }, { 176, 0, 0, 0, 154, 0, 0, 0, 161, 0, 0, 0, 160, 0, 0, 0 } },
    { 10, { 0, 0 }, { 166, 0, 0, 0, 128, 0, 0, 0, 36, 0, 0, 0, 240, 0, 0, 0 } },
    { 10, { 0, 0 }, { 180, 0, 0, 0, 128, 0, 0, 0, 96, 0, 0, 0, 224, 0, 0, 0 } },
};

const TmAnimFrame gUnk_09619D90[3] = {
    { 10, { 0, 0 }, { 81, 0, 0, 0, 96, 0, 0, 0, 116, 0, 0, 0, 0, 0, 0, 0 } },
    { 10, { 0, 0 }, { 81, 0, 0, 0, 101, 0, 0, 0, 111, 0, 0, 0, 180, 0, 0, 0 } },
    { 10, { 0, 0 }, { 81, 0, 0, 0, 91, 0, 0, 0, 104, 0, 0, 0, 220, 0, 0, 0 } },
};

const TmAnimFrame gUnk_09619DCC[1] = {
    { 5, { 0, 0 }, { 128, 0, 0, 0, 128, 0, 0, 0, 108, 0, 0, 0, 214, 0, 0, 0 } },
};

const TmAnimFrame gUnk_09619DE0[1] = {
    { 5, { 0, 0 }, { 128, 0, 0, 0, 128, 0, 0, 0, 108, 0, 0, 0, 64, 0, 0, 0 } },
};

const TmAnimFrame gUnk_09619DF4[1] = {
    { 5, { 0, 0 }, { 128, 0, 0, 0, 128, 0, 0, 0, 148, 0, 0, 0, 64, 0, 0, 0 } },
};

const TmAnimFrame gUnk_09619E08[1] = {
    { 5, { 0, 0 }, { 128, 0, 0, 0, 128, 0, 0, 0, 148, 0, 0, 0, 214, 0, 0, 0 } },
};

const TmAnimFrame gUnk_09619E1C[3] = {
    { 2, { 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 2, { 0, 0 }, { 192, 0, 0, 0, 192, 0, 0, 0, 192, 0, 0, 0, 192, 0, 0, 0 } },
    { 250, { 0, 0 }, { 120, 0, 0, 0, 160, 0, 0, 0, 220, 0, 0, 0, 230, 0, 0, 0 } },
};

const TmAnimFrame gUnk_09619E58[3] = {
    { 2, { 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 2, { 0, 0 }, { 192, 0, 0, 0, 192, 0, 0, 0, 192, 0, 0, 0, 192, 0, 0, 0 } },
    { 250, { 0, 0 }, { 120, 0, 0, 0, 160, 0, 0, 0, 220, 0, 0, 0, 5, 0, 0, 0 } },
};

const TmAnimFrame gUnk_09619E94[3] = {
    { 2, { 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 2, { 0, 0 }, { 64, 0, 0, 0, 64, 0, 0, 0, 64, 0, 0, 0, 192, 0, 0, 0 } },
    { 250, { 0, 0 }, { 136, 0, 0, 0, 96, 0, 0, 0, 36, 0, 0, 0, 5, 0, 0, 0 } },
};

const TmAnimFrame gUnk_09619ED0[3] = {
    { 2, { 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { 2, { 0, 0 }, { 64, 0, 0, 0, 64, 0, 0, 0, 64, 0, 0, 0, 192, 0, 0, 0 } },
    { 250, { 0, 0 }, { 136, 0, 0, 0, 112, 0, 0, 0, 36, 0, 0, 0, 245, 0, 0, 0 } },
};

const TmAnimFrame gUnk_09619F0C[6] = {
    { 3, { 0, 0 }, { 192, 0, 0, 0, 208, 0, 0, 0, 224, 0, 0, 0, 240, 0, 0, 0 } },
    { 3, { 0, 0 }, { 0, 0, 0, 0, 24, 0, 0, 0, 33, 0, 0, 0, 40, 0, 0, 0 } },
    { 24, { 0, 0 }, { 38, 0, 0, 0, 53, 0, 0, 0, 68, 0, 0, 0, 83, 0, 0, 0 } },
    { 1, { 0, 0 }, { 248, 0, 0, 0, 121, 0, 0, 0, 106, 0, 0, 0, 91, 0, 0, 0 } },
    { 1, { 0, 0 }, { 188, 0, 0, 0, 203, 0, 0, 0, 218, 0, 0, 0, 233, 0, 0, 0 } },
    { 250, { 0, 0 }, { 148, 0, 0, 0, 163, 0, 0, 0, 178, 0, 0, 0, 193, 0, 0, 0 } },
};

const TmAnimFrame gUnk_09619F84[6] = {
    { 3, { 0, 0 }, { 192, 0, 0, 0, 208, 0, 0, 0, 224, 0, 0, 0, 240, 0, 0, 0 } },
    { 3, { 0, 0 }, { 0, 0, 0, 0, 24, 0, 0, 0, 33, 0, 0, 0, 40, 0, 0, 0 } },
    { 24, { 0, 0 }, { 38, 0, 0, 0, 53, 0, 0, 0, 68, 0, 0, 0, 83, 0, 0, 0 } },
    { 1, { 0, 0 }, { 248, 0, 0, 0, 121, 0, 0, 0, 106, 0, 0, 0, 91, 0, 0, 0 } },
    { 1, { 0, 0 }, { 188, 0, 0, 0, 203, 0, 0, 0, 218, 0, 0, 0, 233, 0, 0, 0 } },
    { 250, { 0, 0 }, { 148, 0, 0, 0, 163, 0, 0, 0, 178, 0, 0, 0, 193, 0, 0, 0 } },
};

const TmAnimFrame gUnk_09619FFC[6] = {
    { 3, { 0, 0 }, { 64, 0, 0, 0, 48, 0, 0, 0, 32, 0, 0, 0, 240, 0, 0, 0 } },
    { 3, { 0, 0 }, { 0, 0, 0, 0, 232, 0, 0, 0, 223, 0, 0, 0, 40, 0, 0, 0 } },
    { 24, { 0, 0 }, { 218, 0, 0, 0, 203, 0, 0, 0, 188, 0, 0, 0, 83, 0, 0, 0 } },
    { 1, { 0, 0 }, { 8, 0, 0, 0, 135, 0, 0, 0, 150, 0, 0, 0, 91, 0, 0, 0 } },
    { 1, { 0, 0 }, { 68, 0, 0, 0, 53, 0, 0, 0, 38, 0, 0, 0, 233, 0, 0, 0 } },
    { 250, { 0, 0 }, { 108, 0, 0, 0, 93, 0, 0, 0, 78, 0, 0, 0, 193, 0, 0, 0 } },
};

const TmAnimFrame gUnk_0961A074[6] = {
    { 3, { 0, 0 }, { 64, 0, 0, 0, 48, 0, 0, 0, 32, 0, 0, 0, 240, 0, 0, 0 } },
    { 3, { 0, 0 }, { 0, 0, 0, 0, 232, 0, 0, 0, 223, 0, 0, 0, 40, 0, 0, 0 } },
    { 24, { 0, 0 }, { 218, 0, 0, 0, 203, 0, 0, 0, 188, 0, 0, 0, 83, 0, 0, 0 } },
    { 1, { 0, 0 }, { 8, 0, 0, 0, 135, 0, 0, 0, 150, 0, 0, 0, 91, 0, 0, 0 } },
    { 1, { 0, 0 }, { 68, 0, 0, 0, 53, 0, 0, 0, 38, 0, 0, 0, 233, 0, 0, 0 } },
    { 250, { 0, 0 }, { 108, 0, 0, 0, 93, 0, 0, 0, 78, 0, 0, 0, 193, 0, 0, 0 } },
};

const TmAnimFrame gUnk_0961A0EC[6] = {
    { 3, { 0, 0 }, { 192, 0, 0, 0, 208, 0, 0, 0, 224, 0, 0, 0, 240, 0, 0, 0 } },
    { 3, { 0, 0 }, { 0, 0, 0, 0, 24, 0, 0, 0, 33, 0, 0, 0, 40, 0, 0, 0 } },
    { 39, { 0, 0 }, { 38, 0, 0, 0, 53, 0, 0, 0, 68, 0, 0, 0, 83, 0, 0, 0 } },
    { 1, { 0, 0 }, { 248, 0, 0, 0, 121, 0, 0, 0, 106, 0, 0, 0, 91, 0, 0, 0 } },
    { 1, { 0, 0 }, { 188, 0, 0, 0, 203, 0, 0, 0, 218, 0, 0, 0, 233, 0, 0, 0 } },
    { 250, { 0, 0 }, { 148, 0, 0, 0, 163, 0, 0, 0, 178, 0, 0, 0, 193, 0, 0, 0 } },
};

const TmAnimFrame gUnk_0961A164[6] = {
    { 3, { 0, 0 }, { 192, 0, 0, 0, 208, 0, 0, 0, 224, 0, 0, 0, 240, 0, 0, 0 } },
    { 3, { 0, 0 }, { 0, 0, 0, 0, 24, 0, 0, 0, 33, 0, 0, 0, 40, 0, 0, 0 } },
    { 39, { 0, 0 }, { 38, 0, 0, 0, 53, 0, 0, 0, 68, 0, 0, 0, 83, 0, 0, 0 } },
    { 1, { 0, 0 }, { 248, 0, 0, 0, 121, 0, 0, 0, 106, 0, 0, 0, 91, 0, 0, 0 } },
    { 1, { 0, 0 }, { 188, 0, 0, 0, 203, 0, 0, 0, 218, 0, 0, 0, 233, 0, 0, 0 } },
    { 250, { 0, 0 }, { 148, 0, 0, 0, 163, 0, 0, 0, 178, 0, 0, 0, 193, 0, 0, 0 } },
};

const TmAnimFrame gUnk_0961A1DC[6] = {
    { 3, { 0, 0 }, { 64, 0, 0, 0, 48, 0, 0, 0, 32, 0, 0, 0, 240, 0, 0, 0 } },
    { 3, { 0, 0 }, { 0, 0, 0, 0, 232, 0, 0, 0, 223, 0, 0, 0, 40, 0, 0, 0 } },
    { 39, { 0, 0 }, { 218, 0, 0, 0, 203, 0, 0, 0, 188, 0, 0, 0, 83, 0, 0, 0 } },
    { 1, { 0, 0 }, { 8, 0, 0, 0, 135, 0, 0, 0, 150, 0, 0, 0, 91, 0, 0, 0 } },
    { 1, { 0, 0 }, { 68, 0, 0, 0, 53, 0, 0, 0, 38, 0, 0, 0, 233, 0, 0, 0 } },
    { 250, { 0, 0 }, { 108, 0, 0, 0, 93, 0, 0, 0, 78, 0, 0, 0, 193, 0, 0, 0 } },
};

const TmAnimFrame gUnk_0961A254[6] = {
    { 3, { 0, 0 }, { 64, 0, 0, 0, 48, 0, 0, 0, 32, 0, 0, 0, 240, 0, 0, 0 } },
    { 3, { 0, 0 }, { 0, 0, 0, 0, 232, 0, 0, 0, 223, 0, 0, 0, 40, 0, 0, 0 } },
    { 39, { 0, 0 }, { 218, 0, 0, 0, 203, 0, 0, 0, 188, 0, 0, 0, 83, 0, 0, 0 } },
    { 1, { 0, 0 }, { 8, 0, 0, 0, 135, 0, 0, 0, 150, 0, 0, 0, 91, 0, 0, 0 } },
    { 1, { 0, 0 }, { 68, 0, 0, 0, 53, 0, 0, 0, 38, 0, 0, 0, 233, 0, 0, 0 } },
    { 250, { 0, 0 }, { 108, 0, 0, 0, 93, 0, 0, 0, 78, 0, 0, 0, 193, 0, 0, 0 } },
};

const TmAnimFrame gUnk_0961A2CC[6] = {
    { 10, { 0, 0 }, { 148, 0, 0, 0, 128, 0, 0, 0, 108, 0, 0, 0, 88, 0, 0, 0 } },
    { 15, { 0, 0 }, { 138, 0, 0, 0, 118, 0, 0, 0, 98, 0, 0, 0, 68, 0, 0, 0 } },
    { 10, { 0, 0 }, { 128, 0, 0, 0, 148, 0, 0, 0, 168, 0, 0, 0, 208, 0, 0, 0 } },
    { 10, { 0, 0 }, { 118, 0, 0, 0, 148, 0, 0, 0, 178, 0, 0, 0, 218, 0, 0, 0 } },
    { 15, { 0, 0 }, { 138, 0, 0, 0, 168, 0, 0, 0, 228, 0, 0, 0, 248, 0, 0, 0 } },
    { 10, { 0, 0 }, { 158, 0, 0, 0, 138, 0, 0, 0, 108, 0, 0, 0, 58, 0, 0, 0 } },
};

const TmAnimFrame gUnk_0961A344[6] = {
    { 10, { 0, 0 }, { 108, 0, 0, 0, 138, 0, 0, 0, 168, 0, 0, 0, 208, 0, 0, 0 } },
    { 15, { 0, 0 }, { 138, 0, 0, 0, 158, 0, 0, 0, 198, 0, 0, 0, 238, 0, 0, 0 } },
    { 10, { 0, 0 }, { 168, 0, 0, 0, 148, 0, 0, 0, 98, 0, 0, 0, 48, 0, 0, 0 } },
    { 10, { 0, 0 }, { 148, 0, 0, 0, 128, 0, 0, 0, 78, 0, 0, 0, 28, 0, 0, 0 } },
    { 15, { 0, 0 }, { 138, 0, 0, 0, 108, 0, 0, 0, 48, 0, 0, 0, 3, 0, 0, 0 } },
    { 10, { 0, 0 }, { 128, 0, 0, 0, 148, 0, 0, 0, 168, 0, 0, 0, 208, 0, 0, 0 } },
};

const TmAnimFrame gUnk_0961A3BC[6] = {
    { 10, { 0, 0 }, { 108, 0, 0, 0, 128, 0, 0, 0, 148, 0, 0, 0, 88, 0, 0, 0 } },
    { 15, { 0, 0 }, { 118, 0, 0, 0, 138, 0, 0, 0, 158, 0, 0, 0, 68, 0, 0, 0 } },
    { 10, { 0, 0 }, { 128, 0, 0, 0, 108, 0, 0, 0, 88, 0, 0, 0, 208, 0, 0, 0 } },
    { 10, { 0, 0 }, { 138, 0, 0, 0, 108, 0, 0, 0, 78, 0, 0, 0, 218, 0, 0, 0 } },
    { 15, { 0, 0 }, { 118, 0, 0, 0, 88, 0, 0, 0, 28, 0, 0, 0, 248, 0, 0, 0 } },
    { 10, { 0, 0 }, { 98, 0, 0, 0, 118, 0, 0, 0, 148, 0, 0, 0, 58, 0, 0, 0 } },
};

const TmAnimFrame gUnk_0961A434[6] = {
    { 10, { 0, 0 }, { 148, 0, 0, 0, 118, 0, 0, 0, 88, 0, 0, 0, 208, 0, 0, 0 } },
    { 15, { 0, 0 }, { 118, 0, 0, 0, 98, 0, 0, 0, 58, 0, 0, 0, 238, 0, 0, 0 } },
    { 10, { 0, 0 }, { 88, 0, 0, 0, 108, 0, 0, 0, 158, 0, 0, 0, 48, 0, 0, 0 } },
    { 10, { 0, 0 }, { 108, 0, 0, 0, 128, 0, 0, 0, 178, 0, 0, 0, 28, 0, 0, 0 } },
    { 15, { 0, 0 }, { 118, 0, 0, 0, 148, 0, 0, 0, 208, 0, 0, 0, 3, 0, 0, 0 } },
    { 10, { 0, 0 }, { 128, 0, 0, 0, 108, 0, 0, 0, 88, 0, 0, 0, 208, 0, 0, 0 } },
};

const TmAnimFrame gUnk_0961A4AC[5] = {
    { 20, { 0, 0 }, { 128, 0, 0, 0, 112, 0, 0, 0, 72, 0, 0, 0, 58, 0, 0, 0 } },
    { 1, { 0, 0 }, { 160, 0, 0, 0, 144, 0, 0, 0, 112, 0, 0, 0, 96, 0, 0, 0 } },
    { 1, { 0, 0 }, { 192, 0, 0, 0, 184, 0, 0, 0, 96, 0, 0, 0, 118, 0, 0, 0 } },
    { 1, { 0, 0 }, { 192, 0, 0, 0, 188, 0, 0, 0, 178, 0, 0, 0, 160, 0, 0, 0 } },
    { 20, { 0, 0 }, { 192, 0, 0, 0, 198, 0, 0, 0, 224, 0, 0, 0, 248, 0, 0, 0 } },
};

const TmAnimFrame gUnk_0961A510[5] = {
    { 20, { 0, 0 }, { 128, 0, 0, 0, 112, 0, 0, 0, 72, 0, 0, 0, 58, 0, 0, 0 } },
    { 1, { 0, 0 }, { 160, 0, 0, 0, 144, 0, 0, 0, 112, 0, 0, 0, 96, 0, 0, 0 } },
    { 1, { 0, 0 }, { 192, 0, 0, 0, 168, 0, 0, 0, 96, 0, 0, 0, 118, 0, 0, 0 } },
    { 1, { 0, 0 }, { 192, 0, 0, 0, 188, 0, 0, 0, 178, 0, 0, 0, 160, 0, 0, 0 } },
    { 20, { 0, 0 }, { 192, 0, 0, 0, 198, 0, 0, 0, 224, 0, 0, 0, 248, 0, 0, 0 } },
};

const TmAnimFrame gUnk_0961A574[5] = {
    { 20, { 0, 0 }, { 128, 0, 0, 0, 144, 0, 0, 0, 184, 0, 0, 0, 58, 0, 0, 0 } },
    { 1, { 0, 0 }, { 96, 0, 0, 0, 112, 0, 0, 0, 144, 0, 0, 0, 96, 0, 0, 0 } },
    { 1, { 0, 0 }, { 64, 0, 0, 0, 72, 0, 0, 0, 160, 0, 0, 0, 118, 0, 0, 0 } },
    { 1, { 0, 0 }, { 64, 0, 0, 0, 68, 0, 0, 0, 78, 0, 0, 0, 160, 0, 0, 0 } },
    { 20, { 0, 0 }, { 64, 0, 0, 0, 58, 0, 0, 0, 32, 0, 0, 0, 248, 0, 0, 0 } },
};

const TmAnimFrame gUnk_0961A5D8[5] = {
    { 20, { 0, 0 }, { 128, 0, 0, 0, 144, 0, 0, 0, 184, 0, 0, 0, 58, 0, 0, 0 } },
    { 1, { 0, 0 }, { 96, 0, 0, 0, 112, 0, 0, 0, 144, 0, 0, 0, 96, 0, 0, 0 } },
    { 1, { 0, 0 }, { 64, 0, 0, 0, 88, 0, 0, 0, 160, 0, 0, 0, 118, 0, 0, 0 } },
    { 1, { 0, 0 }, { 64, 0, 0, 0, 68, 0, 0, 0, 78, 0, 0, 0, 160, 0, 0, 0 } },
    { 20, { 0, 0 }, { 64, 0, 0, 0, 58, 0, 0, 0, 32, 0, 0, 0, 248, 0, 0, 0 } },
};

const u16 gUnk_0961A63C[6] = { 24, 26, 28, 30, 28, 26 };

void func_080BA08C(BtlObj* work, s16 x, s16 y, s16 z, s16 a, s16 b, s32 c, s16 d) {
    work->x = x << 8;
    work->y = y << 8;
    work->z = z << 8;

    if (d >= 6 && d <= 7) {
        ColliderInit(&work->collider, 8, a, b);
        ColliderSetPosition(&work->collider, work->x, work->y, work->z);
    }
}

void func_080BA0E4(BtlObj* p, s32 a, s32 b, s32 c) {
    p->x = (s16)a << 8;
    p->y = (s16)b << 8;
    p->z = (s16)c << 8;
}

void func_080BA0F8(BtlObj* work) {
    ColliderUnregister(&work->collider);
}

void func_080BA104(BtlObj* sub, TmFootWork* work) {
    ColliderSetPosition(&sub->collider, sub->x, sub->y, sub->z);
}

void func_080BA11C(TmFootWork* work) {
    work->unk_002 = 0;
    work->unk_000 = 0;
    SetObjTileSource(work->tiles2, gUnk_09654C04);
    SetObjTileSource(work->tiles3, gUnk_09654C04);
    work->gfx = gUnk_09EF39DC[2];
    work->gfx2 = gUnk_09EF39DC[2];

    if (work->tm->flags & 0x20) {
        work->body.x = work->tm->unk_08 + 0x100;
        work->body2.x = work->tm->unk_08 - 0x600;
        work->body3.x = work->tm->unk_08 + 0x600;
        work->body4.x = work->tm->unk_08 - 0x200;
        work->body.y = work->tm->unk_0C + 0x200;
        work->body2.y = work->tm->unk_0C - 0x200;
        work->body3.y = work->tm->unk_0C + 0x500;
        work->body4.y = work->tm->unk_0C - 0x200;
        work->body.z = work->tm->unk_10 - 0x400;
        work->body2.z = work->tm->unk_10 - 0x400;
        work->body3.z = work->tm->unk_10 + 0x2800;
        work->body4.z = work->tm->unk_10 + 0x2B00;
    } else {
        work->body.x = work->tm->unk_08 + 0x600;
        work->body2.x = work->tm->unk_08 - 0x100;
        work->body3.x = work->tm->unk_08 + 0x200;
        work->body4.x = work->tm->unk_08 - 0x600;
        work->body.y = work->tm->unk_0C - 0x200;
        work->body2.y = work->tm->unk_0C + 0x200;
        work->body3.y = work->tm->unk_0C - 0x500;
        work->body4.y = work->tm->unk_0C + 0x200;
        work->body.z = work->tm->unk_10 - 0x400;
        work->body2.z = work->tm->unk_10 - 0x400;
        work->body3.z = work->tm->unk_10 + 0x2800;
        work->body4.z = work->tm->unk_10 + 0x2B00;
    }
}
void func_080BA2B0(TmFootWork* work) {
    SetObjTileSource(work->tiles2, gUnk_09654C04);
    SetObjTileSource(work->tiles3, gUnk_09654C04);
    work->gfx = gUnk_09EF39DC[0];
    work->gfx2 = gUnk_09EF39DC[0];

    if (work->tm->flags & 0x20) {
        work->body.x = work->tm->unk_08 + 0x100;
        work->body2.x = work->tm->unk_08 - 0x600;
        work->body3.x = work->tm->unk_08 + 0x600;
        work->body4.x = work->tm->unk_08 - 0x200;
        work->body.y = work->tm->y2 + 0x200;
        work->body2.y = work->tm->y2 - 0x200;
        work->body3.y = work->tm->y2 + 0x500;
        work->body4.y = work->tm->y2 - 0x200;
        work->body.z = work->tm->z2 - 0x400;
        work->body2.z = work->tm->z2 - 0x400;
        work->body3.z = work->tm->z2 + 0x1900;
        work->body4.z = work->tm->z2 + 0x1C00;
    } else {
        work->body.x = work->tm->unk_08 + 0x600;
        work->body2.x = work->tm->unk_08 - 0x100;
        work->body3.x = work->tm->unk_08 + 0x200;
        work->body4.x = work->tm->unk_08 - 0x600;
        work->body.y = work->tm->y2 - 0x200;
        work->body2.y = work->tm->y2 + 0x200;
        work->body3.y = work->tm->y2 - 0x500;
        work->body4.y = work->tm->y2 + 0x200;
        work->body.z = work->tm->z2 - 0x400;
        work->body2.z = work->tm->z2 - 0x400;
        work->body3.z = work->tm->z2 + 0x1900;
        work->body4.z = work->tm->z2 + 0x1C00;
    }
}

void func_080BA43C(TmFootWork* work, s16 a) {
    work->gfx = gUnk_09EF39DC[gUnk_09EF2244[a].unk_06];
    work->gfx2 = gUnk_09EF39DC[gUnk_09EF2244[a].unk_0E];
    work->body.z += gUnk_09EF2244[a].unk_02 << 8;
    work->body2.z += gUnk_09EF2244[a].unk_0A << 8;
}

void func_080BA49C(TmFootWork* work) {
    work->unk_002 = 0;
    work->unk_000 = 0;
    SetObjTileSource(work->tiles2, gUnk_09658C04);
    SetObjTileSource(work->tiles3, gUnk_09658C04);
    work->gfx = gUnk_09EF3A1C[6];
    work->gfx2 = gUnk_09EF3A1C[1];

    if (work->tm->flags & 0x20) {
        work->body.x = work->tm->x2 + 0x500;
        work->body2.x = work->tm->x2 - 0x600;
        work->body3.x = work->tm->x2 + 0x600;
        work->body4.x = work->tm->x2 - 0x200;
        work->body.y = work->tm->y2 + 0x200;
        work->body2.y = work->tm->y2 - 0x200;
        work->body3.y = work->tm->y2 + 0x500;
        work->body4.y = work->tm->y2 - 0x200;
        work->body.z = work->tm->z2 - 0x400;
        work->body2.z = work->tm->z2 - 0x400;
        work->body3.z = work->tm->z2 + 0x1E00;
        work->body4.z = work->tm->z2 + 0x3200;
    } else {
        work->body.x = work->tm->x2 + 0x200;
        work->body2.x = work->tm->x2 - 0x100;
        work->body3.x = work->tm->x2 + 0x200;
        work->body4.x = work->tm->x2 - 0x600;
        work->body.y = work->tm->y2 - 0x200;
        work->body2.y = work->tm->y2 + 0x200;
        work->body3.y = work->tm->y2 - 0x500;
        work->body4.y = work->tm->y2 + 0x200;
        work->body.z = work->tm->z2 - 0x400;
        work->body2.z = work->tm->z2 - 0x400;
        work->body3.z = work->tm->z2 + 0x1E00;
        work->body4.z = work->tm->z2 + 0x3200;
    }
}
void func_080BA62C(TmFootWork* work) {
    if (work->tm->unk_36 != 0) {
        return;
    }

    work->gfx = gUnk_09EF3A1C[gUnk_09EF2464[work->tm->unk_34].unk_06];
    work->gfx2 = gUnk_09EF3A1C[gUnk_09EF2464[work->tm->unk_34].unk_0E];

    if (work->tm->flags & 0x20) {
        work->body3.x = work->tm->x2 + ((gUnk_09EF2464[work->tm->unk_34].unk_10 + 6) << 8);
        work->body4.x = work->tm->x2 + ((gUnk_09EF2464[work->tm->unk_34].unk_18 - 2) << 8);
        work->body.x = work->tm->x2 + 0x100;
        work->body2.x = work->tm->x2 - 0x600;
        work->body3.y = work->tm->y2 + 0x500;
        work->body4.y = work->tm->y2 - 0x200;
        work->body.y = work->tm->y2 + 0x200;
        work->body2.y = work->tm->y2 - 0x200;
        work->body3.z = work->tm->z2 + ((gUnk_09EF2464[work->tm->unk_34].unk_12 + 40) << 8);
        work->body4.z = work->tm->z2 + ((gUnk_09EF2464[work->tm->unk_34].unk_1A + 43) << 8);
        work->body.z = work->tm->z2 - 0x400;
        work->body2.z = work->tm->z2 - 0x400;
    } else {
        work->body3.x = work->tm->x2 + ((2 - gUnk_09EF2464[work->tm->unk_34].unk_10) << 8);
        work->body4.x = work->tm->x2 + ((-6 - gUnk_09EF2464[work->tm->unk_34].unk_18) << 8);
        work->body.x = work->tm->x2 + 0x600;
        work->body2.x = work->tm->x2 - 0x100;
        work->body3.y = work->tm->y2 - 0x500;
        work->body4.y = work->tm->y2 + 0x200;
        work->body.y = work->tm->y2 - 0x200;
        work->body2.y = work->tm->y2 + 0x200;
        work->body3.z = work->tm->z2 + ((gUnk_09EF2464[work->tm->unk_34].unk_12 + 40) << 8);
        work->body4.z = work->tm->z2 + ((gUnk_09EF2464[work->tm->unk_34].unk_1A + 43) << 8);
        work->body.z = work->tm->z2 - 0x400;
        work->body2.z = work->tm->z2 - 0x400;
    }

    if (work->tm->unk_34 == 2) {
        if (func_08011F78(239, work->body3.x, work->body3.y - 0x500, 0, 20, 16, 20) == 1) {
            m4aSongNumStart(SONG_BTL_MON_HIT03);
        }
    }

    if (work->tm->unk_34 == 7) {
        if (func_08011F78(239, work->body4.x, work->body4.y - 0x500, 0, 20, 16, 20) == 1) {
            m4aSongNumStart(SONG_BTL_MON_HIT03);
        }
    }
}

void func_080BA8C8(TmFootWork* work, s16 a) {
    work->gfx = gUnk_09EF39DC[gUnk_09EF25A4[a].unk_06];
    work->gfx2 = gUnk_09EF39DC[gUnk_09EF25A4[a].unk_0E];
    work->body.z += gUnk_09EF25A4[a].unk_02 << 8;
    work->body2.z += gUnk_09EF25A4[a].unk_0A << 8;
}

void task_bos_tm_foot_0(TmFootWork* work, TmWork* arg) {
    u16 f;

    work->tiles = LoadObjTiles(gUnk_09652E84, 0x1D80);
    work->tiles2 = AllocObjTiles(0x440, gUnk_09654C04);
    work->tiles3 = AllocObjTiles(0x440, gUnk_09654C04);
    work->palette = LoadObjPalette(gUnk_096FB2A4, 0x60);
    work->palette2 = LoadObjPalette(gUnk_08F69BC4, 32);
    work->gfx = gUnk_09EF39DC[2];
    work->gfx2 = gUnk_09EF39DC[2];
    work->gfx3 = gUnk_09EF39BC;
    work->gfx4 = gUnk_09EF39C4;
    work->tm = arg;
    work->tm->unk_42 += ((u16*)work->tiles2)[4] + ((u16*)work->tiles3)[4];
    work->unk_003 = 0;
    work->unk_004 = 0;
    work->unk_000 = 0;
    work->unk_480 = -0x100;
    work->unk_002 = 0;
    work->unk_130 = 0;
    work->unk_248 = 0;
    work->unk_360 = 0;
    work->unk_478 = 0;
    f = work->tm->flags & 8;

    if (f != 0) {
        func_080BA0E4(&work->body, (s16)(work->tm->x + 1),
                      (s16)(work->tm->y + 2), (s16)(work->tm->z - 4));
        func_080BA0E4(&work->body2, (s16)(work->tm->x - 6),
                      (s16)(work->tm->y - 2), (s16)(work->tm->z - 4));
        func_080BA0E4(&work->body3, (s16)(work->tm->x + 6),
                      (s16)(work->tm->y + 5), (s16)(work->tm->z + 40));
        func_080BA0E4(&work->body4, (s16)(work->tm->x - 2),
                      (s16)(work->tm->y - 2), (s16)(work->tm->z + 43));
    } else {
        func_080BA08C(&work->body, (s16)(work->tm->x + 1),
                      (s16)(work->tm->y + 2), (s16)(work->tm->z - 4), 4, 32, f,
                      4);
        func_080BA08C(&work->body2, (s16)(work->tm->x - 6),
                      (s16)(work->tm->y - 2), (s16)(work->tm->z - 4), 4, 32, f,
                      5);
        func_080BA08C(&work->body3, (s16)(work->tm->x + 6),
                      (s16)(work->tm->y + 5), (s16)(work->tm->z + 40), 20, 140,
                      f, 6);
        func_080BA08C(&work->body4, (s16)(work->tm->x - 2),
                      (s16)(work->tm->y - 2), (s16)(work->tm->z + 43), 20, 140,
                      f, 7);
    }
}
u8 task_bos_tm_foot_1(TmFootWork* work) {
    u16 n;
    TmFootStep* e;
    TmFootStep* table;

    func_080BA104(&work->body3, work);
    func_080BA104(&work->body4, work);

    switch (work->tm->unk_2C) {
    case 0:
    case 15:
        if (work->tm->unk_38 != 0) {
            if (work->tm->unk_36 != 0) {
                break;
            }

            work->unk_003 = gUnk_09EF21B0[(s16)work->tm->unk_34];
            work->unk_004 = gUnk_09EF21B0[((s16)work->tm->unk_34 + 4) & 7];
            work->gfx = gUnk_09EF39DC[(s8)work->unk_003];
            work->gfx2 = gUnk_09EF39DC[(s8)work->unk_004];
            work->body3.z =
                work->tm->z2 + ((gUnk_09EF21B8[(s8)work->unk_003] + 40) << 8);
            work->body4.z =
                work->tm->z2 + ((gUnk_09EF21B8[(s8)work->unk_004] + 43) << 8);
            work->body.z = work->tm->z2 - 0x400;
            work->body2.z = work->tm->z2 - 0x400;
        } else {
            func_080BA11C(work);
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        if (work->tm->unk_38 != 0) {
            func_080BA62C(work);
        } else {
            func_080BA49C(work);
        }
        break;
    case 1:
    case 10:
        if (work->tm->unk_38 == 0) {
            func_080BA11C(work);
        }
        break;
    case 2:
    case 3:
        if (work->tm->unk_38 != 0) {
            n = work->tm->unk_34;

            if ((s16)work->tm->unk_34 <= 3) {
                func_080BA43C(work, (s16)work->tm->unk_34);
            } else if (n >= 66 && n <= 74) {
                n -= 62;
                func_080BA43C(work, (s16)n);
            } else if (n >= 98 && n <= 100) {
                n -= 85;
                func_080BA43C(work, (s16)n);
            } else {
                break;
            }

        } else {
            func_080BA11C(work);
        }
        break;
    case 11:
        if (work->tm->unk_38 != 0) {
            n = work->tm->unk_34;

            if ((s16)work->tm->unk_34 <= 3) {
                func_080BA43C(work, (s16)work->tm->unk_34);
            } else if (n >= 96 && n <= 104) {
                n -= 92;
                func_080BA43C(work, (s16)n);
            } else if (n >= 128 && n <= 130) {
                n -= 115;
                func_080BA43C(work, (s16)n);
            } else {
                break;
            }

        } else {
            func_080BA11C(work);
        }
        break;
    case 9:
        if (work->tm->unk_38 != 0) {
            n = work->tm->unk_34;

            if ((s16)work->tm->unk_34 <= 2) {
                func_080BA8C8(work, (s16)work->tm->unk_34);
            } else if (n >= 41 && n <= 46) {
                n -= 38;
                func_080BA8C8(work, (s16)n);
            } else {
                break;
            }

        } else {
            func_080BA11C(work);
        }
        break;
    case 12:
        if (work->tm->unk_30 == 1) {
            work->unk_002 = 0;
            work->unk_000 = 0;
            work->gfx = gUnk_09EF39DC[1];
            work->gfx2 = gUnk_09EF39DC[1];
            work->body.z = work->tm->unk_10 +
                            ((gBosTmFootSteps[(s16)work->tm->unk_34].unk_02 - 4) << 8);
            work->body2.z = work->tm->unk_10 +
                            ((gBosTmFootSteps[(s16)work->tm->unk_34].unk_0A - 4) << 8);
            work->body3.z = work->tm->unk_10 + 0x2800;
            work->body4.z = work->tm->unk_10 + 0x2800;
            break;
        }

        if ((s16)work->tm->unk_34 <= 2) {
            work->gfx = gUnk_09EF39DC[gBosTmFootSteps[(s16)work->tm->unk_34].unk_06];
            work->gfx2 = gUnk_09EF39DC[gBosTmFootSteps[(s16)work->tm->unk_34].unk_0E];
            work->body.z += gBosTmFootSteps[(s16)work->tm->unk_34].unk_02 << 8;
            work->body2.z += gBosTmFootSteps[(s16)work->tm->unk_34].unk_0A << 8;
        }

        if (work->tm->unk_32 <= 2) {
            work->gfx =
                gUnk_09EF39DC[(table = gBosTmFootSteps, e = &table[work->tm->unk_32])->unk_06 + 1];
            work->gfx2 = gUnk_09EF39DC[e->unk_0E + 1];
            work->body.z -= e->unk_02 << 8;
            work->body2.z -= e->unk_0A << 8;
        }
        break;
    case 14:
        if (work->tm->unk_38 == 0) {
            func_080BA2B0(work);
        } else if (work->tm->unk_38 > 59) {
            if (work->tm->flags & 0x40) {
                func_080BA49C(work);
            } else {
                func_080BA11C(work);
            }
        }
        break;
    case 13:
        if ((s16)work->tm->unk_34 == 0) {
            func_080BA2B0(work);
        }
        break;
    case 8:
    case 16:
    case 17:
    default:
        break;
    }

    return 1;
}
void task_bos_tm_foot_2(TmFootWork* work) {
    void* pal;
    s32 flag;
    s16 x;
    s16 y;
    BtlObj* s0;
    BtlObj* s1;
    BtlObj* s2;
    BtlObj* s3;
    u16 mode;

    flag = work->tm->flags & 0x20;
    mode = 0x801;
    if (flag != 0) {
        mode = 0x800;
    }

    if (gBtlWork->unk_070 != 0) {
        pal = work->palette;
    } else if ((work->tm->flags & 1) && (gFrameCounter & 1)) {
        pal = work->palette2;
    } else {
        pal = work->palette;
    }

    s0 = &work->body;
    s1 = &work->body2;
    s2 = &work->body3;
    s3 = &work->body4;
    WorldToScreen(&x, &y, s0->x, s0->y, s0->z);
    DrawSprite(x, y, work->gfx, work->tiles2, pal, 0, mode, (u16)(-4100 - (s0->y >> 8) * 4));
    WorldToScreen(&x, &y, s1->x, s1->y, s1->z);
    DrawSprite(x, y, work->gfx2, work->tiles3, pal, 0, mode, (u16)(-4100 - (s1->y >> 8) * 4));
    WorldToScreen(&x, &y, s2->x, s2->y, s2->z);
    DrawSprite(x, y, work->gfx3, work->tiles, pal, 0, mode, (u16)(-4100 - (s2->y >> 8) * 4));
    WorldToScreen(&x, &y, s3->x, s3->y, s3->z);
    DrawSprite(x, y, work->gfx4, work->tiles, pal, 0, mode, (u16)(-4100 - (s3->y >> 8) * 4));
}

void task_bos_tm_foot_3(TmFootWork* work) {
    if ((work->tm->flags & 8) == 0) {
        func_080BA0F8(&work->body3);
        func_080BA0F8(&work->body4);
    }

    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjPalette((void*)work->palette);
    ReleaseObjPalette((void*)work->palette2);
}

void CreateBosTmClbTask(void* pool, TmClbArg* p, TmClbSrc* a) {
    p->src = a;
    p->unk_00 = 0;
    p->unk_04 = 1;
    p->unk_0C = 0;
    TaskCreate(pool, &gTaskDescBosTmClb, p);
}

void func_080BB1D8(TmClbArg* p, TmClbSrc* a, s32 b) {
    p->src = a;
    p->unk_0C = b;
    p->unk_00 = 4;
    p->unk_04 = 0;
}

void func_080BB1E8(TmClbArg* p, TmClbSrc* a) {
    p->src = a;
    p->unk_0C = 0;
    p->unk_00 = 0;
    p->unk_04 = 0;
}

void func_080BB1F4(TmClbArg* p, TmClbSrc* a, u8 mode) {
    p->src = a;
    p->unk_0C = 0;
    p->unk_04 = 2;

    switch (mode) {
    case 0:
        p->unk_00 = 1;
        break;
    case 1:
        p->unk_00 = 1;
        break;
    case 2:
        p->unk_00 = 2;
        break;
    case 3:
        p->unk_00 = 3;
        break;
    }
}

void task_bos_tm_clb_0(TmClbWork* work, void* arg) {
    void* p;

    work->tiles = LoadObjTiles(gUnk_09652E84, 0x1D80);
    work->palette = LoadObjPalette(gUnk_096FB2A4, 0x60);
    work->arg = arg;
    p = ((void**)arg)[2];
    work->unk_00C = *(u16*)((u8*)p + 12);
    work->x = *(s32*)p;
    work->y = *(s32*)((u8*)p + 4);
    work->z = *(s32*)((u8*)p + 8);
}

u8 task_bos_tm_clb_1(TmClbWork* work) {
    TmClbArg* a = work->arg;

    switch (a->unk_00) {
    case 4:
        work->x += (a->src->unk_00 - work->x) >> 4;
        work->y = a->src->unk_04;
        work->z += a->unk_0C;
        a->unk_0C += 51;

        if (a->unk_0C > 0 && work->z >= a->src->unk_08) {
            work->z = a->src->unk_08;
            a->unk_00 = 0;
            a->unk_04 = 1;
        }

        break;
    case 0:
        work->x = a->src->unk_00;
        work->y = a->src->unk_04;
        work->z = a->src->unk_08;
        break;
    case 1:
        work->x = a->src->unk_00;
        work->y = a->src->unk_04;
        work->z = a->src->unk_08;
        break;
    case 2:
        work->x = a->src->unk_00 - 0x600;
        work->y = a->src->unk_04;
        work->z = a->src->unk_08;
        break;
    case 3:
        work->x = a->src->unk_00 + 0x600;
        work->y = a->src->unk_04;
        work->z = a->src->unk_08 - 0x500;
        break;
    }

    switch (a->unk_04) {
    case 0:
        work->unk_00C += 0x10;
        break;
    case 1:
        ApproachAngle(&work->unk_00C, a->src->unk_0C, 2);
        break;
    case 2:
        work->unk_00C = a->src->unk_0C;
        break;
    }

    return 1;
}
void task_bos_tm_clb_2(TmClbWork* work) {
    u8* p;
    s16 x;
    s16 y;

    p = AllocObjAffineAngle(work->unk_00C, 0);
    WorldToScreen(&x, &y, work->x, work->y, work->z);
    DrawSprite(x, y, gUnk_0962E838, work->tiles, work->palette, (s32)p, 0x800,
               (u16)(-0x1002 - (work->y >> 8) * 4));
    p[0x0A] = 1;
    DrawSprite(x, y, work->arg->unk_14, work->arg->unk_10, work->palette, (s32)p, 0x800,
               (u16)(-0x1003 - (work->y >> 8) * 4));
}

void task_bos_tm_clb_3(TmClbWork* work) {
    ReleaseObjTiles(work->tiles);
    ReleaseObjPalette(work->palette);
}

void func_080BB428(u8* dst, const u8* src) {
    s32 i;

    i = 3;

    do {
        *(u16*)(dst + 20) = *src;
        src += 4;
        dst += 0x34;
    } while (--i >= 0);
}

void func_080BB43C(u8* work, const TmAnimFrame* src, u16 a, u8* dst) {
    if (*(const TmAnimFrame**)(work + 8) != src) {
        *(const TmAnimFrame**)(work + 8) = src;
        *(u16*)(work + 0) = 0;
        *(u16*)(work + 2) = 0;
        *(u16*)(work + 4) = a;
        func_080BB428(dst, src->unk_04);
    }
}

void func_080BB464(TmArmWork* work) {
    TmArmJoint* s = &work->joints.all[7];
    TmArmPos* d = &work->unk_1F8[0];

    d->x = s->unk_00 + gSineTable[s->angle] * 12 + work->src->unk_00;
    d->z = s->unk_04 + -gSineTable[s->angle + 0x40] * 12 + work->src->unk_08;
    d->y = work->src->unk_04;
}
void func_080BB4C0(TmArmWork* work) {
    TmArmJoint* s = &work->joints.all[3];
    TmArmPos* d = &work->unk_1F8[1];

    d->x = s->unk_00 + gSineTable[s->angle] * 12 + work->src->unk_0C;
    d->z = s->unk_04 + -gSineTable[s->angle + 0x40] * 12 + work->src->unk_14;
    d->y = work->src->unk_10;
}

void func_080BB518(TmArmJoint* joints) {
    s32 x;
    s32 y;
    s32 i;
    s32 n;
    TmArmJoint* p;

    x = 0;
    y = 0;

    for (i = 0; i < 3; i++) {
        p = &joints[i];
        p->x = x;
        p->y = y;
        x += gSineTable[p->angle] * gUnk_0961A63C[n = p->unk_26];
        y += -gSineTable[p->angle + 0x40] * gUnk_0961A63C[n = p->unk_26];
    }

    p = &joints[n = 3];
    p->x = x;
    p->y = y;
}
void func_080BB588(TmArmJoint* joints, u16 a) {
    s32 i;
    u8* q;
    TmArmJoint* p;

    for (i = 0; i < 4; i++) {
        p = &joints[i];

        q = &p->angle;
        ApproachAngle(q, p->unk_14, a);
    }

    func_080BB518(joints);

    for (i = 0; i < 4; i++) {
        p = &joints[i];

        p->unk_00 += (p->x - p->unk_00) >> 1;
        p->unk_04 += (p->y - p->unk_04) >> 1;
    }
}

void func_080BB5E8(u8* joints, TmAnim* a) {
    if (a->unk_00 >= a->frames[a->unk_02].unk_00) {
        a->unk_00 = 0;
        a->unk_02++;

        if (a->unk_02 >= a->unk_04) {
            a->unk_02 = 0;
        }

        func_080BB428(joints, a->frames[a->unk_02].unk_04);
    }

    a->unk_00++;
    func_080BB588(joints, 1);
}

void task_bos_tm_arm_0(TmArmWork* work, TmArmSrc* arg) {
    s32 i;
    void* gfx;
    TmArmJoint* a;
    TmArmJoint* b;
    TmArmJoint* p;
    TmArmJoint* q;

    work->src = arg;
    work->tiles = LoadObjTiles(gUnk_09652E84, 0x1D80);
    work->palette = LoadObjPalette(gUnk_096FB2A4, 0x60);
    work->palette2 = LoadObjPalette(gUnk_08F69BC4, 32);
    work->unk_1B0 = 0;
    work->unk_1B2 = 0;
    work->unk_230 = 1;
    work->unk_234 = 0;
    work->unk_22C = 0;
    work->unk_220 = 0;
    func_080BB43C(work->unk_224, gUnk_09619CDC, 3, (u8*)work->joints.arms[0]);
    func_080BB43C((u8*)&work->unk_218, gUnk_09619D18, 3, (u8*)&work->joints.arms[1][0]);

    for (i = 0; i < 4; i++) {
        p = &work->joints.arms[0][i];
        q = &work->joints.arms[1][i];
        *(u16*)&p->angle = p->unk_14;
        *(u16*)&q->angle = q->unk_14;
    }

    a = work->joints.arms[0];
    func_080BB518(a);
    b = &work->joints.arms[1][0];
    func_080BB518(b);

    for (i = 0; i < 4; i++) {
        work->joints.arms[0][i].unk_00 = work->joints.arms[0][i].x;
        work->joints.arms[0][i].unk_04 = work->joints.arms[0][i].y;
        work->joints.arms[1][i].unk_00 = work->joints.arms[1][i].x;
        work->joints.arms[1][i].unk_04 = work->joints.arms[1][i].y;
    }

    func_080BB464(work);
    func_080BB4C0(work);
    work->unk_1F8[0].unk_0C = 272;
    work->unk_1F8[1].unk_0C = 240;

    for (i = 0; i < 3; i++) {
        AnimInit((AnimState*)&work->joints.arms[0][i].unk_16[2], gUnk_09EF39B4, gUnk_09EF39A0);
        AnimStart((AnimState*)&work->joints.arms[0][i].unk_16[2], 0, 1);
        work->joints.arms[0][i].unk_26 = i * 2;
        work->joints.arms[0][i].gfx = AnimGetGfx((AnimState*)&work->joints.arms[0][i].unk_16[2]);
        AnimInit((AnimState*)&work->joints.arms[1][i].unk_16[2], gUnk_09EF39B4, gUnk_09EF39A0);
        AnimStart((AnimState*)&work->joints.arms[1][i].unk_16[2], 0, 1);
        work->joints.arms[1][i].unk_26 = i * 2;
        work->joints.arms[1][i].gfx = AnimGetGfx((AnimState*)&work->joints.arms[1][i].unk_16[2]);
    }

    work->joints.arms[0][3].gfx = gUnk_0962E7A0;
    work->joints.arms[1][3].gfx = gUnk_0962E7A0;
    work->tiles2 = AllocObjTiles(0x140, gUnk_09657C04);
    work->src->state->tileCount += ((TmArmTileHeader*)work->tiles2)->tileCount;
    AnimInit(&work->anim, gUnk_09EF3A18, gUnk_09EF39F8);
    AnimStart(&work->anim, 0, 1);
    work->unk_1D8 = work->tiles2;
    work->unk_1F0 = work->tiles2;
    gfx = AnimGetGfx(&work->anim);
    work->unk_1DC = (u32)gfx;
    work->unk_1F4 = (u32)gfx;
    work->unk_254 = 0;
    TaskPoolInit(&work->tasks, 2);
    CreateBosTmClbTask(&work->tasks, (TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0]);
    CreateBosTmClbTask(&work->tasks, (TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1]);
    gUnk_0203AC74 = 0;
    gUnk_0203AC64 = 0;
    gUnk_0203AC78 = 0;
    gUnk_0203AC70 = 0;
    gUnk_0203AC60 = 0;
    gUnk_0203AC6C = 0;
    gUnk_0203AC68 = 0;
}
void func_080BB924(TmArmWork* work) {
    TmArmJoint* j;
    TmArmJoint* j2;
    s32 i;
    s32 offset;
    void* gfx;
    void** dst;
    s32 r;
    s32 x;
    s32 y;
    s32 z;
    s32 x2;
    s32 y2;
    s32 z2;
    u8 v;

    switch (work->src->state->unk_2C) {
    case 0:
    case 15:
        if (work->unk_1B0 == 0) {
            work->unk_1F8[0].unk_0C = 0x110;

            if (work->src->state->flags & 0x20) {
                func_080BB43C((u8*)&work->unk_218, gUnk_09619D18, 3, (u8*)&work->joints.all[4]);
            } else {
                func_080BB43C((u8*)&work->unk_218, gUnk_09619D90, 3, (u8*)&work->joints.all[4]);
            }
        }

        switch (work->unk_1B0 % 30) {
        case 0:
            v = 0;

            if (work->unk_230 == 0) {
                v = 1;
            }

            work->unk_230 = v;
            break;
        case 22:
            if (work->unk_230 != 0) {
                func_080BB1D8((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0], -0x380);
            } else {
                func_080BB1D8((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[0], -0x380);
            }
            break;
        }

        work->unk_1B0++;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        if (work->unk_1B0 == 0) {
            work->unk_1F8[0].unk_0C = 0x110;
            func_080BB1E8((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0]);

            if (work->src->state->flags & 0x20) {
                func_080BB43C((u8*)&work->unk_218, gUnk_0961A2CC, 6, (u8*)&work->joints.all[4]);
            } else {
                func_080BB43C((u8*)&work->unk_218, gUnk_0961A3BC, 6, (u8*)&work->joints.all[4]);
            }
        }

        work->unk_1B0++;
        break;
    case 12:
    case 14:
        if (work->unk_1B0 == 0) {
            work->unk_1F8[0].unk_0C = 90;
            func_080BB1D8((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0], -128);

            if (work->src->state->flags & 0x20) {
                func_080BB43C((u8*)&work->unk_218, gUnk_09619DE0, 1, (u8*)&work->joints.all[4]);
            } else {
                func_080BB43C((u8*)&work->unk_218, gUnk_09619E08, 1, (u8*)&work->joints.all[4]);
            }
        }

        work->unk_1B0++;
        break;
    case 13:
        if (work->unk_1B0 == 0) {
            work->unk_1F8[0].unk_0C = 90;
            func_080BB1D8((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0], -128);

            if (work->src->state->flags & 0x20) {
                func_080BB43C((u8*)&work->unk_218, gUnk_09619DE0, 1, (u8*)&work->joints.all[4]);
            } else {
                func_080BB43C((u8*)&work->unk_218, gUnk_09619E08, 1, (u8*)&work->joints.all[4]);
            }
        }

        work->unk_1B0++;
        break;
    case 1:
        if (work->unk_1B0 == 0) {
            if (work->src->state->flags & 0x20) {
                func_080BB43C((u8*)&work->unk_218, gUnk_09619E1C, 3, (u8*)&work->joints.all[4]);
                work->unk_1F8[0].unk_0C = 0xE8;
                func_080BB1F4((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0], 0);
            } else {
                func_080BB43C((u8*)&work->unk_218, gUnk_09619E94, 3, (u8*)&work->joints.all[4]);
                work->unk_1F8[0].unk_0C = 0xF4;
                func_080BB1F4((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0], 2);
            }
        }

        if (work->unk_1B0 == 45) {
            j = &work->joints.all[3];
            y = work->src->unk_10;
            z = work->src->unk_14 + j->unk_04 - 0x2300;

            if (work->src->state->flags & 0x20) {
                x = work->src->unk_0C + j->unk_00 - 0x3E00;
                func_08012F74(x, y, z, 1, 0, 168, 20);
            } else {
                x = work->src->unk_0C + j->unk_00 + 0x4800;
                func_08012F74(x, y, z, 0, 0, 168, 20);
            }
        } else if (work->unk_1B0 > 55) {
            if (func_080128EC() == 0) {
                work->unk_1F8[0].unk_0C = 0x110;
                work->src->state->flags |= 2;
            }
        }

        work->unk_1B0++;
        break;
    case 10:
        if (work->unk_1B0 == 0) {
            if (work->src->state->flags & 0x20) {
                func_080BB43C((u8*)&work->unk_218, gUnk_09619E1C, 3, (u8*)&work->joints.all[4]);
                work->unk_1F8[0].unk_0C = 0xE8;
                func_080BB1F4((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0], 0);
            } else {
                func_080BB43C((u8*)&work->unk_218, gUnk_09619E94, 3, (u8*)&work->joints.all[4]);
                work->unk_1F8[0].unk_0C = 0xF4;
                func_080BB1F4((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0], 2);
            }
        }

        if (work->unk_1B0 == 30) {
            j = &work->joints.all[3];
            y = work->src->unk_10;
            z = work->src->unk_14 + j->unk_04 - 0x2300;

            if (work->src->state->flags & 0x20) {
                x = work->src->unk_0C + j->unk_00 - 0x3E00;
                func_08012F74(x, y, z, 1, 0, 168, 18);
            } else {
                x = work->src->unk_0C + j->unk_00 + 0x4800;
                func_08012F74(x, y, z, 0, 0, 168, 18);
            }
        } else if (work->unk_1B0 > 70) {
            if (func_080128EC() == 0) {
                work->unk_1F8[0].unk_0C = 0x110;
                work->src->state->flags |= 2;
            }
        } else if (work->unk_1B0 > 50) {
            v = func_080128EC();
            if (v == 0) {
                j2 = &work->joints.all[3];
                y2 = work->src->unk_10;
                z2 = work->src->unk_14 + j2->unk_04 - 0x2300;

                if (work->src->state->flags & 0x20) {
                    x2 = work->src->unk_0C + j2->unk_00 - 0x3E00;
                    func_08012F74(x2, y2, z2, 1, 0, 168, 18);
                } else {
                    x2 = work->src->unk_0C + j2->unk_00 + 0x4800;
                    func_08012F74(x2, y2, z2, 0, 0, 168, 18);
                }
            }
        }

        work->unk_1B0++;
        break;
    case 2:
        if (work->unk_1B0 == 0) {
            if (work->src->state->flags & 0x20) {
                func_080BB43C((u8*)&work->unk_218, gUnk_09619F0C, 6, (u8*)&work->joints.all[4]);
            } else {
                func_080BB43C((u8*)&work->unk_218, gUnk_09619FFC, 6, (u8*)&work->joints.all[4]);
            }

            func_080BB1D8((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0], -0xB00);
            work->unk_1F8[0].unk_0C = 0xE8;
        }

        if (work->unk_1B0 == 35) {
            work->unk_1F8[0].unk_0C = 0x110;
            work->src->state->unk_3A = 1;

            if (work->src->state->flags & 0x20) {
                r = func_08011F78(237, work->unk_1F8[1].x - 0x1000, work->unk_1F8[1].y,
                                  work->unk_1F8[1].z + 0x1400, 16, 16, 16);
            } else {
                r = func_08011F78(237, work->unk_1F8[1].x + 0x2800, work->unk_1F8[1].y,
                                  work->unk_1F8[1].z + 0x1400, 16, 16, 16);
            }

            if (r == 1) {
                m4aSongNumStart(SONG_BTL_MON_HIT03);
            }

            m4aSongNumStart(SONG_BTL_LB_RUMB);
        }

        if (work->unk_1B0 > 50) {
            work->src->state->flags |= 2;
        } else {
            work->unk_1B0++;
        }
        break;
    case 3:
        if (work->unk_1B0 == 0) {
            if (work->src->state->flags & 0x20) {
                func_080BB43C((u8*)&work->unk_218, gUnk_09619F0C, 6, (u8*)&work->joints.all[4]);
            } else {
                func_080BB43C((u8*)&work->unk_218, gUnk_09619FFC, 6, (u8*)&work->joints.all[4]);
            }

            func_080BB1D8((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0], -0xB00);
            work->unk_1F8[0].unk_0C = 0xE8;
        }

        if (work->unk_1B0 == 35) {
            work->unk_1F8[0].unk_0C = 0x110;
        }

        if (work->unk_1B0 == 37) {
            gUnk_0203AC64 = gBtlWork->unk_000;
            gUnk_0203AC78 = gBtlWork->unk_004;
            gUnk_0203AC60 = gUnk_0203AC64 >> 8;
            gUnk_0203AC6C = gUnk_0203AC78 >> 8;

            if (work->src->state->flags & 0x20) {
                func_080147D8(0x10D00, 0x15800);
            } else {
                func_080147D8(0xF000, 0x15800);
            }

            func_0802F1E8();
            m4aSongNumStart(SONG_BTL_LB_RUMB);
            func_08011F78(238, gBtlWork->unk_000, gBtlWork->unk_004, 0, 320, 240, 1);
            gUnk_0203AC64 = gBtlWork->unk_000;
            gUnk_0203AC78 = gBtlWork->unk_004;
            gUnk_0203AC60 = gUnk_0203AC64 >> 8;
            gUnk_0203AC6C = gUnk_0203AC78 >> 8;
        }

        if (work->unk_1B0 > 50) {
            work->src->state->flags |= 2;
        } else {
            work->unk_1B0++;
        }
        break;
    case 11:
        if (work->unk_1B0 == 0) {
            if (work->src->state->flags & 0x20) {
                func_080BB43C((u8*)&work->unk_218, gUnk_0961A0EC, 6, (u8*)&work->joints.all[4]);
            } else {
                func_080BB43C((u8*)&work->unk_218, gUnk_0961A1DC, 6, (u8*)&work->joints.all[4]);
            }

            func_080BB1D8((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0], -0xB00);
            work->unk_1F8[0].unk_0C = 0xE8;
        }

        if (work->unk_1B0 == 50) {
            work->unk_1F8[0].unk_0C = 0x110;
        }

        if (work->unk_1B0 == 52) {
            gUnk_0203AC64 = gBtlWork->unk_000;
            gUnk_0203AC78 = gBtlWork->unk_004;
            gUnk_0203AC60 = gUnk_0203AC64 >> 8;
            gUnk_0203AC6C = gUnk_0203AC78 >> 8;

            if (work->src->state->flags & 0x20) {
                func_080147D8(0x10D00, 0x15800);
            } else {
                func_080147D8(0xF000, 0x15800);
            }

            func_0802F1E8();
            m4aSongNumStart(SONG_BTL_LB_RUMB);
            func_08011F78(238, gBtlWork->unk_000, gBtlWork->unk_004, 0, 320, 240, 1);
            gUnk_0203AC64 = gBtlWork->unk_000;
            gUnk_0203AC78 = gBtlWork->unk_004;
            gUnk_0203AC60 = gUnk_0203AC64 >> 8;
            gUnk_0203AC6C = gUnk_0203AC78 >> 8;
        }

        if (work->unk_1B0 > 65) {
            work->src->state->flags |= 2;
        } else {
            work->unk_1B0++;
        }
        break;
    case 9:
        if (work->unk_1B0 == 0) {
            work->unk_1F8[0].unk_0C = 0x10C;
            func_080BB1E8((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[0]);

            if (work->src->state->flags & 0x20) {
                func_080BB43C((u8*)&work->unk_218, gUnk_0961A4AC, 5, (u8*)&work->joints.all[4]);
            } else {
                func_080BB43C((u8*)&work->unk_218, gUnk_0961A574, 5, (u8*)&work->joints.all[4]);
            }
        }

        if (work->unk_1B0 == 21) {
            if (func_08011F78(240, work->src->state->unk_08, work->src->state->unk_0C,
                              work->unk_1F8[1].z, 36, 32, 32) == 1) {
                m4aSongNumStart(SONG_BTL_MON_HIT03);
            }
        }

        if (work->unk_1B0 > 33) {
            work->src->state->flags |= 2;
        } else {
            work->unk_1B0++;
        }

        gUnk_0203AC74 = work->unk_1B0;
        break;
    case 17:
        return;
    }

    func_080BB5E8((u8*)&work->joints.all[4], (TmAnim*)&work->unk_218);
    func_080BB464(work);

    for (i = 0; i < 3; i++) {
        offset = i * sizeof(TmArmJoint);
        gfx = AnimUpdate((AnimState*)((u8*)work->joints.all + offset + 0xE8));
        dst = &work->joints.all[4].gfx;
        *(void**)((u8*)dst + offset) = gfx;
    }
}

void func_080BC304(TmArmWork* work) {
    s32 i;

    switch (work->src->state->unk_2C) {
    case 0:
    case 15:
        if (work->unk_1B2 == 0) {
            work->unk_1F8[1].unk_0C = 0x110;

            if (work->src->state->flags & 0x20) {
                func_080BB43C(work->unk_224, gUnk_09619CDC, 3, (u8*)work->joints.all);
            } else {
                func_080BB43C(work->unk_224, gUnk_09619D54, 3, (u8*)work->joints.all);
            }
        }

        if (work->unk_1B2 % 30 == 12) {
            if (work->unk_230 != 0) {
                func_080BB1D8((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1], -0x600);
            } else {
                func_080BB1D8((TmClbArg*)&work->unk_1C8, (TmClbSrc*)&work->unk_1F8[1], -0x600);
            }
        }

        work->unk_1B2++;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        if (work->unk_1B2 == 0) {
            work->unk_1F8[1].unk_0C = 0x110;
            func_080BB1E8((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1]);

            if (work->src->state->flags & 0x20) {
                func_080BB43C(work->unk_224, gUnk_0961A344, 6, (u8*)work->joints.all);
            } else {
                func_080BB43C(work->unk_224, gUnk_0961A434, 6, (u8*)work->joints.all);
            }
        }

        work->unk_1B2++;
        break;
    case 12:
    case 14:
        if (work->unk_1B2 == 0) {
            work->unk_1F8[1].unk_0C = 185;
            func_080BB1D8((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1], -128);

            if (work->src->state->flags & 0x20) {
                func_080BB43C(work->unk_224, gUnk_09619DCC, 1, (u8*)work->joints.all);
            } else {
                func_080BB43C(work->unk_224, gUnk_09619DF4, 1, (u8*)work->joints.all);
            }
        }

        work->unk_1B2++;
        break;
    case 13:
        if (work->unk_1B2 == 0) {
            work->unk_1F8[1].unk_0C = 185;
            func_080BB1D8((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1], -128);

            if (work->src->state->flags & 0x20) {
                func_080BB43C(work->unk_224, gUnk_09619DCC, 1, (u8*)work->joints.all);
            } else {
                func_080BB43C(work->unk_224, gUnk_09619DF4, 1, (u8*)work->joints.all);
            }
        }

        work->unk_1B2++;
        break;
    case 1:
        if (work->unk_1B2 == 0) {
            if (work->src->state->flags & 0x20) {
                func_080BB43C(work->unk_224, gUnk_09619E58, 3, (u8*)work->joints.all);
                work->unk_1F8[1].unk_0C = 0x10C;
                func_080BB1F4((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1], 1);
            } else {
                func_080BB43C(work->unk_224, gUnk_09619ED0, 3, (u8*)work->joints.all);
                work->unk_1F8[1].unk_0C = 0x118;
                func_080BB1F4((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1], 3);
            }
        }

        if (work->unk_1B2 > 55) {
            if (func_080128EC() == 0) {
                work->unk_1F8[1].unk_0C = 240;
            }
        }

        work->unk_1B2++;
        break;
    case 10:
        if (work->unk_1B2 == 0) {
            if (work->src->state->flags & 0x20) {
                func_080BB43C(work->unk_224, gUnk_09619E58, 3, (u8*)work->joints.all);
                work->unk_1F8[1].unk_0C = 0x10C;
                func_080BB1F4((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1], 1);
            } else {
                func_080BB43C(work->unk_224, gUnk_09619ED0, 3, (u8*)work->joints.all);
                work->unk_1F8[1].unk_0C = 0x118;
                func_080BB1F4((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1], 3);
            }
        }

        if (work->unk_1B2 > 70) {
            if (func_080128EC() == 0) {
                work->unk_1F8[1].unk_0C = 240;
            }
        }

        work->unk_1B2++;
        break;
    case 2:
        if (work->unk_1B2 == 0) {
            if (work->src->state->flags & 0x20) {
                func_080BB43C(work->unk_224, gUnk_09619F84, 6, (u8*)work->joints.all);
            } else {
                func_080BB43C(work->unk_224, gUnk_0961A074, 6, (u8*)work->joints.all);
            }

            func_080BB1D8((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1], -0xB00);
            work->unk_1F8[1].unk_0C = 0x10C;
        }

        if (work->unk_1B2 == 35) {
            work->unk_1F8[1].unk_0C = 240;
        }

        work->unk_1B2++;
        break;
    case 3:
        if (work->unk_1B2 == 0) {
            if (work->src->state->flags & 0x20) {
                func_080BB43C(work->unk_224, gUnk_09619F84, 6, (u8*)work->joints.all);
            } else {
                func_080BB43C(work->unk_224, gUnk_0961A074, 6, (u8*)work->joints.all);
            }

            func_080BB1D8((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1], -0xB00);
            work->unk_1F8[1].unk_0C = 0x10C;
        }

        if (work->unk_1B2 == 35) {
            work->unk_1F8[1].unk_0C = 240;
        }

        work->unk_1B2++;
        break;
    case 11:
        if (work->unk_1B2 == 0) {
            if (work->src->state->flags & 0x20) {
                func_080BB43C(work->unk_224, gUnk_0961A164, 6, (u8*)work->joints.all);
            } else {
                func_080BB43C(work->unk_224, gUnk_0961A254, 6, (u8*)work->joints.all);
            }

            func_080BB1D8((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1], -0xB00);
            work->unk_1F8[1].unk_0C = 0x10C;
        }

        if (work->unk_1B2 == 50) {
            work->unk_1F8[1].unk_0C = 240;
        }

        work->unk_1B2++;
        break;
    case 9:
        if (work->unk_1B2 == 0) {
            work->unk_1F8[1].unk_0C = 0x110;
            func_080BB1E8((TmClbArg*)&work->unk_1E0, (TmClbSrc*)&work->unk_1F8[1]);

            if (work->src->state->flags & 0x20) {
                func_080BB43C(work->unk_224, gUnk_0961A510, 5, (u8*)work->joints.all);
            } else {
                func_080BB43C(work->unk_224, gUnk_0961A5D8, 5, (u8*)work->joints.all);
            }
        }

        work->unk_1B2++;
        break;
    case 17:
        return;
    }

    func_080BB5E8((u8*)work->joints.all, (TmAnim*)work->unk_224);
    func_080BB4C0(work);

    for (i = 0; i < 3; i++) {
        work->joints.all[i].gfx = AnimUpdate((AnimState*)((u8*)&work->joints.all[i] + 0x18));
    }
}

u8 task_bos_tm_arm_1(TmArmWork* work) {
    void* gfx;

    if (work->unk_234 != work->src->state->unk_2C) {
        work->unk_234 = work->src->state->unk_2C;
        work->unk_1B0 = 0;
        work->unk_1B2 = 0;
    }

    if (gFrameCounter % 2 != 0) {
        func_080BB924(work);
    } else {
        func_080BC304(work);
    }

    if (work->src->state->unk_2C != 13) {
        gfx = AnimUpdate(&work->anim);
        work->unk_1DC = (u32)gfx;
        work->unk_1F4 = (u32)gfx;

        if (gFrameCounter % 5 == 0) {
            LoadObjPaletteBank(work->palette[3] + 1, gUnk_096FB304 + work->unk_254 * 32);
            work->unk_254 = (work->unk_254 + 1) & 7;
        }
    }

    TaskPoolUpdate(&work->tasks);

    return 1;
}

void task_bos_tm_arm_2(TmArmWork* work) {
    void* pal;
    s32 mode;
    s32 affine;
    s16 depth;
    s16 endDepth;
    s16 x;
    s16 y;
    s32 i;
    TmArmJoint* j;

    if (gBtlWork->unk_070 != 0) {
        pal = work->palette;
    } else if ((work->src->state->flags & 1) && (gFrameCounter & 1)) {
        pal = (void*)work->palette2;
    } else {
        pal = work->palette;
    }

    for (i = 0; i < 3; i++) {
        j = &work->joints.all[i + 4];
        affine = AllocObjAffine(j->angle, 256, 256, 0);
        WorldToScreen(&x, &y, work->src->unk_00 + j->unk_00, work->src->unk_04,
                      work->src->unk_08 + j->unk_04);
        depth = -4100;
        DrawSprite(x, y, j->gfx, (void*)work->tiles, pal, affine, 0x800,
                   (depth -= (work->src->unk_04 >> 8) * 4, (u16)depth));
        j = &work->joints.all[i];
        affine = AllocObjAffine(j->angle, 256, 256, 0);
        WorldToScreen(&x, &y, work->src->unk_0C + j->unk_00, work->src->unk_10,
                      work->src->unk_14 + j->unk_04);
        depth = -4100;
        DrawSprite(x, y, j->gfx, (void*)work->tiles, pal, affine, 0x800,
                   (depth -= (work->src->unk_10 >> 8) * 4, (u16)depth));
    }

    if (work->src->state->flags & 32) {
        mode = 256;
    } else {
        mode = -256;
    }

    j = &work->joints.all[7];
    affine = AllocObjAffine(j->angle, mode, 256, 0);
    WorldToScreen(&x, &y, work->src->unk_00 + j->unk_00, work->src->unk_04,
                  work->src->unk_08 + j->unk_04);
    DrawSprite(x, y, j->gfx, (void*)work->tiles, pal, affine, 0x800,
               (endDepth = -4100 - (work->src->unk_04 >> 8) * 4, (u16)endDepth));
    j = &work->joints.all[3];
    affine = AllocObjAffine(j->angle, mode, 256, 0);
    WorldToScreen(&x, &y, work->src->unk_0C + j->unk_00, work->src->unk_10,
                  work->src->unk_14 + j->unk_04);
    DrawSprite(x, y, j->gfx, (void*)work->tiles, pal, affine, 0x800,
               (endDepth = -4100 - (work->src->unk_10 >> 8) * 4, (u16)endDepth));
    TaskPoolDraw(&work->tasks);
}

void task_bos_tm_arm_3(TmArmWork* work) {
    ReleaseObjTiles((void*)work->tiles);
    ReleaseObjTiles((void*)work->tiles2);
    ReleaseObjPalette(work->palette);
    ReleaseObjPalette((void*)work->palette2);
    TaskPoolDestroy(&work->tasks);
}

void task_bos_tm_tbl_0(TmTblWork* work, void* arg) {
    ColliderInit(&work->collider, 7, 0x1C, 0);
    ColliderSetPosition(&work->collider, 0x10000, 0x16000, 0);
    ColliderSetDisabled(&work->collider, 0);
    DisableBg(1);
    work->unk_000 = arg;
    work->unk_068 = 0;
    work->unk_062 = 1;
    work->unk_064 = 0;
    work->unk_066 = 0;
    work->unk_067 = 0;
    work->unk_060 = 0;
}

u8 task_bos_tm_tbl_1(TmTblWork* work) {
    s32 z;
    u16 t;

    switch (work->unk_068) {
    case 1:
        if ((s8)((u8*)work->unk_000)[58] == 1) {
            work->unk_066 = 0;
            work->unk_068 = 3;
        }
        break;
    case 0:
        if (work->unk_067 == 0) {
            if (func_0801C1C0(0) != 0) {
                work->unk_067 = 1;
            }
        } else {
            work->unk_068 = 2;
            ((u8*)work->unk_000)[58] = (z = 0, 1);
            work->unk_067 = z;
        }
        break;
    case 2:
        switch (work->unk_066) {
        case 0:
            m4aSongNumStart(SONG_BTL_TABLE_U);
            EnableBg(1);
            LoadBgMap(1, &gUnk_096BF464[0x5000], 0x800);
            ColliderSetDisabled(&work->collider, 0);
            break;
        case 2:
            LoadBgMap(1, &gUnk_096BF464[0x4800], 0x800);
            break;
        case 4:
            LoadBgMap(1, &gUnk_096BF464[0x4000], 0x800);
            break;
        case 6:
            LoadBgMap(1, &gUnk_096BF464[0x3800], 0x800);
            break;
        case 8:
            LoadBgMap(1, &gUnk_096BF464[0x3000], 0x800);
            break;
        case 10:
            LoadBgMap(1, &gUnk_096BF464[0x2800], 0x800);
            break;
        case 12:
            LoadBgMap(1, &gUnk_096BF464[0x2000], 0x800);
            break;
        case 14:
            LoadBgMap(1, &gUnk_096BF464[0x1800], 0x800);
            break;
        case 16:
            LoadBgMap(1, &gUnk_096BF464[0x1000], 0x800);
            break;
        }

        if (work->unk_066 > 15) {
            work->unk_066 = 0;
            work->unk_068 = 1;
            ((u8*)work->unk_000)[58] = 2;
            t = *(u16*)((u8*)work->unk_000 + 40) | 0x10;
            *(u16*)((u8*)work->unk_000 + 40) = t;
        } else {
            ColliderSetHeight(&work->collider, work->unk_060);
            work->unk_060 += 3;
            work->unk_066++;
        }
        break;
    case 3:
        switch (work->unk_066) {
        case 0:
            LoadBgMap(1, &gUnk_096BF464[0x1800], 0x800);
            ColliderSetDisabled(&work->collider, 1);
            work->unk_060 = 0;
            break;
        case 1:
            LoadBgMap(1, &gUnk_096BF464[0x2000], 0x800);
            break;
        case 2:
            LoadBgMap(1, &gUnk_096BF464[0x2800], 0x800);
            break;
        case 3:
            LoadBgMap(1, &gUnk_096BF464[0x3000], 0x800);
            break;
        case 4:
            LoadBgMap(1, &gUnk_096BF464[0x3800], 0x800);
            break;
        case 5:
            LoadBgMap(1, &gUnk_096BF464[0x4000], 0x800);
            break;
        case 6:
            LoadBgMap(1, &gUnk_096BF464[0x4800], 0x800);
            break;
        case 7:
            LoadBgMap(1, &gUnk_096BF464[0x5000], 0x800);
            break;
        case 8:
            DisableBg(1);
            break;
        }

        if (work->unk_066 > 7) {
            work->unk_066 = 0;
            work->unk_068 = 0;
            ((u8*)work->unk_000)[58] = 0;
        } else {
            work->unk_066++;
        }
        break;
    }

    SetBgScroll(1, (u16)((gBtlWork->unk_000 >> 8) + 8), (u16)((gBtlWork->unk_004 >> 8) - 70));
    return 1;
}

void task_bos_tm_tbl_3(TmTblWork* work) {
    ColliderUnregister(&work->collider);
    DisableBg(1);
}

u8 gUnk_09EF21B0[8] = { 2, 1, 0, 1, 2, 3, 4, 3 };

s16 gUnk_09EF21B8[5] = { -15, -6, 0, 8, 20 };

s16 gUnk_09EF21C2 = 0;

TmFootStep gBosTmFootSteps[3] = {
    { 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, 6, 0, 1, 0, 6, 0, 1, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, 9, 0, 0, 0, 9, 0, 0, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
};

TmFootStep gUnk_09EF2224 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } };

TmFootStep gUnk_09EF2244[16] = {
    { 0, -8, 0, 3, 0, -8, 0, 3, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, -12, 0, 4, 0, -12, 0, 4, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, -8, 0, 5, 0, -8, 0, 5, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, 8, 0, 4, 0, 8, 0, 4, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, 12, 0, 3, 0, 12, 0, 3, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, 8, 0, 2, 0, 8, 0, 2, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, 6, 0, 1, 0, 6, 0, 1, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, 9, 0, 0, 0, 9, 0, 0, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, -9, 0, 1, 0, -9, 0, 1, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, -6, 0, 2, 0, -6, 0, 2, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
};

TmFootStep gUnk_09EF2444 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } };

TmFootStep gUnk_09EF2464[10] = {
    { 0, 0, 0, 7, 0, 0, 0, 2, -13, -10, { 0, 0, 0, 0 }, 0, 21, { 0, 0, 0, 0 } },
    { 0, 0, 0, 8, 0, 0, 0, 3, -20, 29, { 0, 0, 0, 0 }, 11, 25, { 0, 0, 0, 0 } },
    { 0, 0, 0, 9, 0, 0, 0, 4, -23, 39, { 0, 0, 0, 0 }, 24, 12, { 0, 0, 0, 0 } },
    { 0, 0, 0, 0, 0, 0, 0, 5, -4, 27, { 0, 0, 0, 0 }, 16, -15, { 0, 0, 0, 0 } },
    { 0, 0, 0, 1, 0, 0, 0, 6, 0, 10, { 0, 0, 0, 0 }, -4, -7, { 0, 0, 0, 0 } },
    { 0, 0, 0, 2, 0, 0, 0, 7, 0, 21, { 0, 0, 0, 0 }, -13, -10, { 0, 0, 0, 0 } },
    { 0, 0, 0, 3, 0, 0, 0, 8, 11, 25, { 0, 0, 0, 0 }, -20, 29, { 0, 0, 0, 0 } },
    { 0, 0, 0, 4, 0, 0, 0, 9, 24, 12, { 0, 0, 0, 0 }, -23, 39, { 0, 0, 0, 0 } },
    { 0, 0, 0, 5, 0, 0, 0, 0, 16, -15, { 0, 0, 0, 0 }, -4, 27, { 0, 0, 0, 0 } },
    { 0, 0, 0, 6, 0, 0, 0, 1, -4, -7, { 0, 0, 0, 0 }, 0, 10, { 0, 0, 0, 0 } },
};

TmFootStep gUnk_09EF25A4[9] = {
    { 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, 6, 0, 1, 0, 6, 0, 1, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, 9, 0, 0, 0, 9, 0, 0, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, -9, 0, 0, 0, -9, 0, 0, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, -6, 0, 1, 0, -6, 0, 1, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, -8, 0, 3, 0, -8, 0, 3, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, -12, 0, 4, 0, -12, 0, 4, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
    { 0, -8, 0, 5, 0, -8, 0, 5, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } },
};

TmFootStep gUnk_09EF26C4 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, { 0, 0, 0, 0 }, 0, 0, { 0, 0, 0, 0 } };

TaskDesc gTaskDescBosTmFoot = {
    gTaskNameBosTmFoot,
    (TaskInitFunc)task_bos_tm_foot_0,
    (TaskUpdateFunc)task_bos_tm_foot_1,
    (TaskFunc)task_bos_tm_foot_2,
    (TaskFunc)task_bos_tm_foot_3,
    0x484,
};

TaskDesc gTaskDescBosTmClb = {
    gTaskNameBosTmClb,
    (TaskInitFunc)task_bos_tm_clb_0,
    (TaskUpdateFunc)task_bos_tm_clb_1,
    (TaskFunc)task_bos_tm_clb_2,
    (TaskFunc)task_bos_tm_clb_3,
    0x1C,
};

TaskDesc gTaskDescBosTmArm = {
    "task_bos_tm_arm",
    (TaskInitFunc)task_bos_tm_arm_0,
    (TaskUpdateFunc)task_bos_tm_arm_1,
    (TaskFunc)task_bos_tm_arm_2,
    (TaskFunc)task_bos_tm_arm_3,
    0x258,
};

TaskDesc gTaskDescBosTmTbl = {
    "task_bos_tm_tbl",
    (TaskInitFunc)task_bos_tm_tbl_0,
    (TaskUpdateFunc)task_bos_tm_tbl_1,
    0,
    (TaskFunc)task_bos_tm_tbl_3,
    0x6C,
};
