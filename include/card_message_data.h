#ifndef GUARD_CARD_MESSAGE_DATA_H
#define GUARD_CARD_MESSAGE_DATA_H

#include "text_types.h"

#ifdef VERSION_US
typedef u16 CardMessageText;
#elif defined(VERSION_JP)
typedef u8 CardMessageText;
#else
typedef LocalizedText CardMessageText;
#endif

typedef struct CardMessageDef {
    s32 portraitId;
    s32 positionIndex;
    u16 expressionId;
    u8 unk_0A;
    u8 unk_0B;
    const CardMessageText* text;
    u16 flags;
    u16 unk_12;
} CardMessageDef;

extern CardMessageDef gCardMessageDefs[];

#endif
