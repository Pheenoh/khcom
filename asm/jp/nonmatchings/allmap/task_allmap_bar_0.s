.syntax unified
	.align 2, 0
	.global task_allmap_bar_0
	.thumb
	.thumb_func
	.type task_allmap_bar_0, %function
task_allmap_bar_0:
	.incbin "roms/B8CJ.gba", 0xd4014, 0x74
.syntax divided
