.syntax unified
	.align 2, 0
	.global task_status_2
	.thumb
	.thumb_func
	.type task_status_2, %function
task_status_2: @ 080D7878
	push {lr}
	bl TaskPoolDraw
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
