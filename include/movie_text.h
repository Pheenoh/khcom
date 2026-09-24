#ifndef GUARD_MOVIE_TEXT_H
#define GUARD_MOVIE_TEXT_H

#include "types.h"
#include "text_types.h"

#ifndef VERSION_JP
s16 func_0805E848(u16* widths, u16 count);
#endif
u16 CountNonSpaceChars(TextChar* str);

#endif
