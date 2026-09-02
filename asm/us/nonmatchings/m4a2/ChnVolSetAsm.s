.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global ChnVolSetAsm
	.thumb
	.thumb_func
	.type ChnVolSetAsm, %function
ChnVolSetAsm:
	ldrb r1, [r4, o_SoundChannel_velocity]
	movs r0, o_SoundChannel_rhythmPan
	ldrsb r2, [r4, r0]
	movs r3, 0x80
	adds r3, r2
	muls r3, r1
	ldrb r0, [r5, o_MusicPlayerTrack_volMR]
	muls r0, r3
	asrs r0, 14
	cmp r0, 0xFF
	bls ChnVolSetAsm_1
	movs r0, 0xFF
ChnVolSetAsm_1:
	strb r0, [r4, o_SoundChannel_rightVolume]
	movs r3, 0x7F
	subs r3, r2
	muls r3, r1
	ldrb r0, [r5, o_MusicPlayerTrack_volML]
	muls r0, r3
	asrs r0, 14
	cmp r0, 0xFF
	bls ChnVolSetAsm_2
	movs r0, 0xFF
ChnVolSetAsm_2:
	strb r0, [r4, o_SoundChannel_leftVolume]
	bx lr
	.align 2, 0
.syntax divided
