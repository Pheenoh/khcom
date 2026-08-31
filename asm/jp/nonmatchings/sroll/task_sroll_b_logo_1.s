.syntax unified
	.align 2, 0
	.global task_sroll_b_logo_1
	.thumb
	.thumb_func
	.type task_sroll_b_logo_1, %function
task_sroll_b_logo_1:
	.incbin "roms/B8CJ.gba", 0x114d14, 0x30
.syntax divided
