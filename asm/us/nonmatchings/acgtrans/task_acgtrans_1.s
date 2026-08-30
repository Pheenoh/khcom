.syntax unified
	.align 2, 0
	.global task_acgtrans_1
	.thumb
	.thumb_func
	.type task_acgtrans_1, %function
task_acgtrans_1: @ 0801D168
	push {r4, lr}
	adds r4, r0, #0x0
	ldrh r2, [r4, #0x0A]
	ldrh r0, [r4, #0x0C]
	adds r1, r2, r0
	ldrh r0, [r4, #0x08]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r0, #0x00
	bgt _0801D196
	adds r0, r2, r1
	strh r0, [r4, #0x0A]
	ldr r0, [r4, #0x04]
	ldr r1, [r4, #0x00]
	ldrh r2, [r4, #0x0A]
	bl func_080043B4
	ldr r0, [r4, #0x10]
	bl func_0800501C
	movs r0, #0x00
	b _0801D1BE
_0801D196:
	ldr r0, [r4, #0x04]
	ldr r1, [r4, #0x00]
	ldrh r2, [r4, #0x0A]
	bl func_080043B4
	ldrh r1, [r4, #0x0A]
	ldr r0, [r4, #0x04]
	adds r0, r0, r1
	str r0, [r4, #0x04]
	ldr r0, [r4, #0x00]
	adds r0, r0, r1
	str r0, [r4, #0x00]
	ldrh r0, [r4, #0x0A]
	ldrh r1, [r4, #0x0C]
	adds r0, r0, r1
	strh r0, [r4, #0x0C]
	ldr r0, [r4, #0x10]
	bl func_0800501C
	movs r0, #0x01
_0801D1BE:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
