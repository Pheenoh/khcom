.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global ply_voice
	.thumb
	.thumb_func
	.type ply_voice, %function
ply_voice:
	mov r12, lr
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r3, [r2]
	adds r2, 1
	str r2, [r1, o_MusicPlayerTrack_cmdPtr]
	lsls r2, r3, 1
	adds r2, r3
	lsls r2, 2
	ldr r3, [r0, o_MusicPlayerInfo_tone]
	adds r2, r3
	ldr r3, [r2]
	bl chk_adr_r2
	str r3, [r1, o_MusicPlayerTrack_ToneData_type]
	ldr r3, [r2, 0x4]
	bl chk_adr_r2
	str r3, [r1, o_MusicPlayerTrack_ToneData_wav]
	ldr r3, [r2, 0x8]
	bl chk_adr_r2
	str r3, [r1, o_MusicPlayerTrack_ToneData_attack]
	bx r12
	.align 2, 0
.syntax divided
