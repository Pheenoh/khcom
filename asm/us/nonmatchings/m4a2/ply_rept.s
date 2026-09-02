.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global ply_rept
	.thumb
	.thumb_func
	.type ply_rept, %function
ply_rept:
	push {lr}
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r3, [r2]
	cmp r3, 0
	bne ply_rept_1
	adds r2, 1
	str r2, [r1, o_MusicPlayerTrack_cmdPtr]
	b ply_goto_1
ply_rept_1:
	ldrb r3, [r1, o_MusicPlayerTrack_repN]
	adds r3, 1
	strb r3, [r1, o_MusicPlayerTrack_repN]
	mov r12, r3
	bl ld_r3_tp_adr_i
	cmp r12, r3
	bhs ply_rept_2
	b ply_goto_1
ply_rept_2:
	movs r3, 0
	strb r3, [r1, o_MusicPlayerTrack_repN]
	adds r2, 5
	str r2, [r1, o_MusicPlayerTrack_cmdPtr]
	pop {r0}
	bx r0
	.align 2, 0
.syntax divided
