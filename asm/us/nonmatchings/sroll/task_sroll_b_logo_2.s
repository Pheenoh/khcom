.syntax unified
	.align 2, 0
	.global task_sroll_b_logo_2
	.thumb
	.thumb_func
	.type task_sroll_b_logo_2, %function
task_sroll_b_logo_2: @ 08114CC8
	push {r4, r5, lr}
	add sp, #-0x010
	adds r5, r0, #0x0
	ldr r4, [r5, #0x04]
	asrs r4, r4, #0x08
	ldr r0, [r5, #0x08]
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x08
	subs r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r5, #0x0
	adds r0, #0x18
	bl func_08005AFC
	adds r2, r0, #0x0
	ldr r0, [r5, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r3, [r5, #0x10]
	ldr r1, [r5, #0x14]
	str r1, [sp, #0x000]
	movs r1, #0x00
	str r1, [sp, #0x004]
	str r1, [sp, #0x008]
	movs r1, #0xFF
	lsls r1, r1, #0x04
	str r1, [sp, #0x00C]
	adds r1, r4, #0x0
	bl func_080023E0
	add sp, #0x010
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
