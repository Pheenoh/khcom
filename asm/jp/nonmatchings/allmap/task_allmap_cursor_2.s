.syntax unified
	.align 2, 0
	.global task_allmap_cursor_2
	.thumb
	.thumb_func
	.type task_allmap_cursor_2, %function
task_allmap_cursor_2:
	.incbin "roms/B8CJ.gba", 0xd3d74, 0x68
.syntax divided
