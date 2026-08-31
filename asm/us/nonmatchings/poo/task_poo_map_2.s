.syntax unified
	.align 2, 0
	.global task_poo_map_2
	.thumb
	.thumb_func
	.type task_poo_map_2, %function
task_poo_map_2: @ 080CA258
	push {lr}
	adds r0, #0x04
	bl TaskPoolDraw
	pop {r0}
	bx r0
.syntax divided
