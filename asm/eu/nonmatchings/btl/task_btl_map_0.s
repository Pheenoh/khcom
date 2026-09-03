.syntax unified
	.text
	.align 2, 0
	.global task_btl_map_0
	.thumb
	.thumb_func
	.type task_btl_map_0, %function
task_btl_map_0:
	.incbin "roms/B8CP.gba", 0x32938, 0x7cc
.syntax divided
