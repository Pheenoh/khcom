.syntax unified
	.text
	.align 2, 0
	.global task_allmap_bar_2
	.thumb
	.thumb_func
	.type task_allmap_bar_2, %function
task_allmap_bar_2:
	.incbin "roms/B8CP.gba", 0xd09c0, 0x94
.syntax divided
