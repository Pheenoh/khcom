.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global ply_lfodl
	.thumb
	.thumb_func
	.type ply_lfodl, %function
ply_lfodl:
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, o_MusicPlayerTrack_lfoDelay]
	bx r12
	.align 2, 0
.syntax divided
