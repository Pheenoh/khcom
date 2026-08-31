.syntax unified
	.align 2, 0
	.global task_bos_md_1
	.thumb
	.thumb_func
	.type task_bos_md_1, %function
task_bos_md_1:
	.incbin "roms/B8CJ.gba", 0xfc6f4, 0x1dc
.syntax divided
