.syntax unified
	.align 2, 0
	.global task_sroll_b_char_1
	.thumb
	.thumb_func
	.type task_sroll_b_char_1, %function
task_sroll_b_char_1:
	.incbin "roms/B8CJ.gba", 0x114ac8, 0x138
.syntax divided
