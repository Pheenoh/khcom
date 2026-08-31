.syntax unified
	.align 2, 0
	.global task_sroll_b_char_2
	.thumb
	.thumb_func
	.type task_sroll_b_char_2, %function
task_sroll_b_char_2:
	.incbin "roms/B8CJ.gba", 0x114c00, 0x78
.syntax divided
