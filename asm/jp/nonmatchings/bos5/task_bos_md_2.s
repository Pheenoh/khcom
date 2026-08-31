.syntax unified
	.align 2, 0
	.global task_bos_md_2
	.thumb
	.thumb_func
	.type task_bos_md_2, %function
task_bos_md_2:
	.incbin "roms/B8CJ.gba", 0xfc8d0, 0x178
.syntax divided
