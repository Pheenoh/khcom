.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global clear_modM
	.thumb
	.thumb_func
	.type clear_modM, %function
clear_modM:
	movs r2, 0
	strb r2, [r1, o_MusicPlayerTrack_modM]
	strb r2, [r1, o_MusicPlayerTrack_lfoSpeedC]
	ldrb r2, [r1, o_MusicPlayerTrack_modT]
	cmp r2, 0
	bne clear_modM_1
	movs r2, 0xC
	b clear_modM_2
clear_modM_1:
	movs r2, 0x3
clear_modM_2:
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx lr
	.align 2, 0
.syntax divided
