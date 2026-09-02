.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global ld_r3_tp_adr_i_unchecked
	.thumb
	.thumb_func
	.type ld_r3_tp_adr_i_unchecked, %function
ld_r3_tp_adr_i_unchecked:
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	adds r3, r2, 1
	str r3, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r3, [r2]
	bx lr
	.align 2, 0
.syntax divided
