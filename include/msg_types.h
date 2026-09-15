#ifndef GUARD_MSG_TYPES_H
#define GUARD_MSG_TYPES_H

#include "types.h"

typedef struct EventCameraKeyframe {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10;
    u8 unk_11[3];
    u32 unk_14;
    u16 unk_18;
    u8 unk_1A[2];
    void* unk_1C;
} EventCameraKeyframe;

typedef struct MessageScriptEntry {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u8 unk_0C;
    u8 unk_0D[3];
    u32 unk_10;
    u16 unk_14;
    u16 unk_16;
} MessageScriptEntry;

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

typedef struct EventCharaTrack {
    EventCharaKeyframe* keyframes;
    u8 unk_04;
    u8 unk_05[3];
} EventCharaTrack;

typedef struct EvSoundCue {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
} EvSoundCue;

typedef struct EventBgEffectEntry {
    u8 unk_00[0x02];
    u16 unk_02;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C[0x04];
} EventBgEffectEntry;

typedef struct EventSequenceDef {
    u8 unk_00;
    u8 unk_01[3];
    EventCharaTrack* charaTracks;
    EventCameraKeyframe* keyframes;
    MessageScriptEntry* script;
    EvSoundCue* soundCues;
    EventBgEffectEntry* bgEffects;
    u16 unk_18;
    u8 unk_1A;
    u8 unk_1B;
    u8 unk_1C;
    u8 unk_1D;
    u8 unk_1E;
    u8 unk_1F;
    u16 unk_20;
    u16 unk_22;
    u16 unk_24;
    u8 unk_26[2];
    u16 unk_28;
    u8 unk_2A;
    u8 unk_2B;
    u8 unk_2C;
} EventSequenceDef;

extern EventSequenceDef* gUnk_09EE3FB4[];

typedef struct MsgFaceControl {
    u8 portraitId;
    u8 expressionId;
    u8 command;
    u8 unk_03;
    u32 positionIndex;
    u8 unk_08;
} MsgFaceControl;

#endif
