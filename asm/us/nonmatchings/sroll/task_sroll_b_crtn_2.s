.syntax unified
	.align 2, 0
	.global task_sroll_b_crtn_2
	.thumb
	.thumb_func
	.type task_sroll_b_crtn_2, %function
task_sroll_b_crtn_2: @ 08115124
	push {r4, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	adds r0, #0x18
	bl func_08005AFC
	adds r2, r0, #0x0
	ldr r0, [r4, #0x08]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r1, [r4, #0x0C]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r3, [r4, #0x10]
	ldr r4, [r4, #0x14]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x03
	str r4, [sp, #0x008]
	movs r4, #0xFE
	lsls r4, r4, #0x04
	str r4, [sp, #0x00C]
	bl func_080023E0
	add sp, #0x010
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
