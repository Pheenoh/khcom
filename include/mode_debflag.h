#ifndef GUARD_MODE_DEBFLAG_H
#define GUARD_MODE_DEBFLAG_H

#include "mode_test_api.h"

#include "types.h"
#include "key.h"
#include "mode.h"
#include "engine.h"
typedef struct DebugFlag {
    const char* name;
    u32 mask;
} DebugFlag;
extern u8 gUnk_02039B94;
extern u32 gUnk_03006C10;
extern u8 gWhitePalette[];
extern const DebugFlag gUnk_08130BE8[];
extern const DebugFlag gUnk_08130DE0[];

void func_080E04EC(void);

void mode_debflag_0(s32 arg);
void mode_debflag_1(void);
void mode_debflag_2(void);

#endif /* GUARD_MODE_DEBFLAG_H */
