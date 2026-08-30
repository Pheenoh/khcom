.syntax unified
	.align 2, 0
	.global task_wlogo_hwt_3
	.thumb
	.thumb_func
	.type task_wlogo_hwt_3, %function
task_wlogo_hwt_3: @ 080B4CC8
	push {lr}
	ldr r0, _080B4CD4 @ =0x02034C38
	bl func_08000F0C
	pop {r0}
	bx r0
_080B4CD4: .4byte 0x02034C38
.syntax divided
