.syntax unified
	.align 2, 0
	.global task_poo_butterfly_1
	.thumb
	.thumb_func
	.type task_poo_butterfly_1, %function
task_poo_butterfly_1: @ 080D21F4
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_080D2190
	adds r4, #0x68
	adds r0, r4, #0x0
	bl func_080D2190
	movs r0, #0x01
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
