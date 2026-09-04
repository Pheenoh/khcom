#ifndef GUARD_BTL4_H
#define GUARD_BTL4_H

#include "types.h"
#include "anim.h"
typedef struct BtlWork {
    s32 unk_000;
    s32 unk_004;
    s32 unk_008;
    s32 unk_00C;
    u8 unk_010[0x1C];
    s16 unk_02C;
    s16 unk_02E;
    u8 unk_030[0x10];
    u8 unk_040[0x28];
    u64 unk_068;
    u8 unk_070[0x08];
    struct BtlWork* unk_078;
    struct BtlWork* unk_07C;
    u8 unk_080[0x22];
    s16 unk_0A2;
    u8 unk_0A4[0x50];
    s32 unk_0F4;
} BtlWork;

typedef struct GameState {
    u8 unk_000[0x100];
    u32 exp;
    u32 nextExp;
    u8 level;
    u8 unk_109[0x03];
} GameState;

typedef struct BtlEffect {
    u16 unk_00;
    u16 unk_02;
    s32 unk_04;
    void* unk_08;
    s16 unk_0C;
    s16 unk_0E;
    u8 unk_10[0x02];
    u16 unk_12;
    u16 unk_14;
    u8 unk_16[0x0A];
    AnimState unk_20;
} BtlEffect;

typedef struct BtlPopSrc {
    s32 x;
    s32 y;
    s32 z;
    u8 unk_0C[0x06];
    s16 unk_12;
} BtlPopSrc;

typedef struct BtlPopCbWork {
    void* tiles;
    void* palette;
    void* unk_08;
    s32 x;
    s32 y;
    s32 z;
    s16 unk_18;
    u8 unk_1A[0x02];
} BtlPopCbWork;

typedef struct BtlExpWork {
    void* palette;
    void* tiles;
    void* unk_08[6];
    void* unk_20;
    void* unk_24[6];
    s16 unk_3C;
    u8 unk_3E;
    u8 unk_3F;
    u16 unk_40;
    u8 unk_42[0x02];
    u32 unk_44;
    u32 unk_48;
} BtlExpWork;

typedef struct BtlVslockonWork {
    void* tiles;
    void* palette;
    AnimState anim;
    void* gfx;
} BtlVslockonWork;

typedef struct BtlHpothWork {
    s32 unk_00;
    u8 unk_04;
    u8 unk_05[0x03];
    void* unk_08;
    void* unk_0C;
    void* unk_10;
    void* unk_14;
    void* unk_18;
    void* unk_1C;
    void* unk_20;
    void* unk_24;
    void* unk_28;
    AnimState unk_2C;
    AnimState unk_44;
    u8 unk_5C;
    u8 unk_5D;
    s16 unk_5E;
    s16 unk_60;
    s16 unk_62;
    s16 unk_64;
    u8 unk_66[0x02];
    u32 unk_68;
} BtlHpothWork;

extern BtlWork* gBtlWork;
extern BtlWork* gUnk_02039B9C;
extern GameState gGameState;
extern u16 gDispCnt;

extern u8 gUnk_08B1D8BC[];
extern u8 gUnk_08B1FCBC[];
extern u8 gUnk_08B1FCCC[];
extern u8 gUnk_08B1FCDC[];
extern u8 gUnk_08B1FCEC[];
extern u8 gUnk_08B1FCFC[];
extern u8 gUnk_08B1FD0C[];
extern u8 gUnk_08B1FD1C[];
extern u8 gUnk_08B1FD2C[];
extern u8 gUnk_08B1FD3C[];
extern u8 gUnk_08B1FD4C[];
extern u8 gUnk_08B1FD66[];
extern u8 gUnk_08B20D20[];
extern u8 gUnk_08B20D6E[];
extern u8 gUnk_08B23CBA[];
extern u8 gUnk_08B23E7C[];
extern u8 gUnk_08B23E8C[];
extern u8 gUnk_08B23E9C[];
extern u8 gUnk_08B23EAC[];
extern u8 gUnk_08B23EBC[];
extern u8 gUnk_08B23ED2[];
extern u8 gUnk_08B23EE8[];
extern u8 gUnk_08B23F08[];
extern u8 gUnk_08B23F24[];
extern u8 gUnk_08B23F2E[];
extern u8 gUnk_08B24016[];
extern u8 gUnk_08B25E40[];
extern u8 gUnk_08B25E54[];
extern u8 gUnk_08B25E5E[];
extern u8 gUnk_08B25E6E[];
extern u8 gUnk_08B25E78[];
extern u8 gUnk_08B25E82[];
extern u8 gUnk_08B25E8C[];
extern u8 gUnk_08B25E96[];
extern u8 gUnk_08B25EA0[];
extern u8 gUnk_08B25EAA[];
extern u8 gUnk_08B25EB4[];
extern u8 gUnk_08B25EBE[];
extern u8 gUnk_08B25EC8[];
extern u8 gUnk_08B25ED2[];
extern u8 gUnk_08B25EF0[];
extern u8 gUnk_08F69BA4[];
extern u8 gUnk_096FAC64[];
extern u8 gUnk_09EE10EC[];
extern u8 gUnk_09EE10F8[];
extern u8 gUnk_09EE12A4[];
extern u8 gUnk_09EE12B0[];
extern u8 gUnk_09EE1420[];
extern u8 gUnk_09EE1498[];
extern void* gUnk_09EE157C[];

void* AllocObjTiles(s32 a, void* b);
void* LoadObjTiles(void* a, s32 b);
void ReleaseObjTiles(void* a);
void* LoadObjPalette(void* a, s32 b);
void ReleaseObjPalette(u8* p);
s32 AllocObjAffine(s32 a, s32 b, s32 c, s32 d);
void DrawSprite(s16 a, s16 b, void* c, void* d, void* e, s32 f, u16 g, s32 h);
void WorldToScreen(s16* a, s16* b, s32 c, s32 d, s32 e);
void AnimInit(AnimState* a, void* b, void* c);
void AnimStart(AnimState* a, u16 animId, u16 flags);
void AnimChange(AnimState* a, u16 animId, u16 flags);
void* AnimUpdate(AnimState* a);
void* AnimGetGfx(AnimState* a);
void func_080A411C(void* a, s32 b, u16 c);
void func_080A41F0(void* a, u16 b);
void func_080A42E0(void);

void task_btl_pop_cb_0(BtlPopCbWork* work, BtlPopSrc* src);
s32 task_btl_pop_cb_1(BtlPopCbWork* work);
void task_btl_pop_cb_2(BtlPopCbWork* work);
void task_btl_pop_cb_3(BtlPopCbWork* work);
void* func_0805CDC8(s32 digit, u8 leading);
void func_0805CE60(BtlExpWork* work, u32 value);
void task_btl_exp_0(BtlExpWork* work);
s32 task_btl_exp_1(BtlExpWork* work);
void task_btl_exp_2(BtlExpWork* work);
void task_btl_exp_3(BtlExpWork* work);
void task_btl_vslockon_0(BtlVslockonWork* work);
s32 task_btl_vslockon_1(BtlVslockonWork* work);
void task_btl_vslockon_2(BtlVslockonWork* work);
void task_btl_vslockon_3(BtlVslockonWork* work);
void task_btl_hpoth_0(BtlHpothWork* work);
s32 task_btl_hpoth_1(BtlHpothWork* work);
void task_btl_hpoth_2(BtlHpothWork* work);
void task_btl_hpoth_3(BtlHpothWork* work);
void func_0805DA64(u16 a);
void func_0805DA98(u16 a);
void func_0805DAB4(void);
void func_0805DACC(BtlEffect* p, u16 b, void* c);
void func_0805DADC(BtlEffect* p, u16 b, void* c);
void func_0805DAEC(void);
void func_0805DAF8(BtlEffect* p, u16 b, void* c);
void func_0805DB04(BtlEffect* p, u16 b, u16 c, u16 d);
void func_0805DB28(BtlEffect* p);

#endif /* GUARD_BTL4_H */
