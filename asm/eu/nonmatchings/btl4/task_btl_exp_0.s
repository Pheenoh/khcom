.syntax unified
	.text
	.align 2, 0
	.global task_btl_exp_0
	.thumb
	.thumb_func
	.type task_btl_exp_0, %function
task_btl_exp_0:
	.incbin "roms/B8CP.gba", 0x5f1b4, 0x78
.syntax divided
