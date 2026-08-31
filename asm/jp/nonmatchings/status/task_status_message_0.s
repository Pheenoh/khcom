.syntax unified
	.align 2, 0
	.global task_status_message_0
	.thumb
	.thumb_func
	.type task_status_message_0, %function
task_status_message_0:
	.incbin "roms/B8CJ.gba", 0xd8a24, 0x44
.syntax divided
