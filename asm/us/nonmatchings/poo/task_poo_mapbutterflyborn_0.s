.syntax unified
	.align 2, 0
	.global task_poo_mapbutterflyborn_0
	.thumb
	.thumb_func
	.type task_poo_mapbutterflyborn_0, %function
task_poo_mapbutterflyborn_0: @ 080D275C
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r2, r1, #0x0
	adds r1, r5, #0x0
	adds r1, #0x10
	adds r0, r2, #0x0
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	movs r4, #0x00
	str r4, [r5, #0x18]
	ldr r1, [r2, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x05
	adds r1, r1, r0
	str r1, [r5, #0x00]
	ldr r2, [r2, #0x04]
	movs r3, #0xC0
	lsls r3, r3, #0x05
	adds r2, r2, r3
	str r2, [r5, #0x04]
	str r4, [r5, #0x08]
	adds r0, r5, #0x0
	adds r0, #0x20
	movs r3, #0x00
	bl func_08012324
	adds r0, r5, #0x0
	adds r0, #0x98
	strb r4, [r0, #0x00]
	subs r0, #0x1C
	strb r4, [r0, #0x00]
	adds r0, #0x1D
	strb r4, [r0, #0x00]
	subs r0, #0x19
	movs r1, #0x01
	bl func_08000E64
	adds r0, r5, #0x0
	adds r0, #0x94
	str r4, [r0, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
