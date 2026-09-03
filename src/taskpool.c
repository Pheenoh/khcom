#include "macros.h"
#include "intr.h"
#include "gba/syscall.h"
#include "key.h"
#include "malloc.h"
#include "main.h"
#include "mode.h"
#include "gba/keys.h"

extern u16 gSystemFlags;
Mode* gCurrentMode;
void (*gCurrentModeUpdate)(void);
u16 gDebugModeIndex;
Mode* gPendingMode;
s32 gPendingModeArg;
vu8 gModeFlags;
u16 gUnk_0300749E;
void (*gUnk_030074A0)(void);
void (*gUnk_030074A4)(void);
#ifdef VERSION_EU
u32 gUnkEu_030074AC;
#endif
extern Mode gModeCopyright1;
extern Mode* gDebugModes[];

Task* ListPoolRelease(ListNode* node, TaskPool* a);
void func_08000DE8(TaskPool* a, Task* t);
u8 IsTaskActive(Task* t);
u8 IsTaskActiveNamed(Task* t, const char* name);
const char* GetTaskName(Task* t);
void func_08000F94(void);
void ModeStart(Mode* mode, s32 arg);
void ModeInit(void);
void func_08001058(void (*a)(void), void (*b)(void));
void func_08001080(void);
void func_0800109C(void (*fn)(void));
void func_080010A8(void);
u8 IsModeStarted(void);
void ModeRequest(Mode* mode, s32 arg);
void ModeRequestHeapReset(Mode* mode, s32 arg);
void ModeUpdate(void);
void SetModeUpdate(void (*fn)(void));
void func_08001254(void);
void func_080012A8(void);
void func_080012E0(void);
const char* GetModeName(void);
void UpdateDebugModeSelect(void);

u16 _08006338(void);
void VTransReset(void);
void BgReset(void);
void SpriteReset(void);
void FadeReset(void);
void MosaicReset(void);
void func_08004938(void);
void FlushDma3Queue(void);
void func_08002F50(void);
void CommitDisplayRegs(void);
void func_08005C78(void);
void MosaicUpdate(void);
void SortSprites(void);
u8 func_080078E8(void);
void func_080C57B4(void);
void m4aMPlayAllStop(void);
void func_08116CEC(void);
void* GetEwramHeapStart(void);
u32 GetEwramHeapSize(void);

Task* TaskDestroy(TaskPool* a, Task* t) {
    if (t->desc->destroy != 0) {
        t->desc->destroy(t->work);
    }

    EwramFree(t->work);

    return ListPoolRelease(&t->node, a);
}

void func_08000DE8(TaskPool* a, Task* t) {
    if (t->desc->destroy != 0) {
        t->desc->destroy(t->work);
    }

    EwramFree(t->work);

    ListPoolRelease(&t->node, a);
}

Task* TaskCreate(void* a, TaskDesc* desc, void* arg) {
    Task* task;

    task = ListPoolFirstFree();

    if (task == 0) {
        return 0;
    }

    if (desc->workSize > 0) {
        task->work = EwramAlloc(desc->workSize);

        if (task->work == 0) {
            return 0;
        }
    } else {
        task->work = 0;
    }

    task->desc = desc;
    task->update = desc->update;
    ListPoolActivate(&task->node, a);

    if (desc->init != 0) {
        desc->init(task->work, arg);
    }

    return task;
}

void TaskPoolInit(TaskPool* a, s32 count) {
    Task* t;
    s32 i;

    a->tasks = EwramAlloc(count * sizeof(Task));

    if (a->tasks == 0) {
        return;
    }

    ListPoolInit(a);

    for (i = 0; i < count; i++) {
        t = &((Task*)a->tasks)[i];
        ListPoolAddFree(&t->node, a, t);
    }
}

void TaskPoolUpdate(TaskPool* a) {
    Task* t;

    t = ListPoolFirst(&a->head);

    while (t != 0) {
        if (t->update != 0 && t->update(t->work, t) == 0) {
            t = TaskDestroy(a, t);
        } else {
            t = ListPoolNext(&t->node);
        }
    }
}

void TaskPoolDraw(TaskPool* a) {
    Task* t;

    t = ListPoolFirst(&a->head);

    while (t != 0) {
        if (t->desc->draw != 0) {
            t->desc->draw(t->work);
        }

        t = ListPoolNext(&t->node);
    }
}

void TaskPoolDestroy(TaskPool* a) {
    Task* t;

    t = ListPoolFirst(&a->head);

    while (t != 0) {
        t = TaskDestroy(a, t);
    }

    EwramFree(a->tasks);
}

void func_08000F30(TaskPool* a) {
    Task* t;

    t = ListPoolFirst(&a->head);

    if (t != 0) {
        do {
            t = ListPoolNext(&t->node);
        } while (t != 0);
    }
}

u8 IsTaskActive(Task* t) {
    if (t == 0 || (t->node.flags & 1) == 0) {
        return 0;
    }

    return 1;
}

u8 IsTaskActiveNamed(Task* t, const char* name) {
    if (t == 0 || name == 0 || t->desc->name != name || (t->node.flags & 1) == 0) {
        return 0;
    }

    return 1;
}

const char* GetTaskName(Task* t) {
    return t->desc->name;
}

void SetTaskUpdate(u8* p, u32 v) {
    *(u32*)(p + 32) = v;
}

s32 func_08000F90(void) {
    return 0;
}

void func_08000F94(void) {
    *(vu16*)0x04000000 &= 0xE0FF;
    *(vu16*)0x05000000 = gUnk_0300749E;
}

void ModeStart(Mode* mode, s32 arg) {
    gUnk_0300749E = _08006338();
    VTransReset();
    BgReset();
    SpriteReset();
    FadeReset();
    MosaicReset();
    gCurrentMode = mode;

    if (mode->init != 0) {
        mode->init(arg);
    }

    gCurrentModeUpdate = gCurrentMode->update;
    gModeFlags |= 8;
}

#ifndef VERSION_EU
void ModeInit(void) {
    gModeFlags = 3;
    gUnk_0300749E = 0;
    gDebugModeIndex = 0;
    ModeStart(&gModeCopyright1, 0);
    gPendingMode = 0;
    gUnk_030074A0 = 0;
    gUnk_030074A4 = 0;
}
#else
INCLUDE_ASM("taskpool/ModeInit.s");
#endif
void func_08001058(void (*a)(void), void (*b)(void)) {
    if (a != 0) {
        a();
    }

    gUnk_030074A0 = b;
    gModeFlags |= 4;
}

void func_08001080(void) {
    gModeFlags &= ~4;
    gUnk_030074A0 = 0;
}

void func_0800109C(void (*fn)(void)) {
    gUnk_030074A4 = fn;
}

void func_080010A8(void) {
    gUnk_030074A4 = 0;
}

u8 IsModeStarted(void) {
    if (gModeFlags & 8) {
        return 1;
    }

    return 0;
}

void ModeRequest(Mode* mode, s32 arg) {
    gPendingMode = mode;
    gPendingModeArg = arg;
}

#ifndef VERSION_EU
void ModeRequestHeapReset(Mode* mode, s32 arg) {
    gPendingMode = mode;
    gPendingModeArg = arg;
    gModeFlags |= 0x10;
}
#else
INCLUDE_ASM("taskpool/ModeRequestHeapReset.s");
#endif

#ifdef VERSION_EU
INCLUDE_ASM("taskpool/eu_0800115C.s");
#endif

#ifndef VERSION_EU
void ModeUpdate(void) {
    u8 v;

    if ((((GetKeysPressed() & START_BUTTON) && (GetKeysHeld() & SELECT_BUTTON) && (GetKeysHeld() & A_BUTTON) &&
             (GetKeysHeld() & B_BUTTON)) ||
            ((GetKeysHeld() & START_BUTTON) && (GetKeysPressed() & SELECT_BUTTON) && (GetKeysHeld() & A_BUTTON) &&
                (GetKeysHeld() & B_BUTTON))) &&
        !(gSystemFlags & 0x20)) {
        if (func_080078E8()) {
            func_080C57B4();
        }

        m4aMPlayAllStop();
        SoftReset(0xFF);
        func_08116CEC();
    } else {
        if (gModeFlags & 4) {
            return;
        }

        v = gModeFlags & 2;

        if (v != 0) {
            if (gModeFlags & 1) {
                return;
            }

            func_08005C78();
            func_08004938();
            gModeFlags &= ~2;
        } else if (gPendingMode != 0) {
            if (gCurrentMode->exit != 0) {
                gCurrentMode->exit();
            }

            if (gModeFlags & 0x10) {
                gModeFlags &= ~0x10;
                EwramHeapInit(GetEwramHeapStart(), GetEwramHeapSize());
            }

            gModeFlags = 3;
            ModeStart(gPendingMode, gPendingModeArg);
            gPendingMode = 0;
        } else {
            if (gCurrentModeUpdate != 0) {
                gCurrentModeUpdate();
            }

            func_08005C78();
            MosaicUpdate();
            SortSprites();
        }
    }
}
#else
INCLUDE_ASM("taskpool/ModeUpdate.s");
#endif
void SetModeUpdate(void (*fn)(void)) {
    gCurrentModeUpdate = fn;
}

void func_08001254(void) {
    if (gModeFlags & 1) {
        func_08000F94();
        gModeFlags &= ~1;
    }

    if (!(gModeFlags & 2)) {
        if (gSystemFlags & 0x10) {
            func_08004938();
        } else {
            FlushDma3Queue();
        }

        func_08002F50();
        CommitDisplayRegs();
    }
}

void func_080012A8(void) {
    if ((gModeFlags & 2) && gUnk_030074A0 != 0) {
        gUnk_030074A0();
    }

    if (gUnk_030074A4 != 0) {
        gUnk_030074A4();
    }
}

void func_080012E0(void) {
    if (gCurrentMode->exit != 0) {
        gCurrentMode->exit();
    }
}

const char* GetModeName(void) {
    return gCurrentMode->name;
}

#ifndef VERSION_EU
void UpdateDebugModeSelect(void) {
    if (GetKeysHeld() & SELECT_BUTTON) {
        if (GetKeysPressed() & L_BUTTON) {
            gDebugModeIndex--;

            if ((s16)gDebugModeIndex < 0) {
                gDebugModeIndex = 25;
            }

            ModeRequest(gDebugModes[(s16)gDebugModeIndex], 0);
        }

        if (GetKeysPressed() & R_BUTTON) {
            gDebugModeIndex++;

            if (gDebugModeIndex > 25) {
                gDebugModeIndex = 0;
            }

            ModeRequest(gDebugModes[(s16)gDebugModeIndex], 0);
        }
    }
}
#else
INCLUDE_ASM("taskpool/UpdateDebugModeSelect.s");
#endif
