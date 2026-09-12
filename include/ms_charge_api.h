#ifndef GUARD_MS_CHARGE_API_H
#define GUARD_MS_CHARGE_API_H

#include "types.h"

typedef struct MsCard {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    s16 unk_06[10][2];
    u8 unk_2E;
    u8 unk_2F[0x1];
    u32 unk_30;
} MsCard;

MsCard* func_08104B2C(void);
void func_08104BBC(void);
void func_08104D18(void);
void func_08104F2C(void);
void func_08104FA4(void);
void func_08104FF8(void);
void func_08105090(void);
void func_081052C8(s16 a);
void func_0810563C(void);
void func_0810594C(void);
void func_08105BD8(void);
void func_08105DE0(void);
void func_0810601C(void);
void func_081061DC(void);
void func_08106234(void);

#endif
