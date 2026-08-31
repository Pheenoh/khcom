.syntax unified
	.align 2, 0
	.global task_bos_dsd_main_2
	.thumb
	.thumb_func
	.type task_bos_dsd_main_2, %function
task_bos_dsd_main_2:
	.incbin "roms/B8CJ.gba", 0xc25c8, 0x18c
.syntax divided
