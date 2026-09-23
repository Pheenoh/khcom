#include "card_localized_data.h"
#include "card_localized_assets.h"
#include "sprites_deck_menu.h"

#if defined(VERSION_US)
void* gUnk_09EEAFD4 = gUnk_090A1F88;

void* gUnk_09EEAFD8 = gUnk_090A1F98;

AnimHeader* gUnkUs_09EEAFDC = &gUnk_090A1FA8;

void* gUnkUs_09EEAFE0 = gUnk_090A2234;

AnimHeader* gUnkUs_09EEAFE4 = &gUnk_090A228C;

void* gUnk_09EEAFE8 = gUnk_090A25F8;

AnimHeader* gUnkUs_09EEAFEC = &gUnk_090A2614;

void* gUnk_09EEAFF0 = gUnk_090A3E20;

AnimHeader* gUnkUs_09EEAFF4 = &gUnk_090A3E3C;

void* gUnk_09EEAFF8 = gUnk_090A4168;

AnimHeader* gUnkUs_09EEAFFC = &gUnk_090A4184;

void* gUnk_09EEB000 = gUnk_090A44B0;

AnimHeader* gUnkUs_09EEB004 = &gUnk_090A44BA;
#elif defined(VERSION_JP)
void* gUnk_09EEAFD4 = gUnk_090A1F88;

void* gUnk_09EEAFD8 = gUnk_090A1F98;

AnimHeader* gUnkJp_09EC23D0 = &gUnk_090A1FA8;

void* gUnkJp_09EC23D4 = gUnk_090A2234;

AnimHeader* gUnkJp_09EC23D8 = &gUnk_090A228C;

void* gUnk_09EEAFE8 = gUnk_090A25F8;

AnimHeader* gUnkJp_09EC23E0 = &gUnk_090A2614;

void* gUnk_09EEAFF0 = gUnk_090A3E20;

AnimHeader* gUnkJp_09EC23E8 = &gUnk_090A3E3C;

void* gUnk_09EEB000 = gUnk_090A44B0;

AnimHeader* gUnkJp_09EC23F0 = &gUnk_090A44BA;
#elif defined(VERSION_EU)
void* gUnk_09EEAFD4 = gUnk_090A1F88;

void* gUnk_09EEAFD8 = gUnk_090A1F98;

AnimHeader* gUnkEu_09F7704C = &gUnk_090A1FA8;

void* gUnkEu_09F77050 = gUnk_090A2234;

AnimHeader* gUnkEu_09F77054 = &gUnk_090A228C;

void* gUnk_09EEAFE8 = gUnk_090A25F8;

AnimHeader* gUnkEu_09F7705C = &gUnk_090A2614;

void* gUnk_09EEAFF0 = gUnk_090A3E20;

AnimHeader* gUnkEu_09F77064 = &gUnk_090A3E3C;

void* gUnk_09EEAFF8 = gUnk_090A4168;

AnimHeader* gUnkEu_09F7706C = &gUnk_090A4184;

void* gUnkEu_09F77070 = gUnk_090A44B0;

void* gUnkEu_09F77074 = gUnkEu_09189F1C;

AnimHeader* gUnkEu_09F77078 = &gUnkEu_09189F2C;

void* gUnkEu_09F7707C = gUnkEu_0918A1B8;

void* gUnkEu_09F77080 = gUnkEu_0918A1C8;

AnimHeader* gUnkEu_09F77084 = &gUnkEu_0918A1D8;

void* gUnkEu_09F77088 = gUnkEu_0918A464;

void* gUnkEu_09F7708C = gUnkEu_0918A474;

AnimHeader* gUnkEu_09F77090 = &gUnkEu_0918A484;

void* gUnkEu_09F77094 = gUnkEu_0918A710;

void* gUnkEu_09F77098 = gUnkEu_0918A720;

AnimHeader* gUnkEu_09F7709C = &gUnkEu_0918A730;

void* gUnkEu_09F770A0 = gUnkEu_0918A9BC;

AnimHeader* gUnkEu_09F770A4 = &gUnkEu_0918AA14;

void* gUnkEu_09F770A8 = gUnkEu_0918AD80;

AnimHeader* gUnkEu_09F770AC = &gUnkEu_0918ADD8;

void* gUnkEu_09F770B0 = gUnkEu_0918B144;

AnimHeader* gUnkEu_09F770B4 = &gUnkEu_0918B19C;

void* gUnkEu_09F770B8 = gUnkEu_0918B508;

AnimHeader* gUnkEu_09F770BC = &gUnkEu_0918B560;

void* gUnkEu_09F770C0 = gUnkEu_0918B8CC;

AnimHeader* gUnkEu_09F770C4 = &gUnkEu_0918B8E8;

void* gUnkEu_09F770C8 = gUnkEu_0918D0F4;

AnimHeader* gUnkEu_09F770CC = &gUnkEu_0918D110;

void* gUnkEu_09F770D0 = gUnkEu_0918E91C;

AnimHeader* gUnkEu_09F770D4 = &gUnkEu_0918E938;

void* gUnkEu_09F770D8 = gUnkEu_09190144;

AnimHeader* gUnkEu_09F770DC = &gUnkEu_09190160;

void* gUnkEu_09F770E0 = gUnkEu_0919196C;

AnimHeader* gUnkEu_09F770E4 = &gUnkEu_09191988;

void* gUnkEu_09F770E8 = gUnkEu_09191CB4;

AnimHeader* gUnkEu_09F770EC = &gUnkEu_09191CD0;

void* gUnkEu_09F770F0 = gUnkEu_09191FFC;

AnimHeader* gUnkEu_09F770F4 = &gUnkEu_09192018;

void* gUnkEu_09F770F8 = gUnkEu_09192344;

AnimHeader* gUnkEu_09F770FC = &gUnkEu_09192360;

void* gUnkEu_09F77100 = gUnkEu_0919268C;

AnimHeader* gUnkEu_09F77104 = &gUnkEu_091926A8;

void* gUnkEu_09F77108 = gUnkEu_091929D4;

AnimHeader* gUnkEu_09F7710C = &gUnkEu_091929F0;

void* gUnkEu_09F77110 = gUnkEu_09192D1C;

AnimHeader* gUnkEu_09F77114 = &gUnkEu_09192D38;

void* gUnkEu_09F77118 = gUnkEu_09193064;

AnimHeader* gUnkEu_09F7711C = &gUnkEu_09193080;

void* gUnk_09EEB000 = gUnkEu_091933AC;

AnimHeader* gUnkEu_09F77124 = &gUnk_090A44BA;
#endif
