.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global ply_prio
	.thumb
	.thumb_func
	.type ply_prio, %function
ply_prio:
	mov r12, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, o_MusicPlayerTrack_priority]
	bx r12
	.align 2, 0
.syntax divided
