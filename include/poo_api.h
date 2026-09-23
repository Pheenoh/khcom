#ifndef GUARD_POO_API_H
#define GUARD_POO_API_H

#include "types.h"
#include "pooh_actor_types.h"

struct PooPos;

void func_080CA35C(void);
void func_080CA368(s32 a, u16 b, u16 c);
void func_080CA6A8(s32 a, s32 b);
void func_080CCBE8(void);
void func_080D2BE0(void);
void func_080D2C78(void);
void func_080D2C8C(struct PooPos* p, s32 b);
void SetPooStatePos2(struct PooPos* p);
u8 func_080D2D50(s32 a);
void func_080D2D6C(s32 a);
u8 func_080D2D94(s32 a);
void GetPooState(void* p);
void SetPooState(const void* p);
u8 func_080D2DD8(void);
void func_080D2E84(void);
void func_080D2E98(void);
void func_080D2F20(void);
void func_080D2F64(void);
void func_080D3008(void);
void func_080D3034(s16 a);
void func_080D3050(void);
void func_080D30C8(void);
void func_080D313C(void);

struct PooNode;

extern u8 gUnk_0203C3D8;
extern s32 gUnk_0203C3DC;
extern u16 gUnk_0203C3E0;
extern u16 gUnk_0203C3E4;
extern s32 gUnk_0203C3E8;
extern struct PooPos* gUnk_0203C3EC;
extern u32 gUnk_0203C3F0;
extern u32 gUnk_0203C3F4;
extern u16 gUnk_0203C3F8;
extern s32 gUnk_0203C3FC;
extern s32 gUnk_0203C400;
extern s32 gUnk_0203C404;
extern s32 gUnk_0203C408;
extern u16 gUnk_0203C40C;
extern struct PooNode* gUnk_0203C410;
extern void* gUnk_0203C414;
extern PooActor gPooActor;
extern u8* gStockMesDispWork;
extern PooState gPooState;
extern void* gUnk_0203C4B4;

#endif
