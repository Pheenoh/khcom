.syntax unified
	.align 2, 0
	.global task_btl_area_1
	.thumb
	.thumb_func
	.type task_btl_area_1, %function
task_btl_area_1:
	.incbin "roms/B8CJ.gba", 0x1d644, 0x48
.syntax divided
