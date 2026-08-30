.syntax unified
	.align 2, 0
	.global task_emy_39_0
	.thumb
	.thumb_func
	.type task_emy_39_0, %function
task_emy_39_0: @ 0803D020
	push {lr}
	adds r2, r1, #0x0
	ldr r1, _0803D030 @ =0x0813E374
	bl func_0800C778
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0803D030: .4byte 0x0813E374
.syntax divided
