.syntax unified
	.text
	.align 2, 0
	.global task_bos_dsd_1
	.thumb
	.thumb_func
	.type task_bos_dsd_1, %function
task_bos_dsd_1:
	.incbin "roms/B8CP.gba", 0xbe1b8, 0x21c
.syntax divided
