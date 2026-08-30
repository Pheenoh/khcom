.syntax unified
	.align 2, 0
	.global task_emy_25_0
	.thumb
	.thumb_func
	.type task_emy_25_0, %function
task_emy_25_0: @ 0803A6D8
	push {lr}
	adds r2, r1, #0x0
	ldr r1, _0803A6E8 @ =0x0813DD8C
	bl func_0800C778
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0803A6E8: .4byte 0x0813DD8C
.syntax divided
