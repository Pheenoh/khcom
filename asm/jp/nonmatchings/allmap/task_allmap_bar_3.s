.syntax unified
	.align 2, 0
	.global task_allmap_bar_3
	.thumb
	.thumb_func
	.type task_allmap_bar_3, %function
task_allmap_bar_3:
	.incbin "roms/B8CJ.gba", 0xd42c4, 0x1c
.syntax divided
