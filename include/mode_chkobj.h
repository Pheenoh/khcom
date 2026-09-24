#include "registration_data.h"
#ifndef GUARD_MODE_CHKOBJ_H
#define GUARD_MODE_CHKOBJ_H

#include "card_api.h"

#include "mode_test_api.h"

#include "display.h"
#include "anim.h"
#include <stdlib.h>
#include "obj_api.h"
#include "types.h"
#include "engine_math.h"
#include "taskpool.h"
#include "chkobj.h"
#include "main.h"
#include "engine.h"
#include "mode.h"
#include "key.h"

typedef struct ChkObjEntry {
    ObjDef* defs;
    u16 count;
    u16 unk_06;
    const char* name;
} ChkObjEntry;

void func_0800B30C(ObjDef* def);
void mode_chkobj_0(void);
void mode_chkobj_1(void);
void mode_chkobj_2(void);

extern ChkObjWork* gChkObjWork;
extern u8 gUnk_088B629C[];
extern const ChkObjEntry gChkObjEntries[];
extern u8 gUnk_08F683A4[];

#endif /* GUARD_MODE_CHKOBJ_H */
