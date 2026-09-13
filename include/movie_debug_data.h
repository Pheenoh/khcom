#ifndef GUARD_MOVIE_DEBUG_DATA_H
#define GUARD_MOVIE_DEBUG_DATA_H

#include "mode.h"

#ifdef VERSION_EU

typedef struct MovieDebugEntry {
    s32 movie;
    const char* label;
} MovieDebugEntry;

void eu_0800C76C(s32 arg);
void eu_0800C7A0(void);
void eu_0800C898(void);

extern const char gMovieDebugTextEu_0812F6A8[];
extern const char gMovieDebugTextEu_0812F6B4[];
extern const char gMovieDebugTextEu_0812F6BC[];
extern const char gMovieDebugTextEu_0812F6C4[];
extern const char gMovieDebugTextEu_0812F6CC[];
extern const char gMovieDebugTextEu_0812F6D4[];
extern const char gMovieDebugTextEu_0812F6F4[];
extern const char gMovieDebugTextEu_0812F6F8[];

extern MovieDebugEntry gMovieDebugEntriesEu[5];
extern Mode gModeMovieDebugEu;

#endif

#endif
