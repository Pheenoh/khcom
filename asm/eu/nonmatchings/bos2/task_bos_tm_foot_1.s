.syntax unified
	.text
	.align 2, 0
	.global task_bos_tm_foot_1
	.thumb
	.thumb_func
	.type task_bos_tm_foot_1, %function
task_bos_tm_foot_1:
	.incbin "roms/B8CP.gba", 0xb6e90, 0x418
.syntax divided
