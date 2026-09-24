#ifndef GUARD_BOS4_API_H
#define GUARD_BOS4_API_H

#include "types.h"
#include "map_runtime.h"

struct UnkStruct_080DDDDC;
typedef struct UnkStruct_096FE034Entry {
    u16 unk_00;
    u16 unk_02;
} UnkStruct_096FE034Entry;

typedef struct UnkStruct_096FE034 {
    const UnkStruct_096FE034Entry* unk_00;
    u16 unk_04;
    u16 unk_06;
    void* unk_08;
    u16 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    u16 unk_12;
    s32 bg;
} UnkStruct_096FE034;


void func_080DDDDC(struct UnkStruct_080DDDDC* p, const struct UnkStruct_096FE034* q);
u8 func_080DDDEC(struct UnkStruct_080DDDDC* p, const struct UnkStruct_096FE034* q, u8 a);
void func_080DDEA4(void);
void func_080DDEB0(s32 a);
void func_080DDEBC(s32 a);

struct BtlObj;

extern u16 gUnk_0203C554;
extern u8 gUnk_0203C558;
extern struct BtlObj* gUnk_0203C55C;
extern u16 gUnk_0203C560;
extern u8 gUnk_0203C564;
extern u8 gUnk_0203C568;
extern u8 gUnk_0203C56C;
extern u8 gUnk_0203C570;
extern u8 gUnk_0203C574;
extern u8 gUnk_0203C578;
extern u8 gUnk_0203C57C;
extern s32 gUnk_0203C580;
extern u8 gUnk_0203C584;

#endif
