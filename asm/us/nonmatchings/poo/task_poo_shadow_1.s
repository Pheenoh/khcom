.syntax unified
	.align 2, 0
	.global task_poo_shadow_1
	.thumb
	.thumb_func
	.type task_poo_shadow_1, %function
task_poo_shadow_1: @ 080CBF48
	push {lr}
	bl func_08000EA4
	movs r0, #0x01
	pop {r1}
	bx r1
.syntax divided
