#ifndef GUARD_BOSS_TM_H
#define GUARD_BOSS_TM_H

#include "types.h"
#include "battle_actor_types.h"
#include "anim.h"
#include "taskpool.h"

typedef struct TmWork {
    u16 x;
    u16 y;
    u16 z;
    u8 unk_06[0x2];
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 x2;
    s32 y2;
    s32 z2;
    s32 unk_20;
    s32 unk_24;
    u16 unk_28;
    u8 unk_2A[0x2];
    u32 unk_2C;
    s16 unk_30;
    s16 unk_32;
    s16 unk_34;
    s16 unk_36;
    s16 unk_38;
    s8 unk_3A;
    u8 unk_3B;
    s32 unk_3C;
    u16 unk_40;
    u16 unk_42;
    u16 unk_44;
    u8 unk_46[0x2];
    s32 unk_48;
    s32 unk_4C;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5C;
    struct TmWork* unk_60;
} TmWork;

typedef struct TmBodyWork {
    TmWork* tm;
    void* tiles;
    void* palette;
    void* palette2;
    BtlObj body;
    u8 unk_120[0x4];
    void* gfx;
    u8 unk_128;
    u8 unk_129[0x3];
    BtlObj body2;
    u8 unk_23C[0x4];
    void* gfx2;
    u8 unk_244;
    u8 unk_245[0x3];
    BtlObj body3;
    u8 unk_358[0x4];
    void* gfx3;
    u8 unk_360;
    u8 unk_361[0x3];
    BtlObj body4;
    u8 unk_474[0x4];
    void* gfx4;
    u8 unk_47C;
    u8 unk_47D[0x3];
    s16 unk_480;
    s16 unk_482;
    s16 unk_484;
    s16 unk_486;
    u8 unk_488;
    u8 unk_489;
    s16 unk_48A;
    s16 unk_48C;
    s16 unk_48E;
    u8 unk_490;
    u8 unk_491;
    s16 unk_492;
} TmBodyWork;

typedef struct WlogoObjParam {
    u32 tiles;
    u16 unk_04;
    u8 unk_06[0x02];
    u32 palette;
    u16 unk_0C;
    u8 unk_0E[0x02];
    s32 x;
    s32 y;
    s32 z;
    void (*unk_1C)(void);
    void* unk_20;
} WlogoObjParam;

typedef struct TmTblWork {
    u32 unk_000;
    u32 unk_004;
    u8 unk_008[0x32];
    u8 unk_03A;
    u8 unk_03B[0x25];
    u16 unk_060;
    u8 unk_062;
    u8 unk_063[0x1];
    u16 unk_064;
    s8 unk_066;
    u8 unk_067;
    u32 unk_068;
} TmTblWork;

typedef struct TmClbSrc {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u16 unk_0C;
    u16 unk_0E;
} TmClbSrc;

typedef struct TmClbArg {
    u32 unk_00;
    u32 unk_04;
    TmClbSrc* src;
    s32 unk_0C;
    void* unk_10;
    void* unk_14;
} TmClbArg;

typedef struct TmClbWork {
    TmClbArg* arg;
    void* tiles;
    void* palette;
    u16 unk_00C;
    u8 unk_00E[0x2];
    s32 x;
    s32 y;
    s32 z;
} TmClbWork;

typedef struct TmArmState {
    u8 unk_00[0x8];
    s32 unk_08;
    s32 unk_0C;
    u8 unk_10[0x18];
    u16 unk_28;
    u8 unk_2A[0x2];
    s32 unk_2C;
    u8 unk_30[0xA];
    u8 unk_3A;
    u8 unk_3B;
    u8 unk_3C[6];
    u16 tileCount;
} TmArmState;

typedef struct TmAnimFrame {
    s16 unk_00;
    u8 unk_02[0x2];
    u8 unk_04[0x10];
} TmAnimFrame;

typedef struct TmAnim {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    u8 unk_06[0x2];
    TmAnimFrame* frames;
} TmAnim;

typedef struct TmArmSrc {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    TmArmState* state;
} TmArmSrc;

typedef struct TmArmJoint {
    s32 unk_00;
    s32 unk_04;
    u8 unk_08;
    u8 unk_09[0x3];
    s32 x;
    s32 y;
    u16 unk_14;
    u8 unk_16[0x10];
    u16 unk_26;
    u8 unk_28[0x8];
    void* gfx;
} TmArmJoint;

typedef struct TmArmPos {
    s32 x;
    s32 y;
    s32 z;
    u16 unk_0C;
    u16 unk_0E;
} TmArmPos;

typedef struct TmArmTileHeader {
    u16 unk_00[4];
    u16 tileCount;
} TmArmTileHeader;

typedef struct TmArmWork {
    u32 tiles;
    u16* palette;
    u32 palette2;
    TmArmSrc* src;
    union {
        TmArmJoint all[8];
        TmArmJoint arms[2][4];
    } joints;
    u16 unk_1B0;
    u16 unk_1B2;
    TaskPool tasks;
    u32 unk_1C8;
    u8 unk_1CC[0xC];
    u32 unk_1D8;
    u32 unk_1DC;
    u32 unk_1E0;
    u8 unk_1E4[0xC];
    u32 unk_1F0;
    u32 unk_1F4;
    TmArmPos unk_1F8[2];
    u32 unk_218;
    u8 unk_21C[0x4];
    u32 unk_220;
    u8 unk_224[0x8];
    u32 unk_22C;
    u8 unk_230;
    u8 unk_231[0x3];
    u32 unk_234;
    u32 tiles2;
    AnimState anim;
    u8 unk_254;
    u8 unk_255[0x3];
} TmArmWork;

typedef struct TmFootWork {
    u16 unk_000;
    u8 unk_002;
    u8 unk_003;
    u8 unk_004;
    u8 unk_005[0x3];
    u32 tiles;
    u32 tiles2;
    u32 tiles3;
    u32 palette;
    u32 palette2;
    BtlObj body;
    void* gfx;
    u8 unk_130;
    u8 unk_131[0x3];
    BtlObj body2;
    void* gfx2;
    u8 unk_248;
    u8 unk_249[0x3];
    BtlObj body3;
    u32 gfx3;
    u8 unk_360;
    u8 unk_361[0x3];
    BtlObj body4;
    void* gfx4;
    u8 unk_478;
    u8 unk_479[0x3];
    TmWork* tm;
    u32 unk_480;
} TmFootWork;

typedef char TmArmWork_size[(sizeof(TmArmWork) == 0x258) ? 1 : -1];

typedef char TmFootWork_size[(sizeof(TmFootWork) == 0x484) ? 1 : -1];

typedef struct WlogoTtEffStep {
    s16 unk_00;
    s16 unk_02;
    u8 unk_04;
    u8 unk_05[0x3];
    s16 unk_08;
    s16 unk_0A;
    u8 unk_0C;
    u8 unk_0D[0x3];
    s16 unk_10;
    s16 unk_12;
    u8 unk_14[0x2];
    s16 unk_16;
    s16 unk_18;
    s16 unk_1A;
    u8 unk_1C[0x2];
    s16 unk_1E;
} WlogoTtEffStep;

typedef struct TmFootStep {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    s16 unk_0E;
    s16 unk_10;
    s16 unk_12;
    u8 unk_14[0x4];
    s16 unk_18;
    s16 unk_1A;
    u8 unk_1C[0x4];
} TmFootStep;

typedef char TmWork_size[(sizeof(TmWork) == 0x64) ? 1 : -1];
typedef char TmBodyWork_size[(sizeof(TmBodyWork) == 0x494) ? 1 : -1];

void func_080B8324(TmBodyWork* p);
void func_080B8334(BtlObj* p, s16 a, s16 b, s16 c);
void func_080B83A4(BtlObj* p, s16 a, s16 b, s16 c);
void func_080B83B8(BtlObj* a);
void func_080B83C4(TmBodyWork* p);
void func_080B8418(TmBodyWork* p);
void func_080B8508(TmBodyWork* p);
void func_080B8554(TmBodyWork* p);
void func_080B8688(TmBodyWork* p);
void func_080B87C0(TmBodyWork* p, s16 a);
void func_080B895C(TmBodyWork* p);
void func_080B89B0(TmBodyWork* p);
void func_080B8A00(TmBodyWork* p);
void func_080B8FF4(TmBodyWork* p, s16 a);
void func_080B91A4(TmBodyWork* p);
void _080B949C(BtlObj* a, TmBodyWork* b);
void func_080B9FC4(TmBodyWork* p);

s32 GetAbsoluteDifference(s32 a, s32 b);
void func_080B7E68(TmWork* w);
void task_bos_tm_0(TmWork* w, BtlObj* arg);
u8 task_bos_tm_1(TmWork* w);
void task_bos_tm_2(TmWork* w);
void task_bos_tm_3(TmWork* w);
void func_080B82D4(void);
void func_080BB924(TmArmWork* work);
void func_080BC304(TmArmWork* work);
u8 task_bos_tm_clb_1(TmClbWork* work);
u8 task_bos_tm_arm_1(TmArmWork* work);
void task_bos_tm_arm_3(TmArmWork* work);
void task_bos_tm_foot_3(TmFootWork* work);
void task_bos_tm_clb_0(TmClbWork* work, void* arg);
void task_bos_tm_clb_2(TmClbWork* work);
void task_bos_tm_tbl_0(TmTblWork* work, void* arg);
void task_bos_tm_tbl_3(TmTblWork* work);
void task_bos_tm_clb_3(TmClbWork* work);
void func_080BA0E4(BtlObj* p, s32 a, s32 b, s32 c);
void func_080BA0F8(BtlObj* work);
void task_bos_tm_body_3(TmBodyWork* work);
void func_080BB1B8(void* pool, TmClbArg* p, TmClbSrc* a);
void func_080BB1D8(TmClbArg* p, TmClbSrc* a, s32 b);
void func_080BB1E8(TmClbArg* p, TmClbSrc* a);
void func_080BB1F4(TmClbArg* p, TmClbSrc* a, u8 mode);
void func_080BB428(u8* dst, u8* src);
void func_080BB43C(u8* work, u8* src, u16 a, u8* dst);
void func_080BB464(TmArmWork* work);
void func_080BB4C0(TmArmWork* work);
void func_080BA104(BtlObj* sub, TmFootWork* work);
void func_080BA43C(TmFootWork* work, s16 a);
void func_080BA62C(TmFootWork* work);
void func_080BA8C8(TmFootWork* work, s16 a);
void func_080BB588(TmArmJoint* joints, u16 a);
void func_080BB5E8(u8* joints, TmAnim* a);

#endif
