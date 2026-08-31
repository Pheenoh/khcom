.syntax unified
	.align 2, 0
	.global task_bos_dsd_rock_1
	.thumb
	.thumb_func
	.type task_bos_dsd_rock_1, %function
task_bos_dsd_rock_1:
	.incbin "roms/B8CJ.gba", 0xc4690, 0x5c
.syntax divided
