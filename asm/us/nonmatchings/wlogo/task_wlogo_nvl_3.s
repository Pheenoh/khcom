.syntax unified
	.align 2, 0
	.global task_wlogo_nvl_3
	.thumb
	.thumb_func
	.type task_wlogo_nvl_3, %function
task_wlogo_nvl_3: @ 080B568C
	push {lr}
	ldr r0, _080B5698 @ =0x02034C50
	bl func_08000F0C
	pop {r0}
	bx r0
_080B5698: .4byte 0x02034C50
.syntax divided
