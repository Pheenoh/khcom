.syntax unified
	.align 2, 0
	.global task_poo_tigerstump_0
	.thumb
	.thumb_func
	.type task_poo_tigerstump_0, %function
task_poo_tigerstump_0: @ 080CD58C
	push {lr}
	ldr r3, [r1, #0x00]
	str r3, [r0, #0x24]
	ldr r2, [r1, #0x04]
	movs r1, #0x80
	lsls r1, r1, #0x04
	adds r2, r2, r1
	str r2, [r0, #0x28]
	movs r1, #0x00
	str r1, [r0, #0x2C]
	str r1, [r0, #0x04]
	ldr r1, _080CD5B4 @ =0x097561D4
	str r1, [r0, #0x08]
	adds r0, #0x34
	adds r1, r3, #0x0
	movs r3, #0x00
	bl func_08012324
	pop {r0}
	bx r0
_080CD5B4: .4byte 0x097561D4
.syntax divided
