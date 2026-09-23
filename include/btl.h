#include "task_descriptors.h"
#include "battle_localized_data.h"
#ifndef GUARD_BTL_H
#define GUARD_BTL_H


#include "card_api.h"

#include "card_battle.h"

#include "btl_tasks.h"

#include "player_progression.h"

#include "m4a_song.h"
#include <string.h>
#include "fade.h"
#include "btl_effect.h"
#include "btl_collision.h"
#include "obj_api.h"
#include "battle_actor.h"
#include "display.h"
#include "types.h"
#include "engine_math.h"
#include "listpool.h"
#include "battle_work.h"
#include "game_state.h"
#include "anim.h"
#include "taskpool.h"
#include "obj.h"
#include "fld_types.h"
#include "btl_api.h"

typedef struct BtlSpawnArgs {
    u32 unk_00 : 16;
    u32 unk_02 : 8;
    u32 unk_03 : 8;
} BtlSpawnArgs;

typedef struct BtlTaskArgs {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x6];
    s16 unk_12;
    u16 unk_14;
    u16 unk_16;
    void* unk_18;
    u16 unk_1C;
    u8 unk_1E[0x2];
} BtlTaskArgs;

typedef struct BtlDrawInfo {
    s32 x;
    s32 y;
    s32 z;
    u16 unk_0C;
    u8 unk_0E[0x2];
    AnimState anim;
    void* unk_28;
    s32 unk_2C;
} BtlDrawInfo;

typedef struct BtlLockonWork {
    void* tiles;
    void* palette;
    AnimState anim;
    void* gfx;
    s16 unk_024;
    u8 unk_026[0x02];
} BtlLockonWork;

typedef struct BtlAreaWork {
    void* palette;
    void* tiles;
    u8 unk_008;
    u8 unk_009;
    s16 timer;
} BtlAreaWork;

typedef struct SoraAttackDef {
    s32 animId;
    const s32* attackIds;
    u16 swingSound;
    u16 hitSound;
    s32 unk_0C;
    u16 flags;
    u16 unk_12;
    const struct SoraAttackDef* next;
} SoraAttackDef;

typedef struct RikuAttackDef {
    s32 animId;
    s16 hitFrame;
    u16 unk_06;
    const s32* attackIds;
    u16 unk_0C;
    u16 unk_0E;
    s32 unk_10;
    u16 flags;
    u16 unk_16;
    const struct RikuAttackDef* next;
} RikuAttackDef;

typedef struct BtlSoraWork {
    void* tiles;
    ObjPalette* palette;
    u32 gfx;
    AnimState anim;
    TaskPool tasks;
    u32 unk_038;
    u32 unk_03C;
    BtlObj actor;
    s32 unk_150;
    u16 unk_154;
    u16 unk_156;
    u16 unk_158;
    u16 unk_15A;
    s32 unk_15C;
    u8 angle;
    u8 unk_161;
    u8 unk_162[0x2];
    const void* unk_164;
    const void* unk_168;
    const void* unk_16C;
    u8 unk_170[0x2];
    u8 unk_172;
    u8 unk_173;
    u16 unk_174;
    u8 unk_176[0x2];
    u16 unk_178;
    u8 unk_17A[0xA];
    const u16* unk_184;
    u32 task;
    u8 unk_18C[0x4];
    u8 unk_190;
    u8 unk_191[0xB];
    s32 unk_19C;
    s32 unk_1A0;
    u8 unk_1A4[0x4];
    u16 unk_1A8;
    u8 unk_1AA[0x2];
} BtlSoraWork;

typedef struct BtlRikuWork {
    void* tiles2;
    void* tiles;
    ObjPalette* palette;
    u32 gfx;
    AnimState anim;
    TaskPool tasks;
    u32 unk_03C;
    u32 unk_040;
    BtlObj actor;
    s32 unk_154;
    u16 unk_158;
    u16 unk_15A;
    u16 unk_15C;
    u16 unk_15E;
    s32 unk_160;
    u8 unk_164;
    u8 unk_165;
    u8 unk_166[0x2];
    const void* unk_168;
    const void* unk_16C;
    const void* unk_170;
    u8 unk_174[0x4];
    u8 unk_178;
    u8 unk_179;
    u16 unk_17A;
    u8 unk_17C[0x2];
    u16 unk_17E;
    u8 unk_180[0x8];
    const u16* unk_188;
    u32 unk_18C;
    u8 unk_190[0xC];
    s32 unk_19C;
    s32 unk_1A0;
    u8 unk_1A4[0x4];
    u16 unk_1A8;
    u8 unk_1AA[0x2];
    void* unk_1AC;
    u8 unk_1B0[0xC];
    s16 unk_1BC;
    u8 unk_1BE[0x2];
    BtlDrawInfo drawInfo[9];
    BtlObj* actor2;
} BtlRikuWork;

extern u8 gUnk_08F6DD04[];




extern u8 gUnk_08B1D8BC[];
extern u8 gUnk_08B1E974[];
extern u8 gUnk_08B1E97E[];
extern u8 gUnk_08B1E988[];
extern u8 gUnk_08B1E992[];
extern u8 gUnk_08B1E99C[];
extern u8 gUnk_08B1E9A6[];
extern u8 gUnk_08B1EA00[];
extern u8 gUnk_08C78824[];
extern u8 gUnk_08C7C824[];
extern u8 gUnk_08C80824[];
extern u8 gUnk_08C84824[];
extern u8 gUnk_08C88824[];
extern u8 gUnk_08C8C824[];
extern u8 gUnk_08C90824[];
extern u8 gUnk_08C94824[];
extern u8 gUnk_08C98824[];
extern u8 gUnk_08C9C6E4[];
extern u8 gUnk_08CA06E4[];
extern u8 gUnk_08CA46E4[];
extern u8 gUnk_08CA86E4[];
extern u8 gUnk_08CAC6E4[];
extern u8 gUnk_08CB06E4[];
extern u8 gUnk_08CB46E4[];
extern u8 gUnk_08CB86E4[];
extern u8 gUnk_08CBC6E4[];
extern u8 gUnk_08CC06E4[];
extern u8 gUnk_08EEF384[];
extern u8 gUnk_08EF0384[];
extern u8 gUnk_08EF1384[];
extern u8 gUnk_08EF2384[];
extern u8 gUnk_08EF3384[];
extern u8 gUnk_08EF4384[];
extern u8 gUnk_08EF5384[];
extern u8 gUnk_08EF6384[];
extern u8 gUnk_08EF7384[];
extern u8 gUnk_08EF8384[];
extern u8 gUnk_08EF9384[];
extern u8 gUnk_08EFA384[];
extern u8 gUnk_08EFB384[];
extern u8 gUnk_08EFC384[];
extern u8 gUnk_08EFD384[];
extern u8 gUnk_08EFE384[];
extern u8 gUnk_08EFF384[];
extern u8 gUnk_08F00384[];
extern u8 gUnk_08F01384[];
extern u8 gUnk_08F68624[];
extern u8 gUnk_08F686E4[];
extern u8 gUnk_08F687C4[];
extern u8 gUnk_08F68904[];
extern u8 gUnk_08F689C4[];
extern u8 gUnk_08F68A84[];
extern u8 gUnk_08F68B84[];
extern u8 gUnk_08F68C84[];
extern u8 gUnk_08F68D64[];
extern u8 gUnk_08F68EA4[];
extern u8 gUnk_08F68FC4[];
extern u8 gUnk_08F690A4[];
extern u8 gUnk_08F691E4[];
extern u8 gUnk_08F692C4[];
extern u8 gUnk_08F69404[];
extern u8 gUnk_08F694C4[];
extern u8 gUnk_08F69544[];
extern u8 gUnk_08F69604[];
extern u8 gUnk_08F69724[];
extern u8 gUnk_08F683A4[];
extern u8 gUnk_08F69BC4[];
extern u8 gUnk_096FAC64[];
extern u8 gUnk_09618118[];
extern u8 gUnk_08F69BA4[];
extern u32 gFrameCounter;


void func_0801DEB8(BtlSoraWork* work);
void func_0801DC5C(BtlSoraWork* work);
void func_080137C8(s32 x, s32 y, s32 z, u8 f);
void func_080161F8(s32 x, s32 y, s32 z, u8 f);
s32 func_080ABCA4(s32* out, s32 b);

typedef struct BtlMapWork {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} BtlMapWork;








typedef struct BtlTaskArg {
    s32 unk_00;
    u8 unk_04;
} BtlTaskArg;

#endif /* GUARD_BTL_H */
