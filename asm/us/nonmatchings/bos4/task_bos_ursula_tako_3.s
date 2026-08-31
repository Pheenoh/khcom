.syntax unified
	.align 2, 0
	.global task_bos_ursula_tako_3
	.thumb
	.thumb_func
	.type task_bos_ursula_tako_3, %function
task_bos_ursula_tako_3: @ 080DD1C4
	push {r4, lr}
	adds r4, r0, #0x0
	adds r0, #0x28
	bl func_0801B7D8
	movs r1, #0xCE
	lsls r1, r1, #0x01
	adds r0, r4, r1
	bl func_08012304
	movs r1, #0xA0
	lsls r1, r1, #0x01
	adds r0, r4, r1
	bl func_08012304
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x08]
	bl ReleaseObjPalette
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
