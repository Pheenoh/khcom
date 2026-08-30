.syntax unified
	.align 2, 0
	.global task_evt_shadow_1
	.thumb
	.thumb_func
	.type task_evt_shadow_1, %function
task_evt_shadow_1: @ 0801D04C
	movs r0, #0x01
	bx lr
.syntax divided
