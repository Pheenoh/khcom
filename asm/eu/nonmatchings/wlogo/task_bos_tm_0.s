.syntax unified
	.text
	.align 2, 0
	.global task_bos_tm_0
	.thumb
	.thumb_func
	.type task_bos_tm_0, %function
task_bos_tm_0:
	.incbin "roms/B8CP.gba", 0xb41f8, 0x1c0
.syntax divided
