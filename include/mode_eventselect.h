#ifndef GUARD_MODE_EVENTSELECT_H
#define GUARD_MODE_EVENTSELECT_H

#include "card_api.h"

#include "msg_api.h"
#include "mode_test_api.h"

#include "eventselect_api.h"

#include "text.h"
#include "fade.h"
#include "obj_api.h"
#include "display.h"
#include "types.h"
#include "engine_math.h"
#include "listpool.h"
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

typedef struct EventCardLink {
    u8 unk_00[0x3C];
    CardSlot* slot;
    u8 unk_40[0x24];
    u8 node[0x14];
} EventCardLink;

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
extern u8 gUnk_088A5D7A[];
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
extern TaskDesc gTaskDescGlowNose;
extern TaskDesc gTaskDescGlowNose2;
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
#ifdef VERSION_EU
extern Mode gUnkEu_09F5D6EC;
#endif

extern TaskDesc gUnk_09EE4984[];

u8 FormatSmallFontDecimal(s32 a, void* b);
u16 func_080787B8(CardBattleWork* w, u8 n);
s32 func_08077F44(UnkStruct_08080268* w, u8* task);
void func_0807682C(UnkStruct_08080268* w, u8 slot);

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
void EffectDrawObj(EffectWork* w);
void EffectReleaseObj(EffectWork* w);
void Question_0(EffectWork* w, EventActor* arg);
void func_080758D0(EffectWork* w, EventActor* arg);
s32 Question_1(EffectWork* w);
s32 func_080759B0(EffectWork* w);
void func_080759E0(EffectWork* w);
void func_08075A54(EffectWork* w);
void GlowNose_0(EffectWork* w, EventActor* arg);
s32 GlowNose_1(EffectWork* w);
void GlowNose2_0(EffectWork* w, EventActor* arg);
s32 GlowNose2_1(EffectWork* w);
void down_0(EffectWork* w, EventActor* arg);
s32 down_1(EffectWork* w);
s32 down_2(EffectWork* w);
void down_3(EffectWork* w);
void Tinkerbell_0(EffectWork* w, void* arg);
s32 Tinkerbell_1(EffectWork* w);
void Tinkerbell_2(EffectWork* w);
void Tinkerbell_3(EffectWork* w);
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
void Event_Debug_0(u8* work);
s32 Event_Debug_1(u8* work);
void Event_Debug_2(u8* work);
void Event_Debug_3(s32* p);
u8 func_080762A8(void);
void func_08076354(void);
void func_08076388(void);
void func_080763A0(void);
void func_080763AC(void);
void func_080763B8(void);
void func_080763C4(void);
void func_08076438(void);
void func_08076458(void);

#endif
