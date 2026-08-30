.syntax unified
	.align 2, 0
	.global task_emy_15_0
	.thumb
	.thumb_func
	.type task_emy_15_0, %function
task_emy_15_0: @ 08038954
	push {lr}
	adds r2, r1, #0x0
	ldr r1, _08038964 @ =0x0813D944
	bl func_0800C778
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08038964: .4byte 0x0813D944
.syntax divided
