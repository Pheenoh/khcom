.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global ply_goto
	.thumb
	.thumb_func
	.type ply_goto, %function
ply_goto:
	push {lr}
ply_goto_1:
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	ldrb r3, [r2, 0x2]
	orrs r0, r3
	lsls r0, 8
	ldrb r3, [r2, 0x1]
	orrs r0, r3
	lsls r0, 8
	bl ldrb_r3_r2
	orrs r0, r3
	str r0, [r1, o_MusicPlayerTrack_cmdPtr]
	pop {r0}
	bx r0
.syntax divided
