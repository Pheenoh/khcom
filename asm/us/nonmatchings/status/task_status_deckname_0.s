.syntax unified
	.align 2, 0
	.global task_status_deckname_0
	.thumb
	.thumb_func
	.type task_status_deckname_0, %function
task_status_deckname_0: @ 080D7DC8
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	movs r1, #0x0A
	bl func_08065ACC
	str r5, [r4, #0x58]
	bl GetActiveDeckIndex
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl func_080857BC
	adds r1, r4, #0x0
	bl func_08065B6C
	adds r1, r4, #0x0
	adds r1, #0x54
	strb r0, [r1, #0x00]
	ldr r0, _080D7E00 @ =0x0984B1D8
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x50]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D7E00: .4byte 0x0984B1D8
.syntax divided
