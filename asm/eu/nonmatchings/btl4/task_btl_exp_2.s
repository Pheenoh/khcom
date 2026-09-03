.syntax unified
	.text
	.align 2, 0
	.global task_btl_exp_2
	.thumb
	.thumb_func
	.type task_btl_exp_2, %function
task_btl_exp_2:
	.incbin "roms/B8CP.gba", 0x5f4d8, 0x98
.syntax divided
