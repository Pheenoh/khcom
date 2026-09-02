.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global ply_fine
	.thumb
	.thumb_func
	.type ply_fine, %function
ply_fine:
	push {r4,r5,lr}
	adds r5, r1, 0
	ldr r4, [r5, o_MusicPlayerTrack_chan]
	cmp r4, 0
	beq ply_fine_done
ply_fine_loop:
	ldrb r1, [r4]
	movs r0, 0xC7
	tst r0, r1
	beq ply_fine_ok
	movs r0, 0x40
	orrs r1, r0
	strb r1, [r4]
ply_fine_ok:
	adds r0, r4, 0
	bl RealClearChain
	ldr r1, [r4, o_SoundChannel_nextChannelPointer]
	cmp r1, r4
	bne ply_fine_next
	movs r1, 0
	str r1, [r4, o_SoundChannel_nextChannelPointer]
ply_fine_next:
	adds r4, r1, 0
	cmp r4, 0
	bne ply_fine_loop
ply_fine_done:
	movs r0, 0
	strb r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
.syntax divided
