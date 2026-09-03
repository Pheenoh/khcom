.syntax unified
	.text
	.align 2, 0
	.global task_btl_area_2
	.thumb
	.thumb_func
	.type task_btl_area_2, %function
task_btl_area_2:
	.incbin "roms/B8CJ.gba", 0x1d68c, 0x59c
.syntax divided
