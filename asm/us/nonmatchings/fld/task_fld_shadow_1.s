.syntax unified
	.align 2, 0
	.global task_fld_shadow_1
	.thumb
	.thumb_func
	.type task_fld_shadow_1, %function
task_fld_shadow_1: @ 08036B3C
	ldr r2, [r0, #0x10]
	ldr r1, [r2, #0x00]
	str r1, [r0, #0x00]
	ldr r1, [r2, #0x04]
	str r1, [r0, #0x04]
	movs r0, #0x01
	bx lr
	.byte 0x00, 0x00
.syntax divided
