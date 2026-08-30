.syntax unified
	.align 2, 0
	.global task_sroll_b_logo_1
	.thumb
	.thumb_func
	.type task_sroll_b_logo_1, %function
task_sroll_b_logo_1: @ 08114C98
	push {r4, lr}
	adds r2, r0, #0x0
	movs r4, #0x01
	ldr r1, [r2, #0x04]
	asrs r1, r1, #0x08
	ldr r0, [r2, #0x08]
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x08
	subs r1, r1, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r0, #0x20
	negs r0, r0
	cmp r1, r0
	bgt _08114CB8
	movs r4, #0x00
_08114CB8:
	adds r0, r2, #0x0
	adds r0, #0x18
	bl func_08005A64
	adds r0, r4, #0x0
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
