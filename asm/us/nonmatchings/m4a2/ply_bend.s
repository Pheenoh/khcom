.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global ply_bend
	.thumb
	.thumb_func
	.type ply_bend, %function
ply_bend:
	mov r12, lr
	bl ld_r3_tp_adr_i
	subs r3, 0x40
	strb r3, [r1, o_MusicPlayerTrack_bend]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12
.syntax divided
