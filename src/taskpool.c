#include "macros.h"
#include "intr.h"
#include "gba/syscall.h"
#include "key.h"
#include "malloc.h"
#include "main.h"
#include "mode.h"
#include "gba/keys.h"

extern u16 gUnk_03006C78;
extern Mode* gUnk_03007488;
extern void (*gUnk_0300748C)(void);
extern u16 gUnk_03007490;
extern Mode* gUnk_03007494;
extern s32 gUnk_03007498;
extern vu8 gUnk_0300749C;
extern u16 gUnk_0300749E;
extern void (*gUnk_030074A0)(void);
extern void (*gUnk_030074A4)(void);
extern Mode gUnk_09EF4EC0;
extern Mode* gUnk_09ECEAC8[];

Task* func_08000C54(ListNode* node, TaskPool* a);
void func_08000DE8(TaskPool* a, Task* t);
u8 func_08000F48(Task* t);
u8 func_08000F60(Task* t, const char* name);
const char* func_08000F84(Task* t);
void func_08000F94(void);
void func_08000FB4(Mode* mode, s32 arg);
void func_08001010(void);
void func_08001058(void (*a)(void), void (*b)(void));
void func_08001080(void);
void func_0800109C(void (*fn)(void));
void func_080010A8(void);
u8 func_080010B4(void);
void func_080010CC(Mode* mode, s32 arg);
void func_080010E0(Mode* mode, s32 arg);
void func_08001100(void);
void func_08001248(void (*fn)(void));
void func_08001254(void);
void func_080012A8(void);
void func_080012E0(void);
const char* func_080012F8(void);
void func_08001304(void);

u16 _08006338(void);
void VTransReset(void);
void func_08004D74(void);
void func_08001F98(void);
void FadeReset(void);
void func_08006404(void);
void func_08004938(void);
void FlushDma3Queue(void);
void func_08002F50(void);
void CommitDisplayRegs(void);
void func_08005C78(void);
void func_0800642C(void);
void func_08002F0C(void);
u8 func_080078E8(void);
void func_080C57B4(void);
void m4aMPlayAllStop(void);
void func_08116CEC(void);
void* GetEwramHeapStart(void);
u32 GetEwramHeapSize(void);

Task* TaskDestroy(TaskPool* a, Task* t) {
    if (t->unk_00->unk_10 != 0) {
        t->unk_00->unk_10(t->unk_04);
    }

    EwramFree(t->unk_04);

    return func_08000C54(&t->unk_0C, a);
}

void func_08000DE8(TaskPool* a, Task* t) {
    if (t->unk_00->unk_10 != 0) {
        t->unk_00->unk_10(t->unk_04);
    }

    EwramFree(t->unk_04);

    func_08000C54(&t->unk_0C, a);
}

Task* TaskCreate(void* a, TaskDesc* desc, void* arg) {
    Task* task;

    task = func_08000D0C();

    if (task == 0) {
        return 0;
    }

    if (desc->unk_14 > 0) {
        task->unk_04 = EwramAlloc(desc->unk_14);

        if (task->unk_04 == 0) {
            return 0;
        }
    } else {
        task->unk_04 = 0;
    }

    task->unk_00 = desc;
    task->unk_20 = desc->unk_08;
    func_08000BC8(&task->unk_0C, a);

    if (desc->unk_04 != 0) {
        desc->unk_04(task->unk_04, arg);
    }

    return task;
}

void TaskPoolInit(TaskPool* a, s32 count) {
    Task* t;
    s32 i;

    a->unk_10 = EwramAlloc(count * sizeof(Task));

    if (a->unk_10 == 0) {
        return;
    }

    func_08000BA4(a);

    for (i = 0; i < count; i++) {
        t = &((Task*)a->unk_10)[i];
        func_08000BB0(&t->unk_0C, a, t);
    }
}

void TaskPoolUpdate(TaskPool* a) {
    Task* t;

    t = func_08000C8C(&a->head);

    while (t != 0) {
        if (t->unk_20 != 0 && t->unk_20(t->unk_04, t) == 0) {
            t = TaskDestroy(a, t);
        } else {
            t = func_08000CD4(&t->unk_0C);
        }
    }
}

void TaskPoolDraw(TaskPool* a) {
    Task* t;

    t = func_08000C8C(&a->head);

    while (t != 0) {
        if (t->unk_00->unk_0C != 0) {
            t->unk_00->unk_0C(t->unk_04);
        }

        t = func_08000CD4(&t->unk_0C);
    }
}

void TaskPoolDestroy(TaskPool* a) {
    Task* t;

    t = func_08000C8C(&a->head);

    while (t != 0) {
        t = TaskDestroy(a, t);
    }

    EwramFree(a->unk_10);
}

void func_08000F30(TaskPool* a) {
    Task* t;

    t = func_08000C8C(&a->head);

    if (t != 0) {
        do {
            t = func_08000CD4(&t->unk_0C);
        } while (t != 0);
    }
}

u8 func_08000F48(Task* t) {
    if (t == 0 || (t->unk_0C.unk_0C & 1) == 0) {
        return 0;
    }

    return 1;
}

u8 func_08000F60(Task* t, const char* name) {
    if (t == 0 || name == 0 || t->unk_00->name != name || (t->unk_0C.unk_0C & 1) == 0) {
        return 0;
    }

    return 1;
}

const char* func_08000F84(Task* t) {
    return t->unk_00->name;
}

void func_08000F8C(u8* p, u32 v) {
    *(u32*)(p + 32) = v;
}

s32 func_08000F90(void) {
    return 0;
}

void func_08000F94(void) {
    *(vu16*)0x04000000 &= 0xE0FF;
    *(vu16*)0x05000000 = gUnk_0300749E;
}

void func_08000FB4(Mode* mode, s32 arg) {
    gUnk_0300749E = _08006338();
    VTransReset();
    func_08004D74();
    func_08001F98();
    FadeReset();
    func_08006404();
    gUnk_03007488 = mode;

    if (mode->unk_04 != 0) {
        mode->unk_04(arg);
    }

    gUnk_0300748C = gUnk_03007488->unk_08;
    gUnk_0300749C |= 8;
}

void func_08001010(void) {
    gUnk_0300749C = 3;
    gUnk_0300749E = 0;
    gUnk_03007490 = 0;
    func_08000FB4(&gUnk_09EF4EC0, 0);
    gUnk_03007494 = 0;
    gUnk_030074A0 = 0;
    gUnk_030074A4 = 0;
}
void func_08001058(void (*a)(void), void (*b)(void)) {
    if (a != 0) {
        a();
    }

    gUnk_030074A0 = b;
    gUnk_0300749C |= 4;
}

void func_08001080(void) {
    gUnk_0300749C &= ~4;
    gUnk_030074A0 = 0;
}

void func_0800109C(void (*fn)(void)) {
    gUnk_030074A4 = fn;
}

void func_080010A8(void) {
    gUnk_030074A4 = 0;
}

u8 func_080010B4(void) {
    if (gUnk_0300749C & 8) {
        return 1;
    }

    return 0;
}

void func_080010CC(Mode* mode, s32 arg) {
    gUnk_03007494 = mode;
    gUnk_03007498 = arg;
}

void func_080010E0(Mode* mode, s32 arg) {
    gUnk_03007494 = mode;
    gUnk_03007498 = arg;
    gUnk_0300749C |= 0x10;
}
void func_08001100(void) {
    u8 v;

    if ((((GetKeysPressed() & START_BUTTON) && (GetKeysHeld() & SELECT_BUTTON) && (GetKeysHeld() & A_BUTTON) &&
             (GetKeysHeld() & B_BUTTON)) ||
            ((GetKeysHeld() & START_BUTTON) && (GetKeysPressed() & SELECT_BUTTON) && (GetKeysHeld() & A_BUTTON) &&
                (GetKeysHeld() & B_BUTTON))) &&
        !(gUnk_03006C78 & 0x20)) {
        if (func_080078E8()) {
            func_080C57B4();
        }

        m4aMPlayAllStop();
        SoftReset(0xFF);
        func_08116CEC();
    } else {
        if (gUnk_0300749C & 4) {
            return;
        }

        v = gUnk_0300749C & 2;

        if (v != 0) {
            if (gUnk_0300749C & 1) {
                return;
            }

            func_08005C78();
            func_08004938();
            gUnk_0300749C &= ~2;
        } else if (gUnk_03007494 != 0) {
            if (gUnk_03007488->unk_0C != 0) {
                gUnk_03007488->unk_0C();
            }

            if (gUnk_0300749C & 0x10) {
                gUnk_0300749C &= ~0x10;
                EwramHeapInit(GetEwramHeapStart(), GetEwramHeapSize());
            }

            gUnk_0300749C = 3;
            func_08000FB4(gUnk_03007494, gUnk_03007498);
            gUnk_03007494 = 0;
        } else {
            if (gUnk_0300748C != 0) {
                gUnk_0300748C();
            }

            func_08005C78();
            func_0800642C();
            func_08002F0C();
        }
    }
}
void func_08001248(void (*fn)(void)) {
    gUnk_0300748C = fn;
}

void func_08001254(void) {
    if (gUnk_0300749C & 1) {
        func_08000F94();
        gUnk_0300749C &= ~1;
    }

    if (!(gUnk_0300749C & 2)) {
        if (gUnk_03006C78 & 0x10) {
            func_08004938();
        } else {
            FlushDma3Queue();
        }

        func_08002F50();
        CommitDisplayRegs();
    }
}

void func_080012A8(void) {
    if ((gUnk_0300749C & 2) && gUnk_030074A0 != 0) {
        gUnk_030074A0();
    }

    if (gUnk_030074A4 != 0) {
        gUnk_030074A4();
    }
}

void func_080012E0(void) {
    if (gUnk_03007488->unk_0C != 0) {
        gUnk_03007488->unk_0C();
    }
}

const char* func_080012F8(void) {
    return gUnk_03007488->name;
}

void func_08001304(void) {
    if (GetKeysHeld() & SELECT_BUTTON) {
        if (GetKeysPressed() & L_BUTTON) {
            gUnk_03007490--;

            if ((s16)gUnk_03007490 < 0) {
                gUnk_03007490 = 25;
            }

            func_080010CC(gUnk_09ECEAC8[(s16)gUnk_03007490], 0);
        }

        if (GetKeysPressed() & R_BUTTON) {
            gUnk_03007490++;

            if (gUnk_03007490 > 25) {
                gUnk_03007490 = 0;
            }

            func_080010CC(gUnk_09ECEAC8[(s16)gUnk_03007490], 0);
        }
    }
}
