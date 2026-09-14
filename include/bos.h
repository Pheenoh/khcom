#include "boss_background_types.h"
#ifndef GUARD_BOS_H
#define GUARD_BOS_H

#include "bos_tasks.h"

#include "types.h"
#include "game.h"

typedef struct BosShadowWork {
    void* tiles;
    void* palette;
    BtlObj* actor;
} BosShadowWork;


#endif /* GUARD_BOS_H */
