#ifndef GUARD_AUDIO_BLOCK_CODEC_H
#define GUARD_AUDIO_BLOCK_CODEC_H

#include "types.h"


extern u8* gUnk_02038628;
extern s32 gUnk_0203862C;
extern s32 gUnk_02038630;
extern s32* gUnk_02038634;
extern s32 gUnk_02038638[8];
extern s32 gUnk_02038658[16];

void _08117284(s32 offset);
void _08117674(s32 offset);
void _08117A4C(s32 offset);
void func_08117E44(s32 offset);
void DecodeAudioBlock(u8* src, s32* samples, s32 offset);
s32 PeekAudioBits8(void);

#endif
