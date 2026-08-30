.syntax unified
	.align 2, 0
	.global task_emy_19_0
	.thumb
	.thumb_func
	.type task_emy_19_0, %function
task_emy_19_0: @ 08039808
	push {lr}
	adds r2, r1, #0x0
	ldr r1, _08039818 @ =0x0813DB4C
	bl func_0800C778
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08039818: .4byte 0x0813DB4C
.syntax divided
