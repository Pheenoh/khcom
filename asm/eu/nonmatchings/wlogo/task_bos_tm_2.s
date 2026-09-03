.syntax unified
	.text
	.align 2, 0
	.global task_bos_tm_2
	.thumb
	.thumb_func
	.type task_bos_tm_2, %function
task_bos_tm_2:
	.incbin "roms/B8CP.gba", 0xb45b8, 0x10
.syntax divided
