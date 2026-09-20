#ifndef GUARD_MODE_MAPCHK_H
#define GUARD_MODE_MAPCHK_H

#include "types.h"

typedef struct MapChkWork {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06[0x02];
} MapChkWork;

void func_080DDEC8(u8* p, u8 a);
void func_080DDF04(u8 a, u8 b);
void func_080DE2A4(MapChkWork* p);
void func_080DE2FC(MapChkWork* p);
void func_080DE35C(MapChkWork* p);
void func_080DE3E8(MapChkWork* p);
void func_080DE4A4(MapChkWork* p);
void func_080DE50C(MapChkWork* p);
void func_080DE534(MapChkWork* p);
void func_080DE5B0(MapChkWork* p);
void func_080DE62C(MapChkWork* p);
void func_080DE6A8(MapChkWork* p);
void Mode_MapChk_0(void);
void Mode_MapChk_1(void);
void Mode_MapChk_2(void);

#endif
