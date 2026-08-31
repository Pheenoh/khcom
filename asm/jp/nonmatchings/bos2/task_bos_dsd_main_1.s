.syntax unified
	.align 2, 0
	.global task_bos_dsd_main_1
	.thumb
	.thumb_func
	.type task_bos_dsd_main_1, %function
task_bos_dsd_main_1:
	.incbin "roms/B8CJ.gba", 0xc244c, 0x17c
.syntax divided
