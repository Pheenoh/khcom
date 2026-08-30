.syntax unified
	.align 2, 0
	.global task_wlogo_tt_line_2
	.thumb
	.thumb_func
	.type task_wlogo_tt_line_2, %function
task_wlogo_tt_line_2: @ 080B7820
	push {lr}
	adds r0, #0x08
	bl func_08000EE0
	pop {r0}
	bx r0
.syntax divided
