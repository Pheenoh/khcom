#ifndef GUARD_CARD_HELP_DATA_H
#define GUARD_CARD_HELP_DATA_H

#include "text_types.h"

#ifdef VERSION_US
typedef u16 CardHelpText;
#elif defined(VERSION_JP)
typedef u8 CardHelpText;
#else
typedef LocalizedText CardHelpText;
#endif

typedef struct CardHelpDef {
    CardHelpText** texts;
    u8 textCount;
    u8 unk_05[3];
} CardHelpDef;

extern const CardHelpDef gUnk_0903BD0C;
extern const CardHelpDef gUnk_0903BD14;
extern const CardHelpDef gUnk_0903BFB4;
extern const CardHelpDef gUnk_0903BD1C;
extern const CardHelpDef gUnk_0903BD24;
extern const CardHelpDef gUnk_0903BD2C;
extern const CardHelpDef gUnk_0903BD34;
extern const CardHelpDef gUnk_0903BD3C;
extern const CardHelpDef gUnk_0903BD44;
extern const CardHelpDef gUnk_0903BD4C;
extern const CardHelpDef gUnk_0903BD54;
extern const CardHelpDef gUnk_0903BD5C;
extern const CardHelpDef gUnk_0903BD64;
extern const CardHelpDef gUnk_0903BD6C;
extern const CardHelpDef gUnk_0903BD74;
extern const CardHelpDef gUnk_0903BD7C;
extern const CardHelpDef gUnk_0903BD84;
extern const CardHelpDef gUnk_0903BD8C;
extern const CardHelpDef gUnk_0903BD94;
extern const CardHelpDef gUnk_0903BD9C;
extern const CardHelpDef gUnk_0903BDA4;
extern const CardHelpDef gUnk_0903BDAC;
extern const CardHelpDef gUnk_0903BDB4;
extern const CardHelpDef gUnk_0903BDBC;
extern const CardHelpDef gUnk_0903BDC4;
extern const CardHelpDef gUnk_0903BDCC;
extern const CardHelpDef gUnk_0903BDD4;
extern const CardHelpDef gUnk_0903BDDC;
extern const CardHelpDef gUnk_0903BDE4;
extern const CardHelpDef gUnk_0903BDEC;
extern const CardHelpDef gUnk_0903BDF4;
extern const CardHelpDef gUnk_0903BDFC;
extern const CardHelpDef gUnk_0903BE04;
extern const CardHelpDef gUnk_0903BE0C;
extern const CardHelpDef gUnk_0903BE14;
extern const CardHelpDef gUnk_0903BE1C;
extern const CardHelpDef gUnk_0903BE24;
extern const CardHelpDef gUnk_0903BE2C;
extern const CardHelpDef gUnk_0903BE34;
extern const CardHelpDef gUnk_0903BE3C;
extern const CardHelpDef gUnk_0903BE44;
extern const CardHelpDef gUnk_0903BE4C;
extern const CardHelpDef gUnk_0903BE54;
extern const CardHelpDef gUnk_0903BE5C;
extern const CardHelpDef gUnk_0903BE64;
extern const CardHelpDef gUnk_0903BE6C;
extern const CardHelpDef gUnk_0903BE74;
extern const CardHelpDef gUnk_0903BE7C;
extern const CardHelpDef gUnk_0903BE84;
extern const CardHelpDef gUnk_0903BE8C;
extern const CardHelpDef gUnk_0903BE94;
extern const CardHelpDef gUnk_0903BE9C;
extern const CardHelpDef gUnk_0903BEA4;
extern const CardHelpDef gUnk_0903BEAC;
extern const CardHelpDef gUnk_0903BEB4;
extern const CardHelpDef gUnk_0903BEBC;
extern const CardHelpDef gUnk_0903BEC4;
extern const CardHelpDef gUnk_0903BECC;
extern const CardHelpDef gUnk_0903BED4;
extern const CardHelpDef gUnk_0903BEDC;
extern const CardHelpDef gUnk_0903BEE4;
extern const CardHelpDef gUnk_0903BEEC;
extern const CardHelpDef gUnk_0903BEF4;
extern const CardHelpDef gUnk_0903BEFC;
extern const CardHelpDef gUnk_0903BF04;
extern const CardHelpDef gUnk_0903BF0C;
extern const CardHelpDef gUnk_0903BF14;
extern const CardHelpDef gUnk_0903BF1C;
extern const CardHelpDef gUnk_0903BF24;
extern const CardHelpDef gUnk_0903BF2C;
extern const CardHelpDef gUnk_0903BF34;
extern const CardHelpDef gUnk_0903BF3C;
extern const CardHelpDef gUnk_0903BF44;
extern const CardHelpDef gUnk_0903BF4C;
extern const CardHelpDef gUnk_0903BF54;
extern const CardHelpDef gUnk_0903BF5C;
extern const CardHelpDef gUnk_0903BF64;
extern const CardHelpDef gUnk_0903BF6C;
extern const CardHelpDef gUnk_0903BF74;
extern const CardHelpDef gUnk_0903BF7C;
extern const CardHelpDef gUnk_0903BF84;
extern const CardHelpDef gUnk_0903BF8C;
extern const CardHelpDef gUnk_0903BF94;
extern const CardHelpDef gUnk_0903BF9C;
extern const CardHelpDef gUnk_0903BFA4;
extern const CardHelpDef gUnk_0903BFAC;

#endif
