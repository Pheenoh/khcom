.syntax unified
	.text
	.align 2, 0
	.global task_btl_exp_1
	.thumb
	.thumb_func
	.type task_btl_exp_1, %function
task_btl_exp_1:
	.incbin "roms/B8CP.gba", 0x5f22c, 0x2ac
.syntax divided
