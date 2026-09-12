#ifndef GUARD_SMN_H
#define GUARD_SMN_H

#include "eventselect_api.h"

#include "smn_tasks.h"

#include "display.h"
#include "m4a_song.h"
#include <stdlib.h>
#include "fade.h"
#include "btl_effect.h"
#include "btl_collision.h"
#include "obj_api.h"
#include "battle_actor.h"
#include "types.h"
#include "engine_math.h"
#include "listpool.h"
#include "battle_work.h"
#include "anim.h"
#include "taskpool.h"
#include "smn_api.h"
typedef struct SmnArgs {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
} SmnArgs;

typedef struct SmnCloudWork {
    void* tiles;
    void* palette;
    AnimState anim;
    TaskPool unk_020;
    s32 unk_034;
    BtlObj unk_038;
    s16 unk_148;
    s16 unk_14A;
    s32 unk_14C;
    s32 unk_150;
    s32 unk_154;
    u8 unk_158;
    u8 unk_159[0x03];
    s32 unk_15C;
    u16 unk_160;
    u8 unk_162;
    u8 unk_163;
    u8 unk_164;
    u8 unk_165[0x03];
    BtlObj* unk_168;
    u16 unk_16C;
    u8 unk_16E[0x02];
    s32 unk_170;
    s32 unk_174;
    s32 unk_178;
    u16 unk_17C;
    u8 unk_17E[0x02];
} SmnCloudWork;

typedef struct SmnBambiWork {
    void* tiles;
    void* palette;
    AnimState anim;
    TaskPool unk_020;
    u32 unk_034;
    BtlObj unk_038;
    s16 unk_148;
    s16 unk_14A;
    s16 unk_14C;
    u8 unk_14E[0x02];
    s32 unk_150;
    s32 unk_154;
    u8 unk_158;
    u8 unk_159[0x03];
    s32 unk_15C;
    u16 unk_160;
    u8 unk_162;
    u8 unk_163;
    u8 unk_164;
    u8 unk_165[0x03];
    struct BtlObj* unk_168;
    s16 unk_16C;
    u8 unk_16E[0x02];
    s32 unk_170;
    s32 unk_174;
} SmnBambiWork;

typedef struct SmnTinkWork {
    void* tiles;
    void* palette;
    AnimState anim;
    TaskPool unk_020;
    u32 unk_034;
    BtlObj unk_038;
    s16 unk_148;
    s16 unk_14A;
    s32 unk_14C;
    u16 unk_150;
    u8 unk_152;
    u8 unk_153;
    u8 unk_154;
    u8 unk_155[0x0B];
    s32 unk_160;
    u8 unk_164[0x04];
    s32 unk_168;
    u16 unk_16C;
    s16 unk_16E;
    s16 unk_170;
    u8 unk_172[0x02];
    s32 unk_174;
    s32 unk_178;
    struct BtlObj* unk_17C;
} SmnTinkWork;

typedef struct SmnTinkeffWork {
    void* tiles;
    void* palette;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    s32 unk_2C;
} SmnTinkeffWork;

typedef struct SmnSimbaWork {
    void* tiles;
    void* palette;
    AnimState anim;
    TaskPool unk_020;
    u32 unk_034;
    BtlObj unk_038;
    s16 unk_148;
    s16 unk_14A;
    s16 unk_14C;
    u8 unk_14E[0x02];
    s32 unk_150;
    u8 unk_154;
    u8 unk_155;
    u8 unk_156;
    u8 unk_157;
} SmnSimbaWork;

typedef struct SmnMushuWork {
    void* tiles;
    void* palette;
    AnimState anim;
    TaskPool unk_020;
    u32 unk_034;
    BtlObj unk_038;
    s16 unk_148;
    s16 unk_14A;
    s32 unk_14C;
    u16 unk_150;
    u8 unk_152;
    u8 unk_153;
    u8 unk_154;
    u8 unk_155[0x03];
    struct BtlObj* unk_158;
} SmnMushuWork;

typedef struct SmnDumboWork {
    void* tiles;
    void* palette;
    AnimState anim;
    TaskPool unk_020;
    u32 unk_034;
    BtlObj unk_038;
    s16 unk_148;
    s16 unk_14A;
    s16 unk_14C;
    u8 unk_14E[0x02];
    s32 unk_150;
    u8 unk_154;
    u8 unk_155;
    u8 unk_156;
    u8 unk_157;
} SmnDumboWork;

typedef struct SmnGenieWork {
    void* tiles;
    void* palette;
    AnimState anim;
    TaskPool unk_020;
    s32 unk_034;
    BtlObj unk_038;
    u16 unk_148;
    s16 unk_14A;
    s32 unk_14C;
    u8 unk_150;
    u8 unk_151;
    u8 unk_152;
    u8 unk_153;
    struct BtlObj* unk_154;
    s16 unk_158;
    s16 unk_15A;
    u8 unk_15C;
    u8 unk_15D[3];
    s32 unk_160;
    s32 unk_164;
} SmnGenieWork;

typedef struct SmnPrizeArgs {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x06];
    s16 unk_12;
    s16 unk_14;
    u8 unk_16[0x0A];
} SmnPrizeArgs;

typedef struct SmnFrdWork {
    u8 unk_000[0x20];
    BtlObj unk_020;
    u8 unk_130[0x24];
    s32 unk_154;
} SmnFrdWork;

typedef struct SmnKingWork {
    void* tiles;
    void* palette;
    AnimState anim;
    TaskPool unk_020;
    s32 unk_034;
    BtlObj unk_038;
    s16 unk_148;
    s16 unk_14A;
    u16 unk_14C;
    u8 unk_14E[0x06];
    s32 unk_154;
    u32 unk_158;
    u8 unk_15C;
    u8 unk_15D;
    u8 unk_15E;
    u8 unk_15F[0x09];
} SmnKingWork;


void func_0802F1E8(void);
void func_0802F284(s32 a, s32 b, s32 c);
extern u8 gTaskDescBtlShadow[];
extern u8 gTaskDescBtlPrize[];
extern u8 gTaskDescSmnTinkeff[];
extern u8 gUnk_096183F8[];
extern u8 gUnk_0813EB4C[];
extern u8 gUnk_08F6DC24[];
extern s16 gSineTable[];
extern u8 gUnk_088A5D7A[];
extern u8 gUnk_08F69BA4[];
extern u8 gUnk_09617FF8[];
extern u8 gUnk_09EDE7B4[];
extern u8 gUnk_09EDE7E4[];
extern u8 gUnk_09617F98[];
extern u8 gUnk_09618018[];
extern u8 gUnk_09618098[];
extern u8 gUnk_09618298[];
extern u8 gUnk_09618038[];
extern u8 gUnk_0813E958[];
extern u8 gUnk_0813E9E8[];
extern u8 gUnk_0813EA08[];
extern u8 gUnk_0813EA5C[];
extern u8 gUnk_0813EB1C[];
extern u8 gUnk_0813EA7C[];
extern u8 gUnk_0813EADC[];
BtlObj* func_08040D54(SmnCloudWork* work);
BtlObj* func_08040C8C(SmnCloudWork* work);
void func_08041D64(SmnBambiWork* work);
void func_08044518(SmnGenieWork* work);
u8 func_08041FCC(SmnBambiWork* work);
BtlObj* func_08042018(SmnBambiWork* work);
BtlObj* func_08044450(SmnGenieWork* work);
void func_080428E8(SmnTinkWork* work);
u8 func_08044F98(SmnKingWork* work);

#endif /* GUARD_SMN_H */
