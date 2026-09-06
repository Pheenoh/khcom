#ifndef GUARD_MSG_H
#define GUARD_MSG_H

#include "types.h"
#include "anim.h"
#include "mode.h"
#include "key.h"
#include "text_types.h"
#include "malloc.h"
#include "taskpool.h"


#define NULL ((void*)0)

typedef struct Ent0806E9BC {
    u32 unk_00;
    u16 unk_04;
    u8 unk_06[2];
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    u16 unk_14;
    u8 unk_16[2];
    u32 unk_18;
    void* unk_1C;
    void (*unk_20)(void*);
} Ent0806E9BC;

typedef struct Work0806180C {
    Ent0806E9BC* unk_000;
    void* tiles;
    void* palette;
    void* unk_00C;
    TaskPool unk_010;
    u8 unk_024[2];
    u8 unk_026;
    u8 unk_027;
    u8 unk_028[4];
    s32 unk_02C;
    s32 unk_030;
    s32 unk_034;
    u8 unk_038[4];
    u16 unk_03C;
    u16 unk_03E;
    u8 unk_040[4];
    u16 unk_044;
    u8 unk_046[0x136];
    s32 unk_17C;
    s32 unk_180;
    s32 unk_184;
    s32 unk_188;
    s32 unk_18C;
    s32 unk_190;
    s32 unk_194;
    s32 unk_198;
    s32 unk_19C;
    u32 unk_1A0;
    s32 unk_1A4;
    u8 unk_1A8;
    u8 unk_1A9;
    u8 unk_1AA;
    u8 unk_1AB;
    u8 unk_1AC;
    u8 unk_1AD;
    u8 unk_1AE;
    u8 unk_1AF;
    u8 unk_1B0;
    u8 unk_1B1;
    u8 unk_1B2;
    u8 unk_1B3;
    u8 unk_1B4;
    u8 unk_1B5;
    u8 unk_1B6;
    u8 unk_1B7;
    u16 unk_1B8;
    u8 unk_1BA[2];
} Work0806180C;

typedef struct MsgLine0806180C {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u8 unk_0C;
    u8 unk_0D[3];
    u32 unk_10;
    u16 unk_14;
    u16 unk_16;
} MsgLine0806180C;

typedef struct Ent02034A80 {
    s32 unk_00;
    s32 unk_04;
    u32 unk_08[16];
    u32 unk_48;
    u32 unk_4C;
    u8 unk_50;
    u8 unk_51;
    u8 unk_52;
    u8 unk_53;
    u8 unk_54;
    u8 unk_55[3];
} Ent02034A80;

typedef struct Ent08066588 {
    void* unk_00;
    u8 unk_04;
    s8 unk_05;
    u8 unk_06[2];
} Ent08066588;

typedef struct Ent02034A8C {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02[16];
    u8 unk_22;
    u8 unk_23;
    u8 unk_24;
    u8 unk_25;
    u8 unk_26;
} Ent02034A8C;

typedef struct GameState {
    u8 unk_00[8];
    u32 flags;
    u8 world;
    u8 unk_0D;
    u8 unk_0E[0x172];
    u16 unk_180;
} GameState;

typedef struct MsgFaceCtl {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u32 unk_04;
    u8 unk_08;
} MsgFaceCtl;

typedef struct MsgFaceAnim {
    void* unk_00;
    void* unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10;
    u8 unk_11;
    u8 unk_12[2];
} MsgFaceAnim;

typedef struct MsgFaceWork {
    void* tiles;
    void* palette;
    void* gfx;
    u8 anim[0x18];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    u8 unk_30;
    u8 unk_31;
    u8 unk_32;
    u8 unk_33;
    u8 unk_34;
    u8 unk_35[3];
    MsgFaceCtl* unk_38;
} MsgFaceWork;

typedef struct Work08073E34 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u32 unk_04;
} Work08073E34;

typedef struct MsgWinWork {
    u8 unk_00[0x14];
    void* palette;
    s32 unk_18;
    u16 unk_1C;
    u8 unk_1E;
    u8 unk_1F;
    u32 unk_20;
    u8 unk_24;
    u8 unk_25;
    u8 unk_26;
    u8 unk_27;
    u8 unk_28;
    u8 unk_29;
    u8 unk_2A;
    u8 unk_2B;
    Work08073E34 unk_2C;
    u8 unk_34;
    u8 unk_35[3];
    u8 unk_38;
    u8 unk_39[3];
    MsgLine0806180C* unk_3C;
    s32 unk_40;
} MsgWinWork;

typedef struct ContinueWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    void* unk_14;
    void* unk_18;
    void* unk_1C;
    AnimState unk_20;
    AnimState unk_38;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5C;
    s32 unk_60;
    u8 unk_64;
    u8 unk_65;
    u16 unk_66;
    u8 unk_68[2];
    u8 unk_6A;
    s8 unk_6B;
} ContinueWork;

typedef struct EventSeqWork {
    TaskPool unk_00;
    TaskPool unk_14;
    u32 unk_28;
    u16 unk_2C;
    u8 unk_2E;
    u8 unk_2F;
    u8 unk_30;
    u8 unk_31;
    u8 unk_32;
    u8 unk_33;
    struct UnkStruct_09EE3FB4* unk_34;
    u16 unk_38;
    u8 unk_3A[2];
} EventSeqWork;

typedef struct BtlWork {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    u8 unk_18[0x14];
    TaskPool unk_2C;
    TaskPool unk_40;
    u8 unk_54[0x28];
    struct Ent08074EC8* unk_7C;
    ListNode unk_80;
} BtlWork;

typedef struct Ent0903380C {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
} Ent0903380C;

typedef struct Ent0806E7A8 {
    u8 unk_00[0x34];
    u64 unk_34;
} Ent0806E7A8;

typedef struct Ent08074EC8 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} Ent08074EC8;

typedef struct EventSeqArg {
    u32 unk_00 : 16;
    u32 unk_02 : 8;
    u32 unk_03 : 8;
} EventSeqArg;

typedef struct Ent09EE3CA0 {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void** unk_0C;
    void* unk_10;
    void* unk_14;
    u16 unk_18;
    u16 unk_1A;
    u16 unk_1C;
    u8 unk_1E;
    u8 unk_1F;
    s32 unk_20;
    u8 unk_24;
    u8 unk_25[3];
    s32 unk_28;
    u8 unk_2C;
    u8 unk_2D;
    u8 unk_2E[2];
} Ent09EE3CA0;

typedef struct UnkStruct_02039DC8 {
    Ent08074EC8* unk_00[17];
    s32 unk_44;
    s32 unk_48;
    s32 unk_4C;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5C;
    s32 unk_60;
    u32 unk_64;
    s16 unk_68;
    s16 unk_6A;
    u16 unk_6C;
    u16 unk_6E;
    u16 unk_70;
    u8 unk_72[2];
    s32 unk_74;
    u8 unk_78;
    u8 unk_79;
    u8 unk_7A;
    u8 unk_7B;
    u8 unk_7C;
    u8 unk_7D;
    u8 unk_7E;
    u8 unk_7F;
    u8 unk_80;
    u8 unk_81;
    u8 unk_82;
    u8 unk_83;
    u8 unk_84;
    u8 unk_85;
    u8 unk_86;
    u8 unk_87;
    u8 unk_88;
    u8 unk_89;
    u8 unk_8A;
    u8 unk_8B;
} UnkStruct_02039DC8;

typedef struct UnkStruct_02039DCC {
    u8 unk_00[2];
    u8 unk_02;
    u8 unk_03;
    u16 unk_04[160];
} UnkStruct_02039DCC;

typedef struct Actor0806180C {
    u8 unk_00[0x24];
    u16 unk_24;
    u8 unk_26[6];
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
} Actor0806180C;

typedef struct Obj0806180C {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10;
    u8 unk_11[3];
    u32 unk_14;
    u8 unk_18[8];
} Obj0806180C;

typedef struct Work08074DC4 {
    s32 unk_00;
    s32 unk_04;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0A[2];
    Obj0806180C* unk_0C;
    u16 unk_10;
    u16 unk_12;
    u8 unk_14;
    u8 unk_15;
    u16 unk_16;
    u8 unk_18[2];
    u8 unk_1A;
    u8 unk_1B;
    u16 unk_1C[160];
} Work08074DC4;

typedef struct Handle0806180C {
    u8 unk_00[6];
    u16 unk_06;
} Handle0806180C;

typedef struct MsgWaitWork {
    void* tiles;
    u8 unk_04[0x10];
    Handle0806180C* palette;
    u8 unk_18[0xA4];
    void* gfx;
    u8 unk_C0[0x1C];
    u8 unk_DC[0x26];
    u8 unk_102;
    u8 unk_103;
    u8 unk_104[4];
} MsgWaitWork;

typedef struct MsgWaitYesNoWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    void* unk_14;
    void* unk_18;
    TextSlot unk_1C[10];
    TextSlot unk_6C[10];
    void* gfx;
    void* unk_C0;
    u8 unk_C4[0x18];
    u8 anim[0x18];
    u8 unk_F4;
    u8 unk_F5;
    u8 unk_F6[2];
    s32 unk_F8;
    s32 unk_FC;
    u8 unk_100;
    u8 unk_101;
    u8 unk_102;
    u8 unk_103;
    u8 unk_104;
    u8 unk_105[3];
} MsgWaitYesNoWork;

typedef struct Ent080658B8 {
    s32 unk_00;
    s32 unk_04;
    void* unk_08;
    Handle0806180C* unk_0C;
    Handle0806180C* unk_10;
    u8 unk_14;
    u8 unk_15;
    u8 unk_16[2];
} Ent080658B8;

typedef struct Work08075010 {
    u8 unk_00[0x16];
    u16 unk_16;
    u8 unk_18[2];
    u8 unk_1A;
    u8 unk_1B;
    u16 unk_1C[160];
} Work08075010;

typedef struct AnimEntry0806180C {
    u8 unk_00[4];
    u8 unk_04;
    u8 unk_05[3];
} AnimEntry0806180C;

typedef struct UnkStruct_09EE3FB4 {
    u8 unk_00;
    u8 unk_01[3];
    AnimEntry0806180C* unk_04;
    Obj0806180C* unk_08;
    MsgLine0806180C* unk_0C;
    u8 unk_10[8];
    u16 unk_18;
    u8 unk_1A[6];
    u16 unk_20;
    u16 unk_22;
    u16 unk_24;
} UnkStruct_09EE3FB4;

extern UnkStruct_02039DC8* gUnk_02039DC8;
extern UnkStruct_02039DCC* gUnk_02039DCC;
extern u16 gUnk_09033C8C[];
extern u8 gUnk_09EE274C[];
extern u8 gModeBattle[];
extern u8 gUnk_08125E24[];
extern s32 gUnk_08F7DAC4[];
extern u8 gUnk_08F69BA4[];
extern u8 gUnk_09320796[];
extern u8 gUnk_09EEFCAC[];
extern u8 gUnk_09EEFD38[];
extern TaskDesc gTaskDescMsgface[];
extern TaskDesc gTaskDescMsgwin[];
extern TaskDesc gTaskDescEventChara[];
extern TaskDesc gTaskDescView[];
extern TaskDesc gTaskDescEvSound[];
extern TaskDesc gTaskDescEVBGEFFECT[];
extern TaskDesc gTaskDescMapAnim[];
extern TaskDesc gTaskDescEvMapObj[];
extern TaskDesc gTaskDescPooMapanime[];
extern u8 gUnk_096145D8[];
extern u8 gUnk_09614618[];
extern vu16 gIntrCheck;
extern u32 gUnk_02034A78;
extern GameState gGameState;
extern u16 gUnk_09033C98[];
extern u16 gUnk_09033CA0[];
extern s32 gUnk_09033CA8[];
extern s32 gUnk_09033CB8[];
extern s32 gUnk_09033CD0[];
extern s32 gUnk_09033CE0[];
extern s32 gUnk_09033CF0[];
extern BtlWork* gBtlWork;
extern u16 gBldCnt;
extern vu16 gBldAlpha;
extern u32 gFrameCounter;
extern UnkStruct_09EE3FB4* gUnk_09EE3FB4[];
extern u8 gUnk_09614718[];
extern u8 gUnk_09614738[];
extern u8 gUnk_09614758[];
extern u8 gUnk_09614778[];
extern u8 gUnk_09614798[];
extern u8 gUnk_096147B8[];
extern void* gUnk_09EEB204[];
extern void* gUnk_09EEB608[];
extern void* gUnk_09EEBA0C[];
extern void* gUnk_09EEBE10[];
extern void* gUnk_09EEC538[];
extern s32 gUnk_09033D08[][2];
extern s16 gSineTable[];
extern s16 gUnk_09033D50[];
extern s16 gUnk_09033E76[];
extern u8 gUnk_090D4180[];
extern MsgFaceAnim* gUnk_09EE45DC[];
extern void* gUnk_09EE3CA0[];
extern u8 gUnk_050001C0[];
extern u8 gUnk_094233B8[];
extern u8 gUnk_096148D8[];
extern u8 gUnk_0950E2F8[];
extern u8 gUnk_096112B8[];
extern void* gUnk_09EE4724[];
extern void* gUnk_0813B09C[][4];
extern u8 gUnk_08F69BE4[];
extern u8 gUnk_090AB5B2[];
extern u8 gUnk_090B3FBE[];
extern u8 gUnk_090BC9CA[];
extern u8 gUnk_090C51A6[];
extern u8 gUnk_09EDA7E0[];
extern u8 gUnk_08F683A4[];
extern u8 gUnk_09618118[];
extern u8 gUnk_09614418[];
extern u8 gUnk_090A4664[];
extern u8 gUnk_09EEB03C[];
extern u8 gUnk_09EEB008[];
extern u8 gUnk_093F7C9C[];
extern u8 gUnk_09611AB8[];
extern u16 gUnk_08159E10[];
extern u16 gUnk_08159E18[];
extern u8 gUnk_0941A418[];
extern u8 gUnk_0951CAB8[];
extern u8 gUnk_090A7D9A[];
extern u8 gUnk_096146F8[];
extern u8 gUnk_09614658[];
extern u8 gUnk_090A6B26[];
extern u8 gUnk_09EEB108[];
extern u8 gUnk_09EEB0C4[];
extern u8 gUnk_09EEB14C[];
extern u8 gUnk_09EEB11C[];
extern u8 gUnk_090A7F0A[];
extern u8 gUnk_090A8FC4[];
extern u8 gUnk_09EEB180[];
extern u8 gUnk_09EEB150[];
extern u16 gUnk_08F7D438[];
extern void* gUnk_09EEC134[];
extern u8 gUnk_090CBFB2[];
extern s32 gUnk_09033D28[];
extern Ent0903380C gUnk_0903380C[];
extern void* gUnk_09EF126C[];

void _08065994(void);
u16 func_080659BC(u8 v, TextSlot* out);
void func_08065A30(void** p, u8 n);
void func_08065A44(void** p, u8 n);
u16 func_08065A70(u8 v, TextSlot* out);
u16 func_080660C0(u8* s, TextSlot* p);
void _08073E6C(Work08073E34* p);
void func_08073E74(Work08073E34* p);
void view_2(void);
void view_3(void);
void func_08065ACC(TextSlot* p, s32 n);
void func_08065AE0(TextSlot* p, s32 n);
s16 func_08065B08(TextSlot* p, u8 n);
s32 func_08065B54(u16* s);
u16 func_08065B6C(u16* a, TextSlot* b);
s32 func_08065B7C(u16* a, TextSlot* b);
void* func_080668F0(void);
void* func_08066904(void);
void func_08066918(void* a, void* b);
void func_08002488(s16 x, s16 y, void* a, void* b, void* c, u16 d);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, s32 h);
void func_080643D4(u8 a, u8 b, u8 c, u8* s, u8 e, u8 f);
void func_08064624(void);
u8 func_08004678(void* a);
void* GetBgCharBase(s32 bg);
void* GetBgScreenBase(s32 bg);
void* _08066468(s32 a);
void func_080062F4(u16 a, s32 b);
u8 func_0800443C(void* a, u16 b);
void SetBackdropColor(u16 r, u16 g, u16 b);
void func_08006120(s32 a, s32 b);
void m4aSongNumStart(u16 id);
void func_08076110(s32 song, s16 x, s16 y);
u8 func_0809D280(u8* s);
u16 func_0806692C(u8* s, u16* out);
u16 func_08066AF8(s32 v, u16* out);
void func_0801CD74(void* a, s32 b);
void TaskPoolUpdate(TaskPool* a);
void SetTaskUpdate(u8* p, u32 v);
u8 _0806E9DC(Work0806180C* p, void* a);
void func_0801CE00(void* a, u16 b);
void* memcpy(void* dst, const void* src, unsigned long n);
void ModeRequest(Mode* mode, s32 arg);
void* TaskCreate(void* a, TaskDesc* desc, void* arg);
void TaskPoolDestroy(TaskPool* a);
void TaskPoolDraw(TaskPool* a);
void LoadBgPalette(s32 bg, void* src, u16 size);
void LoadBgTiles(s32 bg, void* src, u16 size);
void SetBgPriority(s32 bg, u16 priority);
void TaskPoolInit(TaskPool* a, s32 count);
void func_08073E0C(void* pool, Work08073E34* p, u8 a, u8 b, u8 c);
u8 func_08064EF4(s32 a, s32 b, s32 c, s32* d);
void m4aMPlayAllStop(void);
u8 func_08006314(void);
void func_08074504(void);
void* AnimUpdate(AnimState* a);
void AnimStart(AnimState* a, u16 animId, u16 flags);
void DisableBg(s32 bg);
s32 AllocObjAffine(s32 a, s32 b, s32 c, s32 d);
void* AllocObjTiles(s32 a, s32 b);
void* AllocObjPalette(s32 a);
void LoadObjPaletteBank(u16 a, void* b);
void func_08002A10(void* a, void* b);
void func_08003A70(void* a, void* b);
void* AnimGetGfx(AnimState* a);
u8 func_08073DA4(MsgFaceWork* p, void* a);
void AnimInit(AnimState* a, s32 b, s32 c);
void func_08005244(s32 a, u16 b, u16 c);
void SetBgAffine(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
u8 func_08073294(MsgWinWork* p, void* a);
u8 func_08073318(MsgWinWork* p, void* a);
u8 func_0807344C(MsgWinWork* p, void* a);
void func_0807361C(MsgWinWork* p);
void func_08073508(MsgWinWork* p);
void func_080736F8(MsgWinWork* p);
u8 func_08072EAC(MsgWinWork* p, void* a);
u8 func_08073F78(MsgWaitWork* p);
void LoadBgMap(s32 bg, void* src, u16 size);
void SetBgScroll(s32 a, u16 b, u16 c);
void func_0800516C(s32 a, void* b, s32 c, s32 d);
void func_080051C4(s32 a, u16 b, u16 c);
u8 msgface_1(MsgFaceWork* p, void* a);
u8 func_08073B04(MsgFaceWork* p, void* a);
u8 func_08073B54(MsgFaceWork* p, void* a);
u8 func_08073B9C(MsgFaceWork* p, void* a);
u8 func_08073CA4(MsgFaceWork* p, void* a);
u8 func_0807420C(MsgWaitYesNoWork* p, void* a);
void _0806C3A0(u8 a, void* b);
void func_08065AE0(TextSlot* p, s32 n);
void func_080635C4(void);
void func_080DF828(void);
void func_080E04EC(void);
void func_0800FDD0(s32 a);
void func_08084458(u16 a);
void func_080938F8(u16 a);
void func_08066E40(u16 a, u16* b, u8* c);
void func_0800FB2C(s32 a);
void func_0800FC14(s32 a);
void SaveWriteFileLarge(u16 file);
u8 event_chara_1(Work0806180C* p, void* a);
u8 func_0806FA84(Work0806180C* p, void* a);
u8 func_0806FDB0(Work0806180C* p, void* a);
u8 func_0806FC28(Work0806180C* p, void* a);
u8 func_0806FAB8(Work0806180C* p, void* a);
u16 GetRandom(void);
u8 func_0806E570(Work0806180C* p);
void func_0806E7A8(Work0806180C* p);
void func_08070AD4(Work0806180C* p);
u8 func_0806EA28(Work0806180C* p, void* a);
u8 func_0806EB94(Work0806180C* p, void* a);
u8 func_0806EBE0(Work0806180C* p, void* a);
u8 func_0806ECE0(Work0806180C* p, void* a);
u8 func_0806ED2C(Work0806180C* p, void* a);
u8 func_0806EE20(Work0806180C* p, void* a);
u8 func_0806EE6C(Work0806180C* p, void* a);
u8 func_0806EF40(void* work, void* a);
u8 func_0806F02C(Work0806180C* p, void* a);
u8 func_0806F114(void* work, void* a);
u8 func_0806F204(Work0806180C* p, void* a);
u8 func_0806F2EC(void* work, void* a);
u8 func_0806F3A8(Work0806180C* p, void* a);
u8 func_0806F47C(void* work, void* a);
u8 func_0806F53C(Work0806180C* p, void* a);
u8 func_0806F610(Work0806180C* p, void* a);
u8 func_0806F64C(Work0806180C* p, void* a);
u8 func_0806F734(Work0806180C* p, void* a);
u8 func_0806F770(Work0806180C* p, void* a);
u8 func_0806F858(Work0806180C* p, void* a);
u8 func_0806F898(Work0806180C* p, void* a);
void func_08065940(void);
void func_080658B8(u8 n);
void func_0806C34C(void);
void func_0806E9BC(Work0806180C* p);
void func_0806F94C(Work0806180C* p);
void LoadPalette(void* src, void* dst, s32 size);
void func_0801CD98(void* pool, void* obj, s32 res, s32 anim, s32 a, s32 b, s32 c);
s32 func_0810B350(void* p);
void func_0810C2C4(void* p);
Ent0806E7A8* ListPoolFirst(ListNode* node);
void EvtObjSetPos(void* obj, s32 a, s32 b, s32 c);
void func_08073E34(Work08073E34* p, u8 a, u8 b, u8 c);
void func_080746D8(void);
void func_08072918(Actor0806180C* a, u8 kind, u8 flag);
void func_08072A64(Actor0806180C* a, u8 kind, u8 flag);
u16 func_0806BA74(s32 mode, s32 flag);
void func_0806BA0C(s16 v, u8* out);
void func_0806C2C0(u8 n);
void ApproachValue(s32* value, s32 target, u16 steps);
void func_08074D00(Work08074DC4* p);
void func_08074D14(Work08074DC4* a);
u8 func_08074E40(Work08074DC4* p);
void func_08074D98(Work08074DC4* a);
u8 func_08074E88(Work08074DC4* p, u8 v);
void func_08075010(Work08075010* p);
s16 func_08075064(u8 a);
void func_08074DC4(Work08074DC4* a);

s32 abs(s32 a);
s8 GetAngleDiff(u8 a, u8 b);
void func_0806FE90(Work0806180C* p);
u8 func_0807048C(Work0806180C* p, void* a);
u8 GetKeyReleaseTime(s32 a);
void func_08072C34(Work0806180C* p);
void func_0806CD60(ContinueWork* p);
void func_0806CF04(ContinueWork* p);
void msgwait_yesno_0(MsgWaitYesNoWork* p, u8* a);
u8 func_0806D830(EventSeqWork* p, void* a);
void SetBgMode1(void);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void SetBgSize(s32 bg, s32 size);
void SetBgColorMode(s32 bg, s32 mode);
void func_080CA35C(void);
void func_080065FC(s32 a, s32 b, s32 c);
void func_08006778(void* a, s32 x, s32 y);
void func_08006B34(u16 a);
void PushPaletteEffect(s32 a);
void PopPaletteEffect(void);
void func_08075E60(Work0806180C* p);
void func_08070008(Work0806180C* p);
u8 func_080700D4(Work0806180C* p, void* a);

void* LoadObjTiles(void* a, s32 b);
void* LoadObjPalette(void* a, s32 b);
void* func_080038C8(u16 a);
void func_080038E4(void* a, void* b, void* c);
void ReleaseObjTiles(void* a);
void ReleaseObjPalette(u8* p);

#endif /* GUARD_MSG_H */
