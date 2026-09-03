#ifndef GUARD_ROOM_H
#define GUARD_ROOM_H

#include "types.h"

typedef struct RoomNameWork {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    u8 unk_28;
    u8 unk_29;
    u16 unk_2A;
    u16 unk_2C;
    u8 unk_2E[0x2];
    s32 unk_30;
    u8 unk_34;
    u8 unk_35[0x3];
    void* unk_38;
    u8 unk_3C[0x120];
} RoomNameWork;

typedef struct RoomFld {
    u8 unk_00[0x70];
    u32 unk_70;
} RoomFld;

extern RoomFld* gUnk_02039BA0;

extern s16 gSineTable[];
extern s32 gUnk_0999204C[];
extern u8 gUnk_0993AF64[];
extern u8 gUnk_099910C4[];
extern void* gUnk_09EF8DA4;
extern void* gUnk_09EF7048[];

void* LoadObjTiles(void* a, s32 b);
void* LoadObjPalette(void* a, s32 b);
void ReleaseObjTiles(void* a);
void ReleaseObjPalette(void* a);
s32 AllocObjAffine(s32 a, s32 b, s32 c, s32 d);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, s32 g, u16 h);
void func_08065ACC(void* a, s32 b);
void func_08065AE0(void* a, s32 b);
u8 func_08065B6C(void* a, void* b);
void* _08066468(s32 a);
void func_080664D8(s16 a, s16 b, void* c, void* d, s32 e, u8 f);

typedef struct RoomAnimHeader {
    u32 unk_00;
    u16 unk_04;
    u16 unk_06;
} RoomAnimHeader;

typedef struct RoomAnimFrame {
    u16 unk_00;
    u16 unk_02;
} RoomAnimFrame;

typedef struct RoomAnimState {
    RoomAnimHeader** unk_00;
    u32* unk_04;
    u16 unk_08;
    u16 unk_0A;
    u16 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    u16 unk_12;
    RoomAnimFrame* unk_14;
} RoomAnimState;

typedef struct RoomListNode {
    void* unk_00;
    u8 unk_04[0x04];
    struct RoomListNode* unk_08;
    u16 unk_0C;
    u8 unk_0E[0x02];
} RoomListNode;

typedef struct RoomTaskPool {
    RoomListNode head;
    void* unk_10;
} RoomTaskPool;

typedef struct RoomEntry {
    s32 unk_000;
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
    u8 unk_010[0x24];
    u64 unk_034;
    u8 unk_03C[0x04];
    u8 unk_040[0x60];
    u16 unk_0A0;
    u8 unk_0A2[0x70];
    u8 unk_112;
    u8 unk_113[0x09];
    s32 unk_11C;
    s32 unk_120;
    s32 unk_124;
    s32 unk_128;
    s32 unk_12C;
    s32 unk_130;
    s32 unk_134;
    s32 unk_138;
    s32 unk_13C;
    s32 unk_140;
    s32 unk_144;
    u8 unk_148[0x10];
    u8 unk_158;
    u8 unk_159;
    u16 unk_15A;
    u16 unk_15C;
    u16 unk_15E;
    u16 unk_160;
    u8 unk_162[0x02];
    s32 unk_164;
    s32 unk_168;
    RoomTaskPool unk_16C;
    RoomAnimState unk_180;
    void* unk_198;
    void* unk_19C;
    u32 unk_1A0;
    u8 unk_1A4;
    u8 unk_1A5[0x03];
} RoomEntry;

typedef struct RoomWork {
    s32 unk_000;
    s32 unk_004;
    u32 unk_008;
    u16 unk_00C;
    u16 unk_00E;
    s16 unk_010;
    s16 unk_012;
    s16 unk_014;
    u8 unk_016[0x02];
    s32 unk_018;
    u8 unk_01C;
    u8 unk_01D[0x03];
    RoomEntry entries[6];
    RoomAnimState unk_A10;
    void* unk_A28;
    void* unk_A2C;
    void* unk_A30;
    void* unk_A34;
    s32 unk_A38;
    s32 unk_A3C;
    s32 unk_A40;
    s32 unk_A44;
    s32 unk_A48;
    s32 unk_A4C;
    u16 unk_A50;
    u8 unk_A52;
    u8 unk_A53;
} RoomWork;

typedef struct RoomTableEntry {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u16 unk_10;
    u16 unk_12;
    void* unk_14;
    void* unk_18;
    void* unk_1C;
    u16 unk_20;
    u16 unk_22;
} RoomTableEntry;

extern RoomWork* gUnk_02034FE8;
extern s32 gUnk_09991F44[];
extern RoomTableEntry gUnk_09991F54[];
extern u8 gTaskDescBtlShadow[];
extern u8 gUnk_09EF9728[];
extern u8 gUnk_099999AC[];
extern u8 gUnk_09EF9738[];

typedef struct RoomB84 {
    s32 unk_000;
    s32 unk_004;
    u8 unk_008[0x74];
    s32* unk_07C;
    u8 unk_080[0x20];
    s32 unk_0A0;
    u8 unk_0A4[0x28];
    s32 unk_0CC;
    s32 unk_0D0;
    s32 unk_0D4;
} RoomB84;

extern RoomB84* gUnk_02039B84;

u16 GetRandom(void);
void* AllocObjTiles(s32 a, void* b);
u16 func_08003524(void* a, s32 b);
void AnimInit(RoomAnimState* a, void* b, void* c);
void AnimStart(RoomAnimState* a, u16 animId, u16 flags);
void* AnimGetGfx(RoomAnimState* a);
void TaskPoolInit(RoomTaskPool* a, s32 count);
void TaskPoolDestroy(RoomTaskPool* a);
void TaskPoolDraw(RoomTaskPool* a);
void* TaskCreate(RoomTaskPool* a, void* desc, void* arg);
void m4aSongNumStart(u16 a);
void func_080122AC(void* a, s32 b, s32 c, s32 d);
void func_08012304(void* a);
void func_0801A8A4(void* a, void* b, s32 c, s32 d);
void func_0801B37C(void* a, void* b, s32 c, s32 d, s32 e);
void func_0801B7D8(void* a);
void func_0801C7FC(void* a, s32 b, s32 c);
void func_0801BCD4(void* a);
s32 func_08002C28(u8 a, s32 b);
u16 func_0801AF1C(s32 a);
u8 func_0801CA00(void* a);
void WorldToScreen(u16* a, u16* b, s32 c, s32 d, s32 e);
void func_0802F1E8(void);
s32 func_08011F78(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void func_0801AF08(void* a);

s32 func_080F7F70(RoomWork* work, s16 i);
s32 func_080F7F94(RoomWork* work, s16 i);
s32 func_080F7FAC(RoomWork* work, s16 i);
s32 func_080F7FC8(RoomWork* work, s16 i);
s32 func_080F7FE4(RoomWork* work, s16 i);
void func_080F800C(RoomWork* work, s32 i);
void func_080F80C0(RoomWork* work);
void func_080F7F54(RoomWork* work, s32 state);
void func_080F7E84(RoomEntry* e);
void func_080F80FC(RoomWork* work, u32 i, s32 c);
void func_080F8374(RoomEntry* e);
void func_080F83BC(void);
u8 func_080F8958(RoomWork* work);
void func_080F83E0(RoomWork* work, RoomEntry* e);
u8 func_080FAA18(RoomWork* work);
u8 func_080F99C0(RoomWork* work);
u8 func_080F9C2C(RoomWork* work);
u8 func_080F9744(RoomWork* work);

u16 func_080F7DD8(s32 a);
s32 func_080F7E0C(s32 a, s32 b, s32 c, s32 d);

void task_room_name_0(RoomNameWork* work, s32 arg);
u8 task_room_name_1(RoomNameWork* work);
void task_room_name_2(RoomNameWork* work);
void task_room_name_3(RoomNameWork* work);

#endif /* GUARD_ROOM_H */
