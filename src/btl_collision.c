#include "engine_math.h"
#include "listpool.h"
#include "battle.h"
#include "btl_collision.h"
#include "btl_effect.h"

const BattleAttackDef gUnk_0813400C[330] = {
    { 256, 204, 0, 3, func_080136E0, 0x80002000 },
    { 256, 204, 204, 3, func_080136E0, 0x80002000 },
    { 384, 384, 384, 16, func_080136E0, 0x80002000 },
    { 256, 1024, 384, 8, 0, 0x00003200 },
    { 384, 384, 0, 8, func_080136E0, 0x80002000 },
    { 384, 128, 256, 20, func_080136E0, 0x80002200 },
    { 384, 384, 512, 0, func_080136E0, 0x80002000 },
    { 384, 256, -768, 8, func_080136E0, 0x80002000 },
    { 512, 0, -256, 8, 0, 0x09002000 },
    { 1280, 256, 256, 8, func_080136E0, 0x09002000 },
    { 2048, 256, 256, 8, 0, 0x09004000 },
    { 768, 0, 0, 8, 0, 0x09204000 },
    { 256, 204, 0, 3, func_08013678, 0x80002000 },
    { 256, 204, 204, 3, func_08013678, 0x80002000 },
    { 384, 384, 384, 16, func_08013678, 0x80002000 },
    { 384, 204, 0, 3, func_08013678, 0x80002000 },
    { 384, 204, 204, 3, func_08013678, 0x80002000 },
    { 768, 384, 384, 16, func_08013678, 0x80002000 },
    { 512, 204, 0, 3, func_08013678, 0x80002000 },
    { 256, 204, 204, 3, func_08013678, 0x80002000 },
    { 768, 384, 384, 16, func_08013678, 0x80002000 },
    { 512, 204, 0, 3, func_08013678, 0x80002000 },
    { 256, 204, 204, 3, func_08013678, 0x80002000 },
    { 768, 384, 384, 16, func_08013678, 0x80002000 },
    { 384, 204, 0, 3, func_08013678, 0x80002000 },
    { 384, 204, 204, 3, func_08013678, 0x80002000 },
    { 896, 384, 384, 16, func_08013678, 0x80002000 },
    { 512, 204, 0, 3, func_08013678, 0x80002000 },
    { 512, 204, 204, 3, func_08013678, 0x80002000 },
    { 384, 384, 384, 16, func_08013678, 0x80002000 },
    { 512, 204, 0, 3, func_08013678, 0x80002000 },
    { 512, 204, 204, 3, func_08013678, 0x80002000 },
    { 512, 384, 384, 16, func_08013678, 0x80002000 },
    { 384, 204, 0, 3, func_08013678, 0x80002000 },
    { 384, 204, 204, 3, func_08013678, 0x80002000 },
    { 384, 384, 384, 16, func_08013678, 0x80002000 },
    { 256, 204, 0, 3, func_08013678, 0x40002000 },
    { 896, 204, 204, 3, func_08013678, 0x40002000 },
    { 384, 384, 384, 16, func_08013678, 0x40002000 },
    { 512, 204, 0, 3, func_08013678, 0x08002000 },
    { 512, 204, 204, 3, func_08013678, 0x08002000 },
    { 896, 384, 384, 16, func_08013678, 0x08002000 },
    { 640, 204, 0, 3, func_08013678, 0x10002000 },
    { 640, 204, 204, 3, func_08013678, 0x10002000 },
    { 768, 384, 384, 16, func_08013678, 0x10002000 },
    { 512, 204, 0, 3, func_08013678, 0x80002000 },
    { 512, 204, 204, 3, func_08013678, 0x80002000 },
    { 256, 384, 384, 16, func_08013678, 0x80002000 },
    { 896, 204, 0, 3, func_08013678, 0x80002000 },
    { 256, 204, 204, 3, func_08013678, 0x80002000 },
    { 512, 384, 384, 16, func_08013678, 0x80002000 },
    { 640, 204, 0, 3, func_08013678, 0x80002000 },
    { 1024, 204, 204, 3, func_08013678, 0x80002000 },
    { 896, 384, 384, 16, func_08013678, 0x80002000 },
    { 896, 204, 0, 3, func_08013678, 0x08002000 },
    { 896, 204, 204, 3, func_08013678, 0x08002000 },
    { 256, 384, 384, 16, func_08013678, 0x08002000 },
    { 1024, 204, 0, 3, func_08013678, 0x80002000 },
    { 1024, 204, 204, 3, func_08013678, 0x80002000 },
    { 1024, 384, 384, 16, func_08013678, 0x80002000 },
    { 768, 204, 0, 3, func_08013678, 0x20002000 },
    { 768, 204, 204, 3, func_08013678, 0x20002000 },
    { 768, 384, 384, 16, func_08013678, 0x20002000 },
    { 384, 204, 0, 3, func_08013678, 0x10002000 },
    { 384, 204, 204, 3, func_08013678, 0x10002000 },
    { 1536, 384, 384, 16, func_08013678, 0x10002000 },
    { 1280, 51, 51, 15, 0, 0x10004800 },
    { 2560, 76, 76, 15, 0, 0x10004800 },
    { 3840, 128, 128, 20, 0, 0x10004800 },
    { 1024, 0, 0, 15, 0, 0x20004000 },
    { 2048, 0, 0, 15, 0, 0x20004000 },
    { 3328, 0, 0, 20, 0, 0x20004000 },
    { 768, 256, 256, 15, 0, 0x40005000 },
    { 1280, 256, 256, 15, 0, 0x40005000 },
    { 2048, 256, 256, 15, 0, 0x40005000 },
    { 51, 0, 0, 0, 0, 0x00004400 },
    { 102, 0, 0, 0, 0, 0x00004400 },
    { 179, 0, 0, 0, 0, 0x00004400 },
    { 512, 0, 0, 15, 0, 0x00004900 },
    { 896, 0, 0, 15, 0, 0x00004100 },
    { 1536, 0, 0, 15, 0, 0x00004100 },
    { 768, -384, 384, 0, 0, 0x08005000 },
    { 1536, -384, 384, 0, 0, 0x08005000 },
    { 2304, -384, 384, 0, 0, 0x08005000 },
    { 512, 0, 256, 8, func_08013678, 0x09002000 },
    { 1536, 0, 256, 8, func_08013678, 0x09002000 },
    { 256, 0, 0, 8, func_08013678, 0x09002200 },
    { 6400, 384, 0, 0, 0, 0x08025000 },
    { 640, 76, 0, 2, func_08013560, 0x09002000 },
    { 768, 332, 384, 2, func_08013560, 0x09002000 },
    { 1280, -921, 384, 13, func_08013560, 0x09002000 },
    { 3328, 0, 0, 0, 0, 0x09004000 },
    { 256, 0, 0, 8, 0, 0x09004200 },
    { 512, 460, -768, 8, func_08013560, 0x09002000 },
    { 640, 332, 307, 3, func_08013678, 0x09002000 },
    { 256, 0, 0, 20, 0, 0x09002000 },
    { 5120, 384, 256, 20, 0, 0x10025000 },
    { 3072, 128, 128, 20, 0, 0x10004000 },
    { 0, 0, 0, 20, 0, 0x010C2000 },
    { 640, 204, 0, 0, 0, 0x20004000 },
    { 2048, 0, 0, 8, func_08013678, 0x01002100 },
    { 1280, 0, 0, 8, 0, 0x11002000 },
    { 1280, 0, 0, 8, 0, 0x21002000 },
    { 3072, 256, 256, 15, 0, 0x41003000 },
    { 179, 0, 0, 0, 0, 0x01003400 },
    { 1280, 0, 0, 4, func_08013678, 0x09002000 },
    { 2048, 0, 256, 8, 0, 0x09002000 },
    { 0, 844, 332, 8, 0, 0x09002000 },
    { 512, 0, 0, 0, 0, 0x01002100 },
    { 1024, 0, 0, 0, 0, 0x01002900 },
    { 0, 0, 0, 0, 0, 0x01102000 },
    { 640, 0, 384, 4, func_08013678, 0x01002800 },
    { 2048, 0, 844, 0, 0, 0x08024000 },
    { 3328, 256, 256, 4, 0, 0x08005200 },
    { 256, 256, 256, 8, 0, 0x00205000 },
    { 256, 0, 0, 8, 0, 0x00405000 },
    { 25, 0, 0, 0, 0, 0x08009000 },
    { 25, 0, 0, 0, 0, 0x08009200 },
    { 25, 0, 0, 0, 0, 0x08208800 },
    { 1152, 0, 256, 8, func_0801416C, 0x08011000 },
    { 1024, 384, 384, 3, func_0801416C, 0x08011000 },
    { 1024, 384, 384, 3, func_0801416C, 0x08011200 },
    { 768, 512, 384, 3, func_0801416C, 0x08011000 },
    { 1536, 51, 51, 15, 0, 0x10011800 },
    { 3072, 76, 76, 15, 0, 0x10011800 },
    { 4608, 128, 128, 20, 0, 0x10011800 },
    { 1280, 0, 0, 15, 0, 0x20011000 },
    { 2560, 0, 0, 15, 0, 0x20011000 },
    { 3840, 0, 0, 20, 0, 0x20011000 },
    { 1024, 256, 256, 15, 0, 0x40011000 },
    { 2048, 256, 256, 15, 0, 0x40011000 },
    { 3072, 256, 256, 15, 0, 0x40011000 },
    { 1280, 256, 256, 0, 0, 0x10011000 },
    { 1536, 51, 51, 15, 0, 0x10011800 },
    { 3072, 76, 76, 15, 0, 0x10011800 },
    { 4608, 128, 128, 20, 0, 0x10011800 },
    { 1280, 0, 0, 15, 0, 0x20011000 },
    { 2560, 0, 0, 15, 0, 0x20011000 },
    { 3840, 0, 0, 20, 0, 0x20011000 },
    { 1024, 256, 256, 15, 0, 0x40011000 },
    { 2048, 256, 256, 15, 0, 0x40011000 },
    { 3072, 256, 256, 15, 0, 0x40011000 },
    { 25, 0, 0, 0, 0, 0x00009400 },
    { 76, 0, 0, 0, 0, 0x00009400 },
    { 230, 0, 0, 0, 0, 0x00009400 },
    { 2048, 256, 256, 8, 0, 0x80011000 },
    { 1536, 256, 256, 8, 0, 0x40009000 },
    { 1280, 0, 0, 8, 0, 0x00009900 },
    { 102, 0, 0, 0, 0, 0x00009400 },
    { 512, 384, 256, 8, func_0801416C, 0x08011000 },
    { 256, 0, 0, 4, func_0801416C, 0x08011000 },
    { 1280, 0, 256, 30, func_0801416C, 0x08008000 },
    { 2560, 486, 384, 30, func_0801416C, 0x08008000 },
    { 768, 0, 0, 30, 0, 0x08008000 },
    { 768, 0, 0, 30, 0, 0x08008200 },
    { 1280, 0, 0, 30, 0, 0x08008200 },
    { 384, 204, 0, 0, 0, 0x20008000 },
    { 384, 51, 51, 0, 0, 0x10008800 },
    { 512, 76, 76, 0, 0, 0x10008800 },
    { 384, 128, 128, 0, 0, 0x10008800 },
    { 512, 460, 460, 3, func_0801416C, 0x08011000 },
    { 768, 460, 460, 3, func_0801416C, 0x08011000 },
    { 1024, 0, 0, 0, func_0801416C, 0x08010400 },
    { 1024, 0, 0, 0, func_0801416C, 0x08010000 },
    { 1536, 0, 0, 0, 0, 0x00040000 },
    { 384, 256, 256, 8, func_08013854, 0x80002000 },
    { 512, 256, 256, 8, func_08013854, 0x80002000 },
    { 512, 76, 76, 8, func_08013854, 0x10004000 },
    { 640, 128, 128, 8, func_08013854, 0x10004000 },
    { 384, 0, 0, 8, func_08013854, 0x20004000 },
    { 512, 0, 0, 8, func_08013854, 0x20004000 },
    { 256, 256, 256, 8, func_08013854, 0x40004000 },
    { 384, 256, 256, 15, 0, 0x40005000 },
    { 256, 256, 256, 8, func_08013854, 0x00004000 },
    { 256, 256, 256, 8, func_08013854, 0x00004000 },
    { 384, 256, 256, 8, func_08013854, 0x80002000 },
    { 384, 256, 256, 8, func_08013854, 0x80002000 },
    { 512, 256, 256, 8, func_08013854, 0x00002000 },
    { 384, 256, 256, 8, func_08013854, 0x00004200 },
    { 384, 256, 256, 8, func_08013854, 0x80002000 },
    { 512, 256, 256, 8, func_08013854, 0x80002000 },
    { 384, 256, 256, 8, func_08013854, 0x80002000 },
    { 512, 256, 256, 8, func_08013854, 0x80002000 },
    { 384, 256, 256, 8, func_08013854, 0x08002000 },
    { 256, 256, 256, 8, func_08013854, 0x80002000 },
    { 384, 384, -256, 12, func_08013854, 0x80002000 },
    { 384, 128, 512, 12, func_08013854, 0x80002000 },
    { 179, 358, 179, 8, func_08013854, 0x80002000 },
    { 256, 256, 256, 8, func_08013854, 0x80002000 },
    { 640, 384, 384, 0, func_08013854, 0x10003000 },
    { 256, 128, 256, 8, func_08013854, 0x80002000 },
    { 192, 256, 256, 8, func_08013854, 0x00002000 },
    { 384, 256, 256, 15, func_08013854, 0x80002000 },
    { 256, 256, 256, 8, func_08013854, 0x80002000 },
    { 384, 256, 256, 8, func_08013854, 0x80002000 },
    { 204, 51, 512, 8, func_08013854, 0x80002000 },
    { 256, 256, 256, 8, func_08013854, 0x80002000 },
    { 320, 256, 256, 8, func_08013854, 0x80002000 },
    { 384, 256, 256, 8, func_08013854, 0x10002000 },
    { 153, 332, 0, 8, func_08013854, 0x80002000 },
    { 256, 409, 0, 15, func_08013854, 0x80002200 },
    { 384, 256, 512, 12, func_08013854, 0x80002000 },
    { 384, 256, -256, 12, func_08013854, 0x80002000 },
    { 384, 256, 256, 8, func_08013854, 0x80002000 },
    { 256, 256, 256, 8, func_08013854, 0x80002000 },
    { 76, 0, 0, 4, func_08013854, 0x80002000 },
    { 204, 0, 256, 8, func_08013854, 0x80002000 },
    { 640, 51, 51, 15, 0, 0x10004000 },
    { 512, 0, 0, 15, 0, 0x20004000 },
    { 256, 256, 256, 15, 0, 0x40005000 },
    { 332, 256, 256, 8, func_08013854, 0x80002000 },
    { 256, 256, 256, 8, func_08013854, 0x08002000 },
    { 256, 256, 256, 8, func_08013854, 0x80002000 },
    { 384, 0, 384, 8, func_08013854, 0x08002000 },
    { 307, 256, 256, 15, 0, 0x10004000 },
    { 64, 256, 256, 8, func_08013854, 0x80002000 },
    { 204, 256, 256, 8, func_08013854, 0x80002000 },
    { 256, 256, 256, 15, 0, 0x40005000 },
    { 153, 332, 204, 8, func_08013854, 0x80002000 },
    { 307, 256, 256, 8, 0, 0x10000000 },
    { 256, 256, 0, 8, func_08013854, 0x80002000 },
    { 384, 256, 281, 8, func_08013854, 0x80002000 },
    { 256, 307, 358, 8, func_08013854, 0x80002000 },
    { 256, 256, 256, 8, func_08013854, 0x00002000 },
    { 256, 256, 256, 12, func_08013854, 0x08002000 },
    { 256, 256, 256, 8, func_08013854, 0x08002000 },
    { 102, 256, 256, 8, func_08013854, 0x80002000 },
    { 102, 256, 256, 8, func_08013854, 0x80002000 },
    { 153, 256, 256, 8, func_08013854, 0x80002000 },
    { 256, 256, 256, 8, func_08013854, 0x08002000 },
    { 256, 256, 256, 8, func_08013854, 0x80002000 },
    { 512, 256, 256, 8, 0, 0x10002000 },
    { 256, 256, 256, 8, 0, 0x80002000 },
    { 384, 256, 256, 8, 0, 0x40002000 },
    { 384, 256, 256, 8, 0, 0x40002000 },
    { 256, 256, 256, 8, 0, 0x00002000 },
    { 384, 128, 128, 8, 0, 0x10002000 },
    { 512, 256, 0, 8, func_08013854, 0x80002000 },
    { 384, 0, 256, 8, 0, 0x08002000 },
    { 256, 0, 0, 8, func_08013854, 0x08002000 },
    { 384, 460, 435, 8, func_08013854, 0x80002000 },
    { 256, 256, 256, 8, func_08013854, 0x80002000 },
    { 384, 256, 256, 8, func_08013854, 0x20202000 },
    { 768, 256, 256, 8, 0, 0x40002000 },
    { 384, 256, 256, 8, 0, 0x40002000 },
    { 256, 256, 256, 8, func_08013854, 0x00002000 },
    { 384, 256, 256, 8, func_08013854, 0x80002000 },
    { 384, 256, 256, 8, func_08013854, 0x08002000 },
    { 512, 256, 256, 8, func_08013854, 0x80002000 },
    { 256, 256, 256, 8, func_08013854, 0x00002000 },
    { 256, 256, 256, 8, func_08013854, 0x00002000 },
    { 256, 256, 256, 8, func_08013854, 0x80002000 },
    { 153, 256, 256, 8, func_08013854, 0x08002000 },
    { 332, 256, 256, 8, 0, 0x10002000 },
    { 384, 819, 435, 0, func_08013854, 0x00802000 },
    { 256, 256, 256, 8, func_08013854, 0x00002000 },
    { 256, 256, 256, 8, func_08013854, 0x08002000 },
    { 256, 256, 256, 8, func_08013854, 0x08002000 },
    { 256, 256, 256, 8, func_08013854, 0x08002000 },
    { 256, 256, 256, 8, func_08013854, 0x08002000 },
    { 256, 256, 256, 8, func_08013854, 0x08002000 },
    { 512, 256, 256, 8, func_08013854, 0x80002000 },
    { 512, 0, 0, 8, func_08013854, 0x80002000 },
    { 256, 256, 256, 8, func_08013854, 0x00002000 },
    { 256, 256, 256, 8, func_08013854, 0x00002000 },
    { 256, 256, 256, 8, func_08013854, 0x00002000 },
    { 384, 256, 256, 8, func_08013854, 0x08002000 },
    { 332, 256, 256, 8, func_08013854, 0x08002000 },
    { 384, 256, 256, 8, func_08013854, 0x08002000 },
    { 384, 256, 256, 8, func_08013854, 0x08002000 },
    { 384, 256, 256, 8, func_08013854, 0x08002000 },
    { 256, 256, 256, 8, func_08013854, 0x00002000 },
    { 256, 256, 256, 8, func_08013854, 0x00002000 },
    { 256, 256, 256, 8, func_08013854, 0x00002000 },
    { 256, 256, 256, 8, func_08013854, 0x00002000 },
    { 256, 256, 256, 8, func_08013854, 0x00002000 },
    { 256, 256, 256, 8, func_08013854, 0x00002000 },
    { 384, 256, 0, 8, func_08013854, 0x80002000 },
    { 384, 256, 384, 8, func_08013854, 0x80002000 },
    { 768, 384, 384, 8, 0, 0x10003000 },
    { 76, 0, 256, 0, func_08013854, 0x80002000 },
    { 512, 0, 1152, 15, func_08013854, 0x80002000 },
    { 256, 256, 256, 8, func_08013854, 0x80002000 },
    { 384, 256, 256, 30, func_08013854, 0x80002000 },
    { 512, 256, 256, 30, func_08013854, 0x80002000 },
    { 512, 256, 256, 30, func_08013854, 0x08002000 },
    { 204, 563, 256, 8, func_080138BC, 0x10002000 },
    { 332, 640, 0, 8, func_080138BC, 0x10002000 },
    { 460, 256, 256, 8, func_080138BC, 0x10002000 },
    { 76, 256, 256, 8, func_080138BC, 0x10002000 },
    { 256, 460, 0, 8, func_080136E0, 0x80002000 },
    { 384, 128, 256, 20, func_080136E0, 0x80002200 },
    { 256, 640, 256, 8, func_080136E0, 0x80002000 },
    { 256, 256, 0, 8, func_080136E0, 0x80002000 },
    { 512, 0, -256, 8, func_080136E0, 0x80002000 },
    { 512, 256, 256, 8, func_080136E0, 0x08002000 },
    { 768, 256, 256, 8, 0, 0x08004000 },
    { 512, 0, 0, 8, 0, 0x08204000 },
    { 256, 256, 256, 8, func_08013854, 0x80002000 },
    { 256, 256, 256, 8, func_08013854, 0x80002000 },
    { 256, 256, 256, 0, func_080138BC, 0x80002000 },
    { 256, 128, 256, 0, func_080138BC, 0x80002000 },
    { 256, 256, 256, 3, func_080138BC, 0x80003000 },
    { 512, 256, 256, 8, 0, 0x10004000 },
    { 768, 0, 128, 8, func_080138BC, 0x10002000 },
    { 102, 384, 128, 8, func_08013994, 0x80002000 },
    { 102, 128, 384, 8, func_08013994, 0x80002000 },
    { 102, 102, 0, 8, 0, 0x80002000 },
    { 256, 256, 256, 8, 0, 0x40002000 },
    { 204, 256, 256, 8, 0, 0x40004000 },
    { 128, 0, 256, 0, 0, 0x40004200 },
    { 256, 256, 256, 8, 0, 0x40004000 },
    { 204, 256, 256, 8, func_0801392C, 0x80002000 },
    { 256, 0, 0, 8, 0, 0x20004000 },
    { 384, 0, 0, 8, func_0801392C, 0x20004000 },
    { 128, 256, 256, 8, func_08013854, 0x08002000 },
    { 384, 256, 256, 8, 0, 0x08002000 },
    { 204, 256, 256, 8, 0, 0x08003000 },
    { 128, 0, 0, 8, 0, 0x08005000 },
    { 512, 0, 0, 0, 0, 0x08003000 },
    { 128, 256, 256, 8, func_08013854, 0x00002000 },
    { 256, 89, 512, 8, func_08013854, 0x08002000 },
    { 128, 0, 0, 8, 0, 0x08004000 },
    { 256, 460, 332, 8, func_08013854, 0x00002000 },
    { 384, 0, 0, 12, func_08013854, 0x80002000 },
    { 384, 307, 256, 12, func_08013854, 0x80002000 },
    { 384, 256, 256, 8, func_08013854, 0x80002000 },
    { 256, 256, 256, 8, func_08013854, 0x00002000 },
    { 256, 179, 179, 3, func_08013854, 0x08002000 },
    { 384, 307, 256, 12, func_08013854, 0x80002200 },
};


ListPool gUnk_020348E8;
ListPool gUnk_020348F8;
ListPool gUnk_02034908;
ListPool gUnk_02034918;

u8 func_08011270(BtlObj* p, s32 x, s32 y, s32 z, s16 a, s16 b, s16 c) {
    BtlObj* q = p->unk_0D8;
    u64 f;

    if (q != 0) {
        f = q->unk_034 | p->unk_034;
    } else {
        f = p->unk_034;
        q = p;
    }

    if (f & 0x01000180) {
        return 0;
    }
    if (x - (a << 8) > p->x + (p->unk_09E << 8)) {
        return 0;
    }
    if (x + (a << 8) < p->x - (p->unk_09E << 8)) {
        return 0;
    }
    if (y - (b << 8) > p->y + (p->unk_0A0 << 8)) {
        return 0;
    }
    if (y + (b << 8) < p->y - (p->unk_0A0 << 8)) {
        return 0;
    }
    if (z - (c << 8) > p->z) {
        return 0;
    }
    if (z + (c << 8) < p->z - (p->unk_09C << 8)) {
        return 0;
    }
    if (q->unk_0E2 > 0) {
        return 0;
    }
    return 1;
}

void func_08011364(BtlObj* a, BtlObj* b, const BattleAttackDef* c) {
    gBtlWork->unk_076 = 8;
    a->unk_020 = -((b->unk_030 * c->unk_00) >> 8);
    a->unk_034 |= 0x20;
}

s32 func_08011398(BtlObj* hit, s32 index) {
    const BattleAttackDef* attack = &gUnk_0813400C[index];
    s32 scale = gBtlWork->unk_124;
    BtlObj* target;
    BtlObj* source;
    if (hit->unk_0D8 != 0) {
        target = hit->unk_0D8;
    } else {
        target = hit;
    }
    target->unk_024 = attack->flags;
    target->unk_028 = index;
    if (attack->flags & 0x40000) {
        if (hit->unk_034 & 0x8000000000ULL) {
            func_08019190(hit, 0);
            hit->unk_0E2 = 30;
            return 2;
        }
        if (attack->flags & 0x80000) target->unk_0B4 = 0;
        target->unk_034 |= 0x40;
        return 0;
    }
    if (gBtlWork->unk_068 & 0x4000) {
        if (gBtlWork->unk_068 & 0x20000000) source = gBtlWork->actor;
        else source = gUnk_02039B9C->actor;
    } else if (gBtlWork->unk_068 & 0x800) {
        if (gBtlWork->unk_068 & 0x20000000) source = gBtlWork->actor;
        else source = gBtlWork->actor3;
    } else {
        if (gBtlWork->unk_068 & 0x20000000) source = gBtlWork->actor;
        else source = gBtlWork->actor3;
    }
    if (source->btl != 0) {
        switch (source->btl->unk_0F4) {
        case 35:
            if ((attack->flags & 0x01002000) != 0x2000) break;
            if (hit->unk_034 & 0x100000000ULL) break;
            if ((attack->flags & 0x80000000) && (hit->unk_034 & 0x8000)) break;
            if ((attack->flags & 0x08000000) && (hit->unk_034 & 0x0200000000000000ULL)) break;
            if ((attack->flags & 0x10000000) && (hit->unk_034 & 0x4000000)) break;
            if ((attack->flags & 0x20000000) && (hit->unk_034 & 0x8000000)) break;
            if ((attack->flags & 0x40000000) && (hit->unk_034 & 0x10000000)) break;
            if (hit->unk_0E8 == 2) break;
            {
                s16 drain = target->unk_02C >> 3;
                if (drain <= 0) drain = 1;
                else if (drain > 20) drain = 20;
                source->unk_02C += drain;
                target->unk_02C -= drain;
                if (target->unk_02C <= 0) target->unk_02C = 1;
                if (source->unk_02C > source->unk_02E) source->unk_02C = source->unk_02E;
                func_08019190(source, 10);
                target->unk_0B4 -= target->unk_0B4 >> 2;
            }
            break;
        case 43:
            if ((attack->flags & 0x01002000) == 0x2000) {
                scale = scale != 0 ? (scale * 384) >> 8 : 384;
            }
            break;
        case 8:
            if ((attack->flags & 0x01002000) == 0x2000 && source->unk_02C < (source->unk_02E >> 2)) {
                scale = scale != 0 ? (scale * 512) >> 8 : 512;
            }
            break;
        case 4:
            if (attack->flags & 0x10000000) {
                scale = scale != 0 ? (scale * 384) >> 8 : 384;
            }
            break;
        case 11:
            if (attack->flags & 0x20000000) {
                scale = scale != 0 ? (scale * 384) >> 8 : 384;
            }
            break;
        case 12:
            if (attack->flags & 0x40000000) {
                scale = scale != 0 ? (scale * 384) >> 8 : 384;
            }
            break;
        case 38:
            if (attack->flags & 0x4000) {
                scale = scale != 0 ? (scale * 332) >> 8 : 332;
            }
            break;
        case 39:
            if (attack->flags & 0x8000) {
                scale = scale != 0 ? (scale * 332) >> 8 : 332;
            }
            break;
        case 36:
            if ((attack->flags & 0x01002000) == 0x2000) {
                if (source->unk_034 & 4) {
                    if ((hit->unk_034 & 4) && hit->x < source->x) {
                        scale = scale != 0 ? (scale * 512) >> 8 : 512;
                    }
                } else if (!(hit->unk_034 & 4) && source->x < hit->x) {
                    scale = scale != 0 ? (scale * 512) >> 8 : 512;
                }
            }
            break;
        }
    }
    if (target->btl != 0) {
        switch (target->btl->unk_0F4) {
        case 14:
            if (attack->flags & 0x80000000) {
                func_08019190(hit, 0);
                scale = scale != 0 ? (scale * 128) >> 8 : 128;
            }
            break;
        case 46:
            target->btl->unk_0F8--;
#ifdef VERSION_EU
            if (attack->flags & 0x4000)
#endif
            {
                scale = scale != 0 ? (scale * 128) >> 8 : 128;
            }
            break;
        }
    }
    if (attack->flags & 0x80000000) {
        if (hit->unk_034 & 0x8000) {
            switch ((u32)hit->unk_000) {
            case 7:
            case 28:
            case 50:
            case 52:
                m4aSongNumStart(0x213);
                break;
            default:
                m4aSongNumStart(0x220);
                break;
            }
            hit->unk_0E2 = 30;
            func_08019190(hit, 0);
            func_080139FC(gBtlWork->x3, gBtlWork->y3, hit->z - hit->unk_0A2 * 256);
            return 2;
        } else if (hit->unk_034 & 0x0020000000000000ULL) {
            scale = scale != 0 ? (scale * 128) >> 8 : 128;
        } else if (hit->unk_034 & 0x0002000000000000ULL) {
            if (target->unk_034 & 0x0440000040000000ULL) {
                scale = scale != 0 ? (scale * 384) >> 8 : 384;
            } else {
                hit->unk_034 |= 0x4000;
            }
        }
    } else if (attack->flags & 0x08000000) {
        if (hit->unk_034 & 0x0200000000000000ULL) {
            switch ((u32)hit->unk_000) {
            case 7:
            case 28:
            case 50:
                m4aSongNumStart(0x213);
                break;
            default:
                m4aSongNumStart(0x220);
                break;
            }
            hit->unk_0E2 = 30;
            func_08019190(hit, 0);
            func_080139FC(gBtlWork->x3, gBtlWork->y3, hit->z - hit->unk_0A2 * 256);
            return 2;
        } else if (hit->unk_034 & 0x0100000000000000ULL) {
            scale = scale != 0 ? (scale * 128) >> 8 : 128;
        } else if (hit->unk_034 & 0x0080000000000000ULL) {
            if (target->unk_034 & 0x0440000040000000ULL) {
                scale = scale != 0 ? (scale * 384) >> 8 : 384;
            } else {
                hit->unk_034 |= 0x4000;
            }
        }
    } else if (attack->flags & 0x10000000) {
        if (hit->unk_034 & 0x100000) {
            func_08011364(target, source, attack);
            return 1;
        }
        if (hit->unk_034 & 0x4000000) {
            func_08019190(hit, 0);
            hit->unk_0E2 = 30;
            return 2;
        } else if (hit->unk_034 & 0x0004000000000000ULL) {
            scale = scale != 0 ? (scale * 128) >> 8 : 128;
        } else if (hit->unk_034 & 0x0000400000000000ULL) {
            if (target->unk_034 & 0x0040000040000000ULL) {
                scale = scale != 0 ? (scale * 384) >> 8 : 384;
            } else {
                hit->unk_034 |= 0x4000;
            }
        }
    } else if (attack->flags & 0x20000000) {
        if (hit->unk_034 & 0x200000) {
            func_08011364(target, source, attack);
            return 1;
        }
        if (hit->unk_034 & 0x8000000) {
            func_08019190(hit, 0);
            hit->unk_0E2 = 30;
            return 2;
        } else if (hit->unk_034 & 0x0008000000000000ULL) {
            scale = scale != 0 ? (scale * 128) >> 8 : 128;
        } else if (hit->unk_034 & 0x0000800000000000ULL) {
            if (target->unk_034 & 0x0040000040000000ULL) {
                scale = scale != 0 ? (scale * 384) >> 8 : 384;
            } else {
                hit->unk_034 |= 0x4000;
            }
        }
    } else if (attack->flags & 0x40000000) {
        if (hit->unk_034 & 0x400000) {
            func_08011364(target, source, attack);
            return 1;
        }
        if (hit->unk_034 & 0x10000000) {
            func_08019190(hit, 0);
            hit->unk_0E2 = 30;
            return 2;
        } else if (hit->unk_034 & 0x0010000000000000ULL) {
            scale = scale != 0 ? (scale * 128) >> 8 : 128;
        } else if (hit->unk_034 & 0x0001000000000000ULL) {
            if (target->unk_034 & 0x0040000040000000ULL) {
                scale = scale != 0 ? (scale * 384) >> 8 : 384;
            } else {
                hit->unk_034 |= 0x4000;
            }
        }
    } else if (attack->flags & 0x100) {
        if (hit->unk_034 & 0x80000000ULL) {
            func_08019190(hit, 0);
            hit->unk_0E2 = 30;
            return 2;
        }
        hit->unk_034 |= 0x800;
        if (scale == 0) hit->unk_020 = ((u32)attack->unk_00 * 15) >> 6;
        else hit->unk_020 = (((attack->unk_00 * 60) >> 8) * scale) >> 8;
        gBtlWork->unk_076 = (u8)attack->unk_0C;
        hit->unk_0E2 = 30;
        return 1;
    }
    if (hit->unk_034 & 0x100000000ULL) {
        func_08019190(hit, 0);
        hit->unk_0E2 = 30;
        gBtlWork->unk_072 = (u8)attack->unk_0C;
        return 1;
    }
    if (attack->flags & 0x200) {
        target->unk_034 |= 0x4000;
    } else if (attack->flags & 0x100000) {
        if (hit->unk_034 & 0x4000000000ULL) {
            func_08019190(hit, 0);
            hit->unk_0E2 = 30;
            return 2;
        }
        target->unk_034 |= 0x2000000000ULL;
    } else if (attack->flags & 0x200000) {
        if (hit->unk_034 & 0x20000000000ULL) {
            func_08019190(hit, 0);
            hit->unk_0E2 = 30;
            return 2;
        }
        target->unk_034 |= 0x10000000000ULL;
    } else if (attack->flags & 0x400000) {
        if (hit->unk_034 & 0x80000000000ULL) {
            func_08019190(hit, 0);
            hit->unk_0E2 = 30;
            return 2;
        }
        target->unk_034 |= 0x40000000000ULL;
    }
    if (attack->flags & 0x400) {
        if (hit->unk_034 & 0x200000000ULL) {
            func_08019190(hit, 0);
            hit->unk_0E2 = 30;
            return 2;
        }
        target->unk_034 |= 0x40000;
        if (attack->flags & 0x8000000) {
            if (scale == 0) target->unk_020 = (source->unk_030 * attack->unk_00) >> 8;
            else target->unk_020 = (((source->unk_030 * attack->unk_00) >> 8) * scale) >> 8;
        } else {
            if (scale == 0) target->unk_020 = (target->unk_02C * attack->unk_00) >> 8;
            else target->unk_020 = (((target->unk_02C * attack->unk_00) >> 8) * scale) >> 8;
            if (target->unk_034 & 0x0400000000000000ULL) {
                target->unk_020 = (target->unk_020 * 76) >> 8;
            }
        }
    } else {
        if (scale == 0) target->unk_020 = (source->unk_030 * attack->unk_00) >> 8;
        else target->unk_020 = (((source->unk_030 * attack->unk_00) >> 8) * scale) >> 8;
        if (target->unk_020 == 0 && attack->unk_00 > 0) target->unk_020 = 1;
    }
    if (target->btl != 0 && target->btl->unk_0F4 == 26) {
        if (target->unk_02C > 1 && target->unk_02C - target->unk_020 <= 0) {
            target->unk_020 = target->unk_02C - 1;
            target->unk_0E2 = 60;
            func_08019190(target, 0);
            target->btl->unk_0F8--;
        }
    }
    target->unk_034 |= 2;
    gBtlWork->unk_076 = (u8)attack->unk_0C;
    target->unk_0A8 = attack->unk_04;
    target->unk_0AC = attack->unk_08;
    if (attack->flags & 0x800000) {
        if (source->unk_034 & 4) target->unk_0B0 = 192;
        else target->unk_0B0 = 64;
    } else if (attack->flags & 0x1000) {
        target->unk_0B0 = GetAngle(gBtlWork->x3, gBtlWork->y3, target->x, target->y);
    } else {
        target->unk_0B0 = GetAngle(source->x, source->y, target->x, target->y);
    }
    return 1;
}
u8 func_08011E3C(s32 x, s32 y, s32 z, s16 a, s16 b, s16 c) {
    BtlObj* o;

    gBtlWork->unk_0B4 = 1;
    gBtlWork->x3 = x;
    gBtlWork->y3 = y;
    gBtlWork->unk_0C0 = z;
    gBtlWork->unk_0C4 = a;
    gBtlWork->unk_0C6 = b;
    gBtlWork->unk_0C8 = c;

    if (gBtlWork->unk_068 & 0x4000) {
        if (gBtlWork->unk_068 & 0x20000000) {
            o = gUnk_02039B9C->actor;
        } else {
            o = gBtlWork->actor;
        }
        if (func_08011270(o, x, y, z, a, b, c)) {
            return 1;
        }
    } else if (gBtlWork->unk_068 & 0x20000000) {
        o = ListPoolFirst(&gBtlWork->pool);

        while (o != 0) {
            if (func_08011270(o, x, y, z, a, b, c)) {
                return 1;
            }
            o = ListPoolNext(&o->node);
        }
        return 0;
    } else {
        o = gBtlWork->actor;
        if (func_08011270(o, x, y, z, a, b, c)) {
            return 1;
        }
    }
    return 0;
}

s32 func_08011F68(s32 a, BtlObj* b) {
    return func_08011398(b, a);
}

s32 func_08011F78(s32 a, s32 x, s32 y, s32 z, s16 p, s16 q, s16 r) {
    const BattleAttackDef* t;
    BtlObj* o;
    s32 sx;
    s32 sy;
    s32 sz;
    s16 cnt;
    s32 flag;
    s32 n;
    s32 res;
    s32 r2;

    t = &gUnk_0813400C[a];
    cnt = 0;
    flag = 0;
    gBtlWork->unk_0B4 = 1;
    gBtlWork->x3 = x;
    gBtlWork->y3 = y;
    gBtlWork->unk_0C0 = z;
    gBtlWork->unk_0C4 = p;
    gBtlWork->unk_0C6 = q;
    gBtlWork->unk_0C8 = r;

    if (gBtlWork->unk_068 & 0x4000) {
        if (gBtlWork->unk_068 & 0x20000000) {
            o = gUnk_02039B9C->actor;
        } else {
            o = gBtlWork->actor;
        }
        if (func_08011270(o, x, y, z, p, q, r)) {
            res = func_08011398(o, a);

            if (res == 1) {
                if (t->hitEffect != 0) {
                    t->hitEffect(o->x, o->y, o->z);
                }
            }
            return res;
        }
    } else if (gBtlWork->unk_068 & 0x20000000) {
        o = ListPoolFirst(&gBtlWork->pool);
        sz = 0;
        sy = 0;
        sx = 0;

        while (o != 0) {
            if (!func_08011270(o, x, y, z, p, q, r)) {
                o = ListPoolNext(&o->node);
                continue;
            }
            r2 = func_08011398(o, a);

            if (r2 == 1) {
                sx += o->x;
                sy += o->y;
                sz += o->z;
                cnt++;

                if (t->flags & 0x800) {
                    break;
                }
            } else if (r2 == 2) {
                flag = 1;
            }

            o = ListPoolNext(&o->node);
        }

        if (flag != 0) {
            return 2;
        }

        n = cnt;

        if (n > 0) {
            if (t->hitEffect != 0) {
                sx /= n;
                sy /= n;
                sz /= n;
                t->hitEffect(sx, sy, sz);
            }
            return 1;
        }
    } else {
        o = gBtlWork->actor;
        if (func_08011270(o, x, y, z, p, q, r)) {
            res = func_08011398(o, a);

            if (res == 1) {
                if (t->hitEffect != 0) {
                    t->hitEffect(o->x, o->y, o->z);
                }
            }
            return res;
        }
    }

    return 0;
}

s32 func_08012170(s32 a, s32 b, s32 c, s32 d) {
    return func_08011F78(a, b, c, d, 16, 16, 16);
}

s32 func_08012188(BtlObj* p, s16 h, s32 c) {
    if (p->unk_034 & 4) {
        return func_08012170(p->x - (h << 8), p->y, p->z - (p->unk_09C >> 1), c);
    } else {
        return func_08012170(p->x + (h << 8), p->y, p->z - (p->unk_09C >> 1), c);
    }
}

void func_080121D4(FldObj* p) {
    ListNodeInit(&p->node, &gUnk_02039BA0->actor.pool, p);
    ListPoolAppend(&p->node, &gUnk_02039BA0->actor.pool);
}

void func_080121FC(FldObj* p) {
    ListPoolRemove(&p->node, &gUnk_02039BA0->actor.pool);
}

void func_08012214(void) {
}

void* ColliderGetPool(u32 type) {
    switch (type) {
    case 1:
    case 2:
    case 4:
    case 9:
        return &gUnk_020348E8;
    case 3:
        return &gUnk_020348F8;
    case 5:
    case 7:
    case 8:
    case 10:
    case 11:
    case 12:
        return &gUnk_02034908;
    }
    return &gUnk_02034918;
}

void ColliderPoolsInit(void) {
    ListPoolInit(&gUnk_020348E8);
    ListPoolInit(&gUnk_020348F8);
    ListPoolInit(&gUnk_02034908);
    ListPoolInit(&gUnk_02034918);
}

void ColliderInit(Collider* p, u32 type, u16 r, u16 h) {
    void* pool;
    p->unk_34 = 0;
    p->unk_2C = 0;
    p->unk_2E = 0;
    p->unk_30 = 0;
    p->radius = r << 8;
    p->height = h << 8;
    p->type = type;
    p->self = p;
    p->unk_58 = 0;
    pool = ColliderGetPool(type);

    switch (type) {
    case 6:
    case 7:
        p->unk_30 |= 1;
        break;
    }
    ListNodeInit(&p->node, pool, p);
    ListPoolAppend(&p->node, pool);
}

void ColliderUnregister(Collider* p) {
    Collider* q = p->self;
    if (q == p) {
        ListPoolRemove(&q->node, ColliderGetPool(q->type));
    }
}

void ColliderSetPosition(Collider* p, s32 a, s32 b, s32 c) {
    p->x = a;
    p->y = b * 2;
    p->z = c;
}

void ColliderClearPoolContacts(ListPool* pool) {
    Collider* p = ListPoolFirst(pool);
    while (p != 0) {
        p->unk_2C = 0;
        p->unk_58 = 0;
        p->unk_2E = 0;
        p = ListPoolNext(&p->node);
    }
}

void ColliderCheckPoolPairs(ListPool* a, ListPool* b) {
    Collider* p;
    Collider* q;
    s32 sum;
    s32 dx;
    s32 dy;
    s32 pen;
    s32 dz;
    s32 t;
    u8 angle;

    p = ListPoolFirst(a);

    while (p != 0) {
        q = ListPoolLast(b);

        while (q != 0 && p != q) {
            sum = p->radius + q->radius;
            dx = p->x - q->x;

            if (dx < 0) {
                dx = q->x - p->x;
            }

            dy = p->y - q->y;

            if (dy < 0) {
                dy = q->y - p->y;
            }

            if (dx < sum && dy < sum) {
                pen = sum - Sqrt8(((dx * dx) >> 8) + ((dy * dy) >> 8));

                if (pen > 0) {
                    dz = p->z - q->z;

                    if (dz < p->height && -dz < q->height) {
                        q->unk_2C = 1;
                        p->unk_2C = 1;
                        p->unk_34 = q->type;
                        q->unk_34 = p->type;
                        p->unk_58 |= 1 << q->type;
                        q->unk_58 |= 1 << p->type;
                        angle = GetAngle(p->x, p->y, q->x, q->y);
                        t = (pen * gSineTable[angle]) >> 8;
                        p->unk_38 = -t;
                        p->unk_3C = -((pen * -gSineTable[angle + 64]) >> 8);
                        p->other = q;
                        q->unk_38 = t;
                        q->unk_3C = -p->unk_3C;
                        q->other = p;

                        if (q->unk_30 & 1) {
                            p->unk_40 = q->z - q->height;
                            p->unk_4C = pen;
                            p->unk_48 = q->y >> 1;
                            p->unk_44 = q->x;
                        }

                        if (p->unk_30 & 1) {
                            q->unk_40 = p->z - p->height;
                            q->unk_4C = pen;
                            q->unk_48 = p->y >> 1;
                            q->unk_44 = p->x;
                        }
                    } else {
                        if (q->unk_30 & 1) {
                            if (q->z - q->height >= p->z) {
                                p->unk_2E |= 1;

                                if (q->z - q->height == p->z) {
                                    q->unk_2E |= 2;
                                    p->unk_58 |= 1 << q->type;
                                    q->unk_58 |= 1 << p->type;
                                }

                                p->unk_40 = q->z - q->height;
                                p->unk_4C = pen;
                                p->unk_48 = q->y >> 1;
                                p->unk_44 = q->x;
                                p->other = q;
                                p->unk_34 = q->type;
                                q->unk_34 = p->type;
                            }
                        }

                        if (p->unk_30 & 1) {
                            if (p->z - p->height >= q->z) {
                                q->unk_2E |= 1;

                                if (p->z - p->height == q->z) {
                                    p->unk_2E |= 2;
                                    p->unk_58 |= 1 << q->type;
                                    q->unk_58 |= 1 << p->type;
                                }

                                q->unk_40 = p->z - p->height;
                                q->unk_4C = pen;
                                q->unk_48 = p->y >> 1;
                                q->unk_44 = p->x;
                                q->other = p;
                                p->unk_34 = q->type;
                                q->unk_34 = p->type;
                            }
                        }
                    }
                }
            }

            q = ListPoolPrev(&q->node);
        }

        p = ListPoolNext(&p->node);
    }
}

void ColliderUpdateAll(void) {
    ColliderClearPoolContacts(&gUnk_020348E8);
    ColliderClearPoolContacts(&gUnk_020348F8);
    ColliderClearPoolContacts(&gUnk_02034908);
    ColliderClearPoolContacts(&gUnk_02034918);
    ColliderCheckPoolPairs(&gUnk_020348E8, &gUnk_020348E8);
    ColliderCheckPoolPairs(&gUnk_020348F8, &gUnk_020348E8);
    ColliderCheckPoolPairs(&gUnk_02034908, &gUnk_020348E8);
    ColliderCheckPoolPairs(&gUnk_020348F8, &gUnk_020348F8);
    ColliderCheckPoolPairs(&gUnk_02034918, &gUnk_020348E8);
    ColliderCheckPoolPairs(&gUnk_02034918, &gUnk_020348F8);
}

void ColliderSetDisabled(Collider* p, u8 b) {
    if (b) {
        p->node.flags |= 2;
        p->unk_2C = 0;
        p->unk_2E = 0;
    } else {
        p->node.flags &= ~2;
    }
}

u8 ColliderIsColliding(Collider* p) {
    return p->unk_2C;
}

void ColliderSetRadius(Collider* p, u16 r) {
    p->radius = r << 8;
}

void ColliderSetHeight(Collider* p, u16 h) {
    p->height = h << 8;
}

u8 ColliderIsTouchingType(Collider* p, s32 bit) {
    if (p->unk_58 & (1 << bit)) {
        return 1;
    }
    return 0;
}
