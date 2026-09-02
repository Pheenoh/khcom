.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global ply_pend
	.thumb
	.thumb_func
	.type ply_pend, %function
ply_pend:
	ldrb r2, [r1, o_MusicPlayerTrack_patternLevel]
	cmp r2, 0
	beq ply_pend_done
	subs r2, 1
	strb r2, [r1, o_MusicPlayerTrack_patternLevel]
	lsls r2, 2
	adds r3, r1, r2
	ldr r2, [r3, o_MusicPlayerTrack_patternStack]
	str r2, [r1, o_MusicPlayerTrack_cmdPtr]
ply_pend_done:
	bx lr
	.align 2, 0
.syntax divided
