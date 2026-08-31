.syntax unified
	.align 2, 0
	.global task_poo_leaf_0
	.thumb
	.thumb_func
	.type task_poo_leaf_0, %function
task_poo_leaf_0: @ 080CF280
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0x0
	ldr r0, [r1, #0x00]
	str r0, [r7, #0x24]
	ldr r0, [r1, #0x04]
	str r0, [r7, #0x28]
	movs r4, #0x00
	str r4, [r7, #0x2C]
	ldrh r1, [r1, #0x10]
	adds r0, r7, #0x0
	adds r0, #0x94
	movs r6, #0x00
	strh r1, [r0, #0x00]
	ldr r5, _080CF2F4 @ =0x09EF610C
	adds r0, r5, #0x0
	movs r1, #0x05
	bl func_08003524
	adds r1, r7, #0x0
	adds r1, #0x92
	strh r0, [r1, #0x00]
	str r4, [r7, #0x04]
	adds r4, r7, #0x0
	adds r4, #0x0C
	ldr r1, _080CF2F8 @ =0x09EF612C
	adds r0, r4, #0x0
	adds r2, r5, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r7, #0x08]
	adds r0, r7, #0x0
	adds r0, #0x34
	ldr r1, [r7, #0x24]
	movs r2, #0xE0
	lsls r2, r2, #0x05
	adds r1, r1, r2
	ldr r2, [r7, #0x28]
	movs r3, #0x80
	lsls r3, r3, #0x05
	adds r2, r2, r3
	ldr r3, [r7, #0x2C]
	bl func_08012324
	adds r0, r7, #0x0
	adds r0, #0x90
	strb r6, [r0, #0x00]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CF2F4: .4byte 0x09EF610C
_080CF2F8: .4byte 0x09EF612C
.syntax divided
