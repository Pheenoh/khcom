#ifndef GUARD_MODE_CHKEFF_H
#define GUARD_MODE_CHKEFF_H

#include "card_api.h"

#include "fade.h"
#include "display.h"
#include "types.h"
#include "taskpool.h"
#include "main.h"
#include "mode.h"
#include "key.h"

typedef struct ChkEffWork {
    TaskPool pool;
    s16 unk_14;
    u8 paused;
    u8 unk_17;
    u16 scrollX;
    u16 scrollY;
    u8 unk_1C;
    u8 unk_1D[0x03];
    s32 scale;
    u16 alphaA;
    u16 alphaB;
} ChkEffWork;

void mode_chkeff_0(void);
void mode_chkeff_1(void);
void mode_chkeff_2(void);
extern u32 gFrameCounter;
extern u8 gUnk_08C6B0C4[];
extern u8 gUnk_08EEE384[];
extern u8 gUnk_08F683C4[];
extern void* gUnk_09ED9A1C[];
extern TaskDesc gTaskDescPrint;
extern const char gUnk_081309E0[];
extern const char gUnk_081309E8[];
extern const char gUnk_081309F0[];
extern const char gUnk_08130A18[];
extern const char gUnk_08130A20[];
extern const char gUnk_08130A28[];
extern const char gUnk_08130A30[];
extern const char gUnk_08130A34[];
extern const char gUnk_08130A38[];

#endif /* GUARD_MODE_CHKEFF_H */
