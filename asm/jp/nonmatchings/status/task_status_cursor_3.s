.syntax unified
	.align 2, 0
	.global task_status_cursor_3
	.thumb
	.thumb_func
	.type task_status_cursor_3, %function
task_status_cursor_3:
	.incbin "roms/B8CJ.gba", 0xd8078, 0x24
.syntax divided
