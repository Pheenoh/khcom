.syntax unified
	.align 2, 0
	.global task_wlogo_tt_line_3
	.thumb
	.thumb_func
	.type task_wlogo_tt_line_3, %function
task_wlogo_tt_line_3: @ 080B782C
	push {lr}
	adds r0, #0x08
	bl func_08000F0C
	pop {r0}
	bx r0
.syntax divided
