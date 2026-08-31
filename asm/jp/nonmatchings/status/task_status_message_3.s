.syntax unified
	.align 2, 0
	.global task_status_message_3
	.thumb
	.thumb_func
	.type task_status_message_3, %function
task_status_message_3:
	.incbin "roms/B8CJ.gba", 0xd8aa8, 0x1c
.syntax divided
