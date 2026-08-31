.syntax unified
	.align 2, 0
	.global task_btl_area_3
	.thumb
	.thumb_func
	.type task_btl_area_3, %function
task_btl_area_3:
	.incbin "roms/B8CJ.gba", 0x1dc28, 0x34
.syntax divided
