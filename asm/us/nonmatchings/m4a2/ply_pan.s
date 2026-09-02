.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global ply_pan
	.thumb
	.thumb_func
	.type ply_pan, %function
ply_pan:
	mov r12, lr
	bl ld_r3_tp_adr_i
	subs r3, 0x40
	strb r3, [r1, o_MusicPlayerTrack_pan]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0x3
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12
.syntax divided
