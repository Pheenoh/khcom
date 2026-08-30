.syntax unified
	.align 2, 0
	.global task_poo_map_3
	.thumb
	.thumb_func
	.type task_poo_map_3, %function
task_poo_map_3: @ 080CA264
	push {lr}
	adds r0, #0x04
	bl func_08000F0C
	pop {r0}
	bx r0
.syntax divided
