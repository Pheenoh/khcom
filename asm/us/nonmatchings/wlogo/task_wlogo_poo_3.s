.syntax unified
	.align 2, 0
	.global task_wlogo_poo_3
	.thumb
	.thumb_func
	.type task_wlogo_poo_3, %function
task_wlogo_poo_3: @ 080B6BF0
	push {lr}
	ldr r0, _080B6BFC @ =0x02034C98
	bl func_08000F0C
	pop {r0}
	bx r0
_080B6BFC: .4byte 0x02034C98
.syntax divided
