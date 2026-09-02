.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global ply_endtie
	.thumb
	.thumb_func
	.type ply_endtie, %function
ply_endtie:
	push {r4,r5}
	ldr r2, [r1, o_MusicPlayerTrack_cmdPtr]
	ldrb r3, [r2]
	cmp r3, 0x80
	bhs ply_endtie_1
	strb r3, [r1, o_MusicPlayerTrack_key]
	adds r2, 0x1
	str r2, [r1, o_MusicPlayerTrack_cmdPtr]
	b ply_endtie_2
ply_endtie_1:
	ldrb r3, [r1, o_MusicPlayerTrack_key]
ply_endtie_2:
	ldr r1, [r1, o_MusicPlayerTrack_chan]
	cmp r1, 0
	beq ply_endtie_5
	movs r4, 0x83
	movs r5, 0x40
ply_endtie_3:
	ldrb r2, [r1, o_SoundChannel_statusFlags]
	tst r2, r4
	beq ply_endtie_4
	tst r2, r5
	bne ply_endtie_4
	ldrb r0, [r1, o_SoundChannel_midiKey]
	cmp r0, r3
	bne ply_endtie_4
	movs r0, 0x40
	orrs r2, r0
	strb r2, [r1, o_SoundChannel_statusFlags]
	b ply_endtie_5
ply_endtie_4:
	ldr r2, [r1, o_SoundChannel_nextChannelPointer]
	cmp r2, r1
	bne ply_endtie_next
	movs r2, 0
	str r2, [r1, o_SoundChannel_nextChannelPointer]
ply_endtie_next:
	adds r1, r2, 0
	cmp r1, 0
	bne ply_endtie_3
ply_endtie_5:
	pop {r4,r5}
	bx lr
	.align 2, 0
.syntax divided
