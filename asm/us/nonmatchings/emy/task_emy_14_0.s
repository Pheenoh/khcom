.syntax unified
	.align 2, 0
	.global task_emy_14_0
	.thumb
	.thumb_func
	.type task_emy_14_0, %function
task_emy_14_0: @ 0803882C
	push {lr}
	adds r2, r1, #0x0
	ldr r1, _0803883C @ =0x0813D88C
	bl func_0800C778
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0803883C: .4byte 0x0813D88C
.syntax divided
