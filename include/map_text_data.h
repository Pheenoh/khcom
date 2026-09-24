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

extern MapNameText* gRoomNames[28];


#ifdef VERSION_EU

extern const LocalizedText gMapNameEu_08893370;
extern const LocalizedText gMapNameEu_088933D4;
extern const LocalizedText gMapNameEu_08893480;
extern const LocalizedText gMapNameEu_0889352C;
extern const LocalizedText gMapNameEu_088935D8;
extern const LocalizedText gMapNameEu_08893684;
extern const LocalizedText gMapNameEu_08893730;
extern const LocalizedText gMapNameEu_088937DC;
extern const LocalizedText gMapNameEu_0889388C;
extern const LocalizedText gMapNameEu_08893938;
extern const LocalizedText gMapNameEu_088939E4;
extern const LocalizedText gMapNameEu_08893A94;
extern const LocalizedText gMapNameEu_08893B48;
extern const LocalizedText gMapNameEu_08893BFC;
extern const LocalizedText gMapNameEu_08893CB8;
extern const LocalizedText gMapNameEu_08893D78;
extern const LocalizedText gMapNameEu_08893E38;
extern const LocalizedText gMapNameEu_08893EF4;
extern const LocalizedText gMapNameEu_08893FAC;
extern const LocalizedText gMapNameEu_08894068;
extern const LocalizedText gMapNameEu_08894124;
extern const LocalizedText gMapNameEu_088941DC;
extern const LocalizedText gMapNameEu_08894294;
extern const LocalizedText gMapNameEu_0889434C;
extern const LocalizedText gMapNameEu_08894408;
extern const LocalizedText gMapNameEu_088944C0;
extern const LocalizedText gMapNameEu_08894578;
#endif

#endif
