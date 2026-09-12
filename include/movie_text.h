#ifndef GUARD_MOVIE_TEXT_H
#define GUARD_MOVIE_TEXT_H

#include "types.h"

#ifdef VERSION_JP
u16 func_0805E848(u8* str);
#else
s16 func_0805E848(u16* widths, u16 count);
#endif
#ifndef VERSION_JP
#ifdef VERSION_EU
u16 func_0805E89C(u8* str);
#else
u16 func_0805E89C(u16* str);
#endif
#endif

#endif
