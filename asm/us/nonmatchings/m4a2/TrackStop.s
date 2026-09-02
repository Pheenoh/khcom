.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global TrackStop
	.thumb
	.thumb_func
	.type TrackStop, %function
TrackStop:
	push {r4-r6,lr}
	adds r5, r1, 0
	ldrb r1, [r5, o_MusicPlayerTrack_flags]
	movs r0, 0x80
	tst r0, r1
	beq TrackStop_Done
	ldr r4, [r5, o_MusicPlayerTrack_chan]
	cmp r4, 0
	beq TrackStop_3
	movs r6, 0
TrackStop_Loop:
	ldrb r0, [r4, o_SoundChannel_statusFlags]
	cmp r0, 0
	beq TrackStop_2
	ldrb r0, [r4, o_SoundChannel_type]
	movs r3, 0x7
	ands r0, r3
	beq TrackStop_1
	ldr r3, =SOUND_INFO_PTR
	ldr r3, [r3]
	ldr r3, [r3, o_SoundInfo_CgbOscOff]
	bl call_r3
TrackStop_1:
	strb r6, [r4, o_SoundChannel_statusFlags]
TrackStop_2:
	str r6, [r4, o_SoundChannel_track]
	ldr r0, [r4, o_SoundChannel_nextChannelPointer]
	cmp r0, r4
	bne TrackStop_Next
	movs r0, 0
	str r0, [r4, o_SoundChannel_nextChannelPointer]
TrackStop_Next:
	adds r4, r0, 0
	cmp r4, 0
	bne TrackStop_Loop
TrackStop_3:
	str r4, [r5, o_MusicPlayerTrack_chan]
TrackStop_Done:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
.syntax divided
