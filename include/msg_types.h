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

typedef struct EventCharaTrack {
    struct EventCharaKeyframe* unk_00;
    u8 unk_04;
    u8 unk_05[3];
} EventCharaTrack;

typedef struct EventSequenceDef {
    u8 unk_00;
    u8 unk_01[3];
    EventCharaTrack* unk_04;
    EventCameraKeyframe* unk_08;
    MessageScriptEntry* unk_0C;
    void* unk_10;
    void* unk_14;
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
