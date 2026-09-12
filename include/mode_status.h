#ifndef GUARD_MODE_STATUS_H
#define GUARD_MODE_STATUS_H

#include "map_api.h"
#include "mode_status_api.h"

#include "mode_copyright2.h"

#include "display.h"
#include "fade.h"
#include "types.h"
#include "game_state.h"
#include "taskpool.h"
#include "main.h"
#include "engine.h"

extern u8 gUnk_097FFB98[];
extern u8 gUnk_0984B118[];
extern u8 gUnk_09848198[];
extern u8 gUnk_09847C98[];
extern u8 gUnk_09847798[];
extern u8 gUnk_09848B98[];
extern TaskDesc gTaskDescStatusBar;
extern TaskDesc gTaskDescStatus;

void mode_status_0(void);
void mode_status_1(void);
void mode_status_2(void);

#endif /* GUARD_MODE_STATUS_H */
