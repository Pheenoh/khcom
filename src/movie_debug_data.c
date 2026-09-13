#include "movie_debug_data.h"

#ifdef VERSION_EU

const char gMovieDebugTextEu_0812F6A8[] __attribute__((section(".rodata_gMovieDebugTextEu_0812F6A8"), aligned(4))) = "RIKU_ENDING";

const char gMovieDebugTextEu_0812F6B4[] __attribute__((section(".rodata_gMovieDebugTextEu_0812F6B4"), aligned(4))) = "ENDING";

const char gMovieDebugTextEu_0812F6BC[] __attribute__((section(".rodata_gMovieDebugTextEu_0812F6BC"), aligned(4))) = "12F_E2";

const char gMovieDebugTextEu_0812F6C4[] __attribute__((section(".rodata_gMovieDebugTextEu_0812F6C4"), aligned(4))) = "6F_GOAL";

const char gMovieDebugTextEu_0812F6CC[] __attribute__((section(".rodata_gMovieDebugTextEu_0812F6CC"), aligned(4))) = "OPENING";

const char gMovieDebugTextEu_0812F6D4[] __attribute__((section(".rodata_gMovieDebugTextEu_0812F6D4"), aligned(4))) = "                              ";

const char gMovieDebugTextEu_0812F6F4[] __attribute__((section(".rodata_gMovieDebugTextEu_0812F6F4"), aligned(4))) = ": ";

const char gMovieDebugTextEu_0812F6F8[] __attribute__((section(".rodata_gMovieDebugTextEu_0812F6F8"), aligned(4))) = "mode_chkmov";

MovieDebugEntry gMovieDebugEntriesEu[5] __attribute__((section(".data_gMovieDebugEntriesEu"))) = {
    {1, gMovieDebugTextEu_0812F6CC},
    {2, gMovieDebugTextEu_0812F6C4},
    {3, gMovieDebugTextEu_0812F6BC},
    {4, gMovieDebugTextEu_0812F6B4},
    {5, gMovieDebugTextEu_0812F6A8},
};

Mode gModeMovieDebugEu __attribute__((section(".data_gModeMovieDebugEu"))) = {
    gMovieDebugTextEu_0812F6F8,
    eu_0800C76C,
    eu_0800C7A0,
    eu_0800C898,
};

#endif
