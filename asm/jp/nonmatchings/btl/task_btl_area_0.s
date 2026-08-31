.syntax unified
	.align 2, 0
	.global task_btl_area_0
	.thumb
	.thumb_func
	.type task_btl_area_0, %function
task_btl_area_0:
	.incbin "roms/B8CJ.gba", 0x1d614, 0x30
.syntax divided
