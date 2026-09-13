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
    CardHelpText** unk_00;
    u8 unk_04;
    u8 unk_05[3];
} CardHelpDef;

extern CardHelpDef* gUnk_09EE7D84[];

extern CardHelpText* gUnk_09EE7A38[];
extern CardHelpDef gUnk_0903BD0C;
extern CardHelpText* gUnk_09EE7A40[];
extern CardHelpDef gUnk_0903BD14;
extern CardHelpText* gUnk_09EE7A48[];
extern CardHelpDef gUnk_0903BD1C;
extern CardHelpText* gUnk_09EE7A50[];
extern CardHelpDef gUnk_0903BD24;
extern CardHelpText* gUnk_09EE7A60[];
extern CardHelpDef gUnk_0903BD2C;
extern CardHelpText* gUnk_09EE79F4[];
extern CardHelpDef gUnk_0903BD34;
extern CardHelpText* gUnk_09EE7A08[];
extern CardHelpDef gUnk_0903BD3C;
extern CardHelpText* gUnk_09EE7A70[];
extern CardHelpDef gUnk_0903BD44;
extern CardHelpText* gUnk_09EE7A78[];
extern CardHelpDef gUnk_0903BD4C;
extern CardHelpText* gUnk_09EE7A80[];
extern CardHelpDef gUnk_0903BD54;
extern CardHelpText* gUnk_09EE7A88[];
extern CardHelpDef gUnk_0903BD5C;
extern CardHelpText* gUnk_09EE7A58[];
extern CardHelpDef gUnk_0903BD64;
extern CardHelpText* gUnk_09EE7A90[];
extern CardHelpDef gUnk_0903BD6C;
extern CardHelpText* gUnk_09EE7A98[];
extern CardHelpDef gUnk_0903BD74;
extern CardHelpText* gUnk_09EE7B98[];
extern CardHelpDef gUnk_0903BD7C;
extern CardHelpText* gUnk_09EE7BA0[];
extern CardHelpDef gUnk_0903BD84;
extern CardHelpText* gUnk_09EE7B78[];
extern CardHelpDef gUnk_0903BD8C;
extern CardHelpText* gUnk_09EE7B88[];
extern CardHelpDef gUnk_0903BD94;
extern CardHelpText* gUnk_09EE7AA8[];
extern CardHelpDef gUnk_0903BD9C;
extern CardHelpText* gUnk_09EE7AB8[];
extern CardHelpDef gUnk_0903BDA4;
extern CardHelpText* gUnk_09EE7AC8[];
extern CardHelpDef gUnk_0903BDAC;
extern CardHelpText* gUnk_09EE7AD8[];
extern CardHelpDef gUnk_0903BDB4;
extern CardHelpText* gUnk_09EE7B38[];
extern CardHelpDef gUnk_0903BDBC;
extern CardHelpText* gUnk_09EE7B48[];
extern CardHelpDef gUnk_0903BDC4;
extern CardHelpText* gUnk_09EE7B58[];
extern CardHelpDef gUnk_0903BDCC;
extern CardHelpText* gUnk_09EE7B68[];
extern CardHelpDef gUnk_0903BDD4;
extern CardHelpText* gUnk_09EE7AE8[];
extern CardHelpDef gUnk_0903BDDC;
extern CardHelpText* gUnk_09EE7AF8[];
extern CardHelpDef gUnk_0903BDE4;
extern CardHelpText* gUnk_09EE7B08[];
extern CardHelpDef gUnk_0903BDEC;
extern CardHelpText* gUnk_09EE7B18[];
extern CardHelpDef gUnk_0903BDF4;
extern CardHelpText* gUnk_09EE7B28[];
extern CardHelpDef gUnk_0903BDFC;
extern CardHelpText* gUnk_09EE7B30[];
extern CardHelpDef gUnk_0903BE04;
extern CardHelpText* gUnk_09EE7BA8[];
extern CardHelpDef gUnk_0903BE0C;
extern CardHelpText* gUnk_09EE7BB8[];
extern CardHelpDef gUnk_0903BE14;
extern CardHelpText* gUnk_09EE7BE8[];
extern CardHelpDef gUnk_0903BE1C;
extern CardHelpText* gUnk_09EE7BF8[];
extern CardHelpDef gUnk_0903BE24;
extern CardHelpText* gUnk_09EE7BC8[];
extern CardHelpDef gUnk_0903BE2C;
extern CardHelpText* gUnk_09EE7BD8[];
extern CardHelpDef gUnk_0903BE34;
extern CardHelpText* gUnk_09EE7C08[];
extern CardHelpDef gUnk_0903BE3C;
extern CardHelpText* gUnk_09EE7C18[];
extern CardHelpDef gUnk_0903BE44;
extern CardHelpText* gUnk_09EE7C28[];
extern CardHelpDef gUnk_0903BE4C;
extern CardHelpText* gUnk_09EE7C38[];
extern CardHelpDef gUnk_0903BE54;
extern CardHelpText* gUnk_09EE7D54[];
extern CardHelpDef gUnk_0903BE5C;
extern CardHelpText* gUnk_09EE7D64[];
extern CardHelpDef gUnk_0903BE64;
extern CardHelpText* gUnk_09EE7A68[];
extern CardHelpDef gUnk_0903BE6C;
extern CardHelpText* gUnk_09EE7AA0[];
extern CardHelpDef gUnk_0903BE74;
extern CardHelpText* gUnk_09EE79EC[];
extern CardHelpDef gUnk_0903BE7C;
extern CardHelpText* gUnk_09EE7A00[];
extern CardHelpDef gUnk_0903BE84;
extern CardHelpText* gUnk_09EE7A10[];
extern CardHelpDef gUnk_0903BE8C;
extern CardHelpText* gUnk_09EE7A18[];
extern CardHelpDef gUnk_0903BE94;
extern CardHelpText* gUnk_09EE7A20[];
extern CardHelpDef gUnk_0903BE9C;
extern CardHelpText* gUnk_09EE7A28[];
extern CardHelpDef gUnk_0903BEA4;
extern CardHelpText* gUnk_09EE7A30[];
extern CardHelpDef gUnk_0903BEAC;
extern CardHelpText* gUnk_09EE7C48[];
extern CardHelpDef gUnk_0903BEB4;
extern CardHelpText* gUnk_09EE7C50[];
extern CardHelpDef gUnk_0903BEBC;
extern CardHelpText* gUnk_09EE7C58[];
extern CardHelpDef gUnk_0903BEC4;
extern CardHelpText* gUnk_09EE7C64[];
extern CardHelpDef gUnk_0903BECC;
#ifndef VERSION_EU
extern CardHelpText* gUnk_09EE7D74[];
extern CardHelpDef gUnk_0903BED4;
#endif
extern CardHelpText* gUnk_09EE7C6C[];
extern CardHelpDef gUnk_0903BEDC;
extern CardHelpText* gUnk_09EE7C74[];
extern CardHelpDef gUnk_0903BEE4;
extern CardHelpText* gUnk_09EE7C7C[];
extern CardHelpDef gUnk_0903BEEC;
extern CardHelpText* gUnk_09EE7C84[];
extern CardHelpDef gUnk_0903BEF4;
extern CardHelpText* gUnk_09EE7C8C[];
extern CardHelpDef gUnk_0903BEFC;
extern CardHelpText* gUnk_09EE7C94[];
extern CardHelpDef gUnk_0903BF04;
extern CardHelpText* gUnk_09EE7C9C[];
extern CardHelpDef gUnk_0903BF0C;
extern CardHelpText* gUnk_09EE7CA4[];
extern CardHelpDef gUnk_0903BF14;
extern CardHelpText* gUnk_09EE7CAC[];
extern CardHelpDef gUnk_0903BF1C;
extern CardHelpText* gUnk_09EE7CB4[];
extern CardHelpDef gUnk_0903BF24;
#ifndef VERSION_EU
extern CardHelpText* gUnk_09EE7D7C[];
extern CardHelpDef gUnk_0903BF2C;
#endif
extern CardHelpText* gUnk_09EE7CBC[];
extern CardHelpDef gUnk_0903BF34;
extern CardHelpText* gUnk_09EE7CC8[];
extern CardHelpDef gUnk_0903BF3C;
extern CardHelpText* gUnk_09EE7CD0[];
extern CardHelpDef gUnk_0903BF44;
extern CardHelpText* gUnk_09EE7CD8[];
extern CardHelpDef gUnk_0903BF4C;
extern CardHelpText* gUnk_09EE7CE0[];
extern CardHelpDef gUnk_0903BF54;
extern CardHelpText* gUnk_09EE7CE8[];
extern CardHelpDef gUnk_0903BF5C;
extern CardHelpText* gUnk_09EE7CF0[];
extern CardHelpDef gUnk_0903BF64;
extern CardHelpText* gUnk_09EE7CF8[];
extern CardHelpDef gUnk_0903BF6C;
extern CardHelpText* gUnk_09EE7D00[];
extern CardHelpDef gUnk_0903BF74;
extern CardHelpText* gUnk_09EE7D08[];
extern CardHelpDef gUnk_0903BF7C;
extern CardHelpText* gUnk_09EE7D10[];
extern CardHelpDef gUnk_0903BF84;
extern CardHelpText* gUnk_09EE7D18[];
extern CardHelpDef gUnk_0903BF8C;
extern CardHelpText* gUnk_09EE7D20[];
extern CardHelpDef gUnk_0903BF94;
extern CardHelpText* gUnk_09EE7D2C[];
extern CardHelpDef gUnk_0903BF9C;
extern CardHelpText* gUnk_09EE7D34[];
extern CardHelpDef gUnk_0903BFA4;
extern CardHelpText* gUnk_09EE7D3C[];
extern CardHelpDef gUnk_0903BFAC;
#ifndef VERSION_EU
extern CardHelpText* gUnk_09EE7D44[];
extern CardHelpDef gUnk_0903BFB4;
#endif

#endif
