#ifndef GUARD_CARD_DESCRIPTION_DATA_H
#define GUARD_CARD_DESCRIPTION_DATA_H

#include "text_types.h"

#ifdef VERSION_US
typedef u16 CardDescriptionText;
#elif defined(VERSION_JP)
typedef u8 CardDescriptionText;
#else
typedef LocalizedText CardDescriptionText;
#endif

extern CardDescriptionText* gUnk_09EE8F48[];
extern CardDescriptionText* gUnk_09EE90D0[];
extern CardDescriptionText* gUnk_09EE9138[];

#endif
