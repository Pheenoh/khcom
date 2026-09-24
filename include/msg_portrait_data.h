#ifndef GUARD_MSG_PORTRAIT_DATA_H
#define GUARD_MSG_PORTRAIT_DATA_H

#include "anim.h"

typedef struct MsgFaceAnim {
    void* tiles;
    void* palette;
    void** gfxTable;
    AnimHeader** anims;
    u8 unk_10;
    u8 unk_11;
    u8 unk_12[2];
} MsgFaceAnim;

extern const MsgFaceAnim* gMsgFaceAnims[62];

#endif
