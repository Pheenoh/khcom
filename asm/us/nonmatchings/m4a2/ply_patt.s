.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global ply_patt
	.thumb
	.thumb_func
	.type ply_patt, %function
ply_patt:
	ldrb r2, [r1, o_MusicPlayerTrack_patternLevel]
	cmp r2, 3
	bhs ply_patt_done
	lsls r2, 2
	adds r3, r1, r2
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	adds r2, 0x4
	str r2, [r3, o_MusicPlayerTrack_patternStack]
	ldrb r2, [r1, o_MusicPlayerTrack_patternLevel]
	adds r2, 1
	strb r2, [r1, o_MusicPlayerTrack_patternLevel]
	b ply_goto
ply_patt_done:
	b ply_fine
	.align 2, 0
.syntax divided
