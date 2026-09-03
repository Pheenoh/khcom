.syntax unified
	.text
	.align 2, 0
	.global task_bos_dsd_main_0
	.thumb
	.thumb_func
	.type task_bos_dsd_main_0, %function
task_bos_dsd_main_0:
	.incbin "roms/B8CP.gba", 0xbe480, 0x21c
.syntax divided
