.syntax unified
	.align 2, 0
	.global task_btl_exp_1
	.thumb
	.thumb_func
	.type task_btl_exp_1, %function
task_btl_exp_1:
	.incbin "roms/B8CJ.gba", 0x5cf54, 0x14c
.syntax divided
