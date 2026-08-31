.syntax unified
	.align 2, 0
	.global task_btl_hpply_2
	.thumb
	.thumb_func
	.type task_btl_hpply_2, %function
task_btl_hpply_2:
	.incbin "roms/B8CJ.gba", 0x2fc24, 0x1ec
.syntax divided
