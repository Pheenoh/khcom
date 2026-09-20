#ifndef GUARD_MOVIE_DEBUG_H
#define GUARD_MOVIE_DEBUG_H

#include "mode.h"
#include "taskpool.h"

#ifdef VERSION_EU

typedef struct MovieDebugWork {
    TaskPool pool;
    s16 index;
} MovieDebugWork;

typedef struct MovieDebugEntry {
    s32 movie;
    const char* label;
} MovieDebugEntry;

extern Mode gModeMovieDebugEu;
#endif

#endif
