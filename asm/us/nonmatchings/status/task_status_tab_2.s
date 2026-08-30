.syntax unified
	.align 2, 0
	.global task_status_tab_2
	.thumb
	.thumb_func
	.type task_status_tab_2, %function
task_status_tab_2: @ 080D7C48
	push {r4, r5, r6, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldr r2, [r4, #0x10]
	ldr r3, [r4, #0x00]
	ldr r0, [r4, #0x08]
	str r0, [sp, #0x000]
	movs r6, #0x00
	str r6, [sp, #0x004]
	movs r5, #0x80
	lsls r5, r5, #0x04
	str r5, [sp, #0x008]
	movs r0, #0x0A
	str r0, [sp, #0x00C]
	movs r0, #0x00
	movs r1, #0x10
	bl func_080023E0
	ldr r2, [r4, #0x14]
	ldr r3, [r4, #0x04]
	ldr r0, [r4, #0x0C]
	str r0, [sp, #0x000]
	str r6, [sp, #0x004]
	str r5, [sp, #0x008]
	movs r0, #0x0B
	str r0, [sp, #0x00C]
	movs r0, #0x00
	movs r1, #0x10
	bl func_080023E0
	add sp, #0x010
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
