.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global ply_tempo
	.thumb
	.thumb_func
	.type ply_tempo, %function
ply_tempo:
	mov r12, lr
	bl ld_r3_tp_adr_i
	lsls r3, 1
	strh r3, [r0, o_MusicPlayerInfo_tempoD]
	ldrh r2, [r0, o_MusicPlayerInfo_tempoU]
	muls r3, r2
	lsrs r3, 8
	strh r3, [r0, o_MusicPlayerInfo_tempoI]
	bx r12
.syntax divided
