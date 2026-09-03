.syntax unified
	.text
	.align 2, 0
	.global task_bos_tm_1
	.thumb
	.thumb_func
	.type task_bos_tm_1, %function
task_bos_tm_1:
	.incbin "roms/B8CJ.gba", 0xb8168, 0x200
.syntax divided
