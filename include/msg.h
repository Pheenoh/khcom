#ifndef GUARD_MSG_H
#define GUARD_MSG_H

#include "graphics_state.h"

#include "obj.h"

#include "msg_types.h"

#include "continue_types.h"

#include "evt_types.h"

#include "card_api.h"

#include "map_api.h"
#include "msg_api.h"
#include "eventselect_api.h"

#include "intr.h"
#include "pallet.h"
#include "save_api.h"

#include "player_progression.h"

#include "m4a_song.h"
#include "battle_actor.h"
#include <string.h>
#include <stdlib.h>
#include "text.h"
#include "fade.h"
#include "obj_api.h"
#include "display.h"
#include "types.h"
#include "engine_math.h"
#include "listpool.h"
#include "battle_work.h"
#include "game_state.h"
#include "anim.h"
#include "mode.h"
#include "key.h"
#include "text_types.h"
#include "malloc.h"
#include "taskpool.h"
#include "bos4_api.h"
#include "bos6_api.h"
#include "poo_api.h"
#include "evt_api.h"

#define NULL ((void*)0)

typedef struct EventCharaKeyframe {
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
} EventCharaKeyframe;

typedef struct EventCharaWork {
    EventCharaKeyframe* unk_000;
    void* tiles;
    void* palette;
    void* gfx;
    TaskPool unk_010;
    u16 unk_024;
    u8 unk_026;
    u8 unk_027;
    u8 unk_028[4];
    s32 unk_02C;
    s32 unk_030;
    s32 unk_034;
    u8 unk_038[4];
    u16 unk_03C;
    u16 unk_03E;
    AnimState* unk_040;
    u16 unk_044;
    u8 unk_046[0xE];
    u8 unk_054[0x128];
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
} EventCharaWork;


typedef struct SpriteTextLine {
    s32 x;
    s32 y;
    u32 glyphTiles[16];
    u32 palette;
    u32 unk_4C;
    u8 length;
    u8 font;
    u8 unk_52;
    u8 unk_53;
    u8 unk_54;
    u8 unk_55[3];
} SpriteTextLine;

typedef struct BgTextLine {
    u8 x;
    u8 y;
    u16 glyphs[16];
    u8 length;
    u8 glyphHeight;
    u8 bg;
    u8 dirty;
    u8 paletteIndex;
} BgTextLine;


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
    s32 x;
    s32 y;
    s32 unk_2C;
    u8 unk_30;
    u8 unk_31;
    u8 unk_32;
    u8 unk_33;
    u8 unk_34;
    u8 unk_35[3];
    MsgFaceControl* unk_38;
} MsgFaceWork;


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
    MsgFaceControl unk_2C;
    u8 unk_38;
    u8 unk_39[3];
    MessageScriptEntry* unk_3C;
    s32 unk_40;
} MsgWinWork;


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
    struct EventSequenceDef* unk_34;
    u16 unk_38;
    u8 unk_3A;
    u8 unk_3B;
    u8 unk_3C;
    u8 unk_3D;
} EventSeqWork;

typedef struct EventCharaParams {
    s16 spriteYOffset;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
} EventCharaParams;



typedef struct EventSeqArg {
    u32 unk_00 : 16;
    u32 unk_02 : 8;
    u32 unk_03 : 8;
} EventSeqArg;

typedef struct EventBackgroundDef {
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
} EventBackgroundDef;


typedef struct EventScanlineScroll {
    u8 unk_00[2];
    u8 enabled;
    u8 unk_03;
    u16 scrollX[160];
} EventScanlineScroll;

typedef struct Actor0806180C {
    u8 unk_00[0x24];
    u16 unk_24;
    u8 unk_26[6];
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
} Actor0806180C;


typedef struct EventCameraWork {
    s32 unk_00;
    s32 unk_04;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0A[2];
    EventCameraKeyframe* unk_0C;
    u16 unk_10;
    u16 unk_12;
    u8 unk_14;
    u8 unk_15;
    u16 wavePhase;
    u8 unk_18[2];
    u8 waveEnabled;
    u8 unk_1B;
    u16 scanlineScrollX[160];
} EventCameraWork;


typedef struct MsgWaitWork {
    void* tiles;
    u8 unk_04[0x10];
    ObjPalette* palette;
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

typedef struct TextGlyphSprite {
    s32 x;
    s32 y;
    void* tiles;
    ObjPalette* palette;
    ObjPalette* alternatePalette;
    u8 useAlternatePalette;
    u8 visible;
    u8 unk_16[2];
} TextGlyphSprite;




extern EventState* gUnk_02039DC8;
extern EventScanlineScroll* gUnk_02039DCC;
extern u16 gUnk_09033C8C[];
extern u8 gUnk_09EE274C[];
extern u8 gModeBattle[];
extern u8 gUnk_08125E24[];
extern s32 gUnk_08F7DAC4[];
extern u8 gUnk_08F69BA4[];
extern u8 gUnk_09320796[];
extern u8 gUnk_09EEFCAC[];
extern u8 gUnk_09EEFD38[];
extern TaskDesc gTaskDescBosTm[];
extern TaskDesc gTaskDescBosJf[];
extern TaskDesc gTaskDescBosDsd[];
extern TaskDesc gTaskDescBosBoogie[];
extern TaskDesc gTaskDescBosUrsula[];
extern TaskDesc gTaskDescBosGa[];
extern TaskDesc gTaskDescBosPc[];
extern TaskDesc gTaskDescBosLst[];
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
extern TaskPool gUnk_02034A60;
extern u32 gUnk_02034A78;
extern u16 gUnk_09033C98[];
extern u16 gUnk_09033CA0[];
extern s32 gUnk_09033CA8[];
extern s32 gUnk_09033CB8[];
extern s32 gUnk_09033CD0[];
extern s32 gUnk_09033CE0[];
extern s32 gUnk_09033CF0[];


extern u32 gFrameCounter;
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
extern s32 gUnk_09033758[];
extern u8 gUnk_050001C0[];
extern u8 gUnk_094233B8[];
extern u8 gUnk_096148D8[];
extern u8 gUnk_0950E2F8[];
extern u8 gUnk_096112B8[];
extern void* gUnk_09EE4724[];
extern void* gUnk_0813B09C[][4];
extern u8 gUnk_08F69BE4[];
extern void* gUnk_09EEB188[];
extern u8 gUnk_090AA506[];
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
extern EventCharaParams gUnk_0903380C[];
extern void* gUnk_09EF126C[];

void _08065994(void);
u16 func_080659BC(u8 v, TextSlot* out);
void InitTextTileArray(void** p, u8 n);
void FreeTextTileArray(void** p, u8 n);
u16 LoadTwoDigitTextSlots(u8 v, TextSlot* out);
void _08073E6C(MsgFaceControl* p);
void func_08073E74(MsgFaceControl* p);
void view_2(void);
void view_3(void);
s32 LoadLatinTextSlots(u16* a, TextSlot* b);
s32 LoadJapaneseTextSlots(u16* a, TextSlot* b);
void func_08002488(s16 x, s16 y, void* a, void* b, void* c, u16 d);
void func_080643D4(u8 a, u8 b, u8 c, u8* s, u8 e, u8 f);
void func_08064624(void);
u8 QueueVTransCallback(void* a);
u8 func_0809D280(u8* s);
u8 _0806E9DC(EventCharaWork* p, void* a);
void func_08073E0C(void* pool, MsgFaceControl* p, u8 a, u8 b, u8 c);
u8 func_08064EF4(s32 a, s32 b, s32 c, s32* d);
void func_08074504(void);
u8 func_08073DA4(MsgFaceWork* p, void* a);
u8 func_08073294(MsgWinWork* p, void* a);
u8 func_08073318(MsgWinWork* p, void* a);
u8 func_0807344C(MsgWinWork* p, void* a);
void func_0807361C(MsgWinWork* p);
void func_08073508(MsgWinWork* p);
void func_080736F8(MsgWinWork* p);
u8 func_08072EAC(MsgWinWork* p, void* a);
u8 func_08073F78(MsgWaitWork* p);
u8 msgface_1(MsgFaceWork* p, void* a);
u8 func_08073B04(MsgFaceWork* p, void* a);
u8 func_08073B54(MsgFaceWork* p, void* a);
u8 func_08073B9C(MsgFaceWork* p, void* a);
u8 func_08073CA4(MsgFaceWork* p, void* a);
u8 func_0807420C(MsgWaitYesNoWork* p, void* a);
void _0806C3A0(u8 a, void* b);
void func_080635C4(void);

void func_08066E40(u16 a, u16* b, u8* c);

u8 event_chara_1(EventCharaWork* p, void* a);
u8 func_0806FA84(EventCharaWork* p, void* a);
u8 func_0806FDB0(EventCharaWork* p, void* a);
u8 func_0806FC28(EventCharaWork* p, void* a);
u8 func_0806FAB8(EventCharaWork* p, void* a);
u8 func_0806E570(EventCharaWork* p);
void func_0806E7A8(EventCharaWork* p);
s32 func_08070AD4(EventCharaWork* p);
u8 func_0806EA28(EventCharaWork* p, void* a);
u8 func_0806EB94(EventCharaWork* p, void* a);
u8 func_0806EBE0(EventCharaWork* p, void* a);
u8 func_0806ECE0(EventCharaWork* p, void* a);
u8 func_0806ED2C(EventCharaWork* p, void* a);
u8 func_0806EE20(EventCharaWork* p, void* a);
u8 func_0806EE6C(EventCharaWork* p, void* a);
u8 func_0806EF40(void* work, void* a);
u8 func_0806F02C(EventCharaWork* p, void* a);
u8 func_0806F114(void* work, void* a);
u8 func_0806F204(EventCharaWork* p, void* a);
u8 func_0806F2EC(void* work, void* a);
u8 func_0806F3A8(EventCharaWork* p, void* a);
u8 func_0806F47C(void* work, void* a);
u8 func_0806F53C(EventCharaWork* p, void* a);
u8 func_0806F610(EventCharaWork* p, void* a);
u8 func_0806F64C(EventCharaWork* p, void* a);
u8 func_0806F734(EventCharaWork* p, void* a);
u8 func_0806F770(EventCharaWork* p, void* a);
u8 func_0806F858(EventCharaWork* p, void* a);
u8 func_0806F898(EventCharaWork* p, void* a);
void func_0806E9BC(EventCharaWork* p);
void func_0806F94C(EventCharaWork* p);
void func_08073E34(MsgFaceControl* p, u8 a, u8 b, u8 c);
void func_080746D8(void);
void func_08072918(Actor0806180C* a, u8 kind, u8 flag);
void func_08072A64(Actor0806180C* a, u8 kind, u8 flag);
void func_08074D00(EventCameraWork* p);
void func_08074D14(EventCameraWork* a);
u8 func_08074E40(EventCameraWork* p);
void func_08074D98(EventCameraWork* a);
u8 func_08074E88(EventCameraWork* p, u8 v);
u8 _08074EC8(EventCameraWork* p);
void func_08075010(EventCameraWork* p);
void func_08074DC4(EventCameraWork* a);

void func_0806FE90(EventCharaWork* p);
u8 func_0807048C(EventCharaWork* p, void* a);
void func_08072C34(EventCharaWork* p);
void func_0806CD60(ContinueWork* p);
void func_0806CF04(ContinueWork* p);
void msgwait_yesno_0(MsgWaitYesNoWork* p, u8* a);
u8 func_0806D830(EventSeqWork* p, void* a);
void func_08070008(EventCharaWork* p);
u8 func_080700D4(EventCharaWork* p, void* a);

#endif /* GUARD_MSG_H */
