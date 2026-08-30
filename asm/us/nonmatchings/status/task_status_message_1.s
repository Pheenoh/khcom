.syntax unified
	.align 2, 0
	.global task_status_message_1
	.thumb
	.thumb_func
	.type task_status_message_1, %function
task_status_message_1: @ 080D8A48
	movs r0, #0x01
	bx lr
.syntax divided
