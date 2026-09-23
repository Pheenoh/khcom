#include "actor_localized_data.h"
#include "battle_localized_assets.h"
#include "sprites_hum.h"
#include "sprites_emy.h"
#include "jiminy_journal.h"
#include "sprites_language_select.h"

#ifdef VERSION_US
void* gUnk_09EE25D0[5] = {
    gUnk_08C665DC,
    gUnk_08C665F2,
    gUnk_08C66608,
    gUnk_08C66624,
    gUnk_08C66640,
};

AnimHeader* gUnk_09EE25E4[4] = {
    &gUnk_08C66656,
    &gUnk_08C66664,
    &gUnk_08C6666E,
    &gUnk_08C66680,
};

void* gUnk_09EE25F4[4] = {
    gUnk_08C67F30,
    gUnk_08C67F40,
    gUnk_08C67F50,
    gUnk_08C67F60,
};

AnimHeader* gUnk_09EE2604[1] = {
    &gUnk_08C67F70,
};

void* gUnk_09EE2608[1] = {
    gUnk_08C69188,
};

void* gUnkUs_09EE260C = gUnk_08C69198;

void* gUnkUs_09EE2610 = gUnk_08C691A8;

void* gUnkUs_09EE2614 = gUnk_08C691B8;

AnimHeader* gUnk_09EE2618[1] = {
    &gUnk_08C691C8,
};

AnimHeader* gUnkUs_09EE261C = &gUnk_08C691D2;

AnimHeader* gUnkUs_09EE2620 = &gUnk_08C691DC;

AnimHeader* gUnkUs_09EE2624 = &gUnk_08C691E6;

void* gUnkUs_09EE2628 = gUnk_08C69C04;

void* gUnkUs_09EE262C = gUnk_08C69C20;

void* gUnkUs_09EE2630 = gUnk_08C69C54;

void* gUnkUs_09EE2634 = gUnk_08C69C76;

AnimHeader* gUnkUs_09EE2638 = &gUnk_08C69C92;

void* gUnkUs_09EE263C = gUnk_08C6A51C;

void* gUnkUs_09EE2640 = gUnk_08C6A526;

void* gUnkUs_09EE2644 = gUnk_08C6A530;

void* gUnkUs_09EE2648 = gUnk_08C6A53A;

AnimHeader* gUnkUs_09EE264C = &gUnk_08C6A544;

void* gUnkUs_09EE2650 = gUnk_08C6A690;

void* gUnkUs_09EE2654 = gUnk_08C6A69A;

void* gUnkUs_09EE2658 = gUnk_08C6A6A4;

AnimHeader* gUnkUs_09EE265C = &gUnk_08C6A6AE;

void* gUnkUs_09EE2660 = gUnk_08C6A878;

AnimHeader* gUnkUs_09EE2664 = &gUnk_08C6A882;

void* gUnk_09EE2668[4] = {
    gUnk_08C6A8CC,
    gUnk_08C6A8E2,
    gUnk_08C6A8F8,
    gUnk_08C6A90E,
};

AnimHeader* gUnk_09EE2678[3] = {
    &gUnk_08C6A924,
    &gUnk_08C6A92A,
    &gUnk_08C6A930,
};

AnimHeader* gUnkUs_09EE2684 = &gUnk_08C6A94E;

void* gUnkUs_09EE2688 = gUnk_08C6AA58;

AnimHeader* gUnkUs_09EE268C = &gUnk_08C6AA74;

#endif

#ifdef VERSION_JP
void* gUnk_09EE25D0[5] = {
    gUnk_08C665DC,
    gUnk_08C665F2,
    gUnk_08C66608,
    gUnk_08C66624,
    gUnk_08C66640,
};

AnimHeader* gUnk_09EE25E4[4] = {
    &gUnk_08C66656,
    &gUnk_08C66664,
    &gUnk_08C6666E,
    &gUnk_08C66680,
};

void* gUnk_09EE25F4[4] = {
    gUnk_08C67F30,
    gUnk_08C67F40,
    gUnk_08C67F50,
    gUnk_08C67F60,
};

AnimHeader* gUnk_09EE2604[1] = {
    &gUnk_08C67F70,
};

void* gUnk_09EE2608[1] = {
    gUnk_08C69188,
};

void* gUnkJp_09EBA088 = gUnk_08C69198;

void* gUnkJp_09EBA08C = gUnk_08C691A8;

void* gUnkJp_09EBA090 = gUnk_08C691B8;

AnimHeader* gUnk_09EE2618[1] = {
    &gUnk_08C691C8,
};

AnimHeader* gUnkJp_09EBA098 = &gUnk_08C691D2;

AnimHeader* gUnkJp_09EBA09C = &gUnk_08C691DC;

AnimHeader* gUnkJp_09EBA0A0 = &gUnk_08C691E6;

void* gUnkJp_09EBA0A4 = gUnk_08C69C04;

void* gUnkJp_09EBA0A8 = gUnk_08C69C20;

void* gUnkJp_09EBA0AC = gUnk_08C69C54;

void* gUnkJp_09EBA0B0 = gUnk_08C69C76;

AnimHeader* gUnkJp_09EBA0B4 = &gUnk_08C69C92;

void* gUnkJp_09EBA0B8 = gUnk_08C6A51C;

void* gUnkJp_09EBA0BC = gUnk_08C6A526;

void* gUnkJp_09EBA0C0 = gUnk_08C6A530;

void* gUnkJp_09EBA0C4 = gUnk_08C6A53A;

AnimHeader* gUnkJp_09EBA0C8 = &gUnk_08C6A544;

void* gUnkJp_09EBA0CC = gUnk_08C6A690;

void* gUnkJp_09EBA0D0 = gUnk_08C6A69A;

void* gUnkJp_09EBA0D4 = gUnk_08C6A6A4;

AnimHeader* gUnkJp_09EBA0D8 = &gUnk_08C6A6AE;

void* gUnkJp_09EBA0DC = gUnk_08C6A878;

AnimHeader* gUnkJp_09EBA0E0 = &gUnk_08C6A882;

void* gUnk_09EE2668[4] = {
    gUnk_08C6A8CC,
    gUnk_08C6A8E2,
    gUnk_08C6A8F8,
    gUnk_08C6A90E,
};

AnimHeader* gUnk_09EE2678[3] = {
    &gUnk_08C6A924,
    &gUnk_08C6A92A,
    &gUnk_08C6A930,
};

AnimHeader* gUnkJp_09EBA100 = &gUnk_08C6A94E;

void* gUnkJp_09EBA104 = gUnk_08C6AA58;

AnimHeader* gUnkJp_09EBA108 = &gUnk_08C6AA74;

#endif

#ifdef VERSION_EU
void* gUnk_09EE25D0[5] = {
    gUnk_08C665DC,
    gUnk_08C665F2,
    gUnk_08C66608,
    gUnk_08C66624,
    gUnk_08C66640,
};

AnimHeader* gUnk_09EE25E4[4] = {
    &gUnk_08C66656,
    &gUnk_08C66664,
    &gUnk_08C6666E,
    &gUnk_08C66680,
};

void* gUnk_09EE25F4[4] = {
    gUnk_08C67F30,
    gUnk_08C67F40,
    gUnk_08C67F50,
    gUnk_08C67F60,
};

AnimHeader* gUnk_09EE2604[1] = {
    &gUnk_08C67F70,
};

void* gUnk_09EE2608[1] = {
    gUnk_08C69188,
};

void* gUnkEu_09F5D418 = gUnk_08C69198;

void* gUnkEu_09F5D41C = gUnk_08C691A8;

void* gUnkEu_09F5D420 = gUnk_08C691B8;

AnimHeader* gUnk_09EE2618[1] = {
    &gUnk_08C691C8,
};

AnimHeader* gUnkEu_09F5D428 = &gUnk_08C691D2;

AnimHeader* gUnkEu_09F5D42C = &gUnk_08C691DC;

AnimHeader* gUnkEu_09F5D430 = &gUnk_08C691E6;

void* gUnkEu_09F5D434 = gUnk_08C69C04;

void* gUnkEu_09F5D438 = gUnk_08C69C20;

void* gUnkEu_09F5D43C = gUnk_08C69C54;

void* gUnkEu_09F5D440 = gUnk_08C69C76;

AnimHeader* gUnkEu_09F5D444 = &gUnk_08C69C92;

void* gUnkEu_09F5D448 = gUnkEu_08C9A4CC;

void* gUnkEu_09F5D44C = gUnkEu_08C9A4E2;

void* gUnkEu_09F5D450 = gUnkEu_08C9A516;

void* gUnkEu_09F5D454 = gUnkEu_08C9A538;

void* gUnkEu_09F5D458 = gUnkEu_08C9A554;

void* gUnkEu_09F5D45C = gUnkEu_08C9A564;

void* gUnkEu_09F5D460 = gUnkEu_08C9A57A;

void* gUnkEu_09F5D464 = gUnkEu_08C9A590;

void* gUnkEu_09F5D468 = gUnkEu_08C9A5A6;

void* gUnkEu_09F5D46C = gUnkEu_08C9A5C2;

AnimHeader* gUnkEu_09F5D470 = &gUnkEu_08C9A5D8;

void* gUnkEu_09F5D474 = gUnk_08C6A690;

void* gUnkEu_09F5D478 = gUnk_08C6A69A;

void* gUnkEu_09F5D47C = gUnk_08C6A6A4;

void* gUnkEu_09F5D480 = gUnkEu_08C9BD82;

void* gUnkEu_09F5D484 = gUnkEu_08C9BD8C;

void* gUnkEu_09F5D488 = gUnkEu_08C9BD9C;

void* gUnkEu_09F5D48C = gUnkEu_08C9BDAC;

AnimHeader* gUnkEu_09F5D490 = &gUnk_08C6A6AE;

void* gUnkEu_09F5D494 = gUnk_08C6A51C;

void* gUnkEu_09F5D498 = gUnk_08C6A526;

void* gUnkEu_09F5D49C = gUnk_08C6A530;

void* gUnkEu_09F5D4A0 = gUnk_08C6A53A;

AnimHeader* gUnkEu_09F5D4A4 = &gUnk_08C6A544;

void* gUnkEu_09F5D4A8 = gUnk_08C6A878;

AnimHeader* gUnkEu_09F5D4AC = &gUnk_08C6A882;

void* gUnk_09EE2668[4] = {
    gUnk_08C6A8CC,
    gUnk_08C6A8E2,
    gUnk_08C6A8F8,
    gUnk_08C6A90E,
};

AnimHeader* gUnk_09EE2678[3] = {
    &gUnk_08C6A924,
    &gUnk_08C6A92A,
    &gUnk_08C6A930,
};

AnimHeader* gUnkEu_09F5D4CC = &gUnk_08C6A94E;

void* gUnkEu_09F5D4D0 = gUnk_08C6AA58;

AnimHeader* gUnkEu_09F5D4D4 = &gUnk_08C6AA74;

void* gUnkEu_09F5D4D8 = gUnkEu_08C9C97C;

void* gUnkEu_09F5D4DC = gUnkEu_08C9C99E;

void* gUnkEu_09F5D4E0 = gUnkEu_08C9C9C0;

void* gUnkEu_09F5D4E4 = gUnkEu_08C9C9E2;

void* gUnkEu_09F5D4E8 = gUnkEu_08C9CA04;

AnimHeader* gUnkEu_09F5D4EC = &gUnkEu_08C9CA26;

AnimHeader* gUnkEu_09F5D4F0 = &gUnkEu_08C9CA30;

AnimHeader* gUnkEu_09F5D4F4 = &gUnkEu_08C9CA3A;

AnimHeader* gUnkEu_09F5D4F8 = &gUnkEu_08C9CA44;

AnimHeader* gUnkEu_09F5D4FC = &gUnkEu_08C9CA4E;

#endif
