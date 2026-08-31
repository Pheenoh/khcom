.syntax unified
	.align 2, 0
	.global task_status_scrollcursor_1
	.thumb
	.thumb_func
	.type task_status_scrollcursor_1, %function
task_status_scrollcursor_1:
	.incbin "roms/B8CJ.gba", 0xd88f4, 0x14
.syntax divided
