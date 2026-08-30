.syntax unified
	.align 2, 0
	.global task_wlogo_nvl_mov_3
	.thumb
	.thumb_func
	.type task_wlogo_nvl_mov_3, %function
task_wlogo_nvl_mov_3: @ 080B58E8
	push {lr}
	ldr r0, _080B58F4 @ =0x02034C68
	bl func_08000F0C
	pop {r0}
	bx r0
_080B58F4: .4byte 0x02034C68
.syntax divided
