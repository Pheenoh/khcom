.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global ply_modt
	.thumb
	.thumb_func
	.type ply_modt, %function
ply_modt:
	mov r12, lr
	bl ld_r3_tp_adr_i
	ldrb r0, [r1, o_MusicPlayerTrack_modT]
	cmp r0, r3
	beq ply_modt_1
	strb r3, [r1, o_MusicPlayerTrack_modT]
	ldrb r3, [r1, o_MusicPlayerTrack_flags]
	movs r2, 0xF
	orrs r3, r2
	strb r3, [r1, o_MusicPlayerTrack_flags]
ply_modt_1:
	bx r12
	.align 2, 0
.syntax divided
