.syntax unified
	.align 2, 0
	.global task_poo_shadow_3
	.thumb
	.thumb_func
	.type task_poo_shadow_3, %function
task_poo_shadow_3: @ 080CBF60
	push {lr}
	bl TaskPoolDestroy
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
