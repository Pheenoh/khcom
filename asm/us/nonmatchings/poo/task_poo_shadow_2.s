.syntax unified
	.align 2, 0
	.global task_poo_shadow_2
	.thumb
	.thumb_func
	.type task_poo_shadow_2, %function
task_poo_shadow_2: @ 080CBF54
	push {lr}
	bl func_08000EE0
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
