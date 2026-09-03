.syntax unified
	.text
	.align 2, 0
	.global task_bos_tm_1
	.thumb
	.thumb_func
	.type task_bos_tm_1, %function
task_bos_tm_1:
	.incbin "roms/B8CP.gba", 0xb43b8, 0x200
.syntax divided
