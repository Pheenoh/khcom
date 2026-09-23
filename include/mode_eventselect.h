#include "event_index_data.h"
#include "card_localized_data.h"
#include "card_localized_09EE9C90_data.h"
#include "card_lookup_09EEA344_data.h"
#include "card_sprite_data.h"
#include "registration_data.h"
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

typedef struct DownWork {
    s32 unk_00[8];
    s32 unk_20[8];
    u8 unk_40[8];
    u16 angle[8];
} DownWork;

typedef struct EvSoundWork {
    const EvSoundCue* soundCues;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    s32 unk_08;
} EvSoundWork;

typedef struct EventTaskHost {
    u8 unk_00[0x10];
    TaskPool tasks;
} EventTaskHost;

typedef struct EventBody {
    s32 unk_00;
    s32 x;
    s32 y;
    s32 z;
} EventBody;

typedef struct EventActor {
    u8 unk_00[0x26];
    u8 unk_26;
    u8 unk_27;
    EventBody body;
    u8 unk_38[0x06];
    u16 unk_3E;
    u8 unk_40[0x172];
    u8 unk_1B2;
} EventActor;

typedef struct EffectWork {
    EventActor* actor;
    void* tiles;
    void* palette;
    void* gfx;
    DownWork* down;
    AnimState anim;
    s32 x;
    s32 y;
    s32 z;
    s32 z2;
    s32 vx;
    s32 vz;
    u16 unk_44;
    u16 unk_46;
    u8 unk_48;
    u8 unk_49;
    u8 unk_4A[0x02];
    TaskPool tasks;
} EffectWork;

extern EventState* gUnk_02039DC8;
extern u8 gUnk_08F6DC84[];
extern u8 gUnk_08BCB3D8[];
extern s16 gUnk_0903380C[][6];
extern const char gUnk_08F70990[];
#ifdef VERSION_EU
extern Mode gUnkEu_09F5D6EC;
#endif

u8 FormatSmallFontDecimal(s32 a, void* b);

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
void CreateDownTask(EventTaskHost* h);
void CreateSmokeTask(EventTaskHost* h);
void CreateExclamationTask(EventTaskHost* h);
void CreateBalloonTask(EventTaskHost* h);
void CreateQuestionTask(EventTaskHost* h);
void CreateGlowNoseTask(EventTaskHost* h);
void CreateGlowNose2Task(EventTaskHost* h);
void CreateHanabiraTask(EventTaskHost* h);
void EV_SOUND_0(EvSoundWork* w, u8* arg);
s32 EV_SOUND_1(EvSoundWork* w);
void EV_SOUND_2(void);
void EV_SOUND_3(void);
void func_080760D8(EvSoundWork* w);
void Event_Debug_0(u8* work);
s32 Event_Debug_1(u8* work);
void Event_Debug_2(u8* work);
void Event_Debug_3(s32* p);

s16 func_08075064(u8 a);

#endif
