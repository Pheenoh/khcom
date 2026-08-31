.syntax unified
	.align 2, 0
	.global task_status_cursor_2
	.thumb
	.thumb_func
	.type task_status_cursor_2, %function
task_status_cursor_2:
	.incbin "roms/B8CJ.gba", 0xd7ff8, 0x80
.syntax divided
