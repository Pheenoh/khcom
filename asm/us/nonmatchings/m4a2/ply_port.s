.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global ply_port
	.thumb
	.thumb_func
	.type ply_port, %function
ply_port:
	mov r12, lr
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r3, [r2]
	adds r2, 1
	ldr r0, =REG_SOUND1CNT_L
	adds r0, r3
	bl ld_r3_tp_adr_i_r2
	strb r3, [r0]
	bx r12
	.pool
.syntax divided
