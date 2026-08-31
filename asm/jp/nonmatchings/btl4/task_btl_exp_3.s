.syntax unified
	.align 2, 0
	.global task_btl_exp_3
	.thumb
	.thumb_func
	.type task_btl_exp_3, %function
task_btl_exp_3:
	.incbin "roms/B8CJ.gba", 0x5d130, 0x28
.syntax divided
