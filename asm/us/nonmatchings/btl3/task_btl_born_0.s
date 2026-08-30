.syntax unified
	.align 2, 0
	.global task_btl_born_0
	.thumb
	.thumb_func
	.type task_btl_born_0, %function
task_btl_born_0: @ 08040064
	push {r4, r5, r6, lr}
	adds r3, r0, #0x0
	adds r2, r1, #0x4
	ldm r2!, {r4, r5, r6}
	stm r3!, {r4, r5, r6}
	ldr r2, [r1, #0x00]
	str r2, [r0, #0x0C]
	ldrh r2, [r1, #0x10]
	strh r2, [r0, #0x10]
	ldrh r1, [r1, #0x12]
	strh r1, [r0, #0x12]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
