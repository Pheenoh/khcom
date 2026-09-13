#ifndef GUARD_SYSTEM_STATE_H
#define GUARD_SYSTEM_STATE_H

#include "types.h"
#include "intr.h"

extern vu16 gFrameSyncFlags;
extern u16 gVBlankEndVCount;
extern u32 gUnk_03006C04[3];
extern u32 gUnk_03006C10;
extern IntrFunc* gIntrTableSerial;
extern u32 gUnk_03006C18[2];
extern IntrFunc gIntrTable[14];
extern IntrFunc* gIntrTableVCount;
extern IntrFunc* gIntrTableVBlank;
extern IntrFunc* gIntrTableTimer3;
extern IntrFunc gHBlankCallback;
extern u32 gVBlankCounter;
extern IntrFunc gVCountCallback;
extern IntrFunc gVBlankCallback;
extern IntrFunc* gIntrTableHBlank;
extern u16 gSystemFlags;
extern u8 gUnk_03006C7A[6];
extern u8 gIntrHandler[0x800];
extern u32 gFrameCounter;
#ifdef VERSION_EU
extern u32 gLanguage;
#endif

#endif
