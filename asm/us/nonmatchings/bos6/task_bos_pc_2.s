.syntax unified
	.align 2, 0
	.global task_bos_pc_2
	.thumb
	.thumb_func
	.type task_bos_pc_2, %function
task_bos_pc_2: @ 0810B2E8
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_0810A018
	adds r0, r4, #0x0
	bl func_0810A498
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
