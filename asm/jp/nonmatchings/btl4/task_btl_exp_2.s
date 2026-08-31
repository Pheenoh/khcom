.syntax unified
	.align 2, 0
	.global task_btl_exp_2
	.thumb
	.thumb_func
	.type task_btl_exp_2, %function
task_btl_exp_2:
	.incbin "roms/B8CJ.gba", 0x5d0a0, 0x90
.syntax divided
