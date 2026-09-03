.syntax unified
	.text
	.align 2, 0
	.global task_sroll_b_char_1
	.thumb
	.thumb_func
	.type task_sroll_b_char_1, %function
task_sroll_b_char_1:
	.incbin "roms/B8CP.gba", 0x1132c0, 0x138
.syntax divided
