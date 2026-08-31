.syntax unified
	.align 2, 0
	.global task_btl_hpply_1
	.thumb
	.thumb_func
	.type task_btl_hpply_1, %function
task_btl_hpply_1:
	.incbin "roms/B8CJ.gba", 0x2f964, 0x2c0
.syntax divided
