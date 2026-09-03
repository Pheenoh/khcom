.syntax unified
	.text
	.align 2, 0
	.global task_status_bar_0
	.thumb
	.thumb_func
	.type task_status_bar_0, %function
task_status_bar_0:
	.incbin "roms/B8CP.gba", 0xd4634, 0x78
.syntax divided
