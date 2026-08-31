.syntax unified
	.align 2, 0
	.global task_bos_md_3
	.thumb
	.thumb_func
	.type task_bos_md_3, %function
task_bos_md_3:
	.incbin "roms/B8CJ.gba", 0xfca48, 0x94
.syntax divided
