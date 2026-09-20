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

extern MapNameText* gUnk_09EF7048[28];


#ifdef VERSION_EU
extern LocalizedText gMapNameEu_08893480;
extern LocalizedText gMapNameEu_0889352C;
extern LocalizedText gMapNameEu_088935D8;
extern LocalizedText gMapNameEu_08893684;
extern LocalizedText gMapNameEu_08893730;
extern LocalizedText gMapNameEu_088937DC;
extern LocalizedText gMapNameEu_0889388C;
extern LocalizedText gMapNameEu_08893938;
extern LocalizedText gMapNameEu_088939E4;
extern LocalizedText gMapNameEu_08893A94;
extern LocalizedText gMapNameEu_08893B48;
extern LocalizedText gMapNameEu_08893BFC;
extern LocalizedText gMapNameEu_08893CB8;
extern LocalizedText gMapNameEu_08893D78;
extern LocalizedText gMapNameEu_08893E38;
extern LocalizedText gMapNameEu_08893EF4;
extern LocalizedText gMapNameEu_08893FAC;
extern LocalizedText gMapNameEu_08894068;
extern LocalizedText gMapNameEu_08894124;
extern LocalizedText gMapNameEu_088941DC;
extern LocalizedText gMapNameEu_08894294;
extern LocalizedText gMapNameEu_0889434C;
extern LocalizedText gMapNameEu_08894408;
extern LocalizedText gMapNameEu_088944C0;
extern LocalizedText gMapNameEu_08894578;
#endif

#endif
