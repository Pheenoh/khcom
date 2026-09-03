.syntax unified
	.text
	.align 2, 0
	.global task_allmap_bar_1
	.thumb
	.thumb_func
	.type task_allmap_bar_1, %function
task_allmap_bar_1:
	.incbin "roms/B8CP.gba", 0xd080c, 0x1b4
.syntax divided
