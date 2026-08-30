.syntax unified
	.align 2, 0
	.global task_poo_gauge_2
	.thumb
	.thumb_func
	.type task_poo_gauge_2, %function
task_poo_gauge_2: @ 080CC5B0
	push {lr}
	add sp, #-0x010
	ldr r2, [r0, #0x08]
	ldr r3, [r0, #0x00]
	ldr r0, [r0, #0x04]
	str r0, [sp, #0x000]
	movs r1, #0x00
	str r1, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x03
	str r0, [sp, #0x008]
	str r1, [sp, #0x00C]
	movs r0, #0xDC
	movs r1, #0x18
	bl func_080023E0
	add sp, #0x010
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
