#ifndef GUARD_UTIL_H
#define GUARD_UTIL_H

#include "types.h"

typedef struct KeyState {
    u16 held;
    u16 trg;
    u16 rep;
    u16 unk_6;
    u8 on[10];
    u8 off[10];
} KeyState;

extern KeyState* gUnk_0203407C;
extern KeyState* gUnk_02034080;
extern u16 gUnk_02034084;

u16 KeyGetHeld(KeyState* k);
u16 KeyGetPressed(KeyState* k);
u16 KeyGetRepeat(KeyState* k);
void KeyStateClear(KeyState* k);
u8 KeyGetHoldFrames(KeyState* k, u16 key);
u8 KeyGetOffFrames(KeyState* k, u16 key);
u16 func_0800846C(KeyState* k, u16 a, u16 b);
void KeyStateUpdate(KeyState* k, u16 keys);
void SioKeyInit(void);
void SioKeyFree(void);
u16 func_0800886C(void);
u16 func_08008884(void);
u16 func_0800889C(void);
u16 func_080088B4(void);
u16 func_080088CC(void);
u16 func_080088E4(void);
u16 func_080088FC(u16 a, u16 b);
u16 func_08008920(u16 a, u16 b);
void func_08008944(u16 keys);
void func_0800895C(u16 keys);
s32 IsSongPlaying(u16 songNum);
void StopSong(u16 songNum);

#endif
