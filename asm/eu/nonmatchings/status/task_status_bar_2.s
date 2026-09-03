.syntax unified
	.text
	.align 2, 0
	.global task_status_bar_2
	.thumb
	.thumb_func
	.type task_status_bar_2, %function
task_status_bar_2:
	.incbin "roms/B8CP.gba", 0xd4834, 0xa4
.syntax divided
