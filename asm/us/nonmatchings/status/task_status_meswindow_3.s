.syntax unified
	.align 2, 0
	.global task_status_meswindow_3
	.thumb
	.thumb_func
	.type task_status_meswindow_3, %function
task_status_meswindow_3: @ 080D89F8
	push {lr}
	bl TaskPoolDestroy
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
