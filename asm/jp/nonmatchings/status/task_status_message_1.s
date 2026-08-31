.syntax unified
	.align 2, 0
	.global task_status_message_1
	.thumb
	.thumb_func
	.type task_status_message_1, %function
task_status_message_1:
	.incbin "roms/B8CJ.gba", 0xd8a68, 0x4
.syntax divided
