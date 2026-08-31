.syntax unified
	.align 2, 0
	.global task_allmap_bar_2
	.thumb
	.thumb_func
	.type task_allmap_bar_2, %function
task_allmap_bar_2:
	.incbin "roms/B8CJ.gba", 0xd4240, 0x84
.syntax divided
