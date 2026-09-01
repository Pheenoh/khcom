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

u16 func_0800833C(KeyState* k);
u16 func_08008340(KeyState* k);
u16 func_08008344(KeyState* k);
void func_08008348(KeyState* k);
u8 func_08008384(KeyState* k, u16 key);
u8 func_080083F8(KeyState* k, u16 key);
u16 func_0800846C(KeyState* k, u16 a, u16 b);
void func_08008558(KeyState* k, u16 keys);
void func_08008808(void);
void func_0800884C(void);
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
s32 func_08008974(u16 songNum);
void func_080089A8(u16 songNum);

#endif
