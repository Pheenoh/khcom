#ifndef GUARD_BATTLE_H
#define GUARD_BATTLE_H

#include "field_state.h"

#include "fld_types.h"

#include "card_api.h"

#include "map_api.h"
#include "ms_api.h"
#include "msg_api.h"
#include "mode_chkbtl_api.h"

#include "eventselect_api.h"

#include "save_api.h"

#include "player_progression.h"

#include "card_deck.h"

#include "display.h"
#include "anim.h"
#include <string.h>
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
#include "game_state.h"
#include "m4a.h"
#include "gba/syscall.h"
#include "malloc.h"
#include "taskpool.h"
#include "obj.h"
#include "engine.h"
#include "key.h"
#include "util.h"
#include "mode.h"
#include "bos3.h"
#include "bos4_api.h"
struct BtlObj;

typedef struct BgFx {
    s32 unk_00;
    void (*unk_04)(void);
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    s16 unk_0E;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    u8 unk_24;
    u8 unk_25;
    u16 unk_26;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u16 unk_34;
    u16 unk_36;
    u8 unk_38;
    u8 unk_39[0x03];
    s32 unk_3C;
    s32 unk_40;
    struct BtlObj* unk_44;
    s32 unk_48;
    s16 unk_4C;
    u16 unk_4E;
} BgFx;

typedef struct EmyKind {
    u32 unk_00;
    u16 unk_04;
    s16 unk_06;
    s16 unk_08;
    u16 unk_0A;
    u16 unk_0C;
    u16 unk_0E;
} EmyKind;

typedef struct EnemySpawnRequest {
    TaskDesc* desc;
    s32 x;
    s32 y;
    s32 z;
    u16 unk_10;
    u16 unk_12;
} EnemySpawnRequest;

typedef struct UnkStruct_0801B8A8 {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x06];
    u16 unk_12;
    u16 unk_14;
    u8 unk_16[0x0A];
} UnkStruct_0801B8A8;

typedef struct UnkStruct_020348C8 {
    void* unk_00;
    void* unk_04;
    AnimState unk_08;
    u16 unk_20;
    u8 unk_22;
    u8 unk_23;
} UnkStruct_020348C8;

typedef struct HitData {
    u8 unk_00[0x2C];
    u16 unk_2C;
    s16 unk_2E;
    s16 unk_30;
    u8 unk_32[0x02];
} HitData;

typedef struct AnimDef {
    void* unk_00;
    s32 unk_04;
    void* unk_08;
    u8 unk_0C;
    u8 unk_0D[0x03];
} AnimDef;

typedef struct SprObj {
    void* unk_00;
    void* tiles;
    void* unk_08;
    void* palette;
    u8 anim[0x18];
    s32 x;
    s32 y;
    s32 z;
    u16 flags;
    u16 unk_36;
    void* gfx;
} SprObj;

typedef struct Actor {
    void* unk_00;
    void* tiles;
    ObjPalette* palette;
    SprObj* unk_0C;
    SprObj* unk_10;
    u8 unk_14[0x18];
    TaskPool unk_2C;
    s32 unk_40;
    s32 unk_44;
    u8 unk_48[0x2C];
    u64 unk_74;
    u8 unk_7C[0xD4];
    u16 unk_150;
    u16 unk_152;
    u32 unk_154;
    u8 unk_158[0x10];
    s32 unk_168;
    s32 unk_16C;
    s32 unk_170;
    u8 unk_174[0x04];
    void* unk_178;
    u16 unk_17C;
    u16 unk_17E;
    void* gfx;
    const u32* unk_184;
} Actor;

typedef struct UnkStruct_02039CA8 {
    u16 maxHp;
    u16 cp;
    u16 dp;
    u16 ap;
    u32 exp;
    s32 nextExp;
    u8 level;
    u8 unk_11[0x03];
    u64 unk_14[13];
    u32 unk_7C;
    u16 unk_80;
    u16 unk_82;
    u16 unk_84;
    u8 unk_86[0x02];
} UnkStruct_02039CA8;

typedef struct UnkStruct_08133E5C {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
} UnkStruct_08133E5C;

typedef struct UnkStruct_0813400C {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    void (*unk_10)(s32, s32, s32);
    u32 unk_14;
} UnkStruct_0813400C;


extern u32 gFrameCounter;
extern s32 gUnk_02039DC0;
extern u16 gUnk_09EDA4EC[];
extern TaskDesc gTaskDescBtlBorn;
extern TaskDesc gTaskDescEmy00;
extern TaskDesc gTaskDescEmy01;
extern TaskDesc gTaskDescEmy02;
extern TaskDesc gTaskDescEmy03;
extern TaskDesc gTaskDescEmy04;
extern TaskDesc gTaskDescEmy06;
extern TaskDesc gTaskDescEmy07;
extern TaskDesc gTaskDescEmy08;
extern TaskDesc gTaskDescEmy14;
extern TaskDesc gTaskDescEmy15;
extern TaskDesc gTaskDescEmy16;
extern TaskDesc gTaskDescEmy18;
extern TaskDesc gTaskDescEmy19;
extern TaskDesc gTaskDescEmy21;
extern TaskDesc gTaskDescEmy22;
extern TaskDesc gTaskDescEmy23;
extern TaskDesc gTaskDescEmy25;
extern TaskDesc gTaskDescEmy26;
extern TaskDesc gTaskDescEmy27;
extern TaskDesc gTaskDescEmy28;
extern TaskDesc gTaskDescEmy29;
extern TaskDesc gTaskDescEmy30;
extern TaskDesc gTaskDescEmy31;
extern TaskDesc gTaskDescEmy37;
extern TaskDesc gTaskDescEmy38;
extern TaskDesc gTaskDescEmy39;
extern TaskDesc gTaskDescEmy41;
extern TaskDesc gTaskDescEmy44;
extern TaskDesc gTaskDescEmy81;
extern TaskDesc gTaskDescEmy82;
extern TaskDesc gTaskDescEmy83;
extern TaskDesc gTaskDescEmyTrumpH;
extern TaskDesc gTaskDescEmyTrumpS;
extern u32 gUnk_03006C10;
extern const s16 gSineTable[];
extern const u8 gUnk_08133E54[];
extern u8 gUnk_08F6DA04[];
extern u8 gUnk_08F69BC4[];
extern u8 gUnk_09EDA5A0[];
extern u8 gUnk_09EDA5B8[];
extern u8 gUnk_09EDA600[];
extern u8 gUnk_09EDA648[];
extern u8 gUnk_09EDA780[];
extern u8 gUnk_09EDA7E0[];
extern u8 gUnk_09EDA810[];
extern u8 gUnk_09EDA888[];
extern u8 gUnk_09EDA900[];
extern u8 gUnk_09EDA948[];
extern u8 gUnk_09EDA960[];
extern u8 gUnk_09EDA978[];
extern u8 gUnk_09EDA990[];
extern u8 gUnk_09EDA9D8[];
extern u8 gUnk_09EDA9C0[];
extern u8 gUnk_09EDA9F0[];
extern u8 gUnk_09EDAA20[];
extern u8 gUnk_09EDAA50[];
extern u8 gUnk_09EDAA68[];
extern u8 gUnk_09EDAA98[];
extern u8 gUnk_09EDAAC8[];
extern u8 gUnk_09EDAAE0[];
extern u8 gUnk_09EDAB70[];
extern u8 gUnk_09EDAC78[];
extern u8 gUnk_09EDAC90[];
extern u8 gUnk_09EDACA8[];
extern u8 gTaskDescBtlPrize[];
extern u8 gTaskDescBtlPremire[];
extern u8 gTaskDescBtlPop[];
extern u8 gTaskDescBtlPopCb[];
extern u8 gUnk_09EDABD0[];
extern u8 gUnk_09EDABE8[];
extern u8 gUnk_09EDAD20[];
extern u8 gUnk_09EDAD50[];
extern u8 gUnk_09EDADB0[];
extern u8 gUnk_09EDAD80[];
extern u8 gUnk_09EDA8E8[];
extern u8 gUnk_09EDA930[];
extern u8 gUnk_09EDA630[];
extern u8 gUnk_09EDAD38[];
extern u8 gUnk_09EDA678[];
extern u8 gUnk_09EDAB88[];
extern u8 gUnk_09EDA5D0[];
extern u8 gUnk_09EDA5E8[];
extern u8 gUnk_09EDA618[];
extern u8 gUnk_09EDA720[];
extern u8 gUnk_09EDAA38[];
extern u8 gUnk_09EDA7F8[];
extern u8 gUnk_09EDA858[];
extern u8 gUnk_09EDA870[];
extern u8 gUnk_09EDACF0[];
extern u8 gUnk_09EDAD68[];
extern u8 gUnk_09EDA6C0[];
extern u8 gUnk_09EDA768[];
extern u8 gUnk_09EDAA80[];
extern u8 gUnk_09EDA6F0[];
extern u8 gUnk_09EDAC00[];
extern u8 gUnk_09EDAAB0[];
extern u8 gUnk_09EDACC0[];
extern u8 gUnk_09EDAD98[];
extern u8 gUnk_09EDAB28[];
extern u8 gUnk_09EDAB40[];
extern u8 gUnk_09EDAA08[];
extern u8 gUnk_09EDAC18[];
extern u8 gUnk_09EDA8A0[];
extern u8 gUnk_09EDA8B8[];
extern u8 gUnk_09EDA8D0[];
extern u8 gUnk_09EDA798[];
extern u8 gUnk_09EDA7B0[];
extern u8 gUnk_09EDA7C8[];
extern u8 gUnk_09EDA570[];
extern u8 gUnk_09EDAC60[];
extern u8 gUnk_09EDAB10[];
extern u8 gUnk_09EDA6D8[];
extern u8 gUnk_09EDA558[];
extern u8 gUnk_09EDA840[];
extern u8 gUnk_09EDA828[];
extern const UnkStruct_08133E5C gUnk_08133E5C[];
extern const UnkStruct_0813400C gUnk_0813400C[];

extern UnkStruct_02039CA8 gUnk_02039CA8;
extern UnkStruct_020348C8* gUnk_020348C8;
extern u16 gUnk_020348CC[2];
extern u16 gUnk_020348D0[2];
extern u16 gUnk_020348D4[2];
extern u16 gUnk_020348D8[2];
extern u16 gUnk_020348DC[2];
extern u16 gUnk_020348E0;
extern u16 gUnk_020348E2;
extern ListPool gUnk_020348E8;
extern ListPool gUnk_020348F8;
extern ListPool gUnk_02034908;
extern ListPool gUnk_02034918;
extern BgFx* gUnk_02034928;

void* ColliderGetPool(u32 type);
void func_08019350(void);
void func_080197AC(void);
void func_0801B024(BtlObj* p);
void func_0809B6D0(void* p, s16 x, s16 y, s16 z, u16 n);
void CreatePrizeCardTask(void* p, UnkStruct_0801B8A8* v);
void func_08012674(void);
void func_08012908(void);
void func_0801007C(void);
s32 func_08012170(s32 a, s32 b, s32 c, s32 d);
void func_08013420(void);
void func_08014850(void);
void func_08016A64(void);
void func_08014E38(void);
void func_08014F4C(void);
void func_08017EF4(void);
BtlObj* func_08016320(void);
void func_080192E0(void);
void func_08013D60(void);
void func_080166F8(void);
void func_08012BCC(void);
void func_08014000(void);
void func_08014BA8(void);
void func_0801519C(void);
void func_08015FF4(void);
void func_080152DC(void);
void func_08091234(u16 a);
void func_0801508C(void);
void func_0801848C(void);
void func_080185D0(void);
void func_0801884C(void);
void ColliderCheckPoolPairs(ListPool* a, ListPool* b);
s64 __ashldi3(s64 v, s32 n);
u8 func_080ABED0(void);

void func_0800EEBC(Actor* p, SprObj* s);
void func_0800F230(void);
u8 func_0800F440(Actor* p, s16 a, u16 b, u16 r);
void AdvanceLevelExpThreshold(UnkStruct_02039CA8* p);
void func_0801CA88(void);

const UnkStruct_08133E5C* func_0800FB14(u16 i);
s32 func_08011398(BtlObj* a, s32 b);

u8 func_08081870(void);
s32 func_0807E2BC(void);
u8 func_0807E33C(void);
u8 func_08081848(void);
void func_080838E8(void);
void func_080838EC(void);
extern TaskDesc gTaskDescBtlVslockon;
extern TaskDesc gTaskDescBtlHpoth;
extern TaskDesc gTaskDescCardBattleSora;
extern TaskDesc gTaskDescCardBattleRiku;
extern Mode gModeSioBtlCardget;
extern TaskDesc gTaskDescBtlExp;
extern Mode gModeContinue;
extern TaskDesc gTaskDescBtlStart;
extern TaskDesc gTaskDescBtlLockon;
extern TaskDesc gTaskDescBtlHpply;
extern TaskDesc gTaskDescBtlHpenm;
extern TaskDesc gTaskDescBtlEscape;
extern u8 gTaskDescLevelUp[];
extern u8 gUnk_09EE7804[];
#ifdef VERSION_EU
extern u8 gUnkEu_09F72C10[];
extern u8 gUnkEu_09F72D80[];
void eu_08013190(void);
#endif
extern Mode gModeChkbtl;

extern AnimHeader* gUnk_09EDF514[];
extern u32 gUnk_09EDF4F4[];
extern u8 gUnk_08935BC2[];
extern AnimHeader* gUnk_09EEF938[];
extern u32 gUnk_09EEF918[];
extern u8 gUnk_092F15E4[];
extern AnimHeader* gUnk_09EEF914[];
extern u32 gUnk_09EEF8F4[];
extern u8 gUnk_092EFAD4[];
extern AnimHeader* gUnk_09EEF8F0[];
extern u32 gUnk_09EEF8D0[];
extern u8 gUnk_092ED9F6[];
extern AnimHeader* gUnk_09EDF4F0[];
extern u32 gUnk_09EDF4D0[];
extern u8 gUnk_0893416A[];
extern AnimHeader* gUnk_09EDED5C[];
extern u32 gUnk_09EDED3C[];
extern u8 gUnk_088DC192[];
extern AnimHeader* gUnk_09EDEB88[];
extern u32 gUnk_09EDEB68[];
extern u8 gUnk_088CE0C2[];
extern AnimHeader* gUnk_09EDEA90[];
extern u32 gUnk_09EDEA70[];
extern u8 gUnk_088C5AAA[];
extern AnimHeader* gUnk_09EDEA0C[];
extern u32 gUnk_09EDE9EC[];
extern u8 gUnk_088C1388[];
extern AnimHeader* gUnk_09EDE940[];
extern u32 gUnk_09EDE920[];
extern u8 gUnk_088BAC36[];
extern u8 gUnk_09618118[];
extern u8 gUnk_08F683A4[];
extern vu16 gSystemFlags;

u8 func_0801AD68(BtlObj* p);
void func_08010C70(void);
void func_08011364(BtlObj* a, BtlObj* b, const UnkStruct_0813400C* c);
void InitPlayerProgression(void);

void func_080135EC(s32 x, s32 y, s32 z);
void func_08013560(s32 x, s32 y, s32 z);
void func_0801350C(void);
void func_08013070(void);
void func_080146A8(s32 x, s32 y, s32 z);
void func_08014654(void);
void func_080167F8(void);
void func_08012C08(void);
void func_08017E18(s32 x, u8 f, s32 w);
void func_08017AC0(void);
void func_08017C54(void);
void func_08016D00(void);
void func_0801440C(void);
void func_080175BC(BtlObj* p, BtlObj* o, u8 a, u8 b);
void func_080177EC(void);
void func_080153C8(void);
void func_08018CC4(void);
void func_080180C8(void);
void func_08018240(void);
void func_08015E3C(void);
void func_080160C0(void);
void func_08015698(void);
void func_080158E8(void);
void func_08013B00(void);
void func_08017410(void);
void func_08016468(void);
void func_08018B78(void);
void func_080138BC(s32 x, s32 y, s32 z);
void func_0801392C(s32 x, s32 y, s32 z);
void func_08013854(s32 x, s32 y, s32 z);
void func_080136E0(s32 x, s32 y, s32 z);
void func_08013678(s32 x, s32 y, s32 z);
void func_0801709C(void);
void func_0801718C(void);
u8 func_0801B818(UnkStruct_0801B8A8* p, u16 b, s16 c, s16* n, s16* cnt);
void func_0801B8A8(UnkStruct_0801B8A8* p, u16 b, s16 c, s16* n);

s32 LevelUpMaxHp(void);
s32 LevelUpCp(void);
s32 LevelUpDp(void);
s32 LevelUpAp(void);
void AddExp(u16 a);
void func_08015D04(void);
s32 func_08012188(BtlObj* p, s16 h, s32 c);
void func_0807E260(void);
u8 func_0807B3F8(void);
u8 func_0807E34C(void);
u8 func_08081838(void);
u8 func_0801CA48(BtlObj* p);

void func_08012728(s16 a);
void func_080139FC(s32 x, s32 y, s32 z);
void func_08013748(s32 x, s32 y, s32 z, u8 f);
void func_080141D4(void);
void func_08019C5C(void);

void func_08012214(void);
void ColliderClearPoolContacts(ListPool* pool);
u8 func_080126E4(u8 a);
void func_0801CB18(void);

u8 ColliderIsColliding(Collider* p);
s32 func_0801A978(BtlObj* p);
u8 func_08085BAC(void);
u8 HasNonPremiumCardsInActiveDeck(void);
void func_0809B710(void* pool, s16 a, s16 b, s16 c, u16 d);

#endif /* GUARD_BATTLE_H */
