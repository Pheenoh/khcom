.syntax unified
	.align 2, 0
	.global task_romcri_eff2_3
	.thumb
	.thumb_func
	.type task_romcri_eff2_3, %function
task_romcri_eff2_3: @ 0803FDBC
	push {lr}
	movs r0, #0x01
	bl func_0800501C
	pop {r0}
	bx r0
.syntax divided
