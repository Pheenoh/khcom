.syntax unified
	.text
	.align 2, 0
	.global task_bos_tm_foot_2
	.thumb
	.thumb_func
	.type task_bos_tm_foot_2, %function
task_bos_tm_foot_2:
	.incbin "roms/B8CP.gba", 0xb72a8, 0x1d0
.syntax divided
