.syntax unified
	.align 2, 0
	.global task_allmap_cursor_1
	.thumb
	.thumb_func
	.type task_allmap_cursor_1, %function
task_allmap_cursor_1:
	.incbin "roms/B8CJ.gba", 0xd3c7c, 0xf8
.syntax divided
