.syntax unified
	.text
	.align 2, 0
	.global task_bos_tm_3
	.thumb
	.thumb_func
	.type task_bos_tm_3, %function
task_bos_tm_3:
	.incbin "roms/B8CP.gba", 0xb45c8, 0x70
.syntax divided
