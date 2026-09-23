#include "registration_data.h"
#ifndef GUARD_MODE_DUMMY_H
#define GUARD_MODE_DUMMY_H

#include "mode_battle_data.h"
#include "map_api.h"
#include "msg_api.h"
#include "mode_test_api.h"

#include "fade.h"
#include "display.h"
#include "types.h"
#include "game_state.h"
#include "key.h"
#include "mode.h"
#include "bos4_api.h"
typedef struct DummyEntry {
    const char* name;
    const char* desc;
    u16 unk_08;
} DummyEntry;
extern u32 gFrameCounter;

extern const DummyEntry gDummyEntries[];

void mode_dummy_0(u32 arg);
void func_0800C064(void);
void mode_dummy_1(void);
void mode_dummy_2(void);

#endif /* GUARD_MODE_DUMMY_H */
