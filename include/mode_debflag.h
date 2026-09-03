#ifndef GUARD_MODE_DEBFLAG_H
#define GUARD_MODE_DEBFLAG_H

#include "types.h"
#include "key.h"
#include "mode.h"
typedef struct DebugFlag {
    const char* name;
    u32 mask;
} DebugFlag;

extern s8 gUnk_020348C0;
extern s8 gUnk_020348C1;
extern const DebugFlag* gUnk_020348C4;
extern u8 gUnk_02039B94;
extern u32 gUnk_03006C10;
extern u8 gUnk_08128304[];
extern const DebugFlag gUnk_08130BE8[];
extern const DebugFlag gUnk_08130DE0[];
extern Mode gUnk_09ECEB64;

void ModeRequest(Mode* mode, s32 arg);
u16 GetKeysRepeat(void);
void func_08004DB0(void);
void EnableBg(s32 a);
void SetupBg(s32 bg, u8 charBase, u8 screenBase, u8 palette);
void func_0805FA60(s32 a, void* b, s32 c, s32 d);
void func_0805FA8C(s32 a, u16 b, u16 c);
void func_0805FCB0(u8 x, u8 y, u8 c, const char* s);
void func_08060598(void);
void func_080605A4(s32 a);
void func_080609A0(void);
void func_080E04EC(void);

void mode_debflag_0(s32 arg);
void mode_debflag_1(void);
void mode_debflag_2(void);

#endif /* GUARD_MODE_DEBFLAG_H */
