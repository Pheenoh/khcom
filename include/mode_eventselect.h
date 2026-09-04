#ifndef GUARD_MODE_EVENTSELECT_H
#define GUARD_MODE_EVENTSELECT_H

#include "types.h"
#include "key.h"
#include "taskpool.h"
#include "gba/syscall.h"
#include "malloc.h"
#include "m4a.h"
#include "evt_types.h"
#include "game.h"
#include "card.h"
#include "mode.h"
#include "anim.h"

typedef struct UnkStruct_02039DD0 {
    s16 pan;
    u16 volume;
} UnkStruct_02039DD0;

typedef struct CardBattleWork {
    TaskPool unk_00;
    void* tiles;
    void* palette;
    u8 unk_1C[0x28];
    void* unk_44[4];
    u8 unk_54[0x50];
    s16 unk_A4;
    u8 unk_A6[0x0A];
    s16 unk_B0;
    u8 unk_B2[0x07];
    u8 unk_B9;
    u8 unk_BA;
    u8 unk_BB[0x11];
} CardBattleWork;

typedef struct DownWork {
    s32 unk_00[8];
    s32 unk_20[8];
    u8 unk_40[8];
    u16 unk_48[8];
} DownWork;

typedef struct EvSoundCue {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
} EvSoundCue;

typedef struct EvSoundWork {
    EvSoundCue* unk_00;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    s32 unk_08;
} EvSoundWork;

typedef struct EventTaskHost {
    u8 unk_00[0x10];
    TaskPool unk_10;
} EventTaskHost;

typedef struct EventBody {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} EventBody;

typedef struct EventActor {
    u8 unk_00[0x26];
    u8 unk_26;
    u8 unk_27;
    EventBody unk_28;
    u8 unk_38[0x06];
    u16 unk_3E;
    u8 unk_40[0x172];
    u8 unk_1B2;
} EventActor;

typedef struct EffectWork {
    EventActor* unk_00;
    void* tiles;
    void* palette;
    void* gfx;
    DownWork* unk_10;
    AnimState anim;
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
    u16 unk_44;
    u16 unk_46;
    u8 unk_48;
    u8 unk_49;
    u8 unk_4A[0x02];
    TaskPool unk_4C;
} EffectWork;

extern UnkStruct_02039DD0* gUnk_02039DD0;
extern UnkStruct_02039DC8* gUnk_02039DC8;
extern u8 gUnk_0905EAE8[];
extern u8 gUnk_0905ED36[];
extern u8 gUnk_0905EEE6[];
extern u8 gUnk_09611AB8[];
extern u8 gUnk_08F6DC84[];
extern u8 gUnk_08BCB3D8[];
extern u8 gUnk_08F69BE4[];
extern u8 gUnk_09EE1CB4[];
extern u8 gUnk_09EE1C94[];
extern u8 gUnk_09EEFD78[];
extern u8 gUnk_09EEFD60[];
extern u8 gUnk_09EEFD38[];
extern u8 gUnk_09EEFCAC[];
extern u8 gUnk_09EDE7E4[];
extern u8 gUnk_09EDE7B4[];
extern s16 gUnk_0903380C[][6];
extern s16 gSineTable[];
extern void* gUnk_09EEA19C[];
extern u8 gUnk_093215CA[];
extern u8 gUnk_09320796[];
extern u8 gUnk_09321804[];
extern u8 gUnk_0908C686[];
extern void* gUnk_09EF12E8[];
extern u8 gUnk_09EEFD9C[];
extern u8 gUnk_09EEFD7C[];
extern TaskDesc gTaskDescHanabira;
extern TaskDesc gTaskDescHanabiraC;
extern TaskDesc gTaskDescSmoke;
extern TaskDesc gTaskDescExclamation;
extern TaskDesc gTaskDescBalloon;
extern TaskDesc gTaskDescQuestion;
extern TaskDesc gUnk_09EE484C;
extern TaskDesc gUnk_09EE4864;
extern TaskDesc gUnk_09EE487C;
extern TaskDesc gTaskDescDown;
extern TaskDesc gTaskDescTinkerbell;
extern const char gUnk_08F70990[];
extern const char gUnk_09033ED8[];
extern const char gUnk_09033EDC[];
extern const char gUnk_09033EE0[];
extern const char gUnk_09033EF8[];
extern const char gUnk_09033F10[];
extern s16 gUnk_09033D50[];
extern s16 gUnk_09033E76[];
extern const char* gEventNames[];
extern Mode gModeDebug;

void ModeRequest(Mode* mode, s32 arg);
u16 GetKeysRepeat(void);
void SetBgMode0(void);
void EnableBg(s32 a);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void func_0805FA60(s32 a, void* b, s32 c, u8 d);
void func_0805FA8C(s32 a, s32 b, s32 c);
void func_0805FC04(u8 x, u8 y, u8 c, u16 v);
void func_0805FCB0(u8 x, u8 y, u8 c, const char* s);
void func_08060598(void);
void func_080605A4(s32 a);
void func_0806180C(u16 a);
s16 func_08075064(u8 a);
void func_08085C3C(void);
void func_08085FB0(void);
void func_08093BB4(void);
void* func_080668F0(void);
void* func_08066904(void);
void func_08066918(void* a, void* b);
u8 _080669DC(s32 a, void* b);
void func_08066DC0(s32 a, s32 b, void* c, s32 d, s32 e, s32 f, s32 g);
void func_080062F4(u16 a, s32 b);
void TaskPoolInit(TaskPool* a, s32 count);
void* TaskCreate(TaskPool* pool, void* desc, void* arg);
void TaskPoolUpdate(TaskPool* a);
void AnimInit(AnimState* a, s32 b, s32 c);
void AnimStart(AnimState* a, s32 b, s32 c);
void* AnimUpdate(AnimState* a);
void* AnimGetGfx(AnimState* a);
void* AllocObjTiles(s32 a, void* b);
void func_08002A10(void* a, u32 b);
u8 func_08006314(void);
u16 GetRandom(void);
void func_080609A0(void);
void* func_080038C8(u16 a);
void func_080038E4(void* a, void* b, u32 c);
u16 func_080787B8(CardBattleWork* w, s32 a);
void func_0807B668(UnkStruct_02039DD4* p);
void func_0807E23C(void);
void func_0807E248(void);

void mode_eventselect_0(void);
void mode_eventselect_1(void);
void mode_eventselect_2(void);
void Hanabira_0(EffectWork* w, void* arg);
s32 Hanabira_1(EffectWork* w);
void Hanabira_2(EffectWork* w);
void Hanabira_3(EffectWork* w);
void Hanabira_c_0(EffectWork* w, EventActor* arg);
s32 Hanabira_c_1(EffectWork* w);
void Hanabira_c_2(EffectWork* w);
void Hanabira_c_3(EffectWork* w);
void smoke_0(EffectWork* w, EventActor* arg);
void Exclamation_0(EffectWork* w, EventActor* arg);
void balloon_0(EffectWork* w, EventActor* arg);
s32 func_08075720(EffectWork* w);
s32 Exclamation_1(EffectWork* w);
void func_08075780(EffectWork* w);
void func_080757F4(EffectWork* w);
void Question_0(EffectWork* w, EventActor* arg);
s32 Question_1(EffectWork* w);
s32 func_080759B0(EffectWork* w);
void func_080759E0(EffectWork* w);
void func_08075A54(EffectWork* w);
void func_08075A7C(EffectWork* w, EventActor* arg);
s32 func_08075AFC(EffectWork* w);
void func_08075B24(EffectWork* w, EventActor* arg);
s32 func_08075BC4(EffectWork* w);
void down_0(EffectWork* w, EventActor* arg);
s32 down_1(EffectWork* w);
s32 down_2(EffectWork* w);
void down_3(EffectWork* w);
void Tinkerbell_0(EffectWork* w, void* arg);
s32 Tinkerbell_1(EffectWork* w);
void Tinkerbell_2(EffectWork* w);
void Tinkerbell_3(EffectWork* w);
void func_08075E60(EventTaskHost* h);
void func_08075E74(EventTaskHost* h);
void func_08075E88(EventTaskHost* h);
void func_08075E9C(EventTaskHost* h);
void func_08075EB0(EventTaskHost* h);
void func_08075EC4(EventTaskHost* h);
void func_08075ED8(EventTaskHost* h);
void func_08075EEC(EventTaskHost* h);
void func_08075F00(EventTaskHost* h);
void EV_SOUND_0(EvSoundWork* w, u8* arg);
s32 EV_SOUND_1(EvSoundWork* w);
void EV_SOUND_2(void);
void EV_SOUND_3(void);
void func_080760D8(EvSoundWork* w);
s32 func_08076F4C(CardBattleWork* w);
void func_08077E10(CardBattleWork* w);
void func_08077E98(CardBattleWork* w);
void func_08076110(u16 song, s16 x, s16 y);
void Event_Debug_0(u8* work);
s32 Event_Debug_1(u8* work);
void Event_Debug_2(u8* work);
void Event_Debug_3(s32* p);
void func_08076284(void);
void func_08076290(void);
void func_0807629C(void);
u8 func_080762A8(void);
void func_080762B8(void);
void func_080762C4(void);
void func_080762D0(void);
void func_080762DC(void);
void func_080762E8(void);
void func_080762F4(void);
void func_08076300(void);
void func_0807630C(void);
void func_08076318(void);
void func_08076324(void);
void func_08076330(void);
void func_0807633C(void);
void func_08076348(void);
void func_08076354(void);
void func_08076360(void);
void func_08076374(void);
void func_08076388(void);
void func_08076394(void);
void func_080763A0(void);
void func_080763AC(void);
void func_080763B8(void);
void func_080763C4(void);
u8 func_080763D0(void);
void func_080763F0(void);
void func_08076438(void);
u8 func_0807643C(void);
void func_08076458(void);

#endif
