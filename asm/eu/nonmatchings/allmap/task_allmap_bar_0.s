.syntax unified
	.text
	.align 2, 0
	.global task_allmap_bar_0
	.thumb
	.thumb_func
	.type task_allmap_bar_0, %function
task_allmap_bar_0:
	.incbin "roms/B8CP.gba", 0xd0784, 0x74
.syntax divided
