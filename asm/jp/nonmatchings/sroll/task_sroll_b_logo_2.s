.syntax unified
	.align 2, 0
	.global task_sroll_b_logo_2
	.thumb
	.thumb_func
	.type task_sroll_b_logo_2, %function
task_sroll_b_logo_2:
	.incbin "roms/B8CJ.gba", 0x114d44, 0x4c
.syntax divided
