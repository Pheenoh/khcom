.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global ply_bendr
	.thumb
	.thumb_func
	.type ply_bendr, %function
ply_bendr:
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, o_MusicPlayerTrack_bendRange]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0xC
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
	bx r12
	.align 2, 0
.syntax divided
