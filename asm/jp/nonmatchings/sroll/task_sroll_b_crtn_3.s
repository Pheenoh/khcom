.syntax unified
	.align 2, 0
	.global task_sroll_b_crtn_3
	.thumb
	.thumb_func
	.type task_sroll_b_crtn_3, %function
task_sroll_b_crtn_3:
	.incbin "roms/B8CJ.gba", 0x1151dc, 0x20
.syntax divided
