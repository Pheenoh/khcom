.syntax unified
	.align 2, 0
	.global task_acgtrans_0
	.thumb
	.thumb_func
	.type task_acgtrans_0, %function
task_acgtrans_0: @ 0801D130
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	ldr r0, [r5, #0x04]
	str r0, [r4, #0x00]
	ldr r0, [r5, #0x00]
	str r0, [r4, #0x04]
	ldrh r0, [r5, #0x08]
	strh r0, [r4, #0x08]
	ldrh r0, [r4, #0x08]
	ldrh r1, [r5, #0x0A]
	bl __udivsi3
	strh r0, [r4, #0x0A]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _0801D156
	movs r0, #0x01
	strh r0, [r4, #0x0A]
_0801D156:
	movs r0, #0x00
	strh r0, [r4, #0x0C]
	ldr r0, [r5, #0x0C]
	str r0, [r4, #0x10]
	bl func_0800501C
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
