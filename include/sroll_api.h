#ifndef GUARD_SROLL_API_H
#define GUARD_SROLL_API_H

#include "types.h"

struct SrollBCharWork;
struct SrollInit;
struct SrollWork;

void func_081149B0(struct SrollBCharWork* w, s32 v);
s32 SrollTextMeasureWidth(struct SrollWork* w, u8* s);
void SrollTextSelectFont(struct SrollWork* w, u32 mode);
void SrollTextInit(struct SrollWork* w, struct SrollInit* a);
void SrollTextSetColors(struct SrollWork* w, u16 a, u16 b, u16 c, u16 d);
void SrollTextClearRect(struct SrollWork* w, u16 x, u16 y, u16 cw, u16 ch, u8 flush);
void SrollTextDrawStringAtPixelX(struct SrollWork* w, u16 x, u16 y, u8* s, u8 flush);
void ScanlineDmaReset(void);
void ScanlineDmaInit(vu16* dst, u8* src, u32 cnt);
void ScanlineDmaQueueBuffer(u8* src);
void ScanlineDmaEnable(void);
void ScanlineDmaDisable(void);
void BlockAudioStart(void);
void BlockAudioUpdate(void);
void BlockAudioStop(void);

#endif
