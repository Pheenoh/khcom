.syntax unified
	.align 2, 0
	.global task_sroll_b_char_0
	.thumb
	.thumb_func
	.type task_sroll_b_char_0, %function
task_sroll_b_char_0: @ 081149F4
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r5, [r1, #0x00]
	movs r0, #0x00
	str r0, [r4, #0x00]
	str r0, [r4, #0x04]
	ldr r0, [r1, #0x04]
	str r0, [r4, #0x08]
	ldrh r0, [r5, #0x00]
	lsls r0, r0, #0x15
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl AllocObjTiles
	str r0, [r4, #0x0C]
	ldr r0, [r5, #0x08]
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x10]
	adds r5, r4, #0x0
	adds r5, #0x14
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl AnimInit
	ldr r1, [r4, #0x08]
	str r5, [r1, #0x18]
	ldr r0, [r4, #0x10]
	ldrh r0, [r0, #0x06]
	strh r0, [r1, #0x1C]
	adds r0, r4, #0x0
	bl func_081149B8
	adds r4, #0x2C
	adds r0, r4, #0x0
	movs r1, #0x04
	bl TaskPoolInit
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
