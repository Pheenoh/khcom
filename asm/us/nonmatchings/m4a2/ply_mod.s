.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global ply_mod
	.thumb
	.thumb_func
	.type ply_mod, %function
ply_mod:
	mov r12, lr
	bl ld_r3_tp_adr_i_unchecked
	strb r3, [r1, o_MusicPlayerTrack_mod]
	cmp r3, 0
	bne ply_mod_1
	bl clear_modM
ply_mod_1:
	bx r12
	.align 2, 0
.syntax divided
