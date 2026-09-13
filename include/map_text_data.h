#ifndef GUARD_MAP_TEXT_DATA_H
#define GUARD_MAP_TEXT_DATA_H

#include "text_types.h"

#ifdef VERSION_US
typedef u16 MapNameText;
#elif defined(VERSION_JP)
typedef u8 MapNameText;
#else
typedef LocalizedText MapNameText;
#endif

extern MapNameText* gUnk_09EF6FCC[13];
extern MapNameText* gUnk_09EF7000[12];
extern MapNameText* gUnk_09EF7048[28];

extern u8 gUnk_09EF6C38[2];

#endif
