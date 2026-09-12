#ifndef GUARD_BOS4_H
#define GUARD_BOS4_H

#include "map_types.h"

#include "card_api.h"

#include "map_api.h"
#include "msg_api.h"
#include "status_api.h"
#include "mode_test_api.h"

#include "save_api.h"

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
#include "malloc.h"
#include "engine_math.h"
#include "listpool.h"
#include "battle_work.h"
#include "game_state.h"
#include "anim.h"
#include "mode.h"
#include "key.h"
#include "taskpool.h"
#include "bos4_api.h"
#include "poo_api.h"
#include "btl_api.h"

typedef struct UnkStruct_080DEE18 {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u32 unk_04;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0A;
    u8 unk_0B;
    u8 unk_0C;
    u8 unk_0D[0x03];
} UnkStruct_080DEE18;

typedef struct UnkStruct_0203C590 {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    u8 unk_08[4][4];
    u8 unk_18[0x04];
    UnkStruct_080DEE18 unk_1C[32];
} UnkStruct_0203C590;

extern UnkStruct_0203C590 gUnk_0203C590;
extern u32 gUnk_09EF69FC[];

typedef struct UnkStruct_080DEDD8 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06[0x02];
} UnkStruct_080DEDD8;

typedef struct UnkStruct_0984C868 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8* unk_04;
    UnkStruct_080DEDD8* unk_08;
} UnkStruct_0984C868;

extern UnkStruct_0984C868 gUnk_0984C868[];
extern UnkStruct_0984C868 gUnk_0984CBD0[];

extern UnkStruct_080DEE18 gUnk_0203C5AC[];

UnkStruct_0984C868* func_080DED64(u8 a);
void func_080DEBD8(UnkStruct_080DEDD8* p);

typedef struct UnkStruct_096FE034Entry {
    u16 unk_00;
    u16 unk_02;
} UnkStruct_096FE034Entry;

typedef struct UnkStruct_096FE034 {
    UnkStruct_096FE034Entry* unk_00;
    u16 unk_04;
    u16 unk_06;
    void* unk_08;
    u16 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    u16 unk_12;
    s32 unk_14;
} UnkStruct_096FE034;

typedef struct UnkStruct_080DDDDC {
    u16 unk_00;
    u16 unk_02;
    u8 unk_04;
    u8 unk_05[0x03];
    UnkStruct_096FE034* unk_08;
} UnkStruct_080DDDDC;

extern UnkStruct_096FE034 gUnk_096FE034;
extern UnkStruct_096FE034 gUnk_096FE04C;
extern UnkStruct_096FE034 gUnk_096FE064;

typedef struct BoogieExplosiondiceWork {
    u32 unk_000;
    u16 unk_004;
    u8 unk_006[0x2];
    u32 tiles;
    u32 palette;
    u32 palette2;
    u32 anim;
    u8 unk_018[0x14];
    u32 unk_02C;
    u8 unk_030[0x10];
    u32 unk_040;
    u32 unk_044;
    u32 unk_048;
    u32 unk_04C;
    u8 unk_050[0x24];
    u32 unk_074;
    u8 unk_078[0x8];
    u32 unk_080;
    u8 unk_084[0xCC];
    u32 unk_150;
    u32 unk_154;
    u8 unk_158;
    u8 unk_159[0x3];
    u32 unk_15C;
} BoogieExplosiondiceWork;

typedef struct BoogieDiskWork {
    u32 unk_000;
    u16 unk_004;
    u8 unk_006[0x2];
    u32 tiles;
    u32 palette;
    u32 palette2;
    u32 anim;
    u8 unk_018[0x14];
    u32 unk_02C;
    u8 unk_030[0x10];
    u32 unk_040;
    u32 unk_044;
    u32 unk_048;
    u32 unk_04C;
    u8 unk_050[0x24];
    u64 unk_074;
    u8 unk_07C[0xD4];
    s32 unk_150;
    s32 unk_154;
    s32 unk_158;
    u8 unk_15C;
    u8 unk_15D[0x3];
} BoogieDiskWork;

typedef struct UrsulaWork {
    u32 unk_000;
    u16 unk_004;
    u8 unk_006[0x2];
    u32 unk_008;
    u8 unk_00C[0x10];
    u32 unk_01C;
    u32 unk_020;
    u32 unk_024;
    s32 unk_028;
    u32 unk_02C;
    u32 unk_030;
    u32 unk_034;
    u8 unk_038[0x18];
    s16 unk_050;
    s16 unk_052;
    u8 unk_054[0x4];
    u64 unk_058;
    u8 unk_060[0x4];
    u32 unk_064;
    u8 unk_068[0xCC];
    u32 unk_134;
    s32 unk_138;
    s32 unk_13C;
    u16 unk_140;
    u16 unk_142;
    u8 unk_144[0x4];
    u32 unk_148;
    u32 unk_14C;
    u32 unk_150;
    u32 unk_154;
    u16 unk_158;
    u16 unk_15A;
    u16 unk_15C;
    u16 unk_15E;
    u8 unk_160;
    u8 unk_161[0x3];
} UrsulaWork;

typedef struct UrsulaPrizeArg {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x14];
} UrsulaPrizeArg;

typedef struct BoogieMapanimeWork {
    UnkStruct_080DDDDC unk_000[3];
} BoogieMapanimeWork;

typedef struct UrsulaThunderWork {
    u16 unk_000;
    u8 unk_002[0x2];
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
} UrsulaThunderWork;

extern u16 gDispCnt;

void func_080DD69C(s32 a);

u8 func_080DD754(void);
u8 func_080DD794(void);
void func_080DDEC8(u8* p, u8 a);
typedef struct MapChkWork {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06[0x02];
} MapChkWork;

void Mode_MapChk_2(void);
u8 func_080DF500(void);
u8 func_080DF4D8(void);
u16 func_080DBE64(void);
u8 func_080DA4DC(u8* p);
u8 func_080DDE74(UnkStruct_080DDDDC* p);
void task_bos_boogie_explosiondice_3(BoogieExplosiondiceWork* work);
void task_bos_boogie_disk_3(BoogieDiskWork* work);
void task_bos_ursula_3(UrsulaWork* work);
void task_bos_boogie_mapanime_0(BoogieMapanimeWork* work);
void task_bos_ursula_thunder_0(UrsulaThunderWork* work);
u8 task_bos_ursula_thunder_1(UrsulaThunderWork* work);

typedef struct UnkStruct_0203C7AC {
    s32 unk_00;
    u8 unk_04[0x08];
    u8 unk_0C;
    u8 unk_0D;
    u8 unk_0E;
    u8 unk_0F;
    u8 unk_10;
    u8 unk_11[0x03];
} UnkStruct_0203C7AC;

extern UnkStruct_0203C7AC* gUnk_0203C7AC;

typedef struct UrsulaBubbleSingleWork {
    void* tiles;
    void* palette;
    void* palette2;
#ifndef VERSION_EU
    u32 anim;
    u8 unk_010[0x14];
#endif
    u32 unk_024;
    u32 unk_028;
    u32 unk_02C;
    u32 unk_030;
    u8 unk_034[0x100];
    u16 unk_134;
    u8 unk_136[0x2];
    u32 unk_138;
    u16 unk_13C;
    u16 unk_13E;
    s32 unk_140;
    u8 unk_144[0x4];
} UrsulaBubbleSingleWork;

void func_080DF964(void);
void func_080DEC00(void);
void task_bos_ursula_bubble_single_3(UrsulaBubbleSingleWork* work);

void func_080DF990(u8 a);

typedef struct BoogieKnifereaderWork {
    u32 unk_000;
    u16 unk_004;
    u8 unk_006[0x2];
    u32 unk_008;
    u8 unk_00C[0x10];
    u32 unk_01C;
    u8 unk_020[0x10C];
    void* unk_12C[5];
} BoogieKnifereaderWork;

typedef struct BoogieDiceWork {
    u32 unk_000;
    u16 unk_004;
    u8 unk_006[0x2];
    u32 tiles;
    u32 palette;
    u32 palette2;
    u32 anim;
    u8 unk_018[0x14];
    u32 unk_02C;
    u8 unk_030[0x10];
    u32 unk_040;
    u32 unk_044;
    u32 unk_048;
    u32 unk_04C;
    u8 unk_050[0x1C];
    u16 unk_06C;
    s16 unk_06E;
    u8 unk_070[0x04];
    u64 unk_074;
    u8 unk_07C[0x4];
    u32 unk_080;
    u8 unk_084[0xCC];
    s32 unk_150;
    s32 unk_154;
    u8 unk_158;
    u8 unk_159[0x3];
    s32 unk_15C;
    s32 unk_160;
    s32 unk_164;
    u8 unk_168;
    u8 unk_169[0x3];
    u32 unk_16C;
    u8 unk_170;
    u8 unk_171[0x3];
} BoogieDiceWork;

typedef struct UrsulaBubbleWork {
    u32 unk_000;
    u32 unk_004;
    u8 unk_008[0x10];
    void* unk_018[10];
    u16 unk_040;
    u8 unk_042[0x2];
#ifdef VERSION_EU
    AnimState unkEu_044;
#endif
} UrsulaBubbleWork;

typedef struct UrsulaTakoWork {
    void* tiles;
    void* palette;
    void* palette2;
    u32 anim;
    u8 unk_010[0x14];
    u16 unk_024;
    u8 unk_026[0x2];
    u32 unk_028;
    u32 unk_02C;
    u32 unk_030;
    u32 unk_034;
    u8 unk_038[0x24];
    u64 unk_05C;
    u8 unk_064[0xD4];
    u32 unk_138;
    u16 unk_13C;
    u8 unk_13E;
    u8 unk_13F[0x1];
    u32 unk_140;
    u32 unk_144;
    u8 unk_148[0x26];
    u16 unk_16E;
    u8 unk_170[0x2C];
    u32 unk_19C;
    u8 unk_1A0[0x58];
    s32 unk_1F8;
    s32 unk_1FC;
    s32 unk_200;
} UrsulaTakoWork;

extern u8 gUnk_0979D0B6[];
extern UnkStruct_096FE034 gUnk_096FE278;
extern UnkStruct_096FE034 gUnk_096FE290;
extern UnkStruct_096FE034 gUnk_096FE2A8;
extern const char gUnk_0984B74C[];
extern const char gUnk_0984B754[];
extern u8 gUnk_0984B0D8[];




extern UnkStruct_02034F7C gUnk_0984CECC[];
extern const u8 gUnk_09EF69EE[];


typedef struct UnkStruct_080DFB8C {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06[0x02];
    s32 unk_08;
    s32 unk_0C;
} UnkStruct_080DFB8C;

extern u16 gUnk_0203C560;

typedef struct UnkStruct_080DF640 {
    u16 unk_00;
    u16 unk_02;
} UnkStruct_080DF640;

extern const u8 gUnk_0984D0CC[][4];
extern vu32 gFrameCounter;

extern u8 gUnk_0203C578;
extern u8 gUnk_0203C56C;

typedef struct UnkStruct_080DAA28 {
    void* unk_00;
    u16 unk_04;
    u8 unk_06[0x2];
    void* unk_08;
    u16 unk_0C;
    u8 unk_0E[0x2];
    u8 unk_10[0x4];
} UnkStruct_080DAA28;

void task_bos_boogie_map_0(void* work, UnkStruct_080DAA28* arg);
extern s32 gUnk_0203C580;
extern u8 gUnk_0203C564;
extern u8 gUnk_0203C574;
extern u8 gUnk_096FE0E8[];
u8 func_080DABFC(s32* x, s32* y, s16 w, s16 h, s32 z);
void task_bos_boogie_dice_3(BoogieDiceWork* work);
extern u8 gUnk_0203C584;
extern const u8 gUnk_0984D134[][8];
extern u8 gUnk_09799CBA[];
extern u8 gUnk_0984AF78[];
extern u8 gUnk_09EF680C[];
extern u8 gUnk_09EF67FC[];
extern u8 gTaskDescBosUrsulaBubbleSingle[];
extern u8 gUnk_09EF5190[];
extern u8 gUnk_09EF5100[];
extern u8 gUnk_09EF5160[];
void func_080DB978(UrsulaWork* work);
extern u8 gUnk_09EF5130[];
void task_bos_ursula_2(UrsulaWork* work);
u16 func_080DD7C4(UrsulaBubbleWork* work);
u16 func_080DD854(UrsulaBubbleWork* work);
void task_bos_ursula_bubble_0(UrsulaBubbleWork* work);
u16 func_080DD8A8(UrsulaBubbleWork* work);
u8 func_080DF5F4(void);
u8 func_080DF49C(void);
u8 func_080DFC94(UnkStruct_080DFF1C* p, s32 x, s32 y);
u8 task_bos_boogie_mapanime_1(BoogieMapanimeWork* work);

u8 func_080DBA14(UrsulaWork* work);
u8 func_080DBC68(UrsulaWork* work);
void func_080DBC00(UrsulaWork* work);
s32 func_080DBCC0(UrsulaWork* work);
s32 func_080DBCEC(UrsulaWork* work);
s32 func_080DBDC0(UrsulaWork* work);
void func_080DBDEC(UrsulaWork* work);
void func_080DBE18(UrsulaWork* work);
void task_bos_ursula_tako_3(UrsulaTakoWork* work);
u8 func_080DD1FC(UrsulaTakoWork* work);
void func_080DD210(UrsulaTakoWork* work);
u8 func_080DD230(UrsulaTakoWork* work);
void func_080DD9B0(UrsulaBubbleWork* work);

typedef struct UrsulaMapanimeWork {
    UnkStruct_080DDDDC unk_000;
    u32 unk_00C;
    u32 unk_010;
    u8 unk_014[0x10];
    void* unk_024;
    u8 unk_028;
    u8 unk_029[0x3];
} UrsulaMapanimeWork;

typedef struct UrsulaMapWork {
    s32 unk_00;
    s32 unk_04;
    u16 unk_08;
    u8 unk_0A[0x2];
} UrsulaMapWork;

typedef struct UrsulaBorderWork {
    void* tiles;
    void* palette;
} UrsulaBorderWork;

void task_bos_ursula_map_0(UrsulaMapWork* work, UnkStruct_080DAA28* arg);
u8 task_bos_ursula_map_1(UrsulaMapWork* work);
extern u8 gUnk_0203C57C;

typedef struct BoogieSakuWork {
    u32 tiles;
    u32 palette;
    u32 anim;
    u8 unk_00C[0x14];
    u16 unk_020;
    u8 unk_022[0x2];
    u32 unk_024;
    u32 unk_028;
    u8 unk_02C[0x10];
    u32 unk_03C;
    u8 unk_040;
    u8 unk_041[0x3];
} BoogieSakuWork;

typedef struct BoogieKnifeWork {
    u32 unk_000;
    u16 unk_004;
    u8 unk_006[0x2];
    u32 tiles;
    u32 palette;
    u32 palette2;
    u32 anim;
    u8 unk_018[0x14];
    u32 unk_02C;
    u32 unk_030;
    u32 unk_034;
    u32 unk_038;
    u8 unk_03C[0x30];
    u32 unk_06C;
    u8 unk_070[0xBC];
    u8 unk_12C[0x10];
    s32 unk_13C;
    s32 unk_140;
    u8 unk_144[0x4];
    u32 unk_148;
    u32 unk_14C;
    s32 unk_150;
    s32 unk_154;
} BoogieKnifeWork;

typedef struct UrsulaBacktakoWork {
    u32 tiles;
    u32 palette;
    u32 anim;
    u32 unk_00C;
    u8 unk_010[0x4];
    u16 unk_014;
    u8 unk_016[0xA];
    u16 unk_020;
    u8 unk_022;
    u8 unk_023[0x1];
    u32 unk_024;
    u32 unk_028;
    u32 unk_02C;
    u32 unk_030;
    u32 unk_034;
    u32 unk_038;
    u32 unk_03C;
    u32 unk_040;
} UrsulaBacktakoWork;

typedef struct BoogieKaihukuWork {
    u32 unk_000;
    u16 unk_004;
    u8 unk_006[0x2];
    u32 tiles;
    u32 palette;
    u32 palette2;
    u32 anim;
    u8 unk_018[0x28];
    u32 unk_040;
    u32 unk_044;
    u32 unk_048;
    u32 unk_04C;
    u8 unk_050[0x24];
    u64 unk_074;
    u8 unk_07C[0xD4];
    u32 unk_150;
    u32 unk_154;
} BoogieKaihukuWork;

u8 func_080DEBAC(u8 a);
void func_080DEC44(void);

u16 func_080DDEA0(UnkStruct_080DDDDC* p);
u8 func_080DC510(void);
u8 func_080DC528(void);
u8 func_080DC544(void);
u8 func_080DC578(void);
u8 func_080DC5B0(void);
u32 func_080DC5E8(void);
u8 func_080DA73C(void);
u8 func_080DB428(u8* p);
u8 func_080DC628(void);
s32 func_080DCA78(u8 a);
void task_bos_ursula_border_0(UrsulaBorderWork* work);
void task_bos_ursula_border_3(UrsulaBorderWork* work);
u8 task_bos_ursula_backtako_1(UrsulaBacktakoWork* work);
void task_bos_ursula_backtako_3(UrsulaBacktakoWork* work);
void func_080DA954(BoogieSakuWork* work, s32 a, u16 b);
void task_bos_boogie_saku_0(BoogieSakuWork* work, void* arg);
void task_bos_boogie_saku_3(BoogieSakuWork* work);
void task_bos_boogie_knife_3(BoogieKnifeWork* work);
u8 func_080DB438(BoogieKnifereaderWork* work);
void task_bos_boogie_kaihuku_3(BoogieKaihukuWork* work);

void task_bos_boogie_knifereader_0(BoogieKnifereaderWork* work);
void task_bos_boogie_knifereader_2(BoogieKnifereaderWork* work);
void task_bos_boogie_knifereader_3(BoogieKnifereaderWork* work);
void task_bos_boogie_mapanime_2(void);
void task_bos_boogie_mapanime_3(void);
void task_bos_ursula_thunder_2(void);
void task_bos_ursula_thunder_3(void);
void task_bos_ursula_map_3(void);
s32 task_bos_ursula_border_1(void);
void func_080DDD30(UrsulaBubbleSingleWork* work);
u8 task_bos_ursula_bubble_1(UrsulaBubbleWork* work);
void task_bos_ursula_bubble_2(UrsulaBubbleWork* work);
void task_bos_ursula_bubble_3(UrsulaBubbleWork* work);

void task_bos_ursula_mapanime_0(UrsulaMapanimeWork* work);
u8 task_bos_ursula_mapanime_1(UrsulaMapanimeWork* work);
void task_bos_ursula_mapanime_2(UrsulaMapanimeWork* work);
void task_bos_ursula_mapanime_3(UrsulaMapanimeWork* work);

void task_bos_ursula_tako_2(UrsulaTakoWork* work);
void task_bos_ursula_tako_0(UrsulaTakoWork* work, u8* arg);
u8 task_bos_ursula_tako_1(UrsulaTakoWork* work);
extern u8 gUnk_096FE1A8[];
u8 task_bos_boogie_explosiondice_1(BoogieExplosiondiceWork* work);
void task_bos_boogie_kaihuku_2(BoogieKaihukuWork* work);

void func_080DB04C(BoogieKnifeWork* work);
void Mode_MapChk_1(void);
void func_080DDF04(u8 a, u8 b);
void func_080DE2A4(MapChkWork* p);
void Mode_MapChk_0(void);

extern const char gUnk_0984B72C[];
extern const char gUnk_0984B77C[];
extern const char gUnk_0984B7B0[];
extern const char gUnk_0984B7C0[];
extern const char gUnk_0984B7D0[];
extern const char gUnk_0984B7E0[];
extern const char gUnk_0984B7F0[];
extern const char gUnk_0984B800[];
extern const char gUnk_0984B810[];
extern const char gUnk_0984B820[];
void func_080DE5B0(MapChkWork* p);
void func_080DE62C(MapChkWork* p);
void func_080DE6A8(MapChkWork* p);
void func_080DE50C(MapChkWork* p);
void func_080DE534(MapChkWork* p);
void func_080DE3E8(MapChkWork* p);
void func_080DE4A4(MapChkWork* p);
extern const char* const gUnk_09EF6974[];

typedef struct UnkStruct_02034F18 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
} UnkStruct_02034F18;

extern UnkStruct_02034F18 gUnk_0203C7B0;
void func_080DE2FC(MapChkWork* p);
void func_080DE35C(MapChkWork* p);
extern const char* const gUnk_09EF6960[];
extern const char gUnk_0984B75C[];
extern const char gUnk_0984B76C[];
extern const char gUnk_0984B830[];
extern const char gUnk_0984B834[];
extern void (*const gUnk_09EF69A8[])(MapChkWork* p);
extern const u8 gUnk_0984B458[][8];
extern u8 gModeMapDbg[];
void func_080DF048(void);
u8 task_bos_ursula_bubble_single_1(UrsulaBubbleSingleWork* work);
extern s16 gSineTable[];
void task_bos_ursula_0(UrsulaWork* work);
extern u8 gTaskDescBosUrsulaMap[];
extern u8 gUnk_096FE14C[];
extern u8 gTaskDescBosUrsulaBorder[];
extern u8 gUnk_096FE13C[];
extern u8 gTaskDescBosUrsulaTako[];
extern u8 gTaskDescBosUrsulaMapanime[];
extern u8 gTaskDescBosUrsulaBacktako[];
extern u8 gUnk_096FE098[];
extern u8 gUnk_09EF6824[];
extern u8 gUnk_0979A426[];
extern u8 gUnk_09EF6844[];
u8 task_bos_boogie_saku_1(BoogieSakuWork* work);
extern u16 gUnk_0203C554;
extern u8 gTaskDescBosBoogieExplosiondice[];
void task_bos_boogie_dice_0(BoogieDiceWork* work, u8* arg);
u8 task_bos_boogie_dice_1(BoogieDiceWork* work);
u32 func_080D9A90(void);
u8 func_080D9AC4(s32* a, s32* b, s16 c, u16 d);
void func_080D9B6C(BoogieDiceWork* work);
extern u8 gUnk_0203C568;
extern u8 gUnk_09EF6788[];
extern u8 gUnk_09796EAA[];
extern u8 gUnk_09EF6798[];
u8 task_bos_boogie_kaihuku_1(BoogieKaihukuWork* work);
extern u8 gUnk_0203C570;
extern UnkStruct_096FE034 gUnk_096FE260;
extern u8 gTaskDescBosUrsulaBubble[];

void task_bos_boogie_knife_0(BoogieKnifeWork* work, u32* arg);
extern u8 gUnk_0979C44E[];
extern u8 gUnk_0984AFD8[];
extern u8 gUnk_09EF684C[];
extern u8 gUnk_09EF6848[];

extern BtlObj* gUnk_0203C55C;
void task_bos_boogie_disk_0(BoogieDiskWork* work, BtlObj* arg);
u8 task_bos_boogie_disk_1(BoogieDiskWork* work);
extern const u8 gUnk_09EF69E0[];
u8 task_bos_boogie_knifereader_1(BoogieKnifereaderWork* work);
u8 task_bos_boogie_knife_1(BoogieKnifeWork* work);
void task_bos_boogie_knife_2(BoogieKnifeWork* work);
void task_bos_boogie_explosiondice_0(BoogieExplosiondiceWork* work, void* arg);
extern u8 gUnk_09EF6774[];
extern u8 gUnk_0979666A[];
extern u8 gUnk_0984AF98[];
extern u8 gUnk_09EF6784[];
extern u8 gTaskDescBosShadow[];

typedef struct UnkStruct_096FDFC4 {
    u8 unk_00[0x06];
    u16 unk_06;
    u16 unk_08;
} UnkStruct_096FDFC4;

extern UnkStruct_096FDFC4 gUnk_096FDFC4;
extern UnkStruct_096FDFC4 gUnk_096FE0C0;
extern UnkStruct_096FDFC4 gUnk_096FDF54;
u8 task_bos_boogie_map_1(void);
extern u16 gWin0H;
extern u16 gWin0V;
extern u16 gWinIn;
extern u16 gWinOut;
void task_bos_boogie_dice_2(BoogieDiceWork* work);
u8 func_080D9B28(BoogieDiceWork* work);
void task_bos_ursula_backtako_0(UrsulaBacktakoWork* work, u8* arg);
extern u8 gUnk_09EF6860[];
extern u8 gUnk_0979E344[];
extern u8 gUnk_09EF68A0[];
void task_bos_ursula_bubble_single_0(UrsulaBubbleSingleWork* work, u8* arg);
extern u8 gUnk_096FE324[];
extern u8 gUnk_097A0DE4[];
extern u8 gUnk_0984B0F8[];
extern u8 gUnk_09EF68D8[];
extern u8 gUnk_09EF68C0[];
void task_bos_ursula_border_2(UrsulaBorderWork* work);
extern u8 gUnk_0979D090[];
extern u8 gUnk_0979D8B8[];
s32 strcmp(const char* a, const char* b);
extern const char gUnk_096FE2F4[];
extern u8 gTaskDescBosUrsulaThunder[];
extern UnkStruct_096FE034 gUnk_096FE2C0;
void func_080DA42C(BoogieDiceWork* work);
extern u8 gUnk_096FDF7C[];
extern u8 gUnk_0203C558;
void task_bos_boogie_kaihuku_0(BoogieKaihukuWork* work, BoogieDiceWork* arg);
extern u8 gUnk_096FE114[];
extern u8 gUnk_09799FB0[];
extern u8 gUnk_0984AFB8[];
extern u8 gUnk_08F69BC4[];
extern u8 gUnk_09EF6820[];
extern u8 gUnk_09EF681C[];
void func_080DB468(BoogieKnifereaderWork* work);
extern u8 gTaskDescBosBoogieKnife[];
void task_bos_ursula_backtako_2(UrsulaBacktakoWork* work);
void func_080DC9DC(s32* a, s32* b, s32* c, UrsulaTakoWork* d);
extern const u8 gUnk_0984B844[];
extern const u8 gUnk_0984B851[];
void task_bos_boogie_explosiondice_2(BoogieExplosiondiceWork* work);
void func_080DD248(s32* a, s32* b, s32* c, UrsulaBacktakoWork* d);
void task_bos_boogie_disk_2(BoogieDiskWork* work);
void func_080DF570(u8 a);
void task_bos_ursula_bubble_single_2(UrsulaBubbleSingleWork* work);

s32 func_080DBD44(UrsulaWork* work);
void func_080DF8C0(u8 a, u8 b);

#endif /* GUARD_BOS4_H */
