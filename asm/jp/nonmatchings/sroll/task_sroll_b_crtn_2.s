.syntax unified
	.align 2, 0
	.global task_sroll_b_crtn_2
	.thumb
	.thumb_func
	.type task_sroll_b_crtn_2, %function
task_sroll_b_crtn_2:
	.incbin "roms/B8CJ.gba", 0x1151a0, 0x3c
.syntax divided
