#ifndef GUARD_MODE_MAPINSPECT_H
#define GUARD_MODE_MAPINSPECT_H

#include "types.h"
#include "main.h"

typedef struct AnimFrame {
    u16 unk_00;
    u16 unk_02;
} AnimFrame;

typedef struct AnimState {
    s32 unk_00;
    u32* unk_04;
    u16 unk_08;
    u16 unk_0A;
    u16 unk_0C;
    u16 unk_0E;
    u8 unk_10[0x04];
    AnimFrame* unk_14;
} AnimState;

typedef struct UnkStruct_0810718C {
    u8 unk_00[0x04];
    u16 unk_04;
} UnkStruct_0810718C;

typedef struct UnkStruct_09EF9618 {
    u8 unk_00[0x24];
    s16 unk_24;
} UnkStruct_09EF9618;

extern UnkStruct_09EF9618 gUnk_09EF9618;
extern s16 gUnk_02035E2C;
extern s16 gUnk_02035E2E;
extern s16 gUnk_02035E48;
extern AnimState gUnk_02035E58;
extern AnimState gUnk_02035E80;
extern AnimState gUnk_02035F58;
extern AnimState gUnk_02035F78;
extern s16 gUnk_02035E98;
extern s16 gUnk_02035E9A;
extern s16 gUnk_02035E9C;
extern void* gUnk_02035F00[4][3];
extern u8 gUnk_02035F30[4][3];
extern void* gUnk_02035F44;
extern void* gUnk_02035F50;
extern u8 gUnk_02035F90;
extern u8 gUnk_02035FA8;
extern u8 gUnk_02035FB0;
extern u8 gUnk_02035FB8;
extern u8 gUnk_02035FC0;
extern s16 gUnk_02035FC4;
extern s16 gUnk_02035FC6;
extern s32 gUnk_02035FDC;
extern s32 gUnk_02035FE0;
extern u8 gUnk_08159E10[];
extern u8 gUnk_08159E18[];
extern u8 gUnk_08159FBC[];
extern u8 gUnk_0815C136[];
extern u8 gUnk_0908B1B4[];
extern u8 gUnk_0908C3CE[];
extern u8 gUnk_09611AB8[];
extern u8 gUnk_099597E4[];
extern u8 gUnk_0999DAEC[];
extern u8 gUnk_0999E69E[];
extern u8 gUnk_09985F44[];
extern u8 gUnk_09A03CFC[];
extern u8 gUnk_09A3439C[];
extern u8 gUnk_09A3501C[];
extern u8 gUnk_09A3551C[];
extern u8 gUnk_09A3D0DC[];
extern u8 gUnk_09A3D2DC[];
extern u8 gUnk_09EEA148[];
extern u8 gUnk_09EEA164[];
extern u8 gUnk_09EEA180[];
extern u8 gUnk_09EEA198[];
extern u8 gUnk_09EF97EC[];
extern u8 gUnk_09EF981C[];
extern u8 gUnk_09EF9830[];
extern u8 gUnk_09EF9858[];
extern void* gUnk_02035E4C;
extern void* gUnk_02035E50;
extern void* gUnk_02035E70;
extern void* gUnk_02035E74;
extern void* gUnk_02035E78;
extern void* gUnk_02035EA0[4][3];
extern void* gUnk_02035ED0[4][3];
extern void* gUnk_02035F3C;
extern void* gUnk_02035F40;
extern void* gUnk_02035F48;
extern void* gUnk_02035F4C;
extern void* gUnk_02035F54;
extern void* gUnk_02035F70;
extern u8* gUnk_02035F94;
extern u8* gUnk_02035F9C;
extern u8* gUnk_02035FA4;
extern u16 gUnk_02035FAA;
extern u8* gUnk_02035FAC;
extern u16 gUnk_02035FB2;
extern u8* gUnk_02035FB4;
extern u16 gUnk_02035FBA;
extern void* gUnk_02035FBC[];
extern u16 gUnk_02035FC2[];
extern s16 gUnk_02035FCA;
extern s16 gUnk_02035FCC;
extern s32 gUnk_02035FD0[];
extern s32 gUnk_02035FD8;
extern u8 gUnk_02035FE4;
extern u8* gUnk_02035E28;
extern u8 gUnk_09A3489C[];

void ReleaseObjTiles(void* a);
void ReleaseObjPalette(void* a);
void func_08065AE0(void* a, s32 b);
void func_0801CC80(void);
void func_080058FC(s32* value, s32 target, u16 steps);
void LoadBgMap(s32 bg, void* src, u16 size);
void func_08006184(s32 a, u16 b);
u8 func_08006314(void);
void func_080E052C(u8 a);
void func_08107D44(void);
void func_08107FF0(void);
void func_08108208(void);
void func_081083EC(void);
void func_081085E8(void);
void func_08108650(void);
void func_08001F98(void);
void func_08006120(s32 a, s32 b);
void func_08004DB0(void);
void SetupBg(s32 a, s32 b, s32 c, s32 d);
void SetBgPriority(s32 a, s32 b);
void LoadBgTiles(s32 a, void* b, u16 c);
void LoadBgPalette(s32 a, void* b, u16 c);
void func_08107B84(void);
UnkStruct_0810718C* func_0810718C(void);
void func_081078F0(s16 a);
void func_081075FC(void);
void func_0810764C(void);
void func_081076D4(void);
void* LoadObjTiles(void* a, s32 b);
void* LoadObjPalette(void* a, s32 b);
void AnimInit(AnimState* a, void* b, void* c);
void AnimStart(AnimState* a, s32 b, s32 c);
void func_08065ACC(void* a, s32 b);
u16 func_08065B54(void* a);
u8 func_08065B6C(void* a, void* b);
void func_08107280(void);
void func_081073F0(void);
void func_08004FC8(s32 a);
void func_0800501C(s32 a);

#endif /* GUARD_MODE_MAPINSPECT_H */
