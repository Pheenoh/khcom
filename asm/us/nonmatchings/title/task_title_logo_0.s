.syntax unified
	.align 2, 0
	.global task_title_logo_0
	.thumb
	.thumb_func
	.type task_title_logo_0, %function
task_title_logo_0: @ 080D63EC
	push {lr}
	bl func_080D62A8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
