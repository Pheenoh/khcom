#ifndef GUARD_CARD_LABEL_DATA_H
#define GUARD_CARD_LABEL_DATA_H

#include "card_ui_types.h"

typedef struct UnkStruct_08F7CBA8 {
#ifdef VERSION_EU
    void** unk_00;
    void*** unk_08;
#else
    void* unk_00;
    u32 unk_04;
    void** unk_08;
#endif
    u16 unk_0C;
    u16 unk_0E;
} UnkStruct_08F7CBA8;

extern UnkStruct_08F7CBA8 gUnk_08F7CBA8[];
extern SpriteFrameResourceDef gUnk_08F7CF18[];

#endif
