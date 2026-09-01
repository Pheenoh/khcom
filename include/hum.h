#ifndef GUARD_HUM_H
#define GUARD_HUM_H

#include "types.h"

typedef struct HumListNode {
    void* unk_00;
    u8 unk_04[0x04];
    struct HumListNode* unk_08;
    u16 unk_0C;
} HumListNode;

typedef struct TaskPool {
    HumListNode head;
    void* unk_10;
} TaskPool;

typedef struct HumActor {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u8 unk_1C;
    u8 unk_1D;
    u8 unk_1E;
    u8 unk_1F;
    u16 unk_20;
    u8 unk_22[0x02];
    s32 unk_24;
    u8 unk_28[0x04];
    s16 unk_2C;
    s16 unk_2E;
    u8 unk_30[0x04];
    u64 unk_34;
    u8 unk_3C[0x04];
    u32 unk_40;
    u8 unk_44[0x04];
    u32 unk_48;
    u32 unk_4C;
    u8 unk_50[0x4C];
    u16 unk_9C;
    u8 unk_9E[0x04];
    u16 unk_A2;
    u8 unk_A4[0x14];
    u32 unk_B8;
    u8 unk_BC[0x12];
    s16 unk_CE;
    s16 unk_D0;
    u16 unk_D2;
    u8 unk_D4[0x3C];
} HumActor;

typedef struct HumWork {
    void* unk_000;
    void* unk_004;
    void* unk_008;
    void* unk_00C;
    void* unk_010;
    u8 unk_014[0x18];
    TaskPool unk_02C;
    HumActor unk_040;
    u16 unk_150;
    u16 unk_152;
    u32 unk_154;
    u32 unk_158;
    u32 unk_15C;
    u32 unk_160;
    u32 unk_164;
    u32 unk_168;
    u32 unk_16C;
    u32 unk_170;
    s16 unk_174;
    u16 unk_176;
    void* unk_178;
    u16 unk_17C;
    u16 unk_17E;
    u32 unk_180;
    u32 unk_184;
} HumWork;

typedef struct CloudWork {
    HumWork base;
    u32 unk_188;
    u16 unk_18C;
    u16 unk_18E;
    u16 unk_190;
    u8 unk_192[0x02];
} CloudWork;

typedef struct HookMoonWork {
    void* unk_00;
    void* unk_04;
    u16 unk_08;
    u8 unk_0A;
    u8 unk_0B;
} HookMoonWork;

typedef struct VixenNdlWork {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x28];
} VixenNdlWork;

typedef struct VixenFrzWork {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x30];
} VixenFrzWork;

typedef struct VixenIceWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C[0x1C];
    u8 unk_28[0x6C];
} VixenIceWork;

typedef struct LexTmh0Work {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x30];
} LexTmh0Work;

typedef struct LexTmhWork {
    void* unk_00;
    void* unk_04;
    u8 unk_08[0x38];
    void* unk_40;
    void* unk_44;
    u8 unk_48[0x04];
} LexTmhWork;

typedef struct MahluxiaFlwWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    u8 unk_0C[0x30];
} MahluxiaFlwWork;

typedef struct LaxeneWork {
    HumWork base;
    u8 unk_188[0x0C];
    TaskPool unk_194;
} LaxeneWork;

typedef struct VixenWork {
    HumWork base;
    u8 unk_188[0x1C];
    TaskPool unk_1A4;
    u8 unk_1B8[0x60];
} VixenWork;

typedef struct LexceusWork {
    HumWork base;
    u8 unk_188[0x50];
    TaskPool unk_1D8;
    u8 unk_1EC[0x18];
} LexceusWork;

extern u8 gUnk_0813EF28[];
extern u8 gUnk_0813EDD0[];

void func_0800E168(HumWork* work, void* def);
void func_0800E380(HumWork* work);
void func_0800EFE8(HumWork* work);
void TaskPoolInit(TaskPool* pool, s32 count);
void TaskPoolDraw(TaskPool* pool);
void TaskPoolUpdate(TaskPool* pool);
void* TaskCreate(TaskPool* pool, void* desc, void* arg);
void TaskPoolDestroy(TaskPool* pool);
void* LoadObjTiles(void* src, s32 size);
void* LoadObjPalette(void* src, s32 size);
void ReleaseObjTiles(void* p);
void ReleaseObjPalette(void* p);
void func_08007E68(s32 a);
void func_08007E7C(void);
void func_0801C298(u8 a, u8 b);
void func_08012304(void* p);
void func_08054100(HumWork* work, void* p);
u8 AnimIsFinished(void* a);
void* AnimUpdate(void* a);
void m4aSongNumStop(u16 n);

#endif /* GUARD_HUM_H */
