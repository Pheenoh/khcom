.syntax unified
	.align 2, 0
	.global task_status_cursor_1
	.thumb
	.thumb_func
	.type task_status_cursor_1, %function
task_status_cursor_1:
	.incbin "roms/B8CJ.gba", 0xd7f68, 0x90
.syntax divided
